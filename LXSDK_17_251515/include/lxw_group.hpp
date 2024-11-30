//
// C++ wrapper for lxsdk/lxgroup.h.
//
//	Copyright 2024.
//
//
#pragma once

#include <lxgroup.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx
{
    static LXtGUID const guid_GroupItem = {0x47FDFD87, {0x3FBA, 0x41A4}, {0x80, 0x44, 0x74, 0xEC, 0x9D, 0x9A, 0xA9, 0x86}};
    static LXtGUID const guid_GroupEnumerator = {0xCA4E1FE0, {0xB655, 0x429F}, {0x96, 0x74, 0x3E, 0x1D, 0x7D, 0xEA, 0x5D, 0x04}};
    static LXtGUID const guid_PresetPackageService = {0xb37c7c4d, {0xe91f, 0x406b}, {0xa8, 0x0b, 0x8d, 0x76, 0x1a, 0x62, 0x30, 0x88}};
} // namespace lx

class CLxLoc_GroupItem : public CLxLocalize<ILxGroupItemID>
{
public:
    CLxLoc_GroupItem()
    {
        _init();
    }

    CLxLoc_GroupItem(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_GroupItem(CLxLoc_GroupItem const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_GroupItem;
    }

    auto Enumerator(void **ppvObj) -> LxResult
    {
        return m_loc[0]->Enumerator(m_loc, ppvObj);
    }

    auto Enumerator(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Enumerator(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Type(int *type) -> LxResult
    {
        return m_loc[0]->Type(m_loc, type);
    }

    auto SetType(int type) -> LxResult
    {
        return m_loc[0]->SetType(m_loc, type);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_GroupEnumerator : public CLxLocalize<ILxGroupEnumeratorID>
{
public:
    CLxLoc_GroupEnumerator()
    {
        _init();
    }

    CLxLoc_GroupEnumerator(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_GroupEnumerator(CLxLoc_GroupEnumerator const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_GroupEnumerator;
    }

    auto Enumerate(ILxUnknownID visitor, unsigned mask) -> LxResult
    {
        return m_loc[0]->Enumerate(m_loc,(ILxUnknownID) visitor, mask);
    }

    auto Type(void) -> unsigned
    {
        return m_loc[0]->Type(m_loc);
    }

    auto Item(void **ppvObj) -> LxResult
    {
        return m_loc[0]->Item(m_loc, ppvObj);
    }

    auto Item(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Item(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Channel(void **ppvObj, unsigned *index) -> LxResult
    {
        return m_loc[0]->Channel(m_loc, ppvObj, index);
    }

    auto Channel(CLxLocalizedObject &o_dest, unsigned *index) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Channel(m_loc, &o_obj, index);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_PresetPackageService : public CLxLocalizedService
{
public:
    ILxPresetPackageServiceID m_loc{ nullptr };

public:
    CLxLoc_PresetPackageService()
    {
        _init();
        set();
    }

    ~CLxLoc_PresetPackageService() = default;

    void set()
    {
        if (!m_loc)
        {
            m_loc = reinterpret_cast<ILxPresetPackageServiceID>(lx::GetGlobal(&lx::guid_PresetPackageService));
        }
    }

    auto Version(const char *pkg) -> const char*
    {
        return m_loc[0]->Version(m_loc, pkg);
    }

    auto UserVersion(const char *pkg) -> const char*
    {
        return m_loc[0]->UserVersion(m_loc, pkg);
    }

    auto Type(const char *pkg) -> const char*
    {
        return m_loc[0]->Type(m_loc, pkg);
    }

    auto AssemblyType(const char *pkg) -> unsigned
    {
        return m_loc[0]->AssemblyType(m_loc, pkg);
    }

    auto CountFiles(const char *pkg) -> unsigned
    {
        return m_loc[0]->CountFiles(m_loc, pkg);
    }

    auto Filename(const char *pkg, unsigned id, char *buf, int len) -> LxResult
    {
        return m_loc[0]->Filename(m_loc, pkg, id, buf, len);
    }

    auto HasFile(const char *pkg, const char *file) -> LxResult
    {
        return m_loc[0]->HasFile(m_loc, pkg, file);
    }

    auto Extract(const char *pkg, const char *file, const char *dest) -> LxResult
    {
        return m_loc[0]->Extract(m_loc, pkg, file, dest);
    }

    auto ExtractAll(const char *pkg, const char *dest, const char *subDir) -> LxResult
    {
        return m_loc[0]->ExtractAll(m_loc, pkg, dest, subDir);
    }

    auto AddFile(const char *pkg, const char *filename, const char *filepath) -> LxResult
    {
        return m_loc[0]->AddFile(m_loc, pkg, filename, filepath);
    }

    auto RemoveFile(const char *pkg, const char *filename) -> LxResult
    {
        return m_loc[0]->RemoveFile(m_loc, pkg, filename);
    }

    auto ReplaceFile(const char *pkg, const char *filename, const char *filepath) -> LxResult
    {
        return m_loc[0]->ReplaceFile(m_loc, pkg, filename, filepath);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
