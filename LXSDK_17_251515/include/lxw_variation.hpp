//
// C++ wrapper for lxsdk/lxvariation.h.
//
//	Copyright 2023.
//
//
#pragma once

#include <lxvariation.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx
{
    static LXtGUID const guid_Variation = {0x9EEA0765, {0x4008, 0x426C}, {0xA5, 0x50, 0x88, 0xF6, 0xEB, 0x08, 0xB2, 0xE4}};
    static LXtGUID const guid_VariationService = {0x2BD9441B, {0xC671, 0x4F3C}, {0x9B, 0x02, 0x45, 0xE9, 0xD7, 0x50, 0xE8, 0x0B}};
} // namespace lx

class CLxImpl_Variation
{
public:
    virtual ~CLxImpl_Variation() = default;

    virtual auto var_TestItem(ILxUnknownID item, ILxUnknownID chanRead) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto var_Initialize(double *x, double *y, ILxUnknownID item, ILxUnknownID chanRead) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto var_RangeX(double *min, double *max) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto var_RangeY(double *min, double *max) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto var_Thumb(double x, double y, unsigned int size, ILxUnknownID chanRead, void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto var_Do(double x, double y) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_Variation_TestItem LxResult var_TestItem(ILxUnknownID item, ILxUnknownID chanRead)
#define LXxO_Variation_TestItem LXxD_Variation_TestItem override
#define LXxC_Variation_TestItem(c) LxResult c::var_TestItem(ILxUnknownID item, ILxUnknownID chanRead)
#define LXxD_Variation_Initialize LxResult var_Initialize(double *x, double *y, ILxUnknownID item, ILxUnknownID chanRead)
#define LXxO_Variation_Initialize LXxD_Variation_Initialize override
#define LXxC_Variation_Initialize(c) LxResult c::var_Initialize(double *x, double *y, ILxUnknownID item, ILxUnknownID chanRead)
#define LXxD_Variation_RangeX LxResult var_RangeX(double *min, double *max)
#define LXxO_Variation_RangeX LXxD_Variation_RangeX override
#define LXxC_Variation_RangeX(c) LxResult c::var_RangeX(double *min, double *max)
#define LXxD_Variation_RangeY LxResult var_RangeY(double *min, double *max)
#define LXxO_Variation_RangeY LXxD_Variation_RangeY override
#define LXxC_Variation_RangeY(c) LxResult c::var_RangeY(double *min, double *max)
#define LXxD_Variation_Thumb LxResult var_Thumb(double x, double y, unsigned int size, ILxUnknownID chanRead, void **ppvObj)
#define LXxO_Variation_Thumb LXxD_Variation_Thumb override
#define LXxC_Variation_Thumb(c) LxResult c::var_Thumb(double x, double y, unsigned int size, ILxUnknownID chanRead, void **ppvObj)
#define LXxD_Variation_Do LxResult var_Do(double x, double y)
#define LXxO_Variation_Do LXxD_Variation_Do override
#define LXxC_Variation_Do(c) LxResult c::var_Do(double x, double y)

template <class T>
class CLxIfc_Variation: public CLxInterface
{
public:
    CLxIfc_Variation()
    {
        vt.TestItem = TestItem;
        vt.Initialize = Initialize;
        vt.RangeX = RangeX;
        vt.RangeY = RangeY;
        vt.Thumb = Thumb;
        vt.Do = Do;
        vTable = &vt.iunk;
        iid = &lx::guid_Variation;
    }

    static auto TestItem(LXtObjectID wcom,LXtObjectID item,LXtObjectID chanRead) -> LxResult
    {
        LXCWxINST (CLxImpl_Variation, loc);
        try
        {
           return loc->var_TestItem((ILxUnknownID) item,(ILxUnknownID) chanRead);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Initialize(LXtObjectID wcom,double *x,double *y,LXtObjectID item,LXtObjectID chanRead) -> LxResult
    {
        LXCWxINST (CLxImpl_Variation, loc);
        try
        {
           return loc->var_Initialize( x, y,(ILxUnknownID) item,(ILxUnknownID) chanRead);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto RangeX(LXtObjectID wcom,double *min,double *max) -> LxResult
    {
        LXCWxINST (CLxImpl_Variation, loc);
        try
        {
           return loc->var_RangeX( min, max);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto RangeY(LXtObjectID wcom,double *min,double *max) -> LxResult
    {
        LXCWxINST (CLxImpl_Variation, loc);
        try
        {
           return loc->var_RangeY( min, max);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Thumb(LXtObjectID wcom,double x,double y,unsigned int size,LXtObjectID chanRead,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_Variation, loc);
        try
        {
           return loc->var_Thumb( x, y, size,(ILxUnknownID) chanRead, ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Do(LXtObjectID wcom,double x,double y) -> LxResult
    {
        LXCWxINST (CLxImpl_Variation, loc);
        try
        {
           return loc->var_Do( x, y);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxVariation vt;
};

class CLxLoc_Variation : public CLxLocalize<ILxVariationID>
{
public:
    CLxLoc_Variation()
    {
        _init();
    }

    CLxLoc_Variation(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_Variation(CLxLoc_Variation const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const*
    {
        return &lx::guid_Variation;
    }

    auto TestItem(ILxUnknownID item, ILxUnknownID chanRead) -> LxResult
    {
        return m_loc[0]->TestItem(m_loc,(ILxUnknownID) item,(ILxUnknownID) chanRead);
    }

    auto Initialize(double *x, double *y, ILxUnknownID item, ILxUnknownID chanRead) -> LxResult
    {
        return m_loc[0]->Initialize(m_loc, x, y,(ILxUnknownID) item,(ILxUnknownID) chanRead);
    }

    auto RangeX(double *min, double *max) -> LxResult
    {
        return m_loc[0]->RangeX(m_loc, min, max);
    }

    auto RangeY(double *min, double *max) -> LxResult
    {
        return m_loc[0]->RangeY(m_loc, min, max);
    }

    auto Thumb(double x, double y, unsigned int size, ILxUnknownID chanRead, void **ppvObj) -> LxResult
    {
        return m_loc[0]->Thumb(m_loc, x, y, size,(ILxUnknownID) chanRead, ppvObj);
    }

    auto Thumb(double x, double y, unsigned int size, ILxUnknownID chanRead, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Thumb(m_loc, x, y, size,(ILxUnknownID) chanRead, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Do(double x, double y) -> LxResult
    {
        return m_loc[0]->Do(m_loc, x, y);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_VariationService : public CLxLocalizedService
{
public:
    ILxVariationServiceID m_loc{ nullptr };

public:
    CLxLoc_VariationService()
    {
        _init();
        set();
    }

    ~CLxLoc_VariationService() = default;

    void set()
    {
        if (!m_loc)
        {
            m_loc = reinterpret_cast<ILxVariationServiceID>(lx::GetGlobal(&lx::guid_VariationService));
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

    auto InvalidateItem(ILxUnknownID item) -> void
    {
        m_loc[0]->InvalidateItem(m_loc,(ILxUnknownID) item);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
