/*
 * Plug-in SDK Header: Common Utility
 *
 * Copyright 0000
 *
 * Logging utility class.
 */

#include <cstdio>
#include <cstdlib>
#include <lx_log.hpp>
#include <lx_message.hpp>
#include <lx_thread.hpp>
#include <lxu_log.hpp>
#include <string>

/*
 * CLxLogMessage : Implementation
 *
 * We maintain the service as a member for speed. We attach to the subsystem
 * lazily to get the best chance for it to exist.
 */
class pv_LogMessage
{
public:
    const char*            name;
    std::string            warn, info;
    CLxUser_LogService     svLog;
    CLxUser_MessageService svMsg;
    CLxUser_Log            log;
    CLxUser_LogEntry       lastRoot;

    const char* GetMessage(std::string&, int, const char*);
};

const char* pv_LogMessage::GetMessage(std::string& cache, int msgIdx, const char* raw)
{
    if (cache.empty())
    {
        CLxUser_ThreadService ts;

        if (ts.IsMainThread())
        {
            CLxUser_Message message;

            svMsg.NewMessage(message);
            message.SetMessage("common", nullptr, msgIdx);

            svMsg.GetText(message, cache);
        }
        else
            cache = raw;
    }

    return cache.c_str();
}

CLxLogMessage::CLxLogMessage(const char* name)
{
    pv       = new pv_LogMessage;
    pv->name = name;
}

CLxLogMessage::~CLxLogMessage()
{
    delete pv;
}

const char* CLxLogMessage::GetCopyright()
{
    return nullptr;
}

bool CLxLogMessage::Setup()
{
    if (pv->log.test())
        return true;

    pv->svLog.set();
    pv->svMsg.set();
    pv->log.setByName(pv->name);
    if (!pv->log.test())
        return false;

    return true;
}

void CLxLogMessage::Message(LxResult code, const char* who, const char* what, const char* why)
{
    CLxUser_LogEntry main, sub;
    std::string      str;

    if (!Setup())
        return;

    str = who;
    if (what && *what)
    {
        str += ": ";
        str += what;
    }

    if (pv->svLog.NewEntry(code, str.c_str(), main) && pv->svLog.NewEntry(LXe_INFO, why, sub) && LXx_OK(main.AddEntry(sub)))
    {
        pv->log.AddEntry(main);
        pv->lastRoot.set(main);
    }
}

void CLxLogMessage::SubMessage(LxResult code, const char* who, const char* what, const char* why)
{
    if (!pv->lastRoot.test())
        return Message(code, who, what, why);

    CLxUser_LogEntry sub;

    if (pv->svLog.NewEntry(LXe_INFO, why, sub))
        pv->lastRoot.AddEntry(sub);
}

static const int MSG_LOADER_SAVER_ERROR = 2401;
static const int MSG_LOADER_SAVER_INFO  = 2402;

void CLxLogMessage::Error(const char* msg)
{
    if (!Setup())
        return;

    Message(LXe_WARNING, GetFormat(), pv->GetMessage(pv->warn, MSG_LOADER_SAVER_ERROR, "load/save error"), msg);
}

void CLxLogMessage::Info(const char* msg)
{
    if (!Setup())
        return;

    Message(LXe_INFO, GetFormat(), pv->GetMessage(pv->info, MSG_LOADER_SAVER_INFO, "load/save"), msg);
}

void CLxLogMessage::SubInfo(const char* msg)
{
    if (!pv->lastRoot.test())
        return Info(msg);

    return SubMessage(LXe_INFO, nullptr, nullptr, msg);
}
