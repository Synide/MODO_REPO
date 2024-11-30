//
// C++ wrapper for lxsdk/lxvp.h.
//
//	Copyright 2024.
//
//
#pragma once

#include <lxvp.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx
{
    static LXtGUID const guid_View3D = {0x02DBFE75, {0xC1AB, 0x4E23}, {0xA4, 0xC9, 0x90, 0x50, 0x8C, 0x7C, 0xD7, 0xC3}};
    static LXtGUID const guid_GLViewport = {0x9F4D9937, {0xFF49, 0x45E4}, {0x97, 0x81, 0x80, 0x85, 0xA9, 0x46, 0x36, 0x61}};
    static LXtGUID const guid_GLViewportClient = {0x2975C75E, {0x1F2C, 0x4448}, {0x98, 0xBB, 0xD3, 0xFA, 0x8A, 0xDF, 0x85, 0x95}};
    static LXtGUID const guid_View3DportService = {0xD84FF812, {0xE4E9, 0x41DC}, {0xB8, 0x2F, 0xB5, 0x50, 0xAC, 0xF2, 0xE4, 0x0A}};
    static LXtGUID const guid_SimulationListener = {0x628A3377, {0xC56B, 0x4801}, {0x87, 0x8C, 0x8B, 0xF8, 0x7A, 0x09, 0x7D, 0x29}};
} // namespace lx

class CLxLoc_View3D : public CLxLocalize<ILxView3DID>
{
public:
    CLxLoc_View3D()
    {
        _init();
    }

    CLxLoc_View3D(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_View3D(CLxLoc_View3D const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_View3D;
    }

    auto Space(void) -> LXtID4
    {
        return m_loc[0]->Space(m_loc);
    }

    auto Axis(int *cam, LXtVector axis) -> int
    {
        return m_loc[0]->Axis(m_loc, cam, axis);
    }

    auto Bounds(int *x, int *y, int *w, int *h) -> LxResult
    {
        return m_loc[0]->Bounds(m_loc, x, y, w, h);
    }

    auto Style(int option) -> int
    {
        return m_loc[0]->Style(m_loc, option);
    }

    auto PixelSize(void) -> double
    {
        return m_loc[0]->PixelSize(m_loc);
    }

    auto Center(LXtVector center) -> LxResult
    {
        return m_loc[0]->Center(m_loc, center);
    }

    auto EyeVector(LXtVector pos, LXtVector dir) -> double
    {
        return m_loc[0]->EyeVector(m_loc, pos, dir);
    }

    auto Matrix(LXtMatrix mat, int inverse) -> LxResult
    {
        return m_loc[0]->Matrix(m_loc, mat, inverse);
    }

    auto Angles(LXtVector hpb) -> LxResult
    {
        return m_loc[0]->Angles(m_loc, hpb);
    }

    auto WorkPlane(LXtVector center) -> int
    {
        return m_loc[0]->WorkPlane(m_loc, center);
    }

    auto To3D(float x, float y, LXtVector pos, int flags) -> LxResult
    {
        return m_loc[0]->To3D(m_loc, x, y, pos, flags);
    }

    auto To3DHit(float x, float y, LXtVector pos, LXtVector nrm) -> LxResult
    {
        return m_loc[0]->To3DHit(m_loc, x, y, pos, nrm);
    }

    auto Backdrop(void **item) -> LxResult
    {
        return m_loc[0]->Backdrop(m_loc, item);
    }

    auto BackdropName(void) -> const char*
    {
        return m_loc[0]->BackdropName(m_loc);
    }

    auto BackdropPlace(double *cx, double *cy, double *w, double *h) -> LxResult
    {
        return m_loc[0]->BackdropPlace(m_loc, cx, cy, w, h);
    }

    auto BackdropAspect(double *asp) -> int
    {
        return m_loc[0]->BackdropAspect(m_loc, asp);
    }

    auto BackdropOrient(double *ang) -> int
    {
        return m_loc[0]->BackdropOrient(m_loc, ang);
    }

    auto BackdropLook(double *brit, double *cont, double *trns) -> int
    {
        return m_loc[0]->BackdropLook(m_loc, brit, cont, trns);
    }

    auto BackdropRender(int *resolution, int *blend) -> int
    {
        return m_loc[0]->BackdropRender(m_loc, resolution, blend);
    }

    auto HitElement(LXtID4 type, float x, float y, void **list) -> int
    {
        return m_loc[0]->HitElement(m_loc, type, x, y, list);
    }

    auto GridSize(void) -> double
    {
        return m_loc[0]->GridSize(m_loc);
    }

    auto FrameRate(void) -> double
    {
        return m_loc[0]->FrameRate(m_loc);
    }

    auto SetMatrix(const LXtMatrix mat) -> LxResult
    {
        return m_loc[0]->SetMatrix(m_loc, mat);
    }

    auto SetCenter(const LXtVector vec) -> LxResult
    {
        return m_loc[0]->SetCenter(m_loc, vec);
    }

    auto SetScale(double scl) -> LxResult
    {
        return m_loc[0]->SetScale(m_loc, scl);
    }

    auto ItemShade(ILxUnknownID item, unsigned *shade) -> LxResult
    {
        return m_loc[0]->ItemShade(m_loc,(ILxUnknownID) item, shade);
    }

    auto ItemColor(ILxUnknownID item, LXtFVector4 color) -> LxResult
    {
        return m_loc[0]->ItemColor(m_loc,(ILxUnknownID) item, color);
    }

    auto ItemSelColor(ILxUnknownID item, LXtFVector4 color) -> LxResult
    {
        return m_loc[0]->ItemSelColor(m_loc,(ILxUnknownID) item, color);
    }

    auto ItemWireOverlay(ILxUnknownID item, LXtFVector4 color, unsigned *wireframe) -> LxResult
    {
        return m_loc[0]->ItemWireOverlay(m_loc,(ILxUnknownID) item, color, wireframe);
    }

    auto Deformers(void) -> LxResult
    {
        return m_loc[0]->Deformers(m_loc);
    }

    auto ItemIsVisible(ILxUnknownID item) -> LxResult
    {
        return m_loc[0]->ItemIsVisible(m_loc,(ILxUnknownID) item);
    }

    auto ToUVHit(const char *name, float x, float y, unsigned layer, float *u, float *v) -> LxResult
    {
        return m_loc[0]->ToUVHit(m_loc, name, x, y, layer, u, v);
    }

    auto InvalidateSurface(ILxUnknownID item) -> LxResult
    {
        return m_loc[0]->InvalidateSurface(m_loc,(ILxUnknownID) item);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_GLViewport : public CLxLocalize<ILxGLViewportID>
{
public:
    CLxLoc_GLViewport()
    {
        _init();
    }

    CLxLoc_GLViewport(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_GLViewport(CLxLoc_GLViewport const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_GLViewport;
    }

    auto Initialize(ILxUnknownID client) -> LxResult
    {
        return m_loc[0]->Initialize(m_loc,(ILxUnknownID) client);
    }

    auto SetSize(unsigned w, unsigned h) -> LxResult
    {
        return m_loc[0]->SetSize(m_loc, w, h);
    }

    auto Draw(void) -> LxResult
    {
        return m_loc[0]->Draw(m_loc);
    }

    auto MouseEvent(unsigned event) -> LxResult
    {
        return m_loc[0]->MouseEvent(m_loc, event);
    }

    auto SelectViewport(void) -> LxResult
    {
        return m_loc[0]->SelectViewport(m_loc);
    }

    auto DropDestination(int x, int y, void **ppvObj) -> LxResult
    {
        return m_loc[0]->DropDestination(m_loc, x, y, ppvObj);
    }

    auto DropDestination(int x, int y, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->DropDestination(m_loc, x, y, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_GLViewportClient
{
public:
    virtual ~CLxImpl_GLViewportClient() = default;

    virtual auto glclient_Invalidate([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto glclient_MousePosition([[maybe_unused]] int *x, [[maybe_unused]] int *y) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto glclient_MouseButton([[maybe_unused]] unsigned *button) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto glclient_TabletPressure([[maybe_unused]] double *press) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto glclient_TabletTilt([[maybe_unused]] double *tilt) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto glclient_MouseCount([[maybe_unused]] int *count) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_GLViewportClient_Invalidate LxResult glclient_Invalidate() override
#define LXxO_GLViewportClient_Invalidate LXxD_GLViewportClient_Invalidate
#define LXxC_GLViewportClient_Invalidate(c) LxResult c::glclient_Invalidate()
#define LXxD_GLViewportClient_MousePosition LxResult glclient_MousePosition([[maybe_unused]] int *x, [[maybe_unused]] int *y) override
#define LXxO_GLViewportClient_MousePosition LXxD_GLViewportClient_MousePosition
#define LXxC_GLViewportClient_MousePosition(c) LxResult c::glclient_MousePosition([[maybe_unused]] int *x, [[maybe_unused]] int *y)
#define LXxD_GLViewportClient_MouseButton LxResult glclient_MouseButton([[maybe_unused]] unsigned *button) override
#define LXxO_GLViewportClient_MouseButton LXxD_GLViewportClient_MouseButton
#define LXxC_GLViewportClient_MouseButton(c) LxResult c::glclient_MouseButton([[maybe_unused]] unsigned *button)
#define LXxD_GLViewportClient_TabletPressure LxResult glclient_TabletPressure([[maybe_unused]] double *press) override
#define LXxO_GLViewportClient_TabletPressure LXxD_GLViewportClient_TabletPressure
#define LXxC_GLViewportClient_TabletPressure(c) LxResult c::glclient_TabletPressure([[maybe_unused]] double *press)
#define LXxD_GLViewportClient_TabletTilt LxResult glclient_TabletTilt([[maybe_unused]] double *tilt) override
#define LXxO_GLViewportClient_TabletTilt LXxD_GLViewportClient_TabletTilt
#define LXxC_GLViewportClient_TabletTilt(c) LxResult c::glclient_TabletTilt([[maybe_unused]] double *tilt)
#define LXxD_GLViewportClient_MouseCount LxResult glclient_MouseCount([[maybe_unused]] int *count) override
#define LXxO_GLViewportClient_MouseCount LXxD_GLViewportClient_MouseCount
#define LXxC_GLViewportClient_MouseCount(c) LxResult c::glclient_MouseCount([[maybe_unused]] int *count)

template <class T>
class CLxIfc_GLViewportClient: public CLxInterface
{
public:
    CLxIfc_GLViewportClient()
    {
        vt.Invalidate = Invalidate;
        vt.MousePosition = MousePosition;
        vt.MouseButton = MouseButton;
        vt.TabletPressure = TabletPressure;
        vt.TabletTilt = TabletTilt;
        vt.MouseCount = MouseCount;
        vTable = &vt.iunk;
        iid = &lx::guid_GLViewportClient;
    }

    static auto Invalidate(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_GLViewportClient, loc);
        try
        {
           return loc->glclient_Invalidate();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto MousePosition(LXtObjectID wcom,int *x,int *y) -> LxResult
    {
        LXCWxINST (CLxImpl_GLViewportClient, loc);
        try
        {
           return loc->glclient_MousePosition( x, y);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto MouseButton(LXtObjectID wcom,unsigned *button) -> LxResult
    {
        LXCWxINST (CLxImpl_GLViewportClient, loc);
        try
        {
           return loc->glclient_MouseButton( button);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto TabletPressure(LXtObjectID wcom,double *press) -> LxResult
    {
        LXCWxINST (CLxImpl_GLViewportClient, loc);
        try
        {
           return loc->glclient_TabletPressure( press);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto TabletTilt(LXtObjectID wcom,double *tilt) -> LxResult
    {
        LXCWxINST (CLxImpl_GLViewportClient, loc);
        try
        {
           return loc->glclient_TabletTilt( tilt);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto MouseCount(LXtObjectID wcom,int *count) -> LxResult
    {
        LXCWxINST (CLxImpl_GLViewportClient, loc);
        try
        {
           return loc->glclient_MouseCount( count);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxGLViewportClient vt;
};

class CLxLoc_GLViewportClient : public CLxLocalize<ILxGLViewportClientID>
{
public:
    CLxLoc_GLViewportClient()
    {
        _init();
    }

    CLxLoc_GLViewportClient(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_GLViewportClient(CLxLoc_GLViewportClient const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_GLViewportClient;
    }

    auto Invalidate(void) -> LxResult
    {
        return m_loc[0]->Invalidate(m_loc);
    }

    auto MousePosition(int *x, int *y) -> LxResult
    {
        return m_loc[0]->MousePosition(m_loc, x, y);
    }

    auto MouseButton(unsigned *button) -> LxResult
    {
        return m_loc[0]->MouseButton(m_loc, button);
    }

    auto TabletPressure(double *press) -> LxResult
    {
        return m_loc[0]->TabletPressure(m_loc, press);
    }

    auto TabletTilt(double *tilt) -> LxResult
    {
        return m_loc[0]->TabletTilt(m_loc, tilt);
    }

    auto MouseCount(int *count) -> LxResult
    {
        return m_loc[0]->MouseCount(m_loc, count);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_View3DportService : public CLxLocalizedService
{
public:
    ILxView3DportServiceID m_loc{ nullptr };

public:
    CLxLoc_View3DportService()
    {
        _init();
        set();
    }

    ~CLxLoc_View3DportService() = default;

    void set()
    {
        if (!m_loc)
        {
            m_loc = reinterpret_cast<ILxView3DportServiceID>(lx::GetGlobal(&lx::guid_View3DportService));
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

    auto Count(void) -> int
    {
        return m_loc[0]->Count(m_loc);
    }

    auto Current(void) -> int
    {
        return m_loc[0]->Current(m_loc);
    }

    auto View(int index, void **ppvObj) -> LxResult
    {
        return m_loc[0]->View(m_loc, index, ppvObj);
    }

    auto View(int index, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->View(m_loc, index, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Mouse(int *x, int *y) -> int
    {
        return m_loc[0]->Mouse(m_loc, x, y);
    }

    auto SetHitUVMap(const char *name) -> LxResult
    {
        return m_loc[0]->SetHitUVMap(m_loc, name);
    }

    auto InvalidateOverrider(ILxUnknownID scene, const char *pkgName) -> int
    {
        return m_loc[0]->InvalidateOverrider(m_loc,(ILxUnknownID) scene, pkgName);
    }

    auto GLMaterial(ILxUnknownID bin, ILxUnknownID item, ILxUnknownID view, void **ppvObj) -> LxResult
    {
        return m_loc[0]->GLMaterial(m_loc,(ILxUnknownID) bin,(ILxUnknownID) item,(ILxUnknownID) view, ppvObj);
    }

    auto GLMaterial(ILxUnknownID bin, ILxUnknownID item, ILxUnknownID view, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->GLMaterial(m_loc,(ILxUnknownID) bin,(ILxUnknownID) item,(ILxUnknownID) view, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto TriGroupToViewObject(unsigned int type, ILxUnknownID triGroup, void **ppvObj) -> LxResult
    {
        return m_loc[0]->TriGroupToViewObject(m_loc, type,(ILxUnknownID) triGroup, ppvObj);
    }

    auto TriGroupToViewObject(unsigned int type, ILxUnknownID triGroup, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->TriGroupToViewObject(m_loc, type,(ILxUnknownID) triGroup, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto ImageToGLImage(ILxUnknownID image, void **ppvObj) -> LxResult
    {
        return m_loc[0]->ImageToGLImage(m_loc,(ILxUnknownID) image, ppvObj);
    }

    auto ImageToGLImage(ILxUnknownID image, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->ImageToGLImage(m_loc,(ILxUnknownID) image, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto AllocGLViewport(void **ppvObj) -> LxResult
    {
        return m_loc[0]->AllocGLViewport(m_loc, ppvObj);
    }

    auto AllocGLViewport(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->AllocGLViewport(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto AddVirtualModel(ILxUnknownID vmodel) -> LxResult
    {
        return m_loc[0]->AddVirtualModel(m_loc,(ILxUnknownID) vmodel);
    }

    auto RemoveVirtualModel(ILxUnknownID vmodel) -> void
    {
        m_loc[0]->RemoveVirtualModel(m_loc,(ILxUnknownID) vmodel);
    }

    auto UpdateVirtualModel(ILxUnknownID vmodel) -> void
    {
        m_loc[0]->UpdateVirtualModel(m_loc,(ILxUnknownID) vmodel);
    }

    auto SurfaceToViewObject(unsigned int type, ILxUnknownID item, void **ppvObj) -> LxResult
    {
        return m_loc[0]->SurfaceToViewObject(m_loc, type,(ILxUnknownID) item, ppvObj);
    }

    auto SurfaceToViewObject(unsigned int type, ILxUnknownID item, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->SurfaceToViewObject(m_loc, type,(ILxUnknownID) item, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto MeshToViewObject(unsigned int type, ILxUnknownID mesh, ILxUnknownID item, void **ppvObj) -> LxResult
    {
        return m_loc[0]->MeshToViewObject(m_loc, type,(ILxUnknownID) mesh,(ILxUnknownID) item, ppvObj);
    }

    auto MeshToViewObject(unsigned int type, ILxUnknownID mesh, ILxUnknownID item, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->MeshToViewObject(m_loc, type,(ILxUnknownID) mesh,(ILxUnknownID) item, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_SimulationListener : public CLxLocalize<ILxSimulationListenerID>
{
public:
    CLxLoc_SimulationListener()
    {
        _init();
    }

    CLxLoc_SimulationListener(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_SimulationListener(CLxLoc_SimulationListener const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_SimulationListener;
    }

    auto Start(ILxUnknownID channels) -> LxResult
    {
        return m_loc[0]->Start(m_loc,(ILxUnknownID) channels);
    }

    auto End(void) -> LxResult
    {
        return m_loc[0]->End(m_loc);
    }

    auto Time(double time) -> LxResult
    {
        return m_loc[0]->Time(m_loc, time);
    }

    auto Invalidate(void) -> LxResult
    {
        return m_loc[0]->Invalidate(m_loc);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
