//
// C++ wrapper for lxsdk/lxviewobject.h.
//
//	Copyright 2024.
//
//
#pragma once

#include <lxviewobject.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx
{
    static LXtGUID const guid_ViewObject = {0x81C986D1, {0xA7BA, 0x4278}, {0xB0, 0x60, 0xE7, 0x84, 0x77, 0x9F, 0x5C, 0x36}};
} // namespace lx

class CLxImpl_ViewObject
{
public:
    virtual ~CLxImpl_ViewObject() = default;

    virtual auto viewobj_TestMode([[maybe_unused]] unsigned int type) -> LxResult
    {
        return LXe_NOTAVAILABLE;
    }

    virtual auto viewobj_TestModeSet([[maybe_unused]] const unsigned int* passTypes, [[maybe_unused]] unsigned int passTypeCount) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto viewobj_Flags([[maybe_unused]] void) -> unsigned int
    {
        return 0;
    }

    virtual void viewobj_Generate([[maybe_unused]] unsigned int type)
    {
    }

    virtual void viewobj_GenerateSet([[maybe_unused]] const unsigned int* types, [[maybe_unused]] unsigned int typeCount)
    {
    }

    virtual auto viewobj_Count([[maybe_unused]] unsigned int type) -> unsigned int
    {
        return 0;
    }

    virtual auto viewobj_ByIndex([[maybe_unused]] unsigned int type, [[maybe_unused]] unsigned int index, [[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto viewobj_Root([[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_ViewObject_TestMode LxResult viewobj_TestMode([[maybe_unused]] unsigned int type) override
#define LXxO_ViewObject_TestMode LXxD_ViewObject_TestMode
#define LXxC_ViewObject_TestMode(c) LxResult c::viewobj_TestMode([[maybe_unused]] unsigned int type)
#define LXxD_ViewObject_TestModeSet LxResult viewobj_TestModeSet([[maybe_unused]] const unsigned int* passTypes, [[maybe_unused]] unsigned int passTypeCount) override
#define LXxO_ViewObject_TestModeSet LXxD_ViewObject_TestModeSet
#define LXxC_ViewObject_TestModeSet(c) LxResult c::viewobj_TestModeSet([[maybe_unused]] const unsigned int* passTypes, [[maybe_unused]] unsigned int passTypeCount)
#define LXxD_ViewObject_Flags unsigned int viewobj_Flags() override
#define LXxO_ViewObject_Flags LXxD_ViewObject_Flags
#define LXxC_ViewObject_Flags(c) unsigned int c::viewobj_Flags()
#define LXxD_ViewObject_Generate void viewobj_Generate([[maybe_unused]] unsigned int type) override
#define LXxO_ViewObject_Generate LXxD_ViewObject_Generate
#define LXxC_ViewObject_Generate(c) void c::viewobj_Generate([[maybe_unused]] unsigned int type)
#define LXxD_ViewObject_GenerateSet void viewobj_GenerateSet([[maybe_unused]] const unsigned int* types, [[maybe_unused]] unsigned int typeCount) override
#define LXxO_ViewObject_GenerateSet LXxD_ViewObject_GenerateSet
#define LXxC_ViewObject_GenerateSet(c) void c::viewobj_GenerateSet([[maybe_unused]] const unsigned int* types, [[maybe_unused]] unsigned int typeCount)
#define LXxD_ViewObject_Count unsigned int viewobj_Count([[maybe_unused]] unsigned int type) override
#define LXxO_ViewObject_Count LXxD_ViewObject_Count
#define LXxC_ViewObject_Count(c) unsigned int c::viewobj_Count([[maybe_unused]] unsigned int type)
#define LXxD_ViewObject_ByIndex LxResult viewobj_ByIndex([[maybe_unused]] unsigned int type, [[maybe_unused]] unsigned int index, [[maybe_unused]] void **ppvObj) override
#define LXxO_ViewObject_ByIndex LXxD_ViewObject_ByIndex
#define LXxC_ViewObject_ByIndex(c) LxResult c::viewobj_ByIndex([[maybe_unused]] unsigned int type, [[maybe_unused]] unsigned int index, [[maybe_unused]] void **ppvObj)
#define LXxD_ViewObject_Root LxResult viewobj_Root([[maybe_unused]] void **ppvObj) override
#define LXxO_ViewObject_Root LXxD_ViewObject_Root
#define LXxC_ViewObject_Root(c) LxResult c::viewobj_Root([[maybe_unused]] void **ppvObj)

template <class T>
class CLxIfc_ViewObject: public CLxInterface
{
public:
    CLxIfc_ViewObject()
    {
        vt.TestMode = TestMode;
        vt.TestModeSet = TestModeSet;
        vt.Flags = Flags;
        vt.Generate = Generate;
        vt.GenerateSet = GenerateSet;
        vt.Count = Count;
        vt.ByIndex = ByIndex;
        vt.Root = Root;
        vTable = &vt.iunk;
        iid = &lx::guid_ViewObject;
    }

    static auto TestMode(LXtObjectID wcom,unsigned int type) -> LxResult
    {
        LXCWxINST (CLxImpl_ViewObject, loc);
        try
        {
           return loc->viewobj_TestMode( type);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto TestModeSet(LXtObjectID wcom,const unsigned int* passTypes,unsigned int passTypeCount) -> LxResult
    {
        LXCWxINST (CLxImpl_ViewObject, loc);
        try
        {
           return loc->viewobj_TestModeSet( passTypes, passTypeCount);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Flags(LXtObjectID wcom) -> unsigned int
    {
        LXCWxINST (CLxImpl_ViewObject, loc);
        return loc->viewobj_Flags();
    }

    static auto Generate(LXtObjectID wcom,unsigned int type) -> void
    {
        LXCWxINST (CLxImpl_ViewObject, loc);
        loc->viewobj_Generate( type);
    }

    static auto GenerateSet(LXtObjectID wcom,const unsigned int* types,unsigned int typeCount) -> void
    {
        LXCWxINST (CLxImpl_ViewObject, loc);
        loc->viewobj_GenerateSet( types, typeCount);
    }

    static auto Count(LXtObjectID wcom,unsigned int type) -> unsigned int
    {
        LXCWxINST (CLxImpl_ViewObject, loc);
        return loc->viewobj_Count( type);
    }

    static auto ByIndex(LXtObjectID wcom,unsigned int type,unsigned int index,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_ViewObject, loc);
        try
        {
           return loc->viewobj_ByIndex( type, index, ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Root(LXtObjectID wcom,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_ViewObject, loc);
        try
        {
           return loc->viewobj_Root( ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxViewObject vt;
};

class CLxLoc_ViewObject : public CLxLocalize<ILxViewObjectID>
{
public:
    CLxLoc_ViewObject()
    {
        _init();
    }

    CLxLoc_ViewObject(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_ViewObject(CLxLoc_ViewObject const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_ViewObject;
    }

    auto TestMode(unsigned int type) -> LxResult
    {
        return m_loc[0]->TestMode(m_loc, type);
    }

    auto TestModeSet(const unsigned int* passTypes, unsigned int passTypeCount) -> LxResult
    {
        return m_loc[0]->TestModeSet(m_loc, passTypes, passTypeCount);
    }

    auto Flags(void) -> unsigned int
    {
        return m_loc[0]->Flags(m_loc);
    }

    auto Generate(unsigned int type) -> void
    {
        m_loc[0]->Generate(m_loc, type);
    }

    auto GenerateSet(const unsigned int* types, unsigned int typeCount) -> void
    {
        m_loc[0]->GenerateSet(m_loc, types, typeCount);
    }

    auto Count(unsigned int type) -> unsigned int
    {
        return m_loc[0]->Count(m_loc, type);
    }

    auto ByIndex(unsigned int type, unsigned int index, void **ppvObj) -> LxResult
    {
        return m_loc[0]->ByIndex(m_loc, type, index, ppvObj);
    }

    auto ByIndex(unsigned int type, unsigned int index, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->ByIndex(m_loc, type, index, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Root(void **ppvObj) -> LxResult
    {
        return m_loc[0]->Root(m_loc, ppvObj);
    }

    auto Root(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Root(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
