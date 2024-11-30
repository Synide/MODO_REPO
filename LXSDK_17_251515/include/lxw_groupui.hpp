//
// C++ wrapper for lxsdk/lxgroupui.h.
//
//	Copyright 2024.
//
//
#pragma once

#include <lxgroupui.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx
{
    static LXtGUID const guid_GroupDest = {0x14B16A73, {0xF0A8, 0x459A}, {0xB1, 0xFD, 0x78, 0x50, 0xDF, 0x36, 0x80, 0x1C}};
    static LXtGUID const guid_GroupMemberItemDest = {0x15329747, {0xC092, 0x475A}, {0xB1, 0x88, 0x11, 0xA1, 0x9A, 0x15, 0x18, 0x86}};
    static LXtGUID const guid_GroupMemberChanDest = {0xC52AB199, {0x2410, 0x4698}, {0xB2, 0x6C, 0x45, 0xFA, 0x02, 0x4C, 0xBA, 0xE9}};
    static LXtGUID const guid_PoseItem = {0x73582252, {0x0845, 0x4B33}, {0x90, 0x00, 0x59, 0x6C, 0x78, 0x65, 0x67, 0x5F}};
} // namespace lx

class CLxImpl_GroupDest
{
public:
    virtual ~CLxImpl_GroupDest() = default;

    virtual auto grpd_Group([[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual int grpd_Location(void) = 0;
};

#define LXxD_GroupDest_Group LxResult grpd_Group([[maybe_unused]] void **ppvObj) override
#define LXxO_GroupDest_Group LXxD_GroupDest_Group
#define LXxC_GroupDest_Group(c) LxResult c::grpd_Group([[maybe_unused]] void **ppvObj)
#define LXxD_GroupDest_Location int grpd_Location() override
#define LXxO_GroupDest_Location LXxD_GroupDest_Location
#define LXxC_GroupDest_Location(c) int c::grpd_Location()

template <class T>
class CLxIfc_GroupDest: public CLxInterface
{
public:
    CLxIfc_GroupDest()
    {
        vt.Group = Group;
        vt.Location = Location;
        vTable = &vt.iunk;
        iid = &lx::guid_GroupDest;
    }

    static auto Group(LXtObjectID wcom,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_GroupDest, loc);
        try
        {
           return loc->grpd_Group( ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Location(LXtObjectID wcom) -> int
    {
        LXCWxINST (CLxImpl_GroupDest, loc);
        return loc->grpd_Location();
    }

private:
    ILxGroupDest vt;
};

class CLxLoc_GroupDest : public CLxLocalize<ILxGroupDestID>
{
public:
    CLxLoc_GroupDest()
    {
        _init();
    }

    CLxLoc_GroupDest(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_GroupDest(CLxLoc_GroupDest const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_GroupDest;
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
class CLxImpl_GroupMemberItemDest
{
public:
    virtual ~CLxImpl_GroupMemberItemDest() = default;

    virtual auto grpmid_Group([[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto grpmid_Item([[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual int grpmid_Location(void) = 0;
};

#define LXxD_GroupMemberItemDest_Group LxResult grpmid_Group([[maybe_unused]] void **ppvObj) override
#define LXxO_GroupMemberItemDest_Group LXxD_GroupMemberItemDest_Group
#define LXxC_GroupMemberItemDest_Group(c) LxResult c::grpmid_Group([[maybe_unused]] void **ppvObj)
#define LXxD_GroupMemberItemDest_Item LxResult grpmid_Item([[maybe_unused]] void **ppvObj) override
#define LXxO_GroupMemberItemDest_Item LXxD_GroupMemberItemDest_Item
#define LXxC_GroupMemberItemDest_Item(c) LxResult c::grpmid_Item([[maybe_unused]] void **ppvObj)
#define LXxD_GroupMemberItemDest_Location int grpmid_Location() override
#define LXxO_GroupMemberItemDest_Location LXxD_GroupMemberItemDest_Location
#define LXxC_GroupMemberItemDest_Location(c) int c::grpmid_Location()

template <class T>
class CLxIfc_GroupMemberItemDest: public CLxInterface
{
public:
    CLxIfc_GroupMemberItemDest()
    {
        vt.Group = Group;
        vt.Item = Item;
        vt.Location = Location;
        vTable = &vt.iunk;
        iid = &lx::guid_GroupMemberItemDest;
    }

    static auto Group(LXtObjectID wcom,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_GroupMemberItemDest, loc);
        try
        {
           return loc->grpmid_Group( ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Item(LXtObjectID wcom,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_GroupMemberItemDest, loc);
        try
        {
           return loc->grpmid_Item( ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Location(LXtObjectID wcom) -> int
    {
        LXCWxINST (CLxImpl_GroupMemberItemDest, loc);
        return loc->grpmid_Location();
    }

private:
    ILxGroupMemberItemDest vt;
};

class CLxLoc_GroupMemberItemDest : public CLxLocalize<ILxGroupMemberItemDestID>
{
public:
    CLxLoc_GroupMemberItemDest()
    {
        _init();
    }

    CLxLoc_GroupMemberItemDest(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_GroupMemberItemDest(CLxLoc_GroupMemberItemDest const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_GroupMemberItemDest;
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
class CLxImpl_GroupMemberChanDest
{
public:
    virtual ~CLxImpl_GroupMemberChanDest() = default;

    virtual auto grpmcd_Group([[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto grpmcd_Channel([[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual int grpmcd_Location(void) = 0;
};

#define LXxD_GroupMemberChanDest_Group LxResult grpmcd_Group([[maybe_unused]] void **ppvObj) override
#define LXxO_GroupMemberChanDest_Group LXxD_GroupMemberChanDest_Group
#define LXxC_GroupMemberChanDest_Group(c) LxResult c::grpmcd_Group([[maybe_unused]] void **ppvObj)
#define LXxD_GroupMemberChanDest_Channel LxResult grpmcd_Channel([[maybe_unused]] void **ppvObj) override
#define LXxO_GroupMemberChanDest_Channel LXxD_GroupMemberChanDest_Channel
#define LXxC_GroupMemberChanDest_Channel(c) LxResult c::grpmcd_Channel([[maybe_unused]] void **ppvObj)
#define LXxD_GroupMemberChanDest_Location int grpmcd_Location() override
#define LXxO_GroupMemberChanDest_Location LXxD_GroupMemberChanDest_Location
#define LXxC_GroupMemberChanDest_Location(c) int c::grpmcd_Location()

template <class T>
class CLxIfc_GroupMemberChanDest: public CLxInterface
{
public:
    CLxIfc_GroupMemberChanDest()
    {
        vt.Group = Group;
        vt.Channel = Channel;
        vt.Location = Location;
        vTable = &vt.iunk;
        iid = &lx::guid_GroupMemberChanDest;
    }

    static auto Group(LXtObjectID wcom,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_GroupMemberChanDest, loc);
        try
        {
           return loc->grpmcd_Group( ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Channel(LXtObjectID wcom,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_GroupMemberChanDest, loc);
        try
        {
           return loc->grpmcd_Channel( ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Location(LXtObjectID wcom) -> int
    {
        LXCWxINST (CLxImpl_GroupMemberChanDest, loc);
        return loc->grpmcd_Location();
    }

private:
    ILxGroupMemberChanDest vt;
};

class CLxLoc_GroupMemberChanDest : public CLxLocalize<ILxGroupMemberChanDestID>
{
public:
    CLxLoc_GroupMemberChanDest()
    {
        _init();
    }

    CLxLoc_GroupMemberChanDest(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_GroupMemberChanDest(CLxLoc_GroupMemberChanDest const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_GroupMemberChanDest;
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
class CLxLoc_PoseItem : public CLxLocalize<ILxPoseItemID>
{
public:
    CLxLoc_PoseItem()
    {
        _init();
    }

    CLxLoc_PoseItem(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_PoseItem(CLxLoc_PoseItem const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_PoseItem;
    }

    auto Create(void) -> LxResult
    {
        return m_loc[0]->Create(m_loc);
    }

    auto SetInt(ILxUnknownID item, unsigned int channelIndex, int value) -> LxResult
    {
        return m_loc[0]->SetInt(m_loc,(ILxUnknownID) item, channelIndex, value);
    }

    auto SetFloat(ILxUnknownID item, unsigned int channelIndex, float value) -> LxResult
    {
        return m_loc[0]->SetFloat(m_loc,(ILxUnknownID) item, channelIndex, value);
    }

    auto GetInt(ILxUnknownID item, unsigned int channelIndex, int *value) -> LxResult
    {
        return m_loc[0]->GetInt(m_loc,(ILxUnknownID) item, channelIndex, value);
    }

    auto GetFloat(ILxUnknownID item, unsigned int channelIndex, float *value) -> LxResult
    {
        return m_loc[0]->GetFloat(m_loc,(ILxUnknownID) item, channelIndex, value);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
