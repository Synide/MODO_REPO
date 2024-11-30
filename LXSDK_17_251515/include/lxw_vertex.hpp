//
// C++ wrapper for lxsdk/lxvertex.h.
//
//	Copyright 2024.
//
//
#pragma once

#include <lxvertex.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx
{
    static LXtGUID const guid_TableauVertex = {0xF90A0A39, {0xEE2A, 0x4D11}, {0x91, 0x2B, 0x93, 0x38, 0xEF, 0x27, 0x1D, 0xFF}};
    static LXtGUID const guid_VertexFeatureService = {0xB40D51A9, {0x6C04, 0x46D1}, {0xBA, 0x8A, 0x0F, 0xE9, 0xB3, 0x2E, 0xAC, 0x3C}};
} // namespace lx

class CLxLoc_TableauVertex : public CLxLocalize<ILxTableauVertexID>
{
public:
    CLxLoc_TableauVertex()
    {
        _init();
    }

    CLxLoc_TableauVertex(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_TableauVertex(CLxLoc_TableauVertex const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_TableauVertex;
    }

    auto AddFeature(LXtID4 type, const char *name, unsigned int *index) -> LxResult
    {
        return m_loc[0]->AddFeature(m_loc, type, name, index);
    }

    auto Lookup(LXtID4 type, const char *name, unsigned int *offset) -> LxResult
    {
        return m_loc[0]->Lookup(m_loc, type, name, offset);
    }

    auto Size(void) -> unsigned int
    {
        return m_loc[0]->Size(m_loc);
    }

    auto Count(void) -> unsigned int
    {
        return m_loc[0]->Count(m_loc);
    }

    auto ByIndex(unsigned int index, LXtID4 *type, const char **name, unsigned int *offset) -> LxResult
    {
        return m_loc[0]->ByIndex(m_loc, index, type, name, offset);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_VertexFeatureService : public CLxLocalizedService
{
public:
    ILxVertexFeatureServiceID m_loc{ nullptr };

public:
    CLxLoc_VertexFeatureService()
    {
        _init();
        set();
    }

    ~CLxLoc_VertexFeatureService() = default;

    void set()
    {
        if (!m_loc)
        {
            m_loc = reinterpret_cast<ILxVertexFeatureServiceID>(lx::GetGlobal(&lx::guid_VertexFeatureService));
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

    auto AllocVertex(void **ppvObj) -> LxResult
    {
        return m_loc[0]->AllocVertex(m_loc, ppvObj);
    }

    auto AllocVertex(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->AllocVertex(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Lookup(LXtID4 type, const char *name, const char **ident) -> LxResult
    {
        return m_loc[0]->Lookup(m_loc, type, name, ident);
    }

    auto Type(const char *ident, LXtID4 *type) -> LxResult
    {
        return m_loc[0]->Type(m_loc, ident, type);
    }

    auto Name(const char *ident, const char **name) -> LxResult
    {
        return m_loc[0]->Name(m_loc, ident, name);
    }

    auto Dimension(const char *ident, unsigned *dimension) -> LxResult
    {
        return m_loc[0]->Dimension(m_loc, ident, dimension);
    }

    auto VectorType(const char *ident, const char **vecType) -> LxResult
    {
        return m_loc[0]->VectorType(m_loc, ident, vecType);
    }

    auto DataType(const char *ident, const char **typeName) -> LxResult
    {
        return m_loc[0]->DataType(m_loc, ident, typeName);
    }

    auto TestCategory(const char *ident, const char *category) -> LxResult
    {
        return m_loc[0]->TestCategory(m_loc, ident, category);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
