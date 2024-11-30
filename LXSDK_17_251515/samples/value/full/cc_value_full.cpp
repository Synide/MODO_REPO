/*
 * MODO SDK SAMPLE
 *
 * Value server
 * ============
 *
 *	Copyright 0000
 *
 * This implements a Vaver server with all the optional interfaces.
 * The value server is the class being demonstrated in this sample. But there
 * is also a command and an item type to illustrate how to use a custom value
 * in practice.
 *
 * CLASSES USED:
 *
 *		CLxValue
 *		CLxValue_StreamIO
 *		CLxValue_StringConversionNice
 *		CLxPackage
 *		CLxMeta_Value
 *		CLxMeta_CLxPackage
 *
 * TESTING
 *
 * - Add an item of the "csam.value.full" from the item list.
 * - Use the command of the same name in a form or directly in the
 *   command history to edit the custom channel.
 * - Use "csam.value.full ?" to query the global value and the value
 *   on the selected item.
 */
#include <lxu_format.hpp>
#include <lxu_parser.hpp>
#include <lxu_value.hpp>

#include <lxidef.h>
#include <lxu_command.hpp>
#include <lxu_package.hpp>
#include <lxu_select.hpp>

#define SRVNAME_VALUE    "csam.value.full"
#define SRVNAME_COMMAND  "csam.value.full"
#define SRVNAME_ITEMTYPE "csam.value.full"

namespace ValueFull
{

    /*
     * ----------------------------------------------------------------
     * The value derives from the base value class, plus all the optional
     * capability classes.
     *
     * This value type is a rational number, given by a numerator and
     * denominator.
     */
    class CValue : public CLxValue, public CLxValue_StreamIO, public CLxValue_StringConversionNice
    {
    public:
        int num, dem;

        CValue()
        {
            num = 0;
            dem = 1;
        }

        /*
         * Core functionality -- required methods.
         *
         * copy() is called to take another value of the same type and set
         * this value to match.
         */
        void copy(const CLxValue* from) override
        {
            const CValue* v = dynamic_cast<const CValue*>(from);

            num = v->num;
            dem = v->dem;
        }

        /*
         * compare() is called to take another value of the same type and
         * return a difference as an integer on a linear metric. Typically this
         * is done by comparing members one by one and returning the first
         * non-zero difference.
         */
        int compare(const CLxValue* from) override
        {
            const CValue* v = dynamic_cast<const CValue*>(from);
            int           k;

            k = num - v->num;
            if (k)
                return k;

            return dem - v->dem;
        }

        /*
         * Accessors -- all are optional, but strings should be provided to
         * use this value type for command arguments.
         *
         * set_string() is called to sets this value by decoding a string.
         */
        void set_string(const char* val) override
        {
            CLxParseString par(val);
            int            n, d;

            par.PullWhite();
            lx_err::check(par.PullNum(&n));
            par.PullWhite();
            lx_err::check(par.PullExpected('/'));
            par.PullWhite();
            lx_err::check(par.PullNum(&d));

            num = n;
            dem = d;
        }

        /*
         * Utility to get an output string for different separators.
         */
        std::string fmt_string(const char* sep)
        {
            std::string out;

            out = lx::Encode(num);
            out += sep;
            out += lx::Encode(dem);
            return out;
        }

        /*
         * get_string() is called to return a string encoding this value.
         */
        std::string get_string() override
        {
            return fmt_string("/");
        }

        /*
         * This can be accessed somewhat as a number, but none of the core
         * systems will try to do this.
         *
         * set_int() is called to set this value from an int.
         */
        void set_int(int val) override
        {
            num = val;
            dem = 1;
        }

        /*
         * get_float() is called to return this value as a float.
         */
        double get_float() override
        {
            return num / (double) dem;
        }

        /*
         * StringConversionNice -- optional interface allowing for different
         * strings to be visible to user.
         *
         * get_nice() is called to return a string encoding this value. This
         * differs from get_string() (if present) because this is the string
         * presented to users but never stored.
         */
        std::string get_nice() override
        {
            return fmt_string(" / ");
        }

        /*
         * set_nice() is called to set the value by decoding a string. This
         * differs from set_string() (if present) because this is the string
         * entered from users.
         */
        void set_nice(const char* s)
        {
            set_string(s);
        }

        /*
         * StreamIO -- optional interface allowing the value to be saved and
         * loaded to a block stream.
         *
         * save() is called to save the value into a block stream.
         */
        void save(CLxUser_BlockWrite& strm) override
        {
            strm.Write(num);
            strm.Write(dem);
        }

        /*
         * load() is called to load the value from a block stream.
         */
        void load(CLxUser_BlockRead& strm) override
        {
            strm.Read(&num);
            strm.Read(&dem);
        }
    };

    /*
     * ----------------------------------------------------------------
     * Metaclass
     *
     * Constructor sets the server name. This is defined here because methods
     * on it are used below.
     */
    static CLxMeta_Value<CValue> val_meta(SRVNAME_VALUE);

    /*
     * ----------------------------------------------------------------
     * The channels for our sample item type contains a storage channel of the
     * custom value type. This allows it to hold a value and be saved and loaded.
     */
    class CChannels : public CLxChannels
    {
    public:
        CLxUser_Value cv_val;

#define CHANs_VALUE "valueObj"

        /*
         * init_chan() is called on initialization to define the channels for
         * this item using a CLxAttributeDesc object.
         */
        void init_chan(CLxAttributeDesc& desc) override
        {
            CChannels* chan = 0;

            desc.add(CHANs_VALUE, val_meta.type_name());
            desc.struct_offset(&chan->cv_val);
            desc.set_storage();
        }
    };

    /*
     * ----------------------------------------------------------------
     * Utility class finds if one of these items is selected, and has methods
     * for reading and writing the value channel.
     */
    class CSelItem
    {
    public:
        CLxUser_Item item;

        bool find()
        {
            CLxItemSelectionType sel(SRVNAME_ITEMTYPE);

            return sel.GetFirst(item);
        }

        const CValue* in_val()
        {
            CLxUser_ChannelRead read;
            CLxUser_Value       val;

            read.from(item);
            read.Object(item, CHANs_VALUE, val);
            return val_meta.cast(val);
        }

        CValue* out_val()
        {
            CLxUser_ChannelWrite write;
            CLxUser_Value        val;

            write.from(item);
            write.Object(item, CHANs_VALUE, val);
            return val_meta.cast(val);
        }
    };

    /*
     * ----------------------------------------------------------------
     * The command has an argument of the custom value type. We have a global
     * state that gets set and queried using the value type.
     */
    static int g_numerator = 22, g_demoninator = 7;

    class CCommand : public CLxCommand
    {
    public:
        CLxUser_Value arg_val;

        /*
         * Customize our argument value for query.
         */
        class cArgVal : public CLxCustomArgumentUI
        {
        public:
            /*
             * query() is called to get the current value(s) of an
             * argument. This is done with cmd_add_query() for all
             * relevant values.
             *
             * This returns the global first, and then the value from
             * any selected item second.
             */
            void query(CLxCommand& cmd) override
            {
                CLxUser_Value vobj;
                CValue*       val;

                cmd.cmd_add_query(vobj);
                val      = val_meta.cast(vobj);
                val->num = g_numerator;
                val->dem = g_demoninator;

                CSelItem sel;

                if (sel.find())
                {
                    const CValue* v2 = sel.in_val();
                    if (v2)
                    {
                        cmd.cmd_add_query(vobj);
                        val      = val_meta.cast(vobj);
                        val->num = v2->num;
                        val->dem = v2->dem;
                    }
                }
            }
        };

        /*
         * setup_args() is called on initialization to define the arguments
         * using a CLxAttributeDesc object.
         */
        void setup_args(CLxAttributeDesc& desc) override
        {
            CCommand* cmd = 0;

            desc.add("value", val_meta.type_name());
            desc.struct_offset(&cmd->arg_val);
            desc.arg_flag(LXfCMDARG_QUERY);
            desc.arg_set_custom(new cArgVal);
        }

        /*
         * execute() is called to perform the operation of the command.
         */
        void execute() override
        {
            CValue* val;

            cmd_read_args(this);
            val           = val_meta.cast(arg_val);
            g_numerator   = val->num;
            g_demoninator = val->dem;

            CSelItem sel;

            if (sel.find())
            {
                CValue* v2 = sel.out_val();
                v2->num    = val->num;
                v2->dem    = val->dem;
            }
        }
    };

    /*
     * ----------------------------------------------------------------
     * Metaclass
     *
     * Constructor sets the server name.
     */
    static CLxMeta_Channels<CChannels> chan_meta;
    static CLxMeta_Package<CLxPackage> pkg_meta(SRVNAME_ITEMTYPE);
    static CLxMeta_Command<CCommand>   cmd_meta(SRVNAME_COMMAND);

    /*
     * ----------------------------------------------------------------
     * Root metaclass
     *
     *	(root)
     *	  |
     *	  +---	value
     *	  |	  + strings
     *	  |	  + nice_strings
     *	  |	  + streamIO
     *	  |
     *	  +---	package (example)
     *	  |	  |
     *	  |	  +---	channels
     *	  |
     *	  +---	command (example)
     *
     * The value metaclass.
     */
    static class CRoot : public CLxMetaRoot
    {
        bool pre_init() override
        {
            val_meta.add_strings();
            val_meta.add_nice_strings();
            val_meta.add_streamIO();

            pkg_meta.set_supertype(LXsITYPE_LOCATOR);

            cmd_meta.set_type_model();

            add(&val_meta);
            add(&cmd_meta);
            add(&pkg_meta);
            pkg_meta.add(&chan_meta);
            return false;
        }
    } root_meta;

};  // namespace ValueFull
