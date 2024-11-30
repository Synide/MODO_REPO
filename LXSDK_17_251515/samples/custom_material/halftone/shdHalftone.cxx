/*
 * Plug-in component shader: Halftone Shading
 *
 *   Copyright 0000
 */

#include <lx_action.hpp>
#include <lx_channelui.hpp>
#include <lx_item.hpp>
#include <lx_log.hpp>
#include <lx_package.hpp>
#include <lx_raycast.hpp>
#include <lx_shade.hpp>
#include <lx_shdr.hpp>
#include <lx_tableau.hpp>
#include <lx_value.hpp>
#include <lx_vector.hpp>
#include <lxcommand.h>
#include <lxidef.h>

#include <cmath>
#include <string>

namespace Halftone_Shader
{  // disambiguate everything with a namespace

    static float fastTan(float a)
    {
        float a2 = a * a;
        return a + 0.5f * a2 + 5 * a2 * a2 / 24;
    }

    /*
     * Vector Packet definition: Halftone Packet
     * Here we define the packet that will be used to carry the shading parameters through the shading pipe
     */

    class HalftonePacket : public CLxImpl_VectorPacket
    {
    public:
        HalftonePacket()
        {
        }

        static LXtTagInfoDesc descInfo[];

        unsigned int   vpkt_Size() override;
        const LXtGUID* vpkt_Interface(void) override;
        LxResult       vpkt_Initialize(void* /*packet*/) override;
        LxResult       vpkt_Blend(void* /*packet*/, void* /*p0*/, void* /*p1*/, float /*t*/, int /*mode*/) override;
    };

#define SRVs_HTONE_VPACKET   "halftone.shader.packet"
#define LXsP_SAMPLE_HALFTONE SRVs_HTONE_VPACKET

    LXtTagInfoDesc HalftonePacket::descInfo[] = { { LXsSRV_USERNAME, "Halftone Shader Packet" },
                                                  { LXsSRV_LOGSUBSYSTEM, "vector-packet" },
                                                  { LXsVPK_CATEGORY, LXsCATEGORY_SAMPLE },
                                                  { nullptr } };

    typedef struct st_LXpHalftone
    {
        float      angle;
        float      sinA, cosA;
        float      uvOffset;  // percent of cell size
        float      tiles;
        LXtFVector patColor;
        float      patAlpha;
        float      seeThru;
        float      brightness;
        float      contrast;
        float      shadows;
    } LXpHalftone;

    unsigned int HalftonePacket::vpkt_Size(void)
    {
        return sizeof(LXpHalftone);
    }

    const LXtGUID* HalftonePacket::vpkt_Interface(void)
    {
        return nullptr;
    }

    LxResult HalftonePacket::vpkt_Initialize(void* p)
    {
        LXpHalftone* csp = (LXpHalftone*) p;

        csp->angle = 0.0;
        csp->sinA  = 0.0;
        csp->cosA  = 1.0;

        csp->tiles    = 64;
        csp->uvOffset = 0;
        LXx_VCLR(csp->patColor);
        return LXe_OK;
    }

    LxResult HalftonePacket::vpkt_Blend(void* /*p*/, void* /*p0*/, void* /*p1*/, float /*t*/, int /*mode*/)
    {
        /* This causes the layer opacity to blend FX packet parameters... who knew?
            LXpHalftone		*sp = (LXpHalftone *)p;
            LXpHalftone		*sp0 = (LXpHalftone *)p0;
            LXpHalftone		*sp1 = (LXpHalftone *)p1;
            CLxLoc_ShaderService	 shdrSrv;

            shdrSrv.ColorBlendValue (sp->patColor, sp0->patColor, sp1->patColor, t, mode);

            sp->angle = shdrSrv.ScalarBlendValue (sp0->angle, sp1->angle, t, mode);
            sp->sinA = sin(sp->angle);
            sp->cosA = cos(sp->angle);

            sp->tiles = shdrSrv.ScalarBlendValue (sp0->tiles, sp1->tiles, t, mode);
            sp->shadows = shdrSrv.ScalarBlendValue (sp0->shadows, sp1->shadows, t, mode);
            sp->contrast = shdrSrv.ScalarBlendValue (sp0->contrast, sp1->contrast, t, mode);
            sp->brightness = shdrSrv.ScalarBlendValue (sp0->brightness, sp1->brightness, t, mode);
            sp->uvOffset = shdrSrv.ScalarBlendValue (sp0->uvOffset, sp1->uvOffset, t, mode);
            */
        return LXe_OK;
    }

    /*
     * Non-photorealistic Shader Material: Use halftone pattern to replace diffuse/specular shading
     */
    class HalftoneMaterial : public CLxImpl_CustomMaterial, public CLxImpl_ChannelUI
    {
    public:
        HalftoneMaterial()
        {
        }

        static LXtTagInfoDesc descInfo[];

        int      cmt_Flags() override;
        LxResult cmt_SetupChannels(ILxUnknownID /*addChan*/) override;
        LxResult cmt_LinkChannels(ILxUnknownID /*eval*/, ILxUnknownID /*item*/) override;
        LxResult cmt_LinkSampleChannels(ILxUnknownID /*eval*/, ILxUnknownID /*item*/, int* /*idx*/) override;
        LxResult cmt_ReadChannels(ILxUnknownID /*attr*/, void** /*ppvData*/) override;
        LxResult cmt_CustomPacket(const char**) override;
        void     cmt_MaterialEvaluate(ILxUnknownID /*etor*/, int* /*idx*/, ILxUnknownID /*vector*/, void* /*data*/) override;
        void     cmt_ShaderEvaluate(ILxUnknownID /*vector*/,
                                    ILxUnknownID /*rayObj*/,
                                    LXpShadeComponents* /*sCmp*/,
                                    LXpShadeOutput* /*sOut*/,
                                    void* /*data*/) override;
        void     cmt_Cleanup(void* /*data*/) override;

        LxResult cmt_SetOpaque(int* /*opaque*/) override;

        int cmt_IsSampleDriven(int* idx) override
        {
            return nodalSvc.AnyDrivenChans(&idx[idxs[5].chan], 11);
        }

        LxResult cui_Enabled(const char* /*channelName*/, ILxUnknownID /*msg*/, ILxUnknownID /*item*/, ILxUnknownID /*read*/) override;
        LxResult cui_DependencyCount(const char* /*channelName*/, unsigned* /*count*/) override;
        LxResult
        cui_DependencyByIndex(const char* /*channelName*/, unsigned /*index*/, LXtItemType* /*depItemType*/, const char** /*depChannelName*/) override;
        LxResult cui_UIHints(const char* /*channelName*/, ILxUnknownID /*hints*/) override;

        LXtItemType MyType();

        CLxUser_PacketService pkt_service;
        CLxUser_NodalService  nodalSvc;

        unsigned ray_offset;
        unsigned nrm_offset;
        unsigned tex_offset;
        unsigned pix_offset;
        unsigned prm_offset;
        unsigned cst_offset;
        unsigned res_offset;
        unsigned pkt_offset;

        LXtItemType my_type;

        LXtSampleIndex idxs[16];  // indices to each data channel in RendData

        class RendData
        {
        public:
            int        pattern;      // which halftone pattern
            int        specPattern;  // which pattern for sepcular
            float      angle;
            float      tiles;
            float      uvOffset;  // percent of cell size: range to 'jitter' samples
            float      sinA, cosA;
            bool       screenCoords;
            float      depthScale;  // for screen coords, percent tiling scale per meter depth
            LXtFVector patColor;
            float      patAlpha;
            int        drawSpec;
            float      seeThru;
            float      brightness;
            float      contrast;
            float      shadows;
        };

    private:
        int   htMode;
        float HToneCell(int /*i*/, int /*j*/, int /*mode*/, float /*u*/, float /*v*/, float /*level*/);
        void  CellOffset(int /*mode*/, float* /*du*/, float* /*dv*/);
    };

#define SRVs_HTONE_MATR          "halftone"
#define SRVs_HTONE_MATR_ITEMTYPE "material." SRVs_HTONE_MATR

    LXtTagInfoDesc HalftoneMaterial::descInfo[] = { { LXsSRV_USERNAME, "Halftone Shader" }, { LXsSRV_LOGSUBSYSTEM, "comp-shader" }, { nullptr } };

    /*
     * clean up render data
     */
    void HalftoneMaterial::cmt_Cleanup(void* data)
    {
        RendData* rd = (RendData*) data;

        delete rd;
    }

    /*
     * Setup channels for the item type.
     */

    enum
    {
        HTONE_PAT_DOTS = 0,
        HTONE_PAT_LINES,
        HTONE_PAT_HATCH,
        HTONE_PAT_ADAPT,
        HTONE_PAT_ROUND,
        HTONE_PAT_SQUARE,
        HTONE_PAT_DIAMOND,
        HTONE_PAT_CROSS,
        HTONE_PAT_CHKLINES,
        HTONE_PAT_CHKDIAMOND,
        HTONE_PAT_END
    };

    static LXtTextValueHint hint_Pattern[] = {
        { HTONE_PAT_DOTS, "dots" },        { HTONE_PAT_LINES, "lines" },          { HTONE_PAT_HATCH, "crosshatch" }, { HTONE_PAT_ADAPT, "adaptive" },
        { HTONE_PAT_ROUND, "circle" },     { HTONE_PAT_SQUARE, "square" },        { HTONE_PAT_DIAMOND, "diamond" },  { HTONE_PAT_CROSS, "cross" },
        { HTONE_PAT_CHKLINES, "checker" }, { HTONE_PAT_CHKDIAMOND, "diamCheck" }, { -1, "=halftone-pattern" },       { -1, nullptr },
    };

#define HALFTONE_CH_PATTERN  "cellPattern"
#define HALFTONE_CH_TILES    "cellTiles"
#define HALFTONE_CH_CELLANG  "cellAngle"
#define HALFTONE_CH_SPEC     "drawSpecular"
#define HALFTONE_CH_EDGES    "drawEdges"
#define HALFTONE_CH_INCEDGE  "incidenceEdges"
#define HALFTONE_CH_ANGEDGE  "angleEdges"
#define HALFTONE_CH_DISTEDGE "distanceEdges"
#define HALFTONE_CH_ANGMIN   "minAngle"
#define HALFTONE_CH_ANGMAX   "maxAngle"
#define HALFTONE_CH_THRSH    "distThreshold"
#define HALFTONE_CH_EDWIDTH  "edgesWidth"
#define HALFTONE_CH_SCREEN   "screenCoords"
#define HALFTONE_CH_SPECPAT  "specPattern"
#define HALFTONE_CH_ZSCALE   "zScale"
#define HALFTONE_CH_PATCOLOR "patColor"
#define HALFTONE_CH_PATALPHA "patAlpha"
#define HALFTONE_CH_SEETHRU  "seeThrough"
#define HALFTONE_CH_BRIGHT   "brightness"
#define HALFTONE_CH_CONTRAST "contrast"
#define HALFTONE_CH_SHADOWS  "shadows"
#define HALFTONE_CH_UVOFFSET "uvOffset"

    int HalftoneMaterial::cmt_Flags()
    {
        return LXfSHADERFLAGS_USE_LOCATOR | LXfSHADERFLAGS_NEED_UVS;  // means the shader is using a texture locator (which is automatocally added and
                                                                      // linked on creation)
    }

    LxResult HalftoneMaterial::cmt_SetupChannels(ILxUnknownID addChan)
    {
        CLxUser_AddChannel ac(addChan);
        LXtVector          zero = { 0, 0, 0 };

        ac.NewChannel(HALFTONE_CH_PATTERN, LXsTYPE_INTEGER);
        ac.SetDefault(0.0, HTONE_PAT_ADAPT);
        ac.SetHint(hint_Pattern);

        ac.NewChannel(HALFTONE_CH_SPECPAT, LXsTYPE_INTEGER);
        ac.SetDefault(0.0, HTONE_PAT_DOTS);
        ac.SetHint(hint_Pattern);

        ac.NewChannel(HALFTONE_CH_SCREEN, LXsTYPE_BOOLEAN);
        ac.SetDefault(0.0, 1);

        ac.NewChannel(HALFTONE_CH_ZSCALE, LXsTYPE_PERCENT);
        ac.SetDefault(0.02, 0);

        ac.NewChannel(HALFTONE_CH_TILES, LXsTYPE_FLOAT);
        ac.SetDefault(64.0, 0);

        ac.NewChannel(HALFTONE_CH_CELLANG, LXsTYPE_ANGLE);
        ac.SetDefault(0.0, 0);

        ac.NewChannel(HALFTONE_CH_SPEC, LXsTYPE_BOOLEAN);
        ac.SetDefault(0.0, 1);

        ac.NewChannel(HALFTONE_CH_PATCOLOR, LXsTYPE_COLOR1);
        ac.SetVector(LXsCHANVEC_RGB);
        ac.SetDefaultVec(zero);

        ac.NewChannel(HALFTONE_CH_SEETHRU, LXsTYPE_PERCENT);
        ac.SetDefault(0.0, 0);
        ac.NewChannel(HALFTONE_CH_BRIGHT, LXsTYPE_PERCENT);
        ac.SetDefault(0.0, 0);
        ac.NewChannel(HALFTONE_CH_CONTRAST, LXsTYPE_PERCENT);
        ac.SetDefault(0.0, 0);
        ac.NewChannel(HALFTONE_CH_SHADOWS, LXsTYPE_PERCENT);
        ac.SetDefault(0.0, 0);

        ac.NewChannel(HALFTONE_CH_PATALPHA, LXsTYPE_PERCENT);
        ac.SetDefault(1.0, 0);

        ac.NewChannel(HALFTONE_CH_UVOFFSET, LXsTYPE_PERCENT);
        ac.SetDefault(0.0, 0);
        return LXe_OK;
    }

    /*
     * Attach to channel evaluations. This gets the indicies for the channels in attributes.
     */
    LxResult HalftoneMaterial::cmt_LinkChannels(ILxUnknownID eval, ILxUnknownID item)
    {
        CLxUser_Evaluation ev(eval);
        CLxUser_Item       it(item);

        idxs[0].chan = it.ChannelIndex(HALFTONE_CH_PATTERN);
        idxs[1].chan = it.ChannelIndex(HALFTONE_CH_SPECPAT);
        idxs[2].chan = it.ChannelIndex(HALFTONE_CH_SCREEN);
        idxs[3].chan = it.ChannelIndex(HALFTONE_CH_SPEC);
        idxs[4].chan = it.ChannelIndex(HALFTONE_CH_ZSCALE);

        idxs[5].chan = it.ChannelIndex(HALFTONE_CH_TILES);
        idxs[6].chan = it.ChannelIndex(HALFTONE_CH_CELLANG);

        idxs[7].chan = it.ChannelIndex(HALFTONE_CH_PATCOLOR ".R");
        idxs[8].chan = it.ChannelIndex(HALFTONE_CH_PATCOLOR ".G");
        idxs[9].chan = it.ChannelIndex(HALFTONE_CH_PATCOLOR ".B");

        idxs[10].chan = it.ChannelIndex(HALFTONE_CH_SEETHRU);
        idxs[11].chan = it.ChannelIndex(HALFTONE_CH_BRIGHT);
        idxs[12].chan = it.ChannelIndex(HALFTONE_CH_CONTRAST);
        idxs[13].chan = it.ChannelIndex(HALFTONE_CH_SHADOWS);
        idxs[14].chan = it.ChannelIndex(HALFTONE_CH_PATALPHA);
        idxs[15].chan = it.ChannelIndex(HALFTONE_CH_UVOFFSET);

        idxs[0].layer = ev.AddChan(item, idxs[0].chan);
        idxs[1].layer = ev.AddChan(item, idxs[1].chan);
        idxs[2].layer = ev.AddChan(item, idxs[2].chan);

        idxs[3].layer = ev.AddChan(item, idxs[3].chan);
        idxs[4].layer = ev.AddChan(item, idxs[4].chan);
        idxs[5].layer = ev.AddChan(item, idxs[5].chan);
        idxs[6].layer = ev.AddChan(item, idxs[6].chan);
        idxs[7].layer = ev.AddChan(item, idxs[7].chan);
        idxs[8].layer = ev.AddChan(item, idxs[8].chan);
        idxs[9].layer = ev.AddChan(item, idxs[9].chan);

        idxs[10].layer = ev.AddChan(item, idxs[10].chan);
        idxs[11].layer = ev.AddChan(item, idxs[11].chan);
        idxs[12].layer = ev.AddChan(item, idxs[12].chan);
        idxs[13].layer = ev.AddChan(item, idxs[13].chan);
        idxs[14].layer = ev.AddChan(item, idxs[14].chan);
        idxs[15].layer = ev.AddChan(item, idxs[15].chan);

        ray_offset = pkt_service.GetOffset(LXsCATEGORY_SAMPLE, LXsP_SAMPLE_RAY);
        nrm_offset = pkt_service.GetOffset(LXsCATEGORY_SAMPLE, LXsP_SURF_NORMAL);
        tex_offset = pkt_service.GetOffset(LXsCATEGORY_SAMPLE, LXsP_TEXTURE_INPUT);
        prm_offset = pkt_service.GetOffset(LXsCATEGORY_SAMPLE, LXsP_SAMPLE_PARMS);
        cst_offset = pkt_service.GetOffset(LXsCATEGORY_SAMPLE, LXsP_RAYCAST);
        res_offset = pkt_service.GetOffset(LXsCATEGORY_SAMPLE, LXsP_CAM_RESOLUTION);
        pkt_offset = pkt_service.GetOffset(LXsCATEGORY_SAMPLE, LXsP_SAMPLE_HALFTONE);
        return LXe_OK;
    }

    /*
     * Attach to channel evaluations for per-sample values. This sets the indicies
     * for the channels in the evaluator. These are for the per-sample channels.
     */
    LxResult HalftoneMaterial::cmt_LinkSampleChannels(ILxUnknownID eval, ILxUnknownID item, int* idx)
    {
        // the index of any channel that is not driven will be set to LXiNODAL_NOT_DRIVEN
        nodalSvc.AddSampleChan(eval, item, idxs[0].chan, idx, LXfECHAN_READ);
        nodalSvc.AddSampleChan(eval, item, idxs[1].chan, idx, LXfECHAN_READ);
        nodalSvc.AddSampleChan(eval, item, idxs[2].chan, idx, LXfECHAN_READ);

        nodalSvc.AddSampleChan(eval, item, idxs[3].chan, idx, LXfECHAN_READ);
        nodalSvc.AddSampleChan(eval, item, idxs[4].chan, idx, LXfECHAN_READ);
        nodalSvc.AddSampleChan(eval, item, idxs[5].chan, idx, LXfECHAN_READ);
        nodalSvc.AddSampleChan(eval, item, idxs[6].chan, idx, LXfECHAN_READ);
        nodalSvc.AddSampleChan(eval, item, idxs[7].chan, idx, LXfECHAN_READ);
        nodalSvc.AddSampleChan(eval, item, idxs[8].chan, idx, LXfECHAN_READ);
        nodalSvc.AddSampleChan(eval, item, idxs[9].chan, idx, LXfECHAN_READ);

        nodalSvc.AddSampleChan(eval, item, idxs[10].chan, idx, LXfECHAN_READ);
        nodalSvc.AddSampleChan(eval, item, idxs[11].chan, idx, LXfECHAN_READ);
        nodalSvc.AddSampleChan(eval, item, idxs[12].chan, idx, LXfECHAN_READ);
        nodalSvc.AddSampleChan(eval, item, idxs[13].chan, idx, LXfECHAN_READ);
        nodalSvc.AddSampleChan(eval, item, idxs[14].chan, idx, LXfECHAN_READ);
        nodalSvc.AddSampleChan(eval, item, idxs[15].chan, idx, LXfECHAN_READ);

        return LXe_OK;
    }

    /*
     * Read channel values which may have changed.
     */
    LxResult HalftoneMaterial::cmt_ReadChannels(ILxUnknownID attr, void** ppvData)
    {
        CLxUser_Attributes at(attr);
        RendData*          rd = new RendData;

        rd->pattern      = at.Int(idxs[0].layer);
        rd->specPattern  = at.Int(idxs[1].layer);
        rd->screenCoords = at.Bool(idxs[2].layer);
        rd->drawSpec     = at.Int(idxs[3].layer);
        rd->depthScale   = static_cast<float>(at.Float(idxs[4].layer));

        rd->tiles       = static_cast<float>(at.Int(idxs[5].layer));
        rd->angle       = static_cast<float>(at.Float(idxs[6].layer));
        rd->patColor[0] = static_cast<float>(at.Float(idxs[7].layer));
        rd->patColor[1] = static_cast<float>(at.Float(idxs[8].layer));
        rd->patColor[2] = static_cast<float>(at.Float(idxs[9].layer));
        rd->seeThru     = static_cast<float>(at.Float(idxs[10].layer));
        rd->brightness  = static_cast<float>(at.Float(idxs[11].layer));
        rd->contrast    = static_cast<float>(at.Float(idxs[12].layer));
        rd->shadows     = static_cast<float>(at.Float(idxs[13].layer));
        rd->patAlpha    = static_cast<float>(at.Float(idxs[14].layer));
        rd->uvOffset    = static_cast<float>(at.Float(idxs[15].layer));

        ppvData[0] = rd;
        rd->sinA   = sin(rd->angle);
        rd->cosA   = cos(rd->angle);
        return LXe_OK;
    }

#define ROOT2 1.414213562
    static float xsc = 1.0;

    // stagger rows based on ht mode
    void HalftoneMaterial::CellOffset(int mode, float* du, float* dv)
    {
        *du = 0;
        *dv = 0;
        switch (mode)
        {
            case HTONE_PAT_CROSS:  // double offset
            case HTONE_PAT_CHKLINES:
            case HTONE_PAT_CHKDIAMOND:
                *dv = 0.5;         // fall through to do du
            case HTONE_PAT_ROUND:  // single offset (x) for staggered rows
            case HTONE_PAT_SQUARE:
            case HTONE_PAT_DIAMOND:
                *du = 0.5;
                break;
            case HTONE_PAT_DOTS:  // No offset
            case HTONE_PAT_LINES:
            case HTONE_PAT_HATCH:
            case HTONE_PAT_ADAPT:
            default:
                break;
        }
    }

    float HalftoneMaterial::HToneCell(int /*i*/, int /*j*/, int mode, float u, float v, float level)
    {
        static float minW = 0.1f, maxW = 0.5f;  // adaptive transition thresholds
        float        r, val            = 0.0f;

        switch (mode)
        {
            case HTONE_PAT_ROUND:  // staggered dot
            case HTONE_PAT_DOTS:   // dot
                u -= 0.5;
                v -= 0.5;
                r   = static_cast<float>(sqrt(u * u + v * v) * ROOT2);
                val = (r > level ? 1.f : ((r > level - 0.1f) ? (0.1f - (level - r)) * 10 : 0));  // black circle
                break;
            case HTONE_PAT_LINES:  // h line
            case HTONE_PAT_CHKLINES:
                u -= 0.5;
                v -= 0.5;
                r   = 2 * LXxABS(v);
                val = (r > level ? 1.f : ((r > level - 0.1f) ? (0.1f - (level - r)) * 10 : 0));
                break;
            case HTONE_PAT_HATCH:  // grid
                level *= 0.5;
                u -= 0.5;
                v -= 0.5;
                u   = LXxABS(u);
                v   = LXxABS(v);
                r   = xsc * LXxMIN(u, v);
                val = (r > level ? 1.0f : ((r > level - 0.1f) ? (0.1f - (level - r)) * 10 : 0));
                break;
            case HTONE_PAT_SQUARE:
                u -= 0.5;
                v -= 0.5;
                r   = 2 * LXxMAX(LXxABS(u), LXxABS(v));
                val = (r > level ? 1.0f : ((r > level - 0.1f) ? (0.1f - (level - r)) * 10 : 0));  // black square
                break;
            case HTONE_PAT_DIAMOND:
            case HTONE_PAT_CHKDIAMOND:
                u -= 0.5;
                v -= 0.5;
                r = (LXxABS(u) + LXxABS(v));  // Manhattan metric!
                // r = i&1 ? (LXxABS(v) - LXxABS(u)): (LXxABS(u) - LXxABS(v));
                val = (r > level ? 1.0f : ((r > level - 0.1f) ? (0.1f - (level - r)) * 10 : 0));  // black diamond
                break;
            case HTONE_PAT_CROSS:
                u -= 0.5;
                v -= 0.5;
                r   = 2 * LXxMIN(LXxABS(u), LXxABS(v));
                val = (r > level ? 1.0f : ((r > level - 0.1f) ? (0.1f - (level - r)) * 10 : 0));  // black +
                break;
            case HTONE_PAT_ADAPT:  // dashed line, line, cross, depending on weight
            default:
                u -= 0.5;
                v -= 0.5;
                u = LXxABS(u);
                v = LXxABS(v);

                if (level < minW)
                {
                    float lev, v2;
                    r   = 2 * v;
                    val = (r > minW ? 1.0f : ((r > minW - 0.1f) ? (0.1f - (minW - r)) * 10 : 0));
                    r   = 2 * u;  // shorten line
                    lev = level * 10;
                    v2  = (r > lev ? 1.0f : ((r > lev - 0.1f) ? (0.1f - (lev - r)) * 10 : 0));
                    val = LXxMAX(val, v2);
                }
                else if (level < maxW)
                {
                    r   = 2 * v;
                    val = (r > level ? 1.0f : ((r > level - 0.1f) ? (0.1f - (level - r)) * 10 : 0));
                }
                else
                {
                    float lev, v2;
                    r   = 2 * v;
                    val = (r > maxW ? 1.0f : ((r > maxW - 0.1f) ? (0.1f - (maxW - r)) * 10 : 0));
                    r   = 2 * u;  // crossing line
                    lev = 2 * (level - maxW);
                    v2  = (r > lev ? 1.0f : ((r > lev - 0.1f) ? (0.1f - (lev - r)) * 10 : 0));
                    val = LXxMIN(val, v2);
                }
                break;
        }
        return val;
    }

    /*
     * Like the cel shader, the halftone shader needs shading values to be computed
     * below it, so it can't be opaque.
     */
    LxResult HalftoneMaterial::cmt_SetOpaque(int* opaque)
    {
        *opaque = 0;

        return LXe_OK;
    }

    LxResult HalftoneMaterial::cmt_CustomPacket(const char** packet)
    {
        packet[0] = LXsP_SAMPLE_HALFTONE;
        return LXe_OK;
    }

    /*
     * Set custom material values at a spot
     */
    void HalftoneMaterial::cmt_MaterialEvaluate(ILxUnknownID etor, int* idx, ILxUnknownID vector, void* data)
    {
        LXpHalftone* sHalf = (LXpHalftone*) pkt_service.FastPacket(vector, pkt_offset);
        RendData*    rd    = (RendData*) data;

        // set the edge width in the cel shader packet, this is now available for texturing and for other shaders
        sHalf->tiles = static_cast<float>(nodalSvc.GetInt(etor, idx, idxs[5].chan, static_cast<int>(rd->tiles)));
        sHalf->angle = static_cast<float>(nodalSvc.GetFloat(etor, idx, idxs[6].chan, rd->angle));

        sHalf->patColor[0] = static_cast<float>(nodalSvc.GetFloat(etor, idx, idxs[7].chan, rd->patColor[0]));
        sHalf->patColor[1] = static_cast<float>(nodalSvc.GetFloat(etor, idx, idxs[8].chan, rd->patColor[1]));
        sHalf->patColor[2] = static_cast<float>(nodalSvc.GetFloat(etor, idx, idxs[9].chan, rd->patColor[2]));

        sHalf->seeThru    = static_cast<float>(nodalSvc.GetFloat(etor, idx, idxs[10].chan, rd->seeThru));
        sHalf->brightness = static_cast<float>(nodalSvc.GetFloat(etor, idx, idxs[11].chan, rd->brightness));
        sHalf->contrast   = static_cast<float>(nodalSvc.GetFloat(etor, idx, idxs[12].chan, rd->contrast));
        sHalf->shadows    = static_cast<float>(nodalSvc.GetFloat(etor, idx, idxs[13].chan, rd->shadows));
        sHalf->patAlpha   = static_cast<float>(nodalSvc.GetFloat(etor, idx, idxs[14].chan, rd->patAlpha));
        sHalf->uvOffset   = static_cast<float>(nodalSvc.GetFloat(etor, idx, idxs[15].chan, rd->uvOffset));

        sHalf->sinA = sin(sHalf->angle);
        sHalf->cosA = cos(sHalf->angle);
    }

    /*
     * Evaluate the color at a spot.
     */
    void HalftoneMaterial::cmt_ShaderEvaluate(ILxUnknownID vector, ILxUnknownID rayObj, LXpShadeComponents* sCmp, LXpShadeOutput* sOut, void* data)
    {
        LXpTextureInput* tInp = (LXpTextureInput*) pkt_service.FastPacket(vector, tex_offset);
        // LXpSampleSurfNormal	*sNrm = (LXpSampleSurfNormal*) pkt_service.FastPacket (vector, nrm_offset);
        LXpSampleRay*        sRay   = (LXpSampleRay*) pkt_service.FastPacket(vector, ray_offset);
        LXpSampleParms*      sParms = (LXpSampleParms*) pkt_service.FastPacket(vector, prm_offset);
        LXpCameraResolution* sRes   = (LXpCameraResolution*) pkt_service.FastPacket(vector, res_offset);
        LXpHalftone*         sHalf  = (LXpHalftone*) pkt_service.FastPacket(vector, pkt_offset);
        RendData*            rd     = (RendData*) data;
        float                tiles;
        int                  i, j;
        LXtVector            pos, vec;
        LXtFVector           bkgColor, fgColor;
        CLxLoc_Raycast1      raycast;
        float                xOff, yOff;
        // static int		 tst = 0;

        raycast.set(rayObj);

        float u, v, r, level = 0;
        if (!rd->screenCoords)
        {
            // rotate UV space
            u = (tInp->uvw[0] - 0.5f);
            v = (tInp->uvw[1] - 0.5f);

            r = u * sHalf->cosA + v * sHalf->sinA;
            v = v * sHalf->cosA - u * sHalf->sinA;
            u = r;

            u += 0.5;
            v += 0.5;
        }
        else
        {
            int iu, iv;
            raycast.GetBucketPixel(vector, &iu, &iv);
            raycast.GetBucketSubPixel(vector, &u, &v);
            u += iu;
            v += iv;
            if (sRes->width > 0 && sRes->height > 0)
            {
                u /= sRes->width;
                v /= sRes->width;  // sRes->height; make square cells (#29656)
            }
            else
            {
                u /= 100;
                v /= 100;
            }
            u -= 0.5;  // rotate about center in middle of UVs
            v -= 0.5;

            r = (1.0f + rd->depthScale * sRay->dist);
            u *= r;
            v *= r;
            r = u * sHalf->cosA + v * sHalf->sinA;
            v = v * sHalf->cosA - u * sHalf->sinA;
            u = r;

            u += 0.5;
            v += 0.5;

            if (u < 0)
            {
                u += -floor(u);
            }
            if (v < 0)
            {
                v += -floor(v);
            }
        }

        htMode = LXxCLAMP(rd->pattern, 0, HTONE_PAT_END - 1);  // HTMode;

        tiles = sHalf->tiles;  // use textured value

        // scale UV to tile
        u = tiles * LXxABS(u);
        v = tiles * LXxABS(v);

        u += sHalf->uvOffset;
        v += sHalf->uvOffset;

        i = (int) u;
        j = (int) v;
        CellOffset(htMode, &xOff, &yOff);

        if (j & 1)
        {  // offset alternating rows
            u += xOff;
        }
        if (i & 1)
        {  // and alternating columns
            v += yOff;
        }
        // get grid indices, sub-grid coordinates
        i = (int) u;
        u -= i;
        j = (int) v;
        v -= j;

        level = LXxCLAMP(sHalf->shadows, 0, 1);
        LXx_VLERP(vec, sCmp->diffUns, sCmp->diff, level);  // mix in shadows into surface color

        level = sParms->diffAmt * LXx_VLEN(sParms->diffCol);                // max possible level (should use LUMA)
        level = static_cast<float>(level > 0 ? LXx_VLEN(vec) / level : 0);  // ratio of shaded level to max
        if (sHalf->brightness < 0.0)
            level *= (1.f + sHalf->brightness);
        else
            level += (1.f - level) * sHalf->brightness;
        level = (level - 0.5f) * fastTan(static_cast<float>((1.0f + sHalf->contrast) * 0.5f * LXx_HALFPI)) + 0.5f;

        level = 1.f - level;  // darkening level
        level = HToneCell(i, j, htMode, u, v, level);

        if (sHalf->seeThru > 0)
        {
            LXx_VCPY(pos, sRay->origin);
            ILxUnknownID  shadeVector;
            LXpSampleRay* sRay1 = nullptr;
            double        dist;

            shadeVector = raycast.RayPush(vector);
            if (shadeVector)
            {
                dist  = raycast.Raytrace(shadeVector, pos, sRay->dir, LXfRAY_SCOPE_ENVIRONMENT);
                sRay1 = (LXpSampleRay*) pkt_service.FastPacket(shadeVector, ray_offset);
                LXx_VCPY(bkgColor, sRay1->color);
                raycast.RayPop(vector);
            }
            else
                LXx_VCLR(bkgColor);

            dist = LXxCLAMP(sHalf->seeThru, 0, 1);
            LXx_VLERP(sCmp->diff, sParms->diffCol, bkgColor, dist);
        }
        else
            LXx_VSCL3(sCmp->diff, sParms->diffCol, sParms->diffAmt);

        LXx_VLERP(fgColor, sCmp->diff, sHalf->patColor, sHalf->patAlpha);  // mix pattern color in with alpha
        LXx_VLERP(sCmp->diff, fgColor, sCmp->diff, level);

        if (rd->drawSpec)
        {
            level = LXx_VLEN(sParms->specCol);  // sParms->specAmt*
            level = level > 0 ? LXx_VLEN(sCmp->spec) / level : 0;
            LXx_VCLR(sCmp->spec);
            htMode = LXxCLAMP(rd->specPattern, 0, 3);
            level  = HToneCell(i, j, htMode, u, v, level);
            // level = 1.0 - level; // darkening level
            LXx_VLERP(fgColor, sCmp->diff, sParms->specCol, sHalf->patAlpha);  // mix pattern color in with alpha
            LXx_VLERP(sCmp->diff, fgColor, sCmp->diff, level);
        }

        // Update final output color
        for (i = 0; i < 3; i++)
            sOut->color[i] = sCmp->diff[i] + sCmp->spec[i] + sCmp->refl[i] + sCmp->tran[i] + sCmp->subs[i] + sCmp->lumi[i];
    }

    /*
     * Utility to get the type code for this item type, as needed.
     */
    LXtItemType HalftoneMaterial::MyType()
    {
        if (my_type != LXiTYPE_NONE)
            return my_type;

        CLxUser_SceneService svc;

        my_type = svc.ItemType(SRVs_HTONE_MATR_ITEMTYPE);
        return my_type;
    }

    LxResult HalftoneMaterial::cui_UIHints(const char* channelName, ILxUnknownID hints)
    {
        if (!strcmp(channelName, HALFTONE_CH_PATCOLOR) || !strcmp(channelName, HALFTONE_CH_PATALPHA) || !strcmp(channelName, HALFTONE_CH_TILES) ||
            !strcmp(channelName, HALFTONE_CH_CELLANG) || !strcmp(channelName, HALFTONE_CH_UVOFFSET))
        {
            CLxUser_UIHints ui(hints);
            ui.ChannelFlags(LXfUIHINTCHAN_SUGGESTED);
            return LXe_OK;
        }

        return LXe_NOTIMPL;
    }

    LxResult HalftoneMaterial::cui_Enabled(const char* channelName, ILxUnknownID msg, ILxUnknownID item, ILxUnknownID read)
    {
        if (strcmp(channelName, HALFTONE_CH_ZSCALE))
            return LXe_OK;

        CLxUser_Item        src(item);
        CLxUser_ChannelRead chan(read);

        if (chan.IValue(src, HALFTONE_CH_SCREEN) != 0.0)
            return LXe_OK;

        CLxUser_Message res(msg);

        res.SetCode(LXe_CMD_DISABLED);
        res.SetMsg("common", 99);
        res.SetArg(1, "This only applies when Screen Coordinates are used.");
        return LXe_CMD_DISABLED;
    }

    LxResult HalftoneMaterial::cui_DependencyCount(const char* channelName, unsigned* count)
    {
        if (strcmp(channelName, HALFTONE_CH_ZSCALE) == 0)
            count[0] = 1;
        else
            count[0] = 0;

        return LXe_OK;
    }

    LxResult HalftoneMaterial::cui_DependencyByIndex(const char* channelName, unsigned /*index*/, LXtItemType* depItemType, const char** depChannelName)
    {
        if (strcmp(channelName, HALFTONE_CH_ZSCALE))
            return LXe_OUTOFBOUNDS;

        depItemType[0]    = MyType();
        depChannelName[0] = HALFTONE_CH_SCREEN;
        return LXe_OK;
    }

    /* --------------------------------- */

    /*
     * Packet Effects definition:
     * Here we define the texture effects on the Halftone packet
     */

    class HTonePFX : public CLxImpl_PacketEffect
    {
    public:
        HTonePFX()
        {
        }

        static LXtTagInfoDesc descInfo[];

        LxResult     pfx_Packet(const char** /*packet*/) override;
        unsigned int pfx_Count(void) override;
        LxResult     pfx_ByIndex(int /*idx*/, const char** /*name*/, const char** /*typeName*/, int* /*type*/) override;
        LxResult     pfx_Get(int /*idx*/, void* /*packet*/, float* /*val*/, void* /*item*/) override;
        LxResult     pfx_Set(int /*idx*/, void* /*packet*/, const float* /*val*/, void* /*item*/) override;
    };

#define SRVs_HTONE_PFX "Halftone"
// #define SRVs_EDGE_WIDTH_TFX	"halftoneEdgeWidth"
#define SRVs_TILES_TFX    "halftoneTiles"
#define SRVs_COLOR_TFX    "halftoneColor"
#define SRVs_ALPHA_TFX    "halftoneAlpha"
#define SRVs_UVOFF_TFX    "halftoneCellOffset"
#define SRVs_ANGLE_TFX    "halftoneAngle"
#define SRVs_SEETHRU_TFX  "halftoneSeeThough"
#define SRVs_SHADOWS_TFX  "halftoneShadows"
#define SRVs_BRIGHT_TFX   "halftoneBright"
#define SRVs_CONTRAST_TFX "halftoneContrast"

    LXtTagInfoDesc HTonePFX::descInfo[] = { { LXsSRV_USERNAME, "Halftone Packet FX" },
                                            { LXsSRV_LOGSUBSYSTEM, "texture-effect" },
                                            { LXsTFX_CATEGORY, LXsSHADE_SURFACE },
                                            { nullptr } };

    LxResult HTonePFX::pfx_Packet(const char** packet)
    {
        packet[0] = SRVs_HTONE_VPACKET;
        return LXe_OK;
    }

    unsigned int HTonePFX::pfx_Count(void)
    {
        return 9;
    }

    LxResult HTonePFX::pfx_ByIndex(int id, const char** name, const char** typeName, int* type)
    {
        switch (id)
        {
            case 0:
                name[0]     = SRVs_UVOFF_TFX;
                type[0]     = LXi_TFX_SCALAR | LXf_TFX_READ | LXf_TFX_WRITE;
                typeName[0] = LXsTYPE_FLOAT;
                break;
            case 1:
                name[0]     = SRVs_COLOR_TFX;
                type[0]     = LXi_TFX_COLOR | LXf_TFX_READ | LXf_TFX_WRITE;
                typeName[0] = LXsTYPE_COLOR1;
                break;
            case 2:
                name[0]     = SRVs_TILES_TFX;
                type[0]     = LXi_TFX_SCALAR | LXf_TFX_READ | LXf_TFX_WRITE;
                typeName[0] = LXsTYPE_FLOAT;
                break;
            case 3:
                name[0]     = SRVs_ANGLE_TFX;
                type[0]     = LXi_TFX_SCALAR | LXf_TFX_READ | LXf_TFX_WRITE;
                typeName[0] = LXsTYPE_ANGLE;
                break;
            case 4:
                name[0]     = SRVs_SEETHRU_TFX;
                type[0]     = LXi_TFX_SCALAR | LXf_TFX_READ | LXf_TFX_WRITE;
                typeName[0] = LXsTYPE_PERCENT;
                break;
            case 5:
                name[0]     = SRVs_SHADOWS_TFX;
                type[0]     = LXi_TFX_SCALAR | LXf_TFX_READ | LXf_TFX_WRITE;
                typeName[0] = LXsTYPE_PERCENT;
                break;
            case 6:
                name[0]     = SRVs_ALPHA_TFX;
                type[0]     = LXi_TFX_SCALAR | LXf_TFX_READ | LXf_TFX_WRITE;
                typeName[0] = LXsTYPE_PERCENT;
                break;
            case 7:
                name[0]     = SRVs_BRIGHT_TFX;
                type[0]     = LXi_TFX_SCALAR | LXf_TFX_READ | LXf_TFX_WRITE;
                typeName[0] = LXsTYPE_PERCENT;
                break;
            case 8:
                name[0]     = SRVs_CONTRAST_TFX;
                type[0]     = LXi_TFX_SCALAR | LXf_TFX_READ | LXf_TFX_WRITE;
                typeName[0] = LXsTYPE_PERCENT;
                break;
        }

        return LXe_OK;
    }

    LxResult HTonePFX::pfx_Get(int id, void* packet, float* val, void* /*item*/)
    {
        LXpHalftone* csp = (LXpHalftone*) packet;

        switch (id)
        {
            case 0:
                val[0] = csp->uvOffset;
                break;
            case 1:
                val[0] = csp->patColor[0];
                val[1] = csp->patColor[1];
                val[2] = csp->patColor[2];
                break;
            case 2:
                val[0] = csp->tiles;
                break;
            case 3:
                val[0] = csp->angle;
                break;
            case 4:
                val[0] = csp->seeThru;
                break;
            case 5:
                val[0] = csp->shadows;
                break;
            case 6:
                val[0] = csp->patAlpha;
                break;
            case 7:
                val[0] = csp->brightness;
                break;
            case 8:
                val[0] = csp->contrast;
                break;
        }

        return LXe_OK;
    }
    LxResult HTonePFX::pfx_Set(int id, void* packet, const float* val, void* /*item*/)
    {
        LXpHalftone* csp = (LXpHalftone*) packet;

        switch (id)
        {
            case 0:
                csp->uvOffset = val[0];
                break;
            case 1:
                csp->patColor[0] = val[0];
                csp->patColor[1] = val[1];
                csp->patColor[2] = val[2];
                break;
            case 2:
                csp->tiles = val[0];
                break;
            case 3:
                csp->angle = val[0];
                csp->sinA  = sin(csp->angle);
                csp->cosA  = cos(csp->angle);
                break;
            case 4:
                csp->seeThru = val[0];
                break;
            case 5:
                csp->shadows = val[0];
                break;
            case 6:
                csp->patAlpha = val[0];
                break;
            case 7:
                csp->brightness = val[0];
                break;
            case 8:
                csp->contrast = val[0];
                break;
        }

        return LXe_OK;
    }

    void initialize()
    {
        CLxGenericPolymorph* srv1 = new CLxPolymorph<HalftoneMaterial>;
        CLxGenericPolymorph* srv2 = new CLxPolymorph<HalftonePacket>;
        CLxGenericPolymorph* srv3 = new CLxPolymorph<HTonePFX>;

        srv1->AddInterface(new CLxIfc_CustomMaterial<HalftoneMaterial>);
        srv1->AddInterface(new CLxIfc_ChannelUI<HalftoneMaterial>);
        srv1->AddInterface(new CLxIfc_StaticDesc<HalftoneMaterial>);
        lx::AddServer(SRVs_HTONE_MATR, srv1);

        srv2->AddInterface(new CLxIfc_VectorPacket<HalftonePacket>);
        srv2->AddInterface(new CLxIfc_StaticDesc<HalftonePacket>);
        lx::AddServer(SRVs_HTONE_VPACKET, srv2);

        srv3->AddInterface(new CLxIfc_PacketEffect<HTonePFX>);
        srv3->AddInterface(new CLxIfc_StaticDesc<HTonePFX>);
        lx::AddServer(SRVs_HTONE_PFX, srv3);
    }

};  // namespace Halftone_Shader
