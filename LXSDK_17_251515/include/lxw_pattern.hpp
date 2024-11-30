//
// C++ wrapper for lxsdk/lxpattern.h.
//
//	Copyright 2024.
//
//
#pragma once

#include <lxpattern.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx
{
    static LXtGUID const guid_Pattern = {0x16EE409B, {0x6B63, 0x4CB0}, {0x8D, 0xE6, 0xC3, 0xD9, 0xAD, 0x12, 0x4D, 0xBE}};
} // namespace lx

class CLxLoc_Pattern : public CLxLocalize<ILxPatternID>
{
public:
    CLxLoc_Pattern()
    {
        _init();
    }

    CLxLoc_Pattern(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_Pattern(CLxLoc_Pattern const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_Pattern;
    }

    auto Test(int index, int offset) const -> LxResult
    {
        return m_loc[0]->Test(m_loc, index, offset);
    }

    auto GenerateSequenceString(int start, int end, char *buf, unsigned int len) const -> LxResult
    {
        return m_loc[0]->GenerateSequenceString(m_loc, start, end, buf, len);
    }

    auto GenerateSequenceString(int start, int end, std::string &result) const -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->GenerateSequenceString(m_loc, start, end, buf, len);
        LXWx_SBUF2
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
