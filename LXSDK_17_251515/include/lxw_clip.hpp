//
// C++ wrapper for lxsdk/lxclip.h.
//
//	Copyright 2024.
//
//
#pragma once

#include <lxclip.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx
{
    static LXtGUID const guid_VideoClipItem = {0x340FD1AD, {0xB576, 0x4BC3}, {0x8B, 0x6F, 0x7D, 0xF1, 0xF5, 0xC3, 0x12, 0xFB}};
} // namespace lx

class CLxImpl_VideoClipItem
{
public:
    virtual ~CLxImpl_VideoClipItem() = default;

    virtual auto vclip_PrepFilter([[maybe_unused]] ILxUnknownID eval, [[maybe_unused]] void **cache) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto vclip_AllocFilter([[maybe_unused]] ILxUnknownID attr, [[maybe_unused]] void *cache, [[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual void vclip_Cleanup([[maybe_unused]] void *cache)
    {
    }
};

#define LXxD_VideoClipItem_PrepFilter LxResult vclip_PrepFilter([[maybe_unused]] ILxUnknownID eval, [[maybe_unused]] void **cache) override
#define LXxO_VideoClipItem_PrepFilter LXxD_VideoClipItem_PrepFilter
#define LXxC_VideoClipItem_PrepFilter(c) LxResult c::vclip_PrepFilter([[maybe_unused]] ILxUnknownID eval, [[maybe_unused]] void **cache)
#define LXxD_VideoClipItem_AllocFilter LxResult vclip_AllocFilter([[maybe_unused]] ILxUnknownID attr, [[maybe_unused]] void *cache, [[maybe_unused]] void **ppvObj) override
#define LXxO_VideoClipItem_AllocFilter LXxD_VideoClipItem_AllocFilter
#define LXxC_VideoClipItem_AllocFilter(c) LxResult c::vclip_AllocFilter([[maybe_unused]] ILxUnknownID attr, [[maybe_unused]] void *cache, [[maybe_unused]] void **ppvObj)
#define LXxD_VideoClipItem_Cleanup void vclip_Cleanup([[maybe_unused]] void *cache) override
#define LXxO_VideoClipItem_Cleanup LXxD_VideoClipItem_Cleanup
#define LXxC_VideoClipItem_Cleanup(c) void c::vclip_Cleanup([[maybe_unused]] void *cache)

template <class T>
class CLxIfc_VideoClipItem: public CLxInterface
{
public:
    CLxIfc_VideoClipItem()
    {
        vt.PrepFilter = PrepFilter;
        vt.AllocFilter = AllocFilter;
        vt.Cleanup = Cleanup;
        vTable = &vt.iunk;
        iid = &lx::guid_VideoClipItem;
    }

    static auto PrepFilter(LXtObjectID wcom,LXtObjectID eval,void **cache) -> LxResult
    {
        LXCWxINST (CLxImpl_VideoClipItem, loc);
        try
        {
           return loc->vclip_PrepFilter((ILxUnknownID) eval, cache);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto AllocFilter(LXtObjectID wcom,LXtObjectID attr,void *cache,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_VideoClipItem, loc);
        try
        {
           return loc->vclip_AllocFilter((ILxUnknownID) attr, cache, ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Cleanup(LXtObjectID wcom,void *cache) -> void
    {
        LXCWxINST (CLxImpl_VideoClipItem, loc);
        loc->vclip_Cleanup( cache);
    }

private:
    ILxVideoClipItem vt;
};

class CLxLoc_VideoClipItem : public CLxLocalize<ILxVideoClipItemID>
{
public:
    CLxLoc_VideoClipItem()
    {
        _init();
    }

    CLxLoc_VideoClipItem(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_VideoClipItem(CLxLoc_VideoClipItem const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_VideoClipItem;
    }

    auto PrepFilter(ILxUnknownID eval, void **cache) -> LxResult
    {
        return m_loc[0]->PrepFilter(m_loc,(ILxUnknownID) eval, cache);
    }

    auto AllocFilter(ILxUnknownID attr, void *cache, void **ppvObj) -> LxResult
    {
        return m_loc[0]->AllocFilter(m_loc,(ILxUnknownID) attr, cache, ppvObj);
    }

    auto AllocFilter(ILxUnknownID attr, void *cache, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->AllocFilter(m_loc,(ILxUnknownID) attr, cache, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Cleanup(void *cache) -> void
    {
        m_loc[0]->Cleanup(m_loc, cache);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
