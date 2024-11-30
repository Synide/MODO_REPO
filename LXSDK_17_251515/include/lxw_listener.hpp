//
// C++ wrapper for lxsdk/lxlistener.h.
//
//	Copyright 2024.
//
//
#pragma once

#include <lxlistener.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx
{
    static LXtGUID const guid_ListenerService = {0x1966420D, {0xDFED, 0x11D7}, {0xA2, 0x37, 0x00, 0x0A, 0x95, 0x93, 0xD7, 0x16}};
    static LXtGUID const guid_ListenerPort = {0x4FBF5E77, {0x152D, 0x4C4F}, {0xBF, 0xD4, 0x3F, 0x60, 0x62, 0xCC, 0xF6, 0xBA}};
} // namespace lx

class CLxLoc_ListenerService : public CLxLocalizedService
{
public:
    ILxListenerServiceID m_loc{ nullptr };

public:
    CLxLoc_ListenerService()
    {
        _init();
        set();
    }

    ~CLxLoc_ListenerService() = default;

    void set()
    {
        if (!m_loc)
        {
            m_loc = reinterpret_cast<ILxListenerServiceID>(lx::GetGlobal(&lx::guid_ListenerService));
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

    auto AddListener(ILxUnknownID object) -> LxResult
    {
        return m_loc[0]->AddListener(m_loc,(ILxUnknownID) object);
    }

    auto RemoveListener(ILxUnknownID object) -> LxResult
    {
        return m_loc[0]->RemoveListener(m_loc,(ILxUnknownID) object);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_ListenerPort
{
public:
    virtual ~CLxImpl_ListenerPort() = default;

    virtual auto lport_AddListener([[maybe_unused]] ILxUnknownID object) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto lport_RemoveListener([[maybe_unused]] ILxUnknownID object) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_ListenerPort_AddListener LxResult lport_AddListener([[maybe_unused]] ILxUnknownID object) override
#define LXxO_ListenerPort_AddListener LXxD_ListenerPort_AddListener
#define LXxC_ListenerPort_AddListener(c) LxResult c::lport_AddListener([[maybe_unused]] ILxUnknownID object)
#define LXxD_ListenerPort_RemoveListener LxResult lport_RemoveListener([[maybe_unused]] ILxUnknownID object) override
#define LXxO_ListenerPort_RemoveListener LXxD_ListenerPort_RemoveListener
#define LXxC_ListenerPort_RemoveListener(c) LxResult c::lport_RemoveListener([[maybe_unused]] ILxUnknownID object)

template <class T>
class CLxIfc_ListenerPort: public CLxInterface
{
public:
    CLxIfc_ListenerPort()
    {
        vt.AddListener = AddListener;
        vt.RemoveListener = RemoveListener;
        vTable = &vt.iunk;
        iid = &lx::guid_ListenerPort;
    }

    static auto AddListener(LXtObjectID wcom,LXtObjectID object) -> LxResult
    {
        LXCWxINST (CLxImpl_ListenerPort, loc);
        try
        {
           return loc->lport_AddListener((ILxUnknownID) object);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto RemoveListener(LXtObjectID wcom,LXtObjectID object) -> LxResult
    {
        LXCWxINST (CLxImpl_ListenerPort, loc);
        try
        {
           return loc->lport_RemoveListener((ILxUnknownID) object);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxListenerPort vt;
};

class CLxLoc_ListenerPort : public CLxLocalize<ILxListenerPortID>
{
public:
    CLxLoc_ListenerPort()
    {
        _init();
    }

    CLxLoc_ListenerPort(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_ListenerPort(CLxLoc_ListenerPort const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_ListenerPort;
    }

    auto AddListener(ILxUnknownID object) -> LxResult
    {
        return m_loc[0]->AddListener(m_loc,(ILxUnknownID) object);
    }

    auto RemoveListener(ILxUnknownID object) -> LxResult
    {
        return m_loc[0]->RemoveListener(m_loc,(ILxUnknownID) object);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
