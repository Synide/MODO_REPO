//
// C++ wrapper for lxsdk/lxcolormapping.h.
//
//	Copyright 2024.
//
//
#pragma once

#include <lxcolormapping.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx
{
    static LXtGUID const guid_ColorMappingModule = {0x99D65C3D, {0xD394, 0x40E2}, {0xA7, 0x1A, 0xB1, 0x74, 0xE9, 0x71, 0xF4, 0x62}};
    static LXtGUID const guid_ColorMapping = {0x49B0319A, {0xBBAA, 0x4D43}, {0x84, 0x47, 0x63, 0x1B, 0xE7, 0x29, 0x7F, 0xBB}};
    static LXtGUID const guid_ColorMapping1 = {0x40D65C4F, {0xD394, 0x40E2}, {0xA7, 0x1A, 0xB1, 0x74, 0xE9, 0x71, 0xF4, 0x62}};
    static LXtGUID const guid_ColorMappingService = {0xc3e44fbc, {0x45c6, 0x47b5}, {0xaa, 0xee, 0xf0, 0xcc, 0x00, 0x2d, 0xd4, 0x74}};
} // namespace lx

class CLxImpl_ColorMappingModule
{
public:
    virtual ~CLxImpl_ColorMappingModule() = default;

    virtual unsigned cmapmod_Flags(void) = 0;
};

#define LXxD_ColorMappingModule_Flags unsigned cmapmod_Flags() override
#define LXxO_ColorMappingModule_Flags LXxD_ColorMappingModule_Flags
#define LXxC_ColorMappingModule_Flags(c) unsigned c::cmapmod_Flags()

template <class T>
class CLxIfc_ColorMappingModule: public CLxInterface
{
public:
    CLxIfc_ColorMappingModule()
    {
        vt.Flags = Flags;
        vTable = &vt.iunk;
        iid = &lx::guid_ColorMappingModule;
    }

    static auto Flags(LXtObjectID wcom) -> unsigned
    {
        LXCWxINST (CLxImpl_ColorMappingModule, loc);
        return loc->cmapmod_Flags();
    }

private:
    ILxColorMappingModule vt;
};

class CLxLoc_ColorMappingModule : public CLxLocalize<ILxColorMappingModuleID>
{
public:
    CLxLoc_ColorMappingModule()
    {
        _init();
    }

    CLxLoc_ColorMappingModule(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_ColorMappingModule(CLxLoc_ColorMappingModule const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_ColorMappingModule;
    }

    auto Flags(void) -> unsigned
    {
        return m_loc[0]->Flags(m_loc);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_ColorMapping
{
public:
    virtual ~CLxImpl_ColorMapping() = default;

    virtual auto cmap_Setup([[maybe_unused]] int toLinear) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmap_ToLinear([[maybe_unused]] const LXtFVector sourceValues, [[maybe_unused]] LXtFVector linearValues, [[maybe_unused]] unsigned int length) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmap_FromLinear([[maybe_unused]] const LXtFVector linearValues, [[maybe_unused]] LXtFVector targetValues, [[maybe_unused]] unsigned int length) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmap_ToLinearFast([[maybe_unused]] float* buf, [[maybe_unused]] unsigned int length) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmap_FromLinearFast([[maybe_unused]] float* buf, [[maybe_unused]] unsigned int length) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmap_GetLUTImage([[maybe_unused]] float **ptr) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmap_GetShaderSource([[maybe_unused]] char **ptr) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual const char* cmap_GetName(void) = 0;

    virtual const char* cmap_GetCMServerName(void) = 0;

    virtual unsigned char* cmap_GenerateICCProfile(unsigned int* length) = 0;

    virtual const char* cmap_GetConfigName(void) = 0;
};

#define LXxD_ColorMapping_Setup LxResult cmap_Setup([[maybe_unused]] int toLinear) override
#define LXxO_ColorMapping_Setup LXxD_ColorMapping_Setup
#define LXxC_ColorMapping_Setup(c) LxResult c::cmap_Setup([[maybe_unused]] int toLinear)
#define LXxD_ColorMapping_ToLinear LxResult cmap_ToLinear([[maybe_unused]] const LXtFVector sourceValues, [[maybe_unused]] LXtFVector linearValues, [[maybe_unused]] unsigned int length) override
#define LXxO_ColorMapping_ToLinear LXxD_ColorMapping_ToLinear
#define LXxC_ColorMapping_ToLinear(c) LxResult c::cmap_ToLinear([[maybe_unused]] const LXtFVector sourceValues, [[maybe_unused]] LXtFVector linearValues, [[maybe_unused]] unsigned int length)
#define LXxD_ColorMapping_FromLinear LxResult cmap_FromLinear([[maybe_unused]] const LXtFVector linearValues, [[maybe_unused]] LXtFVector targetValues, [[maybe_unused]] unsigned int length) override
#define LXxO_ColorMapping_FromLinear LXxD_ColorMapping_FromLinear
#define LXxC_ColorMapping_FromLinear(c) LxResult c::cmap_FromLinear([[maybe_unused]] const LXtFVector linearValues, [[maybe_unused]] LXtFVector targetValues, [[maybe_unused]] unsigned int length)
#define LXxD_ColorMapping_ToLinearFast LxResult cmap_ToLinearFast([[maybe_unused]] float* buf, [[maybe_unused]] unsigned int length) override
#define LXxO_ColorMapping_ToLinearFast LXxD_ColorMapping_ToLinearFast
#define LXxC_ColorMapping_ToLinearFast(c) LxResult c::cmap_ToLinearFast([[maybe_unused]] float* buf, [[maybe_unused]] unsigned int length)
#define LXxD_ColorMapping_FromLinearFast LxResult cmap_FromLinearFast([[maybe_unused]] float* buf, [[maybe_unused]] unsigned int length) override
#define LXxO_ColorMapping_FromLinearFast LXxD_ColorMapping_FromLinearFast
#define LXxC_ColorMapping_FromLinearFast(c) LxResult c::cmap_FromLinearFast([[maybe_unused]] float* buf, [[maybe_unused]] unsigned int length)
#define LXxD_ColorMapping_GetLUTImage LxResult cmap_GetLUTImage([[maybe_unused]] float **ptr) override
#define LXxO_ColorMapping_GetLUTImage LXxD_ColorMapping_GetLUTImage
#define LXxC_ColorMapping_GetLUTImage(c) LxResult c::cmap_GetLUTImage([[maybe_unused]] float **ptr)
#define LXxD_ColorMapping_GetShaderSource LxResult cmap_GetShaderSource([[maybe_unused]] char **ptr) override
#define LXxO_ColorMapping_GetShaderSource LXxD_ColorMapping_GetShaderSource
#define LXxC_ColorMapping_GetShaderSource(c) LxResult c::cmap_GetShaderSource([[maybe_unused]] char **ptr)
#define LXxD_ColorMapping_GetName const char* cmap_GetName() override
#define LXxO_ColorMapping_GetName LXxD_ColorMapping_GetName
#define LXxC_ColorMapping_GetName(c) const char* c::cmap_GetName()
#define LXxD_ColorMapping_GetCMServerName const char* cmap_GetCMServerName() override
#define LXxO_ColorMapping_GetCMServerName LXxD_ColorMapping_GetCMServerName
#define LXxC_ColorMapping_GetCMServerName(c) const char* c::cmap_GetCMServerName()
#define LXxD_ColorMapping_GenerateICCProfile unsigned char* cmap_GenerateICCProfile([[maybe_unused]] unsigned int* length) override
#define LXxO_ColorMapping_GenerateICCProfile LXxD_ColorMapping_GenerateICCProfile
#define LXxC_ColorMapping_GenerateICCProfile(c) unsigned char* c::cmap_GenerateICCProfile([[maybe_unused]] unsigned int* length)
#define LXxD_ColorMapping_GetConfigName const char* cmap_GetConfigName() override
#define LXxO_ColorMapping_GetConfigName LXxD_ColorMapping_GetConfigName
#define LXxC_ColorMapping_GetConfigName(c) const char* c::cmap_GetConfigName()

template <class T>
class CLxIfc_ColorMapping: public CLxInterface
{
public:
    CLxIfc_ColorMapping()
    {
        vt.Setup = Setup;
        vt.ToLinear = ToLinear;
        vt.FromLinear = FromLinear;
        vt.ToLinearFast = ToLinearFast;
        vt.FromLinearFast = FromLinearFast;
        vt.GetLUTImage = GetLUTImage;
        vt.GetShaderSource = GetShaderSource;
        vt.GetName = GetName;
        vt.GetCMServerName = GetCMServerName;
        vt.GenerateICCProfile = GenerateICCProfile;
        vt.GetConfigName = GetConfigName;
        vTable = &vt.iunk;
        iid = &lx::guid_ColorMapping;
    }

    static auto Setup(LXtObjectID wcom,int toLinear) -> LxResult
    {
        LXCWxINST (CLxImpl_ColorMapping, loc);
        try
        {
           return loc->cmap_Setup( toLinear);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ToLinear(LXtObjectID wcom,const LXtFVector sourceValues,LXtFVector linearValues,unsigned int length) -> LxResult
    {
        LXCWxINST (CLxImpl_ColorMapping, loc);
        try
        {
           return loc->cmap_ToLinear( sourceValues, linearValues, length);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto FromLinear(LXtObjectID wcom,const LXtFVector linearValues,LXtFVector targetValues,unsigned int length) -> LxResult
    {
        LXCWxINST (CLxImpl_ColorMapping, loc);
        try
        {
           return loc->cmap_FromLinear( linearValues, targetValues, length);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ToLinearFast(LXtObjectID wcom,float* buf,unsigned int length) -> LxResult
    {
        LXCWxINST (CLxImpl_ColorMapping, loc);
        try
        {
           return loc->cmap_ToLinearFast( buf, length);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto FromLinearFast(LXtObjectID wcom,float* buf,unsigned int length) -> LxResult
    {
        LXCWxINST (CLxImpl_ColorMapping, loc);
        try
        {
           return loc->cmap_FromLinearFast( buf, length);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto GetLUTImage(LXtObjectID wcom,float **ptr) -> LxResult
    {
        LXCWxINST (CLxImpl_ColorMapping, loc);
        try
        {
           return loc->cmap_GetLUTImage( ptr);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto GetShaderSource(LXtObjectID wcom,char **ptr) -> LxResult
    {
        LXCWxINST (CLxImpl_ColorMapping, loc);
        try
        {
           return loc->cmap_GetShaderSource( ptr);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto GetName(LXtObjectID wcom) -> const char*
    {
        LXCWxINST (CLxImpl_ColorMapping, loc);
        return loc->cmap_GetName();
    }

    static auto GetCMServerName(LXtObjectID wcom) -> const char*
    {
        LXCWxINST (CLxImpl_ColorMapping, loc);
        return loc->cmap_GetCMServerName();
    }

    static auto GenerateICCProfile(LXtObjectID wcom,unsigned int* length) -> unsigned char*
    {
        LXCWxINST (CLxImpl_ColorMapping, loc);
        return loc->cmap_GenerateICCProfile( length);
    }

    static auto GetConfigName(LXtObjectID wcom) -> const char*
    {
        LXCWxINST (CLxImpl_ColorMapping, loc);
        return loc->cmap_GetConfigName();
    }

private:
    ILxColorMapping vt;
};

class CLxLoc_ColorMapping : public CLxLocalize<ILxColorMappingID>
{
public:
    CLxLoc_ColorMapping()
    {
        _init();
    }

    CLxLoc_ColorMapping(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_ColorMapping(CLxLoc_ColorMapping const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_ColorMapping;
    }

    auto Setup(int toLinear) -> LxResult
    {
        return m_loc[0]->Setup(m_loc, toLinear);
    }

    auto ToLinear(const LXtFVector sourceValues, LXtFVector linearValues, unsigned int length) -> LxResult
    {
        return m_loc[0]->ToLinear(m_loc, sourceValues, linearValues, length);
    }

    auto FromLinear(const LXtFVector linearValues, LXtFVector targetValues, unsigned int length) -> LxResult
    {
        return m_loc[0]->FromLinear(m_loc, linearValues, targetValues, length);
    }

    auto ToLinearFast(float* buf, unsigned int length) -> LxResult
    {
        return m_loc[0]->ToLinearFast(m_loc, buf, length);
    }

    auto FromLinearFast(float* buf, unsigned int length) -> LxResult
    {
        return m_loc[0]->FromLinearFast(m_loc, buf, length);
    }

    auto GetLUTImage(float **ptr) -> LxResult
    {
        return m_loc[0]->GetLUTImage(m_loc, ptr);
    }

    auto GetShaderSource(char **ptr) -> LxResult
    {
        return m_loc[0]->GetShaderSource(m_loc, ptr);
    }

    auto GetName(void) -> const char*
    {
        return m_loc[0]->GetName(m_loc);
    }

    auto GetCMServerName(void) -> const char*
    {
        return m_loc[0]->GetCMServerName(m_loc);
    }

    auto GenerateICCProfile(unsigned int* length) -> unsigned char*
    {
        return m_loc[0]->GenerateICCProfile(m_loc, length);
    }

    auto GetConfigName(void) -> const char*
    {
        return m_loc[0]->GetConfigName(m_loc);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_ColorMapping1
{
public:
    virtual ~CLxImpl_ColorMapping1() = default;

    virtual auto cmap_Setup([[maybe_unused]] int toLinear) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmap_ToLinear([[maybe_unused]] const LXtFVector sourceValues, [[maybe_unused]] LXtFVector linearValues, [[maybe_unused]] unsigned int length) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmap_FromLinear([[maybe_unused]] const LXtFVector linearValues, [[maybe_unused]] LXtFVector targetValues, [[maybe_unused]] unsigned int length) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmap_ToLinearFast([[maybe_unused]] float* buf, [[maybe_unused]] unsigned int length) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmap_FromLinearFast([[maybe_unused]] float* buf, [[maybe_unused]] unsigned int length) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmap_GetLUTImage([[maybe_unused]] float **ptr) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmap_GetShaderSource([[maybe_unused]] char **ptr) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual const char* cmap_GetName(void) = 0;
};

#define LXxD_ColorMapping1_Setup LxResult cmap_Setup([[maybe_unused]] int toLinear) override
#define LXxO_ColorMapping1_Setup LXxD_ColorMapping1_Setup
#define LXxC_ColorMapping1_Setup(c) LxResult c::cmap_Setup([[maybe_unused]] int toLinear)
#define LXxD_ColorMapping1_ToLinear LxResult cmap_ToLinear([[maybe_unused]] const LXtFVector sourceValues, [[maybe_unused]] LXtFVector linearValues, [[maybe_unused]] unsigned int length) override
#define LXxO_ColorMapping1_ToLinear LXxD_ColorMapping1_ToLinear
#define LXxC_ColorMapping1_ToLinear(c) LxResult c::cmap_ToLinear([[maybe_unused]] const LXtFVector sourceValues, [[maybe_unused]] LXtFVector linearValues, [[maybe_unused]] unsigned int length)
#define LXxD_ColorMapping1_FromLinear LxResult cmap_FromLinear([[maybe_unused]] const LXtFVector linearValues, [[maybe_unused]] LXtFVector targetValues, [[maybe_unused]] unsigned int length) override
#define LXxO_ColorMapping1_FromLinear LXxD_ColorMapping1_FromLinear
#define LXxC_ColorMapping1_FromLinear(c) LxResult c::cmap_FromLinear([[maybe_unused]] const LXtFVector linearValues, [[maybe_unused]] LXtFVector targetValues, [[maybe_unused]] unsigned int length)
#define LXxD_ColorMapping1_ToLinearFast LxResult cmap_ToLinearFast([[maybe_unused]] float* buf, [[maybe_unused]] unsigned int length) override
#define LXxO_ColorMapping1_ToLinearFast LXxD_ColorMapping1_ToLinearFast
#define LXxC_ColorMapping1_ToLinearFast(c) LxResult c::cmap_ToLinearFast([[maybe_unused]] float* buf, [[maybe_unused]] unsigned int length)
#define LXxD_ColorMapping1_FromLinearFast LxResult cmap_FromLinearFast([[maybe_unused]] float* buf, [[maybe_unused]] unsigned int length) override
#define LXxO_ColorMapping1_FromLinearFast LXxD_ColorMapping1_FromLinearFast
#define LXxC_ColorMapping1_FromLinearFast(c) LxResult c::cmap_FromLinearFast([[maybe_unused]] float* buf, [[maybe_unused]] unsigned int length)
#define LXxD_ColorMapping1_GetLUTImage LxResult cmap_GetLUTImage([[maybe_unused]] float **ptr) override
#define LXxO_ColorMapping1_GetLUTImage LXxD_ColorMapping1_GetLUTImage
#define LXxC_ColorMapping1_GetLUTImage(c) LxResult c::cmap_GetLUTImage([[maybe_unused]] float **ptr)
#define LXxD_ColorMapping1_GetShaderSource LxResult cmap_GetShaderSource([[maybe_unused]] char **ptr) override
#define LXxO_ColorMapping1_GetShaderSource LXxD_ColorMapping1_GetShaderSource
#define LXxC_ColorMapping1_GetShaderSource(c) LxResult c::cmap_GetShaderSource([[maybe_unused]] char **ptr)
#define LXxD_ColorMapping1_GetName const char* cmap_GetName() override
#define LXxO_ColorMapping1_GetName LXxD_ColorMapping1_GetName
#define LXxC_ColorMapping1_GetName(c) const char* c::cmap_GetName()

template <class T>
class CLxIfc_ColorMapping1: public CLxInterface
{
public:
    CLxIfc_ColorMapping1()
    {
        vt.Setup = Setup;
        vt.ToLinear = ToLinear;
        vt.FromLinear = FromLinear;
        vt.ToLinearFast = ToLinearFast;
        vt.FromLinearFast = FromLinearFast;
        vt.GetLUTImage = GetLUTImage;
        vt.GetShaderSource = GetShaderSource;
        vt.GetName = GetName;
        vTable = &vt.iunk;
        iid = &lx::guid_ColorMapping1;
    }

    static auto Setup(LXtObjectID wcom,int toLinear) -> LxResult
    {
        LXCWxINST (CLxImpl_ColorMapping1, loc);
        try
        {
           return loc->cmap_Setup( toLinear);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ToLinear(LXtObjectID wcom,const LXtFVector sourceValues,LXtFVector linearValues,unsigned int length) -> LxResult
    {
        LXCWxINST (CLxImpl_ColorMapping1, loc);
        try
        {
           return loc->cmap_ToLinear( sourceValues, linearValues, length);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto FromLinear(LXtObjectID wcom,const LXtFVector linearValues,LXtFVector targetValues,unsigned int length) -> LxResult
    {
        LXCWxINST (CLxImpl_ColorMapping1, loc);
        try
        {
           return loc->cmap_FromLinear( linearValues, targetValues, length);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ToLinearFast(LXtObjectID wcom,float* buf,unsigned int length) -> LxResult
    {
        LXCWxINST (CLxImpl_ColorMapping1, loc);
        try
        {
           return loc->cmap_ToLinearFast( buf, length);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto FromLinearFast(LXtObjectID wcom,float* buf,unsigned int length) -> LxResult
    {
        LXCWxINST (CLxImpl_ColorMapping1, loc);
        try
        {
           return loc->cmap_FromLinearFast( buf, length);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto GetLUTImage(LXtObjectID wcom,float **ptr) -> LxResult
    {
        LXCWxINST (CLxImpl_ColorMapping1, loc);
        try
        {
           return loc->cmap_GetLUTImage( ptr);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto GetShaderSource(LXtObjectID wcom,char **ptr) -> LxResult
    {
        LXCWxINST (CLxImpl_ColorMapping1, loc);
        try
        {
           return loc->cmap_GetShaderSource( ptr);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto GetName(LXtObjectID wcom) -> const char*
    {
        LXCWxINST (CLxImpl_ColorMapping1, loc);
        return loc->cmap_GetName();
    }

private:
    ILxColorMapping1 vt;
};

class CLxLoc_ColorMapping1 : public CLxLocalize<ILxColorMapping1ID>
{
public:
    CLxLoc_ColorMapping1()
    {
        _init();
    }

    CLxLoc_ColorMapping1(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_ColorMapping1(CLxLoc_ColorMapping1 const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_ColorMapping1;
    }

    auto Setup(int toLinear) -> LxResult
    {
        return m_loc[0]->Setup(m_loc, toLinear);
    }

    auto ToLinear(const LXtFVector sourceValues, LXtFVector linearValues, unsigned int length) -> LxResult
    {
        return m_loc[0]->ToLinear(m_loc, sourceValues, linearValues, length);
    }

    auto FromLinear(const LXtFVector linearValues, LXtFVector targetValues, unsigned int length) -> LxResult
    {
        return m_loc[0]->FromLinear(m_loc, linearValues, targetValues, length);
    }

    auto ToLinearFast(float* buf, unsigned int length) -> LxResult
    {
        return m_loc[0]->ToLinearFast(m_loc, buf, length);
    }

    auto FromLinearFast(float* buf, unsigned int length) -> LxResult
    {
        return m_loc[0]->FromLinearFast(m_loc, buf, length);
    }

    auto GetLUTImage(float **ptr) -> LxResult
    {
        return m_loc[0]->GetLUTImage(m_loc, ptr);
    }

    auto GetShaderSource(char **ptr) -> LxResult
    {
        return m_loc[0]->GetShaderSource(m_loc, ptr);
    }

    auto GetName(void) -> const char*
    {
        return m_loc[0]->GetName(m_loc);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_ColorMappingService : public CLxLocalizedService
{
public:
    ILxColorMappingServiceID m_loc{ nullptr };

public:
    CLxLoc_ColorMappingService()
    {
        _init();
        set();
    }

    ~CLxLoc_ColorMappingService() = default;

    void set()
    {
        if (!m_loc)
        {
            m_loc = reinterpret_cast<ILxColorMappingServiceID>(lx::GetGlobal(&lx::guid_ColorMappingService));
        }
    }

    auto MakeColorMapping(const char *colorspaceName, int toLinear, void **ppvObj) -> LxResult
    {
        return m_loc[0]->MakeColorMapping(m_loc, colorspaceName, toLinear, ppvObj);
    }

    auto MakeColorMapping(const char *colorspaceName, int toLinear, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->MakeColorMapping(m_loc, colorspaceName, toLinear, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto ConfigCount(void) -> int
    {
        return m_loc[0]->ConfigCount(m_loc);
    }

    auto ConfigName(int index, const char **configName) -> LxResult
    {
        return m_loc[0]->ConfigName(m_loc, index, configName);
    }

    auto ConfigFullPath(int index, const char **configPath) -> LxResult
    {
        return m_loc[0]->ConfigFullPath(m_loc, index, configPath);
    }

    auto RegisterColorspaceForConfig(const char *configName, const char *colorspaceName) -> LxResult
    {
        return m_loc[0]->RegisterColorspaceForConfig(m_loc, configName, colorspaceName);
    }

    auto GetDisplayColorMapping(void **ppvObj) -> LxResult
    {
        return m_loc[0]->GetDisplayColorMapping(m_loc, ppvObj);
    }

    auto GetDisplayColorMapping(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->GetDisplayColorMapping(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto GetNumericColorMapping(void **ppvObj) -> LxResult
    {
        return m_loc[0]->GetNumericColorMapping(m_loc, ppvObj);
    }

    auto GetNumericColorMapping(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->GetNumericColorMapping(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto ColorspaceCount(const char *configName) -> int
    {
        return m_loc[0]->ColorspaceCount(m_loc, configName);
    }

    auto ColorspaceNameByIndex(const char *configName, int index, std::string& colorspaceName) -> LxResult
    {
        return m_loc[0]->ColorspaceNameByIndex(m_loc, configName, index, colorspaceName);
    }

    auto ColorspaceIndexByName(const char *configName, const char *colorspaceName, int& index) -> LxResult
    {
        return m_loc[0]->ColorspaceIndexByName(m_loc, configName, colorspaceName, index);
    }

    auto ColorspaceNameCombByIndex(const char *configName, int index, std::string& colorspaceCombName) -> LxResult
    {
        return m_loc[0]->ColorspaceNameCombByIndex(m_loc, configName, index, colorspaceCombName);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
