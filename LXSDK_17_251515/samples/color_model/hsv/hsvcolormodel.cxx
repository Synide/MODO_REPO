/*
 * Plug-in HSV color model.
 *
 * Copyright 0000
 *
 * A plug-in color model that enables picking colors using
 * hue, saturation, and value color components.
 */

#include "hsvcolormodel.hxx"

#include <lx_dirbrowse.hpp>
#include <lx_file.hpp>
#include <lx_plugin.hpp>
#include <lx_visitor.hpp>
#include <lxu_message.hpp>
#include <lxu_prefvalue.hpp>
#include <lxu_queries.hpp>
#include <lxvmath.h>
#include <lxw_colormapping.hpp>

#include <cfloat>
#include <climits>
#include <cmath>
#include <sstream>
#include <string>

const char* SERVER_HSV_COLOR_MODEL = "HSV";

/*
 * Convert an integer to a string, with optional zero padding.
 */
std::string IntegerToString(unsigned value, unsigned padding = 0, bool asHexadecimal = false, bool withHexPrefix = false)
{
    std::stringstream os;
    std::string       result;

    if (asHexadecimal)
    {
        os << std::hex;
    }

    if (padding)
    {
        unsigned padThreshold = static_cast<unsigned>(powf(10, static_cast<float>(padding)));
        while ((value < padThreshold))
        {
            os << 0;
            padThreshold /= 10;
            if (padThreshold == 1)
            {
                break;
            }
        }
    }

    os << value << std::ends;

    if (asHexadecimal && withHexPrefix)
    {
        result = std::string("0x");
    }
    result += os.str();

    return result;
}

/*
 * ---------------------------------------------------------------------------
 * Utilities for RGB/HSV conversion.
 */

const float PI       = 3.1415926535897932384626433832795f;
const float TWO_PI   = PI * 2.0f;  // 360 degrees
const float THIRD_PI = PI / 3.0f;  // 60 degrees
const float SIXTH_PI = PI / 6.0f;  // 30 degrees

#define _R rgb[0]
#define _G rgb[1]
#define _B rgb[2]
#define _H hsv[0]
#define _S hsv[1]
#define _V hsv[2]

/*
 * rgb in [0, 1]; h in [0, TWO_PI], s and v in [0, 1]
 */
static void RGB2HSV(const float* rgb, float* hsv)
{
    float min, max, delta;

    min   = LXxMIN(LXxMIN(_R, _G), _B);
    max   = LXxMAX(LXxMAX(_R, _G), _B);
    delta = max - min;

    _V = max;
    if (max)
    {
        _S = delta / max;
        if (delta)
        {
            if (_R == max)
            {
                _H = (_G - _B) / delta;  // between yellow and magenta
            }
            else if (_G == max)
            {
                _H = (_B - _R) / delta + 2.0f;  // between cyan and yellow
            }
            else
            {
                _H = (_R - _G) / delta + 4.0f;  // between magenta and cyan
            }
        }
        else
        {
            _H = 0;
        }

        _H *= (PI / 3.0f);
        if (_H < 0)
        {
            _H += TWO_PI;
        }
    }
    else
    {
        _S = 0.0;
        _H = 0.0;  // black: hue undefined, so make it red
    }
}

/*
 * rgb in [0, 1]; h in [0, TWO_PI], s and v in [0, 1]
 */
static void HSV2RGB(const float* hsv, float* rgb)
{
    float h, f, p, q, t;
    int   i;

    if (_S < FLT_EPSILON)
    {
        _R = _G = _B = _V;  // grey
        return;
    }

    h = _H;
    if (h == float(TWO_PI))
    {
        h = float(TWO_PI) - 0.00001f;  // We want it to cap at ALMOST 360 degrees, not wrap back to 0
    }
    f = (h / THIRD_PI);  // f now in [0, 6]

    i = static_cast<int>(floor(f));  // sector 0 to 5
    f = f - i;                       // factorial part of Hue
    p = _V * (1.0f - _S);
    q = _V * (1.0f - _S * f);
    t = _V * (1.0f - _S * (1.0f - f));

    switch (i)
    {
        case 0:
            _R = _V;
            _G = t;
            _B = p;
            break;

        case 1:
            _R = q;
            _G = _V;
            _B = p;
            break;

        case 2:
            _R = p;
            _G = _V;
            _B = t;
            break;

        case 3:
            _R = p;
            _G = q;
            _B = _V;
            break;

        case 4:
            _R = t;
            _G = p;
            _B = _V;
            break;

        default:
            _R = _V;
            _G = p;
            _B = q;
            break;
    }
}

/*
 * ---------------------------------------------------------------------------
 * Command Utilities.
 */

/*
        static string
QueryCommandString (const char *cmdName, const char *argName)
{
        string	value;

        char	textChars[MAX_COMMAND_VALUE_LEN];
        CLxCommandQuery cmdValue (cmdName);
        if (cmdValue.Query (0)) {
                const char *valueChars = cmdValue.GetString (
                        textChars, MAX_COMMAND_VALUE_LEN);
                value = string(valueChars);
        }

        return value;
}
*/
static int QueryCommandInt(const char* cmdName, int defaultValue = 0)
{
    int             value;
    CLxCommandQuery cmdValue(cmdName);
    if (cmdValue.Query(0))
    {
        value = cmdValue.GetInt();
    }
    else
    {
        value = defaultValue;
    }

    return value;
}
/*
        static double
QueryCommandFloat (const char *cmdName, double defaultValue = 0.0)
{
        double value;
        CLxCommandQuery cmdValue (cmdName);
        if (cmdValue.Query (0)) {
                value = cmdValue.GetFloat ();
        }
        else {
                value = defaultValue;
        }

        return value;
}
*/
/*
 * Execute the command of the given name, with no arguments.
 */
void ExecuteCommand(const char* cmdName)
{
    CLxUser_CommandService svc;
    CLxLoc_Command         updateColorCmd;
    if (svc.NewCommand(updateColorCmd, cmdName))
    {
        updateColorCmd.Execute(0);
    }
}

/*
 * ---------------------------------------------------------------------------
 * CHSVColorModelPersist and CHSVColorModelPersistVisitor
 */

struct CHSVColorModelPersist
{
    CLxUser_PersistentEntry hue_as_wheel;
    CLxUser_PersistentEntry wheel;
    CLxUser_PersistentEntry rule;
    CLxUser_PersistentEntry rule_adjust_complementary;
    CLxUser_PersistentEntry rule_adjust_analogous;
    CLxUser_PersistentEntry rule_adjust_triadic;
    CLxUser_PersistentEntry rule_adjust_tetradic;
    CLxUser_PersistentEntry rule_adjust_compound;
    CLxUser_PersistentEntry m_levels;

    CLxUser_Attributes hue_as_wheel_value;
    CLxUser_Attributes wheel_value;
    CLxUser_Attributes rule_value;
    CLxUser_Attributes rule_adjust_value_complementary;
    CLxUser_Attributes rule_adjust_value_analogous;
    CLxUser_Attributes rule_adjust_value_triadic;
    CLxUser_Attributes rule_adjust_value_tetradic;
    CLxUser_Attributes rule_adjust_value_compound;
    CLxUser_Attributes levels_value;
};

static CHSVColorModelPersist* persist = nullptr;

class CHSVColorModelPersistVisitor : public CLxImpl_AbstractVisitor
{
public:
    virtual ~CHSVColorModelPersistVisitor()
    {
    }
    LxResult Evaluate() override;
};

static const char* ATOM_TAG_HUE_AS_WHEEL              = "hsv.hue.as.wheel";
static const char* ATOM_TAG_WHEEL                     = "hsv.wheel";
static const char* ATOM_TAG_RULE                      = "hsv.rule";
static const char* ATOM_TAG_RULE_ADJUST_COMPLEMENTARY = "hsv.rule.adjust_complementary";
static const char* ATOM_TAG_RULE_ADJUST_ANALOGOUS     = "hsv.rule.adjust_analogous";
static const char* ATOM_TAG_RULE_ADJUST_TRIADIC       = "hsv.rule.adjust_triadic";
static const char* ATOM_TAG_RULE_ADJUST_TETRADIC      = "hsv.rule.adjust_tetradic";
static const char* ATOM_TAG_RULE_ADJUST_COMPOUND      = "hsv.rule.adjust_compound";
static const char* ATOM_TAG_LEVELS                    = "hsv.levels";

LxResult CHSVColorModelPersistVisitor::Evaluate()
{
    CLxUser_PersistenceService srv;

    // Hue as Wheel.
    srv.Start(ATOM_TAG_HUE_AS_WHEEL, LXi_PERSIST_ATOM);
    srv.AddValue(LXsTYPE_BOOLEAN);
    srv.EndDef(persist->hue_as_wheel);

    persist->hue_as_wheel_value.set(persist->hue_as_wheel);

    // Wheel.
    srv.Start(ATOM_TAG_WHEEL, LXi_PERSIST_ATOM);
    srv.AddValue(LXsTYPE_INTEGER);
    srv.EndDef(persist->wheel);

    persist->wheel_value.set(persist->wheel);

    // Rule.
    srv.Start(ATOM_TAG_RULE, LXi_PERSIST_ATOM);
    srv.AddValue(LXsTYPE_INTEGER);
    srv.EndDef(persist->rule);

    persist->rule_value.set(persist->rule);

    // Rule Adjust Complementary.
    srv.Start(ATOM_TAG_RULE_ADJUST_COMPLEMENTARY, LXi_PERSIST_ATOM);
    srv.AddValue(LXsTYPE_ANGLE);
    srv.EndDef(persist->rule_adjust_complementary);

    persist->rule_adjust_value_complementary.set(persist->rule_adjust_complementary);

    // Rule Adjust Analogous.
    srv.Start(ATOM_TAG_RULE_ADJUST_ANALOGOUS, LXi_PERSIST_ATOM);
    srv.AddValue(LXsTYPE_ANGLE);
    srv.EndDef(persist->rule_adjust_analogous);

    persist->rule_adjust_value_analogous.set(persist->rule_adjust_analogous);

    // Rule Adjust Triadic.
    srv.Start(ATOM_TAG_RULE_ADJUST_TRIADIC, LXi_PERSIST_ATOM);
    srv.AddValue(LXsTYPE_ANGLE);
    srv.EndDef(persist->rule_adjust_triadic);

    persist->rule_adjust_value_triadic.set(persist->rule_adjust_triadic);

    // Rule Adjust Tetradic.
    srv.Start(ATOM_TAG_RULE_ADJUST_TETRADIC, LXi_PERSIST_ATOM);
    srv.AddValue(LXsTYPE_ANGLE);
    srv.EndDef(persist->rule_adjust_tetradic);

    persist->rule_adjust_value_tetradic.set(persist->rule_adjust_tetradic);

    // Rule Adjust Compound.
    srv.Start(ATOM_TAG_RULE_ADJUST_COMPOUND, LXi_PERSIST_ATOM);
    srv.AddValue(LXsTYPE_ANGLE);
    srv.EndDef(persist->rule_adjust_compound);

    persist->rule_adjust_value_compound.set(persist->rule_adjust_compound);

    // Levels.
    srv.Start(ATOM_TAG_LEVELS, LXi_PERSIST_ATOM);
    srv.AddValue(LXsTYPE_INTEGER);
    srv.EndDef(persist->m_levels);

    persist->levels_value.set(persist->m_levels);

    return LXe_OK;
}

/*
 * ---------------------------------------------------------------------------
 * CHSVColorModelNotifier.
 */

static const char* HSV_COLOR_MODEL_NOTIFIER = "hsv.color.model.notifier";

CHSVColorModelNotifier::CHSVColorModelNotifier() : CLxCommandNotifier(HSV_COLOR_MODEL_NOTIFIER)
{
}

void CHSVColorModelNotifier::cn_Parse(std::string& /*args*/)
{
}

unsigned int CHSVColorModelNotifier::cn_Flags(int /*code*/)
{
    return LXfCMDNOTIFY_DISABLE | LXfCMDNOTIFY_VALUE;
}

/*
 * ---------------------------------------------------------------------------
 * CHueAsWheelHSVColorModelCommand
 */

#define LXsCOMMAND_COLOR_UPDATE_VIEW "color.updateView"
#define LXsCOMMAND_COLOR_MODEL_AXIS  "color.modelAxis"

enum
{
    HUE_AS_WHEEL_HSV_COLOR_MODEL_VALUE
};

const bool PRESET_HSV_HUE_AS_WHEEL = true;

CHueAsWheelHSVColorModelCommand::CHueAsWheelHSVColorModelCommand()
{
    dyna_Add("value", LXsTYPE_BOOLEAN);

    basic_SetFlags(HUE_AS_WHEEL_HSV_COLOR_MODEL_VALUE, LXfCMDARG_QUERY);
}

int CHueAsWheelHSVColorModelCommand::basic_CmdFlags()
{
    return LXfCMD_UI;
}

bool CHueAsWheelHSVColorModelCommand::basic_Notifier(int index, std::string& name, std::string& /*args*/)
{
    bool result;
    if (index == 0)
    {
        name   = HSV_COLOR_MODEL_NOTIFIER;
        result = true;
    }
    else if (index == 1)
    {
        name   = LXs_NOTIFIER_COLOR_CHANGED;
        result = true;
    }
    else
    {
        result = false;
    }

    return result;
}

bool CHueAsWheelHSVColorModelCommand::basic_Enable(CLxUser_Message& /*msg*/)
{
    /*
     * Enable if the strip is not set to the hue axis.
     */
    return !CHSVColorModel::HueAxisOnStrip();
}

enum
{
    NOTIFICATION_HUE_AS_WHEEL,
    NOTIFICATION_RULE
};

void CHueAsWheelHSVColorModelCommand::cmd_Execute(unsigned int /*flags*/)
{
    bool hueAsWheel = PRESET_HSV_HUE_AS_WHEEL;
    if (dyna_IsSet(0))
    {
        attr_GetBool(HUE_AS_WHEEL_HSV_COLOR_MODEL_VALUE, &hueAsWheel);
    }

    LxResult result = persist->hue_as_wheel.Append();
    if (LXx_OK(result) && persist->hue_as_wheel_value.Set(0, hueAsWheel))
    {
        CLxCommandNotifier::Notify(HSV_COLOR_MODEL_NOTIFIER, 0);

        basic_Message().SetCode(LXe_OK);

        ExecuteCommand(LXsCOMMAND_COLOR_UPDATE_VIEW);
    }
}

LxResult CHueAsWheelHSVColorModelCommand::cmd_Query(unsigned int /*index*/, ILxUnknownID vaQuery)
{
    CLxUser_ValueArray vals(vaQuery);

    return vals.Add(CHSVColorModel::HueAsWheel()) ? LXe_OK : LXe_NOTFOUND;
}

/*
 * ---------------------------------------------------------------------------
 * CWheelHSVColorModelCommand
 */

enum
{
    WHEEL_HSV_COLOR_MODEL_VALUE
};

const int PRESET_HSV_WHEEL = 0;

static LXtTextValueHint hint_hsvWheel[] = {
    { HSV_WHEEL_RGB, "rgb" },
    { HSV_WHEEL_RYB, "ryb" },
    { -1, nullptr },
};

CWheelHSVColorModelCommand::CWheelHSVColorModelCommand()
{
    dyna_Add("value", LXsTYPE_INTEGER);
    dyna_SetHint(0, hint_hsvWheel);

    basic_SetFlags(WHEEL_HSV_COLOR_MODEL_VALUE, LXfCMDARG_QUERY);
}

int CWheelHSVColorModelCommand::basic_CmdFlags()
{
    return LXfCMD_UI;
}

bool CWheelHSVColorModelCommand::basic_Notifier(int index, std::string& name, std::string& /*args*/)
{
    bool result;
    if (index == 0)
    {
        name   = HSV_COLOR_MODEL_NOTIFIER;
        result = true;
    }
    else if (index == 1)
    {
        name   = LXs_NOTIFIER_COLOR_CHANGED;
        result = true;
    }
    else
    {
        result = false;
    }

    return result;
}

bool CWheelHSVColorModelCommand::basic_Enable(CLxUser_Message& /*msg*/)
{
    return CHSVColorModel::HueAsWheel() && !CHSVColorModel::HueAxisOnStrip();
}

void CWheelHSVColorModelCommand::cmd_Execute(unsigned int /*flags*/)
{
    int wheel = PRESET_HSV_WHEEL;
    if (dyna_IsSet(0))
    {
        attr_GetInt(WHEEL_HSV_COLOR_MODEL_VALUE, &wheel);
    }

    LxResult result = persist->wheel.Append();
    if (LXx_OK(result) && persist->wheel_value.Set(0, wheel))
    {
        CLxCommandNotifier::Notify(HSV_COLOR_MODEL_NOTIFIER, 0);

        basic_Message().SetCode(LXe_OK);

        ExecuteCommand(LXsCOMMAND_COLOR_UPDATE_VIEW);
    }
}

LxResult CWheelHSVColorModelCommand::cmd_Query(unsigned int /*index*/, ILxUnknownID vaQuery)
{
    int wheel = persist->wheel_value.Int(0, PRESET_HSV_WHEEL);

    CLxUser_ValueArray vals(vaQuery);

    return vals.Add(wheel) ? LXe_OK : LXe_NOTFOUND;
}

void CWheelHSVColorModelCommand::atrui_UIHints2(unsigned int /*index*/, CLxUser_UIHints& /*hints*/)
{
}

/*
 * ---------------------------------------------------------------------------
 * CRuleHSVColorModelCommand
 */

enum
{
    RULE_HSV_COLOR_MODEL_VALUE
};

const int PRESET_HSV_RULE = 0;

static LXtTextValueHint hint_hsvRule[] = {
    { HSV_RULE_SOLO, "solo" },
    { HSV_RULE_COMPLEMENTARY, "complementary" },
    { HSV_RULE_ANALOGOUS, "analogous" },
    { HSV_RULE_TRIADIC, "triadic" },
    { HSV_RULE_TETRADIC, "tetradic" },
    { HSV_RULE_COMPOUND, "compound" },
    { HSV_RULE_TINTS, "tints" },
    { HSV_RULE_SHADES, "shades" },
    { -1, nullptr },
};

CRuleHSVColorModelCommand::CRuleHSVColorModelCommand()
{
    dyna_Add("value", LXsTYPE_INTEGER);
    dyna_SetHint(0, hint_hsvRule);

    basic_SetFlags(RULE_HSV_COLOR_MODEL_VALUE, LXfCMDARG_QUERY);
}

int CRuleHSVColorModelCommand::basic_CmdFlags()
{
    return LXfCMD_UI;
}

bool CRuleHSVColorModelCommand::basic_Notifier(int index, std::string& name, std::string& /*args*/)
{
    bool result;
    if (index == 0)
    {
        name   = HSV_COLOR_MODEL_NOTIFIER;
        result = true;
    }
    else if (index == 1)
    {
        name   = LXs_NOTIFIER_COLOR_CHANGED;
        result = true;
    }
    else
    {
        result = false;
    }

    return result;
}

bool CRuleHSVColorModelCommand::basic_Enable(CLxUser_Message& /*msg*/)
{
    return CHSVColorModel::HueAsWheel() && !CHSVColorModel::HueAxisOnStrip();
}

void CRuleHSVColorModelCommand::cmd_Execute(unsigned int /*flags*/)
{
    int rule = PRESET_HSV_RULE;
    if (dyna_IsSet(0))
    {
        attr_GetInt(RULE_HSV_COLOR_MODEL_VALUE, &rule);
    }

    LxResult result = persist->rule.Append();
    if (LXx_OK(result) && persist->rule_value.Set(0, rule))
    {
        CLxCommandNotifier::Notify(HSV_COLOR_MODEL_NOTIFIER, 0);

        basic_Message().SetCode(LXe_OK);

        ExecuteCommand(LXsCOMMAND_COLOR_UPDATE_VIEW);
    }
}

LxResult CRuleHSVColorModelCommand::cmd_Query(unsigned int /*index*/, ILxUnknownID vaQuery)
{
    int rule = persist->rule_value.Int(0, PRESET_HSV_RULE);

    CLxUser_ValueArray vals(vaQuery);

    return vals.Add(rule) ? LXe_OK : LXe_NOTFOUND;
}

void CRuleHSVColorModelCommand::atrui_UIHints2(unsigned int /*index*/, CLxUser_UIHints& /*hints*/)
{
}

/*
 * ---------------------------------------------------------------------------
 * CRuleAdjustHSVColorModelCommand
 */

enum
{
    RULE_ADJUST_HSV_COLOR_MODEL_VALUE
};

/*
 * Preset rule adjust values vary by rule.
 */
const double DEG2RAD = 0.017453292519943295769236907684886;

const double PRESET_HSV_RULE_ADJUST_COMPLEMENTARY = 180.0 * DEG2RAD;
const double PRESET_HSV_RULE_ADJUST_ANALOGOUS     = 30.0 * DEG2RAD;
const double PRESET_HSV_RULE_ADJUST_TRIADIC       = 120.0 * DEG2RAD;
const double PRESET_HSV_RULE_ADJUST_TETRADIC      = 45.0 * DEG2RAD;
const double PRESET_HSV_RULE_ADJUST_COMPOUND      = 30.0 * DEG2RAD;

CRuleAdjustHSVColorModelCommand::CRuleAdjustHSVColorModelCommand()
{
    dyna_Add("value", LXsTYPE_ANGLE);

    basic_SetFlags(RULE_ADJUST_HSV_COLOR_MODEL_VALUE, LXfCMDARG_QUERY);
}

int CRuleAdjustHSVColorModelCommand::basic_CmdFlags()
{
    return LXfCMD_UI;
}

bool CRuleAdjustHSVColorModelCommand::basic_Notifier(int index, std::string& name, std::string& /*args*/)
{
    bool result;
    if (index == 0)
    {
        name   = HSV_COLOR_MODEL_NOTIFIER;
        result = true;
    }
    else if (index == 1)
    {
        name   = LXs_NOTIFIER_COLOR_CHANGED;
        result = true;
    }
    else
    {
        result = false;
    }

    return result;
}

bool CRuleAdjustHSVColorModelCommand::basic_Enable(CLxUser_Message& /*msg*/)
{
    int rule = CHSVColorModel::Rule();

    return CHSVColorModel::HueAsWheel() && !CHSVColorModel::HueAxisOnStrip() &&
           ((rule != HSV_RULE_TINTS) && (rule != HSV_RULE_SHADES) && (rule != HSV_RULE_SOLO));
}

void CRuleAdjustHSVColorModelCommand::cmd_Execute(unsigned int /*flags*/)
{
    double ruleAdjust = CHSVColorModel::PresetRuleAdjust();
    if (dyna_IsSet(0))
    {
        attr_GetFlt(RULE_ADJUST_HSV_COLOR_MODEL_VALUE, &ruleAdjust);
    }

    LxResult result = LXe_OK;
    unsigned rule   = CHSVColorModel::Rule();
    switch (rule)
    {
        case HSV_RULE_COMPLEMENTARY:
            result = persist->rule_adjust_complementary.Append();
            if (LXx_OK(result))
            {
                persist->rule_adjust_value_complementary.Set(0, ruleAdjust);
            }
            break;

        case HSV_RULE_ANALOGOUS:
            result = persist->rule_adjust_analogous.Append();
            if (LXx_OK(result))
            {
                persist->rule_adjust_value_analogous.Set(0, ruleAdjust);
            }
            break;

        case HSV_RULE_TRIADIC:
            result = persist->rule_adjust_triadic.Append();
            if (LXx_OK(result))
            {
                persist->rule_adjust_value_triadic.Set(0, ruleAdjust);
            }
            break;

        case HSV_RULE_TETRADIC:
            result = persist->rule_adjust_tetradic.Append();
            if (LXx_OK(result))
            {
                persist->rule_adjust_value_tetradic.Set(0, ruleAdjust);
            }
            break;

        case HSV_RULE_COMPOUND:
            result = persist->rule_adjust_compound.Append();
            if (LXx_OK(result))
            {
                persist->rule_adjust_value_compound.Set(0, ruleAdjust);
            }
            break;
    }

    if (LXx_OK(result))
    {
        basic_Message().SetCode(LXe_OK);

        ExecuteCommand(LXsCOMMAND_COLOR_UPDATE_VIEW);
    }
}

LxResult CRuleAdjustHSVColorModelCommand::cmd_Query(unsigned int /*index*/, ILxUnknownID vaQuery)
{
    CLxUser_ValueArray vals(vaQuery);

    return vals.Add(CHSVColorModel::RuleAdjust()) ? LXe_OK : LXe_NOTFOUND;
}

void CRuleAdjustHSVColorModelCommand::atrui_UIHints2(unsigned int /*index*/, CLxUser_UIHints& hints)
{
    // Angles are in radians.
    hints.MinFloat(-PI);
    hints.MaxFloat(PI);
}

/*
 * ---------------------------------------------------------------------------
 * CLevelsHSVColorModelCommand
 */

enum
{
    LEVELS_HSV_COLOR_MODEL_VALUE
};

const int PRESET_HSV_LEVELS = 11;

CLevelsHSVColorModelCommand::CLevelsHSVColorModelCommand()
{
    dyna_Add("value", LXsTYPE_INTEGER);

    basic_SetFlags(LEVELS_HSV_COLOR_MODEL_VALUE, LXfCMDARG_QUERY);
}

int CLevelsHSVColorModelCommand::basic_CmdFlags()
{
    return LXfCMD_UI;
}

bool CLevelsHSVColorModelCommand::basic_Notifier(int index, std::string& name, std::string& /*args*/)
{
    bool result;
    if (index == 0)
    {
        name   = HSV_COLOR_MODEL_NOTIFIER;
        result = true;
    }
    else if (index == 1)
    {
        name   = LXs_NOTIFIER_COLOR_CHANGED;
        result = true;
    }
    else
    {
        result = false;
    }

    return result;
}

bool CLevelsHSVColorModelCommand::basic_Enable(CLxUser_Message& /*msg*/)
{
    int rule = CHSVColorModel::Rule();

    return CHSVColorModel::HueAsWheel() && !CHSVColorModel::HueAxisOnStrip() && ((rule == HSV_RULE_TINTS) || (rule == HSV_RULE_SHADES));
}

void CLevelsHSVColorModelCommand::cmd_Execute(unsigned int /*flags*/)
{
    int levels = PRESET_HSV_LEVELS;
    if (dyna_IsSet(0))
    {
        attr_GetInt(LEVELS_HSV_COLOR_MODEL_VALUE, &levels);
    }

    LxResult result = persist->m_levels.Append();
    if (LXx_OK(result) && persist->levels_value.Set(0, levels))
    {
        basic_Message().SetCode(LXe_OK);

        ExecuteCommand(LXsCOMMAND_COLOR_UPDATE_VIEW);
    }
}

LxResult CLevelsHSVColorModelCommand::cmd_Query(unsigned int /*index*/, ILxUnknownID vaQuery)
{
    CLxUser_ValueArray vals(vaQuery);

    return vals.Add(static_cast<int>(CHSVColorModel::Levels())) ? LXe_OK : LXe_NOTFOUND;
}

void CLevelsHSVColorModelCommand::atrui_UIHints2(unsigned int /*index*/, CLxUser_UIHints& hints)
{
    hints.MinInt(3);
    hints.MaxInt(21);
}

/*
 * ---------------------------------------------------------------------------
 * CSaveAsPresetsHSVColorModelCommand
 */

enum
{
    LEVELS_HSV_COLOR_MODEL_SAVE_AS_PRESETS
};

CSaveAsPresetsHSVColorModelCommand::CSaveAsPresetsHSVColorModelCommand()
{
    dyna_Add("value", LXsTYPE_BOOLEAN);

    basic_SetFlags(LEVELS_HSV_COLOR_MODEL_SAVE_AS_PRESETS, LXfCMDARG_QUERY);
}

int CSaveAsPresetsHSVColorModelCommand::basic_CmdFlags()
{
    return LXfCMD_UI;
}

bool CSaveAsPresetsHSVColorModelCommand::basic_Notifier(int index, std::string& name, std::string& /*args*/)
{
    bool result;
    if (index == 0)
    {
        name   = HSV_COLOR_MODEL_NOTIFIER;
        result = true;
    }
    else if (index == 1)
    {
        name   = LXs_NOTIFIER_COLOR_CHANGED;
        result = true;
    }
    else
    {
        result = false;
    }

    return result;
}

bool CSaveAsPresetsHSVColorModelCommand::basic_Enable(CLxUser_Message& /*msg*/)
{
    return CHSVColorModel::HueAsWheel() && !CHSVColorModel::HueAxisOnStrip();
}

/*
 * Query a series of color.value commands, to retrieve the selected
 * base color's component values, from which the rule-based color
 * swatches will be built.
 */
static bool QueryColorValueCmd(HSVColor& baseColor)
{
    bool foundValues = false;

    for (unsigned index = 0; index < 3; ++index)
    {
        bool                foundValue = false;
        CLxCommandQuery     colorValueQuery("color.value");
        CLxUser_Attributes& arg(colorValueQuery.Arguments());

        /*
         * Look up the argument indices.
         */
        int modelNameArgIndex = arg.FindIndex("model");
        int componentArgIndex = arg.FindIndex("component");
        int valueArgIndex     = arg.FindIndex("value");

        /*
         * Set the color model name argument.
         */
        if (arg.Set(modelNameArgIndex, SERVER_HSV_COLOR_MODEL) && arg.Set(componentArgIndex, static_cast<int>(index)))
        {
            if (colorValueQuery.Query(valueArgIndex))
            {
                baseColor.vec[index] = static_cast<float>(colorValueQuery.GetFloat());
                foundValue           = true;
            }
        }

        foundValues = foundValue;
        if (!foundValue)
        {
            break;
        }
    }

    return foundValues;
}

static bool QueryPBViewPathCmd(std::string& path)
{
    bool                foundValue = false;
    CLxCommandQuery     pathQuery("pbview.currentPath");
    CLxUser_Attributes& arg(pathQuery.Arguments());

    int argIndex = arg.FindIndex("path");
    if (pathQuery.Query(argIndex))
    {
        pathQuery.GetString(path);
        foundValue = !path.empty();
    }

    return foundValue;
}

/*
 * Execute the color.presetSaveWithModel commmand,
 * to generate a preset for the given swatch.
 */
static void ExecuteHSVPresetSaveWithModelCmd(const HSVColor& hsvColor, unsigned /*swatchIndex*/, std::string& swatchPath)
{
    CLxUser_CommandService cmdSvc;
    CLxLoc_Command         presetSaveWithModelCmd;
    if (cmdSvc.NewCommand(presetSaveWithModelCmd, "color.presetSaveWithModel"))
    {
        CLxUser_Attributes arg;
        arg.set(presetSaveWithModelCmd);

        // Generate a unique filename by calling DirCacheService
        bool        uniqueFileName       = false;
        const char* BASE_COLOR_FILE_NAME = "color";
        const char* BASE_COLOR_EXTENSION = ".lxc";

        const unsigned FILE_NAME_PADDING = 7;
        const unsigned maxIndex          = static_cast<unsigned>(powf(10, static_cast<float>(FILE_NAME_PADDING)));

        CLxUser_DirCacheService dirSvc;
        dirSvc.ScanForChanges(nullptr);

        std::string           fullPath;
        CLxUser_DirCacheEntry entry;
        if (LXx_OK(dirSvc.Lookup(swatchPath.c_str(), entry)))
        {
            char resolvedPath[1024];
            if (LXx_OK(dirSvc.MakeUniqueIn(entry, BASE_COLOR_FILE_NAME, resolvedPath, 1024)))
            {
                // Need to ensure the output folder exists
                dirSvc.MakeDirHierarchy(resolvedPath, 1);

                // MakeUniqueIn returns a unique name according to the directory service's current *cached* list
                // of files.  However, we're called in a loop to save several colours, between each of which the
                // cache doesn't get updated, causing it to repeatedly return the same filename.
                // So we're actually only using it here to resolve the color swatch directory to a real path on disc.
                //
                // We also need the filename to be of the form color00123.lxc, rather than color_123.lxc
                // (i.e. with the leading 0's) the colours appear in order in the colour swatch as they're created.

                CLxUser_FileService fileSvc;
                std::string         folder;
                if (LXx_OK(fileSvc.ParsePath(resolvedPath, LXiFILECOMP_DIRECTORY, folder)))
                {
                    // Generate a non-existing filename of the form 'colorXXXXX.lxc'
                    for (int index = 0; index < maxIndex; index++)
                    {
                        std::string candidate = BASE_COLOR_FILE_NAME + IntegerToString(index, FILE_NAME_PADDING) + BASE_COLOR_EXTENSION;

                        if (LXx_OK(fileSvc.ComposePath(candidate.c_str(), folder.c_str(), fullPath)))
                        {
                            unsigned fileType;
                            if (LXx_OK(fileSvc.TestFileType(fullPath.c_str(), &fileType)))
                            {
                                if (fileType == LXiFILETYPE_NONE)
                                    uniqueFileName = true;
                            }
                        }

                        if (uniqueFileName)
                            break;
                    }
                }
            }
        }

        if (uniqueFileName)
        {
            /*
             * Look up the argument indices and set their values.
             */
            int filepathArgIndex  = arg.FindIndex("path");
            int modelNameArgIndex = arg.FindIndex("modelName");
            int c0ArgIndex        = arg.FindIndex("c0");
            int c1ArgIndex        = arg.FindIndex("c1");
            int c2ArgIndex        = arg.FindIndex("c2");
            if ((filepathArgIndex != -1) && (modelNameArgIndex != -1) && (c0ArgIndex != -1) && (c1ArgIndex != -1) && (c2ArgIndex != -1))
            {
                if (arg.Set(filepathArgIndex, fullPath.c_str()) && arg.Set(modelNameArgIndex, SERVER_HSV_COLOR_MODEL))
                {
                    /*
                     * Tell the command to set up
                     * the data types for its
                     * variable arguments.
                     */
                    if (LXx_OK(presetSaveWithModelCmd.ArgSetDatatypes()))
                    {
                        /*
                         * Set the color component values.
                         */
                        if (arg.Set(c0ArgIndex, hsvColor.vec[0]) && arg.Set(c1ArgIndex, hsvColor.vec[1]) && arg.Set(c2ArgIndex, hsvColor.vec[2]))
                        {
                            presetSaveWithModelCmd.Execute(0);
                        }
                    }
                }
            }
        }
    }
}

void CSaveAsPresetsHSVColorModelCommand::cmd_Execute(unsigned int /*flags*/)
{
    /*
     * Query the color.value command for each HSV component value.
     */
    HSVColor baseColor;
    if (QueryColorValueCmd(baseColor))
    {
        /*
         * Build the color swatches according to the selected color wheel rule.
         */
        std::vector<HSVColor> swatchColors;
        unsigned              baseColorIndex;
        CHSVColorModel::BuildSwatches(baseColor, swatchColors, baseColorIndex);

        /*
         * Ask the preset browser for the file path.
         */
        std::string swatchPath;
        if (QueryPBViewPathCmd(swatchPath))
        {
            /*
             * Execute a series of color.presetSaveWithModel commmands,
             * to generate a preset for each color swatch.
             */
            unsigned swatchCount = static_cast<unsigned>(swatchColors.size());
            for (unsigned swatchIndex = 0; swatchIndex < swatchCount; ++swatchIndex)
            {
                ExecuteHSVPresetSaveWithModelCmd(swatchColors[swatchIndex], swatchIndex, swatchPath);
            }
        }
    }
}

LxResult CSaveAsPresetsHSVColorModelCommand::cmd_Query(unsigned int /*index*/, ILxUnknownID vaQuery)
{
    int saveAsPresets = 0;

    CLxUser_ValueArray vals(vaQuery);

    return vals.Add(saveAsPresets) ? LXe_OK : LXe_NOTFOUND;
}

void CSaveAsPresetsHSVColorModelCommand::atrui_UIHints2(unsigned int /*index*/, CLxUser_UIHints& hints)
{
    hints.BooleanStyle(LXiBOOLEANSTYLE_BUTTON);
}

/*
 * ---------------------------------------------------------------------------
 * CHSVColorModel.
 */

LXtTagInfoDesc CHSVColorModel::descInfo[] = { { LXsLOD_CLASSLIST, LXa_COLORMODEL },
                                              { LXsSRV_USERNAME, "HSV" },
                                              { LXsSRV_LOGSUBSYSTEM, SERVER_HSV_COLOR_MODEL },
                                              { nullptr } };

/*
 * The minimum margin in pixels on all sides.
 */
const float HUE_WHEEL_MARGIN = 5.0f;

/*
 * The percentage of the major dimension to use for rule-based swatches.
 */
const float MINIMUM_SWATCH_SIZE = 0.15f;

/*
 * Aspect ratio.
 */
enum
{
    WHEEL_ASPECT_HORIZONTAL,
    WHEEL_ASPECT_VERTICAL
};

struct Metrics
{
    float slice_width;
    float slice_height;

    unsigned wheel_aspect;

    float wheel_radius;
    float wheel_centerX;
    float wheel_centerY;

    float swatch_width;
    float swatch_height;

    float wheel_back_width;
    float wheel_back_height;
};

static void ResizeWheelAndRuleSwatches(unsigned sliceWidth, unsigned sliceHeight, Metrics& metrics)
{
    metrics.slice_width  = static_cast<float>(sliceWidth);
    metrics.slice_height = static_cast<float>(sliceHeight);

    metrics.wheel_aspect = (metrics.slice_width > metrics.slice_height) ? WHEEL_ASPECT_HORIZONTAL : WHEEL_ASPECT_VERTICAL;

    unsigned swatchCount = CHSVColorModel::SwatchCount();
    if (swatchCount > 1)
    {
        if (metrics.wheel_aspect == WHEEL_ASPECT_HORIZONTAL)
        {
            float minSwatchWidth  = metrics.slice_width * MINIMUM_SWATCH_SIZE;
            metrics.swatch_width  = LXxMAX(minSwatchWidth, metrics.slice_width - metrics.slice_height);
            metrics.swatch_height = metrics.slice_height / swatchCount;

            metrics.wheel_back_width  = metrics.slice_width - metrics.swatch_width;
            metrics.wheel_back_height = metrics.slice_height;
        }
        else
        {
            float minSwatchHeight = metrics.slice_height * MINIMUM_SWATCH_SIZE;
            metrics.swatch_height = LXxMAX(minSwatchHeight, metrics.slice_height - metrics.slice_width);
            metrics.swatch_width  = metrics.slice_width / swatchCount;

            metrics.wheel_back_width  = metrics.slice_width;
            metrics.wheel_back_height = metrics.slice_height - metrics.swatch_height;
        }
    }
    else
    {
        metrics.swatch_width      = 0;
        metrics.swatch_height     = 0;
        metrics.wheel_back_width  = metrics.slice_width;
        metrics.wheel_back_height = metrics.slice_height;
    }

    if (metrics.wheel_back_width < metrics.wheel_back_height)
    {
        metrics.wheel_radius = metrics.wheel_back_width * 0.5f;
    }
    else
    {
        metrics.wheel_radius = metrics.wheel_back_height * 0.5f;
    }

    metrics.wheel_radius -= HUE_WHEEL_MARGIN;

    metrics.wheel_centerX = metrics.wheel_back_width * 0.5f;
    metrics.wheel_centerY = metrics.wheel_back_height * 0.5f;
}

/*
 * Return whether or not the given image (X, Y) coordinates are
 * tracking within a swatch.
 */
static bool TrackSwatch(Metrics& metrics,
                        unsigned xAxis,
                        unsigned /*yAxis*/,
                        unsigned /*imageWidth*/,
                        unsigned /*imageHeight*/,
                        unsigned   imageX,
                        unsigned   imageY,
                        LXtFVector downVec,
                        LXtFVector hsv)
{
    bool trackingSwatch = false;

    if ((xAxis == 0) && CHSVColorModel::HueAsWheel() && (CHSVColorModel::Rule() != HSV_RULE_SOLO))
    {
        if (metrics.wheel_aspect == WHEEL_ASPECT_VERTICAL)
        {
            trackingSwatch = imageY > metrics.wheel_back_height;
        }
        else
        {
            trackingSwatch = imageX > metrics.wheel_back_width;
        }

        if (trackingSwatch)
        {
            HSVColor baseColor;
            LXx_VCPY(baseColor.vec, downVec);
            std::vector<HSVColor> swatchColors;
            unsigned              baseColorIndex;
            CHSVColorModel::BuildSwatches(baseColor, swatchColors, baseColorIndex);

            unsigned swatchIndex;
            if (metrics.wheel_aspect == WHEEL_ASPECT_VERTICAL)
            {
                swatchIndex = static_cast<unsigned>(static_cast<float>(imageX) / metrics.swatch_width);
            }
            else
            {
                swatchIndex = static_cast<unsigned>(static_cast<float>(imageY) / metrics.swatch_height);
            }
            swatchIndex = LXxMIN(swatchIndex, static_cast<unsigned>(swatchColors.size() - 1));

            LXx_VCPY(hsv, swatchColors[swatchIndex].vec);
        }
    }

    return trackingSwatch;
}

CHSVColorModel::CHSVColorModel() : rangeWorker(nullptr)
{
    range_factory.AddInterface(new CLxIfc_ThreadRangeWorker<CHSVColorModelThreadRangeWorker>);

    if (persist == nullptr)
    {
        /*
         * Set up the persistent values.
         */
        persist = new CHSVColorModelPersist;

        CLxUser_PersistenceService   srv;
        CHSVColorModelPersistVisitor vis;
        srv.ConfigureVis(SERVER_HSV_COLOR_MODEL, &vis);
    }

/*
 * Pre-load the primary and secondary marker images.
 */
#define HSV_PRIMARY_SLICE_MARKER   "colorMarkerPrimary.tga"
#define HSV_SECONDARY_SLICE_MARKER "colorMarkerSecondary.tga"

    CLxUser_FileService fileSvc;
    std::string         systemPath;
    if (LXx_OK(fileSvc.FileSystemPath(LXsSYSTEM_PATH_RESOURCE, systemPath)))
    {
        std::string primaryMarkerPath(systemPath);
        primaryMarkerPath = primaryMarkerPath + std::string("/") + std::string(HSV_PRIMARY_SLICE_MARKER);

        std::string secondaryMarkerPath(systemPath);
        secondaryMarkerPath = secondaryMarkerPath + std::string("/") + std::string(HSV_SECONDARY_SLICE_MARKER);

        CLxUser_ImageService imageSvc;
        imageSvc.Load(primary_marker, primaryMarkerPath);
        imageSvc.Load(secondary_marker, secondaryMarkerPath);
    }
}

CHSVColorModel::~CHSVColorModel()
{
}

int CHSVColorModel::colm_NumComponents(void)
{
    return 3;  // H, S, and V
}

LxResult CHSVColorModel::colm_ComponentType(unsigned componentIndex, const char** type)
{
    if (componentIndex == 0)
    {
        *type = LXsTYPE_ANGLE;
    }
    else
    {
        *type = LXsTYPE_COLOR1;
    }

    return LXe_OK;
}

LxResult CHSVColorModel::colm_ComponentRange(unsigned componentIndex, float* minValue, float* maxValue)
{
    *minValue = 0.0f;

    if (componentIndex == 0)
    {
        *maxValue = static_cast<float>(TWO_PI);
    }
    else
    {
        *maxValue = 1.0f;
    }

    return LXe_OK;
}

LxResult CHSVColorModel::colm_ToRGB(const float* hsv, float* rgb)
{
    HSV2RGB(hsv, rgb);

    return LXe_OK;
}

LxResult CHSVColorModel::colm_FromRGB(const float* rgb, float* hsv)
{
    RGB2HSV(rgb, hsv);

    return LXe_OK;
}

#define LERP(a, l, h) ((l) + (((h) - (l)) * (a)))
const float DEG2RADF = static_cast<float>(DEG2RAD);

/*
 * Remap an HSV hue such that red, yellow, and blue are triadic,
 * instead of red, green, and blue.
 */
static inline float HueRGBtoRYB(float hue)
{
    float newHue;

    float hueRGB[9] = { 0, 30 * DEG2RADF, 60 * DEG2RADF, 90 * DEG2RADF, 120 * DEG2RADF, 150 * DEG2RADF, 180 * DEG2RADF, 210 * DEG2RADF, 240 * DEG2RADF };
    float hueRYB[9] = { 0, 15 * DEG2RADF, 30 * DEG2RADF, 45 * DEG2RADF, 60 * DEG2RADF, 90 * DEG2RADF, 120 * DEG2RADF, 180 * DEG2RADF, 240 * DEG2RADF };

    unsigned index = static_cast<unsigned>(hue / SIXTH_PI);
    if (index < 8)
    {
        float low, hi, t;

        low = hueRGB[index];
        hi  = hueRGB[index + 1];
        t   = (hue - low) / (hi - low);

        low = hueRYB[index];
        hi  = hueRYB[index + 1];

        newHue = LERP(t, low, hi);
    }
    else
    {
        newHue = hue;
    }

    return newHue;
}

/*
 * The inverse of HueRGBtoRYB.
 */
static inline float HueRYBtoRGB(float hue)
{
    float newHue;

    float hueRYB[9] = { 0, 15 * DEG2RADF, 30 * DEG2RADF, 45 * DEG2RADF, 60 * DEG2RADF, 90 * DEG2RADF, 120 * DEG2RADF, 180 * DEG2RADF, 240 * DEG2RADF };
    float hueRGB[9] = { 0, 30 * DEG2RADF, 60 * DEG2RADF, 90 * DEG2RADF, 120 * DEG2RADF, 150 * DEG2RADF, 180 * DEG2RADF, 210 * DEG2RADF, 240 * DEG2RADF };

    bool     convert = false;
    unsigned index;
    for (index = 0; index < 8; ++index)
    {
        if (hue >= hueRYB[index] && hue <= hueRYB[index + 1])
        {
            convert = true;
            break;
        }
    }
    if (convert)
    {
        float low, hi, t;

        low = hueRYB[index];
        hi  = hueRYB[index + 1];
        t   = (hue - low) / (hi - low);

        low = hueRGB[index];
        hi  = hueRGB[index + 1];

        newHue = LERP(t, low, hi);
    }
    else
    {
        newHue = hue;
    }

    return newHue;
}

CHSVColorModelThreadRangeWorker::CHSVColorModelThreadRangeWorker()
{
}

CHSVColorModelThreadRangeWorker::~CHSVColorModelThreadRangeWorker()
{
}

typedef struct st_HSVColorModelDrawSlice_env
{
    CLxUser_ImageWrite* writeImage;
    float               halfWidth;
    float               halfHeight;
    Metrics*            metrics;
    int                 yAxis;
    const float*        vec;
    unsigned            wheel;
} HSVColorModelDrawSlice_env;

LxResult CHSVColorModelThreadRangeWorker::rngw_Execute(int index, void* sharedData)
{
    int                         y = index;
    HSVColorModelDrawSlice_env* env;
    LxResult                    result = LXe_OK;

    env                      = reinterpret_cast<HSVColorModelDrawSlice_env*>(sharedData);
    LXtImageByte* lineBuffer = new LXtImageByte[static_cast<unsigned>(env->metrics->slice_width) * 4];
    LXtImageByte* pixel      = lineBuffer;

    for (unsigned x = 0; x < env->metrics->slice_width; ++x)
    {
        float xt = static_cast<float>(x) - env->halfWidth;
        float yt = static_cast<float>(y) - env->halfHeight;
        bool  inside;
        float hsv[3];
        float rgb[3];

        // [TODO] Test boundary before radius.
        float colorRadius = sqrtf(xt * xt + yt * yt);
        inside            = colorRadius <= env->metrics->wheel_radius;
        if (inside)
        {
            float angle = 0;
            if (yt != 0)
            {
                angle = atan2(yt, xt) + static_cast<float>(PI);
            }
            else if (xt > 0)
            {
                angle = static_cast<float>(PI);
            }

            /*
             * Position red (0) at 3 o'clock.
             */
            angle = TWO_PI - angle - PI;
            if (angle < 0)
            {
                angle += TWO_PI;
            }

            if (env->wheel == HSV_WHEEL_RYB)
            {
                /*
                 * RYB wheel.
                 */
                angle = HueRGBtoRYB(angle);
            }

            hsv[0] = static_cast<float>(angle);

            /*
             * Vary the saturation or the value,
             * depending on the active center axis.
             */
            if (env->yAxis == 1)
            {
                hsv[1] = static_cast<float>(colorRadius / env->metrics->wheel_radius);
                hsv[2] = env->vec[2];
            }
            else
            {
                hsv[1] = env->vec[1];
                hsv[2] = static_cast<float>(colorRadius / env->metrics->wheel_radius);
            }

            HSV2RGB(hsv, rgb);
            pixel[0] = static_cast<LXtImageByte>(rgb[0] * 255.0);
            pixel[1] = static_cast<LXtImageByte>(rgb[1] * 255.0);
            pixel[2] = static_cast<LXtImageByte>(rgb[2] * 255.0);

            /*
             * Anti-aliased alpha for the edge.
             */
            const float EDGE_SOFTNESS = 2.0;
            if (colorRadius > env->metrics->wheel_radius - EDGE_SOFTNESS)
            {
                pixel[3] = static_cast<LXtImageByte>((env->metrics->wheel_radius - colorRadius) / EDGE_SOFTNESS * 255.0f);
            }
            else
            {
                pixel[3] = 255;
            }
        }
        else
        {
            pixel[0] = pixel[1] = pixel[2] = 128;
            pixel[3]                       = 0;
        }

        pixel += 4;
    }

    result = env->writeImage->SetLine(y, LXiIMP_RGBA32, lineBuffer);

    delete[] lineBuffer;

    return result;
}

LxResult CHSVColorModel::colm_DrawSlice(ILxUnknownID image, unsigned xAxis, unsigned yAxis, const float* vec)
{
    LxResult           result = LXe_OK;
    CLxUser_ImageWrite writeImage;
    CLxUser_Image      readImage;

    /*
     * Save time by fetching the user values outside of the loops.
     */
    bool hueAsWheel = HueAsWheel();

    writeImage.set(image);
    readImage.set(image);

    unsigned width, height;
    writeImage.Size(&width, &height);

    Metrics metrics;
    ResizeWheelAndRuleSwatches(width, height, metrics);

    /*
     * Calculate the radius of the wheel, inset by the margin.
     */
    float halfWidth  = metrics.wheel_back_width * 0.5f;
    float halfHeight = metrics.wheel_back_height * 0.5f;

    CLxUser_ThreadService threadSvc;
    if ((threadSvc.NumProcs() > 1) && (xAxis == 0) && hueAsWheel)
    {
        // Multi-threaded version
        HSVColorModelDrawSlice_env env;
        env.writeImage = &writeImage;
        env.halfWidth  = halfWidth;
        env.halfHeight = halfHeight;
        env.metrics    = &metrics;
        env.yAxis      = yAxis;
        env.vec        = vec;
        env.wheel      = Wheel();

        // Create the range worker if this is the first call.
        result = LXe_OK;
        if (rangeWorker == nullptr)
        {
            rangeWorker = range_factory.Spawn();
            if (rangeWorker == nullptr)
            {
                result = LXe_FAILED;
            }
        }
        if (LXx_OK(result))
        {
            result = threadSvc.ProcessRange(&env, 0, static_cast<int>(metrics.slice_height - 1), rangeWorker);
        }
    }
    else
    {
        // Single-threaded version
        LXtImageByte* lineBuffer;
        lineBuffer = new LXtImageByte[static_cast<unsigned>(metrics.slice_width) * 4];

        float hsv[3], rgb[3];
        for (unsigned y = 0; y < metrics.slice_height; ++y)
        {
            LXtImageByte* pixel = lineBuffer;
            if (xAxis == 0)
            {
                if (hueAsWheel)
                {
                    for (unsigned x = 0; x < metrics.slice_width; ++x)
                    {
                        float xt = static_cast<float>(x) - halfWidth;
                        float yt = static_cast<float>(y) - halfHeight;
                        bool  inside;

                        // [TODO] Test boundary before radius.
                        float colorRadius = sqrtf(xt * xt + yt * yt);
                        inside            = colorRadius <= metrics.wheel_radius;
                        if (inside)
                        {
                            float angle = 0;
                            if (yt != 0)
                            {
                                angle = atan2(yt, xt) + static_cast<float>(PI);
                            }
                            else if (xt > 0)
                            {
                                angle = static_cast<float>(PI);
                            }

                            /*
                             * Position red (0) at 3 o'clock.
                             */
                            angle = TWO_PI - angle - PI;
                            if (angle < 0)
                            {
                                angle += TWO_PI;
                            }

                            if (Wheel() == HSV_WHEEL_RYB)
                            {
                                /*
                                 * RYB wheel.
                                 */
                                angle = HueRGBtoRYB(angle);
                            }

                            _H = static_cast<float>(angle);

                            /*
                             * Vary the saturation or the value,
                             * depending on the active center axis.
                             */
                            if (yAxis == 1)
                            {
                                _S = static_cast<float>(colorRadius / metrics.wheel_radius);
                                _V = vec[2];
                            }
                            else
                            {
                                _S = vec[1];
                                _V = static_cast<float>(colorRadius / metrics.wheel_radius);
                            }

                            HSV2RGB(hsv, rgb);
                            pixel[0] = static_cast<LXtImageByte>(_R * 255.0);
                            pixel[1] = static_cast<LXtImageByte>(_G * 255.0);
                            pixel[2] = static_cast<LXtImageByte>(_B * 255.0);

                            /*
                             * Anti-aliased alpha for the edge.
                             */
                            const float EDGE_SOFTNESS = 2.0;
                            if (colorRadius > metrics.wheel_radius - EDGE_SOFTNESS)
                            {
                                pixel[3] = static_cast<LXtImageByte>((metrics.wheel_radius - colorRadius) / EDGE_SOFTNESS * 255.0f);
                            }
                            else
                            {
                                pixel[3] = 255;
                            }
                        }
                        else
                        {
                            pixel[0] = pixel[1] = pixel[2] = 128;
                            pixel[3]                       = 0;
                        }

                        pixel += 4;
                    }
                }
                else
                {
                    // Draw the square, variable hue format, varying
                    // the hue and the saturation or value.
                    if (yAxis == 1)
                    {
                        _S = static_cast<float>(y) / metrics.slice_height;
                        _V = vec[2];
                    }
                    else
                    {  // yAxis == 2
                        _S = vec[1];
                        _V = static_cast<float>(y) / metrics.slice_height;
                    }
                    for (unsigned x = 0; x < width; ++x)
                    {
                        _H = (static_cast<float>(x) / metrics.slice_width) * static_cast<float>(TWO_PI);
                        HSV2RGB(hsv, rgb);
                        pixel[0] = static_cast<LXtImageByte>(_R * 255.0);
                        pixel[1] = static_cast<LXtImageByte>(_G * 255.0);
                        pixel[2] = static_cast<LXtImageByte>(_B * 255.0);
                        pixel[3] = 255;
                        pixel += 4;
                    }
                }
            }
            else
            {  // xAxis == 1
                // Draw the square, fixed hue format, varying both
                // the saturation and value.
                _H = vec[0];
                _S = static_cast<float>(y) / metrics.slice_height;
                for (unsigned x = 0; x < width; ++x)
                {
                    _V = static_cast<float>(x) / metrics.slice_width;
                    HSV2RGB(hsv, rgb);
                    pixel[0] = static_cast<LXtImageByte>(_R * 255.0);
                    pixel[1] = static_cast<LXtImageByte>(_G * 255.0);
                    pixel[2] = static_cast<LXtImageByte>(_B * 255.0);
                    pixel[3] = 255;
                    pixel += 4;
                }
            }

            result = writeImage.SetLine(y, LXiIMP_RGBA32, lineBuffer);
        }
        delete[] lineBuffer;
    }

    return result;
}

class RGBColor
{
public:
    LXtFVector vec{};
};

class Point2D
{
public:
    LXtUVector2 vec{};
};

static CLxLoc_ColorMapping colorMapping;

static inline void setPixel(LXtImageByte* pixel, LXtFVector color)
{
    float*     finalColor = color;
    LXtFVector corrected;
    if (colorMapping.test())
    {
        colorMapping.FromLinear(color, corrected, 3);
        finalColor = corrected;
    }

    pixel[0] = static_cast<LXtImageByte>(finalColor[0] * 255.0);
    pixel[1] = static_cast<LXtImageByte>(finalColor[1] * 255.0);
    pixel[2] = static_cast<LXtImageByte>(finalColor[2] * 255.0);
    pixel[3] = 255;
}

LxResult CHSVColorModel::colm_DrawSliceMarker(ILxUnknownID image, unsigned xAxis, unsigned yAxis, const float* downVec, const float* /*hsv*/)
{
    CLxUser_ImageService imageSvc;
    LxResult             result{};

    unsigned    rule = Rule();
    std::string msgTxt("DrawSliceMarker Rule: ");
    msgTxt += IntegerToString(rule);
    m_log.Info(msgTxt.c_str());

    if ((xAxis == 0) && HueAsWheel())
    {
        CLxUser_Image readImage;
        readImage.set(image);
        unsigned width, height;
        readImage.Size(&width, &height);

        Metrics metrics;
        ResizeWheelAndRuleSwatches(width, height, metrics);

        HSVColor baseColor;
        LXx_VCPY(baseColor.vec, downVec);
        std::vector<HSVColor> swatchColors;
        unsigned              baseColorIndex;
        BuildSwatches(baseColor, swatchColors, baseColorIndex);

        /*
         * Convert HSV color array to RGB.
         */
        std::vector<RGBColor> rgbSwatchColors;
        unsigned              swatchCount = static_cast<unsigned>(swatchColors.size());
        for (unsigned swatchIndex = 0; swatchIndex < swatchCount; ++swatchIndex)
        {
            RGBColor rgbColor;
            HSV2RGB(swatchColors[swatchIndex].vec, rgbColor.vec);
            rgbSwatchColors.push_back(rgbColor);
        }

        /*
         * Calculate the marker points.
         */
        std::vector<Point2D> markerPoints;
        unsigned             testMarkerCount = static_cast<unsigned>(markerPoints.size());
        m_log.Info(std::string(std::string("DrawSliceMarker: testMarkerCount ") + IntegerToString(testMarkerCount)).c_str());
        int _rule = Rule();
        if ((_rule != HSV_RULE_TINTS) && (_rule != HSV_RULE_SHADES))
        {
            unsigned markerCount = static_cast<unsigned>(swatchColors.size());
            m_log.Info(std::string(std::string("DrawSliceMarker: markerCount ") + IntegerToString(markerCount)).c_str());
            for (unsigned markerIndex = 0; markerIndex < markerCount; ++markerIndex)
            {
                unsigned markerX, markerY;
                colm_ToSlicePos(0,
                                yAxis,
                                static_cast<unsigned>(metrics.slice_width),
                                static_cast<unsigned>(metrics.slice_height),
                                swatchColors[markerIndex].vec,
                                &markerX,
                                &markerY);

                Point2D markerPoint;
                markerPoint.vec[0] = markerX;
                markerPoint.vec[1] = markerY;

                testMarkerCount = static_cast<unsigned>(markerPoints.size());
                m_log.Info(std::string(std::string("DrawSliceMarker: testMarkerCount' ") + IntegerToString(testMarkerCount)).c_str());
                markerPoints.push_back(markerPoint);
                testMarkerCount = static_cast<unsigned>(markerPoints.size());
                m_log.Info(std::string(std::string("DrawSliceMarker: testMarkerCount'' ") + IntegerToString(testMarkerCount)).c_str());
            }
        }
        else
        {  // tints or shades
            unsigned markerX, markerY;
            colm_ToSlicePos(
            0, yAxis, static_cast<unsigned>(metrics.slice_width), static_cast<unsigned>(metrics.slice_height), baseColor.vec, &markerX, &markerY);

            Point2D markerPoint;
            markerPoint.vec[0] = markerX;
            markerPoint.vec[1] = markerY;

            markerPoints.push_back(markerPoint);

            /*
             * Hue is constant. Saturation or Value is constant
             * based on the major axis for the rule.
             */
            HSVColor hsvColor;
            LXx_VCPY(hsvColor.vec, baseColor.vec);

            unsigned majorAxis = _rule == HSV_RULE_TINTS ? 1 : 2;
            unsigned levels    = Levels();
            for (unsigned levelIndex = 0; levelIndex < levels; ++levelIndex)
            {
                hsvColor.vec[majorAxis] = static_cast<float>(levelIndex) / (levels - 1);

                if ((yAxis == majorAxis) && ((levelIndex == 0) || (levelIndex == levels - 1)))
                {
                    colm_ToSlicePos(0,
                                    yAxis,
                                    static_cast<unsigned>(metrics.slice_width),
                                    static_cast<unsigned>(metrics.slice_height),
                                    hsvColor.vec,
                                    &markerX,
                                    &markerY);
                    markerPoint.vec[0] = markerX;
                    markerPoint.vec[1] = markerY;

                    markerPoints.push_back(markerPoint);
                }
            }
        }

        if (_rule != HSV_RULE_SOLO)
        {
            CLxUser_Image _readImage;
            _readImage.set(image);

            /*
             * Draw lines from the wheel center to each marker.
             */
            unsigned markerCount = static_cast<unsigned>(markerPoints.size());
            for (unsigned markerIndex = 0; markerIndex < markerCount; ++markerIndex)
            {
                LXtFVector2 p0 = { metrics.wheel_centerX, metrics.wheel_centerY };

                Point2D     markerPoint = markerPoints[markerIndex];
                LXtFVector2 p1          = { static_cast<float>(markerPoint.vec[0]), static_cast<float>(markerPoint.vec[1]) };

                /*
                 * Reduce the line length by 10 pixels.
                 */
                p1[0] -= p0[0];
                p1[1] -= p0[1];
                float len = sqrtf(p1[0] * p1[0] + p1[1] * p1[1]);
                if (len > 0.0001f)
                {
                    float newLen = len - 10.0f;
                    newLen       = LXxMAX(newLen, 0.0f);
                    float scale  = newLen / len;
                    p1[0] *= scale;
                    p1[1] *= scale;
                    p1[0] += p0[0];
                    p1[1] += p0[1];
                }

                /*
                 * Draw the line in black.
                 * [TODO] Flip to white for a dark wheel.
                 */
                float rgbBlack[4] = { 0, 0, 0 };
                imageSvc.DrawLine(_readImage, p0, p1, rgbBlack);
            }

            /*
             * Draw the swatches.
             */
            CLxUser_ImageWrite writeImage;
            writeImage.set(image);

            CLxReadPreferenceValue readPref;
            readPref.Query("colormanagement.colorMappingApplyToColorSwatches");
            if (readPref.GetInt())
            {
                ILxUnknownID iunk_colorMapping;
                CLxLoc_ColorMappingService().GetDisplayColorMapping(reinterpret_cast<void**>(&iunk_colorMapping));
                colorMapping.set(iunk_colorMapping);
            }
            else
                colorMapping.set(nullptr);

            LXtImageByte* lineBuffer;
            lineBuffer = new LXtImageByte[static_cast<unsigned>(metrics.slice_width) * 4];

            /*
             * For a tall aspect ratio, draw the swatches underneath the wheel.
             */
            if (metrics.wheel_aspect == WHEEL_ASPECT_VERTICAL)
            {
                for (unsigned y2 = static_cast<unsigned>(metrics.wheel_back_height); y2 < static_cast<unsigned>(metrics.slice_height); ++y2)
                {
                    LXtImageByte* pixel        = lineBuffer;
                    unsigned      _swatchCount = static_cast<unsigned>(rgbSwatchColors.size());
                    float         swatchPos    = 0;
                    for (unsigned hSwatchIndex = 0; hSwatchIndex < _swatchCount; ++hSwatchIndex)
                    {
                        RGBColor rgbColor;
                        LXx_VCPY(rgbColor.vec, rgbSwatchColors[hSwatchIndex].vec);
                        pixel               = lineBuffer;
                        unsigned swatchLeft = static_cast<unsigned>(swatchPos);
                        pixel += swatchLeft * 4;
                        unsigned swatchRight = static_cast<unsigned>(swatchPos + metrics.swatch_width + 0.5f);
                        swatchRight          = LXxMIN(swatchRight, static_cast<unsigned>(metrics.wheel_back_width));
                        for (unsigned x = static_cast<unsigned>(swatchPos); x < swatchRight; ++x)
                        {
                            setPixel(pixel, rgbColor.vec);
                            pixel += 4;
                        }
                        swatchPos += metrics.swatch_width;
                    }

                    result = writeImage.SetLine(y2, LXiIMP_RGBA32, lineBuffer);
                }
            }
            else
            {
                /*
                 * For wide aspect ratio, draw the swatches
                 * to the right side of the wheel.
                 */
                CLxLoc_ImageSegment imageSeg;
                imageSeg.set(image);

                RGBColor rgbColor;
                unsigned vSwatchIndex = UINT_MAX, wheelBackWidth = static_cast<unsigned>(metrics.wheel_back_width);
                for (unsigned y = 0; y < metrics.wheel_back_height; ++y)
                {
                    LXtImageByte* pixel          = lineBuffer;
                    unsigned      newSwatchIndex = static_cast<unsigned>(static_cast<float>(y) / metrics.swatch_height);
                    newSwatchIndex               = LXxMIN(newSwatchIndex, static_cast<unsigned>(rgbSwatchColors.size() - 1));
                    if (newSwatchIndex != vSwatchIndex)
                    {
                        vSwatchIndex = newSwatchIndex;
                        LXx_VCPY(rgbColor.vec, rgbSwatchColors[vSwatchIndex].vec);
                    }

                    for (unsigned x = wheelBackWidth; x < metrics.slice_width; ++x)
                    {
                        setPixel(pixel, rgbColor.vec);
                        pixel += 4;
                    }

                    result = imageSeg.SetSegment(y, wheelBackWidth, static_cast<unsigned>(metrics.slice_width), LXiIMP_RGBA32, lineBuffer);
                }
            }

            delete[] lineBuffer;
        }

        unsigned primarySrcWidth, primarySrcHeight;
        primary_marker.Size(&primarySrcWidth, &primarySrcHeight);

        unsigned secondarySrcWidth, secondarySrcHeight;
        secondary_marker.Size(&secondarySrcWidth, &secondarySrcHeight);

        CLxUser_Image readDstImage;
        readDstImage.set(image);

        unsigned markerCount = static_cast<unsigned>(markerPoints.size());
        m_log.Info(std::string(std::string("DrawSliceMarker: markerCount' ") + IntegerToString(markerCount)).c_str());
        for (unsigned markerIndex = 0; markerIndex < markerCount; ++markerIndex)
        {
            Point2D     markerPoint = markerPoints[markerIndex];
            LXtFVector2 point       = { static_cast<float>(markerPoint.vec[0]), static_cast<float>(markerPoint.vec[1]) };

            if (markerIndex == baseColorIndex)
            {
                point[0] -= static_cast<float>(primarySrcWidth) * 0.5f;
                point[1] -= static_cast<float>(primarySrcHeight) * 0.5f;
                result = imageSvc.Composite(readDstImage, primary_marker, point);
            }
            else
            {
                point[0] -= static_cast<float>(secondarySrcWidth) * 0.5f;
                point[1] -= static_cast<float>(secondarySrcHeight) * 0.5f;
                result = imageSvc.Composite(readDstImage, secondary_marker, point);
            }
        }
    }
    else
    {
        result = LXe_NOTIMPL;
    }

    return result;
}

LxResult CHSVColorModel::colm_CanSliceBeReused(unsigned xAxis, unsigned yAxis, const float* oldVec, const float* newVec)
{
    unsigned zAxis = 0;
    if (xAxis == 0)
    {
        if (yAxis == 1)
        {
            zAxis = 2;
        }
        else
        {
            zAxis = 1;
        }
    }
    else if (xAxis == 1)
    {
        zAxis = 0;
    }

    return (oldVec[zAxis] == newVec[zAxis]) ? LXe_TRUE : LXe_FALSE;
}

/*
 * Calculate imgX and imgY in [0, imgW], [0, imgH], from hsv color
 * components on the plane specified by xAxis, yAxis.
 */
LxResult CHSVColorModel::colm_ToSlicePos(unsigned xAxis, unsigned yAxis, unsigned imgW, unsigned imgH, const float* hsv, unsigned* imgX, unsigned* imgY)
{
    float x, y;

    if (xAxis == 0)
    {
        if (HueAsWheel())
        {
            float angle = _H;
            if (Wheel() == HSV_WHEEL_RYB)
            {
                /*
                 * RYB wheel.
                 */
                angle = HueRYBtoRGB(angle);
            }

            /*
             * Position red (0) at 3 o'clock.
             */
            angle = TWO_PI - angle - PI;
            if (angle < 0)
            {
                angle += TWO_PI;
            }

            if (yAxis == 1)
            {
                x = cos(angle) * _S;
                y = sin(angle) * _S;
            }
            else
            {  // yAxis == 2 (value)
                x = cos(angle) * _V;
                y = sin(angle) * _V;
            }

            x = -x * 0.5f + 0.5f;
            y = -y * 0.5f + 0.5f;
        }
        else
        {
            x = _H / static_cast<float>(TWO_PI);
            if (yAxis == 1)
            {
                y = _S;
            }
            else
            {  // yAxis == 2 (value)
                y = _V;
            }
        }
    }
    else
    {  // xAxis == 1
        x = _V;
        y = _S;
    }

    /*
     * For now, use clamping, but this should really clip to the line
     * segment formed from the center point to the nearest edge point.
     */
    x = LXxCLAMP(x, 0, 1);
    y = LXxCLAMP(y, 0, 1);

    if ((xAxis == 0) && (HueAsWheel()))
    {
        Metrics metrics;
        ResizeWheelAndRuleSwatches(imgW, imgH, metrics);

        /*
         * Scale and translate according to the aspect ratio and swatches.
         */
        float wheelDiameter = metrics.wheel_radius * 2;

        x *= wheelDiameter / metrics.slice_width;
        y *= wheelDiameter / metrics.slice_height;

        x += (metrics.wheel_back_width - wheelDiameter) * 0.5f / metrics.slice_width;
        y += (metrics.wheel_back_height - wheelDiameter) * 0.5f / metrics.slice_height;
    }

    *imgX = static_cast<unsigned>(x * imgW);
    *imgY = static_cast<unsigned>(y * imgH);

    return LXe_OK;
}

/*
 * Calculate color model components hsv using imgX and imgY in [0, 1],
 * on the plane specified by xAxis, yAxis.
 *
 * NOTE: The other axis (the one that is neither x nor y) component value
 *       should already be set by the last bar selection or the initial
 *       color load.
 */
LxResult
CHSVColorModel::colm_FromSlicePos(unsigned xAxis, unsigned yAxis, unsigned imgW, unsigned imgH, unsigned imgX, unsigned imgY, float* downVec, float* hsv)
{
    float x = static_cast<float>(imgX);
    float y = static_cast<float>(imgY);

    if (xAxis == 0)
    {
        if (HueAsWheel())
        {
            Metrics metrics;
            ResizeWheelAndRuleSwatches(imgW, imgH, metrics);

            /*
             * Check if tracking in the swatches.
             */
            if (!TrackSwatch(metrics, xAxis, yAxis, imgW, imgH, imgX, imgY, downVec, hsv))
            {
                /*
                 * Translate back to origin.
                 */
                float xt = x - metrics.wheel_centerX;
                float yt = y - metrics.wheel_centerY;
                bool  inside;
                float colorRadius = sqrtf(xt * xt + yt * yt) / metrics.wheel_radius;

                /*
                 * Convert x, y to an angle.
                 */
                float angle = 0;
                if (yt != 0)
                {
                    angle = atan2(yt, xt) + static_cast<float>(PI);
                }
                else if (xt > 0)
                {
                    angle = static_cast<float>(PI);
                }

                /*
                 * Position red (0) at 3 o'clock.
                 */
                angle = TWO_PI - angle - PI;
                if (angle < 0)
                {
                    angle += TWO_PI;
                }

                if (Wheel() == HSV_WHEEL_RYB)
                {
                    /*
                     * RYB wheel.
                     */
                    angle = HueRGBtoRYB(angle);
                }

                _H     = static_cast<float>(angle);
                inside = colorRadius <= 1.0f;
                if (inside)
                {
                    /*
                     * Vary the saturation or the value,
                     * depending on the active center axis.
                     */
                    if (yAxis == 1)
                    {
                        _S = colorRadius;
                    }
                    else
                    {
                        _V = colorRadius;
                    }
                }
                else
                {
                    if (yAxis == 1)
                    {
                        _S = 1.0f;
                    }
                    else
                    {
                        _V = 1.0f;
                    }
                }

                /*
                 * Tracking the wheel, so update base color.
                 */
                LXx_VCPY(downVec, hsv);
            }
        }
        else
        {
            _H = (x / imgW) * static_cast<float>(TWO_PI);
            if (yAxis == 1)
            {
                _S = y / imgH;
            }
            else
            {  // yAxis == 2
                _V = y / imgH;
            }
        }
    }
    else
    {  // xAxis == 1
        _V = x / imgW;
        _S = y / imgH;
    }

    return LXe_OK;
}

/*
 * Return a clean vector so the color picker can drawn the horizontal
 * strip properly.  For hue, this is 0, 1, 1, for saturation we set the
 * value to 1 but leave the rest alone, and for value we set the hue to zero.
 */
LxResult CHSVColorModel::colm_StripBaseVector(unsigned axis, int dynamic, float* hsv)
{
    if (axis == 0)
    {
        // Hue
        if (!dynamic)
        {
            _S = 1.0f;
            _V = 1.0f;
        }
    }
    else if (axis == 1)
    {
        // Saturation
        if (!dynamic)
            _V = 1.0;
    }
    else
    {
        // Value
        if (!dynamic)
            _H = 0.0;
    }

    return LXe_OK;
}

bool CHSVColorModel::HueAxisOnStrip()
{
    return QueryCommandInt(LXsCOMMAND_COLOR_MODEL_AXIS) == 0;
}

bool CHSVColorModel::HueAsWheel()
{
    return persist->hue_as_wheel_value.Bool(0, PRESET_HSV_HUE_AS_WHEEL);
}

unsigned CHSVColorModel::Wheel()
{
    return persist->wheel_value.Int(0, PRESET_HSV_WHEEL);
}

unsigned CHSVColorModel::Rule()
{
    return persist->rule_value.Int(0, PRESET_HSV_RULE);
}

float CHSVColorModel::RuleAdjust()
{
    float adjust = PresetRuleAdjust();
    switch (Rule())
    {
        case HSV_RULE_COMPLEMENTARY:
            adjust = static_cast<float>(persist->rule_adjust_value_complementary.Float(0, adjust));
            break;

        case HSV_RULE_ANALOGOUS:
            adjust = static_cast<float>(persist->rule_adjust_value_analogous.Float(0, adjust));
            break;

        case HSV_RULE_TRIADIC:
            adjust = static_cast<float>(persist->rule_adjust_value_triadic.Float(0, adjust));
            break;

        case HSV_RULE_TETRADIC:
            adjust = static_cast<float>(persist->rule_adjust_value_tetradic.Float(0, adjust));
            break;

        case HSV_RULE_COMPOUND:
            adjust = static_cast<float>(persist->rule_adjust_value_compound.Float(0, adjust));
            break;
    }

    return adjust;
}

float CHSVColorModel::PresetRuleAdjust()
{
    double presetAdjust{};
    switch (Rule())
    {
        case HSV_RULE_COMPLEMENTARY:
            presetAdjust = PRESET_HSV_RULE_ADJUST_COMPLEMENTARY;
            break;

        case HSV_RULE_ANALOGOUS:
            presetAdjust = PRESET_HSV_RULE_ADJUST_ANALOGOUS;
            break;

        case HSV_RULE_TRIADIC:
            presetAdjust = PRESET_HSV_RULE_ADJUST_TRIADIC;
            break;

        case HSV_RULE_TETRADIC:
            presetAdjust = PRESET_HSV_RULE_ADJUST_TETRADIC;
            break;

        case HSV_RULE_COMPOUND:
            presetAdjust = PRESET_HSV_RULE_ADJUST_COMPOUND;
            break;
    }

    return static_cast<float>(presetAdjust);
}

unsigned CHSVColorModel::Levels()
{
    return persist->levels_value.Int(0, PRESET_HSV_LEVELS);
}

unsigned CHSVColorModel::SwatchCount()
{
    unsigned swatchCount = 0;
    switch (Rule())
    {
        case HSV_RULE_SOLO:
            // Just the selected color.
            swatchCount = 1;
            break;

        case HSV_RULE_COMPLEMENTARY:
            // Selected color and its opposite.
            swatchCount = 2;
            break;

        case HSV_RULE_ANALOGOUS:
            // Adjacent colors.
            swatchCount = 3;
            break;

        case HSV_RULE_TRIADIC:
            // Three colors at 120 degree stops.
            swatchCount = 3;
            break;

        case HSV_RULE_TETRADIC:
            // Four colors at 45 degree stops.
            swatchCount = 4;
            break;

        case HSV_RULE_COMPOUND:
            // Five colors at 30 and 45 degree stops.
            swatchCount = 5;
            break;

        case HSV_RULE_TINTS:
        case HSV_RULE_SHADES:
            // Variations by tint or shade.
            swatchCount = Levels();
            break;
    }

    return swatchCount;
}

void CHSVColorModel::BuildSwatches(const HSVColor& baseColor, std::vector<HSVColor>& swatchColors, unsigned& baseColorIndex)
{
    swatchColors.clear();

    switch (Rule())
    {
        case HSV_RULE_SOLO:
            // Just the selected color.
            baseColorIndex = 0;
            swatchColors.push_back(baseColor);
            break;

        case HSV_RULE_COMPLEMENTARY:
            // Selected color and its opposite.
            BuildComplementarySwatches(baseColor, swatchColors, baseColorIndex);
            break;

        case HSV_RULE_ANALOGOUS:
            // Adjacent colors.
            BuildAnalogousSwatches(baseColor, swatchColors, baseColorIndex);
            break;

        case HSV_RULE_TRIADIC:
            // Three colors at 120 degree stops.
            BuildTriadicSwatches(baseColor, swatchColors, baseColorIndex);
            break;

        case HSV_RULE_TETRADIC:
            // Four colors at 45 degree stops.
            BuildTetradicSwatches(baseColor, swatchColors, baseColorIndex);
            break;

        case HSV_RULE_COMPOUND:
            // Five colors at 30 and 45 degree stops.
            BuildCompoundSwatches(baseColor, swatchColors, baseColorIndex);
            break;

        case HSV_RULE_TINTS:
            // Variations by tint.
            BuildTintsSwatches(baseColor, swatchColors, baseColorIndex);
            break;

        case HSV_RULE_SHADES:
            // Variations by shade.
            BuildShadesSwatches(baseColor, swatchColors, baseColorIndex);
            break;
    }
}

/*
 * Selected color and its opposite.
 */
void CHSVColorModel::BuildComplementarySwatches(const HSVColor& baseColor, std::vector<HSVColor>& swatchColors, unsigned& baseColorIndex)
{
    HSVColor hsvColor;

    baseColorIndex = static_cast<unsigned>(swatchColors.size());
    swatchColors.push_back(baseColor);

    float angle = baseColor.vec[0];
    if (Wheel() == HSV_WHEEL_RYB)
    {
        angle = HueRYBtoRGB(angle);
    }

    angle = fmod(angle + RuleAdjust(), TWO_PI);
    if (Wheel() == HSV_WHEEL_RYB)
    {
        angle = HueRGBtoRYB(angle);
    }

    hsvColor.vec[0] = angle;
    hsvColor.vec[1] = baseColor.vec[1];
    hsvColor.vec[2] = baseColor.vec[2];

    swatchColors.push_back(hsvColor);
}

/*
 * Adjacent colors.
 */
void CHSVColorModel::BuildAnalogousSwatches(const HSVColor& baseColor, std::vector<HSVColor>& swatchColors, unsigned& baseColorIndex)
{
    HSVColor hsvColor;

    float baseAngle = baseColor.vec[0];
    if (Wheel() == HSV_WHEEL_RYB)
    {
        baseAngle = HueRYBtoRGB(baseAngle);
    }

    // -45 degrees
    float angle = fmod(baseAngle - RuleAdjust(), TWO_PI);
    if (angle < 0)
    {
        angle += TWO_PI;
    }
    if (Wheel() == HSV_WHEEL_RYB)
    {
        angle = HueRGBtoRYB(angle);
    }
    hsvColor.vec[0] = angle;
    hsvColor.vec[1] = baseColor.vec[1];
    hsvColor.vec[2] = baseColor.vec[2];
    swatchColors.push_back(hsvColor);

    // Selected color.
    baseColorIndex = static_cast<unsigned>(swatchColors.size());
    swatchColors.push_back(baseColor);

    // +45 degrees
    angle = fmod(baseAngle + RuleAdjust(), TWO_PI);
    if (Wheel() == HSV_WHEEL_RYB)
    {
        angle = HueRGBtoRYB(angle);
    }
    hsvColor.vec[0] = angle;
    swatchColors.push_back(hsvColor);
}

/*
 * Three colors at 120 degree stops.
 */
void CHSVColorModel::BuildTriadicSwatches(const HSVColor& baseColor, std::vector<HSVColor>& swatchColors, unsigned& baseColorIndex)
{
    HSVColor hsvColor;

    float baseAngle = baseColor.vec[0];
    if (Wheel() == HSV_WHEEL_RYB)
    {
        baseAngle = HueRYBtoRGB(baseAngle);
    }

    // -120 degrees
    float angle = fmod(baseAngle - RuleAdjust(), TWO_PI);
    if (angle < 0)
    {
        angle += TWO_PI;
    }
    if (Wheel() == HSV_WHEEL_RYB)
    {
        angle = HueRGBtoRYB(angle);
    }
    hsvColor.vec[0] = angle;
    hsvColor.vec[1] = baseColor.vec[1];
    hsvColor.vec[2] = baseColor.vec[2];
    swatchColors.push_back(hsvColor);

    // Selected color.
    baseColorIndex = static_cast<unsigned>(swatchColors.size());
    swatchColors.push_back(baseColor);

    // +120 degrees
    angle = fmod(baseAngle + RuleAdjust(), TWO_PI);
    if (Wheel() == HSV_WHEEL_RYB)
    {
        angle = HueRGBtoRYB(angle);
    }
    hsvColor.vec[0] = angle;
    swatchColors.push_back(hsvColor);
}

/*
 * Four colors at 45 degree stops.
 */
void CHSVColorModel::BuildTetradicSwatches(const HSVColor& baseColor, std::vector<HSVColor>& swatchColors, unsigned& baseColorIndex)
{
    HSVColor hsvColor;

    float baseAngle = baseColor.vec[0];
    if (Wheel() == HSV_WHEEL_RYB)
    {
        baseAngle = HueRYBtoRGB(baseAngle);
    }

    // -45 degrees
    float angle = fmod(baseAngle - RuleAdjust(), TWO_PI);
    if (angle < 0)
    {
        angle += TWO_PI;
    }
    if (Wheel() == HSV_WHEEL_RYB)
    {
        angle = HueRGBtoRYB(angle);
    }
    hsvColor.vec[0] = angle;
    hsvColor.vec[1] = baseColor.vec[1];
    hsvColor.vec[2] = baseColor.vec[2];
    swatchColors.push_back(hsvColor);

    // Selected color.
    baseColorIndex = static_cast<unsigned>(swatchColors.size());
    swatchColors.push_back(baseColor);

    // +180 degrees
    angle = fmod(baseAngle + PI, TWO_PI);
    if (Wheel() == HSV_WHEEL_RYB)
    {
        angle = HueRGBtoRYB(angle);
    }
    hsvColor.vec[0] = angle;
    swatchColors.push_back(hsvColor);

    // +135 degrees
    angle = fmod(baseAngle + PI - RuleAdjust(), TWO_PI);
    if (angle < 0)
    {
        angle += TWO_PI;
    }
    if (Wheel() == HSV_WHEEL_RYB)
    {
        angle = HueRGBtoRYB(angle);
    }
    hsvColor.vec[0] = angle;
    swatchColors.push_back(hsvColor);
}

/*
 * Five colors at 30 and 45 degree stops.
 */
void CHSVColorModel::BuildCompoundSwatches(const HSVColor& baseColor, std::vector<HSVColor>& swatchColors, unsigned& baseColorIndex)
{
    float    adjust = RuleAdjust();
    HSVColor hsvColor;

    float baseAngle = baseColor.vec[0];
    if (Wheel() == HSV_WHEEL_RYB)
    {
        baseAngle = HueRYBtoRGB(baseAngle);
    }

    // - rule - half rule
    float angle = fmod(baseAngle - adjust - adjust * 0.5f, TWO_PI);
    if (angle < 0)
    {
        angle += TWO_PI;
    }
    if (Wheel() == HSV_WHEEL_RYB)
    {
        angle = HueRGBtoRYB(angle);
    }
    hsvColor.vec[0] = angle;
    hsvColor.vec[1] = baseColor.vec[1];
    hsvColor.vec[2] = baseColor.vec[2];
    swatchColors.push_back(hsvColor);

    // -rule
    angle = fmod(baseAngle - adjust, TWO_PI);
    if (angle < 0)
    {
        angle += TWO_PI;
    }
    if (Wheel() == HSV_WHEEL_RYB)
    {
        angle = HueRGBtoRYB(angle);
    }
    hsvColor.vec[0] = angle;
    swatchColors.push_back(hsvColor);

    // Selected color.
    baseColorIndex = static_cast<unsigned>(swatchColors.size());
    swatchColors.push_back(baseColor);

    // +rule
    angle = fmod(baseAngle + adjust, TWO_PI);
    if (Wheel() == HSV_WHEEL_RYB)
    {
        angle = HueRGBtoRYB(angle);
    }
    hsvColor.vec[0] = angle;
    swatchColors.push_back(hsvColor);

    // +rule + half rule
    angle = fmod(baseAngle + adjust + adjust * 0.5f, TWO_PI);
    if (Wheel() == HSV_WHEEL_RYB)
    {
        angle = HueRGBtoRYB(angle);
    }
    hsvColor.vec[0] = angle;
    swatchColors.push_back(hsvColor);
}

/*
 * Variations by tint.
 */
void CHSVColorModel::BuildTintsSwatches(const HSVColor& baseColor, std::vector<HSVColor>& swatchColors, unsigned& baseColorIndex)
{
    HSVColor hsvColor;

    baseColorIndex = 0;

    // Hue and value are constant.
    hsvColor.vec[0] = baseColor.vec[0];
    hsvColor.vec[2] = baseColor.vec[2];

    unsigned levels = Levels();
    for (unsigned levelIndex = 0; levelIndex < levels; ++levelIndex)
    {
        hsvColor.vec[1] = static_cast<float>(levelIndex) / (levels - 1);
        swatchColors.push_back(hsvColor);
    }
}

/*
 * Variations by shade.
 */
void CHSVColorModel::BuildShadesSwatches(const HSVColor& baseColor, std::vector<HSVColor>& swatchColors, unsigned& baseColorIndex)
{
    HSVColor hsvColor;

    baseColorIndex = 0;

    // Hue and saturation are constant.
    hsvColor.vec[0] = baseColor.vec[0];
    hsvColor.vec[1] = baseColor.vec[1];

    unsigned levels = Levels();

    for (unsigned levelIndex = 0; levelIndex < levels; ++levelIndex)
    {
        hsvColor.vec[2] = static_cast<float>(levelIndex) / (levels - 1);
        swatchColors.push_back(hsvColor);
    }
}

/*
 * ----------------------------------------------------------------
 * Server initialization.
 */

void initialize()
{
    // Color Model server.
    LXx_ADD_SERVER(ColorModel, CHSVColorModel, SERVER_HSV_COLOR_MODEL);

    CLxGenericPolymorph* srv;

    // Hue As Wheel command.
    srv = new CLxPolymorph<CHueAsWheelHSVColorModelCommand>;
    srv->AddInterface(new CLxIfc_Command<CHueAsWheelHSVColorModelCommand>);
    srv->AddInterface(new CLxIfc_Attributes<CHueAsWheelHSVColorModelCommand>);
    thisModule.AddServer("color.hsvHueAsWheel", srv);

    // Wheel command.
    srv = new CLxPolymorph<CWheelHSVColorModelCommand>;
    srv->AddInterface(new CLxIfc_Command<CWheelHSVColorModelCommand>);
    srv->AddInterface(new CLxIfc_Attributes<CWheelHSVColorModelCommand>);
    srv->AddInterface(new CLxIfc_AttributesUI<CWheelHSVColorModelCommand>);
    thisModule.AddServer("color.hsvWheel", srv);

    // Rule command.
    srv = new CLxPolymorph<CRuleHSVColorModelCommand>;
    srv->AddInterface(new CLxIfc_Command<CRuleHSVColorModelCommand>);
    srv->AddInterface(new CLxIfc_Attributes<CRuleHSVColorModelCommand>);
    srv->AddInterface(new CLxIfc_AttributesUI<CRuleHSVColorModelCommand>);
    thisModule.AddServer("color.hsvRule", srv);

    // Rule Adjust command.
    srv = new CLxPolymorph<CRuleAdjustHSVColorModelCommand>;
    srv->AddInterface(new CLxIfc_Command<CRuleAdjustHSVColorModelCommand>);
    srv->AddInterface(new CLxIfc_Attributes<CRuleAdjustHSVColorModelCommand>);
    srv->AddInterface(new CLxIfc_AttributesUI<CRuleAdjustHSVColorModelCommand>);
    thisModule.AddServer("color.hsvRuleAdjust", srv);

    // Levels command.
    srv = new CLxPolymorph<CLevelsHSVColorModelCommand>;
    srv->AddInterface(new CLxIfc_Command<CLevelsHSVColorModelCommand>);
    srv->AddInterface(new CLxIfc_Attributes<CLevelsHSVColorModelCommand>);
    srv->AddInterface(new CLxIfc_AttributesUI<CLevelsHSVColorModelCommand>);
    thisModule.AddServer("color.hsvLevels", srv);

    // Save as Presets command.
    srv = new CLxPolymorph<CSaveAsPresetsHSVColorModelCommand>;
    srv->AddInterface(new CLxIfc_Command<CSaveAsPresetsHSVColorModelCommand>);
    srv->AddInterface(new CLxIfc_Attributes<CSaveAsPresetsHSVColorModelCommand>);
    srv->AddInterface(new CLxIfc_AttributesUI<CSaveAsPresetsHSVColorModelCommand>);
    thisModule.AddServer("color.hsvSaveAsPresets", srv);

    // Notifier.
    srv = new CLxPolymorph<CHSVColorModelNotifier>;
    srv->AddInterface(new CLxIfc_Notifier<CHSVColorModelNotifier>);
    thisModule.AddServer(HSV_COLOR_MODEL_NOTIFIER, srv);
}

void cleanup()
{
    if (persist)
    {
        delete persist;
    }
}
