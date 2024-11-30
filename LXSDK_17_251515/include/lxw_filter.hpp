//
// C++ wrapper for lxsdk/lxfilter.h.
//
//	Copyright 2024.
//
//
#pragma once

#include <lxfilter.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx
{
    static LXtGUID const guid_EvaluationStack = {0x47F3BF05, {0xB64A, 0x49D9}, {0xA2, 0xC1, 0x08, 0xB0, 0xD3, 0x6A, 0xB7, 0x87}};
    static LXtGUID const guid_StackFilter = {0xD1A07939, {0xDB83, 0x4869}, {0x94, 0x27, 0xA7, 0x8D, 0x13, 0x4D, 0xA5, 0x75}};
    static LXtGUID const guid_StackFilter1 = {0xB79CF5D3, {0xC630, 0x401B}, {0x82, 0xA5, 0xAD, 0x86, 0x6B, 0xC0, 0x5B, 0x6F}};
    static LXtGUID const guid_CacheData = {0x7561D111, {0x72BD, 0x4C0C}, {0x9E, 0x2D, 0x92, 0x68, 0xA0, 0xEC, 0x30, 0xC2}};
    static LXtGUID const guid_CacheService = {0x6BB353D3, {0x179A, 0x477A}, {0xAC, 0x23, 0x94, 0x6D, 0xEC, 0xB4, 0x5A, 0x37}};
} // namespace lx

class CLxLoc_EvaluationStack : public CLxLocalize<ILxEvaluationStackID>
{
public:
    CLxLoc_EvaluationStack()
    {
        _init();
    }

    CLxLoc_EvaluationStack(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_EvaluationStack(CLxLoc_EvaluationStack const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_EvaluationStack;
    }

    auto Type(void) -> const char *
    {
        return m_loc[0]->Type(m_loc);
    }

    auto Branch(void **ppvObj) -> LxResult
    {
        return m_loc[0]->Branch(m_loc, ppvObj);
    }

    auto Branch(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Branch(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto AddFilter(ILxUnknownID filter) -> LxResult
    {
        return m_loc[0]->AddFilter(m_loc,(ILxUnknownID) filter);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_StackFilter
{
public:
    virtual ~CLxImpl_StackFilter() = default;

    virtual const char * filt_Type(void) = 0;

    virtual auto filt_Compare([[maybe_unused]] ILxUnknownID other) -> unsigned
    {
        return LXiSTACK_DIFFERENT;
    }

    virtual auto filt_Convert([[maybe_unused]] ILxUnknownID other) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto filt_Identifier([[maybe_unused]] const char **identifier) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_StackFilter_Type const char * filt_Type() override
#define LXxO_StackFilter_Type LXxD_StackFilter_Type
#define LXxC_StackFilter_Type(c) const char * c::filt_Type()
#define LXxD_StackFilter_Compare unsigned filt_Compare([[maybe_unused]] ILxUnknownID other) override
#define LXxO_StackFilter_Compare LXxD_StackFilter_Compare
#define LXxC_StackFilter_Compare(c) unsigned c::filt_Compare([[maybe_unused]] ILxUnknownID other)
#define LXxD_StackFilter_Convert LxResult filt_Convert([[maybe_unused]] ILxUnknownID other) override
#define LXxO_StackFilter_Convert LXxD_StackFilter_Convert
#define LXxC_StackFilter_Convert(c) LxResult c::filt_Convert([[maybe_unused]] ILxUnknownID other)
#define LXxD_StackFilter_Identifier LxResult filt_Identifier([[maybe_unused]] const char **identifier) override
#define LXxO_StackFilter_Identifier LXxD_StackFilter_Identifier
#define LXxC_StackFilter_Identifier(c) LxResult c::filt_Identifier([[maybe_unused]] const char **identifier)

template <class T>
class CLxIfc_StackFilter: public CLxInterface
{
public:
    CLxIfc_StackFilter()
    {
        vt.Type = Type;
        vt.Compare = Compare;
        vt.Convert = Convert;
        vt.Identifier = Identifier;
        vTable = &vt.iunk;
        iid = &lx::guid_StackFilter;
    }

    static auto Type(LXtObjectID wcom) -> const char *
    {
        LXCWxINST (CLxImpl_StackFilter, loc);
        return loc->filt_Type();
    }

    static auto Compare(LXtObjectID wcom,LXtObjectID other) -> unsigned
    {
        LXCWxINST (CLxImpl_StackFilter, loc);
        return loc->filt_Compare((ILxUnknownID) other);
    }

    static auto Convert(LXtObjectID wcom,LXtObjectID other) -> LxResult
    {
        LXCWxINST (CLxImpl_StackFilter, loc);
        try
        {
           return loc->filt_Convert((ILxUnknownID) other);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Identifier(LXtObjectID wcom,const char **identifier) -> LxResult
    {
        LXCWxINST (CLxImpl_StackFilter, loc);
        try
        {
           return loc->filt_Identifier( identifier);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxStackFilter vt;
};

class CLxLoc_StackFilter : public CLxLocalize<ILxStackFilterID>
{
public:
    CLxLoc_StackFilter()
    {
        _init();
    }

    CLxLoc_StackFilter(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_StackFilter(CLxLoc_StackFilter const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_StackFilter;
    }

    auto Type(void) -> const char *
    {
        return m_loc[0]->Type(m_loc);
    }

    auto Compare(ILxUnknownID other) -> unsigned
    {
        return m_loc[0]->Compare(m_loc,(ILxUnknownID) other);
    }

    auto Convert(ILxUnknownID other) -> LxResult
    {
        return m_loc[0]->Convert(m_loc,(ILxUnknownID) other);
    }

    auto Identifier(const char **identifier) -> LxResult
    {
        return m_loc[0]->Identifier(m_loc, identifier);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};

class CLxImpl_CacheData
{
public:
    virtual ~CLxImpl_CacheData() = default;

    virtual unsigned int cache_Size(void) = 0;
};

#define LXxD_CacheData_Size unsigned int cache_Size() override
#define LXxO_CacheData_Size LXxD_CacheData_Size
#define LXxC_CacheData_Size(c) unsigned int c::cache_Size()

template <class T>
class CLxIfc_CacheData: public CLxInterface
{
public:
    CLxIfc_CacheData()
    {
        vt.Size = Size;
        vTable = &vt.iunk;
        iid = &lx::guid_CacheData;
    }

    static auto Size(LXtObjectID wcom) -> unsigned int
    {
        LXCWxINST (CLxImpl_CacheData, loc);
        return loc->cache_Size();
    }

private:
    ILxCacheData vt;
};

class CLxLoc_CacheData : public CLxLocalize<ILxCacheDataID>
{
public:
    CLxLoc_CacheData()
    {
        _init();
    }

    CLxLoc_CacheData(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_CacheData(CLxLoc_CacheData const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_CacheData;
    }

    auto Size(void) -> unsigned int
    {
        return m_loc[0]->Size(m_loc);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_CacheService : public CLxLocalizedService
{
public:
    ILxCacheServiceID m_loc{ nullptr };

public:
    CLxLoc_CacheService()
    {
        _init();
        set();
    }

    ~CLxLoc_CacheService() = default;

    void set()
    {
        if (!m_loc)
        {
            m_loc = reinterpret_cast<ILxCacheServiceID>(lx::GetGlobal(&lx::guid_CacheService));
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

    auto Register(const char *name) -> LxResult
    {
        return m_loc[0]->Register(m_loc, name);
    }

    auto Release(const char *name) -> void
    {
        m_loc[0]->Release(m_loc, name);
    }

    auto GetData(const char *name, unsigned int key, void **ppvObj) -> LxResult
    {
        return m_loc[0]->GetData(m_loc, name, key, ppvObj);
    }

    auto GetData(const char *name, unsigned int key, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->GetData(m_loc, name, key, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto SetData(const char *name, unsigned int key, ILxUnknownID data) -> LxResult
    {
        return m_loc[0]->SetData(m_loc, name, key,(ILxUnknownID) data);
    }

    auto PurgeData(const char *name) -> void
    {
        m_loc[0]->PurgeData(m_loc, name);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
