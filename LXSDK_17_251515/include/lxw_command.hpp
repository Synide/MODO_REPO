//
// C++ wrapper for lxsdk/lxcommand.h.
//
//	Copyright 2024.
//
//
#pragma once

#include <lxcommand.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx
{
    static LXtGUID const guid_Command = {0x1db2d294, {0x3b52, 0x4442}, {0xa6, 0x34, 0xf3, 0xd4, 0xc6, 0xce, 0x8d, 0xc4}};
    static LXtGUID const guid_CommandDBHelp = {0x7c8a58e0, {0x0052, 0x4d8e}, {0xad, 0xdb, 0x73, 0x87, 0xfb, 0xa9, 0xd5, 0xbf}};
    static LXtGUID const guid_UIHints = {0x944D9CFD, {0xDB04, 0x4bba}, {0xB8, 0xB1, 0xAD, 0xE4, 0x24, 0x69, 0x5E, 0xDC}};
    static LXtGUID const guid_UIHintsRead = {0x8f22a96d, {0x94e5, 0x49c8}, {0xb3, 0xd4, 0xa4, 0x08, 0x0f, 0xbe, 0xe9, 0x1b}};
    static LXtGUID const guid_UIValueHints = {0x57E8F131, {0xCE2D, 0x42C6}, {0x82, 0x41, 0xA3, 0x95, 0x25, 0x3B, 0x37, 0xD6}};
    static LXtGUID const guid_UIValueHints3 = {0xded71bdb, {0x080c, 0x4ce8}, {0xbf, 0x06, 0x69, 0xe3, 0x72, 0xea, 0x8b, 0xea}};
    static LXtGUID const guid_UIValueHints2 = {0xf37bb385, {0x7214, 0x42d5}, {0x9b, 0xed, 0x55, 0x2f, 0xf4, 0x73, 0x89, 0x08}};
    static LXtGUID const guid_UIValueHints1 = {0x7BB10C3F, {0x1FFB, 0x4104}, {0x8F, 0xBE, 0xCB, 0x1C, 0x33, 0x4E, 0xE3, 0xC1}};
    static LXtGUID const guid_AttributesUI = {0x44D9C65E, {0xAE2E, 0x4012}, {0xAB, 0x57, 0xE2, 0x83, 0x97, 0x34, 0xF7, 0xFF}};
    static LXtGUID const guid_CommandEvent = {0xF7CD29B5, {0x6858, 0x445b}, {0xBE, 0x6D, 0x83, 0x47, 0x60, 0x3B, 0x47, 0xE9}};
    static LXtGUID const guid_Command1 = {0x4F540BF1, {0xF97E, 0x4D46}, {0x8A, 0x5F, 0x6B, 0x27, 0x50, 0xA6, 0xCE, 0xB9}};
    static LXtGUID const guid_Command2 = {0x5e981e16, {0x94b7, 0x4364}, {0x92, 0xf0, 0xd7, 0x67, 0x92, 0x36, 0xf3, 0xd1}};
    static LXtGUID const guid_Command3 = {0xdb970a3b, {0xdce1, 0x4679}, {0xa4, 0xbf, 0xb5, 0xf1, 0xdf, 0xf4, 0xdb, 0x0d}};
    static LXtGUID const guid_CommandBlock = {0x65AEBD9F, {0xD518, 0x47b2}, {0x8C, 0xC6, 0xE4, 0x53, 0xF8, 0xC4, 0x3C, 0xB6}};
    static LXtGUID const guid_CommandService = {0x9DB8BA65, {0x8C36, 0x45A7}, {0xB4, 0x03, 0xDF, 0x7B, 0xA5, 0x9B, 0xA6, 0xC2}};
    static LXtGUID const guid_CommandPostEnd = {0xAEB6B7BF, {0x34B9, 0x4991}, {0x90, 0x4C, 0x29, 0x8B, 0x8D, 0xB1, 0xAE, 0x12}};
    static LXtGUID const guid_CmdSysListener = {0xd89ccb72, {0x43b9, 0x4bf2}, {0xbb, 0x7d, 0x7e, 0x81, 0x6b, 0xb4, 0xd9, 0xd8}};
} // namespace lx

class CLxImpl_Command
{
public:
    virtual ~CLxImpl_Command() = default;

    virtual auto cmd_Tag([[maybe_unused]] LXtCommandTag *tag) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd_Name([[maybe_unused]] const char **name) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd_UserName([[maybe_unused]] const char **userName) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd_ButtonName([[maybe_unused]] const char **buttonName) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd_Desc([[maybe_unused]] const char **desc) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd_Tooltip([[maybe_unused]] const char **tooltip) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd_Help([[maybe_unused]] const char **help) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd_Example([[maybe_unused]] const char **example) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd_Icon([[maybe_unused]] const char **iconNames) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd_Flags([[maybe_unused]] unsigned int *flags) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd_PostExecFlags([[maybe_unused]] unsigned int *flags) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd_PostExecBehaviorFlags([[maybe_unused]] unsigned int *flags) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd_PostExecHints([[maybe_unused]] unsigned int *hints) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd_SandboxGUID([[maybe_unused]] const LXtGUID **guid) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd_Message([[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd_Enable([[maybe_unused]] ILxUnknownID msg) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd_ContainedEnable([[maybe_unused]] LXtID4 *types) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual void cmd_Interact([[maybe_unused]] void)
    {
    }

    virtual void cmd_PreExecute([[maybe_unused]] void)
    {
    }

    virtual void cmd_Execute([[maybe_unused]] unsigned int flags)
    {
    }

    virtual auto cmd_ToggleArg([[maybe_unused]] unsigned int *index, [[maybe_unused]] void **ppvObj, [[maybe_unused]] unsigned int *typeID, [[maybe_unused]] const char **typeName) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd_ArgFlags([[maybe_unused]] unsigned int index, [[maybe_unused]] unsigned int *flags) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd_ArgClear([[maybe_unused]] unsigned int index) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd_ArgResetAll([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd_ArgSetDatatypes([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd_ArgUserName([[maybe_unused]] unsigned int index, [[maybe_unused]] const char **userName) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd_ArgDesc([[maybe_unused]] unsigned int index, [[maybe_unused]] const char **desc) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd_ArgExample([[maybe_unused]] unsigned int index, [[maybe_unused]] const char **example) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd_ArgType([[maybe_unused]] unsigned int index, [[maybe_unused]] const char **type) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd_ArgTypeUserName([[maybe_unused]] unsigned int index, [[maybe_unused]] const char **userName) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd_ArgTypeDesc([[maybe_unused]] unsigned int index, [[maybe_unused]] const char **desc) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd_ArgOptionUserName([[maybe_unused]] unsigned int index, [[maybe_unused]] unsigned int optIndex, [[maybe_unused]] const char **userName) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd_ArgOptionDesc([[maybe_unused]] unsigned int index, [[maybe_unused]] unsigned int optIndex, [[maybe_unused]] const char **desc) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd_DialogInit([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd_DialogArgChange([[maybe_unused]] unsigned int arg) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd_ArgEnable([[maybe_unused]] unsigned int arg) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd_ArgParseString([[maybe_unused]] unsigned int argIndex, [[maybe_unused]] const char *argString) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd_Copy([[maybe_unused]] ILxUnknownID sourceCommand) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd_Query([[maybe_unused]] unsigned int index, [[maybe_unused]] ILxUnknownID vaQuery) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd_NotifyAddClient([[maybe_unused]] int argument, [[maybe_unused]] ILxUnknownID object) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd_NotifyRemoveClient([[maybe_unused]] ILxUnknownID object) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd_DialogFormatting([[maybe_unused]] const char **formatting) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd_IconImage([[maybe_unused]] int w, [[maybe_unused]] int h, [[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd_ArgOptionIconName([[maybe_unused]] unsigned int index, [[maybe_unused]] unsigned int optIndex, [[maybe_unused]] const char **iconName) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_Command_Tag LxResult cmd_Tag([[maybe_unused]] LXtCommandTag *tag) override
#define LXxO_Command_Tag LXxD_Command_Tag
#define LXxC_Command_Tag(c) LxResult c::cmd_Tag([[maybe_unused]] LXtCommandTag *tag)
#define LXxD_Command_Name LxResult cmd_Name([[maybe_unused]] const char **name) override
#define LXxO_Command_Name LXxD_Command_Name
#define LXxC_Command_Name(c) LxResult c::cmd_Name([[maybe_unused]] const char **name)
#define LXxD_Command_UserName LxResult cmd_UserName([[maybe_unused]] const char **userName) override
#define LXxO_Command_UserName LXxD_Command_UserName
#define LXxC_Command_UserName(c) LxResult c::cmd_UserName([[maybe_unused]] const char **userName)
#define LXxD_Command_ButtonName LxResult cmd_ButtonName([[maybe_unused]] const char **buttonName) override
#define LXxO_Command_ButtonName LXxD_Command_ButtonName
#define LXxC_Command_ButtonName(c) LxResult c::cmd_ButtonName([[maybe_unused]] const char **buttonName)
#define LXxD_Command_Desc LxResult cmd_Desc([[maybe_unused]] const char **desc) override
#define LXxO_Command_Desc LXxD_Command_Desc
#define LXxC_Command_Desc(c) LxResult c::cmd_Desc([[maybe_unused]] const char **desc)
#define LXxD_Command_Tooltip LxResult cmd_Tooltip([[maybe_unused]] const char **tooltip) override
#define LXxO_Command_Tooltip LXxD_Command_Tooltip
#define LXxC_Command_Tooltip(c) LxResult c::cmd_Tooltip([[maybe_unused]] const char **tooltip)
#define LXxD_Command_Help LxResult cmd_Help([[maybe_unused]] const char **help) override
#define LXxO_Command_Help LXxD_Command_Help
#define LXxC_Command_Help(c) LxResult c::cmd_Help([[maybe_unused]] const char **help)
#define LXxD_Command_Example LxResult cmd_Example([[maybe_unused]] const char **example) override
#define LXxO_Command_Example LXxD_Command_Example
#define LXxC_Command_Example(c) LxResult c::cmd_Example([[maybe_unused]] const char **example)
#define LXxD_Command_Icon LxResult cmd_Icon([[maybe_unused]] const char **iconNames) override
#define LXxO_Command_Icon LXxD_Command_Icon
#define LXxC_Command_Icon(c) LxResult c::cmd_Icon([[maybe_unused]] const char **iconNames)
#define LXxD_Command_Flags LxResult cmd_Flags([[maybe_unused]] unsigned int *flags) override
#define LXxO_Command_Flags LXxD_Command_Flags
#define LXxC_Command_Flags(c) LxResult c::cmd_Flags([[maybe_unused]] unsigned int *flags)
#define LXxD_Command_PostExecFlags LxResult cmd_PostExecFlags([[maybe_unused]] unsigned int *flags) override
#define LXxO_Command_PostExecFlags LXxD_Command_PostExecFlags
#define LXxC_Command_PostExecFlags(c) LxResult c::cmd_PostExecFlags([[maybe_unused]] unsigned int *flags)
#define LXxD_Command_PostExecBehaviorFlags LxResult cmd_PostExecBehaviorFlags([[maybe_unused]] unsigned int *flags) override
#define LXxO_Command_PostExecBehaviorFlags LXxD_Command_PostExecBehaviorFlags
#define LXxC_Command_PostExecBehaviorFlags(c) LxResult c::cmd_PostExecBehaviorFlags([[maybe_unused]] unsigned int *flags)
#define LXxD_Command_PostExecHints LxResult cmd_PostExecHints([[maybe_unused]] unsigned int *hints) override
#define LXxO_Command_PostExecHints LXxD_Command_PostExecHints
#define LXxC_Command_PostExecHints(c) LxResult c::cmd_PostExecHints([[maybe_unused]] unsigned int *hints)
#define LXxD_Command_SandboxGUID LxResult cmd_SandboxGUID([[maybe_unused]] const LXtGUID **guid) override
#define LXxO_Command_SandboxGUID LXxD_Command_SandboxGUID
#define LXxC_Command_SandboxGUID(c) LxResult c::cmd_SandboxGUID([[maybe_unused]] const LXtGUID **guid)
#define LXxD_Command_Message LxResult cmd_Message([[maybe_unused]] void **ppvObj) override
#define LXxO_Command_Message LXxD_Command_Message
#define LXxC_Command_Message(c) LxResult c::cmd_Message([[maybe_unused]] void **ppvObj)
#define LXxD_Command_Enable LxResult cmd_Enable([[maybe_unused]] ILxUnknownID msg) override
#define LXxO_Command_Enable LXxD_Command_Enable
#define LXxC_Command_Enable(c) LxResult c::cmd_Enable([[maybe_unused]] ILxUnknownID msg)
#define LXxD_Command_ContainedEnable LxResult cmd_ContainedEnable([[maybe_unused]] LXtID4 *types) override
#define LXxO_Command_ContainedEnable LXxD_Command_ContainedEnable
#define LXxC_Command_ContainedEnable(c) LxResult c::cmd_ContainedEnable([[maybe_unused]] LXtID4 *types)
#define LXxD_Command_Interact void cmd_Interact() override
#define LXxO_Command_Interact LXxD_Command_Interact
#define LXxC_Command_Interact(c) void c::cmd_Interact()
#define LXxD_Command_PreExecute void cmd_PreExecute() override
#define LXxO_Command_PreExecute LXxD_Command_PreExecute
#define LXxC_Command_PreExecute(c) void c::cmd_PreExecute()
#define LXxD_Command_Execute void cmd_Execute([[maybe_unused]] unsigned int flags) override
#define LXxO_Command_Execute LXxD_Command_Execute
#define LXxC_Command_Execute(c) void c::cmd_Execute([[maybe_unused]] unsigned int flags)
#define LXxD_Command_ToggleArg LxResult cmd_ToggleArg([[maybe_unused]] unsigned int *index, [[maybe_unused]] void **ppvObj, [[maybe_unused]] unsigned int *typeID, [[maybe_unused]] const char **typeName) override
#define LXxO_Command_ToggleArg LXxD_Command_ToggleArg
#define LXxC_Command_ToggleArg(c) LxResult c::cmd_ToggleArg([[maybe_unused]] unsigned int *index, [[maybe_unused]] void **ppvObj, [[maybe_unused]] unsigned int *typeID, [[maybe_unused]] const char **typeName)
#define LXxD_Command_ArgFlags LxResult cmd_ArgFlags([[maybe_unused]] unsigned int index, [[maybe_unused]] unsigned int *flags) override
#define LXxO_Command_ArgFlags LXxD_Command_ArgFlags
#define LXxC_Command_ArgFlags(c) LxResult c::cmd_ArgFlags([[maybe_unused]] unsigned int index, [[maybe_unused]] unsigned int *flags)
#define LXxD_Command_ArgClear LxResult cmd_ArgClear([[maybe_unused]] unsigned int index) override
#define LXxO_Command_ArgClear LXxD_Command_ArgClear
#define LXxC_Command_ArgClear(c) LxResult c::cmd_ArgClear([[maybe_unused]] unsigned int index)
#define LXxD_Command_ArgResetAll LxResult cmd_ArgResetAll() override
#define LXxO_Command_ArgResetAll LXxD_Command_ArgResetAll
#define LXxC_Command_ArgResetAll(c) LxResult c::cmd_ArgResetAll()
#define LXxD_Command_ArgSetDatatypes LxResult cmd_ArgSetDatatypes() override
#define LXxO_Command_ArgSetDatatypes LXxD_Command_ArgSetDatatypes
#define LXxC_Command_ArgSetDatatypes(c) LxResult c::cmd_ArgSetDatatypes()
#define LXxD_Command_ArgUserName LxResult cmd_ArgUserName([[maybe_unused]] unsigned int index, [[maybe_unused]] const char **userName) override
#define LXxO_Command_ArgUserName LXxD_Command_ArgUserName
#define LXxC_Command_ArgUserName(c) LxResult c::cmd_ArgUserName([[maybe_unused]] unsigned int index, [[maybe_unused]] const char **userName)
#define LXxD_Command_ArgDesc LxResult cmd_ArgDesc([[maybe_unused]] unsigned int index, [[maybe_unused]] const char **desc) override
#define LXxO_Command_ArgDesc LXxD_Command_ArgDesc
#define LXxC_Command_ArgDesc(c) LxResult c::cmd_ArgDesc([[maybe_unused]] unsigned int index, [[maybe_unused]] const char **desc)
#define LXxD_Command_ArgExample LxResult cmd_ArgExample([[maybe_unused]] unsigned int index, [[maybe_unused]] const char **example) override
#define LXxO_Command_ArgExample LXxD_Command_ArgExample
#define LXxC_Command_ArgExample(c) LxResult c::cmd_ArgExample([[maybe_unused]] unsigned int index, [[maybe_unused]] const char **example)
#define LXxD_Command_ArgType LxResult cmd_ArgType([[maybe_unused]] unsigned int index, [[maybe_unused]] const char **type) override
#define LXxO_Command_ArgType LXxD_Command_ArgType
#define LXxC_Command_ArgType(c) LxResult c::cmd_ArgType([[maybe_unused]] unsigned int index, [[maybe_unused]] const char **type)
#define LXxD_Command_ArgTypeUserName LxResult cmd_ArgTypeUserName([[maybe_unused]] unsigned int index, [[maybe_unused]] const char **userName) override
#define LXxO_Command_ArgTypeUserName LXxD_Command_ArgTypeUserName
#define LXxC_Command_ArgTypeUserName(c) LxResult c::cmd_ArgTypeUserName([[maybe_unused]] unsigned int index, [[maybe_unused]] const char **userName)
#define LXxD_Command_ArgTypeDesc LxResult cmd_ArgTypeDesc([[maybe_unused]] unsigned int index, [[maybe_unused]] const char **desc) override
#define LXxO_Command_ArgTypeDesc LXxD_Command_ArgTypeDesc
#define LXxC_Command_ArgTypeDesc(c) LxResult c::cmd_ArgTypeDesc([[maybe_unused]] unsigned int index, [[maybe_unused]] const char **desc)
#define LXxD_Command_ArgOptionUserName LxResult cmd_ArgOptionUserName([[maybe_unused]] unsigned int index, [[maybe_unused]] unsigned int optIndex, [[maybe_unused]] const char **userName) override
#define LXxO_Command_ArgOptionUserName LXxD_Command_ArgOptionUserName
#define LXxC_Command_ArgOptionUserName(c) LxResult c::cmd_ArgOptionUserName([[maybe_unused]] unsigned int index, [[maybe_unused]] unsigned int optIndex, [[maybe_unused]] const char **userName)
#define LXxD_Command_ArgOptionDesc LxResult cmd_ArgOptionDesc([[maybe_unused]] unsigned int index, [[maybe_unused]] unsigned int optIndex, [[maybe_unused]] const char **desc) override
#define LXxO_Command_ArgOptionDesc LXxD_Command_ArgOptionDesc
#define LXxC_Command_ArgOptionDesc(c) LxResult c::cmd_ArgOptionDesc([[maybe_unused]] unsigned int index, [[maybe_unused]] unsigned int optIndex, [[maybe_unused]] const char **desc)
#define LXxD_Command_DialogInit LxResult cmd_DialogInit() override
#define LXxO_Command_DialogInit LXxD_Command_DialogInit
#define LXxC_Command_DialogInit(c) LxResult c::cmd_DialogInit()
#define LXxD_Command_DialogArgChange LxResult cmd_DialogArgChange([[maybe_unused]] unsigned int arg) override
#define LXxO_Command_DialogArgChange LXxD_Command_DialogArgChange
#define LXxC_Command_DialogArgChange(c) LxResult c::cmd_DialogArgChange([[maybe_unused]] unsigned int arg)
#define LXxD_Command_ArgEnable LxResult cmd_ArgEnable([[maybe_unused]] unsigned int arg) override
#define LXxO_Command_ArgEnable LXxD_Command_ArgEnable
#define LXxC_Command_ArgEnable(c) LxResult c::cmd_ArgEnable([[maybe_unused]] unsigned int arg)
#define LXxD_Command_ArgParseString LxResult cmd_ArgParseString([[maybe_unused]] unsigned int argIndex, [[maybe_unused]] const char *argString) override
#define LXxO_Command_ArgParseString LXxD_Command_ArgParseString
#define LXxC_Command_ArgParseString(c) LxResult c::cmd_ArgParseString([[maybe_unused]] unsigned int argIndex, [[maybe_unused]] const char *argString)
#define LXxD_Command_Copy LxResult cmd_Copy([[maybe_unused]] ILxUnknownID sourceCommand) override
#define LXxO_Command_Copy LXxD_Command_Copy
#define LXxC_Command_Copy(c) LxResult c::cmd_Copy([[maybe_unused]] ILxUnknownID sourceCommand)
#define LXxD_Command_Query LxResult cmd_Query([[maybe_unused]] unsigned int index, [[maybe_unused]] ILxUnknownID vaQuery) override
#define LXxO_Command_Query LXxD_Command_Query
#define LXxC_Command_Query(c) LxResult c::cmd_Query([[maybe_unused]] unsigned int index, [[maybe_unused]] ILxUnknownID vaQuery)
#define LXxD_Command_NotifyAddClient LxResult cmd_NotifyAddClient([[maybe_unused]] int argument, [[maybe_unused]] ILxUnknownID object) override
#define LXxO_Command_NotifyAddClient LXxD_Command_NotifyAddClient
#define LXxC_Command_NotifyAddClient(c) LxResult c::cmd_NotifyAddClient([[maybe_unused]] int argument, [[maybe_unused]] ILxUnknownID object)
#define LXxD_Command_NotifyRemoveClient LxResult cmd_NotifyRemoveClient([[maybe_unused]] ILxUnknownID object) override
#define LXxO_Command_NotifyRemoveClient LXxD_Command_NotifyRemoveClient
#define LXxC_Command_NotifyRemoveClient(c) LxResult c::cmd_NotifyRemoveClient([[maybe_unused]] ILxUnknownID object)
#define LXxD_Command_DialogFormatting LxResult cmd_DialogFormatting([[maybe_unused]] const char **formatting) override
#define LXxO_Command_DialogFormatting LXxD_Command_DialogFormatting
#define LXxC_Command_DialogFormatting(c) LxResult c::cmd_DialogFormatting([[maybe_unused]] const char **formatting)
#define LXxD_Command_IconImage LxResult cmd_IconImage([[maybe_unused]] int w, [[maybe_unused]] int h, [[maybe_unused]] void **ppvObj) override
#define LXxO_Command_IconImage LXxD_Command_IconImage
#define LXxC_Command_IconImage(c) LxResult c::cmd_IconImage([[maybe_unused]] int w, [[maybe_unused]] int h, [[maybe_unused]] void **ppvObj)
#define LXxD_Command_ArgOptionIconName LxResult cmd_ArgOptionIconName([[maybe_unused]] unsigned int index, [[maybe_unused]] unsigned int optIndex, [[maybe_unused]] const char **iconName) override
#define LXxO_Command_ArgOptionIconName LXxD_Command_ArgOptionIconName
#define LXxC_Command_ArgOptionIconName(c) LxResult c::cmd_ArgOptionIconName([[maybe_unused]] unsigned int index, [[maybe_unused]] unsigned int optIndex, [[maybe_unused]] const char **iconName)

template <class T>
class CLxIfc_Command: public CLxInterface
{
public:
    CLxIfc_Command()
    {
        vt.Tag = Tag;
        vt.Name = Name;
        vt.UserName = UserName;
        vt.ButtonName = ButtonName;
        vt.Desc = Desc;
        vt.Tooltip = Tooltip;
        vt.Help = Help;
        vt.Example = Example;
        vt.Icon = Icon;
        vt.Flags = Flags;
        vt.PostExecFlags = PostExecFlags;
        vt.PostExecBehaviorFlags = PostExecBehaviorFlags;
        vt.PostExecHints = PostExecHints;
        vt.SandboxGUID = SandboxGUID;
        vt.Message = Message;
        vt.Enable = Enable;
        vt.ContainedEnable = ContainedEnable;
        vt.Interact = Interact;
        vt.PreExecute = PreExecute;
        vt.Execute = Execute;
        vt.ToggleArg = ToggleArg;
        vt.ArgFlags = ArgFlags;
        vt.ArgClear = ArgClear;
        vt.ArgResetAll = ArgResetAll;
        vt.ArgSetDatatypes = ArgSetDatatypes;
        vt.ArgUserName = ArgUserName;
        vt.ArgDesc = ArgDesc;
        vt.ArgExample = ArgExample;
        vt.ArgType = ArgType;
        vt.ArgTypeUserName = ArgTypeUserName;
        vt.ArgTypeDesc = ArgTypeDesc;
        vt.ArgOptionUserName = ArgOptionUserName;
        vt.ArgOptionDesc = ArgOptionDesc;
        vt.DialogInit = DialogInit;
        vt.DialogArgChange = DialogArgChange;
        vt.ArgEnable = ArgEnable;
        vt.ArgParseString = ArgParseString;
        vt.Copy = Copy;
        vt.Query = Query;
        vt.NotifyAddClient = NotifyAddClient;
        vt.NotifyRemoveClient = NotifyRemoveClient;
        vt.DialogFormatting = DialogFormatting;
        vt.IconImage = IconImage;
        vt.ArgOptionIconName = ArgOptionIconName;
        vTable = &vt.iunk;
        iid = &lx::guid_Command;
    }

    static auto Tag(LXtObjectID wcom,LXtCommandTag *tag) -> LxResult
    {
        LXCWxINST (CLxImpl_Command, loc);
        try
        {
           return loc->cmd_Tag( tag);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Name(LXtObjectID wcom,const char **name) -> LxResult
    {
        LXCWxINST (CLxImpl_Command, loc);
        try
        {
           return loc->cmd_Name( name);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto UserName(LXtObjectID wcom,const char **userName) -> LxResult
    {
        LXCWxINST (CLxImpl_Command, loc);
        try
        {
           return loc->cmd_UserName( userName);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ButtonName(LXtObjectID wcom,const char **buttonName) -> LxResult
    {
        LXCWxINST (CLxImpl_Command, loc);
        try
        {
           return loc->cmd_ButtonName( buttonName);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Desc(LXtObjectID wcom,const char **desc) -> LxResult
    {
        LXCWxINST (CLxImpl_Command, loc);
        try
        {
           return loc->cmd_Desc( desc);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Tooltip(LXtObjectID wcom,const char **tooltip) -> LxResult
    {
        LXCWxINST (CLxImpl_Command, loc);
        try
        {
           return loc->cmd_Tooltip( tooltip);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Help(LXtObjectID wcom,const char **help) -> LxResult
    {
        LXCWxINST (CLxImpl_Command, loc);
        try
        {
           return loc->cmd_Help( help);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Example(LXtObjectID wcom,const char **example) -> LxResult
    {
        LXCWxINST (CLxImpl_Command, loc);
        try
        {
           return loc->cmd_Example( example);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Icon(LXtObjectID wcom,const char **iconNames) -> LxResult
    {
        LXCWxINST (CLxImpl_Command, loc);
        try
        {
           return loc->cmd_Icon( iconNames);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Flags(LXtObjectID wcom,unsigned int *flags) -> LxResult
    {
        LXCWxINST (CLxImpl_Command, loc);
        try
        {
           return loc->cmd_Flags( flags);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto PostExecFlags(LXtObjectID wcom,unsigned int *flags) -> LxResult
    {
        LXCWxINST (CLxImpl_Command, loc);
        try
        {
           return loc->cmd_PostExecFlags( flags);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto PostExecBehaviorFlags(LXtObjectID wcom,unsigned int *flags) -> LxResult
    {
        LXCWxINST (CLxImpl_Command, loc);
        try
        {
           return loc->cmd_PostExecBehaviorFlags( flags);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto PostExecHints(LXtObjectID wcom,unsigned int *hints) -> LxResult
    {
        LXCWxINST (CLxImpl_Command, loc);
        try
        {
           return loc->cmd_PostExecHints( hints);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SandboxGUID(LXtObjectID wcom,const LXtGUID **guid) -> LxResult
    {
        LXCWxINST (CLxImpl_Command, loc);
        try
        {
           return loc->cmd_SandboxGUID( guid);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Message(LXtObjectID wcom,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_Command, loc);
        try
        {
           return loc->cmd_Message( ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Enable(LXtObjectID wcom,LXtObjectID msg) -> LxResult
    {
        LXCWxINST (CLxImpl_Command, loc);
        try
        {
           return loc->cmd_Enable((ILxUnknownID) msg);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ContainedEnable(LXtObjectID wcom,LXtID4 *types) -> LxResult
    {
        LXCWxINST (CLxImpl_Command, loc);
        try
        {
           return loc->cmd_ContainedEnable( types);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Interact(LXtObjectID wcom) -> void
    {
        LXCWxINST (CLxImpl_Command, loc);
        loc->cmd_Interact();
    }

    static auto PreExecute(LXtObjectID wcom) -> void
    {
        LXCWxINST (CLxImpl_Command, loc);
        loc->cmd_PreExecute();
    }

    static auto Execute(LXtObjectID wcom,unsigned int flags) -> void
    {
        LXCWxINST (CLxImpl_Command, loc);
        loc->cmd_Execute( flags);
    }

    static auto ToggleArg(LXtObjectID wcom,unsigned int *index,void **ppvObj,unsigned int *typeID,const char **typeName) -> LxResult
    {
        LXCWxINST (CLxImpl_Command, loc);
        try
        {
           return loc->cmd_ToggleArg( index, ppvObj, typeID, typeName);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ArgFlags(LXtObjectID wcom,unsigned int index,unsigned int *flags) -> LxResult
    {
        LXCWxINST (CLxImpl_Command, loc);
        try
        {
           return loc->cmd_ArgFlags( index, flags);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ArgClear(LXtObjectID wcom,unsigned int index) -> LxResult
    {
        LXCWxINST (CLxImpl_Command, loc);
        try
        {
           return loc->cmd_ArgClear( index);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ArgResetAll(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_Command, loc);
        try
        {
           return loc->cmd_ArgResetAll();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ArgSetDatatypes(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_Command, loc);
        try
        {
           return loc->cmd_ArgSetDatatypes();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ArgUserName(LXtObjectID wcom,unsigned int index,const char **userName) -> LxResult
    {
        LXCWxINST (CLxImpl_Command, loc);
        try
        {
           return loc->cmd_ArgUserName( index, userName);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ArgDesc(LXtObjectID wcom,unsigned int index,const char **desc) -> LxResult
    {
        LXCWxINST (CLxImpl_Command, loc);
        try
        {
           return loc->cmd_ArgDesc( index, desc);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ArgExample(LXtObjectID wcom,unsigned int index,const char **example) -> LxResult
    {
        LXCWxINST (CLxImpl_Command, loc);
        try
        {
           return loc->cmd_ArgExample( index, example);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ArgType(LXtObjectID wcom,unsigned int index,const char **type) -> LxResult
    {
        LXCWxINST (CLxImpl_Command, loc);
        try
        {
           return loc->cmd_ArgType( index, type);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ArgTypeUserName(LXtObjectID wcom,unsigned int index,const char **userName) -> LxResult
    {
        LXCWxINST (CLxImpl_Command, loc);
        try
        {
           return loc->cmd_ArgTypeUserName( index, userName);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ArgTypeDesc(LXtObjectID wcom,unsigned int index,const char **desc) -> LxResult
    {
        LXCWxINST (CLxImpl_Command, loc);
        try
        {
           return loc->cmd_ArgTypeDesc( index, desc);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ArgOptionUserName(LXtObjectID wcom,unsigned int index,unsigned int optIndex,const char **userName) -> LxResult
    {
        LXCWxINST (CLxImpl_Command, loc);
        try
        {
           return loc->cmd_ArgOptionUserName( index, optIndex, userName);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ArgOptionDesc(LXtObjectID wcom,unsigned int index,unsigned int optIndex,const char **desc) -> LxResult
    {
        LXCWxINST (CLxImpl_Command, loc);
        try
        {
           return loc->cmd_ArgOptionDesc( index, optIndex, desc);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto DialogInit(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_Command, loc);
        try
        {
           return loc->cmd_DialogInit();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto DialogArgChange(LXtObjectID wcom,unsigned int arg) -> LxResult
    {
        LXCWxINST (CLxImpl_Command, loc);
        try
        {
           return loc->cmd_DialogArgChange( arg);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ArgEnable(LXtObjectID wcom,unsigned int arg) -> LxResult
    {
        LXCWxINST (CLxImpl_Command, loc);
        try
        {
           return loc->cmd_ArgEnable( arg);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ArgParseString(LXtObjectID wcom,unsigned int argIndex,const char *argString) -> LxResult
    {
        LXCWxINST (CLxImpl_Command, loc);
        try
        {
           return loc->cmd_ArgParseString( argIndex, argString);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Copy(LXtObjectID wcom,LXtObjectID sourceCommand) -> LxResult
    {
        LXCWxINST (CLxImpl_Command, loc);
        try
        {
           return loc->cmd_Copy((ILxUnknownID) sourceCommand);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Query(LXtObjectID wcom,unsigned int index,LXtObjectID vaQuery) -> LxResult
    {
        LXCWxINST (CLxImpl_Command, loc);
        try
        {
           return loc->cmd_Query( index,(ILxUnknownID) vaQuery);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto NotifyAddClient(LXtObjectID wcom,int argument,LXtObjectID object) -> LxResult
    {
        LXCWxINST (CLxImpl_Command, loc);
        try
        {
           return loc->cmd_NotifyAddClient( argument,(ILxUnknownID) object);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto NotifyRemoveClient(LXtObjectID wcom,LXtObjectID object) -> LxResult
    {
        LXCWxINST (CLxImpl_Command, loc);
        try
        {
           return loc->cmd_NotifyRemoveClient((ILxUnknownID) object);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto DialogFormatting(LXtObjectID wcom,const char **formatting) -> LxResult
    {
        LXCWxINST (CLxImpl_Command, loc);
        try
        {
           return loc->cmd_DialogFormatting( formatting);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto IconImage(LXtObjectID wcom,int w,int h,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_Command, loc);
        try
        {
           return loc->cmd_IconImage( w, h, ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ArgOptionIconName(LXtObjectID wcom,unsigned int index,unsigned int optIndex,const char **iconName) -> LxResult
    {
        LXCWxINST (CLxImpl_Command, loc);
        try
        {
           return loc->cmd_ArgOptionIconName( index, optIndex, iconName);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxCommand vt;
};

class CLxLoc_Command : public CLxLocalize<ILxCommandID>
{
public:
    CLxLoc_Command()
    {
        _init();
    }

    CLxLoc_Command(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_Command(CLxLoc_Command const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_Command;
    }

    auto Tag(LXtCommandTag *tag) -> LxResult
    {
        return m_loc[0]->Tag(m_loc, tag);
    }

    auto Name(const char **name) -> LxResult
    {
        return m_loc[0]->Name(m_loc, name);
    }

    auto UserName(const char **userName) -> LxResult
    {
        return m_loc[0]->UserName(m_loc, userName);
    }

    auto ButtonName(const char **buttonName) -> LxResult
    {
        return m_loc[0]->ButtonName(m_loc, buttonName);
    }

    auto Desc(const char **desc) -> LxResult
    {
        return m_loc[0]->Desc(m_loc, desc);
    }

    auto Tooltip(const char **tooltip) -> LxResult
    {
        return m_loc[0]->Tooltip(m_loc, tooltip);
    }

    auto Help(const char **help) -> LxResult
    {
        return m_loc[0]->Help(m_loc, help);
    }

    auto Example(const char **example) -> LxResult
    {
        return m_loc[0]->Example(m_loc, example);
    }

    auto Icon(const char **iconNames) -> LxResult
    {
        return m_loc[0]->Icon(m_loc, iconNames);
    }

    auto Flags(unsigned int *flags) -> LxResult
    {
        return m_loc[0]->Flags(m_loc, flags);
    }

    auto PostExecFlags(unsigned int *flags) -> LxResult
    {
        return m_loc[0]->PostExecFlags(m_loc, flags);
    }

    auto PostExecBehaviorFlags(unsigned int *flags) -> LxResult
    {
        return m_loc[0]->PostExecBehaviorFlags(m_loc, flags);
    }

    auto PostExecHints(unsigned int *hints) -> LxResult
    {
        return m_loc[0]->PostExecHints(m_loc, hints);
    }

    auto SandboxGUID(const LXtGUID **guid) -> LxResult
    {
        return m_loc[0]->SandboxGUID(m_loc, guid);
    }

    auto Message(void **ppvObj) -> LxResult
    {
        return m_loc[0]->Message(m_loc, ppvObj);
    }

    auto Message(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Message(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Enable(ILxUnknownID msg) -> LxResult
    {
        return m_loc[0]->Enable(m_loc,(ILxUnknownID) msg);
    }

    auto ContainedEnable(LXtID4 *types) -> LxResult
    {
        return m_loc[0]->ContainedEnable(m_loc, types);
    }

    auto Interact(void) -> void
    {
        m_loc[0]->Interact(m_loc);
    }

    auto PreExecute(void) -> void
    {
        m_loc[0]->PreExecute(m_loc);
    }

    auto Execute(unsigned int flags) -> void
    {
        m_loc[0]->Execute(m_loc, flags);
    }

    auto ToggleArg(unsigned int *index, void **ppvObj, unsigned int *typeID, const char **typeName) -> LxResult
    {
        return m_loc[0]->ToggleArg(m_loc, index, ppvObj, typeID, typeName);
    }

    auto ToggleArg(unsigned int *index, CLxLocalizedObject &o_dest, unsigned int *typeID, const char **typeName) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->ToggleArg(m_loc, index, &o_obj, typeID, typeName);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto ArgFlags(unsigned int index, unsigned int *flags) -> LxResult
    {
        return m_loc[0]->ArgFlags(m_loc, index, flags);
    }

    auto ArgClear(unsigned int index) -> LxResult
    {
        return m_loc[0]->ArgClear(m_loc, index);
    }

    auto ArgResetAll(void) -> LxResult
    {
        return m_loc[0]->ArgResetAll(m_loc);
    }

    auto ArgSetDatatypes(void) -> LxResult
    {
        return m_loc[0]->ArgSetDatatypes(m_loc);
    }

    auto ArgUserName(unsigned int index, const char **userName) -> LxResult
    {
        return m_loc[0]->ArgUserName(m_loc, index, userName);
    }

    auto ArgDesc(unsigned int index, const char **desc) -> LxResult
    {
        return m_loc[0]->ArgDesc(m_loc, index, desc);
    }

    auto ArgExample(unsigned int index, const char **example) -> LxResult
    {
        return m_loc[0]->ArgExample(m_loc, index, example);
    }

    auto ArgType(unsigned int index, const char **type) -> LxResult
    {
        return m_loc[0]->ArgType(m_loc, index, type);
    }

    auto ArgTypeUserName(unsigned int index, const char **userName) -> LxResult
    {
        return m_loc[0]->ArgTypeUserName(m_loc, index, userName);
    }

    auto ArgTypeDesc(unsigned int index, const char **desc) -> LxResult
    {
        return m_loc[0]->ArgTypeDesc(m_loc, index, desc);
    }

    auto ArgOptionUserName(unsigned int index, unsigned int optIndex, const char **userName) -> LxResult
    {
        return m_loc[0]->ArgOptionUserName(m_loc, index, optIndex, userName);
    }

    auto ArgOptionDesc(unsigned int index, unsigned int optIndex, const char **desc) -> LxResult
    {
        return m_loc[0]->ArgOptionDesc(m_loc, index, optIndex, desc);
    }

    auto DialogInit(void) -> LxResult
    {
        return m_loc[0]->DialogInit(m_loc);
    }

    auto DialogArgChange(unsigned int arg) -> LxResult
    {
        return m_loc[0]->DialogArgChange(m_loc, arg);
    }

    auto ArgEnable(unsigned int arg) -> LxResult
    {
        return m_loc[0]->ArgEnable(m_loc, arg);
    }

    auto ArgParseString(unsigned int argIndex, const char *argString) -> LxResult
    {
        return m_loc[0]->ArgParseString(m_loc, argIndex, argString);
    }

    auto Copy(ILxUnknownID sourceCommand) -> LxResult
    {
        return m_loc[0]->Copy(m_loc,(ILxUnknownID) sourceCommand);
    }

    auto Query(unsigned int index, ILxUnknownID vaQuery) -> LxResult
    {
        return m_loc[0]->Query(m_loc, index,(ILxUnknownID) vaQuery);
    }

    auto NotifyAddClient(int argument, ILxUnknownID object) -> LxResult
    {
        return m_loc[0]->NotifyAddClient(m_loc, argument,(ILxUnknownID) object);
    }

    auto NotifyRemoveClient(ILxUnknownID object) -> LxResult
    {
        return m_loc[0]->NotifyRemoveClient(m_loc,(ILxUnknownID) object);
    }

    auto DialogFormatting(const char **formatting) -> LxResult
    {
        return m_loc[0]->DialogFormatting(m_loc, formatting);
    }

    auto IconImage(int w, int h, void **ppvObj) -> LxResult
    {
        return m_loc[0]->IconImage(m_loc, w, h, ppvObj);
    }

    auto IconImage(int w, int h, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->IconImage(m_loc, w, h, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto ArgOptionIconName(unsigned int index, unsigned int optIndex, const char **iconName) -> LxResult
    {
        return m_loc[0]->ArgOptionIconName(m_loc, index, optIndex, iconName);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_CommandDBHelp : public CLxLocalize<ILxCommandDBHelpID>
{
public:
    CLxLoc_CommandDBHelp()
    {
        _init();
    }

    CLxLoc_CommandDBHelp(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_CommandDBHelp(CLxLoc_CommandDBHelp const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_CommandDBHelp;
    }

    auto DBHelp(const char **dbhelp) -> LxResult
    {
        return m_loc[0]->DBHelp(m_loc, dbhelp);
    }

    auto DBTooltip(const char **dbtooltip) -> LxResult
    {
        return m_loc[0]->DBTooltip(m_loc, dbtooltip);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_UIHints : public CLxLocalize<ILxUIHintsID>
{
public:
    CLxLoc_UIHints()
    {
        _init();
    }

    CLxLoc_UIHints(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_UIHints(CLxLoc_UIHints const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_UIHints;
    }

    auto Class(const char *c) -> LxResult
    {
        return m_loc[0]->Class(m_loc, c);
    }

    auto Label(const char *label) -> LxResult
    {
        return m_loc[0]->Label(m_loc, label);
    }

    auto MinInt(int min) -> LxResult
    {
        return m_loc[0]->MinInt(m_loc, min);
    }

    auto MaxInt(int max) -> LxResult
    {
        return m_loc[0]->MaxInt(m_loc, max);
    }

    auto MinFloat(double min) -> LxResult
    {
        return m_loc[0]->MinFloat(m_loc, min);
    }

    auto MaxFloat(double max) -> LxResult
    {
        return m_loc[0]->MaxFloat(m_loc, max);
    }

    auto StepInt(int step) -> LxResult
    {
        return m_loc[0]->StepInt(m_loc, step);
    }

    auto StepFloat(double step) -> LxResult
    {
        return m_loc[0]->StepFloat(m_loc, step);
    }

    auto Track(unsigned int state) -> LxResult
    {
        return m_loc[0]->Track(m_loc, state);
    }

    auto StringList(const char **strings) -> LxResult
    {
        return m_loc[0]->StringList(m_loc, strings);
    }

    auto TextLines(unsigned int lines) -> LxResult
    {
        return m_loc[0]->TextLines(m_loc, lines);
    }

    auto TextFixedWidthFont(unsigned int state) -> LxResult
    {
        return m_loc[0]->TextFixedWidthFont(m_loc, state);
    }

    auto TextPasswordMode(unsigned int state) -> LxResult
    {
        return m_loc[0]->TextPasswordMode(m_loc, state);
    }

    auto ValuePresetCookie(const char *cookie) -> LxResult
    {
        return m_loc[0]->ValuePresetCookie(m_loc, cookie);
    }

    auto ForceUpdate(void) -> LxResult
    {
        return m_loc[0]->ForceUpdate(m_loc);
    }

    auto BooleanStyle(unsigned int style) -> LxResult
    {
        return m_loc[0]->BooleanStyle(m_loc, style);
    }

    auto ChannelFlags(unsigned int flags) -> LxResult
    {
        return m_loc[0]->ChannelFlags(m_loc, flags);
    }

    auto ButtonHasPopoverDecoration(int state) -> LxResult
    {
        return m_loc[0]->ButtonHasPopoverDecoration(m_loc, state);
    }

    auto ClipChoiceSupportsGroups(unsigned flags) -> LxResult
    {
        return m_loc[0]->ClipChoiceSupportsGroups(m_loc, flags);
    }

    auto VertmapType(LXtID4 type) -> LxResult
    {
        return m_loc[0]->VertmapType(m_loc, type);
    }

    auto VertmapAllowNone(int state) -> LxResult
    {
        return m_loc[0]->VertmapAllowNone(m_loc, state);
    }

    auto VertmapItemMode(int state) -> LxResult
    {
        return m_loc[0]->VertmapItemMode(m_loc, state);
    }

    auto InfoTextUseSmallFont(int state) -> LxResult
    {
        return m_loc[0]->InfoTextUseSmallFont(m_loc, state);
    }

    auto FormFilterPriority(int priority) -> LxResult
    {
        return m_loc[0]->FormFilterPriority(m_loc, priority);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_UIHintsRead : public CLxLocalize<ILxUIHintsReadID>
{
public:
    CLxLoc_UIHintsRead()
    {
        _init();
    }

    CLxLoc_UIHintsRead(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_UIHintsRead(CLxLoc_UIHintsRead const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_UIHintsRead;
    }

    auto Class(char *buf, int len) -> LxResult
    {
        return m_loc[0]->Class(m_loc, buf, len);
    }

    auto Label(char *buf, int len) -> LxResult
    {
        return m_loc[0]->Label(m_loc, buf, len);
    }

    auto MinInt(int *min) -> LxResult
    {
        return m_loc[0]->MinInt(m_loc, min);
    }

    auto MaxInt(int *max) -> LxResult
    {
        return m_loc[0]->MaxInt(m_loc, max);
    }

    auto MinFloat(double *min) -> LxResult
    {
        return m_loc[0]->MinFloat(m_loc, min);
    }

    auto MaxFloat(double *max) -> LxResult
    {
        return m_loc[0]->MaxFloat(m_loc, max);
    }

    auto StepInt(int *step) -> LxResult
    {
        return m_loc[0]->StepInt(m_loc, step);
    }

    auto StepFloat(double *step) -> LxResult
    {
        return m_loc[0]->StepFloat(m_loc, step);
    }

    auto Track(unsigned int *state) -> LxResult
    {
        return m_loc[0]->Track(m_loc, state);
    }

    auto StringListCount(int *count) -> LxResult
    {
        return m_loc[0]->StringListCount(m_loc, count);
    }

    auto StringListByIndex(int index, char *buf, int len) -> LxResult
    {
        return m_loc[0]->StringListByIndex(m_loc, index, buf, len);
    }

    auto TextLines(unsigned int *lines) -> LxResult
    {
        return m_loc[0]->TextLines(m_loc, lines);
    }

    auto TextFixedWidthFont(unsigned int *state) -> LxResult
    {
        return m_loc[0]->TextFixedWidthFont(m_loc, state);
    }

    auto TextPasswordMode(unsigned int *state) -> LxResult
    {
        return m_loc[0]->TextPasswordMode(m_loc, state);
    }

    auto ValuePresetCookie(char *buf, int len) -> LxResult
    {
        return m_loc[0]->ValuePresetCookie(m_loc, buf, len);
    }

    auto ForceUpdate(int *state) -> LxResult
    {
        return m_loc[0]->ForceUpdate(m_loc, state);
    }

    auto BooleanStyle(unsigned int *style) -> LxResult
    {
        return m_loc[0]->BooleanStyle(m_loc, style);
    }

    auto ChannelFlags(unsigned int *flags) -> LxResult
    {
        return m_loc[0]->ChannelFlags(m_loc, flags);
    }

    auto ButtonHasPopoverDecoration(int *state) -> LxResult
    {
        return m_loc[0]->ButtonHasPopoverDecoration(m_loc, state);
    }

    auto ClipChoiceSupportsGroups(unsigned *flags) -> LxResult
    {
        return m_loc[0]->ClipChoiceSupportsGroups(m_loc, flags);
    }

    auto VertmapType(LXtID4 *type) -> LxResult
    {
        return m_loc[0]->VertmapType(m_loc, type);
    }

    auto VertmapAllowNone(int *state) -> LxResult
    {
        return m_loc[0]->VertmapAllowNone(m_loc, state);
    }

    auto VertmapItemMode(int *state) -> LxResult
    {
        return m_loc[0]->VertmapItemMode(m_loc, state);
    }

    auto InfoTextUseSmallFont(int *state) -> LxResult
    {
        return m_loc[0]->InfoTextUseSmallFont(m_loc, state);
    }

    auto FormFilterPriority(int *priority) -> LxResult
    {
        return m_loc[0]->FormFilterPriority(m_loc, priority);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_UIValueHints
{
public:
    virtual ~CLxImpl_UIValueHints() = default;

    virtual unsigned uiv_Flags(void) = 0;

    virtual unsigned uiv_PopCount(void) = 0;

    virtual const char * uiv_PopUserName(unsigned index) = 0;

    virtual const char * uiv_PopInternalName(unsigned index) = 0;

    virtual const char * uiv_PopToolTip(unsigned index) = 0;

    virtual unsigned uiv_PopIconSize(int *w, int *h) = 0;

    virtual auto uiv_PopIconImage([[maybe_unused]] int index, [[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto uiv_PopIconResource([[maybe_unused]] int index, [[maybe_unused]] const char **iconResource) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto uiv_PopFlags([[maybe_unused]] unsigned index, [[maybe_unused]] int *flags) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto uiv_PopCategory([[maybe_unused]] const char **category) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto uiv_ItemTest([[maybe_unused]] ILxUnknownID item) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto uiv_ColorPickerCommands([[maybe_unused]] char *rgb, [[maybe_unused]] char *alpha, [[maybe_unused]] char *rgbAlt, [[maybe_unused]] char *alphaAlt, [[maybe_unused]] char *useAlt, [[maybe_unused]] unsigned bufLens) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto uiv_NotifierCount([[maybe_unused]] int *count) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto uiv_NotifierByIndex([[maybe_unused]] int index, [[maybe_unused]] const char **name, [[maybe_unused]] const char **args) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto uiv_FormCommandListCount([[maybe_unused]] int *count) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto uiv_FormCommandListByIndex([[maybe_unused]] int index, [[maybe_unused]] const char **command) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto uiv_CueText([[maybe_unused]] char *buf, [[maybe_unused]] unsigned len) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto uiv_TextValidate([[maybe_unused]] const char *value, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_UIValueHints_Flags unsigned uiv_Flags() override
#define LXxO_UIValueHints_Flags LXxD_UIValueHints_Flags
#define LXxC_UIValueHints_Flags(c) unsigned c::uiv_Flags()
#define LXxD_UIValueHints_PopCount unsigned uiv_PopCount() override
#define LXxO_UIValueHints_PopCount LXxD_UIValueHints_PopCount
#define LXxC_UIValueHints_PopCount(c) unsigned c::uiv_PopCount()
#define LXxD_UIValueHints_PopUserName const char * uiv_PopUserName([[maybe_unused]] unsigned index) override
#define LXxO_UIValueHints_PopUserName LXxD_UIValueHints_PopUserName
#define LXxC_UIValueHints_PopUserName(c) const char * c::uiv_PopUserName([[maybe_unused]] unsigned index)
#define LXxD_UIValueHints_PopInternalName const char * uiv_PopInternalName([[maybe_unused]] unsigned index) override
#define LXxO_UIValueHints_PopInternalName LXxD_UIValueHints_PopInternalName
#define LXxC_UIValueHints_PopInternalName(c) const char * c::uiv_PopInternalName([[maybe_unused]] unsigned index)
#define LXxD_UIValueHints_PopToolTip const char * uiv_PopToolTip([[maybe_unused]] unsigned index) override
#define LXxO_UIValueHints_PopToolTip LXxD_UIValueHints_PopToolTip
#define LXxC_UIValueHints_PopToolTip(c) const char * c::uiv_PopToolTip([[maybe_unused]] unsigned index)
#define LXxD_UIValueHints_PopIconSize unsigned uiv_PopIconSize([[maybe_unused]] int *w, [[maybe_unused]] int *h) override
#define LXxO_UIValueHints_PopIconSize LXxD_UIValueHints_PopIconSize
#define LXxC_UIValueHints_PopIconSize(c) unsigned c::uiv_PopIconSize([[maybe_unused]] int *w, [[maybe_unused]] int *h)
#define LXxD_UIValueHints_PopIconImage LxResult uiv_PopIconImage([[maybe_unused]] int index, [[maybe_unused]] void **ppvObj) override
#define LXxO_UIValueHints_PopIconImage LXxD_UIValueHints_PopIconImage
#define LXxC_UIValueHints_PopIconImage(c) LxResult c::uiv_PopIconImage([[maybe_unused]] int index, [[maybe_unused]] void **ppvObj)
#define LXxD_UIValueHints_PopIconResource LxResult uiv_PopIconResource([[maybe_unused]] int index, [[maybe_unused]] const char **iconResource) override
#define LXxO_UIValueHints_PopIconResource LXxD_UIValueHints_PopIconResource
#define LXxC_UIValueHints_PopIconResource(c) LxResult c::uiv_PopIconResource([[maybe_unused]] int index, [[maybe_unused]] const char **iconResource)
#define LXxD_UIValueHints_PopFlags LxResult uiv_PopFlags([[maybe_unused]] unsigned index, [[maybe_unused]] int *flags) override
#define LXxO_UIValueHints_PopFlags LXxD_UIValueHints_PopFlags
#define LXxC_UIValueHints_PopFlags(c) LxResult c::uiv_PopFlags([[maybe_unused]] unsigned index, [[maybe_unused]] int *flags)
#define LXxD_UIValueHints_PopCategory LxResult uiv_PopCategory([[maybe_unused]] const char **category) override
#define LXxO_UIValueHints_PopCategory LXxD_UIValueHints_PopCategory
#define LXxC_UIValueHints_PopCategory(c) LxResult c::uiv_PopCategory([[maybe_unused]] const char **category)
#define LXxD_UIValueHints_ItemTest LxResult uiv_ItemTest([[maybe_unused]] ILxUnknownID item) override
#define LXxO_UIValueHints_ItemTest LXxD_UIValueHints_ItemTest
#define LXxC_UIValueHints_ItemTest(c) LxResult c::uiv_ItemTest([[maybe_unused]] ILxUnknownID item)
#define LXxD_UIValueHints_ColorPickerCommands LxResult uiv_ColorPickerCommands([[maybe_unused]] char *rgb, [[maybe_unused]] char *alpha, [[maybe_unused]] char *rgbAlt, [[maybe_unused]] char *alphaAlt, [[maybe_unused]] char *useAlt, [[maybe_unused]] unsigned bufLens) override
#define LXxO_UIValueHints_ColorPickerCommands LXxD_UIValueHints_ColorPickerCommands
#define LXxC_UIValueHints_ColorPickerCommands(c) LxResult c::uiv_ColorPickerCommands([[maybe_unused]] char *rgb, [[maybe_unused]] char *alpha, [[maybe_unused]] char *rgbAlt, [[maybe_unused]] char *alphaAlt, [[maybe_unused]] char *useAlt, [[maybe_unused]] unsigned bufLens)
#define LXxD_UIValueHints_NotifierCount LxResult uiv_NotifierCount([[maybe_unused]] int *count) override
#define LXxO_UIValueHints_NotifierCount LXxD_UIValueHints_NotifierCount
#define LXxC_UIValueHints_NotifierCount(c) LxResult c::uiv_NotifierCount([[maybe_unused]] int *count)
#define LXxD_UIValueHints_NotifierByIndex LxResult uiv_NotifierByIndex([[maybe_unused]] int index, [[maybe_unused]] const char **name, [[maybe_unused]] const char **args) override
#define LXxO_UIValueHints_NotifierByIndex LXxD_UIValueHints_NotifierByIndex
#define LXxC_UIValueHints_NotifierByIndex(c) LxResult c::uiv_NotifierByIndex([[maybe_unused]] int index, [[maybe_unused]] const char **name, [[maybe_unused]] const char **args)
#define LXxD_UIValueHints_FormCommandListCount LxResult uiv_FormCommandListCount([[maybe_unused]] int *count) override
#define LXxO_UIValueHints_FormCommandListCount LXxD_UIValueHints_FormCommandListCount
#define LXxC_UIValueHints_FormCommandListCount(c) LxResult c::uiv_FormCommandListCount([[maybe_unused]] int *count)
#define LXxD_UIValueHints_FormCommandListByIndex LxResult uiv_FormCommandListByIndex([[maybe_unused]] int index, [[maybe_unused]] const char **command) override
#define LXxO_UIValueHints_FormCommandListByIndex LXxD_UIValueHints_FormCommandListByIndex
#define LXxC_UIValueHints_FormCommandListByIndex(c) LxResult c::uiv_FormCommandListByIndex([[maybe_unused]] int index, [[maybe_unused]] const char **command)
#define LXxD_UIValueHints_CueText LxResult uiv_CueText([[maybe_unused]] char *buf, [[maybe_unused]] unsigned len) override
#define LXxO_UIValueHints_CueText LXxD_UIValueHints_CueText
#define LXxC_UIValueHints_CueText(c) LxResult c::uiv_CueText([[maybe_unused]] char *buf, [[maybe_unused]] unsigned len)
#define LXxD_UIValueHints_TextValidate LxResult uiv_TextValidate([[maybe_unused]] const char *value, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len) override
#define LXxO_UIValueHints_TextValidate LXxD_UIValueHints_TextValidate
#define LXxC_UIValueHints_TextValidate(c) LxResult c::uiv_TextValidate([[maybe_unused]] const char *value, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len)

template <class T>
class CLxIfc_UIValueHints: public CLxInterface
{
public:
    CLxIfc_UIValueHints()
    {
        vt.Flags = Flags;
        vt.PopCount = PopCount;
        vt.PopUserName = PopUserName;
        vt.PopInternalName = PopInternalName;
        vt.PopToolTip = PopToolTip;
        vt.PopIconSize = PopIconSize;
        vt.PopIconImage = PopIconImage;
        vt.PopIconResource = PopIconResource;
        vt.PopFlags = PopFlags;
        vt.PopCategory = PopCategory;
        vt.ItemTest = ItemTest;
        vt.ColorPickerCommands = ColorPickerCommands;
        vt.NotifierCount = NotifierCount;
        vt.NotifierByIndex = NotifierByIndex;
        vt.FormCommandListCount = FormCommandListCount;
        vt.FormCommandListByIndex = FormCommandListByIndex;
        vt.CueText = CueText;
        vt.TextValidate = TextValidate;
        vTable = &vt.iunk;
        iid = &lx::guid_UIValueHints;
    }

    static auto Flags(LXtObjectID wcom) -> unsigned
    {
        LXCWxINST (CLxImpl_UIValueHints, loc);
        return loc->uiv_Flags();
    }

    static auto PopCount(LXtObjectID wcom) -> unsigned
    {
        LXCWxINST (CLxImpl_UIValueHints, loc);
        return loc->uiv_PopCount();
    }

    static auto PopUserName(LXtObjectID wcom,unsigned index) -> const char *
    {
        LXCWxINST (CLxImpl_UIValueHints, loc);
        return loc->uiv_PopUserName( index);
    }

    static auto PopInternalName(LXtObjectID wcom,unsigned index) -> const char *
    {
        LXCWxINST (CLxImpl_UIValueHints, loc);
        return loc->uiv_PopInternalName( index);
    }

    static auto PopToolTip(LXtObjectID wcom,unsigned index) -> const char *
    {
        LXCWxINST (CLxImpl_UIValueHints, loc);
        return loc->uiv_PopToolTip( index);
    }

    static auto PopIconSize(LXtObjectID wcom,int *w,int *h) -> unsigned
    {
        LXCWxINST (CLxImpl_UIValueHints, loc);
        return loc->uiv_PopIconSize( w, h);
    }

    static auto PopIconImage(LXtObjectID wcom,int index,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_UIValueHints, loc);
        try
        {
           return loc->uiv_PopIconImage( index, ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto PopIconResource(LXtObjectID wcom,int index,const char **iconResource) -> LxResult
    {
        LXCWxINST (CLxImpl_UIValueHints, loc);
        try
        {
           return loc->uiv_PopIconResource( index, iconResource);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto PopFlags(LXtObjectID wcom,unsigned index,int *flags) -> LxResult
    {
        LXCWxINST (CLxImpl_UIValueHints, loc);
        try
        {
           return loc->uiv_PopFlags( index, flags);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto PopCategory(LXtObjectID wcom,const char **category) -> LxResult
    {
        LXCWxINST (CLxImpl_UIValueHints, loc);
        try
        {
           return loc->uiv_PopCategory( category);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ItemTest(LXtObjectID wcom,LXtObjectID item) -> LxResult
    {
        LXCWxINST (CLxImpl_UIValueHints, loc);
        try
        {
           return loc->uiv_ItemTest((ILxUnknownID) item);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ColorPickerCommands(LXtObjectID wcom,char *rgb,char *alpha,char *rgbAlt,char *alphaAlt,char *useAlt,unsigned bufLens) -> LxResult
    {
        LXCWxINST (CLxImpl_UIValueHints, loc);
        try
        {
           return loc->uiv_ColorPickerCommands( rgb, alpha, rgbAlt, alphaAlt, useAlt, bufLens);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto NotifierCount(LXtObjectID wcom,int *count) -> LxResult
    {
        LXCWxINST (CLxImpl_UIValueHints, loc);
        try
        {
           return loc->uiv_NotifierCount( count);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto NotifierByIndex(LXtObjectID wcom,int index,const char **name,const char **args) -> LxResult
    {
        LXCWxINST (CLxImpl_UIValueHints, loc);
        try
        {
           return loc->uiv_NotifierByIndex( index, name, args);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto FormCommandListCount(LXtObjectID wcom,int *count) -> LxResult
    {
        LXCWxINST (CLxImpl_UIValueHints, loc);
        try
        {
           return loc->uiv_FormCommandListCount( count);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto FormCommandListByIndex(LXtObjectID wcom,int index,const char **command) -> LxResult
    {
        LXCWxINST (CLxImpl_UIValueHints, loc);
        try
        {
           return loc->uiv_FormCommandListByIndex( index, command);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto CueText(LXtObjectID wcom,char *buf,unsigned len) -> LxResult
    {
        LXCWxINST (CLxImpl_UIValueHints, loc);
        try
        {
           return loc->uiv_CueText( buf, len);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto TextValidate(LXtObjectID wcom,const char *value,char *buf,unsigned len) -> LxResult
    {
        LXCWxINST (CLxImpl_UIValueHints, loc);
        try
        {
           return loc->uiv_TextValidate( value, buf, len);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxUIValueHints vt;
};

class CLxLoc_UIValueHints : public CLxLocalize<ILxUIValueHintsID>
{
public:
    CLxLoc_UIValueHints()
    {
        _init();
    }

    CLxLoc_UIValueHints(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_UIValueHints(CLxLoc_UIValueHints const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_UIValueHints;
    }

    auto Flags(void) -> unsigned
    {
        return m_loc[0]->Flags(m_loc);
    }

    auto PopCount(void) -> unsigned
    {
        return m_loc[0]->PopCount(m_loc);
    }

    auto PopUserName(unsigned index) -> const char *
    {
        return m_loc[0]->PopUserName(m_loc, index);
    }

    auto PopInternalName(unsigned index) -> const char *
    {
        return m_loc[0]->PopInternalName(m_loc, index);
    }

    auto PopToolTip(unsigned index) -> const char *
    {
        return m_loc[0]->PopToolTip(m_loc, index);
    }

    auto PopIconSize(int *w, int *h) -> unsigned
    {
        return m_loc[0]->PopIconSize(m_loc, w, h);
    }

    auto PopIconImage(int index, void **ppvObj) -> LxResult
    {
        return m_loc[0]->PopIconImage(m_loc, index, ppvObj);
    }

    auto PopIconImage(int index, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->PopIconImage(m_loc, index, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto PopIconResource(int index, const char **iconResource) -> LxResult
    {
        return m_loc[0]->PopIconResource(m_loc, index, iconResource);
    }

    auto PopFlags(unsigned index, int *flags) -> LxResult
    {
        return m_loc[0]->PopFlags(m_loc, index, flags);
    }

    auto PopCategory(const char **category) -> LxResult
    {
        return m_loc[0]->PopCategory(m_loc, category);
    }

    auto ItemTest(ILxUnknownID item) -> LxResult
    {
        return m_loc[0]->ItemTest(m_loc,(ILxUnknownID) item);
    }

    auto ColorPickerCommands(char *rgb, char *alpha, char *rgbAlt, char *alphaAlt, char *useAlt, unsigned bufLens) -> LxResult
    {
        return m_loc[0]->ColorPickerCommands(m_loc, rgb, alpha, rgbAlt, alphaAlt, useAlt, bufLens);
    }

    auto NotifierCount(int *count) -> LxResult
    {
        return m_loc[0]->NotifierCount(m_loc, count);
    }

    auto NotifierByIndex(int index, const char **name, const char **args) -> LxResult
    {
        return m_loc[0]->NotifierByIndex(m_loc, index, name, args);
    }

    auto FormCommandListCount(int *count) -> LxResult
    {
        return m_loc[0]->FormCommandListCount(m_loc, count);
    }

    auto FormCommandListByIndex(int index, const char **command) -> LxResult
    {
        return m_loc[0]->FormCommandListByIndex(m_loc, index, command);
    }

    auto CueText(char *buf, unsigned len) -> LxResult
    {
        return m_loc[0]->CueText(m_loc, buf, len);
    }

    auto CueText(std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->CueText(m_loc, buf, len);
        LXWx_SBUF2
    }

    auto TextValidate(const char *value, char *buf, unsigned len) -> LxResult
    {
        return m_loc[0]->TextValidate(m_loc, value, buf, len);
    }

    auto TextValidate(const char *value, std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->TextValidate(m_loc, value, buf, len);
        LXWx_SBUF2
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_UIValueHints3
{
public:
    virtual ~CLxImpl_UIValueHints3() = default;

    virtual unsigned uiv_Flags(void) = 0;

    virtual unsigned uiv_PopCount(void) = 0;

    virtual const char * uiv_PopUserName(unsigned index) = 0;

    virtual const char * uiv_PopInternalName(unsigned index) = 0;

    virtual const char * uiv_PopToolTip(unsigned index) = 0;

    virtual unsigned uiv_PopIconSize(int *w, int *h) = 0;

    virtual auto uiv_PopIconImage([[maybe_unused]] int index, [[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto uiv_PopIconResource([[maybe_unused]] int index, [[maybe_unused]] const char **iconResource) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto uiv_PopFlags([[maybe_unused]] unsigned index, [[maybe_unused]] int *flags) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto uiv_PopCategory([[maybe_unused]] const char **category) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto uiv_ItemTest([[maybe_unused]] ILxUnknownID item) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto uiv_ColorPickerCommands([[maybe_unused]] char *rgb, [[maybe_unused]] char *alpha, [[maybe_unused]] char *rgbAlt, [[maybe_unused]] char *alphaAlt, [[maybe_unused]] char *useAlt, [[maybe_unused]] unsigned bufLens) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto uiv_NotifierCount([[maybe_unused]] int *count) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto uiv_NotifierByIndex([[maybe_unused]] int index, [[maybe_unused]] const char **name, [[maybe_unused]] const char **args) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto uiv_FormCommandListCount([[maybe_unused]] int *count) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto uiv_FormCommandListByIndex([[maybe_unused]] int index, [[maybe_unused]] const char **command) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto uiv_CueText([[maybe_unused]] char *buf, [[maybe_unused]] unsigned len) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_UIValueHints3_Flags unsigned uiv_Flags() override
#define LXxO_UIValueHints3_Flags LXxD_UIValueHints3_Flags
#define LXxC_UIValueHints3_Flags(c) unsigned c::uiv_Flags()
#define LXxD_UIValueHints3_PopCount unsigned uiv_PopCount() override
#define LXxO_UIValueHints3_PopCount LXxD_UIValueHints3_PopCount
#define LXxC_UIValueHints3_PopCount(c) unsigned c::uiv_PopCount()
#define LXxD_UIValueHints3_PopUserName const char * uiv_PopUserName([[maybe_unused]] unsigned index) override
#define LXxO_UIValueHints3_PopUserName LXxD_UIValueHints3_PopUserName
#define LXxC_UIValueHints3_PopUserName(c) const char * c::uiv_PopUserName([[maybe_unused]] unsigned index)
#define LXxD_UIValueHints3_PopInternalName const char * uiv_PopInternalName([[maybe_unused]] unsigned index) override
#define LXxO_UIValueHints3_PopInternalName LXxD_UIValueHints3_PopInternalName
#define LXxC_UIValueHints3_PopInternalName(c) const char * c::uiv_PopInternalName([[maybe_unused]] unsigned index)
#define LXxD_UIValueHints3_PopToolTip const char * uiv_PopToolTip([[maybe_unused]] unsigned index) override
#define LXxO_UIValueHints3_PopToolTip LXxD_UIValueHints3_PopToolTip
#define LXxC_UIValueHints3_PopToolTip(c) const char * c::uiv_PopToolTip([[maybe_unused]] unsigned index)
#define LXxD_UIValueHints3_PopIconSize unsigned uiv_PopIconSize([[maybe_unused]] int *w, [[maybe_unused]] int *h) override
#define LXxO_UIValueHints3_PopIconSize LXxD_UIValueHints3_PopIconSize
#define LXxC_UIValueHints3_PopIconSize(c) unsigned c::uiv_PopIconSize([[maybe_unused]] int *w, [[maybe_unused]] int *h)
#define LXxD_UIValueHints3_PopIconImage LxResult uiv_PopIconImage([[maybe_unused]] int index, [[maybe_unused]] void **ppvObj) override
#define LXxO_UIValueHints3_PopIconImage LXxD_UIValueHints3_PopIconImage
#define LXxC_UIValueHints3_PopIconImage(c) LxResult c::uiv_PopIconImage([[maybe_unused]] int index, [[maybe_unused]] void **ppvObj)
#define LXxD_UIValueHints3_PopIconResource LxResult uiv_PopIconResource([[maybe_unused]] int index, [[maybe_unused]] const char **iconResource) override
#define LXxO_UIValueHints3_PopIconResource LXxD_UIValueHints3_PopIconResource
#define LXxC_UIValueHints3_PopIconResource(c) LxResult c::uiv_PopIconResource([[maybe_unused]] int index, [[maybe_unused]] const char **iconResource)
#define LXxD_UIValueHints3_PopFlags LxResult uiv_PopFlags([[maybe_unused]] unsigned index, [[maybe_unused]] int *flags) override
#define LXxO_UIValueHints3_PopFlags LXxD_UIValueHints3_PopFlags
#define LXxC_UIValueHints3_PopFlags(c) LxResult c::uiv_PopFlags([[maybe_unused]] unsigned index, [[maybe_unused]] int *flags)
#define LXxD_UIValueHints3_PopCategory LxResult uiv_PopCategory([[maybe_unused]] const char **category) override
#define LXxO_UIValueHints3_PopCategory LXxD_UIValueHints3_PopCategory
#define LXxC_UIValueHints3_PopCategory(c) LxResult c::uiv_PopCategory([[maybe_unused]] const char **category)
#define LXxD_UIValueHints3_ItemTest LxResult uiv_ItemTest([[maybe_unused]] ILxUnknownID item) override
#define LXxO_UIValueHints3_ItemTest LXxD_UIValueHints3_ItemTest
#define LXxC_UIValueHints3_ItemTest(c) LxResult c::uiv_ItemTest([[maybe_unused]] ILxUnknownID item)
#define LXxD_UIValueHints3_ColorPickerCommands LxResult uiv_ColorPickerCommands([[maybe_unused]] char *rgb, [[maybe_unused]] char *alpha, [[maybe_unused]] char *rgbAlt, [[maybe_unused]] char *alphaAlt, [[maybe_unused]] char *useAlt, [[maybe_unused]] unsigned bufLens) override
#define LXxO_UIValueHints3_ColorPickerCommands LXxD_UIValueHints3_ColorPickerCommands
#define LXxC_UIValueHints3_ColorPickerCommands(c) LxResult c::uiv_ColorPickerCommands([[maybe_unused]] char *rgb, [[maybe_unused]] char *alpha, [[maybe_unused]] char *rgbAlt, [[maybe_unused]] char *alphaAlt, [[maybe_unused]] char *useAlt, [[maybe_unused]] unsigned bufLens)
#define LXxD_UIValueHints3_NotifierCount LxResult uiv_NotifierCount([[maybe_unused]] int *count) override
#define LXxO_UIValueHints3_NotifierCount LXxD_UIValueHints3_NotifierCount
#define LXxC_UIValueHints3_NotifierCount(c) LxResult c::uiv_NotifierCount([[maybe_unused]] int *count)
#define LXxD_UIValueHints3_NotifierByIndex LxResult uiv_NotifierByIndex([[maybe_unused]] int index, [[maybe_unused]] const char **name, [[maybe_unused]] const char **args) override
#define LXxO_UIValueHints3_NotifierByIndex LXxD_UIValueHints3_NotifierByIndex
#define LXxC_UIValueHints3_NotifierByIndex(c) LxResult c::uiv_NotifierByIndex([[maybe_unused]] int index, [[maybe_unused]] const char **name, [[maybe_unused]] const char **args)
#define LXxD_UIValueHints3_FormCommandListCount LxResult uiv_FormCommandListCount([[maybe_unused]] int *count) override
#define LXxO_UIValueHints3_FormCommandListCount LXxD_UIValueHints3_FormCommandListCount
#define LXxC_UIValueHints3_FormCommandListCount(c) LxResult c::uiv_FormCommandListCount([[maybe_unused]] int *count)
#define LXxD_UIValueHints3_FormCommandListByIndex LxResult uiv_FormCommandListByIndex([[maybe_unused]] int index, [[maybe_unused]] const char **command) override
#define LXxO_UIValueHints3_FormCommandListByIndex LXxD_UIValueHints3_FormCommandListByIndex
#define LXxC_UIValueHints3_FormCommandListByIndex(c) LxResult c::uiv_FormCommandListByIndex([[maybe_unused]] int index, [[maybe_unused]] const char **command)
#define LXxD_UIValueHints3_CueText LxResult uiv_CueText([[maybe_unused]] char *buf, [[maybe_unused]] unsigned len) override
#define LXxO_UIValueHints3_CueText LXxD_UIValueHints3_CueText
#define LXxC_UIValueHints3_CueText(c) LxResult c::uiv_CueText([[maybe_unused]] char *buf, [[maybe_unused]] unsigned len)

template <class T>
class CLxIfc_UIValueHints3: public CLxInterface
{
public:
    CLxIfc_UIValueHints3()
    {
        vt.Flags = Flags;
        vt.PopCount = PopCount;
        vt.PopUserName = PopUserName;
        vt.PopInternalName = PopInternalName;
        vt.PopToolTip = PopToolTip;
        vt.PopIconSize = PopIconSize;
        vt.PopIconImage = PopIconImage;
        vt.PopIconResource = PopIconResource;
        vt.PopFlags = PopFlags;
        vt.PopCategory = PopCategory;
        vt.ItemTest = ItemTest;
        vt.ColorPickerCommands = ColorPickerCommands;
        vt.NotifierCount = NotifierCount;
        vt.NotifierByIndex = NotifierByIndex;
        vt.FormCommandListCount = FormCommandListCount;
        vt.FormCommandListByIndex = FormCommandListByIndex;
        vt.CueText = CueText;
        vTable = &vt.iunk;
        iid = &lx::guid_UIValueHints3;
    }

    static auto Flags(LXtObjectID wcom) -> unsigned
    {
        LXCWxINST (CLxImpl_UIValueHints3, loc);
        return loc->uiv_Flags();
    }

    static auto PopCount(LXtObjectID wcom) -> unsigned
    {
        LXCWxINST (CLxImpl_UIValueHints3, loc);
        return loc->uiv_PopCount();
    }

    static auto PopUserName(LXtObjectID wcom,unsigned index) -> const char *
    {
        LXCWxINST (CLxImpl_UIValueHints3, loc);
        return loc->uiv_PopUserName( index);
    }

    static auto PopInternalName(LXtObjectID wcom,unsigned index) -> const char *
    {
        LXCWxINST (CLxImpl_UIValueHints3, loc);
        return loc->uiv_PopInternalName( index);
    }

    static auto PopToolTip(LXtObjectID wcom,unsigned index) -> const char *
    {
        LXCWxINST (CLxImpl_UIValueHints3, loc);
        return loc->uiv_PopToolTip( index);
    }

    static auto PopIconSize(LXtObjectID wcom,int *w,int *h) -> unsigned
    {
        LXCWxINST (CLxImpl_UIValueHints3, loc);
        return loc->uiv_PopIconSize( w, h);
    }

    static auto PopIconImage(LXtObjectID wcom,int index,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_UIValueHints3, loc);
        try
        {
           return loc->uiv_PopIconImage( index, ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto PopIconResource(LXtObjectID wcom,int index,const char **iconResource) -> LxResult
    {
        LXCWxINST (CLxImpl_UIValueHints3, loc);
        try
        {
           return loc->uiv_PopIconResource( index, iconResource);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto PopFlags(LXtObjectID wcom,unsigned index,int *flags) -> LxResult
    {
        LXCWxINST (CLxImpl_UIValueHints3, loc);
        try
        {
           return loc->uiv_PopFlags( index, flags);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto PopCategory(LXtObjectID wcom,const char **category) -> LxResult
    {
        LXCWxINST (CLxImpl_UIValueHints3, loc);
        try
        {
           return loc->uiv_PopCategory( category);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ItemTest(LXtObjectID wcom,LXtObjectID item) -> LxResult
    {
        LXCWxINST (CLxImpl_UIValueHints3, loc);
        try
        {
           return loc->uiv_ItemTest((ILxUnknownID) item);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ColorPickerCommands(LXtObjectID wcom,char *rgb,char *alpha,char *rgbAlt,char *alphaAlt,char *useAlt,unsigned bufLens) -> LxResult
    {
        LXCWxINST (CLxImpl_UIValueHints3, loc);
        try
        {
           return loc->uiv_ColorPickerCommands( rgb, alpha, rgbAlt, alphaAlt, useAlt, bufLens);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto NotifierCount(LXtObjectID wcom,int *count) -> LxResult
    {
        LXCWxINST (CLxImpl_UIValueHints3, loc);
        try
        {
           return loc->uiv_NotifierCount( count);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto NotifierByIndex(LXtObjectID wcom,int index,const char **name,const char **args) -> LxResult
    {
        LXCWxINST (CLxImpl_UIValueHints3, loc);
        try
        {
           return loc->uiv_NotifierByIndex( index, name, args);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto FormCommandListCount(LXtObjectID wcom,int *count) -> LxResult
    {
        LXCWxINST (CLxImpl_UIValueHints3, loc);
        try
        {
           return loc->uiv_FormCommandListCount( count);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto FormCommandListByIndex(LXtObjectID wcom,int index,const char **command) -> LxResult
    {
        LXCWxINST (CLxImpl_UIValueHints3, loc);
        try
        {
           return loc->uiv_FormCommandListByIndex( index, command);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto CueText(LXtObjectID wcom,char *buf,unsigned len) -> LxResult
    {
        LXCWxINST (CLxImpl_UIValueHints3, loc);
        try
        {
           return loc->uiv_CueText( buf, len);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxUIValueHints3 vt;
};

class CLxLoc_UIValueHints3 : public CLxLocalize<ILxUIValueHints3ID>
{
public:
    CLxLoc_UIValueHints3()
    {
        _init();
    }

    CLxLoc_UIValueHints3(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_UIValueHints3(CLxLoc_UIValueHints3 const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_UIValueHints3;
    }

    auto Flags(void) -> unsigned
    {
        return m_loc[0]->Flags(m_loc);
    }

    auto PopCount(void) -> unsigned
    {
        return m_loc[0]->PopCount(m_loc);
    }

    auto PopUserName(unsigned index) -> const char *
    {
        return m_loc[0]->PopUserName(m_loc, index);
    }

    auto PopInternalName(unsigned index) -> const char *
    {
        return m_loc[0]->PopInternalName(m_loc, index);
    }

    auto PopToolTip(unsigned index) -> const char *
    {
        return m_loc[0]->PopToolTip(m_loc, index);
    }

    auto PopIconSize(int *w, int *h) -> unsigned
    {
        return m_loc[0]->PopIconSize(m_loc, w, h);
    }

    auto PopIconImage(int index, void **ppvObj) -> LxResult
    {
        return m_loc[0]->PopIconImage(m_loc, index, ppvObj);
    }

    auto PopIconImage(int index, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->PopIconImage(m_loc, index, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto PopIconResource(int index, const char **iconResource) -> LxResult
    {
        return m_loc[0]->PopIconResource(m_loc, index, iconResource);
    }

    auto PopFlags(unsigned index, int *flags) -> LxResult
    {
        return m_loc[0]->PopFlags(m_loc, index, flags);
    }

    auto PopCategory(const char **category) -> LxResult
    {
        return m_loc[0]->PopCategory(m_loc, category);
    }

    auto ItemTest(ILxUnknownID item) -> LxResult
    {
        return m_loc[0]->ItemTest(m_loc,(ILxUnknownID) item);
    }

    auto ColorPickerCommands(char *rgb, char *alpha, char *rgbAlt, char *alphaAlt, char *useAlt, unsigned bufLens) -> LxResult
    {
        return m_loc[0]->ColorPickerCommands(m_loc, rgb, alpha, rgbAlt, alphaAlt, useAlt, bufLens);
    }

    auto NotifierCount(int *count) -> LxResult
    {
        return m_loc[0]->NotifierCount(m_loc, count);
    }

    auto NotifierByIndex(int index, const char **name, const char **args) -> LxResult
    {
        return m_loc[0]->NotifierByIndex(m_loc, index, name, args);
    }

    auto FormCommandListCount(int *count) -> LxResult
    {
        return m_loc[0]->FormCommandListCount(m_loc, count);
    }

    auto FormCommandListByIndex(int index, const char **command) -> LxResult
    {
        return m_loc[0]->FormCommandListByIndex(m_loc, index, command);
    }

    auto CueText(char *buf, unsigned len) -> LxResult
    {
        return m_loc[0]->CueText(m_loc, buf, len);
    }

    auto CueText(std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->CueText(m_loc, buf, len);
        LXWx_SBUF2
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_UIValueHints2
{
public:
    virtual ~CLxImpl_UIValueHints2() = default;

    virtual unsigned uiv_Flags(void) = 0;

    virtual unsigned uiv_PopCount(void) = 0;

    virtual const char * uiv_PopUserName(unsigned index) = 0;

    virtual const char * uiv_PopInternalName(unsigned index) = 0;

    virtual unsigned uiv_PopIconSize(int *w, int *h) = 0;

    virtual auto uiv_PopIconImage([[maybe_unused]] int index, [[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto uiv_PopIconResource([[maybe_unused]] int index, [[maybe_unused]] const char **iconResource) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto uiv_PopFlags([[maybe_unused]] unsigned index, [[maybe_unused]] int *flags) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto uiv_PopCategory([[maybe_unused]] const char **category) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto uiv_ItemTest([[maybe_unused]] ILxUnknownID item) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto uiv_ColorPickerCommands([[maybe_unused]] char *rgb, [[maybe_unused]] char *alpha, [[maybe_unused]] char *rgbAlt, [[maybe_unused]] char *alphaAlt, [[maybe_unused]] char *useAlt, [[maybe_unused]] unsigned bufLens) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto uiv_NotifierCount([[maybe_unused]] int *count) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto uiv_NotifierByIndex([[maybe_unused]] int index, [[maybe_unused]] const char **name, [[maybe_unused]] const char **args) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto uiv_FormCommandListCount([[maybe_unused]] int *count) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto uiv_FormCommandListByIndex([[maybe_unused]] int index, [[maybe_unused]] const char **command) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_UIValueHints2_Flags unsigned uiv_Flags() override
#define LXxO_UIValueHints2_Flags LXxD_UIValueHints2_Flags
#define LXxC_UIValueHints2_Flags(c) unsigned c::uiv_Flags()
#define LXxD_UIValueHints2_PopCount unsigned uiv_PopCount() override
#define LXxO_UIValueHints2_PopCount LXxD_UIValueHints2_PopCount
#define LXxC_UIValueHints2_PopCount(c) unsigned c::uiv_PopCount()
#define LXxD_UIValueHints2_PopUserName const char * uiv_PopUserName([[maybe_unused]] unsigned index) override
#define LXxO_UIValueHints2_PopUserName LXxD_UIValueHints2_PopUserName
#define LXxC_UIValueHints2_PopUserName(c) const char * c::uiv_PopUserName([[maybe_unused]] unsigned index)
#define LXxD_UIValueHints2_PopInternalName const char * uiv_PopInternalName([[maybe_unused]] unsigned index) override
#define LXxO_UIValueHints2_PopInternalName LXxD_UIValueHints2_PopInternalName
#define LXxC_UIValueHints2_PopInternalName(c) const char * c::uiv_PopInternalName([[maybe_unused]] unsigned index)
#define LXxD_UIValueHints2_PopIconSize unsigned uiv_PopIconSize([[maybe_unused]] int *w, [[maybe_unused]] int *h) override
#define LXxO_UIValueHints2_PopIconSize LXxD_UIValueHints2_PopIconSize
#define LXxC_UIValueHints2_PopIconSize(c) unsigned c::uiv_PopIconSize([[maybe_unused]] int *w, [[maybe_unused]] int *h)
#define LXxD_UIValueHints2_PopIconImage LxResult uiv_PopIconImage([[maybe_unused]] int index, [[maybe_unused]] void **ppvObj) override
#define LXxO_UIValueHints2_PopIconImage LXxD_UIValueHints2_PopIconImage
#define LXxC_UIValueHints2_PopIconImage(c) LxResult c::uiv_PopIconImage([[maybe_unused]] int index, [[maybe_unused]] void **ppvObj)
#define LXxD_UIValueHints2_PopIconResource LxResult uiv_PopIconResource([[maybe_unused]] int index, [[maybe_unused]] const char **iconResource) override
#define LXxO_UIValueHints2_PopIconResource LXxD_UIValueHints2_PopIconResource
#define LXxC_UIValueHints2_PopIconResource(c) LxResult c::uiv_PopIconResource([[maybe_unused]] int index, [[maybe_unused]] const char **iconResource)
#define LXxD_UIValueHints2_PopFlags LxResult uiv_PopFlags([[maybe_unused]] unsigned index, [[maybe_unused]] int *flags) override
#define LXxO_UIValueHints2_PopFlags LXxD_UIValueHints2_PopFlags
#define LXxC_UIValueHints2_PopFlags(c) LxResult c::uiv_PopFlags([[maybe_unused]] unsigned index, [[maybe_unused]] int *flags)
#define LXxD_UIValueHints2_PopCategory LxResult uiv_PopCategory([[maybe_unused]] const char **category) override
#define LXxO_UIValueHints2_PopCategory LXxD_UIValueHints2_PopCategory
#define LXxC_UIValueHints2_PopCategory(c) LxResult c::uiv_PopCategory([[maybe_unused]] const char **category)
#define LXxD_UIValueHints2_ItemTest LxResult uiv_ItemTest([[maybe_unused]] ILxUnknownID item) override
#define LXxO_UIValueHints2_ItemTest LXxD_UIValueHints2_ItemTest
#define LXxC_UIValueHints2_ItemTest(c) LxResult c::uiv_ItemTest([[maybe_unused]] ILxUnknownID item)
#define LXxD_UIValueHints2_ColorPickerCommands LxResult uiv_ColorPickerCommands([[maybe_unused]] char *rgb, [[maybe_unused]] char *alpha, [[maybe_unused]] char *rgbAlt, [[maybe_unused]] char *alphaAlt, [[maybe_unused]] char *useAlt, [[maybe_unused]] unsigned bufLens) override
#define LXxO_UIValueHints2_ColorPickerCommands LXxD_UIValueHints2_ColorPickerCommands
#define LXxC_UIValueHints2_ColorPickerCommands(c) LxResult c::uiv_ColorPickerCommands([[maybe_unused]] char *rgb, [[maybe_unused]] char *alpha, [[maybe_unused]] char *rgbAlt, [[maybe_unused]] char *alphaAlt, [[maybe_unused]] char *useAlt, [[maybe_unused]] unsigned bufLens)
#define LXxD_UIValueHints2_NotifierCount LxResult uiv_NotifierCount([[maybe_unused]] int *count) override
#define LXxO_UIValueHints2_NotifierCount LXxD_UIValueHints2_NotifierCount
#define LXxC_UIValueHints2_NotifierCount(c) LxResult c::uiv_NotifierCount([[maybe_unused]] int *count)
#define LXxD_UIValueHints2_NotifierByIndex LxResult uiv_NotifierByIndex([[maybe_unused]] int index, [[maybe_unused]] const char **name, [[maybe_unused]] const char **args) override
#define LXxO_UIValueHints2_NotifierByIndex LXxD_UIValueHints2_NotifierByIndex
#define LXxC_UIValueHints2_NotifierByIndex(c) LxResult c::uiv_NotifierByIndex([[maybe_unused]] int index, [[maybe_unused]] const char **name, [[maybe_unused]] const char **args)
#define LXxD_UIValueHints2_FormCommandListCount LxResult uiv_FormCommandListCount([[maybe_unused]] int *count) override
#define LXxO_UIValueHints2_FormCommandListCount LXxD_UIValueHints2_FormCommandListCount
#define LXxC_UIValueHints2_FormCommandListCount(c) LxResult c::uiv_FormCommandListCount([[maybe_unused]] int *count)
#define LXxD_UIValueHints2_FormCommandListByIndex LxResult uiv_FormCommandListByIndex([[maybe_unused]] int index, [[maybe_unused]] const char **command) override
#define LXxO_UIValueHints2_FormCommandListByIndex LXxD_UIValueHints2_FormCommandListByIndex
#define LXxC_UIValueHints2_FormCommandListByIndex(c) LxResult c::uiv_FormCommandListByIndex([[maybe_unused]] int index, [[maybe_unused]] const char **command)

template <class T>
class CLxIfc_UIValueHints2: public CLxInterface
{
public:
    CLxIfc_UIValueHints2()
    {
        vt.Flags = Flags;
        vt.PopCount = PopCount;
        vt.PopUserName = PopUserName;
        vt.PopInternalName = PopInternalName;
        vt.PopIconSize = PopIconSize;
        vt.PopIconImage = PopIconImage;
        vt.PopIconResource = PopIconResource;
        vt.PopFlags = PopFlags;
        vt.PopCategory = PopCategory;
        vt.ItemTest = ItemTest;
        vt.ColorPickerCommands = ColorPickerCommands;
        vt.NotifierCount = NotifierCount;
        vt.NotifierByIndex = NotifierByIndex;
        vt.FormCommandListCount = FormCommandListCount;
        vt.FormCommandListByIndex = FormCommandListByIndex;
        vTable = &vt.iunk;
        iid = &lx::guid_UIValueHints2;
    }

    static auto Flags(LXtObjectID wcom) -> unsigned
    {
        LXCWxINST (CLxImpl_UIValueHints2, loc);
        return loc->uiv_Flags();
    }

    static auto PopCount(LXtObjectID wcom) -> unsigned
    {
        LXCWxINST (CLxImpl_UIValueHints2, loc);
        return loc->uiv_PopCount();
    }

    static auto PopUserName(LXtObjectID wcom,unsigned index) -> const char *
    {
        LXCWxINST (CLxImpl_UIValueHints2, loc);
        return loc->uiv_PopUserName( index);
    }

    static auto PopInternalName(LXtObjectID wcom,unsigned index) -> const char *
    {
        LXCWxINST (CLxImpl_UIValueHints2, loc);
        return loc->uiv_PopInternalName( index);
    }

    static auto PopIconSize(LXtObjectID wcom,int *w,int *h) -> unsigned
    {
        LXCWxINST (CLxImpl_UIValueHints2, loc);
        return loc->uiv_PopIconSize( w, h);
    }

    static auto PopIconImage(LXtObjectID wcom,int index,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_UIValueHints2, loc);
        try
        {
           return loc->uiv_PopIconImage( index, ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto PopIconResource(LXtObjectID wcom,int index,const char **iconResource) -> LxResult
    {
        LXCWxINST (CLxImpl_UIValueHints2, loc);
        try
        {
           return loc->uiv_PopIconResource( index, iconResource);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto PopFlags(LXtObjectID wcom,unsigned index,int *flags) -> LxResult
    {
        LXCWxINST (CLxImpl_UIValueHints2, loc);
        try
        {
           return loc->uiv_PopFlags( index, flags);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto PopCategory(LXtObjectID wcom,const char **category) -> LxResult
    {
        LXCWxINST (CLxImpl_UIValueHints2, loc);
        try
        {
           return loc->uiv_PopCategory( category);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ItemTest(LXtObjectID wcom,LXtObjectID item) -> LxResult
    {
        LXCWxINST (CLxImpl_UIValueHints2, loc);
        try
        {
           return loc->uiv_ItemTest((ILxUnknownID) item);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ColorPickerCommands(LXtObjectID wcom,char *rgb,char *alpha,char *rgbAlt,char *alphaAlt,char *useAlt,unsigned bufLens) -> LxResult
    {
        LXCWxINST (CLxImpl_UIValueHints2, loc);
        try
        {
           return loc->uiv_ColorPickerCommands( rgb, alpha, rgbAlt, alphaAlt, useAlt, bufLens);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto NotifierCount(LXtObjectID wcom,int *count) -> LxResult
    {
        LXCWxINST (CLxImpl_UIValueHints2, loc);
        try
        {
           return loc->uiv_NotifierCount( count);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto NotifierByIndex(LXtObjectID wcom,int index,const char **name,const char **args) -> LxResult
    {
        LXCWxINST (CLxImpl_UIValueHints2, loc);
        try
        {
           return loc->uiv_NotifierByIndex( index, name, args);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto FormCommandListCount(LXtObjectID wcom,int *count) -> LxResult
    {
        LXCWxINST (CLxImpl_UIValueHints2, loc);
        try
        {
           return loc->uiv_FormCommandListCount( count);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto FormCommandListByIndex(LXtObjectID wcom,int index,const char **command) -> LxResult
    {
        LXCWxINST (CLxImpl_UIValueHints2, loc);
        try
        {
           return loc->uiv_FormCommandListByIndex( index, command);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxUIValueHints2 vt;
};

class CLxLoc_UIValueHints2 : public CLxLocalize<ILxUIValueHints2ID>
{
public:
    CLxLoc_UIValueHints2()
    {
        _init();
    }

    CLxLoc_UIValueHints2(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_UIValueHints2(CLxLoc_UIValueHints2 const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_UIValueHints2;
    }

    auto Flags(void) -> unsigned
    {
        return m_loc[0]->Flags(m_loc);
    }

    auto PopCount(void) -> unsigned
    {
        return m_loc[0]->PopCount(m_loc);
    }

    auto PopUserName(unsigned index) -> const char *
    {
        return m_loc[0]->PopUserName(m_loc, index);
    }

    auto PopInternalName(unsigned index) -> const char *
    {
        return m_loc[0]->PopInternalName(m_loc, index);
    }

    auto PopIconSize(int *w, int *h) -> unsigned
    {
        return m_loc[0]->PopIconSize(m_loc, w, h);
    }

    auto PopIconImage(int index, void **ppvObj) -> LxResult
    {
        return m_loc[0]->PopIconImage(m_loc, index, ppvObj);
    }

    auto PopIconImage(int index, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->PopIconImage(m_loc, index, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto PopIconResource(int index, const char **iconResource) -> LxResult
    {
        return m_loc[0]->PopIconResource(m_loc, index, iconResource);
    }

    auto PopFlags(unsigned index, int *flags) -> LxResult
    {
        return m_loc[0]->PopFlags(m_loc, index, flags);
    }

    auto PopCategory(const char **category) -> LxResult
    {
        return m_loc[0]->PopCategory(m_loc, category);
    }

    auto ItemTest(ILxUnknownID item) -> LxResult
    {
        return m_loc[0]->ItemTest(m_loc,(ILxUnknownID) item);
    }

    auto ColorPickerCommands(char *rgb, char *alpha, char *rgbAlt, char *alphaAlt, char *useAlt, unsigned bufLens) -> LxResult
    {
        return m_loc[0]->ColorPickerCommands(m_loc, rgb, alpha, rgbAlt, alphaAlt, useAlt, bufLens);
    }

    auto NotifierCount(int *count) -> LxResult
    {
        return m_loc[0]->NotifierCount(m_loc, count);
    }

    auto NotifierByIndex(int index, const char **name, const char **args) -> LxResult
    {
        return m_loc[0]->NotifierByIndex(m_loc, index, name, args);
    }

    auto FormCommandListCount(int *count) -> LxResult
    {
        return m_loc[0]->FormCommandListCount(m_loc, count);
    }

    auto FormCommandListByIndex(int index, const char **command) -> LxResult
    {
        return m_loc[0]->FormCommandListByIndex(m_loc, index, command);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_UIValueHints1
{
public:
    virtual ~CLxImpl_UIValueHints1() = default;

    virtual unsigned uiv_Flags(void) = 0;

    virtual unsigned uiv_PopCount(void) = 0;

    virtual const char * uiv_PopUserName(unsigned index) = 0;

    virtual const char * uiv_PopInternalName(unsigned index) = 0;

    virtual auto uiv_PopFlags([[maybe_unused]] unsigned index, [[maybe_unused]] int *flags) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto uiv_PopCategory([[maybe_unused]] const char **category) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto uiv_ItemTest([[maybe_unused]] ILxUnknownID item) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto uiv_ColorPickerCommands([[maybe_unused]] char *rgb, [[maybe_unused]] char *alpha, [[maybe_unused]] char *rgbAlt, [[maybe_unused]] char *alphaAlt, [[maybe_unused]] char *useAlt, [[maybe_unused]] unsigned bufLens) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto uiv_NotifierCount([[maybe_unused]] int *count) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto uiv_NotifierByIndex([[maybe_unused]] const char **name, [[maybe_unused]] const char **args) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto uiv_FormCommandListCount([[maybe_unused]] int *count) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto uiv_FormCommandListByIndex([[maybe_unused]] int index, [[maybe_unused]] const char **command) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_UIValueHints1_Flags unsigned uiv_Flags() override
#define LXxO_UIValueHints1_Flags LXxD_UIValueHints1_Flags
#define LXxC_UIValueHints1_Flags(c) unsigned c::uiv_Flags()
#define LXxD_UIValueHints1_PopCount unsigned uiv_PopCount() override
#define LXxO_UIValueHints1_PopCount LXxD_UIValueHints1_PopCount
#define LXxC_UIValueHints1_PopCount(c) unsigned c::uiv_PopCount()
#define LXxD_UIValueHints1_PopUserName const char * uiv_PopUserName([[maybe_unused]] unsigned index) override
#define LXxO_UIValueHints1_PopUserName LXxD_UIValueHints1_PopUserName
#define LXxC_UIValueHints1_PopUserName(c) const char * c::uiv_PopUserName([[maybe_unused]] unsigned index)
#define LXxD_UIValueHints1_PopInternalName const char * uiv_PopInternalName([[maybe_unused]] unsigned index) override
#define LXxO_UIValueHints1_PopInternalName LXxD_UIValueHints1_PopInternalName
#define LXxC_UIValueHints1_PopInternalName(c) const char * c::uiv_PopInternalName([[maybe_unused]] unsigned index)
#define LXxD_UIValueHints1_PopFlags LxResult uiv_PopFlags([[maybe_unused]] unsigned index, [[maybe_unused]] int *flags) override
#define LXxO_UIValueHints1_PopFlags LXxD_UIValueHints1_PopFlags
#define LXxC_UIValueHints1_PopFlags(c) LxResult c::uiv_PopFlags([[maybe_unused]] unsigned index, [[maybe_unused]] int *flags)
#define LXxD_UIValueHints1_PopCategory LxResult uiv_PopCategory([[maybe_unused]] const char **category) override
#define LXxO_UIValueHints1_PopCategory LXxD_UIValueHints1_PopCategory
#define LXxC_UIValueHints1_PopCategory(c) LxResult c::uiv_PopCategory([[maybe_unused]] const char **category)
#define LXxD_UIValueHints1_ItemTest LxResult uiv_ItemTest([[maybe_unused]] ILxUnknownID item) override
#define LXxO_UIValueHints1_ItemTest LXxD_UIValueHints1_ItemTest
#define LXxC_UIValueHints1_ItemTest(c) LxResult c::uiv_ItemTest([[maybe_unused]] ILxUnknownID item)
#define LXxD_UIValueHints1_ColorPickerCommands LxResult uiv_ColorPickerCommands([[maybe_unused]] char *rgb, [[maybe_unused]] char *alpha, [[maybe_unused]] char *rgbAlt, [[maybe_unused]] char *alphaAlt, [[maybe_unused]] char *useAlt, [[maybe_unused]] unsigned bufLens) override
#define LXxO_UIValueHints1_ColorPickerCommands LXxD_UIValueHints1_ColorPickerCommands
#define LXxC_UIValueHints1_ColorPickerCommands(c) LxResult c::uiv_ColorPickerCommands([[maybe_unused]] char *rgb, [[maybe_unused]] char *alpha, [[maybe_unused]] char *rgbAlt, [[maybe_unused]] char *alphaAlt, [[maybe_unused]] char *useAlt, [[maybe_unused]] unsigned bufLens)
#define LXxD_UIValueHints1_NotifierCount LxResult uiv_NotifierCount([[maybe_unused]] int *count) override
#define LXxO_UIValueHints1_NotifierCount LXxD_UIValueHints1_NotifierCount
#define LXxC_UIValueHints1_NotifierCount(c) LxResult c::uiv_NotifierCount([[maybe_unused]] int *count)
#define LXxD_UIValueHints1_NotifierByIndex LxResult uiv_NotifierByIndex([[maybe_unused]] const char **name, [[maybe_unused]] const char **args) override
#define LXxO_UIValueHints1_NotifierByIndex LXxD_UIValueHints1_NotifierByIndex
#define LXxC_UIValueHints1_NotifierByIndex(c) LxResult c::uiv_NotifierByIndex([[maybe_unused]] const char **name, [[maybe_unused]] const char **args)
#define LXxD_UIValueHints1_FormCommandListCount LxResult uiv_FormCommandListCount([[maybe_unused]] int *count) override
#define LXxO_UIValueHints1_FormCommandListCount LXxD_UIValueHints1_FormCommandListCount
#define LXxC_UIValueHints1_FormCommandListCount(c) LxResult c::uiv_FormCommandListCount([[maybe_unused]] int *count)
#define LXxD_UIValueHints1_FormCommandListByIndex LxResult uiv_FormCommandListByIndex([[maybe_unused]] int index, [[maybe_unused]] const char **command) override
#define LXxO_UIValueHints1_FormCommandListByIndex LXxD_UIValueHints1_FormCommandListByIndex
#define LXxC_UIValueHints1_FormCommandListByIndex(c) LxResult c::uiv_FormCommandListByIndex([[maybe_unused]] int index, [[maybe_unused]] const char **command)

template <class T>
class CLxIfc_UIValueHints1: public CLxInterface
{
public:
    CLxIfc_UIValueHints1()
    {
        vt.Flags = Flags;
        vt.PopCount = PopCount;
        vt.PopUserName = PopUserName;
        vt.PopInternalName = PopInternalName;
        vt.PopFlags = PopFlags;
        vt.PopCategory = PopCategory;
        vt.ItemTest = ItemTest;
        vt.ColorPickerCommands = ColorPickerCommands;
        vt.NotifierCount = NotifierCount;
        vt.NotifierByIndex = NotifierByIndex;
        vt.FormCommandListCount = FormCommandListCount;
        vt.FormCommandListByIndex = FormCommandListByIndex;
        vTable = &vt.iunk;
        iid = &lx::guid_UIValueHints1;
    }

    static auto Flags(LXtObjectID wcom) -> unsigned
    {
        LXCWxINST (CLxImpl_UIValueHints1, loc);
        return loc->uiv_Flags();
    }

    static auto PopCount(LXtObjectID wcom) -> unsigned
    {
        LXCWxINST (CLxImpl_UIValueHints1, loc);
        return loc->uiv_PopCount();
    }

    static auto PopUserName(LXtObjectID wcom,unsigned index) -> const char *
    {
        LXCWxINST (CLxImpl_UIValueHints1, loc);
        return loc->uiv_PopUserName( index);
    }

    static auto PopInternalName(LXtObjectID wcom,unsigned index) -> const char *
    {
        LXCWxINST (CLxImpl_UIValueHints1, loc);
        return loc->uiv_PopInternalName( index);
    }

    static auto PopFlags(LXtObjectID wcom,unsigned index,int *flags) -> LxResult
    {
        LXCWxINST (CLxImpl_UIValueHints1, loc);
        try
        {
           return loc->uiv_PopFlags( index, flags);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto PopCategory(LXtObjectID wcom,const char **category) -> LxResult
    {
        LXCWxINST (CLxImpl_UIValueHints1, loc);
        try
        {
           return loc->uiv_PopCategory( category);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ItemTest(LXtObjectID wcom,LXtObjectID item) -> LxResult
    {
        LXCWxINST (CLxImpl_UIValueHints1, loc);
        try
        {
           return loc->uiv_ItemTest((ILxUnknownID) item);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ColorPickerCommands(LXtObjectID wcom,char *rgb,char *alpha,char *rgbAlt,char *alphaAlt,char *useAlt,unsigned bufLens) -> LxResult
    {
        LXCWxINST (CLxImpl_UIValueHints1, loc);
        try
        {
           return loc->uiv_ColorPickerCommands( rgb, alpha, rgbAlt, alphaAlt, useAlt, bufLens);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto NotifierCount(LXtObjectID wcom,int *count) -> LxResult
    {
        LXCWxINST (CLxImpl_UIValueHints1, loc);
        try
        {
           return loc->uiv_NotifierCount( count);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto NotifierByIndex(LXtObjectID wcom,const char **name,const char **args) -> LxResult
    {
        LXCWxINST (CLxImpl_UIValueHints1, loc);
        try
        {
           return loc->uiv_NotifierByIndex( name, args);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto FormCommandListCount(LXtObjectID wcom,int *count) -> LxResult
    {
        LXCWxINST (CLxImpl_UIValueHints1, loc);
        try
        {
           return loc->uiv_FormCommandListCount( count);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto FormCommandListByIndex(LXtObjectID wcom,int index,const char **command) -> LxResult
    {
        LXCWxINST (CLxImpl_UIValueHints1, loc);
        try
        {
           return loc->uiv_FormCommandListByIndex( index, command);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxUIValueHints1 vt;
};

class CLxLoc_UIValueHints1 : public CLxLocalize<ILxUIValueHints1ID>
{
public:
    CLxLoc_UIValueHints1()
    {
        _init();
    }

    CLxLoc_UIValueHints1(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_UIValueHints1(CLxLoc_UIValueHints1 const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_UIValueHints1;
    }

    auto Flags(void) -> unsigned
    {
        return m_loc[0]->Flags(m_loc);
    }

    auto PopCount(void) -> unsigned
    {
        return m_loc[0]->PopCount(m_loc);
    }

    auto PopUserName(unsigned index) -> const char *
    {
        return m_loc[0]->PopUserName(m_loc, index);
    }

    auto PopInternalName(unsigned index) -> const char *
    {
        return m_loc[0]->PopInternalName(m_loc, index);
    }

    auto PopFlags(unsigned index, int *flags) -> LxResult
    {
        return m_loc[0]->PopFlags(m_loc, index, flags);
    }

    auto PopCategory(const char **category) -> LxResult
    {
        return m_loc[0]->PopCategory(m_loc, category);
    }

    auto ItemTest(ILxUnknownID item) -> LxResult
    {
        return m_loc[0]->ItemTest(m_loc,(ILxUnknownID) item);
    }

    auto ColorPickerCommands(char *rgb, char *alpha, char *rgbAlt, char *alphaAlt, char *useAlt, unsigned bufLens) -> LxResult
    {
        return m_loc[0]->ColorPickerCommands(m_loc, rgb, alpha, rgbAlt, alphaAlt, useAlt, bufLens);
    }

    auto NotifierCount(int *count) -> LxResult
    {
        return m_loc[0]->NotifierCount(m_loc, count);
    }

    auto NotifierByIndex(const char **name, const char **args) -> LxResult
    {
        return m_loc[0]->NotifierByIndex(m_loc, name, args);
    }

    auto FormCommandListCount(int *count) -> LxResult
    {
        return m_loc[0]->FormCommandListCount(m_loc, count);
    }

    auto FormCommandListByIndex(int index, const char **command) -> LxResult
    {
        return m_loc[0]->FormCommandListByIndex(m_loc, index, command);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_AttributesUI
{
public:
    virtual ~CLxImpl_AttributesUI() = default;

    virtual auto atrui_UIHints([[maybe_unused]] unsigned int index, [[maybe_unused]] ILxUnknownID hints) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto atrui_UIValueHints([[maybe_unused]] unsigned int index, [[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto atrui_DisableMsg([[maybe_unused]] unsigned int index, [[maybe_unused]] ILxUnknownID message) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_AttributesUI_UIHints LxResult atrui_UIHints([[maybe_unused]] unsigned int index, [[maybe_unused]] ILxUnknownID hints) override
#define LXxO_AttributesUI_UIHints LXxD_AttributesUI_UIHints
#define LXxC_AttributesUI_UIHints(c) LxResult c::atrui_UIHints([[maybe_unused]] unsigned int index, [[maybe_unused]] ILxUnknownID hints)
#define LXxD_AttributesUI_UIValueHints LxResult atrui_UIValueHints([[maybe_unused]] unsigned int index, [[maybe_unused]] void **ppvObj) override
#define LXxO_AttributesUI_UIValueHints LXxD_AttributesUI_UIValueHints
#define LXxC_AttributesUI_UIValueHints(c) LxResult c::atrui_UIValueHints([[maybe_unused]] unsigned int index, [[maybe_unused]] void **ppvObj)
#define LXxD_AttributesUI_DisableMsg LxResult atrui_DisableMsg([[maybe_unused]] unsigned int index, [[maybe_unused]] ILxUnknownID message) override
#define LXxO_AttributesUI_DisableMsg LXxD_AttributesUI_DisableMsg
#define LXxC_AttributesUI_DisableMsg(c) LxResult c::atrui_DisableMsg([[maybe_unused]] unsigned int index, [[maybe_unused]] ILxUnknownID message)

template <class T>
class CLxIfc_AttributesUI: public CLxInterface
{
public:
    CLxIfc_AttributesUI()
    {
        vt.UIHints = UIHints;
        vt.UIValueHints = UIValueHints;
        vt.DisableMsg = DisableMsg;
        vTable = &vt.iunk;
        iid = &lx::guid_AttributesUI;
    }

    static auto UIHints(LXtObjectID wcom,unsigned int index,LXtObjectID hints) -> LxResult
    {
        LXCWxINST (CLxImpl_AttributesUI, loc);
        try
        {
           return loc->atrui_UIHints( index,(ILxUnknownID) hints);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto UIValueHints(LXtObjectID wcom,unsigned int index,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_AttributesUI, loc);
        try
        {
           return loc->atrui_UIValueHints( index, ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto DisableMsg(LXtObjectID wcom,unsigned int index,LXtObjectID message) -> LxResult
    {
        LXCWxINST (CLxImpl_AttributesUI, loc);
        try
        {
           return loc->atrui_DisableMsg( index,(ILxUnknownID) message);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxAttributesUI vt;
};

class CLxLoc_AttributesUI : public CLxLocalize<ILxAttributesUIID>
{
public:
    CLxLoc_AttributesUI()
    {
        _init();
    }

    CLxLoc_AttributesUI(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_AttributesUI(CLxLoc_AttributesUI const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_AttributesUI;
    }

    auto UIHints(unsigned int index, ILxUnknownID hints) -> LxResult
    {
        return m_loc[0]->UIHints(m_loc, index,(ILxUnknownID) hints);
    }

    auto UIValueHints(unsigned int index, void **ppvObj) -> LxResult
    {
        return m_loc[0]->UIValueHints(m_loc, index, ppvObj);
    }

    auto UIValueHints(unsigned int index, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->UIValueHints(m_loc, index, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto DisableMsg(unsigned int index, ILxUnknownID message) -> LxResult
    {
        return m_loc[0]->DisableMsg(m_loc, index,(ILxUnknownID) message);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_CommandEvent
{
public:
    virtual ~CLxImpl_CommandEvent() = default;

    virtual auto cevt_Event([[maybe_unused]] unsigned int flags) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_CommandEvent_Event LxResult cevt_Event([[maybe_unused]] unsigned int flags) override
#define LXxO_CommandEvent_Event LXxD_CommandEvent_Event
#define LXxC_CommandEvent_Event(c) LxResult c::cevt_Event([[maybe_unused]] unsigned int flags)

template <class T>
class CLxIfc_CommandEvent: public CLxInterface
{
public:
    CLxIfc_CommandEvent()
    {
        vt.Event = Event;
        vTable = &vt.iunk;
        iid = &lx::guid_CommandEvent;
    }

    static auto Event(LXtObjectID wcom,unsigned int flags) -> LxResult
    {
        LXCWxINST (CLxImpl_CommandEvent, loc);
        try
        {
           return loc->cevt_Event( flags);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxCommandEvent vt;
};

class CLxLoc_CommandEvent : public CLxLocalize<ILxCommandEventID>
{
public:
    CLxLoc_CommandEvent()
    {
        _init();
    }

    CLxLoc_CommandEvent(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_CommandEvent(CLxLoc_CommandEvent const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_CommandEvent;
    }

    auto Event(unsigned int flags) -> LxResult
    {
        return m_loc[0]->Event(m_loc, flags);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_Command1
{
public:
    virtual ~CLxImpl_Command1() = default;

    virtual auto cmd1_Tag([[maybe_unused]] LXtCommandTag *tag) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd1_Name([[maybe_unused]] const char **name) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd1_UserName([[maybe_unused]] const char **userName) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd1_ButtonName([[maybe_unused]] const char **buttonName) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd1_Desc([[maybe_unused]] const char **desc) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd1_Tooltip([[maybe_unused]] const char **tooltip) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd1_Help([[maybe_unused]] const char **help) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd1_Example([[maybe_unused]] const char **example) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd1_Icon([[maybe_unused]] const char **iconNames) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd1_Flags([[maybe_unused]] unsigned int *flags) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd1_PostExecFlags([[maybe_unused]] unsigned int *flags) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd1_PostExecBehaviorFlags([[maybe_unused]] unsigned int *flags) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd1_PostExecHints([[maybe_unused]] unsigned int *hints) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd1_SandboxGUID([[maybe_unused]] const LXtGUID **guid) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd1_Message([[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd1_Enable([[maybe_unused]] ILxUnknownID msg) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd1_ContainedEnable([[maybe_unused]] LXtID4 *types) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual void cmd1_Interact([[maybe_unused]] void)
    {
    }

    virtual void cmd1_PreExecute([[maybe_unused]] void)
    {
    }

    virtual void cmd1_Execute([[maybe_unused]] unsigned int flags)
    {
    }

    virtual auto cmd1_ToggleArg([[maybe_unused]] unsigned int *index, [[maybe_unused]] void **ppvObj, [[maybe_unused]] unsigned int *typeID, [[maybe_unused]] const char **typeName) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd1_ArgFlags([[maybe_unused]] unsigned int index, [[maybe_unused]] unsigned int *flags) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd1_ArgClear([[maybe_unused]] unsigned int index) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd1_ArgResetAll([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd1_ArgSetDatatypes([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd1_ArgUserName([[maybe_unused]] unsigned int index, [[maybe_unused]] const char **userName) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd1_ArgDesc([[maybe_unused]] unsigned int index, [[maybe_unused]] const char **desc) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd1_ArgExample([[maybe_unused]] unsigned int index, [[maybe_unused]] const char **example) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd1_ArgType([[maybe_unused]] unsigned int index, [[maybe_unused]] const char **type) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd1_ArgTypeUserName([[maybe_unused]] unsigned int index, [[maybe_unused]] const char **userName) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd1_ArgTypeDesc([[maybe_unused]] unsigned int index, [[maybe_unused]] const char **desc) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd1_ArgOptionUserName([[maybe_unused]] unsigned int index, [[maybe_unused]] unsigned int optIndex, [[maybe_unused]] const char **userName) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd1_ArgOptionDesc([[maybe_unused]] unsigned int index, [[maybe_unused]] unsigned int optIndex, [[maybe_unused]] const char **desc) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd1_DialogInit([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd1_DialogArgChange([[maybe_unused]] unsigned int arg) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd1_ArgEnable([[maybe_unused]] unsigned int arg) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd1_ArgParseString([[maybe_unused]] unsigned int argIndex, [[maybe_unused]] const char *argString) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd1_Copy([[maybe_unused]] ILxUnknownID sourceCommand) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd1_Query([[maybe_unused]] unsigned int index, [[maybe_unused]] ILxUnknownID vaQuery) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd1_NotifyAddClient([[maybe_unused]] int argument, [[maybe_unused]] ILxUnknownID object) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd1_NotifyRemoveClient([[maybe_unused]] ILxUnknownID object) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_Command1_Tag LxResult cmd1_Tag([[maybe_unused]] LXtCommandTag *tag) override
#define LXxO_Command1_Tag LXxD_Command1_Tag
#define LXxC_Command1_Tag(c) LxResult c::cmd1_Tag([[maybe_unused]] LXtCommandTag *tag)
#define LXxD_Command1_Name LxResult cmd1_Name([[maybe_unused]] const char **name) override
#define LXxO_Command1_Name LXxD_Command1_Name
#define LXxC_Command1_Name(c) LxResult c::cmd1_Name([[maybe_unused]] const char **name)
#define LXxD_Command1_UserName LxResult cmd1_UserName([[maybe_unused]] const char **userName) override
#define LXxO_Command1_UserName LXxD_Command1_UserName
#define LXxC_Command1_UserName(c) LxResult c::cmd1_UserName([[maybe_unused]] const char **userName)
#define LXxD_Command1_ButtonName LxResult cmd1_ButtonName([[maybe_unused]] const char **buttonName) override
#define LXxO_Command1_ButtonName LXxD_Command1_ButtonName
#define LXxC_Command1_ButtonName(c) LxResult c::cmd1_ButtonName([[maybe_unused]] const char **buttonName)
#define LXxD_Command1_Desc LxResult cmd1_Desc([[maybe_unused]] const char **desc) override
#define LXxO_Command1_Desc LXxD_Command1_Desc
#define LXxC_Command1_Desc(c) LxResult c::cmd1_Desc([[maybe_unused]] const char **desc)
#define LXxD_Command1_Tooltip LxResult cmd1_Tooltip([[maybe_unused]] const char **tooltip) override
#define LXxO_Command1_Tooltip LXxD_Command1_Tooltip
#define LXxC_Command1_Tooltip(c) LxResult c::cmd1_Tooltip([[maybe_unused]] const char **tooltip)
#define LXxD_Command1_Help LxResult cmd1_Help([[maybe_unused]] const char **help) override
#define LXxO_Command1_Help LXxD_Command1_Help
#define LXxC_Command1_Help(c) LxResult c::cmd1_Help([[maybe_unused]] const char **help)
#define LXxD_Command1_Example LxResult cmd1_Example([[maybe_unused]] const char **example) override
#define LXxO_Command1_Example LXxD_Command1_Example
#define LXxC_Command1_Example(c) LxResult c::cmd1_Example([[maybe_unused]] const char **example)
#define LXxD_Command1_Icon LxResult cmd1_Icon([[maybe_unused]] const char **iconNames) override
#define LXxO_Command1_Icon LXxD_Command1_Icon
#define LXxC_Command1_Icon(c) LxResult c::cmd1_Icon([[maybe_unused]] const char **iconNames)
#define LXxD_Command1_Flags LxResult cmd1_Flags([[maybe_unused]] unsigned int *flags) override
#define LXxO_Command1_Flags LXxD_Command1_Flags
#define LXxC_Command1_Flags(c) LxResult c::cmd1_Flags([[maybe_unused]] unsigned int *flags)
#define LXxD_Command1_PostExecFlags LxResult cmd1_PostExecFlags([[maybe_unused]] unsigned int *flags) override
#define LXxO_Command1_PostExecFlags LXxD_Command1_PostExecFlags
#define LXxC_Command1_PostExecFlags(c) LxResult c::cmd1_PostExecFlags([[maybe_unused]] unsigned int *flags)
#define LXxD_Command1_PostExecBehaviorFlags LxResult cmd1_PostExecBehaviorFlags([[maybe_unused]] unsigned int *flags) override
#define LXxO_Command1_PostExecBehaviorFlags LXxD_Command1_PostExecBehaviorFlags
#define LXxC_Command1_PostExecBehaviorFlags(c) LxResult c::cmd1_PostExecBehaviorFlags([[maybe_unused]] unsigned int *flags)
#define LXxD_Command1_PostExecHints LxResult cmd1_PostExecHints([[maybe_unused]] unsigned int *hints) override
#define LXxO_Command1_PostExecHints LXxD_Command1_PostExecHints
#define LXxC_Command1_PostExecHints(c) LxResult c::cmd1_PostExecHints([[maybe_unused]] unsigned int *hints)
#define LXxD_Command1_SandboxGUID LxResult cmd1_SandboxGUID([[maybe_unused]] const LXtGUID **guid) override
#define LXxO_Command1_SandboxGUID LXxD_Command1_SandboxGUID
#define LXxC_Command1_SandboxGUID(c) LxResult c::cmd1_SandboxGUID([[maybe_unused]] const LXtGUID **guid)
#define LXxD_Command1_Message LxResult cmd1_Message([[maybe_unused]] void **ppvObj) override
#define LXxO_Command1_Message LXxD_Command1_Message
#define LXxC_Command1_Message(c) LxResult c::cmd1_Message([[maybe_unused]] void **ppvObj)
#define LXxD_Command1_Enable LxResult cmd1_Enable([[maybe_unused]] ILxUnknownID msg) override
#define LXxO_Command1_Enable LXxD_Command1_Enable
#define LXxC_Command1_Enable(c) LxResult c::cmd1_Enable([[maybe_unused]] ILxUnknownID msg)
#define LXxD_Command1_ContainedEnable LxResult cmd1_ContainedEnable([[maybe_unused]] LXtID4 *types) override
#define LXxO_Command1_ContainedEnable LXxD_Command1_ContainedEnable
#define LXxC_Command1_ContainedEnable(c) LxResult c::cmd1_ContainedEnable([[maybe_unused]] LXtID4 *types)
#define LXxD_Command1_Interact void cmd1_Interact() override
#define LXxO_Command1_Interact LXxD_Command1_Interact
#define LXxC_Command1_Interact(c) void c::cmd1_Interact()
#define LXxD_Command1_PreExecute void cmd1_PreExecute() override
#define LXxO_Command1_PreExecute LXxD_Command1_PreExecute
#define LXxC_Command1_PreExecute(c) void c::cmd1_PreExecute()
#define LXxD_Command1_Execute void cmd1_Execute([[maybe_unused]] unsigned int flags) override
#define LXxO_Command1_Execute LXxD_Command1_Execute
#define LXxC_Command1_Execute(c) void c::cmd1_Execute([[maybe_unused]] unsigned int flags)
#define LXxD_Command1_ToggleArg LxResult cmd1_ToggleArg([[maybe_unused]] unsigned int *index, [[maybe_unused]] void **ppvObj, [[maybe_unused]] unsigned int *typeID, [[maybe_unused]] const char **typeName) override
#define LXxO_Command1_ToggleArg LXxD_Command1_ToggleArg
#define LXxC_Command1_ToggleArg(c) LxResult c::cmd1_ToggleArg([[maybe_unused]] unsigned int *index, [[maybe_unused]] void **ppvObj, [[maybe_unused]] unsigned int *typeID, [[maybe_unused]] const char **typeName)
#define LXxD_Command1_ArgFlags LxResult cmd1_ArgFlags([[maybe_unused]] unsigned int index, [[maybe_unused]] unsigned int *flags) override
#define LXxO_Command1_ArgFlags LXxD_Command1_ArgFlags
#define LXxC_Command1_ArgFlags(c) LxResult c::cmd1_ArgFlags([[maybe_unused]] unsigned int index, [[maybe_unused]] unsigned int *flags)
#define LXxD_Command1_ArgClear LxResult cmd1_ArgClear([[maybe_unused]] unsigned int index) override
#define LXxO_Command1_ArgClear LXxD_Command1_ArgClear
#define LXxC_Command1_ArgClear(c) LxResult c::cmd1_ArgClear([[maybe_unused]] unsigned int index)
#define LXxD_Command1_ArgResetAll LxResult cmd1_ArgResetAll() override
#define LXxO_Command1_ArgResetAll LXxD_Command1_ArgResetAll
#define LXxC_Command1_ArgResetAll(c) LxResult c::cmd1_ArgResetAll()
#define LXxD_Command1_ArgSetDatatypes LxResult cmd1_ArgSetDatatypes() override
#define LXxO_Command1_ArgSetDatatypes LXxD_Command1_ArgSetDatatypes
#define LXxC_Command1_ArgSetDatatypes(c) LxResult c::cmd1_ArgSetDatatypes()
#define LXxD_Command1_ArgUserName LxResult cmd1_ArgUserName([[maybe_unused]] unsigned int index, [[maybe_unused]] const char **userName) override
#define LXxO_Command1_ArgUserName LXxD_Command1_ArgUserName
#define LXxC_Command1_ArgUserName(c) LxResult c::cmd1_ArgUserName([[maybe_unused]] unsigned int index, [[maybe_unused]] const char **userName)
#define LXxD_Command1_ArgDesc LxResult cmd1_ArgDesc([[maybe_unused]] unsigned int index, [[maybe_unused]] const char **desc) override
#define LXxO_Command1_ArgDesc LXxD_Command1_ArgDesc
#define LXxC_Command1_ArgDesc(c) LxResult c::cmd1_ArgDesc([[maybe_unused]] unsigned int index, [[maybe_unused]] const char **desc)
#define LXxD_Command1_ArgExample LxResult cmd1_ArgExample([[maybe_unused]] unsigned int index, [[maybe_unused]] const char **example) override
#define LXxO_Command1_ArgExample LXxD_Command1_ArgExample
#define LXxC_Command1_ArgExample(c) LxResult c::cmd1_ArgExample([[maybe_unused]] unsigned int index, [[maybe_unused]] const char **example)
#define LXxD_Command1_ArgType LxResult cmd1_ArgType([[maybe_unused]] unsigned int index, [[maybe_unused]] const char **type) override
#define LXxO_Command1_ArgType LXxD_Command1_ArgType
#define LXxC_Command1_ArgType(c) LxResult c::cmd1_ArgType([[maybe_unused]] unsigned int index, [[maybe_unused]] const char **type)
#define LXxD_Command1_ArgTypeUserName LxResult cmd1_ArgTypeUserName([[maybe_unused]] unsigned int index, [[maybe_unused]] const char **userName) override
#define LXxO_Command1_ArgTypeUserName LXxD_Command1_ArgTypeUserName
#define LXxC_Command1_ArgTypeUserName(c) LxResult c::cmd1_ArgTypeUserName([[maybe_unused]] unsigned int index, [[maybe_unused]] const char **userName)
#define LXxD_Command1_ArgTypeDesc LxResult cmd1_ArgTypeDesc([[maybe_unused]] unsigned int index, [[maybe_unused]] const char **desc) override
#define LXxO_Command1_ArgTypeDesc LXxD_Command1_ArgTypeDesc
#define LXxC_Command1_ArgTypeDesc(c) LxResult c::cmd1_ArgTypeDesc([[maybe_unused]] unsigned int index, [[maybe_unused]] const char **desc)
#define LXxD_Command1_ArgOptionUserName LxResult cmd1_ArgOptionUserName([[maybe_unused]] unsigned int index, [[maybe_unused]] unsigned int optIndex, [[maybe_unused]] const char **userName) override
#define LXxO_Command1_ArgOptionUserName LXxD_Command1_ArgOptionUserName
#define LXxC_Command1_ArgOptionUserName(c) LxResult c::cmd1_ArgOptionUserName([[maybe_unused]] unsigned int index, [[maybe_unused]] unsigned int optIndex, [[maybe_unused]] const char **userName)
#define LXxD_Command1_ArgOptionDesc LxResult cmd1_ArgOptionDesc([[maybe_unused]] unsigned int index, [[maybe_unused]] unsigned int optIndex, [[maybe_unused]] const char **desc) override
#define LXxO_Command1_ArgOptionDesc LXxD_Command1_ArgOptionDesc
#define LXxC_Command1_ArgOptionDesc(c) LxResult c::cmd1_ArgOptionDesc([[maybe_unused]] unsigned int index, [[maybe_unused]] unsigned int optIndex, [[maybe_unused]] const char **desc)
#define LXxD_Command1_DialogInit LxResult cmd1_DialogInit() override
#define LXxO_Command1_DialogInit LXxD_Command1_DialogInit
#define LXxC_Command1_DialogInit(c) LxResult c::cmd1_DialogInit()
#define LXxD_Command1_DialogArgChange LxResult cmd1_DialogArgChange([[maybe_unused]] unsigned int arg) override
#define LXxO_Command1_DialogArgChange LXxD_Command1_DialogArgChange
#define LXxC_Command1_DialogArgChange(c) LxResult c::cmd1_DialogArgChange([[maybe_unused]] unsigned int arg)
#define LXxD_Command1_ArgEnable LxResult cmd1_ArgEnable([[maybe_unused]] unsigned int arg) override
#define LXxO_Command1_ArgEnable LXxD_Command1_ArgEnable
#define LXxC_Command1_ArgEnable(c) LxResult c::cmd1_ArgEnable([[maybe_unused]] unsigned int arg)
#define LXxD_Command1_ArgParseString LxResult cmd1_ArgParseString([[maybe_unused]] unsigned int argIndex, [[maybe_unused]] const char *argString) override
#define LXxO_Command1_ArgParseString LXxD_Command1_ArgParseString
#define LXxC_Command1_ArgParseString(c) LxResult c::cmd1_ArgParseString([[maybe_unused]] unsigned int argIndex, [[maybe_unused]] const char *argString)
#define LXxD_Command1_Copy LxResult cmd1_Copy([[maybe_unused]] ILxUnknownID sourceCommand) override
#define LXxO_Command1_Copy LXxD_Command1_Copy
#define LXxC_Command1_Copy(c) LxResult c::cmd1_Copy([[maybe_unused]] ILxUnknownID sourceCommand)
#define LXxD_Command1_Query LxResult cmd1_Query([[maybe_unused]] unsigned int index, [[maybe_unused]] ILxUnknownID vaQuery) override
#define LXxO_Command1_Query LXxD_Command1_Query
#define LXxC_Command1_Query(c) LxResult c::cmd1_Query([[maybe_unused]] unsigned int index, [[maybe_unused]] ILxUnknownID vaQuery)
#define LXxD_Command1_NotifyAddClient LxResult cmd1_NotifyAddClient([[maybe_unused]] int argument, [[maybe_unused]] ILxUnknownID object) override
#define LXxO_Command1_NotifyAddClient LXxD_Command1_NotifyAddClient
#define LXxC_Command1_NotifyAddClient(c) LxResult c::cmd1_NotifyAddClient([[maybe_unused]] int argument, [[maybe_unused]] ILxUnknownID object)
#define LXxD_Command1_NotifyRemoveClient LxResult cmd1_NotifyRemoveClient([[maybe_unused]] ILxUnknownID object) override
#define LXxO_Command1_NotifyRemoveClient LXxD_Command1_NotifyRemoveClient
#define LXxC_Command1_NotifyRemoveClient(c) LxResult c::cmd1_NotifyRemoveClient([[maybe_unused]] ILxUnknownID object)

template <class T>
class CLxIfc_Command1: public CLxInterface
{
public:
    CLxIfc_Command1()
    {
        vt.Tag = Tag;
        vt.Name = Name;
        vt.UserName = UserName;
        vt.ButtonName = ButtonName;
        vt.Desc = Desc;
        vt.Tooltip = Tooltip;
        vt.Help = Help;
        vt.Example = Example;
        vt.Icon = Icon;
        vt.Flags = Flags;
        vt.PostExecFlags = PostExecFlags;
        vt.PostExecBehaviorFlags = PostExecBehaviorFlags;
        vt.PostExecHints = PostExecHints;
        vt.SandboxGUID = SandboxGUID;
        vt.Message = Message;
        vt.Enable = Enable;
        vt.ContainedEnable = ContainedEnable;
        vt.Interact = Interact;
        vt.PreExecute = PreExecute;
        vt.Execute = Execute;
        vt.ToggleArg = ToggleArg;
        vt.ArgFlags = ArgFlags;
        vt.ArgClear = ArgClear;
        vt.ArgResetAll = ArgResetAll;
        vt.ArgSetDatatypes = ArgSetDatatypes;
        vt.ArgUserName = ArgUserName;
        vt.ArgDesc = ArgDesc;
        vt.ArgExample = ArgExample;
        vt.ArgType = ArgType;
        vt.ArgTypeUserName = ArgTypeUserName;
        vt.ArgTypeDesc = ArgTypeDesc;
        vt.ArgOptionUserName = ArgOptionUserName;
        vt.ArgOptionDesc = ArgOptionDesc;
        vt.DialogInit = DialogInit;
        vt.DialogArgChange = DialogArgChange;
        vt.ArgEnable = ArgEnable;
        vt.ArgParseString = ArgParseString;
        vt.Copy = Copy;
        vt.Query = Query;
        vt.NotifyAddClient = NotifyAddClient;
        vt.NotifyRemoveClient = NotifyRemoveClient;
        vTable = &vt.iunk;
        iid = &lx::guid_Command1;
    }

    static auto Tag(LXtObjectID wcom,LXtCommandTag *tag) -> LxResult
    {
        LXCWxINST (CLxImpl_Command1, loc);
        try
        {
           return loc->cmd1_Tag( tag);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Name(LXtObjectID wcom,const char **name) -> LxResult
    {
        LXCWxINST (CLxImpl_Command1, loc);
        try
        {
           return loc->cmd1_Name( name);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto UserName(LXtObjectID wcom,const char **userName) -> LxResult
    {
        LXCWxINST (CLxImpl_Command1, loc);
        try
        {
           return loc->cmd1_UserName( userName);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ButtonName(LXtObjectID wcom,const char **buttonName) -> LxResult
    {
        LXCWxINST (CLxImpl_Command1, loc);
        try
        {
           return loc->cmd1_ButtonName( buttonName);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Desc(LXtObjectID wcom,const char **desc) -> LxResult
    {
        LXCWxINST (CLxImpl_Command1, loc);
        try
        {
           return loc->cmd1_Desc( desc);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Tooltip(LXtObjectID wcom,const char **tooltip) -> LxResult
    {
        LXCWxINST (CLxImpl_Command1, loc);
        try
        {
           return loc->cmd1_Tooltip( tooltip);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Help(LXtObjectID wcom,const char **help) -> LxResult
    {
        LXCWxINST (CLxImpl_Command1, loc);
        try
        {
           return loc->cmd1_Help( help);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Example(LXtObjectID wcom,const char **example) -> LxResult
    {
        LXCWxINST (CLxImpl_Command1, loc);
        try
        {
           return loc->cmd1_Example( example);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Icon(LXtObjectID wcom,const char **iconNames) -> LxResult
    {
        LXCWxINST (CLxImpl_Command1, loc);
        try
        {
           return loc->cmd1_Icon( iconNames);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Flags(LXtObjectID wcom,unsigned int *flags) -> LxResult
    {
        LXCWxINST (CLxImpl_Command1, loc);
        try
        {
           return loc->cmd1_Flags( flags);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto PostExecFlags(LXtObjectID wcom,unsigned int *flags) -> LxResult
    {
        LXCWxINST (CLxImpl_Command1, loc);
        try
        {
           return loc->cmd1_PostExecFlags( flags);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto PostExecBehaviorFlags(LXtObjectID wcom,unsigned int *flags) -> LxResult
    {
        LXCWxINST (CLxImpl_Command1, loc);
        try
        {
           return loc->cmd1_PostExecBehaviorFlags( flags);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto PostExecHints(LXtObjectID wcom,unsigned int *hints) -> LxResult
    {
        LXCWxINST (CLxImpl_Command1, loc);
        try
        {
           return loc->cmd1_PostExecHints( hints);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SandboxGUID(LXtObjectID wcom,const LXtGUID **guid) -> LxResult
    {
        LXCWxINST (CLxImpl_Command1, loc);
        try
        {
           return loc->cmd1_SandboxGUID( guid);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Message(LXtObjectID wcom,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_Command1, loc);
        try
        {
           return loc->cmd1_Message( ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Enable(LXtObjectID wcom,LXtObjectID msg) -> LxResult
    {
        LXCWxINST (CLxImpl_Command1, loc);
        try
        {
           return loc->cmd1_Enable((ILxUnknownID) msg);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ContainedEnable(LXtObjectID wcom,LXtID4 *types) -> LxResult
    {
        LXCWxINST (CLxImpl_Command1, loc);
        try
        {
           return loc->cmd1_ContainedEnable( types);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Interact(LXtObjectID wcom) -> void
    {
        LXCWxINST (CLxImpl_Command1, loc);
        loc->cmd1_Interact();
    }

    static auto PreExecute(LXtObjectID wcom) -> void
    {
        LXCWxINST (CLxImpl_Command1, loc);
        loc->cmd1_PreExecute();
    }

    static auto Execute(LXtObjectID wcom,unsigned int flags) -> void
    {
        LXCWxINST (CLxImpl_Command1, loc);
        loc->cmd1_Execute( flags);
    }

    static auto ToggleArg(LXtObjectID wcom,unsigned int *index,void **ppvObj,unsigned int *typeID,const char **typeName) -> LxResult
    {
        LXCWxINST (CLxImpl_Command1, loc);
        try
        {
           return loc->cmd1_ToggleArg( index, ppvObj, typeID, typeName);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ArgFlags(LXtObjectID wcom,unsigned int index,unsigned int *flags) -> LxResult
    {
        LXCWxINST (CLxImpl_Command1, loc);
        try
        {
           return loc->cmd1_ArgFlags( index, flags);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ArgClear(LXtObjectID wcom,unsigned int index) -> LxResult
    {
        LXCWxINST (CLxImpl_Command1, loc);
        try
        {
           return loc->cmd1_ArgClear( index);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ArgResetAll(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_Command1, loc);
        try
        {
           return loc->cmd1_ArgResetAll();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ArgSetDatatypes(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_Command1, loc);
        try
        {
           return loc->cmd1_ArgSetDatatypes();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ArgUserName(LXtObjectID wcom,unsigned int index,const char **userName) -> LxResult
    {
        LXCWxINST (CLxImpl_Command1, loc);
        try
        {
           return loc->cmd1_ArgUserName( index, userName);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ArgDesc(LXtObjectID wcom,unsigned int index,const char **desc) -> LxResult
    {
        LXCWxINST (CLxImpl_Command1, loc);
        try
        {
           return loc->cmd1_ArgDesc( index, desc);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ArgExample(LXtObjectID wcom,unsigned int index,const char **example) -> LxResult
    {
        LXCWxINST (CLxImpl_Command1, loc);
        try
        {
           return loc->cmd1_ArgExample( index, example);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ArgType(LXtObjectID wcom,unsigned int index,const char **type) -> LxResult
    {
        LXCWxINST (CLxImpl_Command1, loc);
        try
        {
           return loc->cmd1_ArgType( index, type);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ArgTypeUserName(LXtObjectID wcom,unsigned int index,const char **userName) -> LxResult
    {
        LXCWxINST (CLxImpl_Command1, loc);
        try
        {
           return loc->cmd1_ArgTypeUserName( index, userName);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ArgTypeDesc(LXtObjectID wcom,unsigned int index,const char **desc) -> LxResult
    {
        LXCWxINST (CLxImpl_Command1, loc);
        try
        {
           return loc->cmd1_ArgTypeDesc( index, desc);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ArgOptionUserName(LXtObjectID wcom,unsigned int index,unsigned int optIndex,const char **userName) -> LxResult
    {
        LXCWxINST (CLxImpl_Command1, loc);
        try
        {
           return loc->cmd1_ArgOptionUserName( index, optIndex, userName);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ArgOptionDesc(LXtObjectID wcom,unsigned int index,unsigned int optIndex,const char **desc) -> LxResult
    {
        LXCWxINST (CLxImpl_Command1, loc);
        try
        {
           return loc->cmd1_ArgOptionDesc( index, optIndex, desc);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto DialogInit(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_Command1, loc);
        try
        {
           return loc->cmd1_DialogInit();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto DialogArgChange(LXtObjectID wcom,unsigned int arg) -> LxResult
    {
        LXCWxINST (CLxImpl_Command1, loc);
        try
        {
           return loc->cmd1_DialogArgChange( arg);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ArgEnable(LXtObjectID wcom,unsigned int arg) -> LxResult
    {
        LXCWxINST (CLxImpl_Command1, loc);
        try
        {
           return loc->cmd1_ArgEnable( arg);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ArgParseString(LXtObjectID wcom,unsigned int argIndex,const char *argString) -> LxResult
    {
        LXCWxINST (CLxImpl_Command1, loc);
        try
        {
           return loc->cmd1_ArgParseString( argIndex, argString);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Copy(LXtObjectID wcom,LXtObjectID sourceCommand) -> LxResult
    {
        LXCWxINST (CLxImpl_Command1, loc);
        try
        {
           return loc->cmd1_Copy((ILxUnknownID) sourceCommand);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Query(LXtObjectID wcom,unsigned int index,LXtObjectID vaQuery) -> LxResult
    {
        LXCWxINST (CLxImpl_Command1, loc);
        try
        {
           return loc->cmd1_Query( index,(ILxUnknownID) vaQuery);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto NotifyAddClient(LXtObjectID wcom,int argument,LXtObjectID object) -> LxResult
    {
        LXCWxINST (CLxImpl_Command1, loc);
        try
        {
           return loc->cmd1_NotifyAddClient( argument,(ILxUnknownID) object);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto NotifyRemoveClient(LXtObjectID wcom,LXtObjectID object) -> LxResult
    {
        LXCWxINST (CLxImpl_Command1, loc);
        try
        {
           return loc->cmd1_NotifyRemoveClient((ILxUnknownID) object);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxCommand1 vt;
};

class CLxLoc_Command1 : public CLxLocalize<ILxCommand1ID>
{
public:
    CLxLoc_Command1()
    {
        _init();
    }

    CLxLoc_Command1(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_Command1(CLxLoc_Command1 const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_Command1;
    }

    auto Tag(LXtCommandTag *tag) -> LxResult
    {
        return m_loc[0]->Tag(m_loc, tag);
    }

    auto Name(const char **name) -> LxResult
    {
        return m_loc[0]->Name(m_loc, name);
    }

    auto UserName(const char **userName) -> LxResult
    {
        return m_loc[0]->UserName(m_loc, userName);
    }

    auto ButtonName(const char **buttonName) -> LxResult
    {
        return m_loc[0]->ButtonName(m_loc, buttonName);
    }

    auto Desc(const char **desc) -> LxResult
    {
        return m_loc[0]->Desc(m_loc, desc);
    }

    auto Tooltip(const char **tooltip) -> LxResult
    {
        return m_loc[0]->Tooltip(m_loc, tooltip);
    }

    auto Help(const char **help) -> LxResult
    {
        return m_loc[0]->Help(m_loc, help);
    }

    auto Example(const char **example) -> LxResult
    {
        return m_loc[0]->Example(m_loc, example);
    }

    auto Icon(const char **iconNames) -> LxResult
    {
        return m_loc[0]->Icon(m_loc, iconNames);
    }

    auto Flags(unsigned int *flags) -> LxResult
    {
        return m_loc[0]->Flags(m_loc, flags);
    }

    auto PostExecFlags(unsigned int *flags) -> LxResult
    {
        return m_loc[0]->PostExecFlags(m_loc, flags);
    }

    auto PostExecBehaviorFlags(unsigned int *flags) -> LxResult
    {
        return m_loc[0]->PostExecBehaviorFlags(m_loc, flags);
    }

    auto PostExecHints(unsigned int *hints) -> LxResult
    {
        return m_loc[0]->PostExecHints(m_loc, hints);
    }

    auto SandboxGUID(const LXtGUID **guid) -> LxResult
    {
        return m_loc[0]->SandboxGUID(m_loc, guid);
    }

    auto Message(void **ppvObj) -> LxResult
    {
        return m_loc[0]->Message(m_loc, ppvObj);
    }

    auto Message(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Message(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Enable(ILxUnknownID msg) -> LxResult
    {
        return m_loc[0]->Enable(m_loc,(ILxUnknownID) msg);
    }

    auto ContainedEnable(LXtID4 *types) -> LxResult
    {
        return m_loc[0]->ContainedEnable(m_loc, types);
    }

    auto Interact(void) -> void
    {
        m_loc[0]->Interact(m_loc);
    }

    auto PreExecute(void) -> void
    {
        m_loc[0]->PreExecute(m_loc);
    }

    auto Execute(unsigned int flags) -> void
    {
        m_loc[0]->Execute(m_loc, flags);
    }

    auto ToggleArg(unsigned int *index, void **ppvObj, unsigned int *typeID, const char **typeName) -> LxResult
    {
        return m_loc[0]->ToggleArg(m_loc, index, ppvObj, typeID, typeName);
    }

    auto ToggleArg(unsigned int *index, CLxLocalizedObject &o_dest, unsigned int *typeID, const char **typeName) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->ToggleArg(m_loc, index, &o_obj, typeID, typeName);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto ArgFlags(unsigned int index, unsigned int *flags) -> LxResult
    {
        return m_loc[0]->ArgFlags(m_loc, index, flags);
    }

    auto ArgClear(unsigned int index) -> LxResult
    {
        return m_loc[0]->ArgClear(m_loc, index);
    }

    auto ArgResetAll(void) -> LxResult
    {
        return m_loc[0]->ArgResetAll(m_loc);
    }

    auto ArgSetDatatypes(void) -> LxResult
    {
        return m_loc[0]->ArgSetDatatypes(m_loc);
    }

    auto ArgUserName(unsigned int index, const char **userName) -> LxResult
    {
        return m_loc[0]->ArgUserName(m_loc, index, userName);
    }

    auto ArgDesc(unsigned int index, const char **desc) -> LxResult
    {
        return m_loc[0]->ArgDesc(m_loc, index, desc);
    }

    auto ArgExample(unsigned int index, const char **example) -> LxResult
    {
        return m_loc[0]->ArgExample(m_loc, index, example);
    }

    auto ArgType(unsigned int index, const char **type) -> LxResult
    {
        return m_loc[0]->ArgType(m_loc, index, type);
    }

    auto ArgTypeUserName(unsigned int index, const char **userName) -> LxResult
    {
        return m_loc[0]->ArgTypeUserName(m_loc, index, userName);
    }

    auto ArgTypeDesc(unsigned int index, const char **desc) -> LxResult
    {
        return m_loc[0]->ArgTypeDesc(m_loc, index, desc);
    }

    auto ArgOptionUserName(unsigned int index, unsigned int optIndex, const char **userName) -> LxResult
    {
        return m_loc[0]->ArgOptionUserName(m_loc, index, optIndex, userName);
    }

    auto ArgOptionDesc(unsigned int index, unsigned int optIndex, const char **desc) -> LxResult
    {
        return m_loc[0]->ArgOptionDesc(m_loc, index, optIndex, desc);
    }

    auto DialogInit(void) -> LxResult
    {
        return m_loc[0]->DialogInit(m_loc);
    }

    auto DialogArgChange(unsigned int arg) -> LxResult
    {
        return m_loc[0]->DialogArgChange(m_loc, arg);
    }

    auto ArgEnable(unsigned int arg) -> LxResult
    {
        return m_loc[0]->ArgEnable(m_loc, arg);
    }

    auto ArgParseString(unsigned int argIndex, const char *argString) -> LxResult
    {
        return m_loc[0]->ArgParseString(m_loc, argIndex, argString);
    }

    auto Copy(ILxUnknownID sourceCommand) -> LxResult
    {
        return m_loc[0]->Copy(m_loc,(ILxUnknownID) sourceCommand);
    }

    auto Query(unsigned int index, ILxUnknownID vaQuery) -> LxResult
    {
        return m_loc[0]->Query(m_loc, index,(ILxUnknownID) vaQuery);
    }

    auto NotifyAddClient(int argument, ILxUnknownID object) -> LxResult
    {
        return m_loc[0]->NotifyAddClient(m_loc, argument,(ILxUnknownID) object);
    }

    auto NotifyRemoveClient(ILxUnknownID object) -> LxResult
    {
        return m_loc[0]->NotifyRemoveClient(m_loc,(ILxUnknownID) object);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_Command2
{
public:
    virtual ~CLxImpl_Command2() = default;

    virtual auto cmd2_Tag([[maybe_unused]] LXtCommandTag *tag) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd2_Name([[maybe_unused]] const char **name) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd2_UserName([[maybe_unused]] const char **userName) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd2_ButtonName([[maybe_unused]] const char **buttonName) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd2_Desc([[maybe_unused]] const char **desc) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd2_Tooltip([[maybe_unused]] const char **tooltip) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd2_Help([[maybe_unused]] const char **help) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd2_Example([[maybe_unused]] const char **example) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd2_Icon([[maybe_unused]] const char **iconNames) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd2_Flags([[maybe_unused]] unsigned int *flags) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd2_PostExecFlags([[maybe_unused]] unsigned int *flags) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd2_PostExecBehaviorFlags([[maybe_unused]] unsigned int *flags) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd2_PostExecHints([[maybe_unused]] unsigned int *hints) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd2_SandboxGUID([[maybe_unused]] const LXtGUID **guid) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd2_Message([[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd2_Enable([[maybe_unused]] ILxUnknownID msg) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd2_ContainedEnable([[maybe_unused]] LXtID4 *types) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual void cmd2_Interact([[maybe_unused]] void)
    {
    }

    virtual void cmd2_PreExecute([[maybe_unused]] void)
    {
    }

    virtual void cmd2_Execute([[maybe_unused]] unsigned int flags)
    {
    }

    virtual auto cmd2_ToggleArg([[maybe_unused]] unsigned int *index, [[maybe_unused]] void **ppvObj, [[maybe_unused]] unsigned int *typeID, [[maybe_unused]] const char **typeName) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd2_ArgFlags([[maybe_unused]] unsigned int index, [[maybe_unused]] unsigned int *flags) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd2_ArgClear([[maybe_unused]] unsigned int index) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd2_ArgResetAll([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd2_ArgSetDatatypes([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd2_ArgUserName([[maybe_unused]] unsigned int index, [[maybe_unused]] const char **userName) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd2_ArgDesc([[maybe_unused]] unsigned int index, [[maybe_unused]] const char **desc) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd2_ArgExample([[maybe_unused]] unsigned int index, [[maybe_unused]] const char **example) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd2_ArgType([[maybe_unused]] unsigned int index, [[maybe_unused]] const char **type) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd2_ArgTypeUserName([[maybe_unused]] unsigned int index, [[maybe_unused]] const char **userName) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd2_ArgTypeDesc([[maybe_unused]] unsigned int index, [[maybe_unused]] const char **desc) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd2_ArgOptionUserName([[maybe_unused]] unsigned int index, [[maybe_unused]] unsigned int optIndex, [[maybe_unused]] const char **userName) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd2_ArgOptionDesc([[maybe_unused]] unsigned int index, [[maybe_unused]] unsigned int optIndex, [[maybe_unused]] const char **desc) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd2_DialogInit([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd2_DialogArgChange([[maybe_unused]] unsigned int arg) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd2_ArgEnable([[maybe_unused]] unsigned int arg) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd2_ArgParseString([[maybe_unused]] unsigned int argIndex, [[maybe_unused]] const char *argString) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd2_Copy([[maybe_unused]] ILxUnknownID sourceCommand) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd2_Query([[maybe_unused]] unsigned int index, [[maybe_unused]] ILxUnknownID vaQuery) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd2_NotifyAddClient([[maybe_unused]] int argument, [[maybe_unused]] ILxUnknownID object) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd2_NotifyRemoveClient([[maybe_unused]] ILxUnknownID object) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto cmd2_DialogFormatting([[maybe_unused]] const char **formatting) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_Command2_Tag LxResult cmd2_Tag([[maybe_unused]] LXtCommandTag *tag) override
#define LXxO_Command2_Tag LXxD_Command2_Tag
#define LXxC_Command2_Tag(c) LxResult c::cmd2_Tag([[maybe_unused]] LXtCommandTag *tag)
#define LXxD_Command2_Name LxResult cmd2_Name([[maybe_unused]] const char **name) override
#define LXxO_Command2_Name LXxD_Command2_Name
#define LXxC_Command2_Name(c) LxResult c::cmd2_Name([[maybe_unused]] const char **name)
#define LXxD_Command2_UserName LxResult cmd2_UserName([[maybe_unused]] const char **userName) override
#define LXxO_Command2_UserName LXxD_Command2_UserName
#define LXxC_Command2_UserName(c) LxResult c::cmd2_UserName([[maybe_unused]] const char **userName)
#define LXxD_Command2_ButtonName LxResult cmd2_ButtonName([[maybe_unused]] const char **buttonName) override
#define LXxO_Command2_ButtonName LXxD_Command2_ButtonName
#define LXxC_Command2_ButtonName(c) LxResult c::cmd2_ButtonName([[maybe_unused]] const char **buttonName)
#define LXxD_Command2_Desc LxResult cmd2_Desc([[maybe_unused]] const char **desc) override
#define LXxO_Command2_Desc LXxD_Command2_Desc
#define LXxC_Command2_Desc(c) LxResult c::cmd2_Desc([[maybe_unused]] const char **desc)
#define LXxD_Command2_Tooltip LxResult cmd2_Tooltip([[maybe_unused]] const char **tooltip) override
#define LXxO_Command2_Tooltip LXxD_Command2_Tooltip
#define LXxC_Command2_Tooltip(c) LxResult c::cmd2_Tooltip([[maybe_unused]] const char **tooltip)
#define LXxD_Command2_Help LxResult cmd2_Help([[maybe_unused]] const char **help) override
#define LXxO_Command2_Help LXxD_Command2_Help
#define LXxC_Command2_Help(c) LxResult c::cmd2_Help([[maybe_unused]] const char **help)
#define LXxD_Command2_Example LxResult cmd2_Example([[maybe_unused]] const char **example) override
#define LXxO_Command2_Example LXxD_Command2_Example
#define LXxC_Command2_Example(c) LxResult c::cmd2_Example([[maybe_unused]] const char **example)
#define LXxD_Command2_Icon LxResult cmd2_Icon([[maybe_unused]] const char **iconNames) override
#define LXxO_Command2_Icon LXxD_Command2_Icon
#define LXxC_Command2_Icon(c) LxResult c::cmd2_Icon([[maybe_unused]] const char **iconNames)
#define LXxD_Command2_Flags LxResult cmd2_Flags([[maybe_unused]] unsigned int *flags) override
#define LXxO_Command2_Flags LXxD_Command2_Flags
#define LXxC_Command2_Flags(c) LxResult c::cmd2_Flags([[maybe_unused]] unsigned int *flags)
#define LXxD_Command2_PostExecFlags LxResult cmd2_PostExecFlags([[maybe_unused]] unsigned int *flags) override
#define LXxO_Command2_PostExecFlags LXxD_Command2_PostExecFlags
#define LXxC_Command2_PostExecFlags(c) LxResult c::cmd2_PostExecFlags([[maybe_unused]] unsigned int *flags)
#define LXxD_Command2_PostExecBehaviorFlags LxResult cmd2_PostExecBehaviorFlags([[maybe_unused]] unsigned int *flags) override
#define LXxO_Command2_PostExecBehaviorFlags LXxD_Command2_PostExecBehaviorFlags
#define LXxC_Command2_PostExecBehaviorFlags(c) LxResult c::cmd2_PostExecBehaviorFlags([[maybe_unused]] unsigned int *flags)
#define LXxD_Command2_PostExecHints LxResult cmd2_PostExecHints([[maybe_unused]] unsigned int *hints) override
#define LXxO_Command2_PostExecHints LXxD_Command2_PostExecHints
#define LXxC_Command2_PostExecHints(c) LxResult c::cmd2_PostExecHints([[maybe_unused]] unsigned int *hints)
#define LXxD_Command2_SandboxGUID LxResult cmd2_SandboxGUID([[maybe_unused]] const LXtGUID **guid) override
#define LXxO_Command2_SandboxGUID LXxD_Command2_SandboxGUID
#define LXxC_Command2_SandboxGUID(c) LxResult c::cmd2_SandboxGUID([[maybe_unused]] const LXtGUID **guid)
#define LXxD_Command2_Message LxResult cmd2_Message([[maybe_unused]] void **ppvObj) override
#define LXxO_Command2_Message LXxD_Command2_Message
#define LXxC_Command2_Message(c) LxResult c::cmd2_Message([[maybe_unused]] void **ppvObj)
#define LXxD_Command2_Enable LxResult cmd2_Enable([[maybe_unused]] ILxUnknownID msg) override
#define LXxO_Command2_Enable LXxD_Command2_Enable
#define LXxC_Command2_Enable(c) LxResult c::cmd2_Enable([[maybe_unused]] ILxUnknownID msg)
#define LXxD_Command2_ContainedEnable LxResult cmd2_ContainedEnable([[maybe_unused]] LXtID4 *types) override
#define LXxO_Command2_ContainedEnable LXxD_Command2_ContainedEnable
#define LXxC_Command2_ContainedEnable(c) LxResult c::cmd2_ContainedEnable([[maybe_unused]] LXtID4 *types)
#define LXxD_Command2_Interact void cmd2_Interact() override
#define LXxO_Command2_Interact LXxD_Command2_Interact
#define LXxC_Command2_Interact(c) void c::cmd2_Interact()
#define LXxD_Command2_PreExecute void cmd2_PreExecute() override
#define LXxO_Command2_PreExecute LXxD_Command2_PreExecute
#define LXxC_Command2_PreExecute(c) void c::cmd2_PreExecute()
#define LXxD_Command2_Execute void cmd2_Execute([[maybe_unused]] unsigned int flags) override
#define LXxO_Command2_Execute LXxD_Command2_Execute
#define LXxC_Command2_Execute(c) void c::cmd2_Execute([[maybe_unused]] unsigned int flags)
#define LXxD_Command2_ToggleArg LxResult cmd2_ToggleArg([[maybe_unused]] unsigned int *index, [[maybe_unused]] void **ppvObj, [[maybe_unused]] unsigned int *typeID, [[maybe_unused]] const char **typeName) override
#define LXxO_Command2_ToggleArg LXxD_Command2_ToggleArg
#define LXxC_Command2_ToggleArg(c) LxResult c::cmd2_ToggleArg([[maybe_unused]] unsigned int *index, [[maybe_unused]] void **ppvObj, [[maybe_unused]] unsigned int *typeID, [[maybe_unused]] const char **typeName)
#define LXxD_Command2_ArgFlags LxResult cmd2_ArgFlags([[maybe_unused]] unsigned int index, [[maybe_unused]] unsigned int *flags) override
#define LXxO_Command2_ArgFlags LXxD_Command2_ArgFlags
#define LXxC_Command2_ArgFlags(c) LxResult c::cmd2_ArgFlags([[maybe_unused]] unsigned int index, [[maybe_unused]] unsigned int *flags)
#define LXxD_Command2_ArgClear LxResult cmd2_ArgClear([[maybe_unused]] unsigned int index) override
#define LXxO_Command2_ArgClear LXxD_Command2_ArgClear
#define LXxC_Command2_ArgClear(c) LxResult c::cmd2_ArgClear([[maybe_unused]] unsigned int index)
#define LXxD_Command2_ArgResetAll LxResult cmd2_ArgResetAll() override
#define LXxO_Command2_ArgResetAll LXxD_Command2_ArgResetAll
#define LXxC_Command2_ArgResetAll(c) LxResult c::cmd2_ArgResetAll()
#define LXxD_Command2_ArgSetDatatypes LxResult cmd2_ArgSetDatatypes() override
#define LXxO_Command2_ArgSetDatatypes LXxD_Command2_ArgSetDatatypes
#define LXxC_Command2_ArgSetDatatypes(c) LxResult c::cmd2_ArgSetDatatypes()
#define LXxD_Command2_ArgUserName LxResult cmd2_ArgUserName([[maybe_unused]] unsigned int index, [[maybe_unused]] const char **userName) override
#define LXxO_Command2_ArgUserName LXxD_Command2_ArgUserName
#define LXxC_Command2_ArgUserName(c) LxResult c::cmd2_ArgUserName([[maybe_unused]] unsigned int index, [[maybe_unused]] const char **userName)
#define LXxD_Command2_ArgDesc LxResult cmd2_ArgDesc([[maybe_unused]] unsigned int index, [[maybe_unused]] const char **desc) override
#define LXxO_Command2_ArgDesc LXxD_Command2_ArgDesc
#define LXxC_Command2_ArgDesc(c) LxResult c::cmd2_ArgDesc([[maybe_unused]] unsigned int index, [[maybe_unused]] const char **desc)
#define LXxD_Command2_ArgExample LxResult cmd2_ArgExample([[maybe_unused]] unsigned int index, [[maybe_unused]] const char **example) override
#define LXxO_Command2_ArgExample LXxD_Command2_ArgExample
#define LXxC_Command2_ArgExample(c) LxResult c::cmd2_ArgExample([[maybe_unused]] unsigned int index, [[maybe_unused]] const char **example)
#define LXxD_Command2_ArgType LxResult cmd2_ArgType([[maybe_unused]] unsigned int index, [[maybe_unused]] const char **type) override
#define LXxO_Command2_ArgType LXxD_Command2_ArgType
#define LXxC_Command2_ArgType(c) LxResult c::cmd2_ArgType([[maybe_unused]] unsigned int index, [[maybe_unused]] const char **type)
#define LXxD_Command2_ArgTypeUserName LxResult cmd2_ArgTypeUserName([[maybe_unused]] unsigned int index, [[maybe_unused]] const char **userName) override
#define LXxO_Command2_ArgTypeUserName LXxD_Command2_ArgTypeUserName
#define LXxC_Command2_ArgTypeUserName(c) LxResult c::cmd2_ArgTypeUserName([[maybe_unused]] unsigned int index, [[maybe_unused]] const char **userName)
#define LXxD_Command2_ArgTypeDesc LxResult cmd2_ArgTypeDesc([[maybe_unused]] unsigned int index, [[maybe_unused]] const char **desc) override
#define LXxO_Command2_ArgTypeDesc LXxD_Command2_ArgTypeDesc
#define LXxC_Command2_ArgTypeDesc(c) LxResult c::cmd2_ArgTypeDesc([[maybe_unused]] unsigned int index, [[maybe_unused]] const char **desc)
#define LXxD_Command2_ArgOptionUserName LxResult cmd2_ArgOptionUserName([[maybe_unused]] unsigned int index, [[maybe_unused]] unsigned int optIndex, [[maybe_unused]] const char **userName) override
#define LXxO_Command2_ArgOptionUserName LXxD_Command2_ArgOptionUserName
#define LXxC_Command2_ArgOptionUserName(c) LxResult c::cmd2_ArgOptionUserName([[maybe_unused]] unsigned int index, [[maybe_unused]] unsigned int optIndex, [[maybe_unused]] const char **userName)
#define LXxD_Command2_ArgOptionDesc LxResult cmd2_ArgOptionDesc([[maybe_unused]] unsigned int index, [[maybe_unused]] unsigned int optIndex, [[maybe_unused]] const char **desc) override
#define LXxO_Command2_ArgOptionDesc LXxD_Command2_ArgOptionDesc
#define LXxC_Command2_ArgOptionDesc(c) LxResult c::cmd2_ArgOptionDesc([[maybe_unused]] unsigned int index, [[maybe_unused]] unsigned int optIndex, [[maybe_unused]] const char **desc)
#define LXxD_Command2_DialogInit LxResult cmd2_DialogInit() override
#define LXxO_Command2_DialogInit LXxD_Command2_DialogInit
#define LXxC_Command2_DialogInit(c) LxResult c::cmd2_DialogInit()
#define LXxD_Command2_DialogArgChange LxResult cmd2_DialogArgChange([[maybe_unused]] unsigned int arg) override
#define LXxO_Command2_DialogArgChange LXxD_Command2_DialogArgChange
#define LXxC_Command2_DialogArgChange(c) LxResult c::cmd2_DialogArgChange([[maybe_unused]] unsigned int arg)
#define LXxD_Command2_ArgEnable LxResult cmd2_ArgEnable([[maybe_unused]] unsigned int arg) override
#define LXxO_Command2_ArgEnable LXxD_Command2_ArgEnable
#define LXxC_Command2_ArgEnable(c) LxResult c::cmd2_ArgEnable([[maybe_unused]] unsigned int arg)
#define LXxD_Command2_ArgParseString LxResult cmd2_ArgParseString([[maybe_unused]] unsigned int argIndex, [[maybe_unused]] const char *argString) override
#define LXxO_Command2_ArgParseString LXxD_Command2_ArgParseString
#define LXxC_Command2_ArgParseString(c) LxResult c::cmd2_ArgParseString([[maybe_unused]] unsigned int argIndex, [[maybe_unused]] const char *argString)
#define LXxD_Command2_Copy LxResult cmd2_Copy([[maybe_unused]] ILxUnknownID sourceCommand) override
#define LXxO_Command2_Copy LXxD_Command2_Copy
#define LXxC_Command2_Copy(c) LxResult c::cmd2_Copy([[maybe_unused]] ILxUnknownID sourceCommand)
#define LXxD_Command2_Query LxResult cmd2_Query([[maybe_unused]] unsigned int index, [[maybe_unused]] ILxUnknownID vaQuery) override
#define LXxO_Command2_Query LXxD_Command2_Query
#define LXxC_Command2_Query(c) LxResult c::cmd2_Query([[maybe_unused]] unsigned int index, [[maybe_unused]] ILxUnknownID vaQuery)
#define LXxD_Command2_NotifyAddClient LxResult cmd2_NotifyAddClient([[maybe_unused]] int argument, [[maybe_unused]] ILxUnknownID object) override
#define LXxO_Command2_NotifyAddClient LXxD_Command2_NotifyAddClient
#define LXxC_Command2_NotifyAddClient(c) LxResult c::cmd2_NotifyAddClient([[maybe_unused]] int argument, [[maybe_unused]] ILxUnknownID object)
#define LXxD_Command2_NotifyRemoveClient LxResult cmd2_NotifyRemoveClient([[maybe_unused]] ILxUnknownID object) override
#define LXxO_Command2_NotifyRemoveClient LXxD_Command2_NotifyRemoveClient
#define LXxC_Command2_NotifyRemoveClient(c) LxResult c::cmd2_NotifyRemoveClient([[maybe_unused]] ILxUnknownID object)
#define LXxD_Command2_DialogFormatting LxResult cmd2_DialogFormatting([[maybe_unused]] const char **formatting) override
#define LXxO_Command2_DialogFormatting LXxD_Command2_DialogFormatting
#define LXxC_Command2_DialogFormatting(c) LxResult c::cmd2_DialogFormatting([[maybe_unused]] const char **formatting)

template <class T>
class CLxIfc_Command2: public CLxInterface
{
public:
    CLxIfc_Command2()
    {
        vt.Tag = Tag;
        vt.Name = Name;
        vt.UserName = UserName;
        vt.ButtonName = ButtonName;
        vt.Desc = Desc;
        vt.Tooltip = Tooltip;
        vt.Help = Help;
        vt.Example = Example;
        vt.Icon = Icon;
        vt.Flags = Flags;
        vt.PostExecFlags = PostExecFlags;
        vt.PostExecBehaviorFlags = PostExecBehaviorFlags;
        vt.PostExecHints = PostExecHints;
        vt.SandboxGUID = SandboxGUID;
        vt.Message = Message;
        vt.Enable = Enable;
        vt.ContainedEnable = ContainedEnable;
        vt.Interact = Interact;
        vt.PreExecute = PreExecute;
        vt.Execute = Execute;
        vt.ToggleArg = ToggleArg;
        vt.ArgFlags = ArgFlags;
        vt.ArgClear = ArgClear;
        vt.ArgResetAll = ArgResetAll;
        vt.ArgSetDatatypes = ArgSetDatatypes;
        vt.ArgUserName = ArgUserName;
        vt.ArgDesc = ArgDesc;
        vt.ArgExample = ArgExample;
        vt.ArgType = ArgType;
        vt.ArgTypeUserName = ArgTypeUserName;
        vt.ArgTypeDesc = ArgTypeDesc;
        vt.ArgOptionUserName = ArgOptionUserName;
        vt.ArgOptionDesc = ArgOptionDesc;
        vt.DialogInit = DialogInit;
        vt.DialogArgChange = DialogArgChange;
        vt.ArgEnable = ArgEnable;
        vt.ArgParseString = ArgParseString;
        vt.Copy = Copy;
        vt.Query = Query;
        vt.NotifyAddClient = NotifyAddClient;
        vt.NotifyRemoveClient = NotifyRemoveClient;
        vt.DialogFormatting = DialogFormatting;
        vTable = &vt.iunk;
        iid = &lx::guid_Command2;
    }

    static auto Tag(LXtObjectID wcom,LXtCommandTag *tag) -> LxResult
    {
        LXCWxINST (CLxImpl_Command2, loc);
        try
        {
           return loc->cmd2_Tag( tag);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Name(LXtObjectID wcom,const char **name) -> LxResult
    {
        LXCWxINST (CLxImpl_Command2, loc);
        try
        {
           return loc->cmd2_Name( name);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto UserName(LXtObjectID wcom,const char **userName) -> LxResult
    {
        LXCWxINST (CLxImpl_Command2, loc);
        try
        {
           return loc->cmd2_UserName( userName);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ButtonName(LXtObjectID wcom,const char **buttonName) -> LxResult
    {
        LXCWxINST (CLxImpl_Command2, loc);
        try
        {
           return loc->cmd2_ButtonName( buttonName);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Desc(LXtObjectID wcom,const char **desc) -> LxResult
    {
        LXCWxINST (CLxImpl_Command2, loc);
        try
        {
           return loc->cmd2_Desc( desc);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Tooltip(LXtObjectID wcom,const char **tooltip) -> LxResult
    {
        LXCWxINST (CLxImpl_Command2, loc);
        try
        {
           return loc->cmd2_Tooltip( tooltip);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Help(LXtObjectID wcom,const char **help) -> LxResult
    {
        LXCWxINST (CLxImpl_Command2, loc);
        try
        {
           return loc->cmd2_Help( help);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Example(LXtObjectID wcom,const char **example) -> LxResult
    {
        LXCWxINST (CLxImpl_Command2, loc);
        try
        {
           return loc->cmd2_Example( example);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Icon(LXtObjectID wcom,const char **iconNames) -> LxResult
    {
        LXCWxINST (CLxImpl_Command2, loc);
        try
        {
           return loc->cmd2_Icon( iconNames);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Flags(LXtObjectID wcom,unsigned int *flags) -> LxResult
    {
        LXCWxINST (CLxImpl_Command2, loc);
        try
        {
           return loc->cmd2_Flags( flags);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto PostExecFlags(LXtObjectID wcom,unsigned int *flags) -> LxResult
    {
        LXCWxINST (CLxImpl_Command2, loc);
        try
        {
           return loc->cmd2_PostExecFlags( flags);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto PostExecBehaviorFlags(LXtObjectID wcom,unsigned int *flags) -> LxResult
    {
        LXCWxINST (CLxImpl_Command2, loc);
        try
        {
           return loc->cmd2_PostExecBehaviorFlags( flags);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto PostExecHints(LXtObjectID wcom,unsigned int *hints) -> LxResult
    {
        LXCWxINST (CLxImpl_Command2, loc);
        try
        {
           return loc->cmd2_PostExecHints( hints);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SandboxGUID(LXtObjectID wcom,const LXtGUID **guid) -> LxResult
    {
        LXCWxINST (CLxImpl_Command2, loc);
        try
        {
           return loc->cmd2_SandboxGUID( guid);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Message(LXtObjectID wcom,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_Command2, loc);
        try
        {
           return loc->cmd2_Message( ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Enable(LXtObjectID wcom,LXtObjectID msg) -> LxResult
    {
        LXCWxINST (CLxImpl_Command2, loc);
        try
        {
           return loc->cmd2_Enable((ILxUnknownID) msg);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ContainedEnable(LXtObjectID wcom,LXtID4 *types) -> LxResult
    {
        LXCWxINST (CLxImpl_Command2, loc);
        try
        {
           return loc->cmd2_ContainedEnable( types);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Interact(LXtObjectID wcom) -> void
    {
        LXCWxINST (CLxImpl_Command2, loc);
        loc->cmd2_Interact();
    }

    static auto PreExecute(LXtObjectID wcom) -> void
    {
        LXCWxINST (CLxImpl_Command2, loc);
        loc->cmd2_PreExecute();
    }

    static auto Execute(LXtObjectID wcom,unsigned int flags) -> void
    {
        LXCWxINST (CLxImpl_Command2, loc);
        loc->cmd2_Execute( flags);
    }

    static auto ToggleArg(LXtObjectID wcom,unsigned int *index,void **ppvObj,unsigned int *typeID,const char **typeName) -> LxResult
    {
        LXCWxINST (CLxImpl_Command2, loc);
        try
        {
           return loc->cmd2_ToggleArg( index, ppvObj, typeID, typeName);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ArgFlags(LXtObjectID wcom,unsigned int index,unsigned int *flags) -> LxResult
    {
        LXCWxINST (CLxImpl_Command2, loc);
        try
        {
           return loc->cmd2_ArgFlags( index, flags);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ArgClear(LXtObjectID wcom,unsigned int index) -> LxResult
    {
        LXCWxINST (CLxImpl_Command2, loc);
        try
        {
           return loc->cmd2_ArgClear( index);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ArgResetAll(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_Command2, loc);
        try
        {
           return loc->cmd2_ArgResetAll();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ArgSetDatatypes(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_Command2, loc);
        try
        {
           return loc->cmd2_ArgSetDatatypes();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ArgUserName(LXtObjectID wcom,unsigned int index,const char **userName) -> LxResult
    {
        LXCWxINST (CLxImpl_Command2, loc);
        try
        {
           return loc->cmd2_ArgUserName( index, userName);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ArgDesc(LXtObjectID wcom,unsigned int index,const char **desc) -> LxResult
    {
        LXCWxINST (CLxImpl_Command2, loc);
        try
        {
           return loc->cmd2_ArgDesc( index, desc);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ArgExample(LXtObjectID wcom,unsigned int index,const char **example) -> LxResult
    {
        LXCWxINST (CLxImpl_Command2, loc);
        try
        {
           return loc->cmd2_ArgExample( index, example);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ArgType(LXtObjectID wcom,unsigned int index,const char **type) -> LxResult
    {
        LXCWxINST (CLxImpl_Command2, loc);
        try
        {
           return loc->cmd2_ArgType( index, type);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ArgTypeUserName(LXtObjectID wcom,unsigned int index,const char **userName) -> LxResult
    {
        LXCWxINST (CLxImpl_Command2, loc);
        try
        {
           return loc->cmd2_ArgTypeUserName( index, userName);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ArgTypeDesc(LXtObjectID wcom,unsigned int index,const char **desc) -> LxResult
    {
        LXCWxINST (CLxImpl_Command2, loc);
        try
        {
           return loc->cmd2_ArgTypeDesc( index, desc);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ArgOptionUserName(LXtObjectID wcom,unsigned int index,unsigned int optIndex,const char **userName) -> LxResult
    {
        LXCWxINST (CLxImpl_Command2, loc);
        try
        {
           return loc->cmd2_ArgOptionUserName( index, optIndex, userName);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ArgOptionDesc(LXtObjectID wcom,unsigned int index,unsigned int optIndex,const char **desc) -> LxResult
    {
        LXCWxINST (CLxImpl_Command2, loc);
        try
        {
           return loc->cmd2_ArgOptionDesc( index, optIndex, desc);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto DialogInit(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_Command2, loc);
        try
        {
           return loc->cmd2_DialogInit();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto DialogArgChange(LXtObjectID wcom,unsigned int arg) -> LxResult
    {
        LXCWxINST (CLxImpl_Command2, loc);
        try
        {
           return loc->cmd2_DialogArgChange( arg);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ArgEnable(LXtObjectID wcom,unsigned int arg) -> LxResult
    {
        LXCWxINST (CLxImpl_Command2, loc);
        try
        {
           return loc->cmd2_ArgEnable( arg);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ArgParseString(LXtObjectID wcom,unsigned int argIndex,const char *argString) -> LxResult
    {
        LXCWxINST (CLxImpl_Command2, loc);
        try
        {
           return loc->cmd2_ArgParseString( argIndex, argString);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Copy(LXtObjectID wcom,LXtObjectID sourceCommand) -> LxResult
    {
        LXCWxINST (CLxImpl_Command2, loc);
        try
        {
           return loc->cmd2_Copy((ILxUnknownID) sourceCommand);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Query(LXtObjectID wcom,unsigned int index,LXtObjectID vaQuery) -> LxResult
    {
        LXCWxINST (CLxImpl_Command2, loc);
        try
        {
           return loc->cmd2_Query( index,(ILxUnknownID) vaQuery);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto NotifyAddClient(LXtObjectID wcom,int argument,LXtObjectID object) -> LxResult
    {
        LXCWxINST (CLxImpl_Command2, loc);
        try
        {
           return loc->cmd2_NotifyAddClient( argument,(ILxUnknownID) object);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto NotifyRemoveClient(LXtObjectID wcom,LXtObjectID object) -> LxResult
    {
        LXCWxINST (CLxImpl_Command2, loc);
        try
        {
           return loc->cmd2_NotifyRemoveClient((ILxUnknownID) object);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto DialogFormatting(LXtObjectID wcom,const char **formatting) -> LxResult
    {
        LXCWxINST (CLxImpl_Command2, loc);
        try
        {
           return loc->cmd2_DialogFormatting( formatting);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxCommand2 vt;
};

class CLxLoc_Command2 : public CLxLocalize<ILxCommand2ID>
{
public:
    CLxLoc_Command2()
    {
        _init();
    }

    CLxLoc_Command2(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_Command2(CLxLoc_Command2 const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_Command2;
    }

    auto Tag(LXtCommandTag *tag) -> LxResult
    {
        return m_loc[0]->Tag(m_loc, tag);
    }

    auto Name(const char **name) -> LxResult
    {
        return m_loc[0]->Name(m_loc, name);
    }

    auto UserName(const char **userName) -> LxResult
    {
        return m_loc[0]->UserName(m_loc, userName);
    }

    auto ButtonName(const char **buttonName) -> LxResult
    {
        return m_loc[0]->ButtonName(m_loc, buttonName);
    }

    auto Desc(const char **desc) -> LxResult
    {
        return m_loc[0]->Desc(m_loc, desc);
    }

    auto Tooltip(const char **tooltip) -> LxResult
    {
        return m_loc[0]->Tooltip(m_loc, tooltip);
    }

    auto Help(const char **help) -> LxResult
    {
        return m_loc[0]->Help(m_loc, help);
    }

    auto Example(const char **example) -> LxResult
    {
        return m_loc[0]->Example(m_loc, example);
    }

    auto Icon(const char **iconNames) -> LxResult
    {
        return m_loc[0]->Icon(m_loc, iconNames);
    }

    auto Flags(unsigned int *flags) -> LxResult
    {
        return m_loc[0]->Flags(m_loc, flags);
    }

    auto PostExecFlags(unsigned int *flags) -> LxResult
    {
        return m_loc[0]->PostExecFlags(m_loc, flags);
    }

    auto PostExecBehaviorFlags(unsigned int *flags) -> LxResult
    {
        return m_loc[0]->PostExecBehaviorFlags(m_loc, flags);
    }

    auto PostExecHints(unsigned int *hints) -> LxResult
    {
        return m_loc[0]->PostExecHints(m_loc, hints);
    }

    auto SandboxGUID(const LXtGUID **guid) -> LxResult
    {
        return m_loc[0]->SandboxGUID(m_loc, guid);
    }

    auto Message(void **ppvObj) -> LxResult
    {
        return m_loc[0]->Message(m_loc, ppvObj);
    }

    auto Message(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Message(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Enable(ILxUnknownID msg) -> LxResult
    {
        return m_loc[0]->Enable(m_loc,(ILxUnknownID) msg);
    }

    auto ContainedEnable(LXtID4 *types) -> LxResult
    {
        return m_loc[0]->ContainedEnable(m_loc, types);
    }

    auto Interact(void) -> void
    {
        m_loc[0]->Interact(m_loc);
    }

    auto PreExecute(void) -> void
    {
        m_loc[0]->PreExecute(m_loc);
    }

    auto Execute(unsigned int flags) -> void
    {
        m_loc[0]->Execute(m_loc, flags);
    }

    auto ToggleArg(unsigned int *index, void **ppvObj, unsigned int *typeID, const char **typeName) -> LxResult
    {
        return m_loc[0]->ToggleArg(m_loc, index, ppvObj, typeID, typeName);
    }

    auto ToggleArg(unsigned int *index, CLxLocalizedObject &o_dest, unsigned int *typeID, const char **typeName) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->ToggleArg(m_loc, index, &o_obj, typeID, typeName);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto ArgFlags(unsigned int index, unsigned int *flags) -> LxResult
    {
        return m_loc[0]->ArgFlags(m_loc, index, flags);
    }

    auto ArgClear(unsigned int index) -> LxResult
    {
        return m_loc[0]->ArgClear(m_loc, index);
    }

    auto ArgResetAll(void) -> LxResult
    {
        return m_loc[0]->ArgResetAll(m_loc);
    }

    auto ArgSetDatatypes(void) -> LxResult
    {
        return m_loc[0]->ArgSetDatatypes(m_loc);
    }

    auto ArgUserName(unsigned int index, const char **userName) -> LxResult
    {
        return m_loc[0]->ArgUserName(m_loc, index, userName);
    }

    auto ArgDesc(unsigned int index, const char **desc) -> LxResult
    {
        return m_loc[0]->ArgDesc(m_loc, index, desc);
    }

    auto ArgExample(unsigned int index, const char **example) -> LxResult
    {
        return m_loc[0]->ArgExample(m_loc, index, example);
    }

    auto ArgType(unsigned int index, const char **type) -> LxResult
    {
        return m_loc[0]->ArgType(m_loc, index, type);
    }

    auto ArgTypeUserName(unsigned int index, const char **userName) -> LxResult
    {
        return m_loc[0]->ArgTypeUserName(m_loc, index, userName);
    }

    auto ArgTypeDesc(unsigned int index, const char **desc) -> LxResult
    {
        return m_loc[0]->ArgTypeDesc(m_loc, index, desc);
    }

    auto ArgOptionUserName(unsigned int index, unsigned int optIndex, const char **userName) -> LxResult
    {
        return m_loc[0]->ArgOptionUserName(m_loc, index, optIndex, userName);
    }

    auto ArgOptionDesc(unsigned int index, unsigned int optIndex, const char **desc) -> LxResult
    {
        return m_loc[0]->ArgOptionDesc(m_loc, index, optIndex, desc);
    }

    auto DialogInit(void) -> LxResult
    {
        return m_loc[0]->DialogInit(m_loc);
    }

    auto DialogArgChange(unsigned int arg) -> LxResult
    {
        return m_loc[0]->DialogArgChange(m_loc, arg);
    }

    auto ArgEnable(unsigned int arg) -> LxResult
    {
        return m_loc[0]->ArgEnable(m_loc, arg);
    }

    auto ArgParseString(unsigned int argIndex, const char *argString) -> LxResult
    {
        return m_loc[0]->ArgParseString(m_loc, argIndex, argString);
    }

    auto Copy(ILxUnknownID sourceCommand) -> LxResult
    {
        return m_loc[0]->Copy(m_loc,(ILxUnknownID) sourceCommand);
    }

    auto Query(unsigned int index, ILxUnknownID vaQuery) -> LxResult
    {
        return m_loc[0]->Query(m_loc, index,(ILxUnknownID) vaQuery);
    }

    auto NotifyAddClient(int argument, ILxUnknownID object) -> LxResult
    {
        return m_loc[0]->NotifyAddClient(m_loc, argument,(ILxUnknownID) object);
    }

    auto NotifyRemoveClient(ILxUnknownID object) -> LxResult
    {
        return m_loc[0]->NotifyRemoveClient(m_loc,(ILxUnknownID) object);
    }

    auto DialogFormatting(const char **formatting) -> LxResult
    {
        return m_loc[0]->DialogFormatting(m_loc, formatting);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};


class CLxLoc_CommandService : public CLxLocalizedService
{
public:
    ILxCommandServiceID m_loc{ nullptr };

public:
    CLxLoc_CommandService()
    {
        _init();
        set();
    }

    ~CLxLoc_CommandService() = default;

    void set()
    {
        if (!m_loc)
        {
            m_loc = reinterpret_cast<ILxCommandServiceID>(lx::GetGlobal(&lx::guid_CommandService));
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

    auto MasterStatus(unsigned int *status) -> LxResult
    {
        return m_loc[0]->MasterStatus(m_loc, status);
    }

    auto GetNameSep(unsigned int *sep) -> LxResult
    {
        return m_loc[0]->GetNameSep(m_loc, sep);
    }

    auto SetNameSep(unsigned int sep) -> LxResult
    {
        return m_loc[0]->SetNameSep(m_loc, sep);
    }

    auto Proto(LXtCommandTag tag, const char *name, void **ppvObj) -> LxResult
    {
        return m_loc[0]->Proto(m_loc, tag, name, ppvObj);
    }

    auto Proto(LXtCommandTag tag, const char *name, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Proto(m_loc, tag, name, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto ProtoFromCommand(ILxUnknownID cmd, void **ppvObj) -> LxResult
    {
        return m_loc[0]->ProtoFromCommand(m_loc,(ILxUnknownID) cmd, ppvObj);
    }

    auto ProtoFromCommand(ILxUnknownID cmd, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->ProtoFromCommand(m_loc,(ILxUnknownID) cmd, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Lookup(const char *name, LXtCommandTag *tag) -> LxResult
    {
        return m_loc[0]->Lookup(m_loc, name, tag);
    }

    auto Spawn(LXtCommandTag tag, const char *name, void **ppvObj) -> LxResult
    {
        return m_loc[0]->Spawn(m_loc, tag, name, ppvObj);
    }

    auto Spawn(LXtCommandTag tag, const char *name, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Spawn(m_loc, tag, name, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto SpawnFromCommand(ILxUnknownID cmd, void **ppvObj) -> LxResult
    {
        return m_loc[0]->SpawnFromCommand(m_loc,(ILxUnknownID) cmd, ppvObj);
    }

    auto SpawnFromCommand(ILxUnknownID cmd, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->SpawnFromCommand(m_loc,(ILxUnknownID) cmd, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto SpawnFromString(const char *args, unsigned int *execFlags, int *queryArgIndex, void **ppvObj) -> LxResult
    {
        return m_loc[0]->SpawnFromString(m_loc, args, execFlags, queryArgIndex, ppvObj);
    }

    auto SpawnFromString(const char *args, unsigned int *execFlags, int *queryArgIndex, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->SpawnFromString(m_loc, args, execFlags, queryArgIndex, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto ExecuteArgString(unsigned int execFlags, LXtCommandTag tag, const char *args) -> LxResult
    {
        return m_loc[0]->ExecuteArgString(m_loc, execFlags, tag, args);
    }

    auto ExecuteToggleArgString(unsigned int execFlags, LXtCommandTag tag, const char *args, int newState) -> LxResult
    {
        return m_loc[0]->ExecuteToggleArgString(m_loc, execFlags, tag, args, newState);
    }

    auto IsToggleArgString(const char *string) -> LxResult
    {
        return m_loc[0]->IsToggleArgString(m_loc, string);
    }

    auto IsBooleanArgString(const char *string) -> LxResult
    {
        return m_loc[0]->IsBooleanArgString(m_loc, string);
    }

    auto ExecuteBooleanArgString(unsigned int execFlags, LXtCommandTag tag, const char *args) -> LxResult
    {
        return m_loc[0]->ExecuteBooleanArgString(m_loc, execFlags, tag, args);
    }

    auto ExecuteSpecial(unsigned int execFlags, ILxUnknownID cmd, int specialArgIndex) -> LxResult
    {
        return m_loc[0]->ExecuteSpecial(m_loc, execFlags,(ILxUnknownID) cmd, specialArgIndex);
    }

    auto ExecuteAttribObject(unsigned int execFlags, LXtCommandTag tag, const char *cmdName, ILxUnknownID attribArgs) -> LxResult
    {
        return m_loc[0]->ExecuteAttribObject(m_loc, execFlags, tag, cmdName,(ILxUnknownID) attribArgs);
    }

    auto ProcessStringFlags(unsigned int flags, const char *string, unsigned int *newFlags, const char **afterFlags) -> LxResult
    {
        return m_loc[0]->ProcessStringFlags(m_loc, flags, string, newFlags, afterFlags);
    }

    auto ExecFlagsAsPrefixString(unsigned int flags, char *buf, unsigned int len) -> LxResult
    {
        return m_loc[0]->ExecFlagsAsPrefixString(m_loc, flags, buf, len);
    }

    auto ExecFlagsAsPrefixString(unsigned int flags, std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->ExecFlagsAsPrefixString(m_loc, flags, buf, len);
        LXWx_SBUF2
    }

    auto SetToggleArgState(ILxUnknownID cmd, int state) -> LxResult
    {
        return m_loc[0]->SetToggleArgState(m_loc,(ILxUnknownID) cmd, state);
    }

    auto GetToggleArgState(ILxUnknownID cmd, int *state, void **ppvObj) -> LxResult
    {
        return m_loc[0]->GetToggleArgState(m_loc,(ILxUnknownID) cmd, state, ppvObj);
    }

    auto GetToggleArgState(ILxUnknownID cmd, int *state, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->GetToggleArgState(m_loc,(ILxUnknownID) cmd, state, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto IsImplicitScript(const char *definition) -> LxResult
    {
        return m_loc[0]->IsImplicitScript(m_loc, definition);
    }

    auto SpawnImplicitScript(const char *definition, void **ppvObj) -> LxResult
    {
        return m_loc[0]->SpawnImplicitScript(m_loc, definition, ppvObj);
    }

    auto SpawnImplicitScript(const char *definition, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->SpawnImplicitScript(m_loc, definition, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto ExecuteImplicitScript(const char *definition, unsigned int execFlags) -> LxResult
    {
        return m_loc[0]->ExecuteImplicitScript(m_loc, definition, execFlags);
    }

    auto RefireBegin(void) -> LxResult
    {
        return m_loc[0]->RefireBegin(m_loc);
    }

    auto RefireEnd(void) -> LxResult
    {
        return m_loc[0]->RefireEnd(m_loc);
    }

    auto RefireState(unsigned int *state) -> LxResult
    {
        return m_loc[0]->RefireState(m_loc, state);
    }

    auto RefireCmd(void **ppvObj) -> LxResult
    {
        return m_loc[0]->RefireCmd(m_loc, ppvObj);
    }

    auto RefireCmd(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->RefireCmd(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto RefireBlock(const char **name) -> LxResult
    {
        return m_loc[0]->RefireBlock(m_loc, name);
    }

    auto PostModeBegin(ILxUnknownID cmd, LXtCommandTag tag, const char *name, const char *args, ILxUnknownID postEndObj) -> LxResult
    {
        return m_loc[0]->PostModeBegin(m_loc,(ILxUnknownID) cmd, tag, name, args,(ILxUnknownID) postEndObj);
    }

    auto PostModeEnd(void) -> LxResult
    {
        return m_loc[0]->PostModeEnd(m_loc);
    }

    auto PostModeState(void) -> LxResult
    {
        return m_loc[0]->PostModeState(m_loc);
    }

    auto PostModeRestart(void) -> LxResult
    {
        return m_loc[0]->PostModeRestart(m_loc);
    }

    auto CurrentExecDepth(int *depth) -> LxResult
    {
        return m_loc[0]->CurrentExecDepth(m_loc, depth);
    }

    auto BlockBegin(const char *name, unsigned int flags) -> LxResult
    {
        return m_loc[0]->BlockBegin(m_loc, name, flags);
    }

    auto BlockEnd(void) -> LxResult
    {
        return m_loc[0]->BlockEnd(m_loc);
    }

    auto BlockCurrent(void **block) -> LxResult
    {
        return m_loc[0]->BlockCurrent(m_loc, block);
    }

    auto SandboxFlags(unsigned int *flags) -> LxResult
    {
        return m_loc[0]->SandboxFlags(m_loc, flags);
    }

    auto SandboxAddObject(ILxUnknownID object) -> LxResult
    {
        return m_loc[0]->SandboxAddObject(m_loc,(ILxUnknownID) object);
    }

    auto SandboxObjectCount(unsigned int *count) -> LxResult
    {
        return m_loc[0]->SandboxObjectCount(m_loc, count);
    }

    auto SandboxObjectByIndex(unsigned int index, void **ppvObj) -> LxResult
    {
        return m_loc[0]->SandboxObjectByIndex(m_loc, index, ppvObj);
    }

    auto SandboxObjectByIndex(unsigned int index, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->SandboxObjectByIndex(m_loc, index, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto SandboxObjectLookup(const LXtGUID *guid, void **ppvObj) -> LxResult
    {
        return m_loc[0]->SandboxObjectLookup(m_loc, guid, ppvObj);
    }

    auto SandboxObjectLookup(const LXtGUID *guid, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->SandboxObjectLookup(m_loc, guid, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto SandboxObjectByCommand(ILxUnknownID cmd, void **ppvObj) -> LxResult
    {
        return m_loc[0]->SandboxObjectByCommand(m_loc,(ILxUnknownID) cmd, ppvObj);
    }

    auto SandboxObjectByCommand(ILxUnknownID cmd, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->SandboxObjectByCommand(m_loc,(ILxUnknownID) cmd, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto SandboxBegin(unsigned int flags) -> LxResult
    {
        return m_loc[0]->SandboxBegin(m_loc, flags);
    }

    auto SandboxState(void) -> LxResult
    {
        return m_loc[0]->SandboxState(m_loc);
    }

    auto SandboxEnd(void) -> LxResult
    {
        return m_loc[0]->SandboxEnd(m_loc);
    }

    auto ParseArgString(ILxUnknownID cmd, int alertFlags, const char *args) -> LxResult
    {
        return m_loc[0]->ParseArgString(m_loc,(ILxUnknownID) cmd, alertFlags, args);
    }

    auto ParseAttribObject(ILxUnknownID cmd, unsigned int alertFlags, ILxUnknownID attribArgs) -> LxResult
    {
        return m_loc[0]->ParseAttribObject(m_loc,(ILxUnknownID) cmd, alertFlags,(ILxUnknownID) attribArgs);
    }

    auto Usage(ILxUnknownID cmd, const char **buffer) -> LxResult
    {
        return m_loc[0]->Usage(m_loc,(ILxUnknownID) cmd, buffer);
    }

    auto ArgsAsString(ILxUnknownID cmd, char *buf, unsigned int len, unsigned int includeCmd) -> LxResult
    {
        return m_loc[0]->ArgsAsString(m_loc,(ILxUnknownID) cmd, buf, len, includeCmd);
    }

    auto ArgsAsString(ILxUnknownID cmd, std::string &result, unsigned int includeCmd) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->ArgsAsString(m_loc,(ILxUnknownID) cmd, buf, len, includeCmd);
        LXWx_SBUF2
    }

    auto Query(ILxUnknownID cmd, unsigned int index, void **ppvObj) -> LxResult
    {
        return m_loc[0]->Query(m_loc,(ILxUnknownID) cmd, index, ppvObj);
    }

    auto Query(ILxUnknownID cmd, unsigned int index, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Query(m_loc,(ILxUnknownID) cmd, index, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto QueryArgString(ILxUnknownID cmd, unsigned int alertFlags, const char *args, void **ppvObj, unsigned int *queryIndex, unsigned int includesCmdName) -> LxResult
    {
        return m_loc[0]->QueryArgString(m_loc,(ILxUnknownID) cmd, alertFlags, args, ppvObj, queryIndex, includesCmdName);
    }

    auto QueryArgString(ILxUnknownID cmd, unsigned int alertFlags, const char *args, CLxLocalizedObject &o_dest, unsigned int *queryIndex, unsigned int includesCmdName) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->QueryArgString(m_loc,(ILxUnknownID) cmd, alertFlags, args, &o_obj, queryIndex, includesCmdName);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto CreateQueryObject(const char *typeName, void **ppvObj) -> LxResult
    {
        return m_loc[0]->CreateQueryObject(m_loc, typeName, ppvObj);
    }

    auto CreateQueryObject(const char *typeName, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->CreateQueryObject(m_loc, typeName, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto AliasCreate(const char *name, ILxUnknownID targetCmd, LXtCommandTag targetTag, const char *targetName, const char *args) -> LxResult
    {
        return m_loc[0]->AliasCreate(m_loc, name,(ILxUnknownID) targetCmd, targetTag, targetName, args);
    }

    auto AliasDelete(ILxUnknownID alias, LXtCommandTag tag, const char *name) -> LxResult
    {
        return m_loc[0]->AliasDelete(m_loc,(ILxUnknownID) alias, tag, name);
    }

    auto IsContainer(ILxUnknownID cmd) -> LxResult
    {
        return m_loc[0]->IsContainer(m_loc,(ILxUnknownID) cmd);
    }

    auto IsAliased(ILxUnknownID cmd) -> LxResult
    {
        return m_loc[0]->IsAliased(m_loc,(ILxUnknownID) cmd);
    }

    auto CommandCount(unsigned int *count) -> LxResult
    {
        return m_loc[0]->CommandCount(m_loc, count);
    }

    auto CommandByIndex(unsigned int index, void **ppvObj) -> LxResult
    {
        return m_loc[0]->CommandByIndex(m_loc, index, ppvObj);
    }

    auto CommandByIndex(unsigned int index, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->CommandByIndex(m_loc, index, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto ExecEntryType(int index, int *type) -> LxResult
    {
        return m_loc[0]->ExecEntryType(m_loc, index, type);
    }

    auto ExecEntryUserName(int index, const char **userName) -> LxResult
    {
        return m_loc[0]->ExecEntryUserName(m_loc, index, userName);
    }

    auto ExecEntryName(int index, const char **name) -> LxResult
    {
        return m_loc[0]->ExecEntryName(m_loc, index, name);
    }

    auto ExecEntryAsArgString(int index, char *buf, int len) -> LxResult
    {
        return m_loc[0]->ExecEntryAsArgString(m_loc, index, buf, len);
    }

    auto IsGlobalInteractionOK(void) -> LxResult
    {
        return m_loc[0]->IsGlobalInteractionOK(m_loc);
    }

    auto ArgsAsStringLen(ILxUnknownID cmd, char *buf, unsigned int len, unsigned int includeCmd) -> LxResult
    {
        return m_loc[0]->ArgsAsStringLen(m_loc,(ILxUnknownID) cmd, buf, len, includeCmd);
    }

    auto ArgsAsStringLen(ILxUnknownID cmd, std::string &result, unsigned int includeCmd) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->ArgsAsStringLen(m_loc,(ILxUnknownID) cmd, buf, len, includeCmd);
        LXWx_SBUF2
    }

    auto SpawnUnaliased(LXtCommandTag tag, const char *name, void **ppvObj) -> LxResult
    {
        return m_loc[0]->SpawnUnaliased(m_loc, tag, name, ppvObj);
    }

    auto SpawnUnaliased(LXtCommandTag tag, const char *name, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->SpawnUnaliased(m_loc, tag, name, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto SetIsGlobalInteractionOK(int isOK) -> LxResult
    {
        return m_loc[0]->SetIsGlobalInteractionOK(m_loc, isOK);
    }

    auto ExecuteArgString2(unsigned int execFlags, LXtCommandTag tag, const char *args, void **ppvObj) -> LxResult
    {
        return m_loc[0]->ExecuteArgString2(m_loc, execFlags, tag, args, ppvObj);
    }

    auto ExecuteArgString2(unsigned int execFlags, LXtCommandTag tag, const char *args, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->ExecuteArgString2(m_loc, execFlags, tag, args, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto ExecuteToggleArgString2(unsigned int execFlags, LXtCommandTag tag, const char *args, int newState, void **ppvObj) -> LxResult
    {
        return m_loc[0]->ExecuteToggleArgString2(m_loc, execFlags, tag, args, newState, ppvObj);
    }

    auto ExecuteToggleArgString2(unsigned int execFlags, LXtCommandTag tag, const char *args, int newState, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->ExecuteToggleArgString2(m_loc, execFlags, tag, args, newState, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto ExecuteBooleanArgString2(unsigned int execFlags, LXtCommandTag tag, const char *args, void **ppvObj) -> LxResult
    {
        return m_loc[0]->ExecuteBooleanArgString2(m_loc, execFlags, tag, args, ppvObj);
    }

    auto ExecuteBooleanArgString2(unsigned int execFlags, LXtCommandTag tag, const char *args, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->ExecuteBooleanArgString2(m_loc, execFlags, tag, args, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto ExecuteAttribObject2(unsigned int execFlags, LXtCommandTag tag, const char *cmdName, ILxUnknownID attribArgs, void **ppvObj) -> LxResult
    {
        return m_loc[0]->ExecuteAttribObject2(m_loc, execFlags, tag, cmdName,(ILxUnknownID) attribArgs, ppvObj);
    }

    auto ExecuteAttribObject2(unsigned int execFlags, LXtCommandTag tag, const char *cmdName, ILxUnknownID attribArgs, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->ExecuteAttribObject2(m_loc, execFlags, tag, cmdName,(ILxUnknownID) attribArgs, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto ExecuteImplicitScript2(const char *definition, unsigned int execFlags, void **ppvObj) -> LxResult
    {
        return m_loc[0]->ExecuteImplicitScript2(m_loc, definition, execFlags, ppvObj);
    }

    auto ExecuteImplicitScript2(const char *definition, unsigned int execFlags, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->ExecuteImplicitScript2(m_loc, definition, execFlags, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto AllocateUIHintsFromCommand(ILxUnknownID cmd, int argIndex, void **ppvObj) -> LxResult
    {
        return m_loc[0]->AllocateUIHintsFromCommand(m_loc,(ILxUnknownID) cmd, argIndex, ppvObj);
    }

    auto AllocateUIHintsFromCommand(ILxUnknownID cmd, int argIndex, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->AllocateUIHintsFromCommand(m_loc,(ILxUnknownID) cmd, argIndex, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto DoAtEndOfRootLevelUndoableCommand(ILxUnknownID visitor) -> LxResult
    {
        return m_loc[0]->DoAtEndOfRootLevelUndoableCommand(m_loc,(ILxUnknownID) visitor);
    }

    auto CancelDoAtEndOfRootLevelUndoableCommand(ILxUnknownID visitor) -> LxResult
    {
        return m_loc[0]->CancelDoAtEndOfRootLevelUndoableCommand(m_loc,(ILxUnknownID) visitor);
    }

    auto ArgsAsStringWithOptions(ILxUnknownID cmd, char *buf, unsigned int len, int options) -> LxResult
    {
        return m_loc[0]->ArgsAsStringWithOptions(m_loc,(ILxUnknownID) cmd, buf, len, options);
    }

    auto ArgsAsStringWithOptions(ILxUnknownID cmd, std::string &result, int options) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->ArgsAsStringWithOptions(m_loc,(ILxUnknownID) cmd, buf, len, options);
        LXWx_SBUF2
    }

    auto CurrentExecIsRoot(int ignoreBlocks) -> LxResult
    {
        return m_loc[0]->CurrentExecIsRoot(m_loc, ignoreBlocks);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};

class CLxImpl_CmdSysListener
{
public:
    virtual ~CLxImpl_CmdSysListener() = default;

    virtual void cmdsysevent_SystemReady([[maybe_unused]] void)
    {
    }

    virtual void cmdsysevent_UndoLockout([[maybe_unused]] int isLockedOut)
    {
    }

    virtual void cmdsysevent_CommandAdded([[maybe_unused]] const char *name)
    {
    }

    virtual void cmdsysevent_AliasAdded([[maybe_unused]] const char *name, [[maybe_unused]] int isOverride)
    {
    }

    virtual void cmdsysevent_AliasRemoved([[maybe_unused]] const char *name, [[maybe_unused]] int isOverride)
    {
    }

    virtual void cmdsysevent_ExecutePre([[maybe_unused]] ILxUnknownID cmd, [[maybe_unused]] int type, [[maybe_unused]] int isSandboxed, [[maybe_unused]] int isPostCmd)
    {
    }

    virtual void cmdsysevent_ExecuteResult([[maybe_unused]] ILxUnknownID cmd, [[maybe_unused]] int type, [[maybe_unused]] int isSandboxed, [[maybe_unused]] int isPostCmd, [[maybe_unused]] int wasSuccessful)
    {
    }

    virtual void cmdsysevent_ExecutePost([[maybe_unused]] ILxUnknownID cmd, [[maybe_unused]] int isSandboxed, [[maybe_unused]] int isPostCmd)
    {
    }

    virtual void cmdsysevent_BlockBegin([[maybe_unused]] ILxUnknownID block, [[maybe_unused]] int isSandboxed)
    {
    }

    virtual void cmdsysevent_BlockEnd([[maybe_unused]] ILxUnknownID block, [[maybe_unused]] int isSandboxed, [[maybe_unused]] int wasDiscarded)
    {
    }

    virtual void cmdsysevent_BlockEndedPostMode([[maybe_unused]] const char *name, [[maybe_unused]] int isSandboxed)
    {
    }

    virtual void cmdsysevent_RefireBegin([[maybe_unused]] void)
    {
    }

    virtual void cmdsysevent_RefireEnd([[maybe_unused]] void)
    {
    }

    virtual void cmdsysevent_RefiringNext([[maybe_unused]] void)
    {
    }

    virtual void cmdsysevent_PostModeBegin([[maybe_unused]] void)
    {
    }

    virtual void cmdsysevent_PostModeEnd([[maybe_unused]] void)
    {
    }

    virtual void cmdsysevent_PostModeRestart([[maybe_unused]] void)
    {
    }

    virtual void cmdsysevent_PostModeUndoNext([[maybe_unused]] void)
    {
    }

    virtual void cmdsysevent_UserUndo([[maybe_unused]] void)
    {
    }

    virtual void cmdsysevent_UserRedo([[maybe_unused]] void)
    {
    }
};

#define LXxD_CmdSysListener_SystemReady void cmdsysevent_SystemReady() override
#define LXxO_CmdSysListener_SystemReady LXxD_CmdSysListener_SystemReady
#define LXxC_CmdSysListener_SystemReady(c) void c::cmdsysevent_SystemReady()
#define LXxD_CmdSysListener_UndoLockout void cmdsysevent_UndoLockout([[maybe_unused]] int isLockedOut) override
#define LXxO_CmdSysListener_UndoLockout LXxD_CmdSysListener_UndoLockout
#define LXxC_CmdSysListener_UndoLockout(c) void c::cmdsysevent_UndoLockout([[maybe_unused]] int isLockedOut)
#define LXxD_CmdSysListener_CommandAdded void cmdsysevent_CommandAdded([[maybe_unused]] const char *name) override
#define LXxO_CmdSysListener_CommandAdded LXxD_CmdSysListener_CommandAdded
#define LXxC_CmdSysListener_CommandAdded(c) void c::cmdsysevent_CommandAdded([[maybe_unused]] const char *name)
#define LXxD_CmdSysListener_AliasAdded void cmdsysevent_AliasAdded([[maybe_unused]] const char *name, [[maybe_unused]] int isOverride) override
#define LXxO_CmdSysListener_AliasAdded LXxD_CmdSysListener_AliasAdded
#define LXxC_CmdSysListener_AliasAdded(c) void c::cmdsysevent_AliasAdded([[maybe_unused]] const char *name, [[maybe_unused]] int isOverride)
#define LXxD_CmdSysListener_AliasRemoved void cmdsysevent_AliasRemoved([[maybe_unused]] const char *name, [[maybe_unused]] int isOverride) override
#define LXxO_CmdSysListener_AliasRemoved LXxD_CmdSysListener_AliasRemoved
#define LXxC_CmdSysListener_AliasRemoved(c) void c::cmdsysevent_AliasRemoved([[maybe_unused]] const char *name, [[maybe_unused]] int isOverride)
#define LXxD_CmdSysListener_ExecutePre void cmdsysevent_ExecutePre([[maybe_unused]] ILxUnknownID cmd, [[maybe_unused]] int type, [[maybe_unused]] int isSandboxed, [[maybe_unused]] int isPostCmd) override
#define LXxO_CmdSysListener_ExecutePre LXxD_CmdSysListener_ExecutePre
#define LXxC_CmdSysListener_ExecutePre(c) void c::cmdsysevent_ExecutePre([[maybe_unused]] ILxUnknownID cmd, [[maybe_unused]] int type, [[maybe_unused]] int isSandboxed, [[maybe_unused]] int isPostCmd)
#define LXxD_CmdSysListener_ExecuteResult void cmdsysevent_ExecuteResult([[maybe_unused]] ILxUnknownID cmd, [[maybe_unused]] int type, [[maybe_unused]] int isSandboxed, [[maybe_unused]] int isPostCmd, [[maybe_unused]] int wasSuccessful) override
#define LXxO_CmdSysListener_ExecuteResult LXxD_CmdSysListener_ExecuteResult
#define LXxC_CmdSysListener_ExecuteResult(c) void c::cmdsysevent_ExecuteResult([[maybe_unused]] ILxUnknownID cmd, [[maybe_unused]] int type, [[maybe_unused]] int isSandboxed, [[maybe_unused]] int isPostCmd, [[maybe_unused]] int wasSuccessful)
#define LXxD_CmdSysListener_ExecutePost void cmdsysevent_ExecutePost([[maybe_unused]] ILxUnknownID cmd, [[maybe_unused]] int isSandboxed, [[maybe_unused]] int isPostCmd) override
#define LXxO_CmdSysListener_ExecutePost LXxD_CmdSysListener_ExecutePost
#define LXxC_CmdSysListener_ExecutePost(c) void c::cmdsysevent_ExecutePost([[maybe_unused]] ILxUnknownID cmd, [[maybe_unused]] int isSandboxed, [[maybe_unused]] int isPostCmd)
#define LXxD_CmdSysListener_BlockBegin void cmdsysevent_BlockBegin([[maybe_unused]] ILxUnknownID block, [[maybe_unused]] int isSandboxed) override
#define LXxO_CmdSysListener_BlockBegin LXxD_CmdSysListener_BlockBegin
#define LXxC_CmdSysListener_BlockBegin(c) void c::cmdsysevent_BlockBegin([[maybe_unused]] ILxUnknownID block, [[maybe_unused]] int isSandboxed)
#define LXxD_CmdSysListener_BlockEnd void cmdsysevent_BlockEnd([[maybe_unused]] ILxUnknownID block, [[maybe_unused]] int isSandboxed, [[maybe_unused]] int wasDiscarded) override
#define LXxO_CmdSysListener_BlockEnd LXxD_CmdSysListener_BlockEnd
#define LXxC_CmdSysListener_BlockEnd(c) void c::cmdsysevent_BlockEnd([[maybe_unused]] ILxUnknownID block, [[maybe_unused]] int isSandboxed, [[maybe_unused]] int wasDiscarded)
#define LXxD_CmdSysListener_BlockEndedPostMode void cmdsysevent_BlockEndedPostMode([[maybe_unused]] const char *name, [[maybe_unused]] int isSandboxed) override
#define LXxO_CmdSysListener_BlockEndedPostMode LXxD_CmdSysListener_BlockEndedPostMode
#define LXxC_CmdSysListener_BlockEndedPostMode(c) void c::cmdsysevent_BlockEndedPostMode([[maybe_unused]] const char *name, [[maybe_unused]] int isSandboxed)
#define LXxD_CmdSysListener_RefireBegin void cmdsysevent_RefireBegin() override
#define LXxO_CmdSysListener_RefireBegin LXxD_CmdSysListener_RefireBegin
#define LXxC_CmdSysListener_RefireBegin(c) void c::cmdsysevent_RefireBegin()
#define LXxD_CmdSysListener_RefireEnd void cmdsysevent_RefireEnd() override
#define LXxO_CmdSysListener_RefireEnd LXxD_CmdSysListener_RefireEnd
#define LXxC_CmdSysListener_RefireEnd(c) void c::cmdsysevent_RefireEnd()
#define LXxD_CmdSysListener_RefiringNext void cmdsysevent_RefiringNext() override
#define LXxO_CmdSysListener_RefiringNext LXxD_CmdSysListener_RefiringNext
#define LXxC_CmdSysListener_RefiringNext(c) void c::cmdsysevent_RefiringNext()
#define LXxD_CmdSysListener_PostModeBegin void cmdsysevent_PostModeBegin() override
#define LXxO_CmdSysListener_PostModeBegin LXxD_CmdSysListener_PostModeBegin
#define LXxC_CmdSysListener_PostModeBegin(c) void c::cmdsysevent_PostModeBegin()
#define LXxD_CmdSysListener_PostModeEnd void cmdsysevent_PostModeEnd() override
#define LXxO_CmdSysListener_PostModeEnd LXxD_CmdSysListener_PostModeEnd
#define LXxC_CmdSysListener_PostModeEnd(c) void c::cmdsysevent_PostModeEnd()
#define LXxD_CmdSysListener_PostModeRestart void cmdsysevent_PostModeRestart() override
#define LXxO_CmdSysListener_PostModeRestart LXxD_CmdSysListener_PostModeRestart
#define LXxC_CmdSysListener_PostModeRestart(c) void c::cmdsysevent_PostModeRestart()
#define LXxD_CmdSysListener_PostModeUndoNext void cmdsysevent_PostModeUndoNext() override
#define LXxO_CmdSysListener_PostModeUndoNext LXxD_CmdSysListener_PostModeUndoNext
#define LXxC_CmdSysListener_PostModeUndoNext(c) void c::cmdsysevent_PostModeUndoNext()
#define LXxD_CmdSysListener_UserUndo void cmdsysevent_UserUndo() override
#define LXxO_CmdSysListener_UserUndo LXxD_CmdSysListener_UserUndo
#define LXxC_CmdSysListener_UserUndo(c) void c::cmdsysevent_UserUndo()
#define LXxD_CmdSysListener_UserRedo void cmdsysevent_UserRedo() override
#define LXxO_CmdSysListener_UserRedo LXxD_CmdSysListener_UserRedo
#define LXxC_CmdSysListener_UserRedo(c) void c::cmdsysevent_UserRedo()

template <class T>
class CLxIfc_CmdSysListener: public CLxInterface
{
public:
    CLxIfc_CmdSysListener()
    {
        vt.SystemReady = SystemReady;
        vt.UndoLockout = UndoLockout;
        vt.CommandAdded = CommandAdded;
        vt.AliasAdded = AliasAdded;
        vt.AliasRemoved = AliasRemoved;
        vt.ExecutePre = ExecutePre;
        vt.ExecuteResult = ExecuteResult;
        vt.ExecutePost = ExecutePost;
        vt.BlockBegin = BlockBegin;
        vt.BlockEnd = BlockEnd;
        vt.BlockEndedPostMode = BlockEndedPostMode;
        vt.RefireBegin = RefireBegin;
        vt.RefireEnd = RefireEnd;
        vt.RefiringNext = RefiringNext;
        vt.PostModeBegin = PostModeBegin;
        vt.PostModeEnd = PostModeEnd;
        vt.PostModeRestart = PostModeRestart;
        vt.PostModeUndoNext = PostModeUndoNext;
        vt.UserUndo = UserUndo;
        vt.UserRedo = UserRedo;
        vTable = &vt.iunk;
        iid = &lx::guid_CmdSysListener;
    }

    static auto SystemReady(LXtObjectID wcom) -> void
    {
        LXCWxINST (CLxImpl_CmdSysListener, loc);
        loc->cmdsysevent_SystemReady();
    }

    static auto UndoLockout(LXtObjectID wcom,int isLockedOut) -> void
    {
        LXCWxINST (CLxImpl_CmdSysListener, loc);
        loc->cmdsysevent_UndoLockout( isLockedOut);
    }

    static auto CommandAdded(LXtObjectID wcom,const char *name) -> void
    {
        LXCWxINST (CLxImpl_CmdSysListener, loc);
        loc->cmdsysevent_CommandAdded( name);
    }

    static auto AliasAdded(LXtObjectID wcom,const char *name,int isOverride) -> void
    {
        LXCWxINST (CLxImpl_CmdSysListener, loc);
        loc->cmdsysevent_AliasAdded( name, isOverride);
    }

    static auto AliasRemoved(LXtObjectID wcom,const char *name,int isOverride) -> void
    {
        LXCWxINST (CLxImpl_CmdSysListener, loc);
        loc->cmdsysevent_AliasRemoved( name, isOverride);
    }

    static auto ExecutePre(LXtObjectID wcom,LXtObjectID cmd,int type,int isSandboxed,int isPostCmd) -> void
    {
        LXCWxINST (CLxImpl_CmdSysListener, loc);
        loc->cmdsysevent_ExecutePre((ILxUnknownID) cmd, type, isSandboxed, isPostCmd);
    }

    static auto ExecuteResult(LXtObjectID wcom,LXtObjectID cmd,int type,int isSandboxed,int isPostCmd,int wasSuccessful) -> void
    {
        LXCWxINST (CLxImpl_CmdSysListener, loc);
        loc->cmdsysevent_ExecuteResult((ILxUnknownID) cmd, type, isSandboxed, isPostCmd, wasSuccessful);
    }

    static auto ExecutePost(LXtObjectID wcom,LXtObjectID cmd,int isSandboxed,int isPostCmd) -> void
    {
        LXCWxINST (CLxImpl_CmdSysListener, loc);
        loc->cmdsysevent_ExecutePost((ILxUnknownID) cmd, isSandboxed, isPostCmd);
    }

    static auto BlockBegin(LXtObjectID wcom,LXtObjectID block,int isSandboxed) -> void
    {
        LXCWxINST (CLxImpl_CmdSysListener, loc);
        loc->cmdsysevent_BlockBegin((ILxUnknownID) block, isSandboxed);
    }

    static auto BlockEnd(LXtObjectID wcom,LXtObjectID block,int isSandboxed,int wasDiscarded) -> void
    {
        LXCWxINST (CLxImpl_CmdSysListener, loc);
        loc->cmdsysevent_BlockEnd((ILxUnknownID) block, isSandboxed, wasDiscarded);
    }

    static auto BlockEndedPostMode(LXtObjectID wcom,const char *name,int isSandboxed) -> void
    {
        LXCWxINST (CLxImpl_CmdSysListener, loc);
        loc->cmdsysevent_BlockEndedPostMode( name, isSandboxed);
    }

    static auto RefireBegin(LXtObjectID wcom) -> void
    {
        LXCWxINST (CLxImpl_CmdSysListener, loc);
        loc->cmdsysevent_RefireBegin();
    }

    static auto RefireEnd(LXtObjectID wcom) -> void
    {
        LXCWxINST (CLxImpl_CmdSysListener, loc);
        loc->cmdsysevent_RefireEnd();
    }

    static auto RefiringNext(LXtObjectID wcom) -> void
    {
        LXCWxINST (CLxImpl_CmdSysListener, loc);
        loc->cmdsysevent_RefiringNext();
    }

    static auto PostModeBegin(LXtObjectID wcom) -> void
    {
        LXCWxINST (CLxImpl_CmdSysListener, loc);
        loc->cmdsysevent_PostModeBegin();
    }

    static auto PostModeEnd(LXtObjectID wcom) -> void
    {
        LXCWxINST (CLxImpl_CmdSysListener, loc);
        loc->cmdsysevent_PostModeEnd();
    }

    static auto PostModeRestart(LXtObjectID wcom) -> void
    {
        LXCWxINST (CLxImpl_CmdSysListener, loc);
        loc->cmdsysevent_PostModeRestart();
    }

    static auto PostModeUndoNext(LXtObjectID wcom) -> void
    {
        LXCWxINST (CLxImpl_CmdSysListener, loc);
        loc->cmdsysevent_PostModeUndoNext();
    }

    static auto UserUndo(LXtObjectID wcom) -> void
    {
        LXCWxINST (CLxImpl_CmdSysListener, loc);
        loc->cmdsysevent_UserUndo();
    }

    static auto UserRedo(LXtObjectID wcom) -> void
    {
        LXCWxINST (CLxImpl_CmdSysListener, loc);
        loc->cmdsysevent_UserRedo();
    }

private:
    ILxCmdSysListener vt;
};

class CLxLoc_CmdSysListener : public CLxLocalize<ILxCmdSysListenerID>
{
public:
    CLxLoc_CmdSysListener()
    {
        _init();
    }

    CLxLoc_CmdSysListener(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_CmdSysListener(CLxLoc_CmdSysListener const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_CmdSysListener;
    }

    auto SystemReady(void) -> void
    {
        m_loc[0]->SystemReady(m_loc);
    }

    auto UndoLockout(int isLockedOut) -> void
    {
        m_loc[0]->UndoLockout(m_loc, isLockedOut);
    }

    auto CommandAdded(const char *name) -> void
    {
        m_loc[0]->CommandAdded(m_loc, name);
    }

    auto AliasAdded(const char *name, int isOverride) -> void
    {
        m_loc[0]->AliasAdded(m_loc, name, isOverride);
    }

    auto AliasRemoved(const char *name, int isOverride) -> void
    {
        m_loc[0]->AliasRemoved(m_loc, name, isOverride);
    }

    auto ExecutePre(ILxUnknownID cmd, int type, int isSandboxed, int isPostCmd) -> void
    {
        m_loc[0]->ExecutePre(m_loc,(ILxUnknownID) cmd, type, isSandboxed, isPostCmd);
    }

    auto ExecuteResult(ILxUnknownID cmd, int type, int isSandboxed, int isPostCmd, int wasSuccessful) -> void
    {
        m_loc[0]->ExecuteResult(m_loc,(ILxUnknownID) cmd, type, isSandboxed, isPostCmd, wasSuccessful);
    }

    auto ExecutePost(ILxUnknownID cmd, int isSandboxed, int isPostCmd) -> void
    {
        m_loc[0]->ExecutePost(m_loc,(ILxUnknownID) cmd, isSandboxed, isPostCmd);
    }

    auto BlockBegin(ILxUnknownID block, int isSandboxed) -> void
    {
        m_loc[0]->BlockBegin(m_loc,(ILxUnknownID) block, isSandboxed);
    }

    auto BlockEnd(ILxUnknownID block, int isSandboxed, int wasDiscarded) -> void
    {
        m_loc[0]->BlockEnd(m_loc,(ILxUnknownID) block, isSandboxed, wasDiscarded);
    }

    auto BlockEndedPostMode(const char *name, int isSandboxed) -> void
    {
        m_loc[0]->BlockEndedPostMode(m_loc, name, isSandboxed);
    }

    auto RefireBegin(void) -> void
    {
        m_loc[0]->RefireBegin(m_loc);
    }

    auto RefireEnd(void) -> void
    {
        m_loc[0]->RefireEnd(m_loc);
    }

    auto RefiringNext(void) -> void
    {
        m_loc[0]->RefiringNext(m_loc);
    }

    auto PostModeBegin(void) -> void
    {
        m_loc[0]->PostModeBegin(m_loc);
    }

    auto PostModeEnd(void) -> void
    {
        m_loc[0]->PostModeEnd(m_loc);
    }

    auto PostModeRestart(void) -> void
    {
        m_loc[0]->PostModeRestart(m_loc);
    }

    auto PostModeUndoNext(void) -> void
    {
        m_loc[0]->PostModeUndoNext(m_loc);
    }

    auto UserUndo(void) -> void
    {
        m_loc[0]->UserUndo(m_loc);
    }

    auto UserRedo(void) -> void
    {
        m_loc[0]->UserRedo(m_loc);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
