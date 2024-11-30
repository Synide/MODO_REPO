//
// C++ wrapper for lxsdk/lxschematic.h.
//
//	Copyright 2024.
//
//
#pragma once

#include <lxschematic.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx
{
    static LXtGUID const guid_SchematicConnection = {0x3578D79B, {0x798C, 0x4250}, {0x95, 0x38, 0xCF, 0x7E, 0xB9, 0x39, 0xBB, 0x6E}};
    static LXtGUID const guid_SchematicConnection3 = {0x38BB9ED8, {0xF21E, 0x40C1}, {0xB1, 0x18, 0xE7, 0x66, 0xF2, 0x90, 0x7E, 0x4F}};
    static LXtGUID const guid_SchematicConnection2 = {0x7E238C0E, {0x0D64, 0x44ed}, {0xA7, 0x80, 0x13, 0xD2, 0x5A, 0x24, 0x82, 0xD3}};
    static LXtGUID const guid_SchematicConnection1 = {0x5AC0A075, {0x72B7, 0x4935}, {0x8D, 0xA5, 0x58, 0x8D, 0xF7, 0x99, 0x90, 0x69}};
    static LXtGUID const guid_SchemaDest = {0xAA362F0B, {0xDC2F, 0x4480}, {0x82, 0xFF, 0x32, 0xD3, 0x8F, 0xD5, 0x7F, 0x4F}};
    static LXtGUID const guid_SchematicGroup = {0xFD5B73D1, {0xC9E2, 0x44C2}, {0x8D, 0x8D, 0x23, 0xEE, 0x77, 0x06, 0xB3, 0xAB}};
    static LXtGUID const guid_SchematicNode = {0x686F59FF, {0x1E3F, 0x4599}, {0xAD, 0xE0, 0xE3, 0x61, 0x3C, 0x48, 0x3D, 0x38}};
    static LXtGUID const guid_SchematicNodeConnection = {0x5E015AAB, {0xE069, 0x4676}, {0x8F, 0x04, 0xC7, 0xC8, 0xF8, 0x81, 0x81, 0xA5}};
    static LXtGUID const guid_SchematicNodeChannel = {0x322555CC, {0xD635, 0x48A4}, {0xBC, 0xDB, 0xAE, 0x86, 0xCC, 0xFE, 0x29, 0xCF}};
} // namespace lx

class CLxImpl_SchematicConnection
{
public:
    virtual ~CLxImpl_SchematicConnection() = default;

    virtual auto schm_ItemFlags([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned *flags) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto schm_AllowConnect([[maybe_unused]] ILxUnknownID from, [[maybe_unused]] ILxUnknownID to) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto schm_AllowConnectType([[maybe_unused]] ILxUnknownID to, [[maybe_unused]] unsigned int type) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto schm_GraphName([[maybe_unused]] const char **name) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto schm_Count([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned *count) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto schm_ByIndex([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned index, [[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto schm_Connect([[maybe_unused]] ILxUnknownID from, [[maybe_unused]] ILxUnknownID to, [[maybe_unused]] int toIndex) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto schm_Disconnect([[maybe_unused]] ILxUnknownID from, [[maybe_unused]] ILxUnknownID to) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto schm_BaseFlags([[maybe_unused]] void) -> int
    {
        return 0;
    }

    virtual auto schm_PerItemFlags([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned *flags) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto schm_ItemFlagsValid([[maybe_unused]] void) -> int
    {
        return 1;
    }

    virtual auto schm_ChannelAllowConnect([[maybe_unused]] ILxUnknownID from, [[maybe_unused]] int fromIndex, [[maybe_unused]] ILxUnknownID to, [[maybe_unused]] int toIndex) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto schm_ChannelIOType([[maybe_unused]] unsigned int *ioType) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto schm_ChannelCount([[maybe_unused]] ILxUnknownID xItem, [[maybe_unused]] int fromIndex, [[maybe_unused]] unsigned *count) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto schm_ChannelByIndex([[maybe_unused]] ILxUnknownID xItem, [[maybe_unused]] int fromIndex, [[maybe_unused]] unsigned index, [[maybe_unused]] void **ppvObj, [[maybe_unused]] int *toIndex) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto schm_ChannelConnect([[maybe_unused]] ILxUnknownID from, [[maybe_unused]] int fromIndex, [[maybe_unused]] ILxUnknownID to, [[maybe_unused]] int toIndex) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto schm_ChannelDisconnect([[maybe_unused]] ILxUnknownID from, [[maybe_unused]] int fromIndex, [[maybe_unused]] ILxUnknownID to, [[maybe_unused]] int toIndex) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto schm_PresetBrowserHash([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] const char **hash) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_SchematicConnection_ItemFlags LxResult schm_ItemFlags([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned *flags) override
#define LXxO_SchematicConnection_ItemFlags LXxD_SchematicConnection_ItemFlags
#define LXxC_SchematicConnection_ItemFlags(c) LxResult c::schm_ItemFlags([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned *flags)
#define LXxD_SchematicConnection_AllowConnect LxResult schm_AllowConnect([[maybe_unused]] ILxUnknownID from, [[maybe_unused]] ILxUnknownID to) override
#define LXxO_SchematicConnection_AllowConnect LXxD_SchematicConnection_AllowConnect
#define LXxC_SchematicConnection_AllowConnect(c) LxResult c::schm_AllowConnect([[maybe_unused]] ILxUnknownID from, [[maybe_unused]] ILxUnknownID to)
#define LXxD_SchematicConnection_AllowConnectType LxResult schm_AllowConnectType([[maybe_unused]] ILxUnknownID to, [[maybe_unused]] unsigned int type) override
#define LXxO_SchematicConnection_AllowConnectType LXxD_SchematicConnection_AllowConnectType
#define LXxC_SchematicConnection_AllowConnectType(c) LxResult c::schm_AllowConnectType([[maybe_unused]] ILxUnknownID to, [[maybe_unused]] unsigned int type)
#define LXxD_SchematicConnection_GraphName LxResult schm_GraphName([[maybe_unused]] const char **name) override
#define LXxO_SchematicConnection_GraphName LXxD_SchematicConnection_GraphName
#define LXxC_SchematicConnection_GraphName(c) LxResult c::schm_GraphName([[maybe_unused]] const char **name)
#define LXxD_SchematicConnection_Count LxResult schm_Count([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned *count) override
#define LXxO_SchematicConnection_Count LXxD_SchematicConnection_Count
#define LXxC_SchematicConnection_Count(c) LxResult c::schm_Count([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned *count)
#define LXxD_SchematicConnection_ByIndex LxResult schm_ByIndex([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned index, [[maybe_unused]] void **ppvObj) override
#define LXxO_SchematicConnection_ByIndex LXxD_SchematicConnection_ByIndex
#define LXxC_SchematicConnection_ByIndex(c) LxResult c::schm_ByIndex([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned index, [[maybe_unused]] void **ppvObj)
#define LXxD_SchematicConnection_Connect LxResult schm_Connect([[maybe_unused]] ILxUnknownID from, [[maybe_unused]] ILxUnknownID to, [[maybe_unused]] int toIndex) override
#define LXxO_SchematicConnection_Connect LXxD_SchematicConnection_Connect
#define LXxC_SchematicConnection_Connect(c) LxResult c::schm_Connect([[maybe_unused]] ILxUnknownID from, [[maybe_unused]] ILxUnknownID to, [[maybe_unused]] int toIndex)
#define LXxD_SchematicConnection_Disconnect LxResult schm_Disconnect([[maybe_unused]] ILxUnknownID from, [[maybe_unused]] ILxUnknownID to) override
#define LXxO_SchematicConnection_Disconnect LXxD_SchematicConnection_Disconnect
#define LXxC_SchematicConnection_Disconnect(c) LxResult c::schm_Disconnect([[maybe_unused]] ILxUnknownID from, [[maybe_unused]] ILxUnknownID to)
#define LXxD_SchematicConnection_BaseFlags int schm_BaseFlags() override
#define LXxO_SchematicConnection_BaseFlags LXxD_SchematicConnection_BaseFlags
#define LXxC_SchematicConnection_BaseFlags(c) int c::schm_BaseFlags()
#define LXxD_SchematicConnection_PerItemFlags LxResult schm_PerItemFlags([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned *flags) override
#define LXxO_SchematicConnection_PerItemFlags LXxD_SchematicConnection_PerItemFlags
#define LXxC_SchematicConnection_PerItemFlags(c) LxResult c::schm_PerItemFlags([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned *flags)
#define LXxD_SchematicConnection_ItemFlagsValid int schm_ItemFlagsValid() override
#define LXxO_SchematicConnection_ItemFlagsValid LXxD_SchematicConnection_ItemFlagsValid
#define LXxC_SchematicConnection_ItemFlagsValid(c) int c::schm_ItemFlagsValid()
#define LXxD_SchematicConnection_ChannelAllowConnect LxResult schm_ChannelAllowConnect([[maybe_unused]] ILxUnknownID from, [[maybe_unused]] int fromIndex, [[maybe_unused]] ILxUnknownID to, [[maybe_unused]] int toIndex) override
#define LXxO_SchematicConnection_ChannelAllowConnect LXxD_SchematicConnection_ChannelAllowConnect
#define LXxC_SchematicConnection_ChannelAllowConnect(c) LxResult c::schm_ChannelAllowConnect([[maybe_unused]] ILxUnknownID from, [[maybe_unused]] int fromIndex, [[maybe_unused]] ILxUnknownID to, [[maybe_unused]] int toIndex)
#define LXxD_SchematicConnection_ChannelIOType LxResult schm_ChannelIOType([[maybe_unused]] unsigned int *ioType) override
#define LXxO_SchematicConnection_ChannelIOType LXxD_SchematicConnection_ChannelIOType
#define LXxC_SchematicConnection_ChannelIOType(c) LxResult c::schm_ChannelIOType([[maybe_unused]] unsigned int *ioType)
#define LXxD_SchematicConnection_ChannelCount LxResult schm_ChannelCount([[maybe_unused]] ILxUnknownID xItem, [[maybe_unused]] int fromIndex, [[maybe_unused]] unsigned *count) override
#define LXxO_SchematicConnection_ChannelCount LXxD_SchematicConnection_ChannelCount
#define LXxC_SchematicConnection_ChannelCount(c) LxResult c::schm_ChannelCount([[maybe_unused]] ILxUnknownID xItem, [[maybe_unused]] int fromIndex, [[maybe_unused]] unsigned *count)
#define LXxD_SchematicConnection_ChannelByIndex LxResult schm_ChannelByIndex([[maybe_unused]] ILxUnknownID xItem, [[maybe_unused]] int fromIndex, [[maybe_unused]] unsigned index, [[maybe_unused]] void **ppvObj, [[maybe_unused]] int *toIndex) override
#define LXxO_SchematicConnection_ChannelByIndex LXxD_SchematicConnection_ChannelByIndex
#define LXxC_SchematicConnection_ChannelByIndex(c) LxResult c::schm_ChannelByIndex([[maybe_unused]] ILxUnknownID xItem, [[maybe_unused]] int fromIndex, [[maybe_unused]] unsigned index, [[maybe_unused]] void **ppvObj, [[maybe_unused]] int *toIndex)
#define LXxD_SchematicConnection_ChannelConnect LxResult schm_ChannelConnect([[maybe_unused]] ILxUnknownID from, [[maybe_unused]] int fromIndex, [[maybe_unused]] ILxUnknownID to, [[maybe_unused]] int toIndex) override
#define LXxO_SchematicConnection_ChannelConnect LXxD_SchematicConnection_ChannelConnect
#define LXxC_SchematicConnection_ChannelConnect(c) LxResult c::schm_ChannelConnect([[maybe_unused]] ILxUnknownID from, [[maybe_unused]] int fromIndex, [[maybe_unused]] ILxUnknownID to, [[maybe_unused]] int toIndex)
#define LXxD_SchematicConnection_ChannelDisconnect LxResult schm_ChannelDisconnect([[maybe_unused]] ILxUnknownID from, [[maybe_unused]] int fromIndex, [[maybe_unused]] ILxUnknownID to, [[maybe_unused]] int toIndex) override
#define LXxO_SchematicConnection_ChannelDisconnect LXxD_SchematicConnection_ChannelDisconnect
#define LXxC_SchematicConnection_ChannelDisconnect(c) LxResult c::schm_ChannelDisconnect([[maybe_unused]] ILxUnknownID from, [[maybe_unused]] int fromIndex, [[maybe_unused]] ILxUnknownID to, [[maybe_unused]] int toIndex)
#define LXxD_SchematicConnection_PresetBrowserHash LxResult schm_PresetBrowserHash([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] const char **hash) override
#define LXxO_SchematicConnection_PresetBrowserHash LXxD_SchematicConnection_PresetBrowserHash
#define LXxC_SchematicConnection_PresetBrowserHash(c) LxResult c::schm_PresetBrowserHash([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] const char **hash)

template <class T>
class CLxIfc_SchematicConnection: public CLxInterface
{
public:
    CLxIfc_SchematicConnection()
    {
        vt.ItemFlags = ItemFlags;
        vt.AllowConnect = AllowConnect;
        vt.AllowConnectType = AllowConnectType;
        vt.GraphName = GraphName;
        vt.Count = Count;
        vt.ByIndex = ByIndex;
        vt.Connect = Connect;
        vt.Disconnect = Disconnect;
        vt.BaseFlags = BaseFlags;
        vt.PerItemFlags = PerItemFlags;
        vt.ItemFlagsValid = ItemFlagsValid;
        vt.ChannelAllowConnect = ChannelAllowConnect;
        vt.ChannelIOType = ChannelIOType;
        vt.ChannelCount = ChannelCount;
        vt.ChannelByIndex = ChannelByIndex;
        vt.ChannelConnect = ChannelConnect;
        vt.ChannelDisconnect = ChannelDisconnect;
        vt.PresetBrowserHash = PresetBrowserHash;
        vTable = &vt.iunk;
        iid = &lx::guid_SchematicConnection;
    }

    static auto ItemFlags(LXtObjectID wcom,LXtObjectID item,unsigned *flags) -> LxResult
    {
        LXCWxINST (CLxImpl_SchematicConnection, loc);
        try
        {
           return loc->schm_ItemFlags((ILxUnknownID) item, flags);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto AllowConnect(LXtObjectID wcom,LXtObjectID from,LXtObjectID to) -> LxResult
    {
        LXCWxINST (CLxImpl_SchematicConnection, loc);
        try
        {
           return loc->schm_AllowConnect((ILxUnknownID) from,(ILxUnknownID) to);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto AllowConnectType(LXtObjectID wcom,LXtObjectID to,unsigned int type) -> LxResult
    {
        LXCWxINST (CLxImpl_SchematicConnection, loc);
        try
        {
           return loc->schm_AllowConnectType((ILxUnknownID) to, type);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto GraphName(LXtObjectID wcom,const char **name) -> LxResult
    {
        LXCWxINST (CLxImpl_SchematicConnection, loc);
        try
        {
           return loc->schm_GraphName( name);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Count(LXtObjectID wcom,LXtObjectID item,unsigned *count) -> LxResult
    {
        LXCWxINST (CLxImpl_SchematicConnection, loc);
        try
        {
           return loc->schm_Count((ILxUnknownID) item, count);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ByIndex(LXtObjectID wcom,LXtObjectID item,unsigned index,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_SchematicConnection, loc);
        try
        {
           return loc->schm_ByIndex((ILxUnknownID) item, index, ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Connect(LXtObjectID wcom,LXtObjectID from,LXtObjectID to,int toIndex) -> LxResult
    {
        LXCWxINST (CLxImpl_SchematicConnection, loc);
        try
        {
           return loc->schm_Connect((ILxUnknownID) from,(ILxUnknownID) to, toIndex);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Disconnect(LXtObjectID wcom,LXtObjectID from,LXtObjectID to) -> LxResult
    {
        LXCWxINST (CLxImpl_SchematicConnection, loc);
        try
        {
           return loc->schm_Disconnect((ILxUnknownID) from,(ILxUnknownID) to);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto BaseFlags(LXtObjectID wcom) -> int
    {
        LXCWxINST (CLxImpl_SchematicConnection, loc);
        return loc->schm_BaseFlags();
    }

    static auto PerItemFlags(LXtObjectID wcom,LXtObjectID item,unsigned *flags) -> LxResult
    {
        LXCWxINST (CLxImpl_SchematicConnection, loc);
        try
        {
           return loc->schm_PerItemFlags((ILxUnknownID) item, flags);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ItemFlagsValid(LXtObjectID wcom) -> int
    {
        LXCWxINST (CLxImpl_SchematicConnection, loc);
        return loc->schm_ItemFlagsValid();
    }

    static auto ChannelAllowConnect(LXtObjectID wcom,LXtObjectID from,int fromIndex,LXtObjectID to,int toIndex) -> LxResult
    {
        LXCWxINST (CLxImpl_SchematicConnection, loc);
        try
        {
           return loc->schm_ChannelAllowConnect((ILxUnknownID) from, fromIndex,(ILxUnknownID) to, toIndex);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ChannelIOType(LXtObjectID wcom,unsigned int *ioType) -> LxResult
    {
        LXCWxINST (CLxImpl_SchematicConnection, loc);
        try
        {
           return loc->schm_ChannelIOType( ioType);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ChannelCount(LXtObjectID wcom,LXtObjectID xItem,int fromIndex,unsigned *count) -> LxResult
    {
        LXCWxINST (CLxImpl_SchematicConnection, loc);
        try
        {
           return loc->schm_ChannelCount((ILxUnknownID) xItem, fromIndex, count);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ChannelByIndex(LXtObjectID wcom,LXtObjectID xItem,int fromIndex,unsigned index,void **ppvObj,int *toIndex) -> LxResult
    {
        LXCWxINST (CLxImpl_SchematicConnection, loc);
        try
        {
           return loc->schm_ChannelByIndex((ILxUnknownID) xItem, fromIndex, index, ppvObj, toIndex);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ChannelConnect(LXtObjectID wcom,LXtObjectID from,int fromIndex,LXtObjectID to,int toIndex) -> LxResult
    {
        LXCWxINST (CLxImpl_SchematicConnection, loc);
        try
        {
           return loc->schm_ChannelConnect((ILxUnknownID) from, fromIndex,(ILxUnknownID) to, toIndex);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ChannelDisconnect(LXtObjectID wcom,LXtObjectID from,int fromIndex,LXtObjectID to,int toIndex) -> LxResult
    {
        LXCWxINST (CLxImpl_SchematicConnection, loc);
        try
        {
           return loc->schm_ChannelDisconnect((ILxUnknownID) from, fromIndex,(ILxUnknownID) to, toIndex);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto PresetBrowserHash(LXtObjectID wcom,LXtObjectID item,const char **hash) -> LxResult
    {
        LXCWxINST (CLxImpl_SchematicConnection, loc);
        try
        {
           return loc->schm_PresetBrowserHash((ILxUnknownID) item, hash);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxSchematicConnection vt;
};

class CLxLoc_SchematicConnection : public CLxLocalize<ILxSchematicConnectionID>
{
public:
    CLxLoc_SchematicConnection()
    {
        _init();
    }

    CLxLoc_SchematicConnection(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_SchematicConnection(CLxLoc_SchematicConnection const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_SchematicConnection;
    }

    auto ItemFlags(ILxUnknownID item, unsigned *flags) -> LxResult
    {
        return m_loc[0]->ItemFlags(m_loc,(ILxUnknownID) item, flags);
    }

    auto AllowConnect(ILxUnknownID from, ILxUnknownID to) -> LxResult
    {
        return m_loc[0]->AllowConnect(m_loc,(ILxUnknownID) from,(ILxUnknownID) to);
    }

    auto AllowConnectType(ILxUnknownID to, unsigned int type) -> LxResult
    {
        return m_loc[0]->AllowConnectType(m_loc,(ILxUnknownID) to, type);
    }

    auto GraphName(const char **name) -> LxResult
    {
        return m_loc[0]->GraphName(m_loc, name);
    }

    auto Count(ILxUnknownID item, unsigned *count) -> LxResult
    {
        return m_loc[0]->Count(m_loc,(ILxUnknownID) item, count);
    }

    auto ByIndex(ILxUnknownID item, unsigned index, void **ppvObj) -> LxResult
    {
        return m_loc[0]->ByIndex(m_loc,(ILxUnknownID) item, index, ppvObj);
    }

    auto ByIndex(ILxUnknownID item, unsigned index, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->ByIndex(m_loc,(ILxUnknownID) item, index, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Connect(ILxUnknownID from, ILxUnknownID to, int toIndex) -> LxResult
    {
        return m_loc[0]->Connect(m_loc,(ILxUnknownID) from,(ILxUnknownID) to, toIndex);
    }

    auto Disconnect(ILxUnknownID from, ILxUnknownID to) -> LxResult
    {
        return m_loc[0]->Disconnect(m_loc,(ILxUnknownID) from,(ILxUnknownID) to);
    }

    auto BaseFlags(void) -> int
    {
        return m_loc[0]->BaseFlags(m_loc);
    }

    auto PerItemFlags(ILxUnknownID item, unsigned *flags) -> LxResult
    {
        return m_loc[0]->PerItemFlags(m_loc,(ILxUnknownID) item, flags);
    }

    auto ItemFlagsValid(void) -> int
    {
        return m_loc[0]->ItemFlagsValid(m_loc);
    }

    auto ChannelAllowConnect(ILxUnknownID from, int fromIndex, ILxUnknownID to, int toIndex) -> LxResult
    {
        return m_loc[0]->ChannelAllowConnect(m_loc,(ILxUnknownID) from, fromIndex,(ILxUnknownID) to, toIndex);
    }

    auto ChannelIOType(unsigned int *ioType) -> LxResult
    {
        return m_loc[0]->ChannelIOType(m_loc, ioType);
    }

    auto ChannelCount(ILxUnknownID xItem, int fromIndex, unsigned *count) -> LxResult
    {
        return m_loc[0]->ChannelCount(m_loc,(ILxUnknownID) xItem, fromIndex, count);
    }

    auto ChannelByIndex(ILxUnknownID xItem, int fromIndex, unsigned index, void **ppvObj, int *toIndex) -> LxResult
    {
        return m_loc[0]->ChannelByIndex(m_loc,(ILxUnknownID) xItem, fromIndex, index, ppvObj, toIndex);
    }

    auto ChannelByIndex(ILxUnknownID xItem, int fromIndex, unsigned index, CLxLocalizedObject &o_dest, int *toIndex) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->ChannelByIndex(m_loc,(ILxUnknownID) xItem, fromIndex, index, &o_obj, toIndex);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto ChannelConnect(ILxUnknownID from, int fromIndex, ILxUnknownID to, int toIndex) -> LxResult
    {
        return m_loc[0]->ChannelConnect(m_loc,(ILxUnknownID) from, fromIndex,(ILxUnknownID) to, toIndex);
    }

    auto ChannelDisconnect(ILxUnknownID from, int fromIndex, ILxUnknownID to, int toIndex) -> LxResult
    {
        return m_loc[0]->ChannelDisconnect(m_loc,(ILxUnknownID) from, fromIndex,(ILxUnknownID) to, toIndex);
    }

    auto PresetBrowserHash(ILxUnknownID item, const char **hash) -> LxResult
    {
        return m_loc[0]->PresetBrowserHash(m_loc,(ILxUnknownID) item, hash);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_SchematicConnection3
{
public:
    virtual ~CLxImpl_SchematicConnection3() = default;

    virtual auto schm_ItemFlags([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned *flags) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto schm_AllowConnect([[maybe_unused]] ILxUnknownID from, [[maybe_unused]] ILxUnknownID to) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto schm_AllowConnectType([[maybe_unused]] ILxUnknownID to, [[maybe_unused]] unsigned int type) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto schm_GraphName([[maybe_unused]] const char **name) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto schm_Count([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned *count) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto schm_ByIndex([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned index, [[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto schm_Connect([[maybe_unused]] ILxUnknownID from, [[maybe_unused]] ILxUnknownID to, [[maybe_unused]] int toIndex) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto schm_Disconnect([[maybe_unused]] ILxUnknownID from, [[maybe_unused]] ILxUnknownID to) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto schm_BaseFlags([[maybe_unused]] void) -> int
    {
        return 0;
    }

    virtual auto schm_PerItemFlags([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned *flags) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto schm_ItemFlagsValid([[maybe_unused]] void) -> int
    {
        return 1;
    }

    virtual auto schm_ChannelAllowConnect([[maybe_unused]] ILxUnknownID from, [[maybe_unused]] int fromIndex, [[maybe_unused]] ILxUnknownID to, [[maybe_unused]] int toIndex) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto schm_ChannelIOType([[maybe_unused]] unsigned int *ioType) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto schm_ChannelCount([[maybe_unused]] ILxUnknownID xItem, [[maybe_unused]] int fromIndex, [[maybe_unused]] unsigned *count) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto schm_ChannelByIndex([[maybe_unused]] ILxUnknownID xItem, [[maybe_unused]] int fromIndex, [[maybe_unused]] unsigned index, [[maybe_unused]] void **ppvObj, [[maybe_unused]] int *toIndex) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto schm_ChannelConnect([[maybe_unused]] ILxUnknownID from, [[maybe_unused]] int fromIndex, [[maybe_unused]] ILxUnknownID to, [[maybe_unused]] int toIndex) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto schm_ChannelDisconnect([[maybe_unused]] ILxUnknownID from, [[maybe_unused]] int fromIndex, [[maybe_unused]] ILxUnknownID to, [[maybe_unused]] int toIndex) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_SchematicConnection3_ItemFlags LxResult schm_ItemFlags([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned *flags) override
#define LXxO_SchematicConnection3_ItemFlags LXxD_SchematicConnection3_ItemFlags
#define LXxC_SchematicConnection3_ItemFlags(c) LxResult c::schm_ItemFlags([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned *flags)
#define LXxD_SchematicConnection3_AllowConnect LxResult schm_AllowConnect([[maybe_unused]] ILxUnknownID from, [[maybe_unused]] ILxUnknownID to) override
#define LXxO_SchematicConnection3_AllowConnect LXxD_SchematicConnection3_AllowConnect
#define LXxC_SchematicConnection3_AllowConnect(c) LxResult c::schm_AllowConnect([[maybe_unused]] ILxUnknownID from, [[maybe_unused]] ILxUnknownID to)
#define LXxD_SchematicConnection3_AllowConnectType LxResult schm_AllowConnectType([[maybe_unused]] ILxUnknownID to, [[maybe_unused]] unsigned int type) override
#define LXxO_SchematicConnection3_AllowConnectType LXxD_SchematicConnection3_AllowConnectType
#define LXxC_SchematicConnection3_AllowConnectType(c) LxResult c::schm_AllowConnectType([[maybe_unused]] ILxUnknownID to, [[maybe_unused]] unsigned int type)
#define LXxD_SchematicConnection3_GraphName LxResult schm_GraphName([[maybe_unused]] const char **name) override
#define LXxO_SchematicConnection3_GraphName LXxD_SchematicConnection3_GraphName
#define LXxC_SchematicConnection3_GraphName(c) LxResult c::schm_GraphName([[maybe_unused]] const char **name)
#define LXxD_SchematicConnection3_Count LxResult schm_Count([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned *count) override
#define LXxO_SchematicConnection3_Count LXxD_SchematicConnection3_Count
#define LXxC_SchematicConnection3_Count(c) LxResult c::schm_Count([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned *count)
#define LXxD_SchematicConnection3_ByIndex LxResult schm_ByIndex([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned index, [[maybe_unused]] void **ppvObj) override
#define LXxO_SchematicConnection3_ByIndex LXxD_SchematicConnection3_ByIndex
#define LXxC_SchematicConnection3_ByIndex(c) LxResult c::schm_ByIndex([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned index, [[maybe_unused]] void **ppvObj)
#define LXxD_SchematicConnection3_Connect LxResult schm_Connect([[maybe_unused]] ILxUnknownID from, [[maybe_unused]] ILxUnknownID to, [[maybe_unused]] int toIndex) override
#define LXxO_SchematicConnection3_Connect LXxD_SchematicConnection3_Connect
#define LXxC_SchematicConnection3_Connect(c) LxResult c::schm_Connect([[maybe_unused]] ILxUnknownID from, [[maybe_unused]] ILxUnknownID to, [[maybe_unused]] int toIndex)
#define LXxD_SchematicConnection3_Disconnect LxResult schm_Disconnect([[maybe_unused]] ILxUnknownID from, [[maybe_unused]] ILxUnknownID to) override
#define LXxO_SchematicConnection3_Disconnect LXxD_SchematicConnection3_Disconnect
#define LXxC_SchematicConnection3_Disconnect(c) LxResult c::schm_Disconnect([[maybe_unused]] ILxUnknownID from, [[maybe_unused]] ILxUnknownID to)
#define LXxD_SchematicConnection3_BaseFlags int schm_BaseFlags() override
#define LXxO_SchematicConnection3_BaseFlags LXxD_SchematicConnection3_BaseFlags
#define LXxC_SchematicConnection3_BaseFlags(c) int c::schm_BaseFlags()
#define LXxD_SchematicConnection3_PerItemFlags LxResult schm_PerItemFlags([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned *flags) override
#define LXxO_SchematicConnection3_PerItemFlags LXxD_SchematicConnection3_PerItemFlags
#define LXxC_SchematicConnection3_PerItemFlags(c) LxResult c::schm_PerItemFlags([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned *flags)
#define LXxD_SchematicConnection3_ItemFlagsValid int schm_ItemFlagsValid() override
#define LXxO_SchematicConnection3_ItemFlagsValid LXxD_SchematicConnection3_ItemFlagsValid
#define LXxC_SchematicConnection3_ItemFlagsValid(c) int c::schm_ItemFlagsValid()
#define LXxD_SchematicConnection3_ChannelAllowConnect LxResult schm_ChannelAllowConnect([[maybe_unused]] ILxUnknownID from, [[maybe_unused]] int fromIndex, [[maybe_unused]] ILxUnknownID to, [[maybe_unused]] int toIndex) override
#define LXxO_SchematicConnection3_ChannelAllowConnect LXxD_SchematicConnection3_ChannelAllowConnect
#define LXxC_SchematicConnection3_ChannelAllowConnect(c) LxResult c::schm_ChannelAllowConnect([[maybe_unused]] ILxUnknownID from, [[maybe_unused]] int fromIndex, [[maybe_unused]] ILxUnknownID to, [[maybe_unused]] int toIndex)
#define LXxD_SchematicConnection3_ChannelIOType LxResult schm_ChannelIOType([[maybe_unused]] unsigned int *ioType) override
#define LXxO_SchematicConnection3_ChannelIOType LXxD_SchematicConnection3_ChannelIOType
#define LXxC_SchematicConnection3_ChannelIOType(c) LxResult c::schm_ChannelIOType([[maybe_unused]] unsigned int *ioType)
#define LXxD_SchematicConnection3_ChannelCount LxResult schm_ChannelCount([[maybe_unused]] ILxUnknownID xItem, [[maybe_unused]] int fromIndex, [[maybe_unused]] unsigned *count) override
#define LXxO_SchematicConnection3_ChannelCount LXxD_SchematicConnection3_ChannelCount
#define LXxC_SchematicConnection3_ChannelCount(c) LxResult c::schm_ChannelCount([[maybe_unused]] ILxUnknownID xItem, [[maybe_unused]] int fromIndex, [[maybe_unused]] unsigned *count)
#define LXxD_SchematicConnection3_ChannelByIndex LxResult schm_ChannelByIndex([[maybe_unused]] ILxUnknownID xItem, [[maybe_unused]] int fromIndex, [[maybe_unused]] unsigned index, [[maybe_unused]] void **ppvObj, [[maybe_unused]] int *toIndex) override
#define LXxO_SchematicConnection3_ChannelByIndex LXxD_SchematicConnection3_ChannelByIndex
#define LXxC_SchematicConnection3_ChannelByIndex(c) LxResult c::schm_ChannelByIndex([[maybe_unused]] ILxUnknownID xItem, [[maybe_unused]] int fromIndex, [[maybe_unused]] unsigned index, [[maybe_unused]] void **ppvObj, [[maybe_unused]] int *toIndex)
#define LXxD_SchematicConnection3_ChannelConnect LxResult schm_ChannelConnect([[maybe_unused]] ILxUnknownID from, [[maybe_unused]] int fromIndex, [[maybe_unused]] ILxUnknownID to, [[maybe_unused]] int toIndex) override
#define LXxO_SchematicConnection3_ChannelConnect LXxD_SchematicConnection3_ChannelConnect
#define LXxC_SchematicConnection3_ChannelConnect(c) LxResult c::schm_ChannelConnect([[maybe_unused]] ILxUnknownID from, [[maybe_unused]] int fromIndex, [[maybe_unused]] ILxUnknownID to, [[maybe_unused]] int toIndex)
#define LXxD_SchematicConnection3_ChannelDisconnect LxResult schm_ChannelDisconnect([[maybe_unused]] ILxUnknownID from, [[maybe_unused]] int fromIndex, [[maybe_unused]] ILxUnknownID to, [[maybe_unused]] int toIndex) override
#define LXxO_SchematicConnection3_ChannelDisconnect LXxD_SchematicConnection3_ChannelDisconnect
#define LXxC_SchematicConnection3_ChannelDisconnect(c) LxResult c::schm_ChannelDisconnect([[maybe_unused]] ILxUnknownID from, [[maybe_unused]] int fromIndex, [[maybe_unused]] ILxUnknownID to, [[maybe_unused]] int toIndex)

template <class T>
class CLxIfc_SchematicConnection3: public CLxInterface
{
public:
    CLxIfc_SchematicConnection3()
    {
        vt.ItemFlags = ItemFlags;
        vt.AllowConnect = AllowConnect;
        vt.AllowConnectType = AllowConnectType;
        vt.GraphName = GraphName;
        vt.Count = Count;
        vt.ByIndex = ByIndex;
        vt.Connect = Connect;
        vt.Disconnect = Disconnect;
        vt.BaseFlags = BaseFlags;
        vt.PerItemFlags = PerItemFlags;
        vt.ItemFlagsValid = ItemFlagsValid;
        vt.ChannelAllowConnect = ChannelAllowConnect;
        vt.ChannelIOType = ChannelIOType;
        vt.ChannelCount = ChannelCount;
        vt.ChannelByIndex = ChannelByIndex;
        vt.ChannelConnect = ChannelConnect;
        vt.ChannelDisconnect = ChannelDisconnect;
        vTable = &vt.iunk;
        iid = &lx::guid_SchematicConnection3;
    }

    static auto ItemFlags(LXtObjectID wcom,LXtObjectID item,unsigned *flags) -> LxResult
    {
        LXCWxINST (CLxImpl_SchematicConnection3, loc);
        try
        {
           return loc->schm_ItemFlags((ILxUnknownID) item, flags);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto AllowConnect(LXtObjectID wcom,LXtObjectID from,LXtObjectID to) -> LxResult
    {
        LXCWxINST (CLxImpl_SchematicConnection3, loc);
        try
        {
           return loc->schm_AllowConnect((ILxUnknownID) from,(ILxUnknownID) to);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto AllowConnectType(LXtObjectID wcom,LXtObjectID to,unsigned int type) -> LxResult
    {
        LXCWxINST (CLxImpl_SchematicConnection3, loc);
        try
        {
           return loc->schm_AllowConnectType((ILxUnknownID) to, type);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto GraphName(LXtObjectID wcom,const char **name) -> LxResult
    {
        LXCWxINST (CLxImpl_SchematicConnection3, loc);
        try
        {
           return loc->schm_GraphName( name);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Count(LXtObjectID wcom,LXtObjectID item,unsigned *count) -> LxResult
    {
        LXCWxINST (CLxImpl_SchematicConnection3, loc);
        try
        {
           return loc->schm_Count((ILxUnknownID) item, count);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ByIndex(LXtObjectID wcom,LXtObjectID item,unsigned index,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_SchematicConnection3, loc);
        try
        {
           return loc->schm_ByIndex((ILxUnknownID) item, index, ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Connect(LXtObjectID wcom,LXtObjectID from,LXtObjectID to,int toIndex) -> LxResult
    {
        LXCWxINST (CLxImpl_SchematicConnection3, loc);
        try
        {
           return loc->schm_Connect((ILxUnknownID) from,(ILxUnknownID) to, toIndex);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Disconnect(LXtObjectID wcom,LXtObjectID from,LXtObjectID to) -> LxResult
    {
        LXCWxINST (CLxImpl_SchematicConnection3, loc);
        try
        {
           return loc->schm_Disconnect((ILxUnknownID) from,(ILxUnknownID) to);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto BaseFlags(LXtObjectID wcom) -> int
    {
        LXCWxINST (CLxImpl_SchematicConnection3, loc);
        return loc->schm_BaseFlags();
    }

    static auto PerItemFlags(LXtObjectID wcom,LXtObjectID item,unsigned *flags) -> LxResult
    {
        LXCWxINST (CLxImpl_SchematicConnection3, loc);
        try
        {
           return loc->schm_PerItemFlags((ILxUnknownID) item, flags);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ItemFlagsValid(LXtObjectID wcom) -> int
    {
        LXCWxINST (CLxImpl_SchematicConnection3, loc);
        return loc->schm_ItemFlagsValid();
    }

    static auto ChannelAllowConnect(LXtObjectID wcom,LXtObjectID from,int fromIndex,LXtObjectID to,int toIndex) -> LxResult
    {
        LXCWxINST (CLxImpl_SchematicConnection3, loc);
        try
        {
           return loc->schm_ChannelAllowConnect((ILxUnknownID) from, fromIndex,(ILxUnknownID) to, toIndex);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ChannelIOType(LXtObjectID wcom,unsigned int *ioType) -> LxResult
    {
        LXCWxINST (CLxImpl_SchematicConnection3, loc);
        try
        {
           return loc->schm_ChannelIOType( ioType);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ChannelCount(LXtObjectID wcom,LXtObjectID xItem,int fromIndex,unsigned *count) -> LxResult
    {
        LXCWxINST (CLxImpl_SchematicConnection3, loc);
        try
        {
           return loc->schm_ChannelCount((ILxUnknownID) xItem, fromIndex, count);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ChannelByIndex(LXtObjectID wcom,LXtObjectID xItem,int fromIndex,unsigned index,void **ppvObj,int *toIndex) -> LxResult
    {
        LXCWxINST (CLxImpl_SchematicConnection3, loc);
        try
        {
           return loc->schm_ChannelByIndex((ILxUnknownID) xItem, fromIndex, index, ppvObj, toIndex);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ChannelConnect(LXtObjectID wcom,LXtObjectID from,int fromIndex,LXtObjectID to,int toIndex) -> LxResult
    {
        LXCWxINST (CLxImpl_SchematicConnection3, loc);
        try
        {
           return loc->schm_ChannelConnect((ILxUnknownID) from, fromIndex,(ILxUnknownID) to, toIndex);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ChannelDisconnect(LXtObjectID wcom,LXtObjectID from,int fromIndex,LXtObjectID to,int toIndex) -> LxResult
    {
        LXCWxINST (CLxImpl_SchematicConnection3, loc);
        try
        {
           return loc->schm_ChannelDisconnect((ILxUnknownID) from, fromIndex,(ILxUnknownID) to, toIndex);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxSchematicConnection3 vt;
};

class CLxLoc_SchematicConnection3 : public CLxLocalize<ILxSchematicConnection3ID>
{
public:
    CLxLoc_SchematicConnection3()
    {
        _init();
    }

    CLxLoc_SchematicConnection3(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_SchematicConnection3(CLxLoc_SchematicConnection3 const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_SchematicConnection3;
    }

    auto ItemFlags(ILxUnknownID item, unsigned *flags) -> LxResult
    {
        return m_loc[0]->ItemFlags(m_loc,(ILxUnknownID) item, flags);
    }

    auto AllowConnect(ILxUnknownID from, ILxUnknownID to) -> LxResult
    {
        return m_loc[0]->AllowConnect(m_loc,(ILxUnknownID) from,(ILxUnknownID) to);
    }

    auto AllowConnectType(ILxUnknownID to, unsigned int type) -> LxResult
    {
        return m_loc[0]->AllowConnectType(m_loc,(ILxUnknownID) to, type);
    }

    auto GraphName(const char **name) -> LxResult
    {
        return m_loc[0]->GraphName(m_loc, name);
    }

    auto Count(ILxUnknownID item, unsigned *count) -> LxResult
    {
        return m_loc[0]->Count(m_loc,(ILxUnknownID) item, count);
    }

    auto ByIndex(ILxUnknownID item, unsigned index, void **ppvObj) -> LxResult
    {
        return m_loc[0]->ByIndex(m_loc,(ILxUnknownID) item, index, ppvObj);
    }

    auto ByIndex(ILxUnknownID item, unsigned index, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->ByIndex(m_loc,(ILxUnknownID) item, index, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Connect(ILxUnknownID from, ILxUnknownID to, int toIndex) -> LxResult
    {
        return m_loc[0]->Connect(m_loc,(ILxUnknownID) from,(ILxUnknownID) to, toIndex);
    }

    auto Disconnect(ILxUnknownID from, ILxUnknownID to) -> LxResult
    {
        return m_loc[0]->Disconnect(m_loc,(ILxUnknownID) from,(ILxUnknownID) to);
    }

    auto BaseFlags(void) -> int
    {
        return m_loc[0]->BaseFlags(m_loc);
    }

    auto PerItemFlags(ILxUnknownID item, unsigned *flags) -> LxResult
    {
        return m_loc[0]->PerItemFlags(m_loc,(ILxUnknownID) item, flags);
    }

    auto ItemFlagsValid(void) -> int
    {
        return m_loc[0]->ItemFlagsValid(m_loc);
    }

    auto ChannelAllowConnect(ILxUnknownID from, int fromIndex, ILxUnknownID to, int toIndex) -> LxResult
    {
        return m_loc[0]->ChannelAllowConnect(m_loc,(ILxUnknownID) from, fromIndex,(ILxUnknownID) to, toIndex);
    }

    auto ChannelIOType(unsigned int *ioType) -> LxResult
    {
        return m_loc[0]->ChannelIOType(m_loc, ioType);
    }

    auto ChannelCount(ILxUnknownID xItem, int fromIndex, unsigned *count) -> LxResult
    {
        return m_loc[0]->ChannelCount(m_loc,(ILxUnknownID) xItem, fromIndex, count);
    }

    auto ChannelByIndex(ILxUnknownID xItem, int fromIndex, unsigned index, void **ppvObj, int *toIndex) -> LxResult
    {
        return m_loc[0]->ChannelByIndex(m_loc,(ILxUnknownID) xItem, fromIndex, index, ppvObj, toIndex);
    }

    auto ChannelByIndex(ILxUnknownID xItem, int fromIndex, unsigned index, CLxLocalizedObject &o_dest, int *toIndex) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->ChannelByIndex(m_loc,(ILxUnknownID) xItem, fromIndex, index, &o_obj, toIndex);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto ChannelConnect(ILxUnknownID from, int fromIndex, ILxUnknownID to, int toIndex) -> LxResult
    {
        return m_loc[0]->ChannelConnect(m_loc,(ILxUnknownID) from, fromIndex,(ILxUnknownID) to, toIndex);
    }

    auto ChannelDisconnect(ILxUnknownID from, int fromIndex, ILxUnknownID to, int toIndex) -> LxResult
    {
        return m_loc[0]->ChannelDisconnect(m_loc,(ILxUnknownID) from, fromIndex,(ILxUnknownID) to, toIndex);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_SchematicConnection2
{
public:
    virtual ~CLxImpl_SchematicConnection2() = default;

    virtual auto schm_ItemFlags([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned *flags) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto schm_AllowConnect([[maybe_unused]] ILxUnknownID from, [[maybe_unused]] ILxUnknownID to) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto schm_AllowConnectType([[maybe_unused]] ILxUnknownID to, [[maybe_unused]] unsigned int type) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto schm_GraphName([[maybe_unused]] const char **name) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto schm_Count([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned *count) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto schm_ByIndex([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned index, [[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto schm_Connect([[maybe_unused]] ILxUnknownID from, [[maybe_unused]] ILxUnknownID to, [[maybe_unused]] int toIndex) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto schm_Disconnect([[maybe_unused]] ILxUnknownID from, [[maybe_unused]] ILxUnknownID to) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto schm_BaseFlags([[maybe_unused]] void) -> int
    {
        return 0;
    }

    virtual auto schm_PerItemFlags([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned *flags) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto schm_ItemFlagsValid([[maybe_unused]] void) -> int
    {
        return 1;
    }
};

#define LXxD_SchematicConnection2_ItemFlags LxResult schm_ItemFlags([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned *flags) override
#define LXxO_SchematicConnection2_ItemFlags LXxD_SchematicConnection2_ItemFlags
#define LXxC_SchematicConnection2_ItemFlags(c) LxResult c::schm_ItemFlags([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned *flags)
#define LXxD_SchematicConnection2_AllowConnect LxResult schm_AllowConnect([[maybe_unused]] ILxUnknownID from, [[maybe_unused]] ILxUnknownID to) override
#define LXxO_SchematicConnection2_AllowConnect LXxD_SchematicConnection2_AllowConnect
#define LXxC_SchematicConnection2_AllowConnect(c) LxResult c::schm_AllowConnect([[maybe_unused]] ILxUnknownID from, [[maybe_unused]] ILxUnknownID to)
#define LXxD_SchematicConnection2_AllowConnectType LxResult schm_AllowConnectType([[maybe_unused]] ILxUnknownID to, [[maybe_unused]] unsigned int type) override
#define LXxO_SchematicConnection2_AllowConnectType LXxD_SchematicConnection2_AllowConnectType
#define LXxC_SchematicConnection2_AllowConnectType(c) LxResult c::schm_AllowConnectType([[maybe_unused]] ILxUnknownID to, [[maybe_unused]] unsigned int type)
#define LXxD_SchematicConnection2_GraphName LxResult schm_GraphName([[maybe_unused]] const char **name) override
#define LXxO_SchematicConnection2_GraphName LXxD_SchematicConnection2_GraphName
#define LXxC_SchematicConnection2_GraphName(c) LxResult c::schm_GraphName([[maybe_unused]] const char **name)
#define LXxD_SchematicConnection2_Count LxResult schm_Count([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned *count) override
#define LXxO_SchematicConnection2_Count LXxD_SchematicConnection2_Count
#define LXxC_SchematicConnection2_Count(c) LxResult c::schm_Count([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned *count)
#define LXxD_SchematicConnection2_ByIndex LxResult schm_ByIndex([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned index, [[maybe_unused]] void **ppvObj) override
#define LXxO_SchematicConnection2_ByIndex LXxD_SchematicConnection2_ByIndex
#define LXxC_SchematicConnection2_ByIndex(c) LxResult c::schm_ByIndex([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned index, [[maybe_unused]] void **ppvObj)
#define LXxD_SchematicConnection2_Connect LxResult schm_Connect([[maybe_unused]] ILxUnknownID from, [[maybe_unused]] ILxUnknownID to, [[maybe_unused]] int toIndex) override
#define LXxO_SchematicConnection2_Connect LXxD_SchematicConnection2_Connect
#define LXxC_SchematicConnection2_Connect(c) LxResult c::schm_Connect([[maybe_unused]] ILxUnknownID from, [[maybe_unused]] ILxUnknownID to, [[maybe_unused]] int toIndex)
#define LXxD_SchematicConnection2_Disconnect LxResult schm_Disconnect([[maybe_unused]] ILxUnknownID from, [[maybe_unused]] ILxUnknownID to) override
#define LXxO_SchematicConnection2_Disconnect LXxD_SchematicConnection2_Disconnect
#define LXxC_SchematicConnection2_Disconnect(c) LxResult c::schm_Disconnect([[maybe_unused]] ILxUnknownID from, [[maybe_unused]] ILxUnknownID to)
#define LXxD_SchematicConnection2_BaseFlags int schm_BaseFlags() override
#define LXxO_SchematicConnection2_BaseFlags LXxD_SchematicConnection2_BaseFlags
#define LXxC_SchematicConnection2_BaseFlags(c) int c::schm_BaseFlags()
#define LXxD_SchematicConnection2_PerItemFlags LxResult schm_PerItemFlags([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned *flags) override
#define LXxO_SchematicConnection2_PerItemFlags LXxD_SchematicConnection2_PerItemFlags
#define LXxC_SchematicConnection2_PerItemFlags(c) LxResult c::schm_PerItemFlags([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned *flags)
#define LXxD_SchematicConnection2_ItemFlagsValid int schm_ItemFlagsValid() override
#define LXxO_SchematicConnection2_ItemFlagsValid LXxD_SchematicConnection2_ItemFlagsValid
#define LXxC_SchematicConnection2_ItemFlagsValid(c) int c::schm_ItemFlagsValid()

template <class T>
class CLxIfc_SchematicConnection2: public CLxInterface
{
public:
    CLxIfc_SchematicConnection2()
    {
        vt.ItemFlags = ItemFlags;
        vt.AllowConnect = AllowConnect;
        vt.AllowConnectType = AllowConnectType;
        vt.GraphName = GraphName;
        vt.Count = Count;
        vt.ByIndex = ByIndex;
        vt.Connect = Connect;
        vt.Disconnect = Disconnect;
        vt.BaseFlags = BaseFlags;
        vt.PerItemFlags = PerItemFlags;
        vt.ItemFlagsValid = ItemFlagsValid;
        vTable = &vt.iunk;
        iid = &lx::guid_SchematicConnection2;
    }

    static auto ItemFlags(LXtObjectID wcom,LXtObjectID item,unsigned *flags) -> LxResult
    {
        LXCWxINST (CLxImpl_SchematicConnection2, loc);
        try
        {
           return loc->schm_ItemFlags((ILxUnknownID) item, flags);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto AllowConnect(LXtObjectID wcom,LXtObjectID from,LXtObjectID to) -> LxResult
    {
        LXCWxINST (CLxImpl_SchematicConnection2, loc);
        try
        {
           return loc->schm_AllowConnect((ILxUnknownID) from,(ILxUnknownID) to);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto AllowConnectType(LXtObjectID wcom,LXtObjectID to,unsigned int type) -> LxResult
    {
        LXCWxINST (CLxImpl_SchematicConnection2, loc);
        try
        {
           return loc->schm_AllowConnectType((ILxUnknownID) to, type);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto GraphName(LXtObjectID wcom,const char **name) -> LxResult
    {
        LXCWxINST (CLxImpl_SchematicConnection2, loc);
        try
        {
           return loc->schm_GraphName( name);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Count(LXtObjectID wcom,LXtObjectID item,unsigned *count) -> LxResult
    {
        LXCWxINST (CLxImpl_SchematicConnection2, loc);
        try
        {
           return loc->schm_Count((ILxUnknownID) item, count);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ByIndex(LXtObjectID wcom,LXtObjectID item,unsigned index,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_SchematicConnection2, loc);
        try
        {
           return loc->schm_ByIndex((ILxUnknownID) item, index, ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Connect(LXtObjectID wcom,LXtObjectID from,LXtObjectID to,int toIndex) -> LxResult
    {
        LXCWxINST (CLxImpl_SchematicConnection2, loc);
        try
        {
           return loc->schm_Connect((ILxUnknownID) from,(ILxUnknownID) to, toIndex);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Disconnect(LXtObjectID wcom,LXtObjectID from,LXtObjectID to) -> LxResult
    {
        LXCWxINST (CLxImpl_SchematicConnection2, loc);
        try
        {
           return loc->schm_Disconnect((ILxUnknownID) from,(ILxUnknownID) to);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto BaseFlags(LXtObjectID wcom) -> int
    {
        LXCWxINST (CLxImpl_SchematicConnection2, loc);
        return loc->schm_BaseFlags();
    }

    static auto PerItemFlags(LXtObjectID wcom,LXtObjectID item,unsigned *flags) -> LxResult
    {
        LXCWxINST (CLxImpl_SchematicConnection2, loc);
        try
        {
           return loc->schm_PerItemFlags((ILxUnknownID) item, flags);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ItemFlagsValid(LXtObjectID wcom) -> int
    {
        LXCWxINST (CLxImpl_SchematicConnection2, loc);
        return loc->schm_ItemFlagsValid();
    }

private:
    ILxSchematicConnection2 vt;
};

class CLxLoc_SchematicConnection2 : public CLxLocalize<ILxSchematicConnection2ID>
{
public:
    CLxLoc_SchematicConnection2()
    {
        _init();
    }

    CLxLoc_SchematicConnection2(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_SchematicConnection2(CLxLoc_SchematicConnection2 const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_SchematicConnection2;
    }

    auto ItemFlags(ILxUnknownID item, unsigned *flags) -> LxResult
    {
        return m_loc[0]->ItemFlags(m_loc,(ILxUnknownID) item, flags);
    }

    auto AllowConnect(ILxUnknownID from, ILxUnknownID to) -> LxResult
    {
        return m_loc[0]->AllowConnect(m_loc,(ILxUnknownID) from,(ILxUnknownID) to);
    }

    auto AllowConnectType(ILxUnknownID to, unsigned int type) -> LxResult
    {
        return m_loc[0]->AllowConnectType(m_loc,(ILxUnknownID) to, type);
    }

    auto GraphName(const char **name) -> LxResult
    {
        return m_loc[0]->GraphName(m_loc, name);
    }

    auto Count(ILxUnknownID item, unsigned *count) -> LxResult
    {
        return m_loc[0]->Count(m_loc,(ILxUnknownID) item, count);
    }

    auto ByIndex(ILxUnknownID item, unsigned index, void **ppvObj) -> LxResult
    {
        return m_loc[0]->ByIndex(m_loc,(ILxUnknownID) item, index, ppvObj);
    }

    auto ByIndex(ILxUnknownID item, unsigned index, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->ByIndex(m_loc,(ILxUnknownID) item, index, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Connect(ILxUnknownID from, ILxUnknownID to, int toIndex) -> LxResult
    {
        return m_loc[0]->Connect(m_loc,(ILxUnknownID) from,(ILxUnknownID) to, toIndex);
    }

    auto Disconnect(ILxUnknownID from, ILxUnknownID to) -> LxResult
    {
        return m_loc[0]->Disconnect(m_loc,(ILxUnknownID) from,(ILxUnknownID) to);
    }

    auto BaseFlags(void) -> int
    {
        return m_loc[0]->BaseFlags(m_loc);
    }

    auto PerItemFlags(ILxUnknownID item, unsigned *flags) -> LxResult
    {
        return m_loc[0]->PerItemFlags(m_loc,(ILxUnknownID) item, flags);
    }

    auto ItemFlagsValid(void) -> int
    {
        return m_loc[0]->ItemFlagsValid(m_loc);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_SchematicConnection1
{
public:
    virtual ~CLxImpl_SchematicConnection1() = default;

    virtual auto schm_ItemFlags([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned *flags) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto schm_AllowConnect([[maybe_unused]] ILxUnknownID from, [[maybe_unused]] ILxUnknownID to) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto schm_GraphName([[maybe_unused]] const char **name) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto schm_Count([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned *count) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto schm_ByIndex([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned index, [[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto schm_Connect([[maybe_unused]] ILxUnknownID from, [[maybe_unused]] ILxUnknownID to, [[maybe_unused]] int toIndex) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto schm_Disconnect([[maybe_unused]] ILxUnknownID from, [[maybe_unused]] ILxUnknownID to) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto schm_BaseFlags([[maybe_unused]] void) -> int
    {
        return 0;
    }

    virtual auto schm_PerItemFlags([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned *flags) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto schm_ItemFlagsValid([[maybe_unused]] void) -> int
    {
        return 1;
    }
};

#define LXxD_SchematicConnection1_ItemFlags LxResult schm_ItemFlags([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned *flags) override
#define LXxO_SchematicConnection1_ItemFlags LXxD_SchematicConnection1_ItemFlags
#define LXxC_SchematicConnection1_ItemFlags(c) LxResult c::schm_ItemFlags([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned *flags)
#define LXxD_SchematicConnection1_AllowConnect LxResult schm_AllowConnect([[maybe_unused]] ILxUnknownID from, [[maybe_unused]] ILxUnknownID to) override
#define LXxO_SchematicConnection1_AllowConnect LXxD_SchematicConnection1_AllowConnect
#define LXxC_SchematicConnection1_AllowConnect(c) LxResult c::schm_AllowConnect([[maybe_unused]] ILxUnknownID from, [[maybe_unused]] ILxUnknownID to)
#define LXxD_SchematicConnection1_GraphName LxResult schm_GraphName([[maybe_unused]] const char **name) override
#define LXxO_SchematicConnection1_GraphName LXxD_SchematicConnection1_GraphName
#define LXxC_SchematicConnection1_GraphName(c) LxResult c::schm_GraphName([[maybe_unused]] const char **name)
#define LXxD_SchematicConnection1_Count LxResult schm_Count([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned *count) override
#define LXxO_SchematicConnection1_Count LXxD_SchematicConnection1_Count
#define LXxC_SchematicConnection1_Count(c) LxResult c::schm_Count([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned *count)
#define LXxD_SchematicConnection1_ByIndex LxResult schm_ByIndex([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned index, [[maybe_unused]] void **ppvObj) override
#define LXxO_SchematicConnection1_ByIndex LXxD_SchematicConnection1_ByIndex
#define LXxC_SchematicConnection1_ByIndex(c) LxResult c::schm_ByIndex([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned index, [[maybe_unused]] void **ppvObj)
#define LXxD_SchematicConnection1_Connect LxResult schm_Connect([[maybe_unused]] ILxUnknownID from, [[maybe_unused]] ILxUnknownID to, [[maybe_unused]] int toIndex) override
#define LXxO_SchematicConnection1_Connect LXxD_SchematicConnection1_Connect
#define LXxC_SchematicConnection1_Connect(c) LxResult c::schm_Connect([[maybe_unused]] ILxUnknownID from, [[maybe_unused]] ILxUnknownID to, [[maybe_unused]] int toIndex)
#define LXxD_SchematicConnection1_Disconnect LxResult schm_Disconnect([[maybe_unused]] ILxUnknownID from, [[maybe_unused]] ILxUnknownID to) override
#define LXxO_SchematicConnection1_Disconnect LXxD_SchematicConnection1_Disconnect
#define LXxC_SchematicConnection1_Disconnect(c) LxResult c::schm_Disconnect([[maybe_unused]] ILxUnknownID from, [[maybe_unused]] ILxUnknownID to)
#define LXxD_SchematicConnection1_BaseFlags int schm_BaseFlags() override
#define LXxO_SchematicConnection1_BaseFlags LXxD_SchematicConnection1_BaseFlags
#define LXxC_SchematicConnection1_BaseFlags(c) int c::schm_BaseFlags()
#define LXxD_SchematicConnection1_PerItemFlags LxResult schm_PerItemFlags([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned *flags) override
#define LXxO_SchematicConnection1_PerItemFlags LXxD_SchematicConnection1_PerItemFlags
#define LXxC_SchematicConnection1_PerItemFlags(c) LxResult c::schm_PerItemFlags([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned *flags)
#define LXxD_SchematicConnection1_ItemFlagsValid int schm_ItemFlagsValid() override
#define LXxO_SchematicConnection1_ItemFlagsValid LXxD_SchematicConnection1_ItemFlagsValid
#define LXxC_SchematicConnection1_ItemFlagsValid(c) int c::schm_ItemFlagsValid()

template <class T>
class CLxIfc_SchematicConnection1: public CLxInterface
{
public:
    CLxIfc_SchematicConnection1()
    {
        vt.ItemFlags = ItemFlags;
        vt.AllowConnect = AllowConnect;
        vt.GraphName = GraphName;
        vt.Count = Count;
        vt.ByIndex = ByIndex;
        vt.Connect = Connect;
        vt.Disconnect = Disconnect;
        vt.BaseFlags = BaseFlags;
        vt.PerItemFlags = PerItemFlags;
        vt.ItemFlagsValid = ItemFlagsValid;
        vTable = &vt.iunk;
        iid = &lx::guid_SchematicConnection1;
    }

    static auto ItemFlags(LXtObjectID wcom,LXtObjectID item,unsigned *flags) -> LxResult
    {
        LXCWxINST (CLxImpl_SchematicConnection1, loc);
        try
        {
           return loc->schm_ItemFlags((ILxUnknownID) item, flags);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto AllowConnect(LXtObjectID wcom,LXtObjectID from,LXtObjectID to) -> LxResult
    {
        LXCWxINST (CLxImpl_SchematicConnection1, loc);
        try
        {
           return loc->schm_AllowConnect((ILxUnknownID) from,(ILxUnknownID) to);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto GraphName(LXtObjectID wcom,const char **name) -> LxResult
    {
        LXCWxINST (CLxImpl_SchematicConnection1, loc);
        try
        {
           return loc->schm_GraphName( name);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Count(LXtObjectID wcom,LXtObjectID item,unsigned *count) -> LxResult
    {
        LXCWxINST (CLxImpl_SchematicConnection1, loc);
        try
        {
           return loc->schm_Count((ILxUnknownID) item, count);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ByIndex(LXtObjectID wcom,LXtObjectID item,unsigned index,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_SchematicConnection1, loc);
        try
        {
           return loc->schm_ByIndex((ILxUnknownID) item, index, ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Connect(LXtObjectID wcom,LXtObjectID from,LXtObjectID to,int toIndex) -> LxResult
    {
        LXCWxINST (CLxImpl_SchematicConnection1, loc);
        try
        {
           return loc->schm_Connect((ILxUnknownID) from,(ILxUnknownID) to, toIndex);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Disconnect(LXtObjectID wcom,LXtObjectID from,LXtObjectID to) -> LxResult
    {
        LXCWxINST (CLxImpl_SchematicConnection1, loc);
        try
        {
           return loc->schm_Disconnect((ILxUnknownID) from,(ILxUnknownID) to);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto BaseFlags(LXtObjectID wcom) -> int
    {
        LXCWxINST (CLxImpl_SchematicConnection1, loc);
        return loc->schm_BaseFlags();
    }

    static auto PerItemFlags(LXtObjectID wcom,LXtObjectID item,unsigned *flags) -> LxResult
    {
        LXCWxINST (CLxImpl_SchematicConnection1, loc);
        try
        {
           return loc->schm_PerItemFlags((ILxUnknownID) item, flags);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ItemFlagsValid(LXtObjectID wcom) -> int
    {
        LXCWxINST (CLxImpl_SchematicConnection1, loc);
        return loc->schm_ItemFlagsValid();
    }

private:
    ILxSchematicConnection1 vt;
};

class CLxLoc_SchematicConnection1 : public CLxLocalize<ILxSchematicConnection1ID>
{
public:
    CLxLoc_SchematicConnection1()
    {
        _init();
    }

    CLxLoc_SchematicConnection1(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_SchematicConnection1(CLxLoc_SchematicConnection1 const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_SchematicConnection1;
    }

    auto ItemFlags(ILxUnknownID item, unsigned *flags) -> LxResult
    {
        return m_loc[0]->ItemFlags(m_loc,(ILxUnknownID) item, flags);
    }

    auto AllowConnect(ILxUnknownID from, ILxUnknownID to) -> LxResult
    {
        return m_loc[0]->AllowConnect(m_loc,(ILxUnknownID) from,(ILxUnknownID) to);
    }

    auto GraphName(const char **name) -> LxResult
    {
        return m_loc[0]->GraphName(m_loc, name);
    }

    auto Count(ILxUnknownID item, unsigned *count) -> LxResult
    {
        return m_loc[0]->Count(m_loc,(ILxUnknownID) item, count);
    }

    auto ByIndex(ILxUnknownID item, unsigned index, void **ppvObj) -> LxResult
    {
        return m_loc[0]->ByIndex(m_loc,(ILxUnknownID) item, index, ppvObj);
    }

    auto ByIndex(ILxUnknownID item, unsigned index, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->ByIndex(m_loc,(ILxUnknownID) item, index, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Connect(ILxUnknownID from, ILxUnknownID to, int toIndex) -> LxResult
    {
        return m_loc[0]->Connect(m_loc,(ILxUnknownID) from,(ILxUnknownID) to, toIndex);
    }

    auto Disconnect(ILxUnknownID from, ILxUnknownID to) -> LxResult
    {
        return m_loc[0]->Disconnect(m_loc,(ILxUnknownID) from,(ILxUnknownID) to);
    }

    auto BaseFlags(void) -> int
    {
        return m_loc[0]->BaseFlags(m_loc);
    }

    auto PerItemFlags(ILxUnknownID item, unsigned *flags) -> LxResult
    {
        return m_loc[0]->PerItemFlags(m_loc,(ILxUnknownID) item, flags);
    }

    auto ItemFlagsValid(void) -> int
    {
        return m_loc[0]->ItemFlagsValid(m_loc);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_SchemaDest
{
public:
    virtual ~CLxImpl_SchemaDest() = default;

    virtual int schmd_ViewType(void) = 0;

    virtual auto schmd_Position([[maybe_unused]] LXtVector pos) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto schmd_Group([[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto schmd_Item([[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto schmd_Node([[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto schmd_Channel([[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto schmd_Graph([[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto schmd_Link([[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_SchemaDest_ViewType int schmd_ViewType() override
#define LXxO_SchemaDest_ViewType LXxD_SchemaDest_ViewType
#define LXxC_SchemaDest_ViewType(c) int c::schmd_ViewType()
#define LXxD_SchemaDest_Position LxResult schmd_Position([[maybe_unused]] LXtVector pos) override
#define LXxO_SchemaDest_Position LXxD_SchemaDest_Position
#define LXxC_SchemaDest_Position(c) LxResult c::schmd_Position([[maybe_unused]] LXtVector pos)
#define LXxD_SchemaDest_Group LxResult schmd_Group([[maybe_unused]] void **ppvObj) override
#define LXxO_SchemaDest_Group LXxD_SchemaDest_Group
#define LXxC_SchemaDest_Group(c) LxResult c::schmd_Group([[maybe_unused]] void **ppvObj)
#define LXxD_SchemaDest_Item LxResult schmd_Item([[maybe_unused]] void **ppvObj) override
#define LXxO_SchemaDest_Item LXxD_SchemaDest_Item
#define LXxC_SchemaDest_Item(c) LxResult c::schmd_Item([[maybe_unused]] void **ppvObj)
#define LXxD_SchemaDest_Node LxResult schmd_Node([[maybe_unused]] void **ppvObj) override
#define LXxO_SchemaDest_Node LXxD_SchemaDest_Node
#define LXxC_SchemaDest_Node(c) LxResult c::schmd_Node([[maybe_unused]] void **ppvObj)
#define LXxD_SchemaDest_Channel LxResult schmd_Channel([[maybe_unused]] void **ppvObj) override
#define LXxO_SchemaDest_Channel LXxD_SchemaDest_Channel
#define LXxC_SchemaDest_Channel(c) LxResult c::schmd_Channel([[maybe_unused]] void **ppvObj)
#define LXxD_SchemaDest_Graph LxResult schmd_Graph([[maybe_unused]] void **ppvObj) override
#define LXxO_SchemaDest_Graph LXxD_SchemaDest_Graph
#define LXxC_SchemaDest_Graph(c) LxResult c::schmd_Graph([[maybe_unused]] void **ppvObj)
#define LXxD_SchemaDest_Link LxResult schmd_Link([[maybe_unused]] void **ppvObj) override
#define LXxO_SchemaDest_Link LXxD_SchemaDest_Link
#define LXxC_SchemaDest_Link(c) LxResult c::schmd_Link([[maybe_unused]] void **ppvObj)

template <class T>
class CLxIfc_SchemaDest: public CLxInterface
{
public:
    CLxIfc_SchemaDest()
    {
        vt.ViewType = ViewType;
        vt.Position = Position;
        vt.Group = Group;
        vt.Item = Item;
        vt.Node = Node;
        vt.Channel = Channel;
        vt.Graph = Graph;
        vt.Link = Link;
        vTable = &vt.iunk;
        iid = &lx::guid_SchemaDest;
    }

    static auto ViewType(LXtObjectID wcom) -> int
    {
        LXCWxINST (CLxImpl_SchemaDest, loc);
        return loc->schmd_ViewType();
    }

    static auto Position(LXtObjectID wcom,LXtVector pos) -> LxResult
    {
        LXCWxINST (CLxImpl_SchemaDest, loc);
        try
        {
           return loc->schmd_Position( pos);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Group(LXtObjectID wcom,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_SchemaDest, loc);
        try
        {
           return loc->schmd_Group( ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Item(LXtObjectID wcom,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_SchemaDest, loc);
        try
        {
           return loc->schmd_Item( ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Node(LXtObjectID wcom,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_SchemaDest, loc);
        try
        {
           return loc->schmd_Node( ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Channel(LXtObjectID wcom,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_SchemaDest, loc);
        try
        {
           return loc->schmd_Channel( ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Graph(LXtObjectID wcom,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_SchemaDest, loc);
        try
        {
           return loc->schmd_Graph( ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Link(LXtObjectID wcom,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_SchemaDest, loc);
        try
        {
           return loc->schmd_Link( ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxSchemaDest vt;
};

class CLxLoc_SchemaDest : public CLxLocalize<ILxSchemaDestID>
{
public:
    CLxLoc_SchemaDest()
    {
        _init();
    }

    CLxLoc_SchemaDest(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_SchemaDest(CLxLoc_SchemaDest const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_SchemaDest;
    }

    auto ViewType(void) -> int
    {
        return m_loc[0]->ViewType(m_loc);
    }

    auto Position(LXtVector pos) -> LxResult
    {
        return m_loc[0]->Position(m_loc, pos);
    }

    auto Group(void **ppvObj) -> LxResult
    {
        return m_loc[0]->Group(m_loc, ppvObj);
    }

    auto Group(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Group(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Item(void **ppvObj) -> LxResult
    {
        return m_loc[0]->Item(m_loc, ppvObj);
    }

    auto Item(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Item(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Node(void **ppvObj) -> LxResult
    {
        return m_loc[0]->Node(m_loc, ppvObj);
    }

    auto Node(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Node(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Channel(void **ppvObj) -> LxResult
    {
        return m_loc[0]->Channel(m_loc, ppvObj);
    }

    auto Channel(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Channel(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Graph(void **ppvObj) -> LxResult
    {
        return m_loc[0]->Graph(m_loc, ppvObj);
    }

    auto Graph(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Graph(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Link(void **ppvObj) -> LxResult
    {
        return m_loc[0]->Link(m_loc, ppvObj);
    }

    auto Link(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Link(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_SchematicGroup : public CLxLocalize<ILxSchematicGroupID>
{
public:
    CLxLoc_SchematicGroup()
    {
        _init();
    }

    CLxLoc_SchematicGroup(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_SchematicGroup(CLxLoc_SchematicGroup const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_SchematicGroup;
    }

    auto Group(void **ppvObj) -> LxResult
    {
        return m_loc[0]->Group(m_loc, ppvObj);
    }

    auto Group(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Group(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto IsWorkspace(void) -> LxResult
    {
        return m_loc[0]->IsWorkspace(m_loc);
    }

    auto AddItem(ILxUnknownID item, void **ppvObj) -> LxResult
    {
        return m_loc[0]->AddItem(m_loc,(ILxUnknownID) item, ppvObj);
    }

    auto AddItem(ILxUnknownID item, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->AddItem(m_loc,(ILxUnknownID) item, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto RemoveItem(ILxUnknownID item) -> void
    {
        m_loc[0]->RemoveItem(m_loc,(ILxUnknownID) item);
    }

    auto NodeCount(unsigned int *count) -> LxResult
    {
        return m_loc[0]->NodeCount(m_loc, count);
    }

    auto NodeByIndex(unsigned int index, void **ppvObj) -> LxResult
    {
        return m_loc[0]->NodeByIndex(m_loc, index, ppvObj);
    }

    auto NodeByIndex(unsigned int index, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->NodeByIndex(m_loc, index, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto InputNode(void **ppvObj) -> LxResult
    {
        return m_loc[0]->InputNode(m_loc, ppvObj);
    }

    auto InputNode(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->InputNode(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto OutputNode(void **ppvObj) -> LxResult
    {
        return m_loc[0]->OutputNode(m_loc, ppvObj);
    }

    auto OutputNode(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->OutputNode(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_SchematicNode : public CLxLocalize<ILxSchematicNodeID>
{
public:
    CLxLoc_SchematicNode()
    {
        _init();
    }

    CLxLoc_SchematicNode(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_SchematicNode(CLxLoc_SchematicNode const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_SchematicNode;
    }

    auto Group(void **ppvObj) -> LxResult
    {
        return m_loc[0]->Group(m_loc, ppvObj);
    }

    auto Group(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Group(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Item(void **ppvObj) -> LxResult
    {
        return m_loc[0]->Item(m_loc, ppvObj);
    }

    auto Item(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Item(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto AddChannel(unsigned int index) -> LxResult
    {
        return m_loc[0]->AddChannel(m_loc, index);
    }

    auto RemoveChannel(unsigned int index) -> LxResult
    {
        return m_loc[0]->RemoveChannel(m_loc, index);
    }

    auto ChannelCount(unsigned int *count) const -> LxResult
    {
        return m_loc[0]->ChannelCount(m_loc, count);
    }

    auto ChannelByIndex(unsigned int index, unsigned int type, void **ppvObj) -> LxResult
    {
        return m_loc[0]->ChannelByIndex(m_loc, index, type, ppvObj);
    }

    auto ChannelByIndex(unsigned int index, unsigned int type, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->ChannelByIndex(m_loc, index, type, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto ConnectionCount(unsigned int *count) -> LxResult
    {
        return m_loc[0]->ConnectionCount(m_loc, count);
    }

    auto ConnectionByIndex(unsigned int index, unsigned int type, void **ppvObj) -> LxResult
    {
        return m_loc[0]->ConnectionByIndex(m_loc, index, type, ppvObj);
    }

    auto ConnectionByIndex(unsigned int index, unsigned int type, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->ConnectionByIndex(m_loc, index, type, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto IsRoot(void) -> LxResult
    {
        return m_loc[0]->IsRoot(m_loc);
    }

    auto RootNode(void **ppvObj) -> LxResult
    {
        return m_loc[0]->RootNode(m_loc, ppvObj);
    }

    auto RootNode(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->RootNode(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto SubNodeCount(unsigned int *count) const -> LxResult
    {
        return m_loc[0]->SubNodeCount(m_loc, count);
    }

    auto SubNodeByIndex(unsigned int index, void **ppvObj) -> LxResult
    {
        return m_loc[0]->SubNodeByIndex(m_loc, index, ppvObj);
    }

    auto SubNodeByIndex(unsigned int index, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->SubNodeByIndex(m_loc, index, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Position(double *x, double *y) -> LxResult
    {
        return m_loc[0]->Position(m_loc, x, y);
    }

    auto SetPosition(double x, double y) -> LxResult
    {
        return m_loc[0]->SetPosition(m_loc, x, y);
    }

    auto Size(double *width, double *height) -> LxResult
    {
        return m_loc[0]->Size(m_loc, width, height);
    }

    auto AbsoluteSize(double *width, double *height) -> LxResult
    {
        return m_loc[0]->AbsoluteSize(m_loc, width, height);
    }

    auto Expanded(void) -> LxResult
    {
        return m_loc[0]->Expanded(m_loc);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_SchematicNodeConnection : public CLxLocalize<ILxSchematicNodeConnectionID>
{
public:
    CLxLoc_SchematicNodeConnection()
    {
        _init();
    }

    CLxLoc_SchematicNodeConnection(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_SchematicNodeConnection(CLxLoc_SchematicNodeConnection const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_SchematicNodeConnection;
    }

    auto Flags(unsigned int *flags) const -> LxResult
    {
        return m_loc[0]->Flags(m_loc, flags);
    }

    auto Node(void **ppvObj) -> LxResult
    {
        return m_loc[0]->Node(m_loc, ppvObj);
    }

    auto Node(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Node(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Count(unsigned int *count) const -> LxResult
    {
        return m_loc[0]->Count(m_loc, count);
    }

    auto ByIndex(unsigned int index, void **ppvObj) -> LxResult
    {
        return m_loc[0]->ByIndex(m_loc, index, ppvObj);
    }

    auto ByIndex(unsigned int index, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->ByIndex(m_loc, index, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Position(unsigned int index, double *x, double *y) -> LxResult
    {
        return m_loc[0]->Position(m_loc, index, x, y);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_SchematicNodeChannel : public CLxLocalize<ILxSchematicNodeChannelID>
{
public:
    CLxLoc_SchematicNodeChannel()
    {
        _init();
    }

    CLxLoc_SchematicNodeChannel(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_SchematicNodeChannel(CLxLoc_SchematicNodeChannel const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_SchematicNodeChannel;
    }

    auto Flags(unsigned int *flags) const -> LxResult
    {
        return m_loc[0]->Flags(m_loc, flags);
    }

    auto Node(void **ppvObj) -> LxResult
    {
        return m_loc[0]->Node(m_loc, ppvObj);
    }

    auto Node(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Node(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Index(unsigned int *index) const -> LxResult
    {
        return m_loc[0]->Index(m_loc, index);
    }

    auto Count(unsigned int *count) const -> LxResult
    {
        return m_loc[0]->Count(m_loc, count);
    }

    auto ByIndex(unsigned int index, void **ppvObj) -> LxResult
    {
        return m_loc[0]->ByIndex(m_loc, index, ppvObj);
    }

    auto ByIndex(unsigned int index, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->ByIndex(m_loc, index, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Position(double *x, double *y) -> LxResult
    {
        return m_loc[0]->Position(m_loc, x, y);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
