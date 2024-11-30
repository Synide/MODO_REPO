/*
 * MORPH.CPP	Morph Mesh Influence
 *
 *	Copyright 0000
 */
#include "deformMappings.hxx"

namespace Influence_Morph
{  // disambiguate everything with a namespace

#define SRVNAME_ITEMTYPE LXsITYPE_MORPHDEFORM
#define SRVNAME_MODIFIER LXsITYPE_MORPHDEFORM
#define SPWNAME_INSTANCE "morph.inst"

/*
 * The package has a set of standard channels with default values. These
 * are setup at the start using the AddChannel interface.
 */
#define Cs_MESHINF  LXsICHAN_MORPHDEFORM_MESHINF
#define Cs_ENABLE   LXsICHAN_MORPHDEFORM_ENABLE
#define Cs_MAPNAME  LXsICHAN_MORPHDEFORM_MAPNAME
#define Cs_STRENGTH LXsICHAN_MORPHDEFORM_STRENGTH
#define Cs_USELOCAL LXsICHAN_MORPHDEFORM_USELOCAL

    /*
     * -------------------------------------------------------
     *
     * The instance implements the interfaces for the influence item. Since most
     * of the work is done by the deformer, the instance really just has to describe
     * the deformer in high-level terms.
     */
    class CInstance : public CLxImpl_PackageInstance, public CLxImpl_MeshInfluence, public CLxImpl_ItemInfluence, public CLxImpl_WeightMapDeformerItem
    {
    public:
        static std::set<CInstance*> all_inst;

        static void initialize()
        {
            CLxGenericPolymorph* srv;

            srv = new CLxPolymorph<CInstance>;
            srv->AddInterface(new CLxIfc_PackageInstance<CInstance>);
            srv->AddInterface(new CLxIfc_MeshInfluence<CInstance>);
            srv->AddInterface(new CLxIfc_ItemInfluence<CInstance>);
            srv->AddInterface(new CLxIfc_WeightMapDeformerItem<CInstance>);
            lx::AddSpawner(SPWNAME_INSTANCE, srv);
        }

        CLxUser_Item m_item;

        /*
         * Remember ourselves.
         */
        LxResult pins_Initialize(ILxUnknownID item, ILxUnknownID /*super*/) override
        {
            m_item.set(item);
            cur_item = nullptr;
            all_inst.insert(this);
            return LXe_OK;
        }

        void pins_Cleanup(void) override
        {
            all_inst.erase(this);
            m_item.clear();
        }

        /*
         * Try to provide a name that describes the target deformation as much
         * as possible.
         */
        CLxUser_DeformerService  def_S;
        CLxUser_SceneService     scene_S;
        CLxUser_ChannelUIService chan_S;
        CLxUser_MessageService   msg_S;
        CLxUser_ValueService     val_S;

        LxResult pins_SynthName(char* buf, unsigned len) override
        {
            CLxUser_ChannelRead chan;
            CLxUser_Message     msg;
            CLxUser_Value       strVal;
            CLxUser_Item        def;
            // const char		*sptr;
            std::string key, name, abbrev;
            // int			 type;
            bool isLoc /*, hasName*/;

            if (!def_S.GetDeformerDeformationItem(m_item, def, isLoc))
                return LXe_NOTIMPL;

            msg_S.NewMessage(msg);
            msg.SetMsg(SRVNAME_ITEMTYPE, key.c_str());
            msg.SetArg(1, abbrev.c_str());

            return msg_S.MessageText(msg, buf, len);
        }

        /*
         * The MeshInfluence and ItemInfluence interfaces list the target items
         * using a cached mappings object. This has to be rebuilt anytime the
         * state changes, which is managed by the package.
         */
        DeformMapHeader::CDeformerMappings* def_map;

        CInstance()
        {
            def_map = nullptr;
        }

        ~CInstance()
        {
            InvalidateMappings();
        }

        void ValidateMappings()
        {
            if (!def_map)
                def_map = new DeformMapHeader::CDeformerMappings(m_item);
        }

        void InvalidateMappings()
        {
            if (def_map)
            {
                DeformMapHeader::CDeformerMappings::Release(def_map);
                def_map = nullptr;
            }
        }

        static void InvalidateAll()
        {
            for (auto cit = all_inst.begin(); cit != all_inst.end(); cit++)
                (*cit)->InvalidateMappings();
        }

        unsigned minf_MeshCount() override
        {
            InvalidateMappings();
            ValidateMappings();
            return static_cast<unsigned>(def_map->mesh_items.size());
        }

        LxResult minf_MeshByIndex(unsigned index, void** ppvObj) override
        {
            ValidateMappings();
            return def_map->mesh_items[index].get(ppvObj);
        }

        unsigned minf_PartitionIndex(unsigned index) override
        {
            return index + (iinf_HasItems() == LXe_TRUE ? 1 : 0);
        }

        /*
         * Listing items is done by enumeration.
         */
        LxResult iinf_HasItems() override
        {
            ValidateMappings();
            return def_map->has_items ? LXe_TRUE : LXe_FALSE;
        }

        class CSrcItemsEnumVisitor : public CLxImpl_AbstractVisitor
        {
        public:
            CLxUser_ItemInfluence  ii;
            std::set<CLxUser_Item> items;

            LxResult Evaluate() override
            {
                CLxUser_Item item;

                if (ii.CurItem(item))
                    items.insert(item);

                return LXe_OK;
            }
        };

        const CLxUser_Item* cur_item;

        LxResult iinf_Enumerate(ILxUnknownID visitor) override
        {
            CSrcItemsEnumVisitor                             vis;
            DeformMapHeader::CDeformerMappings::FlowList_Itr iflow;

            ValidateMappings();

            for (iflow = def_map->item_flow.begin(); iflow != def_map->item_flow.end(); iflow++)
            {
                vis.ii.set(def_map->def_items[iflow->src_index]);
                vis.ii.Enum(&vis);
            }

            CLxUser_Visitor other(visitor);
            LxResult        rc = LXe_OK;

            for (auto iit = vis.items.begin(); iit != vis.items.end(); iit++)
            {
                cur_item = &(*iit);
                rc       = other.Evaluate();
                if (rc != LXe_OK)
                    break;
            }

            cur_item = nullptr;
            return rc;
        }

        LxResult iinf_GetItem(void** ppvObj) override
        {
            if (cur_item)
                return cur_item->get(ppvObj);
            else
                return LXe_OUTOFBOUNDS;
        }
    };

    std::set<CInstance*> CInstance::all_inst;  // Weird, weird, weird...

    /*
     * Class Declarations
     *
     * These have to come before their implementions because they reference each
     * other. Descriptions are attached to the implementations.
     */
    class CPackage : public CLxDefaultPackage, public CLxImpl_ChannelUI
    {
    public:
        static LXtTagInfoDesc descInfo[];
        CLxSpawner<CInstance> inst_spawn;

        CPackage() : inst_spawn(SPWNAME_INSTANCE)
        {
        }

        LxResult pkg_SetupChannels(ILxUnknownID /*addChan*/) override;

        LxResult pkg_TestInterface(const LXtGUID* guid) override
        {
            return inst_spawn.TestInterfaceRC(guid);
        }

        LxResult pkg_Attach(void** ppvObj) override
        {
            inst_spawn.Alloc(ppvObj);
            return LXe_OK;
        }
    };

    /*
     * ----------------------------------------------------------------
     * Package Class
     *
     * Packages implement item types, or simple item extensions. They are
     * like the metatype object for the item type. They define the common
     * set of channels for the item type and spawn new instances.
     */

    LXtTagInfoDesc CPackage::descInfo[] = { { LXsPKG_SUPERTYPE, LXsITYPE_LOCATOR },
                                            { LXsPKG_DEFORMER_CHANNEL, Cs_MESHINF },
                                            { LXsPKG_DEFORMER_FLAGS, "+WX" },  // no weight, no xfrm
                                            { LXsPKG_DEFORMER_CREATECMD, "morphDeform.create" },
                                            { nullptr } };

    LxResult CPackage::pkg_SetupChannels(ILxUnknownID addChan)
    {
        CLxUser_AddChannel ac(addChan);

        ac.NewChannel(Cs_MESHINF, LXsTYPE_OBJREF);
        ac.SetInternal();

        ac.NewChannel(Cs_ENABLE, LXsTYPE_BOOLEAN);
        ac.SetDefault(0.0, 1);

        ac.NewChannel(Cs_MAPNAME, LXsTYPE_VERTMAPNAME);

        ac.NewChannel(Cs_STRENGTH, LXsTYPE_PERCENT);
        ac.SetDefault(1.0, 0);

        ac.NewChannel(Cs_USELOCAL, LXsTYPE_BOOLEAN);
        ac.SetDefault(0.0, 0);

        return LXe_OK;
    }

    /*
     * Mesh Influence for a morph is dead simple. The CChanState holds values of
     * the channels and handles getting them from the evaluation state. It also
     * serves as the modifier cache so we can compare previous values.
     */
    class CChanState : public CLxObject
    {
    public:
        std::string name;
        double      factor;
        LXtMatrix   xfrm;
        bool        enabled, local;

        void Attach(CLxUser_Evaluation& eval, ILxUnknownID item)
        {
            eval.AddChan(item, Cs_ENABLE);
            eval.AddChan(item, Cs_MAPNAME);
            eval.AddChan(item, Cs_STRENGTH);
            eval.AddChan(item, Cs_USELOCAL);
            eval.AddChan(item, LXsICHAN_XFRMCORE_WORLDMATRIX);
        }

        void Read(CLxUser_Attributes& attr, unsigned index)
        {
            CLxUser_Matrix m4;

            enabled = attr.Bool(index++);
            if (enabled)
            {
                attr.String(index++, name);
                factor = attr.Float(index++);
                local  = attr.Bool(index++);
                if (local)
                {
                    attr.ObjectRO(index++, m4);
                    m4.Get3(xfrm);
                }
            }
        }

        LxResult Compare(CChanState& that)
        {
            if (enabled != that.enabled || name.compare(that.name))
                return LXeEVAL_DIFFERENT;

            return LXeDEFORM_NEWOFFSET;
        }
    };

    class CInfluence : public CLxMeshInfluence
    {
    public:
        std::vector<LXtMeshMapID> cont_maps;
        CLxUser_Item              item;
        LXtMeshMapID              map_id;
        CChanState                cur;
        bool                      is_abs;
        bool                      has_cnt;

        CInfluence() : map_id(nullptr)
        {
        }

        bool ReadContainersMap(CLxUser_Mesh& mesh)
        {
            // Check morph influence links
            CLxUser_ItemGraph graph;
            CLxUser_MeshMap   map;
            CLxUser_Item      othr;
            std::string       name;
            int               i, count;

            cont_maps.clear();

            graph.from(item, LXsGRAPH_DEFORMERS);
            count = graph.Forward(item);
            for (i = count - 1; i >= 0; i--)
            {  // Reversed!
                // if linked item is a morph container
                graph.Forward(item, i, othr);
                if (!othr.IsA(cit_morphCont))
                    continue;

                MapName(othr, name);
                map.fromMesh(mesh);
                if (map.SelectByName(LXi_VMAP_MORPH, name.c_str()) != LXe_OK || !map.test())
                    continue;

                cont_maps.push_back(map.ID());
            }

            return cont_maps.size() > 0;
        }

        void MapName(CLxUser_Item& itemRef, std::string& name)
        {
            CLxUser_Item userItem(itemRef);  // don't want to change itemRef
            LXtObjectID  obj;
            const char*  id;

            while (LXx_OK(userItem.Reference(&obj)))
                userItem.take(obj);

            userItem.Ident(&id);
            name = id;
            name = LXsVMAP_ITEMPREFIX + name;
        }

        bool SelectMap(CLxUser_Mesh& mesh, CLxUser_MeshMap& map) override
        {
            is_abs  = false;
            has_cnt = ReadContainersMap(mesh);
            if (has_cnt)
                return false;

            map.SelectByName(LXi_VMAP_MORPH, cur.name.c_str());
            map_id = map.ID();
            if (map_id)
                return true;

            map.SelectByName(LXi_VMAP_SPOT, cur.name.c_str());
            map_id = map.ID();
            is_abs = true;

            return true;
        }

        void Offset(CLxUser_Point& point, float weight, LXtFVector offset) override
        {
            LXtFVector offF, posF;

            // Morph Container Mode: get correct map_id
            if (has_cnt)
            {
                unsigned i, n = static_cast<unsigned>(cont_maps.size());
                for (i = 0; i < n; i++)
                {
                    if (!cont_maps[i])
                        continue;
                    if (point.MapValue(cont_maps[i], offF) == LXe_OK)
                        break;
                }

                // No map found: exit with a 0 vector.
                if (i == n)
                {
                    LXx_VSET3(offset, 0., 0., 0.);
                    return;
                }
            }
            else
                point.MapValue(map_id, offF);

            if (is_abs)
            {
                point.Pos(posF);
                LXx_VSUB(offF, posF);
            }

            if (cur.local)
            {
                LXtFVector tmp;

                lx::MatrixMultiply(tmp, cur.xfrm, offF);
                LXx_VSCL3(offset, tmp, cur.factor * weight);
            }
            else
                LXx_VSCL3(offset, offF, cur.factor * weight);
        }
    };

    /*
     * The modifier operates on all items of this type, and sets the mesh influence
     * channel to an object allocated using the input parameters for the modifier.
     */
    class CModifierElement : public CLxItemModifierElement
    {
    public:
        CLxUser_Item item;
        unsigned     index;

        bool Test(ILxUnknownID) override
        {
            return false;
        }

        CLxObject* Cache() override
        {
            return new CChanState;
        }

        LxResult EvalCache(CLxUser_Evaluation& /*eval*/, CLxUser_Attributes& attr, CLxObject* cacheRaw, bool prev) override
        {
            CChanState*            cache = dynamic_cast<CChanState*>(cacheRaw);
            CInfluence*            infl;
            CLxUser_ValueReference ref;
            ILxUnknownID           obj;
            LxResult               rc;

            infl       = new CInfluence;
            infl->item = item;
            infl->Spawn(reinterpret_cast<void**>(&obj));
            attr.ObjectRW(index, ref);
            ref.SetObject(obj);
            lx::UnkRelease(obj);

            infl->cur.Read(attr, index + 1);
            if (prev)
                rc = cache->Compare(infl->cur);
            else
                rc = LXe_OK;

            *cache = infl->cur;
            return rc;
        }
    };

    class CModifier : public CLxItemModifierServer
    {
    public:
        const char* ItemType() override
        {
            return SRVNAME_ITEMTYPE;
        }

        CLxItemModifierElement* Alloc(CLxUser_Evaluation& eval, ILxUnknownID item) override
        {
            CModifierElement* elt;
            CChanState        tmp;

            elt        = new CModifierElement;
            elt->item  = item;
            elt->index = eval.AddChan(item, Cs_MESHINF, LXfECHAN_WRITE);

            tmp.Attach(eval, item);

            return elt;
        }

        const char* GraphNames() override
        {
            return LXsGRAPH_DEFORMERS;
        }
    };

    /*
     * Export package server to define a new item type. Also create and destroy
     * the factories so they can persist while their objects are in use.
     */
    void initialize()
    {
        CLxGenericPolymorph* srv;

        srv = new CLxPolymorph<CPackage>;
        srv->AddInterface(new CLxIfc_Package<CPackage>);
        srv->AddInterface(new CLxIfc_ChannelUI<CPackage>);
        srv->AddInterface(new CLxIfc_StaticDesc<CPackage>);
        lx::AddServer(SRVNAME_ITEMTYPE, srv);

        CInstance::initialize();

        CLxExport_ItemModifierServer<CModifier>::Define(SRVNAME_MODIFIER);
    }

};  // namespace Influence_Morph
