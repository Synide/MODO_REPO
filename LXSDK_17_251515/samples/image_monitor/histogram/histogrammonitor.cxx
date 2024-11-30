/*
 * Plug-in Histogram monitor.
 *
 * Copyright 0000
 *
 * A plug-in histogram monitor that displays the relative number
 * of pixels that occur within each color or luminosity level.
 */

#include "histogrammonitor.hxx"

#include <lx_file.hpp>
#include <lx_imagemon.hpp>
#include <lx_plugin.hpp>
#include <lx_visitor.hpp>
#include <lxu_message.hpp>
#include <lxu_queries.hpp>
#include <lxvmath.h>

#include <cfloat>
#include <cmath>
#include <sstream>
#include <string>

const char* SERVER_HISTOGRAM_MONITOR = "histogram";          // Internal names are lower case
const char* CONFIG_HISTOGRAM_MONITOR = "HistogramMonitors";  // But config entries are mixed case for no particular reason

const int PRESET_DISPLAY_MODE      = DISPLAY_HISTOGRAM;
const int PRESET_HISTOGRAM_CHANNEL = HISTOGRAM_COLORS;
const int PRESET_PARADE_CHANNEL    = PARADE_RED;

typedef struct st_HistogramOptions
{
    int    displayMode;
    int    histogramChannelMode;
    int    paradeChannelMode;
    double rangeMin;
    double rangeMax;
} HistogramOptions;

/*
 * ---------------------------------------------------------------------------
 * CHistogramMonitorPersist and CHistogramMonitorVisitor
 */

class CHistogramMonitorPersist
{
public:
    CLxUser_PersistentEntry imageSource;  // Hash; key is the image source string

    CLxUser_PersistentEntry displayMode;           // Atom; Which display mode (histogram or parade)
    CLxUser_PersistentEntry histogramChannelMode;  // Atom; Which histogram channels we're looking at (int)
    CLxUser_PersistentEntry paradeChannelMode;     // Atom; Which parade channels we're looking at (int)
    CLxUser_PersistentEntry rangeMin;              // Atom; Min (double)
    CLxUser_PersistentEntry rangeMax;              // Atom; Max (double)

    CLxUser_Attributes displayMode_value;
    CLxUser_Attributes histogramChannelMode_value;
    CLxUser_Attributes paradeChannelMode_value;
    CLxUser_Attributes rangeMin_value;
    CLxUser_Attributes rangeMax_value;

    LxResult Restore(const std::string& imageSource, HistogramOptions& options);

    LxResult Store(const std::string& imageSource, const HistogramOptions& options);
};

LxResult CHistogramMonitorPersist::Restore(const std::string& imageSourceString, HistogramOptions& options)
{
    options.displayMode          = PRESET_DISPLAY_MODE;
    options.histogramChannelMode = PRESET_HISTOGRAM_CHANNEL;
    options.paradeChannelMode    = PRESET_PARADE_CHANNEL;
    options.rangeMin             = 0.0;
    options.rangeMax             = 1.0;

    LxResult rc = imageSource.Lookup(imageSourceString);
    if (LXx_FAIL(rc))
        return rc;

    options.displayMode          = displayMode_value.Int(0, options.displayMode);
    options.histogramChannelMode = histogramChannelMode_value.Int(0, options.histogramChannelMode);
    options.paradeChannelMode    = paradeChannelMode_value.Int(0, options.paradeChannelMode);
    options.rangeMin             = rangeMin_value.Float(0, options.rangeMin);
    options.rangeMax             = rangeMax_value.Float(0, options.rangeMax);

    if (options.rangeMin > options.rangeMax)
        options.rangeMin = options.rangeMax;

    return LXe_OK;
}

LxResult CHistogramMonitorPersist::Store(const std::string& imageSourceString, const HistogramOptions& options)
{
    imageSource.Insert(imageSourceString);

    displayMode.Append();
    displayMode_value.Set(0, options.displayMode);

    histogramChannelMode.Append();
    histogramChannelMode_value.Set(0, options.histogramChannelMode);

    paradeChannelMode.Append();
    paradeChannelMode_value.Set(0, options.paradeChannelMode);

    rangeMin.Append();
    rangeMin_value.Set(0, options.rangeMin);

    rangeMax.Append();
    rangeMax_value.Set(0, options.rangeMax);

    return LXe_OK;
}

static CHistogramMonitorPersist* persist = nullptr;

class CHistogramMonitorPersistVisitor : public CLxImpl_AbstractVisitor
{
public:
    virtual ~CHistogramMonitorPersistVisitor()
    {
    }
    LxResult Evaluate() override;
};

static void InitializePersistence()
{
    if (persist == nullptr)
    {
        /*
         * Set up the persistent values.
         */
        persist = new CHistogramMonitorPersist();

        CLxUser_PersistenceService      srv;
        CHistogramMonitorPersistVisitor vis;
        srv.ConfigureVis(CONFIG_HISTOGRAM_MONITOR, &vis);
    }
}

// Config entry names are usually mixed case for no particular reason.
static const char* HASH_TAG_IMAGE_SOURCE = "Histogram";

static const char* ATOM_TAG_DISPLAY_MODE           = "DisplayMode";
static const char* ATOM_TAG_HISTOGRAM_CHANNEL_MODE = "HistogramChannelMode";
static const char* ATOM_TAG_PARADE_CHANNEL_MODE    = "ParadeChannelMode";
static const char* ATOM_TAG_RANGE_MIN              = "RangeMin";
static const char* ATOM_TAG_RANGE_MAX              = "RangeMax";

static const std::string imageSourceAttrName = "source";
static const std::string defaultImageSource  = "(default)";

LxResult CHistogramMonitorPersistVisitor::Evaluate()
{
    CLxUser_PersistenceService srv;

    InitializePersistence();

    // Image Source, which in turn contains the per-source atoms
    srv.Start(HASH_TAG_IMAGE_SOURCE, LXi_PERSIST_HASH);

    // Display Mode
    srv.Start(ATOM_TAG_DISPLAY_MODE, LXi_PERSIST_ATOM);
    srv.AddValue(LXsTYPE_INTEGER);
    srv.EndDef(persist->displayMode);
    persist->displayMode_value.set(persist->displayMode);

    // Histogram Channel Mode
    srv.Start(ATOM_TAG_HISTOGRAM_CHANNEL_MODE, LXi_PERSIST_ATOM);
    srv.AddValue(LXsTYPE_INTEGER);
    srv.EndDef(persist->histogramChannelMode);
    persist->histogramChannelMode_value.set(persist->histogramChannelMode);

    // Parade Channel Mode
    srv.Start(ATOM_TAG_PARADE_CHANNEL_MODE, LXi_PERSIST_ATOM);
    srv.AddValue(LXsTYPE_INTEGER);
    srv.EndDef(persist->paradeChannelMode);
    persist->paradeChannelMode_value.set(persist->paradeChannelMode);

    // Range Minimum
    srv.Start(ATOM_TAG_RANGE_MIN, LXi_PERSIST_ATOM);
    srv.AddValue(LXsTYPE_FLOAT);
    srv.EndDef(persist->rangeMin);
    persist->rangeMin_value.set(persist->rangeMin);

    // Range Maximum
    srv.Start(ATOM_TAG_RANGE_MAX, LXi_PERSIST_ATOM);
    srv.AddValue(LXsTYPE_FLOAT);
    srv.EndDef(persist->rangeMax);
    persist->rangeMax_value.set(persist->rangeMax);

    srv.EndDef(persist->imageSource);

    return LXe_OK;
}

/*
 * ---------------------------------------------------------------------------
 * CHistogramMonitorNotifier.
 */

static const char* HISTOGRAM_MONITOR_NOTIFIER = "histogram.monitor.notifier";

CHistogramMonitorNotifier::CHistogramMonitorNotifier() : CLxCommandNotifier(HISTOGRAM_MONITOR_NOTIFIER)
{
}

void CHistogramMonitorNotifier::cn_Parse(std::string& /*args*/)
{
}

unsigned int CHistogramMonitorNotifier::cn_Flags(int /*code*/)
{
    return LXfCMDNOTIFY_DISABLE | LXfCMDNOTIFY_VALUE;
}

static bool CommandEnabled(const std::string& commandName, const std::string& imageSource)
{
    bool enabled = false;

    // Ask the command if it's enabled.
    CLxUser_CommandService cmdSvc;
    CLxLoc_Command         command;
    if (cmdSvc.NewCommand(command, commandName.c_str()))
    {
        CLxUser_Attributes arg;
        arg.set(command);

        int c0ArgIndex = arg.FindIndex("source");
        if (arg.Set(c0ArgIndex, imageSource.c_str()))
        {
            CLxUser_MessageService msgService;
            CLxUser_Message        msg;
            msgService.NewMessage(msg);
            enabled = LXx_OK(command.Enable(msg));
        }
    }

    return enabled;
}

/*
 * ---------------------------------------------------------------------------
 * CDisplayModeHistogramMonitorCommand
 */

enum
{
    DISPLAY_MODE_IMAGE_SOURCE,
    DISPLAY_MODE_VALUE
};

static LXtTextValueHint hint_displayMode[] = { { DISPLAY_HISTOGRAM, "histogram" }, { DISPLAY_RGBPARADE, "parade" }, { 0, nullptr } };

static const std::string displayModeName = "displayMode";

CDisplayModeHistogramMonitorCommand::CDisplayModeHistogramMonitorCommand()
{
    dyna_Add(imageSourceAttrName, std::string(LXsTYPE_STRING));  // Image Source
    basic_SetFlags(DISPLAY_MODE_IMAGE_SOURCE, LXfCMDARG_OPTIONAL);

    dyna_Add(displayModeName, LXsTYPE_INTEGER);
    dyna_SetHint(DISPLAY_MODE_VALUE, hint_displayMode);
    basic_SetFlags(DISPLAY_MODE_VALUE, LXfCMDARG_QUERY);
}

int CDisplayModeHistogramMonitorCommand::basic_CmdFlags()
{
    return LXfCMD_UI;
}

bool CDisplayModeHistogramMonitorCommand::basic_Notifier(int index, std::string& name, std::string& args)
{
    bool result;
    if (index == 0)
    {
        name   = HISTOGRAM_MONITOR_NOTIFIER;
        args   = std::string(displayModeName) + std::string("+v");
        result = true;
    }
    else
    {
        result = false;
    }

    return result;
}

bool CDisplayModeHistogramMonitorCommand::basic_Enable(CLxUser_Message& /*msg*/)
{
    bool        enabled     = false;
    std::string imageSource = defaultImageSource;

    InitializePersistence();

    /* Get the image source string */
    if (dyna_IsSet(DISPLAY_MODE_IMAGE_SOURCE))
    {
        attr_GetString(DISPLAY_MODE_IMAGE_SOURCE, imageSource);
    }

    // For now, enabling is linked to a particular image processing
    // command, pending some API to determine if a slot is selected.
    if (CommandEnabled(std::string("imageProc.outputBlackLevel"), imageSource))
    {
        enabled = true;
    }

    return enabled;
}

void CDisplayModeHistogramMonitorCommand::cmd_Execute(unsigned int /*flags*/)
{
    HistogramOptions options;
    std::string      imageSource = defaultImageSource;

    InitializePersistence();

    /* Get the image source string */
    if (dyna_IsSet(DISPLAY_MODE_IMAGE_SOURCE))
        attr_GetString(DISPLAY_MODE_IMAGE_SOURCE, imageSource);

    /* Grab the old values */
    persist->Restore(imageSource, options);

    /* Get the new value from the argument */
    int displayMode = 0;
    if (dyna_IsSet(DISPLAY_MODE_VALUE))
    {
        attr_GetInt(DISPLAY_MODE_VALUE, &displayMode);
        if ((displayMode < DISPLAY_HISTOGRAM) || (displayMode > DISPLAY_RGBPARADE))
        {
            /* Out of bounds */
            basic_Message().SetCode(LXe_OUTOFBOUNDS);
            return;
        }
    }

    /* Write the values back to the config */
    options.displayMode = displayMode;
    persist->Store(imageSource, options);

    CLxCommandNotifier::Notify(HISTOGRAM_MONITOR_NOTIFIER, 0);

    /* Call the ImageMonitorService function to redraw the monitor */
    CLxUser_ImageMonitorService imSvc;
    imSvc.RefreshViews(imageSource, false);
}

LxResult CDisplayModeHistogramMonitorCommand::cmd_Query(unsigned int /*index*/, ILxUnknownID vaQuery)
{
    HistogramOptions options;
    std::string      imageSource = defaultImageSource;

    InitializePersistence();

    /* Get the image source string */
    if (dyna_IsSet(DISPLAY_MODE_IMAGE_SOURCE))
        attr_GetString(DISPLAY_MODE_IMAGE_SOURCE, imageSource);

    /* Grab the values */
    persist->Restore(imageSource, options);

    /* Add the appropriate value to the query */
    CLxUser_ValueArray vals(vaQuery);
    return vals.Add(options.displayMode) ? LXe_OK : LXe_NOTFOUND;
}

void CDisplayModeHistogramMonitorCommand::atrui_UIHints2(unsigned int /*index*/, CLxUser_UIHints& /*hints*/)
{
}

/*
 * ---------------------------------------------------------------------------
 * CHistogramChannelModeHistogramMonitorCommand
 */

enum
{
    HISTOGRAM_CHANNEL_MODE_IMAGE_SOURCE,
    HISTOGRAM_CHANNEL_MODE_VALUE
};

static LXtTextValueHint hint_histogramChannel[] = { { HISTOGRAM_COLORS, "colors" }, { HISTOGRAM_LUMINOSITY, "luminosity" },
                                                    { HISTOGRAM_RGB, "rgb" },       { HISTOGRAM_RED, "red" },
                                                    { HISTOGRAM_GREEN, "green" },   { HISTOGRAM_BLUE, "blue" },
                                                    { HISTOGRAM_COLORS, nullptr } };

static const std::string histogramChannelModeName = "histogramChannelMode";

CHistogramChannelModeHistogramMonitorCommand::CHistogramChannelModeHistogramMonitorCommand()
{
    dyna_Add(imageSourceAttrName, std::string(LXsTYPE_STRING));  // Image Source
    basic_SetFlags(HISTOGRAM_CHANNEL_MODE_IMAGE_SOURCE, LXfCMDARG_OPTIONAL);

    dyna_Add(histogramChannelModeName, LXsTYPE_INTEGER);
    dyna_SetHint(HISTOGRAM_CHANNEL_MODE_VALUE, hint_histogramChannel);
    basic_SetFlags(HISTOGRAM_CHANNEL_MODE_VALUE, LXfCMDARG_QUERY);
}

int CHistogramChannelModeHistogramMonitorCommand::basic_CmdFlags()
{
    return LXfCMD_UI;
}

bool CHistogramChannelModeHistogramMonitorCommand::basic_Notifier(int index, std::string& name, std::string& args)
{
    bool result;
    if (index == 0)
    {
        name   = HISTOGRAM_MONITOR_NOTIFIER;
        args   = std::string(histogramChannelModeName) + std::string("+v");
        result = true;
    }
    else
    {
        result = false;
    }

    return result;
}

bool CHistogramChannelModeHistogramMonitorCommand::basic_Enable(CLxUser_Message& /*msg*/)
{
    bool enabled = false;

    std::string imageSource = defaultImageSource;

    InitializePersistence();

    /* Get the image source string */
    if (dyna_IsSet(HISTOGRAM_CHANNEL_MODE_IMAGE_SOURCE))
    {
        attr_GetString(HISTOGRAM_CHANNEL_MODE_IMAGE_SOURCE, imageSource);
    }

    // For now, enabling is linked to a particular image processing
    // command, pending some API to determine if a slot is selected.
    if (CommandEnabled(std::string("imageProc.outputBlackLevel"), imageSource))
    {
        HistogramOptions options;

        /* Grab the old values */
        persist->Restore(imageSource, options);

        unsigned displayMode = options.displayMode;

        enabled = (displayMode == DISPLAY_HISTOGRAM);
    }

    return enabled;
}

void CHistogramChannelModeHistogramMonitorCommand::cmd_Execute(unsigned int /*flags*/)
{
    HistogramOptions options;
    std::string      imageSource = defaultImageSource;

    InitializePersistence();

    /* Get the image source string */
    if (dyna_IsSet(HISTOGRAM_CHANNEL_MODE_IMAGE_SOURCE))
        attr_GetString(HISTOGRAM_CHANNEL_MODE_IMAGE_SOURCE, imageSource);

    /* Grab the old values */
    persist->Restore(imageSource, options);

    /* Get the new value from the argument */
    int histogramChannelMode = 0;
    if (dyna_IsSet(HISTOGRAM_CHANNEL_MODE_VALUE))
    {
        attr_GetInt(HISTOGRAM_CHANNEL_MODE_VALUE, &histogramChannelMode);
        if ((histogramChannelMode < HISTOGRAM_COLORS) || (histogramChannelMode > HISTOGRAM_BLUE))
        {
            /* Out of bounds */
            basic_Message().SetCode(LXe_OUTOFBOUNDS);
            return;
        }
    }

    /* Write the values back to the config */
    options.histogramChannelMode = histogramChannelMode;
    persist->Store(imageSource, options);

    CLxCommandNotifier::Notify(HISTOGRAM_MONITOR_NOTIFIER, 0);

    /* Call the ImageMonitorService function to redraw the monitor */
    CLxUser_ImageMonitorService imSvc;
    imSvc.RefreshViews(imageSource, false);
}

LxResult CHistogramChannelModeHistogramMonitorCommand::cmd_Query(unsigned int /*index*/, ILxUnknownID vaQuery)
{
    HistogramOptions options;
    std::string      imageSource = defaultImageSource;

    InitializePersistence();

    /* Get the image source string */
    if (dyna_IsSet(HISTOGRAM_CHANNEL_MODE_IMAGE_SOURCE))
        attr_GetString(HISTOGRAM_CHANNEL_MODE_IMAGE_SOURCE, imageSource);

    /* Grab the values */
    persist->Restore(imageSource, options);

    /* Add the appropriate value to the query */
    CLxUser_ValueArray vals(vaQuery);
    return vals.Add(options.histogramChannelMode) ? LXe_OK : LXe_NOTFOUND;
}

void CHistogramChannelModeHistogramMonitorCommand::atrui_UIHints2(unsigned int /*index*/, CLxUser_UIHints& /*hints*/)
{
}

/*
 * ---------------------------------------------------------------------------
 * CParadeChannelModeHistogramMonitorCommand
 */

enum
{
    PARADE_CHANNEL_MODE_IMAGE_SOURCE,
    PARADE_CHANNEL_MODE_VALUE
};

static LXtTextValueHint hint_paradeChannel[] = { { PARADE_RED, "red" }, { PARADE_GREEN, "green" }, { PARADE_BLUE, "blue" }, { 0, nullptr } };

static const std::string paradeChannelModeName = "paradeChannelMode";

CParadeChannelModeHistogramMonitorCommand::CParadeChannelModeHistogramMonitorCommand()
{
    dyna_Add(imageSourceAttrName, std::string(LXsTYPE_STRING));  // Image Source
    basic_SetFlags(PARADE_CHANNEL_MODE_IMAGE_SOURCE, LXfCMDARG_OPTIONAL);

    dyna_Add(paradeChannelModeName, LXsTYPE_INTEGER);
    dyna_SetHint(PARADE_CHANNEL_MODE_VALUE, hint_paradeChannel);
    basic_SetFlags(PARADE_CHANNEL_MODE_VALUE, LXfCMDARG_QUERY);
}

int CParadeChannelModeHistogramMonitorCommand::basic_CmdFlags()
{
    return LXfCMD_UI;
}

bool CParadeChannelModeHistogramMonitorCommand::basic_Notifier(int index, std::string& name, std::string& args)
{
    bool result;
    if (index == 0)
    {
        name   = HISTOGRAM_MONITOR_NOTIFIER;
        args   = std::string(paradeChannelModeName) + std::string("+v");
        result = true;
    }
    else
    {
        result = false;
    }

    return result;
}

bool CParadeChannelModeHistogramMonitorCommand::basic_Enable(CLxUser_Message& /*msg*/)
{
    bool enabled = false;

    std::string imageSource = defaultImageSource;

    InitializePersistence();

    /* Get the image source string */
    if (dyna_IsSet(PARADE_CHANNEL_MODE_IMAGE_SOURCE))
    {
        attr_GetString(PARADE_CHANNEL_MODE_IMAGE_SOURCE, imageSource);
    }

    // For now, enabling is linked to a particular image processing
    // command, pending some API to determine if a slot is selected.
    if (CommandEnabled(std::string("imageProc.outputBlackLevel"), imageSource))
    {
        HistogramOptions options;

        /* Grab the old values */
        persist->Restore(imageSource, options);

        unsigned displayMode = options.displayMode;

        enabled = (displayMode == DISPLAY_RGBPARADE);
    }

    return enabled;
}

void CParadeChannelModeHistogramMonitorCommand::cmd_Execute(unsigned int /*flags*/)
{
    HistogramOptions options;
    std::string      imageSource = defaultImageSource;

    InitializePersistence();

    /* Get the image source string */
    if (dyna_IsSet(PARADE_CHANNEL_MODE_IMAGE_SOURCE))
        attr_GetString(PARADE_CHANNEL_MODE_IMAGE_SOURCE, imageSource);

    /* Grab the old values */
    persist->Restore(imageSource, options);

    /* Get the new value from the argument */
    int paradeChannelMode = 0;
    if (dyna_IsSet(PARADE_CHANNEL_MODE_VALUE))
    {
        attr_GetInt(PARADE_CHANNEL_MODE_VALUE, &paradeChannelMode);
        if ((paradeChannelMode < PARADE_RED) || (paradeChannelMode > PARADE_BLUE))
        {
            /* Out of bounds */
            basic_Message().SetCode(LXe_OUTOFBOUNDS);
            return;
        }
    }

    /* Write the values back to the config */
    options.paradeChannelMode = paradeChannelMode;
    persist->Store(imageSource, options);

    CLxCommandNotifier::Notify(HISTOGRAM_MONITOR_NOTIFIER, 0);

    /* Call the ImageMonitorService function to redraw the monitor */
    CLxUser_ImageMonitorService imSvc;
    imSvc.RefreshViews(imageSource, false);
}

LxResult CParadeChannelModeHistogramMonitorCommand::cmd_Query(unsigned int /*index*/, ILxUnknownID vaQuery)
{
    HistogramOptions options;
    std::string      imageSource = defaultImageSource;

    InitializePersistence();

    /* Get the image source string */
    if (dyna_IsSet(PARADE_CHANNEL_MODE_IMAGE_SOURCE))
        attr_GetString(PARADE_CHANNEL_MODE_IMAGE_SOURCE, imageSource);

    /* Grab the values */
    persist->Restore(imageSource, options);

    /* Add the appropriate value to the query */
    CLxUser_ValueArray vals(vaQuery);
    return vals.Add(options.paradeChannelMode) ? LXe_OK : LXe_NOTFOUND;
}

void CParadeChannelModeHistogramMonitorCommand::atrui_UIHints2(unsigned int /*index*/, CLxUser_UIHints& /*hints*/)
{
}

/*
 * ---------------------------------------------------------------------------
 * CRangeMinHistogramMonitorCommand
 */

enum
{
    HISTOGRAM_RANGE_MIN_IMAGE_SOURCE,
    HISTOGRAM_RANGE_MIN_VALUE
};

static const std::string rangeMinName = "rangeMin";

static LXtTextValueHint hint_RangeMin[] = { { 0, "%min" },           // float min 0.0
                                            { 1000000000, "%max" },  // float max 100000.0
                                            { -1, nullptr } };

CRangeMinHistogramMonitorCommand::CRangeMinHistogramMonitorCommand()
{
    dyna_Add(imageSourceAttrName, std::string(LXsTYPE_STRING));  // Image source
    basic_SetFlags(HISTOGRAM_RANGE_MIN_IMAGE_SOURCE, LXfCMDARG_OPTIONAL);

    dyna_Add(rangeMinName, LXsTYPE_FLOAT);
    dyna_SetHint(HISTOGRAM_RANGE_MIN_VALUE, hint_RangeMin);
    basic_SetFlags(HISTOGRAM_RANGE_MIN_VALUE, LXfCMDARG_QUERY);
}

int CRangeMinHistogramMonitorCommand::basic_CmdFlags()
{
    return LXfCMD_UI;
}

bool CRangeMinHistogramMonitorCommand::basic_Notifier(int index, std::string& name, std::string& /*args*/)
{
    bool result;
    if (index == 0)
    {
        name   = HISTOGRAM_MONITOR_NOTIFIER;
        result = true;
    }
    else
    {
        result = false;
    }

    return result;
}

bool CRangeMinHistogramMonitorCommand::basic_Enable(CLxUser_Message& /*msg*/)
{
    return true;
}

void CRangeMinHistogramMonitorCommand::cmd_Execute(unsigned int /*flags*/)
{
    HistogramOptions options;
    std::string      imageSource = defaultImageSource;

    InitializePersistence();

    /* Get the image source string */
    if (dyna_IsSet(HISTOGRAM_RANGE_MIN_IMAGE_SOURCE))
        attr_GetString(HISTOGRAM_RANGE_MIN_IMAGE_SOURCE, imageSource);

    /* Grab the old values */
    persist->Restore(imageSource, options);

    /* Get the new value from the argument */
    double rangeMin = 0.0;
    if (dyna_IsSet(HISTOGRAM_RANGE_MIN_VALUE))
    {
        attr_GetFlt(HISTOGRAM_RANGE_MIN_VALUE, &rangeMin);
        if ((rangeMin < 0.0) || (rangeMin > 1000000.0))
        {
            /* Out of bounds */
            basic_Message().SetCode(LXe_OUTOFBOUNDS);
            return;
        }
    }

    /* Write the values back to the config */
    options.rangeMin = static_cast<float>(rangeMin);
    persist->Store(imageSource, options);

    /* Call the ImageMonitorService function to redraw the monitor */
    CLxUser_ImageMonitorService imSvc;
    imSvc.RefreshViews(imageSource, false);
}

LxResult CRangeMinHistogramMonitorCommand::cmd_Query(unsigned int /*index*/, ILxUnknownID vaQuery)
{
    HistogramOptions options;
    std::string      imageSource = defaultImageSource;

    InitializePersistence();

    /* Get the image source string */
    if (dyna_IsSet(HISTOGRAM_RANGE_MIN_IMAGE_SOURCE))
        attr_GetString(HISTOGRAM_RANGE_MIN_IMAGE_SOURCE, imageSource);

    /* Grab the values */
    persist->Restore(imageSource, options);

    /* Add the appropriate value to the query */
    CLxUser_ValueArray vals(vaQuery);
    return vals.Add(static_cast<double>(options.rangeMin)) ? LXe_OK : LXe_NOTFOUND;
}

void CRangeMinHistogramMonitorCommand::atrui_UIHints2(unsigned int /*index*/, CLxUser_UIHints& hints)
{
    hints.MinFloat(0);
    hints.MaxFloat(1000000.0);
}

/*
 * ---------------------------------------------------------------------------
 * CRangeMaxHistogramMonitorCommand
 */

enum
{
    HISTOGRAM_RANGE_MAX_IMAGE_SOURCE,
    HISTOGRAM_RANGE_MAX_VALUE
};

static const std::string rangeMaxName = "rangeMax";

static LXtTextValueHint hint_RangeMax[] = { { 1, "%min" },           // float min 0.01
                                            { 1000000000, "%max" },  // float max 100000.0
                                            { -1, nullptr } };

CRangeMaxHistogramMonitorCommand::CRangeMaxHistogramMonitorCommand()
{
    dyna_Add(imageSourceAttrName, std::string(LXsTYPE_STRING));  // Image source
    basic_SetFlags(HISTOGRAM_RANGE_MAX_IMAGE_SOURCE, LXfCMDARG_OPTIONAL);

    dyna_Add(rangeMaxName, LXsTYPE_FLOAT);
    dyna_SetHint(HISTOGRAM_RANGE_MAX_VALUE, hint_RangeMax);
    basic_SetFlags(HISTOGRAM_RANGE_MAX_VALUE, LXfCMDARG_QUERY);
}

int CRangeMaxHistogramMonitorCommand::basic_CmdFlags()
{
    return LXfCMD_UI;
}

bool CRangeMaxHistogramMonitorCommand::basic_Notifier(int index, std::string& name, std::string& /*args*/)
{
    bool result;
    if (index == 0)
    {
        name   = HISTOGRAM_MONITOR_NOTIFIER;
        result = true;
    }
    else
    {
        result = false;
    }

    return result;
}

bool CRangeMaxHistogramMonitorCommand::basic_Enable(CLxUser_Message& /*msg*/)
{
    return true;
}

void CRangeMaxHistogramMonitorCommand::cmd_Execute(unsigned int /*flags*/)
{
    HistogramOptions options;
    std::string      imageSource = defaultImageSource;

    InitializePersistence();

    /* Get the image source string */
    if (dyna_IsSet(HISTOGRAM_RANGE_MAX_IMAGE_SOURCE))
        attr_GetString(HISTOGRAM_RANGE_MAX_IMAGE_SOURCE, imageSource);

    /* Grab the old values */
    persist->Restore(imageSource, options);

    /* Get the new value from the argument */
    double rangeMax = 0.0;
    if (dyna_IsSet(HISTOGRAM_RANGE_MAX_VALUE))
    {
        attr_GetFlt(HISTOGRAM_RANGE_MAX_VALUE, &rangeMax);
        if ((rangeMax < 0.0) || (rangeMax > 1000000.0))
        {
            /* Out of bounds */
            basic_Message().SetCode(LXe_OUTOFBOUNDS);
            return;
        }
    }

    /* Write the values back to the config */
    options.rangeMax = static_cast<float>(rangeMax);
    persist->Store(imageSource, options);

    /* Call the ImageMonitorService function to redraw the monitor */
    CLxUser_ImageMonitorService imSvc;
    imSvc.RefreshViews(imageSource, false);
}

LxResult CRangeMaxHistogramMonitorCommand::cmd_Query(unsigned int /*index*/, ILxUnknownID vaQuery)
{
    HistogramOptions options;
    std::string      imageSource = defaultImageSource;

    InitializePersistence();

    /* Get the image source string */
    if (dyna_IsSet(HISTOGRAM_RANGE_MAX_IMAGE_SOURCE))
        attr_GetString(HISTOGRAM_RANGE_MAX_IMAGE_SOURCE, imageSource);

    /* Grab the values */
    persist->Restore(imageSource, options);

    /* Add the appropriate value to the query */
    CLxUser_ValueArray vals(vaQuery);
    return vals.Add(static_cast<double>(options.rangeMax)) ? LXe_OK : LXe_NOTFOUND;
}

void CRangeMaxHistogramMonitorCommand::atrui_UIHints2(unsigned int /*index*/, CLxUser_UIHints& hints)
{
    hints.MinFloat(0);
    hints.MaxFloat(1000000.0);
}

/*
 * ---------------------------------------------------------------------------
 * COutputBlackLevelHistogramMonitorCommand
 */

enum
{
    HISTOGRAM_OUTPUT_BLACK_LEVEL_IMAGE_SOURCE,
    HISTOGRAM_OUTPUT_BLACK_LEVEL_VALUE
};

static const std::string outputBlackLevelArgName = "level";

static LXtTextValueHint hint_outputBlackLevel[] = { { 0, "%min" },      // float min 0
                                                    { 10000, "%max" },  // float max 1.0
                                                    { -1, nullptr } };

COutputBlackLevelHistogramMonitorCommand::COutputBlackLevelHistogramMonitorCommand()
{
    dyna_Add(imageSourceAttrName, std::string(LXsTYPE_STRING));  // Image source
    basic_SetFlags(HISTOGRAM_OUTPUT_BLACK_LEVEL_IMAGE_SOURCE, LXfCMDARG_OPTIONAL);

    dyna_Add(outputBlackLevelArgName, LXsTYPE_PERCENT);
    dyna_SetHint(HISTOGRAM_OUTPUT_BLACK_LEVEL_VALUE, hint_outputBlackLevel);
    basic_SetFlags(HISTOGRAM_OUTPUT_BLACK_LEVEL_VALUE, LXfCMDARG_QUERY);
}

int COutputBlackLevelHistogramMonitorCommand::basic_CmdFlags()
{
    return LXfCMD_UNDO_UI;
}

bool COutputBlackLevelHistogramMonitorCommand::basic_Notifier(int index, std::string& name, std::string& args)
{
    std::string imageSource = defaultImageSource;

    InitializePersistence();

    /* Get the image source string */
    if (dyna_IsSet(HISTOGRAM_OUTPUT_BLACK_LEVEL_IMAGE_SOURCE))
    {
        attr_GetString(HISTOGRAM_OUTPUT_BLACK_LEVEL_IMAGE_SOURCE, imageSource);
    }

    bool result;
    if (index == 0)
    {
        name   = HISTOGRAM_MONITOR_NOTIFIER;
        result = true;
    }
    else if (index == 1)
    {
        name   = std::string(LXsIMAGEPROC_NOTIFIER);
        args   = imageSource + std::string(" resetToDefaults+vd outputBlackLevel+v");
        result = true;
    }
    else if (index == 2)
    {
        name   = std::string(LXsIMAGEMONITOR_SOURCE_NOTIFIER);
        args   = imageSource + std::string("+vd");
        result = true;
    }
    else
    {
        result = false;
    }

    return result;
}

bool COutputBlackLevelHistogramMonitorCommand::basic_Enable(CLxUser_Message& /*msg*/)
{
    bool        enabled     = false;
    std::string imageSource = defaultImageSource;

    InitializePersistence();

    /* Get the image source string */
    if (dyna_IsSet(HISTOGRAM_OUTPUT_BLACK_LEVEL_IMAGE_SOURCE))
    {
        attr_GetString(HISTOGRAM_OUTPUT_BLACK_LEVEL_IMAGE_SOURCE, imageSource);
    }

    if (CommandEnabled(std::string("imageProc.outputBlackLevel"), imageSource))
    {
        HistogramOptions options;

        /* Grab the old values */
        persist->Restore(imageSource, options);

        unsigned histogramChannelMode = options.histogramChannelMode;

        enabled = (options.displayMode == DISPLAY_HISTOGRAM) && (histogramChannelMode != HISTOGRAM_RED) &&
                  (histogramChannelMode != HISTOGRAM_GREEN) && (histogramChannelMode != HISTOGRAM_BLUE);
    }

    return enabled;
}

static LxResult SetOutputLevelCommand(const std::string& commandName, const std::string& imageSource, float level)
{
    LxResult result = LXe_FAILED;

    // Execute the command to set the output level on the image processing object.
    CLxUser_CommandService cmdSvc;
    CLxLoc_Command         imageProcSetLevelCmd;
    if (cmdSvc.NewCommand(imageProcSetLevelCmd, commandName.c_str()))
    {
        CLxUser_Attributes arg;
        arg.set(imageProcSetLevelCmd);

        int c0ArgIndex = arg.FindIndex("source");
        int c1ArgIndex = arg.FindIndex("level");
        if (arg.Set(c0ArgIndex, imageSource.c_str()) && arg.Set(c1ArgIndex, level))
        {
            imageProcSetLevelCmd.Execute(0);
        }

        CLxCommandNotifier::Notify(HISTOGRAM_MONITOR_NOTIFIER, 0);

        // [TODO] Check if we really need to invalidate here, or if it's automatic.
        CLxUser_ImageMonitorService imSvc;
        imSvc.RefreshViews(imageSource, true);

        result = LXe_OK;
    }

    return result;
}

void COutputBlackLevelHistogramMonitorCommand::cmd_Execute(unsigned int /*flags*/)
{
    HistogramOptions options;
    std::string      imageSource = defaultImageSource;

    InitializePersistence();

    /* Get the image source string */
    if (dyna_IsSet(HISTOGRAM_OUTPUT_BLACK_LEVEL_IMAGE_SOURCE))
        attr_GetString(HISTOGRAM_OUTPUT_BLACK_LEVEL_IMAGE_SOURCE, imageSource);

    /* Grab the old values */
    persist->Restore(imageSource, options);

    /* Get the new value from the argument */
    double outputLevel = 0.0;
    if (dyna_IsSet(HISTOGRAM_OUTPUT_BLACK_LEVEL_VALUE))
    {
        attr_GetFlt(HISTOGRAM_OUTPUT_BLACK_LEVEL_VALUE, &outputLevel);
        if ((outputLevel < 0.0) || (outputLevel > 1.0))
        {
            /* Out of bounds */
            basic_Message().SetCode(LXe_OUTOFBOUNDS);
            return;
        }
    }

    SetOutputLevelCommand(std::string("imageProc.outputBlackLevel"), imageSource, static_cast<float>(outputLevel));

    /* Call the ImageMonitorService function to redraw the monitor */
    CLxUser_ImageMonitorService imSvc;
    imSvc.RefreshViews(imageSource, false);
}

LxResult COutputBlackLevelHistogramMonitorCommand::cmd_Query(unsigned int index, ILxUnknownID vaQuery)
{
    HistogramOptions options;
    std::string      imageSource = defaultImageSource;
    LxResult         result      = LXe_NOTFOUND;

    InitializePersistence();

    /* Get the image source string */
    if (dyna_IsSet(HISTOGRAM_OUTPUT_BLACK_LEVEL_IMAGE_SOURCE))
        attr_GetString(HISTOGRAM_OUTPUT_BLACK_LEVEL_IMAGE_SOURCE, imageSource);

    /* Grab the values */
    persist->Restore(imageSource, options);

    /* Set up a value array for the query. */
    CLxUser_ValueArray vals(vaQuery);

    /* Create the command and run the query. */
    CLxUser_CommandService cmdSvc;
    CLxLoc_Command         imageProcSetLevelCmd;
    if (cmdSvc.NewCommand(imageProcSetLevelCmd, "imageProc.outputBlackLevel"))
    {
        CLxUser_Attributes arg;
        arg.set(imageProcSetLevelCmd);

        int c0ArgIndex = arg.FindIndex("source");
        if (arg.Set(c0ArgIndex, imageSource.c_str()))
        {
            result = imageProcSetLevelCmd.Query(index, vals);
        }
    }

    return result;
}

void COutputBlackLevelHistogramMonitorCommand::atrui_UIHints2(unsigned int /*index*/, CLxUser_UIHints& hints)
{
    hints.MinFloat(0);
    hints.MaxFloat(1.0);
}

/*
 * ---------------------------------------------------------------------------
 * COutputWhiteLevelHistogramMonitorCommand
 */

enum
{
    HISTOGRAM_OUTPUT_WHITE_LEVEL_IMAGE_SOURCE,
    HISTOGRAM_OUTPUT_WHITE_LEVEL_VALUE
};

#define MAX_OUTPUT_MAX_LEVEL 10000.0

static const std::string outputWhiteLevelArgName = "level";

static LXtTextValueHint hint_outputWhiteLevel[] = { { 0, "%min" },          // float min 0
                                                    { 100000000, "%max" },  // float max 1000000.0
                                                    { -1, nullptr } };

COutputWhiteLevelHistogramMonitorCommand::COutputWhiteLevelHistogramMonitorCommand()
{
    dyna_Add(imageSourceAttrName, std::string(LXsTYPE_STRING));  // Image source
    basic_SetFlags(HISTOGRAM_OUTPUT_WHITE_LEVEL_IMAGE_SOURCE, LXfCMDARG_OPTIONAL);

    dyna_Add(outputWhiteLevelArgName, LXsTYPE_PERCENT);
    dyna_SetHint(HISTOGRAM_OUTPUT_WHITE_LEVEL_VALUE, hint_outputWhiteLevel);
    basic_SetFlags(HISTOGRAM_OUTPUT_WHITE_LEVEL_VALUE, LXfCMDARG_QUERY);
}

int COutputWhiteLevelHistogramMonitorCommand::basic_CmdFlags()
{
    return LXfCMD_UNDO_UI;
}

bool COutputWhiteLevelHistogramMonitorCommand::basic_Notifier(int index, std::string& name, std::string& args)
{
    std::string imageSource = defaultImageSource;

    InitializePersistence();

    /* Get the image source string */
    if (dyna_IsSet(HISTOGRAM_OUTPUT_WHITE_LEVEL_IMAGE_SOURCE))
    {
        attr_GetString(HISTOGRAM_OUTPUT_WHITE_LEVEL_IMAGE_SOURCE, imageSource);
    }

    bool result;
    if (index == 0)
    {
        name   = HISTOGRAM_MONITOR_NOTIFIER;
        result = true;
    }
    else if (index == 1)
    {
        name   = std::string(LXsIMAGEPROC_NOTIFIER);
        args   = imageSource + std::string(" resetToDefaults+vd outputWhiteLevel+v");
        result = true;
    }
    else if (index == 2)
    {
        name   = std::string(LXsIMAGEMONITOR_SOURCE_NOTIFIER);
        args   = imageSource + std::string("+vd");
        result = true;
    }
    else
    {
        result = false;
    }

    return result;
}

bool COutputWhiteLevelHistogramMonitorCommand::basic_Enable(CLxUser_Message& /*msg*/)
{
    bool        enabled     = false;
    std::string imageSource = defaultImageSource;

    InitializePersistence();

    /* Get the image source string */
    if (dyna_IsSet(HISTOGRAM_OUTPUT_WHITE_LEVEL_IMAGE_SOURCE))
    {
        attr_GetString(HISTOGRAM_OUTPUT_WHITE_LEVEL_IMAGE_SOURCE, imageSource);
    }

    if (CommandEnabled(std::string("imageProc.outputWhiteLevel"), imageSource))
    {
        HistogramOptions options;

        /* Grab the old values */
        persist->Restore(imageSource, options);

        unsigned histogramChannelMode = options.histogramChannelMode;

        enabled = (options.displayMode == DISPLAY_HISTOGRAM) && (histogramChannelMode != HISTOGRAM_RED) &&
                  (histogramChannelMode != HISTOGRAM_GREEN) && (histogramChannelMode != HISTOGRAM_BLUE);
    }

    return enabled;
}

void COutputWhiteLevelHistogramMonitorCommand::cmd_Execute(unsigned int /*flags*/)
{
    HistogramOptions options;
    std::string      imageSource = defaultImageSource;

    InitializePersistence();

    /* Get the image source string */
    if (dyna_IsSet(HISTOGRAM_OUTPUT_WHITE_LEVEL_IMAGE_SOURCE))
        attr_GetString(HISTOGRAM_OUTPUT_WHITE_LEVEL_IMAGE_SOURCE, imageSource);

    /* Grab the old values */
    persist->Restore(imageSource, options);

    /* Get the new value from the argument */
    double outputLevel = 1.0;
    if (dyna_IsSet(HISTOGRAM_OUTPUT_WHITE_LEVEL_VALUE))
    {
        attr_GetFlt(HISTOGRAM_OUTPUT_WHITE_LEVEL_VALUE, &outputLevel);
        if ((outputLevel < 0.0) || (outputLevel > MAX_OUTPUT_MAX_LEVEL))
        {
            /* Out of bounds */
            basic_Message().SetCode(LXe_OUTOFBOUNDS);
            return;
        }
    }

    SetOutputLevelCommand(std::string("imageProc.outputWhiteLevel"), imageSource, static_cast<float>(outputLevel));

    /* Call the ImageMonitorService function to redraw the monitor */
    CLxUser_ImageMonitorService imSvc;
    imSvc.RefreshViews(imageSource, false);
}

LxResult COutputWhiteLevelHistogramMonitorCommand::cmd_Query(unsigned int index, ILxUnknownID vaQuery)
{
    LxResult result = LXe_NOTFOUND;

    HistogramOptions options;
    std::string      imageSource = defaultImageSource;

    InitializePersistence();

    /* Get the image source string */
    if (dyna_IsSet(HISTOGRAM_OUTPUT_WHITE_LEVEL_IMAGE_SOURCE))
        attr_GetString(HISTOGRAM_OUTPUT_WHITE_LEVEL_IMAGE_SOURCE, imageSource);

    /* Grab the values */
    persist->Restore(imageSource, options);

    /* Set up a value array for the query. */
    CLxUser_ValueArray vals(vaQuery);

    /* Create the command and run the query. */
    CLxUser_CommandService cmdSvc;
    CLxLoc_Command         imageProcSetLevelCmd;
    if (cmdSvc.NewCommand(imageProcSetLevelCmd, "imageProc.outputWhiteLevel"))
    {
        CLxUser_Attributes arg;
        arg.set(imageProcSetLevelCmd);

        int c0ArgIndex = arg.FindIndex("source");
        if (arg.Set(c0ArgIndex, imageSource.c_str()))
        {
            result = imageProcSetLevelCmd.Query(index, vals);
        }
    }

    return result;
}

void COutputWhiteLevelHistogramMonitorCommand::atrui_UIHints2(unsigned int /*index*/, CLxUser_UIHints& hints)
{
    hints.MinFloat(0);
    hints.MaxFloat(1000000.0);
}

/*
 * ---------------------------------------------------------------------------
 * COutputMinRedLevelHistogramMonitorCommand
 */

enum
{
    HISTOGRAM_OUTPUT_MIN_RED_LEVEL_IMAGE_SOURCE,
    HISTOGRAM_OUTPUT_MIN_RED_LEVEL_VALUE
};

static const std::string outputMinRedLevelArgName = "level";

static LXtTextValueHint hint_outputMinRedLevel[] = { { 0, "%min" },      // float min 0
                                                     { 10000, "%max" },  // float max 1.0
                                                     { -1, nullptr } };

COutputMinRedLevelHistogramMonitorCommand::COutputMinRedLevelHistogramMonitorCommand()
{
    dyna_Add(imageSourceAttrName, std::string(LXsTYPE_STRING));  // Image source
    basic_SetFlags(HISTOGRAM_OUTPUT_MIN_RED_LEVEL_IMAGE_SOURCE, LXfCMDARG_OPTIONAL);

    dyna_Add(outputMinRedLevelArgName, LXsTYPE_PERCENT);
    dyna_SetHint(HISTOGRAM_OUTPUT_MIN_RED_LEVEL_VALUE, hint_outputMinRedLevel);
    basic_SetFlags(HISTOGRAM_OUTPUT_MIN_RED_LEVEL_VALUE, LXfCMDARG_QUERY);
}

int COutputMinRedLevelHistogramMonitorCommand::basic_CmdFlags()
{
    return LXfCMD_UNDO_UI;
}

bool COutputMinRedLevelHistogramMonitorCommand::basic_Notifier(int index, std::string& name, std::string& args)
{
    std::string imageSource = defaultImageSource;

    InitializePersistence();

    /* Get the image source string */
    if (dyna_IsSet(HISTOGRAM_OUTPUT_MIN_RED_LEVEL_IMAGE_SOURCE))
    {
        attr_GetString(HISTOGRAM_OUTPUT_MIN_RED_LEVEL_IMAGE_SOURCE, imageSource);
    }

    bool result;
    if (index == 0)
    {
        name   = HISTOGRAM_MONITOR_NOTIFIER;
        result = true;
    }
    else if (index == 1)
    {
        name   = std::string(LXsIMAGEPROC_NOTIFIER);
        args   = imageSource + std::string(" resetToDefaults+vd outputMinRedLevel+v");
        result = true;
    }
    else if (index == 2)
    {
        name   = std::string(LXsIMAGEMONITOR_SOURCE_NOTIFIER);
        args   = imageSource + std::string("+vd");
        result = true;
    }
    else
    {
        result = false;
    }

    return result;
}

bool COutputMinRedLevelHistogramMonitorCommand::basic_Enable(CLxUser_Message& /*msg*/)
{
    bool        enabled     = false;
    std::string imageSource = defaultImageSource;

    InitializePersistence();

    /* Get the image source string */
    if (dyna_IsSet(HISTOGRAM_OUTPUT_MIN_RED_LEVEL_IMAGE_SOURCE))
    {
        attr_GetString(HISTOGRAM_OUTPUT_MIN_RED_LEVEL_IMAGE_SOURCE, imageSource);
    }

    if (CommandEnabled(std::string("imageProc.outputMinRedLevel"), imageSource))
    {
        HistogramOptions options;

        /* Grab the old values */
        persist->Restore(imageSource, options);

        unsigned displayMode          = options.displayMode;
        unsigned histogramChannelMode = options.histogramChannelMode;
        unsigned paradeChannelMode    = options.paradeChannelMode;
        enabled                       = ((displayMode == DISPLAY_HISTOGRAM) && (histogramChannelMode == HISTOGRAM_RED)) ||
                  ((displayMode == DISPLAY_RGBPARADE) && (paradeChannelMode == PARADE_RED));
    }

    return enabled;
}

void COutputMinRedLevelHistogramMonitorCommand::cmd_Execute(unsigned int /*flags*/)
{
    HistogramOptions options;
    std::string      imageSource = defaultImageSource;

    InitializePersistence();

    /* Get the image source string */
    if (dyna_IsSet(HISTOGRAM_OUTPUT_MIN_RED_LEVEL_IMAGE_SOURCE))
        attr_GetString(HISTOGRAM_OUTPUT_MIN_RED_LEVEL_IMAGE_SOURCE, imageSource);

    /* Grab the old values */
    persist->Restore(imageSource, options);

    /* Get the new value from the argument */
    double outputLevel = 0.0;
    if (dyna_IsSet(HISTOGRAM_OUTPUT_MIN_RED_LEVEL_VALUE))
    {
        attr_GetFlt(HISTOGRAM_OUTPUT_MIN_RED_LEVEL_VALUE, &outputLevel);
        if ((outputLevel < 0.0) || (outputLevel > 1.0))
        {
            /* Out of bounds */
            basic_Message().SetCode(LXe_OUTOFBOUNDS);
            return;
        }
    }

    SetOutputLevelCommand(std::string("imageProc.outputMinRedLevel"), imageSource, static_cast<float>(outputLevel));

    /* Call the ImageMonitorService function to redraw the monitor */
    CLxUser_ImageMonitorService imSvc;
    imSvc.RefreshViews(imageSource, false);
}

LxResult COutputMinRedLevelHistogramMonitorCommand::cmd_Query(unsigned int index, ILxUnknownID vaQuery)
{
    HistogramOptions options;
    std::string      imageSource = defaultImageSource;
    LxResult         result      = LXe_NOTFOUND;

    InitializePersistence();

    /* Get the image source string */
    if (dyna_IsSet(HISTOGRAM_OUTPUT_MIN_RED_LEVEL_IMAGE_SOURCE))
        attr_GetString(HISTOGRAM_OUTPUT_MIN_RED_LEVEL_IMAGE_SOURCE, imageSource);

    /* Grab the values */
    persist->Restore(imageSource, options);

    /* Set up a value array for the query. */
    CLxUser_ValueArray vals(vaQuery);

    /* Create the command and run the query. */
    CLxUser_CommandService cmdSvc;
    CLxLoc_Command         imageProcSetLevelCmd;
    if (cmdSvc.NewCommand(imageProcSetLevelCmd, "imageProc.outputMinRedLevel"))
    {
        CLxUser_Attributes arg;
        arg.set(imageProcSetLevelCmd);

        int c0ArgIndex = arg.FindIndex("source");
        if (arg.Set(c0ArgIndex, imageSource.c_str()))
        {
            result = imageProcSetLevelCmd.Query(index, vals);
        }
    }

    return result;
}

void COutputMinRedLevelHistogramMonitorCommand::atrui_UIHints2(unsigned int /*index*/, CLxUser_UIHints& hints)
{
    hints.MinFloat(0);
    hints.MaxFloat(1.0);
}

/*
 * ---------------------------------------------------------------------------
 * COutputMaxRedLevelHistogramMonitorCommand
 */

enum
{
    HISTOGRAM_OUTPUT_MAX_RED_LEVEL_IMAGE_SOURCE,
    HISTOGRAM_OUTPUT_MAX_RED_LEVEL_VALUE
};

static const std::string outputMaxRedLevelArgName = "level";

static LXtTextValueHint hint_outputMaxRedLevel[] = { { 0, "%min" },          // float min 0
                                                     { 100000000, "%max" },  // float max 1000000.0
                                                     { -1, nullptr } };

COutputMaxRedLevelHistogramMonitorCommand::COutputMaxRedLevelHistogramMonitorCommand()
{
    dyna_Add(imageSourceAttrName, std::string(LXsTYPE_STRING));  // Image source
    basic_SetFlags(HISTOGRAM_OUTPUT_MAX_RED_LEVEL_IMAGE_SOURCE, LXfCMDARG_OPTIONAL);

    dyna_Add(outputMaxRedLevelArgName, LXsTYPE_PERCENT);
    dyna_SetHint(HISTOGRAM_OUTPUT_MAX_RED_LEVEL_VALUE, hint_outputMaxRedLevel);
    basic_SetFlags(HISTOGRAM_OUTPUT_MAX_RED_LEVEL_VALUE, LXfCMDARG_QUERY);
}

int COutputMaxRedLevelHistogramMonitorCommand::basic_CmdFlags()
{
    return LXfCMD_UNDO_UI;
}

bool COutputMaxRedLevelHistogramMonitorCommand::basic_Notifier(int index, std::string& name, std::string& args)
{
    std::string imageSource = defaultImageSource;

    InitializePersistence();

    /* Get the image source string */
    if (dyna_IsSet(HISTOGRAM_OUTPUT_MAX_RED_LEVEL_IMAGE_SOURCE))
    {
        attr_GetString(HISTOGRAM_OUTPUT_MAX_RED_LEVEL_IMAGE_SOURCE, imageSource);
    }

    bool result;
    if (index == 0)
    {
        name   = HISTOGRAM_MONITOR_NOTIFIER;
        result = true;
    }
    else if (index == 1)
    {
        name   = std::string(LXsIMAGEPROC_NOTIFIER);
        args   = imageSource + std::string(" resetToDefaults+vd outputMaxRedLevel+v");
        result = true;
    }
    else if (index == 2)
    {
        name   = std::string(LXsIMAGEMONITOR_SOURCE_NOTIFIER);
        args   = imageSource + std::string("+vd");
        result = true;
    }
    else
    {
        result = false;
    }

    return result;
}

bool COutputMaxRedLevelHistogramMonitorCommand::basic_Enable(CLxUser_Message& /*msg*/)
{
    bool        enabled     = false;
    std::string imageSource = defaultImageSource;

    InitializePersistence();

    /* Get the image source string */
    if (dyna_IsSet(HISTOGRAM_OUTPUT_MAX_RED_LEVEL_IMAGE_SOURCE))
    {
        attr_GetString(HISTOGRAM_OUTPUT_MAX_RED_LEVEL_IMAGE_SOURCE, imageSource);
    }

    if (CommandEnabled(std::string("imageProc.outputMaxRedLevel"), imageSource))
    {
        HistogramOptions options;

        /* Grab the old values */
        persist->Restore(imageSource, options);

        unsigned displayMode          = options.displayMode;
        unsigned histogramChannelMode = options.histogramChannelMode;
        unsigned paradeChannelMode    = options.paradeChannelMode;
        enabled                       = ((displayMode == DISPLAY_HISTOGRAM) && (histogramChannelMode == HISTOGRAM_RED)) ||
                  ((displayMode == DISPLAY_RGBPARADE) && (paradeChannelMode == PARADE_RED));
    }

    return enabled;
}

void COutputMaxRedLevelHistogramMonitorCommand::cmd_Execute(unsigned int /*flags*/)
{
    HistogramOptions options;
    std::string      imageSource = defaultImageSource;

    InitializePersistence();

    /* Get the image source string */
    if (dyna_IsSet(HISTOGRAM_OUTPUT_MAX_RED_LEVEL_IMAGE_SOURCE))
        attr_GetString(HISTOGRAM_OUTPUT_MAX_RED_LEVEL_IMAGE_SOURCE, imageSource);

    /* Grab the old values */
    persist->Restore(imageSource, options);

    /* Get the new value from the argument */
    double outputLevel = 0.0;
    if (dyna_IsSet(HISTOGRAM_OUTPUT_MAX_RED_LEVEL_VALUE))
    {
        attr_GetFlt(HISTOGRAM_OUTPUT_MAX_RED_LEVEL_VALUE, &outputLevel);
        if ((outputLevel < 0.0) || (outputLevel > MAX_OUTPUT_MAX_LEVEL))
        {
            /* Out of bounds */
            basic_Message().SetCode(LXe_OUTOFBOUNDS);
            return;
        }
    }

    SetOutputLevelCommand(std::string("imageProc.outputMaxRedLevel"), imageSource, static_cast<float>(outputLevel));

    /* Call the ImageMonitorService function to redraw the monitor */
    CLxUser_ImageMonitorService imSvc;
    imSvc.RefreshViews(imageSource, false);
}

LxResult COutputMaxRedLevelHistogramMonitorCommand::cmd_Query(unsigned int index, ILxUnknownID vaQuery)
{
    HistogramOptions options;
    std::string      imageSource = defaultImageSource;
    LxResult         result      = LXe_NOTFOUND;

    InitializePersistence();

    /* Get the image source string */
    if (dyna_IsSet(HISTOGRAM_OUTPUT_MAX_RED_LEVEL_IMAGE_SOURCE))
        attr_GetString(HISTOGRAM_OUTPUT_MAX_RED_LEVEL_IMAGE_SOURCE, imageSource);

    /* Grab the values */
    persist->Restore(imageSource, options);

    /* Set up a value array for the query. */
    CLxUser_ValueArray vals(vaQuery);

    /* Create the command and run the query. */
    CLxUser_CommandService cmdSvc;
    CLxLoc_Command         imageProcSetLevelCmd;
    if (cmdSvc.NewCommand(imageProcSetLevelCmd, "imageProc.outputMaxRedLevel"))
    {
        CLxUser_Attributes arg;
        arg.set(imageProcSetLevelCmd);

        int c0ArgIndex = arg.FindIndex("source");
        if (arg.Set(c0ArgIndex, imageSource.c_str()))
        {
            result = imageProcSetLevelCmd.Query(index, vals);
        }
    }

    return result;
}

void COutputMaxRedLevelHistogramMonitorCommand::atrui_UIHints2(unsigned int /*index*/, CLxUser_UIHints& hints)
{
    hints.MinFloat(0);
    hints.MaxFloat(MAX_OUTPUT_MAX_LEVEL);
}

/*
 * ---------------------------------------------------------------------------
 * COutputMinGreenLevelHistogramMonitorCommand
 */

enum
{
    HISTOGRAM_OUTPUT_MIN_GREEN_LEVEL_IMAGE_SOURCE,
    HISTOGRAM_OUTPUT_MIN_GREEN_LEVEL_VALUE
};

static const std::string outputMinGreenLevelArgName = "level";

static LXtTextValueHint hint_outputMinGreenLevel[] = { { 0, "%min" },      // float min 0
                                                       { 10000, "%max" },  // float max 1.0
                                                       { -1, nullptr } };

COutputMinGreenLevelHistogramMonitorCommand::COutputMinGreenLevelHistogramMonitorCommand()
{
    dyna_Add(imageSourceAttrName, std::string(LXsTYPE_STRING));  // Image source
    basic_SetFlags(HISTOGRAM_OUTPUT_MIN_GREEN_LEVEL_IMAGE_SOURCE, LXfCMDARG_OPTIONAL);

    dyna_Add(outputMinGreenLevelArgName, LXsTYPE_PERCENT);
    dyna_SetHint(HISTOGRAM_OUTPUT_MIN_GREEN_LEVEL_VALUE, hint_outputMinGreenLevel);
    basic_SetFlags(HISTOGRAM_OUTPUT_MIN_GREEN_LEVEL_VALUE, LXfCMDARG_QUERY);
}

int COutputMinGreenLevelHistogramMonitorCommand::basic_CmdFlags()
{
    return LXfCMD_UNDO_UI;
}

bool COutputMinGreenLevelHistogramMonitorCommand::basic_Notifier(int index, std::string& name, std::string& args)
{
    std::string imageSource = defaultImageSource;

    InitializePersistence();

    /* Get the image source string */
    if (dyna_IsSet(HISTOGRAM_OUTPUT_MIN_GREEN_LEVEL_IMAGE_SOURCE))
    {
        attr_GetString(HISTOGRAM_OUTPUT_MIN_GREEN_LEVEL_IMAGE_SOURCE, imageSource);
    }

    bool result;
    if (index == 0)
    {
        name   = HISTOGRAM_MONITOR_NOTIFIER;
        result = true;
    }
    else if (index == 1)
    {
        name   = std::string(LXsIMAGEPROC_NOTIFIER);
        args   = imageSource + std::string(" resetToDefaults+vd outputMinGreenLevel+v");
        result = true;
    }
    else if (index == 2)
    {
        name   = std::string(LXsIMAGEMONITOR_SOURCE_NOTIFIER);
        args   = imageSource + std::string("+vd");
        result = true;
    }
    else
    {
        result = false;
    }

    return result;
}

bool COutputMinGreenLevelHistogramMonitorCommand::basic_Enable(CLxUser_Message& /*msg*/)
{
    bool        enabled     = false;
    std::string imageSource = defaultImageSource;

    InitializePersistence();

    /* Get the image source string */
    if (dyna_IsSet(HISTOGRAM_OUTPUT_MIN_GREEN_LEVEL_IMAGE_SOURCE))
    {
        attr_GetString(HISTOGRAM_OUTPUT_MIN_GREEN_LEVEL_IMAGE_SOURCE, imageSource);
    }

    if (CommandEnabled(std::string("imageProc.outputMinGreenLevel"), imageSource))
    {
        HistogramOptions options;

        /* Grab the old values */
        persist->Restore(imageSource, options);

        unsigned displayMode          = options.displayMode;
        unsigned histogramChannelMode = options.histogramChannelMode;
        unsigned paradeChannelMode    = options.paradeChannelMode;
        enabled                       = ((displayMode == DISPLAY_HISTOGRAM) && (histogramChannelMode == HISTOGRAM_GREEN)) ||
                  ((displayMode == DISPLAY_RGBPARADE) && (paradeChannelMode == PARADE_GREEN));
    }

    return enabled;
}

void COutputMinGreenLevelHistogramMonitorCommand::cmd_Execute(unsigned int /*flags*/)
{
    HistogramOptions options;
    std::string      imageSource = defaultImageSource;

    InitializePersistence();

    /* Get the image source string */
    if (dyna_IsSet(HISTOGRAM_OUTPUT_MIN_GREEN_LEVEL_IMAGE_SOURCE))
        attr_GetString(HISTOGRAM_OUTPUT_MIN_GREEN_LEVEL_IMAGE_SOURCE, imageSource);

    /* Grab the old values */
    persist->Restore(imageSource, options);

    /* Get the new value from the argument */
    double outputLevel = 0.0;
    if (dyna_IsSet(HISTOGRAM_OUTPUT_MIN_GREEN_LEVEL_VALUE))
    {
        attr_GetFlt(HISTOGRAM_OUTPUT_MIN_GREEN_LEVEL_VALUE, &outputLevel);
        if ((outputLevel < 0.0) || (outputLevel > 1.0))
        {
            /* Out of bounds */
            basic_Message().SetCode(LXe_OUTOFBOUNDS);
            return;
        }
    }

    SetOutputLevelCommand(std::string("imageProc.outputMinGreenLevel"), imageSource, static_cast<float>(outputLevel));

    /* Call the ImageMonitorService function to redraw the monitor */
    CLxUser_ImageMonitorService imSvc;
    imSvc.RefreshViews(imageSource, false);
}

LxResult COutputMinGreenLevelHistogramMonitorCommand::cmd_Query(unsigned int index, ILxUnknownID vaQuery)
{
    HistogramOptions options;
    std::string      imageSource = defaultImageSource;
    LxResult         result      = LXe_NOTFOUND;

    InitializePersistence();

    /* Get the image source string */
    if (dyna_IsSet(HISTOGRAM_OUTPUT_MIN_GREEN_LEVEL_IMAGE_SOURCE))
        attr_GetString(HISTOGRAM_OUTPUT_MIN_GREEN_LEVEL_IMAGE_SOURCE, imageSource);

    /* Grab the values */
    persist->Restore(imageSource, options);

    /* Set up a value array for the query. */
    CLxUser_ValueArray vals(vaQuery);

    /* Create the command and run the query. */
    CLxUser_CommandService cmdSvc;
    CLxLoc_Command         imageProcSetLevelCmd;
    if (cmdSvc.NewCommand(imageProcSetLevelCmd, "imageProc.outputMinGreenLevel"))
    {
        CLxUser_Attributes arg;
        arg.set(imageProcSetLevelCmd);

        int c0ArgIndex = arg.FindIndex("source");
        if (arg.Set(c0ArgIndex, imageSource.c_str()))
        {
            result = imageProcSetLevelCmd.Query(index, vals);
        }
    }

    return result;
}

void COutputMinGreenLevelHistogramMonitorCommand::atrui_UIHints2(unsigned int /*index*/, CLxUser_UIHints& hints)
{
    hints.MinFloat(0);
    hints.MaxFloat(1.0);
}

/*
 * ---------------------------------------------------------------------------
 * COutputMaxGreenLevelHistogramMonitorCommand
 */

enum
{
    HISTOGRAM_OUTPUT_MAX_GREEN_LEVEL_IMAGE_SOURCE,
    HISTOGRAM_OUTPUT_MAX_GREEN_LEVEL_VALUE
};

static const std::string outputMaxGreenLevelArgName = "level";

static LXtTextValueHint hint_outputMaxGreenLevel[] = { { 0, "%min" },          // float min 0
                                                       { 100000000, "%max" },  // float max 1000000.0
                                                       { -1, nullptr } };

COutputMaxGreenLevelHistogramMonitorCommand::COutputMaxGreenLevelHistogramMonitorCommand()
{
    dyna_Add(imageSourceAttrName, std::string(LXsTYPE_STRING));  // Image source
    basic_SetFlags(HISTOGRAM_OUTPUT_MAX_GREEN_LEVEL_IMAGE_SOURCE, LXfCMDARG_OPTIONAL);

    dyna_Add(outputMaxGreenLevelArgName, LXsTYPE_PERCENT);
    dyna_SetHint(HISTOGRAM_OUTPUT_MAX_GREEN_LEVEL_VALUE, hint_outputMaxGreenLevel);
    basic_SetFlags(HISTOGRAM_OUTPUT_MAX_GREEN_LEVEL_VALUE, LXfCMDARG_QUERY);
}

int COutputMaxGreenLevelHistogramMonitorCommand::basic_CmdFlags()
{
    return LXfCMD_UNDO_UI;
}

bool COutputMaxGreenLevelHistogramMonitorCommand::basic_Notifier(int index, std::string& name, std::string& args)
{
    std::string imageSource = defaultImageSource;

    InitializePersistence();

    /* Get the image source string */
    if (dyna_IsSet(HISTOGRAM_OUTPUT_MAX_GREEN_LEVEL_IMAGE_SOURCE))
    {
        attr_GetString(HISTOGRAM_OUTPUT_MAX_GREEN_LEVEL_IMAGE_SOURCE, imageSource);
    }

    bool result;
    if (index == 0)
    {
        name   = HISTOGRAM_MONITOR_NOTIFIER;
        result = true;
    }
    else if (index == 1)
    {
        name   = std::string(LXsIMAGEPROC_NOTIFIER);
        args   = imageSource + std::string(" resetToDefaults+vd outputMaxGreenLevel+v");
        result = true;
    }
    else if (index == 2)
    {
        name   = std::string(LXsIMAGEMONITOR_SOURCE_NOTIFIER);
        args   = imageSource + std::string("+vd");
        result = true;
    }
    else
    {
        result = false;
    }

    return result;
}

bool COutputMaxGreenLevelHistogramMonitorCommand::basic_Enable(CLxUser_Message& /*msg*/)
{
    bool        enabled     = false;
    std::string imageSource = defaultImageSource;

    InitializePersistence();

    /* Get the image source string */
    if (dyna_IsSet(HISTOGRAM_OUTPUT_BLACK_LEVEL_IMAGE_SOURCE))
    {
        attr_GetString(HISTOGRAM_OUTPUT_BLACK_LEVEL_IMAGE_SOURCE, imageSource);
    }

    if (CommandEnabled(std::string("imageProc.outputMaxGreenLevel"), imageSource))
    {
        HistogramOptions options;

        /* Grab the old values */
        persist->Restore(imageSource, options);

        unsigned displayMode          = options.displayMode;
        unsigned histogramChannelMode = options.histogramChannelMode;
        unsigned paradeChannelMode    = options.paradeChannelMode;
        enabled                       = ((displayMode == DISPLAY_HISTOGRAM) && (histogramChannelMode == HISTOGRAM_GREEN)) ||
                  ((displayMode == DISPLAY_RGBPARADE) && (paradeChannelMode == PARADE_GREEN));
    }

    return enabled;
}

void COutputMaxGreenLevelHistogramMonitorCommand::cmd_Execute(unsigned int /*flags*/)
{
    HistogramOptions options;
    std::string      imageSource = defaultImageSource;

    InitializePersistence();

    /* Get the image source string */
    if (dyna_IsSet(HISTOGRAM_OUTPUT_MAX_GREEN_LEVEL_IMAGE_SOURCE))
        attr_GetString(HISTOGRAM_OUTPUT_MAX_GREEN_LEVEL_IMAGE_SOURCE, imageSource);

    /* Grab the old values */
    persist->Restore(imageSource, options);

    /* Get the new value from the argument */
    double outputLevel = 0.0;
    if (dyna_IsSet(HISTOGRAM_OUTPUT_MAX_GREEN_LEVEL_VALUE))
    {
        attr_GetFlt(HISTOGRAM_OUTPUT_MAX_GREEN_LEVEL_VALUE, &outputLevel);
        if ((outputLevel < 0.0) || (outputLevel > MAX_OUTPUT_MAX_LEVEL))
        {
            /* Out of bounds */
            basic_Message().SetCode(LXe_OUTOFBOUNDS);
            return;
        }
    }

    SetOutputLevelCommand(std::string("imageProc.outputMaxGreenLevel"), imageSource, static_cast<float>(outputLevel));

    /* Call the ImageMonitorService function to redraw the monitor */
    CLxUser_ImageMonitorService imSvc;
    imSvc.RefreshViews(imageSource, false);
}

LxResult COutputMaxGreenLevelHistogramMonitorCommand::cmd_Query(unsigned int index, ILxUnknownID vaQuery)
{
    HistogramOptions options;
    std::string      imageSource = defaultImageSource;
    LxResult         result      = LXe_NOTFOUND;

    InitializePersistence();

    /* Get the image source string */
    if (dyna_IsSet(HISTOGRAM_RANGE_MAX_IMAGE_SOURCE))
        attr_GetString(HISTOGRAM_RANGE_MAX_IMAGE_SOURCE, imageSource);

    /* Grab the values */
    persist->Restore(imageSource, options);

    /* Set up a value array for the query. */
    CLxUser_ValueArray vals(vaQuery);

    /* Create the command and run the query. */
    CLxUser_CommandService cmdSvc;
    CLxLoc_Command         imageProcSetLevelCmd;
    if (cmdSvc.NewCommand(imageProcSetLevelCmd, "imageProc.outputMaxGreenLevel"))
    {
        CLxUser_Attributes arg;
        arg.set(imageProcSetLevelCmd);

        int c0ArgIndex = arg.FindIndex("source");
        if (arg.Set(c0ArgIndex, imageSource.c_str()))
        {
            result = imageProcSetLevelCmd.Query(index, vals);
        }
    }

    return result;
}

void COutputMaxGreenLevelHistogramMonitorCommand::atrui_UIHints2(unsigned int /*index*/, CLxUser_UIHints& hints)
{
    hints.MinFloat(0);
    hints.MaxFloat(MAX_OUTPUT_MAX_LEVEL);
}

/*
 * ---------------------------------------------------------------------------
 * COutputMinBlueLevelHistogramMonitorCommand
 */

enum
{
    HISTOGRAM_OUTPUT_MIN_BLUE_LEVEL_IMAGE_SOURCE,
    HISTOGRAM_OUTPUT_MIN_BLUE_LEVEL_VALUE
};

static const std::string outputMinBlueLevelArgName = "level";

static LXtTextValueHint hint_outputMinBlueLevel[] = { { 0, "%min" },      // float min 0
                                                      { 10000, "%max" },  // float max 1.0
                                                      { -1, nullptr } };

COutputMinBlueLevelHistogramMonitorCommand::COutputMinBlueLevelHistogramMonitorCommand()
{
    dyna_Add(imageSourceAttrName, std::string(LXsTYPE_STRING));  // Image source
    basic_SetFlags(HISTOGRAM_OUTPUT_MIN_BLUE_LEVEL_IMAGE_SOURCE, LXfCMDARG_OPTIONAL);

    dyna_Add(outputMinBlueLevelArgName, LXsTYPE_PERCENT);
    dyna_SetHint(HISTOGRAM_OUTPUT_MIN_BLUE_LEVEL_VALUE, hint_outputMinBlueLevel);
    basic_SetFlags(HISTOGRAM_OUTPUT_MIN_BLUE_LEVEL_VALUE, LXfCMDARG_QUERY);
}

int COutputMinBlueLevelHistogramMonitorCommand::basic_CmdFlags()
{
    return LXfCMD_UNDO_UI;
}

bool COutputMinBlueLevelHistogramMonitorCommand::basic_Notifier(int index, std::string& name, std::string& args)
{
    std::string imageSource = defaultImageSource;

    InitializePersistence();

    /* Get the image source string */
    if (dyna_IsSet(HISTOGRAM_OUTPUT_MIN_BLUE_LEVEL_IMAGE_SOURCE))
    {
        attr_GetString(HISTOGRAM_OUTPUT_MIN_BLUE_LEVEL_IMAGE_SOURCE, imageSource);
    }

    bool result;
    if (index == 0)
    {
        name   = HISTOGRAM_MONITOR_NOTIFIER;
        result = true;
    }
    else if (index == 1)
    {
        name   = std::string(LXsIMAGEPROC_NOTIFIER);
        args   = imageSource + std::string(" resetToDefaults+vd outputMinBlueLevel+v");
        result = true;
    }
    else if (index == 2)
    {
        name   = std::string(LXsIMAGEMONITOR_SOURCE_NOTIFIER);
        args   = imageSource + std::string("+vd");
        result = true;
    }
    else
    {
        result = false;
    }

    return result;
}

bool COutputMinBlueLevelHistogramMonitorCommand::basic_Enable(CLxUser_Message& /*msg*/)
{
    bool        enabled     = false;
    std::string imageSource = defaultImageSource;

    InitializePersistence();

    /* Get the image source string */
    if (dyna_IsSet(HISTOGRAM_OUTPUT_MIN_BLUE_LEVEL_IMAGE_SOURCE))
    {
        attr_GetString(HISTOGRAM_OUTPUT_MIN_BLUE_LEVEL_IMAGE_SOURCE, imageSource);
    }

    if (CommandEnabled(std::string("imageProc.outputMinBlueLevel"), imageSource))
    {
        HistogramOptions options;

        /* Grab the old values */
        persist->Restore(imageSource, options);

        unsigned displayMode          = options.displayMode;
        unsigned histogramChannelMode = options.histogramChannelMode;
        unsigned paradeChannelMode    = options.paradeChannelMode;
        enabled                       = ((displayMode == DISPLAY_HISTOGRAM) && (histogramChannelMode == HISTOGRAM_BLUE)) ||
                  ((displayMode == DISPLAY_RGBPARADE) && (paradeChannelMode == PARADE_BLUE));
    }

    return enabled;
}

void COutputMinBlueLevelHistogramMonitorCommand::cmd_Execute(unsigned int /*flags*/)
{
    HistogramOptions options;
    std::string      imageSource = defaultImageSource;

    InitializePersistence();

    /* Get the image source string */
    if (dyna_IsSet(HISTOGRAM_OUTPUT_MIN_BLUE_LEVEL_IMAGE_SOURCE))
        attr_GetString(HISTOGRAM_OUTPUT_MIN_BLUE_LEVEL_IMAGE_SOURCE, imageSource);

    /* Grab the old values */
    persist->Restore(imageSource, options);

    /* Get the new value from the argument */
    double outputLevel = 0.0;
    if (dyna_IsSet(HISTOGRAM_OUTPUT_MIN_BLUE_LEVEL_VALUE))
    {
        attr_GetFlt(HISTOGRAM_OUTPUT_MIN_BLUE_LEVEL_VALUE, &outputLevel);
        if ((outputLevel < 0.0) || (outputLevel > 1.0))
        {
            /* Out of bounds */
            basic_Message().SetCode(LXe_OUTOFBOUNDS);
            return;
        }
    }

    SetOutputLevelCommand(std::string("imageProc.outputMinBlueLevel"), imageSource, static_cast<float>(outputLevel));

    /* Call the ImageMonitorService function to redraw the monitor */
    CLxUser_ImageMonitorService imSvc;
    imSvc.RefreshViews(imageSource, false);
}

LxResult COutputMinBlueLevelHistogramMonitorCommand::cmd_Query(unsigned int index, ILxUnknownID vaQuery)
{
    HistogramOptions options;
    std::string      imageSource = defaultImageSource;
    LxResult         result      = LXe_NOTFOUND;

    InitializePersistence();

    /* Get the image source string */
    if (dyna_IsSet(HISTOGRAM_RANGE_MAX_IMAGE_SOURCE))
        attr_GetString(HISTOGRAM_RANGE_MAX_IMAGE_SOURCE, imageSource);

    /* Grab the values */
    persist->Restore(imageSource, options);

    /* Set up a value array for the query. */
    CLxUser_ValueArray vals(vaQuery);

    /* Create the command and run the query. */
    CLxUser_CommandService cmdSvc;
    CLxLoc_Command         imageProcSetLevelCmd;
    if (cmdSvc.NewCommand(imageProcSetLevelCmd, "imageProc.outputMinBlueLevel"))
    {
        CLxUser_Attributes arg;
        arg.set(imageProcSetLevelCmd);

        int c0ArgIndex = arg.FindIndex("source");
        if (arg.Set(c0ArgIndex, imageSource.c_str()))
        {
            result = imageProcSetLevelCmd.Query(index, vals);
        }
    }

    return result;
}

void COutputMinBlueLevelHistogramMonitorCommand::atrui_UIHints2(unsigned int /*index*/, CLxUser_UIHints& hints)
{
    hints.MinFloat(0);
    hints.MaxFloat(1.0);
}

/*
 * ---------------------------------------------------------------------------
 * COutputMaxBlueLevelHistogramMonitorCommand
 */

enum
{
    HISTOGRAM_OUTPUT_MAX_BLUE_LEVEL_IMAGE_SOURCE,
    HISTOGRAM_OUTPUT_MAX_BLUE_LEVEL_VALUE
};

static const std::string outputMaxBlueLevelArgName = "level";

static LXtTextValueHint hint_outputMaxBlueLevel[] = { { 0, "%min" },          // float min 0
                                                      { 100000000, "%max" },  // float max 1000000.0
                                                      { -1, nullptr } };

COutputMaxBlueLevelHistogramMonitorCommand::COutputMaxBlueLevelHistogramMonitorCommand()
{
    dyna_Add(imageSourceAttrName, std::string(LXsTYPE_STRING));  // Image source
    basic_SetFlags(HISTOGRAM_OUTPUT_MAX_BLUE_LEVEL_IMAGE_SOURCE, LXfCMDARG_OPTIONAL);

    dyna_Add(outputMaxBlueLevelArgName, LXsTYPE_PERCENT);
    dyna_SetHint(HISTOGRAM_OUTPUT_MAX_BLUE_LEVEL_VALUE, hint_outputMaxBlueLevel);
    basic_SetFlags(HISTOGRAM_OUTPUT_MAX_BLUE_LEVEL_VALUE, LXfCMDARG_QUERY);
}

int COutputMaxBlueLevelHistogramMonitorCommand::basic_CmdFlags()
{
    return LXfCMD_UNDO_UI;
}

bool COutputMaxBlueLevelHistogramMonitorCommand::basic_Notifier(int index, std::string& name, std::string& args)
{
    std::string imageSource = defaultImageSource;

    InitializePersistence();

    /* Get the image source string */
    if (dyna_IsSet(HISTOGRAM_OUTPUT_MAX_BLUE_LEVEL_IMAGE_SOURCE))
    {
        attr_GetString(HISTOGRAM_OUTPUT_MAX_BLUE_LEVEL_IMAGE_SOURCE, imageSource);
    }

    bool result;
    if (index == 0)
    {
        name   = HISTOGRAM_MONITOR_NOTIFIER;
        result = true;
    }
    else if (index == 1)
    {
        name   = std::string(LXsIMAGEPROC_NOTIFIER);
        args   = imageSource + std::string(" resetToDefaults+vd outputMaxBlueLevel+v");
        result = true;
    }
    else if (index == 2)
    {
        name   = std::string(LXsIMAGEMONITOR_SOURCE_NOTIFIER);
        args   = imageSource + std::string("+vd");
        result = true;
    }
    else
    {
        result = false;
    }

    return result;
}

bool COutputMaxBlueLevelHistogramMonitorCommand::basic_Enable(CLxUser_Message& /*msg*/)
{
    bool        enabled     = false;
    std::string imageSource = defaultImageSource;

    InitializePersistence();

    /* Get the image source string */
    if (dyna_IsSet(HISTOGRAM_OUTPUT_MAX_BLUE_LEVEL_IMAGE_SOURCE))
    {
        attr_GetString(HISTOGRAM_OUTPUT_MAX_BLUE_LEVEL_IMAGE_SOURCE, imageSource);
    }

    if (CommandEnabled(std::string("imageProc.outputMaxBlueLevel"), imageSource))
    {
        HistogramOptions options;

        /* Grab the old values */
        persist->Restore(imageSource, options);

        unsigned displayMode          = options.displayMode;
        unsigned histogramChannelMode = options.histogramChannelMode;
        unsigned paradeChannelMode    = options.paradeChannelMode;
        enabled                       = ((displayMode == DISPLAY_HISTOGRAM) && (histogramChannelMode == HISTOGRAM_BLUE)) ||
                  ((displayMode == DISPLAY_RGBPARADE) && (paradeChannelMode == PARADE_BLUE));
    }

    return enabled;
}

void COutputMaxBlueLevelHistogramMonitorCommand::cmd_Execute(unsigned int /*flags*/)
{
    HistogramOptions options;
    std::string      imageSource = defaultImageSource;

    InitializePersistence();

    /* Get the image source string */
    if (dyna_IsSet(HISTOGRAM_OUTPUT_MAX_BLUE_LEVEL_IMAGE_SOURCE))
        attr_GetString(HISTOGRAM_OUTPUT_MAX_BLUE_LEVEL_IMAGE_SOURCE, imageSource);

    /* Grab the old values */
    persist->Restore(imageSource, options);

    /* Get the new value from the argument */
    double outputLevel = 0.0;
    if (dyna_IsSet(HISTOGRAM_OUTPUT_MAX_BLUE_LEVEL_VALUE))
    {
        attr_GetFlt(HISTOGRAM_OUTPUT_MAX_BLUE_LEVEL_VALUE, &outputLevel);
        if ((outputLevel < 0.0) || (outputLevel > MAX_OUTPUT_MAX_LEVEL))
        {
            /* Out of bounds */
            basic_Message().SetCode(LXe_OUTOFBOUNDS);
            return;
        }
    }

    SetOutputLevelCommand(std::string("imageProc.outputMaxBlueLevel"), imageSource, static_cast<float>(outputLevel));

    /* Call the ImageMonitorService function to redraw the monitor */
    CLxUser_ImageMonitorService imSvc;
    imSvc.RefreshViews(imageSource, false);
}

LxResult COutputMaxBlueLevelHistogramMonitorCommand::cmd_Query(unsigned int index, ILxUnknownID vaQuery)
{
    HistogramOptions options;
    std::string      imageSource = defaultImageSource;
    LxResult         result      = LXe_NOTFOUND;

    InitializePersistence();

    /* Get the image source string */
    if (dyna_IsSet(HISTOGRAM_OUTPUT_MAX_BLUE_LEVEL_IMAGE_SOURCE))
        attr_GetString(HISTOGRAM_OUTPUT_MAX_BLUE_LEVEL_IMAGE_SOURCE, imageSource);

    /* Grab the values */
    persist->Restore(imageSource, options);

    /* Set up a value array for the query. */
    CLxUser_ValueArray vals(vaQuery);

    /* Create the command and run the query. */
    CLxUser_CommandService cmdSvc;
    CLxLoc_Command         imageProcSetLevelCmd;
    if (cmdSvc.NewCommand(imageProcSetLevelCmd, "imageProc.outputMaxBlueLevel"))
    {
        CLxUser_Attributes arg;
        arg.set(imageProcSetLevelCmd);

        int c0ArgIndex = arg.FindIndex("source");
        if (arg.Set(c0ArgIndex, imageSource.c_str()))
        {
            result = imageProcSetLevelCmd.Query(index, vals);
        }
    }

    return result;
}

void COutputMaxBlueLevelHistogramMonitorCommand::atrui_UIHints2(unsigned int /*index*/, CLxUser_UIHints& hints)
{
    hints.MinFloat(0);
    hints.MaxFloat(MAX_OUTPUT_MAX_LEVEL);
}

/*
 * ---------------------------------------------------------------------------
 * CHistogramMonitor.
 */

LXtTagInfoDesc CHistogramMonitor::descInfo[] = { { LXsLOD_CLASSLIST, LXa_IMAGEMONITOR },
                                                 { LXsSRV_USERNAME, "Histogram" },
                                                 { LXsSRV_LOGSUBSYSTEM, SERVER_HISTOGRAM_MONITOR },
                                                 { nullptr } };

/*
 * The color resolution; determine the number of levels in the graph.
 */
static const int LEVEL_RESOLUTION = 256;

/*
 * Dimensions for the legend and the thumbs.
 */
static const int LEGEND_HEIGHT       = 17;
static const int LEGEND_THUMB_OFFSET = 5;
static const int LEGEND_THUMB_INSET  = 9;

static const int MARGIN_SIZE  = 1;
static const int TOTAL_MARGIN = MARGIN_SIZE * 2;

static const int PARADE_INSET = LEGEND_THUMB_INSET;

CHistogramMonitor::CHistogramMonitor()
    : sharingThumbnail(false), hasSourceBuffer(false), sourceBufferIndex(0), hasSourceImage(false), levelResolution(LEVEL_RESOLUTION),
      legendHeight(LEGEND_HEIGHT), legendThumbOffset(LEGEND_THUMB_OFFSET), legendThumbInset(LEGEND_THUMB_INSET), paradeInset(PARADE_INSET)
{
    InitializePersistence();

/*
 * Pre-load the primary and secondary marker images.
 */
#define OUTPUT_BLACK_LEVEL_MARKER_16 "BlackPoint16.tga"
#define OUTPUT_BLACK_LEVEL_MARKER_32 "BlackPoint32.tga"

#define OUTPUT_WHITE_LEVEL_MARKER_16 "WhitePoint16.tga"
#define OUTPUT_WHITE_LEVEL_MARKER_32 "WhitePoint32.tga"

#define OUTPUT_MIN_RED_LEVEL_MARKER_16 "BlackPoint16.tga"
#define OUTPUT_MIN_RED_LEVEL_MARKER_32 "BlackPoint32.tga"

#define OUTPUT_MAX_RED_LEVEL_MARKER_16 "WhitePoint16.tga"
#define OUTPUT_MAX_RED_LEVEL_MARKER_32 "WhitePoint32.tga"

#define OUTPUT_MIN_GREEN_LEVEL_MARKER_16 "BlackPoint16.tga"
#define OUTPUT_MIN_GREEN_LEVEL_MARKER_32 "BlackPoint32.tga"

#define OUTPUT_MAX_GREEN_LEVEL_MARKER_16 "WhitePoint16.tga"
#define OUTPUT_MAX_GREEN_LEVEL_MARKER_32 "WhitePoint32.tga"

#define OUTPUT_MIN_BLUE_LEVEL_MARKER_16 "BlackPoint16.tga"
#define OUTPUT_MIN_BLUE_LEVEL_MARKER_32 "BlackPoint32.tga"

#define OUTPUT_MAX_BLUE_LEVEL_MARKER_16 "WhitePoint16.tga"
#define OUTPUT_MAX_BLUE_LEVEL_MARKER_32 "WhitePoint32.tga"

    CLxUser_FileService fileSvc;
    std::string         systemPath;
    if (LXx_OK(fileSvc.FileSystemPath(LXsSYSTEM_PATH_RESOURCE, systemPath)))
    {
        CLxUser_ImageService imageSvc;

        // Black / White
        std::string outputBlackLevelMarker16Path(systemPath);
        outputBlackLevelMarker16Path = outputBlackLevelMarker16Path + std::string("/") + std::string(OUTPUT_BLACK_LEVEL_MARKER_16);

        std::string outputBlackLevelMarker32Path(systemPath);
        outputBlackLevelMarker32Path = outputBlackLevelMarker32Path + std::string("/") + std::string(OUTPUT_BLACK_LEVEL_MARKER_32);

        std::string outputWhiteLevelMarker16Path(systemPath);
        outputWhiteLevelMarker16Path = outputWhiteLevelMarker16Path + std::string("/") + std::string(OUTPUT_WHITE_LEVEL_MARKER_16);

        std::string outputWhiteLevelMarker32Path(systemPath);
        outputWhiteLevelMarker32Path = outputWhiteLevelMarker32Path + std::string("/") + std::string(OUTPUT_WHITE_LEVEL_MARKER_32);

        imageSvc.Load(outputBlackLevel_marker16, outputBlackLevelMarker16Path);
        imageSvc.Load(outputBlackLevel_marker32, outputBlackLevelMarker32Path);

        imageSvc.Load(outputWhiteLevel_marker16, outputWhiteLevelMarker16Path);
        imageSvc.Load(outputWhiteLevel_marker32, outputWhiteLevelMarker32Path);

        // Red
        std::string outputMinRedLevelMarker16Path(systemPath);
        outputMinRedLevelMarker16Path = outputMinRedLevelMarker16Path + std::string("/") + std::string(OUTPUT_MIN_RED_LEVEL_MARKER_16);

        std::string outputMinRedLevelMarker32Path(systemPath);
        outputMinRedLevelMarker32Path = outputMinRedLevelMarker32Path + std::string("/") + std::string(OUTPUT_MIN_RED_LEVEL_MARKER_32);

        std::string outputMaxRedLevelMarker16Path(systemPath);
        outputMaxRedLevelMarker16Path = outputMaxRedLevelMarker16Path + std::string("/") + std::string(OUTPUT_MAX_RED_LEVEL_MARKER_16);

        std::string outputMaxRedLevelMarker32Path(systemPath);
        outputMaxRedLevelMarker32Path = outputMaxRedLevelMarker32Path + std::string("/") + std::string(OUTPUT_MAX_RED_LEVEL_MARKER_32);

        imageSvc.Load(outputMinRedLevel_marker16, outputMinRedLevelMarker16Path);
        imageSvc.Load(outputMinRedLevel_marker32, outputMinRedLevelMarker32Path);

        imageSvc.Load(outputMaxRedLevel_marker16, outputMaxRedLevelMarker16Path);
        imageSvc.Load(outputMaxRedLevel_marker32, outputMaxRedLevelMarker32Path);

        // Green
        std::string outputMinGreenLevelMarker16Path(systemPath);
        outputMinGreenLevelMarker16Path = outputMinGreenLevelMarker16Path + std::string("/") + std::string(OUTPUT_MIN_GREEN_LEVEL_MARKER_16);

        std::string outputMinGreenLevelMarker32Path(systemPath);
        outputMinGreenLevelMarker32Path = outputMinGreenLevelMarker32Path + std::string("/") + std::string(OUTPUT_MIN_GREEN_LEVEL_MARKER_32);

        std::string outputMaxGreenLevelMarker16Path(systemPath);
        outputMaxGreenLevelMarker16Path = outputMaxGreenLevelMarker16Path + std::string("/") + std::string(OUTPUT_MAX_GREEN_LEVEL_MARKER_16);

        std::string outputMaxGreenLevelMarker32Path(systemPath);
        outputMaxGreenLevelMarker32Path = outputMaxGreenLevelMarker32Path + std::string("/") + std::string(OUTPUT_MAX_GREEN_LEVEL_MARKER_32);

        imageSvc.Load(outputMinGreenLevel_marker16, outputMinGreenLevelMarker16Path);
        imageSvc.Load(outputMinGreenLevel_marker32, outputMinGreenLevelMarker32Path);

        imageSvc.Load(outputMaxGreenLevel_marker16, outputMaxGreenLevelMarker16Path);
        imageSvc.Load(outputMaxGreenLevel_marker32, outputMaxGreenLevelMarker32Path);

        // Blue
        std::string outputMinBlueLevelMarker16Path(systemPath);
        outputMinBlueLevelMarker16Path = outputMinBlueLevelMarker16Path + std::string("/") + std::string(OUTPUT_MIN_BLUE_LEVEL_MARKER_16);

        std::string outputMinBlueLevelMarker32Path(systemPath);
        outputMinBlueLevelMarker32Path = outputMinBlueLevelMarker32Path + std::string("/") + std::string(OUTPUT_MIN_BLUE_LEVEL_MARKER_32);

        std::string outputMaxBlueLevelMarker16Path(systemPath);
        outputMaxBlueLevelMarker16Path = outputMaxBlueLevelMarker16Path + std::string("/") + std::string(OUTPUT_MAX_BLUE_LEVEL_MARKER_16);

        std::string outputMaxBlueLevelMarker32Path(systemPath);
        outputMaxBlueLevelMarker32Path = outputMaxBlueLevelMarker32Path + std::string("/") + std::string(OUTPUT_MAX_BLUE_LEVEL_MARKER_32);

        imageSvc.Load(outputMinBlueLevel_marker16, outputMinBlueLevelMarker16Path);
        imageSvc.Load(outputMinBlueLevel_marker32, outputMinBlueLevelMarker32Path);

        imageSvc.Load(outputMaxBlueLevel_marker16, outputMaxBlueLevelMarker16Path);
        imageSvc.Load(outputMaxBlueLevel_marker32, outputMaxBlueLevelMarker32Path);
    }
}

CHistogramMonitor::~CHistogramMonitor()
{
}

LxResult CHistogramMonitor::imon_Image(ILxUnknownID imageToAnalyze,
                                       ILxUnknownID frameBufferToAnalyze,
                                       int          bufferIndex,
                                       double       x1,
                                       double       y1,
                                       double       x2,
                                       double       y2,
                                       ILxUnknownID imageProcRead,
                                       ILxUnknownID processedThumbnail)
{
    LxResult result = LXe_FALSE;

    sharingThumbnail = false;

    regionX1 = x1;
    regionY1 = y1;
    regionX2 = x2;
    regionY2 = y2;

    if (processedThumbnail != nullptr || imageToAnalyze != nullptr)
    {
        if (hasSourceBuffer)
        {
            cachedImage.clear();
            frameBuffer.clear();
            sourceBuffer.clear();
            hasSourceBuffer = false;
        }

        if (processedThumbnail != nullptr)
        {
            hasSourceImage = cachedImage.set(processedThumbnail);
            imageProcessing.set(imageProcRead);
            sharingThumbnail = true;

            result = LXe_OK;
        }
        else
        {
            fullSourceImage.set(imageToAnalyze);
            imageProcessing.set(imageProcRead);

            result = AnalyzeImage();
        }
    }
    else
    {
        if (hasSourceImage)
        {
            fullSourceImage.clear();
            imageProcessing.clear();
            hasSourceImage = false;
        }

        cachedImage.clear();

        if (frameBufferToAnalyze)
        {
            sourceBufferIndex = bufferIndex;
            frameBuffer.set(frameBufferToAnalyze);

            hasSourceBuffer = frameBuffer.ByIndex(sourceBuffer, bufferIndex);
            if (hasSourceBuffer)
            {
                imageProcessing.set(imageProcRead);

                result = AnalyzeFrameBuffer();
            }
        }
        else if (hasSourceBuffer)
        {
            sourceBuffer.clear();
            hasSourceBuffer = false;
        }
    }

    return result;
}

LxResult CHistogramMonitor::imon_ImageProcChanged(void)
{
    LxResult result = LXe_FALSE;

    if (hasSourceImage)
    {
        if (sharingThumbnail)
        {
            result = LXe_OK;
        }
        else
        {
            result = AnalyzeImage();
        }
    }
    else if (hasSourceBuffer)
    {
        result = AnalyzeFrameBuffer();
    }

    return result;
}

LxResult CHistogramMonitor::imon_AspectRange(double* minAspect, double* maxAspect, double* idealAspect)
{
    *minAspect   = 0.5;
    *maxAspect   = 2.0;
    *idealAspect = 1.0;

    return LXe_OK;
}

LxResult CHistogramMonitor::imon_Draw(ILxUnknownID imageForDrawing)
{
    CLxUser_ImageWrite writeImage;
    writeImage.set(imageForDrawing);

    bool histogramDrawn = false;

    if ((writeImage.Width() <= TOTAL_MARGIN + (legendThumbInset * 2)) || (writeImage.Height() <= TOTAL_MARGIN + legendHeight))
    {
        return LXe_FALSE;
    }

    m_dstWidth  = writeImage.Width() - TOTAL_MARGIN - (legendThumbInset * 2);
    m_dstHeight = writeImage.Height() - TOTAL_MARGIN;

    m_dstHeight -= legendHeight;

    if (hasSourceImage || hasSourceBuffer)
    {
        if (DisplayMode() == DISPLAY_RGBPARADE)
        {
            histogramDrawn = DrawParade(writeImage, m_dstWidth, m_dstHeight);
        }
        else
            switch (HistogramChannelMode())
            {
                case HISTOGRAM_COLORS:
                    histogramDrawn = DrawColors(writeImage, m_dstWidth, m_dstHeight);
                    break;

                case HISTOGRAM_LUMINOSITY:
                    histogramDrawn = DrawLuminosity(writeImage, m_dstWidth, m_dstHeight);
                    break;

                case HISTOGRAM_RGB:
                    histogramDrawn = DrawRGB(writeImage, m_dstWidth, m_dstHeight);
                    break;

                case HISTOGRAM_RED:
                case HISTOGRAM_GREEN:
                case HISTOGRAM_BLUE:
                    histogramDrawn = DrawChannel(writeImage, m_dstWidth, m_dstHeight, HistogramChannelMode());
                    break;
            }
    }

    /*
     * Draw the legend; translucently if it's disabled.
     */
    DrawLegend(writeImage, m_dstWidth, m_dstHeight, histogramDrawn);

    if (!histogramDrawn)
    {
        /*
         * Draw the empty background.
         */
        DrawEmptyBackground(writeImage, m_dstWidth, m_dstHeight);
    }

    /*
     * Draw the border.
     */
    DrawBorder(writeImage, m_dstWidth, m_dstHeight);

    return LXe_OK;
}

LxResult CHistogramMonitor::imon_ImageSource(const char* imageSourceString)
{
    imageSource = std::string(imageSourceString);

    return LXe_OK;
}

static LxResult SetParadeChannelCommand(const std::string& imageSource, int channel)
{
    LxResult result = LXe_FAILED;

    // Execute the command to set the output level on the image processing object.
    CLxUser_CommandService cmdSvc;
    CLxLoc_Command         setParadeChannelCmd;
    if (cmdSvc.NewCommand(setParadeChannelCmd, "histogramMonitor.paradeChannelMode"))
    {
        CLxUser_Attributes arg;
        arg.set(setParadeChannelCmd);

        int c0ArgIndex = arg.FindIndex("source");
        int c1ArgIndex = arg.FindIndex("paradeChannelMode");
        if (arg.Set(c0ArgIndex, imageSource.c_str()) && arg.Set(c1ArgIndex, channel))
        {
            setParadeChannelCmd.Execute(0);
        }

        CLxCommandNotifier::Notify(HISTOGRAM_MONITOR_NOTIFIER, 0);

        // [TODO] Check if we really need to invalidate here, or if it's automatic.
        CLxUser_ImageMonitorService imSvc;
        imSvc.RefreshViews(imageSource, true);

        result = LXe_OK;
    }

    return result;
}

LxResult CHistogramMonitor::imon_MouseDown(int startx, int starty, int /*w*/, int /*h*/)
{
    if (hasSourceBuffer || hasSourceImage)
    {
        lastMouse[0] = static_cast<float>(startx);
        lastMouse[1] = static_cast<float>(starty);

        m_movingMarker = HitMarker(startx, starty);

        if (DisplayMode() == DISPLAY_RGBPARADE)
        {
            int paradeChannel = ParadeChannelMode();
            int newChannel    = startx / ((m_dstWidth + legendThumbInset * 2) / 3);
            newChannel        = LXxCLAMP(newChannel, 0, 2);
            if (newChannel != paradeChannel)
            {
                SetParadeChannelCommand(imageSource, newChannel);
            }
        }
    }

    return LXe_OK;
}

LxResult CHistogramMonitor::imon_MouseMove(int /*startx*/, int /*starty*/, int cx, int cy, int /*w*/, int /*h*/)
{
    if (m_movingMarker != Marker_None)
    {
        int deltaX   = static_cast<int>(cx - lastMouse[0]);
        lastMouse[0] = static_cast<float>(cx);
        lastMouse[1] = static_cast<float>(cy);

        if (deltaX)
        {
            float newValue = OffsetToValue(static_cast<float>(cx), m_movingMarker);

            float rangeMin = RangeMin();
            float rangeMax = RangeMax();
            newValue       = LXxCLAMP(newValue, rangeMin, rangeMax);

            switch (m_movingMarker)
            {
                case Marker_BlackPoint:
                {
                    SetBlackPoint(newValue);
                    break;
                }

                case Marker_WhitePoint:
                {
                    SetWhitePoint(newValue);
                    break;
                }

                case Marker_MinRedPoint:
                {
                    SetMinRedPoint(newValue);
                    break;
                }

                case Marker_MaxRedPoint:
                {
                    SetMaxRedPoint(newValue);
                    break;
                }

                case Marker_MinGreenPoint:
                {
                    SetMinGreenPoint(newValue);
                    break;
                }

                case Marker_MaxGreenPoint:
                {
                    SetMaxGreenPoint(newValue);
                    break;
                }

                case Marker_MinBluePoint:
                {
                    SetMinBluePoint(newValue);
                    break;
                }

                case Marker_MaxBluePoint:
                {
                    SetMaxBluePoint(newValue);
                    break;

                    default:
                        break;
                }
            }
        }
    }

    return LXe_OK;
}

LxResult CHistogramMonitor::imon_MouseUp(int /*startx*/, int /*starty*/, int /*cx*/, int /*cy*/, int /*w*/, int /*h*/)
{
    return LXe_OK;
}

LxResult CHistogramMonitor::imon_MouseTrackEnter(void)
{
    return LXe_OK;
}

LxResult CHistogramMonitor::imon_MouseTrack(int /*cx*/, int /*cy*/, int /*w*/, int /*h*/)
{
    return LXe_OK;
}

LxResult CHistogramMonitor::imon_MouseTrackExit(void)
{
    return LXe_OK;
}

LxResult CHistogramMonitor::imon_ToolTip(int /*cx*/, int /*cy*/, int /*w*/, int /*h*/, char* /*buffer*/, unsigned /*len*/)
{
    return LXe_OK;
}

unsigned CHistogramMonitor::DisplayMode(void)
{
    HistogramOptions options;
    persist->Restore(imageSource, options);

    return options.displayMode;
}

unsigned CHistogramMonitor::HistogramChannelMode(void)
{
    HistogramOptions options;
    persist->Restore(imageSource, options);

    return options.histogramChannelMode;
}

unsigned CHistogramMonitor::ParadeChannelMode(void)
{
    HistogramOptions options;
    persist->Restore(imageSource, options);

    return options.paradeChannelMode;
}

float CHistogramMonitor::RangeMin(void)
{
    HistogramOptions options;
    persist->Restore(imageSource, options);

    return static_cast<float>(options.rangeMin);
}

float CHistogramMonitor::RangeMax(void)
{
    HistogramOptions options;
    persist->Restore(imageSource, options);

    return static_cast<float>(options.rangeMax);
}

LxResult CHistogramMonitor::AnalyzeImage(void)
{
    CLxUser_ImageService imageSvc;
    LxResult             result = LXe_FALSE;

    int srcWidth, srcHeight;
    srcWidth  = fullSourceImage.Width();
    srcHeight = fullSourceImage.Height();

    int cacheWidth, cacheHeight;
    cacheWidth = srcWidth;
    while (cacheWidth > 256)
    {
        cacheWidth /= 2;
    }
    cacheWidth = LXxMAX(cacheWidth, 256);

    float zoom  = static_cast<float>(cacheWidth) / srcWidth;
    cacheHeight = static_cast<int>(zoom * srcHeight);

    float xOffset = 0, yOffset = 0;
    float resizedWidth  = static_cast<float>(cacheWidth);
    float resizedHeight = static_cast<float>(cacheHeight);
    if (regionX1 || regionY1 || regionX2 != 1 || regionY2 != 1)
    {
        // Offset is in frame buffer coordinates.
        xOffset = static_cast<float>(srcWidth * regionX1);
        yOffset = static_cast<float>(srcHeight * regionY1);

        // Width is in scaled display coordinates.
        resizedWidth  = static_cast<float>((resizedWidth * regionX2) - (xOffset * zoom));
        resizedHeight = static_cast<float>((resizedHeight * regionY2) - (yOffset * zoom));

        cacheWidth  = static_cast<int>(resizedWidth);
        cacheHeight = static_cast<int>(resizedHeight);
    }

    // [TODO] GREYFP!!
    CLxUser_Image resizedSourceImage;
    hasSourceImage = imageSvc.New(resizedSourceImage, cacheWidth, cacheHeight, fullSourceImage.Format());
    if (hasSourceImage)
    {
        CLxUser_Image cropSourceImage;
        hasSourceImage = imageSvc.NewCrop(cropSourceImage, fullSourceImage, regionX1, regionY1, regionX2 - regionX1, regionY2 - regionY1);
        if (hasSourceImage)
        {
            imageSvc.Resample(resizedSourceImage, cropSourceImage, LXiPROCESS_ACCURATE);

            hasSourceImage = imageSvc.New(cachedImage, cacheWidth, cacheHeight, fullSourceImage.Format());

            if (hasSourceImage)
            {
                // Apply the image processing without output gamma.
                LXtImageProcessingOperators rops;
                imageProcessing.GetImageProcessingOperators(&rops);

                rops = rops & ~LXiIP_OUTPUT_GAMMA;

                int isStereo = 0;
                imageProcessing.GetSourceImageIsStereoSideBySide(&isStereo);
                if (isStereo)
                {
                    rops = rops | LXiIP_STEREO;
                    rops = rops & ~LXiIP_COMPONENT_STEREO;
                }
                else
                {
                    rops = rops & ~LXiIP_STEREO;
                }

                imageProcessing.ApplyToImageOverride(resizedSourceImage, cachedImage, rops);
            }

            result = LXe_OK;
        }
    }

    return result;
}

LxResult CHistogramMonitor::AnalyzeFrameBuffer(void)
{
    CLxUser_ImageService imageSvc;
    LxResult             result = LXe_FALSE;

    int srcWidth, srcHeight;
    sourceBuffer.GetSize(srcWidth, srcHeight);

    int cacheWidth, cacheHeight;
    cacheWidth = srcWidth;
    while (cacheWidth > 256)
    {
        cacheWidth /= 2;
    }
    cacheWidth = LXxMAX(cacheWidth, 256);

    float zoom  = static_cast<float>(cacheWidth) / srcWidth;
    cacheHeight = static_cast<int>(zoom * srcHeight);

    float xOffset = 0, yOffset = 0;
    float resizedWidth  = static_cast<float>(cacheWidth);
    float resizedHeight = static_cast<float>(cacheHeight);
    if (regionX1 || regionY1 || regionX2 != 1 || regionY2 != 1)
    {
        // Offset is in frame buffer coordinates.
        xOffset = static_cast<float>(srcWidth * regionX1);
        yOffset = static_cast<float>(srcHeight * regionY1);

        // Width is in scaled display coordinates.
        resizedWidth  = static_cast<float>((resizedWidth * regionX2) - (xOffset * zoom));
        resizedHeight = static_cast<float>((resizedHeight * regionY2) - (yOffset * zoom));

        cacheWidth  = static_cast<int>(resizedWidth);
        cacheHeight = static_cast<int>(resizedHeight);
    }

    hasSourceBuffer = imageSvc.New(cachedImage, cacheWidth, cacheHeight, LXiIMP_RGBAFP);

    if (hasSourceBuffer)
    {
        // Apply the image processing without output gamma.
        LXtImageProcessingOperators rops;
        imageProcessing.GetImageProcessingOperators(&rops);

        rops = rops & ~LXiIP_OUTPUT_GAMMA;

        bool isStereo = frameBuffer.IsStereo();
        if (isStereo)
        {
            rops = rops | LXiIP_STEREO;
            rops = rops & ~LXiIP_COMPONENT_STEREO;
        }
        else
        {
            rops = rops & ~LXiIP_STEREO;
        }

        imageProcessing.ApplyToImageFromFrameBufferOverride(frameBuffer, sourceBufferIndex, cachedImage, xOffset, yOffset, zoom, rops);
    }

    return result;
}

bool CHistogramMonitor::DrawColors(CLxUser_ImageWrite& writeImage, int dstWidth, int dstHeight)
{
    bool histogramDrawn = false;

    const float muddyShadeMin   = 42;
    const float muddyShadeMax   = 110;
    const float muddyShadeRange = muddyShadeMax - muddyShadeMin;

    int srcWidth, srcHeight;
    srcWidth  = cachedImage.Width();
    srcHeight = cachedImage.Height();

    redLevels.clear();
    greenLevels.clear();
    blueLevels.clear();

    unsigned bucketIndex, bucketCount = levelResolution;
    for (bucketIndex = 0; bucketIndex < bucketCount; ++bucketIndex)
    {
        redLevels.push_back(0);
        greenLevels.push_back(0);
        blueLevels.push_back(0);
    }

    pixelCount = 0;

    float redLevel, greenLevel, blueLevel;
    float rangeMin = RangeMin(), rangeMax = RangeMax();
    float channelRange = rangeMax - rangeMin;
    for (unsigned srcY = 0; srcY < srcHeight; ++srcY)
    {
        for (unsigned srcX = 0; srcX < srcWidth; ++srcX)
        {
            float fpPixel[4];
            float red, green, blue;

            cachedImage.GetPixel(srcX, srcY, cachedImage.Format(), fpPixel);

            if (channelRange)
            {
                red = fpPixel[0];
                if (red >= rangeMin && red <= rangeMax)
                {
                    redLevel = (red - rangeMin) / channelRange * bucketCount;
                    redLevel = LXxCLAMP(redLevel, 0, bucketCount - 1);
                    redLevels[static_cast<size_t>(redLevel)] += 1;
                }

                green = fpPixel[1];
                if (green >= rangeMin && green <= rangeMax)
                {
                    greenLevel = (green - rangeMin) / channelRange * bucketCount;
                    greenLevel = LXxCLAMP(greenLevel, 0, bucketCount - 1);
                    greenLevels[static_cast<size_t>(greenLevel)] += 1;
                }

                blue = fpPixel[2];
                if (blue >= rangeMin && blue <= rangeMax)
                {
                    blueLevel = (blue - rangeMin) / channelRange * bucketCount;
                    blueLevel = LXxCLAMP(blueLevel, 0, bucketCount - 1);
                    blueLevels[static_cast<size_t>(blueLevel)] += 1;
                }
            }
            else
            {
                redLevels[0]   = redLevels[0] + 1;
                greenLevels[0] = greenLevels[0] + 1;
                blueLevels[0]  = blueLevels[0] + 1;
            }

            ++pixelCount;
        }
    }

    unsigned maxRedLevel = 0, maxGreenLevel = 0, maxBlueLevel = 0;
    for (bucketIndex = 0; bucketIndex < bucketCount; ++bucketIndex)
    {
        if (redLevels[bucketIndex] > maxRedLevel)
        {
            maxRedLevel = static_cast<unsigned>(redLevels[bucketIndex]);
        }

        if (greenLevels[bucketIndex] > maxGreenLevel)
        {
            maxGreenLevel = static_cast<unsigned>(greenLevels[bucketIndex]);
        }

        if (blueLevels[bucketIndex] > maxBlueLevel)
        {
            maxBlueLevel = static_cast<unsigned>(blueLevels[bucketIndex]);
        }
    }

    unsigned maxLevel = LXxMAX(maxRedLevel, maxGreenLevel);
    maxLevel          = LXxMAX(maxLevel, maxBlueLevel);

    const float backShadeMin   = 32;
    const float backShadeMax   = 92;
    const float backShadeRange = backShadeMax - backShadeMin;

    const float levelMinorShadeMin   = 50;
    const float levelMinorShadeMax   = 128;
    const float levelMinorShadeRange = levelMinorShadeMax - levelMinorShadeMin;

    const float levelMajorShadeMin   = 128;
    const float levelMajorShadeMax   = 255;
    const float levelMajorShadeRange = levelMajorShadeMax - levelMajorShadeMin;

    for (unsigned x = 0; x < dstWidth; ++x)
    {
        float level  = static_cast<float>(x) / static_cast<float>(dstWidth) * bucketCount;
        level        = LXxCLAMP(level, 0, bucketCount - 1);
        size_t levId = static_cast<size_t>(level);

        redLevel   = redLevels[levId] / maxLevel * dstHeight;
        greenLevel = greenLevels[levId] / maxLevel * dstHeight;
        blueLevel  = blueLevels[levId] / maxLevel * dstHeight;

        unsigned char pixelColor[4];
        pixelColor[3] = 255;
        for (int y = dstHeight - 1; y >= 0; --y)
        {
            bool redGreater   = redLevel > dstHeight - y;
            bool greenGreater = greenLevel > dstHeight - y;
            bool blueGreater  = blueLevel > dstHeight - y;

            if (redGreater && greenGreater && blueGreater)
            {
                // muddy overlap
                unsigned muddyShade = static_cast<unsigned>(muddyShadeMin + static_cast<float>(dstHeight - y) / dstHeight * muddyShadeRange);

                pixelColor[0] = static_cast<unsigned char>(muddyShade);
                pixelColor[1] = static_cast<unsigned char>(muddyShade + 20);
                pixelColor[2] = static_cast<unsigned char>(muddyShade);
            }
            else if (!redGreater && !greenGreater && !blueGreater)
            {
                // empty space
                unsigned backShade = static_cast<unsigned>(backShadeMin + static_cast<float>(dstHeight - y) / dstHeight * backShadeRange);

                pixelColor[0] = static_cast<unsigned char>(backShade);
                pixelColor[1] = static_cast<unsigned char>(backShade);
                pixelColor[2] = static_cast<unsigned char>(backShade);
            }
            else
            {
                unsigned levelMajorShade =
                static_cast<unsigned>(levelMajorShadeMin + static_cast<float>(dstHeight - y) / dstHeight * levelMajorShadeRange);

                unsigned levelMinorShade =
                static_cast<unsigned>(levelMinorShadeMin + static_cast<float>(dstHeight - y) / dstHeight * levelMinorShadeRange);

                pixelColor[0] = static_cast<unsigned char>(levelMinorShade);
                pixelColor[1] = static_cast<unsigned char>(levelMinorShade);
                pixelColor[2] = static_cast<unsigned char>(levelMinorShade);

                // single or blend of two
                if (redGreater)
                {
                    pixelColor[0] = static_cast<unsigned char>(levelMajorShade);
                }
                if (greenGreater)
                {
                    pixelColor[1] = static_cast<unsigned char>(levelMajorShade);
                }
                if (blueGreater)
                {
                    pixelColor[2] = static_cast<unsigned char>(levelMajorShade);
                }
            }
            writeImage.SetPixel(x + legendThumbInset + MARGIN_SIZE, y + MARGIN_SIZE, LXiIMP_RGBA32, pixelColor);
        }
    }
    histogramDrawn = true;

    return histogramDrawn;
}

bool CHistogramMonitor::DrawLuminosity(CLxUser_ImageWrite& writeImage, int dstWidth, int dstHeight)
{
    bool histogramDrawn = false;

    int srcWidth, srcHeight;
    srcWidth  = cachedImage.Width();
    srcHeight = cachedImage.Height();

    lumaLevels.clear();

    unsigned bucketIndex, bucketCount = levelResolution;
    for (bucketIndex = 0; bucketIndex < bucketCount; ++bucketIndex)
    {
        lumaLevels.push_back(0);
    }

    pixelCount = 0;

    float lumaLevel, luma;
    float rangeMin = RangeMin(), rangeMax = RangeMax();
    float lumaRange = rangeMax - rangeMin;
    for (unsigned srcY = 0; srcY < srcHeight; ++srcY)
    {
        for (unsigned srcX = 0; srcX < srcWidth; ++srcX)
        {
            float fpPixel[4];

            cachedImage.GetPixel(srcX, srcY, cachedImage.Format(), fpPixel);

            luma = LXx_LUMAFV(fpPixel);
            if (luma >= rangeMin && luma <= rangeMax)
            {
                lumaLevel = (luma - rangeMin) / lumaRange * bucketCount;
                lumaLevel = LXxCLAMP(lumaLevel, 0, bucketCount - 1);
                lumaLevels[static_cast<size_t>(lumaLevel)] += 1;
            }

            ++pixelCount;
        }
    }

    unsigned maxLevel = 0;
    for (bucketIndex = 0; bucketIndex < bucketCount; ++bucketIndex)
    {
        if (lumaLevels[bucketIndex] > maxLevel)
        {
            maxLevel = static_cast<unsigned>(lumaLevels[bucketIndex]);
        }
    }

    const float backShadeMin   = 32;
    const float backShadeMax   = 92;
    const float backShadeRange = backShadeMax - backShadeMin;

    const float lumaShadeMin   = 128;
    const float lumaShadeMax   = 255;
    const float lumaShadeRange = lumaShadeMax - lumaShadeMin;

    for (unsigned x = 0; x < dstWidth; ++x)
    {
        float level = static_cast<float>(x) / static_cast<float>(dstWidth) * bucketCount;
        level       = LXxCLAMP(level, 0, bucketCount - 1);

        lumaLevel = lumaLevels[static_cast<size_t>(level)] / maxLevel * dstHeight;

        unsigned char pixelColor[4];
        pixelColor[3] = 255;
        for (int y = dstHeight - 1; y >= 0; --y)
        {
            bool lumaGreater = lumaLevel > dstHeight - y;

            if (lumaGreater)
            {
                unsigned lumaShade = static_cast<unsigned>(lumaShadeMin + static_cast<float>(dstHeight - y) / dstHeight * lumaShadeRange);

                pixelColor[0] = static_cast<unsigned char>(lumaShade);
                pixelColor[1] = static_cast<unsigned char>(lumaShade);
                pixelColor[2] = static_cast<unsigned char>(lumaShade);
            }
            else
            {
                // empty space
                unsigned backShade = static_cast<unsigned>(backShadeMin + static_cast<float>(dstHeight - y) / dstHeight * backShadeRange);

                pixelColor[0] = static_cast<unsigned char>(backShade);
                pixelColor[1] = static_cast<unsigned char>(backShade);
                pixelColor[2] = static_cast<unsigned char>(backShade);
            }

            writeImage.SetPixel(x + legendThumbInset + MARGIN_SIZE, y + MARGIN_SIZE, LXiIMP_RGBA32, pixelColor);
        }
    }
    histogramDrawn = true;

    return histogramDrawn;
}

bool CHistogramMonitor::DrawRGB(CLxUser_ImageWrite& writeImage, int dstWidth, int dstHeight)
{
    bool histogramDrawn = false;

    int srcWidth, srcHeight;
    srcWidth  = cachedImage.Width();
    srcHeight = cachedImage.Height();

    lumaLevels.clear();

    unsigned bucketIndex, bucketCount = levelResolution;
    for (bucketIndex = 0; bucketIndex < bucketCount; ++bucketIndex)
    {
        lumaLevels.push_back(0);
    }

    pixelCount = 0;

    float lumaLevel, luma;
    float rangeMin = RangeMin(), rangeMax = RangeMax();
    float lumaRange = rangeMax - rangeMin;
    for (unsigned srcY = 0; srcY < srcHeight; ++srcY)
    {
        for (unsigned srcX = 0; srcX < srcWidth; ++srcX)
        {
            float fpPixel[4];

            cachedImage.GetPixel(srcX, srcY, cachedImage.Format(), fpPixel);

            luma = fpPixel[0];
            if (luma >= rangeMin && luma <= rangeMax)
            {
                lumaLevel = (luma - rangeMin) / lumaRange * bucketCount;
                lumaLevel = LXxCLAMP(lumaLevel, 0, bucketCount - 1);
                lumaLevels[static_cast<size_t>(lumaLevel)] += 1;
            }

            luma = fpPixel[1];
            if (luma >= rangeMin && luma <= rangeMax)
            {
                lumaLevel = (luma - rangeMin) / lumaRange * bucketCount;
                lumaLevel = LXxCLAMP(lumaLevel, 0, bucketCount - 1);
                lumaLevels[static_cast<size_t>(lumaLevel)] += 1;
            }

            luma = fpPixel[2];
            if (luma >= rangeMin && luma <= rangeMax)
            {
                lumaLevel = (luma - rangeMin) / lumaRange * bucketCount;
                lumaLevel = LXxCLAMP(lumaLevel, 0, bucketCount - 1);
                lumaLevels[static_cast<size_t>(lumaLevel)] += 1;
            }

            ++pixelCount;
        }
    }

    unsigned maxLevel = 0;
    for (bucketIndex = 0; bucketIndex < bucketCount; ++bucketIndex)
    {
        if (lumaLevels[bucketIndex] > maxLevel)
        {
            maxLevel = static_cast<unsigned>(lumaLevels[bucketIndex]);
        }
    }

    const float backShadeMin   = 32;
    const float backShadeMax   = 92;
    const float backShadeRange = backShadeMax - backShadeMin;

    const float lumaShadeMin   = 128;
    const float lumaShadeMax   = 255;
    const float lumaShadeRange = lumaShadeMax - lumaShadeMin;

    for (unsigned x = 0; x < dstWidth; ++x)
    {
        float level = static_cast<float>(x) / static_cast<float>(dstWidth) * bucketCount;
        level       = LXxCLAMP(level, 0, bucketCount - 1);

        lumaLevel = lumaLevels[static_cast<size_t>(level)] / maxLevel * dstHeight;

        unsigned char pixelColor[4];
        pixelColor[3] = 255;
        for (int y = dstHeight - 1; y >= 0; --y)
        {
            bool lumaGreater = lumaLevel > dstHeight - y;

            if (lumaGreater)
            {
                unsigned lumaShade = static_cast<unsigned>(lumaShadeMin + static_cast<float>(dstHeight - y) / dstHeight * lumaShadeRange);

                pixelColor[0] = static_cast<unsigned char>(lumaShade);
                pixelColor[1] = static_cast<unsigned char>(lumaShade);
                pixelColor[2] = static_cast<unsigned char>(lumaShade);
            }
            else
            {
                // empty space
                unsigned backShade = static_cast<unsigned>(backShadeMin + static_cast<float>(dstHeight - y) / dstHeight * backShadeRange);

                pixelColor[0] = static_cast<unsigned char>(backShade);
                pixelColor[1] = static_cast<unsigned char>(backShade);
                pixelColor[2] = static_cast<unsigned char>(backShade);
            }

            writeImage.SetPixel(x + legendThumbInset + MARGIN_SIZE, y + MARGIN_SIZE, LXiIMP_RGBA32, pixelColor);
        }
    }
    histogramDrawn = true;

    return histogramDrawn;
}

bool CHistogramMonitor::DrawChannel(CLxUser_ImageWrite& writeImage, int dstWidth, int dstHeight, unsigned channel)
{
    bool histogramDrawn = false;

    int srcWidth, srcHeight;
    srcWidth  = cachedImage.Width();
    srcHeight = cachedImage.Height();

    channelLevels.clear();

    unsigned bucketIndex, bucketCount = levelResolution;
    for (bucketIndex = 0; bucketIndex < bucketCount; ++bucketIndex)
    {
        channelLevels.push_back(0);
    }

    pixelCount = 0;

    float channelLevel, channelValue;
    float rangeMin = RangeMin(), rangeMax = RangeMax();
    float channelRange = rangeMax - rangeMin;
    for (unsigned srcY = 0; srcY < srcHeight; ++srcY)
    {
        for (unsigned srcX = 0; srcX < srcWidth; ++srcX)
        {
            float fpPixel[4];

            cachedImage.GetPixel(srcX, srcY, cachedImage.Format(), fpPixel);

            channelValue = fpPixel[channel - HISTOGRAM_RED];

            if (channelValue >= rangeMin && channelValue <= rangeMax)
            {
                channelLevel = (channelValue - rangeMin) / channelRange * bucketCount;
                channelLevel = LXxCLAMP(channelLevel, 0, bucketCount - 1);
                channelLevels[static_cast<size_t>(channelLevel)] += 1;
            }

            ++pixelCount;
        }
    }

    unsigned maxLevel = 0;
    for (bucketIndex = 0; bucketIndex < bucketCount; ++bucketIndex)
    {
        if (channelLevels[bucketIndex] > maxLevel)
        {
            maxLevel = static_cast<unsigned>(channelLevels[bucketIndex]);
        }
    }

    const float backShadeMin   = 32;
    const float backShadeMax   = 92;
    const float backShadeRange = backShadeMax - backShadeMin;

    const float channelShadeMin   = 128;
    const float channelShadeMax   = 255;
    const float channelShadeRange = channelShadeMax - channelShadeMin;

    for (unsigned x = 0; x < dstWidth; ++x)
    {
        float level = static_cast<float>(x) / static_cast<float>(dstWidth) * bucketCount;
        level       = LXxCLAMP(level, 0, bucketCount - 1);

        channelLevel = channelLevels[static_cast<size_t>(level)] / maxLevel * dstHeight;

        unsigned char pixelColor[4];
        pixelColor[3] = 255;
        for (int y = dstHeight - 1; y >= 0; --y)
        {
            bool channelGreater = channelLevel > dstHeight - y;

            if (channelGreater)
            {
                unsigned channelShade = static_cast<unsigned>(channelShadeMin + static_cast<float>(dstHeight - y) / dstHeight * channelShadeRange);

                pixelColor[0] = static_cast<unsigned char>(backShadeMin);
                pixelColor[1] = static_cast<unsigned char>(backShadeMin);
                pixelColor[2] = static_cast<unsigned char>(backShadeMin);

                pixelColor[channel - HISTOGRAM_RED] = static_cast<unsigned char>(channelShade);
            }
            else
            {
                // empty space
                unsigned backShade = static_cast<unsigned>(backShadeMin + static_cast<float>(dstHeight - y) / dstHeight * backShadeRange);

                pixelColor[0] = static_cast<unsigned char>(backShade);
                pixelColor[1] = static_cast<unsigned char>(backShade);
                pixelColor[2] = static_cast<unsigned char>(backShade);
            }

            writeImage.SetPixel(x + legendThumbInset + MARGIN_SIZE, y + MARGIN_SIZE, LXiIMP_RGBA32, pixelColor);
        }
    }
    histogramDrawn = true;

    return histogramDrawn;
}

bool CHistogramMonitor::DrawParade(CLxUser_ImageWrite& writeImage, int dstWidth, int dstHeight)
{
    bool histogramDrawn = false;
    int  srcWidth, srcHeight;
    srcWidth  = cachedImage.Width();
    srcHeight = cachedImage.Height();

    redLevels.clear();
    greenLevels.clear();
    blueLevels.clear();

    unsigned bucketIndex, bucketCount = levelResolution;
    for (bucketIndex = 0; bucketIndex < bucketCount; ++bucketIndex)
    {
        redLevels.push_back(0);
        greenLevels.push_back(0);
        blueLevels.push_back(0);
    }

    pixelCount = 0;

    float redLevel, greenLevel, blueLevel;
    float rangeMin = RangeMin(), rangeMax = RangeMax();
    float channelRange = rangeMax - rangeMin;
    for (unsigned srcY = 0; srcY < srcHeight; ++srcY)
    {
        for (unsigned srcX = 0; srcX < srcWidth; ++srcX)
        {
            float fpPixel[4];
            float red, green, blue;

            cachedImage.GetPixel(srcX, srcY, cachedImage.Format(), fpPixel);

            red = fpPixel[0];
            if (red >= rangeMin && red <= rangeMax)
            {
                redLevel = (red - rangeMin) / channelRange * bucketCount;
                redLevel = LXxCLAMP(redLevel, 0, bucketCount - 1);
                redLevels[static_cast<size_t>(redLevel)] += 1;
            }

            green = fpPixel[1];
            if (green >= rangeMin && green <= rangeMax)
            {
                greenLevel = (green - rangeMin) / channelRange * bucketCount;
                greenLevel = LXxCLAMP(greenLevel, 0, bucketCount - 1);
                greenLevels[static_cast<size_t>(greenLevel)] += 1;
            }

            blue = fpPixel[2];
            if (blue >= rangeMin && blue <= rangeMax)
            {
                blueLevel = (blue - rangeMin) / channelRange * bucketCount;
                blueLevel = LXxCLAMP(blueLevel, 0, bucketCount - 1);
                blueLevels[static_cast<size_t>(blueLevel)] += 1;
            }

            ++pixelCount;
        }
    }

    unsigned maxRedLevel = 0, maxGreenLevel = 0, maxBlueLevel = 0;
    for (bucketIndex = 0; bucketIndex < bucketCount; ++bucketIndex)
    {
        if (redLevels[bucketIndex] > maxRedLevel)
        {
            maxRedLevel = static_cast<unsigned>(redLevels[bucketIndex]);
        }

        if (greenLevels[bucketIndex] > maxGreenLevel)
        {
            maxGreenLevel = static_cast<unsigned>(greenLevels[bucketIndex]);
        }

        if (blueLevels[bucketIndex] > maxBlueLevel)
        {
            maxBlueLevel = static_cast<unsigned>(blueLevels[bucketIndex]);
        }
    }

    unsigned maxLevel = LXxMAX(maxRedLevel, maxGreenLevel);
    maxLevel          = LXxMAX(maxLevel, maxBlueLevel);

    const float backShadeMin   = 32;
    const float backShadeMax   = 92;
    const float backShadeRange = backShadeMax - backShadeMin;

    const float levelMinorShadeMin   = 50;
    const float levelMinorShadeMax   = 128;
    const float levelMinorShadeRange = levelMinorShadeMax - levelMinorShadeMin;

    const float levelMajorShadeMin   = 128;
    const float levelMajorShadeMax   = 255;
    const float levelMajorShadeRange = levelMajorShadeMax - levelMajorShadeMin;

    /*
     * [TODO] Resample from the bucketResolution down to the parade
     *	  resolution, to avoid missing spikes by undersampling.
     */

    m_paradeWidth = (dstWidth - paradeInset * 4) / 3;
    for (unsigned x = 0; x < m_paradeWidth; ++x)
    {
        float level = static_cast<float>(x) / static_cast<float>(m_paradeWidth) * bucketCount;
        level       = LXxCLAMP(level, 0, bucketCount - 1);
        // [TODO] Provide option for individual channel normalization.
        size_t levId = static_cast<size_t>(level);
        redLevel     = redLevels[levId] / maxLevel * dstHeight;
        greenLevel   = greenLevels[levId] / maxLevel * dstHeight;
        blueLevel    = blueLevels[levId] / maxLevel * dstHeight;

        unsigned char pixelColor[4];
        pixelColor[3] = 255;
        for (int y = dstHeight - 1; y >= 0; --y)
        {
            bool redGreater   = redLevel > dstHeight - y;
            bool greenGreater = greenLevel > dstHeight - y;
            bool blueGreater  = blueLevel > dstHeight - y;

            // empty space
            unsigned backShade = static_cast<unsigned>(backShadeMin + static_cast<float>(dstHeight - y) / dstHeight * backShadeRange);

            unsigned levelMajorShade =
            static_cast<unsigned>(levelMajorShadeMin + static_cast<float>(dstHeight - y) / dstHeight * levelMajorShadeRange);

            unsigned levelMinorShade =
            static_cast<unsigned>(levelMinorShadeMin + static_cast<float>(dstHeight - y) / dstHeight * levelMinorShadeRange);

            if (!redGreater)
            {
                pixelColor[0] = static_cast<unsigned char>(backShade);
                pixelColor[1] = static_cast<unsigned char>(backShade);
                pixelColor[2] = static_cast<unsigned char>(backShade);
            }
            else
            {
                pixelColor[0] = static_cast<unsigned char>(levelMajorShade);
                pixelColor[1] = static_cast<unsigned char>(levelMinorShade);
                pixelColor[2] = static_cast<unsigned char>(levelMinorShade);
            }
            writeImage.SetPixel(x + legendThumbInset + MARGIN_SIZE, y + MARGIN_SIZE, LXiIMP_RGBA32, pixelColor);

            if (!greenGreater)
            {
                pixelColor[0] = static_cast<unsigned char>(backShade);
                pixelColor[1] = static_cast<unsigned char>(backShade);
                pixelColor[2] = static_cast<unsigned char>(backShade);
            }
            else
            {
                pixelColor[0] = static_cast<unsigned char>(levelMinorShade);
                pixelColor[1] = static_cast<unsigned char>(levelMajorShade);
                pixelColor[2] = static_cast<unsigned char>(levelMinorShade);
            }
            writeImage.SetPixel(x + legendThumbInset + MARGIN_SIZE + m_paradeWidth + paradeInset * 2, y + MARGIN_SIZE, LXiIMP_RGBA32, pixelColor);

            if (!blueGreater)
            {
                pixelColor[0] = static_cast<unsigned char>(backShade);
                pixelColor[1] = static_cast<unsigned char>(backShade);
                pixelColor[2] = static_cast<unsigned char>(backShade);
            }
            else
            {
                pixelColor[0] = static_cast<unsigned char>(levelMinorShade);
                pixelColor[1] = static_cast<unsigned char>(levelMinorShade);
                pixelColor[2] = static_cast<unsigned char>(levelMajorShade);
            }
            writeImage.SetPixel(x + legendThumbInset + MARGIN_SIZE + m_paradeWidth * 2 + paradeInset * 4, y + MARGIN_SIZE, LXiIMP_RGBA32, pixelColor);
        }
    }
    histogramDrawn = true;

    return histogramDrawn;
}

void CHistogramMonitor::DrawEmptyBackground(CLxUser_ImageWrite& writeImage, int dstWidth, int dstHeight)
{
    const float emptyShadeMin   = 50;
    const float emptyShadeMax   = 128;
    const float emptyShadeRange = emptyShadeMax - emptyShadeMin;

    unsigned char pixelColor[4];
    pixelColor[3] = 255;
    for (unsigned y = 0; y < dstHeight; ++y)
    {
        for (unsigned x = 0; x < dstWidth; ++x)
        {
            unsigned emptyShade = static_cast<unsigned>(emptyShadeMin + static_cast<float>(dstHeight - y) / dstHeight * emptyShadeRange);
            pixelColor[0]       = static_cast<unsigned char>(emptyShade);
            pixelColor[1]       = static_cast<unsigned char>(emptyShade);
            pixelColor[2]       = static_cast<unsigned char>(emptyShade + 10);
            writeImage.SetPixel(x + legendThumbInset + MARGIN_SIZE, y + MARGIN_SIZE, LXiIMP_RGBA32, pixelColor);
        }
    }
}

void CHistogramMonitor::DrawBorder(CLxUser_ImageWrite& writeImage, int dstWidth, int dstHeight)
{
    unsigned char darkPixelColor[4]  = { 0, 0, 0, 128 };
    unsigned char lightPixelColor[4] = { 255, 255, 255, 160 };

    if (DisplayMode() == DISPLAY_RGBPARADE)
    {
        unsigned char orangeColor[4]     = { 244, 156, 28, 255 };
        unsigned char darkOrangeColor[4] = { 170, 126, 62, 255 };

        m_paradeWidth = (dstWidth - paradeInset * 4) / 3;

        unsigned char *borderDarkRed{}, *borderLightRed{};
        unsigned char *borderDarkGreen{}, *borderLightGreen{};
        unsigned char *borderDarkBlue{}, *borderLightBlue{};

        switch (ParadeChannelMode())
        {
            case PARADE_RED:
                borderDarkRed  = darkOrangeColor;
                borderLightRed = orangeColor;

                borderDarkGreen  = darkPixelColor;
                borderLightGreen = lightPixelColor;

                borderDarkBlue  = darkPixelColor;
                borderLightBlue = lightPixelColor;
                break;

            case PARADE_GREEN:
                borderDarkRed  = darkPixelColor;
                borderLightRed = lightPixelColor;

                borderDarkGreen  = darkOrangeColor;
                borderLightGreen = orangeColor;

                borderDarkBlue  = darkPixelColor;
                borderLightBlue = lightPixelColor;
                break;

            case PARADE_BLUE:
                borderDarkRed  = darkPixelColor;
                borderLightRed = lightPixelColor;

                borderDarkGreen  = darkPixelColor;
                borderLightGreen = lightPixelColor;

                borderDarkBlue  = darkOrangeColor;
                borderLightBlue = orangeColor;
                break;
        }

        for (int my = 0; my < dstHeight + TOTAL_MARGIN; ++my)
        {
            writeImage.SetPixel(legendThumbInset, my, LXiIMP_RGBA32, borderDarkRed);
            writeImage.SetPixel(m_paradeWidth + legendThumbInset + MARGIN_SIZE, my, LXiIMP_RGBA32, borderLightRed);

            writeImage.SetPixel(m_paradeWidth + legendThumbInset + paradeInset * 2, my, LXiIMP_RGBA32, borderDarkGreen);
            writeImage.SetPixel(m_paradeWidth * 2 + legendThumbInset + MARGIN_SIZE + paradeInset * 2, my, LXiIMP_RGBA32, borderLightGreen);

            writeImage.SetPixel(m_paradeWidth * 2 + legendThumbInset + paradeInset * 4, my, LXiIMP_RGBA32, borderDarkBlue);
            writeImage.SetPixel(m_paradeWidth * 3 + legendThumbInset + MARGIN_SIZE + paradeInset * 4, my, LXiIMP_RGBA32, borderLightBlue);
        }

        for (int mx = 0; mx < m_paradeWidth + TOTAL_MARGIN; ++mx)
        {
            writeImage.SetPixel(mx + legendThumbInset, 0, LXiIMP_RGBA32, borderDarkRed);
            writeImage.SetPixel(mx + legendThumbInset, dstHeight + MARGIN_SIZE, LXiIMP_RGBA32, borderLightRed);

            writeImage.SetPixel(mx + m_paradeWidth + legendThumbInset + paradeInset * 2, 0, LXiIMP_RGBA32, borderDarkGreen);
            writeImage.SetPixel(mx + m_paradeWidth + legendThumbInset + paradeInset * 2, dstHeight + MARGIN_SIZE, LXiIMP_RGBA32, borderLightGreen);

            writeImage.SetPixel(mx + m_paradeWidth * 2 + legendThumbInset + paradeInset * 4, 0, LXiIMP_RGBA32, borderDarkBlue);
            writeImage.SetPixel(mx + m_paradeWidth * 2 + legendThumbInset + paradeInset * 4, dstHeight + MARGIN_SIZE, LXiIMP_RGBA32, borderLightBlue);
        }
    }
    else
    {
        for (int my = 0; my < dstHeight + TOTAL_MARGIN; ++my)
        {
            writeImage.SetPixel(legendThumbInset, my, LXiIMP_RGBA32, darkPixelColor);
            writeImage.SetPixel(dstWidth + legendThumbInset + MARGIN_SIZE, my, LXiIMP_RGBA32, lightPixelColor);
        }

        for (int mx = 0; mx < dstWidth + TOTAL_MARGIN; ++mx)
        {
            writeImage.SetPixel(mx + legendThumbInset, 0, LXiIMP_RGBA32, darkPixelColor);
            writeImage.SetPixel(mx + legendThumbInset, dstHeight + MARGIN_SIZE, LXiIMP_RGBA32, lightPixelColor);
        }
    }
}

void CHistogramMonitor::DrawLegend(CLxUser_ImageWrite& writeImage, int dstWidth, int dstHeight, bool enabled)
{
    unsigned char legendColor[4];
    legendColor[3] = enabled ? 255 : 92;

    unsigned char emptyColor[4];
    LXx_V4ZERO(emptyColor);

    int displayMode = DisplayMode();

    int channelMode = HistogramChannelMode();
    if (!enabled)
    {
        channelMode = HISTOGRAM_LUMINOSITY;
    }

    /*
     * Adjust for the min and max range.
     */
    float rangeMin = RangeMin(), rangeMax = RangeMax();
    float valueRange = rangeMax - rangeMin;
    int   top, bottom;

    top    = dstHeight + TOTAL_MARGIN;
    bottom = dstHeight + legendHeight + MARGIN_SIZE - legendThumbOffset;

    if (displayMode == DISPLAY_RGBPARADE)
    {
        m_paradeWidth = (dstWidth - paradeInset * 4) / 3;
        for (int x = 0; x < m_paradeWidth; ++x)
        {
            float legendLevel = (rangeMin + (static_cast<float>(x) / m_paradeWidth) * valueRange) * 255.0f;

            legendLevel               = LXxCLAMP(legendLevel, 0, 255.0f);
            unsigned char legendShade = static_cast<unsigned char>(legendLevel);

            for (int y = top; y < bottom; ++y)
            {
                legendColor[0] = legendShade;
                legendColor[1] = 0;
                legendColor[2] = 0;

                writeImage.SetPixel(x + legendThumbInset + MARGIN_SIZE, y + MARGIN_SIZE, LXiIMP_RGBA32, legendColor);

                legendColor[0] = 0;
                legendColor[1] = legendShade;
                legendColor[2] = 0;

                writeImage.SetPixel(x + legendThumbInset + MARGIN_SIZE + m_paradeWidth + paradeInset * 2, y + MARGIN_SIZE, LXiIMP_RGBA32, legendColor);

                legendColor[0] = 0;
                legendColor[1] = 0;
                legendColor[2] = legendShade;

                writeImage.SetPixel(x + legendThumbInset + MARGIN_SIZE + m_paradeWidth * 2 + paradeInset * 4,
                                    y + MARGIN_SIZE,
                                    LXiIMP_RGBA32,
                                    legendColor);
            }

            writeImage.SetPixel(x + legendThumbInset + MARGIN_SIZE, dstHeight + TOTAL_MARGIN, LXiIMP_RGBA32, emptyColor);

            writeImage.SetPixel(x + legendThumbInset + MARGIN_SIZE + m_paradeWidth + paradeInset * 2,
                                dstHeight + TOTAL_MARGIN,
                                LXiIMP_RGBA32,
                                emptyColor);

            writeImage.SetPixel(x + legendThumbInset + MARGIN_SIZE + m_paradeWidth * 2 + paradeInset * 4,
                                dstHeight + TOTAL_MARGIN,
                                LXiIMP_RGBA32,
                                emptyColor);
        }
    }
    else
        for (int x = 0; x < dstWidth; ++x)
        {
            float legendLevel = (rangeMin + (static_cast<float>(x) / dstWidth) * valueRange) * 255.0f;

            legendLevel               = LXxCLAMP(legendLevel, 0, 255.0f);
            unsigned char legendShade = static_cast<unsigned char>(legendLevel);

            int height = bottom - top;
            for (int y = top; y < bottom; ++y)
            {
                switch (channelMode)
                {
                    case HISTOGRAM_COLORS:
                    case HISTOGRAM_RGB:
                        legendColor[0] = 0;
                        legendColor[1] = 0;
                        legendColor[2] = 0;

                        if (y <= top + height / 3)
                        {
                            legendColor[0] = legendShade;
                        }
                        else if (y <= top + height / 3 * 2)
                        {
                            legendColor[1] = legendShade;
                        }
                        else
                        {
                            legendColor[2] = legendShade;
                        }
                        break;

                    case HISTOGRAM_LUMINOSITY:
                        legendColor[0] = legendShade;
                        legendColor[1] = legendShade;
                        legendColor[2] = legendShade;
                        break;

                    case HISTOGRAM_RED:
                    case HISTOGRAM_GREEN:
                    case HISTOGRAM_BLUE:
                        legendColor[0] = 0;
                        legendColor[1] = 0;
                        legendColor[2] = 0;

                        legendColor[channelMode - HISTOGRAM_RED] = legendShade;
                        break;
                }

                writeImage.SetPixel(x + legendThumbInset + MARGIN_SIZE, y + MARGIN_SIZE, LXiIMP_RGBA32, legendColor);
            }

            writeImage.SetPixel(x + legendThumbInset + MARGIN_SIZE, dstHeight + TOTAL_MARGIN, LXiIMP_RGBA32, emptyColor);
        }

    /* Fill in the empty spots. */
    for (int y = dstHeight + 1; y < dstHeight + legendHeight + TOTAL_MARGIN; ++y)
    {
        writeImage.SetPixel(legendThumbInset, y, LXiIMP_RGBA32, emptyColor);

        writeImage.SetPixel(dstWidth + legendThumbInset + MARGIN_SIZE, y, LXiIMP_RGBA32, emptyColor);
    }

    for (int x = 0; x < dstWidth + MARGIN_SIZE; ++x)
    {
        for (int y = 0; y <= legendThumbOffset; ++y)
        {
            writeImage.SetPixel(x + legendThumbInset, bottom + y, LXiIMP_RGBA32, emptyColor);
        }
    }

    for (int y = 0; y < dstHeight + legendHeight + TOTAL_MARGIN; ++y)
    {
        for (int x = 0; x < legendThumbInset; ++x)
        {
            writeImage.SetPixel(x, y, LXiIMP_RGBA32, emptyColor);

            writeImage.SetPixel(x + legendThumbInset + dstWidth, y, LXiIMP_RGBA32, emptyColor);

            if (displayMode == DISPLAY_RGBPARADE)
            {
                writeImage.SetPixel(x + legendThumbInset + m_paradeWidth + 1, y, LXiIMP_RGBA32, emptyColor);
                writeImage.SetPixel(x + legendThumbInset + m_paradeWidth + 1 + paradeInset, y, LXiIMP_RGBA32, emptyColor);

                writeImage.SetPixel(x + legendThumbInset + m_paradeWidth * 2 + paradeInset * 2 + 2, y, LXiIMP_RGBA32, emptyColor);
                writeImage.SetPixel(x + legendThumbInset + m_paradeWidth * 2 + paradeInset * 3 + 2, y, LXiIMP_RGBA32, emptyColor);
            }
        }

        writeImage.SetPixel(legendThumbInset * 2 + dstWidth, y, LXiIMP_RGBA32, emptyColor);

        writeImage.SetPixel(legendThumbInset * 2 + dstWidth + 1, y, LXiIMP_RGBA32, emptyColor);
    }

    if (imageProcessing.test())
    {
        /* Draw the Output Level thumbs. */
        CLxUser_ImageService imageSvc;
        CLxUser_Image        dstImage;

        dstImage.set(writeImage);

        if (displayMode == DISPLAY_RGBPARADE)
        {
            // Red
            LXtFVector2 minRedPoint;
            if (MarkerPoint(Marker_MinRedPoint, minRedPoint))
            {
                imageSvc.Composite(dstImage, outputBlackLevel_marker16, minRedPoint);
            }

            LXtFVector2 maxRedPoint;
            if (MarkerPoint(Marker_MaxRedPoint, maxRedPoint))
            {
                imageSvc.Composite(dstImage, outputWhiteLevel_marker16, maxRedPoint);
            }

            // Green
            LXtFVector2 minGreenPoint;
            if (MarkerPoint(Marker_MinGreenPoint, minGreenPoint))
            {
                imageSvc.Composite(dstImage, outputBlackLevel_marker16, minGreenPoint);
            }

            LXtFVector2 maxGreenPoint;
            if (MarkerPoint(Marker_MaxGreenPoint, maxGreenPoint))
            {
                imageSvc.Composite(dstImage, outputWhiteLevel_marker16, maxGreenPoint);
            }

            // Blue
            LXtFVector2 minBluePoint;
            if (MarkerPoint(Marker_MinBluePoint, minBluePoint))
            {
                imageSvc.Composite(dstImage, outputBlackLevel_marker16, minBluePoint);
            }

            LXtFVector2 maxBluePoint;
            if (MarkerPoint(Marker_MaxBluePoint, maxBluePoint))
            {
                imageSvc.Composite(dstImage, outputWhiteLevel_marker16, maxBluePoint);
            }
        }
        else
            switch (channelMode)
            {
                case HISTOGRAM_RED:
                {
                    LXtFVector2 minRedPoint;
                    if (MarkerPoint(Marker_MinRedPoint, minRedPoint))
                    {
                        imageSvc.Composite(dstImage, outputBlackLevel_marker16, minRedPoint);
                    }

                    LXtFVector2 maxRedPoint;
                    if (MarkerPoint(Marker_MaxRedPoint, maxRedPoint))
                    {
                        imageSvc.Composite(dstImage, outputWhiteLevel_marker16, maxRedPoint);
                    }
                    break;
                }

                case HISTOGRAM_GREEN:
                {
                    LXtFVector2 minGreenPoint;
                    if (MarkerPoint(Marker_MinGreenPoint, minGreenPoint))
                    {
                        imageSvc.Composite(dstImage, outputBlackLevel_marker16, minGreenPoint);
                    }

                    LXtFVector2 maxGreenPoint;
                    if (MarkerPoint(Marker_MaxGreenPoint, maxGreenPoint))
                    {
                        imageSvc.Composite(dstImage, outputWhiteLevel_marker16, maxGreenPoint);
                    }
                    break;
                }

                case HISTOGRAM_BLUE:
                {
                    LXtFVector2 minBluePoint;
                    if (MarkerPoint(Marker_MinBluePoint, minBluePoint))
                    {
                        imageSvc.Composite(dstImage, outputBlackLevel_marker16, minBluePoint);
                    }

                    LXtFVector2 maxBluePoint;
                    if (MarkerPoint(Marker_MaxBluePoint, maxBluePoint))
                    {
                        imageSvc.Composite(dstImage, outputWhiteLevel_marker16, maxBluePoint);
                    }
                    break;
                }

                default:
                {
                    LXtFVector2 blackPoint;
                    if (MarkerPoint(Marker_BlackPoint, blackPoint))
                    {
                        imageSvc.Composite(dstImage, outputBlackLevel_marker16, blackPoint);
                    }

                    LXtFVector2 whitePoint;
                    if (MarkerPoint(Marker_WhitePoint, whitePoint))
                    {
                        imageSvc.Composite(dstImage, outputWhiteLevel_marker16, whitePoint);
                    }
                    break;
                }
            }
    }
}

bool CHistogramMonitor::MarkerPoint(MarkerType markerType, LXtFVector2& point)
{
    int top = m_dstHeight + TOTAL_MARGIN;

    int blackMarkerWidth = outputBlackLevel_marker16.Width();
    int whiteMarkerWidth = outputWhiteLevel_marker16.Width();

    int displayMode = DisplayMode();

    float leftPoint = static_cast<float>(MARGIN_SIZE + legendThumbInset - (blackMarkerWidth / 2));

    float rightPoint;
    if (displayMode == DISPLAY_RGBPARADE)
    {
        rightPoint = static_cast<float>(m_paradeWidth - (whiteMarkerWidth / 2) + legendThumbInset);
    }
    else
    {
        rightPoint = static_cast<float>(m_dstWidth - (whiteMarkerWidth / 2) + legendThumbInset);
    }

    float pixelRange    = rightPoint - leftPoint;
    float rangeMin      = RangeMin();
    float rangeMax      = RangeMax();
    float displayRange  = rangeMax - rangeMin;
    float pixelsPerUnit = pixelRange / displayRange;
    float channelOffset = 0;

    float zeroPoint = leftPoint - rangeMin * pixelsPerUnit;

    switch (markerType)
    {
        case Marker_BlackPoint:
        {
            double blackLevel;
            imageProcessing.GetOutputBlackLevel(&blackLevel);
            point[0] = static_cast<float>(zeroPoint + blackLevel * pixelsPerUnit);
            break;
        }

        case Marker_WhitePoint:
        {
            double whiteLevel;
            imageProcessing.GetOutputWhiteLevel(&whiteLevel);
            point[0] = static_cast<float>(zeroPoint + whiteLevel * pixelsPerUnit);
            break;
        }

        case Marker_MinRedPoint:
        {
            double minRedLevel;
            imageProcessing.GetOutputMinRedLevel(&minRedLevel);
            point[0] = static_cast<float>(zeroPoint + minRedLevel * pixelsPerUnit);
            break;
        }

        case Marker_MaxRedPoint:
        {
            double maxRedLevel;
            imageProcessing.GetOutputMaxRedLevel(&maxRedLevel);
            point[0] = static_cast<float>(zeroPoint + maxRedLevel * pixelsPerUnit);
            break;
        }

        case Marker_MinGreenPoint:
        {
            double minGreenLevel;
            imageProcessing.GetOutputMinGreenLevel(&minGreenLevel);
            if (displayMode == DISPLAY_RGBPARADE)
            {
                channelOffset = m_paradeWidth + paradeInset * 2.f;
                leftPoint += channelOffset;
                rightPoint += channelOffset;
                zeroPoint += channelOffset;
            }

            point[0] = static_cast<float>(zeroPoint + minGreenLevel * pixelsPerUnit);
            break;
        }

        case Marker_MaxGreenPoint:
        {
            double maxGreenLevel;
            imageProcessing.GetOutputMaxGreenLevel(&maxGreenLevel);
            if (displayMode == DISPLAY_RGBPARADE)
            {
                channelOffset = m_paradeWidth + paradeInset * 2.f;
                leftPoint += channelOffset;
                rightPoint += channelOffset;
                zeroPoint += channelOffset;
            }
            point[0] = static_cast<float>(zeroPoint + maxGreenLevel * pixelsPerUnit);
            break;
        }

        case Marker_MinBluePoint:
        {
            double minBlueLevel;
            imageProcessing.GetOutputMinBlueLevel(&minBlueLevel);
            if (displayMode == DISPLAY_RGBPARADE)
            {
                channelOffset = m_paradeWidth * 2.f + paradeInset * 4.f;
                leftPoint += channelOffset;
                rightPoint += channelOffset;
                zeroPoint += channelOffset;
            }
            point[0] = static_cast<float>(zeroPoint + minBlueLevel * pixelsPerUnit);
            break;
        }

        case Marker_MaxBluePoint:
        {
            double maxBlueLevel;
            imageProcessing.GetOutputMaxBlueLevel(&maxBlueLevel);
            if (displayMode == DISPLAY_RGBPARADE)
            {
                channelOffset = m_paradeWidth * 2.f + paradeInset * 4.f;
                leftPoint += channelOffset;
                rightPoint += channelOffset;
                zeroPoint += channelOffset;
            }
            point[0] = static_cast<float>(zeroPoint + maxBlueLevel * pixelsPerUnit);
            break;
        }

        default:
            break;
    }

    point[1] = static_cast<float>(top);

    return (point[0] >= leftPoint) && (point[0] <= rightPoint);
}

/*
 * Convert an offset in pixels (from the left edge of the image monitor viewport)
 * into a level value.
 */
float CHistogramMonitor::OffsetToValue(float offset, int movingMarker)
{
    int blackMarkerWidth = outputBlackLevel_marker16.Width();
    int whiteMarkerWidth = outputWhiteLevel_marker16.Width();

    int displayMode = DisplayMode();

    float leftPoint{};
    if (displayMode == DISPLAY_RGBPARADE)
    {
        switch (movingMarker)
        {
            case Marker_MinRedPoint:
            case Marker_MaxRedPoint:
                leftPoint = static_cast<float>(MARGIN_SIZE + legendThumbInset - (blackMarkerWidth / 2));
                break;

            case Marker_MinGreenPoint:
            case Marker_MaxGreenPoint:
                leftPoint = static_cast<float>(MARGIN_SIZE + legendThumbInset + m_paradeWidth + paradeInset * 2 - (blackMarkerWidth / 2));
                break;

            case Marker_MinBluePoint:
            case Marker_MaxBluePoint:
                leftPoint = static_cast<float>(MARGIN_SIZE + legendThumbInset + m_paradeWidth * 2 + paradeInset * 4 - (blackMarkerWidth / 2));
                break;
        }
    }
    else
    {
        leftPoint = static_cast<float>(MARGIN_SIZE + legendThumbInset - (blackMarkerWidth / 2));
    }

    float rightPoint{};
    if (displayMode == DISPLAY_RGBPARADE)
    {
        switch (movingMarker)
        {
            case Marker_MinRedPoint:
            case Marker_MaxRedPoint:
                rightPoint = static_cast<float>(m_paradeWidth - (whiteMarkerWidth / 2) + legendThumbInset);
                break;

            case Marker_MinGreenPoint:
            case Marker_MaxGreenPoint:
                rightPoint = static_cast<float>(m_paradeWidth * 2 + paradeInset * 2 - (whiteMarkerWidth / 2) + legendThumbInset);
                break;

            case Marker_MinBluePoint:
            case Marker_MaxBluePoint:
                rightPoint = static_cast<float>(m_paradeWidth * 3 + paradeInset * 4 - (whiteMarkerWidth / 2) + legendThumbInset);
                break;
        }
    }
    else
    {
        rightPoint = static_cast<float>(m_dstWidth - (whiteMarkerWidth / 2) + legendThumbInset);
    }

    float rangeMin = RangeMin();
    float rangeMax = RangeMax();
    float value;
    if (offset < leftPoint)
    {
        value = rangeMin;
    }
    else if (offset > rightPoint)
    {
        value = rangeMax;
    }
    else
    {
        float pixelRange = rightPoint - leftPoint;

        float displayRange  = rangeMax - rangeMin;
        float unitsPerPixel = displayRange / pixelRange;

        value = rangeMin + (offset - leftPoint) * unitsPerPixel;
    }

    return value;
}

/*
 * Return whether or not the given point is hit by the given x, y coordinates,
 * using the given marker dimensions.
 */
static bool HitPoint(int x, int y, const LXtFVector2& point, int markerWidth, int markerHeight)
{
    bool hit = ((x > point[0]) && (x < (point[0] + markerWidth)) && (y > point[1]) && (y < (point[1] + markerHeight)));

    return hit;
}

CHistogramMonitor::MarkerType CHistogramMonitor::HitMarker(int x, int y)
{
    MarkerType markerType = Marker_None;

    int displayMode = DisplayMode();
    if (displayMode == DISPLAY_RGBPARADE)
    {
        LXtFVector2 minRedPoint;
        if (MarkerPoint(Marker_MinRedPoint, minRedPoint))
        {
            int blackMarkerWidth  = outputBlackLevel_marker16.Width();
            int blackMarkerHeight = outputBlackLevel_marker16.Height();
            if (HitPoint(x, y, minRedPoint, blackMarkerWidth, blackMarkerHeight))
            {
                markerType = Marker_MinRedPoint;
            }
        }

        if (markerType == Marker_None)
        {
            LXtFVector2 maxRedPoint;
            if (MarkerPoint(Marker_MaxRedPoint, maxRedPoint))
            {
                int whiteMarkerWidth  = outputWhiteLevel_marker16.Width();
                int whiteMarkerHeight = outputWhiteLevel_marker16.Height();
                if (HitPoint(x, y, maxRedPoint, whiteMarkerWidth, whiteMarkerHeight))
                {
                    markerType = Marker_MaxRedPoint;
                }
            }
        }

        if (markerType == Marker_None)
        {
            LXtFVector2 minGreenPoint;
            if (MarkerPoint(Marker_MinGreenPoint, minGreenPoint))
            {
                int blackMarkerWidth  = outputBlackLevel_marker16.Width();
                int blackMarkerHeight = outputBlackLevel_marker16.Height();
                if (HitPoint(x, y, minGreenPoint, blackMarkerWidth, blackMarkerHeight))
                {
                    markerType = Marker_MinGreenPoint;
                }
            }
        }

        if (markerType == Marker_None)
        {
            LXtFVector2 maxGreenPoint;
            if (MarkerPoint(Marker_MaxGreenPoint, maxGreenPoint))
            {
                int whiteMarkerWidth  = outputWhiteLevel_marker16.Width();
                int whiteMarkerHeight = outputWhiteLevel_marker16.Height();
                if (HitPoint(x, y, maxGreenPoint, whiteMarkerWidth, whiteMarkerHeight))
                {
                    markerType = Marker_MaxGreenPoint;
                }
            }
        }

        if (markerType == Marker_None)
        {
            LXtFVector2 minBluePoint;
            if (MarkerPoint(Marker_MinBluePoint, minBluePoint))
            {
                int blackMarkerWidth  = outputBlackLevel_marker16.Width();
                int blackMarkerHeight = outputBlackLevel_marker16.Height();
                if (HitPoint(x, y, minBluePoint, blackMarkerWidth, blackMarkerHeight))
                {
                    markerType = Marker_MinBluePoint;
                }
            }
        }

        if (markerType == Marker_None)
        {
            LXtFVector2 maxBluePoint;
            if (MarkerPoint(Marker_MaxBluePoint, maxBluePoint))
            {
                int whiteMarkerWidth  = outputWhiteLevel_marker16.Width();
                int whiteMarkerHeight = outputWhiteLevel_marker16.Height();
                if (HitPoint(x, y, maxBluePoint, whiteMarkerWidth, whiteMarkerHeight))
                {
                    markerType = Marker_MaxBluePoint;
                }
            }
        }
    }
    else
        switch (HistogramChannelMode())
        {
            case HISTOGRAM_RED:
            {
                LXtFVector2 minRedPoint;
                if (MarkerPoint(Marker_MinRedPoint, minRedPoint))
                {
                    int blackMarkerWidth  = outputBlackLevel_marker16.Width();
                    int blackMarkerHeight = outputBlackLevel_marker16.Height();
                    if (HitPoint(x, y, minRedPoint, blackMarkerWidth, blackMarkerHeight))
                    {
                        markerType = Marker_MinRedPoint;
                    }
                }

                if (markerType == Marker_None)
                {
                    LXtFVector2 maxRedPoint;
                    if (MarkerPoint(Marker_MaxRedPoint, maxRedPoint))
                    {
                        int whiteMarkerWidth  = outputWhiteLevel_marker16.Width();
                        int whiteMarkerHeight = outputWhiteLevel_marker16.Height();
                        if (HitPoint(x, y, maxRedPoint, whiteMarkerWidth, whiteMarkerHeight))
                        {
                            markerType = Marker_MaxRedPoint;
                        }
                    }
                }
                break;
            }

            case HISTOGRAM_GREEN:
            {
                LXtFVector2 minGreenPoint;
                if (MarkerPoint(Marker_MinGreenPoint, minGreenPoint))
                {
                    int blackMarkerWidth  = outputBlackLevel_marker16.Width();
                    int blackMarkerHeight = outputBlackLevel_marker16.Height();
                    if (HitPoint(x, y, minGreenPoint, blackMarkerWidth, blackMarkerHeight))
                    {
                        markerType = Marker_MinGreenPoint;
                    }
                }

                if (markerType == Marker_None)
                {
                    LXtFVector2 maxGreenPoint;
                    if (MarkerPoint(Marker_MaxGreenPoint, maxGreenPoint))
                    {
                        int whiteMarkerWidth  = outputWhiteLevel_marker16.Width();
                        int whiteMarkerHeight = outputWhiteLevel_marker16.Height();
                        if (HitPoint(x, y, maxGreenPoint, whiteMarkerWidth, whiteMarkerHeight))
                        {
                            markerType = Marker_MaxGreenPoint;
                        }
                    }
                }
                break;
            }

            case HISTOGRAM_BLUE:
            {
                LXtFVector2 minBluePoint;
                if (MarkerPoint(Marker_MinBluePoint, minBluePoint))
                {
                    int blackMarkerWidth  = outputBlackLevel_marker16.Width();
                    int blackMarkerHeight = outputBlackLevel_marker16.Height();
                    if (HitPoint(x, y, minBluePoint, blackMarkerWidth, blackMarkerHeight))
                    {
                        markerType = Marker_MinBluePoint;
                    }
                }

                if (markerType == Marker_None)
                {
                    LXtFVector2 maxBluePoint;
                    if (MarkerPoint(Marker_MaxBluePoint, maxBluePoint))
                    {
                        int whiteMarkerWidth  = outputWhiteLevel_marker16.Width();
                        int whiteMarkerHeight = outputWhiteLevel_marker16.Height();
                        if (HitPoint(x, y, maxBluePoint, whiteMarkerWidth, whiteMarkerHeight))
                        {
                            markerType = Marker_MaxBluePoint;
                        }
                    }
                }
                break;
            }

            default:
            {
                LXtFVector2 blackPoint;
                if (MarkerPoint(Marker_BlackPoint, blackPoint))
                {
                    int blackMarkerWidth  = outputBlackLevel_marker16.Width();
                    int blackMarkerHeight = outputBlackLevel_marker16.Height();
                    if (HitPoint(x, y, blackPoint, blackMarkerWidth, blackMarkerHeight))
                    {
                        markerType = Marker_BlackPoint;
                    }
                }

                if (markerType == Marker_None)
                {
                    LXtFVector2 whitePoint;
                    if (MarkerPoint(Marker_WhitePoint, whitePoint))
                    {
                        int whiteMarkerWidth  = outputWhiteLevel_marker16.Width();
                        int whiteMarkerHeight = outputWhiteLevel_marker16.Height();
                        if (HitPoint(x, y, whitePoint, whiteMarkerWidth, whiteMarkerHeight))
                        {
                            markerType = Marker_WhitePoint;
                        }
                    }
                }
            }
        }

    return markerType;
}

LxResult CHistogramMonitor::SetBlackPoint(float blackPoint)
{
    return SetOutputLevelCommand(std::string("histogramMonitor.outputBlackLevel"), blackPoint);
}

LxResult CHistogramMonitor::SetWhitePoint(float whitePoint)
{
    return SetOutputLevelCommand(std::string("histogramMonitor.outputWhiteLevel"), whitePoint);
}

LxResult CHistogramMonitor::SetMinRedPoint(float minRedPoint)
{
    return SetOutputLevelCommand(std::string("histogramMonitor.outputMinRedLevel"), minRedPoint);
}

LxResult CHistogramMonitor::SetMaxRedPoint(float maxRedPoint)
{
    return SetOutputLevelCommand(std::string("histogramMonitor.outputMaxRedLevel"), maxRedPoint);
}

LxResult CHistogramMonitor::SetMinGreenPoint(float minGreenPoint)
{
    return SetOutputLevelCommand(std::string("histogramMonitor.outputMinGreenLevel"), minGreenPoint);
}

LxResult CHistogramMonitor::SetMaxGreenPoint(float maxGreenPoint)
{
    return SetOutputLevelCommand(std::string("histogramMonitor.outputMaxGreenLevel"), maxGreenPoint);
}

LxResult CHistogramMonitor::SetMinBluePoint(float minBluePoint)
{
    return SetOutputLevelCommand(std::string("histogramMonitor.outputMinBlueLevel"), minBluePoint);
}

LxResult CHistogramMonitor::SetMaxBluePoint(float maxBluePoint)
{
    return SetOutputLevelCommand(std::string("histogramMonitor.outputMaxBlueLevel"), maxBluePoint);
}

LxResult CHistogramMonitor::SetOutputLevelCommand(const std::string& commandName, float level)
{
    LxResult result = LXe_FAILED;

    // Execute the command to set the output level on the image processing object.
    CLxUser_CommandService cmdSvc;
    CLxLoc_Command         imageProcSetLevelCmd;
    if (cmdSvc.NewCommand(imageProcSetLevelCmd, commandName.c_str()))
    {
        CLxUser_Attributes arg;
        arg.set(imageProcSetLevelCmd);

        int c0ArgIndex = arg.FindIndex("source");
        int c1ArgIndex = arg.FindIndex("level");
        if (arg.Set(c0ArgIndex, imageSource.c_str()) && arg.Set(c1ArgIndex, level))
        {
            imageProcSetLevelCmd.Execute(0);
        }

        CLxUser_ImageMonitorService imSvc;
        imSvc.RefreshViews(imageSource, true);

        result = LXe_OK;
    }

    return result;
}

/*
 * ----------------------------------------------------------------
 * Server initialization.
 */

void initialize()
{
    // Monitor server.
    LXx_ADD_SERVER(ImageMonitor, CHistogramMonitor, SERVER_HISTOGRAM_MONITOR);

    CLxGenericPolymorph* srv;

    /*
     * CDisplayModeHistogramMonitorCommand command.
     */
    srv = new CLxPolymorph<CDisplayModeHistogramMonitorCommand>;
    srv->AddInterface(new CLxIfc_Command<CDisplayModeHistogramMonitorCommand>);
    srv->AddInterface(new CLxIfc_Attributes<CDisplayModeHistogramMonitorCommand>);
    srv->AddInterface(new CLxIfc_AttributesUI<CDisplayModeHistogramMonitorCommand>);

    // Command naming convention has only one 'dot'
    thisModule.AddServer("histogramMonitor.displayMode", srv);

    /*
     * CHistogramChannelModeHistogramMonitorCommand command.
     */
    srv = new CLxPolymorph<CHistogramChannelModeHistogramMonitorCommand>;
    srv->AddInterface(new CLxIfc_Command<CHistogramChannelModeHistogramMonitorCommand>);
    srv->AddInterface(new CLxIfc_Attributes<CHistogramChannelModeHistogramMonitorCommand>);
    srv->AddInterface(new CLxIfc_AttributesUI<CHistogramChannelModeHistogramMonitorCommand>);

    // Command naming convention has only one 'dot'
    thisModule.AddServer("histogramMonitor.histogramChannelMode", srv);

    /*
     * CParadeChannelModeHistogramMonitorCommand command.
     */
    srv = new CLxPolymorph<CParadeChannelModeHistogramMonitorCommand>;
    srv->AddInterface(new CLxIfc_Command<CParadeChannelModeHistogramMonitorCommand>);
    srv->AddInterface(new CLxIfc_Attributes<CParadeChannelModeHistogramMonitorCommand>);
    srv->AddInterface(new CLxIfc_AttributesUI<CParadeChannelModeHistogramMonitorCommand>);

    // Command naming convention has only one 'dot'
    thisModule.AddServer("histogramMonitor.paradeChannelMode", srv);

    /*
     * CRangeMinHistogramMonitorCommand command.
     */
    srv = new CLxPolymorph<CRangeMinHistogramMonitorCommand>;
    srv->AddInterface(new CLxIfc_Command<CRangeMinHistogramMonitorCommand>);
    srv->AddInterface(new CLxIfc_Attributes<CRangeMinHistogramMonitorCommand>);
    srv->AddInterface(new CLxIfc_AttributesUI<CRangeMinHistogramMonitorCommand>);

    // Command naming convention has only one 'dot'
    thisModule.AddServer("histogramMonitor.rangeMin", srv);

    /*
     * CRangeMaxHistogramMonitorCommand command.
     */
    srv = new CLxPolymorph<CRangeMaxHistogramMonitorCommand>;
    srv->AddInterface(new CLxIfc_Command<CRangeMaxHistogramMonitorCommand>);
    srv->AddInterface(new CLxIfc_Attributes<CRangeMaxHistogramMonitorCommand>);
    srv->AddInterface(new CLxIfc_AttributesUI<CRangeMaxHistogramMonitorCommand>);

    // Command naming convention has only one 'dot'
    thisModule.AddServer("histogramMonitor.rangeMax", srv);

    /*
     * COutputBlackLevelHistogramMonitorCommand command.
     */
    srv = new CLxPolymorph<COutputBlackLevelHistogramMonitorCommand>;
    srv->AddInterface(new CLxIfc_Command<COutputBlackLevelHistogramMonitorCommand>);
    srv->AddInterface(new CLxIfc_Attributes<COutputBlackLevelHistogramMonitorCommand>);
    srv->AddInterface(new CLxIfc_AttributesUI<COutputBlackLevelHistogramMonitorCommand>);

    // Command naming convention has only one 'dot'
    thisModule.AddServer("histogramMonitor.outputBlackLevel", srv);

    /*
     * COutputWhiteLevelHistogramMonitorCommand command.
     */
    srv = new CLxPolymorph<COutputWhiteLevelHistogramMonitorCommand>;
    srv->AddInterface(new CLxIfc_Command<COutputWhiteLevelHistogramMonitorCommand>);
    srv->AddInterface(new CLxIfc_Attributes<COutputWhiteLevelHistogramMonitorCommand>);
    srv->AddInterface(new CLxIfc_AttributesUI<COutputWhiteLevelHistogramMonitorCommand>);

    // Command naming convention has only one 'dot'
    thisModule.AddServer("histogramMonitor.outputWhiteLevel", srv);

    /*
     * COutputMinRedLevelHistogramMonitorCommand command.
     */
    srv = new CLxPolymorph<COutputMinRedLevelHistogramMonitorCommand>;
    srv->AddInterface(new CLxIfc_Command<COutputMinRedLevelHistogramMonitorCommand>);
    srv->AddInterface(new CLxIfc_Attributes<COutputMinRedLevelHistogramMonitorCommand>);
    srv->AddInterface(new CLxIfc_AttributesUI<COutputMinRedLevelHistogramMonitorCommand>);

    // Command naming convention has only one 'dot'
    thisModule.AddServer("histogramMonitor.outputMinRedLevel", srv);

    /*
     * COutputMaxRedLevelHistogramMonitorCommand command.
     */
    srv = new CLxPolymorph<COutputMaxRedLevelHistogramMonitorCommand>;
    srv->AddInterface(new CLxIfc_Command<COutputMaxRedLevelHistogramMonitorCommand>);
    srv->AddInterface(new CLxIfc_Attributes<COutputMaxRedLevelHistogramMonitorCommand>);
    srv->AddInterface(new CLxIfc_AttributesUI<COutputMaxRedLevelHistogramMonitorCommand>);

    // Command naming convention has only one 'dot'
    thisModule.AddServer("histogramMonitor.outputMaxRedLevel", srv);

    /*
     * COutputMinGreenLevelHistogramMonitorCommand command.
     */
    srv = new CLxPolymorph<COutputMinGreenLevelHistogramMonitorCommand>;
    srv->AddInterface(new CLxIfc_Command<COutputMinGreenLevelHistogramMonitorCommand>);
    srv->AddInterface(new CLxIfc_Attributes<COutputMinGreenLevelHistogramMonitorCommand>);
    srv->AddInterface(new CLxIfc_AttributesUI<COutputMinGreenLevelHistogramMonitorCommand>);

    // Command naming convention has only one 'dot'
    thisModule.AddServer("histogramMonitor.outputMinGreenLevel", srv);

    /*
     * COutputMaxGreenLevelHistogramMonitorCommand command.
     */
    srv = new CLxPolymorph<COutputMaxGreenLevelHistogramMonitorCommand>;
    srv->AddInterface(new CLxIfc_Command<COutputMaxGreenLevelHistogramMonitorCommand>);
    srv->AddInterface(new CLxIfc_Attributes<COutputMaxGreenLevelHistogramMonitorCommand>);
    srv->AddInterface(new CLxIfc_AttributesUI<COutputMaxGreenLevelHistogramMonitorCommand>);

    // Command naming convention has only one 'dot'
    thisModule.AddServer("histogramMonitor.outputMaxGreenLevel", srv);

    /*
     * COutputMinBlueLevelHistogramMonitorCommand command.
     */
    srv = new CLxPolymorph<COutputMinBlueLevelHistogramMonitorCommand>;
    srv->AddInterface(new CLxIfc_Command<COutputMinBlueLevelHistogramMonitorCommand>);
    srv->AddInterface(new CLxIfc_Attributes<COutputMinBlueLevelHistogramMonitorCommand>);
    srv->AddInterface(new CLxIfc_AttributesUI<COutputMinBlueLevelHistogramMonitorCommand>);

    // Command naming convention has only one 'dot'
    thisModule.AddServer("histogramMonitor.outputMinBlueLevel", srv);

    /*
     * COutputMaxBlueLevelHistogramMonitorCommand command.
     */
    srv = new CLxPolymorph<COutputMaxBlueLevelHistogramMonitorCommand>;
    srv->AddInterface(new CLxIfc_Command<COutputMaxBlueLevelHistogramMonitorCommand>);
    srv->AddInterface(new CLxIfc_Attributes<COutputMaxBlueLevelHistogramMonitorCommand>);
    srv->AddInterface(new CLxIfc_AttributesUI<COutputMaxBlueLevelHistogramMonitorCommand>);

    // Command naming convention has only one 'dot'
    thisModule.AddServer("histogramMonitor.outputMaxBlueLevel", srv);

    /*
     * Notifier.
     */
    srv = new CLxPolymorph<CHistogramMonitorNotifier>;
    srv->AddInterface(new CLxIfc_Notifier<CHistogramMonitorNotifier>);
    thisModule.AddServer(HISTOGRAM_MONITOR_NOTIFIER, srv);
}

void cleanup()
{
    if (persist)
    {
        delete persist;
    }
}
