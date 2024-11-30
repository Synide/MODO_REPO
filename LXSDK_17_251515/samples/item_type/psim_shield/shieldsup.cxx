/*
 * SHIELDSUP.CPP	Sample Collider
 *
 * This is a particle filter that collides particles with a unit sphere.
 *
 *	Copyright 0000
 */
#include <cmath>
#include <lx_action.hpp>
#include <lx_deform.hpp>
#include <lx_draw.hpp>
#include <lx_envelope.hpp>
#include <lx_filter.hpp>
#include <lx_handles.hpp>
#include <lx_item.hpp>
#include <lx_log.hpp>
#include <lx_package.hpp>
#include <lx_particle.hpp>
#include <lx_plugin.hpp>
#include <lx_schematic.hpp>
#include <lx_server.hpp>
#include <lx_surface.hpp>
#include <lx_tableau.hpp>
#include <lx_value.hpp>
#include <lx_vertex.hpp>
#include <lx_vmodel.hpp>
#include <lxidef.h>
#include <lxu_math.hpp>
#include <lxu_modifier.hpp>
#include <lxu_simd.hpp>
#include <string>
#include <vector>

namespace Sphere_o_Boom
{

#define SRVNAME_ITEMTYPE "sphereOBoom"
#define SRVNAME_MODIFIER "sphereOBoom"
#define SPNNAME_INSTANCE "ball.inst"
#define SPNNAME_FILTER   "ball.filt"

#define Cs_FILTER "filter"

    /*
     * ----------------------------------------------------------------
     * Item Instance
     *
     * The instance is the implementation of the item, and there will be one
     * allocated for each item in the scene. It can respond to a set of
     * events.
     */
    class CInstance : public CLxImpl_PackageInstance, public CLxImpl_ViewItem3D
    {
    public:
        static void initialize()
        {
            CLxGenericPolymorph* srv;

            srv = new CLxPolymorph<CInstance>;
            srv->AddInterface(new CLxIfc_PackageInstance<CInstance>);
            srv->AddInterface(new CLxIfc_ViewItem3D<CInstance>);
            lx::AddSpawner(SPNNAME_INSTANCE, srv);
        }

        CLxUser_Item m_item;

        LXxO_PackageInstance_Initialize
        {
            m_item.set(item);
            return LXe_OK;
        }

        LXxO_ViewItem3D_Draw
        {
            CLxUser_ShapeDraw shape(strokeDraw);
            LXtVector         pos, rad;

            LXx_VCLR(pos);
            LXx_VSET(rad, 1);
            shape.Ellipsoid(itemColor, 1.0, pos, rad, 0);

            return LXe_OK;
        }
    };

    /*
     * ----------------------------------------------------------------
     * Package Class
     *
     * Packages implement item types, or simple item extensions. They are
     * like the metatype object for the item type. They define the common
     * set of channels for the item type and spawn new instances. This is
     * our Mandelbrot item type, and is a subtype of video clip meaning an
     * image that may change over time.
     */
    class CPackage : public CLxImpl_Package
    {
    public:
        static LXtTagInfoDesc descInfo[];

        static void initialize()
        {
            CLxGenericPolymorph* srv;

            srv = new CLxPolymorph<CPackage>;
            srv->AddInterface(new CLxIfc_Package<CPackage>);
            srv->AddInterface(new CLxIfc_StaticDesc<CPackage>);
            lx::AddServer(SRVNAME_ITEMTYPE, srv);
        }

        CLxSpawner<CInstance> inst_spawn;

        CPackage() : inst_spawn(SPNNAME_INSTANCE)
        {
        }

        LXxO_Package_SetupChannels
        {
            CLxUser_AddChannel ac(addChan);

            ac.NewChannel(Cs_FILTER, LXsTYPE_OBJREF);

            return LXe_OK;
        }

        LXxO_Package_TestInterface
        {
            return inst_spawn.TestInterfaceRC(guid);
        }

        LXxO_Package_Attach
        {
            inst_spawn.Alloc(ppvObj);
            return LXe_OK;
        }
    };

    LXtTagInfoDesc CPackage::descInfo[] = { { LXsPKG_SUPERTYPE, LXsITYPE_LOCATOR }, { LXsPKG_PFILT_CHANNEL, Cs_FILTER }, { nullptr } };

    /*
     * ----------------------------------------------------------------
     * Simulation Channels
     *
     * This object holds the channel values we want to track to control the simulation.
     * In this case it's just the position of the item.
     */
    class CSimChannels : public CLxRefCounted
    {
    public:
        LXtFVector pos;

        static void Attach(CLxUser_Evaluation& eval, ILxUnknownID item)
        {
            eval.AddChan(item, LXsICHAN_XFRMCORE_WORLDMATRIX);
        }

        void Read(CLxUser_Attributes& attr, unsigned index)
        {
            CLxUser_Matrix mat;
            LXtVector      off;

            attr.ObjectRO(index++, mat);
            mat.GetOffset(off);
            LXx_VCPY(pos, off);
        }
    };

    /*
     * ----------------------------------------------------------------
     * Particle Filter
     *
     * The particle filter is placed into the simulation stack where it can
     * manipulate the eval frame.
     */
    class CParticleFilter : public CLxImpl_ParticleFilter
    {
    public:
        static void initialize()
        {
            CLxGenericPolymorph* srv;

            srv = new CLxPolymorph<CParticleFilter>;
            srv->AddInterface(new CLxIfc_ParticleFilter<CParticleFilter>);
            lx::AddSpawner(SPNNAME_FILTER, srv);
        }

        CLxSpawner<CParticleFilter> filt_spawn;

        CParticleFilter() : filt_spawn(SPNNAME_FILTER)
        {
        }

        /*
         * Operate on the whole frame in the post-integration stage. This is the
         * right place to kill particles so they never appear in forbidden locations.
         */
        LXxO_ParticleFilter_Flags
        {
            return LXiPFILT_PARTICLE | LXfPFILT_POSTSTAGE;
        }

        /*
         * We give the caller a peek at our vertex description, created on the
         * fly. We need positions and velocites, which are always there, and
         * the collision channel to write to.
         */
        CLxUser_TableauVertex v_desc;
        unsigned              off_pos, off_vel, off_pps, off_col;

        LXxO_ParticleFilter_Vertex
        {
            if (!v_desc.test())
            {
                CLxUser_TableauService srv;

                srv.NewVertex(v_desc);
                v_desc.NewFeature(LXiTBLX_PARTICLES, LXsTBLX_PARTICLE_POS);
                v_desc.NewFeature(LXiTBLX_PARTICLES, LXsTBLX_PARTICLE_VEL);
                v_desc.NewFeature(LXiTBLX_PARTICLES, LXsTBLX_PARTICLE_PPREV);
                v_desc.NewFeature(LXiTBLX_COLLISION, LXsTBLX_COLLISION_VAL);
                off_pos = 0;
                off_vel = 3;
                off_pps = 6;
                off_col = 9;
            }
            return v_desc.m_loc;
        }

        /*
         * At the start of the simulation we grab the particle frame so we don't
         * have to keep querying it.
         */
        CLxUser_ParticleEvalFrame p_frame;

        LXxO_ParticleFilter_Initialize
        {
            p_frame.set(frame);
            return LXe_OK;
        }

        /*
         * At each timestep we get the duration of the interval, plus another
         * filter evaluated at the start of the interval. By casting it to one
         * of our own types, we can acquire a pointer to the channel state.
         */
        CLxHolder<CSimChannels> c_eval, c_sim;
        double                  d_T;

        LXxO_ParticleFilter_Step
        {
            CParticleFilter* eval;

            eval = filt_spawn.Cast(other);
            c_sim.set(eval->c_eval);

            d_T = dt;
            return LXe_OK;
        }

        /*
         * We're given the final position of the particle after integration and
         * the previous position. If both positions are on the same side of the
         * unit sphere we do nothing. This isn't completely correct since we
         * should be taking the motion of the sphere into account as well.
         *
         * If they have crossed we just set the particle back to the previous
         * position and reflect the velocity around the normal. Finally we set
         * the collision feature to 1.
         */
        LXxO_ParticleFilter_Particle
        {
            LXtFVector p0, p1, vel, n0, n1;
            double     r0, r1, d;

            LXx_VCPY(vel, vertex + off_vel);
            LXx_VCPY(p0, vertex + off_pps);
            LXx_VCPY(p1, vertex + off_pos);

            LXx_VSUB3(n0, p0, c_sim->pos);
            LXx_VSUB3(n1, p1, c_sim->pos);

            r0 = LXx_VLEN(n0);
            r1 = LXx_VLEN(n1);

            if ((r0 > 1.0) ^ !(r1 > 1.0))
                return LXe_OK;

            LXx_VSCL(n0, 1.0 / r0);
            d = LXx_VDOT(n0, vel);
            LXx_VADDS(vel, n0, d * -2.0);
            LXx_VSCL(vel, 0.9f);

            LXx_VCPY(vertex + off_pos, p0);
            LXx_VCPY(vertex + off_vel, vel);
            vertex[off_col] = 1.0;
            return LXe_OK;
        }
    };

    /*
     * ----------------------------------------------------------------
     * Filter Modifier
     *
     * The modifier spawns the filter from the input parameters. The object
     * is stored in the reference channel.
     */
    class CModifierElement : public CLxItemModifierElement
    {
    public:
        CLxSpawner<CParticleFilter> filt_spawn;

        CModifierElement() : filt_spawn(SPNNAME_FILTER)
        {
        }

        void Attach(CLxUser_Evaluation& eval, ILxUnknownID item)
        {
            eval.AddChan(item, Cs_FILTER, LXfECHAN_WRITE);
            CSimChannels::Attach(eval, item);
        }

        void Eval(CLxUser_Evaluation& /*eval*/, CLxUser_Attributes& attr) override
        {
            CParticleFilter*       filt;
            CLxUser_ValueReference ref;
            ILxUnknownID           obj;

            filt = filt_spawn.Alloc(obj);

            filt->c_eval.alloc();
            filt->c_eval->Read(attr, 1);

            attr.ObjectRW(0, ref);
            ref.TakeObject(obj);
        }
    };

    class CModifier : public CLxItemModifierServer
    {
    public:
        static void initialize()
        {
            CLxExport_ItemModifierServer<CModifier>::Define(SRVNAME_MODIFIER);
        }

        const char* ItemType() override
        {
            return SRVNAME_ITEMTYPE;
        }

        CLxItemModifierElement* Alloc(CLxUser_Evaluation& eval, ILxUnknownID item) override
        {
            CModifierElement* elt;

            elt = new CModifierElement;
            elt->Attach(eval, item);
            return elt;
        }
    };

    /*
     * Initialize servers and spawners.
     */
    void initialize()
    {
        CParticleFilter ::initialize();
        CInstance ::initialize();
        CPackage ::initialize();
        CModifier ::initialize();
    }

};  // namespace Sphere_o_Boom

void initialize()
{
    Sphere_o_Boom ::initialize();
}
