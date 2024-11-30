//
// C++ wrapper for lxsdk/lxraycast.h.
//
//	Copyright 2024.
//
//
#pragma once

#include <lxraycast.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx
{
    static LXtGUID const guid_Raycast1 = {0x7B13E5D2, {0xD0D9, 0x427A}, {0xA1, 0xD4, 0x6D, 0xAE, 0xB1, 0x92, 0xB8, 0xB0}};
    static LXtGUID const guid_Raycast = {0x7E2C439F, {0x3B4D, 0x4C3A}, {0x9B, 0x4A, 0x18, 0x30, 0x7E, 0xF9, 0xFC, 0x36}};
    static LXtGUID const guid_Lighting = {0x2F6C2A6C, {0x68AF, 0x4E58}, {0xB5, 0x67, 0xA9, 0x2D, 0x5E, 0xB7, 0x32, 0xF4}};
} // namespace lx

class CLxLoc_Raycast1 : public CLxLocalize<ILxRaycast1ID>
{
public:
    CLxLoc_Raycast1()
    {
        _init();
    }

    CLxLoc_Raycast1(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_Raycast1(CLxLoc_Raycast1 const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_Raycast1;
    }

    auto RayPush(ILxUnknownID vector) -> ILxUnknownID
    {
        return m_loc[0]->RayPush(m_loc,(ILxUnknownID) vector);
    }

    auto RayPop(ILxUnknownID vector) -> LxResult
    {
        return m_loc[0]->RayPop(m_loc,(ILxUnknownID) vector);
    }

    auto Raycast(ILxUnknownID vector, const LXtVector pos, const LXtFVector dir) -> float
    {
        return m_loc[0]->Raycast(m_loc,(ILxUnknownID) vector, pos, dir);
    }

    auto Raytrace(ILxUnknownID vector, const LXtVector pos, const LXtFVector dir, int flags) -> float
    {
        return m_loc[0]->Raytrace(m_loc,(ILxUnknownID) vector, pos, dir, flags);
    }

    auto InternalShade(ILxUnknownID vector) -> LxResult
    {
        return m_loc[0]->InternalShade(m_loc,(ILxUnknownID) vector);
    }

    auto LightCount(ILxUnknownID vector) const -> int
    {
        return m_loc[0]->LightCount(m_loc,(ILxUnknownID) vector);
    }

    auto LightSampleCount(ILxUnknownID vector, const LXtVector pos, const LXtFVector nrm, int *num) -> LxResult
    {
        return m_loc[0]->LightSampleCount(m_loc,(ILxUnknownID) vector, pos, nrm, num);
    }

    auto LightShadowType(ILxUnknownID vector, int lgtIndex) const -> int
    {
        return m_loc[0]->LightShadowType(m_loc,(ILxUnknownID) vector, lgtIndex);
    }

    auto LightSampleCountByLight(ILxUnknownID vector, int lgtIndex) const -> int
    {
        return m_loc[0]->LightSampleCountByLight(m_loc,(ILxUnknownID) vector, lgtIndex);
    }

    auto LightSampleByIndex(ILxUnknownID vector, int index, LXpLightColor *lCol, float *dot) -> LxResult
    {
        return m_loc[0]->LightSampleByIndex(m_loc,(ILxUnknownID) vector, index, lCol, dot);
    }

    auto LightValue(ILxUnknownID vector, int lgtIndex, LXtFVector *color, float *intensity) -> LxResult
    {
        return m_loc[0]->LightValue(m_loc,(ILxUnknownID) vector, lgtIndex, color, intensity);
    }

    auto GetNextShadowRay(ILxUnknownID vector, int lgtIndex, LXtVector pos, LXtFVector *dir, int *flags) -> LxResult
    {
        return m_loc[0]->GetNextShadowRay(m_loc,(ILxUnknownID) vector, lgtIndex, pos, dir, flags);
    }

    auto GetNextGIRaySphere(ILxUnknownID vector, LXtFVector *dir, int *flags) -> LxResult
    {
        return m_loc[0]->GetNextGIRaySphere(m_loc,(ILxUnknownID) vector, dir, flags);
    }

    auto GetNextGIRayHemisphere(ILxUnknownID vector, LXtFVector *dir, int *flags) -> LxResult
    {
        return m_loc[0]->GetNextGIRayHemisphere(m_loc,(ILxUnknownID) vector, dir, flags);
    }

    auto GetSurfaceID(ILxUnknownID vector, void **id) -> LxResult
    {
        return m_loc[0]->GetSurfaceID(m_loc,(ILxUnknownID) vector, id);
    }

    auto PixelToRay(ILxUnknownID vector, int mode, float x, float y, LXpSampleRay *sRay) -> LxResult
    {
        return m_loc[0]->PixelToRay(m_loc,(ILxUnknownID) vector, mode, x, y, sRay);
    }

    auto PixelGeometry(ILxUnknownID vector, int mode, float x, float y, LXpPixelGeometry *pGeo) -> LxResult
    {
        return m_loc[0]->PixelGeometry(m_loc,(ILxUnknownID) vector, mode, x, y, pGeo);
    }

    auto PoissonOffset(ILxUnknownID vector, float *u, float *v) -> LxResult
    {
        return m_loc[0]->PoissonOffset(m_loc,(ILxUnknownID) vector, u, v);
    }

    auto Irradiance(ILxUnknownID vector, const LXtVector pos, const LXtFVector nrm, LXtFVector lum) -> LxResult
    {
        return m_loc[0]->Irradiance(m_loc,(ILxUnknownID) vector, pos, nrm, lum);
    }

    auto GetBucketGlobalBounce(ILxUnknownID vector, int *globBounce) -> LxResult
    {
        return m_loc[0]->GetBucketGlobalBounce(m_loc,(ILxUnknownID) vector, globBounce);
    }

    auto GetBucketPixel(ILxUnknownID vector, int *x, int *y) -> LxResult
    {
        return m_loc[0]->GetBucketPixel(m_loc,(ILxUnknownID) vector, x, y);
    }

    auto GetBucketSubPixel(ILxUnknownID vector, float *x, float *y) -> LxResult
    {
        return m_loc[0]->GetBucketSubPixel(m_loc,(ILxUnknownID) vector, x, y);
    }

    auto GetBucketTimeOffset(ILxUnknownID vector, float *tOffset) -> LxResult
    {
        return m_loc[0]->GetBucketTimeOffset(m_loc,(ILxUnknownID) vector, tOffset);
    }

    auto GetSurfaceType(ILxUnknownID vector) -> int
    {
        return m_loc[0]->GetSurfaceType(m_loc,(ILxUnknownID) vector);
    }

    auto GetLightSampleDirection(ILxUnknownID vector, int lgtIndex, LXtVector pos, LXtFVector *dir) -> LxResult
    {
        return m_loc[0]->GetLightSampleDirection(m_loc,(ILxUnknownID) vector, lgtIndex, pos, dir);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_Raycast : public CLxLocalize<ILxRaycastID>
{
public:
    CLxLoc_Raycast()
    {
        _init();
    }

    CLxLoc_Raycast(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_Raycast(CLxLoc_Raycast const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_Raycast;
    }

    auto RayPush(ILxUnknownID vector) -> ILxUnknownID
    {
        return m_loc[0]->RayPush(m_loc,(ILxUnknownID) vector);
    }

    auto RayPop(ILxUnknownID vector) -> LxResult
    {
        return m_loc[0]->RayPop(m_loc,(ILxUnknownID) vector);
    }

    auto Raycast(ILxUnknownID vector, const LXtVector pos, const LXtFVector dir) -> float
    {
        return m_loc[0]->Raycast(m_loc,(ILxUnknownID) vector, pos, dir);
    }

    auto Raytrace(ILxUnknownID vector, const LXtVector pos, const LXtFVector dir, int flags) -> float
    {
        return m_loc[0]->Raytrace(m_loc,(ILxUnknownID) vector, pos, dir, flags);
    }

    auto InternalShade(ILxUnknownID vector) -> LxResult
    {
        return m_loc[0]->InternalShade(m_loc,(ILxUnknownID) vector);
    }

    auto GetSurfaceID(ILxUnknownID vector, void **id) -> LxResult
    {
        return m_loc[0]->GetSurfaceID(m_loc,(ILxUnknownID) vector, id);
    }

    auto GetSurfaceType(ILxUnknownID vector) -> int
    {
        return m_loc[0]->GetSurfaceType(m_loc,(ILxUnknownID) vector);
    }

    auto PixelToRay(ILxUnknownID vector, int mode, float x, float y, LXpSampleRay *sRay) -> LxResult
    {
        return m_loc[0]->PixelToRay(m_loc,(ILxUnknownID) vector, mode, x, y, sRay);
    }

    auto PixelGeometry(ILxUnknownID vector, int mode, float x, float y, LXpPixelGeometry *pGeo) -> LxResult
    {
        return m_loc[0]->PixelGeometry(m_loc,(ILxUnknownID) vector, mode, x, y, pGeo);
    }

    auto PixelGeometrySeg(ILxUnknownID vector, int mode, float x, float y, LXpPixelGeometrySeg *pGeo) -> LxResult
    {
        return m_loc[0]->PixelGeometrySeg(m_loc,(ILxUnknownID) vector, mode, x, y, pGeo);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_Lighting : public CLxLocalize<ILxLightingID>
{
public:
    CLxLoc_Lighting()
    {
        _init();
    }

    CLxLoc_Lighting(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_Lighting(CLxLoc_Lighting const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_Lighting;
    }

    auto LightSourceCount(ILxUnknownID vector, int *num) -> LxResult
    {
        return m_loc[0]->LightSourceCount(m_loc,(ILxUnknownID) vector, num);
    }

    auto LightSourceByIndex(ILxUnknownID vector, int index, LXpLightSource *lSrc) -> LxResult
    {
        return m_loc[0]->LightSourceByIndex(m_loc,(ILxUnknownID) vector, index, lSrc);
    }

    auto LightSourceEvaluate(ILxUnknownID vector, const LXpLightSource *lSrc, LXtFVector lum) -> LxResult
    {
        return m_loc[0]->LightSourceEvaluate(m_loc,(ILxUnknownID) vector, lSrc, lum);
    }

    auto EnvironmentEvaluate(ILxUnknownID vector, int samples, int flags, LXtFVector lum) -> LxResult
    {
        return m_loc[0]->EnvironmentEvaluate(m_loc,(ILxUnknownID) vector, samples, flags, lum);
    }

    auto GIRequired(ILxUnknownID vector) -> int
    {
        return m_loc[0]->GIRequired(m_loc,(ILxUnknownID) vector);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
