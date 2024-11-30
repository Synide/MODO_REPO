#pragma once

/*
 * OBJ Preset Browser
 *
 *  Copyright 0000
 */

#include <lx_image.hpp>
#include <lx_pretype.hpp>

class ObjPresetMetrics;
class ObjPresetType : public CLxImpl_PresetType
{
public:
    static LXtTagInfoDesc                 descInfo[];
    static CLxPolymorph<ObjPresetMetrics> metricFactory;

    static void Initialize();

    LxResult ptyp_Recognize(const char* path, const char** category) override;
    LxResult ptyp_Do(const char* path) override;
    LxResult ptyp_Metrics(const char* path, int flags, int w, int h, ILxUnknownID prevMetrics, void** ppvObj) override;
    LxResult ptyp_GenericThumbnailResource(const char* path, const char** resourceName) override;
};

class ObjPresetMetrics : public CLxImpl_PresetMetrics
{
public:
    ObjPresetMetrics() : metadata(nullptr), w(0), h(0)
    {
    }

    ~ObjPresetMetrics()
    {
        if (metadata)
            lx::ObjRelease(metadata);
    }

    LxResult pmet_Flags(int* flags) override;
    LxResult pmet_Metadata(void** ppvObj) override;
    LxResult pmet_Markup(void** ppvObj) override;
    LxResult pmet_ThumbnailImage(void** ppvObj) override;
    LxResult pmet_ThumbnailIdealSize(int* idealW, int* idealH) override;

    CLxUser_Image image;
    void*         metadata;
    int           w, h;
};
