//
// C++ wrapper for lxsdk/lxcom.h.
//
//	Copyright 2024.
//
//
#pragma once

#include <lxcom.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx
{
    static LXtGUID const guid_Object = {0x222986AB, {0xFA71, 0x4188}, {0xBF, 0xB3, 0xEE, 0xB3, 0xD5, 0x03, 0xAE, 0x6F}};
    static LXtGUID const guid_GUIDService = {0xB11826F1, {0xA6BC, 0x48B4}, {0x90, 0x9B, 0x5F, 0x6D, 0x01, 0x93, 0x83, 0x27}};
} // namespace lx


class CLxImpl_Object
{
public:
    virtual ~CLxImpl_Object() = default;

    virtual auto obj_Identifier([[maybe_unused]] const char **id) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto obj_InterfaceCount([[maybe_unused]] unsigned int *count) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto obj_InterfaceByIndex([[maybe_unused]] unsigned int index, [[maybe_unused]] const LXtGUID **guid) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual void obj_AddObserver([[maybe_unused]] ILxUnknownID visitor)
    {
    }

    virtual void obj_RemoveObserver([[maybe_unused]] ILxUnknownID visitor)
    {
    }
};

#define LXxD_Object_Identifier LxResult obj_Identifier([[maybe_unused]] const char **id) override
#define LXxO_Object_Identifier LXxD_Object_Identifier
#define LXxC_Object_Identifier(c) LxResult c::obj_Identifier([[maybe_unused]] const char **id)
#define LXxD_Object_InterfaceCount LxResult obj_InterfaceCount([[maybe_unused]] unsigned int *count) override
#define LXxO_Object_InterfaceCount LXxD_Object_InterfaceCount
#define LXxC_Object_InterfaceCount(c) LxResult c::obj_InterfaceCount([[maybe_unused]] unsigned int *count)
#define LXxD_Object_InterfaceByIndex LxResult obj_InterfaceByIndex([[maybe_unused]] unsigned int index, [[maybe_unused]] const LXtGUID **guid) override
#define LXxO_Object_InterfaceByIndex LXxD_Object_InterfaceByIndex
#define LXxC_Object_InterfaceByIndex(c) LxResult c::obj_InterfaceByIndex([[maybe_unused]] unsigned int index, [[maybe_unused]] const LXtGUID **guid)
#define LXxD_Object_AddObserver void obj_AddObserver([[maybe_unused]] ILxUnknownID visitor) override
#define LXxO_Object_AddObserver LXxD_Object_AddObserver
#define LXxC_Object_AddObserver(c) void c::obj_AddObserver([[maybe_unused]] ILxUnknownID visitor)
#define LXxD_Object_RemoveObserver void obj_RemoveObserver([[maybe_unused]] ILxUnknownID visitor) override
#define LXxO_Object_RemoveObserver LXxD_Object_RemoveObserver
#define LXxC_Object_RemoveObserver(c) void c::obj_RemoveObserver([[maybe_unused]] ILxUnknownID visitor)

template <class T>
class CLxIfc_Object: public CLxInterface
{
public:
    CLxIfc_Object()
    {
        vt.Identifier = Identifier;
        vt.InterfaceCount = InterfaceCount;
        vt.InterfaceByIndex = InterfaceByIndex;
        vt.AddObserver = AddObserver;
        vt.RemoveObserver = RemoveObserver;
        vTable = &vt.iunk;
        iid = &lx::guid_Object;
    }

    static auto Identifier(LXtObjectID wcom,const char **id) -> LxResult
    {
        LXCWxINST (CLxImpl_Object, loc);
        try
        {
           return loc->obj_Identifier( id);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto InterfaceCount(LXtObjectID wcom,unsigned int *count) -> LxResult
    {
        LXCWxINST (CLxImpl_Object, loc);
        try
        {
           return loc->obj_InterfaceCount( count);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto InterfaceByIndex(LXtObjectID wcom,unsigned int index,const LXtGUID **guid) -> LxResult
    {
        LXCWxINST (CLxImpl_Object, loc);
        try
        {
           return loc->obj_InterfaceByIndex( index, guid);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto AddObserver(LXtObjectID wcom,LXtObjectID visitor) -> void
    {
        LXCWxINST (CLxImpl_Object, loc);
        loc->obj_AddObserver((ILxUnknownID) visitor);
    }

    static auto RemoveObserver(LXtObjectID wcom,LXtObjectID visitor) -> void
    {
        LXCWxINST (CLxImpl_Object, loc);
        loc->obj_RemoveObserver((ILxUnknownID) visitor);
    }

private:
    ILxObject vt;
};

class CLxLoc_Object : public CLxLocalize<ILxObjectID>
{
public:
    CLxLoc_Object()
    {
        _init();
    }

    CLxLoc_Object(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_Object(CLxLoc_Object const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_Object;
    }

    auto Identifier(const char **id) -> LxResult
    {
        return m_loc[0]->Identifier(m_loc, id);
    }

    auto InterfaceCount(unsigned int *count) -> LxResult
    {
        return m_loc[0]->InterfaceCount(m_loc, count);
    }

    auto InterfaceByIndex(unsigned int index, const LXtGUID **guid) -> LxResult
    {
        return m_loc[0]->InterfaceByIndex(m_loc, index, guid);
    }

    auto AddObserver(ILxUnknownID visitor) -> void
    {
        m_loc[0]->AddObserver(m_loc,(ILxUnknownID) visitor);
    }

    auto RemoveObserver(ILxUnknownID visitor) -> void
    {
        m_loc[0]->RemoveObserver(m_loc,(ILxUnknownID) visitor);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_GUIDService : public CLxLocalizedService
{
public:
    ILxGUIDServiceID m_loc{ nullptr };

public:
    CLxLoc_GUIDService()
    {
        _init();
        set();
    }

    ~CLxLoc_GUIDService() = default;

    void set()
    {
        if (!m_loc)
        {
            m_loc = reinterpret_cast<ILxGUIDServiceID>(lx::GetGlobal(&lx::guid_GUIDService));
        }
    }

    auto Translate(const char *guidStr) -> const LXtGUID *
    {
        return m_loc[0]->Translate(m_loc, guidStr);
    }

    auto GetName(const LXtGUID *guid) -> const char *
    {
        return m_loc[0]->GetName(m_loc, guid);
    }

    auto Compare(const LXtGUID *guid1, const LXtGUID *guid2) -> int
    {
        return m_loc[0]->Compare(m_loc, guid1, guid2);
    }

    auto Fixed(const LXtGUID *guid) -> const LXtGUID *
    {
        return m_loc[0]->Fixed(m_loc, guid);
    }

    auto Class(const LXtGUID *guid) -> const LXtGUID *
    {
        return m_loc[0]->Class(m_loc, guid);
    }

    auto ClassName(const LXtGUID *guid) -> const char *
    {
        return m_loc[0]->ClassName(m_loc, guid);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
