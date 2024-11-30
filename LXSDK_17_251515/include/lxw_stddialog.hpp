//
// C++ wrapper for lxsdk/lxstddialog.h.
//
//	Copyright 2024.
//
//
#pragma once

#include <lxstddialog.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx
{
    static LXtGUID const guid_AsyncMonitorInfo = {0x79f3c06f, {0xf36d, 0x477d}, {0xb9, 0x46, 0xf6, 0xf7, 0x8a, 0x83, 0x82, 0x30}};
    static LXtGUID const guid_AsyncMonitorInfo1 = {0xadf5bb35, {0x7180, 0x4d6e}, {0x93, 0x48, 0x49, 0x20, 0x6a, 0xe7, 0xe6, 0xca}};
    static LXtGUID const guid_AsyncMonitorSystem = {0xc573842a, {0xd4fd, 0x48eb}, {0x8f, 0xb0, 0x07, 0x8a, 0x72, 0x1e, 0x5e, 0x0f}};
    static LXtGUID const guid_ColorDialog = {0x2AB01AAE, {0x110B, 0x11DF}, {0xBF, 0xD0, 0x0A, 0xC7, 0x56, 0xD8, 0x95, 0x93}};
    static LXtGUID const guid_StdDialogService = {0xA78FA063, {0x6C8D, 0x471f}, {0x89, 0x81, 0x6B, 0xAE, 0xFF, 0x62, 0xBE, 0xE3}};
    static LXtGUID const guid_FileDialogClient = {0x77F97D4C, {0x8AF9, 0x4E3A}, {0xAA, 0x58, 0xE8, 0x41, 0x89, 0x90, 0xFC, 0xA8}};
} // namespace lx

class CLxImpl_AsyncMonitorInfo
{
public:
    virtual ~CLxImpl_AsyncMonitorInfo() = default;

    virtual auto amonsys_System([[maybe_unused]] const char **system) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto amonsys_Title([[maybe_unused]] const char **title) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto amonsys_Progress([[maybe_unused]] double *progress) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto amonsys_OverallProgress([[maybe_unused]] double *progress) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto amonsys_Parent([[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto amonsys_Child([[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto amonsys_Identifier([[maybe_unused]] const char **ident) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto amonsys_CanAbort([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto amonsys_Abort([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto amonsys_IsAborted([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_AsyncMonitorInfo_System LxResult amonsys_System([[maybe_unused]] const char **system) override
#define LXxO_AsyncMonitorInfo_System LXxD_AsyncMonitorInfo_System
#define LXxC_AsyncMonitorInfo_System(c) LxResult c::amonsys_System([[maybe_unused]] const char **system)
#define LXxD_AsyncMonitorInfo_Title LxResult amonsys_Title([[maybe_unused]] const char **title) override
#define LXxO_AsyncMonitorInfo_Title LXxD_AsyncMonitorInfo_Title
#define LXxC_AsyncMonitorInfo_Title(c) LxResult c::amonsys_Title([[maybe_unused]] const char **title)
#define LXxD_AsyncMonitorInfo_Progress LxResult amonsys_Progress([[maybe_unused]] double *progress) override
#define LXxO_AsyncMonitorInfo_Progress LXxD_AsyncMonitorInfo_Progress
#define LXxC_AsyncMonitorInfo_Progress(c) LxResult c::amonsys_Progress([[maybe_unused]] double *progress)
#define LXxD_AsyncMonitorInfo_OverallProgress LxResult amonsys_OverallProgress([[maybe_unused]] double *progress) override
#define LXxO_AsyncMonitorInfo_OverallProgress LXxD_AsyncMonitorInfo_OverallProgress
#define LXxC_AsyncMonitorInfo_OverallProgress(c) LxResult c::amonsys_OverallProgress([[maybe_unused]] double *progress)
#define LXxD_AsyncMonitorInfo_Parent LxResult amonsys_Parent([[maybe_unused]] void **ppvObj) override
#define LXxO_AsyncMonitorInfo_Parent LXxD_AsyncMonitorInfo_Parent
#define LXxC_AsyncMonitorInfo_Parent(c) LxResult c::amonsys_Parent([[maybe_unused]] void **ppvObj)
#define LXxD_AsyncMonitorInfo_Child LxResult amonsys_Child([[maybe_unused]] void **ppvObj) override
#define LXxO_AsyncMonitorInfo_Child LXxD_AsyncMonitorInfo_Child
#define LXxC_AsyncMonitorInfo_Child(c) LxResult c::amonsys_Child([[maybe_unused]] void **ppvObj)
#define LXxD_AsyncMonitorInfo_Identifier LxResult amonsys_Identifier([[maybe_unused]] const char **ident) override
#define LXxO_AsyncMonitorInfo_Identifier LXxD_AsyncMonitorInfo_Identifier
#define LXxC_AsyncMonitorInfo_Identifier(c) LxResult c::amonsys_Identifier([[maybe_unused]] const char **ident)
#define LXxD_AsyncMonitorInfo_CanAbort LxResult amonsys_CanAbort() override
#define LXxO_AsyncMonitorInfo_CanAbort LXxD_AsyncMonitorInfo_CanAbort
#define LXxC_AsyncMonitorInfo_CanAbort(c) LxResult c::amonsys_CanAbort()
#define LXxD_AsyncMonitorInfo_Abort LxResult amonsys_Abort() override
#define LXxO_AsyncMonitorInfo_Abort LXxD_AsyncMonitorInfo_Abort
#define LXxC_AsyncMonitorInfo_Abort(c) LxResult c::amonsys_Abort()
#define LXxD_AsyncMonitorInfo_IsAborted LxResult amonsys_IsAborted() override
#define LXxO_AsyncMonitorInfo_IsAborted LXxD_AsyncMonitorInfo_IsAborted
#define LXxC_AsyncMonitorInfo_IsAborted(c) LxResult c::amonsys_IsAborted()

template <class T>
class CLxIfc_AsyncMonitorInfo: public CLxInterface
{
public:
    CLxIfc_AsyncMonitorInfo()
    {
        vt.System = System;
        vt.Title = Title;
        vt.Progress = Progress;
        vt.OverallProgress = OverallProgress;
        vt.Parent = Parent;
        vt.Child = Child;
        vt.Identifier = Identifier;
        vt.CanAbort = CanAbort;
        vt.Abort = Abort;
        vt.IsAborted = IsAborted;
        vTable = &vt.iunk;
        iid = &lx::guid_AsyncMonitorInfo;
    }

    static auto System(LXtObjectID wcom,const char **system) -> LxResult
    {
        LXCWxINST (CLxImpl_AsyncMonitorInfo, loc);
        try
        {
           return loc->amonsys_System( system);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Title(LXtObjectID wcom,const char **title) -> LxResult
    {
        LXCWxINST (CLxImpl_AsyncMonitorInfo, loc);
        try
        {
           return loc->amonsys_Title( title);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Progress(LXtObjectID wcom,double *progress) -> LxResult
    {
        LXCWxINST (CLxImpl_AsyncMonitorInfo, loc);
        try
        {
           return loc->amonsys_Progress( progress);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto OverallProgress(LXtObjectID wcom,double *progress) -> LxResult
    {
        LXCWxINST (CLxImpl_AsyncMonitorInfo, loc);
        try
        {
           return loc->amonsys_OverallProgress( progress);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Parent(LXtObjectID wcom,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_AsyncMonitorInfo, loc);
        try
        {
           return loc->amonsys_Parent( ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Child(LXtObjectID wcom,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_AsyncMonitorInfo, loc);
        try
        {
           return loc->amonsys_Child( ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Identifier(LXtObjectID wcom,const char **ident) -> LxResult
    {
        LXCWxINST (CLxImpl_AsyncMonitorInfo, loc);
        try
        {
           return loc->amonsys_Identifier( ident);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto CanAbort(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_AsyncMonitorInfo, loc);
        try
        {
           return loc->amonsys_CanAbort();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Abort(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_AsyncMonitorInfo, loc);
        try
        {
           return loc->amonsys_Abort();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto IsAborted(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_AsyncMonitorInfo, loc);
        try
        {
           return loc->amonsys_IsAborted();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxAsyncMonitorInfo vt;
};

class CLxLoc_AsyncMonitorInfo : public CLxLocalize<ILxAsyncMonitorInfoID>
{
public:
    CLxLoc_AsyncMonitorInfo()
    {
        _init();
    }

    CLxLoc_AsyncMonitorInfo(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_AsyncMonitorInfo(CLxLoc_AsyncMonitorInfo const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_AsyncMonitorInfo;
    }

    auto System(const char **system) -> LxResult
    {
        return m_loc[0]->System(m_loc, system);
    }

    auto Title(const char **title) -> LxResult
    {
        return m_loc[0]->Title(m_loc, title);
    }

    auto Progress(double *progress) -> LxResult
    {
        return m_loc[0]->Progress(m_loc, progress);
    }

    auto OverallProgress(double *progress) -> LxResult
    {
        return m_loc[0]->OverallProgress(m_loc, progress);
    }

    auto Parent(void **ppvObj) -> LxResult
    {
        return m_loc[0]->Parent(m_loc, ppvObj);
    }

    auto Parent(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Parent(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Child(void **ppvObj) -> LxResult
    {
        return m_loc[0]->Child(m_loc, ppvObj);
    }

    auto Child(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Child(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Identifier(const char **ident) -> LxResult
    {
        return m_loc[0]->Identifier(m_loc, ident);
    }

    auto CanAbort(void) -> LxResult
    {
        return m_loc[0]->CanAbort(m_loc);
    }

    auto Abort(void) -> LxResult
    {
        return m_loc[0]->Abort(m_loc);
    }

    auto IsAborted(void) -> LxResult
    {
        return m_loc[0]->IsAborted(m_loc);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_AsyncMonitorInfo1
{
public:
    virtual ~CLxImpl_AsyncMonitorInfo1() = default;

    virtual auto asy_System([[maybe_unused]] const char **system) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto asy_Title([[maybe_unused]] const char **title) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto asy_Progress([[maybe_unused]] double *progress) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto asy_OverallProgress([[maybe_unused]] double *progress) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto asy_Parent([[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto asy_Child([[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto asy_Identifier([[maybe_unused]] const char **ident) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto asy_Abort([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto asy_IsAborted([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_AsyncMonitorInfo1_System LxResult asy_System([[maybe_unused]] const char **system) override
#define LXxO_AsyncMonitorInfo1_System LXxD_AsyncMonitorInfo1_System
#define LXxC_AsyncMonitorInfo1_System(c) LxResult c::asy_System([[maybe_unused]] const char **system)
#define LXxD_AsyncMonitorInfo1_Title LxResult asy_Title([[maybe_unused]] const char **title) override
#define LXxO_AsyncMonitorInfo1_Title LXxD_AsyncMonitorInfo1_Title
#define LXxC_AsyncMonitorInfo1_Title(c) LxResult c::asy_Title([[maybe_unused]] const char **title)
#define LXxD_AsyncMonitorInfo1_Progress LxResult asy_Progress([[maybe_unused]] double *progress) override
#define LXxO_AsyncMonitorInfo1_Progress LXxD_AsyncMonitorInfo1_Progress
#define LXxC_AsyncMonitorInfo1_Progress(c) LxResult c::asy_Progress([[maybe_unused]] double *progress)
#define LXxD_AsyncMonitorInfo1_OverallProgress LxResult asy_OverallProgress([[maybe_unused]] double *progress) override
#define LXxO_AsyncMonitorInfo1_OverallProgress LXxD_AsyncMonitorInfo1_OverallProgress
#define LXxC_AsyncMonitorInfo1_OverallProgress(c) LxResult c::asy_OverallProgress([[maybe_unused]] double *progress)
#define LXxD_AsyncMonitorInfo1_Parent LxResult asy_Parent([[maybe_unused]] void **ppvObj) override
#define LXxO_AsyncMonitorInfo1_Parent LXxD_AsyncMonitorInfo1_Parent
#define LXxC_AsyncMonitorInfo1_Parent(c) LxResult c::asy_Parent([[maybe_unused]] void **ppvObj)
#define LXxD_AsyncMonitorInfo1_Child LxResult asy_Child([[maybe_unused]] void **ppvObj) override
#define LXxO_AsyncMonitorInfo1_Child LXxD_AsyncMonitorInfo1_Child
#define LXxC_AsyncMonitorInfo1_Child(c) LxResult c::asy_Child([[maybe_unused]] void **ppvObj)
#define LXxD_AsyncMonitorInfo1_Identifier LxResult asy_Identifier([[maybe_unused]] const char **ident) override
#define LXxO_AsyncMonitorInfo1_Identifier LXxD_AsyncMonitorInfo1_Identifier
#define LXxC_AsyncMonitorInfo1_Identifier(c) LxResult c::asy_Identifier([[maybe_unused]] const char **ident)
#define LXxD_AsyncMonitorInfo1_Abort LxResult asy_Abort() override
#define LXxO_AsyncMonitorInfo1_Abort LXxD_AsyncMonitorInfo1_Abort
#define LXxC_AsyncMonitorInfo1_Abort(c) LxResult c::asy_Abort()
#define LXxD_AsyncMonitorInfo1_IsAborted LxResult asy_IsAborted() override
#define LXxO_AsyncMonitorInfo1_IsAborted LXxD_AsyncMonitorInfo1_IsAborted
#define LXxC_AsyncMonitorInfo1_IsAborted(c) LxResult c::asy_IsAborted()

template <class T>
class CLxIfc_AsyncMonitorInfo1: public CLxInterface
{
public:
    CLxIfc_AsyncMonitorInfo1()
    {
        vt.System = System;
        vt.Title = Title;
        vt.Progress = Progress;
        vt.OverallProgress = OverallProgress;
        vt.Parent = Parent;
        vt.Child = Child;
        vt.Identifier = Identifier;
        vt.Abort = Abort;
        vt.IsAborted = IsAborted;
        vTable = &vt.iunk;
        iid = &lx::guid_AsyncMonitorInfo1;
    }

    static auto System(LXtObjectID wcom,const char **system) -> LxResult
    {
        LXCWxINST (CLxImpl_AsyncMonitorInfo1, loc);
        try
        {
           return loc->asy_System( system);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Title(LXtObjectID wcom,const char **title) -> LxResult
    {
        LXCWxINST (CLxImpl_AsyncMonitorInfo1, loc);
        try
        {
           return loc->asy_Title( title);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Progress(LXtObjectID wcom,double *progress) -> LxResult
    {
        LXCWxINST (CLxImpl_AsyncMonitorInfo1, loc);
        try
        {
           return loc->asy_Progress( progress);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto OverallProgress(LXtObjectID wcom,double *progress) -> LxResult
    {
        LXCWxINST (CLxImpl_AsyncMonitorInfo1, loc);
        try
        {
           return loc->asy_OverallProgress( progress);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Parent(LXtObjectID wcom,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_AsyncMonitorInfo1, loc);
        try
        {
           return loc->asy_Parent( ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Child(LXtObjectID wcom,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_AsyncMonitorInfo1, loc);
        try
        {
           return loc->asy_Child( ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Identifier(LXtObjectID wcom,const char **ident) -> LxResult
    {
        LXCWxINST (CLxImpl_AsyncMonitorInfo1, loc);
        try
        {
           return loc->asy_Identifier( ident);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Abort(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_AsyncMonitorInfo1, loc);
        try
        {
           return loc->asy_Abort();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto IsAborted(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_AsyncMonitorInfo1, loc);
        try
        {
           return loc->asy_IsAborted();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxAsyncMonitorInfo1 vt;
};

class CLxLoc_AsyncMonitorInfo1 : public CLxLocalize<ILxAsyncMonitorInfo1ID>
{
public:
    CLxLoc_AsyncMonitorInfo1()
    {
        _init();
    }

    CLxLoc_AsyncMonitorInfo1(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_AsyncMonitorInfo1(CLxLoc_AsyncMonitorInfo1 const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_AsyncMonitorInfo1;
    }

    auto System(const char **system) -> LxResult
    {
        return m_loc[0]->System(m_loc, system);
    }

    auto Title(const char **title) -> LxResult
    {
        return m_loc[0]->Title(m_loc, title);
    }

    auto Progress(double *progress) -> LxResult
    {
        return m_loc[0]->Progress(m_loc, progress);
    }

    auto OverallProgress(double *progress) -> LxResult
    {
        return m_loc[0]->OverallProgress(m_loc, progress);
    }

    auto Parent(void **ppvObj) -> LxResult
    {
        return m_loc[0]->Parent(m_loc, ppvObj);
    }

    auto Parent(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Parent(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Child(void **ppvObj) -> LxResult
    {
        return m_loc[0]->Child(m_loc, ppvObj);
    }

    auto Child(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Child(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Identifier(const char **ident) -> LxResult
    {
        return m_loc[0]->Identifier(m_loc, ident);
    }

    auto Abort(void) -> LxResult
    {
        return m_loc[0]->Abort(m_loc);
    }

    auto IsAborted(void) -> LxResult
    {
        return m_loc[0]->IsAborted(m_loc);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_AsyncMonitorSystem : public CLxLocalize<ILxAsyncMonitorSystemID>
{
public:
    CLxLoc_AsyncMonitorSystem()
    {
        _init();
    }

    CLxLoc_AsyncMonitorSystem(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_AsyncMonitorSystem(CLxLoc_AsyncMonitorSystem const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_AsyncMonitorSystem;
    }

    auto Name(const char **name) -> LxResult
    {
        return m_loc[0]->Name(m_loc, name);
    }

    auto Count(int *count) -> LxResult
    {
        return m_loc[0]->Count(m_loc, count);
    }

    auto ByIndex(int index, void **ppvObj) -> LxResult
    {
        return m_loc[0]->ByIndex(m_loc, index, ppvObj);
    }

    auto ByIndex(int index, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->ByIndex(m_loc, index, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_ColorDialog
{
public:
    virtual ~CLxImpl_ColorDialog() = default;

    virtual auto colordlg_DoDialog([[maybe_unused]] const char *title, [[maybe_unused]] double stops, [[maybe_unused]] double gamma, [[maybe_unused]] double *rgb) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_ColorDialog_DoDialog LxResult colordlg_DoDialog([[maybe_unused]] const char *title, [[maybe_unused]] double stops, [[maybe_unused]] double gamma, [[maybe_unused]] double *rgb) override
#define LXxO_ColorDialog_DoDialog LXxD_ColorDialog_DoDialog
#define LXxC_ColorDialog_DoDialog(c) LxResult c::colordlg_DoDialog([[maybe_unused]] const char *title, [[maybe_unused]] double stops, [[maybe_unused]] double gamma, [[maybe_unused]] double *rgb)

template <class T>
class CLxIfc_ColorDialog: public CLxInterface
{
public:
    CLxIfc_ColorDialog()
    {
        vt.DoDialog = DoDialog;
        vTable = &vt.iunk;
        iid = &lx::guid_ColorDialog;
    }

    static auto DoDialog(LXtObjectID wcom,const char *title,double stops,double gamma,double *rgb) -> LxResult
    {
        LXCWxINST (CLxImpl_ColorDialog, loc);
        try
        {
           return loc->colordlg_DoDialog( title, stops, gamma, rgb);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxColorDialog vt;
};

class CLxLoc_ColorDialog : public CLxLocalize<ILxColorDialogID>
{
public:
    CLxLoc_ColorDialog()
    {
        _init();
    }

    CLxLoc_ColorDialog(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_ColorDialog(CLxLoc_ColorDialog const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_ColorDialog;
    }

    auto DoDialog(const char *title, double stops, double gamma, double *rgb) -> LxResult
    {
        return m_loc[0]->DoDialog(m_loc, title, stops, gamma, rgb);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_StdDialogService : public CLxLocalizedService
{
public:
    ILxStdDialogServiceID m_loc{ nullptr };

public:
    CLxLoc_StdDialogService()
    {
        _init();
        set();
    }

    ~CLxLoc_StdDialogService() = default;

    void set()
    {
        if (!m_loc)
        {
            m_loc = reinterpret_cast<ILxStdDialogServiceID>(lx::GetGlobal(&lx::guid_StdDialogService));
        }
    }

    auto ScriptQuery(void **ppvObj) -> LxResult
    {
        return m_loc[0]->ScriptQuery(m_loc, ppvObj);
    }

    auto ScriptQuery(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->ScriptQuery(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto MonitorAllocate(const char *title, void **ppvObj) -> LxResult
    {
        return m_loc[0]->MonitorAllocate(m_loc, title, ppvObj);
    }

    auto MonitorAllocate(const char *title, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->MonitorAllocate(m_loc, title, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto MonitorRelease(void) -> LxResult
    {
        return m_loc[0]->MonitorRelease(m_loc);
    }

    auto MessageAllocate(void **ppvObj) -> LxResult
    {
        return m_loc[0]->MessageAllocate(m_loc, ppvObj);
    }

    auto MessageAllocate(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->MessageAllocate(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto MessageOpen(ILxUnknownID message, const char *title, const char *helpURL, const char *cookie) -> LxResult
    {
        return m_loc[0]->MessageOpen(m_loc,(ILxUnknownID) message, title, helpURL, cookie);
    }

    auto AsyncMonitorAllocate(const char *system, const char *title, void **ppvObj) -> LxResult
    {
        return m_loc[0]->AsyncMonitorAllocate(m_loc, system, title, ppvObj);
    }

    auto AsyncMonitorAllocate(const char *system, const char *title, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->AsyncMonitorAllocate(m_loc, system, title, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto AsyncMonitorSubAllocate(ILxUnknownID parent, const char *title, void **ppvObj) -> LxResult
    {
        return m_loc[0]->AsyncMonitorSubAllocate(m_loc,(ILxUnknownID) parent, title, ppvObj);
    }

    auto AsyncMonitorSubAllocate(ILxUnknownID parent, const char *title, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->AsyncMonitorSubAllocate(m_loc,(ILxUnknownID) parent, title, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto AsyncMonitorRelease(ILxUnknownID monitor) -> LxResult
    {
        return m_loc[0]->AsyncMonitorRelease(m_loc,(ILxUnknownID) monitor);
    }

    auto AsyncMonitorSystemCount(int *count) -> LxResult
    {
        return m_loc[0]->AsyncMonitorSystemCount(m_loc, count);
    }

    auto AsyncMonitorSystemByIndex(int index, void **ppvObj) -> LxResult
    {
        return m_loc[0]->AsyncMonitorSystemByIndex(m_loc, index, ppvObj);
    }

    auto AsyncMonitorSystemByIndex(int index, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->AsyncMonitorSystemByIndex(m_loc, index, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto AsyncMonitorSystemLookup(const char *name, void **ppvObj) -> LxResult
    {
        return m_loc[0]->AsyncMonitorSystemLookup(m_loc, name, ppvObj);
    }

    auto AsyncMonitorSystemLookup(const char *name, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->AsyncMonitorSystemLookup(m_loc, name, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto AsyncMonitorLookup(const char *ident, void **ppvObj) -> LxResult
    {
        return m_loc[0]->AsyncMonitorLookup(m_loc, ident, ppvObj);
    }

    auto AsyncMonitorLookup(const char *ident, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->AsyncMonitorLookup(m_loc, ident, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto FileDialog(ILxUnknownID dlgObj) -> LxResult
    {
        return m_loc[0]->FileDialog(m_loc,(ILxUnknownID) dlgObj);
    }

    auto AsyncMonitorAllocateWithoutAbort(const char *system, const char *title, void **ppvObj) -> LxResult
    {
        return m_loc[0]->AsyncMonitorAllocateWithoutAbort(m_loc, system, title, ppvObj);
    }

    auto AsyncMonitorAllocateWithoutAbort(const char *system, const char *title, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->AsyncMonitorAllocateWithoutAbort(m_loc, system, title, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto MonitorReleaseObj(ILxUnknownID monitor) -> LxResult
    {
        return m_loc[0]->MonitorReleaseObj(m_loc,(ILxUnknownID) monitor);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_FileDialogClient
{
public:
    virtual ~CLxImpl_FileDialogClient() = default;

    virtual auto filedlg_Flags([[maybe_unused]] void) -> unsigned
    {
        return LXfFILEDIALOG_LOAD;
    }

    virtual auto filedlg_Title([[maybe_unused]] ILxUnknownID message) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto filedlg_FileClass([[maybe_unused]] void) -> const char *
    {
        return 0;
    }

    virtual auto filedlg_ContextString([[maybe_unused]] const char **context) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto filedlg_FileFormat([[maybe_unused]] const char **format) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto filedlg_StartPath([[maybe_unused]] const char **filepath) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto filedlg_ResultPath([[maybe_unused]] const char *filepath) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto filedlg_ResultFormat([[maybe_unused]] const char *format) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_FileDialogClient_Flags unsigned filedlg_Flags() override
#define LXxO_FileDialogClient_Flags LXxD_FileDialogClient_Flags
#define LXxC_FileDialogClient_Flags(c) unsigned c::filedlg_Flags()
#define LXxD_FileDialogClient_Title LxResult filedlg_Title([[maybe_unused]] ILxUnknownID message) override
#define LXxO_FileDialogClient_Title LXxD_FileDialogClient_Title
#define LXxC_FileDialogClient_Title(c) LxResult c::filedlg_Title([[maybe_unused]] ILxUnknownID message)
#define LXxD_FileDialogClient_FileClass const char * filedlg_FileClass() override
#define LXxO_FileDialogClient_FileClass LXxD_FileDialogClient_FileClass
#define LXxC_FileDialogClient_FileClass(c) const char * c::filedlg_FileClass()
#define LXxD_FileDialogClient_ContextString LxResult filedlg_ContextString([[maybe_unused]] const char **context) override
#define LXxO_FileDialogClient_ContextString LXxD_FileDialogClient_ContextString
#define LXxC_FileDialogClient_ContextString(c) LxResult c::filedlg_ContextString([[maybe_unused]] const char **context)
#define LXxD_FileDialogClient_FileFormat LxResult filedlg_FileFormat([[maybe_unused]] const char **format) override
#define LXxO_FileDialogClient_FileFormat LXxD_FileDialogClient_FileFormat
#define LXxC_FileDialogClient_FileFormat(c) LxResult c::filedlg_FileFormat([[maybe_unused]] const char **format)
#define LXxD_FileDialogClient_StartPath LxResult filedlg_StartPath([[maybe_unused]] const char **filepath) override
#define LXxO_FileDialogClient_StartPath LXxD_FileDialogClient_StartPath
#define LXxC_FileDialogClient_StartPath(c) LxResult c::filedlg_StartPath([[maybe_unused]] const char **filepath)
#define LXxD_FileDialogClient_ResultPath LxResult filedlg_ResultPath([[maybe_unused]] const char *filepath) override
#define LXxO_FileDialogClient_ResultPath LXxD_FileDialogClient_ResultPath
#define LXxC_FileDialogClient_ResultPath(c) LxResult c::filedlg_ResultPath([[maybe_unused]] const char *filepath)
#define LXxD_FileDialogClient_ResultFormat LxResult filedlg_ResultFormat([[maybe_unused]] const char *format) override
#define LXxO_FileDialogClient_ResultFormat LXxD_FileDialogClient_ResultFormat
#define LXxC_FileDialogClient_ResultFormat(c) LxResult c::filedlg_ResultFormat([[maybe_unused]] const char *format)

template <class T>
class CLxIfc_FileDialogClient: public CLxInterface
{
public:
    CLxIfc_FileDialogClient()
    {
        vt.Flags = Flags;
        vt.Title = Title;
        vt.FileClass = FileClass;
        vt.ContextString = ContextString;
        vt.FileFormat = FileFormat;
        vt.StartPath = StartPath;
        vt.ResultPath = ResultPath;
        vt.ResultFormat = ResultFormat;
        vTable = &vt.iunk;
        iid = &lx::guid_FileDialogClient;
    }

    static auto Flags(LXtObjectID wcom) -> unsigned
    {
        LXCWxINST (CLxImpl_FileDialogClient, loc);
        return loc->filedlg_Flags();
    }

    static auto Title(LXtObjectID wcom,LXtObjectID message) -> LxResult
    {
        LXCWxINST (CLxImpl_FileDialogClient, loc);
        try
        {
           return loc->filedlg_Title((ILxUnknownID) message);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto FileClass(LXtObjectID wcom) -> const char *
    {
        LXCWxINST (CLxImpl_FileDialogClient, loc);
        return loc->filedlg_FileClass();
    }

    static auto ContextString(LXtObjectID wcom,const char **context) -> LxResult
    {
        LXCWxINST (CLxImpl_FileDialogClient, loc);
        try
        {
           return loc->filedlg_ContextString( context);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto FileFormat(LXtObjectID wcom,const char **format) -> LxResult
    {
        LXCWxINST (CLxImpl_FileDialogClient, loc);
        try
        {
           return loc->filedlg_FileFormat( format);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto StartPath(LXtObjectID wcom,const char **filepath) -> LxResult
    {
        LXCWxINST (CLxImpl_FileDialogClient, loc);
        try
        {
           return loc->filedlg_StartPath( filepath);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ResultPath(LXtObjectID wcom,const char *filepath) -> LxResult
    {
        LXCWxINST (CLxImpl_FileDialogClient, loc);
        try
        {
           return loc->filedlg_ResultPath( filepath);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ResultFormat(LXtObjectID wcom,const char *format) -> LxResult
    {
        LXCWxINST (CLxImpl_FileDialogClient, loc);
        try
        {
           return loc->filedlg_ResultFormat( format);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxFileDialogClient vt;
};


