/*
 * RADIAL.CPP		Radial Falloff for Deformations
 *
 *	Copyright 0000
 */
#include <cmath>
#include <lx_draw.hpp>
#include <lx_filter.hpp>
#include <lx_item.hpp>
#include <lx_locator.hpp>
#include <lx_package.hpp>
#include <lx_plugin.hpp>
#include <lx_value.hpp>
#include <lx_visitor.hpp>
#include <lx_vmodel.hpp>
#include <lxidef.h>
#include <lxu_deform.hpp>
#include <lxu_math.hpp>
#include <lxu_modifier.hpp>
#include <lxu_simd.hpp>
#include <string>

using namespace lxsimd;

namespace Falloff_Radial
{  // disambiguate everything with a namespace

#define SRVNAME_ITEMTYPE "falloff.radial"       // unique within item types
#define SRVNAME_MODIFIER "falloff.radial"       // unique within modifiers
#define SPWNAME_INSTANCE "falloff.radial.inst"  // unique within spawners in this module
#define SPWNAME_FALLOFF  "falloff.radial"       // unique within spawners in this module

    /*
     * Class Declarations
     *
     * These have to come before their implementions because they reference each
     * other. Descriptions are attached to the implementations.
     */
    class CPackage;

    class CInstance : public CLxImpl_PackageInstance, public CLxImpl_ViewItem3D
    {
    public:
        CPackage*    src_pkg;
        CLxUser_Item m_item;

        LxResult pins_Initialize(ILxUnknownID item, ILxUnknownID super) override;
        void     pins_Cleanup(void) override;

        LxResult vitm_Draw(ILxUnknownID itemChanRead, ILxUnknownID viewStrokeDraw, int selectionFlags, const LXtVector itemColor) override;

        void spheroidDraw(CLxUser_ChannelRead chan, CLxUser_StrokeDraw stroke, int selectionFlags, const LXtVector itemColor, bool coreMode);
        void raysDraw(CLxUser_ChannelRead chan, CLxUser_StrokeDraw stroke, int selectionFlags, const LXtVector itemColor, int decayMode);
    };

    class CPackage : public CLxImpl_Package
    {
    public:
        static LXtTagInfoDesc descInfo[];
        CLxSpawner<CInstance> spawn;

        CPackage() : spawn(SPWNAME_INSTANCE)
        {
        }

        LxResult pkg_SetupChannels(ILxUnknownID addChan) override;
        LxResult pkg_TestInterface(const LXtGUID* guid) override;
        LxResult pkg_Attach(void** ppvObj) override;
    };

    /*
     * ----------------------------------------------------------------
     * Package Class
     *
     * Packages implement item types, or simple item extensions. They are
     * like the metatype object for the item type. They define the common
     * set of channels for the item type and spawn new instances.
     */
    LXtTagInfoDesc CPackage::descInfo[] = { { LXsPKG_SUPERTYPE, LXsITYPE_FALLOFF }, { nullptr } };

/*
 * The package has a set of standard channels with default values. These
 * are setup at the start using the AddChannel interface.
 */
#define Cs_RANGESETUP "useSetup"
#define Cs_RADIUS     "radius"
#define Cs_CORE       "core"       // outer radius as abs. distance delta to add on to radius, allowing 0 radius falloffs
#define Cs_MODE       "decayMode"  // type of falloff
#define Cs_EXP        "invPower"

    enum
    {
        RF_DECAY_SMOOTH = 0,
        RF_DECAY_INVPOW,
        // RF_DECAY_INVLIN,
        // RF_DECAY_INVSQ,
        RF_DECAY_GAUSS
    };

#define RF_DECAY_LAST RF_DECAY_GAUSS
    // #define DOUBLE_RAD // include radius channels which are redundant with locator scale, but useful..!?!

    static LXtTextValueHint hint_Mode[] = {
        { RF_DECAY_SMOOTH, "smooth" },
        { RF_DECAY_INVPOW, "power" },
        //{RF_DECAY_INVLIN,	"linear"},
        //{RF_DECAY_INVSQ,		"squared"},
        { RF_DECAY_GAUSS, "gaussian" },
        { -1, "=radial-decay-type" },
        { -1, nullptr },
    };

    LxResult CPackage::pkg_SetupChannels(ILxUnknownID addChan)
    {
        CLxUser_AddChannel ac(addChan);

        ac.NewChannel(Cs_RANGESETUP, LXsTYPE_BOOLEAN);
        ac.SetDefault(0.0, 0);

        ac.NewChannel(Cs_RADIUS, LXsTYPE_DISTANCE);
        ac.SetVector(LXsCHANVEC_XYZ);
        ac.SetDefault(1.0, 0);

        ac.NewChannel(Cs_CORE, LXsTYPE_PERCENT);
        ac.SetDefault(0.0, 0);

        ac.NewChannel(Cs_MODE, LXsTYPE_INTEGER);
        ac.SetDefault(0.0, RF_DECAY_SMOOTH);
        ac.SetHint(hint_Mode);

        ac.NewChannel(Cs_EXP, LXsTYPE_INTEGER);
        ac.SetDefault(0.0, 2);
        return LXe_OK;
    }

    /*
     * TestInterface() is required so that nexus knows what interfaces instance
     * of this package support. Necessary to prevent query loops.
     */
    LxResult CPackage::pkg_TestInterface(const LXtGUID* guid)
    {
        return spawn.TestInterfaceRC(guid);
    }

    /*
     * Attach is called to create a new instance of this item. The returned
     * object implements a specific item of this type in the scene.
     */
    LxResult CPackage::pkg_Attach(void** ppvObj)
    {
        CInstance* inst = spawn.Alloc(ppvObj);

        inst->src_pkg = this;
        return LXe_OK;
    }

    /*
     * The instance is the implementation of the item, and there will be one
     * allocated for each item in the scene. It can respond to a set of
     * events.
     */
    LxResult CInstance::pins_Initialize(ILxUnknownID item, ILxUnknownID /*super*/)
    {
        m_item.set(item);
        return LXe_OK;
    }

    void CInstance::pins_Cleanup(void)
    {
        m_item.clear();
    }

#define SIN45 0.707106781186547  // sine (& cosine!) of 45deg
#define COS30 0.866025403784439
#define COS60 0.5
#define SIN30 COS60
#define SIN60 COS30
#define COS15 0.965925826289068
#define SIN15 0.258819045102521
#define LN2   0.69314718055995  // useful for FWHM calculation

#define LXiLPAT_DOTSXLONG 0x2020
#define LXiLPAT_DATSXLONG 0x7070

    void CInstance::raysDraw(CLxUser_ChannelRead /*chan*/, CLxUser_StrokeDraw stroke, int /*selectionFlags*/, const LXtVector itemColor, int decayMode)
    {
        LXtVector v, p;
        int       ix = 2, iy = 0, axis = 1;
        int       pat = decayMode ? LXiLPAT_DASHLONG : LXiLPAT_DASH;
        float     alf = 0.125, dr[5] = { 0, 0.25, 0.5, 0.75, 1.0 };                                  // could adjust spacing depending on mode
        float     c[8] = { 0, float(SIN45), 1, float(SIN45), 0, -float(SIN45), -1, -float(SIN45) };  // cosines around the circle
        float     s[8] = { 1, float(SIN45), 0, -float(SIN45), -1, -float(SIN45), 0, float(SIN45) };  // sines

        for (int j = 1; j <= 4; j++)
        {
            for (int i = 0; i < 8; i++)
            {  // rounded quarter-circle endcaps, v1 first
                stroke.BeginWD(LXiSTROKE_LINES, itemColor, alf, (5.0 - j), pat);
                v[ix]   = c[i];
                v[iy]   = s[i];
                v[axis] = 0.0;
                LXx_VCPY(p, v);
                stroke.Vert(v);
                LXx_VADDS(v, v, dr[j]);
                stroke.Vert(v);

                p[axis] = -p[axis];
                stroke.Vert(p);
                LXx_VADDS(p, p, dr[j]);
                stroke.Vert(p);

                v[ix]   = c[i] * COS15;
                v[iy]   = s[i] * COS15;
                v[axis] = SIN15;
                LXx_VCPY(p, v);
                stroke.Vert(v);
                LXx_VADDS(v, v, dr[j]);
                stroke.Vert(v);

                p[axis] = -p[axis];
                stroke.Vert(p);
                LXx_VADDS(p, p, dr[j]);
                stroke.Vert(p);

                v[ix]   = c[i] * COS30;
                v[iy]   = s[i] * COS30;
                v[axis] = SIN30;
                LXx_VCPY(p, v);
                stroke.Vert(v);
                LXx_VADDS(v, v, dr[j]);
                stroke.Vert(v);

                p[axis] = -p[axis];
                stroke.Vert(p);
                LXx_VADDS(p, p, dr[j]);
                stroke.Vert(p);

                v[ix]   = c[i] * SIN45;
                v[iy]   = s[i] * SIN45;
                v[axis] = SIN45;
                LXx_VCPY(p, v);
                stroke.Vert(v);
                LXx_VADDS(v, v, dr[j]);
                stroke.Vert(v);

                p[axis] = -p[axis];
                stroke.Vert(p);
                LXx_VADDS(p, p, dr[j]);
                stroke.Vert(p);

                v[ix]   = c[i] * COS60;
                v[iy]   = s[i] * COS60;
                v[axis] = SIN60;
                LXx_VCPY(p, v);
                stroke.Vert(v);
                LXx_VADDS(v, v, dr[j]);
                stroke.Vert(v);

                p[axis] = -p[axis];
                stroke.Vert(p);
                LXx_VADDS(p, p, dr[j]);
                stroke.Vert(p);

                v[ix]   = c[i] * SIN15;
                v[iy]   = s[i] * SIN15;
                v[axis] = COS15;
                LXx_VCPY(p, v);
                stroke.Vert(v);
                LXx_VADDS(v, v, dr[j]);
                stroke.Vert(v);

                p[axis] = -p[axis];
                stroke.Vert(p);
                LXx_VADDS(p, p, dr[j]);
                stroke.Vert(p);

                v[ix]   = 0;
                v[iy]   = 0;
                v[axis] = 1.0;
                LXx_VCPY(p, v);
                stroke.Vert(v);
                LXx_VADDS(v, v, dr[j]);
                stroke.Vert(v);

                p[axis] = -p[axis];
                stroke.Vert(p);
                LXx_VADDS(p, p, dr[j]);
                stroke.Vert(p);
            }
        }
    }

    void CInstance::spheroidDraw(CLxUser_ChannelRead /*chan*/, CLxUser_StrokeDraw stroke, int selectionFlags, const LXtVector itemColor, bool coreMode)
    {
        LXtVector v, r;
        int       ix = 2, iy = 0, axis = 1;

        int   pat = !coreMode ? LXiLPAT_DASH : LXiLPAT_DOTS;
        float alf = 1.0;  // coreMode ? 0.85 : 1.0;

        if (selectionFlags & LXiSELECTION_SELECTED && !coreMode)
            stroke.Begin(LXiSTROKE_CIRCLES, itemColor, 1.0);
        else
            stroke.BeginWD(LXiSTROKE_CIRCLES, itemColor, (selectionFlags & LXiSELECTION_SELECTED) ? 1.0 : 0.60, 1, pat);
        for (int i = 0; i < 3; i++)
        {
            LXx_VCLR(v);
            stroke.Vert(v);
            v[i] = 1;
            stroke.Vert(v);
        }
        stroke.BeginWD(LXiSTROKE_CIRCLES, itemColor, alf, 1, pat);
        LXx_VCLR(v);
        LXx_VCLR(r);

        v[axis] = SIN45;
        r[axis] = SIN45;
        stroke.Vert(v);
        stroke.Vert(r, LXiSTROKE_RELATIVE);
        v[axis] = -SIN45;
        stroke.Vert(v);
        stroke.Vert(r, LXiSTROKE_RELATIVE);

        v[axis] = SIN15;
        r[axis] = COS15;
        stroke.Vert(v);
        stroke.Vert(r, LXiSTROKE_RELATIVE);
        v[axis] = COS30;
        r[axis] = SIN30;
        stroke.Vert(v);
        stroke.Vert(r, LXiSTROKE_RELATIVE);
        v[axis] = COS60;
        r[axis] = SIN60;
        stroke.Vert(v);
        stroke.Vert(r, LXiSTROKE_RELATIVE);

        v[axis] = -SIN15;
        r[axis] = COS15;
        stroke.Vert(v);
        stroke.Vert(r, LXiSTROKE_RELATIVE);
        v[axis] = -COS30;
        r[axis] = SIN30;
        stroke.Vert(v);
        stroke.Vert(r, LXiSTROKE_RELATIVE);
        v[axis] = -COS60;
        r[axis] = SIN60;
        stroke.Vert(v);
        stroke.Vert(r, LXiSTROKE_RELATIVE);

        v[axis] = 0;
        r[axis] = 0;
        r[ix]   = SIN45;
        r[iy]   = SIN45;
        stroke.Vert(v);
        stroke.Vert(r);
        r[iy] = -SIN45;
        stroke.Vert(v);
        stroke.Vert(r);
    }

    LxResult CInstance::vitm_Draw(ILxUnknownID itemChanRead, ILxUnknownID viewStrokeDraw, int selectionFlags, const LXtVector itemColor)
    {
        CLxUser_ChannelRead  chan(itemChanRead);
        CLxUser_StrokeDraw   stroke(viewStrokeDraw);
        LXtVector            rad, v;
        CLxUser_ValueService vS;
        CLxUser_Value        val;
        CLxUser_Matrix       xfrm;
        double               core;
        int                  mode;

        LXx_VCLR(v);
        LXx_VSET(rad, 1.0);
        core = chan.FValue(m_item, Cs_CORE);
        mode = chan.IValue(m_item, Cs_MODE);

        rad[0] = chan.FValue(m_item, Cs_RADIUS ".X");
        rad[1] = chan.FValue(m_item, Cs_RADIUS ".Y");
        rad[2] = chan.FValue(m_item, Cs_RADIUS ".Z");

        vS.NewValue(val, LXsTYPE_MATRIX4);
        xfrm.set(val);
        xfrm.SetIdentity();
        LXtMatrix mat;
        xfrm.Get3(mat);
        mat[0][0] = rad[0];
        mat[1][1] = rad[1];
        mat[2][2] = rad[2];
        stroke.PushTransform(v, mat);
        spheroidDraw(chan, stroke, selectionFlags, itemColor, false);
        stroke.PopTransform();

        if (mode == RF_DECAY_SMOOTH)
        {
            if ((core > 0))
            {
                mat[0][0] = core * rad[0];
                mat[1][1] = core * rad[1];
                mat[2][2] = core * rad[2];
                stroke.PushTransform(v, mat);
                spheroidDraw(chan, stroke, selectionFlags, itemColor, true);
                stroke.PopTransform();
            }
        }
        else
        {
            if ((selectionFlags & LXiSELECTION_SELECTED))
            {
                stroke.PushTransform(v, mat);
                raysDraw(chan, stroke, selectionFlags, itemColor, 0);
                stroke.PopTransform();
            }
        }

        return LXe_OK;
    }

    class CFalloff : public CLxImpl_Falloff
    {
    public:
        CLxUser_Matrix scratch_mat;
        CLxUser_Value  scratch_val;
        LXtMatrix4     w_xfrm;
        LXtMatrix4     inv_w_xfrm;

        LXtVector cen, rad;
        double    core;
        int       mode;
        int       exponent;

        template <class F>
        F Power(F base, int exponent)
        {
            F val = 1;

            for (int i = 0; i < exponent; i++)
                val *= base;
            for (int i = 0; i > exponent; i--)  // handle negative exponent case
                val /= base;

            return val;
        }

        template <class F>
        F CalcWeight1D(F d)
        {
            F w = 0;

            switch (mode)
            {
                case RF_DECAY_SMOOTH:
                    if (d <= core)  // inside hard core, full weight
                        return 1.0;
                    if (d >= 1.0)  // outside radius entirely
                        return 0.0;
                    w = static_cast<F>(1.0 - ((d - core) / (1.0 - core)));
                    w = lx::Smooth(static_cast<F>(LXxCLAMP(w, 0.0, 1.0)));
                    break;
                case RF_DECAY_GAUSS:  // ignore core
                    // gaussian: exp(-k*x^2), FWHM=2*ln(2)/k ==> k = ln(2)/FWHM = ln(2)
                    w = static_cast<F>(exp(-LN2 * d * d * 2));  // half max at R = FWHM/2
                    break;
                case RF_DECAY_INVPOW:
                // case RF_DECAY_INVSQ:
                default:
                    if (d <= core)  // inside hard core, full weight
                        return 1.0;
                    w = static_cast<F>(d - core);
                    w = Power(LXxABS(w), exponent);
                    w = static_cast<F>(w > 0.0 ? 1.0 / (1.0 + w) : 1.0);  // inside radius weight over 1 would be clamped anyway
                    break;
            }
            return w;
        }

        template <class F>
        F GetWeight(const F* pos, const LXtPointID /*point*/, const LXtPolygonID /*polygon*/)
        {
            F         x[3], d;
            LXtVector p, wp;

            scratch_mat.Set4(inv_w_xfrm);  // use inverse world matrix to transform
            LXx_VCPY(wp, pos);             // world position to local coordinates
            scratch_mat.MultiplyVector(wp, p);
            LXx_VCPY(x, p);
            LXx_VDIV(x, rad);

            d = LXx_VLEN(x);

            return CalcWeight1D(d);
        }

        LXxO_Falloff_WeightF
        {
            return GetWeight(position, point, polygon);
        }

        LXxO_Falloff_WeightRun
        {
            VarrayBuffer x;

            VarrayMatrix4Multiply(x, inv_w_xfrm, pos, num);
            VarrayAXYZvecx(x, static_cast<float>(1.0 / rad[0]), static_cast<float>(1.0 / rad[1]), static_cast<float>(1.0 / rad[2]), num);
            FarrayVlenR(weight, x, num);

            if (mode == RF_DECAY_SMOOTH)
            {
                float a;

                if (core < 1.0)
                {
                    a = static_cast<float>(1.0 / (core - 1.0));
                    FarrayABxCp(weight, a, -a, num);
                    FarrayVABclamp(weight, 0.0, 1.0, num);
                    FarrayVsmooth(weight, num);
                }
                else
                {
                    unsigned i;

                    for (i = 0; i < num; i++)
                        weight[i] = weight[i] < 1.f ? 1.f : 0.f;
                }
            }
            else
            {
                unsigned i;

                for (i = 0; i < num; i++)
                    weight[i] = CalcWeight1D(weight[i]);
            }
            return LXe_OK;
        }
    };

    /*
     * The modifier spawns the falloff from the input parameters.
     */
    class CModifier : public CLxObjectRefModifierCore
    {
    public:
        const char* ItemType() override
        {
            return SRVNAME_ITEMTYPE;
        }

        const char* Channel() override
        {
            return LXsICHAN_FALLOFF_FALLOFF;
        }

        void Attach(CLxUser_Evaluation& eval, ILxUnknownID item) override
        {
            eval.AddChan(item, Cs_RADIUS ".X");
            eval.AddChan(item, Cs_RADIUS ".Y");
            eval.AddChan(item, Cs_RADIUS ".Z");

            eval.AddChan(item, Cs_CORE);
            eval.AddChan(item, Cs_MODE);
            eval.AddChan(item, Cs_EXP);
            eval.AddChan(item, Cs_RANGESETUP);
            eval.AddChan(item, LXsICHAN_XFRMCORE_WORLDMATRIX, LXfECHAN_READ | LXfECHAN_SETUP);
        }

        void Alloc(CLxUser_Evaluation& eval, CLxUser_Attributes& attr, unsigned index, ILxUnknownID& obj) override
        {
            CLxSpawner<CFalloff> sp(SPWNAME_FALLOFF);
            CFalloff*            fall;
            CLxUser_Matrix       xfrm;
            CLxUser_ValueService vS;
            fall = sp.Alloc(obj);

            vS.NewValue(fall->scratch_val, LXsTYPE_MATRIX4);
            fall->scratch_mat.set(fall->scratch_val);

            fall->rad[0] = attr.Float(index++);
            fall->rad[1] = attr.Float(index++);
            fall->rad[2] = attr.Float(index++);

            fall->core     = attr.Float(index++);
            fall->core     = LXxCLAMP(fall->core, 0.0, 1.0);
            fall->mode     = attr.Int(index++);
            fall->mode     = LXxCLAMP(fall->mode, RF_DECAY_SMOOTH, RF_DECAY_LAST);
            fall->exponent = attr.Int(index++);
            fall->exponent = LXxMAX(fall->exponent, 1);
            if (attr.Bool(index++))
                eval.SetAlternateSetup();

            attr.ObjectRO(index++, xfrm);
            xfrm.GetOffset(fall->cen);
            xfrm.Get4(fall->w_xfrm);

            fall->scratch_mat.Set4(fall->w_xfrm);  // use mutable matrix for invert!!!
            fall->scratch_mat.Invert();
            fall->scratch_mat.Get4(fall->inv_w_xfrm);
        }

    private:
        // int		 locScaleIdx;
    };

    /*
     * Export package server to define a new item type. Also create and destroy
     * the factories so they can persist while their objects are in use.
     */
    void initialize()
    {
        CLxGenericPolymorph* srv;

        srv = new CLxPolymorph<CPackage>;
        srv->AddInterface(new CLxIfc_Package<CPackage>);
        srv->AddInterface(new CLxIfc_StaticDesc<CPackage>);
        lx::AddServer(SRVNAME_ITEMTYPE, srv);

        srv = new CLxPolymorph<CInstance>;
        srv->AddInterface(new CLxIfc_PackageInstance<CInstance>);
        srv->AddInterface(new CLxIfc_ViewItem3D<CInstance>);
        lx::AddSpawner(SPWNAME_INSTANCE, srv);

        CLxSpawner_Falloff<CFalloff>(SPWNAME_FALLOFF);

        CLxExport_ItemModifierServer<CLxObjectRefModifier<CModifier>>::Define(SRVNAME_MODIFIER);
    }

};  // namespace Falloff_Radial
