//
// C++ wrapper for lxsdk/lxlayer.h.
//
//	Copyright 2024.
//
//
#pragma once

#include <lxlayer.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx
{
    static LXtGUID const guid_LayerService = {0xF12B06AA, {0xBF92, 0x4585}, {0x80, 0x0E, 0x45, 0xAB, 0x99, 0xD4, 0x7A, 0x20}};
    static LXtGUID const guid_LayerScan = {0x097DB669, {0x91C3, 0x11D9}, {0x8E, 0xA2, 0x00, 0x0A, 0x95, 0x6C, 0x2E, 0x10}};
    static LXtGUID const guid_TransformScan = {0x6DD4BC9B, {0xBEDC, 0x46B9}, {0xB5, 0xAC, 0x85, 0x0A, 0x06, 0xAD, 0x5E, 0xEB}};
    static LXtGUID const guid_Scene1Service = {0x11D99CDC, {0xF662, 0x40FF}, {0x9A, 0xC3, 0xB7, 0x6E, 0x59, 0xC8, 0xDE, 0xB0}};
} // namespace lx

class CLxLoc_LayerService : public CLxLocalizedService
{
public:
    ILxLayerServiceID m_loc{ nullptr };

public:
    CLxLoc_LayerService()
    {
        _init();
        set();
    }

    ~CLxLoc_LayerService() = default;

    void set()
    {
        if (!m_loc)
        {
            m_loc = reinterpret_cast<ILxLayerServiceID>(lx::GetGlobal(&lx::guid_LayerService));
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

    auto SetScene(ILxUnknownID scene) -> LxResult
    {
        return m_loc[0]->SetScene(m_loc,(ILxUnknownID) scene);
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

    auto Count(unsigned int *count) -> LxResult
    {
        return m_loc[0]->Count(m_loc, count);
    }

    auto Name(unsigned int index, const char **name) -> LxResult
    {
        return m_loc[0]->Name(m_loc, index, name);
    }

    auto Slot(unsigned int index, int *slot) -> LxResult
    {
        return m_loc[0]->Slot(m_loc, index, slot);
    }

    auto Item(unsigned int index, void **ppvObj) -> LxResult
    {
        return m_loc[0]->Item(m_loc, index, ppvObj);
    }

    auto Item(unsigned int index, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Item(m_loc, index, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Mesh(unsigned int index, void **ppvObj) -> LxResult
    {
        return m_loc[0]->Mesh(m_loc, index, ppvObj);
    }

    auto Mesh(unsigned int index, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Mesh(m_loc, index, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Flags(unsigned int index, int *flags) -> LxResult
    {
        return m_loc[0]->Flags(m_loc, index, flags);
    }

    auto Pivot(unsigned int index, double *pivot) -> LxResult
    {
        return m_loc[0]->Pivot(m_loc, index, pivot);
    }

    auto PatchSubdivision(unsigned int index, int *level) -> LxResult
    {
        return m_loc[0]->PatchSubdivision(m_loc, index, level);
    }

    auto Bounds(unsigned int index, LXtVector min, LXtVector max) -> LxResult
    {
        return m_loc[0]->Bounds(m_loc, index, min, max);
    }

    auto CurveSmoothAngle(unsigned int index, double *angle) -> LxResult
    {
        return m_loc[0]->CurveSmoothAngle(m_loc, index, angle);
    }

    auto SplinePatchSubdivision(unsigned int index, int *level) -> LxResult
    {
        return m_loc[0]->SplinePatchSubdivision(m_loc, index, level);
    }

    auto ItemLookup(int mode, ILxUnknownID item, int *index) -> LxResult
    {
        return m_loc[0]->ItemLookup(m_loc, mode,(ILxUnknownID) item, index);
    }

    auto NameLookup(int mode, const char *name, int *index) -> LxResult
    {
        return m_loc[0]->NameLookup(m_loc, mode, name, index);
    }

    auto LayerParent(int index, int *parentIndex) -> LxResult
    {
        return m_loc[0]->LayerParent(m_loc, index, parentIndex);
    }

    auto LayerChildCount(int index, int *num) -> LxResult
    {
        return m_loc[0]->LayerChildCount(m_loc, index, num);
    }

    auto LayerChild(int index, int childNumber, int *childIndex) -> LxResult
    {
        return m_loc[0]->LayerChild(m_loc, index, childNumber, childIndex);
    }

    auto LayerVMapCount(int *num) -> LxResult
    {
        return m_loc[0]->LayerVMapCount(m_loc, num);
    }

    auto LayerVMap(unsigned int index, void **ppvObj) -> LxResult
    {
        return m_loc[0]->LayerVMap(m_loc, index, ppvObj);
    }

    auto LayerVMap(unsigned int index, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->LayerVMap(m_loc, index, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto LayerClipCount(int *num) -> LxResult
    {
        return m_loc[0]->LayerClipCount(m_loc, num);
    }

    auto LayerClip(unsigned int index, void **ppvObj) -> LxResult
    {
        return m_loc[0]->LayerClip(m_loc, index, ppvObj);
    }

    auto LayerClip(unsigned int index, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->LayerClip(m_loc, index, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto LayerMaterialCount(int *num) -> LxResult
    {
        return m_loc[0]->LayerMaterialCount(m_loc, num);
    }

    auto LayerMaterial(unsigned int index, void **ppvObj) -> LxResult
    {
        return m_loc[0]->LayerMaterial(m_loc, index, ppvObj);
    }

    auto LayerMaterial(unsigned int index, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->LayerMaterial(m_loc, index, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto LayerPartCount(int *num) -> LxResult
    {
        return m_loc[0]->LayerPartCount(m_loc, num);
    }

    auto LayerPart(unsigned int index, const char **part) -> LxResult
    {
        return m_loc[0]->LayerPart(m_loc, index, part);
    }

    auto LayerSelSetCount(unsigned int type, int *num) -> LxResult
    {
        return m_loc[0]->LayerSelSetCount(m_loc, type, num);
    }

    auto LayerSelSet(unsigned int type, unsigned int index, const char **selSet) -> LxResult
    {
        return m_loc[0]->LayerSelSet(m_loc, type, index, selSet);
    }

    auto LayerTextureCount(int layer, int *num) -> LxResult
    {
        return m_loc[0]->LayerTextureCount(m_loc, layer, num);
    }

    auto LayerTexture(int layer, unsigned int index, void **ppvObj) -> LxResult
    {
        return m_loc[0]->LayerTexture(m_loc, layer, index, ppvObj);
    }

    auto LayerTexture(int layer, unsigned int index, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->LayerTexture(m_loc, layer, index, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto LayerTagTextureCount(int layer, unsigned int type, const char *tag, int *num) -> LxResult
    {
        return m_loc[0]->LayerTagTextureCount(m_loc, layer, type, tag, num);
    }

    auto LayerTagTexture(int layer, unsigned int type, const char *tag, unsigned int index, void **ppvObj) -> LxResult
    {
        return m_loc[0]->LayerTagTexture(m_loc, layer, type, tag, index, ppvObj);
    }

    auto LayerTagTexture(int layer, unsigned int type, const char *tag, unsigned int index, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->LayerTagTexture(m_loc, layer, type, tag, index, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto LayerVertexCount(int mode, int *num) -> LxResult
    {
        return m_loc[0]->LayerVertexCount(m_loc, mode, num);
    }

    auto LayerVertex(int mode, unsigned int index, void **ppvObj) -> LxResult
    {
        return m_loc[0]->LayerVertex(m_loc, mode, index, ppvObj);
    }

    auto LayerVertex(int mode, unsigned int index, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->LayerVertex(m_loc, mode, index, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto LayerPolyCount(int mode, int *num) -> LxResult
    {
        return m_loc[0]->LayerPolyCount(m_loc, mode, num);
    }

    auto LayerPoly(int mode, unsigned int index, void **ppvObj) -> LxResult
    {
        return m_loc[0]->LayerPoly(m_loc, mode, index, ppvObj);
    }

    auto LayerPoly(int mode, unsigned int index, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->LayerPoly(m_loc, mode, index, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto LayerEdgeCount(int mode, int *num) -> LxResult
    {
        return m_loc[0]->LayerEdgeCount(m_loc, mode, num);
    }

    auto LayerEdge(int mode, unsigned int index, void **ppvObj) -> LxResult
    {
        return m_loc[0]->LayerEdge(m_loc, mode, index, ppvObj);
    }

    auto LayerEdge(int mode, unsigned int index, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->LayerEdge(m_loc, mode, index, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto ScanAllocate(unsigned flags, void **ppvObj) -> LxResult
    {
        return m_loc[0]->ScanAllocate(m_loc, flags, ppvObj);
    }

    auto ScanAllocate(unsigned flags, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->ScanAllocate(m_loc, flags, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto CurrentMap(LXtID4 type, const char **name) -> LxResult
    {
        return m_loc[0]->CurrentMap(m_loc, type, name);
    }

    auto XfrmAllocate(ILxUnknownID toolVec, void **ppvObj) -> LxResult
    {
        return m_loc[0]->XfrmAllocate(m_loc,(ILxUnknownID) toolVec, ppvObj);
    }

    auto XfrmAllocate(ILxUnknownID toolVec, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->XfrmAllocate(m_loc,(ILxUnknownID) toolVec, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto ScanAllocateItem(ILxUnknownID item, unsigned flags, void **ppvObj) -> LxResult
    {
        return m_loc[0]->ScanAllocateItem(m_loc,(ILxUnknownID) item, flags, ppvObj);
    }

    auto ScanAllocateItem(ILxUnknownID item, unsigned flags, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->ScanAllocateItem(m_loc,(ILxUnknownID) item, flags, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto IsProcedural(unsigned int index) -> LxResult
    {
        return m_loc[0]->IsProcedural(m_loc, index);
    }

    auto SetMark(ILxUnknownID item) -> LxResult
    {
        return m_loc[0]->SetMark(m_loc,(ILxUnknownID) item);
    }

    auto ClearMark(ILxUnknownID item) -> LxResult
    {
        return m_loc[0]->ClearMark(m_loc,(ILxUnknownID) item);
    }

    auto TestMark(ILxUnknownID item) -> int
    {
        return m_loc[0]->TestMark(m_loc,(ILxUnknownID) item);
    }

    auto CurrentDeformer(ILxUnknownID meshItem, const char **name) -> LxResult
    {
        return m_loc[0]->CurrentDeformer(m_loc,(ILxUnknownID) meshItem, name);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_LayerScan : public CLxLocalize<ILxLayerScanID>
{
public:
    CLxLoc_LayerScan()
    {
        _init();
    }

    CLxLoc_LayerScan(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_LayerScan(CLxLoc_LayerScan const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_LayerScan;
    }

    auto Apply(void) -> LxResult
    {
        return m_loc[0]->Apply(m_loc);
    }

    auto Count(unsigned *count) -> LxResult
    {
        return m_loc[0]->Count(m_loc, count);
    }

    auto GetState(unsigned index, unsigned *state) -> LxResult
    {
        return m_loc[0]->GetState(m_loc, index, state);
    }

    auto MeshItem(unsigned index, void **ppvObj) -> LxResult
    {
        return m_loc[0]->MeshItem(m_loc, index, ppvObj);
    }

    auto MeshItem(unsigned index, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->MeshItem(m_loc, index, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto MeshAction(unsigned index, void **ppvObj) -> LxResult
    {
        return m_loc[0]->MeshAction(m_loc, index, ppvObj);
    }

    auto MeshAction(unsigned index, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->MeshAction(m_loc, index, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto MeshBase(unsigned index, void **ppvObj) -> LxResult
    {
        return m_loc[0]->MeshBase(m_loc, index, ppvObj);
    }

    auto MeshBase(unsigned index, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->MeshBase(m_loc, index, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto MeshInstance(unsigned index, void **ppvObj) -> LxResult
    {
        return m_loc[0]->MeshInstance(m_loc, index, ppvObj);
    }

    auto MeshInstance(unsigned index, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->MeshInstance(m_loc, index, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto MeshEdit(unsigned index, void **ppvObj) -> LxResult
    {
        return m_loc[0]->MeshEdit(m_loc, index, ppvObj);
    }

    auto MeshEdit(unsigned index, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->MeshEdit(m_loc, index, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto SetMeshChange(unsigned index, unsigned int edits) -> LxResult
    {
        return m_loc[0]->SetMeshChange(m_loc, index, edits);
    }

    auto Update(void) -> LxResult
    {
        return m_loc[0]->Update(m_loc);
    }

    auto MeshTransform(unsigned index, LXtMatrix4 matrix) const -> LxResult
    {
        return m_loc[0]->MeshTransform(m_loc, index, matrix);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_TransformScan : public CLxLocalize<ILxTransformScanID>
{
public:
    CLxLoc_TransformScan()
    {
        _init();
    }

    CLxLoc_TransformScan(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_TransformScan(CLxLoc_TransformScan const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_TransformScan;
    }

    auto Enumerate(ILxUnknownID visitor) -> LxResult
    {
        return m_loc[0]->Enumerate(m_loc,(ILxUnknownID) visitor);
    }

    auto Flags(void) -> unsigned int
    {
        return m_loc[0]->Flags(m_loc);
    }

    auto Position(void) -> const float *
    {
        return m_loc[0]->Position(m_loc);
    }

    auto SetPosition(LXtFVector pos) -> LxResult
    {
        return m_loc[0]->SetPosition(m_loc, pos);
    }

    auto Weight(void) -> double
    {
        return m_loc[0]->Weight(m_loc);
    }

    auto AlternateCenter(LXtFVector center) -> LxResult
    {
        return m_loc[0]->AlternateCenter(m_loc, center);
    }

    auto AlternateAxis(LXtMatrix matrix, LXtMatrix inverse) -> LxResult
    {
        return m_loc[0]->AlternateAxis(m_loc, matrix, inverse);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};

