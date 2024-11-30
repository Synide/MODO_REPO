//
// C++ wrapper for lxsdk/lxpreview.h.
//
//	Copyright 2024.
//
//
#pragma once

#include <lxpreview.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx
{
    static LXtGUID const guid_PreviewService = {0x0491f901, {0x6eee, 0x48e4}, {0xa4, 0xd0, 0xb2, 0xe6, 0xd1, 0x06, 0x24, 0xb6}};
    static LXtGUID const guid_Preview = {0x6817942a, {0x375d, 0x485f}, {0xb9, 0x27, 0xaf, 0x93, 0xd1, 0x39, 0x1d, 0x73}};
    static LXtGUID const guid_PreviewNotifier = {0x352039c2, {0x8b70, 0x46db}, {0x9a, 0x83, 0x1e, 0x05, 0xfd, 0x88, 0x7f, 0xc0}};
} // namespace lx

class CLxLoc_PreviewService : public CLxLocalizedService
{
public:
    ILxPreviewServiceID m_loc{ nullptr };

public:
    CLxLoc_PreviewService()
    {
        _init();
        set();
    }

    ~CLxLoc_PreviewService() = default;

    void set()
    {
        if (!m_loc)
        {
            m_loc = reinterpret_cast<ILxPreviewServiceID>(lx::GetGlobal(&lx::guid_PreviewService));
        }
    }

    auto CreatePreview(void **ppvObj) -> LxResult
    {
        return m_loc[0]->CreatePreview(m_loc, ppvObj);
    }

    auto CreatePreview(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->CreatePreview(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto GetMeshPreview(ILxUnknownID item, int width, int height, void **ppvObj) -> LxResult
    {
        return m_loc[0]->GetMeshPreview(m_loc,(ILxUnknownID) item, width, height, ppvObj);
    }

    auto GetMeshPreview(ILxUnknownID item, int width, int height, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->GetMeshPreview(m_loc,(ILxUnknownID) item, width, height, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_Preview : public CLxLocalize<ILxPreviewID>
{
public:
    CLxLoc_Preview()
    {
        _init();
    }

    CLxLoc_Preview(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_Preview(CLxLoc_Preview const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_Preview;
    }

    auto Start(void) const -> LxResult
    {
        return m_loc[0]->Start(m_loc);
    }

    auto Stop(void) const -> LxResult
    {
        return m_loc[0]->Stop(m_loc);
    }

    auto Pause(void) const -> LxResult
    {
        return m_loc[0]->Pause(m_loc);
    }

    auto Reset(void) const -> LxResult
    {
        return m_loc[0]->Reset(m_loc);
    }

    auto SetRes(int width, int height) const -> LxResult
    {
        return m_loc[0]->SetRes(m_loc, width, height);
    }

    auto SetRenderTime(double time) -> LxResult
    {
        return m_loc[0]->SetRenderTime(m_loc, time);
    }

    auto SetQuality(int quality, int samples) const -> LxResult
    {
        return m_loc[0]->SetQuality(m_loc, quality, samples);
    }

    auto SetMotionBlur(int enable) -> LxResult
    {
        return m_loc[0]->SetMotionBlur(m_loc, enable);
    }

    auto SetRenderAllOutputs(int enable) const -> LxResult
    {
        return m_loc[0]->SetRenderAllOutputs(m_loc, enable);
    }

    auto SetUseAllThreads(int enable) const -> LxResult
    {
        return m_loc[0]->SetUseAllThreads(m_loc, enable);
    }

    auto SetStereo(int enable, int eye) const -> LxResult
    {
        return m_loc[0]->SetStereo(m_loc, enable, eye);
    }

    auto SetNotifier(ILxUnknownID notifier) -> LxResult
    {
        return m_loc[0]->SetNotifier(m_loc,(ILxUnknownID) notifier);
    }

    auto SetAlpha(int enable) -> LxResult
    {
        return m_loc[0]->SetAlpha(m_loc, enable);
    }

    auto UseCameraOverride(int useCameraOverride) -> LxResult
    {
        return m_loc[0]->UseCameraOverride(m_loc, useCameraOverride);
    }

    auto SetCameraOverrideTransform(const LXtMatrix4 transform) -> LxResult
    {
        return m_loc[0]->SetCameraOverrideTransform(m_loc, transform);
    }

    auto SetCameraOverrideFocalLength(float focalLength) -> LxResult
    {
        return m_loc[0]->SetCameraOverrideFocalLength(m_loc, focalLength);
    }

    auto SetCameraOverrideApertureX(float apertureX) -> LxResult
    {
        return m_loc[0]->SetCameraOverrideApertureX(m_loc, apertureX);
    }

    auto SetCameraOverrideApertureY(float apertureY) -> LxResult
    {
        return m_loc[0]->SetCameraOverrideApertureY(m_loc, apertureY);
    }

    auto SetCameraOverrideProjectionType(int projectionType) -> LxResult
    {
        return m_loc[0]->SetCameraOverrideProjectionType(m_loc, projectionType);
    }

    auto GetResWidth(void) -> int
    {
        return m_loc[0]->GetResWidth(m_loc);
    }

    auto GetResHeight(void) -> int
    {
        return m_loc[0]->GetResHeight(m_loc);
    }

    auto GetCurrentTime(void) -> double
    {
        return m_loc[0]->GetCurrentTime(m_loc);
    }

    auto IsComplete(void) const -> LxResult
    {
        return m_loc[0]->IsComplete(m_loc);
    }

    auto GetBuffer(void **ppvObj) const -> LxResult
    {
        return m_loc[0]->GetBuffer(m_loc, ppvObj);
    }

    auto GetBuffer(CLxLocalizedObject &o_dest) const -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->GetBuffer(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto SetEffect(const char *effect) const -> LxResult
    {
        return m_loc[0]->SetEffect(m_loc, effect);
    }

    auto SetBakeMode(int mode) const -> LxResult
    {
        return m_loc[0]->SetBakeMode(m_loc, mode);
    }

    auto SetLastTexture(ILxUnknownID item) const -> LxResult
    {
        return m_loc[0]->SetLastTexture(m_loc,(ILxUnknownID) item);
    }

    auto GetProgress(void) const -> float
    {
        return m_loc[0]->GetProgress(m_loc);
    }

    auto SetIgnoreSelections(int allow) const -> void
    {
        m_loc[0]->SetIgnoreSelections(m_loc, allow);
    }

    auto IsFinished(void) const -> LxResult
    {
        return m_loc[0]->IsFinished(m_loc);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_PreviewNotifier
{
public:
    virtual ~CLxImpl_PreviewNotifier() = default;

    virtual auto ntf_Notify([[maybe_unused]] const LXtRenderOutputProcess *rndrProcess, [[maybe_unused]] ILxUnknownID image, [[maybe_unused]] int completed) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_PreviewNotifier_Notify LxResult ntf_Notify([[maybe_unused]] const LXtRenderOutputProcess *rndrProcess, [[maybe_unused]] ILxUnknownID image, [[maybe_unused]] int completed) override
#define LXxO_PreviewNotifier_Notify LXxD_PreviewNotifier_Notify
#define LXxC_PreviewNotifier_Notify(c) LxResult c::ntf_Notify([[maybe_unused]] const LXtRenderOutputProcess *rndrProcess, [[maybe_unused]] ILxUnknownID image, [[maybe_unused]] int completed)

template <class T>
class CLxIfc_PreviewNotifier: public CLxInterface
{
public:
    CLxIfc_PreviewNotifier()
    {
        vt.Notify = Notify;
        vTable = &vt.iunk;
        iid = &lx::guid_PreviewNotifier;
    }

    static auto Notify(LXtObjectID wcom,const LXtRenderOutputProcess *rndrProcess,LXtObjectID image,int completed) -> LxResult
    {
        LXCWxINST (CLxImpl_PreviewNotifier, loc);
        try
        {
           return loc->ntf_Notify( rndrProcess,(ILxUnknownID) image, completed);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxPreviewNotifier vt;
};

class CLxLoc_PreviewNotifier : public CLxLocalize<ILxPreviewNotifierID>
{
public:
    CLxLoc_PreviewNotifier()
    {
        _init();
    }

    CLxLoc_PreviewNotifier(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_PreviewNotifier(CLxLoc_PreviewNotifier const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_PreviewNotifier;
    }

    auto Notify(const LXtRenderOutputProcess *rndrProcess, ILxUnknownID image, int completed) -> LxResult
    {
        return m_loc[0]->Notify(m_loc, rndrProcess,(ILxUnknownID) image, completed);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
