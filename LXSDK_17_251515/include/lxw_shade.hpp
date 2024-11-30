//
// C++ wrapper for lxsdk/lxshade.h.
//
//	Copyright 2024.
//
//
#pragma once

#include <lxshade.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx
{
    static LXtGUID const guid_TextureLayer = {0x42369FE7, {0x869E, 0x4c61}, {0x8D, 0x40, 0xAC, 0x62, 0xE5, 0x29, 0xDD, 0x15}};
    static LXtGUID const guid_TextureEval1 = {0x847C1567, {0x1725, 0x4e98}, {0xBA, 0x09, 0xEA, 0x1F, 0x90, 0x49, 0xD7, 0x6A}};
    static LXtGUID const guid_TextureEval = {0x5791A0B4, {0x4B5C, 0x44EC}, {0x8D, 0x1D, 0xD8, 0xCA, 0x53, 0x83, 0x0F, 0xC9}};
    static LXtGUID const guid_TextureVMap = {0x0C68AC79, {0x993C, 0x4823}, {0x97, 0xFA, 0xEA, 0xD5, 0xEF, 0xF9, 0x7B, 0x64}};
    static LXtGUID const guid_TextureMask = {0x701E81D3, {0xFFA6, 0x475a}, {0xA0, 0x2D, 0xEC, 0xE9, 0xAB, 0x15, 0xB4, 0xCD}};
    static LXtGUID const guid_TextureGL = {0x55CE355E, {0xC838, 0x4222}, {0xAB, 0xED, 0xCB, 0xDD, 0x80, 0x82, 0x09, 0xAF}};
    static LXtGUID const guid_ValueTexture1 = {0xCA0E3524, {0x6F82, 0x44B8}, {0xAA, 0xC9, 0xDC, 0x25, 0x8F, 0x54, 0x8C, 0x02}};
    static LXtGUID const guid_ValueTexture = {0x9A2DD931, {0xF442, 0x488a}, {0x8C, 0x6A, 0xAF, 0x6B, 0xDD, 0xC3, 0x0B, 0x32}};
    static LXtGUID const guid_ValueTextureCustom = {0xDE3298A6, {0x1607, 0x4338}, {0xB0, 0x61, 0x18, 0x55, 0x28, 0xE6, 0xFB, 0x51}};
    static LXtGUID const guid_Texture = {0x6376D941, {0x9437, 0x4cf8}, {0xB6, 0xEC, 0xAB, 0x50, 0x79, 0x1F, 0xE6, 0x0F}};
    static LXtGUID const guid_CompShader1 = {0x06717e9d, {0x610d, 0x439f}, {0x93, 0x5b, 0xaf, 0x08, 0x05, 0x82, 0x7e, 0xde}};
    static LXtGUID const guid_CompShader = {0x371e8b57, {0x3a1e, 0x444b}, {0x91, 0xf8, 0x5e, 0x43, 0xc7, 0x5b, 0xf1, 0xcb}};
    static LXtGUID const guid_CustomMaterial1 = {0xd0c4106c, {0xdfd5, 0x4a58}, {0xad, 0x48, 0x45, 0xb5, 0x0a, 0xe6, 0x3f, 0x59}};
    static LXtGUID const guid_CustomMaterial2 = {0x64e2dd96, {0xff7f, 0x4c9b}, {0x96, 0x7e, 0x24, 0xde, 0xc8, 0x3b, 0xfb, 0x72}};
    static LXtGUID const guid_CustomMaterial3 = {0xB6297ECF, {0xCFE9, 0x4923}, {0xA7, 0x0C, 0xDB, 0x87, 0x27, 0x9B, 0x04, 0x11}};
    static LXtGUID const guid_CustomMaterial = {0x3AEBDFE5, {0xAB69, 0x4B58}, {0x8B, 0x8F, 0xE1, 0x09, 0x1D, 0x5F, 0x6D, 0xD5}};
} // namespace lx







class CLxImpl_ValueTexture1
{
public:
    virtual ~CLxImpl_ValueTexture1() = default;

    virtual auto vtx_SetupChannels([[maybe_unused]] ILxUnknownID addChan) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto vtx_LinkChannels([[maybe_unused]] ILxUnknownID eval, [[maybe_unused]] ILxUnknownID item) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto vtx_ReadChannels([[maybe_unused]] ILxUnknownID attr, [[maybe_unused]] void **ppvData) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto vtx_Customize([[maybe_unused]] ILxUnknownID custom, [[maybe_unused]] void **ppvData) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual void vtx_Evaluate([[maybe_unused]] ILxUnknownID vector, [[maybe_unused]] LXpTextureOutput *tOut, [[maybe_unused]] void *data)
    {
    }

    virtual void vtx_Cleanup([[maybe_unused]] void *data)
    {
    }
};

#define LXxD_ValueTexture1_SetupChannels LxResult vtx_SetupChannels([[maybe_unused]] ILxUnknownID addChan) override
#define LXxO_ValueTexture1_SetupChannels LXxD_ValueTexture1_SetupChannels
#define LXxC_ValueTexture1_SetupChannels(c) LxResult c::vtx_SetupChannels([[maybe_unused]] ILxUnknownID addChan)
#define LXxD_ValueTexture1_LinkChannels LxResult vtx_LinkChannels([[maybe_unused]] ILxUnknownID eval, [[maybe_unused]] ILxUnknownID item) override
#define LXxO_ValueTexture1_LinkChannels LXxD_ValueTexture1_LinkChannels
#define LXxC_ValueTexture1_LinkChannels(c) LxResult c::vtx_LinkChannels([[maybe_unused]] ILxUnknownID eval, [[maybe_unused]] ILxUnknownID item)
#define LXxD_ValueTexture1_ReadChannels LxResult vtx_ReadChannels([[maybe_unused]] ILxUnknownID attr, [[maybe_unused]] void **ppvData) override
#define LXxO_ValueTexture1_ReadChannels LXxD_ValueTexture1_ReadChannels
#define LXxC_ValueTexture1_ReadChannels(c) LxResult c::vtx_ReadChannels([[maybe_unused]] ILxUnknownID attr, [[maybe_unused]] void **ppvData)
#define LXxD_ValueTexture1_Customize LxResult vtx_Customize([[maybe_unused]] ILxUnknownID custom, [[maybe_unused]] void **ppvData) override
#define LXxO_ValueTexture1_Customize LXxD_ValueTexture1_Customize
#define LXxC_ValueTexture1_Customize(c) LxResult c::vtx_Customize([[maybe_unused]] ILxUnknownID custom, [[maybe_unused]] void **ppvData)
#define LXxD_ValueTexture1_Evaluate void vtx_Evaluate([[maybe_unused]] ILxUnknownID vector, [[maybe_unused]] LXpTextureOutput *tOut, [[maybe_unused]] void *data) override
#define LXxO_ValueTexture1_Evaluate LXxD_ValueTexture1_Evaluate
#define LXxC_ValueTexture1_Evaluate(c) void c::vtx_Evaluate([[maybe_unused]] ILxUnknownID vector, [[maybe_unused]] LXpTextureOutput *tOut, [[maybe_unused]] void *data)
#define LXxD_ValueTexture1_Cleanup void vtx_Cleanup([[maybe_unused]] void *data) override
#define LXxO_ValueTexture1_Cleanup LXxD_ValueTexture1_Cleanup
#define LXxC_ValueTexture1_Cleanup(c) void c::vtx_Cleanup([[maybe_unused]] void *data)

template <class T>
class CLxIfc_ValueTexture1: public CLxInterface
{
public:
    CLxIfc_ValueTexture1()
    {
        vt.SetupChannels = SetupChannels;
        vt.LinkChannels = LinkChannels;
        vt.ReadChannels = ReadChannels;
        vt.Customize = Customize;
        vt.Evaluate = Evaluate;
        vt.Cleanup = Cleanup;
        vTable = &vt.iunk;
        iid = &lx::guid_ValueTexture1;
    }

    static auto SetupChannels(LXtObjectID wcom,LXtObjectID addChan) -> LxResult
    {
        LXCWxINST (CLxImpl_ValueTexture1, loc);
        try
        {
           return loc->vtx_SetupChannels((ILxUnknownID) addChan);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto LinkChannels(LXtObjectID wcom,LXtObjectID eval,LXtObjectID item) -> LxResult
    {
        LXCWxINST (CLxImpl_ValueTexture1, loc);
        try
        {
           return loc->vtx_LinkChannels((ILxUnknownID) eval,(ILxUnknownID) item);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ReadChannels(LXtObjectID wcom,LXtObjectID attr,void **ppvData) -> LxResult
    {
        LXCWxINST (CLxImpl_ValueTexture1, loc);
        try
        {
           return loc->vtx_ReadChannels((ILxUnknownID) attr, ppvData);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Customize(LXtObjectID wcom,LXtObjectID custom,void **ppvData) -> LxResult
    {
        LXCWxINST (CLxImpl_ValueTexture1, loc);
        try
        {
           return loc->vtx_Customize((ILxUnknownID) custom, ppvData);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Evaluate(LXtObjectID wcom,LXtObjectID vector,LXpTextureOutput *tOut,void *data) -> void
    {
        LXCWxINST (CLxImpl_ValueTexture1, loc);
        loc->vtx_Evaluate((ILxUnknownID) vector, tOut, data);
    }

    static auto Cleanup(LXtObjectID wcom,void *data) -> void
    {
        LXCWxINST (CLxImpl_ValueTexture1, loc);
        loc->vtx_Cleanup( data);
    }

private:
    ILxValueTexture1 vt;
};


class CLxImpl_ValueTexture
{
public:
    virtual ~CLxImpl_ValueTexture() = default;

    virtual auto vtx_SetupChannels([[maybe_unused]] ILxUnknownID addChan) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto vtx_LinkChannels([[maybe_unused]] ILxUnknownID eval, [[maybe_unused]] ILxUnknownID item) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto vtx_LinkSampleChannels([[maybe_unused]] ILxUnknownID nodalEtor, [[maybe_unused]] ILxUnknownID item, [[maybe_unused]] int *idx) -> LxResult
    {
        return LXe_OK;
    }

    virtual auto vtx_ReadChannels([[maybe_unused]] ILxUnknownID attr, [[maybe_unused]] void **ppvData) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto vtx_Customize([[maybe_unused]] ILxUnknownID custom, [[maybe_unused]] void **ppvData) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto vtx_Setup([[maybe_unused]] void *data) -> LxResult
    {
        return LXe_OK;
    }

    virtual void vtx_Evaluate([[maybe_unused]] ILxUnknownID etor, [[maybe_unused]] int *idx, [[maybe_unused]] ILxUnknownID vector, [[maybe_unused]] LXpTextureOutput *tOut, [[maybe_unused]] void *data)
    {
    }

    virtual void vtx_Cleanup([[maybe_unused]] void *data)
    {
    }

    virtual auto vtx_IsSampleDriven([[maybe_unused]] int *idx) -> int
    {
        return LXe_FALSE;
    }
};

#define LXxD_ValueTexture_SetupChannels LxResult vtx_SetupChannels([[maybe_unused]] ILxUnknownID addChan) override
#define LXxO_ValueTexture_SetupChannels LXxD_ValueTexture_SetupChannels
#define LXxC_ValueTexture_SetupChannels(c) LxResult c::vtx_SetupChannels([[maybe_unused]] ILxUnknownID addChan)
#define LXxD_ValueTexture_LinkChannels LxResult vtx_LinkChannels([[maybe_unused]] ILxUnknownID eval, [[maybe_unused]] ILxUnknownID item) override
#define LXxO_ValueTexture_LinkChannels LXxD_ValueTexture_LinkChannels
#define LXxC_ValueTexture_LinkChannels(c) LxResult c::vtx_LinkChannels([[maybe_unused]] ILxUnknownID eval, [[maybe_unused]] ILxUnknownID item)
#define LXxD_ValueTexture_LinkSampleChannels LxResult vtx_LinkSampleChannels([[maybe_unused]] ILxUnknownID nodalEtor, [[maybe_unused]] ILxUnknownID item, [[maybe_unused]] int *idx) override
#define LXxO_ValueTexture_LinkSampleChannels LXxD_ValueTexture_LinkSampleChannels
#define LXxC_ValueTexture_LinkSampleChannels(c) LxResult c::vtx_LinkSampleChannels([[maybe_unused]] ILxUnknownID nodalEtor, [[maybe_unused]] ILxUnknownID item, [[maybe_unused]] int *idx)
#define LXxD_ValueTexture_ReadChannels LxResult vtx_ReadChannels([[maybe_unused]] ILxUnknownID attr, [[maybe_unused]] void **ppvData) override
#define LXxO_ValueTexture_ReadChannels LXxD_ValueTexture_ReadChannels
#define LXxC_ValueTexture_ReadChannels(c) LxResult c::vtx_ReadChannels([[maybe_unused]] ILxUnknownID attr, [[maybe_unused]] void **ppvData)
#define LXxD_ValueTexture_Customize LxResult vtx_Customize([[maybe_unused]] ILxUnknownID custom, [[maybe_unused]] void **ppvData) override
#define LXxO_ValueTexture_Customize LXxD_ValueTexture_Customize
#define LXxC_ValueTexture_Customize(c) LxResult c::vtx_Customize([[maybe_unused]] ILxUnknownID custom, [[maybe_unused]] void **ppvData)
#define LXxD_ValueTexture_Setup LxResult vtx_Setup([[maybe_unused]] void *data) override
#define LXxO_ValueTexture_Setup LXxD_ValueTexture_Setup
#define LXxC_ValueTexture_Setup(c) LxResult c::vtx_Setup([[maybe_unused]] void *data)
#define LXxD_ValueTexture_Evaluate void vtx_Evaluate([[maybe_unused]] ILxUnknownID etor, [[maybe_unused]] int *idx, [[maybe_unused]] ILxUnknownID vector, [[maybe_unused]] LXpTextureOutput *tOut, [[maybe_unused]] void *data) override
#define LXxO_ValueTexture_Evaluate LXxD_ValueTexture_Evaluate
#define LXxC_ValueTexture_Evaluate(c) void c::vtx_Evaluate([[maybe_unused]] ILxUnknownID etor, [[maybe_unused]] int *idx, [[maybe_unused]] ILxUnknownID vector, [[maybe_unused]] LXpTextureOutput *tOut, [[maybe_unused]] void *data)
#define LXxD_ValueTexture_Cleanup void vtx_Cleanup([[maybe_unused]] void *data) override
#define LXxO_ValueTexture_Cleanup LXxD_ValueTexture_Cleanup
#define LXxC_ValueTexture_Cleanup(c) void c::vtx_Cleanup([[maybe_unused]] void *data)
#define LXxD_ValueTexture_IsSampleDriven int vtx_IsSampleDriven([[maybe_unused]] int *idx) override
#define LXxO_ValueTexture_IsSampleDriven LXxD_ValueTexture_IsSampleDriven
#define LXxC_ValueTexture_IsSampleDriven(c) int c::vtx_IsSampleDriven([[maybe_unused]] int *idx)

template <class T>
class CLxIfc_ValueTexture: public CLxInterface
{
public:
    CLxIfc_ValueTexture()
    {
        vt.SetupChannels = SetupChannels;
        vt.LinkChannels = LinkChannels;
        vt.LinkSampleChannels = LinkSampleChannels;
        vt.ReadChannels = ReadChannels;
        vt.Customize = Customize;
        vt.Setup = Setup;
        vt.Evaluate = Evaluate;
        vt.Cleanup = Cleanup;
        vt.IsSampleDriven = IsSampleDriven;
        vTable = &vt.iunk;
        iid = &lx::guid_ValueTexture;
    }

    static auto SetupChannels(LXtObjectID wcom,LXtObjectID addChan) -> LxResult
    {
        LXCWxINST (CLxImpl_ValueTexture, loc);
        try
        {
           return loc->vtx_SetupChannels((ILxUnknownID) addChan);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto LinkChannels(LXtObjectID wcom,LXtObjectID eval,LXtObjectID item) -> LxResult
    {
        LXCWxINST (CLxImpl_ValueTexture, loc);
        try
        {
           return loc->vtx_LinkChannels((ILxUnknownID) eval,(ILxUnknownID) item);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto LinkSampleChannels(LXtObjectID wcom,LXtObjectID nodalEtor,LXtObjectID item,int *idx) -> LxResult
    {
        LXCWxINST (CLxImpl_ValueTexture, loc);
        try
        {
           return loc->vtx_LinkSampleChannels((ILxUnknownID) nodalEtor,(ILxUnknownID) item, idx);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ReadChannels(LXtObjectID wcom,LXtObjectID attr,void **ppvData) -> LxResult
    {
        LXCWxINST (CLxImpl_ValueTexture, loc);
        try
        {
           return loc->vtx_ReadChannels((ILxUnknownID) attr, ppvData);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Customize(LXtObjectID wcom,LXtObjectID custom,void **ppvData) -> LxResult
    {
        LXCWxINST (CLxImpl_ValueTexture, loc);
        try
        {
           return loc->vtx_Customize((ILxUnknownID) custom, ppvData);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Setup(LXtObjectID wcom,void *data) -> LxResult
    {
        LXCWxINST (CLxImpl_ValueTexture, loc);
        try
        {
           return loc->vtx_Setup( data);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Evaluate(LXtObjectID wcom,LXtObjectID etor,int *idx,LXtObjectID vector,LXpTextureOutput *tOut,void *data) -> void
    {
        LXCWxINST (CLxImpl_ValueTexture, loc);
        loc->vtx_Evaluate((ILxUnknownID) etor, idx,(ILxUnknownID) vector, tOut, data);
    }

    static auto Cleanup(LXtObjectID wcom,void *data) -> void
    {
        LXCWxINST (CLxImpl_ValueTexture, loc);
        loc->vtx_Cleanup( data);
    }

    static auto IsSampleDriven(LXtObjectID wcom,int *idx) -> int
    {
        LXCWxINST (CLxImpl_ValueTexture, loc);
        return loc->vtx_IsSampleDriven( idx);
    }

private:
    ILxValueTexture vt;
};

class CLxLoc_ValueTexture : public CLxLocalize<ILxValueTextureID>
{
public:
    CLxLoc_ValueTexture()
    {
        _init();
    }

    CLxLoc_ValueTexture(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_ValueTexture(CLxLoc_ValueTexture const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_ValueTexture;
    }

    auto SetupChannels(ILxUnknownID addChan) -> LxResult
    {
        return m_loc[0]->SetupChannels(m_loc,(ILxUnknownID) addChan);
    }

    auto LinkChannels(ILxUnknownID eval, ILxUnknownID item) -> LxResult
    {
        return m_loc[0]->LinkChannels(m_loc,(ILxUnknownID) eval,(ILxUnknownID) item);
    }

    auto LinkSampleChannels(ILxUnknownID nodalEtor, ILxUnknownID item, int *idx) -> LxResult
    {
        return m_loc[0]->LinkSampleChannels(m_loc,(ILxUnknownID) nodalEtor,(ILxUnknownID) item, idx);
    }

    auto ReadChannels(ILxUnknownID attr, void **ppvData) -> LxResult
    {
        return m_loc[0]->ReadChannels(m_loc,(ILxUnknownID) attr, ppvData);
    }

    auto Customize(ILxUnknownID custom, void **ppvData) -> LxResult
    {
        return m_loc[0]->Customize(m_loc,(ILxUnknownID) custom, ppvData);
    }

    auto Setup(void *data) -> LxResult
    {
        return m_loc[0]->Setup(m_loc, data);
    }

    auto Evaluate(ILxUnknownID etor, int *idx, ILxUnknownID vector, LXpTextureOutput *tOut, void *data) -> void
    {
        m_loc[0]->Evaluate(m_loc,(ILxUnknownID) etor, idx,(ILxUnknownID) vector, tOut, data);
    }

    auto Cleanup(void *data) -> void
    {
        m_loc[0]->Cleanup(m_loc, data);
    }

    auto IsSampleDriven(int *idx) -> int
    {
        return m_loc[0]->IsSampleDriven(m_loc, idx);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_ValueTextureCustom : public CLxLocalize<ILxValueTextureCustomID>
{
public:
    CLxLoc_ValueTextureCustom()
    {
        _init();
    }

    CLxLoc_ValueTextureCustom(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_ValueTextureCustom(CLxLoc_ValueTextureCustom const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_ValueTextureCustom;
    }

    auto AddFeature(LXtID4 type, const char *name) -> LxResult
    {
        return m_loc[0]->AddFeature(m_loc, type, name);
    }

    auto AddPacket(const char *name) -> LxResult
    {
        return m_loc[0]->AddPacket(m_loc, name);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_Texture : public CLxLocalize<ILxTextureID>
{
public:
    CLxLoc_Texture()
    {
        _init();
    }

    CLxLoc_Texture(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_Texture(CLxLoc_Texture const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_Texture;
    }

    auto Locator(void **ppvObj) -> LxResult
    {
        return m_loc[0]->Locator(m_loc, ppvObj);
    }

    auto Locator(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Locator(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto SetLocator(ILxUnknownID tloc) -> LxResult
    {
        return m_loc[0]->SetLocator(m_loc,(ILxUnknownID) tloc);
    }

    auto Image(void **ppvObj) -> LxResult
    {
        return m_loc[0]->Image(m_loc, ppvObj);
    }

    auto Image(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Image(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto SetImage(ILxUnknownID img) -> LxResult
    {
        return m_loc[0]->SetImage(m_loc,(ILxUnknownID) img);
    }

    auto ImageName(void) -> const char *
    {
        return m_loc[0]->ImageName(m_loc);
    }

    auto EvalImage(ILxUnknownID scene, void **ppvObj) -> LxResult
    {
        return m_loc[0]->EvalImage(m_loc,(ILxUnknownID) scene, ppvObj);
    }

    auto EvalImage(ILxUnknownID scene, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->EvalImage(m_loc,(ILxUnknownID) scene, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto LocatorProjectionMode(double time) -> int
    {
        return m_loc[0]->LocatorProjectionMode(m_loc, time);
    }

    auto LocatorProjectionAxis(double time) -> int
    {
        return m_loc[0]->LocatorProjectionAxis(m_loc, time);
    }

    auto Effect(void) -> const char *
    {
        return m_loc[0]->Effect(m_loc);
    }

    auto SetEffect(const char *effect) -> LxResult
    {
        return m_loc[0]->SetEffect(m_loc, effect);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_CompShader1
{
public:
    virtual ~CLxImpl_CompShader1() = default;

    virtual auto csh_SetupChannels([[maybe_unused]] ILxUnknownID addChan) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto csh_LinkChannels([[maybe_unused]] ILxUnknownID eval, [[maybe_unused]] ILxUnknownID item) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto csh_ReadChannels([[maybe_unused]] ILxUnknownID attr, [[maybe_unused]] void **ppvData) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto csh_Customize([[maybe_unused]] ILxUnknownID custom, [[maybe_unused]] void **ppvData) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual void csh_Evaluate([[maybe_unused]] ILxUnknownID vector, [[maybe_unused]] ILxUnknownID rayObj, [[maybe_unused]] LXpShadeComponents *sCmp, [[maybe_unused]] LXpShadeOutput *sOut, [[maybe_unused]] void *data)
    {
    }

    virtual auto csh_SetShadeFlags([[maybe_unused]] LXpShadeFlags *sFlg) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto csh_SetOpaque([[maybe_unused]] int *opaque) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto csh_CustomPacket([[maybe_unused]] const char **packet) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual void csh_Cleanup([[maybe_unused]] void *data)
    {
    }
};

#define LXxD_CompShader1_SetupChannels LxResult csh_SetupChannels([[maybe_unused]] ILxUnknownID addChan) override
#define LXxO_CompShader1_SetupChannels LXxD_CompShader1_SetupChannels
#define LXxC_CompShader1_SetupChannels(c) LxResult c::csh_SetupChannels([[maybe_unused]] ILxUnknownID addChan)
#define LXxD_CompShader1_LinkChannels LxResult csh_LinkChannels([[maybe_unused]] ILxUnknownID eval, [[maybe_unused]] ILxUnknownID item) override
#define LXxO_CompShader1_LinkChannels LXxD_CompShader1_LinkChannels
#define LXxC_CompShader1_LinkChannels(c) LxResult c::csh_LinkChannels([[maybe_unused]] ILxUnknownID eval, [[maybe_unused]] ILxUnknownID item)
#define LXxD_CompShader1_ReadChannels LxResult csh_ReadChannels([[maybe_unused]] ILxUnknownID attr, [[maybe_unused]] void **ppvData) override
#define LXxO_CompShader1_ReadChannels LXxD_CompShader1_ReadChannels
#define LXxC_CompShader1_ReadChannels(c) LxResult c::csh_ReadChannels([[maybe_unused]] ILxUnknownID attr, [[maybe_unused]] void **ppvData)
#define LXxD_CompShader1_Customize LxResult csh_Customize([[maybe_unused]] ILxUnknownID custom, [[maybe_unused]] void **ppvData) override
#define LXxO_CompShader1_Customize LXxD_CompShader1_Customize
#define LXxC_CompShader1_Customize(c) LxResult c::csh_Customize([[maybe_unused]] ILxUnknownID custom, [[maybe_unused]] void **ppvData)
#define LXxD_CompShader1_Evaluate void csh_Evaluate([[maybe_unused]] ILxUnknownID vector, [[maybe_unused]] ILxUnknownID rayObj, [[maybe_unused]] LXpShadeComponents *sCmp, [[maybe_unused]] LXpShadeOutput *sOut, [[maybe_unused]] void *data) override
#define LXxO_CompShader1_Evaluate LXxD_CompShader1_Evaluate
#define LXxC_CompShader1_Evaluate(c) void c::csh_Evaluate([[maybe_unused]] ILxUnknownID vector, [[maybe_unused]] ILxUnknownID rayObj, [[maybe_unused]] LXpShadeComponents *sCmp, [[maybe_unused]] LXpShadeOutput *sOut, [[maybe_unused]] void *data)
#define LXxD_CompShader1_SetShadeFlags LxResult csh_SetShadeFlags([[maybe_unused]] LXpShadeFlags *sFlg) override
#define LXxO_CompShader1_SetShadeFlags LXxD_CompShader1_SetShadeFlags
#define LXxC_CompShader1_SetShadeFlags(c) LxResult c::csh_SetShadeFlags([[maybe_unused]] LXpShadeFlags *sFlg)
#define LXxD_CompShader1_SetOpaque LxResult csh_SetOpaque([[maybe_unused]] int *opaque) override
#define LXxO_CompShader1_SetOpaque LXxD_CompShader1_SetOpaque
#define LXxC_CompShader1_SetOpaque(c) LxResult c::csh_SetOpaque([[maybe_unused]] int *opaque)
#define LXxD_CompShader1_CustomPacket LxResult csh_CustomPacket([[maybe_unused]] const char **packet) override
#define LXxO_CompShader1_CustomPacket LXxD_CompShader1_CustomPacket
#define LXxC_CompShader1_CustomPacket(c) LxResult c::csh_CustomPacket([[maybe_unused]] const char **packet)
#define LXxD_CompShader1_Cleanup void csh_Cleanup([[maybe_unused]] void *data) override
#define LXxO_CompShader1_Cleanup LXxD_CompShader1_Cleanup
#define LXxC_CompShader1_Cleanup(c) void c::csh_Cleanup([[maybe_unused]] void *data)

template <class T>
class CLxIfc_CompShader1: public CLxInterface
{
public:
    CLxIfc_CompShader1()
    {
        vt.SetupChannels = SetupChannels;
        vt.LinkChannels = LinkChannels;
        vt.ReadChannels = ReadChannels;
        vt.Customize = Customize;
        vt.Evaluate = Evaluate;
        vt.SetShadeFlags = SetShadeFlags;
        vt.SetOpaque = SetOpaque;
        vt.CustomPacket = CustomPacket;
        vt.Cleanup = Cleanup;
        vTable = &vt.iunk;
        iid = &lx::guid_CompShader1;
    }

    static auto SetupChannels(LXtObjectID wcom,LXtObjectID addChan) -> LxResult
    {
        LXCWxINST (CLxImpl_CompShader1, loc);
        try
        {
           return loc->csh_SetupChannels((ILxUnknownID) addChan);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto LinkChannels(LXtObjectID wcom,LXtObjectID eval,LXtObjectID item) -> LxResult
    {
        LXCWxINST (CLxImpl_CompShader1, loc);
        try
        {
           return loc->csh_LinkChannels((ILxUnknownID) eval,(ILxUnknownID) item);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ReadChannels(LXtObjectID wcom,LXtObjectID attr,void **ppvData) -> LxResult
    {
        LXCWxINST (CLxImpl_CompShader1, loc);
        try
        {
           return loc->csh_ReadChannels((ILxUnknownID) attr, ppvData);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Customize(LXtObjectID wcom,LXtObjectID custom,void **ppvData) -> LxResult
    {
        LXCWxINST (CLxImpl_CompShader1, loc);
        try
        {
           return loc->csh_Customize((ILxUnknownID) custom, ppvData);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Evaluate(LXtObjectID wcom,LXtObjectID vector,LXtObjectID rayObj,LXpShadeComponents *sCmp,LXpShadeOutput *sOut,void *data) -> void
    {
        LXCWxINST (CLxImpl_CompShader1, loc);
        loc->csh_Evaluate((ILxUnknownID) vector,(ILxUnknownID) rayObj, sCmp, sOut, data);
    }

    static auto SetShadeFlags(LXtObjectID wcom,LXpShadeFlags *sFlg) -> LxResult
    {
        LXCWxINST (CLxImpl_CompShader1, loc);
        try
        {
           return loc->csh_SetShadeFlags( sFlg);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SetOpaque(LXtObjectID wcom,int *opaque) -> LxResult
    {
        LXCWxINST (CLxImpl_CompShader1, loc);
        try
        {
           return loc->csh_SetOpaque( opaque);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto CustomPacket(LXtObjectID wcom,const char **packet) -> LxResult
    {
        LXCWxINST (CLxImpl_CompShader1, loc);
        try
        {
           return loc->csh_CustomPacket( packet);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Cleanup(LXtObjectID wcom,void *data) -> void
    {
        LXCWxINST (CLxImpl_CompShader1, loc);
        loc->csh_Cleanup( data);
    }

private:
    ILxCompShader1 vt;
};


class CLxImpl_CompShader
{
public:
    virtual ~CLxImpl_CompShader() = default;

    virtual auto csh_SetupChannels([[maybe_unused]] ILxUnknownID addChan) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto csh_LinkChannels([[maybe_unused]] ILxUnknownID eval, [[maybe_unused]] ILxUnknownID item) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto csh_ReadChannels([[maybe_unused]] ILxUnknownID attr, [[maybe_unused]] void **ppvData) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto csh_Customize([[maybe_unused]] ILxUnknownID custom, [[maybe_unused]] void **ppvData) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual void csh_Evaluate([[maybe_unused]] ILxUnknownID vector, [[maybe_unused]] ILxUnknownID rayObj, [[maybe_unused]] LXpShadeComponents *sCmp, [[maybe_unused]] LXpShadeOutput *sOut, [[maybe_unused]] void *data)
    {
    }

    virtual auto csh_SetShadeFlags([[maybe_unused]] LXpShadeFlags *sFlg) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto csh_SetOpaque([[maybe_unused]] int *opaque) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto csh_CustomPacket([[maybe_unused]] const char **packet) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual void csh_Cleanup([[maybe_unused]] void *data)
    {
    }

    virtual int csh_Flags(void) = 0;
};

#define LXxD_CompShader_SetupChannels LxResult csh_SetupChannels([[maybe_unused]] ILxUnknownID addChan) override
#define LXxO_CompShader_SetupChannels LXxD_CompShader_SetupChannels
#define LXxC_CompShader_SetupChannels(c) LxResult c::csh_SetupChannels([[maybe_unused]] ILxUnknownID addChan)
#define LXxD_CompShader_LinkChannels LxResult csh_LinkChannels([[maybe_unused]] ILxUnknownID eval, [[maybe_unused]] ILxUnknownID item) override
#define LXxO_CompShader_LinkChannels LXxD_CompShader_LinkChannels
#define LXxC_CompShader_LinkChannels(c) LxResult c::csh_LinkChannels([[maybe_unused]] ILxUnknownID eval, [[maybe_unused]] ILxUnknownID item)
#define LXxD_CompShader_ReadChannels LxResult csh_ReadChannels([[maybe_unused]] ILxUnknownID attr, [[maybe_unused]] void **ppvData) override
#define LXxO_CompShader_ReadChannels LXxD_CompShader_ReadChannels
#define LXxC_CompShader_ReadChannels(c) LxResult c::csh_ReadChannels([[maybe_unused]] ILxUnknownID attr, [[maybe_unused]] void **ppvData)
#define LXxD_CompShader_Customize LxResult csh_Customize([[maybe_unused]] ILxUnknownID custom, [[maybe_unused]] void **ppvData) override
#define LXxO_CompShader_Customize LXxD_CompShader_Customize
#define LXxC_CompShader_Customize(c) LxResult c::csh_Customize([[maybe_unused]] ILxUnknownID custom, [[maybe_unused]] void **ppvData)
#define LXxD_CompShader_Evaluate void csh_Evaluate([[maybe_unused]] ILxUnknownID vector, [[maybe_unused]] ILxUnknownID rayObj, [[maybe_unused]] LXpShadeComponents *sCmp, [[maybe_unused]] LXpShadeOutput *sOut, [[maybe_unused]] void *data) override
#define LXxO_CompShader_Evaluate LXxD_CompShader_Evaluate
#define LXxC_CompShader_Evaluate(c) void c::csh_Evaluate([[maybe_unused]] ILxUnknownID vector, [[maybe_unused]] ILxUnknownID rayObj, [[maybe_unused]] LXpShadeComponents *sCmp, [[maybe_unused]] LXpShadeOutput *sOut, [[maybe_unused]] void *data)
#define LXxD_CompShader_SetShadeFlags LxResult csh_SetShadeFlags([[maybe_unused]] LXpShadeFlags *sFlg) override
#define LXxO_CompShader_SetShadeFlags LXxD_CompShader_SetShadeFlags
#define LXxC_CompShader_SetShadeFlags(c) LxResult c::csh_SetShadeFlags([[maybe_unused]] LXpShadeFlags *sFlg)
#define LXxD_CompShader_SetOpaque LxResult csh_SetOpaque([[maybe_unused]] int *opaque) override
#define LXxO_CompShader_SetOpaque LXxD_CompShader_SetOpaque
#define LXxC_CompShader_SetOpaque(c) LxResult c::csh_SetOpaque([[maybe_unused]] int *opaque)
#define LXxD_CompShader_CustomPacket LxResult csh_CustomPacket([[maybe_unused]] const char **packet) override
#define LXxO_CompShader_CustomPacket LXxD_CompShader_CustomPacket
#define LXxC_CompShader_CustomPacket(c) LxResult c::csh_CustomPacket([[maybe_unused]] const char **packet)
#define LXxD_CompShader_Cleanup void csh_Cleanup([[maybe_unused]] void *data) override
#define LXxO_CompShader_Cleanup LXxD_CompShader_Cleanup
#define LXxC_CompShader_Cleanup(c) void c::csh_Cleanup([[maybe_unused]] void *data)
#define LXxD_CompShader_Flags int csh_Flags() override
#define LXxO_CompShader_Flags LXxD_CompShader_Flags
#define LXxC_CompShader_Flags(c) int c::csh_Flags()

template <class T>
class CLxIfc_CompShader: public CLxInterface
{
public:
    CLxIfc_CompShader()
    {
        vt.SetupChannels = SetupChannels;
        vt.LinkChannels = LinkChannels;
        vt.ReadChannels = ReadChannels;
        vt.Customize = Customize;
        vt.Evaluate = Evaluate;
        vt.SetShadeFlags = SetShadeFlags;
        vt.SetOpaque = SetOpaque;
        vt.CustomPacket = CustomPacket;
        vt.Cleanup = Cleanup;
        vt.Flags = Flags;
        vTable = &vt.iunk;
        iid = &lx::guid_CompShader;
    }

    static auto SetupChannels(LXtObjectID wcom,LXtObjectID addChan) -> LxResult
    {
        LXCWxINST (CLxImpl_CompShader, loc);
        try
        {
           return loc->csh_SetupChannels((ILxUnknownID) addChan);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto LinkChannels(LXtObjectID wcom,LXtObjectID eval,LXtObjectID item) -> LxResult
    {
        LXCWxINST (CLxImpl_CompShader, loc);
        try
        {
           return loc->csh_LinkChannels((ILxUnknownID) eval,(ILxUnknownID) item);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ReadChannels(LXtObjectID wcom,LXtObjectID attr,void **ppvData) -> LxResult
    {
        LXCWxINST (CLxImpl_CompShader, loc);
        try
        {
           return loc->csh_ReadChannels((ILxUnknownID) attr, ppvData);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Customize(LXtObjectID wcom,LXtObjectID custom,void **ppvData) -> LxResult
    {
        LXCWxINST (CLxImpl_CompShader, loc);
        try
        {
           return loc->csh_Customize((ILxUnknownID) custom, ppvData);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Evaluate(LXtObjectID wcom,LXtObjectID vector,LXtObjectID rayObj,LXpShadeComponents *sCmp,LXpShadeOutput *sOut,void *data) -> void
    {
        LXCWxINST (CLxImpl_CompShader, loc);
        loc->csh_Evaluate((ILxUnknownID) vector,(ILxUnknownID) rayObj, sCmp, sOut, data);
    }

    static auto SetShadeFlags(LXtObjectID wcom,LXpShadeFlags *sFlg) -> LxResult
    {
        LXCWxINST (CLxImpl_CompShader, loc);
        try
        {
           return loc->csh_SetShadeFlags( sFlg);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SetOpaque(LXtObjectID wcom,int *opaque) -> LxResult
    {
        LXCWxINST (CLxImpl_CompShader, loc);
        try
        {
           return loc->csh_SetOpaque( opaque);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto CustomPacket(LXtObjectID wcom,const char **packet) -> LxResult
    {
        LXCWxINST (CLxImpl_CompShader, loc);
        try
        {
           return loc->csh_CustomPacket( packet);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Cleanup(LXtObjectID wcom,void *data) -> void
    {
        LXCWxINST (CLxImpl_CompShader, loc);
        loc->csh_Cleanup( data);
    }

    static auto Flags(LXtObjectID wcom) -> int
    {
        LXCWxINST (CLxImpl_CompShader, loc);
        return loc->csh_Flags();
    }

private:
    ILxCompShader vt;
};

class CLxLoc_CompShader : public CLxLocalize<ILxCompShaderID>
{
public:
    CLxLoc_CompShader()
    {
        _init();
    }

    CLxLoc_CompShader(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_CompShader(CLxLoc_CompShader const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_CompShader;
    }

    auto SetupChannels(ILxUnknownID addChan) -> LxResult
    {
        return m_loc[0]->SetupChannels(m_loc,(ILxUnknownID) addChan);
    }

    auto LinkChannels(ILxUnknownID eval, ILxUnknownID item) -> LxResult
    {
        return m_loc[0]->LinkChannels(m_loc,(ILxUnknownID) eval,(ILxUnknownID) item);
    }

    auto ReadChannels(ILxUnknownID attr, void **ppvData) -> LxResult
    {
        return m_loc[0]->ReadChannels(m_loc,(ILxUnknownID) attr, ppvData);
    }

    auto Customize(ILxUnknownID custom, void **ppvData) -> LxResult
    {
        return m_loc[0]->Customize(m_loc,(ILxUnknownID) custom, ppvData);
    }

    auto Evaluate(ILxUnknownID vector, ILxUnknownID rayObj, LXpShadeComponents *sCmp, LXpShadeOutput *sOut, void *data) -> void
    {
        m_loc[0]->Evaluate(m_loc,(ILxUnknownID) vector,(ILxUnknownID) rayObj, sCmp, sOut, data);
    }

    auto SetShadeFlags(LXpShadeFlags *sFlg) -> LxResult
    {
        return m_loc[0]->SetShadeFlags(m_loc, sFlg);
    }

    auto SetOpaque(int *opaque) -> LxResult
    {
        return m_loc[0]->SetOpaque(m_loc, opaque);
    }

    auto CustomPacket(const char **packet) -> LxResult
    {
        return m_loc[0]->CustomPacket(m_loc, packet);
    }

    auto Cleanup(void *data) -> void
    {
        m_loc[0]->Cleanup(m_loc, data);
    }

    auto Flags(void) -> int
    {
        return m_loc[0]->Flags(m_loc);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_CustomMaterial1
{
public:
    virtual ~CLxImpl_CustomMaterial1() = default;

    virtual auto cmt_SetupChannels([[maybe_unused]] ILxUnknownID addChan) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmt_LinkChannels([[maybe_unused]] ILxUnknownID eval, [[maybe_unused]] ILxUnknownID item) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmt_ReadChannels([[maybe_unused]] ILxUnknownID attr, [[maybe_unused]] void **ppvData) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmt_Customize([[maybe_unused]] ILxUnknownID custom, [[maybe_unused]] void **ppvData) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual void cmt_MaterialEvaluate([[maybe_unused]] ILxUnknownID vector, [[maybe_unused]] void *data)
    {
    }

    virtual void cmt_ShaderEvaluate([[maybe_unused]] ILxUnknownID vector, [[maybe_unused]] ILxUnknownID rayObj, [[maybe_unused]] LXpShadeComponents *sCmp, [[maybe_unused]] LXpShadeOutput *sOut, [[maybe_unused]] void *data)
    {
    }

    virtual auto cmt_SetShadeFlags([[maybe_unused]] LXpShadeFlags *sFlg) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmt_SetBump([[maybe_unused]] float *bumpAmplitude, [[maybe_unused]] int *clearBump) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmt_SetDisplacement([[maybe_unused]] float *dispDist) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmt_SetOpaque([[maybe_unused]] int *opaque) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmt_SetSmoothing([[maybe_unused]] double *smooth, [[maybe_unused]] double *angle) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmt_CustomPacket([[maybe_unused]] const char **packet) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual void cmt_Cleanup([[maybe_unused]] void *data)
    {
    }

    virtual auto cmt_UpdatePreview([[maybe_unused]] int chanIdx, [[maybe_unused]] int *flags) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_CustomMaterial1_SetupChannels LxResult cmt_SetupChannels([[maybe_unused]] ILxUnknownID addChan) override
#define LXxO_CustomMaterial1_SetupChannels LXxD_CustomMaterial1_SetupChannels
#define LXxC_CustomMaterial1_SetupChannels(c) LxResult c::cmt_SetupChannels([[maybe_unused]] ILxUnknownID addChan)
#define LXxD_CustomMaterial1_LinkChannels LxResult cmt_LinkChannels([[maybe_unused]] ILxUnknownID eval, [[maybe_unused]] ILxUnknownID item) override
#define LXxO_CustomMaterial1_LinkChannels LXxD_CustomMaterial1_LinkChannels
#define LXxC_CustomMaterial1_LinkChannels(c) LxResult c::cmt_LinkChannels([[maybe_unused]] ILxUnknownID eval, [[maybe_unused]] ILxUnknownID item)
#define LXxD_CustomMaterial1_ReadChannels LxResult cmt_ReadChannels([[maybe_unused]] ILxUnknownID attr, [[maybe_unused]] void **ppvData) override
#define LXxO_CustomMaterial1_ReadChannels LXxD_CustomMaterial1_ReadChannels
#define LXxC_CustomMaterial1_ReadChannels(c) LxResult c::cmt_ReadChannels([[maybe_unused]] ILxUnknownID attr, [[maybe_unused]] void **ppvData)
#define LXxD_CustomMaterial1_Customize LxResult cmt_Customize([[maybe_unused]] ILxUnknownID custom, [[maybe_unused]] void **ppvData) override
#define LXxO_CustomMaterial1_Customize LXxD_CustomMaterial1_Customize
#define LXxC_CustomMaterial1_Customize(c) LxResult c::cmt_Customize([[maybe_unused]] ILxUnknownID custom, [[maybe_unused]] void **ppvData)
#define LXxD_CustomMaterial1_MaterialEvaluate void cmt_MaterialEvaluate([[maybe_unused]] ILxUnknownID vector, [[maybe_unused]] void *data) override
#define LXxO_CustomMaterial1_MaterialEvaluate LXxD_CustomMaterial1_MaterialEvaluate
#define LXxC_CustomMaterial1_MaterialEvaluate(c) void c::cmt_MaterialEvaluate([[maybe_unused]] ILxUnknownID vector, [[maybe_unused]] void *data)
#define LXxD_CustomMaterial1_ShaderEvaluate void cmt_ShaderEvaluate([[maybe_unused]] ILxUnknownID vector, [[maybe_unused]] ILxUnknownID rayObj, [[maybe_unused]] LXpShadeComponents *sCmp, [[maybe_unused]] LXpShadeOutput *sOut, [[maybe_unused]] void *data) override
#define LXxO_CustomMaterial1_ShaderEvaluate LXxD_CustomMaterial1_ShaderEvaluate
#define LXxC_CustomMaterial1_ShaderEvaluate(c) void c::cmt_ShaderEvaluate([[maybe_unused]] ILxUnknownID vector, [[maybe_unused]] ILxUnknownID rayObj, [[maybe_unused]] LXpShadeComponents *sCmp, [[maybe_unused]] LXpShadeOutput *sOut, [[maybe_unused]] void *data)
#define LXxD_CustomMaterial1_SetShadeFlags LxResult cmt_SetShadeFlags([[maybe_unused]] LXpShadeFlags *sFlg) override
#define LXxO_CustomMaterial1_SetShadeFlags LXxD_CustomMaterial1_SetShadeFlags
#define LXxC_CustomMaterial1_SetShadeFlags(c) LxResult c::cmt_SetShadeFlags([[maybe_unused]] LXpShadeFlags *sFlg)
#define LXxD_CustomMaterial1_SetBump LxResult cmt_SetBump([[maybe_unused]] float *bumpAmplitude, [[maybe_unused]] int *clearBump) override
#define LXxO_CustomMaterial1_SetBump LXxD_CustomMaterial1_SetBump
#define LXxC_CustomMaterial1_SetBump(c) LxResult c::cmt_SetBump([[maybe_unused]] float *bumpAmplitude, [[maybe_unused]] int *clearBump)
#define LXxD_CustomMaterial1_SetDisplacement LxResult cmt_SetDisplacement([[maybe_unused]] float *dispDist) override
#define LXxO_CustomMaterial1_SetDisplacement LXxD_CustomMaterial1_SetDisplacement
#define LXxC_CustomMaterial1_SetDisplacement(c) LxResult c::cmt_SetDisplacement([[maybe_unused]] float *dispDist)
#define LXxD_CustomMaterial1_SetOpaque LxResult cmt_SetOpaque([[maybe_unused]] int *opaque) override
#define LXxO_CustomMaterial1_SetOpaque LXxD_CustomMaterial1_SetOpaque
#define LXxC_CustomMaterial1_SetOpaque(c) LxResult c::cmt_SetOpaque([[maybe_unused]] int *opaque)
#define LXxD_CustomMaterial1_SetSmoothing LxResult cmt_SetSmoothing([[maybe_unused]] double *smooth, [[maybe_unused]] double *angle) override
#define LXxO_CustomMaterial1_SetSmoothing LXxD_CustomMaterial1_SetSmoothing
#define LXxC_CustomMaterial1_SetSmoothing(c) LxResult c::cmt_SetSmoothing([[maybe_unused]] double *smooth, [[maybe_unused]] double *angle)
#define LXxD_CustomMaterial1_CustomPacket LxResult cmt_CustomPacket([[maybe_unused]] const char **packet) override
#define LXxO_CustomMaterial1_CustomPacket LXxD_CustomMaterial1_CustomPacket
#define LXxC_CustomMaterial1_CustomPacket(c) LxResult c::cmt_CustomPacket([[maybe_unused]] const char **packet)
#define LXxD_CustomMaterial1_Cleanup void cmt_Cleanup([[maybe_unused]] void *data) override
#define LXxO_CustomMaterial1_Cleanup LXxD_CustomMaterial1_Cleanup
#define LXxC_CustomMaterial1_Cleanup(c) void c::cmt_Cleanup([[maybe_unused]] void *data)
#define LXxD_CustomMaterial1_UpdatePreview LxResult cmt_UpdatePreview([[maybe_unused]] int chanIdx, [[maybe_unused]] int *flags) override
#define LXxO_CustomMaterial1_UpdatePreview LXxD_CustomMaterial1_UpdatePreview
#define LXxC_CustomMaterial1_UpdatePreview(c) LxResult c::cmt_UpdatePreview([[maybe_unused]] int chanIdx, [[maybe_unused]] int *flags)

template <class T>
class CLxIfc_CustomMaterial1: public CLxInterface
{
public:
    CLxIfc_CustomMaterial1()
    {
        vt.SetupChannels = SetupChannels;
        vt.LinkChannels = LinkChannels;
        vt.ReadChannels = ReadChannels;
        vt.Customize = Customize;
        vt.MaterialEvaluate = MaterialEvaluate;
        vt.ShaderEvaluate = ShaderEvaluate;
        vt.SetShadeFlags = SetShadeFlags;
        vt.SetBump = SetBump;
        vt.SetDisplacement = SetDisplacement;
        vt.SetOpaque = SetOpaque;
        vt.SetSmoothing = SetSmoothing;
        vt.CustomPacket = CustomPacket;
        vt.Cleanup = Cleanup;
        vt.UpdatePreview = UpdatePreview;
        vTable = &vt.iunk;
        iid = &lx::guid_CustomMaterial1;
    }

    static auto SetupChannels(LXtObjectID wcom,LXtObjectID addChan) -> LxResult
    {
        LXCWxINST (CLxImpl_CustomMaterial1, loc);
        try
        {
           return loc->cmt_SetupChannels((ILxUnknownID) addChan);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto LinkChannels(LXtObjectID wcom,LXtObjectID eval,LXtObjectID item) -> LxResult
    {
        LXCWxINST (CLxImpl_CustomMaterial1, loc);
        try
        {
           return loc->cmt_LinkChannels((ILxUnknownID) eval,(ILxUnknownID) item);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ReadChannels(LXtObjectID wcom,LXtObjectID attr,void **ppvData) -> LxResult
    {
        LXCWxINST (CLxImpl_CustomMaterial1, loc);
        try
        {
           return loc->cmt_ReadChannels((ILxUnknownID) attr, ppvData);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Customize(LXtObjectID wcom,LXtObjectID custom,void **ppvData) -> LxResult
    {
        LXCWxINST (CLxImpl_CustomMaterial1, loc);
        try
        {
           return loc->cmt_Customize((ILxUnknownID) custom, ppvData);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto MaterialEvaluate(LXtObjectID wcom,LXtObjectID vector,void *data) -> void
    {
        LXCWxINST (CLxImpl_CustomMaterial1, loc);
        loc->cmt_MaterialEvaluate((ILxUnknownID) vector, data);
    }

    static auto ShaderEvaluate(LXtObjectID wcom,LXtObjectID vector,LXtObjectID rayObj,LXpShadeComponents *sCmp,LXpShadeOutput *sOut,void *data) -> void
    {
        LXCWxINST (CLxImpl_CustomMaterial1, loc);
        loc->cmt_ShaderEvaluate((ILxUnknownID) vector,(ILxUnknownID) rayObj, sCmp, sOut, data);
    }

    static auto SetShadeFlags(LXtObjectID wcom,LXpShadeFlags *sFlg) -> LxResult
    {
        LXCWxINST (CLxImpl_CustomMaterial1, loc);
        try
        {
           return loc->cmt_SetShadeFlags( sFlg);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SetBump(LXtObjectID wcom,float *bumpAmplitude,int *clearBump) -> LxResult
    {
        LXCWxINST (CLxImpl_CustomMaterial1, loc);
        try
        {
           return loc->cmt_SetBump( bumpAmplitude, clearBump);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SetDisplacement(LXtObjectID wcom,float *dispDist) -> LxResult
    {
        LXCWxINST (CLxImpl_CustomMaterial1, loc);
        try
        {
           return loc->cmt_SetDisplacement( dispDist);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SetOpaque(LXtObjectID wcom,int *opaque) -> LxResult
    {
        LXCWxINST (CLxImpl_CustomMaterial1, loc);
        try
        {
           return loc->cmt_SetOpaque( opaque);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SetSmoothing(LXtObjectID wcom,double *smooth,double *angle) -> LxResult
    {
        LXCWxINST (CLxImpl_CustomMaterial1, loc);
        try
        {
           return loc->cmt_SetSmoothing( smooth, angle);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto CustomPacket(LXtObjectID wcom,const char **packet) -> LxResult
    {
        LXCWxINST (CLxImpl_CustomMaterial1, loc);
        try
        {
           return loc->cmt_CustomPacket( packet);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Cleanup(LXtObjectID wcom,void *data) -> void
    {
        LXCWxINST (CLxImpl_CustomMaterial1, loc);
        loc->cmt_Cleanup( data);
    }

    static auto UpdatePreview(LXtObjectID wcom,int chanIdx,int *flags) -> LxResult
    {
        LXCWxINST (CLxImpl_CustomMaterial1, loc);
        try
        {
           return loc->cmt_UpdatePreview( chanIdx, flags);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxCustomMaterial1 vt;
};



class CLxImpl_CustomMaterial3
{
public:
    virtual ~CLxImpl_CustomMaterial3() = default;

    virtual auto cmt_SetupChannels([[maybe_unused]] ILxUnknownID addChan) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmt_LinkChannels([[maybe_unused]] ILxUnknownID eval, [[maybe_unused]] ILxUnknownID item) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmt_LinkSampleChannels([[maybe_unused]] ILxUnknownID nodalEtor, [[maybe_unused]] ILxUnknownID item, [[maybe_unused]] int *idx) -> LxResult
    {
        return LXe_OK;
    }

    virtual auto cmt_IsSampleDriven([[maybe_unused]] int *idx) -> int
    {
        return LXe_FALSE;
    }

    virtual auto cmt_ReadChannels([[maybe_unused]] ILxUnknownID attr, [[maybe_unused]] void **ppvData) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmt_Customize([[maybe_unused]] ILxUnknownID custom, [[maybe_unused]] void **ppvData) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual void cmt_MaterialEvaluate([[maybe_unused]] ILxUnknownID etor, [[maybe_unused]] int *idx, [[maybe_unused]] ILxUnknownID vector, [[maybe_unused]] void *data)
    {
    }

    virtual void cmt_ShaderEvaluate([[maybe_unused]] ILxUnknownID vector, [[maybe_unused]] ILxUnknownID rayObj, [[maybe_unused]] LXpShadeComponents *sCmp, [[maybe_unused]] LXpShadeOutput *sOut, [[maybe_unused]] void *data)
    {
    }

    virtual auto cmt_SetShadeFlags([[maybe_unused]] LXpShadeFlags *sFlg) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmt_SetBump([[maybe_unused]] float *bumpAmplitude, [[maybe_unused]] int *clearBump) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmt_SetDisplacement([[maybe_unused]] float *dispDist) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmt_SetOpaque([[maybe_unused]] int *opaque) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmt_SetSmoothing([[maybe_unused]] double *smooth, [[maybe_unused]] double *angle) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmt_CustomPacket([[maybe_unused]] const char **packet) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual void cmt_Cleanup([[maybe_unused]] void *data)
    {
    }

    virtual auto cmt_UpdatePreview([[maybe_unused]] int chanIdx, [[maybe_unused]] int *flags) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual int cmt_Flags(void) = 0;
};

#define LXxD_CustomMaterial3_SetupChannels LxResult cmt_SetupChannels([[maybe_unused]] ILxUnknownID addChan) override
#define LXxO_CustomMaterial3_SetupChannels LXxD_CustomMaterial3_SetupChannels
#define LXxC_CustomMaterial3_SetupChannels(c) LxResult c::cmt_SetupChannels([[maybe_unused]] ILxUnknownID addChan)
#define LXxD_CustomMaterial3_LinkChannels LxResult cmt_LinkChannels([[maybe_unused]] ILxUnknownID eval, [[maybe_unused]] ILxUnknownID item) override
#define LXxO_CustomMaterial3_LinkChannels LXxD_CustomMaterial3_LinkChannels
#define LXxC_CustomMaterial3_LinkChannels(c) LxResult c::cmt_LinkChannels([[maybe_unused]] ILxUnknownID eval, [[maybe_unused]] ILxUnknownID item)
#define LXxD_CustomMaterial3_LinkSampleChannels LxResult cmt_LinkSampleChannels([[maybe_unused]] ILxUnknownID nodalEtor, [[maybe_unused]] ILxUnknownID item, [[maybe_unused]] int *idx) override
#define LXxO_CustomMaterial3_LinkSampleChannels LXxD_CustomMaterial3_LinkSampleChannels
#define LXxC_CustomMaterial3_LinkSampleChannels(c) LxResult c::cmt_LinkSampleChannels([[maybe_unused]] ILxUnknownID nodalEtor, [[maybe_unused]] ILxUnknownID item, [[maybe_unused]] int *idx)
#define LXxD_CustomMaterial3_IsSampleDriven int cmt_IsSampleDriven([[maybe_unused]] int *idx) override
#define LXxO_CustomMaterial3_IsSampleDriven LXxD_CustomMaterial3_IsSampleDriven
#define LXxC_CustomMaterial3_IsSampleDriven(c) int c::cmt_IsSampleDriven([[maybe_unused]] int *idx)
#define LXxD_CustomMaterial3_ReadChannels LxResult cmt_ReadChannels([[maybe_unused]] ILxUnknownID attr, [[maybe_unused]] void **ppvData) override
#define LXxO_CustomMaterial3_ReadChannels LXxD_CustomMaterial3_ReadChannels
#define LXxC_CustomMaterial3_ReadChannels(c) LxResult c::cmt_ReadChannels([[maybe_unused]] ILxUnknownID attr, [[maybe_unused]] void **ppvData)
#define LXxD_CustomMaterial3_Customize LxResult cmt_Customize([[maybe_unused]] ILxUnknownID custom, [[maybe_unused]] void **ppvData) override
#define LXxO_CustomMaterial3_Customize LXxD_CustomMaterial3_Customize
#define LXxC_CustomMaterial3_Customize(c) LxResult c::cmt_Customize([[maybe_unused]] ILxUnknownID custom, [[maybe_unused]] void **ppvData)
#define LXxD_CustomMaterial3_MaterialEvaluate void cmt_MaterialEvaluate([[maybe_unused]] ILxUnknownID etor, [[maybe_unused]] int *idx, [[maybe_unused]] ILxUnknownID vector, [[maybe_unused]] void *data) override
#define LXxO_CustomMaterial3_MaterialEvaluate LXxD_CustomMaterial3_MaterialEvaluate
#define LXxC_CustomMaterial3_MaterialEvaluate(c) void c::cmt_MaterialEvaluate([[maybe_unused]] ILxUnknownID etor, [[maybe_unused]] int *idx, [[maybe_unused]] ILxUnknownID vector, [[maybe_unused]] void *data)
#define LXxD_CustomMaterial3_ShaderEvaluate void cmt_ShaderEvaluate([[maybe_unused]] ILxUnknownID vector, [[maybe_unused]] ILxUnknownID rayObj, [[maybe_unused]] LXpShadeComponents *sCmp, [[maybe_unused]] LXpShadeOutput *sOut, [[maybe_unused]] void *data) override
#define LXxO_CustomMaterial3_ShaderEvaluate LXxD_CustomMaterial3_ShaderEvaluate
#define LXxC_CustomMaterial3_ShaderEvaluate(c) void c::cmt_ShaderEvaluate([[maybe_unused]] ILxUnknownID vector, [[maybe_unused]] ILxUnknownID rayObj, [[maybe_unused]] LXpShadeComponents *sCmp, [[maybe_unused]] LXpShadeOutput *sOut, [[maybe_unused]] void *data)
#define LXxD_CustomMaterial3_SetShadeFlags LxResult cmt_SetShadeFlags([[maybe_unused]] LXpShadeFlags *sFlg) override
#define LXxO_CustomMaterial3_SetShadeFlags LXxD_CustomMaterial3_SetShadeFlags
#define LXxC_CustomMaterial3_SetShadeFlags(c) LxResult c::cmt_SetShadeFlags([[maybe_unused]] LXpShadeFlags *sFlg)
#define LXxD_CustomMaterial3_SetBump LxResult cmt_SetBump([[maybe_unused]] float *bumpAmplitude, [[maybe_unused]] int *clearBump) override
#define LXxO_CustomMaterial3_SetBump LXxD_CustomMaterial3_SetBump
#define LXxC_CustomMaterial3_SetBump(c) LxResult c::cmt_SetBump([[maybe_unused]] float *bumpAmplitude, [[maybe_unused]] int *clearBump)
#define LXxD_CustomMaterial3_SetDisplacement LxResult cmt_SetDisplacement([[maybe_unused]] float *dispDist) override
#define LXxO_CustomMaterial3_SetDisplacement LXxD_CustomMaterial3_SetDisplacement
#define LXxC_CustomMaterial3_SetDisplacement(c) LxResult c::cmt_SetDisplacement([[maybe_unused]] float *dispDist)
#define LXxD_CustomMaterial3_SetOpaque LxResult cmt_SetOpaque([[maybe_unused]] int *opaque) override
#define LXxO_CustomMaterial3_SetOpaque LXxD_CustomMaterial3_SetOpaque
#define LXxC_CustomMaterial3_SetOpaque(c) LxResult c::cmt_SetOpaque([[maybe_unused]] int *opaque)
#define LXxD_CustomMaterial3_SetSmoothing LxResult cmt_SetSmoothing([[maybe_unused]] double *smooth, [[maybe_unused]] double *angle) override
#define LXxO_CustomMaterial3_SetSmoothing LXxD_CustomMaterial3_SetSmoothing
#define LXxC_CustomMaterial3_SetSmoothing(c) LxResult c::cmt_SetSmoothing([[maybe_unused]] double *smooth, [[maybe_unused]] double *angle)
#define LXxD_CustomMaterial3_CustomPacket LxResult cmt_CustomPacket([[maybe_unused]] const char **packet) override
#define LXxO_CustomMaterial3_CustomPacket LXxD_CustomMaterial3_CustomPacket
#define LXxC_CustomMaterial3_CustomPacket(c) LxResult c::cmt_CustomPacket([[maybe_unused]] const char **packet)
#define LXxD_CustomMaterial3_Cleanup void cmt_Cleanup([[maybe_unused]] void *data) override
#define LXxO_CustomMaterial3_Cleanup LXxD_CustomMaterial3_Cleanup
#define LXxC_CustomMaterial3_Cleanup(c) void c::cmt_Cleanup([[maybe_unused]] void *data)
#define LXxD_CustomMaterial3_UpdatePreview LxResult cmt_UpdatePreview([[maybe_unused]] int chanIdx, [[maybe_unused]] int *flags) override
#define LXxO_CustomMaterial3_UpdatePreview LXxD_CustomMaterial3_UpdatePreview
#define LXxC_CustomMaterial3_UpdatePreview(c) LxResult c::cmt_UpdatePreview([[maybe_unused]] int chanIdx, [[maybe_unused]] int *flags)
#define LXxD_CustomMaterial3_Flags int cmt_Flags() override
#define LXxO_CustomMaterial3_Flags LXxD_CustomMaterial3_Flags
#define LXxC_CustomMaterial3_Flags(c) int c::cmt_Flags()

template <class T>
class CLxIfc_CustomMaterial3: public CLxInterface
{
public:
    CLxIfc_CustomMaterial3()
    {
        vt.SetupChannels = SetupChannels;
        vt.LinkChannels = LinkChannels;
        vt.LinkSampleChannels = LinkSampleChannels;
        vt.IsSampleDriven = IsSampleDriven;
        vt.ReadChannels = ReadChannels;
        vt.Customize = Customize;
        vt.MaterialEvaluate = MaterialEvaluate;
        vt.ShaderEvaluate = ShaderEvaluate;
        vt.SetShadeFlags = SetShadeFlags;
        vt.SetBump = SetBump;
        vt.SetDisplacement = SetDisplacement;
        vt.SetOpaque = SetOpaque;
        vt.SetSmoothing = SetSmoothing;
        vt.CustomPacket = CustomPacket;
        vt.Cleanup = Cleanup;
        vt.UpdatePreview = UpdatePreview;
        vt.Flags = Flags;
        vTable = &vt.iunk;
        iid = &lx::guid_CustomMaterial3;
    }

    static auto SetupChannels(LXtObjectID wcom,LXtObjectID addChan) -> LxResult
    {
        LXCWxINST (CLxImpl_CustomMaterial3, loc);
        try
        {
           return loc->cmt_SetupChannels((ILxUnknownID) addChan);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto LinkChannels(LXtObjectID wcom,LXtObjectID eval,LXtObjectID item) -> LxResult
    {
        LXCWxINST (CLxImpl_CustomMaterial3, loc);
        try
        {
           return loc->cmt_LinkChannels((ILxUnknownID) eval,(ILxUnknownID) item);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto LinkSampleChannels(LXtObjectID wcom,LXtObjectID nodalEtor,LXtObjectID item,int *idx) -> LxResult
    {
        LXCWxINST (CLxImpl_CustomMaterial3, loc);
        try
        {
           return loc->cmt_LinkSampleChannels((ILxUnknownID) nodalEtor,(ILxUnknownID) item, idx);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto IsSampleDriven(LXtObjectID wcom,int *idx) -> int
    {
        LXCWxINST (CLxImpl_CustomMaterial3, loc);
        return loc->cmt_IsSampleDriven( idx);
    }

    static auto ReadChannels(LXtObjectID wcom,LXtObjectID attr,void **ppvData) -> LxResult
    {
        LXCWxINST (CLxImpl_CustomMaterial3, loc);
        try
        {
           return loc->cmt_ReadChannels((ILxUnknownID) attr, ppvData);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Customize(LXtObjectID wcom,LXtObjectID custom,void **ppvData) -> LxResult
    {
        LXCWxINST (CLxImpl_CustomMaterial3, loc);
        try
        {
           return loc->cmt_Customize((ILxUnknownID) custom, ppvData);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto MaterialEvaluate(LXtObjectID wcom,LXtObjectID etor,int *idx,LXtObjectID vector,void *data) -> void
    {
        LXCWxINST (CLxImpl_CustomMaterial3, loc);
        loc->cmt_MaterialEvaluate((ILxUnknownID) etor, idx,(ILxUnknownID) vector, data);
    }

    static auto ShaderEvaluate(LXtObjectID wcom,LXtObjectID vector,LXtObjectID rayObj,LXpShadeComponents *sCmp,LXpShadeOutput *sOut,void *data) -> void
    {
        LXCWxINST (CLxImpl_CustomMaterial3, loc);
        loc->cmt_ShaderEvaluate((ILxUnknownID) vector,(ILxUnknownID) rayObj, sCmp, sOut, data);
    }

    static auto SetShadeFlags(LXtObjectID wcom,LXpShadeFlags *sFlg) -> LxResult
    {
        LXCWxINST (CLxImpl_CustomMaterial3, loc);
        try
        {
           return loc->cmt_SetShadeFlags( sFlg);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SetBump(LXtObjectID wcom,float *bumpAmplitude,int *clearBump) -> LxResult
    {
        LXCWxINST (CLxImpl_CustomMaterial3, loc);
        try
        {
           return loc->cmt_SetBump( bumpAmplitude, clearBump);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SetDisplacement(LXtObjectID wcom,float *dispDist) -> LxResult
    {
        LXCWxINST (CLxImpl_CustomMaterial3, loc);
        try
        {
           return loc->cmt_SetDisplacement( dispDist);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SetOpaque(LXtObjectID wcom,int *opaque) -> LxResult
    {
        LXCWxINST (CLxImpl_CustomMaterial3, loc);
        try
        {
           return loc->cmt_SetOpaque( opaque);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SetSmoothing(LXtObjectID wcom,double *smooth,double *angle) -> LxResult
    {
        LXCWxINST (CLxImpl_CustomMaterial3, loc);
        try
        {
           return loc->cmt_SetSmoothing( smooth, angle);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto CustomPacket(LXtObjectID wcom,const char **packet) -> LxResult
    {
        LXCWxINST (CLxImpl_CustomMaterial3, loc);
        try
        {
           return loc->cmt_CustomPacket( packet);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Cleanup(LXtObjectID wcom,void *data) -> void
    {
        LXCWxINST (CLxImpl_CustomMaterial3, loc);
        loc->cmt_Cleanup( data);
    }

    static auto UpdatePreview(LXtObjectID wcom,int chanIdx,int *flags) -> LxResult
    {
        LXCWxINST (CLxImpl_CustomMaterial3, loc);
        try
        {
           return loc->cmt_UpdatePreview( chanIdx, flags);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Flags(LXtObjectID wcom) -> int
    {
        LXCWxINST (CLxImpl_CustomMaterial3, loc);
        return loc->cmt_Flags();
    }

private:
    ILxCustomMaterial3 vt;
};


class CLxImpl_CustomMaterial
{
public:
    virtual ~CLxImpl_CustomMaterial() = default;

    virtual auto cmt_SetupChannels([[maybe_unused]] ILxUnknownID addChan) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmt_LinkChannels([[maybe_unused]] ILxUnknownID eval, [[maybe_unused]] ILxUnknownID item) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmt_LinkSampleChannels([[maybe_unused]] ILxUnknownID nodalEtor, [[maybe_unused]] ILxUnknownID item, [[maybe_unused]] int *idx) -> LxResult
    {
        return LXe_OK;
    }

    virtual auto cmt_IsSampleDriven([[maybe_unused]] int *idx) -> int
    {
        return LXe_FALSE;
    }

    virtual auto cmt_ReadChannels([[maybe_unused]] ILxUnknownID attr, [[maybe_unused]] void **ppvData) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmt_Customize([[maybe_unused]] ILxUnknownID custom, [[maybe_unused]] void **ppvData) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual void cmt_MaterialEvaluate([[maybe_unused]] ILxUnknownID etor, [[maybe_unused]] int *idx, [[maybe_unused]] ILxUnknownID vector, [[maybe_unused]] void *data)
    {
    }

    virtual void cmt_ShaderEvaluate([[maybe_unused]] ILxUnknownID vector, [[maybe_unused]] ILxUnknownID rayObj, [[maybe_unused]] LXpShadeComponents *sCmp, [[maybe_unused]] LXpShadeOutput *sOut, [[maybe_unused]] void *data)
    {
    }

    virtual auto cmt_SetShadeFlags([[maybe_unused]] LXpShadeFlags *sFlg) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmt_SetBump([[maybe_unused]] float *bumpAmplitude, [[maybe_unused]] int *clearBump) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmt_SetDisplacement([[maybe_unused]] float *dispDist) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmt_SetOpaque([[maybe_unused]] int *opaque) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmt_SetSmoothing([[maybe_unused]] double *smooth, [[maybe_unused]] double *angle, [[maybe_unused]] int *weighting, [[maybe_unused]] int *normalMethod, [[maybe_unused]] int *creasing) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmt_CustomPacket([[maybe_unused]] const char **packet) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual void cmt_Cleanup([[maybe_unused]] void *data)
    {
    }

    virtual auto cmt_UpdatePreview([[maybe_unused]] int chanIdx, [[maybe_unused]] int *flags) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual int cmt_Flags(void) = 0;
};

#define LXxD_CustomMaterial_SetupChannels LxResult cmt_SetupChannels([[maybe_unused]] ILxUnknownID addChan) override
#define LXxO_CustomMaterial_SetupChannels LXxD_CustomMaterial_SetupChannels
#define LXxC_CustomMaterial_SetupChannels(c) LxResult c::cmt_SetupChannels([[maybe_unused]] ILxUnknownID addChan)
#define LXxD_CustomMaterial_LinkChannels LxResult cmt_LinkChannels([[maybe_unused]] ILxUnknownID eval, [[maybe_unused]] ILxUnknownID item) override
#define LXxO_CustomMaterial_LinkChannels LXxD_CustomMaterial_LinkChannels
#define LXxC_CustomMaterial_LinkChannels(c) LxResult c::cmt_LinkChannels([[maybe_unused]] ILxUnknownID eval, [[maybe_unused]] ILxUnknownID item)
#define LXxD_CustomMaterial_LinkSampleChannels LxResult cmt_LinkSampleChannels([[maybe_unused]] ILxUnknownID nodalEtor, [[maybe_unused]] ILxUnknownID item, [[maybe_unused]] int *idx) override
#define LXxO_CustomMaterial_LinkSampleChannels LXxD_CustomMaterial_LinkSampleChannels
#define LXxC_CustomMaterial_LinkSampleChannels(c) LxResult c::cmt_LinkSampleChannels([[maybe_unused]] ILxUnknownID nodalEtor, [[maybe_unused]] ILxUnknownID item, [[maybe_unused]] int *idx)
#define LXxD_CustomMaterial_IsSampleDriven int cmt_IsSampleDriven([[maybe_unused]] int *idx) override
#define LXxO_CustomMaterial_IsSampleDriven LXxD_CustomMaterial_IsSampleDriven
#define LXxC_CustomMaterial_IsSampleDriven(c) int c::cmt_IsSampleDriven([[maybe_unused]] int *idx)
#define LXxD_CustomMaterial_ReadChannels LxResult cmt_ReadChannels([[maybe_unused]] ILxUnknownID attr, [[maybe_unused]] void **ppvData) override
#define LXxO_CustomMaterial_ReadChannels LXxD_CustomMaterial_ReadChannels
#define LXxC_CustomMaterial_ReadChannels(c) LxResult c::cmt_ReadChannels([[maybe_unused]] ILxUnknownID attr, [[maybe_unused]] void **ppvData)
#define LXxD_CustomMaterial_Customize LxResult cmt_Customize([[maybe_unused]] ILxUnknownID custom, [[maybe_unused]] void **ppvData) override
#define LXxO_CustomMaterial_Customize LXxD_CustomMaterial_Customize
#define LXxC_CustomMaterial_Customize(c) LxResult c::cmt_Customize([[maybe_unused]] ILxUnknownID custom, [[maybe_unused]] void **ppvData)
#define LXxD_CustomMaterial_MaterialEvaluate void cmt_MaterialEvaluate([[maybe_unused]] ILxUnknownID etor, [[maybe_unused]] int *idx, [[maybe_unused]] ILxUnknownID vector, [[maybe_unused]] void *data) override
#define LXxO_CustomMaterial_MaterialEvaluate LXxD_CustomMaterial_MaterialEvaluate
#define LXxC_CustomMaterial_MaterialEvaluate(c) void c::cmt_MaterialEvaluate([[maybe_unused]] ILxUnknownID etor, [[maybe_unused]] int *idx, [[maybe_unused]] ILxUnknownID vector, [[maybe_unused]] void *data)
#define LXxD_CustomMaterial_ShaderEvaluate void cmt_ShaderEvaluate([[maybe_unused]] ILxUnknownID vector, [[maybe_unused]] ILxUnknownID rayObj, [[maybe_unused]] LXpShadeComponents *sCmp, [[maybe_unused]] LXpShadeOutput *sOut, [[maybe_unused]] void *data) override
#define LXxO_CustomMaterial_ShaderEvaluate LXxD_CustomMaterial_ShaderEvaluate
#define LXxC_CustomMaterial_ShaderEvaluate(c) void c::cmt_ShaderEvaluate([[maybe_unused]] ILxUnknownID vector, [[maybe_unused]] ILxUnknownID rayObj, [[maybe_unused]] LXpShadeComponents *sCmp, [[maybe_unused]] LXpShadeOutput *sOut, [[maybe_unused]] void *data)
#define LXxD_CustomMaterial_SetShadeFlags LxResult cmt_SetShadeFlags([[maybe_unused]] LXpShadeFlags *sFlg) override
#define LXxO_CustomMaterial_SetShadeFlags LXxD_CustomMaterial_SetShadeFlags
#define LXxC_CustomMaterial_SetShadeFlags(c) LxResult c::cmt_SetShadeFlags([[maybe_unused]] LXpShadeFlags *sFlg)
#define LXxD_CustomMaterial_SetBump LxResult cmt_SetBump([[maybe_unused]] float *bumpAmplitude, [[maybe_unused]] int *clearBump) override
#define LXxO_CustomMaterial_SetBump LXxD_CustomMaterial_SetBump
#define LXxC_CustomMaterial_SetBump(c) LxResult c::cmt_SetBump([[maybe_unused]] float *bumpAmplitude, [[maybe_unused]] int *clearBump)
#define LXxD_CustomMaterial_SetDisplacement LxResult cmt_SetDisplacement([[maybe_unused]] float *dispDist) override
#define LXxO_CustomMaterial_SetDisplacement LXxD_CustomMaterial_SetDisplacement
#define LXxC_CustomMaterial_SetDisplacement(c) LxResult c::cmt_SetDisplacement([[maybe_unused]] float *dispDist)
#define LXxD_CustomMaterial_SetOpaque LxResult cmt_SetOpaque([[maybe_unused]] int *opaque) override
#define LXxO_CustomMaterial_SetOpaque LXxD_CustomMaterial_SetOpaque
#define LXxC_CustomMaterial_SetOpaque(c) LxResult c::cmt_SetOpaque([[maybe_unused]] int *opaque)
#define LXxD_CustomMaterial_SetSmoothing LxResult cmt_SetSmoothing([[maybe_unused]] double *smooth, [[maybe_unused]] double *angle, [[maybe_unused]] int *weighting, [[maybe_unused]] int *normalMethod, [[maybe_unused]] int *creasing) override
#define LXxO_CustomMaterial_SetSmoothing LXxD_CustomMaterial_SetSmoothing
#define LXxC_CustomMaterial_SetSmoothing(c) LxResult c::cmt_SetSmoothing([[maybe_unused]] double *smooth, [[maybe_unused]] double *angle, [[maybe_unused]] int *weighting, [[maybe_unused]] int *normalMethod, [[maybe_unused]] int *creasing)
#define LXxD_CustomMaterial_CustomPacket LxResult cmt_CustomPacket([[maybe_unused]] const char **packet) override
#define LXxO_CustomMaterial_CustomPacket LXxD_CustomMaterial_CustomPacket
#define LXxC_CustomMaterial_CustomPacket(c) LxResult c::cmt_CustomPacket([[maybe_unused]] const char **packet)
#define LXxD_CustomMaterial_Cleanup void cmt_Cleanup([[maybe_unused]] void *data) override
#define LXxO_CustomMaterial_Cleanup LXxD_CustomMaterial_Cleanup
#define LXxC_CustomMaterial_Cleanup(c) void c::cmt_Cleanup([[maybe_unused]] void *data)
#define LXxD_CustomMaterial_UpdatePreview LxResult cmt_UpdatePreview([[maybe_unused]] int chanIdx, [[maybe_unused]] int *flags) override
#define LXxO_CustomMaterial_UpdatePreview LXxD_CustomMaterial_UpdatePreview
#define LXxC_CustomMaterial_UpdatePreview(c) LxResult c::cmt_UpdatePreview([[maybe_unused]] int chanIdx, [[maybe_unused]] int *flags)
#define LXxD_CustomMaterial_Flags int cmt_Flags() override
#define LXxO_CustomMaterial_Flags LXxD_CustomMaterial_Flags
#define LXxC_CustomMaterial_Flags(c) int c::cmt_Flags()

template <class T>
class CLxIfc_CustomMaterial: public CLxInterface
{
public:
    CLxIfc_CustomMaterial()
    {
        vt.SetupChannels = SetupChannels;
        vt.LinkChannels = LinkChannels;
        vt.LinkSampleChannels = LinkSampleChannels;
        vt.IsSampleDriven = IsSampleDriven;
        vt.ReadChannels = ReadChannels;
        vt.Customize = Customize;
        vt.MaterialEvaluate = MaterialEvaluate;
        vt.ShaderEvaluate = ShaderEvaluate;
        vt.SetShadeFlags = SetShadeFlags;
        vt.SetBump = SetBump;
        vt.SetDisplacement = SetDisplacement;
        vt.SetOpaque = SetOpaque;
        vt.SetSmoothing = SetSmoothing;
        vt.CustomPacket = CustomPacket;
        vt.Cleanup = Cleanup;
        vt.UpdatePreview = UpdatePreview;
        vt.Flags = Flags;
        vTable = &vt.iunk;
        iid = &lx::guid_CustomMaterial;
    }

    static auto SetupChannels(LXtObjectID wcom,LXtObjectID addChan) -> LxResult
    {
        LXCWxINST (CLxImpl_CustomMaterial, loc);
        try
        {
           return loc->cmt_SetupChannels((ILxUnknownID) addChan);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto LinkChannels(LXtObjectID wcom,LXtObjectID eval,LXtObjectID item) -> LxResult
    {
        LXCWxINST (CLxImpl_CustomMaterial, loc);
        try
        {
           return loc->cmt_LinkChannels((ILxUnknownID) eval,(ILxUnknownID) item);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto LinkSampleChannels(LXtObjectID wcom,LXtObjectID nodalEtor,LXtObjectID item,int *idx) -> LxResult
    {
        LXCWxINST (CLxImpl_CustomMaterial, loc);
        try
        {
           return loc->cmt_LinkSampleChannels((ILxUnknownID) nodalEtor,(ILxUnknownID) item, idx);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto IsSampleDriven(LXtObjectID wcom,int *idx) -> int
    {
        LXCWxINST (CLxImpl_CustomMaterial, loc);
        return loc->cmt_IsSampleDriven( idx);
    }

    static auto ReadChannels(LXtObjectID wcom,LXtObjectID attr,void **ppvData) -> LxResult
    {
        LXCWxINST (CLxImpl_CustomMaterial, loc);
        try
        {
           return loc->cmt_ReadChannels((ILxUnknownID) attr, ppvData);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Customize(LXtObjectID wcom,LXtObjectID custom,void **ppvData) -> LxResult
    {
        LXCWxINST (CLxImpl_CustomMaterial, loc);
        try
        {
           return loc->cmt_Customize((ILxUnknownID) custom, ppvData);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto MaterialEvaluate(LXtObjectID wcom,LXtObjectID etor,int *idx,LXtObjectID vector,void *data) -> void
    {
        LXCWxINST (CLxImpl_CustomMaterial, loc);
        loc->cmt_MaterialEvaluate((ILxUnknownID) etor, idx,(ILxUnknownID) vector, data);
    }

    static auto ShaderEvaluate(LXtObjectID wcom,LXtObjectID vector,LXtObjectID rayObj,LXpShadeComponents *sCmp,LXpShadeOutput *sOut,void *data) -> void
    {
        LXCWxINST (CLxImpl_CustomMaterial, loc);
        loc->cmt_ShaderEvaluate((ILxUnknownID) vector,(ILxUnknownID) rayObj, sCmp, sOut, data);
    }

    static auto SetShadeFlags(LXtObjectID wcom,LXpShadeFlags *sFlg) -> LxResult
    {
        LXCWxINST (CLxImpl_CustomMaterial, loc);
        try
        {
           return loc->cmt_SetShadeFlags( sFlg);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SetBump(LXtObjectID wcom,float *bumpAmplitude,int *clearBump) -> LxResult
    {
        LXCWxINST (CLxImpl_CustomMaterial, loc);
        try
        {
           return loc->cmt_SetBump( bumpAmplitude, clearBump);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SetDisplacement(LXtObjectID wcom,float *dispDist) -> LxResult
    {
        LXCWxINST (CLxImpl_CustomMaterial, loc);
        try
        {
           return loc->cmt_SetDisplacement( dispDist);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SetOpaque(LXtObjectID wcom,int *opaque) -> LxResult
    {
        LXCWxINST (CLxImpl_CustomMaterial, loc);
        try
        {
           return loc->cmt_SetOpaque( opaque);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SetSmoothing(LXtObjectID wcom,double *smooth,double *angle,int *weighting,int *normalMethod,int *creasing) -> LxResult
    {
        LXCWxINST (CLxImpl_CustomMaterial, loc);
        try
        {
           return loc->cmt_SetSmoothing( smooth, angle, weighting, normalMethod, creasing);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto CustomPacket(LXtObjectID wcom,const char **packet) -> LxResult
    {
        LXCWxINST (CLxImpl_CustomMaterial, loc);
        try
        {
           return loc->cmt_CustomPacket( packet);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Cleanup(LXtObjectID wcom,void *data) -> void
    {
        LXCWxINST (CLxImpl_CustomMaterial, loc);
        loc->cmt_Cleanup( data);
    }

    static auto UpdatePreview(LXtObjectID wcom,int chanIdx,int *flags) -> LxResult
    {
        LXCWxINST (CLxImpl_CustomMaterial, loc);
        try
        {
           return loc->cmt_UpdatePreview( chanIdx, flags);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Flags(LXtObjectID wcom) -> int
    {
        LXCWxINST (CLxImpl_CustomMaterial, loc);
        return loc->cmt_Flags();
    }

private:
    ILxCustomMaterial vt;
};

class CLxLoc_CustomMaterial : public CLxLocalize<ILxCustomMaterialID>
{
public:
    CLxLoc_CustomMaterial()
    {
        _init();
    }

    CLxLoc_CustomMaterial(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_CustomMaterial(CLxLoc_CustomMaterial const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_CustomMaterial;
    }

    auto SetupChannels(ILxUnknownID addChan) -> LxResult
    {
        return m_loc[0]->SetupChannels(m_loc,(ILxUnknownID) addChan);
    }

    auto LinkChannels(ILxUnknownID eval, ILxUnknownID item) -> LxResult
    {
        return m_loc[0]->LinkChannels(m_loc,(ILxUnknownID) eval,(ILxUnknownID) item);
    }

    auto LinkSampleChannels(ILxUnknownID nodalEtor, ILxUnknownID item, int *idx) -> LxResult
    {
        return m_loc[0]->LinkSampleChannels(m_loc,(ILxUnknownID) nodalEtor,(ILxUnknownID) item, idx);
    }

    auto IsSampleDriven(int *idx) -> int
    {
        return m_loc[0]->IsSampleDriven(m_loc, idx);
    }

    auto ReadChannels(ILxUnknownID attr, void **ppvData) -> LxResult
    {
        return m_loc[0]->ReadChannels(m_loc,(ILxUnknownID) attr, ppvData);
    }

    auto Customize(ILxUnknownID custom, void **ppvData) -> LxResult
    {
        return m_loc[0]->Customize(m_loc,(ILxUnknownID) custom, ppvData);
    }

    auto MaterialEvaluate(ILxUnknownID etor, int *idx, ILxUnknownID vector, void *data) -> void
    {
        m_loc[0]->MaterialEvaluate(m_loc,(ILxUnknownID) etor, idx,(ILxUnknownID) vector, data);
    }

    auto ShaderEvaluate(ILxUnknownID vector, ILxUnknownID rayObj, LXpShadeComponents *sCmp, LXpShadeOutput *sOut, void *data) -> void
    {
        m_loc[0]->ShaderEvaluate(m_loc,(ILxUnknownID) vector,(ILxUnknownID) rayObj, sCmp, sOut, data);
    }

    auto SetShadeFlags(LXpShadeFlags *sFlg) -> LxResult
    {
        return m_loc[0]->SetShadeFlags(m_loc, sFlg);
    }

    auto SetBump(float *bumpAmplitude, int *clearBump) -> LxResult
    {
        return m_loc[0]->SetBump(m_loc, bumpAmplitude, clearBump);
    }

    auto SetDisplacement(float *dispDist) -> LxResult
    {
        return m_loc[0]->SetDisplacement(m_loc, dispDist);
    }

    auto SetOpaque(int *opaque) -> LxResult
    {
        return m_loc[0]->SetOpaque(m_loc, opaque);
    }

    auto SetSmoothing(double *smooth, double *angle, int *weighting, int *normalMethod, int *creasing) -> LxResult
    {
        return m_loc[0]->SetSmoothing(m_loc, smooth, angle, weighting, normalMethod, creasing);
    }

    auto CustomPacket(const char **packet) -> LxResult
    {
        return m_loc[0]->CustomPacket(m_loc, packet);
    }

    auto Cleanup(void *data) -> void
    {
        m_loc[0]->Cleanup(m_loc, data);
    }

    auto UpdatePreview(int chanIdx, int *flags) -> LxResult
    {
        return m_loc[0]->UpdatePreview(m_loc, chanIdx, flags);
    }

    auto Flags(void) -> int
    {
        return m_loc[0]->Flags(m_loc);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
