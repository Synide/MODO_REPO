//
// C++ wrapper for lxsdk/lxvolume.h.
//
//	Copyright 2024.
//
//
#pragma once

#include <lxvolume.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx
{
    static LXtGUID const guid_Raymarch = {0x1E84C5A8, {0xC002, 0x4120}, {0xBA, 0xB0, 0x9E, 0xEB, 0x17, 0x22, 0x68, 0x8B}};
    static LXtGUID const guid_Voxel = {0xA2B024D6, {0x4D03, 0x4FA0}, {0xB3, 0xCA, 0xA7, 0x94, 0x9D, 0x7F, 0x7B, 0x7A}};
} // namespace lx

class CLxImpl_Raymarch
{
public:
    virtual ~CLxImpl_Raymarch() = default;

    virtual auto rmrch_AddVolume([[maybe_unused]] ILxUnknownID vector, [[maybe_unused]] LXtVolumeSample *vs) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto rmrch_AddSurface([[maybe_unused]] ILxUnknownID vector, [[maybe_unused]] LXtSurfFragment *ss) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto rmrch_GetOpacity([[maybe_unused]] ILxUnknownID vector, [[maybe_unused]] double dist, [[maybe_unused]] double *opa) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto rmrch_ShaderEvaluate([[maybe_unused]] ILxUnknownID vector, [[maybe_unused]] ILxUnknownID shader) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto rmrch_Jitter1D([[maybe_unused]] ILxUnknownID vector, [[maybe_unused]] float *offset) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_Raymarch_AddVolume LxResult rmrch_AddVolume([[maybe_unused]] ILxUnknownID vector, [[maybe_unused]] LXtVolumeSample *vs) override
#define LXxO_Raymarch_AddVolume LXxD_Raymarch_AddVolume
#define LXxC_Raymarch_AddVolume(c) LxResult c::rmrch_AddVolume([[maybe_unused]] ILxUnknownID vector, [[maybe_unused]] LXtVolumeSample *vs)
#define LXxD_Raymarch_AddSurface LxResult rmrch_AddSurface([[maybe_unused]] ILxUnknownID vector, [[maybe_unused]] LXtSurfFragment *ss) override
#define LXxO_Raymarch_AddSurface LXxD_Raymarch_AddSurface
#define LXxC_Raymarch_AddSurface(c) LxResult c::rmrch_AddSurface([[maybe_unused]] ILxUnknownID vector, [[maybe_unused]] LXtSurfFragment *ss)
#define LXxD_Raymarch_GetOpacity LxResult rmrch_GetOpacity([[maybe_unused]] ILxUnknownID vector, [[maybe_unused]] double dist, [[maybe_unused]] double *opa) override
#define LXxO_Raymarch_GetOpacity LXxD_Raymarch_GetOpacity
#define LXxC_Raymarch_GetOpacity(c) LxResult c::rmrch_GetOpacity([[maybe_unused]] ILxUnknownID vector, [[maybe_unused]] double dist, [[maybe_unused]] double *opa)
#define LXxD_Raymarch_ShaderEvaluate LxResult rmrch_ShaderEvaluate([[maybe_unused]] ILxUnknownID vector, [[maybe_unused]] ILxUnknownID shader) override
#define LXxO_Raymarch_ShaderEvaluate LXxD_Raymarch_ShaderEvaluate
#define LXxC_Raymarch_ShaderEvaluate(c) LxResult c::rmrch_ShaderEvaluate([[maybe_unused]] ILxUnknownID vector, [[maybe_unused]] ILxUnknownID shader)
#define LXxD_Raymarch_Jitter1D LxResult rmrch_Jitter1D([[maybe_unused]] ILxUnknownID vector, [[maybe_unused]] float *offset) override
#define LXxO_Raymarch_Jitter1D LXxD_Raymarch_Jitter1D
#define LXxC_Raymarch_Jitter1D(c) LxResult c::rmrch_Jitter1D([[maybe_unused]] ILxUnknownID vector, [[maybe_unused]] float *offset)

template <class T>
class CLxIfc_Raymarch: public CLxInterface
{
public:
    CLxIfc_Raymarch()
    {
        vt.AddVolume = AddVolume;
        vt.AddSurface = AddSurface;
        vt.GetOpacity = GetOpacity;
        vt.ShaderEvaluate = ShaderEvaluate;
        vt.Jitter1D = Jitter1D;
        vTable = &vt.iunk;
        iid = &lx::guid_Raymarch;
    }

    static auto AddVolume(LXtObjectID wcom,LXtObjectID vector,LXtVolumeSample *vs) -> LxResult
    {
        LXCWxINST (CLxImpl_Raymarch, loc);
        try
        {
           return loc->rmrch_AddVolume((ILxUnknownID) vector, vs);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto AddSurface(LXtObjectID wcom,LXtObjectID vector,LXtSurfFragment *ss) -> LxResult
    {
        LXCWxINST (CLxImpl_Raymarch, loc);
        try
        {
           return loc->rmrch_AddSurface((ILxUnknownID) vector, ss);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto GetOpacity(LXtObjectID wcom,LXtObjectID vector,double dist,double *opa) -> LxResult
    {
        LXCWxINST (CLxImpl_Raymarch, loc);
        try
        {
           return loc->rmrch_GetOpacity((ILxUnknownID) vector, dist, opa);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ShaderEvaluate(LXtObjectID wcom,LXtObjectID vector,LXtObjectID shader) -> LxResult
    {
        LXCWxINST (CLxImpl_Raymarch, loc);
        try
        {
           return loc->rmrch_ShaderEvaluate((ILxUnknownID) vector,(ILxUnknownID) shader);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Jitter1D(LXtObjectID wcom,LXtObjectID vector,float *offset) -> LxResult
    {
        LXCWxINST (CLxImpl_Raymarch, loc);
        try
        {
           return loc->rmrch_Jitter1D((ILxUnknownID) vector, offset);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxRaymarch vt;
};

class CLxLoc_Raymarch : public CLxLocalize<ILxRaymarchID>
{
public:
    CLxLoc_Raymarch()
    {
        _init();
    }

    CLxLoc_Raymarch(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_Raymarch(CLxLoc_Raymarch const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_Raymarch;
    }

    auto AddVolume(ILxUnknownID vector, LXtVolumeSample *vs) -> LxResult
    {
        return m_loc[0]->AddVolume(m_loc,(ILxUnknownID) vector, vs);
    }

    auto AddSurface(ILxUnknownID vector, LXtSurfFragment *ss) -> LxResult
    {
        return m_loc[0]->AddSurface(m_loc,(ILxUnknownID) vector, ss);
    }

    auto GetOpacity(ILxUnknownID vector, double dist, double *opa) -> LxResult
    {
        return m_loc[0]->GetOpacity(m_loc,(ILxUnknownID) vector, dist, opa);
    }

    auto ShaderEvaluate(ILxUnknownID vector, ILxUnknownID shader) -> LxResult
    {
        return m_loc[0]->ShaderEvaluate(m_loc,(ILxUnknownID) vector,(ILxUnknownID) shader);
    }

    auto Jitter1D(ILxUnknownID vector, float *offset) -> LxResult
    {
        return m_loc[0]->Jitter1D(m_loc,(ILxUnknownID) vector, offset);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_Voxel
{
public:
    virtual ~CLxImpl_Voxel() = default;

    virtual auto voxel_FeatureCount([[maybe_unused]] unsigned *num) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto voxel_FeatureByIndex([[maybe_unused]] unsigned index, [[maybe_unused]] const char **name) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto voxel_BBox([[maybe_unused]] LXtTableauBox bbox) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto voxel_NextPos([[maybe_unused]] float currentPos, [[maybe_unused]] unsigned currentSegment, [[maybe_unused]] float stride, [[maybe_unused]] float *segmentList, [[maybe_unused]] unsigned *nextSegment, [[maybe_unused]] float *nextPos) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto voxel_Sample([[maybe_unused]] const LXtFVector pos, [[maybe_unused]] unsigned index, [[maybe_unused]] float *val) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto voxel_VDBData([[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto voxel_RayIntersect([[maybe_unused]] const LXtVector origin, [[maybe_unused]] const LXtFVector direction, [[maybe_unused]] unsigned *numberOfSegments, [[maybe_unused]] float **Segmentlist) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto voxel_RayRelease([[maybe_unused]] unsigned numberOfSegments, [[maybe_unused]] float **Segmentlist) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_Voxel_FeatureCount LxResult voxel_FeatureCount([[maybe_unused]] unsigned *num) override
#define LXxO_Voxel_FeatureCount LXxD_Voxel_FeatureCount
#define LXxC_Voxel_FeatureCount(c) LxResult c::voxel_FeatureCount([[maybe_unused]] unsigned *num)
#define LXxD_Voxel_FeatureByIndex LxResult voxel_FeatureByIndex([[maybe_unused]] unsigned index, [[maybe_unused]] const char **name) override
#define LXxO_Voxel_FeatureByIndex LXxD_Voxel_FeatureByIndex
#define LXxC_Voxel_FeatureByIndex(c) LxResult c::voxel_FeatureByIndex([[maybe_unused]] unsigned index, [[maybe_unused]] const char **name)
#define LXxD_Voxel_BBox LxResult voxel_BBox([[maybe_unused]] LXtTableauBox bbox) override
#define LXxO_Voxel_BBox LXxD_Voxel_BBox
#define LXxC_Voxel_BBox(c) LxResult c::voxel_BBox([[maybe_unused]] LXtTableauBox bbox)
#define LXxD_Voxel_NextPos LxResult voxel_NextPos([[maybe_unused]] float currentPos, [[maybe_unused]] unsigned currentSegment, [[maybe_unused]] float stride, [[maybe_unused]] float *segmentList, [[maybe_unused]] unsigned *nextSegment, [[maybe_unused]] float *nextPos) override
#define LXxO_Voxel_NextPos LXxD_Voxel_NextPos
#define LXxC_Voxel_NextPos(c) LxResult c::voxel_NextPos([[maybe_unused]] float currentPos, [[maybe_unused]] unsigned currentSegment, [[maybe_unused]] float stride, [[maybe_unused]] float *segmentList, [[maybe_unused]] unsigned *nextSegment, [[maybe_unused]] float *nextPos)
#define LXxD_Voxel_Sample LxResult voxel_Sample([[maybe_unused]] const LXtFVector pos, [[maybe_unused]] unsigned index, [[maybe_unused]] float *val) override
#define LXxO_Voxel_Sample LXxD_Voxel_Sample
#define LXxC_Voxel_Sample(c) LxResult c::voxel_Sample([[maybe_unused]] const LXtFVector pos, [[maybe_unused]] unsigned index, [[maybe_unused]] float *val)
#define LXxD_Voxel_VDBData LxResult voxel_VDBData([[maybe_unused]] void **ppvObj) override
#define LXxO_Voxel_VDBData LXxD_Voxel_VDBData
#define LXxC_Voxel_VDBData(c) LxResult c::voxel_VDBData([[maybe_unused]] void **ppvObj)
#define LXxD_Voxel_RayIntersect LxResult voxel_RayIntersect([[maybe_unused]] const LXtVector origin, [[maybe_unused]] const LXtFVector direction, [[maybe_unused]] unsigned *numberOfSegments, [[maybe_unused]] float **Segmentlist) override
#define LXxO_Voxel_RayIntersect LXxD_Voxel_RayIntersect
#define LXxC_Voxel_RayIntersect(c) LxResult c::voxel_RayIntersect([[maybe_unused]] const LXtVector origin, [[maybe_unused]] const LXtFVector direction, [[maybe_unused]] unsigned *numberOfSegments, [[maybe_unused]] float **Segmentlist)
#define LXxD_Voxel_RayRelease LxResult voxel_RayRelease([[maybe_unused]] unsigned numberOfSegments, [[maybe_unused]] float **Segmentlist) override
#define LXxO_Voxel_RayRelease LXxD_Voxel_RayRelease
#define LXxC_Voxel_RayRelease(c) LxResult c::voxel_RayRelease([[maybe_unused]] unsigned numberOfSegments, [[maybe_unused]] float **Segmentlist)

template <class T>
class CLxIfc_Voxel: public CLxInterface
{
public:
    CLxIfc_Voxel()
    {
        vt.FeatureCount = FeatureCount;
        vt.FeatureByIndex = FeatureByIndex;
        vt.BBox = BBox;
        vt.NextPos = NextPos;
        vt.Sample = Sample;
        vt.VDBData = VDBData;
        vt.RayIntersect = RayIntersect;
        vt.RayRelease = RayRelease;
        vTable = &vt.iunk;
        iid = &lx::guid_Voxel;
    }

    static auto FeatureCount(LXtObjectID wcom,unsigned *num) -> LxResult
    {
        LXCWxINST (CLxImpl_Voxel, loc);
        try
        {
           return loc->voxel_FeatureCount( num);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto FeatureByIndex(LXtObjectID wcom,unsigned index,const char **name) -> LxResult
    {
        LXCWxINST (CLxImpl_Voxel, loc);
        try
        {
           return loc->voxel_FeatureByIndex( index, name);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto BBox(LXtObjectID wcom,LXtTableauBox bbox) -> LxResult
    {
        LXCWxINST (CLxImpl_Voxel, loc);
        try
        {
           return loc->voxel_BBox( bbox);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto NextPos(LXtObjectID wcom,float currentPos,unsigned currentSegment,float stride,float *segmentList,unsigned *nextSegment,float *nextPos) -> LxResult
    {
        LXCWxINST (CLxImpl_Voxel, loc);
        try
        {
           return loc->voxel_NextPos( currentPos, currentSegment, stride, segmentList, nextSegment, nextPos);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Sample(LXtObjectID wcom,const LXtFVector pos,unsigned index,float *val) -> LxResult
    {
        LXCWxINST (CLxImpl_Voxel, loc);
        try
        {
           return loc->voxel_Sample( pos, index, val);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto VDBData(LXtObjectID wcom,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_Voxel, loc);
        try
        {
           return loc->voxel_VDBData( ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto RayIntersect(LXtObjectID wcom,const LXtVector origin,const LXtFVector direction,unsigned *numberOfSegments,float **Segmentlist) -> LxResult
    {
        LXCWxINST (CLxImpl_Voxel, loc);
        try
        {
           return loc->voxel_RayIntersect( origin, direction, numberOfSegments, Segmentlist);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto RayRelease(LXtObjectID wcom,unsigned numberOfSegments,float **Segmentlist) -> LxResult
    {
        LXCWxINST (CLxImpl_Voxel, loc);
        try
        {
           return loc->voxel_RayRelease( numberOfSegments, Segmentlist);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxVoxel vt;
};

class CLxLoc_Voxel : public CLxLocalize<ILxVoxelID>
{
public:
    CLxLoc_Voxel()
    {
        _init();
    }

    CLxLoc_Voxel(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_Voxel(CLxLoc_Voxel const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_Voxel;
    }

    auto FeatureCount(unsigned *num) -> LxResult
    {
        return m_loc[0]->FeatureCount(m_loc, num);
    }

    auto FeatureByIndex(unsigned index, const char **name) -> LxResult
    {
        return m_loc[0]->FeatureByIndex(m_loc, index, name);
    }

    auto BBox(LXtTableauBox bbox) -> LxResult
    {
        return m_loc[0]->BBox(m_loc, bbox);
    }

    auto NextPos(float currentPos, unsigned currentSegment, float stride, float *segmentList, unsigned *nextSegment, float *nextPos) -> LxResult
    {
        return m_loc[0]->NextPos(m_loc, currentPos, currentSegment, stride, segmentList, nextSegment, nextPos);
    }

    auto Sample(const LXtFVector pos, unsigned index, float *val) -> LxResult
    {
        return m_loc[0]->Sample(m_loc, pos, index, val);
    }

    auto VDBData(void **ppvObj) -> LxResult
    {
        return m_loc[0]->VDBData(m_loc, ppvObj);
    }

    auto VDBData(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->VDBData(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto RayIntersect(const LXtVector origin, const LXtFVector direction, unsigned *numberOfSegments, float **Segmentlist) -> LxResult
    {
        return m_loc[0]->RayIntersect(m_loc, origin, direction, numberOfSegments, Segmentlist);
    }

    auto RayRelease(unsigned numberOfSegments, float **Segmentlist) -> LxResult
    {
        return m_loc[0]->RayRelease(m_loc, numberOfSegments, Segmentlist);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
