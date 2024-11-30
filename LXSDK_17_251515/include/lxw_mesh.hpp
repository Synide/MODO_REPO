//
// C++ wrapper for lxsdk/lxmesh.h.
//
//	Copyright 2024.
//
//
#pragma once

#include <lxmesh.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx
{
    static LXtGUID const guid_MeshService = {0x82B739EC, {0xF92E, 0x4CC9}, {0xA5, 0xFB, 0x58, 0x4A, 0x86, 0x6D, 0x58, 0x97}};
    static LXtGUID const guid_Mesh = {0x8C7F1CF3, {0x8CE8, 0x4395}, {0x93, 0x24, 0xA1, 0x6D, 0xD6, 0x3B, 0x4A, 0xFE}};
    static LXtGUID const guid_Mesh1 = {0xA9E30646, {0xD729, 0x4850}, {0xB4, 0xC4, 0xF0, 0x0A, 0x5E, 0x93, 0xFE, 0x25}};
    static LXtGUID const guid_Mesh2 = {0x1F1BB7BF, {0xA862, 0x4810}, {0x95, 0xFF, 0x33, 0x46, 0xAF, 0x73, 0x82, 0x09}};
    static LXtGUID const guid_Point = {0x37B477FE, {0xED3C, 0x4EDC}, {0xA4, 0xA8, 0x9B, 0xB2, 0x4F, 0x58, 0xA4, 0xE6}};
    static LXtGUID const guid_Polygon = {0xDD64141D, {0xDC92, 0x4348}, {0xB4, 0x5B, 0xF7, 0x3F, 0xC6, 0x4F, 0x1E, 0x52}};
    static LXtGUID const guid_Polygon1 = {0x5839056D, {0x28BF, 0x4D72}, {0x8A, 0x26, 0xE4, 0xAA, 0x00, 0xDA, 0x78, 0x8F}};
    static LXtGUID const guid_Edge = {0x19A44432, {0xE2CF, 0x4BCF}, {0x9E, 0xA6, 0xD6, 0x96, 0xE7, 0xA0, 0xF1, 0x6E}};
    static LXtGUID const guid_MeshMap = {0x2AEBA454, {0x2AC4, 0x4F1E}, {0xB8, 0x92, 0x7A, 0x16, 0xF7, 0x60, 0x10, 0x30}};
    static LXtGUID const guid_MeshListener = {0x9373A003, {0xBEBC, 0x44D4}, {0xAD, 0xEB, 0x36, 0x86, 0x2F, 0x0A, 0xFC, 0x38}};
    static LXtGUID const guid_MeshListener1 = {0x957900AC, {0xBC06, 0x45D9}, {0xB1, 0xB1, 0x9C, 0xC5, 0xA2, 0xAE, 0xC0, 0x26}};
    static LXtGUID const guid_MeshTracker = {0x8FAD284F, {0xC289, 0x40AB}, {0x97, 0xD2, 0x63, 0x93, 0x23, 0x85, 0xBA, 0xB6}};
    static LXtGUID const guid_MeshOperation = {0x8B72A28C, {0x6C2C, 0x4E9C}, {0x82, 0x42, 0x7D, 0x13, 0xAE, 0x80, 0x00, 0x8E}};
    static LXtGUID const guid_MeshOperation2 = {0x71D124CB, {0x8D2A, 0x4E5A}, {0x81, 0x4D, 0x39, 0x21, 0xD9, 0x98, 0x6D, 0x3A}};
    static LXtGUID const guid_MeshOperation1 = {0x98103095, {0x54AC, 0x45CD}, {0x86, 0x85, 0x84, 0x61, 0x4D, 0x99, 0x6A, 0xC2}};
    static LXtGUID const guid_MeshFilter = {0x9AA6236A, {0xCF0F, 0x4E72}, {0xB8, 0xF3, 0x20, 0xBB, 0xC5, 0x53, 0x2B, 0x61}};
    static LXtGUID const guid_MeshFilter1 = {0xF5896BA1, {0x7EC5, 0x4EE9}, {0x85, 0x2F, 0xBF, 0x97, 0x7E, 0x45, 0x19, 0x53}};
    static LXtGUID const guid_MeshFilterBBox = {0xFBD83166, {0x4B50, 0x42A0}, {0x8C, 0x91, 0xC3, 0x6D, 0x3B, 0xB7, 0x69, 0x04}};
    static LXtGUID const guid_MeshFilterIdent = {0x68713DE3, {0x45D8, 0x4722}, {0xBC, 0x43, 0xD0, 0x3E, 0xF4, 0x96, 0x4A, 0xB8}};
    static LXtGUID const guid_MeshFilterBlend = {0x590F4482, {0x3EDE, 0x47DB}, {0xA2, 0x60, 0x65, 0x1B, 0x68, 0x7D, 0x2B, 0x1E}};
    static LXtGUID const guid_MeshBlend = {0xE4690A09, {0x96B9, 0x40CB}, {0xB2, 0x64, 0xAB, 0x90, 0x0B, 0xF1, 0xD9, 0x89}};
    static LXtGUID const guid_MeshMetaData = {0x2C6633EE, {0xBFB0, 0x41B5}, {0xBB, 0x36, 0x2B, 0x1E, 0xBE, 0x31, 0x0D, 0x3E}};
    static LXtGUID const guid_MeshXtraData = {0xA9CC9F05, {0xAB4F, 0x45AD}, {0xAE, 0xB0, 0xF3, 0xA2, 0xD1, 0xF6, 0x6A, 0x98}};
} // namespace lx

class CLxLoc_MeshService : public CLxLocalizedService
{
public:
    ILxMeshServiceID m_loc{ nullptr };

public:
    CLxLoc_MeshService()
    {
        _init();
        set();
    }

    ~CLxLoc_MeshService() = default;

    void set()
    {
        if (!m_loc)
        {
            m_loc = reinterpret_cast<ILxMeshServiceID>(lx::GetGlobal(&lx::guid_MeshService));
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

    auto ModeCompose(const char *set, const char *clear, LXtMarkMode *mode) -> LxResult
    {
        return m_loc[0]->ModeCompose(m_loc, set, clear, mode);
    }

    auto VMapLookupType(const char *name, LXtID4 *type) -> LxResult
    {
        return m_loc[0]->VMapLookupType(m_loc, name, type);
    }

    auto VMapLookupName(LXtID4 type, const char **name) -> LxResult
    {
        return m_loc[0]->VMapLookupName(m_loc, type, name);
    }

    auto VMapDimension(LXtID4 type, unsigned int *dimension) -> LxResult
    {
        return m_loc[0]->VMapDimension(m_loc, type, dimension);
    }

    auto VMapIsEdgeMap(LXtID4 type) -> LxResult
    {
        return m_loc[0]->VMapIsEdgeMap(m_loc, type);
    }

    auto VMapIsContinuous(LXtID4 type) -> LxResult
    {
        return m_loc[0]->VMapIsContinuous(m_loc, type);
    }

    auto VMapZeroDefault(LXtID4 type) -> LxResult
    {
        return m_loc[0]->VMapZeroDefault(m_loc, type);
    }

    auto CreateMesh(void **ppvObj) -> LxResult
    {
        return m_loc[0]->CreateMesh(m_loc, ppvObj);
    }

    auto CreateMesh(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->CreateMesh(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto ConvertMesh(ILxUnknownID triGroupObj, ILxUnknownID meshObj) -> LxResult
    {
        return m_loc[0]->ConvertMesh(m_loc,(ILxUnknownID) triGroupObj,(ILxUnknownID) meshObj);
    }

    auto MeshFromMeshID(LXtMeshID meshID, void **ppvObj) -> LxResult
    {
        return m_loc[0]->MeshFromMeshID(m_loc, meshID, ppvObj);
    }

    auto MeshFromMeshID(LXtMeshID meshID, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->MeshFromMeshID(m_loc, meshID, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto MeshToMeshID(ILxUnknownID mesh) -> LXtMeshID
    {
        return m_loc[0]->MeshToMeshID(m_loc,(ILxUnknownID) mesh);
    }

    auto SurfaceToTriGroup(ILxUnknownID triGroupObj, ILxUnknownID surfObj) -> LxResult
    {
        return m_loc[0]->SurfaceToTriGroup(m_loc,(ILxUnknownID) triGroupObj,(ILxUnknownID) surfObj);
    }

    auto MeshFromTriGroup(ILxUnknownID meshObj, ILxUnknownID triGroupObj) -> LxResult
    {
        return m_loc[0]->MeshFromTriGroup(m_loc,(ILxUnknownID) meshObj,(ILxUnknownID) triGroupObj);
    }

    auto TriGroupTransform(ILxUnknownID triGroupObj, LXtMatrix4 xfrm) -> LxResult
    {
        return m_loc[0]->TriGroupTransform(m_loc,(ILxUnknownID) triGroupObj, xfrm);
    }

    auto CreateSlice(void **ppvObj) -> LxResult
    {
        return m_loc[0]->CreateSlice(m_loc, ppvObj);
    }

    auto CreateSlice(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->CreateSlice(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto CreateSolidDrill(void **ppvObj) -> LxResult
    {
        return m_loc[0]->CreateSolidDrill(m_loc, ppvObj);
    }

    auto CreateSolidDrill(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->CreateSolidDrill(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto IsMeshProcedural(ILxUnknownID item) -> LxResult
    {
        return m_loc[0]->IsMeshProcedural(m_loc,(ILxUnknownID) item);
    }

    auto ItemFromMesh(ILxUnknownID mesh, void **ppvObj) -> LxResult
    {
        return m_loc[0]->ItemFromMesh(m_loc,(ILxUnknownID) mesh, ppvObj);
    }

    auto ItemFromMesh(ILxUnknownID mesh, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->ItemFromMesh(m_loc,(ILxUnknownID) mesh, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto CurveGroupFromMesh(ILxUnknownID mesh, const LXtMatrix4 xfrm, void **ppvObj) -> LxResult
    {
        return m_loc[0]->CurveGroupFromMesh(m_loc,(ILxUnknownID) mesh, xfrm, ppvObj);
    }

    auto CurveGroupFromMesh(ILxUnknownID mesh, const LXtMatrix4 xfrm, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->CurveGroupFromMesh(m_loc,(ILxUnknownID) mesh, xfrm, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto MeshFromSurface(ILxUnknownID meshObj, ILxUnknownID surfItem, ILxUnknownID surfObj) -> LxResult
    {
        return m_loc[0]->MeshFromSurface(m_loc,(ILxUnknownID) meshObj,(ILxUnknownID) surfItem,(ILxUnknownID) surfObj);
    }

    auto SurfaceFromMesh(ILxUnknownID mesh, ILxUnknownID meshItem, void **ppvObj) -> LxResult
    {
        return m_loc[0]->SurfaceFromMesh(m_loc,(ILxUnknownID) mesh,(ILxUnknownID) meshItem, ppvObj);
    }

    auto SurfaceFromMesh(ILxUnknownID mesh, ILxUnknownID meshItem, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->SurfaceFromMesh(m_loc,(ILxUnknownID) mesh,(ILxUnknownID) meshItem, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto ValidateMetaData(ILxUnknownID mesh, const char *name, void **ppvObj) -> LxResult
    {
        return m_loc[0]->ValidateMetaData(m_loc,(ILxUnknownID) mesh, name, ppvObj);
    }

    auto ValidateMetaData(ILxUnknownID mesh, const char *name, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->ValidateMetaData(m_loc,(ILxUnknownID) mesh, name, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Tessellate(ILxUnknownID meshTess, ILxUnknownID meshSource, const LXtMatrix4 xfrm, unsigned int flags) -> LxResult
    {
        return m_loc[0]->Tessellate(m_loc,(ILxUnknownID) meshTess,(ILxUnknownID) meshSource, xfrm, flags);
    }

    auto CreatePolygonEdit(void **ppvObj) -> LxResult
    {
        return m_loc[0]->CreatePolygonEdit(m_loc, ppvObj);
    }

    auto CreatePolygonEdit(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->CreatePolygonEdit(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_Mesh : public CLxLocalize<ILxMeshID>
{
public:
    CLxLoc_Mesh()
    {
        _init();
    }

    CLxLoc_Mesh(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_Mesh(CLxLoc_Mesh const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_Mesh;
    }

    auto PointCount(unsigned int *count) const -> LxResult
    {
        return m_loc[0]->PointCount(m_loc, count);
    }

    auto PolygonCount(unsigned int *count) const -> LxResult
    {
        return m_loc[0]->PolygonCount(m_loc, count);
    }

    auto EdgeCount(unsigned int *count) const -> LxResult
    {
        return m_loc[0]->EdgeCount(m_loc, count);
    }

    auto MapCount(unsigned int *count) const -> LxResult
    {
        return m_loc[0]->MapCount(m_loc, count);
    }

    auto BoundingBox(LXtMarkMode pick, LXtBBox *bbox) -> LxResult
    {
        return m_loc[0]->BoundingBox(m_loc, pick, bbox);
    }

    auto MaxPointPolygons(LXtMarkMode pick, unsigned int *count) -> LxResult
    {
        return m_loc[0]->MaxPointPolygons(m_loc, pick, count);
    }

    auto MaxPolygonSize(LXtMarkMode pick, unsigned int *count) -> LxResult
    {
        return m_loc[0]->MaxPolygonSize(m_loc, pick, count);
    }

    auto PolyTagSetDefault(LXtID4 type, const char *tag) -> LxResult
    {
        return m_loc[0]->PolyTagSetDefault(m_loc, type, tag);
    }

    auto PointAccessor(void **ppvObj) -> LxResult
    {
        return m_loc[0]->PointAccessor(m_loc, ppvObj);
    }

    auto PointAccessor(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->PointAccessor(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto PolygonAccessor(void **ppvObj) -> LxResult
    {
        return m_loc[0]->PolygonAccessor(m_loc, ppvObj);
    }

    auto PolygonAccessor(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->PolygonAccessor(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto EdgeAccessor(void **ppvObj) -> LxResult
    {
        return m_loc[0]->EdgeAccessor(m_loc, ppvObj);
    }

    auto EdgeAccessor(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->EdgeAccessor(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto MeshMapAccessor(void **ppvObj) -> LxResult
    {
        return m_loc[0]->MeshMapAccessor(m_loc, ppvObj);
    }

    auto MeshMapAccessor(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->MeshMapAccessor(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto SetMeshEdits(unsigned int edits) -> LxResult
    {
        return m_loc[0]->SetMeshEdits(m_loc, edits);
    }

    auto SUBDGetLevel(int *n) -> LxResult
    {
        return m_loc[0]->SUBDGetLevel(m_loc, n);
    }

    auto SUBDSetLevel(int n) -> LxResult
    {
        return m_loc[0]->SUBDSetLevel(m_loc, n);
    }

    auto SUBDGetLinearUV(int *isLinear) -> LxResult
    {
        return m_loc[0]->SUBDGetLinearUV(m_loc, isLinear);
    }

    auto SUBDSetLinearUV(int isLinear) -> LxResult
    {
        return m_loc[0]->SUBDSetLinearUV(m_loc, isLinear);
    }

    auto PSUBGetBoundRule(int *bound) -> LxResult
    {
        return m_loc[0]->PSUBGetBoundRule(m_loc, bound);
    }

    auto PSUBSetBoundRule(int bound) -> LxResult
    {
        return m_loc[0]->PSUBSetBoundRule(m_loc, bound);
    }

    auto TestSameMesh(ILxUnknownID other) -> LxResult
    {
        return m_loc[0]->TestSameMesh(m_loc,(ILxUnknownID) other);
    }

    auto PTagCount(LXtID4 type) -> unsigned
    {
        return m_loc[0]->PTagCount(m_loc, type);
    }

    auto PTagByIndex(LXtID4 type, unsigned index, const char **tag) -> LxResult
    {
        return m_loc[0]->PTagByIndex(m_loc, type, index, tag);
    }

    auto PSUBGetLevel(int *n) -> LxResult
    {
        return m_loc[0]->PSUBGetLevel(m_loc, n);
    }

    auto PSUBSetLevel(int n) -> LxResult
    {
        return m_loc[0]->PSUBSetLevel(m_loc, n);
    }

    auto PSUBGetCurrentLevel(int *n) -> LxResult
    {
        return m_loc[0]->PSUBGetCurrentLevel(m_loc, n);
    }

    auto PSUBSetCurrentLevel(int n) -> LxResult
    {
        return m_loc[0]->PSUBSetCurrentLevel(m_loc, n);
    }

    auto PSUBSetSubdivObj(ILxUnknownID subObj) -> LxResult
    {
        return m_loc[0]->PSUBSetSubdivObj(m_loc,(ILxUnknownID) subObj);
    }

    auto ChangeEvent(unsigned event) -> LxResult
    {
        return m_loc[0]->ChangeEvent(m_loc, event);
    }

    auto PSUBDispNumLayer(int *num) -> LxResult
    {
        return m_loc[0]->PSUBDispNumLayer(m_loc, num);
    }

    auto PSUBDispLayerName(int index) -> const char *
    {
        return m_loc[0]->PSUBDispLayerName(m_loc, index);
    }

    auto PSUBDispLayerLookupByName(const char *name, int *index) -> LxResult
    {
        return m_loc[0]->PSUBDispLayerLookupByName(m_loc, name, index);
    }

    auto PSUBDispLayerCurrent(int *index) -> LxResult
    {
        return m_loc[0]->PSUBDispLayerCurrent(m_loc, index);
    }

    auto PSUBDispLayerEnable(int index, int *enable) -> LxResult
    {
        return m_loc[0]->PSUBDispLayerEnable(m_loc, index, enable);
    }

    auto PSUBDispLayerOpacity(int index, double *opacity) -> LxResult
    {
        return m_loc[0]->PSUBDispLayerOpacity(m_loc, index, opacity);
    }

    auto PSUBDispLayerSetOpacity(int index, double opacity) -> LxResult
    {
        return m_loc[0]->PSUBDispLayerSetOpacity(m_loc, index, opacity);
    }

    auto BeginEditBatch(void) -> LxResult
    {
        return m_loc[0]->BeginEditBatch(m_loc);
    }

    auto EndEditBatch(void) -> LxResult
    {
        return m_loc[0]->EndEditBatch(m_loc);
    }

    auto Merge(ILxUnknownID other, unsigned int flags) -> LxResult
    {
        return m_loc[0]->Merge(m_loc,(ILxUnknownID) other, flags);
    }

    auto Clear(void) -> LxResult
    {
        return m_loc[0]->Clear(m_loc);
    }

    auto TrackChanges(void **ppvObj) -> LxResult
    {
        return m_loc[0]->TrackChanges(m_loc, ppvObj);
    }

    auto TrackChanges(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->TrackChanges(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto MergeWithTransform(ILxUnknownID other, const LXtMatrix4 xfrm, unsigned int flags) -> LxResult
    {
        return m_loc[0]->MergeWithTransform(m_loc,(ILxUnknownID) other, xfrm, flags);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};


class CLxLoc_Point : public CLxLocalize<ILxPointID>
{
public:
    CLxLoc_Point()
    {
        _init();
    }

    CLxLoc_Point(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_Point(CLxLoc_Point const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_Point;
    }

    auto Spawn(void **ppvObj) -> LxResult
    {
        return m_loc[0]->Spawn(m_loc, ppvObj);
    }

    auto Spawn(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Spawn(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Enumerate(LXtMarkMode mode, ILxUnknownID visitor, ILxUnknownID monitor) -> LxResult
    {
        return m_loc[0]->Enumerate(m_loc, mode,(ILxUnknownID) visitor,(ILxUnknownID) monitor);
    }

    auto TestMarks(LXtMarkMode mode) -> LxResult
    {
        return m_loc[0]->TestMarks(m_loc, mode);
    }

    auto SetMarks(LXtMarkMode set) -> LxResult
    {
        return m_loc[0]->SetMarks(m_loc, set);
    }

    auto Select(LXtPointID point) -> LxResult
    {
        return m_loc[0]->Select(m_loc, point);
    }

    auto SelectByIndex(unsigned int index) -> LxResult
    {
        return m_loc[0]->SelectByIndex(m_loc, index);
    }

    auto SelectPolygonVertex(LXtPolygonID polygon, unsigned int index) -> LxResult
    {
        return m_loc[0]->SelectPolygonVertex(m_loc, polygon, index);
    }

    auto ID(void) -> LXtPointID
    {
        return m_loc[0]->ID(m_loc);
    }

    auto Index(unsigned int *index) -> LxResult
    {
        return m_loc[0]->Index(m_loc, index);
    }

    auto Pos(LXtFVector pos) -> LxResult
    {
        return m_loc[0]->Pos(m_loc, pos);
    }

    auto Normal(LXtPolygonID pol, LXtVector normal) -> LxResult
    {
        return m_loc[0]->Normal(m_loc, pol, normal);
    }

    auto MapValue(LXtMeshMapID map, float *value) -> LxResult
    {
        return m_loc[0]->MapValue(m_loc, map, value);
    }

    auto MapEvaluate(LXtMeshMapID map, float *value) -> LxResult
    {
        return m_loc[0]->MapEvaluate(m_loc, map, value);
    }

    auto PolygonCount(unsigned int *count) -> LxResult
    {
        return m_loc[0]->PolygonCount(m_loc, count);
    }

    auto PolygonByIndex(unsigned int index, LXtPolygonID *polygonID) -> LxResult
    {
        return m_loc[0]->PolygonByIndex(m_loc, index, polygonID);
    }

    auto New(const LXtVector pos, LXtPointID *pointID) -> LxResult
    {
        return m_loc[0]->New(m_loc, pos, pointID);
    }

    auto Copy(LXtPointID *pointID) -> LxResult
    {
        return m_loc[0]->Copy(m_loc, pointID);
    }

    auto Remove(void) -> LxResult
    {
        return m_loc[0]->Remove(m_loc);
    }

    auto SetPos(const LXtVector pos) -> LxResult
    {
        return m_loc[0]->SetPos(m_loc, pos);
    }

    auto SetMapValue(LXtMeshMapID map, const float *value) -> LxResult
    {
        return m_loc[0]->SetMapValue(m_loc, map, value);
    }

    auto ClearMapValue(LXtMeshMapID map) -> LxResult
    {
        return m_loc[0]->ClearMapValue(m_loc, map);
    }

    auto Corner(LXtFVector pos) -> LxResult
    {
        return m_loc[0]->Corner(m_loc, pos);
    }

    auto PointCount(unsigned int *count) -> LxResult
    {
        return m_loc[0]->PointCount(m_loc, count);
    }

    auto PointByIndex(unsigned int index, LXtPointID *pointID) -> LxResult
    {
        return m_loc[0]->PointByIndex(m_loc, index, pointID);
    }

    auto EdgeCount(unsigned int *count) -> LxResult
    {
        return m_loc[0]->EdgeCount(m_loc, count);
    }

    auto EdgeByIndex(unsigned int index, LXtEdgeID *edgeID) -> LxResult
    {
        return m_loc[0]->EdgeByIndex(m_loc, index, edgeID);
    }

    auto Symmetry(LXtPointID *pointID) -> LxResult
    {
        return m_loc[0]->Symmetry(m_loc, pointID);
    }

    auto OnSymmetryCenter(void) -> LxResult
    {
        return m_loc[0]->OnSymmetryCenter(m_loc);
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

    auto Part(unsigned int *part) -> LxResult
    {
        return m_loc[0]->Part(m_loc, part);
    }

    auto NewOnEdge(LXtPointID A, LXtPointID B, float percent, LXtPointID *newPoint) -> LxResult
    {
        return m_loc[0]->NewOnEdge(m_loc, A, B, percent, newPoint);
    }

    auto UpdatePos(const LXtVector pos) -> LxResult
    {
        return m_loc[0]->UpdatePos(m_loc, pos);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_Polygon : public CLxLocalize<ILxPolygonID>
{
public:
    CLxLoc_Polygon()
    {
        _init();
    }

    CLxLoc_Polygon(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_Polygon(CLxLoc_Polygon const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_Polygon;
    }

    auto Spawn(void **ppvObj) -> LxResult
    {
        return m_loc[0]->Spawn(m_loc, ppvObj);
    }

    auto Spawn(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Spawn(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Enumerate(LXtMarkMode mode, ILxUnknownID visitor, ILxUnknownID monitor) -> LxResult
    {
        return m_loc[0]->Enumerate(m_loc, mode,(ILxUnknownID) visitor,(ILxUnknownID) monitor);
    }

    auto TestMarks(LXtMarkMode mode) -> LxResult
    {
        return m_loc[0]->TestMarks(m_loc, mode);
    }

    auto SetMarks(LXtMarkMode set) -> LxResult
    {
        return m_loc[0]->SetMarks(m_loc, set);
    }

    auto Select(LXtPolygonID polygon) -> LxResult
    {
        return m_loc[0]->Select(m_loc, polygon);
    }

    auto SelectByIndex(unsigned int index) -> LxResult
    {
        return m_loc[0]->SelectByIndex(m_loc, index);
    }

    auto ID(void) -> LXtPolygonID
    {
        return m_loc[0]->ID(m_loc);
    }

    auto Index(int *index) -> LxResult
    {
        return m_loc[0]->Index(m_loc, index);
    }

    auto Type(LXtID4 *type) -> LxResult
    {
        return m_loc[0]->Type(m_loc, type);
    }

    auto VertexCount(unsigned int *count) -> LxResult
    {
        return m_loc[0]->VertexCount(m_loc, count);
    }

    auto VertexByIndex(unsigned int index, LXtPointID *point) -> LxResult
    {
        return m_loc[0]->VertexByIndex(m_loc, index, point);
    }

    auto FirstIsControlEndpoint(void) -> LxResult
    {
        return m_loc[0]->FirstIsControlEndpoint(m_loc);
    }

    auto LastIsControlEndpoint(void) -> LxResult
    {
        return m_loc[0]->LastIsControlEndpoint(m_loc);
    }

    auto Normal(LXtVector normal) -> LxResult
    {
        return m_loc[0]->Normal(m_loc, normal);
    }

    auto MapValue(LXtMeshMapID map, LXtPointID point, float *value) -> LxResult
    {
        return m_loc[0]->MapValue(m_loc, map, point, value);
    }

    auto MapEvaluate(LXtMeshMapID map, LXtPointID point, float *value) -> LxResult
    {
        return m_loc[0]->MapEvaluate(m_loc, map, point, value);
    }

    auto Area(double *area) -> LxResult
    {
        return m_loc[0]->Area(m_loc, area);
    }

    auto New(LXtID4 type, const LXtPointID *vertices, unsigned int numVert, unsigned int rev, LXtPolygonID *polygonID) -> LxResult
    {
        return m_loc[0]->New(m_loc, type, vertices, numVert, rev, polygonID);
    }

    auto NewProto(LXtID4 type, const LXtPointID *vertices, unsigned int numVert, unsigned int rev, LXtPolygonID *polygonID) -> LxResult
    {
        return m_loc[0]->NewProto(m_loc, type, vertices, numVert, rev, polygonID);
    }

    auto Remove(void) -> LxResult
    {
        return m_loc[0]->Remove(m_loc);
    }

    auto SetFirstIsControlEndpoint(int state) -> LxResult
    {
        return m_loc[0]->SetFirstIsControlEndpoint(m_loc, state);
    }

    auto SetLastIsControlEndpoint(int state) -> LxResult
    {
        return m_loc[0]->SetLastIsControlEndpoint(m_loc, state);
    }

    auto SetVertexList(const LXtPointID *vertices, unsigned int numVert, unsigned int rev) -> LxResult
    {
        return m_loc[0]->SetVertexList(m_loc, vertices, numVert, rev);
    }

    auto SetMapValue(LXtPointID point, LXtMeshMapID map, const float *value) -> LxResult
    {
        return m_loc[0]->SetMapValue(m_loc, point, map, value);
    }

    auto ClearMapValue(LXtPointID point, LXtMeshMapID map) -> LxResult
    {
        return m_loc[0]->ClearMapValue(m_loc, point, map);
    }

    auto StartContour(void) -> LxResult
    {
        return m_loc[0]->StartContour(m_loc);
    }

    auto AddContourEdge(LXtPointID startPt, LXtPointID endPt) -> LxResult
    {
        return m_loc[0]->AddContourEdge(m_loc, startPt, endPt);
    }

    auto GenerateContour(LXtID4 type, LXtPolygonID *polygonID) -> LxResult
    {
        return m_loc[0]->GenerateContour(m_loc, type, polygonID);
    }

    auto GenerateContourProto(LXtPolygonID *polygonID) -> LxResult
    {
        return m_loc[0]->GenerateContourProto(m_loc, polygonID);
    }

    auto IntersectRay(const LXtVector pos, const LXtVector dir, LXtVector hitNorm, double *hitDist) -> LxResult
    {
        return m_loc[0]->IntersectRay(m_loc, pos, dir, hitNorm, hitDist);
    }

    auto Closest(double maxDist, const LXtVector pos, LXtVector hitPos, LXtVector hitNorm, double *hitDist) -> LxResult
    {
        return m_loc[0]->Closest(m_loc, maxDist, pos, hitPos, hitNorm, hitDist);
    }

    auto PointIndex(LXtPointID pointID, unsigned int *index) -> LxResult
    {
        return m_loc[0]->PointIndex(m_loc, pointID, index);
    }

    auto EdgeIndex(LXtEdgeID edgeID, unsigned int *index) -> LxResult
    {
        return m_loc[0]->EdgeIndex(m_loc, edgeID, index);
    }

    auto SharedEdge(LXtPolygonID polygonID, LXtEdgeID *edgeID) -> LxResult
    {
        return m_loc[0]->SharedEdge(m_loc, polygonID, edgeID);
    }

    auto IsBorder(void) -> LxResult
    {
        return m_loc[0]->IsBorder(m_loc);
    }

    auto RepresentativePosition(LXtVector pos) -> LxResult
    {
        return m_loc[0]->RepresentativePosition(m_loc, pos);
    }

    auto GoodPoint(const LXtPointID *points, unsigned int nPoints, unsigned int *index) -> LxResult
    {
        return m_loc[0]->GoodPoint(m_loc, points, nPoints, index);
    }

    auto GenerateTriangles(unsigned int *count) -> LxResult
    {
        return m_loc[0]->GenerateTriangles(m_loc, count);
    }

    auto TriangleByIndex(unsigned index, LXtPointID *point0, LXtPointID *point1, LXtPointID *point2) -> LxResult
    {
        return m_loc[0]->TriangleByIndex(m_loc, index, point0, point1, point2);
    }

    auto ClearTriangles(void) -> LxResult
    {
        return m_loc[0]->ClearTriangles(m_loc);
    }

    auto EnumerateBBox(LXtMarkMode mode, ILxUnknownID visitor, const LXtVector min, const LXtVector max) -> LxResult
    {
        return m_loc[0]->EnumerateBBox(m_loc, mode,(ILxUnknownID) visitor, min, max);
    }

    auto EnumerateRay(LXtMarkMode mode, ILxUnknownID visitor, const LXtVector org, const LXtVector ray) -> LxResult
    {
        return m_loc[0]->EnumerateRay(m_loc, mode,(ILxUnknownID) visitor, org, ray);
    }

    auto EnumerateLine(LXtMarkMode mode, ILxUnknownID visitor, const LXtVector org, const LXtVector dir) -> LxResult
    {
        return m_loc[0]->EnumerateLine(m_loc, mode,(ILxUnknownID) visitor, org, dir);
    }

    auto NewCurveFill(const LXtPolygonID *polygons, unsigned int numPols, LXtPolygonID *polygonID) -> LxResult
    {
        return m_loc[0]->NewCurveFill(m_loc, polygons, numPols, polygonID);
    }

    auto Symmetry(LXtPolygonID *polygonID) -> LxResult
    {
        return m_loc[0]->Symmetry(m_loc, polygonID);
    }

    auto UVLookup(const char *vMapName, const LXtVector2 uv, LXtVector surfacePosition, LXtVector surfaceNormal, LXtVector surfaceDPDU, LXtVector surfaceDPDV) -> LxResult
    {
        return m_loc[0]->UVLookup(m_loc, vMapName, uv, surfacePosition, surfaceNormal, surfaceDPDU, surfaceDPDV);
    }

    auto EnumerateByUV(LXtMarkMode mode, const char *vMapName, int quality, const LXtVector2 uv, ILxUnknownID visitor) -> LxResult
    {
        return m_loc[0]->EnumerateByUV(m_loc, mode, vMapName, quality, uv,(ILxUnknownID) visitor);
    }

    auto EnumerateBin(LXtMarkMode mode, ILxUnknownID visitor, ILxUnknownID bin) -> LxResult
    {
        return m_loc[0]->EnumerateBin(m_loc, mode,(ILxUnknownID) visitor,(ILxUnknownID) bin);
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

    auto EnumerateByPTag(LXtMarkMode mode, LXtID4 type, const char *tag, ILxUnknownID visitor) -> LxResult
    {
        return m_loc[0]->EnumerateByPTag(m_loc, mode, type, tag,(ILxUnknownID) visitor);
    }

    auto Part(unsigned int *part) -> LxResult
    {
        return m_loc[0]->Part(m_loc, part);
    }

    auto UVPart(LXtMeshMapID map, unsigned int *part) -> LxResult
    {
        return m_loc[0]->UVPart(m_loc, map, part);
    }

    auto Tessellate(unsigned int flags, LXtPolyMeshInfo *info) -> LxResult
    {
        return m_loc[0]->Tessellate(m_loc, flags, info);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};

class CLxLoc_Edge : public CLxLocalize<ILxEdgeID>
{
public:
    CLxLoc_Edge()
    {
        _init();
    }

    CLxLoc_Edge(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_Edge(CLxLoc_Edge const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_Edge;
    }

    auto Spawn(void **ppvObj) -> LxResult
    {
        return m_loc[0]->Spawn(m_loc, ppvObj);
    }

    auto Spawn(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Spawn(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Enumerate(LXtMarkMode mode, ILxUnknownID visitor, ILxUnknownID monitor) -> LxResult
    {
        return m_loc[0]->Enumerate(m_loc, mode,(ILxUnknownID) visitor,(ILxUnknownID) monitor);
    }

    auto TestMarks(LXtMarkMode mode) -> LxResult
    {
        return m_loc[0]->TestMarks(m_loc, mode);
    }

    auto SetMarks(LXtMarkMode set) -> LxResult
    {
        return m_loc[0]->SetMarks(m_loc, set);
    }

    auto Select(LXtEdgeID edge) -> LxResult
    {
        return m_loc[0]->Select(m_loc, edge);
    }

    auto SelectEndpoints(LXtPointID v0, LXtPointID v1) -> LxResult
    {
        return m_loc[0]->SelectEndpoints(m_loc, v0, v1);
    }

    auto ID(void) -> LXtEdgeID
    {
        return m_loc[0]->ID(m_loc);
    }

    auto Endpoints(LXtPointID *point0, LXtPointID *point1) -> LxResult
    {
        return m_loc[0]->Endpoints(m_loc, point0, point1);
    }

    auto MapValue(LXtMeshMapID map, float *value) -> LxResult
    {
        return m_loc[0]->MapValue(m_loc, map, value);
    }

    auto MapEvaluate(LXtMeshMapID map, float *value) -> LxResult
    {
        return m_loc[0]->MapEvaluate(m_loc, map, value);
    }

    auto SetMapValue(LXtMeshMapID map, const float *value) -> LxResult
    {
        return m_loc[0]->SetMapValue(m_loc, map, value);
    }

    auto ClearMapValue(LXtMeshMapID map) -> LxResult
    {
        return m_loc[0]->ClearMapValue(m_loc, map);
    }

    auto PolygonCount(unsigned int *count) -> LxResult
    {
        return m_loc[0]->PolygonCount(m_loc, count);
    }

    auto PolygonByIndex(unsigned int index, LXtPolygonID *polygonID) -> LxResult
    {
        return m_loc[0]->PolygonByIndex(m_loc, index, polygonID);
    }

    auto RepresentativePolygon(LXtPolygonID *polygonID, unsigned int *index) -> LxResult
    {
        return m_loc[0]->RepresentativePolygon(m_loc, polygonID, index);
    }

    auto SharedPolygon(LXtEdgeID edgeID, LXtPolygonID *polygonID) -> LxResult
    {
        return m_loc[0]->SharedPolygon(m_loc, edgeID, polygonID);
    }

    auto IsBorder(void) -> LxResult
    {
        return m_loc[0]->IsBorder(m_loc);
    }

    auto Symmetry(LXtEdgeID *edgeID) -> LxResult
    {
        return m_loc[0]->Symmetry(m_loc, edgeID);
    }

    auto OnSymmetryCenter(void) -> LxResult
    {
        return m_loc[0]->OnSymmetryCenter(m_loc);
    }

    auto Index(unsigned int *index) -> LxResult
    {
        return m_loc[0]->Index(m_loc, index);
    }

    auto SelectByIndex(unsigned int index) -> LxResult
    {
        return m_loc[0]->SelectByIndex(m_loc, index);
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

    auto NextLoopEdge(int inDirection, int* outDirection, int method, int ignoreBorder, int verifyAngle) -> LXtEdgeID
    {
        return m_loc[0]->NextLoopEdge(m_loc, inDirection, outDirection, method, ignoreBorder, verifyAngle);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_MeshMap : public CLxLocalize<ILxMeshMapID>
{
public:
    CLxLoc_MeshMap()
    {
        _init();
    }

    CLxLoc_MeshMap(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_MeshMap(CLxLoc_MeshMap const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_MeshMap;
    }

    auto Spawn(void **ppvObj) -> LxResult
    {
        return m_loc[0]->Spawn(m_loc, ppvObj);
    }

    auto Spawn(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Spawn(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Enumerate(LXtMarkMode mode, ILxUnknownID visitor, ILxUnknownID monitor) -> LxResult
    {
        return m_loc[0]->Enumerate(m_loc, mode,(ILxUnknownID) visitor,(ILxUnknownID) monitor);
    }

    auto Select(LXtMeshMapID map) -> LxResult
    {
        return m_loc[0]->Select(m_loc, map);
    }

    auto SelectByName(LXtID4 type, const char *name) -> LxResult
    {
        return m_loc[0]->SelectByName(m_loc, type, name);
    }

    auto FilterByType(LXtID4 type) -> LxResult
    {
        return m_loc[0]->FilterByType(m_loc, type);
    }

    auto ID(void) -> LXtMeshMapID
    {
        return m_loc[0]->ID(m_loc);
    }

    auto Name(const char **name) -> LxResult
    {
        return m_loc[0]->Name(m_loc, name);
    }

    auto Type(LXtID4 *type) -> LxResult
    {
        return m_loc[0]->Type(m_loc, type);
    }

    auto Dimension(unsigned int *dimension) -> LxResult
    {
        return m_loc[0]->Dimension(m_loc, dimension);
    }

    auto IsEdgeMap(void) -> LxResult
    {
        return m_loc[0]->IsEdgeMap(m_loc);
    }

    auto IsContinuous(void) -> LxResult
    {
        return m_loc[0]->IsContinuous(m_loc);
    }

    auto ZeroDefault(void) -> LxResult
    {
        return m_loc[0]->ZeroDefault(m_loc);
    }

    auto New(LXtID4 type, const char *name, LXtMeshMapID *mapID) -> LxResult
    {
        return m_loc[0]->New(m_loc, type, name, mapID);
    }

    auto Remove(void) -> LxResult
    {
        return m_loc[0]->Remove(m_loc);
    }

    auto Clear(void) -> LxResult
    {
        return m_loc[0]->Clear(m_loc);
    }

    auto EnumerateContinuous(ILxUnknownID visitor, ILxUnknownID point) -> LxResult
    {
        return m_loc[0]->EnumerateContinuous(m_loc,(ILxUnknownID) visitor,(ILxUnknownID) point);
    }

    auto EnumerateDiscontinuous(ILxUnknownID visitor, ILxUnknownID point, ILxUnknownID poly) -> LxResult
    {
        return m_loc[0]->EnumerateDiscontinuous(m_loc,(ILxUnknownID) visitor,(ILxUnknownID) point,(ILxUnknownID) poly);
    }

    auto EnumerateEdges(ILxUnknownID visitor, ILxUnknownID edge) -> LxResult
    {
        return m_loc[0]->EnumerateEdges(m_loc,(ILxUnknownID) visitor,(ILxUnknownID) edge);
    }

    auto SetName(const char *name) -> LxResult
    {
        return m_loc[0]->SetName(m_loc, name);
    }

    auto EnumerateUVSeamEdges(ILxUnknownID visitor, ILxUnknownID edge, ILxUnknownID poly) -> LxResult
    {
        return m_loc[0]->EnumerateUVSeamEdges(m_loc,(ILxUnknownID) visitor,(ILxUnknownID) edge,(ILxUnknownID) poly);
    }

    auto UVSeamOppositeEdge(LXtEdgeID originalEdge, LXtPolygonID originalPoly, LXtPolygonID *opppositePoly, int *isReverse) -> LxResult
    {
        return m_loc[0]->UVSeamOppositeEdge(m_loc, originalEdge, originalPoly, opppositePoly, isReverse);
    }

    auto UVBoundingBox(LXtBBox *bbox) -> LxResult
    {
        return m_loc[0]->UVBoundingBox(m_loc, bbox);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_MeshListener
{
public:
    virtual ~CLxImpl_MeshListener() = default;

    virtual void ml_Destroy([[maybe_unused]] void)
    {
    }

    virtual void ml_Changes([[maybe_unused]] unsigned event)
    {
    }
};

#define LXxD_MeshListener_Destroy void ml_Destroy() override
#define LXxO_MeshListener_Destroy LXxD_MeshListener_Destroy
#define LXxC_MeshListener_Destroy(c) void c::ml_Destroy()
#define LXxD_MeshListener_Changes void ml_Changes([[maybe_unused]] unsigned event) override
#define LXxO_MeshListener_Changes LXxD_MeshListener_Changes
#define LXxC_MeshListener_Changes(c) void c::ml_Changes([[maybe_unused]] unsigned event)

template <class T>
class CLxIfc_MeshListener: public CLxInterface
{
public:
    CLxIfc_MeshListener()
    {
        vt.Destroy = Destroy;
        vt.Changes = Changes;
        vTable = &vt.iunk;
        iid = &lx::guid_MeshListener;
    }

    static auto Destroy(LXtObjectID wcom) -> void
    {
        LXCWxINST (CLxImpl_MeshListener, loc);
        loc->ml_Destroy();
    }

    static auto Changes(LXtObjectID wcom,unsigned event) -> void
    {
        LXCWxINST (CLxImpl_MeshListener, loc);
        loc->ml_Changes( event);
    }

private:
    ILxMeshListener vt;
};


class CLxImpl_MeshListener1
{
public:
    virtual ~CLxImpl_MeshListener1() = default;

    virtual void ml_Destroy([[maybe_unused]] void)
    {
    }
};

#define LXxD_MeshListener1_Destroy void ml_Destroy() override
#define LXxO_MeshListener1_Destroy LXxD_MeshListener1_Destroy
#define LXxC_MeshListener1_Destroy(c) void c::ml_Destroy()

template <class T>
class CLxIfc_MeshListener1: public CLxInterface
{
public:
    CLxIfc_MeshListener1()
    {
        vt.Destroy = Destroy;
        vTable = &vt.iunk;
        iid = &lx::guid_MeshListener1;
    }

    static auto Destroy(LXtObjectID wcom) -> void
    {
        LXCWxINST (CLxImpl_MeshListener1, loc);
        loc->ml_Destroy();
    }

private:
    ILxMeshListener1 vt;
};


class CLxLoc_MeshTracker : public CLxLocalize<ILxMeshTrackerID>
{
public:
    CLxLoc_MeshTracker()
    {
        _init();
    }

    CLxLoc_MeshTracker(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_MeshTracker(CLxLoc_MeshTracker const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_MeshTracker;
    }

    auto Start(void) -> LxResult
    {
        return m_loc[0]->Start(m_loc);
    }

    auto Stop(void) -> LxResult
    {
        return m_loc[0]->Stop(m_loc);
    }

    auto Active(void) -> LxResult
    {
        return m_loc[0]->Active(m_loc);
    }

    auto Reset(void) -> LxResult
    {
        return m_loc[0]->Reset(m_loc);
    }

    auto Changes(unsigned int *edit) -> LxResult
    {
        return m_loc[0]->Changes(m_loc, edit);
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

    auto EnumeratePoints(unsigned int change, ILxUnknownID visitor, ILxUnknownID point) -> LxResult
    {
        return m_loc[0]->EnumeratePoints(m_loc, change,(ILxUnknownID) visitor,(ILxUnknownID) point);
    }

    auto EnumeratePolygons(unsigned int change, ILxUnknownID visitor, ILxUnknownID poly) -> LxResult
    {
        return m_loc[0]->EnumeratePolygons(m_loc, change,(ILxUnknownID) visitor,(ILxUnknownID) poly);
    }

    auto SetChange(unsigned int change) -> LxResult
    {
        return m_loc[0]->SetChange(m_loc, change);
    }

    auto AddPoint(LXtPointID point, unsigned int change) -> LxResult
    {
        return m_loc[0]->AddPoint(m_loc, point, change);
    }

    auto AddPolygon(LXtPolygonID poly, unsigned int change) -> LxResult
    {
        return m_loc[0]->AddPolygon(m_loc, poly, change);
    }

    auto SetFilter(unsigned int filter) -> LxResult
    {
        return m_loc[0]->SetFilter(m_loc, filter);
    }

    auto Filter(unsigned int *filter) -> LxResult
    {
        return m_loc[0]->Filter(m_loc, filter);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_MeshOperation
{
public:
    virtual ~CLxImpl_MeshOperation() = default;

    virtual auto mop_Evaluate([[maybe_unused]] ILxUnknownID mesh, [[maybe_unused]] LXtID4 type, [[maybe_unused]] LXtMarkMode mode) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto mop_Compare([[maybe_unused]] ILxUnknownID other) -> int
    {
        return LXiMESHOP_DIFFERENT;
    }

    virtual auto mop_Convert([[maybe_unused]] ILxUnknownID other) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto mop_ReEvaluate([[maybe_unused]] ILxUnknownID mesh, [[maybe_unused]] LXtID4 type) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto mop_SetTransform([[maybe_unused]] const LXtMatrix4 matrix) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto mop_Blend([[maybe_unused]] ILxUnknownID other, [[maybe_unused]] ILxUnknownID blend) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto mop_Clone([[maybe_unused]] ILxUnknownID target, [[maybe_unused]] ILxUnknownID source, [[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_MeshOperation_Evaluate LxResult mop_Evaluate([[maybe_unused]] ILxUnknownID mesh, [[maybe_unused]] LXtID4 type, [[maybe_unused]] LXtMarkMode mode) override
#define LXxO_MeshOperation_Evaluate LXxD_MeshOperation_Evaluate
#define LXxC_MeshOperation_Evaluate(c) LxResult c::mop_Evaluate([[maybe_unused]] ILxUnknownID mesh, [[maybe_unused]] LXtID4 type, [[maybe_unused]] LXtMarkMode mode)
#define LXxD_MeshOperation_Compare int mop_Compare([[maybe_unused]] ILxUnknownID other) override
#define LXxO_MeshOperation_Compare LXxD_MeshOperation_Compare
#define LXxC_MeshOperation_Compare(c) int c::mop_Compare([[maybe_unused]] ILxUnknownID other)
#define LXxD_MeshOperation_Convert LxResult mop_Convert([[maybe_unused]] ILxUnknownID other) override
#define LXxO_MeshOperation_Convert LXxD_MeshOperation_Convert
#define LXxC_MeshOperation_Convert(c) LxResult c::mop_Convert([[maybe_unused]] ILxUnknownID other)
#define LXxD_MeshOperation_ReEvaluate LxResult mop_ReEvaluate([[maybe_unused]] ILxUnknownID mesh, [[maybe_unused]] LXtID4 type) override
#define LXxO_MeshOperation_ReEvaluate LXxD_MeshOperation_ReEvaluate
#define LXxC_MeshOperation_ReEvaluate(c) LxResult c::mop_ReEvaluate([[maybe_unused]] ILxUnknownID mesh, [[maybe_unused]] LXtID4 type)
#define LXxD_MeshOperation_SetTransform LxResult mop_SetTransform([[maybe_unused]] const LXtMatrix4 matrix) override
#define LXxO_MeshOperation_SetTransform LXxD_MeshOperation_SetTransform
#define LXxC_MeshOperation_SetTransform(c) LxResult c::mop_SetTransform([[maybe_unused]] const LXtMatrix4 matrix)
#define LXxD_MeshOperation_Blend LxResult mop_Blend([[maybe_unused]] ILxUnknownID other, [[maybe_unused]] ILxUnknownID blend) override
#define LXxO_MeshOperation_Blend LXxD_MeshOperation_Blend
#define LXxC_MeshOperation_Blend(c) LxResult c::mop_Blend([[maybe_unused]] ILxUnknownID other, [[maybe_unused]] ILxUnknownID blend)
#define LXxD_MeshOperation_Clone LxResult mop_Clone([[maybe_unused]] ILxUnknownID target, [[maybe_unused]] ILxUnknownID source, [[maybe_unused]] void **ppvObj) override
#define LXxO_MeshOperation_Clone LXxD_MeshOperation_Clone
#define LXxC_MeshOperation_Clone(c) LxResult c::mop_Clone([[maybe_unused]] ILxUnknownID target, [[maybe_unused]] ILxUnknownID source, [[maybe_unused]] void **ppvObj)

template <class T>
class CLxIfc_MeshOperation: public CLxInterface
{
public:
    CLxIfc_MeshOperation()
    {
        vt.Evaluate = Evaluate;
        vt.Compare = Compare;
        vt.Convert = Convert;
        vt.ReEvaluate = ReEvaluate;
        vt.SetTransform = SetTransform;
        vt.Blend = Blend;
        vt.Clone = Clone;
        vTable = &vt.iunk;
        iid = &lx::guid_MeshOperation;
    }

    static auto Evaluate(LXtObjectID wcom,LXtObjectID mesh,LXtID4 type,LXtMarkMode mode) -> LxResult
    {
        LXCWxINST (CLxImpl_MeshOperation, loc);
        try
        {
           return loc->mop_Evaluate((ILxUnknownID) mesh, type, mode);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Compare(LXtObjectID wcom,LXtObjectID other) -> int
    {
        LXCWxINST (CLxImpl_MeshOperation, loc);
        return loc->mop_Compare((ILxUnknownID) other);
    }

    static auto Convert(LXtObjectID wcom,LXtObjectID other) -> LxResult
    {
        LXCWxINST (CLxImpl_MeshOperation, loc);
        try
        {
           return loc->mop_Convert((ILxUnknownID) other);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ReEvaluate(LXtObjectID wcom,LXtObjectID mesh,LXtID4 type) -> LxResult
    {
        LXCWxINST (CLxImpl_MeshOperation, loc);
        try
        {
           return loc->mop_ReEvaluate((ILxUnknownID) mesh, type);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SetTransform(LXtObjectID wcom,const LXtMatrix4 matrix) -> LxResult
    {
        LXCWxINST (CLxImpl_MeshOperation, loc);
        try
        {
           return loc->mop_SetTransform( matrix);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Blend(LXtObjectID wcom,LXtObjectID other,LXtObjectID blend) -> LxResult
    {
        LXCWxINST (CLxImpl_MeshOperation, loc);
        try
        {
           return loc->mop_Blend((ILxUnknownID) other,(ILxUnknownID) blend);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Clone(LXtObjectID wcom,LXtObjectID target,LXtObjectID source,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_MeshOperation, loc);
        try
        {
           return loc->mop_Clone((ILxUnknownID) target,(ILxUnknownID) source, ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxMeshOperation vt;
};

class CLxLoc_MeshOperation : public CLxLocalize<ILxMeshOperationID>
{
public:
    CLxLoc_MeshOperation()
    {
        _init();
    }

    CLxLoc_MeshOperation(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_MeshOperation(CLxLoc_MeshOperation const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_MeshOperation;
    }

    auto Evaluate(ILxUnknownID mesh, LXtID4 type, LXtMarkMode mode) -> LxResult
    {
        return m_loc[0]->Evaluate(m_loc,(ILxUnknownID) mesh, type, mode);
    }

    auto Compare(ILxUnknownID other) -> int
    {
        return m_loc[0]->Compare(m_loc,(ILxUnknownID) other);
    }

    auto Convert(ILxUnknownID other) -> LxResult
    {
        return m_loc[0]->Convert(m_loc,(ILxUnknownID) other);
    }

    auto ReEvaluate(ILxUnknownID mesh, LXtID4 type) -> LxResult
    {
        return m_loc[0]->ReEvaluate(m_loc,(ILxUnknownID) mesh, type);
    }

    auto SetTransform(const LXtMatrix4 matrix) const -> LxResult
    {
        return m_loc[0]->SetTransform(m_loc, matrix);
    }

    auto Blend(ILxUnknownID other, ILxUnknownID blend) -> LxResult
    {
        return m_loc[0]->Blend(m_loc,(ILxUnknownID) other,(ILxUnknownID) blend);
    }

    auto Clone(ILxUnknownID target, ILxUnknownID source, void **ppvObj) -> LxResult
    {
        return m_loc[0]->Clone(m_loc,(ILxUnknownID) target,(ILxUnknownID) source, ppvObj);
    }

    auto Clone(ILxUnknownID target, ILxUnknownID source, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Clone(m_loc,(ILxUnknownID) target,(ILxUnknownID) source, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};


class CLxImpl_MeshFilter
{
public:
    virtual ~CLxImpl_MeshFilter() = default;

    virtual unsigned mfilt_Type(void) = 0;

    virtual auto mfilt_Evaluate([[maybe_unused]] ILxUnknownID mesh, [[maybe_unused]] ILxUnknownID tracker) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto mfilt_Generate([[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_MeshFilter_Type unsigned mfilt_Type() override
#define LXxO_MeshFilter_Type LXxD_MeshFilter_Type
#define LXxC_MeshFilter_Type(c) unsigned c::mfilt_Type()
#define LXxD_MeshFilter_Evaluate LxResult mfilt_Evaluate([[maybe_unused]] ILxUnknownID mesh, [[maybe_unused]] ILxUnknownID tracker) override
#define LXxO_MeshFilter_Evaluate LXxD_MeshFilter_Evaluate
#define LXxC_MeshFilter_Evaluate(c) LxResult c::mfilt_Evaluate([[maybe_unused]] ILxUnknownID mesh, [[maybe_unused]] ILxUnknownID tracker)
#define LXxD_MeshFilter_Generate LxResult mfilt_Generate([[maybe_unused]] void **ppvObj) override
#define LXxO_MeshFilter_Generate LXxD_MeshFilter_Generate
#define LXxC_MeshFilter_Generate(c) LxResult c::mfilt_Generate([[maybe_unused]] void **ppvObj)

template <class T>
class CLxIfc_MeshFilter: public CLxInterface
{
public:
    CLxIfc_MeshFilter()
    {
        vt.Type = Type;
        vt.Evaluate = Evaluate;
        vt.Generate = Generate;
        vTable = &vt.iunk;
        iid = &lx::guid_MeshFilter;
    }

    static auto Type(LXtObjectID wcom) -> unsigned
    {
        LXCWxINST (CLxImpl_MeshFilter, loc);
        return loc->mfilt_Type();
    }

    static auto Evaluate(LXtObjectID wcom,LXtObjectID mesh,LXtObjectID tracker) -> LxResult
    {
        LXCWxINST (CLxImpl_MeshFilter, loc);
        try
        {
           return loc->mfilt_Evaluate((ILxUnknownID) mesh,(ILxUnknownID) tracker);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Generate(LXtObjectID wcom,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_MeshFilter, loc);
        try
        {
           return loc->mfilt_Generate( ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxMeshFilter vt;
};

class CLxLoc_MeshFilter : public CLxLocalize<ILxMeshFilterID>
{
public:
    CLxLoc_MeshFilter()
    {
        _init();
    }

    CLxLoc_MeshFilter(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_MeshFilter(CLxLoc_MeshFilter const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_MeshFilter;
    }

    auto Type(void) -> unsigned
    {
        return m_loc[0]->Type(m_loc);
    }

    auto Evaluate(ILxUnknownID mesh, ILxUnknownID tracker) -> LxResult
    {
        return m_loc[0]->Evaluate(m_loc,(ILxUnknownID) mesh,(ILxUnknownID) tracker);
    }

    auto Generate(void **ppvObj) -> LxResult
    {
        return m_loc[0]->Generate(m_loc, ppvObj);
    }

    auto Generate(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Generate(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};

class CLxImpl_MeshFilterBBox
{
public:
    virtual ~CLxImpl_MeshFilterBBox() = default;

    virtual auto mfbbox_Evaluate([[maybe_unused]] LXtBBox *box) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_MeshFilterBBox_Evaluate LxResult mfbbox_Evaluate([[maybe_unused]] LXtBBox *box) override
#define LXxO_MeshFilterBBox_Evaluate LXxD_MeshFilterBBox_Evaluate
#define LXxC_MeshFilterBBox_Evaluate(c) LxResult c::mfbbox_Evaluate([[maybe_unused]] LXtBBox *box)

template <class T>
class CLxIfc_MeshFilterBBox: public CLxInterface
{
public:
    CLxIfc_MeshFilterBBox()
    {
        vt.Evaluate = Evaluate;
        vTable = &vt.iunk;
        iid = &lx::guid_MeshFilterBBox;
    }

    static auto Evaluate(LXtObjectID wcom,LXtBBox *box) -> LxResult
    {
        LXCWxINST (CLxImpl_MeshFilterBBox, loc);
        try
        {
           return loc->mfbbox_Evaluate( box);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxMeshFilterBBox vt;
};

class CLxLoc_MeshFilterBBox : public CLxLocalize<ILxMeshFilterBBoxID>
{
public:
    CLxLoc_MeshFilterBBox()
    {
        _init();
    }

    CLxLoc_MeshFilterBBox(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_MeshFilterBBox(CLxLoc_MeshFilterBBox const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_MeshFilterBBox;
    }

    auto Evaluate(LXtBBox *box) -> LxResult
    {
        return m_loc[0]->Evaluate(m_loc, box);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_MeshFilterIdent : public CLxLocalize<ILxMeshFilterIdentID>
{
public:
    CLxLoc_MeshFilterIdent()
    {
        _init();
    }

    CLxLoc_MeshFilterIdent(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_MeshFilterIdent(CLxLoc_MeshFilterIdent const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_MeshFilterIdent;
    }

    auto Generate(const char *ident, void **ppvObj) -> LxResult
    {
        return m_loc[0]->Generate(m_loc, ident, ppvObj);
    }

    auto Generate(const char *ident, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Generate(m_loc, ident, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_MeshFilterBlend : public CLxLocalize<ILxMeshFilterBlendID>
{
public:
    CLxLoc_MeshFilterBlend()
    {
        _init();
    }

    CLxLoc_MeshFilterBlend(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_MeshFilterBlend(CLxLoc_MeshFilterBlend const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_MeshFilterBlend;
    }

    auto Generate(ILxUnknownID other, void **ppvObj) -> LxResult
    {
        return m_loc[0]->Generate(m_loc,(ILxUnknownID) other, ppvObj);
    }

    auto Generate(ILxUnknownID other, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Generate(m_loc,(ILxUnknownID) other, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Evaluate(ILxUnknownID other, ILxUnknownID blend) -> LxResult
    {
        return m_loc[0]->Evaluate(m_loc,(ILxUnknownID) other,(ILxUnknownID) blend);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_MeshBlend : public CLxLocalize<ILxMeshBlendID>
{
public:
    CLxLoc_MeshBlend()
    {
        _init();
    }

    CLxLoc_MeshBlend(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_MeshBlend(CLxLoc_MeshBlend const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_MeshBlend;
    }

    auto BlendMesh(double t, void **ppvObj) -> LxResult
    {
        return m_loc[0]->BlendMesh(m_loc, t, ppvObj);
    }

    auto BlendMesh(double t, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->BlendMesh(m_loc, t, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto SourceMesh(void **ppvObj) -> LxResult
    {
        return m_loc[0]->SourceMesh(m_loc, ppvObj);
    }

    auto SourceMesh(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->SourceMesh(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto TargetMesh(void **ppvObj) -> LxResult
    {
        return m_loc[0]->TargetMesh(m_loc, ppvObj);
    }

    auto TargetMesh(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->TargetMesh(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto GetPoint(LXtPointID source, LXtPointID *target) -> LxResult
    {
        return m_loc[0]->GetPoint(m_loc, source, target);
    }

    auto GetPolygon(LXtPolygonID source, LXtPolygonID *target) -> LxResult
    {
        return m_loc[0]->GetPolygon(m_loc, source, target);
    }

    auto SetPoint(LXtPointID source, LXtPointID target) -> LxResult
    {
        return m_loc[0]->SetPoint(m_loc, source, target);
    }

    auto SetPolygon(LXtPolygonID source, LXtPolygonID target) -> LxResult
    {
        return m_loc[0]->SetPolygon(m_loc, source, target);
    }

    auto EnumeratePoints(ILxUnknownID source, ILxUnknownID target, ILxUnknownID visitor) -> LxResult
    {
        return m_loc[0]->EnumeratePoints(m_loc,(ILxUnknownID) source,(ILxUnknownID) target,(ILxUnknownID) visitor);
    }

    auto EnumeratePolygons(ILxUnknownID source, ILxUnknownID target, ILxUnknownID visitor) -> LxResult
    {
        return m_loc[0]->EnumeratePolygons(m_loc,(ILxUnknownID) source,(ILxUnknownID) target,(ILxUnknownID) visitor);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_MeshMetaData
{
public:
    virtual ~CLxImpl_MeshMetaData() = default;

    virtual auto meta_Validate([[maybe_unused]] ILxUnknownID mesh, [[maybe_unused]] ILxUnknownID xtra, [[maybe_unused]] unsigned int change) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual void meta_FreePointData([[maybe_unused]] void *data)
    {
    }

    virtual void meta_FreePolygonData([[maybe_unused]] void *data)
    {
    }
};

#define LXxD_MeshMetaData_Validate LxResult meta_Validate([[maybe_unused]] ILxUnknownID mesh, [[maybe_unused]] ILxUnknownID xtra, [[maybe_unused]] unsigned int change) override
#define LXxO_MeshMetaData_Validate LXxD_MeshMetaData_Validate
#define LXxC_MeshMetaData_Validate(c) LxResult c::meta_Validate([[maybe_unused]] ILxUnknownID mesh, [[maybe_unused]] ILxUnknownID xtra, [[maybe_unused]] unsigned int change)
#define LXxD_MeshMetaData_FreePointData void meta_FreePointData([[maybe_unused]] void *data) override
#define LXxO_MeshMetaData_FreePointData LXxD_MeshMetaData_FreePointData
#define LXxC_MeshMetaData_FreePointData(c) void c::meta_FreePointData([[maybe_unused]] void *data)
#define LXxD_MeshMetaData_FreePolygonData void meta_FreePolygonData([[maybe_unused]] void *data) override
#define LXxO_MeshMetaData_FreePolygonData LXxD_MeshMetaData_FreePolygonData
#define LXxC_MeshMetaData_FreePolygonData(c) void c::meta_FreePolygonData([[maybe_unused]] void *data)

template <class T>
class CLxIfc_MeshMetaData: public CLxInterface
{
public:
    CLxIfc_MeshMetaData()
    {
        vt.Validate = Validate;
        vt.FreePointData = FreePointData;
        vt.FreePolygonData = FreePolygonData;
        vTable = &vt.iunk;
        iid = &lx::guid_MeshMetaData;
    }

    static auto Validate(LXtObjectID wcom,LXtObjectID mesh,LXtObjectID xtra,unsigned int change) -> LxResult
    {
        LXCWxINST (CLxImpl_MeshMetaData, loc);
        try
        {
           return loc->meta_Validate((ILxUnknownID) mesh,(ILxUnknownID) xtra, change);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto FreePointData(LXtObjectID wcom,void *data) -> void
    {
        LXCWxINST (CLxImpl_MeshMetaData, loc);
        loc->meta_FreePointData( data);
    }

    static auto FreePolygonData(LXtObjectID wcom,void *data) -> void
    {
        LXCWxINST (CLxImpl_MeshMetaData, loc);
        loc->meta_FreePolygonData( data);
    }

private:
    ILxMeshMetaData vt;
};


class CLxLoc_MeshXtraData : public CLxLocalize<ILxMeshXtraDataID>
{
public:
    CLxLoc_MeshXtraData()
    {
        _init();
    }

    CLxLoc_MeshXtraData(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_MeshXtraData(CLxLoc_MeshXtraData const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_MeshXtraData;
    }

    auto SetPointData(LXtPointID point, void *data) -> LxResult
    {
        return m_loc[0]->SetPointData(m_loc, point, data);
    }

    auto SetPointObject(LXtPointID point, ILxUnknownID obj) -> LxResult
    {
        return m_loc[0]->SetPointObject(m_loc, point,(ILxUnknownID) obj);
    }

    auto GetPointData(LXtPointID point, void **data) -> LxResult
    {
        return m_loc[0]->GetPointData(m_loc, point, data);
    }

    auto GetPointObject(LXtPointID point, void **ppvObj) -> LxResult
    {
        return m_loc[0]->GetPointObject(m_loc, point, ppvObj);
    }

    auto GetPointObject(LXtPointID point, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->GetPointObject(m_loc, point, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto ClearPoint(LXtPointID point) -> LxResult
    {
        return m_loc[0]->ClearPoint(m_loc, point);
    }

    auto SetPolygonData(LXtPolygonID poly, void *data) -> LxResult
    {
        return m_loc[0]->SetPolygonData(m_loc, poly, data);
    }

    auto SetPolygonObject(LXtPolygonID poly, ILxUnknownID obj) -> LxResult
    {
        return m_loc[0]->SetPolygonObject(m_loc, poly,(ILxUnknownID) obj);
    }

    auto GetPolygonData(LXtPolygonID poly, void **data) -> LxResult
    {
        return m_loc[0]->GetPolygonData(m_loc, poly, data);
    }

    auto GetPolygonObject(LXtPolygonID poly, void **ppvObj) -> LxResult
    {
        return m_loc[0]->GetPolygonObject(m_loc, poly, ppvObj);
    }

    auto GetPolygonObject(LXtPolygonID poly, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->GetPolygonObject(m_loc, poly, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto ClearPolygon(LXtPolygonID poly) -> LxResult
    {
        return m_loc[0]->ClearPolygon(m_loc, poly);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
