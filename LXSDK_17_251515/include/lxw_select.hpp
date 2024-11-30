//
// C++ wrapper for lxsdk/lxselect.h.
//
//	Copyright 2024.
//
//
#pragma once

#include <lxselect.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx
{
    static LXtGUID const guid_SelectionType = {0x6f0E612B, {0x4462, 0x43B5}, {0x84, 0xD3, 0xA6, 0xFC, 0xA7, 0xC8, 0xEF, 0x94}};
    static LXtGUID const guid_SelectionListener = {0x32E1B478, {0xF2F6, 0x41A8}, {0x9D, 0x79, 0x14, 0x91, 0x9B, 0x79, 0x3A, 0xFE}};
    static LXtGUID const guid_SelectionService = {0x6AEF6F27, {0x046F, 0x4C04}, {0x90, 0xE0, 0x99, 0x4D, 0x74, 0x28, 0x51, 0xE7}};
    static LXtGUID const guid_SelectionPacket1Service = {0x58D8DEAD, {0x3B0C, 0x41FB}, {0xAC, 0x1E, 0xB1, 0x7A, 0x36, 0x52, 0x1D, 0x44}};
} // namespace lx

class CLxImpl_SelectionType
{
public:
    virtual ~CLxImpl_SelectionType() = default;

    virtual unsigned int seltyp_Size(void) = 0;

    virtual unsigned int seltyp_Flags(void) = 0;

    virtual const char * seltyp_MessageTable(void) = 0;

    virtual int seltyp_Compare(void *pkey, void *pelt) = 0;

    virtual auto seltyp_SubType([[maybe_unused]] void *pkt) -> unsigned int
    {
        return 0;
    }
};

#define LXxD_SelectionType_Size unsigned int seltyp_Size() override
#define LXxO_SelectionType_Size LXxD_SelectionType_Size
#define LXxC_SelectionType_Size(c) unsigned int c::seltyp_Size()
#define LXxD_SelectionType_Flags unsigned int seltyp_Flags() override
#define LXxO_SelectionType_Flags LXxD_SelectionType_Flags
#define LXxC_SelectionType_Flags(c) unsigned int c::seltyp_Flags()
#define LXxD_SelectionType_MessageTable const char * seltyp_MessageTable() override
#define LXxO_SelectionType_MessageTable LXxD_SelectionType_MessageTable
#define LXxC_SelectionType_MessageTable(c) const char * c::seltyp_MessageTable()
#define LXxD_SelectionType_Compare int seltyp_Compare([[maybe_unused]] void *pkey, [[maybe_unused]] void *pelt) override
#define LXxO_SelectionType_Compare LXxD_SelectionType_Compare
#define LXxC_SelectionType_Compare(c) int c::seltyp_Compare([[maybe_unused]] void *pkey, [[maybe_unused]] void *pelt)
#define LXxD_SelectionType_SubType unsigned int seltyp_SubType([[maybe_unused]] void *pkt) override
#define LXxO_SelectionType_SubType LXxD_SelectionType_SubType
#define LXxC_SelectionType_SubType(c) unsigned int c::seltyp_SubType([[maybe_unused]] void *pkt)

template <class T>
class CLxIfc_SelectionType: public CLxInterface
{
public:
    CLxIfc_SelectionType()
    {
        vt.Size = Size;
        vt.Flags = Flags;
        vt.MessageTable = MessageTable;
        vt.Compare = Compare;
        vt.SubType = SubType;
        vTable = &vt.iunk;
        iid = &lx::guid_SelectionType;
    }

    static auto Size(LXtObjectID wcom) -> unsigned int
    {
        LXCWxINST (CLxImpl_SelectionType, loc);
        return loc->seltyp_Size();
    }

    static auto Flags(LXtObjectID wcom) -> unsigned int
    {
        LXCWxINST (CLxImpl_SelectionType, loc);
        return loc->seltyp_Flags();
    }

    static auto MessageTable(LXtObjectID wcom) -> const char *
    {
        LXCWxINST (CLxImpl_SelectionType, loc);
        return loc->seltyp_MessageTable();
    }

    static auto Compare(LXtObjectID wcom,void *pkey,void *pelt) -> int
    {
        LXCWxINST (CLxImpl_SelectionType, loc);
        return loc->seltyp_Compare( pkey, pelt);
    }

    static auto SubType(LXtObjectID wcom,void *pkt) -> unsigned int
    {
        LXCWxINST (CLxImpl_SelectionType, loc);
        return loc->seltyp_SubType( pkt);
    }

private:
    ILxSelectionType vt;
};

class CLxLoc_SelectionType : public CLxLocalize<ILxSelectionTypeID>
{
public:
    CLxLoc_SelectionType()
    {
        _init();
    }

    CLxLoc_SelectionType(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_SelectionType(CLxLoc_SelectionType const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_SelectionType;
    }

    auto Size(void) -> unsigned int
    {
        return m_loc[0]->Size(m_loc);
    }

    auto Flags(void) -> unsigned int
    {
        return m_loc[0]->Flags(m_loc);
    }

    auto MessageTable(void) -> const char *
    {
        return m_loc[0]->MessageTable(m_loc);
    }

    auto Compare(void *pkey, void *pelt) -> int
    {
        return m_loc[0]->Compare(m_loc, pkey, pelt);
    }

    auto SubType(void *pkt) -> unsigned int
    {
        return m_loc[0]->SubType(m_loc, pkt);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_SelectionListener
{
public:
    virtual ~CLxImpl_SelectionListener() = default;

    virtual void selevent_Current([[maybe_unused]] LXtID4 type)
    {
    }

    virtual void selevent_Add([[maybe_unused]] LXtID4 type, [[maybe_unused]] unsigned int subtType)
    {
    }

    virtual void selevent_Remove([[maybe_unused]] LXtID4 type, [[maybe_unused]] unsigned int subtType)
    {
    }

    virtual void selevent_Time([[maybe_unused]] double time)
    {
    }

    virtual void selevent_TimeRange([[maybe_unused]] LXtID4 type)
    {
    }
};

#define LXxD_SelectionListener_Current void selevent_Current([[maybe_unused]] LXtID4 type) override
#define LXxO_SelectionListener_Current LXxD_SelectionListener_Current
#define LXxC_SelectionListener_Current(c) void c::selevent_Current([[maybe_unused]] LXtID4 type)
#define LXxD_SelectionListener_Add void selevent_Add([[maybe_unused]] LXtID4 type, [[maybe_unused]] unsigned int subtType) override
#define LXxO_SelectionListener_Add LXxD_SelectionListener_Add
#define LXxC_SelectionListener_Add(c) void c::selevent_Add([[maybe_unused]] LXtID4 type, [[maybe_unused]] unsigned int subtType)
#define LXxD_SelectionListener_Remove void selevent_Remove([[maybe_unused]] LXtID4 type, [[maybe_unused]] unsigned int subtType) override
#define LXxO_SelectionListener_Remove LXxD_SelectionListener_Remove
#define LXxC_SelectionListener_Remove(c) void c::selevent_Remove([[maybe_unused]] LXtID4 type, [[maybe_unused]] unsigned int subtType)
#define LXxD_SelectionListener_Time void selevent_Time([[maybe_unused]] double time) override
#define LXxO_SelectionListener_Time LXxD_SelectionListener_Time
#define LXxC_SelectionListener_Time(c) void c::selevent_Time([[maybe_unused]] double time)
#define LXxD_SelectionListener_TimeRange void selevent_TimeRange([[maybe_unused]] LXtID4 type) override
#define LXxO_SelectionListener_TimeRange LXxD_SelectionListener_TimeRange
#define LXxC_SelectionListener_TimeRange(c) void c::selevent_TimeRange([[maybe_unused]] LXtID4 type)

template <class T>
class CLxIfc_SelectionListener: public CLxInterface
{
public:
    CLxIfc_SelectionListener()
    {
        vt.Current = Current;
        vt.Add = Add;
        vt.Remove = Remove;
        vt.Time = Time;
        vt.TimeRange = TimeRange;
        vTable = &vt.iunk;
        iid = &lx::guid_SelectionListener;
    }

    static auto Current(LXtObjectID wcom,LXtID4 type) -> void
    {
        LXCWxINST (CLxImpl_SelectionListener, loc);
        loc->selevent_Current( type);
    }

    static auto Add(LXtObjectID wcom,LXtID4 type,unsigned int subtType) -> void
    {
        LXCWxINST (CLxImpl_SelectionListener, loc);
        loc->selevent_Add( type, subtType);
    }

    static auto Remove(LXtObjectID wcom,LXtID4 type,unsigned int subtType) -> void
    {
        LXCWxINST (CLxImpl_SelectionListener, loc);
        loc->selevent_Remove( type, subtType);
    }

    static auto Time(LXtObjectID wcom,double time) -> void
    {
        LXCWxINST (CLxImpl_SelectionListener, loc);
        loc->selevent_Time( time);
    }

    static auto TimeRange(LXtObjectID wcom,LXtID4 type) -> void
    {
        LXCWxINST (CLxImpl_SelectionListener, loc);
        loc->selevent_TimeRange( type);
    }

private:
    ILxSelectionListener vt;
};

class CLxLoc_SelectionListener : public CLxLocalize<ILxSelectionListenerID>
{
public:
    CLxLoc_SelectionListener()
    {
        _init();
    }

    CLxLoc_SelectionListener(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_SelectionListener(CLxLoc_SelectionListener const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_SelectionListener;
    }

    auto Current(LXtID4 type) -> void
    {
        m_loc[0]->Current(m_loc, type);
    }

    auto Add(LXtID4 type, unsigned int subtType) -> void
    {
        m_loc[0]->Add(m_loc, type, subtType);
    }

    auto Remove(LXtID4 type, unsigned int subtType) -> void
    {
        m_loc[0]->Remove(m_loc, type, subtType);
    }

    auto Time(double time) -> void
    {
        m_loc[0]->Time(m_loc, time);
    }

    auto TimeRange(LXtID4 type) -> void
    {
        m_loc[0]->TimeRange(m_loc, type);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_SelectionService : public CLxLocalizedService
{
public:
    ILxSelectionServiceID m_loc{ nullptr };

public:
    CLxLoc_SelectionService()
    {
        _init();
        set();
    }

    ~CLxLoc_SelectionService() = default;

    void set()
    {
        if (!m_loc)
        {
            m_loc = reinterpret_cast<ILxSelectionServiceID>(lx::GetGlobal(&lx::guid_SelectionService));
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

    auto Count(LXtID4 type) -> int
    {
        return m_loc[0]->Count(m_loc, type);
    }

    auto ByIndex(LXtID4 type, unsigned int idx) -> void *
    {
        return m_loc[0]->ByIndex(m_loc, type, idx);
    }

    auto Recent(LXtID4 type) -> void *
    {
        return m_loc[0]->Recent(m_loc, type);
    }

    auto Test(LXtID4 type, void *packet) -> LxResult
    {
        return m_loc[0]->Test(m_loc, type, packet);
    }

    auto ScanLoop(LXtScanInfoID scan, LXtID4 type, void **packet) -> LXtScanInfoID
    {
        return m_loc[0]->ScanLoop(m_loc, scan, type, packet);
    }

    auto ScanLoopCurrent(LXtScanInfoID scan, LXtID4 type, void **packet) -> LXtScanInfoID
    {
        return m_loc[0]->ScanLoopCurrent(m_loc, scan, type, packet);
    }

    auto Select(LXtID4 type, void *packet) -> LxResult
    {
        return m_loc[0]->Select(m_loc, type, packet);
    }

    auto Deselect(LXtID4 type, void *packet) -> LxResult
    {
        return m_loc[0]->Deselect(m_loc, type, packet);
    }

    auto Remove(LXtID4 type, void *packet) -> LxResult
    {
        return m_loc[0]->Remove(m_loc, type, packet);
    }

    auto Toggle(LXtID4 type, void *packet) -> LxResult
    {
        return m_loc[0]->Toggle(m_loc, type, packet);
    }

    auto Drop(LXtID4 type) -> LxResult
    {
        return m_loc[0]->Drop(m_loc, type);
    }

    auto StartBatch(void) -> LxResult
    {
        return m_loc[0]->StartBatch(m_loc);
    }

    auto EndBatch(void) -> LxResult
    {
        return m_loc[0]->EndBatch(m_loc);
    }

    auto AbortBatch(void) -> LxResult
    {
        return m_loc[0]->AbortBatch(m_loc);
    }

    auto LookupName(LXtID4 type) -> const char *
    {
        return m_loc[0]->LookupName(m_loc, type);
    }

    auto LookupType(const char *name) -> LXtID4
    {
        return m_loc[0]->LookupType(m_loc, name);
    }

    auto Allocate(const char *name, void **ppvObj) -> LxResult
    {
        return m_loc[0]->Allocate(m_loc, name, ppvObj);
    }

    auto Allocate(const char *name, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Allocate(m_loc, name, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto GetTime(void) -> double
    {
        return m_loc[0]->GetTime(m_loc);
    }

    auto SetTime(double time) -> LxResult
    {
        return m_loc[0]->SetTime(m_loc, time);
    }

    auto Clear(LXtID4 type) -> LxResult
    {
        return m_loc[0]->Clear(m_loc, type);
    }

    auto State(LXtID4 type, void *packet) -> int
    {
        return m_loc[0]->State(m_loc, type, packet);
    }

    auto CurrentType(const LXtID4 *types) -> LXtID4
    {
        return m_loc[0]->CurrentType(m_loc, types);
    }

    auto CurrentSubTypes(LXtID4 type, unsigned *sub, unsigned len, unsigned *num) -> LxResult
    {
        return m_loc[0]->CurrentSubTypes(m_loc, type, sub, len, num);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};

