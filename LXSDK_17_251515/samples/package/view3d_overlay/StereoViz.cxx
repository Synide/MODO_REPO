/*
 * StereoViz.cpp	Plug-in, locator-based stereo volume visualizer
 *
 * Copyright 0000
 */
#include <cmath>
#include <lx_action.hpp>
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

namespace StereoViz
{  // disambiguate everything with a namespace

#define SRVNAME_ITEMTYPE "stereoViz"
#define SRVNAME_MODIFIER "stereoViz"
#define SPWNAME_INSTANCE "stereoViz.inst"

    /*
     * Class Declarations
     *
     * These have to come before their implementions because they reference each
     * other. Descriptions are attached to the implementations.
     */
    class CPackage;
    class CInstance;

    class CInstance : public CLxImpl_PackageInstance, public CLxImpl_ViewItem3D
    {
    public:
        CPackage*    src_pkg;
        LXtItemType  camType;
        CLxUser_Item m_item;
        LXtVector    camPos;
        LXtMatrix4   camXfrm;

        LxResult pins_Initialize(ILxUnknownID item, ILxUnknownID super) override;
        void     pins_Cleanup(void) override;

        // ViewItem3D interface.
        LxResult vitm_Draw(ILxUnknownID itemChanRead, ILxUnknownID viewStrokeDraw, int selectionFlags, const LXtVector itemColor) override;
    };

    class CPackage : public CLxImpl_Package
    {
    public:
        static LXtTagInfoDesc descInfo[];
        CLxSpawner<CInstance> inst_spawn;

        CPackage() : inst_spawn(SPWNAME_INSTANCE)
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
/*
 * The package has a set of standard channels with default values. These
 * are setup at the start using the AddChannel interface.
 */
#define Cs_PLAX_FRONT "frontParallax"
#define Cs_PLAX_BACK  "backParallax"

#define Cs_COLOR "stereoVolColor"
#define Cs_STYLE "stereoVolStyle"
#define Cs_ALPHA "stereoVolAlpha"
#define Cs_SOLID "stereoVolSolid"

    LXtTagInfoDesc CPackage::descInfo[] = {
        //	{ LXsPKG_SUPERTYPE,		LXsITYPE_LOCATOR	}, // this line makes package into item type
        { nullptr }
    };

    LxResult CPackage::pkg_SetupChannels(ILxUnknownID addChan)
    {
        CLxUser_AddChannel ac(addChan);

        ac.NewChannel(Cs_PLAX_FRONT, LXsTYPE_PERCENT);
        ac.SetDefault(0.01, 0);
        ac.NewChannel(Cs_PLAX_BACK, LXsTYPE_PERCENT);
        ac.SetDefault(0.02, 0);

        ac.NewChannel(Cs_SOLID, LXsTYPE_BOOLEAN);
        ac.SetDefault(0.0, 0);

        ac.NewChannel(Cs_ALPHA, LXsTYPE_PERCENT);
        ac.SetDefault(0.60, 0);
        return LXe_OK;
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
        camType = svcScene.ItemType(LXsITYPE_CAMERA);
        return LXe_OK;
    }

    void CInstance::pins_Cleanup(void)
    {
        m_item.clear();
    }

    LxResult CInstance::vitm_Draw(ILxUnknownID itemChanRead, ILxUnknownID viewStrokeDraw, int /*selectionFlags*/, const LXtVector /*itemColor*/)
    {
        CLxUser_View viewMap(viewStrokeDraw);
        if (viewMap.Type() == LXiVIEWv_CAMERA)  // don't draw stuff in camera view
            return LXe_OK;

        CLxUser_ChannelRead chan(itemChanRead);
        CLxLoc_StrokeDraw   strokeDraw(viewStrokeDraw);
        CLxUser_Item        m_cam;
        LXtVector           nrm, pos, quad[4], q2[4], tRGB, aRGB, bRGB;
        double              dx, dy, zoomX = 0, zoomY = 0, alpha, t, q;
        bool                solid;
        float               pxFront, pxBack, zF, zB, p, pMax;

        pxFront = static_cast<float>(chan.FValue(m_item, Cs_PLAX_FRONT));
        pxBack  = static_cast<float>(chan.FValue(m_item, Cs_PLAX_BACK));
        solid   = 0 != chan.IValue(m_item, Cs_SOLID);

        pxFront = LXxABS(pxFront);
        pxBack  = LXxABS(pxBack);
        alpha   = chan.FValue(m_item, Cs_ALPHA);

        LXx_VSET3(aRGB, 0.8, 0.2, 0.1);
        LXx_VSET3(bRGB, 0.1, 0.2, 0.8);
        LXx_VSET3(tRGB, 0.4, 0.6, 0.3);
        // if(selectionFlags&LXiSELECTION_SELECTED) {
        // }

        LXx_VCLR(pos);
        LXx_VCLR(nrm);
        if (m_item.IsA(camType))
            m_cam = m_item;
        else if (m_item.GetParent(m_cam))
        {
            if (!m_cam.IsA(camType))
                return LXe_OK;
        }

        CameraInfo ci(m_cam);
        ci.useSensor = false;
        ci.readCameraChannels(chan);

        double aperX = ci.apertureX, aperY = ci.apertureY;
        // fit 'film back' to output image size, which is what we usually expect
        ci.fitAperture(&aperX, &aperY);

        // F.o.V. half angle: tan(a) =  half-sensor / foc. len = (apX/2) / flen
        // tan(a) also = (w/2) / foc. dist ==> w/2 = fdist * tan(a)
        zoomX = 0.5 / ci.focalLength;  // foc. dist over foc. len
        zoomY = zoomX * aperY;
        zoomX *= aperX;

        pos[2] = ci.convergenceDist;

        // tanA = eyeSep / (2*convergenceDist);
        // parallax separation, S(Z) is 2*tanA*Z, where Z is the distance along the axis from the cam
        // We know the image width, W(Z), (==2*zoomX*Z), so relative parallax separation is P(Z) = S(Z)/W(Z)
        // By inverting we find the distance:
        // P(z) = Q*(1/convergenceDist - 1/z)  { Q== eyeSep/(2*zoomX)) } ==>
        // Z(P) = Q*convergenceDist/ (Q - P*convergenceDist) : asymptote at Pmax==Q/conv
        q    = ci.eyeSep * ci.focalLength / ci.apertureX;  //==ci.eyeSep / (2*zoomX);
        t    = 1.0 / ci.convergenceDist;
        pMax = static_cast<float>(q * t - 1e-6f);  // pmax

        p  = -pxFront;  // Negative for front parallax
        zF = static_cast<float>(q * ci.convergenceDist / (q - p * ci.convergenceDist));

        p  = LXxCLAMP(pxBack, 0, pMax);
        zB = static_cast<float>(q * ci.convergenceDist / (q - p * ci.convergenceDist));

        zF = LXxABS(zF);
        zB = LXxABS(zB);
        // Front plane
        strokeDraw.BeginWD(LXiSTROKE_LINE_STRIP, tRGB, alpha, 1, LXiLPAT_DASHLONG);
        pos[2] = zF;
        dx     = pos[2] * zoomX;  // w/2
        dy     = pos[2] * zoomY;  // h/2

        LXx_VSET3(quad[0], dx, dy, -pos[2]);
        LXx_VSET3(quad[1], dx, -dy, -pos[2]);
        LXx_VSET3(quad[2], -dx, -dy, -pos[2]);
        LXx_VSET3(quad[3], -dx, dy, -pos[2]);
        strokeDraw.Vertex(quad[0], LXiSTROKE_ABSOLUTE);
        strokeDraw.Vertex(quad[1], LXiSTROKE_ABSOLUTE);
        strokeDraw.Vertex(quad[2], LXiSTROKE_ABSOLUTE);
        strokeDraw.Vertex(quad[3], LXiSTROKE_ABSOLUTE);
        strokeDraw.Vertex(quad[0], LXiSTROKE_ABSOLUTE);

        // draw circles on plane to illustrate offset
        LXx_VCLR(nrm);
        nrm[2] = pos[2] * 0.05 * zoomX;
        strokeDraw.BeginWD(LXiSTROKE_CIRCLES, aRGB, alpha, 1, LXiLPAT_DASHLONG);
        pos[2] = -pos[2];
        pos[0] = pxFront * pos[2] * zoomX;  // half separation: % * w/2
        strokeDraw.Vertex(pos, LXiSTROKE_ABSOLUTE);
        strokeDraw.Vertex(nrm, LXiSTROKE_RELATIVE);
        strokeDraw.BeginWD(LXiSTROKE_CIRCLES, bRGB, alpha, 1, ~LXiLPAT_DASHLONG);
        pos[0] = -pos[0];
        strokeDraw.Vertex(pos, LXiSTROKE_ABSOLUTE);
        strokeDraw.Vertex(nrm, LXiSTROKE_RELATIVE);
        pos[0] = 0;

        // back plane
        strokeDraw.BeginWD(LXiSTROKE_LINE_STRIP, tRGB, alpha, 1, LXiLPAT_DASHLONG);
        pos[2] = zB;
        dx     = pos[2] * zoomX;  // w/2
        dy     = pos[2] * zoomY;  // h/2

        LXx_VSET3(q2[0], dx, dy, -pos[2]);
        LXx_VSET3(q2[1], dx, -dy, -pos[2]);
        LXx_VSET3(q2[2], -dx, -dy, -pos[2]);
        LXx_VSET3(q2[3], -dx, dy, -pos[2]);
        strokeDraw.Vertex(q2[0], LXiSTROKE_ABSOLUTE);
        strokeDraw.Vertex(q2[1], LXiSTROKE_ABSOLUTE);
        strokeDraw.Vertex(q2[2], LXiSTROKE_ABSOLUTE);
        strokeDraw.Vertex(q2[3], LXiSTROKE_ABSOLUTE);
        strokeDraw.Vertex(q2[0], LXiSTROKE_ABSOLUTE);

        // draw circles on plane to illustrate offset
        LXx_VCLR(nrm);
        nrm[2] = pos[2] * 0.05 * zoomX;
        strokeDraw.BeginWD(LXiSTROKE_CIRCLES, aRGB, alpha, 1, LXiLPAT_DASHLONG);
        pos[2] = -pos[2];
        pos[0] = pxBack * pos[2] * zoomX;  // half separation: % * w/2
        strokeDraw.Vertex(pos, LXiSTROKE_ABSOLUTE);
        strokeDraw.Vertex(nrm, LXiSTROKE_RELATIVE);
        strokeDraw.BeginWD(LXiSTROKE_CIRCLES, bRGB, alpha, 1, ~LXiLPAT_DASHLONG);
        pos[0] = -pos[0];
        strokeDraw.Vertex(pos, LXiSTROKE_ABSOLUTE);
        strokeDraw.Vertex(nrm, LXiSTROKE_RELATIVE);

        if (solid)
        {
            strokeDraw.BeginWD(LXiSTROKE_QUADS, tRGB, alpha / 2, 1, LXiLPAT_DASHLONG);
            strokeDraw.Vertex(q2[0], LXiSTROKE_ABSOLUTE);
            strokeDraw.Vertex(quad[0], LXiSTROKE_ABSOLUTE);
            strokeDraw.Vertex(quad[1], LXiSTROKE_ABSOLUTE);
            strokeDraw.Vertex(q2[1], LXiSTROKE_ABSOLUTE);

            strokeDraw.Vertex(q2[1], LXiSTROKE_ABSOLUTE);
            strokeDraw.Vertex(quad[1], LXiSTROKE_ABSOLUTE);
            strokeDraw.Vertex(quad[2], LXiSTROKE_ABSOLUTE);
            strokeDraw.Vertex(q2[2], LXiSTROKE_ABSOLUTE);

            strokeDraw.Vertex(q2[2], LXiSTROKE_ABSOLUTE);
            strokeDraw.Vertex(quad[2], LXiSTROKE_ABSOLUTE);
            strokeDraw.Vertex(quad[3], LXiSTROKE_ABSOLUTE);
            strokeDraw.Vertex(q2[3], LXiSTROKE_ABSOLUTE);

            strokeDraw.Vertex(q2[3], LXiSTROKE_ABSOLUTE);
            strokeDraw.Vertex(quad[3], LXiSTROKE_ABSOLUTE);
            strokeDraw.Vertex(quad[0], LXiSTROKE_ABSOLUTE);
            strokeDraw.Vertex(q2[0], LXiSTROKE_ABSOLUTE);
        }

        strokeDraw.BeginWD(LXiSTROKE_LINES, tRGB, alpha, 1, LXiLPAT_DASHLONG);
        strokeDraw.Vertex(q2[0], LXiSTROKE_ABSOLUTE);
        strokeDraw.Vertex(quad[0], LXiSTROKE_ABSOLUTE);
        strokeDraw.Vertex(q2[1], LXiSTROKE_ABSOLUTE);
        strokeDraw.Vertex(quad[1], LXiSTROKE_ABSOLUTE);
        strokeDraw.Vertex(q2[2], LXiSTROKE_ABSOLUTE);
        strokeDraw.Vertex(quad[2], LXiSTROKE_ABSOLUTE);
        strokeDraw.Vertex(q2[3], LXiSTROKE_ABSOLUTE);
        strokeDraw.Vertex(quad[3], LXiSTROKE_ABSOLUTE);

        // draw convergence plane with cute red-blue dashes
        t = 1.0;
        if (solid)
        {
            // alpha *= 2; // make it visible over quads
            t = 1.005;  // add a tiny bit so rect draws over quads...
        }
        strokeDraw.BeginWD(LXiSTROKE_LINE_STRIP, aRGB, alpha, 1, LXiLPAT_DASH);
        pos[2] = ci.convergenceDist;
        dx     = t * pos[2] * zoomX;  // w/2
        dy     = t * pos[2] * zoomY;  // h/2

        LXx_VSET3(quad[0], dx, dy, -pos[2]);
        LXx_VSET3(quad[1], dx, -dy, -pos[2]);
        LXx_VSET3(quad[2], -dx, -dy, -pos[2]);
        LXx_VSET3(quad[3], -dx, dy, -pos[2]);
        strokeDraw.Vertex(quad[0], LXiSTROKE_ABSOLUTE);
        strokeDraw.Vertex(quad[1], LXiSTROKE_ABSOLUTE);
        strokeDraw.Vertex(quad[2], LXiSTROKE_ABSOLUTE);
        strokeDraw.Vertex(quad[3], LXiSTROKE_ABSOLUTE);
        strokeDraw.Vertex(quad[0], LXiSTROKE_ABSOLUTE);
        strokeDraw.BeginWD(LXiSTROKE_LINE_STRIP, bRGB, alpha, 1, ~LXiLPAT_DASH);
        strokeDraw.Vertex(quad[0], LXiSTROKE_ABSOLUTE);
        strokeDraw.Vertex(quad[1], LXiSTROKE_ABSOLUTE);
        strokeDraw.Vertex(quad[2], LXiSTROKE_ABSOLUTE);
        strokeDraw.Vertex(quad[3], LXiSTROKE_ABSOLUTE);
        strokeDraw.Vertex(quad[0], LXiSTROKE_ABSOLUTE);

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

};  // namespace StereoViz
