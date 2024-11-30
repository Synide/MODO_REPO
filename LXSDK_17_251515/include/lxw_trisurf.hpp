//
// C++ wrapper for lxsdk/lxtrisurf.h.
//
//	Copyright 2024.
//
//
#pragma once

#include <lxtrisurf.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx
{
    static LXtGUID const guid_TriangleSurface = {0xB1D985A7, {0x34D6, 0x4251}, {0x94, 0xAA, 0xEE, 0xFB, 0x2C, 0x75, 0x27, 0xF9}};
    static LXtGUID const guid_TriangleGroup = {0x3A0597DF, {0xEA75, 0x4272}, {0x88, 0x31, 0x6B, 0x7A, 0x2B, 0xA5, 0xFE, 0xE3}};
    static LXtGUID const guid_TriangleGroup1 = {0x6975B2A4, {0x69E8, 0x4ED2}, {0x90, 0x58, 0x9C, 0x09, 0x48, 0xCB, 0xB4, 0x3C}};
} // namespace lx

class CLxLoc_TriangleSurface : public CLxLocalize<ILxTriangleSurfaceID>
{
public:
    CLxLoc_TriangleSurface()
    {
        _init();
    }

    CLxLoc_TriangleSurface(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_TriangleSurface(CLxLoc_TriangleSurface const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_TriangleSurface;
    }

    auto SetSize(unsigned nvrt, unsigned ntri) -> LxResult
    {
        return m_loc[0]->SetSize(m_loc, nvrt, ntri);
    }

    auto AddVector(LXtID4 type, const char *name, unsigned *index) -> LxResult
    {
        return m_loc[0]->AddVector(m_loc, type, name, index);
    }

    auto SetVector(unsigned index, unsigned vrt) -> float *
    {
        return m_loc[0]->SetVector(m_loc, index, vrt);
    }

    auto SetTriangle(unsigned tri) -> unsigned *
    {
        return m_loc[0]->SetTriangle(m_loc, tri);
    }

    auto FixNormals(void) -> unsigned *
    {
        return m_loc[0]->FixNormals(m_loc);
    }

    auto GetSize(unsigned *nvrt, unsigned *ntri) -> void
    {
        m_loc[0]->GetSize(m_loc, nvrt, ntri);
    }

    auto Triangles(void) -> unsigned *
    {
        return m_loc[0]->Triangles(m_loc);
    }

    auto VectorInfo(unsigned index, LXtID4 *type, const char **name, unsigned *dim) -> LxResult
    {
        return m_loc[0]->VectorInfo(m_loc, index, type, name, dim);
    }

    auto Vector(unsigned index) -> float *
    {
        return m_loc[0]->Vector(m_loc, index);
    }

    auto SetEdgeCount(unsigned nedge) -> LxResult
    {
        return m_loc[0]->SetEdgeCount(m_loc, nedge);
    }

    auto SetEdge(unsigned edge) -> unsigned *
    {
        return m_loc[0]->SetEdge(m_loc, edge);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_TriangleGroup : public CLxLocalize<ILxTriangleGroupID>
{
public:
    CLxLoc_TriangleGroup()
    {
        _init();
    }

    CLxLoc_TriangleGroup(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_TriangleGroup(CLxLoc_TriangleGroup const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_TriangleGroup;
    }

    auto AddSurface(void **ppvObj) -> LxResult
    {
        return m_loc[0]->AddSurface(m_loc, ppvObj);
    }

    auto AddSurface(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->AddSurface(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto GetSurface(unsigned index, void **ppvObj) -> LxResult
    {
        return m_loc[0]->GetSurface(m_loc, index, ppvObj);
    }

    auto GetSurface(unsigned index, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->GetSurface(m_loc, index, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Cleanup(void) -> LxResult
    {
        return m_loc[0]->Cleanup(m_loc);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};

