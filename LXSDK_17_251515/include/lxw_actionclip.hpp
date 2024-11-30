//
// C++ wrapper for lxsdk/lxactionclip.h.
//
//	Copyright 2024.
//
//
#pragma once

#include <lxactionclip.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx
{
    static LXtGUID const guid_ActionClip = {0xA312921B, {0x41D2, 0x4D2A}, {0x86, 0x78, 0xC9, 0x0E, 0xEA, 0x38, 0x1F, 0xAE}};
} // namespace lx

class CLxLoc_ActionClip : public CLxLocalize<ILxActionClipID>
{
public:
    CLxLoc_ActionClip()
    {
        _init();
    }

    CLxLoc_ActionClip(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_ActionClip(CLxLoc_ActionClip const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_ActionClip;
    }

    auto SetParenting(ILxUnknownID group) -> LxResult
    {
        return m_loc[0]->SetParenting(m_loc,(ILxUnknownID) group);
    }

    auto SetActive(int state) -> LxResult
    {
        return m_loc[0]->SetActive(m_loc, state);
    }

    auto Active(void) -> unsigned
    {
        return m_loc[0]->Active(m_loc);
    }

    auto SetEnabled(int state) -> LxResult
    {
        return m_loc[0]->SetEnabled(m_loc, state);
    }

    auto Enabled(void) -> unsigned
    {
        return m_loc[0]->Enabled(m_loc);
    }

    auto Action(double time, void **ppvObj) -> LxResult
    {
        return m_loc[0]->Action(m_loc, time, ppvObj);
    }

    auto Action(double time, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Action(m_loc, time, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Extents(double *timeS, double *timeE, int layers) -> LxResult
    {
        return m_loc[0]->Extents(m_loc, timeS, timeE, layers);
    }

    auto Create(void) -> LxResult
    {
        return m_loc[0]->Create(m_loc);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
