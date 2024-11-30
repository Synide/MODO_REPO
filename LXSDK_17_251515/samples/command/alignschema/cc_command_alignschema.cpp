/*
 * MODO SDK SAMPLE
 *
 * Schematic Group and Node Example
 * ======================
 *
 *	Copyright 0000
 *
 * This example implements a command which will align
 * the Y position of all nodes in a workspace to that
 * of the currently selected item.
 *
 * CLASSES USED:
 *
 *
 *		CLxCommand
 *		CLxMeta_Command<>
 *		CLxUser_SchematicGroup
 *		CLxUser_SchematicNode
 *
 * TESTING:
 *
 * Create a schematic workspace with multiple items in it
 * spread around.  Select one of the nodes and run
 * "csam.command.schemaAlign".  All nodes should be aligned
 * in the y axis to the selected node.
 */

#include <lxu_command.hpp>

#include <lx_group.hpp>
#include <lxidef.h>
#include <lxu_schematic.hpp>

#define SRVNAME_COMMAND "csam.command.schemaAlign"

namespace csam_command_schemaAlign
{

    /*
     * To test if an item is a certain type, we can use the
     * CLxItemType class and pass the item type's string
     * name into the constructor.  We create a static instance
     * the "group" item type to use later.
     */
    static CLxItemType groupType(LXsITYPE_GROUP);

    class CCommand : public CLxCommand
    {
    public:
        /*
         * To keep things organized, we create a utility function to
         * read the selected item.  This isn't inherited or required
         * for a command, it's just so that the execute function is cleaner.
         */
        bool getSelectedItem(CLxUser_Item& itm)
        {
            CLxUser_SelectionService      sSrv;
            CLxUser_ItemPacketTranslation iTrans;
            LXtID4                        selID;
            void*                         pkt;

            iTrans.autoInit();
            selID = sSrv.LookupType(LXsSELTYP_ITEM);
            pkt   = sSrv.Recent(selID);
            return iTrans.Item(pkt, itm);
        }

        /*
         * A second utility function will let us grab the first schematic
         * group that the selected item belongs to.  We're going to loop
         * through all the group items in the scene and see if they have
         * a SchematicGroup Interface for us to use.  Then we'll use
         * that SchematicGroup to loop through nodes, checking each one
         * to see if it ident matches the ident of the selected item.
         */
        bool getSchemaGroup(CLxUser_SchematicGroup& schemaGrp, CLxUser_SchematicNode& itemNode, CLxUser_Item& itm)
        {
            CLxUser_Scene scene(itm);
            CLxUser_Item  grpItem, testItem;
            const char *  testIdent, *givenIdent;
            unsigned      grpCount = 0, nodeCount, i = 0, j = 0;

            itm.Ident(&givenIdent);

            scene.ItemCount(groupType, &grpCount);
            for (i = 0; i < grpCount; i++)
            {
                if (scene.ItemByIndex(groupType, i, grpItem))
                {
                    if (schemaGrp.set(grpItem))
                    {
                        nodeCount = schemaGrp.NNodes();
                        for (j = 0; j < nodeCount; j++)
                        {
                            if (schemaGrp.NodeByIndex(j, itemNode))
                            {
                                itemNode.Item(testItem);

                                testItem.Ident(&testIdent);
                                if (strcmp(givenIdent, testIdent) == 0)
                                    return true;
                            }
                        }
                    }
                }
            }
            return false;
        }

        /*
         * The execute function is inherited from the parent class.  First,
         * we call our utility function to get the selected item.  If that
         * succeeds, we call our other utility function to try and find a
         * SchematicGroup object where that item is present.  If that also
         * succeeds, we'll store the Y position from the selected item's node,
         * then loop through all the nodes in the found SchematicGroup and set
         * their Y positions to match.
         */
        void execute() override
        {
            CLxUser_Item           alignItem;
            CLxUser_SchematicGroup schemaGroup;
            CLxUser_SchematicNode  schemaNode;
            double                 x, y, targetY;
            unsigned               nodeCount, i;

            if (getSelectedItem(alignItem))
            {
                if (getSchemaGroup(schemaGroup, schemaNode, alignItem))
                {
                    nodeCount = schemaGroup.NNodes();
                    schemaNode.Position(&x, &targetY);
                    for (i = 0; i < nodeCount; i++)
                    {
                        schemaNode.clear();
                        schemaGroup.NodeByIndex(i, schemaNode);
                        schemaNode.Position(&x, &y);
                        schemaNode.SetPosition(x, targetY);
                    }
                }
            }
        }
    };

    static CLxMeta_Command<CCommand> cmd_meta(SRVNAME_COMMAND);

    /*
     * ----------------------------------------------------------------
     * Root metaclass
     *
     *	(root)
     *	  |
     *	  +---	command
     *
     *	The command is set to model type, as it makes undoable changes to the scene.
     */

    static class CRoot : public CLxMetaRoot
    {
        bool pre_init() override
        {
            cmd_meta.set_type_model();
            add(&cmd_meta);
            return false;
        }
    } root_meta;

};  // namespace csam_command_schemaAlign
