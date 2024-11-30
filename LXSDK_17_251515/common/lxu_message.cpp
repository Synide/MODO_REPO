/*
 * Plug-in SDK Source: Message Utilities
 *
 * Copyright 0000
 *
 * Provides message utility functions for C++ plug-ins.
 */
#include <lx_message.hpp>
#include <lxu_message.hpp>

bool lx::GetMessageText(std::string& text, const char* table, unsigned msgIndex, const char* msgName)
{
    CLxUser_MessageService svMsg;
    CLxUser_Message        message;

    return (svMsg.NewMessage(message)) && (LXx_OK(message.SetMessage(table, msgName, msgIndex))) && (LXx_OK(svMsg.GetText(message, text)));
}

bool lx::GetMessageText(std::string& text, const char* table, const char* msgName)
{
    return lx::GetMessageText(text, table, 0, msgName);
}

bool lx::GetMessageText(std::string& text, const char* table, unsigned msgIndex)
{
    return lx::GetMessageText(text, table, msgIndex, nullptr);
}
bool lx::GetMessageText(std::string& text, const std::string& table, const std::string& msgName)
{
    return lx::GetMessageText(text, table.c_str(), msgName.c_str());
}

bool lx::GetMessageText(std::string& text, const std::string& table, unsigned msgIndex)
{
    return lx::GetMessageText(text, table.c_str(), msgIndex);
}

bool lx::CommonMessage(std::string& text, unsigned msgIndex)
{
    return lx::GetMessageText(text, "common", msgIndex);
}

bool lx::CommonMessage(std::string& text, const char* msgName)
{
    return lx::GetMessageText(text, "common", msgName);
}
