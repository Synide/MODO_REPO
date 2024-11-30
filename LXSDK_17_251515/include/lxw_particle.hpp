//
// C++ wrapper for lxsdk/lxparticle.h.
//
//	Copyright 2024.
//
//
#pragma once

#include <lxparticle.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx
{
    static LXtGUID const guid_ParticleItem = {0xBA13DD5D, {0x5093, 0x4D0D}, {0xBE, 0xFE, 0x11, 0x9A, 0xD4, 0xF1, 0xFA, 0xCB}};
    static LXtGUID const guid_ReplicatorEnumerator = {0x01EC90A9, {0x924F, 0x4475}, {0xBA, 0x6A, 0xFF, 0xF8, 0xA2, 0x69, 0x1C, 0xD5}};
    static LXtGUID const guid_ParticleEvalFrame = {0x1AC26263, {0xA422, 0x4B17}, {0xA9, 0x29, 0x2F, 0x61, 0x60, 0x37, 0x75, 0x4F}};
    static LXtGUID const guid_ParticleFilter = {0x04A3C0C5, {0x1C5C, 0x43F5}, {0x85, 0x59, 0xAC, 0xF3, 0xBA, 0xE7, 0x9C, 0x0B}};
    static LXtGUID const guid_ParticleCoOperator = {0xDFBCF67B, {0xC327, 0x496E}, {0x8A, 0x30, 0x20, 0xB6, 0x4C, 0x31, 0xA9, 0xBB}};
    static LXtGUID const guid_PointCacheItem = {0x10930C44, {0x62D3, 0x42D1}, {0xBD, 0x6B, 0x8F, 0xE0, 0x15, 0xD9, 0xC5, 0x66}};
    static LXtGUID const guid_ParticleService = {0x34928BF8, {0x3917, 0x47EF}, {0x83, 0x50, 0xDD, 0x3A, 0x3D, 0xDE, 0xD7, 0xEE}};
} // namespace lx

class CLxImpl_ParticleItem
{
public:
    virtual ~CLxImpl_ParticleItem() = default;

    virtual auto prti_Prepare([[maybe_unused]] ILxUnknownID eval, [[maybe_unused]] unsigned *index) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto prti_Evaluate([[maybe_unused]] ILxUnknownID attr, [[maybe_unused]] unsigned index, [[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_ParticleItem_Prepare LxResult prti_Prepare([[maybe_unused]] ILxUnknownID eval, [[maybe_unused]] unsigned *index) override
#define LXxO_ParticleItem_Prepare LXxD_ParticleItem_Prepare
#define LXxC_ParticleItem_Prepare(c) LxResult c::prti_Prepare([[maybe_unused]] ILxUnknownID eval, [[maybe_unused]] unsigned *index)
#define LXxD_ParticleItem_Evaluate LxResult prti_Evaluate([[maybe_unused]] ILxUnknownID attr, [[maybe_unused]] unsigned index, [[maybe_unused]] void **ppvObj) override
#define LXxO_ParticleItem_Evaluate LXxD_ParticleItem_Evaluate
#define LXxC_ParticleItem_Evaluate(c) LxResult c::prti_Evaluate([[maybe_unused]] ILxUnknownID attr, [[maybe_unused]] unsigned index, [[maybe_unused]] void **ppvObj)

template <class T>
class CLxIfc_ParticleItem: public CLxInterface
{
public:
    CLxIfc_ParticleItem()
    {
        vt.Prepare = Prepare;
        vt.Evaluate = Evaluate;
        vTable = &vt.iunk;
        iid = &lx::guid_ParticleItem;
    }

    static auto Prepare(LXtObjectID wcom,LXtObjectID eval,unsigned *index) -> LxResult
    {
        LXCWxINST (CLxImpl_ParticleItem, loc);
        try
        {
           return loc->prti_Prepare((ILxUnknownID) eval, index);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Evaluate(LXtObjectID wcom,LXtObjectID attr,unsigned index,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_ParticleItem, loc);
        try
        {
           return loc->prti_Evaluate((ILxUnknownID) attr, index, ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxParticleItem vt;
};

class CLxLoc_ParticleItem : public CLxLocalize<ILxParticleItemID>
{
public:
    CLxLoc_ParticleItem()
    {
        _init();
    }

    CLxLoc_ParticleItem(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_ParticleItem(CLxLoc_ParticleItem const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_ParticleItem;
    }

    auto Prepare(ILxUnknownID eval, unsigned *index) -> LxResult
    {
        return m_loc[0]->Prepare(m_loc,(ILxUnknownID) eval, index);
    }

    auto Evaluate(ILxUnknownID attr, unsigned index, void **ppvObj) -> LxResult
    {
        return m_loc[0]->Evaluate(m_loc,(ILxUnknownID) attr, index, ppvObj);
    }

    auto Evaluate(ILxUnknownID attr, unsigned index, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Evaluate(m_loc,(ILxUnknownID) attr, index, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_ReplicatorEnumerator : public CLxLocalize<ILxReplicatorEnumeratorID>
{
public:
    CLxLoc_ReplicatorEnumerator()
    {
        _init();
    }

    CLxLoc_ReplicatorEnumerator(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_ReplicatorEnumerator(CLxLoc_ReplicatorEnumerator const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_ReplicatorEnumerator;
    }

    auto Enumerate(ILxUnknownID visitor, ILxUnknownID chan, int localXform) -> LxResult
    {
        return m_loc[0]->Enumerate(m_loc,(ILxUnknownID) visitor,(ILxUnknownID) chan, localXform);
    }

    auto Item(void **ppvObj) -> LxResult
    {
        return m_loc[0]->Item(m_loc, ppvObj);
    }

    auto Item(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Item(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Position(LXtVector pos) -> void
    {
        m_loc[0]->Position(m_loc, pos);
    }

    auto Orientation(LXtMatrix mx) -> void
    {
        m_loc[0]->Orientation(m_loc, mx);
    }

    auto Id(void) -> float
    {
        return m_loc[0]->Id(m_loc);
    }

    auto Dissolve(void) -> float
    {
        return m_loc[0]->Dissolve(m_loc);
    }

    auto GroupId(void) -> float
    {
        return m_loc[0]->GroupId(m_loc);
    }

    auto Geometry(void **ppvObj) -> LxResult
    {
        return m_loc[0]->Geometry(m_loc, ppvObj);
    }

    auto Geometry(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Geometry(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_ParticleEvalFrame : public CLxLocalize<ILxParticleEvalFrameID>
{
public:
    CLxLoc_ParticleEvalFrame()
    {
        _init();
    }

    CLxLoc_ParticleEvalFrame(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_ParticleEvalFrame(CLxLoc_ParticleEvalFrame const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_ParticleEvalFrame;
    }

    auto VertexDescription(void) -> ILxUnknownID
    {
        return (ILxUnknownID)m_loc[0]->VertexDescription(m_loc);
    }

    auto MaxCount(void) -> unsigned
    {
        return m_loc[0]->MaxCount(m_loc);
    }

    auto AliveCount(void) -> unsigned
    {
        return m_loc[0]->AliveCount(m_loc);
    }

    auto AddParticle(const float *state, unsigned *index) -> LxResult
    {
        return m_loc[0]->AddParticle(m_loc, state, index);
    }

    auto KillParticle(unsigned index) -> LxResult
    {
        return m_loc[0]->KillParticle(m_loc, index);
    }

    auto IsAlive(unsigned index) -> unsigned
    {
        return m_loc[0]->IsAlive(m_loc, index);
    }

    auto GetVector(unsigned index, float *vector) -> LxResult
    {
        return m_loc[0]->GetVector(m_loc, index, vector);
    }

    auto SetVector(unsigned index, const float *vector) -> LxResult
    {
        return m_loc[0]->SetVector(m_loc, index, vector);
    }

    auto AliveRun(unsigned first, const unsigned **alive, unsigned *count) -> LxResult
    {
        return m_loc[0]->AliveRun(m_loc, first, alive, count);
    }

    auto VectorRun(unsigned first, float **values, unsigned *count) -> LxResult
    {
        return m_loc[0]->VectorRun(m_loc, first, values, count);
    }

    auto Neighbors(LXtFVector pos, double maxDist, int maxCount, unsigned *index, double *dist, unsigned *count) -> LxResult
    {
        return m_loc[0]->Neighbors(m_loc, pos, maxDist, maxCount, index, dist, count);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_ParticleFilter
{
public:
    virtual ~CLxImpl_ParticleFilter() = default;

    virtual LXtObjectID pfilt_Vertex(ILxUnknownID full) = 0;

    virtual unsigned pfilt_Flags(void) = 0;

    virtual auto pfilt_Initialize([[maybe_unused]] ILxUnknownID vertex, [[maybe_unused]] ILxUnknownID frame, [[maybe_unused]] double time) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto pfilt_Step([[maybe_unused]] ILxUnknownID other, [[maybe_unused]] double dt) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual void pfilt_Cleanup([[maybe_unused]] void)
    {
    }

    virtual auto pfilt_Frame([[maybe_unused]] unsigned stage) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto pfilt_Run([[maybe_unused]] unsigned stage, [[maybe_unused]] float **values, [[maybe_unused]] const unsigned *alive, [[maybe_unused]] unsigned base, [[maybe_unused]] unsigned count) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto pfilt_Particle([[maybe_unused]] unsigned stage, [[maybe_unused]] float *vertex) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_ParticleFilter_Vertex LXtObjectID pfilt_Vertex([[maybe_unused]] ILxUnknownID full) override
#define LXxO_ParticleFilter_Vertex LXxD_ParticleFilter_Vertex
#define LXxC_ParticleFilter_Vertex(c) LXtObjectID c::pfilt_Vertex([[maybe_unused]] ILxUnknownID full)
#define LXxD_ParticleFilter_Flags unsigned pfilt_Flags() override
#define LXxO_ParticleFilter_Flags LXxD_ParticleFilter_Flags
#define LXxC_ParticleFilter_Flags(c) unsigned c::pfilt_Flags()
#define LXxD_ParticleFilter_Initialize LxResult pfilt_Initialize([[maybe_unused]] ILxUnknownID vertex, [[maybe_unused]] ILxUnknownID frame, [[maybe_unused]] double time) override
#define LXxO_ParticleFilter_Initialize LXxD_ParticleFilter_Initialize
#define LXxC_ParticleFilter_Initialize(c) LxResult c::pfilt_Initialize([[maybe_unused]] ILxUnknownID vertex, [[maybe_unused]] ILxUnknownID frame, [[maybe_unused]] double time)
#define LXxD_ParticleFilter_Step LxResult pfilt_Step([[maybe_unused]] ILxUnknownID other, [[maybe_unused]] double dt) override
#define LXxO_ParticleFilter_Step LXxD_ParticleFilter_Step
#define LXxC_ParticleFilter_Step(c) LxResult c::pfilt_Step([[maybe_unused]] ILxUnknownID other, [[maybe_unused]] double dt)
#define LXxD_ParticleFilter_Cleanup void pfilt_Cleanup() override
#define LXxO_ParticleFilter_Cleanup LXxD_ParticleFilter_Cleanup
#define LXxC_ParticleFilter_Cleanup(c) void c::pfilt_Cleanup()
#define LXxD_ParticleFilter_Frame LxResult pfilt_Frame([[maybe_unused]] unsigned stage) override
#define LXxO_ParticleFilter_Frame LXxD_ParticleFilter_Frame
#define LXxC_ParticleFilter_Frame(c) LxResult c::pfilt_Frame([[maybe_unused]] unsigned stage)
#define LXxD_ParticleFilter_Run LxResult pfilt_Run([[maybe_unused]] unsigned stage, [[maybe_unused]] float **values, [[maybe_unused]] const unsigned *alive, [[maybe_unused]] unsigned base, [[maybe_unused]] unsigned count) override
#define LXxO_ParticleFilter_Run LXxD_ParticleFilter_Run
#define LXxC_ParticleFilter_Run(c) LxResult c::pfilt_Run([[maybe_unused]] unsigned stage, [[maybe_unused]] float **values, [[maybe_unused]] const unsigned *alive, [[maybe_unused]] unsigned base, [[maybe_unused]] unsigned count)
#define LXxD_ParticleFilter_Particle LxResult pfilt_Particle([[maybe_unused]] unsigned stage, [[maybe_unused]] float *vertex) override
#define LXxO_ParticleFilter_Particle LXxD_ParticleFilter_Particle
#define LXxC_ParticleFilter_Particle(c) LxResult c::pfilt_Particle([[maybe_unused]] unsigned stage, [[maybe_unused]] float *vertex)

template <class T>
class CLxIfc_ParticleFilter: public CLxInterface
{
public:
    CLxIfc_ParticleFilter()
    {
        vt.Vertex = Vertex;
        vt.Flags = Flags;
        vt.Initialize = Initialize;
        vt.Step = Step;
        vt.Cleanup = Cleanup;
        vt.Frame = Frame;
        vt.Run = Run;
        vt.Particle = Particle;
        vTable = &vt.iunk;
        iid = &lx::guid_ParticleFilter;
    }

    static auto Vertex(LXtObjectID wcom,LXtObjectID full) -> LXtObjectID
    {
        LXCWxINST (CLxImpl_ParticleFilter, loc);
        return loc->pfilt_Vertex((ILxUnknownID) full);
    }

    static auto Flags(LXtObjectID wcom) -> unsigned
    {
        LXCWxINST (CLxImpl_ParticleFilter, loc);
        return loc->pfilt_Flags();
    }

    static auto Initialize(LXtObjectID wcom,LXtObjectID vertex,LXtObjectID frame,double time) -> LxResult
    {
        LXCWxINST (CLxImpl_ParticleFilter, loc);
        try
        {
           return loc->pfilt_Initialize((ILxUnknownID) vertex,(ILxUnknownID) frame, time);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Step(LXtObjectID wcom,LXtObjectID other,double dt) -> LxResult
    {
        LXCWxINST (CLxImpl_ParticleFilter, loc);
        try
        {
           return loc->pfilt_Step((ILxUnknownID) other, dt);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Cleanup(LXtObjectID wcom) -> void
    {
        LXCWxINST (CLxImpl_ParticleFilter, loc);
        loc->pfilt_Cleanup();
    }

    static auto Frame(LXtObjectID wcom,unsigned stage) -> LxResult
    {
        LXCWxINST (CLxImpl_ParticleFilter, loc);
        try
        {
           return loc->pfilt_Frame( stage);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Run(LXtObjectID wcom,unsigned stage,float **values,const unsigned *alive,unsigned base,unsigned count) -> LxResult
    {
        LXCWxINST (CLxImpl_ParticleFilter, loc);
        try
        {
           return loc->pfilt_Run( stage, values, alive, base, count);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Particle(LXtObjectID wcom,unsigned stage,float *vertex) -> LxResult
    {
        LXCWxINST (CLxImpl_ParticleFilter, loc);
        try
        {
           return loc->pfilt_Particle( stage, vertex);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxParticleFilter vt;
};

class CLxLoc_ParticleFilter : public CLxLocalize<ILxParticleFilterID>
{
public:
    CLxLoc_ParticleFilter()
    {
        _init();
    }

    CLxLoc_ParticleFilter(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_ParticleFilter(CLxLoc_ParticleFilter const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_ParticleFilter;
    }

    auto Vertex(ILxUnknownID full) -> ILxUnknownID
    {
        return (ILxUnknownID)m_loc[0]->Vertex(m_loc,(ILxUnknownID) full);
    }

    auto Flags(void) -> unsigned
    {
        return m_loc[0]->Flags(m_loc);
    }

    auto Initialize(ILxUnknownID vertex, ILxUnknownID frame, double time) -> LxResult
    {
        return m_loc[0]->Initialize(m_loc,(ILxUnknownID) vertex,(ILxUnknownID) frame, time);
    }

    auto Step(ILxUnknownID other, double dt) -> LxResult
    {
        return m_loc[0]->Step(m_loc,(ILxUnknownID) other, dt);
    }

    auto Cleanup(void) -> void
    {
        m_loc[0]->Cleanup(m_loc);
    }

    auto Frame(unsigned stage) -> LxResult
    {
        return m_loc[0]->Frame(m_loc, stage);
    }

    auto Run(unsigned stage, float **values, const unsigned *alive, unsigned base, unsigned count) -> LxResult
    {
        return m_loc[0]->Run(m_loc, stage, values, alive, base, count);
    }

    auto Particle(unsigned stage, float *vertex) -> LxResult
    {
        return m_loc[0]->Particle(m_loc, stage, vertex);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_ParticleCoOperator
{
public:
    virtual ~CLxImpl_ParticleCoOperator() = default;

    virtual auto pcoi_Initialize([[maybe_unused]] ILxUnknownID eval) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto pcoi_Cleanup([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto pcoi_Step([[maybe_unused]] double dT) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto pcoi_Particle([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_ParticleCoOperator_Initialize LxResult pcoi_Initialize([[maybe_unused]] ILxUnknownID eval) override
#define LXxO_ParticleCoOperator_Initialize LXxD_ParticleCoOperator_Initialize
#define LXxC_ParticleCoOperator_Initialize(c) LxResult c::pcoi_Initialize([[maybe_unused]] ILxUnknownID eval)
#define LXxD_ParticleCoOperator_Cleanup LxResult pcoi_Cleanup() override
#define LXxO_ParticleCoOperator_Cleanup LXxD_ParticleCoOperator_Cleanup
#define LXxC_ParticleCoOperator_Cleanup(c) LxResult c::pcoi_Cleanup()
#define LXxD_ParticleCoOperator_Step LxResult pcoi_Step([[maybe_unused]] double dT) override
#define LXxO_ParticleCoOperator_Step LXxD_ParticleCoOperator_Step
#define LXxC_ParticleCoOperator_Step(c) LxResult c::pcoi_Step([[maybe_unused]] double dT)
#define LXxD_ParticleCoOperator_Particle LxResult pcoi_Particle() override
#define LXxO_ParticleCoOperator_Particle LXxD_ParticleCoOperator_Particle
#define LXxC_ParticleCoOperator_Particle(c) LxResult c::pcoi_Particle()

template <class T>
class CLxIfc_ParticleCoOperator: public CLxInterface
{
public:
    CLxIfc_ParticleCoOperator()
    {
        vt.Initialize = Initialize;
        vt.Cleanup = Cleanup;
        vt.Step = Step;
        vt.Particle = Particle;
        vTable = &vt.iunk;
        iid = &lx::guid_ParticleCoOperator;
    }

    static auto Initialize(LXtObjectID wcom,LXtObjectID eval) -> LxResult
    {
        LXCWxINST (CLxImpl_ParticleCoOperator, loc);
        try
        {
           return loc->pcoi_Initialize((ILxUnknownID) eval);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Cleanup(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_ParticleCoOperator, loc);
        try
        {
           return loc->pcoi_Cleanup();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Step(LXtObjectID wcom,double dT) -> LxResult
    {
        LXCWxINST (CLxImpl_ParticleCoOperator, loc);
        try
        {
           return loc->pcoi_Step( dT);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Particle(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_ParticleCoOperator, loc);
        try
        {
           return loc->pcoi_Particle();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxParticleCoOperator vt;
};

class CLxLoc_ParticleCoOperator : public CLxLocalize<ILxParticleCoOperatorID>
{
public:
    CLxLoc_ParticleCoOperator()
    {
        _init();
    }

    CLxLoc_ParticleCoOperator(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_ParticleCoOperator(CLxLoc_ParticleCoOperator const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_ParticleCoOperator;
    }

    auto Initialize(ILxUnknownID eval) -> LxResult
    {
        return m_loc[0]->Initialize(m_loc,(ILxUnknownID) eval);
    }

    auto Cleanup(void) -> LxResult
    {
        return m_loc[0]->Cleanup(m_loc);
    }

    auto Step(double dT) -> LxResult
    {
        return m_loc[0]->Step(m_loc, dT);
    }

    auto Particle(void) -> LxResult
    {
        return m_loc[0]->Particle(m_loc);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_PointCacheItem
{
public:
    virtual ~CLxImpl_PointCacheItem() = default;

    virtual auto pcache_Prepare([[maybe_unused]] ILxUnknownID eval, [[maybe_unused]] unsigned *index) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto pcache_Initialize([[maybe_unused]] ILxUnknownID vdesc, [[maybe_unused]] ILxUnknownID attr, [[maybe_unused]] unsigned index, [[maybe_unused]] double time, [[maybe_unused]] double sample) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto pcache_SaveFrame([[maybe_unused]] ILxUnknownID pobj, [[maybe_unused]] double time) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto pcache_Cleanup([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_PointCacheItem_Prepare LxResult pcache_Prepare([[maybe_unused]] ILxUnknownID eval, [[maybe_unused]] unsigned *index) override
#define LXxO_PointCacheItem_Prepare LXxD_PointCacheItem_Prepare
#define LXxC_PointCacheItem_Prepare(c) LxResult c::pcache_Prepare([[maybe_unused]] ILxUnknownID eval, [[maybe_unused]] unsigned *index)
#define LXxD_PointCacheItem_Initialize LxResult pcache_Initialize([[maybe_unused]] ILxUnknownID vdesc, [[maybe_unused]] ILxUnknownID attr, [[maybe_unused]] unsigned index, [[maybe_unused]] double time, [[maybe_unused]] double sample) override
#define LXxO_PointCacheItem_Initialize LXxD_PointCacheItem_Initialize
#define LXxC_PointCacheItem_Initialize(c) LxResult c::pcache_Initialize([[maybe_unused]] ILxUnknownID vdesc, [[maybe_unused]] ILxUnknownID attr, [[maybe_unused]] unsigned index, [[maybe_unused]] double time, [[maybe_unused]] double sample)
#define LXxD_PointCacheItem_SaveFrame LxResult pcache_SaveFrame([[maybe_unused]] ILxUnknownID pobj, [[maybe_unused]] double time) override
#define LXxO_PointCacheItem_SaveFrame LXxD_PointCacheItem_SaveFrame
#define LXxC_PointCacheItem_SaveFrame(c) LxResult c::pcache_SaveFrame([[maybe_unused]] ILxUnknownID pobj, [[maybe_unused]] double time)
#define LXxD_PointCacheItem_Cleanup LxResult pcache_Cleanup() override
#define LXxO_PointCacheItem_Cleanup LXxD_PointCacheItem_Cleanup
#define LXxC_PointCacheItem_Cleanup(c) LxResult c::pcache_Cleanup()

template <class T>
class CLxIfc_PointCacheItem: public CLxInterface
{
public:
    CLxIfc_PointCacheItem()
    {
        vt.Prepare = Prepare;
        vt.Initialize = Initialize;
        vt.SaveFrame = SaveFrame;
        vt.Cleanup = Cleanup;
        vTable = &vt.iunk;
        iid = &lx::guid_PointCacheItem;
    }

    static auto Prepare(LXtObjectID wcom,LXtObjectID eval,unsigned *index) -> LxResult
    {
        LXCWxINST (CLxImpl_PointCacheItem, loc);
        try
        {
           return loc->pcache_Prepare((ILxUnknownID) eval, index);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Initialize(LXtObjectID wcom,LXtObjectID vdesc,LXtObjectID attr,unsigned index,double time,double sample) -> LxResult
    {
        LXCWxINST (CLxImpl_PointCacheItem, loc);
        try
        {
           return loc->pcache_Initialize((ILxUnknownID) vdesc,(ILxUnknownID) attr, index, time, sample);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SaveFrame(LXtObjectID wcom,LXtObjectID pobj,double time) -> LxResult
    {
        LXCWxINST (CLxImpl_PointCacheItem, loc);
        try
        {
           return loc->pcache_SaveFrame((ILxUnknownID) pobj, time);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Cleanup(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_PointCacheItem, loc);
        try
        {
           return loc->pcache_Cleanup();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxPointCacheItem vt;
};

class CLxLoc_PointCacheItem : public CLxLocalize<ILxPointCacheItemID>
{
public:
    CLxLoc_PointCacheItem()
    {
        _init();
    }

    CLxLoc_PointCacheItem(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_PointCacheItem(CLxLoc_PointCacheItem const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_PointCacheItem;
    }

    auto Prepare(ILxUnknownID eval, unsigned *index) -> LxResult
    {
        return m_loc[0]->Prepare(m_loc,(ILxUnknownID) eval, index);
    }

    auto Initialize(ILxUnknownID vdesc, ILxUnknownID attr, unsigned index, double time, double sample) -> LxResult
    {
        return m_loc[0]->Initialize(m_loc,(ILxUnknownID) vdesc,(ILxUnknownID) attr, index, time, sample);
    }

    auto SaveFrame(ILxUnknownID pobj, double time) -> LxResult
    {
        return m_loc[0]->SaveFrame(m_loc,(ILxUnknownID) pobj, time);
    }

    auto Cleanup(void) -> LxResult
    {
        return m_loc[0]->Cleanup(m_loc);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_ParticleService : public CLxLocalizedService
{
public:
    ILxParticleServiceID m_loc{ nullptr };

public:
    CLxLoc_ParticleService()
    {
        _init();
        set();
    }

    ~CLxLoc_ParticleService() = default;

    void set()
    {
        if (!m_loc)
        {
            m_loc = reinterpret_cast<ILxParticleServiceID>(lx::GetGlobal(&lx::guid_ParticleService));
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

    auto GetReplicatorEnumerator(ILxUnknownID replicatorItem, void **ppvObj) -> LxResult
    {
        return m_loc[0]->GetReplicatorEnumerator(m_loc,(ILxUnknownID) replicatorItem, ppvObj);
    }

    auto GetReplicatorEnumerator(ILxUnknownID replicatorItem, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->GetReplicatorEnumerator(m_loc,(ILxUnknownID) replicatorItem, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto EnumParticleFeatures(ILxUnknownID item, ILxUnknownID visitor) -> LxResult
    {
        return m_loc[0]->EnumParticleFeatures(m_loc,(ILxUnknownID) item,(ILxUnknownID) visitor);
    }

    auto FeatureIdent(const char **ident) -> LxResult
    {
        return m_loc[0]->FeatureIdent(m_loc, ident);
    }

    auto FeatureOffset(unsigned *offset) -> LxResult
    {
        return m_loc[0]->FeatureOffset(m_loc, offset);
    }

    auto TriGroupToParticle(ILxUnknownID triGroup, void **ppvObj) -> LxResult
    {
        return m_loc[0]->TriGroupToParticle(m_loc,(ILxUnknownID) triGroup, ppvObj);
    }

    auto TriGroupToParticle(ILxUnknownID triGroup, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->TriGroupToParticle(m_loc,(ILxUnknownID) triGroup, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto TriGroupBlend(ILxUnknownID triGroup0, ILxUnknownID triGroup1, double blend) -> LxResult
    {
        return m_loc[0]->TriGroupBlend(m_loc,(ILxUnknownID) triGroup0,(ILxUnknownID) triGroup1, blend);
    }

    auto EnumeratorPrepare(ILxUnknownID eval, ILxUnknownID replItem, unsigned *index) -> LxResult
    {
        return m_loc[0]->EnumeratorPrepare(m_loc,(ILxUnknownID) eval,(ILxUnknownID) replItem, index);
    }

    auto EnumeratorEvaluate(ILxUnknownID attr, unsigned index, void **ppvObj) -> LxResult
    {
        return m_loc[0]->EnumeratorEvaluate(m_loc,(ILxUnknownID) attr, index, ppvObj);
    }

    auto EnumeratorEvaluate(ILxUnknownID attr, unsigned index, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->EnumeratorEvaluate(m_loc,(ILxUnknownID) attr, index, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto ItemToParticle(ILxUnknownID item, ILxUnknownID chanRead, void **ppvObj) -> LxResult
    {
        return m_loc[0]->ItemToParticle(m_loc,(ILxUnknownID) item,(ILxUnknownID) chanRead, ppvObj);
    }

    auto ItemToParticle(ILxUnknownID item, ILxUnknownID chanRead, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->ItemToParticle(m_loc,(ILxUnknownID) item,(ILxUnknownID) chanRead, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
