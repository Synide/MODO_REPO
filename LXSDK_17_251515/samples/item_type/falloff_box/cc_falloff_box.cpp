/*
 * MODO SDK SAMPLE
 *
 * Falloff server
 * ==============
 *
 *	Copyright 0000
 *
 * This implements a simple falloff item type.
 *
 * CLASSES USED:
 *
 *		CLxChannels
 *		CLxFalloff
 *		CLxViewItem3D
 *		CLxEvalModifier,
 *		CLxTypeEvaluation<>
 *
 * TESTING:
 *
 * 1. Create a subdivided plane, add transform effector and move it up.
 * 2. Add csam.falloff.box as a falloff on the effector.
 *    Only points in the box will be moved up.
 * 3. Move the falloff around to test the transform.
 * 4. Change the 'distance' channel to alter the falloff weight.
 */
#include <cmath>
#include <lxidef.h>
#include <lxu_deform.hpp>
#include <lxu_matrix.hpp>
#include <lxu_modifier.hpp>
#include <lxu_package.hpp>

#define SRVNAME_ITEMTYPE "csam.falloff.box"
#define SRVNAME_MODIFIER "csam.falloff.box"

#define CHANs_DISTANCE "distance"

namespace FalloffBox
{

    /*
     * ----------------------------------------------------------------
     * Our CLxChannels subclass allows us to add channels to our falloff object.
     * In this case a single boolean channel. The metaclass is declared here
     * because it's needed later.
     */
    class CChannels : public CLxChannels
    {
    public:
        bool cv_distance;

        /*
         * init_chan() is called on initialization to define the channels for
         * this item using a CLxAttributeDesc object.
         */
        void init_chan(CLxAttributeDesc& desc) override
        {
            CChannels* chan = 0;

            desc.add_channel(CHANs_DISTANCE, LXsTYPE_BOOLEAN, false, &chan->cv_distance, LXfECHAN_READ);
        }
    };

    static CLxMeta_Channels<CChannels> chan_meta;

    /*
     * ----------------------------------------------------------------
     * Our falloff is a subclass of the Channels object so that it has the state
     * of the falloff in its member variables. The job of a falloff is mostly to
     * compute a 0-1 float from a position.
     */
    class CFalloff : public CChannels, public CLxFalloff
    {
    public:
        /*
         * weight_local() is called to compute the falloff value for a point
         * in the local coordinates of the falloff item.
         *
         * The box falloff is valid for any point within the unit radius box.
         * Our silly boolean channel just modulates the shape a little.
         */
        float weight_local(const float* pos, const LXtPointID point, const LXtPolygonID polygon) override
        {
            if (fabs(pos[0]) > 1.0 || fabs(pos[1]) > 1.0 || fabs(pos[2]) > 1.0)
                return 0.0;

            if (cv_distance)
                return 1.0 - (fabs(pos[0]) + fabs(pos[1]) + fabs(pos[2])) / 3.0;
            else
                return 1.0;
        }
    };

    /*
     * ----------------------------------------------------------------
     * Subclassing the CLxViewItem3D adds drawing capability to our item type.
     * The metaclass for this modifies the Package metaclass.
     */
    class CViewItem3D : public CLxViewItem3D
    {
    public:
        /*
         * draw() is called to allow the item to draw itself in 3D.
         *
         * We read the channels for this item into a local CChannel (which would
         * be needed if the channels affected the drawing). This falloff just
         * draws a default unit radius box.
         */
        void draw(CLxUser_Item& item, CLxUser_ChannelRead& chan, CLxUser_StrokeDraw& stroke, int selFlags, const CLxVector& color) override
        {
            CChannels fall;
            double    alpha;

            chan_meta->chan_read(chan, item, &fall);

            alpha = (selFlags & LXiSELECTION_SELECTED) ? 1.0 : 0.5;
            stroke.BeginW(LXiSTROKE_BOXES, color, alpha, 2 * alpha);
            stroke.Vertex3(-1.0, -1.0, -1.0, LXiSTROKE_ABSOLUTE);
            stroke.Vertex3(1.0, 1.0, 1.0, LXiSTROKE_ABSOLUTE);
        }
    };

    /*
     * ----------------------------------------------------------------
     * The modifier associated with the falloff reads the channels of the falloff
     * item and creates the falloff object. That's done by creating an EvalModifier
     * metaclass, configured by a TypeEvaluation metaclass for the falloff object.
     */
    class CModifier : public CLxEvalModifier, public CLxTypeEvaluation<CFalloff>
    {
    public:
        /*
         * bind() is called to add channels to the modifier.
         *
         * Channels defined as LXfECHAN_READ in the AttributeDesc will be read
         * automatically. We also need to read the transform channel, so we add
         * that as custom.
         */
        void bind(CLxUser_Item& item, unsigned index) override
        {
            mod_add_chan(item, LXsICHAN_XFRMCORE_WORLDMATRIX);
        }

        /*
         * init_obj() is called to configure the newly allocated object that
         * will be the output of the modifier.
         *
         * We read the normal channel values into the object. The falloff also
         * has an inverse matrix that must be initialized from the channel.
         */
        void init_obj(CLxEvalModifier& com, CFalloff& fall) override
        {
            CLxMatrix4 xfrm;

            com.mod_read_attr((CChannels*) &fall);

            com.mod_cust_val(0, xfrm);
            fall.world_inverse = xfrm.inverse();
        }
    };

    /*
     * ----------------------------------------------------------------
     * Metaclasses
     *
     * For the package we can just use the default CLxPackage implementation.
     * The modifier metaclass creates a server type, which is further configured
     * by the type evaluation. That metaclass template takes the object type, and
     * the channel to receive the computed object.
     */
    static CLxMeta_Package<CLxPackage>     pkg_meta(SRVNAME_ITEMTYPE);
    static CLxMeta_ViewItem3D<CViewItem3D> v3d_meta;

    static CLxMeta_EvalModifier<CModifier>             mod_meta(SRVNAME_MODIFIER);
    static CLxMeta_TypeEvaluation<CModifier, CFalloff> eval_meta(LXsICHAN_FALLOFF_FALLOFF);
    static CLxMeta_Falloff<CFalloff>                   fall_meta;

    /*
     * ----------------------------------------------------------------
     * Root metaclass
     *
     *	(root)
     *	  |
     *	  +---	channels
     *	  |
     *	  +---	package (item type)
     *	  |	  |
     *	  |	  +---	view item 3D
     *	  |
     *	  +---	modifier (item type)
     *		  |
     *		  +---	type evaluation
     *			  |
     *			  +---	falloff
     *
     * The package is set to be a subtype of 'falloff', and the falloff is set to
     * operate in local coordinates.
     */
    static class CRoot : public CLxMetaRoot
    {
        bool pre_init() override
        {
            pkg_meta.set_supertype(LXsITYPE_FALLOFF);
            fall_meta.set_local();

            add(&chan_meta);
            add(&pkg_meta);
            add(&mod_meta);

            pkg_meta.add(&v3d_meta);

            mod_meta.add(&eval_meta);
            eval_meta.add(&fall_meta);
            return false;
        }
    } root_meta;

};  // namespace FalloffBox
