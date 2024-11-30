/*
 * FMTHPGL.CPP	Plug-in saver for HPGL text files
 *
 * Copyright 0000
 *
 * HPGL is a simple plotter control language, emulated here to output only the
 * visible layers as plotter commands.
 */

#include <lx_log.hpp>
#include <lx_server.hpp>
#include <lxidef.h>
#include <lxu_queries.hpp>
#include <lxu_scene.hpp>
#include <map>

/*
 * ----------------------------------------------------------------
 * HPGL Saver
 */

/*
 * The HPGL format derives from a default line format with no delimiters.
 * We keep track of the pen state and perform scaling from meters to plotter
 * units.
 */
class CHPGLFormat : public CLxLineFormat
{
public:
    virtual const char* lf_Separator()
    {
        return "";
    }

    int  Coord(float);
    void outInit();
    void outPen(int);
    void outPoint(float, float);
    void outBreak();
    void outDone();

    bool pen_down;
    int  cur_pen;
    int  next_pen;
};

int CHPGLFormat::Coord(float m)
{
    m /= 0.000025f;  // 25 microns per unit
    if (m > 0)
        return static_cast<int>(m + 0.5);
    else
        return static_cast<int>(m - 0.5);
}

void CHPGLFormat::outInit()
{
    lf_Output(";IN;PA;");
    lf_Break();
    lf_Output("PU;");
    lf_Break();

    pen_down = false;
    cur_pen  = 0;
    next_pen = 1;
}

void CHPGLFormat::outPen(int pen)
{
    next_pen = pen;
}

void CHPGLFormat::outPoint(float x, float y)
{
    char buf[32];
    int  ix, iy;

    ix = Coord(x);
    iy = Coord(y);

    if (!pen_down)
    {
        if (cur_pen != next_pen)
        {
            sprintf(buf, "SP%d;", next_pen);
            lf_Output(buf);
            lf_Break();
            cur_pen = next_pen;
        }

        sprintf(buf, "PA%d,%d;", ix, iy);
        lf_Output(buf);
        lf_Break();
        lf_Output("PD");
        pen_down = true;
    }
    else
        lf_Output(",");

    sprintf(buf, "%d,%d", ix, iy);
    lf_Output(buf);
}

void CHPGLFormat::outBreak()
{
    if (!pen_down)
        return;

    lf_Output(";");
    lf_Break();
    lf_Output("PU;");
    lf_Break();
    pen_down = false;
}

void CHPGLFormat::outDone()
{
    outBreak();
    lf_Output("SP0;");
    lf_Break();
}

/*
 * A polygon edge consists of two point IDs. To rank them we first sort the IDs
 * within each edge and then compare the similar ones.
 */
class CEdge
{
public:
    LXtPointID v[2];

    bool operator<(const CEdge& x) const
    {
        int ti, xi;

        ti = (v[0] < v[1]);
        xi = (x.v[0] < x.v[1]);
        return (v[ti] < x.v[xi] || (v[ti] == x.v[xi] && v[!ti] < x.v[!xi]));
    }
};

/*
 * Our HPGL saver is a subclass of the CLxSceneSaver utility.
 */
class CHPGLSaver : public CLxSceneSaver, public CHPGLFormat
{
public:
    CLxFileFormat* ss_Format() override
    {
        return this;
    }

    LxResult ss_Save() override;
    void     ss_Polygon() override;

    void GetOptions();
    void PlotPoint(LXtPointID);

    int    opt_proj;
    double opt_scale;

    int                  idx_x, idx_y;
    float                max_x, min_y;
    std::map<CEdge, int> edge_map;

    static LXtTagInfoDesc descInfo[];
};

#define SAVER_NAME "HPGL_PLT"
#define LOG_NAME   "io-status"

// This can be defined to enable license-checking
// #define LICENSE		"test 1234"

LXtTagInfoDesc CHPGLSaver::descInfo[] = { { LXsSAV_OUTCLASS, LXa_SCENE },
                                          { LXsSAV_DOSTYPE, "plt" },
                                          { LXsSRV_USERNAME, "HPGL Plotter File" },
                                          { LXsSRV_LOGSUBSYSTEM, LOG_NAME },
#ifdef LICENSE
                                          { LXsSRV_LICENSE, LICENSE },
#endif
                                          { nullptr } };

void CHPGLSaver::GetOptions()
{
    CLxReadUserValue ruv;

    if (ruv.Query("hpgl.projection"))
        opt_proj = ruv.GetInt();
    else
        opt_proj = 3;

    if (ruv.Query("hpgl.scale"))
        opt_scale = ruv.GetFloat();
    else
        opt_scale = 1.0;
}

LxResult CHPGLSaver::ss_Save()
{
    CLxUser_Log log(LOG_NAME);
    bool        first;
    LXtBBox     box, total{};
    int         axis;

    GetOptions();

    StartScan();
    first = 1;
    LXx_VSET(total.min, 0);
    LXx_VSET(total.max, 0);

    while (NextMesh())
        if (ChanInt(LXsICHAN_UISTATE_VISIBLE) != 2)
        {
            MeshBounds(box);
            if (first)
            {
                total = box;
                first = 0;
            }
            else
            {
                LXx_V3MIN(total.min, box.min);
                LXx_V3MAX(total.max, box.max);
            }
        }

    if (opt_proj == 3)
    {
        LXx_VSUB3(total.extent, total.max, total.min);

        if (total.extent[0] < total.extent[1])
        {
            if (total.extent[0] < total.extent[2])
                axis = 0;
            else
                axis = 2;
        }
        else if (total.extent[1] < total.extent[2])
            axis = 1;
        else
            axis = 2;
    }
    else
    {
        axis = opt_proj;
    }

    if (axis == 0)
    {
        idx_x = 1;
        idx_y = 2;
    }
    else if (axis == 1)
    {
        idx_x = 0;
        idx_y = 2;
    }
    else if (axis == 2)
    {
        idx_x = 0;
        idx_y = 1;
    }
    max_x = static_cast<float>(total.max[idx_x]);
    min_y = static_cast<float>(total.min[idx_y]);

    if (ReallySaving() && log.test())
    {
        log.Info("Writing HPGL");
        log.Message(LXe_INFO, "axis %d, %f x %f", axis, total.extent[idx_x], total.extent[idx_y]);

#ifdef LICENSE
        CLxUser_HostService svc;
        CLxUser_Factory     fac;
        const char *        who, *ser;

        if (svc.Lookup(fac, LXa_SAVER, SAVER_NAME) && LXx_OK(fac.InfoTag(LXsSRV_OWNER, &who)) && LXx_OK(fac.InfoTag(LXsSRV_SERIAL, &ser)))
        {
            log.Message(LXe_INFO, "Registered to %s, serial %s", who, ser);
        }
        else
            log.Warn("Can't find my own factory!");
#endif
    }

    outInit();

    StartScan();
    while (NextMesh())
        if (ChanInt(LXsICHAN_UISTATE_VISIBLE) != 2)
            WritePolys();

    outDone();
    return LXe_OK;
}

/*
 * Plotting polygons we want to draw only the contour edges, not edges that
 * connect to holes.  Thus we count the number of times an edge occurs in
 * the polygon and only draw those that happen exactly once.
 */
void CHPGLSaver::ss_Polygon()
{
    CEdge      edge;
    LXtPointID last;
    unsigned   i, n;

    edge_map.clear();
    n = PolyNumVerts();

    for (i = 0; i < n; i++)
    {
        edge.v[0] = PolyVertex(i % n);
        edge.v[1] = PolyVertex((i + 1) % n);

        auto it = edge_map.find(edge);
        if (it == edge_map.end())
            edge_map[edge] = 1;
        else
            it->second += 1;
    }

    do
    {
        last = nullptr;

        for (i = 0; i < n; i++)
        {
            edge.v[0] = PolyVertex(i % n);
            edge.v[1] = PolyVertex((i + 1) % n);
            if (edge_map[edge] != 1)
                continue;

            if (!last)
            {
                PlotPoint(edge.v[0]);
                PlotPoint(edge.v[1]);
            }
            else if (edge.v[0] == last)
            {
                PlotPoint(edge.v[1]);
            }
            else
                continue;

            edge_map[edge] = 0;
            last           = edge.v[1];
        }

        outBreak();
    } while (last);
}

void CHPGLSaver::PlotPoint(LXtPointID pnt)
{
    float vec[3];

    PntSet(pnt);
    PntPosition(vec);
    outPoint(static_cast<float>((max_x - vec[idx_x]) * opt_scale), static_cast<float>((vec[idx_y] - min_y) * opt_scale));
}

/*
 * ----------------------------------------------------------------
 * Exporting Servers
 */
void initialize()
{
    LXx_ADD_SERVER(Saver, CHPGLSaver, SAVER_NAME);
}
