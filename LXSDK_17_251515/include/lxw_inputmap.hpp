//
// C++ wrapper for lxsdk/lxinputmap.h.
//
//	Copyright 2024.
//
//
#pragma once

#include <lxinputmap.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx
{
    static LXtGUID const guid_InputMapService = {0xDEDDBC50, {0xF747, 0x43a4}, {0x83, 0x8D, 0xD7, 0x06, 0xED, 0x68, 0x84, 0x16}};
    static LXtGUID const guid_InputMapClientTest = {0x7653F32B, {0x8FDA, 0x40ce}, {0x8E, 0xDE, 0x0D, 0x55, 0x23, 0xBC, 0x76, 0x09}};
    static LXtGUID const guid_InputContextClientTest = {0xFB08280B, {0x5F3E, 0x4852}, {0xB3, 0x1F, 0x8A, 0x87, 0xA6, 0xE7, 0x42, 0x7F}};
    static LXtGUID const guid_RegionHandler = {0x05811721, {0x08E9, 0x49e0}, {0xAD, 0xFE, 0x92, 0xC6, 0xD4, 0xA3, 0xE5, 0xE6}};
    static LXtGUID const guid_InputDevices = {0x0a70601b, {0x750d, 0x4325}, {0xb3, 0x8a, 0x86, 0xf3, 0x19, 0x93, 0x3e, 0x17}};
    static LXtGUID const guid_InputDeviceInstance = {0xfd2edfc9, {0xc3db, 0x4409}, {0xa4, 0x78, 0xfc, 0xe1, 0x51, 0x1b, 0x9f, 0xf0}};
} // namespace lx

class CLxLoc_InputMapService : public CLxLocalizedService
{
public:
    ILxInputMapServiceID m_loc{ nullptr };

public:
    CLxLoc_InputMapService()
    {
        _init();
        set();
    }

    ~CLxLoc_InputMapService() = default;

    void set()
    {
        if (!m_loc)
        {
            m_loc = reinterpret_cast<ILxInputMapServiceID>(lx::GetGlobal(&lx::guid_InputMapService));
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

    auto Define(LXtInputContextID context, const char *name, LXtInputMapID *im) -> LxResult
    {
        return m_loc[0]->Define(m_loc, context, name, im);
    }

    auto DefineGroup(const char *group) -> LxResult
    {
        return m_loc[0]->DefineGroup(m_loc, group);
    }

    auto DefineStandardEvent(int event, int flags) -> LxResult
    {
        return m_loc[0]->DefineStandardEvent(m_loc, event, flags);
    }

    auto DefineCustomEvent(int event, const char *name, int flags) -> LxResult
    {
        return m_loc[0]->DefineCustomEvent(m_loc, event, name, flags);
    }

    auto DefineClientTests(ILxUnknownID tester) -> LxResult
    {
        return m_loc[0]->DefineClientTests(m_loc,(ILxUnknownID) tester);
    }

    auto DefineRegion(int event, const char *name) -> LxResult
    {
        return m_loc[0]->DefineRegion(m_loc, event, name);
    }

    auto Count(LXtInputContextID context, int *count) -> LxResult
    {
        return m_loc[0]->Count(m_loc, context, count);
    }

    auto ByIndex(LXtInputContextID context, int index, void **ppObj) -> LxResult
    {
        return m_loc[0]->ByIndex(m_loc, context, index, ppObj);
    }

    auto Lookup(LXtInputContextID context, const char *name, void **ppObj) -> LxResult
    {
        return m_loc[0]->Lookup(m_loc, context, name, ppObj);
    }

    auto GroupCount(LXtInputMapGroupID group, int *count) -> LxResult
    {
        return m_loc[0]->GroupCount(m_loc, group, count);
    }

    auto GroupByIndex(LXtInputMapGroupID group, int index, LXtInputMapGroupID *subgroup) -> LxResult
    {
        return m_loc[0]->GroupByIndex(m_loc, group, index, subgroup);
    }

    auto GroupIMCount(LXtInputMapGroupID group, int *count) -> LxResult
    {
        return m_loc[0]->GroupIMCount(m_loc, group, count);
    }

    auto GroupIMByIndex(LXtInputMapGroupID group, int index, LXtInputMapID *im) -> LxResult
    {
        return m_loc[0]->GroupIMByIndex(m_loc, group, index, im);
    }

    auto GroupGetName(LXtInputMapGroupID group, const char **name) -> LxResult
    {
        return m_loc[0]->GroupGetName(m_loc, group, name);
    }

    auto GroupGetUserName(LXtInputMapGroupID group, const char **username) -> LxResult
    {
        return m_loc[0]->GroupGetUserName(m_loc, group, username);
    }

    auto Name(LXtInputMapID im, const char **name) -> LxResult
    {
        return m_loc[0]->Name(m_loc, im, name);
    }

    auto Group(LXtInputMapID im, const char **groupPath, LXtInputMapGroupID *group) -> LxResult
    {
        return m_loc[0]->Group(m_loc, im, groupPath, group);
    }

    auto Data(LXtInputMapID im, void **data) -> LxResult
    {
        return m_loc[0]->Data(m_loc, im, data);
    }

    auto EventCount(LXtInputMapID im, int *count) -> LxResult
    {
        return m_loc[0]->EventCount(m_loc, im, count);
    }

    auto EventName(LXtInputMapID im, int index, const char **name) -> LxResult
    {
        return m_loc[0]->EventName(m_loc, im, index, name);
    }

    auto EventType(LXtInputMapID im, int index, int *type) -> LxResult
    {
        return m_loc[0]->EventType(m_loc, im, index, type);
    }

    auto EventFlags(LXtInputMapID im, int index, int *flags) -> LxResult
    {
        return m_loc[0]->EventFlags(m_loc, im, index, flags);
    }

    auto CanEventsCoexist(LXtInputMapID im, int event1, int event2) -> LxResult
    {
        return m_loc[0]->CanEventsCoexist(m_loc, im, event1, event2);
    }

    auto StandardEventName(int event, const char **name) -> LxResult
    {
        return m_loc[0]->StandardEventName(m_loc, event, name);
    }

    auto StandardEventFlags(int event, int *flags) -> LxResult
    {
        return m_loc[0]->StandardEventFlags(m_loc, event, flags);
    }

    auto RegionCount(LXtInputMapID im, int *count) -> LxResult
    {
        return m_loc[0]->RegionCount(m_loc, im, count);
    }

    auto RegionName(LXtInputMapID im, int i, const char **name) -> LxResult
    {
        return m_loc[0]->RegionName(m_loc, im, i, name);
    }

    auto RegionType(LXtInputMapID im, int i, int *type) -> LxResult
    {
        return m_loc[0]->RegionType(m_loc, im, i, type);
    }

    auto FindEvent(LXtInputMapID im, const char *name, int type, int *index) -> LxResult
    {
        return m_loc[0]->FindEvent(m_loc, im, name, type, index);
    }

    auto FindRegion(LXtInputMapID im, const char *name, int type, int *index) -> LxResult
    {
        return m_loc[0]->FindRegion(m_loc, im, name, type, index);
    }

    auto UserName(LXtInputMapID im, const char **username) -> LxResult
    {
        return m_loc[0]->UserName(m_loc, im, username);
    }

    auto Desc(LXtInputMapID im, const char **desc) -> LxResult
    {
        return m_loc[0]->Desc(m_loc, im, desc);
    }

    auto HelpURL(LXtInputMapID im, const char **helpURL) -> LxResult
    {
        return m_loc[0]->HelpURL(m_loc, im, helpURL);
    }

    auto EventUserName(LXtInputMapID im, const char *stateName, const char *name, int index, const char **username) -> LxResult
    {
        return m_loc[0]->EventUserName(m_loc, im, stateName, name, index, username);
    }

    auto EventDesc(LXtInputMapID im, const char *stateName, const char *name, int index, const char **desc) -> LxResult
    {
        return m_loc[0]->EventDesc(m_loc, im, stateName, name, index, desc);
    }

    auto EventHelpURL(LXtInputMapID im, const char *stateName, const char *name, int index, const char **helpURL) -> LxResult
    {
        return m_loc[0]->EventHelpURL(m_loc, im, stateName, name, index, helpURL);
    }

    auto RegionUserName(LXtInputMapID im, const char *stateName, const char *name, int index, const char **username) -> LxResult
    {
        return m_loc[0]->RegionUserName(m_loc, im, stateName, name, index, username);
    }

    auto RegionDesc(LXtInputMapID im, const char *stateName, const char *name, int index, const char **desc) -> LxResult
    {
        return m_loc[0]->RegionDesc(m_loc, im, stateName, name, index, desc);
    }

    auto RegionHelpURL(LXtInputMapID im, const char *stateName, const char *name, int index, const char **helpURL) -> LxResult
    {
        return m_loc[0]->RegionHelpURL(m_loc, im, stateName, name, index, helpURL);
    }

    auto GroupUserName(const char *path, int depth, const char **username) -> LxResult
    {
        return m_loc[0]->GroupUserName(m_loc, path, depth, username);
    }

    auto StateUserName(const char *state, const char **name) -> LxResult
    {
        return m_loc[0]->StateUserName(m_loc, state, name);
    }

    auto StateCatUserName(const char *cat, const char **name) -> LxResult
    {
        return m_loc[0]->StateCatUserName(m_loc, cat, name);
    }

    auto StateLookup(LXtInputMapID im, const char *name, int add, LXtInputStateID *state) -> LxResult
    {
        return m_loc[0]->StateLookup(m_loc, im, name, add, state);
    }

    auto StateCount(LXtInputMapID im, int *count) -> LxResult
    {
        return m_loc[0]->StateCount(m_loc, im, count);
    }

    auto StateByIndex(LXtInputMapID im, int i, LXtInputStateID *state) -> LxResult
    {
        return m_loc[0]->StateByIndex(m_loc, im, i, state);
    }

    auto StateName(LXtInputStateID state, const char **name) -> LxResult
    {
        return m_loc[0]->StateName(m_loc, state, name);
    }

    auto StateInputMap(LXtInputStateID state, LXtInputMapID *im) -> LxResult
    {
        return m_loc[0]->StateInputMap(m_loc, state, im);
    }

    auto TestState(LXtInputMapID im, const char *state, int *priority) -> LxResult
    {
        return m_loc[0]->TestState(m_loc, im, state, priority);
    }

    auto StateUIListCatCount(int *count) -> LxResult
    {
        return m_loc[0]->StateUIListCatCount(m_loc, count);
    }

    auto StateUIListCatName(int index, const char **name) -> LxResult
    {
        return m_loc[0]->StateUIListCatName(m_loc, index, name);
    }

    auto StateUIListCount(const char *cat, int *count) -> LxResult
    {
        return m_loc[0]->StateUIListCount(m_loc, cat, count);
    }

    auto StateUIListName(const char *cat, int index, const char **name) -> LxResult
    {
        return m_loc[0]->StateUIListName(m_loc, cat, index, name);
    }

    auto StateUIFallbacksCount(const char *stateName, int *count) -> LxResult
    {
        return m_loc[0]->StateUIFallbacksCount(m_loc, stateName, count);
    }

    auto StateUIFallbacksName(const char *stateName, int index, const char **name) -> LxResult
    {
        return m_loc[0]->StateUIFallbacksName(m_loc, stateName, index, name);
    }

    auto StateUITestEvent(LXtInputMapID im, const char *stateName, int eventID) -> LxResult
    {
        return m_loc[0]->StateUITestEvent(m_loc, im, stateName, eventID);
    }

    auto StateUITestRegion(LXtInputMapID im, const char *stateName, int regionID) -> LxResult
    {
        return m_loc[0]->StateUITestRegion(m_loc, im, stateName, regionID);
    }

    auto RefreshStates(int flags) -> LxResult
    {
        return m_loc[0]->RefreshStates(m_loc, flags);
    }

    auto DefineContext(const char *name, int type, ILxUnknownID clientTest, LXtInputContextID *context) -> LxResult
    {
        return m_loc[0]->DefineContext(m_loc, name, type,(ILxUnknownID) clientTest, context);
    }

    auto ContextCount(int *count) -> LxResult
    {
        return m_loc[0]->ContextCount(m_loc, count);
    }

    auto ContextByIndex(int index, LXtInputContextID *context) -> LxResult
    {
        return m_loc[0]->ContextByIndex(m_loc, index, context);
    }

    auto ContextLookup(const char *name, LXtInputContextID *context) -> LxResult
    {
        return m_loc[0]->ContextLookup(m_loc, name, context);
    }

    auto TestContext(LXtInputContextID context, int *priority) -> LxResult
    {
        return m_loc[0]->TestContext(m_loc, context, priority);
    }

    auto ContextName(LXtInputContextID context, const char **name) -> LxResult
    {
        return m_loc[0]->ContextName(m_loc, context, name);
    }

    auto ContextType(LXtInputContextID context, int *type) -> LxResult
    {
        return m_loc[0]->ContextType(m_loc, context, type);
    }

    auto ContextUserName(LXtInputContextID context, const char **name) -> LxResult
    {
        return m_loc[0]->ContextUserName(m_loc, context, name);
    }

    auto ContextDesc(LXtInputContextID context, const char **desc) -> LxResult
    {
        return m_loc[0]->ContextDesc(m_loc, context, desc);
    }

    auto ContextHelpURL(LXtInputContextID context, const char **helpURL) -> LxResult
    {
        return m_loc[0]->ContextHelpURL(m_loc, context, helpURL);
    }

    auto Context(LXtInputMapID im, LXtInputContextID *context) -> LxResult
    {
        return m_loc[0]->Context(m_loc, im, context);
    }

    auto RefreshContexts(void) -> LxResult
    {
        return m_loc[0]->RefreshContexts(m_loc);
    }

    auto EventMappingCount(LXtInputStateID state, const char *eventName, int eventIndex, int eventType, int *count) -> LxResult
    {
        return m_loc[0]->EventMappingCount(m_loc, state, eventName, eventIndex, eventType, count);
    }

    auto EventMappingByIndex(LXtInputStateID state, const char *eventName, int eventIndex, int eventType, int index, LXtDualKeyCombo *combo) -> LxResult
    {
        return m_loc[0]->EventMappingByIndex(m_loc, state, eventName, eventIndex, eventType, index, combo);
    }

    auto RegionMappingCount(LXtInputStateID state, const char *regionName, int regionIndex, int regionType, int *count) -> LxResult
    {
        return m_loc[0]->RegionMappingCount(m_loc, state, regionName, regionIndex, regionType, count);
    }

    auto RegionMappingByIndex(LXtInputStateID state, const char *regionName, int regionIndex, int regionType, int index, LXtDualKeyCombo *combo, const char **command) -> LxResult
    {
        return m_loc[0]->RegionMappingByIndex(m_loc, state, regionName, regionIndex, regionType, index, combo, command);
    }

    auto RegionMappingFind(LXtInputStateID state, const char *regionName, int regionIndex, int regionType, const LXtDualKeyCombo combo, int *index) -> LxResult
    {
        return m_loc[0]->RegionMappingFind(m_loc, state, regionName, regionIndex, regionType, combo, index);
    }

    auto ComboMapsTo(LXtInputStateID state, LXtDualKeyCombo combo, int eventFlags, int index, int *type) -> LxResult
    {
        return m_loc[0]->ComboMapsTo(m_loc, state, combo, eventFlags, index, type);
    }

    auto ComboToString(LXtDualKeyCombo combo, char *buffer, int bufLen) -> LxResult
    {
        return m_loc[0]->ComboToString(m_loc, combo, buffer, bufLen);
    }

    auto ComboEncode(LXtDualKeyCombo combo, char *buffer, int bufLen) -> LxResult
    {
        return m_loc[0]->ComboEncode(m_loc, combo, buffer, bufLen);
    }

    auto ComboDecode(const char *string, LXtDualKeyCombo *combo, int mode) -> LxResult
    {
        return m_loc[0]->ComboDecode(m_loc, string, combo, mode);
    }

    auto ComboCompare(LXtDualKeyCombo combo1, LXtDualKeyCombo combo2) -> LxResult
    {
        return m_loc[0]->ComboCompare(m_loc, combo1, combo2);
    }

    auto ComboEncodePart(LXtDualKey part, char *buffer, int bufLen) -> LxResult
    {
        return m_loc[0]->ComboEncodePart(m_loc, part, buffer, bufLen);
    }

    auto ComboDecodePart(const char *string, LXtDualKey *part) -> LxResult
    {
        return m_loc[0]->ComboDecodePart(m_loc, string, part);
    }

    auto GetMouseMap(LXtInputMapID im, void **ppvObj) -> LxResult
    {
        return m_loc[0]->GetMouseMap(m_loc, im, ppvObj);
    }

    auto GetMouseMap(LXtInputMapID im, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->GetMouseMap(m_loc, im, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto AttachRegions(LXtInputMapID im, void *pane, int mouserPriority, ILxUnknownID handler, void **ppObj) -> LxResult
    {
        return m_loc[0]->AttachRegions(m_loc, im, pane, mouserPriority,(ILxUnknownID) handler, ppObj);
    }

    auto UpdateDeviceList(void) -> LxResult
    {
        return m_loc[0]->UpdateDeviceList(m_loc);
    }

    auto UpdateDeviceInstance(const char *name) -> LxResult
    {
        return m_loc[0]->UpdateDeviceInstance(m_loc, name);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};



class CLxImpl_InputDevices
{
public:
    virtual ~CLxImpl_InputDevices() = default;

    virtual auto indev_DeviceCount([[maybe_unused]] void) -> int
    {
        return 0;
    }

    virtual auto indev_DeviceNameByIndex([[maybe_unused]] unsigned deviceIndex, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto indev_DeviceInstanceByIndex([[maybe_unused]] int index, [[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_InputDevices_DeviceCount int indev_DeviceCount() override
#define LXxO_InputDevices_DeviceCount LXxD_InputDevices_DeviceCount
#define LXxC_InputDevices_DeviceCount(c) int c::indev_DeviceCount()
#define LXxD_InputDevices_DeviceNameByIndex LxResult indev_DeviceNameByIndex([[maybe_unused]] unsigned deviceIndex, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len) override
#define LXxO_InputDevices_DeviceNameByIndex LXxD_InputDevices_DeviceNameByIndex
#define LXxC_InputDevices_DeviceNameByIndex(c) LxResult c::indev_DeviceNameByIndex([[maybe_unused]] unsigned deviceIndex, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len)
#define LXxD_InputDevices_DeviceInstanceByIndex LxResult indev_DeviceInstanceByIndex([[maybe_unused]] int index, [[maybe_unused]] void **ppvObj) override
#define LXxO_InputDevices_DeviceInstanceByIndex LXxD_InputDevices_DeviceInstanceByIndex
#define LXxC_InputDevices_DeviceInstanceByIndex(c) LxResult c::indev_DeviceInstanceByIndex([[maybe_unused]] int index, [[maybe_unused]] void **ppvObj)

template <class T>
class CLxIfc_InputDevices: public CLxInterface
{
public:
    CLxIfc_InputDevices()
    {
        vt.DeviceCount = DeviceCount;
        vt.DeviceNameByIndex = DeviceNameByIndex;
        vt.DeviceInstanceByIndex = DeviceInstanceByIndex;
        vTable = &vt.iunk;
        iid = &lx::guid_InputDevices;
    }

    static auto DeviceCount(LXtObjectID wcom) -> int
    {
        LXCWxINST (CLxImpl_InputDevices, loc);
        return loc->indev_DeviceCount();
    }

    static auto DeviceNameByIndex(LXtObjectID wcom,unsigned deviceIndex,char *buf,unsigned len) -> LxResult
    {
        LXCWxINST (CLxImpl_InputDevices, loc);
        try
        {
           return loc->indev_DeviceNameByIndex( deviceIndex, buf, len);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto DeviceInstanceByIndex(LXtObjectID wcom,int index,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_InputDevices, loc);
        try
        {
           return loc->indev_DeviceInstanceByIndex( index, ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxInputDevices vt;
};

class CLxLoc_InputDevices : public CLxLocalize<ILxInputDevicesID>
{
public:
    CLxLoc_InputDevices()
    {
        _init();
    }

    CLxLoc_InputDevices(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_InputDevices(CLxLoc_InputDevices const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_InputDevices;
    }

    auto DeviceCount(void) -> int
    {
        return m_loc[0]->DeviceCount(m_loc);
    }

    auto DeviceNameByIndex(unsigned deviceIndex, char *buf, unsigned len) -> LxResult
    {
        return m_loc[0]->DeviceNameByIndex(m_loc, deviceIndex, buf, len);
    }

    auto DeviceNameByIndex(unsigned deviceIndex, std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->DeviceNameByIndex(m_loc, deviceIndex, buf, len);
        LXWx_SBUF2
    }

    auto DeviceInstanceByIndex(int index, void **ppvObj) -> LxResult
    {
        return m_loc[0]->DeviceInstanceByIndex(m_loc, index, ppvObj);
    }

    auto DeviceInstanceByIndex(int index, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->DeviceInstanceByIndex(m_loc, index, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_InputDeviceInstance
{
public:
    virtual ~CLxImpl_InputDeviceInstance() = default;

    virtual auto indevinst_Name([[maybe_unused]] const char *name) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto indevinst_IsConnected([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto indevinst_ButtonCount([[maybe_unused]] void) -> int
    {
        return 0;
    }

    virtual auto indevinst_ButtonName([[maybe_unused]] unsigned int index, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned int len) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto indevinst_ButtonUserName([[maybe_unused]] unsigned int index, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned int len) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto indevinst_ButtonIsDown([[maybe_unused]] int index) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto indevinst_AnalogCount([[maybe_unused]] void) -> int
    {
        return 0;
    }

    virtual auto indevinst_AnalogName([[maybe_unused]] unsigned int index, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned int len) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto indevinst_AnalogUserName([[maybe_unused]] unsigned int index, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned int len) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto indevinst_AnalogMetrics([[maybe_unused]] int index, [[maybe_unused]] int *isAbsolute, [[maybe_unused]] int *isDirectional) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto indevinst_AnalogValue([[maybe_unused]] int index, [[maybe_unused]] double *value) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_InputDeviceInstance_Name LxResult indevinst_Name([[maybe_unused]] const char *name) override
#define LXxO_InputDeviceInstance_Name LXxD_InputDeviceInstance_Name
#define LXxC_InputDeviceInstance_Name(c) LxResult c::indevinst_Name([[maybe_unused]] const char *name)
#define LXxD_InputDeviceInstance_IsConnected LxResult indevinst_IsConnected() override
#define LXxO_InputDeviceInstance_IsConnected LXxD_InputDeviceInstance_IsConnected
#define LXxC_InputDeviceInstance_IsConnected(c) LxResult c::indevinst_IsConnected()
#define LXxD_InputDeviceInstance_ButtonCount int indevinst_ButtonCount() override
#define LXxO_InputDeviceInstance_ButtonCount LXxD_InputDeviceInstance_ButtonCount
#define LXxC_InputDeviceInstance_ButtonCount(c) int c::indevinst_ButtonCount()
#define LXxD_InputDeviceInstance_ButtonName LxResult indevinst_ButtonName([[maybe_unused]] unsigned int index, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned int len) override
#define LXxO_InputDeviceInstance_ButtonName LXxD_InputDeviceInstance_ButtonName
#define LXxC_InputDeviceInstance_ButtonName(c) LxResult c::indevinst_ButtonName([[maybe_unused]] unsigned int index, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned int len)
#define LXxD_InputDeviceInstance_ButtonUserName LxResult indevinst_ButtonUserName([[maybe_unused]] unsigned int index, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned int len) override
#define LXxO_InputDeviceInstance_ButtonUserName LXxD_InputDeviceInstance_ButtonUserName
#define LXxC_InputDeviceInstance_ButtonUserName(c) LxResult c::indevinst_ButtonUserName([[maybe_unused]] unsigned int index, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned int len)
#define LXxD_InputDeviceInstance_ButtonIsDown LxResult indevinst_ButtonIsDown([[maybe_unused]] int index) override
#define LXxO_InputDeviceInstance_ButtonIsDown LXxD_InputDeviceInstance_ButtonIsDown
#define LXxC_InputDeviceInstance_ButtonIsDown(c) LxResult c::indevinst_ButtonIsDown([[maybe_unused]] int index)
#define LXxD_InputDeviceInstance_AnalogCount int indevinst_AnalogCount() override
#define LXxO_InputDeviceInstance_AnalogCount LXxD_InputDeviceInstance_AnalogCount
#define LXxC_InputDeviceInstance_AnalogCount(c) int c::indevinst_AnalogCount()
#define LXxD_InputDeviceInstance_AnalogName LxResult indevinst_AnalogName([[maybe_unused]] unsigned int index, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned int len) override
#define LXxO_InputDeviceInstance_AnalogName LXxD_InputDeviceInstance_AnalogName
#define LXxC_InputDeviceInstance_AnalogName(c) LxResult c::indevinst_AnalogName([[maybe_unused]] unsigned int index, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned int len)
#define LXxD_InputDeviceInstance_AnalogUserName LxResult indevinst_AnalogUserName([[maybe_unused]] unsigned int index, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned int len) override
#define LXxO_InputDeviceInstance_AnalogUserName LXxD_InputDeviceInstance_AnalogUserName
#define LXxC_InputDeviceInstance_AnalogUserName(c) LxResult c::indevinst_AnalogUserName([[maybe_unused]] unsigned int index, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned int len)
#define LXxD_InputDeviceInstance_AnalogMetrics LxResult indevinst_AnalogMetrics([[maybe_unused]] int index, [[maybe_unused]] int *isAbsolute, [[maybe_unused]] int *isDirectional) override
#define LXxO_InputDeviceInstance_AnalogMetrics LXxD_InputDeviceInstance_AnalogMetrics
#define LXxC_InputDeviceInstance_AnalogMetrics(c) LxResult c::indevinst_AnalogMetrics([[maybe_unused]] int index, [[maybe_unused]] int *isAbsolute, [[maybe_unused]] int *isDirectional)
#define LXxD_InputDeviceInstance_AnalogValue LxResult indevinst_AnalogValue([[maybe_unused]] int index, [[maybe_unused]] double *value) override
#define LXxO_InputDeviceInstance_AnalogValue LXxD_InputDeviceInstance_AnalogValue
#define LXxC_InputDeviceInstance_AnalogValue(c) LxResult c::indevinst_AnalogValue([[maybe_unused]] int index, [[maybe_unused]] double *value)

template <class T>
class CLxIfc_InputDeviceInstance: public CLxInterface
{
public:
    CLxIfc_InputDeviceInstance()
    {
        vt.Name = Name;
        vt.IsConnected = IsConnected;
        vt.ButtonCount = ButtonCount;
        vt.ButtonName = ButtonName;
        vt.ButtonUserName = ButtonUserName;
        vt.ButtonIsDown = ButtonIsDown;
        vt.AnalogCount = AnalogCount;
        vt.AnalogName = AnalogName;
        vt.AnalogUserName = AnalogUserName;
        vt.AnalogMetrics = AnalogMetrics;
        vt.AnalogValue = AnalogValue;
        vTable = &vt.iunk;
        iid = &lx::guid_InputDeviceInstance;
    }

    static auto Name(LXtObjectID wcom,const char *name) -> LxResult
    {
        LXCWxINST (CLxImpl_InputDeviceInstance, loc);
        try
        {
           return loc->indevinst_Name( name);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto IsConnected(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_InputDeviceInstance, loc);
        try
        {
           return loc->indevinst_IsConnected();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ButtonCount(LXtObjectID wcom) -> int
    {
        LXCWxINST (CLxImpl_InputDeviceInstance, loc);
        return loc->indevinst_ButtonCount();
    }

    static auto ButtonName(LXtObjectID wcom,unsigned int index,char *buf,unsigned int len) -> LxResult
    {
        LXCWxINST (CLxImpl_InputDeviceInstance, loc);
        try
        {
           return loc->indevinst_ButtonName( index, buf, len);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ButtonUserName(LXtObjectID wcom,unsigned int index,char *buf,unsigned int len) -> LxResult
    {
        LXCWxINST (CLxImpl_InputDeviceInstance, loc);
        try
        {
           return loc->indevinst_ButtonUserName( index, buf, len);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ButtonIsDown(LXtObjectID wcom,int index) -> LxResult
    {
        LXCWxINST (CLxImpl_InputDeviceInstance, loc);
        try
        {
           return loc->indevinst_ButtonIsDown( index);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto AnalogCount(LXtObjectID wcom) -> int
    {
        LXCWxINST (CLxImpl_InputDeviceInstance, loc);
        return loc->indevinst_AnalogCount();
    }

    static auto AnalogName(LXtObjectID wcom,unsigned int index,char *buf,unsigned int len) -> LxResult
    {
        LXCWxINST (CLxImpl_InputDeviceInstance, loc);
        try
        {
           return loc->indevinst_AnalogName( index, buf, len);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto AnalogUserName(LXtObjectID wcom,unsigned int index,char *buf,unsigned int len) -> LxResult
    {
        LXCWxINST (CLxImpl_InputDeviceInstance, loc);
        try
        {
           return loc->indevinst_AnalogUserName( index, buf, len);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto AnalogMetrics(LXtObjectID wcom,int index,int *isAbsolute,int *isDirectional) -> LxResult
    {
        LXCWxINST (CLxImpl_InputDeviceInstance, loc);
        try
        {
           return loc->indevinst_AnalogMetrics( index, isAbsolute, isDirectional);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto AnalogValue(LXtObjectID wcom,int index,double *value) -> LxResult
    {
        LXCWxINST (CLxImpl_InputDeviceInstance, loc);
        try
        {
           return loc->indevinst_AnalogValue( index, value);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxInputDeviceInstance vt;
};

class CLxLoc_InputDeviceInstance : public CLxLocalize<ILxInputDeviceInstanceID>
{
public:
    CLxLoc_InputDeviceInstance()
    {
        _init();
    }

    CLxLoc_InputDeviceInstance(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_InputDeviceInstance(CLxLoc_InputDeviceInstance const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_InputDeviceInstance;
    }

    auto Name(const char *name) -> LxResult
    {
        return m_loc[0]->Name(m_loc, name);
    }

    auto IsConnected(void) -> LxResult
    {
        return m_loc[0]->IsConnected(m_loc);
    }

    auto ButtonCount(void) -> int
    {
        return m_loc[0]->ButtonCount(m_loc);
    }

    auto ButtonName(unsigned int index, char *buf, unsigned int len) -> LxResult
    {
        return m_loc[0]->ButtonName(m_loc, index, buf, len);
    }

    auto ButtonName(unsigned int index, std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->ButtonName(m_loc, index, buf, len);
        LXWx_SBUF2
    }

    auto ButtonUserName(unsigned int index, char *buf, unsigned int len) -> LxResult
    {
        return m_loc[0]->ButtonUserName(m_loc, index, buf, len);
    }

    auto ButtonUserName(unsigned int index, std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->ButtonUserName(m_loc, index, buf, len);
        LXWx_SBUF2
    }

    auto ButtonIsDown(int index) -> LxResult
    {
        return m_loc[0]->ButtonIsDown(m_loc, index);
    }

    auto AnalogCount(void) -> int
    {
        return m_loc[0]->AnalogCount(m_loc);
    }

    auto AnalogName(unsigned int index, char *buf, unsigned int len) -> LxResult
    {
        return m_loc[0]->AnalogName(m_loc, index, buf, len);
    }

    auto AnalogName(unsigned int index, std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->AnalogName(m_loc, index, buf, len);
        LXWx_SBUF2
    }

    auto AnalogUserName(unsigned int index, char *buf, unsigned int len) -> LxResult
    {
        return m_loc[0]->AnalogUserName(m_loc, index, buf, len);
    }

    auto AnalogUserName(unsigned int index, std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->AnalogUserName(m_loc, index, buf, len);
        LXWx_SBUF2
    }

    auto AnalogMetrics(int index, int *isAbsolute, int *isDirectional) -> LxResult
    {
        return m_loc[0]->AnalogMetrics(m_loc, index, isAbsolute, isDirectional);
    }

    auto AnalogValue(int index, double *value) -> LxResult
    {
        return m_loc[0]->AnalogValue(m_loc, index, value);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
