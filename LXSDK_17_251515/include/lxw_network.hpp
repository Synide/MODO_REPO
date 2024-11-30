//
// C++ wrapper for lxsdk/lxnetwork.h.
//
//	Copyright 2024.
//
//
#pragma once

#include <lxnetwork.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx
{
    static LXtGUID const guid_NetworkService = {0x333d439d, {0xcfc8, 0x43e6}, {0xad, 0x3c, 0x1e, 0x2b, 0x6f, 0xda, 0x27, 0xfb}};
} // namespace lx

class CLxLoc_NetworkService : public CLxLocalizedService
{
public:
    ILxNetworkServiceID m_loc{ nullptr };

public:
    CLxLoc_NetworkService()
    {
        _init();
        set();
    }

    ~CLxLoc_NetworkService() = default;

    void set()
    {
        if (!m_loc)
        {
            m_loc = reinterpret_cast<ILxNetworkServiceID>(lx::GetGlobal(&lx::guid_NetworkService));
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

    auto OneOffHostListAdd(const char *hostname, LXtIP4 ip, int port) -> LxResult
    {
        return m_loc[0]->OneOffHostListAdd(m_loc, hostname, ip, port);
    }

    auto OneOffHostListRemove(const char *hostname, LXtIP4 ip, int port) -> LxResult
    {
        return m_loc[0]->OneOffHostListRemove(m_loc, hostname, ip, port);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
