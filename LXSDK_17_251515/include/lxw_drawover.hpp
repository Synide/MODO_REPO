//
// C++ wrapper for lxsdk/lxdrawover.h.
//
//	Copyright 2024.
//
//
#pragma once

#include <lxdrawover.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx
{
    static LXtGUID const guid_DrawingOverride = {0x52429702, {0x1D97, 0x4B00}, {0x81, 0x54, 0x65, 0x10, 0xD3, 0x4E, 0xE8, 0xCA}};
} // namespace lx

class CLxImpl_DrawingOverride
{
public:
    virtual ~CLxImpl_DrawingOverride() = default;

    virtual int drov_Flags(void) = 0;

    virtual auto drov_AffectedItems([[maybe_unused]] ILxUnknownID scene, [[maybe_unused]] ILxUnknownID collection) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto drov_SetItem([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned *styles) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto drov_GetColor([[maybe_unused]] unsigned style, [[maybe_unused]] LXtVector4 rgba) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto drov_InitContext([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual void drov_CleanupContext([[maybe_unused]] void)
    {
    }

    virtual auto drov_DrawVisitor([[maybe_unused]] ILxUnknownID scene, [[maybe_unused]] ILxUnknownID view, [[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_DrawingOverride_Flags int drov_Flags() override
#define LXxO_DrawingOverride_Flags LXxD_DrawingOverride_Flags
#define LXxC_DrawingOverride_Flags(c) int c::drov_Flags()
#define LXxD_DrawingOverride_AffectedItems LxResult drov_AffectedItems([[maybe_unused]] ILxUnknownID scene, [[maybe_unused]] ILxUnknownID collection) override
#define LXxO_DrawingOverride_AffectedItems LXxD_DrawingOverride_AffectedItems
#define LXxC_DrawingOverride_AffectedItems(c) LxResult c::drov_AffectedItems([[maybe_unused]] ILxUnknownID scene, [[maybe_unused]] ILxUnknownID collection)
#define LXxD_DrawingOverride_SetItem LxResult drov_SetItem([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned *styles) override
#define LXxO_DrawingOverride_SetItem LXxD_DrawingOverride_SetItem
#define LXxC_DrawingOverride_SetItem(c) LxResult c::drov_SetItem([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned *styles)
#define LXxD_DrawingOverride_GetColor LxResult drov_GetColor([[maybe_unused]] unsigned style, [[maybe_unused]] LXtVector4 rgba) override
#define LXxO_DrawingOverride_GetColor LXxD_DrawingOverride_GetColor
#define LXxC_DrawingOverride_GetColor(c) LxResult c::drov_GetColor([[maybe_unused]] unsigned style, [[maybe_unused]] LXtVector4 rgba)
#define LXxD_DrawingOverride_InitContext LxResult drov_InitContext() override
#define LXxO_DrawingOverride_InitContext LXxD_DrawingOverride_InitContext
#define LXxC_DrawingOverride_InitContext(c) LxResult c::drov_InitContext()
#define LXxD_DrawingOverride_CleanupContext void drov_CleanupContext() override
#define LXxO_DrawingOverride_CleanupContext LXxD_DrawingOverride_CleanupContext
#define LXxC_DrawingOverride_CleanupContext(c) void c::drov_CleanupContext()
#define LXxD_DrawingOverride_DrawVisitor LxResult drov_DrawVisitor([[maybe_unused]] ILxUnknownID scene, [[maybe_unused]] ILxUnknownID view, [[maybe_unused]] void **ppvObj) override
#define LXxO_DrawingOverride_DrawVisitor LXxD_DrawingOverride_DrawVisitor
#define LXxC_DrawingOverride_DrawVisitor(c) LxResult c::drov_DrawVisitor([[maybe_unused]] ILxUnknownID scene, [[maybe_unused]] ILxUnknownID view, [[maybe_unused]] void **ppvObj)

template <class T>
class CLxIfc_DrawingOverride: public CLxInterface
{
public:
    CLxIfc_DrawingOverride()
    {
        vt.Flags = Flags;
        vt.AffectedItems = AffectedItems;
        vt.SetItem = SetItem;
        vt.GetColor = GetColor;
        vt.InitContext = InitContext;
        vt.CleanupContext = CleanupContext;
        vt.DrawVisitor = DrawVisitor;
        vTable = &vt.iunk;
        iid = &lx::guid_DrawingOverride;
    }

    static auto Flags(LXtObjectID wcom) -> int
    {
        LXCWxINST (CLxImpl_DrawingOverride, loc);
        return loc->drov_Flags();
    }

    static auto AffectedItems(LXtObjectID wcom,LXtObjectID scene,LXtObjectID collection) -> LxResult
    {
        LXCWxINST (CLxImpl_DrawingOverride, loc);
        try
        {
           return loc->drov_AffectedItems((ILxUnknownID) scene,(ILxUnknownID) collection);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SetItem(LXtObjectID wcom,LXtObjectID item,unsigned *styles) -> LxResult
    {
        LXCWxINST (CLxImpl_DrawingOverride, loc);
        try
        {
           return loc->drov_SetItem((ILxUnknownID) item, styles);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto GetColor(LXtObjectID wcom,unsigned style,LXtVector4 rgba) -> LxResult
    {
        LXCWxINST (CLxImpl_DrawingOverride, loc);
        try
        {
           return loc->drov_GetColor( style, rgba);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto InitContext(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_DrawingOverride, loc);
        try
        {
           return loc->drov_InitContext();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto CleanupContext(LXtObjectID wcom) -> void
    {
        LXCWxINST (CLxImpl_DrawingOverride, loc);
        loc->drov_CleanupContext();
    }

    static auto DrawVisitor(LXtObjectID wcom,LXtObjectID scene,LXtObjectID view,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_DrawingOverride, loc);
        try
        {
           return loc->drov_DrawVisitor((ILxUnknownID) scene,(ILxUnknownID) view, ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxDrawingOverride vt;
};

class CLxLoc_DrawingOverride : public CLxLocalize<ILxDrawingOverrideID>
{
public:
    CLxLoc_DrawingOverride()
    {
        _init();
    }

    CLxLoc_DrawingOverride(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_DrawingOverride(CLxLoc_DrawingOverride const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_DrawingOverride;
    }

    auto Flags(void) -> int
    {
        return m_loc[0]->Flags(m_loc);
    }

    auto AffectedItems(ILxUnknownID scene, ILxUnknownID collection) -> LxResult
    {
        return m_loc[0]->AffectedItems(m_loc,(ILxUnknownID) scene,(ILxUnknownID) collection);
    }

    auto SetItem(ILxUnknownID item, unsigned *styles) -> LxResult
    {
        return m_loc[0]->SetItem(m_loc,(ILxUnknownID) item, styles);
    }

    auto GetColor(unsigned style, LXtVector4 rgba) -> LxResult
    {
        return m_loc[0]->GetColor(m_loc, style, rgba);
    }

    auto InitContext(void) -> LxResult
    {
        return m_loc[0]->InitContext(m_loc);
    }

    auto CleanupContext(void) -> void
    {
        m_loc[0]->CleanupContext(m_loc);
    }

    auto DrawVisitor(ILxUnknownID scene, ILxUnknownID view, void **ppvObj) -> LxResult
    {
        return m_loc[0]->DrawVisitor(m_loc,(ILxUnknownID) scene,(ILxUnknownID) view, ppvObj);
    }

    auto DrawVisitor(ILxUnknownID scene, ILxUnknownID view, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->DrawVisitor(m_loc,(ILxUnknownID) scene,(ILxUnknownID) view, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
