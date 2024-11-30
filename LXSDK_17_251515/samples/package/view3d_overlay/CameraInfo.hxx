/*
 * CameraInfo.h - Camera computation utility
 *
 * Copyright 0000
 */
#pragma once

#define LXsICHAN_CAMERA_RESOVERRIDE "resOverride"
#define LXsICHAN_CAMERA_RESX        "resX"
#define LXsICHAN_CAMERA_RESY        "resY"
#define LXsICHAN_CAMERA_OVERSCAN    "overscan"

class CameraInfo
{
public:
    bool   valid;
    double apertureX, apertureY;
    double focalLength;
    double focusDist;
    double targetDist;
    double fStop;
    double eyeSep;
    double convergenceDist;
    int    filmFit;
    double offsetX, offsetY;
    double renderX, renderY;
    double overscan;
    double pixAspect;
    int    ortho;
    bool   useSensor;

    LXtVector  pos;
    LXtMatrix4 xfrm;
    LXtMatrix4 invXfrm;

    CameraInfo(CLxUser_Item& cam);

    // Read channels from camera item
    int readCameraChannels(CLxUser_ChannelRead chan);

    // get image plane coords in u,v=(0-1)
    bool WorldToUV(const LXtVector pos, LXtVector2 uv);

    // compute 3D position of screen spot at given depth
    bool UVToWorld(const LXtVector2 uv, const double z, LXtVector pos);

    // compute UV position of 3D position in camera coordinate system.
    bool Cam3DToUV(const LXtVector pos, LXtVector2 uv);

    // convert UV position in image to 3D position in camera coordinate system, at a depth 'z' from camera
    void UVToCam3D(const LXtVector2 uv, const double z, LXtVector pos);

    // compute effective aperture given image resolution and film fit modes
    void fitAperture(double* apX, double* apY);

private:
    CLxUser_Item m_cam;
    void         getZooms(double* zoomX, double* zoomY);
};
