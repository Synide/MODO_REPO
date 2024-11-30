//
// C++ wrapper for lxsdk/lxchannelui.h.
//
//	Copyright 2024.
//
//
#pragma once

#include <lxchannelui.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx
{
    static LXtGUID const guid_ChannelUI = {0xd04810aa, {0xd88a, 0x44ef}, {0x92, 0xc2, 0x79, 0x73, 0x74, 0xb4, 0x23, 0x65}};
    static LXtGUID const guid_ChannelUI1 = {0xBF1BFE3B, {0xF0F5, 0x490b}, {0x89, 0x61, 0x72, 0x17, 0x95, 0xDA, 0x57, 0xB4}};
    static LXtGUID const guid_ChannelUIService = {0x3C3A2D98, {0x7EF1, 0x43F4}, {0x84, 0x5C, 0x39, 0xEF, 0x2D, 0x8F, 0x6D, 0x52}};
} // namespace lx

class CLxImpl_ChannelUI
{
public:
    virtual ~CLxImpl_ChannelUI() = default;

    virtual auto cui_Enabled([[maybe_unused]] const char *channelName, [[maybe_unused]] ILxUnknownID msg, [[maybe_unused]] ILxUnknownID item, [[maybe_unused]] ILxUnknownID chanRead) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cui_DependencyCount([[maybe_unused]] const char *channelName, [[maybe_unused]] unsigned *count) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cui_DependencyByIndex([[maybe_unused]] const char *channelName, [[maybe_unused]] unsigned index, [[maybe_unused]] LXtItemType *depItemType, [[maybe_unused]] const char **depChannelName) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cui_DependencyByIndexName([[maybe_unused]] const char *channelName, [[maybe_unused]] unsigned index, [[maybe_unused]] const char **depItemTypeName, [[maybe_unused]] const char **depChannelName) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cui_ItemEnabled([[maybe_unused]] ILxUnknownID msg, [[maybe_unused]] ILxUnknownID item) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cui_ItemIcon([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] const char **icon) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cui_UIHints([[maybe_unused]] const char *channelName, [[maybe_unused]] ILxUnknownID hints) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cui_UIValueHints([[maybe_unused]] const char *channelName, [[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cui_Cookie([[maybe_unused]] const char *channelName, [[maybe_unused]] const char *requestedFor, [[maybe_unused]] const char **cookie) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_ChannelUI_Enabled LxResult cui_Enabled([[maybe_unused]] const char *channelName, [[maybe_unused]] ILxUnknownID msg, [[maybe_unused]] ILxUnknownID item, [[maybe_unused]] ILxUnknownID chanRead) override
#define LXxO_ChannelUI_Enabled LXxD_ChannelUI_Enabled
#define LXxC_ChannelUI_Enabled(c) LxResult c::cui_Enabled([[maybe_unused]] const char *channelName, [[maybe_unused]] ILxUnknownID msg, [[maybe_unused]] ILxUnknownID item, [[maybe_unused]] ILxUnknownID chanRead)
#define LXxD_ChannelUI_DependencyCount LxResult cui_DependencyCount([[maybe_unused]] const char *channelName, [[maybe_unused]] unsigned *count) override
#define LXxO_ChannelUI_DependencyCount LXxD_ChannelUI_DependencyCount
#define LXxC_ChannelUI_DependencyCount(c) LxResult c::cui_DependencyCount([[maybe_unused]] const char *channelName, [[maybe_unused]] unsigned *count)
#define LXxD_ChannelUI_DependencyByIndex LxResult cui_DependencyByIndex([[maybe_unused]] const char *channelName, [[maybe_unused]] unsigned index, [[maybe_unused]] LXtItemType *depItemType, [[maybe_unused]] const char **depChannelName) override
#define LXxO_ChannelUI_DependencyByIndex LXxD_ChannelUI_DependencyByIndex
#define LXxC_ChannelUI_DependencyByIndex(c) LxResult c::cui_DependencyByIndex([[maybe_unused]] const char *channelName, [[maybe_unused]] unsigned index, [[maybe_unused]] LXtItemType *depItemType, [[maybe_unused]] const char **depChannelName)
#define LXxD_ChannelUI_DependencyByIndexName LxResult cui_DependencyByIndexName([[maybe_unused]] const char *channelName, [[maybe_unused]] unsigned index, [[maybe_unused]] const char **depItemTypeName, [[maybe_unused]] const char **depChannelName) override
#define LXxO_ChannelUI_DependencyByIndexName LXxD_ChannelUI_DependencyByIndexName
#define LXxC_ChannelUI_DependencyByIndexName(c) LxResult c::cui_DependencyByIndexName([[maybe_unused]] const char *channelName, [[maybe_unused]] unsigned index, [[maybe_unused]] const char **depItemTypeName, [[maybe_unused]] const char **depChannelName)
#define LXxD_ChannelUI_ItemEnabled LxResult cui_ItemEnabled([[maybe_unused]] ILxUnknownID msg, [[maybe_unused]] ILxUnknownID item) override
#define LXxO_ChannelUI_ItemEnabled LXxD_ChannelUI_ItemEnabled
#define LXxC_ChannelUI_ItemEnabled(c) LxResult c::cui_ItemEnabled([[maybe_unused]] ILxUnknownID msg, [[maybe_unused]] ILxUnknownID item)
#define LXxD_ChannelUI_ItemIcon LxResult cui_ItemIcon([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] const char **icon) override
#define LXxO_ChannelUI_ItemIcon LXxD_ChannelUI_ItemIcon
#define LXxC_ChannelUI_ItemIcon(c) LxResult c::cui_ItemIcon([[maybe_unused]] ILxUnknownID item, [[maybe_unused]] const char **icon)
#define LXxD_ChannelUI_UIHints LxResult cui_UIHints([[maybe_unused]] const char *channelName, [[maybe_unused]] ILxUnknownID hints) override
#define LXxO_ChannelUI_UIHints LXxD_ChannelUI_UIHints
#define LXxC_ChannelUI_UIHints(c) LxResult c::cui_UIHints([[maybe_unused]] const char *channelName, [[maybe_unused]] ILxUnknownID hints)
#define LXxD_ChannelUI_UIValueHints LxResult cui_UIValueHints([[maybe_unused]] const char *channelName, [[maybe_unused]] void **ppvObj) override
#define LXxO_ChannelUI_UIValueHints LXxD_ChannelUI_UIValueHints
#define LXxC_ChannelUI_UIValueHints(c) LxResult c::cui_UIValueHints([[maybe_unused]] const char *channelName, [[maybe_unused]] void **ppvObj)
#define LXxD_ChannelUI_Cookie LxResult cui_Cookie([[maybe_unused]] const char *channelName, [[maybe_unused]] const char *requestedFor, [[maybe_unused]] const char **cookie) override
#define LXxO_ChannelUI_Cookie LXxD_ChannelUI_Cookie
#define LXxC_ChannelUI_Cookie(c) LxResult c::cui_Cookie([[maybe_unused]] const char *channelName, [[maybe_unused]] const char *requestedFor, [[maybe_unused]] const char **cookie)

template <class T>
class CLxIfc_ChannelUI: public CLxInterface
{
public:
    CLxIfc_ChannelUI()
    {
        vt.Enabled = Enabled;
        vt.DependencyCount = DependencyCount;
        vt.DependencyByIndex = DependencyByIndex;
        vt.DependencyByIndexName = DependencyByIndexName;
        vt.ItemEnabled = ItemEnabled;
        vt.ItemIcon = ItemIcon;
        vt.UIHints = UIHints;
        vt.UIValueHints = UIValueHints;
        vt.Cookie = Cookie;
        vTable = &vt.iunk;
        iid = &lx::guid_ChannelUI;
    }

    static auto Enabled(LXtObjectID wcom,const char *channelName,LXtObjectID msg,LXtObjectID item,LXtObjectID chanRead) -> LxResult
    {
        LXCWxINST (CLxImpl_ChannelUI, loc);
        try
        {
           return loc->cui_Enabled( channelName,(ILxUnknownID) msg,(ILxUnknownID) item,(ILxUnknownID) chanRead);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto DependencyCount(LXtObjectID wcom,const char *channelName,unsigned *count) -> LxResult
    {
        LXCWxINST (CLxImpl_ChannelUI, loc);
        try
        {
           return loc->cui_DependencyCount( channelName, count);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto DependencyByIndex(LXtObjectID wcom,const char *channelName,unsigned index,LXtItemType *depItemType,const char **depChannelName) -> LxResult
    {
        LXCWxINST (CLxImpl_ChannelUI, loc);
        try
        {
           return loc->cui_DependencyByIndex( channelName, index, depItemType, depChannelName);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto DependencyByIndexName(LXtObjectID wcom,const char *channelName,unsigned index,const char **depItemTypeName,const char **depChannelName) -> LxResult
    {
        LXCWxINST (CLxImpl_ChannelUI, loc);
        try
        {
           return loc->cui_DependencyByIndexName( channelName, index, depItemTypeName, depChannelName);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ItemEnabled(LXtObjectID wcom,LXtObjectID msg,LXtObjectID item) -> LxResult
    {
        LXCWxINST (CLxImpl_ChannelUI, loc);
        try
        {
           return loc->cui_ItemEnabled((ILxUnknownID) msg,(ILxUnknownID) item);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ItemIcon(LXtObjectID wcom,LXtObjectID item,const char **icon) -> LxResult
    {
        LXCWxINST (CLxImpl_ChannelUI, loc);
        try
        {
           return loc->cui_ItemIcon((ILxUnknownID) item, icon);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto UIHints(LXtObjectID wcom,const char *channelName,LXtObjectID hints) -> LxResult
    {
        LXCWxINST (CLxImpl_ChannelUI, loc);
        try
        {
           return loc->cui_UIHints( channelName,(ILxUnknownID) hints);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto UIValueHints(LXtObjectID wcom,const char *channelName,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_ChannelUI, loc);
        try
        {
           return loc->cui_UIValueHints( channelName, ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Cookie(LXtObjectID wcom,const char *channelName,const char *requestedFor,const char **cookie) -> LxResult
    {
        LXCWxINST (CLxImpl_ChannelUI, loc);
        try
        {
           return loc->cui_Cookie( channelName, requestedFor, cookie);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxChannelUI vt;
};

class CLxLoc_ChannelUI : public CLxLocalize<ILxChannelUIID>
{
public:
    CLxLoc_ChannelUI()
    {
        _init();
    }

    CLxLoc_ChannelUI(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_ChannelUI(CLxLoc_ChannelUI const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_ChannelUI;
    }

    auto Enabled(const char *channelName, ILxUnknownID msg, ILxUnknownID item, ILxUnknownID chanRead) -> LxResult
    {
        return m_loc[0]->Enabled(m_loc, channelName,(ILxUnknownID) msg,(ILxUnknownID) item,(ILxUnknownID) chanRead);
    }

    auto DependencyCount(const char *channelName, unsigned *count) -> LxResult
    {
        return m_loc[0]->DependencyCount(m_loc, channelName, count);
    }

    auto DependencyByIndex(const char *channelName, unsigned index, LXtItemType *depItemType, const char **depChannelName) -> LxResult
    {
        return m_loc[0]->DependencyByIndex(m_loc, channelName, index, depItemType, depChannelName);
    }

    auto DependencyByIndexName(const char *channelName, unsigned index, const char **depItemTypeName, const char **depChannelName) -> LxResult
    {
        return m_loc[0]->DependencyByIndexName(m_loc, channelName, index, depItemTypeName, depChannelName);
    }

    auto ItemEnabled(ILxUnknownID msg, ILxUnknownID item) -> LxResult
    {
        return m_loc[0]->ItemEnabled(m_loc,(ILxUnknownID) msg,(ILxUnknownID) item);
    }

    auto ItemIcon(ILxUnknownID item, const char **icon) -> LxResult
    {
        return m_loc[0]->ItemIcon(m_loc,(ILxUnknownID) item, icon);
    }

    auto UIHints(const char *channelName, ILxUnknownID hints) -> LxResult
    {
        return m_loc[0]->UIHints(m_loc, channelName,(ILxUnknownID) hints);
    }

    auto UIValueHints(const char *channelName, void **ppvObj) -> LxResult
    {
        return m_loc[0]->UIValueHints(m_loc, channelName, ppvObj);
    }

    auto UIValueHints(const char *channelName, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->UIValueHints(m_loc, channelName, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Cookie(const char *channelName, const char *requestedFor, const char **cookie) -> LxResult
    {
        return m_loc[0]->Cookie(m_loc, channelName, requestedFor, cookie);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};

class CLxLoc_ChannelUIService : public CLxLocalizedService
{
public:
    ILxChannelUIServiceID m_loc{ nullptr };

public:
    CLxLoc_ChannelUIService()
    {
        _init();
        set();
    }

    ~CLxLoc_ChannelUIService() = default;

    void set()
    {
        if (!m_loc)
        {
            m_loc = reinterpret_cast<ILxChannelUIServiceID>(lx::GetGlobal(&lx::guid_ChannelUIService));
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

    auto ItemTypeName(LXtItemType typeID, unsigned useSuper, const char **name) -> LxResult
    {
        return m_loc[0]->ItemTypeName(m_loc, typeID, useSuper, name);
    }

    auto ItemTypeDesc(LXtItemType typeID, unsigned useSuper, const char **name) -> LxResult
    {
        return m_loc[0]->ItemTypeDesc(m_loc, typeID, useSuper, name);
    }

    auto ItemTypeIconText(LXtItemType typeID, unsigned useSuper, char *buf, unsigned len) -> LxResult
    {
        return m_loc[0]->ItemTypeIconText(m_loc, typeID, useSuper, buf, len);
    }

    auto ItemTypeIconText(LXtItemType typeID, unsigned useSuper, std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->ItemTypeIconText(m_loc, typeID, useSuper, buf, len);
        LXWx_SBUF2
    }

    auto MeshMapUserName(const char *name, unsigned addIcon, char *buf, unsigned len) -> LxResult
    {
        return m_loc[0]->MeshMapUserName(m_loc, name, addIcon, buf, len);
    }

    auto MeshMapUserName(const char *name, unsigned addIcon, std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->MeshMapUserName(m_loc, name, addIcon, buf, len);
        LXWx_SBUF2
    }

    auto ChannelUserName(ILxUnknownID item, unsigned channel, char *buf, unsigned len) -> LxResult
    {
        return m_loc[0]->ChannelUserName(m_loc,(ILxUnknownID) item, channel, buf, len);
    }

    auto ChannelUserName(ILxUnknownID item, unsigned channel, std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->ChannelUserName(m_loc,(ILxUnknownID) item, channel, buf, len);
        LXWx_SBUF2
    }

    auto ChannelDescription(ILxUnknownID item, unsigned channel, const char **desc) -> LxResult
    {
        return m_loc[0]->ChannelDescription(m_loc,(ILxUnknownID) item, channel, desc);
    }

    auto ChannelToolTip(ILxUnknownID item, unsigned channel, const char **tip) -> LxResult
    {
        return m_loc[0]->ChannelToolTip(m_loc,(ILxUnknownID) item, channel, tip);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
