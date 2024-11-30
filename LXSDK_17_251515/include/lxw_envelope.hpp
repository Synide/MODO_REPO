//
// C++ wrapper for lxsdk/lxenvelope.h.
//
//	Copyright 2024.
//
//
#pragma once

#include <lxenvelope.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx
{
    static LXtGUID const guid_Envelope = {0xE39EB451, {0x6C35, 0x47F4}, {0x8A, 0x7D, 0xFF, 0x96, 0x67, 0x1C, 0x0D, 0xEF}};
    static LXtGUID const guid_Keyframe = {0xD1D0261F, {0x22CF, 0x4E5D}, {0x82, 0x2E, 0x76, 0xB5, 0xDE, 0xC9, 0x8A, 0xE4}};
    static LXtGUID const guid_GradientFilter = {0xB3E49419, {0x99B9, 0x4066}, {0x9D, 0xEC, 0xAA, 0x4E, 0xF9, 0x80, 0x2F, 0x0D}};
    static LXtGUID const guid_GradientFilter1 = {0xACCD7C33, {0xD246, 0x4FE5}, {0xAB, 0xA0, 0x07, 0x9F, 0x22, 0x5B, 0xBB, 0x34}};
} // namespace lx

class CLxLoc_Envelope : public CLxLocalize<ILxEnvelopeID>
{
public:
    CLxLoc_Envelope()
    {
        _init();
    }

    CLxLoc_Envelope(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_Envelope(CLxLoc_Envelope const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_Envelope;
    }

    auto IsInt(void) -> unsigned
    {
        return m_loc[0]->IsInt(m_loc);
    }

    auto Enumerator(void **ppvObj) -> LxResult
    {
        return m_loc[0]->Enumerator(m_loc, ppvObj);
    }

    auto Enumerator(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Enumerator(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto EvaluateF(double time, double *value) -> LxResult
    {
        return m_loc[0]->EvaluateF(m_loc, time, value);
    }

    auto EvaluateI(double time, int *value) -> LxResult
    {
        return m_loc[0]->EvaluateI(m_loc, time, value);
    }

    auto EndBehavior(unsigned int side) -> unsigned int
    {
        return m_loc[0]->EndBehavior(m_loc, side);
    }

    auto SetEndBehavior(unsigned int behavior, unsigned int side) -> LxResult
    {
        return m_loc[0]->SetEndBehavior(m_loc, behavior, side);
    }

    auto Clear(void) -> LxResult
    {
        return m_loc[0]->Clear(m_loc);
    }

    auto Interpolation(void) -> unsigned int
    {
        return m_loc[0]->Interpolation(m_loc);
    }

    auto SetInterpolation(unsigned int type) -> LxResult
    {
        return m_loc[0]->SetInterpolation(m_loc, type);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_Keyframe : public CLxLocalize<ILxKeyframeID>
{
public:
    CLxLoc_Keyframe()
    {
        _init();
    }

    CLxLoc_Keyframe(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_Keyframe(CLxLoc_Keyframe const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_Keyframe;
    }

    auto First(void) -> LxResult
    {
        return m_loc[0]->First(m_loc);
    }

    auto Last(void) -> LxResult
    {
        return m_loc[0]->Last(m_loc);
    }

    auto Next(void) -> LxResult
    {
        return m_loc[0]->Next(m_loc);
    }

    auto Previous(void) -> LxResult
    {
        return m_loc[0]->Previous(m_loc);
    }

    auto Find(double time, unsigned int side) -> LxResult
    {
        return m_loc[0]->Find(m_loc, time, side);
    }

    auto GetTime(double *time) -> LxResult
    {
        return m_loc[0]->GetTime(m_loc, time);
    }

    auto GetBroken(unsigned int *breaks, unsigned int *side) -> LxResult
    {
        return m_loc[0]->GetBroken(m_loc, breaks, side);
    }

    auto GetValueF(double *value, unsigned int side) -> LxResult
    {
        return m_loc[0]->GetValueF(m_loc, value, side);
    }

    auto GetValueI(int *value, unsigned int side) -> LxResult
    {
        return m_loc[0]->GetValueI(m_loc, value, side);
    }

    auto GetSlopeType(LXtSlopeType *type, unsigned int *weighted, unsigned int side) -> LxResult
    {
        return m_loc[0]->GetSlopeType(m_loc, type, weighted, side);
    }

    auto GetSlope(double *slope, unsigned int side) -> LxResult
    {
        return m_loc[0]->GetSlope(m_loc, slope, side);
    }

    auto GetWeight(double *weight, unsigned int side) -> LxResult
    {
        return m_loc[0]->GetWeight(m_loc, weight, side);
    }

    auto SetTime(double time) -> LxResult
    {
        return m_loc[0]->SetTime(m_loc, time);
    }

    auto SetValueF(double value, unsigned int side) -> LxResult
    {
        return m_loc[0]->SetValueF(m_loc, value, side);
    }

    auto SetValueI(int value, unsigned int side) -> LxResult
    {
        return m_loc[0]->SetValueI(m_loc, value, side);
    }

    auto SetSlope(double slope, unsigned int side) -> LxResult
    {
        return m_loc[0]->SetSlope(m_loc, slope, side);
    }

    auto SetSlopeType(LXtSlopeType type, unsigned int side) -> LxResult
    {
        return m_loc[0]->SetSlopeType(m_loc, type, side);
    }

    auto SetWeight(double weight, unsigned int reset, unsigned int side) -> LxResult
    {
        return m_loc[0]->SetWeight(m_loc, weight, reset, side);
    }

    auto AddF(double time, double value) -> LxResult
    {
        return m_loc[0]->AddF(m_loc, time, value);
    }

    auto AddI(double time, int value) -> LxResult
    {
        return m_loc[0]->AddI(m_loc, time, value);
    }

    auto Delete(void) -> LxResult
    {
        return m_loc[0]->Delete(m_loc);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_GradientFilter
{
public:
    virtual ~CLxImpl_GradientFilter() = default;

    virtual unsigned int grfilt_Type(void) = 0;

    virtual auto grfilt_Generate([[maybe_unused]] double time) -> double
    {
        return 0;
    }

    virtual auto grfilt_Evaluate([[maybe_unused]] double time, [[maybe_unused]] double value) -> double
    {
        return 0;
    }

    virtual auto grfilt_MultiSample([[maybe_unused]] double time, [[maybe_unused]] ILxUnknownID other) -> double
    {
        return 0;
    }
};

#define LXxD_GradientFilter_Type unsigned int grfilt_Type() override
#define LXxO_GradientFilter_Type LXxD_GradientFilter_Type
#define LXxC_GradientFilter_Type(c) unsigned int c::grfilt_Type()
#define LXxD_GradientFilter_Generate double grfilt_Generate([[maybe_unused]] double time) override
#define LXxO_GradientFilter_Generate LXxD_GradientFilter_Generate
#define LXxC_GradientFilter_Generate(c) double c::grfilt_Generate([[maybe_unused]] double time)
#define LXxD_GradientFilter_Evaluate double grfilt_Evaluate([[maybe_unused]] double time, [[maybe_unused]] double value) override
#define LXxO_GradientFilter_Evaluate LXxD_GradientFilter_Evaluate
#define LXxC_GradientFilter_Evaluate(c) double c::grfilt_Evaluate([[maybe_unused]] double time, [[maybe_unused]] double value)
#define LXxD_GradientFilter_MultiSample double grfilt_MultiSample([[maybe_unused]] double time, [[maybe_unused]] ILxUnknownID other) override
#define LXxO_GradientFilter_MultiSample LXxD_GradientFilter_MultiSample
#define LXxC_GradientFilter_MultiSample(c) double c::grfilt_MultiSample([[maybe_unused]] double time, [[maybe_unused]] ILxUnknownID other)

template <class T>
class CLxIfc_GradientFilter: public CLxInterface
{
public:
    CLxIfc_GradientFilter()
    {
        vt.Type = Type;
        vt.Generate = Generate;
        vt.Evaluate = Evaluate;
        vt.MultiSample = MultiSample;
        vTable = &vt.iunk;
        iid = &lx::guid_GradientFilter;
    }

    static auto Type(LXtObjectID wcom) -> unsigned int
    {
        LXCWxINST (CLxImpl_GradientFilter, loc);
        return loc->grfilt_Type();
    }

    static auto Generate(LXtObjectID wcom,double time) -> double
    {
        LXCWxINST (CLxImpl_GradientFilter, loc);
        return loc->grfilt_Generate( time);
    }

    static auto Evaluate(LXtObjectID wcom,double time,double value) -> double
    {
        LXCWxINST (CLxImpl_GradientFilter, loc);
        return loc->grfilt_Evaluate( time, value);
    }

    static auto MultiSample(LXtObjectID wcom,double time,LXtObjectID other) -> double
    {
        LXCWxINST (CLxImpl_GradientFilter, loc);
        return loc->grfilt_MultiSample( time,(ILxUnknownID) other);
    }

private:
    ILxGradientFilter vt;
};

class CLxLoc_GradientFilter : public CLxLocalize<ILxGradientFilterID>
{
public:
    CLxLoc_GradientFilter()
    {
        _init();
    }

    CLxLoc_GradientFilter(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_GradientFilter(CLxLoc_GradientFilter const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_GradientFilter;
    }

    auto Type(void) -> unsigned int
    {
        return m_loc[0]->Type(m_loc);
    }

    auto Generate(double time) -> double
    {
        return m_loc[0]->Generate(m_loc, time);
    }

    auto Evaluate(double time, double value) -> double
    {
        return m_loc[0]->Evaluate(m_loc, time, value);
    }

    auto MultiSample(double time, ILxUnknownID other) -> double
    {
        return m_loc[0]->MultiSample(m_loc, time,(ILxUnknownID) other);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};

