//
// C++ wrapper for lxsdk/lxcliped.h.
//
//	Copyright 2024.
//
//
#pragma once

#include <lxcliped.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx
{
    static LXtGUID const guid_ClipDest = {0x7d40b3b8, {0xc5a4, 0x4918}, {0xb8, 0xe4, 0x92, 0x2e, 0x62, 0x9c, 0x3f, 0xfc}};
} // namespace lx

class CLxImpl_ClipDest
{
public:
    virtual ~CLxImpl_ClipDest() = default;

    virtual auto locd_Item([[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual int locd_Type(void) = 0;

    virtual int locd_Location(void) = 0;
};

#define LXxD_ClipDest_Item LxResult locd_Item([[maybe_unused]] void **ppvObj) override
#define LXxO_ClipDest_Item LXxD_ClipDest_Item
#define LXxC_ClipDest_Item(c) LxResult c::locd_Item([[maybe_unused]] void **ppvObj)
#define LXxD_ClipDest_Type int locd_Type() override
#define LXxO_ClipDest_Type LXxD_ClipDest_Type
#define LXxC_ClipDest_Type(c) int c::locd_Type()
#define LXxD_ClipDest_Location int locd_Location() override
#define LXxO_ClipDest_Location LXxD_ClipDest_Location
#define LXxC_ClipDest_Location(c) int c::locd_Location()

template <class T>
class CLxIfc_ClipDest: public CLxInterface
{
public:
    CLxIfc_ClipDest()
    {
        vt.Item = Item;
        vt.Type = Type;
        vt.Location = Location;
        vTable = &vt.iunk;
        iid = &lx::guid_ClipDest;
    }

    static auto Item(LXtObjectID wcom,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_ClipDest, loc);
        try
        {
           return loc->locd_Item( ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Type(LXtObjectID wcom) -> int
    {
        LXCWxINST (CLxImpl_ClipDest, loc);
        return loc->locd_Type();
    }

    static auto Location(LXtObjectID wcom) -> int
    {
        LXCWxINST (CLxImpl_ClipDest, loc);
        return loc->locd_Location();
    }

private:
    ILxClipDest vt;
};

class CLxLoc_ClipDest : public CLxLocalize<ILxClipDestID>
{
public:
    CLxLoc_ClipDest()
    {
        _init();
    }

    CLxLoc_ClipDest(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_ClipDest(CLxLoc_ClipDest const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_ClipDest;
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

    auto Type(void) -> int
    {
        return m_loc[0]->Type(m_loc);
    }

    auto Location(void) -> int
    {
        return m_loc[0]->Location(m_loc);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
