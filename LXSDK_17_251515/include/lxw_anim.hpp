//
// C++ wrapper for lxsdk/lxanim.h.
//
//	Copyright 2024.
//
//
#pragma once

#include <lxanim.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx
{
    static LXtGUID const guid_AnimListener = {0x4A0862DA, {0xCAC6, 0x48EC}, {0xA3, 0xDA, 0xDE, 0x28, 0x5F, 0xE5, 0x28, 0xB5}};
} // namespace lx

class CLxImpl_AnimListener
{
public:
    virtual ~CLxImpl_AnimListener() = default;

    virtual auto animevent_TimeChange([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto animevent_PlayStart([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto animevent_PlayEnd([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto animevent_ScrubTime([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto animevent_ScrubEnd([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto animevent_EnterSetup([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto animevent_LeaveSetup([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_AnimListener_TimeChange LxResult animevent_TimeChange() override
#define LXxO_AnimListener_TimeChange LXxD_AnimListener_TimeChange
#define LXxC_AnimListener_TimeChange(c) LxResult c::animevent_TimeChange()
#define LXxD_AnimListener_PlayStart LxResult animevent_PlayStart() override
#define LXxO_AnimListener_PlayStart LXxD_AnimListener_PlayStart
#define LXxC_AnimListener_PlayStart(c) LxResult c::animevent_PlayStart()
#define LXxD_AnimListener_PlayEnd LxResult animevent_PlayEnd() override
#define LXxO_AnimListener_PlayEnd LXxD_AnimListener_PlayEnd
#define LXxC_AnimListener_PlayEnd(c) LxResult c::animevent_PlayEnd()
#define LXxD_AnimListener_ScrubTime LxResult animevent_ScrubTime() override
#define LXxO_AnimListener_ScrubTime LXxD_AnimListener_ScrubTime
#define LXxC_AnimListener_ScrubTime(c) LxResult c::animevent_ScrubTime()
#define LXxD_AnimListener_ScrubEnd LxResult animevent_ScrubEnd() override
#define LXxO_AnimListener_ScrubEnd LXxD_AnimListener_ScrubEnd
#define LXxC_AnimListener_ScrubEnd(c) LxResult c::animevent_ScrubEnd()
#define LXxD_AnimListener_EnterSetup LxResult animevent_EnterSetup() override
#define LXxO_AnimListener_EnterSetup LXxD_AnimListener_EnterSetup
#define LXxC_AnimListener_EnterSetup(c) LxResult c::animevent_EnterSetup()
#define LXxD_AnimListener_LeaveSetup LxResult animevent_LeaveSetup() override
#define LXxO_AnimListener_LeaveSetup LXxD_AnimListener_LeaveSetup
#define LXxC_AnimListener_LeaveSetup(c) LxResult c::animevent_LeaveSetup()

template <class T>
class CLxIfc_AnimListener: public CLxInterface
{
public:
    CLxIfc_AnimListener()
    {
        vt.TimeChange = TimeChange;
        vt.PlayStart = PlayStart;
        vt.PlayEnd = PlayEnd;
        vt.ScrubTime = ScrubTime;
        vt.ScrubEnd = ScrubEnd;
        vt.EnterSetup = EnterSetup;
        vt.LeaveSetup = LeaveSetup;
        vTable = &vt.iunk;
        iid = &lx::guid_AnimListener;
    }

    static auto TimeChange(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_AnimListener, loc);
        try
        {
           return loc->animevent_TimeChange();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto PlayStart(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_AnimListener, loc);
        try
        {
           return loc->animevent_PlayStart();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto PlayEnd(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_AnimListener, loc);
        try
        {
           return loc->animevent_PlayEnd();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ScrubTime(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_AnimListener, loc);
        try
        {
           return loc->animevent_ScrubTime();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ScrubEnd(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_AnimListener, loc);
        try
        {
           return loc->animevent_ScrubEnd();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto EnterSetup(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_AnimListener, loc);
        try
        {
           return loc->animevent_EnterSetup();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto LeaveSetup(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_AnimListener, loc);
        try
        {
           return loc->animevent_LeaveSetup();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxAnimListener vt;
};

class CLxLoc_AnimListener : public CLxLocalize<ILxAnimListenerID>
{
public:
    CLxLoc_AnimListener()
    {
        _init();
    }

    CLxLoc_AnimListener(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_AnimListener(CLxLoc_AnimListener const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_AnimListener;
    }

    auto TimeChange(void) -> LxResult
    {
        return m_loc[0]->TimeChange(m_loc);
    }

    auto PlayStart(void) -> LxResult
    {
        return m_loc[0]->PlayStart(m_loc);
    }

    auto PlayEnd(void) -> LxResult
    {
        return m_loc[0]->PlayEnd(m_loc);
    }

    auto ScrubTime(void) -> LxResult
    {
        return m_loc[0]->ScrubTime(m_loc);
    }

    auto ScrubEnd(void) -> LxResult
    {
        return m_loc[0]->ScrubEnd(m_loc);
    }

    auto EnterSetup(void) -> LxResult
    {
        return m_loc[0]->EnterSetup(m_loc);
    }

    auto LeaveSetup(void) -> LxResult
    {
        return m_loc[0]->LeaveSetup(m_loc);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
