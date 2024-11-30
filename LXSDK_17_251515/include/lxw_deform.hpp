//
// C++ wrapper for lxsdk/lxdeform.h.
//
//	Copyright 2024.
//
//
#pragma once

#include <lxdeform.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx
{
    static LXtGUID const guid_Falloff = {0xB75CFFA3, {0xD25C, 0x4520}, {0xB1, 0xC6, 0x3C, 0xB3, 0x92, 0x4B, 0xF5, 0x97}};
    static LXtGUID const guid_Falloff1 = {0xB7D1DEF8, {0x1F45, 0x4924}, {0xB5, 0x18, 0xE2, 0xF2, 0xA7, 0x6D, 0x02, 0x59}};
    static LXtGUID const guid_Deformation = {0xA4736B27, {0x142A, 0x46B2}, {0xAF, 0x7D, 0xF5, 0x00, 0x80, 0x51, 0xFC, 0xD6}};
    static LXtGUID const guid_Deformation1 = {0xF5705327, {0x7382, 0x47C5}, {0x8D, 0x7B, 0xAF, 0x2C, 0xC1, 0x8B, 0x3E, 0x8A}};
    static LXtGUID const guid_Deformer = {0x505D1B5A, {0x74FF, 0x4642}, {0xB9, 0x92, 0x17, 0x48, 0x59, 0x76, 0x6E, 0xA3}};
    static LXtGUID const guid_Deformer1 = {0xF029A563, {0xA937, 0x4DB2}, {0x99, 0x2E, 0x15, 0x92, 0x08, 0x1F, 0x64, 0xCC}};
    static LXtGUID const guid_MeshInfluence = {0xD70AA410, {0x75BB, 0x480E}, {0x90, 0xE2, 0x17, 0xE2, 0x05, 0x9E, 0xB4, 0x0B}};
    static LXtGUID const guid_ItemInfluence = {0x2141BD0B, {0xDEFC, 0x4A92}, {0xA4, 0xA5, 0x30, 0x76, 0x0C, 0x09, 0xF1, 0x8B}};
    static LXtGUID const guid_GroupDeformer = {0x4BC04F3F, {0x29FC, 0x4EA3}, {0xB0, 0x90, 0x10, 0x28, 0x03, 0x31, 0xC7, 0x57}};
    static LXtGUID const guid_WeightMapDeformerItem = {0xA9C81E0B, {0x20F0, 0x4D8B}, {0x83, 0x8B, 0xB5, 0x93, 0xEA, 0xF3, 0xDF, 0xB8}};
    static LXtGUID const guid_DeformerService = {0x8267068C, {0xFDBB, 0x430A}, {0x82, 0x30, 0xBE, 0x64, 0xF7, 0x2C, 0xE3, 0xE3}};
} // namespace lx

class CLxImpl_Falloff
{
public:
    virtual ~CLxImpl_Falloff() = default;

    virtual auto fall_Bounds([[maybe_unused]] LXtBBox *box) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual float fall_WeightF(const LXtFVector position, LXtPointID point, LXtPolygonID polygon) = 0;

    virtual auto fall_WeightRun([[maybe_unused]] const float **pos, [[maybe_unused]] const LXtPointID *points, [[maybe_unused]] const LXtPolygonID *polygons, [[maybe_unused]] float *weight, [[maybe_unused]] unsigned num) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto fall_SetMesh([[maybe_unused]] ILxUnknownID mesh, [[maybe_unused]] LXtMatrix4 xfrm) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_Falloff_Bounds LxResult fall_Bounds([[maybe_unused]] LXtBBox *box) override
#define LXxO_Falloff_Bounds LXxD_Falloff_Bounds
#define LXxC_Falloff_Bounds(c) LxResult c::fall_Bounds([[maybe_unused]] LXtBBox *box)
#define LXxD_Falloff_WeightF float fall_WeightF([[maybe_unused]] const LXtFVector position, [[maybe_unused]] LXtPointID point, [[maybe_unused]] LXtPolygonID polygon) override
#define LXxO_Falloff_WeightF LXxD_Falloff_WeightF
#define LXxC_Falloff_WeightF(c) float c::fall_WeightF([[maybe_unused]] const LXtFVector position, [[maybe_unused]] LXtPointID point, [[maybe_unused]] LXtPolygonID polygon)
#define LXxD_Falloff_WeightRun LxResult fall_WeightRun([[maybe_unused]] const float **pos, [[maybe_unused]] const LXtPointID *points, [[maybe_unused]] const LXtPolygonID *polygons, [[maybe_unused]] float *weight, [[maybe_unused]] unsigned num) override
#define LXxO_Falloff_WeightRun LXxD_Falloff_WeightRun
#define LXxC_Falloff_WeightRun(c) LxResult c::fall_WeightRun([[maybe_unused]] const float **pos, [[maybe_unused]] const LXtPointID *points, [[maybe_unused]] const LXtPolygonID *polygons, [[maybe_unused]] float *weight, [[maybe_unused]] unsigned num)
#define LXxD_Falloff_SetMesh LxResult fall_SetMesh([[maybe_unused]] ILxUnknownID mesh, [[maybe_unused]] LXtMatrix4 xfrm) override
#define LXxO_Falloff_SetMesh LXxD_Falloff_SetMesh
#define LXxC_Falloff_SetMesh(c) LxResult c::fall_SetMesh([[maybe_unused]] ILxUnknownID mesh, [[maybe_unused]] LXtMatrix4 xfrm)

template <class T>
class CLxIfc_Falloff: public CLxInterface
{
public:
    CLxIfc_Falloff()
    {
        vt.Bounds = Bounds;
        vt.WeightF = WeightF;
        vt.WeightRun = WeightRun;
        vt.SetMesh = SetMesh;
        vTable = &vt.iunk;
        iid = &lx::guid_Falloff;
    }

    static auto Bounds(LXtObjectID wcom,LXtBBox *box) -> LxResult
    {
        LXCWxINST (CLxImpl_Falloff, loc);
        try
        {
           return loc->fall_Bounds( box);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto WeightF(LXtObjectID wcom,const LXtFVector position,LXtPointID point,LXtPolygonID polygon) -> float
    {
        LXCWxINST (CLxImpl_Falloff, loc);
        return loc->fall_WeightF( position, point, polygon);
    }

    static auto WeightRun(LXtObjectID wcom,const float **pos,const LXtPointID *points,const LXtPolygonID *polygons,float *weight,unsigned num) -> LxResult
    {
        LXCWxINST (CLxImpl_Falloff, loc);
        try
        {
           return loc->fall_WeightRun( pos, points, polygons, weight, num);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SetMesh(LXtObjectID wcom,LXtObjectID mesh,LXtMatrix4 xfrm) -> LxResult
    {
        LXCWxINST (CLxImpl_Falloff, loc);
        try
        {
           return loc->fall_SetMesh((ILxUnknownID) mesh, xfrm);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxFalloff vt;
};

class CLxLoc_Falloff : public CLxLocalize<ILxFalloffID>
{
public:
    CLxLoc_Falloff()
    {
        _init();
    }

    CLxLoc_Falloff(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_Falloff(CLxLoc_Falloff const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_Falloff;
    }

    auto Bounds(LXtBBox *box) -> LxResult
    {
        return m_loc[0]->Bounds(m_loc, box);
    }

    auto WeightF(const LXtFVector position, LXtPointID point, LXtPolygonID polygon) -> float
    {
        return m_loc[0]->WeightF(m_loc, position, point, polygon);
    }

    auto WeightRun(const float **pos, const LXtPointID *points, const LXtPolygonID *polygons, float *weight, unsigned num) -> LxResult
    {
        return m_loc[0]->WeightRun(m_loc, pos, points, polygons, weight, num);
    }

    auto SetMesh(ILxUnknownID mesh, LXtMatrix4 xfrm) -> LxResult
    {
        return m_loc[0]->SetMesh(m_loc,(ILxUnknownID) mesh, xfrm);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};

class CLxImpl_Deformation
{
public:
    virtual ~CLxImpl_Deformation() = default;

    virtual auto deform_Flags([[maybe_unused]] void) -> unsigned
    {
        return 0;
    }

    virtual auto deform_Transform([[maybe_unused]] LXtMatrix4 xfrm) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual void deform_OffsetF([[maybe_unused]] const LXtFVector position, [[maybe_unused]] int idx, [[maybe_unused]] float weight, [[maybe_unused]] LXtFVector offset)
    {
    }

    virtual void deform_OBSOLETE([[maybe_unused]] void)
    {
    }

    virtual auto deform_OffsetRun([[maybe_unused]] const float **pos, [[maybe_unused]] const int *idx, [[maybe_unused]] const float *weight, [[maybe_unused]] float **offset, [[maybe_unused]] unsigned num) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_Deformation_Flags unsigned deform_Flags() override
#define LXxO_Deformation_Flags LXxD_Deformation_Flags
#define LXxC_Deformation_Flags(c) unsigned c::deform_Flags()
#define LXxD_Deformation_Transform LxResult deform_Transform([[maybe_unused]] LXtMatrix4 xfrm) override
#define LXxO_Deformation_Transform LXxD_Deformation_Transform
#define LXxC_Deformation_Transform(c) LxResult c::deform_Transform([[maybe_unused]] LXtMatrix4 xfrm)
#define LXxD_Deformation_OffsetF void deform_OffsetF([[maybe_unused]] const LXtFVector position, [[maybe_unused]] int idx, [[maybe_unused]] float weight, [[maybe_unused]] LXtFVector offset) override
#define LXxO_Deformation_OffsetF LXxD_Deformation_OffsetF
#define LXxC_Deformation_OffsetF(c) void c::deform_OffsetF([[maybe_unused]] const LXtFVector position, [[maybe_unused]] int idx, [[maybe_unused]] float weight, [[maybe_unused]] LXtFVector offset)
#define LXxD_Deformation_OBSOLETE void deform_OBSOLETE() override
#define LXxO_Deformation_OBSOLETE LXxD_Deformation_OBSOLETE
#define LXxC_Deformation_OBSOLETE(c) void c::deform_OBSOLETE()
#define LXxD_Deformation_OffsetRun LxResult deform_OffsetRun([[maybe_unused]] const float **pos, [[maybe_unused]] const int *idx, [[maybe_unused]] const float *weight, [[maybe_unused]] float **offset, [[maybe_unused]] unsigned num) override
#define LXxO_Deformation_OffsetRun LXxD_Deformation_OffsetRun
#define LXxC_Deformation_OffsetRun(c) LxResult c::deform_OffsetRun([[maybe_unused]] const float **pos, [[maybe_unused]] const int *idx, [[maybe_unused]] const float *weight, [[maybe_unused]] float **offset, [[maybe_unused]] unsigned num)

template <class T>
class CLxIfc_Deformation: public CLxInterface
{
public:
    CLxIfc_Deformation()
    {
        vt.Flags = Flags;
        vt.Transform = Transform;
        vt.OffsetF = OffsetF;
        vt.OBSOLETE = OBSOLETE;
        vt.OffsetRun = OffsetRun;
        vTable = &vt.iunk;
        iid = &lx::guid_Deformation;
    }

    static auto Flags(LXtObjectID wcom) -> unsigned
    {
        LXCWxINST (CLxImpl_Deformation, loc);
        return loc->deform_Flags();
    }

    static auto Transform(LXtObjectID wcom,LXtMatrix4 xfrm) -> LxResult
    {
        LXCWxINST (CLxImpl_Deformation, loc);
        try
        {
           return loc->deform_Transform( xfrm);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto OffsetF(LXtObjectID wcom,const LXtFVector position,int idx,float weight,LXtFVector offset) -> void
    {
        LXCWxINST (CLxImpl_Deformation, loc);
        loc->deform_OffsetF( position, idx, weight, offset);
    }

    static auto OBSOLETE(LXtObjectID wcom) -> void
    {
        LXCWxINST (CLxImpl_Deformation, loc);
        loc->deform_OBSOLETE();
    }

    static auto OffsetRun(LXtObjectID wcom,const float **pos,const int *idx,const float *weight,float **offset,unsigned num) -> LxResult
    {
        LXCWxINST (CLxImpl_Deformation, loc);
        try
        {
           return loc->deform_OffsetRun( pos, idx, weight, offset, num);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxDeformation vt;
};

class CLxLoc_Deformation : public CLxLocalize<ILxDeformationID>
{
public:
    CLxLoc_Deformation()
    {
        _init();
    }

    CLxLoc_Deformation(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_Deformation(CLxLoc_Deformation const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_Deformation;
    }

    auto Flags(void) -> unsigned
    {
        return m_loc[0]->Flags(m_loc);
    }

    auto Transform(LXtMatrix4 xfrm) -> LxResult
    {
        return m_loc[0]->Transform(m_loc, xfrm);
    }

    auto OffsetF(const LXtFVector position, int idx, float weight, LXtFVector offset) -> void
    {
        m_loc[0]->OffsetF(m_loc, position, idx, weight, offset);
    }

    auto OBSOLETE(void) -> void
    {
        m_loc[0]->OBSOLETE(m_loc);
    }

    auto OffsetRun(const float **pos, const int *idx, const float *weight, float **offset, unsigned num) -> LxResult
    {
        return m_loc[0]->OffsetRun(m_loc, pos, idx, weight, offset, num);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};

class CLxImpl_Deformer
{
public:
    virtual ~CLxImpl_Deformer() = default;

    virtual unsigned dinf_Flags(void) = 0;

    virtual auto dinf_PartitionCount([[maybe_unused]] void) -> unsigned
    {
        return 0;
    }

    virtual auto dinf_EnumeratePartition([[maybe_unused]] ILxUnknownID visitor, [[maybe_unused]] unsigned part) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual LXtDeformElt dinf_Element(unsigned *segment) = 0;

    virtual auto dinf_SetPartition([[maybe_unused]] unsigned part) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto dinf_Weight([[maybe_unused]] LXtDeformElt elt, [[maybe_unused]] const LXtFVector pos, [[maybe_unused]] int idx) -> float
    {
        return 1;
    }

    virtual void dinf_Offset([[maybe_unused]] LXtDeformElt elt, [[maybe_unused]] float weight, [[maybe_unused]] const LXtFVector pos, [[maybe_unused]] int idx, [[maybe_unused]] LXtFVector offset)
    {
    }

    virtual auto dinf_WeightRun([[maybe_unused]] unsigned segment, [[maybe_unused]] const LXtDeformElt *elt, [[maybe_unused]] const float **pos, [[maybe_unused]] const int *idx, [[maybe_unused]] float *weight, [[maybe_unused]] unsigned num) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto dinf_OffsetRun([[maybe_unused]] unsigned segment, [[maybe_unused]] const LXtDeformElt *elt, [[maybe_unused]] const float **pos, [[maybe_unused]] const int *idx, [[maybe_unused]] const float *weight, [[maybe_unused]] float **offset, [[maybe_unused]] unsigned num) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_Deformer_Flags unsigned dinf_Flags() override
#define LXxO_Deformer_Flags LXxD_Deformer_Flags
#define LXxC_Deformer_Flags(c) unsigned c::dinf_Flags()
#define LXxD_Deformer_PartitionCount unsigned dinf_PartitionCount() override
#define LXxO_Deformer_PartitionCount LXxD_Deformer_PartitionCount
#define LXxC_Deformer_PartitionCount(c) unsigned c::dinf_PartitionCount()
#define LXxD_Deformer_EnumeratePartition LxResult dinf_EnumeratePartition([[maybe_unused]] ILxUnknownID visitor, [[maybe_unused]] unsigned part) override
#define LXxO_Deformer_EnumeratePartition LXxD_Deformer_EnumeratePartition
#define LXxC_Deformer_EnumeratePartition(c) LxResult c::dinf_EnumeratePartition([[maybe_unused]] ILxUnknownID visitor, [[maybe_unused]] unsigned part)
#define LXxD_Deformer_Element LXtDeformElt dinf_Element([[maybe_unused]] unsigned *segment) override
#define LXxO_Deformer_Element LXxD_Deformer_Element
#define LXxC_Deformer_Element(c) LXtDeformElt c::dinf_Element([[maybe_unused]] unsigned *segment)
#define LXxD_Deformer_SetPartition LxResult dinf_SetPartition([[maybe_unused]] unsigned part) override
#define LXxO_Deformer_SetPartition LXxD_Deformer_SetPartition
#define LXxC_Deformer_SetPartition(c) LxResult c::dinf_SetPartition([[maybe_unused]] unsigned part)
#define LXxD_Deformer_Weight float dinf_Weight([[maybe_unused]] LXtDeformElt elt, [[maybe_unused]] const LXtFVector pos, [[maybe_unused]] int idx) override
#define LXxO_Deformer_Weight LXxD_Deformer_Weight
#define LXxC_Deformer_Weight(c) float c::dinf_Weight([[maybe_unused]] LXtDeformElt elt, [[maybe_unused]] const LXtFVector pos, [[maybe_unused]] int idx)
#define LXxD_Deformer_Offset void dinf_Offset([[maybe_unused]] LXtDeformElt elt, [[maybe_unused]] float weight, [[maybe_unused]] const LXtFVector pos, [[maybe_unused]] int idx, [[maybe_unused]] LXtFVector offset) override
#define LXxO_Deformer_Offset LXxD_Deformer_Offset
#define LXxC_Deformer_Offset(c) void c::dinf_Offset([[maybe_unused]] LXtDeformElt elt, [[maybe_unused]] float weight, [[maybe_unused]] const LXtFVector pos, [[maybe_unused]] int idx, [[maybe_unused]] LXtFVector offset)
#define LXxD_Deformer_WeightRun LxResult dinf_WeightRun([[maybe_unused]] unsigned segment, [[maybe_unused]] const LXtDeformElt *elt, [[maybe_unused]] const float **pos, [[maybe_unused]] const int *idx, [[maybe_unused]] float *weight, [[maybe_unused]] unsigned num) override
#define LXxO_Deformer_WeightRun LXxD_Deformer_WeightRun
#define LXxC_Deformer_WeightRun(c) LxResult c::dinf_WeightRun([[maybe_unused]] unsigned segment, [[maybe_unused]] const LXtDeformElt *elt, [[maybe_unused]] const float **pos, [[maybe_unused]] const int *idx, [[maybe_unused]] float *weight, [[maybe_unused]] unsigned num)
#define LXxD_Deformer_OffsetRun LxResult dinf_OffsetRun([[maybe_unused]] unsigned segment, [[maybe_unused]] const LXtDeformElt *elt, [[maybe_unused]] const float **pos, [[maybe_unused]] const int *idx, [[maybe_unused]] const float *weight, [[maybe_unused]] float **offset, [[maybe_unused]] unsigned num) override
#define LXxO_Deformer_OffsetRun LXxD_Deformer_OffsetRun
#define LXxC_Deformer_OffsetRun(c) LxResult c::dinf_OffsetRun([[maybe_unused]] unsigned segment, [[maybe_unused]] const LXtDeformElt *elt, [[maybe_unused]] const float **pos, [[maybe_unused]] const int *idx, [[maybe_unused]] const float *weight, [[maybe_unused]] float **offset, [[maybe_unused]] unsigned num)

template <class T>
class CLxIfc_Deformer: public CLxInterface
{
public:
    CLxIfc_Deformer()
    {
        vt.Flags = Flags;
        vt.PartitionCount = PartitionCount;
        vt.EnumeratePartition = EnumeratePartition;
        vt.Element = Element;
        vt.SetPartition = SetPartition;
        vt.Weight = Weight;
        vt.Offset = Offset;
        vt.WeightRun = WeightRun;
        vt.OffsetRun = OffsetRun;
        vTable = &vt.iunk;
        iid = &lx::guid_Deformer;
    }

    static auto Flags(LXtObjectID wcom) -> unsigned
    {
        LXCWxINST (CLxImpl_Deformer, loc);
        return loc->dinf_Flags();
    }

    static auto PartitionCount(LXtObjectID wcom) -> unsigned
    {
        LXCWxINST (CLxImpl_Deformer, loc);
        return loc->dinf_PartitionCount();
    }

    static auto EnumeratePartition(LXtObjectID wcom,LXtObjectID visitor,unsigned part) -> LxResult
    {
        LXCWxINST (CLxImpl_Deformer, loc);
        try
        {
           return loc->dinf_EnumeratePartition((ILxUnknownID) visitor, part);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Element(LXtObjectID wcom,unsigned *segment) -> LXtDeformElt
    {
        LXCWxINST (CLxImpl_Deformer, loc);
        return loc->dinf_Element( segment);
    }

    static auto SetPartition(LXtObjectID wcom,unsigned part) -> LxResult
    {
        LXCWxINST (CLxImpl_Deformer, loc);
        try
        {
           return loc->dinf_SetPartition( part);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Weight(LXtObjectID wcom,LXtDeformElt elt,const LXtFVector pos,int idx) -> float
    {
        LXCWxINST (CLxImpl_Deformer, loc);
        return loc->dinf_Weight( elt, pos, idx);
    }

    static auto Offset(LXtObjectID wcom,LXtDeformElt elt,float weight,const LXtFVector pos,int idx,LXtFVector offset) -> void
    {
        LXCWxINST (CLxImpl_Deformer, loc);
        loc->dinf_Offset( elt, weight, pos, idx, offset);
    }

    static auto WeightRun(LXtObjectID wcom,unsigned segment,const LXtDeformElt *elt,const float **pos,const int *idx,float *weight,unsigned num) -> LxResult
    {
        LXCWxINST (CLxImpl_Deformer, loc);
        try
        {
           return loc->dinf_WeightRun( segment, elt, pos, idx, weight, num);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto OffsetRun(LXtObjectID wcom,unsigned segment,const LXtDeformElt *elt,const float **pos,const int *idx,const float *weight,float **offset,unsigned num) -> LxResult
    {
        LXCWxINST (CLxImpl_Deformer, loc);
        try
        {
           return loc->dinf_OffsetRun( segment, elt, pos, idx, weight, offset, num);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxDeformer vt;
};

class CLxLoc_Deformer : public CLxLocalize<ILxDeformerID>
{
public:
    CLxLoc_Deformer()
    {
        _init();
    }

    CLxLoc_Deformer(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_Deformer(CLxLoc_Deformer const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_Deformer;
    }

    auto Flags(void) -> unsigned
    {
        return m_loc[0]->Flags(m_loc);
    }

    auto PartitionCount(void) -> unsigned
    {
        return m_loc[0]->PartitionCount(m_loc);
    }

    auto EnumeratePartition(ILxUnknownID visitor, unsigned part) -> LxResult
    {
        return m_loc[0]->EnumeratePartition(m_loc,(ILxUnknownID) visitor, part);
    }

    auto Element(unsigned *segment) -> LXtDeformElt
    {
        return m_loc[0]->Element(m_loc, segment);
    }

    auto SetPartition(unsigned part) -> LxResult
    {
        return m_loc[0]->SetPartition(m_loc, part);
    }

    auto Weight(LXtDeformElt elt, const LXtFVector pos, int idx) -> float
    {
        return m_loc[0]->Weight(m_loc, elt, pos, idx);
    }

    auto Offset(LXtDeformElt elt, float weight, const LXtFVector pos, int idx, LXtFVector offset) -> void
    {
        m_loc[0]->Offset(m_loc, elt, weight, pos, idx, offset);
    }

    auto WeightRun(unsigned segment, const LXtDeformElt *elt, const float **pos, const int *idx, float *weight, unsigned num) -> LxResult
    {
        return m_loc[0]->WeightRun(m_loc, segment, elt, pos, idx, weight, num);
    }

    auto OffsetRun(unsigned segment, const LXtDeformElt *elt, const float **pos, const int *idx, const float *weight, float **offset, unsigned num) -> LxResult
    {
        return m_loc[0]->OffsetRun(m_loc, segment, elt, pos, idx, weight, offset, num);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};

class CLxImpl_MeshInfluence
{
public:
    virtual ~CLxImpl_MeshInfluence() = default;

    virtual auto minf_MeshCount([[maybe_unused]] void) -> unsigned
    {
        return 0;
    }

    virtual auto minf_MeshByIndex([[maybe_unused]] unsigned index, [[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto minf_PartitionIndex([[maybe_unused]] unsigned index) -> unsigned
    {
        return index;
    }

    virtual auto minf_SetMesh([[maybe_unused]] unsigned index, [[maybe_unused]] ILxUnknownID mesh, [[maybe_unused]] ILxUnknownID item) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto minf_SetTransform([[maybe_unused]] unsigned index, [[maybe_unused]] LXtMatrix4 xfrm) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto minf_MeshChange([[maybe_unused]] unsigned index, [[maybe_unused]] LxResult change) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_MeshInfluence_MeshCount unsigned minf_MeshCount() override
#define LXxO_MeshInfluence_MeshCount LXxD_MeshInfluence_MeshCount
#define LXxC_MeshInfluence_MeshCount(c) unsigned c::minf_MeshCount()
#define LXxD_MeshInfluence_MeshByIndex LxResult minf_MeshByIndex([[maybe_unused]] unsigned index, [[maybe_unused]] void **ppvObj) override
#define LXxO_MeshInfluence_MeshByIndex LXxD_MeshInfluence_MeshByIndex
#define LXxC_MeshInfluence_MeshByIndex(c) LxResult c::minf_MeshByIndex([[maybe_unused]] unsigned index, [[maybe_unused]] void **ppvObj)
#define LXxD_MeshInfluence_PartitionIndex unsigned minf_PartitionIndex([[maybe_unused]] unsigned index) override
#define LXxO_MeshInfluence_PartitionIndex LXxD_MeshInfluence_PartitionIndex
#define LXxC_MeshInfluence_PartitionIndex(c) unsigned c::minf_PartitionIndex([[maybe_unused]] unsigned index)
#define LXxD_MeshInfluence_SetMesh LxResult minf_SetMesh([[maybe_unused]] unsigned index, [[maybe_unused]] ILxUnknownID mesh, [[maybe_unused]] ILxUnknownID item) override
#define LXxO_MeshInfluence_SetMesh LXxD_MeshInfluence_SetMesh
#define LXxC_MeshInfluence_SetMesh(c) LxResult c::minf_SetMesh([[maybe_unused]] unsigned index, [[maybe_unused]] ILxUnknownID mesh, [[maybe_unused]] ILxUnknownID item)
#define LXxD_MeshInfluence_SetTransform LxResult minf_SetTransform([[maybe_unused]] unsigned index, [[maybe_unused]] LXtMatrix4 xfrm) override
#define LXxO_MeshInfluence_SetTransform LXxD_MeshInfluence_SetTransform
#define LXxC_MeshInfluence_SetTransform(c) LxResult c::minf_SetTransform([[maybe_unused]] unsigned index, [[maybe_unused]] LXtMatrix4 xfrm)
#define LXxD_MeshInfluence_MeshChange LxResult minf_MeshChange([[maybe_unused]] unsigned index, [[maybe_unused]] LxResult change) override
#define LXxO_MeshInfluence_MeshChange LXxD_MeshInfluence_MeshChange
#define LXxC_MeshInfluence_MeshChange(c) LxResult c::minf_MeshChange([[maybe_unused]] unsigned index, [[maybe_unused]] LxResult change)

template <class T>
class CLxIfc_MeshInfluence: public CLxInterface
{
public:
    CLxIfc_MeshInfluence()
    {
        vt.MeshCount = MeshCount;
        vt.MeshByIndex = MeshByIndex;
        vt.PartitionIndex = PartitionIndex;
        vt.SetMesh = SetMesh;
        vt.SetTransform = SetTransform;
        vt.MeshChange = MeshChange;
        vTable = &vt.iunk;
        iid = &lx::guid_MeshInfluence;
    }

    static auto MeshCount(LXtObjectID wcom) -> unsigned
    {
        LXCWxINST (CLxImpl_MeshInfluence, loc);
        return loc->minf_MeshCount();
    }

    static auto MeshByIndex(LXtObjectID wcom,unsigned index,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_MeshInfluence, loc);
        try
        {
           return loc->minf_MeshByIndex( index, ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto PartitionIndex(LXtObjectID wcom,unsigned index) -> unsigned
    {
        LXCWxINST (CLxImpl_MeshInfluence, loc);
        return loc->minf_PartitionIndex( index);
    }

    static auto SetMesh(LXtObjectID wcom,unsigned index,LXtObjectID mesh,LXtObjectID item) -> LxResult
    {
        LXCWxINST (CLxImpl_MeshInfluence, loc);
        try
        {
           return loc->minf_SetMesh( index,(ILxUnknownID) mesh,(ILxUnknownID) item);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SetTransform(LXtObjectID wcom,unsigned index,LXtMatrix4 xfrm) -> LxResult
    {
        LXCWxINST (CLxImpl_MeshInfluence, loc);
        try
        {
           return loc->minf_SetTransform( index, xfrm);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto MeshChange(LXtObjectID wcom,unsigned index,LxResult change) -> LxResult
    {
        LXCWxINST (CLxImpl_MeshInfluence, loc);
        try
        {
           return loc->minf_MeshChange( index, change);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxMeshInfluence vt;
};

class CLxLoc_MeshInfluence : public CLxLocalize<ILxMeshInfluenceID>
{
public:
    CLxLoc_MeshInfluence()
    {
        _init();
    }

    CLxLoc_MeshInfluence(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_MeshInfluence(CLxLoc_MeshInfluence const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_MeshInfluence;
    }

    auto MeshCount(void) -> unsigned
    {
        return m_loc[0]->MeshCount(m_loc);
    }

    auto MeshByIndex(unsigned index, void **ppvObj) -> LxResult
    {
        return m_loc[0]->MeshByIndex(m_loc, index, ppvObj);
    }

    auto MeshByIndex(unsigned index, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->MeshByIndex(m_loc, index, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto PartitionIndex(unsigned index) -> unsigned
    {
        return m_loc[0]->PartitionIndex(m_loc, index);
    }

    auto SetMesh(unsigned index, ILxUnknownID mesh, ILxUnknownID item) -> LxResult
    {
        return m_loc[0]->SetMesh(m_loc, index,(ILxUnknownID) mesh,(ILxUnknownID) item);
    }

    auto SetTransform(unsigned index, LXtMatrix4 xfrm) -> LxResult
    {
        return m_loc[0]->SetTransform(m_loc, index, xfrm);
    }

    auto MeshChange(unsigned index, LxResult change) -> LxResult
    {
        return m_loc[0]->MeshChange(m_loc, index, change);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_ItemInfluence
{
public:
    virtual ~CLxImpl_ItemInfluence() = default;

    virtual auto iinf_HasItems([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto iinf_Enumerate([[maybe_unused]] ILxUnknownID visitor) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto iinf_GetItem([[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto iinf_AllowTransform([[maybe_unused]] unsigned index, [[maybe_unused]] unsigned *flags) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_ItemInfluence_HasItems LxResult iinf_HasItems() override
#define LXxO_ItemInfluence_HasItems LXxD_ItemInfluence_HasItems
#define LXxC_ItemInfluence_HasItems(c) LxResult c::iinf_HasItems()
#define LXxD_ItemInfluence_Enumerate LxResult iinf_Enumerate([[maybe_unused]] ILxUnknownID visitor) override
#define LXxO_ItemInfluence_Enumerate LXxD_ItemInfluence_Enumerate
#define LXxC_ItemInfluence_Enumerate(c) LxResult c::iinf_Enumerate([[maybe_unused]] ILxUnknownID visitor)
#define LXxD_ItemInfluence_GetItem LxResult iinf_GetItem([[maybe_unused]] void **ppvObj) override
#define LXxO_ItemInfluence_GetItem LXxD_ItemInfluence_GetItem
#define LXxC_ItemInfluence_GetItem(c) LxResult c::iinf_GetItem([[maybe_unused]] void **ppvObj)
#define LXxD_ItemInfluence_AllowTransform LxResult iinf_AllowTransform([[maybe_unused]] unsigned index, [[maybe_unused]] unsigned *flags) override
#define LXxO_ItemInfluence_AllowTransform LXxD_ItemInfluence_AllowTransform
#define LXxC_ItemInfluence_AllowTransform(c) LxResult c::iinf_AllowTransform([[maybe_unused]] unsigned index, [[maybe_unused]] unsigned *flags)

template <class T>
class CLxIfc_ItemInfluence: public CLxInterface
{
public:
    CLxIfc_ItemInfluence()
    {
        vt.HasItems = HasItems;
        vt.Enumerate = Enumerate;
        vt.GetItem = GetItem;
        vt.AllowTransform = AllowTransform;
        vTable = &vt.iunk;
        iid = &lx::guid_ItemInfluence;
    }

    static auto HasItems(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_ItemInfluence, loc);
        try
        {
           return loc->iinf_HasItems();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Enumerate(LXtObjectID wcom,LXtObjectID visitor) -> LxResult
    {
        LXCWxINST (CLxImpl_ItemInfluence, loc);
        try
        {
           return loc->iinf_Enumerate((ILxUnknownID) visitor);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto GetItem(LXtObjectID wcom,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_ItemInfluence, loc);
        try
        {
           return loc->iinf_GetItem( ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto AllowTransform(LXtObjectID wcom,unsigned index,unsigned *flags) -> LxResult
    {
        LXCWxINST (CLxImpl_ItemInfluence, loc);
        try
        {
           return loc->iinf_AllowTransform( index, flags);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxItemInfluence vt;
};

class CLxLoc_ItemInfluence : public CLxLocalize<ILxItemInfluenceID>
{
public:
    CLxLoc_ItemInfluence()
    {
        _init();
    }

    CLxLoc_ItemInfluence(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_ItemInfluence(CLxLoc_ItemInfluence const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_ItemInfluence;
    }

    auto HasItems(void) -> LxResult
    {
        return m_loc[0]->HasItems(m_loc);
    }

    auto Enumerate(ILxUnknownID visitor) -> LxResult
    {
        return m_loc[0]->Enumerate(m_loc,(ILxUnknownID) visitor);
    }

    auto GetItem(void **ppvObj) -> LxResult
    {
        return m_loc[0]->GetItem(m_loc, ppvObj);
    }

    auto GetItem(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->GetItem(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto AllowTransform(unsigned index, unsigned *flags) -> LxResult
    {
        return m_loc[0]->AllowTransform(m_loc, index, flags);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_GroupDeformer : public CLxLocalize<ILxGroupDeformerID>
{
public:
    CLxLoc_GroupDeformer()
    {
        _init();
    }

    CLxLoc_GroupDeformer(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_GroupDeformer(CLxLoc_GroupDeformer const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_GroupDeformer;
    }

    auto DeformerCount(void) -> unsigned
    {
        return m_loc[0]->DeformerCount(m_loc);
    }

    auto DeformerByIndex(unsigned index, void **ppvObj) -> LxResult
    {
        return m_loc[0]->DeformerByIndex(m_loc, index, ppvObj);
    }

    auto DeformerByIndex(unsigned index, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->DeformerByIndex(m_loc, index, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto PointEffect(unsigned meshIndex, LXtPointID point, unsigned *deformer, float *weight, unsigned *count, unsigned max) -> LxResult
    {
        return m_loc[0]->PointEffect(m_loc, meshIndex, point, deformer, weight, count, max);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_WeightMapDeformerItem
{
public:
    virtual ~CLxImpl_WeightMapDeformerItem() = default;

    virtual auto wmd_GetMapName([[maybe_unused]] ILxUnknownID chanRead, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto wmd_GetColor([[maybe_unused]] ILxUnknownID chanRead, [[maybe_unused]] LXtVector col) -> LxResult
    {
        return LXeDEFORM_AUTO_COLOR;
    }
};

#define LXxD_WeightMapDeformerItem_GetMapName LxResult wmd_GetMapName([[maybe_unused]] ILxUnknownID chanRead, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len) override
#define LXxO_WeightMapDeformerItem_GetMapName LXxD_WeightMapDeformerItem_GetMapName
#define LXxC_WeightMapDeformerItem_GetMapName(c) LxResult c::wmd_GetMapName([[maybe_unused]] ILxUnknownID chanRead, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len)
#define LXxD_WeightMapDeformerItem_GetColor LxResult wmd_GetColor([[maybe_unused]] ILxUnknownID chanRead, [[maybe_unused]] LXtVector col) override
#define LXxO_WeightMapDeformerItem_GetColor LXxD_WeightMapDeformerItem_GetColor
#define LXxC_WeightMapDeformerItem_GetColor(c) LxResult c::wmd_GetColor([[maybe_unused]] ILxUnknownID chanRead, [[maybe_unused]] LXtVector col)

template <class T>
class CLxIfc_WeightMapDeformerItem: public CLxInterface
{
public:
    CLxIfc_WeightMapDeformerItem()
    {
        vt.GetMapName = GetMapName;
        vt.GetColor = GetColor;
        vTable = &vt.iunk;
        iid = &lx::guid_WeightMapDeformerItem;
    }

    static auto GetMapName(LXtObjectID wcom,LXtObjectID chanRead,char *buf,unsigned len) -> LxResult
    {
        LXCWxINST (CLxImpl_WeightMapDeformerItem, loc);
        try
        {
           return loc->wmd_GetMapName((ILxUnknownID) chanRead, buf, len);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto GetColor(LXtObjectID wcom,LXtObjectID chanRead,LXtVector col) -> LxResult
    {
        LXCWxINST (CLxImpl_WeightMapDeformerItem, loc);
        try
        {
           return loc->wmd_GetColor((ILxUnknownID) chanRead, col);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxWeightMapDeformerItem vt;
};

class CLxLoc_WeightMapDeformerItem : public CLxLocalize<ILxWeightMapDeformerItemID>
{
public:
    CLxLoc_WeightMapDeformerItem()
    {
        _init();
    }

    CLxLoc_WeightMapDeformerItem(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_WeightMapDeformerItem(CLxLoc_WeightMapDeformerItem const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_WeightMapDeformerItem;
    }

    auto GetMapName(ILxUnknownID chanRead, char *buf, unsigned len) -> LxResult
    {
        return m_loc[0]->GetMapName(m_loc,(ILxUnknownID) chanRead, buf, len);
    }

    auto GetMapName(ILxUnknownID chanRead, std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->GetMapName(m_loc,(ILxUnknownID) chanRead, buf, len);
        LXWx_SBUF2
    }

    auto GetColor(ILxUnknownID chanRead, LXtVector col) -> LxResult
    {
        return m_loc[0]->GetColor(m_loc,(ILxUnknownID) chanRead, col);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_DeformerService : public CLxLocalizedService
{
public:
    ILxDeformerServiceID m_loc{ nullptr };

public:
    CLxLoc_DeformerService()
    {
        _init();
        set();
    }

    ~CLxLoc_DeformerService() = default;

    void set()
    {
        if (!m_loc)
        {
            m_loc = reinterpret_cast<ILxDeformerServiceID>(lx::GetGlobal(&lx::guid_DeformerService));
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

    auto DeformerFlags(ILxUnknownID item, unsigned *flags) -> LxResult
    {
        return m_loc[0]->DeformerFlags(m_loc,(ILxUnknownID) item, flags);
    }

    auto DeformerChannel(ILxUnknownID item, unsigned *index) -> LxResult
    {
        return m_loc[0]->DeformerChannel(m_loc,(ILxUnknownID) item, index);
    }

    auto MergeChangeState(LxResult c1, LxResult c2) -> LxResult
    {
        return m_loc[0]->MergeChangeState(m_loc, c1, c2);
    }

    auto MeshCount(ILxUnknownID defItem, unsigned *count) -> LxResult
    {
        return m_loc[0]->MeshCount(m_loc,(ILxUnknownID) defItem, count);
    }

    auto MeshByIndex(ILxUnknownID defItem, unsigned index, void **ppvObj) -> LxResult
    {
        return m_loc[0]->MeshByIndex(m_loc,(ILxUnknownID) defItem, index, ppvObj);
    }

    auto MeshByIndex(ILxUnknownID defItem, unsigned index, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->MeshByIndex(m_loc,(ILxUnknownID) defItem, index, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto GroupDeformer(ILxUnknownID dgroup, ILxUnknownID chanRead, void **ppvObj) -> LxResult
    {
        return m_loc[0]->GroupDeformer(m_loc,(ILxUnknownID) dgroup,(ILxUnknownID) chanRead, ppvObj);
    }

    auto GroupDeformer(ILxUnknownID dgroup, ILxUnknownID chanRead, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->GroupDeformer(m_loc,(ILxUnknownID) dgroup,(ILxUnknownID) chanRead, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto DeformerDeformationItem(ILxUnknownID defItem, void **ppvObj) -> LxResult
    {
        return m_loc[0]->DeformerDeformationItem(m_loc,(ILxUnknownID) defItem, ppvObj);
    }

    auto DeformerDeformationItem(ILxUnknownID defItem, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->DeformerDeformationItem(m_loc,(ILxUnknownID) defItem, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto InvalidateTargets(ILxUnknownID scene) -> void
    {
        m_loc[0]->InvalidateTargets(m_loc,(ILxUnknownID) scene);
    }

    auto ItemToDeformElt(ILxUnknownID item) -> LXtDeformElt
    {
        return m_loc[0]->ItemToDeformElt(m_loc,(ILxUnknownID) item);
    }

    auto DeformEltToItem(LXtDeformElt elt) -> ILxUnknownID
    {
        return (ILxUnknownID)m_loc[0]->DeformEltToItem(m_loc, elt);
    }

    auto StackTargetCount(ILxUnknownID defItem, unsigned *count) -> LxResult
    {
        return m_loc[0]->StackTargetCount(m_loc,(ILxUnknownID) defItem, count);
    }

    auto StackTargetByIndex(ILxUnknownID defItem, unsigned index, void **ppvObj) -> LxResult
    {
        return m_loc[0]->StackTargetByIndex(m_loc,(ILxUnknownID) defItem, index, ppvObj);
    }

    auto StackTargetByIndex(ILxUnknownID defItem, unsigned index, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->StackTargetByIndex(m_loc,(ILxUnknownID) defItem, index, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
