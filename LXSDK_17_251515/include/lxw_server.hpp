//
// C++ wrapper for lxsdk/lxserver.h.
//
//	Copyright 2024.
//
//
#pragma once

#include <lxserver.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx
{
    static LXtGUID const guid_Factory = {0x2431A79E, {0x3412, 0x4B0D}, {0x98, 0x7D, 0x87, 0x54, 0x89, 0x46, 0x6C, 0x58}};
    static LXtGUID const guid_HostService = {0x525802A6, {0xBF5F, 0x46E9}, {0x98, 0x63, 0xC0, 0x3B, 0x54, 0xA3, 0xD9, 0x08}};
    static LXtGUID const guid_Module = {0x4DB9C543, {0xB192, 0x4EDD}, {0xA6, 0x5D, 0xDD, 0x01, 0x2F, 0xC2, 0x74, 0x16}};
    static LXtGUID const guid_TagDescription = {0x5582E0EE, {0xD682, 0x47BC}, {0xBF, 0x3D, 0xFB, 0x14, 0xD5, 0x99, 0x48, 0xC1}};
    static LXtGUID const guid_NeedContext = {0x7D30408C, {0x74AB, 0x4d87}, {0xB7, 0x1C, 0xC6, 0x28, 0x08, 0x83, 0x86, 0x3C}};
    static LXtGUID const guid_ServiceExtension = {0xE7C6F1A2, {0x2F31, 0x4FA5}, {0xB2, 0xEF, 0x42, 0x1B, 0xE1, 0x59, 0xD0, 0xD8}};
    static LXtGUID const guid_Module1 = {0xBD6F0E53, {0xC903, 0x46D3}, {0x92, 0x11, 0x75, 0x85, 0x58, 0xD9, 0x5C, 0xAA}};
} // namespace lx

class CLxImpl_Factory
{
public:
    virtual ~CLxImpl_Factory() = default;

    virtual auto fac_Name([[maybe_unused]] const char **name) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto fac_UserName([[maybe_unused]] const char **userName) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto fac_ClassGUID([[maybe_unused]] LXtGUID *guid) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto fac_Module([[maybe_unused]] const char **module) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto fac_InfoTag([[maybe_unused]] const char *type, [[maybe_unused]] const char **value) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto fac_TagCount([[maybe_unused]] unsigned int *count) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto fac_TagByIndex([[maybe_unused]] unsigned int index, [[maybe_unused]] const char **type, [[maybe_unused]] const char **value) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto fac_Spawn([[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_Factory_Name LxResult fac_Name([[maybe_unused]] const char **name) override
#define LXxO_Factory_Name LXxD_Factory_Name
#define LXxC_Factory_Name(c) LxResult c::fac_Name([[maybe_unused]] const char **name)
#define LXxD_Factory_UserName LxResult fac_UserName([[maybe_unused]] const char **userName) override
#define LXxO_Factory_UserName LXxD_Factory_UserName
#define LXxC_Factory_UserName(c) LxResult c::fac_UserName([[maybe_unused]] const char **userName)
#define LXxD_Factory_ClassGUID LxResult fac_ClassGUID([[maybe_unused]] LXtGUID *guid) override
#define LXxO_Factory_ClassGUID LXxD_Factory_ClassGUID
#define LXxC_Factory_ClassGUID(c) LxResult c::fac_ClassGUID([[maybe_unused]] LXtGUID *guid)
#define LXxD_Factory_Module LxResult fac_Module([[maybe_unused]] const char **module) override
#define LXxO_Factory_Module LXxD_Factory_Module
#define LXxC_Factory_Module(c) LxResult c::fac_Module([[maybe_unused]] const char **module)
#define LXxD_Factory_InfoTag LxResult fac_InfoTag([[maybe_unused]] const char *type, [[maybe_unused]] const char **value) override
#define LXxO_Factory_InfoTag LXxD_Factory_InfoTag
#define LXxC_Factory_InfoTag(c) LxResult c::fac_InfoTag([[maybe_unused]] const char *type, [[maybe_unused]] const char **value)
#define LXxD_Factory_TagCount LxResult fac_TagCount([[maybe_unused]] unsigned int *count) override
#define LXxO_Factory_TagCount LXxD_Factory_TagCount
#define LXxC_Factory_TagCount(c) LxResult c::fac_TagCount([[maybe_unused]] unsigned int *count)
#define LXxD_Factory_TagByIndex LxResult fac_TagByIndex([[maybe_unused]] unsigned int index, [[maybe_unused]] const char **type, [[maybe_unused]] const char **value) override
#define LXxO_Factory_TagByIndex LXxD_Factory_TagByIndex
#define LXxC_Factory_TagByIndex(c) LxResult c::fac_TagByIndex([[maybe_unused]] unsigned int index, [[maybe_unused]] const char **type, [[maybe_unused]] const char **value)
#define LXxD_Factory_Spawn LxResult fac_Spawn([[maybe_unused]] void **ppvObj) override
#define LXxO_Factory_Spawn LXxD_Factory_Spawn
#define LXxC_Factory_Spawn(c) LxResult c::fac_Spawn([[maybe_unused]] void **ppvObj)

template <class T>
class CLxIfc_Factory: public CLxInterface
{
public:
    CLxIfc_Factory()
    {
        vt.Name = Name;
        vt.UserName = UserName;
        vt.ClassGUID = ClassGUID;
        vt.Module = Module;
        vt.InfoTag = InfoTag;
        vt.TagCount = TagCount;
        vt.TagByIndex = TagByIndex;
        vt.Spawn = Spawn;
        vTable = &vt.iunk;
        iid = &lx::guid_Factory;
    }

    static auto Name(LXtObjectID wcom,const char **name) -> LxResult
    {
        LXCWxINST (CLxImpl_Factory, loc);
        try
        {
           return loc->fac_Name( name);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto UserName(LXtObjectID wcom,const char **userName) -> LxResult
    {
        LXCWxINST (CLxImpl_Factory, loc);
        try
        {
           return loc->fac_UserName( userName);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ClassGUID(LXtObjectID wcom,LXtGUID *guid) -> LxResult
    {
        LXCWxINST (CLxImpl_Factory, loc);
        try
        {
           return loc->fac_ClassGUID( guid);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Module(LXtObjectID wcom,const char **module) -> LxResult
    {
        LXCWxINST (CLxImpl_Factory, loc);
        try
        {
           return loc->fac_Module( module);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto InfoTag(LXtObjectID wcom,const char *type,const char **value) -> LxResult
    {
        LXCWxINST (CLxImpl_Factory, loc);
        try
        {
           return loc->fac_InfoTag( type, value);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto TagCount(LXtObjectID wcom,unsigned int *count) -> LxResult
    {
        LXCWxINST (CLxImpl_Factory, loc);
        try
        {
           return loc->fac_TagCount( count);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto TagByIndex(LXtObjectID wcom,unsigned int index,const char **type,const char **value) -> LxResult
    {
        LXCWxINST (CLxImpl_Factory, loc);
        try
        {
           return loc->fac_TagByIndex( index, type, value);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Spawn(LXtObjectID wcom,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_Factory, loc);
        try
        {
           return loc->fac_Spawn( ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxFactory vt;
};

class CLxLoc_Factory : public CLxLocalize<ILxFactoryID>
{
public:
    CLxLoc_Factory()
    {
        _init();
    }

    CLxLoc_Factory(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_Factory(CLxLoc_Factory const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_Factory;
    }

    auto Name(const char **name) -> LxResult
    {
        return m_loc[0]->Name(m_loc, name);
    }

    auto UserName(const char **userName) -> LxResult
    {
        return m_loc[0]->UserName(m_loc, userName);
    }

    auto ClassGUID(LXtGUID *guid) -> LxResult
    {
        return m_loc[0]->ClassGUID(m_loc, guid);
    }

    auto Module(const char **module) -> LxResult
    {
        return m_loc[0]->Module(m_loc, module);
    }

    auto InfoTag(const char *type, const char **value) -> LxResult
    {
        return m_loc[0]->InfoTag(m_loc, type, value);
    }

    auto TagCount(unsigned int *count) -> LxResult
    {
        return m_loc[0]->TagCount(m_loc, count);
    }

    auto TagByIndex(unsigned int index, const char **type, const char **value) -> LxResult
    {
        return m_loc[0]->TagByIndex(m_loc, index, type, value);
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

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_HostService : public CLxLocalizedService
{
public:
    ILxHostServiceID m_loc{ nullptr };

public:
    CLxLoc_HostService()
    {
        _init();
        set();
    }

    ~CLxLoc_HostService() = default;

    void set()
    {
        if (!m_loc)
        {
            m_loc = reinterpret_cast<ILxHostServiceID>(lx::GetGlobal(&lx::guid_HostService));
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

    auto LookupServer(const char *className, const char *name, unsigned allowLoad, void **ppvObj) -> LxResult
    {
        return m_loc[0]->LookupServer(m_loc, className, name, allowLoad, ppvObj);
    }

    auto LookupServer(const char *className, const char *name, unsigned allowLoad, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->LookupServer(m_loc, className, name, allowLoad, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto TestServer(const char *className, const char *name) -> LxResult
    {
        return m_loc[0]->TestServer(m_loc, className, name);
    }

    auto NumServers(const char *className) -> unsigned
    {
        return m_loc[0]->NumServers(m_loc, className);
    }

    auto ServerByIndex(const char *className, unsigned index, void **ppvObj) -> LxResult
    {
        return m_loc[0]->ServerByIndex(m_loc, className, index, ppvObj);
    }

    auto ServerByIndex(const char *className, unsigned index, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->ServerByIndex(m_loc, className, index, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto ServerGetIndex(const char *className, const char *name, unsigned *index) -> LxResult
    {
        return m_loc[0]->ServerGetIndex(m_loc, className, name, index);
    }

    auto AddServer(ILxUnknownID factory) -> LxResult
    {
        return m_loc[0]->AddServer(m_loc,(ILxUnknownID) factory);
    }

    auto DefaultPath(const char **path) -> LxResult
    {
        return m_loc[0]->DefaultPath(m_loc, path);
    }

    auto SpawnForTagsOnly(void) -> LxResult
    {
        return m_loc[0]->SpawnForTagsOnly(m_loc);
    }

    auto UpdateModule(const char *name) -> LxResult
    {
        return m_loc[0]->UpdateModule(m_loc, name);
    }

    auto SaverVerify(const char *format, ILxUnknownID object, ILxUnknownID msg) -> LxResult
    {
        return m_loc[0]->SaverVerify(m_loc, format,(ILxUnknownID) object,(ILxUnknownID) msg);
    }

    auto SaverSave(const char *filename, const char *format, ILxUnknownID object, ILxUnknownID monitor) -> LxResult
    {
        return m_loc[0]->SaverSave(m_loc, filename, format,(ILxUnknownID) object,(ILxUnknownID) monitor);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_Module
{
public:
    virtual ~CLxImpl_Module() = default;

    virtual auto mod_Generate([[maybe_unused]] const char *name, [[maybe_unused]] const LXtGUID *iid, [[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto mod_GetTags([[maybe_unused]] const char *name, [[maybe_unused]] const LXtGUID *iid, [[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_Module_Generate LxResult mod_Generate([[maybe_unused]] const char *name, [[maybe_unused]] const LXtGUID *iid, [[maybe_unused]] void **ppvObj) override
#define LXxO_Module_Generate LXxD_Module_Generate
#define LXxC_Module_Generate(c) LxResult c::mod_Generate([[maybe_unused]] const char *name, [[maybe_unused]] const LXtGUID *iid, [[maybe_unused]] void **ppvObj)
#define LXxD_Module_GetTags LxResult mod_GetTags([[maybe_unused]] const char *name, [[maybe_unused]] const LXtGUID *iid, [[maybe_unused]] void **ppvObj) override
#define LXxO_Module_GetTags LXxD_Module_GetTags
#define LXxC_Module_GetTags(c) LxResult c::mod_GetTags([[maybe_unused]] const char *name, [[maybe_unused]] const LXtGUID *iid, [[maybe_unused]] void **ppvObj)

template <class T>
class CLxIfc_Module: public CLxInterface
{
public:
    CLxIfc_Module()
    {
        vt.Generate = Generate;
        vt.GetTags = GetTags;
        vTable = &vt.iunk;
        iid = &lx::guid_Module;
    }

    static auto Generate(LXtObjectID wcom,const char *name,const LXtGUID *iid,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_Module, loc);
        try
        {
           return loc->mod_Generate( name, iid, ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto GetTags(LXtObjectID wcom,const char *name,const LXtGUID *iid,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_Module, loc);
        try
        {
           return loc->mod_GetTags( name, iid, ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxModule vt;
};

class CLxLoc_Module : public CLxLocalize<ILxModuleID>
{
public:
    CLxLoc_Module()
    {
        _init();
    }

    CLxLoc_Module(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_Module(CLxLoc_Module const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_Module;
    }

    auto Generate(const char *name, const LXtGUID *iid, void **ppvObj) -> LxResult
    {
        return m_loc[0]->Generate(m_loc, name, iid, ppvObj);
    }

    auto Generate(const char *name, const LXtGUID *iid, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Generate(m_loc, name, iid, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto GetTags(const char *name, const LXtGUID *iid, void **ppvObj) -> LxResult
    {
        return m_loc[0]->GetTags(m_loc, name, iid, ppvObj);
    }

    auto GetTags(const char *name, const LXtGUID *iid, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->GetTags(m_loc, name, iid, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_TagDescription
{
public:
    virtual ~CLxImpl_TagDescription() = default;

    virtual unsigned tag_Count(void) = 0;

    virtual auto tag_Describe([[maybe_unused]] unsigned index, [[maybe_unused]] LXtTagInfoDesc *desc) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_TagDescription_Count unsigned tag_Count() override
#define LXxO_TagDescription_Count LXxD_TagDescription_Count
#define LXxC_TagDescription_Count(c) unsigned c::tag_Count()
#define LXxD_TagDescription_Describe LxResult tag_Describe([[maybe_unused]] unsigned index, [[maybe_unused]] LXtTagInfoDesc *desc) override
#define LXxO_TagDescription_Describe LXxD_TagDescription_Describe
#define LXxC_TagDescription_Describe(c) LxResult c::tag_Describe([[maybe_unused]] unsigned index, [[maybe_unused]] LXtTagInfoDesc *desc)

template <class T>
class CLxIfc_TagDescription: public CLxInterface
{
public:
    CLxIfc_TagDescription()
    {
        vt.Count = Count;
        vt.Describe = Describe;
        vTable = &vt.iunk;
        iid = &lx::guid_TagDescription;
    }

    static auto Count(LXtObjectID wcom) -> unsigned
    {
        LXCWxINST (CLxImpl_TagDescription, loc);
        return loc->tag_Count();
    }

    static auto Describe(LXtObjectID wcom,unsigned index,LXtTagInfoDesc *desc) -> LxResult
    {
        LXCWxINST (CLxImpl_TagDescription, loc);
        try
        {
           return loc->tag_Describe( index, desc);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxTagDescription vt;
};

class CLxLoc_TagDescription : public CLxLocalize<ILxTagDescriptionID>
{
public:
    CLxLoc_TagDescription()
    {
        _init();
    }

    CLxLoc_TagDescription(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_TagDescription(CLxLoc_TagDescription const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_TagDescription;
    }

    auto Count(void) -> unsigned
    {
        return m_loc[0]->Count(m_loc);
    }

    auto Describe(unsigned index, LXtTagInfoDesc *desc) -> LxResult
    {
        return m_loc[0]->Describe(m_loc, index, desc);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_NeedContext
{
public:
    virtual ~CLxImpl_NeedContext() = default;

    virtual auto need_SetContext([[maybe_unused]] ILxUnknownID app) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_NeedContext_SetContext LxResult need_SetContext([[maybe_unused]] ILxUnknownID app) override
#define LXxO_NeedContext_SetContext LXxD_NeedContext_SetContext
#define LXxC_NeedContext_SetContext(c) LxResult c::need_SetContext([[maybe_unused]] ILxUnknownID app)

template <class T>
class CLxIfc_NeedContext: public CLxInterface
{
public:
    CLxIfc_NeedContext()
    {
        vt.SetContext = SetContext;
        vTable = &vt.iunk;
        iid = &lx::guid_NeedContext;
    }

    static auto SetContext(LXtObjectID wcom,LXtObjectID app) -> LxResult
    {
        LXCWxINST (CLxImpl_NeedContext, loc);
        try
        {
           return loc->need_SetContext((ILxUnknownID) app);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxNeedContext vt;
};

class CLxLoc_NeedContext : public CLxLocalize<ILxNeedContextID>
{
public:
    CLxLoc_NeedContext()
    {
        _init();
    }

    CLxLoc_NeedContext(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_NeedContext(CLxLoc_NeedContext const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_NeedContext;
    }

    auto SetContext(ILxUnknownID app) -> LxResult
    {
        return m_loc[0]->SetContext(m_loc,(ILxUnknownID) app);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_ServiceExtension
{
public:
    virtual ~CLxImpl_ServiceExtension() = default;

    virtual void ser_Dummy([[maybe_unused]] void)
    {
    }
};

#define LXxD_ServiceExtension_Dummy void ser_Dummy() override
#define LXxO_ServiceExtension_Dummy LXxD_ServiceExtension_Dummy
#define LXxC_ServiceExtension_Dummy(c) void c::ser_Dummy()

template <class T>
class CLxIfc_ServiceExtension: public CLxInterface
{
public:
    CLxIfc_ServiceExtension()
    {
        vt.Dummy = Dummy;
        vTable = &vt.iunk;
        iid = &lx::guid_ServiceExtension;
    }

    static auto Dummy(LXtObjectID wcom) -> void
    {
        LXCWxINST (CLxImpl_ServiceExtension, loc);
        loc->ser_Dummy();
    }

private:
    ILxServiceExtension vt;
};



