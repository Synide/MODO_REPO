/*
 * Plug-in SDK Header: Common Utility
 *
 * Copyright 0000
 *
 * Drop Server Wrapper
 */

#include <cstdio>
#include <limits>
#include <lx_wrap.hpp>
#include <lxu_drop.hpp>
#include <string>
#include <vector>

/*
 * ----------------------------------------------------------------
 * Drop Metaclass
 */
class impl_Drop_Server;

class drop_Action
{
public:
    CLxDropAction* act{};
    std::string    name;
    unsigned       index{};
    bool           custom{};
    int            cust_base{}, cust_num{};
};

typedef std::vector<drop_Action> ActionList;

/*
 * Private data for the metaclass itself. Everything here is global state for
 * the Drop.
 */
class pv_Meta_Drop
{
public:
    CLxTagList*        tag_list;
    CLxMeta_Drop_Core* m_core;
    CLxDrop*           m_inst;
    const char*        srv_name;
    ActionList         act_list;
    bool               array_src;
    unsigned           i_max;

    pv_Meta_Drop()
    {
        tag_list  = nullptr;
        m_core    = nullptr;
        m_inst    = nullptr;
        srv_name  = nullptr;
        array_src = false;
    }

    ~pv_Meta_Drop()
    {
        for (auto it = act_list.begin(); it != act_list.end(); ++it)
            delete it->act;

        if (m_inst)
            delete m_inst;
    }

    void add_interfaces(CLxGenericPolymorph* gp)
    {
        gp->AddInterface(new CLxIfc_Drop<impl_Drop_Server>);
        gp->AddInterface(new CLxIfc_TagDescription<impl_Drop_Server>);
    }

    std::string action_names()
    {
        std::string str;
        char        buf[32];

        i_max = 0;

        for (auto it = act_list.begin(); it != act_list.end(); ++it)
        {
            if (it->custom)
                it->index = std::numeric_limits<unsigned>::max();
            else
            {
                it->index = i_max++;
                if (str.length())
                    str += " ";

                sprintf(buf, "%d", it->index);
                str += buf;
                str += "@";
                str += it->name;
            }
        }

        return str;
    }

    void init_drop(CLxDrop* drop)
    {
        for (auto it = act_list.begin(); it != act_list.end(); ++it)
            it->act->init_drop(drop);
    }
};

/*
 * Private data for the CLxDrop implementation. This is unique to each
 * Drop instance.
 */
class pv_Drop
{
public:
    pv_Meta_Drop*         mpv;
    CLxUser_AddDropAction add;
    drop_Action*          cur;
    int                   icur;

    pv_Drop()
    {
        mpv = nullptr;
        cur = nullptr;
    }
};

CLxDrop::CLxDrop()
{
    pv = new pv_Drop;
}

CLxDrop::~CLxDrop()
{
    delete pv;
}

/*
 * Custom actions are added more or less directly. We assign them a global
 * index and return a local index.
 */
unsigned CLxDrop::add_custom(const char* name)
{
    pv->add.AddAction(pv->icur++, name);
    return pv->cur->cust_num++;
}

/*
 * Server implementation class
 */
class impl_Drop_Server : public CLxImpl_Drop, public CLxImpl_TagDescription
{
public:
    pv_Meta_Drop*          mpv;
    CLxDrop*               inst;
    CLxUser_MessageService msg_S;

    /*
     * Inialization sets up the arguments from the desc.
     */
    impl_Drop_Server(pv_Meta_Drop* init = nullptr)
    {
        mpv = init;

        if (!mpv->m_inst)
        {
            mpv->m_inst = mpv->m_core->new_inst();
            mpv->init_drop(mpv->m_inst);
        }

        inst = mpv->m_inst;
    }

    LXxO_Drop_Recognize  // (ILxUnknownID source)
    {
        if (inst->recognize_any(source))
            return LXe_OK;

        if (mpv->array_src)
        {
            CLxUser_ValueArray va(source);
            lx_err::check(va.test());

            if (inst->recognize_array(va))
                return LXe_OK;
        }

        return LXe_NOTFOUND;
    }

    LXxO_Drop_ActionList  // (ILxUnknownID source, ILxUnknownID dest, ILxUnknownID addDropAction)
    {
        std::string name;
        bool        enab;

        if (!inst->enabled(dest))
            return LXe_OK;

        inst->pv->add.set(addDropAction);
        inst->pv->icur = mpv->i_max;

        for (auto it = mpv->act_list.begin(); it != mpv->act_list.end(); ++it)
        {
            inst->pv->cur = &(*it);
            it->cust_base = inst->pv->icur;
            it->cust_num  = 0;

            enab = it->act->enabled(dest);
            if (it->custom || !enab)
                continue;

            name.clear();
            it->act->name_str(name);

            if (name.empty())
            {
                CLxUser_Message msg;

                if (msg_S.NewMessage(msg))
                {
                    it->act->name_msg(msg);
                    msg_S.MessageText(msg, name);
                }
            }

            if (name.empty())
            {
                name = "@";
                name += mpv->srv_name;
                name += "@";
                name += it->name;
                name += "@";
            }

            inst->pv->add.AddAction(it->index, name.c_str());
        }

        inst->pv->add.clear();
        inst->pv->cur = nullptr;
        return LXe_OK;
    }

    //	LXxO_Drop_Preview // (ILxUnknownID source, ILxUnknownID dest, int action, ILxUnknownID draw)
    //	{
    //		return LXe_NOTIMPL;
    //	}

    LXxO_Drop_Drop  // (ILxUnknownID source, ILxUnknownID dest, int action)
    {
        for (auto it = mpv->act_list.begin(); it != mpv->act_list.end(); ++it)
        {
            if (it->custom)
            {
                if (action >= it->cust_base && action < it->cust_base + it->cust_num)
                {
                    it->act->exec_custom(action - it->cust_base);
                    return LXe_OK;
                }
            }
            else if (static_cast<unsigned>(action) == it->index)
            {
                it->act->exec();
                return LXe_OK;
            }
        }

        return LXe_NOTFOUND;
    }

    LXxO_TagDescription_Count
    {
        return mpv->tag_list->count();
    }

    LXxO_TagDescription_Describe
    {
        return mpv->tag_list->describe(index, desc);
    }
};

/*
 * Metaclass implementation.
 */
CLxMeta_Drop_Core::CLxMeta_Drop_Core(const char* srvName) : CLxMetaServer(srvName)
{
    cls_guid = &lx::guid_Drop;

    pv           = new pv_Meta_Drop;
    pv->tag_list = &tag_list;
    pv->srv_name = srvName;
    pv->m_core   = this;
}

CLxMeta_Drop_Core::~CLxMeta_Drop_Core()
{
    delete pv;
}

void* CLxMeta_Drop_Core::alloc()
{
    add_tag(LXsDROP_ACTIONNAMES, pv->action_names().c_str());

    return reinterpret_cast<void*>(new CLxMetagenPolymorph<impl_Drop_Server, pv_Meta_Drop>(pv));
}

void CLxMeta_Drop_Core::set_source_type(const char* type)
{
    add_tag(LXsDROP_SOURCETYPE, type);

    std::string t(type);
    pv->array_src = !t.compare(LXsDROPSOURCE_FILES) || !t.compare(LXsDROPSOURCE_FILES_SYNTH) || !t.compare(LXsDROPSOURCE_ITEMS) ||
                    !t.compare(LXsDROPSOURCE_CHANNELS) || !t.compare(LXsDROPSOURCE_COMMANDS) || !t.compare(LXsDROPSOURCE_FORMCONTROLS);
}

void CLxMeta_Drop_Core::add_action(const char* name, CLxDropAction* action, bool custom)
{
    drop_Action proto;

    proto.name   = name;
    proto.act    = action;
    proto.custom = custom;

    pv->act_list.push_back(proto);
}
