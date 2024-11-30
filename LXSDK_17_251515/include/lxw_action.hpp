//
// C++ wrapper for lxsdk/lxaction.h.
//
//	Copyright 2024.
//
//
#pragma once

#include <lxaction.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx
{
    static LXtGUID const guid_ActionListener = {0x4819A297, {0xA922, 0x11D8}, {0xB1, 0xAD, 0x00, 0x03, 0x93, 0xCE, 0x96, 0x80}};
    static LXtGUID const guid_ChannelRead = {0xD5A8C4FD, {0x151C, 0x4D8B}, {0x97, 0xE1, 0x6E, 0x1B, 0x40, 0x87, 0x88, 0x6B}};
    static LXtGUID const guid_ChannelWrite = {0x91BFE3B8, {0x16C6, 0x4195}, {0xBF, 0xE5, 0x3F, 0x0E, 0x3C, 0x0C, 0x5C, 0x57}};
    static LXtGUID const guid_EvalModifier = {0x30AAAF24, {0x9699, 0x4737}, {0x8E, 0x3B, 0xE2, 0x64, 0xAA, 0x4B, 0x7A, 0x3E}};
    static LXtGUID const guid_Modifier = {0x8D3BEC86, {0xE10B, 0x426A}, {0x8B, 0xA3, 0x84, 0x62, 0x50, 0xE2, 0x5A, 0xF4}};
    static LXtGUID const guid_SimulationModifier = {0xA44F37F3, {0xE94F, 0x4042}, {0x85, 0xE2, 0x1B, 0xBF, 0x63, 0x3E, 0x00, 0xD2}};
    static LXtGUID const guid_Evaluation = {0xFB552E5F, {0x746E, 0x4d74}, {0x88, 0x5C, 0x40, 0xA9, 0x31, 0xB8, 0x2B, 0x84}};
    static LXtGUID const guid_Modifier1 = {0xFA406E1C, {0x5E6A, 0x4574}, {0xA7, 0x95, 0xAA, 0x0F, 0x07, 0xDF, 0xAF, 0xB5}};
    static LXtGUID const guid_Evaluator = {0x7F4B20C2, {0x5646, 0x475B}, {0x90, 0x6F, 0xFA, 0x3C, 0xB9, 0x02, 0x6D, 0x99}};
} // namespace lx

class CLxImpl_ActionListener
{
public:
    virtual ~CLxImpl_ActionListener() = default;

    virtual void actl_ActionChannelSignal([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned channel)
    {
    }

    virtual void actl_ActionChannelConstantChange([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned channel)
    {
    }

    virtual void actl_ActionChannelConstantPreChange([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned channel)
    {
    }
};

#define LXxD_ActionListener_ActionChannelSignal void actl_ActionChannelSignal([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned channel) override
#define LXxO_ActionListener_ActionChannelSignal LXxD_ActionListener_ActionChannelSignal
#define LXxC_ActionListener_ActionChannelSignal(c) void c::actl_ActionChannelSignal([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned channel)
#define LXxD_ActionListener_ActionChannelConstantChange void actl_ActionChannelConstantChange([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned channel) override
#define LXxO_ActionListener_ActionChannelConstantChange LXxD_ActionListener_ActionChannelConstantChange
#define LXxC_ActionListener_ActionChannelConstantChange(c) void c::actl_ActionChannelConstantChange([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned channel)
#define LXxD_ActionListener_ActionChannelConstantPreChange void actl_ActionChannelConstantPreChange([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned channel) override
#define LXxO_ActionListener_ActionChannelConstantPreChange LXxD_ActionListener_ActionChannelConstantPreChange
#define LXxC_ActionListener_ActionChannelConstantPreChange(c) void c::actl_ActionChannelConstantPreChange([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned channel)

template <class T>
class CLxIfc_ActionListener: public CLxInterface
{
public:
    CLxIfc_ActionListener()
    {
        vt.ActionChannelSignal = ActionChannelSignal;
        vt.ActionChannelConstantChange = ActionChannelConstantChange;
        vt.ActionChannelConstantPreChange = ActionChannelConstantPreChange;
        vTable = &vt.iunk;
        iid = &lx::guid_ActionListener;
    }

    static auto ActionChannelSignal(LXtObjectID wcom,LXtObjectID item,unsigned channel) -> void
    {
        LXCWxINST (CLxImpl_ActionListener, loc);
        loc->actl_ActionChannelSignal((ILxUnknownID) item, channel);
    }

    static auto ActionChannelConstantChange(LXtObjectID wcom,LXtObjectID item,unsigned channel) -> void
    {
        LXCWxINST (CLxImpl_ActionListener, loc);
        loc->actl_ActionChannelConstantChange((ILxUnknownID) item, channel);
    }

    static auto ActionChannelConstantPreChange(LXtObjectID wcom,LXtObjectID item,unsigned channel) -> void
    {
        LXCWxINST (CLxImpl_ActionListener, loc);
        loc->actl_ActionChannelConstantPreChange((ILxUnknownID) item, channel);
    }

private:
    ILxActionListener vt;
};

class CLxLoc_ActionListener : public CLxLocalize<ILxActionListenerID>
{
public:
    CLxLoc_ActionListener()
    {
        _init();
    }

    CLxLoc_ActionListener(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_ActionListener(CLxLoc_ActionListener const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_ActionListener;
    }

    auto ActionChannelSignal(ILxUnknownID item, unsigned channel) -> void
    {
        m_loc[0]->ActionChannelSignal(m_loc,(ILxUnknownID) item, channel);
    }

    auto ActionChannelConstantChange(ILxUnknownID item, unsigned channel) -> void
    {
        m_loc[0]->ActionChannelConstantChange(m_loc,(ILxUnknownID) item, channel);
    }

    auto ActionChannelConstantPreChange(ILxUnknownID item, unsigned channel) -> void
    {
        m_loc[0]->ActionChannelConstantPreChange(m_loc,(ILxUnknownID) item, channel);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_ChannelRead : public CLxLocalize<ILxChannelReadID>
{
public:
    CLxLoc_ChannelRead()
    {
        _init();
    }

    CLxLoc_ChannelRead(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_ChannelRead(CLxLoc_ChannelRead const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_ChannelRead;
    }

    auto ValueObj(ILxUnknownID item, unsigned int channel, void **ppvObj) -> LxResult
    {
        return m_loc[0]->ValueObj(m_loc,(ILxUnknownID) item, channel, ppvObj);
    }

    auto ValueObj(ILxUnknownID item, unsigned int channel, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->ValueObj(m_loc,(ILxUnknownID) item, channel, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Integer(ILxUnknownID item, unsigned int channel, int *value) -> LxResult
    {
        return m_loc[0]->Integer(m_loc,(ILxUnknownID) item, channel, value);
    }

    auto Double(ILxUnknownID item, unsigned int channel, double *value) -> LxResult
    {
        return m_loc[0]->Double(m_loc,(ILxUnknownID) item, channel, value);
    }

    auto String(ILxUnknownID item, unsigned int channel, const char **value) -> LxResult
    {
        return m_loc[0]->String(m_loc,(ILxUnknownID) item, channel, value);
    }

    auto Envelope(ILxUnknownID item, unsigned int channel, void **ppvObj) -> LxResult
    {
        return m_loc[0]->Envelope(m_loc,(ILxUnknownID) item, channel, ppvObj);
    }

    auto Envelope(ILxUnknownID item, unsigned int channel, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Envelope(m_loc,(ILxUnknownID) item, channel, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Time(void) -> double
    {
        return m_loc[0]->Time(m_loc);
    }

    auto IsAnimated(ILxUnknownID item, int index) const -> int
    {
        return m_loc[0]->IsAnimated(m_loc,(ILxUnknownID) item, index);
    }

    auto IsBaked(ILxUnknownID item, unsigned int channel) const -> LxResult
    {
        return m_loc[0]->IsBaked(m_loc,(ILxUnknownID) item, channel);
    }

    auto BakedSamples(ILxUnknownID item, unsigned int channel, double *firstSample, double *spsRate, void **ppvObj) -> LxResult
    {
        return m_loc[0]->BakedSamples(m_loc,(ILxUnknownID) item, channel, firstSample, spsRate, ppvObj);
    }

    auto BakedSamples(ILxUnknownID item, unsigned int channel, double *firstSample, double *spsRate, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->BakedSamples(m_loc,(ILxUnknownID) item, channel, firstSample, spsRate, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto SetTime(double time) -> LxResult
    {
        return m_loc[0]->SetTime(m_loc, time);
    }

    auto Type(ILxUnknownID item, unsigned int channel, unsigned *type) -> LxResult
    {
        return m_loc[0]->Type(m_loc,(ILxUnknownID) item, channel, type);
    }

    auto TypeName(ILxUnknownID item, unsigned int channel, const char **typeName) -> LxResult
    {
        return m_loc[0]->TypeName(m_loc,(ILxUnknownID) item, channel, typeName);
    }

    auto EncodedInt(ILxUnknownID item, unsigned int channel, char *buf, unsigned len) -> LxResult
    {
        return m_loc[0]->EncodedInt(m_loc,(ILxUnknownID) item, channel, buf, len);
    }

    auto EncodedInt(ILxUnknownID item, unsigned int channel, std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->EncodedInt(m_loc,(ILxUnknownID) item, channel, buf, len);
        LXWx_SBUF2
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_ChannelWrite : public CLxLocalize<ILxChannelWriteID>
{
public:
    CLxLoc_ChannelWrite()
    {
        _init();
    }

    CLxLoc_ChannelWrite(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_ChannelWrite(CLxLoc_ChannelWrite const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_ChannelWrite;
    }

    auto ValueObj(ILxUnknownID item, unsigned int channel, void **ppvObj) -> LxResult
    {
        return m_loc[0]->ValueObj(m_loc,(ILxUnknownID) item, channel, ppvObj);
    }

    auto ValueObj(ILxUnknownID item, unsigned int channel, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->ValueObj(m_loc,(ILxUnknownID) item, channel, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Integer(ILxUnknownID item, unsigned int channel, int value) -> LxResult
    {
        return m_loc[0]->Integer(m_loc,(ILxUnknownID) item, channel, value);
    }

    auto Double(ILxUnknownID item, unsigned int channel, double value) -> LxResult
    {
        return m_loc[0]->Double(m_loc,(ILxUnknownID) item, channel, value);
    }

    auto String(ILxUnknownID item, unsigned int channel, const char *value) -> LxResult
    {
        return m_loc[0]->String(m_loc,(ILxUnknownID) item, channel, value);
    }

    auto Envelope(ILxUnknownID item, unsigned int channel, void **ppvObj) -> LxResult
    {
        return m_loc[0]->Envelope(m_loc,(ILxUnknownID) item, channel, ppvObj);
    }

    auto Envelope(ILxUnknownID item, unsigned int channel, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Envelope(m_loc,(ILxUnknownID) item, channel, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto IntegerKey(ILxUnknownID item, unsigned int channel, int value, int create) -> LxResult
    {
        return m_loc[0]->IntegerKey(m_loc,(ILxUnknownID) item, channel, value, create);
    }

    auto DoubleKey(ILxUnknownID item, unsigned int channel, double value, int create) -> LxResult
    {
        return m_loc[0]->DoubleKey(m_loc,(ILxUnknownID) item, channel, value, create);
    }

    auto SetState(ILxUnknownID item, unsigned int channel, unsigned int state) -> LxResult
    {
        return m_loc[0]->SetState(m_loc,(ILxUnknownID) item, channel, state);
    }

    auto BakeSamples(ILxUnknownID item, unsigned int channel, double firstSample, double spsRate, void **ppvObj) -> LxResult
    {
        return m_loc[0]->BakeSamples(m_loc,(ILxUnknownID) item, channel, firstSample, spsRate, ppvObj);
    }

    auto BakeSamples(ILxUnknownID item, unsigned int channel, double firstSample, double spsRate, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->BakeSamples(m_loc,(ILxUnknownID) item, channel, firstSample, spsRate, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Type(ILxUnknownID item, unsigned int channel, unsigned *type) -> LxResult
    {
        return m_loc[0]->Type(m_loc,(ILxUnknownID) item, channel, type);
    }

    auto TypeName(ILxUnknownID item, unsigned int channel, const char **typeName) -> LxResult
    {
        return m_loc[0]->TypeName(m_loc,(ILxUnknownID) item, channel, typeName);
    }

    auto EncodedInt(ILxUnknownID item, unsigned int channel, const char *value) -> LxResult
    {
        return m_loc[0]->EncodedInt(m_loc,(ILxUnknownID) item, channel, value);
    }

    auto EncodedIntKey(ILxUnknownID item, unsigned int channel, const char *value) -> LxResult
    {
        return m_loc[0]->EncodedIntKey(m_loc,(ILxUnknownID) item, channel, value);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_EvalModifier
{
public:
    virtual ~CLxImpl_EvalModifier() = default;

    virtual auto eval_Reset([[maybe_unused]] ILxUnknownID scene) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto eval_Next([[maybe_unused]] unsigned *index) -> LXtObjectID
    {
        return 0;
    }

    virtual auto eval_Alloc([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned index, [[maybe_unused]] ILxUnknownID eval, [[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_EvalModifier_Reset LxResult eval_Reset([[maybe_unused]] ILxUnknownID scene) override
#define LXxO_EvalModifier_Reset LXxD_EvalModifier_Reset
#define LXxC_EvalModifier_Reset(c) LxResult c::eval_Reset([[maybe_unused]] ILxUnknownID scene)
#define LXxD_EvalModifier_Next LXtObjectID eval_Next([[maybe_unused]] unsigned *index) override
#define LXxO_EvalModifier_Next LXxD_EvalModifier_Next
#define LXxC_EvalModifier_Next(c) LXtObjectID c::eval_Next([[maybe_unused]] unsigned *index)
#define LXxD_EvalModifier_Alloc LxResult eval_Alloc([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned index, [[maybe_unused]] ILxUnknownID eval, [[maybe_unused]] void **ppvObj) override
#define LXxO_EvalModifier_Alloc LXxD_EvalModifier_Alloc
#define LXxC_EvalModifier_Alloc(c) LxResult c::eval_Alloc([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned index, [[maybe_unused]] ILxUnknownID eval, [[maybe_unused]] void **ppvObj)

template <class T>
class CLxIfc_EvalModifier: public CLxInterface
{
public:
    CLxIfc_EvalModifier()
    {
        vt.Reset = Reset;
        vt.Next = Next;
        vt.Alloc = Alloc;
        vTable = &vt.iunk;
        iid = &lx::guid_EvalModifier;
    }

    static auto Reset(LXtObjectID wcom,LXtObjectID scene) -> LxResult
    {
        LXCWxINST (CLxImpl_EvalModifier, loc);
        try
        {
           return loc->eval_Reset((ILxUnknownID) scene);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Next(LXtObjectID wcom,unsigned *index) -> LXtObjectID
    {
        LXCWxINST (CLxImpl_EvalModifier, loc);
        return loc->eval_Next( index);
    }

    static auto Alloc(LXtObjectID wcom,LXtObjectID item,unsigned index,LXtObjectID eval,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_EvalModifier, loc);
        try
        {
           return loc->eval_Alloc((ILxUnknownID) item, index,(ILxUnknownID) eval, ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxEvalModifier vt;
};

class CLxLoc_EvalModifier : public CLxLocalize<ILxEvalModifierID>
{
public:
    CLxLoc_EvalModifier()
    {
        _init();
    }

    CLxLoc_EvalModifier(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_EvalModifier(CLxLoc_EvalModifier const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_EvalModifier;
    }

    auto Reset(ILxUnknownID scene) -> LxResult
    {
        return m_loc[0]->Reset(m_loc,(ILxUnknownID) scene);
    }

    auto Next(unsigned *index) -> ILxUnknownID
    {
        return (ILxUnknownID)m_loc[0]->Next(m_loc, index);
    }

    auto Alloc(ILxUnknownID item, unsigned index, ILxUnknownID eval, void **ppvObj) -> LxResult
    {
        return m_loc[0]->Alloc(m_loc,(ILxUnknownID) item, index,(ILxUnknownID) eval, ppvObj);
    }

    auto Alloc(ILxUnknownID item, unsigned index, ILxUnknownID eval, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Alloc(m_loc,(ILxUnknownID) item, index,(ILxUnknownID) eval, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_Modifier
{
public:
    virtual ~CLxImpl_Modifier() = default;

    virtual auto mod_Evaluate([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto mod_Test([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned index) -> LxResult
    {
        return LXe_TRUE;
    }

    virtual auto mod_Invalidate([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned index) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto mod_Validate([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned index, [[maybe_unused]] LxResult rc) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto mod_RequiredCount([[maybe_unused]] void) -> unsigned
    {
        return 0;
    }

    virtual auto mod_Required([[maybe_unused]] unsigned index, [[maybe_unused]] unsigned *attr, [[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual void mod_Free([[maybe_unused]] void *cache)
    {
    }
};

#define LXxD_Modifier_Evaluate LxResult mod_Evaluate() override
#define LXxO_Modifier_Evaluate LXxD_Modifier_Evaluate
#define LXxC_Modifier_Evaluate(c) LxResult c::mod_Evaluate()
#define LXxD_Modifier_Test LxResult mod_Test([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned index) override
#define LXxO_Modifier_Test LXxD_Modifier_Test
#define LXxC_Modifier_Test(c) LxResult c::mod_Test([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned index)
#define LXxD_Modifier_Invalidate LxResult mod_Invalidate([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned index) override
#define LXxO_Modifier_Invalidate LXxD_Modifier_Invalidate
#define LXxC_Modifier_Invalidate(c) LxResult c::mod_Invalidate([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned index)
#define LXxD_Modifier_Validate LxResult mod_Validate([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned index, [[maybe_unused]] LxResult rc) override
#define LXxO_Modifier_Validate LXxD_Modifier_Validate
#define LXxC_Modifier_Validate(c) LxResult c::mod_Validate([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned index, [[maybe_unused]] LxResult rc)
#define LXxD_Modifier_RequiredCount unsigned mod_RequiredCount() override
#define LXxO_Modifier_RequiredCount LXxD_Modifier_RequiredCount
#define LXxC_Modifier_RequiredCount(c) unsigned c::mod_RequiredCount()
#define LXxD_Modifier_Required LxResult mod_Required([[maybe_unused]] unsigned index, [[maybe_unused]] unsigned *attr, [[maybe_unused]] void **ppvObj) override
#define LXxO_Modifier_Required LXxD_Modifier_Required
#define LXxC_Modifier_Required(c) LxResult c::mod_Required([[maybe_unused]] unsigned index, [[maybe_unused]] unsigned *attr, [[maybe_unused]] void **ppvObj)
#define LXxD_Modifier_Free void mod_Free([[maybe_unused]] void *cache) override
#define LXxO_Modifier_Free LXxD_Modifier_Free
#define LXxC_Modifier_Free(c) void c::mod_Free([[maybe_unused]] void *cache)

template <class T>
class CLxIfc_Modifier: public CLxInterface
{
public:
    CLxIfc_Modifier()
    {
        vt.Evaluate = Evaluate;
        vt.Test = Test;
        vt.Invalidate = Invalidate;
        vt.Validate = Validate;
        vt.RequiredCount = RequiredCount;
        vt.Required = Required;
        vt.Free = Free;
        vTable = &vt.iunk;
        iid = &lx::guid_Modifier;
    }

    static auto Evaluate(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_Modifier, loc);
        try
        {
           return loc->mod_Evaluate();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Test(LXtObjectID wcom,LXtObjectID item,unsigned index) -> LxResult
    {
        LXCWxINST (CLxImpl_Modifier, loc);
        try
        {
           return loc->mod_Test((ILxUnknownID) item, index);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Invalidate(LXtObjectID wcom,LXtObjectID item,unsigned index) -> LxResult
    {
        LXCWxINST (CLxImpl_Modifier, loc);
        try
        {
           return loc->mod_Invalidate((ILxUnknownID) item, index);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Validate(LXtObjectID wcom,LXtObjectID item,unsigned index,LxResult rc) -> LxResult
    {
        LXCWxINST (CLxImpl_Modifier, loc);
        try
        {
           return loc->mod_Validate((ILxUnknownID) item, index, rc);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto RequiredCount(LXtObjectID wcom) -> unsigned
    {
        LXCWxINST (CLxImpl_Modifier, loc);
        return loc->mod_RequiredCount();
    }

    static auto Required(LXtObjectID wcom,unsigned index,unsigned *attr,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_Modifier, loc);
        try
        {
           return loc->mod_Required( index, attr, ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Free(LXtObjectID wcom,void *cache) -> void
    {
        LXCWxINST (CLxImpl_Modifier, loc);
        loc->mod_Free( cache);
    }

private:
    ILxModifier vt;
};

class CLxLoc_Modifier : public CLxLocalize<ILxModifierID>
{
public:
    CLxLoc_Modifier()
    {
        _init();
    }

    CLxLoc_Modifier(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_Modifier(CLxLoc_Modifier const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_Modifier;
    }

    auto Evaluate(void) -> LxResult
    {
        return m_loc[0]->Evaluate(m_loc);
    }

    auto Test(ILxUnknownID item, unsigned index) -> LxResult
    {
        return m_loc[0]->Test(m_loc,(ILxUnknownID) item, index);
    }

    auto Invalidate(ILxUnknownID item, unsigned index) -> LxResult
    {
        return m_loc[0]->Invalidate(m_loc,(ILxUnknownID) item, index);
    }

    auto Validate(ILxUnknownID item, unsigned index, LxResult rc) -> LxResult
    {
        return m_loc[0]->Validate(m_loc,(ILxUnknownID) item, index, rc);
    }

    auto RequiredCount(void) -> unsigned
    {
        return m_loc[0]->RequiredCount(m_loc);
    }

    auto Required(unsigned index, unsigned *attr, void **ppvObj) -> LxResult
    {
        return m_loc[0]->Required(m_loc, index, attr, ppvObj);
    }

    auto Required(unsigned index, unsigned *attr, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Required(m_loc, index, attr, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Free(void *cache) -> void
    {
        m_loc[0]->Free(m_loc, cache);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_SimulationModifier
{
public:
    virtual ~CLxImpl_SimulationModifier() = default;

    virtual auto sim_Enabled([[maybe_unused]] ILxUnknownID chanRead) -> LxResult
    {
        return LXe_TRUE;
    }

    virtual auto sim_Initialize([[maybe_unused]] double time, [[maybe_unused]] double sample) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual void sim_Cleanup([[maybe_unused]] void)
    {
    }

    virtual auto sim_StepSize([[maybe_unused]] double *stepSize) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto sim_Step([[maybe_unused]] double dt) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto sim_Bake([[maybe_unused]] double time) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_SimulationModifier_Enabled LxResult sim_Enabled([[maybe_unused]] ILxUnknownID chanRead) override
#define LXxO_SimulationModifier_Enabled LXxD_SimulationModifier_Enabled
#define LXxC_SimulationModifier_Enabled(c) LxResult c::sim_Enabled([[maybe_unused]] ILxUnknownID chanRead)
#define LXxD_SimulationModifier_Initialize LxResult sim_Initialize([[maybe_unused]] double time, [[maybe_unused]] double sample) override
#define LXxO_SimulationModifier_Initialize LXxD_SimulationModifier_Initialize
#define LXxC_SimulationModifier_Initialize(c) LxResult c::sim_Initialize([[maybe_unused]] double time, [[maybe_unused]] double sample)
#define LXxD_SimulationModifier_Cleanup void sim_Cleanup() override
#define LXxO_SimulationModifier_Cleanup LXxD_SimulationModifier_Cleanup
#define LXxC_SimulationModifier_Cleanup(c) void c::sim_Cleanup()
#define LXxD_SimulationModifier_StepSize LxResult sim_StepSize([[maybe_unused]] double *stepSize) override
#define LXxO_SimulationModifier_StepSize LXxD_SimulationModifier_StepSize
#define LXxC_SimulationModifier_StepSize(c) LxResult c::sim_StepSize([[maybe_unused]] double *stepSize)
#define LXxD_SimulationModifier_Step LxResult sim_Step([[maybe_unused]] double dt) override
#define LXxO_SimulationModifier_Step LXxD_SimulationModifier_Step
#define LXxC_SimulationModifier_Step(c) LxResult c::sim_Step([[maybe_unused]] double dt)
#define LXxD_SimulationModifier_Bake LxResult sim_Bake([[maybe_unused]] double time) override
#define LXxO_SimulationModifier_Bake LXxD_SimulationModifier_Bake
#define LXxC_SimulationModifier_Bake(c) LxResult c::sim_Bake([[maybe_unused]] double time)

template <class T>
class CLxIfc_SimulationModifier: public CLxInterface
{
public:
    CLxIfc_SimulationModifier()
    {
        vt.Enabled = Enabled;
        vt.Initialize = Initialize;
        vt.Cleanup = Cleanup;
        vt.StepSize = StepSize;
        vt.Step = Step;
        vt.Bake = Bake;
        vTable = &vt.iunk;
        iid = &lx::guid_SimulationModifier;
    }

    static auto Enabled(LXtObjectID wcom,LXtObjectID chanRead) -> LxResult
    {
        LXCWxINST (CLxImpl_SimulationModifier, loc);
        try
        {
           return loc->sim_Enabled((ILxUnknownID) chanRead);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Initialize(LXtObjectID wcom,double time,double sample) -> LxResult
    {
        LXCWxINST (CLxImpl_SimulationModifier, loc);
        try
        {
           return loc->sim_Initialize( time, sample);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Cleanup(LXtObjectID wcom) -> void
    {
        LXCWxINST (CLxImpl_SimulationModifier, loc);
        loc->sim_Cleanup();
    }

    static auto StepSize(LXtObjectID wcom,double *stepSize) -> LxResult
    {
        LXCWxINST (CLxImpl_SimulationModifier, loc);
        try
        {
           return loc->sim_StepSize( stepSize);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Step(LXtObjectID wcom,double dt) -> LxResult
    {
        LXCWxINST (CLxImpl_SimulationModifier, loc);
        try
        {
           return loc->sim_Step( dt);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Bake(LXtObjectID wcom,double time) -> LxResult
    {
        LXCWxINST (CLxImpl_SimulationModifier, loc);
        try
        {
           return loc->sim_Bake( time);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxSimulationModifier vt;
};

class CLxLoc_SimulationModifier : public CLxLocalize<ILxSimulationModifierID>
{
public:
    CLxLoc_SimulationModifier()
    {
        _init();
    }

    CLxLoc_SimulationModifier(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_SimulationModifier(CLxLoc_SimulationModifier const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_SimulationModifier;
    }

    auto Enabled(ILxUnknownID chanRead) -> LxResult
    {
        return m_loc[0]->Enabled(m_loc,(ILxUnknownID) chanRead);
    }

    auto Initialize(double time, double sample) -> LxResult
    {
        return m_loc[0]->Initialize(m_loc, time, sample);
    }

    auto Cleanup(void) -> void
    {
        m_loc[0]->Cleanup(m_loc);
    }

    auto StepSize(double *stepSize) -> LxResult
    {
        return m_loc[0]->StepSize(m_loc, stepSize);
    }

    auto Step(double dt) -> LxResult
    {
        return m_loc[0]->Step(m_loc, dt);
    }

    auto Bake(double time) -> LxResult
    {
        return m_loc[0]->Bake(m_loc, time);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_Evaluation : public CLxLocalize<ILxEvaluationID>
{
public:
    CLxLoc_Evaluation()
    {
        _init();
    }

    CLxLoc_Evaluation(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_Evaluation(CLxLoc_Evaluation const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_Evaluation;
    }

    auto AddChannel(ILxUnknownID item, unsigned index, unsigned type, unsigned *attr) -> LxResult
    {
        return m_loc[0]->AddChannel(m_loc,(ILxUnknownID) item, index, type, attr);
    }

    auto AddChannelName(ILxUnknownID item, const char *name, unsigned type, unsigned *attr) -> LxResult
    {
        return m_loc[0]->AddChannelName(m_loc,(ILxUnknownID) item, name, type, attr);
    }

    auto ReadTime(unsigned *attr) -> LxResult
    {
        return m_loc[0]->ReadTime(m_loc, attr);
    }

    auto SetAlternateTime(double time) -> LxResult
    {
        return m_loc[0]->SetAlternateTime(m_loc, time);
    }

    auto SetAlternate(void **ppvObj) -> LxResult
    {
        return m_loc[0]->SetAlternate(m_loc, ppvObj);
    }

    auto SetAlternate(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->SetAlternate(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto ClearAlternate(void) -> LxResult
    {
        return m_loc[0]->ClearAlternate(m_loc);
    }

    auto SetCache(void *cache) -> LxResult
    {
        return m_loc[0]->SetCache(m_loc, cache);
    }

    auto GetCache(void) -> void *
    {
        return m_loc[0]->GetCache(m_loc);
    }

    auto SetAlternateSetup(void) -> LxResult
    {
        return m_loc[0]->SetAlternateSetup(m_loc);
    }

    auto GetBakedSample(unsigned index, unsigned bracket, double *fraction, void **ppvObj) -> LxResult
    {
        return m_loc[0]->GetBakedSample(m_loc, index, bracket, fraction, ppvObj);
    }

    auto GetBakedSample(unsigned index, unsigned bracket, double *fraction, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->GetBakedSample(m_loc, index, bracket, fraction, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto GetDT(void) -> double
    {
        return m_loc[0]->GetDT(m_loc);
    }

    auto SimulationState(unsigned *flags) -> LxResult
    {
        return m_loc[0]->SimulationState(m_loc, flags);
    }

    auto SimulationRange(double *start, double *end) -> LxResult
    {
        return m_loc[0]->SimulationRange(m_loc, start, end);
    }

    auto ForceValidations(void) -> LxResult
    {
        return m_loc[0]->ForceValidations(m_loc);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};

class CLxImpl_Evaluator
{
public:
    virtual ~CLxImpl_Evaluator() = default;

    virtual auto evaluator_AddChannel([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned index, [[maybe_unused]] unsigned type, [[maybe_unused]] unsigned *attr) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto evaluator_MarkReady([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto evaluator_SetFloat([[maybe_unused]] unsigned index, [[maybe_unused]] double val) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto evaluator_GetFloat([[maybe_unused]] unsigned index, [[maybe_unused]] double *val) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto evaluator_SetInt([[maybe_unused]] unsigned index, [[maybe_unused]] int val) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto evaluator_GetInt([[maybe_unused]] unsigned index, [[maybe_unused]] int *val) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto evaluator_SetObj([[maybe_unused]] unsigned index, [[maybe_unused]] ILxUnknownID obj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto evaluator_GetObj([[maybe_unused]] unsigned index, [[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_Evaluator_AddChannel LxResult evaluator_AddChannel([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned index, [[maybe_unused]] unsigned type, [[maybe_unused]] unsigned *attr) override
#define LXxO_Evaluator_AddChannel LXxD_Evaluator_AddChannel
#define LXxC_Evaluator_AddChannel(c) LxResult c::evaluator_AddChannel([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned index, [[maybe_unused]] unsigned type, [[maybe_unused]] unsigned *attr)
#define LXxD_Evaluator_MarkReady LxResult evaluator_MarkReady() override
#define LXxO_Evaluator_MarkReady LXxD_Evaluator_MarkReady
#define LXxC_Evaluator_MarkReady(c) LxResult c::evaluator_MarkReady()
#define LXxD_Evaluator_SetFloat LxResult evaluator_SetFloat([[maybe_unused]] unsigned index, [[maybe_unused]] double val) override
#define LXxO_Evaluator_SetFloat LXxD_Evaluator_SetFloat
#define LXxC_Evaluator_SetFloat(c) LxResult c::evaluator_SetFloat([[maybe_unused]] unsigned index, [[maybe_unused]] double val)
#define LXxD_Evaluator_GetFloat LxResult evaluator_GetFloat([[maybe_unused]] unsigned index, [[maybe_unused]] double *val) override
#define LXxO_Evaluator_GetFloat LXxD_Evaluator_GetFloat
#define LXxC_Evaluator_GetFloat(c) LxResult c::evaluator_GetFloat([[maybe_unused]] unsigned index, [[maybe_unused]] double *val)
#define LXxD_Evaluator_SetInt LxResult evaluator_SetInt([[maybe_unused]] unsigned index, [[maybe_unused]] int val) override
#define LXxO_Evaluator_SetInt LXxD_Evaluator_SetInt
#define LXxC_Evaluator_SetInt(c) LxResult c::evaluator_SetInt([[maybe_unused]] unsigned index, [[maybe_unused]] int val)
#define LXxD_Evaluator_GetInt LxResult evaluator_GetInt([[maybe_unused]] unsigned index, [[maybe_unused]] int *val) override
#define LXxO_Evaluator_GetInt LXxD_Evaluator_GetInt
#define LXxC_Evaluator_GetInt(c) LxResult c::evaluator_GetInt([[maybe_unused]] unsigned index, [[maybe_unused]] int *val)
#define LXxD_Evaluator_SetObj LxResult evaluator_SetObj([[maybe_unused]] unsigned index, [[maybe_unused]] ILxUnknownID obj) override
#define LXxO_Evaluator_SetObj LXxD_Evaluator_SetObj
#define LXxC_Evaluator_SetObj(c) LxResult c::evaluator_SetObj([[maybe_unused]] unsigned index, [[maybe_unused]] ILxUnknownID obj)
#define LXxD_Evaluator_GetObj LxResult evaluator_GetObj([[maybe_unused]] unsigned index, [[maybe_unused]] void **ppvObj) override
#define LXxO_Evaluator_GetObj LXxD_Evaluator_GetObj
#define LXxC_Evaluator_GetObj(c) LxResult c::evaluator_GetObj([[maybe_unused]] unsigned index, [[maybe_unused]] void **ppvObj)

template <class T>
class CLxIfc_Evaluator: public CLxInterface
{
public:
    CLxIfc_Evaluator()
    {
        vt.AddChannel = AddChannel;
        vt.MarkReady = MarkReady;
        vt.SetFloat = SetFloat;
        vt.GetFloat = GetFloat;
        vt.SetInt = SetInt;
        vt.GetInt = GetInt;
        vt.SetObj = SetObj;
        vt.GetObj = GetObj;
        vTable = &vt.iunk;
        iid = &lx::guid_Evaluator;
    }

    static auto AddChannel(LXtObjectID wcom,LXtObjectID item,unsigned index,unsigned type,unsigned *attr) -> LxResult
    {
        LXCWxINST (CLxImpl_Evaluator, loc);
        try
        {
           return loc->evaluator_AddChannel((ILxUnknownID) item, index, type, attr);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto MarkReady(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_Evaluator, loc);
        try
        {
           return loc->evaluator_MarkReady();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SetFloat(LXtObjectID wcom,unsigned index,double val) -> LxResult
    {
        LXCWxINST (CLxImpl_Evaluator, loc);
        try
        {
           return loc->evaluator_SetFloat( index, val);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto GetFloat(LXtObjectID wcom,unsigned index,double *val) -> LxResult
    {
        LXCWxINST (CLxImpl_Evaluator, loc);
        try
        {
           return loc->evaluator_GetFloat( index, val);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SetInt(LXtObjectID wcom,unsigned index,int val) -> LxResult
    {
        LXCWxINST (CLxImpl_Evaluator, loc);
        try
        {
           return loc->evaluator_SetInt( index, val);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto GetInt(LXtObjectID wcom,unsigned index,int *val) -> LxResult
    {
        LXCWxINST (CLxImpl_Evaluator, loc);
        try
        {
           return loc->evaluator_GetInt( index, val);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SetObj(LXtObjectID wcom,unsigned index,LXtObjectID obj) -> LxResult
    {
        LXCWxINST (CLxImpl_Evaluator, loc);
        try
        {
           return loc->evaluator_SetObj( index,(ILxUnknownID) obj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto GetObj(LXtObjectID wcom,unsigned index,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_Evaluator, loc);
        try
        {
           return loc->evaluator_GetObj( index, ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxEvaluator vt;
};

class CLxLoc_Evaluator : public CLxLocalize<ILxEvaluatorID>
{
public:
    CLxLoc_Evaluator()
    {
        _init();
    }

    CLxLoc_Evaluator(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_Evaluator(CLxLoc_Evaluator const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_Evaluator;
    }

    auto AddChannel(ILxUnknownID item, unsigned index, unsigned type, unsigned *attr) -> LxResult
    {
        return m_loc[0]->AddChannel(m_loc,(ILxUnknownID) item, index, type, attr);
    }

    auto MarkReady(void) -> LxResult
    {
        return m_loc[0]->MarkReady(m_loc);
    }

    auto SetFloat(unsigned index, double val) -> LxResult
    {
        return m_loc[0]->SetFloat(m_loc, index, val);
    }

    auto GetFloat(unsigned index, double *val) -> LxResult
    {
        return m_loc[0]->GetFloat(m_loc, index, val);
    }

    auto SetInt(unsigned index, int val) -> LxResult
    {
        return m_loc[0]->SetInt(m_loc, index, val);
    }

    auto GetInt(unsigned index, int *val) -> LxResult
    {
        return m_loc[0]->GetInt(m_loc, index, val);
    }

    auto SetObj(unsigned index, ILxUnknownID obj) -> LxResult
    {
        return m_loc[0]->SetObj(m_loc, index,(ILxUnknownID) obj);
    }

    auto GetObj(unsigned index, void **ppvObj) -> LxResult
    {
        return m_loc[0]->GetObj(m_loc, index, ppvObj);
    }

    auto GetObj(unsigned index, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->GetObj(m_loc, index, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
