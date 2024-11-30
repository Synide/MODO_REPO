//
// C++ wrapper for lxsdk/lxvectortools.h.
//
//	Copyright 2024.
//
//
#pragma once

#include <lxvectortools.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx
{
    static LXtGUID const guid_VectorCanvas = {0x7A7915F0, {0xE496, 0x40D3}, {0xBD, 0x22, 0x73, 0x3D, 0x73, 0x88, 0x56, 0x52}};
    static LXtGUID const guid_VectorShape = {0x2B56643A, {0x9697, 0x42F4}, {0x99, 0xF9, 0x04, 0xF9, 0x60, 0x38, 0xD4, 0x5E}};
    static LXtGUID const guid_VectorPath = {0x13C5B133, {0x4AE3, 0x4934}, {0xB7, 0x48, 0xE2, 0xB1, 0xD3, 0x90, 0x48, 0x74}};
    static LXtGUID const guid_VectorListener = {0x90310E7B, {0x85DB, 0x4E5D}, {0x83, 0x9B, 0x25, 0x56, 0x2F, 0xF5, 0x07, 0x13}};
} // namespace lx

class CLxImpl_VectorCanvas
{
public:
    virtual ~CLxImpl_VectorCanvas() = default;

    virtual auto canvas_GetItem([[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto canvas_BeginEditBatch([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto canvas_EndEditBatch([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_VectorCanvas_GetItem LxResult canvas_GetItem([[maybe_unused]] void **ppvObj) override
#define LXxO_VectorCanvas_GetItem LXxD_VectorCanvas_GetItem
#define LXxC_VectorCanvas_GetItem(c) LxResult c::canvas_GetItem([[maybe_unused]] void **ppvObj)
#define LXxD_VectorCanvas_BeginEditBatch LxResult canvas_BeginEditBatch() override
#define LXxO_VectorCanvas_BeginEditBatch LXxD_VectorCanvas_BeginEditBatch
#define LXxC_VectorCanvas_BeginEditBatch(c) LxResult c::canvas_BeginEditBatch()
#define LXxD_VectorCanvas_EndEditBatch LxResult canvas_EndEditBatch() override
#define LXxO_VectorCanvas_EndEditBatch LXxD_VectorCanvas_EndEditBatch
#define LXxC_VectorCanvas_EndEditBatch(c) LxResult c::canvas_EndEditBatch()

template <class T>
class CLxIfc_VectorCanvas: public CLxInterface
{
public:
    CLxIfc_VectorCanvas()
    {
        vt.GetItem = GetItem;
        vt.BeginEditBatch = BeginEditBatch;
        vt.EndEditBatch = EndEditBatch;
        vTable = &vt.iunk;
        iid = &lx::guid_VectorCanvas;
    }

    static auto GetItem(LXtObjectID wcom,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_VectorCanvas, loc);
        try
        {
           return loc->canvas_GetItem( ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto BeginEditBatch(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_VectorCanvas, loc);
        try
        {
           return loc->canvas_BeginEditBatch();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto EndEditBatch(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_VectorCanvas, loc);
        try
        {
           return loc->canvas_EndEditBatch();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxVectorCanvas vt;
};

class CLxLoc_VectorCanvas : public CLxLocalize<ILxVectorCanvasID>
{
public:
    CLxLoc_VectorCanvas()
    {
        _init();
    }

    CLxLoc_VectorCanvas(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_VectorCanvas(CLxLoc_VectorCanvas const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_VectorCanvas;
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

    auto BeginEditBatch(void) -> LxResult
    {
        return m_loc[0]->BeginEditBatch(m_loc);
    }

    auto EndEditBatch(void) -> LxResult
    {
        return m_loc[0]->EndEditBatch(m_loc);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_VectorShape
{
public:
    virtual ~CLxImpl_VectorShape() = default;

    virtual auto shape_ShapeCount([[maybe_unused]] unsigned int *count) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto shape_ShapeByIndex([[maybe_unused]] unsigned int index, [[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto shape_Parent([[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto shape_PathCount([[maybe_unused]] unsigned int *count) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto shape_PathByIndex([[maybe_unused]] unsigned int index, [[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto shape_Transform([[maybe_unused]] const LXtMatrix matrix) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_VectorShape_ShapeCount LxResult shape_ShapeCount([[maybe_unused]] unsigned int *count) override
#define LXxO_VectorShape_ShapeCount LXxD_VectorShape_ShapeCount
#define LXxC_VectorShape_ShapeCount(c) LxResult c::shape_ShapeCount([[maybe_unused]] unsigned int *count)
#define LXxD_VectorShape_ShapeByIndex LxResult shape_ShapeByIndex([[maybe_unused]] unsigned int index, [[maybe_unused]] void **ppvObj) override
#define LXxO_VectorShape_ShapeByIndex LXxD_VectorShape_ShapeByIndex
#define LXxC_VectorShape_ShapeByIndex(c) LxResult c::shape_ShapeByIndex([[maybe_unused]] unsigned int index, [[maybe_unused]] void **ppvObj)
#define LXxD_VectorShape_Parent LxResult shape_Parent([[maybe_unused]] void **ppvObj) override
#define LXxO_VectorShape_Parent LXxD_VectorShape_Parent
#define LXxC_VectorShape_Parent(c) LxResult c::shape_Parent([[maybe_unused]] void **ppvObj)
#define LXxD_VectorShape_PathCount LxResult shape_PathCount([[maybe_unused]] unsigned int *count) override
#define LXxO_VectorShape_PathCount LXxD_VectorShape_PathCount
#define LXxC_VectorShape_PathCount(c) LxResult c::shape_PathCount([[maybe_unused]] unsigned int *count)
#define LXxD_VectorShape_PathByIndex LxResult shape_PathByIndex([[maybe_unused]] unsigned int index, [[maybe_unused]] void **ppvObj) override
#define LXxO_VectorShape_PathByIndex LXxD_VectorShape_PathByIndex
#define LXxC_VectorShape_PathByIndex(c) LxResult c::shape_PathByIndex([[maybe_unused]] unsigned int index, [[maybe_unused]] void **ppvObj)
#define LXxD_VectorShape_Transform LxResult shape_Transform([[maybe_unused]] const LXtMatrix matrix) override
#define LXxO_VectorShape_Transform LXxD_VectorShape_Transform
#define LXxC_VectorShape_Transform(c) LxResult c::shape_Transform([[maybe_unused]] const LXtMatrix matrix)

template <class T>
class CLxIfc_VectorShape: public CLxInterface
{
public:
    CLxIfc_VectorShape()
    {
        vt.ShapeCount = ShapeCount;
        vt.ShapeByIndex = ShapeByIndex;
        vt.Parent = Parent;
        vt.PathCount = PathCount;
        vt.PathByIndex = PathByIndex;
        vt.Transform = Transform;
        vTable = &vt.iunk;
        iid = &lx::guid_VectorShape;
    }

    static auto ShapeCount(LXtObjectID wcom,unsigned int *count) -> LxResult
    {
        LXCWxINST (CLxImpl_VectorShape, loc);
        try
        {
           return loc->shape_ShapeCount( count);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ShapeByIndex(LXtObjectID wcom,unsigned int index,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_VectorShape, loc);
        try
        {
           return loc->shape_ShapeByIndex( index, ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Parent(LXtObjectID wcom,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_VectorShape, loc);
        try
        {
           return loc->shape_Parent( ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto PathCount(LXtObjectID wcom,unsigned int *count) -> LxResult
    {
        LXCWxINST (CLxImpl_VectorShape, loc);
        try
        {
           return loc->shape_PathCount( count);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto PathByIndex(LXtObjectID wcom,unsigned int index,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_VectorShape, loc);
        try
        {
           return loc->shape_PathByIndex( index, ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Transform(LXtObjectID wcom,const LXtMatrix matrix) -> LxResult
    {
        LXCWxINST (CLxImpl_VectorShape, loc);
        try
        {
           return loc->shape_Transform( matrix);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxVectorShape vt;
};

class CLxLoc_VectorShape : public CLxLocalize<ILxVectorShapeID>
{
public:
    CLxLoc_VectorShape()
    {
        _init();
    }

    CLxLoc_VectorShape(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_VectorShape(CLxLoc_VectorShape const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_VectorShape;
    }

    auto ShapeCount(unsigned int *count) -> LxResult
    {
        return m_loc[0]->ShapeCount(m_loc, count);
    }

    auto ShapeByIndex(unsigned int index, void **ppvObj) -> LxResult
    {
        return m_loc[0]->ShapeByIndex(m_loc, index, ppvObj);
    }

    auto ShapeByIndex(unsigned int index, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->ShapeByIndex(m_loc, index, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Parent(void **ppvObj) -> LxResult
    {
        return m_loc[0]->Parent(m_loc, ppvObj);
    }

    auto Parent(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Parent(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto PathCount(unsigned int *count) -> LxResult
    {
        return m_loc[0]->PathCount(m_loc, count);
    }

    auto PathByIndex(unsigned int index, void **ppvObj) -> LxResult
    {
        return m_loc[0]->PathByIndex(m_loc, index, ppvObj);
    }

    auto PathByIndex(unsigned int index, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->PathByIndex(m_loc, index, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Transform(const LXtMatrix matrix) -> LxResult
    {
        return m_loc[0]->Transform(m_loc, matrix);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_VectorPath
{
public:
    virtual ~CLxImpl_VectorPath() = default;

    virtual auto path_IsPathClosed([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto path_SetPathClosed([[maybe_unused]] LxResult closed) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto path_KnotCount([[maybe_unused]] unsigned int *count) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto path_SelectKnotByIndex([[maybe_unused]] unsigned int index) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto path_SelectKnot([[maybe_unused]] LXtVectorKnotID knot) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto path_KnotEnumerate([[maybe_unused]] ILxUnknownID visitor) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual LXtVectorKnotID path_ID(void) = 0;

    virtual auto path_Pos([[maybe_unused]] double *x, [[maybe_unused]] double *y) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_VectorPath_IsPathClosed LxResult path_IsPathClosed() override
#define LXxO_VectorPath_IsPathClosed LXxD_VectorPath_IsPathClosed
#define LXxC_VectorPath_IsPathClosed(c) LxResult c::path_IsPathClosed()
#define LXxD_VectorPath_SetPathClosed LxResult path_SetPathClosed([[maybe_unused]] LxResult closed) override
#define LXxO_VectorPath_SetPathClosed LXxD_VectorPath_SetPathClosed
#define LXxC_VectorPath_SetPathClosed(c) LxResult c::path_SetPathClosed([[maybe_unused]] LxResult closed)
#define LXxD_VectorPath_KnotCount LxResult path_KnotCount([[maybe_unused]] unsigned int *count) override
#define LXxO_VectorPath_KnotCount LXxD_VectorPath_KnotCount
#define LXxC_VectorPath_KnotCount(c) LxResult c::path_KnotCount([[maybe_unused]] unsigned int *count)
#define LXxD_VectorPath_SelectKnotByIndex LxResult path_SelectKnotByIndex([[maybe_unused]] unsigned int index) override
#define LXxO_VectorPath_SelectKnotByIndex LXxD_VectorPath_SelectKnotByIndex
#define LXxC_VectorPath_SelectKnotByIndex(c) LxResult c::path_SelectKnotByIndex([[maybe_unused]] unsigned int index)
#define LXxD_VectorPath_SelectKnot LxResult path_SelectKnot([[maybe_unused]] LXtVectorKnotID knot) override
#define LXxO_VectorPath_SelectKnot LXxD_VectorPath_SelectKnot
#define LXxC_VectorPath_SelectKnot(c) LxResult c::path_SelectKnot([[maybe_unused]] LXtVectorKnotID knot)
#define LXxD_VectorPath_KnotEnumerate LxResult path_KnotEnumerate([[maybe_unused]] ILxUnknownID visitor) override
#define LXxO_VectorPath_KnotEnumerate LXxD_VectorPath_KnotEnumerate
#define LXxC_VectorPath_KnotEnumerate(c) LxResult c::path_KnotEnumerate([[maybe_unused]] ILxUnknownID visitor)
#define LXxD_VectorPath_ID LXtVectorKnotID path_ID() override
#define LXxO_VectorPath_ID LXxD_VectorPath_ID
#define LXxC_VectorPath_ID(c) LXtVectorKnotID c::path_ID()
#define LXxD_VectorPath_Pos LxResult path_Pos([[maybe_unused]] double *x, [[maybe_unused]] double *y) override
#define LXxO_VectorPath_Pos LXxD_VectorPath_Pos
#define LXxC_VectorPath_Pos(c) LxResult c::path_Pos([[maybe_unused]] double *x, [[maybe_unused]] double *y)

template <class T>
class CLxIfc_VectorPath: public CLxInterface
{
public:
    CLxIfc_VectorPath()
    {
        vt.IsPathClosed = IsPathClosed;
        vt.SetPathClosed = SetPathClosed;
        vt.KnotCount = KnotCount;
        vt.SelectKnotByIndex = SelectKnotByIndex;
        vt.SelectKnot = SelectKnot;
        vt.KnotEnumerate = KnotEnumerate;
        vt.ID = ID;
        vt.Pos = Pos;
        vTable = &vt.iunk;
        iid = &lx::guid_VectorPath;
    }

    static auto IsPathClosed(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_VectorPath, loc);
        try
        {
           return loc->path_IsPathClosed();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SetPathClosed(LXtObjectID wcom,LxResult closed) -> LxResult
    {
        LXCWxINST (CLxImpl_VectorPath, loc);
        try
        {
           return loc->path_SetPathClosed( closed);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto KnotCount(LXtObjectID wcom,unsigned int *count) -> LxResult
    {
        LXCWxINST (CLxImpl_VectorPath, loc);
        try
        {
           return loc->path_KnotCount( count);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SelectKnotByIndex(LXtObjectID wcom,unsigned int index) -> LxResult
    {
        LXCWxINST (CLxImpl_VectorPath, loc);
        try
        {
           return loc->path_SelectKnotByIndex( index);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SelectKnot(LXtObjectID wcom,LXtVectorKnotID knot) -> LxResult
    {
        LXCWxINST (CLxImpl_VectorPath, loc);
        try
        {
           return loc->path_SelectKnot( knot);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto KnotEnumerate(LXtObjectID wcom,LXtObjectID visitor) -> LxResult
    {
        LXCWxINST (CLxImpl_VectorPath, loc);
        try
        {
           return loc->path_KnotEnumerate((ILxUnknownID) visitor);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ID(LXtObjectID wcom) -> LXtVectorKnotID
    {
        LXCWxINST (CLxImpl_VectorPath, loc);
        return loc->path_ID();
    }

    static auto Pos(LXtObjectID wcom,double *x,double *y) -> LxResult
    {
        LXCWxINST (CLxImpl_VectorPath, loc);
        try
        {
           return loc->path_Pos( x, y);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxVectorPath vt;
};

class CLxLoc_VectorPath : public CLxLocalize<ILxVectorPathID>
{
public:
    CLxLoc_VectorPath()
    {
        _init();
    }

    CLxLoc_VectorPath(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_VectorPath(CLxLoc_VectorPath const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_VectorPath;
    }

    auto IsPathClosed(void) -> LxResult
    {
        return m_loc[0]->IsPathClosed(m_loc);
    }

    auto SetPathClosed(LxResult closed) -> LxResult
    {
        return m_loc[0]->SetPathClosed(m_loc, closed);
    }

    auto KnotCount(unsigned int *count) -> LxResult
    {
        return m_loc[0]->KnotCount(m_loc, count);
    }

    auto SelectKnotByIndex(unsigned int index) -> LxResult
    {
        return m_loc[0]->SelectKnotByIndex(m_loc, index);
    }

    auto SelectKnot(LXtVectorKnotID knot) -> LxResult
    {
        return m_loc[0]->SelectKnot(m_loc, knot);
    }

    auto KnotEnumerate(ILxUnknownID visitor) -> LxResult
    {
        return m_loc[0]->KnotEnumerate(m_loc,(ILxUnknownID) visitor);
    }

    auto ID(void) -> LXtVectorKnotID
    {
        return m_loc[0]->ID(m_loc);
    }

    auto Pos(double *x, double *y) -> LxResult
    {
        return m_loc[0]->Pos(m_loc, x, y);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_VectorListener
{
public:
    virtual ~CLxImpl_VectorListener() = default;

    virtual auto vtl_Destroy([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto vtl_ShapeAdd([[maybe_unused]] ILxUnknownID shape) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto vtl_ShapeRemove([[maybe_unused]] ILxUnknownID shape) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto vtl_ShapeStyle([[maybe_unused]] ILxUnknownID shape, [[maybe_unused]] const char *name) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto vtl_PathAdd([[maybe_unused]] ILxUnknownID shape, [[maybe_unused]] ILxUnknownID path) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto vtl_PathRemove([[maybe_unused]] ILxUnknownID shape, [[maybe_unused]] ILxUnknownID path) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto vtl_KnotPosition([[maybe_unused]] ILxUnknownID shape, [[maybe_unused]] ILxUnknownID path) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_VectorListener_Destroy LxResult vtl_Destroy() override
#define LXxO_VectorListener_Destroy LXxD_VectorListener_Destroy
#define LXxC_VectorListener_Destroy(c) LxResult c::vtl_Destroy()
#define LXxD_VectorListener_ShapeAdd LxResult vtl_ShapeAdd([[maybe_unused]] ILxUnknownID shape) override
#define LXxO_VectorListener_ShapeAdd LXxD_VectorListener_ShapeAdd
#define LXxC_VectorListener_ShapeAdd(c) LxResult c::vtl_ShapeAdd([[maybe_unused]] ILxUnknownID shape)
#define LXxD_VectorListener_ShapeRemove LxResult vtl_ShapeRemove([[maybe_unused]] ILxUnknownID shape) override
#define LXxO_VectorListener_ShapeRemove LXxD_VectorListener_ShapeRemove
#define LXxC_VectorListener_ShapeRemove(c) LxResult c::vtl_ShapeRemove([[maybe_unused]] ILxUnknownID shape)
#define LXxD_VectorListener_ShapeStyle LxResult vtl_ShapeStyle([[maybe_unused]] ILxUnknownID shape, [[maybe_unused]] const char *name) override
#define LXxO_VectorListener_ShapeStyle LXxD_VectorListener_ShapeStyle
#define LXxC_VectorListener_ShapeStyle(c) LxResult c::vtl_ShapeStyle([[maybe_unused]] ILxUnknownID shape, [[maybe_unused]] const char *name)
#define LXxD_VectorListener_PathAdd LxResult vtl_PathAdd([[maybe_unused]] ILxUnknownID shape, [[maybe_unused]] ILxUnknownID path) override
#define LXxO_VectorListener_PathAdd LXxD_VectorListener_PathAdd
#define LXxC_VectorListener_PathAdd(c) LxResult c::vtl_PathAdd([[maybe_unused]] ILxUnknownID shape, [[maybe_unused]] ILxUnknownID path)
#define LXxD_VectorListener_PathRemove LxResult vtl_PathRemove([[maybe_unused]] ILxUnknownID shape, [[maybe_unused]] ILxUnknownID path) override
#define LXxO_VectorListener_PathRemove LXxD_VectorListener_PathRemove
#define LXxC_VectorListener_PathRemove(c) LxResult c::vtl_PathRemove([[maybe_unused]] ILxUnknownID shape, [[maybe_unused]] ILxUnknownID path)
#define LXxD_VectorListener_KnotPosition LxResult vtl_KnotPosition([[maybe_unused]] ILxUnknownID shape, [[maybe_unused]] ILxUnknownID path) override
#define LXxO_VectorListener_KnotPosition LXxD_VectorListener_KnotPosition
#define LXxC_VectorListener_KnotPosition(c) LxResult c::vtl_KnotPosition([[maybe_unused]] ILxUnknownID shape, [[maybe_unused]] ILxUnknownID path)

template <class T>
class CLxIfc_VectorListener: public CLxInterface
{
public:
    CLxIfc_VectorListener()
    {
        vt.Destroy = Destroy;
        vt.ShapeAdd = ShapeAdd;
        vt.ShapeRemove = ShapeRemove;
        vt.ShapeStyle = ShapeStyle;
        vt.PathAdd = PathAdd;
        vt.PathRemove = PathRemove;
        vt.KnotPosition = KnotPosition;
        vTable = &vt.iunk;
        iid = &lx::guid_VectorListener;
    }

    static auto Destroy(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_VectorListener, loc);
        try
        {
           return loc->vtl_Destroy();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ShapeAdd(LXtObjectID wcom,LXtObjectID shape) -> LxResult
    {
        LXCWxINST (CLxImpl_VectorListener, loc);
        try
        {
           return loc->vtl_ShapeAdd((ILxUnknownID) shape);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ShapeRemove(LXtObjectID wcom,LXtObjectID shape) -> LxResult
    {
        LXCWxINST (CLxImpl_VectorListener, loc);
        try
        {
           return loc->vtl_ShapeRemove((ILxUnknownID) shape);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ShapeStyle(LXtObjectID wcom,LXtObjectID shape,const char *name) -> LxResult
    {
        LXCWxINST (CLxImpl_VectorListener, loc);
        try
        {
           return loc->vtl_ShapeStyle((ILxUnknownID) shape, name);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto PathAdd(LXtObjectID wcom,LXtObjectID shape,LXtObjectID path) -> LxResult
    {
        LXCWxINST (CLxImpl_VectorListener, loc);
        try
        {
           return loc->vtl_PathAdd((ILxUnknownID) shape,(ILxUnknownID) path);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto PathRemove(LXtObjectID wcom,LXtObjectID shape,LXtObjectID path) -> LxResult
    {
        LXCWxINST (CLxImpl_VectorListener, loc);
        try
        {
           return loc->vtl_PathRemove((ILxUnknownID) shape,(ILxUnknownID) path);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto KnotPosition(LXtObjectID wcom,LXtObjectID shape,LXtObjectID path) -> LxResult
    {
        LXCWxINST (CLxImpl_VectorListener, loc);
        try
        {
           return loc->vtl_KnotPosition((ILxUnknownID) shape,(ILxUnknownID) path);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxVectorListener vt;
};

class CLxLoc_VectorListener : public CLxLocalize<ILxVectorListenerID>
{
public:
    CLxLoc_VectorListener()
    {
        _init();
    }

    CLxLoc_VectorListener(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_VectorListener(CLxLoc_VectorListener const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_VectorListener;
    }

    auto Destroy(void) -> LxResult
    {
        return m_loc[0]->Destroy(m_loc);
    }

    auto ShapeAdd(ILxUnknownID shape) -> LxResult
    {
        return m_loc[0]->ShapeAdd(m_loc,(ILxUnknownID) shape);
    }

    auto ShapeRemove(ILxUnknownID shape) -> LxResult
    {
        return m_loc[0]->ShapeRemove(m_loc,(ILxUnknownID) shape);
    }

    auto ShapeStyle(ILxUnknownID shape, const char *name) -> LxResult
    {
        return m_loc[0]->ShapeStyle(m_loc,(ILxUnknownID) shape, name);
    }

    auto PathAdd(ILxUnknownID shape, ILxUnknownID path) -> LxResult
    {
        return m_loc[0]->PathAdd(m_loc,(ILxUnknownID) shape,(ILxUnknownID) path);
    }

    auto PathRemove(ILxUnknownID shape, ILxUnknownID path) -> LxResult
    {
        return m_loc[0]->PathRemove(m_loc,(ILxUnknownID) shape,(ILxUnknownID) path);
    }

    auto KnotPosition(ILxUnknownID shape, ILxUnknownID path) -> LxResult
    {
        return m_loc[0]->KnotPosition(m_loc,(ILxUnknownID) shape,(ILxUnknownID) path);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
