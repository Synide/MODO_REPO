//
// C++ wrapper for lxsdk/lxinterviewer.h.
//
//	Copyright 2024.
//
//
#pragma once

#include <lxinterviewer.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx
{
    static LXtGUID const guid_Interviewer = {0x7039c075, {0x3d04, 0x4cc0}, {0xb3, 0xcf, 0xf3, 0xde, 0x50, 0x9b, 0x6a, 0x20}};
    static LXtGUID const guid_InterviewerService = {0x5f892557, {0x80a5, 0x4490}, {0xb3, 0x14, 0xd5, 0xf1, 0x9f, 0xf9, 0xa6, 0xb6}};
} // namespace lx

class CLxImpl_Interviewer
{
public:
    virtual ~CLxImpl_Interviewer() = default;

    virtual auto intrv_Title([[maybe_unused]] char *buf, [[maybe_unused]] unsigned int len) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto intrv_Description([[maybe_unused]] char *buf, [[maybe_unused]] unsigned int len) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto intrv_ButtonLabel([[maybe_unused]] char *buf, [[maybe_unused]] unsigned int len) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto intrv_ButtonCommand([[maybe_unused]] char *buf, [[maybe_unused]] unsigned int len) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_Interviewer_Title LxResult intrv_Title([[maybe_unused]] char *buf, [[maybe_unused]] unsigned int len) override
#define LXxO_Interviewer_Title LXxD_Interviewer_Title
#define LXxC_Interviewer_Title(c) LxResult c::intrv_Title([[maybe_unused]] char *buf, [[maybe_unused]] unsigned int len)
#define LXxD_Interviewer_Description LxResult intrv_Description([[maybe_unused]] char *buf, [[maybe_unused]] unsigned int len) override
#define LXxO_Interviewer_Description LXxD_Interviewer_Description
#define LXxC_Interviewer_Description(c) LxResult c::intrv_Description([[maybe_unused]] char *buf, [[maybe_unused]] unsigned int len)
#define LXxD_Interviewer_ButtonLabel LxResult intrv_ButtonLabel([[maybe_unused]] char *buf, [[maybe_unused]] unsigned int len) override
#define LXxO_Interviewer_ButtonLabel LXxD_Interviewer_ButtonLabel
#define LXxC_Interviewer_ButtonLabel(c) LxResult c::intrv_ButtonLabel([[maybe_unused]] char *buf, [[maybe_unused]] unsigned int len)
#define LXxD_Interviewer_ButtonCommand LxResult intrv_ButtonCommand([[maybe_unused]] char *buf, [[maybe_unused]] unsigned int len) override
#define LXxO_Interviewer_ButtonCommand LXxD_Interviewer_ButtonCommand
#define LXxC_Interviewer_ButtonCommand(c) LxResult c::intrv_ButtonCommand([[maybe_unused]] char *buf, [[maybe_unused]] unsigned int len)

template <class T>
class CLxIfc_Interviewer: public CLxInterface
{
public:
    CLxIfc_Interviewer()
    {
        vt.Title = Title;
        vt.Description = Description;
        vt.ButtonLabel = ButtonLabel;
        vt.ButtonCommand = ButtonCommand;
        vTable = &vt.iunk;
        iid = &lx::guid_Interviewer;
    }

    static auto Title(LXtObjectID wcom,char *buf,unsigned int len) -> LxResult
    {
        LXCWxINST (CLxImpl_Interviewer, loc);
        try
        {
           return loc->intrv_Title( buf, len);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Description(LXtObjectID wcom,char *buf,unsigned int len) -> LxResult
    {
        LXCWxINST (CLxImpl_Interviewer, loc);
        try
        {
           return loc->intrv_Description( buf, len);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ButtonLabel(LXtObjectID wcom,char *buf,unsigned int len) -> LxResult
    {
        LXCWxINST (CLxImpl_Interviewer, loc);
        try
        {
           return loc->intrv_ButtonLabel( buf, len);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ButtonCommand(LXtObjectID wcom,char *buf,unsigned int len) -> LxResult
    {
        LXCWxINST (CLxImpl_Interviewer, loc);
        try
        {
           return loc->intrv_ButtonCommand( buf, len);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxInterviewer vt;
};

class CLxLoc_Interviewer : public CLxLocalize<ILxInterviewerID>
{
public:
    CLxLoc_Interviewer()
    {
        _init();
    }

    CLxLoc_Interviewer(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_Interviewer(CLxLoc_Interviewer const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_Interviewer;
    }

    auto Title(char *buf, unsigned int len) -> LxResult
    {
        return m_loc[0]->Title(m_loc, buf, len);
    }

    auto Title(std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->Title(m_loc, buf, len);
        LXWx_SBUF2
    }

    auto Description(char *buf, unsigned int len) -> LxResult
    {
        return m_loc[0]->Description(m_loc, buf, len);
    }

    auto Description(std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->Description(m_loc, buf, len);
        LXWx_SBUF2
    }

    auto ButtonLabel(char *buf, unsigned int len) -> LxResult
    {
        return m_loc[0]->ButtonLabel(m_loc, buf, len);
    }

    auto ButtonLabel(std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->ButtonLabel(m_loc, buf, len);
        LXWx_SBUF2
    }

    auto ButtonCommand(char *buf, unsigned int len) -> LxResult
    {
        return m_loc[0]->ButtonCommand(m_loc, buf, len);
    }

    auto ButtonCommand(std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->ButtonCommand(m_loc, buf, len);
        LXWx_SBUF2
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_InterviewerService : public CLxLocalizedService
{
public:
    ILxInterviewerServiceID m_loc{ nullptr };

public:
    CLxLoc_InterviewerService()
    {
        _init();
        set();
    }

    ~CLxLoc_InterviewerService() = default;

    void set()
    {
        if (!m_loc)
        {
            m_loc = reinterpret_cast<ILxInterviewerServiceID>(lx::GetGlobal(&lx::guid_InterviewerService));
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

    auto Arm(const char *serverName, int target) -> LxResult
    {
        return m_loc[0]->Arm(m_loc, serverName, target);
    }

    auto Disarm(const char *serverName, int allowRearm) -> LxResult
    {
        return m_loc[0]->Disarm(m_loc, serverName, allowRearm);
    }

    auto WasFired(const char *serverName) -> LxResult
    {
        return m_loc[0]->WasFired(m_loc, serverName);
    }

    auto ClearDismissTimer(const char *serverName) -> LxResult
    {
        return m_loc[0]->ClearDismissTimer(m_loc, serverName);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
