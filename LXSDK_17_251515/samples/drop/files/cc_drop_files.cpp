/*
 * MODO SDK SAMPLE
 *
 * Drop package server
 * ===================
 *
 *	Copyright 0000
 *
 * This implements a Drop server for files.
 *
 * CLASSES USED:
 *
 *		CLxDrop
 *		CLxDropActionT<>
 *		CLxMeta_Drop
 *
 * TESTING:
 *
 * Drag any file from the OS into the app, and hover over an item in the item
 * list. You will get two choices of csam action in the popup, both resetting
 * the name of the item to some part of the path.
 *
 * To test action disable, create a directory with a one-letter name, and drag
 * a file from that onto a locator item. In that case only the base name will
 * be an option as a drop action.
 */
#include <lx_file.hpp>
#include <lx_item.hpp>
#include <lx_itemui.hpp>
#include <lxu_command.hpp>
#include <lxu_drop.hpp>

#define SRVNAME_DROP "csam.drop.files"

#define ACTION_BASENAME "setBase"
#define ACTION_PATHNAME "setPath"

namespace DropFiles
{

    /*
     * ------------------------------------------------------------
     * Drop server for dropping files onto items. The drop class computes the state
     * for the action based on source and destination, holds onto it, and then
     * executes the action if the drop happens.
     */
    class CDrop : public CLxDrop
    {
    public:
        CLxUser_CommandService cmd_S;
        CLxUser_Item           m_loc;
        std::string            base_name, path_name;
        bool                   has_base, has_path;

        /*
         * recognize_array() is called once at the start of dragging, and
         * determines if this drop server can read the object being dragged.
         * Files being dragged are delivered as a list of strings.
         *
         * We're just going to look at the first one and parse the base name
         * and path name (actually the base name of the parent dir). If we
         * find a base name (and optional path name) we return true to
         * indicate this server can process this input.
         */
        bool recognize_array(CLxUser_ValueArray& list) override
        {
            std::string path;
            unsigned    i, n;

            has_base = false;
            has_path = false;

            n = list.Count();
            for (i = 0; i < n; i++)
            {
                if (LXx_FAIL(list.GetString(i, path)))
                    continue;

                CLxUser_FileService f_S;
                std::string         parent;
                LxResult            rc;

                rc = f_S.ParsePath(path.c_str(), LXiFILECOMP_BASENAME, base_name);
                if (LXx_OK(rc))
                    has_base = true;

                rc = f_S.ParsePath(path.c_str(), LXiFILECOMP_DIRECTORY, parent);
                if (LXx_OK(rc))
                {
                    rc = f_S.ParsePath(parent.c_str(), LXiFILECOMP_BASENAME, path_name);
                    if (LXx_OK(rc) && path_name.length() > 2)
                        has_path = true;
                }

                return has_base;
            }

            return false;
        }

        /*
         * enabled() is called for each drop destination as the drag moves across
         * the GUI. Returning true enables all drop actions.
         *
         * We look for a destination interface that we want, and check that it
         * contains a valid item. If so we return true.
         */
        bool enabled(ILxUnknownID dest) override
        {
            CLxUser_LocatorDest ldest(dest);

            return (ldest.test() && ldest.Item(m_loc));
        }

        /*
         * Utility for firing command strings.
         */
        void fire(std::string& cmd)
        {
            lx_err::check(cmd_S.ExecuteArgString(-1, LXiCTAG_NULL, cmd.c_str()));
        }

        /*
         * Utility for performing the drop action -- renaming the destination
         * item. This is done in a command block because it requires selecting
         * the item first.
         */
        void set_name(std::string& name)
        {
            CLxOpenCommandBlock scoped_block("csam Drop Actions");
            std::string         cmd;

            cmd = "select.item ";
            cmd += m_loc.IdentPtr();
            cmd += " set";
            fire(cmd);

            cmd = "item.name {" + name + "}";
            fire(cmd);
        }
    };

    /*
     * ------------------------------------------------------------
     * Our actions set the name of the destination item from parts of the filename.
     * The path name action is only enabled if a path name exists.
     */
    class CActionBase : public CLxDropActionT<CDrop>
    {
    public:
        /*
         * exec() is called to perform the drop action.
         */
        void exec() override
        {
            m_drop->set_name(m_drop->base_name);
        }
    };

    class CActionPath : public CLxDropActionT<CDrop>
    {
    public:
        /*
         * enabled() is called to check if an action should be disabled
         * even if the server it belongs to is enabled.
         */
        bool enabled(ILxUnknownID dest) override
        {
            return m_drop->has_path;
        }

        /*
         * exec() is called to perform the drop action.
         */
        void exec() override
        {
            m_drop->set_name(m_drop->path_name);
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
     *		 + backdrop action
     *		 + foreground action
     *
     * We set the source type of the drop server to files. New instances of the
     * actions are added during init as well.
     */
    static class CRoot : public CLxMetaRoot
    {
        bool pre_init() override
        {
            drop_meta.set_source_type(LXsDROPSOURCE_FILES);

            drop_meta.add_action(ACTION_BASENAME, new CActionBase);
            drop_meta.add_action(ACTION_PATHNAME, new CActionPath);

            add(&drop_meta);
            return false;
        }

    } root_meta;

};  // namespace DropFiles
