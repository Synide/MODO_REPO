//
// C++ wrapper for lxsdk/lxthumbbrowse.h.
//
//	Copyright 2024.
//
//
#pragma once

#include <lxthumbbrowse.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx
{
    static LXtGUID const guid_DTBBadgeOverride = {0x7cc3ec4f, {0x974b, 0x4467}, {0x9f, 0x26, 0xc3, 0xef, 0x78, 0x82, 0x59, 0x18}};
    static LXtGUID const guid_DTBDropPreview = {0x7ccfca70, {0x79d5, 0x42ed}, {0xa5, 0xbf, 0x5d, 0xfd, 0x5b, 0xc3, 0x26, 0x2b}};
    static LXtGUID const guid_DTBGroupSortOverride = {0x0da992be, {0x74c8, 0x4c25}, {0xa4, 0x02, 0xc6, 0x92, 0x16, 0xe5, 0x2d, 0xfb}};
} // namespace lx

class CLxImpl_DTBBadgeOverride
{
public:
    virtual ~CLxImpl_DTBBadgeOverride() = default;

    virtual auto dtbbo_BadgesSupported([[maybe_unused]] ILxUnknownID entry, [[maybe_unused]] int *badges) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto dtbbo_BadgeIsAlwaysVisible([[maybe_unused]] ILxUnknownID entry, [[maybe_unused]] int badge) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto dtbbo_BadgeOverride([[maybe_unused]] ILxUnknownID entry, [[maybe_unused]] int badge, [[maybe_unused]] char *buf, [[maybe_unused]] int len) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto dtbbo_BadgeTooltip([[maybe_unused]] ILxUnknownID entry, [[maybe_unused]] int badge, [[maybe_unused]] char *buf, [[maybe_unused]] int len) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto dtbbo_BadgeStarRatingOverride([[maybe_unused]] ILxUnknownID entry, [[maybe_unused]] int *rating, [[maybe_unused]] char *buf, [[maybe_unused]] int len) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto dtbbo_BadgeAction([[maybe_unused]] ILxUnknownID entry, [[maybe_unused]] int badge) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto dtbbo_BadgeStarRatingAction([[maybe_unused]] ILxUnknownID entry, [[maybe_unused]] int rating) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_DTBBadgeOverride_BadgesSupported LxResult dtbbo_BadgesSupported([[maybe_unused]] ILxUnknownID entry, [[maybe_unused]] int *badges) override
#define LXxO_DTBBadgeOverride_BadgesSupported LXxD_DTBBadgeOverride_BadgesSupported
#define LXxC_DTBBadgeOverride_BadgesSupported(c) LxResult c::dtbbo_BadgesSupported([[maybe_unused]] ILxUnknownID entry, [[maybe_unused]] int *badges)
#define LXxD_DTBBadgeOverride_BadgeIsAlwaysVisible LxResult dtbbo_BadgeIsAlwaysVisible([[maybe_unused]] ILxUnknownID entry, [[maybe_unused]] int badge) override
#define LXxO_DTBBadgeOverride_BadgeIsAlwaysVisible LXxD_DTBBadgeOverride_BadgeIsAlwaysVisible
#define LXxC_DTBBadgeOverride_BadgeIsAlwaysVisible(c) LxResult c::dtbbo_BadgeIsAlwaysVisible([[maybe_unused]] ILxUnknownID entry, [[maybe_unused]] int badge)
#define LXxD_DTBBadgeOverride_BadgeOverride LxResult dtbbo_BadgeOverride([[maybe_unused]] ILxUnknownID entry, [[maybe_unused]] int badge, [[maybe_unused]] char *buf, [[maybe_unused]] int len) override
#define LXxO_DTBBadgeOverride_BadgeOverride LXxD_DTBBadgeOverride_BadgeOverride
#define LXxC_DTBBadgeOverride_BadgeOverride(c) LxResult c::dtbbo_BadgeOverride([[maybe_unused]] ILxUnknownID entry, [[maybe_unused]] int badge, [[maybe_unused]] char *buf, [[maybe_unused]] int len)
#define LXxD_DTBBadgeOverride_BadgeTooltip LxResult dtbbo_BadgeTooltip([[maybe_unused]] ILxUnknownID entry, [[maybe_unused]] int badge, [[maybe_unused]] char *buf, [[maybe_unused]] int len) override
#define LXxO_DTBBadgeOverride_BadgeTooltip LXxD_DTBBadgeOverride_BadgeTooltip
#define LXxC_DTBBadgeOverride_BadgeTooltip(c) LxResult c::dtbbo_BadgeTooltip([[maybe_unused]] ILxUnknownID entry, [[maybe_unused]] int badge, [[maybe_unused]] char *buf, [[maybe_unused]] int len)
#define LXxD_DTBBadgeOverride_BadgeStarRatingOverride LxResult dtbbo_BadgeStarRatingOverride([[maybe_unused]] ILxUnknownID entry, [[maybe_unused]] int *rating, [[maybe_unused]] char *buf, [[maybe_unused]] int len) override
#define LXxO_DTBBadgeOverride_BadgeStarRatingOverride LXxD_DTBBadgeOverride_BadgeStarRatingOverride
#define LXxC_DTBBadgeOverride_BadgeStarRatingOverride(c) LxResult c::dtbbo_BadgeStarRatingOverride([[maybe_unused]] ILxUnknownID entry, [[maybe_unused]] int *rating, [[maybe_unused]] char *buf, [[maybe_unused]] int len)
#define LXxD_DTBBadgeOverride_BadgeAction LxResult dtbbo_BadgeAction([[maybe_unused]] ILxUnknownID entry, [[maybe_unused]] int badge) override
#define LXxO_DTBBadgeOverride_BadgeAction LXxD_DTBBadgeOverride_BadgeAction
#define LXxC_DTBBadgeOverride_BadgeAction(c) LxResult c::dtbbo_BadgeAction([[maybe_unused]] ILxUnknownID entry, [[maybe_unused]] int badge)
#define LXxD_DTBBadgeOverride_BadgeStarRatingAction LxResult dtbbo_BadgeStarRatingAction([[maybe_unused]] ILxUnknownID entry, [[maybe_unused]] int rating) override
#define LXxO_DTBBadgeOverride_BadgeStarRatingAction LXxD_DTBBadgeOverride_BadgeStarRatingAction
#define LXxC_DTBBadgeOverride_BadgeStarRatingAction(c) LxResult c::dtbbo_BadgeStarRatingAction([[maybe_unused]] ILxUnknownID entry, [[maybe_unused]] int rating)

template <class T>
class CLxIfc_DTBBadgeOverride: public CLxInterface
{
public:
    CLxIfc_DTBBadgeOverride()
    {
        vt.BadgesSupported = BadgesSupported;
        vt.BadgeIsAlwaysVisible = BadgeIsAlwaysVisible;
        vt.BadgeOverride = BadgeOverride;
        vt.BadgeTooltip = BadgeTooltip;
        vt.BadgeStarRatingOverride = BadgeStarRatingOverride;
        vt.BadgeAction = BadgeAction;
        vt.BadgeStarRatingAction = BadgeStarRatingAction;
        vTable = &vt.iunk;
        iid = &lx::guid_DTBBadgeOverride;
    }

    static auto BadgesSupported(LXtObjectID wcom,LXtObjectID entry,int *badges) -> LxResult
    {
        LXCWxINST (CLxImpl_DTBBadgeOverride, loc);
        try
        {
           return loc->dtbbo_BadgesSupported((ILxUnknownID) entry, badges);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto BadgeIsAlwaysVisible(LXtObjectID wcom,LXtObjectID entry,int badge) -> LxResult
    {
        LXCWxINST (CLxImpl_DTBBadgeOverride, loc);
        try
        {
           return loc->dtbbo_BadgeIsAlwaysVisible((ILxUnknownID) entry, badge);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto BadgeOverride(LXtObjectID wcom,LXtObjectID entry,int badge,char *buf,int len) -> LxResult
    {
        LXCWxINST (CLxImpl_DTBBadgeOverride, loc);
        try
        {
           return loc->dtbbo_BadgeOverride((ILxUnknownID) entry, badge, buf, len);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto BadgeTooltip(LXtObjectID wcom,LXtObjectID entry,int badge,char *buf,int len) -> LxResult
    {
        LXCWxINST (CLxImpl_DTBBadgeOverride, loc);
        try
        {
           return loc->dtbbo_BadgeTooltip((ILxUnknownID) entry, badge, buf, len);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto BadgeStarRatingOverride(LXtObjectID wcom,LXtObjectID entry,int *rating,char *buf,int len) -> LxResult
    {
        LXCWxINST (CLxImpl_DTBBadgeOverride, loc);
        try
        {
           return loc->dtbbo_BadgeStarRatingOverride((ILxUnknownID) entry, rating, buf, len);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto BadgeAction(LXtObjectID wcom,LXtObjectID entry,int badge) -> LxResult
    {
        LXCWxINST (CLxImpl_DTBBadgeOverride, loc);
        try
        {
           return loc->dtbbo_BadgeAction((ILxUnknownID) entry, badge);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto BadgeStarRatingAction(LXtObjectID wcom,LXtObjectID entry,int rating) -> LxResult
    {
        LXCWxINST (CLxImpl_DTBBadgeOverride, loc);
        try
        {
           return loc->dtbbo_BadgeStarRatingAction((ILxUnknownID) entry, rating);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxDTBBadgeOverride vt;
};

class CLxLoc_DTBBadgeOverride : public CLxLocalize<ILxDTBBadgeOverrideID>
{
public:
    CLxLoc_DTBBadgeOverride()
    {
        _init();
    }

    CLxLoc_DTBBadgeOverride(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_DTBBadgeOverride(CLxLoc_DTBBadgeOverride const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_DTBBadgeOverride;
    }

    auto BadgesSupported(ILxUnknownID entry, int *badges) -> LxResult
    {
        return m_loc[0]->BadgesSupported(m_loc,(ILxUnknownID) entry, badges);
    }

    auto BadgeIsAlwaysVisible(ILxUnknownID entry, int badge) -> LxResult
    {
        return m_loc[0]->BadgeIsAlwaysVisible(m_loc,(ILxUnknownID) entry, badge);
    }

    auto BadgeOverride(ILxUnknownID entry, int badge, char *buf, int len) -> LxResult
    {
        return m_loc[0]->BadgeOverride(m_loc,(ILxUnknownID) entry, badge, buf, len);
    }

    auto BadgeTooltip(ILxUnknownID entry, int badge, char *buf, int len) -> LxResult
    {
        return m_loc[0]->BadgeTooltip(m_loc,(ILxUnknownID) entry, badge, buf, len);
    }

    auto BadgeStarRatingOverride(ILxUnknownID entry, int *rating, char *buf, int len) -> LxResult
    {
        return m_loc[0]->BadgeStarRatingOverride(m_loc,(ILxUnknownID) entry, rating, buf, len);
    }

    auto BadgeAction(ILxUnknownID entry, int badge) -> LxResult
    {
        return m_loc[0]->BadgeAction(m_loc,(ILxUnknownID) entry, badge);
    }

    auto BadgeStarRatingAction(ILxUnknownID entry, int rating) -> LxResult
    {
        return m_loc[0]->BadgeStarRatingAction(m_loc,(ILxUnknownID) entry, rating);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_DTBDropPreview : public CLxLocalize<ILxDTBDropPreviewID>
{
public:
    CLxLoc_DTBDropPreview()
    {
        _init();
    }

    CLxLoc_DTBDropPreview(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_DTBDropPreview(CLxLoc_DTBDropPreview const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_DTBDropPreview;
    }

    auto MarkNone(void) -> LxResult
    {
        return m_loc[0]->MarkNone(m_loc);
    }

    auto MarkGridPos(const char *path, unsigned int x, unsigned int y) -> LxResult
    {
        return m_loc[0]->MarkGridPos(m_loc, path, x, y);
    }

    auto MarkEntry(const char *path) -> LxResult
    {
        return m_loc[0]->MarkEntry(m_loc, path);
    }

    auto MarkBetween(const char *path, int markBefore) -> LxResult
    {
        return m_loc[0]->MarkBetween(m_loc, path, markBefore);
    }

    auto MarkAnywhere(const char *path) -> LxResult
    {
        return m_loc[0]->MarkAnywhere(m_loc, path);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_DTBGroupSortOverride
{
public:
    virtual ~CLxImpl_DTBGroupSortOverride() = default;

    virtual auto gso_SetArguments([[maybe_unused]] const char *args) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual int gso_Sort(const char *string1, const char *string2) = 0;
};

#define LXxD_DTBGroupSortOverride_SetArguments LxResult gso_SetArguments([[maybe_unused]] const char *args) override
#define LXxO_DTBGroupSortOverride_SetArguments LXxD_DTBGroupSortOverride_SetArguments
#define LXxC_DTBGroupSortOverride_SetArguments(c) LxResult c::gso_SetArguments([[maybe_unused]] const char *args)
#define LXxD_DTBGroupSortOverride_Sort int gso_Sort([[maybe_unused]] const char *string1, [[maybe_unused]] const char *string2) override
#define LXxO_DTBGroupSortOverride_Sort LXxD_DTBGroupSortOverride_Sort
#define LXxC_DTBGroupSortOverride_Sort(c) int c::gso_Sort([[maybe_unused]] const char *string1, [[maybe_unused]] const char *string2)

template <class T>
class CLxIfc_DTBGroupSortOverride: public CLxInterface
{
public:
    CLxIfc_DTBGroupSortOverride()
    {
        vt.SetArguments = SetArguments;
        vt.Sort = Sort;
        vTable = &vt.iunk;
        iid = &lx::guid_DTBGroupSortOverride;
    }

    static auto SetArguments(LXtObjectID wcom,const char *args) -> LxResult
    {
        LXCWxINST (CLxImpl_DTBGroupSortOverride, loc);
        try
        {
           return loc->gso_SetArguments( args);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Sort(LXtObjectID wcom,const char *string1,const char *string2) -> int
    {
        LXCWxINST (CLxImpl_DTBGroupSortOverride, loc);
        return loc->gso_Sort( string1, string2);
    }

private:
    ILxDTBGroupSortOverride vt;
};

class CLxLoc_DTBGroupSortOverride : public CLxLocalize<ILxDTBGroupSortOverrideID>
{
public:
    CLxLoc_DTBGroupSortOverride()
    {
        _init();
    }

    CLxLoc_DTBGroupSortOverride(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_DTBGroupSortOverride(CLxLoc_DTBGroupSortOverride const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_DTBGroupSortOverride;
    }

    auto SetArguments(const char *args) -> LxResult
    {
        return m_loc[0]->SetArguments(m_loc, args);
    }

    auto Sort(const char *string1, const char *string2) -> int
    {
        return m_loc[0]->Sort(m_loc, string1, string2);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
