/*
 * Plug-in ground plane item type.
 *
 * Copyright 0000
 *
 */
#pragma once

#include <lx_action.hpp>
#include <lx_item.hpp>
#include <lx_package.hpp>
#include <lx_raycast.hpp>
#include <lx_select.hpp>
#include <lx_surface.hpp>
#include <lx_tableau.hpp>
#include <lx_value.hpp>
#include <lx_vector.hpp>
#include <lx_vertex.hpp>
#include <lx_vmodel.hpp>
#include <lx_volume.hpp>
#include <lxlog.h>
#include <lxu_geometry.hpp>
#include <lxu_log.hpp>
#include <lxvolume.h>

class GPlaneLog : public CLxLuxologyLogMessage
{
public:
    GPlaneLog() : CLxLuxologyLogMessage("gplane-item")
    {
    }

    const char* GetFormat() override
    {
        return "GPlane Object";
    }
};

/*
 * Class Declarations
 *
 * These have to come before their implementions because they reference each
 * other. Descriptions are attached to the implementations.
 */
class GPlanePackage;

class GPlaneElement : public CLxImpl_TableauVolume  // ,
//	public CLxImpl_TableauInstance  // [TODO] Need tins_Properties and tins_GetTransform?
{
    GPlaneLog gpl_log;

public:
    CLxUser_PacketService pkt_service;
    CLxUser_TableauVertex vrt_desc;
    int                   f_pos[4];
    LXtMatrix             xfrm, invXfrm;
    LXtVector             itemPos;
    double                size, fogHeight, nearClip, farClip, density, rate;
    char*                 material;
    int                   ground, clipping, fog, axis;

    unsigned ray_offset;
    unsigned nrm_offset;
    unsigned pos_offset;
    unsigned vol_offset;
    unsigned den_offset;

    void RayTransform(LXpSampleRay* sRay, LXtVector pos, LXtVector opos, LXtVector dir);

    float PlaneHit(LXpSampleRay* sRay, LXpSampleSurfNormal* sNrm, LXtVector opos, LXtVector dir);

    float DensityFunc(LXtVector opos);

    int InsideBox(LXtVector opos, double size);

    LxResult tvol_Bound(LXtTableauBox bbox) override;
    unsigned tvol_FeatureCount(LXtID4 type) override;
    LxResult tvol_FeatureByIndex(LXtID4 type, unsigned int index, const char** name) override;
    LxResult tvol_SetVertex(ILxUnknownID vdesc) override;

    int tvol_Type() override;

    LxResult tvol_RenderInit(ILxUnknownID vector) override;

    LxResult tvol_RaySample(ILxUnknownID densityShader,
                            ILxUnknownID volumeShader,
                            ILxUnknownID vector,
                            ILxUnknownID raycastObj,
                            ILxUnknownID raymarchObj) override;

    LxResult tvol_RayCast(ILxUnknownID densityShader, ILxUnknownID vector, ILxUnknownID raycastObj, double* dist, int* localShader) override;

    LxResult tvol_Density(ILxUnknownID densityShader, ILxUnknownID vector, ILxUnknownID raycastObj, const LXtVector pos, int wp, double* dens) override;

    // [TODO] Does a volumetric implement CLxImpl_TableauInstance?
};

class GPlanePackage;

class GPlaneInstance : public CLxImpl_PackageInstance, public CLxImpl_StringTag, public CLxImpl_TableauSource, public CLxImpl_ViewItem3D
{
    GPlaneLog gpl_log;

public:
    GPlanePackage*        src_pkg;
    CLxUser_Item          m_item;
    ILxUnknownID          inst_ifc;
    CLxUser_PacketService pkt_service;

    unsigned ray_offset;
    unsigned nrm_offset;
    unsigned pos_offset;

    LxResult pins_Initialize(ILxUnknownID item, ILxUnknownID super) override;
    void     pins_Cleanup(void) override;
    LxResult pins_SynthName(char* buf, unsigned len) override;
    unsigned pins_DupType(void) override;
    LxResult pins_TestParent(ILxUnknownID item) override;
    LxResult pins_Loading(void) override;
    LxResult pins_AfterLoad(void) override;
    void     pins_Doomed(void) override;

    LxResult stag_Get(LXtID4 type, const char** tag) override;

    LxResult tsrc_Elements(ILxUnknownID tblx) override;
    LxResult tsrc_PreviewUpdate(int chanIndex, int* update) override;

    LxResult vitm_Draw(ILxUnknownID itemChanRead, ILxUnknownID viewStrokeDraw, int selectionFlags, const LXtVector itemColor) override;

    LxResult vitm_HandleCount(int* count) override;

    LxResult vitm_HandleMotion(int handleIndex, int* motionType, double* min, double* max, LXtVector plane, LXtVector offset) override;

    LxResult vitm_HandleChannel(int handleIndex, int* chanIndex) override;

    LxResult vitm_HandleValueToPosition(int handleIndex, const double* chanValue, LXtVector position) override;

    LxResult vitm_HandlePositionToValue(int handleIndex, const LXtVector position, double* chanValue) override;
};

class GPlanePackage : public CLxImpl_Package
{
public:
    static LXtTagInfoDesc        descInfo[];
    CLxPolymorph<GPlaneInstance> gpl_factory;
    CLxPolymorph<GPlaneElement>  elt_factory;

    GPlanePackage();

    LxResult pkg_SetupChannels(ILxUnknownID addChan) override;
    LxResult pkg_TestInterface(const LXtGUID* guid) override;
    LxResult pkg_Attach(void** ppvObj) override;
};
