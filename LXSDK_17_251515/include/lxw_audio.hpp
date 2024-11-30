//
// C++ wrapper for lxsdk/lxaudio.h.
//
//	Copyright 2024.
//
//
#pragma once

#include <lxaudio.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx
{
    static LXtGUID const guid_AudioAnimService = {0x42F4A65B, {0xA5BE, 0x4C77}, {0x8A, 0x66, 0x3C, 0x1B, 0x24, 0x5C, 0x6B, 0xB0}};
} // namespace lx

class CLxLoc_AudioAnimService : public CLxLocalizedService
{
public:
    ILxAudioAnimServiceID m_loc{ nullptr };

public:
    CLxLoc_AudioAnimService()
    {
        _init();
        set();
    }

    ~CLxLoc_AudioAnimService() = default;

    void set()
    {
        if (!m_loc)
        {
            m_loc = reinterpret_cast<ILxAudioAnimServiceID>(lx::GetGlobal(&lx::guid_AudioAnimService));
        }
    }

    auto Item(void **ppvObj) -> LxResult
    {
        return m_loc[0]->Item(m_loc, ppvObj);
    }

    auto Item(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Item(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Sample(double time, unsigned int type, void *value) -> LxResult
    {
        return m_loc[0]->Sample(m_loc, time, type, value);
    }

    auto Playing(void) -> int
    {
        return m_loc[0]->Playing(m_loc);
    }

    auto Loop(void) -> int
    {
        return m_loc[0]->Loop(m_loc);
    }

    auto Mute(void) -> int
    {
        return m_loc[0]->Mute(m_loc);
    }

    auto Scrub(void) -> int
    {
        return m_loc[0]->Scrub(m_loc);
    }

    auto Start(void) -> double
    {
        return m_loc[0]->Start(m_loc);
    }

    auto End(void) -> double
    {
        return m_loc[0]->End(m_loc);
    }

    auto Audio(void **ppvObj) -> LxResult
    {
        return m_loc[0]->Audio(m_loc, ppvObj);
    }

    auto Audio(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Audio(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Preview(double startTime, double endTime, void **ppvObj) -> LxResult
    {
        return m_loc[0]->Preview(m_loc, startTime, endTime, ppvObj);
    }

    auto Preview(double startTime, double endTime, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Preview(m_loc, startTime, endTime, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto ItemSample(ILxUnknownID obj, int loop, double time, unsigned int type, void *value) -> LxResult
    {
        return m_loc[0]->ItemSample(m_loc,(ILxUnknownID) obj, loop, time, type, value);
    }

    auto ItemAudio(ILxUnknownID obj, void **ppvObj) -> LxResult
    {
        return m_loc[0]->ItemAudio(m_loc,(ILxUnknownID) obj, ppvObj);
    }

    auto ItemAudio(ILxUnknownID obj, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->ItemAudio(m_loc,(ILxUnknownID) obj, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
