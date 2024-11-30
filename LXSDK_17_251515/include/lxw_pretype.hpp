//
// C++ wrapper for lxsdk/lxpretype.h.
//
//	Copyright 2024.
//
//
#pragma once

#include <lxpretype.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx
{
    static LXtGUID const guid_PresetLoaderTarget = {0x3B15936E, {0x11F4, 0x4D4A}, {0x8A, 0xDC, 0x83, 0x10, 0xC6, 0xD9, 0x50, 0x8E}};
    static LXtGUID const guid_PresetType = {0xea04c0c2, {0x61af, 0x4f45}, {0xb1, 0xa1, 0xbc, 0xe6, 0x81, 0xe8, 0x98, 0x2d}};
    static LXtGUID const guid_PresetType1 = {0x2ED1F957, {0x16BE, 0x4d83}, {0x82, 0xA3, 0xBE, 0x5A, 0xF7, 0x82, 0x18, 0x91}};
    static LXtGUID const guid_PresetMetrics = {0x3139ccf8, {0x57ee, 0x472c}, {0x8d, 0xc9, 0xd5, 0x1f, 0x8c, 0x0a, 0xcb, 0x6b}};
    static LXtGUID const guid_PresetMetrics1 = {0x79185753, {0x0696, 0x4c54}, {0x9d, 0xaa, 0xfe, 0x01, 0x25, 0x3b, 0xfc, 0x07}};
    static LXtGUID const guid_PresetDo = {0x468f8808, {0xe3cc, 0x40fb}, {0x96, 0xbe, 0x11, 0x9f, 0x91, 0xe0, 0x1b, 0x87}};
    static LXtGUID const guid_PresetBrowserSource = {0xcc776670, {0x63a8, 0x4fa9}, {0x96, 0x18, 0xe3, 0x69, 0xb5, 0xa2, 0x2f, 0x62}};
    static LXtGUID const guid_PresetBrowserService = {0x4B16BAA1, {0x12DF, 0x47E9}, {0x86, 0x8A, 0x8E, 0xA8, 0x59, 0x66, 0xEB, 0xB0}};
    static LXtGUID const guid_PBSpecialSelListener = {0xe278629d, {0xc00f, 0x49c8}, {0x90, 0x57, 0xf6, 0x11, 0x2b, 0x6a, 0xe0, 0x74}};
} // namespace lx

class CLxLoc_PresetLoaderTarget : public CLxLocalize<ILxPresetLoaderTargetID>
{
public:
    CLxLoc_PresetLoaderTarget()
    {
        _init();
    }

    CLxLoc_PresetLoaderTarget(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_PresetLoaderTarget(CLxLoc_PresetLoaderTarget const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_PresetLoaderTarget;
    }

    auto ServerName(char *buf, unsigned len) -> LxResult
    {
        return m_loc[0]->ServerName(m_loc, buf, len);
    }

    auto ServerName(std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->ServerName(m_loc, buf, len);
        LXWx_SBUF2
    }

    auto CategoryCount(int *count) -> LxResult
    {
        return m_loc[0]->CategoryCount(m_loc, count);
    }

    auto CategoryByIndex(int index, const char **category) -> LxResult
    {
        return m_loc[0]->CategoryByIndex(m_loc, index, category);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_PresetType
{
public:
    virtual ~CLxImpl_PresetType() = default;

    virtual auto ptyp_Recognize([[maybe_unused]] const char *path, [[maybe_unused]] const char **category) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto ptyp_Apply([[maybe_unused]] const char *path, [[maybe_unused]] ILxUnknownID destination) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto ptyp_Do([[maybe_unused]] const char *path) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto ptyp_DoCommandFlags([[maybe_unused]] const char *path, [[maybe_unused]] int *flags) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto ptyp_Metrics([[maybe_unused]] const char *path, [[maybe_unused]] int flags, [[maybe_unused]] int w, [[maybe_unused]] int h, [[maybe_unused]] ILxUnknownID prevMetrics, [[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto ptyp_GenericThumbnailResource([[maybe_unused]] const char *path, [[maybe_unused]] const char **resourceName) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto ptyp_BaseAspect([[maybe_unused]] float *aspect) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto ptyp_StoreThumbnail([[maybe_unused]] const char *path, [[maybe_unused]] ILxUnknownID image) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto ptyp_DefaultThumbnail([[maybe_unused]] const char *path) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto ptyp_StoreMarkup([[maybe_unused]] const char *path, [[maybe_unused]] ILxUnknownID attr) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_PresetType_Recognize LxResult ptyp_Recognize([[maybe_unused]] const char *path, [[maybe_unused]] const char **category) override
#define LXxO_PresetType_Recognize LXxD_PresetType_Recognize
#define LXxC_PresetType_Recognize(c) LxResult c::ptyp_Recognize([[maybe_unused]] const char *path, [[maybe_unused]] const char **category)
#define LXxD_PresetType_Apply LxResult ptyp_Apply([[maybe_unused]] const char *path, [[maybe_unused]] ILxUnknownID destination) override
#define LXxO_PresetType_Apply LXxD_PresetType_Apply
#define LXxC_PresetType_Apply(c) LxResult c::ptyp_Apply([[maybe_unused]] const char *path, [[maybe_unused]] ILxUnknownID destination)
#define LXxD_PresetType_Do LxResult ptyp_Do([[maybe_unused]] const char *path) override
#define LXxO_PresetType_Do LXxD_PresetType_Do
#define LXxC_PresetType_Do(c) LxResult c::ptyp_Do([[maybe_unused]] const char *path)
#define LXxD_PresetType_DoCommandFlags LxResult ptyp_DoCommandFlags([[maybe_unused]] const char *path, [[maybe_unused]] int *flags) override
#define LXxO_PresetType_DoCommandFlags LXxD_PresetType_DoCommandFlags
#define LXxC_PresetType_DoCommandFlags(c) LxResult c::ptyp_DoCommandFlags([[maybe_unused]] const char *path, [[maybe_unused]] int *flags)
#define LXxD_PresetType_Metrics LxResult ptyp_Metrics([[maybe_unused]] const char *path, [[maybe_unused]] int flags, [[maybe_unused]] int w, [[maybe_unused]] int h, [[maybe_unused]] ILxUnknownID prevMetrics, [[maybe_unused]] void **ppvObj) override
#define LXxO_PresetType_Metrics LXxD_PresetType_Metrics
#define LXxC_PresetType_Metrics(c) LxResult c::ptyp_Metrics([[maybe_unused]] const char *path, [[maybe_unused]] int flags, [[maybe_unused]] int w, [[maybe_unused]] int h, [[maybe_unused]] ILxUnknownID prevMetrics, [[maybe_unused]] void **ppvObj)
#define LXxD_PresetType_GenericThumbnailResource LxResult ptyp_GenericThumbnailResource([[maybe_unused]] const char *path, [[maybe_unused]] const char **resourceName) override
#define LXxO_PresetType_GenericThumbnailResource LXxD_PresetType_GenericThumbnailResource
#define LXxC_PresetType_GenericThumbnailResource(c) LxResult c::ptyp_GenericThumbnailResource([[maybe_unused]] const char *path, [[maybe_unused]] const char **resourceName)
#define LXxD_PresetType_BaseAspect LxResult ptyp_BaseAspect([[maybe_unused]] float *aspect) override
#define LXxO_PresetType_BaseAspect LXxD_PresetType_BaseAspect
#define LXxC_PresetType_BaseAspect(c) LxResult c::ptyp_BaseAspect([[maybe_unused]] float *aspect)
#define LXxD_PresetType_StoreThumbnail LxResult ptyp_StoreThumbnail([[maybe_unused]] const char *path, [[maybe_unused]] ILxUnknownID image) override
#define LXxO_PresetType_StoreThumbnail LXxD_PresetType_StoreThumbnail
#define LXxC_PresetType_StoreThumbnail(c) LxResult c::ptyp_StoreThumbnail([[maybe_unused]] const char *path, [[maybe_unused]] ILxUnknownID image)
#define LXxD_PresetType_DefaultThumbnail LxResult ptyp_DefaultThumbnail([[maybe_unused]] const char *path) override
#define LXxO_PresetType_DefaultThumbnail LXxD_PresetType_DefaultThumbnail
#define LXxC_PresetType_DefaultThumbnail(c) LxResult c::ptyp_DefaultThumbnail([[maybe_unused]] const char *path)
#define LXxD_PresetType_StoreMarkup LxResult ptyp_StoreMarkup([[maybe_unused]] const char *path, [[maybe_unused]] ILxUnknownID attr) override
#define LXxO_PresetType_StoreMarkup LXxD_PresetType_StoreMarkup
#define LXxC_PresetType_StoreMarkup(c) LxResult c::ptyp_StoreMarkup([[maybe_unused]] const char *path, [[maybe_unused]] ILxUnknownID attr)

template <class T>
class CLxIfc_PresetType: public CLxInterface
{
public:
    CLxIfc_PresetType()
    {
        vt.Recognize = Recognize;
        vt.Apply = Apply;
        vt.Do = Do;
        vt.DoCommandFlags = DoCommandFlags;
        vt.Metrics = Metrics;
        vt.GenericThumbnailResource = GenericThumbnailResource;
        vt.BaseAspect = BaseAspect;
        vt.StoreThumbnail = StoreThumbnail;
        vt.DefaultThumbnail = DefaultThumbnail;
        vt.StoreMarkup = StoreMarkup;
        vTable = &vt.iunk;
        iid = &lx::guid_PresetType;
    }

    static auto Recognize(LXtObjectID wcom,const char *path,const char **category) -> LxResult
    {
        LXCWxINST (CLxImpl_PresetType, loc);
        try
        {
           return loc->ptyp_Recognize( path, category);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Apply(LXtObjectID wcom,const char *path,LXtObjectID destination) -> LxResult
    {
        LXCWxINST (CLxImpl_PresetType, loc);
        try
        {
           return loc->ptyp_Apply( path,(ILxUnknownID) destination);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Do(LXtObjectID wcom,const char *path) -> LxResult
    {
        LXCWxINST (CLxImpl_PresetType, loc);
        try
        {
           return loc->ptyp_Do( path);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto DoCommandFlags(LXtObjectID wcom,const char *path,int *flags) -> LxResult
    {
        LXCWxINST (CLxImpl_PresetType, loc);
        try
        {
           return loc->ptyp_DoCommandFlags( path, flags);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Metrics(LXtObjectID wcom,const char *path,int flags,int w,int h,LXtObjectID prevMetrics,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_PresetType, loc);
        try
        {
           return loc->ptyp_Metrics( path, flags, w, h,(ILxUnknownID) prevMetrics, ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto GenericThumbnailResource(LXtObjectID wcom,const char *path,const char **resourceName) -> LxResult
    {
        LXCWxINST (CLxImpl_PresetType, loc);
        try
        {
           return loc->ptyp_GenericThumbnailResource( path, resourceName);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto BaseAspect(LXtObjectID wcom,float *aspect) -> LxResult
    {
        LXCWxINST (CLxImpl_PresetType, loc);
        try
        {
           return loc->ptyp_BaseAspect( aspect);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto StoreThumbnail(LXtObjectID wcom,const char *path,LXtObjectID image) -> LxResult
    {
        LXCWxINST (CLxImpl_PresetType, loc);
        try
        {
           return loc->ptyp_StoreThumbnail( path,(ILxUnknownID) image);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto DefaultThumbnail(LXtObjectID wcom,const char *path) -> LxResult
    {
        LXCWxINST (CLxImpl_PresetType, loc);
        try
        {
           return loc->ptyp_DefaultThumbnail( path);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto StoreMarkup(LXtObjectID wcom,const char *path,LXtObjectID attr) -> LxResult
    {
        LXCWxINST (CLxImpl_PresetType, loc);
        try
        {
           return loc->ptyp_StoreMarkup( path,(ILxUnknownID) attr);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxPresetType vt;
};

class CLxLoc_PresetType : public CLxLocalize<ILxPresetTypeID>
{
public:
    CLxLoc_PresetType()
    {
        _init();
    }

    CLxLoc_PresetType(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_PresetType(CLxLoc_PresetType const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_PresetType;
    }

    auto Recognize(const char *path, const char **category) -> LxResult
    {
        return m_loc[0]->Recognize(m_loc, path, category);
    }

    auto Apply(const char *path, ILxUnknownID destination) -> LxResult
    {
        return m_loc[0]->Apply(m_loc, path,(ILxUnknownID) destination);
    }

    auto Do(const char *path) -> LxResult
    {
        return m_loc[0]->Do(m_loc, path);
    }

    auto DoCommandFlags(const char *path, int *flags) -> LxResult
    {
        return m_loc[0]->DoCommandFlags(m_loc, path, flags);
    }

    auto Metrics(const char *path, int flags, int w, int h, ILxUnknownID prevMetrics, void **ppvObj) -> LxResult
    {
        return m_loc[0]->Metrics(m_loc, path, flags, w, h,(ILxUnknownID) prevMetrics, ppvObj);
    }

    auto Metrics(const char *path, int flags, int w, int h, ILxUnknownID prevMetrics, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Metrics(m_loc, path, flags, w, h,(ILxUnknownID) prevMetrics, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto GenericThumbnailResource(const char *path, const char **resourceName) -> LxResult
    {
        return m_loc[0]->GenericThumbnailResource(m_loc, path, resourceName);
    }

    auto BaseAspect(float *aspect) -> LxResult
    {
        return m_loc[0]->BaseAspect(m_loc, aspect);
    }

    auto StoreThumbnail(const char *path, ILxUnknownID image) -> LxResult
    {
        return m_loc[0]->StoreThumbnail(m_loc, path,(ILxUnknownID) image);
    }

    auto DefaultThumbnail(const char *path) -> LxResult
    {
        return m_loc[0]->DefaultThumbnail(m_loc, path);
    }

    auto StoreMarkup(const char *path, ILxUnknownID attr) -> LxResult
    {
        return m_loc[0]->StoreMarkup(m_loc, path,(ILxUnknownID) attr);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_PresetType1
{
public:
    virtual ~CLxImpl_PresetType1() = default;

    virtual auto ptyp1_Recognize([[maybe_unused]] const char *path, [[maybe_unused]] const LXtGUID **guid, [[maybe_unused]] const char **category) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto ptyp1_Apply([[maybe_unused]] const char *path, [[maybe_unused]] ILxUnknownID destination) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto ptyp1_Do([[maybe_unused]] const char *path) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto ptyp1_DoCommandFlags([[maybe_unused]] const char *path, [[maybe_unused]] int *flags) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto ptyp1_Metrics([[maybe_unused]] const char *path, [[maybe_unused]] int flags, [[maybe_unused]] int w, [[maybe_unused]] int h, [[maybe_unused]] ILxUnknownID prevMetrics, [[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto ptyp1_GenericThumbnailResource([[maybe_unused]] const char *path, [[maybe_unused]] const char **resourceName) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto ptyp1_BaseAspect([[maybe_unused]] float *aspect) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_PresetType1_Recognize LxResult ptyp1_Recognize([[maybe_unused]] const char *path, [[maybe_unused]] const LXtGUID **guid, [[maybe_unused]] const char **category) override
#define LXxO_PresetType1_Recognize LXxD_PresetType1_Recognize
#define LXxC_PresetType1_Recognize(c) LxResult c::ptyp1_Recognize([[maybe_unused]] const char *path, [[maybe_unused]] const LXtGUID **guid, [[maybe_unused]] const char **category)
#define LXxD_PresetType1_Apply LxResult ptyp1_Apply([[maybe_unused]] const char *path, [[maybe_unused]] ILxUnknownID destination) override
#define LXxO_PresetType1_Apply LXxD_PresetType1_Apply
#define LXxC_PresetType1_Apply(c) LxResult c::ptyp1_Apply([[maybe_unused]] const char *path, [[maybe_unused]] ILxUnknownID destination)
#define LXxD_PresetType1_Do LxResult ptyp1_Do([[maybe_unused]] const char *path) override
#define LXxO_PresetType1_Do LXxD_PresetType1_Do
#define LXxC_PresetType1_Do(c) LxResult c::ptyp1_Do([[maybe_unused]] const char *path)
#define LXxD_PresetType1_DoCommandFlags LxResult ptyp1_DoCommandFlags([[maybe_unused]] const char *path, [[maybe_unused]] int *flags) override
#define LXxO_PresetType1_DoCommandFlags LXxD_PresetType1_DoCommandFlags
#define LXxC_PresetType1_DoCommandFlags(c) LxResult c::ptyp1_DoCommandFlags([[maybe_unused]] const char *path, [[maybe_unused]] int *flags)
#define LXxD_PresetType1_Metrics LxResult ptyp1_Metrics([[maybe_unused]] const char *path, [[maybe_unused]] int flags, [[maybe_unused]] int w, [[maybe_unused]] int h, [[maybe_unused]] ILxUnknownID prevMetrics, [[maybe_unused]] void **ppvObj) override
#define LXxO_PresetType1_Metrics LXxD_PresetType1_Metrics
#define LXxC_PresetType1_Metrics(c) LxResult c::ptyp1_Metrics([[maybe_unused]] const char *path, [[maybe_unused]] int flags, [[maybe_unused]] int w, [[maybe_unused]] int h, [[maybe_unused]] ILxUnknownID prevMetrics, [[maybe_unused]] void **ppvObj)
#define LXxD_PresetType1_GenericThumbnailResource LxResult ptyp1_GenericThumbnailResource([[maybe_unused]] const char *path, [[maybe_unused]] const char **resourceName) override
#define LXxO_PresetType1_GenericThumbnailResource LXxD_PresetType1_GenericThumbnailResource
#define LXxC_PresetType1_GenericThumbnailResource(c) LxResult c::ptyp1_GenericThumbnailResource([[maybe_unused]] const char *path, [[maybe_unused]] const char **resourceName)
#define LXxD_PresetType1_BaseAspect LxResult ptyp1_BaseAspect([[maybe_unused]] float *aspect) override
#define LXxO_PresetType1_BaseAspect LXxD_PresetType1_BaseAspect
#define LXxC_PresetType1_BaseAspect(c) LxResult c::ptyp1_BaseAspect([[maybe_unused]] float *aspect)

template <class T>
class CLxIfc_PresetType1: public CLxInterface
{
public:
    CLxIfc_PresetType1()
    {
        vt.Recognize = Recognize;
        vt.Apply = Apply;
        vt.Do = Do;
        vt.DoCommandFlags = DoCommandFlags;
        vt.Metrics = Metrics;
        vt.GenericThumbnailResource = GenericThumbnailResource;
        vt.BaseAspect = BaseAspect;
        vTable = &vt.iunk;
        iid = &lx::guid_PresetType1;
    }

    static auto Recognize(LXtObjectID wcom,const char *path,const LXtGUID **guid,const char **category) -> LxResult
    {
        LXCWxINST (CLxImpl_PresetType1, loc);
        try
        {
           return loc->ptyp1_Recognize( path, guid, category);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Apply(LXtObjectID wcom,const char *path,LXtObjectID destination) -> LxResult
    {
        LXCWxINST (CLxImpl_PresetType1, loc);
        try
        {
           return loc->ptyp1_Apply( path,(ILxUnknownID) destination);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Do(LXtObjectID wcom,const char *path) -> LxResult
    {
        LXCWxINST (CLxImpl_PresetType1, loc);
        try
        {
           return loc->ptyp1_Do( path);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto DoCommandFlags(LXtObjectID wcom,const char *path,int *flags) -> LxResult
    {
        LXCWxINST (CLxImpl_PresetType1, loc);
        try
        {
           return loc->ptyp1_DoCommandFlags( path, flags);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Metrics(LXtObjectID wcom,const char *path,int flags,int w,int h,LXtObjectID prevMetrics,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_PresetType1, loc);
        try
        {
           return loc->ptyp1_Metrics( path, flags, w, h,(ILxUnknownID) prevMetrics, ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto GenericThumbnailResource(LXtObjectID wcom,const char *path,const char **resourceName) -> LxResult
    {
        LXCWxINST (CLxImpl_PresetType1, loc);
        try
        {
           return loc->ptyp1_GenericThumbnailResource( path, resourceName);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto BaseAspect(LXtObjectID wcom,float *aspect) -> LxResult
    {
        LXCWxINST (CLxImpl_PresetType1, loc);
        try
        {
           return loc->ptyp1_BaseAspect( aspect);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxPresetType1 vt;
};

class CLxLoc_PresetType1 : public CLxLocalize<ILxPresetType1ID>
{
public:
    CLxLoc_PresetType1()
    {
        _init();
    }

    CLxLoc_PresetType1(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_PresetType1(CLxLoc_PresetType1 const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_PresetType1;
    }

    auto Recognize(const char *path, const LXtGUID **guid, const char **category) -> LxResult
    {
        return m_loc[0]->Recognize(m_loc, path, guid, category);
    }

    auto Apply(const char *path, ILxUnknownID destination) -> LxResult
    {
        return m_loc[0]->Apply(m_loc, path,(ILxUnknownID) destination);
    }

    auto Do(const char *path) -> LxResult
    {
        return m_loc[0]->Do(m_loc, path);
    }

    auto DoCommandFlags(const char *path, int *flags) -> LxResult
    {
        return m_loc[0]->DoCommandFlags(m_loc, path, flags);
    }

    auto Metrics(const char *path, int flags, int w, int h, ILxUnknownID prevMetrics, void **ppvObj) -> LxResult
    {
        return m_loc[0]->Metrics(m_loc, path, flags, w, h,(ILxUnknownID) prevMetrics, ppvObj);
    }

    auto Metrics(const char *path, int flags, int w, int h, ILxUnknownID prevMetrics, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Metrics(m_loc, path, flags, w, h,(ILxUnknownID) prevMetrics, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto GenericThumbnailResource(const char *path, const char **resourceName) -> LxResult
    {
        return m_loc[0]->GenericThumbnailResource(m_loc, path, resourceName);
    }

    auto BaseAspect(float *aspect) -> LxResult
    {
        return m_loc[0]->BaseAspect(m_loc, aspect);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_PresetMetrics
{
public:
    virtual ~CLxImpl_PresetMetrics() = default;

    virtual auto pmet_ThumbnailImage([[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto pmet_ThumbnailIdealSize([[maybe_unused]] int *idealW, [[maybe_unused]] int *idealH) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto pmet_ThumbnailResource([[maybe_unused]] const char **resourceName) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto pmet_Metadata([[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto pmet_Markup([[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto pmet_Flags([[maybe_unused]] int *flags) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_PresetMetrics_ThumbnailImage LxResult pmet_ThumbnailImage([[maybe_unused]] void **ppvObj) override
#define LXxO_PresetMetrics_ThumbnailImage LXxD_PresetMetrics_ThumbnailImage
#define LXxC_PresetMetrics_ThumbnailImage(c) LxResult c::pmet_ThumbnailImage([[maybe_unused]] void **ppvObj)
#define LXxD_PresetMetrics_ThumbnailIdealSize LxResult pmet_ThumbnailIdealSize([[maybe_unused]] int *idealW, [[maybe_unused]] int *idealH) override
#define LXxO_PresetMetrics_ThumbnailIdealSize LXxD_PresetMetrics_ThumbnailIdealSize
#define LXxC_PresetMetrics_ThumbnailIdealSize(c) LxResult c::pmet_ThumbnailIdealSize([[maybe_unused]] int *idealW, [[maybe_unused]] int *idealH)
#define LXxD_PresetMetrics_ThumbnailResource LxResult pmet_ThumbnailResource([[maybe_unused]] const char **resourceName) override
#define LXxO_PresetMetrics_ThumbnailResource LXxD_PresetMetrics_ThumbnailResource
#define LXxC_PresetMetrics_ThumbnailResource(c) LxResult c::pmet_ThumbnailResource([[maybe_unused]] const char **resourceName)
#define LXxD_PresetMetrics_Metadata LxResult pmet_Metadata([[maybe_unused]] void **ppvObj) override
#define LXxO_PresetMetrics_Metadata LXxD_PresetMetrics_Metadata
#define LXxC_PresetMetrics_Metadata(c) LxResult c::pmet_Metadata([[maybe_unused]] void **ppvObj)
#define LXxD_PresetMetrics_Markup LxResult pmet_Markup([[maybe_unused]] void **ppvObj) override
#define LXxO_PresetMetrics_Markup LXxD_PresetMetrics_Markup
#define LXxC_PresetMetrics_Markup(c) LxResult c::pmet_Markup([[maybe_unused]] void **ppvObj)
#define LXxD_PresetMetrics_Flags LxResult pmet_Flags([[maybe_unused]] int *flags) override
#define LXxO_PresetMetrics_Flags LXxD_PresetMetrics_Flags
#define LXxC_PresetMetrics_Flags(c) LxResult c::pmet_Flags([[maybe_unused]] int *flags)

template <class T>
class CLxIfc_PresetMetrics: public CLxInterface
{
public:
    CLxIfc_PresetMetrics()
    {
        vt.ThumbnailImage = ThumbnailImage;
        vt.ThumbnailIdealSize = ThumbnailIdealSize;
        vt.ThumbnailResource = ThumbnailResource;
        vt.Metadata = Metadata;
        vt.Markup = Markup;
        vt.Flags = Flags;
        vTable = &vt.iunk;
        iid = &lx::guid_PresetMetrics;
    }

    static auto ThumbnailImage(LXtObjectID wcom,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_PresetMetrics, loc);
        try
        {
           return loc->pmet_ThumbnailImage( ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ThumbnailIdealSize(LXtObjectID wcom,int *idealW,int *idealH) -> LxResult
    {
        LXCWxINST (CLxImpl_PresetMetrics, loc);
        try
        {
           return loc->pmet_ThumbnailIdealSize( idealW, idealH);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ThumbnailResource(LXtObjectID wcom,const char **resourceName) -> LxResult
    {
        LXCWxINST (CLxImpl_PresetMetrics, loc);
        try
        {
           return loc->pmet_ThumbnailResource( resourceName);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Metadata(LXtObjectID wcom,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_PresetMetrics, loc);
        try
        {
           return loc->pmet_Metadata( ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Markup(LXtObjectID wcom,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_PresetMetrics, loc);
        try
        {
           return loc->pmet_Markup( ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Flags(LXtObjectID wcom,int *flags) -> LxResult
    {
        LXCWxINST (CLxImpl_PresetMetrics, loc);
        try
        {
           return loc->pmet_Flags( flags);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxPresetMetrics vt;
};

class CLxLoc_PresetMetrics : public CLxLocalize<ILxPresetMetricsID>
{
public:
    CLxLoc_PresetMetrics()
    {
        _init();
    }

    CLxLoc_PresetMetrics(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_PresetMetrics(CLxLoc_PresetMetrics const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_PresetMetrics;
    }

    auto ThumbnailImage(void **ppvObj) -> LxResult
    {
        return m_loc[0]->ThumbnailImage(m_loc, ppvObj);
    }

    auto ThumbnailImage(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->ThumbnailImage(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto ThumbnailIdealSize(int *idealW, int *idealH) -> LxResult
    {
        return m_loc[0]->ThumbnailIdealSize(m_loc, idealW, idealH);
    }

    auto ThumbnailResource(const char **resourceName) -> LxResult
    {
        return m_loc[0]->ThumbnailResource(m_loc, resourceName);
    }

    auto Metadata(void **ppvObj) -> LxResult
    {
        return m_loc[0]->Metadata(m_loc, ppvObj);
    }

    auto Metadata(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Metadata(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Markup(void **ppvObj) -> LxResult
    {
        return m_loc[0]->Markup(m_loc, ppvObj);
    }

    auto Markup(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Markup(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Flags(int *flags) -> LxResult
    {
        return m_loc[0]->Flags(m_loc, flags);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_PresetMetrics1
{
public:
    virtual ~CLxImpl_PresetMetrics1() = default;

    virtual auto pmet1_Label([[maybe_unused]] const char **label) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto pmet1_ThumbnailImage([[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto pmet1_ThumbnailIdealSize([[maybe_unused]] int *idealW, [[maybe_unused]] int *idealH) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto pmet1_ThumbnailResource([[maybe_unused]] const char **resourceName) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto pmet1_Caption([[maybe_unused]] const char **caption) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto pmet1_ToolTip([[maybe_unused]] const char **tooltip) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_PresetMetrics1_Label LxResult pmet1_Label([[maybe_unused]] const char **label) override
#define LXxO_PresetMetrics1_Label LXxD_PresetMetrics1_Label
#define LXxC_PresetMetrics1_Label(c) LxResult c::pmet1_Label([[maybe_unused]] const char **label)
#define LXxD_PresetMetrics1_ThumbnailImage LxResult pmet1_ThumbnailImage([[maybe_unused]] void **ppvObj) override
#define LXxO_PresetMetrics1_ThumbnailImage LXxD_PresetMetrics1_ThumbnailImage
#define LXxC_PresetMetrics1_ThumbnailImage(c) LxResult c::pmet1_ThumbnailImage([[maybe_unused]] void **ppvObj)
#define LXxD_PresetMetrics1_ThumbnailIdealSize LxResult pmet1_ThumbnailIdealSize([[maybe_unused]] int *idealW, [[maybe_unused]] int *idealH) override
#define LXxO_PresetMetrics1_ThumbnailIdealSize LXxD_PresetMetrics1_ThumbnailIdealSize
#define LXxC_PresetMetrics1_ThumbnailIdealSize(c) LxResult c::pmet1_ThumbnailIdealSize([[maybe_unused]] int *idealW, [[maybe_unused]] int *idealH)
#define LXxD_PresetMetrics1_ThumbnailResource LxResult pmet1_ThumbnailResource([[maybe_unused]] const char **resourceName) override
#define LXxO_PresetMetrics1_ThumbnailResource LXxD_PresetMetrics1_ThumbnailResource
#define LXxC_PresetMetrics1_ThumbnailResource(c) LxResult c::pmet1_ThumbnailResource([[maybe_unused]] const char **resourceName)
#define LXxD_PresetMetrics1_Caption LxResult pmet1_Caption([[maybe_unused]] const char **caption) override
#define LXxO_PresetMetrics1_Caption LXxD_PresetMetrics1_Caption
#define LXxC_PresetMetrics1_Caption(c) LxResult c::pmet1_Caption([[maybe_unused]] const char **caption)
#define LXxD_PresetMetrics1_ToolTip LxResult pmet1_ToolTip([[maybe_unused]] const char **tooltip) override
#define LXxO_PresetMetrics1_ToolTip LXxD_PresetMetrics1_ToolTip
#define LXxC_PresetMetrics1_ToolTip(c) LxResult c::pmet1_ToolTip([[maybe_unused]] const char **tooltip)

template <class T>
class CLxIfc_PresetMetrics1: public CLxInterface
{
public:
    CLxIfc_PresetMetrics1()
    {
        vt.Label = Label;
        vt.ThumbnailImage = ThumbnailImage;
        vt.ThumbnailIdealSize = ThumbnailIdealSize;
        vt.ThumbnailResource = ThumbnailResource;
        vt.Caption = Caption;
        vt.ToolTip = ToolTip;
        vTable = &vt.iunk;
        iid = &lx::guid_PresetMetrics1;
    }

    static auto Label(LXtObjectID wcom,const char **label) -> LxResult
    {
        LXCWxINST (CLxImpl_PresetMetrics1, loc);
        try
        {
           return loc->pmet1_Label( label);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ThumbnailImage(LXtObjectID wcom,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_PresetMetrics1, loc);
        try
        {
           return loc->pmet1_ThumbnailImage( ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ThumbnailIdealSize(LXtObjectID wcom,int *idealW,int *idealH) -> LxResult
    {
        LXCWxINST (CLxImpl_PresetMetrics1, loc);
        try
        {
           return loc->pmet1_ThumbnailIdealSize( idealW, idealH);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ThumbnailResource(LXtObjectID wcom,const char **resourceName) -> LxResult
    {
        LXCWxINST (CLxImpl_PresetMetrics1, loc);
        try
        {
           return loc->pmet1_ThumbnailResource( resourceName);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Caption(LXtObjectID wcom,const char **caption) -> LxResult
    {
        LXCWxINST (CLxImpl_PresetMetrics1, loc);
        try
        {
           return loc->pmet1_Caption( caption);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ToolTip(LXtObjectID wcom,const char **tooltip) -> LxResult
    {
        LXCWxINST (CLxImpl_PresetMetrics1, loc);
        try
        {
           return loc->pmet1_ToolTip( tooltip);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxPresetMetrics1 vt;
};

class CLxLoc_PresetMetrics1 : public CLxLocalize<ILxPresetMetrics1ID>
{
public:
    CLxLoc_PresetMetrics1()
    {
        _init();
    }

    CLxLoc_PresetMetrics1(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_PresetMetrics1(CLxLoc_PresetMetrics1 const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_PresetMetrics1;
    }

    auto Label(const char **label) -> LxResult
    {
        return m_loc[0]->Label(m_loc, label);
    }

    auto ThumbnailImage(void **ppvObj) -> LxResult
    {
        return m_loc[0]->ThumbnailImage(m_loc, ppvObj);
    }

    auto ThumbnailImage(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->ThumbnailImage(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto ThumbnailIdealSize(int *idealW, int *idealH) -> LxResult
    {
        return m_loc[0]->ThumbnailIdealSize(m_loc, idealW, idealH);
    }

    auto ThumbnailResource(const char **resourceName) -> LxResult
    {
        return m_loc[0]->ThumbnailResource(m_loc, resourceName);
    }

    auto Caption(const char **caption) -> LxResult
    {
        return m_loc[0]->Caption(m_loc, caption);
    }

    auto ToolTip(const char **tooltip) -> LxResult
    {
        return m_loc[0]->ToolTip(m_loc, tooltip);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_PresetDo
{
public:
    virtual ~CLxImpl_PresetDo() = default;

    virtual auto pdo_Test([[maybe_unused]] const char *path) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto pdo_Do([[maybe_unused]] const char *path) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_PresetDo_Test LxResult pdo_Test([[maybe_unused]] const char *path) override
#define LXxO_PresetDo_Test LXxD_PresetDo_Test
#define LXxC_PresetDo_Test(c) LxResult c::pdo_Test([[maybe_unused]] const char *path)
#define LXxD_PresetDo_Do LxResult pdo_Do([[maybe_unused]] const char *path) override
#define LXxO_PresetDo_Do LXxD_PresetDo_Do
#define LXxC_PresetDo_Do(c) LxResult c::pdo_Do([[maybe_unused]] const char *path)

template <class T>
class CLxIfc_PresetDo: public CLxInterface
{
public:
    CLxIfc_PresetDo()
    {
        vt.Test = Test;
        vt.Do = Do;
        vTable = &vt.iunk;
        iid = &lx::guid_PresetDo;
    }

    static auto Test(LXtObjectID wcom,const char *path) -> LxResult
    {
        LXCWxINST (CLxImpl_PresetDo, loc);
        try
        {
           return loc->pdo_Test( path);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Do(LXtObjectID wcom,const char *path) -> LxResult
    {
        LXCWxINST (CLxImpl_PresetDo, loc);
        try
        {
           return loc->pdo_Do( path);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxPresetDo vt;
};

class CLxLoc_PresetDo : public CLxLocalize<ILxPresetDoID>
{
public:
    CLxLoc_PresetDo()
    {
        _init();
    }

    CLxLoc_PresetDo(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_PresetDo(CLxLoc_PresetDo const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_PresetDo;
    }

    auto Test(const char *path) -> LxResult
    {
        return m_loc[0]->Test(m_loc, path);
    }

    auto Do(const char *path) -> LxResult
    {
        return m_loc[0]->Do(m_loc, path);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_PresetBrowserSource : public CLxLocalize<ILxPresetBrowserSourceID>
{
public:
    CLxLoc_PresetBrowserSource()
    {
        _init();
    }

    CLxLoc_PresetBrowserSource(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_PresetBrowserSource(CLxLoc_PresetBrowserSource const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_PresetBrowserSource;
    }

    auto ViewportHash(char *buf, int len) -> LxResult
    {
        return m_loc[0]->ViewportHash(m_loc, buf, len);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_PresetBrowserService : public CLxLocalizedService
{
public:
    ILxPresetBrowserServiceID m_loc{ nullptr };

public:
    CLxLoc_PresetBrowserService()
    {
        _init();
        set();
    }

    ~CLxLoc_PresetBrowserService() = default;

    void set()
    {
        if (!m_loc)
        {
            m_loc = reinterpret_cast<ILxPresetBrowserServiceID>(lx::GetGlobal(&lx::guid_PresetBrowserService));
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

    auto SubtypeFromIdentifier(const char *identifier, int *subtype) -> LxResult
    {
        return m_loc[0]->SubtypeFromIdentifier(m_loc, identifier, subtype);
    }

    auto UpdateIdentifierState(const char *identifier, const char *path) -> LxResult
    {
        return m_loc[0]->UpdateIdentifierState(m_loc, identifier, path);
    }

    auto ServerCount(int *count) -> LxResult
    {
        return m_loc[0]->ServerCount(m_loc, count);
    }

    auto ServerByIndex(int index, void **ppvObj) -> LxResult
    {
        return m_loc[0]->ServerByIndex(m_loc, index, ppvObj);
    }

    auto ServerByIndex(int index, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->ServerByIndex(m_loc, index, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto ServerLookup(const char *name, void **ppvObj) -> LxResult
    {
        return m_loc[0]->ServerLookup(m_loc, name, ppvObj);
    }

    auto ServerLookup(const char *name, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->ServerLookup(m_loc, name, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto ServerNameByIndex(int index, const char **name) -> LxResult
    {
        return m_loc[0]->ServerNameByIndex(m_loc, index, name);
    }

    auto ServerUserNameByIndex(int index, const char **name) -> LxResult
    {
        return m_loc[0]->ServerUserNameByIndex(m_loc, index, name);
    }

    auto RecognizeFile(const char *path, int flags, const char **serverName, const char **category) -> LxResult
    {
        return m_loc[0]->RecognizeFile(m_loc, path, flags, serverName, category);
    }

    auto RecognizeFileForce(const char *path, int flags, const char **serverName, const char **category) -> LxResult
    {
        return m_loc[0]->RecognizeFileForce(m_loc, path, flags, serverName, category);
    }

    auto Rescan(const char *path) -> LxResult
    {
        return m_loc[0]->Rescan(m_loc, path);
    }

    auto IsViewportVisible(const char *identifier, const char *hash) -> LxResult
    {
        return m_loc[0]->IsViewportVisible(m_loc, identifier, hash);
    }

    auto GetSpecialSelModePath(const char *identifier, char *buf, int len) -> LxResult
    {
        return m_loc[0]->GetSpecialSelModePath(m_loc, identifier, buf, len);
    }

    auto SetSpecialSelModePath(const char *identifier, const char *path, int asInteractive) -> LxResult
    {
        return m_loc[0]->SetSpecialSelModePath(m_loc, identifier, path, asInteractive);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};

