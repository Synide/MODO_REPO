/*
 * MODO SDK SAMPLE
 *
 * Schematic Modifier Example
 * ======================
 *
 *	Copyright 0000
 *
 * This example implements an item type with a default
 * schematic connection.  The connected item's channel
 * count is read and a channel on our implemented item
 * is updated with that channel count.
 *
 * CLASSES USED:
 *
 *
 *		CLxPackage
 *		CLxMeta_Package
 *		CLxChannels
 *		CLxMeta_Channels<>
 *		CLxMeta_SchematicConnection<>
 *		CLxEvalModifier
 *		CLxMeta_EvalModifier<>
 *
 *
 * TESTING:
 *
 *	Create a new csam.schema.modItem item and add it to the schematic.
 *	The created item should be called "Graph Test Item" in the scene.
 *	Bring the camera or another item into the schematic and connect it
 *	to the Graph Test Item's schematic input.  Select the Graph Test Item
 *	and look in the channels list.  At the bottom, you should see the
 *	channelCount channel set to some non-zero number.  Disconnect the
 *	schematic connection and mouse over the channels list again, and the
 *	channelCount should reset to 0.
 */

#include <cmath>
#include <lxidef.h>
#include <lxu_modifier.hpp>
#include <lxu_package.hpp>
#include <lxu_schematic.hpp>

/*
 * We pre-define names for our servers (the registered
 * objects modo will need to load as plugins) as well
 * as a name for the string channel we'll write the
 * connected item's channel count to.
 */

#define SRVNAME_ITEM       "csam.schema.modItem"
#define SRVNAME_GRAPH      "csam.schema.modGraph"
#define SRVNAME_CONNECTION "csam.schema.modGraph"
#define SRVNAME_EVAL       "csam.schema.modifier"

#define CHAN_CHANCOUNT "channelCount"

namespace csam_schema_modifier
{
    /*
     * ------------------------------------------------------------
     * The Package is the item itself.  Just to show an
     * example of customization, we'll set the synth name.
     * This sets the item's name when it is first created.
     */
    class CPackage : public CLxPackage
    {
    public:
        /*
         * Synth_name gives us a reference to the string
         * which will become the new item's name.  We simply
         * set it equal to whatever we want.
         */
        void synth_name(std::string& name)
        {
            name = "Graph Test Item";
        }
    };

    /*
     * ------------------------------------------------------------
     * The Channels object is what we use to add new
     * channels to our package.  In the root_meta object's
     * definition, we add the package and the channels meta
     * objects both to the meta_root object, which will infer
     * automatically that our Channels object is intended to
     * be a set of channels on our Package object.
     */

    class CChannels : public CLxChannels
    {
    public:
        /*
         * Overridding the init_chan method gives us an
         * attributedesc object, which we use to add channels
         * We're just going to add a single string channel to
         * write to.  Add takes a string to identify the channel,
         * and a string which defines the channel data type.  These
         * should all be defined in lxvalue.h, but you can pass
         * a string directly in if you really need to.
         * eg. desc.add("myChannelName", "integer");
         */
        void init_chan(CLxAttributeDesc& desc)
        {
            desc.add(CHAN_CHANCOUNT, LXsTYPE_INTEGER);
            desc.default_val(0);
        }
    };

    /*
     * ------------------------------------------------------------
     * Eval modifiers aren't actually an item in the scene.
     * Instead, they are more of a service which lets you pick a set
     * of channels or graphs to watch over, and set of channels to edit.
     * When one of the channels or graphs it's watching changes, the
     * modifier can re-evaluate and update any or all of the channels it
     * has been told to edit.  It's sorting of like having hidden links
     * between channels.
     */

    class CEval : public CLxEvalModifier
    {
    public:
        /*
         * When one of our items is created, an instance of this
         * modifier class will be created also.  We'll call that item
         * the "modItem" and store it as part of this modifier.  We
         * also want to keep track of the ident of whatever item is
         * connected to our modItem so that we can determine if we
         * need to re-evaluate later on in the change_test function.
         * Finally, we'll create an int variable to store the index
         * for any channel we want the modifier to edit.
         */
        CLxUser_Item modItem;
        const char*  cachedName;
        unsigned     itemNameChannelIdx;

        /*
         * When the modifier instance is born, the bind function gets called with
         * the item that it was created with.  We can then tell the modifier which
         * channels it needs to watch for changes on and which channels it's going
         * to be writing out to. Here, we're not going to bother watching any
         * channels, since we'll just perform updates based on changes to the
         * schematic connections. We'll allocate one of the channels on our modItem
         * for the modifier to write to, but we could also write to any channel
         * on any item in the scene if we needed.
         *
         * To set a channel to be watched over or to be written to by our modifier,
         * we just call the "mod_add_chan" function with the UserItem the channel
         * belongs to, the string name of the channel, and whether we want to read
         * (watch the channel for changes), write (output a result value into the channel)
         * or both.  We also "set" the class level "modItem" to the user item provided.
         */
        void bind(CLxUser_Item& item, unsigned ident) override
        {
            /*
             * We need to keep track of the order of channels we add
             * here, because accessing their values for read or write
             * later is done by providing the index based on the order
             * the channel was added to the modifier.  We could be
             * really careful about making sure we access channels in the
             * same order in the eval () function as the order we add them
             * here, or we could just store an index at the class level
             * for each Channel and not worry about it.
             */
            unsigned currentIdx = 0;

            modItem.set(item);
            cachedName = "";

            mod_add_chan(item, CHAN_CHANCOUNT, LXfECHAN_WRITE);
            itemNameChannelIdx = currentIdx++;
        }

        /*
         * We'll need to check what item is connected to our modifier item
         * in a couple of different places, so we'll build a utility function
         * to make that easier.  This isn't inherited or required, it just saves
         * us a bit of typing.
         */
        bool current_link(CLxUser_Item& linkedItem)
        {
            CLxUser_ItemGraph graph;
            unsigned          linkCount;

            /*
             * The user class for ItemGraphs lets us get an
             * item graph object directly from an item, by
             * passing the item in and the string name of the
             * graph connection.  Then we simply check if any
             * items are connected into it.  The RevCount gives
             * us connections coming into the input. Then we can
             * get the item connected to that input by using the
             * RevByIndex functino.  Since our schematic connection
             * will only support one item at a time, we know the
             * item we want is at index 0.
             */

            if (modItem.test())
            {
                graph.from(modItem, SRVNAME_GRAPH);
                graph.RevCount(modItem, &linkCount);
                if (linkCount > 0)
                {
                    graph.RevByIndex(modItem, 0, linkedItem);
                    return linkedItem.test();
                }
            }

            return false;
        }

        /*
         * Since we're only watching graphs and not channels, we
         * aren't guaranteed the modifier will re-evaluate when an
         * item is plugged into our schematic connection.  Instead,
         * change_test is called and we have a chance to decide whether
         * a new evaluation is needed. Multiple items of our type could
         * exist in the scene, and we only want to re-evaluate the one
         * that had its connection changed.  So we'll check if the linked
         * item here has changed.
         */
        bool change_test() override
        {
            CLxUser_Item tstItem;
            const char*  tstName = "";

            if (current_link(tstItem))
            {
                tstItem.Ident(&tstName);
                if (strcmp(tstName, cachedName) == 0)
                {
                    return true;
                }
            }
            return false;
        }

        /*
         * Eval is the meat of the eval modifier.  When our modifier
         * is told to evaluate, we'll check for a connected item.
         * If there is an item linked, we'll read its channel count and
         * write that value out to the modItem's channelCount channel.
         */

        void eval() override
        {
            CLxUser_Item linkItem;
            unsigned     chanCount = 0;

            /*
             * If our "current_link" function returns true, it means a
             * valid item is connected and is now set as the item we
             * passed in.  We can then read the channel count to
             * overwrite the initialized 0 value on 'chanCount' to
             * the connected item's actual channel count.
             */

            if (current_link(linkItem))
            {
                linkItem.ChannelCount(&chanCount);
            }
            /*
             * To write to a channel we've told the modifier to write to,
             * we can use the mod_cust_write function.  Since we only have
             * one channel we're writing to, it must be index 0.  But since
             * you might be writing to several channels, this shows a better
             * practice case.
             */

            mod_cust_write(itemNameChannelIdx, (int) chanCount);
        }
    };

    /*
     * ----------------------------------------------------------------
     * Metaclass
     *
     * The Package, SchematicConnection, and EvalModifier metaclasses are
     * all servers that require a server name for the constructor.  We'll
     * pass our customized Channels, Package, and Eval classes into their
     * templated metaclasses.  The SchematicConnection will just use the
     * default CLxSchematicConnection class.  The root_meta object will
     * automatically work out the association between our Package and Channels
     * metaclasses, and the association between our Package and EvalModifier
     * metaclasses, so we don't need to do anything specific there.
     */

    static CLxMeta_Channels<CChannels> chan_meta;
    static CLxMeta_Package<CPackage>   pkg_meta(SRVNAME_ITEM);

    static CLxMeta_SchematicConnection<CLxSchematicConnection> schm_meta(SRVNAME_CONNECTION);

    static CLxMeta_EvalModifier<CEval> eval_meta(SRVNAME_EVAL);

    /*
     * ------------------------------------------------------------
     * Metaclass declaration.
     *
     *	root
     *	 |
     *	 +---	channels
     *	 |
     *	 +---	schematic connection (server)
     *	 |
     *	 +---	package (item type)
     *	 |
     *	 +---	modifier (server)
     *
     *	We set the package's supertype to be a locator so it shows up as an
     *	independent item.  We also add a tag to tell it what graph it contains.
     *	We set the item type of the schematic connection to our Package, and
     *	tell it to use the same graph we've set for the package.  The eval
     *	modifier needs to know it should allow re-evaluation when there are
     *	changes to this graph.  All metaclasses are added to the root meta object.
     */

    static class CRoot : public CLxMetaRoot
    {
        bool pre_init() override
        {
            add(&chan_meta);

            pkg_meta.set_supertype(LXsITYPE_LOCATOR);
            pkg_meta.add_tag(LXsPKG_GRAPHS, SRVNAME_GRAPH);

            schm_meta.set_itemtype(SRVNAME_ITEM);
            schm_meta.set_graph(SRVNAME_GRAPH);

            /*
             * Our eval modifier just needs to know what graph it
             * depends on.  We could add several graphs or different item
             * types here if we needed as well.
             */
            eval_meta.add_dependent_graph(SRVNAME_GRAPH);

            /*
             * Finally we add all our meta constructors
             * for our various objects to this root_meta
             * object, which will register everything for us
             */

            add(&pkg_meta);
            add(&schm_meta);
            add(&eval_meta);
            return false;
        }
    } root_meta;

};  // namespace csam_schema_modifier