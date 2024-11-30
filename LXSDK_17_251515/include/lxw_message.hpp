//
// C++ wrapper for lxsdk/lxmessage.h.
//
//	Copyright 2024.
//
//
#pragma once

#include <lxmessage.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx
{
    static LXtGUID const guid_MessageService = {0x86A69B5D, {0xACFA, 0x11D9}, {0xB3, 0x8C, 0x00, 0x0A, 0x95, 0x6C, 0x2E, 0x10}};
    static LXtGUID const guid_AutoSaveListener = {0x04f41d4e, {0x7267, 0x430e}, {0x81, 0xf4, 0xa8, 0x98, 0x96, 0xbf, 0x74, 0x6c}};
} // namespace lx

class CLxLoc_MessageService : public CLxLocalizedService
{
public:
    ILxMessageServiceID m_loc{ nullptr };

public:
    CLxLoc_MessageService()
    {
        _init();
        set();
    }

    ~CLxLoc_MessageService() = default;

    void set()
    {
        if (!m_loc)
        {
            m_loc = reinterpret_cast<ILxMessageServiceID>(lx::GetGlobal(&lx::guid_MessageService));
        }
    }

    auto ScriptQuery(void **ppvObj) -> LxResult
    {
        return m_loc[0]->ScriptQuery(m_loc, ppvObj);
    }

    auto ScriptQuery(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->ScriptQuery(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Allocate(void **ppvObj) -> LxResult
    {
        return m_loc[0]->Allocate(m_loc, ppvObj);
    }

    auto Allocate(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Allocate(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Duplicate(ILxUnknownID msg, void **ppvObj) -> LxResult
    {
        return m_loc[0]->Duplicate(m_loc,(ILxUnknownID) msg, ppvObj);
    }

    auto Duplicate(ILxUnknownID msg, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Duplicate(m_loc,(ILxUnknownID) msg, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto MessageText(ILxUnknownID msg, char *buf, unsigned len) -> LxResult
    {
        return m_loc[0]->MessageText(m_loc,(ILxUnknownID) msg, buf, len);
    }

    auto MessageText(ILxUnknownID msg, std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->MessageText(m_loc,(ILxUnknownID) msg, buf, len);
        LXWx_SBUF2
    }

    auto RawText(const char *table, const char *msg, const char **text) -> LxResult
    {
        return m_loc[0]->RawText(m_loc, table, msg, text);
    }

    auto ArgTypeUserName(const char *argType, char *buf, unsigned len) -> LxResult
    {
        return m_loc[0]->ArgTypeUserName(m_loc, argType, buf, len);
    }

    auto ArgTypeUserName(const char *argType, std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->ArgTypeUserName(m_loc, argType, buf, len);
        LXWx_SBUF2
    }

    auto ArgTypeDesc(const char *argType, char *buf, unsigned len) -> LxResult
    {
        return m_loc[0]->ArgTypeDesc(m_loc, argType, buf, len);
    }

    auto ArgTypeDesc(const char *argType, std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->ArgTypeDesc(m_loc, argType, buf, len);
        LXWx_SBUF2
    }

    auto ArgTypeOptionUserName(const char *argType, const char *option, char *buf, unsigned len) -> LxResult
    {
        return m_loc[0]->ArgTypeOptionUserName(m_loc, argType, option, buf, len);
    }

    auto ArgTypeOptionUserName(const char *argType, const char *option, std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->ArgTypeOptionUserName(m_loc, argType, option, buf, len);
        LXWx_SBUF2
    }

    auto ArgTypeOptionDesc(const char *argType, const char *option, char *buf, unsigned len) -> LxResult
    {
        return m_loc[0]->ArgTypeOptionDesc(m_loc, argType, option, buf, len);
    }

    auto ArgTypeOptionDesc(const char *argType, const char *option, std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->ArgTypeOptionDesc(m_loc, argType, option, buf, len);
        LXWx_SBUF2
    }

    auto MessageTextRich(ILxUnknownID msg, char *buf, unsigned len) -> LxResult
    {
        return m_loc[0]->MessageTextRich(m_loc,(ILxUnknownID) msg, buf, len);
    }

    auto MessageTextRich(ILxUnknownID msg, std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->MessageTextRich(m_loc,(ILxUnknownID) msg, buf, len);
        LXWx_SBUF2
    }

    auto RawTextRich(const char *table, const char *msg, const char **text) -> LxResult
    {
        return m_loc[0]->RawTextRich(m_loc, table, msg, text);
    }

    auto StripRichText(const char *string, const char **stripped) -> LxResult
    {
        return m_loc[0]->StripRichText(m_loc, string, stripped);
    }

    auto StringLookup(const char *table, const char *ident, const char **text) -> LxResult
    {
        return m_loc[0]->StringLookup(m_loc, table, ident, text);
    }

    auto ArgTypeOptionIconName(const char *argType, const char *option, char *buf, unsigned len) -> LxResult
    {
        return m_loc[0]->ArgTypeOptionIconName(m_loc, argType, option, buf, len);
    }

    auto ArgTypeOptionIconName(const char *argType, const char *option, std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->ArgTypeOptionIconName(m_loc, argType, option, buf, len);
        LXWx_SBUF2
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_AutoSaveListener
{
public:
    virtual ~CLxImpl_AutoSaveListener() = default;

    virtual auto asl_AutoSaveNow([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_AutoSaveListener_AutoSaveNow LxResult asl_AutoSaveNow() override
#define LXxO_AutoSaveListener_AutoSaveNow LXxD_AutoSaveListener_AutoSaveNow
#define LXxC_AutoSaveListener_AutoSaveNow(c) LxResult c::asl_AutoSaveNow()

template <class T>
class CLxIfc_AutoSaveListener: public CLxInterface
{
public:
    CLxIfc_AutoSaveListener()
    {
        vt.AutoSaveNow = AutoSaveNow;
        vTable = &vt.iunk;
        iid = &lx::guid_AutoSaveListener;
    }

    static auto AutoSaveNow(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_AutoSaveListener, loc);
        try
        {
           return loc->asl_AutoSaveNow();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxAutoSaveListener vt;
};

class CLxLoc_AutoSaveListener : public CLxLocalize<ILxAutoSaveListenerID>
{
public:
    CLxLoc_AutoSaveListener()
    {
        _init();
    }

    CLxLoc_AutoSaveListener(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_AutoSaveListener(CLxLoc_AutoSaveListener const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_AutoSaveListener;
    }

    auto AutoSaveNow(void) -> LxResult
    {
        return m_loc[0]->AutoSaveNow(m_loc);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
