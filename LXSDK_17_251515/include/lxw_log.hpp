//
// C++ wrapper for lxsdk/lxlog.h.
//
//	Copyright 2024.
//
//
#pragma once

#include <lxlog.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx
{
    static LXtGUID const guid_LogService = {0x0BC355C2, {0x5E6B, 0x49EF}, {0xB3, 0x68, 0x60, 0x0D, 0x9F, 0x26, 0xF5, 0x43}};
    static LXtGUID const guid_LogInfoBlock = {0xB9AEE11A, {0x3501, 0x4dc2}, {0x90, 0xA6, 0x41, 0xF2, 0x43, 0x58, 0x56, 0xC6}};
    static LXtGUID const guid_Log = {0x1890538F, {0xD64C, 0x478c}, {0x84, 0x72, 0x22, 0x8B, 0x7C, 0x9A, 0xB1, 0xDF}};
    static LXtGUID const guid_LogEntry = {0xE83679B2, {0xDB4D, 0x4D90}, {0xB8, 0x1B, 0x5F, 0x78, 0x6D, 0x21, 0x2F, 0xB3}};
    static LXtGUID const guid_LogListener = {0xc5fd260b, {0xcab7, 0x4283}, {0xb8, 0x76, 0x23, 0x14, 0x14, 0x4a, 0xe8, 0x3a}};
} // namespace lx

class CLxLoc_LogService : public CLxLocalizedService
{
public:
    ILxLogServiceID m_loc{ nullptr };

public:
    CLxLoc_LogService()
    {
        _init();
        set();
    }

    ~CLxLoc_LogService() = default;

    void set()
    {
        if (!m_loc)
        {
            m_loc = reinterpret_cast<ILxLogServiceID>(lx::GetGlobal(&lx::guid_LogService));
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

    auto SubSystemCount(unsigned int *count) -> LxResult
    {
        return m_loc[0]->SubSystemCount(m_loc, count);
    }

    auto SubSystemByIndex(unsigned int index, void **ppvObj) -> LxResult
    {
        return m_loc[0]->SubSystemByIndex(m_loc, index, ppvObj);
    }

    auto SubSystemByIndex(unsigned int index, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->SubSystemByIndex(m_loc, index, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto SubSystemLookup(const char *name, void **ppvObj) -> LxResult
    {
        return m_loc[0]->SubSystemLookup(m_loc, name, ppvObj);
    }

    auto SubSystemLookup(const char *name, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->SubSystemLookup(m_loc, name, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto PrimarySubSystem(void **ppvObj) -> LxResult
    {
        return m_loc[0]->PrimarySubSystem(m_loc, ppvObj);
    }

    auto PrimarySubSystem(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->PrimarySubSystem(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto InfoBlockCount(unsigned int *count) -> LxResult
    {
        return m_loc[0]->InfoBlockCount(m_loc, count);
    }

    auto InfoBlockByIndex(unsigned int index, void **ppvObj) -> LxResult
    {
        return m_loc[0]->InfoBlockByIndex(m_loc, index, ppvObj);
    }

    auto InfoBlockByIndex(unsigned int index, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->InfoBlockByIndex(m_loc, index, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto InfoBlockLookup(const char *name, void **ppvObj) -> LxResult
    {
        return m_loc[0]->InfoBlockLookup(m_loc, name, ppvObj);
    }

    auto InfoBlockLookup(const char *name, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->InfoBlockLookup(m_loc, name, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto InfoBlockFieldsAreSameGroup(const char *name1, const char *name2) -> LxResult
    {
        return m_loc[0]->InfoBlockFieldsAreSameGroup(m_loc, name1, name2);
    }

    auto InfoBlockFieldGetParts(const char *name, const char **group, const char **sub) -> LxResult
    {
        return m_loc[0]->InfoBlockFieldGetParts(m_loc, name, group, sub);
    }

    auto CreateEntryMessage(LxResult type, const char *message, void **ppvObj) -> LxResult
    {
        return m_loc[0]->CreateEntryMessage(m_loc, type, message, ppvObj);
    }

    auto CreateEntryMessage(LxResult type, const char *message, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->CreateEntryMessage(m_loc, type, message, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto CreateEntryInfoBlock(LxResult type, const char *blockName, void **ppvObj) -> LxResult
    {
        return m_loc[0]->CreateEntryInfoBlock(m_loc, type, blockName, ppvObj);
    }

    auto CreateEntryInfoBlock(LxResult type, const char *blockName, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->CreateEntryInfoBlock(m_loc, type, blockName, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto CreateEntryPaired(LxResult type, void **ppvObj) -> LxResult
    {
        return m_loc[0]->CreateEntryPaired(m_loc, type, ppvObj);
    }

    auto CreateEntryPaired(LxResult type, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->CreateEntryPaired(m_loc, type, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto SetMonitor(ILxUnknownID monitor) -> LxResult
    {
        return m_loc[0]->SetMonitor(m_loc,(ILxUnknownID) monitor);
    }

    auto AcquireMonitor(void) -> ILxUnknownID
    {
        return (ILxUnknownID)m_loc[0]->AcquireMonitor(m_loc);
    }

    auto EnableLogging(const char *systemName, unsigned int state) -> LxResult
    {
        return m_loc[0]->EnableLogging(m_loc, systemName, state);
    }

    auto IsLoggingEnabled(const char *systemName) -> LxResult
    {
        return m_loc[0]->IsLoggingEnabled(m_loc, systemName);
    }

    auto CreateEntryMessageFromMsgObj(ILxUnknownID msgObj, void **ppvObj) -> LxResult
    {
        return m_loc[0]->CreateEntryMessageFromMsgObj(m_loc,(ILxUnknownID) msgObj, ppvObj);
    }

    auto CreateEntryMessageFromMsgObj(ILxUnknownID msgObj, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->CreateEntryMessageFromMsgObj(m_loc,(ILxUnknownID) msgObj, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto DebugLogOutput(unsigned int level, const char *line) -> LxResult
    {
        return m_loc[0]->DebugLogOutput(m_loc, level, line);
    }

    auto DebugLogOutputSys(unsigned int level, const char *logSystem, const char *line) -> LxResult
    {
        return m_loc[0]->DebugLogOutputSys(m_loc, level, logSystem, line);
    }

    auto ExceptionMessage(LxResult error, unsigned flags) -> ILxUnknownID
    {
        return (ILxUnknownID)m_loc[0]->ExceptionMessage(m_loc, error, flags);
    }

    auto ExceptionBlockStart(void) -> LxResult
    {
        return m_loc[0]->ExceptionBlockStart(m_loc);
    }

    auto ExceptionBlockCollect(void **ppvObj) -> LxResult
    {
        return m_loc[0]->ExceptionBlockCollect(m_loc, ppvObj);
    }

    auto ExceptionBlockCollect(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->ExceptionBlockCollect(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto ReplaceEntryMessage(ILxUnknownID logEntry, LxResult type, const char *msg) -> LxResult
    {
        return m_loc[0]->ReplaceEntryMessage(m_loc,(ILxUnknownID) logEntry, type, msg);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_LogInfoBlock
{
public:
    virtual ~CLxImpl_LogInfoBlock() = default;

    virtual auto lb_Name([[maybe_unused]] const char **name) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto lb_FieldCount([[maybe_unused]] unsigned int *count) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto lb_FieldName([[maybe_unused]] unsigned int index, [[maybe_unused]] const char **name) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto lb_FieldType([[maybe_unused]] unsigned int index, [[maybe_unused]] const char **type) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_LogInfoBlock_Name LxResult lb_Name([[maybe_unused]] const char **name) override
#define LXxO_LogInfoBlock_Name LXxD_LogInfoBlock_Name
#define LXxC_LogInfoBlock_Name(c) LxResult c::lb_Name([[maybe_unused]] const char **name)
#define LXxD_LogInfoBlock_FieldCount LxResult lb_FieldCount([[maybe_unused]] unsigned int *count) override
#define LXxO_LogInfoBlock_FieldCount LXxD_LogInfoBlock_FieldCount
#define LXxC_LogInfoBlock_FieldCount(c) LxResult c::lb_FieldCount([[maybe_unused]] unsigned int *count)
#define LXxD_LogInfoBlock_FieldName LxResult lb_FieldName([[maybe_unused]] unsigned int index, [[maybe_unused]] const char **name) override
#define LXxO_LogInfoBlock_FieldName LXxD_LogInfoBlock_FieldName
#define LXxC_LogInfoBlock_FieldName(c) LxResult c::lb_FieldName([[maybe_unused]] unsigned int index, [[maybe_unused]] const char **name)
#define LXxD_LogInfoBlock_FieldType LxResult lb_FieldType([[maybe_unused]] unsigned int index, [[maybe_unused]] const char **type) override
#define LXxO_LogInfoBlock_FieldType LXxD_LogInfoBlock_FieldType
#define LXxC_LogInfoBlock_FieldType(c) LxResult c::lb_FieldType([[maybe_unused]] unsigned int index, [[maybe_unused]] const char **type)

template <class T>
class CLxIfc_LogInfoBlock: public CLxInterface
{
public:
    CLxIfc_LogInfoBlock()
    {
        vt.Name = Name;
        vt.FieldCount = FieldCount;
        vt.FieldName = FieldName;
        vt.FieldType = FieldType;
        vTable = &vt.iunk;
        iid = &lx::guid_LogInfoBlock;
    }

    static auto Name(LXtObjectID wcom,const char **name) -> LxResult
    {
        LXCWxINST (CLxImpl_LogInfoBlock, loc);
        try
        {
           return loc->lb_Name( name);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto FieldCount(LXtObjectID wcom,unsigned int *count) -> LxResult
    {
        LXCWxINST (CLxImpl_LogInfoBlock, loc);
        try
        {
           return loc->lb_FieldCount( count);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto FieldName(LXtObjectID wcom,unsigned int index,const char **name) -> LxResult
    {
        LXCWxINST (CLxImpl_LogInfoBlock, loc);
        try
        {
           return loc->lb_FieldName( index, name);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto FieldType(LXtObjectID wcom,unsigned int index,const char **type) -> LxResult
    {
        LXCWxINST (CLxImpl_LogInfoBlock, loc);
        try
        {
           return loc->lb_FieldType( index, type);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxLogInfoBlock vt;
};

class CLxLoc_LogInfoBlock : public CLxLocalize<ILxLogInfoBlockID>
{
public:
    CLxLoc_LogInfoBlock()
    {
        _init();
    }

    CLxLoc_LogInfoBlock(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_LogInfoBlock(CLxLoc_LogInfoBlock const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_LogInfoBlock;
    }

    auto Name(const char **name) -> LxResult
    {
        return m_loc[0]->Name(m_loc, name);
    }

    auto FieldCount(unsigned int *count) -> LxResult
    {
        return m_loc[0]->FieldCount(m_loc, count);
    }

    auto FieldName(unsigned int index, const char **name) -> LxResult
    {
        return m_loc[0]->FieldName(m_loc, index, name);
    }

    auto FieldType(unsigned int index, const char **type) -> LxResult
    {
        return m_loc[0]->FieldType(m_loc, index, type);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_Log : public CLxLocalize<ILxLogID>
{
public:
    CLxLoc_Log()
    {
        _init();
    }

    CLxLoc_Log(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_Log(CLxLoc_Log const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_Log;
    }

    auto AddEntry(ILxUnknownID entry) -> LxResult
    {
        return m_loc[0]->AddEntry(m_loc,(ILxUnknownID) entry);
    }

    auto RollEntry(ILxUnknownID entry) -> LxResult
    {
        return m_loc[0]->RollEntry(m_loc,(ILxUnknownID) entry);
    }

    auto RollClear(void) -> LxResult
    {
        return m_loc[0]->RollClear(m_loc);
    }

    auto EntryCount(unsigned int *count) -> LxResult
    {
        return m_loc[0]->EntryCount(m_loc, count);
    }

    auto EntryByIndex(unsigned int index, void **ppvObj) -> LxResult
    {
        return m_loc[0]->EntryByIndex(m_loc, index, ppvObj);
    }

    auto EntryByIndex(unsigned int index, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->EntryByIndex(m_loc, index, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto PeekEntryByIndex(unsigned int index) -> ILxUnknownID
    {
        return (ILxUnknownID)m_loc[0]->PeekEntryByIndex(m_loc, index);
    }

    auto GetCurrentEntry(void **ppvObj) -> LxResult
    {
        return m_loc[0]->GetCurrentEntry(m_loc, ppvObj);
    }

    auto GetCurrentEntry(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->GetCurrentEntry(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto SetMaxEntries(unsigned int max) -> LxResult
    {
        return m_loc[0]->SetMaxEntries(m_loc, max);
    }

    auto GetMaxEntries(unsigned int *max) -> LxResult
    {
        return m_loc[0]->GetMaxEntries(m_loc, max);
    }

    auto GetRolling(void **ppvObj) -> LxResult
    {
        return m_loc[0]->GetRolling(m_loc, ppvObj);
    }

    auto GetRolling(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->GetRolling(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto ClearAll(void) -> LxResult
    {
        return m_loc[0]->ClearAll(m_loc);
    }

    auto ClearOrdinal(uint64_t ordinal) -> LxResult
    {
        return m_loc[0]->ClearOrdinal(m_loc, ordinal);
    }

    auto Name(const char **name) -> LxResult
    {
        return m_loc[0]->Name(m_loc, name);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_LogEntry : public CLxLocalize<ILxLogEntryID>
{
public:
    CLxLoc_LogEntry()
    {
        _init();
    }

    CLxLoc_LogEntry(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_LogEntry(CLxLoc_LogEntry const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_LogEntry;
    }

    auto AddEntry(ILxUnknownID entry) -> LxResult
    {
        return m_loc[0]->AddEntry(m_loc,(ILxUnknownID) entry);
    }

    auto SetTitle(const char *title) -> LxResult
    {
        return m_loc[0]->SetTitle(m_loc, title);
    }

    auto SetDesc(const char *desc) -> LxResult
    {
        return m_loc[0]->SetDesc(m_loc, desc);
    }

    auto SetValue(const char *name, unsigned int index, ILxUnknownID value) -> LxResult
    {
        return m_loc[0]->SetValue(m_loc, name, index,(ILxUnknownID) value);
    }

    auto AddPair(const char *name, const char *value) -> LxResult
    {
        return m_loc[0]->AddPair(m_loc, name, value);
    }

    auto Class(unsigned int *classType) -> LxResult
    {
        return m_loc[0]->Class(m_loc, classType);
    }

    auto Type(LxResult *type) -> LxResult
    {
        return m_loc[0]->Type(m_loc, type);
    }

    auto Time(time_t *time) -> LxResult
    {
        return m_loc[0]->Time(m_loc, time);
    }

    auto TimeString(const char **string) -> LxResult
    {
        return m_loc[0]->TimeString(m_loc, string);
    }

    auto ChildCount(unsigned int *count) -> LxResult
    {
        return m_loc[0]->ChildCount(m_loc, count);
    }

    auto ChildByIndex(unsigned int index, void **ppvObj) -> LxResult
    {
        return m_loc[0]->ChildByIndex(m_loc, index, ppvObj);
    }

    auto ChildByIndex(unsigned int index, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->ChildByIndex(m_loc, index, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto PeekChildByIndex(unsigned int index) -> ILxUnknownID
    {
        return (ILxUnknownID)m_loc[0]->PeekChildByIndex(m_loc, index);
    }

    auto SubSystemCount(unsigned int *count) -> LxResult
    {
        return m_loc[0]->SubSystemCount(m_loc, count);
    }

    auto SubSystemByIndex(unsigned int index, void **ppvObj) -> LxResult
    {
        return m_loc[0]->SubSystemByIndex(m_loc, index, ppvObj);
    }

    auto SubSystemByIndex(unsigned int index, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->SubSystemByIndex(m_loc, index, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Message(const char **message) -> LxResult
    {
        return m_loc[0]->Message(m_loc, message);
    }

    auto Title(const char **title) -> LxResult
    {
        return m_loc[0]->Title(m_loc, title);
    }

    auto Desc(const char **desc) -> LxResult
    {
        return m_loc[0]->Desc(m_loc, desc);
    }

    auto InfoBlock(void **ppvObj) -> LxResult
    {
        return m_loc[0]->InfoBlock(m_loc, ppvObj);
    }

    auto InfoBlock(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->InfoBlock(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto InfoBlockValue(const char *name, unsigned int index, void **ppvObj) -> LxResult
    {
        return m_loc[0]->InfoBlockValue(m_loc, name, index, ppvObj);
    }

    auto InfoBlockValue(const char *name, unsigned int index, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->InfoBlockValue(m_loc, name, index, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto PairCount(unsigned int *count) -> LxResult
    {
        return m_loc[0]->PairCount(m_loc, count);
    }

    auto PairName(unsigned int index, const char **name) -> LxResult
    {
        return m_loc[0]->PairName(m_loc, index, name);
    }

    auto PairValue(unsigned int index, const char **value) -> LxResult
    {
        return m_loc[0]->PairValue(m_loc, index, value);
    }

    auto Ordinal(uint64_t *value) -> LxResult
    {
        return m_loc[0]->Ordinal(m_loc, value);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_LogListener
{
public:
    virtual ~CLxImpl_LogListener() = default;

    virtual void logevent_SystemAdded([[maybe_unused]] ILxUnknownID system)
    {
    }

    virtual void logevent_EntryAdded([[maybe_unused]] ILxUnknownID system, [[maybe_unused]] ILxUnknownID entry)
    {
    }

    virtual void logevent_ChildEntryAdded([[maybe_unused]] ILxUnknownID entry, [[maybe_unused]] ILxUnknownID parentEntry)
    {
    }

    virtual void logevent_EntryDropped([[maybe_unused]] ILxUnknownID system, [[maybe_unused]] ILxUnknownID entry)
    {
    }

    virtual void logevent_RollingEntryAdded([[maybe_unused]] ILxUnknownID system, [[maybe_unused]] ILxUnknownID entry)
    {
    }

    virtual void logevent_RollingChildEntryAdded([[maybe_unused]] ILxUnknownID entry, [[maybe_unused]] ILxUnknownID parentEntry)
    {
    }

    virtual void logevent_RollingEntryDropped([[maybe_unused]] ILxUnknownID system, [[maybe_unused]] ILxUnknownID entry)
    {
    }
};

#define LXxD_LogListener_SystemAdded void logevent_SystemAdded([[maybe_unused]] ILxUnknownID system) override
#define LXxO_LogListener_SystemAdded LXxD_LogListener_SystemAdded
#define LXxC_LogListener_SystemAdded(c) void c::logevent_SystemAdded([[maybe_unused]] ILxUnknownID system)
#define LXxD_LogListener_EntryAdded void logevent_EntryAdded([[maybe_unused]] ILxUnknownID system, [[maybe_unused]] ILxUnknownID entry) override
#define LXxO_LogListener_EntryAdded LXxD_LogListener_EntryAdded
#define LXxC_LogListener_EntryAdded(c) void c::logevent_EntryAdded([[maybe_unused]] ILxUnknownID system, [[maybe_unused]] ILxUnknownID entry)
#define LXxD_LogListener_ChildEntryAdded void logevent_ChildEntryAdded([[maybe_unused]] ILxUnknownID entry, [[maybe_unused]] ILxUnknownID parentEntry) override
#define LXxO_LogListener_ChildEntryAdded LXxD_LogListener_ChildEntryAdded
#define LXxC_LogListener_ChildEntryAdded(c) void c::logevent_ChildEntryAdded([[maybe_unused]] ILxUnknownID entry, [[maybe_unused]] ILxUnknownID parentEntry)
#define LXxD_LogListener_EntryDropped void logevent_EntryDropped([[maybe_unused]] ILxUnknownID system, [[maybe_unused]] ILxUnknownID entry) override
#define LXxO_LogListener_EntryDropped LXxD_LogListener_EntryDropped
#define LXxC_LogListener_EntryDropped(c) void c::logevent_EntryDropped([[maybe_unused]] ILxUnknownID system, [[maybe_unused]] ILxUnknownID entry)
#define LXxD_LogListener_RollingEntryAdded void logevent_RollingEntryAdded([[maybe_unused]] ILxUnknownID system, [[maybe_unused]] ILxUnknownID entry) override
#define LXxO_LogListener_RollingEntryAdded LXxD_LogListener_RollingEntryAdded
#define LXxC_LogListener_RollingEntryAdded(c) void c::logevent_RollingEntryAdded([[maybe_unused]] ILxUnknownID system, [[maybe_unused]] ILxUnknownID entry)
#define LXxD_LogListener_RollingChildEntryAdded void logevent_RollingChildEntryAdded([[maybe_unused]] ILxUnknownID entry, [[maybe_unused]] ILxUnknownID parentEntry) override
#define LXxO_LogListener_RollingChildEntryAdded LXxD_LogListener_RollingChildEntryAdded
#define LXxC_LogListener_RollingChildEntryAdded(c) void c::logevent_RollingChildEntryAdded([[maybe_unused]] ILxUnknownID entry, [[maybe_unused]] ILxUnknownID parentEntry)
#define LXxD_LogListener_RollingEntryDropped void logevent_RollingEntryDropped([[maybe_unused]] ILxUnknownID system, [[maybe_unused]] ILxUnknownID entry) override
#define LXxO_LogListener_RollingEntryDropped LXxD_LogListener_RollingEntryDropped
#define LXxC_LogListener_RollingEntryDropped(c) void c::logevent_RollingEntryDropped([[maybe_unused]] ILxUnknownID system, [[maybe_unused]] ILxUnknownID entry)

template <class T>
class CLxIfc_LogListener: public CLxInterface
{
public:
    CLxIfc_LogListener()
    {
        vt.SystemAdded = SystemAdded;
        vt.EntryAdded = EntryAdded;
        vt.ChildEntryAdded = ChildEntryAdded;
        vt.EntryDropped = EntryDropped;
        vt.RollingEntryAdded = RollingEntryAdded;
        vt.RollingChildEntryAdded = RollingChildEntryAdded;
        vt.RollingEntryDropped = RollingEntryDropped;
        vTable = &vt.iunk;
        iid = &lx::guid_LogListener;
    }

    static auto SystemAdded(LXtObjectID wcom,LXtObjectID system) -> void
    {
        LXCWxINST (CLxImpl_LogListener, loc);
        loc->logevent_SystemAdded((ILxUnknownID) system);
    }

    static auto EntryAdded(LXtObjectID wcom,LXtObjectID system,LXtObjectID entry) -> void
    {
        LXCWxINST (CLxImpl_LogListener, loc);
        loc->logevent_EntryAdded((ILxUnknownID) system,(ILxUnknownID) entry);
    }

    static auto ChildEntryAdded(LXtObjectID wcom,LXtObjectID entry,LXtObjectID parentEntry) -> void
    {
        LXCWxINST (CLxImpl_LogListener, loc);
        loc->logevent_ChildEntryAdded((ILxUnknownID) entry,(ILxUnknownID) parentEntry);
    }

    static auto EntryDropped(LXtObjectID wcom,LXtObjectID system,LXtObjectID entry) -> void
    {
        LXCWxINST (CLxImpl_LogListener, loc);
        loc->logevent_EntryDropped((ILxUnknownID) system,(ILxUnknownID) entry);
    }

    static auto RollingEntryAdded(LXtObjectID wcom,LXtObjectID system,LXtObjectID entry) -> void
    {
        LXCWxINST (CLxImpl_LogListener, loc);
        loc->logevent_RollingEntryAdded((ILxUnknownID) system,(ILxUnknownID) entry);
    }

    static auto RollingChildEntryAdded(LXtObjectID wcom,LXtObjectID entry,LXtObjectID parentEntry) -> void
    {
        LXCWxINST (CLxImpl_LogListener, loc);
        loc->logevent_RollingChildEntryAdded((ILxUnknownID) entry,(ILxUnknownID) parentEntry);
    }

    static auto RollingEntryDropped(LXtObjectID wcom,LXtObjectID system,LXtObjectID entry) -> void
    {
        LXCWxINST (CLxImpl_LogListener, loc);
        loc->logevent_RollingEntryDropped((ILxUnknownID) system,(ILxUnknownID) entry);
    }

private:
    ILxLogListener vt;
};

class CLxLoc_LogListener : public CLxLocalize<ILxLogListenerID>
{
public:
    CLxLoc_LogListener()
    {
        _init();
    }

    CLxLoc_LogListener(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_LogListener(CLxLoc_LogListener const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_LogListener;
    }

    auto SystemAdded(ILxUnknownID system) -> void
    {
        m_loc[0]->SystemAdded(m_loc,(ILxUnknownID) system);
    }

    auto EntryAdded(ILxUnknownID system, ILxUnknownID entry) -> void
    {
        m_loc[0]->EntryAdded(m_loc,(ILxUnknownID) system,(ILxUnknownID) entry);
    }

    auto ChildEntryAdded(ILxUnknownID entry, ILxUnknownID parentEntry) -> void
    {
        m_loc[0]->ChildEntryAdded(m_loc,(ILxUnknownID) entry,(ILxUnknownID) parentEntry);
    }

    auto EntryDropped(ILxUnknownID system, ILxUnknownID entry) -> void
    {
        m_loc[0]->EntryDropped(m_loc,(ILxUnknownID) system,(ILxUnknownID) entry);
    }

    auto RollingEntryAdded(ILxUnknownID system, ILxUnknownID entry) -> void
    {
        m_loc[0]->RollingEntryAdded(m_loc,(ILxUnknownID) system,(ILxUnknownID) entry);
    }

    auto RollingChildEntryAdded(ILxUnknownID entry, ILxUnknownID parentEntry) -> void
    {
        m_loc[0]->RollingChildEntryAdded(m_loc,(ILxUnknownID) entry,(ILxUnknownID) parentEntry);
    }

    auto RollingEntryDropped(ILxUnknownID system, ILxUnknownID entry) -> void
    {
        m_loc[0]->RollingEntryDropped(m_loc,(ILxUnknownID) system,(ILxUnknownID) entry);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
