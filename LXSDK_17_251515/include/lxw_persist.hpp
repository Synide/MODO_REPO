//
// C++ wrapper for lxsdk/lxpersist.h.
//
//	Copyright 2024.
//
//
#pragma once

#include <lxpersist.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx
{
    static LXtGUID const guid_PersistenceService = {0x4CB5705E, {0xC705, 0x499D}, {0x95, 0x61, 0x6F, 0xD3, 0x69, 0xCE, 0xFE, 0x99}};
    static LXtGUID const guid_PersistenceClient = {0x435E3BEE, {0x8317, 0x4DEB}, {0x92, 0xA8, 0x74, 0xE1, 0x15, 0x38, 0x4F, 0x3F}};
    static LXtGUID const guid_PersistentEntry = {0xBD3F1DF5, {0x967B, 0x441F}, {0x86, 0xA7, 0xA0, 0x91, 0xF2, 0xE6, 0xCD, 0xA5}};
} // namespace lx

class CLxLoc_PersistenceService : public CLxLocalizedService
{
public:
    ILxPersistenceServiceID m_loc{ nullptr };

public:
    CLxLoc_PersistenceService()
    {
        _init();
        set();
    }

    ~CLxLoc_PersistenceService() = default;

    void set()
    {
        if (!m_loc)
        {
            m_loc = reinterpret_cast<ILxPersistenceServiceID>(lx::GetGlobal(&lx::guid_PersistenceService));
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

    auto Configure(const char *name, ILxUnknownID obj) -> LxResult
    {
        return m_loc[0]->Configure(m_loc, name,(ILxUnknownID) obj);
    }

    auto Start(const char *name, unsigned int type) -> LxResult
    {
        return m_loc[0]->Start(m_loc, name, type);
    }

    auto End(void **ppvObj) -> LxResult
    {
        return m_loc[0]->End(m_loc, ppvObj);
    }

    auto End(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->End(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto AddValue(const char *typeName) -> LxResult
    {
        return m_loc[0]->AddValue(m_loc, typeName);
    }

    auto AddKeyValueSupport(void) -> LxResult
    {
        return m_loc[0]->AddKeyValueSupport(m_loc);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_PersistenceClient
{
public:
    virtual ~CLxImpl_PersistenceClient() = default;

    virtual auto cc_Setup([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cc_SyncRead([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cc_SyncWrite([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_PersistenceClient_Setup LxResult cc_Setup() override
#define LXxO_PersistenceClient_Setup LXxD_PersistenceClient_Setup
#define LXxC_PersistenceClient_Setup(c) LxResult c::cc_Setup()
#define LXxD_PersistenceClient_SyncRead LxResult cc_SyncRead() override
#define LXxO_PersistenceClient_SyncRead LXxD_PersistenceClient_SyncRead
#define LXxC_PersistenceClient_SyncRead(c) LxResult c::cc_SyncRead()
#define LXxD_PersistenceClient_SyncWrite LxResult cc_SyncWrite() override
#define LXxO_PersistenceClient_SyncWrite LXxD_PersistenceClient_SyncWrite
#define LXxC_PersistenceClient_SyncWrite(c) LxResult c::cc_SyncWrite()

template <class T>
class CLxIfc_PersistenceClient: public CLxInterface
{
public:
    CLxIfc_PersistenceClient()
    {
        vt.Setup = Setup;
        vt.SyncRead = SyncRead;
        vt.SyncWrite = SyncWrite;
        vTable = &vt.iunk;
        iid = &lx::guid_PersistenceClient;
    }

    static auto Setup(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_PersistenceClient, loc);
        try
        {
           return loc->cc_Setup();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SyncRead(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_PersistenceClient, loc);
        try
        {
           return loc->cc_SyncRead();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SyncWrite(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_PersistenceClient, loc);
        try
        {
           return loc->cc_SyncWrite();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxPersistenceClient vt;
};

class CLxLoc_PersistenceClient : public CLxLocalize<ILxPersistenceClientID>
{
public:
    CLxLoc_PersistenceClient()
    {
        _init();
    }

    CLxLoc_PersistenceClient(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_PersistenceClient(CLxLoc_PersistenceClient const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_PersistenceClient;
    }

    auto Setup(void) -> LxResult
    {
        return m_loc[0]->Setup(m_loc);
    }

    auto SyncRead(void) -> LxResult
    {
        return m_loc[0]->SyncRead(m_loc);
    }

    auto SyncWrite(void) -> LxResult
    {
        return m_loc[0]->SyncWrite(m_loc);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_PersistentEntry : public CLxLocalize<ILxPersistentEntryID>
{
public:
    CLxLoc_PersistentEntry()
    {
        _init();
    }

    CLxLoc_PersistentEntry(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_PersistentEntry(CLxLoc_PersistentEntry const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_PersistentEntry;
    }

    auto Count(unsigned int *count) -> LxResult
    {
        return m_loc[0]->Count(m_loc, count);
    }

    auto Select(unsigned int index) -> LxResult
    {
        return m_loc[0]->Select(m_loc, index);
    }

    auto Lookup(const char *key) -> LxResult
    {
        return m_loc[0]->Lookup(m_loc, key);
    }

    auto Append(void) -> LxResult
    {
        return m_loc[0]->Append(m_loc);
    }

    auto Insert(const char *key) -> LxResult
    {
        return m_loc[0]->Insert(m_loc, key);
    }

    auto Delete(void) -> LxResult
    {
        return m_loc[0]->Delete(m_loc);
    }

    auto Clear(void) -> LxResult
    {
        return m_loc[0]->Clear(m_loc);
    }

    auto Hash(const char **key) -> LxResult
    {
        return m_loc[0]->Hash(m_loc, key);
    }

    auto KeyValueFloat(const char *key, double *value) -> LxResult
    {
        return m_loc[0]->KeyValueFloat(m_loc, key, value);
    }

    auto SetKeyValueFloat(const char *key, double value) -> LxResult
    {
        return m_loc[0]->SetKeyValueFloat(m_loc, key, value);
    }

    auto KeyValueInt(const char *key, int *value) -> LxResult
    {
        return m_loc[0]->KeyValueInt(m_loc, key, value);
    }

    auto SetKeyValueInt(const char *key, int value) -> LxResult
    {
        return m_loc[0]->SetKeyValueInt(m_loc, key, value);
    }

    auto KeyValueString(const char *key, char *buf, int len) -> LxResult
    {
        return m_loc[0]->KeyValueString(m_loc, key, buf, len);
    }

    auto SetKeyValueString(const char *key, const char *value) -> LxResult
    {
        return m_loc[0]->SetKeyValueString(m_loc, key, value);
    }

    auto DeleteKeyValue(const char *key) -> LxResult
    {
        return m_loc[0]->DeleteKeyValue(m_loc, key);
    }

    auto ClearKeyValues(void) -> LxResult
    {
        return m_loc[0]->ClearKeyValues(m_loc);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
