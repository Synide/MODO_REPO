//
// C++ wrapper for lxsdk/lxscripts.h.
//
//	Copyright 2024.
//
//
#pragma once

#include <lxscripts.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx
{
    static LXtGUID const guid_ScriptSysService = {0x5046C663, {0x7990, 0x44d5}, {0x84, 0xCB, 0xA8, 0x59, 0x10, 0x1B, 0x1C, 0x59}};
    static LXtGUID const guid_UserValue = {0xd7fb1eb0, {0x47fe, 0x4dc2}, {0xa6, 0x4f, 0xc8, 0xa3, 0x5a, 0x86, 0xc5, 0x1e}};
    static LXtGUID const guid_Kit = {0x6A961CA0, {0x6174, 0x4E65}, {0xBB, 0x13, 0xAC, 0x19, 0x9D, 0xD1, 0x04, 0x71}};
    static LXtGUID const guid_SessionListener = {0xb5cb3afe, {0x3f0c, 0x4498}, {0xb5, 0x30, 0x17, 0x26, 0x81, 0x1b, 0x14, 0x01}};
    static LXtGUID const guid_UserValueListener = {0x13a85a48, {0x06aa, 0x4a75}, {0x9e, 0x73, 0x06, 0x6e, 0xe3, 0xcb, 0x76, 0x1f}};
    static LXtGUID const guid_ScriptManager = {0x3699E7C5, {0x44B8, 0x4e07}, {0xB8, 0xCA, 0xE2, 0x68, 0x99, 0xCD, 0x7B, 0x3B}};
    static LXtGUID const guid_TextScriptInterpreter = {0xD612FFCE, {0x4B94, 0x4823}, {0xA0, 0xA7, 0xCC, 0x7C, 0xA2, 0xDD, 0xC3, 0xD6}};
    static LXtGUID const guid_Script = {0x33C03F3F, {0xA692, 0x4bf4}, {0x8A, 0xB4, 0xC5, 0xA9, 0x5C, 0xA7, 0x93, 0x0C}};
    static LXtGUID const guid_PlatformService = {0xB9596D64, {0x8CB3, 0x4943}, {0x84, 0x15, 0x7E, 0xDF, 0x52, 0x7A, 0xE5, 0x13}};
    static LXtGUID const guid_AppActiveListener = {0x7c35c2c0, {0x8116, 0x43f7}, {0x82, 0x77, 0xdd, 0x52, 0x1d, 0x1b, 0xd6, 0xa8}};
    static LXtGUID const guid_LineInterpreter = {0x8F7DF2BE, {0x69A2, 0x4E1C}, {0xA4, 0xE9, 0xCB, 0x3B, 0xC3, 0xD5, 0x34, 0xD5}};
    static LXtGUID const guid_LineExecution = {0x16947735, {0x3797, 0x444C}, {0xA9, 0x07, 0xDA, 0xDD, 0x81, 0x65, 0xF4, 0xFB}};
    static LXtGUID const guid_ScriptLineEvent = {0xDABF6619, {0xA4B5, 0x4919}, {0x83, 0x89, 0x8C, 0x54, 0xB3, 0x94, 0x22, 0xE4}};
} // namespace lx

class CLxLoc_ScriptSysService : public CLxLocalizedService
{
public:
    ILxScriptSysServiceID m_loc{ nullptr };

public:
    CLxLoc_ScriptSysService()
    {
        _init();
        set();
    }

    ~CLxLoc_ScriptSysService() = default;

    void set()
    {
        if (!m_loc)
        {
            m_loc = reinterpret_cast<ILxScriptSysServiceID>(lx::GetGlobal(&lx::guid_ScriptSysService));
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

    auto Count(unsigned int *count) -> LxResult
    {
        return m_loc[0]->Count(m_loc, count);
    }

    auto ByIndex(unsigned int index, void **ppvObj) -> LxResult
    {
        return m_loc[0]->ByIndex(m_loc, index, ppvObj);
    }

    auto ByIndex(unsigned int index, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->ByIndex(m_loc, index, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto NameByIndex(unsigned int index, const char **name) -> LxResult
    {
        return m_loc[0]->NameByIndex(m_loc, index, name);
    }

    auto Lookup(const char *name, void **ppvObj) -> LxResult
    {
        return m_loc[0]->Lookup(m_loc, name, ppvObj);
    }

    auto Lookup(const char *name, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Lookup(m_loc, name, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto UserName(ILxUnknownID manager, const char **name) -> LxResult
    {
        return m_loc[0]->UserName(m_loc,(ILxUnknownID) manager, name);
    }

    auto Desc(ILxUnknownID manager, const char **name) -> LxResult
    {
        return m_loc[0]->Desc(m_loc,(ILxUnknownID) manager, name);
    }

    auto UserValueCount(int *count) -> LxResult
    {
        return m_loc[0]->UserValueCount(m_loc, count);
    }

    auto UserValueByIndex(int index, void **ppvObj) -> LxResult
    {
        return m_loc[0]->UserValueByIndex(m_loc, index, ppvObj);
    }

    auto UserValueByIndex(int index, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->UserValueByIndex(m_loc, index, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto UserValueLookup(const char *name, void **ppvObj) -> LxResult
    {
        return m_loc[0]->UserValueLookup(m_loc, name, ppvObj);
    }

    auto UserValueLookup(const char *name, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->UserValueLookup(m_loc, name, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto ResolveAlias(const char *alias, const char **path) -> LxResult
    {
        return m_loc[0]->ResolveAlias(m_loc, alias, path);
    }

    auto LookupScript(const char *hash, int write, int tryAsUsername, void **service, void **script) -> LxResult
    {
        return m_loc[0]->LookupScript(m_loc, hash, write, tryAsUsername, service, script);
    }

    auto KitCount(int visible, int *count) -> LxResult
    {
        return m_loc[0]->KitCount(m_loc, visible, count);
    }

    auto KitByIndex(int index, int visible, void **ppvObj) -> LxResult
    {
        return m_loc[0]->KitByIndex(m_loc, index, visible, ppvObj);
    }

    auto KitByIndex(int index, int visible, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->KitByIndex(m_loc, index, visible, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto KitLookup(const char *name, void **ppvObj) -> LxResult
    {
        return m_loc[0]->KitLookup(m_loc, name, ppvObj);
    }

    auto KitLookup(const char *name, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->KitLookup(m_loc, name, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_UserValue : public CLxLocalize<ILxUserValueID>
{
public:
    CLxLoc_UserValue()
    {
        _init();
    }

    CLxLoc_UserValue(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_UserValue(CLxLoc_UserValue const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_UserValue;
    }

    auto Name(const char **name) -> LxResult
    {
        return m_loc[0]->Name(m_loc, name);
    }

    auto UserName(const char **username) -> LxResult
    {
        return m_loc[0]->UserName(m_loc, username);
    }

    auto Type(int *type) -> LxResult
    {
        return m_loc[0]->Type(m_loc, type);
    }

    auto TypeName(const char **tname) -> LxResult
    {
        return m_loc[0]->TypeName(m_loc, tname);
    }

    auto IsTransient(int *isTransient) -> LxResult
    {
        return m_loc[0]->IsTransient(m_loc, isTransient);
    }

    auto GetInt(int *val) -> LxResult
    {
        return m_loc[0]->GetInt(m_loc, val);
    }

    auto GetFlt(double *val) -> LxResult
    {
        return m_loc[0]->GetFlt(m_loc, val);
    }

    auto GetString(char *buf, unsigned len) -> LxResult
    {
        return m_loc[0]->GetString(m_loc, buf, len);
    }

    auto GetString(std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->GetString(m_loc, buf, len);
        LXWx_SBUF2
    }

    auto Lifespan(int *life) -> LxResult
    {
        return m_loc[0]->Lifespan(m_loc, life);
    }

    auto FloatRange(int *hasMin, double *min, int *hasMax, double *max) -> LxResult
    {
        return m_loc[0]->FloatRange(m_loc, hasMin, min, hasMax, max);
    }

    auto IntRange(int *hasMin, int *min, int *hasMax, int *max) -> LxResult
    {
        return m_loc[0]->IntRange(m_loc, hasMin, min, hasMax, max);
    }

    auto List(const char **list) -> LxResult
    {
        return m_loc[0]->List(m_loc, list);
    }

    auto ListNames(const char **listNames) -> LxResult
    {
        return m_loc[0]->ListNames(m_loc, listNames);
    }

    auto ArgType(const char **argType) -> LxResult
    {
        return m_loc[0]->ArgType(m_loc, argType);
    }

    auto Action(const char **action) -> LxResult
    {
        return m_loc[0]->Action(m_loc, action);
    }

    auto DeferAction(void) -> LxResult
    {
        return m_loc[0]->DeferAction(m_loc);
    }

    auto DialogUserName(const char **username) -> LxResult
    {
        return m_loc[0]->DialogUserName(m_loc, username);
    }

    auto ValuePresetCookie(const char **cookie) -> LxResult
    {
        return m_loc[0]->ValuePresetCookie(m_loc, cookie);
    }

    auto EnableCommand(const char **command) -> LxResult
    {
        return m_loc[0]->EnableCommand(m_loc, command);
    }

    auto Notifier(const char **notifier) -> LxResult
    {
        return m_loc[0]->Notifier(m_loc, notifier);
    }

    auto DefaultValue(void **ppvObj) -> LxResult
    {
        return m_loc[0]->DefaultValue(m_loc, ppvObj);
    }

    auto DefaultValue(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->DefaultValue(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto AsUI(void) -> LxResult
    {
        return m_loc[0]->AsUI(m_loc);
    }

    auto InvertEnableCommandTest(void) -> LxResult
    {
        return m_loc[0]->InvertEnableCommandTest(m_loc);
    }

    auto UIMode(int *uiMode) -> LxResult
    {
        return m_loc[0]->UIMode(m_loc, uiMode);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_Kit : public CLxLocalize<ILxKitID>
{
public:
    CLxLoc_Kit()
    {
        _init();
    }

    CLxLoc_Kit(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_Kit(CLxLoc_Kit const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_Kit;
    }

    auto Name(const char **name) -> LxResult
    {
        return m_loc[0]->Name(m_loc, name);
    }

    auto Version(const char **version) -> LxResult
    {
        return m_loc[0]->Version(m_loc, version);
    }

    auto IsEnabled(void) -> LxResult
    {
        return m_loc[0]->IsEnabled(m_loc);
    }

    auto SetEnabled(int enabled) -> void
    {
        m_loc[0]->SetEnabled(m_loc, enabled);
    }

    auto IsVisible(void) -> LxResult
    {
        return m_loc[0]->IsVisible(m_loc);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_SessionListener
{
public:
    virtual ~CLxImpl_SessionListener() = default;

    virtual auto sesl_FirstWindowOpening([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto sesl_BeforeStartupCommands([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto sesl_SystemReady([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto sesl_CheckQuitUI([[maybe_unused]] int quitWasAborted) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto sesl_QuittingUI([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto sesl_LastWindowClosed([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto sesl_ShuttingDown([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_SessionListener_FirstWindowOpening LxResult sesl_FirstWindowOpening() override
#define LXxO_SessionListener_FirstWindowOpening LXxD_SessionListener_FirstWindowOpening
#define LXxC_SessionListener_FirstWindowOpening(c) LxResult c::sesl_FirstWindowOpening()
#define LXxD_SessionListener_BeforeStartupCommands LxResult sesl_BeforeStartupCommands() override
#define LXxO_SessionListener_BeforeStartupCommands LXxD_SessionListener_BeforeStartupCommands
#define LXxC_SessionListener_BeforeStartupCommands(c) LxResult c::sesl_BeforeStartupCommands()
#define LXxD_SessionListener_SystemReady LxResult sesl_SystemReady() override
#define LXxO_SessionListener_SystemReady LXxD_SessionListener_SystemReady
#define LXxC_SessionListener_SystemReady(c) LxResult c::sesl_SystemReady()
#define LXxD_SessionListener_CheckQuitUI LxResult sesl_CheckQuitUI([[maybe_unused]] int quitWasAborted) override
#define LXxO_SessionListener_CheckQuitUI LXxD_SessionListener_CheckQuitUI
#define LXxC_SessionListener_CheckQuitUI(c) LxResult c::sesl_CheckQuitUI([[maybe_unused]] int quitWasAborted)
#define LXxD_SessionListener_QuittingUI LxResult sesl_QuittingUI() override
#define LXxO_SessionListener_QuittingUI LXxD_SessionListener_QuittingUI
#define LXxC_SessionListener_QuittingUI(c) LxResult c::sesl_QuittingUI()
#define LXxD_SessionListener_LastWindowClosed LxResult sesl_LastWindowClosed() override
#define LXxO_SessionListener_LastWindowClosed LXxD_SessionListener_LastWindowClosed
#define LXxC_SessionListener_LastWindowClosed(c) LxResult c::sesl_LastWindowClosed()
#define LXxD_SessionListener_ShuttingDown LxResult sesl_ShuttingDown() override
#define LXxO_SessionListener_ShuttingDown LXxD_SessionListener_ShuttingDown
#define LXxC_SessionListener_ShuttingDown(c) LxResult c::sesl_ShuttingDown()

template <class T>
class CLxIfc_SessionListener: public CLxInterface
{
public:
    CLxIfc_SessionListener()
    {
        vt.FirstWindowOpening = FirstWindowOpening;
        vt.BeforeStartupCommands = BeforeStartupCommands;
        vt.SystemReady = SystemReady;
        vt.CheckQuitUI = CheckQuitUI;
        vt.QuittingUI = QuittingUI;
        vt.LastWindowClosed = LastWindowClosed;
        vt.ShuttingDown = ShuttingDown;
        vTable = &vt.iunk;
        iid = &lx::guid_SessionListener;
    }

    static auto FirstWindowOpening(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_SessionListener, loc);
        try
        {
           return loc->sesl_FirstWindowOpening();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto BeforeStartupCommands(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_SessionListener, loc);
        try
        {
           return loc->sesl_BeforeStartupCommands();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SystemReady(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_SessionListener, loc);
        try
        {
           return loc->sesl_SystemReady();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto CheckQuitUI(LXtObjectID wcom,int quitWasAborted) -> LxResult
    {
        LXCWxINST (CLxImpl_SessionListener, loc);
        try
        {
           return loc->sesl_CheckQuitUI( quitWasAborted);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto QuittingUI(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_SessionListener, loc);
        try
        {
           return loc->sesl_QuittingUI();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto LastWindowClosed(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_SessionListener, loc);
        try
        {
           return loc->sesl_LastWindowClosed();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ShuttingDown(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_SessionListener, loc);
        try
        {
           return loc->sesl_ShuttingDown();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxSessionListener vt;
};

class CLxLoc_SessionListener : public CLxLocalize<ILxSessionListenerID>
{
public:
    CLxLoc_SessionListener()
    {
        _init();
    }

    CLxLoc_SessionListener(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_SessionListener(CLxLoc_SessionListener const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_SessionListener;
    }

    auto FirstWindowOpening(void) -> LxResult
    {
        return m_loc[0]->FirstWindowOpening(m_loc);
    }

    auto BeforeStartupCommands(void) -> LxResult
    {
        return m_loc[0]->BeforeStartupCommands(m_loc);
    }

    auto SystemReady(void) -> LxResult
    {
        return m_loc[0]->SystemReady(m_loc);
    }

    auto CheckQuitUI(int quitWasAborted) -> LxResult
    {
        return m_loc[0]->CheckQuitUI(m_loc, quitWasAborted);
    }

    auto QuittingUI(void) -> LxResult
    {
        return m_loc[0]->QuittingUI(m_loc);
    }

    auto LastWindowClosed(void) -> LxResult
    {
        return m_loc[0]->LastWindowClosed(m_loc);
    }

    auto ShuttingDown(void) -> LxResult
    {
        return m_loc[0]->ShuttingDown(m_loc);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_UserValueListener
{
public:
    virtual ~CLxImpl_UserValueListener() = default;

    virtual auto uvl_Added([[maybe_unused]] ILxUnknownID userValue) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto uvl_Deleted([[maybe_unused]] const char *name) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto uvl_DefChanged([[maybe_unused]] ILxUnknownID userValue) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto uvl_ValueChanged([[maybe_unused]] ILxUnknownID userValue) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_UserValueListener_Added LxResult uvl_Added([[maybe_unused]] ILxUnknownID userValue) override
#define LXxO_UserValueListener_Added LXxD_UserValueListener_Added
#define LXxC_UserValueListener_Added(c) LxResult c::uvl_Added([[maybe_unused]] ILxUnknownID userValue)
#define LXxD_UserValueListener_Deleted LxResult uvl_Deleted([[maybe_unused]] const char *name) override
#define LXxO_UserValueListener_Deleted LXxD_UserValueListener_Deleted
#define LXxC_UserValueListener_Deleted(c) LxResult c::uvl_Deleted([[maybe_unused]] const char *name)
#define LXxD_UserValueListener_DefChanged LxResult uvl_DefChanged([[maybe_unused]] ILxUnknownID userValue) override
#define LXxO_UserValueListener_DefChanged LXxD_UserValueListener_DefChanged
#define LXxC_UserValueListener_DefChanged(c) LxResult c::uvl_DefChanged([[maybe_unused]] ILxUnknownID userValue)
#define LXxD_UserValueListener_ValueChanged LxResult uvl_ValueChanged([[maybe_unused]] ILxUnknownID userValue) override
#define LXxO_UserValueListener_ValueChanged LXxD_UserValueListener_ValueChanged
#define LXxC_UserValueListener_ValueChanged(c) LxResult c::uvl_ValueChanged([[maybe_unused]] ILxUnknownID userValue)

template <class T>
class CLxIfc_UserValueListener: public CLxInterface
{
public:
    CLxIfc_UserValueListener()
    {
        vt.Added = Added;
        vt.Deleted = Deleted;
        vt.DefChanged = DefChanged;
        vt.ValueChanged = ValueChanged;
        vTable = &vt.iunk;
        iid = &lx::guid_UserValueListener;
    }

    static auto Added(LXtObjectID wcom,LXtObjectID userValue) -> LxResult
    {
        LXCWxINST (CLxImpl_UserValueListener, loc);
        try
        {
           return loc->uvl_Added((ILxUnknownID) userValue);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Deleted(LXtObjectID wcom,const char *name) -> LxResult
    {
        LXCWxINST (CLxImpl_UserValueListener, loc);
        try
        {
           return loc->uvl_Deleted( name);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto DefChanged(LXtObjectID wcom,LXtObjectID userValue) -> LxResult
    {
        LXCWxINST (CLxImpl_UserValueListener, loc);
        try
        {
           return loc->uvl_DefChanged((ILxUnknownID) userValue);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ValueChanged(LXtObjectID wcom,LXtObjectID userValue) -> LxResult
    {
        LXCWxINST (CLxImpl_UserValueListener, loc);
        try
        {
           return loc->uvl_ValueChanged((ILxUnknownID) userValue);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxUserValueListener vt;
};

class CLxLoc_UserValueListener : public CLxLocalize<ILxUserValueListenerID>
{
public:
    CLxLoc_UserValueListener()
    {
        _init();
    }

    CLxLoc_UserValueListener(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_UserValueListener(CLxLoc_UserValueListener const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_UserValueListener;
    }

    auto Added(ILxUnknownID userValue) -> LxResult
    {
        return m_loc[0]->Added(m_loc,(ILxUnknownID) userValue);
    }

    auto Deleted(const char *name) -> LxResult
    {
        return m_loc[0]->Deleted(m_loc, name);
    }

    auto DefChanged(ILxUnknownID userValue) -> LxResult
    {
        return m_loc[0]->DefChanged(m_loc,(ILxUnknownID) userValue);
    }

    auto ValueChanged(ILxUnknownID userValue) -> LxResult
    {
        return m_loc[0]->ValueChanged(m_loc,(ILxUnknownID) userValue);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_ScriptManager
{
public:
    virtual ~CLxImpl_ScriptManager() = default;

    virtual auto scman_Name([[maybe_unused]] const char **name) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto scman_Flags([[maybe_unused]] int *flags) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto scman_Count([[maybe_unused]] unsigned int *count) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto scman_ByIndex([[maybe_unused]] unsigned int index, [[maybe_unused]] void **ppvObj, [[maybe_unused]] int write) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto scman_Lookup([[maybe_unused]] const char *hash, [[maybe_unused]] void **ppvObj, [[maybe_unused]] int write, [[maybe_unused]] int tryAsUserName) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto scman_ReadWrite([[maybe_unused]] const char *hash, [[maybe_unused]] int index) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto scman_New([[maybe_unused]] const char *name, [[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto scman_Remove([[maybe_unused]] ILxUnknownID script) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto scman_Validate([[maybe_unused]] ILxUnknownID script, [[maybe_unused]] ILxUnknownID msg) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto scman_Run([[maybe_unused]] ILxUnknownID script, [[maybe_unused]] int execFlags, [[maybe_unused]] const char *args, [[maybe_unused]] ILxUnknownID msg) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_ScriptManager_Name LxResult scman_Name([[maybe_unused]] const char **name) override
#define LXxO_ScriptManager_Name LXxD_ScriptManager_Name
#define LXxC_ScriptManager_Name(c) LxResult c::scman_Name([[maybe_unused]] const char **name)
#define LXxD_ScriptManager_Flags LxResult scman_Flags([[maybe_unused]] int *flags) override
#define LXxO_ScriptManager_Flags LXxD_ScriptManager_Flags
#define LXxC_ScriptManager_Flags(c) LxResult c::scman_Flags([[maybe_unused]] int *flags)
#define LXxD_ScriptManager_Count LxResult scman_Count([[maybe_unused]] unsigned int *count) override
#define LXxO_ScriptManager_Count LXxD_ScriptManager_Count
#define LXxC_ScriptManager_Count(c) LxResult c::scman_Count([[maybe_unused]] unsigned int *count)
#define LXxD_ScriptManager_ByIndex LxResult scman_ByIndex([[maybe_unused]] unsigned int index, [[maybe_unused]] void **ppvObj, [[maybe_unused]] int write) override
#define LXxO_ScriptManager_ByIndex LXxD_ScriptManager_ByIndex
#define LXxC_ScriptManager_ByIndex(c) LxResult c::scman_ByIndex([[maybe_unused]] unsigned int index, [[maybe_unused]] void **ppvObj, [[maybe_unused]] int write)
#define LXxD_ScriptManager_Lookup LxResult scman_Lookup([[maybe_unused]] const char *hash, [[maybe_unused]] void **ppvObj, [[maybe_unused]] int write, [[maybe_unused]] int tryAsUserName) override
#define LXxO_ScriptManager_Lookup LXxD_ScriptManager_Lookup
#define LXxC_ScriptManager_Lookup(c) LxResult c::scman_Lookup([[maybe_unused]] const char *hash, [[maybe_unused]] void **ppvObj, [[maybe_unused]] int write, [[maybe_unused]] int tryAsUserName)
#define LXxD_ScriptManager_ReadWrite LxResult scman_ReadWrite([[maybe_unused]] const char *hash, [[maybe_unused]] int index) override
#define LXxO_ScriptManager_ReadWrite LXxD_ScriptManager_ReadWrite
#define LXxC_ScriptManager_ReadWrite(c) LxResult c::scman_ReadWrite([[maybe_unused]] const char *hash, [[maybe_unused]] int index)
#define LXxD_ScriptManager_New LxResult scman_New([[maybe_unused]] const char *name, [[maybe_unused]] void **ppvObj) override
#define LXxO_ScriptManager_New LXxD_ScriptManager_New
#define LXxC_ScriptManager_New(c) LxResult c::scman_New([[maybe_unused]] const char *name, [[maybe_unused]] void **ppvObj)
#define LXxD_ScriptManager_Remove LxResult scman_Remove([[maybe_unused]] ILxUnknownID script) override
#define LXxO_ScriptManager_Remove LXxD_ScriptManager_Remove
#define LXxC_ScriptManager_Remove(c) LxResult c::scman_Remove([[maybe_unused]] ILxUnknownID script)
#define LXxD_ScriptManager_Validate LxResult scman_Validate([[maybe_unused]] ILxUnknownID script, [[maybe_unused]] ILxUnknownID msg) override
#define LXxO_ScriptManager_Validate LXxD_ScriptManager_Validate
#define LXxC_ScriptManager_Validate(c) LxResult c::scman_Validate([[maybe_unused]] ILxUnknownID script, [[maybe_unused]] ILxUnknownID msg)
#define LXxD_ScriptManager_Run LxResult scman_Run([[maybe_unused]] ILxUnknownID script, [[maybe_unused]] int execFlags, [[maybe_unused]] const char *args, [[maybe_unused]] ILxUnknownID msg) override
#define LXxO_ScriptManager_Run LXxD_ScriptManager_Run
#define LXxC_ScriptManager_Run(c) LxResult c::scman_Run([[maybe_unused]] ILxUnknownID script, [[maybe_unused]] int execFlags, [[maybe_unused]] const char *args, [[maybe_unused]] ILxUnknownID msg)

template <class T>
class CLxIfc_ScriptManager: public CLxInterface
{
public:
    CLxIfc_ScriptManager()
    {
        vt.Name = Name;
        vt.Flags = Flags;
        vt.Count = Count;
        vt.ByIndex = ByIndex;
        vt.Lookup = Lookup;
        vt.ReadWrite = ReadWrite;
        vt.New = New;
        vt.Remove = Remove;
        vt.Validate = Validate;
        vt.Run = Run;
        vTable = &vt.iunk;
        iid = &lx::guid_ScriptManager;
    }

    static auto Name(LXtObjectID wcom,const char **name) -> LxResult
    {
        LXCWxINST (CLxImpl_ScriptManager, loc);
        try
        {
           return loc->scman_Name( name);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Flags(LXtObjectID wcom,int *flags) -> LxResult
    {
        LXCWxINST (CLxImpl_ScriptManager, loc);
        try
        {
           return loc->scman_Flags( flags);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Count(LXtObjectID wcom,unsigned int *count) -> LxResult
    {
        LXCWxINST (CLxImpl_ScriptManager, loc);
        try
        {
           return loc->scman_Count( count);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ByIndex(LXtObjectID wcom,unsigned int index,void **ppvObj,int write) -> LxResult
    {
        LXCWxINST (CLxImpl_ScriptManager, loc);
        try
        {
           return loc->scman_ByIndex( index, ppvObj, write);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Lookup(LXtObjectID wcom,const char *hash,void **ppvObj,int write,int tryAsUserName) -> LxResult
    {
        LXCWxINST (CLxImpl_ScriptManager, loc);
        try
        {
           return loc->scman_Lookup( hash, ppvObj, write, tryAsUserName);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ReadWrite(LXtObjectID wcom,const char *hash,int index) -> LxResult
    {
        LXCWxINST (CLxImpl_ScriptManager, loc);
        try
        {
           return loc->scman_ReadWrite( hash, index);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto New(LXtObjectID wcom,const char *name,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_ScriptManager, loc);
        try
        {
           return loc->scman_New( name, ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Remove(LXtObjectID wcom,LXtObjectID script) -> LxResult
    {
        LXCWxINST (CLxImpl_ScriptManager, loc);
        try
        {
           return loc->scman_Remove((ILxUnknownID) script);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Validate(LXtObjectID wcom,LXtObjectID script,LXtObjectID msg) -> LxResult
    {
        LXCWxINST (CLxImpl_ScriptManager, loc);
        try
        {
           return loc->scman_Validate((ILxUnknownID) script,(ILxUnknownID) msg);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Run(LXtObjectID wcom,LXtObjectID script,int execFlags,const char *args,LXtObjectID msg) -> LxResult
    {
        LXCWxINST (CLxImpl_ScriptManager, loc);
        try
        {
           return loc->scman_Run((ILxUnknownID) script, execFlags, args,(ILxUnknownID) msg);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxScriptManager vt;
};

class CLxLoc_ScriptManager : public CLxLocalize<ILxScriptManagerID>
{
public:
    CLxLoc_ScriptManager()
    {
        _init();
    }

    CLxLoc_ScriptManager(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_ScriptManager(CLxLoc_ScriptManager const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_ScriptManager;
    }

    auto Name(const char **name) -> LxResult
    {
        return m_loc[0]->Name(m_loc, name);
    }

    auto Flags(int *flags) -> LxResult
    {
        return m_loc[0]->Flags(m_loc, flags);
    }

    auto Count(unsigned int *count) -> LxResult
    {
        return m_loc[0]->Count(m_loc, count);
    }

    auto ByIndex(unsigned int index, void **ppvObj, int write) -> LxResult
    {
        return m_loc[0]->ByIndex(m_loc, index, ppvObj, write);
    }

    auto ByIndex(unsigned int index, CLxLocalizedObject &o_dest, int write) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->ByIndex(m_loc, index, &o_obj, write);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Lookup(const char *hash, void **ppvObj, int write, int tryAsUserName) -> LxResult
    {
        return m_loc[0]->Lookup(m_loc, hash, ppvObj, write, tryAsUserName);
    }

    auto Lookup(const char *hash, CLxLocalizedObject &o_dest, int write, int tryAsUserName) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Lookup(m_loc, hash, &o_obj, write, tryAsUserName);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto ReadWrite(const char *hash, int index) -> LxResult
    {
        return m_loc[0]->ReadWrite(m_loc, hash, index);
    }

    auto New(const char *name, void **ppvObj) -> LxResult
    {
        return m_loc[0]->New(m_loc, name, ppvObj);
    }

    auto New(const char *name, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->New(m_loc, name, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Remove(ILxUnknownID script) -> LxResult
    {
        return m_loc[0]->Remove(m_loc,(ILxUnknownID) script);
    }

    auto Validate(ILxUnknownID script, ILxUnknownID msg) -> LxResult
    {
        return m_loc[0]->Validate(m_loc,(ILxUnknownID) script,(ILxUnknownID) msg);
    }

    auto Run(ILxUnknownID script, int execFlags, const char *args, ILxUnknownID msg) -> LxResult
    {
        return m_loc[0]->Run(m_loc,(ILxUnknownID) script, execFlags, args,(ILxUnknownID) msg);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_TextScriptInterpreter
{
public:
    virtual ~CLxImpl_TextScriptInterpreter() = default;

    virtual auto tsi_ValidateFileType([[maybe_unused]] ILxUnknownID script, [[maybe_unused]] const char *firstLine) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto tsi_Validate([[maybe_unused]] ILxUnknownID script, [[maybe_unused]] ILxUnknownID msg) -> LxResult
    {
        return LXe_OK;
    }

    virtual auto tsi_Run([[maybe_unused]] ILxUnknownID script, [[maybe_unused]] int execFlags, [[maybe_unused]] const char *args, [[maybe_unused]] ILxUnknownID msg) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_TextScriptInterpreter_ValidateFileType LxResult tsi_ValidateFileType([[maybe_unused]] ILxUnknownID script, [[maybe_unused]] const char *firstLine) override
#define LXxO_TextScriptInterpreter_ValidateFileType LXxD_TextScriptInterpreter_ValidateFileType
#define LXxC_TextScriptInterpreter_ValidateFileType(c) LxResult c::tsi_ValidateFileType([[maybe_unused]] ILxUnknownID script, [[maybe_unused]] const char *firstLine)
#define LXxD_TextScriptInterpreter_Validate LxResult tsi_Validate([[maybe_unused]] ILxUnknownID script, [[maybe_unused]] ILxUnknownID msg) override
#define LXxO_TextScriptInterpreter_Validate LXxD_TextScriptInterpreter_Validate
#define LXxC_TextScriptInterpreter_Validate(c) LxResult c::tsi_Validate([[maybe_unused]] ILxUnknownID script, [[maybe_unused]] ILxUnknownID msg)
#define LXxD_TextScriptInterpreter_Run LxResult tsi_Run([[maybe_unused]] ILxUnknownID script, [[maybe_unused]] int execFlags, [[maybe_unused]] const char *args, [[maybe_unused]] ILxUnknownID msg) override
#define LXxO_TextScriptInterpreter_Run LXxD_TextScriptInterpreter_Run
#define LXxC_TextScriptInterpreter_Run(c) LxResult c::tsi_Run([[maybe_unused]] ILxUnknownID script, [[maybe_unused]] int execFlags, [[maybe_unused]] const char *args, [[maybe_unused]] ILxUnknownID msg)

template <class T>
class CLxIfc_TextScriptInterpreter: public CLxInterface
{
public:
    CLxIfc_TextScriptInterpreter()
    {
        vt.ValidateFileType = ValidateFileType;
        vt.Validate = Validate;
        vt.Run = Run;
        vTable = &vt.iunk;
        iid = &lx::guid_TextScriptInterpreter;
    }

    static auto ValidateFileType(LXtObjectID wcom,LXtObjectID script,const char *firstLine) -> LxResult
    {
        LXCWxINST (CLxImpl_TextScriptInterpreter, loc);
        try
        {
           return loc->tsi_ValidateFileType((ILxUnknownID) script, firstLine);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Validate(LXtObjectID wcom,LXtObjectID script,LXtObjectID msg) -> LxResult
    {
        LXCWxINST (CLxImpl_TextScriptInterpreter, loc);
        try
        {
           return loc->tsi_Validate((ILxUnknownID) script,(ILxUnknownID) msg);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Run(LXtObjectID wcom,LXtObjectID script,int execFlags,const char *args,LXtObjectID msg) -> LxResult
    {
        LXCWxINST (CLxImpl_TextScriptInterpreter, loc);
        try
        {
           return loc->tsi_Run((ILxUnknownID) script, execFlags, args,(ILxUnknownID) msg);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxTextScriptInterpreter vt;
};

class CLxLoc_TextScriptInterpreter : public CLxLocalize<ILxTextScriptInterpreterID>
{
public:
    CLxLoc_TextScriptInterpreter()
    {
        _init();
    }

    CLxLoc_TextScriptInterpreter(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_TextScriptInterpreter(CLxLoc_TextScriptInterpreter const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_TextScriptInterpreter;
    }

    auto ValidateFileType(ILxUnknownID script, const char *firstLine) -> LxResult
    {
        return m_loc[0]->ValidateFileType(m_loc,(ILxUnknownID) script, firstLine);
    }

    auto Validate(ILxUnknownID script, ILxUnknownID msg) -> LxResult
    {
        return m_loc[0]->Validate(m_loc,(ILxUnknownID) script,(ILxUnknownID) msg);
    }

    auto Run(ILxUnknownID script, int execFlags, const char *args, ILxUnknownID msg) -> LxResult
    {
        return m_loc[0]->Run(m_loc,(ILxUnknownID) script, execFlags, args,(ILxUnknownID) msg);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_Script
{
public:
    virtual ~CLxImpl_Script() = default;

    virtual auto scr_Hash([[maybe_unused]] const char **hash) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto scr_UserName([[maybe_unused]] const char **userName) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto scr_SetUserName([[maybe_unused]] const char *userName) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto scr_Desc([[maybe_unused]] const char **desc) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto scr_SetDesc([[maybe_unused]] const char *desc) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto scr_Icon([[maybe_unused]] const char **icon) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto scr_HelpKey([[maybe_unused]] const char *args, [[maybe_unused]] const char **key) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto scr_Manager([[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto scr_GetBuffer([[maybe_unused]] const char **buffer, [[maybe_unused]] unsigned int *bufferLength) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto scr_SetBuffer([[maybe_unused]] const char *buffer, [[maybe_unused]] unsigned int bufferLength) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_Script_Hash LxResult scr_Hash([[maybe_unused]] const char **hash) override
#define LXxO_Script_Hash LXxD_Script_Hash
#define LXxC_Script_Hash(c) LxResult c::scr_Hash([[maybe_unused]] const char **hash)
#define LXxD_Script_UserName LxResult scr_UserName([[maybe_unused]] const char **userName) override
#define LXxO_Script_UserName LXxD_Script_UserName
#define LXxC_Script_UserName(c) LxResult c::scr_UserName([[maybe_unused]] const char **userName)
#define LXxD_Script_SetUserName LxResult scr_SetUserName([[maybe_unused]] const char *userName) override
#define LXxO_Script_SetUserName LXxD_Script_SetUserName
#define LXxC_Script_SetUserName(c) LxResult c::scr_SetUserName([[maybe_unused]] const char *userName)
#define LXxD_Script_Desc LxResult scr_Desc([[maybe_unused]] const char **desc) override
#define LXxO_Script_Desc LXxD_Script_Desc
#define LXxC_Script_Desc(c) LxResult c::scr_Desc([[maybe_unused]] const char **desc)
#define LXxD_Script_SetDesc LxResult scr_SetDesc([[maybe_unused]] const char *desc) override
#define LXxO_Script_SetDesc LXxD_Script_SetDesc
#define LXxC_Script_SetDesc(c) LxResult c::scr_SetDesc([[maybe_unused]] const char *desc)
#define LXxD_Script_Icon LxResult scr_Icon([[maybe_unused]] const char **icon) override
#define LXxO_Script_Icon LXxD_Script_Icon
#define LXxC_Script_Icon(c) LxResult c::scr_Icon([[maybe_unused]] const char **icon)
#define LXxD_Script_HelpKey LxResult scr_HelpKey([[maybe_unused]] const char *args, [[maybe_unused]] const char **key) override
#define LXxO_Script_HelpKey LXxD_Script_HelpKey
#define LXxC_Script_HelpKey(c) LxResult c::scr_HelpKey([[maybe_unused]] const char *args, [[maybe_unused]] const char **key)
#define LXxD_Script_Manager LxResult scr_Manager([[maybe_unused]] void **ppvObj) override
#define LXxO_Script_Manager LXxD_Script_Manager
#define LXxC_Script_Manager(c) LxResult c::scr_Manager([[maybe_unused]] void **ppvObj)
#define LXxD_Script_GetBuffer LxResult scr_GetBuffer([[maybe_unused]] const char **buffer, [[maybe_unused]] unsigned int *bufferLength) override
#define LXxO_Script_GetBuffer LXxD_Script_GetBuffer
#define LXxC_Script_GetBuffer(c) LxResult c::scr_GetBuffer([[maybe_unused]] const char **buffer, [[maybe_unused]] unsigned int *bufferLength)
#define LXxD_Script_SetBuffer LxResult scr_SetBuffer([[maybe_unused]] const char *buffer, [[maybe_unused]] unsigned int bufferLength) override
#define LXxO_Script_SetBuffer LXxD_Script_SetBuffer
#define LXxC_Script_SetBuffer(c) LxResult c::scr_SetBuffer([[maybe_unused]] const char *buffer, [[maybe_unused]] unsigned int bufferLength)

template <class T>
class CLxIfc_Script: public CLxInterface
{
public:
    CLxIfc_Script()
    {
        vt.Hash = Hash;
        vt.UserName = UserName;
        vt.SetUserName = SetUserName;
        vt.Desc = Desc;
        vt.SetDesc = SetDesc;
        vt.Icon = Icon;
        vt.HelpKey = HelpKey;
        vt.Manager = Manager;
        vt.GetBuffer = GetBuffer;
        vt.SetBuffer = SetBuffer;
        vTable = &vt.iunk;
        iid = &lx::guid_Script;
    }

    static auto Hash(LXtObjectID wcom,const char **hash) -> LxResult
    {
        LXCWxINST (CLxImpl_Script, loc);
        try
        {
           return loc->scr_Hash( hash);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto UserName(LXtObjectID wcom,const char **userName) -> LxResult
    {
        LXCWxINST (CLxImpl_Script, loc);
        try
        {
           return loc->scr_UserName( userName);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SetUserName(LXtObjectID wcom,const char *userName) -> LxResult
    {
        LXCWxINST (CLxImpl_Script, loc);
        try
        {
           return loc->scr_SetUserName( userName);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Desc(LXtObjectID wcom,const char **desc) -> LxResult
    {
        LXCWxINST (CLxImpl_Script, loc);
        try
        {
           return loc->scr_Desc( desc);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SetDesc(LXtObjectID wcom,const char *desc) -> LxResult
    {
        LXCWxINST (CLxImpl_Script, loc);
        try
        {
           return loc->scr_SetDesc( desc);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Icon(LXtObjectID wcom,const char **icon) -> LxResult
    {
        LXCWxINST (CLxImpl_Script, loc);
        try
        {
           return loc->scr_Icon( icon);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto HelpKey(LXtObjectID wcom,const char *args,const char **key) -> LxResult
    {
        LXCWxINST (CLxImpl_Script, loc);
        try
        {
           return loc->scr_HelpKey( args, key);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Manager(LXtObjectID wcom,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_Script, loc);
        try
        {
           return loc->scr_Manager( ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto GetBuffer(LXtObjectID wcom,const char **buffer,unsigned int *bufferLength) -> LxResult
    {
        LXCWxINST (CLxImpl_Script, loc);
        try
        {
           return loc->scr_GetBuffer( buffer, bufferLength);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SetBuffer(LXtObjectID wcom,const char *buffer,unsigned int bufferLength) -> LxResult
    {
        LXCWxINST (CLxImpl_Script, loc);
        try
        {
           return loc->scr_SetBuffer( buffer, bufferLength);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxScript vt;
};

class CLxLoc_Script : public CLxLocalize<ILxScriptID>
{
public:
    CLxLoc_Script()
    {
        _init();
    }

    CLxLoc_Script(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_Script(CLxLoc_Script const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_Script;
    }

    auto Hash(const char **hash) -> LxResult
    {
        return m_loc[0]->Hash(m_loc, hash);
    }

    auto UserName(const char **userName) -> LxResult
    {
        return m_loc[0]->UserName(m_loc, userName);
    }

    auto SetUserName(const char *userName) -> LxResult
    {
        return m_loc[0]->SetUserName(m_loc, userName);
    }

    auto Desc(const char **desc) -> LxResult
    {
        return m_loc[0]->Desc(m_loc, desc);
    }

    auto SetDesc(const char *desc) -> LxResult
    {
        return m_loc[0]->SetDesc(m_loc, desc);
    }

    auto Icon(const char **icon) -> LxResult
    {
        return m_loc[0]->Icon(m_loc, icon);
    }

    auto HelpKey(const char *args, const char **key) -> LxResult
    {
        return m_loc[0]->HelpKey(m_loc, args, key);
    }

    auto Manager(void **ppvObj) -> LxResult
    {
        return m_loc[0]->Manager(m_loc, ppvObj);
    }

    auto Manager(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Manager(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto GetBuffer(const char **buffer, unsigned int *bufferLength) -> LxResult
    {
        return m_loc[0]->GetBuffer(m_loc, buffer, bufferLength);
    }

    auto SetBuffer(const char *buffer, unsigned int bufferLength) -> LxResult
    {
        return m_loc[0]->SetBuffer(m_loc, buffer, bufferLength);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_PlatformService : public CLxLocalizedService
{
public:
    ILxPlatformServiceID m_loc{ nullptr };

public:
    CLxLoc_PlatformService()
    {
        _init();
        set();
    }

    ~CLxLoc_PlatformService() = default;

    void set()
    {
        if (!m_loc)
        {
            m_loc = reinterpret_cast<ILxPlatformServiceID>(lx::GetGlobal(&lx::guid_PlatformService));
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

    auto LicensedTo(const char **licensee) -> LxResult
    {
        return m_loc[0]->LicensedTo(m_loc, licensee);
    }

    auto ExpiresIn(int *daysLeft) -> LxResult
    {
        return m_loc[0]->ExpiresIn(m_loc, daysLeft);
    }

    auto SerialNumber(const char **serial) -> LxResult
    {
        return m_loc[0]->SerialNumber(m_loc, serial);
    }

    auto NumLicenses(int *licenses) -> LxResult
    {
        return m_loc[0]->NumLicenses(m_loc, licenses);
    }

    auto AppName(const char **name) -> LxResult
    {
        return m_loc[0]->AppName(m_loc, name);
    }

    auto AppVersion(int *version) -> LxResult
    {
        return m_loc[0]->AppVersion(m_loc, version);
    }

    auto AppBuild(int *build) -> LxResult
    {
        return m_loc[0]->AppBuild(m_loc, build);
    }

    auto IsHeadless(void) -> LxResult
    {
        return m_loc[0]->IsHeadless(m_loc);
    }

    auto OSType(int *type) -> LxResult
    {
        return m_loc[0]->OSType(m_loc, type);
    }

    auto OSName(const char **name) -> LxResult
    {
        return m_loc[0]->OSName(m_loc, name);
    }

    auto OSVersion(const char **version) -> LxResult
    {
        return m_loc[0]->OSVersion(m_loc, version);
    }

    auto PathCount(int *count) -> LxResult
    {
        return m_loc[0]->PathCount(m_loc, count);
    }

    auto PathByIndex(int index, const char **path) -> LxResult
    {
        return m_loc[0]->PathByIndex(m_loc, index, path);
    }

    auto PathNameByIndex(int index, const char **name) -> LxResult
    {
        return m_loc[0]->PathNameByIndex(m_loc, index, name);
    }

    auto ImportPathCount(int *index) -> LxResult
    {
        return m_loc[0]->ImportPathCount(m_loc, index);
    }

    auto ImportPathByIndex(int index, const char **path) -> LxResult
    {
        return m_loc[0]->ImportPathByIndex(m_loc, index, path);
    }

    auto IsApp64Bit(void) -> LxResult
    {
        return m_loc[0]->IsApp64Bit(m_loc);
    }

    auto DoWhenUserIsIdle(ILxUnknownID visitor, int flags) -> LxResult
    {
        return m_loc[0]->DoWhenUserIsIdle(m_loc,(ILxUnknownID) visitor, flags);
    }

    auto CancelDoWhenUserIsIdle(ILxUnknownID visitor, int flags) -> LxResult
    {
        return m_loc[0]->CancelDoWhenUserIsIdle(m_loc,(ILxUnknownID) visitor, flags);
    }

    auto IsUserIdle(void) -> LxResult
    {
        return m_loc[0]->IsUserIdle(m_loc);
    }

    auto IsAppActive(void) -> LxResult
    {
        return m_loc[0]->IsAppActive(m_loc);
    }

    auto SessionStage(int *stage) -> LxResult
    {
        return m_loc[0]->SessionStage(m_loc, stage);
    }

    auto AppUsername(const char **name) -> LxResult
    {
        return m_loc[0]->AppUsername(m_loc, name);
    }

    auto TimerStart(ILxUnknownID visitor, int milliseconds, int idleFlags) -> LxResult
    {
        return m_loc[0]->TimerStart(m_loc,(ILxUnknownID) visitor, milliseconds, idleFlags);
    }

    auto TimerCancel(ILxUnknownID visitor, int idleFlags) -> LxResult
    {
        return m_loc[0]->TimerCancel(m_loc,(ILxUnknownID) visitor, idleFlags);
    }

    auto IsSafeMode(void) -> LxResult
    {
        return m_loc[0]->IsSafeMode(m_loc);
    }

    auto AppVersionMinor(int *version) -> LxResult
    {
        return m_loc[0]->AppVersionMinor(m_loc, version);
    }

    auto AppVersionSP(int *version) -> LxResult
    {
        return m_loc[0]->AppVersionSP(m_loc, version);
    }

    auto AppVersionMajor(int *version) -> LxResult
    {
        return m_loc[0]->AppVersionMajor(m_loc, version);
    }

    auto AppBranch(const char** branchname) -> LxResult
    {
        return m_loc[0]->AppBranch(m_loc, branchname);
    }

    auto ImageSizeLimit(void) -> unsigned int
    {
        return m_loc[0]->ImageSizeLimit(m_loc);
    }

    auto CheckPythonSignatures(void) -> bool
    {
        return m_loc[0]->CheckPythonSignatures(m_loc);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_AppActiveListener
{
public:
    virtual ~CLxImpl_AppActiveListener() = default;

    virtual auto activeevent_IsNowActive([[maybe_unused]] int isActive) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_AppActiveListener_IsNowActive LxResult activeevent_IsNowActive([[maybe_unused]] int isActive) override
#define LXxO_AppActiveListener_IsNowActive LXxD_AppActiveListener_IsNowActive
#define LXxC_AppActiveListener_IsNowActive(c) LxResult c::activeevent_IsNowActive([[maybe_unused]] int isActive)

template <class T>
class CLxIfc_AppActiveListener: public CLxInterface
{
public:
    CLxIfc_AppActiveListener()
    {
        vt.IsNowActive = IsNowActive;
        vTable = &vt.iunk;
        iid = &lx::guid_AppActiveListener;
    }

    static auto IsNowActive(LXtObjectID wcom,int isActive) -> LxResult
    {
        LXCWxINST (CLxImpl_AppActiveListener, loc);
        try
        {
           return loc->activeevent_IsNowActive( isActive);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxAppActiveListener vt;
};

class CLxLoc_AppActiveListener : public CLxLocalize<ILxAppActiveListenerID>
{
public:
    CLxLoc_AppActiveListener()
    {
        _init();
    }

    CLxLoc_AppActiveListener(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_AppActiveListener(CLxLoc_AppActiveListener const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_AppActiveListener;
    }

    auto IsNowActive(int isActive) -> LxResult
    {
        return m_loc[0]->IsNowActive(m_loc, isActive);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_LineInterpreter
{
public:
    virtual ~CLxImpl_LineInterpreter() = default;

    virtual unsigned lin_Flags(void) = 0;

    virtual auto lin_Prompt([[maybe_unused]] const char **prompt, [[maybe_unused]] unsigned type) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto lin_Execute([[maybe_unused]] const char *line, [[maybe_unused]] int execFlags, [[maybe_unused]] ILxUnknownID execution) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_LineInterpreter_Flags unsigned lin_Flags() override
#define LXxO_LineInterpreter_Flags LXxD_LineInterpreter_Flags
#define LXxC_LineInterpreter_Flags(c) unsigned c::lin_Flags()
#define LXxD_LineInterpreter_Prompt LxResult lin_Prompt([[maybe_unused]] const char **prompt, [[maybe_unused]] unsigned type) override
#define LXxO_LineInterpreter_Prompt LXxD_LineInterpreter_Prompt
#define LXxC_LineInterpreter_Prompt(c) LxResult c::lin_Prompt([[maybe_unused]] const char **prompt, [[maybe_unused]] unsigned type)
#define LXxD_LineInterpreter_Execute LxResult lin_Execute([[maybe_unused]] const char *line, [[maybe_unused]] int execFlags, [[maybe_unused]] ILxUnknownID execution) override
#define LXxO_LineInterpreter_Execute LXxD_LineInterpreter_Execute
#define LXxC_LineInterpreter_Execute(c) LxResult c::lin_Execute([[maybe_unused]] const char *line, [[maybe_unused]] int execFlags, [[maybe_unused]] ILxUnknownID execution)

template <class T>
class CLxIfc_LineInterpreter: public CLxInterface
{
public:
    CLxIfc_LineInterpreter()
    {
        vt.Flags = Flags;
        vt.Prompt = Prompt;
        vt.Execute = Execute;
        vTable = &vt.iunk;
        iid = &lx::guid_LineInterpreter;
    }

    static auto Flags(LXtObjectID wcom) -> unsigned
    {
        LXCWxINST (CLxImpl_LineInterpreter, loc);
        return loc->lin_Flags();
    }

    static auto Prompt(LXtObjectID wcom,const char **prompt,unsigned type) -> LxResult
    {
        LXCWxINST (CLxImpl_LineInterpreter, loc);
        try
        {
           return loc->lin_Prompt( prompt, type);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Execute(LXtObjectID wcom,const char *line,int execFlags,LXtObjectID execution) -> LxResult
    {
        LXCWxINST (CLxImpl_LineInterpreter, loc);
        try
        {
           return loc->lin_Execute( line, execFlags,(ILxUnknownID) execution);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxLineInterpreter vt;
};

class CLxLoc_LineInterpreter : public CLxLocalize<ILxLineInterpreterID>
{
public:
    CLxLoc_LineInterpreter()
    {
        _init();
    }

    CLxLoc_LineInterpreter(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_LineInterpreter(CLxLoc_LineInterpreter const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_LineInterpreter;
    }

    auto Flags(void) -> unsigned
    {
        return m_loc[0]->Flags(m_loc);
    }

    auto Prompt(const char **prompt, unsigned type) -> LxResult
    {
        return m_loc[0]->Prompt(m_loc, prompt, type);
    }

    auto Execute(const char *line, int execFlags, ILxUnknownID execution) -> LxResult
    {
        return m_loc[0]->Execute(m_loc, line, execFlags,(ILxUnknownID) execution);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_LineExecution
{
public:
    virtual ~CLxImpl_LineExecution() = default;

    virtual auto lin_CookedLine([[maybe_unused]] const char *text) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto lin_Message([[maybe_unused]] ILxUnknownID message) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto lin_Results([[maybe_unused]] ILxUnknownID valArray) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto lin_ResultHints([[maybe_unused]] const LXtTextValueHint *hints) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto lin_Info([[maybe_unused]] const char *text) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_LineExecution_CookedLine LxResult lin_CookedLine([[maybe_unused]] const char *text) override
#define LXxO_LineExecution_CookedLine LXxD_LineExecution_CookedLine
#define LXxC_LineExecution_CookedLine(c) LxResult c::lin_CookedLine([[maybe_unused]] const char *text)
#define LXxD_LineExecution_Message LxResult lin_Message([[maybe_unused]] ILxUnknownID message) override
#define LXxO_LineExecution_Message LXxD_LineExecution_Message
#define LXxC_LineExecution_Message(c) LxResult c::lin_Message([[maybe_unused]] ILxUnknownID message)
#define LXxD_LineExecution_Results LxResult lin_Results([[maybe_unused]] ILxUnknownID valArray) override
#define LXxO_LineExecution_Results LXxD_LineExecution_Results
#define LXxC_LineExecution_Results(c) LxResult c::lin_Results([[maybe_unused]] ILxUnknownID valArray)
#define LXxD_LineExecution_ResultHints LxResult lin_ResultHints([[maybe_unused]] const LXtTextValueHint *hints) override
#define LXxO_LineExecution_ResultHints LXxD_LineExecution_ResultHints
#define LXxC_LineExecution_ResultHints(c) LxResult c::lin_ResultHints([[maybe_unused]] const LXtTextValueHint *hints)
#define LXxD_LineExecution_Info LxResult lin_Info([[maybe_unused]] const char *text) override
#define LXxO_LineExecution_Info LXxD_LineExecution_Info
#define LXxC_LineExecution_Info(c) LxResult c::lin_Info([[maybe_unused]] const char *text)

template <class T>
class CLxIfc_LineExecution: public CLxInterface
{
public:
    CLxIfc_LineExecution()
    {
        vt.CookedLine = CookedLine;
        vt.Message = Message;
        vt.Results = Results;
        vt.ResultHints = ResultHints;
        vt.Info = Info;
        vTable = &vt.iunk;
        iid = &lx::guid_LineExecution;
    }

    static auto CookedLine(LXtObjectID wcom,const char *text) -> LxResult
    {
        LXCWxINST (CLxImpl_LineExecution, loc);
        try
        {
           return loc->lin_CookedLine( text);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Message(LXtObjectID wcom,LXtObjectID message) -> LxResult
    {
        LXCWxINST (CLxImpl_LineExecution, loc);
        try
        {
           return loc->lin_Message((ILxUnknownID) message);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Results(LXtObjectID wcom,LXtObjectID valArray) -> LxResult
    {
        LXCWxINST (CLxImpl_LineExecution, loc);
        try
        {
           return loc->lin_Results((ILxUnknownID) valArray);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ResultHints(LXtObjectID wcom,const LXtTextValueHint *hints) -> LxResult
    {
        LXCWxINST (CLxImpl_LineExecution, loc);
        try
        {
           return loc->lin_ResultHints( hints);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Info(LXtObjectID wcom,const char *text) -> LxResult
    {
        LXCWxINST (CLxImpl_LineExecution, loc);
        try
        {
           return loc->lin_Info( text);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxLineExecution vt;
};

class CLxLoc_LineExecution : public CLxLocalize<ILxLineExecutionID>
{
public:
    CLxLoc_LineExecution()
    {
        _init();
    }

    CLxLoc_LineExecution(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_LineExecution(CLxLoc_LineExecution const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_LineExecution;
    }

    auto CookedLine(const char *text) -> LxResult
    {
        return m_loc[0]->CookedLine(m_loc, text);
    }

    auto Message(ILxUnknownID message) -> LxResult
    {
        return m_loc[0]->Message(m_loc,(ILxUnknownID) message);
    }

    auto Results(ILxUnknownID valArray) -> LxResult
    {
        return m_loc[0]->Results(m_loc,(ILxUnknownID) valArray);
    }

    auto ResultHints(const LXtTextValueHint *hints) -> LxResult
    {
        return m_loc[0]->ResultHints(m_loc, hints);
    }

    auto Info(const char *text) -> LxResult
    {
        return m_loc[0]->Info(m_loc, text);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_ScriptLineEvent
{
public:
    virtual ~CLxImpl_ScriptLineEvent() = default;

    virtual auto slev_Index([[maybe_unused]] unsigned int *index) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto slev_Script([[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_ScriptLineEvent_Index LxResult slev_Index([[maybe_unused]] unsigned int *index) override
#define LXxO_ScriptLineEvent_Index LXxD_ScriptLineEvent_Index
#define LXxC_ScriptLineEvent_Index(c) LxResult c::slev_Index([[maybe_unused]] unsigned int *index)
#define LXxD_ScriptLineEvent_Script LxResult slev_Script([[maybe_unused]] void **ppvObj) override
#define LXxO_ScriptLineEvent_Script LXxD_ScriptLineEvent_Script
#define LXxC_ScriptLineEvent_Script(c) LxResult c::slev_Script([[maybe_unused]] void **ppvObj)

template <class T>
class CLxIfc_ScriptLineEvent: public CLxInterface
{
public:
    CLxIfc_ScriptLineEvent()
    {
        vt.Index = Index;
        vt.Script = Script;
        vTable = &vt.iunk;
        iid = &lx::guid_ScriptLineEvent;
    }

    static auto Index(LXtObjectID wcom,unsigned int *index) -> LxResult
    {
        LXCWxINST (CLxImpl_ScriptLineEvent, loc);
        try
        {
           return loc->slev_Index( index);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Script(LXtObjectID wcom,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_ScriptLineEvent, loc);
        try
        {
           return loc->slev_Script( ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxScriptLineEvent vt;
};

class CLxLoc_ScriptLineEvent : public CLxLocalize<ILxScriptLineEventID>
{
public:
    CLxLoc_ScriptLineEvent()
    {
        _init();
    }

    CLxLoc_ScriptLineEvent(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_ScriptLineEvent(CLxLoc_ScriptLineEvent const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_ScriptLineEvent;
    }

    auto Index(unsigned int *index) -> LxResult
    {
        return m_loc[0]->Index(m_loc, index);
    }

    auto Script(void **ppvObj) -> LxResult
    {
        return m_loc[0]->Script(m_loc, ppvObj);
    }

    auto Script(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Script(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
