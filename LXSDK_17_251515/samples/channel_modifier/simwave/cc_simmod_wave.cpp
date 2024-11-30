/*
 * MODO SDK SAMPLE
 *
 * Simulation Modifier server
 * ==========================
 *
 *	Copyright 0000
 *
 * This implements a simple simulation modifier.
 *
 * CLASSES USED:
 *
 *		CLxChannels
 *		CLxEvalModifier
 *		CLxSimulation
 *
 * TESTING:
 *
 * 1. Add csam.simmod.wave modifier to schematic.
 * 2. Connect output to something visible in GL, like object position.
 * 3. Run the live simulation.
 * 4. In channel list, toggle trigger channel from False to True.
 *
 * Each time the trigger trips the output will execute a damped sin wave.
 * Change the period to make the wave faster or slower.
 */
#include <lxidef.h>
#include <lxu_modifier.hpp>
#include <lxu_package.hpp>



#define SRVNAME_ITEMTYPE "csam.simmod.wave"
#define SRVNAME_MODIFIER "csam.simmod.wave"

#define CHANs_TRIGGER "trigger"
#define CHANs_OUTPUT  "output"
#define CHANs_PERIOD  "period"

namespace SimmodWave
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
        bool   cv_trigger;
        double cv_period;

        /*
         * init_chan() is called on initialization to define the channels for
         * this item using a CLxAttributeDesc object.
         *
         * OUTPUT is added without an LXfECHAN state. Both OUTPUT and TRIGGER are
         * suggested, meaning they will be added automatically to the node when
         * the item is added to schematic. INPUT will have a connection on the
         * left, and OUTPUT will have one on the right only.
         */
        void init_chan(CLxAttributeDesc& desc) override
        {
            CChannels* chan = 0;

            desc.add(CHANs_OUTPUT, LXsTYPE_PERCENT);
            desc.chan_flags(LXfUIHINTCHAN_OUTPUT_ONLY | LXfUIHINTCHAN_SUGGESTED);

            desc.add_channel(CHANs_TRIGGER, LXsTYPE_BOOLEAN, false, &chan->cv_trigger, LXfECHAN_READ);
            desc.chan_flags(LXfUIHINTCHAN_INPUT_ONLY | LXfUIHINTCHAN_SUGGESTED);

            desc.add_channel(CHANs_PERIOD, LXsTYPE_TIME, 1.0, &chan->cv_period, LXfECHAN_READ);
        }
    };

    static CLxMeta_Channels<CChannels> chan_meta;

    /*
     * ----------------------------------------------------------------
     * This modifier derives from the normal eval modifier, and also from
     * CLxSimulation. The latter adds the methods necessary for a state that
     * evolves over time.
     */
    class CModifier : public CLxEvalModifier, public CLxSimulation
    {
    public:
        CChannels cur_chan;
        double    cur_time, cur_amp;

        /*
         * bind() is called to add channels to the modifier.
         *
         * We add the OUTPUT channel as custom channel zero.
         */
        void bind(CLxUser_Item& item, unsigned index) override
        {
            mod_add_chan(item, CHANs_OUTPUT, LXfECHAN_WRITE);
        }

        /*
         * init_sim() is called to initialize the simulation state at the
         * start of the simulation. Channels can be read as needed.
         */
        void init_sim(double time, double sample) override
        {
            cur_chan.cv_trigger = false;
            cur_time            = 0.0;
            cur_amp             = 0.0;
        }

        /*
         * step() is called to advance the simulation by the interval. Output
         * channels are written for the current time.
         *
         * When the trigger channel changes from false to true we restart the
         * waveform.
         */
        void step(double dt) override
        {
            bool   start, prev;
            double output;

            prev = cur_chan.cv_trigger;
            mod_read_attr(&cur_chan);

            start = cur_chan.cv_trigger && !prev;
            if (start)
            {
                cur_amp  = 1.0;
                cur_time = 0.0;
            }

            output = cur_amp * sin(LXx_TWOPI * cur_time / cur_chan.cv_period) * exp(-cur_time / cur_chan.cv_period);
            cur_time += dt;

            mod_cust_write(0, output);
        }
    };

    /*
     * ----------------------------------------------------------------
     * Metaclass
     *
     * We use default package behaviors for our item type.
     */
    static CLxMeta_Package<CLxPackage>     pkg_meta(SRVNAME_ITEMTYPE);
    static CLxMeta_EvalModifier<CModifier> mod_meta(SRVNAME_MODIFIER);

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
     * Add simulation to the modifier, and set the item type to appear in the
     * 'add' list for schematic.
     */
    static class CRoot : public CLxMetaRoot
    {
        bool pre_init() override
        {
            pkg_meta.set_supertype(LXsITYPE_ITEMMODIFY);

            mod_meta.set_simulation();

            add(&chan_meta);
            add(&pkg_meta);
            add(&mod_meta);

            return false;
        }

    } root_meta;

};  // namespace SimmodWave
