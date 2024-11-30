//
// C++ wrapper for lxsdk/lxpackage.h.
//
//	Copyright 2024.
//
//
#pragma once

#include <lxpackage.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx
{
    static LXtGUID const guid_SceneEvalListener = {0x7793643D, {0xFA56, 0x4198}, {0x96, 0x3B, 0xAE, 0x8F, 0xAC, 0x69, 0xF4, 0x8D}};
    static LXtGUID const guid_SceneEvalListener1 = {0x816116A8, {0xB180, 0x49E1}, {0x99, 0x84, 0x0D, 0xE3, 0x53, 0x1B, 0xDE, 0x55}};
    static LXtGUID const guid_SceneItemListener1 = {0xBCCD05F8, {0xE560, 0x11D7}, {0xB3, 0xB8, 0x00, 0x03, 0x93, 0xCE, 0x96, 0x80}};
    static LXtGUID const guid_SceneItemListener2 = {0xC72C641E, {0xCDCD, 0x431B}, {0xAD, 0xD9, 0xD7, 0x55, 0x54, 0xD6, 0x56, 0xE1}};
    static LXtGUID const guid_SceneItemListener = {0xAFB67180, {0xEC4F, 0x4E9B}, {0xAA, 0xF1, 0x67, 0xAA, 0x47, 0x09, 0x7C, 0x29}};
    static LXtGUID const guid_SceneLoaderTarget = {0xA914B4F9, {0x947C, 0x4334}, {0x9D, 0x89, 0x64, 0xBB, 0x8D, 0xC2, 0x6B, 0xF6}};
    static LXtGUID const guid_Scene1 = {0x4340A8FC, {0xF984, 0x4E04}, {0xA4, 0xBB, 0x83, 0x93, 0x1A, 0x63, 0x35, 0xAF}};
    static LXtGUID const guid_Item1 = {0x5B14C8B6, {0x29EF, 0x473A}, {0xB1, 0xB3, 0x56, 0x8D, 0xFD, 0x9A, 0xE8, 0xD7}};
    static LXtGUID const guid_Package = {0x01DA3920, {0x484A, 0x415F}, {0xAF, 0xF7, 0x5A, 0x27, 0x4B, 0x77, 0xAC, 0x3A}};
    static LXtGUID const guid_AddChannel = {0x47C1E8A9, {0x6C76, 0x4068}, {0xBD, 0x4F, 0x36, 0x00, 0x15, 0x68, 0x3C, 0xD0}};
    static LXtGUID const guid_AddChannel1 = {0x6E732ACC, {0xAAA5, 0x4695}, {0xB5, 0xDE, 0x80, 0x59, 0xA2, 0x80, 0x05, 0x54}};
    static LXtGUID const guid_ItemCollection = {0x8D37934E, {0xF517, 0x45F1}, {0x90, 0xF0, 0x8C, 0x17, 0xF5, 0x95, 0xDC, 0x7D}};
    static LXtGUID const guid_PackageInstance = {0x68DD1902, {0xE5AB, 0x4591}, {0xBF, 0x93, 0xB8, 0x3C, 0x85, 0x6D, 0x19, 0x08}};
    static LXtGUID const guid_AssemblyAlias = {0x1794FFAE, {0x1E80, 0x4211}, {0xB1, 0xE8, 0xCE, 0x09, 0xB4, 0x70, 0xB2, 0x0C}};
    static LXtGUID const guid_PackageInstance1 = {0x09D603F7, {0xCCF6, 0x4A5C}, {0xB4, 0x1C, 0x02, 0x1A, 0xC6, 0xC1, 0x7A, 0x94}};
    static LXtGUID const guid_Package1 = {0x6383211E, {0x2624, 0x492e}, {0x8C, 0x4B, 0xD0, 0x6B, 0xB4, 0x38, 0x86, 0xA7}};
} // namespace lx

class CLxImpl_SceneEvalListener
{
public:
    virtual ~CLxImpl_SceneEvalListener() = default;

    virtual void sel_ChannelValue([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned index)
    {
    }

    virtual void sel_ChannelPreValue([[maybe_unused]] void)
    {
    }

    virtual void sel_ChannelPostValue([[maybe_unused]] void)
    {
    }
};

#define LXxD_SceneEvalListener_ChannelValue void sel_ChannelValue([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned index) override
#define LXxO_SceneEvalListener_ChannelValue LXxD_SceneEvalListener_ChannelValue
#define LXxC_SceneEvalListener_ChannelValue(c) void c::sel_ChannelValue([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned index)
#define LXxD_SceneEvalListener_ChannelPreValue void sel_ChannelPreValue() override
#define LXxO_SceneEvalListener_ChannelPreValue LXxD_SceneEvalListener_ChannelPreValue
#define LXxC_SceneEvalListener_ChannelPreValue(c) void c::sel_ChannelPreValue()
#define LXxD_SceneEvalListener_ChannelPostValue void sel_ChannelPostValue() override
#define LXxO_SceneEvalListener_ChannelPostValue LXxD_SceneEvalListener_ChannelPostValue
#define LXxC_SceneEvalListener_ChannelPostValue(c) void c::sel_ChannelPostValue()

template <class T>
class CLxIfc_SceneEvalListener: public CLxInterface
{
public:
    CLxIfc_SceneEvalListener()
    {
        vt.ChannelValue = ChannelValue;
        vt.ChannelPreValue = ChannelPreValue;
        vt.ChannelPostValue = ChannelPostValue;
        vTable = &vt.iunk;
        iid = &lx::guid_SceneEvalListener;
    }

    static auto ChannelValue(LXtObjectID wcom,LXtObjectID item,unsigned index) -> void
    {
        LXCWxINST (CLxImpl_SceneEvalListener, loc);
        loc->sel_ChannelValue((ILxUnknownID) item, index);
    }

    static auto ChannelPreValue(LXtObjectID wcom) -> void
    {
        LXCWxINST (CLxImpl_SceneEvalListener, loc);
        loc->sel_ChannelPreValue();
    }

    static auto ChannelPostValue(LXtObjectID wcom) -> void
    {
        LXCWxINST (CLxImpl_SceneEvalListener, loc);
        loc->sel_ChannelPostValue();
    }

private:
    ILxSceneEvalListener vt;
};

class CLxLoc_SceneEvalListener : public CLxLocalize<ILxSceneEvalListenerID>
{
public:
    CLxLoc_SceneEvalListener()
    {
        _init();
    }

    CLxLoc_SceneEvalListener(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_SceneEvalListener(CLxLoc_SceneEvalListener const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_SceneEvalListener;
    }

    auto ChannelValue(ILxUnknownID item, unsigned index) -> void
    {
        m_loc[0]->ChannelValue(m_loc,(ILxUnknownID) item, index);
    }

    auto ChannelPreValue(void) -> void
    {
        m_loc[0]->ChannelPreValue(m_loc);
    }

    auto ChannelPostValue(void) -> void
    {
        m_loc[0]->ChannelPostValue(m_loc);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};



class CLxImpl_SceneItemListener
{
public:
    virtual ~CLxImpl_SceneItemListener() = default;

    virtual void sil_SceneCreate([[maybe_unused]] ILxUnknownID scene)
    {
    }

    virtual void sil_SceneDestroy([[maybe_unused]] ILxUnknownID scene)
    {
    }

    virtual void sil_SceneFilename([[maybe_unused]] ILxUnknownID scene, [[maybe_unused]] const char *filename)
    {
    }

    virtual void sil_SceneClear([[maybe_unused]] ILxUnknownID scene)
    {
    }

    virtual void sil_ItemPreChange([[maybe_unused]] ILxUnknownID scene)
    {
    }

    virtual void sil_ItemPostDelete([[maybe_unused]] ILxUnknownID scene)
    {
    }

    virtual void sil_ItemAdd([[maybe_unused]] ILxUnknownID item)
    {
    }

    virtual void sil_ItemRemove([[maybe_unused]] ILxUnknownID item)
    {
    }

    virtual void sil_ItemParent([[maybe_unused]] ILxUnknownID item)
    {
    }

    virtual void sil_ItemChild([[maybe_unused]] ILxUnknownID item)
    {
    }

    virtual void sil_ItemAddChannel([[maybe_unused]] ILxUnknownID item)
    {
    }

    virtual void sil_ItemLocal([[maybe_unused]] ILxUnknownID item)
    {
    }

    virtual void sil_ItemName([[maybe_unused]] ILxUnknownID item)
    {
    }

    virtual void sil_ItemSource([[maybe_unused]] ILxUnknownID item)
    {
    }

    virtual void sil_ItemPackage([[maybe_unused]] ILxUnknownID item)
    {
    }

    virtual void sil_ChannelValue([[maybe_unused]] const char *action, [[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned index)
    {
    }

    virtual void sil_LinkAdd([[maybe_unused]] const char *graph, [[maybe_unused]] ILxUnknownID itemFrom, [[maybe_unused]] ILxUnknownID itemTo)
    {
    }

    virtual void sil_LinkRemBefore([[maybe_unused]] const char *graph, [[maybe_unused]] ILxUnknownID itemFrom, [[maybe_unused]] ILxUnknownID itemTo)
    {
    }

    virtual void sil_LinkRemAfter([[maybe_unused]] const char *graph, [[maybe_unused]] ILxUnknownID itemFrom, [[maybe_unused]] ILxUnknownID itemTo)
    {
    }

    virtual void sil_LinkSet([[maybe_unused]] const char *graph, [[maybe_unused]] ILxUnknownID itemFrom, [[maybe_unused]] ILxUnknownID itemTo)
    {
    }

    virtual void sil_ChanLinkAdd([[maybe_unused]] const char *graph, [[maybe_unused]] ILxUnknownID itemFrom, [[maybe_unused]] unsigned chanFrom, [[maybe_unused]] ILxUnknownID itemTo, [[maybe_unused]] unsigned chanTo)
    {
    }

    virtual void sil_ChanLinkRemBefore([[maybe_unused]] const char *graph, [[maybe_unused]] ILxUnknownID itemFrom, [[maybe_unused]] unsigned chanFrom, [[maybe_unused]] ILxUnknownID itemTo, [[maybe_unused]] unsigned chanTo)
    {
    }

    virtual void sil_ChanLinkRemAfter([[maybe_unused]] const char *graph, [[maybe_unused]] ILxUnknownID itemFrom, [[maybe_unused]] unsigned chanFrom, [[maybe_unused]] ILxUnknownID itemTo, [[maybe_unused]] unsigned chanTo)
    {
    }

    virtual void sil_ChanLinkSet([[maybe_unused]] const char *graph, [[maybe_unused]] ILxUnknownID itemFrom, [[maybe_unused]] unsigned chanFrom, [[maybe_unused]] ILxUnknownID itemTo, [[maybe_unused]] unsigned chanTo)
    {
    }

    virtual void sil_ItemTag([[maybe_unused]] ILxUnknownID item)
    {
    }

    virtual void sil_ItemRemoveChannel([[maybe_unused]] ILxUnknownID item)
    {
    }

    virtual void sil_ItemChannelName([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned int index)
    {
    }

    virtual void sil_ItemChannelDefault([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned int index)
    {
    }

    virtual void sil_ItemChannelMinMax([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned int index)
    {
    }

    virtual void sil_ItemChannelType([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned int index)
    {
    }
};

#define LXxD_SceneItemListener_SceneCreate void sil_SceneCreate([[maybe_unused]] ILxUnknownID scene) override
#define LXxO_SceneItemListener_SceneCreate LXxD_SceneItemListener_SceneCreate
#define LXxC_SceneItemListener_SceneCreate(c) void c::sil_SceneCreate([[maybe_unused]] ILxUnknownID scene)
#define LXxD_SceneItemListener_SceneDestroy void sil_SceneDestroy([[maybe_unused]] ILxUnknownID scene) override
#define LXxO_SceneItemListener_SceneDestroy LXxD_SceneItemListener_SceneDestroy
#define LXxC_SceneItemListener_SceneDestroy(c) void c::sil_SceneDestroy([[maybe_unused]] ILxUnknownID scene)
#define LXxD_SceneItemListener_SceneFilename void sil_SceneFilename([[maybe_unused]] ILxUnknownID scene, [[maybe_unused]] const char *filename) override
#define LXxO_SceneItemListener_SceneFilename LXxD_SceneItemListener_SceneFilename
#define LXxC_SceneItemListener_SceneFilename(c) void c::sil_SceneFilename([[maybe_unused]] ILxUnknownID scene, [[maybe_unused]] const char *filename)
#define LXxD_SceneItemListener_SceneClear void sil_SceneClear([[maybe_unused]] ILxUnknownID scene) override
#define LXxO_SceneItemListener_SceneClear LXxD_SceneItemListener_SceneClear
#define LXxC_SceneItemListener_SceneClear(c) void c::sil_SceneClear([[maybe_unused]] ILxUnknownID scene)
#define LXxD_SceneItemListener_ItemPreChange void sil_ItemPreChange([[maybe_unused]] ILxUnknownID scene) override
#define LXxO_SceneItemListener_ItemPreChange LXxD_SceneItemListener_ItemPreChange
#define LXxC_SceneItemListener_ItemPreChange(c) void c::sil_ItemPreChange([[maybe_unused]] ILxUnknownID scene)
#define LXxD_SceneItemListener_ItemPostDelete void sil_ItemPostDelete([[maybe_unused]] ILxUnknownID scene) override
#define LXxO_SceneItemListener_ItemPostDelete LXxD_SceneItemListener_ItemPostDelete
#define LXxC_SceneItemListener_ItemPostDelete(c) void c::sil_ItemPostDelete([[maybe_unused]] ILxUnknownID scene)
#define LXxD_SceneItemListener_ItemAdd void sil_ItemAdd([[maybe_unused]] ILxUnknownID item) override
#define LXxO_SceneItemListener_ItemAdd LXxD_SceneItemListener_ItemAdd
#define LXxC_SceneItemListener_ItemAdd(c) void c::sil_ItemAdd([[maybe_unused]] ILxUnknownID item)
#define LXxD_SceneItemListener_ItemRemove void sil_ItemRemove([[maybe_unused]] ILxUnknownID item) override
#define LXxO_SceneItemListener_ItemRemove LXxD_SceneItemListener_ItemRemove
#define LXxC_SceneItemListener_ItemRemove(c) void c::sil_ItemRemove([[maybe_unused]] ILxUnknownID item)
#define LXxD_SceneItemListener_ItemParent void sil_ItemParent([[maybe_unused]] ILxUnknownID item) override
#define LXxO_SceneItemListener_ItemParent LXxD_SceneItemListener_ItemParent
#define LXxC_SceneItemListener_ItemParent(c) void c::sil_ItemParent([[maybe_unused]] ILxUnknownID item)
#define LXxD_SceneItemListener_ItemChild void sil_ItemChild([[maybe_unused]] ILxUnknownID item) override
#define LXxO_SceneItemListener_ItemChild LXxD_SceneItemListener_ItemChild
#define LXxC_SceneItemListener_ItemChild(c) void c::sil_ItemChild([[maybe_unused]] ILxUnknownID item)
#define LXxD_SceneItemListener_ItemAddChannel void sil_ItemAddChannel([[maybe_unused]] ILxUnknownID item) override
#define LXxO_SceneItemListener_ItemAddChannel LXxD_SceneItemListener_ItemAddChannel
#define LXxC_SceneItemListener_ItemAddChannel(c) void c::sil_ItemAddChannel([[maybe_unused]] ILxUnknownID item)
#define LXxD_SceneItemListener_ItemLocal void sil_ItemLocal([[maybe_unused]] ILxUnknownID item) override
#define LXxO_SceneItemListener_ItemLocal LXxD_SceneItemListener_ItemLocal
#define LXxC_SceneItemListener_ItemLocal(c) void c::sil_ItemLocal([[maybe_unused]] ILxUnknownID item)
#define LXxD_SceneItemListener_ItemName void sil_ItemName([[maybe_unused]] ILxUnknownID item) override
#define LXxO_SceneItemListener_ItemName LXxD_SceneItemListener_ItemName
#define LXxC_SceneItemListener_ItemName(c) void c::sil_ItemName([[maybe_unused]] ILxUnknownID item)
#define LXxD_SceneItemListener_ItemSource void sil_ItemSource([[maybe_unused]] ILxUnknownID item) override
#define LXxO_SceneItemListener_ItemSource LXxD_SceneItemListener_ItemSource
#define LXxC_SceneItemListener_ItemSource(c) void c::sil_ItemSource([[maybe_unused]] ILxUnknownID item)
#define LXxD_SceneItemListener_ItemPackage void sil_ItemPackage([[maybe_unused]] ILxUnknownID item) override
#define LXxO_SceneItemListener_ItemPackage LXxD_SceneItemListener_ItemPackage
#define LXxC_SceneItemListener_ItemPackage(c) void c::sil_ItemPackage([[maybe_unused]] ILxUnknownID item)
#define LXxD_SceneItemListener_ChannelValue void sil_ChannelValue([[maybe_unused]] const char *action, [[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned index) override
#define LXxO_SceneItemListener_ChannelValue LXxD_SceneItemListener_ChannelValue
#define LXxC_SceneItemListener_ChannelValue(c) void c::sil_ChannelValue([[maybe_unused]] const char *action, [[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned index)
#define LXxD_SceneItemListener_LinkAdd void sil_LinkAdd([[maybe_unused]] const char *graph, [[maybe_unused]] ILxUnknownID itemFrom, [[maybe_unused]] ILxUnknownID itemTo) override
#define LXxO_SceneItemListener_LinkAdd LXxD_SceneItemListener_LinkAdd
#define LXxC_SceneItemListener_LinkAdd(c) void c::sil_LinkAdd([[maybe_unused]] const char *graph, [[maybe_unused]] ILxUnknownID itemFrom, [[maybe_unused]] ILxUnknownID itemTo)
#define LXxD_SceneItemListener_LinkRemBefore void sil_LinkRemBefore([[maybe_unused]] const char *graph, [[maybe_unused]] ILxUnknownID itemFrom, [[maybe_unused]] ILxUnknownID itemTo) override
#define LXxO_SceneItemListener_LinkRemBefore LXxD_SceneItemListener_LinkRemBefore
#define LXxC_SceneItemListener_LinkRemBefore(c) void c::sil_LinkRemBefore([[maybe_unused]] const char *graph, [[maybe_unused]] ILxUnknownID itemFrom, [[maybe_unused]] ILxUnknownID itemTo)
#define LXxD_SceneItemListener_LinkRemAfter void sil_LinkRemAfter([[maybe_unused]] const char *graph, [[maybe_unused]] ILxUnknownID itemFrom, [[maybe_unused]] ILxUnknownID itemTo) override
#define LXxO_SceneItemListener_LinkRemAfter LXxD_SceneItemListener_LinkRemAfter
#define LXxC_SceneItemListener_LinkRemAfter(c) void c::sil_LinkRemAfter([[maybe_unused]] const char *graph, [[maybe_unused]] ILxUnknownID itemFrom, [[maybe_unused]] ILxUnknownID itemTo)
#define LXxD_SceneItemListener_LinkSet void sil_LinkSet([[maybe_unused]] const char *graph, [[maybe_unused]] ILxUnknownID itemFrom, [[maybe_unused]] ILxUnknownID itemTo) override
#define LXxO_SceneItemListener_LinkSet LXxD_SceneItemListener_LinkSet
#define LXxC_SceneItemListener_LinkSet(c) void c::sil_LinkSet([[maybe_unused]] const char *graph, [[maybe_unused]] ILxUnknownID itemFrom, [[maybe_unused]] ILxUnknownID itemTo)
#define LXxD_SceneItemListener_ChanLinkAdd void sil_ChanLinkAdd([[maybe_unused]] const char *graph, [[maybe_unused]] ILxUnknownID itemFrom, [[maybe_unused]] unsigned chanFrom, [[maybe_unused]] ILxUnknownID itemTo, [[maybe_unused]] unsigned chanTo) override
#define LXxO_SceneItemListener_ChanLinkAdd LXxD_SceneItemListener_ChanLinkAdd
#define LXxC_SceneItemListener_ChanLinkAdd(c) void c::sil_ChanLinkAdd([[maybe_unused]] const char *graph, [[maybe_unused]] ILxUnknownID itemFrom, [[maybe_unused]] unsigned chanFrom, [[maybe_unused]] ILxUnknownID itemTo, [[maybe_unused]] unsigned chanTo)
#define LXxD_SceneItemListener_ChanLinkRemBefore void sil_ChanLinkRemBefore([[maybe_unused]] const char *graph, [[maybe_unused]] ILxUnknownID itemFrom, [[maybe_unused]] unsigned chanFrom, [[maybe_unused]] ILxUnknownID itemTo, [[maybe_unused]] unsigned chanTo) override
#define LXxO_SceneItemListener_ChanLinkRemBefore LXxD_SceneItemListener_ChanLinkRemBefore
#define LXxC_SceneItemListener_ChanLinkRemBefore(c) void c::sil_ChanLinkRemBefore([[maybe_unused]] const char *graph, [[maybe_unused]] ILxUnknownID itemFrom, [[maybe_unused]] unsigned chanFrom, [[maybe_unused]] ILxUnknownID itemTo, [[maybe_unused]] unsigned chanTo)
#define LXxD_SceneItemListener_ChanLinkRemAfter void sil_ChanLinkRemAfter([[maybe_unused]] const char *graph, [[maybe_unused]] ILxUnknownID itemFrom, [[maybe_unused]] unsigned chanFrom, [[maybe_unused]] ILxUnknownID itemTo, [[maybe_unused]] unsigned chanTo) override
#define LXxO_SceneItemListener_ChanLinkRemAfter LXxD_SceneItemListener_ChanLinkRemAfter
#define LXxC_SceneItemListener_ChanLinkRemAfter(c) void c::sil_ChanLinkRemAfter([[maybe_unused]] const char *graph, [[maybe_unused]] ILxUnknownID itemFrom, [[maybe_unused]] unsigned chanFrom, [[maybe_unused]] ILxUnknownID itemTo, [[maybe_unused]] unsigned chanTo)
#define LXxD_SceneItemListener_ChanLinkSet void sil_ChanLinkSet([[maybe_unused]] const char *graph, [[maybe_unused]] ILxUnknownID itemFrom, [[maybe_unused]] unsigned chanFrom, [[maybe_unused]] ILxUnknownID itemTo, [[maybe_unused]] unsigned chanTo) override
#define LXxO_SceneItemListener_ChanLinkSet LXxD_SceneItemListener_ChanLinkSet
#define LXxC_SceneItemListener_ChanLinkSet(c) void c::sil_ChanLinkSet([[maybe_unused]] const char *graph, [[maybe_unused]] ILxUnknownID itemFrom, [[maybe_unused]] unsigned chanFrom, [[maybe_unused]] ILxUnknownID itemTo, [[maybe_unused]] unsigned chanTo)
#define LXxD_SceneItemListener_ItemTag void sil_ItemTag([[maybe_unused]] ILxUnknownID item) override
#define LXxO_SceneItemListener_ItemTag LXxD_SceneItemListener_ItemTag
#define LXxC_SceneItemListener_ItemTag(c) void c::sil_ItemTag([[maybe_unused]] ILxUnknownID item)
#define LXxD_SceneItemListener_ItemRemoveChannel void sil_ItemRemoveChannel([[maybe_unused]] ILxUnknownID item) override
#define LXxO_SceneItemListener_ItemRemoveChannel LXxD_SceneItemListener_ItemRemoveChannel
#define LXxC_SceneItemListener_ItemRemoveChannel(c) void c::sil_ItemRemoveChannel([[maybe_unused]] ILxUnknownID item)
#define LXxD_SceneItemListener_ItemChannelName void sil_ItemChannelName([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned int index) override
#define LXxO_SceneItemListener_ItemChannelName LXxD_SceneItemListener_ItemChannelName
#define LXxC_SceneItemListener_ItemChannelName(c) void c::sil_ItemChannelName([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned int index)
#define LXxD_SceneItemListener_ItemChannelDefault void sil_ItemChannelDefault([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned int index) override
#define LXxO_SceneItemListener_ItemChannelDefault LXxD_SceneItemListener_ItemChannelDefault
#define LXxC_SceneItemListener_ItemChannelDefault(c) void c::sil_ItemChannelDefault([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned int index)
#define LXxD_SceneItemListener_ItemChannelMinMax void sil_ItemChannelMinMax([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned int index) override
#define LXxO_SceneItemListener_ItemChannelMinMax LXxD_SceneItemListener_ItemChannelMinMax
#define LXxC_SceneItemListener_ItemChannelMinMax(c) void c::sil_ItemChannelMinMax([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned int index)
#define LXxD_SceneItemListener_ItemChannelType void sil_ItemChannelType([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned int index) override
#define LXxO_SceneItemListener_ItemChannelType LXxD_SceneItemListener_ItemChannelType
#define LXxC_SceneItemListener_ItemChannelType(c) void c::sil_ItemChannelType([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned int index)

template <class T>
class CLxIfc_SceneItemListener: public CLxInterface
{
public:
    CLxIfc_SceneItemListener()
    {
        vt.SceneCreate = SceneCreate;
        vt.SceneDestroy = SceneDestroy;
        vt.SceneFilename = SceneFilename;
        vt.SceneClear = SceneClear;
        vt.ItemPreChange = ItemPreChange;
        vt.ItemPostDelete = ItemPostDelete;
        vt.ItemAdd = ItemAdd;
        vt.ItemRemove = ItemRemove;
        vt.ItemParent = ItemParent;
        vt.ItemChild = ItemChild;
        vt.ItemAddChannel = ItemAddChannel;
        vt.ItemLocal = ItemLocal;
        vt.ItemName = ItemName;
        vt.ItemSource = ItemSource;
        vt.ItemPackage = ItemPackage;
        vt.ChannelValue = ChannelValue;
        vt.LinkAdd = LinkAdd;
        vt.LinkRemBefore = LinkRemBefore;
        vt.LinkRemAfter = LinkRemAfter;
        vt.LinkSet = LinkSet;
        vt.ChanLinkAdd = ChanLinkAdd;
        vt.ChanLinkRemBefore = ChanLinkRemBefore;
        vt.ChanLinkRemAfter = ChanLinkRemAfter;
        vt.ChanLinkSet = ChanLinkSet;
        vt.ItemTag = ItemTag;
        vt.ItemRemoveChannel = ItemRemoveChannel;
        vt.ItemChannelName = ItemChannelName;
        vt.ItemChannelDefault = ItemChannelDefault;
        vt.ItemChannelMinMax = ItemChannelMinMax;
        vt.ItemChannelType = ItemChannelType;
        vTable = &vt.iunk;
        iid = &lx::guid_SceneItemListener;
    }

    static auto SceneCreate(LXtObjectID wcom,LXtObjectID scene) -> void
    {
        LXCWxINST (CLxImpl_SceneItemListener, loc);
        loc->sil_SceneCreate((ILxUnknownID) scene);
    }

    static auto SceneDestroy(LXtObjectID wcom,LXtObjectID scene) -> void
    {
        LXCWxINST (CLxImpl_SceneItemListener, loc);
        loc->sil_SceneDestroy((ILxUnknownID) scene);
    }

    static auto SceneFilename(LXtObjectID wcom,LXtObjectID scene,const char *filename) -> void
    {
        LXCWxINST (CLxImpl_SceneItemListener, loc);
        loc->sil_SceneFilename((ILxUnknownID) scene, filename);
    }

    static auto SceneClear(LXtObjectID wcom,LXtObjectID scene) -> void
    {
        LXCWxINST (CLxImpl_SceneItemListener, loc);
        loc->sil_SceneClear((ILxUnknownID) scene);
    }

    static auto ItemPreChange(LXtObjectID wcom,LXtObjectID scene) -> void
    {
        LXCWxINST (CLxImpl_SceneItemListener, loc);
        loc->sil_ItemPreChange((ILxUnknownID) scene);
    }

    static auto ItemPostDelete(LXtObjectID wcom,LXtObjectID scene) -> void
    {
        LXCWxINST (CLxImpl_SceneItemListener, loc);
        loc->sil_ItemPostDelete((ILxUnknownID) scene);
    }

    static auto ItemAdd(LXtObjectID wcom,LXtObjectID item) -> void
    {
        LXCWxINST (CLxImpl_SceneItemListener, loc);
        loc->sil_ItemAdd((ILxUnknownID) item);
    }

    static auto ItemRemove(LXtObjectID wcom,LXtObjectID item) -> void
    {
        LXCWxINST (CLxImpl_SceneItemListener, loc);
        loc->sil_ItemRemove((ILxUnknownID) item);
    }

    static auto ItemParent(LXtObjectID wcom,LXtObjectID item) -> void
    {
        LXCWxINST (CLxImpl_SceneItemListener, loc);
        loc->sil_ItemParent((ILxUnknownID) item);
    }

    static auto ItemChild(LXtObjectID wcom,LXtObjectID item) -> void
    {
        LXCWxINST (CLxImpl_SceneItemListener, loc);
        loc->sil_ItemChild((ILxUnknownID) item);
    }

    static auto ItemAddChannel(LXtObjectID wcom,LXtObjectID item) -> void
    {
        LXCWxINST (CLxImpl_SceneItemListener, loc);
        loc->sil_ItemAddChannel((ILxUnknownID) item);
    }

    static auto ItemLocal(LXtObjectID wcom,LXtObjectID item) -> void
    {
        LXCWxINST (CLxImpl_SceneItemListener, loc);
        loc->sil_ItemLocal((ILxUnknownID) item);
    }

    static auto ItemName(LXtObjectID wcom,LXtObjectID item) -> void
    {
        LXCWxINST (CLxImpl_SceneItemListener, loc);
        loc->sil_ItemName((ILxUnknownID) item);
    }

    static auto ItemSource(LXtObjectID wcom,LXtObjectID item) -> void
    {
        LXCWxINST (CLxImpl_SceneItemListener, loc);
        loc->sil_ItemSource((ILxUnknownID) item);
    }

    static auto ItemPackage(LXtObjectID wcom,LXtObjectID item) -> void
    {
        LXCWxINST (CLxImpl_SceneItemListener, loc);
        loc->sil_ItemPackage((ILxUnknownID) item);
    }

    static auto ChannelValue(LXtObjectID wcom,const char *action,LXtObjectID item,unsigned index) -> void
    {
        LXCWxINST (CLxImpl_SceneItemListener, loc);
        loc->sil_ChannelValue( action,(ILxUnknownID) item, index);
    }

    static auto LinkAdd(LXtObjectID wcom,const char *graph,LXtObjectID itemFrom,LXtObjectID itemTo) -> void
    {
        LXCWxINST (CLxImpl_SceneItemListener, loc);
        loc->sil_LinkAdd( graph,(ILxUnknownID) itemFrom,(ILxUnknownID) itemTo);
    }

    static auto LinkRemBefore(LXtObjectID wcom,const char *graph,LXtObjectID itemFrom,LXtObjectID itemTo) -> void
    {
        LXCWxINST (CLxImpl_SceneItemListener, loc);
        loc->sil_LinkRemBefore( graph,(ILxUnknownID) itemFrom,(ILxUnknownID) itemTo);
    }

    static auto LinkRemAfter(LXtObjectID wcom,const char *graph,LXtObjectID itemFrom,LXtObjectID itemTo) -> void
    {
        LXCWxINST (CLxImpl_SceneItemListener, loc);
        loc->sil_LinkRemAfter( graph,(ILxUnknownID) itemFrom,(ILxUnknownID) itemTo);
    }

    static auto LinkSet(LXtObjectID wcom,const char *graph,LXtObjectID itemFrom,LXtObjectID itemTo) -> void
    {
        LXCWxINST (CLxImpl_SceneItemListener, loc);
        loc->sil_LinkSet( graph,(ILxUnknownID) itemFrom,(ILxUnknownID) itemTo);
    }

    static auto ChanLinkAdd(LXtObjectID wcom,const char *graph,LXtObjectID itemFrom,unsigned chanFrom,LXtObjectID itemTo,unsigned chanTo) -> void
    {
        LXCWxINST (CLxImpl_SceneItemListener, loc);
        loc->sil_ChanLinkAdd( graph,(ILxUnknownID) itemFrom, chanFrom,(ILxUnknownID) itemTo, chanTo);
    }

    static auto ChanLinkRemBefore(LXtObjectID wcom,const char *graph,LXtObjectID itemFrom,unsigned chanFrom,LXtObjectID itemTo,unsigned chanTo) -> void
    {
        LXCWxINST (CLxImpl_SceneItemListener, loc);
        loc->sil_ChanLinkRemBefore( graph,(ILxUnknownID) itemFrom, chanFrom,(ILxUnknownID) itemTo, chanTo);
    }

    static auto ChanLinkRemAfter(LXtObjectID wcom,const char *graph,LXtObjectID itemFrom,unsigned chanFrom,LXtObjectID itemTo,unsigned chanTo) -> void
    {
        LXCWxINST (CLxImpl_SceneItemListener, loc);
        loc->sil_ChanLinkRemAfter( graph,(ILxUnknownID) itemFrom, chanFrom,(ILxUnknownID) itemTo, chanTo);
    }

    static auto ChanLinkSet(LXtObjectID wcom,const char *graph,LXtObjectID itemFrom,unsigned chanFrom,LXtObjectID itemTo,unsigned chanTo) -> void
    {
        LXCWxINST (CLxImpl_SceneItemListener, loc);
        loc->sil_ChanLinkSet( graph,(ILxUnknownID) itemFrom, chanFrom,(ILxUnknownID) itemTo, chanTo);
    }

    static auto ItemTag(LXtObjectID wcom,LXtObjectID item) -> void
    {
        LXCWxINST (CLxImpl_SceneItemListener, loc);
        loc->sil_ItemTag((ILxUnknownID) item);
    }

    static auto ItemRemoveChannel(LXtObjectID wcom,LXtObjectID item) -> void
    {
        LXCWxINST (CLxImpl_SceneItemListener, loc);
        loc->sil_ItemRemoveChannel((ILxUnknownID) item);
    }

    static auto ItemChannelName(LXtObjectID wcom,LXtObjectID item,unsigned int index) -> void
    {
        LXCWxINST (CLxImpl_SceneItemListener, loc);
        loc->sil_ItemChannelName((ILxUnknownID) item, index);
    }

    static auto ItemChannelDefault(LXtObjectID wcom,LXtObjectID item,unsigned int index) -> void
    {
        LXCWxINST (CLxImpl_SceneItemListener, loc);
        loc->sil_ItemChannelDefault((ILxUnknownID) item, index);
    }

    static auto ItemChannelMinMax(LXtObjectID wcom,LXtObjectID item,unsigned int index) -> void
    {
        LXCWxINST (CLxImpl_SceneItemListener, loc);
        loc->sil_ItemChannelMinMax((ILxUnknownID) item, index);
    }

    static auto ItemChannelType(LXtObjectID wcom,LXtObjectID item,unsigned int index) -> void
    {
        LXCWxINST (CLxImpl_SceneItemListener, loc);
        loc->sil_ItemChannelType((ILxUnknownID) item, index);
    }

private:
    ILxSceneItemListener vt;
};

class CLxLoc_SceneItemListener : public CLxLocalize<ILxSceneItemListenerID>
{
public:
    CLxLoc_SceneItemListener()
    {
        _init();
    }

    CLxLoc_SceneItemListener(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_SceneItemListener(CLxLoc_SceneItemListener const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_SceneItemListener;
    }

    auto SceneCreate(ILxUnknownID scene) -> void
    {
        m_loc[0]->SceneCreate(m_loc,(ILxUnknownID) scene);
    }

    auto SceneDestroy(ILxUnknownID scene) -> void
    {
        m_loc[0]->SceneDestroy(m_loc,(ILxUnknownID) scene);
    }

    auto SceneFilename(ILxUnknownID scene, const char *filename) -> void
    {
        m_loc[0]->SceneFilename(m_loc,(ILxUnknownID) scene, filename);
    }

    auto SceneClear(ILxUnknownID scene) -> void
    {
        m_loc[0]->SceneClear(m_loc,(ILxUnknownID) scene);
    }

    auto ItemPreChange(ILxUnknownID scene) -> void
    {
        m_loc[0]->ItemPreChange(m_loc,(ILxUnknownID) scene);
    }

    auto ItemPostDelete(ILxUnknownID scene) -> void
    {
        m_loc[0]->ItemPostDelete(m_loc,(ILxUnknownID) scene);
    }

    auto ItemAdd(ILxUnknownID item) -> void
    {
        m_loc[0]->ItemAdd(m_loc,(ILxUnknownID) item);
    }

    auto ItemRemove(ILxUnknownID item) -> void
    {
        m_loc[0]->ItemRemove(m_loc,(ILxUnknownID) item);
    }

    auto ItemParent(ILxUnknownID item) -> void
    {
        m_loc[0]->ItemParent(m_loc,(ILxUnknownID) item);
    }

    auto ItemChild(ILxUnknownID item) -> void
    {
        m_loc[0]->ItemChild(m_loc,(ILxUnknownID) item);
    }

    auto ItemAddChannel(ILxUnknownID item) -> void
    {
        m_loc[0]->ItemAddChannel(m_loc,(ILxUnknownID) item);
    }

    auto ItemLocal(ILxUnknownID item) -> void
    {
        m_loc[0]->ItemLocal(m_loc,(ILxUnknownID) item);
    }

    auto ItemName(ILxUnknownID item) -> void
    {
        m_loc[0]->ItemName(m_loc,(ILxUnknownID) item);
    }

    auto ItemSource(ILxUnknownID item) -> void
    {
        m_loc[0]->ItemSource(m_loc,(ILxUnknownID) item);
    }

    auto ItemPackage(ILxUnknownID item) -> void
    {
        m_loc[0]->ItemPackage(m_loc,(ILxUnknownID) item);
    }

    auto ChannelValue(const char *action, ILxUnknownID item, unsigned index) -> void
    {
        m_loc[0]->ChannelValue(m_loc, action,(ILxUnknownID) item, index);
    }

    auto LinkAdd(const char *graph, ILxUnknownID itemFrom, ILxUnknownID itemTo) -> void
    {
        m_loc[0]->LinkAdd(m_loc, graph,(ILxUnknownID) itemFrom,(ILxUnknownID) itemTo);
    }

    auto LinkRemBefore(const char *graph, ILxUnknownID itemFrom, ILxUnknownID itemTo) -> void
    {
        m_loc[0]->LinkRemBefore(m_loc, graph,(ILxUnknownID) itemFrom,(ILxUnknownID) itemTo);
    }

    auto LinkRemAfter(const char *graph, ILxUnknownID itemFrom, ILxUnknownID itemTo) -> void
    {
        m_loc[0]->LinkRemAfter(m_loc, graph,(ILxUnknownID) itemFrom,(ILxUnknownID) itemTo);
    }

    auto LinkSet(const char *graph, ILxUnknownID itemFrom, ILxUnknownID itemTo) -> void
    {
        m_loc[0]->LinkSet(m_loc, graph,(ILxUnknownID) itemFrom,(ILxUnknownID) itemTo);
    }

    auto ChanLinkAdd(const char *graph, ILxUnknownID itemFrom, unsigned chanFrom, ILxUnknownID itemTo, unsigned chanTo) -> void
    {
        m_loc[0]->ChanLinkAdd(m_loc, graph,(ILxUnknownID) itemFrom, chanFrom,(ILxUnknownID) itemTo, chanTo);
    }

    auto ChanLinkRemBefore(const char *graph, ILxUnknownID itemFrom, unsigned chanFrom, ILxUnknownID itemTo, unsigned chanTo) -> void
    {
        m_loc[0]->ChanLinkRemBefore(m_loc, graph,(ILxUnknownID) itemFrom, chanFrom,(ILxUnknownID) itemTo, chanTo);
    }

    auto ChanLinkRemAfter(const char *graph, ILxUnknownID itemFrom, unsigned chanFrom, ILxUnknownID itemTo, unsigned chanTo) -> void
    {
        m_loc[0]->ChanLinkRemAfter(m_loc, graph,(ILxUnknownID) itemFrom, chanFrom,(ILxUnknownID) itemTo, chanTo);
    }

    auto ChanLinkSet(const char *graph, ILxUnknownID itemFrom, unsigned chanFrom, ILxUnknownID itemTo, unsigned chanTo) -> void
    {
        m_loc[0]->ChanLinkSet(m_loc, graph,(ILxUnknownID) itemFrom, chanFrom,(ILxUnknownID) itemTo, chanTo);
    }

    auto ItemTag(ILxUnknownID item) -> void
    {
        m_loc[0]->ItemTag(m_loc,(ILxUnknownID) item);
    }

    auto ItemRemoveChannel(ILxUnknownID item) -> void
    {
        m_loc[0]->ItemRemoveChannel(m_loc,(ILxUnknownID) item);
    }

    auto ItemChannelName(ILxUnknownID item, unsigned int index) -> void
    {
        m_loc[0]->ItemChannelName(m_loc,(ILxUnknownID) item, index);
    }

    auto ItemChannelDefault(ILxUnknownID item, unsigned int index) -> void
    {
        m_loc[0]->ItemChannelDefault(m_loc,(ILxUnknownID) item, index);
    }

    auto ItemChannelMinMax(ILxUnknownID item, unsigned int index) -> void
    {
        m_loc[0]->ItemChannelMinMax(m_loc,(ILxUnknownID) item, index);
    }

    auto ItemChannelType(ILxUnknownID item, unsigned int index) -> void
    {
        m_loc[0]->ItemChannelType(m_loc,(ILxUnknownID) item, index);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_SceneLoaderTarget : public CLxLocalize<ILxSceneLoaderTargetID>
{
public:
    CLxLoc_SceneLoaderTarget()
    {
        _init();
    }

    CLxLoc_SceneLoaderTarget(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_SceneLoaderTarget(CLxLoc_SceneLoaderTarget const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_SceneLoaderTarget;
    }

    auto SetRootType(const char *typeName) -> LxResult
    {
        return m_loc[0]->SetRootType(m_loc, typeName);
    }

    auto SetFlags(unsigned flags) -> LxResult
    {
        return m_loc[0]->SetFlags(m_loc, flags);
    }

    auto ClearFlags(unsigned flags) -> LxResult
    {
        return m_loc[0]->ClearFlags(m_loc, flags);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};


class CLxImpl_Package
{
public:
    virtual ~CLxImpl_Package() = default;

    virtual auto pkg_SetupChannels([[maybe_unused]] ILxUnknownID addChan) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto pkg_Attach([[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto pkg_TestInterface([[maybe_unused]] const LXtGUID *guid) -> LxResult
    {
        return LXe_FALSE;
    }

    virtual auto pkg_PostLoad([[maybe_unused]] ILxUnknownID scene) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto pkg_CollectItems([[maybe_unused]] ILxUnknownID collection, [[maybe_unused]] unsigned mode) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_Package_SetupChannels LxResult pkg_SetupChannels([[maybe_unused]] ILxUnknownID addChan) override
#define LXxO_Package_SetupChannels LXxD_Package_SetupChannels
#define LXxC_Package_SetupChannels(c) LxResult c::pkg_SetupChannels([[maybe_unused]] ILxUnknownID addChan)
#define LXxD_Package_Attach LxResult pkg_Attach([[maybe_unused]] void **ppvObj) override
#define LXxO_Package_Attach LXxD_Package_Attach
#define LXxC_Package_Attach(c) LxResult c::pkg_Attach([[maybe_unused]] void **ppvObj)
#define LXxD_Package_TestInterface LxResult pkg_TestInterface([[maybe_unused]] const LXtGUID *guid) override
#define LXxO_Package_TestInterface LXxD_Package_TestInterface
#define LXxC_Package_TestInterface(c) LxResult c::pkg_TestInterface([[maybe_unused]] const LXtGUID *guid)
#define LXxD_Package_PostLoad LxResult pkg_PostLoad([[maybe_unused]] ILxUnknownID scene) override
#define LXxO_Package_PostLoad LXxD_Package_PostLoad
#define LXxC_Package_PostLoad(c) LxResult c::pkg_PostLoad([[maybe_unused]] ILxUnknownID scene)
#define LXxD_Package_CollectItems LxResult pkg_CollectItems([[maybe_unused]] ILxUnknownID collection, [[maybe_unused]] unsigned mode) override
#define LXxO_Package_CollectItems LXxD_Package_CollectItems
#define LXxC_Package_CollectItems(c) LxResult c::pkg_CollectItems([[maybe_unused]] ILxUnknownID collection, [[maybe_unused]] unsigned mode)

template <class T>
class CLxIfc_Package: public CLxInterface
{
public:
    CLxIfc_Package()
    {
        vt.SetupChannels = SetupChannels;
        vt.Attach = Attach;
        vt.TestInterface = TestInterface;
        vt.PostLoad = PostLoad;
        vt.CollectItems = CollectItems;
        vTable = &vt.iunk;
        iid = &lx::guid_Package;
    }

    static auto SetupChannels(LXtObjectID wcom,LXtObjectID addChan) -> LxResult
    {
        LXCWxINST (CLxImpl_Package, loc);
        try
        {
           return loc->pkg_SetupChannels((ILxUnknownID) addChan);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Attach(LXtObjectID wcom,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_Package, loc);
        try
        {
           return loc->pkg_Attach( ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto TestInterface(LXtObjectID wcom,const LXtGUID *guid) -> LxResult
    {
        LXCWxINST (CLxImpl_Package, loc);
        try
        {
           return loc->pkg_TestInterface( guid);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto PostLoad(LXtObjectID wcom,LXtObjectID scene) -> LxResult
    {
        LXCWxINST (CLxImpl_Package, loc);
        try
        {
           return loc->pkg_PostLoad((ILxUnknownID) scene);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto CollectItems(LXtObjectID wcom,LXtObjectID collection,unsigned mode) -> LxResult
    {
        LXCWxINST (CLxImpl_Package, loc);
        try
        {
           return loc->pkg_CollectItems((ILxUnknownID) collection, mode);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxPackage vt;
};

class CLxLoc_Package : public CLxLocalize<ILxPackageID>
{
public:
    CLxLoc_Package()
    {
        _init();
    }

    CLxLoc_Package(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_Package(CLxLoc_Package const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_Package;
    }

    auto SetupChannels(ILxUnknownID addChan) -> LxResult
    {
        return m_loc[0]->SetupChannels(m_loc,(ILxUnknownID) addChan);
    }

    auto Attach(void **ppvObj) -> LxResult
    {
        return m_loc[0]->Attach(m_loc, ppvObj);
    }

    auto Attach(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Attach(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto TestInterface(const LXtGUID *guid) -> LxResult
    {
        return m_loc[0]->TestInterface(m_loc, guid);
    }

    auto PostLoad(ILxUnknownID scene) -> LxResult
    {
        return m_loc[0]->PostLoad(m_loc,(ILxUnknownID) scene);
    }

    auto CollectItems(ILxUnknownID collection, unsigned mode) -> LxResult
    {
        return m_loc[0]->CollectItems(m_loc,(ILxUnknownID) collection, mode);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_AddChannel : public CLxLocalize<ILxAddChannelID>
{
public:
    CLxLoc_AddChannel()
    {
        _init();
    }

    CLxLoc_AddChannel(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_AddChannel(CLxLoc_AddChannel const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_AddChannel;
    }

    auto NewChannel(const char *name, const char *type) -> LxResult
    {
        return m_loc[0]->NewChannel(m_loc, name, type);
    }

    auto SetGradient(const char *inType) -> LxResult
    {
        return m_loc[0]->SetGradient(m_loc, inType);
    }

    auto SetStorage(const char *stType) -> LxResult
    {
        return m_loc[0]->SetStorage(m_loc, stType);
    }

    auto SetVector(const char *vecType) -> LxResult
    {
        return m_loc[0]->SetVector(m_loc, vecType);
    }

    auto SetDefault(double defFlt, int defInt) -> LxResult
    {
        return m_loc[0]->SetDefault(m_loc, defFlt, defInt);
    }

    auto SetDefaultVec(const double *defVec) -> LxResult
    {
        return m_loc[0]->SetDefaultVec(m_loc, defVec);
    }

    auto SetHint(const LXtTextValueHint *hint) -> LxResult
    {
        return m_loc[0]->SetHint(m_loc, hint);
    }

    auto SetUserHint(const LXtTextValueHint *hint) -> LxResult
    {
        return m_loc[0]->SetUserHint(m_loc, hint);
    }

    auto SetDefaultObj(void **ppvObj) -> LxResult
    {
        return m_loc[0]->SetDefaultObj(m_loc, ppvObj);
    }

    auto SetDefaultObj(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->SetDefaultObj(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto SetInternal(void) -> void
    {
        m_loc[0]->SetInternal(m_loc);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_AddChannel1 : public CLxLocalize<ILxAddChannel1ID>
{
public:
    CLxLoc_AddChannel1()
    {
        _init();
    }

    CLxLoc_AddChannel1(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_AddChannel1(CLxLoc_AddChannel1 const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_AddChannel1;
    }

    auto NewChannel(const char *name, const char *type) -> LxResult
    {
        return m_loc[0]->NewChannel(m_loc, name, type);
    }

    auto SetGradient(const char *inType) -> LxResult
    {
        return m_loc[0]->SetGradient(m_loc, inType);
    }

    auto SetStorage(const char *stType) -> LxResult
    {
        return m_loc[0]->SetStorage(m_loc, stType);
    }

    auto SetVector(const char *vecType) -> LxResult
    {
        return m_loc[0]->SetVector(m_loc, vecType);
    }

    auto SetDefault(double defFlt, int defInt) -> LxResult
    {
        return m_loc[0]->SetDefault(m_loc, defFlt, defInt);
    }

    auto SetDefaultVec(const double *defVec) -> LxResult
    {
        return m_loc[0]->SetDefaultVec(m_loc, defVec);
    }

    auto SetHint(const LXtTextValueHint *hint) -> LxResult
    {
        return m_loc[0]->SetHint(m_loc, hint);
    }

    auto SetDefaultObj(void **ppvObj) -> LxResult
    {
        return m_loc[0]->SetDefaultObj(m_loc, ppvObj);
    }

    auto SetDefaultObj(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->SetDefaultObj(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto SetInternal(void) -> void
    {
        m_loc[0]->SetInternal(m_loc);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_ItemCollection : public CLxLocalize<ILxItemCollectionID>
{
public:
    CLxLoc_ItemCollection()
    {
        _init();
    }

    CLxLoc_ItemCollection(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_ItemCollection(CLxLoc_ItemCollection const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_ItemCollection;
    }

    auto Test(ILxUnknownID item) -> LxResult
    {
        return m_loc[0]->Test(m_loc,(ILxUnknownID) item);
    }

    auto Count(int type, unsigned *count) -> LxResult
    {
        return m_loc[0]->Count(m_loc, type, count);
    }

    auto ByIndex(int type, unsigned index, void **ppvObj) -> LxResult
    {
        return m_loc[0]->ByIndex(m_loc, type, index, ppvObj);
    }

    auto ByIndex(int type, unsigned index, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->ByIndex(m_loc, type, index, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Add(ILxUnknownID item) -> LxResult
    {
        return m_loc[0]->Add(m_loc,(ILxUnknownID) item);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_PackageInstance
{
public:
    virtual ~CLxImpl_PackageInstance() = default;

    virtual auto pins_Initialize([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] ILxUnknownID super) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual void pins_Cleanup([[maybe_unused]] void)
    {
    }

    virtual auto pins_SynthName([[maybe_unused]] char *buf, [[maybe_unused]] unsigned len) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto pins_DupType([[maybe_unused]] void) -> unsigned
    {
        return 0;
    }

    virtual auto pins_TestParent([[maybe_unused]] ILxUnknownID item) -> LxResult
    {
        return LXe_TRUE;
    }

    virtual auto pins_Newborn([[maybe_unused]] ILxUnknownID original, [[maybe_unused]] unsigned flags) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto pins_Loading([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto pins_AfterLoad([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual void pins_Doomed([[maybe_unused]] void)
    {
    }

    virtual auto pins_Add([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto pins_Remove([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_PackageInstance_Initialize LxResult pins_Initialize([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] ILxUnknownID super) override
#define LXxO_PackageInstance_Initialize LXxD_PackageInstance_Initialize
#define LXxC_PackageInstance_Initialize(c) LxResult c::pins_Initialize([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] ILxUnknownID super)
#define LXxD_PackageInstance_Cleanup void pins_Cleanup() override
#define LXxO_PackageInstance_Cleanup LXxD_PackageInstance_Cleanup
#define LXxC_PackageInstance_Cleanup(c) void c::pins_Cleanup()
#define LXxD_PackageInstance_SynthName LxResult pins_SynthName([[maybe_unused]] char *buf, [[maybe_unused]] unsigned len) override
#define LXxO_PackageInstance_SynthName LXxD_PackageInstance_SynthName
#define LXxC_PackageInstance_SynthName(c) LxResult c::pins_SynthName([[maybe_unused]] char *buf, [[maybe_unused]] unsigned len)
#define LXxD_PackageInstance_DupType unsigned pins_DupType() override
#define LXxO_PackageInstance_DupType LXxD_PackageInstance_DupType
#define LXxC_PackageInstance_DupType(c) unsigned c::pins_DupType()
#define LXxD_PackageInstance_TestParent LxResult pins_TestParent([[maybe_unused]] ILxUnknownID item) override
#define LXxO_PackageInstance_TestParent LXxD_PackageInstance_TestParent
#define LXxC_PackageInstance_TestParent(c) LxResult c::pins_TestParent([[maybe_unused]] ILxUnknownID item)
#define LXxD_PackageInstance_Newborn LxResult pins_Newborn([[maybe_unused]] ILxUnknownID original, [[maybe_unused]] unsigned flags) override
#define LXxO_PackageInstance_Newborn LXxD_PackageInstance_Newborn
#define LXxC_PackageInstance_Newborn(c) LxResult c::pins_Newborn([[maybe_unused]] ILxUnknownID original, [[maybe_unused]] unsigned flags)
#define LXxD_PackageInstance_Loading LxResult pins_Loading() override
#define LXxO_PackageInstance_Loading LXxD_PackageInstance_Loading
#define LXxC_PackageInstance_Loading(c) LxResult c::pins_Loading()
#define LXxD_PackageInstance_AfterLoad LxResult pins_AfterLoad() override
#define LXxO_PackageInstance_AfterLoad LXxD_PackageInstance_AfterLoad
#define LXxC_PackageInstance_AfterLoad(c) LxResult c::pins_AfterLoad()
#define LXxD_PackageInstance_Doomed void pins_Doomed() override
#define LXxO_PackageInstance_Doomed LXxD_PackageInstance_Doomed
#define LXxC_PackageInstance_Doomed(c) void c::pins_Doomed()
#define LXxD_PackageInstance_Add LxResult pins_Add() override
#define LXxO_PackageInstance_Add LXxD_PackageInstance_Add
#define LXxC_PackageInstance_Add(c) LxResult c::pins_Add()
#define LXxD_PackageInstance_Remove LxResult pins_Remove() override
#define LXxO_PackageInstance_Remove LXxD_PackageInstance_Remove
#define LXxC_PackageInstance_Remove(c) LxResult c::pins_Remove()

template <class T>
class CLxIfc_PackageInstance: public CLxInterface
{
public:
    CLxIfc_PackageInstance()
    {
        vt.Initialize = Initialize;
        vt.Cleanup = Cleanup;
        vt.SynthName = SynthName;
        vt.DupType = DupType;
        vt.TestParent = TestParent;
        vt.Newborn = Newborn;
        vt.Loading = Loading;
        vt.AfterLoad = AfterLoad;
        vt.Doomed = Doomed;
        vt.Add = Add;
        vt.Remove = Remove;
        vTable = &vt.iunk;
        iid = &lx::guid_PackageInstance;
    }

    static auto Initialize(LXtObjectID wcom,LXtObjectID item,LXtObjectID super) -> LxResult
    {
        LXCWxINST (CLxImpl_PackageInstance, loc);
        try
        {
           return loc->pins_Initialize((ILxUnknownID) item,(ILxUnknownID) super);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Cleanup(LXtObjectID wcom) -> void
    {
        LXCWxINST (CLxImpl_PackageInstance, loc);
        loc->pins_Cleanup();
    }

    static auto SynthName(LXtObjectID wcom,char *buf,unsigned len) -> LxResult
    {
        LXCWxINST (CLxImpl_PackageInstance, loc);
        try
        {
           return loc->pins_SynthName( buf, len);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto DupType(LXtObjectID wcom) -> unsigned
    {
        LXCWxINST (CLxImpl_PackageInstance, loc);
        return loc->pins_DupType();
    }

    static auto TestParent(LXtObjectID wcom,LXtObjectID item) -> LxResult
    {
        LXCWxINST (CLxImpl_PackageInstance, loc);
        try
        {
           return loc->pins_TestParent((ILxUnknownID) item);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Newborn(LXtObjectID wcom,LXtObjectID original,unsigned flags) -> LxResult
    {
        LXCWxINST (CLxImpl_PackageInstance, loc);
        try
        {
           return loc->pins_Newborn((ILxUnknownID) original, flags);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Loading(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_PackageInstance, loc);
        try
        {
           return loc->pins_Loading();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto AfterLoad(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_PackageInstance, loc);
        try
        {
           return loc->pins_AfterLoad();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Doomed(LXtObjectID wcom) -> void
    {
        LXCWxINST (CLxImpl_PackageInstance, loc);
        loc->pins_Doomed();
    }

    static auto Add(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_PackageInstance, loc);
        try
        {
           return loc->pins_Add();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Remove(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_PackageInstance, loc);
        try
        {
           return loc->pins_Remove();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxPackageInstance vt;
};

class CLxLoc_PackageInstance : public CLxLocalize<ILxPackageInstanceID>
{
public:
    CLxLoc_PackageInstance()
    {
        _init();
    }

    CLxLoc_PackageInstance(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_PackageInstance(CLxLoc_PackageInstance const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_PackageInstance;
    }

    auto Initialize(ILxUnknownID item, ILxUnknownID super) -> LxResult
    {
        return m_loc[0]->Initialize(m_loc,(ILxUnknownID) item,(ILxUnknownID) super);
    }

    auto Cleanup(void) -> void
    {
        m_loc[0]->Cleanup(m_loc);
    }

    auto SynthName(char *buf, unsigned len) -> LxResult
    {
        return m_loc[0]->SynthName(m_loc, buf, len);
    }

    auto SynthName(std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->SynthName(m_loc, buf, len);
        LXWx_SBUF2
    }

    auto DupType(void) -> unsigned
    {
        return m_loc[0]->DupType(m_loc);
    }

    auto TestParent(ILxUnknownID item) -> LxResult
    {
        return m_loc[0]->TestParent(m_loc,(ILxUnknownID) item);
    }

    auto Newborn(ILxUnknownID original, unsigned flags) -> LxResult
    {
        return m_loc[0]->Newborn(m_loc,(ILxUnknownID) original, flags);
    }

    auto Loading(void) -> LxResult
    {
        return m_loc[0]->Loading(m_loc);
    }

    auto AfterLoad(void) -> LxResult
    {
        return m_loc[0]->AfterLoad(m_loc);
    }

    auto Doomed(void) -> void
    {
        m_loc[0]->Doomed(m_loc);
    }

    auto Add(void) -> LxResult
    {
        return m_loc[0]->Add(m_loc);
    }

    auto Remove(void) -> LxResult
    {
        return m_loc[0]->Remove(m_loc);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_AssemblyAlias
{
public:
    virtual ~CLxImpl_AssemblyAlias() = default;

    virtual auto alias_Test([[maybe_unused]] ILxUnknownID assembly, [[maybe_unused]] ILxUnknownID other) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto alias_Configure([[maybe_unused]] ILxUnknownID assembly, [[maybe_unused]] ILxUnknownID other, [[maybe_unused]] ILxUnknownID alias, [[maybe_unused]] const unsigned int change) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto alias_SuperType([[maybe_unused]] LXtItemType *type) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto alias_Flags([[maybe_unused]] unsigned int *flags) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_AssemblyAlias_Test LxResult alias_Test([[maybe_unused]] ILxUnknownID assembly, [[maybe_unused]] ILxUnknownID other) override
#define LXxO_AssemblyAlias_Test LXxD_AssemblyAlias_Test
#define LXxC_AssemblyAlias_Test(c) LxResult c::alias_Test([[maybe_unused]] ILxUnknownID assembly, [[maybe_unused]] ILxUnknownID other)
#define LXxD_AssemblyAlias_Configure LxResult alias_Configure([[maybe_unused]] ILxUnknownID assembly, [[maybe_unused]] ILxUnknownID other, [[maybe_unused]] ILxUnknownID alias, [[maybe_unused]] const unsigned int change) override
#define LXxO_AssemblyAlias_Configure LXxD_AssemblyAlias_Configure
#define LXxC_AssemblyAlias_Configure(c) LxResult c::alias_Configure([[maybe_unused]] ILxUnknownID assembly, [[maybe_unused]] ILxUnknownID other, [[maybe_unused]] ILxUnknownID alias, [[maybe_unused]] const unsigned int change)
#define LXxD_AssemblyAlias_SuperType LxResult alias_SuperType([[maybe_unused]] LXtItemType *type) override
#define LXxO_AssemblyAlias_SuperType LXxD_AssemblyAlias_SuperType
#define LXxC_AssemblyAlias_SuperType(c) LxResult c::alias_SuperType([[maybe_unused]] LXtItemType *type)
#define LXxD_AssemblyAlias_Flags LxResult alias_Flags([[maybe_unused]] unsigned int *flags) override
#define LXxO_AssemblyAlias_Flags LXxD_AssemblyAlias_Flags
#define LXxC_AssemblyAlias_Flags(c) LxResult c::alias_Flags([[maybe_unused]] unsigned int *flags)

template <class T>
class CLxIfc_AssemblyAlias: public CLxInterface
{
public:
    CLxIfc_AssemblyAlias()
    {
        vt.Test = Test;
        vt.Configure = Configure;
        vt.SuperType = SuperType;
        vt.Flags = Flags;
        vTable = &vt.iunk;
        iid = &lx::guid_AssemblyAlias;
    }

    static auto Test(LXtObjectID wcom,LXtObjectID assembly,LXtObjectID other) -> LxResult
    {
        LXCWxINST (CLxImpl_AssemblyAlias, loc);
        try
        {
           return loc->alias_Test((ILxUnknownID) assembly,(ILxUnknownID) other);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Configure(LXtObjectID wcom,LXtObjectID assembly,LXtObjectID other,LXtObjectID alias,const unsigned int change) -> LxResult
    {
        LXCWxINST (CLxImpl_AssemblyAlias, loc);
        try
        {
           return loc->alias_Configure((ILxUnknownID) assembly,(ILxUnknownID) other,(ILxUnknownID) alias, change);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SuperType(LXtObjectID wcom,LXtItemType *type) -> LxResult
    {
        LXCWxINST (CLxImpl_AssemblyAlias, loc);
        try
        {
           return loc->alias_SuperType( type);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Flags(LXtObjectID wcom,unsigned int *flags) -> LxResult
    {
        LXCWxINST (CLxImpl_AssemblyAlias, loc);
        try
        {
           return loc->alias_Flags( flags);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxAssemblyAlias vt;
};




