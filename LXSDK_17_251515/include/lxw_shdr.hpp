//
// C++ wrapper for lxsdk/lxshdr.h.
//
//	Copyright 2024.
//
//
#pragma once

#include <lxshdr.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx
{
    static LXtGUID const guid_ShaderService = {0x0b4e73ac, {0x9325, 0x4920}, {0xaf, 0xcc, 0x78, 0x14, 0x95, 0x3a, 0x26, 0xb6}};
    static LXtGUID const guid_Shader = {0x051ba6d8, {0x46ba, 0x4722}, {0x8b, 0x07, 0x94, 0x39, 0x61, 0xc3, 0xae, 0xda}};
} // namespace lx

class CLxLoc_ShaderService : public CLxLocalizedService
{
public:
    ILxShaderServiceID m_loc{ nullptr };

public:
    CLxLoc_ShaderService()
    {
        _init();
        set();
    }

    ~CLxLoc_ShaderService() = default;

    void set()
    {
        if (!m_loc)
        {
            m_loc = reinterpret_cast<ILxShaderServiceID>(lx::GetGlobal(&lx::guid_ShaderService));
        }
    }

    auto ComputeFresnel(const LXtFVector inRay, const LXtFVector normalRay, float normReflAmt) const -> float
    {
        return m_loc[0]->ComputeFresnel(m_loc, inRay, normalRay, normReflAmt);
    }

    auto ScalarBlendValue(float v1, float v2, float opa, int mode) -> float
    {
        return m_loc[0]->ScalarBlendValue(m_loc, v1, v2, opa, mode);
    }

    auto ColorBlendValue(LXtFVector c, const LXtFVector c1, const LXtFVector c2, float opa, int mode) -> void
    {
        m_loc[0]->ColorBlendValue(m_loc, c, c1, c2, opa, mode);
    }

    auto SquareToCircle(float *x, float *y) const -> void
    {
        m_loc[0]->SquareToCircle(m_loc, x, y);
    }

    auto SampleCloud(ILxUnknownID sample, void **ppvObj) const -> LxResult
    {
        return m_loc[0]->SampleCloud(m_loc,(ILxUnknownID) sample, ppvObj);
    }

    auto SampleCloud(ILxUnknownID sample, CLxLocalizedObject &o_dest) const -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->SampleCloud(m_loc,(ILxUnknownID) sample, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto MeshShaderAccessor(ILxUnknownID meshItem, void **ppvObj) -> LxResult
    {
        return m_loc[0]->MeshShaderAccessor(m_loc,(ILxUnknownID) meshItem, ppvObj);
    }

    auto MeshShaderAccessor(ILxUnknownID meshItem, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->MeshShaderAccessor(m_loc,(ILxUnknownID) meshItem, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto PolyShaderAccessor(ILxUnknownID meshItem, LXtPolygonID polyID, void **ppvObj) -> LxResult
    {
        return m_loc[0]->PolyShaderAccessor(m_loc,(ILxUnknownID) meshItem, polyID, ppvObj);
    }

    auto PolyShaderAccessor(ILxUnknownID meshItem, LXtPolygonID polyID, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->PolyShaderAccessor(m_loc,(ILxUnknownID) meshItem, polyID, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto RussianRoulette(ILxUnknownID vector, float importance) const -> float
    {
        return m_loc[0]->RussianRoulette(m_loc,(ILxUnknownID) vector, importance);
    }

    auto NextRandom(ILxUnknownID vector) const -> float
    {
        return m_loc[0]->NextRandom(m_loc,(ILxUnknownID) vector);
    }

    auto PoissonOffset(ILxUnknownID vector, float *u, float *v) const -> LxResult
    {
        return m_loc[0]->PoissonOffset(m_loc,(ILxUnknownID) vector, u, v);
    }

    auto CollectMaterials(ILxUnknownID collection) -> LxResult
    {
        return m_loc[0]->CollectMaterials(m_loc,(ILxUnknownID) collection);
    }

    auto MeshMaskAccessor(ILxUnknownID meshItem, void **ppvObj) -> LxResult
    {
        return m_loc[0]->MeshMaskAccessor(m_loc,(ILxUnknownID) meshItem, ppvObj);
    }

    auto MeshMaskAccessor(ILxUnknownID meshItem, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->MeshMaskAccessor(m_loc,(ILxUnknownID) meshItem, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto CollectMaskedItems(ILxUnknownID collection) -> LxResult
    {
        return m_loc[0]->CollectMaskedItems(m_loc,(ILxUnknownID) collection);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_Shader : public CLxLocalize<ILxShaderID>
{
public:
    CLxLoc_Shader()
    {
        _init();
    }

    CLxLoc_Shader(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_Shader(CLxLoc_Shader const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_Shader;
    }

    auto Enumerate(ILxUnknownID visitor) -> LxResult
    {
        return m_loc[0]->Enumerate(m_loc,(ILxUnknownID) visitor);
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

    auto ShaderItemGet(void **ppvObj) -> LxResult
    {
        return m_loc[0]->ShaderItemGet(m_loc, ppvObj);
    }

    auto ShaderItemGet(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->ShaderItemGet(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
