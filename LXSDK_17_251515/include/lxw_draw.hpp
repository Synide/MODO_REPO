//
// C++ wrapper for lxsdk/lxdraw.h.
//
//	Copyright 2024.
//
//
#pragma once

#include <lxdraw.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx
{
    static LXtGUID const guid_View = {0x7D171FD2, {0x20D5, 0x438C}, {0x86, 0x64, 0xAE, 0xCC, 0x2F, 0x82, 0x8B, 0x76}};
    static LXtGUID const guid_StrokeDraw = {0x8E7D34FC, {0x563A, 0x4C0D}, {0xAD, 0xDC, 0x2B, 0xFB, 0x2D, 0xDB, 0xF3, 0xE1}};
    static LXtGUID const guid_GLMaterial = {0x2AA53B64, {0x9EEF, 0x4504}, {0xBE, 0x1B, 0x64, 0x71, 0xA8, 0x34, 0x85, 0x3D}};
    static LXtGUID const guid_GLImage = {0xDA71480A, {0x95AA, 0x11D9}, {0x93, 0x6D, 0x00, 0x0A, 0x95, 0x6C, 0x2E, 0x10}};
} // namespace lx

class CLxLoc_View : public CLxLocalize<ILxViewID>
{
public:
    CLxLoc_View()
    {
        _init();
    }

    CLxLoc_View(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_View(CLxLoc_View const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_View;
    }

    auto Type(void) -> int
    {
        return m_loc[0]->Type(m_loc);
    }

    auto Center(LXtVector center) -> void
    {
        m_loc[0]->Center(m_loc, center);
    }

    auto Scale(void) -> double
    {
        return m_loc[0]->Scale(m_loc);
    }

    auto PixelScale(void) -> double
    {
        return m_loc[0]->PixelScale(m_loc);
    }

    auto Aspect(void) -> double
    {
        return m_loc[0]->Aspect(m_loc);
    }

    auto Matrix(LXtMatrix xfrm) -> void
    {
        m_loc[0]->Matrix(m_loc, xfrm);
    }

    auto InvMatrix(LXtMatrix xfrm) -> void
    {
        m_loc[0]->InvMatrix(m_loc, xfrm);
    }

    auto Ortho(int *index, int *spin) -> void
    {
        m_loc[0]->Ortho(m_loc, index, spin);
    }

    auto Axis(void) -> int
    {
        return m_loc[0]->Axis(m_loc);
    }

    auto Zoom(void) -> double
    {
        return m_loc[0]->Zoom(m_loc);
    }

    auto Focal(double *flen, double *fdist) -> void
    {
        m_loc[0]->Focal(m_loc, flen, fdist);
    }

    auto ToScreen(const LXtVector pos, double *x, double *y) -> int
    {
        return m_loc[0]->ToScreen(m_loc, pos, x, y);
    }

    auto ToScreen3(const LXtVector pos, LXtVector vp) -> int
    {
        return m_loc[0]->ToScreen3(m_loc, pos, vp);
    }

    auto ToModel(int x, int y, LXtVector pos, int snap) -> void
    {
        m_loc[0]->ToModel(m_loc, x, y, pos, snap);
    }

    auto ScreenNormals(const LXtVector pos, LXtVector ax, LXtVector ay, LXtVector az) -> void
    {
        m_loc[0]->ScreenNormals(m_loc, pos, ax, ay, az);
    }

    auto EyeVector(const LXtVector pos, LXtVector eye) -> double
    {
        return m_loc[0]->EyeVector(m_loc, pos, eye);
    }

    auto Dimensions(int *w, int *h) -> void
    {
        m_loc[0]->Dimensions(m_loc, w, h);
    }

    auto WorkPlane(LXtVector center) -> int
    {
        return m_loc[0]->WorkPlane(m_loc, center);
    }

    auto GridSize(void) -> double
    {
        return m_loc[0]->GridSize(m_loc);
    }

    auto GridSnap(void) -> double
    {
        return m_loc[0]->GridSnap(m_loc);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_StrokeDraw : public CLxLocalize<ILxStrokeDrawID>
{
public:
    CLxLoc_StrokeDraw()
    {
        _init();
    }

    CLxLoc_StrokeDraw(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_StrokeDraw(CLxLoc_StrokeDraw const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_StrokeDraw;
    }

    auto Begin(int type, const LXtVector color, double alpha) -> void
    {
        m_loc[0]->Begin(m_loc, type, color, alpha);
    }

    auto BeginW(int type, const LXtVector color, double alpha, double width) -> void
    {
        m_loc[0]->BeginW(m_loc, type, color, alpha, width);
    }

    auto BeginWD(int type, const LXtVector color, double alpha, double width, int dashPattern) -> void
    {
        m_loc[0]->BeginWD(m_loc, type, color, alpha, width, dashPattern);
    }

    auto Vertex(const LXtVector pos, int flags) -> void
    {
        m_loc[0]->Vertex(m_loc, pos, flags);
    }

    auto Vertex3(double x, double y, double z, int flags) -> void
    {
        m_loc[0]->Vertex3(m_loc, x, y, z, flags);
    }

    auto TextureUV(double u, double v) -> void
    {
        m_loc[0]->TextureUV(m_loc, u, v);
    }

    auto Text(const char *text, int just) -> void
    {
        m_loc[0]->Text(m_loc, text, just);
    }

    auto PushTransform(const LXtVector v, const LXtMatrix m) -> void
    {
        m_loc[0]->PushTransform(m_loc, v, m);
    }

    auto PopTransform(void) -> void
    {
        m_loc[0]->PopTransform(m_loc);
    }

    auto SetPart(int part) -> void
    {
        m_loc[0]->SetPart(m_loc, part);
    }

    auto BeginPoints(double size, const LXtVector color, double alpha) -> void
    {
        m_loc[0]->BeginPoints(m_loc, size, color, alpha);
    }

    auto Image(int texID, int just) -> void
    {
        m_loc[0]->Image(m_loc, texID, just);
    }

    auto BeginPolygons(int type, const LXtVector color, double alpha, double stip, double offsetX, double offsetY, int fill, int cull) -> void
    {
        m_loc[0]->BeginPolygons(m_loc, type, color, alpha, stip, offsetX, offsetY, fill, cull);
    }

    auto BeginI(ILxUnknownID texture, int type, const LXtVector color, double alpha) -> void
    {
        m_loc[0]->BeginI(m_loc,(ILxUnknownID) texture, type, color, alpha);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_GLMaterial : public CLxLocalize<ILxGLMaterialID>
{
public:
    CLxLoc_GLMaterial()
    {
        _init();
    }

    CLxLoc_GLMaterial(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_GLMaterial(CLxLoc_GLMaterial const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_GLMaterial;
    }

    auto Color(LXtFVector color) -> LxResult
    {
        return m_loc[0]->Color(m_loc, color);
    }

    auto Alpha(float *alpha) -> LxResult
    {
        return m_loc[0]->Alpha(m_loc, alpha);
    }

    auto DiffuseAmount(float *amount) -> LxResult
    {
        return m_loc[0]->DiffuseAmount(m_loc, amount);
    }

    auto DiffuseColor(LXtFVector color) -> LxResult
    {
        return m_loc[0]->DiffuseColor(m_loc, color);
    }

    auto SpecularAmount(float *amount) -> LxResult
    {
        return m_loc[0]->SpecularAmount(m_loc, amount);
    }

    auto SpecularColor(LXtFVector color) -> LxResult
    {
        return m_loc[0]->SpecularColor(m_loc, color);
    }

    auto LuminosityColor(LXtFVector color) -> LxResult
    {
        return m_loc[0]->LuminosityColor(m_loc, color);
    }

    auto Glossiness(float *amount) -> LxResult
    {
        return m_loc[0]->Glossiness(m_loc, amount);
    }

    auto ReflectionColor(LXtFVector color) -> LxResult
    {
        return m_loc[0]->ReflectionColor(m_loc, color);
    }

    auto TwoSide(int *value) -> LxResult
    {
        return m_loc[0]->TwoSide(m_loc, value);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_GLImage : public CLxLocalize<ILxGLImageID>
{
public:
    CLxLoc_GLImage()
    {
        _init();
    }

    CLxLoc_GLImage(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_GLImage(CLxLoc_GLImage const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_GLImage;
    }

    auto SetImage(ILxUnknownID image) -> LxResult
    {
        return m_loc[0]->SetImage(m_loc,(ILxUnknownID) image);
    }

    auto Size(double *w, double *h) -> LxResult
    {
        return m_loc[0]->Size(m_loc, w, h);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
