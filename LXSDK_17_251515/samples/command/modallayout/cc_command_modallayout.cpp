/*
 * MODO SDK SAMPLE
 *
 * Modal Dialog Command
 * ==============
 *
 *	Copyright 0000
 *
 * This implements a Command that launches a modal
 * dialog layout using layout.window.  It writes the
 * user's choice out to the dblog.
 *
 * CLASSES USED:
 *
 *		CLxCommand
 *		CLxMeta_Command
 *
 * TESTING:
 *
 * Execute the command "csam.command.modalLayout" from the command history.
 * Choose an option in the modal dialog and check the dblog to confirm
 * the correct choice was registered.
 */

#include <cstdio>
#include <lx_log.hpp>
#include <lx_stddialog.hpp>
#include <lxu_command.hpp>

#define SRVNAME_CMD "csam.command.modalLayout"

namespace csam_commands_modalDialog
{

    /*
     * ----------------------------------------------------------------
     * The command will launch a modal yesNoAll dialog, then output the
     * choice to the dblog.
     */
    class CModalCommand : public CLxCommand
    {
    public:
        /*
         * The return codes are integers, so we'll create
         * a translation table to make the db output readable.
         */

        std::map<LxResult, const char*> msgLookup;

        CModalCommand()
        {
            msgLookup[LXeMSGDIALOG_YESTOALL] = "Yes To All";
            msgLookup[LXeMSGDIALOG_NOTOALL]  = "No To All";
            msgLookup[LXeMSGDIALOG_YES]      = "Yes";
            msgLookup[LXeMSGDIALOG_NO]       = "No";
            msgLookup[LXeMSGDIALOG_CANCEL]   = "Cancel";
        }

        /*
         * We need to retrive the message object from the layout.window
         * command after it fires to read the return code.  So we'll
         * create a new command object from the command string, execute it
         * and then we'll be able to read the code that is set after execution.
         */
        void execute() override
        {
            CLxUser_CommandService cSrv;
            CLxUser_Command        cmd;
            CLxUser_Message        msg;
            std::string            cmdString;
            unsigned               flags;
            int                    qIdx;
            LxResult               resCode;

            cmdString = "layout.window ItemListDialog";
            cSrv.NewCommandFromString(cmd, cmdString.c_str(), flags, qIdx);
            cmd.Execute(0);
            cmd.Message(msg);
            resCode = msg.Code();

            CLxUser_LogService lS;
            lS.DebugOut(LXi_DBLOG_NORMAL, SRVNAME_CMD ":\tUser Pressed \"%s\"\n", msgLookup[resCode]);
        }
    };

    /*
     * ----------------------------------------------------------------
     * Metaclass
     *
     * The command name is passed to the metaclass constructor.
     */
    static CLxMeta_Command<CModalCommand> cmd_meta(SRVNAME_CMD);

    /*
     * ----------------------------------------------------------------
     * Root metaclass
     *
     *	(root)
     *	  |
     *	  +---	command
     *
     * The user could alter selection within the dialog, so we need to
     * make this a model command.
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

};  // namespace csam_commands_modalDialog
