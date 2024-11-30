/*
 * olaySafeArea.cpp	Plug-in locator-based graphic overlay
 *
 * Copyright 0000
 */
#include <cmath>
#include <lx_action.hpp>
#include <lx_channelui.hpp>
#include <lx_deform.hpp>
#include <lx_draw.hpp>
#include <lx_filter.hpp>
#include <lx_handles.hpp>
#include <lx_item.hpp>
#include <lx_mesh.hpp>
#include <lx_package.hpp>
#include <lx_plugin.hpp>
#include <lx_value.hpp>
#include <lx_visitor.hpp>
#include <lx_vmodel.hpp>
#include <lxidef.h>
#include <lxu_deform.hpp>
#include <lxu_math.hpp>
#include <lxu_modifier.hpp>
#include <string>

#include "CameraInfo.hxx"

namespace Overlay_SafeArea
{  // disambiguate everything with a namespace

#define SRVNAME_ITEMTYPE "safeAreaOverlay"
#define SRVNAME_MODIFIER "safeAreaOverlay"
#define SPWNAME_INSTANCE "safeAreaOlay.inst"

    /*
     * Class Declarations
     *
     * These have to come before their implementions because they reference each
     * other. Descriptions are attached to the implementations.
     */
    class CPackage;
    class CInstance;

#define PHI          1.6180339887499
#define ONE_OVER_PHI 0.61803398874989
    // logarithmic spiral: a*exp(b*Theta)
#define SPIRAL_a  1.120529
#define SPIRAL_b  0.306349
#define SPIRAL_CX 1.17082   // (2PHI+1)/(PHI+2)
#define SPIRAL_CY 0.276393  // -1/(PHI+2)

    typedef struct
    {
        LXtVector2 pos;  // corner position
        LXtVector2 siz;  // width, height
    } Rect;

    class CInstance : public CLxImpl_PackageInstance, public CLxImpl_ViewItem3D
    {
    public:
        CPackage*    src_pkg;
        LXtItemType  camType;
        LXtItemType  rendType;
        CLxUser_Item m_item;
        CLxUser_Item m_cam;
        LXtVector    camPos;
        LXtMatrix4   camXfrm;
        bool         useSensor;  // use aperture/filmback instead of image res

        LxResult pins_Initialize(ILxUnknownID item, ILxUnknownID super) override;
        void     pins_Cleanup(void) override;

        // ViewItem3D interface.
        LxResult vitm_Draw(ILxUnknownID itemChanRead, ILxUnknownID viewStrokeDraw, int selectionFlags, const LXtVector itemColor) override;

    private:
        void divideRect(const Rect* src, Rect* dst, int side);
        void quarterArc(const LXtVector A, const LXtVector cen, LXtVector* arc, int num, bool ccw);
    };

    class CPackage : public CLxImpl_Package, public CLxImpl_ChannelUI
    {
    public:
        static LXtTagInfoDesc descInfo[];
        CLxSpawner<CInstance> inst_spawn;

        CPackage() : inst_spawn(SPWNAME_INSTANCE), my_type(LXiTYPE_NONE)
        {
        }

        LxResult pkg_SetupChannels(ILxUnknownID addChan) override;
        LxResult pkg_TestInterface(const LXtGUID* guid) override;
        LxResult pkg_Attach(void** ppvObj) override;

        LxResult    cui_Enabled(const char* channelName, ILxUnknownID msg, ILxUnknownID item, ILxUnknownID read) override;
        LxResult    cui_DependencyCount(const char* channelName, unsigned* count) override;
        LxResult    cui_DependencyByIndex(const char* channelName, unsigned index, LXtItemType* depItemType, const char** depChannelName) override;
        LxResult    cui_UIHints(const char* channelName, ILxUnknownID hints) override;
        LXtItemType MyType();

    private:
        LXtItemType my_type;
    };

/*
 * ----------------------------------------------------------------
 * Package Class
 *
 * Packages implement item types, or simple item extensions. They are
 * like the metatype object for the item type. They define the common
 * set of channels for the item type and spawn new instances.
 */
/*
 * The package has a set of standard channels with default values. These
 * are setup at the start using the AddChannel interface.
 */
#define Cs_ACTSAFE_ENABLE  "actionOn"
#define Cs_ACTSAFE_HBORDER "actHBorder"
#define Cs_ACTSAFE_VBORDER "actVBorder"

#define Cs_TITSAFE_ENABLE  "titleOn"
#define Cs_TITSAFE_HBORDER "titHBorder"
#define Cs_TITSAFE_VBORDER "titVBorder"

#define Cs_USE_SENSOR "useFilmBack"
#define Cs_COLOR      "color"
#define Cs_CGUIDE     "compGuide"
#define Cs_STYLE      "style"
#define Cs_ALPHA      "overlayAlpha"
#define Cs_THIRDS     "thirds"
#define Cs_QUAD       "quadrant"
#define Cs_HORIZ      "horizon"
#define Cs_DIAG_L     "diagonalLeft"
#define Cs_DIAG_R     "diagonalRight"
#define Cs_OCCULT     "occult"
#define Cs_CHEV_UP    "chevronUp"
#define Cs_CHEV_DOWN  "chevronDown"

#define Cs_GOLD_CLR "goldColor"
#define Cs_GRID_CLR "gridColor"
#define Cs_SAFE_CLR "safeColor"
#define Cs_LINE_CLR "lineColor"

    enum
    {
        GRIDi_NONE,
        GRIDi_THIRDS,
        GRIDi_HALVES,
        GRIDi_GOLDEN,
        GRIDi_TENTHS,
        GRIDi_SQUARE
    };

    enum
    {
        GDi_NONE,
        GDi_SECTIONS,
        GDi_SPIRAL,
        GDi_BOTH,
    };

    static LXtTextValueHint hint_GridMode[] = {
        { GRIDi_NONE, "off" },      { GRIDi_THIRDS, "thirds" }, { GRIDi_HALVES, "halves" }, { GRIDi_GOLDEN, "golden" },
        { GRIDi_TENTHS, "tenths" }, { GRIDi_SQUARE, "square" }, { -1, "=olay-gridmode" },   { -1, nullptr },
    };

    static LXtTextValueHint hint_PhiMode[] = {
        { GDi_NONE, "off" }, { GDi_SECTIONS, "sections" }, { GDi_SPIRAL, "spiral" }, { GDi_BOTH, "both" }, { -1, "=olay-phimode" }, { -1, nullptr },
    };

    static LXtTextValueHint hint_PhiQuadrant[] = {
        { 0, "first" }, { 1, "second" }, { 2, "third" }, { 3, "fourth" }, { -1, "=olay-phiquad" }, { -1, nullptr },
    };

    LXtTagInfoDesc CPackage::descInfo[] = {
        //	{ LXsPKG_SUPERTYPE,		LXsITYPE_LOCATOR	},
        { nullptr }
    };

    LxResult CPackage::pkg_SetupChannels(ILxUnknownID addChan)
    {
        CLxUser_AddChannel ac(addChan);

        ac.NewChannel(Cs_ACTSAFE_ENABLE, LXsTYPE_BOOLEAN);
        ac.SetDefault(0.0, 1);
        ac.NewChannel(Cs_ACTSAFE_HBORDER, LXsTYPE_PERCENT);  // BORDER WIDTH AS PERCENT
        ac.SetDefault(0.05, 0);
        ac.NewChannel(Cs_ACTSAFE_VBORDER, LXsTYPE_PERCENT);  // BORDER height AS PERCENT
        ac.SetDefault(0.05, 0);

        ac.NewChannel(Cs_TITSAFE_ENABLE, LXsTYPE_BOOLEAN);
        ac.SetDefault(0.0, 1);
        ac.NewChannel(Cs_TITSAFE_HBORDER, LXsTYPE_PERCENT);
        ac.SetDefault(0.1, 0);
        ac.NewChannel(Cs_TITSAFE_VBORDER, LXsTYPE_PERCENT);
        ac.SetDefault(0.1, 0);

        ac.NewChannel(Cs_ALPHA, LXsTYPE_PERCENT);  // radial boost to rotation
        ac.SetDefault(0.50, 0);

        ac.NewChannel(Cs_THIRDS, LXsTYPE_INTEGER);
        ac.SetDefault(0.0, GRIDi_NONE);
        ac.SetHint(hint_GridMode);

        ac.NewChannel(Cs_CGUIDE, LXsTYPE_INTEGER);
        ac.SetDefault(0.0, GDi_NONE);
        ac.SetHint(hint_PhiMode);

        ac.NewChannel(Cs_QUAD, LXsTYPE_INTEGER);
        ac.SetDefault(0.0, 0);
        ac.SetHint(hint_PhiQuadrant);

        ac.NewChannel(Cs_DIAG_L, LXsTYPE_BOOLEAN);
        ac.SetDefault(0.0, 0);

        ac.NewChannel(Cs_DIAG_R, LXsTYPE_BOOLEAN);
        ac.SetDefault(0.0, 0);

        ac.NewChannel(Cs_HORIZ, LXsTYPE_BOOLEAN);
        ac.SetDefault(0.0, 0);

        ac.NewChannel(Cs_CHEV_UP, LXsTYPE_BOOLEAN);
        ac.SetDefault(0.0, 0);

        ac.NewChannel(Cs_CHEV_DOWN, LXsTYPE_BOOLEAN);
        ac.SetDefault(0.0, 0);

        ac.NewChannel(Cs_USE_SENSOR, LXsTYPE_BOOLEAN);
        ac.SetDefault(0.0, 0);

        LXtVector rgb;
        LXx_VSET3(rgb, 1.0, 0.8, 0.2);
        ac.NewChannel(Cs_GOLD_CLR, LXsTYPE_COLOR1);
        ac.SetVector(LXsCHANVEC_RGB);
        ac.SetDefaultVec(rgb);

        LXx_VSET3(rgb, 0.2, 1.0, 1.0);
        ac.NewChannel(Cs_GRID_CLR, LXsTYPE_COLOR1);
        ac.SetVector(LXsCHANVEC_RGB);
        ac.SetDefaultVec(rgb);

        LXx_VSET3(rgb, 0.2, 1.0, 0.4);
        ac.NewChannel(Cs_SAFE_CLR, LXsTYPE_COLOR1);
        ac.SetVector(LXsCHANVEC_RGB);
        ac.SetDefaultVec(rgb);

        LXx_VSET3(rgb, 1.0, 0.2, 0.4);
        ac.NewChannel(Cs_LINE_CLR, LXsTYPE_COLOR1);
        ac.SetVector(LXsCHANVEC_RGB);
        ac.SetDefaultVec(rgb);

        return LXe_OK;
    }

    LXtItemType CPackage::MyType()
    {
        if (my_type != LXiTYPE_NONE)
            return my_type;

        CLxUser_SceneService svc;

        my_type = svc.ItemType(LXsITYPE_CAMERA);
        return my_type;
    }

    static const char* lineDeps[] = { Cs_DIAG_L, Cs_DIAG_R, Cs_CHEV_DOWN, Cs_CHEV_UP, Cs_HORIZ, nullptr };

    LxResult CPackage::cui_Enabled(const char* channelName, ILxUnknownID msg, ILxUnknownID item, ILxUnknownID read)
    {
        if (!strncmp(channelName, Cs_ACTSAFE_HBORDER, strlen(Cs_ACTSAFE_HBORDER)) ||
            !strncmp(channelName, Cs_ACTSAFE_VBORDER, strlen(Cs_ACTSAFE_VBORDER)))
        {
            CLxUser_Item        src(item);
            CLxUser_ChannelRead chan(read);

            if (chan.IValue(src, Cs_ACTSAFE_ENABLE) == 1)
                return LXe_OK;

            CLxUser_Message res(msg);
            if (res.test())
            {
                res.SetCode(LXe_CMD_DISABLED);
                res.SetMsg("common", 99);
                res.SetArg(1, "Turned off.");
            }
            return LXe_CMD_DISABLED;
        }
        else if (!strncmp(channelName, Cs_TITSAFE_HBORDER, strlen(Cs_TITSAFE_HBORDER)) ||
                 !strncmp(channelName, Cs_TITSAFE_VBORDER, strlen(Cs_TITSAFE_VBORDER)))
        {
            CLxUser_Item        src(item);
            CLxUser_ChannelRead chan(read);

            if (chan.IValue(src, Cs_TITSAFE_ENABLE) == 1)
                return LXe_OK;

            CLxUser_Message res(msg);
            if (res.test())
            {
                res.SetCode(LXe_CMD_DISABLED);
                res.SetMsg("common", 99);
                res.SetArg(1, "Turned off.");
            }
            return LXe_CMD_DISABLED;
        }
        else if (!strncmp(channelName, Cs_QUAD, strlen(Cs_QUAD)) || !strncmp(channelName, Cs_GOLD_CLR, strlen(Cs_GOLD_CLR)))
        {
            CLxUser_Item        src(item);
            CLxUser_ChannelRead chan(read);
            int                 mode = chan.IValue(src, Cs_CGUIDE);

            if ((mode != GDi_NONE))
                return LXe_OK;

            CLxUser_Message res(msg);
            if (res.test())
            {
                res.SetCode(LXe_CMD_DISABLED);
                res.SetMsg("common", 99);
                res.SetArg(1, "Quadrant applies to Golden Sections and Spiral.");
            }
            return LXe_CMD_DISABLED;
        }
        else if (!strncmp(channelName, Cs_SAFE_CLR, strlen(Cs_SAFE_CLR)))
        {
            CLxUser_Item        src(item);
            CLxUser_ChannelRead chan(read);

            if (chan.IValue(src, Cs_TITSAFE_ENABLE) == 1)
                return LXe_OK;
            if (chan.IValue(src, Cs_ACTSAFE_ENABLE) == 1)
                return LXe_OK;

            CLxUser_Message res(msg);
            if (res.test())
            {
                res.SetCode(LXe_CMD_DISABLED);
                res.SetMsg("common", 99);
                res.SetArg(1, "Turned off.");
            }
            return LXe_CMD_DISABLED;
        }
        else if (!strncmp(channelName, Cs_GRID_CLR, strlen(Cs_GRID_CLR)))
        {
            CLxUser_Item        src(item);
            CLxUser_ChannelRead chan(read);
            int                 mode = chan.IValue(src, Cs_THIRDS);

            if ((mode != GRIDi_NONE))
                return LXe_OK;

            CLxUser_Message res(msg);
            if (res.test())
            {
                res.SetCode(LXe_CMD_DISABLED);
                res.SetMsg("common", 99);
                res.SetArg(1, "Color applies only to visible grid.");
            }
            return LXe_CMD_DISABLED;
        }
        else if (!strncmp(channelName, Cs_LINE_CLR, strlen(Cs_LINE_CLR)))
        {
            CLxUser_Item        src(item);
            CLxUser_ChannelRead chan(read);
            int                 i = 0;
            while (lineDeps[i])
            {
                if (0 != chan.IValue(src, lineDeps[i++]))
                    return LXe_OK;
            }

            CLxUser_Message res(msg);
            if (res.test())
            {
                res.SetCode(LXe_CMD_DISABLED);
                res.SetMsg("common", 99);
                res.SetArg(1, "Color applies only to visible grid.");
            }
            return LXe_CMD_DISABLED;
        }
        return LXe_OK;
    }

    LxResult CPackage::cui_DependencyCount(const char* channelName, unsigned* count)
    {
        if (strncmp(channelName, Cs_ACTSAFE_HBORDER, strlen(Cs_ACTSAFE_HBORDER)) == 0)
            count[0] = 1;
        else if (strncmp(channelName, Cs_ACTSAFE_VBORDER, strlen(Cs_ACTSAFE_VBORDER)) == 0)
            count[0] = 1;
        else if (strncmp(channelName, Cs_TITSAFE_HBORDER, strlen(Cs_TITSAFE_HBORDER)) == 0)
            count[0] = 1;
        else if (strncmp(channelName, Cs_TITSAFE_VBORDER, strlen(Cs_TITSAFE_VBORDER)) == 0)
            count[0] = 1;
        else if (strncmp(channelName, Cs_QUAD, strlen(Cs_QUAD)) == 0)
            count[0] = 1;
        else if (strncmp(channelName, Cs_GOLD_CLR, strlen(Cs_GOLD_CLR)) == 0)
            count[0] = 1;
        else if (strncmp(channelName, Cs_SAFE_CLR, strlen(Cs_SAFE_CLR)) == 0)
            count[0] = 2;
        else if (strncmp(channelName, Cs_GRID_CLR, strlen(Cs_GRID_CLR)) == 0)
            count[0] = 1;
        else if (strncmp(channelName, Cs_LINE_CLR, strlen(Cs_LINE_CLR)) == 0)
            count[0] = 5;
        else
            count[0] = 0;

        return LXe_OK;
    }

    LxResult CPackage::cui_DependencyByIndex(const char* channelName, unsigned index, LXtItemType* depItemType, const char** depChannelName)
    {
        if (!strncmp(channelName, Cs_ACTSAFE_HBORDER, strlen(Cs_ACTSAFE_HBORDER)) ||
            !strncmp(channelName, Cs_ACTSAFE_VBORDER, strlen(Cs_ACTSAFE_VBORDER)))
        {
            depItemType[0]    = MyType();
            depChannelName[0] = Cs_ACTSAFE_ENABLE;
            return LXe_OK;
        }
        if (!strncmp(channelName, Cs_TITSAFE_HBORDER, strlen(Cs_TITSAFE_HBORDER)) ||
            !strncmp(channelName, Cs_TITSAFE_VBORDER, strlen(Cs_TITSAFE_VBORDER)))
        {
            depItemType[0]    = MyType();
            depChannelName[0] = Cs_ACTSAFE_ENABLE;
            return LXe_OK;
        }

        if (!strncmp(channelName, Cs_QUAD, strlen(Cs_QUAD)) || !strncmp(channelName, Cs_GOLD_CLR, strlen(Cs_GOLD_CLR)))
        {
            depItemType[0]    = MyType();
            depChannelName[0] = Cs_CGUIDE;
            return LXe_OK;
        }
        if (!strncmp(channelName, Cs_SAFE_CLR, strlen(Cs_SAFE_CLR)))
        {
            depItemType[0]    = MyType();
            depChannelName[0] = index ? Cs_TITSAFE_ENABLE : Cs_ACTSAFE_ENABLE;
            return LXe_OK;
        }
        if (!strncmp(channelName, Cs_GRID_CLR, strlen(Cs_GRID_CLR)))
        {
            depItemType[0]    = MyType();
            depChannelName[0] = Cs_THIRDS;
            return LXe_OK;
        }
        if (!strncmp(channelName, Cs_LINE_CLR, strlen(Cs_LINE_CLR)))
        {
            depItemType[0]    = MyType();
            depChannelName[0] = lineDeps[index % 5];
            return LXe_OK;
        }
        return LXe_OUTOFBOUNDS;
    }

    LxResult CPackage::cui_UIHints(const char* /*channelName*/, ILxUnknownID /*hints*/)
    {
        return LXe_NOTIMPL;
    }

    /*
     * TestInterface() is required so that nexus knows what interfaces instance
     * of this package support. Necessary to prevent query loops.
     */
    LxResult CPackage::pkg_TestInterface(const LXtGUID* guid)
    {
        return inst_spawn.TestInterfaceRC(guid);
    }

    /*
     * Attach is called to create a new instance of this item. The returned
     * object implements a specific item of this type in the scene.
     */
    LxResult CPackage::pkg_Attach(void** ppvObj)
    {
        CInstance* inst = inst_spawn.Alloc(ppvObj);

        inst->src_pkg = this;
        return LXe_OK;
    }

    /*
     * ----------------------------------------------------------------
     * Item Instance
     *
     * The instance is the implementation of the item, and there will be one
     * allocated for each item in the scene. It can respond to a set of
     * events.
     */
    LxResult CInstance::pins_Initialize(ILxUnknownID item, ILxUnknownID /*super*/)
    {
        m_item.set(item);

        CLxUser_SceneService svcScene;
        CLxUser_Scene        scene;
        m_item.GetContext(scene);
        camType  = svcScene.ItemType(LXsITYPE_CAMERA);
        rendType = svcScene.ItemType(LXsITYPE_RENDER);

        return LXe_OK;
    }

    void CInstance::pins_Cleanup(void)
    {
        m_item.clear();
    }

    // divide rect by golden ratio with either vertical or horizontal line (for side even or odd), return new rect in 'dst'
    // position of new rect is always diagonally across the square, with size flipped accordingly, so the sequence of positions
    // when dest is fed back in as source for the next side, will trace the logarithmic spiral
    void CInstance::divideRect(const Rect* src, Rect* dst, int side)
    {
        int vrt, horizontal = side & 1;  // start horizontally at side==0, even
        *dst = *src;
        vrt  = !horizontal;

        dst->siz[horizontal] *= 1.0 - ONE_OVER_PHI;

        dst->pos[horizontal] += src->siz[horizontal] - dst->siz[horizontal];
        dst->pos[vrt] += src->siz[vrt];
        dst->siz[vrt] = -dst->siz[vrt];
    }

    void CInstance::quarterArc(const LXtVector A, const LXtVector cen, LXtVector* arc, int num, bool ccw)
    {
        LXtMatrix4 xfrm;
        LXtVector  rad, pos;
        LXx_VSUB3(rad, A, cen);
        LXx_VUNIT(pos, 2);
        if (num > 2)
        {
            double a = ccw ? -LXx_HALFPI / (num - 1) : LXx_HALFPI / (num - 1);
            lx::MatrixAxisRotation(xfrm, pos, sin(a), cos(a));
            LXx_VCPY(pos, rad);
            for (int i = 0; i < num; i++)
            {
                LXx_VCPY(rad, pos);
                LXx_VADD3(arc[i], pos, cen);
                lx::MatrixMultiply(pos, xfrm, rad);
            }
        }
    }

    LxResult CInstance::vitm_Draw(ILxUnknownID itemChanRead, ILxUnknownID viewStrokeDraw, int /*selectionFlags*/, const LXtVector /*itemColor*/)
    {
        CLxUser_View viewMap(viewStrokeDraw);

        if (viewMap.Type() != LXiVIEWv_CAMERA)
            return LXe_OK;

        CLxUser_ChannelRead chan(itemChanRead);
        CLxLoc_StrokeDraw   strokeDraw(viewStrokeDraw);
        LXtVector           pos, quad[4], tRGB, aRGB, uv, gRGB, lRGB;
        double              dx = 1, dy = 1, zoomX = 0, zoomY = 0, alpha, zDepth;
        bool                titOn, actOn, horizOn, diagL, diagR, chevUp, chevDn;
        int                 gridMode, compMode;
        float               actXBord = 0, actYBord = 0, lineWidth;
        float               titXBord = 0, titYBord = 0, offX, offY;
        int                 quadrant = 0, upAxis = 1;
        static int          levels = 10, glClipRatio = 95;

        actOn = 0 != chan.IValue(m_item, Cs_ACTSAFE_ENABLE);
        if (actOn)
        {
            actXBord = static_cast<float>(chan.FValue(m_item, Cs_ACTSAFE_HBORDER));
            actYBord = static_cast<float>(chan.FValue(m_item, Cs_ACTSAFE_VBORDER));
        }
        titOn = 0 != chan.IValue(m_item, Cs_TITSAFE_ENABLE);
        if (titOn)
        {
            titXBord = static_cast<float>(chan.FValue(m_item, Cs_TITSAFE_HBORDER));
            titYBord = static_cast<float>(chan.FValue(m_item, Cs_TITSAFE_VBORDER));
        }
        alpha     = chan.FValue(m_item, Cs_ALPHA);
        lineWidth = static_cast<float>(LXxMAX(alpha, 1.0));  // pump line width if opacity is driven over 100%

        gridMode  = chan.IValue(m_item, Cs_THIRDS);
        compMode  = chan.IValue(m_item, Cs_CGUIDE);
        quadrant  = chan.IValue(m_item, Cs_QUAD) % 4;
        diagL     = 0 != chan.IValue(m_item, Cs_DIAG_L);
        diagR     = 0 != chan.IValue(m_item, Cs_DIAG_R);
        horizOn   = 0 != chan.IValue(m_item, Cs_HORIZ);
        chevUp    = 0 != chan.IValue(m_item, Cs_CHEV_UP);
        chevDn    = 0 != chan.IValue(m_item, Cs_CHEV_DOWN);
        useSensor = 0 != chan.IValue(m_item, Cs_USE_SENSOR);

        aRGB[0] = chan.FValue(m_item, Cs_GOLD_CLR ".R");
        aRGB[1] = chan.FValue(m_item, Cs_GOLD_CLR ".G");
        aRGB[2] = chan.FValue(m_item, Cs_GOLD_CLR ".B");

        gRGB[0] = chan.FValue(m_item, Cs_GRID_CLR ".R");
        gRGB[1] = chan.FValue(m_item, Cs_GRID_CLR ".G");
        gRGB[2] = chan.FValue(m_item, Cs_GRID_CLR ".B");

        tRGB[0] = chan.FValue(m_item, Cs_SAFE_CLR ".R");
        tRGB[1] = chan.FValue(m_item, Cs_SAFE_CLR ".G");
        tRGB[2] = chan.FValue(m_item, Cs_SAFE_CLR ".B");

        lRGB[0] = chan.FValue(m_item, Cs_LINE_CLR ".R");
        lRGB[1] = chan.FValue(m_item, Cs_LINE_CLR ".G");
        lRGB[2] = chan.FValue(m_item, Cs_LINE_CLR ".B");

        LXx_VCLR(pos);

        if (m_item.IsA(camType))
            m_cam = m_item;
        else if (m_item.GetParent(m_cam))
        {
            if (!m_cam.IsA(camType))
                return LXe_OK;
        }

        if (!m_cam.test())
            return LXe_OK;

        CameraInfo ci(m_cam);
        ci.useSensor = useSensor;
        ci.readCameraChannels(chan);
        // GL drawing seems to get FG clipped at distances nearer than the targetDist/100 (#49200)
        pos[2] = LXxMAX(ci.focalLength, ci.targetDist / glClipRatio);
        zDepth = pos[2];

        double aperX = ci.apertureX, aperY = ci.apertureY;
        if (!useSensor)  // fit 'film back' to output image size, which is what we usually expect
            ci.fitAperture(&aperX, &aperY);

        // offset in drawing plane via similar triangles: ds/f = dx/z
        offX = static_cast<float>((ci.offsetX / ci.focalLength) * zDepth);
        offY = static_cast<float>((ci.offsetY / ci.focalLength) * zDepth);

        // F.o.V. half angle: tan(a) =  half-sensor / foc. len = (apX/2) / flen
        // tan(a) also = (w/2) / foc. dist ==> w/2 = fdist * tan(a)
        zoomX = 0.5 / ci.focalLength;  // foc. dist over foc. len
        zoomY = zoomX * aperY;
        zoomX *= aperX;
        if (actOn)
        {
            strokeDraw.BeginWD(LXiSTROKE_LINE_STRIP, tRGB, alpha, lineWidth, LXiLPAT_DASHLONG);
            uv[0] = (1.0 - actXBord);
            uv[1] = (1.0 - actYBord);
            ci.UVToCam3D(uv, zDepth, pos);
            dx = pos[0];
            dy = pos[1];

            LXx_VSET3(quad[0], dx, dy, -zDepth);
            LXx_VSET3(quad[1], dx, -dy, -zDepth);
            LXx_VSET3(quad[2], -dx, -dy, -zDepth);
            LXx_VSET3(quad[3], -dx, dy, -zDepth);

            quad[0][0] += offX;
            quad[0][1] += offY;
            quad[1][0] += offX;
            quad[1][1] += offY;
            quad[2][0] += offX;
            quad[2][1] += offY;
            quad[3][0] += offX;
            quad[3][1] += offY;

            strokeDraw.Vertex(quad[0], LXiSTROKE_ABSOLUTE);
            strokeDraw.Vertex(quad[1], LXiSTROKE_ABSOLUTE);
            strokeDraw.Vertex(quad[2], LXiSTROKE_ABSOLUTE);
            strokeDraw.Vertex(quad[3], LXiSTROKE_ABSOLUTE);
            strokeDraw.Vertex(quad[0], LXiSTROKE_ABSOLUTE);
        }
        if (titOn)
        {
            strokeDraw.BeginWD(LXiSTROKE_LINE_STRIP, tRGB, alpha, lineWidth, LXiLPAT_DASHLONG);
            uv[0] = (1.0 - titXBord);
            uv[1] = (1.0 - titYBord);
            ci.UVToCam3D(uv, zDepth, pos);
            dx = pos[0];
            dy = pos[1];

            LXx_VSET3(quad[0], dx, dy, -zDepth);
            LXx_VSET3(quad[1], dx, -dy, -zDepth);
            LXx_VSET3(quad[2], -dx, -dy, -zDepth);
            LXx_VSET3(quad[3], -dx, dy, -zDepth);

            quad[0][0] += offX;
            quad[0][1] += offY;
            quad[1][0] += offX;
            quad[1][1] += offY;
            quad[2][0] += offX;
            quad[2][1] += offY;
            quad[3][0] += offX;
            quad[3][1] += offY;

            strokeDraw.Vertex(quad[0], LXiSTROKE_ABSOLUTE);
            strokeDraw.Vertex(quad[1], LXiSTROKE_ABSOLUTE);
            strokeDraw.Vertex(quad[2], LXiSTROKE_ABSOLUTE);
            strokeDraw.Vertex(quad[3], LXiSTROKE_ABSOLUTE);
            strokeDraw.Vertex(quad[0], LXiSTROKE_ABSOLUTE);
        }

        /*
                CLxUser_Value			 val_ang;
                CLxUser_StringConversionNice	 str_ang;
                CLxUser_ValueService		 valService;

                strokeDraw.Begin (LXiSTROKE_TEXT, itemColor, alpha);

                valService.NewValue (val_ang, LXsTYPE_FLOAT);
                str_ang.set  (val_ang);
                std::string label;
                val_ang.SetFlt (dx);
                str_ang.EncodeStr (label);

                strokeDraw.Text (label.c_str(), LXiTEXT_CENTER);
                strokeDraw.Vertex (quad[3], LXiSTROKE_ABSOLUTE);

                val_ang.SetFlt (dy);
                str_ang.EncodeStr (label);

                strokeDraw.Text (label.c_str(), LXiTEXT_CENTER);
                strokeDraw.Vertex (quad[2], LXiSTROKE_ABSOLUTE);


                val_ang.SetFlt (dx/dy);
                str_ang.EncodeStr (label);

                strokeDraw.Text (label.c_str(), LXiTEXT_CENTER);
                strokeDraw.Vertex (quad[0], LXiSTROKE_ABSOLUTE);
        */

        float      w, h, frac;
        int        ix = 0, iy = 1;
        LXtVector2 zoom, sz;

        if (zoomY > zoomX)
        {
            ix = 1;
            iy = 0;
        }
        zoom[ix] = zoomX;
        zoom[iy] = zoomY;
        sz[ix]   = zDepth * zoom[ix];
        sz[iy]   = zDepth * zoom[iy];
        switch (gridMode)
        {
            case GRIDi_THIRDS:
                frac = 1.0f / 3.0f;
                strokeDraw.BeginWD(LXiSTROKE_LINES, gRGB, alpha, lineWidth, LXiLPAT_DOTS);
                w  = static_cast<float>(pos[2] * zoom[ix]);
                h  = static_cast<float>(pos[2] * zoom[iy]);
                dx = frac * w;
                dy = frac * h;

                LXx_VSET3(quad[0], -w, dy, -pos[2]);
                LXx_VSET3(quad[1], w, dy, -pos[2]);
                quad[0][0] += offX;
                quad[0][1] += offY;
                quad[1][0] += offX;
                quad[1][1] += offY;
                strokeDraw.Vertex(quad[0], LXiSTROKE_ABSOLUTE);
                strokeDraw.Vertex(quad[1], LXiSTROKE_ABSOLUTE);

                LXx_VSET3(quad[0], -w, -dy, -pos[2]);
                LXx_VSET3(quad[1], w, -dy, -pos[2]);
                quad[0][0] += offX;
                quad[0][1] += offY;
                quad[1][0] += offX;
                quad[1][1] += offY;
                strokeDraw.Vertex(quad[0], LXiSTROKE_ABSOLUTE);
                strokeDraw.Vertex(quad[1], LXiSTROKE_ABSOLUTE);

                LXx_VSET3(quad[2], -dx, -h, -pos[2]);
                LXx_VSET3(quad[3], -dx, h, -pos[2]);
                quad[2][0] += offX;
                quad[2][1] += offY;
                quad[3][0] += offX;
                quad[3][1] += offY;
                strokeDraw.Vertex(quad[2], LXiSTROKE_ABSOLUTE);
                strokeDraw.Vertex(quad[3], LXiSTROKE_ABSOLUTE);

                LXx_VSET3(quad[2], dx, -h, -pos[2]);
                LXx_VSET3(quad[3], dx, h, -pos[2]);
                quad[2][0] += offX;
                quad[2][1] += offY;
                quad[3][0] += offX;
                quad[3][1] += offY;
                strokeDraw.Vertex(quad[2], LXiSTROKE_ABSOLUTE);
                strokeDraw.Vertex(quad[3], LXiSTROKE_ABSOLUTE);
                break;
            case GRIDi_GOLDEN:
                frac = float(ONE_OVER_PHI);
                frac = 2 * frac - 1;  // convert to -1 to +1 scale
                strokeDraw.BeginWD(LXiSTROKE_LINES, gRGB, alpha, lineWidth, LXiLPAT_DOTS);
                w  = static_cast<float>(pos[2] * zoom[ix]);
                h  = static_cast<float>(pos[2] * zoom[iy]);
                dx = frac * w;
                dy = frac * h;

                LXx_VSET3(quad[0], -w, dy, -pos[2]);
                LXx_VSET3(quad[1], w, dy, -pos[2]);
                quad[0][0] += offX;
                quad[0][1] += offY;
                quad[1][0] += offX;
                quad[1][1] += offY;
                strokeDraw.Vertex(quad[0], LXiSTROKE_ABSOLUTE);
                strokeDraw.Vertex(quad[1], LXiSTROKE_ABSOLUTE);

                LXx_VSET3(quad[0], -w, -dy, -pos[2]);
                LXx_VSET3(quad[1], w, -dy, -pos[2]);
                quad[0][0] += offX;
                quad[0][1] += offY;
                quad[1][0] += offX;
                quad[1][1] += offY;
                strokeDraw.Vertex(quad[0], LXiSTROKE_ABSOLUTE);
                strokeDraw.Vertex(quad[1], LXiSTROKE_ABSOLUTE);

                LXx_VSET3(quad[2], -dx, -h, -pos[2]);
                LXx_VSET3(quad[3], -dx, h, -pos[2]);
                quad[2][0] += offX;
                quad[2][1] += offY;
                quad[3][0] += offX;
                quad[3][1] += offY;
                strokeDraw.Vertex(quad[2], LXiSTROKE_ABSOLUTE);
                strokeDraw.Vertex(quad[3], LXiSTROKE_ABSOLUTE);

                LXx_VSET3(quad[2], dx, -h, -pos[2]);
                LXx_VSET3(quad[3], dx, h, -pos[2]);
                quad[2][0] += offX;
                quad[2][1] += offY;
                quad[3][0] += offX;
                quad[3][1] += offY;
                strokeDraw.Vertex(quad[2], LXiSTROKE_ABSOLUTE);
                strokeDraw.Vertex(quad[3], LXiSTROKE_ABSOLUTE);

                break;
            case GRIDi_HALVES:
                strokeDraw.BeginWD(LXiSTROKE_LINES, gRGB, alpha, lineWidth, LXiLPAT_DOTS);
                w = static_cast<float>(pos[2] * zoom[ix]);
                h = static_cast<float>(pos[2] * zoom[iy]);

                LXx_VSET3(quad[0], -w, 0.0, -pos[2]);
                LXx_VSET3(quad[1], w, 0.0, -pos[2]);
                quad[0][0] += offX;
                quad[0][1] += offY;
                quad[1][0] += offX;
                quad[1][1] += offY;
                strokeDraw.Vertex(quad[0], LXiSTROKE_ABSOLUTE);
                strokeDraw.Vertex(quad[1], LXiSTROKE_ABSOLUTE);

                LXx_VSET3(quad[2], 0.0, -h, -pos[2]);
                LXx_VSET3(quad[3], 0.0, h, -pos[2]);
                quad[2][0] += offX;
                quad[2][1] += offY;
                quad[3][0] += offX;
                quad[3][1] += offY;
                strokeDraw.Vertex(quad[2], LXiSTROKE_ABSOLUTE);
                strokeDraw.Vertex(quad[3], LXiSTROKE_ABSOLUTE);
                break;
            case GRIDi_TENTHS:
                strokeDraw.BeginWD(LXiSTROKE_LINES, gRGB, alpha, lineWidth, LXiLPAT_DOTS);
                dx    = 0.1;
                uv[0] = 0;
                uv[1] = 0;
                w     = static_cast<float>(zDepth * zoom[ix]);
                h     = static_cast<float>(zDepth * zoom[iy]);
                for (int i = 0; i <= 10; i++)
                {
                    ci.UVToCam3D(uv, zDepth, pos);
                    dx = pos[0];
                    dy = pos[1];

                    LXx_VSET3(quad[0], dx, h, -zDepth);
                    LXx_VSET3(quad[1], dx, -h, -zDepth);
                    LXx_VSET3(quad[2], w, dy, -zDepth);
                    LXx_VSET3(quad[3], -w, dy, -zDepth);

                    quad[0][0] += offX;
                    quad[0][1] += offY;
                    quad[1][0] += offX;
                    quad[1][1] += offY;
                    quad[2][0] += offX;
                    quad[2][1] += offY;
                    quad[3][0] += offX;
                    quad[3][1] += offY;

                    strokeDraw.Vertex(quad[0], LXiSTROKE_ABSOLUTE);
                    strokeDraw.Vertex(quad[1], LXiSTROKE_ABSOLUTE);
                    strokeDraw.Vertex(quad[2], LXiSTROKE_ABSOLUTE);
                    strokeDraw.Vertex(quad[3], LXiSTROKE_ABSOLUTE);
                    uv[0] += 0.1;
                    uv[1] += 0.1;
                }

                break;
            case GRIDi_SQUARE:
                strokeDraw.BeginWD(LXiSTROKE_LINES, gRGB, alpha, lineWidth, LXiLPAT_DOTS);
                uv[0]     = 0;
                uv[1]     = 0;
                w         = static_cast<float>(pos[2] * zoom[ix]);
                h         = static_cast<float>(pos[2] * zoom[iy]);
                float asp = h / w, grid = LXxMIN(w, h) / 8;
                int   n = static_cast<int>(LXxMAX(w, h) / grid);
                grid    = 1.f / n;

                for (int i = 0; i <= n; i++)
                {
                    ci.UVToCam3D(uv, zDepth, pos);
                    dx = pos[0];
                    dy = pos[1];

                    LXx_VSET3(quad[0], dx, h, -zDepth);
                    LXx_VSET3(quad[1], dx, -h, -zDepth);
                    LXx_VSET3(quad[2], w, dy, -zDepth);
                    LXx_VSET3(quad[3], -w, dy, -zDepth);

                    quad[0][0] += offX;
                    quad[0][1] += offY;
                    quad[1][0] += offX;
                    quad[1][1] += offY;
                    quad[2][0] += offX;
                    quad[2][1] += offY;
                    quad[3][0] += offX;
                    quad[3][1] += offY;

                    if (dx <= w)
                    {
                        strokeDraw.Vertex(quad[0], LXiSTROKE_ABSOLUTE);
                        strokeDraw.Vertex(quad[1], LXiSTROKE_ABSOLUTE);
                    }
                    if (dy <= h)
                    {
                        strokeDraw.Vertex(quad[2], LXiSTROKE_ABSOLUTE);
                        strokeDraw.Vertex(quad[3], LXiSTROKE_ABSOLUTE);
                    }
                    uv[0] += grid;
                    uv[1] += grid / asp;
                }

                break;
        }

        w = static_cast<float>(zDepth * zoom[ix]);
        h = static_cast<float>(zDepth * zoom[iy]);

        frac = 2.0f * float(ONE_OVER_PHI) - 1.0f;  // convert to -1 to +1 scale
        dx   = frac * w;
        dy   = frac * h;
        if (diagL)
        {
            strokeDraw.BeginWD(LXiSTROKE_LINES, lRGB, alpha, lineWidth, LXiLPAT_DASH);
            LXx_VSET3(quad[0], w, h, -zDepth);
            LXx_VSET3(quad[1], -w, -h, -zDepth);
            quad[0][0] += offX;
            quad[0][1] += offY;
            quad[1][0] += offX;
            quad[1][1] += offY;
            strokeDraw.Vertex(quad[0], LXiSTROKE_ABSOLUTE);
            strokeDraw.Vertex(quad[1], LXiSTROKE_ABSOLUTE);

            // semi-diagonals / golden triangles

            LXx_VSET3(quad[2], -dx, -h, -pos[2]);
            LXx_VSET3(quad[3], -w, h, -pos[2]);
            quad[2][0] += offX;
            quad[2][1] += offY;
            quad[3][0] += offX;
            quad[3][1] += offY;
            strokeDraw.Vertex(quad[2], LXiSTROKE_ABSOLUTE);
            strokeDraw.Vertex(quad[3], LXiSTROKE_ABSOLUTE);
            LXx_VSET3(quad[2], dx, h, -pos[2]);
            LXx_VSET3(quad[3], w, -h, -pos[2]);
            quad[2][0] += offX;
            quad[2][1] += offY;
            quad[3][0] += offX;
            quad[3][1] += offY;
            strokeDraw.Vertex(quad[2], LXiSTROKE_ABSOLUTE);
            strokeDraw.Vertex(quad[3], LXiSTROKE_ABSOLUTE);
        }
        if (diagR)
        {
            strokeDraw.BeginWD(LXiSTROKE_LINES, lRGB, alpha, lineWidth, LXiLPAT_DASH);
            LXx_VSET3(quad[0], -w, h, -zDepth);
            LXx_VSET3(quad[1], w, -h, -zDepth);
            quad[0][0] += offX;
            quad[0][1] += offY;
            quad[1][0] += offX;
            quad[1][1] += offY;
            strokeDraw.Vertex(quad[0], LXiSTROKE_ABSOLUTE);
            strokeDraw.Vertex(quad[1], LXiSTROKE_ABSOLUTE);

            LXx_VSET3(quad[2], dx, -h, -pos[2]);
            LXx_VSET3(quad[3], w, h, -pos[2]);
            quad[2][0] += offX;
            quad[2][1] += offY;
            quad[3][0] += offX;
            quad[3][1] += offY;
            strokeDraw.Vertex(quad[2], LXiSTROKE_ABSOLUTE);
            strokeDraw.Vertex(quad[3], LXiSTROKE_ABSOLUTE);

            LXx_VSET3(quad[2], -dx, h, -pos[2]);
            LXx_VSET3(quad[3], -w, -h, -pos[2]);
            quad[2][0] += offX;
            quad[2][1] += offY;
            quad[3][0] += offX;
            quad[3][1] += offY;
            strokeDraw.Vertex(quad[2], LXiSTROKE_ABSOLUTE);
            strokeDraw.Vertex(quad[3], LXiSTROKE_ABSOLUTE);
        }
        if (horizOn)
        {  // artificial horizon convert world up axis to screen, draw perpendicular
            LXtVector up;

            LXx_VCPY(up, ci.invXfrm[upAxis]);  // get world up in cam system
            up[2] = 0;
            lx::VectorNormalize(up);
            LXx_V2PERP(uv, up);  // direction perp to up is parallel to horizon
            LXx_V2SCL(uv, w / 12);
            uv[2] = 0;

            strokeDraw.BeginW(LXiSTROKE_LINES, lRGB, alpha, lineWidth);
            LXx_VSET3(quad[0], uv[0] / 2, uv[1] / 2, -zDepth);
            quad[0][0] += offX;
            quad[0][1] += offY;
            strokeDraw.Vertex(quad[0], LXiSTROKE_ABSOLUTE);
            strokeDraw.Vertex(uv, LXiSTROKE_RELATIVE);
            LXx_V2SCL(uv, -1.0);
            LXx_VSET3(quad[0], uv[0] / 2, uv[1] / 2, -zDepth);
            quad[0][0] += offX;
            quad[0][1] += offY;
            strokeDraw.Vertex(quad[0], LXiSTROKE_ABSOLUTE);
            strokeDraw.Vertex(uv, LXiSTROKE_RELATIVE);
        }
        if (chevDn)
        {
            strokeDraw.BeginWD(LXiSTROKE_LINE_STRIP, lRGB, alpha, lineWidth, LXiLPAT_DASH);
            LXx_VSET3(quad[0], -w, h, -zDepth);
            LXx_VSET3(quad[1], 0, -h, -zDepth);
            LXx_VSET3(quad[2], w, h, -zDepth);
            quad[0][0] += offX;
            quad[0][1] += offY;
            quad[1][0] += offX;
            quad[1][1] += offY;
            quad[2][0] += offX;
            quad[2][1] += offY;
            strokeDraw.Vertex(quad[0], LXiSTROKE_ABSOLUTE);
            strokeDraw.Vertex(quad[1], LXiSTROKE_ABSOLUTE);
            strokeDraw.Vertex(quad[2], LXiSTROKE_ABSOLUTE);
        }
        if (chevUp)
        {
            strokeDraw.BeginWD(LXiSTROKE_LINE_STRIP, lRGB, alpha, lineWidth, LXiLPAT_DASH);
            LXx_VSET3(quad[0], -w, -h, -zDepth);
            LXx_VSET3(quad[1], 0, h, -zDepth);
            LXx_VSET3(quad[2], w, -h, -zDepth);
            quad[0][0] += offX;
            quad[0][1] += offY;
            quad[1][0] += offX;
            quad[1][1] += offY;
            quad[2][0] += offX;
            quad[2][1] += offY;
            strokeDraw.Vertex(quad[0], LXiSTROKE_ABSOLUTE);
            strokeDraw.Vertex(quad[1], LXiSTROKE_ABSOLUTE);
            strokeDraw.Vertex(quad[2], LXiSTROKE_ABSOLUTE);
        }

        if (compMode == GDi_NONE)
            return LXe_OK;
        dx     = 0.1;
        uv[0]  = 0;
        uv[1]  = 0;
        sz[ix] = w;
        sz[iy] = h;
        frac   = ix ? h / w : w / h;
        if (frac > PHI)
        {
            if (ix)
                h = static_cast<float>(w * PHI);
            else
                w = static_cast<float>(h * PHI);
        }
        else if (frac < PHI)
        {
            if (ix)
                w = static_cast<float>(h * ONE_OVER_PHI);
            else
                h = static_cast<float>(w * ONE_OVER_PHI);
        }
        sz[ix] = LXxMAX(w, h);  // w;
        sz[iy] = LXxMIN(w, h);  // h;
        Rect src, dst;
        switch (quadrant)
        {
            case 1:
                src.pos[ix] = sz[ix];
                src.pos[iy] = -sz[iy];
                src.siz[ix] = -2 * sz[ix];
                src.siz[iy] = 2 * sz[iy];
                break;
            case 2:
                src.pos[ix] = sz[ix];
                src.pos[iy] = sz[iy];
                src.siz[ix] = -2 * sz[ix];
                src.siz[iy] = -2 * sz[iy];
                break;
            case 3:
                src.pos[ix] = -sz[ix];
                src.pos[iy] = sz[iy];
                src.siz[ix] = 2 * sz[ix];
                src.siz[iy] = -2 * sz[iy];
                break;
            case 0:
            default:
                src.pos[ix] = -sz[ix];
                src.pos[iy] = -sz[iy];
                src.siz[ix] = 2 * sz[ix];
                src.siz[iy] = 2 * sz[iy];
                break;
        }
        LXtVector spiral[16];
        LXtVector centers[16];

        spiral[0][ix] = src.pos[ix];
        spiral[0][iy] = src.pos[iy];
        spiral[0][2]  = -zDepth;
        // compute successive rectangles by successively subdividing an initial screen-fit golden rectangle
        // store corners for drawing sectiond and/or spiral
        for (int i = 0; i <= levels; i++)
        {
            divideRect(&src, &dst, i + ix);  // i&1, i&2 ? 1:0);
            if (i & 1)
            {  // horizontal
                // these are points on the spiral;
                spiral[i + 1][ix] = dst.pos[ix];
                spiral[i + 1][iy] = dst.pos[iy];
                spiral[i + 1][2]  = -zDepth;
                // these are arc centers for approximate curve
                centers[i][ix] = dst.pos[ix] + dst.siz[ix];
                centers[i][iy] = dst.pos[iy];
                centers[i][2]  = -zDepth;
            }
            else
            {
                spiral[i + 1][ix] = dst.pos[ix];
                spiral[i + 1][iy] = dst.pos[iy];
                spiral[i + 1][2]  = -zDepth;
                centers[i][ix]    = dst.pos[ix];
                centers[i][iy]    = dst.pos[iy] + dst.siz[iy];
                centers[i][2]     = -zDepth;
            }
            src = dst;
        }

        if ((compMode == GDi_BOTH) || (compMode == GDi_SECTIONS))
        {
            strokeDraw.BeginWD(LXiSTROKE_LINE_LOOP, aRGB, alpha, 2 * lineWidth, LXiLPAT_DASH);
            quad[0][ix] = sz[ix];
            quad[0][iy] = sz[iy];
            quad[0][2]  = -zDepth;

            quad[1][ix] = sz[ix];
            quad[1][iy] = -sz[iy];
            quad[1][2]  = -zDepth;

            quad[2][ix] = -sz[ix];
            quad[2][iy] = -sz[iy];
            quad[2][2]  = -zDepth;

            quad[3][ix] = -sz[ix];
            quad[3][iy] = sz[iy];
            quad[3][2]  = -zDepth;

            quad[0][0] += offX;
            quad[0][1] += offY;
            quad[1][0] += offX;
            quad[1][1] += offY;
            quad[2][0] += offX;
            quad[2][1] += offY;
            quad[3][0] += offX;
            quad[3][1] += offY;

            strokeDraw.Vertex(quad[0], LXiSTROKE_ABSOLUTE);
            strokeDraw.Vertex(quad[1], LXiSTROKE_ABSOLUTE);
            strokeDraw.Vertex(quad[2], LXiSTROKE_ABSOLUTE);
            strokeDraw.Vertex(quad[3], LXiSTROKE_ABSOLUTE);

            strokeDraw.BeginWD(LXiSTROKE_LINES, aRGB, alpha, lineWidth, LXiLPAT_DASH);
            for (int i = 0; i <= levels; i++)
            {
                LXx_VCPY(quad[0], spiral[i + 1]);
                quad[0][0] += offX;
                quad[0][1] += offY;
                strokeDraw.Vertex(quad[0], LXiSTROKE_ABSOLUTE);
                // strokeDraw.Vertex (spiral[i+1], LXiSTROKE_ABSOLUTE);

                LXx_VCPY(quad[0], centers[i]);
                quad[0][0] += offX;
                quad[0][1] += offY;
                strokeDraw.Vertex(quad[0], LXiSTROKE_ABSOLUTE);
                // strokeDraw.Vertex (centers[i], LXiSTROKE_ABSOLUTE);
            }
        }

        if ((compMode == GDi_BOTH) || (compMode == GDi_SPIRAL))
        {
            // draw chords for spiral... useful??
            strokeDraw.BeginWD(LXiSTROKE_LINE_STRIP, aRGB, LXxMIN(alpha, 1.0) / 2, 1, LXiLPAT_DOTSLONG);
            for (int i = 0; i <= levels; i++)
            {
                LXx_VCPY(quad[0], spiral[i]);
                quad[0][0] += offX;
                quad[0][1] += offY;
                strokeDraw.Vertex(quad[0], LXiSTROKE_ABSOLUTE);
                // strokeDraw.Vertex (spiral[i], LXiSTROKE_ABSOLUTE);
            }
            //		strokeDraw.BeginW (LXiSTROKE_CIRCLES, tRGB, alpha, 1);
            //		LXx_VCLR(quad[2]);
            //		quad[2][2] = zDepth/250;
            //		for (int i=0; i<=8; i++) {
            //			strokeDraw.Vertex (spiral[i], LXiSTROKE_ABSOLUTE);
            //			strokeDraw.Vertex (quad[2], LXiSTROKE_RELATIVE);
            //
            //		}
            //		LXx_VSET3(tRGB, 0, 1.0, 1.0);
            //		strokeDraw.BeginW (LXiSTROKE_CIRCLES, tRGB, alpha, 1);
            //		for (int i=0; i<=8; i++) {
            //			strokeDraw.Vertex (centers[i], LXiSTROKE_ABSOLUTE);
            //			strokeDraw.Vertex (quad[2], LXiSTROKE_RELATIVE);
            //
            //		}

            // Approximate logarithmic spirals with quarter circles
            // draw a pi/2 arc between corners of successive rects

            int       i, j, n;
            LXtVector arc[18];
            // LXx_VSET3(tRGB, 1.0, 0, 1.0);
            strokeDraw.BeginWD(LXiSTROKE_LINE_STRIP, aRGB, alpha, lineWidth, LXiLPAT_DOTS);
            for (i = 0; i <= levels; i++)
            {
                n = 18 - i;
                quarterArc(spiral[i], centers[i], arc, n, (quadrant + ix) & 1 ? false : true);  // lower res for smaller arcs...
                for (j = 0; j < (n - 1); j++)
                {
                    LXx_VCPY(quad[0], arc[j]);
                    quad[0][0] += offX;
                    quad[0][1] += offY;
                    strokeDraw.Vertex(quad[0], LXiSTROKE_ABSOLUTE);
                    // strokeDraw.Vertex (arc[j], LXiSTROKE_ABSOLUTE);
                }
            }
            LXx_VCPY(quad[0], spiral[i]);
            quad[0][0] += offX;
            quad[0][1] += offY;
            strokeDraw.Vertex(quad[0], LXiSTROKE_ABSOLUTE);
            // strokeDraw.Vertex (spiral[i], LXiSTROKE_ABSOLUTE);
        }

        return LXe_OK;
    }

    /*
     * Export package server to define a new item type. Also create and destroy
     * the factories so they can persist while their objects are in use.
     */
    void initialize()
    {
        CLxGenericPolymorph* srv;

        srv = new CLxPolymorph<CPackage>;
        srv->AddInterface(new CLxIfc_Package<CPackage>);
        srv->AddInterface(new CLxIfc_ChannelUI<CPackage>);
        srv->AddInterface(new CLxIfc_StaticDesc<CPackage>);
        lx::AddServer(SRVNAME_ITEMTYPE, srv);

        srv = new CLxPolymorph<CInstance>;
        srv->AddInterface(new CLxIfc_PackageInstance<CInstance>);
        srv->AddInterface(new CLxIfc_ViewItem3D<CInstance>);
        lx::AddSpawner(SPWNAME_INSTANCE, srv);
    }

    void cleanup()
    {
    }

};  // namespace Overlay_SafeArea
