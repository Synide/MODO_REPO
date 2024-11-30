//
// C++ wrapper for lxsdk/lxtree.h.
//
//	Copyright 2024.
//
//
#pragma once

#include <lxtree.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx
{
    static LXtGUID const guid_Tree = {0xE61F3BA6, {0xB9E8, 0x41B8}, {0x8A, 0x61, 0x3F, 0x78, 0xCB, 0xC7, 0x9E, 0x98}};
    static LXtGUID const guid_TreeListener = {0x200fe1a6, {0xc764, 0x42f7}, {0x91, 0x7f, 0x04, 0x4a, 0x0f, 0x58, 0xe0, 0x07}};
    static LXtGUID const guid_TreeListener1 = {0xEB38EE07, {0x0E35, 0x455F}, {0xA5, 0x70, 0xF4, 0xAF, 0x31, 0x34, 0x94, 0xFD}};
} // namespace lx

class CLxImpl_Tree
{
public:
    virtual ~CLxImpl_Tree() = default;

    virtual auto tree_Spawn([[maybe_unused]] unsigned mode, [[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto tree_ToParent([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto tree_ToChild([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto tree_ToRoot([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto tree_IsRoot([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto tree_ChildIsLeaf([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto tree_Count([[maybe_unused]] unsigned *count) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto tree_Current([[maybe_unused]] unsigned *index) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto tree_SetCurrent([[maybe_unused]] unsigned index) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto tree_ItemState([[maybe_unused]] const char *guid, [[maybe_unused]] int *state) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto tree_SetItemState([[maybe_unused]] const char *guid, [[maybe_unused]] int state) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_Tree_Spawn LxResult tree_Spawn([[maybe_unused]] unsigned mode, [[maybe_unused]] void **ppvObj) override
#define LXxO_Tree_Spawn LXxD_Tree_Spawn
#define LXxC_Tree_Spawn(c) LxResult c::tree_Spawn([[maybe_unused]] unsigned mode, [[maybe_unused]] void **ppvObj)
#define LXxD_Tree_ToParent LxResult tree_ToParent() override
#define LXxO_Tree_ToParent LXxD_Tree_ToParent
#define LXxC_Tree_ToParent(c) LxResult c::tree_ToParent()
#define LXxD_Tree_ToChild LxResult tree_ToChild() override
#define LXxO_Tree_ToChild LXxD_Tree_ToChild
#define LXxC_Tree_ToChild(c) LxResult c::tree_ToChild()
#define LXxD_Tree_ToRoot LxResult tree_ToRoot() override
#define LXxO_Tree_ToRoot LXxD_Tree_ToRoot
#define LXxC_Tree_ToRoot(c) LxResult c::tree_ToRoot()
#define LXxD_Tree_IsRoot LxResult tree_IsRoot() override
#define LXxO_Tree_IsRoot LXxD_Tree_IsRoot
#define LXxC_Tree_IsRoot(c) LxResult c::tree_IsRoot()
#define LXxD_Tree_ChildIsLeaf LxResult tree_ChildIsLeaf() override
#define LXxO_Tree_ChildIsLeaf LXxD_Tree_ChildIsLeaf
#define LXxC_Tree_ChildIsLeaf(c) LxResult c::tree_ChildIsLeaf()
#define LXxD_Tree_Count LxResult tree_Count([[maybe_unused]] unsigned *count) override
#define LXxO_Tree_Count LXxD_Tree_Count
#define LXxC_Tree_Count(c) LxResult c::tree_Count([[maybe_unused]] unsigned *count)
#define LXxD_Tree_Current LxResult tree_Current([[maybe_unused]] unsigned *index) override
#define LXxO_Tree_Current LXxD_Tree_Current
#define LXxC_Tree_Current(c) LxResult c::tree_Current([[maybe_unused]] unsigned *index)
#define LXxD_Tree_SetCurrent LxResult tree_SetCurrent([[maybe_unused]] unsigned index) override
#define LXxO_Tree_SetCurrent LXxD_Tree_SetCurrent
#define LXxC_Tree_SetCurrent(c) LxResult c::tree_SetCurrent([[maybe_unused]] unsigned index)
#define LXxD_Tree_ItemState LxResult tree_ItemState([[maybe_unused]] const char *guid, [[maybe_unused]] int *state) override
#define LXxO_Tree_ItemState LXxD_Tree_ItemState
#define LXxC_Tree_ItemState(c) LxResult c::tree_ItemState([[maybe_unused]] const char *guid, [[maybe_unused]] int *state)
#define LXxD_Tree_SetItemState LxResult tree_SetItemState([[maybe_unused]] const char *guid, [[maybe_unused]] int state) override
#define LXxO_Tree_SetItemState LXxD_Tree_SetItemState
#define LXxC_Tree_SetItemState(c) LxResult c::tree_SetItemState([[maybe_unused]] const char *guid, [[maybe_unused]] int state)

template <class T>
class CLxIfc_Tree: public CLxInterface
{
public:
    CLxIfc_Tree()
    {
        vt.Spawn = Spawn;
        vt.ToParent = ToParent;
        vt.ToChild = ToChild;
        vt.ToRoot = ToRoot;
        vt.IsRoot = IsRoot;
        vt.ChildIsLeaf = ChildIsLeaf;
        vt.Count = Count;
        vt.Current = Current;
        vt.SetCurrent = SetCurrent;
        vt.ItemState = ItemState;
        vt.SetItemState = SetItemState;
        vTable = &vt.iunk;
        iid = &lx::guid_Tree;
    }

    static auto Spawn(LXtObjectID wcom,unsigned mode,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_Tree, loc);
        try
        {
           return loc->tree_Spawn( mode, ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ToParent(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_Tree, loc);
        try
        {
           return loc->tree_ToParent();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ToChild(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_Tree, loc);
        try
        {
           return loc->tree_ToChild();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ToRoot(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_Tree, loc);
        try
        {
           return loc->tree_ToRoot();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto IsRoot(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_Tree, loc);
        try
        {
           return loc->tree_IsRoot();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ChildIsLeaf(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_Tree, loc);
        try
        {
           return loc->tree_ChildIsLeaf();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Count(LXtObjectID wcom,unsigned *count) -> LxResult
    {
        LXCWxINST (CLxImpl_Tree, loc);
        try
        {
           return loc->tree_Count( count);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Current(LXtObjectID wcom,unsigned *index) -> LxResult
    {
        LXCWxINST (CLxImpl_Tree, loc);
        try
        {
           return loc->tree_Current( index);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SetCurrent(LXtObjectID wcom,unsigned index) -> LxResult
    {
        LXCWxINST (CLxImpl_Tree, loc);
        try
        {
           return loc->tree_SetCurrent( index);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ItemState(LXtObjectID wcom,const char *guid,int *state) -> LxResult
    {
        LXCWxINST (CLxImpl_Tree, loc);
        try
        {
           return loc->tree_ItemState( guid, state);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SetItemState(LXtObjectID wcom,const char *guid,int state) -> LxResult
    {
        LXCWxINST (CLxImpl_Tree, loc);
        try
        {
           return loc->tree_SetItemState( guid, state);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxTree vt;
};

class CLxLoc_Tree : public CLxLocalize<ILxTreeID>
{
public:
    CLxLoc_Tree()
    {
        _init();
    }

    CLxLoc_Tree(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_Tree(CLxLoc_Tree const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_Tree;
    }

    auto Spawn(unsigned mode, void **ppvObj) -> LxResult
    {
        return m_loc[0]->Spawn(m_loc, mode, ppvObj);
    }

    auto Spawn(unsigned mode, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Spawn(m_loc, mode, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto ToParent(void) -> LxResult
    {
        return m_loc[0]->ToParent(m_loc);
    }

    auto ToChild(void) -> LxResult
    {
        return m_loc[0]->ToChild(m_loc);
    }

    auto ToRoot(void) -> LxResult
    {
        return m_loc[0]->ToRoot(m_loc);
    }

    auto IsRoot(void) -> LxResult
    {
        return m_loc[0]->IsRoot(m_loc);
    }

    auto ChildIsLeaf(void) -> LxResult
    {
        return m_loc[0]->ChildIsLeaf(m_loc);
    }

    auto Count(unsigned *count) -> LxResult
    {
        return m_loc[0]->Count(m_loc, count);
    }

    auto Current(unsigned *index) -> LxResult
    {
        return m_loc[0]->Current(m_loc, index);
    }

    auto SetCurrent(unsigned index) -> LxResult
    {
        return m_loc[0]->SetCurrent(m_loc, index);
    }

    auto ItemState(const char *guid, int *state) -> LxResult
    {
        return m_loc[0]->ItemState(m_loc, guid, state);
    }

    auto SetItemState(const char *guid, int state) -> LxResult
    {
        return m_loc[0]->SetItemState(m_loc, guid, state);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_TreeListener
{
public:
    virtual ~CLxImpl_TreeListener() = default;

    virtual auto tlis_NewAttributes([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto tlis_NewShape([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto tlis_NewSpaceForThumbnails([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto tlis_ClearCachedThumbnail([[maybe_unused]] const char *ident) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto tlis_ClearAllCachedThumbnails([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto tlis_NewShowDescriptionText([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_TreeListener_NewAttributes LxResult tlis_NewAttributes() override
#define LXxO_TreeListener_NewAttributes LXxD_TreeListener_NewAttributes
#define LXxC_TreeListener_NewAttributes(c) LxResult c::tlis_NewAttributes()
#define LXxD_TreeListener_NewShape LxResult tlis_NewShape() override
#define LXxO_TreeListener_NewShape LXxD_TreeListener_NewShape
#define LXxC_TreeListener_NewShape(c) LxResult c::tlis_NewShape()
#define LXxD_TreeListener_NewSpaceForThumbnails LxResult tlis_NewSpaceForThumbnails() override
#define LXxO_TreeListener_NewSpaceForThumbnails LXxD_TreeListener_NewSpaceForThumbnails
#define LXxC_TreeListener_NewSpaceForThumbnails(c) LxResult c::tlis_NewSpaceForThumbnails()
#define LXxD_TreeListener_ClearCachedThumbnail LxResult tlis_ClearCachedThumbnail([[maybe_unused]] const char *ident) override
#define LXxO_TreeListener_ClearCachedThumbnail LXxD_TreeListener_ClearCachedThumbnail
#define LXxC_TreeListener_ClearCachedThumbnail(c) LxResult c::tlis_ClearCachedThumbnail([[maybe_unused]] const char *ident)
#define LXxD_TreeListener_ClearAllCachedThumbnails LxResult tlis_ClearAllCachedThumbnails() override
#define LXxO_TreeListener_ClearAllCachedThumbnails LXxD_TreeListener_ClearAllCachedThumbnails
#define LXxC_TreeListener_ClearAllCachedThumbnails(c) LxResult c::tlis_ClearAllCachedThumbnails()
#define LXxD_TreeListener_NewShowDescriptionText LxResult tlis_NewShowDescriptionText() override
#define LXxO_TreeListener_NewShowDescriptionText LXxD_TreeListener_NewShowDescriptionText
#define LXxC_TreeListener_NewShowDescriptionText(c) LxResult c::tlis_NewShowDescriptionText()

template <class T>
class CLxIfc_TreeListener: public CLxInterface
{
public:
    CLxIfc_TreeListener()
    {
        vt.NewAttributes = NewAttributes;
        vt.NewShape = NewShape;
        vt.NewSpaceForThumbnails = NewSpaceForThumbnails;
        vt.ClearCachedThumbnail = ClearCachedThumbnail;
        vt.ClearAllCachedThumbnails = ClearAllCachedThumbnails;
        vt.NewShowDescriptionText = NewShowDescriptionText;
        vTable = &vt.iunk;
        iid = &lx::guid_TreeListener;
    }

    static auto NewAttributes(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_TreeListener, loc);
        try
        {
           return loc->tlis_NewAttributes();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto NewShape(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_TreeListener, loc);
        try
        {
           return loc->tlis_NewShape();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto NewSpaceForThumbnails(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_TreeListener, loc);
        try
        {
           return loc->tlis_NewSpaceForThumbnails();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ClearCachedThumbnail(LXtObjectID wcom,const char *ident) -> LxResult
    {
        LXCWxINST (CLxImpl_TreeListener, loc);
        try
        {
           return loc->tlis_ClearCachedThumbnail( ident);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ClearAllCachedThumbnails(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_TreeListener, loc);
        try
        {
           return loc->tlis_ClearAllCachedThumbnails();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto NewShowDescriptionText(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_TreeListener, loc);
        try
        {
           return loc->tlis_NewShowDescriptionText();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxTreeListener vt;
};

class CLxLoc_TreeListener : public CLxLocalize<ILxTreeListenerID>
{
public:
    CLxLoc_TreeListener()
    {
        _init();
    }

    CLxLoc_TreeListener(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_TreeListener(CLxLoc_TreeListener const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_TreeListener;
    }

    auto NewAttributes(void) -> LxResult
    {
        return m_loc[0]->NewAttributes(m_loc);
    }

    auto NewShape(void) -> LxResult
    {
        return m_loc[0]->NewShape(m_loc);
    }

    auto NewSpaceForThumbnails(void) -> LxResult
    {
        return m_loc[0]->NewSpaceForThumbnails(m_loc);
    }

    auto ClearCachedThumbnail(const char *ident) -> LxResult
    {
        return m_loc[0]->ClearCachedThumbnail(m_loc, ident);
    }

    auto ClearAllCachedThumbnails(void) -> LxResult
    {
        return m_loc[0]->ClearAllCachedThumbnails(m_loc);
    }

    auto NewShowDescriptionText(void) -> LxResult
    {
        return m_loc[0]->NewShowDescriptionText(m_loc);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_TreeListener1
{
public:
    virtual ~CLxImpl_TreeListener1() = default;

    virtual auto tlis_NewAttributes([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto tlis_NewShape([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_TreeListener1_NewAttributes LxResult tlis_NewAttributes() override
#define LXxO_TreeListener1_NewAttributes LXxD_TreeListener1_NewAttributes
#define LXxC_TreeListener1_NewAttributes(c) LxResult c::tlis_NewAttributes()
#define LXxD_TreeListener1_NewShape LxResult tlis_NewShape() override
#define LXxO_TreeListener1_NewShape LXxD_TreeListener1_NewShape
#define LXxC_TreeListener1_NewShape(c) LxResult c::tlis_NewShape()

template <class T>
class CLxIfc_TreeListener1: public CLxInterface
{
public:
    CLxIfc_TreeListener1()
    {
        vt.NewAttributes = NewAttributes;
        vt.NewShape = NewShape;
        vTable = &vt.iunk;
        iid = &lx::guid_TreeListener1;
    }

    static auto NewAttributes(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_TreeListener1, loc);
        try
        {
           return loc->tlis_NewAttributes();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto NewShape(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_TreeListener1, loc);
        try
        {
           return loc->tlis_NewShape();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxTreeListener1 vt;
};

class CLxLoc_TreeListener1 : public CLxLocalize<ILxTreeListener1ID>
{
public:
    CLxLoc_TreeListener1()
    {
        _init();
    }

    CLxLoc_TreeListener1(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_TreeListener1(CLxLoc_TreeListener1 const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_TreeListener1;
    }

    auto NewAttributes(void) -> LxResult
    {
        return m_loc[0]->NewAttributes(m_loc);
    }

    auto NewShape(void) -> LxResult
    {
        return m_loc[0]->NewShape(m_loc);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
