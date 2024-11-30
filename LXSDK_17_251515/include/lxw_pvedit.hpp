//
// C++ wrapper for lxsdk/lxpvedit.h.
//
//	Copyright 2024.
//
//
#pragma once

#include <lxpvedit.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx
{
    static LXtGUID const guid_PolygonSlice = {0x99C623EE, {0x0873, 0x4DB5}, {0x90, 0xDF, 0xCC, 0x94, 0x60, 0xDA, 0x8F, 0xA8}};
    static LXtGUID const guid_SolidDrill = {0x0D6D30C6, {0x0DEB, 0x4848}, {0xA9, 0xF9, 0x73, 0x14, 0x72, 0x25, 0x5B, 0xA9}};
    static LXtGUID const guid_PolygonEdit = {0x3EA0362E, {0x61B6, 0x4BFE}, {0xA9, 0x8B, 0xCE, 0x72, 0x22, 0x1F, 0xC9, 0x6B}};
} // namespace lx

class CLxLoc_PolygonSlice : public CLxLocalize<ILxPolygonSliceID>
{
public:
    CLxLoc_PolygonSlice()
    {
        _init();
    }

    CLxLoc_PolygonSlice(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_PolygonSlice(CLxLoc_PolygonSlice const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_PolygonSlice;
    }

    auto SetAxis(unsigned axis) -> LxResult
    {
        return m_loc[0]->SetAxis(m_loc, axis);
    }

    auto SetAxisByVector(const LXtVector axis) -> LxResult
    {
        return m_loc[0]->SetAxisByVector(m_loc, axis);
    }

    auto Start(ILxUnknownID meshObj, LXtPolygonID pol, unsigned setAxis) -> LxResult
    {
        return m_loc[0]->Start(m_loc,(ILxUnknownID) meshObj, pol, setAxis);
    }

    auto ByLine(const LXtVector pos0, const LXtVector pos1) -> LxResult
    {
        return m_loc[0]->ByLine(m_loc, pos0, pos1);
    }

    auto Done(void) -> int
    {
        return m_loc[0]->Done(m_loc);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_SolidDrill : public CLxLocalize<ILxSolidDrillID>
{
public:
    CLxLoc_SolidDrill()
    {
        _init();
    }

    CLxLoc_SolidDrill(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_SolidDrill(CLxLoc_SolidDrill const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_SolidDrill;
    }

    auto Clear(void) -> LxResult
    {
        return m_loc[0]->Clear(m_loc);
    }

    auto AddMesh(ILxUnknownID meshObj, const LXtMatrix4 xfrm) -> LxResult
    {
        return m_loc[0]->AddMesh(m_loc,(ILxUnknownID) meshObj, xfrm);
    }

    auto Execute(ILxUnknownID meshObj, const LXtMatrix4 xfrm, LXtMarkMode pick, unsigned int mode, const char *sten, ILxUnknownID monitor) -> LxResult
    {
        return m_loc[0]->Execute(m_loc,(ILxUnknownID) meshObj, xfrm, pick, mode, sten,(ILxUnknownID) monitor);
    }

    auto UnifyDrivers(bool solid) -> LxResult
    {
        return m_loc[0]->UnifyDrivers(m_loc, solid);
    }

    auto UnionAll(const LXtMatrix4 xfrm, LXtMarkMode pick, const char *sset, void **ppvObj) -> LxResult
    {
        return m_loc[0]->UnionAll(m_loc, xfrm, pick, sset, ppvObj);
    }

    auto UnionAll(const LXtMatrix4 xfrm, LXtMarkMode pick, const char *sset, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->UnionAll(m_loc, xfrm, pick, sset, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_PolygonEdit : public CLxLocalize<ILxPolygonEditID>
{
public:
    CLxLoc_PolygonEdit()
    {
        _init();
    }

    CLxLoc_PolygonEdit(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_PolygonEdit(CLxLoc_PolygonEdit const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_PolygonEdit;
    }

    auto SetMesh(ILxUnknownID meshObj, ILxUnknownID baseObj) -> LxResult
    {
        return m_loc[0]->SetMesh(m_loc,(ILxUnknownID) meshObj,(ILxUnknownID) baseObj);
    }

    auto SetPolygon(ILxUnknownID meshObj, LXtPolygonID polygonID) -> LxResult
    {
        return m_loc[0]->SetPolygon(m_loc,(ILxUnknownID) meshObj, polygonID);
    }

    auto SetSearchBox(const LXtBBox *box, double tol) -> LxResult
    {
        return m_loc[0]->SetSearchBox(m_loc, box, tol);
    }

    auto SetSearch(int search, double tol) -> LxResult
    {
        return m_loc[0]->SetSearch(m_loc, search, tol);
    }

    auto SetSearchPolygon(LXtPolygonID polygonID, bool search) -> LxResult
    {
        return m_loc[0]->SetSearchPolygon(m_loc, polygonID, search);
    }

    auto ClearSearch(void) -> LxResult
    {
        return m_loc[0]->ClearSearch(m_loc);
    }

    auto NewVertex(const LXtVector pos, LXtPointID *pointID) -> LxResult
    {
        return m_loc[0]->NewVertex(m_loc, pos, pointID);
    }

    auto FindVertex(const LXtVector pos, LXtPointID *pointID) -> LxResult
    {
        return m_loc[0]->FindVertex(m_loc, pos, pointID);
    }

    auto NewLoneVertex(const LXtVector pos, LXtPointID *pointID) -> LxResult
    {
        return m_loc[0]->NewLoneVertex(m_loc, pos, pointID);
    }

    auto CopyVertex(LXtPointID sourceID, const LXtVector pos, LXtPointID *pointID) -> LxResult
    {
        return m_loc[0]->CopyVertex(m_loc, sourceID, pos, pointID);
    }

    auto CopyVrtOfPol(LXtPointID sourceID, LXtPolygonID polygonID, const LXtVector pos, LXtPointID *pointID) -> LxResult
    {
        return m_loc[0]->CopyVrtOfPol(m_loc, sourceID, polygonID, pos, pointID);
    }

    auto AddMiddleVertex(const LXtVector pos, LXtPointID v1, LXtPointID v2, double f, LXtPointID *pointID) -> LxResult
    {
        return m_loc[0]->AddMiddleVertex(m_loc, pos, v1, v2, f, pointID);
    }

    auto AddFaceVertex(const LXtVector pos, LXtPolygonID polygonID, const double *vwt, LXtPointID *pointID) -> LxResult
    {
        return m_loc[0]->AddFaceVertex(m_loc, pos, polygonID, vwt, pointID);
    }

    auto CopyPolygon(ILxUnknownID meshObj, LXtPolygonID sourceID, unsigned int rev, LXtPolygonID *polygonID) -> LxResult
    {
        return m_loc[0]->CopyPolygon(m_loc,(ILxUnknownID) meshObj, sourceID, rev, polygonID);
    }

    auto RenewVList(LXtPolygonID sourceID, unsigned int nvert, const LXtPointID *verts, unsigned int rev, LXtPolygonID *polygonID) -> LxResult
    {
        return m_loc[0]->RenewVList(m_loc, sourceID, nvert, verts, rev, polygonID);
    }

    auto NewPolygon(LXtID4 type, unsigned int nvert, const LXtPointID *verts, unsigned int rev, LXtPolygonID *polygonID) -> LxResult
    {
        return m_loc[0]->NewPolygon(m_loc, type, nvert, verts, rev, polygonID);
    }

    auto DeletePolygon(LXtPolygonID polygonID) -> LxResult
    {
        return m_loc[0]->DeletePolygon(m_loc, polygonID);
    }

    auto RemoveEdges(LXtMarkMode pick, bool keepVertices) -> LxResult
    {
        return m_loc[0]->RemoveEdges(m_loc, pick, keepVertices);
    }

    auto UnwrapStart(LXtPolygonID polygonID) -> LxResult
    {
        return m_loc[0]->UnwrapStart(m_loc, polygonID);
    }

    auto UnwrapAddEdge(LXtPointID v0, LXtPointID v1, bool both) -> LxResult
    {
        return m_loc[0]->UnwrapAddEdge(m_loc, v0, v1, both);
    }

    auto UnwrapDone(const LXtVector axis, unsigned int *npol) -> LxResult
    {
        return m_loc[0]->UnwrapDone(m_loc, axis, npol);
    }

    auto UnwrapPolygonByIndex(unsigned int index, LXtPolygonID *polygonID) -> LxResult
    {
        return m_loc[0]->UnwrapPolygonByIndex(m_loc, index, polygonID);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
