//
// C++ wrapper for lxsdk/lxvaluehud.h.
//
//	Copyright 2024.
//
//
#pragma once

#include <lxvaluehud.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx
{
    static LXtGUID const guid_ValueHUDService = {0x7ed5ebf7, {0x578c, 0x4cf6}, {0x98, 0xe7, 0x2e, 0x0a, 0xf5, 0x3e, 0x56, 0xfa}};
} // namespace lx

class CLxLoc_ValueHUDService : public CLxLocalizedService
{
public:
    ILxValueHUDServiceID m_loc{ nullptr };

public:
    CLxLoc_ValueHUDService()
    {
        _init();
        set();
    }

    ~CLxLoc_ValueHUDService() = default;

    void set()
    {
        if (!m_loc)
        {
            m_loc = reinterpret_cast<ILxValueHUDServiceID>(lx::GetGlobal(&lx::guid_ValueHUDService));
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

    auto SetHUDCommands(const char *cookie, const char *command1, const char *command2, const char *command3, int alphaSort) -> LxResult
    {
        return m_loc[0]->SetHUDCommands(m_loc, cookie, command1, command2, command3, alphaSort);
    }

    auto ClearHUD(const char *cookie) -> LxResult
    {
        return m_loc[0]->ClearHUD(m_loc, cookie);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
