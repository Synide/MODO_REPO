//
// C++ wrapper for lxsdk/lxstopwatch.h.
//
//	Copyright 2024.
//
//
#pragma once

#include <lxstopwatch.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx
{
    static LXtGUID const guid_StopwatchService = {0x87E96FE9, {0xFA5C, 0x4C74}, {0xAC, 0x42, 0x03, 0x17, 0xFF, 0xE3, 0x8D, 0x59}};
    static LXtGUID const guid_Stopwatch = {0x237FC39A, {0x1B46, 0x4392}, {0xAE, 0x72, 0xCD, 0x78, 0x7F, 0xA5, 0x92, 0xC9}};
} // namespace lx

class CLxLoc_StopwatchService : public CLxLocalizedService
{
public:
    ILxStopwatchServiceID m_loc{ nullptr };

public:
    CLxLoc_StopwatchService()
    {
        _init();
        set();
    }

    ~CLxLoc_StopwatchService() = default;

    void set()
    {
        if (!m_loc)
        {
            m_loc = reinterpret_cast<ILxStopwatchServiceID>(lx::GetGlobal(&lx::guid_StopwatchService));
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

    auto Allocate(const char *ident, void **ppvObj) -> LxResult
    {
        return m_loc[0]->Allocate(m_loc, ident, ppvObj);
    }

    auto Allocate(const char *ident, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Allocate(m_loc, ident, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_Stopwatch
{
public:
    virtual ~CLxImpl_Stopwatch() = default;

    virtual auto stop_Start([[maybe_unused]] int startChildren) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto stop_Stop([[maybe_unused]] int stopChildren) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto stop_Reset([[maybe_unused]] int resetChildren) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto stop_Time([[maybe_unused]] int includeChildren, [[maybe_unused]] int *time) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual int stop_IsActive(void) = 0;

    virtual void stop_Identifier([[maybe_unused]] const char **ident)
    {
    }

    virtual auto stop_AddChildStopwatch([[maybe_unused]] const char *ident, [[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto stop_RemoveChildStopwatch([[maybe_unused]] const char *ident) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual int stop_ChildCount(void) = 0;

    virtual auto stop_ChildByIndex([[maybe_unused]] int index, [[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual void stop_LogOutput([[maybe_unused]] void)
    {
    }
};

#define LXxD_Stopwatch_Start LxResult stop_Start([[maybe_unused]] int startChildren) override
#define LXxO_Stopwatch_Start LXxD_Stopwatch_Start
#define LXxC_Stopwatch_Start(c) LxResult c::stop_Start([[maybe_unused]] int startChildren)
#define LXxD_Stopwatch_Stop LxResult stop_Stop([[maybe_unused]] int stopChildren) override
#define LXxO_Stopwatch_Stop LXxD_Stopwatch_Stop
#define LXxC_Stopwatch_Stop(c) LxResult c::stop_Stop([[maybe_unused]] int stopChildren)
#define LXxD_Stopwatch_Reset LxResult stop_Reset([[maybe_unused]] int resetChildren) override
#define LXxO_Stopwatch_Reset LXxD_Stopwatch_Reset
#define LXxC_Stopwatch_Reset(c) LxResult c::stop_Reset([[maybe_unused]] int resetChildren)
#define LXxD_Stopwatch_Time LxResult stop_Time([[maybe_unused]] int includeChildren, [[maybe_unused]] int *time) override
#define LXxO_Stopwatch_Time LXxD_Stopwatch_Time
#define LXxC_Stopwatch_Time(c) LxResult c::stop_Time([[maybe_unused]] int includeChildren, [[maybe_unused]] int *time)
#define LXxD_Stopwatch_IsActive int stop_IsActive() override
#define LXxO_Stopwatch_IsActive LXxD_Stopwatch_IsActive
#define LXxC_Stopwatch_IsActive(c) int c::stop_IsActive()
#define LXxD_Stopwatch_Identifier void stop_Identifier([[maybe_unused]] const char **ident) override
#define LXxO_Stopwatch_Identifier LXxD_Stopwatch_Identifier
#define LXxC_Stopwatch_Identifier(c) void c::stop_Identifier([[maybe_unused]] const char **ident)
#define LXxD_Stopwatch_AddChildStopwatch LxResult stop_AddChildStopwatch([[maybe_unused]] const char *ident, [[maybe_unused]] void **ppvObj) override
#define LXxO_Stopwatch_AddChildStopwatch LXxD_Stopwatch_AddChildStopwatch
#define LXxC_Stopwatch_AddChildStopwatch(c) LxResult c::stop_AddChildStopwatch([[maybe_unused]] const char *ident, [[maybe_unused]] void **ppvObj)
#define LXxD_Stopwatch_RemoveChildStopwatch LxResult stop_RemoveChildStopwatch([[maybe_unused]] const char *ident) override
#define LXxO_Stopwatch_RemoveChildStopwatch LXxD_Stopwatch_RemoveChildStopwatch
#define LXxC_Stopwatch_RemoveChildStopwatch(c) LxResult c::stop_RemoveChildStopwatch([[maybe_unused]] const char *ident)
#define LXxD_Stopwatch_ChildCount int stop_ChildCount() override
#define LXxO_Stopwatch_ChildCount LXxD_Stopwatch_ChildCount
#define LXxC_Stopwatch_ChildCount(c) int c::stop_ChildCount()
#define LXxD_Stopwatch_ChildByIndex LxResult stop_ChildByIndex([[maybe_unused]] int index, [[maybe_unused]] void **ppvObj) override
#define LXxO_Stopwatch_ChildByIndex LXxD_Stopwatch_ChildByIndex
#define LXxC_Stopwatch_ChildByIndex(c) LxResult c::stop_ChildByIndex([[maybe_unused]] int index, [[maybe_unused]] void **ppvObj)
#define LXxD_Stopwatch_LogOutput void stop_LogOutput() override
#define LXxO_Stopwatch_LogOutput LXxD_Stopwatch_LogOutput
#define LXxC_Stopwatch_LogOutput(c) void c::stop_LogOutput()

template <class T>
class CLxIfc_Stopwatch: public CLxInterface
{
public:
    CLxIfc_Stopwatch()
    {
        vt.Start = Start;
        vt.Stop = Stop;
        vt.Reset = Reset;
        vt.Time = Time;
        vt.IsActive = IsActive;
        vt.Identifier = Identifier;
        vt.AddChildStopwatch = AddChildStopwatch;
        vt.RemoveChildStopwatch = RemoveChildStopwatch;
        vt.ChildCount = ChildCount;
        vt.ChildByIndex = ChildByIndex;
        vt.LogOutput = LogOutput;
        vTable = &vt.iunk;
        iid = &lx::guid_Stopwatch;
    }

    static auto Start(LXtObjectID wcom,int startChildren) -> LxResult
    {
        LXCWxINST (CLxImpl_Stopwatch, loc);
        try
        {
           return loc->stop_Start( startChildren);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Stop(LXtObjectID wcom,int stopChildren) -> LxResult
    {
        LXCWxINST (CLxImpl_Stopwatch, loc);
        try
        {
           return loc->stop_Stop( stopChildren);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Reset(LXtObjectID wcom,int resetChildren) -> LxResult
    {
        LXCWxINST (CLxImpl_Stopwatch, loc);
        try
        {
           return loc->stop_Reset( resetChildren);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Time(LXtObjectID wcom,int includeChildren,int *time) -> LxResult
    {
        LXCWxINST (CLxImpl_Stopwatch, loc);
        try
        {
           return loc->stop_Time( includeChildren, time);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto IsActive(LXtObjectID wcom) -> int
    {
        LXCWxINST (CLxImpl_Stopwatch, loc);
        return loc->stop_IsActive();
    }

    static auto Identifier(LXtObjectID wcom,const char **ident) -> void
    {
        LXCWxINST (CLxImpl_Stopwatch, loc);
        loc->stop_Identifier( ident);
    }

    static auto AddChildStopwatch(LXtObjectID wcom,const char *ident,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_Stopwatch, loc);
        try
        {
           return loc->stop_AddChildStopwatch( ident, ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto RemoveChildStopwatch(LXtObjectID wcom,const char *ident) -> LxResult
    {
        LXCWxINST (CLxImpl_Stopwatch, loc);
        try
        {
           return loc->stop_RemoveChildStopwatch( ident);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ChildCount(LXtObjectID wcom) -> int
    {
        LXCWxINST (CLxImpl_Stopwatch, loc);
        return loc->stop_ChildCount();
    }

    static auto ChildByIndex(LXtObjectID wcom,int index,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_Stopwatch, loc);
        try
        {
           return loc->stop_ChildByIndex( index, ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto LogOutput(LXtObjectID wcom) -> void
    {
        LXCWxINST (CLxImpl_Stopwatch, loc);
        loc->stop_LogOutput();
    }

private:
    ILxStopwatch vt;
};

class CLxLoc_Stopwatch : public CLxLocalize<ILxStopwatchID>
{
public:
    CLxLoc_Stopwatch()
    {
        _init();
    }

    CLxLoc_Stopwatch(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_Stopwatch(CLxLoc_Stopwatch const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_Stopwatch;
    }

    auto Start(int startChildren) -> LxResult
    {
        return m_loc[0]->Start(m_loc, startChildren);
    }

    auto Stop(int stopChildren) -> LxResult
    {
        return m_loc[0]->Stop(m_loc, stopChildren);
    }

    auto Reset(int resetChildren) -> LxResult
    {
        return m_loc[0]->Reset(m_loc, resetChildren);
    }

    auto Time(int includeChildren, int *time) -> LxResult
    {
        return m_loc[0]->Time(m_loc, includeChildren, time);
    }

    auto IsActive(void) -> int
    {
        return m_loc[0]->IsActive(m_loc);
    }

    auto Identifier(const char **ident) -> void
    {
        m_loc[0]->Identifier(m_loc, ident);
    }

    auto AddChildStopwatch(const char *ident, void **ppvObj) -> LxResult
    {
        return m_loc[0]->AddChildStopwatch(m_loc, ident, ppvObj);
    }

    auto AddChildStopwatch(const char *ident, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->AddChildStopwatch(m_loc, ident, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto RemoveChildStopwatch(const char *ident) -> LxResult
    {
        return m_loc[0]->RemoveChildStopwatch(m_loc, ident);
    }

    auto ChildCount(void) -> int
    {
        return m_loc[0]->ChildCount(m_loc);
    }

    auto ChildByIndex(int index, void **ppvObj) -> LxResult
    {
        return m_loc[0]->ChildByIndex(m_loc, index, ppvObj);
    }

    auto ChildByIndex(int index, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->ChildByIndex(m_loc, index, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto LogOutput(void) -> void
    {
        m_loc[0]->LogOutput(m_loc);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
