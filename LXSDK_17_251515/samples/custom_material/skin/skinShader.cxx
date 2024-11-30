/*
 * Plug-in component shader: Skin Shader
 * This shader essentially layers a bunch of modo shaders together, simplifying
 * the process of setting up an appropriate skin shader. It also makes it much
 * easier to ensure energy conservation.
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
#include <cstdlib>
#include <string>

#define CLAMP(value, low, high) (((value) < (low)) ? (low) : (((value) > (high)) ? (high) : (value)))

/* -------------------------------------------------------------------------
 *
 * Vector Packet definition: SkinShader Packet
 *
 * ------------------------------------------------------------------------- */

class SkinPacket : public CLxImpl_VectorPacket
{
public:
    SkinPacket()
    {
    }

    static LXtTagInfoDesc descInfo[];

    unsigned int   vpkt_Size() override;
    const LXtGUID* vpkt_Interface(void) override;
    LxResult       vpkt_Initialize(void* packet) override;
    LxResult       vpkt_Blend(void* packet, void* p0, void* p1, float t, int mode) override;
    LxResult       vpkt_Copy(void* packet, void* from) override;
};

#define SRVs_SKIN_VPACKET      "skin.shader.packet"
#define LXsP_SAMPLE_SKINSHADER SRVs_SKIN_VPACKET

LXtTagInfoDesc SkinPacket::descInfo[] = { { LXsSRV_USERNAME, "Skin Shader Packet" },
                                          { LXsSRV_LOGSUBSYSTEM, "vector-packet" },
                                          { LXsVPK_CATEGORY, LXsCATEGORY_SAMPLE },
                                          { nullptr } };

class SkinMaterialData
{
public:
    SkinMaterialData()
    {
        physical      = 1;
        matchSpec     = 0;
        oilBlurRefl   = 0;
        dermColorDist = 0;
        subColorDist  = 0;
        reflRays      = 0;
        sssRays       = 0;
    }

    int physical;

    LXtFVector oilSpecColor;
    float      oilSpecAmt;
    float      oilSpecFres;
    float      oilRoughness;

    int        matchSpec;
    LXtFVector oilReflColor;
    float      oilReflAmt;
    float      oilReflFres;
    int        oilBlurRefl;

    LXtFVector epiDiffColor;
    float      epiDiffAmt;
    float      epiDiffRoughness;

    LXtFVector epiSSSColor;
    float      epiSSSAmt;
    float      epiSSSDist;
    float      epiSSSDepth;
    float      epiSSSBias;

    LXtFVector dermSSSColor;
    float      dermSSSAmt;
    float      dermSSSDist;
    float      dermSSSDepth;
    float      dermSSSBias;
    int        dermColorDist;
    float      dermRedDist;
    float      dermGreenDist;
    float      dermBlueDist;

    LXtFVector subSSSColor;
    float      subSSSAmt;
    float      subSSSDist;
    float      subSSSDepth;
    float      subSSSBias;
    int        subColorDist;
    float      subRedDist;
    float      subGreenDist;
    float      subBlueDist;

    int reflRays;
    int sssRays;

    int sameSurface;
};

typedef LXtSampleIndex LXtSampIndVector[LXdND];
struct SkinMaterialDataSampleIndex
{
    LXtSampleIndex physical;

    LXtSampIndVector oilSpecColor;
    LXtSampleIndex   oilSpecAmt;
    LXtSampleIndex   oilSpecFres;
    LXtSampleIndex   oilRoughness;

    LXtSampleIndex   matchSpec;
    LXtSampIndVector oilReflColor;
    LXtSampleIndex   oilReflAmt;
    LXtSampleIndex   oilReflFres;
    LXtSampleIndex   oilBlurRefl;

    LXtSampIndVector epiDiffColor;
    LXtSampleIndex   epiDiffAmt;
    LXtSampleIndex   epiDiffRoughness;

    LXtSampIndVector epiSSSColor;
    LXtSampleIndex   epiSSSAmt;
    LXtSampleIndex   epiSSSDist;
    LXtSampleIndex   epiSSSDepth;
    LXtSampleIndex   epiSSSBias;

    LXtSampIndVector dermSSSColor;
    LXtSampleIndex   dermSSSAmt;
    LXtSampleIndex   dermSSSDist;
    LXtSampleIndex   dermSSSDepth;
    LXtSampleIndex   dermSSSBias;
    LXtSampleIndex   dermColorDist;
    LXtSampleIndex   dermRedDist;
    LXtSampleIndex   dermGreenDist;
    LXtSampleIndex   dermBlueDist;

    LXtSampIndVector subSSSColor;
    LXtSampleIndex   subSSSAmt;
    LXtSampleIndex   subSSSDist;
    LXtSampleIndex   subSSSDepth;
    LXtSampleIndex   subSSSBias;
    LXtSampleIndex   subColorDist;
    LXtSampleIndex   subRedDist;
    LXtSampleIndex   subGreenDist;
    LXtSampleIndex   subBlueDist;

    LXtSampleIndex reflRays;
    LXtSampleIndex sssRays;

    LXtSampleIndex sameSurface;

    LXtSampleIndex bumpAmp, dispDist;
};

typedef struct st_LXpSkinShader
{
    SkinMaterialData matrData;
} LXpSkinShader;

unsigned int SkinPacket::vpkt_Size(void)
{
    return sizeof(LXpSkinShader);
}

const LXtGUID* SkinPacket::vpkt_Interface(void)
{
    return nullptr;
}

LxResult SkinPacket::vpkt_Initialize(void* p)
{
    LXpSkinShader* ssp = (LXpSkinShader*) p;

    ssp->matrData.physical      = 1;
    ssp->matrData.matchSpec     = 0;
    ssp->matrData.oilBlurRefl   = 0;
    ssp->matrData.dermColorDist = 0;
    ssp->matrData.subColorDist  = 0;
    ssp->matrData.reflRays      = 0;
    ssp->matrData.sameSurface   = 1;
    ssp->matrData.sssRays       = 0;

    return LXe_OK;
}

LxResult SkinPacket::vpkt_Blend(void* p, void* p0, void* p1, float t, int mode)
{
    LXpSkinShader* ssp  = (LXpSkinShader*) p;
    LXpSkinShader* ssp0 = (LXpSkinShader*) p0;
    LXpSkinShader* ssp1 = (LXpSkinShader*) p1;

    bool decision;

    CLxLoc_ShaderService shdrSrv;

    /*
     * Do the boolean values first
     */

    decision = (int) (shdrSrv.ScalarBlendValue(1.0, 0.0, t, mode) + .5);

    ssp->matrData.physical      = (decision) ? ssp0->matrData.physical : ssp1->matrData.physical;
    ssp->matrData.matchSpec     = (decision) ? ssp0->matrData.matchSpec : ssp1->matrData.matchSpec;
    ssp->matrData.dermColorDist = (decision) ? ssp0->matrData.dermColorDist : ssp1->matrData.dermColorDist;
    ssp->matrData.subColorDist  = (decision) ? ssp0->matrData.subColorDist : ssp1->matrData.subColorDist;
    ssp->matrData.oilBlurRefl   = (decision) ? ssp0->matrData.oilBlurRefl : ssp1->matrData.oilBlurRefl;
    ssp->matrData.sameSurface   = (decision) ? ssp0->matrData.sameSurface : ssp1->matrData.sameSurface;

    /*
     * Do the color values
     */

    shdrSrv.ColorBlendValue(ssp->matrData.oilSpecColor, ssp0->matrData.oilSpecColor, ssp1->matrData.oilSpecColor, t, mode);
    shdrSrv.ColorBlendValue(ssp->matrData.oilReflColor, ssp0->matrData.oilReflColor, ssp1->matrData.oilReflColor, t, mode);
    shdrSrv.ColorBlendValue(ssp->matrData.epiDiffColor, ssp0->matrData.epiDiffColor, ssp1->matrData.epiDiffColor, t, mode);
    shdrSrv.ColorBlendValue(ssp->matrData.epiSSSColor, ssp0->matrData.epiSSSColor, ssp1->matrData.epiSSSColor, t, mode);

    /*
     * Finally do the floats
     */

    ssp->matrData.oilSpecAmt       = shdrSrv.ScalarBlendValue(ssp0->matrData.oilSpecAmt, ssp1->matrData.oilSpecAmt, t, mode);
    ssp->matrData.oilSpecFres      = shdrSrv.ScalarBlendValue(ssp0->matrData.oilSpecFres, ssp1->matrData.oilSpecFres, t, mode);
    ssp->matrData.oilRoughness     = shdrSrv.ScalarBlendValue(ssp0->matrData.oilRoughness, ssp1->matrData.oilRoughness, t, mode);
    ssp->matrData.oilReflAmt       = shdrSrv.ScalarBlendValue(ssp0->matrData.oilReflAmt, ssp1->matrData.oilReflAmt, t, mode);
    ssp->matrData.oilReflFres      = shdrSrv.ScalarBlendValue(ssp0->matrData.oilReflFres, ssp1->matrData.oilReflFres, t, mode);
    ssp->matrData.epiDiffAmt       = shdrSrv.ScalarBlendValue(ssp0->matrData.epiDiffAmt, ssp1->matrData.epiDiffAmt, t, mode);
    ssp->matrData.epiDiffRoughness = shdrSrv.ScalarBlendValue(ssp0->matrData.epiDiffRoughness, ssp1->matrData.epiDiffRoughness, t, mode);
    ssp->matrData.epiSSSAmt        = shdrSrv.ScalarBlendValue(ssp0->matrData.epiSSSAmt, ssp1->matrData.epiSSSAmt, t, mode);
    ssp->matrData.epiSSSDist       = shdrSrv.ScalarBlendValue(ssp0->matrData.epiSSSDist, ssp1->matrData.epiSSSDist, t, mode);
    ssp->matrData.epiSSSDepth      = shdrSrv.ScalarBlendValue(ssp0->matrData.epiSSSDepth, ssp1->matrData.epiSSSDepth, t, mode);
    ssp->matrData.epiSSSBias       = shdrSrv.ScalarBlendValue(ssp0->matrData.epiSSSBias, ssp1->matrData.epiSSSBias, t, mode);
    ssp->matrData.dermSSSAmt       = shdrSrv.ScalarBlendValue(ssp0->matrData.dermSSSAmt, ssp1->matrData.dermSSSAmt, t, mode);
    ssp->matrData.dermSSSDist      = shdrSrv.ScalarBlendValue(ssp0->matrData.dermSSSDist, ssp1->matrData.dermSSSDist, t, mode);
    ssp->matrData.dermSSSDepth     = shdrSrv.ScalarBlendValue(ssp0->matrData.dermSSSDepth, ssp1->matrData.dermSSSDepth, t, mode);
    ssp->matrData.dermSSSBias      = shdrSrv.ScalarBlendValue(ssp0->matrData.dermSSSBias, ssp1->matrData.dermSSSBias, t, mode);
    ssp->matrData.dermRedDist      = shdrSrv.ScalarBlendValue(ssp0->matrData.dermRedDist, ssp1->matrData.dermRedDist, t, mode);
    ssp->matrData.dermGreenDist    = shdrSrv.ScalarBlendValue(ssp0->matrData.dermGreenDist, ssp1->matrData.dermGreenDist, t, mode);
    ssp->matrData.dermBlueDist     = shdrSrv.ScalarBlendValue(ssp0->matrData.dermBlueDist, ssp1->matrData.dermBlueDist, t, mode);
    ssp->matrData.subSSSAmt        = shdrSrv.ScalarBlendValue(ssp0->matrData.subSSSAmt, ssp1->matrData.subSSSAmt, t, mode);
    ssp->matrData.subSSSDist       = shdrSrv.ScalarBlendValue(ssp0->matrData.subSSSDist, ssp1->matrData.subSSSDist, t, mode);
    ssp->matrData.subSSSDepth      = shdrSrv.ScalarBlendValue(ssp0->matrData.subSSSDepth, ssp1->matrData.subSSSDepth, t, mode);
    ssp->matrData.subSSSBias       = shdrSrv.ScalarBlendValue(ssp0->matrData.subSSSBias, ssp1->matrData.subSSSBias, t, mode);
    ssp->matrData.subRedDist       = shdrSrv.ScalarBlendValue(ssp0->matrData.subRedDist, ssp1->matrData.subRedDist, t, mode);
    ssp->matrData.subGreenDist     = shdrSrv.ScalarBlendValue(ssp0->matrData.subGreenDist, ssp1->matrData.subGreenDist, t, mode);
    ssp->matrData.subBlueDist      = shdrSrv.ScalarBlendValue(ssp0->matrData.subBlueDist, ssp1->matrData.subBlueDist, t, mode);

    ssp->matrData.reflRays = static_cast<int>(t * ssp0->matrData.reflRays + (1 - t) * ssp1->matrData.reflRays);
    ssp->matrData.sssRays  = static_cast<int>(t * ssp0->matrData.sssRays + (1 - t) * ssp1->matrData.sssRays);

    return LXe_OK;
}

LxResult SkinPacket::vpkt_Copy(void* packet, void* from)
{
    LXpSkinShader* sspDst = (LXpSkinShader*) packet;
    LXpSkinShader* sspSrc = (LXpSkinShader*) from;

    *sspDst = *sspSrc;

    return LXe_OK;
}

/* -------------------------------------------------------------------------
 *
 * Skin Material
 *
 * ------------------------------------------------------------------------- */

#define NUM_CHANNELS 53

class SkinMaterial : public CLxImpl_CustomMaterial, public CLxImpl_ChannelUI
{
public:
    SkinMaterial()
    {
        DISPLACEMENT_INDEX     = -1;
        channelsAreInitialized = 0;
    }

    static LXtTagInfoDesc descInfo[];

    /*
     *  Custom Material Interface
     */
    int      cmt_Flags() override;
    LxResult cmt_SetupChannels(ILxUnknownID addChan) override;
    LxResult cmt_LinkChannels(ILxUnknownID eval, ILxUnknownID item) override;
    LxResult cmt_ReadChannels(ILxUnknownID attr, void** ppvData) override;
    LxResult cmt_CustomPacket(const char**) override;
    void     cmt_MaterialEvaluate(ILxUnknownID etor, int* idx, ILxUnknownID vector, void* data) override;
    void     cmt_ShaderEvaluate(ILxUnknownID vector, ILxUnknownID rayObj, LXpShadeComponents* sCmp, LXpShadeOutput* sOut, void* data) override;
    void     cmt_Cleanup(void* data) override;
    LxResult cmt_SetBump(float* bumpAmp, int* clearBump) override;
    LxResult cmt_SetDisplacement(float* dispDist) override;
    LxResult cmt_SetSmoothing(double* smooth, double* angle, int* weighting, int* normalMethod, int* creasing) override;
    LxResult cmt_UpdatePreview(int chanIdx, int* flags) override;
    LxResult cmt_LinkSampleChannels(ILxUnknownID nodalEtor, ILxUnknownID item, int* idx) override;
    int      cmt_IsSampleDriven(int* idx) override;

    /*
     *  Channel UI Interface
     */
    LxResult cui_Enabled(const char* channelName, ILxUnknownID msg, ILxUnknownID item, ILxUnknownID read) override;

    LxResult cui_DependencyCount(const char* channelName, unsigned* count) override;

    LxResult cui_DependencyByIndex(const char* channelName, unsigned index, LXtItemType* depItemType, const char** depChannelName) override;

    LxResult ShadeLowerDermalLayer(ILxUnknownID        vector,
                                   CLxLoc_Raycast*     raycast,
                                   SkinMaterialData*   matrData,
                                   float*              energy,
                                   LXpShadeComponents* sCmp,
                                   LXpShadeComponents* sCmpOut,
                                   LXpSampleParms*     sampleParmsOut);
    LxResult ShadeUpperDermalLayer(ILxUnknownID        vector,
                                   CLxLoc_Raycast*     raycast,
                                   SkinMaterialData*   matrData,
                                   float*              energy,
                                   LXpShadeComponents* sCmp,
                                   LXpShadeComponents* sCmpOut,
                                   LXpSampleParms*     sampleParmsOut);
    LxResult ShadeEpidermalLayer(ILxUnknownID        vector,
                                 CLxLoc_Raycast*     raycast,
                                 SkinMaterialData*   matrData,
                                 float*              energy,
                                 LXpShadeComponents* sCmp,
                                 LXpShadeComponents* sCmpOut,
                                 LXpSampleParms*     sampleParmsOut);
    LxResult ShadeOilLayer(ILxUnknownID        vector,
                           CLxLoc_Raycast*     raycast,
                           SkinMaterialData*   matrData,
                           float*              energy,
                           LXpShadeComponents* sCmp,
                           LXpShadeComponents* sCmpOut,
                           LXpSampleParms*     sampleParmsOut);

    void ClearShader(LXpSampleParms* sParm);
    void ClearShadeComponents(LXpShadeComponents* sCmp);

    LXtItemType MyType();

    CLxUser_PacketService       pkt_service;
    CLxUser_NodalService        nodalSvc;
    SkinMaterialDataSampleIndex samplesIndex;

    unsigned parms_offset;
    unsigned ray_offset;
    unsigned nrm_offset;
    unsigned smth_offset;
    unsigned pkt_offset;

    LXtItemType my_type;

    int channelsAreInitialized;
    int DISPLACEMENT_INDEX;

    float bumpAmp, dispDist;
};

#define SRVs_SKIN_MATR          "skinMaterial"
#define SRVs_SKIN_MATR_ITEMTYPE "material." SRVs_SKIN_MATR

LXtTagInfoDesc SkinMaterial::descInfo[] = { { LXsSRV_USERNAME, "Skin Material" }, { LXsSRV_LOGSUBSYSTEM, "comp-shader" }, { nullptr } };

/*
 * Some useful utilities
 */
void SkinMaterial::ClearShader(LXpSampleParms* sParm)
{
    sParm->diffAmt = 0.0;
    sParm->specAmt = 0.0;
    sParm->reflAmt = 0.0;
    sParm->tranAmt = 0.0;
    sParm->subsAmt = 0.0;
    sParm->lumiAmt = 0.0;
    sParm->coatAmt = 0.0;
    sParm->dissAmt = 0.0;
}

void SkinMaterial::ClearShadeComponents(LXpShadeComponents* sCmp)
{
    LXx_VCLR(sCmp->diff);
    LXx_VCLR(sCmp->diffDir);
    LXx_VCLR(sCmp->diffInd);
    LXx_VCLR(sCmp->diffUns);
    LXx_VCLR(sCmp->spec);
    LXx_VCLR(sCmp->refl);
    LXx_VCLR(sCmp->tran);
    LXx_VCLR(sCmp->subs);
    LXx_VCLR(sCmp->lumi);
    LXx_VCLR(sCmp->illum);
    LXx_VCLR(sCmp->illumDir);
    LXx_VCLR(sCmp->illumInd);
    LXx_VCLR(sCmp->illumUns);
    LXx_VCLR(sCmp->volLum);
    LXx_VCLR(sCmp->volOpa);
}

int floatTest(float val)
{
    unsigned int n, exp, mant;
    union
    {
        float        f;
        unsigned int i;
    } u = { val };

    n   = u.i;
    exp = (n & 0x7F800000) >> 23;
    if (exp != 255)
        return 0;

    mant = (n & 0x007FFFFF);
    if (mant != 0)
        return -1;  // NAN
    else
        return +1;  // INFINITY
}

/*
 * Add all the channels to the skin material item
 */
const char* SUB_COLOR_DIST  = "subSSSColorDist";
const char* SUB_RED_DIST    = "subSSSRedDist";
const char* SUB_GREEN_DIST  = "subSSSGreenDist";
const char* SUB_BLUE_DIST   = "subSSSBlueDist";
const char* DERM_COLOR_DIST = "dermSSSColorDist";
const char* DERM_RED_DIST   = "dermSSSRedDist";
const char* DERM_GREEN_DIST = "dermSSSGreenDist";
const char* DERM_BLUE_DIST  = "dermSSSBlueDist";

int SkinMaterial::cmt_Flags()
{
    return 0;  // shader doesn't require any special behavior
}

LxResult SkinMaterial::cmt_SetupChannels(ILxUnknownID addChan)
{
    CLxUser_AddChannel ac(addChan);

    LXtVector white = { 1.0, 1.0, 1.0 };

    LXtVector epiColor    = { .98, .79, .68 };
    LXtVector epiSSSColor = { .98, .83, .74 };
    LXtVector dermColor   = { .98, .26, .2 };
    LXtVector subColor    = { .98, .03, .03 };

    ac.NewChannel("physical", LXsTYPE_BOOLEAN);
    ac.SetDefault(0, 1);

    ac.NewChannel("oilSpecColor", LXsTYPE_COLOR1);
    ac.SetVector(LXsCHANVEC_RGB);
    ac.SetDefaultVec(white);

    ac.NewChannel("oilSpecAmt", LXsTYPE_PERCENT);
    ac.SetDefault(.02, 0);

    ac.NewChannel("oilSpecFres", LXsTYPE_PERCENT);
    ac.SetDefault(1.0, 0);

    ac.NewChannel("oilRoughness", LXsTYPE_PERCENT);
    ac.SetDefault(.85, 0);

    ac.NewChannel("oilMatchSpec", LXsTYPE_BOOLEAN);  // 5
    ac.SetDefault(0, 0);

    ac.NewChannel("oilReflColor", LXsTYPE_COLOR1);
    ac.SetVector(LXsCHANVEC_RGB);
    ac.SetDefaultVec(white);

    ac.NewChannel("oilReflAmt", LXsTYPE_PERCENT);
    ac.SetDefault(0.01, 0);

    ac.NewChannel("oilReflFres", LXsTYPE_PERCENT);
    ac.SetDefault(1.0, 0);

    ac.NewChannel("oilBlurRefl", LXsTYPE_BOOLEAN);
    ac.SetDefault(0, 0);

    ac.NewChannel("epiDiffColor", LXsTYPE_COLOR1);
    ac.SetVector(LXsCHANVEC_RGB);
    ac.SetDefaultVec(epiColor);

    ac.NewChannel("epiDiffAmt", LXsTYPE_PERCENT);
    ac.SetDefault(.2, 0);

    ac.NewChannel("epiDiffRoughness", LXsTYPE_PERCENT);
    ac.SetDefault(0.0, 0);

    ac.NewChannel("epiSSSColor", LXsTYPE_COLOR1);
    ac.SetVector(LXsCHANVEC_RGB);
    ac.SetDefaultVec(epiSSSColor);

    ac.NewChannel("epiSSSAmt", LXsTYPE_PERCENT);
    ac.SetDefault(.4, 0);

    ac.NewChannel("epiSSSDist", LXsTYPE_DISTANCE);
    ac.SetDefault(.001, 0);

    ac.NewChannel("epiSSSDepth", LXsTYPE_DISTANCE);
    ac.SetDefault(.001, 0);

    ac.NewChannel("epiSSSBias", LXsTYPE_PERCENT);
    ac.SetDefault(.95, 0);

    ac.NewChannel("dermSSSColor", LXsTYPE_COLOR1);
    ac.SetVector(LXsCHANVEC_RGB);
    ac.SetDefaultVec(dermColor);

    ac.NewChannel("dermSSSAmt", LXsTYPE_PERCENT);
    ac.SetDefault(.4, 0);

    ac.NewChannel("dermSSSDist", LXsTYPE_DISTANCE);
    ac.SetDefault(.001, 0);

    ac.NewChannel(DERM_COLOR_DIST, LXsTYPE_BOOLEAN);
    ac.SetDefault(.0, 0);

    ac.NewChannel(DERM_RED_DIST, LXsTYPE_PERCENT);
    ac.SetDefault(1.0, 0);

    ac.NewChannel(DERM_GREEN_DIST, LXsTYPE_PERCENT);
    ac.SetDefault(.6, 0);

    ac.NewChannel(DERM_BLUE_DIST, LXsTYPE_PERCENT);
    ac.SetDefault(.4, 0);

    ac.NewChannel("dermSSSDepth", LXsTYPE_DISTANCE);
    ac.SetDefault(.0025, 0);

    ac.NewChannel("dermSSSBias", LXsTYPE_PERCENT);
    ac.SetDefault(.95, 0);

    ac.NewChannel("subSSSColor", LXsTYPE_COLOR1);
    ac.SetVector(LXsCHANVEC_RGB);
    ac.SetDefaultVec(subColor);

    ac.NewChannel("subSSSAmt", LXsTYPE_PERCENT);
    ac.SetDefault(1.0, 0);

    ac.NewChannel("subSSSDist", LXsTYPE_DISTANCE);
    ac.SetDefault(.003, 0);

    ac.NewChannel(SUB_COLOR_DIST, LXsTYPE_BOOLEAN);
    ac.SetDefault(0.0, 0);

    ac.NewChannel(SUB_RED_DIST, LXsTYPE_PERCENT);
    ac.SetDefault(1.0, 0);

    ac.NewChannel(SUB_GREEN_DIST, LXsTYPE_PERCENT);
    ac.SetDefault(.6, 0);

    ac.NewChannel(SUB_BLUE_DIST, LXsTYPE_PERCENT);
    ac.SetDefault(.4, 0);

    ac.NewChannel("subSSSDepth", LXsTYPE_DISTANCE);
    ac.SetDefault(.015, 0);

    ac.NewChannel("subSSSBias", LXsTYPE_PERCENT);
    ac.SetDefault(.2, 0);

    ac.NewChannel("bumpAmp", LXsTYPE_DISTANCE);
    ac.SetDefault(.005, 0);

    ac.NewChannel("reflRays", LXsTYPE_INTEGER);
    ac.SetDefault(0, 256);

    ac.NewChannel("sssRays", LXsTYPE_INTEGER);
    ac.SetDefault(0, 64);

    ac.NewChannel("dispDist", LXsTYPE_DISTANCE);
    ac.SetDefault(.02, 64);

    ac.NewChannel("sameSurface", LXsTYPE_BOOLEAN);
    ac.SetDefault(0, 0);

    return LXe_OK;
}

/*
 * Attach to channel evaluations.
 * This gets the indices for the channels in attributes.
 */
LxResult SkinMaterial::cmt_LinkChannels(ILxUnknownID eval, ILxUnknownID item)
{
    CLxUser_Evaluation ev(eval);
    CLxUser_Item       it(item);

    samplesIndex.physical.chan = it.ChannelIndex("physical");  // 0

    samplesIndex.oilSpecColor[0].chan = it.ChannelIndex("oilSpecColor.R");
    samplesIndex.oilSpecColor[1].chan = it.ChannelIndex("oilSpecColor.G");
    samplesIndex.oilSpecColor[2].chan = it.ChannelIndex("oilSpecColor.B");
    samplesIndex.oilSpecAmt.chan      = it.ChannelIndex("oilSpecAmt");
    samplesIndex.oilSpecFres.chan     = it.ChannelIndex("oilSpecFres");
    samplesIndex.oilRoughness.chan    = it.ChannelIndex("oilRoughness");  // 6

    samplesIndex.matchSpec.chan       = it.ChannelIndex("oilMatchSpec");
    samplesIndex.oilReflColor[0].chan = it.ChannelIndex("oilReflColor.R");
    samplesIndex.oilReflColor[1].chan = it.ChannelIndex("oilReflColor.G");
    samplesIndex.oilReflColor[2].chan = it.ChannelIndex("oilReflColor.B");
    samplesIndex.oilReflAmt.chan      = it.ChannelIndex("oilReflAmt");
    samplesIndex.oilReflFres.chan     = it.ChannelIndex("oilReflFres");  // 12
    samplesIndex.oilBlurRefl.chan     = it.ChannelIndex("oilBlurRefl");  // 13

    samplesIndex.epiDiffColor[0].chan  = it.ChannelIndex("epiDiffColor.R");
    samplesIndex.epiDiffColor[1].chan  = it.ChannelIndex("epiDiffColor.G");
    samplesIndex.epiDiffColor[2].chan  = it.ChannelIndex("epiDiffColor.B");
    samplesIndex.epiDiffAmt.chan       = it.ChannelIndex("epiDiffAmt");
    samplesIndex.epiDiffRoughness.chan = it.ChannelIndex("epiDiffRoughness");  // 18

    samplesIndex.epiSSSColor[0].chan = it.ChannelIndex("epiSSSColor.R");
    samplesIndex.epiSSSColor[1].chan = it.ChannelIndex("epiSSSColor.G");
    samplesIndex.epiSSSColor[2].chan = it.ChannelIndex("epiSSSColor.B");
    samplesIndex.epiSSSAmt.chan      = it.ChannelIndex("epiSSSAmt");
    samplesIndex.epiSSSDist.chan     = it.ChannelIndex("epiSSSDist");
    samplesIndex.epiSSSDepth.chan    = it.ChannelIndex("epiSSSDepth");
    samplesIndex.epiSSSBias.chan     = it.ChannelIndex("epiSSSBias");  // 25

    samplesIndex.dermSSSColor[0].chan = it.ChannelIndex("dermSSSColor.R");
    samplesIndex.dermSSSColor[1].chan = it.ChannelIndex("dermSSSColor.G");
    samplesIndex.dermSSSColor[2].chan = it.ChannelIndex("dermSSSColor.B");
    samplesIndex.dermSSSAmt.chan      = it.ChannelIndex("dermSSSAmt");
    samplesIndex.dermSSSDist.chan     = it.ChannelIndex("dermSSSDist");
    samplesIndex.dermColorDist.chan   = it.ChannelIndex(DERM_COLOR_DIST);
    samplesIndex.dermRedDist.chan     = it.ChannelIndex(DERM_RED_DIST);
    samplesIndex.dermGreenDist.chan   = it.ChannelIndex(DERM_GREEN_DIST);
    samplesIndex.dermBlueDist.chan    = it.ChannelIndex(DERM_BLUE_DIST);
    samplesIndex.dermSSSDepth.chan    = it.ChannelIndex("dermSSSDepth");
    samplesIndex.dermSSSBias.chan     = it.ChannelIndex("dermSSSBias");  // 36

    samplesIndex.subSSSColor[0].chan = it.ChannelIndex("subSSSColor.R");
    samplesIndex.subSSSColor[1].chan = it.ChannelIndex("subSSSColor.G");
    samplesIndex.subSSSColor[2].chan = it.ChannelIndex("subSSSColor.B");
    samplesIndex.subSSSAmt.chan      = it.ChannelIndex("subSSSAmt");
    samplesIndex.subSSSDist.chan     = it.ChannelIndex("subSSSDist");
    samplesIndex.subColorDist.chan   = it.ChannelIndex(SUB_COLOR_DIST);
    samplesIndex.subRedDist.chan     = it.ChannelIndex(SUB_RED_DIST);
    samplesIndex.subGreenDist.chan   = it.ChannelIndex(SUB_GREEN_DIST);
    samplesIndex.subBlueDist.chan    = it.ChannelIndex(SUB_BLUE_DIST);
    samplesIndex.subSSSDepth.chan    = it.ChannelIndex("subSSSDepth");
    samplesIndex.subSSSBias.chan     = it.ChannelIndex("subSSSBias");  // 47

    samplesIndex.bumpAmp.chan  = it.ChannelIndex("bumpAmp");   // 48
    samplesIndex.reflRays.chan = it.ChannelIndex("reflRays");  // 49
    samplesIndex.sssRays.chan  = it.ChannelIndex("sssRays");   // 50

    samplesIndex.dispDist.chan    = it.ChannelIndex("dispDist");  // 51
    samplesIndex.sameSurface.chan = it.ChannelIndex("sameSurface");

    samplesIndex.physical.layer = ev.AddChan(item, samplesIndex.physical.chan);  // 0

    samplesIndex.oilSpecColor[0].layer = ev.AddChan(item, samplesIndex.oilSpecColor[0].chan);
    samplesIndex.oilSpecColor[1].layer = ev.AddChan(item, samplesIndex.oilSpecColor[1].chan);
    samplesIndex.oilSpecColor[2].layer = ev.AddChan(item, samplesIndex.oilSpecColor[2].chan);
    samplesIndex.oilSpecAmt.layer      = ev.AddChan(item, samplesIndex.oilSpecAmt.chan);
    samplesIndex.oilSpecFres.layer     = ev.AddChan(item, samplesIndex.oilSpecFres.chan);
    samplesIndex.oilRoughness.layer    = ev.AddChan(item, samplesIndex.oilRoughness.chan);  // 6

    samplesIndex.matchSpec.layer       = ev.AddChan(item, samplesIndex.matchSpec.chan);
    samplesIndex.oilReflColor[0].layer = ev.AddChan(item, samplesIndex.oilReflColor[0].chan);
    samplesIndex.oilReflColor[1].layer = ev.AddChan(item, samplesIndex.oilReflColor[1].chan);
    samplesIndex.oilReflColor[2].layer = ev.AddChan(item, samplesIndex.oilReflColor[2].chan);
    samplesIndex.oilReflAmt.layer      = ev.AddChan(item, samplesIndex.oilReflAmt.chan);
    samplesIndex.oilReflFres.layer     = ev.AddChan(item, samplesIndex.oilReflFres.chan);  // 12
    samplesIndex.oilBlurRefl.layer     = ev.AddChan(item, samplesIndex.oilBlurRefl.chan);  // 13

    samplesIndex.epiDiffColor[0].layer  = ev.AddChan(item, samplesIndex.epiDiffColor[0].chan);
    samplesIndex.epiDiffColor[1].layer  = ev.AddChan(item, samplesIndex.epiDiffColor[1].chan);
    samplesIndex.epiDiffColor[2].layer  = ev.AddChan(item, samplesIndex.epiDiffColor[2].chan);
    samplesIndex.epiDiffAmt.layer       = ev.AddChan(item, samplesIndex.epiDiffAmt.chan);
    samplesIndex.epiDiffRoughness.layer = ev.AddChan(item, samplesIndex.epiDiffRoughness.chan);  // 18

    samplesIndex.epiSSSColor[0].layer = ev.AddChan(item, samplesIndex.epiSSSColor[0].chan);
    samplesIndex.epiSSSColor[1].layer = ev.AddChan(item, samplesIndex.epiSSSColor[1].chan);
    samplesIndex.epiSSSColor[2].layer = ev.AddChan(item, samplesIndex.epiSSSColor[2].chan);
    samplesIndex.epiSSSAmt.layer      = ev.AddChan(item, samplesIndex.epiSSSAmt.chan);
    samplesIndex.epiSSSDist.layer     = ev.AddChan(item, samplesIndex.epiSSSDist.chan);
    samplesIndex.epiSSSDepth.layer    = ev.AddChan(item, samplesIndex.epiSSSDepth.chan);
    samplesIndex.epiSSSBias.layer     = ev.AddChan(item, samplesIndex.epiSSSBias.chan);  // 25

    samplesIndex.dermSSSColor[0].layer = ev.AddChan(item, samplesIndex.dermSSSColor[0].chan);
    samplesIndex.dermSSSColor[1].layer = ev.AddChan(item, samplesIndex.dermSSSColor[1].chan);
    samplesIndex.dermSSSColor[2].layer = ev.AddChan(item, samplesIndex.dermSSSColor[2].chan);
    samplesIndex.dermSSSAmt.layer      = ev.AddChan(item, samplesIndex.dermSSSAmt.chan);
    samplesIndex.dermSSSDist.layer     = ev.AddChan(item, samplesIndex.dermSSSDist.chan);
    samplesIndex.dermColorDist.layer   = ev.AddChan(item, samplesIndex.dermColorDist.chan);
    samplesIndex.dermRedDist.layer     = ev.AddChan(item, samplesIndex.dermRedDist.chan);
    samplesIndex.dermGreenDist.layer   = ev.AddChan(item, samplesIndex.dermGreenDist.chan);
    samplesIndex.dermBlueDist.layer    = ev.AddChan(item, samplesIndex.dermBlueDist.chan);
    samplesIndex.dermSSSDepth.layer    = ev.AddChan(item, samplesIndex.dermSSSDepth.chan);
    samplesIndex.dermSSSBias.layer     = ev.AddChan(item, samplesIndex.dermSSSBias.chan);  // 36

    samplesIndex.subSSSColor[0].layer = ev.AddChan(item, samplesIndex.subSSSColor[0].chan);
    samplesIndex.subSSSColor[1].layer = ev.AddChan(item, samplesIndex.subSSSColor[1].chan);
    samplesIndex.subSSSColor[2].layer = ev.AddChan(item, samplesIndex.subSSSColor[2].chan);
    samplesIndex.subSSSAmt.layer      = ev.AddChan(item, samplesIndex.subSSSAmt.chan);
    samplesIndex.subSSSDist.layer     = ev.AddChan(item, samplesIndex.subSSSDist.chan);
    samplesIndex.subColorDist.layer   = ev.AddChan(item, samplesIndex.subColorDist.chan);
    samplesIndex.subRedDist.layer     = ev.AddChan(item, samplesIndex.subRedDist.chan);
    samplesIndex.subGreenDist.layer   = ev.AddChan(item, samplesIndex.subGreenDist.chan);
    samplesIndex.subBlueDist.layer    = ev.AddChan(item, samplesIndex.subBlueDist.chan);
    samplesIndex.subSSSDepth.layer    = ev.AddChan(item, samplesIndex.subSSSDepth.chan);
    samplesIndex.subSSSBias.layer     = ev.AddChan(item, samplesIndex.subSSSBias.chan);  // 47

    samplesIndex.bumpAmp.layer  = ev.AddChan(item, samplesIndex.bumpAmp.chan);   // 48
    samplesIndex.reflRays.layer = ev.AddChan(item, samplesIndex.reflRays.chan);  // 49
    samplesIndex.sssRays.layer  = ev.AddChan(item, samplesIndex.sssRays.chan);   // 50

    samplesIndex.dispDist.layer    = ev.AddChan(item, samplesIndex.dispDist.chan);     // 51
    samplesIndex.sameSurface.layer = ev.AddChan(item, samplesIndex.sameSurface.chan);  // 0

    parms_offset = pkt_service.GetOffset(LXsCATEGORY_SAMPLE, LXsP_SAMPLE_PARMS);
    ray_offset   = pkt_service.GetOffset(LXsCATEGORY_SAMPLE, LXsP_SAMPLE_RAY);
    nrm_offset   = pkt_service.GetOffset(LXsCATEGORY_SAMPLE, LXsP_SURF_NORMAL);
    pkt_offset   = pkt_service.GetOffset(LXsCATEGORY_SAMPLE, LXsP_SAMPLE_SKINSHADER);

    channelsAreInitialized = 1;

    return LXe_OK;
}

/*
 * Read channel values which may have changed.
 */
LxResult SkinMaterial::cmt_ReadChannels(ILxUnknownID attr, void** ppvData)
{
    CLxUser_Attributes at(attr);
    SkinMaterialData*  md = new SkinMaterialData;

    // int			index = 0;

    md->physical = at.Int(samplesIndex.physical.layer);  // 0

    md->oilSpecColor[0] = static_cast<float>(at.Float(samplesIndex.oilSpecColor[0].layer));
    md->oilSpecColor[1] = static_cast<float>(at.Float(samplesIndex.oilSpecColor[1].layer));
    md->oilSpecColor[2] = static_cast<float>(at.Float(samplesIndex.oilSpecColor[2].layer));
    md->oilSpecAmt      = static_cast<float>(at.Float(samplesIndex.oilSpecAmt.layer));
    md->oilSpecFres     = static_cast<float>(at.Float(samplesIndex.oilSpecFres.layer));
    md->oilRoughness    = static_cast<float>(at.Float(samplesIndex.oilRoughness.layer));  // 6

    md->matchSpec = at.Int(samplesIndex.matchSpec.layer);

    md->oilReflColor[0] = static_cast<float>(at.Float(samplesIndex.oilReflColor[0].layer));
    md->oilReflColor[1] = static_cast<float>(at.Float(samplesIndex.oilReflColor[1].layer));
    md->oilReflColor[2] = static_cast<float>(at.Float(samplesIndex.oilReflColor[2].layer));
    md->oilReflAmt      = static_cast<float>(at.Float(samplesIndex.oilReflAmt.layer));
    md->oilReflFres     = static_cast<float>(at.Float(samplesIndex.oilReflFres.layer));
    md->oilBlurRefl     = at.Int(samplesIndex.oilBlurRefl.layer);

    md->epiDiffColor[0]  = static_cast<float>(at.Float(samplesIndex.epiDiffColor[0].layer));
    md->epiDiffColor[1]  = static_cast<float>(at.Float(samplesIndex.epiDiffColor[1].layer));
    md->epiDiffColor[2]  = static_cast<float>(at.Float(samplesIndex.epiDiffColor[2].layer));
    md->epiDiffAmt       = static_cast<float>(at.Float(samplesIndex.epiDiffAmt.layer));
    md->epiDiffRoughness = static_cast<float>(at.Float(samplesIndex.epiDiffRoughness.layer));  // 18

    md->epiSSSColor[0] = static_cast<float>(at.Float(samplesIndex.epiSSSColor[0].layer));
    md->epiSSSColor[1] = static_cast<float>(at.Float(samplesIndex.epiSSSColor[1].layer));
    md->epiSSSColor[2] = static_cast<float>(at.Float(samplesIndex.epiSSSColor[2].layer));
    md->epiSSSAmt      = static_cast<float>(at.Float(samplesIndex.epiSSSAmt.layer));
    md->epiSSSDist     = static_cast<float>(at.Float(samplesIndex.epiSSSDist.layer));
    md->epiSSSDepth    = static_cast<float>(at.Float(samplesIndex.epiSSSDepth.layer));
    md->epiSSSBias     = static_cast<float>(at.Float(samplesIndex.epiSSSBias.layer));  // 25

    md->dermSSSColor[0] = static_cast<float>(at.Float(samplesIndex.dermSSSColor[0].layer));
    md->dermSSSColor[1] = static_cast<float>(at.Float(samplesIndex.dermSSSColor[1].layer));
    md->dermSSSColor[2] = static_cast<float>(at.Float(samplesIndex.dermSSSColor[2].layer));
    md->dermSSSAmt      = static_cast<float>(at.Float(samplesIndex.dermSSSAmt.layer));
    md->dermSSSDist     = static_cast<float>(at.Float(samplesIndex.dermSSSDist.layer));
    md->dermColorDist   = at.Int(samplesIndex.dermColorDist.layer);
    md->dermRedDist     = static_cast<float>(at.Float(samplesIndex.dermRedDist.layer));
    md->dermGreenDist   = static_cast<float>(at.Float(samplesIndex.dermGreenDist.layer));
    md->dermBlueDist    = static_cast<float>(at.Float(samplesIndex.dermBlueDist.layer));
    md->dermSSSDepth    = static_cast<float>(at.Float(samplesIndex.dermSSSDepth.layer));
    md->dermSSSBias     = static_cast<float>(at.Float(samplesIndex.dermSSSBias.layer));  // 36

    md->subSSSColor[0] = static_cast<float>(at.Float(samplesIndex.subSSSColor[0].layer));
    md->subSSSColor[1] = static_cast<float>(at.Float(samplesIndex.subSSSColor[1].layer));
    md->subSSSColor[2] = static_cast<float>(at.Float(samplesIndex.subSSSColor[2].layer));
    md->subSSSAmt      = static_cast<float>(at.Float(samplesIndex.subSSSAmt.layer));
    md->subSSSDist     = static_cast<float>(at.Float(samplesIndex.subSSSDist.layer));
    md->subColorDist   = at.Int(samplesIndex.subColorDist.layer);
    md->subRedDist     = static_cast<float>(at.Float(samplesIndex.subRedDist.layer));
    md->subGreenDist   = static_cast<float>(at.Float(samplesIndex.subGreenDist.layer));
    md->subBlueDist    = static_cast<float>(at.Float(samplesIndex.subBlueDist.layer));
    md->subSSSDepth    = static_cast<float>(at.Float(samplesIndex.subSSSDepth.layer));
    md->subSSSBias     = static_cast<float>(at.Float(samplesIndex.subSSSBias.layer));  // 47

    this->bumpAmp = static_cast<float>(at.Float(samplesIndex.bumpAmp.layer));  // 48

    md->reflRays = at.Int(samplesIndex.reflRays.layer);  // 49
    md->sssRays  = at.Int(samplesIndex.sssRays.layer);   // 50

    this->dispDist = static_cast<float>(at.Float(samplesIndex.dispDist.layer));  // 51

    md->sameSurface = at.Int(samplesIndex.sameSurface.layer);

    // This is to make sure we don't go out of bounds
    // if (index > NUM_CHANNELS)
    //        abort();

    ppvData[0] = md;
    return LXe_OK;
}

LxResult SkinMaterial::cmt_CustomPacket(const char** packet)
{
    packet[0] = LXsP_SAMPLE_SKINSHADER;
    return LXe_OK;
}
/*
 * Channel UI Functions
 */
const char* SKIN_MATERIAL_MSG_TABLE = "material.skinMaterial";

const unsigned SKIN_MATERIAL_PER_COLOR_SCATTERING_MSG = 1001;

LxResult SkinMaterial::cui_Enabled(const char* channelName, ILxUnknownID msg, ILxUnknownID item, ILxUnknownID read)
{
    CLxUser_ChannelRead chan(read);
    CLxUser_Item        src(item);
    LxResult            result = LXe_OK;

    if ((strcmp(channelName, SUB_RED_DIST) == 0) || (strcmp(channelName, SUB_GREEN_DIST) == 0) || (strcmp(channelName, SUB_BLUE_DIST) == 0))
    {
        int perColorDist = chan.IValue(src, SUB_COLOR_DIST);

        if (!perColorDist)
        {
            CLxUser_Message res(msg);

            res.SetCode(LXe_CMD_DISABLED);
            res.SetMsg(SKIN_MATERIAL_MSG_TABLE, SKIN_MATERIAL_PER_COLOR_SCATTERING_MSG);

            result = LXe_CMD_DISABLED;
        }
    }
    else if ((strcmp(channelName, DERM_RED_DIST) == 0) || (strcmp(channelName, DERM_GREEN_DIST) == 0) || (strcmp(channelName, DERM_BLUE_DIST) == 0))
    {
        int perColorDist = chan.IValue(src, DERM_COLOR_DIST);

        if (!perColorDist)
        {
            CLxUser_Message res(msg);

            res.SetCode(LXe_CMD_DISABLED);
            res.SetMsg(SKIN_MATERIAL_MSG_TABLE, SKIN_MATERIAL_PER_COLOR_SCATTERING_MSG);

            result = LXe_CMD_DISABLED;
        }
    }

    return result;
}

LxResult SkinMaterial::cui_DependencyCount(const char* channelName, unsigned* count)
{
    if ((strcmp(channelName, SUB_RED_DIST) == 0) || (strcmp(channelName, SUB_GREEN_DIST) == 0) || (strcmp(channelName, SUB_BLUE_DIST) == 0) ||
        (strcmp(channelName, DERM_RED_DIST) == 0) || (strcmp(channelName, DERM_GREEN_DIST) == 0) || (strcmp(channelName, DERM_BLUE_DIST) == 0))
    {
        count[0] = 1;
    }
    else
    {
        count[0] = 0;
    }

    return LXe_OK;
}

LxResult SkinMaterial::cui_DependencyByIndex(const char* channelName, unsigned index, LXtItemType* depItemType, const char** depChannelName)
{
    LxResult result = LXe_OUTOFBOUNDS;

    if ((strcmp(channelName, SUB_RED_DIST) == 0) || (strcmp(channelName, SUB_GREEN_DIST) == 0) || (strcmp(channelName, SUB_BLUE_DIST) == 0))
    {
        depItemType[0] = MyType();
        switch (index)
        {
            case 0:
                depChannelName[0] = SUB_COLOR_DIST;
                result            = LXe_OK;
                break;

            default:
                result = LXe_OUTOFBOUNDS;
                break;
        }
    }
    else if ((strcmp(channelName, DERM_RED_DIST) == 0) || (strcmp(channelName, DERM_GREEN_DIST) == 0) || (strcmp(channelName, DERM_BLUE_DIST) == 0))
    {
        depItemType[0] = MyType();
        switch (index)
        {
            case 0:
                depChannelName[0] = DERM_COLOR_DIST;
                result            = LXe_OK;
                break;

            default:
                result = LXe_OUTOFBOUNDS;
                break;
        }
    }

    return result;
}

/*
 * Functions for shading the individual layers
 */
LxResult SkinMaterial::ShadeLowerDermalLayer(ILxUnknownID        vector,
                                             CLxLoc_Raycast*     raycast,
                                             SkinMaterialData*   matrData,
                                             float*              energy,
                                             LXpShadeComponents* sCmp,
                                             LXpShadeComponents* sCmpOut,
                                             LXpSampleParms*     sampleParmsOut)
{
    LXpSampleParms* sampleParameters = (LXpSampleParms*) pkt_service.FastPacket(vector, parms_offset);
    LxResult        result;

    if (!matrData->subColorDist)
    {
        LXx_VCPY(sampleParameters->subsCol, matrData->subSSSColor);
        sampleParameters->subsAmt   = matrData->subSSSAmt * (*energy);
        sampleParameters->subsDist  = matrData->subSSSDist;
        sampleParameters->subsPhase = matrData->subSSSBias;
        sampleParameters->subsDepth = matrData->subSSSDepth;

        result = raycast->InternalShade(vector);

        if (result != LXe_OK)
            return result;

        LXx_VADD(sCmpOut->subs, sCmp->subs);
    }
    else
    {
        float* dist[3];
        dist[0] = &(matrData->subRedDist);
        dist[1] = &(matrData->subGreenDist);
        dist[2] = &(matrData->subBlueDist);

        sampleParameters->subsAmt   = matrData->subSSSAmt * (*energy);
        sampleParameters->subsPhase = matrData->subSSSBias;
        sampleParameters->subsDepth = matrData->subSSSDepth;

        for (int i = 0; i < 3; i++)
        {
            LXx_VCLR(sampleParameters->subsCol);
            sampleParameters->subsCol[i] = matrData->subSSSColor[i];
            sampleParameters->subsDist   = matrData->subSSSDist * (*(dist[i]));

            result = raycast->InternalShade(vector);

            if (result != LXe_OK)
                return result;

            LXx_VADD(sCmpOut->subs, sCmp->subs);
        }
    }
    sampleParmsOut->subsAmt += sampleParameters->subsAmt;

    return LXe_OK;
}

LxResult SkinMaterial::ShadeUpperDermalLayer(ILxUnknownID        vector,
                                             CLxLoc_Raycast*     raycast,
                                             SkinMaterialData*   matrData,
                                             float*              energy,
                                             LXpShadeComponents* sCmp,
                                             LXpShadeComponents* sCmpOut,
                                             LXpSampleParms*     sampleParmsOut)
{
    LXpSampleParms* sampleParameters = (LXpSampleParms*) pkt_service.FastPacket(vector, parms_offset);
    LxResult        result;

    if (!matrData->dermColorDist)
    {
        LXx_VCPY(sampleParameters->subsCol, matrData->dermSSSColor);
        sampleParameters->subsAmt   = matrData->dermSSSAmt * (*energy);
        sampleParameters->subsDist  = matrData->dermSSSDist;
        sampleParameters->subsPhase = matrData->dermSSSBias;
        sampleParameters->subsDepth = matrData->dermSSSDepth;

        result = raycast->InternalShade(vector);

        if (result != LXe_OK)
            return result;

        LXx_VADD(sCmpOut->subs, sCmp->subs);
    }
    else
    {
        float* dist[3];
        dist[0] = &(matrData->dermRedDist);
        dist[1] = &(matrData->dermGreenDist);
        dist[2] = &(matrData->dermBlueDist);

        sampleParameters->subsAmt   = matrData->dermSSSAmt * (*energy);
        sampleParameters->subsPhase = matrData->dermSSSBias;
        sampleParameters->subsDepth = matrData->dermSSSDepth;

        for (int i = 0; i < 3; i++)
        {
            LXx_VCLR(sampleParameters->subsCol);
            sampleParameters->subsCol[i] = matrData->dermSSSColor[i];
            sampleParameters->subsDist   = matrData->dermSSSDist * (*(dist[i]));

            result = raycast->InternalShade(vector);

            if (result != LXe_OK)
                return result;

            LXx_VADD(sCmpOut->subs, sCmp->subs);
        }
    }

    if (matrData->physical)
    {
        (*energy) *= (1.f - CLAMP(matrData->dermSSSAmt, 0.f, 1.f));
    }

    /* In this case, we just overwrite the SSS */
    sampleParmsOut->subsAmt = sampleParameters->subsAmt;
    LXx_VCPY(sampleParmsOut->subsCol, sampleParameters->subsCol);
    sampleParmsOut->subsAmt = 1.0;

    sampleParameters->subsAmt = 0.0;

    return LXe_OK;
}

LxResult SkinMaterial::ShadeEpidermalLayer(ILxUnknownID        vector,
                                           CLxLoc_Raycast*     raycast,
                                           SkinMaterialData*   matrData,
                                           float*              energy,
                                           LXpShadeComponents* sCmp,
                                           LXpShadeComponents* sCmpOut,
                                           LXpSampleParms*     sampleParmsOut)
{
    LXpSampleParms* sampleParameters = (LXpSampleParms*) pkt_service.FastPacket(vector, parms_offset);
    LxResult        result;

    LXx_VCPY(sampleParameters->diffCol, matrData->epiDiffColor);
    sampleParameters->diffAmt   = matrData->epiDiffAmt * (*energy);
    sampleParameters->diffRough = matrData->epiDiffRoughness;

    LXx_VCPY(sampleParameters->subsCol, matrData->epiSSSColor);
    sampleParameters->subsAmt   = matrData->epiSSSAmt * (*energy);
    sampleParameters->subsDist  = matrData->epiSSSDist;
    sampleParameters->subsPhase = matrData->epiSSSBias;
    sampleParameters->subsDepth = matrData->epiSSSDepth;

    result = raycast->InternalShade(vector);

    if (result != LXe_OK)
        return result;

    // Add in the resulting shade components
    LXx_VADD(sCmpOut->diff, sCmp->diff);
    LXx_VADD(sCmpOut->diffDir, sCmp->diffDir);
    LXx_VADD(sCmpOut->diffInd, sCmp->diffInd);
    LXx_VADD(sCmpOut->diffUns, sCmp->diffUns);
    LXx_VADD(sCmpOut->illum, sCmp->illum);
    LXx_VADD(sCmpOut->illumDir, sCmp->illumDir);
    LXx_VADD(sCmpOut->illumInd, sCmp->illumInd);
    LXx_VADD(sCmpOut->illumUns, sCmp->illumUns);
    LXx_VADD(sCmpOut->subs, sCmp->subs);

    if (matrData->physical)
    {
        (*energy) *= (1.f - CLAMP(matrData->epiDiffAmt, 0.f, 1.f));
        (*energy) *= (1.f - CLAMP(matrData->epiSSSAmt, 0.f, 1.f));
    }

    /* Set the diffuse and subsurface for render outputs */
    sampleParmsOut->diffAmt = sampleParameters->diffAmt;
    LXx_VCPY(sampleParmsOut->diffCol, sampleParameters->diffCol);
    sampleParmsOut->subsAmt = sampleParameters->subsAmt;
    LXx_VCPY(sampleParmsOut->subsCol, sampleParameters->subsCol);

    // Reset the diffuse and subsurface amounts
    sampleParameters->diffAmt = 0.0;
    sampleParameters->subsAmt = 0.0;

    return LXe_OK;
}

LxResult SkinMaterial::ShadeOilLayer(ILxUnknownID        vector,
                                     CLxLoc_Raycast*     raycast,
                                     SkinMaterialData*   matrData,
                                     float*              energy,
                                     LXpShadeComponents* sCmp,
                                     LXpShadeComponents* sCmpOut,
                                     LXpSampleParms*     sampleParmsOut)
{
    LXpSampleParms*      sampleParameters = (LXpSampleParms*) pkt_service.FastPacket(vector, parms_offset);
    LXpSampleSurfNormal* sampleNormal     = (LXpSampleSurfNormal*) pkt_service.FastPacket(vector, nrm_offset);
    LXpSampleRay*        sampleRay        = (LXpSampleRay*) pkt_service.FastPacket(vector, ray_offset);
    LxResult             result;
    CLxLoc_ShaderService shdrSrv;

    if (matrData->oilBlurRefl)
        sampleParameters->flags |= LXfSURF_REFLBLUR;
    else
        sampleParameters->flags &= ~LXfSURF_REFLBLUR;

    LXx_VCPY(sampleParameters->specCol, matrData->oilSpecColor);
    sampleParameters->specAmt  = matrData->oilSpecAmt;
    sampleParameters->specFres = matrData->oilSpecFres;
    sampleParameters->rough    = matrData->oilRoughness;

    if (matrData->matchSpec)
    {
        LXx_VCPY(sampleParameters->reflCol, matrData->oilSpecColor);
        sampleParameters->reflAmt  = matrData->oilSpecAmt;
        sampleParameters->reflFres = matrData->oilSpecFres;
    }
    else
    {
        LXx_VCPY(sampleParameters->reflCol, matrData->oilReflColor);
        sampleParameters->reflAmt  = matrData->oilReflAmt;
        sampleParameters->reflFres = matrData->oilReflFres;
    }

    result = raycast->InternalShade(vector);

    if (result != LXe_OK)
    {
        return result;
    }

    // Add in the relevant shade components
    LXx_VADD(sCmpOut->spec, sCmp->spec);
    LXx_VADD(sCmpOut->refl, sCmp->refl);

    if (matrData->physical)
    {
        float      energyLossSpec, energyLossRefl;
        LXtFVector view;

        LXx_VSCL3(view, sampleRay->dir, -1.0);

        energyLossSpec = shdrSrv.ComputeFresnel(view, sampleNormal->wNorm, matrData->oilSpecAmt);
        energyLossSpec = (matrData->oilSpecFres * energyLossSpec) + ((1.f - matrData->oilSpecFres) * matrData->oilSpecAmt);

        energyLossRefl = shdrSrv.ComputeFresnel(view, sampleNormal->wNorm, matrData->oilReflAmt);
        energyLossRefl = (matrData->oilReflFres * energyLossRefl) + ((1.f - matrData->oilReflFres) * matrData->oilReflAmt);

        (*energy) *= (1.f - CLAMP(LXxMAX(energyLossSpec, energyLossRefl), 0.f, 1.f));
    }

    /* Set the specular and reflection values for render output */
    sampleParmsOut->specAmt = sampleParameters->specAmt;
    LXx_VCPY(sampleParmsOut->specCol, sampleParameters->specCol);
    sampleParmsOut->reflAmt = sampleParameters->reflAmt;
    LXx_VCPY(sampleParmsOut->reflCol, sampleParameters->reflCol);
    sampleParmsOut->specFres = sampleParameters->specFres;
    sampleParmsOut->reflFres = sampleParameters->reflFres;

    // Reset the specularity and reflection amounts
    sampleParameters->specAmt  = 0.0;
    sampleParameters->reflAmt  = 0.0;
    sampleParameters->specFres = 0.0;
    sampleParameters->reflFres = 0.0;

    return LXe_OK;
}

LxResult SkinMaterial::cmt_LinkSampleChannels(ILxUnknownID eval, ILxUnknownID item, int* idx)
{
    nodalSvc.AddSampleChan(eval, item, samplesIndex.physical.chan, idx, LXfECHAN_READ);  // 0

    nodalSvc.AddSampleChan(eval, item, samplesIndex.oilSpecColor[0].chan, idx, LXfECHAN_READ);
    nodalSvc.AddSampleChan(eval, item, samplesIndex.oilSpecColor[1].chan, idx, LXfECHAN_READ);
    nodalSvc.AddSampleChan(eval, item, samplesIndex.oilSpecColor[2].chan, idx, LXfECHAN_READ);
    nodalSvc.AddSampleChan(eval, item, samplesIndex.oilSpecAmt.chan, idx, LXfECHAN_READ);
    nodalSvc.AddSampleChan(eval, item, samplesIndex.oilSpecFres.chan, idx, LXfECHAN_READ);
    nodalSvc.AddSampleChan(eval, item, samplesIndex.oilRoughness.chan, idx, LXfECHAN_READ);  // 6

    nodalSvc.AddSampleChan(eval, item, samplesIndex.matchSpec.chan, idx, LXfECHAN_READ);
    nodalSvc.AddSampleChan(eval, item, samplesIndex.oilReflColor[0].chan, idx, LXfECHAN_READ);
    nodalSvc.AddSampleChan(eval, item, samplesIndex.oilReflColor[1].chan, idx, LXfECHAN_READ);
    nodalSvc.AddSampleChan(eval, item, samplesIndex.oilReflColor[2].chan, idx, LXfECHAN_READ);
    nodalSvc.AddSampleChan(eval, item, samplesIndex.oilReflAmt.chan, idx, LXfECHAN_READ);
    nodalSvc.AddSampleChan(eval, item, samplesIndex.oilReflFres.chan, idx, LXfECHAN_READ);  // 12
    nodalSvc.AddSampleChan(eval, item, samplesIndex.oilBlurRefl.chan, idx, LXfECHAN_READ);  // 13

    nodalSvc.AddSampleChan(eval, item, samplesIndex.epiDiffColor[0].chan, idx, LXfECHAN_READ);
    nodalSvc.AddSampleChan(eval, item, samplesIndex.epiDiffColor[1].chan, idx, LXfECHAN_READ);
    nodalSvc.AddSampleChan(eval, item, samplesIndex.epiDiffColor[2].chan, idx, LXfECHAN_READ);
    nodalSvc.AddSampleChan(eval, item, samplesIndex.epiDiffAmt.chan, idx, LXfECHAN_READ);
    nodalSvc.AddSampleChan(eval, item, samplesIndex.epiDiffRoughness.chan, idx, LXfECHAN_READ);  // 18

    nodalSvc.AddSampleChan(eval, item, samplesIndex.epiSSSColor[0].chan, idx, LXfECHAN_READ);
    nodalSvc.AddSampleChan(eval, item, samplesIndex.epiSSSColor[1].chan, idx, LXfECHAN_READ);
    nodalSvc.AddSampleChan(eval, item, samplesIndex.epiSSSColor[2].chan, idx, LXfECHAN_READ);
    nodalSvc.AddSampleChan(eval, item, samplesIndex.epiSSSAmt.chan, idx, LXfECHAN_READ);
    nodalSvc.AddSampleChan(eval, item, samplesIndex.epiSSSDist.chan, idx, LXfECHAN_READ);
    nodalSvc.AddSampleChan(eval, item, samplesIndex.epiSSSDepth.chan, idx, LXfECHAN_READ);
    nodalSvc.AddSampleChan(eval, item, samplesIndex.epiSSSBias.chan, idx, LXfECHAN_READ);  // 25

    nodalSvc.AddSampleChan(eval, item, samplesIndex.dermSSSColor[0].chan, idx, LXfECHAN_READ);
    nodalSvc.AddSampleChan(eval, item, samplesIndex.dermSSSColor[1].chan, idx, LXfECHAN_READ);
    nodalSvc.AddSampleChan(eval, item, samplesIndex.dermSSSColor[2].chan, idx, LXfECHAN_READ);
    nodalSvc.AddSampleChan(eval, item, samplesIndex.dermSSSAmt.chan, idx, LXfECHAN_READ);
    nodalSvc.AddSampleChan(eval, item, samplesIndex.dermSSSDist.chan, idx, LXfECHAN_READ);
    nodalSvc.AddSampleChan(eval, item, samplesIndex.dermColorDist.chan, idx, LXfECHAN_READ);
    nodalSvc.AddSampleChan(eval, item, samplesIndex.dermRedDist.chan, idx, LXfECHAN_READ);
    nodalSvc.AddSampleChan(eval, item, samplesIndex.dermGreenDist.chan, idx, LXfECHAN_READ);
    nodalSvc.AddSampleChan(eval, item, samplesIndex.dermBlueDist.chan, idx, LXfECHAN_READ);
    nodalSvc.AddSampleChan(eval, item, samplesIndex.dermSSSDepth.chan, idx, LXfECHAN_READ);
    nodalSvc.AddSampleChan(eval, item, samplesIndex.dermSSSBias.chan, idx, LXfECHAN_READ);  // 36

    nodalSvc.AddSampleChan(eval, item, samplesIndex.subSSSColor[0].chan, idx, LXfECHAN_READ);
    nodalSvc.AddSampleChan(eval, item, samplesIndex.subSSSColor[1].chan, idx, LXfECHAN_READ);
    nodalSvc.AddSampleChan(eval, item, samplesIndex.subSSSColor[2].chan, idx, LXfECHAN_READ);
    nodalSvc.AddSampleChan(eval, item, samplesIndex.subSSSAmt.chan, idx, LXfECHAN_READ);
    nodalSvc.AddSampleChan(eval, item, samplesIndex.subSSSDist.chan, idx, LXfECHAN_READ);
    nodalSvc.AddSampleChan(eval, item, samplesIndex.subColorDist.chan, idx, LXfECHAN_READ);
    nodalSvc.AddSampleChan(eval, item, samplesIndex.subRedDist.chan, idx, LXfECHAN_READ);
    nodalSvc.AddSampleChan(eval, item, samplesIndex.subGreenDist.chan, idx, LXfECHAN_READ);
    nodalSvc.AddSampleChan(eval, item, samplesIndex.subBlueDist.chan, idx, LXfECHAN_READ);
    nodalSvc.AddSampleChan(eval, item, samplesIndex.subSSSDepth.chan, idx, LXfECHAN_READ);
    nodalSvc.AddSampleChan(eval, item, samplesIndex.subSSSBias.chan, idx, LXfECHAN_READ);  // 47

    nodalSvc.AddSampleChan(eval, item, samplesIndex.bumpAmp.chan, idx, LXfECHAN_READ);   // 48
    nodalSvc.AddSampleChan(eval, item, samplesIndex.reflRays.chan, idx, LXfECHAN_READ);  // 49
    nodalSvc.AddSampleChan(eval, item, samplesIndex.sssRays.chan, idx, LXfECHAN_READ);   // 50

    nodalSvc.AddSampleChan(eval, item, samplesIndex.dispDist.chan, idx, LXfECHAN_READ);  // 51
    nodalSvc.AddSampleChan(eval, item, samplesIndex.sameSurface.chan, idx, LXfECHAN_READ);

    return LXe_OK;
}

int SkinMaterial::cmt_IsSampleDriven(int* idx)
{
    return nodalSvc.AnyDrivenChans(&idx[samplesIndex.physical.chan], NUM_CHANNELS);
}

/*
 * Evaluate the color at a spot.
 */
void SkinMaterial::cmt_MaterialEvaluate(ILxUnknownID etor, int* idx, ILxUnknownID vector, void* data)
{
    LXpSkinShader*    sSkin = (LXpSkinShader*) pkt_service.FastPacket(vector, pkt_offset);
    SkinMaterialData* md    = (SkinMaterialData*) data;

    // Copy over the material data
    sSkin->matrData = *md;

    sSkin->matrData.physical = nodalSvc.GetInt(etor, idx, samplesIndex.physical.chan, sSkin->matrData.physical);  // 0

    sSkin->matrData.oilSpecColor[0] =
    static_cast<float>(nodalSvc.GetFloat(etor, idx, samplesIndex.oilSpecColor[0].chan, sSkin->matrData.oilSpecColor[0]));
    sSkin->matrData.oilSpecColor[1] =
    static_cast<float>(nodalSvc.GetFloat(etor, idx, samplesIndex.oilSpecColor[1].chan, sSkin->matrData.oilSpecColor[1]));
    sSkin->matrData.oilSpecColor[2] =
    static_cast<float>(nodalSvc.GetFloat(etor, idx, samplesIndex.oilSpecColor[2].chan, sSkin->matrData.oilSpecColor[2]));
    sSkin->matrData.oilSpecAmt  = static_cast<float>(nodalSvc.GetFloat(etor, idx, samplesIndex.oilSpecAmt.chan, sSkin->matrData.oilSpecAmt));
    sSkin->matrData.oilSpecFres = static_cast<float>(nodalSvc.GetFloat(etor, idx, samplesIndex.oilSpecFres.chan, sSkin->matrData.oilSpecFres));
    sSkin->matrData.oilRoughness =
    static_cast<float>(nodalSvc.GetFloat(etor, idx, samplesIndex.oilRoughness.chan, sSkin->matrData.oilRoughness));  // 6

    sSkin->matrData.matchSpec = nodalSvc.GetInt(etor, idx, samplesIndex.matchSpec.chan, sSkin->matrData.matchSpec);

    if (sSkin->matrData.matchSpec)
    {
        sSkin->matrData.oilReflColor[0] = md->oilSpecColor[0];
        sSkin->matrData.oilReflColor[1] = md->oilSpecColor[1];
        sSkin->matrData.oilReflColor[2] = md->oilSpecColor[2];
        sSkin->matrData.oilReflAmt      = md->oilSpecAmt;
        sSkin->matrData.oilReflFres     = md->oilSpecFres;
    }
    else
    {
        sSkin->matrData.oilReflColor[0] =
        static_cast<float>(nodalSvc.GetFloat(etor, idx, samplesIndex.oilReflColor[0].chan, sSkin->matrData.oilReflColor[0]));
        sSkin->matrData.oilReflColor[1] =
        static_cast<float>(nodalSvc.GetFloat(etor, idx, samplesIndex.oilReflColor[1].chan, sSkin->matrData.oilReflColor[1]));
        sSkin->matrData.oilReflColor[2] =
        static_cast<float>(nodalSvc.GetFloat(etor, idx, samplesIndex.oilReflColor[2].chan, sSkin->matrData.oilReflColor[2]));
        sSkin->matrData.oilReflAmt = static_cast<float>(nodalSvc.GetFloat(etor, idx, samplesIndex.oilReflAmt.chan, sSkin->matrData.oilReflAmt));
        sSkin->matrData.oilReflFres =
        static_cast<float>(nodalSvc.GetFloat(etor, idx, samplesIndex.oilReflFres.chan, sSkin->matrData.oilReflFres));  // 12
    }
    sSkin->matrData.oilBlurRefl = nodalSvc.GetInt(etor, idx, samplesIndex.oilBlurRefl.chan, sSkin->matrData.oilBlurRefl);  // 13

    sSkin->matrData.epiDiffColor[0] =
    static_cast<float>(nodalSvc.GetFloat(etor, idx, samplesIndex.epiDiffColor[0].chan, sSkin->matrData.epiDiffColor[0]));
    sSkin->matrData.epiDiffColor[1] =
    static_cast<float>(nodalSvc.GetFloat(etor, idx, samplesIndex.epiDiffColor[1].chan, sSkin->matrData.epiDiffColor[1]));
    sSkin->matrData.epiDiffColor[2] =
    static_cast<float>(nodalSvc.GetFloat(etor, idx, samplesIndex.epiDiffColor[2].chan, sSkin->matrData.epiDiffColor[2]));
    sSkin->matrData.epiDiffAmt = static_cast<float>(nodalSvc.GetFloat(etor, idx, samplesIndex.epiDiffAmt.chan, sSkin->matrData.epiDiffAmt));
    sSkin->matrData.epiDiffRoughness =
    static_cast<float>(nodalSvc.GetFloat(etor, idx, samplesIndex.epiDiffRoughness.chan, sSkin->matrData.epiDiffRoughness));  // 18

    sSkin->matrData.epiSSSColor[0] =
    static_cast<float>(nodalSvc.GetFloat(etor, idx, samplesIndex.epiSSSColor[0].chan, sSkin->matrData.epiSSSColor[0]));
    sSkin->matrData.epiSSSColor[1] =
    static_cast<float>(nodalSvc.GetFloat(etor, idx, samplesIndex.epiSSSColor[1].chan, sSkin->matrData.epiSSSColor[1]));
    sSkin->matrData.epiSSSColor[2] =
    static_cast<float>(nodalSvc.GetFloat(etor, idx, samplesIndex.epiSSSColor[2].chan, sSkin->matrData.epiSSSColor[2]));
    sSkin->matrData.epiSSSAmt   = static_cast<float>(nodalSvc.GetFloat(etor, idx, samplesIndex.epiSSSAmt.chan, sSkin->matrData.epiSSSAmt));
    sSkin->matrData.epiSSSDist  = static_cast<float>(nodalSvc.GetFloat(etor, idx, samplesIndex.epiSSSDist.chan, sSkin->matrData.epiSSSDist));
    sSkin->matrData.epiSSSDepth = static_cast<float>(nodalSvc.GetFloat(etor, idx, samplesIndex.epiSSSDepth.chan, sSkin->matrData.epiSSSDepth));
    sSkin->matrData.epiSSSBias  = static_cast<float>(nodalSvc.GetFloat(etor, idx, samplesIndex.epiSSSBias.chan, sSkin->matrData.epiSSSBias));  // 25

    sSkin->matrData.dermSSSColor[0] =
    static_cast<float>(nodalSvc.GetFloat(etor, idx, samplesIndex.dermSSSColor[0].chan, sSkin->matrData.dermSSSColor[0]));
    sSkin->matrData.dermSSSColor[1] =
    static_cast<float>(nodalSvc.GetFloat(etor, idx, samplesIndex.dermSSSColor[1].chan, sSkin->matrData.dermSSSColor[1]));
    sSkin->matrData.dermSSSColor[2] =
    static_cast<float>(nodalSvc.GetFloat(etor, idx, samplesIndex.dermSSSColor[2].chan, sSkin->matrData.dermSSSColor[2]));
    sSkin->matrData.dermSSSAmt    = static_cast<float>(nodalSvc.GetFloat(etor, idx, samplesIndex.dermSSSAmt.chan, sSkin->matrData.dermSSSAmt));
    sSkin->matrData.dermSSSDist   = static_cast<float>(nodalSvc.GetFloat(etor, idx, samplesIndex.dermSSSDist.chan, sSkin->matrData.dermSSSDist));
    sSkin->matrData.dermColorDist = static_cast<int>(nodalSvc.GetFloat(etor, idx, samplesIndex.dermColorDist.chan, sSkin->matrData.dermSSSDist));
    sSkin->matrData.dermRedDist   = static_cast<float>(nodalSvc.GetFloat(etor, idx, samplesIndex.dermRedDist.chan, sSkin->matrData.dermRedDist));
    sSkin->matrData.dermGreenDist = static_cast<float>(nodalSvc.GetFloat(etor, idx, samplesIndex.dermGreenDist.chan, sSkin->matrData.dermGreenDist));
    sSkin->matrData.dermBlueDist  = static_cast<float>(nodalSvc.GetFloat(etor, idx, samplesIndex.dermBlueDist.chan, sSkin->matrData.dermBlueDist));
    sSkin->matrData.dermSSSDepth  = static_cast<float>(nodalSvc.GetFloat(etor, idx, samplesIndex.dermSSSDepth.chan, sSkin->matrData.dermSSSDepth));
    sSkin->matrData.dermSSSBias = static_cast<float>(nodalSvc.GetFloat(etor, idx, samplesIndex.dermSSSBias.chan, sSkin->matrData.dermSSSBias));  // 36

    sSkin->matrData.subSSSColor[0] =
    static_cast<float>(nodalSvc.GetFloat(etor, idx, samplesIndex.subSSSColor[0].chan, sSkin->matrData.subSSSColor[0]));
    sSkin->matrData.subSSSColor[1] =
    static_cast<float>(nodalSvc.GetFloat(etor, idx, samplesIndex.subSSSColor[1].chan, sSkin->matrData.subSSSColor[1]));
    sSkin->matrData.subSSSColor[2] =
    static_cast<float>(nodalSvc.GetFloat(etor, idx, samplesIndex.subSSSColor[2].chan, sSkin->matrData.subSSSColor[2]));
    sSkin->matrData.subSSSAmt    = static_cast<float>(nodalSvc.GetFloat(etor, idx, samplesIndex.subSSSAmt.chan, sSkin->matrData.subSSSAmt));
    sSkin->matrData.subSSSDist   = static_cast<float>(nodalSvc.GetFloat(etor, idx, samplesIndex.subSSSDist.chan, sSkin->matrData.subSSSDist));
    sSkin->matrData.subColorDist = nodalSvc.GetInt(etor, idx, samplesIndex.subColorDist.chan, sSkin->matrData.subColorDist);
    sSkin->matrData.subRedDist   = static_cast<float>(nodalSvc.GetFloat(etor, idx, samplesIndex.subRedDist.chan, sSkin->matrData.subRedDist));
    sSkin->matrData.subGreenDist = static_cast<float>(nodalSvc.GetFloat(etor, idx, samplesIndex.subGreenDist.chan, sSkin->matrData.subGreenDist));
    sSkin->matrData.subBlueDist  = static_cast<float>(nodalSvc.GetFloat(etor, idx, samplesIndex.subBlueDist.chan, sSkin->matrData.subBlueDist));
    sSkin->matrData.subSSSDepth  = static_cast<float>(nodalSvc.GetFloat(etor, idx, samplesIndex.subSSSDepth.chan, sSkin->matrData.subSSSDepth));
    sSkin->matrData.subSSSBias   = static_cast<float>(nodalSvc.GetFloat(etor, idx, samplesIndex.subSSSBias.chan, sSkin->matrData.subSSSBias));  // 47

    bumpAmp                  = static_cast<float>(nodalSvc.GetFloat(etor, idx, samplesIndex.bumpAmp.chan, bumpAmp));  // 48
    sSkin->matrData.reflRays = nodalSvc.GetInt(etor, idx, samplesIndex.reflRays.chan, sSkin->matrData.reflRays);      // 49
    sSkin->matrData.sssRays  = nodalSvc.GetInt(etor, idx, samplesIndex.sssRays.chan, sSkin->matrData.sssRays);        // 50

    dispDist                    = static_cast<float>(nodalSvc.GetFloat(etor, idx, samplesIndex.dispDist.chan, dispDist));  // 51
    sSkin->matrData.sameSurface = nodalSvc.GetInt(etor, idx, samplesIndex.sameSurface.chan, sSkin->matrData.sameSurface);  // 0
}

void SkinMaterial::cmt_Cleanup(void* data)
{
    SkinMaterialData* md = (SkinMaterialData*) data;

    delete md;
}

LxResult SkinMaterial::cmt_SetBump(float* bumpAmount, int* clearBump)
{
    *bumpAmount = this->bumpAmp;
    *clearBump  = 1;

    return LXe_OK;
}

LxResult SkinMaterial::cmt_SetDisplacement(float* dispDistance)
{
    *dispDistance = this->dispDist;

    return LXe_OK;
}

/*
 * Skin should be smooth!
 */
LxResult SkinMaterial::cmt_SetSmoothing(double* smooth, double* angle, int* /*weighting*/, int* /*normalMethod*/, int* creasing)
{
    *smooth   = 1.0;
    *angle    = LXx_PI;
    *creasing = 0;

    return LXe_OK;
}
/*
 * If displacement distance has changed, we need to update geometry. Otherwise
 * we return LXe_NOTIMPL so that it will use the default updating.
 */

LxResult SkinMaterial::cmt_UpdatePreview(int chanIdx, int* flags)
{
    if (!channelsAreInitialized)
        return LXe_NOTIMPL;
    if (static_cast<unsigned>(chanIdx) != samplesIndex.dispDist.layer)
        return LXe_NOTIMPL;

    *flags = LXfPREV_UPDATE_GEOMETRY;
    return LXe_OK;
}
/*
 * Evaluate the color at a spot.
 */
void SkinMaterial::cmt_ShaderEvaluate(ILxUnknownID vector, ILxUnknownID rayObj, LXpShadeComponents* sCmp, LXpShadeOutput* sOut, void* /*data*/)
{
    LXpSampleParms*   sampleParameters = (LXpSampleParms*) pkt_service.FastPacket(vector, parms_offset);
    LXpSampleParms    sampleParms{};
    LXpSkinShader*    sSkin    = (LXpSkinShader*) pkt_service.FastPacket(vector, pkt_offset);
    SkinMaterialData* matrData = &(sSkin->matrData);

    LXpShadeComponents sCmpOut;

    LxResult result;

    LXtFVector purple = { 1.0, 0.0, 1.0 };

    CLxLoc_Raycast raycast;

    // This is used for Energy Conservation
    float energy = 1.0;

    // Initialize the raycast object
    raycast.set(rayObj);

    if (raycast.GetSurfaceType(vector) == LXi_SURF_FUR)
    {
        return;
    }

    if (matrData->physical)
        sampleParameters->flags |= LXfSURF_PHYSICAL;

    if (matrData->sameSurface)
        sampleParameters->flags |= LXfSURF_SAMESURF;

    /*
     * Set the quality settings
     */
    sampleParameters->reflRays   = matrData->reflRays;
    sampleParameters->subsRays   = matrData->sssRays;
    sampleParameters->importance = 1.0;

    /*
     * Initialize the shading by setting everything to zero
     */
    this->ClearShader(sampleParameters);
    this->ClearShader(&sampleParms);
    this->ClearShadeComponents(&sCmpOut);

    /*
     * Compute all the shading
     */

    result = ShadeOilLayer(vector, &raycast, matrData, &energy, sCmp, &sCmpOut, &sampleParms);
    if (result != LXe_OK)
    {
        LXx_VCPY(sOut->color, purple);
        return;
    }

    result = ShadeEpidermalLayer(vector, &raycast, matrData, &energy, sCmp, &sCmpOut, &sampleParms);
    if (result != LXe_OK)
    {
        LXx_VCPY(sOut->color, purple);
        return;
    }

    result = ShadeUpperDermalLayer(vector, &raycast, matrData, &energy, sCmp, &sCmpOut, &sampleParms);
    if (result != LXe_OK)
    {
        LXx_VCPY(sOut->color, purple);
        return;
    }

    result = ShadeLowerDermalLayer(vector, &raycast, matrData, &energy, sCmp, &sCmpOut, &sampleParms);
    if (result != LXe_OK)
    {
        LXx_VCPY(sOut->color, purple);
        return;
    }

    // Copy the final new shade components out
    *sCmp = sCmpOut;

    // Compute the final color
    for (int i = 0; i < 3; i++)
        sOut->color[i] = sCmp->diff[i] + sCmp->spec[i] + sCmp->refl[i] + sCmp->subs[i];

    if (floatTest(sOut->color[0]) || floatTest(sOut->color[1]) || floatTest(sOut->color[2]))
    {
        LXx_VCPY(sOut->color, purple);
    }

    // Set the outgoing sample parameters
    *sampleParameters = sampleParms;

    // Set the final alpha to zero
    sOut->alpha = 1.0;
}

LXtItemType SkinMaterial::MyType()
{
    if (my_type != LXiTYPE_NONE)
        return my_type;

    CLxUser_SceneService svc;

    my_type = svc.ItemType(SRVs_SKIN_MATR_ITEMTYPE);
    return my_type;
}

/* -------------------------------------------------------------------------
 *
 * Packet Effects definition:
 * This section is used to define all the various texture effects that
 * can be used with the skin shader.
 *
 * ------------------------------------------------------------------------- */

class SkinPFX : public CLxImpl_PacketEffect
{
public:
    SkinPFX()
    {
    }

    static LXtTagInfoDesc descInfo[];

    LxResult     pfx_Packet(const char** packet) override;
    unsigned int pfx_Count(void) override;
    LxResult     pfx_ByIndex(int idx, const char** name, const char** typeName, int* type) override;
    LxResult     pfx_Get(int idx, void* packet, float* val, void* item) override;
    LxResult     pfx_Set(int idx, void* packet, const float* val, void* item) override;
};

#define SRVs_SKIN_PFX SRVs_SKIN_MATR

enum
{
    SRVs_OIL_SPEC_COL_IDX = 0,
    SRVs_OIL_SPEC_AMT_IDX,
    SRVs_OIL_SPEC_FRES_IDX,
    SRVs_OIL_ROUGH_IDX,
    SRVs_OIL_REFL_COL_IDX,
    SRVs_OIL_REFL_AMT_IDX,
    SRVs_OIL_REFL_FRES_IDX,
    SRVs_EPI_DIFF_COL_IDX,
    SRVs_EPI_DIFF_AMT_IDX,
    SRVs_EPI_DIFF_ROUGH_IDX,
    SRVs_EPI_SSS_COL_IDX,
    SRVs_EPI_SSS_AMT_IDX,
    SRVs_EPI_SSS_DEPTH_IDX,
    SRVs_DERM_SSS_COL_IDX,
    SRVs_DERM_SSS_AMT_IDX,
    SRVs_DERM_SSS_DEPTH_IDX,
    SRVs_SUB_SSS_COL_IDX,
    SRVs_SUB_SSS_AMT_IDX,
    SRVs_SUB_SSS_DEPTH_IDX
};

#define SRVs_OIL_SPEC_COL_TFX   "oilSpecColor"
#define SRVs_OIL_SPEC_AMT_TFX   "oilSpecAmt"
#define SRVs_OIL_SPEC_FRES_TFX  "oilSpecFres"
#define SRVs_OIL_ROUGH_TFX      "oilRoughness"
#define SRVs_OIL_REFL_COL_TFX   "oilReflColor"
#define SRVs_OIL_REFL_AMT_TFX   "oilReflAmt"
#define SRVs_OIL_REFL_FRES_TFX  "oilReflFres"
#define SRVs_EPI_DIFF_COL_TFX   "epiDiffColor"
#define SRVs_EPI_DIFF_AMT_TFX   "epiDiffAmt"
#define SRVs_EPI_DIFF_ROUGH_TFX "epiDiffRoughness"
#define SRVs_EPI_SSS_COL_TFX    "epiSSSColor"
#define SRVs_EPI_SSS_AMT_TFX    "epiSSSAmt"
#define SRVs_EPI_SSS_DEPTH_TFX  "epiSSSDepth"
#define SRVs_DERM_SSS_COL_TFX   "dermSSSColor"
#define SRVs_DERM_SSS_AMT_TFX   "dermSSSAmt"
#define SRVs_DERM_SSS_DEPTH_TFX "dermSSSDepth"
#define SRVs_SUB_SSS_COL_TFX    "subSSSColor"
#define SRVs_SUB_SSS_AMT_TFX    "subSSSAmt"
#define SRVs_SUB_SSS_DEPTH_TFX  "subSSSDepth"

LXtTagInfoDesc SkinPFX::descInfo[] = { { LXsSRV_USERNAME, "Skin Packet FX" },
                                       { LXsSRV_LOGSUBSYSTEM, "texture-effect" },
                                       { LXsTFX_CATEGORY, LXsSHADE_SURFACE },
                                       { nullptr } };

LxResult SkinPFX::pfx_Packet(const char** packet)
{
    packet[0] = SRVs_SKIN_VPACKET;
    return LXe_OK;
}

unsigned int SkinPFX::pfx_Count(void)
{
    return 19;
}

LxResult SkinPFX::pfx_ByIndex(int id, const char** name, const char** typeName, int* type)
{
    switch (id)
    {
        case SRVs_OIL_SPEC_COL_IDX:
            name[0]     = SRVs_OIL_SPEC_COL_TFX;
            type[0]     = LXi_TFX_COLOR | LXf_TFX_READ | LXf_TFX_WRITE;
            typeName[0] = LXsTYPE_COLOR1;
            break;
        case SRVs_OIL_SPEC_AMT_IDX:
            name[0]     = SRVs_OIL_SPEC_AMT_TFX;
            type[0]     = LXi_TFX_SCALAR | LXf_TFX_READ | LXf_TFX_WRITE;
            typeName[0] = LXsTYPE_FLOAT;
            break;
        case SRVs_OIL_SPEC_FRES_IDX:
            name[0]     = SRVs_OIL_SPEC_FRES_TFX;
            type[0]     = LXi_TFX_SCALAR | LXf_TFX_READ | LXf_TFX_WRITE;
            typeName[0] = LXsTYPE_FLOAT;
            break;
        case SRVs_OIL_ROUGH_IDX:
            name[0]     = SRVs_OIL_ROUGH_TFX;
            type[0]     = LXi_TFX_SCALAR | LXf_TFX_READ | LXf_TFX_WRITE;
            typeName[0] = LXsTYPE_FLOAT;
            break;

        case SRVs_OIL_REFL_COL_IDX:
            name[0]     = SRVs_OIL_REFL_COL_TFX;
            type[0]     = LXi_TFX_COLOR | LXf_TFX_READ | LXf_TFX_WRITE;
            typeName[0] = LXsTYPE_COLOR1;
            break;
        case SRVs_OIL_REFL_AMT_IDX:
            name[0]     = SRVs_OIL_REFL_AMT_TFX;
            type[0]     = LXi_TFX_SCALAR | LXf_TFX_READ | LXf_TFX_WRITE;
            typeName[0] = LXsTYPE_FLOAT;
            break;
        case SRVs_OIL_REFL_FRES_IDX:
            name[0]     = SRVs_OIL_REFL_FRES_TFX;
            type[0]     = LXi_TFX_SCALAR | LXf_TFX_READ | LXf_TFX_WRITE;
            typeName[0] = LXsTYPE_FLOAT;
            break;

        case SRVs_EPI_DIFF_COL_IDX:
            name[0]     = SRVs_EPI_DIFF_COL_TFX;
            type[0]     = LXi_TFX_COLOR | LXf_TFX_READ | LXf_TFX_WRITE;
            typeName[0] = LXsTYPE_COLOR1;
            break;
        case SRVs_EPI_DIFF_AMT_IDX:
            name[0]     = SRVs_EPI_DIFF_AMT_TFX;
            type[0]     = LXi_TFX_SCALAR | LXf_TFX_READ | LXf_TFX_WRITE;
            typeName[0] = LXsTYPE_FLOAT;
            break;
        case SRVs_EPI_DIFF_ROUGH_IDX:
            name[0]     = SRVs_EPI_DIFF_ROUGH_TFX;
            type[0]     = LXi_TFX_SCALAR | LXf_TFX_READ | LXf_TFX_WRITE;
            typeName[0] = LXsTYPE_FLOAT;
            break;

        case SRVs_EPI_SSS_COL_IDX:
            name[0]     = SRVs_EPI_SSS_COL_TFX;
            type[0]     = LXi_TFX_COLOR | LXf_TFX_READ | LXf_TFX_WRITE;
            typeName[0] = LXsTYPE_COLOR1;
            break;
        case SRVs_EPI_SSS_AMT_IDX:
            name[0]     = SRVs_EPI_SSS_AMT_TFX;
            type[0]     = LXi_TFX_SCALAR | LXf_TFX_READ | LXf_TFX_WRITE;
            typeName[0] = LXsTYPE_FLOAT;
            break;
        case SRVs_EPI_SSS_DEPTH_IDX:
            name[0]     = SRVs_EPI_SSS_DEPTH_TFX;
            type[0]     = LXi_TFX_SCALAR | LXf_TFX_READ | LXf_TFX_WRITE;
            typeName[0] = LXsTYPE_FLOAT;
            break;

        case SRVs_DERM_SSS_COL_IDX:
            name[0]     = SRVs_DERM_SSS_COL_TFX;
            type[0]     = LXi_TFX_COLOR | LXf_TFX_READ | LXf_TFX_WRITE;
            typeName[0] = LXsTYPE_COLOR1;
            break;
        case SRVs_DERM_SSS_AMT_IDX:
            name[0]     = SRVs_DERM_SSS_AMT_TFX;
            type[0]     = LXi_TFX_SCALAR | LXf_TFX_READ | LXf_TFX_WRITE;
            typeName[0] = LXsTYPE_FLOAT;
            break;
        case SRVs_DERM_SSS_DEPTH_IDX:
            name[0]     = SRVs_DERM_SSS_DEPTH_TFX;
            type[0]     = LXi_TFX_SCALAR | LXf_TFX_READ | LXf_TFX_WRITE;
            typeName[0] = LXsTYPE_FLOAT;
            break;

        case SRVs_SUB_SSS_COL_IDX:
            name[0]     = SRVs_SUB_SSS_COL_TFX;
            type[0]     = LXi_TFX_COLOR | LXf_TFX_READ | LXf_TFX_WRITE;
            typeName[0] = LXsTYPE_COLOR1;
            break;
        case SRVs_SUB_SSS_AMT_IDX:
            name[0]     = SRVs_SUB_SSS_AMT_TFX;
            type[0]     = LXi_TFX_SCALAR | LXf_TFX_READ | LXf_TFX_WRITE;
            typeName[0] = LXsTYPE_FLOAT;
            break;
        case SRVs_SUB_SSS_DEPTH_IDX:
            name[0]     = SRVs_SUB_SSS_DEPTH_TFX;
            type[0]     = LXi_TFX_SCALAR | LXf_TFX_READ | LXf_TFX_WRITE;
            typeName[0] = LXsTYPE_FLOAT;
            break;
    }

    return LXe_OK;
}

LxResult SkinPFX::pfx_Get(int id, void* packet, float* val, void* /*item*/)
{
    LXpSkinShader* skinPacket = (LXpSkinShader*) packet;

    switch (id)
    {
        case SRVs_OIL_SPEC_COL_IDX:
            val[0] = skinPacket->matrData.oilSpecColor[0];
            val[1] = skinPacket->matrData.oilSpecColor[1];
            val[2] = skinPacket->matrData.oilSpecColor[2];
            break;
        case SRVs_OIL_SPEC_AMT_IDX:
            val[0] = skinPacket->matrData.oilSpecAmt;
            break;
        case SRVs_OIL_SPEC_FRES_IDX:
            val[0] = skinPacket->matrData.oilSpecFres;
            break;
        case SRVs_OIL_ROUGH_IDX:
            val[0] = skinPacket->matrData.oilRoughness;
            break;

        case SRVs_OIL_REFL_COL_IDX:
            val[0] = skinPacket->matrData.oilReflColor[0];
            val[1] = skinPacket->matrData.oilReflColor[1];
            val[2] = skinPacket->matrData.oilReflColor[2];
            break;
        case SRVs_OIL_REFL_AMT_IDX:
            val[0] = skinPacket->matrData.oilReflAmt;
            break;
        case SRVs_OIL_REFL_FRES_IDX:
            val[0] = skinPacket->matrData.oilReflFres;
            break;

        case SRVs_EPI_DIFF_COL_IDX:
            val[0] = skinPacket->matrData.epiDiffColor[0];
            val[1] = skinPacket->matrData.epiDiffColor[1];
            val[2] = skinPacket->matrData.epiDiffColor[2];
            break;
        case SRVs_EPI_DIFF_AMT_IDX:
            val[0] = skinPacket->matrData.epiDiffAmt;
            break;
        case SRVs_EPI_DIFF_ROUGH_IDX:
            val[0] = skinPacket->matrData.oilRoughness;
            break;

        case SRVs_EPI_SSS_COL_IDX:
            val[0] = skinPacket->matrData.epiSSSColor[0];
            val[1] = skinPacket->matrData.epiSSSColor[1];
            val[2] = skinPacket->matrData.epiSSSColor[2];
            break;
        case SRVs_EPI_SSS_AMT_IDX:
            val[0] = skinPacket->matrData.epiSSSAmt;
            break;
        case SRVs_EPI_SSS_DEPTH_IDX:
            val[0] = skinPacket->matrData.epiSSSDepth;
            break;

        case SRVs_DERM_SSS_COL_IDX:
            val[0] = skinPacket->matrData.dermSSSColor[0];
            val[1] = skinPacket->matrData.dermSSSColor[1];
            val[2] = skinPacket->matrData.dermSSSColor[2];
            break;
        case SRVs_DERM_SSS_AMT_IDX:
            val[0] = skinPacket->matrData.dermSSSAmt;
            break;
        case SRVs_DERM_SSS_DEPTH_IDX:
            val[0] = skinPacket->matrData.dermSSSDepth;
            break;

        case SRVs_SUB_SSS_COL_IDX:
            val[0] = skinPacket->matrData.subSSSColor[0];
            val[1] = skinPacket->matrData.subSSSColor[1];
            val[2] = skinPacket->matrData.subSSSColor[2];
            break;
        case SRVs_SUB_SSS_AMT_IDX:
            val[0] = skinPacket->matrData.subSSSAmt;
            break;
        case SRVs_SUB_SSS_DEPTH_IDX:
            val[0] = skinPacket->matrData.subSSSDepth;
            break;
    }

    return LXe_OK;
}

LxResult SkinPFX::pfx_Set(int id, void* packet, const float* val, void* /*item*/)
{
    LXpSkinShader* skinPacket = (LXpSkinShader*) packet;

    switch (id)
    {
        case SRVs_OIL_SPEC_COL_IDX:
            skinPacket->matrData.oilSpecColor[0] = val[0];
            skinPacket->matrData.oilSpecColor[1] = val[1];
            skinPacket->matrData.oilSpecColor[2] = val[2];
            break;
        case SRVs_OIL_SPEC_AMT_IDX:
            skinPacket->matrData.oilSpecAmt = val[0];
            break;
        case SRVs_OIL_SPEC_FRES_IDX:
            skinPacket->matrData.oilSpecFres = val[0];
            break;
        case SRVs_OIL_ROUGH_IDX:
            skinPacket->matrData.oilRoughness = val[0];
            break;

        case SRVs_OIL_REFL_COL_IDX:
            skinPacket->matrData.oilReflColor[0] = val[0];
            skinPacket->matrData.oilReflColor[1] = val[1];
            skinPacket->matrData.oilReflColor[2] = val[2];
            break;
        case SRVs_OIL_REFL_AMT_IDX:
            skinPacket->matrData.oilReflAmt = val[0];
            break;
        case SRVs_OIL_REFL_FRES_IDX:
            skinPacket->matrData.oilReflFres = val[0];
            break;

        case SRVs_EPI_DIFF_COL_IDX:
            skinPacket->matrData.epiDiffColor[0] = val[0];
            skinPacket->matrData.epiDiffColor[1] = val[1];
            skinPacket->matrData.epiDiffColor[2] = val[2];
            break;
        case SRVs_EPI_DIFF_AMT_IDX:
            skinPacket->matrData.epiDiffAmt = val[0];
            break;
        case SRVs_EPI_DIFF_ROUGH_IDX:
            skinPacket->matrData.oilRoughness = val[0];
            break;

        case SRVs_EPI_SSS_COL_IDX:
            skinPacket->matrData.epiSSSColor[0] = val[0];
            skinPacket->matrData.epiSSSColor[1] = val[1];
            skinPacket->matrData.epiSSSColor[2] = val[2];
            break;
        case SRVs_EPI_SSS_AMT_IDX:
            skinPacket->matrData.epiSSSAmt = val[0];
            break;
        case SRVs_EPI_SSS_DEPTH_IDX:
            skinPacket->matrData.epiSSSDepth = val[0];
            break;

        case SRVs_DERM_SSS_COL_IDX:
            skinPacket->matrData.dermSSSColor[0] = val[0];
            skinPacket->matrData.dermSSSColor[1] = val[1];
            skinPacket->matrData.dermSSSColor[2] = val[2];
            break;
        case SRVs_DERM_SSS_AMT_IDX:
            skinPacket->matrData.dermSSSAmt = val[0];
            break;
        case SRVs_DERM_SSS_DEPTH_IDX:
            skinPacket->matrData.dermSSSDepth = val[0];
            break;

        case SRVs_SUB_SSS_COL_IDX:
            skinPacket->matrData.subSSSColor[0] = val[0];
            skinPacket->matrData.subSSSColor[1] = val[1];
            skinPacket->matrData.subSSSColor[2] = val[2];
            break;
        case SRVs_SUB_SSS_AMT_IDX:
            skinPacket->matrData.subSSSAmt = val[0];
            break;
        case SRVs_SUB_SSS_DEPTH_IDX:
            skinPacket->matrData.subSSSDepth = val[0];
            break;
    }

    return LXe_OK;
}

namespace skinShader
{
    void initialize()
    {
        CLxGenericPolymorph* materialServer = new CLxPolymorph<SkinMaterial>;
        CLxGenericPolymorph* packetServer   = new CLxPolymorph<SkinPacket>;
        CLxGenericPolymorph* FXServer       = new CLxPolymorph<SkinPFX>;

        materialServer->AddInterface(new CLxIfc_CustomMaterial<SkinMaterial>);
        materialServer->AddInterface(new CLxIfc_ChannelUI<SkinMaterial>);
        materialServer->AddInterface(new CLxIfc_StaticDesc<SkinMaterial>);
        lx::AddServer(SRVs_SKIN_MATR, materialServer);

        packetServer->AddInterface(new CLxIfc_VectorPacket<SkinPacket>);
        packetServer->AddInterface(new CLxIfc_StaticDesc<SkinPacket>);
        lx::AddServer(SRVs_SKIN_VPACKET, packetServer);

        FXServer->AddInterface(new CLxIfc_PacketEffect<SkinPFX>);
        FXServer->AddInterface(new CLxIfc_StaticDesc<SkinPFX>);
        lx::AddServer(SRVs_SKIN_PFX, FXServer);
    }
}  // namespace skinShader
