//
// C++ wrapper for lxsdk/lxio.h.
//
//	Copyright 2024.
//
//
#pragma once

#include <lxio.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx
{
    static LXtGUID const guid_BlockRead = {0x36A00A47, {0x2664, 0x49E0}, {0xBA, 0xFF, 0x26, 0x3E, 0x63, 0x85, 0x32, 0xB5}};
    static LXtGUID const guid_BlockWrite = {0xADE569E1, {0xE9A1, 0x4AD6}, {0xB6, 0x25, 0x63, 0x40, 0x93, 0x66, 0x09, 0x65}};
    static LXtGUID const guid_Loader = {0x7711F608, {0xB8FF, 0x48BF}, {0x81, 0xED, 0xCE, 0xBD, 0xE5, 0x4D, 0x34, 0xDE}};
    static LXtGUID const guid_LoaderInfo = {0x4CA8BE1A, {0x6ADE, 0x4F93}, {0x99, 0xF6, 0x1F, 0x0E, 0xFC, 0x8A, 0x58, 0x1E}};
    static LXtGUID const guid_Saver = {0x75AD8F36, {0x5B69, 0x413b}, {0xA7, 0x7B, 0x5A, 0x78, 0xD3, 0x9A, 0xEF, 0x51}};
    static LXtGUID const guid_Monitor = {0x2B514D4C, {0x5142, 0x4687}, {0xBC, 0xEF, 0xB0, 0xFD, 0x44, 0xA3, 0x31, 0x46}};
    static LXtGUID const guid_StreamIO = {0x2884D6EE, {0x4BA7, 0x46D6}, {0xA7, 0x76, 0x8E, 0xE2, 0x2C, 0x9F, 0xD4, 0x14}};
    static LXtGUID const guid_IOService = {0x9970CCAD, {0x7322, 0x4CD6}, {0xA6, 0xBA, 0x96, 0x3A, 0x63, 0xDE, 0x57, 0xD7}};
    static LXtGUID const guid_BlockStore = {0x9094E95E, {0xE91E, 0x42AE}, {0xAB, 0xD6, 0x84, 0x26, 0xCC, 0x0A, 0xE4, 0x2A}};
    static LXtGUID const guid_Loader1 = {0x73333A41, {0x3C0A, 0x4B0E}, {0xA7, 0xC5, 0xD7, 0x66, 0x09, 0x82, 0x7A, 0x2D}};
} // namespace lx

class CLxLoc_BlockRead : public CLxLocalize<ILxBlockReadID>
{
public:
    CLxLoc_BlockRead()
    {
        _init();
    }

    CLxLoc_BlockRead(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_BlockRead(CLxLoc_BlockRead const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_BlockRead;
    }

    auto FindBlock(const LXtBlockHeader *head, int flags, LXtID4 *blkId) -> LxResult
    {
        return m_loc[0]->FindBlock(m_loc, head, flags, blkId);
    }

    auto End(void) -> void
    {
        m_loc[0]->End(m_loc);
    }

    auto Depth(void) -> int
    {
        return m_loc[0]->Depth(m_loc);
    }

    auto ReadI1(char *data, int count, int *ocount) -> LxResult
    {
        return m_loc[0]->ReadI1(m_loc, data, count, ocount);
    }

    auto ReadI2(short *data, int count, int *ocount) -> LxResult
    {
        return m_loc[0]->ReadI2(m_loc, data, count, ocount);
    }

    auto ReadI4(int *data, int count, int *ocount) -> LxResult
    {
        return m_loc[0]->ReadI4(m_loc, data, count, ocount);
    }

    auto ReadU1(unsigned char *data, int count, int *ocount) -> LxResult
    {
        return m_loc[0]->ReadU1(m_loc, data, count, ocount);
    }

    auto ReadU2(unsigned short *data, int count, int *ocount) -> LxResult
    {
        return m_loc[0]->ReadU2(m_loc, data, count, ocount);
    }

    auto ReadU4(unsigned int *data, int count, int *ocount) -> LxResult
    {
        return m_loc[0]->ReadU4(m_loc, data, count, ocount);
    }

    auto ReadFP(float *data, int count, int *ocount) -> LxResult
    {
        return m_loc[0]->ReadFP(m_loc, data, count, ocount);
    }

    auto ReadFP8(double *data, int count, int *ocount) -> LxResult
    {
        return m_loc[0]->ReadFP8(m_loc, data, count, ocount);
    }

    auto ReadString(char *buf, int max, int flags, int *ocount) -> LxResult
    {
        return m_loc[0]->ReadString(m_loc, buf, max, flags, ocount);
    }

    auto ReadIDCode(const LXtBlockHeader *list, LXtID4 *idCode) -> LxResult
    {
        return m_loc[0]->ReadIDCode(m_loc, list, idCode);
    }

    auto ReadVX(unsigned *data, int count, int *ocount) -> LxResult
    {
        return m_loc[0]->ReadVX(m_loc, data, count, ocount);
    }

    auto SetSourceEncoding(unsigned encoding) -> LxResult
    {
        return m_loc[0]->SetSourceEncoding(m_loc, encoding);
    }

    auto SetTargetEncoding(unsigned encoding) -> LxResult
    {
        return m_loc[0]->SetTargetEncoding(m_loc, encoding);
    }

    auto SetMiniBlockHeight(unsigned mini) -> LxResult
    {
        return m_loc[0]->SetMiniBlockHeight(m_loc, mini);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_BlockWrite : public CLxLocalize<ILxBlockWriteID>
{
public:
    CLxLoc_BlockWrite()
    {
        _init();
    }

    CLxLoc_BlockWrite(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_BlockWrite(CLxLoc_BlockWrite const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_BlockWrite;
    }

    auto WriteBlock(const LXtBlockHeader *head, int flags) -> LxResult
    {
        return m_loc[0]->WriteBlock(m_loc, head, flags);
    }

    auto End(void) -> void
    {
        m_loc[0]->End(m_loc);
    }

    auto Depth(void) -> int
    {
        return m_loc[0]->Depth(m_loc);
    }

    auto WriteI1(const char *data, int count) -> LxResult
    {
        return m_loc[0]->WriteI1(m_loc, data, count);
    }

    auto WriteI2(const short *data, int count) -> LxResult
    {
        return m_loc[0]->WriteI2(m_loc, data, count);
    }

    auto WriteI4(const int *data, int count) -> LxResult
    {
        return m_loc[0]->WriteI4(m_loc, data, count);
    }

    auto WriteU1(const unsigned char *data, int count) -> LxResult
    {
        return m_loc[0]->WriteU1(m_loc, data, count);
    }

    auto WriteU2(const unsigned short *data, int count) -> LxResult
    {
        return m_loc[0]->WriteU2(m_loc, data, count);
    }

    auto WriteU4(const unsigned int *data, int count) -> LxResult
    {
        return m_loc[0]->WriteU4(m_loc, data, count);
    }

    auto WriteFP(const float *data, int count) -> LxResult
    {
        return m_loc[0]->WriteFP(m_loc, data, count);
    }

    auto WriteFP8(const double *data, int count) -> LxResult
    {
        return m_loc[0]->WriteFP8(m_loc, data, count);
    }

    auto WriteString(const char *str) -> LxResult
    {
        return m_loc[0]->WriteString(m_loc, str);
    }

    auto WriteIDCode(const LXtBlockHeader *ident) -> LxResult
    {
        return m_loc[0]->WriteIDCode(m_loc, ident);
    }

    auto WriteVX(const unsigned int *data, int count) -> LxResult
    {
        return m_loc[0]->WriteVX(m_loc, data, count);
    }

    auto SetSourceEncoding(unsigned encoding) -> LxResult
    {
        return m_loc[0]->SetSourceEncoding(m_loc, encoding);
    }

    auto SetTargetEncoding(unsigned encoding) -> LxResult
    {
        return m_loc[0]->SetTargetEncoding(m_loc, encoding);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_Loader
{
public:
    virtual ~CLxImpl_Loader() = default;

    virtual auto load_Recognize([[maybe_unused]] const char *filename, [[maybe_unused]] ILxUnknownID loadInfo) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto load_LoadInstance([[maybe_unused]] ILxUnknownID loadInfo, [[maybe_unused]] ILxUnknownID monitor, [[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto load_LoadObject([[maybe_unused]] ILxUnknownID loadInfo, [[maybe_unused]] ILxUnknownID monitor, [[maybe_unused]] ILxUnknownID dest) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual void load_Cleanup([[maybe_unused]] void)
    {
    }

    virtual auto load_SpawnOptions([[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_Loader_Recognize LxResult load_Recognize([[maybe_unused]] const char *filename, [[maybe_unused]] ILxUnknownID loadInfo) override
#define LXxO_Loader_Recognize LXxD_Loader_Recognize
#define LXxC_Loader_Recognize(c) LxResult c::load_Recognize([[maybe_unused]] const char *filename, [[maybe_unused]] ILxUnknownID loadInfo)
#define LXxD_Loader_LoadInstance LxResult load_LoadInstance([[maybe_unused]] ILxUnknownID loadInfo, [[maybe_unused]] ILxUnknownID monitor, [[maybe_unused]] void **ppvObj) override
#define LXxO_Loader_LoadInstance LXxD_Loader_LoadInstance
#define LXxC_Loader_LoadInstance(c) LxResult c::load_LoadInstance([[maybe_unused]] ILxUnknownID loadInfo, [[maybe_unused]] ILxUnknownID monitor, [[maybe_unused]] void **ppvObj)
#define LXxD_Loader_LoadObject LxResult load_LoadObject([[maybe_unused]] ILxUnknownID loadInfo, [[maybe_unused]] ILxUnknownID monitor, [[maybe_unused]] ILxUnknownID dest) override
#define LXxO_Loader_LoadObject LXxD_Loader_LoadObject
#define LXxC_Loader_LoadObject(c) LxResult c::load_LoadObject([[maybe_unused]] ILxUnknownID loadInfo, [[maybe_unused]] ILxUnknownID monitor, [[maybe_unused]] ILxUnknownID dest)
#define LXxD_Loader_Cleanup void load_Cleanup() override
#define LXxO_Loader_Cleanup LXxD_Loader_Cleanup
#define LXxC_Loader_Cleanup(c) void c::load_Cleanup()
#define LXxD_Loader_SpawnOptions LxResult load_SpawnOptions([[maybe_unused]] void **ppvObj) override
#define LXxO_Loader_SpawnOptions LXxD_Loader_SpawnOptions
#define LXxC_Loader_SpawnOptions(c) LxResult c::load_SpawnOptions([[maybe_unused]] void **ppvObj)

template <class T>
class CLxIfc_Loader: public CLxInterface
{
public:
    CLxIfc_Loader()
    {
        vt.Recognize = Recognize;
        vt.LoadInstance = LoadInstance;
        vt.LoadObject = LoadObject;
        vt.Cleanup = Cleanup;
        vt.SpawnOptions = SpawnOptions;
        vTable = &vt.iunk;
        iid = &lx::guid_Loader;
    }

    static auto Recognize(LXtObjectID wcom,const char *filename,LXtObjectID loadInfo) -> LxResult
    {
        LXCWxINST (CLxImpl_Loader, loc);
        try
        {
           return loc->load_Recognize( filename,(ILxUnknownID) loadInfo);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto LoadInstance(LXtObjectID wcom,LXtObjectID loadInfo,LXtObjectID monitor,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_Loader, loc);
        try
        {
           return loc->load_LoadInstance((ILxUnknownID) loadInfo,(ILxUnknownID) monitor, ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto LoadObject(LXtObjectID wcom,LXtObjectID loadInfo,LXtObjectID monitor,LXtObjectID dest) -> LxResult
    {
        LXCWxINST (CLxImpl_Loader, loc);
        try
        {
           return loc->load_LoadObject((ILxUnknownID) loadInfo,(ILxUnknownID) monitor,(ILxUnknownID) dest);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Cleanup(LXtObjectID wcom) -> void
    {
        LXCWxINST (CLxImpl_Loader, loc);
        loc->load_Cleanup();
    }

    static auto SpawnOptions(LXtObjectID wcom,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_Loader, loc);
        try
        {
           return loc->load_SpawnOptions( ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxLoader vt;
};

class CLxLoc_Loader : public CLxLocalize<ILxLoaderID>
{
public:
    CLxLoc_Loader()
    {
        _init();
    }

    CLxLoc_Loader(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_Loader(CLxLoc_Loader const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_Loader;
    }

    auto Recognize(const char *filename, ILxUnknownID loadInfo) -> LxResult
    {
        return m_loc[0]->Recognize(m_loc, filename,(ILxUnknownID) loadInfo);
    }

    auto LoadInstance(ILxUnknownID loadInfo, ILxUnknownID monitor, void **ppvObj) -> LxResult
    {
        return m_loc[0]->LoadInstance(m_loc,(ILxUnknownID) loadInfo,(ILxUnknownID) monitor, ppvObj);
    }

    auto LoadInstance(ILxUnknownID loadInfo, ILxUnknownID monitor, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->LoadInstance(m_loc,(ILxUnknownID) loadInfo,(ILxUnknownID) monitor, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto LoadObject(ILxUnknownID loadInfo, ILxUnknownID monitor, ILxUnknownID dest) -> LxResult
    {
        return m_loc[0]->LoadObject(m_loc,(ILxUnknownID) loadInfo,(ILxUnknownID) monitor,(ILxUnknownID) dest);
    }

    auto Cleanup(void) -> void
    {
        m_loc[0]->Cleanup(m_loc);
    }

    auto SpawnOptions(void **ppvObj) -> LxResult
    {
        return m_loc[0]->SpawnOptions(m_loc, ppvObj);
    }

    auto SpawnOptions(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->SpawnOptions(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_LoaderInfo
{
public:
    virtual ~CLxImpl_LoaderInfo() = default;

    virtual auto linf_TestClass([[maybe_unused]] const LXtGUID *clsGUID, [[maybe_unused]] unsigned *priority) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto linf_SetClass([[maybe_unused]] const LXtGUID *clsGUID) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto linf_SetFlags([[maybe_unused]] unsigned flags) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto linf_SetFormat([[maybe_unused]] const char *format) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_LoaderInfo_TestClass LxResult linf_TestClass([[maybe_unused]] const LXtGUID *clsGUID, [[maybe_unused]] unsigned *priority) override
#define LXxO_LoaderInfo_TestClass LXxD_LoaderInfo_TestClass
#define LXxC_LoaderInfo_TestClass(c) LxResult c::linf_TestClass([[maybe_unused]] const LXtGUID *clsGUID, [[maybe_unused]] unsigned *priority)
#define LXxD_LoaderInfo_SetClass LxResult linf_SetClass([[maybe_unused]] const LXtGUID *clsGUID) override
#define LXxO_LoaderInfo_SetClass LXxD_LoaderInfo_SetClass
#define LXxC_LoaderInfo_SetClass(c) LxResult c::linf_SetClass([[maybe_unused]] const LXtGUID *clsGUID)
#define LXxD_LoaderInfo_SetFlags LxResult linf_SetFlags([[maybe_unused]] unsigned flags) override
#define LXxO_LoaderInfo_SetFlags LXxD_LoaderInfo_SetFlags
#define LXxC_LoaderInfo_SetFlags(c) LxResult c::linf_SetFlags([[maybe_unused]] unsigned flags)
#define LXxD_LoaderInfo_SetFormat LxResult linf_SetFormat([[maybe_unused]] const char *format) override
#define LXxO_LoaderInfo_SetFormat LXxD_LoaderInfo_SetFormat
#define LXxC_LoaderInfo_SetFormat(c) LxResult c::linf_SetFormat([[maybe_unused]] const char *format)

template <class T>
class CLxIfc_LoaderInfo: public CLxInterface
{
public:
    CLxIfc_LoaderInfo()
    {
        vt.TestClass = TestClass;
        vt.SetClass = SetClass;
        vt.SetFlags = SetFlags;
        vt.SetFormat = SetFormat;
        vTable = &vt.iunk;
        iid = &lx::guid_LoaderInfo;
    }

    static auto TestClass(LXtObjectID wcom,const LXtGUID *clsGUID,unsigned *priority) -> LxResult
    {
        LXCWxINST (CLxImpl_LoaderInfo, loc);
        try
        {
           return loc->linf_TestClass( clsGUID, priority);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SetClass(LXtObjectID wcom,const LXtGUID *clsGUID) -> LxResult
    {
        LXCWxINST (CLxImpl_LoaderInfo, loc);
        try
        {
           return loc->linf_SetClass( clsGUID);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SetFlags(LXtObjectID wcom,unsigned flags) -> LxResult
    {
        LXCWxINST (CLxImpl_LoaderInfo, loc);
        try
        {
           return loc->linf_SetFlags( flags);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SetFormat(LXtObjectID wcom,const char *format) -> LxResult
    {
        LXCWxINST (CLxImpl_LoaderInfo, loc);
        try
        {
           return loc->linf_SetFormat( format);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxLoaderInfo vt;
};

class CLxLoc_LoaderInfo : public CLxLocalize<ILxLoaderInfoID>
{
public:
    CLxLoc_LoaderInfo()
    {
        _init();
    }

    CLxLoc_LoaderInfo(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_LoaderInfo(CLxLoc_LoaderInfo const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_LoaderInfo;
    }

    auto TestClass(const LXtGUID *clsGUID, unsigned *priority) -> LxResult
    {
        return m_loc[0]->TestClass(m_loc, clsGUID, priority);
    }

    auto SetClass(const LXtGUID *clsGUID) -> LxResult
    {
        return m_loc[0]->SetClass(m_loc, clsGUID);
    }

    auto SetFlags(unsigned flags) -> LxResult
    {
        return m_loc[0]->SetFlags(m_loc, flags);
    }

    auto SetFormat(const char *format) -> LxResult
    {
        return m_loc[0]->SetFormat(m_loc, format);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_Saver
{
public:
    virtual ~CLxImpl_Saver() = default;

    virtual auto sav_Verify([[maybe_unused]] ILxUnknownID source, [[maybe_unused]] ILxUnknownID message) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto sav_Save([[maybe_unused]] ILxUnknownID source, [[maybe_unused]] const char *filename, [[maybe_unused]] ILxUnknownID monitor) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_Saver_Verify LxResult sav_Verify([[maybe_unused]] ILxUnknownID source, [[maybe_unused]] ILxUnknownID message) override
#define LXxO_Saver_Verify LXxD_Saver_Verify
#define LXxC_Saver_Verify(c) LxResult c::sav_Verify([[maybe_unused]] ILxUnknownID source, [[maybe_unused]] ILxUnknownID message)
#define LXxD_Saver_Save LxResult sav_Save([[maybe_unused]] ILxUnknownID source, [[maybe_unused]] const char *filename, [[maybe_unused]] ILxUnknownID monitor) override
#define LXxO_Saver_Save LXxD_Saver_Save
#define LXxC_Saver_Save(c) LxResult c::sav_Save([[maybe_unused]] ILxUnknownID source, [[maybe_unused]] const char *filename, [[maybe_unused]] ILxUnknownID monitor)

template <class T>
class CLxIfc_Saver: public CLxInterface
{
public:
    CLxIfc_Saver()
    {
        vt.Verify = Verify;
        vt.Save = Save;
        vTable = &vt.iunk;
        iid = &lx::guid_Saver;
    }

    static auto Verify(LXtObjectID wcom,LXtObjectID source,LXtObjectID message) -> LxResult
    {
        LXCWxINST (CLxImpl_Saver, loc);
        try
        {
           return loc->sav_Verify((ILxUnknownID) source,(ILxUnknownID) message);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Save(LXtObjectID wcom,LXtObjectID source,const char *filename,LXtObjectID monitor) -> LxResult
    {
        LXCWxINST (CLxImpl_Saver, loc);
        try
        {
           return loc->sav_Save((ILxUnknownID) source, filename,(ILxUnknownID) monitor);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxSaver vt;
};

class CLxLoc_Saver : public CLxLocalize<ILxSaverID>
{
public:
    CLxLoc_Saver()
    {
        _init();
    }

    CLxLoc_Saver(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_Saver(CLxLoc_Saver const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_Saver;
    }

    auto Verify(ILxUnknownID source, ILxUnknownID message) -> LxResult
    {
        return m_loc[0]->Verify(m_loc,(ILxUnknownID) source,(ILxUnknownID) message);
    }

    auto Save(ILxUnknownID source, const char *filename, ILxUnknownID monitor) -> LxResult
    {
        return m_loc[0]->Save(m_loc,(ILxUnknownID) source, filename,(ILxUnknownID) monitor);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_Monitor
{
public:
    virtual ~CLxImpl_Monitor() = default;

    virtual auto mon_Initialize([[maybe_unused]] unsigned int count) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto mon_Increment([[maybe_unused]] unsigned int count) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_Monitor_Initialize LxResult mon_Initialize([[maybe_unused]] unsigned int count) override
#define LXxO_Monitor_Initialize LXxD_Monitor_Initialize
#define LXxC_Monitor_Initialize(c) LxResult c::mon_Initialize([[maybe_unused]] unsigned int count)
#define LXxD_Monitor_Increment LxResult mon_Increment([[maybe_unused]] unsigned int count) override
#define LXxO_Monitor_Increment LXxD_Monitor_Increment
#define LXxC_Monitor_Increment(c) LxResult c::mon_Increment([[maybe_unused]] unsigned int count)

template <class T>
class CLxIfc_Monitor: public CLxInterface
{
public:
    CLxIfc_Monitor()
    {
        vt.Initialize = Initialize;
        vt.Increment = Increment;
        vTable = &vt.iunk;
        iid = &lx::guid_Monitor;
    }

    static auto Initialize(LXtObjectID wcom,unsigned int count) -> LxResult
    {
        LXCWxINST (CLxImpl_Monitor, loc);
        try
        {
           return loc->mon_Initialize( count);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Increment(LXtObjectID wcom,unsigned int count) -> LxResult
    {
        LXCWxINST (CLxImpl_Monitor, loc);
        try
        {
           return loc->mon_Increment( count);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxMonitor vt;
};

class CLxLoc_Monitor : public CLxLocalize<ILxMonitorID>
{
public:
    CLxLoc_Monitor()
    {
        _init();
    }

    CLxLoc_Monitor(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_Monitor(CLxLoc_Monitor const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_Monitor;
    }

    auto Initialize(unsigned int count) -> LxResult
    {
        return m_loc[0]->Initialize(m_loc, count);
    }

    auto Increment(unsigned int count) -> LxResult
    {
        return m_loc[0]->Increment(m_loc, count);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_StreamIO
{
public:
    virtual ~CLxImpl_StreamIO() = default;

    virtual auto io_Write([[maybe_unused]] ILxUnknownID stream) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto io_Read([[maybe_unused]] ILxUnknownID stream) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_StreamIO_Write LxResult io_Write([[maybe_unused]] ILxUnknownID stream) override
#define LXxO_StreamIO_Write LXxD_StreamIO_Write
#define LXxC_StreamIO_Write(c) LxResult c::io_Write([[maybe_unused]] ILxUnknownID stream)
#define LXxD_StreamIO_Read LxResult io_Read([[maybe_unused]] ILxUnknownID stream) override
#define LXxO_StreamIO_Read LXxD_StreamIO_Read
#define LXxC_StreamIO_Read(c) LxResult c::io_Read([[maybe_unused]] ILxUnknownID stream)

template <class T>
class CLxIfc_StreamIO: public CLxInterface
{
public:
    CLxIfc_StreamIO()
    {
        vt.Write = Write;
        vt.Read = Read;
        vTable = &vt.iunk;
        iid = &lx::guid_StreamIO;
    }

    static auto Write(LXtObjectID wcom,LXtObjectID stream) -> LxResult
    {
        LXCWxINST (CLxImpl_StreamIO, loc);
        try
        {
           return loc->io_Write((ILxUnknownID) stream);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Read(LXtObjectID wcom,LXtObjectID stream) -> LxResult
    {
        LXCWxINST (CLxImpl_StreamIO, loc);
        try
        {
           return loc->io_Read((ILxUnknownID) stream);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxStreamIO vt;
};

class CLxLoc_StreamIO : public CLxLocalize<ILxStreamIOID>
{
public:
    CLxLoc_StreamIO()
    {
        _init();
    }

    CLxLoc_StreamIO(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_StreamIO(CLxLoc_StreamIO const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_StreamIO;
    }

    auto Write(ILxUnknownID stream) -> LxResult
    {
        return m_loc[0]->Write(m_loc,(ILxUnknownID) stream);
    }

    auto Read(ILxUnknownID stream) -> LxResult
    {
        return m_loc[0]->Read(m_loc,(ILxUnknownID) stream);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_IOService : public CLxLocalizedService
{
public:
    ILxIOServiceID m_loc{ nullptr };

public:
    CLxLoc_IOService()
    {
        _init();
        set();
    }

    ~CLxLoc_IOService() = default;

    void set()
    {
        if (!m_loc)
        {
            m_loc = reinterpret_cast<ILxIOServiceID>(lx::GetGlobal(&lx::guid_IOService));
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

    auto SetOptions(ILxUnknownID options) -> LxResult
    {
        return m_loc[0]->SetOptions(m_loc,(ILxUnknownID) options);
    }

    auto PeekOptions(void) -> ILxUnknownID
    {
        return (ILxUnknownID)m_loc[0]->PeekOptions(m_loc);
    }

    auto OpenBlockStore(const char *filename, const char *format, unsigned flags, void **ppvObj) -> LxResult
    {
        return m_loc[0]->OpenBlockStore(m_loc, filename, format, flags, ppvObj);
    }

    auto OpenBlockStore(const char *filename, const char *format, unsigned flags, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->OpenBlockStore(m_loc, filename, format, flags, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_BlockStore : public CLxLocalize<ILxBlockStoreID>
{
public:
    CLxLoc_BlockStore()
    {
        _init();
    }

    CLxLoc_BlockStore(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_BlockStore(CLxLoc_BlockStore const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_BlockStore;
    }

    auto AllocBookmark(LXtBlockBookmarkID *loc) -> LxResult
    {
        return m_loc[0]->AllocBookmark(m_loc, loc);
    }

    auto Lookup(LXtID4 type, const char *id, LXtBlockBookmarkID parent) -> LxResult
    {
        return m_loc[0]->Lookup(m_loc, type, id, parent);
    }

    auto Stack(unsigned operation) -> LxResult
    {
        return m_loc[0]->Stack(m_loc, operation);
    }

    auto Count(LXtID4 type, unsigned *count, LXtBlockBookmarkID parent) -> LxResult
    {
        return m_loc[0]->Count(m_loc, type, count, parent);
    }

    auto ByIndex(LXtID4 type, unsigned index, LXtBlockBookmarkID parent) -> LxResult
    {
        return m_loc[0]->ByIndex(m_loc, type, index, parent);
    }

    auto RestoreBookmark(LXtBlockBookmarkID loc) -> LxResult
    {
        return m_loc[0]->RestoreBookmark(m_loc, loc);
    }

    auto SaveBookmark(LXtBlockBookmarkID loc) -> LxResult
    {
        return m_loc[0]->SaveBookmark(m_loc, loc);
    }

    auto Type(LXtID4 *type) -> LxResult
    {
        return m_loc[0]->Type(m_loc, type);
    }

    auto Ident(const char **id) -> LxResult
    {
        return m_loc[0]->Ident(m_loc, id);
    }

    auto Size(size_t *size) -> LxResult
    {
        return m_loc[0]->Size(m_loc, size);
    }

    auto Delete(void) -> LxResult
    {
        return m_loc[0]->Delete(m_loc);
    }

    auto WriteSize(size_t size) -> LxResult
    {
        return m_loc[0]->WriteSize(m_loc, size);
    }

    auto WriteBlock(const void *buf, size_t offset, size_t size) -> LxResult
    {
        return m_loc[0]->WriteBlock(m_loc, buf, offset, size);
    }

    auto ReadBlock(void *buf, size_t offset, size_t size) -> LxResult
    {
        return m_loc[0]->ReadBlock(m_loc, buf, offset, size);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_Loader1
{
public:
    virtual ~CLxImpl_Loader1() = default;

    virtual auto load_Recognize([[maybe_unused]] LXtLoadAccess1 *load) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto load_LoadInstance([[maybe_unused]] LXtLoadAccess1 *load, [[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto load_LoadObject([[maybe_unused]] LXtLoadAccess1 *load, [[maybe_unused]] ILxUnknownID dest) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto load_Cleanup([[maybe_unused]] LXtLoadAccess1 *load) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto load_SpawnOptions([[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_Loader1_Recognize LxResult load_Recognize([[maybe_unused]] LXtLoadAccess1 *load) override
#define LXxO_Loader1_Recognize LXxD_Loader1_Recognize
#define LXxC_Loader1_Recognize(c) LxResult c::load_Recognize([[maybe_unused]] LXtLoadAccess1 *load)
#define LXxD_Loader1_LoadInstance LxResult load_LoadInstance([[maybe_unused]] LXtLoadAccess1 *load, [[maybe_unused]] void **ppvObj) override
#define LXxO_Loader1_LoadInstance LXxD_Loader1_LoadInstance
#define LXxC_Loader1_LoadInstance(c) LxResult c::load_LoadInstance([[maybe_unused]] LXtLoadAccess1 *load, [[maybe_unused]] void **ppvObj)
#define LXxD_Loader1_LoadObject LxResult load_LoadObject([[maybe_unused]] LXtLoadAccess1 *load, [[maybe_unused]] ILxUnknownID dest) override
#define LXxO_Loader1_LoadObject LXxD_Loader1_LoadObject
#define LXxC_Loader1_LoadObject(c) LxResult c::load_LoadObject([[maybe_unused]] LXtLoadAccess1 *load, [[maybe_unused]] ILxUnknownID dest)
#define LXxD_Loader1_Cleanup LxResult load_Cleanup([[maybe_unused]] LXtLoadAccess1 *load) override
#define LXxO_Loader1_Cleanup LXxD_Loader1_Cleanup
#define LXxC_Loader1_Cleanup(c) LxResult c::load_Cleanup([[maybe_unused]] LXtLoadAccess1 *load)
#define LXxD_Loader1_SpawnOptions LxResult load_SpawnOptions([[maybe_unused]] void **ppvObj) override
#define LXxO_Loader1_SpawnOptions LXxD_Loader1_SpawnOptions
#define LXxC_Loader1_SpawnOptions(c) LxResult c::load_SpawnOptions([[maybe_unused]] void **ppvObj)

template <class T>
class CLxIfc_Loader1: public CLxInterface
{
public:
    CLxIfc_Loader1()
    {
        vt.Recognize = Recognize;
        vt.LoadInstance = LoadInstance;
        vt.LoadObject = LoadObject;
        vt.Cleanup = Cleanup;
        vt.SpawnOptions = SpawnOptions;
        vTable = &vt.iunk;
        iid = &lx::guid_Loader1;
    }

    static auto Recognize(LXtObjectID wcom,LXtLoadAccess1 *load) -> LxResult
    {
        LXCWxINST (CLxImpl_Loader1, loc);
        try
        {
           return loc->load_Recognize( load);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto LoadInstance(LXtObjectID wcom,LXtLoadAccess1 *load,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_Loader1, loc);
        try
        {
           return loc->load_LoadInstance( load, ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto LoadObject(LXtObjectID wcom,LXtLoadAccess1 *load,LXtObjectID dest) -> LxResult
    {
        LXCWxINST (CLxImpl_Loader1, loc);
        try
        {
           return loc->load_LoadObject( load,(ILxUnknownID) dest);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Cleanup(LXtObjectID wcom,LXtLoadAccess1 *load) -> LxResult
    {
        LXCWxINST (CLxImpl_Loader1, loc);
        try
        {
           return loc->load_Cleanup( load);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SpawnOptions(LXtObjectID wcom,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_Loader1, loc);
        try
        {
           return loc->load_SpawnOptions( ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxLoader1 vt;
};


