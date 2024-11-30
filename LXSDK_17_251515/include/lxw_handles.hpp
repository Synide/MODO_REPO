//
// C++ wrapper for lxsdk/lxhandles.h.
//
//	Copyright 2024.
//
//
#pragma once

#include <lxhandles.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx
{
    static LXtGUID const guid_ShapeDraw = {0xDC46A7E2, {0x2849, 0x46CE}, {0x90, 0x75, 0x23, 0x94, 0xE0, 0x4E, 0xB3, 0xAE}};
    static LXtGUID const guid_HandleDraw = {0x502ACBC8, {0xADFB, 0x4493}, {0x82, 0x8C, 0x3D, 0x2E, 0xC4, 0x23, 0x05, 0x1B}};
    static LXtGUID const guid_HandleDraw1 = {0xEEC6665A, {0xBB44, 0x48A4}, {0x8F, 0x8C, 0xB4, 0xBC, 0xDF, 0x2E, 0xD8, 0x80}};
    static LXtGUID const guid_EventTranslatePacket = {0x4D50C150, {0x8681, 0x4F4A}, {0x91, 0xE9, 0xE7, 0x30, 0xC4, 0xD1, 0x17, 0x3A}};
    static LXtGUID const guid_EventTranslatePacket1 = {0x81B7CACE, {0xDB90, 0x4AD7}, {0xAE, 0x93, 0x42, 0xC2, 0x3E, 0x62, 0x13, 0x0D}};
    static LXtGUID const guid_EventGuide = {0xB2A11425, {0x25DE, 0x4628}, {0x83, 0x9C, 0x99, 0x50, 0x20, 0xBD, 0x8D, 0xF1}};
    static LXtGUID const guid_GeoConstraintPacket = {0x0589BA62, {0x5A11, 0x453d}, {0xB8, 0x4A, 0x1C, 0x7C, 0xF3, 0x0A, 0x0D, 0x35}};
} // namespace lx

class CLxLoc_ShapeDraw : public CLxLocalize<ILxShapeDrawID>
{
public:
    CLxLoc_ShapeDraw()
    {
        _init();
    }

    CLxLoc_ShapeDraw(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_ShapeDraw(CLxLoc_ShapeDraw const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_ShapeDraw;
    }

    auto Circle(const LXtVector col, double alpha, const LXtVector pos, double rad, int axis, int flags) -> void
    {
        m_loc[0]->Circle(m_loc, col, alpha, pos, rad, axis, flags);
    }

    auto Ellipse(const LXtVector col, double alpha, const LXtVector pos, const LXtVector rad, int axis, int flags) -> void
    {
        m_loc[0]->Ellipse(m_loc, col, alpha, pos, rad, axis, flags);
    }

    auto Pill(const LXtVector col, double alpha, const LXtVector pos, double width, double height, double rad, int axis, int flags) -> void
    {
        m_loc[0]->Pill(m_loc, col, alpha, pos, width, height, rad, axis, flags);
    }

    auto Bone(const LXtVector col, double rlen, int active) -> void
    {
        m_loc[0]->Bone(m_loc, col, rlen, active);
    }

    auto Arc(const LXtVector col, double alpha, const LXtVector pos, double rad, double start, double end, int axis, int flags) -> void
    {
        m_loc[0]->Arc(m_loc, col, alpha, pos, rad, start, end, axis, flags);
    }

    auto Plane(const LXtVector col, const LXtVector pos, const LXtVector size, int axis, int flags) -> void
    {
        m_loc[0]->Plane(m_loc, col, pos, size, axis, flags);
    }

    auto Ellipsoid(const LXtVector col, double alpha, const LXtVector pos, const LXtVector rad, int flags) -> void
    {
        m_loc[0]->Ellipsoid(m_loc, col, alpha, pos, rad, flags);
    }

    auto Cube(const LXtVector col, const LXtVector pos, const LXtVector size, int flags) -> void
    {
        m_loc[0]->Cube(m_loc, col, pos, size, flags);
    }

    auto CubeFill(const LXtVector col, double alpha, const LXtVector pos, const LXtVector size, int flags) -> void
    {
        m_loc[0]->CubeFill(m_loc, col, alpha, pos, size, flags);
    }

    auto BoxShape(const LXtVector colW, const LXtVector colF, const LXtVector pos, const LXtVector size, int flags) -> void
    {
        m_loc[0]->BoxShape(m_loc, colW, colF, pos, size, flags);
    }

    auto Pyramid(const LXtVector col, const LXtVector pos, const LXtVector size, int axis, int flags) -> void
    {
        m_loc[0]->Pyramid(m_loc, col, pos, size, axis, flags);
    }

    auto PyramidShape(const LXtVector colW, const LXtVector colF, const LXtVector pos, const LXtVector size, int axis, int flags) -> void
    {
        m_loc[0]->PyramidShape(m_loc, colW, colF, pos, size, axis, flags);
    }

    auto Rhombus(const LXtVector col, const LXtVector pos, const LXtVector size, int axis, int flags) -> void
    {
        m_loc[0]->Rhombus(m_loc, col, pos, size, axis, flags);
    }

    auto RhombusShape(const LXtVector colW, const LXtVector colF, const LXtVector pos, const LXtVector size, int axis, int flags) -> void
    {
        m_loc[0]->RhombusShape(m_loc, colW, colF, pos, size, axis, flags);
    }

    auto Cone(const LXtVector col, const LXtVector pos, double rad, double height, int axis, int flags) -> void
    {
        m_loc[0]->Cone(m_loc, col, pos, rad, height, axis, flags);
    }

    auto ConeShape(const LXtVector colW, const LXtVector colF, const LXtVector pos, double radius, double height, int axis, int flags) -> void
    {
        m_loc[0]->ConeShape(m_loc, colW, colF, pos, radius, height, axis, flags);
    }

    auto Cylinder(const LXtVector col, const LXtVector pos, double rad, double height, int axis, int flags) -> void
    {
        m_loc[0]->Cylinder(m_loc, col, pos, rad, height, axis, flags);
    }

    auto CylinderShape(const LXtVector colW, const LXtVector colF, const LXtVector pos, double radius, double height, int axis, int flags) -> void
    {
        m_loc[0]->CylinderShape(m_loc, colW, colF, pos, radius, height, axis, flags);
    }

    auto SphereShape(const LXtVector colW, const LXtVector colF, const LXtVector pos, double radius, int axis, int flags) -> void
    {
        m_loc[0]->SphereShape(m_loc, colW, colF, pos, radius, axis, flags);
    }

    auto CircleShape(const LXtVector colW, const LXtVector colF, const LXtVector pos, double radius, int axis, int flags) -> void
    {
        m_loc[0]->CircleShape(m_loc, colW, colF, pos, radius, axis, flags);
    }

    auto PlaneShape(const LXtVector colW, const LXtVector colF, const LXtVector pos, const LXtVector size, int axis, int flags) -> void
    {
        m_loc[0]->PlaneShape(m_loc, colW, colF, pos, size, axis, flags);
    }

    auto RadialMap(ILxUnknownID image, const LXtVector col, const LXtVector cen, double size, int sel, int flags) -> void
    {
        m_loc[0]->RadialMap(m_loc,(ILxUnknownID) image, col, cen, size, sel, flags);
    }

    auto RadialRays(ILxUnknownID image, const LXtVector col, const LXtVector cen, double size, int sel, int flags) -> void
    {
        m_loc[0]->RadialRays(m_loc,(ILxUnknownID) image, col, cen, size, sel, flags);
    }

    auto Link(const LXtVector col, const LXtVector posS, const LXtVector posE, int solid, int flags) -> void
    {
        m_loc[0]->Link(m_loc, col, posS, posE, solid, flags);
    }

    auto BBox(const LXtVector col, double size, int flags) -> void
    {
        m_loc[0]->BBox(m_loc, col, size, flags);
    }

    auto Arrow(const LXtVector col, const LXtVector pos, double size, int axis, int flags) -> void
    {
        m_loc[0]->Arrow(m_loc, col, pos, size, axis, flags);
    }

    auto Axis(const LXtVector col, const LXtVector pos, const LXtVector size, int flags) -> void
    {
        m_loc[0]->Axis(m_loc, col, pos, size, flags);
    }

    auto Star(const LXtVector col, const LXtVector pos, const LXtVector rad, int flags) -> void
    {
        m_loc[0]->Star(m_loc, col, pos, rad, flags);
    }

    auto Cross(const LXtVector col, const LXtVector pos, const LXtVector rad, int flags) -> void
    {
        m_loc[0]->Cross(m_loc, col, pos, rad, flags);
    }

    auto Line(const LXtVector v0, const LXtVector v1, const LXtVector col, double alpha, int flags) -> void
    {
        m_loc[0]->Line(m_loc, v0, v1, col, alpha, flags);
    }

    auto CSeg(const LXtVector cen, const LXtVector offset, double screen, const LXtVector col, int flags) -> void
    {
        m_loc[0]->CSeg(m_loc, cen, offset, screen, col, flags);
    }

    auto PlaneIndicator(const LXtVector col, double alpha, const LXtVector pos, double rad, int axis, int flags) -> void
    {
        m_loc[0]->PlaneIndicator(m_loc, col, alpha, pos, rad, axis, flags);
    }

    auto CrossHair(const LXtVector col, double alpha, const LXtVector pos, int flags) -> void
    {
        m_loc[0]->CrossHair(m_loc, col, alpha, pos, flags);
    }

    auto PreciseHandle(const LXtVector col, double alpha, const LXtVector pos, const LXtVector size, int flags) -> void
    {
        m_loc[0]->PreciseHandle(m_loc, col, alpha, pos, size, flags);
    }

    auto Ruler(const LXtVector col, const LXtVector pos, const LXtMatrix xfrm, double len, int axis, int flags) -> void
    {
        m_loc[0]->Ruler(m_loc, col, pos, xfrm, len, axis, flags);
    }

    auto Distance(const LXtVector col, const LXtVector pos, double dist, int axis, int flags) -> void
    {
        m_loc[0]->Distance(m_loc, col, pos, dist, axis, flags);
    }

    auto Dimension(const LXtVector col, const LXtVector A, const LXtVector B, const char *format, int top, int flags) -> void
    {
        m_loc[0]->Dimension(m_loc, col, A, B, format, top, flags);
    }

    auto Grid(const LXtVector col, const LXtVector pos, const LXtVector siz, int divX, int divY, int divZ, int axis, int flags) -> void
    {
        m_loc[0]->Grid(m_loc, col, pos, siz, divX, divY, divZ, axis, flags);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_HandleDraw : public CLxLocalize<ILxHandleDrawID>
{
public:
    CLxLoc_HandleDraw()
    {
        _init();
    }

    CLxLoc_HandleDraw(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_HandleDraw(CLxLoc_HandleDraw const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_HandleDraw;
    }

    auto Handle(const LXtVector pos, const LXtMatrix mat, int part, int flags) -> void
    {
        m_loc[0]->Handle(m_loc, pos, mat, part, flags);
    }

    auto AxisHandle(const LXtVector pos, const LXtMatrix mat, int axis, int part, double len, int flags) -> void
    {
        m_loc[0]->AxisHandle(m_loc, pos, mat, axis, part, len, flags);
    }

    auto MoveHandle(const LXtVector pos, const LXtMatrix mat, int axis, int part, int flags) -> void
    {
        m_loc[0]->MoveHandle(m_loc, pos, mat, axis, part, flags);
    }

    auto RotateHandle(const LXtVector pos, const LXtMatrix mat, int axis, int part, double sAngle, double eAngle, int facing, int flags) -> void
    {
        m_loc[0]->RotateHandle(m_loc, pos, mat, axis, part, sAngle, eAngle, facing, flags);
    }

    auto RotateMouseHandle(const LXtVector center, const LXtVector pos, const LXtMatrix mat, int axis, int part, int flags) -> void
    {
        m_loc[0]->RotateMouseHandle(m_loc, center, pos, mat, axis, part, flags);
    }

    auto ScaleHandle(const LXtVector pos, const LXtMatrix mat, int axis, int part, double offset, int line, int flags) -> void
    {
        m_loc[0]->ScaleHandle(m_loc, pos, mat, axis, part, offset, line, flags);
    }

    auto CrossHandle(const LXtVector pos, const LXtMatrix mat, int part, int flags) -> void
    {
        m_loc[0]->CrossHandle(m_loc, pos, mat, part, flags);
    }

    auto PointHandle(const LXtVector pos, int part, int flags) -> void
    {
        m_loc[0]->PointHandle(m_loc, pos, part, flags);
    }

    auto XHandle(const LXtVector pos, const LXtMatrix mat, int part, int flags) -> void
    {
        m_loc[0]->XHandle(m_loc, pos, mat, part, flags);
    }

    auto PlaneHandle(const LXtVector pos, const LXtMatrix mat, int axis, int part, int flags) -> void
    {
        m_loc[0]->PlaneHandle(m_loc, pos, mat, axis, part, flags);
    }

    auto LineHandleHilight(const LXtVector pos, const LXtVector dir, int part, int flags) -> void
    {
        m_loc[0]->LineHandleHilight(m_loc, pos, dir, part, flags);
    }

    auto PlaneHandleHilight(const LXtVector pos, const LXtVector norm, int part, int flags) -> void
    {
        m_loc[0]->PlaneHandleHilight(m_loc, pos, norm, part, flags);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_HandleDraw1 : public CLxLocalize<ILxHandleDraw1ID>
{
public:
    CLxLoc_HandleDraw1()
    {
        _init();
    }

    CLxLoc_HandleDraw1(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_HandleDraw1(CLxLoc_HandleDraw1 const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_HandleDraw1;
    }

    auto Handle(const LXtVector pos, const LXtMatrix mat, int part, int flags) -> void
    {
        m_loc[0]->Handle(m_loc, pos, mat, part, flags);
    }

    auto AxisHandle(const LXtVector pos, const LXtMatrix mat, int axis, int part, double len, int flags) -> void
    {
        m_loc[0]->AxisHandle(m_loc, pos, mat, axis, part, len, flags);
    }

    auto MoveHandle(const LXtVector pos, const LXtMatrix mat, int axis, int part, int flags) -> void
    {
        m_loc[0]->MoveHandle(m_loc, pos, mat, axis, part, flags);
    }

    auto RotateHandle(const LXtVector pos, const LXtMatrix mat, int axis, int part, double sAngle, double eAngle, int facing, int flags) -> void
    {
        m_loc[0]->RotateHandle(m_loc, pos, mat, axis, part, sAngle, eAngle, facing, flags);
    }

    auto RotateMouseHandle(const LXtVector center, const LXtVector pos, const LXtMatrix mat, int axis, int part, int flags) -> void
    {
        m_loc[0]->RotateMouseHandle(m_loc, center, pos, mat, axis, part, flags);
    }

    auto ScaleHandle(const LXtVector pos, const LXtMatrix mat, int axis, int part, double offset, int line, int flags) -> void
    {
        m_loc[0]->ScaleHandle(m_loc, pos, mat, axis, part, offset, line, flags);
    }

    auto CrossHandle(const LXtVector pos, const LXtMatrix mat, int part, int flags) -> void
    {
        m_loc[0]->CrossHandle(m_loc, pos, mat, part, flags);
    }

    auto PointHandle(const LXtVector pos, int part, int flags) -> void
    {
        m_loc[0]->PointHandle(m_loc, pos, part, flags);
    }

    auto XHandle(const LXtVector pos, const LXtMatrix mat, int part, int flags) -> void
    {
        m_loc[0]->XHandle(m_loc, pos, mat, part, flags);
    }

    auto PlaneHandle(const LXtVector pos, const LXtMatrix mat, int axis, int part, int flags) -> void
    {
        m_loc[0]->PlaneHandle(m_loc, pos, mat, axis, part, flags);
    }

    auto LineHandleHilight(const LXtVector pos, const LXtVector dir, int part, int flags) -> void
    {
        m_loc[0]->LineHandleHilight(m_loc, pos, dir, part, flags);
    }

    auto PlaneHandleHilight(const LXtVector pos, const LXtVector norm, int part, int flags) -> void
    {
        m_loc[0]->PlaneHandleHilight(m_loc, pos, norm, part, flags);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_EventTranslatePacket : public CLxLocalize<ILxEventTranslatePacketID>
{
public:
    CLxLoc_EventTranslatePacket()
    {
        _init();
    }

    CLxLoc_EventTranslatePacket(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_EventTranslatePacket(CLxLoc_EventTranslatePacket const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_EventTranslatePacket;
    }

    auto ToModel(ILxUnknownID toolVector, LXtVector pos, LXtVector axis) -> int
    {
        return m_loc[0]->ToModel(m_loc,(ILxUnknownID) toolVector, pos, axis);
    }

    auto ToModelLine(ILxUnknownID toolVector, const LXtVector center, const LXtVector dir, LXtVector pos) -> void
    {
        m_loc[0]->ToModelLine(m_loc,(ILxUnknownID) toolVector, center, dir, pos);
    }

    auto ToModelPlane(ILxUnknownID toolVector, const LXtVector center, const LXtVector normal, LXtVector pos) -> void
    {
        m_loc[0]->ToModelPlane(m_loc,(ILxUnknownID) toolVector, center, normal, pos);
    }

    auto ModelDelta(ILxUnknownID toolVector, const LXtVector handle, LXtVector delta) -> void
    {
        m_loc[0]->ModelDelta(m_loc,(ILxUnknownID) toolVector, handle, delta);
    }

    auto ModelLineDelta(ILxUnknownID toolVector, const LXtVector center, const LXtVector dir, const LXtVector handle, LXtVector delta) -> void
    {
        m_loc[0]->ModelLineDelta(m_loc,(ILxUnknownID) toolVector, center, dir, handle, delta);
    }

    auto ModelPlaneDelta(ILxUnknownID toolVector, const LXtVector center, const LXtVector normal, const LXtVector handle, LXtVector delta) -> void
    {
        m_loc[0]->ModelPlaneDelta(m_loc,(ILxUnknownID) toolVector, center, normal, handle, delta);
    }

    auto HitHandle(ILxUnknownID toolVector, const LXtVector handle) -> void
    {
        m_loc[0]->HitHandle(m_loc,(ILxUnknownID) toolVector, handle);
    }

    auto GetNewPosition(ILxUnknownID toolVector, LXtVector pos) -> void
    {
        m_loc[0]->GetNewPosition(m_loc,(ILxUnknownID) toolVector, pos);
    }

    auto SetLinearConstraint(ILxUnknownID toolVector, const LXtVector center, const LXtVector dir) -> void
    {
        m_loc[0]->SetLinearConstraint(m_loc,(ILxUnknownID) toolVector, center, dir);
    }

    auto SetPlanarConstraint(ILxUnknownID toolVector, const LXtVector center, const LXtVector normal) -> void
    {
        m_loc[0]->SetPlanarConstraint(m_loc,(ILxUnknownID) toolVector, center, normal);
    }

    auto GetConstraint(ILxUnknownID toolVector, LXtVector center, LXtVector vector) -> int
    {
        return m_loc[0]->GetConstraint(m_loc,(ILxUnknownID) toolVector, center, vector);
    }

    auto SetSnapRange(double inner, double outer) -> void
    {
        m_loc[0]->SetSnapRange(m_loc, inner, outer);
    }

    auto ScreenToRay(ILxUnknownID toolVector, float x, float y, LXtVector pos, LXtVector dir) -> void
    {
        m_loc[0]->ScreenToRay(m_loc,(ILxUnknownID) toolVector, x, y, pos, dir);
    }

    auto AddGuide(ILxUnknownID guide, void *client) -> void
    {
        m_loc[0]->AddGuide(m_loc,(ILxUnknownID) guide, client);
    }

    auto RemoveGuide(ILxUnknownID guide, void *client) -> int
    {
        return m_loc[0]->RemoveGuide(m_loc,(ILxUnknownID) guide, client);
    }

    auto SetLinearSnapConstraint(ILxUnknownID toolVector, const LXtVector center, const LXtVector dir) -> void
    {
        m_loc[0]->SetLinearSnapConstraint(m_loc,(ILxUnknownID) toolVector, center, dir);
    }

    auto SnapPosition(ILxUnknownID toolVector, const LXtVector pos, LXtVector snapPos) -> int
    {
        return m_loc[0]->SnapPosition(m_loc,(ILxUnknownID) toolVector, pos, snapPos);
    }

    auto SetPlanarSnapConstraint(ILxUnknownID toolVector, const LXtVector center, const LXtVector dir) -> void
    {
        m_loc[0]->SetPlanarSnapConstraint(m_loc,(ILxUnknownID) toolVector, center, dir);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_EventTranslatePacket1 : public CLxLocalize<ILxEventTranslatePacket1ID>
{
public:
    CLxLoc_EventTranslatePacket1()
    {
        _init();
    }

    CLxLoc_EventTranslatePacket1(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_EventTranslatePacket1(CLxLoc_EventTranslatePacket1 const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_EventTranslatePacket1;
    }

    auto ToModel(ILxUnknownID toolVector, LXtVector pos, LXtVector axis) -> int
    {
        return m_loc[0]->ToModel(m_loc,(ILxUnknownID) toolVector, pos, axis);
    }

    auto ToModelLine(ILxUnknownID toolVector, LXtVector center, LXtVector dir, LXtVector pos) -> void
    {
        m_loc[0]->ToModelLine(m_loc,(ILxUnknownID) toolVector, center, dir, pos);
    }

    auto ToModelPlane(ILxUnknownID toolVector, LXtVector center, LXtVector normal, LXtVector pos) -> void
    {
        m_loc[0]->ToModelPlane(m_loc,(ILxUnknownID) toolVector, center, normal, pos);
    }

    auto ModelDelta(ILxUnknownID toolVector, const LXtVector handle, LXtVector delta) -> void
    {
        m_loc[0]->ModelDelta(m_loc,(ILxUnknownID) toolVector, handle, delta);
    }

    auto ModelLineDelta(ILxUnknownID toolVector, const LXtVector center, const LXtVector dir, const LXtVector handle, LXtVector delta) -> void
    {
        m_loc[0]->ModelLineDelta(m_loc,(ILxUnknownID) toolVector, center, dir, handle, delta);
    }

    auto ModelPlaneDelta(ILxUnknownID toolVector, const LXtVector center, const LXtVector normal, const LXtVector handle, LXtVector delta) -> void
    {
        m_loc[0]->ModelPlaneDelta(m_loc,(ILxUnknownID) toolVector, center, normal, handle, delta);
    }

    auto HitHandle(ILxUnknownID toolVector, LXtVector handle) -> void
    {
        m_loc[0]->HitHandle(m_loc,(ILxUnknownID) toolVector, handle);
    }

    auto GetNewPosition(ILxUnknownID toolVector, LXtVector pos) -> void
    {
        m_loc[0]->GetNewPosition(m_loc,(ILxUnknownID) toolVector, pos);
    }

    auto SetLinearConstraint(ILxUnknownID toolVector, const LXtVector center, const LXtVector dir) -> void
    {
        m_loc[0]->SetLinearConstraint(m_loc,(ILxUnknownID) toolVector, center, dir);
    }

    auto SetPlanarConstraint(ILxUnknownID toolVector, const LXtVector center, const LXtVector normal) -> void
    {
        m_loc[0]->SetPlanarConstraint(m_loc,(ILxUnknownID) toolVector, center, normal);
    }

    auto GetConstraint(ILxUnknownID toolVector, LXtVector center, LXtVector vector) -> int
    {
        return m_loc[0]->GetConstraint(m_loc,(ILxUnknownID) toolVector, center, vector);
    }

    auto SetSnapRange(double inner, double outer) -> void
    {
        m_loc[0]->SetSnapRange(m_loc, inner, outer);
    }

    auto ScreenToRay(ILxUnknownID toolVector, float x, float y, LXtVector pos, LXtVector dir) -> void
    {
        m_loc[0]->ScreenToRay(m_loc,(ILxUnknownID) toolVector, x, y, pos, dir);
    }

    auto AddGuide(ILxUnknownID guide, void *client) -> void
    {
        m_loc[0]->AddGuide(m_loc,(ILxUnknownID) guide, client);
    }

    auto RemoveGuide(ILxUnknownID guide, void *client) -> int
    {
        return m_loc[0]->RemoveGuide(m_loc,(ILxUnknownID) guide, client);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_EventGuide : public CLxLocalize<ILxEventGuideID>
{
public:
    CLxLoc_EventGuide()
    {
        _init();
    }

    CLxLoc_EventGuide(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_EventGuide(CLxLoc_EventGuide const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_EventGuide;
    }

    auto Limits(double inner, double outer) -> int
    {
        return m_loc[0]->Limits(m_loc, inner, outer);
    }

    auto Proximity(ILxUnknownID toolVector, LXtVector pos, double *dist, int *priority, void *element) -> int
    {
        return m_loc[0]->Proximity(m_loc,(ILxUnknownID) toolVector, pos, dist, priority, element);
    }

    auto SetDrawState(int flags) -> int
    {
        return m_loc[0]->SetDrawState(m_loc, flags);
    }

    auto SetFlags(int flags) -> void
    {
        m_loc[0]->SetFlags(m_loc, flags);
    }

    auto Flags(void) -> int
    {
        return m_loc[0]->Flags(m_loc);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};

