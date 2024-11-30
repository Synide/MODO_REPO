//
// C++ wrapper for lxsdk/lxvmodel.h.
//
//	Copyright 2024.
//
//
#pragma once

#include <lxvmodel.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx
{
    static LXtGUID const guid_ViewItem3D = {0x5E0E5E09, {0x9D9F, 0x447C}, {0xAE, 0xDA, 0x2F, 0x6F, 0x26, 0x6D, 0xB4, 0x64}};
    static LXtGUID const guid_ViewItem3D1 = {0x9BCE73B5, {0x3264, 0x48BB}, {0xB1, 0x29, 0x15, 0xFF, 0x53, 0xFD, 0x16, 0x61}};
    static LXtGUID const guid_VirtualModel = {0x28F7A244, {0xE5B0, 0x406C}, {0xAA, 0x54, 0x55, 0xD3, 0x3D, 0x52, 0xEB, 0x4A}};
    static LXtGUID const guid_ToolModel = {0x7C98503C, {0xB697, 0x43D2}, {0xBC, 0x04, 0x50, 0xCE, 0x8E, 0x48, 0x39, 0xB2}};
    static LXtGUID const guid_ToolModel4 = {0x6E3DCFCE, {0xF8BF, 0x43EB}, {0x9D, 0x2E, 0x61, 0x70, 0x70, 0x57, 0x47, 0x36}};
    static LXtGUID const guid_ToolModel3 = {0x27DB58F5, {0x5C0C, 0x4CF7}, {0xB0, 0x64, 0x6B, 0x07, 0x18, 0x8E, 0x98, 0x13}};
    static LXtGUID const guid_ToolModel2 = {0xB70B1F15, {0x137A, 0x4716}, {0xA8, 0x93, 0x1A, 0xC4, 0x16, 0xC5, 0x47, 0xE9}};
    static LXtGUID const guid_ToolModel1 = {0xEECE6570, {0xAD5F, 0x4190}, {0xAF, 0xA7, 0x15, 0x06, 0x75, 0x00, 0x45, 0x4F}};
    static LXtGUID const guid_AdjustTool = {0x26E85301, {0x8165, 0x4FF3}, {0xAF, 0x26, 0x39, 0x2A, 0x03, 0xC9, 0xE1, 0xE7}};
    static LXtGUID const guid_NavigationListener = {0x61724B7C, {0x59DE, 0x40F7}, {0xB2, 0x60, 0x8C, 0x71, 0xD8, 0xFE, 0x97, 0x10}};
} // namespace lx

class CLxImpl_ViewItem3D
{
public:
    virtual ~CLxImpl_ViewItem3D() = default;

    virtual auto vitm_Draw([[maybe_unused]] ILxUnknownID chanRead, [[maybe_unused]] ILxUnknownID strokeDraw, [[maybe_unused]] int selectionFlags, [[maybe_unused]] const LXtVector itemColor) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto vitm_DrawBackground([[maybe_unused]] ILxUnknownID chanRead, [[maybe_unused]] ILxUnknownID strokeDraw, [[maybe_unused]] const LXtVector itemColor) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto vitm_WorldSpace([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto vitm_HandleCount([[maybe_unused]] int *count) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto vitm_HandleMotion([[maybe_unused]] int handleIndex, [[maybe_unused]] int *handleFlags, [[maybe_unused]] double *min, [[maybe_unused]] double *max, [[maybe_unused]] LXtVector plane, [[maybe_unused]] LXtVector offset) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto vitm_HandleChannel([[maybe_unused]] int handleIndex, [[maybe_unused]] int *chanIndex) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto vitm_HandleValueToPosition([[maybe_unused]] int handleIndex, [[maybe_unused]] const double *chanValue, [[maybe_unused]] LXtVector position) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto vitm_HandlePositionToValue([[maybe_unused]] int handleIndex, [[maybe_unused]] const LXtVector position, [[maybe_unused]] double *chanValue) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto vitm_Test([[maybe_unused]] ILxUnknownID chanRead, [[maybe_unused]] ILxUnknownID strokeDraw, [[maybe_unused]] int selectionFlags, [[maybe_unused]] const LXtVector itemColor) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_ViewItem3D_Draw LxResult vitm_Draw([[maybe_unused]] ILxUnknownID chanRead, [[maybe_unused]] ILxUnknownID strokeDraw, [[maybe_unused]] int selectionFlags, [[maybe_unused]] const LXtVector itemColor) override
#define LXxO_ViewItem3D_Draw LXxD_ViewItem3D_Draw
#define LXxC_ViewItem3D_Draw(c) LxResult c::vitm_Draw([[maybe_unused]] ILxUnknownID chanRead, [[maybe_unused]] ILxUnknownID strokeDraw, [[maybe_unused]] int selectionFlags, [[maybe_unused]] const LXtVector itemColor)
#define LXxD_ViewItem3D_DrawBackground LxResult vitm_DrawBackground([[maybe_unused]] ILxUnknownID chanRead, [[maybe_unused]] ILxUnknownID strokeDraw, [[maybe_unused]] const LXtVector itemColor) override
#define LXxO_ViewItem3D_DrawBackground LXxD_ViewItem3D_DrawBackground
#define LXxC_ViewItem3D_DrawBackground(c) LxResult c::vitm_DrawBackground([[maybe_unused]] ILxUnknownID chanRead, [[maybe_unused]] ILxUnknownID strokeDraw, [[maybe_unused]] const LXtVector itemColor)
#define LXxD_ViewItem3D_WorldSpace LxResult vitm_WorldSpace() override
#define LXxO_ViewItem3D_WorldSpace LXxD_ViewItem3D_WorldSpace
#define LXxC_ViewItem3D_WorldSpace(c) LxResult c::vitm_WorldSpace()
#define LXxD_ViewItem3D_HandleCount LxResult vitm_HandleCount([[maybe_unused]] int *count) override
#define LXxO_ViewItem3D_HandleCount LXxD_ViewItem3D_HandleCount
#define LXxC_ViewItem3D_HandleCount(c) LxResult c::vitm_HandleCount([[maybe_unused]] int *count)
#define LXxD_ViewItem3D_HandleMotion LxResult vitm_HandleMotion([[maybe_unused]] int handleIndex, [[maybe_unused]] int *handleFlags, [[maybe_unused]] double *min, [[maybe_unused]] double *max, [[maybe_unused]] LXtVector plane, [[maybe_unused]] LXtVector offset) override
#define LXxO_ViewItem3D_HandleMotion LXxD_ViewItem3D_HandleMotion
#define LXxC_ViewItem3D_HandleMotion(c) LxResult c::vitm_HandleMotion([[maybe_unused]] int handleIndex, [[maybe_unused]] int *handleFlags, [[maybe_unused]] double *min, [[maybe_unused]] double *max, [[maybe_unused]] LXtVector plane, [[maybe_unused]] LXtVector offset)
#define LXxD_ViewItem3D_HandleChannel LxResult vitm_HandleChannel([[maybe_unused]] int handleIndex, [[maybe_unused]] int *chanIndex) override
#define LXxO_ViewItem3D_HandleChannel LXxD_ViewItem3D_HandleChannel
#define LXxC_ViewItem3D_HandleChannel(c) LxResult c::vitm_HandleChannel([[maybe_unused]] int handleIndex, [[maybe_unused]] int *chanIndex)
#define LXxD_ViewItem3D_HandleValueToPosition LxResult vitm_HandleValueToPosition([[maybe_unused]] int handleIndex, [[maybe_unused]] const double *chanValue, [[maybe_unused]] LXtVector position) override
#define LXxO_ViewItem3D_HandleValueToPosition LXxD_ViewItem3D_HandleValueToPosition
#define LXxC_ViewItem3D_HandleValueToPosition(c) LxResult c::vitm_HandleValueToPosition([[maybe_unused]] int handleIndex, [[maybe_unused]] const double *chanValue, [[maybe_unused]] LXtVector position)
#define LXxD_ViewItem3D_HandlePositionToValue LxResult vitm_HandlePositionToValue([[maybe_unused]] int handleIndex, [[maybe_unused]] const LXtVector position, [[maybe_unused]] double *chanValue) override
#define LXxO_ViewItem3D_HandlePositionToValue LXxD_ViewItem3D_HandlePositionToValue
#define LXxC_ViewItem3D_HandlePositionToValue(c) LxResult c::vitm_HandlePositionToValue([[maybe_unused]] int handleIndex, [[maybe_unused]] const LXtVector position, [[maybe_unused]] double *chanValue)
#define LXxD_ViewItem3D_Test LxResult vitm_Test([[maybe_unused]] ILxUnknownID chanRead, [[maybe_unused]] ILxUnknownID strokeDraw, [[maybe_unused]] int selectionFlags, [[maybe_unused]] const LXtVector itemColor) override
#define LXxO_ViewItem3D_Test LXxD_ViewItem3D_Test
#define LXxC_ViewItem3D_Test(c) LxResult c::vitm_Test([[maybe_unused]] ILxUnknownID chanRead, [[maybe_unused]] ILxUnknownID strokeDraw, [[maybe_unused]] int selectionFlags, [[maybe_unused]] const LXtVector itemColor)

template <class T>
class CLxIfc_ViewItem3D: public CLxInterface
{
public:
    CLxIfc_ViewItem3D()
    {
        vt.Draw = Draw;
        vt.DrawBackground = DrawBackground;
        vt.WorldSpace = WorldSpace;
        vt.HandleCount = HandleCount;
        vt.HandleMotion = HandleMotion;
        vt.HandleChannel = HandleChannel;
        vt.HandleValueToPosition = HandleValueToPosition;
        vt.HandlePositionToValue = HandlePositionToValue;
        vt.Test = Test;
        vTable = &vt.iunk;
        iid = &lx::guid_ViewItem3D;
    }

    static auto Draw(LXtObjectID wcom,LXtObjectID chanRead,LXtObjectID strokeDraw,int selectionFlags,const LXtVector itemColor) -> LxResult
    {
        LXCWxINST (CLxImpl_ViewItem3D, loc);
        try
        {
           return loc->vitm_Draw((ILxUnknownID) chanRead,(ILxUnknownID) strokeDraw, selectionFlags, itemColor);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto DrawBackground(LXtObjectID wcom,LXtObjectID chanRead,LXtObjectID strokeDraw,const LXtVector itemColor) -> LxResult
    {
        LXCWxINST (CLxImpl_ViewItem3D, loc);
        try
        {
           return loc->vitm_DrawBackground((ILxUnknownID) chanRead,(ILxUnknownID) strokeDraw, itemColor);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto WorldSpace(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_ViewItem3D, loc);
        try
        {
           return loc->vitm_WorldSpace();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto HandleCount(LXtObjectID wcom,int *count) -> LxResult
    {
        LXCWxINST (CLxImpl_ViewItem3D, loc);
        try
        {
           return loc->vitm_HandleCount( count);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto HandleMotion(LXtObjectID wcom,int handleIndex,int *handleFlags,double *min,double *max,LXtVector plane,LXtVector offset) -> LxResult
    {
        LXCWxINST (CLxImpl_ViewItem3D, loc);
        try
        {
           return loc->vitm_HandleMotion( handleIndex, handleFlags, min, max, plane, offset);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto HandleChannel(LXtObjectID wcom,int handleIndex,int *chanIndex) -> LxResult
    {
        LXCWxINST (CLxImpl_ViewItem3D, loc);
        try
        {
           return loc->vitm_HandleChannel( handleIndex, chanIndex);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto HandleValueToPosition(LXtObjectID wcom,int handleIndex,const double *chanValue,LXtVector position) -> LxResult
    {
        LXCWxINST (CLxImpl_ViewItem3D, loc);
        try
        {
           return loc->vitm_HandleValueToPosition( handleIndex, chanValue, position);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto HandlePositionToValue(LXtObjectID wcom,int handleIndex,const LXtVector position,double *chanValue) -> LxResult
    {
        LXCWxINST (CLxImpl_ViewItem3D, loc);
        try
        {
           return loc->vitm_HandlePositionToValue( handleIndex, position, chanValue);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Test(LXtObjectID wcom,LXtObjectID chanRead,LXtObjectID strokeDraw,int selectionFlags,const LXtVector itemColor) -> LxResult
    {
        LXCWxINST (CLxImpl_ViewItem3D, loc);
        try
        {
           return loc->vitm_Test((ILxUnknownID) chanRead,(ILxUnknownID) strokeDraw, selectionFlags, itemColor);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxViewItem3D vt;
};

class CLxLoc_ViewItem3D : public CLxLocalize<ILxViewItem3DID>
{
public:
    CLxLoc_ViewItem3D()
    {
        _init();
    }

    CLxLoc_ViewItem3D(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_ViewItem3D(CLxLoc_ViewItem3D const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_ViewItem3D;
    }

    auto Draw(ILxUnknownID chanRead, ILxUnknownID strokeDraw, int selectionFlags, const LXtVector itemColor) -> LxResult
    {
        return m_loc[0]->Draw(m_loc,(ILxUnknownID) chanRead,(ILxUnknownID) strokeDraw, selectionFlags, itemColor);
    }

    auto DrawBackground(ILxUnknownID chanRead, ILxUnknownID strokeDraw, const LXtVector itemColor) -> LxResult
    {
        return m_loc[0]->DrawBackground(m_loc,(ILxUnknownID) chanRead,(ILxUnknownID) strokeDraw, itemColor);
    }

    auto WorldSpace(void) -> LxResult
    {
        return m_loc[0]->WorldSpace(m_loc);
    }

    auto HandleCount(int *count) -> LxResult
    {
        return m_loc[0]->HandleCount(m_loc, count);
    }

    auto HandleMotion(int handleIndex, int *handleFlags, double *min, double *max, LXtVector plane, LXtVector offset) -> LxResult
    {
        return m_loc[0]->HandleMotion(m_loc, handleIndex, handleFlags, min, max, plane, offset);
    }

    auto HandleChannel(int handleIndex, int *chanIndex) -> LxResult
    {
        return m_loc[0]->HandleChannel(m_loc, handleIndex, chanIndex);
    }

    auto HandleValueToPosition(int handleIndex, const double *chanValue, LXtVector position) -> LxResult
    {
        return m_loc[0]->HandleValueToPosition(m_loc, handleIndex, chanValue, position);
    }

    auto HandlePositionToValue(int handleIndex, const LXtVector position, double *chanValue) -> LxResult
    {
        return m_loc[0]->HandlePositionToValue(m_loc, handleIndex, position, chanValue);
    }

    auto Test(ILxUnknownID chanRead, ILxUnknownID strokeDraw, int selectionFlags, const LXtVector itemColor) -> LxResult
    {
        return m_loc[0]->Test(m_loc,(ILxUnknownID) chanRead,(ILxUnknownID) strokeDraw, selectionFlags, itemColor);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_ViewItem3D1
{
public:
    virtual ~CLxImpl_ViewItem3D1() = default;

    virtual auto vitm_Draw([[maybe_unused]] ILxUnknownID chanRead, [[maybe_unused]] ILxUnknownID strokeDraw, [[maybe_unused]] int selectionFlags, [[maybe_unused]] LXtVector itemColor) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto vitm_DrawBackground([[maybe_unused]] ILxUnknownID chanRead, [[maybe_unused]] ILxUnknownID strokeDraw, [[maybe_unused]] LXtVector itemColor) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto vitm_WorldSpace([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto vitm_HandleCount([[maybe_unused]] int *count) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto vitm_HandleMotion([[maybe_unused]] int handleIndex, [[maybe_unused]] int *handleFlags, [[maybe_unused]] double *min, [[maybe_unused]] double *max, [[maybe_unused]] LXtVector plane, [[maybe_unused]] LXtVector offset) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto vitm_HandleChannel([[maybe_unused]] int handleIndex, [[maybe_unused]] int *chanIndex) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto vitm_HandleValueToPosition([[maybe_unused]] int handleIndex, [[maybe_unused]] double *chanValue, [[maybe_unused]] LXtVector position) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto vitm_HandlePositionToValue([[maybe_unused]] int handleIndex, [[maybe_unused]] LXtVector position, [[maybe_unused]] double *chanValue) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_ViewItem3D1_Draw LxResult vitm_Draw([[maybe_unused]] ILxUnknownID chanRead, [[maybe_unused]] ILxUnknownID strokeDraw, [[maybe_unused]] int selectionFlags, [[maybe_unused]] LXtVector itemColor) override
#define LXxO_ViewItem3D1_Draw LXxD_ViewItem3D1_Draw
#define LXxC_ViewItem3D1_Draw(c) LxResult c::vitm_Draw([[maybe_unused]] ILxUnknownID chanRead, [[maybe_unused]] ILxUnknownID strokeDraw, [[maybe_unused]] int selectionFlags, [[maybe_unused]] LXtVector itemColor)
#define LXxD_ViewItem3D1_DrawBackground LxResult vitm_DrawBackground([[maybe_unused]] ILxUnknownID chanRead, [[maybe_unused]] ILxUnknownID strokeDraw, [[maybe_unused]] LXtVector itemColor) override
#define LXxO_ViewItem3D1_DrawBackground LXxD_ViewItem3D1_DrawBackground
#define LXxC_ViewItem3D1_DrawBackground(c) LxResult c::vitm_DrawBackground([[maybe_unused]] ILxUnknownID chanRead, [[maybe_unused]] ILxUnknownID strokeDraw, [[maybe_unused]] LXtVector itemColor)
#define LXxD_ViewItem3D1_WorldSpace LxResult vitm_WorldSpace() override
#define LXxO_ViewItem3D1_WorldSpace LXxD_ViewItem3D1_WorldSpace
#define LXxC_ViewItem3D1_WorldSpace(c) LxResult c::vitm_WorldSpace()
#define LXxD_ViewItem3D1_HandleCount LxResult vitm_HandleCount([[maybe_unused]] int *count) override
#define LXxO_ViewItem3D1_HandleCount LXxD_ViewItem3D1_HandleCount
#define LXxC_ViewItem3D1_HandleCount(c) LxResult c::vitm_HandleCount([[maybe_unused]] int *count)
#define LXxD_ViewItem3D1_HandleMotion LxResult vitm_HandleMotion([[maybe_unused]] int handleIndex, [[maybe_unused]] int *handleFlags, [[maybe_unused]] double *min, [[maybe_unused]] double *max, [[maybe_unused]] LXtVector plane, [[maybe_unused]] LXtVector offset) override
#define LXxO_ViewItem3D1_HandleMotion LXxD_ViewItem3D1_HandleMotion
#define LXxC_ViewItem3D1_HandleMotion(c) LxResult c::vitm_HandleMotion([[maybe_unused]] int handleIndex, [[maybe_unused]] int *handleFlags, [[maybe_unused]] double *min, [[maybe_unused]] double *max, [[maybe_unused]] LXtVector plane, [[maybe_unused]] LXtVector offset)
#define LXxD_ViewItem3D1_HandleChannel LxResult vitm_HandleChannel([[maybe_unused]] int handleIndex, [[maybe_unused]] int *chanIndex) override
#define LXxO_ViewItem3D1_HandleChannel LXxD_ViewItem3D1_HandleChannel
#define LXxC_ViewItem3D1_HandleChannel(c) LxResult c::vitm_HandleChannel([[maybe_unused]] int handleIndex, [[maybe_unused]] int *chanIndex)
#define LXxD_ViewItem3D1_HandleValueToPosition LxResult vitm_HandleValueToPosition([[maybe_unused]] int handleIndex, [[maybe_unused]] double *chanValue, [[maybe_unused]] LXtVector position) override
#define LXxO_ViewItem3D1_HandleValueToPosition LXxD_ViewItem3D1_HandleValueToPosition
#define LXxC_ViewItem3D1_HandleValueToPosition(c) LxResult c::vitm_HandleValueToPosition([[maybe_unused]] int handleIndex, [[maybe_unused]] double *chanValue, [[maybe_unused]] LXtVector position)
#define LXxD_ViewItem3D1_HandlePositionToValue LxResult vitm_HandlePositionToValue([[maybe_unused]] int handleIndex, [[maybe_unused]] LXtVector position, [[maybe_unused]] double *chanValue) override
#define LXxO_ViewItem3D1_HandlePositionToValue LXxD_ViewItem3D1_HandlePositionToValue
#define LXxC_ViewItem3D1_HandlePositionToValue(c) LxResult c::vitm_HandlePositionToValue([[maybe_unused]] int handleIndex, [[maybe_unused]] LXtVector position, [[maybe_unused]] double *chanValue)

template <class T>
class CLxIfc_ViewItem3D1: public CLxInterface
{
public:
    CLxIfc_ViewItem3D1()
    {
        vt.Draw = Draw;
        vt.DrawBackground = DrawBackground;
        vt.WorldSpace = WorldSpace;
        vt.HandleCount = HandleCount;
        vt.HandleMotion = HandleMotion;
        vt.HandleChannel = HandleChannel;
        vt.HandleValueToPosition = HandleValueToPosition;
        vt.HandlePositionToValue = HandlePositionToValue;
        vTable = &vt.iunk;
        iid = &lx::guid_ViewItem3D1;
    }

    static auto Draw(LXtObjectID wcom,LXtObjectID chanRead,LXtObjectID strokeDraw,int selectionFlags,LXtVector itemColor) -> LxResult
    {
        LXCWxINST (CLxImpl_ViewItem3D1, loc);
        try
        {
           return loc->vitm_Draw((ILxUnknownID) chanRead,(ILxUnknownID) strokeDraw, selectionFlags, itemColor);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto DrawBackground(LXtObjectID wcom,LXtObjectID chanRead,LXtObjectID strokeDraw,LXtVector itemColor) -> LxResult
    {
        LXCWxINST (CLxImpl_ViewItem3D1, loc);
        try
        {
           return loc->vitm_DrawBackground((ILxUnknownID) chanRead,(ILxUnknownID) strokeDraw, itemColor);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto WorldSpace(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_ViewItem3D1, loc);
        try
        {
           return loc->vitm_WorldSpace();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto HandleCount(LXtObjectID wcom,int *count) -> LxResult
    {
        LXCWxINST (CLxImpl_ViewItem3D1, loc);
        try
        {
           return loc->vitm_HandleCount( count);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto HandleMotion(LXtObjectID wcom,int handleIndex,int *handleFlags,double *min,double *max,LXtVector plane,LXtVector offset) -> LxResult
    {
        LXCWxINST (CLxImpl_ViewItem3D1, loc);
        try
        {
           return loc->vitm_HandleMotion( handleIndex, handleFlags, min, max, plane, offset);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto HandleChannel(LXtObjectID wcom,int handleIndex,int *chanIndex) -> LxResult
    {
        LXCWxINST (CLxImpl_ViewItem3D1, loc);
        try
        {
           return loc->vitm_HandleChannel( handleIndex, chanIndex);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto HandleValueToPosition(LXtObjectID wcom,int handleIndex,double *chanValue,LXtVector position) -> LxResult
    {
        LXCWxINST (CLxImpl_ViewItem3D1, loc);
        try
        {
           return loc->vitm_HandleValueToPosition( handleIndex, chanValue, position);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto HandlePositionToValue(LXtObjectID wcom,int handleIndex,LXtVector position,double *chanValue) -> LxResult
    {
        LXCWxINST (CLxImpl_ViewItem3D1, loc);
        try
        {
           return loc->vitm_HandlePositionToValue( handleIndex, position, chanValue);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxViewItem3D1 vt;
};

class CLxLoc_ViewItem3D1 : public CLxLocalize<ILxViewItem3D1ID>
{
public:
    CLxLoc_ViewItem3D1()
    {
        _init();
    }

    CLxLoc_ViewItem3D1(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_ViewItem3D1(CLxLoc_ViewItem3D1 const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_ViewItem3D1;
    }

    auto Draw(ILxUnknownID chanRead, ILxUnknownID strokeDraw, int selectionFlags, LXtVector itemColor) -> LxResult
    {
        return m_loc[0]->Draw(m_loc,(ILxUnknownID) chanRead,(ILxUnknownID) strokeDraw, selectionFlags, itemColor);
    }

    auto DrawBackground(ILxUnknownID chanRead, ILxUnknownID strokeDraw, LXtVector itemColor) -> LxResult
    {
        return m_loc[0]->DrawBackground(m_loc,(ILxUnknownID) chanRead,(ILxUnknownID) strokeDraw, itemColor);
    }

    auto WorldSpace(void) -> LxResult
    {
        return m_loc[0]->WorldSpace(m_loc);
    }

    auto HandleCount(int *count) -> LxResult
    {
        return m_loc[0]->HandleCount(m_loc, count);
    }

    auto HandleMotion(int handleIndex, int *handleFlags, double *min, double *max, LXtVector plane, LXtVector offset) -> LxResult
    {
        return m_loc[0]->HandleMotion(m_loc, handleIndex, handleFlags, min, max, plane, offset);
    }

    auto HandleChannel(int handleIndex, int *chanIndex) -> LxResult
    {
        return m_loc[0]->HandleChannel(m_loc, handleIndex, chanIndex);
    }

    auto HandleValueToPosition(int handleIndex, double *chanValue, LXtVector position) -> LxResult
    {
        return m_loc[0]->HandleValueToPosition(m_loc, handleIndex, chanValue, position);
    }

    auto HandlePositionToValue(int handleIndex, LXtVector position, double *chanValue) -> LxResult
    {
        return m_loc[0]->HandlePositionToValue(m_loc, handleIndex, position, chanValue);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_VirtualModel
{
public:
    virtual ~CLxImpl_VirtualModel() = default;

    virtual auto vmodel_Flags([[maybe_unused]] void) -> unsigned
    {
        return LXfTMOD_DRAW_3D;
    }

    virtual void vmodel_Draw([[maybe_unused]] ILxUnknownID stroke)
    {
    }

    virtual void vmodel_Test([[maybe_unused]] ILxUnknownID stroke)
    {
    }

    virtual void vmodel_Track([[maybe_unused]] int part)
    {
    }

    virtual void vmodel_Down([[maybe_unused]] ILxUnknownID vts)
    {
    }

    virtual void vmodel_Move([[maybe_unused]] ILxUnknownID vts)
    {
    }

    virtual void vmodel_Up([[maybe_unused]] ILxUnknownID vts)
    {
    }

    virtual auto vmodel_Tooltip([[maybe_unused]] int part) -> const char *
    {
        return nullptr;
    }
};

#define LXxD_VirtualModel_Flags unsigned vmodel_Flags() override
#define LXxO_VirtualModel_Flags LXxD_VirtualModel_Flags
#define LXxC_VirtualModel_Flags(c) unsigned c::vmodel_Flags()
#define LXxD_VirtualModel_Draw void vmodel_Draw([[maybe_unused]] ILxUnknownID stroke) override
#define LXxO_VirtualModel_Draw LXxD_VirtualModel_Draw
#define LXxC_VirtualModel_Draw(c) void c::vmodel_Draw([[maybe_unused]] ILxUnknownID stroke)
#define LXxD_VirtualModel_Test void vmodel_Test([[maybe_unused]] ILxUnknownID stroke) override
#define LXxO_VirtualModel_Test LXxD_VirtualModel_Test
#define LXxC_VirtualModel_Test(c) void c::vmodel_Test([[maybe_unused]] ILxUnknownID stroke)
#define LXxD_VirtualModel_Track void vmodel_Track([[maybe_unused]] int part) override
#define LXxO_VirtualModel_Track LXxD_VirtualModel_Track
#define LXxC_VirtualModel_Track(c) void c::vmodel_Track([[maybe_unused]] int part)
#define LXxD_VirtualModel_Down void vmodel_Down([[maybe_unused]] ILxUnknownID vts) override
#define LXxO_VirtualModel_Down LXxD_VirtualModel_Down
#define LXxC_VirtualModel_Down(c) void c::vmodel_Down([[maybe_unused]] ILxUnknownID vts)
#define LXxD_VirtualModel_Move void vmodel_Move([[maybe_unused]] ILxUnknownID vts) override
#define LXxO_VirtualModel_Move LXxD_VirtualModel_Move
#define LXxC_VirtualModel_Move(c) void c::vmodel_Move([[maybe_unused]] ILxUnknownID vts)
#define LXxD_VirtualModel_Up void vmodel_Up([[maybe_unused]] ILxUnknownID vts) override
#define LXxO_VirtualModel_Up LXxD_VirtualModel_Up
#define LXxC_VirtualModel_Up(c) void c::vmodel_Up([[maybe_unused]] ILxUnknownID vts)
#define LXxD_VirtualModel_Tooltip const char * vmodel_Tooltip([[maybe_unused]] int part) override
#define LXxO_VirtualModel_Tooltip LXxD_VirtualModel_Tooltip
#define LXxC_VirtualModel_Tooltip(c) const char * c::vmodel_Tooltip([[maybe_unused]] int part)

template <class T>
class CLxIfc_VirtualModel: public CLxInterface
{
public:
    CLxIfc_VirtualModel()
    {
        vt.Flags = Flags;
        vt.Draw = Draw;
        vt.Test = Test;
        vt.Track = Track;
        vt.Down = Down;
        vt.Move = Move;
        vt.Up = Up;
        vt.Tooltip = Tooltip;
        vTable = &vt.iunk;
        iid = &lx::guid_VirtualModel;
    }

    static auto Flags(LXtObjectID wcom) -> unsigned
    {
        LXCWxINST (CLxImpl_VirtualModel, loc);
        return loc->vmodel_Flags();
    }

    static auto Draw(LXtObjectID wcom,LXtObjectID stroke) -> void
    {
        LXCWxINST (CLxImpl_VirtualModel, loc);
        loc->vmodel_Draw((ILxUnknownID) stroke);
    }

    static auto Test(LXtObjectID wcom,LXtObjectID stroke) -> void
    {
        LXCWxINST (CLxImpl_VirtualModel, loc);
        loc->vmodel_Test((ILxUnknownID) stroke);
    }

    static auto Track(LXtObjectID wcom,int part) -> void
    {
        LXCWxINST (CLxImpl_VirtualModel, loc);
        loc->vmodel_Track( part);
    }

    static auto Down(LXtObjectID wcom,LXtObjectID vts) -> void
    {
        LXCWxINST (CLxImpl_VirtualModel, loc);
        loc->vmodel_Down((ILxUnknownID) vts);
    }

    static auto Move(LXtObjectID wcom,LXtObjectID vts) -> void
    {
        LXCWxINST (CLxImpl_VirtualModel, loc);
        loc->vmodel_Move((ILxUnknownID) vts);
    }

    static auto Up(LXtObjectID wcom,LXtObjectID vts) -> void
    {
        LXCWxINST (CLxImpl_VirtualModel, loc);
        loc->vmodel_Up((ILxUnknownID) vts);
    }

    static auto Tooltip(LXtObjectID wcom,int part) -> const char *
    {
        LXCWxINST (CLxImpl_VirtualModel, loc);
        return loc->vmodel_Tooltip( part);
    }

private:
    ILxVirtualModel vt;
};

class CLxLoc_VirtualModel : public CLxLocalize<ILxVirtualModelID>
{
public:
    CLxLoc_VirtualModel()
    {
        _init();
    }

    CLxLoc_VirtualModel(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_VirtualModel(CLxLoc_VirtualModel const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_VirtualModel;
    }

    auto Flags(void) -> unsigned
    {
        return m_loc[0]->Flags(m_loc);
    }

    auto Draw(ILxUnknownID stroke) -> void
    {
        m_loc[0]->Draw(m_loc,(ILxUnknownID) stroke);
    }

    auto Test(ILxUnknownID stroke) -> void
    {
        m_loc[0]->Test(m_loc,(ILxUnknownID) stroke);
    }

    auto Track(int part) -> void
    {
        m_loc[0]->Track(m_loc, part);
    }

    auto Down(ILxUnknownID vts) -> void
    {
        m_loc[0]->Down(m_loc,(ILxUnknownID) vts);
    }

    auto Move(ILxUnknownID vts) -> void
    {
        m_loc[0]->Move(m_loc,(ILxUnknownID) vts);
    }

    auto Up(ILxUnknownID vts) -> void
    {
        m_loc[0]->Up(m_loc,(ILxUnknownID) vts);
    }

    auto Tooltip(int part) -> const char *
    {
        return m_loc[0]->Tooltip(m_loc, part);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_ToolModel
{
public:
    virtual ~CLxImpl_ToolModel() = default;

    virtual auto tmod_Flags([[maybe_unused]] void) -> unsigned
    {
        return LXfTMOD_DRAW_3D;
    }

    virtual void tmod_Draw([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID stroke, [[maybe_unused]] int flags)
    {
    }

    virtual void tmod_Test([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID stroke, [[maybe_unused]] int flags)
    {
    }

    virtual void tmod_Filter([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID adjust)
    {
    }

    virtual void tmod_Initialize([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID adjust, [[maybe_unused]] unsigned int flags)
    {
    }

    virtual auto tmod_Down([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID adjust) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual void tmod_Move([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID adjust)
    {
    }

    virtual void tmod_Up([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID adjust)
    {
    }

    virtual auto tmod_Haul([[maybe_unused]] unsigned int index) -> const char *
    {
        return 0;
    }

    virtual auto tmod_AllowOverride([[maybe_unused]] const char *attrName, [[maybe_unused]] unsigned int mouseInput, [[maybe_unused]] unsigned int haulAxis) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto tmod_Help([[maybe_unused]] ILxUnknownID vts) -> const char *
    {
        return 0;
    }

    virtual auto tmod_Enable([[maybe_unused]] ILxUnknownID msg) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto tmod_Drop([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto tmod_Track([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] unsigned int eventType) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto tmod_TrackFlags([[maybe_unused]] unsigned int *flags) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto tmod_Post([[maybe_unused]] ILxUnknownID vts) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto tmod_TestType([[maybe_unused]] LXtID4 type) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto tmod_Tooltip([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] int part) -> const char *
    {
        return 0;
    }
};

#define LXxD_ToolModel_Flags unsigned tmod_Flags() override
#define LXxO_ToolModel_Flags LXxD_ToolModel_Flags
#define LXxC_ToolModel_Flags(c) unsigned c::tmod_Flags()
#define LXxD_ToolModel_Draw void tmod_Draw([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID stroke, [[maybe_unused]] int flags) override
#define LXxO_ToolModel_Draw LXxD_ToolModel_Draw
#define LXxC_ToolModel_Draw(c) void c::tmod_Draw([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID stroke, [[maybe_unused]] int flags)
#define LXxD_ToolModel_Test void tmod_Test([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID stroke, [[maybe_unused]] int flags) override
#define LXxO_ToolModel_Test LXxD_ToolModel_Test
#define LXxC_ToolModel_Test(c) void c::tmod_Test([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID stroke, [[maybe_unused]] int flags)
#define LXxD_ToolModel_Filter void tmod_Filter([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID adjust) override
#define LXxO_ToolModel_Filter LXxD_ToolModel_Filter
#define LXxC_ToolModel_Filter(c) void c::tmod_Filter([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID adjust)
#define LXxD_ToolModel_Initialize void tmod_Initialize([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID adjust, [[maybe_unused]] unsigned int flags) override
#define LXxO_ToolModel_Initialize LXxD_ToolModel_Initialize
#define LXxC_ToolModel_Initialize(c) void c::tmod_Initialize([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID adjust, [[maybe_unused]] unsigned int flags)
#define LXxD_ToolModel_Down LxResult tmod_Down([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID adjust) override
#define LXxO_ToolModel_Down LXxD_ToolModel_Down
#define LXxC_ToolModel_Down(c) LxResult c::tmod_Down([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID adjust)
#define LXxD_ToolModel_Move void tmod_Move([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID adjust) override
#define LXxO_ToolModel_Move LXxD_ToolModel_Move
#define LXxC_ToolModel_Move(c) void c::tmod_Move([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID adjust)
#define LXxD_ToolModel_Up void tmod_Up([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID adjust) override
#define LXxO_ToolModel_Up LXxD_ToolModel_Up
#define LXxC_ToolModel_Up(c) void c::tmod_Up([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID adjust)
#define LXxD_ToolModel_Haul const char * tmod_Haul([[maybe_unused]] unsigned int index) override
#define LXxO_ToolModel_Haul LXxD_ToolModel_Haul
#define LXxC_ToolModel_Haul(c) const char * c::tmod_Haul([[maybe_unused]] unsigned int index)
#define LXxD_ToolModel_AllowOverride LxResult tmod_AllowOverride([[maybe_unused]] const char *attrName, [[maybe_unused]] unsigned int mouseInput, [[maybe_unused]] unsigned int haulAxis) override
#define LXxO_ToolModel_AllowOverride LXxD_ToolModel_AllowOverride
#define LXxC_ToolModel_AllowOverride(c) LxResult c::tmod_AllowOverride([[maybe_unused]] const char *attrName, [[maybe_unused]] unsigned int mouseInput, [[maybe_unused]] unsigned int haulAxis)
#define LXxD_ToolModel_Help const char * tmod_Help([[maybe_unused]] ILxUnknownID vts) override
#define LXxO_ToolModel_Help LXxD_ToolModel_Help
#define LXxC_ToolModel_Help(c) const char * c::tmod_Help([[maybe_unused]] ILxUnknownID vts)
#define LXxD_ToolModel_Enable LxResult tmod_Enable([[maybe_unused]] ILxUnknownID msg) override
#define LXxO_ToolModel_Enable LXxD_ToolModel_Enable
#define LXxC_ToolModel_Enable(c) LxResult c::tmod_Enable([[maybe_unused]] ILxUnknownID msg)
#define LXxD_ToolModel_Drop LxResult tmod_Drop() override
#define LXxO_ToolModel_Drop LXxD_ToolModel_Drop
#define LXxC_ToolModel_Drop(c) LxResult c::tmod_Drop()
#define LXxD_ToolModel_Track LxResult tmod_Track([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] unsigned int eventType) override
#define LXxO_ToolModel_Track LXxD_ToolModel_Track
#define LXxC_ToolModel_Track(c) LxResult c::tmod_Track([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] unsigned int eventType)
#define LXxD_ToolModel_TrackFlags LxResult tmod_TrackFlags([[maybe_unused]] unsigned int *flags) override
#define LXxO_ToolModel_TrackFlags LXxD_ToolModel_TrackFlags
#define LXxC_ToolModel_TrackFlags(c) LxResult c::tmod_TrackFlags([[maybe_unused]] unsigned int *flags)
#define LXxD_ToolModel_Post LxResult tmod_Post([[maybe_unused]] ILxUnknownID vts) override
#define LXxO_ToolModel_Post LXxD_ToolModel_Post
#define LXxC_ToolModel_Post(c) LxResult c::tmod_Post([[maybe_unused]] ILxUnknownID vts)
#define LXxD_ToolModel_TestType LxResult tmod_TestType([[maybe_unused]] LXtID4 type) override
#define LXxO_ToolModel_TestType LXxD_ToolModel_TestType
#define LXxC_ToolModel_TestType(c) LxResult c::tmod_TestType([[maybe_unused]] LXtID4 type)
#define LXxD_ToolModel_Tooltip const char * tmod_Tooltip([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] int part) override
#define LXxO_ToolModel_Tooltip LXxD_ToolModel_Tooltip
#define LXxC_ToolModel_Tooltip(c) const char * c::tmod_Tooltip([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] int part)

template <class T>
class CLxIfc_ToolModel: public CLxInterface
{
public:
    CLxIfc_ToolModel()
    {
        vt.Flags = Flags;
        vt.Draw = Draw;
        vt.Test = Test;
        vt.Filter = Filter;
        vt.Initialize = Initialize;
        vt.Down = Down;
        vt.Move = Move;
        vt.Up = Up;
        vt.Haul = Haul;
        vt.AllowOverride = AllowOverride;
        vt.Help = Help;
        vt.Enable = Enable;
        vt.Drop = Drop;
        vt.Track = Track;
        vt.TrackFlags = TrackFlags;
        vt.Post = Post;
        vt.TestType = TestType;
        vt.Tooltip = Tooltip;
        vTable = &vt.iunk;
        iid = &lx::guid_ToolModel;
    }

    static auto Flags(LXtObjectID wcom) -> unsigned
    {
        LXCWxINST (CLxImpl_ToolModel, loc);
        return loc->tmod_Flags();
    }

    static auto Draw(LXtObjectID wcom,LXtObjectID vts,LXtObjectID stroke,int flags) -> void
    {
        LXCWxINST (CLxImpl_ToolModel, loc);
        loc->tmod_Draw((ILxUnknownID) vts,(ILxUnknownID) stroke, flags);
    }

    static auto Test(LXtObjectID wcom,LXtObjectID vts,LXtObjectID stroke,int flags) -> void
    {
        LXCWxINST (CLxImpl_ToolModel, loc);
        loc->tmod_Test((ILxUnknownID) vts,(ILxUnknownID) stroke, flags);
    }

    static auto Filter(LXtObjectID wcom,LXtObjectID vts,LXtObjectID adjust) -> void
    {
        LXCWxINST (CLxImpl_ToolModel, loc);
        loc->tmod_Filter((ILxUnknownID) vts,(ILxUnknownID) adjust);
    }

    static auto Initialize(LXtObjectID wcom,LXtObjectID vts,LXtObjectID adjust,unsigned int flags) -> void
    {
        LXCWxINST (CLxImpl_ToolModel, loc);
        loc->tmod_Initialize((ILxUnknownID) vts,(ILxUnknownID) adjust, flags);
    }

    static auto Down(LXtObjectID wcom,LXtObjectID vts,LXtObjectID adjust) -> LxResult
    {
        LXCWxINST (CLxImpl_ToolModel, loc);
        try
        {
           return loc->tmod_Down((ILxUnknownID) vts,(ILxUnknownID) adjust);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Move(LXtObjectID wcom,LXtObjectID vts,LXtObjectID adjust) -> void
    {
        LXCWxINST (CLxImpl_ToolModel, loc);
        loc->tmod_Move((ILxUnknownID) vts,(ILxUnknownID) adjust);
    }

    static auto Up(LXtObjectID wcom,LXtObjectID vts,LXtObjectID adjust) -> void
    {
        LXCWxINST (CLxImpl_ToolModel, loc);
        loc->tmod_Up((ILxUnknownID) vts,(ILxUnknownID) adjust);
    }

    static auto Haul(LXtObjectID wcom,unsigned int index) -> const char *
    {
        LXCWxINST (CLxImpl_ToolModel, loc);
        return loc->tmod_Haul( index);
    }

    static auto AllowOverride(LXtObjectID wcom,const char *attrName,unsigned int mouseInput,unsigned int haulAxis) -> LxResult
    {
        LXCWxINST (CLxImpl_ToolModel, loc);
        try
        {
           return loc->tmod_AllowOverride( attrName, mouseInput, haulAxis);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Help(LXtObjectID wcom,LXtObjectID vts) -> const char *
    {
        LXCWxINST (CLxImpl_ToolModel, loc);
        return loc->tmod_Help((ILxUnknownID) vts);
    }

    static auto Enable(LXtObjectID wcom,LXtObjectID msg) -> LxResult
    {
        LXCWxINST (CLxImpl_ToolModel, loc);
        try
        {
           return loc->tmod_Enable((ILxUnknownID) msg);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Drop(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_ToolModel, loc);
        try
        {
           return loc->tmod_Drop();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Track(LXtObjectID wcom,LXtObjectID vts,unsigned int eventType) -> LxResult
    {
        LXCWxINST (CLxImpl_ToolModel, loc);
        try
        {
           return loc->tmod_Track((ILxUnknownID) vts, eventType);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto TrackFlags(LXtObjectID wcom,unsigned int *flags) -> LxResult
    {
        LXCWxINST (CLxImpl_ToolModel, loc);
        try
        {
           return loc->tmod_TrackFlags( flags);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Post(LXtObjectID wcom,LXtObjectID vts) -> LxResult
    {
        LXCWxINST (CLxImpl_ToolModel, loc);
        try
        {
           return loc->tmod_Post((ILxUnknownID) vts);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto TestType(LXtObjectID wcom,LXtID4 type) -> LxResult
    {
        LXCWxINST (CLxImpl_ToolModel, loc);
        try
        {
           return loc->tmod_TestType( type);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Tooltip(LXtObjectID wcom,LXtObjectID vts,int part) -> const char *
    {
        LXCWxINST (CLxImpl_ToolModel, loc);
        return loc->tmod_Tooltip((ILxUnknownID) vts, part);
    }

private:
    ILxToolModel vt;
};

class CLxLoc_ToolModel : public CLxLocalize<ILxToolModelID>
{
public:
    CLxLoc_ToolModel()
    {
        _init();
    }

    CLxLoc_ToolModel(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_ToolModel(CLxLoc_ToolModel const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_ToolModel;
    }

    auto Flags(void) -> unsigned
    {
        return m_loc[0]->Flags(m_loc);
    }

    auto Draw(ILxUnknownID vts, ILxUnknownID stroke, int flags) -> void
    {
        m_loc[0]->Draw(m_loc,(ILxUnknownID) vts,(ILxUnknownID) stroke, flags);
    }

    auto Test(ILxUnknownID vts, ILxUnknownID stroke, int flags) -> void
    {
        m_loc[0]->Test(m_loc,(ILxUnknownID) vts,(ILxUnknownID) stroke, flags);
    }

    auto Filter(ILxUnknownID vts, ILxUnknownID adjust) -> void
    {
        m_loc[0]->Filter(m_loc,(ILxUnknownID) vts,(ILxUnknownID) adjust);
    }

    auto Initialize(ILxUnknownID vts, ILxUnknownID adjust, unsigned int flags) -> void
    {
        m_loc[0]->Initialize(m_loc,(ILxUnknownID) vts,(ILxUnknownID) adjust, flags);
    }

    auto Down(ILxUnknownID vts, ILxUnknownID adjust) -> LxResult
    {
        return m_loc[0]->Down(m_loc,(ILxUnknownID) vts,(ILxUnknownID) adjust);
    }

    auto Move(ILxUnknownID vts, ILxUnknownID adjust) -> void
    {
        m_loc[0]->Move(m_loc,(ILxUnknownID) vts,(ILxUnknownID) adjust);
    }

    auto Up(ILxUnknownID vts, ILxUnknownID adjust) -> void
    {
        m_loc[0]->Up(m_loc,(ILxUnknownID) vts,(ILxUnknownID) adjust);
    }

    auto Haul(unsigned int index) -> const char *
    {
        return m_loc[0]->Haul(m_loc, index);
    }

    auto AllowOverride(const char *attrName, unsigned int mouseInput, unsigned int haulAxis) -> LxResult
    {
        return m_loc[0]->AllowOverride(m_loc, attrName, mouseInput, haulAxis);
    }

    auto Help(ILxUnknownID vts) -> const char *
    {
        return m_loc[0]->Help(m_loc,(ILxUnknownID) vts);
    }

    auto Enable(ILxUnknownID msg) -> LxResult
    {
        return m_loc[0]->Enable(m_loc,(ILxUnknownID) msg);
    }

    auto Drop(void) -> LxResult
    {
        return m_loc[0]->Drop(m_loc);
    }

    auto Track(ILxUnknownID vts, unsigned int eventType) -> LxResult
    {
        return m_loc[0]->Track(m_loc,(ILxUnknownID) vts, eventType);
    }

    auto TrackFlags(unsigned int *flags) -> LxResult
    {
        return m_loc[0]->TrackFlags(m_loc, flags);
    }

    auto Post(ILxUnknownID vts) -> LxResult
    {
        return m_loc[0]->Post(m_loc,(ILxUnknownID) vts);
    }

    auto TestType(LXtID4 type) -> LxResult
    {
        return m_loc[0]->TestType(m_loc, type);
    }

    auto Tooltip(ILxUnknownID vts, int part) -> const char *
    {
        return m_loc[0]->Tooltip(m_loc,(ILxUnknownID) vts, part);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_ToolModel4
{
public:
    virtual ~CLxImpl_ToolModel4() = default;

    virtual auto tmod_Flags([[maybe_unused]] void) -> unsigned
    {
        return LXfTMOD_DRAW_3D;
    }

    virtual void tmod_Draw([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID stroke, [[maybe_unused]] int flags)
    {
    }

    virtual void tmod_Test([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID stroke, [[maybe_unused]] int flags)
    {
    }

    virtual void tmod_Filter([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID adjust)
    {
    }

    virtual void tmod_Initialize([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID adjust, [[maybe_unused]] unsigned int flags)
    {
    }

    virtual auto tmod_Down([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID adjust) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual void tmod_Move([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID adjust)
    {
    }

    virtual void tmod_Up([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID adjust)
    {
    }

    virtual auto tmod_Haul([[maybe_unused]] unsigned int index) -> const char *
    {
        return 0;
    }

    virtual auto tmod_Help([[maybe_unused]] ILxUnknownID vts) -> const char *
    {
        return 0;
    }

    virtual auto tmod_Enable([[maybe_unused]] ILxUnknownID msg) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto tmod_Drop([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto tmod_Track([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] unsigned int eventType) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto tmod_TrackFlags([[maybe_unused]] unsigned int *flags) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto tmod_Post([[maybe_unused]] ILxUnknownID vts) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto tmod_TestType([[maybe_unused]] LXtID4 type) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto tmod_Tooltip([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] int part) -> const char *
    {
        return 0;
    }
};

#define LXxD_ToolModel4_Flags unsigned tmod_Flags() override
#define LXxO_ToolModel4_Flags LXxD_ToolModel4_Flags
#define LXxC_ToolModel4_Flags(c) unsigned c::tmod_Flags()
#define LXxD_ToolModel4_Draw void tmod_Draw([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID stroke, [[maybe_unused]] int flags) override
#define LXxO_ToolModel4_Draw LXxD_ToolModel4_Draw
#define LXxC_ToolModel4_Draw(c) void c::tmod_Draw([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID stroke, [[maybe_unused]] int flags)
#define LXxD_ToolModel4_Test void tmod_Test([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID stroke, [[maybe_unused]] int flags) override
#define LXxO_ToolModel4_Test LXxD_ToolModel4_Test
#define LXxC_ToolModel4_Test(c) void c::tmod_Test([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID stroke, [[maybe_unused]] int flags)
#define LXxD_ToolModel4_Filter void tmod_Filter([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID adjust) override
#define LXxO_ToolModel4_Filter LXxD_ToolModel4_Filter
#define LXxC_ToolModel4_Filter(c) void c::tmod_Filter([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID adjust)
#define LXxD_ToolModel4_Initialize void tmod_Initialize([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID adjust, [[maybe_unused]] unsigned int flags) override
#define LXxO_ToolModel4_Initialize LXxD_ToolModel4_Initialize
#define LXxC_ToolModel4_Initialize(c) void c::tmod_Initialize([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID adjust, [[maybe_unused]] unsigned int flags)
#define LXxD_ToolModel4_Down LxResult tmod_Down([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID adjust) override
#define LXxO_ToolModel4_Down LXxD_ToolModel4_Down
#define LXxC_ToolModel4_Down(c) LxResult c::tmod_Down([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID adjust)
#define LXxD_ToolModel4_Move void tmod_Move([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID adjust) override
#define LXxO_ToolModel4_Move LXxD_ToolModel4_Move
#define LXxC_ToolModel4_Move(c) void c::tmod_Move([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID adjust)
#define LXxD_ToolModel4_Up void tmod_Up([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID adjust) override
#define LXxO_ToolModel4_Up LXxD_ToolModel4_Up
#define LXxC_ToolModel4_Up(c) void c::tmod_Up([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID adjust)
#define LXxD_ToolModel4_Haul const char * tmod_Haul([[maybe_unused]] unsigned int index) override
#define LXxO_ToolModel4_Haul LXxD_ToolModel4_Haul
#define LXxC_ToolModel4_Haul(c) const char * c::tmod_Haul([[maybe_unused]] unsigned int index)
#define LXxD_ToolModel4_Help const char * tmod_Help([[maybe_unused]] ILxUnknownID vts) override
#define LXxO_ToolModel4_Help LXxD_ToolModel4_Help
#define LXxC_ToolModel4_Help(c) const char * c::tmod_Help([[maybe_unused]] ILxUnknownID vts)
#define LXxD_ToolModel4_Enable LxResult tmod_Enable([[maybe_unused]] ILxUnknownID msg) override
#define LXxO_ToolModel4_Enable LXxD_ToolModel4_Enable
#define LXxC_ToolModel4_Enable(c) LxResult c::tmod_Enable([[maybe_unused]] ILxUnknownID msg)
#define LXxD_ToolModel4_Drop LxResult tmod_Drop() override
#define LXxO_ToolModel4_Drop LXxD_ToolModel4_Drop
#define LXxC_ToolModel4_Drop(c) LxResult c::tmod_Drop()
#define LXxD_ToolModel4_Track LxResult tmod_Track([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] unsigned int eventType) override
#define LXxO_ToolModel4_Track LXxD_ToolModel4_Track
#define LXxC_ToolModel4_Track(c) LxResult c::tmod_Track([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] unsigned int eventType)
#define LXxD_ToolModel4_TrackFlags LxResult tmod_TrackFlags([[maybe_unused]] unsigned int *flags) override
#define LXxO_ToolModel4_TrackFlags LXxD_ToolModel4_TrackFlags
#define LXxC_ToolModel4_TrackFlags(c) LxResult c::tmod_TrackFlags([[maybe_unused]] unsigned int *flags)
#define LXxD_ToolModel4_Post LxResult tmod_Post([[maybe_unused]] ILxUnknownID vts) override
#define LXxO_ToolModel4_Post LXxD_ToolModel4_Post
#define LXxC_ToolModel4_Post(c) LxResult c::tmod_Post([[maybe_unused]] ILxUnknownID vts)
#define LXxD_ToolModel4_TestType LxResult tmod_TestType([[maybe_unused]] LXtID4 type) override
#define LXxO_ToolModel4_TestType LXxD_ToolModel4_TestType
#define LXxC_ToolModel4_TestType(c) LxResult c::tmod_TestType([[maybe_unused]] LXtID4 type)
#define LXxD_ToolModel4_Tooltip const char * tmod_Tooltip([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] int part) override
#define LXxO_ToolModel4_Tooltip LXxD_ToolModel4_Tooltip
#define LXxC_ToolModel4_Tooltip(c) const char * c::tmod_Tooltip([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] int part)

template <class T>
class CLxIfc_ToolModel4: public CLxInterface
{
public:
    CLxIfc_ToolModel4()
    {
        vt.Flags = Flags;
        vt.Draw = Draw;
        vt.Test = Test;
        vt.Filter = Filter;
        vt.Initialize = Initialize;
        vt.Down = Down;
        vt.Move = Move;
        vt.Up = Up;
        vt.Haul = Haul;
        vt.Help = Help;
        vt.Enable = Enable;
        vt.Drop = Drop;
        vt.Track = Track;
        vt.TrackFlags = TrackFlags;
        vt.Post = Post;
        vt.TestType = TestType;
        vt.Tooltip = Tooltip;
        vTable = &vt.iunk;
        iid = &lx::guid_ToolModel4;
    }

    static auto Flags(LXtObjectID wcom) -> unsigned
    {
        LXCWxINST (CLxImpl_ToolModel4, loc);
        return loc->tmod_Flags();
    }

    static auto Draw(LXtObjectID wcom,LXtObjectID vts,LXtObjectID stroke,int flags) -> void
    {
        LXCWxINST (CLxImpl_ToolModel4, loc);
        loc->tmod_Draw((ILxUnknownID) vts,(ILxUnknownID) stroke, flags);
    }

    static auto Test(LXtObjectID wcom,LXtObjectID vts,LXtObjectID stroke,int flags) -> void
    {
        LXCWxINST (CLxImpl_ToolModel4, loc);
        loc->tmod_Test((ILxUnknownID) vts,(ILxUnknownID) stroke, flags);
    }

    static auto Filter(LXtObjectID wcom,LXtObjectID vts,LXtObjectID adjust) -> void
    {
        LXCWxINST (CLxImpl_ToolModel4, loc);
        loc->tmod_Filter((ILxUnknownID) vts,(ILxUnknownID) adjust);
    }

    static auto Initialize(LXtObjectID wcom,LXtObjectID vts,LXtObjectID adjust,unsigned int flags) -> void
    {
        LXCWxINST (CLxImpl_ToolModel4, loc);
        loc->tmod_Initialize((ILxUnknownID) vts,(ILxUnknownID) adjust, flags);
    }

    static auto Down(LXtObjectID wcom,LXtObjectID vts,LXtObjectID adjust) -> LxResult
    {
        LXCWxINST (CLxImpl_ToolModel4, loc);
        try
        {
           return loc->tmod_Down((ILxUnknownID) vts,(ILxUnknownID) adjust);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Move(LXtObjectID wcom,LXtObjectID vts,LXtObjectID adjust) -> void
    {
        LXCWxINST (CLxImpl_ToolModel4, loc);
        loc->tmod_Move((ILxUnknownID) vts,(ILxUnknownID) adjust);
    }

    static auto Up(LXtObjectID wcom,LXtObjectID vts,LXtObjectID adjust) -> void
    {
        LXCWxINST (CLxImpl_ToolModel4, loc);
        loc->tmod_Up((ILxUnknownID) vts,(ILxUnknownID) adjust);
    }

    static auto Haul(LXtObjectID wcom,unsigned int index) -> const char *
    {
        LXCWxINST (CLxImpl_ToolModel4, loc);
        return loc->tmod_Haul( index);
    }

    static auto Help(LXtObjectID wcom,LXtObjectID vts) -> const char *
    {
        LXCWxINST (CLxImpl_ToolModel4, loc);
        return loc->tmod_Help((ILxUnknownID) vts);
    }

    static auto Enable(LXtObjectID wcom,LXtObjectID msg) -> LxResult
    {
        LXCWxINST (CLxImpl_ToolModel4, loc);
        try
        {
           return loc->tmod_Enable((ILxUnknownID) msg);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Drop(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_ToolModel4, loc);
        try
        {
           return loc->tmod_Drop();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Track(LXtObjectID wcom,LXtObjectID vts,unsigned int eventType) -> LxResult
    {
        LXCWxINST (CLxImpl_ToolModel4, loc);
        try
        {
           return loc->tmod_Track((ILxUnknownID) vts, eventType);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto TrackFlags(LXtObjectID wcom,unsigned int *flags) -> LxResult
    {
        LXCWxINST (CLxImpl_ToolModel4, loc);
        try
        {
           return loc->tmod_TrackFlags( flags);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Post(LXtObjectID wcom,LXtObjectID vts) -> LxResult
    {
        LXCWxINST (CLxImpl_ToolModel4, loc);
        try
        {
           return loc->tmod_Post((ILxUnknownID) vts);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto TestType(LXtObjectID wcom,LXtID4 type) -> LxResult
    {
        LXCWxINST (CLxImpl_ToolModel4, loc);
        try
        {
           return loc->tmod_TestType( type);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Tooltip(LXtObjectID wcom,LXtObjectID vts,int part) -> const char *
    {
        LXCWxINST (CLxImpl_ToolModel4, loc);
        return loc->tmod_Tooltip((ILxUnknownID) vts, part);
    }

private:
    ILxToolModel4 vt;
};

class CLxLoc_ToolModel4 : public CLxLocalize<ILxToolModel4ID>
{
public:
    CLxLoc_ToolModel4()
    {
        _init();
    }

    CLxLoc_ToolModel4(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_ToolModel4(CLxLoc_ToolModel4 const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_ToolModel4;
    }

    auto Flags(void) -> unsigned
    {
        return m_loc[0]->Flags(m_loc);
    }

    auto Draw(ILxUnknownID vts, ILxUnknownID stroke, int flags) -> void
    {
        m_loc[0]->Draw(m_loc,(ILxUnknownID) vts,(ILxUnknownID) stroke, flags);
    }

    auto Test(ILxUnknownID vts, ILxUnknownID stroke, int flags) -> void
    {
        m_loc[0]->Test(m_loc,(ILxUnknownID) vts,(ILxUnknownID) stroke, flags);
    }

    auto Filter(ILxUnknownID vts, ILxUnknownID adjust) -> void
    {
        m_loc[0]->Filter(m_loc,(ILxUnknownID) vts,(ILxUnknownID) adjust);
    }

    auto Initialize(ILxUnknownID vts, ILxUnknownID adjust, unsigned int flags) -> void
    {
        m_loc[0]->Initialize(m_loc,(ILxUnknownID) vts,(ILxUnknownID) adjust, flags);
    }

    auto Down(ILxUnknownID vts, ILxUnknownID adjust) -> LxResult
    {
        return m_loc[0]->Down(m_loc,(ILxUnknownID) vts,(ILxUnknownID) adjust);
    }

    auto Move(ILxUnknownID vts, ILxUnknownID adjust) -> void
    {
        m_loc[0]->Move(m_loc,(ILxUnknownID) vts,(ILxUnknownID) adjust);
    }

    auto Up(ILxUnknownID vts, ILxUnknownID adjust) -> void
    {
        m_loc[0]->Up(m_loc,(ILxUnknownID) vts,(ILxUnknownID) adjust);
    }

    auto Haul(unsigned int index) -> const char *
    {
        return m_loc[0]->Haul(m_loc, index);
    }

    auto Help(ILxUnknownID vts) -> const char *
    {
        return m_loc[0]->Help(m_loc,(ILxUnknownID) vts);
    }

    auto Enable(ILxUnknownID msg) -> LxResult
    {
        return m_loc[0]->Enable(m_loc,(ILxUnknownID) msg);
    }

    auto Drop(void) -> LxResult
    {
        return m_loc[0]->Drop(m_loc);
    }

    auto Track(ILxUnknownID vts, unsigned int eventType) -> LxResult
    {
        return m_loc[0]->Track(m_loc,(ILxUnknownID) vts, eventType);
    }

    auto TrackFlags(unsigned int *flags) -> LxResult
    {
        return m_loc[0]->TrackFlags(m_loc, flags);
    }

    auto Post(ILxUnknownID vts) -> LxResult
    {
        return m_loc[0]->Post(m_loc,(ILxUnknownID) vts);
    }

    auto TestType(LXtID4 type) -> LxResult
    {
        return m_loc[0]->TestType(m_loc, type);
    }

    auto Tooltip(ILxUnknownID vts, int part) -> const char *
    {
        return m_loc[0]->Tooltip(m_loc,(ILxUnknownID) vts, part);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_ToolModel3
{
public:
    virtual ~CLxImpl_ToolModel3() = default;

    virtual auto tmod_Flags([[maybe_unused]] void) -> unsigned
    {
        return LXfTMOD_DRAW_3D;
    }

    virtual void tmod_Draw([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID stroke, [[maybe_unused]] int flags)
    {
    }

    virtual void tmod_Test([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID stroke, [[maybe_unused]] int flags)
    {
    }

    virtual void tmod_Filter([[maybe_unused]] ILxUnknownID vts)
    {
    }

    virtual void tmod_Initialize([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID adjust, [[maybe_unused]] unsigned int flags)
    {
    }

    virtual auto tmod_Down([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID adjust) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual void tmod_Move([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID adjust)
    {
    }

    virtual void tmod_Up([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID adjust)
    {
    }

    virtual auto tmod_Haul([[maybe_unused]] unsigned int index) -> const char *
    {
        return 0;
    }

    virtual auto tmod_Help([[maybe_unused]] ILxUnknownID vts) -> const char *
    {
        return 0;
    }

    virtual auto tmod_Enable([[maybe_unused]] ILxUnknownID msg) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto tmod_Drop([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto tmod_Track([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] unsigned int eventType) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto tmod_TrackFlags([[maybe_unused]] unsigned int *flags) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto tmod_Post([[maybe_unused]] ILxUnknownID vts) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto tmod_TestType([[maybe_unused]] LXtID4 type) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual const char * tmod_Tooltip(ILxUnknownID vts, int part) = 0;
};

#define LXxD_ToolModel3_Flags unsigned tmod_Flags() override
#define LXxO_ToolModel3_Flags LXxD_ToolModel3_Flags
#define LXxC_ToolModel3_Flags(c) unsigned c::tmod_Flags()
#define LXxD_ToolModel3_Draw void tmod_Draw([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID stroke, [[maybe_unused]] int flags) override
#define LXxO_ToolModel3_Draw LXxD_ToolModel3_Draw
#define LXxC_ToolModel3_Draw(c) void c::tmod_Draw([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID stroke, [[maybe_unused]] int flags)
#define LXxD_ToolModel3_Test void tmod_Test([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID stroke, [[maybe_unused]] int flags) override
#define LXxO_ToolModel3_Test LXxD_ToolModel3_Test
#define LXxC_ToolModel3_Test(c) void c::tmod_Test([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID stroke, [[maybe_unused]] int flags)
#define LXxD_ToolModel3_Filter void tmod_Filter([[maybe_unused]] ILxUnknownID vts) override
#define LXxO_ToolModel3_Filter LXxD_ToolModel3_Filter
#define LXxC_ToolModel3_Filter(c) void c::tmod_Filter([[maybe_unused]] ILxUnknownID vts)
#define LXxD_ToolModel3_Initialize void tmod_Initialize([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID adjust, [[maybe_unused]] unsigned int flags) override
#define LXxO_ToolModel3_Initialize LXxD_ToolModel3_Initialize
#define LXxC_ToolModel3_Initialize(c) void c::tmod_Initialize([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID adjust, [[maybe_unused]] unsigned int flags)
#define LXxD_ToolModel3_Down LxResult tmod_Down([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID adjust) override
#define LXxO_ToolModel3_Down LXxD_ToolModel3_Down
#define LXxC_ToolModel3_Down(c) LxResult c::tmod_Down([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID adjust)
#define LXxD_ToolModel3_Move void tmod_Move([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID adjust) override
#define LXxO_ToolModel3_Move LXxD_ToolModel3_Move
#define LXxC_ToolModel3_Move(c) void c::tmod_Move([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID adjust)
#define LXxD_ToolModel3_Up void tmod_Up([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID adjust) override
#define LXxO_ToolModel3_Up LXxD_ToolModel3_Up
#define LXxC_ToolModel3_Up(c) void c::tmod_Up([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID adjust)
#define LXxD_ToolModel3_Haul const char * tmod_Haul([[maybe_unused]] unsigned int index) override
#define LXxO_ToolModel3_Haul LXxD_ToolModel3_Haul
#define LXxC_ToolModel3_Haul(c) const char * c::tmod_Haul([[maybe_unused]] unsigned int index)
#define LXxD_ToolModel3_Help const char * tmod_Help([[maybe_unused]] ILxUnknownID vts) override
#define LXxO_ToolModel3_Help LXxD_ToolModel3_Help
#define LXxC_ToolModel3_Help(c) const char * c::tmod_Help([[maybe_unused]] ILxUnknownID vts)
#define LXxD_ToolModel3_Enable LxResult tmod_Enable([[maybe_unused]] ILxUnknownID msg) override
#define LXxO_ToolModel3_Enable LXxD_ToolModel3_Enable
#define LXxC_ToolModel3_Enable(c) LxResult c::tmod_Enable([[maybe_unused]] ILxUnknownID msg)
#define LXxD_ToolModel3_Drop LxResult tmod_Drop() override
#define LXxO_ToolModel3_Drop LXxD_ToolModel3_Drop
#define LXxC_ToolModel3_Drop(c) LxResult c::tmod_Drop()
#define LXxD_ToolModel3_Track LxResult tmod_Track([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] unsigned int eventType) override
#define LXxO_ToolModel3_Track LXxD_ToolModel3_Track
#define LXxC_ToolModel3_Track(c) LxResult c::tmod_Track([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] unsigned int eventType)
#define LXxD_ToolModel3_TrackFlags LxResult tmod_TrackFlags([[maybe_unused]] unsigned int *flags) override
#define LXxO_ToolModel3_TrackFlags LXxD_ToolModel3_TrackFlags
#define LXxC_ToolModel3_TrackFlags(c) LxResult c::tmod_TrackFlags([[maybe_unused]] unsigned int *flags)
#define LXxD_ToolModel3_Post LxResult tmod_Post([[maybe_unused]] ILxUnknownID vts) override
#define LXxO_ToolModel3_Post LXxD_ToolModel3_Post
#define LXxC_ToolModel3_Post(c) LxResult c::tmod_Post([[maybe_unused]] ILxUnknownID vts)
#define LXxD_ToolModel3_TestType LxResult tmod_TestType([[maybe_unused]] LXtID4 type) override
#define LXxO_ToolModel3_TestType LXxD_ToolModel3_TestType
#define LXxC_ToolModel3_TestType(c) LxResult c::tmod_TestType([[maybe_unused]] LXtID4 type)
#define LXxD_ToolModel3_Tooltip const char * tmod_Tooltip([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] int part) override
#define LXxO_ToolModel3_Tooltip LXxD_ToolModel3_Tooltip
#define LXxC_ToolModel3_Tooltip(c) const char * c::tmod_Tooltip([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] int part)

template <class T>
class CLxIfc_ToolModel3: public CLxInterface
{
public:
    CLxIfc_ToolModel3()
    {
        vt.Flags = Flags;
        vt.Draw = Draw;
        vt.Test = Test;
        vt.Filter = Filter;
        vt.Initialize = Initialize;
        vt.Down = Down;
        vt.Move = Move;
        vt.Up = Up;
        vt.Haul = Haul;
        vt.Help = Help;
        vt.Enable = Enable;
        vt.Drop = Drop;
        vt.Track = Track;
        vt.TrackFlags = TrackFlags;
        vt.Post = Post;
        vt.TestType = TestType;
        vt.Tooltip = Tooltip;
        vTable = &vt.iunk;
        iid = &lx::guid_ToolModel3;
    }

    static auto Flags(LXtObjectID wcom) -> unsigned
    {
        LXCWxINST (CLxImpl_ToolModel3, loc);
        return loc->tmod_Flags();
    }

    static auto Draw(LXtObjectID wcom,LXtObjectID vts,LXtObjectID stroke,int flags) -> void
    {
        LXCWxINST (CLxImpl_ToolModel3, loc);
        loc->tmod_Draw((ILxUnknownID) vts,(ILxUnknownID) stroke, flags);
    }

    static auto Test(LXtObjectID wcom,LXtObjectID vts,LXtObjectID stroke,int flags) -> void
    {
        LXCWxINST (CLxImpl_ToolModel3, loc);
        loc->tmod_Test((ILxUnknownID) vts,(ILxUnknownID) stroke, flags);
    }

    static auto Filter(LXtObjectID wcom,LXtObjectID vts) -> void
    {
        LXCWxINST (CLxImpl_ToolModel3, loc);
        loc->tmod_Filter((ILxUnknownID) vts);
    }

    static auto Initialize(LXtObjectID wcom,LXtObjectID vts,LXtObjectID adjust,unsigned int flags) -> void
    {
        LXCWxINST (CLxImpl_ToolModel3, loc);
        loc->tmod_Initialize((ILxUnknownID) vts,(ILxUnknownID) adjust, flags);
    }

    static auto Down(LXtObjectID wcom,LXtObjectID vts,LXtObjectID adjust) -> LxResult
    {
        LXCWxINST (CLxImpl_ToolModel3, loc);
        try
        {
           return loc->tmod_Down((ILxUnknownID) vts,(ILxUnknownID) adjust);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Move(LXtObjectID wcom,LXtObjectID vts,LXtObjectID adjust) -> void
    {
        LXCWxINST (CLxImpl_ToolModel3, loc);
        loc->tmod_Move((ILxUnknownID) vts,(ILxUnknownID) adjust);
    }

    static auto Up(LXtObjectID wcom,LXtObjectID vts,LXtObjectID adjust) -> void
    {
        LXCWxINST (CLxImpl_ToolModel3, loc);
        loc->tmod_Up((ILxUnknownID) vts,(ILxUnknownID) adjust);
    }

    static auto Haul(LXtObjectID wcom,unsigned int index) -> const char *
    {
        LXCWxINST (CLxImpl_ToolModel3, loc);
        return loc->tmod_Haul( index);
    }

    static auto Help(LXtObjectID wcom,LXtObjectID vts) -> const char *
    {
        LXCWxINST (CLxImpl_ToolModel3, loc);
        return loc->tmod_Help((ILxUnknownID) vts);
    }

    static auto Enable(LXtObjectID wcom,LXtObjectID msg) -> LxResult
    {
        LXCWxINST (CLxImpl_ToolModel3, loc);
        try
        {
           return loc->tmod_Enable((ILxUnknownID) msg);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Drop(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_ToolModel3, loc);
        try
        {
           return loc->tmod_Drop();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Track(LXtObjectID wcom,LXtObjectID vts,unsigned int eventType) -> LxResult
    {
        LXCWxINST (CLxImpl_ToolModel3, loc);
        try
        {
           return loc->tmod_Track((ILxUnknownID) vts, eventType);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto TrackFlags(LXtObjectID wcom,unsigned int *flags) -> LxResult
    {
        LXCWxINST (CLxImpl_ToolModel3, loc);
        try
        {
           return loc->tmod_TrackFlags( flags);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Post(LXtObjectID wcom,LXtObjectID vts) -> LxResult
    {
        LXCWxINST (CLxImpl_ToolModel3, loc);
        try
        {
           return loc->tmod_Post((ILxUnknownID) vts);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto TestType(LXtObjectID wcom,LXtID4 type) -> LxResult
    {
        LXCWxINST (CLxImpl_ToolModel3, loc);
        try
        {
           return loc->tmod_TestType( type);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Tooltip(LXtObjectID wcom,LXtObjectID vts,int part) -> const char *
    {
        LXCWxINST (CLxImpl_ToolModel3, loc);
        return loc->tmod_Tooltip((ILxUnknownID) vts, part);
    }

private:
    ILxToolModel3 vt;
};

class CLxLoc_ToolModel3 : public CLxLocalize<ILxToolModel3ID>
{
public:
    CLxLoc_ToolModel3()
    {
        _init();
    }

    CLxLoc_ToolModel3(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_ToolModel3(CLxLoc_ToolModel3 const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_ToolModel3;
    }

    auto Flags(void) -> unsigned
    {
        return m_loc[0]->Flags(m_loc);
    }

    auto Draw(ILxUnknownID vts, ILxUnknownID stroke, int flags) -> void
    {
        m_loc[0]->Draw(m_loc,(ILxUnknownID) vts,(ILxUnknownID) stroke, flags);
    }

    auto Test(ILxUnknownID vts, ILxUnknownID stroke, int flags) -> void
    {
        m_loc[0]->Test(m_loc,(ILxUnknownID) vts,(ILxUnknownID) stroke, flags);
    }

    auto Filter(ILxUnknownID vts) -> void
    {
        m_loc[0]->Filter(m_loc,(ILxUnknownID) vts);
    }

    auto Initialize(ILxUnknownID vts, ILxUnknownID adjust, unsigned int flags) -> void
    {
        m_loc[0]->Initialize(m_loc,(ILxUnknownID) vts,(ILxUnknownID) adjust, flags);
    }

    auto Down(ILxUnknownID vts, ILxUnknownID adjust) -> LxResult
    {
        return m_loc[0]->Down(m_loc,(ILxUnknownID) vts,(ILxUnknownID) adjust);
    }

    auto Move(ILxUnknownID vts, ILxUnknownID adjust) -> void
    {
        m_loc[0]->Move(m_loc,(ILxUnknownID) vts,(ILxUnknownID) adjust);
    }

    auto Up(ILxUnknownID vts, ILxUnknownID adjust) -> void
    {
        m_loc[0]->Up(m_loc,(ILxUnknownID) vts,(ILxUnknownID) adjust);
    }

    auto Haul(unsigned int index) -> const char *
    {
        return m_loc[0]->Haul(m_loc, index);
    }

    auto Help(ILxUnknownID vts) -> const char *
    {
        return m_loc[0]->Help(m_loc,(ILxUnknownID) vts);
    }

    auto Enable(ILxUnknownID msg) -> LxResult
    {
        return m_loc[0]->Enable(m_loc,(ILxUnknownID) msg);
    }

    auto Drop(void) -> LxResult
    {
        return m_loc[0]->Drop(m_loc);
    }

    auto Track(ILxUnknownID vts, unsigned int eventType) -> LxResult
    {
        return m_loc[0]->Track(m_loc,(ILxUnknownID) vts, eventType);
    }

    auto TrackFlags(unsigned int *flags) -> LxResult
    {
        return m_loc[0]->TrackFlags(m_loc, flags);
    }

    auto Post(ILxUnknownID vts) -> LxResult
    {
        return m_loc[0]->Post(m_loc,(ILxUnknownID) vts);
    }

    auto TestType(LXtID4 type) -> LxResult
    {
        return m_loc[0]->TestType(m_loc, type);
    }

    auto Tooltip(ILxUnknownID vts, int part) -> const char *
    {
        return m_loc[0]->Tooltip(m_loc,(ILxUnknownID) vts, part);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_ToolModel2
{
public:
    virtual ~CLxImpl_ToolModel2() = default;

    virtual auto tmod_Flags([[maybe_unused]] void) -> unsigned
    {
        return LXfTMOD_DRAW_3D;
    }

    virtual void tmod_Draw([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID stroke, [[maybe_unused]] int flags)
    {
    }

    virtual void tmod_Test([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID stroke, [[maybe_unused]] int flags)
    {
    }

    virtual void tmod_Filter([[maybe_unused]] ILxUnknownID vts)
    {
    }

    virtual void tmod_Initialize([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID adjust, [[maybe_unused]] unsigned int flags)
    {
    }

    virtual auto tmod_Down([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID adjust) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual void tmod_Move([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID adjust)
    {
    }

    virtual void tmod_Up([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID adjust)
    {
    }

    virtual auto tmod_Haul([[maybe_unused]] unsigned int index) -> const char *
    {
        return 0;
    }

    virtual auto tmod_Help([[maybe_unused]] ILxUnknownID vts) -> const char *
    {
        return 0;
    }

    virtual auto tmod_Enable([[maybe_unused]] ILxUnknownID msg) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto tmod_Drop([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto tmod_Track([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] unsigned int eventType) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto tmod_TrackFlags([[maybe_unused]] unsigned int *flags) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto tmod_Post([[maybe_unused]] ILxUnknownID vts) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto tmod_TestType([[maybe_unused]] LXtID4 type) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_ToolModel2_Flags unsigned tmod_Flags() override
#define LXxO_ToolModel2_Flags LXxD_ToolModel2_Flags
#define LXxC_ToolModel2_Flags(c) unsigned c::tmod_Flags()
#define LXxD_ToolModel2_Draw void tmod_Draw([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID stroke, [[maybe_unused]] int flags) override
#define LXxO_ToolModel2_Draw LXxD_ToolModel2_Draw
#define LXxC_ToolModel2_Draw(c) void c::tmod_Draw([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID stroke, [[maybe_unused]] int flags)
#define LXxD_ToolModel2_Test void tmod_Test([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID stroke, [[maybe_unused]] int flags) override
#define LXxO_ToolModel2_Test LXxD_ToolModel2_Test
#define LXxC_ToolModel2_Test(c) void c::tmod_Test([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID stroke, [[maybe_unused]] int flags)
#define LXxD_ToolModel2_Filter void tmod_Filter([[maybe_unused]] ILxUnknownID vts) override
#define LXxO_ToolModel2_Filter LXxD_ToolModel2_Filter
#define LXxC_ToolModel2_Filter(c) void c::tmod_Filter([[maybe_unused]] ILxUnknownID vts)
#define LXxD_ToolModel2_Initialize void tmod_Initialize([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID adjust, [[maybe_unused]] unsigned int flags) override
#define LXxO_ToolModel2_Initialize LXxD_ToolModel2_Initialize
#define LXxC_ToolModel2_Initialize(c) void c::tmod_Initialize([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID adjust, [[maybe_unused]] unsigned int flags)
#define LXxD_ToolModel2_Down LxResult tmod_Down([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID adjust) override
#define LXxO_ToolModel2_Down LXxD_ToolModel2_Down
#define LXxC_ToolModel2_Down(c) LxResult c::tmod_Down([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID adjust)
#define LXxD_ToolModel2_Move void tmod_Move([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID adjust) override
#define LXxO_ToolModel2_Move LXxD_ToolModel2_Move
#define LXxC_ToolModel2_Move(c) void c::tmod_Move([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID adjust)
#define LXxD_ToolModel2_Up void tmod_Up([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID adjust) override
#define LXxO_ToolModel2_Up LXxD_ToolModel2_Up
#define LXxC_ToolModel2_Up(c) void c::tmod_Up([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID adjust)
#define LXxD_ToolModel2_Haul const char * tmod_Haul([[maybe_unused]] unsigned int index) override
#define LXxO_ToolModel2_Haul LXxD_ToolModel2_Haul
#define LXxC_ToolModel2_Haul(c) const char * c::tmod_Haul([[maybe_unused]] unsigned int index)
#define LXxD_ToolModel2_Help const char * tmod_Help([[maybe_unused]] ILxUnknownID vts) override
#define LXxO_ToolModel2_Help LXxD_ToolModel2_Help
#define LXxC_ToolModel2_Help(c) const char * c::tmod_Help([[maybe_unused]] ILxUnknownID vts)
#define LXxD_ToolModel2_Enable LxResult tmod_Enable([[maybe_unused]] ILxUnknownID msg) override
#define LXxO_ToolModel2_Enable LXxD_ToolModel2_Enable
#define LXxC_ToolModel2_Enable(c) LxResult c::tmod_Enable([[maybe_unused]] ILxUnknownID msg)
#define LXxD_ToolModel2_Drop LxResult tmod_Drop() override
#define LXxO_ToolModel2_Drop LXxD_ToolModel2_Drop
#define LXxC_ToolModel2_Drop(c) LxResult c::tmod_Drop()
#define LXxD_ToolModel2_Track LxResult tmod_Track([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] unsigned int eventType) override
#define LXxO_ToolModel2_Track LXxD_ToolModel2_Track
#define LXxC_ToolModel2_Track(c) LxResult c::tmod_Track([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] unsigned int eventType)
#define LXxD_ToolModel2_TrackFlags LxResult tmod_TrackFlags([[maybe_unused]] unsigned int *flags) override
#define LXxO_ToolModel2_TrackFlags LXxD_ToolModel2_TrackFlags
#define LXxC_ToolModel2_TrackFlags(c) LxResult c::tmod_TrackFlags([[maybe_unused]] unsigned int *flags)
#define LXxD_ToolModel2_Post LxResult tmod_Post([[maybe_unused]] ILxUnknownID vts) override
#define LXxO_ToolModel2_Post LXxD_ToolModel2_Post
#define LXxC_ToolModel2_Post(c) LxResult c::tmod_Post([[maybe_unused]] ILxUnknownID vts)
#define LXxD_ToolModel2_TestType LxResult tmod_TestType([[maybe_unused]] LXtID4 type) override
#define LXxO_ToolModel2_TestType LXxD_ToolModel2_TestType
#define LXxC_ToolModel2_TestType(c) LxResult c::tmod_TestType([[maybe_unused]] LXtID4 type)

template <class T>
class CLxIfc_ToolModel2: public CLxInterface
{
public:
    CLxIfc_ToolModel2()
    {
        vt.Flags = Flags;
        vt.Draw = Draw;
        vt.Test = Test;
        vt.Filter = Filter;
        vt.Initialize = Initialize;
        vt.Down = Down;
        vt.Move = Move;
        vt.Up = Up;
        vt.Haul = Haul;
        vt.Help = Help;
        vt.Enable = Enable;
        vt.Drop = Drop;
        vt.Track = Track;
        vt.TrackFlags = TrackFlags;
        vt.Post = Post;
        vt.TestType = TestType;
        vTable = &vt.iunk;
        iid = &lx::guid_ToolModel2;
    }

    static auto Flags(LXtObjectID wcom) -> unsigned
    {
        LXCWxINST (CLxImpl_ToolModel2, loc);
        return loc->tmod_Flags();
    }

    static auto Draw(LXtObjectID wcom,LXtObjectID vts,LXtObjectID stroke,int flags) -> void
    {
        LXCWxINST (CLxImpl_ToolModel2, loc);
        loc->tmod_Draw((ILxUnknownID) vts,(ILxUnknownID) stroke, flags);
    }

    static auto Test(LXtObjectID wcom,LXtObjectID vts,LXtObjectID stroke,int flags) -> void
    {
        LXCWxINST (CLxImpl_ToolModel2, loc);
        loc->tmod_Test((ILxUnknownID) vts,(ILxUnknownID) stroke, flags);
    }

    static auto Filter(LXtObjectID wcom,LXtObjectID vts) -> void
    {
        LXCWxINST (CLxImpl_ToolModel2, loc);
        loc->tmod_Filter((ILxUnknownID) vts);
    }

    static auto Initialize(LXtObjectID wcom,LXtObjectID vts,LXtObjectID adjust,unsigned int flags) -> void
    {
        LXCWxINST (CLxImpl_ToolModel2, loc);
        loc->tmod_Initialize((ILxUnknownID) vts,(ILxUnknownID) adjust, flags);
    }

    static auto Down(LXtObjectID wcom,LXtObjectID vts,LXtObjectID adjust) -> LxResult
    {
        LXCWxINST (CLxImpl_ToolModel2, loc);
        try
        {
           return loc->tmod_Down((ILxUnknownID) vts,(ILxUnknownID) adjust);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Move(LXtObjectID wcom,LXtObjectID vts,LXtObjectID adjust) -> void
    {
        LXCWxINST (CLxImpl_ToolModel2, loc);
        loc->tmod_Move((ILxUnknownID) vts,(ILxUnknownID) adjust);
    }

    static auto Up(LXtObjectID wcom,LXtObjectID vts,LXtObjectID adjust) -> void
    {
        LXCWxINST (CLxImpl_ToolModel2, loc);
        loc->tmod_Up((ILxUnknownID) vts,(ILxUnknownID) adjust);
    }

    static auto Haul(LXtObjectID wcom,unsigned int index) -> const char *
    {
        LXCWxINST (CLxImpl_ToolModel2, loc);
        return loc->tmod_Haul( index);
    }

    static auto Help(LXtObjectID wcom,LXtObjectID vts) -> const char *
    {
        LXCWxINST (CLxImpl_ToolModel2, loc);
        return loc->tmod_Help((ILxUnknownID) vts);
    }

    static auto Enable(LXtObjectID wcom,LXtObjectID msg) -> LxResult
    {
        LXCWxINST (CLxImpl_ToolModel2, loc);
        try
        {
           return loc->tmod_Enable((ILxUnknownID) msg);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Drop(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_ToolModel2, loc);
        try
        {
           return loc->tmod_Drop();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Track(LXtObjectID wcom,LXtObjectID vts,unsigned int eventType) -> LxResult
    {
        LXCWxINST (CLxImpl_ToolModel2, loc);
        try
        {
           return loc->tmod_Track((ILxUnknownID) vts, eventType);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto TrackFlags(LXtObjectID wcom,unsigned int *flags) -> LxResult
    {
        LXCWxINST (CLxImpl_ToolModel2, loc);
        try
        {
           return loc->tmod_TrackFlags( flags);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Post(LXtObjectID wcom,LXtObjectID vts) -> LxResult
    {
        LXCWxINST (CLxImpl_ToolModel2, loc);
        try
        {
           return loc->tmod_Post((ILxUnknownID) vts);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto TestType(LXtObjectID wcom,LXtID4 type) -> LxResult
    {
        LXCWxINST (CLxImpl_ToolModel2, loc);
        try
        {
           return loc->tmod_TestType( type);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxToolModel2 vt;
};

class CLxLoc_ToolModel2 : public CLxLocalize<ILxToolModel2ID>
{
public:
    CLxLoc_ToolModel2()
    {
        _init();
    }

    CLxLoc_ToolModel2(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_ToolModel2(CLxLoc_ToolModel2 const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_ToolModel2;
    }

    auto Flags(void) -> unsigned
    {
        return m_loc[0]->Flags(m_loc);
    }

    auto Draw(ILxUnknownID vts, ILxUnknownID stroke, int flags) -> void
    {
        m_loc[0]->Draw(m_loc,(ILxUnknownID) vts,(ILxUnknownID) stroke, flags);
    }

    auto Test(ILxUnknownID vts, ILxUnknownID stroke, int flags) -> void
    {
        m_loc[0]->Test(m_loc,(ILxUnknownID) vts,(ILxUnknownID) stroke, flags);
    }

    auto Filter(ILxUnknownID vts) -> void
    {
        m_loc[0]->Filter(m_loc,(ILxUnknownID) vts);
    }

    auto Initialize(ILxUnknownID vts, ILxUnknownID adjust, unsigned int flags) -> void
    {
        m_loc[0]->Initialize(m_loc,(ILxUnknownID) vts,(ILxUnknownID) adjust, flags);
    }

    auto Down(ILxUnknownID vts, ILxUnknownID adjust) -> LxResult
    {
        return m_loc[0]->Down(m_loc,(ILxUnknownID) vts,(ILxUnknownID) adjust);
    }

    auto Move(ILxUnknownID vts, ILxUnknownID adjust) -> void
    {
        m_loc[0]->Move(m_loc,(ILxUnknownID) vts,(ILxUnknownID) adjust);
    }

    auto Up(ILxUnknownID vts, ILxUnknownID adjust) -> void
    {
        m_loc[0]->Up(m_loc,(ILxUnknownID) vts,(ILxUnknownID) adjust);
    }

    auto Haul(unsigned int index) -> const char *
    {
        return m_loc[0]->Haul(m_loc, index);
    }

    auto Help(ILxUnknownID vts) -> const char *
    {
        return m_loc[0]->Help(m_loc,(ILxUnknownID) vts);
    }

    auto Enable(ILxUnknownID msg) -> LxResult
    {
        return m_loc[0]->Enable(m_loc,(ILxUnknownID) msg);
    }

    auto Drop(void) -> LxResult
    {
        return m_loc[0]->Drop(m_loc);
    }

    auto Track(ILxUnknownID vts, unsigned int eventType) -> LxResult
    {
        return m_loc[0]->Track(m_loc,(ILxUnknownID) vts, eventType);
    }

    auto TrackFlags(unsigned int *flags) -> LxResult
    {
        return m_loc[0]->TrackFlags(m_loc, flags);
    }

    auto Post(ILxUnknownID vts) -> LxResult
    {
        return m_loc[0]->Post(m_loc,(ILxUnknownID) vts);
    }

    auto TestType(LXtID4 type) -> LxResult
    {
        return m_loc[0]->TestType(m_loc, type);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_ToolModel1
{
public:
    virtual ~CLxImpl_ToolModel1() = default;

    virtual auto tmod_Flags([[maybe_unused]] void) -> unsigned
    {
        return LXfTMOD_DRAW_3D;
    }

    virtual void tmod_Draw([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID stroke, [[maybe_unused]] int flags)
    {
    }

    virtual void tmod_Test([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID stroke, [[maybe_unused]] int flags)
    {
    }

    virtual void tmod_Filter([[maybe_unused]] ILxUnknownID vts)
    {
    }

    virtual void tmod_Initialize([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID adjust, [[maybe_unused]] unsigned int flags)
    {
    }

    virtual auto tmod_Down([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID adjust) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual void tmod_Move([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID adjust)
    {
    }

    virtual void tmod_Up([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID adjust)
    {
    }

    virtual auto tmod_Haul([[maybe_unused]] unsigned int index) -> const char *
    {
        return 0;
    }

    virtual auto tmod_Help([[maybe_unused]] ILxUnknownID vts) -> const char *
    {
        return 0;
    }

    virtual auto tmod_Enable([[maybe_unused]] ILxUnknownID msg) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto tmod_Drop([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto tmod_Track([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] unsigned int eventType) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto tmod_TrackFlags([[maybe_unused]] unsigned int *flags) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto tmod_Post([[maybe_unused]] ILxUnknownID vts) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_ToolModel1_Flags unsigned tmod_Flags() override
#define LXxO_ToolModel1_Flags LXxD_ToolModel1_Flags
#define LXxC_ToolModel1_Flags(c) unsigned c::tmod_Flags()
#define LXxD_ToolModel1_Draw void tmod_Draw([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID stroke, [[maybe_unused]] int flags) override
#define LXxO_ToolModel1_Draw LXxD_ToolModel1_Draw
#define LXxC_ToolModel1_Draw(c) void c::tmod_Draw([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID stroke, [[maybe_unused]] int flags)
#define LXxD_ToolModel1_Test void tmod_Test([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID stroke, [[maybe_unused]] int flags) override
#define LXxO_ToolModel1_Test LXxD_ToolModel1_Test
#define LXxC_ToolModel1_Test(c) void c::tmod_Test([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID stroke, [[maybe_unused]] int flags)
#define LXxD_ToolModel1_Filter void tmod_Filter([[maybe_unused]] ILxUnknownID vts) override
#define LXxO_ToolModel1_Filter LXxD_ToolModel1_Filter
#define LXxC_ToolModel1_Filter(c) void c::tmod_Filter([[maybe_unused]] ILxUnknownID vts)
#define LXxD_ToolModel1_Initialize void tmod_Initialize([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID adjust, [[maybe_unused]] unsigned int flags) override
#define LXxO_ToolModel1_Initialize LXxD_ToolModel1_Initialize
#define LXxC_ToolModel1_Initialize(c) void c::tmod_Initialize([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID adjust, [[maybe_unused]] unsigned int flags)
#define LXxD_ToolModel1_Down LxResult tmod_Down([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID adjust) override
#define LXxO_ToolModel1_Down LXxD_ToolModel1_Down
#define LXxC_ToolModel1_Down(c) LxResult c::tmod_Down([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID adjust)
#define LXxD_ToolModel1_Move void tmod_Move([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID adjust) override
#define LXxO_ToolModel1_Move LXxD_ToolModel1_Move
#define LXxC_ToolModel1_Move(c) void c::tmod_Move([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID adjust)
#define LXxD_ToolModel1_Up void tmod_Up([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID adjust) override
#define LXxO_ToolModel1_Up LXxD_ToolModel1_Up
#define LXxC_ToolModel1_Up(c) void c::tmod_Up([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] ILxUnknownID adjust)
#define LXxD_ToolModel1_Haul const char * tmod_Haul([[maybe_unused]] unsigned int index) override
#define LXxO_ToolModel1_Haul LXxD_ToolModel1_Haul
#define LXxC_ToolModel1_Haul(c) const char * c::tmod_Haul([[maybe_unused]] unsigned int index)
#define LXxD_ToolModel1_Help const char * tmod_Help([[maybe_unused]] ILxUnknownID vts) override
#define LXxO_ToolModel1_Help LXxD_ToolModel1_Help
#define LXxC_ToolModel1_Help(c) const char * c::tmod_Help([[maybe_unused]] ILxUnknownID vts)
#define LXxD_ToolModel1_Enable LxResult tmod_Enable([[maybe_unused]] ILxUnknownID msg) override
#define LXxO_ToolModel1_Enable LXxD_ToolModel1_Enable
#define LXxC_ToolModel1_Enable(c) LxResult c::tmod_Enable([[maybe_unused]] ILxUnknownID msg)
#define LXxD_ToolModel1_Drop LxResult tmod_Drop() override
#define LXxO_ToolModel1_Drop LXxD_ToolModel1_Drop
#define LXxC_ToolModel1_Drop(c) LxResult c::tmod_Drop()
#define LXxD_ToolModel1_Track LxResult tmod_Track([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] unsigned int eventType) override
#define LXxO_ToolModel1_Track LXxD_ToolModel1_Track
#define LXxC_ToolModel1_Track(c) LxResult c::tmod_Track([[maybe_unused]] ILxUnknownID vts, [[maybe_unused]] unsigned int eventType)
#define LXxD_ToolModel1_TrackFlags LxResult tmod_TrackFlags([[maybe_unused]] unsigned int *flags) override
#define LXxO_ToolModel1_TrackFlags LXxD_ToolModel1_TrackFlags
#define LXxC_ToolModel1_TrackFlags(c) LxResult c::tmod_TrackFlags([[maybe_unused]] unsigned int *flags)
#define LXxD_ToolModel1_Post LxResult tmod_Post([[maybe_unused]] ILxUnknownID vts) override
#define LXxO_ToolModel1_Post LXxD_ToolModel1_Post
#define LXxC_ToolModel1_Post(c) LxResult c::tmod_Post([[maybe_unused]] ILxUnknownID vts)

template <class T>
class CLxIfc_ToolModel1: public CLxInterface
{
public:
    CLxIfc_ToolModel1()
    {
        vt.Flags = Flags;
        vt.Draw = Draw;
        vt.Test = Test;
        vt.Filter = Filter;
        vt.Initialize = Initialize;
        vt.Down = Down;
        vt.Move = Move;
        vt.Up = Up;
        vt.Haul = Haul;
        vt.Help = Help;
        vt.Enable = Enable;
        vt.Drop = Drop;
        vt.Track = Track;
        vt.TrackFlags = TrackFlags;
        vt.Post = Post;
        vTable = &vt.iunk;
        iid = &lx::guid_ToolModel1;
    }

    static auto Flags(LXtObjectID wcom) -> unsigned
    {
        LXCWxINST (CLxImpl_ToolModel1, loc);
        return loc->tmod_Flags();
    }

    static auto Draw(LXtObjectID wcom,LXtObjectID vts,LXtObjectID stroke,int flags) -> void
    {
        LXCWxINST (CLxImpl_ToolModel1, loc);
        loc->tmod_Draw((ILxUnknownID) vts,(ILxUnknownID) stroke, flags);
    }

    static auto Test(LXtObjectID wcom,LXtObjectID vts,LXtObjectID stroke,int flags) -> void
    {
        LXCWxINST (CLxImpl_ToolModel1, loc);
        loc->tmod_Test((ILxUnknownID) vts,(ILxUnknownID) stroke, flags);
    }

    static auto Filter(LXtObjectID wcom,LXtObjectID vts) -> void
    {
        LXCWxINST (CLxImpl_ToolModel1, loc);
        loc->tmod_Filter((ILxUnknownID) vts);
    }

    static auto Initialize(LXtObjectID wcom,LXtObjectID vts,LXtObjectID adjust,unsigned int flags) -> void
    {
        LXCWxINST (CLxImpl_ToolModel1, loc);
        loc->tmod_Initialize((ILxUnknownID) vts,(ILxUnknownID) adjust, flags);
    }

    static auto Down(LXtObjectID wcom,LXtObjectID vts,LXtObjectID adjust) -> LxResult
    {
        LXCWxINST (CLxImpl_ToolModel1, loc);
        try
        {
           return loc->tmod_Down((ILxUnknownID) vts,(ILxUnknownID) adjust);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Move(LXtObjectID wcom,LXtObjectID vts,LXtObjectID adjust) -> void
    {
        LXCWxINST (CLxImpl_ToolModel1, loc);
        loc->tmod_Move((ILxUnknownID) vts,(ILxUnknownID) adjust);
    }

    static auto Up(LXtObjectID wcom,LXtObjectID vts,LXtObjectID adjust) -> void
    {
        LXCWxINST (CLxImpl_ToolModel1, loc);
        loc->tmod_Up((ILxUnknownID) vts,(ILxUnknownID) adjust);
    }

    static auto Haul(LXtObjectID wcom,unsigned int index) -> const char *
    {
        LXCWxINST (CLxImpl_ToolModel1, loc);
        return loc->tmod_Haul( index);
    }

    static auto Help(LXtObjectID wcom,LXtObjectID vts) -> const char *
    {
        LXCWxINST (CLxImpl_ToolModel1, loc);
        return loc->tmod_Help((ILxUnknownID) vts);
    }

    static auto Enable(LXtObjectID wcom,LXtObjectID msg) -> LxResult
    {
        LXCWxINST (CLxImpl_ToolModel1, loc);
        try
        {
           return loc->tmod_Enable((ILxUnknownID) msg);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Drop(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_ToolModel1, loc);
        try
        {
           return loc->tmod_Drop();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Track(LXtObjectID wcom,LXtObjectID vts,unsigned int eventType) -> LxResult
    {
        LXCWxINST (CLxImpl_ToolModel1, loc);
        try
        {
           return loc->tmod_Track((ILxUnknownID) vts, eventType);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto TrackFlags(LXtObjectID wcom,unsigned int *flags) -> LxResult
    {
        LXCWxINST (CLxImpl_ToolModel1, loc);
        try
        {
           return loc->tmod_TrackFlags( flags);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Post(LXtObjectID wcom,LXtObjectID vts) -> LxResult
    {
        LXCWxINST (CLxImpl_ToolModel1, loc);
        try
        {
           return loc->tmod_Post((ILxUnknownID) vts);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxToolModel1 vt;
};

class CLxLoc_ToolModel1 : public CLxLocalize<ILxToolModel1ID>
{
public:
    CLxLoc_ToolModel1()
    {
        _init();
    }

    CLxLoc_ToolModel1(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_ToolModel1(CLxLoc_ToolModel1 const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_ToolModel1;
    }

    auto Flags(void) -> unsigned
    {
        return m_loc[0]->Flags(m_loc);
    }

    auto Draw(ILxUnknownID vts, ILxUnknownID stroke, int flags) -> void
    {
        m_loc[0]->Draw(m_loc,(ILxUnknownID) vts,(ILxUnknownID) stroke, flags);
    }

    auto Test(ILxUnknownID vts, ILxUnknownID stroke, int flags) -> void
    {
        m_loc[0]->Test(m_loc,(ILxUnknownID) vts,(ILxUnknownID) stroke, flags);
    }

    auto Filter(ILxUnknownID vts) -> void
    {
        m_loc[0]->Filter(m_loc,(ILxUnknownID) vts);
    }

    auto Initialize(ILxUnknownID vts, ILxUnknownID adjust, unsigned int flags) -> void
    {
        m_loc[0]->Initialize(m_loc,(ILxUnknownID) vts,(ILxUnknownID) adjust, flags);
    }

    auto Down(ILxUnknownID vts, ILxUnknownID adjust) -> LxResult
    {
        return m_loc[0]->Down(m_loc,(ILxUnknownID) vts,(ILxUnknownID) adjust);
    }

    auto Move(ILxUnknownID vts, ILxUnknownID adjust) -> void
    {
        m_loc[0]->Move(m_loc,(ILxUnknownID) vts,(ILxUnknownID) adjust);
    }

    auto Up(ILxUnknownID vts, ILxUnknownID adjust) -> void
    {
        m_loc[0]->Up(m_loc,(ILxUnknownID) vts,(ILxUnknownID) adjust);
    }

    auto Haul(unsigned int index) -> const char *
    {
        return m_loc[0]->Haul(m_loc, index);
    }

    auto Help(ILxUnknownID vts) -> const char *
    {
        return m_loc[0]->Help(m_loc,(ILxUnknownID) vts);
    }

    auto Enable(ILxUnknownID msg) -> LxResult
    {
        return m_loc[0]->Enable(m_loc,(ILxUnknownID) msg);
    }

    auto Drop(void) -> LxResult
    {
        return m_loc[0]->Drop(m_loc);
    }

    auto Track(ILxUnknownID vts, unsigned int eventType) -> LxResult
    {
        return m_loc[0]->Track(m_loc,(ILxUnknownID) vts, eventType);
    }

    auto TrackFlags(unsigned int *flags) -> LxResult
    {
        return m_loc[0]->TrackFlags(m_loc, flags);
    }

    auto Post(ILxUnknownID vts) -> LxResult
    {
        return m_loc[0]->Post(m_loc,(ILxUnknownID) vts);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_AdjustTool : public CLxLocalize<ILxAdjustToolID>
{
public:
    CLxLoc_AdjustTool()
    {
        _init();
    }

    CLxLoc_AdjustTool(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_AdjustTool(CLxLoc_AdjustTool const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_AdjustTool;
    }

    auto Value(unsigned int index, ILxUnknownID val) -> void
    {
        m_loc[0]->Value(m_loc, index,(ILxUnknownID) val);
    }

    auto SetInt(unsigned int index, int val) -> void
    {
        m_loc[0]->SetInt(m_loc, index, val);
    }

    auto SetFlt(unsigned int index, double val) -> void
    {
        m_loc[0]->SetFlt(m_loc, index, val);
    }

    auto SetString(unsigned int index, const char *val) -> void
    {
        m_loc[0]->SetString(m_loc, index, val);
    }

    auto Lock(void) -> void
    {
        m_loc[0]->Lock(m_loc);
    }

    auto Invalidate(void) -> void
    {
        m_loc[0]->Invalidate(m_loc);
    }

    auto Update(void) -> void
    {
        m_loc[0]->Update(m_loc);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_NavigationListener
{
public:
    virtual ~CLxImpl_NavigationListener() = default;

    virtual void nav_Down([[maybe_unused]] ILxUnknownID view, [[maybe_unused]] ILxUnknownID item)
    {
    }

    virtual void nav_Move([[maybe_unused]] ILxUnknownID view, [[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned hot, [[maybe_unused]] const LXtVector pos, [[maybe_unused]] const LXtMatrix rot, [[maybe_unused]] double zoom)
    {
    }

    virtual void nav_Up([[maybe_unused]] ILxUnknownID view, [[maybe_unused]] ILxUnknownID item)
    {
    }

    virtual void nav_Delta([[maybe_unused]] ILxUnknownID view, [[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned hot, [[maybe_unused]] const LXtVector pos, [[maybe_unused]] const LXtMatrix rot, [[maybe_unused]] double zoom)
    {
    }

    virtual void nav_Wheel([[maybe_unused]] ILxUnknownID view, [[maybe_unused]] ILxUnknownID item)
    {
    }

    virtual void nav_HotSyncPre([[maybe_unused]] ILxUnknownID view, [[maybe_unused]] ILxUnknownID item)
    {
    }

    virtual void nav_HotSyncPost([[maybe_unused]] ILxUnknownID view, [[maybe_unused]] ILxUnknownID item)
    {
    }
};

#define LXxD_NavigationListener_Down void nav_Down([[maybe_unused]] ILxUnknownID view, [[maybe_unused]] ILxUnknownID item) override
#define LXxO_NavigationListener_Down LXxD_NavigationListener_Down
#define LXxC_NavigationListener_Down(c) void c::nav_Down([[maybe_unused]] ILxUnknownID view, [[maybe_unused]] ILxUnknownID item)
#define LXxD_NavigationListener_Move void nav_Move([[maybe_unused]] ILxUnknownID view, [[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned hot, [[maybe_unused]] const LXtVector pos, [[maybe_unused]] const LXtMatrix rot, [[maybe_unused]] double zoom) override
#define LXxO_NavigationListener_Move LXxD_NavigationListener_Move
#define LXxC_NavigationListener_Move(c) void c::nav_Move([[maybe_unused]] ILxUnknownID view, [[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned hot, [[maybe_unused]] const LXtVector pos, [[maybe_unused]] const LXtMatrix rot, [[maybe_unused]] double zoom)
#define LXxD_NavigationListener_Up void nav_Up([[maybe_unused]] ILxUnknownID view, [[maybe_unused]] ILxUnknownID item) override
#define LXxO_NavigationListener_Up LXxD_NavigationListener_Up
#define LXxC_NavigationListener_Up(c) void c::nav_Up([[maybe_unused]] ILxUnknownID view, [[maybe_unused]] ILxUnknownID item)
#define LXxD_NavigationListener_Delta void nav_Delta([[maybe_unused]] ILxUnknownID view, [[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned hot, [[maybe_unused]] const LXtVector pos, [[maybe_unused]] const LXtMatrix rot, [[maybe_unused]] double zoom) override
#define LXxO_NavigationListener_Delta LXxD_NavigationListener_Delta
#define LXxC_NavigationListener_Delta(c) void c::nav_Delta([[maybe_unused]] ILxUnknownID view, [[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned hot, [[maybe_unused]] const LXtVector pos, [[maybe_unused]] const LXtMatrix rot, [[maybe_unused]] double zoom)
#define LXxD_NavigationListener_Wheel void nav_Wheel([[maybe_unused]] ILxUnknownID view, [[maybe_unused]] ILxUnknownID item) override
#define LXxO_NavigationListener_Wheel LXxD_NavigationListener_Wheel
#define LXxC_NavigationListener_Wheel(c) void c::nav_Wheel([[maybe_unused]] ILxUnknownID view, [[maybe_unused]] ILxUnknownID item)
#define LXxD_NavigationListener_HotSyncPre void nav_HotSyncPre([[maybe_unused]] ILxUnknownID view, [[maybe_unused]] ILxUnknownID item) override
#define LXxO_NavigationListener_HotSyncPre LXxD_NavigationListener_HotSyncPre
#define LXxC_NavigationListener_HotSyncPre(c) void c::nav_HotSyncPre([[maybe_unused]] ILxUnknownID view, [[maybe_unused]] ILxUnknownID item)
#define LXxD_NavigationListener_HotSyncPost void nav_HotSyncPost([[maybe_unused]] ILxUnknownID view, [[maybe_unused]] ILxUnknownID item) override
#define LXxO_NavigationListener_HotSyncPost LXxD_NavigationListener_HotSyncPost
#define LXxC_NavigationListener_HotSyncPost(c) void c::nav_HotSyncPost([[maybe_unused]] ILxUnknownID view, [[maybe_unused]] ILxUnknownID item)

template <class T>
class CLxIfc_NavigationListener: public CLxInterface
{
public:
    CLxIfc_NavigationListener()
    {
        vt.Down = Down;
        vt.Move = Move;
        vt.Up = Up;
        vt.Delta = Delta;
        vt.Wheel = Wheel;
        vt.HotSyncPre = HotSyncPre;
        vt.HotSyncPost = HotSyncPost;
        vTable = &vt.iunk;
        iid = &lx::guid_NavigationListener;
    }

    static auto Down(LXtObjectID wcom,LXtObjectID view,LXtObjectID item) -> void
    {
        LXCWxINST (CLxImpl_NavigationListener, loc);
        loc->nav_Down((ILxUnknownID) view,(ILxUnknownID) item);
    }

    static auto Move(LXtObjectID wcom,LXtObjectID view,LXtObjectID item,unsigned hot,const LXtVector pos,const LXtMatrix rot,double zoom) -> void
    {
        LXCWxINST (CLxImpl_NavigationListener, loc);
        loc->nav_Move((ILxUnknownID) view,(ILxUnknownID) item, hot, pos, rot, zoom);
    }

    static auto Up(LXtObjectID wcom,LXtObjectID view,LXtObjectID item) -> void
    {
        LXCWxINST (CLxImpl_NavigationListener, loc);
        loc->nav_Up((ILxUnknownID) view,(ILxUnknownID) item);
    }

    static auto Delta(LXtObjectID wcom,LXtObjectID view,LXtObjectID item,unsigned hot,const LXtVector pos,const LXtMatrix rot,double zoom) -> void
    {
        LXCWxINST (CLxImpl_NavigationListener, loc);
        loc->nav_Delta((ILxUnknownID) view,(ILxUnknownID) item, hot, pos, rot, zoom);
    }

    static auto Wheel(LXtObjectID wcom,LXtObjectID view,LXtObjectID item) -> void
    {
        LXCWxINST (CLxImpl_NavigationListener, loc);
        loc->nav_Wheel((ILxUnknownID) view,(ILxUnknownID) item);
    }

    static auto HotSyncPre(LXtObjectID wcom,LXtObjectID view,LXtObjectID item) -> void
    {
        LXCWxINST (CLxImpl_NavigationListener, loc);
        loc->nav_HotSyncPre((ILxUnknownID) view,(ILxUnknownID) item);
    }

    static auto HotSyncPost(LXtObjectID wcom,LXtObjectID view,LXtObjectID item) -> void
    {
        LXCWxINST (CLxImpl_NavigationListener, loc);
        loc->nav_HotSyncPost((ILxUnknownID) view,(ILxUnknownID) item);
    }

private:
    ILxNavigationListener vt;
};

class CLxLoc_NavigationListener : public CLxLocalize<ILxNavigationListenerID>
{
public:
    CLxLoc_NavigationListener()
    {
        _init();
    }

    CLxLoc_NavigationListener(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_NavigationListener(CLxLoc_NavigationListener const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_NavigationListener;
    }

    auto Down(ILxUnknownID view, ILxUnknownID item) -> void
    {
        m_loc[0]->Down(m_loc,(ILxUnknownID) view,(ILxUnknownID) item);
    }

    auto Move(ILxUnknownID view, ILxUnknownID item, unsigned hot, const LXtVector pos, const LXtMatrix rot, double zoom) -> void
    {
        m_loc[0]->Move(m_loc,(ILxUnknownID) view,(ILxUnknownID) item, hot, pos, rot, zoom);
    }

    auto Up(ILxUnknownID view, ILxUnknownID item) -> void
    {
        m_loc[0]->Up(m_loc,(ILxUnknownID) view,(ILxUnknownID) item);
    }

    auto Delta(ILxUnknownID view, ILxUnknownID item, unsigned hot, const LXtVector pos, const LXtMatrix rot, double zoom) -> void
    {
        m_loc[0]->Delta(m_loc,(ILxUnknownID) view,(ILxUnknownID) item, hot, pos, rot, zoom);
    }

    auto Wheel(ILxUnknownID view, ILxUnknownID item) -> void
    {
        m_loc[0]->Wheel(m_loc,(ILxUnknownID) view,(ILxUnknownID) item);
    }

    auto HotSyncPre(ILxUnknownID view, ILxUnknownID item) -> void
    {
        m_loc[0]->HotSyncPre(m_loc,(ILxUnknownID) view,(ILxUnknownID) item);
    }

    auto HotSyncPost(ILxUnknownID view, ILxUnknownID item) -> void
    {
        m_loc[0]->HotSyncPost(m_loc,(ILxUnknownID) view,(ILxUnknownID) item);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
