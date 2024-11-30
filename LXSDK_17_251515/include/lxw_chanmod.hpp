//
// C++ wrapper for lxsdk/lxchanmod.h.
//
//	Copyright 2024.
//
//
#pragma once

#include <lxchanmod.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx
{
    static LXtGUID const guid_ChannelModItem = {0x1955CFD9, {0x9E56, 0x42AB}, {0x94, 0xC8, 0xBF, 0x6B, 0xE1, 0xB0, 0x69, 0xD6}};
    static LXtGUID const guid_ChannelModifier = {0x7D633F1B, {0x41A9, 0x4151}, {0xB9, 0x4E, 0xA5, 0x03, 0x22, 0xDB, 0x62, 0xEB}};
    static LXtGUID const guid_ChannelModManager = {0x0F9981DD, {0xC1F7, 0x4D92}, {0x8D, 0x3D, 0x6F, 0x3C, 0x64, 0x40, 0x11, 0x62}};
    static LXtGUID const guid_ChannelModOperator = {0xB9D8203C, {0x54D4, 0x424C}, {0xB7, 0x6F, 0x33, 0x94, 0x39, 0x80, 0x3F, 0x1E}};
    static LXtGUID const guid_ChannelModSetup = {0x75D1C574, {0xC10E, 0x47A0}, {0xB6, 0xDA, 0x96, 0x29, 0x8A, 0xB2, 0x67, 0xE7}};
} // namespace lx

class CLxImpl_ChannelModItem
{
public:
    virtual ~CLxImpl_ChannelModItem() = default;

    virtual auto cmod_Allocate([[maybe_unused]] ILxUnknownID cmod, [[maybe_unused]] ILxUnknownID eval, [[maybe_unused]] ILxUnknownID item, [[maybe_unused]] void **ppvData) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual unsigned int cmod_Flags(ILxUnknownID item, unsigned int index) = 0;

    virtual auto cmod_Evaluate([[maybe_unused]] ILxUnknownID cmod, [[maybe_unused]] ILxUnknownID attr, [[maybe_unused]] void *data) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual void cmod_Cleanup([[maybe_unused]] void *data)
    {
    }
};

#define LXxD_ChannelModItem_Allocate LxResult cmod_Allocate([[maybe_unused]] ILxUnknownID cmod, [[maybe_unused]] ILxUnknownID eval, [[maybe_unused]] ILxUnknownID item, [[maybe_unused]] void **ppvData) override
#define LXxO_ChannelModItem_Allocate LXxD_ChannelModItem_Allocate
#define LXxC_ChannelModItem_Allocate(c) LxResult c::cmod_Allocate([[maybe_unused]] ILxUnknownID cmod, [[maybe_unused]] ILxUnknownID eval, [[maybe_unused]] ILxUnknownID item, [[maybe_unused]] void **ppvData)
#define LXxD_ChannelModItem_Flags unsigned int cmod_Flags([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned int index) override
#define LXxO_ChannelModItem_Flags LXxD_ChannelModItem_Flags
#define LXxC_ChannelModItem_Flags(c) unsigned int c::cmod_Flags([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] unsigned int index)
#define LXxD_ChannelModItem_Evaluate LxResult cmod_Evaluate([[maybe_unused]] ILxUnknownID cmod, [[maybe_unused]] ILxUnknownID attr, [[maybe_unused]] void *data) override
#define LXxO_ChannelModItem_Evaluate LXxD_ChannelModItem_Evaluate
#define LXxC_ChannelModItem_Evaluate(c) LxResult c::cmod_Evaluate([[maybe_unused]] ILxUnknownID cmod, [[maybe_unused]] ILxUnknownID attr, [[maybe_unused]] void *data)
#define LXxD_ChannelModItem_Cleanup void cmod_Cleanup([[maybe_unused]] void *data) override
#define LXxO_ChannelModItem_Cleanup LXxD_ChannelModItem_Cleanup
#define LXxC_ChannelModItem_Cleanup(c) void c::cmod_Cleanup([[maybe_unused]] void *data)

template <class T>
class CLxIfc_ChannelModItem: public CLxInterface
{
public:
    CLxIfc_ChannelModItem()
    {
        vt.Allocate = Allocate;
        vt.Flags = Flags;
        vt.Evaluate = Evaluate;
        vt.Cleanup = Cleanup;
        vTable = &vt.iunk;
        iid = &lx::guid_ChannelModItem;
    }

    static auto Allocate(LXtObjectID wcom,LXtObjectID cmod,LXtObjectID eval,LXtObjectID item,void **ppvData) -> LxResult
    {
        LXCWxINST (CLxImpl_ChannelModItem, loc);
        try
        {
           return loc->cmod_Allocate((ILxUnknownID) cmod,(ILxUnknownID) eval,(ILxUnknownID) item, ppvData);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Flags(LXtObjectID wcom,LXtObjectID item,unsigned int index) -> unsigned int
    {
        LXCWxINST (CLxImpl_ChannelModItem, loc);
        return loc->cmod_Flags((ILxUnknownID) item, index);
    }

    static auto Evaluate(LXtObjectID wcom,LXtObjectID cmod,LXtObjectID attr,void *data) -> LxResult
    {
        LXCWxINST (CLxImpl_ChannelModItem, loc);
        try
        {
           return loc->cmod_Evaluate((ILxUnknownID) cmod,(ILxUnknownID) attr, data);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Cleanup(LXtObjectID wcom,void *data) -> void
    {
        LXCWxINST (CLxImpl_ChannelModItem, loc);
        loc->cmod_Cleanup( data);
    }

private:
    ILxChannelModItem vt;
};


class CLxLoc_ChannelModifier : public CLxLocalize<ILxChannelModifierID>
{
public:
    CLxLoc_ChannelModifier()
    {
        _init();
    }

    CLxLoc_ChannelModifier(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_ChannelModifier(CLxLoc_ChannelModifier const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_ChannelModifier;
    }

    auto AddInput(ILxUnknownID item, unsigned int index) -> LxResult
    {
        return m_loc[0]->AddInput(m_loc,(ILxUnknownID) item, index);
    }

    auto AddOutput(ILxUnknownID item, unsigned int index) -> LxResult
    {
        return m_loc[0]->AddOutput(m_loc,(ILxUnknownID) item, index);
    }

    auto AddTime(void) -> LxResult
    {
        return m_loc[0]->AddTime(m_loc);
    }

    auto InputCount(unsigned int index, unsigned int *nInputs) -> LxResult
    {
        return m_loc[0]->InputCount(m_loc, index, nInputs);
    }

    auto OutputCount(unsigned int index, unsigned int *nOutputs) -> LxResult
    {
        return m_loc[0]->OutputCount(m_loc, index, nOutputs);
    }

    auto ReadInputFloat(ILxUnknownID attr, unsigned int inputIndex, double *dVal) -> LxResult
    {
        return m_loc[0]->ReadInputFloat(m_loc,(ILxUnknownID) attr, inputIndex, dVal);
    }

    auto ReadInputFloatByIndex(ILxUnknownID attr, unsigned int inputIndex, unsigned int linkIndex, double *dVal) -> LxResult
    {
        return m_loc[0]->ReadInputFloatByIndex(m_loc,(ILxUnknownID) attr, inputIndex, linkIndex, dVal);
    }

    auto ReadInputAngle(ILxUnknownID attr, unsigned int inputIndex, double *dVal) -> LxResult
    {
        return m_loc[0]->ReadInputAngle(m_loc,(ILxUnknownID) attr, inputIndex, dVal);
    }

    auto ReadInputInt(ILxUnknownID attr, unsigned int inputIndex, int *iVal) -> LxResult
    {
        return m_loc[0]->ReadInputInt(m_loc,(ILxUnknownID) attr, inputIndex, iVal);
    }

    auto ReadInputIntByIndex(ILxUnknownID attr, unsigned int inputIndex, unsigned int linkIndex, int *iVal) -> LxResult
    {
        return m_loc[0]->ReadInputIntByIndex(m_loc,(ILxUnknownID) attr, inputIndex, linkIndex, iVal);
    }

    auto ReadInputVal(ILxUnknownID attr, unsigned int inputIndex, void **val) -> LxResult
    {
        return m_loc[0]->ReadInputVal(m_loc,(ILxUnknownID) attr, inputIndex, val);
    }

    auto ReadInputValByIndex(ILxUnknownID attr, unsigned int inputIndex, unsigned int linkIndex, void **val) -> LxResult
    {
        return m_loc[0]->ReadInputValByIndex(m_loc,(ILxUnknownID) attr, inputIndex, linkIndex, val);
    }

    auto WriteOutputFloat(ILxUnknownID attr, unsigned int outputIndex, double dVal) -> LxResult
    {
        return m_loc[0]->WriteOutputFloat(m_loc,(ILxUnknownID) attr, outputIndex, dVal);
    }

    auto WriteOutputInt(ILxUnknownID attr, unsigned int outputIndex, int iVal) -> LxResult
    {
        return m_loc[0]->WriteOutputInt(m_loc,(ILxUnknownID) attr, outputIndex, iVal);
    }

    auto WriteOutputVal(ILxUnknownID attr, unsigned int outputIndex, void **val) -> LxResult
    {
        return m_loc[0]->WriteOutputVal(m_loc,(ILxUnknownID) attr, outputIndex, val);
    }

    auto WriteOutputValByIndex(ILxUnknownID attr, unsigned int outputIndex, unsigned int linkIndex, void **val) -> LxResult
    {
        return m_loc[0]->WriteOutputValByIndex(m_loc,(ILxUnknownID) attr, outputIndex, linkIndex, val);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_ChannelModManager
{
public:
    virtual ~CLxImpl_ChannelModManager() = default;

    virtual auto cman_Define([[maybe_unused]] ILxUnknownID cmod) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cman_Allocate([[maybe_unused]] ILxUnknownID cmod, [[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_ChannelModManager_Define LxResult cman_Define([[maybe_unused]] ILxUnknownID cmod) override
#define LXxO_ChannelModManager_Define LXxD_ChannelModManager_Define
#define LXxC_ChannelModManager_Define(c) LxResult c::cman_Define([[maybe_unused]] ILxUnknownID cmod)
#define LXxD_ChannelModManager_Allocate LxResult cman_Allocate([[maybe_unused]] ILxUnknownID cmod, [[maybe_unused]] void **ppvObj) override
#define LXxO_ChannelModManager_Allocate LXxD_ChannelModManager_Allocate
#define LXxC_ChannelModManager_Allocate(c) LxResult c::cman_Allocate([[maybe_unused]] ILxUnknownID cmod, [[maybe_unused]] void **ppvObj)

template <class T>
class CLxIfc_ChannelModManager: public CLxInterface
{
public:
    CLxIfc_ChannelModManager()
    {
        vt.Define = Define;
        vt.Allocate = Allocate;
        vTable = &vt.iunk;
        iid = &lx::guid_ChannelModManager;
    }

    static auto Define(LXtObjectID wcom,LXtObjectID cmod) -> LxResult
    {
        LXCWxINST (CLxImpl_ChannelModManager, loc);
        try
        {
           return loc->cman_Define((ILxUnknownID) cmod);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Allocate(LXtObjectID wcom,LXtObjectID cmod,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_ChannelModManager, loc);
        try
        {
           return loc->cman_Allocate((ILxUnknownID) cmod, ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxChannelModManager vt;
};


class CLxImpl_ChannelModOperator
{
public:
    virtual ~CLxImpl_ChannelModOperator() = default;

    virtual auto cmop_Evaluate([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_ChannelModOperator_Evaluate LxResult cmop_Evaluate() override
#define LXxO_ChannelModOperator_Evaluate LXxD_ChannelModOperator_Evaluate
#define LXxC_ChannelModOperator_Evaluate(c) LxResult c::cmop_Evaluate()

template <class T>
class CLxIfc_ChannelModOperator: public CLxInterface
{
public:
    CLxIfc_ChannelModOperator()
    {
        vt.Evaluate = Evaluate;
        vTable = &vt.iunk;
        iid = &lx::guid_ChannelModOperator;
    }

    static auto Evaluate(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_ChannelModOperator, loc);
        try
        {
           return loc->cmop_Evaluate();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxChannelModOperator vt;
};


class CLxLoc_ChannelModSetup : public CLxLocalize<ILxChannelModSetupID>
{
public:
    CLxLoc_ChannelModSetup()
    {
        _init();
    }

    CLxLoc_ChannelModSetup(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_ChannelModSetup(CLxLoc_ChannelModSetup const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_ChannelModSetup;
    }

    auto AddChannel(const char *name, unsigned int flags) -> LxResult
    {
        return m_loc[0]->AddChannel(m_loc, name, flags);
    }

    auto AddTime(void) -> LxResult
    {
        return m_loc[0]->AddTime(m_loc);
    }

    auto ReadValue(const char *name, void **ppvObj) -> LxResult
    {
        return m_loc[0]->ReadValue(m_loc, name, ppvObj);
    }

    auto ReadValue(const char *name, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->ReadValue(m_loc, name, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto ReadArray(const char *name, void **ppvObj) -> LxResult
    {
        return m_loc[0]->ReadArray(m_loc, name, ppvObj);
    }

    auto ReadArray(const char *name, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->ReadArray(m_loc, name, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto ReadTimeValue(void **ppvObj) -> LxResult
    {
        return m_loc[0]->ReadTimeValue(m_loc, ppvObj);
    }

    auto ReadTimeValue(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->ReadTimeValue(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto WriteValue(const char *name, void **ppvObj) -> LxResult
    {
        return m_loc[0]->WriteValue(m_loc, name, ppvObj);
    }

    auto WriteValue(const char *name, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->WriteValue(m_loc, name, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto GetEvaluation(void) -> ILxUnknownID
    {
        return (ILxUnknownID)m_loc[0]->GetEvaluation(m_loc);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
