/*
 * MODO SDK SAMPLE
 *
 * Command server
 * ==============
 *
 *	Copyright 0000
 *
 * This implements a Command server with one computed popup argument.
 *
 * CLASSES USED:
 *
 *		CLxCommand
 *		CLxMeta_Command
 *
 * TESTING:
 *
 * Execute the command "psam.command.arg" from the command history.
 * A dialog will open with the arguments
 */
#include <lx_log.hpp>
#include <lxu_command.hpp>
#include <lxu_format.hpp>
#include <string>

#define SRVNAME_COMMAND "csam.command.arg"

namespace CommandArg
{

    /*
     * ----------------------------------------------------------------
     * The command defines a single arg with value hints.
     */
    class CCommand : public CLxCommand
    {
    public:
        int arg_encoded;

        /*
         * setup_args() is called on initialization to define the arguments
         * using a CLxAttributeDesc object.
         *
         * We add our one int argument, and add the customization object.
         */
        void setup_args(CLxAttributeDesc& desc) override
        {
            static LXtTextValueHint arg_hints[] = { -1, "down", 0, "unchanged", 1, "up", 0, 0 };

            CCommand* cmd = 0;

            desc.add("encodedInt", LXsTYPE_INTEGER);
            desc.struct_offset(&cmd->arg_encoded);
            desc.set_hint(arg_hints);
        }

        /*
         * execute() is called to perform the operation of the command.
         *
         * We read the arguments (setting arg_pop), and dump to debug output.
         */
        void execute() override
        {
            cmd_read_args(this);

            CLxUser_LogService lS;
            lS.DebugOut(LXi_DBLOG_NORMAL, SRVNAME_COMMAND " got %d\n", arg_encoded);
        }
    };

    /*
     * ----------------------------------------------------------------
     * Metaclass
     *
     * The command name is passed to the metaclass constructor.
     */
    static CLxMeta_Command<CCommand> cmd_meta(SRVNAME_COMMAND);

    /*
     * ----------------------------------------------------------------
     * Root metaclass
     *
     *	(root)
     *	  |
     *	  +---	command
     *
     * We'll make this a UI command since it doesn't alter any scene state.
     */
    static class CRoot : public CLxMetaRoot
    {
        bool pre_init() override
        {
            cmd_meta.set_type_UI();
            add(&cmd_meta);
            return false;
        }
    } root_meta;

};  // namespace CommandArg
