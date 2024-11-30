/*
 * LINEAR.CPP	Linear Force
 *
 *	Copyright 0000
 */
#include <cmath>
#include <lx_force.hpp>
#include <lx_handles.hpp>
#include <lx_item.hpp>
#include <lx_package.hpp>
#include <lx_plugin.hpp>
#include <lx_vmodel.hpp>
#include <lxidef.h>
#include <lxu_math.hpp>
#include <lxu_modifier.hpp>
#include <lxu_simd.hpp>
#include <string>

namespace Linear_Force
{

#define SRVNAME_PACKAGE  "force.linear"
#define SRVNAME_MODIFIER "force.linear"
#define SPNNAME_INSTANCE "linear.inst"
#define SPNNAME_FORCE    "linear.filt"

    /*
     * Class Declarations
     *
     * These have to come before their implementions because they reference each
     * other. Descriptions are attached to the implementations.
     */
    class CForce : public CLxImpl_Force
    {
    public:
        static void initialize()
        {
            CLxGenericPolymorph* srv;

            srv = new CLxPolymorph<CForce>;
            srv->AddInterface(new CLxIfc_Force<CForce>);
            lx::AddSpawner(SPNNAME_FORCE, srv);
        }

        CLxSpawner<CForce> force_spawn;

        CForce() : force_spawn(SPNNAME_FORCE)
        {
        }

        LXtFVector force_vector;

        unsigned force_Flags() override;
        LxResult force_Force(const LXtFVector, LXtFVector) override;
        LxResult force_ForceRun(const float**, const float**, const float*, float**, unsigned) override;
    };

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

        CLxSpawner<CForce> force_spawn;

        CInstance() : force_spawn(SPNNAME_FORCE)
        {
        }

        CLxUser_Item m_item;

        LxResult pins_Initialize(ILxUnknownID item, ILxUnknownID super) override;
        void     pins_Cleanup(void) override;

        LxResult vitm_Draw(ILxUnknownID itemChanRead, ILxUnknownID viewStrokeDraw, int selectionFlags, const LXtVector itemColor) override;
    };

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
            lx::AddServer(SRVNAME_PACKAGE, srv);
        }

        CLxSpawner<CInstance> inst_spawn;

        CPackage() : inst_spawn(SPNNAME_INSTANCE)
        {
        }

        LxResult pkg_SetupChannels(ILxUnknownID addChan) override;
        LxResult pkg_TestInterface(const LXtGUID* guid) override;
        LxResult pkg_Attach(void** ppvObj) override;
    };

    /*
     * ----------------------------------------------------------------
     * Package Class
     *
     * Packages implement item types, or simple item extensions. They are
     * like the metatype object for the item type. They define the common
     * set of channels for the item type and spawn new instances.
     *
     */

    /*
     * The package has a set of standard channels with default values. These
     * are setup at the start using the AddChannel interface.
     */

    LXtTagInfoDesc CPackage::descInfo[] = { { LXsPKG_SUPERTYPE, LXsITYPE_FORCE }, { nullptr } };

    LxResult CPackage::pkg_SetupChannels(ILxUnknownID /*addChan*/)
    {
        return LXe_OK;
    }

    /*
     * TestInterface() is required so that nexus knows what interfaces instances
     * of this package support. Necessary to prevent query loops.
     */
    LxResult CPackage::pkg_TestInterface(const LXtGUID* guid)
    {
        return inst_spawn.TestInterfaceRC(guid);
    }

    /*
     * Attach is called to create a new instance of this item. The returned
     * object implements a specific item of this type in the scene.
     */
    LxResult CPackage::pkg_Attach(void** ppvObj)
    {
        inst_spawn.Alloc(ppvObj);

        return LXe_OK;
    }

    /*
     * ----------------------------------------------------------------
     * Environment Item Instance
     *
     * The instance is the implementation of the item, and there will be one
     * allocated for each item in the scene. It can respond to a set of
     * events.
     */
    LxResult CInstance::pins_Initialize(ILxUnknownID item, ILxUnknownID /*super*/)
    {
        m_item.set(item);
        return LXe_OK;
    }

    void CInstance::pins_Cleanup(void)
    {
        m_item.clear();
    }

    LxResult CInstance::vitm_Draw(ILxUnknownID itemChanRead, ILxUnknownID viewStrokeDraw, int /*selectionFlags*/, const LXtVector itemColor)
    {
        CLxUser_ChannelRead chan(itemChanRead);
        CLxUser_ShapeDraw   shape(viewStrokeDraw);
        LXtVector           v, vs;
        double              vel;
        double              s;

        s   = chan.FValue(m_item, LXsICHAN_LOCATOR_SIZE);
        vel = 1.0;
        LXx_VSET(v, 0.0);
        LXx_VSET(vs, s * 0.65);

        if (s == 0.0)
            LXx_VSET(vs, 0.65);

        LXx_VCLR(v);
        shape.Arrow(itemColor, v, vel, 1, 0);
        shape.Plane(itemColor, v, vs, 1, 0);

        return LXe_OK;
    }

    /*
     * ----------------------------------------------------------------
     * Linear Force
     */
    unsigned CForce::force_Flags()
    {
        return 0;
    }

    LxResult CForce::force_Force(const LXtFVector /*pos*/, LXtFVector force)
    {
        LXx_VCPY(force, force_vector);
        return LXe_OK;
    }

    LxResult CForce::force_ForceRun(const float** /*pos*/, const float** /*velocity*/, const float* /*mass*/, float** force, unsigned num)
    {
        for (int ii = 0; ii < num; ii++)
            lxsimd::VarraySet(force, force_vector, ii);

        return LXe_OK;
    }

    /*
     * ----------------------------------------------------------------
     * Force Modifier
     *
     * The modifier spawns the filter from the input parameters. The hard work
     * of storing the object in the reference channel is done by the superclass.
     */
    class CModifier : public CLxObjectRefModifierCore
    {
    public:
        static void initialize()
        {
            CLxExport_ItemModifierServer<CLxObjectRefModifier<CModifier>>::Define(SRVNAME_MODIFIER);
        }

        CLxSpawner<CForce> force_spawn;

        CModifier() : force_spawn(SPNNAME_FORCE)
        {
        }

        const char* ItemType() override
        {
            return SRVNAME_PACKAGE;
        }

        const char* Channel() override
        {
            return LXsICHAN_FORCE_FORCE;
        }

        void Attach(CLxUser_Evaluation& eval, ILxUnknownID item) override
        {
            eval.AddChan(item, LXsICHAN_XFRMCORE_WROTMATRIX);
        }

        void Alloc(CLxUser_Evaluation& /*eval*/, CLxUser_Attributes& attr, unsigned index, ILxUnknownID& obj) override
        {
            CForce* force;

            force = force_spawn.Alloc(obj);

            static LXtFVector V = { 0.0, 1.0, 0.0 };

            CLxUser_Matrix mat;
            attr.ObjectRO(index++, mat);
            LXtMatrix rot;
            mat.Get3(rot);

            lx::MatrixMultiply(force->force_vector, rot, V);
        }
    };

    /*
     * Initialize servers and spawners.
     */
    void initialize()
    {
        CForce ::initialize();
        CInstance ::initialize();
        CPackage ::initialize();
        CModifier ::initialize();
    }

};  // namespace Linear_Force

#if defined(SDK_SAMPLES_BUILD)

void initialize()
{
    Linear_Force::initialize();
}

#endif  // #if defined(SDK_SAMPLES_BUILD)
