//
// C++ wrapper for lxsdk/lxvalue.h.
//
//	Copyright 2024.
//
//
#pragma once

#include <lxvalue.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx
{
    static LXtGUID const guid_ValueService = {0xDD2C3059, {0x2CD0, 0x4c7d}, {0x86, 0x0C, 0xCF, 0x35, 0x3C, 0xFB, 0x2F, 0x92}};
    static LXtGUID const guid_Value = {0x83065459, {0xD9EA, 0x11E8}, {0xAE, 0xB4, 0xE2, 0x00, 0xE9, 0x30, 0x97, 0x01}};
    static LXtGUID const guid_Value1 = {0x62E1DBE9, {0x2FFE, 0x4B5C}, {0xB2, 0x86, 0xE5, 0x4E, 0x79, 0x41, 0x53, 0x03}};
    static LXtGUID const guid_StringConversion = {0x5CB3EEDB, {0xE4E0, 0x499E}, {0xB0, 0xBA, 0xA7, 0xFB, 0x51, 0xBA, 0xBE, 0x3C}};
    static LXtGUID const guid_StringConversionNice = {0x5407328B, {0xDE99, 0x4F15}, {0x86, 0x6F, 0xF6, 0xE2, 0x14, 0xFF, 0xA4, 0x12}};
    static LXtGUID const guid_ValueMath = {0x752B4D2E, {0x6F13, 0x4B2C}, {0xB0, 0xB3, 0x0B, 0xA8, 0xCA, 0x6B, 0x06, 0x92}};
    static LXtGUID const guid_ValueReference = {0x0567BC88, {0xF782, 0x426E}, {0x98, 0xC5, 0x83, 0x02, 0xFD, 0x52, 0xD9, 0xE4}};
    static LXtGUID const guid_ValueConversion = {0xAE427D16, {0xAA5E, 0x4135}, {0x87, 0x22, 0x38, 0xD6, 0x9F, 0x48, 0xF9, 0xEC}};
    static LXtGUID const guid_Attributes = {0x117957D0, {0x5A13, 0x11D7}, {0xA1, 0x8C, 0x00, 0x0A, 0x95, 0x76, 0x5C, 0x9E}};
    static LXtGUID const guid_Message = {0xDDDBF46A, {0x0865, 0x4AB7}, {0x99, 0x62, 0x72, 0xE7, 0xB4, 0x77, 0xFD, 0x22}};
    static LXtGUID const guid_ValueArray = {0x6DAC2F05, {0xD95B, 0x11E8}, {0x96, 0x84, 0xE2, 0x00, 0xE9, 0x30, 0x97, 0x01}};
    static LXtGUID const guid_ValueArray1 = {0xA964962F, {0x9028, 0x4CA3}, {0x96, 0x12, 0x17, 0xD3, 0x60, 0xDF, 0x92, 0xBA}};
    static LXtGUID const guid_Array = {0xd1e1ba61, {0x700e, 0x48ad}, {0xaa, 0xda, 0x68, 0x65, 0x14, 0x8f, 0xcc, 0x40}};
    static LXtGUID const guid_ScriptQuery = {0x0434F07E, {0xAD4A, 0x492f}, {0xAD, 0x43, 0x32, 0x49, 0xBD, 0x16, 0x99, 0x4D}};
    static LXtGUID const guid_StringTag = {0xC2004BC7, {0x6A90, 0x4BD3}, {0xBD, 0xF7, 0xB3, 0x75, 0xC7, 0x90, 0xDB, 0x70}};
    static LXtGUID const guid_Matrix = {0xEF9FDE7B, {0xE7FA, 0x48B2}, {0x83, 0x8E, 0xA5, 0xA8, 0xF7, 0xD5, 0xC2, 0x54}};
    static LXtGUID const guid_Quaternion = {0xB8697DEB, {0xDCD0, 0x4C86}, {0xB8, 0x22, 0x70, 0x2D, 0x5E, 0xDE, 0xFA, 0x76}};
    static LXtGUID const guid_Visitor = {0xC8FCAD70, {0xDDDF, 0x499E}, {0xA0, 0x3B, 0xA0, 0x8B, 0x90, 0x6D, 0x3E, 0x53}};
    static LXtGUID const guid_TextEncoding = {0xEE4989E5, {0xF1E5, 0x43D4}, {0x80, 0xCC, 0x16, 0xF5, 0x06, 0xEF, 0xD6, 0x32}};
    static LXtGUID const guid_TextEncodingService = {0x7753B6E4, {0xCF23, 0x491E}, {0x89, 0xC1, 0x2C, 0xA2, 0x6B, 0xE5, 0xC8, 0x9F}};
} // namespace lx

class CLxLoc_ValueService : public CLxLocalizedService
{
public:
    ILxValueServiceID m_loc{ nullptr };

public:
    CLxLoc_ValueService()
    {
        _init();
        set();
    }

    ~CLxLoc_ValueService() = default;

    void set()
    {
        if (!m_loc)
        {
            m_loc = reinterpret_cast<ILxValueServiceID>(lx::GetGlobal(&lx::guid_ValueService));
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

    auto TextHintEncode(int value, const LXtTextValueHint *hint, char *buf, unsigned len) -> LxResult
    {
        return m_loc[0]->TextHintEncode(m_loc, value, hint, buf, len);
    }

    auto TextHintEncode(int value, const LXtTextValueHint *hint, std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->TextHintEncode(m_loc, value, hint, buf, len);
        LXWx_SBUF2
    }

    auto TextHintDecode(const char *buf, const LXtTextValueHint *hint, int *value) -> LxResult
    {
        return m_loc[0]->TextHintDecode(m_loc, buf, hint, value);
    }

    auto CreateValue(const char *type, void **ppvObj) -> LxResult
    {
        return m_loc[0]->CreateValue(m_loc, type, ppvObj);
    }

    auto CreateValue(const char *type, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->CreateValue(m_loc, type, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto ValueType(const char *type, unsigned *valType) -> LxResult
    {
        return m_loc[0]->ValueType(m_loc, type, valType);
    }

    auto TextHintDuplicate(const LXtTextValueHint *hint, LXtTextValueHint **copy) -> LxResult
    {
        return m_loc[0]->TextHintDuplicate(m_loc, hint, copy);
    }

    auto TextHintFreeDuplicate(LXtTextValueHint *copy) -> LxResult
    {
        return m_loc[0]->TextHintFreeDuplicate(m_loc, copy);
    }

    auto FloatType(float val) -> int
    {
        return m_loc[0]->FloatType(m_loc, val);
    }

    auto GetFPS(void) -> double
    {
        return m_loc[0]->GetFPS(m_loc);
    }

    auto TimeToFrame(double time) -> double
    {
        return m_loc[0]->TimeToFrame(m_loc, time);
    }

    auto FrameToTime(double frame) -> double
    {
        return m_loc[0]->FrameToTime(m_loc, frame);
    }

    auto TimeToFrameFPS(double time, double fps) -> double
    {
        return m_loc[0]->TimeToFrameFPS(m_loc, time, fps);
    }

    auto FrameToTimeFPS(double frame, double fps) -> double
    {
        return m_loc[0]->FrameToTimeFPS(m_loc, frame, fps);
    }

    auto ConvertValues(const char *from, const char *to, void **ppvObj) -> LxResult
    {
        return m_loc[0]->ConvertValues(m_loc, from, to, ppvObj);
    }

    auto ConvertValues(const char *from, const char *to, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->ConvertValues(m_loc, from, to, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_Value
{
public:
    virtual ~CLxImpl_Value() = default;

    virtual auto val_Clone([[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto val_Copy([[maybe_unused]] ILxUnknownID from) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto val_Compare([[maybe_unused]] ILxUnknownID other, [[maybe_unused]] int *diff) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual unsigned int val_Type(void) = 0;

    virtual auto val_TypeName([[maybe_unused]] const char **name) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto val_SubTypeName([[maybe_unused]] const char **name) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto val_GetInt([[maybe_unused]] int *val) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto val_SetInt([[maybe_unused]] int val) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto val_GetFlt([[maybe_unused]] double *val) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto val_SetFlt([[maybe_unused]] double val) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto val_GetString([[maybe_unused]] char *buf, [[maybe_unused]] unsigned len) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto val_SetString([[maybe_unused]] const char *val) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto val_Intrinsic([[maybe_unused]] void) -> void *
    {
        return 0;
    }
};

#define LXxD_Value_Clone LxResult val_Clone([[maybe_unused]] void **ppvObj) override
#define LXxO_Value_Clone LXxD_Value_Clone
#define LXxC_Value_Clone(c) LxResult c::val_Clone([[maybe_unused]] void **ppvObj)
#define LXxD_Value_Copy LxResult val_Copy([[maybe_unused]] ILxUnknownID from) override
#define LXxO_Value_Copy LXxD_Value_Copy
#define LXxC_Value_Copy(c) LxResult c::val_Copy([[maybe_unused]] ILxUnknownID from)
#define LXxD_Value_Compare LxResult val_Compare([[maybe_unused]] ILxUnknownID other, [[maybe_unused]] int *diff) override
#define LXxO_Value_Compare LXxD_Value_Compare
#define LXxC_Value_Compare(c) LxResult c::val_Compare([[maybe_unused]] ILxUnknownID other, [[maybe_unused]] int *diff)
#define LXxD_Value_Type unsigned int val_Type() override
#define LXxO_Value_Type LXxD_Value_Type
#define LXxC_Value_Type(c) unsigned int c::val_Type()
#define LXxD_Value_TypeName LxResult val_TypeName([[maybe_unused]] const char **name) override
#define LXxO_Value_TypeName LXxD_Value_TypeName
#define LXxC_Value_TypeName(c) LxResult c::val_TypeName([[maybe_unused]] const char **name)
#define LXxD_Value_SubTypeName LxResult val_SubTypeName([[maybe_unused]] const char **name) override
#define LXxO_Value_SubTypeName LXxD_Value_SubTypeName
#define LXxC_Value_SubTypeName(c) LxResult c::val_SubTypeName([[maybe_unused]] const char **name)
#define LXxD_Value_GetInt LxResult val_GetInt([[maybe_unused]] int *val) override
#define LXxO_Value_GetInt LXxD_Value_GetInt
#define LXxC_Value_GetInt(c) LxResult c::val_GetInt([[maybe_unused]] int *val)
#define LXxD_Value_SetInt LxResult val_SetInt([[maybe_unused]] int val) override
#define LXxO_Value_SetInt LXxD_Value_SetInt
#define LXxC_Value_SetInt(c) LxResult c::val_SetInt([[maybe_unused]] int val)
#define LXxD_Value_GetFlt LxResult val_GetFlt([[maybe_unused]] double *val) override
#define LXxO_Value_GetFlt LXxD_Value_GetFlt
#define LXxC_Value_GetFlt(c) LxResult c::val_GetFlt([[maybe_unused]] double *val)
#define LXxD_Value_SetFlt LxResult val_SetFlt([[maybe_unused]] double val) override
#define LXxO_Value_SetFlt LXxD_Value_SetFlt
#define LXxC_Value_SetFlt(c) LxResult c::val_SetFlt([[maybe_unused]] double val)
#define LXxD_Value_GetString LxResult val_GetString([[maybe_unused]] char *buf, [[maybe_unused]] unsigned len) override
#define LXxO_Value_GetString LXxD_Value_GetString
#define LXxC_Value_GetString(c) LxResult c::val_GetString([[maybe_unused]] char *buf, [[maybe_unused]] unsigned len)
#define LXxD_Value_SetString LxResult val_SetString([[maybe_unused]] const char *val) override
#define LXxO_Value_SetString LXxD_Value_SetString
#define LXxC_Value_SetString(c) LxResult c::val_SetString([[maybe_unused]] const char *val)
#define LXxD_Value_Intrinsic void * val_Intrinsic() override
#define LXxO_Value_Intrinsic LXxD_Value_Intrinsic
#define LXxC_Value_Intrinsic(c) void * c::val_Intrinsic()

template <class T>
class CLxIfc_Value: public CLxInterface
{
public:
    CLxIfc_Value()
    {
        vt.Clone = Clone;
        vt.Copy = Copy;
        vt.Compare = Compare;
        vt.Type = Type;
        vt.TypeName = TypeName;
        vt.SubTypeName = SubTypeName;
        vt.GetInt = GetInt;
        vt.SetInt = SetInt;
        vt.GetFlt = GetFlt;
        vt.SetFlt = SetFlt;
        vt.GetString = GetString;
        vt.SetString = SetString;
        vt.Intrinsic = Intrinsic;
        vTable = &vt.iunk;
        iid = &lx::guid_Value;
    }

    static auto Clone(LXtObjectID wcom,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_Value, loc);
        try
        {
           return loc->val_Clone( ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Copy(LXtObjectID wcom,LXtObjectID from) -> LxResult
    {
        LXCWxINST (CLxImpl_Value, loc);
        try
        {
           return loc->val_Copy((ILxUnknownID) from);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Compare(LXtObjectID wcom,LXtObjectID other,int *diff) -> LxResult
    {
        LXCWxINST (CLxImpl_Value, loc);
        try
        {
           return loc->val_Compare((ILxUnknownID) other, diff);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Type(LXtObjectID wcom) -> unsigned int
    {
        LXCWxINST (CLxImpl_Value, loc);
        return loc->val_Type();
    }

    static auto TypeName(LXtObjectID wcom,const char **name) -> LxResult
    {
        LXCWxINST (CLxImpl_Value, loc);
        try
        {
           return loc->val_TypeName( name);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SubTypeName(LXtObjectID wcom,const char **name) -> LxResult
    {
        LXCWxINST (CLxImpl_Value, loc);
        try
        {
           return loc->val_SubTypeName( name);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto GetInt(LXtObjectID wcom,int *val) -> LxResult
    {
        LXCWxINST (CLxImpl_Value, loc);
        try
        {
           return loc->val_GetInt( val);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SetInt(LXtObjectID wcom,int val) -> LxResult
    {
        LXCWxINST (CLxImpl_Value, loc);
        try
        {
           return loc->val_SetInt( val);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto GetFlt(LXtObjectID wcom,double *val) -> LxResult
    {
        LXCWxINST (CLxImpl_Value, loc);
        try
        {
           return loc->val_GetFlt( val);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SetFlt(LXtObjectID wcom,double val) -> LxResult
    {
        LXCWxINST (CLxImpl_Value, loc);
        try
        {
           return loc->val_SetFlt( val);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto GetString(LXtObjectID wcom,char *buf,unsigned len) -> LxResult
    {
        LXCWxINST (CLxImpl_Value, loc);
        try
        {
           return loc->val_GetString( buf, len);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SetString(LXtObjectID wcom,const char *val) -> LxResult
    {
        LXCWxINST (CLxImpl_Value, loc);
        try
        {
           return loc->val_SetString( val);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Intrinsic(LXtObjectID wcom) -> void *
    {
        LXCWxINST (CLxImpl_Value, loc);
        return loc->val_Intrinsic();
    }

private:
    ILxValue vt;
};

class CLxLoc_Value : public CLxLocalize<ILxValueID>
{
public:
    CLxLoc_Value()
    {
        _init();
    }

    CLxLoc_Value(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_Value(CLxLoc_Value const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_Value;
    }

    auto Clone(void **ppvObj) -> LxResult
    {
        return m_loc[0]->Clone(m_loc, ppvObj);
    }

    auto Clone(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Clone(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Copy(ILxUnknownID from) -> LxResult
    {
        return m_loc[0]->Copy(m_loc,(ILxUnknownID) from);
    }

    auto Compare(ILxUnknownID other, int *diff) const -> LxResult
    {
        return m_loc[0]->Compare(m_loc,(ILxUnknownID) other, diff);
    }

    auto Type(void) const -> unsigned int
    {
        return m_loc[0]->Type(m_loc);
    }

    auto TypeName(const char **name) -> LxResult
    {
        return m_loc[0]->TypeName(m_loc, name);
    }

    auto SubTypeName(const char **name) -> LxResult
    {
        return m_loc[0]->SubTypeName(m_loc, name);
    }

    auto GetInt(int *val) const -> LxResult
    {
        return m_loc[0]->GetInt(m_loc, val);
    }

    auto SetInt(int val) -> LxResult
    {
        return m_loc[0]->SetInt(m_loc, val);
    }

    auto GetFlt(double *val) const -> LxResult
    {
        return m_loc[0]->GetFlt(m_loc, val);
    }

    auto SetFlt(double val) -> LxResult
    {
        return m_loc[0]->SetFlt(m_loc, val);
    }

    auto GetString(char *buf, unsigned len) const -> LxResult
    {
        return m_loc[0]->GetString(m_loc, buf, len);
    }

    auto GetString(std::string &result) const -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->GetString(m_loc, buf, len);
        LXWx_SBUF2
    }

    auto SetString(const char *val) -> LxResult
    {
        return m_loc[0]->SetString(m_loc, val);
    }

    auto Intrinsic(void) const -> void *
    {
        return m_loc[0]->Intrinsic(m_loc);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};

class CLxImpl_StringConversion
{
public:
    virtual ~CLxImpl_StringConversion() = default;

    virtual auto str_Encode([[maybe_unused]] char *buf, [[maybe_unused]] unsigned len) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto str_Decode([[maybe_unused]] const char *buf) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_StringConversion_Encode LxResult str_Encode([[maybe_unused]] char *buf, [[maybe_unused]] unsigned len) override
#define LXxO_StringConversion_Encode LXxD_StringConversion_Encode
#define LXxC_StringConversion_Encode(c) LxResult c::str_Encode([[maybe_unused]] char *buf, [[maybe_unused]] unsigned len)
#define LXxD_StringConversion_Decode LxResult str_Decode([[maybe_unused]] const char *buf) override
#define LXxO_StringConversion_Decode LXxD_StringConversion_Decode
#define LXxC_StringConversion_Decode(c) LxResult c::str_Decode([[maybe_unused]] const char *buf)

template <class T>
class CLxIfc_StringConversion: public CLxInterface
{
public:
    CLxIfc_StringConversion()
    {
        vt.Encode = Encode;
        vt.Decode = Decode;
        vTable = &vt.iunk;
        iid = &lx::guid_StringConversion;
    }

    static auto Encode(LXtObjectID wcom,char *buf,unsigned len) -> LxResult
    {
        LXCWxINST (CLxImpl_StringConversion, loc);
        try
        {
           return loc->str_Encode( buf, len);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Decode(LXtObjectID wcom,const char *buf) -> LxResult
    {
        LXCWxINST (CLxImpl_StringConversion, loc);
        try
        {
           return loc->str_Decode( buf);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxStringConversion vt;
};

class CLxLoc_StringConversion : public CLxLocalize<ILxStringConversionID>
{
public:
    CLxLoc_StringConversion()
    {
        _init();
    }

    CLxLoc_StringConversion(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_StringConversion(CLxLoc_StringConversion const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_StringConversion;
    }

    auto Encode(char *buf, unsigned len) const -> LxResult
    {
        return m_loc[0]->Encode(m_loc, buf, len);
    }

    auto Encode(std::string &result) const -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->Encode(m_loc, buf, len);
        LXWx_SBUF2
    }

    auto Decode(const char *buf) -> LxResult
    {
        return m_loc[0]->Decode(m_loc, buf);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_StringConversionNice
{
public:
    virtual ~CLxImpl_StringConversionNice() = default;

    virtual auto nicestr_Encode([[maybe_unused]] char *buf, [[maybe_unused]] unsigned len) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto nicestr_Decode([[maybe_unused]] const char *buf) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_StringConversionNice_Encode LxResult nicestr_Encode([[maybe_unused]] char *buf, [[maybe_unused]] unsigned len) override
#define LXxO_StringConversionNice_Encode LXxD_StringConversionNice_Encode
#define LXxC_StringConversionNice_Encode(c) LxResult c::nicestr_Encode([[maybe_unused]] char *buf, [[maybe_unused]] unsigned len)
#define LXxD_StringConversionNice_Decode LxResult nicestr_Decode([[maybe_unused]] const char *buf) override
#define LXxO_StringConversionNice_Decode LXxD_StringConversionNice_Decode
#define LXxC_StringConversionNice_Decode(c) LxResult c::nicestr_Decode([[maybe_unused]] const char *buf)

template <class T>
class CLxIfc_StringConversionNice: public CLxInterface
{
public:
    CLxIfc_StringConversionNice()
    {
        vt.Encode = Encode;
        vt.Decode = Decode;
        vTable = &vt.iunk;
        iid = &lx::guid_StringConversionNice;
    }

    static auto Encode(LXtObjectID wcom,char *buf,unsigned len) -> LxResult
    {
        LXCWxINST (CLxImpl_StringConversionNice, loc);
        try
        {
           return loc->nicestr_Encode( buf, len);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Decode(LXtObjectID wcom,const char *buf) -> LxResult
    {
        LXCWxINST (CLxImpl_StringConversionNice, loc);
        try
        {
           return loc->nicestr_Decode( buf);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxStringConversionNice vt;
};

class CLxLoc_StringConversionNice : public CLxLocalize<ILxStringConversionNiceID>
{
public:
    CLxLoc_StringConversionNice()
    {
        _init();
    }

    CLxLoc_StringConversionNice(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_StringConversionNice(CLxLoc_StringConversionNice const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_StringConversionNice;
    }

    auto Encode(char *buf, unsigned len) const -> LxResult
    {
        return m_loc[0]->Encode(m_loc, buf, len);
    }

    auto Encode(std::string &result) const -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->Encode(m_loc, buf, len);
        LXWx_SBUF2
    }

    auto Decode(const char *buf) -> LxResult
    {
        return m_loc[0]->Decode(m_loc, buf);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_ValueMath
{
public:
    virtual ~CLxImpl_ValueMath() = default;

    virtual auto math_Step([[maybe_unused]] int direction) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual int math_Detent(void) = 0;

    virtual auto math_Add([[maybe_unused]] double delta) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto math_Multiply([[maybe_unused]] double factor) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto math_Blend([[maybe_unused]] ILxUnknownID other, [[maybe_unused]] double blend) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_ValueMath_Step LxResult math_Step([[maybe_unused]] int direction) override
#define LXxO_ValueMath_Step LXxD_ValueMath_Step
#define LXxC_ValueMath_Step(c) LxResult c::math_Step([[maybe_unused]] int direction)
#define LXxD_ValueMath_Detent int math_Detent() override
#define LXxO_ValueMath_Detent LXxD_ValueMath_Detent
#define LXxC_ValueMath_Detent(c) int c::math_Detent()
#define LXxD_ValueMath_Add LxResult math_Add([[maybe_unused]] double delta) override
#define LXxO_ValueMath_Add LXxD_ValueMath_Add
#define LXxC_ValueMath_Add(c) LxResult c::math_Add([[maybe_unused]] double delta)
#define LXxD_ValueMath_Multiply LxResult math_Multiply([[maybe_unused]] double factor) override
#define LXxO_ValueMath_Multiply LXxD_ValueMath_Multiply
#define LXxC_ValueMath_Multiply(c) LxResult c::math_Multiply([[maybe_unused]] double factor)
#define LXxD_ValueMath_Blend LxResult math_Blend([[maybe_unused]] ILxUnknownID other, [[maybe_unused]] double blend) override
#define LXxO_ValueMath_Blend LXxD_ValueMath_Blend
#define LXxC_ValueMath_Blend(c) LxResult c::math_Blend([[maybe_unused]] ILxUnknownID other, [[maybe_unused]] double blend)

template <class T>
class CLxIfc_ValueMath: public CLxInterface
{
public:
    CLxIfc_ValueMath()
    {
        vt.Step = Step;
        vt.Detent = Detent;
        vt.Add = Add;
        vt.Multiply = Multiply;
        vt.Blend = Blend;
        vTable = &vt.iunk;
        iid = &lx::guid_ValueMath;
    }

    static auto Step(LXtObjectID wcom,int direction) -> LxResult
    {
        LXCWxINST (CLxImpl_ValueMath, loc);
        try
        {
           return loc->math_Step( direction);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Detent(LXtObjectID wcom) -> int
    {
        LXCWxINST (CLxImpl_ValueMath, loc);
        return loc->math_Detent();
    }

    static auto Add(LXtObjectID wcom,double delta) -> LxResult
    {
        LXCWxINST (CLxImpl_ValueMath, loc);
        try
        {
           return loc->math_Add( delta);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Multiply(LXtObjectID wcom,double factor) -> LxResult
    {
        LXCWxINST (CLxImpl_ValueMath, loc);
        try
        {
           return loc->math_Multiply( factor);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Blend(LXtObjectID wcom,LXtObjectID other,double blend) -> LxResult
    {
        LXCWxINST (CLxImpl_ValueMath, loc);
        try
        {
           return loc->math_Blend((ILxUnknownID) other, blend);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxValueMath vt;
};

class CLxLoc_ValueMath : public CLxLocalize<ILxValueMathID>
{
public:
    CLxLoc_ValueMath()
    {
        _init();
    }

    CLxLoc_ValueMath(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_ValueMath(CLxLoc_ValueMath const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_ValueMath;
    }

    auto Step(int direction) -> LxResult
    {
        return m_loc[0]->Step(m_loc, direction);
    }

    auto Detent(void) const -> int
    {
        return m_loc[0]->Detent(m_loc);
    }

    auto Add(double delta) -> LxResult
    {
        return m_loc[0]->Add(m_loc, delta);
    }

    auto Multiply(double factor) -> LxResult
    {
        return m_loc[0]->Multiply(m_loc, factor);
    }

    auto Blend(ILxUnknownID other, double blend) -> LxResult
    {
        return m_loc[0]->Blend(m_loc,(ILxUnknownID) other, blend);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_ValueReference : public CLxLocalize<ILxValueReferenceID>
{
public:
    CLxLoc_ValueReference()
    {
        _init();
    }

    CLxLoc_ValueReference(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_ValueReference(CLxLoc_ValueReference const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_ValueReference;
    }

    auto IsSet(void) const -> LxResult
    {
        return m_loc[0]->IsSet(m_loc);
    }

    auto GetObject(void **ppvObj) const -> LxResult
    {
        return m_loc[0]->GetObject(m_loc, ppvObj);
    }

    auto GetObject(CLxLocalizedObject &o_dest) const -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->GetObject(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto SetObject(ILxUnknownID obj) -> LxResult
    {
        return m_loc[0]->SetObject(m_loc,(ILxUnknownID) obj);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_ValueConversion
{
public:
    virtual ~CLxImpl_ValueConversion() = default;

    virtual auto conv_Test([[maybe_unused]] const char *fromType, [[maybe_unused]] const char *toType) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto conv_Convert([[maybe_unused]] ILxUnknownID from, [[maybe_unused]] const char *fromType, [[maybe_unused]] ILxUnknownID to, [[maybe_unused]] const char *toType) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_ValueConversion_Test LxResult conv_Test([[maybe_unused]] const char *fromType, [[maybe_unused]] const char *toType) override
#define LXxO_ValueConversion_Test LXxD_ValueConversion_Test
#define LXxC_ValueConversion_Test(c) LxResult c::conv_Test([[maybe_unused]] const char *fromType, [[maybe_unused]] const char *toType)
#define LXxD_ValueConversion_Convert LxResult conv_Convert([[maybe_unused]] ILxUnknownID from, [[maybe_unused]] const char *fromType, [[maybe_unused]] ILxUnknownID to, [[maybe_unused]] const char *toType) override
#define LXxO_ValueConversion_Convert LXxD_ValueConversion_Convert
#define LXxC_ValueConversion_Convert(c) LxResult c::conv_Convert([[maybe_unused]] ILxUnknownID from, [[maybe_unused]] const char *fromType, [[maybe_unused]] ILxUnknownID to, [[maybe_unused]] const char *toType)

template <class T>
class CLxIfc_ValueConversion: public CLxInterface
{
public:
    CLxIfc_ValueConversion()
    {
        vt.Test = Test;
        vt.Convert = Convert;
        vTable = &vt.iunk;
        iid = &lx::guid_ValueConversion;
    }

    static auto Test(LXtObjectID wcom,const char *fromType,const char *toType) -> LxResult
    {
        LXCWxINST (CLxImpl_ValueConversion, loc);
        try
        {
           return loc->conv_Test( fromType, toType);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Convert(LXtObjectID wcom,LXtObjectID from,const char *fromType,LXtObjectID to,const char *toType) -> LxResult
    {
        LXCWxINST (CLxImpl_ValueConversion, loc);
        try
        {
           return loc->conv_Convert((ILxUnknownID) from, fromType,(ILxUnknownID) to, toType);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxValueConversion vt;
};

class CLxLoc_ValueConversion : public CLxLocalize<ILxValueConversionID>
{
public:
    CLxLoc_ValueConversion()
    {
        _init();
    }

    CLxLoc_ValueConversion(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_ValueConversion(CLxLoc_ValueConversion const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_ValueConversion;
    }

    auto Test(const char *fromType, const char *toType) -> LxResult
    {
        return m_loc[0]->Test(m_loc, fromType, toType);
    }

    auto Convert(ILxUnknownID from, const char *fromType, ILxUnknownID to, const char *toType) -> LxResult
    {
        return m_loc[0]->Convert(m_loc,(ILxUnknownID) from, fromType,(ILxUnknownID) to, toType);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_Attributes
{
public:
    virtual ~CLxImpl_Attributes() = default;

    virtual auto attr_Count([[maybe_unused]] void) -> unsigned int
    {
        return 0;
    }

    virtual auto attr_Name([[maybe_unused]] unsigned int index, [[maybe_unused]] const char **name) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto attr_Lookup([[maybe_unused]] const char *name, [[maybe_unused]] unsigned int *index) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto attr_Type([[maybe_unused]] unsigned int index, [[maybe_unused]] unsigned int *type) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto attr_TypeName([[maybe_unused]] unsigned int index, [[maybe_unused]] const char **tname) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto attr_Hints([[maybe_unused]] unsigned int index) -> const LXtTextValueHint *
    {
        return 0;
    }

    virtual auto attr_Value([[maybe_unused]] unsigned int index, [[maybe_unused]] void **ppvObj, [[maybe_unused]] int writeOK) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto attr_GetInt([[maybe_unused]] unsigned int index, [[maybe_unused]] int *val) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto attr_SetInt([[maybe_unused]] unsigned int index, [[maybe_unused]] int val) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto attr_GetFlt([[maybe_unused]] unsigned int index, [[maybe_unused]] double *val) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto attr_SetFlt([[maybe_unused]] unsigned int index, [[maybe_unused]] double val) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto attr_GetString([[maybe_unused]] unsigned int index, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto attr_SetString([[maybe_unused]] unsigned int index, [[maybe_unused]] const char *val) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_Attributes_Count unsigned int attr_Count() override
#define LXxO_Attributes_Count LXxD_Attributes_Count
#define LXxC_Attributes_Count(c) unsigned int c::attr_Count()
#define LXxD_Attributes_Name LxResult attr_Name([[maybe_unused]] unsigned int index, [[maybe_unused]] const char **name) override
#define LXxO_Attributes_Name LXxD_Attributes_Name
#define LXxC_Attributes_Name(c) LxResult c::attr_Name([[maybe_unused]] unsigned int index, [[maybe_unused]] const char **name)
#define LXxD_Attributes_Lookup LxResult attr_Lookup([[maybe_unused]] const char *name, [[maybe_unused]] unsigned int *index) override
#define LXxO_Attributes_Lookup LXxD_Attributes_Lookup
#define LXxC_Attributes_Lookup(c) LxResult c::attr_Lookup([[maybe_unused]] const char *name, [[maybe_unused]] unsigned int *index)
#define LXxD_Attributes_Type LxResult attr_Type([[maybe_unused]] unsigned int index, [[maybe_unused]] unsigned int *type) override
#define LXxO_Attributes_Type LXxD_Attributes_Type
#define LXxC_Attributes_Type(c) LxResult c::attr_Type([[maybe_unused]] unsigned int index, [[maybe_unused]] unsigned int *type)
#define LXxD_Attributes_TypeName LxResult attr_TypeName([[maybe_unused]] unsigned int index, [[maybe_unused]] const char **tname) override
#define LXxO_Attributes_TypeName LXxD_Attributes_TypeName
#define LXxC_Attributes_TypeName(c) LxResult c::attr_TypeName([[maybe_unused]] unsigned int index, [[maybe_unused]] const char **tname)
#define LXxD_Attributes_Hints const LXtTextValueHint * attr_Hints([[maybe_unused]] unsigned int index) override
#define LXxO_Attributes_Hints LXxD_Attributes_Hints
#define LXxC_Attributes_Hints(c) const LXtTextValueHint * c::attr_Hints([[maybe_unused]] unsigned int index)
#define LXxD_Attributes_Value LxResult attr_Value([[maybe_unused]] unsigned int index, [[maybe_unused]] void **ppvObj, [[maybe_unused]] int writeOK) override
#define LXxO_Attributes_Value LXxD_Attributes_Value
#define LXxC_Attributes_Value(c) LxResult c::attr_Value([[maybe_unused]] unsigned int index, [[maybe_unused]] void **ppvObj, [[maybe_unused]] int writeOK)
#define LXxD_Attributes_GetInt LxResult attr_GetInt([[maybe_unused]] unsigned int index, [[maybe_unused]] int *val) override
#define LXxO_Attributes_GetInt LXxD_Attributes_GetInt
#define LXxC_Attributes_GetInt(c) LxResult c::attr_GetInt([[maybe_unused]] unsigned int index, [[maybe_unused]] int *val)
#define LXxD_Attributes_SetInt LxResult attr_SetInt([[maybe_unused]] unsigned int index, [[maybe_unused]] int val) override
#define LXxO_Attributes_SetInt LXxD_Attributes_SetInt
#define LXxC_Attributes_SetInt(c) LxResult c::attr_SetInt([[maybe_unused]] unsigned int index, [[maybe_unused]] int val)
#define LXxD_Attributes_GetFlt LxResult attr_GetFlt([[maybe_unused]] unsigned int index, [[maybe_unused]] double *val) override
#define LXxO_Attributes_GetFlt LXxD_Attributes_GetFlt
#define LXxC_Attributes_GetFlt(c) LxResult c::attr_GetFlt([[maybe_unused]] unsigned int index, [[maybe_unused]] double *val)
#define LXxD_Attributes_SetFlt LxResult attr_SetFlt([[maybe_unused]] unsigned int index, [[maybe_unused]] double val) override
#define LXxO_Attributes_SetFlt LXxD_Attributes_SetFlt
#define LXxC_Attributes_SetFlt(c) LxResult c::attr_SetFlt([[maybe_unused]] unsigned int index, [[maybe_unused]] double val)
#define LXxD_Attributes_GetString LxResult attr_GetString([[maybe_unused]] unsigned int index, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len) override
#define LXxO_Attributes_GetString LXxD_Attributes_GetString
#define LXxC_Attributes_GetString(c) LxResult c::attr_GetString([[maybe_unused]] unsigned int index, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len)
#define LXxD_Attributes_SetString LxResult attr_SetString([[maybe_unused]] unsigned int index, [[maybe_unused]] const char *val) override
#define LXxO_Attributes_SetString LXxD_Attributes_SetString
#define LXxC_Attributes_SetString(c) LxResult c::attr_SetString([[maybe_unused]] unsigned int index, [[maybe_unused]] const char *val)

template <class T>
class CLxIfc_Attributes: public CLxInterface
{
public:
    CLxIfc_Attributes()
    {
        vt.Count = Count;
        vt.Name = Name;
        vt.Lookup = Lookup;
        vt.Type = Type;
        vt.TypeName = TypeName;
        vt.Hints = Hints;
        vt.Value = Value;
        vt.GetInt = GetInt;
        vt.SetInt = SetInt;
        vt.GetFlt = GetFlt;
        vt.SetFlt = SetFlt;
        vt.GetString = GetString;
        vt.SetString = SetString;
        vTable = &vt.iunk;
        iid = &lx::guid_Attributes;
    }

    static auto Count(LXtObjectID wcom) -> unsigned int
    {
        LXCWxINST (CLxImpl_Attributes, loc);
        return loc->attr_Count();
    }

    static auto Name(LXtObjectID wcom,unsigned int index,const char **name) -> LxResult
    {
        LXCWxINST (CLxImpl_Attributes, loc);
        try
        {
           return loc->attr_Name( index, name);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Lookup(LXtObjectID wcom,const char *name,unsigned int *index) -> LxResult
    {
        LXCWxINST (CLxImpl_Attributes, loc);
        try
        {
           return loc->attr_Lookup( name, index);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Type(LXtObjectID wcom,unsigned int index,unsigned int *type) -> LxResult
    {
        LXCWxINST (CLxImpl_Attributes, loc);
        try
        {
           return loc->attr_Type( index, type);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto TypeName(LXtObjectID wcom,unsigned int index,const char **tname) -> LxResult
    {
        LXCWxINST (CLxImpl_Attributes, loc);
        try
        {
           return loc->attr_TypeName( index, tname);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Hints(LXtObjectID wcom,unsigned int index) -> const LXtTextValueHint *
    {
        LXCWxINST (CLxImpl_Attributes, loc);
        return loc->attr_Hints( index);
    }

    static auto Value(LXtObjectID wcom,unsigned int index,void **ppvObj,int writeOK) -> LxResult
    {
        LXCWxINST (CLxImpl_Attributes, loc);
        try
        {
           return loc->attr_Value( index, ppvObj, writeOK);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto GetInt(LXtObjectID wcom,unsigned int index,int *val) -> LxResult
    {
        LXCWxINST (CLxImpl_Attributes, loc);
        try
        {
           return loc->attr_GetInt( index, val);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SetInt(LXtObjectID wcom,unsigned int index,int val) -> LxResult
    {
        LXCWxINST (CLxImpl_Attributes, loc);
        try
        {
           return loc->attr_SetInt( index, val);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto GetFlt(LXtObjectID wcom,unsigned int index,double *val) -> LxResult
    {
        LXCWxINST (CLxImpl_Attributes, loc);
        try
        {
           return loc->attr_GetFlt( index, val);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SetFlt(LXtObjectID wcom,unsigned int index,double val) -> LxResult
    {
        LXCWxINST (CLxImpl_Attributes, loc);
        try
        {
           return loc->attr_SetFlt( index, val);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto GetString(LXtObjectID wcom,unsigned int index,char *buf,unsigned len) -> LxResult
    {
        LXCWxINST (CLxImpl_Attributes, loc);
        try
        {
           return loc->attr_GetString( index, buf, len);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SetString(LXtObjectID wcom,unsigned int index,const char *val) -> LxResult
    {
        LXCWxINST (CLxImpl_Attributes, loc);
        try
        {
           return loc->attr_SetString( index, val);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxAttributes vt;
};

class CLxLoc_Attributes : public CLxLocalize<ILxAttributesID>
{
public:
    CLxLoc_Attributes()
    {
        _init();
    }

    CLxLoc_Attributes(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_Attributes(CLxLoc_Attributes const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_Attributes;
    }

    auto Count(void) const -> unsigned int
    {
        return m_loc[0]->Count(m_loc);
    }

    auto Name(unsigned int index, const char **name) const -> LxResult
    {
        return m_loc[0]->Name(m_loc, index, name);
    }

    auto Lookup(const char *name, unsigned int *index) const -> LxResult
    {
        return m_loc[0]->Lookup(m_loc, name, index);
    }

    auto Type(unsigned int index, unsigned int *type) const -> LxResult
    {
        return m_loc[0]->Type(m_loc, index, type);
    }

    auto TypeName(unsigned int index, const char **tname) const -> LxResult
    {
        return m_loc[0]->TypeName(m_loc, index, tname);
    }

    auto Hints(unsigned int index) const -> const LXtTextValueHint *
    {
        return m_loc[0]->Hints(m_loc, index);
    }

    auto Value(unsigned int index, void **ppvObj, int writeOK) -> LxResult
    {
        return m_loc[0]->Value(m_loc, index, ppvObj, writeOK);
    }

    auto Value(unsigned int index, CLxLocalizedObject &o_dest, int writeOK) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Value(m_loc, index, &o_obj, writeOK);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto GetInt(unsigned int index, int *val) const -> LxResult
    {
        return m_loc[0]->GetInt(m_loc, index, val);
    }

    auto SetInt(unsigned int index, int val) -> LxResult
    {
        return m_loc[0]->SetInt(m_loc, index, val);
    }

    auto GetFlt(unsigned int index, double *val) const -> LxResult
    {
        return m_loc[0]->GetFlt(m_loc, index, val);
    }

    auto SetFlt(unsigned int index, double val) -> LxResult
    {
        return m_loc[0]->SetFlt(m_loc, index, val);
    }

    auto GetString(unsigned int index, char *buf, unsigned len) const -> LxResult
    {
        return m_loc[0]->GetString(m_loc, index, buf, len);
    }

    auto GetString(unsigned int index, std::string &result) const -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->GetString(m_loc, index, buf, len);
        LXWx_SBUF2
    }

    auto SetString(unsigned int index, const char *val) -> LxResult
    {
        return m_loc[0]->SetString(m_loc, index, val);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_Message
{
public:
    virtual ~CLxImpl_Message() = default;

    virtual auto msg_Code([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto msg_SetCode([[maybe_unused]] LxResult code) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto msg_SetMessage([[maybe_unused]] const char *table, [[maybe_unused]] const char *name, [[maybe_unused]] unsigned id) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto msg_SetArgumentInt([[maybe_unused]] unsigned arg, [[maybe_unused]] int value) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto msg_SetArgumentFloat([[maybe_unused]] unsigned arg, [[maybe_unused]] double value) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto msg_SetArgumentString([[maybe_unused]] unsigned arg, [[maybe_unused]] const char *string) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto msg_SetArgumentObject([[maybe_unused]] unsigned arg, [[maybe_unused]] ILxUnknownID object) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto msg_Reset([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto msg_Table([[maybe_unused]] const char **table) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto msg_Name([[maybe_unused]] const char **name) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto msg_SetMessageResult([[maybe_unused]] unsigned id) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_Message_Code LxResult msg_Code() override
#define LXxO_Message_Code LXxD_Message_Code
#define LXxC_Message_Code(c) LxResult c::msg_Code()
#define LXxD_Message_SetCode LxResult msg_SetCode([[maybe_unused]] LxResult code) override
#define LXxO_Message_SetCode LXxD_Message_SetCode
#define LXxC_Message_SetCode(c) LxResult c::msg_SetCode([[maybe_unused]] LxResult code)
#define LXxD_Message_SetMessage LxResult msg_SetMessage([[maybe_unused]] const char *table, [[maybe_unused]] const char *name, [[maybe_unused]] unsigned id) override
#define LXxO_Message_SetMessage LXxD_Message_SetMessage
#define LXxC_Message_SetMessage(c) LxResult c::msg_SetMessage([[maybe_unused]] const char *table, [[maybe_unused]] const char *name, [[maybe_unused]] unsigned id)
#define LXxD_Message_SetArgumentInt LxResult msg_SetArgumentInt([[maybe_unused]] unsigned arg, [[maybe_unused]] int value) override
#define LXxO_Message_SetArgumentInt LXxD_Message_SetArgumentInt
#define LXxC_Message_SetArgumentInt(c) LxResult c::msg_SetArgumentInt([[maybe_unused]] unsigned arg, [[maybe_unused]] int value)
#define LXxD_Message_SetArgumentFloat LxResult msg_SetArgumentFloat([[maybe_unused]] unsigned arg, [[maybe_unused]] double value) override
#define LXxO_Message_SetArgumentFloat LXxD_Message_SetArgumentFloat
#define LXxC_Message_SetArgumentFloat(c) LxResult c::msg_SetArgumentFloat([[maybe_unused]] unsigned arg, [[maybe_unused]] double value)
#define LXxD_Message_SetArgumentString LxResult msg_SetArgumentString([[maybe_unused]] unsigned arg, [[maybe_unused]] const char *string) override
#define LXxO_Message_SetArgumentString LXxD_Message_SetArgumentString
#define LXxC_Message_SetArgumentString(c) LxResult c::msg_SetArgumentString([[maybe_unused]] unsigned arg, [[maybe_unused]] const char *string)
#define LXxD_Message_SetArgumentObject LxResult msg_SetArgumentObject([[maybe_unused]] unsigned arg, [[maybe_unused]] ILxUnknownID object) override
#define LXxO_Message_SetArgumentObject LXxD_Message_SetArgumentObject
#define LXxC_Message_SetArgumentObject(c) LxResult c::msg_SetArgumentObject([[maybe_unused]] unsigned arg, [[maybe_unused]] ILxUnknownID object)
#define LXxD_Message_Reset LxResult msg_Reset() override
#define LXxO_Message_Reset LXxD_Message_Reset
#define LXxC_Message_Reset(c) LxResult c::msg_Reset()
#define LXxD_Message_Table LxResult msg_Table([[maybe_unused]] const char **table) override
#define LXxO_Message_Table LXxD_Message_Table
#define LXxC_Message_Table(c) LxResult c::msg_Table([[maybe_unused]] const char **table)
#define LXxD_Message_Name LxResult msg_Name([[maybe_unused]] const char **name) override
#define LXxO_Message_Name LXxD_Message_Name
#define LXxC_Message_Name(c) LxResult c::msg_Name([[maybe_unused]] const char **name)
#define LXxD_Message_SetMessageResult LxResult msg_SetMessageResult([[maybe_unused]] unsigned id) override
#define LXxO_Message_SetMessageResult LXxD_Message_SetMessageResult
#define LXxC_Message_SetMessageResult(c) LxResult c::msg_SetMessageResult([[maybe_unused]] unsigned id)

template <class T>
class CLxIfc_Message: public CLxInterface
{
public:
    CLxIfc_Message()
    {
        vt.Code = Code;
        vt.SetCode = SetCode;
        vt.SetMessage = SetMessage;
        vt.SetArgumentInt = SetArgumentInt;
        vt.SetArgumentFloat = SetArgumentFloat;
        vt.SetArgumentString = SetArgumentString;
        vt.SetArgumentObject = SetArgumentObject;
        vt.Reset = Reset;
        vt.Table = Table;
        vt.Name = Name;
        vt.SetMessageResult = SetMessageResult;
        vTable = &vt.iunk;
        iid = &lx::guid_Message;
    }

    static auto Code(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_Message, loc);
        try
        {
           return loc->msg_Code();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SetCode(LXtObjectID wcom,LxResult code) -> LxResult
    {
        LXCWxINST (CLxImpl_Message, loc);
        try
        {
           return loc->msg_SetCode( code);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SetMessage(LXtObjectID wcom,const char *table,const char *name,unsigned id) -> LxResult
    {
        LXCWxINST (CLxImpl_Message, loc);
        try
        {
           return loc->msg_SetMessage( table, name, id);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SetArgumentInt(LXtObjectID wcom,unsigned arg,int value) -> LxResult
    {
        LXCWxINST (CLxImpl_Message, loc);
        try
        {
           return loc->msg_SetArgumentInt( arg, value);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SetArgumentFloat(LXtObjectID wcom,unsigned arg,double value) -> LxResult
    {
        LXCWxINST (CLxImpl_Message, loc);
        try
        {
           return loc->msg_SetArgumentFloat( arg, value);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SetArgumentString(LXtObjectID wcom,unsigned arg,const char *string) -> LxResult
    {
        LXCWxINST (CLxImpl_Message, loc);
        try
        {
           return loc->msg_SetArgumentString( arg, string);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SetArgumentObject(LXtObjectID wcom,unsigned arg,LXtObjectID object) -> LxResult
    {
        LXCWxINST (CLxImpl_Message, loc);
        try
        {
           return loc->msg_SetArgumentObject( arg,(ILxUnknownID) object);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Reset(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_Message, loc);
        try
        {
           return loc->msg_Reset();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Table(LXtObjectID wcom,const char **table) -> LxResult
    {
        LXCWxINST (CLxImpl_Message, loc);
        try
        {
           return loc->msg_Table( table);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Name(LXtObjectID wcom,const char **name) -> LxResult
    {
        LXCWxINST (CLxImpl_Message, loc);
        try
        {
           return loc->msg_Name( name);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SetMessageResult(LXtObjectID wcom,unsigned id) -> LxResult
    {
        LXCWxINST (CLxImpl_Message, loc);
        try
        {
           return loc->msg_SetMessageResult( id);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxMessage vt;
};

class CLxLoc_Message : public CLxLocalize<ILxMessageID>
{
public:
    CLxLoc_Message()
    {
        _init();
    }

    CLxLoc_Message(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_Message(CLxLoc_Message const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_Message;
    }

    auto Code(void) -> LxResult
    {
        return m_loc[0]->Code(m_loc);
    }

    auto SetCode(LxResult code) -> LxResult
    {
        return m_loc[0]->SetCode(m_loc, code);
    }

    auto SetMessage(const char *table, const char *name, unsigned id) -> LxResult
    {
        return m_loc[0]->SetMessage(m_loc, table, name, id);
    }

    auto SetArgumentInt(unsigned arg, int value) -> LxResult
    {
        return m_loc[0]->SetArgumentInt(m_loc, arg, value);
    }

    auto SetArgumentFloat(unsigned arg, double value) -> LxResult
    {
        return m_loc[0]->SetArgumentFloat(m_loc, arg, value);
    }

    auto SetArgumentString(unsigned arg, const char *string) -> LxResult
    {
        return m_loc[0]->SetArgumentString(m_loc, arg, string);
    }

    auto SetArgumentObject(unsigned arg, ILxUnknownID object) -> LxResult
    {
        return m_loc[0]->SetArgumentObject(m_loc, arg,(ILxUnknownID) object);
    }

    auto Reset(void) -> LxResult
    {
        return m_loc[0]->Reset(m_loc);
    }

    auto Table(const char **table) -> LxResult
    {
        return m_loc[0]->Table(m_loc, table);
    }

    auto Name(const char **name) -> LxResult
    {
        return m_loc[0]->Name(m_loc, name);
    }

    auto SetMessageResult(unsigned id) -> LxResult
    {
        return m_loc[0]->SetMessageResult(m_loc, id);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_ValueArray
{
public:
    virtual ~CLxImpl_ValueArray() = default;

    virtual auto va_Type([[maybe_unused]] unsigned int *type) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto va_TypeName([[maybe_unused]] const char **name) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual unsigned int va_Count(void) = 0;

    virtual auto va_AddEmptyValue([[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto va_AddValue([[maybe_unused]] ILxUnknownID value) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto va_AddInt([[maybe_unused]] int value) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto va_AddFloat([[maybe_unused]] double value) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto va_AddString([[maybe_unused]] const char *value) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto va_GetValue([[maybe_unused]] unsigned int index, [[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto va_GetInt([[maybe_unused]] unsigned int index, [[maybe_unused]] int *value) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto va_GetFloat([[maybe_unused]] unsigned int index, [[maybe_unused]] double *value) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto va_GetString([[maybe_unused]] unsigned int index, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto va_FirstUnique([[maybe_unused]] unsigned int *uniqueIndex) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto va_Reset([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto va_Remove([[maybe_unused]] unsigned int index) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto va_SetValue([[maybe_unused]] unsigned int index, [[maybe_unused]] ILxUnknownID value) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto va_SetInt([[maybe_unused]] unsigned int index, [[maybe_unused]] int value) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto va_SetFloat([[maybe_unused]] unsigned int index, [[maybe_unused]] double value) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto va_SetString([[maybe_unused]] unsigned int index, [[maybe_unused]] const char *value) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_ValueArray_Type LxResult va_Type([[maybe_unused]] unsigned int *type) override
#define LXxO_ValueArray_Type LXxD_ValueArray_Type
#define LXxC_ValueArray_Type(c) LxResult c::va_Type([[maybe_unused]] unsigned int *type)
#define LXxD_ValueArray_TypeName LxResult va_TypeName([[maybe_unused]] const char **name) override
#define LXxO_ValueArray_TypeName LXxD_ValueArray_TypeName
#define LXxC_ValueArray_TypeName(c) LxResult c::va_TypeName([[maybe_unused]] const char **name)
#define LXxD_ValueArray_Count unsigned int va_Count() override
#define LXxO_ValueArray_Count LXxD_ValueArray_Count
#define LXxC_ValueArray_Count(c) unsigned int c::va_Count()
#define LXxD_ValueArray_AddEmptyValue LxResult va_AddEmptyValue([[maybe_unused]] void **ppvObj) override
#define LXxO_ValueArray_AddEmptyValue LXxD_ValueArray_AddEmptyValue
#define LXxC_ValueArray_AddEmptyValue(c) LxResult c::va_AddEmptyValue([[maybe_unused]] void **ppvObj)
#define LXxD_ValueArray_AddValue LxResult va_AddValue([[maybe_unused]] ILxUnknownID value) override
#define LXxO_ValueArray_AddValue LXxD_ValueArray_AddValue
#define LXxC_ValueArray_AddValue(c) LxResult c::va_AddValue([[maybe_unused]] ILxUnknownID value)
#define LXxD_ValueArray_AddInt LxResult va_AddInt([[maybe_unused]] int value) override
#define LXxO_ValueArray_AddInt LXxD_ValueArray_AddInt
#define LXxC_ValueArray_AddInt(c) LxResult c::va_AddInt([[maybe_unused]] int value)
#define LXxD_ValueArray_AddFloat LxResult va_AddFloat([[maybe_unused]] double value) override
#define LXxO_ValueArray_AddFloat LXxD_ValueArray_AddFloat
#define LXxC_ValueArray_AddFloat(c) LxResult c::va_AddFloat([[maybe_unused]] double value)
#define LXxD_ValueArray_AddString LxResult va_AddString([[maybe_unused]] const char *value) override
#define LXxO_ValueArray_AddString LXxD_ValueArray_AddString
#define LXxC_ValueArray_AddString(c) LxResult c::va_AddString([[maybe_unused]] const char *value)
#define LXxD_ValueArray_GetValue LxResult va_GetValue([[maybe_unused]] unsigned int index, [[maybe_unused]] void **ppvObj) override
#define LXxO_ValueArray_GetValue LXxD_ValueArray_GetValue
#define LXxC_ValueArray_GetValue(c) LxResult c::va_GetValue([[maybe_unused]] unsigned int index, [[maybe_unused]] void **ppvObj)
#define LXxD_ValueArray_GetInt LxResult va_GetInt([[maybe_unused]] unsigned int index, [[maybe_unused]] int *value) override
#define LXxO_ValueArray_GetInt LXxD_ValueArray_GetInt
#define LXxC_ValueArray_GetInt(c) LxResult c::va_GetInt([[maybe_unused]] unsigned int index, [[maybe_unused]] int *value)
#define LXxD_ValueArray_GetFloat LxResult va_GetFloat([[maybe_unused]] unsigned int index, [[maybe_unused]] double *value) override
#define LXxO_ValueArray_GetFloat LXxD_ValueArray_GetFloat
#define LXxC_ValueArray_GetFloat(c) LxResult c::va_GetFloat([[maybe_unused]] unsigned int index, [[maybe_unused]] double *value)
#define LXxD_ValueArray_GetString LxResult va_GetString([[maybe_unused]] unsigned int index, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len) override
#define LXxO_ValueArray_GetString LXxD_ValueArray_GetString
#define LXxC_ValueArray_GetString(c) LxResult c::va_GetString([[maybe_unused]] unsigned int index, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len)
#define LXxD_ValueArray_FirstUnique LxResult va_FirstUnique([[maybe_unused]] unsigned int *uniqueIndex) override
#define LXxO_ValueArray_FirstUnique LXxD_ValueArray_FirstUnique
#define LXxC_ValueArray_FirstUnique(c) LxResult c::va_FirstUnique([[maybe_unused]] unsigned int *uniqueIndex)
#define LXxD_ValueArray_Reset LxResult va_Reset() override
#define LXxO_ValueArray_Reset LXxD_ValueArray_Reset
#define LXxC_ValueArray_Reset(c) LxResult c::va_Reset()
#define LXxD_ValueArray_Remove LxResult va_Remove([[maybe_unused]] unsigned int index) override
#define LXxO_ValueArray_Remove LXxD_ValueArray_Remove
#define LXxC_ValueArray_Remove(c) LxResult c::va_Remove([[maybe_unused]] unsigned int index)
#define LXxD_ValueArray_SetValue LxResult va_SetValue([[maybe_unused]] unsigned int index, [[maybe_unused]] ILxUnknownID value) override
#define LXxO_ValueArray_SetValue LXxD_ValueArray_SetValue
#define LXxC_ValueArray_SetValue(c) LxResult c::va_SetValue([[maybe_unused]] unsigned int index, [[maybe_unused]] ILxUnknownID value)
#define LXxD_ValueArray_SetInt LxResult va_SetInt([[maybe_unused]] unsigned int index, [[maybe_unused]] int value) override
#define LXxO_ValueArray_SetInt LXxD_ValueArray_SetInt
#define LXxC_ValueArray_SetInt(c) LxResult c::va_SetInt([[maybe_unused]] unsigned int index, [[maybe_unused]] int value)
#define LXxD_ValueArray_SetFloat LxResult va_SetFloat([[maybe_unused]] unsigned int index, [[maybe_unused]] double value) override
#define LXxO_ValueArray_SetFloat LXxD_ValueArray_SetFloat
#define LXxC_ValueArray_SetFloat(c) LxResult c::va_SetFloat([[maybe_unused]] unsigned int index, [[maybe_unused]] double value)
#define LXxD_ValueArray_SetString LxResult va_SetString([[maybe_unused]] unsigned int index, [[maybe_unused]] const char *value) override
#define LXxO_ValueArray_SetString LXxD_ValueArray_SetString
#define LXxC_ValueArray_SetString(c) LxResult c::va_SetString([[maybe_unused]] unsigned int index, [[maybe_unused]] const char *value)

template <class T>
class CLxIfc_ValueArray: public CLxInterface
{
public:
    CLxIfc_ValueArray()
    {
        vt.Type = Type;
        vt.TypeName = TypeName;
        vt.Count = Count;
        vt.AddEmptyValue = AddEmptyValue;
        vt.AddValue = AddValue;
        vt.AddInt = AddInt;
        vt.AddFloat = AddFloat;
        vt.AddString = AddString;
        vt.GetValue = GetValue;
        vt.GetInt = GetInt;
        vt.GetFloat = GetFloat;
        vt.GetString = GetString;
        vt.FirstUnique = FirstUnique;
        vt.Reset = Reset;
        vt.Remove = Remove;
        vt.SetValue = SetValue;
        vt.SetInt = SetInt;
        vt.SetFloat = SetFloat;
        vt.SetString = SetString;
        vTable = &vt.iunk;
        iid = &lx::guid_ValueArray;
    }

    static auto Type(LXtObjectID wcom,unsigned int *type) -> LxResult
    {
        LXCWxINST (CLxImpl_ValueArray, loc);
        try
        {
           return loc->va_Type( type);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto TypeName(LXtObjectID wcom,const char **name) -> LxResult
    {
        LXCWxINST (CLxImpl_ValueArray, loc);
        try
        {
           return loc->va_TypeName( name);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Count(LXtObjectID wcom) -> unsigned int
    {
        LXCWxINST (CLxImpl_ValueArray, loc);
        return loc->va_Count();
    }

    static auto AddEmptyValue(LXtObjectID wcom,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_ValueArray, loc);
        try
        {
           return loc->va_AddEmptyValue( ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto AddValue(LXtObjectID wcom,LXtObjectID value) -> LxResult
    {
        LXCWxINST (CLxImpl_ValueArray, loc);
        try
        {
           return loc->va_AddValue((ILxUnknownID) value);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto AddInt(LXtObjectID wcom,int value) -> LxResult
    {
        LXCWxINST (CLxImpl_ValueArray, loc);
        try
        {
           return loc->va_AddInt( value);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto AddFloat(LXtObjectID wcom,double value) -> LxResult
    {
        LXCWxINST (CLxImpl_ValueArray, loc);
        try
        {
           return loc->va_AddFloat( value);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto AddString(LXtObjectID wcom,const char *value) -> LxResult
    {
        LXCWxINST (CLxImpl_ValueArray, loc);
        try
        {
           return loc->va_AddString( value);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto GetValue(LXtObjectID wcom,unsigned int index,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_ValueArray, loc);
        try
        {
           return loc->va_GetValue( index, ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto GetInt(LXtObjectID wcom,unsigned int index,int *value) -> LxResult
    {
        LXCWxINST (CLxImpl_ValueArray, loc);
        try
        {
           return loc->va_GetInt( index, value);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto GetFloat(LXtObjectID wcom,unsigned int index,double *value) -> LxResult
    {
        LXCWxINST (CLxImpl_ValueArray, loc);
        try
        {
           return loc->va_GetFloat( index, value);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto GetString(LXtObjectID wcom,unsigned int index,char *buf,unsigned len) -> LxResult
    {
        LXCWxINST (CLxImpl_ValueArray, loc);
        try
        {
           return loc->va_GetString( index, buf, len);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto FirstUnique(LXtObjectID wcom,unsigned int *uniqueIndex) -> LxResult
    {
        LXCWxINST (CLxImpl_ValueArray, loc);
        try
        {
           return loc->va_FirstUnique( uniqueIndex);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Reset(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_ValueArray, loc);
        try
        {
           return loc->va_Reset();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Remove(LXtObjectID wcom,unsigned int index) -> LxResult
    {
        LXCWxINST (CLxImpl_ValueArray, loc);
        try
        {
           return loc->va_Remove( index);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SetValue(LXtObjectID wcom,unsigned int index,LXtObjectID value) -> LxResult
    {
        LXCWxINST (CLxImpl_ValueArray, loc);
        try
        {
           return loc->va_SetValue( index,(ILxUnknownID) value);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SetInt(LXtObjectID wcom,unsigned int index,int value) -> LxResult
    {
        LXCWxINST (CLxImpl_ValueArray, loc);
        try
        {
           return loc->va_SetInt( index, value);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SetFloat(LXtObjectID wcom,unsigned int index,double value) -> LxResult
    {
        LXCWxINST (CLxImpl_ValueArray, loc);
        try
        {
           return loc->va_SetFloat( index, value);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SetString(LXtObjectID wcom,unsigned int index,const char *value) -> LxResult
    {
        LXCWxINST (CLxImpl_ValueArray, loc);
        try
        {
           return loc->va_SetString( index, value);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxValueArray vt;
};

class CLxLoc_ValueArray : public CLxLocalize<ILxValueArrayID>
{
public:
    CLxLoc_ValueArray()
    {
        _init();
    }

    CLxLoc_ValueArray(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_ValueArray(CLxLoc_ValueArray const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_ValueArray;
    }

    auto Type(unsigned int *type) -> LxResult
    {
        return m_loc[0]->Type(m_loc, type);
    }

    auto TypeName(const char **name) -> LxResult
    {
        return m_loc[0]->TypeName(m_loc, name);
    }

    auto Count(void) -> unsigned int
    {
        return m_loc[0]->Count(m_loc);
    }

    auto AddEmptyValue(void **ppvObj) -> LxResult
    {
        return m_loc[0]->AddEmptyValue(m_loc, ppvObj);
    }

    auto AddEmptyValue(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->AddEmptyValue(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto AddValue(ILxUnknownID value) -> LxResult
    {
        return m_loc[0]->AddValue(m_loc,(ILxUnknownID) value);
    }

    auto AddInt(int value) -> LxResult
    {
        return m_loc[0]->AddInt(m_loc, value);
    }

    auto AddFloat(double value) -> LxResult
    {
        return m_loc[0]->AddFloat(m_loc, value);
    }

    auto AddString(const char *value) -> LxResult
    {
        return m_loc[0]->AddString(m_loc, value);
    }

    auto GetValue(unsigned int index, void **ppvObj) -> LxResult
    {
        return m_loc[0]->GetValue(m_loc, index, ppvObj);
    }

    auto GetValue(unsigned int index, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->GetValue(m_loc, index, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto GetInt(unsigned int index, int *value) -> LxResult
    {
        return m_loc[0]->GetInt(m_loc, index, value);
    }

    auto GetFloat(unsigned int index, double *value) -> LxResult
    {
        return m_loc[0]->GetFloat(m_loc, index, value);
    }

    auto GetString(unsigned int index, char *buf, unsigned len) -> LxResult
    {
        return m_loc[0]->GetString(m_loc, index, buf, len);
    }

    auto GetString(unsigned int index, std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->GetString(m_loc, index, buf, len);
        LXWx_SBUF2
    }

    auto FirstUnique(unsigned int *uniqueIndex) -> LxResult
    {
        return m_loc[0]->FirstUnique(m_loc, uniqueIndex);
    }

    auto Reset(void) -> LxResult
    {
        return m_loc[0]->Reset(m_loc);
    }

    auto Remove(unsigned int index) -> LxResult
    {
        return m_loc[0]->Remove(m_loc, index);
    }

    auto SetValue(unsigned int index, ILxUnknownID value) -> LxResult
    {
        return m_loc[0]->SetValue(m_loc, index,(ILxUnknownID) value);
    }

    auto SetInt(unsigned int index, int value) -> LxResult
    {
        return m_loc[0]->SetInt(m_loc, index, value);
    }

    auto SetFloat(unsigned int index, double value) -> LxResult
    {
        return m_loc[0]->SetFloat(m_loc, index, value);
    }

    auto SetString(unsigned int index, const char *value) -> LxResult
    {
        return m_loc[0]->SetString(m_loc, index, value);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};


class CLxImpl_ScriptQuery
{
public:
    virtual ~CLxImpl_ScriptQuery() = default;

    virtual auto sq_Select([[maybe_unused]] const char *attribute, [[maybe_unused]] const char *which) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto sq_Query([[maybe_unused]] const char *attribute, [[maybe_unused]] ILxUnknownID query) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto sq_Type([[maybe_unused]] const char *attribute, [[maybe_unused]] int *type) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto sq_TypeName([[maybe_unused]] const char *attribute, [[maybe_unused]] const char **type) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_ScriptQuery_Select LxResult sq_Select([[maybe_unused]] const char *attribute, [[maybe_unused]] const char *which) override
#define LXxO_ScriptQuery_Select LXxD_ScriptQuery_Select
#define LXxC_ScriptQuery_Select(c) LxResult c::sq_Select([[maybe_unused]] const char *attribute, [[maybe_unused]] const char *which)
#define LXxD_ScriptQuery_Query LxResult sq_Query([[maybe_unused]] const char *attribute, [[maybe_unused]] ILxUnknownID query) override
#define LXxO_ScriptQuery_Query LXxD_ScriptQuery_Query
#define LXxC_ScriptQuery_Query(c) LxResult c::sq_Query([[maybe_unused]] const char *attribute, [[maybe_unused]] ILxUnknownID query)
#define LXxD_ScriptQuery_Type LxResult sq_Type([[maybe_unused]] const char *attribute, [[maybe_unused]] int *type) override
#define LXxO_ScriptQuery_Type LXxD_ScriptQuery_Type
#define LXxC_ScriptQuery_Type(c) LxResult c::sq_Type([[maybe_unused]] const char *attribute, [[maybe_unused]] int *type)
#define LXxD_ScriptQuery_TypeName LxResult sq_TypeName([[maybe_unused]] const char *attribute, [[maybe_unused]] const char **type) override
#define LXxO_ScriptQuery_TypeName LXxD_ScriptQuery_TypeName
#define LXxC_ScriptQuery_TypeName(c) LxResult c::sq_TypeName([[maybe_unused]] const char *attribute, [[maybe_unused]] const char **type)

template <class T>
class CLxIfc_ScriptQuery: public CLxInterface
{
public:
    CLxIfc_ScriptQuery()
    {
        vt.Select = Select;
        vt.Query = Query;
        vt.Type = Type;
        vt.TypeName = TypeName;
        vTable = &vt.iunk;
        iid = &lx::guid_ScriptQuery;
    }

    static auto Select(LXtObjectID wcom,const char *attribute,const char *which) -> LxResult
    {
        LXCWxINST (CLxImpl_ScriptQuery, loc);
        try
        {
           return loc->sq_Select( attribute, which);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Query(LXtObjectID wcom,const char *attribute,LXtObjectID query) -> LxResult
    {
        LXCWxINST (CLxImpl_ScriptQuery, loc);
        try
        {
           return loc->sq_Query( attribute,(ILxUnknownID) query);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Type(LXtObjectID wcom,const char *attribute,int *type) -> LxResult
    {
        LXCWxINST (CLxImpl_ScriptQuery, loc);
        try
        {
           return loc->sq_Type( attribute, type);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto TypeName(LXtObjectID wcom,const char *attribute,const char **type) -> LxResult
    {
        LXCWxINST (CLxImpl_ScriptQuery, loc);
        try
        {
           return loc->sq_TypeName( attribute, type);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxScriptQuery vt;
};

class CLxLoc_ScriptQuery : public CLxLocalize<ILxScriptQueryID>
{
public:
    CLxLoc_ScriptQuery()
    {
        _init();
    }

    CLxLoc_ScriptQuery(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_ScriptQuery(CLxLoc_ScriptQuery const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_ScriptQuery;
    }

    auto Select(const char *attribute, const char *which) -> LxResult
    {
        return m_loc[0]->Select(m_loc, attribute, which);
    }

    auto Query(const char *attribute, ILxUnknownID query) -> LxResult
    {
        return m_loc[0]->Query(m_loc, attribute,(ILxUnknownID) query);
    }

    auto Type(const char *attribute, int *type) -> LxResult
    {
        return m_loc[0]->Type(m_loc, attribute, type);
    }

    auto TypeName(const char *attribute, const char **type) -> LxResult
    {
        return m_loc[0]->TypeName(m_loc, attribute, type);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_StringTag
{
public:
    virtual ~CLxImpl_StringTag() = default;

    virtual auto stag_Get([[maybe_unused]] LXtID4 type, [[maybe_unused]] const char **tag) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto stag_Set([[maybe_unused]] LXtID4 type, [[maybe_unused]] const char *tag) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto stag_Count([[maybe_unused]] unsigned int *count) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto stag_ByIndex([[maybe_unused]] unsigned int index, [[maybe_unused]] LXtID4 *type, [[maybe_unused]] const char **tag) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_StringTag_Get LxResult stag_Get([[maybe_unused]] LXtID4 type, [[maybe_unused]] const char **tag) override
#define LXxO_StringTag_Get LXxD_StringTag_Get
#define LXxC_StringTag_Get(c) LxResult c::stag_Get([[maybe_unused]] LXtID4 type, [[maybe_unused]] const char **tag)
#define LXxD_StringTag_Set LxResult stag_Set([[maybe_unused]] LXtID4 type, [[maybe_unused]] const char *tag) override
#define LXxO_StringTag_Set LXxD_StringTag_Set
#define LXxC_StringTag_Set(c) LxResult c::stag_Set([[maybe_unused]] LXtID4 type, [[maybe_unused]] const char *tag)
#define LXxD_StringTag_Count LxResult stag_Count([[maybe_unused]] unsigned int *count) override
#define LXxO_StringTag_Count LXxD_StringTag_Count
#define LXxC_StringTag_Count(c) LxResult c::stag_Count([[maybe_unused]] unsigned int *count)
#define LXxD_StringTag_ByIndex LxResult stag_ByIndex([[maybe_unused]] unsigned int index, [[maybe_unused]] LXtID4 *type, [[maybe_unused]] const char **tag) override
#define LXxO_StringTag_ByIndex LXxD_StringTag_ByIndex
#define LXxC_StringTag_ByIndex(c) LxResult c::stag_ByIndex([[maybe_unused]] unsigned int index, [[maybe_unused]] LXtID4 *type, [[maybe_unused]] const char **tag)

template <class T>
class CLxIfc_StringTag: public CLxInterface
{
public:
    CLxIfc_StringTag()
    {
        vt.Get = Get;
        vt.Set = Set;
        vt.Count = Count;
        vt.ByIndex = ByIndex;
        vTable = &vt.iunk;
        iid = &lx::guid_StringTag;
    }

    static auto Get(LXtObjectID wcom,LXtID4 type,const char **tag) -> LxResult
    {
        LXCWxINST (CLxImpl_StringTag, loc);
        try
        {
           return loc->stag_Get( type, tag);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Set(LXtObjectID wcom,LXtID4 type,const char *tag) -> LxResult
    {
        LXCWxINST (CLxImpl_StringTag, loc);
        try
        {
           return loc->stag_Set( type, tag);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Count(LXtObjectID wcom,unsigned int *count) -> LxResult
    {
        LXCWxINST (CLxImpl_StringTag, loc);
        try
        {
           return loc->stag_Count( count);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ByIndex(LXtObjectID wcom,unsigned int index,LXtID4 *type,const char **tag) -> LxResult
    {
        LXCWxINST (CLxImpl_StringTag, loc);
        try
        {
           return loc->stag_ByIndex( index, type, tag);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxStringTag vt;
};

class CLxLoc_StringTag : public CLxLocalize<ILxStringTagID>
{
public:
    CLxLoc_StringTag()
    {
        _init();
    }

    CLxLoc_StringTag(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_StringTag(CLxLoc_StringTag const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_StringTag;
    }

    auto Get(LXtID4 type, const char **tag) -> LxResult
    {
        return m_loc[0]->Get(m_loc, type, tag);
    }

    auto Set(LXtID4 type, const char *tag) -> LxResult
    {
        return m_loc[0]->Set(m_loc, type, tag);
    }

    auto Count(unsigned int *count) -> LxResult
    {
        return m_loc[0]->Count(m_loc, count);
    }

    auto ByIndex(unsigned int index, LXtID4 *type, const char **tag) -> LxResult
    {
        return m_loc[0]->ByIndex(m_loc, index, type, tag);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_Matrix : public CLxLocalize<ILxMatrixID>
{
public:
    CLxLoc_Matrix()
    {
        _init();
    }

    CLxLoc_Matrix(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_Matrix(CLxLoc_Matrix const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_Matrix;
    }

    auto Get3(LXtMatrix mat3) const -> LxResult
    {
        return m_loc[0]->Get3(m_loc, mat3);
    }

    auto Get4(LXtMatrix4 mat4) const -> LxResult
    {
        return m_loc[0]->Get4(m_loc, mat4);
    }

    auto GetOffset(LXtVector offset) const -> LxResult
    {
        return m_loc[0]->GetOffset(m_loc, offset);
    }

    auto MultiplyVector(const LXtVector vector, LXtVector result) const -> LxResult
    {
        return m_loc[0]->MultiplyVector(m_loc, vector, result);
    }

    auto Set3(const LXtMatrix mat3) -> LxResult
    {
        return m_loc[0]->Set3(m_loc, mat3);
    }

    auto Set4(const LXtMatrix4 mat4) -> LxResult
    {
        return m_loc[0]->Set4(m_loc, mat4);
    }

    auto SetOffset(const LXtVector offset) -> LxResult
    {
        return m_loc[0]->SetOffset(m_loc, offset);
    }

    auto SetIdentity(void) -> LxResult
    {
        return m_loc[0]->SetIdentity(m_loc);
    }

    auto Multiply3(const LXtMatrix mat3) -> LxResult
    {
        return m_loc[0]->Multiply3(m_loc, mat3);
    }

    auto Multiply4(const LXtMatrix4 mat4) -> LxResult
    {
        return m_loc[0]->Multiply4(m_loc, mat4);
    }

    auto Invert(void) -> LxResult
    {
        return m_loc[0]->Invert(m_loc);
    }

    auto Transpose(void) -> LxResult
    {
        return m_loc[0]->Transpose(m_loc);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_Quaternion : public CLxLocalize<ILxQuaternionID>
{
public:
    CLxLoc_Quaternion()
    {
        _init();
    }

    CLxLoc_Quaternion(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_Quaternion(CLxLoc_Quaternion const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_Quaternion;
    }

    auto GetQuaternion(LXtQuaternion q) const -> LxResult
    {
        return m_loc[0]->GetQuaternion(m_loc, q);
    }

    auto GetMatrix(LXtMatrix mat3) const -> LxResult
    {
        return m_loc[0]->GetMatrix(m_loc, mat3);
    }

    auto GetAngleAxis(double *ang, LXtVector axis) const -> LxResult
    {
        return m_loc[0]->GetAngleAxis(m_loc, ang, axis);
    }

    auto SetQuaternion(const LXtQuaternion q) -> LxResult
    {
        return m_loc[0]->SetQuaternion(m_loc, q);
    }

    auto SetMatrix(const LXtMatrix mat3) -> LxResult
    {
        return m_loc[0]->SetMatrix(m_loc, mat3);
    }

    auto SetAngleAxis(double ang, const LXtVector axis) -> LxResult
    {
        return m_loc[0]->SetAngleAxis(m_loc, ang, axis);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_Visitor
{
public:
    virtual ~CLxImpl_Visitor() = default;

    virtual auto vis_Evaluate([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_Visitor_Evaluate LxResult vis_Evaluate() override
#define LXxO_Visitor_Evaluate LXxD_Visitor_Evaluate
#define LXxC_Visitor_Evaluate(c) LxResult c::vis_Evaluate()

template <class T>
class CLxIfc_Visitor: public CLxInterface
{
public:
    CLxIfc_Visitor()
    {
        vt.Evaluate = Evaluate;
        vTable = &vt.iunk;
        iid = &lx::guid_Visitor;
    }

    static auto Evaluate(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_Visitor, loc);
        try
        {
           return loc->vis_Evaluate();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxVisitor vt;
};

class CLxLoc_Visitor : public CLxLocalize<ILxVisitorID>
{
public:
    CLxLoc_Visitor()
    {
        _init();
    }

    CLxLoc_Visitor(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_Visitor(CLxLoc_Visitor const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_Visitor;
    }

    auto Evaluate(void) -> LxResult
    {
        return m_loc[0]->Evaluate(m_loc);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_TextEncoding : public CLxLocalize<ILxTextEncodingID>
{
public:
    CLxLoc_TextEncoding()
    {
        _init();
    }

    CLxLoc_TextEncoding(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_TextEncoding(CLxLoc_TextEncoding const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_TextEncoding;
    }

    auto Default(void) -> unsigned
    {
        return m_loc[0]->Default(m_loc);
    }

    auto Source(void) -> unsigned
    {
        return m_loc[0]->Source(m_loc);
    }

    auto Target(void) -> unsigned
    {
        return m_loc[0]->Target(m_loc);
    }

    auto SetSource(unsigned encoding) -> LxResult
    {
        return m_loc[0]->SetSource(m_loc, encoding);
    }

    auto SetTarget(unsigned encoding) -> LxResult
    {
        return m_loc[0]->SetTarget(m_loc, encoding);
    }

    auto Convert(const char *src, char *buf, unsigned max) -> LxResult
    {
        return m_loc[0]->Convert(m_loc, src, buf, max);
    }

    auto NumChar(const char *string, int target) -> int
    {
        return m_loc[0]->NumChar(m_loc, string, target);
    }

    auto PullChar(const char *string, int *code, int *len, int target) -> const char *
    {
        return m_loc[0]->PullChar(m_loc, string, code, len, target);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_TextEncodingService : public CLxLocalizedService
{
public:
    ILxTextEncodingServiceID m_loc{ nullptr };

public:
    CLxLoc_TextEncodingService()
    {
        _init();
        set();
    }

    ~CLxLoc_TextEncodingService() = default;

    void set()
    {
        if (!m_loc)
        {
            m_loc = reinterpret_cast<ILxTextEncodingServiceID>(lx::GetGlobal(&lx::guid_TextEncodingService));
        }
    }

    auto Allocate(void **ppvObj) -> LxResult
    {
        return m_loc[0]->Allocate(m_loc, ppvObj);
    }

    auto Allocate(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Allocate(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
