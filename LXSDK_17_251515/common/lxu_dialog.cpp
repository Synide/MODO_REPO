/*
 * Plug-in SDK Source: Dialog Utilities
 *
 * Copyright 0000
 *
 * Provides dialog utility functions for C++ plug-ins.
 */
#include <lx_message.hpp>
#include <lxu_dialog.hpp>

class pv_FileDialog
{
public:
    unsigned                  base_flags, event_flags;
    const char *              title_table, *title_key;
    const char *              s_cls, *s_context;
    std::string               f_format, f_path;
    std::string*              res_str;
    std::vector<std::string>* res_list;
    bool                      has_format, has_path;

    pv_FileDialog()
    {
        base_flags  = 0;
        event_flags = 0;
        title_table = nullptr;
        title_key   = nullptr;
        s_cls       = nullptr;
        s_context   = nullptr;
        res_str     = nullptr;
        res_list    = nullptr;
        has_format  = false;
        has_path    = false;
    }
};

class impl_FileDialogClient : public CLxImpl_FileDialogClient, public CLxSingletonPolymorph
{
public:
    class pv_FileDialog* pv;

    LXxSINGLETON_METHOD

    impl_FileDialogClient()
    {
        AddInterface(new CLxIfc_FileDialogClient<impl_FileDialogClient>);
    }

    LXxO_FileDialogClient_Flags  // (void)
    {
        return pv->base_flags | pv->event_flags;
    }

    LXxO_FileDialogClient_Title  // (ILxUnknownID message)
    {
        if (!pv->title_table)
            return LXe_NOTIMPL;

        CLxUser_Message title(message);

        if (pv->title_key)
            title.SetMsg(pv->title_table, pv->title_key);
        else
        {
            title.SetMsg("common", 99);
            title.SetArg(1, pv->title_table);
        }
        return LXe_OK;
    }

    LXxO_FileDialogClient_FileClass  // (void)
    {
        return pv->s_cls;
    }

    LXxO_FileDialogClient_ContextString  // (const char **context)
    {
        if (!pv->s_context)
            return LXe_NOTIMPL;

        context[0] = pv->s_context;
        return LXe_OK;
    }

    LXxO_FileDialogClient_FileFormat  // (const char **format)
    {
        if (!pv->has_format)
            return LXe_NOTIMPL;

        format[0] = pv->f_format.c_str();
        return LXe_OK;
    }

    LXxO_FileDialogClient_StartPath  // (const char **filepath)
    {
        if (!pv->has_path)
            return LXe_NOTIMPL;

        filepath[0] = pv->f_path.c_str();
        return LXe_OK;
    }

    LXxO_FileDialogClient_ResultPath  // (const char *filepath)
    {
        if (pv->res_str)
            *pv->res_str = filepath;
        else if (pv->res_list)
        {
            std::string tmp(filepath);
            pv->res_list->push_back(tmp);
        }
        return LXe_OK;
    }

    LXxO_FileDialogClient_ResultFormat  // (const char *format)
    {
        pv->f_format   = format;
        pv->has_format = true;
        return LXe_OK;
    }

    static bool open(pv_FileDialog*);
};

bool impl_FileDialogClient::open(pv_FileDialog* init)
{
    static impl_FileDialogClient impl;
    CLxUser_StdDialogService     dlg_S;
    LxResult                     rc;

    impl.pv = init;
    rc      = dlg_S.FileDialog(impl);

    init->res_str  = nullptr;
    init->res_list = nullptr;
    init->has_path = false;

    if (rc == LXeMSGDIALOG_OK)
        return true;

    if (rc == LXeMSGDIALOG_CANCEL)
        return false;

    throw(rc);
}

CLxFileDialog::CLxFileDialog()
{
    pv = new pv_FileDialog;
}

CLxFileDialog::~CLxFileDialog()
{
    delete pv;
}

void CLxFileDialog::set_title(const char* table, const char* key)
{
    pv->title_table = table;
    pv->title_key   = key;
}

void CLxFileDialog::set_class(const char* cls, const char* context)
{
    pv->s_cls     = cls;
    pv->s_context = context;
}

void CLxFileDialog::set_format(const char* format)
{
    pv->f_format   = format;
    pv->has_format = true;
}

void CLxFileDialog::set_start_path(const char* path)
{
    pv->f_path   = path;
    pv->has_path = true;
}

void CLxFileDialog::no_formats()
{
    pv->base_flags = LXfFILEDIALOG_NOFORMATS;
}

bool CLxFileDialog::load_single(std::string& result, const char* basename)
{
    bool oldpath = pv->has_path;
    bool res;

    if (!pv->has_path && basename)
    {
        pv->f_path   = basename;
        pv->has_path = true;
    }

    pv->event_flags = LXfFILEDIALOG_LOAD;
    pv->res_str     = &result;

    res          = impl_FileDialogClient::open(pv);
    pv->has_path = oldpath;
    return res;
}

bool CLxFileDialog::load_multiple(std::vector<std::string>& list)
{
    pv->event_flags = LXfFILEDIALOG_LOAD | LXfFILEDIALOG_MULTIPLE;
    pv->res_list    = &list;

    return impl_FileDialogClient::open(pv);
}

bool CLxFileDialog::save(std::string& result, bool overwrite)
{
    pv->event_flags = LXfFILEDIALOG_SAVE;
    if (overwrite)
        pv->event_flags |= LXfFILEDIALOG_MULTIPLE;

    pv->res_str = &result;

    return impl_FileDialogClient::open(pv);
}

bool CLxFileDialog::pick_directory(std::string& result)
{
    pv->event_flags = LXfFILEDIALOG_DIRECTORY;
    pv->res_str     = &result;

    return impl_FileDialogClient::open(pv);
}
