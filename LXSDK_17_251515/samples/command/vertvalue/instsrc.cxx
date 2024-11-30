/*
 * Command: instance.source
 *
 *  Copyright 0000
 *
 * This module implements the command:
 *
 *	instance.source source:&item
 */
#include <cstdio>
#include <lx_item.hpp>
#include <lxidef.h>

#include <lx_listener.hpp>
#include <lx_select.hpp>
#include <lx_seltypes.hpp>
#include <lxu_command.hpp>
#include <set>
#include <string>

// not used, but included to make it part of the SDK
#include <lx_undo.hpp>

/*
 * ----------------------------------------------------------------
 * The selection tracker class keeps track of when item selection changes and
 * takes care of building a list of unique item types for the current state.
 * It's also in charge of enumeration, which is why we have a vistor class.
 */
class CItemVisitor
{
public:
    virtual bool Item(CLxUser_Item& item) = 0;
};

class CItemSelectionTracker : public CItemVisitor, public CLxImpl_SelectionListener, public CLxSingletonPolymorph
{
public:
    CLxUser_SceneService          srv_scene;
    CLxUser_SelectionService      srv_sel;
    CLxUser_ItemPacketTranslation pkt_item;
    LXtID4                        selID_item;
    bool                          is_valid;
    unsigned                      use_count;
    std::set<LXtItemType>         cur_types;

    LXtItemType mesh_type;
    LXtItemType meshInst_type;

    LXxSINGLETON_METHOD;

    CItemSelectionTracker()
    {
        srv_scene.ItemTypeLookup(LXsITYPE_MESH, &mesh_type);
        srv_scene.ItemTypeLookup(LXsITYPE_MESHINST, &meshInst_type);

        is_valid  = false;
        use_count = 1;

        AddInterface(new CLxIfc_SelectionListener<CItemSelectionTracker>);

        selID_item = srv_sel.LookupType(LXsSELTYP_ITEM);
        pkt_item.autoInit();
    }

    void selevent_Add(LXtID4 type, unsigned int /*subtype*/) override
    {
        if (type == selID_item)
            is_valid = false;
    }

    void selevent_Remove(LXtID4 type, unsigned int /*subtype*/) override
    {
        if (type == selID_item)
            is_valid = false;
    }

    void Enumerate(CItemVisitor& vis)
    {
        CLxUser_Item  item;
        LXtScanInfoID scan;
        void*         pkt;

        scan = nullptr;
        while ((scan = srv_sel.ScanLoopCurrent(scan, selID_item, &pkt)) != nullptr)
        {
            pkt_item.GetItem(pkt, item);
            if (vis.Item(item))
                return;
        }
    }

    void ValidateTypeSet()
    {
        cur_types.clear();
        Enumerate(*this);
    }

    bool Item(CLxUser_Item& item) override
    {
        /*
         *	Mesh instances do not have the same item type as the source mesh.
         *	Instead, they are a special item type called meshInst. If the
         *	current item type is a meshInst, add the mesh type to the
         *	current types list. Otherwise, just store the item type.
         */

        if (item.IsA(meshInst_type))
            cur_types.insert(mesh_type);
        else
            cur_types.insert(item.Type());

        return false;
    }

    bool AllowType(LXtItemType type)
    {
        if (!is_valid)
            ValidateTypeSet();

        for (auto sit = cur_types.begin(); sit != cur_types.end(); sit++)
            if (srv_scene.ItemTypeTest(*sit, type) == LXe_TRUE)
                return true;

        return false;
    }
};

/*
 * We only need one selection tracker for however many instances of commands, so
 * we keep a count.
 */
static CItemSelectionTracker* sT = nullptr;

void SelTrack_Acquire(void)
{
    if (sT)
    {
        sT->use_count++;
        return;
    }

    CLxUser_ListenerService ls;

    sT = new CItemSelectionTracker;
    ls.AddListener(*sT);
}

void SelTrack_Release(void)
{
    sT->use_count--;
    if (sT->use_count)
        return;

    CLxUser_ListenerService ls;

    ls.RemoveListener(*sT);
    delete sT;
    sT = nullptr;
}

/*
 * ----------------------------------------------------------------
 * The 'instance.source' command has the usual collection of basic methods,
 * plus a method for customizing argument UI.
 */
class CInstSourceCommand : public CLxBasicCommand
{
public:
    CInstSourceCommand();
    ~CInstSourceCommand();

    int  basic_CmdFlags() override;
    bool basic_Notifier(int index, std::string& name, std::string& args) override;
    bool basic_Enable(CLxUser_Message& msg) override;

    CLxDynamicUIValue* atrui_UIValue(unsigned int index) override;

    void     cmd_Execute(unsigned int flags) override;
    LxResult cmd_Query(unsigned int index, ILxUnknownID vaQuery) override;
};

CInstSourceCommand::CInstSourceCommand()
{
    dyna_Add("source", "&item");
    basic_SetFlags(0, LXfCMDARG_QUERY);

    SelTrack_Acquire();
}

CInstSourceCommand::~CInstSourceCommand()
{
    SelTrack_Release();
}

int CInstSourceCommand::basic_CmdFlags()
{
    return LXfCMD_MODEL | LXfCMD_UNDO;
}

bool CInstSourceCommand::basic_Notifier(int index, std::string& name, std::string& args)
{
    if (index == 0)
    {
        name = "select.event";
        args = "item +v";  // VALUE on item selection
    }
    else if (index == 1)
    {
        name = "select.event";
        args = "item exist+d";  // DISABLE on item selection existence
    }
    else
        return false;

    return true;
}

/*
 * Enable -- test if there's anything selected.
 */
class CEnableItemVisitor : public CItemVisitor
{
public:
    bool any;

    bool Item(CLxUser_Item& /*item*/) override
    {
        any = true;
        return true;
    }
};

bool CInstSourceCommand::basic_Enable(CLxUser_Message& /*msg*/)
{
    CEnableItemVisitor vis;

    vis.any = false;
    sT->Enumerate(vis);
    return vis.any;
}

/*
 * Query -- return a list of all selected item's source items. This is a value
 * reference datatype so it allows for 'none'.
 */
class CQueryItemVisitor : public CItemVisitor
{
public:
    CLxUser_SceneService srv_scene;
    CLxUser_ValueArray   va;

    LXtItemType meshInst_type;

    CQueryItemVisitor()
    {
        srv_scene.ItemTypeLookup(LXsITYPE_MESHINST, &meshInst_type);
    }

    bool Item(CLxUser_Item& item) override
    {
        CLxUser_Value          val;
        CLxUser_ValueReference ref;
        LXtObjectID            src = nullptr;

        va.AddEmpty(val);
        ref.set(val);

        /*
         *	If the item is a mesh instance, use a different method
         *	for getting it's source item.
         */

        if (item.IsA(meshInst_type))
            srv_scene.GetMeshInstSourceItem(item, &src);
        else
            item.Source(&src);

        /*
         *	Set the initial choice to the current instance source.
         */

        if (src)
            ref.SetObject(static_cast<ILxUnknownID>(src));

        return false;
    }
};

LxResult CInstSourceCommand::cmd_Query(unsigned int /*index*/, ILxUnknownID vaQuery)
{
    CQueryItemVisitor vis;

    vis.va.set(vaQuery);
    sT->Enumerate(vis);
    return LXe_OK;
}

/*
 * Customize the item popup. We use the selection tracker to tell us if the
 * item should be part of the item popup. Also, we want a 'none' item choice.
 */
class CItemPopup : public CLxDynamicUIValue
{
public:
    unsigned Flags() override
    {
        return LXfVALHINT_ITEMS | LXfVALHINT_ITEMS_NONE;
    }

    bool ItemTest(CLxUser_Item& item) override
    {
        return sT->AllowType(item.Type());
    }
};

CLxDynamicUIValue* CInstSourceCommand::atrui_UIValue(unsigned int /*index*/)
{
    return new CItemPopup;
}

/*
 * Execute -- this changes the source item for all selected items, or at least
 * tries to. There are many possible reasons for failure, including the fact that
 * this is the item itself.
 */
class CExecItemVisitor : public CItemVisitor
{
public:
    CLxUser_SceneService srv_scene;
    CLxUser_Item         set_to;
    const char*          set_id;
    int                  n_total, n_fail;

    LXtItemType mesh_type;
    LXtItemType meshInst_type;

    CExecItemVisitor()
    {
        srv_scene.ItemTypeLookup(LXsITYPE_MESH, &mesh_type);
        srv_scene.ItemTypeLookup(LXsITYPE_MESHINST, &meshInst_type);
    }

    bool Item(CLxUser_Item& item) override
    {
        CLxUser_Scene     scene;
        CLxUser_ItemGraph meshInst_graph;
        CLxUser_Item      current_source;
        LxResult          rc;
        const char*       id = nullptr;

        n_total++;
        rc = LXe_FAILED;

        if (item.IsA(meshInst_type))
        {
            /*
             *	If the item is a meshInst, we want to allow the user to set
             *	the source to an item of the mesh type. A slightly different
             *	method is used for changing the source of mesh instances.
             */

            item.Context(scene);
            scene.GetGraph(LXsGRAPH_MESHINST, meshInst_graph);

            if (set_to.test() && meshInst_graph.test() && set_to.IsA(mesh_type))
            {
                item.Ident(&id);

                if (id != set_id)
                {
                    /*
                     *	The mesh instance source can be changed by modifying
                     *	the meshInst graph. Mesh instances are defined by a link
                     *	from the mesh source to the mesh instance. By deleting
                     *	the link and connecting it to another mesh item, the
                     *	source will be changed.
                     */

                    if (meshInst_graph.Reverse(item) > 0)
                    {
                        if (meshInst_graph.Reverse(item, 0, current_source))
                        {
                            if (LXx_OK(meshInst_graph.DeleteLink(current_source, item)))
                                rc = meshInst_graph.AddLink(set_to, item);
                        }
                    }
                }
            }
        }
        else
        {
            /*
             *	If the item is not a mesh instance, then we use a different
             *	method for setting the instance source.
             */

            if (set_to.test())
            {
                if (set_to.IsA(item.Type()))
                {
                    item.Ident(&id);
                    if (id != set_id)
                        rc = item.SetSource(set_to);
                }
            }
            else
                rc = item.SetSource(nullptr);
        }

        if (LXx_FAIL(rc))
            n_fail++;

        return false;
    }
};

void CInstSourceCommand::cmd_Execute(unsigned int /*flags*/)
{
    CExecItemVisitor       vis;
    CLxUser_ValueReference ref;

    if (dyna_Object(0, ref) && ref.Get(vis.set_to))
        vis.set_to.Ident(&vis.set_id);

    vis.n_total = 0;
    vis.n_fail  = 0;
    sT->Enumerate(vis);

    if (vis.n_fail == 0)
        return;

    CLxUser_Message& msg = basic_Message();

    if (vis.n_fail == vis.n_total)
    {
        msg.SetMsg("common", 99);
        msg.SetArg(1, "Total failure!");
    }
    else
    {
        msg.SetMsg("common", 99);
        msg.SetArg(1, "Some of them failed.");
    }
}

/*
 * Setup our command as a server. It has a command interface, an attributes
 * interface for arguments, and an attributesUI interface.
 */
void init_InstanceSource()
{
    CLxGenericPolymorph* srv;

    srv = new CLxPolymorph<CInstSourceCommand>;
    srv->AddInterface(new CLxIfc_Command<CInstSourceCommand>);
    srv->AddInterface(new CLxIfc_Attributes<CInstSourceCommand>);
    srv->AddInterface(new CLxIfc_AttributesUI<CInstSourceCommand>);
    lx::AddServer("instance.source", srv);
}
