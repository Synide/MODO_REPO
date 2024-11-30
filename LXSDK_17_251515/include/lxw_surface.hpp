//
// C++ wrapper for lxsdk/lxsurface.h.
//
//	Copyright 2024.
//
//
#pragma once

#include <lxsurface.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx
{
    static LXtGUID const guid_GLShadingListener = {0x893C9E49, {0xCBFE, 0x496D}, {0xBE, 0x18, 0xDD, 0x45, 0xBB, 0xE4, 0xE6, 0x7D}};
    static LXtGUID const guid_SurfaceItem = {0x65EC0E0E, {0xFFD7, 0x48a3}, {0x9E, 0x20, 0x62, 0xEA, 0x82, 0xEF, 0x47, 0x28}};
    static LXtGUID const guid_Surface = {0x75006BDB, {0x93F7, 0x4a41}, {0x8B, 0x8C, 0xE7, 0x10, 0xD8, 0x0D, 0x3F, 0x1A}};
    static LXtGUID const guid_SurfaceBin = {0x48B534C1, {0x7B7C, 0x4147}, {0xAD, 0xBC, 0x15, 0x48, 0x50, 0x89, 0x8E, 0x7F}};
    static LXtGUID const guid_CurveGroup = {0x20F1B298, {0x84E2, 0x4DA2}, {0xBA, 0x66, 0x88, 0x83, 0xB4, 0xB0, 0xD7, 0xFF}};
    static LXtGUID const guid_Curve = {0x2FE806FE, {0x0E47, 0x41B4}, {0x9F, 0x2A, 0xC0, 0xBB, 0x2C, 0xAF, 0x36, 0x4F}};
    static LXtGUID const guid_Curve1 = {0x9DDF4A43, {0x691F, 0x4F30}, {0x89, 0x86, 0xB5, 0x2F, 0xD1, 0xD9, 0x6E, 0x34}};
    static LXtGUID const guid_Curve2 = {0xE3EF1C95, {0xF295, 0x4FAD}, {0x9D, 0xF8, 0x9E, 0x82, 0x2E, 0xF3, 0x20, 0x2F}};
    static LXtGUID const guid_Curve3 = {0x1A832950, {0xB71E, 0x4BCB}, {0x8D, 0x56, 0x46, 0xEC, 0xE4, 0xF5, 0xBC, 0x3F}};
} // namespace lx

class CLxImpl_GLShadingListener
{
public:
    virtual ~CLxImpl_GLShadingListener() = default;

    virtual void gls_ShadingUpdate([[maybe_unused]] ILxUnknownID item)
    {
    }

    virtual void gls_DisplacementUpdate([[maybe_unused]] ILxUnknownID item)
    {
    }

    virtual void gls_FurUpdate([[maybe_unused]] ILxUnknownID item)
    {
    }
};

#define LXxD_GLShadingListener_ShadingUpdate void gls_ShadingUpdate([[maybe_unused]] ILxUnknownID item) override
#define LXxO_GLShadingListener_ShadingUpdate LXxD_GLShadingListener_ShadingUpdate
#define LXxC_GLShadingListener_ShadingUpdate(c) void c::gls_ShadingUpdate([[maybe_unused]] ILxUnknownID item)
#define LXxD_GLShadingListener_DisplacementUpdate void gls_DisplacementUpdate([[maybe_unused]] ILxUnknownID item) override
#define LXxO_GLShadingListener_DisplacementUpdate LXxD_GLShadingListener_DisplacementUpdate
#define LXxC_GLShadingListener_DisplacementUpdate(c) void c::gls_DisplacementUpdate([[maybe_unused]] ILxUnknownID item)
#define LXxD_GLShadingListener_FurUpdate void gls_FurUpdate([[maybe_unused]] ILxUnknownID item) override
#define LXxO_GLShadingListener_FurUpdate LXxD_GLShadingListener_FurUpdate
#define LXxC_GLShadingListener_FurUpdate(c) void c::gls_FurUpdate([[maybe_unused]] ILxUnknownID item)

template <class T>
class CLxIfc_GLShadingListener: public CLxInterface
{
public:
    CLxIfc_GLShadingListener()
    {
        vt.ShadingUpdate = ShadingUpdate;
        vt.DisplacementUpdate = DisplacementUpdate;
        vt.FurUpdate = FurUpdate;
        vTable = &vt.iunk;
        iid = &lx::guid_GLShadingListener;
    }

    static auto ShadingUpdate(LXtObjectID wcom,LXtObjectID item) -> void
    {
        LXCWxINST (CLxImpl_GLShadingListener, loc);
        loc->gls_ShadingUpdate((ILxUnknownID) item);
    }

    static auto DisplacementUpdate(LXtObjectID wcom,LXtObjectID item) -> void
    {
        LXCWxINST (CLxImpl_GLShadingListener, loc);
        loc->gls_DisplacementUpdate((ILxUnknownID) item);
    }

    static auto FurUpdate(LXtObjectID wcom,LXtObjectID item) -> void
    {
        LXCWxINST (CLxImpl_GLShadingListener, loc);
        loc->gls_FurUpdate((ILxUnknownID) item);
    }

private:
    ILxGLShadingListener vt;
};

class CLxLoc_GLShadingListener : public CLxLocalize<ILxGLShadingListenerID>
{
public:
    CLxLoc_GLShadingListener()
    {
        _init();
    }

    CLxLoc_GLShadingListener(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_GLShadingListener(CLxLoc_GLShadingListener const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_GLShadingListener;
    }

    auto ShadingUpdate(ILxUnknownID item) -> void
    {
        m_loc[0]->ShadingUpdate(m_loc,(ILxUnknownID) item);
    }

    auto DisplacementUpdate(ILxUnknownID item) -> void
    {
        m_loc[0]->DisplacementUpdate(m_loc,(ILxUnknownID) item);
    }

    auto FurUpdate(ILxUnknownID item) -> void
    {
        m_loc[0]->FurUpdate(m_loc,(ILxUnknownID) item);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_SurfaceItem
{
public:
    virtual ~CLxImpl_SurfaceItem() = default;

    virtual auto isurf_GetSurface([[maybe_unused]] ILxUnknownID chanRead, [[maybe_unused]] unsigned morph, [[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto isurf_Prepare([[maybe_unused]] ILxUnknownID eval, [[maybe_unused]] unsigned *index) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto isurf_Evaluate([[maybe_unused]] ILxUnknownID attr, [[maybe_unused]] unsigned index, [[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_SurfaceItem_GetSurface LxResult isurf_GetSurface([[maybe_unused]] ILxUnknownID chanRead, [[maybe_unused]] unsigned morph, [[maybe_unused]] void **ppvObj) override
#define LXxO_SurfaceItem_GetSurface LXxD_SurfaceItem_GetSurface
#define LXxC_SurfaceItem_GetSurface(c) LxResult c::isurf_GetSurface([[maybe_unused]] ILxUnknownID chanRead, [[maybe_unused]] unsigned morph, [[maybe_unused]] void **ppvObj)
#define LXxD_SurfaceItem_Prepare LxResult isurf_Prepare([[maybe_unused]] ILxUnknownID eval, [[maybe_unused]] unsigned *index) override
#define LXxO_SurfaceItem_Prepare LXxD_SurfaceItem_Prepare
#define LXxC_SurfaceItem_Prepare(c) LxResult c::isurf_Prepare([[maybe_unused]] ILxUnknownID eval, [[maybe_unused]] unsigned *index)
#define LXxD_SurfaceItem_Evaluate LxResult isurf_Evaluate([[maybe_unused]] ILxUnknownID attr, [[maybe_unused]] unsigned index, [[maybe_unused]] void **ppvObj) override
#define LXxO_SurfaceItem_Evaluate LXxD_SurfaceItem_Evaluate
#define LXxC_SurfaceItem_Evaluate(c) LxResult c::isurf_Evaluate([[maybe_unused]] ILxUnknownID attr, [[maybe_unused]] unsigned index, [[maybe_unused]] void **ppvObj)

template <class T>
class CLxIfc_SurfaceItem: public CLxInterface
{
public:
    CLxIfc_SurfaceItem()
    {
        vt.GetSurface = GetSurface;
        vt.Prepare = Prepare;
        vt.Evaluate = Evaluate;
        vTable = &vt.iunk;
        iid = &lx::guid_SurfaceItem;
    }

    static auto GetSurface(LXtObjectID wcom,LXtObjectID chanRead,unsigned morph,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_SurfaceItem, loc);
        try
        {
           return loc->isurf_GetSurface((ILxUnknownID) chanRead, morph, ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Prepare(LXtObjectID wcom,LXtObjectID eval,unsigned *index) -> LxResult
    {
        LXCWxINST (CLxImpl_SurfaceItem, loc);
        try
        {
           return loc->isurf_Prepare((ILxUnknownID) eval, index);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Evaluate(LXtObjectID wcom,LXtObjectID attr,unsigned index,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_SurfaceItem, loc);
        try
        {
           return loc->isurf_Evaluate((ILxUnknownID) attr, index, ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxSurfaceItem vt;
};

class CLxLoc_SurfaceItem : public CLxLocalize<ILxSurfaceItemID>
{
public:
    CLxLoc_SurfaceItem()
    {
        _init();
    }

    CLxLoc_SurfaceItem(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_SurfaceItem(CLxLoc_SurfaceItem const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_SurfaceItem;
    }

    auto GetSurface(ILxUnknownID chanRead, unsigned morph, void **ppvObj) -> LxResult
    {
        return m_loc[0]->GetSurface(m_loc,(ILxUnknownID) chanRead, morph, ppvObj);
    }

    auto GetSurface(ILxUnknownID chanRead, unsigned morph, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->GetSurface(m_loc,(ILxUnknownID) chanRead, morph, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Prepare(ILxUnknownID eval, unsigned *index) -> LxResult
    {
        return m_loc[0]->Prepare(m_loc,(ILxUnknownID) eval, index);
    }

    auto Evaluate(ILxUnknownID attr, unsigned index, void **ppvObj) -> LxResult
    {
        return m_loc[0]->Evaluate(m_loc,(ILxUnknownID) attr, index, ppvObj);
    }

    auto Evaluate(ILxUnknownID attr, unsigned index, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Evaluate(m_loc,(ILxUnknownID) attr, index, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_Surface
{
public:
    virtual ~CLxImpl_Surface() = default;

    virtual auto surf_GetBBox([[maybe_unused]] LXtBBox *bbox) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto surf_FrontBBox([[maybe_unused]] const LXtVector pos, [[maybe_unused]] const LXtVector dir, [[maybe_unused]] LXtBBox *bbox) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto surf_RayCast([[maybe_unused]] const LXtRayInfo *ray, [[maybe_unused]] LXtRayHit *hit) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto surf_BinCount([[maybe_unused]] unsigned int *count) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto surf_BinByIndex([[maybe_unused]] unsigned int index, [[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto surf_TagCount([[maybe_unused]] LXtID4 type, [[maybe_unused]] unsigned int *count) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto surf_TagByIndex([[maybe_unused]] LXtID4 type, [[maybe_unused]] unsigned int index, [[maybe_unused]] const char **stag) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto surf_GLCount([[maybe_unused]] unsigned int *count) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_Surface_GetBBox LxResult surf_GetBBox([[maybe_unused]] LXtBBox *bbox) override
#define LXxO_Surface_GetBBox LXxD_Surface_GetBBox
#define LXxC_Surface_GetBBox(c) LxResult c::surf_GetBBox([[maybe_unused]] LXtBBox *bbox)
#define LXxD_Surface_FrontBBox LxResult surf_FrontBBox([[maybe_unused]] const LXtVector pos, [[maybe_unused]] const LXtVector dir, [[maybe_unused]] LXtBBox *bbox) override
#define LXxO_Surface_FrontBBox LXxD_Surface_FrontBBox
#define LXxC_Surface_FrontBBox(c) LxResult c::surf_FrontBBox([[maybe_unused]] const LXtVector pos, [[maybe_unused]] const LXtVector dir, [[maybe_unused]] LXtBBox *bbox)
#define LXxD_Surface_RayCast LxResult surf_RayCast([[maybe_unused]] const LXtRayInfo *ray, [[maybe_unused]] LXtRayHit *hit) override
#define LXxO_Surface_RayCast LXxD_Surface_RayCast
#define LXxC_Surface_RayCast(c) LxResult c::surf_RayCast([[maybe_unused]] const LXtRayInfo *ray, [[maybe_unused]] LXtRayHit *hit)
#define LXxD_Surface_BinCount LxResult surf_BinCount([[maybe_unused]] unsigned int *count) override
#define LXxO_Surface_BinCount LXxD_Surface_BinCount
#define LXxC_Surface_BinCount(c) LxResult c::surf_BinCount([[maybe_unused]] unsigned int *count)
#define LXxD_Surface_BinByIndex LxResult surf_BinByIndex([[maybe_unused]] unsigned int index, [[maybe_unused]] void **ppvObj) override
#define LXxO_Surface_BinByIndex LXxD_Surface_BinByIndex
#define LXxC_Surface_BinByIndex(c) LxResult c::surf_BinByIndex([[maybe_unused]] unsigned int index, [[maybe_unused]] void **ppvObj)
#define LXxD_Surface_TagCount LxResult surf_TagCount([[maybe_unused]] LXtID4 type, [[maybe_unused]] unsigned int *count) override
#define LXxO_Surface_TagCount LXxD_Surface_TagCount
#define LXxC_Surface_TagCount(c) LxResult c::surf_TagCount([[maybe_unused]] LXtID4 type, [[maybe_unused]] unsigned int *count)
#define LXxD_Surface_TagByIndex LxResult surf_TagByIndex([[maybe_unused]] LXtID4 type, [[maybe_unused]] unsigned int index, [[maybe_unused]] const char **stag) override
#define LXxO_Surface_TagByIndex LXxD_Surface_TagByIndex
#define LXxC_Surface_TagByIndex(c) LxResult c::surf_TagByIndex([[maybe_unused]] LXtID4 type, [[maybe_unused]] unsigned int index, [[maybe_unused]] const char **stag)
#define LXxD_Surface_GLCount LxResult surf_GLCount([[maybe_unused]] unsigned int *count) override
#define LXxO_Surface_GLCount LXxD_Surface_GLCount
#define LXxC_Surface_GLCount(c) LxResult c::surf_GLCount([[maybe_unused]] unsigned int *count)

template <class T>
class CLxIfc_Surface: public CLxInterface
{
public:
    CLxIfc_Surface()
    {
        vt.GetBBox = GetBBox;
        vt.FrontBBox = FrontBBox;
        vt.RayCast = RayCast;
        vt.BinCount = BinCount;
        vt.BinByIndex = BinByIndex;
        vt.TagCount = TagCount;
        vt.TagByIndex = TagByIndex;
        vt.GLCount = GLCount;
        vTable = &vt.iunk;
        iid = &lx::guid_Surface;
    }

    static auto GetBBox(LXtObjectID wcom,LXtBBox *bbox) -> LxResult
    {
        LXCWxINST (CLxImpl_Surface, loc);
        try
        {
           return loc->surf_GetBBox( bbox);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto FrontBBox(LXtObjectID wcom,const LXtVector pos,const LXtVector dir,LXtBBox *bbox) -> LxResult
    {
        LXCWxINST (CLxImpl_Surface, loc);
        try
        {
           return loc->surf_FrontBBox( pos, dir, bbox);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto RayCast(LXtObjectID wcom,const LXtRayInfo *ray,LXtRayHit *hit) -> LxResult
    {
        LXCWxINST (CLxImpl_Surface, loc);
        try
        {
           return loc->surf_RayCast( ray, hit);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto BinCount(LXtObjectID wcom,unsigned int *count) -> LxResult
    {
        LXCWxINST (CLxImpl_Surface, loc);
        try
        {
           return loc->surf_BinCount( count);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto BinByIndex(LXtObjectID wcom,unsigned int index,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_Surface, loc);
        try
        {
           return loc->surf_BinByIndex( index, ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto TagCount(LXtObjectID wcom,LXtID4 type,unsigned int *count) -> LxResult
    {
        LXCWxINST (CLxImpl_Surface, loc);
        try
        {
           return loc->surf_TagCount( type, count);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto TagByIndex(LXtObjectID wcom,LXtID4 type,unsigned int index,const char **stag) -> LxResult
    {
        LXCWxINST (CLxImpl_Surface, loc);
        try
        {
           return loc->surf_TagByIndex( type, index, stag);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto GLCount(LXtObjectID wcom,unsigned int *count) -> LxResult
    {
        LXCWxINST (CLxImpl_Surface, loc);
        try
        {
           return loc->surf_GLCount( count);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxSurface vt;
};

class CLxLoc_Surface : public CLxLocalize<ILxSurfaceID>
{
public:
    CLxLoc_Surface()
    {
        _init();
    }

    CLxLoc_Surface(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_Surface(CLxLoc_Surface const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_Surface;
    }

    auto GetBBox(LXtBBox *bbox) -> LxResult
    {
        return m_loc[0]->GetBBox(m_loc, bbox);
    }

    auto FrontBBox(const LXtVector pos, const LXtVector dir, LXtBBox *bbox) -> LxResult
    {
        return m_loc[0]->FrontBBox(m_loc, pos, dir, bbox);
    }

    auto RayCast(const LXtRayInfo *ray, LXtRayHit *hit) -> LxResult
    {
        return m_loc[0]->RayCast(m_loc, ray, hit);
    }

    auto BinCount(unsigned int *count) -> LxResult
    {
        return m_loc[0]->BinCount(m_loc, count);
    }

    auto BinByIndex(unsigned int index, void **ppvObj) -> LxResult
    {
        return m_loc[0]->BinByIndex(m_loc, index, ppvObj);
    }

    auto BinByIndex(unsigned int index, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->BinByIndex(m_loc, index, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto TagCount(LXtID4 type, unsigned int *count) -> LxResult
    {
        return m_loc[0]->TagCount(m_loc, type, count);
    }

    auto TagByIndex(LXtID4 type, unsigned int index, const char **stag) -> LxResult
    {
        return m_loc[0]->TagByIndex(m_loc, type, index, stag);
    }

    auto GLCount(unsigned int *count) -> LxResult
    {
        return m_loc[0]->GLCount(m_loc, count);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_SurfaceBin
{
public:
    virtual ~CLxImpl_SurfaceBin() = default;

    virtual auto surfbin_GetBBox([[maybe_unused]] LXtBBox *bbox) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto surfbin_FrontBBox([[maybe_unused]] const LXtVector pos, [[maybe_unused]] const LXtVector dir, [[maybe_unused]] LXtBBox *bbox) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_SurfaceBin_GetBBox LxResult surfbin_GetBBox([[maybe_unused]] LXtBBox *bbox) override
#define LXxO_SurfaceBin_GetBBox LXxD_SurfaceBin_GetBBox
#define LXxC_SurfaceBin_GetBBox(c) LxResult c::surfbin_GetBBox([[maybe_unused]] LXtBBox *bbox)
#define LXxD_SurfaceBin_FrontBBox LxResult surfbin_FrontBBox([[maybe_unused]] const LXtVector pos, [[maybe_unused]] const LXtVector dir, [[maybe_unused]] LXtBBox *bbox) override
#define LXxO_SurfaceBin_FrontBBox LXxD_SurfaceBin_FrontBBox
#define LXxC_SurfaceBin_FrontBBox(c) LxResult c::surfbin_FrontBBox([[maybe_unused]] const LXtVector pos, [[maybe_unused]] const LXtVector dir, [[maybe_unused]] LXtBBox *bbox)

template <class T>
class CLxIfc_SurfaceBin: public CLxInterface
{
public:
    CLxIfc_SurfaceBin()
    {
        vt.GetBBox = GetBBox;
        vt.FrontBBox = FrontBBox;
        vTable = &vt.iunk;
        iid = &lx::guid_SurfaceBin;
    }

    static auto GetBBox(LXtObjectID wcom,LXtBBox *bbox) -> LxResult
    {
        LXCWxINST (CLxImpl_SurfaceBin, loc);
        try
        {
           return loc->surfbin_GetBBox( bbox);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto FrontBBox(LXtObjectID wcom,const LXtVector pos,const LXtVector dir,LXtBBox *bbox) -> LxResult
    {
        LXCWxINST (CLxImpl_SurfaceBin, loc);
        try
        {
           return loc->surfbin_FrontBBox( pos, dir, bbox);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxSurfaceBin vt;
};

class CLxLoc_SurfaceBin : public CLxLocalize<ILxSurfaceBinID>
{
public:
    CLxLoc_SurfaceBin()
    {
        _init();
    }

    CLxLoc_SurfaceBin(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_SurfaceBin(CLxLoc_SurfaceBin const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_SurfaceBin;
    }

    auto GetBBox(LXtBBox *bbox) -> LxResult
    {
        return m_loc[0]->GetBBox(m_loc, bbox);
    }

    auto FrontBBox(const LXtVector pos, const LXtVector dir, LXtBBox *bbox) -> LxResult
    {
        return m_loc[0]->FrontBBox(m_loc, pos, dir, bbox);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_CurveGroup
{
public:
    virtual ~CLxImpl_CurveGroup() = default;

    virtual auto cgrp_GetBBox([[maybe_unused]] LXtBBox *bbox) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cgrp_Count([[maybe_unused]] unsigned *count) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cgrp_ByIndex([[maybe_unused]] unsigned index, [[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_CurveGroup_GetBBox LxResult cgrp_GetBBox([[maybe_unused]] LXtBBox *bbox) override
#define LXxO_CurveGroup_GetBBox LXxD_CurveGroup_GetBBox
#define LXxC_CurveGroup_GetBBox(c) LxResult c::cgrp_GetBBox([[maybe_unused]] LXtBBox *bbox)
#define LXxD_CurveGroup_Count LxResult cgrp_Count([[maybe_unused]] unsigned *count) override
#define LXxO_CurveGroup_Count LXxD_CurveGroup_Count
#define LXxC_CurveGroup_Count(c) LxResult c::cgrp_Count([[maybe_unused]] unsigned *count)
#define LXxD_CurveGroup_ByIndex LxResult cgrp_ByIndex([[maybe_unused]] unsigned index, [[maybe_unused]] void **ppvObj) override
#define LXxO_CurveGroup_ByIndex LXxD_CurveGroup_ByIndex
#define LXxC_CurveGroup_ByIndex(c) LxResult c::cgrp_ByIndex([[maybe_unused]] unsigned index, [[maybe_unused]] void **ppvObj)

template <class T>
class CLxIfc_CurveGroup: public CLxInterface
{
public:
    CLxIfc_CurveGroup()
    {
        vt.GetBBox = GetBBox;
        vt.Count = Count;
        vt.ByIndex = ByIndex;
        vTable = &vt.iunk;
        iid = &lx::guid_CurveGroup;
    }

    static auto GetBBox(LXtObjectID wcom,LXtBBox *bbox) -> LxResult
    {
        LXCWxINST (CLxImpl_CurveGroup, loc);
        try
        {
           return loc->cgrp_GetBBox( bbox);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Count(LXtObjectID wcom,unsigned *count) -> LxResult
    {
        LXCWxINST (CLxImpl_CurveGroup, loc);
        try
        {
           return loc->cgrp_Count( count);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ByIndex(LXtObjectID wcom,unsigned index,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_CurveGroup, loc);
        try
        {
           return loc->cgrp_ByIndex( index, ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxCurveGroup vt;
};

class CLxLoc_CurveGroup : public CLxLocalize<ILxCurveGroupID>
{
public:
    CLxLoc_CurveGroup()
    {
        _init();
    }

    CLxLoc_CurveGroup(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_CurveGroup(CLxLoc_CurveGroup const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_CurveGroup;
    }

    auto GetBBox(LXtBBox *bbox) -> LxResult
    {
        return m_loc[0]->GetBBox(m_loc, bbox);
    }

    auto Count(unsigned *count) -> LxResult
    {
        return m_loc[0]->Count(m_loc, count);
    }

    auto ByIndex(unsigned index, void **ppvObj) -> LxResult
    {
        return m_loc[0]->ByIndex(m_loc, index, ppvObj);
    }

    auto ByIndex(unsigned index, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->ByIndex(m_loc, index, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_Curve
{
public:
    virtual ~CLxImpl_Curve() = default;

    virtual auto curve_GetBBox([[maybe_unused]] LXtBBox *bbox) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual double curve_Length(void) = 0;

    virtual auto curve_SplineCount([[maybe_unused]] unsigned *count) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto curve_SplineByIndex([[maybe_unused]] unsigned index, [[maybe_unused]] LXtVector b0, [[maybe_unused]] LXtVector b1, [[maybe_unused]] LXtVector b2, [[maybe_unused]] LXtVector b3) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto curve_SplineLengthByIndex([[maybe_unused]] unsigned index, [[maybe_unused]] double *length) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual unsigned curve_BendCount(void) = 0;

    virtual double curve_Param(void) = 0;

    virtual auto curve_SetParam([[maybe_unused]] double param) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual double curve_LenFraction(void) = 0;

    virtual auto curve_SetLenFraction([[maybe_unused]] double frac) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto curve_Position([[maybe_unused]] LXtVector pos) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto curve_Tangent([[maybe_unused]] LXtVector tan) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto curve_Curvature([[maybe_unused]] double *curv) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto curve_Normal([[maybe_unused]] LXtVector normal) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto curve_MeshNormal([[maybe_unused]] ILxUnknownID meshObj, [[maybe_unused]] LXtMatrix4 xfrm, [[maybe_unused]] LXtVector normal) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto curve_GuideCurveNormal([[maybe_unused]] ILxUnknownID other, [[maybe_unused]] LXtVector normal) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto curve_Closest([[maybe_unused]] const LXtVector probe, [[maybe_unused]] double *param, [[maybe_unused]] LXtVector pos, [[maybe_unused]] LXtVector norm) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto curve_IsClosed([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto curve_WalkByAngle([[maybe_unused]] double start, [[maybe_unused]] double end, [[maybe_unused]] double angle, [[maybe_unused]] ILxUnknownID visitor) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_Curve_GetBBox LxResult curve_GetBBox([[maybe_unused]] LXtBBox *bbox) override
#define LXxO_Curve_GetBBox LXxD_Curve_GetBBox
#define LXxC_Curve_GetBBox(c) LxResult c::curve_GetBBox([[maybe_unused]] LXtBBox *bbox)
#define LXxD_Curve_Length double curve_Length() override
#define LXxO_Curve_Length LXxD_Curve_Length
#define LXxC_Curve_Length(c) double c::curve_Length()
#define LXxD_Curve_SplineCount LxResult curve_SplineCount([[maybe_unused]] unsigned *count) override
#define LXxO_Curve_SplineCount LXxD_Curve_SplineCount
#define LXxC_Curve_SplineCount(c) LxResult c::curve_SplineCount([[maybe_unused]] unsigned *count)
#define LXxD_Curve_SplineByIndex LxResult curve_SplineByIndex([[maybe_unused]] unsigned index, [[maybe_unused]] LXtVector b0, [[maybe_unused]] LXtVector b1, [[maybe_unused]] LXtVector b2, [[maybe_unused]] LXtVector b3) override
#define LXxO_Curve_SplineByIndex LXxD_Curve_SplineByIndex
#define LXxC_Curve_SplineByIndex(c) LxResult c::curve_SplineByIndex([[maybe_unused]] unsigned index, [[maybe_unused]] LXtVector b0, [[maybe_unused]] LXtVector b1, [[maybe_unused]] LXtVector b2, [[maybe_unused]] LXtVector b3)
#define LXxD_Curve_SplineLengthByIndex LxResult curve_SplineLengthByIndex([[maybe_unused]] unsigned index, [[maybe_unused]] double *length) override
#define LXxO_Curve_SplineLengthByIndex LXxD_Curve_SplineLengthByIndex
#define LXxC_Curve_SplineLengthByIndex(c) LxResult c::curve_SplineLengthByIndex([[maybe_unused]] unsigned index, [[maybe_unused]] double *length)
#define LXxD_Curve_BendCount unsigned curve_BendCount() override
#define LXxO_Curve_BendCount LXxD_Curve_BendCount
#define LXxC_Curve_BendCount(c) unsigned c::curve_BendCount()
#define LXxD_Curve_Param double curve_Param() override
#define LXxO_Curve_Param LXxD_Curve_Param
#define LXxC_Curve_Param(c) double c::curve_Param()
#define LXxD_Curve_SetParam LxResult curve_SetParam([[maybe_unused]] double param) override
#define LXxO_Curve_SetParam LXxD_Curve_SetParam
#define LXxC_Curve_SetParam(c) LxResult c::curve_SetParam([[maybe_unused]] double param)
#define LXxD_Curve_LenFraction double curve_LenFraction() override
#define LXxO_Curve_LenFraction LXxD_Curve_LenFraction
#define LXxC_Curve_LenFraction(c) double c::curve_LenFraction()
#define LXxD_Curve_SetLenFraction LxResult curve_SetLenFraction([[maybe_unused]] double frac) override
#define LXxO_Curve_SetLenFraction LXxD_Curve_SetLenFraction
#define LXxC_Curve_SetLenFraction(c) LxResult c::curve_SetLenFraction([[maybe_unused]] double frac)
#define LXxD_Curve_Position LxResult curve_Position([[maybe_unused]] LXtVector pos) override
#define LXxO_Curve_Position LXxD_Curve_Position
#define LXxC_Curve_Position(c) LxResult c::curve_Position([[maybe_unused]] LXtVector pos)
#define LXxD_Curve_Tangent LxResult curve_Tangent([[maybe_unused]] LXtVector tan) override
#define LXxO_Curve_Tangent LXxD_Curve_Tangent
#define LXxC_Curve_Tangent(c) LxResult c::curve_Tangent([[maybe_unused]] LXtVector tan)
#define LXxD_Curve_Curvature LxResult curve_Curvature([[maybe_unused]] double *curv) override
#define LXxO_Curve_Curvature LXxD_Curve_Curvature
#define LXxC_Curve_Curvature(c) LxResult c::curve_Curvature([[maybe_unused]] double *curv)
#define LXxD_Curve_Normal LxResult curve_Normal([[maybe_unused]] LXtVector normal) override
#define LXxO_Curve_Normal LXxD_Curve_Normal
#define LXxC_Curve_Normal(c) LxResult c::curve_Normal([[maybe_unused]] LXtVector normal)
#define LXxD_Curve_MeshNormal LxResult curve_MeshNormal([[maybe_unused]] ILxUnknownID meshObj, [[maybe_unused]] LXtMatrix4 xfrm, [[maybe_unused]] LXtVector normal) override
#define LXxO_Curve_MeshNormal LXxD_Curve_MeshNormal
#define LXxC_Curve_MeshNormal(c) LxResult c::curve_MeshNormal([[maybe_unused]] ILxUnknownID meshObj, [[maybe_unused]] LXtMatrix4 xfrm, [[maybe_unused]] LXtVector normal)
#define LXxD_Curve_GuideCurveNormal LxResult curve_GuideCurveNormal([[maybe_unused]] ILxUnknownID other, [[maybe_unused]] LXtVector normal) override
#define LXxO_Curve_GuideCurveNormal LXxD_Curve_GuideCurveNormal
#define LXxC_Curve_GuideCurveNormal(c) LxResult c::curve_GuideCurveNormal([[maybe_unused]] ILxUnknownID other, [[maybe_unused]] LXtVector normal)
#define LXxD_Curve_Closest LxResult curve_Closest([[maybe_unused]] const LXtVector probe, [[maybe_unused]] double *param, [[maybe_unused]] LXtVector pos, [[maybe_unused]] LXtVector norm) override
#define LXxO_Curve_Closest LXxD_Curve_Closest
#define LXxC_Curve_Closest(c) LxResult c::curve_Closest([[maybe_unused]] const LXtVector probe, [[maybe_unused]] double *param, [[maybe_unused]] LXtVector pos, [[maybe_unused]] LXtVector norm)
#define LXxD_Curve_IsClosed LxResult curve_IsClosed() override
#define LXxO_Curve_IsClosed LXxD_Curve_IsClosed
#define LXxC_Curve_IsClosed(c) LxResult c::curve_IsClosed()
#define LXxD_Curve_WalkByAngle LxResult curve_WalkByAngle([[maybe_unused]] double start, [[maybe_unused]] double end, [[maybe_unused]] double angle, [[maybe_unused]] ILxUnknownID visitor) override
#define LXxO_Curve_WalkByAngle LXxD_Curve_WalkByAngle
#define LXxC_Curve_WalkByAngle(c) LxResult c::curve_WalkByAngle([[maybe_unused]] double start, [[maybe_unused]] double end, [[maybe_unused]] double angle, [[maybe_unused]] ILxUnknownID visitor)

template <class T>
class CLxIfc_Curve: public CLxInterface
{
public:
    CLxIfc_Curve()
    {
        vt.GetBBox = GetBBox;
        vt.Length = Length;
        vt.SplineCount = SplineCount;
        vt.SplineByIndex = SplineByIndex;
        vt.SplineLengthByIndex = SplineLengthByIndex;
        vt.BendCount = BendCount;
        vt.Param = Param;
        vt.SetParam = SetParam;
        vt.LenFraction = LenFraction;
        vt.SetLenFraction = SetLenFraction;
        vt.Position = Position;
        vt.Tangent = Tangent;
        vt.Curvature = Curvature;
        vt.Normal = Normal;
        vt.MeshNormal = MeshNormal;
        vt.GuideCurveNormal = GuideCurveNormal;
        vt.Closest = Closest;
        vt.IsClosed = IsClosed;
        vt.WalkByAngle = WalkByAngle;
        vTable = &vt.iunk;
        iid = &lx::guid_Curve;
    }

    static auto GetBBox(LXtObjectID wcom,LXtBBox *bbox) -> LxResult
    {
        LXCWxINST (CLxImpl_Curve, loc);
        try
        {
           return loc->curve_GetBBox( bbox);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Length(LXtObjectID wcom) -> double
    {
        LXCWxINST (CLxImpl_Curve, loc);
        return loc->curve_Length();
    }

    static auto SplineCount(LXtObjectID wcom,unsigned *count) -> LxResult
    {
        LXCWxINST (CLxImpl_Curve, loc);
        try
        {
           return loc->curve_SplineCount( count);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SplineByIndex(LXtObjectID wcom,unsigned index,LXtVector b0,LXtVector b1,LXtVector b2,LXtVector b3) -> LxResult
    {
        LXCWxINST (CLxImpl_Curve, loc);
        try
        {
           return loc->curve_SplineByIndex( index, b0, b1, b2, b3);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SplineLengthByIndex(LXtObjectID wcom,unsigned index,double *length) -> LxResult
    {
        LXCWxINST (CLxImpl_Curve, loc);
        try
        {
           return loc->curve_SplineLengthByIndex( index, length);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto BendCount(LXtObjectID wcom) -> unsigned
    {
        LXCWxINST (CLxImpl_Curve, loc);
        return loc->curve_BendCount();
    }

    static auto Param(LXtObjectID wcom) -> double
    {
        LXCWxINST (CLxImpl_Curve, loc);
        return loc->curve_Param();
    }

    static auto SetParam(LXtObjectID wcom,double param) -> LxResult
    {
        LXCWxINST (CLxImpl_Curve, loc);
        try
        {
           return loc->curve_SetParam( param);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto LenFraction(LXtObjectID wcom) -> double
    {
        LXCWxINST (CLxImpl_Curve, loc);
        return loc->curve_LenFraction();
    }

    static auto SetLenFraction(LXtObjectID wcom,double frac) -> LxResult
    {
        LXCWxINST (CLxImpl_Curve, loc);
        try
        {
           return loc->curve_SetLenFraction( frac);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Position(LXtObjectID wcom,LXtVector pos) -> LxResult
    {
        LXCWxINST (CLxImpl_Curve, loc);
        try
        {
           return loc->curve_Position( pos);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Tangent(LXtObjectID wcom,LXtVector tan) -> LxResult
    {
        LXCWxINST (CLxImpl_Curve, loc);
        try
        {
           return loc->curve_Tangent( tan);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Curvature(LXtObjectID wcom,double *curv) -> LxResult
    {
        LXCWxINST (CLxImpl_Curve, loc);
        try
        {
           return loc->curve_Curvature( curv);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Normal(LXtObjectID wcom,LXtVector normal) -> LxResult
    {
        LXCWxINST (CLxImpl_Curve, loc);
        try
        {
           return loc->curve_Normal( normal);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto MeshNormal(LXtObjectID wcom,LXtObjectID meshObj,LXtMatrix4 xfrm,LXtVector normal) -> LxResult
    {
        LXCWxINST (CLxImpl_Curve, loc);
        try
        {
           return loc->curve_MeshNormal((ILxUnknownID) meshObj, xfrm, normal);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto GuideCurveNormal(LXtObjectID wcom,LXtObjectID other,LXtVector normal) -> LxResult
    {
        LXCWxINST (CLxImpl_Curve, loc);
        try
        {
           return loc->curve_GuideCurveNormal((ILxUnknownID) other, normal);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Closest(LXtObjectID wcom,const LXtVector probe,double *param,LXtVector pos,LXtVector norm) -> LxResult
    {
        LXCWxINST (CLxImpl_Curve, loc);
        try
        {
           return loc->curve_Closest( probe, param, pos, norm);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto IsClosed(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_Curve, loc);
        try
        {
           return loc->curve_IsClosed();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto WalkByAngle(LXtObjectID wcom,double start,double end,double angle,LXtObjectID visitor) -> LxResult
    {
        LXCWxINST (CLxImpl_Curve, loc);
        try
        {
           return loc->curve_WalkByAngle( start, end, angle,(ILxUnknownID) visitor);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxCurve vt;
};

class CLxLoc_Curve : public CLxLocalize<ILxCurveID>
{
public:
    CLxLoc_Curve()
    {
        _init();
    }

    CLxLoc_Curve(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_Curve(CLxLoc_Curve const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_Curve;
    }

    auto GetBBox(LXtBBox *bbox) -> LxResult
    {
        return m_loc[0]->GetBBox(m_loc, bbox);
    }

    auto Length(void) -> double
    {
        return m_loc[0]->Length(m_loc);
    }

    auto SplineCount(unsigned *count) -> LxResult
    {
        return m_loc[0]->SplineCount(m_loc, count);
    }

    auto SplineByIndex(unsigned index, LXtVector b0, LXtVector b1, LXtVector b2, LXtVector b3) -> LxResult
    {
        return m_loc[0]->SplineByIndex(m_loc, index, b0, b1, b2, b3);
    }

    auto SplineLengthByIndex(unsigned index, double *length) -> LxResult
    {
        return m_loc[0]->SplineLengthByIndex(m_loc, index, length);
    }

    auto BendCount(void) -> unsigned
    {
        return m_loc[0]->BendCount(m_loc);
    }

    auto Param(void) -> double
    {
        return m_loc[0]->Param(m_loc);
    }

    auto SetParam(double param) -> LxResult
    {
        return m_loc[0]->SetParam(m_loc, param);
    }

    auto LenFraction(void) -> double
    {
        return m_loc[0]->LenFraction(m_loc);
    }

    auto SetLenFraction(double frac) -> LxResult
    {
        return m_loc[0]->SetLenFraction(m_loc, frac);
    }

    auto Position(LXtVector pos) -> LxResult
    {
        return m_loc[0]->Position(m_loc, pos);
    }

    auto Tangent(LXtVector tan) -> LxResult
    {
        return m_loc[0]->Tangent(m_loc, tan);
    }

    auto Curvature(double *curv) -> LxResult
    {
        return m_loc[0]->Curvature(m_loc, curv);
    }

    auto Normal(LXtVector normal) -> LxResult
    {
        return m_loc[0]->Normal(m_loc, normal);
    }

    auto MeshNormal(ILxUnknownID meshObj, LXtMatrix4 xfrm, LXtVector normal) -> LxResult
    {
        return m_loc[0]->MeshNormal(m_loc,(ILxUnknownID) meshObj, xfrm, normal);
    }

    auto GuideCurveNormal(ILxUnknownID other, LXtVector normal) -> LxResult
    {
        return m_loc[0]->GuideCurveNormal(m_loc,(ILxUnknownID) other, normal);
    }

    auto Closest(const LXtVector probe, double *param, LXtVector pos, LXtVector norm) -> LxResult
    {
        return m_loc[0]->Closest(m_loc, probe, param, pos, norm);
    }

    auto IsClosed(void) -> LxResult
    {
        return m_loc[0]->IsClosed(m_loc);
    }

    auto WalkByAngle(double start, double end, double angle, ILxUnknownID visitor) -> LxResult
    {
        return m_loc[0]->WalkByAngle(m_loc, start, end, angle,(ILxUnknownID) visitor);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};



