//
// C++ wrapper for lxsdk/lxthread.h.
//
//	Copyright 2024.
//
//
#pragma once

#include <lxthread.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx
{
    static LXtGUID const guid_WorkList = {0x74568CA9, {0x92C9, 0x4C73}, {0x98, 0x51, 0xE9, 0x16, 0x99, 0x34, 0x62, 0x9A}};
    static LXtGUID const guid_ThreadMutex = {0x7624F6B7, {0x83FD, 0x424F}, {0xA6, 0x8E, 0x0E, 0xDD, 0x08, 0x91, 0x67, 0xCB}};
    static LXtGUID const guid_ThreadService = {0x0A9D5B42, {0x1DA6, 0x42A4}, {0x8F, 0xC4, 0x01, 0xFC, 0xCE, 0x93, 0x9A, 0xC4}};
    static LXtGUID const guid_ThreadJob = {0xDE892B0B, {0xA791, 0x4FA5}, {0xB8, 0x5D, 0x46, 0xE8, 0xCA, 0xCB, 0x69, 0x5B}};
    static LXtGUID const guid_ThreadGroup = {0x54A9DD48, {0x3AFC, 0x435F}, {0x9F, 0x17, 0x2E, 0xEB, 0x6F, 0xB4, 0x6F, 0xBA}};
    static LXtGUID const guid_ThreadSlot = {0x365E4616, {0x0FB9, 0x478E}, {0x99, 0x3D, 0xD3, 0x52, 0x82, 0xF4, 0xC3, 0x26}};
    static LXtGUID const guid_ThreadSlotClient = {0xD24835B6, {0x518B, 0x4E33}, {0x8A, 0x70, 0xE5, 0x30, 0x38, 0xC2, 0x9B, 0xB7}};
    static LXtGUID const guid_SharedWork = {0x4D414F97, {0x35A4, 0x4B26}, {0x84, 0xFE, 0x0E, 0x74, 0x0C, 0x79, 0x72, 0x2C}};
    static LXtGUID const guid_ThreadRangeWorker = {0x612153FE, {0x572F, 0x4CD6}, {0x80, 0x33, 0xB9, 0x05, 0x76, 0x2C, 0x31, 0x06}};
    static LXtGUID const guid_Waterfall = {0x2B845B2A, {0x06BE, 0x4C90}, {0x8E, 0x50, 0x58, 0xF7, 0xFB, 0xEE, 0xC2, 0x5E}};
} // namespace lx

class CLxImpl_WorkList
{
public:
    virtual ~CLxImpl_WorkList() = default;

    virtual auto work_IsEmpty([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual void * work_Next(void) = 0;

    virtual auto work_Split([[maybe_unused]] unsigned mode, [[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual void work_Clear([[maybe_unused]] void)
    {
    }
};

#define LXxD_WorkList_IsEmpty LxResult work_IsEmpty() override
#define LXxO_WorkList_IsEmpty LXxD_WorkList_IsEmpty
#define LXxC_WorkList_IsEmpty(c) LxResult c::work_IsEmpty()
#define LXxD_WorkList_Next void * work_Next() override
#define LXxO_WorkList_Next LXxD_WorkList_Next
#define LXxC_WorkList_Next(c) void * c::work_Next()
#define LXxD_WorkList_Split LxResult work_Split([[maybe_unused]] unsigned mode, [[maybe_unused]] void **ppvObj) override
#define LXxO_WorkList_Split LXxD_WorkList_Split
#define LXxC_WorkList_Split(c) LxResult c::work_Split([[maybe_unused]] unsigned mode, [[maybe_unused]] void **ppvObj)
#define LXxD_WorkList_Clear void work_Clear() override
#define LXxO_WorkList_Clear LXxD_WorkList_Clear
#define LXxC_WorkList_Clear(c) void c::work_Clear()

template <class T>
class CLxIfc_WorkList: public CLxInterface
{
public:
    CLxIfc_WorkList()
    {
        vt.IsEmpty = IsEmpty;
        vt.Next = Next;
        vt.Split = Split;
        vt.Clear = Clear;
        vTable = &vt.iunk;
        iid = &lx::guid_WorkList;
    }

    static auto IsEmpty(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_WorkList, loc);
        try
        {
           return loc->work_IsEmpty();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Next(LXtObjectID wcom) -> void *
    {
        LXCWxINST (CLxImpl_WorkList, loc);
        return loc->work_Next();
    }

    static auto Split(LXtObjectID wcom,unsigned mode,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_WorkList, loc);
        try
        {
           return loc->work_Split( mode, ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Clear(LXtObjectID wcom) -> void
    {
        LXCWxINST (CLxImpl_WorkList, loc);
        loc->work_Clear();
    }

private:
    ILxWorkList vt;
};

class CLxLoc_WorkList : public CLxLocalize<ILxWorkListID>
{
public:
    CLxLoc_WorkList()
    {
        _init();
    }

    CLxLoc_WorkList(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_WorkList(CLxLoc_WorkList const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_WorkList;
    }

    auto IsEmpty(void) -> LxResult
    {
        return m_loc[0]->IsEmpty(m_loc);
    }

    auto Next(void) -> void *
    {
        return m_loc[0]->Next(m_loc);
    }

    auto Split(unsigned mode, void **ppvObj) -> LxResult
    {
        return m_loc[0]->Split(m_loc, mode, ppvObj);
    }

    auto Split(unsigned mode, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Split(m_loc, mode, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Clear(void) -> void
    {
        m_loc[0]->Clear(m_loc);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_ThreadMutex : public CLxLocalize<ILxThreadMutexID>
{
public:
    CLxLoc_ThreadMutex()
    {
        _init();
    }

    CLxLoc_ThreadMutex(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_ThreadMutex(CLxLoc_ThreadMutex const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_ThreadMutex;
    }

    auto Enter(void) -> void
    {
        m_loc[0]->Enter(m_loc);
    }

    auto Leave(void) -> void
    {
        m_loc[0]->Leave(m_loc);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_ThreadService : public CLxLocalizedService
{
public:
    ILxThreadServiceID m_loc{ nullptr };

public:
    CLxLoc_ThreadService()
    {
        _init();
        set();
    }

    ~CLxLoc_ThreadService() = default;

    void set()
    {
        if (!m_loc)
        {
            m_loc = reinterpret_cast<ILxThreadServiceID>(lx::GetGlobal(&lx::guid_ThreadService));
        }
    }

    auto CreateMutex(void **ppvObj) -> LxResult
    {
        return m_loc[0]->CreateMutex(m_loc, ppvObj);
    }

    auto CreateMutex(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->CreateMutex(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto CreateCS(void **ppvObj) -> LxResult
    {
        return m_loc[0]->CreateCS(m_loc, ppvObj);
    }

    auto CreateCS(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->CreateCS(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto CreateGroup(void **ppvObj) -> LxResult
    {
        return m_loc[0]->CreateGroup(m_loc, ppvObj);
    }

    auto CreateGroup(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->CreateGroup(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto NumProcs(void) -> unsigned int
    {
        return m_loc[0]->NumProcs(m_loc);
    }

    auto IsMainThread(void) -> unsigned int
    {
        return m_loc[0]->IsMainThread(m_loc);
    }

    auto CreateSlot(size_t size, ILxUnknownID client, void **ppvObj) -> LxResult
    {
        return m_loc[0]->CreateSlot(m_loc, size,(ILxUnknownID) client, ppvObj);
    }

    auto CreateSlot(size_t size, ILxUnknownID client, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->CreateSlot(m_loc, size,(ILxUnknownID) client, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto ProcessShared(ILxUnknownID shared) -> LxResult
    {
        return m_loc[0]->ProcessShared(m_loc,(ILxUnknownID) shared);
    }

    auto ProcessRange(void *data, int startIndex, int endIndex, ILxUnknownID rangeWorker) -> LxResult
    {
        return m_loc[0]->ProcessRange(m_loc, data, startIndex, endIndex,(ILxUnknownID) rangeWorker);
    }

    auto InitThread(void) const -> LxResult
    {
        return m_loc[0]->InitThread(m_loc);
    }

    auto CleanupThread(void) const -> LxResult
    {
        return m_loc[0]->CleanupThread(m_loc);
    }

    auto ProcessWaterfall(ILxUnknownID waterfall, unsigned threads) -> LxResult
    {
        return m_loc[0]->ProcessWaterfall(m_loc,(ILxUnknownID) waterfall, threads);
    }

    auto AtomicIncrement(volatile int *addr) -> int
    {
        return m_loc[0]->AtomicIncrement(m_loc, addr);
    }

    auto AtomicDecrement(volatile int *addr) -> int
    {
        return m_loc[0]->AtomicDecrement(m_loc, addr);
    }

    auto AtomicIntegerAdd(volatile int *addr, int val) -> int
    {
        return m_loc[0]->AtomicIntegerAdd(m_loc, addr, val);
    }

    auto AtomicIntegerSubtract(volatile int *addr, int val) -> int
    {
        return m_loc[0]->AtomicIntegerSubtract(m_loc, addr, val);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_ThreadJob
{
public:
    virtual ~CLxImpl_ThreadJob() = default;

    virtual void job_Execute([[maybe_unused]] void)
    {
    }
};

#define LXxD_ThreadJob_Execute void job_Execute() override
#define LXxO_ThreadJob_Execute LXxD_ThreadJob_Execute
#define LXxC_ThreadJob_Execute(c) void c::job_Execute()

template <class T>
class CLxIfc_ThreadJob: public CLxInterface
{
public:
    CLxIfc_ThreadJob()
    {
        vt.Execute = Execute;
        vTable = &vt.iunk;
        iid = &lx::guid_ThreadJob;
    }

    static auto Execute(LXtObjectID wcom) -> void
    {
        LXCWxINST (CLxImpl_ThreadJob, loc);
        loc->job_Execute();
    }

private:
    ILxThreadJob vt;
};

class CLxLoc_ThreadJob : public CLxLocalize<ILxThreadJobID>
{
public:
    CLxLoc_ThreadJob()
    {
        _init();
    }

    CLxLoc_ThreadJob(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_ThreadJob(CLxLoc_ThreadJob const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_ThreadJob;
    }

    auto Execute(void) -> void
    {
        m_loc[0]->Execute(m_loc);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_ThreadGroup : public CLxLocalize<ILxThreadGroupID>
{
public:
    CLxLoc_ThreadGroup()
    {
        _init();
    }

    CLxLoc_ThreadGroup(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_ThreadGroup(CLxLoc_ThreadGroup const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_ThreadGroup;
    }

    auto AddJob(ILxUnknownID job) -> void
    {
        m_loc[0]->AddJob(m_loc,(ILxUnknownID) job);
    }

    auto NumJobs(void) -> unsigned
    {
        return m_loc[0]->NumJobs(m_loc);
    }

    auto Clear(void) -> void
    {
        m_loc[0]->Clear(m_loc);
    }

    auto Execute(void) -> void
    {
        m_loc[0]->Execute(m_loc);
    }

    auto Wait(void) -> void
    {
        m_loc[0]->Wait(m_loc);
    }

    auto Running(void) -> LxResult
    {
        return m_loc[0]->Running(m_loc);
    }

    auto Kill(void) -> void
    {
        m_loc[0]->Kill(m_loc);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_ThreadSlot : public CLxLocalize<ILxThreadSlotID>
{
public:
    CLxLoc_ThreadSlot()
    {
        _init();
    }

    CLxLoc_ThreadSlot(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_ThreadSlot(CLxLoc_ThreadSlot const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_ThreadSlot;
    }

    auto Set(void *value) -> LxResult
    {
        return m_loc[0]->Set(m_loc, value);
    }

    auto Get(void **value) -> LxResult
    {
        return m_loc[0]->Get(m_loc, value);
    }

    auto Clear(void) -> LxResult
    {
        return m_loc[0]->Clear(m_loc);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_ThreadSlotClient
{
public:
    virtual ~CLxImpl_ThreadSlotClient() = default;

    virtual auto tsc_Alloc([[maybe_unused]] void **value) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto tsc_Free([[maybe_unused]] void *value) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_ThreadSlotClient_Alloc LxResult tsc_Alloc([[maybe_unused]] void **value) override
#define LXxO_ThreadSlotClient_Alloc LXxD_ThreadSlotClient_Alloc
#define LXxC_ThreadSlotClient_Alloc(c) LxResult c::tsc_Alloc([[maybe_unused]] void **value)
#define LXxD_ThreadSlotClient_Free LxResult tsc_Free([[maybe_unused]] void *value) override
#define LXxO_ThreadSlotClient_Free LXxD_ThreadSlotClient_Free
#define LXxC_ThreadSlotClient_Free(c) LxResult c::tsc_Free([[maybe_unused]] void *value)

template <class T>
class CLxIfc_ThreadSlotClient: public CLxInterface
{
public:
    CLxIfc_ThreadSlotClient()
    {
        vt.Alloc = Alloc;
        vt.Free = Free;
        vTable = &vt.iunk;
        iid = &lx::guid_ThreadSlotClient;
    }

    static auto Alloc(LXtObjectID wcom,void **value) -> LxResult
    {
        LXCWxINST (CLxImpl_ThreadSlotClient, loc);
        try
        {
           return loc->tsc_Alloc( value);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Free(LXtObjectID wcom,void *value) -> LxResult
    {
        LXCWxINST (CLxImpl_ThreadSlotClient, loc);
        try
        {
           return loc->tsc_Free( value);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxThreadSlotClient vt;
};

class CLxLoc_ThreadSlotClient : public CLxLocalize<ILxThreadSlotClientID>
{
public:
    CLxLoc_ThreadSlotClient()
    {
        _init();
    }

    CLxLoc_ThreadSlotClient(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_ThreadSlotClient(CLxLoc_ThreadSlotClient const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_ThreadSlotClient;
    }

    auto Alloc(void **value) -> LxResult
    {
        return m_loc[0]->Alloc(m_loc, value);
    }

    auto Free(void *value) -> LxResult
    {
        return m_loc[0]->Free(m_loc, value);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_SharedWork
{
public:
    virtual ~CLxImpl_SharedWork() = default;

    virtual auto share_Evaluate([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto share_Spawn([[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto share_Share([[maybe_unused]] ILxUnknownID other, [[maybe_unused]] unsigned int split) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_SharedWork_Evaluate LxResult share_Evaluate() override
#define LXxO_SharedWork_Evaluate LXxD_SharedWork_Evaluate
#define LXxC_SharedWork_Evaluate(c) LxResult c::share_Evaluate()
#define LXxD_SharedWork_Spawn LxResult share_Spawn([[maybe_unused]] void **ppvObj) override
#define LXxO_SharedWork_Spawn LXxD_SharedWork_Spawn
#define LXxC_SharedWork_Spawn(c) LxResult c::share_Spawn([[maybe_unused]] void **ppvObj)
#define LXxD_SharedWork_Share LxResult share_Share([[maybe_unused]] ILxUnknownID other, [[maybe_unused]] unsigned int split) override
#define LXxO_SharedWork_Share LXxD_SharedWork_Share
#define LXxC_SharedWork_Share(c) LxResult c::share_Share([[maybe_unused]] ILxUnknownID other, [[maybe_unused]] unsigned int split)

template <class T>
class CLxIfc_SharedWork: public CLxInterface
{
public:
    CLxIfc_SharedWork()
    {
        vt.Evaluate = Evaluate;
        vt.Spawn = Spawn;
        vt.Share = Share;
        vTable = &vt.iunk;
        iid = &lx::guid_SharedWork;
    }

    static auto Evaluate(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_SharedWork, loc);
        try
        {
           return loc->share_Evaluate();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Spawn(LXtObjectID wcom,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_SharedWork, loc);
        try
        {
           return loc->share_Spawn( ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Share(LXtObjectID wcom,LXtObjectID other,unsigned int split) -> LxResult
    {
        LXCWxINST (CLxImpl_SharedWork, loc);
        try
        {
           return loc->share_Share((ILxUnknownID) other, split);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxSharedWork vt;
};

class CLxLoc_SharedWork : public CLxLocalize<ILxSharedWorkID>
{
public:
    CLxLoc_SharedWork()
    {
        _init();
    }

    CLxLoc_SharedWork(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_SharedWork(CLxLoc_SharedWork const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_SharedWork;
    }

    auto Evaluate(void) -> LxResult
    {
        return m_loc[0]->Evaluate(m_loc);
    }

    auto Spawn(void **ppvObj) -> LxResult
    {
        return m_loc[0]->Spawn(m_loc, ppvObj);
    }

    auto Spawn(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Spawn(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Share(ILxUnknownID other, unsigned int split) -> LxResult
    {
        return m_loc[0]->Share(m_loc,(ILxUnknownID) other, split);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_ThreadRangeWorker
{
public:
    virtual ~CLxImpl_ThreadRangeWorker() = default;

    virtual auto rngw_Execute([[maybe_unused]] int index, [[maybe_unused]] void *sharedData) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_ThreadRangeWorker_Execute LxResult rngw_Execute([[maybe_unused]] int index, [[maybe_unused]] void *sharedData) override
#define LXxO_ThreadRangeWorker_Execute LXxD_ThreadRangeWorker_Execute
#define LXxC_ThreadRangeWorker_Execute(c) LxResult c::rngw_Execute([[maybe_unused]] int index, [[maybe_unused]] void *sharedData)

template <class T>
class CLxIfc_ThreadRangeWorker: public CLxInterface
{
public:
    CLxIfc_ThreadRangeWorker()
    {
        vt.Execute = Execute;
        vTable = &vt.iunk;
        iid = &lx::guid_ThreadRangeWorker;
    }

    static auto Execute(LXtObjectID wcom,int index,void *sharedData) -> LxResult
    {
        LXCWxINST (CLxImpl_ThreadRangeWorker, loc);
        try
        {
           return loc->rngw_Execute( index, sharedData);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxThreadRangeWorker vt;
};

class CLxLoc_ThreadRangeWorker : public CLxLocalize<ILxThreadRangeWorkerID>
{
public:
    CLxLoc_ThreadRangeWorker()
    {
        _init();
    }

    CLxLoc_ThreadRangeWorker(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_ThreadRangeWorker(CLxLoc_ThreadRangeWorker const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_ThreadRangeWorker;
    }

    auto Execute(int index, void *sharedData) -> LxResult
    {
        return m_loc[0]->Execute(m_loc, index, sharedData);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_Waterfall
{
public:
    virtual ~CLxImpl_Waterfall() = default;

    virtual auto wfall_Spawn([[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual unsigned wfall_State(void) = 0;

    virtual auto wfall_ProcessWork([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto wfall_GetWork([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto wfall_Advance([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_Waterfall_Spawn LxResult wfall_Spawn([[maybe_unused]] void **ppvObj) override
#define LXxO_Waterfall_Spawn LXxD_Waterfall_Spawn
#define LXxC_Waterfall_Spawn(c) LxResult c::wfall_Spawn([[maybe_unused]] void **ppvObj)
#define LXxD_Waterfall_State unsigned wfall_State() override
#define LXxO_Waterfall_State LXxD_Waterfall_State
#define LXxC_Waterfall_State(c) unsigned c::wfall_State()
#define LXxD_Waterfall_ProcessWork LxResult wfall_ProcessWork() override
#define LXxO_Waterfall_ProcessWork LXxD_Waterfall_ProcessWork
#define LXxC_Waterfall_ProcessWork(c) LxResult c::wfall_ProcessWork()
#define LXxD_Waterfall_GetWork LxResult wfall_GetWork() override
#define LXxO_Waterfall_GetWork LXxD_Waterfall_GetWork
#define LXxC_Waterfall_GetWork(c) LxResult c::wfall_GetWork()
#define LXxD_Waterfall_Advance LxResult wfall_Advance() override
#define LXxO_Waterfall_Advance LXxD_Waterfall_Advance
#define LXxC_Waterfall_Advance(c) LxResult c::wfall_Advance()

template <class T>
class CLxIfc_Waterfall: public CLxInterface
{
public:
    CLxIfc_Waterfall()
    {
        vt.Spawn = Spawn;
        vt.State = State;
        vt.ProcessWork = ProcessWork;
        vt.GetWork = GetWork;
        vt.Advance = Advance;
        vTable = &vt.iunk;
        iid = &lx::guid_Waterfall;
    }

    static auto Spawn(LXtObjectID wcom,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_Waterfall, loc);
        try
        {
           return loc->wfall_Spawn( ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto State(LXtObjectID wcom) -> unsigned
    {
        LXCWxINST (CLxImpl_Waterfall, loc);
        return loc->wfall_State();
    }

    static auto ProcessWork(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_Waterfall, loc);
        try
        {
           return loc->wfall_ProcessWork();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto GetWork(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_Waterfall, loc);
        try
        {
           return loc->wfall_GetWork();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Advance(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_Waterfall, loc);
        try
        {
           return loc->wfall_Advance();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxWaterfall vt;
};

class CLxLoc_Waterfall : public CLxLocalize<ILxWaterfallID>
{
public:
    CLxLoc_Waterfall()
    {
        _init();
    }

    CLxLoc_Waterfall(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_Waterfall(CLxLoc_Waterfall const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_Waterfall;
    }

    auto Spawn(void **ppvObj) -> LxResult
    {
        return m_loc[0]->Spawn(m_loc, ppvObj);
    }

    auto Spawn(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Spawn(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto State(void) -> unsigned
    {
        return m_loc[0]->State(m_loc);
    }

    auto ProcessWork(void) -> LxResult
    {
        return m_loc[0]->ProcessWork(m_loc);
    }

    auto GetWork(void) -> LxResult
    {
        return m_loc[0]->GetWork(m_loc);
    }

    auto Advance(void) -> LxResult
    {
        return m_loc[0]->Advance(m_loc);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
