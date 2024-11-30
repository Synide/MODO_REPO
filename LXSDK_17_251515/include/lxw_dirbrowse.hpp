//
// C++ wrapper for lxsdk/lxdirbrowse.h.
//
//	Copyright 2024.
//
//
#pragma once

#include <lxdirbrowse.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx
{
    static LXtGUID const guid_DirCacheService = {0xb61119fa, {0x4cd9, 0x4067}, {0xba, 0x48, 0xba, 0x83, 0xad, 0x1f, 0xa5, 0x44}};
    static LXtGUID const guid_DirCacheEntry = {0x1013a289, {0xaa27, 0x416a}, {0xb2, 0x73, 0x66, 0x67, 0x32, 0xce, 0x3d, 0x88}};
    static LXtGUID const guid_DirEntryThumbAsync = {0x0a3c97de, {0x37b8, 0x44b2}, {0xa5, 0x2b, 0xb1, 0xb9, 0x1c, 0x77, 0xe5, 0x97}};
    static LXtGUID const guid_MergedDirCacheEntry = {0x38986948, {0x6e89, 0x4208}, {0xa7, 0x34, 0x41, 0x1d, 0x28, 0xab, 0x48, 0x15}};
    static LXtGUID const guid_DirCacheFileMetrics = {0x2c00a80c, {0xac90, 0x401c}, {0x8c, 0xb8, 0xab, 0xfd, 0xf3, 0xba, 0x26, 0xdd}};
    static LXtGUID const guid_DirCacheSynthetic = {0xd269abf7, {0x7bd3, 0x4982}, {0xa6, 0xbd, 0xcb, 0x46, 0xfc, 0xeb, 0xe1, 0xe3}};
    static LXtGUID const guid_DirCacheSyntheticEntry1 = {0xc85d528d, {0x50aa, 0x4974}, {0xbb, 0xf0, 0x61, 0x22, 0xb4, 0xe0, 0x0d, 0x5b}};
    static LXtGUID const guid_DirCacheSyntheticEntry = {0x9d741627, {0xbeea, 0x4c7f}, {0x86, 0x66, 0xcc, 0xbd, 0xb2, 0xcd, 0x3e, 0x72}};
    static LXtGUID const guid_BasePathAddDest = {0x1710a8c1, {0xa493, 0x4e65}, {0xa1, 0x90, 0x00, 0x9e, 0xff, 0xc4, 0xa1, 0x34}};
    static LXtGUID const guid_DirCacheManualOrderDest = {0xfb69c873, {0x9f95, 0x4ba1}, {0xba, 0x1f, 0x12, 0x35, 0x30, 0x7e, 0x3c, 0x88}};
    static LXtGUID const guid_DirCacheGridPosDest = {0x09a9db0d, {0x131f, 0x40ed}, {0x91, 0x0a, 0x89, 0x16, 0xa6, 0x36, 0xdc, 0x36}};
    static LXtGUID const guid_FileSysDest = {0x79d4f661, {0x3249, 0x4455}, {0xbf, 0xb9, 0x48, 0x61, 0x20, 0xc1, 0x8f, 0x24}};
    static LXtGUID const guid_MergedFileSysDest = {0xa58450c6, {0x5789, 0x4072}, {0x84, 0xeb, 0x92, 0x15, 0x4d, 0x63, 0x2d, 0xc2}};
    static LXtGUID const guid_DirBrowserBasePathEntryDest = {0x56a0f290, {0x9aca, 0x4e44}, {0xb0, 0x36, 0xb2, 0xbb, 0xb7, 0xbe, 0x28, 0xd2}};
} // namespace lx

class CLxLoc_DirCacheService : public CLxLocalizedService
{
public:
    ILxDirCacheServiceID m_loc{ nullptr };

public:
    CLxLoc_DirCacheService()
    {
        _init();
        set();
    }

    ~CLxLoc_DirCacheService() = default;

    void set()
    {
        if (!m_loc)
        {
            m_loc = reinterpret_cast<ILxDirCacheServiceID>(lx::GetGlobal(&lx::guid_DirCacheService));
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

    auto RootCount(int *count) -> LxResult
    {
        return m_loc[0]->RootCount(m_loc, count);
    }

    auto RootByIndex(int index, void **ppvObj) -> LxResult
    {
        return m_loc[0]->RootByIndex(m_loc, index, ppvObj);
    }

    auto RootByIndex(int index, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->RootByIndex(m_loc, index, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto RootLock(void) -> LxResult
    {
        return m_loc[0]->RootLock(m_loc);
    }

    auto RootUnlock(void) -> LxResult
    {
        return m_loc[0]->RootUnlock(m_loc);
    }

    auto Lookup(const char *path, void **ppvObj) -> LxResult
    {
        return m_loc[0]->Lookup(m_loc, path, ppvObj);
    }

    auto Lookup(const char *path, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Lookup(m_loc, path, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto CachedThumbnailAsyncCancel(const char *ident) -> LxResult
    {
        return m_loc[0]->CachedThumbnailAsyncCancel(m_loc, ident);
    }

    auto SetPosOnDrop(const char *path, ILxUnknownID dest) -> LxResult
    {
        return m_loc[0]->SetPosOnDrop(m_loc, path,(ILxUnknownID) dest);
    }

    auto AttributesChanged(ILxUnknownID dirCacheEntry, int which, const char *attribute) -> LxResult
    {
        return m_loc[0]->AttributesChanged(m_loc,(ILxUnknownID) dirCacheEntry, which, attribute);
    }

    auto ScanForChanges(const char *path) -> LxResult
    {
        return m_loc[0]->ScanForChanges(m_loc, path);
    }

    auto AddClient(void) -> LxResult
    {
        return m_loc[0]->AddClient(m_loc);
    }

    auto RemoveClient(void) -> LxResult
    {
        return m_loc[0]->RemoveClient(m_loc);
    }

    auto ParseName(const char *filename, char *baseName, int baseNameLen, char *path, int pathLen) -> LxResult
    {
        return m_loc[0]->ParseName(m_loc, filename, baseName, baseNameLen, path, pathLen);
    }

    auto PathCompose(char *filename, int filenameLen, const char *baseName, const char *path) -> LxResult
    {
        return m_loc[0]->PathCompose(m_loc, filename, filenameLen, baseName, path);
    }

    auto IsChildOfPath(const char *possibleChild, const char *parentToTestAgainsts, int orIsSame) -> LxResult
    {
        return m_loc[0]->IsChildOfPath(m_loc, possibleChild, parentToTestAgainsts, orIsSame);
    }

    auto ToLocalAlias(char *path, char *buf, int len) -> LxResult
    {
        return m_loc[0]->ToLocalAlias(m_loc, path, buf, len);
    }

    auto ArePathsEqual(const char *path1, const char *path2) -> LxResult
    {
        return m_loc[0]->ArePathsEqual(m_loc, path1, path2);
    }

    auto CanBeRenamed(const char *path) -> LxResult
    {
        return m_loc[0]->CanBeRenamed(m_loc, path);
    }

    auto MakeDirHierarchy(const char *path, int skipLastPart) -> LxResult
    {
        return m_loc[0]->MakeDirHierarchy(m_loc, path, skipLastPart);
    }

    auto MakeUniqueIn(ILxUnknownID object, const char *filename, char *buf, int len) -> LxResult
    {
        return m_loc[0]->MakeUniqueIn(m_loc,(ILxUnknownID) object, filename, buf, len);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_DirCacheEntry : public CLxLocalize<ILxDirCacheEntryID>
{
public:
    CLxLoc_DirCacheEntry()
    {
        _init();
    }

    CLxLoc_DirCacheEntry(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_DirCacheEntry(CLxLoc_DirCacheEntry const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_DirCacheEntry;
    }

    auto Type(int *type) -> LxResult
    {
        return m_loc[0]->Type(m_loc, type);
    }

    auto DirList(int listMode, void **ppvObj, int asCopy) -> LxResult
    {
        return m_loc[0]->DirList(m_loc, listMode, ppvObj, asCopy);
    }

    auto DirList(int listMode, CLxLocalizedObject &o_dest, int asCopy) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->DirList(m_loc, listMode, &o_obj, asCopy);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto DirCount(int listMode) -> unsigned int
    {
        return m_loc[0]->DirCount(m_loc, listMode);
    }

    auto Path(char *buf, unsigned int len) -> LxResult
    {
        return m_loc[0]->Path(m_loc, buf, len);
    }

    auto Path(std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->Path(m_loc, buf, len);
        LXWx_SBUF2
    }

    auto Name(char *buf, unsigned int len) -> LxResult
    {
        return m_loc[0]->Name(m_loc, buf, len);
    }

    auto Name(std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->Name(m_loc, buf, len);
        LXWx_SBUF2
    }

    auto Extension(char *buf, unsigned int len) -> LxResult
    {
        return m_loc[0]->Extension(m_loc, buf, len);
    }

    auto Extension(std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->Extension(m_loc, buf, len);
        LXWx_SBUF2
    }

    auto Size(double *size) -> LxResult
    {
        return m_loc[0]->Size(m_loc, size);
    }

    auto ModTime(char *buf, unsigned int len) -> LxResult
    {
        return m_loc[0]->ModTime(m_loc, buf, len);
    }

    auto ModTime(std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->ModTime(m_loc, buf, len);
        LXWx_SBUF2
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

    auto ReferenceSource(void **ppvObj) -> LxResult
    {
        return m_loc[0]->ReferenceSource(m_loc, ppvObj);
    }

    auto ReferenceSource(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->ReferenceSource(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto ReferencedList(void **ppvObj, int asCopy) -> LxResult
    {
        return m_loc[0]->ReferencedList(m_loc, ppvObj, asCopy);
    }

    auto ReferencedList(CLxLocalizedObject &o_dest, int asCopy) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->ReferencedList(m_loc, &o_obj, asCopy);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto ReferencedCount(void) -> unsigned int
    {
        return m_loc[0]->ReferencedCount(m_loc);
    }

    auto WasRecognized(void) -> LxResult
    {
        return m_loc[0]->WasRecognized(m_loc);
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

    auto UserMarkup(void **ppvObj, int asWritable) -> LxResult
    {
        return m_loc[0]->UserMarkup(m_loc, ppvObj, asWritable);
    }

    auto UserMarkup(CLxLocalizedObject &o_dest, int asWritable) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->UserMarkup(m_loc, &o_obj, asWritable);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto SharedMarkup(void **ppvObj, int asWritable) -> LxResult
    {
        return m_loc[0]->SharedMarkup(m_loc, ppvObj, asWritable);
    }

    auto SharedMarkup(CLxLocalizedObject &o_dest, int asWritable) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->SharedMarkup(m_loc, &o_obj, asWritable);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto CommitUserMarkup(ILxUnknownID userMarkup) -> LxResult
    {
        return m_loc[0]->CommitUserMarkup(m_loc,(ILxUnknownID) userMarkup);
    }

    auto CommitSharedMarkup(ILxUnknownID sharedMarkup) -> LxResult
    {
        return m_loc[0]->CommitSharedMarkup(m_loc,(ILxUnknownID) sharedMarkup);
    }

    auto Label(char *buf, unsigned int len) -> LxResult
    {
        return m_loc[0]->Label(m_loc, buf, len);
    }

    auto Label(std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->Label(m_loc, buf, len);
        LXWx_SBUF2
    }

    auto Desc(char *buf, unsigned int len) -> LxResult
    {
        return m_loc[0]->Desc(m_loc, buf, len);
    }

    auto Desc(std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->Desc(m_loc, buf, len);
        LXWx_SBUF2
    }

    auto ToolTip(char *buf, unsigned int len) -> LxResult
    {
        return m_loc[0]->ToolTip(m_loc, buf, len);
    }

    auto ToolTip(std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->ToolTip(m_loc, buf, len);
        LXWx_SBUF2
    }

    auto Thumbnail(int w, int h, unsigned int *idealW, unsigned int *idealH, void **ppvObj) -> LxResult
    {
        return m_loc[0]->Thumbnail(m_loc, w, h, idealW, idealH, ppvObj);
    }

    auto Thumbnail(int w, int h, unsigned int *idealW, unsigned int *idealH, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Thumbnail(m_loc, w, h, idealW, idealH, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto CachedThumbnail(int size, unsigned int *idealW, unsigned int *idealH, void **ppvObj) -> LxResult
    {
        return m_loc[0]->CachedThumbnail(m_loc, size, idealW, idealH, ppvObj);
    }

    auto CachedThumbnail(int size, unsigned int *idealW, unsigned int *idealH, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->CachedThumbnail(m_loc, size, idealW, idealH, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto CachedThumbnailCustom(int w, int h, unsigned int *idealW, unsigned int *idealH, void **ppvObj) -> LxResult
    {
        return m_loc[0]->CachedThumbnailCustom(m_loc, w, h, idealW, idealH, ppvObj);
    }

    auto CachedThumbnailCustom(int w, int h, unsigned int *idealW, unsigned int *idealH, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->CachedThumbnailCustom(m_loc, w, h, idealW, idealH, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto CachedThumbnailAsync(int size, unsigned int *idealW, unsigned int *idealH, void **ppvObj, ILxUnknownID asyncHandler) -> LxResult
    {
        return m_loc[0]->CachedThumbnailAsync(m_loc, size, idealW, idealH, ppvObj,(ILxUnknownID) asyncHandler);
    }

    auto CachedThumbnailAsync(int size, unsigned int *idealW, unsigned int *idealH, CLxLocalizedObject &o_dest, ILxUnknownID asyncHandler) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->CachedThumbnailAsync(m_loc, size, idealW, idealH, &o_obj,(ILxUnknownID) asyncHandler);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto CachedThumbnailCustomAsync(int w, int h, unsigned int *idealW, unsigned int *idealH, void **ppvObj, ILxUnknownID asyncHandler) -> LxResult
    {
        return m_loc[0]->CachedThumbnailCustomAsync(m_loc, w, h, idealW, idealH, ppvObj,(ILxUnknownID) asyncHandler);
    }

    auto CachedThumbnailCustomAsync(int w, int h, unsigned int *idealW, unsigned int *idealH, CLxLocalizedObject &o_dest, ILxUnknownID asyncHandler) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->CachedThumbnailCustomAsync(m_loc, w, h, idealW, idealH, &o_obj,(ILxUnknownID) asyncHandler);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto ChildManualOrderLookup(const char *childPath, unsigned int *pos) -> LxResult
    {
        return m_loc[0]->ChildManualOrderLookup(m_loc, childPath, pos);
    }

    auto ChildManualOrderSet(const char *childPath, unsigned int pos) -> LxResult
    {
        return m_loc[0]->ChildManualOrderSet(m_loc, childPath, pos);
    }

    auto ChildGridPositionLookup(const char *childPath, unsigned int *x, unsigned int *y) -> LxResult
    {
        return m_loc[0]->ChildGridPositionLookup(m_loc, childPath, x, y);
    }

    auto ChildGridPositionSet(const char *childPath, unsigned int x, unsigned int y) -> LxResult
    {
        return m_loc[0]->ChildGridPositionSet(m_loc, childPath, x, y);
    }

    auto GridExtents(unsigned int *bottom, unsigned int *right) -> LxResult
    {
        return m_loc[0]->GridExtents(m_loc, bottom, right);
    }

    auto GridSetExtents(unsigned int bottom, unsigned int right) -> LxResult
    {
        return m_loc[0]->GridSetExtents(m_loc, bottom, right);
    }

    auto GridInsert(int doRows, unsigned int x, unsigned int y, unsigned int count) -> LxResult
    {
        return m_loc[0]->GridInsert(m_loc, doRows, x, y, count);
    }

    auto GridRemove(int doRows, unsigned int x, unsigned int y, unsigned int count, int force) -> LxResult
    {
        return m_loc[0]->GridRemove(m_loc, doRows, x, y, count, force);
    }

    auto GridIsEmpty(int doRows, unsigned int x, unsigned int y) -> LxResult
    {
        return m_loc[0]->GridIsEmpty(m_loc, doRows, x, y);
    }

    auto GridIsEmptyCell(unsigned int x, unsigned int y, void **ppvObj) -> LxResult
    {
        return m_loc[0]->GridIsEmptyCell(m_loc, x, y, ppvObj);
    }

    auto GridIsEmptyCell(unsigned int x, unsigned int y, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->GridIsEmptyCell(m_loc, x, y, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Username(char *buf, unsigned int len) -> LxResult
    {
        return m_loc[0]->Username(m_loc, buf, len);
    }

    auto Username(std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->Username(m_loc, buf, len);
        LXWx_SBUF2
    }

    auto OverrideParent(char *buf, unsigned int len) -> LxResult
    {
        return m_loc[0]->OverrideParent(m_loc, buf, len);
    }

    auto OverrideParent(std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->OverrideParent(m_loc, buf, len);
        LXWx_SBUF2
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_DirEntryThumbAsync
{
public:
    virtual ~CLxImpl_DirEntryThumbAsync() = default;

    virtual auto detasync_Ready([[maybe_unused]] ILxUnknownID dirCacheEntry, [[maybe_unused]] unsigned int idealW, [[maybe_unused]] unsigned int idealH, [[maybe_unused]] ILxUnknownID image) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto detasync_Failed([[maybe_unused]] ILxUnknownID dirCacheEntry) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto detasync_Ident([[maybe_unused]] const char **ident) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_DirEntryThumbAsync_Ready LxResult detasync_Ready([[maybe_unused]] ILxUnknownID dirCacheEntry, [[maybe_unused]] unsigned int idealW, [[maybe_unused]] unsigned int idealH, [[maybe_unused]] ILxUnknownID image) override
#define LXxO_DirEntryThumbAsync_Ready LXxD_DirEntryThumbAsync_Ready
#define LXxC_DirEntryThumbAsync_Ready(c) LxResult c::detasync_Ready([[maybe_unused]] ILxUnknownID dirCacheEntry, [[maybe_unused]] unsigned int idealW, [[maybe_unused]] unsigned int idealH, [[maybe_unused]] ILxUnknownID image)
#define LXxD_DirEntryThumbAsync_Failed LxResult detasync_Failed([[maybe_unused]] ILxUnknownID dirCacheEntry) override
#define LXxO_DirEntryThumbAsync_Failed LXxD_DirEntryThumbAsync_Failed
#define LXxC_DirEntryThumbAsync_Failed(c) LxResult c::detasync_Failed([[maybe_unused]] ILxUnknownID dirCacheEntry)
#define LXxD_DirEntryThumbAsync_Ident LxResult detasync_Ident([[maybe_unused]] const char **ident) override
#define LXxO_DirEntryThumbAsync_Ident LXxD_DirEntryThumbAsync_Ident
#define LXxC_DirEntryThumbAsync_Ident(c) LxResult c::detasync_Ident([[maybe_unused]] const char **ident)

template <class T>
class CLxIfc_DirEntryThumbAsync: public CLxInterface
{
public:
    CLxIfc_DirEntryThumbAsync()
    {
        vt.Ready = Ready;
        vt.Failed = Failed;
        vt.Ident = Ident;
        vTable = &vt.iunk;
        iid = &lx::guid_DirEntryThumbAsync;
    }

    static auto Ready(LXtObjectID wcom,LXtObjectID dirCacheEntry,unsigned int idealW,unsigned int idealH,LXtObjectID image) -> LxResult
    {
        LXCWxINST (CLxImpl_DirEntryThumbAsync, loc);
        try
        {
           return loc->detasync_Ready((ILxUnknownID) dirCacheEntry, idealW, idealH,(ILxUnknownID) image);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Failed(LXtObjectID wcom,LXtObjectID dirCacheEntry) -> LxResult
    {
        LXCWxINST (CLxImpl_DirEntryThumbAsync, loc);
        try
        {
           return loc->detasync_Failed((ILxUnknownID) dirCacheEntry);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Ident(LXtObjectID wcom,const char **ident) -> LxResult
    {
        LXCWxINST (CLxImpl_DirEntryThumbAsync, loc);
        try
        {
           return loc->detasync_Ident( ident);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxDirEntryThumbAsync vt;
};

class CLxLoc_DirEntryThumbAsync : public CLxLocalize<ILxDirEntryThumbAsyncID>
{
public:
    CLxLoc_DirEntryThumbAsync()
    {
        _init();
    }

    CLxLoc_DirEntryThumbAsync(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_DirEntryThumbAsync(CLxLoc_DirEntryThumbAsync const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_DirEntryThumbAsync;
    }

    auto Ready(ILxUnknownID dirCacheEntry, unsigned int idealW, unsigned int idealH, ILxUnknownID image) -> LxResult
    {
        return m_loc[0]->Ready(m_loc,(ILxUnknownID) dirCacheEntry, idealW, idealH,(ILxUnknownID) image);
    }

    auto Failed(ILxUnknownID dirCacheEntry) -> LxResult
    {
        return m_loc[0]->Failed(m_loc,(ILxUnknownID) dirCacheEntry);
    }

    auto Ident(const char **ident) -> LxResult
    {
        return m_loc[0]->Ident(m_loc, ident);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_MergedDirCacheEntry : public CLxLocalize<ILxMergedDirCacheEntryID>
{
public:
    CLxLoc_MergedDirCacheEntry()
    {
        _init();
    }

    CLxLoc_MergedDirCacheEntry(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_MergedDirCacheEntry(CLxLoc_MergedDirCacheEntry const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_MergedDirCacheEntry;
    }

    auto Path(char *buf, unsigned int len) -> LxResult
    {
        return m_loc[0]->Path(m_loc, buf, len);
    }

    auto Path(std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->Path(m_loc, buf, len);
        LXWx_SBUF2
    }

    auto EntryCount(int *count) -> LxResult
    {
        return m_loc[0]->EntryCount(m_loc, count);
    }

    auto EntryByIndex(int index, void **ppvObj) -> LxResult
    {
        return m_loc[0]->EntryByIndex(m_loc, index, ppvObj);
    }

    auto EntryByIndex(int index, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->EntryByIndex(m_loc, index, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto UserPath(char *buf, unsigned int len) -> LxResult
    {
        return m_loc[0]->UserPath(m_loc, buf, len);
    }

    auto UserPath(std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->UserPath(m_loc, buf, len);
        LXWx_SBUF2
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

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_DirCacheFileMetrics
{
public:
    virtual ~CLxImpl_DirCacheFileMetrics() = default;

    virtual auto dcfilemetrics_Metadata([[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto dcfilemetrics_Markup([[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto dcfilemetrics_Flags([[maybe_unused]] int *flags) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_DirCacheFileMetrics_Metadata LxResult dcfilemetrics_Metadata([[maybe_unused]] void **ppvObj) override
#define LXxO_DirCacheFileMetrics_Metadata LXxD_DirCacheFileMetrics_Metadata
#define LXxC_DirCacheFileMetrics_Metadata(c) LxResult c::dcfilemetrics_Metadata([[maybe_unused]] void **ppvObj)
#define LXxD_DirCacheFileMetrics_Markup LxResult dcfilemetrics_Markup([[maybe_unused]] void **ppvObj) override
#define LXxO_DirCacheFileMetrics_Markup LXxD_DirCacheFileMetrics_Markup
#define LXxC_DirCacheFileMetrics_Markup(c) LxResult c::dcfilemetrics_Markup([[maybe_unused]] void **ppvObj)
#define LXxD_DirCacheFileMetrics_Flags LxResult dcfilemetrics_Flags([[maybe_unused]] int *flags) override
#define LXxO_DirCacheFileMetrics_Flags LXxD_DirCacheFileMetrics_Flags
#define LXxC_DirCacheFileMetrics_Flags(c) LxResult c::dcfilemetrics_Flags([[maybe_unused]] int *flags)

template <class T>
class CLxIfc_DirCacheFileMetrics: public CLxInterface
{
public:
    CLxIfc_DirCacheFileMetrics()
    {
        vt.Metadata = Metadata;
        vt.Markup = Markup;
        vt.Flags = Flags;
        vTable = &vt.iunk;
        iid = &lx::guid_DirCacheFileMetrics;
    }

    static auto Metadata(LXtObjectID wcom,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_DirCacheFileMetrics, loc);
        try
        {
           return loc->dcfilemetrics_Metadata( ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Markup(LXtObjectID wcom,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_DirCacheFileMetrics, loc);
        try
        {
           return loc->dcfilemetrics_Markup( ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Flags(LXtObjectID wcom,int *flags) -> LxResult
    {
        LXCWxINST (CLxImpl_DirCacheFileMetrics, loc);
        try
        {
           return loc->dcfilemetrics_Flags( flags);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxDirCacheFileMetrics vt;
};

class CLxLoc_DirCacheFileMetrics : public CLxLocalize<ILxDirCacheFileMetricsID>
{
public:
    CLxLoc_DirCacheFileMetrics()
    {
        _init();
    }

    CLxLoc_DirCacheFileMetrics(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_DirCacheFileMetrics(CLxLoc_DirCacheFileMetrics const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_DirCacheFileMetrics;
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
class CLxImpl_DirCacheSynthetic
{
public:
    virtual ~CLxImpl_DirCacheSynthetic() = default;

    virtual auto dcsyn_Lookup([[maybe_unused]] const char *path, [[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto dcsyn_Root([[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_DirCacheSynthetic_Lookup LxResult dcsyn_Lookup([[maybe_unused]] const char *path, [[maybe_unused]] void **ppvObj) override
#define LXxO_DirCacheSynthetic_Lookup LXxD_DirCacheSynthetic_Lookup
#define LXxC_DirCacheSynthetic_Lookup(c) LxResult c::dcsyn_Lookup([[maybe_unused]] const char *path, [[maybe_unused]] void **ppvObj)
#define LXxD_DirCacheSynthetic_Root LxResult dcsyn_Root([[maybe_unused]] void **ppvObj) override
#define LXxO_DirCacheSynthetic_Root LXxD_DirCacheSynthetic_Root
#define LXxC_DirCacheSynthetic_Root(c) LxResult c::dcsyn_Root([[maybe_unused]] void **ppvObj)

template <class T>
class CLxIfc_DirCacheSynthetic: public CLxInterface
{
public:
    CLxIfc_DirCacheSynthetic()
    {
        vt.Lookup = Lookup;
        vt.Root = Root;
        vTable = &vt.iunk;
        iid = &lx::guid_DirCacheSynthetic;
    }

    static auto Lookup(LXtObjectID wcom,const char *path,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_DirCacheSynthetic, loc);
        try
        {
           return loc->dcsyn_Lookup( path, ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Root(LXtObjectID wcom,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_DirCacheSynthetic, loc);
        try
        {
           return loc->dcsyn_Root( ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxDirCacheSynthetic vt;
};

class CLxLoc_DirCacheSynthetic : public CLxLocalize<ILxDirCacheSyntheticID>
{
public:
    CLxLoc_DirCacheSynthetic()
    {
        _init();
    }

    CLxLoc_DirCacheSynthetic(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_DirCacheSynthetic(CLxLoc_DirCacheSynthetic const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_DirCacheSynthetic;
    }

    auto Lookup(const char *path, void **ppvObj) -> LxResult
    {
        return m_loc[0]->Lookup(m_loc, path, ppvObj);
    }

    auto Lookup(const char *path, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Lookup(m_loc, path, &o_obj);
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
class CLxImpl_DirCacheSyntheticEntry1
{
public:
    virtual ~CLxImpl_DirCacheSyntheticEntry1() = default;

    virtual auto dcsyne_Path([[maybe_unused]] char *buf, [[maybe_unused]] int len) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto dcsyne_Name([[maybe_unused]] char *buf, [[maybe_unused]] int len) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto dcsyne_DirUsername([[maybe_unused]] char *buf, [[maybe_unused]] unsigned int len) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto dcsyne_FileExtension([[maybe_unused]] char *buf, [[maybe_unused]] unsigned int len) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto dcsyne_IsFile([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto dcsyne_DirBuild([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual unsigned int dcsyne_DirCount(int listMode) = 0;

    virtual auto dcsyne_DirByIndex([[maybe_unused]] int listMode, [[maybe_unused]] unsigned int index, [[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto dcsyne_ModTime([[maybe_unused]] char *buf, [[maybe_unused]] unsigned int len) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual double dcsyne_Size(void) = 0;
};

#define LXxD_DirCacheSyntheticEntry1_Path LxResult dcsyne_Path([[maybe_unused]] char *buf, [[maybe_unused]] int len) override
#define LXxO_DirCacheSyntheticEntry1_Path LXxD_DirCacheSyntheticEntry1_Path
#define LXxC_DirCacheSyntheticEntry1_Path(c) LxResult c::dcsyne_Path([[maybe_unused]] char *buf, [[maybe_unused]] int len)
#define LXxD_DirCacheSyntheticEntry1_Name LxResult dcsyne_Name([[maybe_unused]] char *buf, [[maybe_unused]] int len) override
#define LXxO_DirCacheSyntheticEntry1_Name LXxD_DirCacheSyntheticEntry1_Name
#define LXxC_DirCacheSyntheticEntry1_Name(c) LxResult c::dcsyne_Name([[maybe_unused]] char *buf, [[maybe_unused]] int len)
#define LXxD_DirCacheSyntheticEntry1_DirUsername LxResult dcsyne_DirUsername([[maybe_unused]] char *buf, [[maybe_unused]] unsigned int len) override
#define LXxO_DirCacheSyntheticEntry1_DirUsername LXxD_DirCacheSyntheticEntry1_DirUsername
#define LXxC_DirCacheSyntheticEntry1_DirUsername(c) LxResult c::dcsyne_DirUsername([[maybe_unused]] char *buf, [[maybe_unused]] unsigned int len)
#define LXxD_DirCacheSyntheticEntry1_FileExtension LxResult dcsyne_FileExtension([[maybe_unused]] char *buf, [[maybe_unused]] unsigned int len) override
#define LXxO_DirCacheSyntheticEntry1_FileExtension LXxD_DirCacheSyntheticEntry1_FileExtension
#define LXxC_DirCacheSyntheticEntry1_FileExtension(c) LxResult c::dcsyne_FileExtension([[maybe_unused]] char *buf, [[maybe_unused]] unsigned int len)
#define LXxD_DirCacheSyntheticEntry1_IsFile LxResult dcsyne_IsFile() override
#define LXxO_DirCacheSyntheticEntry1_IsFile LXxD_DirCacheSyntheticEntry1_IsFile
#define LXxC_DirCacheSyntheticEntry1_IsFile(c) LxResult c::dcsyne_IsFile()
#define LXxD_DirCacheSyntheticEntry1_DirBuild LxResult dcsyne_DirBuild() override
#define LXxO_DirCacheSyntheticEntry1_DirBuild LXxD_DirCacheSyntheticEntry1_DirBuild
#define LXxC_DirCacheSyntheticEntry1_DirBuild(c) LxResult c::dcsyne_DirBuild()
#define LXxD_DirCacheSyntheticEntry1_DirCount unsigned int dcsyne_DirCount([[maybe_unused]] int listMode) override
#define LXxO_DirCacheSyntheticEntry1_DirCount LXxD_DirCacheSyntheticEntry1_DirCount
#define LXxC_DirCacheSyntheticEntry1_DirCount(c) unsigned int c::dcsyne_DirCount([[maybe_unused]] int listMode)
#define LXxD_DirCacheSyntheticEntry1_DirByIndex LxResult dcsyne_DirByIndex([[maybe_unused]] int listMode, [[maybe_unused]] unsigned int index, [[maybe_unused]] void **ppvObj) override
#define LXxO_DirCacheSyntheticEntry1_DirByIndex LXxD_DirCacheSyntheticEntry1_DirByIndex
#define LXxC_DirCacheSyntheticEntry1_DirByIndex(c) LxResult c::dcsyne_DirByIndex([[maybe_unused]] int listMode, [[maybe_unused]] unsigned int index, [[maybe_unused]] void **ppvObj)
#define LXxD_DirCacheSyntheticEntry1_ModTime LxResult dcsyne_ModTime([[maybe_unused]] char *buf, [[maybe_unused]] unsigned int len) override
#define LXxO_DirCacheSyntheticEntry1_ModTime LXxD_DirCacheSyntheticEntry1_ModTime
#define LXxC_DirCacheSyntheticEntry1_ModTime(c) LxResult c::dcsyne_ModTime([[maybe_unused]] char *buf, [[maybe_unused]] unsigned int len)
#define LXxD_DirCacheSyntheticEntry1_Size double dcsyne_Size() override
#define LXxO_DirCacheSyntheticEntry1_Size LXxD_DirCacheSyntheticEntry1_Size
#define LXxC_DirCacheSyntheticEntry1_Size(c) double c::dcsyne_Size()

template <class T>
class CLxIfc_DirCacheSyntheticEntry1: public CLxInterface
{
public:
    CLxIfc_DirCacheSyntheticEntry1()
    {
        vt.Path = Path;
        vt.Name = Name;
        vt.DirUsername = DirUsername;
        vt.FileExtension = FileExtension;
        vt.IsFile = IsFile;
        vt.DirBuild = DirBuild;
        vt.DirCount = DirCount;
        vt.DirByIndex = DirByIndex;
        vt.ModTime = ModTime;
        vt.Size = Size;
        vTable = &vt.iunk;
        iid = &lx::guid_DirCacheSyntheticEntry1;
    }

    static auto Path(LXtObjectID wcom,char *buf,int len) -> LxResult
    {
        LXCWxINST (CLxImpl_DirCacheSyntheticEntry1, loc);
        try
        {
           return loc->dcsyne_Path( buf, len);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Name(LXtObjectID wcom,char *buf,int len) -> LxResult
    {
        LXCWxINST (CLxImpl_DirCacheSyntheticEntry1, loc);
        try
        {
           return loc->dcsyne_Name( buf, len);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto DirUsername(LXtObjectID wcom,char *buf,unsigned int len) -> LxResult
    {
        LXCWxINST (CLxImpl_DirCacheSyntheticEntry1, loc);
        try
        {
           return loc->dcsyne_DirUsername( buf, len);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto FileExtension(LXtObjectID wcom,char *buf,unsigned int len) -> LxResult
    {
        LXCWxINST (CLxImpl_DirCacheSyntheticEntry1, loc);
        try
        {
           return loc->dcsyne_FileExtension( buf, len);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto IsFile(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_DirCacheSyntheticEntry1, loc);
        try
        {
           return loc->dcsyne_IsFile();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto DirBuild(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_DirCacheSyntheticEntry1, loc);
        try
        {
           return loc->dcsyne_DirBuild();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto DirCount(LXtObjectID wcom,int listMode) -> unsigned int
    {
        LXCWxINST (CLxImpl_DirCacheSyntheticEntry1, loc);
        return loc->dcsyne_DirCount( listMode);
    }

    static auto DirByIndex(LXtObjectID wcom,int listMode,unsigned int index,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_DirCacheSyntheticEntry1, loc);
        try
        {
           return loc->dcsyne_DirByIndex( listMode, index, ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ModTime(LXtObjectID wcom,char *buf,unsigned int len) -> LxResult
    {
        LXCWxINST (CLxImpl_DirCacheSyntheticEntry1, loc);
        try
        {
           return loc->dcsyne_ModTime( buf, len);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Size(LXtObjectID wcom) -> double
    {
        LXCWxINST (CLxImpl_DirCacheSyntheticEntry1, loc);
        return loc->dcsyne_Size();
    }

private:
    ILxDirCacheSyntheticEntry1 vt;
};

class CLxLoc_DirCacheSyntheticEntry1 : public CLxLocalize<ILxDirCacheSyntheticEntry1ID>
{
public:
    CLxLoc_DirCacheSyntheticEntry1()
    {
        _init();
    }

    CLxLoc_DirCacheSyntheticEntry1(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_DirCacheSyntheticEntry1(CLxLoc_DirCacheSyntheticEntry1 const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_DirCacheSyntheticEntry1;
    }

    auto Path(char *buf, int len) -> LxResult
    {
        return m_loc[0]->Path(m_loc, buf, len);
    }

    auto Name(char *buf, int len) -> LxResult
    {
        return m_loc[0]->Name(m_loc, buf, len);
    }

    auto DirUsername(char *buf, unsigned int len) -> LxResult
    {
        return m_loc[0]->DirUsername(m_loc, buf, len);
    }

    auto DirUsername(std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->DirUsername(m_loc, buf, len);
        LXWx_SBUF2
    }

    auto FileExtension(char *buf, unsigned int len) -> LxResult
    {
        return m_loc[0]->FileExtension(m_loc, buf, len);
    }

    auto FileExtension(std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->FileExtension(m_loc, buf, len);
        LXWx_SBUF2
    }

    auto IsFile(void) -> LxResult
    {
        return m_loc[0]->IsFile(m_loc);
    }

    auto DirBuild(void) -> LxResult
    {
        return m_loc[0]->DirBuild(m_loc);
    }

    auto DirCount(int listMode) -> unsigned int
    {
        return m_loc[0]->DirCount(m_loc, listMode);
    }

    auto DirByIndex(int listMode, unsigned int index, void **ppvObj) -> LxResult
    {
        return m_loc[0]->DirByIndex(m_loc, listMode, index, ppvObj);
    }

    auto DirByIndex(int listMode, unsigned int index, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->DirByIndex(m_loc, listMode, index, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto ModTime(char *buf, unsigned int len) -> LxResult
    {
        return m_loc[0]->ModTime(m_loc, buf, len);
    }

    auto ModTime(std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->ModTime(m_loc, buf, len);
        LXWx_SBUF2
    }

    auto Size(void) -> double
    {
        return m_loc[0]->Size(m_loc);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_DirCacheSyntheticEntry
{
public:
    virtual ~CLxImpl_DirCacheSyntheticEntry() = default;

    virtual auto dcsyne_Path([[maybe_unused]] char *buf, [[maybe_unused]] unsigned int len) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto dcsyne_OverrideParent([[maybe_unused]] char *buf, [[maybe_unused]] unsigned int len) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto dcsyne_Name([[maybe_unused]] char *buf, [[maybe_unused]] unsigned int len) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto dcsyne_DirUsername([[maybe_unused]] char *buf, [[maybe_unused]] unsigned int len) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto dcsyne_FileExtension([[maybe_unused]] char *buf, [[maybe_unused]] unsigned int len) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto dcsyne_IsFile([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto dcsyne_DirBuild([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual unsigned int dcsyne_DirCount(int listMode) = 0;

    virtual auto dcsyne_DirByIndex([[maybe_unused]] int listMode, [[maybe_unused]] unsigned int index, [[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto dcsyne_ModTime([[maybe_unused]] char *buf, [[maybe_unused]] unsigned int len) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual double dcsyne_Size(void) = 0;
};

#define LXxD_DirCacheSyntheticEntry_Path LxResult dcsyne_Path([[maybe_unused]] char *buf, [[maybe_unused]] unsigned int len) override
#define LXxO_DirCacheSyntheticEntry_Path LXxD_DirCacheSyntheticEntry_Path
#define LXxC_DirCacheSyntheticEntry_Path(c) LxResult c::dcsyne_Path([[maybe_unused]] char *buf, [[maybe_unused]] unsigned int len)
#define LXxD_DirCacheSyntheticEntry_OverrideParent LxResult dcsyne_OverrideParent([[maybe_unused]] char *buf, [[maybe_unused]] unsigned int len) override
#define LXxO_DirCacheSyntheticEntry_OverrideParent LXxD_DirCacheSyntheticEntry_OverrideParent
#define LXxC_DirCacheSyntheticEntry_OverrideParent(c) LxResult c::dcsyne_OverrideParent([[maybe_unused]] char *buf, [[maybe_unused]] unsigned int len)
#define LXxD_DirCacheSyntheticEntry_Name LxResult dcsyne_Name([[maybe_unused]] char *buf, [[maybe_unused]] unsigned int len) override
#define LXxO_DirCacheSyntheticEntry_Name LXxD_DirCacheSyntheticEntry_Name
#define LXxC_DirCacheSyntheticEntry_Name(c) LxResult c::dcsyne_Name([[maybe_unused]] char *buf, [[maybe_unused]] unsigned int len)
#define LXxD_DirCacheSyntheticEntry_DirUsername LxResult dcsyne_DirUsername([[maybe_unused]] char *buf, [[maybe_unused]] unsigned int len) override
#define LXxO_DirCacheSyntheticEntry_DirUsername LXxD_DirCacheSyntheticEntry_DirUsername
#define LXxC_DirCacheSyntheticEntry_DirUsername(c) LxResult c::dcsyne_DirUsername([[maybe_unused]] char *buf, [[maybe_unused]] unsigned int len)
#define LXxD_DirCacheSyntheticEntry_FileExtension LxResult dcsyne_FileExtension([[maybe_unused]] char *buf, [[maybe_unused]] unsigned int len) override
#define LXxO_DirCacheSyntheticEntry_FileExtension LXxD_DirCacheSyntheticEntry_FileExtension
#define LXxC_DirCacheSyntheticEntry_FileExtension(c) LxResult c::dcsyne_FileExtension([[maybe_unused]] char *buf, [[maybe_unused]] unsigned int len)
#define LXxD_DirCacheSyntheticEntry_IsFile LxResult dcsyne_IsFile() override
#define LXxO_DirCacheSyntheticEntry_IsFile LXxD_DirCacheSyntheticEntry_IsFile
#define LXxC_DirCacheSyntheticEntry_IsFile(c) LxResult c::dcsyne_IsFile()
#define LXxD_DirCacheSyntheticEntry_DirBuild LxResult dcsyne_DirBuild() override
#define LXxO_DirCacheSyntheticEntry_DirBuild LXxD_DirCacheSyntheticEntry_DirBuild
#define LXxC_DirCacheSyntheticEntry_DirBuild(c) LxResult c::dcsyne_DirBuild()
#define LXxD_DirCacheSyntheticEntry_DirCount unsigned int dcsyne_DirCount([[maybe_unused]] int listMode) override
#define LXxO_DirCacheSyntheticEntry_DirCount LXxD_DirCacheSyntheticEntry_DirCount
#define LXxC_DirCacheSyntheticEntry_DirCount(c) unsigned int c::dcsyne_DirCount([[maybe_unused]] int listMode)
#define LXxD_DirCacheSyntheticEntry_DirByIndex LxResult dcsyne_DirByIndex([[maybe_unused]] int listMode, [[maybe_unused]] unsigned int index, [[maybe_unused]] void **ppvObj) override
#define LXxO_DirCacheSyntheticEntry_DirByIndex LXxD_DirCacheSyntheticEntry_DirByIndex
#define LXxC_DirCacheSyntheticEntry_DirByIndex(c) LxResult c::dcsyne_DirByIndex([[maybe_unused]] int listMode, [[maybe_unused]] unsigned int index, [[maybe_unused]] void **ppvObj)
#define LXxD_DirCacheSyntheticEntry_ModTime LxResult dcsyne_ModTime([[maybe_unused]] char *buf, [[maybe_unused]] unsigned int len) override
#define LXxO_DirCacheSyntheticEntry_ModTime LXxD_DirCacheSyntheticEntry_ModTime
#define LXxC_DirCacheSyntheticEntry_ModTime(c) LxResult c::dcsyne_ModTime([[maybe_unused]] char *buf, [[maybe_unused]] unsigned int len)
#define LXxD_DirCacheSyntheticEntry_Size double dcsyne_Size() override
#define LXxO_DirCacheSyntheticEntry_Size LXxD_DirCacheSyntheticEntry_Size
#define LXxC_DirCacheSyntheticEntry_Size(c) double c::dcsyne_Size()

template <class T>
class CLxIfc_DirCacheSyntheticEntry: public CLxInterface
{
public:
    CLxIfc_DirCacheSyntheticEntry()
    {
        vt.Path = Path;
        vt.OverrideParent = OverrideParent;
        vt.Name = Name;
        vt.DirUsername = DirUsername;
        vt.FileExtension = FileExtension;
        vt.IsFile = IsFile;
        vt.DirBuild = DirBuild;
        vt.DirCount = DirCount;
        vt.DirByIndex = DirByIndex;
        vt.ModTime = ModTime;
        vt.Size = Size;
        vTable = &vt.iunk;
        iid = &lx::guid_DirCacheSyntheticEntry;
    }

    static auto Path(LXtObjectID wcom,char *buf,unsigned int len) -> LxResult
    {
        LXCWxINST (CLxImpl_DirCacheSyntheticEntry, loc);
        try
        {
           return loc->dcsyne_Path( buf, len);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto OverrideParent(LXtObjectID wcom,char *buf,unsigned int len) -> LxResult
    {
        LXCWxINST (CLxImpl_DirCacheSyntheticEntry, loc);
        try
        {
           return loc->dcsyne_OverrideParent( buf, len);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Name(LXtObjectID wcom,char *buf,unsigned int len) -> LxResult
    {
        LXCWxINST (CLxImpl_DirCacheSyntheticEntry, loc);
        try
        {
           return loc->dcsyne_Name( buf, len);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto DirUsername(LXtObjectID wcom,char *buf,unsigned int len) -> LxResult
    {
        LXCWxINST (CLxImpl_DirCacheSyntheticEntry, loc);
        try
        {
           return loc->dcsyne_DirUsername( buf, len);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto FileExtension(LXtObjectID wcom,char *buf,unsigned int len) -> LxResult
    {
        LXCWxINST (CLxImpl_DirCacheSyntheticEntry, loc);
        try
        {
           return loc->dcsyne_FileExtension( buf, len);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto IsFile(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_DirCacheSyntheticEntry, loc);
        try
        {
           return loc->dcsyne_IsFile();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto DirBuild(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_DirCacheSyntheticEntry, loc);
        try
        {
           return loc->dcsyne_DirBuild();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto DirCount(LXtObjectID wcom,int listMode) -> unsigned int
    {
        LXCWxINST (CLxImpl_DirCacheSyntheticEntry, loc);
        return loc->dcsyne_DirCount( listMode);
    }

    static auto DirByIndex(LXtObjectID wcom,int listMode,unsigned int index,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_DirCacheSyntheticEntry, loc);
        try
        {
           return loc->dcsyne_DirByIndex( listMode, index, ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ModTime(LXtObjectID wcom,char *buf,unsigned int len) -> LxResult
    {
        LXCWxINST (CLxImpl_DirCacheSyntheticEntry, loc);
        try
        {
           return loc->dcsyne_ModTime( buf, len);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Size(LXtObjectID wcom) -> double
    {
        LXCWxINST (CLxImpl_DirCacheSyntheticEntry, loc);
        return loc->dcsyne_Size();
    }

private:
    ILxDirCacheSyntheticEntry vt;
};

class CLxLoc_DirCacheSyntheticEntry : public CLxLocalize<ILxDirCacheSyntheticEntryID>
{
public:
    CLxLoc_DirCacheSyntheticEntry()
    {
        _init();
    }

    CLxLoc_DirCacheSyntheticEntry(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_DirCacheSyntheticEntry(CLxLoc_DirCacheSyntheticEntry const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_DirCacheSyntheticEntry;
    }

    auto Path(char *buf, unsigned int len) -> LxResult
    {
        return m_loc[0]->Path(m_loc, buf, len);
    }

    auto Path(std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->Path(m_loc, buf, len);
        LXWx_SBUF2
    }

    auto OverrideParent(char *buf, unsigned int len) -> LxResult
    {
        return m_loc[0]->OverrideParent(m_loc, buf, len);
    }

    auto OverrideParent(std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->OverrideParent(m_loc, buf, len);
        LXWx_SBUF2
    }

    auto Name(char *buf, unsigned int len) -> LxResult
    {
        return m_loc[0]->Name(m_loc, buf, len);
    }

    auto Name(std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->Name(m_loc, buf, len);
        LXWx_SBUF2
    }

    auto DirUsername(char *buf, unsigned int len) -> LxResult
    {
        return m_loc[0]->DirUsername(m_loc, buf, len);
    }

    auto DirUsername(std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->DirUsername(m_loc, buf, len);
        LXWx_SBUF2
    }

    auto FileExtension(char *buf, unsigned int len) -> LxResult
    {
        return m_loc[0]->FileExtension(m_loc, buf, len);
    }

    auto FileExtension(std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->FileExtension(m_loc, buf, len);
        LXWx_SBUF2
    }

    auto IsFile(void) -> LxResult
    {
        return m_loc[0]->IsFile(m_loc);
    }

    auto DirBuild(void) -> LxResult
    {
        return m_loc[0]->DirBuild(m_loc);
    }

    auto DirCount(int listMode) -> unsigned int
    {
        return m_loc[0]->DirCount(m_loc, listMode);
    }

    auto DirByIndex(int listMode, unsigned int index, void **ppvObj) -> LxResult
    {
        return m_loc[0]->DirByIndex(m_loc, listMode, index, ppvObj);
    }

    auto DirByIndex(int listMode, unsigned int index, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->DirByIndex(m_loc, listMode, index, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto ModTime(char *buf, unsigned int len) -> LxResult
    {
        return m_loc[0]->ModTime(m_loc, buf, len);
    }

    auto ModTime(std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->ModTime(m_loc, buf, len);
        LXWx_SBUF2
    }

    auto Size(void) -> double
    {
        return m_loc[0]->Size(m_loc);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_BasePathAddDest : public CLxLocalize<ILxBasePathAddDestID>
{
public:
    CLxLoc_BasePathAddDest()
    {
        _init();
    }

    CLxLoc_BasePathAddDest(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_BasePathAddDest(CLxLoc_BasePathAddDest const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_BasePathAddDest;
    }

    auto AddBasePath(const char *setName, const char *path) -> LxResult
    {
        return m_loc[0]->AddBasePath(m_loc, setName, path);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_DirCacheManualOrderDest : public CLxLocalize<ILxDirCacheManualOrderDestID>
{
public:
    CLxLoc_DirCacheManualOrderDest()
    {
        _init();
    }

    CLxLoc_DirCacheManualOrderDest(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_DirCacheManualOrderDest(CLxLoc_DirCacheManualOrderDest const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_DirCacheManualOrderDest;
    }

    auto BetweenPaths(void **ppvObj, const char **nameBefore, const char **nameAfter, int asPaths) -> LxResult
    {
        return m_loc[0]->BetweenPaths(m_loc, ppvObj, nameBefore, nameAfter, asPaths);
    }

    auto BetweenPaths(CLxLocalizedObject &o_dest, const char **nameBefore, const char **nameAfter, int asPaths) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->BetweenPaths(m_loc, &o_obj, nameBefore, nameAfter, asPaths);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_DirCacheGridPosDest : public CLxLocalize<ILxDirCacheGridPosDestID>
{
public:
    CLxLoc_DirCacheGridPosDest()
    {
        _init();
    }

    CLxLoc_DirCacheGridPosDest(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_DirCacheGridPosDest(CLxLoc_DirCacheGridPosDest const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_DirCacheGridPosDest;
    }

    auto GridPos(void **ppvObj, unsigned int *x, unsigned int *y) -> LxResult
    {
        return m_loc[0]->GridPos(m_loc, ppvObj, x, y);
    }

    auto GridPos(CLxLocalizedObject &o_dest, unsigned int *x, unsigned int *y) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->GridPos(m_loc, &o_obj, x, y);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_FileSysDest : public CLxLocalize<ILxFileSysDestID>
{
public:
    CLxLoc_FileSysDest()
    {
        _init();
    }

    CLxLoc_FileSysDest(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_FileSysDest(CLxLoc_FileSysDest const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_FileSysDest;
    }

    auto Path(const char **path) -> LxResult
    {
        return m_loc[0]->Path(m_loc, path);
    }

    auto IsDir(void) -> LxResult
    {
        return m_loc[0]->IsDir(m_loc);
    }

    auto AsDir(const char **dir) -> LxResult
    {
        return m_loc[0]->AsDir(m_loc, dir);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_MergedFileSysDest : public CLxLocalize<ILxMergedFileSysDestID>
{
public:
    CLxLoc_MergedFileSysDest()
    {
        _init();
    }

    CLxLoc_MergedFileSysDest(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_MergedFileSysDest(CLxLoc_MergedFileSysDest const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_MergedFileSysDest;
    }

    auto MergedEntry(void **ppvObj) -> LxResult
    {
        return m_loc[0]->MergedEntry(m_loc, ppvObj);
    }

    auto MergedEntry(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->MergedEntry(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto EntryCount(unsigned int *count) -> LxResult
    {
        return m_loc[0]->EntryCount(m_loc, count);
    }

    auto EntryByIndex(int index, void **ppvObj) -> LxResult
    {
        return m_loc[0]->EntryByIndex(m_loc, index, ppvObj);
    }

    auto EntryByIndex(int index, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->EntryByIndex(m_loc, index, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Path(char *buf, unsigned int len) -> LxResult
    {
        return m_loc[0]->Path(m_loc, buf, len);
    }

    auto Path(std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->Path(m_loc, buf, len);
        LXWx_SBUF2
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_DirBrowserBasePathEntryDest : public CLxLocalize<ILxDirBrowserBasePathEntryDestID>
{
public:
    CLxLoc_DirBrowserBasePathEntryDest()
    {
        _init();
    }

    CLxLoc_DirBrowserBasePathEntryDest(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_DirBrowserBasePathEntryDest(CLxLoc_DirBrowserBasePathEntryDest const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_DirBrowserBasePathEntryDest;
    }

    auto SetPath(const char **path) -> LxResult
    {
        return m_loc[0]->SetPath(m_loc, path);
    }

    auto OrdinalBefore(const char **ordinal) -> LxResult
    {
        return m_loc[0]->OrdinalBefore(m_loc, ordinal);
    }

    auto OrdinalAfter(const char **ordinal) -> LxResult
    {
        return m_loc[0]->OrdinalAfter(m_loc, ordinal);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
