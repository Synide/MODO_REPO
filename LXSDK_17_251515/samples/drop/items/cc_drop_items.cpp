/*
 * MODO SDK SAMPLE
 *
 * Drop package server
 * ===================
 *
 *	Copyright 0000
 *
 * This implements a Drop server for items. It copies the size channel of the
 * item being dropped on, to all the items being dragged.
 *
 * CLASSES USED:
 *
 *		CLxDrop
 *		CLxDropActionT<>
 *		CLxMeta_Drop
 *
 * TESTING
 *
 * 1. Set the size channel of one locator.
 * 2. Drag one or more locators and hover over the one with the size.
 * 3. Pick this drop action.
 *
 * Size channel should be set on the items that you dragged.
 */
#include <lx_item.hpp>
#include <lx_itemui.hpp>
#include <lxidef.h>
#include <lxu_command.hpp>
#include <lxu_drop.hpp>
#include <lxu_format.hpp>

#define SRVNAME_DROP "csam.drop.items"

#define ACTION_COPYSIZE "copySize"

namespace DropItems
{

    static CLxItemType cit_locator(LXsITYPE_LOCATOR);

    /*
     * ------------------------------------------------------------
     * Drop server for dropping
     */
    class CDrop : public CLxDrop
    {
    public:
        CLxUser_CommandService cmd_S;
        CLxUser_ValueArray     drag_list;
        CLxUser_Item           drop_item;

        /*
         * recognize_array() is called once at the start of dragging, and
         * determines if this drop server can read the object being dragged.
         * Items being dragged are delivered as a list of object containers.
         *
         * We check the list and if there are any locators being dragged we
         * return true.
         */
        bool recognize_array(CLxUser_ValueArray& list) override
        {
            CLxUser_ValueReference ref;
            CLxUser_Item           item;
            unsigned               i, n;

            n = list.Count();
            for (i = 0; i < n; i++)
            {
                lx_err::check(list.GetValue(i, ref));
                lx_err::check(ref.GetObject(item));
                if (item.IsA(cit_locator))
                {
                    drag_list.set(list);
                    return true;
                }
            }

            return false;
        }

        /*
         * enabled() is called for each drop destination as the drag moves across
         * the GUI. Returning true enables all drop actions.
         *
         * We look for a destination interface that we want, and check that it
         * contains a valid locatgor item. If so we return true.
         */
        bool enabled(ILxUnknownID dest) override
        {
            CLxUser_LocatorDest ldest(dest);

            return (ldest.test() && ldest.Item(drop_item) && drop_item.IsA(cit_locator));
        }

        /*
         * Utility for firing command strings.
         */
        void fire(std::string& cmd)
        {
            lx_err::check(cmd_S.ExecuteArgString(-1, LXiCTAG_NULL, cmd.c_str()));
        }

        /*
         * Utility for performing the drop action -- copying the size of the
         * destination locator to change all the items being dragged.
         */
        void perform_drop()
        {
            /*
             * This starts a command block because it's multiple commands.
             */
            CLxOpenCommandBlock scoped_block("csam Drop Actions");
            std::string         cmd;

            /*
             * Select all the items in the drag list.
             */
            CLxUser_ValueReference ref;
            CLxUser_Item           item;
            unsigned               i, n;

            n = drag_list.Count();
            for (i = 0; i < n; i++)
            {
                lx_err::check(drag_list.GetValue(i, ref));
                lx_err::check(ref.GetObject(item));

                cmd = "select.item ";
                cmd += item.IdentPtr();
                cmd += (i ? " add" : " set");
                fire(cmd);
            }

            /*
             * Read the size channel from the drop item.
             */
            CLxUser_ChannelRead read;
            double              size;

            read.from(drop_item);
            size = read.FValue(drop_item, LXsICHAN_LOCATOR_SIZE);

            /*
             * Execute the item.channel command to set the size on the
             * selected items.
             */
            cmd = "item.channel " LXsICHAN_LOCATOR_SIZE " " + lx::Encode(size);
            fire(cmd);
        }
    };

    /*
     * ------------------------------------------------------------
     * Our action just calls on the drop object to perform the operation.
     */
    class CActionCopySize : public CLxDropActionT<CDrop>
    {
    public:
        /*
         * exec() is called to perform the drop action.
         */
        void exec() override
        {
            m_drop->perform_drop();
        }
    };

    /*
     * ------------------------------------------------------------
     * Metaclass
     *
     * The name of the server is passed to the constructor.
     */
    static CLxMeta_Drop<CDrop> drop_meta(SRVNAME_DROP);

    /*
     * ------------------------------------------------------------
     * Metaclass declaration.
     *
     *	root
     *	 |
     *	 +---	drop (server)
     *		 + action
     *
     * We set the source type of the drop server to items. New instances of the
     * actions are added during init as well.
     */
    static class CRoot : public CLxMetaRoot
    {
        bool pre_init() override
        {
            drop_meta.set_source_type(LXsDROPSOURCE_ITEMS);

            drop_meta.add_action(ACTION_COPYSIZE, new CActionCopySize);

            add(&drop_meta);
            return false;
        }

    } root_meta;

};  // namespace DropItems
