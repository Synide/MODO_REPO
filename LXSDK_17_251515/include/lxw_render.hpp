//
// C++ wrapper for lxsdk/lxrender.h.
//
//	Copyright 2024.
//
//
#pragma once

#include <lxrender.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx
{
    static LXtGUID const guid_RenderBucket = {0xED6F0ABE, {0xF76F, 0x4EED}, {0xBE, 0xF5, 0xA3, 0x0F, 0xF7, 0xF7, 0x10, 0x98}};
} // namespace lx

class CLxLoc_RenderBucket : public CLxLocalize<ILxRenderBucketID>
{
public:
    CLxLoc_RenderBucket()
    {
        _init();
    }

    CLxLoc_RenderBucket(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_RenderBucket(CLxLoc_RenderBucket const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_RenderBucket;
    }

    auto Thread(void) -> unsigned int
    {
        return m_loc[0]->Thread(m_loc);
    }

    auto SampleVec(void **ppvObj) -> LxResult
    {
        return m_loc[0]->SampleVec(m_loc, ppvObj);
    }

    auto SampleVec(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->SampleVec(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto PushRay(void) -> LxResult
    {
        return m_loc[0]->PushRay(m_loc);
    }

    auto PopRay(void) -> LxResult
    {
        return m_loc[0]->PopRay(m_loc);
    }

    auto GetGIBounce(void) -> int
    {
        return m_loc[0]->GetGIBounce(m_loc);
    }

    auto GetPixel(int *x, int *y) -> void
    {
        m_loc[0]->GetPixel(m_loc, x, y);
    }

    auto GetSubPixel(float *x, float *y) -> void
    {
        m_loc[0]->GetSubPixel(m_loc, x, y);
    }

    auto GetTimeOffset(void) -> float
    {
        return m_loc[0]->GetTimeOffset(m_loc);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
