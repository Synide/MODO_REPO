/*
 * Plug-in SDK Source: Deformation Wrappers
 *
 * Copyright 0000
 *
 * Implements wrapper classes for deformation types.
 */
#include <lx_deform.hpp>
#include <lx_listener.hpp>
#include <lxu_deform.hpp>
#include <lxu_simd.hpp>
#include <vector>

/*
 * ------------------------------------------------------------
 * Mesh Influence Wrapper
 */

/*
 * The mesh influence object wraps the element provided by the client. This is
 * the actual exported object's implementation.
 */
class CLxPriv_MeshInfluence : public CLxImpl_Deformer, public CLxImpl_MeshInfluence, public CLxImpl_MeshListener
{
public:
    CLxMeshInfluence* elt;
    ILxUnknownID      self;

    typedef std::vector<LXtPointID> PointList;

    CLxUser_Mesh pnt_mesh;
    PointList    pnt_list;
    bool         all_points, map_set;

    CLxPriv_MeshInfluence()
    {
        all_points = false;
        map_set    = false;
    }
    ~CLxPriv_MeshInfluence();

    unsigned     dinf_Flags() override;
    LxResult     dinf_EnumeratePartition(ILxUnknownID, unsigned) override;
    LXtDeformElt dinf_Element(unsigned*) override;

    LxResult dinf_SetPartition(unsigned) override;
    LxResult dinf_WeightRun(unsigned, const LXtDeformElt* elt, const float** pos, const int* idx, float* weight, unsigned num) override;
    LxResult
    dinf_OffsetRun(unsigned, const LXtDeformElt* elt, const float** pos, const int* idx, const float* weight, float** offset, unsigned num) override;
    float dinf_Weight(LXtDeformElt elt, const LXtFVector pos, int idx) override;
    void  dinf_Offset(LXtDeformElt elt, float weight, const LXtFVector pos, int idx, LXtFVector offset) override;

    LxResult minf_SetTransform(unsigned, LXtMatrix4 xfrm) override;
    LxResult minf_SetMesh(unsigned, ILxUnknownID mesh, ILxUnknownID item) override;

    void ml_Destroy() override;
};

/*
 * The private state contains the implementation of the influence, as well
 * as the spawner for the exported object.
 */
class pv_MeshInfluence
{
public:
    CLxUser_Mesh    mesh;
    CLxUser_MeshMap map;
    CLxUser_Point   point;

    pv_MeshInfluence();

    CLxPolymorph<CLxPriv_MeshInfluence>* spawn;
};

pv_MeshInfluence::pv_MeshInfluence()
{
    CLxSpawnerCreate<CLxPriv_MeshInfluence> sp("CLxPriv_MeshInfluence");

    if (sp.created)
    {
        sp.AddInterface(new CLxIfc_Deformer<CLxPriv_MeshInfluence>);
        sp.AddInterface(new CLxIfc_MeshInfluence<CLxPriv_MeshInfluence>);
        sp.AddInterface(new CLxIfc_MeshListener<CLxPriv_MeshInfluence>);
    }

    spawn = sp.spawn;
}

CLxMeshInfluence::CLxMeshInfluence()
{
    pv = new pv_MeshInfluence;
}

CLxMeshInfluence::~CLxMeshInfluence()
{
    delete pv;
}

void CLxMeshInfluence::Spawn(void** ppvObj)
{
    CLxPriv_MeshInfluence* inst;

    inst       = pv->spawn->Alloc(ppvObj);
    inst->elt  = this;
    inst->self = (ILxUnknownID) ppvObj[0];
}

CLxPriv_MeshInfluence::~CLxPriv_MeshInfluence()
{
    if (pnt_mesh.test())
    {
        CLxUser_ListenerPort port(pnt_mesh);
        port.RemoveListener(self);
    }
    delete elt;
}

unsigned CLxPriv_MeshInfluence::dinf_Flags()
{
    return (elt->HasOffset() ? 0 : LXfDEFORMER_NO_OFFSET) | (elt->HasWeight() ? 0 : LXfDEFORMER_NO_WEIGHT);
}

LxResult CLxPriv_MeshInfluence::minf_SetMesh(unsigned /*shouldBeZero*/, ILxUnknownID mesh, ILxUnknownID item)
{
    pv_MeshInfluence* pv = elt->pv;

    if (!mesh)
    {
        pv->mesh.clear();
        pv->point.clear();
        pv->map.clear();
        return LXe_OK;
    }

    if (!elt->IsEnabled())
        return LXe_OK;

    pv->mesh.set(mesh);
    pv->point.fromMesh(pv->mesh);
    pv->map.fromMesh(pv->mesh);
    map_set = false;

    CLxUser_Item user(item);
    elt->SourceItem(user);

    return LXe_OK;
}

LxResult CLxPriv_MeshInfluence::minf_SetTransform(unsigned /*shouldBeZero*/, LXtMatrix4 xfrm)
{
    elt->WorldXfrm(xfrm);
    return LXe_OK;
}

/*
 * Visitor that just puts points into a list.
 */
class CListVisitor : public CLxImpl_AbstractVisitor
{
public:
    CLxPriv_MeshInfluence* pmi;

    LxResult Evaluate() override
    {
        pmi->pnt_list.push_back(pmi->elt->pv->point.ID());
        return LXe_OK;
    }
};

/*
 * Enumeration in the map case is much easier. Since map enumeration
 * will hit only the member points and will set the current point
 * in our point enumerator, we can pass the client's visitor directly.
 * We can also do that when the client wants to enumerate all points.
 *
 * In the case where the client has marked a subset of points, we
 * convert that to a list so that we don't have to do the marking each
 * time or picked the marked points out of the whole mesh. The list is
 * only valid as long as we're doing fast-path edits of the same mesh.
 */
LxResult CLxPriv_MeshInfluence::dinf_EnumeratePartition(ILxUnknownID visitor, unsigned /*partition*/)
{
    pv_MeshInfluence* pv = elt->pv;

    if (!elt->IsEnabled())
        return LXe_OK;

    if (elt->SelectMap(pv->mesh, pv->map))
    {
        if (!pv->map.ID())
            return LXe_OK;

        map_set = true;
        return pv->map.EnumerateContinuous(visitor, pv->point);
    }

    if (!all_points && (!pnt_mesh.test() || !pnt_mesh.IsSame(pv->mesh)))
    {
        CLxUser_ListenerPort port;
        CListVisitor         lvis;
        LXtMarkMode          mode;

        mode = elt->MarkMode(pv->mesh, pv->point);

        if (mode == LXiMARK_ANY)
            all_points = true;
        else
        {
            if (pnt_mesh.test())
            {
                port.set(pnt_mesh);
                port.RemoveListener(self);
            }
            pnt_mesh.set(pv->mesh);
            port.set(pnt_mesh);
            port.AddListener(self);

            pnt_list.clear();
            lvis.pmi = this;
            pv->point.Enum(&lvis, mode);
        }
    }

    if (all_points)
        return pv->point.Enumerate(LXiMARK_ANY, visitor, nullptr);

    CLxUser_Visitor vis(visitor);
    LxResult        rc;

    for (auto pi = pnt_list.begin(); pi != pnt_list.end(); pi++)
    {
        pv->point.Select(*pi);
        rc = vis.Evaluate();
        if (rc != LXe_OK)
            return rc;
    }

    return LXe_OK;
}

/*
 * We listen for destroy events on the mesh so we don't try to use an
 * object that's already gone.
 */
void CLxPriv_MeshInfluence::ml_Destroy()
{
    pnt_mesh.clear();
}

LxResult CLxPriv_MeshInfluence::dinf_SetPartition(unsigned /*part*/)
{
    if (!elt->IsEnabled())
        return LXe_INVALIDARG;

    if (!map_set)
    {
        elt->SelectMap(elt->pv->mesh, elt->pv->map);
        map_set = true;
    }

    return LXe_OK;
}

LXtDeformElt CLxPriv_MeshInfluence::dinf_Element(unsigned* segment)
{
    segment[0] = 0;
    return (LXtDeformElt) elt->pv->point.ID();
}

LxResult CLxPriv_MeshInfluence::dinf_WeightRun(unsigned /*segment*/,
                                               const LXtDeformElt* pntArray,
                                               const float** /*pos*/,
                                               const int* /*idx*/,
                                               float*   weight,
                                               unsigned num)
{
    CLxUser_Point point;
    unsigned      i;

    point.fromMesh(elt->pv->mesh);
    for (i = 0; i < num; i++)
    {
        point.Select((LXtPointID) pntArray[i]);
        weight[i] = elt->Weight(point);
    }
    return LXe_OK;
}

LxResult CLxPriv_MeshInfluence::dinf_OffsetRun(unsigned /*segment*/,
                                               const LXtDeformElt* pntArray,
                                               const float**       pos,
                                               const int* /*idx*/,
                                               const float* weight,
                                               float**      offset,
                                               unsigned     num)
{
    CLxUser_Point point;
    LXtFVector    tPos, tOff;
    unsigned      i;

    point.fromMesh(elt->pv->mesh);
    if (weight)
    {
        for (i = 0; i < num; i++)
        {
            point.Select((LXtPointID) pntArray[i]);

            lxsimd::VarrayGet(pos, tPos, i);
            elt->Offset(point, weight[i], tOff);
            lxsimd::VarraySet(offset, tOff, i);
        }
    }
    else
    {
        for (i = 0; i < num; i++)
        {
            point.Select((LXtPointID) pntArray[i]);

            lxsimd::VarrayGet(pos, tPos, i);
            elt->Offset(point, 1.0, tOff);
            lxsimd::VarraySet(offset, tOff, i);
        }
    }
    return LXe_OK;
}

float CLxPriv_MeshInfluence::dinf_Weight(LXtDeformElt deformElt, const LXtFVector pos, int idx)
{
    const float* vf[3];
    int          idxArr[1];
    float        wt;

    idxArr[0] = idx;
    vf[0]     = &pos[0];
    vf[1]     = &pos[1];
    vf[2]     = &pos[2];
    dinf_WeightRun(0, &deformElt, vf, idxArr, &wt, 1);
    return wt;
}

void CLxPriv_MeshInfluence::dinf_Offset(LXtDeformElt deformElt, float weight, const LXtFVector pos, int idx, LXtFVector offset)
{
    const float* vp[3];
    float*       vo[3];
    int          idxArr[1];

    idxArr[0] = idx;
    vp[0]     = &pos[0];
    vp[1]     = &pos[1];
    vp[2]     = &pos[2];
    vo[0]     = &offset[0];
    vo[1]     = &offset[1];
    vo[2]     = &offset[2];
    dinf_OffsetRun(0, &deformElt, vp, idxArr, &weight, vo, 1);
}
