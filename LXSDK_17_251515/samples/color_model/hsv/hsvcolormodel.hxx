/*
 * Plug-in HSV color model.
 *
 * Copyright 0000
 *
 * A plug-in color model that enables picking colors using
 * hue, saturation, and value color components.
 */
#pragma once

#include <lx_color.hpp>
#include <lx_image.hpp>
#include <lx_persist.hpp>
#include <lx_thread.hpp>
#include <lx_value.hpp>
#include <lx_wrap.hpp>
#include <lxlog.h>
#include <lxu_command.hpp>
#include <lxu_log.hpp>

#include <vector>

extern const char* SERVER_HSV_COLOR_MODEL;

class CHSVColorModelLog : public CLxLuxologyLogMessage
{
public:
    CHSVColorModelLog() : CLxLuxologyLogMessage(SERVER_HSV_COLOR_MODEL)
    {
    }

    const char* GetFormat() override
    {
        return "HSV Color Model";
    }
};

/*
 * ---------------------------------------------------------------------------
 * Commands.
 */

class CHueAsWheelHSVColorModelCommand : public CLxBasicCommand
{
public:
    CHueAsWheelHSVColorModelCommand();
    virtual ~CHueAsWheelHSVColorModelCommand()
    {
    }

    int  basic_CmdFlags() override;
    bool basic_Notifier(int index, std::string& name, std::string& args) override;
    bool basic_Enable(CLxUser_Message& msg) override;

    void     cmd_Execute(unsigned int flags) override;
    LxResult cmd_Query(unsigned int index, ILxUnknownID vaQuery) override;
};

class CWheelHSVColorModelCommand : public CLxBasicCommand
{
public:
    CWheelHSVColorModelCommand();
    virtual ~CWheelHSVColorModelCommand()
    {
    }

    int  basic_CmdFlags() override;
    bool basic_Notifier(int index, std::string& name, std::string& args) override;
    bool basic_Enable(CLxUser_Message& msg) override;

    void     cmd_Execute(unsigned int flags) override;
    LxResult cmd_Query(unsigned int index, ILxUnknownID vaQuery) override;

    using CLxDynamicAttributes::atrui_UIHints;  // to distinguish from the overloaded version in CLxImpl_AttributesUI

    void atrui_UIHints2(unsigned int index, CLxUser_UIHints& hints) override;
};

class CRuleHSVColorModelCommand : public CLxBasicCommand
{
public:
    CRuleHSVColorModelCommand();
    virtual ~CRuleHSVColorModelCommand()
    {
    }

    int  basic_CmdFlags() override;
    bool basic_Notifier(int index, std::string& name, std::string& args) override;
    bool basic_Enable(CLxUser_Message& msg) override;

    void     cmd_Execute(unsigned int flags) override;
    LxResult cmd_Query(unsigned int index, ILxUnknownID vaQuery) override;

    using CLxDynamicAttributes::atrui_UIHints;  // to distinguish from the overloaded version in CLxImpl_AttributesUI

    void atrui_UIHints2(unsigned int index, CLxUser_UIHints& hints) override;
};

class CRuleAdjustHSVColorModelCommand : public CLxBasicCommand
{
public:
    CRuleAdjustHSVColorModelCommand();
    virtual ~CRuleAdjustHSVColorModelCommand()
    {
    }

    int  basic_CmdFlags() override;
    bool basic_Notifier(int index, std::string& name, std::string& args) override;
    bool basic_Enable(CLxUser_Message& msg) override;

    void     cmd_Execute(unsigned int flags) override;
    LxResult cmd_Query(unsigned int index, ILxUnknownID vaQuery) override;

    using CLxDynamicAttributes::atrui_UIHints;  // to distinguish from the overloaded version in CLxImpl_AttributesUI

    void atrui_UIHints2(unsigned int index, CLxUser_UIHints& hints) override;
};

class CLevelsHSVColorModelCommand : public CLxBasicCommand
{
public:
    CLevelsHSVColorModelCommand();
    virtual ~CLevelsHSVColorModelCommand()
    {
    }

    int  basic_CmdFlags() override;
    bool basic_Notifier(int index, std::string& name, std::string& args) override;
    bool basic_Enable(CLxUser_Message& msg) override;

    void     cmd_Execute(unsigned int flags) override;
    LxResult cmd_Query(unsigned int index, ILxUnknownID vaQuery) override;

    using CLxDynamicAttributes::atrui_UIHints;  // to distinguish from the overloaded version in CLxImpl_AttributesUI

    void atrui_UIHints2(unsigned int index, CLxUser_UIHints& hints) override;
};

class CSaveAsPresetsHSVColorModelCommand : public CLxBasicCommand
{
public:
    CSaveAsPresetsHSVColorModelCommand();
    virtual ~CSaveAsPresetsHSVColorModelCommand()
    {
    }

    int  basic_CmdFlags() override;
    bool basic_Notifier(int index, std::string& name, std::string& args) override;
    bool basic_Enable(CLxUser_Message& msg) override;

    void     cmd_Execute(unsigned int flags) override;
    LxResult cmd_Query(unsigned int index, ILxUnknownID vaQuery) override;

    using CLxDynamicAttributes::atrui_UIHints;  // to distinguish from the overloaded version in CLxImpl_AttributesUI

    void atrui_UIHints2(unsigned int index, CLxUser_UIHints& hints) override;
};

/*
 * Notifier responds to changes executed by commands.
 */
class CHSVColorModelNotifier : public CLxCommandNotifier
{
public:
    CHSVColorModelNotifier();
    virtual ~CHSVColorModelNotifier()
    {
    }

    void         cn_Parse(std::string& args) override;
    unsigned int cn_Flags(int code) override;
};

/*
 * ---------------------------------------------------------------------------
 * CHSVColorModel.
 */

/*
 * Wheel types
 */
enum
{
    HSV_WHEEL_RGB,  // Red, green, and blue is triadic.
    HSV_WHEEL_RYB   // Red, yellow, and blue is triadic.
};

/*
 * Rules for building swatches.
 */
enum
{
    HSV_RULE_SOLO,           // Just the selected color.
    HSV_RULE_COMPLEMENTARY,  // Selected color and its opposite.
    HSV_RULE_ANALOGOUS,      // Adjacent colors.
    HSV_RULE_TRIADIC,        // Three colors at 120 degree stops.
    HSV_RULE_TETRADIC,       // Four colors at 45 degree stops.
    HSV_RULE_COMPOUND,       // Five colors at 30 and 45 degree stops.
    HSV_RULE_TINTS,          // Tinted variations.
    HSV_RULE_SHADES          // Shaded variations.
};

class HSVColor
{
public:
    LXtFVector vec;
};

class CHSVColorModelThreadRangeWorker : public CLxImpl_ThreadRangeWorker
{
public:
    CHSVColorModelThreadRangeWorker();
    ~CHSVColorModelThreadRangeWorker();

    LxResult rngw_Execute(int index, void* sharedData) override;
};

class CHSVColorModel : public CLxImpl_ColorModel
{
    CHSVColorModelLog m_log;
    ILxUnknownID      rangeWorker;

public:
    static LXtTagInfoDesc                         descInfo[];
    CLxPolymorph<CHSVColorModelThreadRangeWorker> range_factory;

    CHSVColorModel();
    virtual ~CHSVColorModel();

    int colm_NumComponents(void) override;

    LxResult colm_ComponentType(unsigned componentIndex, const char** type) override;

    LxResult colm_ComponentRange(unsigned componentIndex, float* minValue, float* maxValue) override;

    LxResult colm_ToRGB(const float* hsv, float* rgb) override;

    LxResult colm_FromRGB(const float* rgb, float* hsv) override;

    LxResult colm_DrawSlice(ILxUnknownID image, unsigned xAxis, unsigned yAxis, const float* vec) override;

    LxResult colm_DrawSliceMarker(ILxUnknownID image, unsigned xAxis, unsigned yAxis, const float* downVec, const float* hsv) override;

    LxResult colm_CanSliceBeReused(unsigned xAxis, unsigned yAxis, const float* oldVec, const float* newVec) override;

    LxResult colm_ToSlicePos(unsigned xAxis, unsigned yAxis, unsigned imgW, unsigned imgH, const float* hsv, unsigned* imgX, unsigned* imgY) override;

    LxResult
    colm_FromSlicePos(unsigned xAxis, unsigned yAxis, unsigned imgW, unsigned imgH, unsigned imgX, unsigned imgY, float* downVec, float* hsv) override;

    LxResult colm_StripBaseVector(unsigned axis, int dynamic, float* hsv) override;

    static bool     HueAxisOnStrip();
    static bool     HueAsWheel();
    static unsigned Wheel();

    static unsigned Rule();
    static float    RuleAdjust();
    static float    PresetRuleAdjust();

    static unsigned Levels();

    static unsigned SwatchCount();

    static void BuildSwatches(const HSVColor& baseColor, std::vector<HSVColor>& swatchColors, unsigned& baseColorIndex);

private:
    static void BuildComplementarySwatches(const HSVColor& baseColor, std::vector<HSVColor>& swatchColors, unsigned& baseColorIndex);

    static void BuildAnalogousSwatches(const HSVColor& baseColor, std::vector<HSVColor>& swatchColors, unsigned& baseColorIndex);

    static void BuildTriadicSwatches(const HSVColor& baseColor, std::vector<HSVColor>& swatchColors, unsigned& baseColorIndex);

    static void BuildTetradicSwatches(const HSVColor& baseColor, std::vector<HSVColor>& swatchColors, unsigned& baseColorIndex);

    static void BuildCompoundSwatches(const HSVColor& baseColor, std::vector<HSVColor>& swatchColors, unsigned& baseColorIndex);

    static void BuildTintsSwatches(const HSVColor& baseColor, std::vector<HSVColor>& swatchColors, unsigned& baseColorIndex);

    static void BuildShadesSwatches(const HSVColor& baseColor, std::vector<HSVColor>& swatchColors, unsigned& baseColorIndex);

    CLxUser_Image primary_marker;
    CLxUser_Image secondary_marker;
};
