//
// C++ wrapper for lxsdk/lxnotify.h.
//
//	Copyright 2024.
//
//
#pragma once

#include <lxnotify.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx
{
    static LXtGUID const guid_NotifySysService = {0x4A3B31B0, {0xA8F8, 0x430A}, {0x96, 0x11, 0x9D, 0x30, 0xE5, 0x1C, 0xBB, 0xBA}};
    static LXtGUID const guid_Notifier = {0x68725BA4, {0x8EF9, 0x4de4}, {0x87, 0x92, 0x74, 0xCF, 0x09, 0x07, 0x99, 0xC3}};
    static LXtGUID const guid_Notify = {0x15C9BFC0, {0xA0A7, 0x448c}, {0x8C, 0xD5, 0xA8, 0xFC, 0xA2, 0xCB, 0x14, 0x5B}};
} // namespace lx

class CLxLoc_NotifySysService : public CLxLocalizedService
{
public:
    ILxNotifySysServiceID m_loc{ nullptr };

public:
    CLxLoc_NotifySysService()
    {
        _init();
        set();
    }

    ~CLxLoc_NotifySysService() = default;

    void set()
    {
        if (!m_loc)
        {
            m_loc = reinterpret_cast<ILxNotifySysServiceID>(lx::GetGlobal(&lx::guid_NotifySysService));
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

    auto Spawn(const char *name, const char *args, void **ppvObj) -> LxResult
    {
        return m_loc[0]->Spawn(m_loc, name, args, ppvObj);
    }

    auto Spawn(const char *name, const char *args, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Spawn(m_loc, name, args, &o_obj);
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

    auto Lookup(const char *name, const char *args, void **ppvObj) -> LxResult
    {
        return m_loc[0]->Lookup(m_loc, name, args, ppvObj);
    }

    auto Lookup(const char *name, const char *args, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Lookup(m_loc, name, args, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_Notifier
{
public:
    virtual ~CLxImpl_Notifier() = default;

    virtual auto noti_Name([[maybe_unused]] const char **name) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto noti_SetArgs([[maybe_unused]] const char *args) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto noti_Args([[maybe_unused]] const char **args) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto noti_AddClient([[maybe_unused]] ILxUnknownID object) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto noti_RemoveClient([[maybe_unused]] ILxUnknownID object) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_Notifier_Name LxResult noti_Name([[maybe_unused]] const char **name) override
#define LXxO_Notifier_Name LXxD_Notifier_Name
#define LXxC_Notifier_Name(c) LxResult c::noti_Name([[maybe_unused]] const char **name)
#define LXxD_Notifier_SetArgs LxResult noti_SetArgs([[maybe_unused]] const char *args) override
#define LXxO_Notifier_SetArgs LXxD_Notifier_SetArgs
#define LXxC_Notifier_SetArgs(c) LxResult c::noti_SetArgs([[maybe_unused]] const char *args)
#define LXxD_Notifier_Args LxResult noti_Args([[maybe_unused]] const char **args) override
#define LXxO_Notifier_Args LXxD_Notifier_Args
#define LXxC_Notifier_Args(c) LxResult c::noti_Args([[maybe_unused]] const char **args)
#define LXxD_Notifier_AddClient LxResult noti_AddClient([[maybe_unused]] ILxUnknownID object) override
#define LXxO_Notifier_AddClient LXxD_Notifier_AddClient
#define LXxC_Notifier_AddClient(c) LxResult c::noti_AddClient([[maybe_unused]] ILxUnknownID object)
#define LXxD_Notifier_RemoveClient LxResult noti_RemoveClient([[maybe_unused]] ILxUnknownID object) override
#define LXxO_Notifier_RemoveClient LXxD_Notifier_RemoveClient
#define LXxC_Notifier_RemoveClient(c) LxResult c::noti_RemoveClient([[maybe_unused]] ILxUnknownID object)

template <class T>
class CLxIfc_Notifier: public CLxInterface
{
public:
    CLxIfc_Notifier()
    {
        vt.Name = Name;
        vt.SetArgs = SetArgs;
        vt.Args = Args;
        vt.AddClient = AddClient;
        vt.RemoveClient = RemoveClient;
        vTable = &vt.iunk;
        iid = &lx::guid_Notifier;
    }

    static auto Name(LXtObjectID wcom,const char **name) -> LxResult
    {
        LXCWxINST (CLxImpl_Notifier, loc);
        try
        {
           return loc->noti_Name( name);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SetArgs(LXtObjectID wcom,const char *args) -> LxResult
    {
        LXCWxINST (CLxImpl_Notifier, loc);
        try
        {
           return loc->noti_SetArgs( args);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Args(LXtObjectID wcom,const char **args) -> LxResult
    {
        LXCWxINST (CLxImpl_Notifier, loc);
        try
        {
           return loc->noti_Args( args);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto AddClient(LXtObjectID wcom,LXtObjectID object) -> LxResult
    {
        LXCWxINST (CLxImpl_Notifier, loc);
        try
        {
           return loc->noti_AddClient((ILxUnknownID) object);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto RemoveClient(LXtObjectID wcom,LXtObjectID object) -> LxResult
    {
        LXCWxINST (CLxImpl_Notifier, loc);
        try
        {
           return loc->noti_RemoveClient((ILxUnknownID) object);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxNotifier vt;
};

class CLxLoc_Notifier : public CLxLocalize<ILxNotifierID>
{
public:
    CLxLoc_Notifier()
    {
        _init();
    }

    CLxLoc_Notifier(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_Notifier(CLxLoc_Notifier const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_Notifier;
    }

    auto Name(const char **name) -> LxResult
    {
        return m_loc[0]->Name(m_loc, name);
    }

    auto SetArgs(const char *args) -> LxResult
    {
        return m_loc[0]->SetArgs(m_loc, args);
    }

    auto Args(const char **args) -> LxResult
    {
        return m_loc[0]->Args(m_loc, args);
    }

    auto AddClient(ILxUnknownID object) -> LxResult
    {
        return m_loc[0]->AddClient(m_loc,(ILxUnknownID) object);
    }

    auto RemoveClient(ILxUnknownID object) -> LxResult
    {
        return m_loc[0]->RemoveClient(m_loc,(ILxUnknownID) object);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};

