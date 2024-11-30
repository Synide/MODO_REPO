/*
 * MODO SDK SAMPLE
 *
 * Command server with filename arguments
 * ======================================
 *
 *	Copyright 0000
 *
 * This implements two Command which demonstrate the two ways to get filename
 * arguments by opening a file dialog.
 *
 * CLASSES USED:
 *
 *		CLxCommand
 *		CLxMeta_Command
 *		CLxFileDialog
 *
 * TESTING:
 *
 * 1. Fire csam.command.fileSingle w/o arguments.
 * 2. Fire csam.command.fileSingle with path argument.
 * 3. Fire csam.command.fileMultiple & select on or more images.
 */
#include <lx_image.hpp>
#include <lx_log.hpp>
#include <lxu_command.hpp>
#include <lxu_dialog.hpp>

#define CMDNAME_FILESINGLE   "csam.command.fileSingle"
#define CMDNAME_FILEMULTIPLE "csam.command.fileMultiple"

#define ARGs_FILENAME "filename"

namespace CommandFilename
{

    /*
     * ------------------------------------------------------------
     * Since we're going to use this in two places, we customize the CLxFileDialog
     * utility class with the common attributes. We'll configure to look for files
     * that match the LXa_IMAGE class, and set the title for this usage.
     *
     * We set the context to one of the command names, although it can be any unique
     * string. This makes it easier for the dialog to get back to the same directory
     * when the user fires it again.
     */
    class CLoadDialog : public CLxFileDialog
    {
    public:
        CLoadDialog(const char* title)
        {
            set_class(LXa_IMAGE, CMDNAME_FILESINGLE);
            set_title(title);
        }
    };

    /*
     * ------------------------------------------------------------
     * This command will have a single filename argument. When fired it will
     * allow the user to browse for a file using a file dialog. The command
     * history will correctly show the filename chosen.
     */
    class CCommandSingle : public CLxCommand
    {
    public:
        std::string arg_filename;
        bool        isset_filename;

        /*
         * setup_args() is called on initialization to define the arguments
         * using a CLxAttributeDesc object.
         *
         * Add the filename argument as type FILEPATH. Set the destination
         * for the value and for the is-set boolean.
         */
        void setup_args(CLxAttributeDesc& desc) override
        {
            CCommandSingle* cmd = 0;

            desc.add(ARGs_FILENAME, LXsTYPE_FILEPATH);
            desc.struct_offset(&cmd->arg_filename);
            desc.isset_offset(&cmd->isset_filename);
        }

        /*
         * interact() will be called if user interaction is OK and after the
         * arguments have been parsed.
         *
         * Check if the filename argument has been set. If not set open the
         * dialog and browse for one. Once we have a filename, set the arg
         * string with it so it will be passed to execution.
         */
        void interact() override
        {
            std::string path;

            cmd_read_args_isset(this);
            if (isset_filename)
                return;

            /*
             * Use the CLxFileDialog helper class to open a dialog to
             * pick a single filename.
             */
            CLoadDialog load("Pick an Image File");

            if (load.load_single(path))
                cmd_set_arg(ARGs_FILENAME, path);
        }

        /*
         * execute() is called to perform the operation of the command.
         *
         * We just print the filename. Note that because the filename argument
         * is required this won't be called unless it's set.
         */
        void execute() override
        {
            cmd_read_args(this);

            CLxUser_LogService lS;
            lS.DebugOut(LXi_DBLOG_NORMAL, CMDNAME_FILESINGLE " path is: %s\n", arg_filename.c_str());
        }
    };

    /*
     * ------------------------------------------------------------
     * This command will allow the user to pick multiple files in the same dialog.
     * The process for this is for this QUIET command to get the list of files from
     * the user, and then fire the FILESINGLE command multiple times.
     */
    class CCommandMultiple : public CLxCommand
    {
    public:
        CLxUser_CommandService cmd_S;

        /*
         * Utility function to call the FILESINGLE command with a path.
         */
        void single_cmd(std::string& path)
        {
            std::string cmd;

            cmd = CMDNAME_FILESINGLE " {" + path + "}";
            lx_err::check(cmd_S.ExecuteArgString(-1, LXiCTAG_NULL, cmd.c_str()));
        }

        /*
         * execute() is called to perform the operation of the command.
         *
         * Get a list of files from the user and fire the single command for
         * each one in a block.
         */
        void execute() override
        {
            /*
             * We require that this command be fired in a state where
             * user interaction is allowed, so we raise an exception if not.
             */
            cmd_interaction_ok(true);

            /*
             * Get a list of file paths from the file dialog.
             */
            CLoadDialog              load("Pick One or More Image Files");
            std::vector<std::string> list;

            if (!load.load_multiple(list))
                return;

            /*
             * Fire the single command multiple times.
             */
            CLxOpenCommandBlock blk("Process Multiple Files", LXfCMDBLOCK_UI);
            for (int i = 0; i < list.size(); i++)
                single_cmd(list[i]);
        }
    };

    /*
     * ------------------------------------------------------------
     * Metaclasses
     *
     * The command name is passed to the metaclass constructor.
     */
    static CLxMeta_Command<CCommandSingle>   cmd_sing_meta(CMDNAME_FILESINGLE);
    static CLxMeta_Command<CCommandMultiple> cmd_mult_meta(CMDNAME_FILEMULTIPLE);

    /*
     * ------------------------------------------------------------
     * Metaclass declaration.
     *
     *	root
     *	 |
     *	 +---	command (single)
     *	 |
     *	 +---	command (multiple)
     *
     * We set the source type of the drop server to items. New instances of the
     * actions are added during init as well.
     */
    static class CRoot : public CLxMetaRoot
    {
        bool pre_init() override
        {
            cmd_sing_meta.set_type_UI();
            cmd_mult_meta.set_type_flags(LXfCMD_UI | LXfCMD_QUIET);

            add(&cmd_sing_meta);
            add(&cmd_mult_meta);
            return false;
        }

    } root_meta;

};  // namespace CommandFilename
