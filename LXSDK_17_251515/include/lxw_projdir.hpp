//
// C++ wrapper for lxsdk/lxprojdir.h.
//
//	Copyright 2024.
//
//
#pragma once

#include <lxprojdir.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx
{
    static LXtGUID const guid_ProjDirOverride = {0x257bac48, {0x5e70, 0x42a3}, {0xb5, 0xa4, 0x7e, 0xb3, 0x3f, 0xdb, 0xa1, 0x14}};
} // namespace lx

class CLxImpl_ProjDirOverride
{
public:
    virtual ~CLxImpl_ProjDirOverride() = default;

    virtual auto pdo_OverrideWith([[maybe_unused]] const char *originalPath, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_ProjDirOverride_OverrideWith LxResult pdo_OverrideWith([[maybe_unused]] const char *originalPath, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len) override
#define LXxO_ProjDirOverride_OverrideWith LXxD_ProjDirOverride_OverrideWith
#define LXxC_ProjDirOverride_OverrideWith(c) LxResult c::pdo_OverrideWith([[maybe_unused]] const char *originalPath, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len)

template <class T>
class CLxIfc_ProjDirOverride: public CLxInterface
{
public:
    CLxIfc_ProjDirOverride()
    {
        vt.OverrideWith = OverrideWith;
        vTable = &vt.iunk;
        iid = &lx::guid_ProjDirOverride;
    }

    static auto OverrideWith(LXtObjectID wcom,const char *originalPath,char *buf,unsigned len) -> LxResult
    {
        LXCWxINST (CLxImpl_ProjDirOverride, loc);
        try
        {
           return loc->pdo_OverrideWith( originalPath, buf, len);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxProjDirOverride vt;
};

class CLxLoc_ProjDirOverride : public CLxLocalize<ILxProjDirOverrideID>
{
public:
    CLxLoc_ProjDirOverride()
    {
        _init();
    }

    CLxLoc_ProjDirOverride(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_ProjDirOverride(CLxLoc_ProjDirOverride const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_ProjDirOverride;
    }

    auto OverrideWith(const char *originalPath, char *buf, unsigned len) -> LxResult
    {
        return m_loc[0]->OverrideWith(m_loc, originalPath, buf, len);
    }

    auto OverrideWith(const char *originalPath, std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->OverrideWith(m_loc, originalPath, buf, len);
        LXWx_SBUF2
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
