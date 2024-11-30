/*
 * SEASHELL.CPP  Plug-in Interactive Modeling Tool.
 *
 *	Copyright 0000
 */
#include <lx_plugin.hpp>

#include <lx_layer.hpp>
#include <lx_log.hpp>
#include <lx_mesh.hpp>
#include <lx_tool.hpp>
#include <lx_toolui.hpp>
#include <lx_value.hpp>
#include <lx_vector.hpp>
#include <lx_vmodel.hpp>
#include <lxu_attributes.hpp>
#include <string>

/*
 * Log block allows us to display structured data in the log. In this case it's
 * used to show feedback on the current seashell scale.
 */
class CSeashellLogBlock : public CLxImpl_LogInfoBlock
{
public:
    LxResult lb_Name(const char** name) override
    {
        name[0] = "mesh.seashell";
        return LXe_OK;
    }

    LxResult lb_FieldCount(unsigned int* count) override
    {
        count[0] = 1;
        return LXe_OK;
    }

    LxResult lb_FieldName(unsigned int /*index*/, const char** name) override
    {
        name[0] = "scale";
        return LXe_OK;
    }

    LxResult lb_FieldType(unsigned int /*index*/, const char** type) override
    {
        type[0] = LXsTYPE_PERCENT;
        return LXe_OK;
    }
};

/*
 * The Seashell tool. Basic tool and tool model methods are defined here. The
 * attributes interface is inherited from the utility class.
 */

/*
 * Vertices coordinate structure.
 */
typedef struct _vertex
{
    LXtVector co;
} Vertex;

typedef struct _face
{
    int           nvrt;
    const char *  matr, *part;
    unsigned long type;
    LXtPolygonID  pol;
} Face;

/*
 * Evaluation. This is done with a polygon visitor which holds the current
 * state of the action.
 */
class CSeashellPolygonVisitor : public CLxImpl_AbstractVisitor
{
public:
    LxResult Evaluate() override;

    CLxUser_Mesh      e_mesh;
    CLxUser_Polygon   e_poly;
    CLxUser_Point     e_vert;
    CLxUser_MeshMap   e_mmap;
    CLxUser_StringTag e_ptag;

    /*  SeaShell Working Area  */
    int         numPnts; /*  number of points  */
    int         numPols; /*  number of polygons  */
    LXtPointID* points0; /*  front polygons list  */
    LXtPointID* points1; /*  back polygons list  */
    Face*       faces;   /*  face info  */
    Vertex*     verts;   /*  vertex list  */
    int         m_vrot, m_uvs;
};

class CSeashellTool : public CLxImpl_Tool, public CLxImpl_ToolModel, public CLxDynamicAttributes
{
public:
    CSeashellTool();

    void        tool_Reset() override;
    LXtObjectID tool_VectorType() override;
    const char* tool_Order() override;
    LXtID4      tool_Task() override;
    void        tool_Evaluate(ILxUnknownID vts) override;

    unsigned    tmod_Flags() override;
    void        tmod_Initialize(ILxUnknownID vts, ILxUnknownID adjust, unsigned flags) override;
    const char* tmod_Haul(unsigned index) override;
    LxResult    tmod_Enable(ILxUnknownID obj) override;

    using CLxDynamicAttributes::atrui_UIHints;  // to distinguish from the overloaded version in CLxImpl_AttributesUI

    void atrui_UIHints2(unsigned int index, CLxUser_UIHints& hints) override;
    bool atrui_Enabled(unsigned int index, CLxUser_Message& msg) override;

    void Build(CSeashellPolygonVisitor* vis);
    void TransPoint(int axis, double rot, double scal, double cen, LXtVector sco, LXtVector dco);
    bool TestPolygon();

    CLxUser_LogService   s_log;
    CLxUser_LayerService s_layer;
    CLxUser_VectorType   v_type;

    unsigned offset_view;
    unsigned mode_select;
};

#define ATTRs_AXIS "axis"
#define ATTRs_NREP "nrep"
#define ATTRs_NSID "sides"
#define ATTRs_OFF  "offset"
#define ATTRs_SCL  "scale"
#define ATTRs_TXUV "uvs"
#define ATTRs_UWRP "uwrap"
#define ATTRs_VWRP "vwrap"
#define ATTRs_VROT "vrot"

#define ATTRa_AXIS  0
#define ATTRa_NREP  1
#define ATTRa_NSID  2
#define ATTRa_OFF   3
#define ATTRa_SCL   4
#define ATTRa_TXUV  5
#define ATTRa_UWRP  6
#define ATTRa_VWRP  7
#define ATTRa_VROT  8
#define ATTRa_TOTAL 9

#define DEF_AXIS 1
#define DEF_NREP 4
#define DEF_NSID 20
#define DEF_OFF  1
#define DEF_TXUV 1
#define DEF_UWRP 0.2
#define DEF_VWRP 1.0
#define DEF_SCL  0.6
#define DEF_VROT 0

#ifndef DEG2RAD
#define DEG2RAD 0.01745329252222
#endif

/*
 * On create we add our one tool attribute. We also allocate a vector type
 * and select mode mask.
 */
CSeashellTool::CSeashellTool()
{
    CLxUser_PacketService sPkt;
    CLxUser_MeshService   sMesh;

    dyna_Add(ATTRs_AXIS, LXsTYPE_AXIS);
    dyna_Add(ATTRs_NREP, LXsTYPE_INTEGER);
    dyna_Add(ATTRs_NSID, LXsTYPE_INTEGER);
    dyna_Add(ATTRs_OFF, LXsTYPE_INTEGER);
    dyna_Add(ATTRs_SCL, LXsTYPE_PERCENT);
    dyna_Add(ATTRs_TXUV, LXsTYPE_BOOLEAN);
    dyna_Add(ATTRs_UWRP, LXsTYPE_FLOAT);
    dyna_Add(ATTRs_VWRP, LXsTYPE_FLOAT);
    dyna_Add(ATTRs_VROT, LXsTYPE_BOOLEAN);

    dyna_Value(ATTRa_AXIS).SetInt(DEF_AXIS);
    dyna_Value(ATTRa_NREP).SetInt(DEF_NREP);
    dyna_Value(ATTRa_NSID).SetInt(DEF_NSID);
    dyna_Value(ATTRa_OFF).SetFlt(DEF_OFF);
    dyna_Value(ATTRa_SCL).SetFlt(DEF_SCL);
    dyna_Value(ATTRa_TXUV).SetInt(DEF_TXUV);
    dyna_Value(ATTRa_UWRP).SetFlt(DEF_UWRP);
    dyna_Value(ATTRa_VWRP).SetFlt(DEF_VWRP);
    dyna_Value(ATTRa_VROT).SetInt(DEF_VROT);

    sPkt.NewVectorType(LXsCATEGORY_TOOL, v_type);
    sPkt.AddPacket(v_type, LXsP_TOOL_VIEW_EVENT, LXfVT_GET);

    offset_view = sPkt.GetOffset(LXsCATEGORY_TOOL, LXsP_TOOL_VIEW_EVENT);
    mode_select = sMesh.SetMode("select");
}

/*
 * Reset sets the attributes back to defaults.
 */
void CSeashellTool::tool_Reset()
{
    dyna_Value(ATTRa_AXIS).SetInt(DEF_AXIS);
    dyna_Value(ATTRa_NREP).SetInt(DEF_NREP);
    dyna_Value(ATTRa_NSID).SetInt(DEF_NSID);
    dyna_Value(ATTRa_OFF).SetFlt(DEF_OFF);
    dyna_Value(ATTRa_SCL).SetFlt(DEF_SCL);
    dyna_Value(ATTRa_TXUV).SetInt(DEF_TXUV);
    dyna_Value(ATTRa_UWRP).SetFlt(DEF_UWRP);
    dyna_Value(ATTRa_VWRP).SetFlt(DEF_VWRP);
    dyna_Value(ATTRa_VROT).SetInt(DEF_VROT);
}

/*
 * Boilerplate methods that identify this as an action (state altering) tool.
 */
LXtObjectID CSeashellTool::tool_VectorType()
{
    return v_type.m_loc;  // peek method; does not add-ref
}

const char* CSeashellTool::tool_Order()
{
    return LXs_ORD_ACTR;
}

LXtID4 CSeashellTool::tool_Task()
{
    return LXi_TASK_ACTR;
}

/*
 * We employ the simplest possible tool model -- default hauling. We indicate
 * that we want to haul one attribute, we name the attribute, and we implement
 * Initialize() which is what to do when the tool activates or re-activates.
 * In this case set the axis to the current value.
 */
unsigned CSeashellTool::tmod_Flags()
{
    return LXfTMOD_I0_ATTRHAUL;
}

void CSeashellTool::tmod_Initialize(ILxUnknownID /*vts*/, ILxUnknownID adjust, unsigned int /*flags*/)
{
    CLxUser_AdjustTool at(adjust);
    int                axis;

    dyna_Value(ATTRa_AXIS).GetInt(&axis);
    at.SetInt(ATTRa_AXIS, axis);
}

const char* CSeashellTool::tmod_Haul(unsigned index)
{
    if (index == 0)
        return ATTRs_SCL;
    else
        return nullptr;
}

LxResult CSeashellTool::tmod_Enable(ILxUnknownID obj)
{
    CLxUser_Message msg(obj);

    if (TestPolygon() == false)
    {
        msg.SetCode(LXe_CMD_DISABLED);
        msg.SetMessage("mesh.seashell", "NoPolygon", 0);
        return LXe_DISABLED;
    }
    return LXe_OK;
}

void CSeashellTool::atrui_UIHints2(unsigned int index, CLxUser_UIHints& hints)
{
    switch (index)
    {
        case ATTRa_NREP:
        case ATTRa_NSID:
        case ATTRa_OFF:
            hints.MinInt(1);
            break;
    }
}

bool CSeashellTool::atrui_Enabled(unsigned int index, CLxUser_Message& msg)
{
    int uvs;

    switch (index)
    {
        case ATTRa_UWRP:
        case ATTRa_VWRP:
        case ATTRa_VROT:
            dyna_Value(ATTRa_TXUV).GetInt(&uvs);
            if (!uvs)
            {
                msg.SetMessage("mesh.seashell", "NeedMakeUVs", 0);
                return false;
            }
            break;
    }
    return true;
}

bool CSeashellTool::TestPolygon()
{
    /*
     * Start the scan in read-only mode.
     */
    CLxUser_LayerScan scan;
    CLxUser_Mesh      mesh;
    unsigned          i, n, count;
    bool              ok = false;

    s_layer.BeginScan(LXf_LAYERSCAN_ACTIVE | LXf_LAYERSCAN_MARKPOLYS, scan);

    /*
     * Count the polygons in all mesh layers.
     */
    if (scan)
    {
        n = scan.NumLayers();
        for (i = 0; i < n; i++)
        {
            scan.BaseMeshByIndex(i, mesh);
            mesh.PolygonCount(&count);
            if (count > 0)
            {
                ok = true;
                break;
            }
        }
        scan.Apply();
    }

    /*
     * Return false if there is no polygons in any active layers.
     */
    return ok;
}

/*
 * We count the maximum number of points and polygons at the first pass.
 * Then store the vertex positions, polygon types and polygon tags to the
 * allocated buffer.
 */
LxResult CSeashellPolygonVisitor::Evaluate()
{
    unsigned   i, n, idx{};
    LXtID4     type;
    LXtPointID vrt;
    LXtFVector pos;

    if (!faces)
    {
        e_poly.VertexCount(&n);
        numPnts += n + 1;
        numPols++;
        return LXe_OK;
    }

    e_poly.VertexCount(&n);

    for (i = 0; i < n; i++)
    {
        idx = (i + m_vrot) % n;
        e_poly.VertexByIndex(idx, &vrt);
        e_vert.Select(vrt);
        e_vert.Pos(pos);
        points0[numPnts] = vrt;
        LXx_VCPY(verts[numPnts].co, pos);
        numPnts++;
    }

    if (m_uvs)
    {
        e_poly.VertexByIndex(idx, &vrt);
        e_vert.Select(vrt);
        e_vert.Pos(pos);
        points0[numPnts] = vrt;
        LXx_VCPY(verts[numPnts].co, pos);
    }

    e_poly.Type(&type);

    faces[numPols].nvrt = n;
    faces[numPols].matr = nullptr;
    faces[numPols].part = nullptr;
    faces[numPols].type = type;
    faces[numPols].pol  = e_poly.ID();
    e_ptag.set(e_poly);
    e_ptag.Get(LXi_PTAG_MATR, &faces[numPols].matr);
    e_ptag.Get(LXi_PTAG_PART, &faces[numPols].part);
    numPols++;
    return LXe_OK;
}

/*
 * Tool evaluation uses layer scan interface to walk through all the active
 * meshes and visit all the selected polygons.
 */
void CSeashellTool::tool_Evaluate(ILxUnknownID vts)
{
    CLxUser_VectorStack vec(vts);
    LXpToolViewEvent*   view;

    view = (LXpToolViewEvent*) vec.Read(offset_view);
    if (!view || view->type != LXi_VIEWTYPE_3D)
        return;

    /*
     * Start the scan in edit-poly mode.
     */
    CLxUser_LayerScan       scan;
    CSeashellPolygonVisitor vis;

    s_layer.BeginScan(LXf_LAYERSCAN_EDIT_POLYS, scan);

    /*
     * Enumerate all selected polygons in all mesh layers.
     */
    unsigned i, n;

    dyna_Value(ATTRa_TXUV).GetInt(&vis.m_uvs);
    dyna_Value(ATTRa_VROT).GetInt(&vis.m_vrot);

    n = scan.NumLayers();
    for (i = 0; i < n; i++)
    {
        scan.EditMeshByIndex(i, vis.e_mesh);
        vis.e_vert.fromMeshObj(vis.e_mesh);
        vis.e_poly.fromMeshObj(vis.e_mesh);
        vis.e_mmap.fromMeshObj(vis.e_mesh);

        /*
         * At the first pass,
         * count the number of points and polygons to store the profile shape.
         */
        vis.faces   = nullptr;
        vis.verts   = nullptr;
        vis.numPnts = 0;
        vis.numPols = 0;
        vis.e_poly.Enum(&vis, mode_select);
        if (!vis.numPols || !vis.numPnts)
            continue;
        /*
         * At the 2nd pass, store the shape in the foreground mesh layer as the
         * profile.
         */
        vis.faces   = new Face[vis.numPols];
        vis.verts   = new Vertex[vis.numPnts];
        vis.points0 = new LXtPointID[vis.numPnts * 2];
        vis.points1 = vis.points0 + vis.numPnts;
        vis.numPnts = 0;
        vis.numPols = 0;
        vis.e_poly.Enum(&vis, mode_select);

        /*
         * Build the seashell geometry based on the profile shape.
         */
        Build(&vis);

        if (vis.numPnts)
            scan.SetMeshChange(i, LXf_MESHEDIT_GEOMETRY);

        delete[] vis.points0;
        delete[] vis.verts;
        delete[] vis.faces;
    }

    scan.Apply();
}

void CSeashellTool::Build(CSeashellPolygonVisitor* vis)
{
    int    n, i, j, k, l, sum;
    int    axis, nrep, nsid, uvs;
    double off, uwrp, vwrp;
    double scl, rot, cen, sc, rt;

    dyna_Value(ATTRa_AXIS).GetInt(&axis);
    dyna_Value(ATTRa_NREP).GetInt(&nrep);
    dyna_Value(ATTRa_NSID).GetInt(&nsid);
    dyna_Value(ATTRa_OFF).GetFlt(&off);
    dyna_Value(ATTRa_SCL).GetFlt(&scl);
    dyna_Value(ATTRa_TXUV).GetInt(&uvs);
    dyna_Value(ATTRa_UWRP).GetFlt(&uwrp);
    dyna_Value(ATTRa_VWRP).GetFlt(&vwrp);

    scl = (scl < 1.0e-6) ? 1.0e-6 : scl;
    n   = nsid * nrep;
    rot = DEG2RAD * 360.0 / nsid;
    cen = (double) off / scl;
    scl = pow(scl, 1.0 / nsid);
    sc  = 1.0;
    rt  = 0.0;

    LXtPointID * front_p, *back_p, *temp_p, vrt, points[4];
    LXtPolygonID pol;
    LXtMeshMapID map{};
    Face*        face;
    float        uv[2];
    LXtVector    co;

    /*
     * Create a new texture uv map.
     */
    if (uvs)
        vis->e_mmap.New(LXi_VMAP_TEXTUREUV, "Texture", &map);

    front_p = vis->points0;
    back_p  = vis->points1;

    for (i = 0; i < n; i++)
    {
        sc *= scl;
        rt += rot;
        for (j = sum = 0; j < vis->numPols; j++)
        {
            face = &vis->faces[j];
            /*
             * Transform the points on the profile and generate the new vertices.
             */
            for (k = 0; k < face->nvrt; k++)
            {
                TransPoint(axis, rt, sc, cen, vis->verts[sum + k].co, co);
                vis->e_vert.New(co, &vrt);
                back_p[sum + k] = vrt;
            }
            back_p[sum + face->nvrt] = back_p[sum];

            for (k = 0; k < face->nvrt; k++)
            {
                l = (k + 1) % face->nvrt;
                /*
                 * Generate the side quadrangles.
                 */
                points[0] = front_p[sum + l];
                points[1] = front_p[sum + k];
                points[2] = back_p[sum + k];
                points[3] = back_p[sum + l];
                vis->e_poly.New(face->type, points, 4, 0, &pol);
                vis->e_poly.Select(pol);
                /*
                 * Set the material and part from the source polygon to
                 * the new quadrangle polygon.
                 */
                if (face->matr)
                    vis->e_ptag.Set(LXi_PTAG_MATR, face->matr);
                if (face->part)
                    vis->e_ptag.Set(LXi_PTAG_PART, face->part);
                /*
                 * Assign the UV values.
                 */
                if (uvs)
                {
                    uv[0] = (float) i * (float) uwrp;
                    uv[1] = 1.0f - (float) k / face->nvrt * (float) vwrp;
                    vis->e_poly.SetMapValue(front_p[sum + k], map, uv);
                    uv[0] = (float) i * (float) uwrp;
                    uv[1] = 1.0f - (float) (k + 1) / face->nvrt * (float) vwrp;
                    vis->e_poly.SetMapValue(front_p[sum + l], map, uv);
                    uv[0] = (float) (i + 1) * (float) uwrp;
                    uv[1] = 1.0f - (float) k / face->nvrt * (float) vwrp;
                    vis->e_poly.SetMapValue(back_p[sum + k], map, uv);
                    uv[0] = (float) (i + 1) * (float) uwrp;
                    uv[1] = 1.0f - (float) (k + 1) / face->nvrt * (float) vwrp;
                    vis->e_poly.SetMapValue(back_p[sum + l], map, uv);
                }
            }
            sum += face->nvrt;
        }
        temp_p  = front_p;
        front_p = back_p;
        back_p  = temp_p;
    }

    /*
     * Make the cap polygon at the top.
     */
    for (i = sum = 0; i < vis->numPols; i++)
    {
        face = &vis->faces[i];
        for (j = 0; j < face->nvrt; j++)
            back_p[sum + j] = front_p[sum + face->nvrt - j - 1];
        vis->e_poly.New(face->type, back_p + sum, face->nvrt, 0, &pol);
        vis->e_poly.Select(pol);
        if (face->matr)
            vis->e_ptag.Set(LXi_PTAG_MATR, face->matr);
        if (face->part)
            vis->e_ptag.Set(LXi_PTAG_PART, face->part);
        sum += face->nvrt;
    }
}

/*
 * Point translation function.
 */
void CSeashellTool::TransPoint(int axis, double rot, double scal, double cen, LXtVector sco, LXtVector dco)
{
    if (axis == 0)
    {
        dco[1] = (sco[1] * scal * cos(rot) - sco[2] * scal * sin(rot));
        dco[0] = (sco[0] - cen) * scal + cen;
        dco[2] = sco[1] * scal * sin(rot) + sco[2] * scal * cos(rot);
    }
    else if (axis == 1)
    {
        dco[0] = sco[0] * scal * cos(rot) - sco[2] * scal * sin(rot);
        dco[1] = (sco[1] - cen) * scal + cen;
        dco[2] = (sco[0] * scal * sin(rot) + sco[2] * scal * cos(rot));
    }
    else if (axis == 2)
    {
        dco[0] = (sco[0] * scal * cos(rot) - sco[1] * scal * sin(rot));
        dco[2] = (sco[2] - cen) * scal + cen;
        dco[1] = sco[0] * scal * sin(rot) + sco[1] * scal * cos(rot);
    }
}

/*
 * Export tool server and its log info block.
 */
void initialize()
{
    CLxGenericPolymorph* srv;

    srv = new CLxPolymorph<CSeashellTool>;
    srv->AddInterface(new CLxIfc_Tool<CSeashellTool>);
    srv->AddInterface(new CLxIfc_ToolModel<CSeashellTool>);
    srv->AddInterface(new CLxIfc_Attributes<CSeashellTool>);
    srv->AddInterface(new CLxIfc_AttributesUI<CSeashellTool>);
    thisModule.AddServer("mesh.seashell", srv);

    srv = new CLxPolymorph<CSeashellLogBlock>;
    srv->AddInterface(new CLxIfc_LogInfoBlock<CSeashellLogBlock>);
    thisModule.AddServer("mesh.seashell", srv);
}
