//
// C++ wrapper for lxsdk/lxrendercache.h.
//
//	Copyright 2024.
//
//
#pragma once

#include <lxrendercache.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx
{
    static LXtGUID const guid_RenderCacheService = {0x138FF638, {0x1E34, 0x4CC6}, {0xBA, 0xFC, 0x4F, 0x73, 0x49, 0x69, 0xF4, 0x7E}};
    static LXtGUID const guid_RenderCache = {0x1ED14AD3, {0xB202, 0x46FF}, {0xA7, 0x20, 0xA1, 0xDC, 0xFC, 0x0B, 0x89, 0x3A}};
    static LXtGUID const guid_RenderCacheListener1 = {0xE1EBCD71, {0xB28A, 0x42FB}, {0x9A, 0xF7, 0xFA, 0xDA, 0x18, 0xFE, 0xBF, 0xC6}};
    static LXtGUID const guid_RenderCacheListener = {0xBBF6E7B5, {0xC59D, 0x45D2}, {0x97, 0xE6, 0xF4, 0x95, 0x92, 0xA7, 0xEA, 0x6A}};
    static LXtGUID const guid_GeoCacheSegment = {0xCDA6EDAD, {0x8E71, 0x4EA9}, {0xA0, 0x5A, 0x32, 0x6C, 0xEA, 0xD7, 0xDE, 0x9B}};
    static LXtGUID const guid_GeoCacheSurface = {0x770BD566, {0x315B, 0x4EEC}, {0xA2, 0xA5, 0x26, 0x6D, 0x12, 0x2D, 0x8D, 0xDF}};
} // namespace lx

class CLxLoc_RenderCacheService : public CLxLocalizedService
{
public:
    ILxRenderCacheServiceID m_loc{ nullptr };

public:
    CLxLoc_RenderCacheService()
    {
        _init();
        set();
    }

    ~CLxLoc_RenderCacheService() = default;

    void set()
    {
        if (!m_loc)
        {
            m_loc = reinterpret_cast<ILxRenderCacheServiceID>(lx::GetGlobal(&lx::guid_RenderCacheService));
        }
    }

    auto CreateRenderCache(void **ppvObj, unsigned int createFlags) -> LxResult
    {
        return m_loc[0]->CreateRenderCache(m_loc, ppvObj, createFlags);
    }

    auto CreateRenderCache(CLxLocalizedObject &o_dest, unsigned int createFlags) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->CreateRenderCache(m_loc, &o_obj, createFlags);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_RenderCache : public CLxLocalize<ILxRenderCacheID>
{
public:
    CLxLoc_RenderCache()
    {
        _init();
    }

    CLxLoc_RenderCache(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_RenderCache(CLxLoc_RenderCache const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_RenderCache;
    }

    auto Time(double *time, double *timeOffsets) -> void
    {
        m_loc[0]->Time(m_loc, time, timeOffsets);
    }

    auto Update(double time, int force) -> LxResult
    {
        return m_loc[0]->Update(m_loc, time, force);
    }

    auto Clear(void) -> void
    {
        m_loc[0]->Clear(m_loc);
    }

    auto GeoSurfaceCount(int *count) -> LxResult
    {
        return m_loc[0]->GeoSurfaceCount(m_loc, count);
    }

    auto GeoSurfaceAt(int index, void **srf) -> LxResult
    {
        return m_loc[0]->GeoSurfaceAt(m_loc, index, srf);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};

class CLxImpl_RenderCacheListener
{
public:
    virtual ~CLxImpl_RenderCacheListener() = default;

    virtual void rli_RenderCacheDestroy([[maybe_unused]] void)
    {
    }

    virtual void rli_UpdateBegin([[maybe_unused]] void)
    {
    }

    virtual void rli_UpdateEnd([[maybe_unused]] void)
    {
    }

    virtual void rli_GeoCacheSurfaceAdd([[maybe_unused]] ILxUnknownID geoSrf)
    {
    }

    virtual void rli_GeoCacheSurfaceRemove([[maybe_unused]] ILxUnknownID geoSrf)
    {
    }

    virtual void rli_GeoCacheSurfaceGeoUpdate([[maybe_unused]] ILxUnknownID geoSrf)
    {
    }

    virtual void rli_GeoCacheSurfaceXformUpdate([[maybe_unused]] ILxUnknownID geoSrf)
    {
    }

    virtual void rli_GeoCacheSurfaceShaderUpdate([[maybe_unused]] ILxUnknownID geoSrf)
    {
    }

    virtual void rli_RenderCacheClear([[maybe_unused]] void)
    {
    }
};

#define LXxD_RenderCacheListener_RenderCacheDestroy void rli_RenderCacheDestroy() override
#define LXxO_RenderCacheListener_RenderCacheDestroy LXxD_RenderCacheListener_RenderCacheDestroy
#define LXxC_RenderCacheListener_RenderCacheDestroy(c) void c::rli_RenderCacheDestroy()
#define LXxD_RenderCacheListener_UpdateBegin void rli_UpdateBegin() override
#define LXxO_RenderCacheListener_UpdateBegin LXxD_RenderCacheListener_UpdateBegin
#define LXxC_RenderCacheListener_UpdateBegin(c) void c::rli_UpdateBegin()
#define LXxD_RenderCacheListener_UpdateEnd void rli_UpdateEnd() override
#define LXxO_RenderCacheListener_UpdateEnd LXxD_RenderCacheListener_UpdateEnd
#define LXxC_RenderCacheListener_UpdateEnd(c) void c::rli_UpdateEnd()
#define LXxD_RenderCacheListener_GeoCacheSurfaceAdd void rli_GeoCacheSurfaceAdd([[maybe_unused]] ILxUnknownID geoSrf) override
#define LXxO_RenderCacheListener_GeoCacheSurfaceAdd LXxD_RenderCacheListener_GeoCacheSurfaceAdd
#define LXxC_RenderCacheListener_GeoCacheSurfaceAdd(c) void c::rli_GeoCacheSurfaceAdd([[maybe_unused]] ILxUnknownID geoSrf)
#define LXxD_RenderCacheListener_GeoCacheSurfaceRemove void rli_GeoCacheSurfaceRemove([[maybe_unused]] ILxUnknownID geoSrf) override
#define LXxO_RenderCacheListener_GeoCacheSurfaceRemove LXxD_RenderCacheListener_GeoCacheSurfaceRemove
#define LXxC_RenderCacheListener_GeoCacheSurfaceRemove(c) void c::rli_GeoCacheSurfaceRemove([[maybe_unused]] ILxUnknownID geoSrf)
#define LXxD_RenderCacheListener_GeoCacheSurfaceGeoUpdate void rli_GeoCacheSurfaceGeoUpdate([[maybe_unused]] ILxUnknownID geoSrf) override
#define LXxO_RenderCacheListener_GeoCacheSurfaceGeoUpdate LXxD_RenderCacheListener_GeoCacheSurfaceGeoUpdate
#define LXxC_RenderCacheListener_GeoCacheSurfaceGeoUpdate(c) void c::rli_GeoCacheSurfaceGeoUpdate([[maybe_unused]] ILxUnknownID geoSrf)
#define LXxD_RenderCacheListener_GeoCacheSurfaceXformUpdate void rli_GeoCacheSurfaceXformUpdate([[maybe_unused]] ILxUnknownID geoSrf) override
#define LXxO_RenderCacheListener_GeoCacheSurfaceXformUpdate LXxD_RenderCacheListener_GeoCacheSurfaceXformUpdate
#define LXxC_RenderCacheListener_GeoCacheSurfaceXformUpdate(c) void c::rli_GeoCacheSurfaceXformUpdate([[maybe_unused]] ILxUnknownID geoSrf)
#define LXxD_RenderCacheListener_GeoCacheSurfaceShaderUpdate void rli_GeoCacheSurfaceShaderUpdate([[maybe_unused]] ILxUnknownID geoSrf) override
#define LXxO_RenderCacheListener_GeoCacheSurfaceShaderUpdate LXxD_RenderCacheListener_GeoCacheSurfaceShaderUpdate
#define LXxC_RenderCacheListener_GeoCacheSurfaceShaderUpdate(c) void c::rli_GeoCacheSurfaceShaderUpdate([[maybe_unused]] ILxUnknownID geoSrf)
#define LXxD_RenderCacheListener_RenderCacheClear void rli_RenderCacheClear() override
#define LXxO_RenderCacheListener_RenderCacheClear LXxD_RenderCacheListener_RenderCacheClear
#define LXxC_RenderCacheListener_RenderCacheClear(c) void c::rli_RenderCacheClear()

template <class T>
class CLxIfc_RenderCacheListener: public CLxInterface
{
public:
    CLxIfc_RenderCacheListener()
    {
        vt.RenderCacheDestroy = RenderCacheDestroy;
        vt.UpdateBegin = UpdateBegin;
        vt.UpdateEnd = UpdateEnd;
        vt.GeoCacheSurfaceAdd = GeoCacheSurfaceAdd;
        vt.GeoCacheSurfaceRemove = GeoCacheSurfaceRemove;
        vt.GeoCacheSurfaceGeoUpdate = GeoCacheSurfaceGeoUpdate;
        vt.GeoCacheSurfaceXformUpdate = GeoCacheSurfaceXformUpdate;
        vt.GeoCacheSurfaceShaderUpdate = GeoCacheSurfaceShaderUpdate;
        vt.RenderCacheClear = RenderCacheClear;
        vTable = &vt.iunk;
        iid = &lx::guid_RenderCacheListener;
    }

    static auto RenderCacheDestroy(LXtObjectID wcom) -> void
    {
        LXCWxINST (CLxImpl_RenderCacheListener, loc);
        loc->rli_RenderCacheDestroy();
    }

    static auto UpdateBegin(LXtObjectID wcom) -> void
    {
        LXCWxINST (CLxImpl_RenderCacheListener, loc);
        loc->rli_UpdateBegin();
    }

    static auto UpdateEnd(LXtObjectID wcom) -> void
    {
        LXCWxINST (CLxImpl_RenderCacheListener, loc);
        loc->rli_UpdateEnd();
    }

    static auto GeoCacheSurfaceAdd(LXtObjectID wcom,LXtObjectID geoSrf) -> void
    {
        LXCWxINST (CLxImpl_RenderCacheListener, loc);
        loc->rli_GeoCacheSurfaceAdd((ILxUnknownID) geoSrf);
    }

    static auto GeoCacheSurfaceRemove(LXtObjectID wcom,LXtObjectID geoSrf) -> void
    {
        LXCWxINST (CLxImpl_RenderCacheListener, loc);
        loc->rli_GeoCacheSurfaceRemove((ILxUnknownID) geoSrf);
    }

    static auto GeoCacheSurfaceGeoUpdate(LXtObjectID wcom,LXtObjectID geoSrf) -> void
    {
        LXCWxINST (CLxImpl_RenderCacheListener, loc);
        loc->rli_GeoCacheSurfaceGeoUpdate((ILxUnknownID) geoSrf);
    }

    static auto GeoCacheSurfaceXformUpdate(LXtObjectID wcom,LXtObjectID geoSrf) -> void
    {
        LXCWxINST (CLxImpl_RenderCacheListener, loc);
        loc->rli_GeoCacheSurfaceXformUpdate((ILxUnknownID) geoSrf);
    }

    static auto GeoCacheSurfaceShaderUpdate(LXtObjectID wcom,LXtObjectID geoSrf) -> void
    {
        LXCWxINST (CLxImpl_RenderCacheListener, loc);
        loc->rli_GeoCacheSurfaceShaderUpdate((ILxUnknownID) geoSrf);
    }

    static auto RenderCacheClear(LXtObjectID wcom) -> void
    {
        LXCWxINST (CLxImpl_RenderCacheListener, loc);
        loc->rli_RenderCacheClear();
    }

private:
    ILxRenderCacheListener vt;
};


class CLxLoc_GeoCacheSegment : public CLxLocalize<ILxGeoCacheSegmentID>
{
public:
    CLxLoc_GeoCacheSegment()
    {
        _init();
    }

    CLxLoc_GeoCacheSegment(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_GeoCacheSegment(CLxLoc_GeoCacheSegment const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_GeoCacheSegment;
    }

    auto GetBBox(LXtBBox *bbox) -> LxResult
    {
        return m_loc[0]->GetBBox(m_loc, bbox);
    }

    auto PolygonCount(int *count) -> void
    {
        m_loc[0]->PolygonCount(m_loc, count);
    }

    auto VertexCount(int *count) -> void
    {
        m_loc[0]->VertexCount(m_loc, count);
    }

    auto VertsPerPoly(int *count) -> void
    {
        m_loc[0]->VertsPerPoly(m_loc, count);
    }

    auto VertexFeatureCount(int feature, int *count) -> void
    {
        m_loc[0]->VertexFeatureCount(m_loc, feature, count);
    }

    auto GetPolygonVertexFeature(int feature, void *featureData, int count, int start) -> LxResult
    {
        return m_loc[0]->GetPolygonVertexFeature(m_loc, feature, featureData, count, start);
    }

    auto GetVertexFeature(int feature, void *featureData, int count, int start) -> LxResult
    {
        return m_loc[0]->GetVertexFeature(m_loc, feature, featureData, count, start);
    }

    auto GetPolygonVertexInds(int *polyVertexInds, int count, int start) -> LxResult
    {
        return m_loc[0]->GetPolygonVertexInds(m_loc, polyVertexInds, count, start);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_GeoCacheSurface : public CLxLocalize<ILxGeoCacheSurfaceID>
{
public:
    CLxLoc_GeoCacheSurface()
    {
        _init();
    }

    CLxLoc_GeoCacheSurface(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_GeoCacheSurface(CLxLoc_GeoCacheSurface const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_GeoCacheSurface;
    }

    auto ShaderMaskName(const char **name) -> LxResult
    {
        return m_loc[0]->ShaderMaskName(m_loc, name);
    }

    auto ShaderMaskType(void) -> int
    {
        return m_loc[0]->ShaderMaskType(m_loc);
    }

    auto SourceItem(void **ppvObj) -> LxResult
    {
        return m_loc[0]->SourceItem(m_loc, ppvObj);
    }

    auto SourceItem(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->SourceItem(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto IsInstanced(void) -> int
    {
        return m_loc[0]->IsInstanced(m_loc);
    }

    auto InstanceIndex(void) -> int
    {
        return m_loc[0]->InstanceIndex(m_loc);
    }

    auto SourceSurface(void **ppvObj) -> LxResult
    {
        return m_loc[0]->SourceSurface(m_loc, ppvObj);
    }

    auto SourceSurface(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->SourceSurface(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto GetBBox(LXtBBox *bbox) -> LxResult
    {
        return m_loc[0]->GetBBox(m_loc, bbox);
    }

    auto GetXfrm(LXtVector pos, LXtMatrix rot, LXtVector scl, int endpoint) -> LxResult
    {
        return m_loc[0]->GetXfrm(m_loc, pos, rot, scl, endpoint);
    }

    auto SegmentCount(int *count) -> void
    {
        m_loc[0]->SegmentCount(m_loc, count);
    }

    auto PolygonCount(int *count) -> void
    {
        m_loc[0]->PolygonCount(m_loc, count);
    }

    auto VertexCount(int *count) -> void
    {
        m_loc[0]->VertexCount(m_loc, count);
    }

    auto SegmentAt(int index, void **segment) -> LxResult
    {
        return m_loc[0]->SegmentAt(m_loc, index, segment);
    }

    auto VisibilityFlags(LXtGeoCacheSrfVisibility *flags) -> LxResult
    {
        return m_loc[0]->VisibilityFlags(m_loc, flags);
    }

    auto ID(void) -> int
    {
        return m_loc[0]->ID(m_loc);
    }

    auto IsValid(void) -> int
    {
        return m_loc[0]->IsValid(m_loc);
    }

    auto LoadSegments(void) -> LxResult
    {
        return m_loc[0]->LoadSegments(m_loc);
    }

    auto UnloadSegments(void) -> LxResult
    {
        return m_loc[0]->UnloadSegments(m_loc);
    }

    auto GetVertexDesc(void) -> ILxTableauVertexID
    {
        return m_loc[0]->GetVertexDesc(m_loc);
    }

    auto MaterialPTag(void) -> const char*
    {
        return m_loc[0]->MaterialPTag(m_loc);
    }

    auto PartPTag(void) -> const char*
    {
        return m_loc[0]->PartPTag(m_loc);
    }

    auto PickPTag(void) -> const char*
    {
        return m_loc[0]->PickPTag(m_loc);
    }

    auto ShaderLayerCount(unsigned int *count) -> LxResult
    {
        return m_loc[0]->ShaderLayerCount(m_loc, count);
    }

    auto ShaderLayerAt(unsigned int index, void **shaderLayer) -> LxResult
    {
        return m_loc[0]->ShaderLayerAt(m_loc, index, shaderLayer);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
