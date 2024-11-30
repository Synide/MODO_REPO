//
// C++ wrapper for lxsdk/lxtoolui.h.
//
//	Copyright 2024.
//
//
#pragma once

#include <lxtoolui.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx
{
    static LXtGUID const guid_RaycastPacket = {0xB2973789, {0x447F, 0x45AA}, {0x98, 0xF3, 0x79, 0x48, 0x4A, 0x34, 0x80, 0xD8}};
    static LXtGUID const guid_RaycastPacket1 = {0xD622B573, {0x2638, 0x4A47}, {0xAD, 0x91, 0x6B, 0xC7, 0xA6, 0xD2, 0xD3, 0x0B}};
    static LXtGUID const guid_RaycastPacket2 = {0x4AC0C624, {0x15EE, 0x4BB1}, {0x91, 0xEB, 0xCD, 0xF9, 0x39, 0x5A, 0x91, 0x93}};
    static LXtGUID const guid_PaintBrushPacket = {0x9283C21E, {0x77FC, 0x402D}, {0xB2, 0x2A, 0x7B, 0x26, 0x28, 0x58, 0x88, 0xC4}};
    static LXtGUID const guid_PaintInkPacket = {0x340EE412, {0x232D, 0x4619}, {0x97, 0x4D, 0x7E, 0x59, 0xC7, 0xB3, 0x93, 0x53}};
    static LXtGUID const guid_PaintNozzlePacket = {0xF0BB49ED, {0x0BBB, 0x448a}, {0x83, 0x39, 0xF6, 0x9F, 0x78, 0xE9, 0x50, 0x48}};
    static LXtGUID const guid_ItemReplacement1 = {0x3C256C60, {0xDDE0, 0x4347}, {0x82, 0xBB, 0x10, 0xBF, 0x6E, 0x3A, 0xE8, 0x87}};
    static LXtGUID const guid_ItemReplacement = {0x2829760d, {0xfd93, 0x400e}, {0xaa, 0xc5, 0xf9, 0x8f, 0x1b, 0x9a, 0x15, 0x00}};
} // namespace lx

class CLxLoc_RaycastPacket : public CLxLocalize<ILxRaycastPacketID>
{
public:
    CLxLoc_RaycastPacket()
    {
        _init();
    }

    CLxLoc_RaycastPacket(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_RaycastPacket(CLxLoc_RaycastPacket const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_RaycastPacket;
    }

    auto HitPolygon(ILxUnknownID toolVector, unsigned layer, float x, float y, LXtHitPolygon *hit) -> int
    {
        return m_loc[0]->HitPolygon(m_loc,(ILxUnknownID) toolVector, layer, x, y, hit);
    }

    auto HitEdge(ILxUnknownID toolVector, unsigned layer, float x, float y, LXtHitEdge *hit) -> int
    {
        return m_loc[0]->HitEdge(m_loc,(ILxUnknownID) toolVector, layer, x, y, hit);
    }

    auto HitVertex(ILxUnknownID toolVector, unsigned layer, float x, float y, LXtHitVertex *hit) -> int
    {
        return m_loc[0]->HitVertex(m_loc,(ILxUnknownID) toolVector, layer, x, y, hit);
    }

    auto HitItem(ILxUnknownID toolVector, float x, float y, LXtHitItem *hit) -> int
    {
        return m_loc[0]->HitItem(m_loc,(ILxUnknownID) toolVector, x, y, hit);
    }

    auto HitPolygon1(ILxUnknownID toolVector, unsigned layer, float x, float y, LXtHitElement *hit) -> int
    {
        return m_loc[0]->HitPolygon1(m_loc,(ILxUnknownID) toolVector, layer, x, y, hit);
    }

    auto HitEdge1(ILxUnknownID toolVector, unsigned layer, float x, float y, LXtHitElement *hit) -> int
    {
        return m_loc[0]->HitEdge1(m_loc,(ILxUnknownID) toolVector, layer, x, y, hit);
    }

    auto HitVertex1(ILxUnknownID toolVector, unsigned layer, float x, float y, LXtHitElement *hit) -> int
    {
        return m_loc[0]->HitVertex1(m_loc,(ILxUnknownID) toolVector, layer, x, y, hit);
    }

    auto HitClosest(ILxUnknownID toolVector, unsigned layer, float x, float y, LXtHitElement *hit) -> int
    {
        return m_loc[0]->HitClosest(m_loc,(ILxUnknownID) toolVector, layer, x, y, hit);
    }

    auto HitCached(ILxUnknownID toolVector, LXtHitElement *hit) -> int
    {
        return m_loc[0]->HitCached(m_loc,(ILxUnknownID) toolVector, hit);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_RaycastPacket1 : public CLxLocalize<ILxRaycastPacket1ID>
{
public:
    CLxLoc_RaycastPacket1()
    {
        _init();
    }

    CLxLoc_RaycastPacket1(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_RaycastPacket1(CLxLoc_RaycastPacket1 const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_RaycastPacket1;
    }

    auto HitPolygon(ILxUnknownID toolVector, float x, float y, LXtHitPolygon *hit) -> int
    {
        return m_loc[0]->HitPolygon(m_loc,(ILxUnknownID) toolVector, x, y, hit);
    }

    auto HitEdge(ILxUnknownID toolVector, float x, float y, LXtHitEdge *hit) -> int
    {
        return m_loc[0]->HitEdge(m_loc,(ILxUnknownID) toolVector, x, y, hit);
    }

    auto HitVertex(ILxUnknownID toolVector, float x, float y, LXtHitVertex *hit) -> int
    {
        return m_loc[0]->HitVertex(m_loc,(ILxUnknownID) toolVector, x, y, hit);
    }

    auto HitItem(ILxUnknownID toolVector, float x, float y, LXtHitItem *hit) -> int
    {
        return m_loc[0]->HitItem(m_loc,(ILxUnknownID) toolVector, x, y, hit);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_RaycastPacket2 : public CLxLocalize<ILxRaycastPacket2ID>
{
public:
    CLxLoc_RaycastPacket2()
    {
        _init();
    }

    CLxLoc_RaycastPacket2(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_RaycastPacket2(CLxLoc_RaycastPacket2 const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_RaycastPacket2;
    }

    auto HitPolygon(ILxUnknownID toolVector, unsigned layer, float x, float y, LXtHitPolygon *hit) -> int
    {
        return m_loc[0]->HitPolygon(m_loc,(ILxUnknownID) toolVector, layer, x, y, hit);
    }

    auto HitEdge(ILxUnknownID toolVector, unsigned layer, float x, float y, LXtHitEdge *hit) -> int
    {
        return m_loc[0]->HitEdge(m_loc,(ILxUnknownID) toolVector, layer, x, y, hit);
    }

    auto HitVertex(ILxUnknownID toolVector, unsigned layer, float x, float y, LXtHitVertex *hit) -> int
    {
        return m_loc[0]->HitVertex(m_loc,(ILxUnknownID) toolVector, layer, x, y, hit);
    }

    auto HitItem(ILxUnknownID toolVector, float x, float y, LXtHitItem *hit) -> int
    {
        return m_loc[0]->HitItem(m_loc,(ILxUnknownID) toolVector, x, y, hit);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_PaintBrushPacket : public CLxLocalize<ILxPaintBrushPacketID>
{
public:
    CLxLoc_PaintBrushPacket()
    {
        _init();
    }

    CLxLoc_PaintBrushPacket(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_PaintBrushPacket(CLxLoc_PaintBrushPacket const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_PaintBrushPacket;
    }

    auto Flags(void) -> int
    {
        return m_loc[0]->Flags(m_loc);
    }

    auto Size(void) -> float
    {
        return m_loc[0]->Size(m_loc);
    }

    auto BBox(ILxUnknownID toolVector, const LXtVector center, double size, LXtBBox *bbox) -> int
    {
        return m_loc[0]->BBox(m_loc,(ILxUnknownID) toolVector, center, size, bbox);
    }

    auto Eval2D(ILxUnknownID toolVector, float multiplier, LXtPaintBrush *brush) -> int
    {
        return m_loc[0]->Eval2D(m_loc,(ILxUnknownID) toolVector, multiplier, brush);
    }

    auto Eval3D(ILxUnknownID toolVector, const LXtVector center, const LXtVector wpos, const LXtVector bpos, double rad, float *rgba) -> double
    {
        return m_loc[0]->Eval3D(m_loc,(ILxUnknownID) toolVector, center, wpos, bpos, rad, rgba);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_PaintInkPacket : public CLxLocalize<ILxPaintInkPacketID>
{
public:
    CLxLoc_PaintInkPacket()
    {
        _init();
    }

    CLxLoc_PaintInkPacket(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_PaintInkPacket(CLxLoc_PaintInkPacket const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_PaintInkPacket;
    }

    auto Flags(ILxUnknownID toolVector) -> int
    {
        return m_loc[0]->Flags(m_loc,(ILxUnknownID) toolVector);
    }

    auto Color(ILxUnknownID toolVector, int flags, LXtColorRGBA rgba) -> int
    {
        return m_loc[0]->Color(m_loc,(ILxUnknownID) toolVector, flags, rgba);
    }

    auto Stamp(LXtPaintBrush *brush) -> int
    {
        return m_loc[0]->Stamp(m_loc, brush);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_PaintNozzlePacket : public CLxLocalize<ILxPaintNozzlePacketID>
{
public:
    CLxLoc_PaintNozzlePacket()
    {
        _init();
    }

    CLxLoc_PaintNozzlePacket(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_PaintNozzlePacket(CLxLoc_PaintNozzlePacket const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_PaintNozzlePacket;
    }

    auto Paint(ILxUnknownID toolVector, float brushSize) -> int
    {
        return m_loc[0]->Paint(m_loc,(ILxUnknownID) toolVector, brushSize);
    }

    auto Jitter(ILxUnknownID toolVector, float brushSize, int *xj, int *yj) -> int
    {
        return m_loc[0]->Jitter(m_loc,(ILxUnknownID) toolVector, brushSize, xj, yj);
    }

    auto Nozzle(ILxUnknownID toolVector, float *strength, float *size, float *rotation) -> int
    {
        return m_loc[0]->Nozzle(m_loc,(ILxUnknownID) toolVector, strength, size, rotation);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_ItemReplacement1
{
public:
    virtual ~CLxImpl_ItemReplacement1() = default;

    virtual auto itemrep_ReplaceItems([[maybe_unused]] ILxUnknownID current, [[maybe_unused]] ILxUnknownID replacement) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto itemrep_Types([[maybe_unused]] const char *curType, [[maybe_unused]] const char **repTypes) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto itemrep_NotifierCount([[maybe_unused]] const char *itemType, [[maybe_unused]] const char *channelName, [[maybe_unused]] unsigned *count) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto itemrep_NotifierByIndex([[maybe_unused]] const char *itemType, [[maybe_unused]] const char *channelName, [[maybe_unused]] unsigned index, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_ItemReplacement1_ReplaceItems LxResult itemrep_ReplaceItems([[maybe_unused]] ILxUnknownID current, [[maybe_unused]] ILxUnknownID replacement) override
#define LXxO_ItemReplacement1_ReplaceItems LXxD_ItemReplacement1_ReplaceItems
#define LXxC_ItemReplacement1_ReplaceItems(c) LxResult c::itemrep_ReplaceItems([[maybe_unused]] ILxUnknownID current, [[maybe_unused]] ILxUnknownID replacement)
#define LXxD_ItemReplacement1_Types LxResult itemrep_Types([[maybe_unused]] const char *curType, [[maybe_unused]] const char **repTypes) override
#define LXxO_ItemReplacement1_Types LXxD_ItemReplacement1_Types
#define LXxC_ItemReplacement1_Types(c) LxResult c::itemrep_Types([[maybe_unused]] const char *curType, [[maybe_unused]] const char **repTypes)
#define LXxD_ItemReplacement1_NotifierCount LxResult itemrep_NotifierCount([[maybe_unused]] const char *itemType, [[maybe_unused]] const char *channelName, [[maybe_unused]] unsigned *count) override
#define LXxO_ItemReplacement1_NotifierCount LXxD_ItemReplacement1_NotifierCount
#define LXxC_ItemReplacement1_NotifierCount(c) LxResult c::itemrep_NotifierCount([[maybe_unused]] const char *itemType, [[maybe_unused]] const char *channelName, [[maybe_unused]] unsigned *count)
#define LXxD_ItemReplacement1_NotifierByIndex LxResult itemrep_NotifierByIndex([[maybe_unused]] const char *itemType, [[maybe_unused]] const char *channelName, [[maybe_unused]] unsigned index, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len) override
#define LXxO_ItemReplacement1_NotifierByIndex LXxD_ItemReplacement1_NotifierByIndex
#define LXxC_ItemReplacement1_NotifierByIndex(c) LxResult c::itemrep_NotifierByIndex([[maybe_unused]] const char *itemType, [[maybe_unused]] const char *channelName, [[maybe_unused]] unsigned index, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len)

template <class T>
class CLxIfc_ItemReplacement1: public CLxInterface
{
public:
    CLxIfc_ItemReplacement1()
    {
        vt.ReplaceItems = ReplaceItems;
        vt.Types = Types;
        vt.NotifierCount = NotifierCount;
        vt.NotifierByIndex = NotifierByIndex;
        vTable = &vt.iunk;
        iid = &lx::guid_ItemReplacement1;
    }

    static auto ReplaceItems(LXtObjectID wcom,LXtObjectID current,LXtObjectID replacement) -> LxResult
    {
        LXCWxINST (CLxImpl_ItemReplacement1, loc);
        try
        {
           return loc->itemrep_ReplaceItems((ILxUnknownID) current,(ILxUnknownID) replacement);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Types(LXtObjectID wcom,const char *curType,const char **repTypes) -> LxResult
    {
        LXCWxINST (CLxImpl_ItemReplacement1, loc);
        try
        {
           return loc->itemrep_Types( curType, repTypes);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto NotifierCount(LXtObjectID wcom,const char *itemType,const char *channelName,unsigned *count) -> LxResult
    {
        LXCWxINST (CLxImpl_ItemReplacement1, loc);
        try
        {
           return loc->itemrep_NotifierCount( itemType, channelName, count);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto NotifierByIndex(LXtObjectID wcom,const char *itemType,const char *channelName,unsigned index,char *buf,unsigned len) -> LxResult
    {
        LXCWxINST (CLxImpl_ItemReplacement1, loc);
        try
        {
           return loc->itemrep_NotifierByIndex( itemType, channelName, index, buf, len);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxItemReplacement1 vt;
};

class CLxLoc_ItemReplacement1 : public CLxLocalize<ILxItemReplacement1ID>
{
public:
    CLxLoc_ItemReplacement1()
    {
        _init();
    }

    CLxLoc_ItemReplacement1(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_ItemReplacement1(CLxLoc_ItemReplacement1 const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_ItemReplacement1;
    }

    auto ReplaceItems(ILxUnknownID current, ILxUnknownID replacement) -> LxResult
    {
        return m_loc[0]->ReplaceItems(m_loc,(ILxUnknownID) current,(ILxUnknownID) replacement);
    }

    auto Types(const char *curType, const char **repTypes) -> LxResult
    {
        return m_loc[0]->Types(m_loc, curType, repTypes);
    }

    auto NotifierCount(const char *itemType, const char *channelName, unsigned *count) -> LxResult
    {
        return m_loc[0]->NotifierCount(m_loc, itemType, channelName, count);
    }

    auto NotifierByIndex(const char *itemType, const char *channelName, unsigned index, char *buf, unsigned len) -> LxResult
    {
        return m_loc[0]->NotifierByIndex(m_loc, itemType, channelName, index, buf, len);
    }

    auto NotifierByIndex(const char *itemType, const char *channelName, unsigned index, std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->NotifierByIndex(m_loc, itemType, channelName, index, buf, len);
        LXWx_SBUF2
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_ItemReplacement
{
public:
    virtual ~CLxImpl_ItemReplacement() = default;

    virtual auto itemrep_ReplaceItems([[maybe_unused]] ILxUnknownID current, [[maybe_unused]] ILxUnknownID replacement, [[maybe_unused]] int targetType) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto itemrep_Types([[maybe_unused]] const char *curType, [[maybe_unused]] const char **repTypes) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto itemrep_NotifierCount([[maybe_unused]] const char *itemType, [[maybe_unused]] const char *channelName, [[maybe_unused]] unsigned *count) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto itemrep_NotifierByIndex([[maybe_unused]] const char *itemType, [[maybe_unused]] const char *channelName, [[maybe_unused]] unsigned index, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_ItemReplacement_ReplaceItems LxResult itemrep_ReplaceItems([[maybe_unused]] ILxUnknownID current, [[maybe_unused]] ILxUnknownID replacement, [[maybe_unused]] int targetType) override
#define LXxO_ItemReplacement_ReplaceItems LXxD_ItemReplacement_ReplaceItems
#define LXxC_ItemReplacement_ReplaceItems(c) LxResult c::itemrep_ReplaceItems([[maybe_unused]] ILxUnknownID current, [[maybe_unused]] ILxUnknownID replacement, [[maybe_unused]] int targetType)
#define LXxD_ItemReplacement_Types LxResult itemrep_Types([[maybe_unused]] const char *curType, [[maybe_unused]] const char **repTypes) override
#define LXxO_ItemReplacement_Types LXxD_ItemReplacement_Types
#define LXxC_ItemReplacement_Types(c) LxResult c::itemrep_Types([[maybe_unused]] const char *curType, [[maybe_unused]] const char **repTypes)
#define LXxD_ItemReplacement_NotifierCount LxResult itemrep_NotifierCount([[maybe_unused]] const char *itemType, [[maybe_unused]] const char *channelName, [[maybe_unused]] unsigned *count) override
#define LXxO_ItemReplacement_NotifierCount LXxD_ItemReplacement_NotifierCount
#define LXxC_ItemReplacement_NotifierCount(c) LxResult c::itemrep_NotifierCount([[maybe_unused]] const char *itemType, [[maybe_unused]] const char *channelName, [[maybe_unused]] unsigned *count)
#define LXxD_ItemReplacement_NotifierByIndex LxResult itemrep_NotifierByIndex([[maybe_unused]] const char *itemType, [[maybe_unused]] const char *channelName, [[maybe_unused]] unsigned index, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len) override
#define LXxO_ItemReplacement_NotifierByIndex LXxD_ItemReplacement_NotifierByIndex
#define LXxC_ItemReplacement_NotifierByIndex(c) LxResult c::itemrep_NotifierByIndex([[maybe_unused]] const char *itemType, [[maybe_unused]] const char *channelName, [[maybe_unused]] unsigned index, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len)

template <class T>
class CLxIfc_ItemReplacement: public CLxInterface
{
public:
    CLxIfc_ItemReplacement()
    {
        vt.ReplaceItems = ReplaceItems;
        vt.Types = Types;
        vt.NotifierCount = NotifierCount;
        vt.NotifierByIndex = NotifierByIndex;
        vTable = &vt.iunk;
        iid = &lx::guid_ItemReplacement;
    }

    static auto ReplaceItems(LXtObjectID wcom,LXtObjectID current,LXtObjectID replacement,int targetType) -> LxResult
    {
        LXCWxINST (CLxImpl_ItemReplacement, loc);
        try
        {
           return loc->itemrep_ReplaceItems((ILxUnknownID) current,(ILxUnknownID) replacement, targetType);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Types(LXtObjectID wcom,const char *curType,const char **repTypes) -> LxResult
    {
        LXCWxINST (CLxImpl_ItemReplacement, loc);
        try
        {
           return loc->itemrep_Types( curType, repTypes);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto NotifierCount(LXtObjectID wcom,const char *itemType,const char *channelName,unsigned *count) -> LxResult
    {
        LXCWxINST (CLxImpl_ItemReplacement, loc);
        try
        {
           return loc->itemrep_NotifierCount( itemType, channelName, count);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto NotifierByIndex(LXtObjectID wcom,const char *itemType,const char *channelName,unsigned index,char *buf,unsigned len) -> LxResult
    {
        LXCWxINST (CLxImpl_ItemReplacement, loc);
        try
        {
           return loc->itemrep_NotifierByIndex( itemType, channelName, index, buf, len);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxItemReplacement vt;
};

class CLxLoc_ItemReplacement : public CLxLocalize<ILxItemReplacementID>
{
public:
    CLxLoc_ItemReplacement()
    {
        _init();
    }

    CLxLoc_ItemReplacement(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_ItemReplacement(CLxLoc_ItemReplacement const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_ItemReplacement;
    }

    auto ReplaceItems(ILxUnknownID current, ILxUnknownID replacement, int targetType) -> LxResult
    {
        return m_loc[0]->ReplaceItems(m_loc,(ILxUnknownID) current,(ILxUnknownID) replacement, targetType);
    }

    auto Types(const char *curType, const char **repTypes) -> LxResult
    {
        return m_loc[0]->Types(m_loc, curType, repTypes);
    }

    auto NotifierCount(const char *itemType, const char *channelName, unsigned *count) -> LxResult
    {
        return m_loc[0]->NotifierCount(m_loc, itemType, channelName, count);
    }

    auto NotifierByIndex(const char *itemType, const char *channelName, unsigned index, char *buf, unsigned len) -> LxResult
    {
        return m_loc[0]->NotifierByIndex(m_loc, itemType, channelName, index, buf, len);
    }

    auto NotifierByIndex(const char *itemType, const char *channelName, unsigned index, std::string &result) -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->NotifierByIndex(m_loc, itemType, channelName, index, buf, len);
        LXWx_SBUF2
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
