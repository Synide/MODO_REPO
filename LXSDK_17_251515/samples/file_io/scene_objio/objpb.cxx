/*
 * Obj Preset Browser
 *
 * Copyright 0000
 *
 */

#include "objpb.hxx"
#include "objio.hxx"

#include <lx_command.hpp>

////////////////////////////////////////////////
// ObjPresetType

LXtTagInfoDesc ObjPresetType::descInfo[] = { { LXsSRV_USERNAME, "Obj" },
                                             { LXsPBS_CATEGORY, "ObjPB" },
                                             { LXsPBS_CANAPPLY, "false" },
                                             { LXsPBS_CANDO, "true" },
                                             { LXsPBS_DYNAMICTHUMBNAILS, "true" },
                                             { LXsPBS_SYNTHETICSUPPORT, "false" },
                                             { nullptr } };

CLxPolymorph<ObjPresetMetrics> ObjPresetType::metricFactory;

void ObjPresetType::Initialize()
{
    CLxGenericPolymorph* srv;

    // Preset Type
    srv = new CLxPolymorph<ObjPresetType>;
    srv->AddInterface(new CLxIfc_PresetType<ObjPresetType>);
    srv->AddInterface(new CLxIfc_StaticDesc<ObjPresetType>);
    lx::AddServer("ObjPT", srv);

    ObjPresetType::metricFactory.AddInterface(new CLxIfc_PresetMetrics<ObjPresetMetrics>);
}

LxResult ObjPresetType::ptyp_Do(const char* path)
{
    CLxUser_CommandService cmdSrv;
    std::string            loadCmd = "app.load \"" + std::string(path) + "\"";
    cmdSrv.ExecuteArgString(LXiCMD_EXEC_WITH_PARENTS_FLAGS, LXiCTAG_NULL, loadCmd.c_str());
    return LXe_OK;
}

LxResult ObjPresetType::ptyp_Recognize(const char* path, const char** category)
{
    if (!OBJ_Options::Recognize(path))
        return LXe_FALSE;

    *category = "Obj";
    return LXe_TRUE;
}

LxResult ObjPresetType::ptyp_Metrics(const char* /*path*/, int /*flags*/, int w, int h, ILxUnknownID prevMetrics, void** ppvObj)
{
    // Create a generic Metrics, so that GenericThumbnail is launched
    if (prevMetrics)
    {
        lx::ObjAddRef(prevMetrics);
        *ppvObj = prevMetrics;
        return LXe_OK;
    }

    // Create the new metrics.
    ObjPresetMetrics* metrics = metricFactory.Alloc(ppvObj);
    metrics->w                = w;
    metrics->h                = h;

    return LXe_OK;
}

LxResult ObjPresetType::ptyp_GenericThumbnailResource(const char* /*path*/, const char** resourceName)
{
    *resourceName = "item.thumbnail.undefined";
    return LXe_OK;
}

/////////////////////////////////////////////////////
// ObjPresetMetrics

LxResult ObjPresetMetrics::pmet_Flags(int* flags)
{
    *flags = 0;
    return LXe_OK;
}

LxResult ObjPresetMetrics::pmet_Metadata(void** ppvObj)
{
    if (!metadata)
        return LXe_NOTIMPL;

    *ppvObj = metadata;
    lx::ObjAddRef(*ppvObj);

    return LXe_OK;
}

LxResult ObjPresetMetrics::pmet_Markup(void** /*ppvObj*/)
{
    return LXe_NOTIMPL;
}

LxResult ObjPresetMetrics::pmet_ThumbnailImage(void** ppvObj)
{
    // If we already have an image, just return that
    if (image.test())
    {
        *ppvObj = image;
        lx::ObjAddRef(*ppvObj);
        return LXe_OK;
    }

    return LXe_NOTFOUND;
}

LxResult ObjPresetMetrics::pmet_ThumbnailIdealSize(int* idealW, int* idealH)
{
    *idealW = 0;
    *idealH = 0;

    return LXe_OK;
}
