//
// C++ wrapper for lxsdk/lxtool.h.
//
//	Copyright 2024.
//
//
#pragma once

#include <lxtool.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx
{
    static LXtGUID const guid_Tool = {0xB2E6874C, {0xEDD1, 0x4F60}, {0x8B, 0x3C, 0xF5, 0x65, 0x03, 0xF9, 0x61, 0x86}};
    static LXtGUID const guid_Tool1 = {0x12E79F81, {0x565E, 0x11D7}, {0xA4, 0xCF, 0x00, 0x0A, 0x95, 0x76, 0x5C, 0x9E}};
    static LXtGUID const guid_AttrSequence = {0xF54FEF16, {0x223F, 0x439D}, {0x85, 0x93, 0x6F, 0x35, 0x07, 0x83, 0x99, 0x3E}};
    static LXtGUID const guid_ToolOperation = {0x116E5285, {0x6C4A, 0x44E8}, {0x9D, 0xC8, 0x71, 0x5E, 0x69, 0xA6, 0x47, 0xA0}};
    static LXtGUID const guid_ToolOperation1 = {0x9239B41C, {0xAC58, 0x44D5}, {0x8E, 0x5E, 0xB9, 0x59, 0x30, 0xE8, 0x71, 0x96}};
    static LXtGUID const guid_FalloffPacket = {0xB0EA09EB, {0xB022, 0x4AE2}, {0x90, 0x3A, 0x4A, 0x0F, 0x5C, 0xA3, 0x38, 0x35}};
    static LXtGUID const guid_FalloffPacket1 = {0xD0F8CF5D, {0x1BB5, 0x4002}, {0x81, 0x0B, 0x0E, 0x7E, 0xF3, 0x4B, 0x78, 0x67}};
    static LXtGUID const guid_SymmetryPacket = {0xF13F6933, {0x1289, 0x4EFC}, {0x9C, 0xE1, 0xD5, 0xC4, 0xF1, 0x3E, 0xE7, 0xD8}};
    static LXtGUID const guid_Subject2Packet = {0xCA342D92, {0x26C8, 0x4A25}, {0xAD, 0x27, 0x01, 0x63, 0xAD, 0x54, 0x73, 0x0D}};
    static LXtGUID const guid_TexturePacket = {0x851271E5, {0xF4F4, 0x444D}, {0xA8, 0x7A, 0x56, 0x3B, 0x9E, 0x1E, 0x6E, 0xFB}};
    static LXtGUID const guid_ElementAxisPacket = {0x292A47BF, {0x3CF5, 0x492D}, {0xAA, 0xFD, 0xAE, 0x76, 0x10, 0x92, 0xA7, 0x82}};
    static LXtGUID const guid_ElementCenterPacket = {0x5221C415, {0x073A, 0x4610}, {0xBC, 0xB6, 0xF8, 0x20, 0xF8, 0xD7, 0xF6, 0xD0}};
    static LXtGUID const guid_PathGeneratorPacket = {0x284B625A, {0xC82E, 0x4103}, {0xA8, 0xE0, 0xF7, 0x84, 0x86, 0x87, 0xBD, 0x4B}};
    static LXtGUID const guid_BagGenerator = {0x9A368FAA, {0x7576, 0x42B9}, {0x9B, 0x6A, 0xC2, 0xF8, 0xD3, 0x46, 0x12, 0xF0}};
    static LXtGUID const guid_PathStep = {0xB9F58563, {0xFBA0, 0x4CA2}, {0x86, 0x6B, 0x1D, 0xD6, 0x41, 0x74, 0xA2, 0x77}};
    static LXtGUID const guid_PathGeneratorPacket1 = {0xAE70D946, {0x8A9A, 0x4A72}, {0x95, 0xEC, 0xBF, 0xF8, 0x56, 0x39, 0x1D, 0x22}};
    static LXtGUID const guid_ParticleGeneratorPacket = {0xEF9E8BC9, {0xB875, 0x40FC}, {0x8A, 0x30, 0xD3, 0xB2, 0x88, 0xCB, 0xC2, 0x4C}};
    static LXtGUID const guid_ParticleGeneratorPacket2 = {0x36001340, {0xF153, 0x4B32}, {0x82, 0xA4, 0x7D, 0xA4, 0x38, 0x96, 0x93, 0x71}};
    static LXtGUID const guid_ParticleGeneratorPacket1 = {0x5CDF5B58, {0x46BF, 0x4D78}, {0x86, 0x52, 0x65, 0x9E, 0x87, 0xE1, 0x9C, 0x4B}};
} // namespace lx

class CLxImpl_Tool
{
public:
    virtual ~CLxImpl_Tool() = default;

    virtual void tool_Reset([[maybe_unused]] void)
    {
    }

    virtual void tool_Evaluate([[maybe_unused]] ILxUnknownID vts)
    {
    }

    virtual LXtObjectID tool_VectorType(void) = 0;

    virtual const char * tool_Order(void) = 0;

    virtual LXtID4 tool_Task(void) = 0;

    virtual auto tool_Sequence([[maybe_unused]] ILxUnknownID seq) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto tool_ShouldBeAttribute([[maybe_unused]] LXtID4 task) -> int
    {
        return 0;
    }

    virtual auto tool_GetOp([[maybe_unused]] void **ppvObj, [[maybe_unused]] unsigned flags) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto tool_CompareOp([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID toolop) -> unsigned
    {
        return LXiTOOLOP_DIFFERENT;
    }

    virtual auto tool_UpdateOp([[maybe_unused]] ILxUnknownID toolop) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_Tool_Reset void tool_Reset() override
#define LXxO_Tool_Reset LXxD_Tool_Reset
#define LXxC_Tool_Reset(c) void c::tool_Reset()
#define LXxD_Tool_Evaluate void tool_Evaluate([[maybe_unused]] ILxUnknownID vts) override
#define LXxO_Tool_Evaluate LXxD_Tool_Evaluate
#define LXxC_Tool_Evaluate(c) void c::tool_Evaluate([[maybe_unused]] ILxUnknownID vts)
#define LXxD_Tool_VectorType LXtObjectID tool_VectorType() override
#define LXxO_Tool_VectorType LXxD_Tool_VectorType
#define LXxC_Tool_VectorType(c) LXtObjectID c::tool_VectorType()
#define LXxD_Tool_Order const char * tool_Order() override
#define LXxO_Tool_Order LXxD_Tool_Order
#define LXxC_Tool_Order(c) const char * c::tool_Order()
#define LXxD_Tool_Task LXtID4 tool_Task() override
#define LXxO_Tool_Task LXxD_Tool_Task
#define LXxC_Tool_Task(c) LXtID4 c::tool_Task()
#define LXxD_Tool_Sequence LxResult tool_Sequence([[maybe_unused]] ILxUnknownID seq) override
#define LXxO_Tool_Sequence LXxD_Tool_Sequence
#define LXxC_Tool_Sequence(c) LxResult c::tool_Sequence([[maybe_unused]] ILxUnknownID seq)
#define LXxD_Tool_ShouldBeAttribute int tool_ShouldBeAttribute([[maybe_unused]] LXtID4 task) override
#define LXxO_Tool_ShouldBeAttribute LXxD_Tool_ShouldBeAttribute
#define LXxC_Tool_ShouldBeAttribute(c) int c::tool_ShouldBeAttribute([[maybe_unused]] LXtID4 task)
#define LXxD_Tool_GetOp LxResult tool_GetOp([[maybe_unused]] void **ppvObj, [[maybe_unused]] unsigned flags) override
#define LXxO_Tool_GetOp LXxD_Tool_GetOp
#define LXxC_Tool_GetOp(c) LxResult c::tool_GetOp([[maybe_unused]] void **ppvObj, [[maybe_unused]] unsigned flags)
#define LXxD_Tool_CompareOp unsigned tool_CompareOp([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID toolop) override
#define LXxO_Tool_CompareOp LXxD_Tool_CompareOp
#define LXxC_Tool_CompareOp(c) unsigned c::tool_CompareOp([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID toolop)
#define LXxD_Tool_UpdateOp LxResult tool_UpdateOp([[maybe_unused]] ILxUnknownID toolop) override
#define LXxO_Tool_UpdateOp LXxD_Tool_UpdateOp
#define LXxC_Tool_UpdateOp(c) LxResult c::tool_UpdateOp([[maybe_unused]] ILxUnknownID toolop)

template <class T>
class CLxIfc_Tool: public CLxInterface
{
public:
    CLxIfc_Tool()
    {
        vt.Reset = Reset;
        vt.Evaluate = Evaluate;
        vt.VectorType = VectorType;
        vt.Order = Order;
        vt.Task = Task;
        vt.Sequence = Sequence;
        vt.ShouldBeAttribute = ShouldBeAttribute;
        vt.GetOp = GetOp;
        vt.CompareOp = CompareOp;
        vt.UpdateOp = UpdateOp;
        vTable = &vt.iunk;
        iid = &lx::guid_Tool;
    }

    static auto Reset(LXtObjectID wcom) -> void
    {
        LXCWxINST (CLxImpl_Tool, loc);
        loc->tool_Reset();
    }

    static auto Evaluate(LXtObjectID wcom,LXtObjectID vts) -> void
    {
        LXCWxINST (CLxImpl_Tool, loc);
        loc->tool_Evaluate((ILxUnknownID) vts);
    }

    static auto VectorType(LXtObjectID wcom) -> LXtObjectID
    {
        LXCWxINST (CLxImpl_Tool, loc);
        return loc->tool_VectorType();
    }

    static auto Order(LXtObjectID wcom) -> const char *
    {
        LXCWxINST (CLxImpl_Tool, loc);
        return loc->tool_Order();
    }

    static auto Task(LXtObjectID wcom) -> LXtID4
    {
        LXCWxINST (CLxImpl_Tool, loc);
        return loc->tool_Task();
    }

    static auto Sequence(LXtObjectID wcom,LXtObjectID seq) -> LxResult
    {
        LXCWxINST (CLxImpl_Tool, loc);
        try
        {
           return loc->tool_Sequence((ILxUnknownID) seq);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ShouldBeAttribute(LXtObjectID wcom,LXtID4 task) -> int
    {
        LXCWxINST (CLxImpl_Tool, loc);
        return loc->tool_ShouldBeAttribute( task);
    }

    static auto GetOp(LXtObjectID wcom,void **ppvObj,unsigned flags) -> LxResult
    {
        LXCWxINST (CLxImpl_Tool, loc);
        try
        {
           return loc->tool_GetOp( ppvObj, flags);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto CompareOp(LXtObjectID wcom,LXtObjectID vts,LXtObjectID toolop) -> unsigned
    {
        LXCWxINST (CLxImpl_Tool, loc);
        return loc->tool_CompareOp((ILxUnknownID) vts,(ILxUnknownID) toolop);
    }

    static auto UpdateOp(LXtObjectID wcom,LXtObjectID toolop) -> LxResult
    {
        LXCWxINST (CLxImpl_Tool, loc);
        try
        {
           return loc->tool_UpdateOp((ILxUnknownID) toolop);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxTool vt;
};

class CLxLoc_Tool : public CLxLocalize<ILxToolID>
{
public:
    CLxLoc_Tool()
    {
        _init();
    }

    CLxLoc_Tool(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_Tool(CLxLoc_Tool const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_Tool;
    }

    auto Reset(void) -> void
    {
        m_loc[0]->Reset(m_loc);
    }

    auto Evaluate(ILxUnknownID vts) -> void
    {
        m_loc[0]->Evaluate(m_loc,(ILxUnknownID) vts);
    }

    auto VectorType(void) -> ILxUnknownID
    {
        return (ILxUnknownID)m_loc[0]->VectorType(m_loc);
    }

    auto Order(void) -> const char *
    {
        return m_loc[0]->Order(m_loc);
    }

    auto Task(void) -> LXtID4
    {
        return m_loc[0]->Task(m_loc);
    }

    auto Sequence(ILxUnknownID seq) -> LxResult
    {
        return m_loc[0]->Sequence(m_loc,(ILxUnknownID) seq);
    }

    auto ShouldBeAttribute(LXtID4 task) -> int
    {
        return m_loc[0]->ShouldBeAttribute(m_loc, task);
    }

    auto GetOp(void **ppvObj, unsigned flags) -> LxResult
    {
        return m_loc[0]->GetOp(m_loc, ppvObj, flags);
    }

    auto GetOp(CLxLocalizedObject &o_dest, unsigned flags) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->GetOp(m_loc, &o_obj, flags);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto CompareOp(ILxUnknownID vts, ILxUnknownID toolop) -> unsigned
    {
        return m_loc[0]->CompareOp(m_loc,(ILxUnknownID) vts,(ILxUnknownID) toolop);
    }

    auto UpdateOp(ILxUnknownID toolop) -> LxResult
    {
        return m_loc[0]->UpdateOp(m_loc,(ILxUnknownID) toolop);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};

class CLxLoc_AttrSequence : public CLxLocalize<ILxAttrSequenceID>
{
public:
    CLxLoc_AttrSequence()
    {
        _init();
    }

    CLxLoc_AttrSequence(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_AttrSequence(CLxLoc_AttrSequence const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_AttrSequence;
    }

    auto Integer(const char *name, int value) -> LxResult
    {
        return m_loc[0]->Integer(m_loc, name, value);
    }

    auto Float(const char *name, double value) -> LxResult
    {
        return m_loc[0]->Float(m_loc, name, value);
    }

    auto String(const char *name, const char *value) -> LxResult
    {
        return m_loc[0]->String(m_loc, name, value);
    }

    auto Value(const char *name, ILxUnknownID value) -> LxResult
    {
        return m_loc[0]->Value(m_loc, name,(ILxUnknownID) value);
    }

    auto HaulingOverride(const char *name, const char *value) -> LxResult
    {
        return m_loc[0]->HaulingOverride(m_loc, name, value);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_ToolOperation
{
public:
    virtual ~CLxImpl_ToolOperation() = default;

    virtual auto top_Evaluate([[maybe_unused]] ILxUnknownID vts) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto top_ReEvaluate([[maybe_unused]] ILxUnknownID vts) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto top_Blend([[maybe_unused]] ILxUnknownID other, [[maybe_unused]] ILxUnknownID blend) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_ToolOperation_Evaluate LxResult top_Evaluate([[maybe_unused]] ILxUnknownID vts) override
#define LXxO_ToolOperation_Evaluate LXxD_ToolOperation_Evaluate
#define LXxC_ToolOperation_Evaluate(c) LxResult c::top_Evaluate([[maybe_unused]] ILxUnknownID vts)
#define LXxD_ToolOperation_ReEvaluate LxResult top_ReEvaluate([[maybe_unused]] ILxUnknownID vts) override
#define LXxO_ToolOperation_ReEvaluate LXxD_ToolOperation_ReEvaluate
#define LXxC_ToolOperation_ReEvaluate(c) LxResult c::top_ReEvaluate([[maybe_unused]] ILxUnknownID vts)
#define LXxD_ToolOperation_Blend LxResult top_Blend([[maybe_unused]] ILxUnknownID other, [[maybe_unused]] ILxUnknownID blend) override
#define LXxO_ToolOperation_Blend LXxD_ToolOperation_Blend
#define LXxC_ToolOperation_Blend(c) LxResult c::top_Blend([[maybe_unused]] ILxUnknownID other, [[maybe_unused]] ILxUnknownID blend)

template <class T>
class CLxIfc_ToolOperation: public CLxInterface
{
public:
    CLxIfc_ToolOperation()
    {
        vt.Evaluate = Evaluate;
        vt.ReEvaluate = ReEvaluate;
        vt.Blend = Blend;
        vTable = &vt.iunk;
        iid = &lx::guid_ToolOperation;
    }

    static auto Evaluate(LXtObjectID wcom,LXtObjectID vts) -> LxResult
    {
        LXCWxINST (CLxImpl_ToolOperation, loc);
        try
        {
           return loc->top_Evaluate((ILxUnknownID) vts);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ReEvaluate(LXtObjectID wcom,LXtObjectID vts) -> LxResult
    {
        LXCWxINST (CLxImpl_ToolOperation, loc);
        try
        {
           return loc->top_ReEvaluate((ILxUnknownID) vts);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Blend(LXtObjectID wcom,LXtObjectID other,LXtObjectID blend) -> LxResult
    {
        LXCWxINST (CLxImpl_ToolOperation, loc);
        try
        {
           return loc->top_Blend((ILxUnknownID) other,(ILxUnknownID) blend);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxToolOperation vt;
};

class CLxLoc_ToolOperation : public CLxLocalize<ILxToolOperationID>
{
public:
    CLxLoc_ToolOperation()
    {
        _init();
    }

    CLxLoc_ToolOperation(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_ToolOperation(CLxLoc_ToolOperation const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_ToolOperation;
    }

    auto Evaluate(ILxUnknownID vts) -> LxResult
    {
        return m_loc[0]->Evaluate(m_loc,(ILxUnknownID) vts);
    }

    auto ReEvaluate(ILxUnknownID vts) -> LxResult
    {
        return m_loc[0]->ReEvaluate(m_loc,(ILxUnknownID) vts);
    }

    auto Blend(ILxUnknownID other, ILxUnknownID blend) -> LxResult
    {
        return m_loc[0]->Blend(m_loc,(ILxUnknownID) other,(ILxUnknownID) blend);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};

class CLxLoc_FalloffPacket : public CLxLocalize<ILxFalloffPacketID>
{
public:
    CLxLoc_FalloffPacket()
    {
        _init();
    }

    CLxLoc_FalloffPacket(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_FalloffPacket(CLxLoc_FalloffPacket const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_FalloffPacket;
    }

    auto Evaluate(LXtFVector pos, LXtPointID vrx, LXtPolygonID poly) -> double
    {
        return m_loc[0]->Evaluate(m_loc, pos, vrx, poly);
    }

    auto Screen(ILxUnknownID vts, int x, int y) -> double
    {
        return m_loc[0]->Screen(m_loc,(ILxUnknownID) vts, x, y);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};

class CLxLoc_SymmetryPacket : public CLxLocalize<ILxSymmetryPacketID>
{
public:
    CLxLoc_SymmetryPacket()
    {
        _init();
    }

    CLxLoc_SymmetryPacket(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_SymmetryPacket(CLxLoc_SymmetryPacket const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_SymmetryPacket;
    }

    auto Active(void) -> int
    {
        return m_loc[0]->Active(m_loc);
    }

    auto Axis(LXtFVector axvec, float *offset) -> int
    {
        return m_loc[0]->Axis(m_loc, axvec, offset);
    }

    auto Point(LXtMeshID mesh, LXtPointID vrx) -> LXtPointID
    {
        return m_loc[0]->Point(m_loc, mesh, vrx);
    }

    auto Polygon(LXtMeshID mesh, LXtPolygonID pol) -> LXtPolygonID
    {
        return m_loc[0]->Polygon(m_loc, mesh, pol);
    }

    auto Edge(LXtMeshID mesh, LXtEdgeID edge) -> LXtEdgeID
    {
        return m_loc[0]->Edge(m_loc, mesh, edge);
    }

    auto Position(const LXtFVector pos, LXtFVector sv) -> int
    {
        return m_loc[0]->Position(m_loc, pos, sv);
    }

    auto BaseSide(void) -> int
    {
        return m_loc[0]->BaseSide(m_loc);
    }

    auto SetBase(const LXtFVector pos) -> void
    {
        m_loc[0]->SetBase(m_loc, pos);
    }

    auto TestSide(const LXtFVector pos, int useBase) -> int
    {
        return m_loc[0]->TestSide(m_loc, pos, useBase);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_Subject2Packet : public CLxLocalize<ILxSubject2PacketID>
{
public:
    CLxLoc_Subject2Packet()
    {
        _init();
    }

    CLxLoc_Subject2Packet(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_Subject2Packet(CLxLoc_Subject2Packet const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_Subject2Packet;
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

    auto Type(void) -> LXtID4
    {
        return m_loc[0]->Type(m_loc);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_TexturePacket : public CLxLocalize<ILxTexturePacketID>
{
public:
    CLxLoc_TexturePacket()
    {
        _init();
    }

    CLxLoc_TexturePacket(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_TexturePacket(CLxLoc_TexturePacket const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_TexturePacket;
    }

    auto Evaluate(LXtFVector pos, LXtPointID vrx, LXtPolygonID pol, int context, double *res) -> LxResult
    {
        return m_loc[0]->Evaluate(m_loc, pos, vrx, pol, context, res);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_ElementAxisPacket : public CLxLocalize<ILxElementAxisPacketID>
{
public:
    CLxLoc_ElementAxisPacket()
    {
        _init();
    }

    CLxLoc_ElementAxisPacket(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_ElementAxisPacket(CLxLoc_ElementAxisPacket const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_ElementAxisPacket;
    }

    auto Axis(LXtPointID vrx, LXtFVector axis, LXtMatrix m, LXtMatrix mInv) -> LxResult
    {
        return m_loc[0]->Axis(m_loc, vrx, axis, m, mInv);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_ElementCenterPacket : public CLxLocalize<ILxElementCenterPacketID>
{
public:
    CLxLoc_ElementCenterPacket()
    {
        _init();
    }

    CLxLoc_ElementCenterPacket(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_ElementCenterPacket(CLxLoc_ElementCenterPacket const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_ElementCenterPacket;
    }

    auto Center(LXtPointID vrx, LXtFVector center) -> LxResult
    {
        return m_loc[0]->Center(m_loc, vrx, center);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_PathGeneratorPacket
{
public:
    virtual ~CLxImpl_PathGeneratorPacket() = default;

    virtual auto pathgen_Value([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] double t, [[maybe_unused]] LXtVector pos) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto pathgen_Length([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] double t0, [[maybe_unused]] double t1) -> double
    {
        return 0;
    }

    virtual auto pathgen_Tangent([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] double t, [[maybe_unused]] double *tan) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto pathgen_Source([[maybe_unused]] ILxUnknownID vts) -> LXtPolygonID
    {
        return 0;
    }

    virtual auto pathgen_Count([[maybe_unused]] ILxUnknownID vts) -> int
    {
        return 0;
    }

    virtual auto pathgen_Knot([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] int index, [[maybe_unused]] LXtPathKnot *knot) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto pathgen_Current([[maybe_unused]] ILxUnknownID vts) -> int
    {
        return 0;
    }

    virtual auto pathgen_KnotDataSet([[maybe_unused]] ILxUnknownID gen) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto pathgen_Walk([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID pathStep, [[maybe_unused]] double angle, [[maybe_unused]] double ti, [[maybe_unused]] double tf) -> int
    {
        return 0;
    }

    virtual auto pathgen_Bank([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] double t) -> double
    {
        return 0;
    }

    virtual auto pathgen_CurveCount([[maybe_unused]] void) -> int
    {
        return 1;
    }

    virtual auto pathgen_SetCurveIndex([[maybe_unused]] int idx) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto pathgen_CurrentCurveIndex([[maybe_unused]] void) -> int
    {
        return 0;
    }
};

#define LXxD_PathGeneratorPacket_Value LxResult pathgen_Value([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] double t, [[maybe_unused]] LXtVector pos) override
#define LXxO_PathGeneratorPacket_Value LXxD_PathGeneratorPacket_Value
#define LXxC_PathGeneratorPacket_Value(c) LxResult c::pathgen_Value([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] double t, [[maybe_unused]] LXtVector pos)
#define LXxD_PathGeneratorPacket_Length double pathgen_Length([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] double t0, [[maybe_unused]] double t1) override
#define LXxO_PathGeneratorPacket_Length LXxD_PathGeneratorPacket_Length
#define LXxC_PathGeneratorPacket_Length(c) double c::pathgen_Length([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] double t0, [[maybe_unused]] double t1)
#define LXxD_PathGeneratorPacket_Tangent LxResult pathgen_Tangent([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] double t, [[maybe_unused]] double *tan) override
#define LXxO_PathGeneratorPacket_Tangent LXxD_PathGeneratorPacket_Tangent
#define LXxC_PathGeneratorPacket_Tangent(c) LxResult c::pathgen_Tangent([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] double t, [[maybe_unused]] double *tan)
#define LXxD_PathGeneratorPacket_Source LXtPolygonID pathgen_Source([[maybe_unused]] ILxUnknownID vts) override
#define LXxO_PathGeneratorPacket_Source LXxD_PathGeneratorPacket_Source
#define LXxC_PathGeneratorPacket_Source(c) LXtPolygonID c::pathgen_Source([[maybe_unused]] ILxUnknownID vts)
#define LXxD_PathGeneratorPacket_Count int pathgen_Count([[maybe_unused]] ILxUnknownID vts) override
#define LXxO_PathGeneratorPacket_Count LXxD_PathGeneratorPacket_Count
#define LXxC_PathGeneratorPacket_Count(c) int c::pathgen_Count([[maybe_unused]] ILxUnknownID vts)
#define LXxD_PathGeneratorPacket_Knot LxResult pathgen_Knot([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] int index, [[maybe_unused]] LXtPathKnot *knot) override
#define LXxO_PathGeneratorPacket_Knot LXxD_PathGeneratorPacket_Knot
#define LXxC_PathGeneratorPacket_Knot(c) LxResult c::pathgen_Knot([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] int index, [[maybe_unused]] LXtPathKnot *knot)
#define LXxD_PathGeneratorPacket_Current int pathgen_Current([[maybe_unused]] ILxUnknownID vts) override
#define LXxO_PathGeneratorPacket_Current LXxD_PathGeneratorPacket_Current
#define LXxC_PathGeneratorPacket_Current(c) int c::pathgen_Current([[maybe_unused]] ILxUnknownID vts)
#define LXxD_PathGeneratorPacket_KnotDataSet LxResult pathgen_KnotDataSet([[maybe_unused]] ILxUnknownID gen) override
#define LXxO_PathGeneratorPacket_KnotDataSet LXxD_PathGeneratorPacket_KnotDataSet
#define LXxC_PathGeneratorPacket_KnotDataSet(c) LxResult c::pathgen_KnotDataSet([[maybe_unused]] ILxUnknownID gen)
#define LXxD_PathGeneratorPacket_Walk int pathgen_Walk([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID pathStep, [[maybe_unused]] double angle, [[maybe_unused]] double ti, [[maybe_unused]] double tf) override
#define LXxO_PathGeneratorPacket_Walk LXxD_PathGeneratorPacket_Walk
#define LXxC_PathGeneratorPacket_Walk(c) int c::pathgen_Walk([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID pathStep, [[maybe_unused]] double angle, [[maybe_unused]] double ti, [[maybe_unused]] double tf)
#define LXxD_PathGeneratorPacket_Bank double pathgen_Bank([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] double t) override
#define LXxO_PathGeneratorPacket_Bank LXxD_PathGeneratorPacket_Bank
#define LXxC_PathGeneratorPacket_Bank(c) double c::pathgen_Bank([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] double t)
#define LXxD_PathGeneratorPacket_CurveCount int pathgen_CurveCount() override
#define LXxO_PathGeneratorPacket_CurveCount LXxD_PathGeneratorPacket_CurveCount
#define LXxC_PathGeneratorPacket_CurveCount(c) int c::pathgen_CurveCount()
#define LXxD_PathGeneratorPacket_SetCurveIndex LxResult pathgen_SetCurveIndex([[maybe_unused]] int idx) override
#define LXxO_PathGeneratorPacket_SetCurveIndex LXxD_PathGeneratorPacket_SetCurveIndex
#define LXxC_PathGeneratorPacket_SetCurveIndex(c) LxResult c::pathgen_SetCurveIndex([[maybe_unused]] int idx)
#define LXxD_PathGeneratorPacket_CurrentCurveIndex int pathgen_CurrentCurveIndex() override
#define LXxO_PathGeneratorPacket_CurrentCurveIndex LXxD_PathGeneratorPacket_CurrentCurveIndex
#define LXxC_PathGeneratorPacket_CurrentCurveIndex(c) int c::pathgen_CurrentCurveIndex()

template <class T>
class CLxIfc_PathGeneratorPacket: public CLxInterface
{
public:
    CLxIfc_PathGeneratorPacket()
    {
        vt.Value = Value;
        vt.Length = Length;
        vt.Tangent = Tangent;
        vt.Source = Source;
        vt.Count = Count;
        vt.Knot = Knot;
        vt.Current = Current;
        vt.KnotDataSet = KnotDataSet;
        vt.Walk = Walk;
        vt.Bank = Bank;
        vt.CurveCount = CurveCount;
        vt.SetCurveIndex = SetCurveIndex;
        vt.CurrentCurveIndex = CurrentCurveIndex;
        vTable = &vt.iunk;
        iid = &lx::guid_PathGeneratorPacket;
    }

    static auto Value(LXtObjectID wcom,LXtObjectID vts,double t,LXtVector pos) -> LxResult
    {
        LXCWxINST (CLxImpl_PathGeneratorPacket, loc);
        try
        {
           return loc->pathgen_Value((ILxUnknownID) vts, t, pos);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Length(LXtObjectID wcom,LXtObjectID vts,double t0,double t1) -> double
    {
        LXCWxINST (CLxImpl_PathGeneratorPacket, loc);
        return loc->pathgen_Length((ILxUnknownID) vts, t0, t1);
    }

    static auto Tangent(LXtObjectID wcom,LXtObjectID vts,double t,double *tan) -> LxResult
    {
        LXCWxINST (CLxImpl_PathGeneratorPacket, loc);
        try
        {
           return loc->pathgen_Tangent((ILxUnknownID) vts, t, tan);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Source(LXtObjectID wcom,LXtObjectID vts) -> LXtPolygonID
    {
        LXCWxINST (CLxImpl_PathGeneratorPacket, loc);
        return loc->pathgen_Source((ILxUnknownID) vts);
    }

    static auto Count(LXtObjectID wcom,LXtObjectID vts) -> int
    {
        LXCWxINST (CLxImpl_PathGeneratorPacket, loc);
        return loc->pathgen_Count((ILxUnknownID) vts);
    }

    static auto Knot(LXtObjectID wcom,LXtObjectID vts,int index,LXtPathKnot *knot) -> LxResult
    {
        LXCWxINST (CLxImpl_PathGeneratorPacket, loc);
        try
        {
           return loc->pathgen_Knot((ILxUnknownID) vts, index, knot);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Current(LXtObjectID wcom,LXtObjectID vts) -> int
    {
        LXCWxINST (CLxImpl_PathGeneratorPacket, loc);
        return loc->pathgen_Current((ILxUnknownID) vts);
    }

    static auto KnotDataSet(LXtObjectID wcom,LXtObjectID gen) -> LxResult
    {
        LXCWxINST (CLxImpl_PathGeneratorPacket, loc);
        try
        {
           return loc->pathgen_KnotDataSet((ILxUnknownID) gen);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Walk(LXtObjectID wcom,LXtObjectID vts,LXtObjectID pathStep,double angle,double ti,double tf) -> int
    {
        LXCWxINST (CLxImpl_PathGeneratorPacket, loc);
        return loc->pathgen_Walk((ILxUnknownID) vts,(ILxUnknownID) pathStep, angle, ti, tf);
    }

    static auto Bank(LXtObjectID wcom,LXtObjectID vts,double t) -> double
    {
        LXCWxINST (CLxImpl_PathGeneratorPacket, loc);
        return loc->pathgen_Bank((ILxUnknownID) vts, t);
    }

    static auto CurveCount(LXtObjectID wcom) -> int
    {
        LXCWxINST (CLxImpl_PathGeneratorPacket, loc);
        return loc->pathgen_CurveCount();
    }

    static auto SetCurveIndex(LXtObjectID wcom,int idx) -> LxResult
    {
        LXCWxINST (CLxImpl_PathGeneratorPacket, loc);
        try
        {
           return loc->pathgen_SetCurveIndex( idx);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto CurrentCurveIndex(LXtObjectID wcom) -> int
    {
        LXCWxINST (CLxImpl_PathGeneratorPacket, loc);
        return loc->pathgen_CurrentCurveIndex();
    }

private:
    ILxPathGeneratorPacket vt;
};

class CLxLoc_PathGeneratorPacket : public CLxLocalize<ILxPathGeneratorPacketID>
{
public:
    CLxLoc_PathGeneratorPacket()
    {
        _init();
    }

    CLxLoc_PathGeneratorPacket(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_PathGeneratorPacket(CLxLoc_PathGeneratorPacket const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_PathGeneratorPacket;
    }

    auto Value(ILxUnknownID vts, double t, LXtVector pos) -> LxResult
    {
        return m_loc[0]->Value(m_loc,(ILxUnknownID) vts, t, pos);
    }

    auto Length(ILxUnknownID vts, double t0, double t1) -> double
    {
        return m_loc[0]->Length(m_loc,(ILxUnknownID) vts, t0, t1);
    }

    auto Tangent(ILxUnknownID vts, double t, double *tan) -> LxResult
    {
        return m_loc[0]->Tangent(m_loc,(ILxUnknownID) vts, t, tan);
    }

    auto Source(ILxUnknownID vts) -> LXtPolygonID
    {
        return m_loc[0]->Source(m_loc,(ILxUnknownID) vts);
    }

    auto Count(ILxUnknownID vts) -> int
    {
        return m_loc[0]->Count(m_loc,(ILxUnknownID) vts);
    }

    auto Knot(ILxUnknownID vts, int index, LXtPathKnot *knot) -> LxResult
    {
        return m_loc[0]->Knot(m_loc,(ILxUnknownID) vts, index, knot);
    }

    auto Current(ILxUnknownID vts) -> int
    {
        return m_loc[0]->Current(m_loc,(ILxUnknownID) vts);
    }

    auto KnotDataSet(ILxUnknownID gen) -> LxResult
    {
        return m_loc[0]->KnotDataSet(m_loc,(ILxUnknownID) gen);
    }

    auto Walk(ILxUnknownID vts, ILxUnknownID pathStep, double angle, double ti, double tf) -> int
    {
        return m_loc[0]->Walk(m_loc,(ILxUnknownID) vts,(ILxUnknownID) pathStep, angle, ti, tf);
    }

    auto Bank(ILxUnknownID vts, double t) -> double
    {
        return m_loc[0]->Bank(m_loc,(ILxUnknownID) vts, t);
    }

    auto CurveCount(void) -> int
    {
        return m_loc[0]->CurveCount(m_loc);
    }

    auto SetCurveIndex(int idx) -> LxResult
    {
        return m_loc[0]->SetCurveIndex(m_loc, idx);
    }

    auto CurrentCurveIndex(void) -> int
    {
        return m_loc[0]->CurrentCurveIndex(m_loc);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_BagGenerator : public CLxLocalize<ILxBagGeneratorID>
{
public:
    CLxLoc_BagGenerator()
    {
        _init();
    }

    CLxLoc_BagGenerator(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_BagGenerator(CLxLoc_BagGenerator const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_BagGenerator;
    }

    auto Generate(void *data, void *cloneMe) -> void*
    {
        return m_loc[0]->Generate(m_loc, data, cloneMe);
    }

    auto Dispose(void *data) -> void
    {
        m_loc[0]->Dispose(m_loc, data);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_PathStep : public CLxLocalize<ILxPathStepID>
{
public:
    CLxLoc_PathStep()
    {
        _init();
    }

    CLxLoc_PathStep(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_PathStep(CLxLoc_PathStep const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_PathStep;
    }

    auto Setup(void) -> void
    {
        m_loc[0]->Setup(m_loc);
    }

    auto Step(double t, LXtVector pos) -> int
    {
        return m_loc[0]->Step(m_loc, t, pos);
    }

    auto CleanUp(void) -> void
    {
        m_loc[0]->CleanUp(m_loc);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};

class CLxImpl_ParticleGeneratorPacket
{
public:
    virtual ~CLxImpl_ParticleGeneratorPacket() = default;

    virtual auto partgen_Count([[maybe_unused]] ILxUnknownID vts) -> int
    {
        return 0;
    }

    virtual auto partgen_Particle([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] int index, [[maybe_unused]] LXtPGenParticle *part) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto partgen_InitialParticleSet([[maybe_unused]] const LXtPGenParticle *part) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto partgen_HintBoxSet([[maybe_unused]] const LXtBBox *box, [[maybe_unused]] const LXtVector orient, [[maybe_unused]] const LXtPGenParticle *part) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto partgen_SourceCount([[maybe_unused]] void) -> int
    {
        return 1;
    }

    virtual auto partgen_SetSourceIndex([[maybe_unused]] int idx) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto partgen_CurrentSourceIndex([[maybe_unused]] void) -> int
    {
        return 0;
    }
};

#define LXxD_ParticleGeneratorPacket_Count int partgen_Count([[maybe_unused]] ILxUnknownID vts) override
#define LXxO_ParticleGeneratorPacket_Count LXxD_ParticleGeneratorPacket_Count
#define LXxC_ParticleGeneratorPacket_Count(c) int c::partgen_Count([[maybe_unused]] ILxUnknownID vts)
#define LXxD_ParticleGeneratorPacket_Particle LxResult partgen_Particle([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] int index, [[maybe_unused]] LXtPGenParticle *part) override
#define LXxO_ParticleGeneratorPacket_Particle LXxD_ParticleGeneratorPacket_Particle
#define LXxC_ParticleGeneratorPacket_Particle(c) LxResult c::partgen_Particle([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] int index, [[maybe_unused]] LXtPGenParticle *part)
#define LXxD_ParticleGeneratorPacket_InitialParticleSet LxResult partgen_InitialParticleSet([[maybe_unused]] const LXtPGenParticle *part) override
#define LXxO_ParticleGeneratorPacket_InitialParticleSet LXxD_ParticleGeneratorPacket_InitialParticleSet
#define LXxC_ParticleGeneratorPacket_InitialParticleSet(c) LxResult c::partgen_InitialParticleSet([[maybe_unused]] const LXtPGenParticle *part)
#define LXxD_ParticleGeneratorPacket_HintBoxSet LxResult partgen_HintBoxSet([[maybe_unused]] const LXtBBox *box, [[maybe_unused]] const LXtVector orient, [[maybe_unused]] const LXtPGenParticle *part) override
#define LXxO_ParticleGeneratorPacket_HintBoxSet LXxD_ParticleGeneratorPacket_HintBoxSet
#define LXxC_ParticleGeneratorPacket_HintBoxSet(c) LxResult c::partgen_HintBoxSet([[maybe_unused]] const LXtBBox *box, [[maybe_unused]] const LXtVector orient, [[maybe_unused]] const LXtPGenParticle *part)
#define LXxD_ParticleGeneratorPacket_SourceCount int partgen_SourceCount() override
#define LXxO_ParticleGeneratorPacket_SourceCount LXxD_ParticleGeneratorPacket_SourceCount
#define LXxC_ParticleGeneratorPacket_SourceCount(c) int c::partgen_SourceCount()
#define LXxD_ParticleGeneratorPacket_SetSourceIndex LxResult partgen_SetSourceIndex([[maybe_unused]] int idx) override
#define LXxO_ParticleGeneratorPacket_SetSourceIndex LXxD_ParticleGeneratorPacket_SetSourceIndex
#define LXxC_ParticleGeneratorPacket_SetSourceIndex(c) LxResult c::partgen_SetSourceIndex([[maybe_unused]] int idx)
#define LXxD_ParticleGeneratorPacket_CurrentSourceIndex int partgen_CurrentSourceIndex() override
#define LXxO_ParticleGeneratorPacket_CurrentSourceIndex LXxD_ParticleGeneratorPacket_CurrentSourceIndex
#define LXxC_ParticleGeneratorPacket_CurrentSourceIndex(c) int c::partgen_CurrentSourceIndex()

template <class T>
class CLxIfc_ParticleGeneratorPacket: public CLxInterface
{
public:
    CLxIfc_ParticleGeneratorPacket()
    {
        vt.Count = Count;
        vt.Particle = Particle;
        vt.InitialParticleSet = InitialParticleSet;
        vt.HintBoxSet = HintBoxSet;
        vt.SourceCount = SourceCount;
        vt.SetSourceIndex = SetSourceIndex;
        vt.CurrentSourceIndex = CurrentSourceIndex;
        vTable = &vt.iunk;
        iid = &lx::guid_ParticleGeneratorPacket;
    }

    static auto Count(LXtObjectID wcom,LXtObjectID vts) -> int
    {
        LXCWxINST (CLxImpl_ParticleGeneratorPacket, loc);
        return loc->partgen_Count((ILxUnknownID) vts);
    }

    static auto Particle(LXtObjectID wcom,LXtObjectID vts,int index,LXtPGenParticle *part) -> LxResult
    {
        LXCWxINST (CLxImpl_ParticleGeneratorPacket, loc);
        try
        {
           return loc->partgen_Particle((ILxUnknownID) vts, index, part);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto InitialParticleSet(LXtObjectID wcom,const LXtPGenParticle *part) -> LxResult
    {
        LXCWxINST (CLxImpl_ParticleGeneratorPacket, loc);
        try
        {
           return loc->partgen_InitialParticleSet( part);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto HintBoxSet(LXtObjectID wcom,const LXtBBox *box,const LXtVector orient,const LXtPGenParticle *part) -> LxResult
    {
        LXCWxINST (CLxImpl_ParticleGeneratorPacket, loc);
        try
        {
           return loc->partgen_HintBoxSet( box, orient, part);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SourceCount(LXtObjectID wcom) -> int
    {
        LXCWxINST (CLxImpl_ParticleGeneratorPacket, loc);
        return loc->partgen_SourceCount();
    }

    static auto SetSourceIndex(LXtObjectID wcom,int idx) -> LxResult
    {
        LXCWxINST (CLxImpl_ParticleGeneratorPacket, loc);
        try
        {
           return loc->partgen_SetSourceIndex( idx);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto CurrentSourceIndex(LXtObjectID wcom) -> int
    {
        LXCWxINST (CLxImpl_ParticleGeneratorPacket, loc);
        return loc->partgen_CurrentSourceIndex();
    }

private:
    ILxParticleGeneratorPacket vt;
};

class CLxLoc_ParticleGeneratorPacket : public CLxLocalize<ILxParticleGeneratorPacketID>
{
public:
    CLxLoc_ParticleGeneratorPacket()
    {
        _init();
    }

    CLxLoc_ParticleGeneratorPacket(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_ParticleGeneratorPacket(CLxLoc_ParticleGeneratorPacket const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_ParticleGeneratorPacket;
    }

    auto Count(ILxUnknownID vts) -> int
    {
        return m_loc[0]->Count(m_loc,(ILxUnknownID) vts);
    }

    auto Particle(ILxUnknownID vts, int index, LXtPGenParticle *part) -> LxResult
    {
        return m_loc[0]->Particle(m_loc,(ILxUnknownID) vts, index, part);
    }

    auto InitialParticleSet(const LXtPGenParticle *part) -> LxResult
    {
        return m_loc[0]->InitialParticleSet(m_loc, part);
    }

    auto HintBoxSet(const LXtBBox *box, const LXtVector orient, const LXtPGenParticle *part) -> LxResult
    {
        return m_loc[0]->HintBoxSet(m_loc, box, orient, part);
    }

    auto SourceCount(void) -> int
    {
        return m_loc[0]->SourceCount(m_loc);
    }

    auto SetSourceIndex(int idx) -> LxResult
    {
        return m_loc[0]->SetSourceIndex(m_loc, idx);
    }

    auto CurrentSourceIndex(void) -> int
    {
        return m_loc[0]->CurrentSourceIndex(m_loc);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};


