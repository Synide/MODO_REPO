/*
 * MODO SDK SAMPLE
 *
 * SelectionType server
 * ====================
 *
 *	Copyright 0000
 *
 * This implements a selection type that can select integers, and is not
 * undoable. The bulk of this file is a test command.
 *
 * CLASSES USED:
 *
 *		CLxSelectionTypePkt
 *		CLxCommand
 *		CLxMeta_SelectionType
 *		CLxMeta_Command
 *
 * TESTING
 *
 * Use "csam.select.tint" from the command history (or form button) to
 * add, remove, set integers to the selection. 'clear' will clear the
 * selection, 'test' will check that the selection contains a value, and
 * 'list' will list the current selection. Note that 'test' and 'list'
 * are only useful if you set a breakpoint in the debugger.
 *
 * Note that the command dialog also tests argument disable.
 */
#include <lxu_command.hpp>
#include <lxu_select.hpp>
#include <vector>

#define SRVNAME_INTSELTYPE  "csam.intsel"
#define TYPECODE_INTSELTYPE "csaI"

#define SRVNAME_TINTCOMMAND "csam.select.tint"

namespace SelTypeInt
{

    /*
     * ----------------------------------------------------------------
     * The client class for the selection type mainly derives from the template
     * given the packet type, in this case "int". The only override that would
     * be interesting would be a subtype.
     */
    class CIntSelectType : public CLxSelectionTypePkt<int>
    {
    public:
        // int subtype(int *pkt) { return *pkt; }
    };

    /*
     * ----------------------------------------------------------------
     * Metaclass:
     *
     * The selection type metaclass is specialized by the selection type cliet
     * class and the packet type. The names are the server name and the selection
     * ID code as a 4-char string.
     *
     * This is defined here because methods on it are used later.
     */
    static CLxMeta_SelectionType<CIntSelectType, int> stype_meta(SRVNAME_INTSELTYPE, TYPECODE_INTSELTYPE);

    /*
     * ----------------------------------------------------------------
     * Command (test)
     *
     *	select.tint act <value>
     *
     * This test command allows manipulation and read-out of the selection. The
     * required 'act' argument selects an action, and the optional 'value' gives
     * the packet value.
     */
    class CSelectTint : public CLxCommand
    {
    public:
#define ARGs_ACT   "act"
#define ARGs_VALUE "value"

#define ACT_ADD    0
#define ACT_SET    1
#define ACT_REMOVE 2
#define ACT_CLEAR  3
#define ACT_TEST   4
#define ACT_LIST   5

        int arg_act;
        int arg_value;

        /*
         * Customize the UI of the value argument.
         */
        class cArgValue : public CLxCustomArgumentUI
        {
        public:
            /*
             * enabled() is called to test is an argument is enabled. If other
             * argument values make this argument meaningless, return false.
             */
            bool enabled(CLxCommand& cmd)
            {
                int act;

                cmd.cmd_read_arg(ARGs_ACT, act);
                return (act != ACT_CLEAR && act != ACT_LIST);
            }
        };

        /*
         * setup_args() is called on initialization to define the arguments
         * using a CLxAttributeDesc object.
         */
        void setup_args(CLxAttributeDesc& desc) override
        {
            static LXtTextValueHint act_hints[] = { ACT_ADD, "add",    ACT_SET, "set",    ACT_REMOVE, "remove", ACT_CLEAR,
                                                    "clear", ACT_TEST, "test",  ACT_LIST, "list",     -1,       0 };

            CSelectTint* cmd = 0;

            desc.add(ARGs_ACT, LXsTYPE_INTEGER);
            desc.struct_offset(&cmd->arg_act);
            desc.set_hint(act_hints);

            desc.add(ARGs_VALUE, LXsTYPE_INTEGER);
            desc.struct_offset(&cmd->arg_value);
            desc.arg_flag(LXfCMDARG_OPTIONAL);
            desc.arg_set_custom(new cArgValue);
        }

        CLxUser_SelectionService sel_S;
        bool                     test_res;
        std::vector<int>         list_res;

        /*
         * execute() is called to perform the operation of the command.
         */
        void execute() override
        {
            cmd_read_args(this);

            if (arg_act == ACT_ADD)
            {
                stype_meta.select(&arg_value);
            }
            else if (arg_act == ACT_SET)
            {
                stype_meta.select(&arg_value, false);
            }
            else if (arg_act == ACT_REMOVE)
            {
                stype_meta.deselect(&arg_value);
            }
            else if (arg_act == ACT_CLEAR)
            {
                stype_meta.clear();
            }
            else if (arg_act == ACT_TEST)
            {
                LxResult rc;

                rc = sel_S.Test(stype_meta.get_ID4(), &arg_value);
                lx_err::check(rc);

                test_res = (rc == LXe_TRUE);
            }
            else if (arg_act == ACT_LIST)
            {
                int i, n, *pkt;

                n = sel_S.Count(stype_meta.get_ID4());
                lx_err::check(n >= 0);

                list_res.clear();
                for (i = 0; i < n; i++)
                {
                    pkt = (int*) sel_S.ByIndex(stype_meta.get_ID4(), i);
                    lx_err::check(pkt != 0);
                    list_res.push_back(*pkt);
                }
            }
        }
    };

    /*
     * ----------------------------------------------------------------
     * Metaclass:
     *
     * The command name is passed to the command metaclass constructor.
     */
    static CLxMeta_Command<CSelectTint> tintcmd_meta(SRVNAME_TINTCOMMAND);

    /*
     * ----------------------------------------------------------------
     * Root metaclass:
     *
     *	(root)
     *	  |
     *	  +--	selection type
     *	  |
     *	  +--	command
     */
    static class CRoot : public CLxMetaRoot
    {
        bool pre_init() override
        {
            stype_meta.set_username("Test Int Selection");

            tintcmd_meta.set_type_UI();

            add(&stype_meta);
            add(&tintcmd_meta);
            return false;
        }
    } root_meta;

};  // namespace SelTypeInt
