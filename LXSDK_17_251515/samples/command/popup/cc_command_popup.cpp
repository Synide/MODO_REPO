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
 *		CLxCustomArgumentUI
 *		CLxUIValue
 *
 * TESTING:
 *
 * Execute the command "csam.command.popup" from the command history.
 * A dialog should open with a single popup with three options.
 */
#include <lx_log.hpp>
#include <lxu_command.hpp>
#include <lxu_format.hpp>
#include <string>

#define SRVNAME_COMMAND "csam.command.popup"

namespace CommandPopup
{

    static int how_many = 0;

    /*
     * ----------------------------------------------------------------
     * This class customizes one of the arguments of the command, returning the
     * popup when requested. A new one is allocated each time, allowing them to
     * be dynamic.
     */
    class CCustomArg : public CLxCustomArgumentUI
    {
    public:
        /*
         * uivalue() is called to get a new instance of a class of value
         * customization classes. Return 0 for none.
         *
         * We create a CLxUIValue object and populate it as a popup. The
         * strings contain a dynamic value to coutn how many calls.
         */
        CLxDynamicUIValue* uivalue(CLxCommand& cmd) override
        {
            CLxUIValue* pop;

            pop = new CLxUIValue;

            std::string count("(");
            count += lx::Encode(++how_many) + ")";

            pop->popup_add(("First" + count).c_str());
            pop->popup_add(("Second" + count).c_str());
            pop->popup_add(("Third" + count).c_str());
            return pop;
        }
    };

    /*
     * ----------------------------------------------------------------
     * The command defines a single arg with custom UI object.
     */
    class CCommand : public CLxCommand
    {
    public:
        int arg_pop;

        /*
         * setup_args() is called on initialization to define the arguments
         * using a CLxAttributeDesc object.
         *
         * We add our one int argument, and add the customization object.
         */
        void setup_args(CLxAttributeDesc& desc) override
        {
            CCommand* cmd = 0;

            desc.add("poparg", LXsTYPE_INTEGER);
            desc.struct_offset(&cmd->arg_pop);
            desc.arg_set_custom(new CCustomArg);
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
            lS.DebugOut(LXi_DBLOG_NORMAL, SRVNAME_COMMAND " got %d\n", arg_pop);
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

};  // namespace CommandPopup
