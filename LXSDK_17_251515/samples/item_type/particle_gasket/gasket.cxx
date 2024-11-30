/*
 * GASKET.CPP	Plug-in Particle Generator Item Type
 *
 *	Copyright 0000
 */
#include <lx_action.hpp>
#include <lx_item.hpp>
#include <lx_package.hpp>
#include <lx_particle.hpp>
#include <lx_plugin.hpp>
#include <lx_tableau.hpp>
#include <lx_value.hpp>
#include <lx_vertex.hpp>
#include <lxidef.h>
#include <lxu_attributes.hpp>
#include <lxu_log.hpp>
#include <lxu_math.hpp>
#include <lxvmath.h>

#define SRVNAME_PACKAGE   "gaskettoy"
#define SPNNAME_INSTANCE  "gasket.inst"
#define SPNNAME_GENERATOR "gasket.gen"

/*
 * Class Declarations
 *
 * These have to come before their implementions because they reference each
 * other. Descriptions are attached to the implementations.
 */
class CGasketPackage;

class CGasketGenerator : public CLxImpl_TableauSurface, public CLxDynamicAttributes
{
public:
    static void initialize()
    {
        CLxGenericPolymorph* srv;

        srv = new CLxPolymorph<CGasketGenerator>;
        srv->AddInterface(new CLxIfc_TableauSurface<CGasketGenerator>);
        srv->AddInterface(new CLxIfc_Attributes<CGasketGenerator>);
        lx::AddSpawner(SPNNAME_GENERATOR, srv);
    }

    /*
     * The 'corner' is a simple 3D vector class used to compute the corners of
     * the various primitives.
     */
    class CCorner
    {
    public:
        LXtFVector pos;

        void Set(float x, float y, float z)
        {
            LXx_VSET3(pos, x, y, z);
        }

        void Ave(const CCorner& c1, const CCorner& c2, float w1 = 0.5)
        {
            float w2 = 1.0f - w1;

            for (int i = 0; i < 3; i++)
                pos[i] = c1.pos[i] * w1 + c2.pos[i] * w2;
        }

        void Third(const CCorner& c1, const CCorner& c2)
        {
            Ave(c1, c2, 2 / 3.0f);
        }

        void Xfrm(const CLxUser_Matrix& m)
        {
            LXtVector in, out;

            LXx_VCPY(in, pos);
            m.MultiplyVector(in, out);
            LXx_VCPY(pos, out);
        }
    };

    CLxUser_Matrix w_matrix;
    float          f_iter;
    int            i_type;

    CLxUser_TriangleSoup tri_soup;
    CLxPseudoRandom      rand_seq;
    int                  vrt_size;
    float*               vrt_vec;
    int                  i_pos, i_xfrm, i_id;

    CGasketGenerator();

    unsigned int tsrf_FeatureCount(LXtID4 type) override;
    LxResult     tsrf_FeatureByIndex(LXtID4 type, unsigned int index, const char** name) override;
    LxResult     tsrf_SetVertex(ILxUnknownID vdesc) override;
    LxResult     tsrf_Sample(const LXtTableauBox bbox, float scale, ILxUnknownID trisoup) override;

    void Square9();
    void Square9Gen(const CCorner& cc, const CCorner& c0, const CCorner& c1, const CCorner& c2, const CCorner& c3, float level);

    void Serpinski();
    void SerpinskiGen(const CCorner& cc, const CCorner& c0, const CCorner& c1, const CCorner& c2, float level);

    void Tetrahedron();
    void TetrahedronGen(const CCorner& cc, const CCorner& c0, const CCorner& c1, const CCorner& c2, const CCorner& c3, float level);

    void Point(const CCorner& parent, const CCorner& center, float level);
};

class CGasketInstance : public CLxImpl_PackageInstance, public CLxImpl_ParticleItem, public CLxImpl_TableauSource
{
public:
    static void initialize()
    {
        CLxGenericPolymorph* srv;

        srv = new CLxPolymorph<CGasketInstance>;
        srv->AddInterface(new CLxIfc_PackageInstance<CGasketInstance>);
        srv->AddInterface(new CLxIfc_ParticleItem<CGasketInstance>);
        srv->AddInterface(new CLxIfc_TableauSource<CGasketInstance>);
        lx::AddSpawner(SPNNAME_INSTANCE, srv);
    }

    CLxSpawner<CGasketGenerator> gen_spawn;
    CLxUser_Item                 m_item;

    CGasketInstance() : gen_spawn(SPNNAME_GENERATOR)
    {
    }

    LxResult pins_Initialize(ILxUnknownID item, ILxUnknownID super) override;
    void     pins_Cleanup(void) override;

    LxResult prti_Prepare(ILxUnknownID eval, unsigned* index) override;
    LxResult prti_Evaluate(ILxUnknownID attr, unsigned index, void** ppvObj) override;

    /*
     * TableauSource interface.
     */
    LxResult tsrc_PreviewUpdate(int chanIndex, int* update) override;
};

class CGasketPackage : public CLxImpl_Package
{
public:
    static LXtTagInfoDesc descInfo[];

    static void initialize()
    {
        CLxGenericPolymorph* srv;

        srv = new CLxPolymorph<CGasketPackage>;
        srv->AddInterface(new CLxIfc_Package<CGasketPackage>);
        srv->AddInterface(new CLxIfc_StaticDesc<CGasketPackage>);
        lx::AddServer(SRVNAME_PACKAGE, srv);
    }

    CLxSpawner<CGasketInstance> inst_spawn;

    CGasketPackage() : inst_spawn(SPNNAME_INSTANCE)
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
 * like the metatype object for the item type.
 *
 * The Gasket is a locator.
 */
LXtTagInfoDesc CGasketPackage::descInfo[] = { { LXsPKG_SUPERTYPE, LXsITYPE_LOCATOR }, { nullptr } };

/*
 * The package has a set of standard channels with default values. These
 * are setup at the start using the AddChannel interface.
 *
 * The gasket has a type and an iteration count (which needs a low default,
 * since these can get huge really quickly).
 */
#define Cs_TYPE  "type"
#define Cs_LEVEL "level"

#define TYPEi_SQUAREHOLE  0
#define TYPEi_SQUAREFLAKE 1
#define TYPEi_SERPINSKI   2
#define TYPEi_TETRAHEDRON 3

static LXtTextValueHint hint_typechan[] = {
    { TYPEi_SQUAREHOLE, "squareHole" },   { TYPEi_SQUAREFLAKE, "squareFlake" }, { TYPEi_SERPINSKI, "serpinski" },
    { TYPEi_TETRAHEDRON, "tetrahedron" }, { -1, "=gasket_toy-type" },           { 0, nullptr },
};

LxResult CGasketPackage::pkg_SetupChannels(ILxUnknownID addChan)
{
    CLxUser_AddChannel ac(addChan);

    ac.NewChannel(Cs_TYPE, LXsTYPE_INTEGER);
    ac.SetDefault(0.0, TYPEi_SERPINSKI);
    ac.SetHint(hint_typechan);

    ac.NewChannel(Cs_LEVEL, LXsTYPE_FLOAT);
    ac.SetDefault(3.0, 3);

    return LXe_OK;
}

/*
 * TestInterface() is required so that nexus knows what interfaces instance
 * of this package support. Necessary to prevent query loops.
 */
LxResult CGasketPackage::pkg_TestInterface(const LXtGUID* guid)
{
    return inst_spawn.TestInterfaceRC(guid);
}

/*
 * Attach is called to create a new instance of this item. The returned
 * object implements a specific item of this type in the scene.
 */
LxResult CGasketPackage::pkg_Attach(void** ppvObj)
{
    inst_spawn.Alloc(ppvObj);
    return LXe_OK;
}

/*
 * ----------------------------------------------------------------
 * Gasket Item Instance
 *
 * The instance is the implementation of the item, and there will be one
 * allocated for each item in the scene. It can respond to a set of
 * events. Initialization typically stores the item it's attached to.
 */
LxResult CGasketInstance::pins_Initialize(ILxUnknownID item, ILxUnknownID /*super*/)
{
    m_item.set(item);
    return LXe_OK;
}

void CGasketInstance::pins_Cleanup(void)
{
    m_item.clear();
}

/*
 * The particle interface initializes and returns a particle object, which is then
 * used to access particle data. This first method is passed an evaluation object
 * which selects the channels it wants and returns a key index.
 */
LxResult CGasketInstance::prti_Prepare(ILxUnknownID evalObj, unsigned* index)
{
    CLxUser_Evaluation eval(evalObj);

    index[0] = eval.AddChan(m_item, Cs_TYPE);
    eval.AddChan(m_item, Cs_LEVEL);
    eval.AddChan(m_item, LXsICHAN_XFRMCORE_WORLDMATRIX);

    return LXe_OK;
}

/*
 * Once prepared, the second method is called to actually create the object and
 * initialize its state from the channel values.
 */
LxResult CGasketInstance::prti_Evaluate(ILxUnknownID attr, unsigned index, void** ppvObj)
{
    CLxUser_Attributes ai(attr);
    CGasketGenerator*  gen = gen_spawn.Alloc(ppvObj);

    gen->i_type = ai.Int(index + 0);
    gen->f_iter = static_cast<float>(ai.Float(index + 1));
    ai.ObjectRO(index + 2, gen->w_matrix);

    return LXe_OK;
}

LxResult CGasketInstance::tsrc_PreviewUpdate(int /*chanIndex*/, int* update)
{
    *update = LXfTBLX_PREVIEW_UPDATE_GEOMETRY;

    return LXe_OK;
}

/*
 * ----------------------------------------------------------------
 * Gasket Particle Object
 *
 * The particle object can be enumerated by a client to get the data for
 * all particles. It also can preset an attributes interface to allow the
 * client to set hints, in this case the random seed.
 */
CGasketGenerator::CGasketGenerator()
{
    dyna_Add(LXsPARTICLEATTR_SEED, "integer");
    attr_SetInt(0, 137);
}

/*
 * Like tableau surfaces, particle sources have features. These are the
 * properties of each particle as a vector of floats. We provide the standard
 * 3 particle features: position, transform, and ID.
 */
unsigned int CGasketGenerator::tsrf_FeatureCount(LXtID4 type)
{
    return (type == LXiTBLX_PARTICLES ? 3 : 0);
}

LxResult CGasketGenerator::tsrf_FeatureByIndex(LXtID4 type, unsigned int index, const char** name)
{
    if (type != LXiTBLX_PARTICLES || index > 2)
        return LXe_OUTOFBOUNDS;

    switch (index)
    {
        case 0:
            name[0] = LXsTBLX_PARTICLE_POS;
            break;
        case 1:
            name[0] = LXsTBLX_PARTICLE_XFRM;
            break;
        case 2:
            name[0] = LXsTBLX_PARTICLE_ID;
            break;
    }
    return LXe_OK;
}

/*
 * Given a tableau vertex allocated by the client, we need to determine the
 * features they want and their offsets into the vertex vector.
 */
LxResult CGasketGenerator::tsrf_SetVertex(ILxUnknownID vdesc)
{
    CLxUser_TableauVertex vrx(vdesc);
    unsigned              offset;

    i_pos  = -1;
    i_xfrm = -1;
    i_id   = -1;

    vrt_size = vrx.Size();
    if (vrt_size == 0)
        return LXe_OK;

    if (LXx_OK(vrx.Lookup(LXiTBLX_PARTICLES, LXsTBLX_PARTICLE_POS, &offset)))
        i_pos = offset;

    if (LXx_OK(vrx.Lookup(LXiTBLX_PARTICLES, LXsTBLX_PARTICLE_XFRM, &offset)))
        i_xfrm = offset;

    if (LXx_OK(vrx.Lookup(LXiTBLX_PARTICLES, LXsTBLX_PARTICLE_ID, &offset)))
        i_id = offset;

    return LXe_OK;
}

/*
 * Sampling walks the particles. This will be done by traversing the fractal
 * geometry recursively.
 */
LxResult CGasketGenerator::tsrf_Sample(const LXtTableauBox /*bbox*/, float /*scale*/, ILxUnknownID trisoup)
{
    double   s{};
    int      i;
    LxResult result;

    /*
     * Allocate the vertex vector and init to zeros. We only need one
     * since points are sampled sequentially.
     */
    vrt_vec = new float[vrt_size];
    if (!vrt_vec)
        return LXe_OUTOFMEMORY;

    for (i = 0; i < vrt_size; i++)
        vrt_vec[i] = 0.0;

    /*
     * Set the transform scale based on the number of iterations. The
     * rigid transform comes from the middle 3x3 matrix of the world transform.
     */
    switch (i_type)
    {
        case TYPEi_SQUAREHOLE:
        case TYPEi_SQUAREFLAKE:
            s = 3.0;
            break;

        case TYPEi_SERPINSKI:
        case TYPEi_TETRAHEDRON:
            s = 2.0;
            break;
    }

    s = pow(1.0 / s, static_cast<double>(f_iter));

    if (i_xfrm >= 0)
    {
        if (0)
        {  // world space
            LXtMatrix4 m;
            int        j;

            w_matrix.Get4(m);

            for (j = 0; j < 9; j++)
                vrt_vec[i_xfrm + j] = static_cast<float>(s * m[j % 3][j / 3]);
        }
        else
        {
            float sf            = static_cast<float>(s);
            vrt_vec[i_xfrm + 0] = sf;
            vrt_vec[i_xfrm + 4] = sf;
            vrt_vec[i_xfrm + 8] = sf;
        }
    }

    /*
     * Init random seed from the attribute the client may have set.
     */
    int seed;
    attr_GetInt(0, &seed);
    rand_seq.seed(seed);

    result = LXe_OK;
    try
    {
        /*
         * Init the triangle soup.
         */
        tri_soup.set(trisoup);
        tri_soup.Segment(1, LXiTBLX_SEG_POINT);

        /*
         * Set initial square to a fixed shape transformed by the
         * gasket item's world transform and then recurse. Any errors
         * lower down will be caught by the try block.
         */
        switch (i_type)
        {
            case TYPEi_SQUAREHOLE:
            case TYPEi_SQUAREFLAKE:
                Square9();
                break;

            case TYPEi_SERPINSKI:
                Serpinski();
                break;

            case TYPEi_TETRAHEDRON:
                Tetrahedron();
                break;
        }
    }
    catch (LxResult rc)
    {
        result = rc;
    }

    delete[] vrt_vec;
    return result;
}

/*
 * Square gasket root: makes a flat square.
 */
void CGasketGenerator::Square9()
{
    CCorner cc, c0, c1, c2, c3;

    cc.Set(0.0, 0.0, 0.0);
    c0.Set(-1.0, 0.0, -1.0);
    c1.Set(+1.0, 0.0, -1.0);
    c2.Set(+1.0, 0.0, +1.0);
    c3.Set(-1.0, 0.0, +1.0);

    if (0)
    {  // world space
        cc.Xfrm(w_matrix);
        c0.Xfrm(w_matrix);
        c1.Xfrm(w_matrix);
        c2.Xfrm(w_matrix);
        c3.Xfrm(w_matrix);
    }

    Square9Gen(cc, c0, c1, c2, c3, f_iter);
}

/*
 * Square gasket recursion will split the square into 9 sub-squares. The hole
 * mode is an 8-fold multiplier that leaves out the middle, and the flake
 * mode is a 5-fold multiplier that leaves out the corners.
 */
void CGasketGenerator::Square9Gen(const CCorner& cc, const CCorner& c0, const CCorner& c1, const CCorner& c2, const CCorner& c3, float level)
{
    CCorner a03, a12, cen;

    a03.Ave(c0, c3);
    a12.Ave(c1, c2);
    cen.Ave(a03, a12);

    if (level <= 1.0)
    {
        Point(cc, cen, level);
        return;
    }

    CCorner c01, c10, c12, c21, c23, c32, c30, c03;
    CCorner c00, c11, c22, c33;

    c01.Third(c0, c1);
    c10.Third(c1, c0);
    c12.Third(c1, c2);
    c21.Third(c2, c1);
    c23.Third(c2, c3);
    c32.Third(c3, c2);
    c30.Third(c3, c0);
    c03.Third(c0, c3);

    c00.Third(c03, c12);
    c11.Third(c12, c03);
    c22.Third(c21, c30);
    c33.Third(c30, c21);

    level -= 1.0;
    Square9Gen(cen, c0, c01, c00, c03, level);
    Square9Gen(cen, c10, c1, c12, c11, level);
    Square9Gen(cen, c21, c2, c23, c22, level);
    Square9Gen(cen, c30, c33, c32, c3, level);
    if (i_type == TYPEi_SQUAREHOLE)
    {
        Square9Gen(cen, c01, c10, c11, c00, level);
        Square9Gen(cen, c11, c12, c21, c22, level);
        Square9Gen(cen, c33, c22, c23, c32, level);
        Square9Gen(cen, c03, c00, c33, c30, level);
    }
    else
    {
        Square9Gen(cen, c00, c11, c22, c33, level);
    }
}

/*
 * Serpinski starts with an equilateral triangle. Each level splits the
 * edges evenly and recurses on the three corner triangles.
 */
void CGasketGenerator::Serpinski()
{
    CCorner cc, c0, c1, c2;
    float   a;

    a = sqrt(3.0f) / 2.0f;
    cc.Set(0.0, 0.0, 0.0);
    c0.Set(1.0, 0.0, 0.0);
    c1.Set(-0.5, 0.0, a);
    c2.Set(-0.5, 0.0, -a);

    if (0)
    {  // world space
        cc.Xfrm(w_matrix);
        c0.Xfrm(w_matrix);
        c1.Xfrm(w_matrix);
        c2.Xfrm(w_matrix);
    }

    SerpinskiGen(cc, c0, c1, c2, f_iter);
}

void CGasketGenerator::SerpinskiGen(const CCorner& cc, const CCorner& c0, const CCorner& c1, const CCorner& c2, float level)
{
    CCorner c01, cen;

    c01.Ave(c0, c1);
    cen.Ave(c01, c2, 2 / 3.0f);

    if (level <= 1.0)
    {
        Point(cc, cen, level);
        return;
    }

    CCorner c12, c20;

    c12.Ave(c1, c2);
    c20.Ave(c2, c0);

    level -= 1.0;
    SerpinskiGen(cen, c0, c01, c20, level);
    SerpinskiGen(cen, c1, c12, c01, level);
    SerpinskiGen(cen, c2, c20, c12, level);
}

/*
 * Tetrahedron is four points evenly spaced. Each edge is split and the four
 * corners become half-sized tetrahedrons.
 */
void CGasketGenerator::Tetrahedron()
{
    // corners of a tetrahedron
    CCorner cc, c0, c1, c2, c3;
    float   s3;

    s3 = sqrt(3.0f);

    cc.Set(0.0, 0.0, 0.0);
    c0.Set(0.0, s3 - 1 / s3, 0.0);
    c1.Set(-1.0, -1 / s3, 0.0);
    c2.Set(1.0, -1 / s3, 0.0);
    c3.Set(0.0, 0.0, 2 * sqrt(2 / 3.0f));

    if (0)
    {  // world space
        cc.Xfrm(w_matrix);
        c0.Xfrm(w_matrix);
        c1.Xfrm(w_matrix);
        c2.Xfrm(w_matrix);
        c3.Xfrm(w_matrix);
    }

    TetrahedronGen(cc, c0, c1, c2, c3, f_iter);
}

void CGasketGenerator::TetrahedronGen(const CCorner& cc, const CCorner& c0, const CCorner& c1, const CCorner& c2, const CCorner& c3, float level)
{
    CCorner c01, c23, cen;

    c01.Ave(c0, c1);
    c23.Ave(c2, c3);
    cen.Ave(c01, c23);

    if (level <= 1.0)
    {
        Point(cc, cen, level);
        return;
    }

    CCorner c02, c03, c12, c13;

    c02.Ave(c0, c2);
    c03.Ave(c0, c3);
    c12.Ave(c1, c2);
    c13.Ave(c1, c3);

    level -= 1.0;
    TetrahedronGen(cen, c0, c01, c02, c03, level);
    TetrahedronGen(cen, c1, c01, c12, c13, level);
    TetrahedronGen(cen, c2, c02, c12, c23, level);
    TetrahedronGen(cen, c3, c03, c13, c23, level);
}

/*
 * To send a particle to the client we set the position and ID, if requested
 * (the transform is fixed in this example). Then we generate a single point.
 * This will interpolate between the parent center position and the real center
 * position for intermediate levels.
 */
void CGasketGenerator::Point(const CCorner& parent, const CCorner& center, float level)
{
    CCorner      cc;
    unsigned int index;
    LxResult     rc;

    cc.Ave(center, parent, level);

    if (i_pos >= 0)
    {
        vrt_vec[i_pos + 0] = cc.pos[0];
        vrt_vec[i_pos + 1] = cc.pos[1];
        vrt_vec[i_pos + 2] = cc.pos[2];
    }

    if (i_id >= 0)
        vrt_vec[i_id] = rand_seq.uniform();

    rc = tri_soup.Vertex(vrt_vec, &index);
    if (LXx_FAIL(rc))
        throw(rc);

    rc = tri_soup.Polygon(index, 0, 0);
    if (LXx_FAIL(rc))
        throw(rc);
}

/*
 * Export package server to define a new item type.
 */
void initialize()
{
    CGasketPackage ::initialize();
    CGasketGenerator ::initialize();
    CGasketInstance ::initialize();
}
