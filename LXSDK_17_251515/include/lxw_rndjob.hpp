//
// C++ wrapper for lxsdk/lxrndjob.h.
//
//	Copyright 2024.
//
//
#pragma once

#include <lxrndjob.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx
{
    static LXtGUID const guid_RenderService = {0x8D1710CE, {0x7AF4, 0x46cd}, {0xB6, 0xB1, 0x22, 0x2A, 0x7D, 0xC4, 0xC5, 0x3F}};
    static LXtGUID const guid_RenderJob = {0x97a84077, {0x9ce3, 0x46cc}, {0x96, 0xca, 0xd6, 0xee, 0x6e, 0x3d, 0x01, 0x09}};
    static LXtGUID const guid_RenderJob1 = {0x091C8EB2, {0x5DC1, 0x4d01}, {0xAF, 0x9B, 0x3C, 0x73, 0x5F, 0x2F, 0xFB, 0x1D}};
    static LXtGUID const guid_RenderSystemListener = {0x4c8551af, {0x515b, 0x4983}, {0x9e, 0xdd, 0x70, 0xe3, 0x7a, 0x18, 0x70, 0xd6}};
    static LXtGUID const guid_RenderStats = {0xd7630419, {0xeef3, 0x4725}, {0xa6, 0xcc, 0x1c, 0x8c, 0xe0, 0x9d, 0xbd, 0x6d}};
    static LXtGUID const guid_Buffer = {0x088D0A6B, {0x7A83, 0x4774}, {0xAA, 0x56, 0x47, 0x3F, 0x6C, 0x24, 0x1F, 0x40}};
    static LXtGUID const guid_FrameBuffer = {0x90B060B4, {0x1EC2, 0x45F4}, {0xA6, 0xA8, 0x9A, 0x38, 0x22, 0xB9, 0xB3, 0x9C}};
    static LXtGUID const guid_ImageProcessing = {0x1a89cc09, {0x5326, 0x44d6}, {0x96, 0x05, 0x3b, 0x66, 0xbf, 0x9c, 0x03, 0xf5}};
    static LXtGUID const guid_ImageProcessingListener = {0x4a4ca8b2, {0xdf07, 0x4156}, {0xb1, 0xc3, 0xa5, 0xfc, 0x63, 0x31, 0x8e, 0xa8}};
    static LXtGUID const guid_ImageProcessingRead = {0x154307c9, {0x5fa3, 0x4749}, {0x88, 0x53, 0x08, 0x8e, 0x2c, 0xc1, 0xf5, 0xed}};
    static LXtGUID const guid_ImageProcessingService = {0x2f403a5c, {0xa6aa, 0x4d5a}, {0x88, 0xf6, 0xa2, 0xdf, 0xf2, 0x3d, 0xa5, 0x23}};
} // namespace lx

class CLxLoc_RenderService : public CLxLocalizedService
{
public:
    ILxRenderServiceID m_loc{ nullptr };

public:
    CLxLoc_RenderService()
    {
        _init();
        set();
    }

    ~CLxLoc_RenderService() = default;

    void set()
    {
        if (!m_loc)
        {
            m_loc = reinterpret_cast<ILxRenderServiceID>(lx::GetGlobal(&lx::guid_RenderService));
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

    auto JobSetCurrent(ILxUnknownID job) -> LxResult
    {
        return m_loc[0]->JobSetCurrent(m_loc,(ILxUnknownID) job);
    }

    auto JobCurrent(void **ppvObj) const -> LxResult
    {
        return m_loc[0]->JobCurrent(m_loc, ppvObj);
    }

    auto JobCurrent(CLxLocalizedObject &o_dest) const -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->JobCurrent(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto JobStart(void) -> LxResult
    {
        return m_loc[0]->JobStart(m_loc);
    }

    auto JobAbort(void) -> LxResult
    {
        return m_loc[0]->JobAbort(m_loc);
    }

    auto JobStatus(void) const -> LxResult
    {
        return m_loc[0]->JobStatus(m_loc);
    }

    auto JobStats(void) -> ILxUnknownID
    {
        return (ILxUnknownID)m_loc[0]->JobStats(m_loc);
    }

    auto JobIsSlave(void) const -> int
    {
        return m_loc[0]->JobIsSlave(m_loc);
    }

    auto JobCleanup(int clearJob) -> LxResult
    {
        return m_loc[0]->JobCleanup(m_loc, clearJob);
    }

    auto JobRenderOutputCount(int *count) const -> LxResult
    {
        return m_loc[0]->JobRenderOutputCount(m_loc, count);
    }

    auto JobRenderOutputName(int index, const char **name) const -> LxResult
    {
        return m_loc[0]->JobRenderOutputName(m_loc, index, name);
    }

    auto JobRenderOutputType(int index, int *type) const -> LxResult
    {
        return m_loc[0]->JobRenderOutputType(m_loc, index, type);
    }

    auto UpdateProgressImage(void) -> LxResult
    {
        return m_loc[0]->UpdateProgressImage(m_loc);
    }

    auto RefreshProgressImageMetrics(void) -> LxResult
    {
        return m_loc[0]->RefreshProgressImageMetrics(m_loc);
    }

    auto FrameStore(ILxUnknownID frameBuffer, int writePixels) -> LxResult
    {
        return m_loc[0]->FrameStore(m_loc,(ILxUnknownID) frameBuffer, writePixels);
    }

    auto FrameRecall(int slotIndex, int passIndex, ILxUnknownID monitor, void **ppvObj) -> LxResult
    {
        return m_loc[0]->FrameRecall(m_loc, slotIndex, passIndex,(ILxUnknownID) monitor, ppvObj);
    }

    auto FrameRecall(int slotIndex, int passIndex, ILxUnknownID monitor, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->FrameRecall(m_loc, slotIndex, passIndex,(ILxUnknownID) monitor, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto FrameTestRecall(int slotIndex, int passIndex) -> LxResult
    {
        return m_loc[0]->FrameTestRecall(m_loc, slotIndex, passIndex);
    }

    auto FrameRenderPassCount(int slotIndex, int *numPasses) -> LxResult
    {
        return m_loc[0]->FrameRenderPassCount(m_loc, slotIndex, numPasses);
    }

    auto FrameRenderPassInfo(int slotIndex, int passIndex, char *name, unsigned *width, unsigned *height, unsigned *outputCount, int *isStereo, LXtStereoEye *eyeDisplay, LXtStereoComposite *stereoComposite) -> LxResult
    {
        return m_loc[0]->FrameRenderPassInfo(m_loc, slotIndex, passIndex, name, width, height, outputCount, isStereo, eyeDisplay, stereoComposite);
    }

    auto FrameRenderPassOutputInfo(int slotIndex, int passIndex, char *renderPassName, unsigned *width, unsigned *height, LXtRenderOutputProcessList *outputs) -> LxResult
    {
        return m_loc[0]->FrameRenderPassOutputInfo(m_loc, slotIndex, passIndex, renderPassName, width, height, outputs);
    }

    auto FrameSaveImage(ILxUnknownID framebuffer, int bufferIndex, const char *filename, const char *format, ILxUnknownID message, ILxUnknownID monitor) -> LxResult
    {
        return m_loc[0]->FrameSaveImage(m_loc,(ILxUnknownID) framebuffer, bufferIndex, filename, format,(ILxUnknownID) message,(ILxUnknownID) monitor);
    }

    auto FrameSaveLayered(ILxUnknownID framebuffer, const char *filename, const char *format, ILxUnknownID message, ILxUnknownID monitor) -> LxResult
    {
        return m_loc[0]->FrameSaveLayered(m_loc,(ILxUnknownID) framebuffer, filename, format,(ILxUnknownID) message,(ILxUnknownID) monitor);
    }

    auto FrameSavePassLayered(ILxUnknownID framebuffer, const char *filename, const char *format, ILxUnknownID message, ILxUnknownID monitor) -> LxResult
    {
        return m_loc[0]->FrameSavePassLayered(m_loc,(ILxUnknownID) framebuffer, filename, format,(ILxUnknownID) message,(ILxUnknownID) monitor);
    }

    auto FrameSavePassesAsImages(int slotIndex, const char *filename, const char *format, ILxUnknownID message, ILxUnknownID monitor) -> LxResult
    {
        return m_loc[0]->FrameSavePassesAsImages(m_loc, slotIndex, filename, format,(ILxUnknownID) message,(ILxUnknownID) monitor);
    }

    auto FrameSavePassesAsLayeredImages(int slotIndex, const char *filename, const char *format, ILxUnknownID message, ILxUnknownID monitor) -> LxResult
    {
        return m_loc[0]->FrameSavePassesAsLayeredImages(m_loc, slotIndex, filename, format,(ILxUnknownID) message,(ILxUnknownID) monitor);
    }

    auto FrameStoreStats(int slotIndex, ILxUnknownID stats) -> LxResult
    {
        return m_loc[0]->FrameStoreStats(m_loc, slotIndex,(ILxUnknownID) stats);
    }

    auto FrameRecallStats(int slotIndex, void **ppvObj) -> LxResult
    {
        return m_loc[0]->FrameRecallStats(m_loc, slotIndex, ppvObj);
    }

    auto FrameRecallStats(int slotIndex, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->FrameRecallStats(m_loc, slotIndex, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto FrameStoreThumbnail(int slotIndex, ILxUnknownID image) -> LxResult
    {
        return m_loc[0]->FrameStoreThumbnail(m_loc, slotIndex,(ILxUnknownID) image);
    }

    auto FrameRecallThumbnail(int slotIndex, void **ppvObj) -> LxResult
    {
        return m_loc[0]->FrameRecallThumbnail(m_loc, slotIndex, ppvObj);
    }

    auto FrameRecallThumbnail(int slotIndex, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->FrameRecallThumbnail(m_loc, slotIndex, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto FrameDelete(int slotIndex) -> LxResult
    {
        return m_loc[0]->FrameDelete(m_loc, slotIndex);
    }

    auto RenderEffectFromRenderType(int type, const char** effectName) -> LxResult
    {
        return m_loc[0]->RenderEffectFromRenderType(m_loc, type, effectName);
    }

    auto RenderEffectToType(const char* effect, int* type, int* size) -> LxResult
    {
        return m_loc[0]->RenderEffectToType(m_loc, effect, type, size);
    }

    auto MaxRenderSlots(void) -> int
    {
        return m_loc[0]->MaxRenderSlots(m_loc);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_RenderJob
{
public:
    virtual ~CLxImpl_RenderJob() = default;

    virtual auto rjob_RenderItem([[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto rjob_ActionName([[maybe_unused]] const char **action) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto rjob_GroupName([[maybe_unused]] const char **group) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto rjob_RenderAs([[maybe_unused]] int *mode) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto rjob_RenderAtTime([[maybe_unused]] double *time) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto rjob_RenderTurntableNumFrames([[maybe_unused]] int *numFrames) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto rjob_RenderTurntableFPS([[maybe_unused]] int *fps) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto rjob_RenderBakeVMap([[maybe_unused]] const char **vmap) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto rjob_RenderBakeLookDistance([[maybe_unused]] double *distance) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto rjob_RenderBakeItem([[maybe_unused]] int *include, [[maybe_unused]] void **item) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto rjob_RenderBakeEffect([[maybe_unused]] const char **effect) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto rjob_RenderBakeImage([[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto rjob_TestItem([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] ILxUnknownID eval) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto rjob_FrameBufferSlot([[maybe_unused]] int *index) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto rjob_FrameBufferRegionBackgroundSlot([[maybe_unused]] int *slotIndex, [[maybe_unused]] int *passIndex) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto rjob_OutputFormat([[maybe_unused]] const char **format) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto rjob_OutputFilename([[maybe_unused]] const char **filename) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto rjob_Options([[maybe_unused]] int *options) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto rjob_ProgressAborted([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto rjob_ProgressBegin([[maybe_unused]] ILxUnknownID renderStats) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto rjob_ProgressEnd([[maybe_unused]] ILxUnknownID finalFrameBuffer, [[maybe_unused]] ILxUnknownID finalStats) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto rjob_ProgressPercentDone([[maybe_unused]] double progressScene, [[maybe_unused]] double progressFrame, [[maybe_unused]] double progressRenderPass) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto rjob_ProgressImageMetrics([[maybe_unused]] int resX, [[maybe_unused]] int resH, [[maybe_unused]] int *w, [[maybe_unused]] int *h, [[maybe_unused]] double *zoom, [[maybe_unused]] int *panX, [[maybe_unused]] int *panY, [[maybe_unused]] int *output) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto rjob_ProgressFrameBegin([[maybe_unused]] int frame, [[maybe_unused]] int w, [[maybe_unused]] int h) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto rjob_ProgressFrameEnd([[maybe_unused]] int frame, [[maybe_unused]] ILxUnknownID stats) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto rjob_ProgressRenderPassBegin([[maybe_unused]] int frameIndex, [[maybe_unused]] int renderPassIndex, [[maybe_unused]] const char *renderPassName, [[maybe_unused]] int eye) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto rjob_ProgressRenderPassEnd([[maybe_unused]] int frame, [[maybe_unused]] int renderPassIndex, [[maybe_unused]] const char *renderPassName, [[maybe_unused]] int eye, [[maybe_unused]] ILxUnknownID frameBuffer, [[maybe_unused]] ILxUnknownID stats) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto rjob_ProgressFramePassBegin([[maybe_unused]] int frame, [[maybe_unused]] int renderPass, [[maybe_unused]] int eye, [[maybe_unused]] int pass) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto rjob_ProgressFramePassEnd([[maybe_unused]] int frame, [[maybe_unused]] int renderPass, [[maybe_unused]] int eye, [[maybe_unused]] int pass) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto rjob_ProgressBucketBegin([[maybe_unused]] int row, [[maybe_unused]] int col) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto rjob_ProgressBucketEnd([[maybe_unused]] int row, [[maybe_unused]] int col, [[maybe_unused]] LxResult code) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto rjob_ProgressString([[maybe_unused]] const char *infoString, [[maybe_unused]] const char *userString) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto rjob_ProgressImage([[maybe_unused]] ILxUnknownID img) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto rjob_ProgressImageUpdated([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto rjob_ProgressTickle([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto rjob_RenderBakeCageVMap([[maybe_unused]] const char **vmap) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto rjob_BakeItem([[maybe_unused]] void **item) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto rjob_UDIM([[maybe_unused]] int *udim) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto rjob_RenderBakeToRGBA([[maybe_unused]] int *mode) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto rjob_RenderBakeFromRGBA([[maybe_unused]] int *mode) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_RenderJob_RenderItem LxResult rjob_RenderItem([[maybe_unused]] void **ppvObj) override
#define LXxO_RenderJob_RenderItem LXxD_RenderJob_RenderItem
#define LXxC_RenderJob_RenderItem(c) LxResult c::rjob_RenderItem([[maybe_unused]] void **ppvObj)
#define LXxD_RenderJob_ActionName LxResult rjob_ActionName([[maybe_unused]] const char **action) override
#define LXxO_RenderJob_ActionName LXxD_RenderJob_ActionName
#define LXxC_RenderJob_ActionName(c) LxResult c::rjob_ActionName([[maybe_unused]] const char **action)
#define LXxD_RenderJob_GroupName LxResult rjob_GroupName([[maybe_unused]] const char **group) override
#define LXxO_RenderJob_GroupName LXxD_RenderJob_GroupName
#define LXxC_RenderJob_GroupName(c) LxResult c::rjob_GroupName([[maybe_unused]] const char **group)
#define LXxD_RenderJob_RenderAs LxResult rjob_RenderAs([[maybe_unused]] int *mode) override
#define LXxO_RenderJob_RenderAs LXxD_RenderJob_RenderAs
#define LXxC_RenderJob_RenderAs(c) LxResult c::rjob_RenderAs([[maybe_unused]] int *mode)
#define LXxD_RenderJob_RenderAtTime LxResult rjob_RenderAtTime([[maybe_unused]] double *time) override
#define LXxO_RenderJob_RenderAtTime LXxD_RenderJob_RenderAtTime
#define LXxC_RenderJob_RenderAtTime(c) LxResult c::rjob_RenderAtTime([[maybe_unused]] double *time)
#define LXxD_RenderJob_RenderTurntableNumFrames LxResult rjob_RenderTurntableNumFrames([[maybe_unused]] int *numFrames) override
#define LXxO_RenderJob_RenderTurntableNumFrames LXxD_RenderJob_RenderTurntableNumFrames
#define LXxC_RenderJob_RenderTurntableNumFrames(c) LxResult c::rjob_RenderTurntableNumFrames([[maybe_unused]] int *numFrames)
#define LXxD_RenderJob_RenderTurntableFPS LxResult rjob_RenderTurntableFPS([[maybe_unused]] int *fps) override
#define LXxO_RenderJob_RenderTurntableFPS LXxD_RenderJob_RenderTurntableFPS
#define LXxC_RenderJob_RenderTurntableFPS(c) LxResult c::rjob_RenderTurntableFPS([[maybe_unused]] int *fps)
#define LXxD_RenderJob_RenderBakeVMap LxResult rjob_RenderBakeVMap([[maybe_unused]] const char **vmap) override
#define LXxO_RenderJob_RenderBakeVMap LXxD_RenderJob_RenderBakeVMap
#define LXxC_RenderJob_RenderBakeVMap(c) LxResult c::rjob_RenderBakeVMap([[maybe_unused]] const char **vmap)
#define LXxD_RenderJob_RenderBakeLookDistance LxResult rjob_RenderBakeLookDistance([[maybe_unused]] double *distance) override
#define LXxO_RenderJob_RenderBakeLookDistance LXxD_RenderJob_RenderBakeLookDistance
#define LXxC_RenderJob_RenderBakeLookDistance(c) LxResult c::rjob_RenderBakeLookDistance([[maybe_unused]] double *distance)
#define LXxD_RenderJob_RenderBakeItem LxResult rjob_RenderBakeItem([[maybe_unused]] int *include, [[maybe_unused]] void **item) override
#define LXxO_RenderJob_RenderBakeItem LXxD_RenderJob_RenderBakeItem
#define LXxC_RenderJob_RenderBakeItem(c) LxResult c::rjob_RenderBakeItem([[maybe_unused]] int *include, [[maybe_unused]] void **item)
#define LXxD_RenderJob_RenderBakeEffect LxResult rjob_RenderBakeEffect([[maybe_unused]] const char **effect) override
#define LXxO_RenderJob_RenderBakeEffect LXxD_RenderJob_RenderBakeEffect
#define LXxC_RenderJob_RenderBakeEffect(c) LxResult c::rjob_RenderBakeEffect([[maybe_unused]] const char **effect)
#define LXxD_RenderJob_RenderBakeImage LxResult rjob_RenderBakeImage([[maybe_unused]] void **ppvObj) override
#define LXxO_RenderJob_RenderBakeImage LXxD_RenderJob_RenderBakeImage
#define LXxC_RenderJob_RenderBakeImage(c) LxResult c::rjob_RenderBakeImage([[maybe_unused]] void **ppvObj)
#define LXxD_RenderJob_TestItem LxResult rjob_TestItem([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] ILxUnknownID eval) override
#define LXxO_RenderJob_TestItem LXxD_RenderJob_TestItem
#define LXxC_RenderJob_TestItem(c) LxResult c::rjob_TestItem([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] ILxUnknownID eval)
#define LXxD_RenderJob_FrameBufferSlot LxResult rjob_FrameBufferSlot([[maybe_unused]] int *index) override
#define LXxO_RenderJob_FrameBufferSlot LXxD_RenderJob_FrameBufferSlot
#define LXxC_RenderJob_FrameBufferSlot(c) LxResult c::rjob_FrameBufferSlot([[maybe_unused]] int *index)
#define LXxD_RenderJob_FrameBufferRegionBackgroundSlot LxResult rjob_FrameBufferRegionBackgroundSlot([[maybe_unused]] int *slotIndex, [[maybe_unused]] int *passIndex) override
#define LXxO_RenderJob_FrameBufferRegionBackgroundSlot LXxD_RenderJob_FrameBufferRegionBackgroundSlot
#define LXxC_RenderJob_FrameBufferRegionBackgroundSlot(c) LxResult c::rjob_FrameBufferRegionBackgroundSlot([[maybe_unused]] int *slotIndex, [[maybe_unused]] int *passIndex)
#define LXxD_RenderJob_OutputFormat LxResult rjob_OutputFormat([[maybe_unused]] const char **format) override
#define LXxO_RenderJob_OutputFormat LXxD_RenderJob_OutputFormat
#define LXxC_RenderJob_OutputFormat(c) LxResult c::rjob_OutputFormat([[maybe_unused]] const char **format)
#define LXxD_RenderJob_OutputFilename LxResult rjob_OutputFilename([[maybe_unused]] const char **filename) override
#define LXxO_RenderJob_OutputFilename LXxD_RenderJob_OutputFilename
#define LXxC_RenderJob_OutputFilename(c) LxResult c::rjob_OutputFilename([[maybe_unused]] const char **filename)
#define LXxD_RenderJob_Options LxResult rjob_Options([[maybe_unused]] int *options) override
#define LXxO_RenderJob_Options LXxD_RenderJob_Options
#define LXxC_RenderJob_Options(c) LxResult c::rjob_Options([[maybe_unused]] int *options)
#define LXxD_RenderJob_ProgressAborted LxResult rjob_ProgressAborted() override
#define LXxO_RenderJob_ProgressAborted LXxD_RenderJob_ProgressAborted
#define LXxC_RenderJob_ProgressAborted(c) LxResult c::rjob_ProgressAborted()
#define LXxD_RenderJob_ProgressBegin LxResult rjob_ProgressBegin([[maybe_unused]] ILxUnknownID renderStats) override
#define LXxO_RenderJob_ProgressBegin LXxD_RenderJob_ProgressBegin
#define LXxC_RenderJob_ProgressBegin(c) LxResult c::rjob_ProgressBegin([[maybe_unused]] ILxUnknownID renderStats)
#define LXxD_RenderJob_ProgressEnd LxResult rjob_ProgressEnd([[maybe_unused]] ILxUnknownID finalFrameBuffer, [[maybe_unused]] ILxUnknownID finalStats) override
#define LXxO_RenderJob_ProgressEnd LXxD_RenderJob_ProgressEnd
#define LXxC_RenderJob_ProgressEnd(c) LxResult c::rjob_ProgressEnd([[maybe_unused]] ILxUnknownID finalFrameBuffer, [[maybe_unused]] ILxUnknownID finalStats)
#define LXxD_RenderJob_ProgressPercentDone LxResult rjob_ProgressPercentDone([[maybe_unused]] double progressScene, [[maybe_unused]] double progressFrame, [[maybe_unused]] double progressRenderPass) override
#define LXxO_RenderJob_ProgressPercentDone LXxD_RenderJob_ProgressPercentDone
#define LXxC_RenderJob_ProgressPercentDone(c) LxResult c::rjob_ProgressPercentDone([[maybe_unused]] double progressScene, [[maybe_unused]] double progressFrame, [[maybe_unused]] double progressRenderPass)
#define LXxD_RenderJob_ProgressImageMetrics LxResult rjob_ProgressImageMetrics([[maybe_unused]] int resX, [[maybe_unused]] int resH, [[maybe_unused]] int *w, [[maybe_unused]] int *h, [[maybe_unused]] double *zoom, [[maybe_unused]] int *panX, [[maybe_unused]] int *panY, [[maybe_unused]] int *output) override
#define LXxO_RenderJob_ProgressImageMetrics LXxD_RenderJob_ProgressImageMetrics
#define LXxC_RenderJob_ProgressImageMetrics(c) LxResult c::rjob_ProgressImageMetrics([[maybe_unused]] int resX, [[maybe_unused]] int resH, [[maybe_unused]] int *w, [[maybe_unused]] int *h, [[maybe_unused]] double *zoom, [[maybe_unused]] int *panX, [[maybe_unused]] int *panY, [[maybe_unused]] int *output)
#define LXxD_RenderJob_ProgressFrameBegin LxResult rjob_ProgressFrameBegin([[maybe_unused]] int frame, [[maybe_unused]] int w, [[maybe_unused]] int h) override
#define LXxO_RenderJob_ProgressFrameBegin LXxD_RenderJob_ProgressFrameBegin
#define LXxC_RenderJob_ProgressFrameBegin(c) LxResult c::rjob_ProgressFrameBegin([[maybe_unused]] int frame, [[maybe_unused]] int w, [[maybe_unused]] int h)
#define LXxD_RenderJob_ProgressFrameEnd LxResult rjob_ProgressFrameEnd([[maybe_unused]] int frame, [[maybe_unused]] ILxUnknownID stats) override
#define LXxO_RenderJob_ProgressFrameEnd LXxD_RenderJob_ProgressFrameEnd
#define LXxC_RenderJob_ProgressFrameEnd(c) LxResult c::rjob_ProgressFrameEnd([[maybe_unused]] int frame, [[maybe_unused]] ILxUnknownID stats)
#define LXxD_RenderJob_ProgressRenderPassBegin LxResult rjob_ProgressRenderPassBegin([[maybe_unused]] int frameIndex, [[maybe_unused]] int renderPassIndex, [[maybe_unused]] const char *renderPassName, [[maybe_unused]] int eye) override
#define LXxO_RenderJob_ProgressRenderPassBegin LXxD_RenderJob_ProgressRenderPassBegin
#define LXxC_RenderJob_ProgressRenderPassBegin(c) LxResult c::rjob_ProgressRenderPassBegin([[maybe_unused]] int frameIndex, [[maybe_unused]] int renderPassIndex, [[maybe_unused]] const char *renderPassName, [[maybe_unused]] int eye)
#define LXxD_RenderJob_ProgressRenderPassEnd LxResult rjob_ProgressRenderPassEnd([[maybe_unused]] int frame, [[maybe_unused]] int renderPassIndex, [[maybe_unused]] const char *renderPassName, [[maybe_unused]] int eye, [[maybe_unused]] ILxUnknownID frameBuffer, [[maybe_unused]] ILxUnknownID stats) override
#define LXxO_RenderJob_ProgressRenderPassEnd LXxD_RenderJob_ProgressRenderPassEnd
#define LXxC_RenderJob_ProgressRenderPassEnd(c) LxResult c::rjob_ProgressRenderPassEnd([[maybe_unused]] int frame, [[maybe_unused]] int renderPassIndex, [[maybe_unused]] const char *renderPassName, [[maybe_unused]] int eye, [[maybe_unused]] ILxUnknownID frameBuffer, [[maybe_unused]] ILxUnknownID stats)
#define LXxD_RenderJob_ProgressFramePassBegin LxResult rjob_ProgressFramePassBegin([[maybe_unused]] int frame, [[maybe_unused]] int renderPass, [[maybe_unused]] int eye, [[maybe_unused]] int pass) override
#define LXxO_RenderJob_ProgressFramePassBegin LXxD_RenderJob_ProgressFramePassBegin
#define LXxC_RenderJob_ProgressFramePassBegin(c) LxResult c::rjob_ProgressFramePassBegin([[maybe_unused]] int frame, [[maybe_unused]] int renderPass, [[maybe_unused]] int eye, [[maybe_unused]] int pass)
#define LXxD_RenderJob_ProgressFramePassEnd LxResult rjob_ProgressFramePassEnd([[maybe_unused]] int frame, [[maybe_unused]] int renderPass, [[maybe_unused]] int eye, [[maybe_unused]] int pass) override
#define LXxO_RenderJob_ProgressFramePassEnd LXxD_RenderJob_ProgressFramePassEnd
#define LXxC_RenderJob_ProgressFramePassEnd(c) LxResult c::rjob_ProgressFramePassEnd([[maybe_unused]] int frame, [[maybe_unused]] int renderPass, [[maybe_unused]] int eye, [[maybe_unused]] int pass)
#define LXxD_RenderJob_ProgressBucketBegin LxResult rjob_ProgressBucketBegin([[maybe_unused]] int row, [[maybe_unused]] int col) override
#define LXxO_RenderJob_ProgressBucketBegin LXxD_RenderJob_ProgressBucketBegin
#define LXxC_RenderJob_ProgressBucketBegin(c) LxResult c::rjob_ProgressBucketBegin([[maybe_unused]] int row, [[maybe_unused]] int col)
#define LXxD_RenderJob_ProgressBucketEnd LxResult rjob_ProgressBucketEnd([[maybe_unused]] int row, [[maybe_unused]] int col, [[maybe_unused]] LxResult code) override
#define LXxO_RenderJob_ProgressBucketEnd LXxD_RenderJob_ProgressBucketEnd
#define LXxC_RenderJob_ProgressBucketEnd(c) LxResult c::rjob_ProgressBucketEnd([[maybe_unused]] int row, [[maybe_unused]] int col, [[maybe_unused]] LxResult code)
#define LXxD_RenderJob_ProgressString LxResult rjob_ProgressString([[maybe_unused]] const char *infoString, [[maybe_unused]] const char *userString) override
#define LXxO_RenderJob_ProgressString LXxD_RenderJob_ProgressString
#define LXxC_RenderJob_ProgressString(c) LxResult c::rjob_ProgressString([[maybe_unused]] const char *infoString, [[maybe_unused]] const char *userString)
#define LXxD_RenderJob_ProgressImage LxResult rjob_ProgressImage([[maybe_unused]] ILxUnknownID img) override
#define LXxO_RenderJob_ProgressImage LXxD_RenderJob_ProgressImage
#define LXxC_RenderJob_ProgressImage(c) LxResult c::rjob_ProgressImage([[maybe_unused]] ILxUnknownID img)
#define LXxD_RenderJob_ProgressImageUpdated LxResult rjob_ProgressImageUpdated() override
#define LXxO_RenderJob_ProgressImageUpdated LXxD_RenderJob_ProgressImageUpdated
#define LXxC_RenderJob_ProgressImageUpdated(c) LxResult c::rjob_ProgressImageUpdated()
#define LXxD_RenderJob_ProgressTickle LxResult rjob_ProgressTickle() override
#define LXxO_RenderJob_ProgressTickle LXxD_RenderJob_ProgressTickle
#define LXxC_RenderJob_ProgressTickle(c) LxResult c::rjob_ProgressTickle()
#define LXxD_RenderJob_RenderBakeCageVMap LxResult rjob_RenderBakeCageVMap([[maybe_unused]] const char **vmap) override
#define LXxO_RenderJob_RenderBakeCageVMap LXxD_RenderJob_RenderBakeCageVMap
#define LXxC_RenderJob_RenderBakeCageVMap(c) LxResult c::rjob_RenderBakeCageVMap([[maybe_unused]] const char **vmap)
#define LXxD_RenderJob_BakeItem LxResult rjob_BakeItem([[maybe_unused]] void **item) override
#define LXxO_RenderJob_BakeItem LXxD_RenderJob_BakeItem
#define LXxC_RenderJob_BakeItem(c) LxResult c::rjob_BakeItem([[maybe_unused]] void **item)
#define LXxD_RenderJob_UDIM LxResult rjob_UDIM([[maybe_unused]] int *udim) override
#define LXxO_RenderJob_UDIM LXxD_RenderJob_UDIM
#define LXxC_RenderJob_UDIM(c) LxResult c::rjob_UDIM([[maybe_unused]] int *udim)
#define LXxD_RenderJob_RenderBakeToRGBA LxResult rjob_RenderBakeToRGBA([[maybe_unused]] int *mode) override
#define LXxO_RenderJob_RenderBakeToRGBA LXxD_RenderJob_RenderBakeToRGBA
#define LXxC_RenderJob_RenderBakeToRGBA(c) LxResult c::rjob_RenderBakeToRGBA([[maybe_unused]] int *mode)
#define LXxD_RenderJob_RenderBakeFromRGBA LxResult rjob_RenderBakeFromRGBA([[maybe_unused]] int *mode) override
#define LXxO_RenderJob_RenderBakeFromRGBA LXxD_RenderJob_RenderBakeFromRGBA
#define LXxC_RenderJob_RenderBakeFromRGBA(c) LxResult c::rjob_RenderBakeFromRGBA([[maybe_unused]] int *mode)

template <class T>
class CLxIfc_RenderJob: public CLxInterface
{
public:
    CLxIfc_RenderJob()
    {
        vt.RenderItem = RenderItem;
        vt.ActionName = ActionName;
        vt.GroupName = GroupName;
        vt.RenderAs = RenderAs;
        vt.RenderAtTime = RenderAtTime;
        vt.RenderTurntableNumFrames = RenderTurntableNumFrames;
        vt.RenderTurntableFPS = RenderTurntableFPS;
        vt.RenderBakeVMap = RenderBakeVMap;
        vt.RenderBakeLookDistance = RenderBakeLookDistance;
        vt.RenderBakeItem = RenderBakeItem;
        vt.RenderBakeEffect = RenderBakeEffect;
        vt.RenderBakeImage = RenderBakeImage;
        vt.TestItem = TestItem;
        vt.FrameBufferSlot = FrameBufferSlot;
        vt.FrameBufferRegionBackgroundSlot = FrameBufferRegionBackgroundSlot;
        vt.OutputFormat = OutputFormat;
        vt.OutputFilename = OutputFilename;
        vt.Options = Options;
        vt.ProgressAborted = ProgressAborted;
        vt.ProgressBegin = ProgressBegin;
        vt.ProgressEnd = ProgressEnd;
        vt.ProgressPercentDone = ProgressPercentDone;
        vt.ProgressImageMetrics = ProgressImageMetrics;
        vt.ProgressFrameBegin = ProgressFrameBegin;
        vt.ProgressFrameEnd = ProgressFrameEnd;
        vt.ProgressRenderPassBegin = ProgressRenderPassBegin;
        vt.ProgressRenderPassEnd = ProgressRenderPassEnd;
        vt.ProgressFramePassBegin = ProgressFramePassBegin;
        vt.ProgressFramePassEnd = ProgressFramePassEnd;
        vt.ProgressBucketBegin = ProgressBucketBegin;
        vt.ProgressBucketEnd = ProgressBucketEnd;
        vt.ProgressString = ProgressString;
        vt.ProgressImage = ProgressImage;
        vt.ProgressImageUpdated = ProgressImageUpdated;
        vt.ProgressTickle = ProgressTickle;
        vt.RenderBakeCageVMap = RenderBakeCageVMap;
        vt.BakeItem = BakeItem;
        vt.UDIM = UDIM;
        vt.RenderBakeToRGBA = RenderBakeToRGBA;
        vt.RenderBakeFromRGBA = RenderBakeFromRGBA;
        vTable = &vt.iunk;
        iid = &lx::guid_RenderJob;
    }

    static auto RenderItem(LXtObjectID wcom,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_RenderJob, loc);
        try
        {
           return loc->rjob_RenderItem( ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ActionName(LXtObjectID wcom,const char **action) -> LxResult
    {
        LXCWxINST (CLxImpl_RenderJob, loc);
        try
        {
           return loc->rjob_ActionName( action);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto GroupName(LXtObjectID wcom,const char **group) -> LxResult
    {
        LXCWxINST (CLxImpl_RenderJob, loc);
        try
        {
           return loc->rjob_GroupName( group);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto RenderAs(LXtObjectID wcom,int *mode) -> LxResult
    {
        LXCWxINST (CLxImpl_RenderJob, loc);
        try
        {
           return loc->rjob_RenderAs( mode);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto RenderAtTime(LXtObjectID wcom,double *time) -> LxResult
    {
        LXCWxINST (CLxImpl_RenderJob, loc);
        try
        {
           return loc->rjob_RenderAtTime( time);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto RenderTurntableNumFrames(LXtObjectID wcom,int *numFrames) -> LxResult
    {
        LXCWxINST (CLxImpl_RenderJob, loc);
        try
        {
           return loc->rjob_RenderTurntableNumFrames( numFrames);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto RenderTurntableFPS(LXtObjectID wcom,int *fps) -> LxResult
    {
        LXCWxINST (CLxImpl_RenderJob, loc);
        try
        {
           return loc->rjob_RenderTurntableFPS( fps);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto RenderBakeVMap(LXtObjectID wcom,const char **vmap) -> LxResult
    {
        LXCWxINST (CLxImpl_RenderJob, loc);
        try
        {
           return loc->rjob_RenderBakeVMap( vmap);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto RenderBakeLookDistance(LXtObjectID wcom,double *distance) -> LxResult
    {
        LXCWxINST (CLxImpl_RenderJob, loc);
        try
        {
           return loc->rjob_RenderBakeLookDistance( distance);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto RenderBakeItem(LXtObjectID wcom,int *include,void **item) -> LxResult
    {
        LXCWxINST (CLxImpl_RenderJob, loc);
        try
        {
           return loc->rjob_RenderBakeItem( include, item);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto RenderBakeEffect(LXtObjectID wcom,const char **effect) -> LxResult
    {
        LXCWxINST (CLxImpl_RenderJob, loc);
        try
        {
           return loc->rjob_RenderBakeEffect( effect);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto RenderBakeImage(LXtObjectID wcom,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_RenderJob, loc);
        try
        {
           return loc->rjob_RenderBakeImage( ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto TestItem(LXtObjectID wcom,LXtObjectID item,LXtObjectID eval) -> LxResult
    {
        LXCWxINST (CLxImpl_RenderJob, loc);
        try
        {
           return loc->rjob_TestItem((ILxUnknownID) item,(ILxUnknownID) eval);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto FrameBufferSlot(LXtObjectID wcom,int *index) -> LxResult
    {
        LXCWxINST (CLxImpl_RenderJob, loc);
        try
        {
           return loc->rjob_FrameBufferSlot( index);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto FrameBufferRegionBackgroundSlot(LXtObjectID wcom,int *slotIndex,int *passIndex) -> LxResult
    {
        LXCWxINST (CLxImpl_RenderJob, loc);
        try
        {
           return loc->rjob_FrameBufferRegionBackgroundSlot( slotIndex, passIndex);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto OutputFormat(LXtObjectID wcom,const char **format) -> LxResult
    {
        LXCWxINST (CLxImpl_RenderJob, loc);
        try
        {
           return loc->rjob_OutputFormat( format);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto OutputFilename(LXtObjectID wcom,const char **filename) -> LxResult
    {
        LXCWxINST (CLxImpl_RenderJob, loc);
        try
        {
           return loc->rjob_OutputFilename( filename);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Options(LXtObjectID wcom,int *options) -> LxResult
    {
        LXCWxINST (CLxImpl_RenderJob, loc);
        try
        {
           return loc->rjob_Options( options);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ProgressAborted(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_RenderJob, loc);
        try
        {
           return loc->rjob_ProgressAborted();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ProgressBegin(LXtObjectID wcom,LXtObjectID renderStats) -> LxResult
    {
        LXCWxINST (CLxImpl_RenderJob, loc);
        try
        {
           return loc->rjob_ProgressBegin((ILxUnknownID) renderStats);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ProgressEnd(LXtObjectID wcom,LXtObjectID finalFrameBuffer,LXtObjectID finalStats) -> LxResult
    {
        LXCWxINST (CLxImpl_RenderJob, loc);
        try
        {
           return loc->rjob_ProgressEnd((ILxUnknownID) finalFrameBuffer,(ILxUnknownID) finalStats);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ProgressPercentDone(LXtObjectID wcom,double progressScene,double progressFrame,double progressRenderPass) -> LxResult
    {
        LXCWxINST (CLxImpl_RenderJob, loc);
        try
        {
           return loc->rjob_ProgressPercentDone( progressScene, progressFrame, progressRenderPass);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ProgressImageMetrics(LXtObjectID wcom,int resX,int resH,int *w,int *h,double *zoom,int *panX,int *panY,int *output) -> LxResult
    {
        LXCWxINST (CLxImpl_RenderJob, loc);
        try
        {
           return loc->rjob_ProgressImageMetrics( resX, resH, w, h, zoom, panX, panY, output);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ProgressFrameBegin(LXtObjectID wcom,int frame,int w,int h) -> LxResult
    {
        LXCWxINST (CLxImpl_RenderJob, loc);
        try
        {
           return loc->rjob_ProgressFrameBegin( frame, w, h);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ProgressFrameEnd(LXtObjectID wcom,int frame,LXtObjectID stats) -> LxResult
    {
        LXCWxINST (CLxImpl_RenderJob, loc);
        try
        {
           return loc->rjob_ProgressFrameEnd( frame,(ILxUnknownID) stats);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ProgressRenderPassBegin(LXtObjectID wcom,int frameIndex,int renderPassIndex,const char *renderPassName,int eye) -> LxResult
    {
        LXCWxINST (CLxImpl_RenderJob, loc);
        try
        {
           return loc->rjob_ProgressRenderPassBegin( frameIndex, renderPassIndex, renderPassName, eye);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ProgressRenderPassEnd(LXtObjectID wcom,int frame,int renderPassIndex,const char *renderPassName,int eye,LXtObjectID frameBuffer,LXtObjectID stats) -> LxResult
    {
        LXCWxINST (CLxImpl_RenderJob, loc);
        try
        {
           return loc->rjob_ProgressRenderPassEnd( frame, renderPassIndex, renderPassName, eye,(ILxUnknownID) frameBuffer,(ILxUnknownID) stats);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ProgressFramePassBegin(LXtObjectID wcom,int frame,int renderPass,int eye,int pass) -> LxResult
    {
        LXCWxINST (CLxImpl_RenderJob, loc);
        try
        {
           return loc->rjob_ProgressFramePassBegin( frame, renderPass, eye, pass);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ProgressFramePassEnd(LXtObjectID wcom,int frame,int renderPass,int eye,int pass) -> LxResult
    {
        LXCWxINST (CLxImpl_RenderJob, loc);
        try
        {
           return loc->rjob_ProgressFramePassEnd( frame, renderPass, eye, pass);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ProgressBucketBegin(LXtObjectID wcom,int row,int col) -> LxResult
    {
        LXCWxINST (CLxImpl_RenderJob, loc);
        try
        {
           return loc->rjob_ProgressBucketBegin( row, col);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ProgressBucketEnd(LXtObjectID wcom,int row,int col,LxResult code) -> LxResult
    {
        LXCWxINST (CLxImpl_RenderJob, loc);
        try
        {
           return loc->rjob_ProgressBucketEnd( row, col, code);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ProgressString(LXtObjectID wcom,const char *infoString,const char *userString) -> LxResult
    {
        LXCWxINST (CLxImpl_RenderJob, loc);
        try
        {
           return loc->rjob_ProgressString( infoString, userString);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ProgressImage(LXtObjectID wcom,LXtObjectID img) -> LxResult
    {
        LXCWxINST (CLxImpl_RenderJob, loc);
        try
        {
           return loc->rjob_ProgressImage((ILxUnknownID) img);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ProgressImageUpdated(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_RenderJob, loc);
        try
        {
           return loc->rjob_ProgressImageUpdated();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ProgressTickle(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_RenderJob, loc);
        try
        {
           return loc->rjob_ProgressTickle();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto RenderBakeCageVMap(LXtObjectID wcom,const char **vmap) -> LxResult
    {
        LXCWxINST (CLxImpl_RenderJob, loc);
        try
        {
           return loc->rjob_RenderBakeCageVMap( vmap);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto BakeItem(LXtObjectID wcom,void **item) -> LxResult
    {
        LXCWxINST (CLxImpl_RenderJob, loc);
        try
        {
           return loc->rjob_BakeItem( item);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto UDIM(LXtObjectID wcom,int *udim) -> LxResult
    {
        LXCWxINST (CLxImpl_RenderJob, loc);
        try
        {
           return loc->rjob_UDIM( udim);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto RenderBakeToRGBA(LXtObjectID wcom,int *mode) -> LxResult
    {
        LXCWxINST (CLxImpl_RenderJob, loc);
        try
        {
           return loc->rjob_RenderBakeToRGBA( mode);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto RenderBakeFromRGBA(LXtObjectID wcom,int *mode) -> LxResult
    {
        LXCWxINST (CLxImpl_RenderJob, loc);
        try
        {
           return loc->rjob_RenderBakeFromRGBA( mode);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxRenderJob vt;
};

class CLxLoc_RenderJob : public CLxLocalize<ILxRenderJobID>
{
public:
    CLxLoc_RenderJob()
    {
        _init();
    }

    CLxLoc_RenderJob(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_RenderJob(CLxLoc_RenderJob const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_RenderJob;
    }

    auto RenderItem(void **ppvObj) const -> LxResult
    {
        return m_loc[0]->RenderItem(m_loc, ppvObj);
    }

    auto RenderItem(CLxLocalizedObject &o_dest) const -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->RenderItem(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto ActionName(const char **action) const -> LxResult
    {
        return m_loc[0]->ActionName(m_loc, action);
    }

    auto GroupName(const char **group) const -> LxResult
    {
        return m_loc[0]->GroupName(m_loc, group);
    }

    auto RenderAs(int *mode) const -> LxResult
    {
        return m_loc[0]->RenderAs(m_loc, mode);
    }

    auto RenderAtTime(double *time) const -> LxResult
    {
        return m_loc[0]->RenderAtTime(m_loc, time);
    }

    auto RenderTurntableNumFrames(int *numFrames) const -> LxResult
    {
        return m_loc[0]->RenderTurntableNumFrames(m_loc, numFrames);
    }

    auto RenderTurntableFPS(int *fps) const -> LxResult
    {
        return m_loc[0]->RenderTurntableFPS(m_loc, fps);
    }

    auto RenderBakeVMap(const char **vmap) const -> LxResult
    {
        return m_loc[0]->RenderBakeVMap(m_loc, vmap);
    }

    auto RenderBakeLookDistance(double *distance) const -> LxResult
    {
        return m_loc[0]->RenderBakeLookDistance(m_loc, distance);
    }

    auto RenderBakeItem(int *include, void **item) const -> LxResult
    {
        return m_loc[0]->RenderBakeItem(m_loc, include, item);
    }

    auto RenderBakeEffect(const char **effect) const -> LxResult
    {
        return m_loc[0]->RenderBakeEffect(m_loc, effect);
    }

    auto RenderBakeImage(void **ppvObj) const -> LxResult
    {
        return m_loc[0]->RenderBakeImage(m_loc, ppvObj);
    }

    auto RenderBakeImage(CLxLocalizedObject &o_dest) const -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->RenderBakeImage(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto TestItem(ILxUnknownID item, ILxUnknownID eval) -> LxResult
    {
        return m_loc[0]->TestItem(m_loc,(ILxUnknownID) item,(ILxUnknownID) eval);
    }

    auto FrameBufferSlot(int *index) const -> LxResult
    {
        return m_loc[0]->FrameBufferSlot(m_loc, index);
    }

    auto FrameBufferRegionBackgroundSlot(int *slotIndex, int *passIndex) const -> LxResult
    {
        return m_loc[0]->FrameBufferRegionBackgroundSlot(m_loc, slotIndex, passIndex);
    }

    auto OutputFormat(const char **format) const -> LxResult
    {
        return m_loc[0]->OutputFormat(m_loc, format);
    }

    auto OutputFilename(const char **filename) const -> LxResult
    {
        return m_loc[0]->OutputFilename(m_loc, filename);
    }

    auto Options(int *options) const -> LxResult
    {
        return m_loc[0]->Options(m_loc, options);
    }

    auto ProgressAborted(void) -> LxResult
    {
        return m_loc[0]->ProgressAborted(m_loc);
    }

    auto ProgressBegin(ILxUnknownID renderStats) -> LxResult
    {
        return m_loc[0]->ProgressBegin(m_loc,(ILxUnknownID) renderStats);
    }

    auto ProgressEnd(ILxUnknownID finalFrameBuffer, ILxUnknownID finalStats) -> LxResult
    {
        return m_loc[0]->ProgressEnd(m_loc,(ILxUnknownID) finalFrameBuffer,(ILxUnknownID) finalStats);
    }

    auto ProgressPercentDone(double progressScene, double progressFrame, double progressRenderPass) -> LxResult
    {
        return m_loc[0]->ProgressPercentDone(m_loc, progressScene, progressFrame, progressRenderPass);
    }

    auto ProgressImageMetrics(int resX, int resH, int *w, int *h, double *zoom, int *panX, int *panY, int *output) -> LxResult
    {
        return m_loc[0]->ProgressImageMetrics(m_loc, resX, resH, w, h, zoom, panX, panY, output);
    }

    auto ProgressFrameBegin(int frame, int w, int h) -> LxResult
    {
        return m_loc[0]->ProgressFrameBegin(m_loc, frame, w, h);
    }

    auto ProgressFrameEnd(int frame, ILxUnknownID stats) -> LxResult
    {
        return m_loc[0]->ProgressFrameEnd(m_loc, frame,(ILxUnknownID) stats);
    }

    auto ProgressRenderPassBegin(int frameIndex, int renderPassIndex, const char *renderPassName, int eye) -> LxResult
    {
        return m_loc[0]->ProgressRenderPassBegin(m_loc, frameIndex, renderPassIndex, renderPassName, eye);
    }

    auto ProgressRenderPassEnd(int frame, int renderPassIndex, const char *renderPassName, int eye, ILxUnknownID frameBuffer, ILxUnknownID stats) -> LxResult
    {
        return m_loc[0]->ProgressRenderPassEnd(m_loc, frame, renderPassIndex, renderPassName, eye,(ILxUnknownID) frameBuffer,(ILxUnknownID) stats);
    }

    auto ProgressFramePassBegin(int frame, int renderPass, int eye, int pass) -> LxResult
    {
        return m_loc[0]->ProgressFramePassBegin(m_loc, frame, renderPass, eye, pass);
    }

    auto ProgressFramePassEnd(int frame, int renderPass, int eye, int pass) -> LxResult
    {
        return m_loc[0]->ProgressFramePassEnd(m_loc, frame, renderPass, eye, pass);
    }

    auto ProgressBucketBegin(int row, int col) -> LxResult
    {
        return m_loc[0]->ProgressBucketBegin(m_loc, row, col);
    }

    auto ProgressBucketEnd(int row, int col, LxResult code) -> LxResult
    {
        return m_loc[0]->ProgressBucketEnd(m_loc, row, col, code);
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

    auto ProgressTickle(void) -> LxResult
    {
        return m_loc[0]->ProgressTickle(m_loc);
    }

    auto RenderBakeCageVMap(const char **vmap) const -> LxResult
    {
        return m_loc[0]->RenderBakeCageVMap(m_loc, vmap);
    }

    auto BakeItem(void **item) const -> LxResult
    {
        return m_loc[0]->BakeItem(m_loc, item);
    }

    auto UDIM(int *udim) const -> LxResult
    {
        return m_loc[0]->UDIM(m_loc, udim);
    }

    auto RenderBakeToRGBA(int *mode) -> LxResult
    {
        return m_loc[0]->RenderBakeToRGBA(m_loc, mode);
    }

    auto RenderBakeFromRGBA(int *mode) -> LxResult
    {
        return m_loc[0]->RenderBakeFromRGBA(m_loc, mode);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};

class CLxImpl_RenderSystemListener
{
public:
    virtual ~CLxImpl_RenderSystemListener() = default;

    virtual void rndsys_MaxRenderSlots([[maybe_unused]] int maxSlots)
    {
    }
};

#define LXxD_RenderSystemListener_MaxRenderSlots void rndsys_MaxRenderSlots([[maybe_unused]] int maxSlots) override
#define LXxO_RenderSystemListener_MaxRenderSlots LXxD_RenderSystemListener_MaxRenderSlots
#define LXxC_RenderSystemListener_MaxRenderSlots(c) void c::rndsys_MaxRenderSlots([[maybe_unused]] int maxSlots)

template <class T>
class CLxIfc_RenderSystemListener: public CLxInterface
{
public:
    CLxIfc_RenderSystemListener()
    {
        vt.MaxRenderSlots = MaxRenderSlots;
        vTable = &vt.iunk;
        iid = &lx::guid_RenderSystemListener;
    }

    static auto MaxRenderSlots(LXtObjectID wcom,int maxSlots) -> void
    {
        LXCWxINST (CLxImpl_RenderSystemListener, loc);
        loc->rndsys_MaxRenderSlots( maxSlots);
    }

private:
    ILxRenderSystemListener vt;
};

class CLxLoc_RenderSystemListener : public CLxLocalize<ILxRenderSystemListenerID>
{
public:
    CLxLoc_RenderSystemListener()
    {
        _init();
    }

    CLxLoc_RenderSystemListener(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_RenderSystemListener(CLxLoc_RenderSystemListener const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_RenderSystemListener;
    }

    auto MaxRenderSlots(int maxSlots) -> void
    {
        m_loc[0]->MaxRenderSlots(m_loc, maxSlots);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_RenderStats : public CLxLocalize<ILxRenderStatsID>
{
public:
    CLxLoc_RenderStats()
    {
        _init();
    }

    CLxLoc_RenderStats(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_RenderStats(CLxLoc_RenderStats const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_RenderStats;
    }

    auto NumFrames(int *count) -> LxResult
    {
        return m_loc[0]->NumFrames(m_loc, count);
    }

    auto NumPasses(int frameIndex, int *count) -> LxResult
    {
        return m_loc[0]->NumPasses(m_loc, frameIndex, count);
    }

    auto GetPassStats(int frameIndex, int passIndex, void **ppvObj) -> LxResult
    {
        return m_loc[0]->GetPassStats(m_loc, frameIndex, passIndex, ppvObj);
    }

    auto GetPassStats(int frameIndex, int passIndex, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->GetPassStats(m_loc, frameIndex, passIndex, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto GetFrameStats(int frameIndex, void **ppvObj) -> LxResult
    {
        return m_loc[0]->GetFrameStats(m_loc, frameIndex, ppvObj);
    }

    auto GetFrameStats(int frameIndex, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->GetFrameStats(m_loc, frameIndex, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto GetSceneStats(void **ppvObj) -> LxResult
    {
        return m_loc[0]->GetSceneStats(m_loc, ppvObj);
    }

    auto GetSceneStats(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->GetSceneStats(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_Buffer
{
public:
    virtual ~CLxImpl_Buffer() = default;

    virtual void buff_SetFlags([[maybe_unused]] int flags)
    {
    }

    virtual int buff_Flags(void) = 0;

    virtual unsigned buff_DataType(void) = 0;

    virtual LXtObjectID buff_VectorType(void) = 0;

    virtual void buff_SetSize([[maybe_unused]] int width, [[maybe_unused]] int height, [[maybe_unused]] int writeBucketsToDisk, [[maybe_unused]] int isStereo)
    {
    }

    virtual void buff_GetSize([[maybe_unused]] int *width, [[maybe_unused]] int *height)
    {
    }

    virtual auto buff_SetEyeSide([[maybe_unused]] int eyeSide) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual void buff_Clear([[maybe_unused]] int x, [[maybe_unused]] int y)
    {
    }

    virtual auto buff_Convert([[maybe_unused]] LXtGenVectorID gv, [[maybe_unused]] int x, [[maybe_unused]] int y, [[maybe_unused]] float blend) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual void * buff_Pixel(int x, int y) = 0;

    virtual void * buff_Line(int y) = 0;

    virtual auto buff_Name([[maybe_unused]] const char **name) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto buff_SetUserName([[maybe_unused]] const char *name) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto buff_UserName([[maybe_unused]] const char **name) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto buff_CreateImageTileTree([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto buff_DestroyImageTileTree([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual LXtTileTreeID buff_GetImageTileTree(void) = 0;

    virtual size_t buff_GetImageTileTreeSize(void) = 0;

    virtual auto buff_ResetImageTileTree([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto buff_IncrementTileTreeSize([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto buff_DecrementTileTreeSize([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_Buffer_SetFlags void buff_SetFlags([[maybe_unused]] int flags) override
#define LXxO_Buffer_SetFlags LXxD_Buffer_SetFlags
#define LXxC_Buffer_SetFlags(c) void c::buff_SetFlags([[maybe_unused]] int flags)
#define LXxD_Buffer_Flags int buff_Flags() override
#define LXxO_Buffer_Flags LXxD_Buffer_Flags
#define LXxC_Buffer_Flags(c) int c::buff_Flags()
#define LXxD_Buffer_DataType unsigned buff_DataType() override
#define LXxO_Buffer_DataType LXxD_Buffer_DataType
#define LXxC_Buffer_DataType(c) unsigned c::buff_DataType()
#define LXxD_Buffer_VectorType LXtObjectID buff_VectorType() override
#define LXxO_Buffer_VectorType LXxD_Buffer_VectorType
#define LXxC_Buffer_VectorType(c) LXtObjectID c::buff_VectorType()
#define LXxD_Buffer_SetSize void buff_SetSize([[maybe_unused]] int width, [[maybe_unused]] int height, [[maybe_unused]] int writeBucketsToDisk, [[maybe_unused]] int isStereo) override
#define LXxO_Buffer_SetSize LXxD_Buffer_SetSize
#define LXxC_Buffer_SetSize(c) void c::buff_SetSize([[maybe_unused]] int width, [[maybe_unused]] int height, [[maybe_unused]] int writeBucketsToDisk, [[maybe_unused]] int isStereo)
#define LXxD_Buffer_GetSize void buff_GetSize([[maybe_unused]] int *width, [[maybe_unused]] int *height) override
#define LXxO_Buffer_GetSize LXxD_Buffer_GetSize
#define LXxC_Buffer_GetSize(c) void c::buff_GetSize([[maybe_unused]] int *width, [[maybe_unused]] int *height)
#define LXxD_Buffer_SetEyeSide LxResult buff_SetEyeSide([[maybe_unused]] int eyeSide) override
#define LXxO_Buffer_SetEyeSide LXxD_Buffer_SetEyeSide
#define LXxC_Buffer_SetEyeSide(c) LxResult c::buff_SetEyeSide([[maybe_unused]] int eyeSide)
#define LXxD_Buffer_Clear void buff_Clear([[maybe_unused]] int x, [[maybe_unused]] int y) override
#define LXxO_Buffer_Clear LXxD_Buffer_Clear
#define LXxC_Buffer_Clear(c) void c::buff_Clear([[maybe_unused]] int x, [[maybe_unused]] int y)
#define LXxD_Buffer_Convert LxResult buff_Convert([[maybe_unused]] LXtGenVectorID gv, [[maybe_unused]] int x, [[maybe_unused]] int y, [[maybe_unused]] float blend) override
#define LXxO_Buffer_Convert LXxD_Buffer_Convert
#define LXxC_Buffer_Convert(c) LxResult c::buff_Convert([[maybe_unused]] LXtGenVectorID gv, [[maybe_unused]] int x, [[maybe_unused]] int y, [[maybe_unused]] float blend)
#define LXxD_Buffer_Pixel void * buff_Pixel([[maybe_unused]] int x, [[maybe_unused]] int y) override
#define LXxO_Buffer_Pixel LXxD_Buffer_Pixel
#define LXxC_Buffer_Pixel(c) void * c::buff_Pixel([[maybe_unused]] int x, [[maybe_unused]] int y)
#define LXxD_Buffer_Line void * buff_Line([[maybe_unused]] int y) override
#define LXxO_Buffer_Line LXxD_Buffer_Line
#define LXxC_Buffer_Line(c) void * c::buff_Line([[maybe_unused]] int y)
#define LXxD_Buffer_Name LxResult buff_Name([[maybe_unused]] const char **name) override
#define LXxO_Buffer_Name LXxD_Buffer_Name
#define LXxC_Buffer_Name(c) LxResult c::buff_Name([[maybe_unused]] const char **name)
#define LXxD_Buffer_SetUserName LxResult buff_SetUserName([[maybe_unused]] const char *name) override
#define LXxO_Buffer_SetUserName LXxD_Buffer_SetUserName
#define LXxC_Buffer_SetUserName(c) LxResult c::buff_SetUserName([[maybe_unused]] const char *name)
#define LXxD_Buffer_UserName LxResult buff_UserName([[maybe_unused]] const char **name) override
#define LXxO_Buffer_UserName LXxD_Buffer_UserName
#define LXxC_Buffer_UserName(c) LxResult c::buff_UserName([[maybe_unused]] const char **name)
#define LXxD_Buffer_CreateImageTileTree LxResult buff_CreateImageTileTree() override
#define LXxO_Buffer_CreateImageTileTree LXxD_Buffer_CreateImageTileTree
#define LXxC_Buffer_CreateImageTileTree(c) LxResult c::buff_CreateImageTileTree()
#define LXxD_Buffer_DestroyImageTileTree LxResult buff_DestroyImageTileTree() override
#define LXxO_Buffer_DestroyImageTileTree LXxD_Buffer_DestroyImageTileTree
#define LXxC_Buffer_DestroyImageTileTree(c) LxResult c::buff_DestroyImageTileTree()
#define LXxD_Buffer_GetImageTileTree LXtTileTreeID buff_GetImageTileTree() override
#define LXxO_Buffer_GetImageTileTree LXxD_Buffer_GetImageTileTree
#define LXxC_Buffer_GetImageTileTree(c) LXtTileTreeID c::buff_GetImageTileTree()
#define LXxD_Buffer_GetImageTileTreeSize size_t buff_GetImageTileTreeSize() override
#define LXxO_Buffer_GetImageTileTreeSize LXxD_Buffer_GetImageTileTreeSize
#define LXxC_Buffer_GetImageTileTreeSize(c) size_t c::buff_GetImageTileTreeSize()
#define LXxD_Buffer_ResetImageTileTree LxResult buff_ResetImageTileTree() override
#define LXxO_Buffer_ResetImageTileTree LXxD_Buffer_ResetImageTileTree
#define LXxC_Buffer_ResetImageTileTree(c) LxResult c::buff_ResetImageTileTree()
#define LXxD_Buffer_IncrementTileTreeSize LxResult buff_IncrementTileTreeSize() override
#define LXxO_Buffer_IncrementTileTreeSize LXxD_Buffer_IncrementTileTreeSize
#define LXxC_Buffer_IncrementTileTreeSize(c) LxResult c::buff_IncrementTileTreeSize()
#define LXxD_Buffer_DecrementTileTreeSize LxResult buff_DecrementTileTreeSize() override
#define LXxO_Buffer_DecrementTileTreeSize LXxD_Buffer_DecrementTileTreeSize
#define LXxC_Buffer_DecrementTileTreeSize(c) LxResult c::buff_DecrementTileTreeSize()

template <class T>
class CLxIfc_Buffer: public CLxInterface
{
public:
    CLxIfc_Buffer()
    {
        vt.SetFlags = SetFlags;
        vt.Flags = Flags;
        vt.DataType = DataType;
        vt.VectorType = VectorType;
        vt.SetSize = SetSize;
        vt.GetSize = GetSize;
        vt.SetEyeSide = SetEyeSide;
        vt.Clear = Clear;
        vt.Convert = Convert;
        vt.Pixel = Pixel;
        vt.Line = Line;
        vt.Name = Name;
        vt.SetUserName = SetUserName;
        vt.UserName = UserName;
        vt.CreateImageTileTree = CreateImageTileTree;
        vt.DestroyImageTileTree = DestroyImageTileTree;
        vt.GetImageTileTree = GetImageTileTree;
        vt.GetImageTileTreeSize = GetImageTileTreeSize;
        vt.ResetImageTileTree = ResetImageTileTree;
        vt.IncrementTileTreeSize = IncrementTileTreeSize;
        vt.DecrementTileTreeSize = DecrementTileTreeSize;
        vTable = &vt.iunk;
        iid = &lx::guid_Buffer;
    }

    static auto SetFlags(LXtObjectID wcom,int flags) -> void
    {
        LXCWxINST (CLxImpl_Buffer, loc);
        loc->buff_SetFlags( flags);
    }

    static auto Flags(LXtObjectID wcom) -> int
    {
        LXCWxINST (CLxImpl_Buffer, loc);
        return loc->buff_Flags();
    }

    static auto DataType(LXtObjectID wcom) -> unsigned
    {
        LXCWxINST (CLxImpl_Buffer, loc);
        return loc->buff_DataType();
    }

    static auto VectorType(LXtObjectID wcom) -> LXtObjectID
    {
        LXCWxINST (CLxImpl_Buffer, loc);
        return loc->buff_VectorType();
    }

    static auto SetSize(LXtObjectID wcom,int width,int height,int writeBucketsToDisk,int isStereo) -> void
    {
        LXCWxINST (CLxImpl_Buffer, loc);
        loc->buff_SetSize( width, height, writeBucketsToDisk, isStereo);
    }

    static auto GetSize(LXtObjectID wcom,int *width,int *height) -> void
    {
        LXCWxINST (CLxImpl_Buffer, loc);
        loc->buff_GetSize( width, height);
    }

    static auto SetEyeSide(LXtObjectID wcom,int eyeSide) -> LxResult
    {
        LXCWxINST (CLxImpl_Buffer, loc);
        try
        {
           return loc->buff_SetEyeSide( eyeSide);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Clear(LXtObjectID wcom,int x,int y) -> void
    {
        LXCWxINST (CLxImpl_Buffer, loc);
        loc->buff_Clear( x, y);
    }

    static auto Convert(LXtObjectID wcom,LXtGenVectorID gv,int x,int y,float blend) -> LxResult
    {
        LXCWxINST (CLxImpl_Buffer, loc);
        try
        {
           return loc->buff_Convert( gv, x, y, blend);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Pixel(LXtObjectID wcom,int x,int y) -> void *
    {
        LXCWxINST (CLxImpl_Buffer, loc);
        return loc->buff_Pixel( x, y);
    }

    static auto Line(LXtObjectID wcom,int y) -> void *
    {
        LXCWxINST (CLxImpl_Buffer, loc);
        return loc->buff_Line( y);
    }

    static auto Name(LXtObjectID wcom,const char **name) -> LxResult
    {
        LXCWxINST (CLxImpl_Buffer, loc);
        try
        {
           return loc->buff_Name( name);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SetUserName(LXtObjectID wcom,const char *name) -> LxResult
    {
        LXCWxINST (CLxImpl_Buffer, loc);
        try
        {
           return loc->buff_SetUserName( name);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto UserName(LXtObjectID wcom,const char **name) -> LxResult
    {
        LXCWxINST (CLxImpl_Buffer, loc);
        try
        {
           return loc->buff_UserName( name);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto CreateImageTileTree(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_Buffer, loc);
        try
        {
           return loc->buff_CreateImageTileTree();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto DestroyImageTileTree(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_Buffer, loc);
        try
        {
           return loc->buff_DestroyImageTileTree();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto GetImageTileTree(LXtObjectID wcom) -> LXtTileTreeID
    {
        LXCWxINST (CLxImpl_Buffer, loc);
        return loc->buff_GetImageTileTree();
    }

    static auto GetImageTileTreeSize(LXtObjectID wcom) -> size_t
    {
        LXCWxINST (CLxImpl_Buffer, loc);
        return loc->buff_GetImageTileTreeSize();
    }

    static auto ResetImageTileTree(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_Buffer, loc);
        try
        {
           return loc->buff_ResetImageTileTree();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto IncrementTileTreeSize(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_Buffer, loc);
        try
        {
           return loc->buff_IncrementTileTreeSize();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto DecrementTileTreeSize(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_Buffer, loc);
        try
        {
           return loc->buff_DecrementTileTreeSize();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxBuffer vt;
};

class CLxLoc_Buffer : public CLxLocalize<ILxBufferID>
{
public:
    CLxLoc_Buffer()
    {
        _init();
    }

    CLxLoc_Buffer(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_Buffer(CLxLoc_Buffer const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_Buffer;
    }

    auto SetFlags(int flags) -> void
    {
        m_loc[0]->SetFlags(m_loc, flags);
    }

    auto Flags(void) const -> int
    {
        return m_loc[0]->Flags(m_loc);
    }

    auto DataType(void) const -> unsigned
    {
        return m_loc[0]->DataType(m_loc);
    }

    auto VectorType(void) const -> ILxUnknownID
    {
        return (ILxUnknownID)m_loc[0]->VectorType(m_loc);
    }

    auto SetSize(int width, int height, int writeBucketsToDisk, int isStereo) -> void
    {
        m_loc[0]->SetSize(m_loc, width, height, writeBucketsToDisk, isStereo);
    }

    auto GetSize(int *width, int *height) const -> void
    {
        m_loc[0]->GetSize(m_loc, width, height);
    }

    auto SetEyeSide(int eyeSide) -> LxResult
    {
        return m_loc[0]->SetEyeSide(m_loc, eyeSide);
    }

    auto Clear(int x, int y) -> void
    {
        m_loc[0]->Clear(m_loc, x, y);
    }

    auto Convert(LXtGenVectorID gv, int x, int y, float blend) -> LxResult
    {
        return m_loc[0]->Convert(m_loc, gv, x, y, blend);
    }

    auto Pixel(int x, int y) const -> void *
    {
        return m_loc[0]->Pixel(m_loc, x, y);
    }

    auto Line(int y) const -> void *
    {
        return m_loc[0]->Line(m_loc, y);
    }

    auto Name(const char **name) const -> LxResult
    {
        return m_loc[0]->Name(m_loc, name);
    }

    auto SetUserName(const char *name) -> LxResult
    {
        return m_loc[0]->SetUserName(m_loc, name);
    }

    auto UserName(const char **name) const -> LxResult
    {
        return m_loc[0]->UserName(m_loc, name);
    }

    auto CreateImageTileTree(void) -> LxResult
    {
        return m_loc[0]->CreateImageTileTree(m_loc);
    }

    auto DestroyImageTileTree(void) -> LxResult
    {
        return m_loc[0]->DestroyImageTileTree(m_loc);
    }

    auto GetImageTileTree(void) const -> LXtTileTreeID
    {
        return m_loc[0]->GetImageTileTree(m_loc);
    }

    auto GetImageTileTreeSize(void) const -> size_t
    {
        return m_loc[0]->GetImageTileTreeSize(m_loc);
    }

    auto ResetImageTileTree(void) -> LxResult
    {
        return m_loc[0]->ResetImageTileTree(m_loc);
    }

    auto IncrementTileTreeSize(void) -> LxResult
    {
        return m_loc[0]->IncrementTileTreeSize(m_loc);
    }

    auto DecrementTileTreeSize(void) -> LxResult
    {
        return m_loc[0]->DecrementTileTreeSize(m_loc);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_FrameBuffer
{
public:
    virtual ~CLxImpl_FrameBuffer() = default;

    virtual ILxBufferID fbuf_Allocate(const char *name, ILxUnknownID item, const char *identity, const char *userName, int isFactoryName, int writeBucketsToDisk) = 0;

    virtual auto fbuf_IsStereo([[maybe_unused]] int *isStereo) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto fbuf_GetStereoEyeDisplay([[maybe_unused]] LXtStereoEye *eyeDisplay) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto fbuf_SetStereoEyeDisplay([[maybe_unused]] LXtStereoEye eyeDisplay) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto fbuf_GetStereoComposite([[maybe_unused]] LXtStereoComposite *composite) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto fbuf_SetStereoComposite([[maybe_unused]] LXtStereoComposite composite) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto fbuf_SetEyeSide([[maybe_unused]] int eyeSide) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto fbuf_GetLineBuffer([[maybe_unused]] float **buf) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto fbuf_CreateFrameBufferTargetImage([[maybe_unused]] LXtPixelFormat type, [[maybe_unused]] int w, [[maybe_unused]] int h, [[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto fbuf_GetRenderPassName([[maybe_unused]] char *name) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto fbuf_SetRenderPassName([[maybe_unused]] const char *name) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual unsigned int fbuf_BucketsOnDisk(int index) = 0;

    virtual LXtObjectID fbuf_Lookup(const char *name, ILxUnknownID item) = 0;

    virtual LXtObjectID fbuf_LookupByIdentity(const char *identity) = 0;

    virtual unsigned int fbuf_Count(void) = 0;

    virtual LXtObjectID fbuf_ByIndex(int index) = 0;

    virtual LXtObjectID fbuf_Alpha(int index) = 0;

    virtual int fbuf_AlphaIndex(int index) = 0;

    virtual auto fbuf_Size([[maybe_unused]] int index, [[maybe_unused]] int *width, [[maybe_unused]] int *height) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto fbuf_AreaProcessingActive([[maybe_unused]] int bufferIndex, [[maybe_unused]] int *active) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual int fbuf_GetSaveProcessed(int bufferIndex) = 0;

    virtual auto fbuf_SetSaveProcessed([[maybe_unused]] int bufferIndex, [[maybe_unused]] int enabled) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual int fbuf_GetBloomEnabled(int bufferIndex) = 0;

    virtual auto fbuf_SetBloomEnabled([[maybe_unused]] int bufferIndex, [[maybe_unused]] int enabled) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual double fbuf_GetBloomThreshold(int bufferIndex) = 0;

    virtual auto fbuf_SetBloomThreshold([[maybe_unused]] int bufferIndex, [[maybe_unused]] double threshold) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual double fbuf_GetBloomRadius(int bufferIndex) = 0;

    virtual auto fbuf_SetBloomRadius([[maybe_unused]] int bufferIndex, [[maybe_unused]] double radius) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual double fbuf_GetVignetteAmount(int bufferIndex) = 0;

    virtual auto fbuf_SetVignetteAmount([[maybe_unused]] int bufferIndex, [[maybe_unused]] double radius) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual double fbuf_GetInputBlackLevel(int bufferIndex) = 0;

    virtual auto fbuf_SetInputBlackLevel([[maybe_unused]] int bufferIndex, [[maybe_unused]] double blackLevel) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual double fbuf_GetInputGrayLevel(int bufferIndex) = 0;

    virtual double fbuf_GetInvInputGrayLevel(int bufferIndex) = 0;

    virtual auto fbuf_SetInputGrayLevel([[maybe_unused]] int bufferIndex, [[maybe_unused]] double gamma) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual double fbuf_GetInputWhiteLevel(int bufferIndex) = 0;

    virtual auto fbuf_SetInputWhiteLevel([[maybe_unused]] int bufferIndex, [[maybe_unused]] double whiteLevel) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual double fbuf_GetInputMinRedLevel(int bufferIndex) = 0;

    virtual auto fbuf_SetInputMinRedLevel([[maybe_unused]] int bufferIndex, [[maybe_unused]] double level) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual double fbuf_GetInputRedGrayLevel(int bufferIndex) = 0;

    virtual double fbuf_GetInvInputRedGrayLevel(int bufferIndex) = 0;

    virtual auto fbuf_SetInputRedGrayLevel([[maybe_unused]] int bufferIndex, [[maybe_unused]] double gamma) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual double fbuf_GetInputMaxRedLevel(int bufferIndex) = 0;

    virtual auto fbuf_SetInputMaxRedLevel([[maybe_unused]] int bufferIndex, [[maybe_unused]] double level) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual double fbuf_GetInputMinGreenLevel(int bufferIndex) = 0;

    virtual auto fbuf_SetInputMinGreenLevel([[maybe_unused]] int bufferIndex, [[maybe_unused]] double level) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual double fbuf_GetInputGreenGrayLevel(int bufferIndex) = 0;

    virtual double fbuf_GetInvInputGreenGrayLevel(int bufferIndex) = 0;

    virtual auto fbuf_SetInputGreenGrayLevel([[maybe_unused]] int bufferIndex, [[maybe_unused]] double gamma) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual double fbuf_GetInputMaxGreenLevel(int bufferIndex) = 0;

    virtual auto fbuf_SetInputMaxGreenLevel([[maybe_unused]] int bufferIndex, [[maybe_unused]] double level) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual double fbuf_GetInputMinBlueLevel(int bufferIndex) = 0;

    virtual auto fbuf_SetInputMinBlueLevel([[maybe_unused]] int bufferIndex, [[maybe_unused]] double level) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual double fbuf_GetInputBlueGrayLevel(int bufferIndex) = 0;

    virtual double fbuf_GetInvInputBlueGrayLevel(int bufferIndex) = 0;

    virtual auto fbuf_SetInputBlueGrayLevel([[maybe_unused]] int bufferIndex, [[maybe_unused]] double gamma) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual double fbuf_GetInputMaxBlueLevel(int bufferIndex) = 0;

    virtual auto fbuf_SetInputMaxBlueLevel([[maybe_unused]] int bufferIndex, [[maybe_unused]] double level) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual int fbuf_GetExpType(int bufferIndex) = 0;

    virtual auto fbuf_SetExpType([[maybe_unused]] int bufferIndex, [[maybe_unused]] int expType) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual double fbuf_GetISO(int bufferIndex) = 0;

    virtual auto fbuf_SetISO([[maybe_unused]] int bufferIndex, [[maybe_unused]] double iso) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual int fbuf_GetToneMap(int bufferIndex) = 0;

    virtual auto fbuf_SetToneMap([[maybe_unused]] int bufferIndex, [[maybe_unused]] int toneMap) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual double fbuf_GetToneAmt(int bufferIndex) = 0;

    virtual auto fbuf_SetToneAmt([[maybe_unused]] int bufferIndex, [[maybe_unused]] double toneAmt) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual double fbuf_GetHueOffset(int bufferIndex) = 0;

    virtual auto fbuf_SetHueOffset([[maybe_unused]] int bufferIndex, [[maybe_unused]] double hueOffset) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual double fbuf_GetSaturation(int bufferIndex) = 0;

    virtual auto fbuf_SetSaturation([[maybe_unused]] int bufferIndex, [[maybe_unused]] double saturation) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual double fbuf_GetColorization(int bufferIndex) = 0;

    virtual auto fbuf_SetColorization([[maybe_unused]] int bufferIndex, [[maybe_unused]] double colorization) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual void fbuf_GetTargetColor([[maybe_unused]] int bufferIndex, [[maybe_unused]] double *color)
    {
    }

    virtual auto fbuf_SetTargetColor([[maybe_unused]] int bufferIndex, [[maybe_unused]] const double *color) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual double fbuf_GetOutputBlackLevel(int bufferIndex) = 0;

    virtual auto fbuf_SetOutputBlackLevel([[maybe_unused]] int bufferIndex, [[maybe_unused]] double blackLevel) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual double fbuf_GetOutputWhiteLevel(int bufferIndex) = 0;

    virtual auto fbuf_SetOutputWhiteLevel([[maybe_unused]] int bufferIndex, [[maybe_unused]] double whiteLevel) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual double fbuf_GetOutputMinRedLevel(int bufferIndex) = 0;

    virtual auto fbuf_SetOutputMinRedLevel([[maybe_unused]] int bufferIndex, [[maybe_unused]] double blackLevel) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual double fbuf_GetOutputMaxRedLevel(int bufferIndex) = 0;

    virtual auto fbuf_SetOutputMaxRedLevel([[maybe_unused]] int bufferIndex, [[maybe_unused]] double whiteLevel) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual double fbuf_GetOutputMinGreenLevel(int bufferIndex) = 0;

    virtual auto fbuf_SetOutputMinGreenLevel([[maybe_unused]] int bufferIndex, [[maybe_unused]] double blackLevel) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual double fbuf_GetOutputMaxGreenLevel(int bufferIndex) = 0;

    virtual auto fbuf_SetOutputMaxGreenLevel([[maybe_unused]] int bufferIndex, [[maybe_unused]] double whiteLevel) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual double fbuf_GetOutputMinBlueLevel(int bufferIndex) = 0;

    virtual auto fbuf_SetOutputMinBlueLevel([[maybe_unused]] int bufferIndex, [[maybe_unused]] double blackLevel) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual double fbuf_GetOutputMaxBlueLevel(int bufferIndex) = 0;

    virtual auto fbuf_SetOutputMaxBlueLevel([[maybe_unused]] int bufferIndex, [[maybe_unused]] double whiteLevel) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual double fbuf_GetOutputGamma(int bufferIndex) = 0;

    virtual double fbuf_GetOutputInvGamma(int bufferIndex) = 0;

    virtual auto fbuf_SetOutputGamma([[maybe_unused]] int bufferIndex, [[maybe_unused]] double gamma) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual const char* fbuf_GetOutputColorspace(int bufferIndex) = 0;

    virtual auto fbuf_SetOutputColorspace([[maybe_unused]] const char* colorspace) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual ILxColorMappingID fbuf_GetOutputColormapping(int bufferIndex) = 0;

    virtual auto fbuf_SetOutputColormapping([[maybe_unused]] ILxUnknownID colormapping) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto fbuf_AddAttribute([[maybe_unused]] const char *name, [[maybe_unused]] const char *type, [[maybe_unused]] unsigned *index) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto fbuf_RenderProcessAllocate([[maybe_unused]] int bufferIndex, [[maybe_unused]] LXtRenderOutputProcess **rndrProcess) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto fbuf_RenderProcessDeallocate([[maybe_unused]] LXtRenderOutputProcess **rndrProcess) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_FrameBuffer_Allocate ILxBufferID fbuf_Allocate([[maybe_unused]] const char *name, [[maybe_unused]] ILxUnknownID item, [[maybe_unused]] const char *identity, [[maybe_unused]] const char *userName, [[maybe_unused]] int isFactoryName, [[maybe_unused]] int writeBucketsToDisk) override
#define LXxO_FrameBuffer_Allocate LXxD_FrameBuffer_Allocate
#define LXxC_FrameBuffer_Allocate(c) ILxBufferID c::fbuf_Allocate([[maybe_unused]] const char *name, [[maybe_unused]] ILxUnknownID item, [[maybe_unused]] const char *identity, [[maybe_unused]] const char *userName, [[maybe_unused]] int isFactoryName, [[maybe_unused]] int writeBucketsToDisk)
#define LXxD_FrameBuffer_IsStereo LxResult fbuf_IsStereo([[maybe_unused]] int *isStereo) override
#define LXxO_FrameBuffer_IsStereo LXxD_FrameBuffer_IsStereo
#define LXxC_FrameBuffer_IsStereo(c) LxResult c::fbuf_IsStereo([[maybe_unused]] int *isStereo)
#define LXxD_FrameBuffer_GetStereoEyeDisplay LxResult fbuf_GetStereoEyeDisplay([[maybe_unused]] LXtStereoEye *eyeDisplay) override
#define LXxO_FrameBuffer_GetStereoEyeDisplay LXxD_FrameBuffer_GetStereoEyeDisplay
#define LXxC_FrameBuffer_GetStereoEyeDisplay(c) LxResult c::fbuf_GetStereoEyeDisplay([[maybe_unused]] LXtStereoEye *eyeDisplay)
#define LXxD_FrameBuffer_SetStereoEyeDisplay LxResult fbuf_SetStereoEyeDisplay([[maybe_unused]] LXtStereoEye eyeDisplay) override
#define LXxO_FrameBuffer_SetStereoEyeDisplay LXxD_FrameBuffer_SetStereoEyeDisplay
#define LXxC_FrameBuffer_SetStereoEyeDisplay(c) LxResult c::fbuf_SetStereoEyeDisplay([[maybe_unused]] LXtStereoEye eyeDisplay)
#define LXxD_FrameBuffer_GetStereoComposite LxResult fbuf_GetStereoComposite([[maybe_unused]] LXtStereoComposite *composite) override
#define LXxO_FrameBuffer_GetStereoComposite LXxD_FrameBuffer_GetStereoComposite
#define LXxC_FrameBuffer_GetStereoComposite(c) LxResult c::fbuf_GetStereoComposite([[maybe_unused]] LXtStereoComposite *composite)
#define LXxD_FrameBuffer_SetStereoComposite LxResult fbuf_SetStereoComposite([[maybe_unused]] LXtStereoComposite composite) override
#define LXxO_FrameBuffer_SetStereoComposite LXxD_FrameBuffer_SetStereoComposite
#define LXxC_FrameBuffer_SetStereoComposite(c) LxResult c::fbuf_SetStereoComposite([[maybe_unused]] LXtStereoComposite composite)
#define LXxD_FrameBuffer_SetEyeSide LxResult fbuf_SetEyeSide([[maybe_unused]] int eyeSide) override
#define LXxO_FrameBuffer_SetEyeSide LXxD_FrameBuffer_SetEyeSide
#define LXxC_FrameBuffer_SetEyeSide(c) LxResult c::fbuf_SetEyeSide([[maybe_unused]] int eyeSide)
#define LXxD_FrameBuffer_GetLineBuffer LxResult fbuf_GetLineBuffer([[maybe_unused]] float **buf) override
#define LXxO_FrameBuffer_GetLineBuffer LXxD_FrameBuffer_GetLineBuffer
#define LXxC_FrameBuffer_GetLineBuffer(c) LxResult c::fbuf_GetLineBuffer([[maybe_unused]] float **buf)
#define LXxD_FrameBuffer_CreateFrameBufferTargetImage LxResult fbuf_CreateFrameBufferTargetImage([[maybe_unused]] LXtPixelFormat type, [[maybe_unused]] int w, [[maybe_unused]] int h, [[maybe_unused]] void **ppvObj) override
#define LXxO_FrameBuffer_CreateFrameBufferTargetImage LXxD_FrameBuffer_CreateFrameBufferTargetImage
#define LXxC_FrameBuffer_CreateFrameBufferTargetImage(c) LxResult c::fbuf_CreateFrameBufferTargetImage([[maybe_unused]] LXtPixelFormat type, [[maybe_unused]] int w, [[maybe_unused]] int h, [[maybe_unused]] void **ppvObj)
#define LXxD_FrameBuffer_GetRenderPassName LxResult fbuf_GetRenderPassName([[maybe_unused]] char *name) override
#define LXxO_FrameBuffer_GetRenderPassName LXxD_FrameBuffer_GetRenderPassName
#define LXxC_FrameBuffer_GetRenderPassName(c) LxResult c::fbuf_GetRenderPassName([[maybe_unused]] char *name)
#define LXxD_FrameBuffer_SetRenderPassName LxResult fbuf_SetRenderPassName([[maybe_unused]] const char *name) override
#define LXxO_FrameBuffer_SetRenderPassName LXxD_FrameBuffer_SetRenderPassName
#define LXxC_FrameBuffer_SetRenderPassName(c) LxResult c::fbuf_SetRenderPassName([[maybe_unused]] const char *name)
#define LXxD_FrameBuffer_BucketsOnDisk unsigned int fbuf_BucketsOnDisk([[maybe_unused]] int index) override
#define LXxO_FrameBuffer_BucketsOnDisk LXxD_FrameBuffer_BucketsOnDisk
#define LXxC_FrameBuffer_BucketsOnDisk(c) unsigned int c::fbuf_BucketsOnDisk([[maybe_unused]] int index)
#define LXxD_FrameBuffer_Lookup LXtObjectID fbuf_Lookup([[maybe_unused]] const char *name, [[maybe_unused]] ILxUnknownID item) override
#define LXxO_FrameBuffer_Lookup LXxD_FrameBuffer_Lookup
#define LXxC_FrameBuffer_Lookup(c) LXtObjectID c::fbuf_Lookup([[maybe_unused]] const char *name, [[maybe_unused]] ILxUnknownID item)
#define LXxD_FrameBuffer_LookupByIdentity LXtObjectID fbuf_LookupByIdentity([[maybe_unused]] const char *identity) override
#define LXxO_FrameBuffer_LookupByIdentity LXxD_FrameBuffer_LookupByIdentity
#define LXxC_FrameBuffer_LookupByIdentity(c) LXtObjectID c::fbuf_LookupByIdentity([[maybe_unused]] const char *identity)
#define LXxD_FrameBuffer_Count unsigned int fbuf_Count() override
#define LXxO_FrameBuffer_Count LXxD_FrameBuffer_Count
#define LXxC_FrameBuffer_Count(c) unsigned int c::fbuf_Count()
#define LXxD_FrameBuffer_ByIndex LXtObjectID fbuf_ByIndex([[maybe_unused]] int index) override
#define LXxO_FrameBuffer_ByIndex LXxD_FrameBuffer_ByIndex
#define LXxC_FrameBuffer_ByIndex(c) LXtObjectID c::fbuf_ByIndex([[maybe_unused]] int index)
#define LXxD_FrameBuffer_Alpha LXtObjectID fbuf_Alpha([[maybe_unused]] int index) override
#define LXxO_FrameBuffer_Alpha LXxD_FrameBuffer_Alpha
#define LXxC_FrameBuffer_Alpha(c) LXtObjectID c::fbuf_Alpha([[maybe_unused]] int index)
#define LXxD_FrameBuffer_AlphaIndex int fbuf_AlphaIndex([[maybe_unused]] int index) override
#define LXxO_FrameBuffer_AlphaIndex LXxD_FrameBuffer_AlphaIndex
#define LXxC_FrameBuffer_AlphaIndex(c) int c::fbuf_AlphaIndex([[maybe_unused]] int index)
#define LXxD_FrameBuffer_Size LxResult fbuf_Size([[maybe_unused]] int index, [[maybe_unused]] int *width, [[maybe_unused]] int *height) override
#define LXxO_FrameBuffer_Size LXxD_FrameBuffer_Size
#define LXxC_FrameBuffer_Size(c) LxResult c::fbuf_Size([[maybe_unused]] int index, [[maybe_unused]] int *width, [[maybe_unused]] int *height)
#define LXxD_FrameBuffer_AreaProcessingActive LxResult fbuf_AreaProcessingActive([[maybe_unused]] int bufferIndex, [[maybe_unused]] int *active) override
#define LXxO_FrameBuffer_AreaProcessingActive LXxD_FrameBuffer_AreaProcessingActive
#define LXxC_FrameBuffer_AreaProcessingActive(c) LxResult c::fbuf_AreaProcessingActive([[maybe_unused]] int bufferIndex, [[maybe_unused]] int *active)
#define LXxD_FrameBuffer_GetSaveProcessed int fbuf_GetSaveProcessed([[maybe_unused]] int bufferIndex) override
#define LXxO_FrameBuffer_GetSaveProcessed LXxD_FrameBuffer_GetSaveProcessed
#define LXxC_FrameBuffer_GetSaveProcessed(c) int c::fbuf_GetSaveProcessed([[maybe_unused]] int bufferIndex)
#define LXxD_FrameBuffer_SetSaveProcessed LxResult fbuf_SetSaveProcessed([[maybe_unused]] int bufferIndex, [[maybe_unused]] int enabled) override
#define LXxO_FrameBuffer_SetSaveProcessed LXxD_FrameBuffer_SetSaveProcessed
#define LXxC_FrameBuffer_SetSaveProcessed(c) LxResult c::fbuf_SetSaveProcessed([[maybe_unused]] int bufferIndex, [[maybe_unused]] int enabled)
#define LXxD_FrameBuffer_GetBloomEnabled int fbuf_GetBloomEnabled([[maybe_unused]] int bufferIndex) override
#define LXxO_FrameBuffer_GetBloomEnabled LXxD_FrameBuffer_GetBloomEnabled
#define LXxC_FrameBuffer_GetBloomEnabled(c) int c::fbuf_GetBloomEnabled([[maybe_unused]] int bufferIndex)
#define LXxD_FrameBuffer_SetBloomEnabled LxResult fbuf_SetBloomEnabled([[maybe_unused]] int bufferIndex, [[maybe_unused]] int enabled) override
#define LXxO_FrameBuffer_SetBloomEnabled LXxD_FrameBuffer_SetBloomEnabled
#define LXxC_FrameBuffer_SetBloomEnabled(c) LxResult c::fbuf_SetBloomEnabled([[maybe_unused]] int bufferIndex, [[maybe_unused]] int enabled)
#define LXxD_FrameBuffer_GetBloomThreshold double fbuf_GetBloomThreshold([[maybe_unused]] int bufferIndex) override
#define LXxO_FrameBuffer_GetBloomThreshold LXxD_FrameBuffer_GetBloomThreshold
#define LXxC_FrameBuffer_GetBloomThreshold(c) double c::fbuf_GetBloomThreshold([[maybe_unused]] int bufferIndex)
#define LXxD_FrameBuffer_SetBloomThreshold LxResult fbuf_SetBloomThreshold([[maybe_unused]] int bufferIndex, [[maybe_unused]] double threshold) override
#define LXxO_FrameBuffer_SetBloomThreshold LXxD_FrameBuffer_SetBloomThreshold
#define LXxC_FrameBuffer_SetBloomThreshold(c) LxResult c::fbuf_SetBloomThreshold([[maybe_unused]] int bufferIndex, [[maybe_unused]] double threshold)
#define LXxD_FrameBuffer_GetBloomRadius double fbuf_GetBloomRadius([[maybe_unused]] int bufferIndex) override
#define LXxO_FrameBuffer_GetBloomRadius LXxD_FrameBuffer_GetBloomRadius
#define LXxC_FrameBuffer_GetBloomRadius(c) double c::fbuf_GetBloomRadius([[maybe_unused]] int bufferIndex)
#define LXxD_FrameBuffer_SetBloomRadius LxResult fbuf_SetBloomRadius([[maybe_unused]] int bufferIndex, [[maybe_unused]] double radius) override
#define LXxO_FrameBuffer_SetBloomRadius LXxD_FrameBuffer_SetBloomRadius
#define LXxC_FrameBuffer_SetBloomRadius(c) LxResult c::fbuf_SetBloomRadius([[maybe_unused]] int bufferIndex, [[maybe_unused]] double radius)
#define LXxD_FrameBuffer_GetVignetteAmount double fbuf_GetVignetteAmount([[maybe_unused]] int bufferIndex) override
#define LXxO_FrameBuffer_GetVignetteAmount LXxD_FrameBuffer_GetVignetteAmount
#define LXxC_FrameBuffer_GetVignetteAmount(c) double c::fbuf_GetVignetteAmount([[maybe_unused]] int bufferIndex)
#define LXxD_FrameBuffer_SetVignetteAmount LxResult fbuf_SetVignetteAmount([[maybe_unused]] int bufferIndex, [[maybe_unused]] double radius) override
#define LXxO_FrameBuffer_SetVignetteAmount LXxD_FrameBuffer_SetVignetteAmount
#define LXxC_FrameBuffer_SetVignetteAmount(c) LxResult c::fbuf_SetVignetteAmount([[maybe_unused]] int bufferIndex, [[maybe_unused]] double radius)
#define LXxD_FrameBuffer_GetInputBlackLevel double fbuf_GetInputBlackLevel([[maybe_unused]] int bufferIndex) override
#define LXxO_FrameBuffer_GetInputBlackLevel LXxD_FrameBuffer_GetInputBlackLevel
#define LXxC_FrameBuffer_GetInputBlackLevel(c) double c::fbuf_GetInputBlackLevel([[maybe_unused]] int bufferIndex)
#define LXxD_FrameBuffer_SetInputBlackLevel LxResult fbuf_SetInputBlackLevel([[maybe_unused]] int bufferIndex, [[maybe_unused]] double blackLevel) override
#define LXxO_FrameBuffer_SetInputBlackLevel LXxD_FrameBuffer_SetInputBlackLevel
#define LXxC_FrameBuffer_SetInputBlackLevel(c) LxResult c::fbuf_SetInputBlackLevel([[maybe_unused]] int bufferIndex, [[maybe_unused]] double blackLevel)
#define LXxD_FrameBuffer_GetInputGrayLevel double fbuf_GetInputGrayLevel([[maybe_unused]] int bufferIndex) override
#define LXxO_FrameBuffer_GetInputGrayLevel LXxD_FrameBuffer_GetInputGrayLevel
#define LXxC_FrameBuffer_GetInputGrayLevel(c) double c::fbuf_GetInputGrayLevel([[maybe_unused]] int bufferIndex)
#define LXxD_FrameBuffer_GetInvInputGrayLevel double fbuf_GetInvInputGrayLevel([[maybe_unused]] int bufferIndex) override
#define LXxO_FrameBuffer_GetInvInputGrayLevel LXxD_FrameBuffer_GetInvInputGrayLevel
#define LXxC_FrameBuffer_GetInvInputGrayLevel(c) double c::fbuf_GetInvInputGrayLevel([[maybe_unused]] int bufferIndex)
#define LXxD_FrameBuffer_SetInputGrayLevel LxResult fbuf_SetInputGrayLevel([[maybe_unused]] int bufferIndex, [[maybe_unused]] double gamma) override
#define LXxO_FrameBuffer_SetInputGrayLevel LXxD_FrameBuffer_SetInputGrayLevel
#define LXxC_FrameBuffer_SetInputGrayLevel(c) LxResult c::fbuf_SetInputGrayLevel([[maybe_unused]] int bufferIndex, [[maybe_unused]] double gamma)
#define LXxD_FrameBuffer_GetInputWhiteLevel double fbuf_GetInputWhiteLevel([[maybe_unused]] int bufferIndex) override
#define LXxO_FrameBuffer_GetInputWhiteLevel LXxD_FrameBuffer_GetInputWhiteLevel
#define LXxC_FrameBuffer_GetInputWhiteLevel(c) double c::fbuf_GetInputWhiteLevel([[maybe_unused]] int bufferIndex)
#define LXxD_FrameBuffer_SetInputWhiteLevel LxResult fbuf_SetInputWhiteLevel([[maybe_unused]] int bufferIndex, [[maybe_unused]] double whiteLevel) override
#define LXxO_FrameBuffer_SetInputWhiteLevel LXxD_FrameBuffer_SetInputWhiteLevel
#define LXxC_FrameBuffer_SetInputWhiteLevel(c) LxResult c::fbuf_SetInputWhiteLevel([[maybe_unused]] int bufferIndex, [[maybe_unused]] double whiteLevel)
#define LXxD_FrameBuffer_GetInputMinRedLevel double fbuf_GetInputMinRedLevel([[maybe_unused]] int bufferIndex) override
#define LXxO_FrameBuffer_GetInputMinRedLevel LXxD_FrameBuffer_GetInputMinRedLevel
#define LXxC_FrameBuffer_GetInputMinRedLevel(c) double c::fbuf_GetInputMinRedLevel([[maybe_unused]] int bufferIndex)
#define LXxD_FrameBuffer_SetInputMinRedLevel LxResult fbuf_SetInputMinRedLevel([[maybe_unused]] int bufferIndex, [[maybe_unused]] double level) override
#define LXxO_FrameBuffer_SetInputMinRedLevel LXxD_FrameBuffer_SetInputMinRedLevel
#define LXxC_FrameBuffer_SetInputMinRedLevel(c) LxResult c::fbuf_SetInputMinRedLevel([[maybe_unused]] int bufferIndex, [[maybe_unused]] double level)
#define LXxD_FrameBuffer_GetInputRedGrayLevel double fbuf_GetInputRedGrayLevel([[maybe_unused]] int bufferIndex) override
#define LXxO_FrameBuffer_GetInputRedGrayLevel LXxD_FrameBuffer_GetInputRedGrayLevel
#define LXxC_FrameBuffer_GetInputRedGrayLevel(c) double c::fbuf_GetInputRedGrayLevel([[maybe_unused]] int bufferIndex)
#define LXxD_FrameBuffer_GetInvInputRedGrayLevel double fbuf_GetInvInputRedGrayLevel([[maybe_unused]] int bufferIndex) override
#define LXxO_FrameBuffer_GetInvInputRedGrayLevel LXxD_FrameBuffer_GetInvInputRedGrayLevel
#define LXxC_FrameBuffer_GetInvInputRedGrayLevel(c) double c::fbuf_GetInvInputRedGrayLevel([[maybe_unused]] int bufferIndex)
#define LXxD_FrameBuffer_SetInputRedGrayLevel LxResult fbuf_SetInputRedGrayLevel([[maybe_unused]] int bufferIndex, [[maybe_unused]] double gamma) override
#define LXxO_FrameBuffer_SetInputRedGrayLevel LXxD_FrameBuffer_SetInputRedGrayLevel
#define LXxC_FrameBuffer_SetInputRedGrayLevel(c) LxResult c::fbuf_SetInputRedGrayLevel([[maybe_unused]] int bufferIndex, [[maybe_unused]] double gamma)
#define LXxD_FrameBuffer_GetInputMaxRedLevel double fbuf_GetInputMaxRedLevel([[maybe_unused]] int bufferIndex) override
#define LXxO_FrameBuffer_GetInputMaxRedLevel LXxD_FrameBuffer_GetInputMaxRedLevel
#define LXxC_FrameBuffer_GetInputMaxRedLevel(c) double c::fbuf_GetInputMaxRedLevel([[maybe_unused]] int bufferIndex)
#define LXxD_FrameBuffer_SetInputMaxRedLevel LxResult fbuf_SetInputMaxRedLevel([[maybe_unused]] int bufferIndex, [[maybe_unused]] double level) override
#define LXxO_FrameBuffer_SetInputMaxRedLevel LXxD_FrameBuffer_SetInputMaxRedLevel
#define LXxC_FrameBuffer_SetInputMaxRedLevel(c) LxResult c::fbuf_SetInputMaxRedLevel([[maybe_unused]] int bufferIndex, [[maybe_unused]] double level)
#define LXxD_FrameBuffer_GetInputMinGreenLevel double fbuf_GetInputMinGreenLevel([[maybe_unused]] int bufferIndex) override
#define LXxO_FrameBuffer_GetInputMinGreenLevel LXxD_FrameBuffer_GetInputMinGreenLevel
#define LXxC_FrameBuffer_GetInputMinGreenLevel(c) double c::fbuf_GetInputMinGreenLevel([[maybe_unused]] int bufferIndex)
#define LXxD_FrameBuffer_SetInputMinGreenLevel LxResult fbuf_SetInputMinGreenLevel([[maybe_unused]] int bufferIndex, [[maybe_unused]] double level) override
#define LXxO_FrameBuffer_SetInputMinGreenLevel LXxD_FrameBuffer_SetInputMinGreenLevel
#define LXxC_FrameBuffer_SetInputMinGreenLevel(c) LxResult c::fbuf_SetInputMinGreenLevel([[maybe_unused]] int bufferIndex, [[maybe_unused]] double level)
#define LXxD_FrameBuffer_GetInputGreenGrayLevel double fbuf_GetInputGreenGrayLevel([[maybe_unused]] int bufferIndex) override
#define LXxO_FrameBuffer_GetInputGreenGrayLevel LXxD_FrameBuffer_GetInputGreenGrayLevel
#define LXxC_FrameBuffer_GetInputGreenGrayLevel(c) double c::fbuf_GetInputGreenGrayLevel([[maybe_unused]] int bufferIndex)
#define LXxD_FrameBuffer_GetInvInputGreenGrayLevel double fbuf_GetInvInputGreenGrayLevel([[maybe_unused]] int bufferIndex) override
#define LXxO_FrameBuffer_GetInvInputGreenGrayLevel LXxD_FrameBuffer_GetInvInputGreenGrayLevel
#define LXxC_FrameBuffer_GetInvInputGreenGrayLevel(c) double c::fbuf_GetInvInputGreenGrayLevel([[maybe_unused]] int bufferIndex)
#define LXxD_FrameBuffer_SetInputGreenGrayLevel LxResult fbuf_SetInputGreenGrayLevel([[maybe_unused]] int bufferIndex, [[maybe_unused]] double gamma) override
#define LXxO_FrameBuffer_SetInputGreenGrayLevel LXxD_FrameBuffer_SetInputGreenGrayLevel
#define LXxC_FrameBuffer_SetInputGreenGrayLevel(c) LxResult c::fbuf_SetInputGreenGrayLevel([[maybe_unused]] int bufferIndex, [[maybe_unused]] double gamma)
#define LXxD_FrameBuffer_GetInputMaxGreenLevel double fbuf_GetInputMaxGreenLevel([[maybe_unused]] int bufferIndex) override
#define LXxO_FrameBuffer_GetInputMaxGreenLevel LXxD_FrameBuffer_GetInputMaxGreenLevel
#define LXxC_FrameBuffer_GetInputMaxGreenLevel(c) double c::fbuf_GetInputMaxGreenLevel([[maybe_unused]] int bufferIndex)
#define LXxD_FrameBuffer_SetInputMaxGreenLevel LxResult fbuf_SetInputMaxGreenLevel([[maybe_unused]] int bufferIndex, [[maybe_unused]] double level) override
#define LXxO_FrameBuffer_SetInputMaxGreenLevel LXxD_FrameBuffer_SetInputMaxGreenLevel
#define LXxC_FrameBuffer_SetInputMaxGreenLevel(c) LxResult c::fbuf_SetInputMaxGreenLevel([[maybe_unused]] int bufferIndex, [[maybe_unused]] double level)
#define LXxD_FrameBuffer_GetInputMinBlueLevel double fbuf_GetInputMinBlueLevel([[maybe_unused]] int bufferIndex) override
#define LXxO_FrameBuffer_GetInputMinBlueLevel LXxD_FrameBuffer_GetInputMinBlueLevel
#define LXxC_FrameBuffer_GetInputMinBlueLevel(c) double c::fbuf_GetInputMinBlueLevel([[maybe_unused]] int bufferIndex)
#define LXxD_FrameBuffer_SetInputMinBlueLevel LxResult fbuf_SetInputMinBlueLevel([[maybe_unused]] int bufferIndex, [[maybe_unused]] double level) override
#define LXxO_FrameBuffer_SetInputMinBlueLevel LXxD_FrameBuffer_SetInputMinBlueLevel
#define LXxC_FrameBuffer_SetInputMinBlueLevel(c) LxResult c::fbuf_SetInputMinBlueLevel([[maybe_unused]] int bufferIndex, [[maybe_unused]] double level)
#define LXxD_FrameBuffer_GetInputBlueGrayLevel double fbuf_GetInputBlueGrayLevel([[maybe_unused]] int bufferIndex) override
#define LXxO_FrameBuffer_GetInputBlueGrayLevel LXxD_FrameBuffer_GetInputBlueGrayLevel
#define LXxC_FrameBuffer_GetInputBlueGrayLevel(c) double c::fbuf_GetInputBlueGrayLevel([[maybe_unused]] int bufferIndex)
#define LXxD_FrameBuffer_GetInvInputBlueGrayLevel double fbuf_GetInvInputBlueGrayLevel([[maybe_unused]] int bufferIndex) override
#define LXxO_FrameBuffer_GetInvInputBlueGrayLevel LXxD_FrameBuffer_GetInvInputBlueGrayLevel
#define LXxC_FrameBuffer_GetInvInputBlueGrayLevel(c) double c::fbuf_GetInvInputBlueGrayLevel([[maybe_unused]] int bufferIndex)
#define LXxD_FrameBuffer_SetInputBlueGrayLevel LxResult fbuf_SetInputBlueGrayLevel([[maybe_unused]] int bufferIndex, [[maybe_unused]] double gamma) override
#define LXxO_FrameBuffer_SetInputBlueGrayLevel LXxD_FrameBuffer_SetInputBlueGrayLevel
#define LXxC_FrameBuffer_SetInputBlueGrayLevel(c) LxResult c::fbuf_SetInputBlueGrayLevel([[maybe_unused]] int bufferIndex, [[maybe_unused]] double gamma)
#define LXxD_FrameBuffer_GetInputMaxBlueLevel double fbuf_GetInputMaxBlueLevel([[maybe_unused]] int bufferIndex) override
#define LXxO_FrameBuffer_GetInputMaxBlueLevel LXxD_FrameBuffer_GetInputMaxBlueLevel
#define LXxC_FrameBuffer_GetInputMaxBlueLevel(c) double c::fbuf_GetInputMaxBlueLevel([[maybe_unused]] int bufferIndex)
#define LXxD_FrameBuffer_SetInputMaxBlueLevel LxResult fbuf_SetInputMaxBlueLevel([[maybe_unused]] int bufferIndex, [[maybe_unused]] double level) override
#define LXxO_FrameBuffer_SetInputMaxBlueLevel LXxD_FrameBuffer_SetInputMaxBlueLevel
#define LXxC_FrameBuffer_SetInputMaxBlueLevel(c) LxResult c::fbuf_SetInputMaxBlueLevel([[maybe_unused]] int bufferIndex, [[maybe_unused]] double level)
#define LXxD_FrameBuffer_GetExpType int fbuf_GetExpType([[maybe_unused]] int bufferIndex) override
#define LXxO_FrameBuffer_GetExpType LXxD_FrameBuffer_GetExpType
#define LXxC_FrameBuffer_GetExpType(c) int c::fbuf_GetExpType([[maybe_unused]] int bufferIndex)
#define LXxD_FrameBuffer_SetExpType LxResult fbuf_SetExpType([[maybe_unused]] int bufferIndex, [[maybe_unused]] int expType) override
#define LXxO_FrameBuffer_SetExpType LXxD_FrameBuffer_SetExpType
#define LXxC_FrameBuffer_SetExpType(c) LxResult c::fbuf_SetExpType([[maybe_unused]] int bufferIndex, [[maybe_unused]] int expType)
#define LXxD_FrameBuffer_GetISO double fbuf_GetISO([[maybe_unused]] int bufferIndex) override
#define LXxO_FrameBuffer_GetISO LXxD_FrameBuffer_GetISO
#define LXxC_FrameBuffer_GetISO(c) double c::fbuf_GetISO([[maybe_unused]] int bufferIndex)
#define LXxD_FrameBuffer_SetISO LxResult fbuf_SetISO([[maybe_unused]] int bufferIndex, [[maybe_unused]] double iso) override
#define LXxO_FrameBuffer_SetISO LXxD_FrameBuffer_SetISO
#define LXxC_FrameBuffer_SetISO(c) LxResult c::fbuf_SetISO([[maybe_unused]] int bufferIndex, [[maybe_unused]] double iso)
#define LXxD_FrameBuffer_GetToneMap int fbuf_GetToneMap([[maybe_unused]] int bufferIndex) override
#define LXxO_FrameBuffer_GetToneMap LXxD_FrameBuffer_GetToneMap
#define LXxC_FrameBuffer_GetToneMap(c) int c::fbuf_GetToneMap([[maybe_unused]] int bufferIndex)
#define LXxD_FrameBuffer_SetToneMap LxResult fbuf_SetToneMap([[maybe_unused]] int bufferIndex, [[maybe_unused]] int toneMap) override
#define LXxO_FrameBuffer_SetToneMap LXxD_FrameBuffer_SetToneMap
#define LXxC_FrameBuffer_SetToneMap(c) LxResult c::fbuf_SetToneMap([[maybe_unused]] int bufferIndex, [[maybe_unused]] int toneMap)
#define LXxD_FrameBuffer_GetToneAmt double fbuf_GetToneAmt([[maybe_unused]] int bufferIndex) override
#define LXxO_FrameBuffer_GetToneAmt LXxD_FrameBuffer_GetToneAmt
#define LXxC_FrameBuffer_GetToneAmt(c) double c::fbuf_GetToneAmt([[maybe_unused]] int bufferIndex)
#define LXxD_FrameBuffer_SetToneAmt LxResult fbuf_SetToneAmt([[maybe_unused]] int bufferIndex, [[maybe_unused]] double toneAmt) override
#define LXxO_FrameBuffer_SetToneAmt LXxD_FrameBuffer_SetToneAmt
#define LXxC_FrameBuffer_SetToneAmt(c) LxResult c::fbuf_SetToneAmt([[maybe_unused]] int bufferIndex, [[maybe_unused]] double toneAmt)
#define LXxD_FrameBuffer_GetHueOffset double fbuf_GetHueOffset([[maybe_unused]] int bufferIndex) override
#define LXxO_FrameBuffer_GetHueOffset LXxD_FrameBuffer_GetHueOffset
#define LXxC_FrameBuffer_GetHueOffset(c) double c::fbuf_GetHueOffset([[maybe_unused]] int bufferIndex)
#define LXxD_FrameBuffer_SetHueOffset LxResult fbuf_SetHueOffset([[maybe_unused]] int bufferIndex, [[maybe_unused]] double hueOffset) override
#define LXxO_FrameBuffer_SetHueOffset LXxD_FrameBuffer_SetHueOffset
#define LXxC_FrameBuffer_SetHueOffset(c) LxResult c::fbuf_SetHueOffset([[maybe_unused]] int bufferIndex, [[maybe_unused]] double hueOffset)
#define LXxD_FrameBuffer_GetSaturation double fbuf_GetSaturation([[maybe_unused]] int bufferIndex) override
#define LXxO_FrameBuffer_GetSaturation LXxD_FrameBuffer_GetSaturation
#define LXxC_FrameBuffer_GetSaturation(c) double c::fbuf_GetSaturation([[maybe_unused]] int bufferIndex)
#define LXxD_FrameBuffer_SetSaturation LxResult fbuf_SetSaturation([[maybe_unused]] int bufferIndex, [[maybe_unused]] double saturation) override
#define LXxO_FrameBuffer_SetSaturation LXxD_FrameBuffer_SetSaturation
#define LXxC_FrameBuffer_SetSaturation(c) LxResult c::fbuf_SetSaturation([[maybe_unused]] int bufferIndex, [[maybe_unused]] double saturation)
#define LXxD_FrameBuffer_GetColorization double fbuf_GetColorization([[maybe_unused]] int bufferIndex) override
#define LXxO_FrameBuffer_GetColorization LXxD_FrameBuffer_GetColorization
#define LXxC_FrameBuffer_GetColorization(c) double c::fbuf_GetColorization([[maybe_unused]] int bufferIndex)
#define LXxD_FrameBuffer_SetColorization LxResult fbuf_SetColorization([[maybe_unused]] int bufferIndex, [[maybe_unused]] double colorization) override
#define LXxO_FrameBuffer_SetColorization LXxD_FrameBuffer_SetColorization
#define LXxC_FrameBuffer_SetColorization(c) LxResult c::fbuf_SetColorization([[maybe_unused]] int bufferIndex, [[maybe_unused]] double colorization)
#define LXxD_FrameBuffer_GetTargetColor void fbuf_GetTargetColor([[maybe_unused]] int bufferIndex, [[maybe_unused]] double *color) override
#define LXxO_FrameBuffer_GetTargetColor LXxD_FrameBuffer_GetTargetColor
#define LXxC_FrameBuffer_GetTargetColor(c) void c::fbuf_GetTargetColor([[maybe_unused]] int bufferIndex, [[maybe_unused]] double *color)
#define LXxD_FrameBuffer_SetTargetColor LxResult fbuf_SetTargetColor([[maybe_unused]] int bufferIndex, [[maybe_unused]] const double *color) override
#define LXxO_FrameBuffer_SetTargetColor LXxD_FrameBuffer_SetTargetColor
#define LXxC_FrameBuffer_SetTargetColor(c) LxResult c::fbuf_SetTargetColor([[maybe_unused]] int bufferIndex, [[maybe_unused]] const double *color)
#define LXxD_FrameBuffer_GetOutputBlackLevel double fbuf_GetOutputBlackLevel([[maybe_unused]] int bufferIndex) override
#define LXxO_FrameBuffer_GetOutputBlackLevel LXxD_FrameBuffer_GetOutputBlackLevel
#define LXxC_FrameBuffer_GetOutputBlackLevel(c) double c::fbuf_GetOutputBlackLevel([[maybe_unused]] int bufferIndex)
#define LXxD_FrameBuffer_SetOutputBlackLevel LxResult fbuf_SetOutputBlackLevel([[maybe_unused]] int bufferIndex, [[maybe_unused]] double blackLevel) override
#define LXxO_FrameBuffer_SetOutputBlackLevel LXxD_FrameBuffer_SetOutputBlackLevel
#define LXxC_FrameBuffer_SetOutputBlackLevel(c) LxResult c::fbuf_SetOutputBlackLevel([[maybe_unused]] int bufferIndex, [[maybe_unused]] double blackLevel)
#define LXxD_FrameBuffer_GetOutputWhiteLevel double fbuf_GetOutputWhiteLevel([[maybe_unused]] int bufferIndex) override
#define LXxO_FrameBuffer_GetOutputWhiteLevel LXxD_FrameBuffer_GetOutputWhiteLevel
#define LXxC_FrameBuffer_GetOutputWhiteLevel(c) double c::fbuf_GetOutputWhiteLevel([[maybe_unused]] int bufferIndex)
#define LXxD_FrameBuffer_SetOutputWhiteLevel LxResult fbuf_SetOutputWhiteLevel([[maybe_unused]] int bufferIndex, [[maybe_unused]] double whiteLevel) override
#define LXxO_FrameBuffer_SetOutputWhiteLevel LXxD_FrameBuffer_SetOutputWhiteLevel
#define LXxC_FrameBuffer_SetOutputWhiteLevel(c) LxResult c::fbuf_SetOutputWhiteLevel([[maybe_unused]] int bufferIndex, [[maybe_unused]] double whiteLevel)
#define LXxD_FrameBuffer_GetOutputMinRedLevel double fbuf_GetOutputMinRedLevel([[maybe_unused]] int bufferIndex) override
#define LXxO_FrameBuffer_GetOutputMinRedLevel LXxD_FrameBuffer_GetOutputMinRedLevel
#define LXxC_FrameBuffer_GetOutputMinRedLevel(c) double c::fbuf_GetOutputMinRedLevel([[maybe_unused]] int bufferIndex)
#define LXxD_FrameBuffer_SetOutputMinRedLevel LxResult fbuf_SetOutputMinRedLevel([[maybe_unused]] int bufferIndex, [[maybe_unused]] double blackLevel) override
#define LXxO_FrameBuffer_SetOutputMinRedLevel LXxD_FrameBuffer_SetOutputMinRedLevel
#define LXxC_FrameBuffer_SetOutputMinRedLevel(c) LxResult c::fbuf_SetOutputMinRedLevel([[maybe_unused]] int bufferIndex, [[maybe_unused]] double blackLevel)
#define LXxD_FrameBuffer_GetOutputMaxRedLevel double fbuf_GetOutputMaxRedLevel([[maybe_unused]] int bufferIndex) override
#define LXxO_FrameBuffer_GetOutputMaxRedLevel LXxD_FrameBuffer_GetOutputMaxRedLevel
#define LXxC_FrameBuffer_GetOutputMaxRedLevel(c) double c::fbuf_GetOutputMaxRedLevel([[maybe_unused]] int bufferIndex)
#define LXxD_FrameBuffer_SetOutputMaxRedLevel LxResult fbuf_SetOutputMaxRedLevel([[maybe_unused]] int bufferIndex, [[maybe_unused]] double whiteLevel) override
#define LXxO_FrameBuffer_SetOutputMaxRedLevel LXxD_FrameBuffer_SetOutputMaxRedLevel
#define LXxC_FrameBuffer_SetOutputMaxRedLevel(c) LxResult c::fbuf_SetOutputMaxRedLevel([[maybe_unused]] int bufferIndex, [[maybe_unused]] double whiteLevel)
#define LXxD_FrameBuffer_GetOutputMinGreenLevel double fbuf_GetOutputMinGreenLevel([[maybe_unused]] int bufferIndex) override
#define LXxO_FrameBuffer_GetOutputMinGreenLevel LXxD_FrameBuffer_GetOutputMinGreenLevel
#define LXxC_FrameBuffer_GetOutputMinGreenLevel(c) double c::fbuf_GetOutputMinGreenLevel([[maybe_unused]] int bufferIndex)
#define LXxD_FrameBuffer_SetOutputMinGreenLevel LxResult fbuf_SetOutputMinGreenLevel([[maybe_unused]] int bufferIndex, [[maybe_unused]] double blackLevel) override
#define LXxO_FrameBuffer_SetOutputMinGreenLevel LXxD_FrameBuffer_SetOutputMinGreenLevel
#define LXxC_FrameBuffer_SetOutputMinGreenLevel(c) LxResult c::fbuf_SetOutputMinGreenLevel([[maybe_unused]] int bufferIndex, [[maybe_unused]] double blackLevel)
#define LXxD_FrameBuffer_GetOutputMaxGreenLevel double fbuf_GetOutputMaxGreenLevel([[maybe_unused]] int bufferIndex) override
#define LXxO_FrameBuffer_GetOutputMaxGreenLevel LXxD_FrameBuffer_GetOutputMaxGreenLevel
#define LXxC_FrameBuffer_GetOutputMaxGreenLevel(c) double c::fbuf_GetOutputMaxGreenLevel([[maybe_unused]] int bufferIndex)
#define LXxD_FrameBuffer_SetOutputMaxGreenLevel LxResult fbuf_SetOutputMaxGreenLevel([[maybe_unused]] int bufferIndex, [[maybe_unused]] double whiteLevel) override
#define LXxO_FrameBuffer_SetOutputMaxGreenLevel LXxD_FrameBuffer_SetOutputMaxGreenLevel
#define LXxC_FrameBuffer_SetOutputMaxGreenLevel(c) LxResult c::fbuf_SetOutputMaxGreenLevel([[maybe_unused]] int bufferIndex, [[maybe_unused]] double whiteLevel)
#define LXxD_FrameBuffer_GetOutputMinBlueLevel double fbuf_GetOutputMinBlueLevel([[maybe_unused]] int bufferIndex) override
#define LXxO_FrameBuffer_GetOutputMinBlueLevel LXxD_FrameBuffer_GetOutputMinBlueLevel
#define LXxC_FrameBuffer_GetOutputMinBlueLevel(c) double c::fbuf_GetOutputMinBlueLevel([[maybe_unused]] int bufferIndex)
#define LXxD_FrameBuffer_SetOutputMinBlueLevel LxResult fbuf_SetOutputMinBlueLevel([[maybe_unused]] int bufferIndex, [[maybe_unused]] double blackLevel) override
#define LXxO_FrameBuffer_SetOutputMinBlueLevel LXxD_FrameBuffer_SetOutputMinBlueLevel
#define LXxC_FrameBuffer_SetOutputMinBlueLevel(c) LxResult c::fbuf_SetOutputMinBlueLevel([[maybe_unused]] int bufferIndex, [[maybe_unused]] double blackLevel)
#define LXxD_FrameBuffer_GetOutputMaxBlueLevel double fbuf_GetOutputMaxBlueLevel([[maybe_unused]] int bufferIndex) override
#define LXxO_FrameBuffer_GetOutputMaxBlueLevel LXxD_FrameBuffer_GetOutputMaxBlueLevel
#define LXxC_FrameBuffer_GetOutputMaxBlueLevel(c) double c::fbuf_GetOutputMaxBlueLevel([[maybe_unused]] int bufferIndex)
#define LXxD_FrameBuffer_SetOutputMaxBlueLevel LxResult fbuf_SetOutputMaxBlueLevel([[maybe_unused]] int bufferIndex, [[maybe_unused]] double whiteLevel) override
#define LXxO_FrameBuffer_SetOutputMaxBlueLevel LXxD_FrameBuffer_SetOutputMaxBlueLevel
#define LXxC_FrameBuffer_SetOutputMaxBlueLevel(c) LxResult c::fbuf_SetOutputMaxBlueLevel([[maybe_unused]] int bufferIndex, [[maybe_unused]] double whiteLevel)
#define LXxD_FrameBuffer_GetOutputGamma double fbuf_GetOutputGamma([[maybe_unused]] int bufferIndex) override
#define LXxO_FrameBuffer_GetOutputGamma LXxD_FrameBuffer_GetOutputGamma
#define LXxC_FrameBuffer_GetOutputGamma(c) double c::fbuf_GetOutputGamma([[maybe_unused]] int bufferIndex)
#define LXxD_FrameBuffer_GetOutputInvGamma double fbuf_GetOutputInvGamma([[maybe_unused]] int bufferIndex) override
#define LXxO_FrameBuffer_GetOutputInvGamma LXxD_FrameBuffer_GetOutputInvGamma
#define LXxC_FrameBuffer_GetOutputInvGamma(c) double c::fbuf_GetOutputInvGamma([[maybe_unused]] int bufferIndex)
#define LXxD_FrameBuffer_SetOutputGamma LxResult fbuf_SetOutputGamma([[maybe_unused]] int bufferIndex, [[maybe_unused]] double gamma) override
#define LXxO_FrameBuffer_SetOutputGamma LXxD_FrameBuffer_SetOutputGamma
#define LXxC_FrameBuffer_SetOutputGamma(c) LxResult c::fbuf_SetOutputGamma([[maybe_unused]] int bufferIndex, [[maybe_unused]] double gamma)
#define LXxD_FrameBuffer_GetOutputColorspace const char* fbuf_GetOutputColorspace([[maybe_unused]] int bufferIndex) override
#define LXxO_FrameBuffer_GetOutputColorspace LXxD_FrameBuffer_GetOutputColorspace
#define LXxC_FrameBuffer_GetOutputColorspace(c) const char* c::fbuf_GetOutputColorspace([[maybe_unused]] int bufferIndex)
#define LXxD_FrameBuffer_SetOutputColorspace LxResult fbuf_SetOutputColorspace([[maybe_unused]] const char* colorspace) override
#define LXxO_FrameBuffer_SetOutputColorspace LXxD_FrameBuffer_SetOutputColorspace
#define LXxC_FrameBuffer_SetOutputColorspace(c) LxResult c::fbuf_SetOutputColorspace([[maybe_unused]] const char* colorspace)
#define LXxD_FrameBuffer_GetOutputColormapping ILxColorMappingID fbuf_GetOutputColormapping([[maybe_unused]] int bufferIndex) override
#define LXxO_FrameBuffer_GetOutputColormapping LXxD_FrameBuffer_GetOutputColormapping
#define LXxC_FrameBuffer_GetOutputColormapping(c) ILxColorMappingID c::fbuf_GetOutputColormapping([[maybe_unused]] int bufferIndex)
#define LXxD_FrameBuffer_SetOutputColormapping LxResult fbuf_SetOutputColormapping([[maybe_unused]] ILxUnknownID colormapping) override
#define LXxO_FrameBuffer_SetOutputColormapping LXxD_FrameBuffer_SetOutputColormapping
#define LXxC_FrameBuffer_SetOutputColormapping(c) LxResult c::fbuf_SetOutputColormapping([[maybe_unused]] ILxUnknownID colormapping)
#define LXxD_FrameBuffer_AddAttribute LxResult fbuf_AddAttribute([[maybe_unused]] const char *name, [[maybe_unused]] const char *type, [[maybe_unused]] unsigned *index) override
#define LXxO_FrameBuffer_AddAttribute LXxD_FrameBuffer_AddAttribute
#define LXxC_FrameBuffer_AddAttribute(c) LxResult c::fbuf_AddAttribute([[maybe_unused]] const char *name, [[maybe_unused]] const char *type, [[maybe_unused]] unsigned *index)
#define LXxD_FrameBuffer_RenderProcessAllocate LxResult fbuf_RenderProcessAllocate([[maybe_unused]] int bufferIndex, [[maybe_unused]] LXtRenderOutputProcess **rndrProcess) override
#define LXxO_FrameBuffer_RenderProcessAllocate LXxD_FrameBuffer_RenderProcessAllocate
#define LXxC_FrameBuffer_RenderProcessAllocate(c) LxResult c::fbuf_RenderProcessAllocate([[maybe_unused]] int bufferIndex, [[maybe_unused]] LXtRenderOutputProcess **rndrProcess)
#define LXxD_FrameBuffer_RenderProcessDeallocate LxResult fbuf_RenderProcessDeallocate([[maybe_unused]] LXtRenderOutputProcess **rndrProcess) override
#define LXxO_FrameBuffer_RenderProcessDeallocate LXxD_FrameBuffer_RenderProcessDeallocate
#define LXxC_FrameBuffer_RenderProcessDeallocate(c) LxResult c::fbuf_RenderProcessDeallocate([[maybe_unused]] LXtRenderOutputProcess **rndrProcess)

template <class T>
class CLxIfc_FrameBuffer: public CLxInterface
{
public:
    CLxIfc_FrameBuffer()
    {
        vt.Allocate = Allocate;
        vt.IsStereo = IsStereo;
        vt.GetStereoEyeDisplay = GetStereoEyeDisplay;
        vt.SetStereoEyeDisplay = SetStereoEyeDisplay;
        vt.GetStereoComposite = GetStereoComposite;
        vt.SetStereoComposite = SetStereoComposite;
        vt.SetEyeSide = SetEyeSide;
        vt.GetLineBuffer = GetLineBuffer;
        vt.CreateFrameBufferTargetImage = CreateFrameBufferTargetImage;
        vt.GetRenderPassName = GetRenderPassName;
        vt.SetRenderPassName = SetRenderPassName;
        vt.BucketsOnDisk = BucketsOnDisk;
        vt.Lookup = Lookup;
        vt.LookupByIdentity = LookupByIdentity;
        vt.Count = Count;
        vt.ByIndex = ByIndex;
        vt.Alpha = Alpha;
        vt.AlphaIndex = AlphaIndex;
        vt.Size = Size;
        vt.AreaProcessingActive = AreaProcessingActive;
        vt.GetSaveProcessed = GetSaveProcessed;
        vt.SetSaveProcessed = SetSaveProcessed;
        vt.GetBloomEnabled = GetBloomEnabled;
        vt.SetBloomEnabled = SetBloomEnabled;
        vt.GetBloomThreshold = GetBloomThreshold;
        vt.SetBloomThreshold = SetBloomThreshold;
        vt.GetBloomRadius = GetBloomRadius;
        vt.SetBloomRadius = SetBloomRadius;
        vt.GetVignetteAmount = GetVignetteAmount;
        vt.SetVignetteAmount = SetVignetteAmount;
        vt.GetInputBlackLevel = GetInputBlackLevel;
        vt.SetInputBlackLevel = SetInputBlackLevel;
        vt.GetInputGrayLevel = GetInputGrayLevel;
        vt.GetInvInputGrayLevel = GetInvInputGrayLevel;
        vt.SetInputGrayLevel = SetInputGrayLevel;
        vt.GetInputWhiteLevel = GetInputWhiteLevel;
        vt.SetInputWhiteLevel = SetInputWhiteLevel;
        vt.GetInputMinRedLevel = GetInputMinRedLevel;
        vt.SetInputMinRedLevel = SetInputMinRedLevel;
        vt.GetInputRedGrayLevel = GetInputRedGrayLevel;
        vt.GetInvInputRedGrayLevel = GetInvInputRedGrayLevel;
        vt.SetInputRedGrayLevel = SetInputRedGrayLevel;
        vt.GetInputMaxRedLevel = GetInputMaxRedLevel;
        vt.SetInputMaxRedLevel = SetInputMaxRedLevel;
        vt.GetInputMinGreenLevel = GetInputMinGreenLevel;
        vt.SetInputMinGreenLevel = SetInputMinGreenLevel;
        vt.GetInputGreenGrayLevel = GetInputGreenGrayLevel;
        vt.GetInvInputGreenGrayLevel = GetInvInputGreenGrayLevel;
        vt.SetInputGreenGrayLevel = SetInputGreenGrayLevel;
        vt.GetInputMaxGreenLevel = GetInputMaxGreenLevel;
        vt.SetInputMaxGreenLevel = SetInputMaxGreenLevel;
        vt.GetInputMinBlueLevel = GetInputMinBlueLevel;
        vt.SetInputMinBlueLevel = SetInputMinBlueLevel;
        vt.GetInputBlueGrayLevel = GetInputBlueGrayLevel;
        vt.GetInvInputBlueGrayLevel = GetInvInputBlueGrayLevel;
        vt.SetInputBlueGrayLevel = SetInputBlueGrayLevel;
        vt.GetInputMaxBlueLevel = GetInputMaxBlueLevel;
        vt.SetInputMaxBlueLevel = SetInputMaxBlueLevel;
        vt.GetExpType = GetExpType;
        vt.SetExpType = SetExpType;
        vt.GetISO = GetISO;
        vt.SetISO = SetISO;
        vt.GetToneMap = GetToneMap;
        vt.SetToneMap = SetToneMap;
        vt.GetToneAmt = GetToneAmt;
        vt.SetToneAmt = SetToneAmt;
        vt.GetHueOffset = GetHueOffset;
        vt.SetHueOffset = SetHueOffset;
        vt.GetSaturation = GetSaturation;
        vt.SetSaturation = SetSaturation;
        vt.GetColorization = GetColorization;
        vt.SetColorization = SetColorization;
        vt.GetTargetColor = GetTargetColor;
        vt.SetTargetColor = SetTargetColor;
        vt.GetOutputBlackLevel = GetOutputBlackLevel;
        vt.SetOutputBlackLevel = SetOutputBlackLevel;
        vt.GetOutputWhiteLevel = GetOutputWhiteLevel;
        vt.SetOutputWhiteLevel = SetOutputWhiteLevel;
        vt.GetOutputMinRedLevel = GetOutputMinRedLevel;
        vt.SetOutputMinRedLevel = SetOutputMinRedLevel;
        vt.GetOutputMaxRedLevel = GetOutputMaxRedLevel;
        vt.SetOutputMaxRedLevel = SetOutputMaxRedLevel;
        vt.GetOutputMinGreenLevel = GetOutputMinGreenLevel;
        vt.SetOutputMinGreenLevel = SetOutputMinGreenLevel;
        vt.GetOutputMaxGreenLevel = GetOutputMaxGreenLevel;
        vt.SetOutputMaxGreenLevel = SetOutputMaxGreenLevel;
        vt.GetOutputMinBlueLevel = GetOutputMinBlueLevel;
        vt.SetOutputMinBlueLevel = SetOutputMinBlueLevel;
        vt.GetOutputMaxBlueLevel = GetOutputMaxBlueLevel;
        vt.SetOutputMaxBlueLevel = SetOutputMaxBlueLevel;
        vt.GetOutputGamma = GetOutputGamma;
        vt.GetOutputInvGamma = GetOutputInvGamma;
        vt.SetOutputGamma = SetOutputGamma;
        vt.GetOutputColorspace = GetOutputColorspace;
        vt.SetOutputColorspace = SetOutputColorspace;
        vt.GetOutputColormapping = GetOutputColormapping;
        vt.SetOutputColormapping = SetOutputColormapping;
        vt.AddAttribute = AddAttribute;
        vt.RenderProcessAllocate = RenderProcessAllocate;
        vt.RenderProcessDeallocate = RenderProcessDeallocate;
        vTable = &vt.iunk;
        iid = &lx::guid_FrameBuffer;
    }

    static auto Allocate(LXtObjectID wcom,const char *name,LXtObjectID item,const char *identity,const char *userName,int isFactoryName,int writeBucketsToDisk) -> ILxBufferID
    {
        LXCWxINST (CLxImpl_FrameBuffer, loc);
        return loc->fbuf_Allocate( name,(ILxUnknownID) item, identity, userName, isFactoryName, writeBucketsToDisk);
    }

    static auto IsStereo(LXtObjectID wcom,int *isStereo) -> LxResult
    {
        LXCWxINST (CLxImpl_FrameBuffer, loc);
        try
        {
           return loc->fbuf_IsStereo( isStereo);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto GetStereoEyeDisplay(LXtObjectID wcom,LXtStereoEye *eyeDisplay) -> LxResult
    {
        LXCWxINST (CLxImpl_FrameBuffer, loc);
        try
        {
           return loc->fbuf_GetStereoEyeDisplay( eyeDisplay);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SetStereoEyeDisplay(LXtObjectID wcom,LXtStereoEye eyeDisplay) -> LxResult
    {
        LXCWxINST (CLxImpl_FrameBuffer, loc);
        try
        {
           return loc->fbuf_SetStereoEyeDisplay( eyeDisplay);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto GetStereoComposite(LXtObjectID wcom,LXtStereoComposite *composite) -> LxResult
    {
        LXCWxINST (CLxImpl_FrameBuffer, loc);
        try
        {
           return loc->fbuf_GetStereoComposite( composite);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SetStereoComposite(LXtObjectID wcom,LXtStereoComposite composite) -> LxResult
    {
        LXCWxINST (CLxImpl_FrameBuffer, loc);
        try
        {
           return loc->fbuf_SetStereoComposite( composite);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SetEyeSide(LXtObjectID wcom,int eyeSide) -> LxResult
    {
        LXCWxINST (CLxImpl_FrameBuffer, loc);
        try
        {
           return loc->fbuf_SetEyeSide( eyeSide);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto GetLineBuffer(LXtObjectID wcom,float **buf) -> LxResult
    {
        LXCWxINST (CLxImpl_FrameBuffer, loc);
        try
        {
           return loc->fbuf_GetLineBuffer( buf);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto CreateFrameBufferTargetImage(LXtObjectID wcom,LXtPixelFormat type,int w,int h,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_FrameBuffer, loc);
        try
        {
           return loc->fbuf_CreateFrameBufferTargetImage( type, w, h, ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto GetRenderPassName(LXtObjectID wcom,char *name) -> LxResult
    {
        LXCWxINST (CLxImpl_FrameBuffer, loc);
        try
        {
           return loc->fbuf_GetRenderPassName( name);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SetRenderPassName(LXtObjectID wcom,const char *name) -> LxResult
    {
        LXCWxINST (CLxImpl_FrameBuffer, loc);
        try
        {
           return loc->fbuf_SetRenderPassName( name);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto BucketsOnDisk(LXtObjectID wcom,int index) -> unsigned int
    {
        LXCWxINST (CLxImpl_FrameBuffer, loc);
        return loc->fbuf_BucketsOnDisk( index);
    }

    static auto Lookup(LXtObjectID wcom,const char *name,LXtObjectID item) -> LXtObjectID
    {
        LXCWxINST (CLxImpl_FrameBuffer, loc);
        return loc->fbuf_Lookup( name,(ILxUnknownID) item);
    }

    static auto LookupByIdentity(LXtObjectID wcom,const char *identity) -> LXtObjectID
    {
        LXCWxINST (CLxImpl_FrameBuffer, loc);
        return loc->fbuf_LookupByIdentity( identity);
    }

    static auto Count(LXtObjectID wcom) -> unsigned int
    {
        LXCWxINST (CLxImpl_FrameBuffer, loc);
        return loc->fbuf_Count();
    }

    static auto ByIndex(LXtObjectID wcom,int index) -> LXtObjectID
    {
        LXCWxINST (CLxImpl_FrameBuffer, loc);
        return loc->fbuf_ByIndex( index);
    }

    static auto Alpha(LXtObjectID wcom,int index) -> LXtObjectID
    {
        LXCWxINST (CLxImpl_FrameBuffer, loc);
        return loc->fbuf_Alpha( index);
    }

    static auto AlphaIndex(LXtObjectID wcom,int index) -> int
    {
        LXCWxINST (CLxImpl_FrameBuffer, loc);
        return loc->fbuf_AlphaIndex( index);
    }

    static auto Size(LXtObjectID wcom,int index,int *width,int *height) -> LxResult
    {
        LXCWxINST (CLxImpl_FrameBuffer, loc);
        try
        {
           return loc->fbuf_Size( index, width, height);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto AreaProcessingActive(LXtObjectID wcom,int bufferIndex,int *active) -> LxResult
    {
        LXCWxINST (CLxImpl_FrameBuffer, loc);
        try
        {
           return loc->fbuf_AreaProcessingActive( bufferIndex, active);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto GetSaveProcessed(LXtObjectID wcom,int bufferIndex) -> int
    {
        LXCWxINST (CLxImpl_FrameBuffer, loc);
        return loc->fbuf_GetSaveProcessed( bufferIndex);
    }

    static auto SetSaveProcessed(LXtObjectID wcom,int bufferIndex,int enabled) -> LxResult
    {
        LXCWxINST (CLxImpl_FrameBuffer, loc);
        try
        {
           return loc->fbuf_SetSaveProcessed( bufferIndex, enabled);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto GetBloomEnabled(LXtObjectID wcom,int bufferIndex) -> int
    {
        LXCWxINST (CLxImpl_FrameBuffer, loc);
        return loc->fbuf_GetBloomEnabled( bufferIndex);
    }

    static auto SetBloomEnabled(LXtObjectID wcom,int bufferIndex,int enabled) -> LxResult
    {
        LXCWxINST (CLxImpl_FrameBuffer, loc);
        try
        {
           return loc->fbuf_SetBloomEnabled( bufferIndex, enabled);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto GetBloomThreshold(LXtObjectID wcom,int bufferIndex) -> double
    {
        LXCWxINST (CLxImpl_FrameBuffer, loc);
        return loc->fbuf_GetBloomThreshold( bufferIndex);
    }

    static auto SetBloomThreshold(LXtObjectID wcom,int bufferIndex,double threshold) -> LxResult
    {
        LXCWxINST (CLxImpl_FrameBuffer, loc);
        try
        {
           return loc->fbuf_SetBloomThreshold( bufferIndex, threshold);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto GetBloomRadius(LXtObjectID wcom,int bufferIndex) -> double
    {
        LXCWxINST (CLxImpl_FrameBuffer, loc);
        return loc->fbuf_GetBloomRadius( bufferIndex);
    }

    static auto SetBloomRadius(LXtObjectID wcom,int bufferIndex,double radius) -> LxResult
    {
        LXCWxINST (CLxImpl_FrameBuffer, loc);
        try
        {
           return loc->fbuf_SetBloomRadius( bufferIndex, radius);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto GetVignetteAmount(LXtObjectID wcom,int bufferIndex) -> double
    {
        LXCWxINST (CLxImpl_FrameBuffer, loc);
        return loc->fbuf_GetVignetteAmount( bufferIndex);
    }

    static auto SetVignetteAmount(LXtObjectID wcom,int bufferIndex,double radius) -> LxResult
    {
        LXCWxINST (CLxImpl_FrameBuffer, loc);
        try
        {
           return loc->fbuf_SetVignetteAmount( bufferIndex, radius);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto GetInputBlackLevel(LXtObjectID wcom,int bufferIndex) -> double
    {
        LXCWxINST (CLxImpl_FrameBuffer, loc);
        return loc->fbuf_GetInputBlackLevel( bufferIndex);
    }

    static auto SetInputBlackLevel(LXtObjectID wcom,int bufferIndex,double blackLevel) -> LxResult
    {
        LXCWxINST (CLxImpl_FrameBuffer, loc);
        try
        {
           return loc->fbuf_SetInputBlackLevel( bufferIndex, blackLevel);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto GetInputGrayLevel(LXtObjectID wcom,int bufferIndex) -> double
    {
        LXCWxINST (CLxImpl_FrameBuffer, loc);
        return loc->fbuf_GetInputGrayLevel( bufferIndex);
    }

    static auto GetInvInputGrayLevel(LXtObjectID wcom,int bufferIndex) -> double
    {
        LXCWxINST (CLxImpl_FrameBuffer, loc);
        return loc->fbuf_GetInvInputGrayLevel( bufferIndex);
    }

    static auto SetInputGrayLevel(LXtObjectID wcom,int bufferIndex,double gamma) -> LxResult
    {
        LXCWxINST (CLxImpl_FrameBuffer, loc);
        try
        {
           return loc->fbuf_SetInputGrayLevel( bufferIndex, gamma);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto GetInputWhiteLevel(LXtObjectID wcom,int bufferIndex) -> double
    {
        LXCWxINST (CLxImpl_FrameBuffer, loc);
        return loc->fbuf_GetInputWhiteLevel( bufferIndex);
    }

    static auto SetInputWhiteLevel(LXtObjectID wcom,int bufferIndex,double whiteLevel) -> LxResult
    {
        LXCWxINST (CLxImpl_FrameBuffer, loc);
        try
        {
           return loc->fbuf_SetInputWhiteLevel( bufferIndex, whiteLevel);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto GetInputMinRedLevel(LXtObjectID wcom,int bufferIndex) -> double
    {
        LXCWxINST (CLxImpl_FrameBuffer, loc);
        return loc->fbuf_GetInputMinRedLevel( bufferIndex);
    }

    static auto SetInputMinRedLevel(LXtObjectID wcom,int bufferIndex,double level) -> LxResult
    {
        LXCWxINST (CLxImpl_FrameBuffer, loc);
        try
        {
           return loc->fbuf_SetInputMinRedLevel( bufferIndex, level);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto GetInputRedGrayLevel(LXtObjectID wcom,int bufferIndex) -> double
    {
        LXCWxINST (CLxImpl_FrameBuffer, loc);
        return loc->fbuf_GetInputRedGrayLevel( bufferIndex);
    }

    static auto GetInvInputRedGrayLevel(LXtObjectID wcom,int bufferIndex) -> double
    {
        LXCWxINST (CLxImpl_FrameBuffer, loc);
        return loc->fbuf_GetInvInputRedGrayLevel( bufferIndex);
    }

    static auto SetInputRedGrayLevel(LXtObjectID wcom,int bufferIndex,double gamma) -> LxResult
    {
        LXCWxINST (CLxImpl_FrameBuffer, loc);
        try
        {
           return loc->fbuf_SetInputRedGrayLevel( bufferIndex, gamma);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto GetInputMaxRedLevel(LXtObjectID wcom,int bufferIndex) -> double
    {
        LXCWxINST (CLxImpl_FrameBuffer, loc);
        return loc->fbuf_GetInputMaxRedLevel( bufferIndex);
    }

    static auto SetInputMaxRedLevel(LXtObjectID wcom,int bufferIndex,double level) -> LxResult
    {
        LXCWxINST (CLxImpl_FrameBuffer, loc);
        try
        {
           return loc->fbuf_SetInputMaxRedLevel( bufferIndex, level);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto GetInputMinGreenLevel(LXtObjectID wcom,int bufferIndex) -> double
    {
        LXCWxINST (CLxImpl_FrameBuffer, loc);
        return loc->fbuf_GetInputMinGreenLevel( bufferIndex);
    }

    static auto SetInputMinGreenLevel(LXtObjectID wcom,int bufferIndex,double level) -> LxResult
    {
        LXCWxINST (CLxImpl_FrameBuffer, loc);
        try
        {
           return loc->fbuf_SetInputMinGreenLevel( bufferIndex, level);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto GetInputGreenGrayLevel(LXtObjectID wcom,int bufferIndex) -> double
    {
        LXCWxINST (CLxImpl_FrameBuffer, loc);
        return loc->fbuf_GetInputGreenGrayLevel( bufferIndex);
    }

    static auto GetInvInputGreenGrayLevel(LXtObjectID wcom,int bufferIndex) -> double
    {
        LXCWxINST (CLxImpl_FrameBuffer, loc);
        return loc->fbuf_GetInvInputGreenGrayLevel( bufferIndex);
    }

    static auto SetInputGreenGrayLevel(LXtObjectID wcom,int bufferIndex,double gamma) -> LxResult
    {
        LXCWxINST (CLxImpl_FrameBuffer, loc);
        try
        {
           return loc->fbuf_SetInputGreenGrayLevel( bufferIndex, gamma);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto GetInputMaxGreenLevel(LXtObjectID wcom,int bufferIndex) -> double
    {
        LXCWxINST (CLxImpl_FrameBuffer, loc);
        return loc->fbuf_GetInputMaxGreenLevel( bufferIndex);
    }

    static auto SetInputMaxGreenLevel(LXtObjectID wcom,int bufferIndex,double level) -> LxResult
    {
        LXCWxINST (CLxImpl_FrameBuffer, loc);
        try
        {
           return loc->fbuf_SetInputMaxGreenLevel( bufferIndex, level);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto GetInputMinBlueLevel(LXtObjectID wcom,int bufferIndex) -> double
    {
        LXCWxINST (CLxImpl_FrameBuffer, loc);
        return loc->fbuf_GetInputMinBlueLevel( bufferIndex);
    }

    static auto SetInputMinBlueLevel(LXtObjectID wcom,int bufferIndex,double level) -> LxResult
    {
        LXCWxINST (CLxImpl_FrameBuffer, loc);
        try
        {
           return loc->fbuf_SetInputMinBlueLevel( bufferIndex, level);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto GetInputBlueGrayLevel(LXtObjectID wcom,int bufferIndex) -> double
    {
        LXCWxINST (CLxImpl_FrameBuffer, loc);
        return loc->fbuf_GetInputBlueGrayLevel( bufferIndex);
    }

    static auto GetInvInputBlueGrayLevel(LXtObjectID wcom,int bufferIndex) -> double
    {
        LXCWxINST (CLxImpl_FrameBuffer, loc);
        return loc->fbuf_GetInvInputBlueGrayLevel( bufferIndex);
    }

    static auto SetInputBlueGrayLevel(LXtObjectID wcom,int bufferIndex,double gamma) -> LxResult
    {
        LXCWxINST (CLxImpl_FrameBuffer, loc);
        try
        {
           return loc->fbuf_SetInputBlueGrayLevel( bufferIndex, gamma);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto GetInputMaxBlueLevel(LXtObjectID wcom,int bufferIndex) -> double
    {
        LXCWxINST (CLxImpl_FrameBuffer, loc);
        return loc->fbuf_GetInputMaxBlueLevel( bufferIndex);
    }

    static auto SetInputMaxBlueLevel(LXtObjectID wcom,int bufferIndex,double level) -> LxResult
    {
        LXCWxINST (CLxImpl_FrameBuffer, loc);
        try
        {
           return loc->fbuf_SetInputMaxBlueLevel( bufferIndex, level);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto GetExpType(LXtObjectID wcom,int bufferIndex) -> int
    {
        LXCWxINST (CLxImpl_FrameBuffer, loc);
        return loc->fbuf_GetExpType( bufferIndex);
    }

    static auto SetExpType(LXtObjectID wcom,int bufferIndex,int expType) -> LxResult
    {
        LXCWxINST (CLxImpl_FrameBuffer, loc);
        try
        {
           return loc->fbuf_SetExpType( bufferIndex, expType);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto GetISO(LXtObjectID wcom,int bufferIndex) -> double
    {
        LXCWxINST (CLxImpl_FrameBuffer, loc);
        return loc->fbuf_GetISO( bufferIndex);
    }

    static auto SetISO(LXtObjectID wcom,int bufferIndex,double iso) -> LxResult
    {
        LXCWxINST (CLxImpl_FrameBuffer, loc);
        try
        {
           return loc->fbuf_SetISO( bufferIndex, iso);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto GetToneMap(LXtObjectID wcom,int bufferIndex) -> int
    {
        LXCWxINST (CLxImpl_FrameBuffer, loc);
        return loc->fbuf_GetToneMap( bufferIndex);
    }

    static auto SetToneMap(LXtObjectID wcom,int bufferIndex,int toneMap) -> LxResult
    {
        LXCWxINST (CLxImpl_FrameBuffer, loc);
        try
        {
           return loc->fbuf_SetToneMap( bufferIndex, toneMap);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto GetToneAmt(LXtObjectID wcom,int bufferIndex) -> double
    {
        LXCWxINST (CLxImpl_FrameBuffer, loc);
        return loc->fbuf_GetToneAmt( bufferIndex);
    }

    static auto SetToneAmt(LXtObjectID wcom,int bufferIndex,double toneAmt) -> LxResult
    {
        LXCWxINST (CLxImpl_FrameBuffer, loc);
        try
        {
           return loc->fbuf_SetToneAmt( bufferIndex, toneAmt);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto GetHueOffset(LXtObjectID wcom,int bufferIndex) -> double
    {
        LXCWxINST (CLxImpl_FrameBuffer, loc);
        return loc->fbuf_GetHueOffset( bufferIndex);
    }

    static auto SetHueOffset(LXtObjectID wcom,int bufferIndex,double hueOffset) -> LxResult
    {
        LXCWxINST (CLxImpl_FrameBuffer, loc);
        try
        {
           return loc->fbuf_SetHueOffset( bufferIndex, hueOffset);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto GetSaturation(LXtObjectID wcom,int bufferIndex) -> double
    {
        LXCWxINST (CLxImpl_FrameBuffer, loc);
        return loc->fbuf_GetSaturation( bufferIndex);
    }

    static auto SetSaturation(LXtObjectID wcom,int bufferIndex,double saturation) -> LxResult
    {
        LXCWxINST (CLxImpl_FrameBuffer, loc);
        try
        {
           return loc->fbuf_SetSaturation( bufferIndex, saturation);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto GetColorization(LXtObjectID wcom,int bufferIndex) -> double
    {
        LXCWxINST (CLxImpl_FrameBuffer, loc);
        return loc->fbuf_GetColorization( bufferIndex);
    }

    static auto SetColorization(LXtObjectID wcom,int bufferIndex,double colorization) -> LxResult
    {
        LXCWxINST (CLxImpl_FrameBuffer, loc);
        try
        {
           return loc->fbuf_SetColorization( bufferIndex, colorization);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto GetTargetColor(LXtObjectID wcom,int bufferIndex,double *color) -> void
    {
        LXCWxINST (CLxImpl_FrameBuffer, loc);
        loc->fbuf_GetTargetColor( bufferIndex, color);
    }

    static auto SetTargetColor(LXtObjectID wcom,int bufferIndex,const double *color) -> LxResult
    {
        LXCWxINST (CLxImpl_FrameBuffer, loc);
        try
        {
           return loc->fbuf_SetTargetColor( bufferIndex, color);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto GetOutputBlackLevel(LXtObjectID wcom,int bufferIndex) -> double
    {
        LXCWxINST (CLxImpl_FrameBuffer, loc);
        return loc->fbuf_GetOutputBlackLevel( bufferIndex);
    }

    static auto SetOutputBlackLevel(LXtObjectID wcom,int bufferIndex,double blackLevel) -> LxResult
    {
        LXCWxINST (CLxImpl_FrameBuffer, loc);
        try
        {
           return loc->fbuf_SetOutputBlackLevel( bufferIndex, blackLevel);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto GetOutputWhiteLevel(LXtObjectID wcom,int bufferIndex) -> double
    {
        LXCWxINST (CLxImpl_FrameBuffer, loc);
        return loc->fbuf_GetOutputWhiteLevel( bufferIndex);
    }

    static auto SetOutputWhiteLevel(LXtObjectID wcom,int bufferIndex,double whiteLevel) -> LxResult
    {
        LXCWxINST (CLxImpl_FrameBuffer, loc);
        try
        {
           return loc->fbuf_SetOutputWhiteLevel( bufferIndex, whiteLevel);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto GetOutputMinRedLevel(LXtObjectID wcom,int bufferIndex) -> double
    {
        LXCWxINST (CLxImpl_FrameBuffer, loc);
        return loc->fbuf_GetOutputMinRedLevel( bufferIndex);
    }

    static auto SetOutputMinRedLevel(LXtObjectID wcom,int bufferIndex,double blackLevel) -> LxResult
    {
        LXCWxINST (CLxImpl_FrameBuffer, loc);
        try
        {
           return loc->fbuf_SetOutputMinRedLevel( bufferIndex, blackLevel);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto GetOutputMaxRedLevel(LXtObjectID wcom,int bufferIndex) -> double
    {
        LXCWxINST (CLxImpl_FrameBuffer, loc);
        return loc->fbuf_GetOutputMaxRedLevel( bufferIndex);
    }

    static auto SetOutputMaxRedLevel(LXtObjectID wcom,int bufferIndex,double whiteLevel) -> LxResult
    {
        LXCWxINST (CLxImpl_FrameBuffer, loc);
        try
        {
           return loc->fbuf_SetOutputMaxRedLevel( bufferIndex, whiteLevel);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto GetOutputMinGreenLevel(LXtObjectID wcom,int bufferIndex) -> double
    {
        LXCWxINST (CLxImpl_FrameBuffer, loc);
        return loc->fbuf_GetOutputMinGreenLevel( bufferIndex);
    }

    static auto SetOutputMinGreenLevel(LXtObjectID wcom,int bufferIndex,double blackLevel) -> LxResult
    {
        LXCWxINST (CLxImpl_FrameBuffer, loc);
        try
        {
           return loc->fbuf_SetOutputMinGreenLevel( bufferIndex, blackLevel);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto GetOutputMaxGreenLevel(LXtObjectID wcom,int bufferIndex) -> double
    {
        LXCWxINST (CLxImpl_FrameBuffer, loc);
        return loc->fbuf_GetOutputMaxGreenLevel( bufferIndex);
    }

    static auto SetOutputMaxGreenLevel(LXtObjectID wcom,int bufferIndex,double whiteLevel) -> LxResult
    {
        LXCWxINST (CLxImpl_FrameBuffer, loc);
        try
        {
           return loc->fbuf_SetOutputMaxGreenLevel( bufferIndex, whiteLevel);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto GetOutputMinBlueLevel(LXtObjectID wcom,int bufferIndex) -> double
    {
        LXCWxINST (CLxImpl_FrameBuffer, loc);
        return loc->fbuf_GetOutputMinBlueLevel( bufferIndex);
    }

    static auto SetOutputMinBlueLevel(LXtObjectID wcom,int bufferIndex,double blackLevel) -> LxResult
    {
        LXCWxINST (CLxImpl_FrameBuffer, loc);
        try
        {
           return loc->fbuf_SetOutputMinBlueLevel( bufferIndex, blackLevel);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto GetOutputMaxBlueLevel(LXtObjectID wcom,int bufferIndex) -> double
    {
        LXCWxINST (CLxImpl_FrameBuffer, loc);
        return loc->fbuf_GetOutputMaxBlueLevel( bufferIndex);
    }

    static auto SetOutputMaxBlueLevel(LXtObjectID wcom,int bufferIndex,double whiteLevel) -> LxResult
    {
        LXCWxINST (CLxImpl_FrameBuffer, loc);
        try
        {
           return loc->fbuf_SetOutputMaxBlueLevel( bufferIndex, whiteLevel);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto GetOutputGamma(LXtObjectID wcom,int bufferIndex) -> double
    {
        LXCWxINST (CLxImpl_FrameBuffer, loc);
        return loc->fbuf_GetOutputGamma( bufferIndex);
    }

    static auto GetOutputInvGamma(LXtObjectID wcom,int bufferIndex) -> double
    {
        LXCWxINST (CLxImpl_FrameBuffer, loc);
        return loc->fbuf_GetOutputInvGamma( bufferIndex);
    }

    static auto SetOutputGamma(LXtObjectID wcom,int bufferIndex,double gamma) -> LxResult
    {
        LXCWxINST (CLxImpl_FrameBuffer, loc);
        try
        {
           return loc->fbuf_SetOutputGamma( bufferIndex, gamma);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto GetOutputColorspace(LXtObjectID wcom,int bufferIndex) -> const char*
    {
        LXCWxINST (CLxImpl_FrameBuffer, loc);
        return loc->fbuf_GetOutputColorspace( bufferIndex);
    }

    static auto SetOutputColorspace(LXtObjectID wcom,const char* colorspace) -> LxResult
    {
        LXCWxINST (CLxImpl_FrameBuffer, loc);
        try
        {
           return loc->fbuf_SetOutputColorspace( colorspace);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto GetOutputColormapping(LXtObjectID wcom,int bufferIndex) -> ILxColorMappingID
    {
        LXCWxINST (CLxImpl_FrameBuffer, loc);
        return loc->fbuf_GetOutputColormapping( bufferIndex);
    }

    static auto SetOutputColormapping(LXtObjectID wcom,LXtObjectID colormapping) -> LxResult
    {
        LXCWxINST (CLxImpl_FrameBuffer, loc);
        try
        {
           return loc->fbuf_SetOutputColormapping((ILxUnknownID) colormapping);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto AddAttribute(LXtObjectID wcom,const char *name,const char *type,unsigned *index) -> LxResult
    {
        LXCWxINST (CLxImpl_FrameBuffer, loc);
        try
        {
           return loc->fbuf_AddAttribute( name, type, index);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto RenderProcessAllocate(LXtObjectID wcom,int bufferIndex,LXtRenderOutputProcess **rndrProcess) -> LxResult
    {
        LXCWxINST (CLxImpl_FrameBuffer, loc);
        try
        {
           return loc->fbuf_RenderProcessAllocate( bufferIndex, rndrProcess);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto RenderProcessDeallocate(LXtObjectID wcom,LXtRenderOutputProcess **rndrProcess) -> LxResult
    {
        LXCWxINST (CLxImpl_FrameBuffer, loc);
        try
        {
           return loc->fbuf_RenderProcessDeallocate( rndrProcess);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxFrameBuffer vt;
};

class CLxLoc_FrameBuffer : public CLxLocalize<ILxFrameBufferID>
{
public:
    CLxLoc_FrameBuffer()
    {
        _init();
    }

    CLxLoc_FrameBuffer(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_FrameBuffer(CLxLoc_FrameBuffer const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_FrameBuffer;
    }

    auto Allocate(const char *name, ILxUnknownID item, const char *identity, const char *userName, int isFactoryName, int writeBucketsToDisk) -> ILxBufferID
    {
        return m_loc[0]->Allocate(m_loc, name,(ILxUnknownID) item, identity, userName, isFactoryName, writeBucketsToDisk);
    }

    auto IsStereo(int *isStereo) const -> LxResult
    {
        return m_loc[0]->IsStereo(m_loc, isStereo);
    }

    auto GetStereoEyeDisplay(LXtStereoEye *eyeDisplay) const -> LxResult
    {
        return m_loc[0]->GetStereoEyeDisplay(m_loc, eyeDisplay);
    }

    auto SetStereoEyeDisplay(LXtStereoEye eyeDisplay) -> LxResult
    {
        return m_loc[0]->SetStereoEyeDisplay(m_loc, eyeDisplay);
    }

    auto GetStereoComposite(LXtStereoComposite *composite) const -> LxResult
    {
        return m_loc[0]->GetStereoComposite(m_loc, composite);
    }

    auto SetStereoComposite(LXtStereoComposite composite) -> LxResult
    {
        return m_loc[0]->SetStereoComposite(m_loc, composite);
    }

    auto SetEyeSide(int eyeSide) -> LxResult
    {
        return m_loc[0]->SetEyeSide(m_loc, eyeSide);
    }

    auto GetLineBuffer(float **buf) -> LxResult
    {
        return m_loc[0]->GetLineBuffer(m_loc, buf);
    }

    auto CreateFrameBufferTargetImage(LXtPixelFormat type, int w, int h, void **ppvObj) -> LxResult
    {
        return m_loc[0]->CreateFrameBufferTargetImage(m_loc, type, w, h, ppvObj);
    }

    auto CreateFrameBufferTargetImage(LXtPixelFormat type, int w, int h, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->CreateFrameBufferTargetImage(m_loc, type, w, h, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto GetRenderPassName(char *name) -> LxResult
    {
        return m_loc[0]->GetRenderPassName(m_loc, name);
    }

    auto SetRenderPassName(const char *name) -> LxResult
    {
        return m_loc[0]->SetRenderPassName(m_loc, name);
    }

    auto BucketsOnDisk(int index) -> unsigned int
    {
        return m_loc[0]->BucketsOnDisk(m_loc, index);
    }

    auto Lookup(const char *name, ILxUnknownID item) const -> ILxUnknownID
    {
        return (ILxUnknownID)m_loc[0]->Lookup(m_loc, name,(ILxUnknownID) item);
    }

    auto LookupByIdentity(const char *identity) -> ILxUnknownID
    {
        return (ILxUnknownID)m_loc[0]->LookupByIdentity(m_loc, identity);
    }

    auto Count(void) const -> unsigned int
    {
        return m_loc[0]->Count(m_loc);
    }

    auto ByIndex(int index) const -> ILxUnknownID
    {
        return (ILxUnknownID)m_loc[0]->ByIndex(m_loc, index);
    }

    auto Alpha(int index) const -> ILxUnknownID
    {
        return (ILxUnknownID)m_loc[0]->Alpha(m_loc, index);
    }

    auto AlphaIndex(int index) -> int
    {
        return m_loc[0]->AlphaIndex(m_loc, index);
    }

    auto Size(int index, int *width, int *height) -> LxResult
    {
        return m_loc[0]->Size(m_loc, index, width, height);
    }

    auto AreaProcessingActive(int bufferIndex, int *active) -> LxResult
    {
        return m_loc[0]->AreaProcessingActive(m_loc, bufferIndex, active);
    }

    auto GetSaveProcessed(int bufferIndex) -> int
    {
        return m_loc[0]->GetSaveProcessed(m_loc, bufferIndex);
    }

    auto SetSaveProcessed(int bufferIndex, int enabled) -> LxResult
    {
        return m_loc[0]->SetSaveProcessed(m_loc, bufferIndex, enabled);
    }

    auto GetBloomEnabled(int bufferIndex) -> int
    {
        return m_loc[0]->GetBloomEnabled(m_loc, bufferIndex);
    }

    auto SetBloomEnabled(int bufferIndex, int enabled) -> LxResult
    {
        return m_loc[0]->SetBloomEnabled(m_loc, bufferIndex, enabled);
    }

    auto GetBloomThreshold(int bufferIndex) -> double
    {
        return m_loc[0]->GetBloomThreshold(m_loc, bufferIndex);
    }

    auto SetBloomThreshold(int bufferIndex, double threshold) -> LxResult
    {
        return m_loc[0]->SetBloomThreshold(m_loc, bufferIndex, threshold);
    }

    auto GetBloomRadius(int bufferIndex) -> double
    {
        return m_loc[0]->GetBloomRadius(m_loc, bufferIndex);
    }

    auto SetBloomRadius(int bufferIndex, double radius) -> LxResult
    {
        return m_loc[0]->SetBloomRadius(m_loc, bufferIndex, radius);
    }

    auto GetVignetteAmount(int bufferIndex) -> double
    {
        return m_loc[0]->GetVignetteAmount(m_loc, bufferIndex);
    }

    auto SetVignetteAmount(int bufferIndex, double radius) -> LxResult
    {
        return m_loc[0]->SetVignetteAmount(m_loc, bufferIndex, radius);
    }

    auto GetInputBlackLevel(int bufferIndex) -> double
    {
        return m_loc[0]->GetInputBlackLevel(m_loc, bufferIndex);
    }

    auto SetInputBlackLevel(int bufferIndex, double blackLevel) -> LxResult
    {
        return m_loc[0]->SetInputBlackLevel(m_loc, bufferIndex, blackLevel);
    }

    auto GetInputGrayLevel(int bufferIndex) -> double
    {
        return m_loc[0]->GetInputGrayLevel(m_loc, bufferIndex);
    }

    auto GetInvInputGrayLevel(int bufferIndex) -> double
    {
        return m_loc[0]->GetInvInputGrayLevel(m_loc, bufferIndex);
    }

    auto SetInputGrayLevel(int bufferIndex, double gamma) -> LxResult
    {
        return m_loc[0]->SetInputGrayLevel(m_loc, bufferIndex, gamma);
    }

    auto GetInputWhiteLevel(int bufferIndex) -> double
    {
        return m_loc[0]->GetInputWhiteLevel(m_loc, bufferIndex);
    }

    auto SetInputWhiteLevel(int bufferIndex, double whiteLevel) -> LxResult
    {
        return m_loc[0]->SetInputWhiteLevel(m_loc, bufferIndex, whiteLevel);
    }

    auto GetInputMinRedLevel(int bufferIndex) -> double
    {
        return m_loc[0]->GetInputMinRedLevel(m_loc, bufferIndex);
    }

    auto SetInputMinRedLevel(int bufferIndex, double level) -> LxResult
    {
        return m_loc[0]->SetInputMinRedLevel(m_loc, bufferIndex, level);
    }

    auto GetInputRedGrayLevel(int bufferIndex) -> double
    {
        return m_loc[0]->GetInputRedGrayLevel(m_loc, bufferIndex);
    }

    auto GetInvInputRedGrayLevel(int bufferIndex) -> double
    {
        return m_loc[0]->GetInvInputRedGrayLevel(m_loc, bufferIndex);
    }

    auto SetInputRedGrayLevel(int bufferIndex, double gamma) -> LxResult
    {
        return m_loc[0]->SetInputRedGrayLevel(m_loc, bufferIndex, gamma);
    }

    auto GetInputMaxRedLevel(int bufferIndex) -> double
    {
        return m_loc[0]->GetInputMaxRedLevel(m_loc, bufferIndex);
    }

    auto SetInputMaxRedLevel(int bufferIndex, double level) -> LxResult
    {
        return m_loc[0]->SetInputMaxRedLevel(m_loc, bufferIndex, level);
    }

    auto GetInputMinGreenLevel(int bufferIndex) -> double
    {
        return m_loc[0]->GetInputMinGreenLevel(m_loc, bufferIndex);
    }

    auto SetInputMinGreenLevel(int bufferIndex, double level) -> LxResult
    {
        return m_loc[0]->SetInputMinGreenLevel(m_loc, bufferIndex, level);
    }

    auto GetInputGreenGrayLevel(int bufferIndex) -> double
    {
        return m_loc[0]->GetInputGreenGrayLevel(m_loc, bufferIndex);
    }

    auto GetInvInputGreenGrayLevel(int bufferIndex) -> double
    {
        return m_loc[0]->GetInvInputGreenGrayLevel(m_loc, bufferIndex);
    }

    auto SetInputGreenGrayLevel(int bufferIndex, double gamma) -> LxResult
    {
        return m_loc[0]->SetInputGreenGrayLevel(m_loc, bufferIndex, gamma);
    }

    auto GetInputMaxGreenLevel(int bufferIndex) -> double
    {
        return m_loc[0]->GetInputMaxGreenLevel(m_loc, bufferIndex);
    }

    auto SetInputMaxGreenLevel(int bufferIndex, double level) -> LxResult
    {
        return m_loc[0]->SetInputMaxGreenLevel(m_loc, bufferIndex, level);
    }

    auto GetInputMinBlueLevel(int bufferIndex) -> double
    {
        return m_loc[0]->GetInputMinBlueLevel(m_loc, bufferIndex);
    }

    auto SetInputMinBlueLevel(int bufferIndex, double level) -> LxResult
    {
        return m_loc[0]->SetInputMinBlueLevel(m_loc, bufferIndex, level);
    }

    auto GetInputBlueGrayLevel(int bufferIndex) -> double
    {
        return m_loc[0]->GetInputBlueGrayLevel(m_loc, bufferIndex);
    }

    auto GetInvInputBlueGrayLevel(int bufferIndex) -> double
    {
        return m_loc[0]->GetInvInputBlueGrayLevel(m_loc, bufferIndex);
    }

    auto SetInputBlueGrayLevel(int bufferIndex, double gamma) -> LxResult
    {
        return m_loc[0]->SetInputBlueGrayLevel(m_loc, bufferIndex, gamma);
    }

    auto GetInputMaxBlueLevel(int bufferIndex) -> double
    {
        return m_loc[0]->GetInputMaxBlueLevel(m_loc, bufferIndex);
    }

    auto SetInputMaxBlueLevel(int bufferIndex, double level) -> LxResult
    {
        return m_loc[0]->SetInputMaxBlueLevel(m_loc, bufferIndex, level);
    }

    auto GetExpType(int bufferIndex) -> int
    {
        return m_loc[0]->GetExpType(m_loc, bufferIndex);
    }

    auto SetExpType(int bufferIndex, int expType) -> LxResult
    {
        return m_loc[0]->SetExpType(m_loc, bufferIndex, expType);
    }

    auto GetISO(int bufferIndex) -> double
    {
        return m_loc[0]->GetISO(m_loc, bufferIndex);
    }

    auto SetISO(int bufferIndex, double iso) -> LxResult
    {
        return m_loc[0]->SetISO(m_loc, bufferIndex, iso);
    }

    auto GetToneMap(int bufferIndex) -> int
    {
        return m_loc[0]->GetToneMap(m_loc, bufferIndex);
    }

    auto SetToneMap(int bufferIndex, int toneMap) -> LxResult
    {
        return m_loc[0]->SetToneMap(m_loc, bufferIndex, toneMap);
    }

    auto GetToneAmt(int bufferIndex) -> double
    {
        return m_loc[0]->GetToneAmt(m_loc, bufferIndex);
    }

    auto SetToneAmt(int bufferIndex, double toneAmt) -> LxResult
    {
        return m_loc[0]->SetToneAmt(m_loc, bufferIndex, toneAmt);
    }

    auto GetHueOffset(int bufferIndex) -> double
    {
        return m_loc[0]->GetHueOffset(m_loc, bufferIndex);
    }

    auto SetHueOffset(int bufferIndex, double hueOffset) -> LxResult
    {
        return m_loc[0]->SetHueOffset(m_loc, bufferIndex, hueOffset);
    }

    auto GetSaturation(int bufferIndex) -> double
    {
        return m_loc[0]->GetSaturation(m_loc, bufferIndex);
    }

    auto SetSaturation(int bufferIndex, double saturation) -> LxResult
    {
        return m_loc[0]->SetSaturation(m_loc, bufferIndex, saturation);
    }

    auto GetColorization(int bufferIndex) -> double
    {
        return m_loc[0]->GetColorization(m_loc, bufferIndex);
    }

    auto SetColorization(int bufferIndex, double colorization) -> LxResult
    {
        return m_loc[0]->SetColorization(m_loc, bufferIndex, colorization);
    }

    auto GetTargetColor(int bufferIndex, double *color) -> void
    {
        m_loc[0]->GetTargetColor(m_loc, bufferIndex, color);
    }

    auto SetTargetColor(int bufferIndex, const double *color) -> LxResult
    {
        return m_loc[0]->SetTargetColor(m_loc, bufferIndex, color);
    }

    auto GetOutputBlackLevel(int bufferIndex) -> double
    {
        return m_loc[0]->GetOutputBlackLevel(m_loc, bufferIndex);
    }

    auto SetOutputBlackLevel(int bufferIndex, double blackLevel) -> LxResult
    {
        return m_loc[0]->SetOutputBlackLevel(m_loc, bufferIndex, blackLevel);
    }

    auto GetOutputWhiteLevel(int bufferIndex) -> double
    {
        return m_loc[0]->GetOutputWhiteLevel(m_loc, bufferIndex);
    }

    auto SetOutputWhiteLevel(int bufferIndex, double whiteLevel) -> LxResult
    {
        return m_loc[0]->SetOutputWhiteLevel(m_loc, bufferIndex, whiteLevel);
    }

    auto GetOutputMinRedLevel(int bufferIndex) -> double
    {
        return m_loc[0]->GetOutputMinRedLevel(m_loc, bufferIndex);
    }

    auto SetOutputMinRedLevel(int bufferIndex, double blackLevel) -> LxResult
    {
        return m_loc[0]->SetOutputMinRedLevel(m_loc, bufferIndex, blackLevel);
    }

    auto GetOutputMaxRedLevel(int bufferIndex) -> double
    {
        return m_loc[0]->GetOutputMaxRedLevel(m_loc, bufferIndex);
    }

    auto SetOutputMaxRedLevel(int bufferIndex, double whiteLevel) -> LxResult
    {
        return m_loc[0]->SetOutputMaxRedLevel(m_loc, bufferIndex, whiteLevel);
    }

    auto GetOutputMinGreenLevel(int bufferIndex) -> double
    {
        return m_loc[0]->GetOutputMinGreenLevel(m_loc, bufferIndex);
    }

    auto SetOutputMinGreenLevel(int bufferIndex, double blackLevel) -> LxResult
    {
        return m_loc[0]->SetOutputMinGreenLevel(m_loc, bufferIndex, blackLevel);
    }

    auto GetOutputMaxGreenLevel(int bufferIndex) -> double
    {
        return m_loc[0]->GetOutputMaxGreenLevel(m_loc, bufferIndex);
    }

    auto SetOutputMaxGreenLevel(int bufferIndex, double whiteLevel) -> LxResult
    {
        return m_loc[0]->SetOutputMaxGreenLevel(m_loc, bufferIndex, whiteLevel);
    }

    auto GetOutputMinBlueLevel(int bufferIndex) -> double
    {
        return m_loc[0]->GetOutputMinBlueLevel(m_loc, bufferIndex);
    }

    auto SetOutputMinBlueLevel(int bufferIndex, double blackLevel) -> LxResult
    {
        return m_loc[0]->SetOutputMinBlueLevel(m_loc, bufferIndex, blackLevel);
    }

    auto GetOutputMaxBlueLevel(int bufferIndex) -> double
    {
        return m_loc[0]->GetOutputMaxBlueLevel(m_loc, bufferIndex);
    }

    auto SetOutputMaxBlueLevel(int bufferIndex, double whiteLevel) -> LxResult
    {
        return m_loc[0]->SetOutputMaxBlueLevel(m_loc, bufferIndex, whiteLevel);
    }

    auto GetOutputGamma(int bufferIndex) -> double
    {
        return m_loc[0]->GetOutputGamma(m_loc, bufferIndex);
    }

    auto GetOutputInvGamma(int bufferIndex) -> double
    {
        return m_loc[0]->GetOutputInvGamma(m_loc, bufferIndex);
    }

    auto SetOutputGamma(int bufferIndex, double gamma) -> LxResult
    {
        return m_loc[0]->SetOutputGamma(m_loc, bufferIndex, gamma);
    }

    auto GetOutputColorspace(int bufferIndex) -> const char*
    {
        return m_loc[0]->GetOutputColorspace(m_loc, bufferIndex);
    }

    auto SetOutputColorspace(const char* colorspace) -> LxResult
    {
        return m_loc[0]->SetOutputColorspace(m_loc, colorspace);
    }

    auto GetOutputColormapping(int bufferIndex) -> ILxColorMappingID
    {
        return m_loc[0]->GetOutputColormapping(m_loc, bufferIndex);
    }

    auto SetOutputColormapping(ILxUnknownID colormapping) -> LxResult
    {
        return m_loc[0]->SetOutputColormapping(m_loc,(ILxUnknownID) colormapping);
    }

    auto AddAttribute(const char *name, const char *type, unsigned *index) -> LxResult
    {
        return m_loc[0]->AddAttribute(m_loc, name, type, index);
    }

    auto RenderProcessAllocate(int bufferIndex, LXtRenderOutputProcess **rndrProcess) -> LxResult
    {
        return m_loc[0]->RenderProcessAllocate(m_loc, bufferIndex, rndrProcess);
    }

    auto RenderProcessDeallocate(LXtRenderOutputProcess **rndrProcess) -> LxResult
    {
        return m_loc[0]->RenderProcessDeallocate(m_loc, rndrProcess);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_ImageProcessing : public CLxLocalize<ILxImageProcessingID>
{
public:
    CLxLoc_ImageProcessing()
    {
        _init();
    }

    CLxLoc_ImageProcessing(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_ImageProcessing(CLxLoc_ImageProcessing const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_ImageProcessing;
    }

    auto GetAsReadOnly(void **ppvObj) -> LxResult
    {
        return m_loc[0]->GetAsReadOnly(m_loc, ppvObj);
    }

    auto GetAsReadOnly(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->GetAsReadOnly(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto SetIdentifier(const char *string) -> LxResult
    {
        return m_loc[0]->SetIdentifier(m_loc, string);
    }

    auto GetIdentifier(const char **string) const -> LxResult
    {
        return m_loc[0]->GetIdentifier(m_loc, string);
    }

    auto Reset(void) -> LxResult
    {
        return m_loc[0]->Reset(m_loc);
    }

    auto CopyToRenderProcess(LXtRenderOutputProcess *rop) -> LxResult
    {
        return m_loc[0]->CopyToRenderProcess(m_loc, rop);
    }

    auto CopyFromRenderProcess(const LXtRenderOutputProcess *rop) -> LxResult
    {
        return m_loc[0]->CopyFromRenderProcess(m_loc, rop);
    }

    auto CopySettingsFromFrameBuffer(ILxUnknownID frameBuffer, int bufferIndex) -> LxResult
    {
        return m_loc[0]->CopySettingsFromFrameBuffer(m_loc,(ILxUnknownID) frameBuffer, bufferIndex);
    }

    auto CopySettingsToFrameBuffer(ILxUnknownID frameBuffer, int bufferIndex) -> LxResult
    {
        return m_loc[0]->CopySettingsToFrameBuffer(m_loc,(ILxUnknownID) frameBuffer, bufferIndex);
    }

    auto ApplyToImageFromFrameBuffer(ILxUnknownID frameBuffer, int bufferIndex, ILxUnknownID image, float xOffset, float yOffset, float zoom) -> LxResult
    {
        return m_loc[0]->ApplyToImageFromFrameBuffer(m_loc,(ILxUnknownID) frameBuffer, bufferIndex,(ILxUnknownID) image, xOffset, yOffset, zoom);
    }

    auto ApplyToImageFromFrameBufferOverride(ILxUnknownID frameBuffer, int bufferIndex, ILxUnknownID image, float xOffset, float yOffset, float zoom, LXtImageProcessingOperators opOverride) -> LxResult
    {
        return m_loc[0]->ApplyToImageFromFrameBufferOverride(m_loc,(ILxUnknownID) frameBuffer, bufferIndex,(ILxUnknownID) image, xOffset, yOffset, zoom, opOverride);
    }

    auto ApplyToFrameBuffer(ILxUnknownID frameBuffer, int bufferIndex) -> LxResult
    {
        return m_loc[0]->ApplyToFrameBuffer(m_loc,(ILxUnknownID) frameBuffer, bufferIndex);
    }

    auto ApplyToFrameBufferOverride(ILxUnknownID frameBuffer, int bufferIndex, LXtImageProcessingOperators opOverride) -> LxResult
    {
        return m_loc[0]->ApplyToFrameBufferOverride(m_loc,(ILxUnknownID) frameBuffer, bufferIndex, opOverride);
    }

    auto ApplyToImage(ILxUnknownID srcImage, ILxUnknownID dstImage) -> LxResult
    {
        return m_loc[0]->ApplyToImage(m_loc,(ILxUnknownID) srcImage,(ILxUnknownID) dstImage);
    }

    auto ApplyToImageOverride(ILxUnknownID srcImage, ILxUnknownID dstImage, LXtImageProcessingOperators opOverride) -> LxResult
    {
        return m_loc[0]->ApplyToImageOverride(m_loc,(ILxUnknownID) srcImage,(ILxUnknownID) dstImage, opOverride);
    }

    auto GetImageProcessingOperators(LXtImageProcessingOperators *ops) -> LxResult
    {
        return m_loc[0]->GetImageProcessingOperators(m_loc, ops);
    }

    auto SetImageProcessingOperators(LXtImageProcessingOperators ops) -> LxResult
    {
        return m_loc[0]->SetImageProcessingOperators(m_loc, ops);
    }

    auto AreaProcessingActive(int *active) -> LxResult
    {
        return m_loc[0]->AreaProcessingActive(m_loc, active);
    }

    auto GetSourceImageGamma(double *gamma) -> LxResult
    {
        return m_loc[0]->GetSourceImageGamma(m_loc, gamma);
    }

    auto SetSourceImageGamma(double gamma) -> LxResult
    {
        return m_loc[0]->SetSourceImageGamma(m_loc, gamma);
    }

    auto GetSourceImageIsStereoSideBySide(int *isStereo) -> LxResult
    {
        return m_loc[0]->GetSourceImageIsStereoSideBySide(m_loc, isStereo);
    }

    auto SetSourceImageIsStereoSideBySide(int isStereo) -> LxResult
    {
        return m_loc[0]->SetSourceImageIsStereoSideBySide(m_loc, isStereo);
    }

    auto GetSaveProcessed(int *enabled) -> LxResult
    {
        return m_loc[0]->GetSaveProcessed(m_loc, enabled);
    }

    auto SetSaveProcessed(int enabled) -> LxResult
    {
        return m_loc[0]->SetSaveProcessed(m_loc, enabled);
    }

    auto GetStereoEye(LXtStereoEye *eye) -> LxResult
    {
        return m_loc[0]->GetStereoEye(m_loc, eye);
    }

    auto SetStereoEye(LXtStereoEye eye) -> LxResult
    {
        return m_loc[0]->SetStereoEye(m_loc, eye);
    }

    auto GetStereoComposite(LXtStereoComposite *mode) -> LxResult
    {
        return m_loc[0]->GetStereoComposite(m_loc, mode);
    }

    auto SetStereoComposite(LXtStereoComposite mode) -> LxResult
    {
        return m_loc[0]->SetStereoComposite(m_loc, mode);
    }

    auto GetBloomEnabled(int *enabled) const -> LxResult
    {
        return m_loc[0]->GetBloomEnabled(m_loc, enabled);
    }

    auto SetBloomEnabled(int enabled) -> LxResult
    {
        return m_loc[0]->SetBloomEnabled(m_loc, enabled);
    }

    auto GetBloomThreshold(double *threshold) -> LxResult
    {
        return m_loc[0]->GetBloomThreshold(m_loc, threshold);
    }

    auto SetBloomThreshold(double threshold) -> LxResult
    {
        return m_loc[0]->SetBloomThreshold(m_loc, threshold);
    }

    auto GetBloomRadius(double *radius) -> LxResult
    {
        return m_loc[0]->GetBloomRadius(m_loc, radius);
    }

    auto SetBloomRadius(double radius) -> LxResult
    {
        return m_loc[0]->SetBloomRadius(m_loc, radius);
    }

    auto GetVignetteAmount(double *amount) -> LxResult
    {
        return m_loc[0]->GetVignetteAmount(m_loc, amount);
    }

    auto SetVignetteAmount(double amount) -> LxResult
    {
        return m_loc[0]->SetVignetteAmount(m_loc, amount);
    }

    auto GetInputBlackLevel(double *inputBlackLevel) -> LxResult
    {
        return m_loc[0]->GetInputBlackLevel(m_loc, inputBlackLevel);
    }

    auto SetInputBlackLevel(double blackLevel) -> LxResult
    {
        return m_loc[0]->SetInputBlackLevel(m_loc, blackLevel);
    }

    auto GetInputGrayLevel(double *gamma) -> LxResult
    {
        return m_loc[0]->GetInputGrayLevel(m_loc, gamma);
    }

    auto GetInvInputGrayLevel(double *invGamma) -> LxResult
    {
        return m_loc[0]->GetInvInputGrayLevel(m_loc, invGamma);
    }

    auto SetInputGrayLevel(double gamma) -> LxResult
    {
        return m_loc[0]->SetInputGrayLevel(m_loc, gamma);
    }

    auto GetInputWhiteLevel(double *inputWhiteLevel) -> LxResult
    {
        return m_loc[0]->GetInputWhiteLevel(m_loc, inputWhiteLevel);
    }

    auto SetInputWhiteLevel(double whiteLevel) -> LxResult
    {
        return m_loc[0]->SetInputWhiteLevel(m_loc, whiteLevel);
    }

    auto GetInputMinRedLevel(double *inputLevel) -> LxResult
    {
        return m_loc[0]->GetInputMinRedLevel(m_loc, inputLevel);
    }

    auto SetInputMinRedLevel(double level) -> LxResult
    {
        return m_loc[0]->SetInputMinRedLevel(m_loc, level);
    }

    auto GetInputRedGrayLevel(double *gamma) -> LxResult
    {
        return m_loc[0]->GetInputRedGrayLevel(m_loc, gamma);
    }

    auto GetInvInputRedGrayLevel(double *invGamma) -> LxResult
    {
        return m_loc[0]->GetInvInputRedGrayLevel(m_loc, invGamma);
    }

    auto SetInputRedGrayLevel(double gamma) -> LxResult
    {
        return m_loc[0]->SetInputRedGrayLevel(m_loc, gamma);
    }

    auto GetInputMaxRedLevel(double *inputLevel) -> LxResult
    {
        return m_loc[0]->GetInputMaxRedLevel(m_loc, inputLevel);
    }

    auto SetInputMaxRedLevel(double level) -> LxResult
    {
        return m_loc[0]->SetInputMaxRedLevel(m_loc, level);
    }

    auto GetInputMinGreenLevel(double *inputLevel) -> LxResult
    {
        return m_loc[0]->GetInputMinGreenLevel(m_loc, inputLevel);
    }

    auto SetInputMinGreenLevel(double level) -> LxResult
    {
        return m_loc[0]->SetInputMinGreenLevel(m_loc, level);
    }

    auto GetInputGreenGrayLevel(double *gamma) -> LxResult
    {
        return m_loc[0]->GetInputGreenGrayLevel(m_loc, gamma);
    }

    auto GetInvInputGreenGrayLevel(double *invGamma) -> LxResult
    {
        return m_loc[0]->GetInvInputGreenGrayLevel(m_loc, invGamma);
    }

    auto SetInputGreenGrayLevel(double gamma) -> LxResult
    {
        return m_loc[0]->SetInputGreenGrayLevel(m_loc, gamma);
    }

    auto GetInputMaxGreenLevel(double *inputLevel) -> LxResult
    {
        return m_loc[0]->GetInputMaxGreenLevel(m_loc, inputLevel);
    }

    auto SetInputMaxGreenLevel(double level) -> LxResult
    {
        return m_loc[0]->SetInputMaxGreenLevel(m_loc, level);
    }

    auto GetInputMinBlueLevel(double *inputLevel) -> LxResult
    {
        return m_loc[0]->GetInputMinBlueLevel(m_loc, inputLevel);
    }

    auto SetInputMinBlueLevel(double level) -> LxResult
    {
        return m_loc[0]->SetInputMinBlueLevel(m_loc, level);
    }

    auto GetInputBlueGrayLevel(double *gamma) -> LxResult
    {
        return m_loc[0]->GetInputBlueGrayLevel(m_loc, gamma);
    }

    auto GetInvInputBlueGrayLevel(double *invGamma) -> LxResult
    {
        return m_loc[0]->GetInvInputBlueGrayLevel(m_loc, invGamma);
    }

    auto SetInputBlueGrayLevel(double gamma) -> LxResult
    {
        return m_loc[0]->SetInputBlueGrayLevel(m_loc, gamma);
    }

    auto GetInputMaxBlueLevel(double *inputLevel) -> LxResult
    {
        return m_loc[0]->GetInputMaxBlueLevel(m_loc, inputLevel);
    }

    auto SetInputMaxBlueLevel(double level) -> LxResult
    {
        return m_loc[0]->SetInputMaxBlueLevel(m_loc, level);
    }

    auto GetExpType(int *expType) -> LxResult
    {
        return m_loc[0]->GetExpType(m_loc, expType);
    }

    auto SetExpType(int expType) -> LxResult
    {
        return m_loc[0]->SetExpType(m_loc, expType);
    }

    auto GetISO(double *iso) -> LxResult
    {
        return m_loc[0]->GetISO(m_loc, iso);
    }

    auto SetISO(double iso) -> LxResult
    {
        return m_loc[0]->SetISO(m_loc, iso);
    }

    auto GetToneMap(int *toneMap) -> LxResult
    {
        return m_loc[0]->GetToneMap(m_loc, toneMap);
    }

    auto SetToneMap(int toneMap) -> LxResult
    {
        return m_loc[0]->SetToneMap(m_loc, toneMap);
    }

    auto GetToneAmt(double *toneAmt) -> LxResult
    {
        return m_loc[0]->GetToneAmt(m_loc, toneAmt);
    }

    auto SetToneAmt(double toneAmt) -> LxResult
    {
        return m_loc[0]->SetToneAmt(m_loc, toneAmt);
    }

    auto GetHueOffset(double *hueOffset) -> LxResult
    {
        return m_loc[0]->GetHueOffset(m_loc, hueOffset);
    }

    auto SetHueOffset(double hueOffset) -> LxResult
    {
        return m_loc[0]->SetHueOffset(m_loc, hueOffset);
    }

    auto GetSaturation(double *saturation) -> LxResult
    {
        return m_loc[0]->GetSaturation(m_loc, saturation);
    }

    auto SetSaturation(double saturation) -> LxResult
    {
        return m_loc[0]->SetSaturation(m_loc, saturation);
    }

    auto GetColorization(double *colorization) -> LxResult
    {
        return m_loc[0]->GetColorization(m_loc, colorization);
    }

    auto SetColorization(double colorization) -> LxResult
    {
        return m_loc[0]->SetColorization(m_loc, colorization);
    }

    auto GetTargetColor(double *color) -> LxResult
    {
        return m_loc[0]->GetTargetColor(m_loc, color);
    }

    auto SetTargetColor(const double *color) -> LxResult
    {
        return m_loc[0]->SetTargetColor(m_loc, color);
    }

    auto GetOutputBlackLevel(double *outputBlackLevel) -> LxResult
    {
        return m_loc[0]->GetOutputBlackLevel(m_loc, outputBlackLevel);
    }

    auto SetOutputBlackLevel(double blackLevel) -> LxResult
    {
        return m_loc[0]->SetOutputBlackLevel(m_loc, blackLevel);
    }

    auto GetOutputWhiteLevel(double *outputWhiteLevel) -> LxResult
    {
        return m_loc[0]->GetOutputWhiteLevel(m_loc, outputWhiteLevel);
    }

    auto SetOutputWhiteLevel(double whiteLevel) -> LxResult
    {
        return m_loc[0]->SetOutputWhiteLevel(m_loc, whiteLevel);
    }

    auto GetOutputMinRedLevel(double *outputLevel) -> LxResult
    {
        return m_loc[0]->GetOutputMinRedLevel(m_loc, outputLevel);
    }

    auto SetOutputMinRedLevel(double outputLevel) -> LxResult
    {
        return m_loc[0]->SetOutputMinRedLevel(m_loc, outputLevel);
    }

    auto GetOutputMaxRedLevel(double *outputLevel) -> LxResult
    {
        return m_loc[0]->GetOutputMaxRedLevel(m_loc, outputLevel);
    }

    auto SetOutputMaxRedLevel(double outputLevel) -> LxResult
    {
        return m_loc[0]->SetOutputMaxRedLevel(m_loc, outputLevel);
    }

    auto GetOutputMinGreenLevel(double *outputLevel) -> LxResult
    {
        return m_loc[0]->GetOutputMinGreenLevel(m_loc, outputLevel);
    }

    auto SetOutputMinGreenLevel(double outputLevel) -> LxResult
    {
        return m_loc[0]->SetOutputMinGreenLevel(m_loc, outputLevel);
    }

    auto GetOutputMaxGreenLevel(double *outputLevel) -> LxResult
    {
        return m_loc[0]->GetOutputMaxGreenLevel(m_loc, outputLevel);
    }

    auto SetOutputMaxGreenLevel(double outputLevel) -> LxResult
    {
        return m_loc[0]->SetOutputMaxGreenLevel(m_loc, outputLevel);
    }

    auto GetOutputMinBlueLevel(double *outputLevel) -> LxResult
    {
        return m_loc[0]->GetOutputMinBlueLevel(m_loc, outputLevel);
    }

    auto SetOutputMinBlueLevel(double outputLevel) -> LxResult
    {
        return m_loc[0]->SetOutputMinBlueLevel(m_loc, outputLevel);
    }

    auto GetOutputMaxBlueLevel(double *outputLevel) -> LxResult
    {
        return m_loc[0]->GetOutputMaxBlueLevel(m_loc, outputLevel);
    }

    auto SetOutputMaxBlueLevel(double outputLevel) -> LxResult
    {
        return m_loc[0]->SetOutputMaxBlueLevel(m_loc, outputLevel);
    }

    auto GetOutputGamma(double *outputGamma) -> LxResult
    {
        return m_loc[0]->GetOutputGamma(m_loc, outputGamma);
    }

    auto GetOutputInvGamma(double *outputInvGamma) -> LxResult
    {
        return m_loc[0]->GetOutputInvGamma(m_loc, outputInvGamma);
    }

    auto SetOutputGamma(double gamma) -> LxResult
    {
        return m_loc[0]->SetOutputGamma(m_loc, gamma);
    }

    auto GetOutputColorspace(void) -> const char*
    {
        return m_loc[0]->GetOutputColorspace(m_loc);
    }

    auto SetOutputColorspace(const char* colorspace) -> LxResult
    {
        return m_loc[0]->SetOutputColorspace(m_loc, colorspace);
    }

    auto GetOutputColormapping(void) -> ILxColorMappingID
    {
        return m_loc[0]->GetOutputColormapping(m_loc);
    }

    auto SetOutputColormapping(ILxUnknownID colormapping) -> LxResult
    {
        return m_loc[0]->SetOutputColormapping(m_loc,(ILxUnknownID) colormapping);
    }

    auto GetColorSpaceEmbedding(int *colorSpaceEmbedding) -> LxResult
    {
        return m_loc[0]->GetColorSpaceEmbedding(m_loc, colorSpaceEmbedding);
    }

    auto SetColorSpaceEmbedding(const int colorSpaceEmbedding) -> LxResult
    {
        return m_loc[0]->SetColorSpaceEmbedding(m_loc, colorSpaceEmbedding);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_ImageProcessingListener
{
public:
    virtual ~CLxImpl_ImageProcessingListener() = default;

    virtual auto improl_Changed([[maybe_unused]] const char *identifier, [[maybe_unused]] int eventCode) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto improl_Reset([[maybe_unused]] const char *identifier) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_ImageProcessingListener_Changed LxResult improl_Changed([[maybe_unused]] const char *identifier, [[maybe_unused]] int eventCode) override
#define LXxO_ImageProcessingListener_Changed LXxD_ImageProcessingListener_Changed
#define LXxC_ImageProcessingListener_Changed(c) LxResult c::improl_Changed([[maybe_unused]] const char *identifier, [[maybe_unused]] int eventCode)
#define LXxD_ImageProcessingListener_Reset LxResult improl_Reset([[maybe_unused]] const char *identifier) override
#define LXxO_ImageProcessingListener_Reset LXxD_ImageProcessingListener_Reset
#define LXxC_ImageProcessingListener_Reset(c) LxResult c::improl_Reset([[maybe_unused]] const char *identifier)

template <class T>
class CLxIfc_ImageProcessingListener: public CLxInterface
{
public:
    CLxIfc_ImageProcessingListener()
    {
        vt.Changed = Changed;
        vt.Reset = Reset;
        vTable = &vt.iunk;
        iid = &lx::guid_ImageProcessingListener;
    }

    static auto Changed(LXtObjectID wcom,const char *identifier,int eventCode) -> LxResult
    {
        LXCWxINST (CLxImpl_ImageProcessingListener, loc);
        try
        {
           return loc->improl_Changed( identifier, eventCode);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Reset(LXtObjectID wcom,const char *identifier) -> LxResult
    {
        LXCWxINST (CLxImpl_ImageProcessingListener, loc);
        try
        {
           return loc->improl_Reset( identifier);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxImageProcessingListener vt;
};

class CLxLoc_ImageProcessingListener : public CLxLocalize<ILxImageProcessingListenerID>
{
public:
    CLxLoc_ImageProcessingListener()
    {
        _init();
    }

    CLxLoc_ImageProcessingListener(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_ImageProcessingListener(CLxLoc_ImageProcessingListener const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_ImageProcessingListener;
    }

    auto Changed(const char *identifier, int eventCode) -> LxResult
    {
        return m_loc[0]->Changed(m_loc, identifier, eventCode);
    }

    auto Reset(const char *identifier) -> LxResult
    {
        return m_loc[0]->Reset(m_loc, identifier);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_ImageProcessingRead : public CLxLocalize<ILxImageProcessingReadID>
{
public:
    CLxLoc_ImageProcessingRead()
    {
        _init();
    }

    CLxLoc_ImageProcessingRead(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_ImageProcessingRead(CLxLoc_ImageProcessingRead const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_ImageProcessingRead;
    }

    auto GetIdentifier(const char **string) const -> LxResult
    {
        return m_loc[0]->GetIdentifier(m_loc, string);
    }

    auto CopyToRenderProcess(LXtRenderOutputProcess *rop) -> LxResult
    {
        return m_loc[0]->CopyToRenderProcess(m_loc, rop);
    }

    auto CopySettingsToFrameBuffer(ILxUnknownID frameBuffer, int bufferIndex) const -> LxResult
    {
        return m_loc[0]->CopySettingsToFrameBuffer(m_loc,(ILxUnknownID) frameBuffer, bufferIndex);
    }

    auto ApplyToImageFromFrameBuffer(ILxUnknownID frameBuffer, int bufferIndex, ILxUnknownID image, float xOffset, float yOffset, float zoom) -> LxResult
    {
        return m_loc[0]->ApplyToImageFromFrameBuffer(m_loc,(ILxUnknownID) frameBuffer, bufferIndex,(ILxUnknownID) image, xOffset, yOffset, zoom);
    }

    auto ApplyToImageFromFrameBufferOverride(ILxUnknownID frameBuffer, int bufferIndex, ILxUnknownID image, float xOffset, float yOffset, float zoom, LXtImageProcessingOperators opOverride) -> LxResult
    {
        return m_loc[0]->ApplyToImageFromFrameBufferOverride(m_loc,(ILxUnknownID) frameBuffer, bufferIndex,(ILxUnknownID) image, xOffset, yOffset, zoom, opOverride);
    }

    auto ApplyToFrameBuffer(ILxUnknownID frameBuffer, int bufferIndex) -> LxResult
    {
        return m_loc[0]->ApplyToFrameBuffer(m_loc,(ILxUnknownID) frameBuffer, bufferIndex);
    }

    auto ApplyToFrameBufferOverride(ILxUnknownID frameBuffer, int bufferIndex, LXtImageProcessingOperators opOverride) -> LxResult
    {
        return m_loc[0]->ApplyToFrameBufferOverride(m_loc,(ILxUnknownID) frameBuffer, bufferIndex, opOverride);
    }

    auto ApplyToImage(ILxUnknownID srcImage, ILxUnknownID dstImage) -> LxResult
    {
        return m_loc[0]->ApplyToImage(m_loc,(ILxUnknownID) srcImage,(ILxUnknownID) dstImage);
    }

    auto ApplyToImageOverride(ILxUnknownID srcImage, ILxUnknownID dstImage, LXtImageProcessingOperators opOverride) -> LxResult
    {
        return m_loc[0]->ApplyToImageOverride(m_loc,(ILxUnknownID) srcImage,(ILxUnknownID) dstImage, opOverride);
    }

    auto GetImageProcessingOperators(LXtImageProcessingOperators *ops) -> LxResult
    {
        return m_loc[0]->GetImageProcessingOperators(m_loc, ops);
    }

    auto AreaProcessingActive(int *active) -> LxResult
    {
        return m_loc[0]->AreaProcessingActive(m_loc, active);
    }

    auto GetSourceImageGamma(double *gamma) -> LxResult
    {
        return m_loc[0]->GetSourceImageGamma(m_loc, gamma);
    }

    auto GetSourceImageIsStereoSideBySide(int *isStereo) -> LxResult
    {
        return m_loc[0]->GetSourceImageIsStereoSideBySide(m_loc, isStereo);
    }

    auto GetSaveProcessed(int *enabled) -> LxResult
    {
        return m_loc[0]->GetSaveProcessed(m_loc, enabled);
    }

    auto GetStereoEye(int *eye) -> LxResult
    {
        return m_loc[0]->GetStereoEye(m_loc, eye);
    }

    auto GetStereoComposite(int *mode) -> LxResult
    {
        return m_loc[0]->GetStereoComposite(m_loc, mode);
    }

    auto GetBloomEnabled(int *enabled) -> LxResult
    {
        return m_loc[0]->GetBloomEnabled(m_loc, enabled);
    }

    auto GetBloomThreshold(double *threshold) -> LxResult
    {
        return m_loc[0]->GetBloomThreshold(m_loc, threshold);
    }

    auto GetBloomRadius(double *radius) -> LxResult
    {
        return m_loc[0]->GetBloomRadius(m_loc, radius);
    }

    auto GetInputBlackLevel(double *inputLevel) -> LxResult
    {
        return m_loc[0]->GetInputBlackLevel(m_loc, inputLevel);
    }

    auto GetInputGrayLevel(double *gamma) -> LxResult
    {
        return m_loc[0]->GetInputGrayLevel(m_loc, gamma);
    }

    auto GetInvInputGrayLevel(double *invGamma) -> LxResult
    {
        return m_loc[0]->GetInvInputGrayLevel(m_loc, invGamma);
    }

    auto GetInputWhiteLevel(double *inputLevel) -> LxResult
    {
        return m_loc[0]->GetInputWhiteLevel(m_loc, inputLevel);
    }

    auto GetInputMinRedLevel(double *inputLevel) -> LxResult
    {
        return m_loc[0]->GetInputMinRedLevel(m_loc, inputLevel);
    }

    auto GetInputRedGrayLevel(double *gamma) -> LxResult
    {
        return m_loc[0]->GetInputRedGrayLevel(m_loc, gamma);
    }

    auto GetInvInputRedGrayLevel(double *invGamma) -> LxResult
    {
        return m_loc[0]->GetInvInputRedGrayLevel(m_loc, invGamma);
    }

    auto GetInputMaxRedLevel(double *inputLevel) -> LxResult
    {
        return m_loc[0]->GetInputMaxRedLevel(m_loc, inputLevel);
    }

    auto GetInputMinGreenLevel(double *inputLevel) -> LxResult
    {
        return m_loc[0]->GetInputMinGreenLevel(m_loc, inputLevel);
    }

    auto GetInputGreenGrayLevel(double *gamma) -> LxResult
    {
        return m_loc[0]->GetInputGreenGrayLevel(m_loc, gamma);
    }

    auto GetInvInputGreenGrayLevel(double *invGamma) -> LxResult
    {
        return m_loc[0]->GetInvInputGreenGrayLevel(m_loc, invGamma);
    }

    auto GetInputMaxGreenLevel(double *inputLevel) -> LxResult
    {
        return m_loc[0]->GetInputMaxGreenLevel(m_loc, inputLevel);
    }

    auto GetInputMinBlueLevel(double *inputLevel) -> LxResult
    {
        return m_loc[0]->GetInputMinBlueLevel(m_loc, inputLevel);
    }

    auto GetInputBlueGrayLevel(double *gamma) -> LxResult
    {
        return m_loc[0]->GetInputBlueGrayLevel(m_loc, gamma);
    }

    auto GetInvInputBlueGrayLevel(double *invGamma) -> LxResult
    {
        return m_loc[0]->GetInvInputBlueGrayLevel(m_loc, invGamma);
    }

    auto GetInputMaxBlueLevel(double *inputLevel) -> LxResult
    {
        return m_loc[0]->GetInputMaxBlueLevel(m_loc, inputLevel);
    }

    auto GetExpType(int *expType) -> LxResult
    {
        return m_loc[0]->GetExpType(m_loc, expType);
    }

    auto GetISO(double *iso) -> LxResult
    {
        return m_loc[0]->GetISO(m_loc, iso);
    }

    auto GetToneMap(int *toneMap) -> LxResult
    {
        return m_loc[0]->GetToneMap(m_loc, toneMap);
    }

    auto GetToneAmt(double *toneAmt) -> LxResult
    {
        return m_loc[0]->GetToneAmt(m_loc, toneAmt);
    }

    auto GetHueOffset(double *hueOffset) -> LxResult
    {
        return m_loc[0]->GetHueOffset(m_loc, hueOffset);
    }

    auto GetSaturation(double *saturation) -> LxResult
    {
        return m_loc[0]->GetSaturation(m_loc, saturation);
    }

    auto GetColorization(double *colorization) -> LxResult
    {
        return m_loc[0]->GetColorization(m_loc, colorization);
    }

    auto GetTargetColor(double *color) -> LxResult
    {
        return m_loc[0]->GetTargetColor(m_loc, color);
    }

    auto GetOutputBlackLevel(double *outputLevel) -> LxResult
    {
        return m_loc[0]->GetOutputBlackLevel(m_loc, outputLevel);
    }

    auto GetOutputWhiteLevel(double *outputLevel) -> LxResult
    {
        return m_loc[0]->GetOutputWhiteLevel(m_loc, outputLevel);
    }

    auto GetOutputMinRedLevel(double *outputLevel) -> LxResult
    {
        return m_loc[0]->GetOutputMinRedLevel(m_loc, outputLevel);
    }

    auto GetOutputMaxRedLevel(double *outputLevel) -> LxResult
    {
        return m_loc[0]->GetOutputMaxRedLevel(m_loc, outputLevel);
    }

    auto GetOutputMinGreenLevel(double *outputLevel) -> LxResult
    {
        return m_loc[0]->GetOutputMinGreenLevel(m_loc, outputLevel);
    }

    auto GetOutputMaxGreenLevel(double *outputLevel) -> LxResult
    {
        return m_loc[0]->GetOutputMaxGreenLevel(m_loc, outputLevel);
    }

    auto GetOutputMinBlueLevel(double *outputLevel) -> LxResult
    {
        return m_loc[0]->GetOutputMinBlueLevel(m_loc, outputLevel);
    }

    auto GetOutputMaxBlueLevel(double *outputLevel) -> LxResult
    {
        return m_loc[0]->GetOutputMaxBlueLevel(m_loc, outputLevel);
    }

    auto GetOutputGamma(double *outputGamma) -> LxResult
    {
        return m_loc[0]->GetOutputGamma(m_loc, outputGamma);
    }

    auto GetOutputInvGamma(double *outputInvGamma) -> LxResult
    {
        return m_loc[0]->GetOutputInvGamma(m_loc, outputInvGamma);
    }

    auto GetOutputColorspace(void) -> const char*
    {
        return m_loc[0]->GetOutputColorspace(m_loc);
    }

    auto GetOutputColormapping(void) -> ILxColorMappingID
    {
        return m_loc[0]->GetOutputColormapping(m_loc);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_ImageProcessingService : public CLxLocalizedService
{
public:
    ILxImageProcessingServiceID m_loc{ nullptr };

public:
    CLxLoc_ImageProcessingService()
    {
        _init();
        set();
    }

    ~CLxLoc_ImageProcessingService() = default;

    void set()
    {
        if (!m_loc)
        {
            m_loc = reinterpret_cast<ILxImageProcessingServiceID>(lx::GetGlobal(&lx::guid_ImageProcessingService));
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

    auto Create(void **ppvObj) -> LxResult
    {
        return m_loc[0]->Create(m_loc, ppvObj);
    }

    auto Create(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Create(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
