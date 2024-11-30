//
// C++ wrapper for lxsdk/lxforce.h.
//
//	Copyright 2024.
//
//
#pragma once

#include <lxforce.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx
{
    static LXtGUID const guid_Force = {0xA712DF74, {0x0DD4, 0x4D8C}, {0x87, 0xB7, 0xCD, 0xF6, 0x6D, 0x4E, 0x68, 0x48}};
} // namespace lx

class CLxImpl_Force
{
public:
    virtual ~CLxImpl_Force() = default;

    virtual auto force_Flags([[maybe_unused]] void) -> unsigned
    {
        return 0;
    }

    virtual auto force_Force([[maybe_unused]] const LXtFVector pos, [[maybe_unused]] LXtFVector force) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto force_ForceV([[maybe_unused]] const LXtFVector pos, [[maybe_unused]] const LXtFVector velocity, [[maybe_unused]] LXtFVector force) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto force_ForceM([[maybe_unused]] const LXtFVector pos, [[maybe_unused]] float mass, [[maybe_unused]] LXtFVector force) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto force_ForceVM([[maybe_unused]] const LXtFVector pos, [[maybe_unused]] const LXtFVector velocity, [[maybe_unused]] float mass, [[maybe_unused]] LXtFVector force) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto force_ForceRun([[maybe_unused]] const float **pos, [[maybe_unused]] const float **velocity, [[maybe_unused]] const float *mass, [[maybe_unused]] float **force, [[maybe_unused]] unsigned num) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto force_ForceRunAng([[maybe_unused]] const float **pos, [[maybe_unused]] const float **velocity, [[maybe_unused]] const float **angVel, [[maybe_unused]] const float *mass, [[maybe_unused]] float **force, [[maybe_unused]] float **torque, [[maybe_unused]] unsigned num) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_Force_Flags unsigned force_Flags() override
#define LXxO_Force_Flags LXxD_Force_Flags
#define LXxC_Force_Flags(c) unsigned c::force_Flags()
#define LXxD_Force_Force LxResult force_Force([[maybe_unused]] const LXtFVector pos, [[maybe_unused]] LXtFVector force) override
#define LXxO_Force_Force LXxD_Force_Force
#define LXxC_Force_Force(c) LxResult c::force_Force([[maybe_unused]] const LXtFVector pos, [[maybe_unused]] LXtFVector force)
#define LXxD_Force_ForceV LxResult force_ForceV([[maybe_unused]] const LXtFVector pos, [[maybe_unused]] const LXtFVector velocity, [[maybe_unused]] LXtFVector force) override
#define LXxO_Force_ForceV LXxD_Force_ForceV
#define LXxC_Force_ForceV(c) LxResult c::force_ForceV([[maybe_unused]] const LXtFVector pos, [[maybe_unused]] const LXtFVector velocity, [[maybe_unused]] LXtFVector force)
#define LXxD_Force_ForceM LxResult force_ForceM([[maybe_unused]] const LXtFVector pos, [[maybe_unused]] float mass, [[maybe_unused]] LXtFVector force) override
#define LXxO_Force_ForceM LXxD_Force_ForceM
#define LXxC_Force_ForceM(c) LxResult c::force_ForceM([[maybe_unused]] const LXtFVector pos, [[maybe_unused]] float mass, [[maybe_unused]] LXtFVector force)
#define LXxD_Force_ForceVM LxResult force_ForceVM([[maybe_unused]] const LXtFVector pos, [[maybe_unused]] const LXtFVector velocity, [[maybe_unused]] float mass, [[maybe_unused]] LXtFVector force) override
#define LXxO_Force_ForceVM LXxD_Force_ForceVM
#define LXxC_Force_ForceVM(c) LxResult c::force_ForceVM([[maybe_unused]] const LXtFVector pos, [[maybe_unused]] const LXtFVector velocity, [[maybe_unused]] float mass, [[maybe_unused]] LXtFVector force)
#define LXxD_Force_ForceRun LxResult force_ForceRun([[maybe_unused]] const float **pos, [[maybe_unused]] const float **velocity, [[maybe_unused]] const float *mass, [[maybe_unused]] float **force, [[maybe_unused]] unsigned num) override
#define LXxO_Force_ForceRun LXxD_Force_ForceRun
#define LXxC_Force_ForceRun(c) LxResult c::force_ForceRun([[maybe_unused]] const float **pos, [[maybe_unused]] const float **velocity, [[maybe_unused]] const float *mass, [[maybe_unused]] float **force, [[maybe_unused]] unsigned num)
#define LXxD_Force_ForceRunAng LxResult force_ForceRunAng([[maybe_unused]] const float **pos, [[maybe_unused]] const float **velocity, [[maybe_unused]] const float **angVel, [[maybe_unused]] const float *mass, [[maybe_unused]] float **force, [[maybe_unused]] float **torque, [[maybe_unused]] unsigned num) override
#define LXxO_Force_ForceRunAng LXxD_Force_ForceRunAng
#define LXxC_Force_ForceRunAng(c) LxResult c::force_ForceRunAng([[maybe_unused]] const float **pos, [[maybe_unused]] const float **velocity, [[maybe_unused]] const float **angVel, [[maybe_unused]] const float *mass, [[maybe_unused]] float **force, [[maybe_unused]] float **torque, [[maybe_unused]] unsigned num)

template <class T>
class CLxIfc_Force: public CLxInterface
{
public:
    CLxIfc_Force()
    {
        vt.Flags = Flags;
        vt.Force = Force;
        vt.ForceV = ForceV;
        vt.ForceM = ForceM;
        vt.ForceVM = ForceVM;
        vt.ForceRun = ForceRun;
        vt.ForceRunAng = ForceRunAng;
        vTable = &vt.iunk;
        iid = &lx::guid_Force;
    }

    static auto Flags(LXtObjectID wcom) -> unsigned
    {
        LXCWxINST (CLxImpl_Force, loc);
        return loc->force_Flags();
    }

    static auto Force(LXtObjectID wcom,const LXtFVector pos,LXtFVector force) -> LxResult
    {
        LXCWxINST (CLxImpl_Force, loc);
        try
        {
           return loc->force_Force( pos, force);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ForceV(LXtObjectID wcom,const LXtFVector pos,const LXtFVector velocity,LXtFVector force) -> LxResult
    {
        LXCWxINST (CLxImpl_Force, loc);
        try
        {
           return loc->force_ForceV( pos, velocity, force);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ForceM(LXtObjectID wcom,const LXtFVector pos,float mass,LXtFVector force) -> LxResult
    {
        LXCWxINST (CLxImpl_Force, loc);
        try
        {
           return loc->force_ForceM( pos, mass, force);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ForceVM(LXtObjectID wcom,const LXtFVector pos,const LXtFVector velocity,float mass,LXtFVector force) -> LxResult
    {
        LXCWxINST (CLxImpl_Force, loc);
        try
        {
           return loc->force_ForceVM( pos, velocity, mass, force);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ForceRun(LXtObjectID wcom,const float **pos,const float **velocity,const float *mass,float **force,unsigned num) -> LxResult
    {
        LXCWxINST (CLxImpl_Force, loc);
        try
        {
           return loc->force_ForceRun( pos, velocity, mass, force, num);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ForceRunAng(LXtObjectID wcom,const float **pos,const float **velocity,const float **angVel,const float *mass,float **force,float **torque,unsigned num) -> LxResult
    {
        LXCWxINST (CLxImpl_Force, loc);
        try
        {
           return loc->force_ForceRunAng( pos, velocity, angVel, mass, force, torque, num);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxForce vt;
};

class CLxLoc_Force : public CLxLocalize<ILxForceID>
{
public:
    CLxLoc_Force()
    {
        _init();
    }

    CLxLoc_Force(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_Force(CLxLoc_Force const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_Force;
    }

    auto Flags(void) -> unsigned
    {
        return m_loc[0]->Flags(m_loc);
    }

    auto Force(const LXtFVector pos, LXtFVector force) -> LxResult
    {
        return m_loc[0]->Force(m_loc, pos, force);
    }

    auto ForceV(const LXtFVector pos, const LXtFVector velocity, LXtFVector force) -> LxResult
    {
        return m_loc[0]->ForceV(m_loc, pos, velocity, force);
    }

    auto ForceM(const LXtFVector pos, float mass, LXtFVector force) -> LxResult
    {
        return m_loc[0]->ForceM(m_loc, pos, mass, force);
    }

    auto ForceVM(const LXtFVector pos, const LXtFVector velocity, float mass, LXtFVector force) -> LxResult
    {
        return m_loc[0]->ForceVM(m_loc, pos, velocity, mass, force);
    }

    auto ForceRun(const float **pos, const float **velocity, const float *mass, float **force, unsigned num) -> LxResult
    {
        return m_loc[0]->ForceRun(m_loc, pos, velocity, mass, force, num);
    }

    auto ForceRunAng(const float **pos, const float **velocity, const float **angVel, const float *mass, float **force, float **torque, unsigned num) -> LxResult
    {
        return m_loc[0]->ForceRunAng(m_loc, pos, velocity, angVel, mass, force, torque, num);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
