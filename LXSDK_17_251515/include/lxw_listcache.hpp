//
// C++ wrapper for lxsdk/lxlistcache.h.
//
//	Copyright 2024.
//
//
#pragma once

#include <lxlistcache.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx
{
    static LXtGUID const guid_ItemListType = {0x14EC78B2, {0x8DAB, 0x4E8B}, {0x8D, 0x38, 0x14, 0x20, 0x92, 0x95, 0x0A, 0xE8}};
} // namespace lx

class CLxImpl_ItemListType
{
public:
    virtual ~CLxImpl_ItemListType() = default;

    virtual auto ilt_SetArgument([[maybe_unused]] const char *arg) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto ilt_SetRootItem([[maybe_unused]] ILxUnknownID item) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto ilt_GenerateList([[maybe_unused]] ILxUnknownID scene, [[maybe_unused]] ILxUnknownID collection) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_ItemListType_SetArgument LxResult ilt_SetArgument([[maybe_unused]] const char *arg) override
#define LXxO_ItemListType_SetArgument LXxD_ItemListType_SetArgument
#define LXxC_ItemListType_SetArgument(c) LxResult c::ilt_SetArgument([[maybe_unused]] const char *arg)
#define LXxD_ItemListType_SetRootItem LxResult ilt_SetRootItem([[maybe_unused]] ILxUnknownID item) override
#define LXxO_ItemListType_SetRootItem LXxD_ItemListType_SetRootItem
#define LXxC_ItemListType_SetRootItem(c) LxResult c::ilt_SetRootItem([[maybe_unused]] ILxUnknownID item)
#define LXxD_ItemListType_GenerateList LxResult ilt_GenerateList([[maybe_unused]] ILxUnknownID scene, [[maybe_unused]] ILxUnknownID collection) override
#define LXxO_ItemListType_GenerateList LXxD_ItemListType_GenerateList
#define LXxC_ItemListType_GenerateList(c) LxResult c::ilt_GenerateList([[maybe_unused]] ILxUnknownID scene, [[maybe_unused]] ILxUnknownID collection)

template <class T>
class CLxIfc_ItemListType: public CLxInterface
{
public:
    CLxIfc_ItemListType()
    {
        vt.SetArgument = SetArgument;
        vt.SetRootItem = SetRootItem;
        vt.GenerateList = GenerateList;
        vTable = &vt.iunk;
        iid = &lx::guid_ItemListType;
    }

    static auto SetArgument(LXtObjectID wcom,const char *arg) -> LxResult
    {
        LXCWxINST (CLxImpl_ItemListType, loc);
        try
        {
           return loc->ilt_SetArgument( arg);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SetRootItem(LXtObjectID wcom,LXtObjectID item) -> LxResult
    {
        LXCWxINST (CLxImpl_ItemListType, loc);
        try
        {
           return loc->ilt_SetRootItem((ILxUnknownID) item);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto GenerateList(LXtObjectID wcom,LXtObjectID scene,LXtObjectID collection) -> LxResult
    {
        LXCWxINST (CLxImpl_ItemListType, loc);
        try
        {
           return loc->ilt_GenerateList((ILxUnknownID) scene,(ILxUnknownID) collection);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxItemListType vt;
};

class CLxLoc_ItemListType : public CLxLocalize<ILxItemListTypeID>
{
public:
    CLxLoc_ItemListType()
    {
        _init();
    }

    CLxLoc_ItemListType(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_ItemListType(CLxLoc_ItemListType const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_ItemListType;
    }

    auto SetArgument(const char *arg) -> LxResult
    {
        return m_loc[0]->SetArgument(m_loc, arg);
    }

    auto SetRootItem(ILxUnknownID item) -> LxResult
    {
        return m_loc[0]->SetRootItem(m_loc,(ILxUnknownID) item);
    }

    auto GenerateList(ILxUnknownID scene, ILxUnknownID collection) -> LxResult
    {
        return m_loc[0]->GenerateList(m_loc,(ILxUnknownID) scene,(ILxUnknownID) collection);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
