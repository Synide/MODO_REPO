/*
 * sdk.rendercache command.
 *
 * Copyright 0000
 *
 * This command is an example on how to use the ILxRenderCache.
 * There are several simple commands that show how to use the render cache.
 *
 * To print information in the render cache use this command
 *    sdk.rcache.print
 *
 * To save the render cache content into file
 *    sdk.rcache.save test outPath:"c:\temp\test.mrc"
 *
 * There's also a listener example
 *    sdk.rcache.listen
 */

#include <lx_item.hpp>
#include <lx_listener.hpp>
#include <lx_log.hpp>
#include <lx_rendercache.hpp>
#include <lx_surface.hpp>

#include <lxidef.h>
#include <lxu_command.hpp>
#include <lxu_select.hpp>

#include <lx_vertex.hpp>

#include "mrcwriter.hxx"

#include <cstdio>
#include <map>

#ifdef _MSC_VER
#define snprintf _snprintf
#endif

//=============================================================================
// Helper class to write into MODO master log
//=============================================================================
class MasterLog
{
public:
    //-------------------------------------------------------------------------
    // Return instance
    //-------------------------------------------------------------------------
    static MasterLog* GetInstance()
    {
        if (m_log == nullptr)
            m_log = new MasterLog();

        return m_log;
    }

    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    static void Clear()
    {
        delete m_log;
        m_log = nullptr;
    }

    //-------------------------------------------------------------------------
    // Append new message to log
    //-------------------------------------------------------------------------
    void Append(int type, const char* msg, ...)
    {
        if (m_masterLog.test())
        {
            va_list args;
            va_start(args, msg);
            Append(type, msg, args);
            va_end(args);
        }
    }

    //-------------------------------------------------------------------------
    // Append new message to log
    //-------------------------------------------------------------------------
    void Append(int type, const char* msg, va_list args)
    {
        if (m_masterLog.test())
        {
            vsnprintf(m_msgBuff, sizeof(m_msgBuff) - 1, msg, args);

            m_logSvc.NewEntry(type, m_msgBuff, m_logEntry);
            m_masterLog.AddEntry(m_logEntry);
        }
    }

private:
    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    MasterLog()
    {
        m_logSvc.GetSubSystem(LXsLOG_LOGSYS, m_masterLog);
    }

    static MasterLog* m_log;

    char               m_msgBuff[512];
    CLxUser_LogService m_logSvc;
    CLxUser_LogEntry   m_logEntry;
    CLxUser_Log        m_masterLog;
};

//=============================================================================
//=============================================================================
MasterLog* MasterLog::m_log = nullptr;

//=============================================================================
// Base class for render cache commands
//=============================================================================
class CmdRenderCacheBase : public CLxBasicCommand
{
protected:
    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    bool CreateRenderCache(CLxUser_RenderCache& rcache, bool autoUpdates = true, bool useDisp = true, bool genFur = true)
    {
        CLxUser_RenderCacheService rcacheSvc;
        unsigned                   flags;

        // The render cache geo cache is populated on-demand.
        // The geo cache surfaces are going to be created but they wont contain any vertex data
        // to minimize the memory load.
        // Geo cache surface data can be loaded using GeoCacheSurface::LoadSegments().
        // Once surface's data is not needed anymore then use the GeoCacheSurface::UnloadSegments().
        //
        // By default render cache geo cache will populate displaced surfaces and generate fur and
        // the current scene will be tracked.
        // By default auto updates are turned on.
        // That means if something changes in the scene, the render cache is going to be automatically
        // updated. You can turn off that behavior.
        // Also, you can force the full render cache rebuild on each update.
        // (There can be procedural items, which don't trigger automatic updates).

        flags = LXfRENDERCACHE_TRACK_CURRENT_SCENE;

        if (!autoUpdates)
            flags |= LXfRENDERCACHE_TURN_OFF_AUTO_UPDATES;

        if (useDisp)
            flags |= LXfRENDERCACHE_GEOCACHE_DISPLACE;

        if (genFur)
            flags |= LXfRENDERCACHE_GEOCACHE_GENFUR;

        if (!rcacheSvc.NewRenderCache(rcache, flags))
        {
            Error("Failed to create render cache");
            return false;
        }

        return true;
    }

    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    void Error(const char* msgStr, ...)
    {
        int     len;
        va_list args;
        char    logMsgBuff[256];

        va_start(args, msgStr);
        len             = vsnprintf(logMsgBuff, sizeof(logMsgBuff) - 1, msgStr, args);
        logMsgBuff[len] = '\0';

        CLxUser_Message& msg = basic_Message();

        msg.SetCode(LXe_FAILED);
        msg.SetMsg("common", 99);
        msg.SetArg(1, logMsgBuff);

        va_end(args);
    }

    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    void LogAppend(int type, const char* msg, ...)
    {
        va_list args;

        va_start(args, msg);
        MasterLog::GetInstance()->Append(type, msg, args);
        va_end(args);
    }
};

//=============================================================================
// Simple command to print basic information about render cache geo surfaces
//=============================================================================
class CmdPrintRenderCache : public CmdRenderCacheBase
{
public:
    enum
    {
        CMDARGi_GeoDisplace = 0,
        CMDARGi_GenerateFur,
    };

    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    CmdPrintRenderCache()
    {
        dyna_Add("displace", LXsTYPE_BOOLEAN);
        basic_SetFlags(CMDARGi_GeoDisplace, LXfCMDARG_OPTIONAL);

        dyna_Add("genFur", LXsTYPE_BOOLEAN);
        basic_SetFlags(CMDARGi_GenerateFur, LXfCMDARG_OPTIONAL);
    }

    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    int basic_CmdFlags() override
    {
        return LXfCMD_MODEL;
    }

    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    void cmd_Execute(unsigned /*flags*/) override
    {
        CLxUser_RenderCache rcache;
        bool                geoDisplace = false, genFur = false;

        if (dyna_IsSet(CMDARGi_GeoDisplace))
            attr_GetBool(CMDARGi_GeoDisplace, &geoDisplace);

        if (dyna_IsSet(CMDARGi_GenerateFur))
            attr_GetBool(CMDARGi_GenerateFur, &genFur);

        if (!CreateRenderCache(rcache, false, geoDisplace, genFur))
            return;

        int                     nSrfs;
        CLxUser_GeoCacheSurface srf;
        LxResult                res;

        res = rcache.GeoSurfaceCount(&nSrfs);
        if (LXx_FAIL(res))
        {
            Error("Failed to obtain number of surfaces");
            return;
        }

        LogAppend(LXe_INFO, "Num geo cache surfaces:%d", nSrfs);

        for (int c = 0; c < nSrfs; ++c)
        {
            res = rcache.GetGeoSurface(c, srf);
            if (LXx_FAIL(res))
            {
                Error("Failed to obtain geo cache surface at index:%d", c);
                break;
            }

            PrintGeoSurface(srf);
        }
    }

    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    void PrintGeoSurface(CLxUser_GeoCacheSurface& srf)
    {
        const char*              srfName = nullptr;
        int                      nSegs, nPols, nVrts;
        unsigned                 srfID;
        LXtGeoCacheSrfVisibility vis;
        unsigned                 visFlags;
        char                     visFlagsStr[32];
        LXtBBox                  bbox;
        LXtVector                pos;
        LXtMatrix                rot;
        LXtVector                scl;
        CLxUser_TableauVertex    vrt;
        CLxUser_GeoCacheSurface  srcSrf;
        int                      srcSrfID;
        int                      instIndex;
        CLxUser_Item             srcItem;
        const char*              srcItemName = nullptr;

        if (!srf.IsValid())
        {
            LogAppend(LXe_INFO, "Skipping invalid surface:%d", srf.ID());
            return;
        }

        if (srf.GetSourceItem(srcItem))
            srcItem.UniqueName(&srcItemName);

        srf.ShaderMaskName(&srfName);
        srfID = srf.ID();

        // For instanced geo surfaces geometry segments wont be populated, instead
        // they're stored in the source surface
        // The instance will contain different bbox, transform and shader data.
        if (srf.GetSourceSurface(srcSrf))
            srcSrfID = srcSrf.ID();
        else
            srcSrfID = -1;

        instIndex = srf.InstanceIndex();
        srf.GetXfrm(pos, rot, scl, 0);

        srf.VisibilityFlags(&vis);
        visFlags = 0;
        visFlags |= vis.camera << 1;
        visFlags |= vis.indirect << 2;
        visFlags |= vis.reflection << 3;
        visFlags |= vis.refraction << 4;
        visFlags |= vis.subscatter << 5;
        visFlags |= vis.occlusion << 6;

        snprintf(visFlagsStr, sizeof(visFlagsStr) - 1, "%0X", visFlags);

        // We need to make sure that segments are loaded to get information
        srf.LoadSegments();

        srf.SegmentCount(&nSegs);
        srf.PolygonCount(&nPols);
        srf.VertexCount(&nVrts);
        srf.GetBBox(&bbox);

        if (!srf.IsInstanced())
        {
            // grab the vertex descriptor (ILxTableauVertex) to query vertex feature names
            vrt.set(srf.GetVertexDesc());

            // Print surface information into log
            LogAppend(LXe_INFO, "Surface:%s id:%d pols:%d verts:%d segs:%d", srfName, srfID, nPols, nVrts, nSegs);

            if (nPols || nVrts)
            {
                LogAppend(LXe_INFO, "   sourceItem:%s", srcItemName);
                LogAppend(LXe_INFO, "   pos:%lf %lf %lf", pos[0], pos[1], pos[2]);
                LogAppend(LXe_INFO, "   scl:%lf %lf %lf", scl[0], scl[1], scl[2]);

                // Print vertex feature names
                if (vrt.test())
                {
                    for (int vc = 0; vc < vrt.Count(); ++vc)
                    {
                        LXtID4      type;
                        const char* name;
                        unsigned    offset;

                        vrt.ByIndex(vc, &type, &name, &offset);

                        LogAppend(LXe_INFO, "    Vertex:%s %c%c%c%c", name, type >> 24, type >> 16, type >> 8, type & 0xff);
                    }
                }
            }
        }
        else
        {
            // Print surface information into log
            LogAppend(LXe_INFO, "Surface:%s id:%d (source:%d instIndex:%d) pols:%d verts:%d", srfName, srfID, srcSrfID, instIndex, nPols, nVrts, nSegs);
        }

        LogAppend(LXe_INFO, "   MaterialPTag:%s", srf.MaterialPTag());
        LogAppend(LXe_INFO, "   PartPTag:%s", srf.PartPTag());
        LogAppend(LXe_INFO, "   PickPTag:%s", srf.PickPTag());

        for (int sc = 0; sc < nSegs && nPols && nVrts; ++sc)
        {
            CLxUser_GeoCacheSegment seg;

            srf.GetSegment(sc, seg);
            if (seg.test())
            {
                int nSegVrts;
                int nSegPols;

                seg.VertexCount(&nSegVrts);
                seg.PolygonCount(&nSegPols);
                LogAppend(LXe_INFO, "   Segment:[%2d] pols:%d verts:%d", sc, nSegPols, nSegVrts);
            }
        }

        srf.UnloadSegments();
    }
};

//=============================================================================
//=============================================================================
class RenderCacheListener : public CLxImpl_RenderCacheListener
{
public:
    // Add render cache listener for given render cache
    // NOTE: This is a singleton class, i.e. only one listener instance will be
    //       created
    static RenderCacheListener* Create(CLxUser_RenderCache& rcache);

    RenderCacheListener();
    ~RenderCacheListener();

    void StartListener();
    void StopListener();

    void SetRenderCache(CLxUser_RenderCache& rcache);
    void ReleaseRenderCache();

    void SetEnabled(bool enabled);
    void PrintStats();
    void PrintStats(CLxUser_GeoCacheSurface& srf, int* nVrts = nullptr, int* nPols = nullptr);

    void rli_RenderCacheDestroy() override;
    void rli_UpdateBegin() override;
    void rli_UpdateEnd() override;
    void rli_GeoCacheSurfaceAdd(ILxUnknownID geoSurf) override;
    void rli_GeoCacheSurfaceRemove(ILxUnknownID geoSurf) override;
    void rli_GeoCacheSurfaceGeoUpdate(ILxUnknownID geoSurf) override;
    void rli_GeoCacheSurfaceXformUpdate(ILxUnknownID geoSurf) override;
    void rli_GeoCacheSurfaceShaderUpdate(ILxUnknownID geoSurf) override;

private:
    CLxUser_RenderCache m_rcache;
    ILxUnknownID        m_listenerIfc;
    bool                m_enabled;

    std::vector<ILxUnknownID> m_updatedGeoSrfs;
};

//=============================================================================
//=============================================================================
class CFactories
{
public:
    CFactories()
    {
        rli.AddInterface(new CLxIfc_RenderCacheListener<RenderCacheListener>());
    }

    CLxPolymorph<RenderCacheListener> rli;
};

static CFactories* pF = nullptr;

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
RenderCacheListener* RenderCacheListener::Create(CLxUser_RenderCache& rcache)
{
    static RenderCacheListener* listener = nullptr;

    if (listener == nullptr)
    {
        ILxUnknownID         listenerIfc;
        CLxUser_ListenerPort port(rcache);

        listenerIfc = pF->rli.Spawn();
        port.AddListener(listenerIfc);
        listener = LXCWxOBJ(listenerIfc, RenderCacheListener);

        listener->m_listenerIfc = listenerIfc;
        listener->m_rcache      = rcache;
    }

    return listener;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
RenderCacheListener::RenderCacheListener() : m_listenerIfc(nullptr), m_enabled(true)
{
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
RenderCacheListener::~RenderCacheListener()
{
    StopListener();

    m_listenerIfc = nullptr;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void RenderCacheListener::StartListener()
{
    if (m_rcache.test())
    {
        CLxUser_ListenerPort port(m_rcache);

        if (m_listenerIfc && port.test())
            port.AddListener(m_listenerIfc);
    }
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void RenderCacheListener::StopListener()
{
    if (m_rcache.test())
    {
        CLxUser_ListenerPort port(m_rcache);

        if (m_listenerIfc && port.test())
            port.RemoveListener(m_listenerIfc);
    }
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void RenderCacheListener::SetRenderCache(CLxUser_RenderCache& rcache)
{
    ReleaseRenderCache();

    m_rcache = rcache;
    StartListener();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void RenderCacheListener::ReleaseRenderCache()
{
    StopListener();
    if (m_rcache)
        m_rcache.clear();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void RenderCacheListener::SetEnabled(bool enabled)
{
    m_enabled = enabled;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void RenderCacheListener::PrintStats()
{
    int nSrfs  = 0;
    int nVrts  = 0;
    int nPols  = 0;
    int nInsts = 0;

    m_rcache.GeoSurfaceCount(&nSrfs);
    MasterLog::GetInstance()->Append(LXe_INFO, "RCL Surfaces");

    for (int sc = 0; sc < nSrfs; ++sc)
    {
        CLxUser_GeoCacheSurface srf;

        if (m_rcache.GetGeoSurface(sc, srf))
        {
            if (srf.IsInstanced())
                ++nInsts;

            PrintStats(srf, &nVrts, &nPols);
        }
    }

    MasterLog::GetInstance()->Append(LXe_INFO, "RCL stats srfs:%d pols:%d vrts:%d insts:%d", nSrfs, nPols, nVrts, nInsts);
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void RenderCacheListener::PrintStats(CLxUser_GeoCacheSurface& srf, int* nVrts, int* nPols)
{
    CLxUser_SceneService sceneSvc;
    CLxUser_Item         item;
    const char*          itemName;
    const char*          itemType;

    int nSegs = 0, nSrfVrts = 0, nSrfPols = 0;

    if (!srf.IsInstanced())
    {
        srf.SegmentCount(&nSegs);
        if (nSegs == 0)
        {
            srf.LoadSegments();
            srf.SegmentCount(&nSegs);
        }

        srf.PolygonCount(&nSrfPols);
        srf.VertexCount(&nSrfVrts);

        if (nVrts)
            *nVrts += nSrfVrts;

        if (nPols)
            *nPols += nSrfPols;
    }

    srf.GetSourceItem(item);
    item.UniqueName(&itemName);
    sceneSvc.ItemTypeName(item.Type(), &itemType);

    if (!srf.IsInstanced())
    {
        MasterLog::GetInstance()->Append(
        LXe_INFO, "   Surface:%d item:%s (%s) valid:%d segs:%d pols:%d verts:%d", srf.ID(), itemName, itemType, srf.IsValid(), nSegs, nSrfPols, nSrfVrts);
    }
    else
    {
        CLxUser_GeoCacheSurface srcSrf;
        CLxUser_Item            srcItem;
        const char*             srcItemName;

        srf.GetSourceSurface(srcSrf);
        srcSrf.GetSourceItem(srcItem);
        srcItem.UniqueName(&srcItemName);

        MasterLog::GetInstance()->Append(
        LXe_INFO, "   Surface:%d item:%s (%s) valid:%d instId:%d src:%s", srf.ID(), itemName, itemType, srf.IsValid(), srf.InstanceIndex(), srcItemName);
    }

    // Commented out the code below due to performance reasons on heavy scenes
    //	for (int sc = 0; sc < nSegs; ++sc)
    //	{
    //		CLxUser_GeoCacheSegment		seg;

    //		if (!srf.GetSegment (sc, seg))
    //			break;

    //		LXtBBox		bbox;
    //		int			nSegVrts = 0, nSegPols = 0, nVrtsPerPoly = 0;

    //		seg.GetBBox (&bbox);
    //		seg.VertexCount (&nSegVrts);
    //		seg.PolygonCount (&nSegPols);
    //		seg.VertsPerPoly (&nVrtsPerPoly);

    //		MasterLog::GetInstance()->Append (
    //			LXe_INFO,
    //			"      Segment pols:%d verts:%d vrtsPerPoly:%d",
    //			nSegPols, nSegVrts, nVrtsPerPoly);
    //	}

    srf.UnloadSegments();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void RenderCacheListener::rli_RenderCacheDestroy()
{
    if (m_enabled)
        MasterLog::GetInstance()->Append(LXe_INFO, "RCL:Destroy()");
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void RenderCacheListener::rli_UpdateBegin()
{
    if (!m_enabled)
        return;

    MasterLog::GetInstance()->Append(LXe_INFO, "RCL:UpdateBegin()");
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void RenderCacheListener::rli_UpdateEnd()
{
    if (!m_enabled)
        return;

    int srfInd = 0;

    MasterLog::GetInstance()->Append(LXe_INFO, "RCL:UpdateEnd()");

    for (auto it = m_updatedGeoSrfs.begin(); it != m_updatedGeoSrfs.end(); it++, srfInd++)
    {
        CLxUser_GeoCacheSurface srf(*it);

        if (!srf.test())
        {
            MasterLog::GetInstance()->Append(LXe_WARNING, "Failed to access updated surface at index:%d", srfInd);
            continue;
        }

        PrintStats(srf);
    }

    m_updatedGeoSrfs.clear();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void RenderCacheListener::rli_GeoCacheSurfaceAdd(ILxUnknownID geoSurf)
{
    if (m_enabled)
    {
        CLxUser_GeoCacheSurface srf(geoSurf);
        CLxUser_SceneService    sceneSvc;
        CLxUser_Item            item;
        const char*             itemName;
        const char*             itemType;

        srf.GetSourceItem(item);
        item.UniqueName(&itemName);
        sceneSvc.ItemTypeName(item.Type(), &itemType);

        MasterLog::GetInstance()->Append(LXe_INFO, "   GeoCacheSurfaceAdd:%d inst:%d item:%s (%s)", srf.ID(), srf.InstanceIndex(), itemName, itemType);

        m_updatedGeoSrfs.push_back(geoSurf);
    }
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void RenderCacheListener::rli_GeoCacheSurfaceRemove(ILxUnknownID geoSurf)
{
    if (m_enabled)
    {
        CLxUser_GeoCacheSurface srf(geoSurf);

        MasterLog::GetInstance()->Append(LXe_INFO, "   GeoCacheSurfaceRemove:%d inst:%d", srf.ID(), srf.InstanceIndex());
    }
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void RenderCacheListener::rli_GeoCacheSurfaceGeoUpdate(ILxUnknownID geoSurf)
{
    if (m_enabled)
    {
        CLxUser_GeoCacheSurface srf(geoSurf);

        // NOTE: It's not safe to call LoadSegments() here, it should be done
        // after the RenderCacheUpdateEnd() is called.

        MasterLog::GetInstance()->Append(LXe_INFO, "   GeoCacheSurfaceGeoUpdate:%d inst:%d valid:%d", srf.ID(), srf.InstanceIndex(), srf.IsValid());

        m_updatedGeoSrfs.push_back(geoSurf);
    }
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void RenderCacheListener::rli_GeoCacheSurfaceXformUpdate(ILxUnknownID geoSurf)
{
    if (m_enabled)
    {
        CLxUser_GeoCacheSurface srf(geoSurf);

        MasterLog::GetInstance()->Append(LXe_INFO, "   GeoCacheSurfaceXformUpdate:%d inst:%d", srf.ID(), srf.InstanceIndex());

        m_updatedGeoSrfs.push_back(geoSurf);
    }
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void RenderCacheListener::rli_GeoCacheSurfaceShaderUpdate(ILxUnknownID geoSurf)
{
    if (m_enabled)
    {
        CLxUser_GeoCacheSurface srf(geoSurf);

        MasterLog::GetInstance()->Append(LXe_INFO, "   GeoCacheSurfaceShaderUpdate:%d inst:%d", srf.ID(), srf.InstanceIndex());

        m_updatedGeoSrfs.push_back(geoSurf);
    }
}

enum
{
    CMDARGi_Enable = 0,
    CMDARGi_PrintStats,
    CMDARGi_ReInit,
    CMDARGi_Stop,
    CMDARGi_Start
};

//=============================================================================
//=============================================================================
class CmdRenderCacheListen : public CmdRenderCacheBase
{
public:
    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    CmdRenderCacheListen()
    {
        dyna_Add("enable", LXsTYPE_BOOLEAN);
        basic_SetFlags(CMDARGi_Enable, LXfCMDARG_OPTIONAL);

        dyna_Add("print", LXsTYPE_BOOLEAN);
        basic_SetFlags(CMDARGi_PrintStats, LXfCMDARG_OPTIONAL);

        dyna_Add("reinit", LXsTYPE_BOOLEAN);
        basic_SetFlags(CMDARGi_ReInit, LXfCMDARG_OPTIONAL);

        dyna_Add("stop", LXsTYPE_BOOLEAN);
        basic_SetFlags(CMDARGi_Stop, LXfCMDARG_OPTIONAL);

        dyna_Add("start", LXsTYPE_BOOLEAN);
        basic_SetFlags(CMDARGi_Start, LXfCMDARG_OPTIONAL);
    }

    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    int basic_CmdFlags() override
    {
        return LXfCMD_MODEL;
    }

    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    void cmd_Execute(unsigned /*flags*/) override
    {
        if (s_listener == nullptr)
        {
            CLxUser_RenderCache rcache;

            if (!CreateRenderCache(rcache))
                return;

            s_listener = RenderCacheListener::Create(rcache);
        }

        if (dyna_IsSet(CMDARGi_Enable))
        {
            bool     value;
            LxResult res;

            res = attr_GetBool(CMDARGi_Enable, &value);
            if (LXx_OK(res))
                s_listener->SetEnabled(value);
        }

        if (dyna_IsSet(CMDARGi_PrintStats))
        {
            bool     value;
            LxResult res;

            res = attr_GetBool(CMDARGi_PrintStats, &value);
            if (LXx_OK(res) && value)
                s_listener->PrintStats();
        }

        if (dyna_IsSet(CMDARGi_Stop))
        {
            bool     value;
            LxResult res;

            res = attr_GetBool(CMDARGi_Stop, &value);
            if (LXx_OK(res) && value)
                s_listener->StopListener();
        }

        if (dyna_IsSet(CMDARGi_Start))
        {
            bool     value;
            LxResult res;

            res = attr_GetBool(CMDARGi_Start, &value);
            if (LXx_OK(res) && value)
                s_listener->StartListener();
        }

        if (dyna_IsSet(CMDARGi_ReInit))
        {
            bool     value;
            LxResult res;

            res = attr_GetBool(CMDARGi_ReInit, &value);
            if (LXx_OK(res) && value)
            {
                CLxUser_RenderCache rcache;

                s_listener->ReleaseRenderCache();

                if (CreateRenderCache(rcache))
                    s_listener->SetRenderCache(rcache);
            }
        }
    }

private:
    static RenderCacheListener* s_listener;
};

RenderCacheListener* CmdRenderCacheListen::s_listener = nullptr;

//=============================================================================
// Helper class used by CmdSaveRenderCache
//=============================================================================
namespace
{
    class Buffer
    {
    public:
        Buffer() : m_data(nullptr), m_size(0)
        {
        }

        ~Buffer()
        {
            if (m_data)
                free(m_data);
        }

        template <typename T>
        bool Alloc(int count)
        {
            Free();

            m_size = count * sizeof(T);
            m_data = static_cast<char*>(malloc(m_size));

            return m_data != nullptr;
        }

        template <typename T>
        bool Resize(int count)
        {
            const int size = count * sizeof(T);

            if (size > m_size)
            {
                Free();
                return Alloc<T>(count);
            }

            return true;
        }

        void Free()
        {
            if (m_data)
            {
                free(m_data);
                m_data = nullptr;
            }

            m_size = 0;
        }

        template <typename T>
        T* GetPtr()
        {
            return (T*) m_data;
        }

    private:
        char* m_data;
        int   m_size;
    };
}  // namespace

//=============================================================================
//=============================================================================
class CmdSaveRenderCache : public CmdRenderCacheBase
{
public:
    CmdSaveRenderCache();
    ~CmdSaveRenderCache();

    int basic_CmdFlags() override;

    void cmd_Execute(unsigned int flags) override;

private:
    void SaveGeoSurface(CLxUser_GeoCacheSurface& srf);
    void SaveGeoSegment(CLxUser_GeoCacheSegment& seg);

    template <typename T>
    void WriteVertexFeature(CLxUser_GeoCacheSegment& seg, int feature, const char* typeStr, Buffer& data, int count);

    // members
    MrcWriter m_writer;
    Buffer    m_data;
};

enum
{
    CMDARGi_OutPath = 0
};

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
CmdSaveRenderCache::CmdSaveRenderCache()
{
    dyna_Add("outPath", LXsTYPE_FILEPATH);
    basic_SetFlags(CMDARGi_OutPath, LXfCMDARG_OPTIONAL);
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
CmdSaveRenderCache::~CmdSaveRenderCache()
{
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
int CmdSaveRenderCache::basic_CmdFlags()
{
    return LXfCMD_MODEL;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void CmdSaveRenderCache::cmd_Execute(unsigned int /*flags*/)
{
    CLxUser_RenderCache rcache;
    std::string         path;

    if (!CreateRenderCache(rcache))
        return;

    if (!dyna_String(CMDARGi_OutPath, path))
    {
        Error("Please specify the path argument");
        return;
    }

    if (!m_writer.Open(path.c_str()))
    {
        Error("Failed to open mrc file for write");
        return;
    }

    // Make sure that our block scopes are called before writer.Close()
    {
        m_writer.BlockBegin("RenderCache");
        m_writer.BlockBegin("GeoCache");

        // Visit geo cache surfaces and save them to mrc file
        int nSrfs;

        rcache.GeoSurfaceCount(&nSrfs);
        m_writer.WriteParam("surfaceCount", nSrfs);

        for (int sc = 0; sc < nSrfs; ++sc)
        {
            CLxUser_GeoCacheSurface srf;

            rcache.GetGeoSurface(sc, srf);
            if (srf.test())
            {
                m_writer.Separator();
                SaveGeoSurface(srf);
            }
        }

        m_writer.BlockEnd();
        m_writer.BlockEnd();
        m_writer.Close();
    }
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void CmdSaveRenderCache::SaveGeoSurface(CLxUser_GeoCacheSurface& srf)
{
    CLxUser_Item             item;
    const char*              itemName = nullptr;
    const char*              srfName  = nullptr;
    int                      nSegs, nPols, nVrts;
    int                      srfID;
    LXtGeoCacheSrfVisibility vis;
    unsigned                 visFlags;
    char                     visFlagsStr[32];
    LXtBBox                  bbox;
    LXtVector                pos;
    LXtMatrix                rot;
    LXtVector                scl;

    CLxUser_GeoCacheSurface srcSrf;
    int                     srcSrfID = -1;
    int                     instIndex;

    if (!srf.IsValid())
    {
        LogAppend(LXe_INFO, "Skipping invalid surface:%d", srf.ID());
        return;
    }

    if (srf.GetSourceItem(item))
        item.UniqueName(&itemName);

    srf.ShaderMaskName(&srfName);
    srfID = srf.ID();

    srf.GetSourceSurface(srcSrf);
    if (srcSrf.test())
        srcSrfID = srcSrf.ID();

    instIndex = srf.InstanceIndex();

    srf.VisibilityFlags(&vis);
    visFlags = 0;
    visFlags |= vis.camera << 1;
    visFlags |= vis.indirect << 2;
    visFlags |= vis.reflection << 3;
    visFlags |= vis.refraction << 4;
    visFlags |= vis.subscatter << 5;
    visFlags |= vis.occlusion << 6;

    snprintf(visFlagsStr, sizeof(visFlagsStr) - 1, "%0X", visFlags);

    srf.SegmentCount(&nSegs);
    if (nSegs == 0)
        srf.LoadSegments();

    srf.SegmentCount(&nSegs);
    srf.PolygonCount(&nPols);
    srf.VertexCount(&nVrts);
    srf.GetBBox(&bbox);

    // Write segment parameters
    MrcWriter::BlockScope gsrfBlock(m_writer.BlockBegin("GeoCacheSurface"));

    m_writer.WriteParam("name", srfName);
    m_writer.WriteParam("ID", srfID);
    m_writer.WriteParam("sourceSurfaceID", srcSrfID);
    m_writer.WriteParam("instanceIndex", instIndex);
    m_writer.WriteParam("visibilityFlags", visFlagsStr);
    m_writer.WriteParam("sourceItem", itemName);
    m_writer.WriteParam("segmentCount", nSegs);
    m_writer.WriteParam("polygonCount", nPols);
    m_writer.WriteParam("vertexCount", nVrts);
    m_writer.WriteParam("bbox", bbox);

    srf.GetXfrm(pos, rot, scl, 0);
    m_writer.WriteParam("pos0", pos);
    m_writer.WriteParam("rot0", rot);
    m_writer.WriteParam("scl0", scl);

    srf.GetXfrm(pos, rot, scl, 1);
    m_writer.WriteParam("pos1", pos);
    m_writer.WriteParam("rot1", rot);
    m_writer.WriteParam("scl1", scl);

    m_writer.Separator();

    // Visit geometry segments for this geo surface
    for (int sc = 0; sc < nSegs; sc++)
    {
        CLxUser_GeoCacheSegment seg;

        if (!srf.GetSegment(sc, seg))
            break;

        SaveGeoSegment(seg);
    }
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void CmdSaveRenderCache::SaveGeoSegment(CLxUser_GeoCacheSegment& seg)
{
    LXtBBox bbox;
    int     nVertsPerPoly = 0;
    int     nSegVrts      = 0;
    int     nSegPols      = 0;
    int     nUVs          = 0;
    int     hasFur        = 0;
    int     hasVel        = 0;
    int     hasRad        = 0;
    int     nPolyVerts    = 0;

    seg.GetBBox(&bbox);
    seg.VertexCount(&nSegVrts);
    seg.PolygonCount(&nSegPols);
    seg.VertsPerPoly(&nVertsPerPoly);
    nPolyVerts = nSegPols * nVertsPerPoly;

    // Some segments can be empty, i.e. no geometry will be generated (for example procedural items)
    if (nSegVrts && nSegPols && nPolyVerts)
    {
        MrcWriter::BlockScope gsegBlock(m_writer.BlockBegin("GeoCacheSegment"));

        m_writer.WriteParam("polygonCount", nSegPols);
        m_writer.WriteParam("vertexCount", nSegVrts);
        m_writer.WriteParam("vertsPerPoly", nVertsPerPoly);
        m_writer.WriteParam("bbox", bbox);

        WriteVertexFeature<LXtFVector>(seg, LXiRENDERCACHE_GEOVERT_OPOS, "FVector3", m_data, nSegVrts);
        WriteVertexFeature<LXtFVector>(seg, LXiRENDERCACHE_GEOVERT_ONRM, "FVector3", m_data, nSegVrts);

        seg.VertexFeatureCount(LXiRENDERCACHE_GEOVERT_OVEL, &hasVel);
        if (hasVel)
            WriteVertexFeature<LXtFVector>(seg, LXiRENDERCACHE_GEOVERT_OVEL, "FVector3", m_data, nSegVrts);

        seg.VertexFeatureCount(LXiRENDERCACHE_GEOVERT_RAD, &hasRad);
        if (hasRad)
            WriteVertexFeature<float>(seg, LXiRENDERCACHE_GEOVERT_RAD, "Float", m_data, nSegVrts);

        seg.VertexFeatureCount(LXiRENDERCACHE_GEOVERT_FUR, &hasFur);
        if (hasFur)
            WriteVertexFeature<LXtFVector>(seg, LXiRENDERCACHE_GEOVERT_FUR, "FurData", m_data, nSegVrts);

        seg.VertexFeatureCount(LXiRENDERCACHE_GEOVERT_UV, &nUVs);
        for (int uvc = 0; uvc < nUVs; ++uvc)
        {
            WriteVertexFeature<LXtFVector2>(seg, LXiRENDERCACHE_GEOVERT_UV + uvc, "FVector2", m_data, nSegVrts);
            WriteVertexFeature<LXtFVector>(seg, LXiRENDERCACHE_GEOVERT_DPDU + uvc, "FVector3", m_data, nSegVrts);
            WriteVertexFeature<LXtFVector>(seg, LXiRENDERCACHE_GEOVERT_DPDV + uvc, "FVector3", m_data, nSegVrts);
        }

        // Write polygon vertex indices
        if (nVertsPerPoly == 3)
        {
            m_data.Resize<int>(nPolyVerts);

            // Get all polygon vertex indices
            LxResult res = seg.GetPolygonVertexInds(m_data.GetPtr<int>(), nPolyVerts, 0);

            if (LXx_OK(res))
            {
                m_writer.Separator();
                MrcWriter::BlockScope scope(m_writer.BlockBegin("PolygonVertexIndices"));

                m_writer.WriteParam("type", "int");
                m_writer.WriteParam("count", nPolyVerts);
                m_writer.WriteArray("data", m_data.GetPtr<int>(), nPolyVerts);
            }
            else
            {
                Error("Failed to obtain polygon vertex indices");
            }
        }
    }
}

//-----------------------------------------------------------------------------
// Helper function to obtain vertex feature name
//-----------------------------------------------------------------------------
static void GetFeatureName(int feature, char* name)
{
    if (feature >= LXiRENDERCACHE_GEOVERT_UV && feature < LXiRENDERCACHE_GEOVERT_DPDU)
    {
        int index = feature - LXiRENDERCACHE_GEOVERT_UV;

        sprintf(name, "UV[%d]", index);
    }
    else if (feature >= LXiRENDERCACHE_GEOVERT_DPDU && feature < LXiRENDERCACHE_GEOVERT_DPDV)
    {
        int index = feature - LXiRENDERCACHE_GEOVERT_DPDU;

        sprintf(name, "DPDU[%d]", index);
    }
    else if (feature >= LXiRENDERCACHE_GEOVERT_DPDV)
    {
        int index = feature - LXiRENDERCACHE_GEOVERT_DPDV;

        sprintf(name, "DPDV[%d]", index);
    }
    else
    {
        switch (feature)
        {
            case LXiRENDERCACHE_GEOVERT_OPOS:
                strcpy(name, "OPOS");
                break;

            case LXiRENDERCACHE_GEOVERT_ONRM:
                strcpy(name, "ONRM");
                break;

            case LXiRENDERCACHE_GEOVERT_OVEL:
                strcpy(name, "OVEL");
                break;

            case LXiRENDERCACHE_GEOVERT_RAD:
                strcpy(name, "RAD");
                break;

            case LXiRENDERCACHE_GEOVERT_FUR:
                strcpy(name, "FUR");
                break;

            default:
                strcpy(name, "Unknown");
                break;
        }
    }
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
template <typename T>
void CmdSaveRenderCache::WriteVertexFeature(CLxUser_GeoCacheSegment& seg, int feature, const char* typeStr, Buffer& data, int count)
{
    char     featureName[64];
    LxResult res;

    GetFeatureName(feature, featureName);

    // Allocate enough data storage
    data.Resize<T>(count);

    res = seg.GetVertexFeature(feature, data.GetPtr<T>(), count, 0);
    if (LXx_OK(res))
    {
        m_writer.Separator();
        MrcWriter::BlockScope scope(m_writer.BlockBegin("VertexFeature"));

        m_writer.WriteParam("name", featureName);
        m_writer.WriteParam("type", typeStr);
        m_writer.WriteParam("count", count);
        m_writer.WriteArray("data", data.GetPtr<T>(), count);
    }
    else
    {
        Error("Failed to obtain data for feature:%s (%d)", featureName, feature);
    }
}

//=============================================================================
// MODO plugin initialize
//=============================================================================
void initialize()
{
    CLxGenericPolymorph* srv;

    srv = new CLxPolymorph<CmdPrintRenderCache>();
    srv->AddInterface(new CLxIfc_Command<CmdPrintRenderCache>());
    srv->AddInterface(new CLxIfc_Attributes<CmdPrintRenderCache>);
    lx::AddServer("sdk.rcache.print", srv);

    srv = new CLxPolymorph<CmdSaveRenderCache>();
    srv->AddInterface(new CLxIfc_Command<CmdSaveRenderCache>());
    srv->AddInterface(new CLxIfc_Attributes<CmdSaveRenderCache>);
    lx::AddServer("sdk.rcache.save", srv);

    srv = new CLxPolymorph<CmdRenderCacheListen>();
    srv->AddInterface(new CLxIfc_Command<CmdRenderCacheListen>());
    srv->AddInterface(new CLxIfc_Attributes<CmdRenderCacheListen>);
    lx::AddServer("sdk.rcache.listen", srv);

    pF = new CFactories();
}

//=============================================================================
// MODO plugin cleanup
//=============================================================================
void cleanup()
{
    delete pF;

    //	RenderCacheMap::GetInstance ()->Clear();
    MasterLog::GetInstance()->Clear();
}
