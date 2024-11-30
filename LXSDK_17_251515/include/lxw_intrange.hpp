//
// C++ wrapper for lxsdk/lxintrange.h.
//
//	Copyright 2024.
//
//
#pragma once

#include <lxintrange.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx
{
    static LXtGUID const guid_IntRange = {0xFEAF19EC, {0xB819, 0x4C46}, {0xAB, 0xA3, 0xEC, 0x85, 0x93, 0xF8, 0xBE, 0x8C}};
} // namespace lx

class CLxLoc_IntRange : public CLxLocalize<ILxIntRangeID>
{
public:
    CLxLoc_IntRange()
    {
        _init();
    }

    CLxLoc_IntRange(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_IntRange(CLxLoc_IntRange const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_IntRange;
    }

    auto AllBefore(void) const -> LxResult
    {
        return m_loc[0]->AllBefore(m_loc);
    }

    auto AllAfter(void) const -> LxResult
    {
        return m_loc[0]->AllAfter(m_loc);
    }

    auto Next(int *i) -> LxResult
    {
        return m_loc[0]->Next(m_loc, i);
    }

    auto Prev(int *i) -> LxResult
    {
        return m_loc[0]->Prev(m_loc, i);
    }

    auto Min(int *min) -> LxResult
    {
        return m_loc[0]->Min(m_loc, min);
    }

    auto Max(int *max) -> LxResult
    {
        return m_loc[0]->Max(m_loc, max);
    }

    auto First(int *first) -> LxResult
    {
        return m_loc[0]->First(m_loc, first);
    }

    auto Last(int *last) -> LxResult
    {
        return m_loc[0]->Last(m_loc, last);
    }

    auto Current(int *current) const -> LxResult
    {
        return m_loc[0]->Current(m_loc, current);
    }

    auto Test(int i) const -> LxResult
    {
        return m_loc[0]->Test(m_loc, i);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
