//
// C++ wrapper for lxsdk/lxcolor.h.
//
//	Copyright 2024.
//
//
#pragma once

#include <lxcolor.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx
{
    static LXtGUID const guid_ColorModel = {0x67d3d952, {0x4ab0, 0x49e5}, {0x8f, 0x9e, 0x6c, 0x88, 0x9b, 0x00, 0xf2, 0x53}};
    static LXtGUID const guid_Color = {0x7c084df3, {0xadb6, 0x48ee}, {0x92, 0xd3, 0x03, 0x2d, 0x90, 0xef, 0xea, 0x05}};
} // namespace lx

class CLxImpl_ColorModel
{
public:
    virtual ~CLxImpl_ColorModel() = default;

    virtual int colm_NumComponents(void) = 0;

    virtual auto colm_ComponentType([[maybe_unused]] unsigned component, [[maybe_unused]] const char **type) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto colm_ComponentRange([[maybe_unused]] unsigned component, [[maybe_unused]] float *min, [[maybe_unused]] float *max) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto colm_ToRGB([[maybe_unused]] const float *vector, [[maybe_unused]] float *rgb) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto colm_FromRGB([[maybe_unused]] const float *rgb, [[maybe_unused]] float *vector) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto colm_DrawSlice([[maybe_unused]] ILxUnknownID image, [[maybe_unused]] unsigned xAxis, [[maybe_unused]] unsigned yAxis, [[maybe_unused]] const float *vec) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto colm_DrawSliceMarker([[maybe_unused]] ILxUnknownID image, [[maybe_unused]] unsigned xAxis, [[maybe_unused]] unsigned yAxis, [[maybe_unused]] const float *downVec, [[maybe_unused]] const float *vec) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto colm_CanSliceBeReused([[maybe_unused]] unsigned xAxis, [[maybe_unused]] unsigned yAxis, [[maybe_unused]] const float *oldVec, [[maybe_unused]] const float *newVec) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto colm_ToSlicePos([[maybe_unused]] unsigned xAxis, [[maybe_unused]] unsigned yAxis, [[maybe_unused]] unsigned imgW, [[maybe_unused]] unsigned imgH, [[maybe_unused]] const float *vec, [[maybe_unused]] unsigned *imgX, [[maybe_unused]] unsigned *imgY) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto colm_FromSlicePos([[maybe_unused]] unsigned xAxis, [[maybe_unused]] unsigned yAxis, [[maybe_unused]] unsigned imgW, [[maybe_unused]] unsigned imgH, [[maybe_unused]] unsigned imgX, [[maybe_unused]] unsigned imgY, [[maybe_unused]] float *downVec, [[maybe_unused]] float *vec) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto colm_StripBaseVector([[maybe_unused]] unsigned axis, [[maybe_unused]] int dynamic, [[maybe_unused]] float *vec) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_ColorModel_NumComponents int colm_NumComponents() override
#define LXxO_ColorModel_NumComponents LXxD_ColorModel_NumComponents
#define LXxC_ColorModel_NumComponents(c) int c::colm_NumComponents()
#define LXxD_ColorModel_ComponentType LxResult colm_ComponentType([[maybe_unused]] unsigned component, [[maybe_unused]] const char **type) override
#define LXxO_ColorModel_ComponentType LXxD_ColorModel_ComponentType
#define LXxC_ColorModel_ComponentType(c) LxResult c::colm_ComponentType([[maybe_unused]] unsigned component, [[maybe_unused]] const char **type)
#define LXxD_ColorModel_ComponentRange LxResult colm_ComponentRange([[maybe_unused]] unsigned component, [[maybe_unused]] float *min, [[maybe_unused]] float *max) override
#define LXxO_ColorModel_ComponentRange LXxD_ColorModel_ComponentRange
#define LXxC_ColorModel_ComponentRange(c) LxResult c::colm_ComponentRange([[maybe_unused]] unsigned component, [[maybe_unused]] float *min, [[maybe_unused]] float *max)
#define LXxD_ColorModel_ToRGB LxResult colm_ToRGB([[maybe_unused]] const float *vector, [[maybe_unused]] float *rgb) override
#define LXxO_ColorModel_ToRGB LXxD_ColorModel_ToRGB
#define LXxC_ColorModel_ToRGB(c) LxResult c::colm_ToRGB([[maybe_unused]] const float *vector, [[maybe_unused]] float *rgb)
#define LXxD_ColorModel_FromRGB LxResult colm_FromRGB([[maybe_unused]] const float *rgb, [[maybe_unused]] float *vector) override
#define LXxO_ColorModel_FromRGB LXxD_ColorModel_FromRGB
#define LXxC_ColorModel_FromRGB(c) LxResult c::colm_FromRGB([[maybe_unused]] const float *rgb, [[maybe_unused]] float *vector)
#define LXxD_ColorModel_DrawSlice LxResult colm_DrawSlice([[maybe_unused]] ILxUnknownID image, [[maybe_unused]] unsigned xAxis, [[maybe_unused]] unsigned yAxis, [[maybe_unused]] const float *vec) override
#define LXxO_ColorModel_DrawSlice LXxD_ColorModel_DrawSlice
#define LXxC_ColorModel_DrawSlice(c) LxResult c::colm_DrawSlice([[maybe_unused]] ILxUnknownID image, [[maybe_unused]] unsigned xAxis, [[maybe_unused]] unsigned yAxis, [[maybe_unused]] const float *vec)
#define LXxD_ColorModel_DrawSliceMarker LxResult colm_DrawSliceMarker([[maybe_unused]] ILxUnknownID image, [[maybe_unused]] unsigned xAxis, [[maybe_unused]] unsigned yAxis, [[maybe_unused]] const float *downVec, [[maybe_unused]] const float *vec) override
#define LXxO_ColorModel_DrawSliceMarker LXxD_ColorModel_DrawSliceMarker
#define LXxC_ColorModel_DrawSliceMarker(c) LxResult c::colm_DrawSliceMarker([[maybe_unused]] ILxUnknownID image, [[maybe_unused]] unsigned xAxis, [[maybe_unused]] unsigned yAxis, [[maybe_unused]] const float *downVec, [[maybe_unused]] const float *vec)
#define LXxD_ColorModel_CanSliceBeReused LxResult colm_CanSliceBeReused([[maybe_unused]] unsigned xAxis, [[maybe_unused]] unsigned yAxis, [[maybe_unused]] const float *oldVec, [[maybe_unused]] const float *newVec) override
#define LXxO_ColorModel_CanSliceBeReused LXxD_ColorModel_CanSliceBeReused
#define LXxC_ColorModel_CanSliceBeReused(c) LxResult c::colm_CanSliceBeReused([[maybe_unused]] unsigned xAxis, [[maybe_unused]] unsigned yAxis, [[maybe_unused]] const float *oldVec, [[maybe_unused]] const float *newVec)
#define LXxD_ColorModel_ToSlicePos LxResult colm_ToSlicePos([[maybe_unused]] unsigned xAxis, [[maybe_unused]] unsigned yAxis, [[maybe_unused]] unsigned imgW, [[maybe_unused]] unsigned imgH, [[maybe_unused]] const float *vec, [[maybe_unused]] unsigned *imgX, [[maybe_unused]] unsigned *imgY) override
#define LXxO_ColorModel_ToSlicePos LXxD_ColorModel_ToSlicePos
#define LXxC_ColorModel_ToSlicePos(c) LxResult c::colm_ToSlicePos([[maybe_unused]] unsigned xAxis, [[maybe_unused]] unsigned yAxis, [[maybe_unused]] unsigned imgW, [[maybe_unused]] unsigned imgH, [[maybe_unused]] const float *vec, [[maybe_unused]] unsigned *imgX, [[maybe_unused]] unsigned *imgY)
#define LXxD_ColorModel_FromSlicePos LxResult colm_FromSlicePos([[maybe_unused]] unsigned xAxis, [[maybe_unused]] unsigned yAxis, [[maybe_unused]] unsigned imgW, [[maybe_unused]] unsigned imgH, [[maybe_unused]] unsigned imgX, [[maybe_unused]] unsigned imgY, [[maybe_unused]] float *downVec, [[maybe_unused]] float *vec) override
#define LXxO_ColorModel_FromSlicePos LXxD_ColorModel_FromSlicePos
#define LXxC_ColorModel_FromSlicePos(c) LxResult c::colm_FromSlicePos([[maybe_unused]] unsigned xAxis, [[maybe_unused]] unsigned yAxis, [[maybe_unused]] unsigned imgW, [[maybe_unused]] unsigned imgH, [[maybe_unused]] unsigned imgX, [[maybe_unused]] unsigned imgY, [[maybe_unused]] float *downVec, [[maybe_unused]] float *vec)
#define LXxD_ColorModel_StripBaseVector LxResult colm_StripBaseVector([[maybe_unused]] unsigned axis, [[maybe_unused]] int dynamic, [[maybe_unused]] float *vec) override
#define LXxO_ColorModel_StripBaseVector LXxD_ColorModel_StripBaseVector
#define LXxC_ColorModel_StripBaseVector(c) LxResult c::colm_StripBaseVector([[maybe_unused]] unsigned axis, [[maybe_unused]] int dynamic, [[maybe_unused]] float *vec)

template <class T>
class CLxIfc_ColorModel: public CLxInterface
{
public:
    CLxIfc_ColorModel()
    {
        vt.NumComponents = NumComponents;
        vt.ComponentType = ComponentType;
        vt.ComponentRange = ComponentRange;
        vt.ToRGB = ToRGB;
        vt.FromRGB = FromRGB;
        vt.DrawSlice = DrawSlice;
        vt.DrawSliceMarker = DrawSliceMarker;
        vt.CanSliceBeReused = CanSliceBeReused;
        vt.ToSlicePos = ToSlicePos;
        vt.FromSlicePos = FromSlicePos;
        vt.StripBaseVector = StripBaseVector;
        vTable = &vt.iunk;
        iid = &lx::guid_ColorModel;
    }

    static auto NumComponents(LXtObjectID wcom) -> int
    {
        LXCWxINST (CLxImpl_ColorModel, loc);
        return loc->colm_NumComponents();
    }

    static auto ComponentType(LXtObjectID wcom,unsigned component,const char **type) -> LxResult
    {
        LXCWxINST (CLxImpl_ColorModel, loc);
        try
        {
           return loc->colm_ComponentType( component, type);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ComponentRange(LXtObjectID wcom,unsigned component,float *min,float *max) -> LxResult
    {
        LXCWxINST (CLxImpl_ColorModel, loc);
        try
        {
           return loc->colm_ComponentRange( component, min, max);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ToRGB(LXtObjectID wcom,const float *vector,float *rgb) -> LxResult
    {
        LXCWxINST (CLxImpl_ColorModel, loc);
        try
        {
           return loc->colm_ToRGB( vector, rgb);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto FromRGB(LXtObjectID wcom,const float *rgb,float *vector) -> LxResult
    {
        LXCWxINST (CLxImpl_ColorModel, loc);
        try
        {
           return loc->colm_FromRGB( rgb, vector);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto DrawSlice(LXtObjectID wcom,LXtObjectID image,unsigned xAxis,unsigned yAxis,const float *vec) -> LxResult
    {
        LXCWxINST (CLxImpl_ColorModel, loc);
        try
        {
           return loc->colm_DrawSlice((ILxUnknownID) image, xAxis, yAxis, vec);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto DrawSliceMarker(LXtObjectID wcom,LXtObjectID image,unsigned xAxis,unsigned yAxis,const float *downVec,const float *vec) -> LxResult
    {
        LXCWxINST (CLxImpl_ColorModel, loc);
        try
        {
           return loc->colm_DrawSliceMarker((ILxUnknownID) image, xAxis, yAxis, downVec, vec);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto CanSliceBeReused(LXtObjectID wcom,unsigned xAxis,unsigned yAxis,const float *oldVec,const float *newVec) -> LxResult
    {
        LXCWxINST (CLxImpl_ColorModel, loc);
        try
        {
           return loc->colm_CanSliceBeReused( xAxis, yAxis, oldVec, newVec);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ToSlicePos(LXtObjectID wcom,unsigned xAxis,unsigned yAxis,unsigned imgW,unsigned imgH,const float *vec,unsigned *imgX,unsigned *imgY) -> LxResult
    {
        LXCWxINST (CLxImpl_ColorModel, loc);
        try
        {
           return loc->colm_ToSlicePos( xAxis, yAxis, imgW, imgH, vec, imgX, imgY);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto FromSlicePos(LXtObjectID wcom,unsigned xAxis,unsigned yAxis,unsigned imgW,unsigned imgH,unsigned imgX,unsigned imgY,float *downVec,float *vec) -> LxResult
    {
        LXCWxINST (CLxImpl_ColorModel, loc);
        try
        {
           return loc->colm_FromSlicePos( xAxis, yAxis, imgW, imgH, imgX, imgY, downVec, vec);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto StripBaseVector(LXtObjectID wcom,unsigned axis,int dynamic,float *vec) -> LxResult
    {
        LXCWxINST (CLxImpl_ColorModel, loc);
        try
        {
           return loc->colm_StripBaseVector( axis, dynamic, vec);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxColorModel vt;
};

class CLxLoc_ColorModel : public CLxLocalize<ILxColorModelID>
{
public:
    CLxLoc_ColorModel()
    {
        _init();
    }

    CLxLoc_ColorModel(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_ColorModel(CLxLoc_ColorModel const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_ColorModel;
    }

    auto NumComponents(void) -> int
    {
        return m_loc[0]->NumComponents(m_loc);
    }

    auto ComponentType(unsigned component, const char **type) -> LxResult
    {
        return m_loc[0]->ComponentType(m_loc, component, type);
    }

    auto ComponentRange(unsigned component, float *min, float *max) -> LxResult
    {
        return m_loc[0]->ComponentRange(m_loc, component, min, max);
    }

    auto ToRGB(const float *vector, float *rgb) -> LxResult
    {
        return m_loc[0]->ToRGB(m_loc, vector, rgb);
    }

    auto FromRGB(const float *rgb, float *vector) -> LxResult
    {
        return m_loc[0]->FromRGB(m_loc, rgb, vector);
    }

    auto DrawSlice(ILxUnknownID image, unsigned xAxis, unsigned yAxis, const float *vec) -> LxResult
    {
        return m_loc[0]->DrawSlice(m_loc,(ILxUnknownID) image, xAxis, yAxis, vec);
    }

    auto DrawSliceMarker(ILxUnknownID image, unsigned xAxis, unsigned yAxis, const float *downVec, const float *vec) -> LxResult
    {
        return m_loc[0]->DrawSliceMarker(m_loc,(ILxUnknownID) image, xAxis, yAxis, downVec, vec);
    }

    auto CanSliceBeReused(unsigned xAxis, unsigned yAxis, const float *oldVec, const float *newVec) -> LxResult
    {
        return m_loc[0]->CanSliceBeReused(m_loc, xAxis, yAxis, oldVec, newVec);
    }

    auto ToSlicePos(unsigned xAxis, unsigned yAxis, unsigned imgW, unsigned imgH, const float *vec, unsigned *imgX, unsigned *imgY) -> LxResult
    {
        return m_loc[0]->ToSlicePos(m_loc, xAxis, yAxis, imgW, imgH, vec, imgX, imgY);
    }

    auto FromSlicePos(unsigned xAxis, unsigned yAxis, unsigned imgW, unsigned imgH, unsigned imgX, unsigned imgY, float *downVec, float *vec) -> LxResult
    {
        return m_loc[0]->FromSlicePos(m_loc, xAxis, yAxis, imgW, imgH, imgX, imgY, downVec, vec);
    }

    auto StripBaseVector(unsigned axis, int dynamic, float *vec) -> LxResult
    {
        return m_loc[0]->StripBaseVector(m_loc, axis, dynamic, vec);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_Color
{
public:
    virtual ~CLxImpl_Color() = default;

    virtual auto color_Color([[maybe_unused]] float *color) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto color_Alpha([[maybe_unused]] float *alpha) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto color_ColorModel([[maybe_unused]] const char **model) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto color_ColorInModelSpace([[maybe_unused]] float *vec) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_Color_Color LxResult color_Color([[maybe_unused]] float *color) override
#define LXxO_Color_Color LXxD_Color_Color
#define LXxC_Color_Color(c) LxResult c::color_Color([[maybe_unused]] float *color)
#define LXxD_Color_Alpha LxResult color_Alpha([[maybe_unused]] float *alpha) override
#define LXxO_Color_Alpha LXxD_Color_Alpha
#define LXxC_Color_Alpha(c) LxResult c::color_Alpha([[maybe_unused]] float *alpha)
#define LXxD_Color_ColorModel LxResult color_ColorModel([[maybe_unused]] const char **model) override
#define LXxO_Color_ColorModel LXxD_Color_ColorModel
#define LXxC_Color_ColorModel(c) LxResult c::color_ColorModel([[maybe_unused]] const char **model)
#define LXxD_Color_ColorInModelSpace LxResult color_ColorInModelSpace([[maybe_unused]] float *vec) override
#define LXxO_Color_ColorInModelSpace LXxD_Color_ColorInModelSpace
#define LXxC_Color_ColorInModelSpace(c) LxResult c::color_ColorInModelSpace([[maybe_unused]] float *vec)

template <class T>
class CLxIfc_Color: public CLxInterface
{
public:
    CLxIfc_Color()
    {
        vt.Color = Color;
        vt.Alpha = Alpha;
        vt.ColorModel = ColorModel;
        vt.ColorInModelSpace = ColorInModelSpace;
        vTable = &vt.iunk;
        iid = &lx::guid_Color;
    }

    static auto Color(LXtObjectID wcom,float *color) -> LxResult
    {
        LXCWxINST (CLxImpl_Color, loc);
        try
        {
           return loc->color_Color( color);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Alpha(LXtObjectID wcom,float *alpha) -> LxResult
    {
        LXCWxINST (CLxImpl_Color, loc);
        try
        {
           return loc->color_Alpha( alpha);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ColorModel(LXtObjectID wcom,const char **model) -> LxResult
    {
        LXCWxINST (CLxImpl_Color, loc);
        try
        {
           return loc->color_ColorModel( model);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ColorInModelSpace(LXtObjectID wcom,float *vec) -> LxResult
    {
        LXCWxINST (CLxImpl_Color, loc);
        try
        {
           return loc->color_ColorInModelSpace( vec);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxColor vt;
};

class CLxLoc_Color : public CLxLocalize<ILxColorID>
{
public:
    CLxLoc_Color()
    {
        _init();
    }

    CLxLoc_Color(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_Color(CLxLoc_Color const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_Color;
    }

    auto Color(float *color) -> LxResult
    {
        return m_loc[0]->Color(m_loc, color);
    }

    auto Alpha(float *alpha) -> LxResult
    {
        return m_loc[0]->Alpha(m_loc, alpha);
    }

    auto ColorModel(const char **model) -> LxResult
    {
        return m_loc[0]->ColorModel(m_loc, model);
    }

    auto ColorInModelSpace(float *vec) -> LxResult
    {
        return m_loc[0]->ColorInModelSpace(m_loc, vec);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
