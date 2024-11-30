//
// C++ wrapper for lxsdk/lxlocator.h.
//
//	Copyright 2024.
//
//
#pragma once

#include <lxlocator.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx
{
    static LXtGUID const guid_Locator = {0x50DCCB9D, {0x9856, 0x4A33}, {0x9B, 0xDA, 0xDA, 0xF3, 0xA7, 0x1B, 0xBD, 0x2D}};
} // namespace lx

class CLxLoc_Locator : public CLxLocalize<ILxLocatorID>
{
public:
    CLxLoc_Locator()
    {
        _init();
    }

    CLxLoc_Locator(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_Locator(CLxLoc_Locator const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_Locator;
    }

    auto Visible(ILxUnknownID chanRead) const -> LxResult
    {
        return m_loc[0]->Visible(m_loc,(ILxUnknownID) chanRead);
    }

    auto WorldTransform(ILxUnknownID chanRead, LXtMatrix xfrm, LXtVector pos) const -> LxResult
    {
        return m_loc[0]->WorldTransform(m_loc,(ILxUnknownID) chanRead, xfrm, pos);
    }

    auto GetTransformItem(LXtTransformType type, void **ppvObj) const -> LxResult
    {
        return m_loc[0]->GetTransformItem(m_loc, type, ppvObj);
    }

    auto GetTransformItem(LXtTransformType type, CLxLocalizedObject &o_dest) const -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->GetTransformItem(m_loc, type, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto AddTransformItem(LXtTransformType type, void **ppvObj, unsigned *index) -> LxResult
    {
        return m_loc[0]->AddTransformItem(m_loc, type, ppvObj, index);
    }

    auto AddTransformItem(LXtTransformType type, CLxLocalizedObject &o_dest, unsigned *index) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->AddTransformItem(m_loc, type, &o_obj, index);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto SetTransformVector(ILxUnknownID chanWrite, LXtTransformType type, const LXtVector value) -> LxResult
    {
        return m_loc[0]->SetTransformVector(m_loc,(ILxUnknownID) chanWrite, type, value);
    }

    auto AddPreTransformItem(ILxUnknownID chanWrite, LXtTransformType type, const LXtVector value, void **ppvObj, unsigned *index) -> LxResult
    {
        return m_loc[0]->AddPreTransformItem(m_loc,(ILxUnknownID) chanWrite, type, value, ppvObj, index);
    }

    auto AddPreTransformItem(ILxUnknownID chanWrite, LXtTransformType type, const LXtVector value, CLxLocalizedObject &o_dest, unsigned *index) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->AddPreTransformItem(m_loc,(ILxUnknownID) chanWrite, type, value, &o_obj, index);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto AddPostTransformItem(ILxUnknownID chanWrite, LXtTransformType type, const LXtVector value, void **ppvObj, unsigned *index) -> LxResult
    {
        return m_loc[0]->AddPostTransformItem(m_loc,(ILxUnknownID) chanWrite, type, value, ppvObj, index);
    }

    auto AddPostTransformItem(ILxUnknownID chanWrite, LXtTransformType type, const LXtVector value, CLxLocalizedObject &o_dest, unsigned *index) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->AddPostTransformItem(m_loc,(ILxUnknownID) chanWrite, type, value, &o_obj, index);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto SetTarget(ILxUnknownID target, void **ppvObj) -> LxResult
    {
        return m_loc[0]->SetTarget(m_loc,(ILxUnknownID) target, ppvObj);
    }

    auto SetTarget(ILxUnknownID target, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->SetTarget(m_loc,(ILxUnknownID) target, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto PrependTransformItem(ILxUnknownID chanWrite, LXtTransformType type, const LXtVector value, void **ppvObj, unsigned *index) -> LxResult
    {
        return m_loc[0]->PrependTransformItem(m_loc,(ILxUnknownID) chanWrite, type, value, ppvObj, index);
    }

    auto PrependTransformItem(ILxUnknownID chanWrite, LXtTransformType type, const LXtVector value, CLxLocalizedObject &o_dest, unsigned *index) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->PrependTransformItem(m_loc,(ILxUnknownID) chanWrite, type, value, &o_obj, index);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto AppendTransformItem(ILxUnknownID chanWrite, LXtTransformType type, const LXtVector value, void **ppvObj, unsigned *index) -> LxResult
    {
        return m_loc[0]->AppendTransformItem(m_loc,(ILxUnknownID) chanWrite, type, value, ppvObj, index);
    }

    auto AppendTransformItem(ILxUnknownID chanWrite, LXtTransformType type, const LXtVector value, CLxLocalizedObject &o_dest, unsigned *index) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->AppendTransformItem(m_loc,(ILxUnknownID) chanWrite, type, value, &o_obj, index);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto SetPosition(ILxUnknownID chanRead, ILxUnknownID chanWrite, const LXtVector pos, unsigned type, unsigned comp) -> LxResult
    {
        return m_loc[0]->SetPosition(m_loc,(ILxUnknownID) chanRead,(ILxUnknownID) chanWrite, pos, type, comp);
    }

    auto SetRotation(ILxUnknownID chanRead, ILxUnknownID chanWrite, const LXtMatrix m3, unsigned type, unsigned comp) -> LxResult
    {
        return m_loc[0]->SetRotation(m_loc,(ILxUnknownID) chanRead,(ILxUnknownID) chanWrite, m3, type, comp);
    }

    auto SetScale(ILxUnknownID chanRead, ILxUnknownID chanWrite, const LXtMatrix4 m4, unsigned type, unsigned comp) -> LxResult
    {
        return m_loc[0]->SetScale(m_loc,(ILxUnknownID) chanRead,(ILxUnknownID) chanWrite, m4, type, comp);
    }

    auto ExtractLocalPosition(ILxUnknownID chanRead, LXtVector pos) -> LxResult
    {
        return m_loc[0]->ExtractLocalPosition(m_loc,(ILxUnknownID) chanRead, pos);
    }

    auto ExtractLocalRotation(ILxUnknownID chanRead, LXtMatrix m3) -> LxResult
    {
        return m_loc[0]->ExtractLocalRotation(m_loc,(ILxUnknownID) chanRead, m3);
    }

    auto ZeroTransform(ILxUnknownID chanRead, ILxUnknownID chanWrite, LXtTransformType type) -> LxResult
    {
        return m_loc[0]->ZeroTransform(m_loc,(ILxUnknownID) chanRead,(ILxUnknownID) chanWrite, type);
    }

    auto WorldTransform4(ILxUnknownID chanRead, LXtMatrix4 xfrm4) const -> LxResult
    {
        return m_loc[0]->WorldTransform4(m_loc,(ILxUnknownID) chanRead, xfrm4);
    }

    auto WorldInvertTransform(ILxUnknownID chanRead, LXtMatrix xfrm, LXtVector pos) -> LxResult
    {
        return m_loc[0]->WorldInvertTransform(m_loc,(ILxUnknownID) chanRead, xfrm, pos);
    }

    auto LocalTransform(ILxUnknownID chanRead, LXtMatrix xfrm, LXtVector pos) const -> LxResult
    {
        return m_loc[0]->LocalTransform(m_loc,(ILxUnknownID) chanRead, xfrm, pos);
    }

    auto LocalTransform4(ILxUnknownID chanRead, LXtMatrix4 xfrm4) const -> LxResult
    {
        return m_loc[0]->LocalTransform4(m_loc,(ILxUnknownID) chanRead, xfrm4);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
