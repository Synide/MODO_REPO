//
// C++ wrapper for lxsdk/lxexternalrender.h.
//
//	Copyright 2023.
//
//
#pragma once

#include <lxexternalrender.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx
{
    static LXtGUID const guid_ExternalRender = {0x4D764AD2, {0xE3B8, 0x4689}, {0x93, 0xE0, 0x61, 0x31, 0x07, 0xE0, 0x44, 0xB8}};
    static LXtGUID const guid_ExternalRenderBufferQueue = {0x17F0A6B6, {0x9B36, 0x4BE2}, {0xB6, 0x5B, 0x76, 0xD2, 0xAC, 0x3F, 0x57, 0x53}};
    static LXtGUID const guid_ExternalRenderNotifier = {0x2D7FFF27, {0x5E49, 0x47C2}, {0x92, 0x8D, 0x38, 0x0D, 0x8E, 0x18, 0xE8, 0xF9}};
} // namespace lx

class CLxImpl_ExternalRender
{
public:
    virtual ~CLxImpl_ExternalRender() = default;

    virtual auto rend_Start([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto rend_Stop([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto rend_Pause([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto rend_Reset([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto rend_SelectedPixelAt([[maybe_unused]] const int x, [[maybe_unused]] const int y) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto rend_SetNotifier([[maybe_unused]] ILxUnknownID notifier) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto rend_SetBufferQueue([[maybe_unused]] ILxUnknownID bufferQueue) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_ExternalRender_Start LxResult rend_Start()
#define LXxO_ExternalRender_Start LXxD_ExternalRender_Start override
#define LXxC_ExternalRender_Start(c) LxResult c::rend_Start()
#define LXxD_ExternalRender_Stop LxResult rend_Stop()
#define LXxO_ExternalRender_Stop LXxD_ExternalRender_Stop override
#define LXxC_ExternalRender_Stop(c) LxResult c::rend_Stop()
#define LXxD_ExternalRender_Pause LxResult rend_Pause()
#define LXxO_ExternalRender_Pause LXxD_ExternalRender_Pause override
#define LXxC_ExternalRender_Pause(c) LxResult c::rend_Pause()
#define LXxD_ExternalRender_Reset LxResult rend_Reset()
#define LXxO_ExternalRender_Reset LXxD_ExternalRender_Reset override
#define LXxC_ExternalRender_Reset(c) LxResult c::rend_Reset()
#define LXxD_ExternalRender_SelectedPixelAt LxResult rend_SelectedPixelAt([[maybe_unused]] const int x, [[maybe_unused]] const int y)
#define LXxO_ExternalRender_SelectedPixelAt LXxD_ExternalRender_SelectedPixelAt override
#define LXxC_ExternalRender_SelectedPixelAt(c) LxResult c::rend_SelectedPixelAt([[maybe_unused]] const int x, [[maybe_unused]] const int y)
#define LXxD_ExternalRender_SetNotifier LxResult rend_SetNotifier([[maybe_unused]] ILxUnknownID notifier)
#define LXxO_ExternalRender_SetNotifier LXxD_ExternalRender_SetNotifier override
#define LXxC_ExternalRender_SetNotifier(c) LxResult c::rend_SetNotifier([[maybe_unused]] ILxUnknownID notifier)
#define LXxD_ExternalRender_SetBufferQueue LxResult rend_SetBufferQueue([[maybe_unused]] ILxUnknownID bufferQueue)
#define LXxO_ExternalRender_SetBufferQueue LXxD_ExternalRender_SetBufferQueue override
#define LXxC_ExternalRender_SetBufferQueue(c) LxResult c::rend_SetBufferQueue([[maybe_unused]] ILxUnknownID bufferQueue)

template <class T>
class CLxIfc_ExternalRender: public CLxInterface
{
public:
    CLxIfc_ExternalRender()
    {
        vt.Start = Start;
        vt.Stop = Stop;
        vt.Pause = Pause;
        vt.Reset = Reset;
        vt.SelectedPixelAt = SelectedPixelAt;
        vt.SetNotifier = SetNotifier;
        vt.SetBufferQueue = SetBufferQueue;
        vTable = &vt.iunk;
        iid = &lx::guid_ExternalRender;
    }

    static auto Start(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_ExternalRender, loc);
        try
        {
           return loc->rend_Start();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Stop(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_ExternalRender, loc);
        try
        {
           return loc->rend_Stop();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Pause(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_ExternalRender, loc);
        try
        {
           return loc->rend_Pause();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Reset(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_ExternalRender, loc);
        try
        {
           return loc->rend_Reset();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SelectedPixelAt(LXtObjectID wcom,const int x,const int y) -> LxResult
    {
        LXCWxINST (CLxImpl_ExternalRender, loc);
        try
        {
           return loc->rend_SelectedPixelAt( x, y);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SetNotifier(LXtObjectID wcom,LXtObjectID notifier) -> LxResult
    {
        LXCWxINST (CLxImpl_ExternalRender, loc);
        try
        {
           return loc->rend_SetNotifier((ILxUnknownID) notifier);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SetBufferQueue(LXtObjectID wcom,LXtObjectID bufferQueue) -> LxResult
    {
        LXCWxINST (CLxImpl_ExternalRender, loc);
        try
        {
           return loc->rend_SetBufferQueue((ILxUnknownID) bufferQueue);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxExternalRender vt;
};

class CLxLoc_ExternalRender : public CLxLocalize<ILxExternalRenderID>
{
public:
    CLxLoc_ExternalRender()
    {
        _init();
    }

    CLxLoc_ExternalRender(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_ExternalRender(CLxLoc_ExternalRender const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const*
    {
        return &lx::guid_ExternalRender;
    }

    auto Start(void) const -> LxResult
    {
        return m_loc[0]->Start(m_loc);
    }

    auto Stop(void) const -> LxResult
    {
        return m_loc[0]->Stop(m_loc);
    }

    auto Pause(void) const -> LxResult
    {
        return m_loc[0]->Pause(m_loc);
    }

    auto Reset(void) const -> LxResult
    {
        return m_loc[0]->Reset(m_loc);
    }

    auto SelectedPixelAt(const int x, const int y) const -> LxResult
    {
        return m_loc[0]->SelectedPixelAt(m_loc, x, y);
    }

    auto SetNotifier(ILxUnknownID notifier) -> LxResult
    {
        return m_loc[0]->SetNotifier(m_loc,(ILxUnknownID) notifier);
    }

    auto SetBufferQueue(ILxUnknownID bufferQueue) -> LxResult
    {
        return m_loc[0]->SetBufferQueue(m_loc,(ILxUnknownID) bufferQueue);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_ExternalRenderBufferQueue : public CLxLocalize<ILxExternalRenderBufferQueueID>
{
public:
    CLxLoc_ExternalRenderBufferQueue()
    {
        _init();
    }

    CLxLoc_ExternalRenderBufferQueue(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_ExternalRenderBufferQueue(CLxLoc_ExternalRenderBufferQueue const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const*
    {
        return &lx::guid_ExternalRenderBufferQueue;
    }

    auto WriteBegin(LXtExternalRenderBuffer *buffer) -> LxResult
    {
        return m_loc[0]->WriteBegin(m_loc, buffer);
    }

    auto WriteEnd(LXtExternalRenderBuffer *buffer) -> LxResult
    {
        return m_loc[0]->WriteEnd(m_loc, buffer);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_ExternalRenderNotifier
{
public:
    virtual ~CLxImpl_ExternalRenderNotifier() = default;

    virtual auto ntf_Notify([[maybe_unused]] const LXtRenderOutputProcess *rndrProcess, [[maybe_unused]] ILxUnknownID image, [[maybe_unused]] int completed) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto ntf_SetStatusText([[maybe_unused]] const char *text) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_ExternalRenderNotifier_Notify LxResult ntf_Notify([[maybe_unused]] const LXtRenderOutputProcess *rndrProcess, [[maybe_unused]] ILxUnknownID image, [[maybe_unused]] int completed)
#define LXxO_ExternalRenderNotifier_Notify LXxD_ExternalRenderNotifier_Notify override
#define LXxC_ExternalRenderNotifier_Notify(c) LxResult c::ntf_Notify([[maybe_unused]] const LXtRenderOutputProcess *rndrProcess, [[maybe_unused]] ILxUnknownID image, [[maybe_unused]] int completed)
#define LXxD_ExternalRenderNotifier_SetStatusText LxResult ntf_SetStatusText([[maybe_unused]] const char *text)
#define LXxO_ExternalRenderNotifier_SetStatusText LXxD_ExternalRenderNotifier_SetStatusText override
#define LXxC_ExternalRenderNotifier_SetStatusText(c) LxResult c::ntf_SetStatusText([[maybe_unused]] const char *text)

template <class T>
class CLxIfc_ExternalRenderNotifier: public CLxInterface
{
public:
    CLxIfc_ExternalRenderNotifier()
    {
        vt.Notify = Notify;
        vt.SetStatusText = SetStatusText;
        vTable = &vt.iunk;
        iid = &lx::guid_ExternalRenderNotifier;
    }

    static auto Notify(LXtObjectID wcom,const LXtRenderOutputProcess *rndrProcess,LXtObjectID image,int completed) -> LxResult
    {
        LXCWxINST (CLxImpl_ExternalRenderNotifier, loc);
        try
        {
           return loc->ntf_Notify( rndrProcess,(ILxUnknownID) image, completed);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SetStatusText(LXtObjectID wcom,const char *text) -> LxResult
    {
        LXCWxINST (CLxImpl_ExternalRenderNotifier, loc);
        try
        {
           return loc->ntf_SetStatusText( text);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxExternalRenderNotifier vt;
};

class CLxLoc_ExternalRenderNotifier : public CLxLocalize<ILxExternalRenderNotifierID>
{
public:
    CLxLoc_ExternalRenderNotifier()
    {
        _init();
    }

    CLxLoc_ExternalRenderNotifier(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_ExternalRenderNotifier(CLxLoc_ExternalRenderNotifier const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const*
    {
        return &lx::guid_ExternalRenderNotifier;
    }

    auto Notify(const LXtRenderOutputProcess *rndrProcess, ILxUnknownID image, int completed) -> LxResult
    {
        return m_loc[0]->Notify(m_loc, rndrProcess,(ILxUnknownID) image, completed);
    }

    auto SetStatusText(const char *text) -> LxResult
    {
        return m_loc[0]->SetStatusText(m_loc, text);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
