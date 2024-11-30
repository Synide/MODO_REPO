/*
 * Plug-in component shader: cel shader
 *
 *   Copyright 0000
 */
#include <lxu_shade.hpp>

// -------------------- START REPLACEMENT

#include <lx_action.hpp>
#include <lx_channelui.hpp>
#include <lx_item.hpp>
#include <lx_log.hpp>
#include <lx_package.hpp>
#include <lx_raycast.hpp>
#include <lx_shdr.hpp>
#include <lx_tableau.hpp>
#include <lx_value.hpp>
#include <lx_vector.hpp>
#include <lxcommand.h>
#include <lxidef.h>

#include <cmath>
#include <string>

/*
 * Names
 */
#define SRVs_CEL_VPACKET "cel.packet"
#define LXsP_SAMPLE_CEL  SRVs_CEL_VPACKET

#define SRVs_REFL_TFX "celReflLevel"
#define SRVs_DIFF_TFX "celDiffLevel"
#define SRVs_SPEC_TFX "celSpecLevel"

// -------------------- START METACLASS CODE

/*
 * Our custom packet struct. The class template derives from this and implements
 * code to manipulate it.
 */
typedef struct st_LXpCelCM
{
    float diffLevel;
    float specLevel;
    float reflLevel;
} LXpCelCM;

class CPacket : public CLxVectorPacket<LXpCelCM>
{
public:
    void define_effects() override
    {
        LXpCelCM* csp = nullptr;

        add_effect(SRVs_DIFF_TFX, LXsTYPE_PERCENT);
        struct_offset(&csp->diffLevel);

        add_effect(SRVs_SPEC_TFX, LXsTYPE_PERCENT);
        struct_offset(&csp->specLevel);

        add_effect(SRVs_REFL_TFX, LXsTYPE_PERCENT);
        struct_offset(&csp->reflLevel);
    }

    void init(LXpCelCM* csp) override
    {
        csp->diffLevel = 0.5;
        csp->specLevel = 0.5;
        csp->reflLevel = 0.5;
    }
};

class CChannels : public CLxChannels
{
public:
    int    cv_diff_bands;
    int    cv_spec_bands;
    int    cv_refl_bands;
    double cv_diff_level;
    double cv_spec_level;
    double cv_refl_level;

    void add_bands(CLxAttributeDesc& desc, const char* name, int* offset)
    {
        desc.add(name, LXsTYPE_INTEGER);
        desc.default_val(3);
        desc.struct_offset(offset);
        desc.eval_flag(LXfECHAN_READ);
    }

    void add_level(CLxAttributeDesc& desc, const char* name, double* offset)
    {
        desc.add(name, LXsTYPE_PERCENT);
        desc.default_val(0.5);
        desc.struct_offset(offset);
        desc.eval_flag(LXfECHAN_READ);
        desc.nodal_input();
    }

    void init_chan(CLxAttributeDesc& desc) override
    {
        CChannels* chan = nullptr;

        add_bands(desc, "diffBands", &chan->cv_diff_bands);
        add_bands(desc, "specBands", &chan->cv_spec_bands);
        add_bands(desc, "reflBands", &chan->cv_refl_bands);

        add_level(desc, "diffLevel", &chan->cv_diff_level);
        add_level(desc, "specLevel", &chan->cv_spec_level);
        add_level(desc, "reflLevel", &chan->cv_refl_level);
    }
};

static CLxMetaRoot                   root_meta;
static CLxMeta_VectorPacket<CPacket> pkt_meta(SRVs_CEL_VPACKET);
static CLxMeta_Channels<CChannels>   chan_meta;

static void PacketServerInit()
{
    pkt_meta.add_tag(LXsSRV_USERNAME, "CelCM Packet");

    root_meta.add(&pkt_meta);
    root_meta.add(&chan_meta);
    root_meta.initialize();
}

// -------------------- OLD CODE RESUMES

/*
 * Cel material & shader
 * The cel shader is implemented as a custom material. Custom materials have the ability to set material attributes
 * and to contribute to shading after the base shader has been evaluated
 */
class CelMaterial : public CLxImpl_CustomMaterial, public CLxImpl_ChannelUI
{
public:
    CelMaterial()
    {
    }

    static LXtTagInfoDesc descInfo[];

    int      cmt_Flags() override;
    LxResult cmt_SetupChannels(ILxUnknownID addChan) override;
    LxResult cmt_LinkChannels(ILxUnknownID eval, ILxUnknownID item) override;
    LxResult cmt_ReadChannels(ILxUnknownID attr, void** ppvData) override;
    LxResult cmt_CustomPacket(const char**) override;
    void     cmt_MaterialEvaluate(ILxUnknownID etor, int* idx, ILxUnknownID vector, void* data) override;
    void     cmt_ShaderEvaluate(ILxUnknownID vector, ILxUnknownID rayObj, LXpShadeComponents* sCmp, LXpShadeOutput* sOut, void* data) override;
    void     cmt_Cleanup(void* data) override;

    LxResult cmt_SetOpaque(int* opaque) override;

    LxResult cui_UIHints(const char* channelName, ILxUnknownID hints) override;

    LXtItemType MyType();

    LXtItemType my_type;
    unsigned    pkt_offset;

    LXtSampleIndex        samp_idx[6];  // indices to each data channel in RendData
    int                   cmt_IsSampleDriven(int* idx) override;
    LxResult              cmt_LinkSampleChannels(ILxUnknownID eval, ILxUnknownID item, int* idx) override;
    CLxUser_NodalService  nodalSvc;
    CLxUser_PacketService pkt_service;

    class RendData
    {
    public:
        int   diffBands;
        int   specBands;
        int   reflBands;
        float diffLevel, specLevel, reflLevel;
    };
};

#define SRVs_CEL_MATR          "celShader"
#define SRVs_CEL_MATR_ITEMTYPE "material." SRVs_CEL_MATR

LXtTagInfoDesc CelMaterial::descInfo[] = { { LXsSRV_USERNAME, "Cel Material" }, { LXsSRV_LOGSUBSYSTEM, "comp-shader" }, { nullptr } };

/*
 * clean up render data
 */
void CelMaterial::cmt_Cleanup(void* data)
{
    RendData* rd = static_cast<RendData*>(data);

    delete rd;
}

/*
 * Setup channels for the item type.
 */
int CelMaterial::cmt_Flags()
{
    return 0;
}

LxResult CelMaterial::cmt_SetupChannels(ILxUnknownID addChan)
{
    CLxUser_AddChannel ac(addChan);

    ac.NewChannel("diffBands", LXsTYPE_INTEGER);
    ac.SetDefault(0.0, 3);

    ac.NewChannel("specBands", LXsTYPE_INTEGER);
    ac.SetDefault(0.0, 0);

    ac.NewChannel("reflBands", LXsTYPE_INTEGER);
    ac.SetDefault(0.0, 0);

    ac.NewChannel("diffLevel", LXsTYPE_PERCENT);
    ac.SetDefault(0.50, 0);

    ac.NewChannel("specLevel", LXsTYPE_PERCENT);
    ac.SetDefault(0.50, 0);

    ac.NewChannel("reflLevel", LXsTYPE_PERCENT);
    ac.SetDefault(0.50, 0);

    return LXe_OK;
}

/*
 * Attach to channel evaluations.
 * This gets the indices for the channels in attributes.
 */
LxResult CelMaterial::cmt_LinkChannels(ILxUnknownID eval, ILxUnknownID item)
{
    CLxUser_Evaluation ev(eval);
    int                i = 0;
    CLxUser_Item       it(item);

    samp_idx[i++].chan = it.ChannelIndex("diffBands");
    samp_idx[i++].chan = it.ChannelIndex("specBands");
    samp_idx[i++].chan = it.ChannelIndex("reflBands");
    samp_idx[i++].chan = it.ChannelIndex("diffLevel");
    samp_idx[i++].chan = it.ChannelIndex("specLevel");
    samp_idx[i++].chan = it.ChannelIndex("reflLevel");

    i                 = 0;
    samp_idx[i].layer = ev.AddChan(item, samp_idx[i].chan);
    i++;  //"diffBands"
    samp_idx[i].layer = ev.AddChan(item, samp_idx[i].chan);
    i++;  //"specBands"
    samp_idx[i].layer = ev.AddChan(item, samp_idx[i].chan);
    i++;  //"reflBands"
    samp_idx[i].layer = ev.AddChan(item, samp_idx[i].chan);
    i++;  //"diffLevel"
    samp_idx[i].layer = ev.AddChan(item, samp_idx[i].chan);
    i++;  //"specLevel"
    samp_idx[i].layer = ev.AddChan(item, samp_idx[i].chan);
    i++;  //"reflLevel"

    pkt_offset = pkt_service.GetOffset(LXsCATEGORY_SAMPLE, LXsP_SAMPLE_CEL);

    return LXe_OK;
}

LxResult CelMaterial::cmt_LinkSampleChannels(ILxUnknownID eval, ILxUnknownID item, int* idx)
{
    CLxUser_Evaluation ev(eval);
    int                i = 3;  // skip band counts
    // the index of any channel that is not driven will be set to LXiNODAL_NOT_DRIVEN
    nodalSvc.AddSampleChan(eval, item, samp_idx[i++].chan, idx, LXfECHAN_READ);  //"diffLevel
    nodalSvc.AddSampleChan(eval, item, samp_idx[i++].chan, idx, LXfECHAN_READ);  //"specLevel
    nodalSvc.AddSampleChan(eval, item, samp_idx[i++].chan, idx, LXfECHAN_READ);  //"reflLevel
    return LXe_OK;
}

int CelMaterial::cmt_IsSampleDriven(int* idx)
{
    return nodalSvc.AnyDrivenChans(&idx[samp_idx[3].chan], 3);
}

/*
 * Read channel values which may have changed.
 */
LxResult CelMaterial::cmt_ReadChannels(ILxUnknownID attr, void** ppvData)
{
    CLxUser_Attributes at(attr);
    RendData*          rd = new RendData;

    int i = 0;

    rd->diffBands = at.Int(samp_idx[i++].layer);
    rd->specBands = at.Int(samp_idx[i++].layer);
    rd->reflBands = at.Int(samp_idx[i++].layer);

    rd->diffLevel = static_cast<float>(at.Float(samp_idx[i++].layer));
    rd->specLevel = static_cast<float>(at.Float(samp_idx[i++].layer));
    rd->reflLevel = static_cast<float>(at.Float(samp_idx[i++].layer));

    ppvData[0] = rd;
    return LXe_OK;
}

static float FVectorNormalize(LXtFVector v)
{
    float m, p;
    m = LXx_VDOT(v, v);
    if (m <= 0)
        return -1;
    m = sqrt(m);
    p = 1.f / m;
    LXx_VSCL(v, p);
    return m;
}

static void FVectorQuantize(LXtFVector vec, int bnd, float level)
{
    float vec0[3], len;
    int   i;

    LXx_VCPY(vec0, vec);
    len = FVectorNormalize(vec0);

    for (i = 0; i < 3; i++)
        vec[i] = vec0[i] * (floor(len * (bnd - 1)) + level) / static_cast<float>(bnd);
}

/*
 * Since the cel shader is modifying the results of another shader,
 * it cannot be opaque.
 */

LxResult CelMaterial::cmt_SetOpaque(int* opaque)
{
    *opaque = 0;

    return LXe_OK;
}

LxResult CelMaterial::cmt_CustomPacket(const char** packet)
{
    packet[0] = LXsP_SAMPLE_CEL;
    return LXe_OK;
}

/*
 * Set custom material values at a spot
 */
void CelMaterial::cmt_MaterialEvaluate(ILxUnknownID etor, int* idx, ILxUnknownID vector, void* data)
{
    LXpCelCM* celPkt = static_cast<LXpCelCM*>(pkt_service.FastPacket(vector, pkt_offset));
    RendData* rd     = static_cast<RendData*>(data);

    celPkt->diffLevel = static_cast<float>(nodalSvc.GetFloat(etor, idx, samp_idx[3].chan, rd->diffLevel));
    celPkt->specLevel = static_cast<float>(nodalSvc.GetFloat(etor, idx, samp_idx[4].chan, rd->specLevel));
    celPkt->reflLevel = static_cast<float>(nodalSvc.GetFloat(etor, idx, samp_idx[5].chan, rd->reflLevel));
}

/*
 * Evaluate the color at a spot.
 */
void CelMaterial::cmt_ShaderEvaluate(ILxUnknownID vector, ILxUnknownID /*rayObj*/, LXpShadeComponents* sCmp, LXpShadeOutput* sOut, void* data)
{
    LXpCelCM* celPkt = static_cast<LXpCelCM*>(pkt_service.FastPacket(vector, pkt_offset));
    RendData* rd     = static_cast<RendData*>(data);

    /*
     * Quantize each component with the bands and level settings
     */

    if (rd->diffBands)
        FVectorQuantize(sCmp->diff, rd->diffBands, celPkt->diffLevel);
    if (rd->specBands)
        FVectorQuantize(sCmp->spec, rd->specBands, celPkt->specLevel);
    if (rd->reflBands)
        FVectorQuantize(sCmp->refl, rd->reflBands, celPkt->reflLevel);

    // Update final output color
    for (int i = 0; i < 3; i++)
        sOut->color[i] = sCmp->diff[i] + sCmp->spec[i] + sCmp->refl[i] + sCmp->tran[i] + sCmp->subs[i] + sCmp->lumi[i];
}

LxResult CelMaterial::cui_UIHints(const char* channelName, ILxUnknownID hints)
{
    if (!strcmp(channelName, "diffLevel") || !strcmp(channelName, "diffBands"))
    {
        CLxUser_UIHints ui(hints);
        ui.ChannelFlags(LXfUIHINTCHAN_SUGGESTED);
        return LXe_OK;
    }

    return LXe_NOTIMPL;
}

/*
 * Utility to get the type code for this item type, as needed.
 */
LXtItemType CelMaterial::MyType()
{
    if (my_type != LXiTYPE_NONE)
        return my_type;

    CLxUser_SceneService svc;

    my_type = svc.ItemType(SRVs_CEL_MATR_ITEMTYPE);
    return my_type;
}

namespace celshader
{
    void initialize()
    {
        PacketServerInit();

        CLxGenericPolymorph* srv1 = new CLxPolymorph<CelMaterial>;
        srv1->AddInterface(new CLxIfc_CustomMaterial<CelMaterial>);
        srv1->AddInterface(new CLxIfc_StaticDesc<CelMaterial>);
        lx::AddServer(SRVs_CEL_MATR, srv1);
    }
}  // namespace celshader
