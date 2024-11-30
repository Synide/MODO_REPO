//
// C++ wrapper for lxsdk/lxtreeview.h.
//
//	Copyright 2024.
//
//
#pragma once

#include <lxtreeview.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx
{
    static LXtGUID const guid_TreeView = {0x86e7a5cc, {0x9a4b, 0x4621}, {0x9f, 0x97, 0x99, 0x6e, 0x6f, 0x7f, 0x0a, 0x62}};
    static LXtGUID const guid_TreeView3 = {0xec0c5d6f, {0x9477, 0x4bae}, {0x97, 0xe8, 0x22, 0x05, 0xed, 0x1c, 0xdb, 0x23}};
    static LXtGUID const guid_TreeView2 = {0x8307d6f1, {0xc30b, 0x48e7}, {0xa0, 0xee, 0xaa, 0xb0, 0xa4, 0x5b, 0xcf, 0x1d}};
    static LXtGUID const guid_TreeView1 = {0xe4b1f6b4, {0xfed6, 0x4668}, {0x9b, 0x6b, 0x95, 0x26, 0xb5, 0x9c, 0xd9, 0xee}};
} // namespace lx

class CLxImpl_TreeView
{
public:
    virtual ~CLxImpl_TreeView() = default;

    virtual auto treeview_StoreState([[maybe_unused]] const char *uid) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto treeview_RestoreState([[maybe_unused]] const char *uid) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto treeview_StyleHints([[maybe_unused]] int *flags) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto treeview_ColumnCount([[maybe_unused]] unsigned* colCount) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto treeview_ColumnByIndex([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len, [[maybe_unused]] int *columnWidth) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto treeview_ColumnInternalName([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto treeview_ColumnIconResource([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto treeview_ColumnJustification([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] int *justification) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto treeview_PrimaryColumnPosition([[maybe_unused]] unsigned *index) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto treeview_ToPrimary([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto treeview_IsSelected([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto treeview_Select([[maybe_unused]] unsigned mode) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto treeview_CellCommand([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto treeview_BatchCommand([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto treeview_ToolTip([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto treeview_DescriptionText([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto treeview_ShowDescriptionText([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto treeview_ReservedSpaceForIcons([[maybe_unused]] int *columnIndex, [[maybe_unused]] int *width, [[maybe_unused]] int *height, [[maybe_unused]] int *iconAsValue) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto treeview_IconResource([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] int width, [[maybe_unused]] int height, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto treeview_ReservedSpaceForThumbnails([[maybe_unused]] int *columnIndex, [[maybe_unused]] int *width, [[maybe_unused]] int *height) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto treeview_Thumbnail([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] int width, [[maybe_unused]] int height, [[maybe_unused]] void **ppvObj, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto treeview_BadgeType([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] unsigned badgeIndex, [[maybe_unused]] unsigned *badgeType) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto treeview_BadgeType2([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] unsigned badgeIndex, [[maybe_unused]] unsigned *badgeType) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto treeview_BadgeDetail([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] unsigned badgeIndex, [[maybe_unused]] unsigned badgeDetail, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto treeview_IsInputRegion([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] unsigned regionID) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto treeview_SupportedDragDropSourceTypes([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto treeview_GetDragDropSourceObject([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] const char *type, [[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto treeview_GetDragDropDestinationObject([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] unsigned location, [[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto treeview_IsDescendantSelected([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto treeview_CanFilter([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto treeview_Filter([[maybe_unused]] int *flags) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_TreeView_StoreState LxResult treeview_StoreState([[maybe_unused]] const char *uid) override
#define LXxO_TreeView_StoreState LXxD_TreeView_StoreState
#define LXxC_TreeView_StoreState(c) LxResult c::treeview_StoreState([[maybe_unused]] const char *uid)
#define LXxD_TreeView_RestoreState LxResult treeview_RestoreState([[maybe_unused]] const char *uid) override
#define LXxO_TreeView_RestoreState LXxD_TreeView_RestoreState
#define LXxC_TreeView_RestoreState(c) LxResult c::treeview_RestoreState([[maybe_unused]] const char *uid)
#define LXxD_TreeView_StyleHints LxResult treeview_StyleHints([[maybe_unused]] int *flags) override
#define LXxO_TreeView_StyleHints LXxD_TreeView_StyleHints
#define LXxC_TreeView_StyleHints(c) LxResult c::treeview_StyleHints([[maybe_unused]] int *flags)
#define LXxD_TreeView_ColumnCount LxResult treeview_ColumnCount([[maybe_unused]] unsigned* colCount) override
#define LXxO_TreeView_ColumnCount LXxD_TreeView_ColumnCount
#define LXxC_TreeView_ColumnCount(c) LxResult c::treeview_ColumnCount([[maybe_unused]] unsigned* colCount)
#define LXxD_TreeView_ColumnByIndex LxResult treeview_ColumnByIndex([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len, [[maybe_unused]] int *columnWidth) override
#define LXxO_TreeView_ColumnByIndex LXxD_TreeView_ColumnByIndex
#define LXxC_TreeView_ColumnByIndex(c) LxResult c::treeview_ColumnByIndex([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len, [[maybe_unused]] int *columnWidth)
#define LXxD_TreeView_ColumnInternalName LxResult treeview_ColumnInternalName([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len) override
#define LXxO_TreeView_ColumnInternalName LXxD_TreeView_ColumnInternalName
#define LXxC_TreeView_ColumnInternalName(c) LxResult c::treeview_ColumnInternalName([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len)
#define LXxD_TreeView_ColumnIconResource LxResult treeview_ColumnIconResource([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len) override
#define LXxO_TreeView_ColumnIconResource LXxD_TreeView_ColumnIconResource
#define LXxC_TreeView_ColumnIconResource(c) LxResult c::treeview_ColumnIconResource([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len)
#define LXxD_TreeView_ColumnJustification LxResult treeview_ColumnJustification([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] int *justification) override
#define LXxO_TreeView_ColumnJustification LXxD_TreeView_ColumnJustification
#define LXxC_TreeView_ColumnJustification(c) LxResult c::treeview_ColumnJustification([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] int *justification)
#define LXxD_TreeView_PrimaryColumnPosition LxResult treeview_PrimaryColumnPosition([[maybe_unused]] unsigned *index) override
#define LXxO_TreeView_PrimaryColumnPosition LXxD_TreeView_PrimaryColumnPosition
#define LXxC_TreeView_PrimaryColumnPosition(c) LxResult c::treeview_PrimaryColumnPosition([[maybe_unused]] unsigned *index)
#define LXxD_TreeView_ToPrimary LxResult treeview_ToPrimary() override
#define LXxO_TreeView_ToPrimary LXxD_TreeView_ToPrimary
#define LXxC_TreeView_ToPrimary(c) LxResult c::treeview_ToPrimary()
#define LXxD_TreeView_IsSelected LxResult treeview_IsSelected() override
#define LXxO_TreeView_IsSelected LXxD_TreeView_IsSelected
#define LXxC_TreeView_IsSelected(c) LxResult c::treeview_IsSelected()
#define LXxD_TreeView_Select LxResult treeview_Select([[maybe_unused]] unsigned mode) override
#define LXxO_TreeView_Select LXxD_TreeView_Select
#define LXxC_TreeView_Select(c) LxResult c::treeview_Select([[maybe_unused]] unsigned mode)
#define LXxD_TreeView_CellCommand LxResult treeview_CellCommand([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len) override
#define LXxO_TreeView_CellCommand LXxD_TreeView_CellCommand
#define LXxC_TreeView_CellCommand(c) LxResult c::treeview_CellCommand([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len)
#define LXxD_TreeView_BatchCommand LxResult treeview_BatchCommand([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len) override
#define LXxO_TreeView_BatchCommand LXxD_TreeView_BatchCommand
#define LXxC_TreeView_BatchCommand(c) LxResult c::treeview_BatchCommand([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len)
#define LXxD_TreeView_ToolTip LxResult treeview_ToolTip([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len) override
#define LXxO_TreeView_ToolTip LXxD_TreeView_ToolTip
#define LXxC_TreeView_ToolTip(c) LxResult c::treeview_ToolTip([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len)
#define LXxD_TreeView_DescriptionText LxResult treeview_DescriptionText([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len) override
#define LXxO_TreeView_DescriptionText LXxD_TreeView_DescriptionText
#define LXxC_TreeView_DescriptionText(c) LxResult c::treeview_DescriptionText([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len)
#define LXxD_TreeView_ShowDescriptionText LxResult treeview_ShowDescriptionText() override
#define LXxO_TreeView_ShowDescriptionText LXxD_TreeView_ShowDescriptionText
#define LXxC_TreeView_ShowDescriptionText(c) LxResult c::treeview_ShowDescriptionText()
#define LXxD_TreeView_ReservedSpaceForIcons LxResult treeview_ReservedSpaceForIcons([[maybe_unused]] int *columnIndex, [[maybe_unused]] int *width, [[maybe_unused]] int *height, [[maybe_unused]] int *iconAsValue) override
#define LXxO_TreeView_ReservedSpaceForIcons LXxD_TreeView_ReservedSpaceForIcons
#define LXxC_TreeView_ReservedSpaceForIcons(c) LxResult c::treeview_ReservedSpaceForIcons([[maybe_unused]] int *columnIndex, [[maybe_unused]] int *width, [[maybe_unused]] int *height, [[maybe_unused]] int *iconAsValue)
#define LXxD_TreeView_IconResource LxResult treeview_IconResource([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] int width, [[maybe_unused]] int height, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len) override
#define LXxO_TreeView_IconResource LXxD_TreeView_IconResource
#define LXxC_TreeView_IconResource(c) LxResult c::treeview_IconResource([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] int width, [[maybe_unused]] int height, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len)
#define LXxD_TreeView_ReservedSpaceForThumbnails LxResult treeview_ReservedSpaceForThumbnails([[maybe_unused]] int *columnIndex, [[maybe_unused]] int *width, [[maybe_unused]] int *height) override
#define LXxO_TreeView_ReservedSpaceForThumbnails LXxD_TreeView_ReservedSpaceForThumbnails
#define LXxC_TreeView_ReservedSpaceForThumbnails(c) LxResult c::treeview_ReservedSpaceForThumbnails([[maybe_unused]] int *columnIndex, [[maybe_unused]] int *width, [[maybe_unused]] int *height)
#define LXxD_TreeView_Thumbnail LxResult treeview_Thumbnail([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] int width, [[maybe_unused]] int height, [[maybe_unused]] void **ppvObj, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len) override
#define LXxO_TreeView_Thumbnail LXxD_TreeView_Thumbnail
#define LXxC_TreeView_Thumbnail(c) LxResult c::treeview_Thumbnail([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] int width, [[maybe_unused]] int height, [[maybe_unused]] void **ppvObj, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len)
#define LXxD_TreeView_BadgeType LxResult treeview_BadgeType([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] unsigned badgeIndex, [[maybe_unused]] unsigned *badgeType) override
#define LXxO_TreeView_BadgeType LXxD_TreeView_BadgeType
#define LXxC_TreeView_BadgeType(c) LxResult c::treeview_BadgeType([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] unsigned badgeIndex, [[maybe_unused]] unsigned *badgeType)
#define LXxD_TreeView_BadgeType2 LxResult treeview_BadgeType2([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] unsigned badgeIndex, [[maybe_unused]] unsigned *badgeType) override
#define LXxO_TreeView_BadgeType2 LXxD_TreeView_BadgeType2
#define LXxC_TreeView_BadgeType2(c) LxResult c::treeview_BadgeType2([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] unsigned badgeIndex, [[maybe_unused]] unsigned *badgeType)
#define LXxD_TreeView_BadgeDetail LxResult treeview_BadgeDetail([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] unsigned badgeIndex, [[maybe_unused]] unsigned badgeDetail, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len) override
#define LXxO_TreeView_BadgeDetail LXxD_TreeView_BadgeDetail
#define LXxC_TreeView_BadgeDetail(c) LxResult c::treeview_BadgeDetail([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] unsigned badgeIndex, [[maybe_unused]] unsigned badgeDetail, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len)
#define LXxD_TreeView_IsInputRegion LxResult treeview_IsInputRegion([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] unsigned regionID) override
#define LXxO_TreeView_IsInputRegion LXxD_TreeView_IsInputRegion
#define LXxC_TreeView_IsInputRegion(c) LxResult c::treeview_IsInputRegion([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] unsigned regionID)
#define LXxD_TreeView_SupportedDragDropSourceTypes LxResult treeview_SupportedDragDropSourceTypes([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len) override
#define LXxO_TreeView_SupportedDragDropSourceTypes LXxD_TreeView_SupportedDragDropSourceTypes
#define LXxC_TreeView_SupportedDragDropSourceTypes(c) LxResult c::treeview_SupportedDragDropSourceTypes([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len)
#define LXxD_TreeView_GetDragDropSourceObject LxResult treeview_GetDragDropSourceObject([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] const char *type, [[maybe_unused]] void **ppvObj) override
#define LXxO_TreeView_GetDragDropSourceObject LXxD_TreeView_GetDragDropSourceObject
#define LXxC_TreeView_GetDragDropSourceObject(c) LxResult c::treeview_GetDragDropSourceObject([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] const char *type, [[maybe_unused]] void **ppvObj)
#define LXxD_TreeView_GetDragDropDestinationObject LxResult treeview_GetDragDropDestinationObject([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] unsigned location, [[maybe_unused]] void **ppvObj) override
#define LXxO_TreeView_GetDragDropDestinationObject LXxD_TreeView_GetDragDropDestinationObject
#define LXxC_TreeView_GetDragDropDestinationObject(c) LxResult c::treeview_GetDragDropDestinationObject([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] unsigned location, [[maybe_unused]] void **ppvObj)
#define LXxD_TreeView_IsDescendantSelected LxResult treeview_IsDescendantSelected() override
#define LXxO_TreeView_IsDescendantSelected LXxD_TreeView_IsDescendantSelected
#define LXxC_TreeView_IsDescendantSelected(c) LxResult c::treeview_IsDescendantSelected()
#define LXxD_TreeView_CanFilter LxResult treeview_CanFilter() override
#define LXxO_TreeView_CanFilter LXxD_TreeView_CanFilter
#define LXxC_TreeView_CanFilter(c) LxResult c::treeview_CanFilter()
#define LXxD_TreeView_Filter LxResult treeview_Filter([[maybe_unused]] int *flags) override
#define LXxO_TreeView_Filter LXxD_TreeView_Filter
#define LXxC_TreeView_Filter(c) LxResult c::treeview_Filter([[maybe_unused]] int *flags)

template <class T>
class CLxIfc_TreeView: public CLxInterface
{
public:
    CLxIfc_TreeView()
    {
        vt.StoreState = StoreState;
        vt.RestoreState = RestoreState;
        vt.StyleHints = StyleHints;
        vt.ColumnCount = ColumnCount;
        vt.ColumnByIndex = ColumnByIndex;
        vt.ColumnInternalName = ColumnInternalName;
        vt.ColumnIconResource = ColumnIconResource;
        vt.ColumnJustification = ColumnJustification;
        vt.PrimaryColumnPosition = PrimaryColumnPosition;
        vt.ToPrimary = ToPrimary;
        vt.IsSelected = IsSelected;
        vt.Select = Select;
        vt.CellCommand = CellCommand;
        vt.BatchCommand = BatchCommand;
        vt.ToolTip = ToolTip;
        vt.DescriptionText = DescriptionText;
        vt.ShowDescriptionText = ShowDescriptionText;
        vt.ReservedSpaceForIcons = ReservedSpaceForIcons;
        vt.IconResource = IconResource;
        vt.ReservedSpaceForThumbnails = ReservedSpaceForThumbnails;
        vt.Thumbnail = Thumbnail;
        vt.BadgeType = BadgeType;
        vt.BadgeType2 = BadgeType2;
        vt.BadgeDetail = BadgeDetail;
        vt.IsInputRegion = IsInputRegion;
        vt.SupportedDragDropSourceTypes = SupportedDragDropSourceTypes;
        vt.GetDragDropSourceObject = GetDragDropSourceObject;
        vt.GetDragDropDestinationObject = GetDragDropDestinationObject;
        vt.IsDescendantSelected = IsDescendantSelected;
        vt.CanFilter = CanFilter;
        vt.Filter = Filter;
        vTable = &vt.iunk;
        iid = &lx::guid_TreeView;
    }

    static auto StoreState(LXtObjectID wcom,const char *uid) -> LxResult
    {
        LXCWxINST (CLxImpl_TreeView, loc);
        try
        {
           return loc->treeview_StoreState( uid);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto RestoreState(LXtObjectID wcom,const char *uid) -> LxResult
    {
        LXCWxINST (CLxImpl_TreeView, loc);
        try
        {
           return loc->treeview_RestoreState( uid);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto StyleHints(LXtObjectID wcom,int *flags) -> LxResult
    {
        LXCWxINST (CLxImpl_TreeView, loc);
        try
        {
           return loc->treeview_StyleHints( flags);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ColumnCount(LXtObjectID wcom,unsigned* colCount) -> LxResult
    {
        LXCWxINST (CLxImpl_TreeView, loc);
        try
        {
           return loc->treeview_ColumnCount( colCount);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ColumnByIndex(LXtObjectID wcom,unsigned columnIndex,char *buf,unsigned len,int *columnWidth) -> LxResult
    {
        LXCWxINST (CLxImpl_TreeView, loc);
        try
        {
           return loc->treeview_ColumnByIndex( columnIndex, buf, len, columnWidth);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ColumnInternalName(LXtObjectID wcom,unsigned columnIndex,char *buf,unsigned len) -> LxResult
    {
        LXCWxINST (CLxImpl_TreeView, loc);
        try
        {
           return loc->treeview_ColumnInternalName( columnIndex, buf, len);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ColumnIconResource(LXtObjectID wcom,unsigned columnIndex,char *buf,unsigned len) -> LxResult
    {
        LXCWxINST (CLxImpl_TreeView, loc);
        try
        {
           return loc->treeview_ColumnIconResource( columnIndex, buf, len);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ColumnJustification(LXtObjectID wcom,unsigned columnIndex,int *justification) -> LxResult
    {
        LXCWxINST (CLxImpl_TreeView, loc);
        try
        {
           return loc->treeview_ColumnJustification( columnIndex, justification);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto PrimaryColumnPosition(LXtObjectID wcom,unsigned *index) -> LxResult
    {
        LXCWxINST (CLxImpl_TreeView, loc);
        try
        {
           return loc->treeview_PrimaryColumnPosition( index);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ToPrimary(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_TreeView, loc);
        try
        {
           return loc->treeview_ToPrimary();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto IsSelected(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_TreeView, loc);
        try
        {
           return loc->treeview_IsSelected();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Select(LXtObjectID wcom,unsigned mode) -> LxResult
    {
        LXCWxINST (CLxImpl_TreeView, loc);
        try
        {
           return loc->treeview_Select( mode);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto CellCommand(LXtObjectID wcom,unsigned columnIndex,char *buf,unsigned len) -> LxResult
    {
        LXCWxINST (CLxImpl_TreeView, loc);
        try
        {
           return loc->treeview_CellCommand( columnIndex, buf, len);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto BatchCommand(LXtObjectID wcom,unsigned columnIndex,char *buf,unsigned len) -> LxResult
    {
        LXCWxINST (CLxImpl_TreeView, loc);
        try
        {
           return loc->treeview_BatchCommand( columnIndex, buf, len);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ToolTip(LXtObjectID wcom,unsigned columnIndex,char *buf,unsigned len) -> LxResult
    {
        LXCWxINST (CLxImpl_TreeView, loc);
        try
        {
           return loc->treeview_ToolTip( columnIndex, buf, len);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto DescriptionText(LXtObjectID wcom,unsigned columnIndex,char *buf,unsigned len) -> LxResult
    {
        LXCWxINST (CLxImpl_TreeView, loc);
        try
        {
           return loc->treeview_DescriptionText( columnIndex, buf, len);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ShowDescriptionText(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_TreeView, loc);
        try
        {
           return loc->treeview_ShowDescriptionText();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ReservedSpaceForIcons(LXtObjectID wcom,int *columnIndex,int *width,int *height,int *iconAsValue) -> LxResult
    {
        LXCWxINST (CLxImpl_TreeView, loc);
        try
        {
           return loc->treeview_ReservedSpaceForIcons( columnIndex, width, height, iconAsValue);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto IconResource(LXtObjectID wcom,unsigned columnIndex,int width,int height,char *buf,unsigned len) -> LxResult
    {
        LXCWxINST (CLxImpl_TreeView, loc);
        try
        {
           return loc->treeview_IconResource( columnIndex, width, height, buf, len);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ReservedSpaceForThumbnails(LXtObjectID wcom,int *columnIndex,int *width,int *height) -> LxResult
    {
        LXCWxINST (CLxImpl_TreeView, loc);
        try
        {
           return loc->treeview_ReservedSpaceForThumbnails( columnIndex, width, height);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Thumbnail(LXtObjectID wcom,unsigned columnIndex,int width,int height,void **ppvObj,char *buf,unsigned len) -> LxResult
    {
        LXCWxINST (CLxImpl_TreeView, loc);
        try
        {
           return loc->treeview_Thumbnail( columnIndex, width, height, ppvObj, buf, len);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto BadgeType(LXtObjectID wcom,unsigned columnIndex,unsigned badgeIndex,unsigned *badgeType) -> LxResult
    {
        LXCWxINST (CLxImpl_TreeView, loc);
        try
        {
           return loc->treeview_BadgeType( columnIndex, badgeIndex, badgeType);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto BadgeType2(LXtObjectID wcom,unsigned columnIndex,unsigned badgeIndex,unsigned *badgeType) -> LxResult
    {
        LXCWxINST (CLxImpl_TreeView, loc);
        try
        {
           return loc->treeview_BadgeType2( columnIndex, badgeIndex, badgeType);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto BadgeDetail(LXtObjectID wcom,unsigned columnIndex,unsigned badgeIndex,unsigned badgeDetail,char *buf,unsigned len) -> LxResult
    {
        LXCWxINST (CLxImpl_TreeView, loc);
        try
        {
           return loc->treeview_BadgeDetail( columnIndex, badgeIndex, badgeDetail, buf, len);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto IsInputRegion(LXtObjectID wcom,unsigned columnIndex,unsigned regionID) -> LxResult
    {
        LXCWxINST (CLxImpl_TreeView, loc);
        try
        {
           return loc->treeview_IsInputRegion( columnIndex, regionID);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SupportedDragDropSourceTypes(LXtObjectID wcom,unsigned columnIndex,char *buf,unsigned len) -> LxResult
    {
        LXCWxINST (CLxImpl_TreeView, loc);
        try
        {
           return loc->treeview_SupportedDragDropSourceTypes( columnIndex, buf, len);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto GetDragDropSourceObject(LXtObjectID wcom,unsigned columnIndex,const char *type,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_TreeView, loc);
        try
        {
           return loc->treeview_GetDragDropSourceObject( columnIndex, type, ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto GetDragDropDestinationObject(LXtObjectID wcom,unsigned columnIndex,unsigned location,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_TreeView, loc);
        try
        {
           return loc->treeview_GetDragDropDestinationObject( columnIndex, location, ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto IsDescendantSelected(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_TreeView, loc);
        try
        {
           return loc->treeview_IsDescendantSelected();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto CanFilter(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_TreeView, loc);
        try
        {
           return loc->treeview_CanFilter();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Filter(LXtObjectID wcom,int *flags) -> LxResult
    {
        LXCWxINST (CLxImpl_TreeView, loc);
        try
        {
           return loc->treeview_Filter( flags);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxTreeView vt;
};

class CLxLoc_TreeView : public CLxLocalize<ILxTreeViewID>
{
public:
    CLxLoc_TreeView()
    {
        _init();
    }

    CLxLoc_TreeView(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_TreeView(CLxLoc_TreeView const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_TreeView;
    }

    auto StoreState(const char *uid) -> LxResult
    {
        return m_loc[0]->StoreState(m_loc, uid);
    }

    auto RestoreState(const char *uid) -> LxResult
    {
        return m_loc[0]->RestoreState(m_loc, uid);
    }

    auto StyleHints(int *flags) -> LxResult
    {
        return m_loc[0]->StyleHints(m_loc, flags);
    }

    auto ColumnCount(unsigned* colCount) -> LxResult
    {
        return m_loc[0]->ColumnCount(m_loc, colCount);
    }

    auto ColumnByIndex(unsigned columnIndex, char *buf, unsigned len, int *columnWidth) -> LxResult
    {
        return m_loc[0]->ColumnByIndex(m_loc, columnIndex, buf, len, columnWidth);
    }

    auto ColumnByIndex(unsigned columnIndex, std::string &result, int *columnWidth) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->ColumnByIndex(m_loc, columnIndex, buf, len, columnWidth);
        LXWx_SBUF2
    }

    auto ColumnInternalName(unsigned columnIndex, char *buf, unsigned len) -> LxResult
    {
        return m_loc[0]->ColumnInternalName(m_loc, columnIndex, buf, len);
    }

    auto ColumnInternalName(unsigned columnIndex, std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->ColumnInternalName(m_loc, columnIndex, buf, len);
        LXWx_SBUF2
    }

    auto ColumnIconResource(unsigned columnIndex, char *buf, unsigned len) -> LxResult
    {
        return m_loc[0]->ColumnIconResource(m_loc, columnIndex, buf, len);
    }

    auto ColumnIconResource(unsigned columnIndex, std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->ColumnIconResource(m_loc, columnIndex, buf, len);
        LXWx_SBUF2
    }

    auto ColumnJustification(unsigned columnIndex, int *justification) -> LxResult
    {
        return m_loc[0]->ColumnJustification(m_loc, columnIndex, justification);
    }

    auto PrimaryColumnPosition(unsigned *index) -> LxResult
    {
        return m_loc[0]->PrimaryColumnPosition(m_loc, index);
    }

    auto ToPrimary(void) -> LxResult
    {
        return m_loc[0]->ToPrimary(m_loc);
    }

    auto IsSelected(void) -> LxResult
    {
        return m_loc[0]->IsSelected(m_loc);
    }

    auto Select(unsigned mode) -> LxResult
    {
        return m_loc[0]->Select(m_loc, mode);
    }

    auto CellCommand(unsigned columnIndex, char *buf, unsigned len) -> LxResult
    {
        return m_loc[0]->CellCommand(m_loc, columnIndex, buf, len);
    }

    auto CellCommand(unsigned columnIndex, std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->CellCommand(m_loc, columnIndex, buf, len);
        LXWx_SBUF2
    }

    auto BatchCommand(unsigned columnIndex, char *buf, unsigned len) -> LxResult
    {
        return m_loc[0]->BatchCommand(m_loc, columnIndex, buf, len);
    }

    auto BatchCommand(unsigned columnIndex, std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->BatchCommand(m_loc, columnIndex, buf, len);
        LXWx_SBUF2
    }

    auto ToolTip(unsigned columnIndex, char *buf, unsigned len) -> LxResult
    {
        return m_loc[0]->ToolTip(m_loc, columnIndex, buf, len);
    }

    auto ToolTip(unsigned columnIndex, std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->ToolTip(m_loc, columnIndex, buf, len);
        LXWx_SBUF2
    }

    auto DescriptionText(unsigned columnIndex, char *buf, unsigned len) -> LxResult
    {
        return m_loc[0]->DescriptionText(m_loc, columnIndex, buf, len);
    }

    auto DescriptionText(unsigned columnIndex, std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->DescriptionText(m_loc, columnIndex, buf, len);
        LXWx_SBUF2
    }

    auto ShowDescriptionText(void) -> LxResult
    {
        return m_loc[0]->ShowDescriptionText(m_loc);
    }

    auto ReservedSpaceForIcons(int *columnIndex, int *width, int *height, int *iconAsValue) -> LxResult
    {
        return m_loc[0]->ReservedSpaceForIcons(m_loc, columnIndex, width, height, iconAsValue);
    }

    auto IconResource(unsigned columnIndex, int width, int height, char *buf, unsigned len) -> LxResult
    {
        return m_loc[0]->IconResource(m_loc, columnIndex, width, height, buf, len);
    }

    auto IconResource(unsigned columnIndex, int width, int height, std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->IconResource(m_loc, columnIndex, width, height, buf, len);
        LXWx_SBUF2
    }

    auto ReservedSpaceForThumbnails(int *columnIndex, int *width, int *height) -> LxResult
    {
        return m_loc[0]->ReservedSpaceForThumbnails(m_loc, columnIndex, width, height);
    }

    auto Thumbnail(unsigned columnIndex, int width, int height, void **ppvObj, char *buf, unsigned len) -> LxResult
    {
        return m_loc[0]->Thumbnail(m_loc, columnIndex, width, height, ppvObj, buf, len);
    }

    auto Thumbnail(unsigned columnIndex, int width, int height, CLxLocalizedObject &o_dest, char *buf, unsigned len) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Thumbnail(m_loc, columnIndex, width, height, &o_obj, buf, len);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Thumbnail(unsigned columnIndex, int width, int height, void **ppvObj, std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->Thumbnail(m_loc, columnIndex, width, height, ppvObj, buf, len);
        LXWx_SBUF2
    }

    auto BadgeType(unsigned columnIndex, unsigned badgeIndex, unsigned *badgeType) -> LxResult
    {
        return m_loc[0]->BadgeType(m_loc, columnIndex, badgeIndex, badgeType);
    }

    auto BadgeType2(unsigned columnIndex, unsigned badgeIndex, unsigned *badgeType) -> LxResult
    {
        return m_loc[0]->BadgeType2(m_loc, columnIndex, badgeIndex, badgeType);
    }

    auto BadgeDetail(unsigned columnIndex, unsigned badgeIndex, unsigned badgeDetail, char *buf, unsigned len) -> LxResult
    {
        return m_loc[0]->BadgeDetail(m_loc, columnIndex, badgeIndex, badgeDetail, buf, len);
    }

    auto BadgeDetail(unsigned columnIndex, unsigned badgeIndex, unsigned badgeDetail, std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->BadgeDetail(m_loc, columnIndex, badgeIndex, badgeDetail, buf, len);
        LXWx_SBUF2
    }

    auto IsInputRegion(unsigned columnIndex, unsigned regionID) -> LxResult
    {
        return m_loc[0]->IsInputRegion(m_loc, columnIndex, regionID);
    }

    auto SupportedDragDropSourceTypes(unsigned columnIndex, char *buf, unsigned len) -> LxResult
    {
        return m_loc[0]->SupportedDragDropSourceTypes(m_loc, columnIndex, buf, len);
    }

    auto SupportedDragDropSourceTypes(unsigned columnIndex, std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->SupportedDragDropSourceTypes(m_loc, columnIndex, buf, len);
        LXWx_SBUF2
    }

    auto GetDragDropSourceObject(unsigned columnIndex, const char *type, void **ppvObj) -> LxResult
    {
        return m_loc[0]->GetDragDropSourceObject(m_loc, columnIndex, type, ppvObj);
    }

    auto GetDragDropSourceObject(unsigned columnIndex, const char *type, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->GetDragDropSourceObject(m_loc, columnIndex, type, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto GetDragDropDestinationObject(unsigned columnIndex, unsigned location, void **ppvObj) -> LxResult
    {
        return m_loc[0]->GetDragDropDestinationObject(m_loc, columnIndex, location, ppvObj);
    }

    auto GetDragDropDestinationObject(unsigned columnIndex, unsigned location, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->GetDragDropDestinationObject(m_loc, columnIndex, location, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto IsDescendantSelected(void) -> LxResult
    {
        return m_loc[0]->IsDescendantSelected(m_loc);
    }

    auto CanFilter(void) -> LxResult
    {
        return m_loc[0]->CanFilter(m_loc);
    }

    auto Filter(int *flags) -> LxResult
    {
        return m_loc[0]->Filter(m_loc, flags);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_TreeView3
{
public:
    virtual ~CLxImpl_TreeView3() = default;

    virtual auto treeview3_StoreState([[maybe_unused]] const char *uid) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto treeview3_RestoreState([[maybe_unused]] const char *uid) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto treeview3_ColumnCount([[maybe_unused]] unsigned* colCount) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto treeview3_ColumnByIndex([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len, [[maybe_unused]] int *columnWidth) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto treeview3_ColumnInternalName([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto treeview3_ColumnIconResource([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto treeview3_ColumnJustification([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] int *justification) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto treeview3_PrimaryColumnPosition([[maybe_unused]] unsigned *index) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto treeview3_ToPrimary([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto treeview3_IsSelected([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto treeview3_Select([[maybe_unused]] unsigned mode) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto treeview3_CellCommand([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto treeview3_BatchCommand([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto treeview3_ToolTip([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto treeview3_BadgeType([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] unsigned badgeIndex, [[maybe_unused]] unsigned *badgeType) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto treeview3_BadgeDetail([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] unsigned badgeIndex, [[maybe_unused]] unsigned badgeDetail, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto treeview3_IsInputRegion([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] unsigned regionID) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto treeview3_SupportedDragDropSourceTypes([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto treeview3_GetDragDropSourceObject([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] const char *type, [[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto treeview3_GetDragDropDestinationObject([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] unsigned location, [[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto treeview3_IsDescendantSelected([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_TreeView3_StoreState LxResult treeview3_StoreState([[maybe_unused]] const char *uid) override
#define LXxO_TreeView3_StoreState LXxD_TreeView3_StoreState
#define LXxC_TreeView3_StoreState(c) LxResult c::treeview3_StoreState([[maybe_unused]] const char *uid)
#define LXxD_TreeView3_RestoreState LxResult treeview3_RestoreState([[maybe_unused]] const char *uid) override
#define LXxO_TreeView3_RestoreState LXxD_TreeView3_RestoreState
#define LXxC_TreeView3_RestoreState(c) LxResult c::treeview3_RestoreState([[maybe_unused]] const char *uid)
#define LXxD_TreeView3_ColumnCount LxResult treeview3_ColumnCount([[maybe_unused]] unsigned* colCount) override
#define LXxO_TreeView3_ColumnCount LXxD_TreeView3_ColumnCount
#define LXxC_TreeView3_ColumnCount(c) LxResult c::treeview3_ColumnCount([[maybe_unused]] unsigned* colCount)
#define LXxD_TreeView3_ColumnByIndex LxResult treeview3_ColumnByIndex([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len, [[maybe_unused]] int *columnWidth) override
#define LXxO_TreeView3_ColumnByIndex LXxD_TreeView3_ColumnByIndex
#define LXxC_TreeView3_ColumnByIndex(c) LxResult c::treeview3_ColumnByIndex([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len, [[maybe_unused]] int *columnWidth)
#define LXxD_TreeView3_ColumnInternalName LxResult treeview3_ColumnInternalName([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len) override
#define LXxO_TreeView3_ColumnInternalName LXxD_TreeView3_ColumnInternalName
#define LXxC_TreeView3_ColumnInternalName(c) LxResult c::treeview3_ColumnInternalName([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len)
#define LXxD_TreeView3_ColumnIconResource LxResult treeview3_ColumnIconResource([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len) override
#define LXxO_TreeView3_ColumnIconResource LXxD_TreeView3_ColumnIconResource
#define LXxC_TreeView3_ColumnIconResource(c) LxResult c::treeview3_ColumnIconResource([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len)
#define LXxD_TreeView3_ColumnJustification LxResult treeview3_ColumnJustification([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] int *justification) override
#define LXxO_TreeView3_ColumnJustification LXxD_TreeView3_ColumnJustification
#define LXxC_TreeView3_ColumnJustification(c) LxResult c::treeview3_ColumnJustification([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] int *justification)
#define LXxD_TreeView3_PrimaryColumnPosition LxResult treeview3_PrimaryColumnPosition([[maybe_unused]] unsigned *index) override
#define LXxO_TreeView3_PrimaryColumnPosition LXxD_TreeView3_PrimaryColumnPosition
#define LXxC_TreeView3_PrimaryColumnPosition(c) LxResult c::treeview3_PrimaryColumnPosition([[maybe_unused]] unsigned *index)
#define LXxD_TreeView3_ToPrimary LxResult treeview3_ToPrimary() override
#define LXxO_TreeView3_ToPrimary LXxD_TreeView3_ToPrimary
#define LXxC_TreeView3_ToPrimary(c) LxResult c::treeview3_ToPrimary()
#define LXxD_TreeView3_IsSelected LxResult treeview3_IsSelected() override
#define LXxO_TreeView3_IsSelected LXxD_TreeView3_IsSelected
#define LXxC_TreeView3_IsSelected(c) LxResult c::treeview3_IsSelected()
#define LXxD_TreeView3_Select LxResult treeview3_Select([[maybe_unused]] unsigned mode) override
#define LXxO_TreeView3_Select LXxD_TreeView3_Select
#define LXxC_TreeView3_Select(c) LxResult c::treeview3_Select([[maybe_unused]] unsigned mode)
#define LXxD_TreeView3_CellCommand LxResult treeview3_CellCommand([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len) override
#define LXxO_TreeView3_CellCommand LXxD_TreeView3_CellCommand
#define LXxC_TreeView3_CellCommand(c) LxResult c::treeview3_CellCommand([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len)
#define LXxD_TreeView3_BatchCommand LxResult treeview3_BatchCommand([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len) override
#define LXxO_TreeView3_BatchCommand LXxD_TreeView3_BatchCommand
#define LXxC_TreeView3_BatchCommand(c) LxResult c::treeview3_BatchCommand([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len)
#define LXxD_TreeView3_ToolTip LxResult treeview3_ToolTip([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len) override
#define LXxO_TreeView3_ToolTip LXxD_TreeView3_ToolTip
#define LXxC_TreeView3_ToolTip(c) LxResult c::treeview3_ToolTip([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len)
#define LXxD_TreeView3_BadgeType LxResult treeview3_BadgeType([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] unsigned badgeIndex, [[maybe_unused]] unsigned *badgeType) override
#define LXxO_TreeView3_BadgeType LXxD_TreeView3_BadgeType
#define LXxC_TreeView3_BadgeType(c) LxResult c::treeview3_BadgeType([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] unsigned badgeIndex, [[maybe_unused]] unsigned *badgeType)
#define LXxD_TreeView3_BadgeDetail LxResult treeview3_BadgeDetail([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] unsigned badgeIndex, [[maybe_unused]] unsigned badgeDetail, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len) override
#define LXxO_TreeView3_BadgeDetail LXxD_TreeView3_BadgeDetail
#define LXxC_TreeView3_BadgeDetail(c) LxResult c::treeview3_BadgeDetail([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] unsigned badgeIndex, [[maybe_unused]] unsigned badgeDetail, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len)
#define LXxD_TreeView3_IsInputRegion LxResult treeview3_IsInputRegion([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] unsigned regionID) override
#define LXxO_TreeView3_IsInputRegion LXxD_TreeView3_IsInputRegion
#define LXxC_TreeView3_IsInputRegion(c) LxResult c::treeview3_IsInputRegion([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] unsigned regionID)
#define LXxD_TreeView3_SupportedDragDropSourceTypes LxResult treeview3_SupportedDragDropSourceTypes([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len) override
#define LXxO_TreeView3_SupportedDragDropSourceTypes LXxD_TreeView3_SupportedDragDropSourceTypes
#define LXxC_TreeView3_SupportedDragDropSourceTypes(c) LxResult c::treeview3_SupportedDragDropSourceTypes([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len)
#define LXxD_TreeView3_GetDragDropSourceObject LxResult treeview3_GetDragDropSourceObject([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] const char *type, [[maybe_unused]] void **ppvObj) override
#define LXxO_TreeView3_GetDragDropSourceObject LXxD_TreeView3_GetDragDropSourceObject
#define LXxC_TreeView3_GetDragDropSourceObject(c) LxResult c::treeview3_GetDragDropSourceObject([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] const char *type, [[maybe_unused]] void **ppvObj)
#define LXxD_TreeView3_GetDragDropDestinationObject LxResult treeview3_GetDragDropDestinationObject([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] unsigned location, [[maybe_unused]] void **ppvObj) override
#define LXxO_TreeView3_GetDragDropDestinationObject LXxD_TreeView3_GetDragDropDestinationObject
#define LXxC_TreeView3_GetDragDropDestinationObject(c) LxResult c::treeview3_GetDragDropDestinationObject([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] unsigned location, [[maybe_unused]] void **ppvObj)
#define LXxD_TreeView3_IsDescendantSelected LxResult treeview3_IsDescendantSelected() override
#define LXxO_TreeView3_IsDescendantSelected LXxD_TreeView3_IsDescendantSelected
#define LXxC_TreeView3_IsDescendantSelected(c) LxResult c::treeview3_IsDescendantSelected()

template <class T>
class CLxIfc_TreeView3: public CLxInterface
{
public:
    CLxIfc_TreeView3()
    {
        vt.StoreState = StoreState;
        vt.RestoreState = RestoreState;
        vt.ColumnCount = ColumnCount;
        vt.ColumnByIndex = ColumnByIndex;
        vt.ColumnInternalName = ColumnInternalName;
        vt.ColumnIconResource = ColumnIconResource;
        vt.ColumnJustification = ColumnJustification;
        vt.PrimaryColumnPosition = PrimaryColumnPosition;
        vt.ToPrimary = ToPrimary;
        vt.IsSelected = IsSelected;
        vt.Select = Select;
        vt.CellCommand = CellCommand;
        vt.BatchCommand = BatchCommand;
        vt.ToolTip = ToolTip;
        vt.BadgeType = BadgeType;
        vt.BadgeDetail = BadgeDetail;
        vt.IsInputRegion = IsInputRegion;
        vt.SupportedDragDropSourceTypes = SupportedDragDropSourceTypes;
        vt.GetDragDropSourceObject = GetDragDropSourceObject;
        vt.GetDragDropDestinationObject = GetDragDropDestinationObject;
        vt.IsDescendantSelected = IsDescendantSelected;
        vTable = &vt.iunk;
        iid = &lx::guid_TreeView3;
    }

    static auto StoreState(LXtObjectID wcom,const char *uid) -> LxResult
    {
        LXCWxINST (CLxImpl_TreeView3, loc);
        try
        {
           return loc->treeview3_StoreState( uid);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto RestoreState(LXtObjectID wcom,const char *uid) -> LxResult
    {
        LXCWxINST (CLxImpl_TreeView3, loc);
        try
        {
           return loc->treeview3_RestoreState( uid);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ColumnCount(LXtObjectID wcom,unsigned* colCount) -> LxResult
    {
        LXCWxINST (CLxImpl_TreeView3, loc);
        try
        {
           return loc->treeview3_ColumnCount( colCount);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ColumnByIndex(LXtObjectID wcom,unsigned columnIndex,char *buf,unsigned len,int *columnWidth) -> LxResult
    {
        LXCWxINST (CLxImpl_TreeView3, loc);
        try
        {
           return loc->treeview3_ColumnByIndex( columnIndex, buf, len, columnWidth);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ColumnInternalName(LXtObjectID wcom,unsigned columnIndex,char *buf,unsigned len) -> LxResult
    {
        LXCWxINST (CLxImpl_TreeView3, loc);
        try
        {
           return loc->treeview3_ColumnInternalName( columnIndex, buf, len);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ColumnIconResource(LXtObjectID wcom,unsigned columnIndex,char *buf,unsigned len) -> LxResult
    {
        LXCWxINST (CLxImpl_TreeView3, loc);
        try
        {
           return loc->treeview3_ColumnIconResource( columnIndex, buf, len);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ColumnJustification(LXtObjectID wcom,unsigned columnIndex,int *justification) -> LxResult
    {
        LXCWxINST (CLxImpl_TreeView3, loc);
        try
        {
           return loc->treeview3_ColumnJustification( columnIndex, justification);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto PrimaryColumnPosition(LXtObjectID wcom,unsigned *index) -> LxResult
    {
        LXCWxINST (CLxImpl_TreeView3, loc);
        try
        {
           return loc->treeview3_PrimaryColumnPosition( index);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ToPrimary(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_TreeView3, loc);
        try
        {
           return loc->treeview3_ToPrimary();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto IsSelected(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_TreeView3, loc);
        try
        {
           return loc->treeview3_IsSelected();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Select(LXtObjectID wcom,unsigned mode) -> LxResult
    {
        LXCWxINST (CLxImpl_TreeView3, loc);
        try
        {
           return loc->treeview3_Select( mode);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto CellCommand(LXtObjectID wcom,unsigned columnIndex,char *buf,unsigned len) -> LxResult
    {
        LXCWxINST (CLxImpl_TreeView3, loc);
        try
        {
           return loc->treeview3_CellCommand( columnIndex, buf, len);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto BatchCommand(LXtObjectID wcom,unsigned columnIndex,char *buf,unsigned len) -> LxResult
    {
        LXCWxINST (CLxImpl_TreeView3, loc);
        try
        {
           return loc->treeview3_BatchCommand( columnIndex, buf, len);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ToolTip(LXtObjectID wcom,unsigned columnIndex,char *buf,unsigned len) -> LxResult
    {
        LXCWxINST (CLxImpl_TreeView3, loc);
        try
        {
           return loc->treeview3_ToolTip( columnIndex, buf, len);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto BadgeType(LXtObjectID wcom,unsigned columnIndex,unsigned badgeIndex,unsigned *badgeType) -> LxResult
    {
        LXCWxINST (CLxImpl_TreeView3, loc);
        try
        {
           return loc->treeview3_BadgeType( columnIndex, badgeIndex, badgeType);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto BadgeDetail(LXtObjectID wcom,unsigned columnIndex,unsigned badgeIndex,unsigned badgeDetail,char *buf,unsigned len) -> LxResult
    {
        LXCWxINST (CLxImpl_TreeView3, loc);
        try
        {
           return loc->treeview3_BadgeDetail( columnIndex, badgeIndex, badgeDetail, buf, len);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto IsInputRegion(LXtObjectID wcom,unsigned columnIndex,unsigned regionID) -> LxResult
    {
        LXCWxINST (CLxImpl_TreeView3, loc);
        try
        {
           return loc->treeview3_IsInputRegion( columnIndex, regionID);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SupportedDragDropSourceTypes(LXtObjectID wcom,unsigned columnIndex,char *buf,unsigned len) -> LxResult
    {
        LXCWxINST (CLxImpl_TreeView3, loc);
        try
        {
           return loc->treeview3_SupportedDragDropSourceTypes( columnIndex, buf, len);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto GetDragDropSourceObject(LXtObjectID wcom,unsigned columnIndex,const char *type,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_TreeView3, loc);
        try
        {
           return loc->treeview3_GetDragDropSourceObject( columnIndex, type, ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto GetDragDropDestinationObject(LXtObjectID wcom,unsigned columnIndex,unsigned location,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_TreeView3, loc);
        try
        {
           return loc->treeview3_GetDragDropDestinationObject( columnIndex, location, ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto IsDescendantSelected(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_TreeView3, loc);
        try
        {
           return loc->treeview3_IsDescendantSelected();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxTreeView3 vt;
};

class CLxLoc_TreeView3 : public CLxLocalize<ILxTreeView3ID>
{
public:
    CLxLoc_TreeView3()
    {
        _init();
    }

    CLxLoc_TreeView3(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_TreeView3(CLxLoc_TreeView3 const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_TreeView3;
    }

    auto StoreState(const char *uid) -> LxResult
    {
        return m_loc[0]->StoreState(m_loc, uid);
    }

    auto RestoreState(const char *uid) -> LxResult
    {
        return m_loc[0]->RestoreState(m_loc, uid);
    }

    auto ColumnCount(unsigned* colCount) -> LxResult
    {
        return m_loc[0]->ColumnCount(m_loc, colCount);
    }

    auto ColumnByIndex(unsigned columnIndex, char *buf, unsigned len, int *columnWidth) -> LxResult
    {
        return m_loc[0]->ColumnByIndex(m_loc, columnIndex, buf, len, columnWidth);
    }

    auto ColumnByIndex(unsigned columnIndex, std::string &result, int *columnWidth) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->ColumnByIndex(m_loc, columnIndex, buf, len, columnWidth);
        LXWx_SBUF2
    }

    auto ColumnInternalName(unsigned columnIndex, char *buf, unsigned len) -> LxResult
    {
        return m_loc[0]->ColumnInternalName(m_loc, columnIndex, buf, len);
    }

    auto ColumnInternalName(unsigned columnIndex, std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->ColumnInternalName(m_loc, columnIndex, buf, len);
        LXWx_SBUF2
    }

    auto ColumnIconResource(unsigned columnIndex, char *buf, unsigned len) -> LxResult
    {
        return m_loc[0]->ColumnIconResource(m_loc, columnIndex, buf, len);
    }

    auto ColumnIconResource(unsigned columnIndex, std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->ColumnIconResource(m_loc, columnIndex, buf, len);
        LXWx_SBUF2
    }

    auto ColumnJustification(unsigned columnIndex, int *justification) -> LxResult
    {
        return m_loc[0]->ColumnJustification(m_loc, columnIndex, justification);
    }

    auto PrimaryColumnPosition(unsigned *index) -> LxResult
    {
        return m_loc[0]->PrimaryColumnPosition(m_loc, index);
    }

    auto ToPrimary(void) -> LxResult
    {
        return m_loc[0]->ToPrimary(m_loc);
    }

    auto IsSelected(void) -> LxResult
    {
        return m_loc[0]->IsSelected(m_loc);
    }

    auto Select(unsigned mode) -> LxResult
    {
        return m_loc[0]->Select(m_loc, mode);
    }

    auto CellCommand(unsigned columnIndex, char *buf, unsigned len) -> LxResult
    {
        return m_loc[0]->CellCommand(m_loc, columnIndex, buf, len);
    }

    auto CellCommand(unsigned columnIndex, std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->CellCommand(m_loc, columnIndex, buf, len);
        LXWx_SBUF2
    }

    auto BatchCommand(unsigned columnIndex, char *buf, unsigned len) -> LxResult
    {
        return m_loc[0]->BatchCommand(m_loc, columnIndex, buf, len);
    }

    auto BatchCommand(unsigned columnIndex, std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->BatchCommand(m_loc, columnIndex, buf, len);
        LXWx_SBUF2
    }

    auto ToolTip(unsigned columnIndex, char *buf, unsigned len) -> LxResult
    {
        return m_loc[0]->ToolTip(m_loc, columnIndex, buf, len);
    }

    auto ToolTip(unsigned columnIndex, std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->ToolTip(m_loc, columnIndex, buf, len);
        LXWx_SBUF2
    }

    auto BadgeType(unsigned columnIndex, unsigned badgeIndex, unsigned *badgeType) -> LxResult
    {
        return m_loc[0]->BadgeType(m_loc, columnIndex, badgeIndex, badgeType);
    }

    auto BadgeDetail(unsigned columnIndex, unsigned badgeIndex, unsigned badgeDetail, char *buf, unsigned len) -> LxResult
    {
        return m_loc[0]->BadgeDetail(m_loc, columnIndex, badgeIndex, badgeDetail, buf, len);
    }

    auto BadgeDetail(unsigned columnIndex, unsigned badgeIndex, unsigned badgeDetail, std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->BadgeDetail(m_loc, columnIndex, badgeIndex, badgeDetail, buf, len);
        LXWx_SBUF2
    }

    auto IsInputRegion(unsigned columnIndex, unsigned regionID) -> LxResult
    {
        return m_loc[0]->IsInputRegion(m_loc, columnIndex, regionID);
    }

    auto SupportedDragDropSourceTypes(unsigned columnIndex, char *buf, unsigned len) -> LxResult
    {
        return m_loc[0]->SupportedDragDropSourceTypes(m_loc, columnIndex, buf, len);
    }

    auto SupportedDragDropSourceTypes(unsigned columnIndex, std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->SupportedDragDropSourceTypes(m_loc, columnIndex, buf, len);
        LXWx_SBUF2
    }

    auto GetDragDropSourceObject(unsigned columnIndex, const char *type, void **ppvObj) -> LxResult
    {
        return m_loc[0]->GetDragDropSourceObject(m_loc, columnIndex, type, ppvObj);
    }

    auto GetDragDropSourceObject(unsigned columnIndex, const char *type, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->GetDragDropSourceObject(m_loc, columnIndex, type, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto GetDragDropDestinationObject(unsigned columnIndex, unsigned location, void **ppvObj) -> LxResult
    {
        return m_loc[0]->GetDragDropDestinationObject(m_loc, columnIndex, location, ppvObj);
    }

    auto GetDragDropDestinationObject(unsigned columnIndex, unsigned location, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->GetDragDropDestinationObject(m_loc, columnIndex, location, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto IsDescendantSelected(void) -> LxResult
    {
        return m_loc[0]->IsDescendantSelected(m_loc);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_TreeView2
{
public:
    virtual ~CLxImpl_TreeView2() = default;

    virtual auto treeview2_StoreState([[maybe_unused]] const char *uid) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto treeview2_RestoreState([[maybe_unused]] const char *uid) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto treeview2_ColumnCount([[maybe_unused]] unsigned* colCount) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto treeview2_ColumnByIndex([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len, [[maybe_unused]] int *columnWidth) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto treeview2_ColumnInternalName([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto treeview2_ColumnIconResource([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto treeview2_ColumnJustification([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] int *justification) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto treeview2_PrimaryColumnPosition([[maybe_unused]] unsigned *index) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto treeview2_ToPrimary([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto treeview2_IsSelected([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto treeview2_Select([[maybe_unused]] unsigned mode) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto treeview2_CellCommand([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto treeview2_BatchCommand([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto treeview2_ToolTip([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto treeview2_BadgeType([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] unsigned badgeIndex, [[maybe_unused]] unsigned *badgeType) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto treeview2_BadgeDetail([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] unsigned badgeIndex, [[maybe_unused]] unsigned badgeDetail, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto treeview2_IsInputRegion([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] unsigned regionID) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto treeview2_SupportedDragDropSourceTypes([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto treeview2_GetDragDropSourceObject([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] const char *type, [[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto treeview2_GetDragDropDestinationObject([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] unsigned location, [[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_TreeView2_StoreState LxResult treeview2_StoreState([[maybe_unused]] const char *uid) override
#define LXxO_TreeView2_StoreState LXxD_TreeView2_StoreState
#define LXxC_TreeView2_StoreState(c) LxResult c::treeview2_StoreState([[maybe_unused]] const char *uid)
#define LXxD_TreeView2_RestoreState LxResult treeview2_RestoreState([[maybe_unused]] const char *uid) override
#define LXxO_TreeView2_RestoreState LXxD_TreeView2_RestoreState
#define LXxC_TreeView2_RestoreState(c) LxResult c::treeview2_RestoreState([[maybe_unused]] const char *uid)
#define LXxD_TreeView2_ColumnCount LxResult treeview2_ColumnCount([[maybe_unused]] unsigned* colCount) override
#define LXxO_TreeView2_ColumnCount LXxD_TreeView2_ColumnCount
#define LXxC_TreeView2_ColumnCount(c) LxResult c::treeview2_ColumnCount([[maybe_unused]] unsigned* colCount)
#define LXxD_TreeView2_ColumnByIndex LxResult treeview2_ColumnByIndex([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len, [[maybe_unused]] int *columnWidth) override
#define LXxO_TreeView2_ColumnByIndex LXxD_TreeView2_ColumnByIndex
#define LXxC_TreeView2_ColumnByIndex(c) LxResult c::treeview2_ColumnByIndex([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len, [[maybe_unused]] int *columnWidth)
#define LXxD_TreeView2_ColumnInternalName LxResult treeview2_ColumnInternalName([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len) override
#define LXxO_TreeView2_ColumnInternalName LXxD_TreeView2_ColumnInternalName
#define LXxC_TreeView2_ColumnInternalName(c) LxResult c::treeview2_ColumnInternalName([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len)
#define LXxD_TreeView2_ColumnIconResource LxResult treeview2_ColumnIconResource([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len) override
#define LXxO_TreeView2_ColumnIconResource LXxD_TreeView2_ColumnIconResource
#define LXxC_TreeView2_ColumnIconResource(c) LxResult c::treeview2_ColumnIconResource([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len)
#define LXxD_TreeView2_ColumnJustification LxResult treeview2_ColumnJustification([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] int *justification) override
#define LXxO_TreeView2_ColumnJustification LXxD_TreeView2_ColumnJustification
#define LXxC_TreeView2_ColumnJustification(c) LxResult c::treeview2_ColumnJustification([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] int *justification)
#define LXxD_TreeView2_PrimaryColumnPosition LxResult treeview2_PrimaryColumnPosition([[maybe_unused]] unsigned *index) override
#define LXxO_TreeView2_PrimaryColumnPosition LXxD_TreeView2_PrimaryColumnPosition
#define LXxC_TreeView2_PrimaryColumnPosition(c) LxResult c::treeview2_PrimaryColumnPosition([[maybe_unused]] unsigned *index)
#define LXxD_TreeView2_ToPrimary LxResult treeview2_ToPrimary() override
#define LXxO_TreeView2_ToPrimary LXxD_TreeView2_ToPrimary
#define LXxC_TreeView2_ToPrimary(c) LxResult c::treeview2_ToPrimary()
#define LXxD_TreeView2_IsSelected LxResult treeview2_IsSelected() override
#define LXxO_TreeView2_IsSelected LXxD_TreeView2_IsSelected
#define LXxC_TreeView2_IsSelected(c) LxResult c::treeview2_IsSelected()
#define LXxD_TreeView2_Select LxResult treeview2_Select([[maybe_unused]] unsigned mode) override
#define LXxO_TreeView2_Select LXxD_TreeView2_Select
#define LXxC_TreeView2_Select(c) LxResult c::treeview2_Select([[maybe_unused]] unsigned mode)
#define LXxD_TreeView2_CellCommand LxResult treeview2_CellCommand([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len) override
#define LXxO_TreeView2_CellCommand LXxD_TreeView2_CellCommand
#define LXxC_TreeView2_CellCommand(c) LxResult c::treeview2_CellCommand([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len)
#define LXxD_TreeView2_BatchCommand LxResult treeview2_BatchCommand([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len) override
#define LXxO_TreeView2_BatchCommand LXxD_TreeView2_BatchCommand
#define LXxC_TreeView2_BatchCommand(c) LxResult c::treeview2_BatchCommand([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len)
#define LXxD_TreeView2_ToolTip LxResult treeview2_ToolTip([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len) override
#define LXxO_TreeView2_ToolTip LXxD_TreeView2_ToolTip
#define LXxC_TreeView2_ToolTip(c) LxResult c::treeview2_ToolTip([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len)
#define LXxD_TreeView2_BadgeType LxResult treeview2_BadgeType([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] unsigned badgeIndex, [[maybe_unused]] unsigned *badgeType) override
#define LXxO_TreeView2_BadgeType LXxD_TreeView2_BadgeType
#define LXxC_TreeView2_BadgeType(c) LxResult c::treeview2_BadgeType([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] unsigned badgeIndex, [[maybe_unused]] unsigned *badgeType)
#define LXxD_TreeView2_BadgeDetail LxResult treeview2_BadgeDetail([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] unsigned badgeIndex, [[maybe_unused]] unsigned badgeDetail, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len) override
#define LXxO_TreeView2_BadgeDetail LXxD_TreeView2_BadgeDetail
#define LXxC_TreeView2_BadgeDetail(c) LxResult c::treeview2_BadgeDetail([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] unsigned badgeIndex, [[maybe_unused]] unsigned badgeDetail, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len)
#define LXxD_TreeView2_IsInputRegion LxResult treeview2_IsInputRegion([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] unsigned regionID) override
#define LXxO_TreeView2_IsInputRegion LXxD_TreeView2_IsInputRegion
#define LXxC_TreeView2_IsInputRegion(c) LxResult c::treeview2_IsInputRegion([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] unsigned regionID)
#define LXxD_TreeView2_SupportedDragDropSourceTypes LxResult treeview2_SupportedDragDropSourceTypes([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len) override
#define LXxO_TreeView2_SupportedDragDropSourceTypes LXxD_TreeView2_SupportedDragDropSourceTypes
#define LXxC_TreeView2_SupportedDragDropSourceTypes(c) LxResult c::treeview2_SupportedDragDropSourceTypes([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len)
#define LXxD_TreeView2_GetDragDropSourceObject LxResult treeview2_GetDragDropSourceObject([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] const char *type, [[maybe_unused]] void **ppvObj) override
#define LXxO_TreeView2_GetDragDropSourceObject LXxD_TreeView2_GetDragDropSourceObject
#define LXxC_TreeView2_GetDragDropSourceObject(c) LxResult c::treeview2_GetDragDropSourceObject([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] const char *type, [[maybe_unused]] void **ppvObj)
#define LXxD_TreeView2_GetDragDropDestinationObject LxResult treeview2_GetDragDropDestinationObject([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] unsigned location, [[maybe_unused]] void **ppvObj) override
#define LXxO_TreeView2_GetDragDropDestinationObject LXxD_TreeView2_GetDragDropDestinationObject
#define LXxC_TreeView2_GetDragDropDestinationObject(c) LxResult c::treeview2_GetDragDropDestinationObject([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] unsigned location, [[maybe_unused]] void **ppvObj)

template <class T>
class CLxIfc_TreeView2: public CLxInterface
{
public:
    CLxIfc_TreeView2()
    {
        vt.StoreState = StoreState;
        vt.RestoreState = RestoreState;
        vt.ColumnCount = ColumnCount;
        vt.ColumnByIndex = ColumnByIndex;
        vt.ColumnInternalName = ColumnInternalName;
        vt.ColumnIconResource = ColumnIconResource;
        vt.ColumnJustification = ColumnJustification;
        vt.PrimaryColumnPosition = PrimaryColumnPosition;
        vt.ToPrimary = ToPrimary;
        vt.IsSelected = IsSelected;
        vt.Select = Select;
        vt.CellCommand = CellCommand;
        vt.BatchCommand = BatchCommand;
        vt.ToolTip = ToolTip;
        vt.BadgeType = BadgeType;
        vt.BadgeDetail = BadgeDetail;
        vt.IsInputRegion = IsInputRegion;
        vt.SupportedDragDropSourceTypes = SupportedDragDropSourceTypes;
        vt.GetDragDropSourceObject = GetDragDropSourceObject;
        vt.GetDragDropDestinationObject = GetDragDropDestinationObject;
        vTable = &vt.iunk;
        iid = &lx::guid_TreeView2;
    }

    static auto StoreState(LXtObjectID wcom,const char *uid) -> LxResult
    {
        LXCWxINST (CLxImpl_TreeView2, loc);
        try
        {
           return loc->treeview2_StoreState( uid);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto RestoreState(LXtObjectID wcom,const char *uid) -> LxResult
    {
        LXCWxINST (CLxImpl_TreeView2, loc);
        try
        {
           return loc->treeview2_RestoreState( uid);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ColumnCount(LXtObjectID wcom,unsigned* colCount) -> LxResult
    {
        LXCWxINST (CLxImpl_TreeView2, loc);
        try
        {
           return loc->treeview2_ColumnCount( colCount);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ColumnByIndex(LXtObjectID wcom,unsigned columnIndex,char *buf,unsigned len,int *columnWidth) -> LxResult
    {
        LXCWxINST (CLxImpl_TreeView2, loc);
        try
        {
           return loc->treeview2_ColumnByIndex( columnIndex, buf, len, columnWidth);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ColumnInternalName(LXtObjectID wcom,unsigned columnIndex,char *buf,unsigned len) -> LxResult
    {
        LXCWxINST (CLxImpl_TreeView2, loc);
        try
        {
           return loc->treeview2_ColumnInternalName( columnIndex, buf, len);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ColumnIconResource(LXtObjectID wcom,unsigned columnIndex,char *buf,unsigned len) -> LxResult
    {
        LXCWxINST (CLxImpl_TreeView2, loc);
        try
        {
           return loc->treeview2_ColumnIconResource( columnIndex, buf, len);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ColumnJustification(LXtObjectID wcom,unsigned columnIndex,int *justification) -> LxResult
    {
        LXCWxINST (CLxImpl_TreeView2, loc);
        try
        {
           return loc->treeview2_ColumnJustification( columnIndex, justification);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto PrimaryColumnPosition(LXtObjectID wcom,unsigned *index) -> LxResult
    {
        LXCWxINST (CLxImpl_TreeView2, loc);
        try
        {
           return loc->treeview2_PrimaryColumnPosition( index);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ToPrimary(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_TreeView2, loc);
        try
        {
           return loc->treeview2_ToPrimary();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto IsSelected(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_TreeView2, loc);
        try
        {
           return loc->treeview2_IsSelected();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Select(LXtObjectID wcom,unsigned mode) -> LxResult
    {
        LXCWxINST (CLxImpl_TreeView2, loc);
        try
        {
           return loc->treeview2_Select( mode);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto CellCommand(LXtObjectID wcom,unsigned columnIndex,char *buf,unsigned len) -> LxResult
    {
        LXCWxINST (CLxImpl_TreeView2, loc);
        try
        {
           return loc->treeview2_CellCommand( columnIndex, buf, len);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto BatchCommand(LXtObjectID wcom,unsigned columnIndex,char *buf,unsigned len) -> LxResult
    {
        LXCWxINST (CLxImpl_TreeView2, loc);
        try
        {
           return loc->treeview2_BatchCommand( columnIndex, buf, len);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ToolTip(LXtObjectID wcom,unsigned columnIndex,char *buf,unsigned len) -> LxResult
    {
        LXCWxINST (CLxImpl_TreeView2, loc);
        try
        {
           return loc->treeview2_ToolTip( columnIndex, buf, len);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto BadgeType(LXtObjectID wcom,unsigned columnIndex,unsigned badgeIndex,unsigned *badgeType) -> LxResult
    {
        LXCWxINST (CLxImpl_TreeView2, loc);
        try
        {
           return loc->treeview2_BadgeType( columnIndex, badgeIndex, badgeType);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto BadgeDetail(LXtObjectID wcom,unsigned columnIndex,unsigned badgeIndex,unsigned badgeDetail,char *buf,unsigned len) -> LxResult
    {
        LXCWxINST (CLxImpl_TreeView2, loc);
        try
        {
           return loc->treeview2_BadgeDetail( columnIndex, badgeIndex, badgeDetail, buf, len);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto IsInputRegion(LXtObjectID wcom,unsigned columnIndex,unsigned regionID) -> LxResult
    {
        LXCWxINST (CLxImpl_TreeView2, loc);
        try
        {
           return loc->treeview2_IsInputRegion( columnIndex, regionID);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SupportedDragDropSourceTypes(LXtObjectID wcom,unsigned columnIndex,char *buf,unsigned len) -> LxResult
    {
        LXCWxINST (CLxImpl_TreeView2, loc);
        try
        {
           return loc->treeview2_SupportedDragDropSourceTypes( columnIndex, buf, len);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto GetDragDropSourceObject(LXtObjectID wcom,unsigned columnIndex,const char *type,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_TreeView2, loc);
        try
        {
           return loc->treeview2_GetDragDropSourceObject( columnIndex, type, ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto GetDragDropDestinationObject(LXtObjectID wcom,unsigned columnIndex,unsigned location,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_TreeView2, loc);
        try
        {
           return loc->treeview2_GetDragDropDestinationObject( columnIndex, location, ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxTreeView2 vt;
};

class CLxLoc_TreeView2 : public CLxLocalize<ILxTreeView2ID>
{
public:
    CLxLoc_TreeView2()
    {
        _init();
    }

    CLxLoc_TreeView2(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_TreeView2(CLxLoc_TreeView2 const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_TreeView2;
    }

    auto StoreState(const char *uid) -> LxResult
    {
        return m_loc[0]->StoreState(m_loc, uid);
    }

    auto RestoreState(const char *uid) -> LxResult
    {
        return m_loc[0]->RestoreState(m_loc, uid);
    }

    auto ColumnCount(unsigned* colCount) -> LxResult
    {
        return m_loc[0]->ColumnCount(m_loc, colCount);
    }

    auto ColumnByIndex(unsigned columnIndex, char *buf, unsigned len, int *columnWidth) -> LxResult
    {
        return m_loc[0]->ColumnByIndex(m_loc, columnIndex, buf, len, columnWidth);
    }

    auto ColumnByIndex(unsigned columnIndex, std::string &result, int *columnWidth) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->ColumnByIndex(m_loc, columnIndex, buf, len, columnWidth);
        LXWx_SBUF2
    }

    auto ColumnInternalName(unsigned columnIndex, char *buf, unsigned len) -> LxResult
    {
        return m_loc[0]->ColumnInternalName(m_loc, columnIndex, buf, len);
    }

    auto ColumnInternalName(unsigned columnIndex, std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->ColumnInternalName(m_loc, columnIndex, buf, len);
        LXWx_SBUF2
    }

    auto ColumnIconResource(unsigned columnIndex, char *buf, unsigned len) -> LxResult
    {
        return m_loc[0]->ColumnIconResource(m_loc, columnIndex, buf, len);
    }

    auto ColumnIconResource(unsigned columnIndex, std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->ColumnIconResource(m_loc, columnIndex, buf, len);
        LXWx_SBUF2
    }

    auto ColumnJustification(unsigned columnIndex, int *justification) -> LxResult
    {
        return m_loc[0]->ColumnJustification(m_loc, columnIndex, justification);
    }

    auto PrimaryColumnPosition(unsigned *index) -> LxResult
    {
        return m_loc[0]->PrimaryColumnPosition(m_loc, index);
    }

    auto ToPrimary(void) -> LxResult
    {
        return m_loc[0]->ToPrimary(m_loc);
    }

    auto IsSelected(void) -> LxResult
    {
        return m_loc[0]->IsSelected(m_loc);
    }

    auto Select(unsigned mode) -> LxResult
    {
        return m_loc[0]->Select(m_loc, mode);
    }

    auto CellCommand(unsigned columnIndex, char *buf, unsigned len) -> LxResult
    {
        return m_loc[0]->CellCommand(m_loc, columnIndex, buf, len);
    }

    auto CellCommand(unsigned columnIndex, std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->CellCommand(m_loc, columnIndex, buf, len);
        LXWx_SBUF2
    }

    auto BatchCommand(unsigned columnIndex, char *buf, unsigned len) -> LxResult
    {
        return m_loc[0]->BatchCommand(m_loc, columnIndex, buf, len);
    }

    auto BatchCommand(unsigned columnIndex, std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->BatchCommand(m_loc, columnIndex, buf, len);
        LXWx_SBUF2
    }

    auto ToolTip(unsigned columnIndex, char *buf, unsigned len) -> LxResult
    {
        return m_loc[0]->ToolTip(m_loc, columnIndex, buf, len);
    }

    auto ToolTip(unsigned columnIndex, std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->ToolTip(m_loc, columnIndex, buf, len);
        LXWx_SBUF2
    }

    auto BadgeType(unsigned columnIndex, unsigned badgeIndex, unsigned *badgeType) -> LxResult
    {
        return m_loc[0]->BadgeType(m_loc, columnIndex, badgeIndex, badgeType);
    }

    auto BadgeDetail(unsigned columnIndex, unsigned badgeIndex, unsigned badgeDetail, char *buf, unsigned len) -> LxResult
    {
        return m_loc[0]->BadgeDetail(m_loc, columnIndex, badgeIndex, badgeDetail, buf, len);
    }

    auto BadgeDetail(unsigned columnIndex, unsigned badgeIndex, unsigned badgeDetail, std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->BadgeDetail(m_loc, columnIndex, badgeIndex, badgeDetail, buf, len);
        LXWx_SBUF2
    }

    auto IsInputRegion(unsigned columnIndex, unsigned regionID) -> LxResult
    {
        return m_loc[0]->IsInputRegion(m_loc, columnIndex, regionID);
    }

    auto SupportedDragDropSourceTypes(unsigned columnIndex, char *buf, unsigned len) -> LxResult
    {
        return m_loc[0]->SupportedDragDropSourceTypes(m_loc, columnIndex, buf, len);
    }

    auto SupportedDragDropSourceTypes(unsigned columnIndex, std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->SupportedDragDropSourceTypes(m_loc, columnIndex, buf, len);
        LXWx_SBUF2
    }

    auto GetDragDropSourceObject(unsigned columnIndex, const char *type, void **ppvObj) -> LxResult
    {
        return m_loc[0]->GetDragDropSourceObject(m_loc, columnIndex, type, ppvObj);
    }

    auto GetDragDropSourceObject(unsigned columnIndex, const char *type, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->GetDragDropSourceObject(m_loc, columnIndex, type, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto GetDragDropDestinationObject(unsigned columnIndex, unsigned location, void **ppvObj) -> LxResult
    {
        return m_loc[0]->GetDragDropDestinationObject(m_loc, columnIndex, location, ppvObj);
    }

    auto GetDragDropDestinationObject(unsigned columnIndex, unsigned location, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->GetDragDropDestinationObject(m_loc, columnIndex, location, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_TreeView1
{
public:
    virtual ~CLxImpl_TreeView1() = default;

    virtual auto treeview1_StoreState([[maybe_unused]] const char *uid) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto treeview1_RestoreState([[maybe_unused]] const char *uid) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto treeview1_ColumnCount([[maybe_unused]] unsigned* colCount) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto treeview1_ColumnByIndex([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len, [[maybe_unused]] int *columnWidth) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto treeview1_ToPrimary([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto treeview1_IsSelected([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto treeview1_Select([[maybe_unused]] unsigned mode) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto treeview1_CellCommand([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto treeview1_BatchCommand([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto treeview1_ToolTip([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto treeview1_BadgeType([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] unsigned badgeIndex, [[maybe_unused]] unsigned *badgeType) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto treeview1_BadgeDetail([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] unsigned badgeIndex, [[maybe_unused]] unsigned badgeDetail, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto treeview1_IsInputRegion([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] unsigned regionID) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto treeview1_SupportedDragDropSourceTypes([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto treeview1_GetDragDropSourceObject([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] const char *type, [[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto treeview1_GetDragDropDestinationObject([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_TreeView1_StoreState LxResult treeview1_StoreState([[maybe_unused]] const char *uid) override
#define LXxO_TreeView1_StoreState LXxD_TreeView1_StoreState
#define LXxC_TreeView1_StoreState(c) LxResult c::treeview1_StoreState([[maybe_unused]] const char *uid)
#define LXxD_TreeView1_RestoreState LxResult treeview1_RestoreState([[maybe_unused]] const char *uid) override
#define LXxO_TreeView1_RestoreState LXxD_TreeView1_RestoreState
#define LXxC_TreeView1_RestoreState(c) LxResult c::treeview1_RestoreState([[maybe_unused]] const char *uid)
#define LXxD_TreeView1_ColumnCount LxResult treeview1_ColumnCount([[maybe_unused]] unsigned* colCount) override
#define LXxO_TreeView1_ColumnCount LXxD_TreeView1_ColumnCount
#define LXxC_TreeView1_ColumnCount(c) LxResult c::treeview1_ColumnCount([[maybe_unused]] unsigned* colCount)
#define LXxD_TreeView1_ColumnByIndex LxResult treeview1_ColumnByIndex([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len, [[maybe_unused]] int *columnWidth) override
#define LXxO_TreeView1_ColumnByIndex LXxD_TreeView1_ColumnByIndex
#define LXxC_TreeView1_ColumnByIndex(c) LxResult c::treeview1_ColumnByIndex([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len, [[maybe_unused]] int *columnWidth)
#define LXxD_TreeView1_ToPrimary LxResult treeview1_ToPrimary() override
#define LXxO_TreeView1_ToPrimary LXxD_TreeView1_ToPrimary
#define LXxC_TreeView1_ToPrimary(c) LxResult c::treeview1_ToPrimary()
#define LXxD_TreeView1_IsSelected LxResult treeview1_IsSelected() override
#define LXxO_TreeView1_IsSelected LXxD_TreeView1_IsSelected
#define LXxC_TreeView1_IsSelected(c) LxResult c::treeview1_IsSelected()
#define LXxD_TreeView1_Select LxResult treeview1_Select([[maybe_unused]] unsigned mode) override
#define LXxO_TreeView1_Select LXxD_TreeView1_Select
#define LXxC_TreeView1_Select(c) LxResult c::treeview1_Select([[maybe_unused]] unsigned mode)
#define LXxD_TreeView1_CellCommand LxResult treeview1_CellCommand([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len) override
#define LXxO_TreeView1_CellCommand LXxD_TreeView1_CellCommand
#define LXxC_TreeView1_CellCommand(c) LxResult c::treeview1_CellCommand([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len)
#define LXxD_TreeView1_BatchCommand LxResult treeview1_BatchCommand([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len) override
#define LXxO_TreeView1_BatchCommand LXxD_TreeView1_BatchCommand
#define LXxC_TreeView1_BatchCommand(c) LxResult c::treeview1_BatchCommand([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len)
#define LXxD_TreeView1_ToolTip LxResult treeview1_ToolTip([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len) override
#define LXxO_TreeView1_ToolTip LXxD_TreeView1_ToolTip
#define LXxC_TreeView1_ToolTip(c) LxResult c::treeview1_ToolTip([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len)
#define LXxD_TreeView1_BadgeType LxResult treeview1_BadgeType([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] unsigned badgeIndex, [[maybe_unused]] unsigned *badgeType) override
#define LXxO_TreeView1_BadgeType LXxD_TreeView1_BadgeType
#define LXxC_TreeView1_BadgeType(c) LxResult c::treeview1_BadgeType([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] unsigned badgeIndex, [[maybe_unused]] unsigned *badgeType)
#define LXxD_TreeView1_BadgeDetail LxResult treeview1_BadgeDetail([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] unsigned badgeIndex, [[maybe_unused]] unsigned badgeDetail, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len) override
#define LXxO_TreeView1_BadgeDetail LXxD_TreeView1_BadgeDetail
#define LXxC_TreeView1_BadgeDetail(c) LxResult c::treeview1_BadgeDetail([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] unsigned badgeIndex, [[maybe_unused]] unsigned badgeDetail, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len)
#define LXxD_TreeView1_IsInputRegion LxResult treeview1_IsInputRegion([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] unsigned regionID) override
#define LXxO_TreeView1_IsInputRegion LXxD_TreeView1_IsInputRegion
#define LXxC_TreeView1_IsInputRegion(c) LxResult c::treeview1_IsInputRegion([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] unsigned regionID)
#define LXxD_TreeView1_SupportedDragDropSourceTypes LxResult treeview1_SupportedDragDropSourceTypes([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len) override
#define LXxO_TreeView1_SupportedDragDropSourceTypes LXxD_TreeView1_SupportedDragDropSourceTypes
#define LXxC_TreeView1_SupportedDragDropSourceTypes(c) LxResult c::treeview1_SupportedDragDropSourceTypes([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len)
#define LXxD_TreeView1_GetDragDropSourceObject LxResult treeview1_GetDragDropSourceObject([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] const char *type, [[maybe_unused]] void **ppvObj) override
#define LXxO_TreeView1_GetDragDropSourceObject LXxD_TreeView1_GetDragDropSourceObject
#define LXxC_TreeView1_GetDragDropSourceObject(c) LxResult c::treeview1_GetDragDropSourceObject([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] const char *type, [[maybe_unused]] void **ppvObj)
#define LXxD_TreeView1_GetDragDropDestinationObject LxResult treeview1_GetDragDropDestinationObject([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] void **ppvObj) override
#define LXxO_TreeView1_GetDragDropDestinationObject LXxD_TreeView1_GetDragDropDestinationObject
#define LXxC_TreeView1_GetDragDropDestinationObject(c) LxResult c::treeview1_GetDragDropDestinationObject([[maybe_unused]] unsigned columnIndex, [[maybe_unused]] void **ppvObj)

template <class T>
class CLxIfc_TreeView1: public CLxInterface
{
public:
    CLxIfc_TreeView1()
    {
        vt.StoreState = StoreState;
        vt.RestoreState = RestoreState;
        vt.ColumnCount = ColumnCount;
        vt.ColumnByIndex = ColumnByIndex;
        vt.ToPrimary = ToPrimary;
        vt.IsSelected = IsSelected;
        vt.Select = Select;
        vt.CellCommand = CellCommand;
        vt.BatchCommand = BatchCommand;
        vt.ToolTip = ToolTip;
        vt.BadgeType = BadgeType;
        vt.BadgeDetail = BadgeDetail;
        vt.IsInputRegion = IsInputRegion;
        vt.SupportedDragDropSourceTypes = SupportedDragDropSourceTypes;
        vt.GetDragDropSourceObject = GetDragDropSourceObject;
        vt.GetDragDropDestinationObject = GetDragDropDestinationObject;
        vTable = &vt.iunk;
        iid = &lx::guid_TreeView1;
    }

    static auto StoreState(LXtObjectID wcom,const char *uid) -> LxResult
    {
        LXCWxINST (CLxImpl_TreeView1, loc);
        try
        {
           return loc->treeview1_StoreState( uid);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto RestoreState(LXtObjectID wcom,const char *uid) -> LxResult
    {
        LXCWxINST (CLxImpl_TreeView1, loc);
        try
        {
           return loc->treeview1_RestoreState( uid);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ColumnCount(LXtObjectID wcom,unsigned* colCount) -> LxResult
    {
        LXCWxINST (CLxImpl_TreeView1, loc);
        try
        {
           return loc->treeview1_ColumnCount( colCount);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ColumnByIndex(LXtObjectID wcom,unsigned columnIndex,char *buf,unsigned len,int *columnWidth) -> LxResult
    {
        LXCWxINST (CLxImpl_TreeView1, loc);
        try
        {
           return loc->treeview1_ColumnByIndex( columnIndex, buf, len, columnWidth);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ToPrimary(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_TreeView1, loc);
        try
        {
           return loc->treeview1_ToPrimary();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto IsSelected(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_TreeView1, loc);
        try
        {
           return loc->treeview1_IsSelected();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Select(LXtObjectID wcom,unsigned mode) -> LxResult
    {
        LXCWxINST (CLxImpl_TreeView1, loc);
        try
        {
           return loc->treeview1_Select( mode);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto CellCommand(LXtObjectID wcom,unsigned columnIndex,char *buf,unsigned len) -> LxResult
    {
        LXCWxINST (CLxImpl_TreeView1, loc);
        try
        {
           return loc->treeview1_CellCommand( columnIndex, buf, len);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto BatchCommand(LXtObjectID wcom,unsigned columnIndex,char *buf,unsigned len) -> LxResult
    {
        LXCWxINST (CLxImpl_TreeView1, loc);
        try
        {
           return loc->treeview1_BatchCommand( columnIndex, buf, len);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ToolTip(LXtObjectID wcom,unsigned columnIndex,char *buf,unsigned len) -> LxResult
    {
        LXCWxINST (CLxImpl_TreeView1, loc);
        try
        {
           return loc->treeview1_ToolTip( columnIndex, buf, len);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto BadgeType(LXtObjectID wcom,unsigned columnIndex,unsigned badgeIndex,unsigned *badgeType) -> LxResult
    {
        LXCWxINST (CLxImpl_TreeView1, loc);
        try
        {
           return loc->treeview1_BadgeType( columnIndex, badgeIndex, badgeType);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto BadgeDetail(LXtObjectID wcom,unsigned columnIndex,unsigned badgeIndex,unsigned badgeDetail,char *buf,unsigned len) -> LxResult
    {
        LXCWxINST (CLxImpl_TreeView1, loc);
        try
        {
           return loc->treeview1_BadgeDetail( columnIndex, badgeIndex, badgeDetail, buf, len);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto IsInputRegion(LXtObjectID wcom,unsigned columnIndex,unsigned regionID) -> LxResult
    {
        LXCWxINST (CLxImpl_TreeView1, loc);
        try
        {
           return loc->treeview1_IsInputRegion( columnIndex, regionID);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SupportedDragDropSourceTypes(LXtObjectID wcom,unsigned columnIndex,char *buf,unsigned len) -> LxResult
    {
        LXCWxINST (CLxImpl_TreeView1, loc);
        try
        {
           return loc->treeview1_SupportedDragDropSourceTypes( columnIndex, buf, len);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto GetDragDropSourceObject(LXtObjectID wcom,unsigned columnIndex,const char *type,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_TreeView1, loc);
        try
        {
           return loc->treeview1_GetDragDropSourceObject( columnIndex, type, ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto GetDragDropDestinationObject(LXtObjectID wcom,unsigned columnIndex,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_TreeView1, loc);
        try
        {
           return loc->treeview1_GetDragDropDestinationObject( columnIndex, ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxTreeView1 vt;
};

class CLxLoc_TreeView1 : public CLxLocalize<ILxTreeView1ID>
{
public:
    CLxLoc_TreeView1()
    {
        _init();
    }

    CLxLoc_TreeView1(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_TreeView1(CLxLoc_TreeView1 const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_TreeView1;
    }

    auto StoreState(const char *uid) -> LxResult
    {
        return m_loc[0]->StoreState(m_loc, uid);
    }

    auto RestoreState(const char *uid) -> LxResult
    {
        return m_loc[0]->RestoreState(m_loc, uid);
    }

    auto ColumnCount(unsigned* colCount) -> LxResult
    {
        return m_loc[0]->ColumnCount(m_loc, colCount);
    }

    auto ColumnByIndex(unsigned columnIndex, char *buf, unsigned len, int *columnWidth) -> LxResult
    {
        return m_loc[0]->ColumnByIndex(m_loc, columnIndex, buf, len, columnWidth);
    }

    auto ColumnByIndex(unsigned columnIndex, std::string &result, int *columnWidth) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->ColumnByIndex(m_loc, columnIndex, buf, len, columnWidth);
        LXWx_SBUF2
    }

    auto ToPrimary(void) -> LxResult
    {
        return m_loc[0]->ToPrimary(m_loc);
    }

    auto IsSelected(void) -> LxResult
    {
        return m_loc[0]->IsSelected(m_loc);
    }

    auto Select(unsigned mode) -> LxResult
    {
        return m_loc[0]->Select(m_loc, mode);
    }

    auto CellCommand(unsigned columnIndex, char *buf, unsigned len) -> LxResult
    {
        return m_loc[0]->CellCommand(m_loc, columnIndex, buf, len);
    }

    auto CellCommand(unsigned columnIndex, std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->CellCommand(m_loc, columnIndex, buf, len);
        LXWx_SBUF2
    }

    auto BatchCommand(unsigned columnIndex, char *buf, unsigned len) -> LxResult
    {
        return m_loc[0]->BatchCommand(m_loc, columnIndex, buf, len);
    }

    auto BatchCommand(unsigned columnIndex, std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->BatchCommand(m_loc, columnIndex, buf, len);
        LXWx_SBUF2
    }

    auto ToolTip(unsigned columnIndex, char *buf, unsigned len) -> LxResult
    {
        return m_loc[0]->ToolTip(m_loc, columnIndex, buf, len);
    }

    auto ToolTip(unsigned columnIndex, std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->ToolTip(m_loc, columnIndex, buf, len);
        LXWx_SBUF2
    }

    auto BadgeType(unsigned columnIndex, unsigned badgeIndex, unsigned *badgeType) -> LxResult
    {
        return m_loc[0]->BadgeType(m_loc, columnIndex, badgeIndex, badgeType);
    }

    auto BadgeDetail(unsigned columnIndex, unsigned badgeIndex, unsigned badgeDetail, char *buf, unsigned len) -> LxResult
    {
        return m_loc[0]->BadgeDetail(m_loc, columnIndex, badgeIndex, badgeDetail, buf, len);
    }

    auto BadgeDetail(unsigned columnIndex, unsigned badgeIndex, unsigned badgeDetail, std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->BadgeDetail(m_loc, columnIndex, badgeIndex, badgeDetail, buf, len);
        LXWx_SBUF2
    }

    auto IsInputRegion(unsigned columnIndex, unsigned regionID) -> LxResult
    {
        return m_loc[0]->IsInputRegion(m_loc, columnIndex, regionID);
    }

    auto SupportedDragDropSourceTypes(unsigned columnIndex, char *buf, unsigned len) -> LxResult
    {
        return m_loc[0]->SupportedDragDropSourceTypes(m_loc, columnIndex, buf, len);
    }

    auto SupportedDragDropSourceTypes(unsigned columnIndex, std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->SupportedDragDropSourceTypes(m_loc, columnIndex, buf, len);
        LXWx_SBUF2
    }

    auto GetDragDropSourceObject(unsigned columnIndex, const char *type, void **ppvObj) -> LxResult
    {
        return m_loc[0]->GetDragDropSourceObject(m_loc, columnIndex, type, ppvObj);
    }

    auto GetDragDropSourceObject(unsigned columnIndex, const char *type, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->GetDragDropSourceObject(m_loc, columnIndex, type, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto GetDragDropDestinationObject(unsigned columnIndex, void **ppvObj) -> LxResult
    {
        return m_loc[0]->GetDragDropDestinationObject(m_loc, columnIndex, ppvObj);
    }

    auto GetDragDropDestinationObject(unsigned columnIndex, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->GetDragDropDestinationObject(m_loc, columnIndex, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
