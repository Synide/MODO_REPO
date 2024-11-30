//
// C++ wrapper for lxsdk/lxvector.h.
//
//	Copyright 2024.
//
//
#pragma once

#include <lxvector.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx
{
    static LXtGUID const guid_VectorPacket = {0xDDD79825, {0x3E2F, 0x4A6B}, {0xA2, 0x7A, 0xB0, 0xB2, 0xC6, 0xFB, 0x81, 0x1C}};
    static LXtGUID const guid_VectorPacket1 = {0xF74C2B0E, {0x4BC5, 0x4E76}, {0x8F, 0x7D, 0x1D, 0x64, 0xDA, 0x86, 0xFD, 0x28}};
    static LXtGUID const guid_PacketService = {0x2B8D8867, {0x4EFC, 0x4A1D}, {0x8F, 0x6A, 0xB5, 0xF1, 0x03, 0xA9, 0x0A, 0x9B}};
    static LXtGUID const guid_VectorType = {0x791B288F, {0xDD69, 0x11D7}, {0x85, 0x7A, 0x00, 0x0A, 0x95, 0x93, 0xD7, 0x16}};
    static LXtGUID const guid_VectorStack = {0x7915D133, {0x4272, 0x498B}, {0xA6, 0x91, 0xC9, 0x81, 0x18, 0xF4, 0x0F, 0xD5}};
    static LXtGUID const guid_VectorList = {0xF091C272, {0xC770, 0x42C3}, {0xB3, 0x14, 0x62, 0xEE, 0x90, 0xD3, 0x4C, 0x57}};
    static LXtGUID const guid_TextureEffect = {0xCA13032E, {0x3855, 0x4744}, {0xB7, 0x7A, 0x59, 0x53, 0x0E, 0xC3, 0xE2, 0x60}};
    static LXtGUID const guid_PacketEffect = {0x7e8a37ce, {0x618b, 0x4ae4}, {0xa4, 0x29, 0x01, 0x31, 0x7a, 0xc4, 0x0e, 0xb0}};
} // namespace lx

class CLxImpl_VectorPacket
{
public:
    virtual ~CLxImpl_VectorPacket() = default;

    virtual unsigned int vpkt_Size(void) = 0;

    virtual const LXtGUID * vpkt_Interface(void) = 0;

    virtual auto vpkt_Initialize([[maybe_unused]] void *packet) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual void vpkt_Reset([[maybe_unused]] void *packet)
    {
    }

    virtual auto vpkt_Copy([[maybe_unused]] void *packet, [[maybe_unused]] void *from) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual void vpkt_Cleanup([[maybe_unused]] void *packet)
    {
    }

    virtual auto vpkt_Blend([[maybe_unused]] void *packet, [[maybe_unused]] void *p0, [[maybe_unused]] void *p1, [[maybe_unused]] float t, [[maybe_unused]] int mode) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto vpkt_Invert([[maybe_unused]] void *packet) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto vpkt_NodeCount([[maybe_unused]] void) -> unsigned int
    {
        return 0;
    }

    virtual auto vpkt_NodeName([[maybe_unused]] unsigned int index, [[maybe_unused]] const char **name) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto vpkt_NodeType([[maybe_unused]] unsigned int index, [[maybe_unused]] VPacketPubType *dataType, [[maybe_unused]] unsigned int *count, [[maybe_unused]] const char **exoType, [[maybe_unused]] const char **vecType) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto vpkt_NodeGet([[maybe_unused]] unsigned int index, [[maybe_unused]] void *packet, [[maybe_unused]] void **data) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_VectorPacket_Size unsigned int vpkt_Size() override
#define LXxO_VectorPacket_Size LXxD_VectorPacket_Size
#define LXxC_VectorPacket_Size(c) unsigned int c::vpkt_Size()
#define LXxD_VectorPacket_Interface const LXtGUID * vpkt_Interface() override
#define LXxO_VectorPacket_Interface LXxD_VectorPacket_Interface
#define LXxC_VectorPacket_Interface(c) const LXtGUID * c::vpkt_Interface()
#define LXxD_VectorPacket_Initialize LxResult vpkt_Initialize([[maybe_unused]] void *packet) override
#define LXxO_VectorPacket_Initialize LXxD_VectorPacket_Initialize
#define LXxC_VectorPacket_Initialize(c) LxResult c::vpkt_Initialize([[maybe_unused]] void *packet)
#define LXxD_VectorPacket_Reset void vpkt_Reset([[maybe_unused]] void *packet) override
#define LXxO_VectorPacket_Reset LXxD_VectorPacket_Reset
#define LXxC_VectorPacket_Reset(c) void c::vpkt_Reset([[maybe_unused]] void *packet)
#define LXxD_VectorPacket_Copy LxResult vpkt_Copy([[maybe_unused]] void *packet, [[maybe_unused]] void *from) override
#define LXxO_VectorPacket_Copy LXxD_VectorPacket_Copy
#define LXxC_VectorPacket_Copy(c) LxResult c::vpkt_Copy([[maybe_unused]] void *packet, [[maybe_unused]] void *from)
#define LXxD_VectorPacket_Cleanup void vpkt_Cleanup([[maybe_unused]] void *packet) override
#define LXxO_VectorPacket_Cleanup LXxD_VectorPacket_Cleanup
#define LXxC_VectorPacket_Cleanup(c) void c::vpkt_Cleanup([[maybe_unused]] void *packet)
#define LXxD_VectorPacket_Blend LxResult vpkt_Blend([[maybe_unused]] void *packet, [[maybe_unused]] void *p0, [[maybe_unused]] void *p1, [[maybe_unused]] float t, [[maybe_unused]] int mode) override
#define LXxO_VectorPacket_Blend LXxD_VectorPacket_Blend
#define LXxC_VectorPacket_Blend(c) LxResult c::vpkt_Blend([[maybe_unused]] void *packet, [[maybe_unused]] void *p0, [[maybe_unused]] void *p1, [[maybe_unused]] float t, [[maybe_unused]] int mode)
#define LXxD_VectorPacket_Invert LxResult vpkt_Invert([[maybe_unused]] void *packet) override
#define LXxO_VectorPacket_Invert LXxD_VectorPacket_Invert
#define LXxC_VectorPacket_Invert(c) LxResult c::vpkt_Invert([[maybe_unused]] void *packet)
#define LXxD_VectorPacket_NodeCount unsigned int vpkt_NodeCount() override
#define LXxO_VectorPacket_NodeCount LXxD_VectorPacket_NodeCount
#define LXxC_VectorPacket_NodeCount(c) unsigned int c::vpkt_NodeCount()
#define LXxD_VectorPacket_NodeName LxResult vpkt_NodeName([[maybe_unused]] unsigned int index, [[maybe_unused]] const char **name) override
#define LXxO_VectorPacket_NodeName LXxD_VectorPacket_NodeName
#define LXxC_VectorPacket_NodeName(c) LxResult c::vpkt_NodeName([[maybe_unused]] unsigned int index, [[maybe_unused]] const char **name)
#define LXxD_VectorPacket_NodeType LxResult vpkt_NodeType([[maybe_unused]] unsigned int index, [[maybe_unused]] VPacketPubType *dataType, [[maybe_unused]] unsigned int *count, [[maybe_unused]] const char **exoType, [[maybe_unused]] const char **vecType) override
#define LXxO_VectorPacket_NodeType LXxD_VectorPacket_NodeType
#define LXxC_VectorPacket_NodeType(c) LxResult c::vpkt_NodeType([[maybe_unused]] unsigned int index, [[maybe_unused]] VPacketPubType *dataType, [[maybe_unused]] unsigned int *count, [[maybe_unused]] const char **exoType, [[maybe_unused]] const char **vecType)
#define LXxD_VectorPacket_NodeGet LxResult vpkt_NodeGet([[maybe_unused]] unsigned int index, [[maybe_unused]] void *packet, [[maybe_unused]] void **data) override
#define LXxO_VectorPacket_NodeGet LXxD_VectorPacket_NodeGet
#define LXxC_VectorPacket_NodeGet(c) LxResult c::vpkt_NodeGet([[maybe_unused]] unsigned int index, [[maybe_unused]] void *packet, [[maybe_unused]] void **data)

template <class T>
class CLxIfc_VectorPacket: public CLxInterface
{
public:
    CLxIfc_VectorPacket()
    {
        vt.Size = Size;
        vt.Interface = Interface;
        vt.Initialize = Initialize;
        vt.Reset = Reset;
        vt.Copy = Copy;
        vt.Cleanup = Cleanup;
        vt.Blend = Blend;
        vt.Invert = Invert;
        vt.NodeCount = NodeCount;
        vt.NodeName = NodeName;
        vt.NodeType = NodeType;
        vt.NodeGet = NodeGet;
        vTable = &vt.iunk;
        iid = &lx::guid_VectorPacket;
    }

    static auto Size(LXtObjectID wcom) -> unsigned int
    {
        LXCWxINST (CLxImpl_VectorPacket, loc);
        return loc->vpkt_Size();
    }

    static auto Interface(LXtObjectID wcom) -> const LXtGUID *
    {
        LXCWxINST (CLxImpl_VectorPacket, loc);
        return loc->vpkt_Interface();
    }

    static auto Initialize(LXtObjectID wcom,void *packet) -> LxResult
    {
        LXCWxINST (CLxImpl_VectorPacket, loc);
        try
        {
           return loc->vpkt_Initialize( packet);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Reset(LXtObjectID wcom,void *packet) -> void
    {
        LXCWxINST (CLxImpl_VectorPacket, loc);
        loc->vpkt_Reset( packet);
    }

    static auto Copy(LXtObjectID wcom,void *packet,void *from) -> LxResult
    {
        LXCWxINST (CLxImpl_VectorPacket, loc);
        try
        {
           return loc->vpkt_Copy( packet, from);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Cleanup(LXtObjectID wcom,void *packet) -> void
    {
        LXCWxINST (CLxImpl_VectorPacket, loc);
        loc->vpkt_Cleanup( packet);
    }

    static auto Blend(LXtObjectID wcom,void *packet,void *p0,void *p1,float t,int mode) -> LxResult
    {
        LXCWxINST (CLxImpl_VectorPacket, loc);
        try
        {
           return loc->vpkt_Blend( packet, p0, p1, t, mode);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Invert(LXtObjectID wcom,void *packet) -> LxResult
    {
        LXCWxINST (CLxImpl_VectorPacket, loc);
        try
        {
           return loc->vpkt_Invert( packet);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto NodeCount(LXtObjectID wcom) -> unsigned int
    {
        LXCWxINST (CLxImpl_VectorPacket, loc);
        return loc->vpkt_NodeCount();
    }

    static auto NodeName(LXtObjectID wcom,unsigned int index,const char **name) -> LxResult
    {
        LXCWxINST (CLxImpl_VectorPacket, loc);
        try
        {
           return loc->vpkt_NodeName( index, name);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto NodeType(LXtObjectID wcom,unsigned int index,VPacketPubType *dataType,unsigned int *count,const char **exoType,const char **vecType) -> LxResult
    {
        LXCWxINST (CLxImpl_VectorPacket, loc);
        try
        {
           return loc->vpkt_NodeType( index, dataType, count, exoType, vecType);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto NodeGet(LXtObjectID wcom,unsigned int index,void *packet,void **data) -> LxResult
    {
        LXCWxINST (CLxImpl_VectorPacket, loc);
        try
        {
           return loc->vpkt_NodeGet( index, packet, data);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxVectorPacket vt;
};


class CLxImpl_VectorPacket1
{
public:
    virtual ~CLxImpl_VectorPacket1() = default;

    virtual unsigned int vpkt_Size(void) = 0;

    virtual const LXtGUID * vpkt_Interface(void) = 0;

    virtual auto vpkt_Initialize([[maybe_unused]] void *packet) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual void vpkt_Reset([[maybe_unused]] void *packet)
    {
    }

    virtual auto vpkt_Copy([[maybe_unused]] void *packet, [[maybe_unused]] void *from) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual void vpkt_Cleanup([[maybe_unused]] void *packet)
    {
    }

    virtual auto vpkt_Save([[maybe_unused]] void *packet, [[maybe_unused]] unsigned int n, [[maybe_unused]] ILxUnknownID writestream) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto vpkt_Load([[maybe_unused]] void *packet, [[maybe_unused]] unsigned int n, [[maybe_unused]] ILxUnknownID readstream) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto vpkt_Interpolate([[maybe_unused]] void *packet, [[maybe_unused]] void *p0, [[maybe_unused]] void *p1, [[maybe_unused]] float t) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto vpkt_Blend([[maybe_unused]] void *packet, [[maybe_unused]] void *p0, [[maybe_unused]] void *p1, [[maybe_unused]] float t, [[maybe_unused]] int mode) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto vpkt_Invert([[maybe_unused]] void *packet) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_VectorPacket1_Size unsigned int vpkt_Size() override
#define LXxO_VectorPacket1_Size LXxD_VectorPacket1_Size
#define LXxC_VectorPacket1_Size(c) unsigned int c::vpkt_Size()
#define LXxD_VectorPacket1_Interface const LXtGUID * vpkt_Interface() override
#define LXxO_VectorPacket1_Interface LXxD_VectorPacket1_Interface
#define LXxC_VectorPacket1_Interface(c) const LXtGUID * c::vpkt_Interface()
#define LXxD_VectorPacket1_Initialize LxResult vpkt_Initialize([[maybe_unused]] void *packet) override
#define LXxO_VectorPacket1_Initialize LXxD_VectorPacket1_Initialize
#define LXxC_VectorPacket1_Initialize(c) LxResult c::vpkt_Initialize([[maybe_unused]] void *packet)
#define LXxD_VectorPacket1_Reset void vpkt_Reset([[maybe_unused]] void *packet) override
#define LXxO_VectorPacket1_Reset LXxD_VectorPacket1_Reset
#define LXxC_VectorPacket1_Reset(c) void c::vpkt_Reset([[maybe_unused]] void *packet)
#define LXxD_VectorPacket1_Copy LxResult vpkt_Copy([[maybe_unused]] void *packet, [[maybe_unused]] void *from) override
#define LXxO_VectorPacket1_Copy LXxD_VectorPacket1_Copy
#define LXxC_VectorPacket1_Copy(c) LxResult c::vpkt_Copy([[maybe_unused]] void *packet, [[maybe_unused]] void *from)
#define LXxD_VectorPacket1_Cleanup void vpkt_Cleanup([[maybe_unused]] void *packet) override
#define LXxO_VectorPacket1_Cleanup LXxD_VectorPacket1_Cleanup
#define LXxC_VectorPacket1_Cleanup(c) void c::vpkt_Cleanup([[maybe_unused]] void *packet)
#define LXxD_VectorPacket1_Save LxResult vpkt_Save([[maybe_unused]] void *packet, [[maybe_unused]] unsigned int n, [[maybe_unused]] ILxUnknownID writestream) override
#define LXxO_VectorPacket1_Save LXxD_VectorPacket1_Save
#define LXxC_VectorPacket1_Save(c) LxResult c::vpkt_Save([[maybe_unused]] void *packet, [[maybe_unused]] unsigned int n, [[maybe_unused]] ILxUnknownID writestream)
#define LXxD_VectorPacket1_Load LxResult vpkt_Load([[maybe_unused]] void *packet, [[maybe_unused]] unsigned int n, [[maybe_unused]] ILxUnknownID readstream) override
#define LXxO_VectorPacket1_Load LXxD_VectorPacket1_Load
#define LXxC_VectorPacket1_Load(c) LxResult c::vpkt_Load([[maybe_unused]] void *packet, [[maybe_unused]] unsigned int n, [[maybe_unused]] ILxUnknownID readstream)
#define LXxD_VectorPacket1_Interpolate LxResult vpkt_Interpolate([[maybe_unused]] void *packet, [[maybe_unused]] void *p0, [[maybe_unused]] void *p1, [[maybe_unused]] float t) override
#define LXxO_VectorPacket1_Interpolate LXxD_VectorPacket1_Interpolate
#define LXxC_VectorPacket1_Interpolate(c) LxResult c::vpkt_Interpolate([[maybe_unused]] void *packet, [[maybe_unused]] void *p0, [[maybe_unused]] void *p1, [[maybe_unused]] float t)
#define LXxD_VectorPacket1_Blend LxResult vpkt_Blend([[maybe_unused]] void *packet, [[maybe_unused]] void *p0, [[maybe_unused]] void *p1, [[maybe_unused]] float t, [[maybe_unused]] int mode) override
#define LXxO_VectorPacket1_Blend LXxD_VectorPacket1_Blend
#define LXxC_VectorPacket1_Blend(c) LxResult c::vpkt_Blend([[maybe_unused]] void *packet, [[maybe_unused]] void *p0, [[maybe_unused]] void *p1, [[maybe_unused]] float t, [[maybe_unused]] int mode)
#define LXxD_VectorPacket1_Invert LxResult vpkt_Invert([[maybe_unused]] void *packet) override
#define LXxO_VectorPacket1_Invert LXxD_VectorPacket1_Invert
#define LXxC_VectorPacket1_Invert(c) LxResult c::vpkt_Invert([[maybe_unused]] void *packet)

template <class T>
class CLxIfc_VectorPacket1: public CLxInterface
{
public:
    CLxIfc_VectorPacket1()
    {
        vt.Size = Size;
        vt.Interface = Interface;
        vt.Initialize = Initialize;
        vt.Reset = Reset;
        vt.Copy = Copy;
        vt.Cleanup = Cleanup;
        vt.Save = Save;
        vt.Load = Load;
        vt.Interpolate = Interpolate;
        vt.Blend = Blend;
        vt.Invert = Invert;
        vTable = &vt.iunk;
        iid = &lx::guid_VectorPacket1;
    }

    static auto Size(LXtObjectID wcom) -> unsigned int
    {
        LXCWxINST (CLxImpl_VectorPacket1, loc);
        return loc->vpkt_Size();
    }

    static auto Interface(LXtObjectID wcom) -> const LXtGUID *
    {
        LXCWxINST (CLxImpl_VectorPacket1, loc);
        return loc->vpkt_Interface();
    }

    static auto Initialize(LXtObjectID wcom,void *packet) -> LxResult
    {
        LXCWxINST (CLxImpl_VectorPacket1, loc);
        try
        {
           return loc->vpkt_Initialize( packet);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Reset(LXtObjectID wcom,void *packet) -> void
    {
        LXCWxINST (CLxImpl_VectorPacket1, loc);
        loc->vpkt_Reset( packet);
    }

    static auto Copy(LXtObjectID wcom,void *packet,void *from) -> LxResult
    {
        LXCWxINST (CLxImpl_VectorPacket1, loc);
        try
        {
           return loc->vpkt_Copy( packet, from);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Cleanup(LXtObjectID wcom,void *packet) -> void
    {
        LXCWxINST (CLxImpl_VectorPacket1, loc);
        loc->vpkt_Cleanup( packet);
    }

    static auto Save(LXtObjectID wcom,void *packet,unsigned int n,LXtObjectID writestream) -> LxResult
    {
        LXCWxINST (CLxImpl_VectorPacket1, loc);
        try
        {
           return loc->vpkt_Save( packet, n,(ILxUnknownID) writestream);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Load(LXtObjectID wcom,void *packet,unsigned int n,LXtObjectID readstream) -> LxResult
    {
        LXCWxINST (CLxImpl_VectorPacket1, loc);
        try
        {
           return loc->vpkt_Load( packet, n,(ILxUnknownID) readstream);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Interpolate(LXtObjectID wcom,void *packet,void *p0,void *p1,float t) -> LxResult
    {
        LXCWxINST (CLxImpl_VectorPacket1, loc);
        try
        {
           return loc->vpkt_Interpolate( packet, p0, p1, t);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Blend(LXtObjectID wcom,void *packet,void *p0,void *p1,float t,int mode) -> LxResult
    {
        LXCWxINST (CLxImpl_VectorPacket1, loc);
        try
        {
           return loc->vpkt_Blend( packet, p0, p1, t, mode);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Invert(LXtObjectID wcom,void *packet) -> LxResult
    {
        LXCWxINST (CLxImpl_VectorPacket1, loc);
        try
        {
           return loc->vpkt_Invert( packet);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxVectorPacket1 vt;
};


class CLxLoc_PacketService : public CLxLocalizedService
{
public:
    ILxPacketServiceID m_loc{ nullptr };

public:
    CLxLoc_PacketService()
    {
        _init();
        set();
    }

    ~CLxLoc_PacketService() = default;

    void set()
    {
        if (!m_loc)
        {
            m_loc = reinterpret_cast<ILxPacketServiceID>(lx::GetGlobal(&lx::guid_PacketService));
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

    auto Lookup(const char *category, const char *name, unsigned int *offset) -> LxResult
    {
        return m_loc[0]->Lookup(m_loc, category, name, offset);
    }

    auto Name(const char *category, unsigned int offset, const char **name) -> LxResult
    {
        return m_loc[0]->Name(m_loc, category, offset, name);
    }

    auto FastPacket(ILxUnknownID vector, unsigned int offset) -> void *
    {
        return m_loc[0]->FastPacket(m_loc,(ILxUnknownID) vector, offset);
    }

    auto CreateVectorType(const char *category, void **ppvObj) -> LxResult
    {
        return m_loc[0]->CreateVectorType(m_loc, category, ppvObj);
    }

    auto CreateVectorType(const char *category, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->CreateVectorType(m_loc, category, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto AddPacket(ILxUnknownID vtype, const char *name, unsigned int flags) -> LxResult
    {
        return m_loc[0]->AddPacket(m_loc,(ILxUnknownID) vtype, name, flags);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_VectorType : public CLxLocalize<ILxVectorTypeID>
{
public:
    CLxLoc_VectorType()
    {
        _init();
    }

    CLxLoc_VectorType(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_VectorType(CLxLoc_VectorType const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_VectorType;
    }

    auto Category(void) -> const char *
    {
        return m_loc[0]->Category(m_loc);
    }

    auto Test(unsigned int offset) -> unsigned int
    {
        return m_loc[0]->Test(m_loc, offset);
    }

    auto Count(unsigned int type) -> unsigned int
    {
        return m_loc[0]->Count(m_loc, type);
    }

    auto ByIndex(unsigned int type, unsigned int index, unsigned int *flags) -> unsigned int
    {
        return m_loc[0]->ByIndex(m_loc, type, index, flags);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_VectorStack : public CLxLocalize<ILxVectorStackID>
{
public:
    CLxLoc_VectorStack()
    {
        _init();
    }

    CLxLoc_VectorStack(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_VectorStack(CLxLoc_VectorStack const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_VectorStack;
    }

    auto Optional(unsigned int offset) -> void *
    {
        return m_loc[0]->Optional(m_loc, offset);
    }

    auto Readable(unsigned int offset, void **packet) -> LxResult
    {
        return m_loc[0]->Readable(m_loc, offset, packet);
    }

    auto Writable(unsigned int offset, void **packet) -> LxResult
    {
        return m_loc[0]->Writable(m_loc, offset, packet);
    }

    auto SetPacket(unsigned int offset, void *pdat) -> LxResult
    {
        return m_loc[0]->SetPacket(m_loc, offset, pdat);
    }

    auto Push(void) -> LxResult
    {
        return m_loc[0]->Push(m_loc);
    }

    auto Pop(void) -> LxResult
    {
        return m_loc[0]->Pop(m_loc);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_VectorList : public CLxLocalize<ILxVectorListID>
{
public:
    CLxLoc_VectorList()
    {
        _init();
    }

    CLxLoc_VectorList(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_VectorList(CLxLoc_VectorList const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_VectorList;
    }

    auto Optional(unsigned int offset) -> void *
    {
        return m_loc[0]->Optional(m_loc, offset);
    }

    auto Readable(unsigned int offset, void **packet) -> LxResult
    {
        return m_loc[0]->Readable(m_loc, offset, packet);
    }

    auto Writable(unsigned int offset, void **packet) -> LxResult
    {
        return m_loc[0]->Writable(m_loc, offset, packet);
    }

    auto SetPacket(unsigned int offset, void *pdat) -> LxResult
    {
        return m_loc[0]->SetPacket(m_loc, offset, pdat);
    }

    auto Append(unsigned int *index) -> LxResult
    {
        return m_loc[0]->Append(m_loc, index);
    }

    auto Current(void) -> unsigned int
    {
        return m_loc[0]->Current(m_loc);
    }

    auto SetCurrent(unsigned int index) -> LxResult
    {
        return m_loc[0]->SetCurrent(m_loc, index);
    }

    auto Count(void) -> unsigned int
    {
        return m_loc[0]->Count(m_loc);
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
class CLxImpl_TextureEffect
{
public:
    virtual ~CLxImpl_TextureEffect() = default;

    virtual unsigned int tfx_Type(void) = 0;

    virtual const char * tfx_TypeName(void) = 0;

    virtual auto tfx_Get([[maybe_unused]] ILxUnknownID sv, [[maybe_unused]] float *val, [[maybe_unused]] void *item) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto tfx_Set([[maybe_unused]] ILxUnknownID sv, [[maybe_unused]] const float *val, [[maybe_unused]] void *item) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_TextureEffect_Type unsigned int tfx_Type() override
#define LXxO_TextureEffect_Type LXxD_TextureEffect_Type
#define LXxC_TextureEffect_Type(c) unsigned int c::tfx_Type()
#define LXxD_TextureEffect_TypeName const char * tfx_TypeName() override
#define LXxO_TextureEffect_TypeName LXxD_TextureEffect_TypeName
#define LXxC_TextureEffect_TypeName(c) const char * c::tfx_TypeName()
#define LXxD_TextureEffect_Get LxResult tfx_Get([[maybe_unused]] ILxUnknownID sv, [[maybe_unused]] float *val, [[maybe_unused]] void *item) override
#define LXxO_TextureEffect_Get LXxD_TextureEffect_Get
#define LXxC_TextureEffect_Get(c) LxResult c::tfx_Get([[maybe_unused]] ILxUnknownID sv, [[maybe_unused]] float *val, [[maybe_unused]] void *item)
#define LXxD_TextureEffect_Set LxResult tfx_Set([[maybe_unused]] ILxUnknownID sv, [[maybe_unused]] const float *val, [[maybe_unused]] void *item) override
#define LXxO_TextureEffect_Set LXxD_TextureEffect_Set
#define LXxC_TextureEffect_Set(c) LxResult c::tfx_Set([[maybe_unused]] ILxUnknownID sv, [[maybe_unused]] const float *val, [[maybe_unused]] void *item)

template <class T>
class CLxIfc_TextureEffect: public CLxInterface
{
public:
    CLxIfc_TextureEffect()
    {
        vt.Type = Type;
        vt.TypeName = TypeName;
        vt.Get = Get;
        vt.Set = Set;
        vTable = &vt.iunk;
        iid = &lx::guid_TextureEffect;
    }

    static auto Type(LXtObjectID wcom) -> unsigned int
    {
        LXCWxINST (CLxImpl_TextureEffect, loc);
        return loc->tfx_Type();
    }

    static auto TypeName(LXtObjectID wcom) -> const char *
    {
        LXCWxINST (CLxImpl_TextureEffect, loc);
        return loc->tfx_TypeName();
    }

    static auto Get(LXtObjectID wcom,LXtObjectID sv,float *val,void *item) -> LxResult
    {
        LXCWxINST (CLxImpl_TextureEffect, loc);
        try
        {
           return loc->tfx_Get((ILxUnknownID) sv, val, item);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Set(LXtObjectID wcom,LXtObjectID sv,const float *val,void *item) -> LxResult
    {
        LXCWxINST (CLxImpl_TextureEffect, loc);
        try
        {
           return loc->tfx_Set((ILxUnknownID) sv, val, item);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxTextureEffect vt;
};

class CLxLoc_TextureEffect : public CLxLocalize<ILxTextureEffectID>
{
public:
    CLxLoc_TextureEffect()
    {
        _init();
    }

    CLxLoc_TextureEffect(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_TextureEffect(CLxLoc_TextureEffect const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_TextureEffect;
    }

    auto Type(void) -> unsigned int
    {
        return m_loc[0]->Type(m_loc);
    }

    auto TypeName(void) -> const char *
    {
        return m_loc[0]->TypeName(m_loc);
    }

    auto Get(ILxUnknownID sv, float *val, void *item) -> LxResult
    {
        return m_loc[0]->Get(m_loc,(ILxUnknownID) sv, val, item);
    }

    auto Set(ILxUnknownID sv, const float *val, void *item) -> LxResult
    {
        return m_loc[0]->Set(m_loc,(ILxUnknownID) sv, val, item);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_PacketEffect
{
public:
    virtual ~CLxImpl_PacketEffect() = default;

    virtual auto pfx_Packet([[maybe_unused]] const char **packet) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual unsigned int pfx_Count(void) = 0;

    virtual auto pfx_ByIndex([[maybe_unused]] int index, [[maybe_unused]] const char **name, [[maybe_unused]] const char **typeName, [[maybe_unused]] int *type) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto pfx_Get([[maybe_unused]] int index, [[maybe_unused]] void *packet, [[maybe_unused]] float *val, [[maybe_unused]] void *item) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto pfx_Set([[maybe_unused]] int index, [[maybe_unused]] void *packet, [[maybe_unused]] const float *val, [[maybe_unused]] void *item) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_PacketEffect_Packet LxResult pfx_Packet([[maybe_unused]] const char **packet) override
#define LXxO_PacketEffect_Packet LXxD_PacketEffect_Packet
#define LXxC_PacketEffect_Packet(c) LxResult c::pfx_Packet([[maybe_unused]] const char **packet)
#define LXxD_PacketEffect_Count unsigned int pfx_Count() override
#define LXxO_PacketEffect_Count LXxD_PacketEffect_Count
#define LXxC_PacketEffect_Count(c) unsigned int c::pfx_Count()
#define LXxD_PacketEffect_ByIndex LxResult pfx_ByIndex([[maybe_unused]] int index, [[maybe_unused]] const char **name, [[maybe_unused]] const char **typeName, [[maybe_unused]] int *type) override
#define LXxO_PacketEffect_ByIndex LXxD_PacketEffect_ByIndex
#define LXxC_PacketEffect_ByIndex(c) LxResult c::pfx_ByIndex([[maybe_unused]] int index, [[maybe_unused]] const char **name, [[maybe_unused]] const char **typeName, [[maybe_unused]] int *type)
#define LXxD_PacketEffect_Get LxResult pfx_Get([[maybe_unused]] int index, [[maybe_unused]] void *packet, [[maybe_unused]] float *val, [[maybe_unused]] void *item) override
#define LXxO_PacketEffect_Get LXxD_PacketEffect_Get
#define LXxC_PacketEffect_Get(c) LxResult c::pfx_Get([[maybe_unused]] int index, [[maybe_unused]] void *packet, [[maybe_unused]] float *val, [[maybe_unused]] void *item)
#define LXxD_PacketEffect_Set LxResult pfx_Set([[maybe_unused]] int index, [[maybe_unused]] void *packet, [[maybe_unused]] const float *val, [[maybe_unused]] void *item) override
#define LXxO_PacketEffect_Set LXxD_PacketEffect_Set
#define LXxC_PacketEffect_Set(c) LxResult c::pfx_Set([[maybe_unused]] int index, [[maybe_unused]] void *packet, [[maybe_unused]] const float *val, [[maybe_unused]] void *item)

template <class T>
class CLxIfc_PacketEffect: public CLxInterface
{
public:
    CLxIfc_PacketEffect()
    {
        vt.Packet = Packet;
        vt.Count = Count;
        vt.ByIndex = ByIndex;
        vt.Get = Get;
        vt.Set = Set;
        vTable = &vt.iunk;
        iid = &lx::guid_PacketEffect;
    }

    static auto Packet(LXtObjectID wcom,const char **packet) -> LxResult
    {
        LXCWxINST (CLxImpl_PacketEffect, loc);
        try
        {
           return loc->pfx_Packet( packet);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Count(LXtObjectID wcom) -> unsigned int
    {
        LXCWxINST (CLxImpl_PacketEffect, loc);
        return loc->pfx_Count();
    }

    static auto ByIndex(LXtObjectID wcom,int index,const char **name,const char **typeName,int *type) -> LxResult
    {
        LXCWxINST (CLxImpl_PacketEffect, loc);
        try
        {
           return loc->pfx_ByIndex( index, name, typeName, type);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Get(LXtObjectID wcom,int index,void *packet,float *val,void *item) -> LxResult
    {
        LXCWxINST (CLxImpl_PacketEffect, loc);
        try
        {
           return loc->pfx_Get( index, packet, val, item);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Set(LXtObjectID wcom,int index,void *packet,const float *val,void *item) -> LxResult
    {
        LXCWxINST (CLxImpl_PacketEffect, loc);
        try
        {
           return loc->pfx_Set( index, packet, val, item);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxPacketEffect vt;
};

class CLxLoc_PacketEffect : public CLxLocalize<ILxPacketEffectID>
{
public:
    CLxLoc_PacketEffect()
    {
        _init();
    }

    CLxLoc_PacketEffect(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_PacketEffect(CLxLoc_PacketEffect const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_PacketEffect;
    }

    auto Packet(const char **packet) -> LxResult
    {
        return m_loc[0]->Packet(m_loc, packet);
    }

    auto Count(void) -> unsigned int
    {
        return m_loc[0]->Count(m_loc);
    }

    auto ByIndex(int index, const char **name, const char **typeName, int *type) -> LxResult
    {
        return m_loc[0]->ByIndex(m_loc, index, name, typeName, type);
    }

    auto Get(int index, void *packet, float *val, void *item) -> LxResult
    {
        return m_loc[0]->Get(m_loc, index, packet, val, item);
    }

    auto Set(int index, void *packet, const float *val, void *item) -> LxResult
    {
        return m_loc[0]->Set(m_loc, index, packet, val, item);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
