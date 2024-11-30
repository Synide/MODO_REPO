/*
 * Plug-in SDK Source: Channel Modifier Utilities
 *
 * Copyright 0000
 *
 * Provides channel modifier utility classes.
 */
#include <lxu_chanmod.hpp>

/*
 * ------------------------------------------------------------
 * Channel Modifier Manager (& implicit Operator)
 *
 * Operator is self-contained, with its own instance of the manager.
 */
class meta_Operator : public CLxImpl_ChannelModOperator
{
public:
    CLxChannelModManager* man;

    LXxD_ChannelModOperator_Evaluate
    {
        man->eval();
        return LXe_OK;
    }
};

/*
 * Common data for everything other than the operator includes the channel
 * description and the operator spawner.
 */
class pv_Meta_ChannelModManager
{
public:
    CLxAttributeDesc*               attr_desc;
    CLxMeta_ChannelModManager_Core* m_core;
    CLxPolymorph<meta_Operator>     op_spawn;

    pv_Meta_ChannelModManager()
    {
        op_spawn.AddInterface(new CLxIfc_ChannelModOperator<meta_Operator>);
    }
};

/*
 * The actual manager (sub-interface of Package) defines the channels and
 * allocates the operators. Each operator also gets its own manager instance.
 * Casting types changes pointers, so we get the raw pointer directly.
 */
class meta_ChannelModManager : public CLxImpl_ChannelModManager
{
public:
    pv_Meta_ChannelModManager* pv;

    LXxO_ChannelModManager_Define
    {
        return pv->attr_desc->chanmod_define(cmod);
    }

    LXxO_ChannelModManager_Allocate
    {
        CLxUser_ChannelModSetup setup(cmod);
        meta_Operator*          op;
        void*                   ptr;

        op      = pv->op_spawn.Alloc(ppvObj);
        op->man = pv->m_core->new_inst(&ptr);
        op->man->m_eval.set(setup.GetEvaluation());

        pv->attr_desc->chanmod_bind(cmod, ptr);
        op->man->post_alloc();
        return LXe_OK;
    }
};

/*
 * Manager polymorph.
 *
 * Just passes the core object pointer up to the manager instance.
 */
class meta_ChannelModManagerPolymorph : public CLxPolymorph<meta_ChannelModManager>
{
public:
    pv_Meta_ChannelModManager* pv;

    meta_ChannelModManagerPolymorph(pv_Meta_ChannelModManager* init)
    {
        this->AddInterface(new CLxIfc_ChannelModManager<meta_ChannelModManager>);
        pv = init;
    }

    void* NewObj() override
    {
        meta_ChannelModManager* man;

        man     = new meta_ChannelModManager;
        man->pv = pv;
        return reinterpret_cast<void*>(man);
    }
};

/*
 * Core Methods.
 *
 * Declare self as interface for package. We allocate the spawner for
 * operators and find the channel attributes on alloc.
 */
CLxMeta_ChannelModManager_Core::CLxMeta_ChannelModManager_Core()
{
    m_type   = LXsMETA_INTERFACE;
    cls_guid = &lx::guid_Package;

    pv         = new pv_Meta_ChannelModManager;
    pv->m_core = this;
}

CLxMeta_ChannelModManager_Core::~CLxMeta_ChannelModManager_Core()
{
    delete pv;
}

void* CLxMeta_ChannelModManager_Core::alloc()
{
    CLxMeta* m;

    m = find_any(LXsMETA_ATTRDESC);
    if (m)
        pv->attr_desc = reinterpret_cast<CLxAttributeDesc*>(m->alloc());

    return new meta_ChannelModManagerPolymorph(pv);
}
