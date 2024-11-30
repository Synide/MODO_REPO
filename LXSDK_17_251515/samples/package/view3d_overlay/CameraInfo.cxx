/*
 * CameraInfo.cpp - Camera computation utility
 *
 * Copyright 0000
 */

#include <lx_action.hpp>
#include <lx_item.hpp>
#include <lx_locator.hpp>
#include <lxidef.h>
#include <lxu_math.hpp>

#include "CameraInfo.hxx"

CameraInfo::CameraInfo(CLxUser_Item& cam)
{
    apertureX = apertureY = focusDist = fStop = convergenceDist = 1;
    focalLength = eyeSep = 0.01;
    lx::Matrix4Ident(xfrm);
    lx::Matrix4Ident(invXfrm);
    LXx_VCLR(pos);
    valid     = false;
    overscan  = 0;
    useSensor = false;
    m_cam     = cam;
};

int CameraInfo::readCameraChannels(CLxUser_ChannelRead chan)
{
    unsigned index, n = 0;
    if (!m_cam.test())
        return 0;

    if (LXx_OK(m_cam.ChannelLookup(LXsICHAN_CAMERA_APERTUREX, &index)))
    {
        apertureX = chan.FValue(m_cam, index);
        n++;
    }
    if (LXx_OK(m_cam.ChannelLookup(LXsICHAN_CAMERA_APERTUREY, &index)))
    {
        apertureY = chan.FValue(m_cam, index);
        n++;
    }
    if (LXx_OK(m_cam.ChannelLookup(LXsICHAN_CAMERA_FOCALLEN, &index)))
    {
        focalLength = chan.FValue(m_cam, index);
        n++;
    }
    if (LXx_OK(m_cam.ChannelLookup(LXsICHAN_CAMERA_FOCUSDIST, &index)))
    {
        focusDist = chan.FValue(m_cam, index);
        n++;
    }
    if (LXx_OK(m_cam.ChannelLookup(LXsICHAN_CAMERA_FSTOP, &index)))
    {
        fStop = chan.FValue(m_cam, index);
        n++;
    }
    if (LXx_OK(m_cam.ChannelLookup(LXsICHAN_CAMERA_IODIST, &index)))
    {
        eyeSep = chan.FValue(m_cam, index);
        n++;
    }
    if (LXx_OK(m_cam.ChannelLookup(LXsICHAN_CAMERA_CONVDIST, &index)))
    {
        convergenceDist = chan.FValue(m_cam, index);
        n++;
    }
    if (LXx_OK(m_cam.ChannelLookup(LXsICHAN_CAMERA_FILMFIT, &index)))
    {
        filmFit = chan.IValue(m_cam, index);
        n++;
    }
    if (LXx_OK(m_cam.ChannelLookup(LXsICHAN_CAMERA_PROJTYPE, &index)))
    {
        ortho = chan.IValue(m_cam, index);
        n++;
    }
    if (LXx_OK(m_cam.ChannelLookup(LXsICHAN_CAMERA_OFFSETX, &index)))
    {
        offsetX = chan.FValue(m_cam, index);
        n++;
    }
    if (LXx_OK(m_cam.ChannelLookup(LXsICHAN_CAMERA_OFFSETY, &index)))
    {
        offsetY = chan.FValue(m_cam, index);
        n++;
    }
    if (LXx_OK(m_cam.ChannelLookup(LXsICHAN_CAMERA_TARGET, &index)))
    {
        targetDist = chan.FValue(m_cam, index);
        n++;
    }
    pixAspect = 1.0;
    if (LXx_OK(m_cam.ChannelLookup(LXsICHAN_CAMERA_RESOVERRIDE, &index)))
    {
        if (chan.IValue(m_cam, index))
        {  // get override values
            if (LXx_OK(m_cam.ChannelLookup(LXsICHAN_CAMERA_RESX, &index)))
            {
                renderX = chan.IValue(m_cam, index);
                n++;
            }
            if (LXx_OK(m_cam.ChannelLookup(LXsICHAN_CAMERA_RESY, &index)))
            {
                renderY = chan.IValue(m_cam, index);
                n++;
            }
        }
        else
        {  // find render item
            CLxUser_Scene scene;
            CLxUser_Item  render;
            m_cam.GetContext(scene);
            scene.AnyItemOfType(CLxItemType(LXsITYPE_POLYRENDER), render);
            if (!render.test())
                return 0;
            if (LXx_OK(render.ChannelLookup(LXsICHAN_POLYRENDER_RESX, &index)))
            {
                renderX = chan.IValue(render, index);
                n++;
            }
            if (LXx_OK(render.ChannelLookup(LXsICHAN_POLYRENDER_RESY, &index)))
            {
                renderY = chan.IValue(render, index);
                n++;
            }
            if (LXx_OK(render.ChannelLookup(LXsICHAN_POLYRENDER_PASPECT, &index)))
            {
                pixAspect = chan.FValue(render, index);
                n++;
            }
        }
        n++;
    }
    CLxUser_Matrix uxfrm;

    if (LXx_OK(m_cam.ChannelLookup(LXsICHAN_XFRMCORE_WORLDMATRIX, &index)))
    {
        if (chan.Object(m_cam, index, uxfrm))
        {
            uxfrm.Get4(xfrm);
            uxfrm.GetOffset(pos);
            lx::MatrixInvert(xfrm, invXfrm);
        }
    }
    valid = true;
    return n;
}

void CameraInfo::fitAperture(double* apX, double* apY)
{
    double aperX = apertureX, aperY = apertureY;
    double cAspect = apertureX / apertureY;
    double fAspect = pixAspect * renderX / renderY;
    if (cAspect > fAspect)
    {
        switch (filmFit)
        {
            case LXi_CAMERA_FILMFIT_FILL:
            case LXi_CAMERA_FILMFIT_VERTICAL:
                aperX *= fAspect / cAspect;
                break;

            case LXi_CAMERA_FILMFIT_HORIZONTAL:
            case LXi_CAMERA_FILMFIT_OVERSCAN:
                aperY *= cAspect / fAspect;
                break;
        }
    }
    else if (cAspect < fAspect)
    {
        switch (filmFit)
        {
            case LXi_CAMERA_FILMFIT_FILL:
            case LXi_CAMERA_FILMFIT_HORIZONTAL:
                aperY *= cAspect / fAspect;
                break;

            case LXi_CAMERA_FILMFIT_VERTICAL:
            case LXi_CAMERA_FILMFIT_OVERSCAN:
                aperX *= fAspect / cAspect;
                break;
        }
    }
    if (apX)
        apX[0] = aperX;
    if (apY)
        apY[0] = aperY;
}

void CameraInfo::getZooms(double* zoomX, double* zoomY)
{
    double aperX = apertureX, aperY = apertureY;
    if (!useSensor)
        fitAperture(&aperX, &aperY);

    *zoomX = 0.5 / focalLength;
    *zoomY = *zoomX * aperY;
    *zoomX *= aperX;
}

// Find the 3D position in camera coord.s at depth z, of a spot in the camera view/render
void CameraInfo::UVToCam3D(const LXtVector2 uv, const double z, LXtVector outPos)
{
    double x, y, v, zx, zy;

    x = 2 * uv[0] - 1.0;  // convert from {0,1} range to {-1,1}
    y = 2 * uv[1] - 1.0;

    getZooms(&zx, &zy);

    v         = fabs(z);
    outPos[0] = v * zx * x;
    outPos[1] = v * zy * y;

    outPos[2] = z;
}

// Find the position in the camera view/render of a 3D position in camera coord.s, return false for positions not visible
bool CameraInfo::Cam3DToUV(const LXtVector inPos, LXtVector2 uv)
{
    double z = fabs(inPos[2]);
    double zoomX, zoomY;
    getZooms(&zoomX, &zoomY);

    uv[0] = inPos[0] / (zoomX * z);
    uv[1] = inPos[1] / (zoomY * z);
    uv[0] = (uv[0] + 1.0) / 2;
    uv[1] = (uv[1] + 1.0) / 2;
    return (uv[0] >= 0 && uv[0] <= 1.0 && uv[1] >= 0 && uv[1] <= 1.0 && inPos[2] >= 0);
}

bool CameraInfo::WorldToUV(const LXtVector inPos, LXtVector2 uv)
{
    LXtVector cpos;
    lx::Matrix4Multiply(cpos, invXfrm, inPos);  // convert to camera space pos

    return Cam3DToUV(cpos, uv);
}

// compute 3D position of screen spot at given depth
bool CameraInfo::UVToWorld(const LXtVector2 uv, const double z, LXtVector outPos)
{
    LXtVector cpos;
    UVToCam3D(uv, z, cpos);
    lx::Matrix4Multiply(outPos, xfrm, cpos);  // convert to world pos
    return true;
}
