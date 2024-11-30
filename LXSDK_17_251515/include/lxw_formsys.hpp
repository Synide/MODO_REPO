//
// C++ wrapper for lxsdk/lxformsys.h.
//
//	Copyright 2024.
//
//
#pragma once

#include <lxformsys.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx
{
    static LXtGUID const guid_FormEntryDest = {0xd8c44d68, {0xba77, 0x4193}, {0x94, 0x2a, 0xd5, 0x9e, 0xe1, 0x15, 0xd9, 0x9f}};
    static LXtGUID const guid_FormEntryDropPreview = {0x43908515, {0xdd63, 0x4b36}, {0xa8, 0xca, 0x56, 0x99, 0xd0, 0x18, 0x82, 0x5d}};
    static LXtGUID const guid_FormDeleteEntryDest = {0xa70bedf3, {0xbd43, 0x40c9}, {0x9e, 0x77, 0xa7, 0x63, 0x2e, 0x0f, 0x35, 0xed}};
} // namespace lx

class CLxLoc_FormEntryDest : public CLxLocalize<ILxFormEntryDestID>
{
public:
    CLxLoc_FormEntryDest()
    {
        _init();
    }

    CLxLoc_FormEntryDest(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_FormEntryDest(CLxLoc_FormEntryDest const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_FormEntryDest;
    }

    auto FormHash(const char **hash) -> LxResult
    {
        return m_loc[0]->FormHash(m_loc, hash);
    }

    auto ControlHash(const char **hash) -> LxResult
    {
        return m_loc[0]->ControlHash(m_loc, hash);
    }

    auto SyntheticIndex(int *index) -> LxResult
    {
        return m_loc[0]->SyntheticIndex(m_loc, index);
    }

    auto Position(int *pos) -> LxResult
    {
        return m_loc[0]->Position(m_loc, pos);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_FormEntryDropPreview : public CLxLocalize<ILxFormEntryDropPreviewID>
{
public:
    CLxLoc_FormEntryDropPreview()
    {
        _init();
    }

    CLxLoc_FormEntryDropPreview(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_FormEntryDropPreview(CLxLoc_FormEntryDropPreview const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_FormEntryDropPreview;
    }

    auto MarkControl(const char *hash, int syntheticIndex, int pos) -> LxResult
    {
        return m_loc[0]->MarkControl(m_loc, hash, syntheticIndex, pos);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_FormDeleteEntryDest : public CLxLocalize<ILxFormDeleteEntryDestID>
{
public:
    CLxLoc_FormDeleteEntryDest()
    {
        _init();
    }

    CLxLoc_FormDeleteEntryDest(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_FormDeleteEntryDest(CLxLoc_FormDeleteEntryDest const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_FormDeleteEntryDest;
    }

    auto Delete(const char *hash) -> LxResult
    {
        return m_loc[0]->Delete(m_loc, hash);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
