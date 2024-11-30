/*
 * Command: vertex.componentValue
 *
 *  Copyright 0000
 *
 * This module implements the command:
 *
 *	vertex.componentValue component:integer ?value:* <type:string>
 *
 * This allows the reading and setting of a vertex map value. The map is given
 * by the current selection, filtered by the optional 'type' argument. The value
 * when queried comes from the given component of the mapped vector of selected
 * vertices. When set, it sets same. So if a UV map is selected, and 'component'
 * is 0, then the command sets the U component of the UV map value for selected
 * vertices.
 *
 * This command also illustrates a variable argument type, with the 'value'
 * argument changing types based on the map type.
 */
#include <cstdio>
#include <lx_mesh.hpp>
#include <lx_plugin.hpp>
#include <lx_select.hpp>
#include <lx_seltypes.hpp>
#include <lxu_command.hpp>

#include <lx_layer.hpp>

#include <string>

#include <lx_log.hpp>
#include <lx_persist.hpp>

/*
 * This command has a very silly example of persistent data.
 */
class CPersistData
{
public:
    CLxUser_PersistentEntry mainHash;
    CLxUser_PersistentEntry atom;
    CLxUser_PersistentEntry hash;
    CLxUser_PersistentEntry list;

    CLxUser_Attributes aVal;
    CLxUser_Attributes hVal;
    CLxUser_Attributes lVal;

    void GenIndex();
    void Peek();
    void Poke(int comp, double value, const char* name);
    char index_buf[4];
};

static CPersistData* pd;

/*
 * The structure of persistent data is set up using a vistor. This allows the
 * system to bracket the setup with its own state management. The structure
 * created is as follows:
 *
 *	root TestData
 *	  hash MainHash
 *	    atom FloatAtom %f
 *	    hash IntHash %d
 *	    list StringList %s
 */
class CPersistVisitor : public CLxImpl_AbstractVisitor
{
public:
    LxResult Evaluate() override;
};

LxResult CPersistVisitor::Evaluate()
{
    CLxUser_PersistenceService srv;

    srv.Start("MainHash", LXi_PERSIST_HASH);

    srv.Start("FloatAtom", LXi_PERSIST_ATOM);
    srv.AddValue(LXsTYPE_FLOAT);
    srv.EndDef(pd->atom);

    srv.Start("IntHash", LXi_PERSIST_HASH);
    srv.AddValue(LXsTYPE_INTEGER);
    srv.EndDef(pd->hash);

    srv.Start("StringList", LXi_PERSIST_LIST);
    srv.AddValue(LXsTYPE_STRING);
    srv.EndDef(pd->list);

    srv.EndDef(pd->mainHash);

    pd->aVal.set(pd->atom);
    pd->hVal.set(pd->hash);
    pd->lVal.set(pd->list);

    return LXe_OK;
}

void CPersistData::GenIndex()
{
    static int nn = 0;

    index_buf[0] = '0' + (nn++ % 4);
    index_buf[1] = 0;
}

void CPersistData::Peek()
{
    if (LXx_FAIL(mainHash.Lookup(index_buf)))
        return;

    CLxUser_LogService lsrv;
    double             val;
    int                comp;
    char               out[128];

    val = aVal.Float(0);

    hash.Lookup("comp");
    comp = hVal.Int(0);

    sprintf(out, "old[%s] = %f (%d)\n", index_buf, val, comp);
    lsrv.DebugLogOutput(LXi_DBLOG_NORMAL, out);

    mainHash.Delete();
}

void CPersistData::Poke(int comp, double value, const char* name)
{
    mainHash.Insert(index_buf);

    atom.Append();
    aVal.SetFlt(0, value);

    hash.Insert("comp");
    hVal.SetInt(0, comp);

    list.Append();
    lVal.SetString(0, name);

    list.Append();
    lVal.SetString(0, "so there");
}

/*
 * Setup happens once per session.
 */
static void Persist_Setup(void)
{
    if (pd)
        return;

    pd = new CPersistData;

    CLxUser_PersistenceService srv;
    CPersistVisitor            vis;

    srv.ConfigureVis("TestData", &vis);
}

/*
 * This command will operate over selected vertices, so we have a specialized
 * version of a visitor for processing them. StartMesh() is called when we enter
 * a new mesh (if multiple meshes are selected) and Vertex() is called for each
 * vertex. Vertex() can return true to halt the enumeration.
 */
class CVertexSelectionVisitor : public CLxImpl_AbstractVisitor
{
public:
    virtual void StartMesh(class CVertexCompCommand&)
    {
    }
    virtual bool Vertex(class CVertexCompCommand&) = 0;

    class CVertexCompCommand* m_cvc;
    void                      init(class CVertexCompCommand* cvc)
    {
        m_cvc = cvc;
    }

    LxResult Evaluate() override
    {
        if (Vertex(*m_cvc))
            return LXe_ABORT;
        else
            return LXe_OK;
    }
};

/*
 * Our command, derived from basic command.
 */
class CVertexCompCommand : public CLxBasicCommand
{
public:
    CVertexCompCommand();

    int         basic_CmdFlags() override;
    bool        basic_Notifier(int index, std::string& name, std::string& args) override;
    const char* basic_ArgType(unsigned int index) override;
    bool        basic_Enable(CLxUser_Message& msg) override;

    void     cmd_Execute(unsigned int flags) override;
    LxResult cmd_Query(unsigned int index, ILxUnknownID vaQuery) override;

    bool GetVMap();
    void Enumerate(CVertexSelectionVisitor&, bool edit = false);

    CLxUser_MeshService           srv_mesh;
    CLxUser_LayerService          srv_lay;
    CLxUser_SelectionService      srv_sel;
    CLxUser_VMapPacketTranslation pkt_vmap;
    LXtID4                        selID_vmap, selID_vert;
    LXtMarkMode                   select_mode;

    const char* cm_name;
    LXtID4      cm_type;
    unsigned    cm_dim;
    unsigned    cm_change;

    CLxUser_Mesh  cm_mesh;
    CLxUser_Point cm_point;
    LXtMeshMapID  cm_mapID;
};

/*
 * Command argument indices.
 */
#define ARGi_COMP  0
#define ARGi_VALUE 1
#define ARGi_TYPE  2

/*
 * Setting up our command requires first initializing the arguments. They are added
 * to the dynamic attributes and their flags are set. We also look up some selection
 * types and the mode for selected elements.
 */
CVertexCompCommand::CVertexCompCommand()
{
    CLxUser_SelectionType styp;

    Persist_Setup();

    dyna_Add("component", LXsTYPE_INTEGER);
    dyna_Add("value", LXsTYPE_FLOAT);
    dyna_Add("type", LXsTYPE_STRING);

    basic_SetFlags(ARGi_VALUE, LXfCMDARG_QUERY | LXfCMDARG_VARIABLE);
    basic_SetFlags(ARGi_TYPE, LXfCMDARG_OPTIONAL);

    selID_vmap = srv_sel.LookupType("vmap");
    srv_sel.GetImplementation(selID_vmap, styp);
    pkt_vmap.set(styp);

    selID_vert = srv_sel.LookupType("vertex");

    select_mode = srv_mesh.SetMode("select");
}

/*
 * Flags indicate what type of command this is. MODEL means that it affects the
 * data model of the scene, in this case the meshes, and UNDO means that it supports
 * undo.
 */
int CVertexCompCommand::basic_CmdFlags()
{
    return LXfCMD_MODEL | LXfCMD_UNDO;
}

/*
 * Notifiers are used to signal changes to a command's state to any client that
 * may be using it. For example a command in a form may be disabled. If something
 * changes in the system that changes the disable state, we need a notifier so
 * that the form will be triggered to update.
 *
 * This method on the basic command is called with sequentially higher index values
 * until it returns false. As long as it returns true it will add more notifiers.
 */
bool CVertexCompCommand::basic_Notifier(int index, std::string& name, std::string& args)
{
    if (index == 0)
    {
        name = "select.event";
        args = "vmap +vdt";  // VALUE+DISABLE+TYPE on vmap selection
    }
    else if (index == 1)
    {
        name = "select.event";
        args = "vertex exist+d";  // DISABLE on vertex selection existence
    }
    else if (index == 2)
    {
        name = "select.event";
        args = "vertex +v";  // VALUE on vertex selection change
    }
    else if (index == 3)
    {
        name = "meshes.event";
        args = "+ouma +v";  // VALUE on position(o), UV map(u), morph map(m), and other map(a) edits
    }
    else
        return false;

    return true;
}

/*
 * This method selects a map based on the state of the command. If it returns true
 * then 'cm_name' and 'cm_type' have been successfully set.
 */
bool CVertexCompCommand::GetVMap()
{
    void* pkt;

    /*
     * If the 'type' argument is unset, we just take the most recent vmap
     * selection and read it's name and type.
     */
    if (!dyna_IsSet(ARGi_TYPE))
    {
        pkt = srv_sel.Recent(selID_vmap);
        if (!pkt)
            return false;

        pkt_vmap.Name(pkt, &cm_name);
        pkt_vmap.Type(pkt, &cm_type);
        return true;
    }

    /*
     * If the type is set, we decode it and then walk the selection to find
     * a map that fits the request.
     */
    std::string typeStr;
    LXtID4      type;
    unsigned    i, n;

    attr_GetString(ARGi_TYPE, typeStr);
    if (LXx_FAIL(srv_mesh.VMapLookupType(typeStr.c_str(), &type)))
        return false;

    n = srv_sel.Count(selID_vmap);
    for (i = 0; i < n; i++)
    {
        pkt = srv_sel.ByIndex(selID_vmap, i);

        pkt_vmap.Type(pkt, &cm_type);
        if (cm_type != type)
            continue;

        pkt_vmap.Name(pkt, &cm_name);
        return true;
    }

    return false;
}

/*
 * This is a core utility function that enumerates selected vertices with our
 * custom visitor. This uses a layer scan object created by the layer service.
 * Since this obeys the normal rule that if no points are seelcted all are
 * selected, we test the selection explicitly so we do nothing when there is
 * no explicit selection.
 */
void CVertexCompCommand::Enumerate(CVertexSelectionVisitor& vsv, bool edit)
{
    CLxUser_LayerScan scan;
    unsigned          i, n;

    if (!srv_sel.Count(selID_vert))
        return;

    if (!GetVMap())
        return;

    srv_mesh.VMapDimension(cm_type, &cm_dim);
    if (cm_type == LXi_VMAP_OBJECTPOS)
        cm_change = LXf_MESHEDIT_POSITION;
    else if (cm_type == LXi_VMAP_TEXTUREUV)
        cm_change = LXf_MESHEDIT_MAP_UV;
    else if (cm_type == LXi_VMAP_MORPH || cm_type == LXi_VMAP_SPOT)
        cm_change = LXf_MESHEDIT_MAP_MORPH;
    else
        cm_change = LXf_MESHEDIT_MAP_OTHER;

    n = LXf_LAYERSCAN_ACTIVE | LXf_LAYERSCAN_MARKVERTS;
    if (edit)
        n |= LXf_LAYERSCAN_WRITEMESH;

    if (!srv_lay.BeginScan(n, scan))
        return;

    vsv.init(this);

    n = scan.NumLayers();
    for (i = 0; i < n; i++)
    {
        if (edit)
            scan.EditMeshByIndex(i, cm_mesh);
        else
            scan.BaseMeshByIndex(i, cm_mesh);

        CLxUser_MeshMap mmap(cm_mesh);
        mmap.SelectByName(cm_type, cm_name);
        cm_mapID = mmap.ID();

        vsv.StartMesh(*this);

        cm_point.fromMeshObj(cm_mesh);
        cm_point.Enum(&vsv, select_mode);

        // the POINTS flag shouldn't be needed (bug 22347)
        //
        if (edit)
            scan.SetMeshChange(i, LXf_MESHEDIT_POINTS | cm_change);
    }

    if (edit)
        scan.Apply();
}

/*
 * Enable visitor. Just note if there was anything to operate on by setting
 * the flag if Vertex() gets called. Returns true to abort immediately.
 */
class CEnableVisitor : public CVertexSelectionVisitor
{
public:
    bool Vertex(class CVertexCompCommand& /*cmd*/) override
    {
        any = true;
        return true;
    }

    bool any;
};

/*
 * We're diabled if there is nothing to operate on. Otherwise we want to be enabled
 * if the 'component' arg is unset (to open a full dialog). If set, it has to be
 * smaller than the map dimension.
 */
bool CVertexCompCommand::basic_Enable(CLxUser_Message& /*msg*/)
{
    CEnableVisitor vis;
    int            comp;

    vis.any = false;
    Enumerate(vis);

    if (!vis.any)
        return false;

    if (!dyna_IsSet(ARGi_COMP))
        return true;

    attr_GetInt(ARGi_COMP, &comp);
    return (comp >= 0 && comp < static_cast<int>(cm_dim));
}

/*
 * This method will be called to get the type of the variable argument type,
 * which in our case is the 'type' argument. 'index' will be ARGi_VALUE, so
 * we don't really have to test that. We pick a datatype appropriate for the
 * map type.
 */
const char* CVertexCompCommand::basic_ArgType(unsigned int /*index*/)
{
    if (!GetVMap())
        return LXsTYPE_FLOAT;

    if (cm_type == LXi_VMAP_TEXTUREUV)
        return LXsTYPE_UVCOORD;

    if (cm_type == LXi_VMAP_WEIGHT)
        return LXsTYPE_PERCENT;

    if (cm_type == LXi_VMAP_MORPH || cm_type == LXi_VMAP_SPOT)
        return LXsTYPE_DISTANCE;

    if (cm_type == LXi_VMAP_RGBA || cm_type == LXi_VMAP_RGB)
        return LXsTYPE_COLOR1;

    return LXsTYPE_FLOAT;
}

/*
 * Vector visitor. This is a subclass of the vertex visitor that maintains a vector
 * of the right size for the map.
 */
class CVectorVisitor : public CVertexSelectionVisitor
{
public:
    float* vec;

    CVectorVisitor()
    {
        vec = nullptr;
    }

    void StartMesh(class CVertexCompCommand& cmd) override
    {
        if (!vec)
            vec = new float[cmd.cm_dim];
    }

    ~CVectorVisitor()
    {
        if (vec)
            delete[] vec;
    }
};

/*
 * Query visitor. For every vertex we read the vector from the map, and if we find
 * one we append the desired component to the value array. This is pretty much all
 * that's required for a query of the 'value' argument.
 */
class CQueryVisitor : public CVectorVisitor
{
public:
    bool Vertex(class CVertexCompCommand& cmd) override
    {
        if (LXx_FAIL(cmd.cm_point.MapEvaluate(cmd.cm_mapID, vec)))
            return false;

        va.AddFloat(vec[comp]);
        return false;
    }

    CLxUser_ValueArray va;
    int                comp;
};

LxResult CVertexCompCommand::cmd_Query(unsigned int /*index*/, ILxUnknownID vaQuery)
{
    CQueryVisitor vis;

    vis.va.set(vaQuery);
    attr_GetInt(ARGi_COMP, &vis.comp);

    Enumerate(vis);
    return LXe_OK;
}

/*
 * Apply visitor. This time we read out the vector, change the component, and
 * write it back.
 */
class CApplyVisitor : public CVectorVisitor
{
public:
    bool Vertex(class CVertexCompCommand& cmd) override
    {
        if (LXx_FAIL(cmd.cm_point.MapEvaluate(cmd.cm_mapID, vec)))
            return false;

        vec[comp] = static_cast<float>(value);
        cmd.cm_point.SetMapValue(cmd.cm_mapID, vec);
        return false;
    }

    int    comp;
    double value;
};

void CVertexCompCommand::cmd_Execute(unsigned int /*flags*/)
{
    CApplyVisitor vis;

    attr_GetInt(ARGi_COMP, &vis.comp);
    attr_GetFlt(ARGi_VALUE, &vis.value);

    Enumerate(vis, true);

    basic_Message().SetCode(LXe_OK);

    /*
     * Test persistent data by recording executions.
     */
    pd->GenIndex();
    pd->Peek();
    pd->Poke(vis.comp, vis.value, cm_name);
}

extern void init_InstanceSource();

/*
 * Setup our command as a server. It has a command interface, an attributes
 * interface for arguments, and an attributesUI interface.
 */
void initialize()
{
    CLxGenericPolymorph* srv;

    srv = new CLxPolymorph<CVertexCompCommand>;
    srv->AddInterface(new CLxIfc_Command<CVertexCompCommand>);
    srv->AddInterface(new CLxIfc_Attributes<CVertexCompCommand>);
    srv->AddInterface(new CLxIfc_AttributesUI<CVertexCompCommand>);
    lx::AddServer("vertex.componentValue", srv);

    init_InstanceSource();
}

void cleanup()
{
    if (pd)
        delete pd;
}
