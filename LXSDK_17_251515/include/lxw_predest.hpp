//
// C++ wrapper for lxsdk/lxpredest.h.
//
//	Copyright 2024.
//
//
#pragma once

#include <lxpredest.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx
{
    static LXtGUID const guid_ShaderPreDest = {0x51CE68B9, {0xBDED, 0x41FC}, {0xBD, 0x33, 0x37, 0xBB, 0xAF, 0xFD, 0x18, 0x0B}};
    static LXtGUID const guid_MeshLayerPreDest = {0x052B08CD, {0xF2F2, 0x4C0F}, {0x9D, 0x32, 0x1A, 0xAF, 0xEF, 0x49, 0x4D, 0x36}};
    static LXtGUID const guid_SceneItemPreDest = {0xF81AD9DB, {0x6068, 0x4782}, {0xB1, 0xBB, 0x7F, 0x45, 0x23, 0x36, 0x82, 0xDC}};
    static LXtGUID const guid_Profile1DPreDest = {0x66879EE7, {0x45AE, 0x4704}, {0x8E, 0x03, 0x19, 0xF9, 0x98, 0xEF, 0xDE, 0x73}};
    static LXtGUID const guid_Profile1DPreDest1 = {0xA4E5FAD3, {0xE3A7, 0x4ed9}, {0xA1, 0xE3, 0x4E, 0xB0, 0xD3, 0x1A, 0x41, 0x87}};
    static LXtGUID const guid_Profile2DPreDest = {0x449009ED, {0x847D, 0x4925}, {0x94, 0xBC, 0xC5, 0xE8, 0xEC, 0xCA, 0xD5, 0x15}};
    static LXtGUID const guid_Profile2DPreDest1 = {0xF845F4AD, {0x7DFC, 0x4a41}, {0x98, 0xD1, 0x0F, 0xFB, 0x2C, 0xA7, 0x44, 0xFB}};
    static LXtGUID const guid_ColorPreDest = {0x307b5aab, {0xf8df, 0x4c5b}, {0xb9, 0x16, 0x22, 0x31, 0x72, 0xea, 0x92, 0x1e}};
    static LXtGUID const guid_PresetDestinationService = {0xA4305404, {0x7D11, 0x4A9F}, {0xB8, 0x69, 0xF5, 0x78, 0x61, 0xCE, 0x1D, 0x4D}};
} // namespace lx

class CLxImpl_ShaderPreDest
{
public:
    virtual ~CLxImpl_ShaderPreDest() = default;

    virtual auto spd_Scene([[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto spd_Item([[maybe_unused]] int *mode, [[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto spd_ContainerItem([[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto spd_HitItem([[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto spd_GetTag([[maybe_unused]] LXtID4 type, [[maybe_unused]] const char **tag) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto spd_Mode([[maybe_unused]] int *mode) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_ShaderPreDest_Scene LxResult spd_Scene([[maybe_unused]] void **ppvObj) override
#define LXxO_ShaderPreDest_Scene LXxD_ShaderPreDest_Scene
#define LXxC_ShaderPreDest_Scene(c) LxResult c::spd_Scene([[maybe_unused]] void **ppvObj)
#define LXxD_ShaderPreDest_Item LxResult spd_Item([[maybe_unused]] int *mode, [[maybe_unused]] void **ppvObj) override
#define LXxO_ShaderPreDest_Item LXxD_ShaderPreDest_Item
#define LXxC_ShaderPreDest_Item(c) LxResult c::spd_Item([[maybe_unused]] int *mode, [[maybe_unused]] void **ppvObj)
#define LXxD_ShaderPreDest_ContainerItem LxResult spd_ContainerItem([[maybe_unused]] void **ppvObj) override
#define LXxO_ShaderPreDest_ContainerItem LXxD_ShaderPreDest_ContainerItem
#define LXxC_ShaderPreDest_ContainerItem(c) LxResult c::spd_ContainerItem([[maybe_unused]] void **ppvObj)
#define LXxD_ShaderPreDest_HitItem LxResult spd_HitItem([[maybe_unused]] void **ppvObj) override
#define LXxO_ShaderPreDest_HitItem LXxD_ShaderPreDest_HitItem
#define LXxC_ShaderPreDest_HitItem(c) LxResult c::spd_HitItem([[maybe_unused]] void **ppvObj)
#define LXxD_ShaderPreDest_GetTag LxResult spd_GetTag([[maybe_unused]] LXtID4 type, [[maybe_unused]] const char **tag) override
#define LXxO_ShaderPreDest_GetTag LXxD_ShaderPreDest_GetTag
#define LXxC_ShaderPreDest_GetTag(c) LxResult c::spd_GetTag([[maybe_unused]] LXtID4 type, [[maybe_unused]] const char **tag)
#define LXxD_ShaderPreDest_Mode LxResult spd_Mode([[maybe_unused]] int *mode) override
#define LXxO_ShaderPreDest_Mode LXxD_ShaderPreDest_Mode
#define LXxC_ShaderPreDest_Mode(c) LxResult c::spd_Mode([[maybe_unused]] int *mode)

template <class T>
class CLxIfc_ShaderPreDest: public CLxInterface
{
public:
    CLxIfc_ShaderPreDest()
    {
        vt.Scene = Scene;
        vt.Item = Item;
        vt.ContainerItem = ContainerItem;
        vt.HitItem = HitItem;
        vt.GetTag = GetTag;
        vt.Mode = Mode;
        vTable = &vt.iunk;
        iid = &lx::guid_ShaderPreDest;
    }

    static auto Scene(LXtObjectID wcom,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_ShaderPreDest, loc);
        try
        {
           return loc->spd_Scene( ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Item(LXtObjectID wcom,int *mode,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_ShaderPreDest, loc);
        try
        {
           return loc->spd_Item( mode, ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ContainerItem(LXtObjectID wcom,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_ShaderPreDest, loc);
        try
        {
           return loc->spd_ContainerItem( ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto HitItem(LXtObjectID wcom,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_ShaderPreDest, loc);
        try
        {
           return loc->spd_HitItem( ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto GetTag(LXtObjectID wcom,LXtID4 type,const char **tag) -> LxResult
    {
        LXCWxINST (CLxImpl_ShaderPreDest, loc);
        try
        {
           return loc->spd_GetTag( type, tag);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Mode(LXtObjectID wcom,int *mode) -> LxResult
    {
        LXCWxINST (CLxImpl_ShaderPreDest, loc);
        try
        {
           return loc->spd_Mode( mode);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxShaderPreDest vt;
};

class CLxLoc_ShaderPreDest : public CLxLocalize<ILxShaderPreDestID>
{
public:
    CLxLoc_ShaderPreDest()
    {
        _init();
    }

    CLxLoc_ShaderPreDest(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_ShaderPreDest(CLxLoc_ShaderPreDest const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_ShaderPreDest;
    }

    auto Scene(void **ppvObj) -> LxResult
    {
        return m_loc[0]->Scene(m_loc, ppvObj);
    }

    auto Scene(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Scene(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Item(int *mode, void **ppvObj) -> LxResult
    {
        return m_loc[0]->Item(m_loc, mode, ppvObj);
    }

    auto Item(int *mode, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Item(m_loc, mode, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto ContainerItem(void **ppvObj) -> LxResult
    {
        return m_loc[0]->ContainerItem(m_loc, ppvObj);
    }

    auto ContainerItem(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->ContainerItem(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto HitItem(void **ppvObj) -> LxResult
    {
        return m_loc[0]->HitItem(m_loc, ppvObj);
    }

    auto HitItem(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->HitItem(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto GetTag(LXtID4 type, const char **tag) -> LxResult
    {
        return m_loc[0]->GetTag(m_loc, type, tag);
    }

    auto Mode(int *mode) -> LxResult
    {
        return m_loc[0]->Mode(m_loc, mode);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_MeshLayerPreDest
{
public:
    virtual ~CLxImpl_MeshLayerPreDest() = default;

    virtual auto mlpd_Mesh([[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto mlpd_Transform([[maybe_unused]] LXtMatrix4 xform) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto mlpd_ShaderDest([[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_MeshLayerPreDest_Mesh LxResult mlpd_Mesh([[maybe_unused]] void **ppvObj) override
#define LXxO_MeshLayerPreDest_Mesh LXxD_MeshLayerPreDest_Mesh
#define LXxC_MeshLayerPreDest_Mesh(c) LxResult c::mlpd_Mesh([[maybe_unused]] void **ppvObj)
#define LXxD_MeshLayerPreDest_Transform LxResult mlpd_Transform([[maybe_unused]] LXtMatrix4 xform) override
#define LXxO_MeshLayerPreDest_Transform LXxD_MeshLayerPreDest_Transform
#define LXxC_MeshLayerPreDest_Transform(c) LxResult c::mlpd_Transform([[maybe_unused]] LXtMatrix4 xform)
#define LXxD_MeshLayerPreDest_ShaderDest LxResult mlpd_ShaderDest([[maybe_unused]] void **ppvObj) override
#define LXxO_MeshLayerPreDest_ShaderDest LXxD_MeshLayerPreDest_ShaderDest
#define LXxC_MeshLayerPreDest_ShaderDest(c) LxResult c::mlpd_ShaderDest([[maybe_unused]] void **ppvObj)

template <class T>
class CLxIfc_MeshLayerPreDest: public CLxInterface
{
public:
    CLxIfc_MeshLayerPreDest()
    {
        vt.Mesh = Mesh;
        vt.Transform = Transform;
        vt.ShaderDest = ShaderDest;
        vTable = &vt.iunk;
        iid = &lx::guid_MeshLayerPreDest;
    }

    static auto Mesh(LXtObjectID wcom,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_MeshLayerPreDest, loc);
        try
        {
           return loc->mlpd_Mesh( ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Transform(LXtObjectID wcom,LXtMatrix4 xform) -> LxResult
    {
        LXCWxINST (CLxImpl_MeshLayerPreDest, loc);
        try
        {
           return loc->mlpd_Transform( xform);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ShaderDest(LXtObjectID wcom,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_MeshLayerPreDest, loc);
        try
        {
           return loc->mlpd_ShaderDest( ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxMeshLayerPreDest vt;
};

class CLxLoc_MeshLayerPreDest : public CLxLocalize<ILxMeshLayerPreDestID>
{
public:
    CLxLoc_MeshLayerPreDest()
    {
        _init();
    }

    CLxLoc_MeshLayerPreDest(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_MeshLayerPreDest(CLxLoc_MeshLayerPreDest const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_MeshLayerPreDest;
    }

    auto Mesh(void **ppvObj) -> LxResult
    {
        return m_loc[0]->Mesh(m_loc, ppvObj);
    }

    auto Mesh(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Mesh(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Transform(LXtMatrix4 xform) -> LxResult
    {
        return m_loc[0]->Transform(m_loc, xform);
    }

    auto ShaderDest(void **ppvObj) -> LxResult
    {
        return m_loc[0]->ShaderDest(m_loc, ppvObj);
    }

    auto ShaderDest(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->ShaderDest(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_SceneItemPreDest
{
public:
    virtual ~CLxImpl_SceneItemPreDest() = default;

    virtual auto sipd_Scene([[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto sipd_Item([[maybe_unused]] int *mode, [[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto sipd_ContainerItem([[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto sipd_Position([[maybe_unused]] LXtVector pos) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto sipd_Orientation([[maybe_unused]] LXtMatrix xfrm) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_SceneItemPreDest_Scene LxResult sipd_Scene([[maybe_unused]] void **ppvObj) override
#define LXxO_SceneItemPreDest_Scene LXxD_SceneItemPreDest_Scene
#define LXxC_SceneItemPreDest_Scene(c) LxResult c::sipd_Scene([[maybe_unused]] void **ppvObj)
#define LXxD_SceneItemPreDest_Item LxResult sipd_Item([[maybe_unused]] int *mode, [[maybe_unused]] void **ppvObj) override
#define LXxO_SceneItemPreDest_Item LXxD_SceneItemPreDest_Item
#define LXxC_SceneItemPreDest_Item(c) LxResult c::sipd_Item([[maybe_unused]] int *mode, [[maybe_unused]] void **ppvObj)
#define LXxD_SceneItemPreDest_ContainerItem LxResult sipd_ContainerItem([[maybe_unused]] void **ppvObj) override
#define LXxO_SceneItemPreDest_ContainerItem LXxD_SceneItemPreDest_ContainerItem
#define LXxC_SceneItemPreDest_ContainerItem(c) LxResult c::sipd_ContainerItem([[maybe_unused]] void **ppvObj)
#define LXxD_SceneItemPreDest_Position LxResult sipd_Position([[maybe_unused]] LXtVector pos) override
#define LXxO_SceneItemPreDest_Position LXxD_SceneItemPreDest_Position
#define LXxC_SceneItemPreDest_Position(c) LxResult c::sipd_Position([[maybe_unused]] LXtVector pos)
#define LXxD_SceneItemPreDest_Orientation LxResult sipd_Orientation([[maybe_unused]] LXtMatrix xfrm) override
#define LXxO_SceneItemPreDest_Orientation LXxD_SceneItemPreDest_Orientation
#define LXxC_SceneItemPreDest_Orientation(c) LxResult c::sipd_Orientation([[maybe_unused]] LXtMatrix xfrm)

template <class T>
class CLxIfc_SceneItemPreDest: public CLxInterface
{
public:
    CLxIfc_SceneItemPreDest()
    {
        vt.Scene = Scene;
        vt.Item = Item;
        vt.ContainerItem = ContainerItem;
        vt.Position = Position;
        vt.Orientation = Orientation;
        vTable = &vt.iunk;
        iid = &lx::guid_SceneItemPreDest;
    }

    static auto Scene(LXtObjectID wcom,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_SceneItemPreDest, loc);
        try
        {
           return loc->sipd_Scene( ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Item(LXtObjectID wcom,int *mode,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_SceneItemPreDest, loc);
        try
        {
           return loc->sipd_Item( mode, ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ContainerItem(LXtObjectID wcom,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_SceneItemPreDest, loc);
        try
        {
           return loc->sipd_ContainerItem( ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Position(LXtObjectID wcom,LXtVector pos) -> LxResult
    {
        LXCWxINST (CLxImpl_SceneItemPreDest, loc);
        try
        {
           return loc->sipd_Position( pos);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Orientation(LXtObjectID wcom,LXtMatrix xfrm) -> LxResult
    {
        LXCWxINST (CLxImpl_SceneItemPreDest, loc);
        try
        {
           return loc->sipd_Orientation( xfrm);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxSceneItemPreDest vt;
};

class CLxLoc_SceneItemPreDest : public CLxLocalize<ILxSceneItemPreDestID>
{
public:
    CLxLoc_SceneItemPreDest()
    {
        _init();
    }

    CLxLoc_SceneItemPreDest(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_SceneItemPreDest(CLxLoc_SceneItemPreDest const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_SceneItemPreDest;
    }

    auto Scene(void **ppvObj) -> LxResult
    {
        return m_loc[0]->Scene(m_loc, ppvObj);
    }

    auto Scene(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Scene(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Item(int *mode, void **ppvObj) -> LxResult
    {
        return m_loc[0]->Item(m_loc, mode, ppvObj);
    }

    auto Item(int *mode, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Item(m_loc, mode, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto ContainerItem(void **ppvObj) -> LxResult
    {
        return m_loc[0]->ContainerItem(m_loc, ppvObj);
    }

    auto ContainerItem(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->ContainerItem(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Position(LXtVector pos) -> LxResult
    {
        return m_loc[0]->Position(m_loc, pos);
    }

    auto Orientation(LXtMatrix xfrm) -> LxResult
    {
        return m_loc[0]->Orientation(m_loc, xfrm);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_Profile1DPreDest
{
public:
    virtual ~CLxImpl_Profile1DPreDest() = default;

    virtual auto p1pd_MoveTo([[maybe_unused]] double x, [[maybe_unused]] double y) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto p1pd_LineTo([[maybe_unused]] double x, [[maybe_unused]] double y) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto p1pd_CurveTo([[maybe_unused]] double x0, [[maybe_unused]] double y0, [[maybe_unused]] double x1, [[maybe_unused]] double y1, [[maybe_unused]] double x2, [[maybe_unused]] double y2) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual double p1pd_Evaluate(double t, int flags, int axis) = 0;

    virtual int p1pd_PathSteps(double tol, int flags, double *x, double *y, int nstep) = 0;

    virtual auto p1pd_Box([[maybe_unused]] LXtBBox *box) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual unsigned p1pd_Count(void) = 0;

    virtual auto p1pd_SelectByIndex([[maybe_unused]] unsigned index) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto p1pd_SelectByParameter([[maybe_unused]] double t) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto p1pd_SelectByVertex([[maybe_unused]] LXtMeshID meshID, [[maybe_unused]] LXtPointID pointID) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_Profile1DPreDest_MoveTo LxResult p1pd_MoveTo([[maybe_unused]] double x, [[maybe_unused]] double y) override
#define LXxO_Profile1DPreDest_MoveTo LXxD_Profile1DPreDest_MoveTo
#define LXxC_Profile1DPreDest_MoveTo(c) LxResult c::p1pd_MoveTo([[maybe_unused]] double x, [[maybe_unused]] double y)
#define LXxD_Profile1DPreDest_LineTo LxResult p1pd_LineTo([[maybe_unused]] double x, [[maybe_unused]] double y) override
#define LXxO_Profile1DPreDest_LineTo LXxD_Profile1DPreDest_LineTo
#define LXxC_Profile1DPreDest_LineTo(c) LxResult c::p1pd_LineTo([[maybe_unused]] double x, [[maybe_unused]] double y)
#define LXxD_Profile1DPreDest_CurveTo LxResult p1pd_CurveTo([[maybe_unused]] double x0, [[maybe_unused]] double y0, [[maybe_unused]] double x1, [[maybe_unused]] double y1, [[maybe_unused]] double x2, [[maybe_unused]] double y2) override
#define LXxO_Profile1DPreDest_CurveTo LXxD_Profile1DPreDest_CurveTo
#define LXxC_Profile1DPreDest_CurveTo(c) LxResult c::p1pd_CurveTo([[maybe_unused]] double x0, [[maybe_unused]] double y0, [[maybe_unused]] double x1, [[maybe_unused]] double y1, [[maybe_unused]] double x2, [[maybe_unused]] double y2)
#define LXxD_Profile1DPreDest_Evaluate double p1pd_Evaluate([[maybe_unused]] double t, [[maybe_unused]] int flags, [[maybe_unused]] int axis) override
#define LXxO_Profile1DPreDest_Evaluate LXxD_Profile1DPreDest_Evaluate
#define LXxC_Profile1DPreDest_Evaluate(c) double c::p1pd_Evaluate([[maybe_unused]] double t, [[maybe_unused]] int flags, [[maybe_unused]] int axis)
#define LXxD_Profile1DPreDest_PathSteps int p1pd_PathSteps([[maybe_unused]] double tol, [[maybe_unused]] int flags, [[maybe_unused]] double *x, [[maybe_unused]] double *y, [[maybe_unused]] int nstep) override
#define LXxO_Profile1DPreDest_PathSteps LXxD_Profile1DPreDest_PathSteps
#define LXxC_Profile1DPreDest_PathSteps(c) int c::p1pd_PathSteps([[maybe_unused]] double tol, [[maybe_unused]] int flags, [[maybe_unused]] double *x, [[maybe_unused]] double *y, [[maybe_unused]] int nstep)
#define LXxD_Profile1DPreDest_Box LxResult p1pd_Box([[maybe_unused]] LXtBBox *box) override
#define LXxO_Profile1DPreDest_Box LXxD_Profile1DPreDest_Box
#define LXxC_Profile1DPreDest_Box(c) LxResult c::p1pd_Box([[maybe_unused]] LXtBBox *box)
#define LXxD_Profile1DPreDest_Count unsigned p1pd_Count() override
#define LXxO_Profile1DPreDest_Count LXxD_Profile1DPreDest_Count
#define LXxC_Profile1DPreDest_Count(c) unsigned c::p1pd_Count()
#define LXxD_Profile1DPreDest_SelectByIndex LxResult p1pd_SelectByIndex([[maybe_unused]] unsigned index) override
#define LXxO_Profile1DPreDest_SelectByIndex LXxD_Profile1DPreDest_SelectByIndex
#define LXxC_Profile1DPreDest_SelectByIndex(c) LxResult c::p1pd_SelectByIndex([[maybe_unused]] unsigned index)
#define LXxD_Profile1DPreDest_SelectByParameter LxResult p1pd_SelectByParameter([[maybe_unused]] double t) override
#define LXxO_Profile1DPreDest_SelectByParameter LXxD_Profile1DPreDest_SelectByParameter
#define LXxC_Profile1DPreDest_SelectByParameter(c) LxResult c::p1pd_SelectByParameter([[maybe_unused]] double t)
#define LXxD_Profile1DPreDest_SelectByVertex LxResult p1pd_SelectByVertex([[maybe_unused]] LXtMeshID meshID, [[maybe_unused]] LXtPointID pointID) override
#define LXxO_Profile1DPreDest_SelectByVertex LXxD_Profile1DPreDest_SelectByVertex
#define LXxC_Profile1DPreDest_SelectByVertex(c) LxResult c::p1pd_SelectByVertex([[maybe_unused]] LXtMeshID meshID, [[maybe_unused]] LXtPointID pointID)

template <class T>
class CLxIfc_Profile1DPreDest: public CLxInterface
{
public:
    CLxIfc_Profile1DPreDest()
    {
        vt.MoveTo = MoveTo;
        vt.LineTo = LineTo;
        vt.CurveTo = CurveTo;
        vt.Evaluate = Evaluate;
        vt.PathSteps = PathSteps;
        vt.Box = Box;
        vt.Count = Count;
        vt.SelectByIndex = SelectByIndex;
        vt.SelectByParameter = SelectByParameter;
        vt.SelectByVertex = SelectByVertex;
        vTable = &vt.iunk;
        iid = &lx::guid_Profile1DPreDest;
    }

    static auto MoveTo(LXtObjectID wcom,double x,double y) -> LxResult
    {
        LXCWxINST (CLxImpl_Profile1DPreDest, loc);
        try
        {
           return loc->p1pd_MoveTo( x, y);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto LineTo(LXtObjectID wcom,double x,double y) -> LxResult
    {
        LXCWxINST (CLxImpl_Profile1DPreDest, loc);
        try
        {
           return loc->p1pd_LineTo( x, y);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto CurveTo(LXtObjectID wcom,double x0,double y0,double x1,double y1,double x2,double y2) -> LxResult
    {
        LXCWxINST (CLxImpl_Profile1DPreDest, loc);
        try
        {
           return loc->p1pd_CurveTo( x0, y0, x1, y1, x2, y2);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Evaluate(LXtObjectID wcom,double t,int flags,int axis) -> double
    {
        LXCWxINST (CLxImpl_Profile1DPreDest, loc);
        return loc->p1pd_Evaluate( t, flags, axis);
    }

    static auto PathSteps(LXtObjectID wcom,double tol,int flags,double *x,double *y,int nstep) -> int
    {
        LXCWxINST (CLxImpl_Profile1DPreDest, loc);
        return loc->p1pd_PathSteps( tol, flags, x, y, nstep);
    }

    static auto Box(LXtObjectID wcom,LXtBBox *box) -> LxResult
    {
        LXCWxINST (CLxImpl_Profile1DPreDest, loc);
        try
        {
           return loc->p1pd_Box( box);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Count(LXtObjectID wcom) -> unsigned
    {
        LXCWxINST (CLxImpl_Profile1DPreDest, loc);
        return loc->p1pd_Count();
    }

    static auto SelectByIndex(LXtObjectID wcom,unsigned index) -> LxResult
    {
        LXCWxINST (CLxImpl_Profile1DPreDest, loc);
        try
        {
           return loc->p1pd_SelectByIndex( index);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SelectByParameter(LXtObjectID wcom,double t) -> LxResult
    {
        LXCWxINST (CLxImpl_Profile1DPreDest, loc);
        try
        {
           return loc->p1pd_SelectByParameter( t);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SelectByVertex(LXtObjectID wcom,LXtMeshID meshID,LXtPointID pointID) -> LxResult
    {
        LXCWxINST (CLxImpl_Profile1DPreDest, loc);
        try
        {
           return loc->p1pd_SelectByVertex( meshID, pointID);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxProfile1DPreDest vt;
};

class CLxLoc_Profile1DPreDest : public CLxLocalize<ILxProfile1DPreDestID>
{
public:
    CLxLoc_Profile1DPreDest()
    {
        _init();
    }

    CLxLoc_Profile1DPreDest(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_Profile1DPreDest(CLxLoc_Profile1DPreDest const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_Profile1DPreDest;
    }

    auto MoveTo(double x, double y) -> LxResult
    {
        return m_loc[0]->MoveTo(m_loc, x, y);
    }

    auto LineTo(double x, double y) -> LxResult
    {
        return m_loc[0]->LineTo(m_loc, x, y);
    }

    auto CurveTo(double x0, double y0, double x1, double y1, double x2, double y2) -> LxResult
    {
        return m_loc[0]->CurveTo(m_loc, x0, y0, x1, y1, x2, y2);
    }

    auto Evaluate(double t, int flags, int axis) -> double
    {
        return m_loc[0]->Evaluate(m_loc, t, flags, axis);
    }

    auto PathSteps(double tol, int flags, double *x, double *y, int nstep) -> int
    {
        return m_loc[0]->PathSteps(m_loc, tol, flags, x, y, nstep);
    }

    auto Box(LXtBBox *box) -> LxResult
    {
        return m_loc[0]->Box(m_loc, box);
    }

    auto Count(void) -> unsigned
    {
        return m_loc[0]->Count(m_loc);
    }

    auto SelectByIndex(unsigned index) -> LxResult
    {
        return m_loc[0]->SelectByIndex(m_loc, index);
    }

    auto SelectByParameter(double t) -> LxResult
    {
        return m_loc[0]->SelectByParameter(m_loc, t);
    }

    auto SelectByVertex(LXtMeshID meshID, LXtPointID pointID) -> LxResult
    {
        return m_loc[0]->SelectByVertex(m_loc, meshID, pointID);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_Profile1DPreDest1
{
public:
    virtual ~CLxImpl_Profile1DPreDest1() = default;

    virtual auto p1pd_MoveTo([[maybe_unused]] double x, [[maybe_unused]] double y) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto p1pd_LineTo([[maybe_unused]] double x, [[maybe_unused]] double y) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto p1pd_CurveTo([[maybe_unused]] double x0, [[maybe_unused]] double y0, [[maybe_unused]] double x1, [[maybe_unused]] double y1, [[maybe_unused]] double x2, [[maybe_unused]] double y2) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual double p1pd_Evaluate(double t, int flags, int axis) = 0;

    virtual int p1pd_PathSteps(double tol, int flags, double *x, double *y, int nstep) = 0;

    virtual auto p1pd_Box([[maybe_unused]] LXtBBox *box) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_Profile1DPreDest1_MoveTo LxResult p1pd_MoveTo([[maybe_unused]] double x, [[maybe_unused]] double y) override
#define LXxO_Profile1DPreDest1_MoveTo LXxD_Profile1DPreDest1_MoveTo
#define LXxC_Profile1DPreDest1_MoveTo(c) LxResult c::p1pd_MoveTo([[maybe_unused]] double x, [[maybe_unused]] double y)
#define LXxD_Profile1DPreDest1_LineTo LxResult p1pd_LineTo([[maybe_unused]] double x, [[maybe_unused]] double y) override
#define LXxO_Profile1DPreDest1_LineTo LXxD_Profile1DPreDest1_LineTo
#define LXxC_Profile1DPreDest1_LineTo(c) LxResult c::p1pd_LineTo([[maybe_unused]] double x, [[maybe_unused]] double y)
#define LXxD_Profile1DPreDest1_CurveTo LxResult p1pd_CurveTo([[maybe_unused]] double x0, [[maybe_unused]] double y0, [[maybe_unused]] double x1, [[maybe_unused]] double y1, [[maybe_unused]] double x2, [[maybe_unused]] double y2) override
#define LXxO_Profile1DPreDest1_CurveTo LXxD_Profile1DPreDest1_CurveTo
#define LXxC_Profile1DPreDest1_CurveTo(c) LxResult c::p1pd_CurveTo([[maybe_unused]] double x0, [[maybe_unused]] double y0, [[maybe_unused]] double x1, [[maybe_unused]] double y1, [[maybe_unused]] double x2, [[maybe_unused]] double y2)
#define LXxD_Profile1DPreDest1_Evaluate double p1pd_Evaluate([[maybe_unused]] double t, [[maybe_unused]] int flags, [[maybe_unused]] int axis) override
#define LXxO_Profile1DPreDest1_Evaluate LXxD_Profile1DPreDest1_Evaluate
#define LXxC_Profile1DPreDest1_Evaluate(c) double c::p1pd_Evaluate([[maybe_unused]] double t, [[maybe_unused]] int flags, [[maybe_unused]] int axis)
#define LXxD_Profile1DPreDest1_PathSteps int p1pd_PathSteps([[maybe_unused]] double tol, [[maybe_unused]] int flags, [[maybe_unused]] double *x, [[maybe_unused]] double *y, [[maybe_unused]] int nstep) override
#define LXxO_Profile1DPreDest1_PathSteps LXxD_Profile1DPreDest1_PathSteps
#define LXxC_Profile1DPreDest1_PathSteps(c) int c::p1pd_PathSteps([[maybe_unused]] double tol, [[maybe_unused]] int flags, [[maybe_unused]] double *x, [[maybe_unused]] double *y, [[maybe_unused]] int nstep)
#define LXxD_Profile1DPreDest1_Box LxResult p1pd_Box([[maybe_unused]] LXtBBox *box) override
#define LXxO_Profile1DPreDest1_Box LXxD_Profile1DPreDest1_Box
#define LXxC_Profile1DPreDest1_Box(c) LxResult c::p1pd_Box([[maybe_unused]] LXtBBox *box)

template <class T>
class CLxIfc_Profile1DPreDest1: public CLxInterface
{
public:
    CLxIfc_Profile1DPreDest1()
    {
        vt.MoveTo = MoveTo;
        vt.LineTo = LineTo;
        vt.CurveTo = CurveTo;
        vt.Evaluate = Evaluate;
        vt.PathSteps = PathSteps;
        vt.Box = Box;
        vTable = &vt.iunk;
        iid = &lx::guid_Profile1DPreDest1;
    }

    static auto MoveTo(LXtObjectID wcom,double x,double y) -> LxResult
    {
        LXCWxINST (CLxImpl_Profile1DPreDest1, loc);
        try
        {
           return loc->p1pd_MoveTo( x, y);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto LineTo(LXtObjectID wcom,double x,double y) -> LxResult
    {
        LXCWxINST (CLxImpl_Profile1DPreDest1, loc);
        try
        {
           return loc->p1pd_LineTo( x, y);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto CurveTo(LXtObjectID wcom,double x0,double y0,double x1,double y1,double x2,double y2) -> LxResult
    {
        LXCWxINST (CLxImpl_Profile1DPreDest1, loc);
        try
        {
           return loc->p1pd_CurveTo( x0, y0, x1, y1, x2, y2);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Evaluate(LXtObjectID wcom,double t,int flags,int axis) -> double
    {
        LXCWxINST (CLxImpl_Profile1DPreDest1, loc);
        return loc->p1pd_Evaluate( t, flags, axis);
    }

    static auto PathSteps(LXtObjectID wcom,double tol,int flags,double *x,double *y,int nstep) -> int
    {
        LXCWxINST (CLxImpl_Profile1DPreDest1, loc);
        return loc->p1pd_PathSteps( tol, flags, x, y, nstep);
    }

    static auto Box(LXtObjectID wcom,LXtBBox *box) -> LxResult
    {
        LXCWxINST (CLxImpl_Profile1DPreDest1, loc);
        try
        {
           return loc->p1pd_Box( box);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxProfile1DPreDest1 vt;
};

class CLxLoc_Profile1DPreDest1 : public CLxLocalize<ILxProfile1DPreDest1ID>
{
public:
    CLxLoc_Profile1DPreDest1()
    {
        _init();
    }

    CLxLoc_Profile1DPreDest1(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_Profile1DPreDest1(CLxLoc_Profile1DPreDest1 const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_Profile1DPreDest1;
    }

    auto MoveTo(double x, double y) -> LxResult
    {
        return m_loc[0]->MoveTo(m_loc, x, y);
    }

    auto LineTo(double x, double y) -> LxResult
    {
        return m_loc[0]->LineTo(m_loc, x, y);
    }

    auto CurveTo(double x0, double y0, double x1, double y1, double x2, double y2) -> LxResult
    {
        return m_loc[0]->CurveTo(m_loc, x0, y0, x1, y1, x2, y2);
    }

    auto Evaluate(double t, int flags, int axis) -> double
    {
        return m_loc[0]->Evaluate(m_loc, t, flags, axis);
    }

    auto PathSteps(double tol, int flags, double *x, double *y, int nstep) -> int
    {
        return m_loc[0]->PathSteps(m_loc, tol, flags, x, y, nstep);
    }

    auto Box(LXtBBox *box) -> LxResult
    {
        return m_loc[0]->Box(m_loc, box);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_Profile2DPreDest
{
public:
    virtual ~CLxImpl_Profile2DPreDest() = default;

    virtual auto p2pd_MoveTo([[maybe_unused]] double x, [[maybe_unused]] double y) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto p2pd_LineTo([[maybe_unused]] double x, [[maybe_unused]] double y) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto p2pd_CurveTo([[maybe_unused]] double x0, [[maybe_unused]] double y0, [[maybe_unused]] double x1, [[maybe_unused]] double y1, [[maybe_unused]] double x2, [[maybe_unused]] double y2) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto p2pd_NewPath([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto p2pd_Closed([[maybe_unused]] int closed) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto p2pd_Box([[maybe_unused]] LXtBBox *box) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual unsigned p2pd_Count(void) = 0;

    virtual auto p2pd_SelectByIndex([[maybe_unused]] unsigned index) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_Profile2DPreDest_MoveTo LxResult p2pd_MoveTo([[maybe_unused]] double x, [[maybe_unused]] double y) override
#define LXxO_Profile2DPreDest_MoveTo LXxD_Profile2DPreDest_MoveTo
#define LXxC_Profile2DPreDest_MoveTo(c) LxResult c::p2pd_MoveTo([[maybe_unused]] double x, [[maybe_unused]] double y)
#define LXxD_Profile2DPreDest_LineTo LxResult p2pd_LineTo([[maybe_unused]] double x, [[maybe_unused]] double y) override
#define LXxO_Profile2DPreDest_LineTo LXxD_Profile2DPreDest_LineTo
#define LXxC_Profile2DPreDest_LineTo(c) LxResult c::p2pd_LineTo([[maybe_unused]] double x, [[maybe_unused]] double y)
#define LXxD_Profile2DPreDest_CurveTo LxResult p2pd_CurveTo([[maybe_unused]] double x0, [[maybe_unused]] double y0, [[maybe_unused]] double x1, [[maybe_unused]] double y1, [[maybe_unused]] double x2, [[maybe_unused]] double y2) override
#define LXxO_Profile2DPreDest_CurveTo LXxD_Profile2DPreDest_CurveTo
#define LXxC_Profile2DPreDest_CurveTo(c) LxResult c::p2pd_CurveTo([[maybe_unused]] double x0, [[maybe_unused]] double y0, [[maybe_unused]] double x1, [[maybe_unused]] double y1, [[maybe_unused]] double x2, [[maybe_unused]] double y2)
#define LXxD_Profile2DPreDest_NewPath LxResult p2pd_NewPath() override
#define LXxO_Profile2DPreDest_NewPath LXxD_Profile2DPreDest_NewPath
#define LXxC_Profile2DPreDest_NewPath(c) LxResult c::p2pd_NewPath()
#define LXxD_Profile2DPreDest_Closed LxResult p2pd_Closed([[maybe_unused]] int closed) override
#define LXxO_Profile2DPreDest_Closed LXxD_Profile2DPreDest_Closed
#define LXxC_Profile2DPreDest_Closed(c) LxResult c::p2pd_Closed([[maybe_unused]] int closed)
#define LXxD_Profile2DPreDest_Box LxResult p2pd_Box([[maybe_unused]] LXtBBox *box) override
#define LXxO_Profile2DPreDest_Box LXxD_Profile2DPreDest_Box
#define LXxC_Profile2DPreDest_Box(c) LxResult c::p2pd_Box([[maybe_unused]] LXtBBox *box)
#define LXxD_Profile2DPreDest_Count unsigned p2pd_Count() override
#define LXxO_Profile2DPreDest_Count LXxD_Profile2DPreDest_Count
#define LXxC_Profile2DPreDest_Count(c) unsigned c::p2pd_Count()
#define LXxD_Profile2DPreDest_SelectByIndex LxResult p2pd_SelectByIndex([[maybe_unused]] unsigned index) override
#define LXxO_Profile2DPreDest_SelectByIndex LXxD_Profile2DPreDest_SelectByIndex
#define LXxC_Profile2DPreDest_SelectByIndex(c) LxResult c::p2pd_SelectByIndex([[maybe_unused]] unsigned index)

template <class T>
class CLxIfc_Profile2DPreDest: public CLxInterface
{
public:
    CLxIfc_Profile2DPreDest()
    {
        vt.MoveTo = MoveTo;
        vt.LineTo = LineTo;
        vt.CurveTo = CurveTo;
        vt.NewPath = NewPath;
        vt.Closed = Closed;
        vt.Box = Box;
        vt.Count = Count;
        vt.SelectByIndex = SelectByIndex;
        vTable = &vt.iunk;
        iid = &lx::guid_Profile2DPreDest;
    }

    static auto MoveTo(LXtObjectID wcom,double x,double y) -> LxResult
    {
        LXCWxINST (CLxImpl_Profile2DPreDest, loc);
        try
        {
           return loc->p2pd_MoveTo( x, y);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto LineTo(LXtObjectID wcom,double x,double y) -> LxResult
    {
        LXCWxINST (CLxImpl_Profile2DPreDest, loc);
        try
        {
           return loc->p2pd_LineTo( x, y);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto CurveTo(LXtObjectID wcom,double x0,double y0,double x1,double y1,double x2,double y2) -> LxResult
    {
        LXCWxINST (CLxImpl_Profile2DPreDest, loc);
        try
        {
           return loc->p2pd_CurveTo( x0, y0, x1, y1, x2, y2);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto NewPath(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_Profile2DPreDest, loc);
        try
        {
           return loc->p2pd_NewPath();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Closed(LXtObjectID wcom,int closed) -> LxResult
    {
        LXCWxINST (CLxImpl_Profile2DPreDest, loc);
        try
        {
           return loc->p2pd_Closed( closed);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Box(LXtObjectID wcom,LXtBBox *box) -> LxResult
    {
        LXCWxINST (CLxImpl_Profile2DPreDest, loc);
        try
        {
           return loc->p2pd_Box( box);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Count(LXtObjectID wcom) -> unsigned
    {
        LXCWxINST (CLxImpl_Profile2DPreDest, loc);
        return loc->p2pd_Count();
    }

    static auto SelectByIndex(LXtObjectID wcom,unsigned index) -> LxResult
    {
        LXCWxINST (CLxImpl_Profile2DPreDest, loc);
        try
        {
           return loc->p2pd_SelectByIndex( index);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxProfile2DPreDest vt;
};

class CLxLoc_Profile2DPreDest : public CLxLocalize<ILxProfile2DPreDestID>
{
public:
    CLxLoc_Profile2DPreDest()
    {
        _init();
    }

    CLxLoc_Profile2DPreDest(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_Profile2DPreDest(CLxLoc_Profile2DPreDest const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_Profile2DPreDest;
    }

    auto MoveTo(double x, double y) -> LxResult
    {
        return m_loc[0]->MoveTo(m_loc, x, y);
    }

    auto LineTo(double x, double y) -> LxResult
    {
        return m_loc[0]->LineTo(m_loc, x, y);
    }

    auto CurveTo(double x0, double y0, double x1, double y1, double x2, double y2) -> LxResult
    {
        return m_loc[0]->CurveTo(m_loc, x0, y0, x1, y1, x2, y2);
    }

    auto NewPath(void) -> LxResult
    {
        return m_loc[0]->NewPath(m_loc);
    }

    auto Closed(int closed) -> LxResult
    {
        return m_loc[0]->Closed(m_loc, closed);
    }

    auto Box(LXtBBox *box) -> LxResult
    {
        return m_loc[0]->Box(m_loc, box);
    }

    auto Count(void) -> unsigned
    {
        return m_loc[0]->Count(m_loc);
    }

    auto SelectByIndex(unsigned index) -> LxResult
    {
        return m_loc[0]->SelectByIndex(m_loc, index);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};

class CLxImpl_ColorPreDest
{
public:
    virtual ~CLxImpl_ColorPreDest() = default;

    virtual auto colpd_SetColor([[maybe_unused]] const LXtVector rgb) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto colpd_SetColorModel([[maybe_unused]] const char *name, [[maybe_unused]] const double *vec) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto colpd_Apply([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_ColorPreDest_SetColor LxResult colpd_SetColor([[maybe_unused]] const LXtVector rgb) override
#define LXxO_ColorPreDest_SetColor LXxD_ColorPreDest_SetColor
#define LXxC_ColorPreDest_SetColor(c) LxResult c::colpd_SetColor([[maybe_unused]] const LXtVector rgb)
#define LXxD_ColorPreDest_SetColorModel LxResult colpd_SetColorModel([[maybe_unused]] const char *name, [[maybe_unused]] const double *vec) override
#define LXxO_ColorPreDest_SetColorModel LXxD_ColorPreDest_SetColorModel
#define LXxC_ColorPreDest_SetColorModel(c) LxResult c::colpd_SetColorModel([[maybe_unused]] const char *name, [[maybe_unused]] const double *vec)
#define LXxD_ColorPreDest_Apply LxResult colpd_Apply() override
#define LXxO_ColorPreDest_Apply LXxD_ColorPreDest_Apply
#define LXxC_ColorPreDest_Apply(c) LxResult c::colpd_Apply()

template <class T>
class CLxIfc_ColorPreDest: public CLxInterface
{
public:
    CLxIfc_ColorPreDest()
    {
        vt.SetColor = SetColor;
        vt.SetColorModel = SetColorModel;
        vt.Apply = Apply;
        vTable = &vt.iunk;
        iid = &lx::guid_ColorPreDest;
    }

    static auto SetColor(LXtObjectID wcom,const LXtVector rgb) -> LxResult
    {
        LXCWxINST (CLxImpl_ColorPreDest, loc);
        try
        {
           return loc->colpd_SetColor( rgb);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SetColorModel(LXtObjectID wcom,const char *name,const double *vec) -> LxResult
    {
        LXCWxINST (CLxImpl_ColorPreDest, loc);
        try
        {
           return loc->colpd_SetColorModel( name, vec);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Apply(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_ColorPreDest, loc);
        try
        {
           return loc->colpd_Apply();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxColorPreDest vt;
};

class CLxLoc_ColorPreDest : public CLxLocalize<ILxColorPreDestID>
{
public:
    CLxLoc_ColorPreDest()
    {
        _init();
    }

    CLxLoc_ColorPreDest(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_ColorPreDest(CLxLoc_ColorPreDest const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_ColorPreDest;
    }

    auto SetColor(const LXtVector rgb) -> LxResult
    {
        return m_loc[0]->SetColor(m_loc, rgb);
    }

    auto SetColorModel(const char *name, const double *vec) -> LxResult
    {
        return m_loc[0]->SetColorModel(m_loc, name, vec);
    }

    auto Apply(void) -> LxResult
    {
        return m_loc[0]->Apply(m_loc);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_PresetDestinationService : public CLxLocalizedService
{
public:
    ILxPresetDestinationServiceID m_loc{ nullptr };

public:
    CLxLoc_PresetDestinationService()
    {
        _init();
        set();
    }

    ~CLxLoc_PresetDestinationService() = default;

    void set()
    {
        if (!m_loc)
        {
            m_loc = reinterpret_cast<ILxPresetDestinationServiceID>(lx::GetGlobal(&lx::guid_PresetDestinationService));
        }
    }

    auto ShaderPDFromItem(ILxUnknownID item, void **ppvObj) -> LxResult
    {
        return m_loc[0]->ShaderPDFromItem(m_loc,(ILxUnknownID) item, ppvObj);
    }

    auto ShaderPDFromItem(ILxUnknownID item, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->ShaderPDFromItem(m_loc,(ILxUnknownID) item, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto CreateMeshLayerPD(ILxUnknownID mesh, ILxUnknownID shadeItem, void **ppvObj) -> LxResult
    {
        return m_loc[0]->CreateMeshLayerPD(m_loc,(ILxUnknownID) mesh,(ILxUnknownID) shadeItem, ppvObj);
    }

    auto CreateMeshLayerPD(ILxUnknownID mesh, ILxUnknownID shadeItem, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->CreateMeshLayerPD(m_loc,(ILxUnknownID) mesh,(ILxUnknownID) shadeItem, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Profile1DPDFromPath(const char *filepath, void **ppvObj) -> LxResult
    {
        return m_loc[0]->Profile1DPDFromPath(m_loc, filepath, ppvObj);
    }

    auto Profile1DPDFromPath(const char *filepath, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Profile1DPDFromPath(m_loc, filepath, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Profile2DPDFromPath(const char *filepath, void **ppvObj) -> LxResult
    {
        return m_loc[0]->Profile2DPDFromPath(m_loc, filepath, ppvObj);
    }

    auto Profile2DPDFromPath(const char *filepath, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Profile2DPDFromPath(m_loc, filepath, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto ApplyProfilePDToMesh(ILxUnknownID predest, double tolerance, int freeze, int axis, ILxUnknownID mesh) -> LxResult
    {
        return m_loc[0]->ApplyProfilePDToMesh(m_loc,(ILxUnknownID) predest, tolerance, freeze, axis,(ILxUnknownID) mesh);
    }

    auto ApplyMeshPresetToMeshPD(ILxUnknownID predest, const char *filepath) -> LxResult
    {
        return m_loc[0]->ApplyMeshPresetToMeshPD(m_loc,(ILxUnknownID) predest, filepath);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
