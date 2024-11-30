//
// C++ wrapper for lxsdk/lxproxy.h.
//
//	Copyright 2024.
//
//
#pragma once

#include <lxproxy.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx
{
    static LXtGUID const guid_SceneContents = {0x89448742, {0xE996, 0x11E1}, {0x89, 0x7D, 0x24, 0xD8, 0x61, 0x88, 0x70, 0x9B}};
    static LXtGUID const guid_ProxyOptions = {0x68ACA4BE, {0xA274, 0x4D04}, {0xA5, 0xC9, 0x85, 0xAB, 0xFA, 0x27, 0xD2, 0xE6}};
} // namespace lx

class CLxLoc_SceneContents : public CLxLocalize<ILxSceneContentsID>
{
public:
    CLxLoc_SceneContents()
    {
        _init();
    }

    CLxLoc_SceneContents(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_SceneContents(CLxLoc_SceneContents const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_SceneContents;
    }

    auto Item(unsigned int type, const char *internal_name, const char *user_name) -> LxResult
    {
        return m_loc[0]->Item(m_loc, type, internal_name, user_name);
    }

    auto SetBBox(double min_X, double min_Y, double min_Z, double max_X, double max_Y, double max_Z) -> LxResult
    {
        return m_loc[0]->SetBBox(m_loc, min_X, min_Y, min_Z, max_X, max_Y, max_Z);
    }

    auto AddLink(unsigned int type, const char *internal_name, const char *user_name) -> LxResult
    {
        return m_loc[0]->AddLink(m_loc, type, internal_name, user_name);
    }

    auto Count(void) -> unsigned int
    {
        return m_loc[0]->Count(m_loc);
    }

    auto InternalName(unsigned int index, char *buf, unsigned len) -> LxResult
    {
        return m_loc[0]->InternalName(m_loc, index, buf, len);
    }

    auto InternalName(unsigned int index, std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->InternalName(m_loc, index, buf, len);
        LXWx_SBUF2
    }

    auto UserName(unsigned int index, char *buf, unsigned len) -> LxResult
    {
        return m_loc[0]->UserName(m_loc, index, buf, len);
    }

    auto UserName(unsigned int index, std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->UserName(m_loc, index, buf, len);
        LXWx_SBUF2
    }

    auto BBox(unsigned int index, LXtBBox *box) -> LxResult
    {
        return m_loc[0]->BBox(m_loc, index, box);
    }

    auto Type(unsigned int index, unsigned int *type) -> LxResult
    {
        return m_loc[0]->Type(m_loc, index, type);
    }

    auto ByInternalName(const char *internal_name, unsigned int *index) -> LxResult
    {
        return m_loc[0]->ByInternalName(m_loc, internal_name, index);
    }

    auto ByUserName(const char *user_name, unsigned int *index) -> LxResult
    {
        return m_loc[0]->ByUserName(m_loc, user_name, index);
    }

    auto Reset(void) -> LxResult
    {
        return m_loc[0]->Reset(m_loc);
    }

    auto LinkCount(unsigned int index) -> unsigned int
    {
        return m_loc[0]->LinkCount(m_loc, index);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_ProxyOptions : public CLxLocalize<ILxProxyOptionsID>
{
public:
    CLxLoc_ProxyOptions()
    {
        _init();
    }

    CLxLoc_ProxyOptions(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_ProxyOptions(CLxLoc_ProxyOptions const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_ProxyOptions;
    }

    auto LoadList(void) -> LxResult
    {
        return m_loc[0]->LoadList(m_loc);
    }

    auto LoadNone(void) -> LxResult
    {
        return m_loc[0]->LoadNone(m_loc);
    }

    auto AddItem(unsigned int type, const char *internal_name, const char *user_name) -> LxResult
    {
        return m_loc[0]->AddItem(m_loc, type, internal_name, user_name);
    }

    auto SetFlags(unsigned int flags) -> LxResult
    {
        return m_loc[0]->SetFlags(m_loc, flags);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
