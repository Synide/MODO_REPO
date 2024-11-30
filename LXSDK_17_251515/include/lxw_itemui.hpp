//
// C++ wrapper for lxsdk/lxitemui.h.
//
//	Copyright 2024.
//
//
#pragma once

#include <lxitemui.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx
{
    static LXtGUID const guid_LocatorDest = {0x451EE72D, {0x640C, 0x43E4}, {0xAE, 0x1A, 0x15, 0x36, 0x84, 0x13, 0x3C, 0x65}};
    static LXtGUID const guid_MeshOpDest = {0x451EE72D, {0x640C, 0x43E4}, {0xAE, 0x1A, 0x15, 0x36, 0x84, 0x13, 0x3C, 0x42}};
    static LXtGUID const guid_ShaderDest = {0xb346d569, {0xc841, 0x46c8}, {0xb5, 0x01, 0x25, 0x65, 0x71, 0x21, 0x26, 0x66}};
    static LXtGUID const guid_MeshDest = {0xDD13F0F7, {0x9BA1, 0x42EB}, {0xB3, 0x6A, 0x65, 0x3B, 0x32, 0x2F, 0xD5, 0x20}};
    static LXtGUID const guid_ChannelDest = {0x0C84BE94, {0x9B18, 0x42F5}, {0xB3, 0x74, 0x48, 0xC5, 0xCD, 0x27, 0x8D, 0x55}};
    static LXtGUID const guid_ChannelDropPreview = {0x41fe952b, {0xdd79, 0x4fe7}, {0xb6, 0xe1, 0x3d, 0xae, 0x47, 0xce, 0xe3, 0x96}};
    static LXtGUID const guid_ItemTypeDest = {0xF088D1C9, {0x78D9, 0x4F73}, {0xA9, 0x06, 0x9B, 0xD7, 0xED, 0xA0, 0xB4, 0x7D}};
} // namespace lx

class CLxImpl_LocatorDest
{
public:
    virtual ~CLxImpl_LocatorDest() = default;

    virtual auto locd_Item([[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual int locd_Location(void) = 0;
};

#define LXxD_LocatorDest_Item LxResult locd_Item([[maybe_unused]] void **ppvObj) override
#define LXxO_LocatorDest_Item LXxD_LocatorDest_Item
#define LXxC_LocatorDest_Item(c) LxResult c::locd_Item([[maybe_unused]] void **ppvObj)
#define LXxD_LocatorDest_Location int locd_Location() override
#define LXxO_LocatorDest_Location LXxD_LocatorDest_Location
#define LXxC_LocatorDest_Location(c) int c::locd_Location()

template <class T>
class CLxIfc_LocatorDest: public CLxInterface
{
public:
    CLxIfc_LocatorDest()
    {
        vt.Item = Item;
        vt.Location = Location;
        vTable = &vt.iunk;
        iid = &lx::guid_LocatorDest;
    }

    static auto Item(LXtObjectID wcom,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_LocatorDest, loc);
        try
        {
           return loc->locd_Item( ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Location(LXtObjectID wcom) -> int
    {
        LXCWxINST (CLxImpl_LocatorDest, loc);
        return loc->locd_Location();
    }

private:
    ILxLocatorDest vt;
};

class CLxLoc_LocatorDest : public CLxLocalize<ILxLocatorDestID>
{
public:
    CLxLoc_LocatorDest()
    {
        _init();
    }

    CLxLoc_LocatorDest(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_LocatorDest(CLxLoc_LocatorDest const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_LocatorDest;
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

    auto Location(void) -> int
    {
        return m_loc[0]->Location(m_loc);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_MeshOpDest
{
public:
    virtual ~CLxImpl_MeshOpDest() = default;

    virtual auto locd_Item([[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto locd_ItemDeformer([[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto locd_ItemHG([[maybe_unused]] void **itemHG) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual const char* locd_Graph(void) = 0;

    virtual int locd_Location(void) = 0;
};

#define LXxD_MeshOpDest_Item LxResult locd_Item([[maybe_unused]] void **ppvObj) override
#define LXxO_MeshOpDest_Item LXxD_MeshOpDest_Item
#define LXxC_MeshOpDest_Item(c) LxResult c::locd_Item([[maybe_unused]] void **ppvObj)
#define LXxD_MeshOpDest_ItemDeformer LxResult locd_ItemDeformer([[maybe_unused]] void **ppvObj) override
#define LXxO_MeshOpDest_ItemDeformer LXxD_MeshOpDest_ItemDeformer
#define LXxC_MeshOpDest_ItemDeformer(c) LxResult c::locd_ItemDeformer([[maybe_unused]] void **ppvObj)
#define LXxD_MeshOpDest_ItemHG LxResult locd_ItemHG([[maybe_unused]] void **itemHG) override
#define LXxO_MeshOpDest_ItemHG LXxD_MeshOpDest_ItemHG
#define LXxC_MeshOpDest_ItemHG(c) LxResult c::locd_ItemHG([[maybe_unused]] void **itemHG)
#define LXxD_MeshOpDest_Graph const char* locd_Graph() override
#define LXxO_MeshOpDest_Graph LXxD_MeshOpDest_Graph
#define LXxC_MeshOpDest_Graph(c) const char* c::locd_Graph()
#define LXxD_MeshOpDest_Location int locd_Location() override
#define LXxO_MeshOpDest_Location LXxD_MeshOpDest_Location
#define LXxC_MeshOpDest_Location(c) int c::locd_Location()

template <class T>
class CLxIfc_MeshOpDest: public CLxInterface
{
public:
    CLxIfc_MeshOpDest()
    {
        vt.Item = Item;
        vt.ItemDeformer = ItemDeformer;
        vt.ItemHG = ItemHG;
        vt.Graph = Graph;
        vt.Location = Location;
        vTable = &vt.iunk;
        iid = &lx::guid_MeshOpDest;
    }

    static auto Item(LXtObjectID wcom,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_MeshOpDest, loc);
        try
        {
           return loc->locd_Item( ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ItemDeformer(LXtObjectID wcom,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_MeshOpDest, loc);
        try
        {
           return loc->locd_ItemDeformer( ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ItemHG(LXtObjectID wcom,void **itemHG) -> LxResult
    {
        LXCWxINST (CLxImpl_MeshOpDest, loc);
        try
        {
           return loc->locd_ItemHG( itemHG);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Graph(LXtObjectID wcom) -> const char*
    {
        LXCWxINST (CLxImpl_MeshOpDest, loc);
        return loc->locd_Graph();
    }

    static auto Location(LXtObjectID wcom) -> int
    {
        LXCWxINST (CLxImpl_MeshOpDest, loc);
        return loc->locd_Location();
    }

private:
    ILxMeshOpDest vt;
};

class CLxLoc_MeshOpDest : public CLxLocalize<ILxMeshOpDestID>
{
public:
    CLxLoc_MeshOpDest()
    {
        _init();
    }

    CLxLoc_MeshOpDest(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_MeshOpDest(CLxLoc_MeshOpDest const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_MeshOpDest;
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

    auto ItemDeformer(void **ppvObj) -> LxResult
    {
        return m_loc[0]->ItemDeformer(m_loc, ppvObj);
    }

    auto ItemDeformer(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->ItemDeformer(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto ItemHG(void **itemHG) -> LxResult
    {
        return m_loc[0]->ItemHG(m_loc, itemHG);
    }

    auto Graph(void) -> const char*
    {
        return m_loc[0]->Graph(m_loc);
    }

    auto Location(void) -> int
    {
        return m_loc[0]->Location(m_loc);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_ShaderDest
{
public:
    virtual ~CLxImpl_ShaderDest() = default;

    virtual auto locd_Item([[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual int locd_Type(void) = 0;

    virtual int locd_Location(void) = 0;
};

#define LXxD_ShaderDest_Item LxResult locd_Item([[maybe_unused]] void **ppvObj) override
#define LXxO_ShaderDest_Item LXxD_ShaderDest_Item
#define LXxC_ShaderDest_Item(c) LxResult c::locd_Item([[maybe_unused]] void **ppvObj)
#define LXxD_ShaderDest_Type int locd_Type() override
#define LXxO_ShaderDest_Type LXxD_ShaderDest_Type
#define LXxC_ShaderDest_Type(c) int c::locd_Type()
#define LXxD_ShaderDest_Location int locd_Location() override
#define LXxO_ShaderDest_Location LXxD_ShaderDest_Location
#define LXxC_ShaderDest_Location(c) int c::locd_Location()

template <class T>
class CLxIfc_ShaderDest: public CLxInterface
{
public:
    CLxIfc_ShaderDest()
    {
        vt.Item = Item;
        vt.Type = Type;
        vt.Location = Location;
        vTable = &vt.iunk;
        iid = &lx::guid_ShaderDest;
    }

    static auto Item(LXtObjectID wcom,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_ShaderDest, loc);
        try
        {
           return loc->locd_Item( ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Type(LXtObjectID wcom) -> int
    {
        LXCWxINST (CLxImpl_ShaderDest, loc);
        return loc->locd_Type();
    }

    static auto Location(LXtObjectID wcom) -> int
    {
        LXCWxINST (CLxImpl_ShaderDest, loc);
        return loc->locd_Location();
    }

private:
    ILxShaderDest vt;
};

class CLxLoc_ShaderDest : public CLxLocalize<ILxShaderDestID>
{
public:
    CLxLoc_ShaderDest()
    {
        _init();
    }

    CLxLoc_ShaderDest(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_ShaderDest(CLxLoc_ShaderDest const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_ShaderDest;
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

    auto Type(void) -> int
    {
        return m_loc[0]->Type(m_loc);
    }

    auto Location(void) -> int
    {
        return m_loc[0]->Location(m_loc);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_MeshDest
{
public:
    virtual ~CLxImpl_MeshDest() = default;

    virtual auto meshd_Item([[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto meshd_HitPosition([[maybe_unused]] LXtVector pos) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto meshd_HitNormal([[maybe_unused]] LXtVector nrm) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_MeshDest_Item LxResult meshd_Item([[maybe_unused]] void **ppvObj) override
#define LXxO_MeshDest_Item LXxD_MeshDest_Item
#define LXxC_MeshDest_Item(c) LxResult c::meshd_Item([[maybe_unused]] void **ppvObj)
#define LXxD_MeshDest_HitPosition LxResult meshd_HitPosition([[maybe_unused]] LXtVector pos) override
#define LXxO_MeshDest_HitPosition LXxD_MeshDest_HitPosition
#define LXxC_MeshDest_HitPosition(c) LxResult c::meshd_HitPosition([[maybe_unused]] LXtVector pos)
#define LXxD_MeshDest_HitNormal LxResult meshd_HitNormal([[maybe_unused]] LXtVector nrm) override
#define LXxO_MeshDest_HitNormal LXxD_MeshDest_HitNormal
#define LXxC_MeshDest_HitNormal(c) LxResult c::meshd_HitNormal([[maybe_unused]] LXtVector nrm)

template <class T>
class CLxIfc_MeshDest: public CLxInterface
{
public:
    CLxIfc_MeshDest()
    {
        vt.Item = Item;
        vt.HitPosition = HitPosition;
        vt.HitNormal = HitNormal;
        vTable = &vt.iunk;
        iid = &lx::guid_MeshDest;
    }

    static auto Item(LXtObjectID wcom,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_MeshDest, loc);
        try
        {
           return loc->meshd_Item( ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto HitPosition(LXtObjectID wcom,LXtVector pos) -> LxResult
    {
        LXCWxINST (CLxImpl_MeshDest, loc);
        try
        {
           return loc->meshd_HitPosition( pos);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto HitNormal(LXtObjectID wcom,LXtVector nrm) -> LxResult
    {
        LXCWxINST (CLxImpl_MeshDest, loc);
        try
        {
           return loc->meshd_HitNormal( nrm);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxMeshDest vt;
};

class CLxLoc_MeshDest : public CLxLocalize<ILxMeshDestID>
{
public:
    CLxLoc_MeshDest()
    {
        _init();
    }

    CLxLoc_MeshDest(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_MeshDest(CLxLoc_MeshDest const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_MeshDest;
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

    auto HitPosition(LXtVector pos) -> LxResult
    {
        return m_loc[0]->HitPosition(m_loc, pos);
    }

    auto HitNormal(LXtVector nrm) -> LxResult
    {
        return m_loc[0]->HitNormal(m_loc, nrm);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_ChannelDest
{
public:
    virtual ~CLxImpl_ChannelDest() = default;

    virtual auto chand_Channel([[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual int chand_Location(void) = 0;
};

#define LXxD_ChannelDest_Channel LxResult chand_Channel([[maybe_unused]] void **ppvObj) override
#define LXxO_ChannelDest_Channel LXxD_ChannelDest_Channel
#define LXxC_ChannelDest_Channel(c) LxResult c::chand_Channel([[maybe_unused]] void **ppvObj)
#define LXxD_ChannelDest_Location int chand_Location() override
#define LXxO_ChannelDest_Location LXxD_ChannelDest_Location
#define LXxC_ChannelDest_Location(c) int c::chand_Location()

template <class T>
class CLxIfc_ChannelDest: public CLxInterface
{
public:
    CLxIfc_ChannelDest()
    {
        vt.Channel = Channel;
        vt.Location = Location;
        vTable = &vt.iunk;
        iid = &lx::guid_ChannelDest;
    }

    static auto Channel(LXtObjectID wcom,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_ChannelDest, loc);
        try
        {
           return loc->chand_Channel( ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Location(LXtObjectID wcom) -> int
    {
        LXCWxINST (CLxImpl_ChannelDest, loc);
        return loc->chand_Location();
    }

private:
    ILxChannelDest vt;
};

class CLxLoc_ChannelDest : public CLxLocalize<ILxChannelDestID>
{
public:
    CLxLoc_ChannelDest()
    {
        _init();
    }

    CLxLoc_ChannelDest(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_ChannelDest(CLxLoc_ChannelDest const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_ChannelDest;
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

    auto Location(void) -> int
    {
        return m_loc[0]->Location(m_loc);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_ChannelDropPreview
{
public:
    virtual ~CLxImpl_ChannelDropPreview() = default;

    virtual int chandp_MarkChannel(void) = 0;
};

#define LXxD_ChannelDropPreview_MarkChannel int chandp_MarkChannel() override
#define LXxO_ChannelDropPreview_MarkChannel LXxD_ChannelDropPreview_MarkChannel
#define LXxC_ChannelDropPreview_MarkChannel(c) int c::chandp_MarkChannel()

template <class T>
class CLxIfc_ChannelDropPreview: public CLxInterface
{
public:
    CLxIfc_ChannelDropPreview()
    {
        vt.MarkChannel = MarkChannel;
        vTable = &vt.iunk;
        iid = &lx::guid_ChannelDropPreview;
    }

    static auto MarkChannel(LXtObjectID wcom) -> int
    {
        LXCWxINST (CLxImpl_ChannelDropPreview, loc);
        return loc->chandp_MarkChannel();
    }

private:
    ILxChannelDropPreview vt;
};

class CLxLoc_ChannelDropPreview : public CLxLocalize<ILxChannelDropPreviewID>
{
public:
    CLxLoc_ChannelDropPreview()
    {
        _init();
    }

    CLxLoc_ChannelDropPreview(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_ChannelDropPreview(CLxLoc_ChannelDropPreview const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_ChannelDropPreview;
    }

    auto MarkChannel(void) -> int
    {
        return m_loc[0]->MarkChannel(m_loc);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_ItemTypeDest
{
public:
    virtual ~CLxImpl_ItemTypeDest() = default;

    virtual auto ityped_Item([[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual int ityped_Location(void) = 0;
};

#define LXxD_ItemTypeDest_Item LxResult ityped_Item([[maybe_unused]] void **ppvObj) override
#define LXxO_ItemTypeDest_Item LXxD_ItemTypeDest_Item
#define LXxC_ItemTypeDest_Item(c) LxResult c::ityped_Item([[maybe_unused]] void **ppvObj)
#define LXxD_ItemTypeDest_Location int ityped_Location() override
#define LXxO_ItemTypeDest_Location LXxD_ItemTypeDest_Location
#define LXxC_ItemTypeDest_Location(c) int c::ityped_Location()

template <class T>
class CLxIfc_ItemTypeDest: public CLxInterface
{
public:
    CLxIfc_ItemTypeDest()
    {
        vt.Item = Item;
        vt.Location = Location;
        vTable = &vt.iunk;
        iid = &lx::guid_ItemTypeDest;
    }

    static auto Item(LXtObjectID wcom,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_ItemTypeDest, loc);
        try
        {
           return loc->ityped_Item( ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Location(LXtObjectID wcom) -> int
    {
        LXCWxINST (CLxImpl_ItemTypeDest, loc);
        return loc->ityped_Location();
    }

private:
    ILxItemTypeDest vt;
};

class CLxLoc_ItemTypeDest : public CLxLocalize<ILxItemTypeDestID>
{
public:
    CLxLoc_ItemTypeDest()
    {
        _init();
    }

    CLxLoc_ItemTypeDest(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_ItemTypeDest(CLxLoc_ItemTypeDest const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_ItemTypeDest;
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

    auto Location(void) -> int
    {
        return m_loc[0]->Location(m_loc);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
