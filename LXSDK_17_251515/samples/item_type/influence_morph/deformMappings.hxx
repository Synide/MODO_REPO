#pragma once

#include <algorithm>
#include <cmath>
#include <iostream>
#include <lx_action.hpp>
#include <lx_channelui.hpp>
#include <lx_deform.hpp>
#include <lx_io.hpp>
#include <lx_layer.hpp>
#include <lx_listener.hpp>
#include <lx_log.hpp>
#include <lx_package.hpp>
#include <lx_plugin.hpp>
#include <lx_thread.hpp>
#include <lx_undo.hpp>
#include <lx_vmodel.hpp>
#include <lxidef.h>
#include <lxpmodel.h>
#include <lxu_command.hpp>
#include <lxu_deform.hpp>
#include <lxu_math.hpp>
#include <lxu_message.hpp>
#include <lxu_modifier.hpp>
#include <lxu_package.hpp>
#include <lxu_select.hpp>
#include <lxu_simd.hpp>
#include <lxw_schematic.hpp>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

/*
 * Some static item types
 */
static CLxItemType cit_mesh(LXsITYPE_MESH);
static CLxItemType cit_instance(LXsITYPE_MESHINST);
static CLxItemType cit_morphCont(LXsITYPE_MORPHCONTAINER);
static CLxItemType cit_genInf(LXsITYPE_GENINFLUENCE);
static CLxItemType cit_locator(LXsITYPE_LOCATOR);
static CLxItemType cit_weightCont(LXsITYPE_WEIGHTCONTAINER);
static CLxItemType cit_morphInf(LXsITYPE_MORPHDEFORM);
static CLxItemType cit_mddInf(LXsITYPE_MDD2);
static CLxItemType cit_wrapInf(LXsITYPE_WRAPDEFORM);
static CLxItemType cit_softLag(LXsITYPE_SOFTLAG);
static CLxItemType cit_modSculpt(LXsITYPE_MODSCULPT);
static CLxItemType cit_pushInf(LXsITYPE_PUSHINF);
static CLxItemType cit_mop(LXsITYPE_MESHOP);
static CLxItemType cit_group(LXsITYPE_DEFORMGROUP);
static CLxItemType cit_stackOp(LXsITYPE_MESHOPSTACK);

namespace DeformMapHeader
{

    /**
     * Template method for getting an array of keys from a map.
     */
    template <class K, class V>
    void KeyVector(const std::map<K, V>& map, std::vector<K>& keyList)
    {
        typename std::map<K, V>::const_iterator it;

        keyList.clear();
        for (it = map.begin(); it != map.end(); it++)
            keyList.push_back(it->first);
    }

    /**
     * The deformer mappings object is the subclass of our deformers
     * which computes the relationships between this deformer item and
     * all the ones it depends on. This is used directly by the item
     * instance to report related meshes and target items.
     */
    class CDeformerMappings
    {
    public:
        CLxUser_DeformerService d_S;

        /*
         * FlowSource defines a sub-influence that targets a mesh, given by the
         * influence item and the partition index. Called flow because it allows
         * us to chain influences together to affect each other.
         */
        class FlowSource
        {
        public:
            CLxUser_Item src_def;     // deformer item
            unsigned     src_index;   // deformer index (0 for this)
            unsigned     mesh_index;  // index for the mesh in the mesh sequence
            unsigned     part_index;  // partition index for the mesh

            bool operator==(const FlowSource& rhs) const
            {
                return (src_def == rhs.src_def) && (part_index == rhs.part_index);
            }
        };

        typedef std::vector<CLxUser_Item>         ItemList;
        typedef std::vector<FlowSource>           FlowList;
        typedef std::vector<FlowSource>::iterator FlowList_Itr;
        typedef std::map<CLxUser_Item, FlowList>  FlowMap;

        /*
         * Item relationships. This item, the meshes it deforms, and the
         * sub-influences that provide the content and weights of the meshes.
         */
        CLxUser_Item m_item;      // this item
        FlowMap      flow_map;    // list of FlowSources by target mesh item
        ItemList     mesh_items;  // list of mesh items (partition order)
        ItemList     def_items;   // flow deformer items (0 = this)
        FlowList     item_flow;   // FlowSources providing items
        bool         has_items;   // true if we have items
        unsigned     m_meshIdx;
        unsigned     m_meshCount;  // number of meshes before adding meshop stack targets

        /*
         * Helper class to build the list of deformers. First time we encounter it
         * we add it to the end of the list and remember the index.
         */
        class DeformerTable
        {
        public:
            ItemList*                   def_items;
            std::map<CLxUser_Item, int> def_2_idx;
            int                         cur_index;

            void Set(ItemList& list)
            {
                cur_index = 0;
                def_items = &list;
            }

            int Index(CLxUser_Item& def)
            {
                if (def_2_idx.find(def) == def_2_idx.end())
                {
                    def_items->push_back(def);
                    def_2_idx[def] = cur_index++;
                }

                return def_2_idx[def];
            }
        };

        DeformerTable src_table;

        /*
         * Initialization reads the item relations and builds the flow_map table. It
         * finds target meshes and all the deformer items (including this one) that
         * affect it. This also extracts the list of mesh items for easier use in
         * the deformer item instance, and builds the deformer list with this
         * item at index zero.
         */
        void Init(ILxUnknownID itemObj)
        {
            CLxUser_Item      target, stackOp;
            CLxUser_ItemGraph defGraph;
            CLxUser_ItemGraph stackGraph;

            src_table.Set(def_items);

            m_item.set(itemObj);
            has_items = false;

            defGraph.from(m_item, LXsGRAPH_DEFORMERS);
            stackGraph.from(m_item, "deformerStack");

            src_table.Index(m_item);
            m_meshIdx = 0;

            CollectTargets(m_item, defGraph, stackGraph);

            KeyVector(flow_map, mesh_items);
        }

        void ProcessTarget(CLxUser_Item& target)
        {
            FlowSource            fsrc;
            CLxUser_MeshInfluence mi;
            CLxUser_ItemInfluence iif;
            CLxUser_Item          mesh;
            unsigned              i, n;

            if (target.IsA(cit_mesh) || target.IsA(cit_instance))
            {
                fsrc.src_def.set(m_item);
                fsrc.src_index  = src_table.Index(fsrc.src_def);
                fsrc.mesh_index = std::numeric_limits<unsigned>::max();  // never used
                fsrc.part_index = m_meshIdx++;
                flow_map[target].push_back(fsrc);
                return;
            }

            if (mi.set(target))
            {
                fsrc.src_def.set(target);
                fsrc.src_index = src_table.Index(fsrc.src_def);

                n = mi.MeshCount();
                for (i = 0; i < n; i++)
                {
                    mi.GetMesh(i, mesh);
                    fsrc.mesh_index = i;
                    fsrc.part_index = mi.PartitionIndex(i);
                    flow_map[mesh].push_back(fsrc);
                }
            }
            else if (InfluenceChannel(target) >= 0)
            {
                fsrc.src_def.set(target);
                fsrc.src_index = src_table.Index(fsrc.src_def);

                d_S.MeshCount(target, &n);
                for (i = 0; i < n; i++)
                {
                    d_S.GetMesh(target, i, mesh);
                    fsrc.mesh_index = i;
                    fsrc.part_index = i;
                    flow_map[mesh].push_back(fsrc);
                }
            }

            if (iif.set(target) && iif.HasItems() == LXe_TRUE)
            {
                fsrc.src_def.set(target);
                fsrc.src_index  = src_table.Index(fsrc.src_def);
                fsrc.mesh_index = std::numeric_limits<unsigned>::max();  // never used
                fsrc.part_index = 0;
                item_flow.push_back(fsrc);
                has_items = true;
            }
        }

        void CollectTargets(CLxUser_Item& item, CLxUser_ItemGraph& defGraph, CLxUser_ItemGraph& stackGraph)
        {
            CLxUser_Item target, stackOp;
            unsigned     i, n;

            n = defGraph.Forward(item);
            for (i = n; i > 0; i--)
            {
                defGraph.Forward(item, i - 1, target);
                ProcessTarget(target);
            }

            i = 0;
            while (stackGraph.Reverse(item, i, stackOp))
            {
                i++;
                CollectTargets(stackOp, defGraph, stackGraph);
            }
        }

        int InfluenceChannel(CLxUser_Item& item)
        {
            unsigned chan;

            if (LXx_OK(d_S.DeformerChannel(item, &chan)))
                return chan;

            if (item.IsA(cit_weightCont))
                return item.ChannelIndex(LXsICHAN_WEIGHTCONTAINER_INFLUENCE);

            if (item.IsA(cit_morphCont))
                return item.ChannelIndex(LXsICHAN_MORPHDEFORM_MESHINF);

            return -1;
        }

        /*
         * For the purpose of testing whether the modifier node is still valid
         * we just have to test the equivalence of the flow map(s).
         */
        bool IsSame(const CDeformerMappings& that) const
        {
            return (m_item == that.m_item) && (flow_map == that.flow_map) && (item_flow == that.item_flow);
        }

        /*
         * Constructors, with one that takes an item for quick initialization.
         */
        unsigned use_count;

        CDeformerMappings() : use_count(1)
        {
        }
        CDeformerMappings(ILxUnknownID item) : use_count(1)
        {
            Init(item);
        }

        CDeformerMappings* AddRef()
        {
            use_count++;
            return this;
        }

        static void Release(CDeformerMappings* dp)
        {
            if (--dp->use_count == 0)
                delete dp;
        }
    };

};  // namespace DeformMapHeader
