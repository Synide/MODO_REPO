/*
 * MODO SDK SAMPLE
 *
 * Notifier server
 * ===============
 *
 *	Copyright 0000
 *
 * Implements a notifier that trips when global state changes. This is wired
 * up with test commands to prove that it works.
 *
 * CLASSES USED:
 *
 *		CLxNotifier<>
 *		CLxCommand
 *		CLxMeta_Notifier
 *		CLxMeta_Command
 *
 * TESTING:
 *
 * To test, set up a form with the following commands:
 *
 *	csam.queryNote.setValue ?
 *	csam.queryNote.setValue ?
 *	csam.queryNote.subValue 0 ?
 *	csam.queryNote.subValue 1 ?
 *	csam.queryNote.subValue 2 ?
 *
 * The first two commands set a global value to a state from 0 to 2. Changing
 * either one should update the value displated on the other. The last three
 * commands will be disabled unless the global state matches their first
 * argument. Changing the value should update the disable state.
 */
#include <lxu_command.hpp>

#include <cstdio>

#define SRVNAME_NOTIFY_VALUE "csam.queryNote.value"
#define SRVNAME_CMD_SETVALUE "csam.queryNote.setValue"
#define SRVNAME_CMD_SUBVALUE "csam.queryNote.subValue"

namespace NotifyGlobal
{

    /*
     * ----------------------------------------------------------------
     * Global state. Changes to this will trip the Notifier.
     */
    static int currentValue = 0;
    static int subValues[3] = { 1, 2, 3 };

    /*
     * ----------------------------------------------------------------
     * The Notifier needs an event type. Events will be sent when the state changes
     * and need to describe the nature of the event for the purpose of what effects
     * to trigger.
     *
     * Our event is a class that encodes the previous and current values.
     */
    class ValEvent
    {
    public:
        int prev, cur;
    };

    /*
     * ----------------------------------------------------------------
     * The Notifier itself derives from the template for a notifier specialized
     * with the event class. The state of the Notifier is set by an argument string
     * and determines what events the notifier will send, and in what circumstances.
     */
    class CValNotifier : public CLxNotifier<ValEvent>
    {
    public:
        int      match;
        unsigned flags;

        /*
         * parse_args() is called to configure the Notifier. The contents of
         * the argument string are not defined and will need to be described in
         * the documentation for the Notifier.
         *
         * Our string can start with a digit (0,1,2) to trip on a
         * specific global state value, or it can be '*' to match any
         * change. The string can then contain an optional 'd' to change
         * the event from the default VALUE to DISABLE.
         */
        void parse_args(const char* args) override
        {
            if (args[0] == '*')
            {
                match = -1;
                args++;
            }
            else
            {
                match = (args[0] - '0');
                args++;
                if (match < 0 || match > 2)
                    match = -2;
            }

            if (args[0] == 'd')
                flags = LXfCMDNOTIFY_DISABLE;
            else
                flags = LXfCMDNOTIFY_VALUE;
        }

        /*
         * change_flags() is passed an event when a change occurs, and this
         * should be compared to the arguments to determine which notification
         * flags, if any should be returned.
         */
        unsigned change_flags(ValEvent event) override
        {
            if (match == -1 || match == event.prev || match == event.cur)
                return flags;
            else
                return 0;
        }
    };

    /*
     * ----------------------------------------------------------------
     * Metaclass
     *
     * The metaclass is specialized by both the Notifier and the event type,
     * and the notifier name is passed to the constructor.
     *
     * You normally call CLxMeta_Notifier::notify(event) to trigger the notification.
     * In this case we'll customize the class to manage the global state and send
     * notifications on change.
     */
    static class CMetaValNotifier : public CLxMeta_Notifier<CValNotifier, ValEvent>
    {
    public:
        CMetaValNotifier() : CLxMeta_Notifier<CValNotifier, ValEvent>(SRVNAME_NOTIFY_VALUE)
        {
        }

        /*
         * Utility class to both change the state and trip notifiers.
         */
        void set_value(int val)
        {
            ValEvent event;

            val = LXxCLAMP(val, 0, 2);

            event.prev = currentValue;
            event.cur  = val;
            notify(event);

            currentValue = val;
        }

    } notifier_meta;

    /*
     * -----------------------------------------
     * Command (test)
     *
     *	xxx.setValue ?value:int
     *
     * Sets and queries the global state value. All instances of this command
     * have the same notifier to respond to all value changes.
     */
    class CSetVal : public CLxCommand
    {
    public:
        int arg_value;

        /*
         * Customize an argument UI.
         */
        class cArgVal : public CLxCustomArgumentUI
        {
        public:
            /*
             * query() is called to get the current value(s) of an
             * argument. This is done with cmd_add_query() for all
             * relevant values.
             *
             * We only have one global value.
             */
            void query(CLxCommand& cmd) override
            {
                cmd.cmd_add_query(currentValue);
            }
        };

        /*
         * setup_args() is called on initialization to define the arguments
         * using a CLxAttributeDesc object.
         *
         * Add the argument, set it to QUERY, and add the custom UI.
         */
        void setup_args(CLxAttributeDesc& desc) override
        {
            CSetVal* cmd = 0;

            desc.add("value", LXsTYPE_INTEGER);
            desc.struct_offset(&cmd->arg_value);
            desc.arg_flag(LXfCMDARG_QUERY);
            desc.arg_set_custom(new cArgVal);
        }

        /*
         * execute() is called to perform the operation of the command.
         *
         * Set the global value through the notifier meta.
         */
        void execute() override
        {
            cmd_read_args(this);
            notifier_meta.set_value(this->arg_value);
        }
    };

    /*
     * -----------------------------------------
     * Command (test)
     *
     *	xxx.subValue.tint value ?result
     *
     * Sets and queries the sub-value matching the required value argument.
     * The command is disabled unless the global value matches the argument.
     */
    class CSubVal : public CLxCommand
    {
    public:
        int arg_value;
        int arg_res;

        /*
         * Customize an argument UI.
         */
        class cArgRes : public CLxCustomArgumentUI
        {
        public:
            /*
             * query() is called to get the current value(s) of an
             * argument. This is done with cmd_add_query() for all
             * relevant values.
             *
             * Return the sub-value based on the input argument.
             */
            void query(CLxCommand& cmd) override
            {
                CSubVal* sub = reinterpret_cast<CSubVal*>(&cmd);

                cmd.cmd_read_args(sub);
                cmd.cmd_add_query(subValues[sub->arg_value]);
            }
        };

        /*
         * setup_args() is called on initialization to define the arguments
         * using a CLxAttributeDesc object.
         *
         * Add the second argument for query.
         */
        void setup_args(CLxAttributeDesc& desc) override
        {
            CSubVal* cmd = 0;

            desc.add("value", LXsTYPE_INTEGER);
            desc.struct_offset(&cmd->arg_value);

            desc.add("result", LXsTYPE_INTEGER);
            desc.struct_offset(&cmd->arg_res);
            desc.arg_flag(LXfCMDARG_QUERY);
            desc.arg_set_custom(new cArgRes);
        }

        /*
         * notifiers() is called to allow a command to add notifiers. Specifically
         * it can add notifiers that depend on argument values.
         */
        void notifiers() override
        {
            char buf[32];

            /*
             * Each command has a notifier specific to its main value,
             * updating enable state when a matching change occurs.
             */
            cmd_read_args(this);
            sprintf(buf, "%dd", this->arg_value);
            cmd_add_notifier(SRVNAME_NOTIFY_VALUE, buf);
        }

        /*
         * enabled() can return false, and optionally set a message, when the
         * command is disabled.
         *
         * Return true only when the global state matches the argument.
         */
        bool enabled() override
        {
            cmd_read_args(this);
            return this->arg_value == currentValue;
        }

        /*
         * execute() is called to perform the operation of the command.
         */
        void execute() override
        {
            cmd_read_args(this);
            subValues[this->arg_value] = this->arg_res;
        }
    };

    /*
     * Root metaclass:
     *
     *	(root)
     *	  |
     *	  +--	notifier
     *	  |
     *	  +--	command 1
     *	  |
     *	  +--	command 2
     *
     * Commands are set to UI type. The main setval command has a notifier added
     * that doesn't depend on arguments, so it can be done for all command instances.
     */
    static CLxMeta_Command<CSetVal> setval_meta(SRVNAME_CMD_SETVALUE);
    static CLxMeta_Command<CSubVal> subval_meta(SRVNAME_CMD_SUBVALUE);

    static class CRoot : public CLxMetaRoot
    {
        bool pre_init() override
        {
            setval_meta.set_type_UI();
            setval_meta.add_notifier(SRVNAME_NOTIFY_VALUE, "*");

            subval_meta.set_type_UI();

            add(&notifier_meta);
            add(&setval_meta);
            add(&subval_meta);
            return false;
        }
    } root_meta;

};  // namespace NotifyGlobal
