//
// C++ wrapper for lxsdk/lximagemon.h.
//
//	Copyright 2024.
//
//
#pragma once

#include <lximagemon.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx
{
    static LXtGUID const guid_ImageMonitor = {0x5ef021ed, {0xa2e3, 0x48d3}, {0xab, 0xa1, 0x7c, 0xbb, 0x81, 0x5f, 0x15, 0xb7}};
    static LXtGUID const guid_ImageMonitorService = {0xf59258f8, {0x3e86, 0x408f}, {0x9e, 0x92, 0xf8, 0x1a, 0x21, 0xd0, 0x1b, 0xde}};
} // namespace lx

class CLxImpl_ImageMonitor
{
public:
    virtual ~CLxImpl_ImageMonitor() = default;

    virtual auto imon_Image([[maybe_unused]] ILxUnknownID imageToAnalyze, [[maybe_unused]] ILxUnknownID frameBufferToAnalyze, [[maybe_unused]] int bufferIndex, [[maybe_unused]] double x1, [[maybe_unused]] double y1, [[maybe_unused]] double x2, [[maybe_unused]] double y2, [[maybe_unused]] ILxUnknownID imageProcessingRead, [[maybe_unused]] ILxUnknownID processedThumbnail) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto imon_ImageProcChanged([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto imon_AspectRange([[maybe_unused]] double *minAspect, [[maybe_unused]] double *maxAspect, [[maybe_unused]] double *idealAspect) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto imon_Draw([[maybe_unused]] ILxUnknownID imageForDrawing) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto imon_ImageSource([[maybe_unused]] const char *source) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto imon_MouseDown([[maybe_unused]] int startx, [[maybe_unused]] int starty, [[maybe_unused]] int w, [[maybe_unused]] int h) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto imon_MouseMove([[maybe_unused]] int startx, [[maybe_unused]] int starty, [[maybe_unused]] int cx, [[maybe_unused]] int cy, [[maybe_unused]] int w, [[maybe_unused]] int h) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto imon_MouseUp([[maybe_unused]] int startx, [[maybe_unused]] int starty, [[maybe_unused]] int cx, [[maybe_unused]] int cy, [[maybe_unused]] int w, [[maybe_unused]] int h) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto imon_MouseTrackEnter([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto imon_MouseTrack([[maybe_unused]] int cx, [[maybe_unused]] int cy, [[maybe_unused]] int w, [[maybe_unused]] int h) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto imon_MouseTrackExit([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto imon_ToolTip([[maybe_unused]] int cx, [[maybe_unused]] int cy, [[maybe_unused]] int w, [[maybe_unused]] int h, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_ImageMonitor_Image LxResult imon_Image([[maybe_unused]] ILxUnknownID imageToAnalyze, [[maybe_unused]] ILxUnknownID frameBufferToAnalyze, [[maybe_unused]] int bufferIndex, [[maybe_unused]] double x1, [[maybe_unused]] double y1, [[maybe_unused]] double x2, [[maybe_unused]] double y2, [[maybe_unused]] ILxUnknownID imageProcessingRead, [[maybe_unused]] ILxUnknownID processedThumbnail) override
#define LXxO_ImageMonitor_Image LXxD_ImageMonitor_Image
#define LXxC_ImageMonitor_Image(c) LxResult c::imon_Image([[maybe_unused]] ILxUnknownID imageToAnalyze, [[maybe_unused]] ILxUnknownID frameBufferToAnalyze, [[maybe_unused]] int bufferIndex, [[maybe_unused]] double x1, [[maybe_unused]] double y1, [[maybe_unused]] double x2, [[maybe_unused]] double y2, [[maybe_unused]] ILxUnknownID imageProcessingRead, [[maybe_unused]] ILxUnknownID processedThumbnail)
#define LXxD_ImageMonitor_ImageProcChanged LxResult imon_ImageProcChanged() override
#define LXxO_ImageMonitor_ImageProcChanged LXxD_ImageMonitor_ImageProcChanged
#define LXxC_ImageMonitor_ImageProcChanged(c) LxResult c::imon_ImageProcChanged()
#define LXxD_ImageMonitor_AspectRange LxResult imon_AspectRange([[maybe_unused]] double *minAspect, [[maybe_unused]] double *maxAspect, [[maybe_unused]] double *idealAspect) override
#define LXxO_ImageMonitor_AspectRange LXxD_ImageMonitor_AspectRange
#define LXxC_ImageMonitor_AspectRange(c) LxResult c::imon_AspectRange([[maybe_unused]] double *minAspect, [[maybe_unused]] double *maxAspect, [[maybe_unused]] double *idealAspect)
#define LXxD_ImageMonitor_Draw LxResult imon_Draw([[maybe_unused]] ILxUnknownID imageForDrawing) override
#define LXxO_ImageMonitor_Draw LXxD_ImageMonitor_Draw
#define LXxC_ImageMonitor_Draw(c) LxResult c::imon_Draw([[maybe_unused]] ILxUnknownID imageForDrawing)
#define LXxD_ImageMonitor_ImageSource LxResult imon_ImageSource([[maybe_unused]] const char *source) override
#define LXxO_ImageMonitor_ImageSource LXxD_ImageMonitor_ImageSource
#define LXxC_ImageMonitor_ImageSource(c) LxResult c::imon_ImageSource([[maybe_unused]] const char *source)
#define LXxD_ImageMonitor_MouseDown LxResult imon_MouseDown([[maybe_unused]] int startx, [[maybe_unused]] int starty, [[maybe_unused]] int w, [[maybe_unused]] int h) override
#define LXxO_ImageMonitor_MouseDown LXxD_ImageMonitor_MouseDown
#define LXxC_ImageMonitor_MouseDown(c) LxResult c::imon_MouseDown([[maybe_unused]] int startx, [[maybe_unused]] int starty, [[maybe_unused]] int w, [[maybe_unused]] int h)
#define LXxD_ImageMonitor_MouseMove LxResult imon_MouseMove([[maybe_unused]] int startx, [[maybe_unused]] int starty, [[maybe_unused]] int cx, [[maybe_unused]] int cy, [[maybe_unused]] int w, [[maybe_unused]] int h) override
#define LXxO_ImageMonitor_MouseMove LXxD_ImageMonitor_MouseMove
#define LXxC_ImageMonitor_MouseMove(c) LxResult c::imon_MouseMove([[maybe_unused]] int startx, [[maybe_unused]] int starty, [[maybe_unused]] int cx, [[maybe_unused]] int cy, [[maybe_unused]] int w, [[maybe_unused]] int h)
#define LXxD_ImageMonitor_MouseUp LxResult imon_MouseUp([[maybe_unused]] int startx, [[maybe_unused]] int starty, [[maybe_unused]] int cx, [[maybe_unused]] int cy, [[maybe_unused]] int w, [[maybe_unused]] int h) override
#define LXxO_ImageMonitor_MouseUp LXxD_ImageMonitor_MouseUp
#define LXxC_ImageMonitor_MouseUp(c) LxResult c::imon_MouseUp([[maybe_unused]] int startx, [[maybe_unused]] int starty, [[maybe_unused]] int cx, [[maybe_unused]] int cy, [[maybe_unused]] int w, [[maybe_unused]] int h)
#define LXxD_ImageMonitor_MouseTrackEnter LxResult imon_MouseTrackEnter() override
#define LXxO_ImageMonitor_MouseTrackEnter LXxD_ImageMonitor_MouseTrackEnter
#define LXxC_ImageMonitor_MouseTrackEnter(c) LxResult c::imon_MouseTrackEnter()
#define LXxD_ImageMonitor_MouseTrack LxResult imon_MouseTrack([[maybe_unused]] int cx, [[maybe_unused]] int cy, [[maybe_unused]] int w, [[maybe_unused]] int h) override
#define LXxO_ImageMonitor_MouseTrack LXxD_ImageMonitor_MouseTrack
#define LXxC_ImageMonitor_MouseTrack(c) LxResult c::imon_MouseTrack([[maybe_unused]] int cx, [[maybe_unused]] int cy, [[maybe_unused]] int w, [[maybe_unused]] int h)
#define LXxD_ImageMonitor_MouseTrackExit LxResult imon_MouseTrackExit() override
#define LXxO_ImageMonitor_MouseTrackExit LXxD_ImageMonitor_MouseTrackExit
#define LXxC_ImageMonitor_MouseTrackExit(c) LxResult c::imon_MouseTrackExit()
#define LXxD_ImageMonitor_ToolTip LxResult imon_ToolTip([[maybe_unused]] int cx, [[maybe_unused]] int cy, [[maybe_unused]] int w, [[maybe_unused]] int h, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len) override
#define LXxO_ImageMonitor_ToolTip LXxD_ImageMonitor_ToolTip
#define LXxC_ImageMonitor_ToolTip(c) LxResult c::imon_ToolTip([[maybe_unused]] int cx, [[maybe_unused]] int cy, [[maybe_unused]] int w, [[maybe_unused]] int h, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len)

template <class T>
class CLxIfc_ImageMonitor: public CLxInterface
{
public:
    CLxIfc_ImageMonitor()
    {
        vt.Image = Image;
        vt.ImageProcChanged = ImageProcChanged;
        vt.AspectRange = AspectRange;
        vt.Draw = Draw;
        vt.ImageSource = ImageSource;
        vt.MouseDown = MouseDown;
        vt.MouseMove = MouseMove;
        vt.MouseUp = MouseUp;
        vt.MouseTrackEnter = MouseTrackEnter;
        vt.MouseTrack = MouseTrack;
        vt.MouseTrackExit = MouseTrackExit;
        vt.ToolTip = ToolTip;
        vTable = &vt.iunk;
        iid = &lx::guid_ImageMonitor;
    }

    static auto Image(LXtObjectID wcom,LXtObjectID imageToAnalyze,LXtObjectID frameBufferToAnalyze,int bufferIndex,double x1,double y1,double x2,double y2,LXtObjectID imageProcessingRead,LXtObjectID processedThumbnail) -> LxResult
    {
        LXCWxINST (CLxImpl_ImageMonitor, loc);
        try
        {
           return loc->imon_Image((ILxUnknownID) imageToAnalyze,(ILxUnknownID) frameBufferToAnalyze, bufferIndex, x1, y1, x2, y2,(ILxUnknownID) imageProcessingRead,(ILxUnknownID) processedThumbnail);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ImageProcChanged(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_ImageMonitor, loc);
        try
        {
           return loc->imon_ImageProcChanged();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto AspectRange(LXtObjectID wcom,double *minAspect,double *maxAspect,double *idealAspect) -> LxResult
    {
        LXCWxINST (CLxImpl_ImageMonitor, loc);
        try
        {
           return loc->imon_AspectRange( minAspect, maxAspect, idealAspect);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Draw(LXtObjectID wcom,LXtObjectID imageForDrawing) -> LxResult
    {
        LXCWxINST (CLxImpl_ImageMonitor, loc);
        try
        {
           return loc->imon_Draw((ILxUnknownID) imageForDrawing);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ImageSource(LXtObjectID wcom,const char *source) -> LxResult
    {
        LXCWxINST (CLxImpl_ImageMonitor, loc);
        try
        {
           return loc->imon_ImageSource( source);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto MouseDown(LXtObjectID wcom,int startx,int starty,int w,int h) -> LxResult
    {
        LXCWxINST (CLxImpl_ImageMonitor, loc);
        try
        {
           return loc->imon_MouseDown( startx, starty, w, h);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto MouseMove(LXtObjectID wcom,int startx,int starty,int cx,int cy,int w,int h) -> LxResult
    {
        LXCWxINST (CLxImpl_ImageMonitor, loc);
        try
        {
           return loc->imon_MouseMove( startx, starty, cx, cy, w, h);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto MouseUp(LXtObjectID wcom,int startx,int starty,int cx,int cy,int w,int h) -> LxResult
    {
        LXCWxINST (CLxImpl_ImageMonitor, loc);
        try
        {
           return loc->imon_MouseUp( startx, starty, cx, cy, w, h);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto MouseTrackEnter(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_ImageMonitor, loc);
        try
        {
           return loc->imon_MouseTrackEnter();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto MouseTrack(LXtObjectID wcom,int cx,int cy,int w,int h) -> LxResult
    {
        LXCWxINST (CLxImpl_ImageMonitor, loc);
        try
        {
           return loc->imon_MouseTrack( cx, cy, w, h);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto MouseTrackExit(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_ImageMonitor, loc);
        try
        {
           return loc->imon_MouseTrackExit();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ToolTip(LXtObjectID wcom,int cx,int cy,int w,int h,char *buf,unsigned len) -> LxResult
    {
        LXCWxINST (CLxImpl_ImageMonitor, loc);
        try
        {
           return loc->imon_ToolTip( cx, cy, w, h, buf, len);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxImageMonitor vt;
};

class CLxLoc_ImageMonitor : public CLxLocalize<ILxImageMonitorID>
{
public:
    CLxLoc_ImageMonitor()
    {
        _init();
    }

    CLxLoc_ImageMonitor(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_ImageMonitor(CLxLoc_ImageMonitor const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_ImageMonitor;
    }

    auto Image(ILxUnknownID imageToAnalyze, ILxUnknownID frameBufferToAnalyze, int bufferIndex, double x1, double y1, double x2, double y2, ILxUnknownID imageProcessingRead, ILxUnknownID processedThumbnail) -> LxResult
    {
        return m_loc[0]->Image(m_loc,(ILxUnknownID) imageToAnalyze,(ILxUnknownID) frameBufferToAnalyze, bufferIndex, x1, y1, x2, y2,(ILxUnknownID) imageProcessingRead,(ILxUnknownID) processedThumbnail);
    }

    auto ImageProcChanged(void) -> LxResult
    {
        return m_loc[0]->ImageProcChanged(m_loc);
    }

    auto AspectRange(double *minAspect, double *maxAspect, double *idealAspect) -> LxResult
    {
        return m_loc[0]->AspectRange(m_loc, minAspect, maxAspect, idealAspect);
    }

    auto Draw(ILxUnknownID imageForDrawing) -> LxResult
    {
        return m_loc[0]->Draw(m_loc,(ILxUnknownID) imageForDrawing);
    }

    auto ImageSource(const char *source) -> LxResult
    {
        return m_loc[0]->ImageSource(m_loc, source);
    }

    auto MouseDown(int startx, int starty, int w, int h) -> LxResult
    {
        return m_loc[0]->MouseDown(m_loc, startx, starty, w, h);
    }

    auto MouseMove(int startx, int starty, int cx, int cy, int w, int h) -> LxResult
    {
        return m_loc[0]->MouseMove(m_loc, startx, starty, cx, cy, w, h);
    }

    auto MouseUp(int startx, int starty, int cx, int cy, int w, int h) -> LxResult
    {
        return m_loc[0]->MouseUp(m_loc, startx, starty, cx, cy, w, h);
    }

    auto MouseTrackEnter(void) -> LxResult
    {
        return m_loc[0]->MouseTrackEnter(m_loc);
    }

    auto MouseTrack(int cx, int cy, int w, int h) -> LxResult
    {
        return m_loc[0]->MouseTrack(m_loc, cx, cy, w, h);
    }

    auto MouseTrackExit(void) -> LxResult
    {
        return m_loc[0]->MouseTrackExit(m_loc);
    }

    auto ToolTip(int cx, int cy, int w, int h, char *buf, unsigned len) -> LxResult
    {
        return m_loc[0]->ToolTip(m_loc, cx, cy, w, h, buf, len);
    }

    auto ToolTip(int cx, int cy, int w, int h, std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->ToolTip(m_loc, cx, cy, w, h, buf, len);
        LXWx_SBUF2
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_ImageMonitorService : public CLxLocalizedService
{
public:
    ILxImageMonitorServiceID m_loc{ nullptr };

public:
    CLxLoc_ImageMonitorService()
    {
        _init();
        set();
    }

    ~CLxLoc_ImageMonitorService() = default;

    void set()
    {
        if (!m_loc)
        {
            m_loc = reinterpret_cast<ILxImageMonitorServiceID>(lx::GetGlobal(&lx::guid_ImageMonitorService));
        }
    }

    auto ScriptQuery(void **ppvObj) -> LxResult
    {
        return m_loc[0]->ScriptQuery(m_loc, ppvObj);
    }

    auto ScriptQuery(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->ScriptQuery(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto ServerCount(int *count) -> LxResult
    {
        return m_loc[0]->ServerCount(m_loc, count);
    }

    auto ServerByIndex(int index, void **ppvObj) -> LxResult
    {
        return m_loc[0]->ServerByIndex(m_loc, index, ppvObj);
    }

    auto ServerByIndex(int index, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->ServerByIndex(m_loc, index, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto ServerLookup(const char *name, void **ppvObj) -> LxResult
    {
        return m_loc[0]->ServerLookup(m_loc, name, ppvObj);
    }

    auto ServerLookup(const char *name, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->ServerLookup(m_loc, name, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto ServerNameByIndex(int index, const char **name) -> LxResult
    {
        return m_loc[0]->ServerNameByIndex(m_loc, index, name);
    }

    auto ServerUserNameByIndex(int index, const char **name) -> LxResult
    {
        return m_loc[0]->ServerUserNameByIndex(m_loc, index, name);
    }

    auto SourceCount(int *count) -> LxResult
    {
        return m_loc[0]->SourceCount(m_loc, count);
    }

    auto SourceNameByIndex(int index, const char **name) -> LxResult
    {
        return m_loc[0]->SourceNameByIndex(m_loc, index, name);
    }

    auto SourceUserNameByIndex(int index, const char **username) -> LxResult
    {
        return m_loc[0]->SourceUserNameByIndex(m_loc, index, username);
    }

    auto SetImage(const char *imageSource, ILxUnknownID image, ILxUnknownID frameBuffer, int bufferIndex, double x1, double y1, double x2, double y2, ILxUnknownID imageProc, ILxUnknownID processedThumbnail) -> LxResult
    {
        return m_loc[0]->SetImage(m_loc, imageSource,(ILxUnknownID) image,(ILxUnknownID) frameBuffer, bufferIndex, x1, y1, x2, y2,(ILxUnknownID) imageProc,(ILxUnknownID) processedThumbnail);
    }

    auto GetImage(const char *imageSource, void **ppvObj_image, void **ppvObj_frameBuffer, int *bufferIndex, double *x1, double *y1, double *x2, double *y2, void **ppvObj_imageProc, void **ppvObj_processedThumbnail) -> LxResult
    {
        return m_loc[0]->GetImage(m_loc, imageSource, ppvObj_image, ppvObj_frameBuffer, bufferIndex, x1, y1, x2, y2, ppvObj_imageProc, ppvObj_processedThumbnail);
    }

    auto GetImagePacket(const char *imageSource, const LXtImageMonitorPacket **packet) -> LxResult
    {
        return m_loc[0]->GetImagePacket(m_loc, imageSource, packet);
    }

    auto RefreshViews(const char *imageSource, int immediate) -> LxResult
    {
        return m_loc[0]->RefreshViews(m_loc, imageSource, immediate);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
