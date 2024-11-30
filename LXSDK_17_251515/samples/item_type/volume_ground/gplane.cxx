/*
 * Plug-in GPlane item type.
 *
 * Copyright 0000
 *
 * A plug-in item type that creates a ground plane item with optional fog and clipping effects.
 * The plugin exercices the various possibilities that volume items have to contribute to rendering:
 * - implicit surface rendering: the ground plane surface is implemented with the RayCast method
 * - volume rendering: the fog is implemented with the RaySample method
 * - render boolean: the clipping plane is implemented with the Density and RayCast methods
 *
 * Maximum respect DFacto, special dedicace: DJ Patrice pour les bons vibes
 *
 */

#include "gplane.hxx"

#include <lx_action.hpp>
#include <lx_draw.hpp>
#include <lx_locator.hpp>
#include <lx_plugin.hpp>
#include <lxu_math.hpp>

#include <cmath>
#include <string>
#include <vector>

/*
 * ----------------------------------------------------------------
 * Ground Plane Tableau Element
 *
 * A tableau volume element lives in the tableau and generates a volume
 * for the renderer. It has a bounding box, vertex features, and sampling methods.
 */
LxResult GPlaneElement::tvol_Bound(LXtTableauBox bbox)
{
    float hs = static_cast<float>(size * .5);
    bbox[0]  = -hs;
    bbox[1]  = 0;
    bbox[2]  = -hs;
    bbox[3]  = hs;
    bbox[4]  = 0;
    bbox[5]  = hs;
    return LXe_OK;
}

unsigned GPlaneElement::tvol_FeatureCount(LXtID4 /*type*/)
{
    return 0;
}

LxResult GPlaneElement::tvol_FeatureByIndex(LXtID4 /*type*/, unsigned /*index*/, const char** /*name*/)
{
    return LXe_OUTOFBOUNDS;
}

LxResult GPlaneElement::tvol_SetVertex(ILxUnknownID /*vdesc*/)
{
    return LXe_OK;
}

int GPlaneElement::tvol_Type(void)
{
    int flags = 0;

    if (clipping)
        flags |= LXfTBLX_VOL_CLIPPING;
    if (fog)
        flags |= LXfTBLX_VOL_VOLUME;
    if (ground)
        flags |= LXfTBLX_VOL_IMPSURF;

    flags |= LXfTBLX_VOL_LOCAL_SHADER;

    return flags;
}

void GPlaneElement::RayTransform(LXpSampleRay* sRay, LXtVector /*pos*/, LXtVector opos, LXtVector dir)
{
    LXtVector tmp, dir0;

    // transform ray into object space
    LXx_VSUB3(tmp, sRay->origin, itemPos);
    lx::MatrixMultiply(opos, invXfrm, tmp);

    LXx_VCPY(dir0, sRay->dir);
    lx::MatrixMultiply(dir, invXfrm, dir0);
}

float GPlaneElement::PlaneHit(LXpSampleRay* /*sRay*/, LXpSampleSurfNormal* sNrm, LXtVector opos, LXtVector dir)
{
    LXtVector nrm = { 0, 0, 0 };
    float     t, dist = -1;

    if (dir[axis] && opos[axis] >= 0.0)
    {
        t = static_cast<float>(-1 * opos[axis] / dir[axis]);
        if (t > 0)
            dist = t;
    }

    // set normal packet
    if (sNrm && dist > 0)
    {
        nrm[axis] = 1;
        lx::MatrixMultiply(sNrm->wNorm, xfrm, nrm);
    }

    return dist;
}

float GPlaneElement::DensityFunc(LXtVector opos)
{
    float dens = 0;

    if (!InsideBox(opos, size))
        return 0.0;

    // if we are below the ground, density is 1.0.
    // - It is exponential above the ground in the case of the fog
    // - It is 0.0 above the ground in all other cases (ie clipping)
    if (opos[axis] < 0)
        dens = 1.0;
    else
    {
        if (fog)
        {
            double d0, y = opos[axis] / fogHeight;

            if (y > 1.0)
                dens = 0.0;
            else
            {
                d0   = exp(-100.0f);
                dens = static_cast<float>((exp(-100 * y) - d0) / (1 - d0));  //  exponential ground fog
            }
        }
    }

    return dens;
}

int GPlaneElement::InsideBox(LXtVector opos, double sized)
{
    if (opos[0] < -sized || opos[0] > sized || opos[2] < -sized || opos[2] > sized)
        return 0;
    else
        return 1;
}

LxResult GPlaneElement::tvol_RenderInit(ILxUnknownID /*vector*/)
{
    // do something here if you need
    return LXe_OK;
}

/*
 * Raymarching function. This is used for volume rendering, raymarching consists of finding
 * the intersection of the ray with the volume and adding samples along the ray. The volumetric
 * engine then integrates all the volume samples into a single absorption and scattering value.
 */

LxResult GPlaneElement::tvol_RaySample(ILxUnknownID densityShader,
                                       ILxUnknownID volumeShader,
                                       ILxUnknownID vector,
                                       ILxUnknownID raycastObj,
                                       ILxUnknownID raymarchObj)
{
    LXpSamplePosition* sPos = static_cast<LXpSamplePosition*>(pkt_service.FastPacket(vector, pos_offset));
    LXpSampleDensity*  sDen = static_cast<LXpSampleDensity*>(pkt_service.FastPacket(vector, den_offset));
    LXpSampleVolume*   sVol = static_cast<LXpSampleVolume*>(pkt_service.FastPacket(vector, vol_offset));
    LXpSampleRay*      sRay = static_cast<LXpSampleRay*>(pkt_service.FastPacket(vector, ray_offset));
    LXtVolumeSample    vSmp;
    LXtVector          opos, dir;
    CLxLoc_Raycast     raycast;
    CLxLoc_Raymarch    raymarch;
    LXtVector          v, tmp;
    double             dist[2], start, end, dens = 0.0;
    float              offset, d, stride, scatter, absorb;
    int                i;

    raycast.set(raycastObj);
    raymarch.set(raymarchObj);

    // transform ray into object space
    RayTransform(sRay, itemPos, opos, dir);

    // Compute ray intersection with ground plane
    dist[0] = PlaneHit(sRay, nullptr, opos, dir);

    // Compute ray intersection with fog plane
    opos[axis] -= fogHeight;
    dist[1] = PlaneHit(sRay, nullptr, opos, dir);
    opos[axis] += fogHeight;

    // setup raymarching: start & end
    start = LXxMIN(dist[0], dist[1]);
    end   = LXxMAX(dist[0], dist[1]);

    // Early exit if the fog is behind us
    if (start == -1 && end == -1)
        return LXe_OK;

    // apply nearclip & farClip distances
    if (start < nearClip)
        start = nearClip;
    if (end > farClip)
        end = farClip;
    if (end > sRay->farClip)
        end = sRay->farClip;

    // set start position and stride
    d = static_cast<float>(start);
    if (rate < 0.1)
        rate = 0.1;  // set lower limit to the rate otherwise we could get horrible render times
    stride = static_cast<float>(sRay->cone * start * rate);

    // increase stride as importance decreases
    stride /= LXxCLAMP(sRay->importance, 0.1f, 1.f);

    // jitter start position to break banding effects
    raymarch.Jitter1D(vector, &offset);
    d += 0.5f * stride * offset;

    // Raymarching loop.
    // This is the heart of volumetric rendering: we evaluate volume samples and add them to the ray
    while (d < end)
    {
        // set position
        LXx_VSCL3(v, dir, d);
        LXx_VADD3(sPos->wPos, sRay->origin, v);

        LXx_VSUB3(tmp, itemPos, sPos->wPos);
        lx::MatrixMultiply(sPos->oPos, invXfrm, tmp);

        // evaluate density
        raymarch.ShaderEvaluate(vector, densityShader);
        dens = DensityFunc(sPos->oPos);  // -> [0,1]
        dens = 2 * dens - 1;             // -> [-1,1]
        dens += sDen->density;           // add density textures
        dens -= 2 * (1 - sDen->level);   // retrieve level texures
        dens *= density;                 // multiply by base density

        if (dens > 0)
        {
            // evaluate volume shader
            raymarch.ShaderEvaluate(vector, volumeShader);

            // Compute scattering. Here we have a very simple (uniform) lighting model with no shadows
            // This could be much more elaborate than that:
            // - we could easily evaluate the lighting at that point using the raycast object
            // - for each light we could evaluate self shadows by opacity integration on the light path
            scatter = static_cast<float>(stride * (1.0 - exp(-1 * dens)));  // apply beer's law

            // compute opacity
            absorb = static_cast<float>(stride * dens);

            for (i = 0; i < 3; i++)
            {
                vSmp.color[i]   = sVol->scatterAmt * sVol->scatter[i] * scatter;
                vSmp.opacity[i] = sVol->absorbAmt * sVol->absorb[i] * absorb;
            }

            // add volumetric sample to the ray
            vSmp.dist   = d;
            vSmp.stride = stride;
            raymarch.AddVolume(vector, &vSmp);
        }

        // Bail if we're never going to converge (due to 0 cone) - MJC
        if (stride == 0)
            break;

        // update distance and stride
        d += stride;
        stride = static_cast<float>(sRay->cone * d * rate);
        stride /= LXxCLAMP(sRay->importance, 0.1f, 1.f);
    }

    return LXe_OK;
}

/*
 * Raycast. This is used for implicit surface rendering and also for render booleans
 * to show the intersection.
 */
LxResult GPlaneElement::tvol_RayCast(ILxUnknownID /*densityShader*/, ILxUnknownID vector, ILxUnknownID /*raycastObj*/, double* dist, int* localShader)
{
    LXpSampleSurfNormal* sNrm = static_cast<LXpSampleSurfNormal*>(pkt_service.FastPacket(vector, nrm_offset));
    LXpSampleRay*        sRay = static_cast<LXpSampleRay*>(pkt_service.FastPacket(vector, ray_offset));
    LXtVector            opos, dir, hpos;

    // transform ray into object space
    RayTransform(sRay, itemPos, opos, dir);

    // Compute ray intersection with ground plane
    dist[0] = PlaneHit(sRay, sNrm, opos, dir);

    hpos[0] = opos[0] + dist[0] * dir[0];
    hpos[1] = opos[1] + dist[0] * dir[1];
    hpos[2] = opos[2] + dist[0] * dir[2];

    if (!InsideBox(hpos, 0.5 * size))
        dist[0] = -1;

    localShader[0] = 1;
    return LXe_OK;
}

/*
 * Evaluate the density at the given position. This is what the boolean effect uses to determine if a given sample
 * in space is visble or not, which is pretty much like a stencil effect
 */
LxResult GPlaneElement::tvol_Density(ILxUnknownID /*densityShader*/,
                                     ILxUnknownID /*vector*/,
                                     ILxUnknownID /*raycastObj*/,
                                     const LXtVector wpos,
                                     int             wc,
                                     double*         dens)
{
    LXtVector tmp, opos;

    // transform position into object space if needed
    if (wc)
    {
        LXx_VSUB3(tmp, itemPos, wpos);
        lx::MatrixMultiply(opos, invXfrm, tmp);
    }
    else
        LXx_VCPY(opos, wpos);

    dens[0] = DensityFunc(opos);
    return LXe_OK;
}

/*
 * ----------------------------------------------------------------
 * Ground Plane Instance
 *
 * The instance is the implementation of the item, and there will be one
 * allocated for each item in the scene. It can respond to a set of
 * events.
 */
LxResult GPlaneInstance::pins_Initialize(ILxUnknownID item, ILxUnknownID /*super*/)
{
    gpl_log.Info("Initialize");
    if (m_item.set(item))
    {
        std::string x = "-- got item ";
        gpl_log.Info(x.c_str());
    }
    return LXe_OK;
}

void GPlaneInstance::pins_Cleanup(void)
{
    m_item.clear();
}

LxResult GPlaneInstance::pins_SynthName(char* buf, unsigned len)
{
    std::string name("Ground Plane");
    size_t      count = name.size() + 1;
    if (count > len)
    {
        count = len;
    }
    memcpy(buf, &name[0], count);

    return LXe_OK;
}

unsigned GPlaneInstance::pins_DupType(void)
{
    return 0;
}

LxResult GPlaneInstance::pins_TestParent(ILxUnknownID /*item*/)
{
    return LXe_NOTIMPL;
}

LxResult GPlaneInstance::pins_Loading(void)
{
    return LXe_NOTIMPL;
}

LxResult GPlaneInstance::pins_AfterLoad(void)
{
    return LXe_NOTIMPL;
}

void GPlaneInstance::pins_Doomed(void)
{
}

/*
 * The instance also presents a StringTag interface so it can pretend to have
 * part and material tags for finding a shader.
 */
LxResult GPlaneInstance::stag_Get(LXtID4 /*type*/, const char** tag)
{
    tag[0] = "Default";
    return LXe_OK;
}

/*
 * The instance's TableauSource interface allows it to place elements into the
 * tableau, in this case our ground plane element.
 */
LxResult GPlaneInstance::tsrc_Elements(ILxUnknownID tblx)
{
    CLxUser_Tableau       tbx(tblx);
    CLxUser_ChannelRead   chan;
    CLxUser_TableauShader shader;
    ILxUnknownID          element;
    LxResult              rc;
    int                   idx;

    /*
     * This is our opportunity to fetch our custom channel values.
     */
    if (!tbx.GetChannels(chan, 0))
        return LXe_NOINTERFACE;

    element = src_pkg->elt_factory.Spawn();
    if (!element)
        return LXe_FAILED;

    idx = m_item.ChannelIndex("gsize");
    if (idx >= 0)
        LXCWxOBJ(element, GPlaneElement)->size = chan.FValue(m_item, idx);

    idx = m_item.ChannelIndex("fogHeight");
    if (idx >= 0)
        LXCWxOBJ(element, GPlaneElement)->fogHeight = chan.FValue(m_item, idx);

    idx = m_item.ChannelIndex("clipping");
    if (idx >= 0)
        LXCWxOBJ(element, GPlaneElement)->clipping = chan.IValue(m_item, idx);

    idx = m_item.ChannelIndex("fog");
    if (idx >= 0)
        LXCWxOBJ(element, GPlaneElement)->fog = chan.IValue(m_item, idx);

    idx = m_item.ChannelIndex("axis");
    if (idx >= 0)
        LXCWxOBJ(element, GPlaneElement)->axis = chan.IValue(m_item, idx);

    idx = m_item.ChannelIndex("ground");
    if (idx >= 0)
        LXCWxOBJ(element, GPlaneElement)->ground = chan.IValue(m_item, idx);

    idx = m_item.ChannelIndex("nearClip");
    if (idx >= 0)
        LXCWxOBJ(element, GPlaneElement)->nearClip = chan.FValue(m_item, idx);

    idx = m_item.ChannelIndex("farClip");
    if (idx >= 0)
        LXCWxOBJ(element, GPlaneElement)->farClip = chan.FValue(m_item, idx);

    idx = m_item.ChannelIndex("density");
    if (idx >= 0)
        LXCWxOBJ(element, GPlaneElement)->density = chan.FValue(m_item, idx);

    idx = m_item.ChannelIndex("rate");
    if (idx >= 0)
        LXCWxOBJ(element, GPlaneElement)->rate = chan.FValue(m_item, idx);

    if (!tbx.GetShader(shader, m_item, inst_ifc))
        return LXe_NOTFOUND;

    /*
     * We also need to store the locator transform, so it can be looked
     * up later on when TableauInstance::GetTransform is called.
     */
    CLxLoc_Locator locator;
    if (locator.set(m_item))
    {
        LXtMatrix xfrm, invXfrm;
        LXtVector offset, invOffset;

        locator.WorldTransform(chan, xfrm, offset);
        locator.WorldInvertTransform(chan, invXfrm, invOffset);

        for (unsigned i = 0; i < 3; i++)
        {
            LXx_VCPY(LXCWxOBJ(element, GPlaneElement)->xfrm[i], xfrm[i]);
            LXx_VCPY(LXCWxOBJ(element, GPlaneElement)->invXfrm[i], invXfrm[i]);
        }

        LXx_VCPY(LXCWxOBJ(element, GPlaneElement)->itemPos, offset);
    }

    rc = tbx.AddElement(element, shader);
    lx::UnkRelease(element);

    LXCWxOBJ(element, GPlaneElement)->ray_offset = pkt_service.GetOffset(LXsCATEGORY_SAMPLE, LXsP_SAMPLE_RAY);
    LXCWxOBJ(element, GPlaneElement)->nrm_offset = pkt_service.GetOffset(LXsCATEGORY_SAMPLE, LXsP_SURF_NORMAL);
    LXCWxOBJ(element, GPlaneElement)->pos_offset = pkt_service.GetOffset(LXsCATEGORY_SAMPLE, LXsP_SAMPLE_POSITION);
    LXCWxOBJ(element, GPlaneElement)->vol_offset = pkt_service.GetOffset(LXsCATEGORY_SAMPLE, LXsP_SAMPLE_VOLUME);
    LXCWxOBJ(element, GPlaneElement)->den_offset = pkt_service.GetOffset(LXsCATEGORY_SAMPLE, LXsP_SAMPLE_DENSITY);

    return rc;
}

LxResult GPlaneInstance::tsrc_PreviewUpdate(int /*chanIndex*/, int* update)
{
    *update = LXfTBLX_PREVIEW_UPDATE_SHADING;

    return LXe_OK;
}

/*
 * Based on the channel values, draw the abstract item representation
 * using the stroke drawing interface.
 */
LxResult GPlaneInstance::vitm_Draw(ILxUnknownID itemChanRead, ILxUnknownID viewStrokeDraw, int /*selectionFlags*/, const LXtVector itemColor)
{
    CLxUser_ChannelRead chanRead;
    CLxLoc_StrokeDraw   strokeDraw;
    float               lineWidth;
    int                 chanIndex;
    double              hgt;
    double              corner = 5.0, alpha = 1.0;
    int                 k, fog, boolean, n, dot;
#if USE_AXIS
    int axis;
#endif
#if USE_GROUND
    int ground;
#endif

    chanRead.set(itemChanRead);
    strokeDraw.set(viewStrokeDraw);

    /*
     * Fetch the channel values for the current frame.
     */
    chanIndex = m_item.ChannelIndex("gsize");
    if (chanIndex < 0)
        return LXe_NOTFOUND;

    corner = chanRead.FValue(m_item, chanIndex);
    corner *= 0.5;

#if USE_AXIS
    chanIndex = m_item.ChannelIndex("axis");
    if (chanIndex < 0)
        return LXe_NOTFOUND;

    axis = chanRead.IValue(m_item, chanIndex);
#endif
#if USE_GROUND
    chanIndex = m_item.ChannelIndex("ground");
    if (chanIndex < 0)
        return LXe_NOTFOUND;

    ground = chanRead.IValue(m_item, chanIndex);
#endif
    chanIndex = m_item.ChannelIndex("fog");
    if (chanIndex < 0)
        return LXe_NOTFOUND;

    fog = chanRead.IValue(m_item, chanIndex);

    chanIndex = m_item.ChannelIndex("clipping");
    if (chanIndex < 0)
        return LXe_NOTFOUND;

    boolean = chanRead.IValue(m_item, chanIndex);

    chanIndex = m_item.ChannelIndex("fogHeight");
    if (chanIndex < 0)
        return LXe_NOTFOUND;

    hgt = chanRead.FValue(m_item, chanIndex);

    lineWidth = 1.0;
    if (fog && !boolean)
        n = 2;
    else
        n = 1;

    if (boolean)
        dot = LXiLPAT_DOTDASH;
    else
        dot = 0;

    /*
     * The item color is automatically set according to the last hit test.
     */
    LXtVector vert;
    int       strokeFlags = LXiSTROKE_ABSOLUTE;

    for (k = 0; k < n; k++)
    {
        if (k == 0)
            vert[1] = 0;
        else
        {
            vert[1] = hgt;
            dot     = LXiLPAT_DOTS;
            alpha   = 0.5;
        }

        if (dot)
            strokeDraw.BeginWD(LXiSTROKE_LINE_STRIP, itemColor, alpha, lineWidth, dot);
        else
            strokeDraw.BeginW(LXiSTROKE_LINE_STRIP, itemColor, alpha, lineWidth);

        vert[0] = -corner;
        vert[2] = -corner;
        strokeDraw.Vertex(vert, strokeFlags);

        vert[0] = corner;
        vert[2] = -corner;
        strokeDraw.Vertex(vert, strokeFlags);

        vert[0] = corner;
        vert[2] = corner;
        strokeDraw.Vertex(vert, strokeFlags);

        vert[0] = -corner;
        vert[2] = corner;
        strokeDraw.Vertex(vert, strokeFlags);

        vert[0] = -corner;
        vert[2] = -corner;
        strokeDraw.Vertex(vert, strokeFlags);
    }

    return LXe_OK;
}

LxResult GPlaneInstance::vitm_HandleCount(int* count)
{
    *count = 0;
    return LXe_OK;
}

LxResult
GPlaneInstance::vitm_HandleMotion(int /*handleIndex*/, int* /*motionType*/, double* /*min*/, double* /*max*/, LXtVector /*plane*/, LXtVector /*offset*/)
{
    return LXe_OUTOFBOUNDS;
}

LxResult GPlaneInstance::vitm_HandleChannel(int /*handleIndex*/, int* /*chanIndex*/)
{
    return LXe_OUTOFBOUNDS;
}

LxResult GPlaneInstance::vitm_HandleValueToPosition(int /*handleIndex*/, const double* /*chanValue*/, LXtVector /*position*/)
{
    return LXe_OUTOFBOUNDS;
}

LxResult GPlaneInstance::vitm_HandlePositionToValue(int /*handleIndex*/, const LXtVector /*position*/, double* /*chanValue*/)
{
    return LXe_OUTOFBOUNDS;
}

/*
 * ----------------------------------------------------------------
 * Package Class
 *
 * Packages implement item types, or simple item extensions. They are
 * like the metatype object for the item type. They define the common
 * set of channels for the item type and spawn new instances.
 *
 * Our Ground Plane item type is a subtype of "volume".
 */
LXtTagInfoDesc GPlanePackage::descInfo[] = { { LXsPKG_SUPERTYPE, "baseVolume" },
                                             { LXsPKG_IS_MASK, "." },
                                             { LXsSRV_LOGSUBSYSTEM, "volume-gplane" },
                                             { nullptr } };

GPlanePackage::GPlanePackage()
{
    gpl_factory.AddInterface(new CLxIfc_PackageInstance<GPlaneInstance>);
    gpl_factory.AddInterface(new CLxIfc_TableauSource<GPlaneInstance>);
    gpl_factory.AddInterface(new CLxIfc_StringTag<GPlaneInstance>);
    gpl_factory.AddInterface(new CLxIfc_ViewItem3D<GPlaneInstance>);

    elt_factory.AddInterface(new CLxIfc_TableauVolume<GPlaneElement>);
}

LxResult GPlanePackage::pkg_SetupChannels(ILxUnknownID addChan)
{
    CLxUser_AddChannel ac(addChan);

    ac.NewChannel("material", LXsTYPE_STRING);
    ac.SetDefault(1.0, 1);

    ac.NewChannel("ground", LXsTYPE_BOOLEAN);
    ac.SetDefault(1.0, 1);

    ac.NewChannel("clipping", LXsTYPE_BOOLEAN);
    ac.SetDefault(0.0, 0);

    ac.NewChannel("fog", LXsTYPE_BOOLEAN);
    ac.SetDefault(0.0, 0);

    ac.NewChannel("gsize", LXsTYPE_DISTANCE);
    ac.SetDefault(10.0, 0);

    ac.NewChannel("fogHeight", LXsTYPE_DISTANCE);
    ac.SetDefault(1.0, 0);

    ac.NewChannel("axis", LXsTYPE_AXIS);
    ac.SetDefault(1.0, 1);

    ac.NewChannel("nearClip", LXsTYPE_DISTANCE);
    ac.SetDefault(0.2, 0);

    ac.NewChannel("farClip", LXsTYPE_DISTANCE);
    ac.SetDefault(100.0, 0);

    ac.NewChannel("density", LXsTYPE_PERCENT);
    ac.SetDefault(1.0, 0);

    ac.NewChannel("rate", LXsTYPE_FLOAT);
    ac.SetDefault(1.0, 0);

    return LXe_OK;
}

LxResult GPlanePackage::pkg_TestInterface(const LXtGUID* guid)
{
    return (gpl_factory.TestInterface(guid) ? LXe_TRUE : LXe_FALSE);
}

LxResult GPlanePackage::pkg_Attach(void** ppvObj)
{
    GPlaneInstance* orb = gpl_factory.Alloc(ppvObj);

    orb->src_pkg  = this;
    orb->inst_ifc = static_cast<ILxUnknownID>(ppvObj[0]);

    return LXe_OK;
}

void initialize()
{
    CLxGenericPolymorph* srv;

    srv = new CLxPolymorph<GPlanePackage>;
    srv->AddInterface(new CLxIfc_Package<GPlanePackage>);
    srv->AddInterface(new CLxIfc_StaticDesc<GPlanePackage>);

    thisModule.AddServer("gplane", srv);
}
