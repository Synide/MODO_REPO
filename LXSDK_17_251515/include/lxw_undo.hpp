//
// C++ wrapper for lxsdk/lxundo.h.
//
//	Copyright 2024.
//
//
#pragma once

#include <lxundo.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx
{
    static LXtGUID const guid_Undo = {0x17FF7DDF, {0x6F9B, 0x47F1}, {0x83, 0x35, 0x57, 0xA4, 0x1D, 0xB3, 0xD3, 0xAD}};
    static LXtGUID const guid_UndoService = {0xD8CA1EC8, {0xF6A0, 0x463E}, {0xAB, 0x82, 0x94, 0x78, 0xA2, 0x81, 0xB2, 0xCB}};
} // namespace lx

class CLxImpl_Undo
{
public:
    virtual ~CLxImpl_Undo() = default;

    virtual void undo_Forward([[maybe_unused]] void)
    {
    }

    virtual void undo_Reverse([[maybe_unused]] void)
    {
    }
};

#define LXxD_Undo_Forward void undo_Forward() override
#define LXxO_Undo_Forward LXxD_Undo_Forward
#define LXxC_Undo_Forward(c) void c::undo_Forward()
#define LXxD_Undo_Reverse void undo_Reverse() override
#define LXxO_Undo_Reverse LXxD_Undo_Reverse
#define LXxC_Undo_Reverse(c) void c::undo_Reverse()

template <class T>
class CLxIfc_Undo: public CLxInterface
{
public:
    CLxIfc_Undo()
    {
        vt.Forward = Forward;
        vt.Reverse = Reverse;
        vTable = &vt.iunk;
        iid = &lx::guid_Undo;
    }

    static auto Forward(LXtObjectID wcom) -> void
    {
        LXCWxINST (CLxImpl_Undo, loc);
        loc->undo_Forward();
    }

    static auto Reverse(LXtObjectID wcom) -> void
    {
        LXCWxINST (CLxImpl_Undo, loc);
        loc->undo_Reverse();
    }

private:
    ILxUndo vt;
};

class CLxLoc_Undo : public CLxLocalize<ILxUndoID>
{
public:
    CLxLoc_Undo()
    {
        _init();
    }

    CLxLoc_Undo(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_Undo(CLxLoc_Undo const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_Undo;
    }

    auto Forward(void) -> void
    {
        m_loc[0]->Forward(m_loc);
    }

    auto Reverse(void) -> void
    {
        m_loc[0]->Reverse(m_loc);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_UndoService : public CLxLocalizedService
{
public:
    ILxUndoServiceID m_loc{ nullptr };

public:
    CLxLoc_UndoService()
    {
        _init();
        set();
    }

    ~CLxLoc_UndoService() = default;

    void set()
    {
        if (!m_loc)
        {
            m_loc = reinterpret_cast<ILxUndoServiceID>(lx::GetGlobal(&lx::guid_UndoService));
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

    auto State(void) -> unsigned int
    {
        return m_loc[0]->State(m_loc);
    }

    auto Apply(ILxUnknownID undo) -> LxResult
    {
        return m_loc[0]->Apply(m_loc,(ILxUnknownID) undo);
    }

    auto Record(ILxUnknownID undo) -> LxResult
    {
        return m_loc[0]->Record(m_loc,(ILxUnknownID) undo);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
