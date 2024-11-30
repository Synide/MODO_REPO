//
// C++ wrapper for lxsdk/lxseltypes.h.
//
//	Copyright 2024.
//
//
#pragma once

#include <lxseltypes.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx
{
    static LXtGUID const guid_ScenePacketTranslation = {0xA63F8E08, {0x94D8, 0x11D9}, {0x96, 0xD3, 0x00, 0x0A, 0x95, 0x6C, 0x2E, 0x10}};
    static LXtGUID const guid_ItemPacketTranslation = {0x029663CC, {0x9571, 0x11D9}, {0xB9, 0xAD, 0x00, 0x0A, 0x95, 0x6C, 0x2E, 0x10}};
    static LXtGUID const guid_NodePacketTranslation = {0x5A560F1B, {0xDC73, 0x4efb}, {0x85, 0x79, 0xC6, 0xC7, 0xD9, 0x37, 0x3C, 0x60}};
    static LXtGUID const guid_ChannelPacketTranslation = {0x00DE9D39, {0x6A83, 0x46DC}, {0x9C, 0x28, 0x36, 0x06, 0x62, 0x92, 0x2C, 0xE5}};
    static LXtGUID const guid_CenterPacketTranslation = {0x52B10EAB, {0x9EA6, 0x4F28}, {0x81, 0xD1, 0x2F, 0xEC, 0x51, 0xE0, 0x29, 0x33}};
    static LXtGUID const guid_PivotPacketTranslation = {0x9744D68E, {0xD6CD, 0x4652}, {0xAD, 0x33, 0x07, 0x3A, 0x24, 0xE1, 0x69, 0x01}};
    static LXtGUID const guid_LinkPacketTranslation = {0xEEA9F625, {0xEB3C, 0x43FD}, {0xA1, 0x56, 0xC8, 0x55, 0x2D, 0x6D, 0x18, 0xC9}};
    static LXtGUID const guid_ActionLayerPacketTranslation = {0xE685D569, {0x1C0F, 0x4E8A}, {0x94, 0xA9, 0x4F, 0xC2, 0x94, 0x53, 0x68, 0x9F}};
    static LXtGUID const guid_VertexPacketTranslation = {0xD77B8382, {0x9572, 0x11D9}, {0xAF, 0xDE, 0x00, 0x0A, 0x95, 0x6C, 0x2E, 0x10}};
    static LXtGUID const guid_EdgePacketTranslation = {0xCA4DFE14, {0x957E, 0x11D9}, {0xAC, 0x64, 0x00, 0x0A, 0x95, 0x6C, 0x2E, 0x10}};
    static LXtGUID const guid_PolygonPacketTranslation = {0x2E0929DC, {0x9583, 0x11D9}, {0xB0, 0x58, 0x00, 0x0A, 0x95, 0x6C, 0x2E, 0x10}};
    static LXtGUID const guid_VMapPacketTranslation = {0xBBCB6B90, {0x9586, 0x11D9}, {0xA3, 0xB8, 0x00, 0x0A, 0x95, 0x6C, 0x2E, 0x10}};
    static LXtGUID const guid_PresetPathPacketTranslation = {0x6b95c2ac, {0x9a9e, 0x471f}, {0x97, 0x71, 0xcf, 0x10, 0xfd, 0x5c, 0x6b, 0xcb}};
    static LXtGUID const guid_ItemChannel = {0x3cfab0aa, {0x8e8c, 0x452c}, {0x81, 0xe5, 0x27, 0x28, 0x42, 0xff, 0xf9, 0x35}};
    static LXtGUID const guid_VectorShapePacketTranslation = {0x33C886D1, {0x1574, 0x4D8E}, {0x9D, 0xFD, 0xD8, 0xD1, 0xCB, 0x7A, 0x21, 0xFE}};
    static LXtGUID const guid_VectorPathPacketTranslation = {0xC3E6DF29, {0x7217, 0x4D89}, {0x9E, 0x84, 0xDA, 0x6D, 0x45, 0xB9, 0x39, 0x6E}};
    static LXtGUID const guid_VectorKnotPacketTranslation = {0xF4DDFFEA, {0x3077, 0x4931}, {0x83, 0x84, 0x81, 0xC4, 0x9A, 0xD1, 0xC4, 0x1C}};
    static LXtGUID const guid_RenderSlotPacketTranslation = {0xd6e1af16, {0xe8be, 0x4be2}, {0xa4, 0xcf, 0x48, 0x49, 0xa6, 0x7e, 0x5d, 0x9c}};
} // namespace lx

class CLxLoc_ScenePacketTranslation : public CLxLocalize<ILxScenePacketTranslationID>
{
public:
    CLxLoc_ScenePacketTranslation()
    {
        _init();
    }

    CLxLoc_ScenePacketTranslation(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_ScenePacketTranslation(CLxLoc_ScenePacketTranslation const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_ScenePacketTranslation;
    }

    auto Scene(void *packet, void **ppvObj) -> LxResult
    {
        return m_loc[0]->Scene(m_loc, packet, ppvObj);
    }

    auto Scene(void *packet, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Scene(m_loc, packet, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Packet(ILxUnknownID scene) -> void *
    {
        return m_loc[0]->Packet(m_loc,(ILxUnknownID) scene);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_ItemPacketTranslation : public CLxLocalize<ILxItemPacketTranslationID>
{
public:
    CLxLoc_ItemPacketTranslation()
    {
        _init();
    }

    CLxLoc_ItemPacketTranslation(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_ItemPacketTranslation(CLxLoc_ItemPacketTranslation const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_ItemPacketTranslation;
    }

    auto Item(void *packet, void **ppvObj) -> LxResult
    {
        return m_loc[0]->Item(m_loc, packet, ppvObj);
    }

    auto Item(void *packet, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Item(m_loc, packet, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Packet(ILxUnknownID item) -> void *
    {
        return m_loc[0]->Packet(m_loc,(ILxUnknownID) item);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_NodePacketTranslation : public CLxLocalize<ILxNodePacketTranslationID>
{
public:
    CLxLoc_NodePacketTranslation()
    {
        _init();
    }

    CLxLoc_NodePacketTranslation(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_NodePacketTranslation(CLxLoc_NodePacketTranslation const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_NodePacketTranslation;
    }

    auto Node(void *packet, void **ppvObj) -> LxResult
    {
        return m_loc[0]->Node(m_loc, packet, ppvObj);
    }

    auto Node(void *packet, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Node(m_loc, packet, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Packet(ILxUnknownID node) -> void *
    {
        return m_loc[0]->Packet(m_loc,(ILxUnknownID) node);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_ChannelPacketTranslation : public CLxLocalize<ILxChannelPacketTranslationID>
{
public:
    CLxLoc_ChannelPacketTranslation()
    {
        _init();
    }

    CLxLoc_ChannelPacketTranslation(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_ChannelPacketTranslation(CLxLoc_ChannelPacketTranslation const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_ChannelPacketTranslation;
    }

    auto Item(void *packet, void **ppvObj) -> LxResult
    {
        return m_loc[0]->Item(m_loc, packet, ppvObj);
    }

    auto Item(void *packet, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Item(m_loc, packet, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Index(void *packet) -> unsigned int
    {
        return m_loc[0]->Index(m_loc, packet);
    }

    auto Packet(ILxUnknownID item, unsigned int index) -> void *
    {
        return m_loc[0]->Packet(m_loc,(ILxUnknownID) item, index);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_CenterPacketTranslation : public CLxLocalize<ILxCenterPacketTranslationID>
{
public:
    CLxLoc_CenterPacketTranslation()
    {
        _init();
    }

    CLxLoc_CenterPacketTranslation(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_CenterPacketTranslation(CLxLoc_CenterPacketTranslation const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_CenterPacketTranslation;
    }

    auto Item(void *packet, void **ppvObj) -> LxResult
    {
        return m_loc[0]->Item(m_loc, packet, ppvObj);
    }

    auto Item(void *packet, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Item(m_loc, packet, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Packet(ILxUnknownID item) -> void *
    {
        return m_loc[0]->Packet(m_loc,(ILxUnknownID) item);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_PivotPacketTranslation : public CLxLocalize<ILxPivotPacketTranslationID>
{
public:
    CLxLoc_PivotPacketTranslation()
    {
        _init();
    }

    CLxLoc_PivotPacketTranslation(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_PivotPacketTranslation(CLxLoc_PivotPacketTranslation const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_PivotPacketTranslation;
    }

    auto Item(void *packet, void **ppvObj) -> LxResult
    {
        return m_loc[0]->Item(m_loc, packet, ppvObj);
    }

    auto Item(void *packet, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Item(m_loc, packet, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Type(void *packet) -> unsigned int
    {
        return m_loc[0]->Type(m_loc, packet);
    }

    auto Packet(ILxUnknownID item, unsigned int type) -> void *
    {
        return m_loc[0]->Packet(m_loc,(ILxUnknownID) item, type);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_LinkPacketTranslation : public CLxLocalize<ILxLinkPacketTranslationID>
{
public:
    CLxLoc_LinkPacketTranslation()
    {
        _init();
    }

    CLxLoc_LinkPacketTranslation(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_LinkPacketTranslation(CLxLoc_LinkPacketTranslation const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_LinkPacketTranslation;
    }

    auto From(void *packet, int *channel, void **ppvObj) -> LxResult
    {
        return m_loc[0]->From(m_loc, packet, channel, ppvObj);
    }

    auto From(void *packet, int *channel, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->From(m_loc, packet, channel, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto To(void *packet, int *channel, void **ppvObj) -> LxResult
    {
        return m_loc[0]->To(m_loc, packet, channel, ppvObj);
    }

    auto To(void *packet, int *channel, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->To(m_loc, packet, channel, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Packet(ILxUnknownID fromItem, int fromChannel, ILxUnknownID toItem, int toChannel) -> void *
    {
        return m_loc[0]->Packet(m_loc,(ILxUnknownID) fromItem, fromChannel,(ILxUnknownID) toItem, toChannel);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_ActionLayerPacketTranslation : public CLxLocalize<ILxActionLayerPacketTranslationID>
{
public:
    CLxLoc_ActionLayerPacketTranslation()
    {
        _init();
    }

    CLxLoc_ActionLayerPacketTranslation(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_ActionLayerPacketTranslation(CLxLoc_ActionLayerPacketTranslation const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_ActionLayerPacketTranslation;
    }

    auto Item(void *packet, void **ppvObj) -> LxResult
    {
        return m_loc[0]->Item(m_loc, packet, ppvObj);
    }

    auto Item(void *packet, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Item(m_loc, packet, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Index(void *packet) -> unsigned int
    {
        return m_loc[0]->Index(m_loc, packet);
    }

    auto Packet(ILxUnknownID item, unsigned int index) -> void *
    {
        return m_loc[0]->Packet(m_loc,(ILxUnknownID) item, index);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_VertexPacketTranslation : public CLxLocalize<ILxVertexPacketTranslationID>
{
public:
    CLxLoc_VertexPacketTranslation()
    {
        _init();
    }

    CLxLoc_VertexPacketTranslation(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_VertexPacketTranslation(CLxLoc_VertexPacketTranslation const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_VertexPacketTranslation;
    }

    auto Vertex(void *packet, LXtPointID *vertex) -> LxResult
    {
        return m_loc[0]->Vertex(m_loc, packet, vertex);
    }

    auto Polygon(void *packet, LXtPolygonID *polygon) -> LxResult
    {
        return m_loc[0]->Polygon(m_loc, packet, polygon);
    }

    auto Mesh(void *packet, void **ppvObj) -> LxResult
    {
        return m_loc[0]->Mesh(m_loc, packet, ppvObj);
    }

    auto Mesh(void *packet, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Mesh(m_loc, packet, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Packet(LXtPointID vertex, LXtPolygonID polygon, ILxUnknownID mesh) -> void *
    {
        return m_loc[0]->Packet(m_loc, vertex, polygon,(ILxUnknownID) mesh);
    }

    auto Item(void *packet, void **ppvObj) -> LxResult
    {
        return m_loc[0]->Item(m_loc, packet, ppvObj);
    }

    auto Item(void *packet, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Item(m_loc, packet, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_EdgePacketTranslation : public CLxLocalize<ILxEdgePacketTranslationID>
{
public:
    CLxLoc_EdgePacketTranslation()
    {
        _init();
    }

    CLxLoc_EdgePacketTranslation(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_EdgePacketTranslation(CLxLoc_EdgePacketTranslation const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_EdgePacketTranslation;
    }

    auto Vertices(void *packet, LXtPointID *vertexA, LXtPointID *vertexB) -> LxResult
    {
        return m_loc[0]->Vertices(m_loc, packet, vertexA, vertexB);
    }

    auto Polygon(void *packet, LXtPolygonID *polygon) -> LxResult
    {
        return m_loc[0]->Polygon(m_loc, packet, polygon);
    }

    auto Mesh(void *packet, void **ppvObj) -> LxResult
    {
        return m_loc[0]->Mesh(m_loc, packet, ppvObj);
    }

    auto Mesh(void *packet, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Mesh(m_loc, packet, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Packet(LXtPointID vertexA, LXtPointID vertexB, LXtPolygonID polygon, ILxUnknownID mesh) -> void *
    {
        return m_loc[0]->Packet(m_loc, vertexA, vertexB, polygon,(ILxUnknownID) mesh);
    }

    auto Item(void *packet, void **ppvObj) -> LxResult
    {
        return m_loc[0]->Item(m_loc, packet, ppvObj);
    }

    auto Item(void *packet, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Item(m_loc, packet, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_PolygonPacketTranslation : public CLxLocalize<ILxPolygonPacketTranslationID>
{
public:
    CLxLoc_PolygonPacketTranslation()
    {
        _init();
    }

    CLxLoc_PolygonPacketTranslation(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_PolygonPacketTranslation(CLxLoc_PolygonPacketTranslation const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_PolygonPacketTranslation;
    }

    auto Polygon(void *packet, LXtPolygonID *polygon) -> LxResult
    {
        return m_loc[0]->Polygon(m_loc, packet, polygon);
    }

    auto Mesh(void *packet, void **ppvObj) -> LxResult
    {
        return m_loc[0]->Mesh(m_loc, packet, ppvObj);
    }

    auto Mesh(void *packet, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Mesh(m_loc, packet, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Packet(LXtPolygonID polygon, ILxUnknownID mesh) -> void *
    {
        return m_loc[0]->Packet(m_loc, polygon,(ILxUnknownID) mesh);
    }

    auto Item(void *packet, void **ppvObj) -> LxResult
    {
        return m_loc[0]->Item(m_loc, packet, ppvObj);
    }

    auto Item(void *packet, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Item(m_loc, packet, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_VMapPacketTranslation : public CLxLocalize<ILxVMapPacketTranslationID>
{
public:
    CLxLoc_VMapPacketTranslation()
    {
        _init();
    }

    CLxLoc_VMapPacketTranslation(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_VMapPacketTranslation(CLxLoc_VMapPacketTranslation const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_VMapPacketTranslation;
    }

    auto Name(void *packet, const char **name) -> LxResult
    {
        return m_loc[0]->Name(m_loc, packet, name);
    }

    auto Type(void *packet, LXtID4 *type) -> LxResult
    {
        return m_loc[0]->Type(m_loc, packet, type);
    }

    auto Packet(LXtID4 type, const char *name) -> void *
    {
        return m_loc[0]->Packet(m_loc, type, name);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_PresetPathPacketTranslation : public CLxLocalize<ILxPresetPathPacketTranslationID>
{
public:
    CLxLoc_PresetPathPacketTranslation()
    {
        _init();
    }

    CLxLoc_PresetPathPacketTranslation(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_PresetPathPacketTranslation(CLxLoc_PresetPathPacketTranslation const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_PresetPathPacketTranslation;
    }

    auto Path(void *packet, const char **path) -> LxResult
    {
        return m_loc[0]->Path(m_loc, packet, path);
    }

    auto Identifier(void *packet, const char **identifier) -> LxResult
    {
        return m_loc[0]->Identifier(m_loc, packet, identifier);
    }

    auto Packet(const char *path, const char *identifier) -> void *
    {
        return m_loc[0]->Packet(m_loc, path, identifier);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_ItemChannel : public CLxLocalize<ILxItemChannelID>
{
public:
    CLxLoc_ItemChannel()
    {
        _init();
    }

    CLxLoc_ItemChannel(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_ItemChannel(CLxLoc_ItemChannel const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_ItemChannel;
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

    auto ChannelIndex(void) -> unsigned int
    {
        return m_loc[0]->ChannelIndex(m_loc);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_VectorShapePacketTranslation
{
public:
    virtual ~CLxImpl_VectorShapePacketTranslation() = default;

    virtual auto shapetrans_Shape([[maybe_unused]] void *packet, [[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto shapetrans_Canvas([[maybe_unused]] void *packet, [[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto shapetrans_Item([[maybe_unused]] void *packet, [[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual void * shapetrans_Packet(ILxUnknownID shape) = 0;
};

#define LXxD_VectorShapePacketTranslation_Shape LxResult shapetrans_Shape([[maybe_unused]] void *packet, [[maybe_unused]] void **ppvObj) override
#define LXxO_VectorShapePacketTranslation_Shape LXxD_VectorShapePacketTranslation_Shape
#define LXxC_VectorShapePacketTranslation_Shape(c) LxResult c::shapetrans_Shape([[maybe_unused]] void *packet, [[maybe_unused]] void **ppvObj)
#define LXxD_VectorShapePacketTranslation_Canvas LxResult shapetrans_Canvas([[maybe_unused]] void *packet, [[maybe_unused]] void **ppvObj) override
#define LXxO_VectorShapePacketTranslation_Canvas LXxD_VectorShapePacketTranslation_Canvas
#define LXxC_VectorShapePacketTranslation_Canvas(c) LxResult c::shapetrans_Canvas([[maybe_unused]] void *packet, [[maybe_unused]] void **ppvObj)
#define LXxD_VectorShapePacketTranslation_Item LxResult shapetrans_Item([[maybe_unused]] void *packet, [[maybe_unused]] void **ppvObj) override
#define LXxO_VectorShapePacketTranslation_Item LXxD_VectorShapePacketTranslation_Item
#define LXxC_VectorShapePacketTranslation_Item(c) LxResult c::shapetrans_Item([[maybe_unused]] void *packet, [[maybe_unused]] void **ppvObj)
#define LXxD_VectorShapePacketTranslation_Packet void * shapetrans_Packet([[maybe_unused]] ILxUnknownID shape) override
#define LXxO_VectorShapePacketTranslation_Packet LXxD_VectorShapePacketTranslation_Packet
#define LXxC_VectorShapePacketTranslation_Packet(c) void * c::shapetrans_Packet([[maybe_unused]] ILxUnknownID shape)

template <class T>
class CLxIfc_VectorShapePacketTranslation: public CLxInterface
{
public:
    CLxIfc_VectorShapePacketTranslation()
    {
        vt.Shape = Shape;
        vt.Canvas = Canvas;
        vt.Item = Item;
        vt.Packet = Packet;
        vTable = &vt.iunk;
        iid = &lx::guid_VectorShapePacketTranslation;
    }

    static auto Shape(LXtObjectID wcom,void *packet,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_VectorShapePacketTranslation, loc);
        try
        {
           return loc->shapetrans_Shape( packet, ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Canvas(LXtObjectID wcom,void *packet,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_VectorShapePacketTranslation, loc);
        try
        {
           return loc->shapetrans_Canvas( packet, ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Item(LXtObjectID wcom,void *packet,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_VectorShapePacketTranslation, loc);
        try
        {
           return loc->shapetrans_Item( packet, ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Packet(LXtObjectID wcom,LXtObjectID shape) -> void *
    {
        LXCWxINST (CLxImpl_VectorShapePacketTranslation, loc);
        return loc->shapetrans_Packet((ILxUnknownID) shape);
    }

private:
    ILxVectorShapePacketTranslation vt;
};

class CLxLoc_VectorShapePacketTranslation : public CLxLocalize<ILxVectorShapePacketTranslationID>
{
public:
    CLxLoc_VectorShapePacketTranslation()
    {
        _init();
    }

    CLxLoc_VectorShapePacketTranslation(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_VectorShapePacketTranslation(CLxLoc_VectorShapePacketTranslation const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_VectorShapePacketTranslation;
    }

    auto Shape(void *packet, void **ppvObj) -> LxResult
    {
        return m_loc[0]->Shape(m_loc, packet, ppvObj);
    }

    auto Shape(void *packet, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Shape(m_loc, packet, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Canvas(void *packet, void **ppvObj) -> LxResult
    {
        return m_loc[0]->Canvas(m_loc, packet, ppvObj);
    }

    auto Canvas(void *packet, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Canvas(m_loc, packet, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Item(void *packet, void **ppvObj) -> LxResult
    {
        return m_loc[0]->Item(m_loc, packet, ppvObj);
    }

    auto Item(void *packet, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Item(m_loc, packet, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Packet(ILxUnknownID shape) -> void *
    {
        return m_loc[0]->Packet(m_loc,(ILxUnknownID) shape);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_VectorPathPacketTranslation
{
public:
    virtual ~CLxImpl_VectorPathPacketTranslation() = default;

    virtual auto pathtrans_Path([[maybe_unused]] void *packet, [[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto pathtrans_Shape([[maybe_unused]] void *packet, [[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto pathtrans_Canvas([[maybe_unused]] void *packet, [[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto pathtrans_Item([[maybe_unused]] void *packet, [[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual void * pathtrans_Packet(ILxUnknownID path) = 0;
};

#define LXxD_VectorPathPacketTranslation_Path LxResult pathtrans_Path([[maybe_unused]] void *packet, [[maybe_unused]] void **ppvObj) override
#define LXxO_VectorPathPacketTranslation_Path LXxD_VectorPathPacketTranslation_Path
#define LXxC_VectorPathPacketTranslation_Path(c) LxResult c::pathtrans_Path([[maybe_unused]] void *packet, [[maybe_unused]] void **ppvObj)
#define LXxD_VectorPathPacketTranslation_Shape LxResult pathtrans_Shape([[maybe_unused]] void *packet, [[maybe_unused]] void **ppvObj) override
#define LXxO_VectorPathPacketTranslation_Shape LXxD_VectorPathPacketTranslation_Shape
#define LXxC_VectorPathPacketTranslation_Shape(c) LxResult c::pathtrans_Shape([[maybe_unused]] void *packet, [[maybe_unused]] void **ppvObj)
#define LXxD_VectorPathPacketTranslation_Canvas LxResult pathtrans_Canvas([[maybe_unused]] void *packet, [[maybe_unused]] void **ppvObj) override
#define LXxO_VectorPathPacketTranslation_Canvas LXxD_VectorPathPacketTranslation_Canvas
#define LXxC_VectorPathPacketTranslation_Canvas(c) LxResult c::pathtrans_Canvas([[maybe_unused]] void *packet, [[maybe_unused]] void **ppvObj)
#define LXxD_VectorPathPacketTranslation_Item LxResult pathtrans_Item([[maybe_unused]] void *packet, [[maybe_unused]] void **ppvObj) override
#define LXxO_VectorPathPacketTranslation_Item LXxD_VectorPathPacketTranslation_Item
#define LXxC_VectorPathPacketTranslation_Item(c) LxResult c::pathtrans_Item([[maybe_unused]] void *packet, [[maybe_unused]] void **ppvObj)
#define LXxD_VectorPathPacketTranslation_Packet void * pathtrans_Packet([[maybe_unused]] ILxUnknownID path) override
#define LXxO_VectorPathPacketTranslation_Packet LXxD_VectorPathPacketTranslation_Packet
#define LXxC_VectorPathPacketTranslation_Packet(c) void * c::pathtrans_Packet([[maybe_unused]] ILxUnknownID path)

template <class T>
class CLxIfc_VectorPathPacketTranslation: public CLxInterface
{
public:
    CLxIfc_VectorPathPacketTranslation()
    {
        vt.Path = Path;
        vt.Shape = Shape;
        vt.Canvas = Canvas;
        vt.Item = Item;
        vt.Packet = Packet;
        vTable = &vt.iunk;
        iid = &lx::guid_VectorPathPacketTranslation;
    }

    static auto Path(LXtObjectID wcom,void *packet,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_VectorPathPacketTranslation, loc);
        try
        {
           return loc->pathtrans_Path( packet, ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Shape(LXtObjectID wcom,void *packet,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_VectorPathPacketTranslation, loc);
        try
        {
           return loc->pathtrans_Shape( packet, ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Canvas(LXtObjectID wcom,void *packet,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_VectorPathPacketTranslation, loc);
        try
        {
           return loc->pathtrans_Canvas( packet, ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Item(LXtObjectID wcom,void *packet,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_VectorPathPacketTranslation, loc);
        try
        {
           return loc->pathtrans_Item( packet, ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Packet(LXtObjectID wcom,LXtObjectID path) -> void *
    {
        LXCWxINST (CLxImpl_VectorPathPacketTranslation, loc);
        return loc->pathtrans_Packet((ILxUnknownID) path);
    }

private:
    ILxVectorPathPacketTranslation vt;
};

class CLxLoc_VectorPathPacketTranslation : public CLxLocalize<ILxVectorPathPacketTranslationID>
{
public:
    CLxLoc_VectorPathPacketTranslation()
    {
        _init();
    }

    CLxLoc_VectorPathPacketTranslation(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_VectorPathPacketTranslation(CLxLoc_VectorPathPacketTranslation const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_VectorPathPacketTranslation;
    }

    auto Path(void *packet, void **ppvObj) -> LxResult
    {
        return m_loc[0]->Path(m_loc, packet, ppvObj);
    }

    auto Path(void *packet, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Path(m_loc, packet, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Shape(void *packet, void **ppvObj) -> LxResult
    {
        return m_loc[0]->Shape(m_loc, packet, ppvObj);
    }

    auto Shape(void *packet, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Shape(m_loc, packet, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Canvas(void *packet, void **ppvObj) -> LxResult
    {
        return m_loc[0]->Canvas(m_loc, packet, ppvObj);
    }

    auto Canvas(void *packet, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Canvas(m_loc, packet, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Item(void *packet, void **ppvObj) -> LxResult
    {
        return m_loc[0]->Item(m_loc, packet, ppvObj);
    }

    auto Item(void *packet, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Item(m_loc, packet, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Packet(ILxUnknownID path) -> void *
    {
        return m_loc[0]->Packet(m_loc,(ILxUnknownID) path);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_VectorKnotPacketTranslation
{
public:
    virtual ~CLxImpl_VectorKnotPacketTranslation() = default;

    virtual auto knottrans_Knot([[maybe_unused]] void *packet, [[maybe_unused]] LXtVectorKnotID *knot) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto knottrans_Path([[maybe_unused]] void *packet, [[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto knottrans_Shape([[maybe_unused]] void *packet, [[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto knottrans_Canvas([[maybe_unused]] void *packet, [[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto knottrans_Item([[maybe_unused]] void *packet, [[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual void * knottrans_Packet(LXtVectorKnotID knot) = 0;
};

#define LXxD_VectorKnotPacketTranslation_Knot LxResult knottrans_Knot([[maybe_unused]] void *packet, [[maybe_unused]] LXtVectorKnotID *knot) override
#define LXxO_VectorKnotPacketTranslation_Knot LXxD_VectorKnotPacketTranslation_Knot
#define LXxC_VectorKnotPacketTranslation_Knot(c) LxResult c::knottrans_Knot([[maybe_unused]] void *packet, [[maybe_unused]] LXtVectorKnotID *knot)
#define LXxD_VectorKnotPacketTranslation_Path LxResult knottrans_Path([[maybe_unused]] void *packet, [[maybe_unused]] void **ppvObj) override
#define LXxO_VectorKnotPacketTranslation_Path LXxD_VectorKnotPacketTranslation_Path
#define LXxC_VectorKnotPacketTranslation_Path(c) LxResult c::knottrans_Path([[maybe_unused]] void *packet, [[maybe_unused]] void **ppvObj)
#define LXxD_VectorKnotPacketTranslation_Shape LxResult knottrans_Shape([[maybe_unused]] void *packet, [[maybe_unused]] void **ppvObj) override
#define LXxO_VectorKnotPacketTranslation_Shape LXxD_VectorKnotPacketTranslation_Shape
#define LXxC_VectorKnotPacketTranslation_Shape(c) LxResult c::knottrans_Shape([[maybe_unused]] void *packet, [[maybe_unused]] void **ppvObj)
#define LXxD_VectorKnotPacketTranslation_Canvas LxResult knottrans_Canvas([[maybe_unused]] void *packet, [[maybe_unused]] void **ppvObj) override
#define LXxO_VectorKnotPacketTranslation_Canvas LXxD_VectorKnotPacketTranslation_Canvas
#define LXxC_VectorKnotPacketTranslation_Canvas(c) LxResult c::knottrans_Canvas([[maybe_unused]] void *packet, [[maybe_unused]] void **ppvObj)
#define LXxD_VectorKnotPacketTranslation_Item LxResult knottrans_Item([[maybe_unused]] void *packet, [[maybe_unused]] void **ppvObj) override
#define LXxO_VectorKnotPacketTranslation_Item LXxD_VectorKnotPacketTranslation_Item
#define LXxC_VectorKnotPacketTranslation_Item(c) LxResult c::knottrans_Item([[maybe_unused]] void *packet, [[maybe_unused]] void **ppvObj)
#define LXxD_VectorKnotPacketTranslation_Packet void * knottrans_Packet([[maybe_unused]] LXtVectorKnotID knot) override
#define LXxO_VectorKnotPacketTranslation_Packet LXxD_VectorKnotPacketTranslation_Packet
#define LXxC_VectorKnotPacketTranslation_Packet(c) void * c::knottrans_Packet([[maybe_unused]] LXtVectorKnotID knot)

template <class T>
class CLxIfc_VectorKnotPacketTranslation: public CLxInterface
{
public:
    CLxIfc_VectorKnotPacketTranslation()
    {
        vt.Knot = Knot;
        vt.Path = Path;
        vt.Shape = Shape;
        vt.Canvas = Canvas;
        vt.Item = Item;
        vt.Packet = Packet;
        vTable = &vt.iunk;
        iid = &lx::guid_VectorKnotPacketTranslation;
    }

    static auto Knot(LXtObjectID wcom,void *packet,LXtVectorKnotID *knot) -> LxResult
    {
        LXCWxINST (CLxImpl_VectorKnotPacketTranslation, loc);
        try
        {
           return loc->knottrans_Knot( packet, knot);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Path(LXtObjectID wcom,void *packet,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_VectorKnotPacketTranslation, loc);
        try
        {
           return loc->knottrans_Path( packet, ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Shape(LXtObjectID wcom,void *packet,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_VectorKnotPacketTranslation, loc);
        try
        {
           return loc->knottrans_Shape( packet, ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Canvas(LXtObjectID wcom,void *packet,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_VectorKnotPacketTranslation, loc);
        try
        {
           return loc->knottrans_Canvas( packet, ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Item(LXtObjectID wcom,void *packet,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_VectorKnotPacketTranslation, loc);
        try
        {
           return loc->knottrans_Item( packet, ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Packet(LXtObjectID wcom,LXtVectorKnotID knot) -> void *
    {
        LXCWxINST (CLxImpl_VectorKnotPacketTranslation, loc);
        return loc->knottrans_Packet( knot);
    }

private:
    ILxVectorKnotPacketTranslation vt;
};

class CLxLoc_VectorKnotPacketTranslation : public CLxLocalize<ILxVectorKnotPacketTranslationID>
{
public:
    CLxLoc_VectorKnotPacketTranslation()
    {
        _init();
    }

    CLxLoc_VectorKnotPacketTranslation(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_VectorKnotPacketTranslation(CLxLoc_VectorKnotPacketTranslation const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_VectorKnotPacketTranslation;
    }

    auto Knot(void *packet, LXtVectorKnotID *knot) -> LxResult
    {
        return m_loc[0]->Knot(m_loc, packet, knot);
    }

    auto Path(void *packet, void **ppvObj) -> LxResult
    {
        return m_loc[0]->Path(m_loc, packet, ppvObj);
    }

    auto Path(void *packet, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Path(m_loc, packet, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Shape(void *packet, void **ppvObj) -> LxResult
    {
        return m_loc[0]->Shape(m_loc, packet, ppvObj);
    }

    auto Shape(void *packet, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Shape(m_loc, packet, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Canvas(void *packet, void **ppvObj) -> LxResult
    {
        return m_loc[0]->Canvas(m_loc, packet, ppvObj);
    }

    auto Canvas(void *packet, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Canvas(m_loc, packet, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Item(void *packet, void **ppvObj) -> LxResult
    {
        return m_loc[0]->Item(m_loc, packet, ppvObj);
    }

    auto Item(void *packet, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Item(m_loc, packet, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Packet(LXtVectorKnotID knot) -> void *
    {
        return m_loc[0]->Packet(m_loc, knot);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_RenderSlotPacketTranslation : public CLxLocalize<ILxRenderSlotPacketTranslationID>
{
public:
    CLxLoc_RenderSlotPacketTranslation()
    {
        _init();
    }

    CLxLoc_RenderSlotPacketTranslation(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_RenderSlotPacketTranslation(CLxLoc_RenderSlotPacketTranslation const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_RenderSlotPacketTranslation;
    }

    auto SlotIdent(void *packet) -> int
    {
        return m_loc[0]->SlotIdent(m_loc, packet);
    }

    auto PassIndex(void *packet) -> int
    {
        return m_loc[0]->PassIndex(m_loc, packet);
    }

    auto OutputIndex(void *packet) -> int
    {
        return m_loc[0]->OutputIndex(m_loc, packet);
    }

    auto Client(void *packet, char *buf, int len) -> LxResult
    {
        return m_loc[0]->Client(m_loc, packet, buf, len);
    }

    auto Packet(int slotIdent, int passIndex, int outputIndex, const char *client) -> void *
    {
        return m_loc[0]->Packet(m_loc, slotIdent, passIndex, outputIndex, client);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
