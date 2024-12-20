/*
 * Plug-in SDK Source: Package Utilities
 *
 * Copyright 0000
 *
 * Provides package utility classes.
 */
#include <lxu_drawover.hpp>
#include <lxu_package.hpp>
#include <map>

/*
 * ------------------------------------------------------
 * Drawing Overrides
 *
 * The client's CLxDrawingOverride object mainly acts to create a list of items
 * to override. It also holds pass-drawing state.
 */
class pv_DrawingOverride
{
public:
    CLxUser_Scene  scene;
    CLxUser_View3D view;

    class cOverride
    {
    public:
        unsigned   flags;
        LXtVector4 ghost, wire;
    };

    std::map<CLxUser_Item, cOverride*> map;
    cOverride*                         current;

    void clear()
    {
        for (auto mit = map.begin(); mit != map.end(); mit++)
            delete mit->second;

        map.clear();
    }
};

CLxDrawingOverride::CLxDrawingOverride()
{
    pv = new pv_DrawingOverride;
}

CLxDrawingOverride::~CLxDrawingOverride()
{
    delete pv;
}

void CLxDrawingOverride::add_item(CLxUser_Item& item, unsigned flags)
{
    pv->current        = new pv_DrawingOverride::cOverride;
    pv->current->flags = flags;

    pv->map[item] = pv->current;
}

void CLxDrawingOverride::set_ghost_color(double r, double g, double b, double a)
{
    pv->current->flags |= LXfDRAWOVER_STYLE_GHOSTING;

    pv->current->ghost[0] = r;
    pv->current->ghost[1] = g;
    pv->current->ghost[2] = b;
    pv->current->ghost[3] = a;
}

void CLxDrawingOverride::set_wireframe_color(double r, double g, double b, double a)
{
    pv->current->flags |= LXfDRAWOVER_STYLE_WIREFRAME;

    pv->current->wire[0] = r;
    pv->current->wire[1] = g;
    pv->current->wire[2] = b;
    pv->current->wire[3] = a;
}

CLxUser_Scene& CLxDrawingOverride::pass_scene()
{
    return pv->scene;
}

CLxUser_View3D& CLxDrawingOverride::pass_view()
{
    return pv->view;
}

/*
 * Pass Drawing Object -- implemented as a subclass of CLxVisitor.
 */
class impl_DrawVisitor : public CLxVisitor
{
public:
    CLxDrawingOverride* dop;

    ~impl_DrawVisitor()
    {
        delete dop;
    }

    bool self_destruct() override
    {
        return true;
    }

    void evaluate() override
    {
        dop->pass_draw();
    }
};

/*
 * DrawOverride implementation. This uses the pv_Meta class to do setup and
 * init the interfaces.
 */
class impl_DrawingOverride;

class pv_Meta_DrawingOverride
{
public:
    CLxMeta_DrawingOverride_Core* core;
    CLxUser_View3DportService     vp_S;
    std::string                   pkg_name;
    unsigned                      flags;

    pv_Meta_DrawingOverride(CLxMeta_DrawingOverride_Core* init)
    {
        core  = init;
        flags = 0;
    }

    void add_interfaces(CLxGenericPolymorph* gp)
    {
        gp->AddInterface(new CLxIfc_DrawingOverride<impl_DrawingOverride>);
    }
};

class impl_DrawingOverride : public CLxImpl_DrawingOverride
{
public:
    pv_Meta_DrawingOverride* mpv;
    CLxDrawingOverride*      dop;

    impl_DrawingOverride(pv_Meta_DrawingOverride* init = nullptr)
    {
        mpv = init;
        dop = mpv->core->new_inst();
    }

    LXxO_DrawingOverride_Flags  // (void)
    {
        return mpv->flags;
    }

    LXxO_DrawingOverride_AffectedItems  // (ILxUnknownID scene, ILxUnknownID collection)
    {
        CLxUser_Scene          sc(scene);
        CLxUser_ItemCollection coll(collection);

        dop->pv->clear();
        dop->style_items(sc);

        for (auto mit = dop->pv->map.begin(); mit != dop->pv->map.end(); mit++)
            lx_err::check(coll.Add(mit->first));

        return LXe_OK;
    }

    LXxO_DrawingOverride_SetItem  // (ILxUnknownID item, unsigned *styles)
    {
        CLxUser_Item key(item);

        auto mit = dop->pv->map.find(key);
        if (mit == dop->pv->map.end())
            throw(LXe_NOTFOUND);

        dop->pv->current = mit->second;
        *styles          = dop->pv->current->flags;
        return LXe_OK;
    }

    LXxO_DrawingOverride_GetColor  // (unsigned style, LXtVector4 rgba)
    {
        if (style == LXfDRAWOVER_STYLE_GHOSTING)
            LXx_V4CPY(rgba, dop->pv->current->ghost);
        else if (style == LXfDRAWOVER_STYLE_WIREFRAME)
            LXx_V4CPY(rgba, dop->pv->current->wire);
        else
            throw(LXe_INVALIDARG);

        return LXe_OK;
    }

    LXxO_DrawingOverride_InitContext  // (void)
    {
        dop->pass_setup();
        return LXe_OK;
    }

    LXxO_DrawingOverride_CleanupContext  // (void)
    {
        dop->pass_cleanup();
    }

    LXxO_DrawingOverride_DrawVisitor  // (ILxUnknownID scene, ILxUnknownID view, void **ppvObj)
    {
        impl_DrawVisitor* vis;

        vis      = new impl_DrawVisitor;
        vis->dop = mpv->core->new_inst();
        lx_err::check(vis->dop->pv->scene.set(scene));
        lx_err::check(vis->dop->pv->view.set(view));

        ppvObj[0] = vis->init_cache();
        return LXe_OK;
    }
};

CLxMeta_DrawingOverride_Core::CLxMeta_DrawingOverride_Core()
{
    m_type   = LXsMETA_INTERFACE;
    cls_guid = &lx::guid_Package;

    mpv = new pv_Meta_DrawingOverride(this);
}

void* CLxMeta_DrawingOverride_Core::alloc()
{
    CLxMeta* m;

    m = find_any(LXsMETA_SERVER, &lx::guid_Package);
    if (m)
        mpv->pkg_name = m->m_name;

    return reinterpret_cast<void*>(new CLxMetagenPolymorph<impl_DrawingOverride, pv_Meta_DrawingOverride>(mpv));
}

void CLxMeta_DrawingOverride_Core::set_flags(unsigned flags)
{
    mpv->flags = flags;
}

void CLxMeta_DrawingOverride_Core::invalidate_style(CLxUser_Scene& scene)
{
    mpv->vp_S.set();
    mpv->vp_S.InvalidateOverrider(scene, mpv->pkg_name.c_str());
}

void CLxMeta_DrawingOverride_Core::invalidate_style(CLxUser_Item& item)
{
    CLxUser_Scene scene;

    scene.from(item);
    invalidate_style(scene);
}
