//
// C++ wrapper for lxsdk/lxtableau.h.
//
//	Copyright 2024.
//
//
#pragma once

#include <lxtableau.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx
{
    static LXtGUID const guid_TableauSurface1 = {0xB5769A8B, {0x6254, 0x42E3}, {0x86, 0x2F, 0x0A, 0x81, 0x1E, 0x71, 0x6E, 0x21}};
    static LXtGUID const guid_Tableau = {0x76C4EDD9, {0x5FF9, 0x4342}, {0xBB, 0x08, 0xEF, 0xCD, 0x0B, 0x34, 0x40, 0x04}};
    static LXtGUID const guid_TableauElement = {0x71D90AD9, {0x3E30, 0x4CE8}, {0x9E, 0x2B, 0xF7, 0x0D, 0xA2, 0x81, 0xB2, 0xDC}};
    static LXtGUID const guid_TableauSurface = {0xF785D229, {0x6BA5, 0x4C8E}, {0x99, 0x94, 0x3E, 0x50, 0x20, 0x53, 0xB8, 0x3C}};
    static LXtGUID const guid_TriangleSoup = {0x17536C2D, {0x07BD, 0x49C8}, {0x83, 0x48, 0xCE, 0xBD, 0xE4, 0xD3, 0xA8, 0x56}};
    static LXtGUID const guid_TableauVolume = {0x97962302, {0x4B49, 0x4282}, {0xB2, 0x59, 0xF3, 0x47, 0xF1, 0x01, 0x28, 0x18}};
    static LXtGUID const guid_TableauLight = {0x7FE816D1, {0x4A7F, 0x4BE5}, {0x96, 0x89, 0x49, 0x91, 0xC0, 0x3C, 0xAE, 0xE0}};
    static LXtGUID const guid_LightSample = {0x43734621, {0x9B93, 0x4174}, {0xAC, 0x63, 0xE2, 0xFE, 0x7D, 0xDA, 0x87, 0x94}};
    static LXtGUID const guid_TableauProxy = {0xFB34BD64, {0x099C, 0x4B30}, {0x8E, 0xF7, 0x2B, 0xB0, 0x4C, 0xA0, 0xE9, 0x2C}};
    static LXtGUID const guid_TableauInstance = {0x77837A98, {0x2BC5, 0x466C}, {0x83, 0x4F, 0xDC, 0x93, 0x76, 0x42, 0x55, 0x8B}};
    static LXtGUID const guid_TableauShader = {0xA0E3B574, {0xB0AC, 0x4530}, {0xA4, 0x3F, 0x7C, 0xC8, 0xDA, 0x53, 0x6E, 0x25}};
    static LXtGUID const guid_ShaderSlice = {0x47B885B9, {0xB1D9, 0x4F86}, {0x82, 0x9F, 0xA6, 0xAA, 0xBB, 0xD7, 0xFF, 0xF7}};
    static LXtGUID const guid_TableauFilter = {0xFD1326E7, {0xEECF, 0x4EAC}, {0xB9, 0xAD, 0xB1, 0xD6, 0x4E, 0x75, 0x03, 0xBE}};
    static LXtGUID const guid_TableauSource = {0x9CC7F9F4, {0x9540, 0x4EEA}, {0x8E, 0xE9, 0x71, 0x0D, 0x58, 0xEC, 0x68, 0xF9}};
    static LXtGUID const guid_Instanceable = {0x7EFFB896, {0xB794, 0x4030}, {0x86, 0x71, 0xA7, 0xA8, 0xA9, 0x9A, 0x08, 0xC8}};
    static LXtGUID const guid_TableauService = {0x8DF92316, {0x3172, 0x465A}, {0xA1, 0x99, 0x25, 0x47, 0x92, 0xD3, 0x77, 0x32}};
    static LXtGUID const guid_NodalService = {0x2055F206, {0x1682, 0x11E3}, {0x9F, 0x05, 0x6A, 0xCC, 0x60, 0x88, 0x70, 0x9B}};
    static LXtGUID const guid_TableauListener = {0x848C5B64, {0x4C9F, 0x404E}, {0x8E, 0x3F, 0xCF, 0x72, 0x50, 0x07, 0xF7, 0x4D}};
    static LXtGUID const guid_TableauSource1 = {0x1121C167, {0xF934, 0x4421}, {0x8A, 0xBE, 0x32, 0xF8, 0xE4, 0x65, 0x93, 0x24}};
    static LXtGUID const guid_TableauInstance1 = {0x9B57D0DB, {0xC0B4, 0x435E}, {0x8C, 0xDD, 0xE3, 0xDD, 0xCF, 0x66, 0x17, 0x2D}};
} // namespace lx

class CLxImpl_TableauSurface1
{
public:
    virtual ~CLxImpl_TableauSurface1() = default;

    virtual auto tsrf_Bound([[maybe_unused]] LXtTableauBox bbox) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto tsrf_FeatureCount([[maybe_unused]] LXtID4 type) -> unsigned int
    {
        return 0;
    }

    virtual auto tsrf_FeatureByIndex([[maybe_unused]] LXtID4 type, [[maybe_unused]] unsigned int index, [[maybe_unused]] const char **name) -> LxResult
    {
        return LXe_OUTOFBOUNDS;
    }

    virtual auto tsrf_SetVertex([[maybe_unused]] ILxUnknownID vdesc) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto tsrf_Sample([[maybe_unused]] const LXtTableauBox bbox, [[maybe_unused]] float scale, [[maybe_unused]] ILxUnknownID trisoup) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto tsrf_Padding([[maybe_unused]] float *dist) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_TableauSurface1_Bound LxResult tsrf_Bound([[maybe_unused]] LXtTableauBox bbox) override
#define LXxO_TableauSurface1_Bound LXxD_TableauSurface1_Bound
#define LXxC_TableauSurface1_Bound(c) LxResult c::tsrf_Bound([[maybe_unused]] LXtTableauBox bbox)
#define LXxD_TableauSurface1_FeatureCount unsigned int tsrf_FeatureCount([[maybe_unused]] LXtID4 type) override
#define LXxO_TableauSurface1_FeatureCount LXxD_TableauSurface1_FeatureCount
#define LXxC_TableauSurface1_FeatureCount(c) unsigned int c::tsrf_FeatureCount([[maybe_unused]] LXtID4 type)
#define LXxD_TableauSurface1_FeatureByIndex LxResult tsrf_FeatureByIndex([[maybe_unused]] LXtID4 type, [[maybe_unused]] unsigned int index, [[maybe_unused]] const char **name) override
#define LXxO_TableauSurface1_FeatureByIndex LXxD_TableauSurface1_FeatureByIndex
#define LXxC_TableauSurface1_FeatureByIndex(c) LxResult c::tsrf_FeatureByIndex([[maybe_unused]] LXtID4 type, [[maybe_unused]] unsigned int index, [[maybe_unused]] const char **name)
#define LXxD_TableauSurface1_SetVertex LxResult tsrf_SetVertex([[maybe_unused]] ILxUnknownID vdesc) override
#define LXxO_TableauSurface1_SetVertex LXxD_TableauSurface1_SetVertex
#define LXxC_TableauSurface1_SetVertex(c) LxResult c::tsrf_SetVertex([[maybe_unused]] ILxUnknownID vdesc)
#define LXxD_TableauSurface1_Sample LxResult tsrf_Sample([[maybe_unused]] const LXtTableauBox bbox, [[maybe_unused]] float scale, [[maybe_unused]] ILxUnknownID trisoup) override
#define LXxO_TableauSurface1_Sample LXxD_TableauSurface1_Sample
#define LXxC_TableauSurface1_Sample(c) LxResult c::tsrf_Sample([[maybe_unused]] const LXtTableauBox bbox, [[maybe_unused]] float scale, [[maybe_unused]] ILxUnknownID trisoup)
#define LXxD_TableauSurface1_Padding LxResult tsrf_Padding([[maybe_unused]] float *dist) override
#define LXxO_TableauSurface1_Padding LXxD_TableauSurface1_Padding
#define LXxC_TableauSurface1_Padding(c) LxResult c::tsrf_Padding([[maybe_unused]] float *dist)

template <class T>
class CLxIfc_TableauSurface1: public CLxInterface
{
public:
    CLxIfc_TableauSurface1()
    {
        vt.Bound = Bound;
        vt.FeatureCount = FeatureCount;
        vt.FeatureByIndex = FeatureByIndex;
        vt.SetVertex = SetVertex;
        vt.Sample = Sample;
        vt.Padding = Padding;
        vTable = &vt.iunk;
        iid = &lx::guid_TableauSurface1;
    }

    static auto Bound(LXtObjectID wcom,LXtTableauBox bbox) -> LxResult
    {
        LXCWxINST (CLxImpl_TableauSurface1, loc);
        try
        {
           return loc->tsrf_Bound( bbox);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto FeatureCount(LXtObjectID wcom,LXtID4 type) -> unsigned int
    {
        LXCWxINST (CLxImpl_TableauSurface1, loc);
        return loc->tsrf_FeatureCount( type);
    }

    static auto FeatureByIndex(LXtObjectID wcom,LXtID4 type,unsigned int index,const char **name) -> LxResult
    {
        LXCWxINST (CLxImpl_TableauSurface1, loc);
        try
        {
           return loc->tsrf_FeatureByIndex( type, index, name);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SetVertex(LXtObjectID wcom,LXtObjectID vdesc) -> LxResult
    {
        LXCWxINST (CLxImpl_TableauSurface1, loc);
        try
        {
           return loc->tsrf_SetVertex((ILxUnknownID) vdesc);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Sample(LXtObjectID wcom,const LXtTableauBox bbox,float scale,LXtObjectID trisoup) -> LxResult
    {
        LXCWxINST (CLxImpl_TableauSurface1, loc);
        try
        {
           return loc->tsrf_Sample( bbox, scale,(ILxUnknownID) trisoup);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Padding(LXtObjectID wcom,float *dist) -> LxResult
    {
        LXCWxINST (CLxImpl_TableauSurface1, loc);
        try
        {
           return loc->tsrf_Padding( dist);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxTableauSurface1 vt;
};

class CLxLoc_TableauSurface1 : public CLxLocalize<ILxTableauSurface1ID>
{
public:
    CLxLoc_TableauSurface1()
    {
        _init();
    }

    CLxLoc_TableauSurface1(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_TableauSurface1(CLxLoc_TableauSurface1 const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_TableauSurface1;
    }

    auto Bound(LXtTableauBox bbox) -> LxResult
    {
        return m_loc[0]->Bound(m_loc, bbox);
    }

    auto FeatureCount(LXtID4 type) -> unsigned int
    {
        return m_loc[0]->FeatureCount(m_loc, type);
    }

    auto FeatureByIndex(LXtID4 type, unsigned int index, const char **name) -> LxResult
    {
        return m_loc[0]->FeatureByIndex(m_loc, type, index, name);
    }

    auto SetVertex(ILxUnknownID vdesc) -> LxResult
    {
        return m_loc[0]->SetVertex(m_loc,(ILxUnknownID) vdesc);
    }

    auto Sample(const LXtTableauBox bbox, float scale, ILxUnknownID trisoup) -> LxResult
    {
        return m_loc[0]->Sample(m_loc, bbox, scale,(ILxUnknownID) trisoup);
    }

    auto Padding(float *dist) -> LxResult
    {
        return m_loc[0]->Padding(m_loc, dist);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_Tableau : public CLxLocalize<ILxTableauID>
{
public:
    CLxLoc_Tableau()
    {
        _init();
    }

    CLxLoc_Tableau(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_Tableau(CLxLoc_Tableau const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_Tableau;
    }

    auto Time(float *t0, float *interval) -> LxResult
    {
        return m_loc[0]->Time(m_loc, t0, interval);
    }

    auto AddElement(ILxUnknownID element, ILxUnknownID shader) -> LxResult
    {
        return m_loc[0]->AddElement(m_loc,(ILxUnknownID) element,(ILxUnknownID) shader);
    }

    auto AddInstance(ILxUnknownID inst, ILxUnknownID element, ILxUnknownID shader) -> LxResult
    {
        return m_loc[0]->AddInstance(m_loc,(ILxUnknownID) inst,(ILxUnknownID) element,(ILxUnknownID) shader);
    }

    auto Channels(unsigned type, void **ppvObj) -> LxResult
    {
        return m_loc[0]->Channels(m_loc, type, ppvObj);
    }

    auto Channels(unsigned type, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Channels(m_loc, type, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Visible(ILxUnknownID item) -> LxResult
    {
        return m_loc[0]->Visible(m_loc,(ILxUnknownID) item);
    }

    auto FindShader(ILxUnknownID item, ILxUnknownID tags, void **ppvObj) -> LxResult
    {
        return m_loc[0]->FindShader(m_loc,(ILxUnknownID) item,(ILxUnknownID) tags, ppvObj);
    }

    auto FindShader(ILxUnknownID item, ILxUnknownID tags, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->FindShader(m_loc,(ILxUnknownID) item,(ILxUnknownID) tags, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto InstanceItem(void) -> ILxUnknownID
    {
        return (ILxUnknownID)m_loc[0]->InstanceItem(m_loc);
    }

    auto Update(ILxUnknownID visitor, int immediate) -> LxResult
    {
        return m_loc[0]->Update(m_loc,(ILxUnknownID) visitor, immediate);
    }

    auto UpdateAll(void) -> LxResult
    {
        return m_loc[0]->UpdateAll(m_loc);
    }

    auto EltNotify(ILxUnknownID element, int event) -> LxResult
    {
        return m_loc[0]->EltNotify(m_loc,(ILxUnknownID) element, event);
    }

    auto InstNotify(ILxUnknownID instance, int event) -> LxResult
    {
        return m_loc[0]->InstNotify(m_loc,(ILxUnknownID) instance, event);
    }

    auto AddInstanceItem(ILxUnknownID instItem, ILxUnknownID fromItem, ILxUnknownID inst, ILxUnknownID vdesc, const float *vertex) -> LxResult
    {
        return m_loc[0]->AddInstanceItem(m_loc,(ILxUnknownID) instItem,(ILxUnknownID) fromItem,(ILxUnknownID) inst,(ILxUnknownID) vdesc, vertex);
    }

    auto AddInstanceableElement(ILxUnknownID elt, ILxUnknownID tags) -> LxResult
    {
        return m_loc[0]->AddInstanceableElement(m_loc,(ILxUnknownID) elt,(ILxUnknownID) tags);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_TableauElement : public CLxLocalize<ILxTableauElementID>
{
public:
    CLxLoc_TableauElement()
    {
        _init();
    }

    CLxLoc_TableauElement(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_TableauElement(CLxLoc_TableauElement const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_TableauElement;
    }

    auto Bound(LXtTableauBox bbox) -> LxResult
    {
        return m_loc[0]->Bound(m_loc, bbox);
    }

    auto FeatureCount(LXtID4 type) -> unsigned int
    {
        return m_loc[0]->FeatureCount(m_loc, type);
    }

    auto FeatureByIndex(LXtID4 type, unsigned int index, const char **name) -> LxResult
    {
        return m_loc[0]->FeatureByIndex(m_loc, type, index, name);
    }

    auto SetVertex(ILxUnknownID vdesc) -> LxResult
    {
        return m_loc[0]->SetVertex(m_loc,(ILxUnknownID) vdesc);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_TableauSurface
{
public:
    virtual ~CLxImpl_TableauSurface() = default;

    virtual auto tsrf_Bound([[maybe_unused]] LXtTableauBox bbox) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto tsrf_FeatureCount([[maybe_unused]] LXtID4 type) -> unsigned int
    {
        return 0;
    }

    virtual auto tsrf_FeatureByIndex([[maybe_unused]] LXtID4 type, [[maybe_unused]] unsigned int index, [[maybe_unused]] const char **name) -> LxResult
    {
        return LXe_OUTOFBOUNDS;
    }

    virtual auto tsrf_SetVertex([[maybe_unused]] ILxUnknownID vdesc) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto tsrf_Sample([[maybe_unused]] const LXtTableauBox bbox, [[maybe_unused]] float scale, [[maybe_unused]] ILxUnknownID trisoup) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto tsrf_Padding([[maybe_unused]] float *dist) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto tsrf_SegmentBox([[maybe_unused]] unsigned int segID, [[maybe_unused]] LXtTableauBox bbox) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_TableauSurface_Bound LxResult tsrf_Bound([[maybe_unused]] LXtTableauBox bbox) override
#define LXxO_TableauSurface_Bound LXxD_TableauSurface_Bound
#define LXxC_TableauSurface_Bound(c) LxResult c::tsrf_Bound([[maybe_unused]] LXtTableauBox bbox)
#define LXxD_TableauSurface_FeatureCount unsigned int tsrf_FeatureCount([[maybe_unused]] LXtID4 type) override
#define LXxO_TableauSurface_FeatureCount LXxD_TableauSurface_FeatureCount
#define LXxC_TableauSurface_FeatureCount(c) unsigned int c::tsrf_FeatureCount([[maybe_unused]] LXtID4 type)
#define LXxD_TableauSurface_FeatureByIndex LxResult tsrf_FeatureByIndex([[maybe_unused]] LXtID4 type, [[maybe_unused]] unsigned int index, [[maybe_unused]] const char **name) override
#define LXxO_TableauSurface_FeatureByIndex LXxD_TableauSurface_FeatureByIndex
#define LXxC_TableauSurface_FeatureByIndex(c) LxResult c::tsrf_FeatureByIndex([[maybe_unused]] LXtID4 type, [[maybe_unused]] unsigned int index, [[maybe_unused]] const char **name)
#define LXxD_TableauSurface_SetVertex LxResult tsrf_SetVertex([[maybe_unused]] ILxUnknownID vdesc) override
#define LXxO_TableauSurface_SetVertex LXxD_TableauSurface_SetVertex
#define LXxC_TableauSurface_SetVertex(c) LxResult c::tsrf_SetVertex([[maybe_unused]] ILxUnknownID vdesc)
#define LXxD_TableauSurface_Sample LxResult tsrf_Sample([[maybe_unused]] const LXtTableauBox bbox, [[maybe_unused]] float scale, [[maybe_unused]] ILxUnknownID trisoup) override
#define LXxO_TableauSurface_Sample LXxD_TableauSurface_Sample
#define LXxC_TableauSurface_Sample(c) LxResult c::tsrf_Sample([[maybe_unused]] const LXtTableauBox bbox, [[maybe_unused]] float scale, [[maybe_unused]] ILxUnknownID trisoup)
#define LXxD_TableauSurface_Padding LxResult tsrf_Padding([[maybe_unused]] float *dist) override
#define LXxO_TableauSurface_Padding LXxD_TableauSurface_Padding
#define LXxC_TableauSurface_Padding(c) LxResult c::tsrf_Padding([[maybe_unused]] float *dist)
#define LXxD_TableauSurface_SegmentBox LxResult tsrf_SegmentBox([[maybe_unused]] unsigned int segID, [[maybe_unused]] LXtTableauBox bbox) override
#define LXxO_TableauSurface_SegmentBox LXxD_TableauSurface_SegmentBox
#define LXxC_TableauSurface_SegmentBox(c) LxResult c::tsrf_SegmentBox([[maybe_unused]] unsigned int segID, [[maybe_unused]] LXtTableauBox bbox)

template <class T>
class CLxIfc_TableauSurface: public CLxInterface
{
public:
    CLxIfc_TableauSurface()
    {
        vt.Bound = Bound;
        vt.FeatureCount = FeatureCount;
        vt.FeatureByIndex = FeatureByIndex;
        vt.SetVertex = SetVertex;
        vt.Sample = Sample;
        vt.Padding = Padding;
        vt.SegmentBox = SegmentBox;
        vTable = &vt.iunk;
        iid = &lx::guid_TableauSurface;
    }

    static auto Bound(LXtObjectID wcom,LXtTableauBox bbox) -> LxResult
    {
        LXCWxINST (CLxImpl_TableauSurface, loc);
        try
        {
           return loc->tsrf_Bound( bbox);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto FeatureCount(LXtObjectID wcom,LXtID4 type) -> unsigned int
    {
        LXCWxINST (CLxImpl_TableauSurface, loc);
        return loc->tsrf_FeatureCount( type);
    }

    static auto FeatureByIndex(LXtObjectID wcom,LXtID4 type,unsigned int index,const char **name) -> LxResult
    {
        LXCWxINST (CLxImpl_TableauSurface, loc);
        try
        {
           return loc->tsrf_FeatureByIndex( type, index, name);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SetVertex(LXtObjectID wcom,LXtObjectID vdesc) -> LxResult
    {
        LXCWxINST (CLxImpl_TableauSurface, loc);
        try
        {
           return loc->tsrf_SetVertex((ILxUnknownID) vdesc);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Sample(LXtObjectID wcom,const LXtTableauBox bbox,float scale,LXtObjectID trisoup) -> LxResult
    {
        LXCWxINST (CLxImpl_TableauSurface, loc);
        try
        {
           return loc->tsrf_Sample( bbox, scale,(ILxUnknownID) trisoup);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Padding(LXtObjectID wcom,float *dist) -> LxResult
    {
        LXCWxINST (CLxImpl_TableauSurface, loc);
        try
        {
           return loc->tsrf_Padding( dist);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SegmentBox(LXtObjectID wcom,unsigned int segID,LXtTableauBox bbox) -> LxResult
    {
        LXCWxINST (CLxImpl_TableauSurface, loc);
        try
        {
           return loc->tsrf_SegmentBox( segID, bbox);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxTableauSurface vt;
};

class CLxLoc_TableauSurface : public CLxLocalize<ILxTableauSurfaceID>
{
public:
    CLxLoc_TableauSurface()
    {
        _init();
    }

    CLxLoc_TableauSurface(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_TableauSurface(CLxLoc_TableauSurface const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_TableauSurface;
    }

    auto Bound(LXtTableauBox bbox) -> LxResult
    {
        return m_loc[0]->Bound(m_loc, bbox);
    }

    auto FeatureCount(LXtID4 type) -> unsigned int
    {
        return m_loc[0]->FeatureCount(m_loc, type);
    }

    auto FeatureByIndex(LXtID4 type, unsigned int index, const char **name) -> LxResult
    {
        return m_loc[0]->FeatureByIndex(m_loc, type, index, name);
    }

    auto SetVertex(ILxUnknownID vdesc) -> LxResult
    {
        return m_loc[0]->SetVertex(m_loc,(ILxUnknownID) vdesc);
    }

    auto Sample(const LXtTableauBox bbox, float scale, ILxUnknownID trisoup) -> LxResult
    {
        return m_loc[0]->Sample(m_loc, bbox, scale,(ILxUnknownID) trisoup);
    }

    auto Padding(float *dist) -> LxResult
    {
        return m_loc[0]->Padding(m_loc, dist);
    }

    auto SegmentBox(unsigned int segID, LXtTableauBox bbox) -> LxResult
    {
        return m_loc[0]->SegmentBox(m_loc, segID, bbox);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_TriangleSoup
{
public:
    virtual ~CLxImpl_TriangleSoup() = default;

    virtual auto soup_TestBox([[maybe_unused]] const LXtTableauBox bbox) -> unsigned int
    {
        return 1;
    }

    virtual auto soup_Segment([[maybe_unused]] unsigned int segID, [[maybe_unused]] unsigned int type) -> LxResult
    {
        return LXe_TRUE;
    }

    virtual auto soup_Vertex([[maybe_unused]] const float *vertex, [[maybe_unused]] unsigned int *index) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto soup_Polygon([[maybe_unused]] unsigned int v0, [[maybe_unused]] unsigned int v1, [[maybe_unused]] unsigned int v2) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual void soup_Connect([[maybe_unused]] unsigned int type)
    {
    }
};

#define LXxD_TriangleSoup_TestBox unsigned int soup_TestBox([[maybe_unused]] const LXtTableauBox bbox) override
#define LXxO_TriangleSoup_TestBox LXxD_TriangleSoup_TestBox
#define LXxC_TriangleSoup_TestBox(c) unsigned int c::soup_TestBox([[maybe_unused]] const LXtTableauBox bbox)
#define LXxD_TriangleSoup_Segment LxResult soup_Segment([[maybe_unused]] unsigned int segID, [[maybe_unused]] unsigned int type) override
#define LXxO_TriangleSoup_Segment LXxD_TriangleSoup_Segment
#define LXxC_TriangleSoup_Segment(c) LxResult c::soup_Segment([[maybe_unused]] unsigned int segID, [[maybe_unused]] unsigned int type)
#define LXxD_TriangleSoup_Vertex LxResult soup_Vertex([[maybe_unused]] const float *vertex, [[maybe_unused]] unsigned int *index) override
#define LXxO_TriangleSoup_Vertex LXxD_TriangleSoup_Vertex
#define LXxC_TriangleSoup_Vertex(c) LxResult c::soup_Vertex([[maybe_unused]] const float *vertex, [[maybe_unused]] unsigned int *index)
#define LXxD_TriangleSoup_Polygon LxResult soup_Polygon([[maybe_unused]] unsigned int v0, [[maybe_unused]] unsigned int v1, [[maybe_unused]] unsigned int v2) override
#define LXxO_TriangleSoup_Polygon LXxD_TriangleSoup_Polygon
#define LXxC_TriangleSoup_Polygon(c) LxResult c::soup_Polygon([[maybe_unused]] unsigned int v0, [[maybe_unused]] unsigned int v1, [[maybe_unused]] unsigned int v2)
#define LXxD_TriangleSoup_Connect void soup_Connect([[maybe_unused]] unsigned int type) override
#define LXxO_TriangleSoup_Connect LXxD_TriangleSoup_Connect
#define LXxC_TriangleSoup_Connect(c) void c::soup_Connect([[maybe_unused]] unsigned int type)

template <class T>
class CLxIfc_TriangleSoup: public CLxInterface
{
public:
    CLxIfc_TriangleSoup()
    {
        vt.TestBox = TestBox;
        vt.Segment = Segment;
        vt.Vertex = Vertex;
        vt.Polygon = Polygon;
        vt.Connect = Connect;
        vTable = &vt.iunk;
        iid = &lx::guid_TriangleSoup;
    }

    static auto TestBox(LXtObjectID wcom,const LXtTableauBox bbox) -> unsigned int
    {
        LXCWxINST (CLxImpl_TriangleSoup, loc);
        return loc->soup_TestBox( bbox);
    }

    static auto Segment(LXtObjectID wcom,unsigned int segID,unsigned int type) -> LxResult
    {
        LXCWxINST (CLxImpl_TriangleSoup, loc);
        try
        {
           return loc->soup_Segment( segID, type);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Vertex(LXtObjectID wcom,const float *vertex,unsigned int *index) -> LxResult
    {
        LXCWxINST (CLxImpl_TriangleSoup, loc);
        try
        {
           return loc->soup_Vertex( vertex, index);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Polygon(LXtObjectID wcom,unsigned int v0,unsigned int v1,unsigned int v2) -> LxResult
    {
        LXCWxINST (CLxImpl_TriangleSoup, loc);
        try
        {
           return loc->soup_Polygon( v0, v1, v2);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Connect(LXtObjectID wcom,unsigned int type) -> void
    {
        LXCWxINST (CLxImpl_TriangleSoup, loc);
        loc->soup_Connect( type);
    }

private:
    ILxTriangleSoup vt;
};

class CLxLoc_TriangleSoup : public CLxLocalize<ILxTriangleSoupID>
{
public:
    CLxLoc_TriangleSoup()
    {
        _init();
    }

    CLxLoc_TriangleSoup(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_TriangleSoup(CLxLoc_TriangleSoup const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_TriangleSoup;
    }

    auto TestBox(const LXtTableauBox bbox) -> unsigned int
    {
        return m_loc[0]->TestBox(m_loc, bbox);
    }

    auto Segment(unsigned int segID, unsigned int type) -> LxResult
    {
        return m_loc[0]->Segment(m_loc, segID, type);
    }

    auto Vertex(const float *vertex, unsigned int *index) -> LxResult
    {
        return m_loc[0]->Vertex(m_loc, vertex, index);
    }

    auto Polygon(unsigned int v0, unsigned int v1, unsigned int v2) -> LxResult
    {
        return m_loc[0]->Polygon(m_loc, v0, v1, v2);
    }

    auto Connect(unsigned int type) -> void
    {
        m_loc[0]->Connect(m_loc, type);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_TableauVolume
{
public:
    virtual ~CLxImpl_TableauVolume() = default;

    virtual auto tvol_Bound([[maybe_unused]] LXtTableauBox bbox) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto tvol_FeatureCount([[maybe_unused]] LXtID4 type) -> unsigned int
    {
        return 0;
    }

    virtual auto tvol_FeatureByIndex([[maybe_unused]] LXtID4 type, [[maybe_unused]] unsigned int index, [[maybe_unused]] const char **name) -> LxResult
    {
        return LXe_OUTOFBOUNDS;
    }

    virtual auto tvol_SetVertex([[maybe_unused]] ILxUnknownID vdesc) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual int tvol_Type(void) = 0;

    virtual auto tvol_RenderInit([[maybe_unused]] ILxUnknownID sv) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto tvol_RaySample([[maybe_unused]] ILxUnknownID densitySlice, [[maybe_unused]] ILxUnknownID shadingSlice, [[maybe_unused]] ILxUnknownID sv, [[maybe_unused]] ILxUnknownID raycastObj, [[maybe_unused]] ILxUnknownID raymarchObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto tvol_RayCast([[maybe_unused]] ILxUnknownID densitySlice, [[maybe_unused]] ILxUnknownID sv, [[maybe_unused]] ILxUnknownID raycastObj, [[maybe_unused]] double *dist, [[maybe_unused]] int *localShader) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto tvol_Density([[maybe_unused]] ILxUnknownID densitySlice, [[maybe_unused]] ILxUnknownID sv, [[maybe_unused]] ILxUnknownID raycastObj, [[maybe_unused]] const LXtVector pos, [[maybe_unused]] int worldPos, [[maybe_unused]] double *dens) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_TableauVolume_Bound LxResult tvol_Bound([[maybe_unused]] LXtTableauBox bbox) override
#define LXxO_TableauVolume_Bound LXxD_TableauVolume_Bound
#define LXxC_TableauVolume_Bound(c) LxResult c::tvol_Bound([[maybe_unused]] LXtTableauBox bbox)
#define LXxD_TableauVolume_FeatureCount unsigned int tvol_FeatureCount([[maybe_unused]] LXtID4 type) override
#define LXxO_TableauVolume_FeatureCount LXxD_TableauVolume_FeatureCount
#define LXxC_TableauVolume_FeatureCount(c) unsigned int c::tvol_FeatureCount([[maybe_unused]] LXtID4 type)
#define LXxD_TableauVolume_FeatureByIndex LxResult tvol_FeatureByIndex([[maybe_unused]] LXtID4 type, [[maybe_unused]] unsigned int index, [[maybe_unused]] const char **name) override
#define LXxO_TableauVolume_FeatureByIndex LXxD_TableauVolume_FeatureByIndex
#define LXxC_TableauVolume_FeatureByIndex(c) LxResult c::tvol_FeatureByIndex([[maybe_unused]] LXtID4 type, [[maybe_unused]] unsigned int index, [[maybe_unused]] const char **name)
#define LXxD_TableauVolume_SetVertex LxResult tvol_SetVertex([[maybe_unused]] ILxUnknownID vdesc) override
#define LXxO_TableauVolume_SetVertex LXxD_TableauVolume_SetVertex
#define LXxC_TableauVolume_SetVertex(c) LxResult c::tvol_SetVertex([[maybe_unused]] ILxUnknownID vdesc)
#define LXxD_TableauVolume_Type int tvol_Type() override
#define LXxO_TableauVolume_Type LXxD_TableauVolume_Type
#define LXxC_TableauVolume_Type(c) int c::tvol_Type()
#define LXxD_TableauVolume_RenderInit LxResult tvol_RenderInit([[maybe_unused]] ILxUnknownID sv) override
#define LXxO_TableauVolume_RenderInit LXxD_TableauVolume_RenderInit
#define LXxC_TableauVolume_RenderInit(c) LxResult c::tvol_RenderInit([[maybe_unused]] ILxUnknownID sv)
#define LXxD_TableauVolume_RaySample LxResult tvol_RaySample([[maybe_unused]] ILxUnknownID densitySlice, [[maybe_unused]] ILxUnknownID shadingSlice, [[maybe_unused]] ILxUnknownID sv, [[maybe_unused]] ILxUnknownID raycastObj, [[maybe_unused]] ILxUnknownID raymarchObj) override
#define LXxO_TableauVolume_RaySample LXxD_TableauVolume_RaySample
#define LXxC_TableauVolume_RaySample(c) LxResult c::tvol_RaySample([[maybe_unused]] ILxUnknownID densitySlice, [[maybe_unused]] ILxUnknownID shadingSlice, [[maybe_unused]] ILxUnknownID sv, [[maybe_unused]] ILxUnknownID raycastObj, [[maybe_unused]] ILxUnknownID raymarchObj)
#define LXxD_TableauVolume_RayCast LxResult tvol_RayCast([[maybe_unused]] ILxUnknownID densitySlice, [[maybe_unused]] ILxUnknownID sv, [[maybe_unused]] ILxUnknownID raycastObj, [[maybe_unused]] double *dist, [[maybe_unused]] int *localShader) override
#define LXxO_TableauVolume_RayCast LXxD_TableauVolume_RayCast
#define LXxC_TableauVolume_RayCast(c) LxResult c::tvol_RayCast([[maybe_unused]] ILxUnknownID densitySlice, [[maybe_unused]] ILxUnknownID sv, [[maybe_unused]] ILxUnknownID raycastObj, [[maybe_unused]] double *dist, [[maybe_unused]] int *localShader)
#define LXxD_TableauVolume_Density LxResult tvol_Density([[maybe_unused]] ILxUnknownID densitySlice, [[maybe_unused]] ILxUnknownID sv, [[maybe_unused]] ILxUnknownID raycastObj, [[maybe_unused]] const LXtVector pos, [[maybe_unused]] int worldPos, [[maybe_unused]] double *dens) override
#define LXxO_TableauVolume_Density LXxD_TableauVolume_Density
#define LXxC_TableauVolume_Density(c) LxResult c::tvol_Density([[maybe_unused]] ILxUnknownID densitySlice, [[maybe_unused]] ILxUnknownID sv, [[maybe_unused]] ILxUnknownID raycastObj, [[maybe_unused]] const LXtVector pos, [[maybe_unused]] int worldPos, [[maybe_unused]] double *dens)

template <class T>
class CLxIfc_TableauVolume: public CLxInterface
{
public:
    CLxIfc_TableauVolume()
    {
        vt.Bound = Bound;
        vt.FeatureCount = FeatureCount;
        vt.FeatureByIndex = FeatureByIndex;
        vt.SetVertex = SetVertex;
        vt.Type = Type;
        vt.RenderInit = RenderInit;
        vt.RaySample = RaySample;
        vt.RayCast = RayCast;
        vt.Density = Density;
        vTable = &vt.iunk;
        iid = &lx::guid_TableauVolume;
    }

    static auto Bound(LXtObjectID wcom,LXtTableauBox bbox) -> LxResult
    {
        LXCWxINST (CLxImpl_TableauVolume, loc);
        try
        {
           return loc->tvol_Bound( bbox);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto FeatureCount(LXtObjectID wcom,LXtID4 type) -> unsigned int
    {
        LXCWxINST (CLxImpl_TableauVolume, loc);
        return loc->tvol_FeatureCount( type);
    }

    static auto FeatureByIndex(LXtObjectID wcom,LXtID4 type,unsigned int index,const char **name) -> LxResult
    {
        LXCWxINST (CLxImpl_TableauVolume, loc);
        try
        {
           return loc->tvol_FeatureByIndex( type, index, name);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SetVertex(LXtObjectID wcom,LXtObjectID vdesc) -> LxResult
    {
        LXCWxINST (CLxImpl_TableauVolume, loc);
        try
        {
           return loc->tvol_SetVertex((ILxUnknownID) vdesc);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Type(LXtObjectID wcom) -> int
    {
        LXCWxINST (CLxImpl_TableauVolume, loc);
        return loc->tvol_Type();
    }

    static auto RenderInit(LXtObjectID wcom,LXtObjectID sv) -> LxResult
    {
        LXCWxINST (CLxImpl_TableauVolume, loc);
        try
        {
           return loc->tvol_RenderInit((ILxUnknownID) sv);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto RaySample(LXtObjectID wcom,LXtObjectID densitySlice,LXtObjectID shadingSlice,LXtObjectID sv,LXtObjectID raycastObj,LXtObjectID raymarchObj) -> LxResult
    {
        LXCWxINST (CLxImpl_TableauVolume, loc);
        try
        {
           return loc->tvol_RaySample((ILxUnknownID) densitySlice,(ILxUnknownID) shadingSlice,(ILxUnknownID) sv,(ILxUnknownID) raycastObj,(ILxUnknownID) raymarchObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto RayCast(LXtObjectID wcom,LXtObjectID densitySlice,LXtObjectID sv,LXtObjectID raycastObj,double *dist,int *localShader) -> LxResult
    {
        LXCWxINST (CLxImpl_TableauVolume, loc);
        try
        {
           return loc->tvol_RayCast((ILxUnknownID) densitySlice,(ILxUnknownID) sv,(ILxUnknownID) raycastObj, dist, localShader);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Density(LXtObjectID wcom,LXtObjectID densitySlice,LXtObjectID sv,LXtObjectID raycastObj,const LXtVector pos,int worldPos,double *dens) -> LxResult
    {
        LXCWxINST (CLxImpl_TableauVolume, loc);
        try
        {
           return loc->tvol_Density((ILxUnknownID) densitySlice,(ILxUnknownID) sv,(ILxUnknownID) raycastObj, pos, worldPos, dens);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxTableauVolume vt;
};

class CLxLoc_TableauVolume : public CLxLocalize<ILxTableauVolumeID>
{
public:
    CLxLoc_TableauVolume()
    {
        _init();
    }

    CLxLoc_TableauVolume(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_TableauVolume(CLxLoc_TableauVolume const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_TableauVolume;
    }

    auto Bound(LXtTableauBox bbox) -> LxResult
    {
        return m_loc[0]->Bound(m_loc, bbox);
    }

    auto FeatureCount(LXtID4 type) -> unsigned int
    {
        return m_loc[0]->FeatureCount(m_loc, type);
    }

    auto FeatureByIndex(LXtID4 type, unsigned int index, const char **name) -> LxResult
    {
        return m_loc[0]->FeatureByIndex(m_loc, type, index, name);
    }

    auto SetVertex(ILxUnknownID vdesc) -> LxResult
    {
        return m_loc[0]->SetVertex(m_loc,(ILxUnknownID) vdesc);
    }

    auto Type(void) -> int
    {
        return m_loc[0]->Type(m_loc);
    }

    auto RenderInit(ILxUnknownID sv) -> LxResult
    {
        return m_loc[0]->RenderInit(m_loc,(ILxUnknownID) sv);
    }

    auto RaySample(ILxUnknownID densitySlice, ILxUnknownID shadingSlice, ILxUnknownID sv, ILxUnknownID raycastObj, ILxUnknownID raymarchObj) -> LxResult
    {
        return m_loc[0]->RaySample(m_loc,(ILxUnknownID) densitySlice,(ILxUnknownID) shadingSlice,(ILxUnknownID) sv,(ILxUnknownID) raycastObj,(ILxUnknownID) raymarchObj);
    }

    auto RayCast(ILxUnknownID densitySlice, ILxUnknownID sv, ILxUnknownID raycastObj, double *dist, int *localShader) -> LxResult
    {
        return m_loc[0]->RayCast(m_loc,(ILxUnknownID) densitySlice,(ILxUnknownID) sv,(ILxUnknownID) raycastObj, dist, localShader);
    }

    auto Density(ILxUnknownID densitySlice, ILxUnknownID sv, ILxUnknownID raycastObj, const LXtVector pos, int worldPos, double *dens) -> LxResult
    {
        return m_loc[0]->Density(m_loc,(ILxUnknownID) densitySlice,(ILxUnknownID) sv,(ILxUnknownID) raycastObj, pos, worldPos, dens);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_TableauLight
{
public:
    virtual ~CLxImpl_TableauLight() = default;

    virtual auto tlgt_Bound([[maybe_unused]] LXtTableauBox bbox) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto tlgt_FeatureCount([[maybe_unused]] LXtID4 type) -> unsigned int
    {
        return 0;
    }

    virtual auto tlgt_FeatureByIndex([[maybe_unused]] LXtID4 type, [[maybe_unused]] unsigned int index, [[maybe_unused]] const char **name) -> LxResult
    {
        return LXe_OUTOFBOUNDS;
    }

    virtual auto tlgt_SetVertex([[maybe_unused]] ILxUnknownID vdesc) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto tlgt_Sample([[maybe_unused]] float u, [[maybe_unused]] float v, [[maybe_unused]] const LXtFVector dir, [[maybe_unused]] LXtFVector wPos, [[maybe_unused]] LXtFVector oPos, [[maybe_unused]] LXtFVector norm, [[maybe_unused]] float t) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual int tlgt_Geometry(void *gc) = 0;

    virtual auto tlgt_Emit([[maybe_unused]] unsigned int nPhotons, [[maybe_unused]] int offset, [[maybe_unused]] ILxUnknownID slice, [[maybe_unused]] LXtSampleVectorID sv) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual int tlgt_ShadowMap(void **ppvObj) = 0;
};

#define LXxD_TableauLight_Bound LxResult tlgt_Bound([[maybe_unused]] LXtTableauBox bbox) override
#define LXxO_TableauLight_Bound LXxD_TableauLight_Bound
#define LXxC_TableauLight_Bound(c) LxResult c::tlgt_Bound([[maybe_unused]] LXtTableauBox bbox)
#define LXxD_TableauLight_FeatureCount unsigned int tlgt_FeatureCount([[maybe_unused]] LXtID4 type) override
#define LXxO_TableauLight_FeatureCount LXxD_TableauLight_FeatureCount
#define LXxC_TableauLight_FeatureCount(c) unsigned int c::tlgt_FeatureCount([[maybe_unused]] LXtID4 type)
#define LXxD_TableauLight_FeatureByIndex LxResult tlgt_FeatureByIndex([[maybe_unused]] LXtID4 type, [[maybe_unused]] unsigned int index, [[maybe_unused]] const char **name) override
#define LXxO_TableauLight_FeatureByIndex LXxD_TableauLight_FeatureByIndex
#define LXxC_TableauLight_FeatureByIndex(c) LxResult c::tlgt_FeatureByIndex([[maybe_unused]] LXtID4 type, [[maybe_unused]] unsigned int index, [[maybe_unused]] const char **name)
#define LXxD_TableauLight_SetVertex LxResult tlgt_SetVertex([[maybe_unused]] ILxUnknownID vdesc) override
#define LXxO_TableauLight_SetVertex LXxD_TableauLight_SetVertex
#define LXxC_TableauLight_SetVertex(c) LxResult c::tlgt_SetVertex([[maybe_unused]] ILxUnknownID vdesc)
#define LXxD_TableauLight_Sample LxResult tlgt_Sample([[maybe_unused]] float u, [[maybe_unused]] float v, [[maybe_unused]] const LXtFVector dir, [[maybe_unused]] LXtFVector wPos, [[maybe_unused]] LXtFVector oPos, [[maybe_unused]] LXtFVector norm, [[maybe_unused]] float t) override
#define LXxO_TableauLight_Sample LXxD_TableauLight_Sample
#define LXxC_TableauLight_Sample(c) LxResult c::tlgt_Sample([[maybe_unused]] float u, [[maybe_unused]] float v, [[maybe_unused]] const LXtFVector dir, [[maybe_unused]] LXtFVector wPos, [[maybe_unused]] LXtFVector oPos, [[maybe_unused]] LXtFVector norm, [[maybe_unused]] float t)
#define LXxD_TableauLight_Geometry int tlgt_Geometry([[maybe_unused]] void *gc) override
#define LXxO_TableauLight_Geometry LXxD_TableauLight_Geometry
#define LXxC_TableauLight_Geometry(c) int c::tlgt_Geometry([[maybe_unused]] void *gc)
#define LXxD_TableauLight_Emit LxResult tlgt_Emit([[maybe_unused]] unsigned int nPhotons, [[maybe_unused]] int offset, [[maybe_unused]] ILxUnknownID slice, [[maybe_unused]] LXtSampleVectorID sv) override
#define LXxO_TableauLight_Emit LXxD_TableauLight_Emit
#define LXxC_TableauLight_Emit(c) LxResult c::tlgt_Emit([[maybe_unused]] unsigned int nPhotons, [[maybe_unused]] int offset, [[maybe_unused]] ILxUnknownID slice, [[maybe_unused]] LXtSampleVectorID sv)
#define LXxD_TableauLight_ShadowMap int tlgt_ShadowMap([[maybe_unused]] void **ppvObj) override
#define LXxO_TableauLight_ShadowMap LXxD_TableauLight_ShadowMap
#define LXxC_TableauLight_ShadowMap(c) int c::tlgt_ShadowMap([[maybe_unused]] void **ppvObj)

template <class T>
class CLxIfc_TableauLight: public CLxInterface
{
public:
    CLxIfc_TableauLight()
    {
        vt.Bound = Bound;
        vt.FeatureCount = FeatureCount;
        vt.FeatureByIndex = FeatureByIndex;
        vt.SetVertex = SetVertex;
        vt.Sample = Sample;
        vt.Geometry = Geometry;
        vt.Emit = Emit;
        vt.ShadowMap = ShadowMap;
        vTable = &vt.iunk;
        iid = &lx::guid_TableauLight;
    }

    static auto Bound(LXtObjectID wcom,LXtTableauBox bbox) -> LxResult
    {
        LXCWxINST (CLxImpl_TableauLight, loc);
        try
        {
           return loc->tlgt_Bound( bbox);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto FeatureCount(LXtObjectID wcom,LXtID4 type) -> unsigned int
    {
        LXCWxINST (CLxImpl_TableauLight, loc);
        return loc->tlgt_FeatureCount( type);
    }

    static auto FeatureByIndex(LXtObjectID wcom,LXtID4 type,unsigned int index,const char **name) -> LxResult
    {
        LXCWxINST (CLxImpl_TableauLight, loc);
        try
        {
           return loc->tlgt_FeatureByIndex( type, index, name);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SetVertex(LXtObjectID wcom,LXtObjectID vdesc) -> LxResult
    {
        LXCWxINST (CLxImpl_TableauLight, loc);
        try
        {
           return loc->tlgt_SetVertex((ILxUnknownID) vdesc);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Sample(LXtObjectID wcom,float u,float v,const LXtFVector dir,LXtFVector wPos,LXtFVector oPos,LXtFVector norm,float t) -> LxResult
    {
        LXCWxINST (CLxImpl_TableauLight, loc);
        try
        {
           return loc->tlgt_Sample( u, v, dir, wPos, oPos, norm, t);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Geometry(LXtObjectID wcom,void *gc) -> int
    {
        LXCWxINST (CLxImpl_TableauLight, loc);
        return loc->tlgt_Geometry( gc);
    }

    static auto Emit(LXtObjectID wcom,unsigned int nPhotons,int offset,LXtObjectID slice,LXtSampleVectorID sv) -> LxResult
    {
        LXCWxINST (CLxImpl_TableauLight, loc);
        try
        {
           return loc->tlgt_Emit( nPhotons, offset,(ILxUnknownID) slice, sv);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ShadowMap(LXtObjectID wcom,void **ppvObj) -> int
    {
        LXCWxINST (CLxImpl_TableauLight, loc);
        return loc->tlgt_ShadowMap( ppvObj);
    }

private:
    ILxTableauLight vt;
};

class CLxLoc_TableauLight : public CLxLocalize<ILxTableauLightID>
{
public:
    CLxLoc_TableauLight()
    {
        _init();
    }

    CLxLoc_TableauLight(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_TableauLight(CLxLoc_TableauLight const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_TableauLight;
    }

    auto Bound(LXtTableauBox bbox) -> LxResult
    {
        return m_loc[0]->Bound(m_loc, bbox);
    }

    auto FeatureCount(LXtID4 type) -> unsigned int
    {
        return m_loc[0]->FeatureCount(m_loc, type);
    }

    auto FeatureByIndex(LXtID4 type, unsigned int index, const char **name) -> LxResult
    {
        return m_loc[0]->FeatureByIndex(m_loc, type, index, name);
    }

    auto SetVertex(ILxUnknownID vdesc) -> LxResult
    {
        return m_loc[0]->SetVertex(m_loc,(ILxUnknownID) vdesc);
    }

    auto Sample(float u, float v, const LXtFVector dir, LXtFVector wPos, LXtFVector oPos, LXtFVector norm, float t) -> LxResult
    {
        return m_loc[0]->Sample(m_loc, u, v, dir, wPos, oPos, norm, t);
    }

    auto Geometry(void *gc) -> int
    {
        return m_loc[0]->Geometry(m_loc, gc);
    }

    auto Emit(unsigned int nPhotons, int offset, ILxUnknownID slice, LXtSampleVectorID sv) -> LxResult
    {
        return m_loc[0]->Emit(m_loc, nPhotons, offset,(ILxUnknownID) slice, sv);
    }

    auto ShadowMap(void **ppvObj) -> int
    {
        return m_loc[0]->ShadowMap(m_loc, ppvObj);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_LightSample : public CLxLocalize<ILxLightSampleID>
{
public:
    CLxLoc_LightSample()
    {
        _init();
    }

    CLxLoc_LightSample(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_LightSample(CLxLoc_LightSample const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_LightSample;
    }

    auto Vertex(const float *vertex) -> void
    {
        m_loc[0]->Vertex(m_loc, vertex);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_TableauProxy
{
public:
    virtual ~CLxImpl_TableauProxy() = default;

    virtual auto tpro_Bound([[maybe_unused]] LXtTableauBox bbox) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto tpro_FeatureCount([[maybe_unused]] LXtID4 type) -> unsigned int
    {
        return 0;
    }

    virtual auto tpro_FeatureByIndex([[maybe_unused]] LXtID4 type, [[maybe_unused]] unsigned int index, [[maybe_unused]] const char **name) -> LxResult
    {
        return LXe_OUTOFBOUNDS;
    }

    virtual auto tpro_SetVertex([[maybe_unused]] ILxUnknownID vdesc) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto tpro_Sample([[maybe_unused]] const LXtTableauBox bbox, [[maybe_unused]] ILxUnknownID tableau) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_TableauProxy_Bound LxResult tpro_Bound([[maybe_unused]] LXtTableauBox bbox) override
#define LXxO_TableauProxy_Bound LXxD_TableauProxy_Bound
#define LXxC_TableauProxy_Bound(c) LxResult c::tpro_Bound([[maybe_unused]] LXtTableauBox bbox)
#define LXxD_TableauProxy_FeatureCount unsigned int tpro_FeatureCount([[maybe_unused]] LXtID4 type) override
#define LXxO_TableauProxy_FeatureCount LXxD_TableauProxy_FeatureCount
#define LXxC_TableauProxy_FeatureCount(c) unsigned int c::tpro_FeatureCount([[maybe_unused]] LXtID4 type)
#define LXxD_TableauProxy_FeatureByIndex LxResult tpro_FeatureByIndex([[maybe_unused]] LXtID4 type, [[maybe_unused]] unsigned int index, [[maybe_unused]] const char **name) override
#define LXxO_TableauProxy_FeatureByIndex LXxD_TableauProxy_FeatureByIndex
#define LXxC_TableauProxy_FeatureByIndex(c) LxResult c::tpro_FeatureByIndex([[maybe_unused]] LXtID4 type, [[maybe_unused]] unsigned int index, [[maybe_unused]] const char **name)
#define LXxD_TableauProxy_SetVertex LxResult tpro_SetVertex([[maybe_unused]] ILxUnknownID vdesc) override
#define LXxO_TableauProxy_SetVertex LXxD_TableauProxy_SetVertex
#define LXxC_TableauProxy_SetVertex(c) LxResult c::tpro_SetVertex([[maybe_unused]] ILxUnknownID vdesc)
#define LXxD_TableauProxy_Sample LxResult tpro_Sample([[maybe_unused]] const LXtTableauBox bbox, [[maybe_unused]] ILxUnknownID tableau) override
#define LXxO_TableauProxy_Sample LXxD_TableauProxy_Sample
#define LXxC_TableauProxy_Sample(c) LxResult c::tpro_Sample([[maybe_unused]] const LXtTableauBox bbox, [[maybe_unused]] ILxUnknownID tableau)

template <class T>
class CLxIfc_TableauProxy: public CLxInterface
{
public:
    CLxIfc_TableauProxy()
    {
        vt.Bound = Bound;
        vt.FeatureCount = FeatureCount;
        vt.FeatureByIndex = FeatureByIndex;
        vt.SetVertex = SetVertex;
        vt.Sample = Sample;
        vTable = &vt.iunk;
        iid = &lx::guid_TableauProxy;
    }

    static auto Bound(LXtObjectID wcom,LXtTableauBox bbox) -> LxResult
    {
        LXCWxINST (CLxImpl_TableauProxy, loc);
        try
        {
           return loc->tpro_Bound( bbox);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto FeatureCount(LXtObjectID wcom,LXtID4 type) -> unsigned int
    {
        LXCWxINST (CLxImpl_TableauProxy, loc);
        return loc->tpro_FeatureCount( type);
    }

    static auto FeatureByIndex(LXtObjectID wcom,LXtID4 type,unsigned int index,const char **name) -> LxResult
    {
        LXCWxINST (CLxImpl_TableauProxy, loc);
        try
        {
           return loc->tpro_FeatureByIndex( type, index, name);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SetVertex(LXtObjectID wcom,LXtObjectID vdesc) -> LxResult
    {
        LXCWxINST (CLxImpl_TableauProxy, loc);
        try
        {
           return loc->tpro_SetVertex((ILxUnknownID) vdesc);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Sample(LXtObjectID wcom,const LXtTableauBox bbox,LXtObjectID tableau) -> LxResult
    {
        LXCWxINST (CLxImpl_TableauProxy, loc);
        try
        {
           return loc->tpro_Sample( bbox,(ILxUnknownID) tableau);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxTableauProxy vt;
};

class CLxLoc_TableauProxy : public CLxLocalize<ILxTableauProxyID>
{
public:
    CLxLoc_TableauProxy()
    {
        _init();
    }

    CLxLoc_TableauProxy(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_TableauProxy(CLxLoc_TableauProxy const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_TableauProxy;
    }

    auto Bound(LXtTableauBox bbox) -> LxResult
    {
        return m_loc[0]->Bound(m_loc, bbox);
    }

    auto FeatureCount(LXtID4 type) -> unsigned int
    {
        return m_loc[0]->FeatureCount(m_loc, type);
    }

    auto FeatureByIndex(LXtID4 type, unsigned int index, const char **name) -> LxResult
    {
        return m_loc[0]->FeatureByIndex(m_loc, type, index, name);
    }

    auto SetVertex(ILxUnknownID vdesc) -> LxResult
    {
        return m_loc[0]->SetVertex(m_loc,(ILxUnknownID) vdesc);
    }

    auto Sample(const LXtTableauBox bbox, ILxUnknownID tableau) -> LxResult
    {
        return m_loc[0]->Sample(m_loc, bbox,(ILxUnknownID) tableau);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_TableauInstance
{
public:
    virtual ~CLxImpl_TableauInstance() = default;

    virtual auto tins_Properties([[maybe_unused]] ILxUnknownID vecstack) -> LxResult
    {
        return LXe_OK;
    }

    virtual auto tins_GetTransform([[maybe_unused]] unsigned endPoint, [[maybe_unused]] LXtVector offset, [[maybe_unused]] LXtMatrix xfrm) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto tins_GetDissolve([[maybe_unused]] double *dissolve) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto tins_ParticleDescription([[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto tins_ParticleArray([[maybe_unused]] float *vector) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_TableauInstance_Properties LxResult tins_Properties([[maybe_unused]] ILxUnknownID vecstack) override
#define LXxO_TableauInstance_Properties LXxD_TableauInstance_Properties
#define LXxC_TableauInstance_Properties(c) LxResult c::tins_Properties([[maybe_unused]] ILxUnknownID vecstack)
#define LXxD_TableauInstance_GetTransform LxResult tins_GetTransform([[maybe_unused]] unsigned endPoint, [[maybe_unused]] LXtVector offset, [[maybe_unused]] LXtMatrix xfrm) override
#define LXxO_TableauInstance_GetTransform LXxD_TableauInstance_GetTransform
#define LXxC_TableauInstance_GetTransform(c) LxResult c::tins_GetTransform([[maybe_unused]] unsigned endPoint, [[maybe_unused]] LXtVector offset, [[maybe_unused]] LXtMatrix xfrm)
#define LXxD_TableauInstance_GetDissolve LxResult tins_GetDissolve([[maybe_unused]] double *dissolve) override
#define LXxO_TableauInstance_GetDissolve LXxD_TableauInstance_GetDissolve
#define LXxC_TableauInstance_GetDissolve(c) LxResult c::tins_GetDissolve([[maybe_unused]] double *dissolve)
#define LXxD_TableauInstance_ParticleDescription LxResult tins_ParticleDescription([[maybe_unused]] void **ppvObj) override
#define LXxO_TableauInstance_ParticleDescription LXxD_TableauInstance_ParticleDescription
#define LXxC_TableauInstance_ParticleDescription(c) LxResult c::tins_ParticleDescription([[maybe_unused]] void **ppvObj)
#define LXxD_TableauInstance_ParticleArray LxResult tins_ParticleArray([[maybe_unused]] float *vector) override
#define LXxO_TableauInstance_ParticleArray LXxD_TableauInstance_ParticleArray
#define LXxC_TableauInstance_ParticleArray(c) LxResult c::tins_ParticleArray([[maybe_unused]] float *vector)

template <class T>
class CLxIfc_TableauInstance: public CLxInterface
{
public:
    CLxIfc_TableauInstance()
    {
        vt.Properties = Properties;
        vt.GetTransform = GetTransform;
        vt.GetDissolve = GetDissolve;
        vt.ParticleDescription = ParticleDescription;
        vt.ParticleArray = ParticleArray;
        vTable = &vt.iunk;
        iid = &lx::guid_TableauInstance;
    }

    static auto Properties(LXtObjectID wcom,LXtObjectID vecstack) -> LxResult
    {
        LXCWxINST (CLxImpl_TableauInstance, loc);
        try
        {
           return loc->tins_Properties((ILxUnknownID) vecstack);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto GetTransform(LXtObjectID wcom,unsigned endPoint,LXtVector offset,LXtMatrix xfrm) -> LxResult
    {
        LXCWxINST (CLxImpl_TableauInstance, loc);
        try
        {
           return loc->tins_GetTransform( endPoint, offset, xfrm);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto GetDissolve(LXtObjectID wcom,double *dissolve) -> LxResult
    {
        LXCWxINST (CLxImpl_TableauInstance, loc);
        try
        {
           return loc->tins_GetDissolve( dissolve);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ParticleDescription(LXtObjectID wcom,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_TableauInstance, loc);
        try
        {
           return loc->tins_ParticleDescription( ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ParticleArray(LXtObjectID wcom,float *vector) -> LxResult
    {
        LXCWxINST (CLxImpl_TableauInstance, loc);
        try
        {
           return loc->tins_ParticleArray( vector);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxTableauInstance vt;
};

class CLxLoc_TableauInstance : public CLxLocalize<ILxTableauInstanceID>
{
public:
    CLxLoc_TableauInstance()
    {
        _init();
    }

    CLxLoc_TableauInstance(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_TableauInstance(CLxLoc_TableauInstance const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_TableauInstance;
    }

    auto Properties(ILxUnknownID vecstack) -> LxResult
    {
        return m_loc[0]->Properties(m_loc,(ILxUnknownID) vecstack);
    }

    auto GetTransform(unsigned endPoint, LXtVector offset, LXtMatrix xfrm) -> LxResult
    {
        return m_loc[0]->GetTransform(m_loc, endPoint, offset, xfrm);
    }

    auto GetDissolve(double *dissolve) -> LxResult
    {
        return m_loc[0]->GetDissolve(m_loc, dissolve);
    }

    auto ParticleDescription(void **ppvObj) -> LxResult
    {
        return m_loc[0]->ParticleDescription(m_loc, ppvObj);
    }

    auto ParticleDescription(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->ParticleDescription(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto ParticleArray(float *vector) -> LxResult
    {
        return m_loc[0]->ParticleArray(m_loc, vector);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_TableauShader
{
public:
    virtual ~CLxImpl_TableauShader() = default;

    virtual auto tsha_Select([[maybe_unused]] ILxUnknownID teElt, [[maybe_unused]] ILxUnknownID tvDesc) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto tsha_Slice([[maybe_unused]] ILxUnknownID vtOutput, [[maybe_unused]] ILxUnknownID tvDesc, [[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_TableauShader_Select LxResult tsha_Select([[maybe_unused]] ILxUnknownID teElt, [[maybe_unused]] ILxUnknownID tvDesc) override
#define LXxO_TableauShader_Select LXxD_TableauShader_Select
#define LXxC_TableauShader_Select(c) LxResult c::tsha_Select([[maybe_unused]] ILxUnknownID teElt, [[maybe_unused]] ILxUnknownID tvDesc)
#define LXxD_TableauShader_Slice LxResult tsha_Slice([[maybe_unused]] ILxUnknownID vtOutput, [[maybe_unused]] ILxUnknownID tvDesc, [[maybe_unused]] void **ppvObj) override
#define LXxO_TableauShader_Slice LXxD_TableauShader_Slice
#define LXxC_TableauShader_Slice(c) LxResult c::tsha_Slice([[maybe_unused]] ILxUnknownID vtOutput, [[maybe_unused]] ILxUnknownID tvDesc, [[maybe_unused]] void **ppvObj)

template <class T>
class CLxIfc_TableauShader: public CLxInterface
{
public:
    CLxIfc_TableauShader()
    {
        vt.Select = Select;
        vt.Slice = Slice;
        vTable = &vt.iunk;
        iid = &lx::guid_TableauShader;
    }

    static auto Select(LXtObjectID wcom,LXtObjectID teElt,LXtObjectID tvDesc) -> LxResult
    {
        LXCWxINST (CLxImpl_TableauShader, loc);
        try
        {
           return loc->tsha_Select((ILxUnknownID) teElt,(ILxUnknownID) tvDesc);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Slice(LXtObjectID wcom,LXtObjectID vtOutput,LXtObjectID tvDesc,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_TableauShader, loc);
        try
        {
           return loc->tsha_Slice((ILxUnknownID) vtOutput,(ILxUnknownID) tvDesc, ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxTableauShader vt;
};

class CLxLoc_TableauShader : public CLxLocalize<ILxTableauShaderID>
{
public:
    CLxLoc_TableauShader()
    {
        _init();
    }

    CLxLoc_TableauShader(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_TableauShader(CLxLoc_TableauShader const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_TableauShader;
    }

    auto Select(ILxUnknownID teElt, ILxUnknownID tvDesc) -> LxResult
    {
        return m_loc[0]->Select(m_loc,(ILxUnknownID) teElt,(ILxUnknownID) tvDesc);
    }

    auto Slice(ILxUnknownID vtOutput, ILxUnknownID tvDesc, void **ppvObj) -> LxResult
    {
        return m_loc[0]->Slice(m_loc,(ILxUnknownID) vtOutput,(ILxUnknownID) tvDesc, ppvObj);
    }

    auto Slice(ILxUnknownID vtOutput, ILxUnknownID tvDesc, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Slice(m_loc,(ILxUnknownID) vtOutput,(ILxUnknownID) tvDesc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_ShaderSlice : public CLxLocalize<ILxShaderSliceID>
{
public:
    CLxLoc_ShaderSlice()
    {
        _init();
    }

    CLxLoc_ShaderSlice(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_ShaderSlice(CLxLoc_ShaderSlice const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_ShaderSlice;
    }

    auto Evaluate(ILxUnknownID vecstack) -> LxResult
    {
        return m_loc[0]->Evaluate(m_loc,(ILxUnknownID) vecstack);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};

class CLxImpl_TableauSource
{
public:
    virtual ~CLxImpl_TableauSource() = default;

    virtual auto tsrc_Elements([[maybe_unused]] ILxUnknownID tableau) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto tsrc_Preview([[maybe_unused]] ILxUnknownID tableau) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto tsrc_Instance([[maybe_unused]] ILxUnknownID tableau, [[maybe_unused]] ILxUnknownID instance) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto tsrc_SubShader([[maybe_unused]] ILxUnknownID tableau, [[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto tsrc_PreviewUpdate([[maybe_unused]] int chanIndex, [[maybe_unused]] int *update) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto tsrc_GetCurves([[maybe_unused]] ILxUnknownID tableau, [[maybe_unused]] ILxUnknownID tags, [[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto tsrc_ElementType([[maybe_unused]] int type, [[maybe_unused]] int *supported) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_TableauSource_Elements LxResult tsrc_Elements([[maybe_unused]] ILxUnknownID tableau) override
#define LXxO_TableauSource_Elements LXxD_TableauSource_Elements
#define LXxC_TableauSource_Elements(c) LxResult c::tsrc_Elements([[maybe_unused]] ILxUnknownID tableau)
#define LXxD_TableauSource_Preview LxResult tsrc_Preview([[maybe_unused]] ILxUnknownID tableau) override
#define LXxO_TableauSource_Preview LXxD_TableauSource_Preview
#define LXxC_TableauSource_Preview(c) LxResult c::tsrc_Preview([[maybe_unused]] ILxUnknownID tableau)
#define LXxD_TableauSource_Instance LxResult tsrc_Instance([[maybe_unused]] ILxUnknownID tableau, [[maybe_unused]] ILxUnknownID instance) override
#define LXxO_TableauSource_Instance LXxD_TableauSource_Instance
#define LXxC_TableauSource_Instance(c) LxResult c::tsrc_Instance([[maybe_unused]] ILxUnknownID tableau, [[maybe_unused]] ILxUnknownID instance)
#define LXxD_TableauSource_SubShader LxResult tsrc_SubShader([[maybe_unused]] ILxUnknownID tableau, [[maybe_unused]] void **ppvObj) override
#define LXxO_TableauSource_SubShader LXxD_TableauSource_SubShader
#define LXxC_TableauSource_SubShader(c) LxResult c::tsrc_SubShader([[maybe_unused]] ILxUnknownID tableau, [[maybe_unused]] void **ppvObj)
#define LXxD_TableauSource_PreviewUpdate LxResult tsrc_PreviewUpdate([[maybe_unused]] int chanIndex, [[maybe_unused]] int *update) override
#define LXxO_TableauSource_PreviewUpdate LXxD_TableauSource_PreviewUpdate
#define LXxC_TableauSource_PreviewUpdate(c) LxResult c::tsrc_PreviewUpdate([[maybe_unused]] int chanIndex, [[maybe_unused]] int *update)
#define LXxD_TableauSource_GetCurves LxResult tsrc_GetCurves([[maybe_unused]] ILxUnknownID tableau, [[maybe_unused]] ILxUnknownID tags, [[maybe_unused]] void **ppvObj) override
#define LXxO_TableauSource_GetCurves LXxD_TableauSource_GetCurves
#define LXxC_TableauSource_GetCurves(c) LxResult c::tsrc_GetCurves([[maybe_unused]] ILxUnknownID tableau, [[maybe_unused]] ILxUnknownID tags, [[maybe_unused]] void **ppvObj)
#define LXxD_TableauSource_ElementType LxResult tsrc_ElementType([[maybe_unused]] int type, [[maybe_unused]] int *supported) override
#define LXxO_TableauSource_ElementType LXxD_TableauSource_ElementType
#define LXxC_TableauSource_ElementType(c) LxResult c::tsrc_ElementType([[maybe_unused]] int type, [[maybe_unused]] int *supported)

template <class T>
class CLxIfc_TableauSource: public CLxInterface
{
public:
    CLxIfc_TableauSource()
    {
        vt.Elements = Elements;
        vt.Preview = Preview;
        vt.Instance = Instance;
        vt.SubShader = SubShader;
        vt.PreviewUpdate = PreviewUpdate;
        vt.GetCurves = GetCurves;
        vt.ElementType = ElementType;
        vTable = &vt.iunk;
        iid = &lx::guid_TableauSource;
    }

    static auto Elements(LXtObjectID wcom,LXtObjectID tableau) -> LxResult
    {
        LXCWxINST (CLxImpl_TableauSource, loc);
        try
        {
           return loc->tsrc_Elements((ILxUnknownID) tableau);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Preview(LXtObjectID wcom,LXtObjectID tableau) -> LxResult
    {
        LXCWxINST (CLxImpl_TableauSource, loc);
        try
        {
           return loc->tsrc_Preview((ILxUnknownID) tableau);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Instance(LXtObjectID wcom,LXtObjectID tableau,LXtObjectID instance) -> LxResult
    {
        LXCWxINST (CLxImpl_TableauSource, loc);
        try
        {
           return loc->tsrc_Instance((ILxUnknownID) tableau,(ILxUnknownID) instance);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SubShader(LXtObjectID wcom,LXtObjectID tableau,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_TableauSource, loc);
        try
        {
           return loc->tsrc_SubShader((ILxUnknownID) tableau, ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto PreviewUpdate(LXtObjectID wcom,int chanIndex,int *update) -> LxResult
    {
        LXCWxINST (CLxImpl_TableauSource, loc);
        try
        {
           return loc->tsrc_PreviewUpdate( chanIndex, update);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto GetCurves(LXtObjectID wcom,LXtObjectID tableau,LXtObjectID tags,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_TableauSource, loc);
        try
        {
           return loc->tsrc_GetCurves((ILxUnknownID) tableau,(ILxUnknownID) tags, ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ElementType(LXtObjectID wcom,int type,int *supported) -> LxResult
    {
        LXCWxINST (CLxImpl_TableauSource, loc);
        try
        {
           return loc->tsrc_ElementType( type, supported);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxTableauSource vt;
};

class CLxLoc_TableauSource : public CLxLocalize<ILxTableauSourceID>
{
public:
    CLxLoc_TableauSource()
    {
        _init();
    }

    CLxLoc_TableauSource(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_TableauSource(CLxLoc_TableauSource const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_TableauSource;
    }

    auto Elements(ILxUnknownID tableau) -> LxResult
    {
        return m_loc[0]->Elements(m_loc,(ILxUnknownID) tableau);
    }

    auto Preview(ILxUnknownID tableau) -> LxResult
    {
        return m_loc[0]->Preview(m_loc,(ILxUnknownID) tableau);
    }

    auto Instance(ILxUnknownID tableau, ILxUnknownID instance) -> LxResult
    {
        return m_loc[0]->Instance(m_loc,(ILxUnknownID) tableau,(ILxUnknownID) instance);
    }

    auto SubShader(ILxUnknownID tableau, void **ppvObj) -> LxResult
    {
        return m_loc[0]->SubShader(m_loc,(ILxUnknownID) tableau, ppvObj);
    }

    auto SubShader(ILxUnknownID tableau, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->SubShader(m_loc,(ILxUnknownID) tableau, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto PreviewUpdate(int chanIndex, int *update) -> LxResult
    {
        return m_loc[0]->PreviewUpdate(m_loc, chanIndex, update);
    }

    auto GetCurves(ILxUnknownID tableau, ILxUnknownID tags, void **ppvObj) -> LxResult
    {
        return m_loc[0]->GetCurves(m_loc,(ILxUnknownID) tableau,(ILxUnknownID) tags, ppvObj);
    }

    auto GetCurves(ILxUnknownID tableau, ILxUnknownID tags, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->GetCurves(m_loc,(ILxUnknownID) tableau,(ILxUnknownID) tags, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto ElementType(int type, int *supported) -> LxResult
    {
        return m_loc[0]->ElementType(m_loc, type, supported);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_Instanceable
{
public:
    virtual ~CLxImpl_Instanceable() = default;

    virtual int instable_Compare(ILxUnknownID other) = 0;

    virtual auto instable_AddElements([[maybe_unused]] ILxUnknownID tableau, [[maybe_unused]] ILxUnknownID instT0, [[maybe_unused]] ILxUnknownID instT1) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto instable_GetSurface([[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_Instanceable_Compare int instable_Compare([[maybe_unused]] ILxUnknownID other) override
#define LXxO_Instanceable_Compare LXxD_Instanceable_Compare
#define LXxC_Instanceable_Compare(c) int c::instable_Compare([[maybe_unused]] ILxUnknownID other)
#define LXxD_Instanceable_AddElements LxResult instable_AddElements([[maybe_unused]] ILxUnknownID tableau, [[maybe_unused]] ILxUnknownID instT0, [[maybe_unused]] ILxUnknownID instT1) override
#define LXxO_Instanceable_AddElements LXxD_Instanceable_AddElements
#define LXxC_Instanceable_AddElements(c) LxResult c::instable_AddElements([[maybe_unused]] ILxUnknownID tableau, [[maybe_unused]] ILxUnknownID instT0, [[maybe_unused]] ILxUnknownID instT1)
#define LXxD_Instanceable_GetSurface LxResult instable_GetSurface([[maybe_unused]] void **ppvObj) override
#define LXxO_Instanceable_GetSurface LXxD_Instanceable_GetSurface
#define LXxC_Instanceable_GetSurface(c) LxResult c::instable_GetSurface([[maybe_unused]] void **ppvObj)

template <class T>
class CLxIfc_Instanceable: public CLxInterface
{
public:
    CLxIfc_Instanceable()
    {
        vt.Compare = Compare;
        vt.AddElements = AddElements;
        vt.GetSurface = GetSurface;
        vTable = &vt.iunk;
        iid = &lx::guid_Instanceable;
    }

    static auto Compare(LXtObjectID wcom,LXtObjectID other) -> int
    {
        LXCWxINST (CLxImpl_Instanceable, loc);
        return loc->instable_Compare((ILxUnknownID) other);
    }

    static auto AddElements(LXtObjectID wcom,LXtObjectID tableau,LXtObjectID instT0,LXtObjectID instT1) -> LxResult
    {
        LXCWxINST (CLxImpl_Instanceable, loc);
        try
        {
           return loc->instable_AddElements((ILxUnknownID) tableau,(ILxUnknownID) instT0,(ILxUnknownID) instT1);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto GetSurface(LXtObjectID wcom,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_Instanceable, loc);
        try
        {
           return loc->instable_GetSurface( ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxInstanceable vt;
};

class CLxLoc_Instanceable : public CLxLocalize<ILxInstanceableID>
{
public:
    CLxLoc_Instanceable()
    {
        _init();
    }

    CLxLoc_Instanceable(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_Instanceable(CLxLoc_Instanceable const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_Instanceable;
    }

    auto Compare(ILxUnknownID other) -> int
    {
        return m_loc[0]->Compare(m_loc,(ILxUnknownID) other);
    }

    auto AddElements(ILxUnknownID tableau, ILxUnknownID instT0, ILxUnknownID instT1) -> LxResult
    {
        return m_loc[0]->AddElements(m_loc,(ILxUnknownID) tableau,(ILxUnknownID) instT0,(ILxUnknownID) instT1);
    }

    auto GetSurface(void **ppvObj) -> LxResult
    {
        return m_loc[0]->GetSurface(m_loc, ppvObj);
    }

    auto GetSurface(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->GetSurface(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_TableauService : public CLxLocalizedService
{
public:
    ILxTableauServiceID m_loc{ nullptr };

public:
    CLxLoc_TableauService()
    {
        _init();
        set();
    }

    ~CLxLoc_TableauService() = default;

    void set()
    {
        if (!m_loc)
        {
            m_loc = reinterpret_cast<ILxTableauServiceID>(lx::GetGlobal(&lx::guid_TableauService));
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

    auto AllocVertex(void **ppvObj) -> LxResult
    {
        return m_loc[0]->AllocVertex(m_loc, ppvObj);
    }

    auto AllocVertex(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->AllocVertex(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto VertexFromFeatures(ILxUnknownID surfObj, ILxUnknownID vertex) -> LxResult
    {
        return m_loc[0]->VertexFromFeatures(m_loc,(ILxUnknownID) surfObj,(ILxUnknownID) vertex);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_NodalService : public CLxLocalizedService
{
public:
    ILxNodalServiceID m_loc{ nullptr };

public:
    CLxLoc_NodalService()
    {
        _init();
        set();
    }

    ~CLxLoc_NodalService() = default;

    void set()
    {
        if (!m_loc)
        {
            m_loc = reinterpret_cast<ILxNodalServiceID>(lx::GetGlobal(&lx::guid_NodalService));
        }
    }

    auto AddSampleChan(ILxUnknownID eval, ILxUnknownID item, int chanIndex, int *idxArray, int type) -> int
    {
        return m_loc[0]->AddSampleChan(m_loc,(ILxUnknownID) eval,(ILxUnknownID) item, chanIndex, idxArray, type);
    }

    auto AddSampleChanName(ILxUnknownID eval, ILxUnknownID item, const char *chanName, int *idxArray, int type) -> int
    {
        return m_loc[0]->AddSampleChanName(m_loc,(ILxUnknownID) eval,(ILxUnknownID) item, chanName, idxArray, type);
    }

    auto GetFloat(ILxUnknownID etor, int *idxArray, int index, double orig) const -> double
    {
        return m_loc[0]->GetFloat(m_loc,(ILxUnknownID) etor, idxArray, index, orig);
    }

    auto GetInt(ILxUnknownID etor, int *idxArray, int index, int orig) const -> int
    {
        return m_loc[0]->GetInt(m_loc,(ILxUnknownID) etor, idxArray, index, orig);
    }

    auto GetValue(ILxUnknownID etor, int *idxArray, int index, void *orig) const -> void*
    {
        return m_loc[0]->GetValue(m_loc,(ILxUnknownID) etor, idxArray, index, orig);
    }

    auto IsDriven(ILxUnknownID item, int chanIndex) -> int
    {
        return m_loc[0]->IsDriven(m_loc,(ILxUnknownID) item, chanIndex);
    }

    auto IsDrivenName(ILxUnknownID item, const char *chanName) -> int
    {
        return m_loc[0]->IsDrivenName(m_loc,(ILxUnknownID) item, chanName);
    }

    auto AnyDrivenChans(int *chans, int count) -> int
    {
        return m_loc[0]->AnyDrivenChans(m_loc, chans, count);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_TableauListener
{
public:
    virtual ~CLxImpl_TableauListener() = default;

    virtual void tli_ChannelChange([[maybe_unused]] ILxUnknownID tableau, [[maybe_unused]] ILxUnknownID item, [[maybe_unused]] int channel)
    {
    }

    virtual void tli_FlushElements([[maybe_unused]] ILxUnknownID tableau)
    {
    }

    virtual void tli_TableauDestroy([[maybe_unused]] ILxUnknownID tableau)
    {
    }
};

#define LXxD_TableauListener_ChannelChange void tli_ChannelChange([[maybe_unused]] ILxUnknownID tableau, [[maybe_unused]] ILxUnknownID item, [[maybe_unused]] int channel) override
#define LXxO_TableauListener_ChannelChange LXxD_TableauListener_ChannelChange
#define LXxC_TableauListener_ChannelChange(c) void c::tli_ChannelChange([[maybe_unused]] ILxUnknownID tableau, [[maybe_unused]] ILxUnknownID item, [[maybe_unused]] int channel)
#define LXxD_TableauListener_FlushElements void tli_FlushElements([[maybe_unused]] ILxUnknownID tableau) override
#define LXxO_TableauListener_FlushElements LXxD_TableauListener_FlushElements
#define LXxC_TableauListener_FlushElements(c) void c::tli_FlushElements([[maybe_unused]] ILxUnknownID tableau)
#define LXxD_TableauListener_TableauDestroy void tli_TableauDestroy([[maybe_unused]] ILxUnknownID tableau) override
#define LXxO_TableauListener_TableauDestroy LXxD_TableauListener_TableauDestroy
#define LXxC_TableauListener_TableauDestroy(c) void c::tli_TableauDestroy([[maybe_unused]] ILxUnknownID tableau)

template <class T>
class CLxIfc_TableauListener: public CLxInterface
{
public:
    CLxIfc_TableauListener()
    {
        vt.ChannelChange = ChannelChange;
        vt.FlushElements = FlushElements;
        vt.TableauDestroy = TableauDestroy;
        vTable = &vt.iunk;
        iid = &lx::guid_TableauListener;
    }

    static auto ChannelChange(LXtObjectID wcom,LXtObjectID tableau,LXtObjectID item,int channel) -> void
    {
        LXCWxINST (CLxImpl_TableauListener, loc);
        loc->tli_ChannelChange((ILxUnknownID) tableau,(ILxUnknownID) item, channel);
    }

    static auto FlushElements(LXtObjectID wcom,LXtObjectID tableau) -> void
    {
        LXCWxINST (CLxImpl_TableauListener, loc);
        loc->tli_FlushElements((ILxUnknownID) tableau);
    }

    static auto TableauDestroy(LXtObjectID wcom,LXtObjectID tableau) -> void
    {
        LXCWxINST (CLxImpl_TableauListener, loc);
        loc->tli_TableauDestroy((ILxUnknownID) tableau);
    }

private:
    ILxTableauListener vt;
};


class CLxImpl_TableauSource1
{
public:
    virtual ~CLxImpl_TableauSource1() = default;

    virtual auto tsrc_Elements([[maybe_unused]] ILxUnknownID tableau) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto tsrc_Preview([[maybe_unused]] ILxUnknownID tableau) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto tsrc_Instance([[maybe_unused]] ILxUnknownID tableau, [[maybe_unused]] ILxUnknownID instance) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto tsrc_SubShader([[maybe_unused]] ILxUnknownID tableau, [[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto tsrc_PreviewUpdate([[maybe_unused]] int chanIndex, [[maybe_unused]] int *update) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto tsrc_GetCurves([[maybe_unused]] ILxUnknownID tableau, [[maybe_unused]] ILxUnknownID tags, [[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_TableauSource1_Elements LxResult tsrc_Elements([[maybe_unused]] ILxUnknownID tableau) override
#define LXxO_TableauSource1_Elements LXxD_TableauSource1_Elements
#define LXxC_TableauSource1_Elements(c) LxResult c::tsrc_Elements([[maybe_unused]] ILxUnknownID tableau)
#define LXxD_TableauSource1_Preview LxResult tsrc_Preview([[maybe_unused]] ILxUnknownID tableau) override
#define LXxO_TableauSource1_Preview LXxD_TableauSource1_Preview
#define LXxC_TableauSource1_Preview(c) LxResult c::tsrc_Preview([[maybe_unused]] ILxUnknownID tableau)
#define LXxD_TableauSource1_Instance LxResult tsrc_Instance([[maybe_unused]] ILxUnknownID tableau, [[maybe_unused]] ILxUnknownID instance) override
#define LXxO_TableauSource1_Instance LXxD_TableauSource1_Instance
#define LXxC_TableauSource1_Instance(c) LxResult c::tsrc_Instance([[maybe_unused]] ILxUnknownID tableau, [[maybe_unused]] ILxUnknownID instance)
#define LXxD_TableauSource1_SubShader LxResult tsrc_SubShader([[maybe_unused]] ILxUnknownID tableau, [[maybe_unused]] void **ppvObj) override
#define LXxO_TableauSource1_SubShader LXxD_TableauSource1_SubShader
#define LXxC_TableauSource1_SubShader(c) LxResult c::tsrc_SubShader([[maybe_unused]] ILxUnknownID tableau, [[maybe_unused]] void **ppvObj)
#define LXxD_TableauSource1_PreviewUpdate LxResult tsrc_PreviewUpdate([[maybe_unused]] int chanIndex, [[maybe_unused]] int *update) override
#define LXxO_TableauSource1_PreviewUpdate LXxD_TableauSource1_PreviewUpdate
#define LXxC_TableauSource1_PreviewUpdate(c) LxResult c::tsrc_PreviewUpdate([[maybe_unused]] int chanIndex, [[maybe_unused]] int *update)
#define LXxD_TableauSource1_GetCurves LxResult tsrc_GetCurves([[maybe_unused]] ILxUnknownID tableau, [[maybe_unused]] ILxUnknownID tags, [[maybe_unused]] void **ppvObj) override
#define LXxO_TableauSource1_GetCurves LXxD_TableauSource1_GetCurves
#define LXxC_TableauSource1_GetCurves(c) LxResult c::tsrc_GetCurves([[maybe_unused]] ILxUnknownID tableau, [[maybe_unused]] ILxUnknownID tags, [[maybe_unused]] void **ppvObj)

template <class T>
class CLxIfc_TableauSource1: public CLxInterface
{
public:
    CLxIfc_TableauSource1()
    {
        vt.Elements = Elements;
        vt.Preview = Preview;
        vt.Instance = Instance;
        vt.SubShader = SubShader;
        vt.PreviewUpdate = PreviewUpdate;
        vt.GetCurves = GetCurves;
        vTable = &vt.iunk;
        iid = &lx::guid_TableauSource1;
    }

    static auto Elements(LXtObjectID wcom,LXtObjectID tableau) -> LxResult
    {
        LXCWxINST (CLxImpl_TableauSource1, loc);
        try
        {
           return loc->tsrc_Elements((ILxUnknownID) tableau);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Preview(LXtObjectID wcom,LXtObjectID tableau) -> LxResult
    {
        LXCWxINST (CLxImpl_TableauSource1, loc);
        try
        {
           return loc->tsrc_Preview((ILxUnknownID) tableau);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Instance(LXtObjectID wcom,LXtObjectID tableau,LXtObjectID instance) -> LxResult
    {
        LXCWxINST (CLxImpl_TableauSource1, loc);
        try
        {
           return loc->tsrc_Instance((ILxUnknownID) tableau,(ILxUnknownID) instance);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SubShader(LXtObjectID wcom,LXtObjectID tableau,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_TableauSource1, loc);
        try
        {
           return loc->tsrc_SubShader((ILxUnknownID) tableau, ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto PreviewUpdate(LXtObjectID wcom,int chanIndex,int *update) -> LxResult
    {
        LXCWxINST (CLxImpl_TableauSource1, loc);
        try
        {
           return loc->tsrc_PreviewUpdate( chanIndex, update);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto GetCurves(LXtObjectID wcom,LXtObjectID tableau,LXtObjectID tags,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_TableauSource1, loc);
        try
        {
           return loc->tsrc_GetCurves((ILxUnknownID) tableau,(ILxUnknownID) tags, ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxTableauSource1 vt;
};



