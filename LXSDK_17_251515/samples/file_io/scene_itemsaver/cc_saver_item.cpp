/*
 * MODO SDK SAMPLE
 *
 * Item Saver Server and Command
 * ======================
 *
 *	Copyright 0000
 *
 * This implements an item-based saver
 * and a command to call it from
 *
 * CLASSES USED:
 *
 *		CLxSaverT<>
 *		CLxMeta_Saver
 *		CLxCommand
 *
 * TESTING:
 *
 * Select an item in the item list.
 * In the command history window, enter "csam.command.itemSave"
 * Enter a filepath to export the file to in the dialog.
 * If the item is a mesh, you should get an error.  Otherwise, a
 * file with the selected item's ident should be written to the
 * location you specified.
 */

#include <lxu_command.hpp>
#include <lxu_format.hpp>
#include <lxu_io.hpp>
#include <lxu_package.hpp>

#define SRVNAME_SAVER "csam.saver.item"
#define SRVNAME_CMD   "csam.command.itemSave"

namespace csam_itemSaver
{

    /*
     * ----------------------------------------------------------------
     * Our saver derives from the template saver class, specialized for items.
     * Our command will create an instance of this class, call the verify and
     * save functions we implement below, and then delete the instance.
     */
    class CSaver : public CLxSaverT<CLxUser_Item>
    {
    public:
        CLxLineFormat line_out;

        /*
         * The save function we're overridding takes an object
         * of the template type we specify (an item, here), a
         * filepath to save to, and a monitor to show progress to
         * the user.
         */
        void save(CLxUser_Item& itm, const char* filename, CLxUser_Monitor& mon) override
        {
            /*
             * The actual functionality of the saver is simple.
             * We read the ident of the given item and write it out.
             */

            CLxUser_Item item(itm);
            const char*  ident;

            line_out.ff_Open(filename);
            item.Ident(&ident);
            line_out.lf_Output(ident);
            lx_err::check(!line_out.ff_HasError());
        }

        /*
         * The verify function is passed the same item we'll
         * get in the save function, and we can check it to see if we
         * should display warnings or abort the save all together.
         * To test that our verify function works correctly,
         * we have just arbitrarily decided to fail if the saved item
         * happens to be a mesh.  We set the message object's code to
         * LXe_FAILED, and the command will be expected to read the code
         * and respond accordingly.
         */
        void verify(CLxUser_Item& itm, CLxUser_Message& msg) override
        {
            if (itm.IsA(LXi_CIT_MESH))
            {
                msg.SetCode(LXe_FAILED);
            }
            else
            {
                msg.SetCode(LXe_OK);
            }
        }
    };

    /*
     * Because modo has no native Item based savers,
     * we need to write our own command to call the saver.
     * We'll just take a filename as an argument, read
     * the first item the user has selected, and then create
     * a new instance of our Saver class.  We'll call the
     * verify function of the saver to check if saving should
     * go ahead, and if so we call the saver's save
     * function.  We'll pass both the selected
     * item and make sure to destroy the saver instance when we're
     * done.
     */
    class CCommand : public CLxCommand
    {
    public:
        /*
         * The command's setup_args function adds an argument for filepath.
         */
        void setup_args(CLxAttributeDesc& desc) override
        {
            desc.add("filename", LXsTYPE_FILEPATH);
        }

        /*
         * To keep things organized, we create a utility function to
         * read the selected item.  This isn't inherited or required
         * for a command, it's just so that the execute function is cleaner.
         */
        void getSelectedItem(CLxUser_Item& itm)
        {
            CLxUser_SelectionService      sSrv;
            CLxUser_ItemPacketTranslation iTrans;
            LXtID4                        selID;
            void*                         pkt;

            iTrans.autoInit();
            selID = sSrv.LookupType(LXsSELTYP_ITEM);
            pkt   = sSrv.Recent(selID);
            iTrans.Item(pkt, itm);
        }

        /*
         * The execute function is inherited from the parent CLxCommand
         * class.  We override it to create an instance of our saver and
         * call the save and verify functions we've created above.
         * We grab the command's associate message object using the "cmd_message"
         * function.  Then we can pass that to our saver's verify function and
         * read the result.  If the result is a failure, we throw a cmd_error, using
         * a string that points to a message table (see config) to define the actual
         * message our user will see.  The command is responsible for creating and
         * deleting the saver object.
         */
        void execute() override
        {
            CSaver*         saver;
            CLxUser_Item    saveItem;
            std::string     filename;
            CLxUser_Monitor mon;
            CLxUser_Message cmdMsg;

            cmdMsg = cmd_message();
            cmd_read_arg("filename", filename);

            /*
             * It would be more realistic to disable the command
             * if no item were selected, but to show a bit more on
             * message tables, we throw a unique error for this case
             * instead.
             */
            getSelectedItem(saveItem);
            if (!saveItem.test())
            {
                cmd_error(LXe_FAILED, "noItem");
            }

            saver = new CSaver();
            saver->verify(saveItem, cmdMsg);
            if (cmdMsg.Code() == LXe_FAILED)
            {
                delete saver;
                cmd_error(LXe_FAILED, "meshFail");
            }
            saver->save(saveItem, filename.c_str(), mon);
            delete saver;
        }
    };

    /*
     * ----------------------------------------------------------------
     * Metaclass
     *
     * The constructors for the Saver and Command metaclasses
     * both require a server name to set.
     */
    static CLxMeta_Saver<CSaver>     save_meta(SRVNAME_SAVER);
    static CLxMeta_Command<CCommand> cmd_meta(SRVNAME_CMD);

    /*
     * ----------------------------------------------------------------
     * Root metaclass
     *
     *	(root)
     *	  |
     *	  +---	saver
     *	  |
     *	  +---	command
     *
     * The saver metaclass needs a class to be set to indicate what type of
     * objects it is meant to save.
     */
    static class CRoot : public CLxMetaRoot
    {
        bool pre_init() override
        {
            save_meta.set_class(LXu_ITEM);

            add(&cmd_meta);
            add(&save_meta);
            return false;
        }
    } root_meta;

};  // namespace csam_itemSaver
