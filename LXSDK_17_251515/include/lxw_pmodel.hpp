//
// C++ wrapper for lxsdk/lxpmodel.h.
//
//	Copyright 2024.
//
//
#pragma once

#include <lxpmodel.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx
{
    static LXtGUID const guid_MeshElementGroup = {0x4773EA40, {0xC2D6, 0x4B55}, {0x80, 0x0C, 0x59, 0xFF, 0x6E, 0x97, 0x30, 0xB7}};
    static LXtGUID const guid_SelectionOperation = {0xAA86E146, {0x36F1, 0x44C3}, {0xB1, 0x70, 0x01, 0x07, 0xF6, 0x00, 0x94, 0x1D}};
    static LXtGUID const guid_SelectionOperation1 = {0x563E56B1, {0xACC9, 0x4E3F}, {0xB3, 0xA8, 0xE0, 0xAF, 0xE2, 0xAB, 0x56, 0x45}};
    static LXtGUID const guid_SelectionState = {0xD1F068A3, {0x5DFC, 0x4587}, {0xAD, 0x63, 0xFE, 0x1D, 0x4D, 0x05, 0x01, 0xED}};
} // namespace lx

class CLxImpl_MeshElementGroup
{
public:
    virtual ~CLxImpl_MeshElementGroup() = default;

    virtual auto eltgrp_GroupCount([[maybe_unused]] unsigned int *count) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto eltgrp_GroupName([[maybe_unused]] unsigned int index, [[maybe_unused]] const char **name) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto eltgrp_GroupUserName([[maybe_unused]] unsigned int index, [[maybe_unused]] const char **username) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto eltgrp_TestPoint([[maybe_unused]] unsigned int index, [[maybe_unused]] LXtPointID point) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto eltgrp_TestEdge([[maybe_unused]] unsigned int index, [[maybe_unused]] LXtEdgeID edge) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto eltgrp_TestPolygon([[maybe_unused]] unsigned int index, [[maybe_unused]] LXtPolygonID polygon) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_MeshElementGroup_GroupCount LxResult eltgrp_GroupCount([[maybe_unused]] unsigned int *count) override
#define LXxO_MeshElementGroup_GroupCount LXxD_MeshElementGroup_GroupCount
#define LXxC_MeshElementGroup_GroupCount(c) LxResult c::eltgrp_GroupCount([[maybe_unused]] unsigned int *count)
#define LXxD_MeshElementGroup_GroupName LxResult eltgrp_GroupName([[maybe_unused]] unsigned int index, [[maybe_unused]] const char **name) override
#define LXxO_MeshElementGroup_GroupName LXxD_MeshElementGroup_GroupName
#define LXxC_MeshElementGroup_GroupName(c) LxResult c::eltgrp_GroupName([[maybe_unused]] unsigned int index, [[maybe_unused]] const char **name)
#define LXxD_MeshElementGroup_GroupUserName LxResult eltgrp_GroupUserName([[maybe_unused]] unsigned int index, [[maybe_unused]] const char **username) override
#define LXxO_MeshElementGroup_GroupUserName LXxD_MeshElementGroup_GroupUserName
#define LXxC_MeshElementGroup_GroupUserName(c) LxResult c::eltgrp_GroupUserName([[maybe_unused]] unsigned int index, [[maybe_unused]] const char **username)
#define LXxD_MeshElementGroup_TestPoint LxResult eltgrp_TestPoint([[maybe_unused]] unsigned int index, [[maybe_unused]] LXtPointID point) override
#define LXxO_MeshElementGroup_TestPoint LXxD_MeshElementGroup_TestPoint
#define LXxC_MeshElementGroup_TestPoint(c) LxResult c::eltgrp_TestPoint([[maybe_unused]] unsigned int index, [[maybe_unused]] LXtPointID point)
#define LXxD_MeshElementGroup_TestEdge LxResult eltgrp_TestEdge([[maybe_unused]] unsigned int index, [[maybe_unused]] LXtEdgeID edge) override
#define LXxO_MeshElementGroup_TestEdge LXxD_MeshElementGroup_TestEdge
#define LXxC_MeshElementGroup_TestEdge(c) LxResult c::eltgrp_TestEdge([[maybe_unused]] unsigned int index, [[maybe_unused]] LXtEdgeID edge)
#define LXxD_MeshElementGroup_TestPolygon LxResult eltgrp_TestPolygon([[maybe_unused]] unsigned int index, [[maybe_unused]] LXtPolygonID polygon) override
#define LXxO_MeshElementGroup_TestPolygon LXxD_MeshElementGroup_TestPolygon
#define LXxC_MeshElementGroup_TestPolygon(c) LxResult c::eltgrp_TestPolygon([[maybe_unused]] unsigned int index, [[maybe_unused]] LXtPolygonID polygon)

template <class T>
class CLxIfc_MeshElementGroup: public CLxInterface
{
public:
    CLxIfc_MeshElementGroup()
    {
        vt.GroupCount = GroupCount;
        vt.GroupName = GroupName;
        vt.GroupUserName = GroupUserName;
        vt.TestPoint = TestPoint;
        vt.TestEdge = TestEdge;
        vt.TestPolygon = TestPolygon;
        vTable = &vt.iunk;
        iid = &lx::guid_MeshElementGroup;
    }

    static auto GroupCount(LXtObjectID wcom,unsigned int *count) -> LxResult
    {
        LXCWxINST (CLxImpl_MeshElementGroup, loc);
        try
        {
           return loc->eltgrp_GroupCount( count);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto GroupName(LXtObjectID wcom,unsigned int index,const char **name) -> LxResult
    {
        LXCWxINST (CLxImpl_MeshElementGroup, loc);
        try
        {
           return loc->eltgrp_GroupName( index, name);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto GroupUserName(LXtObjectID wcom,unsigned int index,const char **username) -> LxResult
    {
        LXCWxINST (CLxImpl_MeshElementGroup, loc);
        try
        {
           return loc->eltgrp_GroupUserName( index, username);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto TestPoint(LXtObjectID wcom,unsigned int index,LXtPointID point) -> LxResult
    {
        LXCWxINST (CLxImpl_MeshElementGroup, loc);
        try
        {
           return loc->eltgrp_TestPoint( index, point);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto TestEdge(LXtObjectID wcom,unsigned int index,LXtEdgeID edge) -> LxResult
    {
        LXCWxINST (CLxImpl_MeshElementGroup, loc);
        try
        {
           return loc->eltgrp_TestEdge( index, edge);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto TestPolygon(LXtObjectID wcom,unsigned int index,LXtPolygonID polygon) -> LxResult
    {
        LXCWxINST (CLxImpl_MeshElementGroup, loc);
        try
        {
           return loc->eltgrp_TestPolygon( index, polygon);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxMeshElementGroup vt;
};

class CLxLoc_MeshElementGroup : public CLxLocalize<ILxMeshElementGroupID>
{
public:
    CLxLoc_MeshElementGroup()
    {
        _init();
    }

    CLxLoc_MeshElementGroup(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_MeshElementGroup(CLxLoc_MeshElementGroup const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_MeshElementGroup;
    }

    auto GroupCount(unsigned int *count) -> LxResult
    {
        return m_loc[0]->GroupCount(m_loc, count);
    }

    auto GroupName(unsigned int index, const char **name) -> LxResult
    {
        return m_loc[0]->GroupName(m_loc, index, name);
    }

    auto GroupUserName(unsigned int index, const char **username) -> LxResult
    {
        return m_loc[0]->GroupUserName(m_loc, index, username);
    }

    auto TestPoint(unsigned int index, LXtPointID point) -> LxResult
    {
        return m_loc[0]->TestPoint(m_loc, index, point);
    }

    auto TestEdge(unsigned int index, LXtEdgeID edge) -> LxResult
    {
        return m_loc[0]->TestEdge(m_loc, index, edge);
    }

    auto TestPolygon(unsigned int index, LXtPolygonID polygon) -> LxResult
    {
        return m_loc[0]->TestPolygon(m_loc, index, polygon);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_SelectionOperation
{
public:
    virtual ~CLxImpl_SelectionOperation() = default;

    virtual auto selop_SetMesh([[maybe_unused]] ILxUnknownID mesh) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto selop_SetTransform([[maybe_unused]] LXtMatrix4 xfrm) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto selop_TestPoint([[maybe_unused]] LXtPointID point) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto selop_TestEdge([[maybe_unused]] LXtEdgeID edge) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto selop_TestPolygon([[maybe_unused]] LXtPolygonID polygon) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto selop_Evaluate([[maybe_unused]] LXtID4 type, [[maybe_unused]] ILxUnknownID state) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_SelectionOperation_SetMesh LxResult selop_SetMesh([[maybe_unused]] ILxUnknownID mesh) override
#define LXxO_SelectionOperation_SetMesh LXxD_SelectionOperation_SetMesh
#define LXxC_SelectionOperation_SetMesh(c) LxResult c::selop_SetMesh([[maybe_unused]] ILxUnknownID mesh)
#define LXxD_SelectionOperation_SetTransform LxResult selop_SetTransform([[maybe_unused]] LXtMatrix4 xfrm) override
#define LXxO_SelectionOperation_SetTransform LXxD_SelectionOperation_SetTransform
#define LXxC_SelectionOperation_SetTransform(c) LxResult c::selop_SetTransform([[maybe_unused]] LXtMatrix4 xfrm)
#define LXxD_SelectionOperation_TestPoint LxResult selop_TestPoint([[maybe_unused]] LXtPointID point) override
#define LXxO_SelectionOperation_TestPoint LXxD_SelectionOperation_TestPoint
#define LXxC_SelectionOperation_TestPoint(c) LxResult c::selop_TestPoint([[maybe_unused]] LXtPointID point)
#define LXxD_SelectionOperation_TestEdge LxResult selop_TestEdge([[maybe_unused]] LXtEdgeID edge) override
#define LXxO_SelectionOperation_TestEdge LXxD_SelectionOperation_TestEdge
#define LXxC_SelectionOperation_TestEdge(c) LxResult c::selop_TestEdge([[maybe_unused]] LXtEdgeID edge)
#define LXxD_SelectionOperation_TestPolygon LxResult selop_TestPolygon([[maybe_unused]] LXtPolygonID polygon) override
#define LXxO_SelectionOperation_TestPolygon LXxD_SelectionOperation_TestPolygon
#define LXxC_SelectionOperation_TestPolygon(c) LxResult c::selop_TestPolygon([[maybe_unused]] LXtPolygonID polygon)
#define LXxD_SelectionOperation_Evaluate LxResult selop_Evaluate([[maybe_unused]] LXtID4 type, [[maybe_unused]] ILxUnknownID state) override
#define LXxO_SelectionOperation_Evaluate LXxD_SelectionOperation_Evaluate
#define LXxC_SelectionOperation_Evaluate(c) LxResult c::selop_Evaluate([[maybe_unused]] LXtID4 type, [[maybe_unused]] ILxUnknownID state)

template <class T>
class CLxIfc_SelectionOperation: public CLxInterface
{
public:
    CLxIfc_SelectionOperation()
    {
        vt.SetMesh = SetMesh;
        vt.SetTransform = SetTransform;
        vt.TestPoint = TestPoint;
        vt.TestEdge = TestEdge;
        vt.TestPolygon = TestPolygon;
        vt.Evaluate = Evaluate;
        vTable = &vt.iunk;
        iid = &lx::guid_SelectionOperation;
    }

    static auto SetMesh(LXtObjectID wcom,LXtObjectID mesh) -> LxResult
    {
        LXCWxINST (CLxImpl_SelectionOperation, loc);
        try
        {
           return loc->selop_SetMesh((ILxUnknownID) mesh);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SetTransform(LXtObjectID wcom,LXtMatrix4 xfrm) -> LxResult
    {
        LXCWxINST (CLxImpl_SelectionOperation, loc);
        try
        {
           return loc->selop_SetTransform( xfrm);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto TestPoint(LXtObjectID wcom,LXtPointID point) -> LxResult
    {
        LXCWxINST (CLxImpl_SelectionOperation, loc);
        try
        {
           return loc->selop_TestPoint( point);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto TestEdge(LXtObjectID wcom,LXtEdgeID edge) -> LxResult
    {
        LXCWxINST (CLxImpl_SelectionOperation, loc);
        try
        {
           return loc->selop_TestEdge( edge);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto TestPolygon(LXtObjectID wcom,LXtPolygonID polygon) -> LxResult
    {
        LXCWxINST (CLxImpl_SelectionOperation, loc);
        try
        {
           return loc->selop_TestPolygon( polygon);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Evaluate(LXtObjectID wcom,LXtID4 type,LXtObjectID state) -> LxResult
    {
        LXCWxINST (CLxImpl_SelectionOperation, loc);
        try
        {
           return loc->selop_Evaluate( type,(ILxUnknownID) state);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxSelectionOperation vt;
};

class CLxLoc_SelectionOperation : public CLxLocalize<ILxSelectionOperationID>
{
public:
    CLxLoc_SelectionOperation()
    {
        _init();
    }

    CLxLoc_SelectionOperation(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_SelectionOperation(CLxLoc_SelectionOperation const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_SelectionOperation;
    }

    auto SetMesh(ILxUnknownID mesh) -> LxResult
    {
        return m_loc[0]->SetMesh(m_loc,(ILxUnknownID) mesh);
    }

    auto SetTransform(LXtMatrix4 xfrm) -> LxResult
    {
        return m_loc[0]->SetTransform(m_loc, xfrm);
    }

    auto TestPoint(LXtPointID point) -> LxResult
    {
        return m_loc[0]->TestPoint(m_loc, point);
    }

    auto TestEdge(LXtEdgeID edge) -> LxResult
    {
        return m_loc[0]->TestEdge(m_loc, edge);
    }

    auto TestPolygon(LXtPolygonID polygon) -> LxResult
    {
        return m_loc[0]->TestPolygon(m_loc, polygon);
    }

    auto Evaluate(LXtID4 type, ILxUnknownID state) -> LxResult
    {
        return m_loc[0]->Evaluate(m_loc, type,(ILxUnknownID) state);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};

class CLxLoc_SelectionState : public CLxLocalize<ILxSelectionStateID>
{
public:
    CLxLoc_SelectionState()
    {
        _init();
    }

    CLxLoc_SelectionState(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_SelectionState(CLxLoc_SelectionState const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_SelectionState;
    }

    auto TestPoint(LXtPointID point) -> LxResult
    {
        return m_loc[0]->TestPoint(m_loc, point);
    }

    auto TestEdge(LXtEdgeID edge) -> LxResult
    {
        return m_loc[0]->TestEdge(m_loc, edge);
    }

    auto TestPolygon(LXtPolygonID polygon) -> LxResult
    {
        return m_loc[0]->TestPolygon(m_loc, polygon);
    }

    auto SetPoint(LXtPointID point, LxResult state) -> LxResult
    {
        return m_loc[0]->SetPoint(m_loc, point, state);
    }

    auto SetEdge(LXtEdgeID edge, LxResult state) -> LxResult
    {
        return m_loc[0]->SetEdge(m_loc, edge, state);
    }

    auto SetPolygon(LXtPolygonID polygon, LxResult state) -> LxResult
    {
        return m_loc[0]->SetPolygon(m_loc, polygon, state);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
