//
// C++ wrapper for lxsdk/lxfile.h.
//
//	Copyright 2024.
//
//
#pragma once

#include <lxfile.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx
{
    static LXtGUID const guid_File1Service = {0xD792F5C0, {0x0555, 0x4FC7}, {0x83, 0x2C, 0xD2, 0x00, 0xCD, 0xA4, 0x2D, 0x97}};
    static LXtGUID const guid_VirtualDevice = {0x60B61E9D, {0x17F3, 0x4068}, {0x85, 0xC2, 0x37, 0x99, 0xA7, 0x3F, 0x5D, 0x95}};
    static LXtGUID const guid_FileService = {0x742B3D3D, {0x1151, 0x4AB7}, {0xAF, 0x4F, 0x66, 0x8D, 0x18, 0x46, 0x8D, 0x7F}};
    static LXtGUID const guid_FileReference = {0xA18B9A9D, {0x6623, 0x4463}, {0xB6, 0xAF, 0x46, 0x97, 0x71, 0xB4, 0x14, 0x85}};
    static LXtGUID const guid_FileRedirect = {0x05DACE30, {0xBFA0, 0x453C}, {0xAB, 0x7A, 0x33, 0xDF, 0x35, 0x82, 0x7A, 0x35}};
} // namespace lx


class CLxImpl_VirtualDevice
{
public:
    virtual ~CLxImpl_VirtualDevice() = default;

    virtual auto vdev_Initialize([[maybe_unused]] const char *path) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto vdev_Select([[maybe_unused]] const char *sub) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto vdev_Extract([[maybe_unused]] const char *dest) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto vdev_Scan([[maybe_unused]] ILxUnknownID visitor) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto vdev_Type([[maybe_unused]] unsigned *type) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto vdev_Name([[maybe_unused]] char *buf, [[maybe_unused]] unsigned len) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto vdev_Date([[maybe_unused]] char *buf, [[maybe_unused]] unsigned len) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto vdev_Size([[maybe_unused]] double *bytes) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_VirtualDevice_Initialize LxResult vdev_Initialize([[maybe_unused]] const char *path) override
#define LXxO_VirtualDevice_Initialize LXxD_VirtualDevice_Initialize
#define LXxC_VirtualDevice_Initialize(c) LxResult c::vdev_Initialize([[maybe_unused]] const char *path)
#define LXxD_VirtualDevice_Select LxResult vdev_Select([[maybe_unused]] const char *sub) override
#define LXxO_VirtualDevice_Select LXxD_VirtualDevice_Select
#define LXxC_VirtualDevice_Select(c) LxResult c::vdev_Select([[maybe_unused]] const char *sub)
#define LXxD_VirtualDevice_Extract LxResult vdev_Extract([[maybe_unused]] const char *dest) override
#define LXxO_VirtualDevice_Extract LXxD_VirtualDevice_Extract
#define LXxC_VirtualDevice_Extract(c) LxResult c::vdev_Extract([[maybe_unused]] const char *dest)
#define LXxD_VirtualDevice_Scan LxResult vdev_Scan([[maybe_unused]] ILxUnknownID visitor) override
#define LXxO_VirtualDevice_Scan LXxD_VirtualDevice_Scan
#define LXxC_VirtualDevice_Scan(c) LxResult c::vdev_Scan([[maybe_unused]] ILxUnknownID visitor)
#define LXxD_VirtualDevice_Type LxResult vdev_Type([[maybe_unused]] unsigned *type) override
#define LXxO_VirtualDevice_Type LXxD_VirtualDevice_Type
#define LXxC_VirtualDevice_Type(c) LxResult c::vdev_Type([[maybe_unused]] unsigned *type)
#define LXxD_VirtualDevice_Name LxResult vdev_Name([[maybe_unused]] char *buf, [[maybe_unused]] unsigned len) override
#define LXxO_VirtualDevice_Name LXxD_VirtualDevice_Name
#define LXxC_VirtualDevice_Name(c) LxResult c::vdev_Name([[maybe_unused]] char *buf, [[maybe_unused]] unsigned len)
#define LXxD_VirtualDevice_Date LxResult vdev_Date([[maybe_unused]] char *buf, [[maybe_unused]] unsigned len) override
#define LXxO_VirtualDevice_Date LXxD_VirtualDevice_Date
#define LXxC_VirtualDevice_Date(c) LxResult c::vdev_Date([[maybe_unused]] char *buf, [[maybe_unused]] unsigned len)
#define LXxD_VirtualDevice_Size LxResult vdev_Size([[maybe_unused]] double *bytes) override
#define LXxO_VirtualDevice_Size LXxD_VirtualDevice_Size
#define LXxC_VirtualDevice_Size(c) LxResult c::vdev_Size([[maybe_unused]] double *bytes)

template <class T>
class CLxIfc_VirtualDevice: public CLxInterface
{
public:
    CLxIfc_VirtualDevice()
    {
        vt.Initialize = Initialize;
        vt.Select = Select;
        vt.Extract = Extract;
        vt.Scan = Scan;
        vt.Type = Type;
        vt.Name = Name;
        vt.Date = Date;
        vt.Size = Size;
        vTable = &vt.iunk;
        iid = &lx::guid_VirtualDevice;
    }

    static auto Initialize(LXtObjectID wcom,const char *path) -> LxResult
    {
        LXCWxINST (CLxImpl_VirtualDevice, loc);
        try
        {
           return loc->vdev_Initialize( path);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Select(LXtObjectID wcom,const char *sub) -> LxResult
    {
        LXCWxINST (CLxImpl_VirtualDevice, loc);
        try
        {
           return loc->vdev_Select( sub);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Extract(LXtObjectID wcom,const char *dest) -> LxResult
    {
        LXCWxINST (CLxImpl_VirtualDevice, loc);
        try
        {
           return loc->vdev_Extract( dest);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Scan(LXtObjectID wcom,LXtObjectID visitor) -> LxResult
    {
        LXCWxINST (CLxImpl_VirtualDevice, loc);
        try
        {
           return loc->vdev_Scan((ILxUnknownID) visitor);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Type(LXtObjectID wcom,unsigned *type) -> LxResult
    {
        LXCWxINST (CLxImpl_VirtualDevice, loc);
        try
        {
           return loc->vdev_Type( type);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Name(LXtObjectID wcom,char *buf,unsigned len) -> LxResult
    {
        LXCWxINST (CLxImpl_VirtualDevice, loc);
        try
        {
           return loc->vdev_Name( buf, len);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Date(LXtObjectID wcom,char *buf,unsigned len) -> LxResult
    {
        LXCWxINST (CLxImpl_VirtualDevice, loc);
        try
        {
           return loc->vdev_Date( buf, len);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Size(LXtObjectID wcom,double *bytes) -> LxResult
    {
        LXCWxINST (CLxImpl_VirtualDevice, loc);
        try
        {
           return loc->vdev_Size( bytes);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxVirtualDevice vt;
};

class CLxLoc_VirtualDevice : public CLxLocalize<ILxVirtualDeviceID>
{
public:
    CLxLoc_VirtualDevice()
    {
        _init();
    }

    CLxLoc_VirtualDevice(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_VirtualDevice(CLxLoc_VirtualDevice const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_VirtualDevice;
    }

    auto Initialize(const char *path) -> LxResult
    {
        return m_loc[0]->Initialize(m_loc, path);
    }

    auto Select(const char *sub) -> LxResult
    {
        return m_loc[0]->Select(m_loc, sub);
    }

    auto Extract(const char *dest) -> LxResult
    {
        return m_loc[0]->Extract(m_loc, dest);
    }

    auto Scan(ILxUnknownID visitor) -> LxResult
    {
        return m_loc[0]->Scan(m_loc,(ILxUnknownID) visitor);
    }

    auto Type(unsigned *type) -> LxResult
    {
        return m_loc[0]->Type(m_loc, type);
    }

    auto Name(char *buf, unsigned len) -> LxResult
    {
        return m_loc[0]->Name(m_loc, buf, len);
    }

    auto Name(std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->Name(m_loc, buf, len);
        LXWx_SBUF2
    }

    auto Date(char *buf, unsigned len) -> LxResult
    {
        return m_loc[0]->Date(m_loc, buf, len);
    }

    auto Date(std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->Date(m_loc, buf, len);
        LXWx_SBUF2
    }

    auto Size(double *bytes) -> LxResult
    {
        return m_loc[0]->Size(m_loc, bytes);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_FileService : public CLxLocalizedService
{
public:
    ILxFileServiceID m_loc{ nullptr };

public:
    CLxLoc_FileService()
    {
        _init();
        set();
    }

    ~CLxLoc_FileService() = default;

    void set()
    {
        if (!m_loc)
        {
            m_loc = reinterpret_cast<ILxFileServiceID>(lx::GetGlobal(&lx::guid_FileService));
        }
    }

    auto FileSystemPath(const char *name, const char **path) -> LxResult
    {
        return m_loc[0]->FileSystemPath(m_loc, name, path);
    }

    auto IsAbsolutePath(const char *path) -> LxResult
    {
        return m_loc[0]->IsAbsolutePath(m_loc, path);
    }

    auto ArePathsEqual(const char *path1, const char *path2) -> LxResult
    {
        return m_loc[0]->ArePathsEqual(m_loc, path1, path2);
    }

    auto ParsePath(const char *filename, unsigned component, char *buf, unsigned len) -> LxResult
    {
        return m_loc[0]->ParsePath(m_loc, filename, component, buf, len);
    }

    auto ParsePath(const char *filename, unsigned component, std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->ParsePath(m_loc, filename, component, buf, len);
        LXWx_SBUF2
    }

    auto ComposePath(const char *basename, const char *path, char *buf, unsigned len) -> LxResult
    {
        return m_loc[0]->ComposePath(m_loc, basename, path, buf, len);
    }

    auto ComposePath(const char *basename, const char *path, std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->ComposePath(m_loc, basename, path, buf, len);
        LXWx_SBUF2
    }

    auto SetExtension(const char *filename, const char *extension, char *buf, unsigned len) -> LxResult
    {
        return m_loc[0]->SetExtension(m_loc, filename, extension, buf, len);
    }

    auto SetExtension(const char *filename, const char *extension, std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->SetExtension(m_loc, filename, extension, buf, len);
        LXWx_SBUF2
    }

    auto MakeRelative(const char *filename, const char *path, char *buf, unsigned len) -> LxResult
    {
        return m_loc[0]->MakeRelative(m_loc, filename, path, buf, len);
    }

    auto MakeRelative(const char *filename, const char *path, std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->MakeRelative(m_loc, filename, path, buf, len);
        LXWx_SBUF2
    }

    auto MakeUnique(const char *filename, char *buf, unsigned len) -> LxResult
    {
        return m_loc[0]->MakeUnique(m_loc, filename, buf, len);
    }

    auto MakeUnique(const char *filename, std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->MakeUnique(m_loc, filename, buf, len);
        LXWx_SBUF2
    }

    auto MakeDirectory(const char *path) -> LxResult
    {
        return m_loc[0]->MakeDirectory(m_loc, path);
    }

    auto TestFileType(const char *filename, unsigned *type) -> LxResult
    {
        return m_loc[0]->TestFileType(m_loc, filename, type);
    }

    auto TestFileMode(const char *filename, unsigned *mode) -> LxResult
    {
        return m_loc[0]->TestFileMode(m_loc, filename, mode);
    }

    auto RenameFile(const char *from, const char *to) -> LxResult
    {
        return m_loc[0]->RenameFile(m_loc, from, to);
    }

    auto FileCopy(const char *srcFilePath, const char *dstFilePath, unsigned overwrite) -> LxResult
    {
        return m_loc[0]->FileCopy(m_loc, srcFilePath, dstFilePath, overwrite);
    }

    auto FileDelete(const char *filename) -> LxResult
    {
        return m_loc[0]->FileDelete(m_loc, filename);
    }

    auto DirDelete(const char *filename) -> LxResult
    {
        return m_loc[0]->DirDelete(m_loc, filename);
    }

    auto OpenFileWithDefaultApp(const char *filename) -> LxResult
    {
        return m_loc[0]->OpenFileWithDefaultApp(m_loc, filename);
    }

    auto RevealInFileViewer(const char *filename) -> LxResult
    {
        return m_loc[0]->RevealInFileViewer(m_loc, filename);
    }

    auto Execute(const char **argv, int show, int force32) -> LxResult
    {
        return m_loc[0]->Execute(m_loc, argv, show, force32);
    }

    auto FileToURL(const char *filename, char *buf, unsigned len) -> LxResult
    {
        return m_loc[0]->FileToURL(m_loc, filename, buf, len);
    }

    auto FileToURL(const char *filename, std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->FileToURL(m_loc, filename, buf, len);
        LXWx_SBUF2
    }

    auto FileFromURL(const char *url, char *buf, unsigned len) -> LxResult
    {
        return m_loc[0]->FileFromURL(m_loc, url, buf, len);
    }

    auto FileFromURL(const char *url, std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->FileFromURL(m_loc, url, buf, len);
        LXWx_SBUF2
    }

    auto FromLocal(const char *local, char *buf, unsigned len) -> LxResult
    {
        return m_loc[0]->FromLocal(m_loc, local, buf, len);
    }

    auto FromLocal(const char *local, std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->FromLocal(m_loc, local, buf, len);
        LXWx_SBUF2
    }

    auto ToLocal(char *neutral, char *buf, unsigned len) -> LxResult
    {
        return m_loc[0]->ToLocal(m_loc, neutral, buf, len);
    }

    auto ToLocal(char *neutral, std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->ToLocal(m_loc, neutral, buf, len);
        LXWx_SBUF2
    }

    auto ToLocalAlias(const char *neutral, char *buf, unsigned len) -> LxResult
    {
        return m_loc[0]->ToLocalAlias(m_loc, neutral, buf, len);
    }

    auto ToLocalAlias(const char *neutral, std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->ToLocalAlias(m_loc, neutral, buf, len);
        LXWx_SBUF2
    }

    auto AllocReference(const char *path, void **ppvObj) -> LxResult
    {
        return m_loc[0]->AllocReference(m_loc, path, ppvObj);
    }

    auto AllocReference(const char *path, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->AllocReference(m_loc, path, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto FindSequencePattern(const char *filename, char *buf, unsigned len) -> LxResult
    {
        return m_loc[0]->FindSequencePattern(m_loc, filename, buf, len);
    }

    auto FindSequencePattern(const char *filename, std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->FindSequencePattern(m_loc, filename, buf, len);
        LXWx_SBUF2
    }

    auto FindSequenceBounds(const char *pattern, unsigned *first, unsigned *last) -> LxResult
    {
        return m_loc[0]->FindSequenceBounds(m_loc, pattern, first, last);
    }

    auto GenerateSequenceName(const char *pattern, unsigned frame, char *buf, unsigned len) -> LxResult
    {
        return m_loc[0]->GenerateSequenceName(m_loc, pattern, frame, buf, len);
    }

    auto GenerateSequenceName(const char *pattern, unsigned frame, std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->GenerateSequenceName(m_loc, pattern, frame, buf, len);
        LXWx_SBUF2
    }

    auto ValidateLicense(const char *product, int versionNum) -> LxResult
    {
        return m_loc[0]->ValidateLicense(m_loc, product, versionNum);
    }

    auto FileDateString(const char *filename, char *buf, int len) -> LxResult
    {
        return m_loc[0]->FileDateString(m_loc, filename, buf, len);
    }

    auto AllocRedirect(void **ppvObj) -> LxResult
    {
        return m_loc[0]->AllocRedirect(m_loc, ppvObj);
    }

    auto AllocRedirect(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->AllocRedirect(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto MakeLegalFilename(char *filename, int replaceDot) -> LxResult
    {
        return m_loc[0]->MakeLegalFilename(m_loc, filename, replaceDot);
    }

    auto PkgCountFiles(const char *package) -> unsigned
    {
        return m_loc[0]->PkgCountFiles(m_loc, package);
    }

    auto PkgFilename(const char *package, unsigned id, char *buf, int len) -> LxResult
    {
        return m_loc[0]->PkgFilename(m_loc, package, id, buf, len);
    }

    auto PkgHasFile(const char *package, const char *file) -> LxResult
    {
        return m_loc[0]->PkgHasFile(m_loc, package, file);
    }

    auto PkgExtract(const char *package, const char *file, const char *dest) -> LxResult
    {
        return m_loc[0]->PkgExtract(m_loc, package, file, dest);
    }

    auto PkgExtractAll(const char *package, const char *dest, const char *subDir) -> LxResult
    {
        return m_loc[0]->PkgExtractAll(m_loc, package, dest, subDir);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_FileReference : public CLxLocalize<ILxFileReferenceID>
{
public:
    CLxLoc_FileReference()
    {
        _init();
    }

    CLxLoc_FileReference(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_FileReference(CLxLoc_FileReference const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_FileReference;
    }

    auto Path(const char **path) -> LxResult
    {
        return m_loc[0]->Path(m_loc, path);
    }

    auto NiceName(char *buf, unsigned len) -> LxResult
    {
        return m_loc[0]->NiceName(m_loc, buf, len);
    }

    auto NiceName(std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->NiceName(m_loc, buf, len);
        LXWx_SBUF2
    }

    auto Type(unsigned *type) -> LxResult
    {
        return m_loc[0]->Type(m_loc, type);
    }

    auto Mode(unsigned *mode) -> LxResult
    {
        return m_loc[0]->Mode(m_loc, mode);
    }

    auto SubCount(unsigned *count) -> LxResult
    {
        return m_loc[0]->SubCount(m_loc, count);
    }

    auto SubByIndex(unsigned index, void **ppvObj) -> LxResult
    {
        return m_loc[0]->SubByIndex(m_loc, index, ppvObj);
    }

    auto SubByIndex(unsigned index, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->SubByIndex(m_loc, index, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_FileRedirect : public CLxLocalize<ILxFileRedirectID>
{
public:
    CLxLoc_FileRedirect()
    {
        _init();
    }

    CLxLoc_FileRedirect(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_FileRedirect(CLxLoc_FileRedirect const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_FileRedirect;
    }

    auto NeutralFormat(unsigned allow) -> LxResult
    {
        return m_loc[0]->NeutralFormat(m_loc, allow);
    }

    auto AddSearchPath(const char *path) -> LxResult
    {
        return m_loc[0]->AddSearchPath(m_loc, path);
    }

    auto Locate(const char *path, const char *type, char *buf, unsigned len) -> LxResult
    {
        return m_loc[0]->Locate(m_loc, path, type, buf, len);
    }

    auto Locate(const char *path, const char *type, std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->Locate(m_loc, path, type, buf, len);
        LXWx_SBUF2
    }

    auto LocateSequence(const char *pattern, const char *type, unsigned *first, unsigned *last, char *buf, unsigned len) -> LxResult
    {
        return m_loc[0]->LocateSequence(m_loc, pattern, type, first, last, buf, len);
    }

    auto LocateSequence(const char *pattern, const char *type, unsigned *first, unsigned *last, std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->LocateSequence(m_loc, pattern, type, first, last, buf, len);
        LXWx_SBUF2
    }

    auto Reference(const char *path, char *buf, unsigned len) -> LxResult
    {
        return m_loc[0]->Reference(m_loc, path, buf, len);
    }

    auto Reference(const char *path, std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->Reference(m_loc, path, buf, len);
        LXWx_SBUF2
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
