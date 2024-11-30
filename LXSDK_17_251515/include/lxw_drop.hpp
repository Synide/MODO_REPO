//
// C++ wrapper for lxsdk/lxdrop.h.
//
//	Copyright 2024.
//
//
#pragma once

#include <lxdrop.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx
{
    static LXtGUID const guid_Drop = {0xca3c0d04, {0x5ebe, 0x40a7}, {0xbb, 0x1a, 0xd3, 0x84, 0x88, 0xc7, 0x96, 0x7d}};
    static LXtGUID const guid_Drop1 = {0xabea8de3, {0xd821, 0x4437}, {0x88, 0xb3, 0x05, 0xf2, 0x02, 0x76, 0xff, 0xeb}};
    static LXtGUID const guid_AddDropAction = {0x05C3FF8F, {0x5C3C, 0x4463}, {0xAF, 0x6E, 0x43, 0x9C, 0x52, 0x62, 0x1D, 0xCA}};
    static LXtGUID const guid_DropPreviewDefault = {0xf3823495, {0xd23f, 0x448f}, {0xa5, 0xdd, 0x16, 0xa1, 0x76, 0x14, 0x45, 0xa0}};
    static LXtGUID const guid_DropService = {0x44345a07, {0x014c, 0x4deb}, {0xab, 0xa8, 0x8a, 0x31, 0x47, 0xbb, 0xa2, 0x12}};
} // namespace lx

class CLxImpl_Drop
{
public:
    virtual ~CLxImpl_Drop() = default;

    virtual auto drop_Recognize([[maybe_unused]] ILxUnknownID source) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto drop_ActionList([[maybe_unused]] ILxUnknownID source, [[maybe_unused]] ILxUnknownID dest, [[maybe_unused]] ILxUnknownID addDropAction) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto drop_Preview([[maybe_unused]] ILxUnknownID source, [[maybe_unused]] ILxUnknownID dest, [[maybe_unused]] int action, [[maybe_unused]] ILxUnknownID draw) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto drop_Drop([[maybe_unused]] ILxUnknownID source, [[maybe_unused]] ILxUnknownID dest, [[maybe_unused]] int action) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_Drop_Recognize LxResult drop_Recognize([[maybe_unused]] ILxUnknownID source) override
#define LXxO_Drop_Recognize LXxD_Drop_Recognize
#define LXxC_Drop_Recognize(c) LxResult c::drop_Recognize([[maybe_unused]] ILxUnknownID source)
#define LXxD_Drop_ActionList LxResult drop_ActionList([[maybe_unused]] ILxUnknownID source, [[maybe_unused]] ILxUnknownID dest, [[maybe_unused]] ILxUnknownID addDropAction) override
#define LXxO_Drop_ActionList LXxD_Drop_ActionList
#define LXxC_Drop_ActionList(c) LxResult c::drop_ActionList([[maybe_unused]] ILxUnknownID source, [[maybe_unused]] ILxUnknownID dest, [[maybe_unused]] ILxUnknownID addDropAction)
#define LXxD_Drop_Preview LxResult drop_Preview([[maybe_unused]] ILxUnknownID source, [[maybe_unused]] ILxUnknownID dest, [[maybe_unused]] int action, [[maybe_unused]] ILxUnknownID draw) override
#define LXxO_Drop_Preview LXxD_Drop_Preview
#define LXxC_Drop_Preview(c) LxResult c::drop_Preview([[maybe_unused]] ILxUnknownID source, [[maybe_unused]] ILxUnknownID dest, [[maybe_unused]] int action, [[maybe_unused]] ILxUnknownID draw)
#define LXxD_Drop_Drop LxResult drop_Drop([[maybe_unused]] ILxUnknownID source, [[maybe_unused]] ILxUnknownID dest, [[maybe_unused]] int action) override
#define LXxO_Drop_Drop LXxD_Drop_Drop
#define LXxC_Drop_Drop(c) LxResult c::drop_Drop([[maybe_unused]] ILxUnknownID source, [[maybe_unused]] ILxUnknownID dest, [[maybe_unused]] int action)

template <class T>
class CLxIfc_Drop: public CLxInterface
{
public:
    CLxIfc_Drop()
    {
        vt.Recognize = Recognize;
        vt.ActionList = ActionList;
        vt.Preview = Preview;
        vt.Drop = Drop;
        vTable = &vt.iunk;
        iid = &lx::guid_Drop;
    }

    static auto Recognize(LXtObjectID wcom,LXtObjectID source) -> LxResult
    {
        LXCWxINST (CLxImpl_Drop, loc);
        try
        {
           return loc->drop_Recognize((ILxUnknownID) source);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ActionList(LXtObjectID wcom,LXtObjectID source,LXtObjectID dest,LXtObjectID addDropAction) -> LxResult
    {
        LXCWxINST (CLxImpl_Drop, loc);
        try
        {
           return loc->drop_ActionList((ILxUnknownID) source,(ILxUnknownID) dest,(ILxUnknownID) addDropAction);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Preview(LXtObjectID wcom,LXtObjectID source,LXtObjectID dest,int action,LXtObjectID draw) -> LxResult
    {
        LXCWxINST (CLxImpl_Drop, loc);
        try
        {
           return loc->drop_Preview((ILxUnknownID) source,(ILxUnknownID) dest, action,(ILxUnknownID) draw);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Drop(LXtObjectID wcom,LXtObjectID source,LXtObjectID dest,int action) -> LxResult
    {
        LXCWxINST (CLxImpl_Drop, loc);
        try
        {
           return loc->drop_Drop((ILxUnknownID) source,(ILxUnknownID) dest, action);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxDrop vt;
};

class CLxLoc_Drop : public CLxLocalize<ILxDropID>
{
public:
    CLxLoc_Drop()
    {
        _init();
    }

    CLxLoc_Drop(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_Drop(CLxLoc_Drop const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_Drop;
    }

    auto Recognize(ILxUnknownID source) -> LxResult
    {
        return m_loc[0]->Recognize(m_loc,(ILxUnknownID) source);
    }

    auto ActionList(ILxUnknownID source, ILxUnknownID dest, ILxUnknownID addDropAction) -> LxResult
    {
        return m_loc[0]->ActionList(m_loc,(ILxUnknownID) source,(ILxUnknownID) dest,(ILxUnknownID) addDropAction);
    }

    auto Preview(ILxUnknownID source, ILxUnknownID dest, int action, ILxUnknownID draw) -> LxResult
    {
        return m_loc[0]->Preview(m_loc,(ILxUnknownID) source,(ILxUnknownID) dest, action,(ILxUnknownID) draw);
    }

    auto Drop(ILxUnknownID source, ILxUnknownID dest, int action) -> LxResult
    {
        return m_loc[0]->Drop(m_loc,(ILxUnknownID) source,(ILxUnknownID) dest, action);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_Drop1
{
public:
    virtual ~CLxImpl_Drop1() = default;

    virtual auto drop1_Recognize([[maybe_unused]] ILxUnknownID source) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto drop1_ActionList([[maybe_unused]] ILxUnknownID source, [[maybe_unused]] ILxUnknownID dest, [[maybe_unused]] ILxUnknownID addDropAction) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto drop1_Drop([[maybe_unused]] ILxUnknownID source, [[maybe_unused]] ILxUnknownID dest, [[maybe_unused]] int action) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_Drop1_Recognize LxResult drop1_Recognize([[maybe_unused]] ILxUnknownID source) override
#define LXxO_Drop1_Recognize LXxD_Drop1_Recognize
#define LXxC_Drop1_Recognize(c) LxResult c::drop1_Recognize([[maybe_unused]] ILxUnknownID source)
#define LXxD_Drop1_ActionList LxResult drop1_ActionList([[maybe_unused]] ILxUnknownID source, [[maybe_unused]] ILxUnknownID dest, [[maybe_unused]] ILxUnknownID addDropAction) override
#define LXxO_Drop1_ActionList LXxD_Drop1_ActionList
#define LXxC_Drop1_ActionList(c) LxResult c::drop1_ActionList([[maybe_unused]] ILxUnknownID source, [[maybe_unused]] ILxUnknownID dest, [[maybe_unused]] ILxUnknownID addDropAction)
#define LXxD_Drop1_Drop LxResult drop1_Drop([[maybe_unused]] ILxUnknownID source, [[maybe_unused]] ILxUnknownID dest, [[maybe_unused]] int action) override
#define LXxO_Drop1_Drop LXxD_Drop1_Drop
#define LXxC_Drop1_Drop(c) LxResult c::drop1_Drop([[maybe_unused]] ILxUnknownID source, [[maybe_unused]] ILxUnknownID dest, [[maybe_unused]] int action)

template <class T>
class CLxIfc_Drop1: public CLxInterface
{
public:
    CLxIfc_Drop1()
    {
        vt.Recognize = Recognize;
        vt.ActionList = ActionList;
        vt.Drop = Drop;
        vTable = &vt.iunk;
        iid = &lx::guid_Drop1;
    }

    static auto Recognize(LXtObjectID wcom,LXtObjectID source) -> LxResult
    {
        LXCWxINST (CLxImpl_Drop1, loc);
        try
        {
           return loc->drop1_Recognize((ILxUnknownID) source);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ActionList(LXtObjectID wcom,LXtObjectID source,LXtObjectID dest,LXtObjectID addDropAction) -> LxResult
    {
        LXCWxINST (CLxImpl_Drop1, loc);
        try
        {
           return loc->drop1_ActionList((ILxUnknownID) source,(ILxUnknownID) dest,(ILxUnknownID) addDropAction);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Drop(LXtObjectID wcom,LXtObjectID source,LXtObjectID dest,int action) -> LxResult
    {
        LXCWxINST (CLxImpl_Drop1, loc);
        try
        {
           return loc->drop1_Drop((ILxUnknownID) source,(ILxUnknownID) dest, action);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxDrop1 vt;
};

class CLxLoc_Drop1 : public CLxLocalize<ILxDrop1ID>
{
public:
    CLxLoc_Drop1()
    {
        _init();
    }

    CLxLoc_Drop1(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_Drop1(CLxLoc_Drop1 const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_Drop1;
    }

    auto Recognize(ILxUnknownID source) -> LxResult
    {
        return m_loc[0]->Recognize(m_loc,(ILxUnknownID) source);
    }

    auto ActionList(ILxUnknownID source, ILxUnknownID dest, ILxUnknownID addDropAction) -> LxResult
    {
        return m_loc[0]->ActionList(m_loc,(ILxUnknownID) source,(ILxUnknownID) dest,(ILxUnknownID) addDropAction);
    }

    auto Drop(ILxUnknownID source, ILxUnknownID dest, int action) -> LxResult
    {
        return m_loc[0]->Drop(m_loc,(ILxUnknownID) source,(ILxUnknownID) dest, action);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_AddDropAction : public CLxLocalize<ILxAddDropActionID>
{
public:
    CLxLoc_AddDropAction()
    {
        _init();
    }

    CLxLoc_AddDropAction(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_AddDropAction(CLxLoc_AddDropAction const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_AddDropAction;
    }

    auto AddAction(int action, const char *message) -> LxResult
    {
        return m_loc[0]->AddAction(m_loc, action, message);
    }

    auto Peek(void **ppvObj) -> LxResult
    {
        return m_loc[0]->Peek(m_loc, ppvObj);
    }

    auto Peek(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Peek(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_DropPreviewDefault : public CLxLocalize<ILxDropPreviewDefaultID>
{
public:
    CLxLoc_DropPreviewDefault()
    {
        _init();
    }

    CLxLoc_DropPreviewDefault(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_DropPreviewDefault(CLxLoc_DropPreviewDefault const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_DropPreviewDefault;
    }

    auto Draw(void) -> LxResult
    {
        return m_loc[0]->Draw(m_loc);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_DropService : public CLxLocalizedService
{
public:
    ILxDropServiceID m_loc{ nullptr };

public:
    CLxLoc_DropService()
    {
        _init();
        set();
    }

    ~CLxLoc_DropService() = default;

    void set()
    {
        if (!m_loc)
        {
            m_loc = reinterpret_cast<ILxDropServiceID>(lx::GetGlobal(&lx::guid_DropService));
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

    auto Destination(void **ppvObj) -> LxResult
    {
        return m_loc[0]->Destination(m_loc, ppvObj);
    }

    auto Destination(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Destination(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Source(const char **sourceType, void **ppvObj) -> LxResult
    {
        return m_loc[0]->Source(m_loc, sourceType, ppvObj);
    }

    auto Source(const char **sourceType, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Source(m_loc, sourceType, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Action(const char **serverName, int *actionCode) -> LxResult
    {
        return m_loc[0]->Action(m_loc, serverName, actionCode);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
