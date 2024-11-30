//
// C++ wrapper for lxsdk/lxrenderslot.h.
//
//	Copyright 2024.
//
//
#pragma once

#include <lxrenderslot.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx
{
    static LXtGUID const guid_RenderSlotService = {0x0f1d9e87, {0xf441, 0x4deb}, {0xb9, 0x3b, 0x12, 0x9e, 0x2d, 0x0a, 0xce, 0xe3}};
    static LXtGUID const guid_RenderSlot = {0x7f3e8cb9, {0x2def, 0x4c50}, {0x9d, 0xd9, 0xd6, 0x19, 0x84, 0xbd, 0x32, 0x92}};
    static LXtGUID const guid_RenderSlotPass = {0x5c2a8557, {0x38b2, 0x4c7e}, {0x89, 0xbf, 0x90, 0xe9, 0xa2, 0xf6, 0x4d, 0xbb}};
    static LXtGUID const guid_RenderSlotOutput = {0xcac5a601, {0xe87a, 0x4e1d}, {0x93, 0x6b, 0x60, 0x74, 0x0a, 0xbf, 0x49, 0xf3}};
    static LXtGUID const guid_RenderSlotListener = {0x0c0f7bb4, {0x809d, 0x4c28}, {0xbb, 0x67, 0x54, 0x9d, 0x17, 0xb0, 0x4b, 0x71}};
    static LXtGUID const guid_RenderProgressListener = {0x1bc2eeb3, {0x6e43, 0x4559}, {0xb6, 0x62, 0x8f, 0x5d, 0x25, 0xa1, 0xa9, 0x8a}};
    static LXtGUID const guid_RenderProgressPixel = {0xbdc74053, {0x417d, 0x46dc}, {0xa9, 0xe0, 0x2e, 0xbb, 0xc2, 0x6d, 0x62, 0x13}};
} // namespace lx

class CLxLoc_RenderSlotService : public CLxLocalizedService
{
public:
    ILxRenderSlotServiceID m_loc{ nullptr };

public:
    CLxLoc_RenderSlotService()
    {
        _init();
        set();
    }

    ~CLxLoc_RenderSlotService() = default;

    void set()
    {
        if (!m_loc)
        {
            m_loc = reinterpret_cast<ILxRenderSlotServiceID>(lx::GetGlobal(&lx::guid_RenderSlotService));
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

    auto Initialize(void) -> LxResult
    {
        return m_loc[0]->Initialize(m_loc);
    }

    auto MaxSlots(void) -> int
    {
        return m_loc[0]->MaxSlots(m_loc);
    }

    auto SlotCount(int *count) -> LxResult
    {
        return m_loc[0]->SlotCount(m_loc, count);
    }

    auto SlotByIndex(int index, void **ppvObj) -> LxResult
    {
        return m_loc[0]->SlotByIndex(m_loc, index, ppvObj);
    }

    auto SlotByIndex(int index, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->SlotByIndex(m_loc, index, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto SlotLookupByIdent(int ident, void **ppvObj) -> LxResult
    {
        return m_loc[0]->SlotLookupByIdent(m_loc, ident, ppvObj);
    }

    auto SlotLookupByIdent(int ident, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->SlotLookupByIdent(m_loc, ident, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto SetupSlotForNewRender(int noImageOpt, const char *passName, int *newSlotIndex, int *limitedRegionBackgroundDiskSlot, int *limitedRegionBackgroundPassIndex) -> LxResult
    {
        return m_loc[0]->SetupSlotForNewRender(m_loc, noImageOpt, passName, newSlotIndex, limitedRegionBackgroundDiskSlot, limitedRegionBackgroundPassIndex);
    }

    auto ClearCurrentRenderSlot(bool asAbort) -> LxResult
    {
        return m_loc[0]->ClearCurrentRenderSlot(m_loc, asAbort);
    }

    auto CurrentRenderSlot(void **ppvObj) -> LxResult
    {
        return m_loc[0]->CurrentRenderSlot(m_loc, ppvObj);
    }

    auto CurrentRenderSlot(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->CurrentRenderSlot(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto SlotRemoveByIdent(int ident) -> LxResult
    {
        return m_loc[0]->SlotRemoveByIdent(m_loc, ident);
    }

    auto LoadImage(void) -> LxResult
    {
        return m_loc[0]->LoadImage(m_loc);
    }

    auto LoadImageFromPath(const char *filePath) -> LxResult
    {
        return m_loc[0]->LoadImageFromPath(m_loc, filePath);
    }

    auto WriteProgressImageForOutput(int outputIdx, void **ppvObj) -> LxResult
    {
        return m_loc[0]->WriteProgressImageForOutput(m_loc, outputIdx, ppvObj);
    }

    auto WriteProgressImageForOutput(int outputIdx, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->WriteProgressImageForOutput(m_loc, outputIdx, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto CurrentRenderPass(void **ppvObj) -> LxResult
    {
        return m_loc[0]->CurrentRenderPass(m_loc, ppvObj);
    }

    auto CurrentRenderPass(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->CurrentRenderPass(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_RenderSlot : public CLxLocalize<ILxRenderSlotID>
{
public:
    CLxLoc_RenderSlot()
    {
        _init();
    }

    CLxLoc_RenderSlot(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_RenderSlot(CLxLoc_RenderSlot const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_RenderSlot;
    }

    auto Ident(int *ident) -> LxResult
    {
        return m_loc[0]->Ident(m_loc, ident);
    }

    auto Type(int *type) -> LxResult
    {
        return m_loc[0]->Type(m_loc, type);
    }

    auto IsRendering(void) -> LxResult
    {
        return m_loc[0]->IsRendering(m_loc);
    }

    auto Mapping(int *mapping) -> LxResult
    {
        return m_loc[0]->Mapping(m_loc, mapping);
    }

    auto SetMapping(int mapping) -> LxResult
    {
        return m_loc[0]->SetMapping(m_loc, mapping);
    }

    auto DiskSlotIndex(int *index) -> LxResult
    {
        return m_loc[0]->DiskSlotIndex(m_loc, index);
    }

    auto IsLocked(void) -> LxResult
    {
        return m_loc[0]->IsLocked(m_loc);
    }

    auto SetIsLocked(int lock) -> LxResult
    {
        return m_loc[0]->SetIsLocked(m_loc, lock);
    }

    auto Stats(void **ppvObj) -> LxResult
    {
        return m_loc[0]->Stats(m_loc, ppvObj);
    }

    auto Stats(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Stats(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto ImagePath(char *buf, int len) -> LxResult
    {
        return m_loc[0]->ImagePath(m_loc, buf, len);
    }

    auto ImageByteFormat(int *format) -> LxResult
    {
        return m_loc[0]->ImageByteFormat(m_loc, format);
    }

    auto IsAbortedRender(void) -> LxResult
    {
        return m_loc[0]->IsAbortedRender(m_loc);
    }

    auto PassCount(int *count) -> LxResult
    {
        return m_loc[0]->PassCount(m_loc, count);
    }

    auto PassByIndex(int index, void **ppvObj) -> LxResult
    {
        return m_loc[0]->PassByIndex(m_loc, index, ppvObj);
    }

    auto PassByIndex(int index, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->PassByIndex(m_loc, index, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto PassLookupByName(const char *name, void **ppvObj) -> LxResult
    {
        return m_loc[0]->PassLookupByName(m_loc, name, ppvObj);
    }

    auto PassLookupByName(const char *name, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->PassLookupByName(m_loc, name, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto QuickThumbnail(void **ppvObj) -> LxResult
    {
        return m_loc[0]->QuickThumbnail(m_loc, ppvObj);
    }

    auto QuickThumbnail(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->QuickThumbnail(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto ImageSource(void **ppvObj) -> LxResult
    {
        return m_loc[0]->ImageSource(m_loc, ppvObj);
    }

    auto ImageSource(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->ImageSource(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_RenderSlotPass : public CLxLocalize<ILxRenderSlotPassID>
{
public:
    CLxLoc_RenderSlotPass()
    {
        _init();
    }

    CLxLoc_RenderSlotPass(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_RenderSlotPass(CLxLoc_RenderSlotPass const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_RenderSlotPass;
    }

    auto Name(char *buf, int len) -> LxResult
    {
        return m_loc[0]->Name(m_loc, buf, len);
    }

    auto Slot(void **ppvObj) -> LxResult
    {
        return m_loc[0]->Slot(m_loc, ppvObj);
    }

    auto Slot(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Slot(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Index(int *index) -> LxResult
    {
        return m_loc[0]->Index(m_loc, index);
    }

    auto IsRendering(void) -> LxResult
    {
        return m_loc[0]->IsRendering(m_loc);
    }

    auto FrameBuffer(void **ppvObj) -> LxResult
    {
        return m_loc[0]->FrameBuffer(m_loc, ppvObj);
    }

    auto FrameBuffer(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->FrameBuffer(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto FrameBufferLoadResult(int *index) -> LxResult
    {
        return m_loc[0]->FrameBufferLoadResult(m_loc, index);
    }

    auto OutputCount(int *count) -> LxResult
    {
        return m_loc[0]->OutputCount(m_loc, count);
    }

    auto OutputByIndex(int index, void **ppvObj) -> LxResult
    {
        return m_loc[0]->OutputByIndex(m_loc, index, ppvObj);
    }

    auto OutputByIndex(int index, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->OutputByIndex(m_loc, index, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto OutputLookupByName(const char *name, void **ppvObj) -> LxResult
    {
        return m_loc[0]->OutputLookupByName(m_loc, name, ppvObj);
    }

    auto OutputLookupByName(const char *name, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->OutputLookupByName(m_loc, name, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto OutputLookupByType(int type, void **ppvObj) -> LxResult
    {
        return m_loc[0]->OutputLookupByType(m_loc, type, ppvObj);
    }

    auto OutputLookupByType(int type, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->OutputLookupByType(m_loc, type, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_RenderSlotOutput : public CLxLocalize<ILxRenderSlotOutputID>
{
public:
    CLxLoc_RenderSlotOutput()
    {
        _init();
    }

    CLxLoc_RenderSlotOutput(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_RenderSlotOutput(CLxLoc_RenderSlotOutput const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_RenderSlotOutput;
    }

    auto Name(char *buf, int len) -> LxResult
    {
        return m_loc[0]->Name(m_loc, buf, len);
    }

    auto Pass(void **ppvObj) -> LxResult
    {
        return m_loc[0]->Pass(m_loc, ppvObj);
    }

    auto Pass(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Pass(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Type(int *type) -> LxResult
    {
        return m_loc[0]->Type(m_loc, type);
    }

    auto Index(int *index) -> LxResult
    {
        return m_loc[0]->Index(m_loc, index);
    }

    auto Thumbnail(void **ppvObj) -> LxResult
    {
        return m_loc[0]->Thumbnail(m_loc, ppvObj);
    }

    auto Thumbnail(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Thumbnail(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto RawThumbnail(void **ppvObj) -> LxResult
    {
        return m_loc[0]->RawThumbnail(m_loc, ppvObj);
    }

    auto RawThumbnail(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->RawThumbnail(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto InProgressThumbnail(void **ppvObj) -> LxResult
    {
        return m_loc[0]->InProgressThumbnail(m_loc, ppvObj);
    }

    auto InProgressThumbnail(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->InProgressThumbnail(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto ImageProcessing(void **ppvObj) -> LxResult
    {
        return m_loc[0]->ImageProcessing(m_loc, ppvObj);
    }

    auto ImageProcessing(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->ImageProcessing(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto SaveToImage(int saveOp, const char *preferredFormat) -> LxResult
    {
        return m_loc[0]->SaveToImage(m_loc, saveOp, preferredFormat);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_RenderSlotListener
{
public:
    virtual ~CLxImpl_RenderSlotListener() = default;

    virtual auto rendslotevent_SlotListChanged([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto rendslotevent_SlotAdded([[maybe_unused]] ILxUnknownID slot) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto rendslotevent_SlotRemoved([[maybe_unused]] ILxUnknownID slot) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto rendslotevent_RenderSlotInitialized([[maybe_unused]] ILxUnknownID slot) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto rendslotevent_SlotThumbnailUpdated([[maybe_unused]] ILxUnknownID slot) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto rendslotevent_OutputThumbnailUpdated([[maybe_unused]] ILxUnknownID output) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto rendslotevent_SlotLockChanged([[maybe_unused]] ILxUnknownID slot, [[maybe_unused]] int newState) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto rendslotevent_SlotMappingChanged([[maybe_unused]] ILxUnknownID slot, [[maybe_unused]] int newMapping) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto rendslotevent_SlotStatsReset([[maybe_unused]] ILxUnknownID slot) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_RenderSlotListener_SlotListChanged LxResult rendslotevent_SlotListChanged() override
#define LXxO_RenderSlotListener_SlotListChanged LXxD_RenderSlotListener_SlotListChanged
#define LXxC_RenderSlotListener_SlotListChanged(c) LxResult c::rendslotevent_SlotListChanged()
#define LXxD_RenderSlotListener_SlotAdded LxResult rendslotevent_SlotAdded([[maybe_unused]] ILxUnknownID slot) override
#define LXxO_RenderSlotListener_SlotAdded LXxD_RenderSlotListener_SlotAdded
#define LXxC_RenderSlotListener_SlotAdded(c) LxResult c::rendslotevent_SlotAdded([[maybe_unused]] ILxUnknownID slot)
#define LXxD_RenderSlotListener_SlotRemoved LxResult rendslotevent_SlotRemoved([[maybe_unused]] ILxUnknownID slot) override
#define LXxO_RenderSlotListener_SlotRemoved LXxD_RenderSlotListener_SlotRemoved
#define LXxC_RenderSlotListener_SlotRemoved(c) LxResult c::rendslotevent_SlotRemoved([[maybe_unused]] ILxUnknownID slot)
#define LXxD_RenderSlotListener_RenderSlotInitialized LxResult rendslotevent_RenderSlotInitialized([[maybe_unused]] ILxUnknownID slot) override
#define LXxO_RenderSlotListener_RenderSlotInitialized LXxD_RenderSlotListener_RenderSlotInitialized
#define LXxC_RenderSlotListener_RenderSlotInitialized(c) LxResult c::rendslotevent_RenderSlotInitialized([[maybe_unused]] ILxUnknownID slot)
#define LXxD_RenderSlotListener_SlotThumbnailUpdated LxResult rendslotevent_SlotThumbnailUpdated([[maybe_unused]] ILxUnknownID slot) override
#define LXxO_RenderSlotListener_SlotThumbnailUpdated LXxD_RenderSlotListener_SlotThumbnailUpdated
#define LXxC_RenderSlotListener_SlotThumbnailUpdated(c) LxResult c::rendslotevent_SlotThumbnailUpdated([[maybe_unused]] ILxUnknownID slot)
#define LXxD_RenderSlotListener_OutputThumbnailUpdated LxResult rendslotevent_OutputThumbnailUpdated([[maybe_unused]] ILxUnknownID output) override
#define LXxO_RenderSlotListener_OutputThumbnailUpdated LXxD_RenderSlotListener_OutputThumbnailUpdated
#define LXxC_RenderSlotListener_OutputThumbnailUpdated(c) LxResult c::rendslotevent_OutputThumbnailUpdated([[maybe_unused]] ILxUnknownID output)
#define LXxD_RenderSlotListener_SlotLockChanged LxResult rendslotevent_SlotLockChanged([[maybe_unused]] ILxUnknownID slot, [[maybe_unused]] int newState) override
#define LXxO_RenderSlotListener_SlotLockChanged LXxD_RenderSlotListener_SlotLockChanged
#define LXxC_RenderSlotListener_SlotLockChanged(c) LxResult c::rendslotevent_SlotLockChanged([[maybe_unused]] ILxUnknownID slot, [[maybe_unused]] int newState)
#define LXxD_RenderSlotListener_SlotMappingChanged LxResult rendslotevent_SlotMappingChanged([[maybe_unused]] ILxUnknownID slot, [[maybe_unused]] int newMapping) override
#define LXxO_RenderSlotListener_SlotMappingChanged LXxD_RenderSlotListener_SlotMappingChanged
#define LXxC_RenderSlotListener_SlotMappingChanged(c) LxResult c::rendslotevent_SlotMappingChanged([[maybe_unused]] ILxUnknownID slot, [[maybe_unused]] int newMapping)
#define LXxD_RenderSlotListener_SlotStatsReset LxResult rendslotevent_SlotStatsReset([[maybe_unused]] ILxUnknownID slot) override
#define LXxO_RenderSlotListener_SlotStatsReset LXxD_RenderSlotListener_SlotStatsReset
#define LXxC_RenderSlotListener_SlotStatsReset(c) LxResult c::rendslotevent_SlotStatsReset([[maybe_unused]] ILxUnknownID slot)

template <class T>
class CLxIfc_RenderSlotListener: public CLxInterface
{
public:
    CLxIfc_RenderSlotListener()
    {
        vt.SlotListChanged = SlotListChanged;
        vt.SlotAdded = SlotAdded;
        vt.SlotRemoved = SlotRemoved;
        vt.RenderSlotInitialized = RenderSlotInitialized;
        vt.SlotThumbnailUpdated = SlotThumbnailUpdated;
        vt.OutputThumbnailUpdated = OutputThumbnailUpdated;
        vt.SlotLockChanged = SlotLockChanged;
        vt.SlotMappingChanged = SlotMappingChanged;
        vt.SlotStatsReset = SlotStatsReset;
        vTable = &vt.iunk;
        iid = &lx::guid_RenderSlotListener;
    }

    static auto SlotListChanged(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_RenderSlotListener, loc);
        try
        {
           return loc->rendslotevent_SlotListChanged();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SlotAdded(LXtObjectID wcom,LXtObjectID slot) -> LxResult
    {
        LXCWxINST (CLxImpl_RenderSlotListener, loc);
        try
        {
           return loc->rendslotevent_SlotAdded((ILxUnknownID) slot);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SlotRemoved(LXtObjectID wcom,LXtObjectID slot) -> LxResult
    {
        LXCWxINST (CLxImpl_RenderSlotListener, loc);
        try
        {
           return loc->rendslotevent_SlotRemoved((ILxUnknownID) slot);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto RenderSlotInitialized(LXtObjectID wcom,LXtObjectID slot) -> LxResult
    {
        LXCWxINST (CLxImpl_RenderSlotListener, loc);
        try
        {
           return loc->rendslotevent_RenderSlotInitialized((ILxUnknownID) slot);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SlotThumbnailUpdated(LXtObjectID wcom,LXtObjectID slot) -> LxResult
    {
        LXCWxINST (CLxImpl_RenderSlotListener, loc);
        try
        {
           return loc->rendslotevent_SlotThumbnailUpdated((ILxUnknownID) slot);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto OutputThumbnailUpdated(LXtObjectID wcom,LXtObjectID output) -> LxResult
    {
        LXCWxINST (CLxImpl_RenderSlotListener, loc);
        try
        {
           return loc->rendslotevent_OutputThumbnailUpdated((ILxUnknownID) output);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SlotLockChanged(LXtObjectID wcom,LXtObjectID slot,int newState) -> LxResult
    {
        LXCWxINST (CLxImpl_RenderSlotListener, loc);
        try
        {
           return loc->rendslotevent_SlotLockChanged((ILxUnknownID) slot, newState);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SlotMappingChanged(LXtObjectID wcom,LXtObjectID slot,int newMapping) -> LxResult
    {
        LXCWxINST (CLxImpl_RenderSlotListener, loc);
        try
        {
           return loc->rendslotevent_SlotMappingChanged((ILxUnknownID) slot, newMapping);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SlotStatsReset(LXtObjectID wcom,LXtObjectID slot) -> LxResult
    {
        LXCWxINST (CLxImpl_RenderSlotListener, loc);
        try
        {
           return loc->rendslotevent_SlotStatsReset((ILxUnknownID) slot);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxRenderSlotListener vt;
};

class CLxLoc_RenderSlotListener : public CLxLocalize<ILxRenderSlotListenerID>
{
public:
    CLxLoc_RenderSlotListener()
    {
        _init();
    }

    CLxLoc_RenderSlotListener(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_RenderSlotListener(CLxLoc_RenderSlotListener const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_RenderSlotListener;
    }

    auto SlotListChanged(void) -> LxResult
    {
        return m_loc[0]->SlotListChanged(m_loc);
    }

    auto SlotAdded(ILxUnknownID slot) -> LxResult
    {
        return m_loc[0]->SlotAdded(m_loc,(ILxUnknownID) slot);
    }

    auto SlotRemoved(ILxUnknownID slot) -> LxResult
    {
        return m_loc[0]->SlotRemoved(m_loc,(ILxUnknownID) slot);
    }

    auto RenderSlotInitialized(ILxUnknownID slot) -> LxResult
    {
        return m_loc[0]->RenderSlotInitialized(m_loc,(ILxUnknownID) slot);
    }

    auto SlotThumbnailUpdated(ILxUnknownID slot) -> LxResult
    {
        return m_loc[0]->SlotThumbnailUpdated(m_loc,(ILxUnknownID) slot);
    }

    auto OutputThumbnailUpdated(ILxUnknownID output) -> LxResult
    {
        return m_loc[0]->OutputThumbnailUpdated(m_loc,(ILxUnknownID) output);
    }

    auto SlotLockChanged(ILxUnknownID slot, int newState) -> LxResult
    {
        return m_loc[0]->SlotLockChanged(m_loc,(ILxUnknownID) slot, newState);
    }

    auto SlotMappingChanged(ILxUnknownID slot, int newMapping) -> LxResult
    {
        return m_loc[0]->SlotMappingChanged(m_loc,(ILxUnknownID) slot, newMapping);
    }

    auto SlotStatsReset(ILxUnknownID slot) -> LxResult
    {
        return m_loc[0]->SlotStatsReset(m_loc,(ILxUnknownID) slot);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_RenderProgressListener
{
public:
    virtual ~CLxImpl_RenderProgressListener() = default;

    virtual auto rendprogevent_PercentDone([[maybe_unused]] double progressScene, [[maybe_unused]] double progressFrame, [[maybe_unused]] double progressRenderPass) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto rendprogevent_ProgressString([[maybe_unused]] const char *infoString, [[maybe_unused]] const char *userString) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto rendprogevent_ProgressImage([[maybe_unused]] ILxUnknownID img) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto rendprogevent_ProgressImageUpdated([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto rendprogevent_Begin([[maybe_unused]] ILxUnknownID renderSlot, [[maybe_unused]] ILxUnknownID renderStats) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto rendprogevent_End([[maybe_unused]] ILxUnknownID renderSlot, [[maybe_unused]] int wasAborted, [[maybe_unused]] ILxUnknownID finalFrameBuffer, [[maybe_unused]] ILxUnknownID finalStats) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto rendprogevent_FrameBegin([[maybe_unused]] int frame, [[maybe_unused]] int w, [[maybe_unused]] int h) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto rendprogevent_FrameEnd([[maybe_unused]] int frame, [[maybe_unused]] ILxUnknownID stats) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto rendprogevent_RenderPassBegin([[maybe_unused]] int frame, [[maybe_unused]] int renderPassIndex, [[maybe_unused]] const char *renderPassName, [[maybe_unused]] int eye) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto rendprogevent_RenderPassEnd([[maybe_unused]] int frame, [[maybe_unused]] int renderPassIndex, [[maybe_unused]] const char *renderPassName, [[maybe_unused]] int eye, [[maybe_unused]] ILxUnknownID frameBuffer, [[maybe_unused]] ILxUnknownID stats) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto rendprogevent_FramePassBegin([[maybe_unused]] int frame, [[maybe_unused]] int renderPassIndex, [[maybe_unused]] int eye, [[maybe_unused]] int framePassIndex) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto rendprogevent_FramePassEnd([[maybe_unused]] int frame, [[maybe_unused]] int renderPassIndex, [[maybe_unused]] int eye, [[maybe_unused]] int framePassIndex) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto rendprogevent_BucketBegin([[maybe_unused]] int row, [[maybe_unused]] int col) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto rendprogevent_BucketEnd([[maybe_unused]] int row, [[maybe_unused]] int col, [[maybe_unused]] LxResult code) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto rendprogevent_BucketInit([[maybe_unused]] int rows, [[maybe_unused]] int cols, [[maybe_unused]] int width, [[maybe_unused]] int height) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_RenderProgressListener_PercentDone LxResult rendprogevent_PercentDone([[maybe_unused]] double progressScene, [[maybe_unused]] double progressFrame, [[maybe_unused]] double progressRenderPass) override
#define LXxO_RenderProgressListener_PercentDone LXxD_RenderProgressListener_PercentDone
#define LXxC_RenderProgressListener_PercentDone(c) LxResult c::rendprogevent_PercentDone([[maybe_unused]] double progressScene, [[maybe_unused]] double progressFrame, [[maybe_unused]] double progressRenderPass)
#define LXxD_RenderProgressListener_ProgressString LxResult rendprogevent_ProgressString([[maybe_unused]] const char *infoString, [[maybe_unused]] const char *userString) override
#define LXxO_RenderProgressListener_ProgressString LXxD_RenderProgressListener_ProgressString
#define LXxC_RenderProgressListener_ProgressString(c) LxResult c::rendprogevent_ProgressString([[maybe_unused]] const char *infoString, [[maybe_unused]] const char *userString)
#define LXxD_RenderProgressListener_ProgressImage LxResult rendprogevent_ProgressImage([[maybe_unused]] ILxUnknownID img) override
#define LXxO_RenderProgressListener_ProgressImage LXxD_RenderProgressListener_ProgressImage
#define LXxC_RenderProgressListener_ProgressImage(c) LxResult c::rendprogevent_ProgressImage([[maybe_unused]] ILxUnknownID img)
#define LXxD_RenderProgressListener_ProgressImageUpdated LxResult rendprogevent_ProgressImageUpdated() override
#define LXxO_RenderProgressListener_ProgressImageUpdated LXxD_RenderProgressListener_ProgressImageUpdated
#define LXxC_RenderProgressListener_ProgressImageUpdated(c) LxResult c::rendprogevent_ProgressImageUpdated()
#define LXxD_RenderProgressListener_Begin LxResult rendprogevent_Begin([[maybe_unused]] ILxUnknownID renderSlot, [[maybe_unused]] ILxUnknownID renderStats) override
#define LXxO_RenderProgressListener_Begin LXxD_RenderProgressListener_Begin
#define LXxC_RenderProgressListener_Begin(c) LxResult c::rendprogevent_Begin([[maybe_unused]] ILxUnknownID renderSlot, [[maybe_unused]] ILxUnknownID renderStats)
#define LXxD_RenderProgressListener_End LxResult rendprogevent_End([[maybe_unused]] ILxUnknownID renderSlot, [[maybe_unused]] int wasAborted, [[maybe_unused]] ILxUnknownID finalFrameBuffer, [[maybe_unused]] ILxUnknownID finalStats) override
#define LXxO_RenderProgressListener_End LXxD_RenderProgressListener_End
#define LXxC_RenderProgressListener_End(c) LxResult c::rendprogevent_End([[maybe_unused]] ILxUnknownID renderSlot, [[maybe_unused]] int wasAborted, [[maybe_unused]] ILxUnknownID finalFrameBuffer, [[maybe_unused]] ILxUnknownID finalStats)
#define LXxD_RenderProgressListener_FrameBegin LxResult rendprogevent_FrameBegin([[maybe_unused]] int frame, [[maybe_unused]] int w, [[maybe_unused]] int h) override
#define LXxO_RenderProgressListener_FrameBegin LXxD_RenderProgressListener_FrameBegin
#define LXxC_RenderProgressListener_FrameBegin(c) LxResult c::rendprogevent_FrameBegin([[maybe_unused]] int frame, [[maybe_unused]] int w, [[maybe_unused]] int h)
#define LXxD_RenderProgressListener_FrameEnd LxResult rendprogevent_FrameEnd([[maybe_unused]] int frame, [[maybe_unused]] ILxUnknownID stats) override
#define LXxO_RenderProgressListener_FrameEnd LXxD_RenderProgressListener_FrameEnd
#define LXxC_RenderProgressListener_FrameEnd(c) LxResult c::rendprogevent_FrameEnd([[maybe_unused]] int frame, [[maybe_unused]] ILxUnknownID stats)
#define LXxD_RenderProgressListener_RenderPassBegin LxResult rendprogevent_RenderPassBegin([[maybe_unused]] int frame, [[maybe_unused]] int renderPassIndex, [[maybe_unused]] const char *renderPassName, [[maybe_unused]] int eye) override
#define LXxO_RenderProgressListener_RenderPassBegin LXxD_RenderProgressListener_RenderPassBegin
#define LXxC_RenderProgressListener_RenderPassBegin(c) LxResult c::rendprogevent_RenderPassBegin([[maybe_unused]] int frame, [[maybe_unused]] int renderPassIndex, [[maybe_unused]] const char *renderPassName, [[maybe_unused]] int eye)
#define LXxD_RenderProgressListener_RenderPassEnd LxResult rendprogevent_RenderPassEnd([[maybe_unused]] int frame, [[maybe_unused]] int renderPassIndex, [[maybe_unused]] const char *renderPassName, [[maybe_unused]] int eye, [[maybe_unused]] ILxUnknownID frameBuffer, [[maybe_unused]] ILxUnknownID stats) override
#define LXxO_RenderProgressListener_RenderPassEnd LXxD_RenderProgressListener_RenderPassEnd
#define LXxC_RenderProgressListener_RenderPassEnd(c) LxResult c::rendprogevent_RenderPassEnd([[maybe_unused]] int frame, [[maybe_unused]] int renderPassIndex, [[maybe_unused]] const char *renderPassName, [[maybe_unused]] int eye, [[maybe_unused]] ILxUnknownID frameBuffer, [[maybe_unused]] ILxUnknownID stats)
#define LXxD_RenderProgressListener_FramePassBegin LxResult rendprogevent_FramePassBegin([[maybe_unused]] int frame, [[maybe_unused]] int renderPassIndex, [[maybe_unused]] int eye, [[maybe_unused]] int framePassIndex) override
#define LXxO_RenderProgressListener_FramePassBegin LXxD_RenderProgressListener_FramePassBegin
#define LXxC_RenderProgressListener_FramePassBegin(c) LxResult c::rendprogevent_FramePassBegin([[maybe_unused]] int frame, [[maybe_unused]] int renderPassIndex, [[maybe_unused]] int eye, [[maybe_unused]] int framePassIndex)
#define LXxD_RenderProgressListener_FramePassEnd LxResult rendprogevent_FramePassEnd([[maybe_unused]] int frame, [[maybe_unused]] int renderPassIndex, [[maybe_unused]] int eye, [[maybe_unused]] int framePassIndex) override
#define LXxO_RenderProgressListener_FramePassEnd LXxD_RenderProgressListener_FramePassEnd
#define LXxC_RenderProgressListener_FramePassEnd(c) LxResult c::rendprogevent_FramePassEnd([[maybe_unused]] int frame, [[maybe_unused]] int renderPassIndex, [[maybe_unused]] int eye, [[maybe_unused]] int framePassIndex)
#define LXxD_RenderProgressListener_BucketBegin LxResult rendprogevent_BucketBegin([[maybe_unused]] int row, [[maybe_unused]] int col) override
#define LXxO_RenderProgressListener_BucketBegin LXxD_RenderProgressListener_BucketBegin
#define LXxC_RenderProgressListener_BucketBegin(c) LxResult c::rendprogevent_BucketBegin([[maybe_unused]] int row, [[maybe_unused]] int col)
#define LXxD_RenderProgressListener_BucketEnd LxResult rendprogevent_BucketEnd([[maybe_unused]] int row, [[maybe_unused]] int col, [[maybe_unused]] LxResult code) override
#define LXxO_RenderProgressListener_BucketEnd LXxD_RenderProgressListener_BucketEnd
#define LXxC_RenderProgressListener_BucketEnd(c) LxResult c::rendprogevent_BucketEnd([[maybe_unused]] int row, [[maybe_unused]] int col, [[maybe_unused]] LxResult code)
#define LXxD_RenderProgressListener_BucketInit LxResult rendprogevent_BucketInit([[maybe_unused]] int rows, [[maybe_unused]] int cols, [[maybe_unused]] int width, [[maybe_unused]] int height) override
#define LXxO_RenderProgressListener_BucketInit LXxD_RenderProgressListener_BucketInit
#define LXxC_RenderProgressListener_BucketInit(c) LxResult c::rendprogevent_BucketInit([[maybe_unused]] int rows, [[maybe_unused]] int cols, [[maybe_unused]] int width, [[maybe_unused]] int height)

template <class T>
class CLxIfc_RenderProgressListener: public CLxInterface
{
public:
    CLxIfc_RenderProgressListener()
    {
        vt.PercentDone = PercentDone;
        vt.ProgressString = ProgressString;
        vt.ProgressImage = ProgressImage;
        vt.ProgressImageUpdated = ProgressImageUpdated;
        vt.Begin = Begin;
        vt.End = End;
        vt.FrameBegin = FrameBegin;
        vt.FrameEnd = FrameEnd;
        vt.RenderPassBegin = RenderPassBegin;
        vt.RenderPassEnd = RenderPassEnd;
        vt.FramePassBegin = FramePassBegin;
        vt.FramePassEnd = FramePassEnd;
        vt.BucketBegin = BucketBegin;
        vt.BucketEnd = BucketEnd;
        vt.BucketInit = BucketInit;
        vTable = &vt.iunk;
        iid = &lx::guid_RenderProgressListener;
    }

    static auto PercentDone(LXtObjectID wcom,double progressScene,double progressFrame,double progressRenderPass) -> LxResult
    {
        LXCWxINST (CLxImpl_RenderProgressListener, loc);
        try
        {
           return loc->rendprogevent_PercentDone( progressScene, progressFrame, progressRenderPass);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ProgressString(LXtObjectID wcom,const char *infoString,const char *userString) -> LxResult
    {
        LXCWxINST (CLxImpl_RenderProgressListener, loc);
        try
        {
           return loc->rendprogevent_ProgressString( infoString, userString);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ProgressImage(LXtObjectID wcom,LXtObjectID img) -> LxResult
    {
        LXCWxINST (CLxImpl_RenderProgressListener, loc);
        try
        {
           return loc->rendprogevent_ProgressImage((ILxUnknownID) img);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ProgressImageUpdated(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_RenderProgressListener, loc);
        try
        {
           return loc->rendprogevent_ProgressImageUpdated();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Begin(LXtObjectID wcom,LXtObjectID renderSlot,LXtObjectID renderStats) -> LxResult
    {
        LXCWxINST (CLxImpl_RenderProgressListener, loc);
        try
        {
           return loc->rendprogevent_Begin((ILxUnknownID) renderSlot,(ILxUnknownID) renderStats);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto End(LXtObjectID wcom,LXtObjectID renderSlot,int wasAborted,LXtObjectID finalFrameBuffer,LXtObjectID finalStats) -> LxResult
    {
        LXCWxINST (CLxImpl_RenderProgressListener, loc);
        try
        {
           return loc->rendprogevent_End((ILxUnknownID) renderSlot, wasAborted,(ILxUnknownID) finalFrameBuffer,(ILxUnknownID) finalStats);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto FrameBegin(LXtObjectID wcom,int frame,int w,int h) -> LxResult
    {
        LXCWxINST (CLxImpl_RenderProgressListener, loc);
        try
        {
           return loc->rendprogevent_FrameBegin( frame, w, h);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto FrameEnd(LXtObjectID wcom,int frame,LXtObjectID stats) -> LxResult
    {
        LXCWxINST (CLxImpl_RenderProgressListener, loc);
        try
        {
           return loc->rendprogevent_FrameEnd( frame,(ILxUnknownID) stats);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto RenderPassBegin(LXtObjectID wcom,int frame,int renderPassIndex,const char *renderPassName,int eye) -> LxResult
    {
        LXCWxINST (CLxImpl_RenderProgressListener, loc);
        try
        {
           return loc->rendprogevent_RenderPassBegin( frame, renderPassIndex, renderPassName, eye);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto RenderPassEnd(LXtObjectID wcom,int frame,int renderPassIndex,const char *renderPassName,int eye,LXtObjectID frameBuffer,LXtObjectID stats) -> LxResult
    {
        LXCWxINST (CLxImpl_RenderProgressListener, loc);
        try
        {
           return loc->rendprogevent_RenderPassEnd( frame, renderPassIndex, renderPassName, eye,(ILxUnknownID) frameBuffer,(ILxUnknownID) stats);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto FramePassBegin(LXtObjectID wcom,int frame,int renderPassIndex,int eye,int framePassIndex) -> LxResult
    {
        LXCWxINST (CLxImpl_RenderProgressListener, loc);
        try
        {
           return loc->rendprogevent_FramePassBegin( frame, renderPassIndex, eye, framePassIndex);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto FramePassEnd(LXtObjectID wcom,int frame,int renderPassIndex,int eye,int framePassIndex) -> LxResult
    {
        LXCWxINST (CLxImpl_RenderProgressListener, loc);
        try
        {
           return loc->rendprogevent_FramePassEnd( frame, renderPassIndex, eye, framePassIndex);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto BucketBegin(LXtObjectID wcom,int row,int col) -> LxResult
    {
        LXCWxINST (CLxImpl_RenderProgressListener, loc);
        try
        {
           return loc->rendprogevent_BucketBegin( row, col);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto BucketEnd(LXtObjectID wcom,int row,int col,LxResult code) -> LxResult
    {
        LXCWxINST (CLxImpl_RenderProgressListener, loc);
        try
        {
           return loc->rendprogevent_BucketEnd( row, col, code);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto BucketInit(LXtObjectID wcom,int rows,int cols,int width,int height) -> LxResult
    {
        LXCWxINST (CLxImpl_RenderProgressListener, loc);
        try
        {
           return loc->rendprogevent_BucketInit( rows, cols, width, height);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxRenderProgressListener vt;
};

class CLxLoc_RenderProgressListener : public CLxLocalize<ILxRenderProgressListenerID>
{
public:
    CLxLoc_RenderProgressListener()
    {
        _init();
    }

    CLxLoc_RenderProgressListener(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_RenderProgressListener(CLxLoc_RenderProgressListener const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_RenderProgressListener;
    }

    auto PercentDone(double progressScene, double progressFrame, double progressRenderPass) -> LxResult
    {
        return m_loc[0]->PercentDone(m_loc, progressScene, progressFrame, progressRenderPass);
    }

    auto ProgressString(const char *infoString, const char *userString) -> LxResult
    {
        return m_loc[0]->ProgressString(m_loc, infoString, userString);
    }

    auto ProgressImage(ILxUnknownID img) -> LxResult
    {
        return m_loc[0]->ProgressImage(m_loc,(ILxUnknownID) img);
    }

    auto ProgressImageUpdated(void) -> LxResult
    {
        return m_loc[0]->ProgressImageUpdated(m_loc);
    }

    auto Begin(ILxUnknownID renderSlot, ILxUnknownID renderStats) -> LxResult
    {
        return m_loc[0]->Begin(m_loc,(ILxUnknownID) renderSlot,(ILxUnknownID) renderStats);
    }

    auto End(ILxUnknownID renderSlot, int wasAborted, ILxUnknownID finalFrameBuffer, ILxUnknownID finalStats) -> LxResult
    {
        return m_loc[0]->End(m_loc,(ILxUnknownID) renderSlot, wasAborted,(ILxUnknownID) finalFrameBuffer,(ILxUnknownID) finalStats);
    }

    auto FrameBegin(int frame, int w, int h) -> LxResult
    {
        return m_loc[0]->FrameBegin(m_loc, frame, w, h);
    }

    auto FrameEnd(int frame, ILxUnknownID stats) -> LxResult
    {
        return m_loc[0]->FrameEnd(m_loc, frame,(ILxUnknownID) stats);
    }

    auto RenderPassBegin(int frame, int renderPassIndex, const char *renderPassName, int eye) -> LxResult
    {
        return m_loc[0]->RenderPassBegin(m_loc, frame, renderPassIndex, renderPassName, eye);
    }

    auto RenderPassEnd(int frame, int renderPassIndex, const char *renderPassName, int eye, ILxUnknownID frameBuffer, ILxUnknownID stats) -> LxResult
    {
        return m_loc[0]->RenderPassEnd(m_loc, frame, renderPassIndex, renderPassName, eye,(ILxUnknownID) frameBuffer,(ILxUnknownID) stats);
    }

    auto FramePassBegin(int frame, int renderPassIndex, int eye, int framePassIndex) -> LxResult
    {
        return m_loc[0]->FramePassBegin(m_loc, frame, renderPassIndex, eye, framePassIndex);
    }

    auto FramePassEnd(int frame, int renderPassIndex, int eye, int framePassIndex) -> LxResult
    {
        return m_loc[0]->FramePassEnd(m_loc, frame, renderPassIndex, eye, framePassIndex);
    }

    auto BucketBegin(int row, int col) -> LxResult
    {
        return m_loc[0]->BucketBegin(m_loc, row, col);
    }

    auto BucketEnd(int row, int col, LxResult code) -> LxResult
    {
        return m_loc[0]->BucketEnd(m_loc, row, col, code);
    }

    auto BucketInit(int rows, int cols, int width, int height) -> LxResult
    {
        return m_loc[0]->BucketInit(m_loc, rows, cols, width, height);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_RenderProgressPixel
{
public:
    virtual ~CLxImpl_RenderProgressPixel() = default;

    virtual auto rendprogpixel_Raw([[maybe_unused]] int x, [[maybe_unused]] int y, [[maybe_unused]] const LXtFVector rgb) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto rendprogpixel_Corrected([[maybe_unused]] int x, [[maybe_unused]] int y, [[maybe_unused]] const LXtFVector rgb) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto rendprogpixel_OutputRaw([[maybe_unused]] int outputIdx, [[maybe_unused]] int x, [[maybe_unused]] int y, [[maybe_unused]] const LXtFVector rgb) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto rendprogpixel_OutputCorrected([[maybe_unused]] int outputIdx, [[maybe_unused]] int x, [[maybe_unused]] int y, [[maybe_unused]] const LXtFVector rgb) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_RenderProgressPixel_Raw LxResult rendprogpixel_Raw([[maybe_unused]] int x, [[maybe_unused]] int y, [[maybe_unused]] const LXtFVector rgb) override
#define LXxO_RenderProgressPixel_Raw LXxD_RenderProgressPixel_Raw
#define LXxC_RenderProgressPixel_Raw(c) LxResult c::rendprogpixel_Raw([[maybe_unused]] int x, [[maybe_unused]] int y, [[maybe_unused]] const LXtFVector rgb)
#define LXxD_RenderProgressPixel_Corrected LxResult rendprogpixel_Corrected([[maybe_unused]] int x, [[maybe_unused]] int y, [[maybe_unused]] const LXtFVector rgb) override
#define LXxO_RenderProgressPixel_Corrected LXxD_RenderProgressPixel_Corrected
#define LXxC_RenderProgressPixel_Corrected(c) LxResult c::rendprogpixel_Corrected([[maybe_unused]] int x, [[maybe_unused]] int y, [[maybe_unused]] const LXtFVector rgb)
#define LXxD_RenderProgressPixel_OutputRaw LxResult rendprogpixel_OutputRaw([[maybe_unused]] int outputIdx, [[maybe_unused]] int x, [[maybe_unused]] int y, [[maybe_unused]] const LXtFVector rgb) override
#define LXxO_RenderProgressPixel_OutputRaw LXxD_RenderProgressPixel_OutputRaw
#define LXxC_RenderProgressPixel_OutputRaw(c) LxResult c::rendprogpixel_OutputRaw([[maybe_unused]] int outputIdx, [[maybe_unused]] int x, [[maybe_unused]] int y, [[maybe_unused]] const LXtFVector rgb)
#define LXxD_RenderProgressPixel_OutputCorrected LxResult rendprogpixel_OutputCorrected([[maybe_unused]] int outputIdx, [[maybe_unused]] int x, [[maybe_unused]] int y, [[maybe_unused]] const LXtFVector rgb) override
#define LXxO_RenderProgressPixel_OutputCorrected LXxD_RenderProgressPixel_OutputCorrected
#define LXxC_RenderProgressPixel_OutputCorrected(c) LxResult c::rendprogpixel_OutputCorrected([[maybe_unused]] int outputIdx, [[maybe_unused]] int x, [[maybe_unused]] int y, [[maybe_unused]] const LXtFVector rgb)

template <class T>
class CLxIfc_RenderProgressPixel: public CLxInterface
{
public:
    CLxIfc_RenderProgressPixel()
    {
        vt.Raw = Raw;
        vt.Corrected = Corrected;
        vt.OutputRaw = OutputRaw;
        vt.OutputCorrected = OutputCorrected;
        vTable = &vt.iunk;
        iid = &lx::guid_RenderProgressPixel;
    }

    static auto Raw(LXtObjectID wcom,int x,int y,const LXtFVector rgb) -> LxResult
    {
        LXCWxINST (CLxImpl_RenderProgressPixel, loc);
        try
        {
           return loc->rendprogpixel_Raw( x, y, rgb);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Corrected(LXtObjectID wcom,int x,int y,const LXtFVector rgb) -> LxResult
    {
        LXCWxINST (CLxImpl_RenderProgressPixel, loc);
        try
        {
           return loc->rendprogpixel_Corrected( x, y, rgb);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto OutputRaw(LXtObjectID wcom,int outputIdx,int x,int y,const LXtFVector rgb) -> LxResult
    {
        LXCWxINST (CLxImpl_RenderProgressPixel, loc);
        try
        {
           return loc->rendprogpixel_OutputRaw( outputIdx, x, y, rgb);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto OutputCorrected(LXtObjectID wcom,int outputIdx,int x,int y,const LXtFVector rgb) -> LxResult
    {
        LXCWxINST (CLxImpl_RenderProgressPixel, loc);
        try
        {
           return loc->rendprogpixel_OutputCorrected( outputIdx, x, y, rgb);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxRenderProgressPixel vt;
};

class CLxLoc_RenderProgressPixel : public CLxLocalize<ILxRenderProgressPixelID>
{
public:
    CLxLoc_RenderProgressPixel()
    {
        _init();
    }

    CLxLoc_RenderProgressPixel(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_RenderProgressPixel(CLxLoc_RenderProgressPixel const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_RenderProgressPixel;
    }

    auto Raw(int x, int y, const LXtFVector rgb) -> LxResult
    {
        return m_loc[0]->Raw(m_loc, x, y, rgb);
    }

    auto Corrected(int x, int y, const LXtFVector rgb) -> LxResult
    {
        return m_loc[0]->Corrected(m_loc, x, y, rgb);
    }

    auto OutputRaw(int outputIdx, int x, int y, const LXtFVector rgb) -> LxResult
    {
        return m_loc[0]->OutputRaw(m_loc, outputIdx, x, y, rgb);
    }

    auto OutputCorrected(int outputIdx, int x, int y, const LXtFVector rgb) -> LxResult
    {
        return m_loc[0]->OutputCorrected(m_loc, outputIdx, x, y, rgb);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
