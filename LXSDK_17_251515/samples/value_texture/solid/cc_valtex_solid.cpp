/*
 * MODO SDK SAMPLE
 *
 * ValueTexture server
 * ===================
 *
 *	Copyright 0000
 *
 * This implements a Value Texture server that computes a very simple solid
 * texture.
 *
 * CLASSES USED:
 *
 *		CLxChannels
 *		CLxCustomChannelUI
 *		CLxValueTexture
 *		CLxMeta_Channels
 *		CLxMeta_ValueTexture
 *
 * TESTING:
 *
 * Add the texture item and render.
 *
 * This also tests disabled channels. Saturation is disabled when low and high
 * are equal.
 */
#include <cmath>
#include <lxu_shade.hpp>
#include <lxu_vector.hpp>



#define SRVNAME_VALUETEXTURE "csam.valtex.solid"

namespace ValueTextureSolid
{

/*
 * ----------------------------------------------------------------
 * This defines the channel description as well as the structure that
 * contains channel values. Channels are set to read and are enabled
 * for nodal overrides.
 */
#define Cs_SATURATION "saturation"
#define Cs_LOW        "low"
#define Cs_HIGH       "high"

    class CChannels : public CLxChannels
    {
    public:
        double cv_saturation;
        double cv_low;
        double cv_high;

        /*
         * Define a custom channel UI for saturation.
         */
        class cSaturation : public CLxCustomChannelUI
        {
        public:
            /*
             * enabled() is called with the item and channel values of related
             * channels. It can return false and set an optional message if the
             * channel is disabled.
             */
            bool enabled(CLxUser_Item& src, CLxUser_ChannelRead& chan, CLxUser_Message& res) override
            {
                if (chan.FValue(src, Cs_LOW) != chan.FValue(src, Cs_HIGH))
                    return true;

                res.SetMsg("common", 99);
                res.SetArg(1, "This only applies when High and Low are different.");
                return false;
            }
        };

        /*
         * init_chan() is called on initialization to define the channels for
         * this item using a CLxAttributeDesc object.
         */
        void init_chan(CLxAttributeDesc& desc) override
        {
            CChannels* chan = 0;

            desc.add(Cs_SATURATION, LXsTYPE_PERCENT);
            desc.default_val(1.0);
            desc.set_min(0.0);
            desc.struct_offset(&chan->cv_saturation);
            desc.eval_flag(LXfECHAN_READ);
            desc.nodal_input();

            desc.chan_set_custom(new cSaturation);
            desc.chan_add_dependency(Cs_LOW);
            desc.chan_add_dependency(Cs_HIGH);

            desc.add(Cs_LOW, LXsTYPE_PERCENT);
            desc.default_val(0.0);
            desc.struct_offset(&chan->cv_low);
            desc.eval_flag(LXfECHAN_READ);
            desc.nodal_input();

            desc.add(Cs_HIGH, LXsTYPE_PERCENT);
            desc.default_val(0.0);
            desc.struct_offset(&chan->cv_high);
            desc.eval_flag(LXfECHAN_READ);
            desc.nodal_input();
        }
    };

    /*
     * ----------------------------------------------------------------
     * The value texture derives from the common class, and computes the
     * texture at sample locations.
     */
    class CTexture : public CLxValueTexture
    {
    public:
        CChannels tex;

        /*
         * struct_ptr() is called to get a pointer to the CLxChannels struct
         * to receive the channel values for this sample. For channels
         * marked with nodal_input() nodal links are also computed.
         */
        void* struct_ptr() override
        {
            return reinterpret_cast<void*>(&tex);
        }

        /*
         * eval() is called to compute the texture at a single sample. Results
         * are returned through the TextureOutput packet.
         */
        void eval(ILxUnknownID vector, CLxPkt_TextureInput& tInp, CLxPkt_TextureOutput& tOut) override
        {
            CLxFVector rgb;
            double     f;
            int        i;

            for (i = 0; i < 3; i++)
            {
                f      = tInp->tPos[i] - floor(tInp->tPos[i]);
                f      = pow(f, 1.0 / (tex.cv_saturation + 1.0));
                rgb[i] = tex.cv_low + (tex.cv_high - tex.cv_low) * f;
            }

            tOut.Set<float>(rgb);
        }
    };

    /*
     * ----------------------------------------------------------------
     * Metaclass
     *
     * Constructor sets the server name, which is not the same as the item type
     * name. That can be read from the metaclass if needed.
     */
    static CLxMeta_Channels<CChannels>    chan_meta;
    static CLxMeta_ValueTexture<CTexture> vtex_meta(SRVNAME_VALUETEXTURE);

    /*
     * ----------------------------------------------------------------
     * Root metaclass
     *
     *	(root)
     *	  |
     *	  +---	channels
     *	  |
     *	  +---	value texture
     *
     * The value texture metaclass automatically finds the nearby channel metaclass
     * and uses those channels for the texture.
     */
    static class CRoot : public CLxMetaRoot
    {
        bool pre_init() override
        {
            vtex_meta.set_username("Sample: Solid");

            add(&chan_meta);
            add(&vtex_meta);
            return false;
        }
    } root_meta;

};  // namespace ValueTextureSolid
