//
// C++ wrapper for lxsdk/lxpoly.h.
//
//	Copyright 2024.
//
//
#pragma once

#include <lxpoly.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx
{
    static LXtGUID const guid_SUBDPolyType = {0x3441291E, {0x3686, 0x42F1}, {0xA4, 0xCA, 0x71, 0xFC, 0x4A, 0xE5, 0x24, 0x3A}};
    static LXtGUID const guid_Subdivision = {0x0910EEE5, {0x01DF, 0x4120}, {0xB6, 0x64, 0xE8, 0x04, 0xCA, 0xC3, 0x8A, 0xF5}};
} // namespace lx


class CLxImpl_Subdivision
{
public:
    virtual ~CLxImpl_Subdivision() = default;

    virtual auto subdiv_Validate([[maybe_unused]] ILxUnknownID mesh) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto subdiv_Refine([[maybe_unused]] ILxUnknownID mesh) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual void subdiv_InvalidateTopology([[maybe_unused]] void)
    {
    }

    virtual void subdiv_InvalidatePosition([[maybe_unused]] void)
    {
    }

    virtual int subdiv_Status(void) = 0;

    virtual int subdiv_MaxLevel(void) = 0;

    virtual int subdiv_SetMaxLevel(int level) = 0;

    virtual int subdiv_BoundaryRule(void) = 0;

    virtual int subdiv_SetBoundaryRule(int bound) = 0;

    virtual int subdiv_UVBoundaryRule(void) = 0;

    virtual int subdiv_SetUVBoundaryRule(int bound) = 0;

    virtual int subdiv_Scheme(void) = 0;

    virtual int subdiv_SetScheme(int scheme) = 0;

    virtual int subdiv_Backend(void) = 0;

    virtual int subdiv_SetBackend(int backend) = 0;

    virtual int subdiv_Adaptive(void) = 0;

    virtual int subdiv_SetAdaptive(int adaptive) = 0;

    virtual int subdiv_NumFaces(void) = 0;

    virtual int subdiv_FaceDepth(int faceIndex) = 0;

    virtual int subdiv_NumVerticesOfFace(int faceIndex) = 0;

    virtual int subdiv_VertexOfFace(int faceIndex, int vertofface) = 0;

    virtual int subdiv_NumLevelFaces(int level) = 0;

    virtual int subdiv_FirstFaceOffset(int level) = 0;

    virtual int subdiv_ChildFace(int faceIndex, int vertOfFace) = 0;

    virtual int subdiv_ParentFace(int faceIndex) = 0;

    virtual LXtPolygonID subdiv_PolygonID(int faceIndex) = 0;

    virtual int subdiv_PolygonFace(LXtPolygonID polyID) = 0;

    virtual int subdiv_NumVertices(void) = 0;

    virtual int subdiv_NumLevelVertices(int level) = 0;

    virtual int subdiv_FirstVertexOffset(int level) = 0;

    virtual int subdiv_ParentVertex(int vertIndex) = 0;

    virtual float * subdiv_VertexPosition(int vertIndex) = 0;

    virtual float * subdiv_VertexNormal(int vertIndex) = 0;

    virtual int subdiv_AddUVMap(const char *name) = 0;

    virtual int subdiv_NumUVMap(void) = 0;

    virtual const char * subdiv_UVMapName(int mapIndex) = 0;

    virtual int subdiv_LookupUVMap(const char *name) = 0;

    virtual float * subdiv_GetUV(int mapIndex, int faceIndex, int vertOfFace) = 0;
};

#define LXxD_Subdivision_Validate LxResult subdiv_Validate([[maybe_unused]] ILxUnknownID mesh) override
#define LXxO_Subdivision_Validate LXxD_Subdivision_Validate
#define LXxC_Subdivision_Validate(c) LxResult c::subdiv_Validate([[maybe_unused]] ILxUnknownID mesh)
#define LXxD_Subdivision_Refine LxResult subdiv_Refine([[maybe_unused]] ILxUnknownID mesh) override
#define LXxO_Subdivision_Refine LXxD_Subdivision_Refine
#define LXxC_Subdivision_Refine(c) LxResult c::subdiv_Refine([[maybe_unused]] ILxUnknownID mesh)
#define LXxD_Subdivision_InvalidateTopology void subdiv_InvalidateTopology() override
#define LXxO_Subdivision_InvalidateTopology LXxD_Subdivision_InvalidateTopology
#define LXxC_Subdivision_InvalidateTopology(c) void c::subdiv_InvalidateTopology()
#define LXxD_Subdivision_InvalidatePosition void subdiv_InvalidatePosition() override
#define LXxO_Subdivision_InvalidatePosition LXxD_Subdivision_InvalidatePosition
#define LXxC_Subdivision_InvalidatePosition(c) void c::subdiv_InvalidatePosition()
#define LXxD_Subdivision_Status int subdiv_Status() override
#define LXxO_Subdivision_Status LXxD_Subdivision_Status
#define LXxC_Subdivision_Status(c) int c::subdiv_Status()
#define LXxD_Subdivision_MaxLevel int subdiv_MaxLevel() override
#define LXxO_Subdivision_MaxLevel LXxD_Subdivision_MaxLevel
#define LXxC_Subdivision_MaxLevel(c) int c::subdiv_MaxLevel()
#define LXxD_Subdivision_SetMaxLevel int subdiv_SetMaxLevel([[maybe_unused]] int level) override
#define LXxO_Subdivision_SetMaxLevel LXxD_Subdivision_SetMaxLevel
#define LXxC_Subdivision_SetMaxLevel(c) int c::subdiv_SetMaxLevel([[maybe_unused]] int level)
#define LXxD_Subdivision_BoundaryRule int subdiv_BoundaryRule() override
#define LXxO_Subdivision_BoundaryRule LXxD_Subdivision_BoundaryRule
#define LXxC_Subdivision_BoundaryRule(c) int c::subdiv_BoundaryRule()
#define LXxD_Subdivision_SetBoundaryRule int subdiv_SetBoundaryRule([[maybe_unused]] int bound) override
#define LXxO_Subdivision_SetBoundaryRule LXxD_Subdivision_SetBoundaryRule
#define LXxC_Subdivision_SetBoundaryRule(c) int c::subdiv_SetBoundaryRule([[maybe_unused]] int bound)
#define LXxD_Subdivision_UVBoundaryRule int subdiv_UVBoundaryRule() override
#define LXxO_Subdivision_UVBoundaryRule LXxD_Subdivision_UVBoundaryRule
#define LXxC_Subdivision_UVBoundaryRule(c) int c::subdiv_UVBoundaryRule()
#define LXxD_Subdivision_SetUVBoundaryRule int subdiv_SetUVBoundaryRule([[maybe_unused]] int bound) override
#define LXxO_Subdivision_SetUVBoundaryRule LXxD_Subdivision_SetUVBoundaryRule
#define LXxC_Subdivision_SetUVBoundaryRule(c) int c::subdiv_SetUVBoundaryRule([[maybe_unused]] int bound)
#define LXxD_Subdivision_Scheme int subdiv_Scheme() override
#define LXxO_Subdivision_Scheme LXxD_Subdivision_Scheme
#define LXxC_Subdivision_Scheme(c) int c::subdiv_Scheme()
#define LXxD_Subdivision_SetScheme int subdiv_SetScheme([[maybe_unused]] int scheme) override
#define LXxO_Subdivision_SetScheme LXxD_Subdivision_SetScheme
#define LXxC_Subdivision_SetScheme(c) int c::subdiv_SetScheme([[maybe_unused]] int scheme)
#define LXxD_Subdivision_Backend int subdiv_Backend() override
#define LXxO_Subdivision_Backend LXxD_Subdivision_Backend
#define LXxC_Subdivision_Backend(c) int c::subdiv_Backend()
#define LXxD_Subdivision_SetBackend int subdiv_SetBackend([[maybe_unused]] int backend) override
#define LXxO_Subdivision_SetBackend LXxD_Subdivision_SetBackend
#define LXxC_Subdivision_SetBackend(c) int c::subdiv_SetBackend([[maybe_unused]] int backend)
#define LXxD_Subdivision_Adaptive int subdiv_Adaptive() override
#define LXxO_Subdivision_Adaptive LXxD_Subdivision_Adaptive
#define LXxC_Subdivision_Adaptive(c) int c::subdiv_Adaptive()
#define LXxD_Subdivision_SetAdaptive int subdiv_SetAdaptive([[maybe_unused]] int adaptive) override
#define LXxO_Subdivision_SetAdaptive LXxD_Subdivision_SetAdaptive
#define LXxC_Subdivision_SetAdaptive(c) int c::subdiv_SetAdaptive([[maybe_unused]] int adaptive)
#define LXxD_Subdivision_NumFaces int subdiv_NumFaces() override
#define LXxO_Subdivision_NumFaces LXxD_Subdivision_NumFaces
#define LXxC_Subdivision_NumFaces(c) int c::subdiv_NumFaces()
#define LXxD_Subdivision_FaceDepth int subdiv_FaceDepth([[maybe_unused]] int faceIndex) override
#define LXxO_Subdivision_FaceDepth LXxD_Subdivision_FaceDepth
#define LXxC_Subdivision_FaceDepth(c) int c::subdiv_FaceDepth([[maybe_unused]] int faceIndex)
#define LXxD_Subdivision_NumVerticesOfFace int subdiv_NumVerticesOfFace([[maybe_unused]] int faceIndex) override
#define LXxO_Subdivision_NumVerticesOfFace LXxD_Subdivision_NumVerticesOfFace
#define LXxC_Subdivision_NumVerticesOfFace(c) int c::subdiv_NumVerticesOfFace([[maybe_unused]] int faceIndex)
#define LXxD_Subdivision_VertexOfFace int subdiv_VertexOfFace([[maybe_unused]] int faceIndex, [[maybe_unused]] int vertofface) override
#define LXxO_Subdivision_VertexOfFace LXxD_Subdivision_VertexOfFace
#define LXxC_Subdivision_VertexOfFace(c) int c::subdiv_VertexOfFace([[maybe_unused]] int faceIndex, [[maybe_unused]] int vertofface)
#define LXxD_Subdivision_NumLevelFaces int subdiv_NumLevelFaces([[maybe_unused]] int level) override
#define LXxO_Subdivision_NumLevelFaces LXxD_Subdivision_NumLevelFaces
#define LXxC_Subdivision_NumLevelFaces(c) int c::subdiv_NumLevelFaces([[maybe_unused]] int level)
#define LXxD_Subdivision_FirstFaceOffset int subdiv_FirstFaceOffset([[maybe_unused]] int level) override
#define LXxO_Subdivision_FirstFaceOffset LXxD_Subdivision_FirstFaceOffset
#define LXxC_Subdivision_FirstFaceOffset(c) int c::subdiv_FirstFaceOffset([[maybe_unused]] int level)
#define LXxD_Subdivision_ChildFace int subdiv_ChildFace([[maybe_unused]] int faceIndex, [[maybe_unused]] int vertOfFace) override
#define LXxO_Subdivision_ChildFace LXxD_Subdivision_ChildFace
#define LXxC_Subdivision_ChildFace(c) int c::subdiv_ChildFace([[maybe_unused]] int faceIndex, [[maybe_unused]] int vertOfFace)
#define LXxD_Subdivision_ParentFace int subdiv_ParentFace([[maybe_unused]] int faceIndex) override
#define LXxO_Subdivision_ParentFace LXxD_Subdivision_ParentFace
#define LXxC_Subdivision_ParentFace(c) int c::subdiv_ParentFace([[maybe_unused]] int faceIndex)
#define LXxD_Subdivision_PolygonID LXtPolygonID subdiv_PolygonID([[maybe_unused]] int faceIndex) override
#define LXxO_Subdivision_PolygonID LXxD_Subdivision_PolygonID
#define LXxC_Subdivision_PolygonID(c) LXtPolygonID c::subdiv_PolygonID([[maybe_unused]] int faceIndex)
#define LXxD_Subdivision_PolygonFace int subdiv_PolygonFace([[maybe_unused]] LXtPolygonID polyID) override
#define LXxO_Subdivision_PolygonFace LXxD_Subdivision_PolygonFace
#define LXxC_Subdivision_PolygonFace(c) int c::subdiv_PolygonFace([[maybe_unused]] LXtPolygonID polyID)
#define LXxD_Subdivision_NumVertices int subdiv_NumVertices() override
#define LXxO_Subdivision_NumVertices LXxD_Subdivision_NumVertices
#define LXxC_Subdivision_NumVertices(c) int c::subdiv_NumVertices()
#define LXxD_Subdivision_NumLevelVertices int subdiv_NumLevelVertices([[maybe_unused]] int level) override
#define LXxO_Subdivision_NumLevelVertices LXxD_Subdivision_NumLevelVertices
#define LXxC_Subdivision_NumLevelVertices(c) int c::subdiv_NumLevelVertices([[maybe_unused]] int level)
#define LXxD_Subdivision_FirstVertexOffset int subdiv_FirstVertexOffset([[maybe_unused]] int level) override
#define LXxO_Subdivision_FirstVertexOffset LXxD_Subdivision_FirstVertexOffset
#define LXxC_Subdivision_FirstVertexOffset(c) int c::subdiv_FirstVertexOffset([[maybe_unused]] int level)
#define LXxD_Subdivision_ParentVertex int subdiv_ParentVertex([[maybe_unused]] int vertIndex) override
#define LXxO_Subdivision_ParentVertex LXxD_Subdivision_ParentVertex
#define LXxC_Subdivision_ParentVertex(c) int c::subdiv_ParentVertex([[maybe_unused]] int vertIndex)
#define LXxD_Subdivision_VertexPosition float * subdiv_VertexPosition([[maybe_unused]] int vertIndex) override
#define LXxO_Subdivision_VertexPosition LXxD_Subdivision_VertexPosition
#define LXxC_Subdivision_VertexPosition(c) float * c::subdiv_VertexPosition([[maybe_unused]] int vertIndex)
#define LXxD_Subdivision_VertexNormal float * subdiv_VertexNormal([[maybe_unused]] int vertIndex) override
#define LXxO_Subdivision_VertexNormal LXxD_Subdivision_VertexNormal
#define LXxC_Subdivision_VertexNormal(c) float * c::subdiv_VertexNormal([[maybe_unused]] int vertIndex)
#define LXxD_Subdivision_AddUVMap int subdiv_AddUVMap([[maybe_unused]] const char *name) override
#define LXxO_Subdivision_AddUVMap LXxD_Subdivision_AddUVMap
#define LXxC_Subdivision_AddUVMap(c) int c::subdiv_AddUVMap([[maybe_unused]] const char *name)
#define LXxD_Subdivision_NumUVMap int subdiv_NumUVMap() override
#define LXxO_Subdivision_NumUVMap LXxD_Subdivision_NumUVMap
#define LXxC_Subdivision_NumUVMap(c) int c::subdiv_NumUVMap()
#define LXxD_Subdivision_UVMapName const char * subdiv_UVMapName([[maybe_unused]] int mapIndex) override
#define LXxO_Subdivision_UVMapName LXxD_Subdivision_UVMapName
#define LXxC_Subdivision_UVMapName(c) const char * c::subdiv_UVMapName([[maybe_unused]] int mapIndex)
#define LXxD_Subdivision_LookupUVMap int subdiv_LookupUVMap([[maybe_unused]] const char *name) override
#define LXxO_Subdivision_LookupUVMap LXxD_Subdivision_LookupUVMap
#define LXxC_Subdivision_LookupUVMap(c) int c::subdiv_LookupUVMap([[maybe_unused]] const char *name)
#define LXxD_Subdivision_GetUV float * subdiv_GetUV([[maybe_unused]] int mapIndex, [[maybe_unused]] int faceIndex, [[maybe_unused]] int vertOfFace) override
#define LXxO_Subdivision_GetUV LXxD_Subdivision_GetUV
#define LXxC_Subdivision_GetUV(c) float * c::subdiv_GetUV([[maybe_unused]] int mapIndex, [[maybe_unused]] int faceIndex, [[maybe_unused]] int vertOfFace)

template <class T>
class CLxIfc_Subdivision: public CLxInterface
{
public:
    CLxIfc_Subdivision()
    {
        vt.Validate = Validate;
        vt.Refine = Refine;
        vt.InvalidateTopology = InvalidateTopology;
        vt.InvalidatePosition = InvalidatePosition;
        vt.Status = Status;
        vt.MaxLevel = MaxLevel;
        vt.SetMaxLevel = SetMaxLevel;
        vt.BoundaryRule = BoundaryRule;
        vt.SetBoundaryRule = SetBoundaryRule;
        vt.UVBoundaryRule = UVBoundaryRule;
        vt.SetUVBoundaryRule = SetUVBoundaryRule;
        vt.Scheme = Scheme;
        vt.SetScheme = SetScheme;
        vt.Backend = Backend;
        vt.SetBackend = SetBackend;
        vt.Adaptive = Adaptive;
        vt.SetAdaptive = SetAdaptive;
        vt.NumFaces = NumFaces;
        vt.FaceDepth = FaceDepth;
        vt.NumVerticesOfFace = NumVerticesOfFace;
        vt.VertexOfFace = VertexOfFace;
        vt.NumLevelFaces = NumLevelFaces;
        vt.FirstFaceOffset = FirstFaceOffset;
        vt.ChildFace = ChildFace;
        vt.ParentFace = ParentFace;
        vt.PolygonID = PolygonID;
        vt.PolygonFace = PolygonFace;
        vt.NumVertices = NumVertices;
        vt.NumLevelVertices = NumLevelVertices;
        vt.FirstVertexOffset = FirstVertexOffset;
        vt.ParentVertex = ParentVertex;
        vt.VertexPosition = VertexPosition;
        vt.VertexNormal = VertexNormal;
        vt.AddUVMap = AddUVMap;
        vt.NumUVMap = NumUVMap;
        vt.UVMapName = UVMapName;
        vt.LookupUVMap = LookupUVMap;
        vt.GetUV = GetUV;
        vTable = &vt.iunk;
        iid = &lx::guid_Subdivision;
    }

    static auto Validate(LXtObjectID wcom,LXtObjectID mesh) -> LxResult
    {
        LXCWxINST (CLxImpl_Subdivision, loc);
        try
        {
           return loc->subdiv_Validate((ILxUnknownID) mesh);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Refine(LXtObjectID wcom,LXtObjectID mesh) -> LxResult
    {
        LXCWxINST (CLxImpl_Subdivision, loc);
        try
        {
           return loc->subdiv_Refine((ILxUnknownID) mesh);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto InvalidateTopology(LXtObjectID wcom) -> void
    {
        LXCWxINST (CLxImpl_Subdivision, loc);
        loc->subdiv_InvalidateTopology();
    }

    static auto InvalidatePosition(LXtObjectID wcom) -> void
    {
        LXCWxINST (CLxImpl_Subdivision, loc);
        loc->subdiv_InvalidatePosition();
    }

    static auto Status(LXtObjectID wcom) -> int
    {
        LXCWxINST (CLxImpl_Subdivision, loc);
        return loc->subdiv_Status();
    }

    static auto MaxLevel(LXtObjectID wcom) -> int
    {
        LXCWxINST (CLxImpl_Subdivision, loc);
        return loc->subdiv_MaxLevel();
    }

    static auto SetMaxLevel(LXtObjectID wcom,int level) -> int
    {
        LXCWxINST (CLxImpl_Subdivision, loc);
        return loc->subdiv_SetMaxLevel( level);
    }

    static auto BoundaryRule(LXtObjectID wcom) -> int
    {
        LXCWxINST (CLxImpl_Subdivision, loc);
        return loc->subdiv_BoundaryRule();
    }

    static auto SetBoundaryRule(LXtObjectID wcom,int bound) -> int
    {
        LXCWxINST (CLxImpl_Subdivision, loc);
        return loc->subdiv_SetBoundaryRule( bound);
    }

    static auto UVBoundaryRule(LXtObjectID wcom) -> int
    {
        LXCWxINST (CLxImpl_Subdivision, loc);
        return loc->subdiv_UVBoundaryRule();
    }

    static auto SetUVBoundaryRule(LXtObjectID wcom,int bound) -> int
    {
        LXCWxINST (CLxImpl_Subdivision, loc);
        return loc->subdiv_SetUVBoundaryRule( bound);
    }

    static auto Scheme(LXtObjectID wcom) -> int
    {
        LXCWxINST (CLxImpl_Subdivision, loc);
        return loc->subdiv_Scheme();
    }

    static auto SetScheme(LXtObjectID wcom,int scheme) -> int
    {
        LXCWxINST (CLxImpl_Subdivision, loc);
        return loc->subdiv_SetScheme( scheme);
    }

    static auto Backend(LXtObjectID wcom) -> int
    {
        LXCWxINST (CLxImpl_Subdivision, loc);
        return loc->subdiv_Backend();
    }

    static auto SetBackend(LXtObjectID wcom,int backend) -> int
    {
        LXCWxINST (CLxImpl_Subdivision, loc);
        return loc->subdiv_SetBackend( backend);
    }

    static auto Adaptive(LXtObjectID wcom) -> int
    {
        LXCWxINST (CLxImpl_Subdivision, loc);
        return loc->subdiv_Adaptive();
    }

    static auto SetAdaptive(LXtObjectID wcom,int adaptive) -> int
    {
        LXCWxINST (CLxImpl_Subdivision, loc);
        return loc->subdiv_SetAdaptive( adaptive);
    }

    static auto NumFaces(LXtObjectID wcom) -> int
    {
        LXCWxINST (CLxImpl_Subdivision, loc);
        return loc->subdiv_NumFaces();
    }

    static auto FaceDepth(LXtObjectID wcom,int faceIndex) -> int
    {
        LXCWxINST (CLxImpl_Subdivision, loc);
        return loc->subdiv_FaceDepth( faceIndex);
    }

    static auto NumVerticesOfFace(LXtObjectID wcom,int faceIndex) -> int
    {
        LXCWxINST (CLxImpl_Subdivision, loc);
        return loc->subdiv_NumVerticesOfFace( faceIndex);
    }

    static auto VertexOfFace(LXtObjectID wcom,int faceIndex,int vertofface) -> int
    {
        LXCWxINST (CLxImpl_Subdivision, loc);
        return loc->subdiv_VertexOfFace( faceIndex, vertofface);
    }

    static auto NumLevelFaces(LXtObjectID wcom,int level) -> int
    {
        LXCWxINST (CLxImpl_Subdivision, loc);
        return loc->subdiv_NumLevelFaces( level);
    }

    static auto FirstFaceOffset(LXtObjectID wcom,int level) -> int
    {
        LXCWxINST (CLxImpl_Subdivision, loc);
        return loc->subdiv_FirstFaceOffset( level);
    }

    static auto ChildFace(LXtObjectID wcom,int faceIndex,int vertOfFace) -> int
    {
        LXCWxINST (CLxImpl_Subdivision, loc);
        return loc->subdiv_ChildFace( faceIndex, vertOfFace);
    }

    static auto ParentFace(LXtObjectID wcom,int faceIndex) -> int
    {
        LXCWxINST (CLxImpl_Subdivision, loc);
        return loc->subdiv_ParentFace( faceIndex);
    }

    static auto PolygonID(LXtObjectID wcom,int faceIndex) -> LXtPolygonID
    {
        LXCWxINST (CLxImpl_Subdivision, loc);
        return loc->subdiv_PolygonID( faceIndex);
    }

    static auto PolygonFace(LXtObjectID wcom,LXtPolygonID polyID) -> int
    {
        LXCWxINST (CLxImpl_Subdivision, loc);
        return loc->subdiv_PolygonFace( polyID);
    }

    static auto NumVertices(LXtObjectID wcom) -> int
    {
        LXCWxINST (CLxImpl_Subdivision, loc);
        return loc->subdiv_NumVertices();
    }

    static auto NumLevelVertices(LXtObjectID wcom,int level) -> int
    {
        LXCWxINST (CLxImpl_Subdivision, loc);
        return loc->subdiv_NumLevelVertices( level);
    }

    static auto FirstVertexOffset(LXtObjectID wcom,int level) -> int
    {
        LXCWxINST (CLxImpl_Subdivision, loc);
        return loc->subdiv_FirstVertexOffset( level);
    }

    static auto ParentVertex(LXtObjectID wcom,int vertIndex) -> int
    {
        LXCWxINST (CLxImpl_Subdivision, loc);
        return loc->subdiv_ParentVertex( vertIndex);
    }

    static auto VertexPosition(LXtObjectID wcom,int vertIndex) -> float *
    {
        LXCWxINST (CLxImpl_Subdivision, loc);
        return loc->subdiv_VertexPosition( vertIndex);
    }

    static auto VertexNormal(LXtObjectID wcom,int vertIndex) -> float *
    {
        LXCWxINST (CLxImpl_Subdivision, loc);
        return loc->subdiv_VertexNormal( vertIndex);
    }

    static auto AddUVMap(LXtObjectID wcom,const char *name) -> int
    {
        LXCWxINST (CLxImpl_Subdivision, loc);
        return loc->subdiv_AddUVMap( name);
    }

    static auto NumUVMap(LXtObjectID wcom) -> int
    {
        LXCWxINST (CLxImpl_Subdivision, loc);
        return loc->subdiv_NumUVMap();
    }

    static auto UVMapName(LXtObjectID wcom,int mapIndex) -> const char *
    {
        LXCWxINST (CLxImpl_Subdivision, loc);
        return loc->subdiv_UVMapName( mapIndex);
    }

    static auto LookupUVMap(LXtObjectID wcom,const char *name) -> int
    {
        LXCWxINST (CLxImpl_Subdivision, loc);
        return loc->subdiv_LookupUVMap( name);
    }

    static auto GetUV(LXtObjectID wcom,int mapIndex,int faceIndex,int vertOfFace) -> float *
    {
        LXCWxINST (CLxImpl_Subdivision, loc);
        return loc->subdiv_GetUV( mapIndex, faceIndex, vertOfFace);
    }

private:
    ILxSubdivision vt;
};

class CLxLoc_Subdivision : public CLxLocalize<ILxSubdivisionID>
{
public:
    CLxLoc_Subdivision()
    {
        _init();
    }

    CLxLoc_Subdivision(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_Subdivision(CLxLoc_Subdivision const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_Subdivision;
    }

    auto Validate(ILxUnknownID mesh) -> LxResult
    {
        return m_loc[0]->Validate(m_loc,(ILxUnknownID) mesh);
    }

    auto Refine(ILxUnknownID mesh) -> LxResult
    {
        return m_loc[0]->Refine(m_loc,(ILxUnknownID) mesh);
    }

    auto InvalidateTopology(void) -> void
    {
        m_loc[0]->InvalidateTopology(m_loc);
    }

    auto InvalidatePosition(void) -> void
    {
        m_loc[0]->InvalidatePosition(m_loc);
    }

    auto Status(void) -> int
    {
        return m_loc[0]->Status(m_loc);
    }

    auto MaxLevel(void) -> int
    {
        return m_loc[0]->MaxLevel(m_loc);
    }

    auto SetMaxLevel(int level) -> int
    {
        return m_loc[0]->SetMaxLevel(m_loc, level);
    }

    auto BoundaryRule(void) -> int
    {
        return m_loc[0]->BoundaryRule(m_loc);
    }

    auto SetBoundaryRule(int bound) -> int
    {
        return m_loc[0]->SetBoundaryRule(m_loc, bound);
    }

    auto UVBoundaryRule(void) -> int
    {
        return m_loc[0]->UVBoundaryRule(m_loc);
    }

    auto SetUVBoundaryRule(int bound) -> int
    {
        return m_loc[0]->SetUVBoundaryRule(m_loc, bound);
    }

    auto Scheme(void) -> int
    {
        return m_loc[0]->Scheme(m_loc);
    }

    auto SetScheme(int scheme) -> int
    {
        return m_loc[0]->SetScheme(m_loc, scheme);
    }

    auto Backend(void) -> int
    {
        return m_loc[0]->Backend(m_loc);
    }

    auto SetBackend(int backend) -> int
    {
        return m_loc[0]->SetBackend(m_loc, backend);
    }

    auto Adaptive(void) -> int
    {
        return m_loc[0]->Adaptive(m_loc);
    }

    auto SetAdaptive(int adaptive) -> int
    {
        return m_loc[0]->SetAdaptive(m_loc, adaptive);
    }

    auto NumFaces(void) -> int
    {
        return m_loc[0]->NumFaces(m_loc);
    }

    auto FaceDepth(int faceIndex) -> int
    {
        return m_loc[0]->FaceDepth(m_loc, faceIndex);
    }

    auto NumVerticesOfFace(int faceIndex) -> int
    {
        return m_loc[0]->NumVerticesOfFace(m_loc, faceIndex);
    }

    auto VertexOfFace(int faceIndex, int vertofface) -> int
    {
        return m_loc[0]->VertexOfFace(m_loc, faceIndex, vertofface);
    }

    auto NumLevelFaces(int level) -> int
    {
        return m_loc[0]->NumLevelFaces(m_loc, level);
    }

    auto FirstFaceOffset(int level) -> int
    {
        return m_loc[0]->FirstFaceOffset(m_loc, level);
    }

    auto ChildFace(int faceIndex, int vertOfFace) -> int
    {
        return m_loc[0]->ChildFace(m_loc, faceIndex, vertOfFace);
    }

    auto ParentFace(int faceIndex) -> int
    {
        return m_loc[0]->ParentFace(m_loc, faceIndex);
    }

    auto PolygonID(int faceIndex) -> LXtPolygonID
    {
        return m_loc[0]->PolygonID(m_loc, faceIndex);
    }

    auto PolygonFace(LXtPolygonID polyID) -> int
    {
        return m_loc[0]->PolygonFace(m_loc, polyID);
    }

    auto NumVertices(void) -> int
    {
        return m_loc[0]->NumVertices(m_loc);
    }

    auto NumLevelVertices(int level) -> int
    {
        return m_loc[0]->NumLevelVertices(m_loc, level);
    }

    auto FirstVertexOffset(int level) -> int
    {
        return m_loc[0]->FirstVertexOffset(m_loc, level);
    }

    auto ParentVertex(int vertIndex) -> int
    {
        return m_loc[0]->ParentVertex(m_loc, vertIndex);
    }

    auto VertexPosition(int vertIndex) -> float *
    {
        return m_loc[0]->VertexPosition(m_loc, vertIndex);
    }

    auto VertexNormal(int vertIndex) -> float *
    {
        return m_loc[0]->VertexNormal(m_loc, vertIndex);
    }

    auto AddUVMap(const char *name) -> int
    {
        return m_loc[0]->AddUVMap(m_loc, name);
    }

    auto NumUVMap(void) -> int
    {
        return m_loc[0]->NumUVMap(m_loc);
    }

    auto UVMapName(int mapIndex) -> const char *
    {
        return m_loc[0]->UVMapName(m_loc, mapIndex);
    }

    auto LookupUVMap(const char *name) -> int
    {
        return m_loc[0]->LookupUVMap(m_loc, name);
    }

    auto GetUV(int mapIndex, int faceIndex, int vertOfFace) -> float *
    {
        return m_loc[0]->GetUV(m_loc, mapIndex, faceIndex, vertOfFace);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
