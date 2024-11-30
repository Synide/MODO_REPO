/*
 * MODO SDK SAMPLE
 *
 * Time Modifier server
 * ==========================
 *
 *	Copyright 0000
 *
 * This implements a simple modifier that reads the current time as an input.
 *
 * CLASSES USED:
 *
 *		CLxChannels
 *		CLxEvalModifier
 *
 * TESTING:
 *
 * 1. Add csam.mod.time modifier to schematic.
 * 2. With the item selected, view the channels list
 * 3. Scrub in the timeline, and note the "currentTime" channel updates
 *
 */

#include <lxidef.h>
#include <lxu_modifier.hpp>
#include <lxu_package.hpp>

#define SRVNAME_ITEM "csam.mod.time"
#define SRVNAME_EVAL "csam.mod.time"

#define CHANs_TIME "currentTime"

namespace csam_time_modifier
{

    /*
     * ----------------------------------------------------------------
     * The CChannels class both describes the channels for our item in the
     * attribute description object, and serves as a container for specific
     * channel values.
     */
    class CChannels : public CLxChannels
    {
    public:
        double _time;

        /*
         * init_chan() is called on initialization to define the channels for
         * this item using a CLxAttributeDesc object.
         *
         * Calling "eval_time" and reading this CLxChannels object in our evaluation
         * function will cause the modifier to re-evaluate every time the scene time
         * changes.  To also read the time, we create a pointer to this class and give
         * give the eval_time call a reference to the class's _time variable, where the
         * time will be stored.  We also add a double channel to write the time into.
         */
        void init_chan(CLxAttributeDesc& desc)
        {
            CChannels* cc = NULL;

            desc.eval_time(&cc->_time);
            desc.add(CHANs_TIME, LXsTYPE_TIME);
            desc.default_val(0);
            desc.chan_flags(LXfUIHINTCHAN_SUGGESTED | LXfUIHINTCHAN_OUTPUT_ONLY);
        }
    };

    static CLxMeta_Channels<CChannels> chan_meta;

    /*
     * ----------------------------------------------------------------
     * This modifier derives from the normal eval modifier.  We
     * tell it which channels it needs to read or write, and what
     * to do when it evaluates.
     */

    class CEval : public CLxEvalModifier
    {
    public:
        CChannels vals;

        /*
         * bind() is called to add channels to the modifier.
         *
         * We add our time channel for writing.  We don't need
         * to add the scene time as an input here, as that's
         * already done in the CChannels class.
         */
        void bind(CLxUser_Item& item, unsigned ident) override
        {
            mod_add_chan(item, CHANs_TIME, LXfECHAN_WRITE);
        }

        /*
         * In eval, we need to read CChannels object by calling
         * mod_read_attr.  This will then have the up to date
         * scene time stored as its _time variable, which we can
         * write into the modifier's time channel.
         */
        void eval() override
        {
            mod_read_attr(&vals);
            mod_cust_write(0, vals._time);
        }
    };

    /*
     * ----------------------------------------------------------------
     * Metaclass
     *
     * We use default package behaviors for our item type.
     */
    static CLxMeta_Package<CLxPackage> pkg_meta(SRVNAME_ITEM);
    static CLxMeta_EvalModifier<CEval> eval_meta(SRVNAME_EVAL);

    /*
     * ----------------------------------------------------------------
     * Root metaclass
     *
     *	(root)
     *	  |
     *	  +---	channels
     *	  |
     *	  +---	package
     *	  |
     *	  +---	modifier
     *
     * We'll set the supertype of item to be an item modifier,
     * but everything else can be default.  We just need to add
     * the channels, package, and modifier meta objects to the
     * root metaclass.
     */
    static class CRoot : public CLxMetaRoot
    {
        bool pre_init() override
        {
            add(&chan_meta);

            pkg_meta.set_supertype(LXsITYPE_ITEMMODIFY);
            add(&pkg_meta);
            add(&eval_meta);
            return false;
        }
    } root_meta;

};  // namespace csam_time_modifier