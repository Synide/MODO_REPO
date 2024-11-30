/*
 * LINEAR.CPP		Linear Falloff for Deformations
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
#include <lxu_matrix.hpp>
#include <lxu_modifier.hpp>
#include <lxu_package.hpp>
#include <string>

namespace Falloff_Linear
{  // disambiguate everything with a namespace

#define SRVNAME_ITEMTYPE "falloff.linear"  // unique within item types
#define SRVNAME_MODIFIER "falloff.linear"  // unique within modifiers

/*
 * ----------------------------------------------------------------
 * Channels
 *
 * The CChannels class both describes the channels for our item in the
 * attribute description object, but also serves as a container for
 * specific channel values. There are also a couple of methods for
 * computing common values from channel values.
 */
#define Cs_RANGESETUP "useSetup"
#define Cs_RANGE      "range"
#define Cs_MODE       "decayMode"
#define Cs_AXIS       "linearAxis"
#define Cs_FLIP       "flip"
#define Cs_MIRROR     "mirror"

#define ESHPi_LINEAR   0
#define ESHPi_EASE_IN  1
#define ESHPi_EASE_OUT 2
#define ESHPi_SMOOTH   3

    static LXtTextValueHint hint_Mode[] = {
        { ESHPi_LINEAR, "linear" }, { ESHPi_EASE_IN, "easeIn" },  { ESHPi_EASE_OUT, "easeOut" },
        { ESHPi_SMOOTH, "smooth" }, { -1, "=linear-decay-type" }, { -1, nullptr },
    };

    class CChannels : public CLxChannels
    {
    public:
        bool   cv_rangeSetup;
        double cv_range;
        int    cv_mode;
        int    cv_axis;
#ifdef HAS_FLIP
        bool cv_flip;
#else
        static const bool cv_flip = false;
#endif
        bool cv_mirror;

        void init_chan(CLxAttributeDesc& desc) override
        {
            CChannels* chan = nullptr;

            desc.add_channel(Cs_RANGESETUP, LXsTYPE_BOOLEAN, false, &chan->cv_rangeSetup, LXfECHAN_READ);

            desc.add_channel(Cs_RANGE, LXsTYPE_DISTANCE, 1.0, &chan->cv_range, LXfECHAN_READ);
            desc.set_min(0.0);

            desc.add_channel(Cs_MODE, LXsTYPE_INTEGER, ESHPi_LINEAR, &chan->cv_mode, LXfECHAN_READ);
            desc.hint(hint_Mode);

            desc.add_channel(Cs_AXIS, LXsTYPE_AXIS, 2, &chan->cv_axis, LXfECHAN_READ);

#ifdef HAS_FLIP
            desc.add_channel(Cs_FLIP, LXsTYPE_BOOLEAN, false, &chan->cv_flip, LXfECHAN_READ);
#endif

            desc.add_channel(Cs_MIRROR, LXsTYPE_BOOLEAN, false, &chan->cv_mirror, LXfECHAN_READ);
        }

        void clamp_ranges()
        {
            cv_axis = LXxCLAMP(cv_axis, 0, 2);
        }
    };

    static CLxMeta_Channels<CChannels> chan_meta;

    /*
     * ----------------------------------------------------------------
     * Falloff
     *
     * A subclass of the Channels object so that it has the state of the falloff,
     * the falloff object is an exported COM object implementing the ILxFalloff
     * methods. It also has a transform and ease that need to be initialized.
     */
    class CFalloff : public CChannels, public CLxFalloff
    {
    public:
        bool            cv_invert;
        CLxEaseFraction m_ease;

        void set_ease()
        {
            if (cv_mode == ESHPi_LINEAR)
                m_ease.set_shape(LXiESHP_LINEAR);
            else if (cv_mode == ESHPi_EASE_IN)
                m_ease.set_shape(LXiESHP_EASE_IN);
            else if (cv_mode == ESHPi_EASE_OUT)
                m_ease.set_shape(LXiESHP_EASE_OUT);
            else if (cv_mode == ESHPi_SMOOTH)
                m_ease.set_shape(LXiESHP_SMOOTH);

            m_ease.flags = (cv_flip ? LXfEASE_NEGATIVE : 0) | (cv_mirror ? LXfEASE_DOUBLE : 0);
        }

        float weight_local(const float* pos, const LXtPointID /*point*/, const LXtPolygonID /*polygon*/) override
        {
            return static_cast<float>(1.0 - m_ease.evaluate(pos[cv_axis] / cv_range));
        }

        void draw(CLxUser_StrokeDraw& stroke, int selFlags, const LXtVector itemColor)
        {
            CLxVector rad, v;
            double    alpha;
            int       ix, iy, iz;

            ix    = (cv_axis + 1) % 3;
            iy    = (cv_axis + 2) % 3;
            iz    = cv_axis;
            alpha = (selFlags & LXiSELECTION_SELECTED) ? 1.0 : 0.5;

            rad.clear();
            rad[iz] = cv_invert ? 0.0 : cv_range;

            v.clear();
            v[iz] = cv_invert ? cv_range : 0.0;
            stroke.BeginW(LXiSTROKE_LINE_STRIP, itemColor, alpha, 2 * alpha);
            v[ix] = cv_range;
            v[iy] = cv_range;
            stroke.Vertex(v, LXiSTROKE_ABSOLUTE);
            v[iy] = -cv_range;
            stroke.Vertex(v, LXiSTROKE_ABSOLUTE);
            v[ix] = -cv_range;
            stroke.Vertex(v, LXiSTROKE_ABSOLUTE);
            v[iy] = cv_range;
            stroke.Vertex(v, LXiSTROKE_ABSOLUTE);
            v[ix] = cv_range;
            stroke.Vertex(v, LXiSTROKE_ABSOLUTE);

            v.clear();
            stroke.BeginW(LXiSTROKE_LINES, itemColor, alpha, 2 * alpha);
            stroke.Vertex(v, LXiSTROKE_ABSOLUTE);
            stroke.Vertex(rad, LXiSTROKE_RELATIVE);
            if (cv_mirror)
            {
                stroke.Vertex(v, LXiSTROKE_ABSOLUTE);
                stroke.Vertex(rad * -1.0, LXiSTROKE_RELATIVE);
            }

            v[cv_axis] = cv_invert ? cv_range : 0;
            stroke.BeginWD(LXiSTROKE_CIRCLES, itemColor, alpha, 1.0, LXiLPAT_DOTSLONG);
            stroke.Vertex(v, LXiSTROKE_ABSOLUTE);
            stroke.Vertex(rad, LXiSTROKE_RELATIVE);

            if (selFlags & LXiSELECTION_SELECTED)
            {
                double w, d, x, pw, px;

                for (int i = 1; i <= 10; i++)
                {
                    d = i / 10.0;
                    x = cv_range * d;
                    if (cv_invert)
                        d = 1.0 - d;

                    w            = 1.0 - m_ease.evaluate(d);
                    rad[cv_axis] = cv_range * w;
                    v[cv_axis]   = x;
                    stroke.Vertex(v, LXiSTROKE_ABSOLUTE);
                    stroke.Vertex(rad, LXiSTROKE_RELATIVE);
                    if (cv_mirror)
                    {
                        v[cv_axis] = -x;
                        stroke.Vertex(v, LXiSTROKE_ABSOLUTE);
                        stroke.Vertex(rad, LXiSTROKE_RELATIVE);
                    }
                }

                v.clear();
                rad.clear();
                pw = cv_invert ? 0 : 1;
                px = 0;
                stroke.Begin(LXiSTROKE_LINES, itemColor, alpha);
                for (int i = 1; i <= 10; i++)
                {
                    d = i / 10.0;
                    x = cv_range * d;
                    if (cv_invert)
                        d = 1.0 - d;

                    w = 1.0 - m_ease.evaluate(d);

                    rad[iy] = 0;
                    rad[ix] = cv_range * pw;
                    rad[iz] = px;
                    v[iy]   = 0;
                    v[ix]   = cv_range * w;
                    v[iz]   = x;
                    stroke.Vertex(v, LXiSTROKE_ABSOLUTE);
                    stroke.Vertex(rad, LXiSTROKE_ABSOLUTE);
                    if (cv_mirror)
                    {
                        v[iz]   = -x;
                        rad[iz] = -px;
                        stroke.Vertex(v, LXiSTROKE_ABSOLUTE);
                        stroke.Vertex(rad, LXiSTROKE_ABSOLUTE);
                    }

                    rad[ix] = -cv_range * pw;
                    rad[iy] = 0;
                    rad[iz] = px;
                    v[ix]   = -cv_range * w;
                    v[iy]   = 0;
                    v[iz]   = x;
                    stroke.Vertex(v, LXiSTROKE_ABSOLUTE);
                    stroke.Vertex(rad, LXiSTROKE_ABSOLUTE);
                    if (cv_mirror)
                    {
                        v[iz]   = -x;
                        rad[iz] = -px;
                        stroke.Vertex(v, LXiSTROKE_ABSOLUTE);
                        stroke.Vertex(rad, LXiSTROKE_ABSOLUTE);
                    }

                    rad[ix] = 0;
                    rad[iy] = cv_range * pw;
                    rad[iz] = px;
                    v[ix]   = 0;
                    v[iy]   = cv_range * w;
                    v[iz]   = x;
                    stroke.Vertex(v, LXiSTROKE_ABSOLUTE);
                    stroke.Vertex(rad, LXiSTROKE_ABSOLUTE);
                    if (cv_mirror)
                    {
                        v[iz]   = -x;
                        rad[iz] = -px;
                        stroke.Vertex(v, LXiSTROKE_ABSOLUTE);
                        stroke.Vertex(rad, LXiSTROKE_ABSOLUTE);
                    }

                    rad[ix] = 0;
                    rad[iy] = -cv_range * pw;
                    rad[iz] = px;
                    v[ix]   = 0;
                    v[iy]   = -cv_range * w;
                    v[iz]   = x;
                    stroke.Vertex(v, LXiSTROKE_ABSOLUTE);
                    stroke.Vertex(rad, LXiSTROKE_ABSOLUTE);
                    if (cv_mirror)
                    {
                        v[iz]   = -x;
                        rad[iz] = -px;
                        stroke.Vertex(v, LXiSTROKE_ABSOLUTE);
                        stroke.Vertex(rad, LXiSTROKE_ABSOLUTE);
                    }

                    pw = w;
                    px = x;
                }
            }
        }
    };

    /*
     * ----------------------------------------------------------------
     * Package (Item Type)
     */
    class CViewItem3D : public CLxViewItem3D
    {
    public:
        void draw(CLxUser_Item& item, CLxUser_ChannelRead& chan, CLxUser_StrokeDraw& stroke, int selFlags, const CLxVector& color) override
        {
            CFalloff fall;

            chan_meta->chan_read(chan, item, (CChannels*) &fall);
            fall.cv_invert = chan.IValue(item, LXsICHAN_FALLOFF_INVERT);

            fall.clamp_ranges();
            fall.set_ease();
            fall.draw(stroke, selFlags, color);
        }
    };

    /*
     * ----------------------------------------------------------------
     * Modifier
     */
    class CModifier : public CLxEvalModifier, public CLxTypeEvaluation<CFalloff>
    {
    public:
        void bind(CLxUser_Item& item, unsigned /*index*/) override
        {
            mod_add_chan(item, LXsICHAN_FALLOFF_INVERT);
            mod_add_chan(item, LXsICHAN_XFRMCORE_WORLDMATRIX);
        }

        void init_obj(CLxEvalModifier& com, CFalloff& fall) override
        {
            CLxMatrix4 xfrm;

            com.mod_read_attr((CChannels*) &fall);
            com.mod_cust_val(0, &fall.cv_invert);

            if (fall.cv_rangeSetup)
                com.mod_eval()->SetAlternateSetup();

            com.mod_cust_val(1, xfrm);

            fall.world_inverse = xfrm.inverse();
            fall.clamp_ranges();
            fall.set_ease();
        }
    };

    /*
     * ----------------------------------------------------------------
     * Metaclasses
     *
     *	+ root
     *	    + channels
     *	    + package
     *	        + view3D
     *	    + modifier
     *	        + type eval
     *	            + falloff
     */
    static CLxMetaRoot root_meta;

    static CLxMeta_Package<CLxPackage>     pkg_meta(SRVNAME_ITEMTYPE);
    static CLxMeta_ViewItem3D<CViewItem3D> v3d_meta;

    static CLxMeta_EvalModifier<CModifier>             mod_meta(SRVNAME_MODIFIER);
    static CLxMeta_TypeEvaluation<CModifier, CFalloff> eval_meta(LXsICHAN_FALLOFF_FALLOFF);
    static CLxMeta_Falloff<CFalloff>                   fall_meta;

    void initialize()
    {
        root_meta.add(&chan_meta);
        root_meta.add(&pkg_meta);
        root_meta.add(&mod_meta);

        pkg_meta.set_supertype(LXsITYPE_FALLOFF);
        pkg_meta.add(&v3d_meta);

        mod_meta.add(&eval_meta);
        eval_meta.add(&fall_meta);
        fall_meta.set_local();
    }

};  // namespace Falloff_Linear
