//
// C++ wrapper for lxsdk/lxcustomview.h.
//
//	Copyright 2024.
//
//
#pragma once

#include <lxcustomview.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx
{
    static LXtGUID const guid_CustomPane = {0x7412C685, {0x3ED9, 0x4622}, {0x91, 0x5F, 0x25, 0x31, 0x05, 0x01, 0x2B, 0xC4}};
    static LXtGUID const guid_CustomView = {0xe9af4a0d, {0x3048, 0x4ec4}, {0xb8, 0x02, 0xaa, 0x72, 0x01, 0xdf, 0xde, 0xbe}};
    static LXtGUID const guid_CustomView1 = {0xb427f640, {0x821a, 0x48ee}, {0xb7, 0xec, 0xf4, 0xaa, 0xfe, 0x79, 0x96, 0x95}};
} // namespace lx

class CLxLoc_CustomPane : public CLxLocalize<ILxCustomPaneID>
{
public:
    CLxLoc_CustomPane()
    {
        _init();
    }

    CLxLoc_CustomPane(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_CustomPane(CLxLoc_CustomPane const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_CustomPane;
    }

    auto GetParent(LXtPaneHandleID *handle) -> LxResult
    {
        return m_loc[0]->GetParent(m_loc, handle);
    }

    auto GetIdentifier(const char** ident) -> LxResult
    {
        return m_loc[0]->GetIdentifier(m_loc, ident);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_CustomView
{
public:
    virtual ~CLxImpl_CustomView() = default;

    virtual auto customview_Init([[maybe_unused]] ILxUnknownID pane) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto customview_Cleanup([[maybe_unused]] ILxUnknownID pane) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto customview_StoreState([[maybe_unused]] ILxUnknownID pane) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto customview_RestoreState([[maybe_unused]] ILxUnknownID pane) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto customview_StoreSettingsString([[maybe_unused]] char *buf, [[maybe_unused]] unsigned int len) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto customview_RestoreSettingsString([[maybe_unused]] const char *settings) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto customview_EmbeddedArgumentSetInt([[maybe_unused]] const char *name, [[maybe_unused]] int value) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto customview_EmbeddedArgumentSetFloat([[maybe_unused]] const char *name, [[maybe_unused]] double value) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto customview_EmbeddedArgumentSetString([[maybe_unused]] const char *name, [[maybe_unused]] const char *value) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto customview_EmbeddedHeight([[maybe_unused]] int width, [[maybe_unused]] int height, [[maybe_unused]] int *fixedHeight) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto customview_EmbeddedLabel([[maybe_unused]] const char *label) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto customview_EmbeddedStoreSettingsString([[maybe_unused]] char *buf, [[maybe_unused]] unsigned int len) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto customview_EmbeddedRestoreSettingsString([[maybe_unused]] const char *settings) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_CustomView_Init LxResult customview_Init([[maybe_unused]] ILxUnknownID pane) override
#define LXxO_CustomView_Init LXxD_CustomView_Init
#define LXxC_CustomView_Init(c) LxResult c::customview_Init([[maybe_unused]] ILxUnknownID pane)
#define LXxD_CustomView_Cleanup LxResult customview_Cleanup([[maybe_unused]] ILxUnknownID pane) override
#define LXxO_CustomView_Cleanup LXxD_CustomView_Cleanup
#define LXxC_CustomView_Cleanup(c) LxResult c::customview_Cleanup([[maybe_unused]] ILxUnknownID pane)
#define LXxD_CustomView_StoreState LxResult customview_StoreState([[maybe_unused]] ILxUnknownID pane) override
#define LXxO_CustomView_StoreState LXxD_CustomView_StoreState
#define LXxC_CustomView_StoreState(c) LxResult c::customview_StoreState([[maybe_unused]] ILxUnknownID pane)
#define LXxD_CustomView_RestoreState LxResult customview_RestoreState([[maybe_unused]] ILxUnknownID pane) override
#define LXxO_CustomView_RestoreState LXxD_CustomView_RestoreState
#define LXxC_CustomView_RestoreState(c) LxResult c::customview_RestoreState([[maybe_unused]] ILxUnknownID pane)
#define LXxD_CustomView_StoreSettingsString LxResult customview_StoreSettingsString([[maybe_unused]] char *buf, [[maybe_unused]] unsigned int len) override
#define LXxO_CustomView_StoreSettingsString LXxD_CustomView_StoreSettingsString
#define LXxC_CustomView_StoreSettingsString(c) LxResult c::customview_StoreSettingsString([[maybe_unused]] char *buf, [[maybe_unused]] unsigned int len)
#define LXxD_CustomView_RestoreSettingsString LxResult customview_RestoreSettingsString([[maybe_unused]] const char *settings) override
#define LXxO_CustomView_RestoreSettingsString LXxD_CustomView_RestoreSettingsString
#define LXxC_CustomView_RestoreSettingsString(c) LxResult c::customview_RestoreSettingsString([[maybe_unused]] const char *settings)
#define LXxD_CustomView_EmbeddedArgumentSetInt LxResult customview_EmbeddedArgumentSetInt([[maybe_unused]] const char *name, [[maybe_unused]] int value) override
#define LXxO_CustomView_EmbeddedArgumentSetInt LXxD_CustomView_EmbeddedArgumentSetInt
#define LXxC_CustomView_EmbeddedArgumentSetInt(c) LxResult c::customview_EmbeddedArgumentSetInt([[maybe_unused]] const char *name, [[maybe_unused]] int value)
#define LXxD_CustomView_EmbeddedArgumentSetFloat LxResult customview_EmbeddedArgumentSetFloat([[maybe_unused]] const char *name, [[maybe_unused]] double value) override
#define LXxO_CustomView_EmbeddedArgumentSetFloat LXxD_CustomView_EmbeddedArgumentSetFloat
#define LXxC_CustomView_EmbeddedArgumentSetFloat(c) LxResult c::customview_EmbeddedArgumentSetFloat([[maybe_unused]] const char *name, [[maybe_unused]] double value)
#define LXxD_CustomView_EmbeddedArgumentSetString LxResult customview_EmbeddedArgumentSetString([[maybe_unused]] const char *name, [[maybe_unused]] const char *value) override
#define LXxO_CustomView_EmbeddedArgumentSetString LXxD_CustomView_EmbeddedArgumentSetString
#define LXxC_CustomView_EmbeddedArgumentSetString(c) LxResult c::customview_EmbeddedArgumentSetString([[maybe_unused]] const char *name, [[maybe_unused]] const char *value)
#define LXxD_CustomView_EmbeddedHeight LxResult customview_EmbeddedHeight([[maybe_unused]] int width, [[maybe_unused]] int height, [[maybe_unused]] int *fixedHeight) override
#define LXxO_CustomView_EmbeddedHeight LXxD_CustomView_EmbeddedHeight
#define LXxC_CustomView_EmbeddedHeight(c) LxResult c::customview_EmbeddedHeight([[maybe_unused]] int width, [[maybe_unused]] int height, [[maybe_unused]] int *fixedHeight)
#define LXxD_CustomView_EmbeddedLabel LxResult customview_EmbeddedLabel([[maybe_unused]] const char *label) override
#define LXxO_CustomView_EmbeddedLabel LXxD_CustomView_EmbeddedLabel
#define LXxC_CustomView_EmbeddedLabel(c) LxResult c::customview_EmbeddedLabel([[maybe_unused]] const char *label)
#define LXxD_CustomView_EmbeddedStoreSettingsString LxResult customview_EmbeddedStoreSettingsString([[maybe_unused]] char *buf, [[maybe_unused]] unsigned int len) override
#define LXxO_CustomView_EmbeddedStoreSettingsString LXxD_CustomView_EmbeddedStoreSettingsString
#define LXxC_CustomView_EmbeddedStoreSettingsString(c) LxResult c::customview_EmbeddedStoreSettingsString([[maybe_unused]] char *buf, [[maybe_unused]] unsigned int len)
#define LXxD_CustomView_EmbeddedRestoreSettingsString LxResult customview_EmbeddedRestoreSettingsString([[maybe_unused]] const char *settings) override
#define LXxO_CustomView_EmbeddedRestoreSettingsString LXxD_CustomView_EmbeddedRestoreSettingsString
#define LXxC_CustomView_EmbeddedRestoreSettingsString(c) LxResult c::customview_EmbeddedRestoreSettingsString([[maybe_unused]] const char *settings)

template <class T>
class CLxIfc_CustomView: public CLxInterface
{
public:
    CLxIfc_CustomView()
    {
        vt.Init = Init;
        vt.Cleanup = Cleanup;
        vt.StoreState = StoreState;
        vt.RestoreState = RestoreState;
        vt.StoreSettingsString = StoreSettingsString;
        vt.RestoreSettingsString = RestoreSettingsString;
        vt.EmbeddedArgumentSetInt = EmbeddedArgumentSetInt;
        vt.EmbeddedArgumentSetFloat = EmbeddedArgumentSetFloat;
        vt.EmbeddedArgumentSetString = EmbeddedArgumentSetString;
        vt.EmbeddedHeight = EmbeddedHeight;
        vt.EmbeddedLabel = EmbeddedLabel;
        vt.EmbeddedStoreSettingsString = EmbeddedStoreSettingsString;
        vt.EmbeddedRestoreSettingsString = EmbeddedRestoreSettingsString;
        vTable = &vt.iunk;
        iid = &lx::guid_CustomView;
    }

    static auto Init(LXtObjectID wcom,LXtObjectID pane) -> LxResult
    {
        LXCWxINST (CLxImpl_CustomView, loc);
        try
        {
           return loc->customview_Init((ILxUnknownID) pane);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Cleanup(LXtObjectID wcom,LXtObjectID pane) -> LxResult
    {
        LXCWxINST (CLxImpl_CustomView, loc);
        try
        {
           return loc->customview_Cleanup((ILxUnknownID) pane);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto StoreState(LXtObjectID wcom,LXtObjectID pane) -> LxResult
    {
        LXCWxINST (CLxImpl_CustomView, loc);
        try
        {
           return loc->customview_StoreState((ILxUnknownID) pane);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto RestoreState(LXtObjectID wcom,LXtObjectID pane) -> LxResult
    {
        LXCWxINST (CLxImpl_CustomView, loc);
        try
        {
           return loc->customview_RestoreState((ILxUnknownID) pane);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto StoreSettingsString(LXtObjectID wcom,char *buf,unsigned int len) -> LxResult
    {
        LXCWxINST (CLxImpl_CustomView, loc);
        try
        {
           return loc->customview_StoreSettingsString( buf, len);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto RestoreSettingsString(LXtObjectID wcom,const char *settings) -> LxResult
    {
        LXCWxINST (CLxImpl_CustomView, loc);
        try
        {
           return loc->customview_RestoreSettingsString( settings);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto EmbeddedArgumentSetInt(LXtObjectID wcom,const char *name,int value) -> LxResult
    {
        LXCWxINST (CLxImpl_CustomView, loc);
        try
        {
           return loc->customview_EmbeddedArgumentSetInt( name, value);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto EmbeddedArgumentSetFloat(LXtObjectID wcom,const char *name,double value) -> LxResult
    {
        LXCWxINST (CLxImpl_CustomView, loc);
        try
        {
           return loc->customview_EmbeddedArgumentSetFloat( name, value);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto EmbeddedArgumentSetString(LXtObjectID wcom,const char *name,const char *value) -> LxResult
    {
        LXCWxINST (CLxImpl_CustomView, loc);
        try
        {
           return loc->customview_EmbeddedArgumentSetString( name, value);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto EmbeddedHeight(LXtObjectID wcom,int width,int height,int *fixedHeight) -> LxResult
    {
        LXCWxINST (CLxImpl_CustomView, loc);
        try
        {
           return loc->customview_EmbeddedHeight( width, height, fixedHeight);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto EmbeddedLabel(LXtObjectID wcom,const char *label) -> LxResult
    {
        LXCWxINST (CLxImpl_CustomView, loc);
        try
        {
           return loc->customview_EmbeddedLabel( label);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto EmbeddedStoreSettingsString(LXtObjectID wcom,char *buf,unsigned int len) -> LxResult
    {
        LXCWxINST (CLxImpl_CustomView, loc);
        try
        {
           return loc->customview_EmbeddedStoreSettingsString( buf, len);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto EmbeddedRestoreSettingsString(LXtObjectID wcom,const char *settings) -> LxResult
    {
        LXCWxINST (CLxImpl_CustomView, loc);
        try
        {
           return loc->customview_EmbeddedRestoreSettingsString( settings);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxCustomView vt;
};

class CLxLoc_CustomView : public CLxLocalize<ILxCustomViewID>
{
public:
    CLxLoc_CustomView()
    {
        _init();
    }

    CLxLoc_CustomView(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_CustomView(CLxLoc_CustomView const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_CustomView;
    }

    auto Init(ILxUnknownID pane) -> LxResult
    {
        return m_loc[0]->Init(m_loc,(ILxUnknownID) pane);
    }

    auto Cleanup(ILxUnknownID pane) -> LxResult
    {
        return m_loc[0]->Cleanup(m_loc,(ILxUnknownID) pane);
    }

    auto StoreState(ILxUnknownID pane) -> LxResult
    {
        return m_loc[0]->StoreState(m_loc,(ILxUnknownID) pane);
    }

    auto RestoreState(ILxUnknownID pane) -> LxResult
    {
        return m_loc[0]->RestoreState(m_loc,(ILxUnknownID) pane);
    }

    auto StoreSettingsString(char *buf, unsigned int len) -> LxResult
    {
        return m_loc[0]->StoreSettingsString(m_loc, buf, len);
    }

    auto StoreSettingsString(std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->StoreSettingsString(m_loc, buf, len);
        LXWx_SBUF2
    }

    auto RestoreSettingsString(const char *settings) -> LxResult
    {
        return m_loc[0]->RestoreSettingsString(m_loc, settings);
    }

    auto EmbeddedArgumentSetInt(const char *name, int value) -> LxResult
    {
        return m_loc[0]->EmbeddedArgumentSetInt(m_loc, name, value);
    }

    auto EmbeddedArgumentSetFloat(const char *name, double value) -> LxResult
    {
        return m_loc[0]->EmbeddedArgumentSetFloat(m_loc, name, value);
    }

    auto EmbeddedArgumentSetString(const char *name, const char *value) -> LxResult
    {
        return m_loc[0]->EmbeddedArgumentSetString(m_loc, name, value);
    }

    auto EmbeddedHeight(int width, int height, int *fixedHeight) -> LxResult
    {
        return m_loc[0]->EmbeddedHeight(m_loc, width, height, fixedHeight);
    }

    auto EmbeddedLabel(const char *label) -> LxResult
    {
        return m_loc[0]->EmbeddedLabel(m_loc, label);
    }

    auto EmbeddedStoreSettingsString(char *buf, unsigned int len) -> LxResult
    {
        return m_loc[0]->EmbeddedStoreSettingsString(m_loc, buf, len);
    }

    auto EmbeddedStoreSettingsString(std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->EmbeddedStoreSettingsString(m_loc, buf, len);
        LXWx_SBUF2
    }

    auto EmbeddedRestoreSettingsString(const char *settings) -> LxResult
    {
        return m_loc[0]->EmbeddedRestoreSettingsString(m_loc, settings);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_CustomView1
{
public:
    virtual ~CLxImpl_CustomView1() = default;

    virtual auto customview1_Init([[maybe_unused]] ILxUnknownID pane) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto customview1_Cleanup([[maybe_unused]] ILxUnknownID pane) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto customview1_StoreState([[maybe_unused]] ILxUnknownID pane) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto customview1_RestoreState([[maybe_unused]] ILxUnknownID pane) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_CustomView1_Init LxResult customview1_Init([[maybe_unused]] ILxUnknownID pane) override
#define LXxO_CustomView1_Init LXxD_CustomView1_Init
#define LXxC_CustomView1_Init(c) LxResult c::customview1_Init([[maybe_unused]] ILxUnknownID pane)
#define LXxD_CustomView1_Cleanup LxResult customview1_Cleanup([[maybe_unused]] ILxUnknownID pane) override
#define LXxO_CustomView1_Cleanup LXxD_CustomView1_Cleanup
#define LXxC_CustomView1_Cleanup(c) LxResult c::customview1_Cleanup([[maybe_unused]] ILxUnknownID pane)
#define LXxD_CustomView1_StoreState LxResult customview1_StoreState([[maybe_unused]] ILxUnknownID pane) override
#define LXxO_CustomView1_StoreState LXxD_CustomView1_StoreState
#define LXxC_CustomView1_StoreState(c) LxResult c::customview1_StoreState([[maybe_unused]] ILxUnknownID pane)
#define LXxD_CustomView1_RestoreState LxResult customview1_RestoreState([[maybe_unused]] ILxUnknownID pane) override
#define LXxO_CustomView1_RestoreState LXxD_CustomView1_RestoreState
#define LXxC_CustomView1_RestoreState(c) LxResult c::customview1_RestoreState([[maybe_unused]] ILxUnknownID pane)

template <class T>
class CLxIfc_CustomView1: public CLxInterface
{
public:
    CLxIfc_CustomView1()
    {
        vt.Init = Init;
        vt.Cleanup = Cleanup;
        vt.StoreState = StoreState;
        vt.RestoreState = RestoreState;
        vTable = &vt.iunk;
        iid = &lx::guid_CustomView1;
    }

    static auto Init(LXtObjectID wcom,LXtObjectID pane) -> LxResult
    {
        LXCWxINST (CLxImpl_CustomView1, loc);
        try
        {
           return loc->customview1_Init((ILxUnknownID) pane);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Cleanup(LXtObjectID wcom,LXtObjectID pane) -> LxResult
    {
        LXCWxINST (CLxImpl_CustomView1, loc);
        try
        {
           return loc->customview1_Cleanup((ILxUnknownID) pane);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto StoreState(LXtObjectID wcom,LXtObjectID pane) -> LxResult
    {
        LXCWxINST (CLxImpl_CustomView1, loc);
        try
        {
           return loc->customview1_StoreState((ILxUnknownID) pane);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto RestoreState(LXtObjectID wcom,LXtObjectID pane) -> LxResult
    {
        LXCWxINST (CLxImpl_CustomView1, loc);
        try
        {
           return loc->customview1_RestoreState((ILxUnknownID) pane);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxCustomView1 vt;
};

class CLxLoc_CustomView1 : public CLxLocalize<ILxCustomView1ID>
{
public:
    CLxLoc_CustomView1()
    {
        _init();
    }

    CLxLoc_CustomView1(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_CustomView1(CLxLoc_CustomView1 const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_CustomView1;
    }

    auto Init(ILxUnknownID pane) -> LxResult
    {
        return m_loc[0]->Init(m_loc,(ILxUnknownID) pane);
    }

    auto Cleanup(ILxUnknownID pane) -> LxResult
    {
        return m_loc[0]->Cleanup(m_loc,(ILxUnknownID) pane);
    }

    auto StoreState(ILxUnknownID pane) -> LxResult
    {
        return m_loc[0]->StoreState(m_loc,(ILxUnknownID) pane);
    }

    auto RestoreState(ILxUnknownID pane) -> LxResult
    {
        return m_loc[0]->RestoreState(m_loc,(ILxUnknownID) pane);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
