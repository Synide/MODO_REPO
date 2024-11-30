/*
 * Plug-in Histogram monitor.
 *
 * Copyright 0000
 *
 * A plug-in histogram monitor that displays the relative number
 * of pixels that occur within each color or luminosity level.
 */

#pragma once

#include <lx_image.hpp>
#include <lx_imagemon.hpp>
#include <lx_persist.hpp>
#include <lx_rndjob.hpp>
#include <lx_value.hpp>
#include <lxlog.h>
#include <lxu_command.hpp>
#include <lxu_log.hpp>

#include <string>
#include <vector>

extern const char* SERVER_HISTOGRAM_MONITOR;

class CHistogramMonitorLog : public CLxLuxologyLogMessage
{
public:
    CHistogramMonitorLog() : CLxLuxologyLogMessage(SERVER_HISTOGRAM_MONITOR)
    {
    }

    const char* GetFormat() override
    {
        return "Histogram Monitor";
    }
};

/*
 * ---------------------------------------------------------------------------
 * Commands.
 */

class CDisplayModeHistogramMonitorCommand : public CLxBasicCommand
{
public:
    CDisplayModeHistogramMonitorCommand();
    virtual ~CDisplayModeHistogramMonitorCommand()
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

class CHistogramChannelModeHistogramMonitorCommand : public CLxBasicCommand
{
public:
    CHistogramChannelModeHistogramMonitorCommand();
    virtual ~CHistogramChannelModeHistogramMonitorCommand()
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

class CParadeChannelModeHistogramMonitorCommand : public CLxBasicCommand
{
public:
    CParadeChannelModeHistogramMonitorCommand();
    virtual ~CParadeChannelModeHistogramMonitorCommand()
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

class CRangeMinHistogramMonitorCommand : public CLxBasicCommand
{
public:
    CRangeMinHistogramMonitorCommand();
    virtual ~CRangeMinHistogramMonitorCommand()
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

class CRangeMaxHistogramMonitorCommand : public CLxBasicCommand
{
public:
    CRangeMaxHistogramMonitorCommand();
    virtual ~CRangeMaxHistogramMonitorCommand()
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

class COutputBlackLevelHistogramMonitorCommand : public CLxBasicCommand
{
public:
    COutputBlackLevelHistogramMonitorCommand();
    virtual ~COutputBlackLevelHistogramMonitorCommand()
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

class COutputWhiteLevelHistogramMonitorCommand : public CLxBasicCommand
{
public:
    COutputWhiteLevelHistogramMonitorCommand();
    virtual ~COutputWhiteLevelHistogramMonitorCommand()
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

class COutputMinRedLevelHistogramMonitorCommand : public CLxBasicCommand
{
public:
    COutputMinRedLevelHistogramMonitorCommand();
    virtual ~COutputMinRedLevelHistogramMonitorCommand()
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

class COutputMaxRedLevelHistogramMonitorCommand : public CLxBasicCommand
{
public:
    COutputMaxRedLevelHistogramMonitorCommand();
    virtual ~COutputMaxRedLevelHistogramMonitorCommand()
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

class COutputMinGreenLevelHistogramMonitorCommand : public CLxBasicCommand
{
public:
    COutputMinGreenLevelHistogramMonitorCommand();
    virtual ~COutputMinGreenLevelHistogramMonitorCommand()
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

class COutputMaxGreenLevelHistogramMonitorCommand : public CLxBasicCommand
{
public:
    COutputMaxGreenLevelHistogramMonitorCommand();
    virtual ~COutputMaxGreenLevelHistogramMonitorCommand()
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

class COutputMinBlueLevelHistogramMonitorCommand : public CLxBasicCommand
{
public:
    COutputMinBlueLevelHistogramMonitorCommand();
    virtual ~COutputMinBlueLevelHistogramMonitorCommand()
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

class COutputMaxBlueLevelHistogramMonitorCommand : public CLxBasicCommand
{
public:
    COutputMaxBlueLevelHistogramMonitorCommand();
    virtual ~COutputMaxBlueLevelHistogramMonitorCommand()
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
class CHistogramMonitorNotifier : public CLxCommandNotifier
{
public:
    CHistogramMonitorNotifier();
    virtual ~CHistogramMonitorNotifier()
    {
    }

    void         cn_Parse(std::string& args) override;
    unsigned int cn_Flags(int code) override;
};

/*
 * ---------------------------------------------------------------------------
 * CHistogramMonitor.
 */

/*
 * Display Mode choices.
 */
enum
{
    DISPLAY_HISTOGRAM,  // Histogram
    DISPLAY_RGBPARADE   // RGB Parade
};

/*
 * Histogram Channel choices.
 */
enum
{
    HISTOGRAM_COLORS,      // color components overlaid one on top of another
    HISTOGRAM_LUMINOSITY,  // luminosity
    HISTOGRAM_RGB,         // sum of the RGB channels
    HISTOGRAM_RED,         // red channel
    HISTOGRAM_GREEN,       // green channel
    HISTOGRAM_BLUE         // blue channel
};

/*
 * Parade Channel choices.
 */
enum
{
    PARADE_RED,    // red channel
    PARADE_GREEN,  // green channel
    PARADE_BLUE    // blue channel
};

class CHistogramMonitor : public CLxImpl_ImageMonitor
{
    CHistogramMonitorLog m_log;

public:
    static LXtTagInfoDesc descInfo[];

    CHistogramMonitor();
    virtual ~CHistogramMonitor();

    LxResult imon_Image(ILxUnknownID imageToAnalyze,
                        ILxUnknownID frameBufferToAnalyze,
                        int          bufferIndex,
                        double       x1,
                        double       y1,
                        double       x2,
                        double       y2,
                        ILxUnknownID imageProcRead,
                        ILxUnknownID processedThumbnail) override;

    LxResult imon_ImageProcChanged(void) override;

    LxResult imon_AspectRange(double* minAspect, double* maxAspect, double* idealAspect) override;

    LxResult imon_Draw(ILxUnknownID imageForDrawing) override;

    LxResult imon_ImageSource(const char* imageSourceString) override;

    LxResult imon_MouseDown(int startx, int starty, int w, int h) override;

    LxResult imon_MouseMove(int startx, int starty, int cx, int cy, int w, int h) override;

    LxResult imon_MouseUp(int startx, int starty, int cx, int cy, int w, int h) override;

    LxResult imon_MouseTrackEnter(void) override;

    LxResult imon_MouseTrack(int cx, int cy, int w, int h) override;

    LxResult imon_MouseTrackExit(void) override;

    LxResult imon_ToolTip(int cx, int cy, int w, int h, char* buffer, unsigned len) override;

    unsigned DisplayMode(void);
    unsigned HistogramChannelMode(void);
    unsigned ParadeChannelMode(void);

    float RangeMin(void);
    float RangeMax(void);

private:
    LxResult AnalyzeImage(void);

    LxResult AnalyzeFrameBuffer(void);

    bool                sharingThumbnail;
    bool                hasSourceBuffer;
    CLxUser_FrameBuffer frameBuffer;
    CLxUser_Buffer      sourceBuffer;
    int                 sourceBufferIndex;

    CLxUser_ImageProcessingRead imageProcessing;

    bool          hasSourceImage;
    CLxUser_Image fullSourceImage;
    CLxUser_Image cachedImage;

    double regionX1;
    double regionY1;
    double regionX2;
    double regionY2;

    int levelResolution;

    unsigned pixelCount;

    std::string imageSource;

    std::vector<float> redLevels;
    std::vector<float> greenLevels;
    std::vector<float> blueLevels;

    std::vector<float> lumaLevels;
    std::vector<float> channelLevels;

    int legendHeight;
    int legendThumbOffset;
    int legendThumbInset;
    int paradeInset;

    bool DrawColors(CLxUser_ImageWrite& writeImage, int dstWidth, int dstHeight);

    bool DrawLuminosity(CLxUser_ImageWrite& writeImage, int dstWidth, int dstHeight);

    bool DrawRGB(CLxUser_ImageWrite& writeImage, int dstWidth, int dstHeight);

    bool DrawChannel(CLxUser_ImageWrite& writeImage, int dstWidth, int dstHeight, unsigned channel);

    bool DrawParade(CLxUser_ImageWrite& writeImage, int dstWidth, int dstHeight);

    void DrawEmptyBackground(CLxUser_ImageWrite& writeImage, int dstWidth, int dstHeight);

    void DrawBorder(CLxUser_ImageWrite& writeImage, int dstWidth, int dstHeight);

    void DrawLegend(CLxUser_ImageWrite& writeImage, int dstWidth, int dstHeight, bool enabled);

    typedef enum
    {
        Marker_None,
        Marker_BlackPoint,
        Marker_WhitePoint,
        Marker_MinRedPoint,
        Marker_MaxRedPoint,
        Marker_MinGreenPoint,
        Marker_MaxGreenPoint,
        Marker_MinBluePoint,
        Marker_MaxBluePoint
    } MarkerType;

    bool MarkerPoint(MarkerType markerType, LXtFVector2& point);

    float OffsetToValue(float offset, int movingMarker);

    MarkerType HitMarker(int x, int y);

    MarkerType m_movingMarker;

    LXtFVector2 lastMouse;

    CLxUser_Image outputBlackLevel_marker16;
    CLxUser_Image outputBlackLevel_marker32;

    CLxUser_Image outputWhiteLevel_marker16;
    CLxUser_Image outputWhiteLevel_marker32;

    CLxUser_Image outputMinRedLevel_marker16;
    CLxUser_Image outputMinRedLevel_marker32;

    CLxUser_Image outputMaxRedLevel_marker16;
    CLxUser_Image outputMaxRedLevel_marker32;

    CLxUser_Image outputMinGreenLevel_marker16;
    CLxUser_Image outputMinGreenLevel_marker32;

    CLxUser_Image outputMaxGreenLevel_marker16;
    CLxUser_Image outputMaxGreenLevel_marker32;

    CLxUser_Image outputMinBlueLevel_marker16;
    CLxUser_Image outputMinBlueLevel_marker32;

    CLxUser_Image outputMaxBlueLevel_marker16;
    CLxUser_Image outputMaxBlueLevel_marker32;

    LxResult SetBlackPoint(float blackPoint);
    LxResult SetWhitePoint(float whitePoint);

    LxResult SetMinRedPoint(float minRedPoint);
    LxResult SetMaxRedPoint(float maxRedPoint);

    LxResult SetMinGreenPoint(float minGreenPoint);
    LxResult SetMaxGreenPoint(float maxGreenPoint);

    LxResult SetMinBluePoint(float minBluePoint);
    LxResult SetMaxBluePoint(float maxBluePoint);

    LxResult SetOutputLevelCommand(const std::string& commandName, float level);

    int m_dstWidth;
    int m_paradeWidth;

    int m_dstHeight;
};
