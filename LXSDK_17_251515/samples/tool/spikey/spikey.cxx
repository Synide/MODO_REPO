/*
 * SPIKEY.CPP	Plug-in Tool Type
 *
 *	Copyright 0000
 */

#include <lx_plugin.hpp>

#include <lx_layer.hpp>
#include <lx_log.hpp>
#include <lx_mesh.hpp>
#include <lx_tool.hpp>
#include <lx_toolui.hpp>
#include <lx_vector.hpp>
#include <lx_vmodel.hpp>
#include <lxu_attributes.hpp>
#include <string>
#include <vector>

/*
 * Log block allows us to display structured data in the log. In this case it's
 * used to show feedback on the current spikey factor.
 */
class CSpikeyLogBlock : public CLxImpl_LogInfoBlock
{
public:
    LxResult lb_Name(const char** name) override
    {
        name[0] = "test.spikey";
        return LXe_OK;
    }

    LxResult lb_FieldCount(unsigned int* count) override
    {
        count[0] = 1;
        return LXe_OK;
    }

    LxResult lb_FieldName(unsigned int /*index*/, const char** name) override
    {
        name[0] = "factor";
        return LXe_OK;
    }

    LxResult lb_FieldType(unsigned int /*index*/, const char** type) override
    {
        type[0] = LXsTYPE_PERCENT;
        return LXe_OK;
    }
};

/*
 * The Spikey tool. Basic tool and tool model methods are defined here. The
 * attributes interface is inherited from the utility class.
 */
class CSpikeyTool : public CLxImpl_Tool, public CLxImpl_ToolModel, public CLxDynamicAttributes
{
public:
    CSpikeyTool();

    void        tool_Reset() override;
    LXtObjectID tool_VectorType() override;
    const char* tool_Order() override;
    LXtID4      tool_Task() override;
    void        tool_Evaluate(ILxUnknownID vts) override;

    unsigned    tmod_Flags() override;
    void        tmod_Initialize(ILxUnknownID vts, ILxUnknownID adjust, unsigned flags) override;
    const char* tmod_Haul(unsigned index) override;

    CLxUser_LogService   s_log;
    CLxUser_LayerService s_layer;
    CLxUser_VectorType   v_type;
    unsigned             offset_falloff, offset_view;
    unsigned             mode_select;
};

#define ATTRs_FACTOR "factor"

/*
 * On create we add our one tool attribute. We also allocate a vector type
 * (which doesn't seem to need anything in it!), the falloff packet offset
 * and select mode mask.
 */
CSpikeyTool::CSpikeyTool()
{
    CLxUser_PacketService sPkt;
    CLxUser_MeshService   sMesh;

    dyna_Add(ATTRs_FACTOR, LXsTYPE_PERCENT);

    sPkt.NewVectorType(LXsCATEGORY_TOOL, v_type);
    sPkt.AddPacket(v_type, LXsP_TOOL_FALLOFF, LXfVT_GET);
    sPkt.AddPacket(v_type, LXsP_TOOL_VIEW_EVENT, LXfVT_GET);

    offset_falloff = sPkt.GetOffset(LXsCATEGORY_TOOL, LXsP_TOOL_FALLOFF);
    offset_view    = sPkt.GetOffset(LXsCATEGORY_TOOL, LXsP_TOOL_VIEW_EVENT);
    mode_select    = sMesh.SetMode("select");
}

/*
 * Reset sets the attributes back to defaults.
 */
void CSpikeyTool::tool_Reset()
{
    attr_SetFlt(0, 0.0);
}

/*
 * Boilerplate methods that identify this as an action (state altering) tool.
 */
LXtObjectID CSpikeyTool::tool_VectorType()
{
    return v_type.m_loc;  // peek method; does not add-ref
}

const char* CSpikeyTool::tool_Order()
{
    return LXs_ORD_ACTR;
}

LXtID4 CSpikeyTool::tool_Task()
{
    return LXi_TASK_ACTR;
}

/*
 * We employ the simplest possible tool model -- default hauling. We indicate
 * that we want to haul one attribute, we name the attribute, and we implement
 * Initialize() which is what to do when the tool activates or re-activates.
 * In this case set the factor back to zero.
 */
unsigned CSpikeyTool::tmod_Flags()
{
    return LXfTMOD_I0_ATTRHAUL;
}

void CSpikeyTool::tmod_Initialize(ILxUnknownID /*vts*/, ILxUnknownID adjust, unsigned int /*flags*/)
{
    CLxUser_AdjustTool at(adjust);

    at.SetFlt(0, 0.0);
}

const char* CSpikeyTool::tmod_Haul(unsigned index)
{
    if (index == 0)
        return ATTRs_FACTOR;
    else
        return nullptr;
}

/*
 * Map visitor just collects the maps in vectors based on type.
 */
class CSpikeMapListVisitor : public CLxVisitor
{
public:
    CLxUser_MeshMap           map;
    std::vector<LXtMeshMapID> morph;
    std::vector<LXtMeshMapID> spot;
    std::vector<LXtMeshMapID> other;
    LXtMeshMapID              opos;
    float *                   buf, *acc;
    unsigned                  len, max;

    CSpikeMapListVisitor()
    {
        len = 0;
    }

    ~CSpikeMapListVisitor()
    {
        FreeArrays();
    }

    void FreeArrays()
    {
        if (len)
        {
            delete[] buf;
            delete[] acc;
            len = 0;
        }
    }

    void fromMeshObj(CLxLoc_Mesh& mesh)
    {
        map.fromMeshObj(mesh);
    }

    void evaluate() override
    {
        LXtID4   type;
        unsigned dim;

        map.Type(&type);
        map.Dimension(&dim);
        if (dim == 0)
            return;

        if (dim > max)
            max = dim;

        if (type == LXi_VMAP_OBJECTPOS)
            opos = map.ID();

        else if (type == LXi_VMAP_MORPH)
            morph.push_back(map.ID());

        else if (type == LXi_VMAP_SPOT)
            spot.push_back(map.ID());

        else if (map.IsEdgeMap() != LXe_TRUE)
            other.push_back(map.ID());
    }

    void Collect()
    {
        morph.clear();
        spot.clear();
        other.clear();

        max = 0;
        map.Enumerate(0, *this, nullptr);

        if (max > len)
        {
            FreeArrays();
            buf = new float[max];
            acc = new float[max];
            len = max;
        }
    }
};

/*
 * Evaluation. This is done with a polygon visitor which holds the current
 * state of the action.
 */
class CSpikePolygonVisitor : public CLxVisitor
{
public:
    void evaluate() override;

    bool Normalize(LXtVector);
    void VertexPos(unsigned index, LXtFVector pos);
    bool VertexCross(unsigned i0, unsigned i1, unsigned i2, LXtVector dir);
    bool GoodNormal(LXtVector dir);
    bool GetSpike(LXtVector pos);

    LXtMeshMapID map_id;
    LXtID4       map_type;
    unsigned     vrt_count;
    double       pol_weight;

    CSpikeMapListVisitor  e_maps;
    CLxUser_Mesh          e_mesh;
    CLxUser_Polygon       e_poly, e_dest;
    CLxUser_Point         e_vert;
    CLxUser_FalloffPacket e_falloff;
    double                e_factor;
    bool                  edit_any;
};

/*
 * Get a vertex position. This gets the position of the given vertex of the
 * polygon relative to the current map. This allows us to evaluate the shape
 * of polygons in morphs.
 */
void CSpikePolygonVisitor::VertexPos(unsigned index, LXtFVector pos)
{
    e_vert.SelectPolygonVertex(e_poly.ID(), index);

    if (map_type == LXi_VMAP_OBJECTPOS)
        e_vert.Pos(pos);

    else if (map_type == LXi_VMAP_SPOT)
    {
        if (e_vert.MapValue(map_id, pos) != LXe_OK)
            e_vert.Pos(pos);
    }
    else
    {
        LXtFVector delta;

        e_vert.Pos(pos);
        e_vert.MapEvaluate(map_id, delta);
        LXx_VADD(pos, delta);
    }
}

/*
 * Normalize a vector, if possible.
 */
bool CSpikePolygonVisitor::Normalize(LXtVector v)
{
    double len;

    len = LXx_VLEN(v);
    if (len)
    {
        LXx_VSCL(v, 1.0 / len);
        return true;
    }
    else
    {
        LXx_VCLR(v);
        return false;
    }
}

/*
 * Get the normalized cross-product of edge vectors defined by the three
 * points of the polygon.
 */
bool CSpikePolygonVisitor::VertexCross(unsigned i0, unsigned i1, unsigned i2, LXtVector dir)
{
    LXtFVector p0, p1, p2;
    LXtFVector e0, e1;

    VertexPos(i0, p0);
    VertexPos(i1, p1);
    VertexPos(i2, p2);
    LXx_VSUB3(e0, p1, p0);
    LXx_VSUB3(e1, p2, p1);
    LXx_VCROSS(dir, e0, e1);
    return Normalize(dir);
}

/*
 * Compute a good normal (one that's symmetry safe, which the basic polygon
 * normal is not). This takes the cross product of the 0'th point, then adds
 * in the rest flipping as needed. Final result is renormalized.
 */
bool CSpikePolygonVisitor::GoodNormal(LXtVector dir)
{
    LXtVector base, norm;
    unsigned  i;

    if (!VertexCross(vrt_count - 1, 0, 1, base))
        return false;

    LXx_VCPY(dir, base);
    for (i = 1; i < vrt_count; i++)
        if (VertexCross(i - 1, i, (i + 1) % vrt_count, norm))
        {
            if (LXx_VDOT(base, norm) < 0.0)
            {
                LXx_VSUB(dir, norm);
            }
            else
            {
                LXx_VADD(dir, norm);
            }
        }

    return Normalize(dir);
}

/*
 * Compute the position of the spike for the current polygon in the current
 * morph map. We compute the average position and the perimeter and normal of
 * the polygon, and compute a position along the normal with an offset given by
 * average edge length modulated by weight. Returns false if it cannot be computed.
 */
bool CSpikePolygonVisitor::GetSpike(LXtVector pos)
{
    LXtVector  dir;
    LXtFVector p0, p1;
    double     perimeter;
    unsigned   i;

    LXx_VCLR(pos);
    perimeter = 0.0;

    VertexPos(vrt_count - 1, p0);

    for (i = 0; i < vrt_count; i++)
    {
        VertexPos(i, p1);

        LXx_VSUB3(dir, p0, p1);
        perimeter += LXx_VLEN(dir);

        LXx_VADD(pos, p1);
        LXx_VCPY(p0, p1);
    }

    if (perimeter <= 0.0)
        return false;

    if (!GoodNormal(dir))
        return false;

    LXx_VSCL(pos, 1.0 / vrt_count);
    LXx_VADDS(pos, dir, pol_weight * e_factor * perimeter / vrt_count);
    return true;
}

/*
 * Evaluation replaces the polygon with a fan of triangles. The central point is
 * given a spike position in all morphs, and other maps are interpolated.
 */
void CSpikePolygonVisitor::evaluate()
{
    LXtPointID   vrt, vl[3];
    LXtPolygonID pol;
    LXtFVector   fvec;
    LXtVector    tip, tip1;
    unsigned     i;

    e_poly.VertexCount(&vrt_count);
    pol = e_poly.ID();
    if (vrt_count < 3)
        return;

    /*
     * Compute average weight of all vertices, rejecting zero-weight polys.
     */
    pol_weight = 0.0;
    for (i = 0; i < vrt_count; i++)
    {
        e_poly.VertexByIndex(i, &vrt);
        e_vert.Pos(fvec);
        pol_weight += e_falloff.Evaluate(fvec, vrt, pol);
    }

    if (pol_weight <= 0.0)
        return;

    pol_weight /= vrt_count;

    /*
     * Create vertex using the basic spike position, if any.
     */
    map_id   = e_maps.opos;
    map_type = LXi_VMAP_OBJECTPOS;
    if (!GetSpike(tip))
        return;

    e_vert.New(tip, &vl[2]);

    /*
     * Compute morph positions for the spike tip. MORF maps are deltas from
     * the base position and can be unset if close to zero.
     */
    map_type = LXi_VMAP_MORPH;
    for (auto mit = e_maps.morph.begin(); mit < e_maps.morph.end(); mit++)
    {
        map_id = *mit;
        if (GetSpike(tip1))
        {
            LXx_VSUB3(fvec, tip1, tip);
            if (LXx_VLEN(fvec) > 1.0e-5)
            {
                e_vert.Select(vl[2]);
                e_vert.SetMapValue(map_id, fvec);
            }
        }
    }

    /*
     * Compute morph positions for the spike tip. SPOT maps are absolute
     * positions and can be unset if the same as the base position.
     */
    map_type = LXi_VMAP_SPOT;
    for (auto mit = e_maps.spot.begin(); mit < e_maps.spot.end(); mit++)
    {
        map_id = *mit;
        if (GetSpike(tip1))
        {
            LXx_VSUB3(fvec, tip1, tip);
            if (LXx_VLEN(fvec) > 1.0e-5)
            {
                LXx_VCPY(fvec, tip1);
                e_vert.Select(vl[2]);
                e_vert.SetMapValue(map_id, fvec);
            }
        }
    }

    /*
     * All other maps are set as averages of the vectors from the vertices.
     * This uses the allocated buffers because arbitrary vertex map types
     * can have any dimension.
     */
    for (auto mit = e_maps.other.begin(); mit < e_maps.other.end(); mit++)
    {
        unsigned k, dim;

        e_maps.map.Select(*mit);
        e_maps.map.Dimension(&dim);

        for (k = 0; k < dim; k++)
            e_maps.acc[k] = 0.0;

        for (i = 0; i < vrt_count; i++)
        {
            e_poly.VertexByIndex(i, &vrt);
            if (e_poly.MapEvaluate(*mit, vrt, e_maps.buf) != LXe_OK)
                break;

            for (k = 0; k < dim; k++)
                e_maps.acc[k] += e_maps.buf[k];
        }

        if (i < vrt_count)
            continue;

        for (k = 0; k < dim; k++)
            e_maps.acc[k] /= vrt_count;

        e_vert.Select(vl[2]);
        e_vert.SetMapValue(*mit, e_maps.acc);
    }

    /*
     * Finally replace the original polygon with a fan of triangles. We also
     * have to copy discontinuous vertex maps (like UV maps) from the original
     * polygon to the replacements.
     */
    e_poly.VertexByIndex(0, &vl[0]);
    for (i = 0; i < vrt_count; i++)
    {
        e_poly.VertexByIndex((i + 1) % vrt_count, &vl[1]);
        e_poly.NewProto(0, vl, 3, 0, &pol);

        for (auto mit = e_maps.other.begin(); mit < e_maps.other.end(); mit++)
        {
            unsigned k;

            e_maps.map.Select(*mit);
            if (e_maps.map.IsContinuous() == LXe_TRUE)
                continue;

            e_dest.Select(pol);
            for (k = 0; k < 2; k++)
                if (e_poly.MapEvaluate(*mit, vl[k], e_maps.buf) == LXe_OK)
                    e_dest.SetMapValue(vl[k], *mit, e_maps.buf);
        }

        vl[0] = vl[1];
    }

    e_poly.Remove();
    edit_any = true;
}

/*
 * Tool evaluation uses layer scan interface to walk through all the active
 * meshes and visit all the selected polygons.
 */
void CSpikeyTool::tool_Evaluate(ILxUnknownID vts)
{
    CLxUser_VectorStack vec(vts);
    LXpToolViewEvent*   view;

    view = static_cast<LXpToolViewEvent*>(vec.Read(offset_view));
    if (!view || view->type != LXi_VIEWTYPE_3D)
        return;

    /*
     * Display current spikey factor using our log block.
     */
    CLxUser_LogEntry entry;

    s_log.NewBlockEntry(LXe_INFO, "test.spikey", entry);
    entry.SetValue(nullptr, 0, dyna_Value(0));

    /*
     * Read the falloff and start the scan in edit-poly mode.
     */
    CLxUser_LayerScan    scan;
    CSpikePolygonVisitor vis;

    dyna_Value(0).GetFlt(&vis.e_factor);
    vec.ReadObject(offset_falloff, vis.e_falloff);

    s_layer.BeginScan(LXf_LAYERSCAN_EDIT_POLYS, scan);

    /*
     * Enumerate all selected polygons in all mesh layers. If a mesh is
     * edited we set the "geometry" change flag indicating that points
     * and polygons have both changed.
     */
    unsigned i, n;

    n = scan.NumLayers();
    for (i = 0; i < n; i++)
    {
        scan.EditMeshByIndex(i, vis.e_mesh);
        vis.e_vert.fromMeshObj(vis.e_mesh);
        vis.e_poly.fromMeshObj(vis.e_mesh);
        vis.e_dest.fromMeshObj(vis.e_mesh);
        vis.e_maps.fromMeshObj(vis.e_mesh);

        vis.e_maps.Collect();
        vis.edit_any = false;

        vis.e_poly.Enumerate(mode_select, vis, nullptr);

        if (vis.edit_any)
            scan.SetMeshChange(i, LXf_MESHEDIT_GEOMETRY);
    }

    scan.Apply();
}

/*
 * Export tool server and its log info block.
 */
void initialize()
{
    CLxGenericPolymorph* srv;

    srv = new CLxPolymorph<CSpikeyTool>;
    srv->AddInterface(new CLxIfc_Tool<CSpikeyTool>);
    srv->AddInterface(new CLxIfc_ToolModel<CSpikeyTool>);
    srv->AddInterface(new CLxIfc_Attributes<CSpikeyTool>);
    thisModule.AddServer("test.spikey", srv);

    srv = new CLxPolymorph<CSpikeyLogBlock>;
    srv->AddInterface(new CLxIfc_LogInfoBlock<CSpikeyLogBlock>);
    thisModule.AddServer("test.spikey", srv);
}
