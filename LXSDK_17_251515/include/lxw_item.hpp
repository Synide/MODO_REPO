//
// C++ wrapper for lxsdk/lxitem.h.
//
//	Copyright 2024.
//
//
#pragma once

#include <lxitem.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx
{
    static LXtGUID const guid_SceneService = {0x50190141, {0x0059, 0x48FE}, {0xB2, 0x7D, 0x6C, 0x98, 0xE1, 0x34, 0x8D, 0x7B}};
    static LXtGUID const guid_SceneSubset = {0xBC46E557, {0xA612, 0x4820}, {0x85, 0xF8, 0x12, 0x2D, 0x0F, 0xF5, 0x52, 0x1C}};
    static LXtGUID const guid_Scene2Service = {0x3B1E02DD, {0x8ACA, 0x4f30}, {0x99, 0xC4, 0xF8, 0x7B, 0x62, 0x6D, 0x4F, 0xA3}};
    static LXtGUID const guid_Scene = {0xFF870F44, {0xFED9, 0x4dbc}, {0x95, 0xBA, 0x29, 0x72, 0xA4, 0x3F, 0xC9, 0x36}};
    static LXtGUID const guid_Item = {0x7FF2D6D5, {0x5E28, 0x4650}, {0x93, 0xED, 0x89, 0xFF, 0x25, 0x7F, 0x96, 0x29}};
    static LXtGUID const guid_SceneGraph = {0xFE07D3C5, {0xC7E4, 0x46af}, {0x8F, 0x0A, 0x5A, 0xB1, 0x73, 0xD4, 0x84, 0x45}};
    static LXtGUID const guid_ItemGraph = {0xC34D7C65, {0x031A, 0x4c9d}, {0x8C, 0x01, 0x31, 0x87, 0xD3, 0x83, 0x93, 0x7B}};
    static LXtGUID const guid_ChannelGraph = {0xF70C8AD7, {0xC15F, 0x42e7}, {0x98, 0xF6, 0x4C, 0x4C, 0x7F, 0x6D, 0x57, 0x7E}};
    static LXtGUID const guid_SceneAssets = {0xFB35AE38, {0x4BF6, 0x4B6E}, {0x87, 0xE0, 0x6A, 0x6C, 0xB2, 0x99, 0x5B, 0x78}};
    static LXtGUID const guid_InstanceAssets = {0xC7454DED, {0x84A7, 0x4E5E}, {0x8F, 0xBE, 0xA9, 0x8D, 0x0E, 0xE3, 0xC6, 0xB4}};
} // namespace lx

class CLxLoc_SceneService : public CLxLocalizedService
{
public:
    ILxSceneServiceID m_loc{ nullptr };

public:
    CLxLoc_SceneService()
    {
        _init();
        set();
    }

    ~CLxLoc_SceneService() = default;

    void set()
    {
        if (!m_loc)
        {
            m_loc = reinterpret_cast<ILxSceneServiceID>(lx::GetGlobal(&lx::guid_SceneService));
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

    auto Root(void **ppvObj) -> LxResult
    {
        return m_loc[0]->Root(m_loc, ppvObj);
    }

    auto Root(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Root(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto ItemTypeCount(void) -> unsigned
    {
        return m_loc[0]->ItemTypeCount(m_loc);
    }

    auto ItemTypeByIndex(unsigned index, LXtItemType *type) -> LxResult
    {
        return m_loc[0]->ItemTypeByIndex(m_loc, index, type);
    }

    auto ItemTypeLookup(const char *name, LXtItemType *type) -> LxResult
    {
        return m_loc[0]->ItemTypeLookup(m_loc, name, type);
    }

    auto ItemTypeName(LXtItemType type, const char **name) -> LxResult
    {
        return m_loc[0]->ItemTypeName(m_loc, type, name);
    }

    auto ItemTypeTest(LXtItemType what, LXtItemType isA) -> LxResult
    {
        return m_loc[0]->ItemTypeTest(m_loc, what, isA);
    }

    auto ItemTypeSuper(LXtItemType type, LXtItemType *super) -> LxResult
    {
        return m_loc[0]->ItemTypeSuper(m_loc, type, super);
    }

    auto ItemTypeCommonChannels(ILxUnknownID item1, ILxUnknownID item2, unsigned *count) -> LxResult
    {
        return m_loc[0]->ItemTypeCommonChannels(m_loc,(ILxUnknownID) item1,(ILxUnknownID) item2, count);
    }

    auto ItemSubTypeCount(LXtItemType type, unsigned int *count) -> LxResult
    {
        return m_loc[0]->ItemSubTypeCount(m_loc, type, count);
    }

    auto ItemSubTypeByIndex(LXtItemType type, unsigned int index, const char **subtype) -> LxResult
    {
        return m_loc[0]->ItemSubTypeByIndex(m_loc, type, index, subtype);
    }

    auto ChannelVectorSize(unsigned int mode, unsigned int *size) -> LxResult
    {
        return m_loc[0]->ChannelVectorSize(m_loc, mode, size);
    }

    auto ChannelVectorTextHints(const LXtTextValueHint **hints) -> LxResult
    {
        return m_loc[0]->ChannelVectorTextHints(m_loc, hints);
    }

    auto CreateScene(void **ppvObj) -> LxResult
    {
        return m_loc[0]->CreateScene(m_loc, ppvObj);
    }

    auto CreateScene(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->CreateScene(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto DestroyScene(ILxUnknownID scene) -> LxResult
    {
        return m_loc[0]->DestroyScene(m_loc,(ILxUnknownID) scene);
    }

    auto SubSceneAdd(ILxUnknownID scene, ILxUnknownID other, unsigned refItems) -> LxResult
    {
        return m_loc[0]->SubSceneAdd(m_loc,(ILxUnknownID) scene,(ILxUnknownID) other, refItems);
    }

    auto SubSceneLoad(ILxUnknownID scene, const char *path, ILxUnknownID monitor, void **ppvObj) -> LxResult
    {
        return m_loc[0]->SubSceneLoad(m_loc,(ILxUnknownID) scene, path,(ILxUnknownID) monitor, ppvObj);
    }

    auto SubSceneLoad(ILxUnknownID scene, const char *path, ILxUnknownID monitor, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->SubSceneLoad(m_loc,(ILxUnknownID) scene, path,(ILxUnknownID) monitor, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto GetMeshInstSourceItem(ILxUnknownID inst, void **ppvObj) -> LxResult
    {
        return m_loc[0]->GetMeshInstSourceItem(m_loc,(ILxUnknownID) inst, ppvObj);
    }

    auto GetMeshInstSourceItem(ILxUnknownID inst, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->GetMeshInstSourceItem(m_loc,(ILxUnknownID) inst, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto MeshInstanceCount(ILxUnknownID mesh) -> int
    {
        return m_loc[0]->MeshInstanceCount(m_loc,(ILxUnknownID) mesh);
    }

    auto MeshInstanceByIndex(ILxUnknownID mesh, int index, void **ppvObj) -> LxResult
    {
        return m_loc[0]->MeshInstanceByIndex(m_loc,(ILxUnknownID) mesh, index, ppvObj);
    }

    auto MeshInstanceByIndex(ILxUnknownID mesh, int index, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->MeshInstanceByIndex(m_loc,(ILxUnknownID) mesh, index, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto LoadImage(ILxUnknownID scene, const char *path, ILxUnknownID monitor, void **ppvObj) -> LxResult
    {
        return m_loc[0]->LoadImage(m_loc,(ILxUnknownID) scene, path,(ILxUnknownID) monitor, ppvObj);
    }

    auto LoadImage(ILxUnknownID scene, const char *path, ILxUnknownID monitor, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->LoadImage(m_loc,(ILxUnknownID) scene, path,(ILxUnknownID) monitor, &o_obj);
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

    auto ItemTypeGetTag(LXtItemType type, const char *tag, unsigned super, const char **value) -> LxResult
    {
        return m_loc[0]->ItemTypeGetTag(m_loc, type, tag, super, value);
    }

    auto ItemGraphCollection(ILxUnknownID collection, LXtItemType type, const char *graph, int fwd) -> LxResult
    {
        return m_loc[0]->ItemGraphCollection(m_loc,(ILxUnknownID) collection, type, graph, fwd);
    }

    auto CreateSubsetEvaluator(ILxUnknownID eval, void **ppvObj) -> LxResult
    {
        return m_loc[0]->CreateSubsetEvaluator(m_loc,(ILxUnknownID) eval, ppvObj);
    }

    auto CreateSubsetEvaluator(ILxUnknownID eval, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->CreateSubsetEvaluator(m_loc,(ILxUnknownID) eval, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto AllocEmptyCollection(void **ppvObj) -> LxResult
    {
        return m_loc[0]->AllocEmptyCollection(m_loc, ppvObj);
    }

    auto AllocEmptyCollection(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->AllocEmptyCollection(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto CloseCollection(ILxUnknownID collection, unsigned mode) -> LxResult
    {
        return m_loc[0]->CloseCollection(m_loc,(ILxUnknownID) collection, mode);
    }

    auto ItemTypeSupportsInterface(LXtItemType type, const LXtGUID *guid) -> LxResult
    {
        return m_loc[0]->ItemTypeSupportsInterface(m_loc, type, guid);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_SceneSubset
{
public:
    virtual ~CLxImpl_SceneSubset() = default;

    virtual auto scnsub_GetScene([[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto scnsub_GetCollection([[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_SceneSubset_GetScene LxResult scnsub_GetScene([[maybe_unused]] void **ppvObj) override
#define LXxO_SceneSubset_GetScene LXxD_SceneSubset_GetScene
#define LXxC_SceneSubset_GetScene(c) LxResult c::scnsub_GetScene([[maybe_unused]] void **ppvObj)
#define LXxD_SceneSubset_GetCollection LxResult scnsub_GetCollection([[maybe_unused]] void **ppvObj) override
#define LXxO_SceneSubset_GetCollection LXxD_SceneSubset_GetCollection
#define LXxC_SceneSubset_GetCollection(c) LxResult c::scnsub_GetCollection([[maybe_unused]] void **ppvObj)

template <class T>
class CLxIfc_SceneSubset: public CLxInterface
{
public:
    CLxIfc_SceneSubset()
    {
        vt.GetScene = GetScene;
        vt.GetCollection = GetCollection;
        vTable = &vt.iunk;
        iid = &lx::guid_SceneSubset;
    }

    static auto GetScene(LXtObjectID wcom,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_SceneSubset, loc);
        try
        {
           return loc->scnsub_GetScene( ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto GetCollection(LXtObjectID wcom,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_SceneSubset, loc);
        try
        {
           return loc->scnsub_GetCollection( ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxSceneSubset vt;
};

class CLxLoc_SceneSubset : public CLxLocalize<ILxSceneSubsetID>
{
public:
    CLxLoc_SceneSubset()
    {
        _init();
    }

    CLxLoc_SceneSubset(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_SceneSubset(CLxLoc_SceneSubset const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_SceneSubset;
    }

    auto GetScene(void **ppvObj) -> LxResult
    {
        return m_loc[0]->GetScene(m_loc, ppvObj);
    }

    auto GetScene(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->GetScene(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto GetCollection(void **ppvObj) -> LxResult
    {
        return m_loc[0]->GetCollection(m_loc, ppvObj);
    }

    auto GetCollection(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->GetCollection(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};

class CLxLoc_Scene : public CLxLocalize<ILxSceneID>
{
public:
    CLxLoc_Scene()
    {
        _init();
    }

    CLxLoc_Scene(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_Scene(CLxLoc_Scene const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_Scene;
    }

    auto ItemRootType(void) -> LXtItemType
    {
        return m_loc[0]->ItemRootType(m_loc);
    }

    auto Filename(const char **filename) -> LxResult
    {
        return m_loc[0]->Filename(m_loc, filename);
    }

    auto FriendlyFilename(unsigned flags, const char **filename) -> LxResult
    {
        return m_loc[0]->FriendlyFilename(m_loc, flags, filename);
    }

    auto FileFormat(const char **format) -> LxResult
    {
        return m_loc[0]->FileFormat(m_loc, format);
    }

    auto Changed(unsigned changed) -> LxResult
    {
        return m_loc[0]->Changed(m_loc, changed);
    }

    auto HasChanged(unsigned int *numChanges) -> LxResult
    {
        return m_loc[0]->HasChanged(m_loc, numChanges);
    }

    auto Parent(void **ppvObj) -> LxResult
    {
        return m_loc[0]->Parent(m_loc, ppvObj);
    }

    auto Parent(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Parent(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto SubSceneCount(LXtItemType type, unsigned int *count) -> LxResult
    {
        return m_loc[0]->SubSceneCount(m_loc, type, count);
    }

    auto SubSceneByIndex(LXtItemType type, unsigned int index, void **ppvObj) -> LxResult
    {
        return m_loc[0]->SubSceneByIndex(m_loc, type, index, ppvObj);
    }

    auto SubSceneByIndex(LXtItemType type, unsigned int index, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->SubSceneByIndex(m_loc, type, index, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto LoadFlags(void) -> unsigned
    {
        return m_loc[0]->LoadFlags(m_loc);
    }

    auto Channels(const char *name, double time, void **ppvObj) const -> LxResult
    {
        return m_loc[0]->Channels(m_loc, name, time, ppvObj);
    }

    auto Channels(const char *name, double time, CLxLocalizedObject &o_dest) const -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Channels(m_loc, name, time, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto ItemCount(LXtItemType type, unsigned int *count) const -> LxResult
    {
        return m_loc[0]->ItemCount(m_loc, type, count);
    }

    auto ItemByIndex(LXtItemType type, unsigned int index, void **ppvObj) const -> LxResult
    {
        return m_loc[0]->ItemByIndex(m_loc, type, index, ppvObj);
    }

    auto ItemByIndex(LXtItemType type, unsigned int index, CLxLocalizedObject &o_dest) const -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->ItemByIndex(m_loc, type, index, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto ItemLookup(const char *id, void **ppvObj) const -> LxResult
    {
        return m_loc[0]->ItemLookup(m_loc, id, ppvObj);
    }

    auto ItemLookup(const char *id, CLxLocalizedObject &o_dest) const -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->ItemLookup(m_loc, id, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto ItemCountByTypes(const LXtItemType *types, unsigned *count) const -> LxResult
    {
        return m_loc[0]->ItemCountByTypes(m_loc, types, count);
    }

    auto ItemByIndexByTypes(const LXtItemType *types, unsigned index, void **ppvObj) const -> LxResult
    {
        return m_loc[0]->ItemByIndexByTypes(m_loc, types, index, ppvObj);
    }

    auto ItemByIndexByTypes(const LXtItemType *types, unsigned index, CLxLocalizedObject &o_dest) const -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->ItemByIndexByTypes(m_loc, types, index, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto AnyItemOfType(LXtItemType type, void **ppvObj) const -> LxResult
    {
        return m_loc[0]->AnyItemOfType(m_loc, type, ppvObj);
    }

    auto AnyItemOfType(LXtItemType type, CLxLocalizedObject &o_dest) const -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->AnyItemOfType(m_loc, type, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto ItemLocalize(ILxUnknownID item, void **ppvObj) -> LxResult
    {
        return m_loc[0]->ItemLocalize(m_loc,(ILxUnknownID) item, ppvObj);
    }

    auto ItemLocalize(ILxUnknownID item, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->ItemLocalize(m_loc,(ILxUnknownID) item, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto ItemAdd(LXtItemType type, void **ppvObj) -> LxResult
    {
        return m_loc[0]->ItemAdd(m_loc, type, ppvObj);
    }

    auto ItemAdd(LXtItemType type, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->ItemAdd(m_loc, type, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto ItemInstance(ILxUnknownID item, void **ppvObj) -> LxResult
    {
        return m_loc[0]->ItemInstance(m_loc,(ILxUnknownID) item, ppvObj);
    }

    auto ItemInstance(ILxUnknownID item, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->ItemInstance(m_loc,(ILxUnknownID) item, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto ItemAddReference(ILxUnknownID item, void **ppvObj) -> LxResult
    {
        return m_loc[0]->ItemAddReference(m_loc,(ILxUnknownID) item, ppvObj);
    }

    auto ItemAddReference(ILxUnknownID item, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->ItemAddReference(m_loc,(ILxUnknownID) item, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto GraphLookup(const char *name, void **ppvObj) const -> LxResult
    {
        return m_loc[0]->GraphLookup(m_loc, name, ppvObj);
    }

    auto GraphLookup(const char *name, CLxLocalizedObject &o_dest) const -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->GraphLookup(m_loc, name, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto GraphCount(int *count) const -> LxResult
    {
        return m_loc[0]->GraphCount(m_loc, count);
    }

    auto GraphByIndex(unsigned index, void **ppvObj) const -> LxResult
    {
        return m_loc[0]->GraphByIndex(m_loc, index, ppvObj);
    }

    auto GraphByIndex(unsigned index, CLxLocalizedObject &o_dest) const -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->GraphByIndex(m_loc, index, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto ItemRemove(ILxUnknownID item) -> LxResult
    {
        return m_loc[0]->ItemRemove(m_loc,(ILxUnknownID) item);
    }

    auto Import(const char *path, ILxUnknownID monitor) -> LxResult
    {
        return m_loc[0]->Import(m_loc, path,(ILxUnknownID) monitor);
    }

    auto EvalModInvalidate(const char *modName) -> LxResult
    {
        return m_loc[0]->EvalModInvalidate(m_loc, modName);
    }

    auto EvalModReset(const char *modName) -> LxResult
    {
        return m_loc[0]->EvalModReset(m_loc, modName);
    }

    auto ItemReplace(ILxUnknownID item, int type, void **ppvObj) -> LxResult
    {
        return m_loc[0]->ItemReplace(m_loc,(ILxUnknownID) item, type, ppvObj);
    }

    auto ItemReplace(ILxUnknownID item, int type, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->ItemReplace(m_loc,(ILxUnknownID) item, type, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto SetupMode(void) -> LxResult
    {
        return m_loc[0]->SetupMode(m_loc);
    }

    auto SetupChannels(void **ppvObj) const -> LxResult
    {
        return m_loc[0]->SetupChannels(m_loc, ppvObj);
    }

    auto SetupChannels(CLxLocalizedObject &o_dest) const -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->SetupChannels(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto ItemLookupIdent(const char *id, void **ppvObj) -> LxResult
    {
        return m_loc[0]->ItemLookupIdent(m_loc, id, ppvObj);
    }

    auto ItemLookupIdent(const char *id, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->ItemLookupIdent(m_loc, id, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto ItemLookupImported(const char *id, void **ppvObj) -> LxResult
    {
        return m_loc[0]->ItemLookupImported(m_loc, id, ppvObj);
    }

    auto ItemLookupImported(const char *id, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->ItemLookupImported(m_loc, id, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto RenderCameraCount(int *count) const -> LxResult
    {
        return m_loc[0]->RenderCameraCount(m_loc, count);
    }

    auto RenderCameraByIndex(int index, void **ppvObj) const -> LxResult
    {
        return m_loc[0]->RenderCameraByIndex(m_loc, index, ppvObj);
    }

    auto RenderCameraByIndex(int index, CLxLocalizedObject &o_dest) const -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->RenderCameraByIndex(m_loc, index, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto RenderCameraIndex(ILxUnknownID eval, int *index) const -> LxResult
    {
        return m_loc[0]->RenderCameraIndex(m_loc,(ILxUnknownID) eval, index);
    }

    auto ItemCopy(ILxUnknownID item, void **ppvObj) -> LxResult
    {
        return m_loc[0]->ItemCopy(m_loc,(ILxUnknownID) item, ppvObj);
    }

    auto ItemCopy(ILxUnknownID item, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->ItemCopy(m_loc,(ILxUnknownID) item, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto BatchCreateBegin(void) -> LxResult
    {
        return m_loc[0]->BatchCreateBegin(m_loc);
    }

    auto BatchCreateEnd(void) -> LxResult
    {
        return m_loc[0]->BatchCreateEnd(m_loc);
    }

    auto BatchCreateAbort(void) -> LxResult
    {
        return m_loc[0]->BatchCreateAbort(m_loc);
    }

    auto BatchCopyBegin(ILxUnknownID destination) -> LxResult
    {
        return m_loc[0]->BatchCopyBegin(m_loc,(ILxUnknownID) destination);
    }

    auto BatchCopyEnd(void) -> LxResult
    {
        return m_loc[0]->BatchCopyEnd(m_loc);
    }

    auto BatchCopyAbort(void) -> LxResult
    {
        return m_loc[0]->BatchCopyAbort(m_loc);
    }

    auto WorkPlaneRotation(ILxUnknownID chanRead, LXtMatrix m3) -> LxResult
    {
        return m_loc[0]->WorkPlaneRotation(m_loc,(ILxUnknownID) chanRead, m3);
    }

    auto WorkPlanePosition(ILxUnknownID chanRead, LXtVector pos) -> LxResult
    {
        return m_loc[0]->WorkPlanePosition(m_loc,(ILxUnknownID) chanRead, pos);
    }

    auto GeneralCollection(const char *typeName, const char *arg, ILxUnknownID rootItem, void **ppvObj) -> LxResult
    {
        return m_loc[0]->GeneralCollection(m_loc, typeName, arg,(ILxUnknownID) rootItem, ppvObj);
    }

    auto GeneralCollection(const char *typeName, const char *arg, ILxUnknownID rootItem, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->GeneralCollection(m_loc, typeName, arg,(ILxUnknownID) rootItem, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto GeneralCollectionRaw(const char *typeName, const char *arg, ILxUnknownID rootItem, void **ppvObj) -> LxResult
    {
        return m_loc[0]->GeneralCollectionRaw(m_loc, typeName, arg,(ILxUnknownID) rootItem, ppvObj);
    }

    auto GeneralCollectionRaw(const char *typeName, const char *arg, ILxUnknownID rootItem, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->GeneralCollectionRaw(m_loc, typeName, arg,(ILxUnknownID) rootItem, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto AllocAssets(void **ppvObj) -> LxResult
    {
        return m_loc[0]->AllocAssets(m_loc, ppvObj);
    }

    auto AllocAssets(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->AllocAssets(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto DeleteCollection(ILxUnknownID collection, unsigned closeMode) -> LxResult
    {
        return m_loc[0]->DeleteCollection(m_loc,(ILxUnknownID) collection, closeMode);
    }

    auto CustomLoad(ILxUnknownID visitor) -> LxResult
    {
        return m_loc[0]->CustomLoad(m_loc,(ILxUnknownID) visitor);
    }

    auto TextureCopy(ILxUnknownID item, void **ppvObj) -> LxResult
    {
        return m_loc[0]->TextureCopy(m_loc,(ILxUnknownID) item, ppvObj);
    }

    auto TextureCopy(ILxUnknownID item, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->TextureCopy(m_loc,(ILxUnknownID) item, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Index(unsigned int *index) -> LxResult
    {
        return m_loc[0]->Index(m_loc, index);
    }

    auto IsChanging(unsigned int *type) -> LxResult
    {
        return m_loc[0]->IsChanging(m_loc, type);
    }

    auto TriangleLimit(void) -> unsigned
    {
        return m_loc[0]->TriangleLimit(m_loc);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_Item : public CLxLocalize<ILxItemID>
{
public:
    CLxLoc_Item()
    {
        _init();
    }

    CLxLoc_Item(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_Item(CLxLoc_Item const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_Item;
    }

    auto Type(void) -> LXtItemType
    {
        return m_loc[0]->Type(m_loc);
    }

    auto TestType(LXtItemType type) -> LxResult
    {
        return m_loc[0]->TestType(m_loc, type);
    }

    auto TestTypes(const LXtItemType *types) -> LxResult
    {
        return m_loc[0]->TestTypes(m_loc, types);
    }

    auto Ident(const char **ident) const -> LxResult
    {
        return m_loc[0]->Ident(m_loc, ident);
    }

    auto SetIdent(const char *ident) -> LxResult
    {
        return m_loc[0]->SetIdent(m_loc, ident);
    }

    auto Name(const char **name) -> LxResult
    {
        return m_loc[0]->Name(m_loc, name);
    }

    auto SetName(const char *name) -> LxResult
    {
        return m_loc[0]->SetName(m_loc, name);
    }

    auto UniqueName(const char **name) -> LxResult
    {
        return m_loc[0]->UniqueName(m_loc, name);
    }

    auto UniqueIndex(unsigned *index) -> LxResult
    {
        return m_loc[0]->UniqueIndex(m_loc, index);
    }

    auto SetUniqueIndex(unsigned index) -> LxResult
    {
        return m_loc[0]->SetUniqueIndex(m_loc, index);
    }

    auto Parent(void **ppvObj) -> LxResult
    {
        return m_loc[0]->Parent(m_loc, ppvObj);
    }

    auto Parent(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Parent(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto SetParent(ILxUnknownID parent) -> LxResult
    {
        return m_loc[0]->SetParent(m_loc,(ILxUnknownID) parent);
    }

    auto SubCount(unsigned *count) -> LxResult
    {
        return m_loc[0]->SubCount(m_loc, count);
    }

    auto SubByIndex(unsigned index, void **ppvObj) -> LxResult
    {
        return m_loc[0]->SubByIndex(m_loc, index, ppvObj);
    }

    auto SubByIndex(unsigned index, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->SubByIndex(m_loc, index, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Root(void **ppvObj) -> LxResult
    {
        return m_loc[0]->Root(m_loc, ppvObj);
    }

    auto Root(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Root(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Context(void **ppvObj) -> LxResult
    {
        return m_loc[0]->Context(m_loc, ppvObj);
    }

    auto Context(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Context(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Reference(void **ppvObj) -> LxResult
    {
        return m_loc[0]->Reference(m_loc, ppvObj);
    }

    auto Reference(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Reference(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto IsReferenced(void) -> LxResult
    {
        return m_loc[0]->IsReferenced(m_loc);
    }

    auto Source(void **ppvObj) -> LxResult
    {
        return m_loc[0]->Source(m_loc, ppvObj);
    }

    auto Source(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Source(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto SetSource(ILxUnknownID source) -> LxResult
    {
        return m_loc[0]->SetSource(m_loc,(ILxUnknownID) source);
    }

    auto ChannelCount(unsigned *count) const -> LxResult
    {
        return m_loc[0]->ChannelCount(m_loc, count);
    }

    auto ChannelLookup(const char *name, unsigned *index) const -> LxResult
    {
        return m_loc[0]->ChannelLookup(m_loc, name, index);
    }

    auto ChannelName(unsigned index, const char **name) const -> LxResult
    {
        return m_loc[0]->ChannelName(m_loc, index, name);
    }

    auto ChannelType(unsigned index, unsigned *type) -> LxResult
    {
        return m_loc[0]->ChannelType(m_loc, index, type);
    }

    auto ChannelVectorMode(unsigned index, unsigned *mode, unsigned *components) -> LxResult
    {
        return m_loc[0]->ChannelVectorMode(m_loc, index, mode, components);
    }

    auto ChannelStorageType(unsigned index, const char **type) -> LxResult
    {
        return m_loc[0]->ChannelStorageType(m_loc, index, type);
    }

    auto ChannelEvalType(unsigned index, const char **type) -> LxResult
    {
        return m_loc[0]->ChannelEvalType(m_loc, index, type);
    }

    auto ChannelGradient(unsigned index, const char **input, const char **output) -> LxResult
    {
        return m_loc[0]->ChannelGradient(m_loc, index, input, output);
    }

    auto ChannelIntHint(unsigned index, const LXtTextValueHint **hints) const -> LxResult
    {
        return m_loc[0]->ChannelIntHint(m_loc, index, hints);
    }

    auto ChannelPackage(unsigned index, const char **package) -> LxResult
    {
        return m_loc[0]->ChannelPackage(m_loc, index, package);
    }

    auto PackageAdd(const char *package) -> LxResult
    {
        return m_loc[0]->PackageAdd(m_loc, package);
    }

    auto PackageTest(const char *package) const -> LxResult
    {
        return m_loc[0]->PackageTest(m_loc, package);
    }

    auto PackageStartIndex(const char *package, unsigned *index) -> LxResult
    {
        return m_loc[0]->PackageStartIndex(m_loc, package, index);
    }

    auto PackageRemove(const char *package) -> LxResult
    {
        return m_loc[0]->PackageRemove(m_loc, package);
    }

    auto ChannelAdd(void **ppvObj) -> LxResult
    {
        return m_loc[0]->ChannelAdd(m_loc, ppvObj);
    }

    auto ChannelAdd(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->ChannelAdd(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto GetTag(LXtID4 type) -> const char *
    {
        return m_loc[0]->GetTag(m_loc, type);
    }

    auto SetTag(LXtID4 type, const char *tag) -> LxResult
    {
        return m_loc[0]->SetTag(m_loc, type, tag);
    }

    auto InvalidateName(void) -> void
    {
        m_loc[0]->InvalidateName(m_loc);
    }

    auto WasLoaded(unsigned test) -> LxResult
    {
        return m_loc[0]->WasLoaded(m_loc, test);
    }

    auto Delete(void) -> LxResult
    {
        return m_loc[0]->Delete(m_loc);
    }

    auto UserChannelCount(unsigned int *count) const -> LxResult
    {
        return m_loc[0]->UserChannelCount(m_loc, count);
    }

    auto ChannelIsDriven(unsigned index) -> LxResult
    {
        return m_loc[0]->ChannelIsDriven(m_loc, index);
    }

    auto SetParentAndPosition(ILxUnknownID parent, unsigned pos) -> LxResult
    {
        return m_loc[0]->SetParentAndPosition(m_loc,(ILxUnknownID) parent, pos);
    }

    auto BaseName(const char **name) -> LxResult
    {
        return m_loc[0]->BaseName(m_loc, name);
    }

    auto DuplicateChannel(ILxUnknownID from, unsigned int channelIndex, int channelVectorMode, const char **newChannelName) -> LxResult
    {
        return m_loc[0]->DuplicateChannel(m_loc,(ILxUnknownID) from, channelIndex, channelVectorMode, newChannelName);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_SceneGraph : public CLxLocalize<ILxSceneGraphID>
{
public:
    CLxLoc_SceneGraph()
    {
        _init();
    }

    CLxLoc_SceneGraph(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_SceneGraph(CLxLoc_SceneGraph const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_SceneGraph;
    }

    auto Name(const char **name) -> LxResult
    {
        return m_loc[0]->Name(m_loc, name);
    }

    auto Context(void **ppvObj) -> LxResult
    {
        return m_loc[0]->Context(m_loc, ppvObj);
    }

    auto Context(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Context(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto RootCount(int *count) -> LxResult
    {
        return m_loc[0]->RootCount(m_loc, count);
    }

    auto RootByIndex(int index, void **ppvObj) -> LxResult
    {
        return m_loc[0]->RootByIndex(m_loc, index, ppvObj);
    }

    auto RootByIndex(int index, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->RootByIndex(m_loc, index, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto RootFirst(void **ppvObj) -> LxResult
    {
        return m_loc[0]->RootFirst(m_loc, ppvObj);
    }

    auto RootFirst(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->RootFirst(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto RootNext(void **ppvObj) -> LxResult
    {
        return m_loc[0]->RootNext(m_loc, ppvObj);
    }

    auto RootNext(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->RootNext(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto RootSetPos(ILxUnknownID item, int pos) -> LxResult
    {
        return m_loc[0]->RootSetPos(m_loc,(ILxUnknownID) item, pos);
    }

    auto RootRemove(ILxUnknownID item) -> LxResult
    {
        return m_loc[0]->RootRemove(m_loc,(ILxUnknownID) item);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_ItemGraph : public CLxLocalize<ILxItemGraphID>
{
public:
    CLxLoc_ItemGraph()
    {
        _init();
    }

    CLxLoc_ItemGraph(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_ItemGraph(CLxLoc_ItemGraph const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_ItemGraph;
    }

    auto AddLink(ILxUnknownID from, ILxUnknownID to) -> LxResult
    {
        return m_loc[0]->AddLink(m_loc,(ILxUnknownID) from,(ILxUnknownID) to);
    }

    auto SetLink(ILxUnknownID from, int fromIndex, ILxUnknownID to, int toIndex) -> LxResult
    {
        return m_loc[0]->SetLink(m_loc,(ILxUnknownID) from, fromIndex,(ILxUnknownID) to, toIndex);
    }

    auto DeleteLink(ILxUnknownID from, ILxUnknownID to) -> LxResult
    {
        return m_loc[0]->DeleteLink(m_loc,(ILxUnknownID) from,(ILxUnknownID) to);
    }

    auto FwdCount(ILxUnknownID item, unsigned *count) -> LxResult
    {
        return m_loc[0]->FwdCount(m_loc,(ILxUnknownID) item, count);
    }

    auto FwdByIndex(ILxUnknownID item, unsigned index, void **ppvObj) -> LxResult
    {
        return m_loc[0]->FwdByIndex(m_loc,(ILxUnknownID) item, index, ppvObj);
    }

    auto FwdByIndex(ILxUnknownID item, unsigned index, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->FwdByIndex(m_loc,(ILxUnknownID) item, index, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto RevCount(ILxUnknownID item, unsigned *count) -> LxResult
    {
        return m_loc[0]->RevCount(m_loc,(ILxUnknownID) item, count);
    }

    auto RevByIndex(ILxUnknownID item, unsigned index, void **ppvObj) -> LxResult
    {
        return m_loc[0]->RevByIndex(m_loc,(ILxUnknownID) item, index, ppvObj);
    }

    auto RevByIndex(ILxUnknownID item, unsigned index, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->RevByIndex(m_loc,(ILxUnknownID) item, index, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_ChannelGraph : public CLxLocalize<ILxChannelGraphID>
{
public:
    CLxLoc_ChannelGraph()
    {
        _init();
    }

    CLxLoc_ChannelGraph(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_ChannelGraph(CLxLoc_ChannelGraph const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_ChannelGraph;
    }

    auto AddLink(ILxUnknownID from, int fromChan, ILxUnknownID to, int toChan) -> LxResult
    {
        return m_loc[0]->AddLink(m_loc,(ILxUnknownID) from, fromChan,(ILxUnknownID) to, toChan);
    }

    auto SetLink(ILxUnknownID from, int fromChan, int fromIndex, ILxUnknownID to, int toChan, int toIndex) -> LxResult
    {
        return m_loc[0]->SetLink(m_loc,(ILxUnknownID) from, fromChan, fromIndex,(ILxUnknownID) to, toChan, toIndex);
    }

    auto DeleteLink(ILxUnknownID from, int fromChan, ILxUnknownID to, int toChan) -> LxResult
    {
        return m_loc[0]->DeleteLink(m_loc,(ILxUnknownID) from, fromChan,(ILxUnknownID) to, toChan);
    }

    auto FwdCount(ILxUnknownID item, int channel, unsigned *count) -> LxResult
    {
        return m_loc[0]->FwdCount(m_loc,(ILxUnknownID) item, channel, count);
    }

    auto FwdByIndex(ILxUnknownID item, int channel, unsigned index, void **ppvObj, int *objChan) -> LxResult
    {
        return m_loc[0]->FwdByIndex(m_loc,(ILxUnknownID) item, channel, index, ppvObj, objChan);
    }

    auto FwdByIndex(ILxUnknownID item, int channel, unsigned index, CLxLocalizedObject &o_dest, int *objChan) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->FwdByIndex(m_loc,(ILxUnknownID) item, channel, index, &o_obj, objChan);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto RevCount(ILxUnknownID item, int channel, unsigned *count) -> LxResult
    {
        return m_loc[0]->RevCount(m_loc,(ILxUnknownID) item, channel, count);
    }

    auto RevByIndex(ILxUnknownID item, int channel, unsigned index, void **ppvObj, int *objChan) -> LxResult
    {
        return m_loc[0]->RevByIndex(m_loc,(ILxUnknownID) item, channel, index, ppvObj, objChan);
    }

    auto RevByIndex(ILxUnknownID item, int channel, unsigned index, CLxLocalizedObject &o_dest, int *objChan) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->RevByIndex(m_loc,(ILxUnknownID) item, channel, index, &o_obj, objChan);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_SceneAssets : public CLxLocalize<ILxSceneAssetsID>
{
public:
    CLxLoc_SceneAssets()
    {
        _init();
    }

    CLxLoc_SceneAssets(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_SceneAssets(CLxLoc_SceneAssets const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_SceneAssets;
    }

    auto Count(unsigned *count) -> LxResult
    {
        return m_loc[0]->Count(m_loc, count);
    }

    auto Item(unsigned index, void **ppvObj) const -> LxResult
    {
        return m_loc[0]->Item(m_loc, index, ppvObj);
    }

    auto Item(unsigned index, CLxLocalizedObject &o_dest) const -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Item(m_loc, index, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Ident(unsigned index, const char **ident) -> LxResult
    {
        return m_loc[0]->Ident(m_loc, index, ident);
    }

    auto FileType(unsigned index, const char **type) -> LxResult
    {
        return m_loc[0]->FileType(m_loc, index, type);
    }

    auto Category(unsigned index, const char **category) const -> LxResult
    {
        return m_loc[0]->Category(m_loc, index, category);
    }

    auto IsSequence(unsigned index) -> LxResult
    {
        return m_loc[0]->IsSequence(m_loc, index);
    }

    auto GetPath(ILxUnknownID item, const char *ident, char *buf, unsigned len) const -> LxResult
    {
        return m_loc[0]->GetPath(m_loc,(ILxUnknownID) item, ident, buf, len);
    }

    auto GetPath(ILxUnknownID item, const char *ident, std::string &result) const -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->GetPath(m_loc,(ILxUnknownID) item, ident, buf, len);
        LXWx_SBUF2
    }

    auto SetPath(ILxUnknownID item, const char *ident, const char *newPath) -> LxResult
    {
        return m_loc[0]->SetPath(m_loc,(ILxUnknownID) item, ident, newPath);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_InstanceAssets
{
public:
    virtual ~CLxImpl_InstanceAssets() = default;

    virtual auto instass_Count([[maybe_unused]] unsigned *count) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto instass_IdentByIndex([[maybe_unused]] unsigned index, [[maybe_unused]] unsigned *isSeq, [[maybe_unused]] const char **fileType, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto instass_Category([[maybe_unused]] unsigned index, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto instass_GetPath([[maybe_unused]] const char *ident, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto instass_SetPath([[maybe_unused]] const char *ident, [[maybe_unused]] const char *newPath) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_InstanceAssets_Count LxResult instass_Count([[maybe_unused]] unsigned *count) override
#define LXxO_InstanceAssets_Count LXxD_InstanceAssets_Count
#define LXxC_InstanceAssets_Count(c) LxResult c::instass_Count([[maybe_unused]] unsigned *count)
#define LXxD_InstanceAssets_IdentByIndex LxResult instass_IdentByIndex([[maybe_unused]] unsigned index, [[maybe_unused]] unsigned *isSeq, [[maybe_unused]] const char **fileType, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len) override
#define LXxO_InstanceAssets_IdentByIndex LXxD_InstanceAssets_IdentByIndex
#define LXxC_InstanceAssets_IdentByIndex(c) LxResult c::instass_IdentByIndex([[maybe_unused]] unsigned index, [[maybe_unused]] unsigned *isSeq, [[maybe_unused]] const char **fileType, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len)
#define LXxD_InstanceAssets_Category LxResult instass_Category([[maybe_unused]] unsigned index, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len) override
#define LXxO_InstanceAssets_Category LXxD_InstanceAssets_Category
#define LXxC_InstanceAssets_Category(c) LxResult c::instass_Category([[maybe_unused]] unsigned index, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len)
#define LXxD_InstanceAssets_GetPath LxResult instass_GetPath([[maybe_unused]] const char *ident, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len) override
#define LXxO_InstanceAssets_GetPath LXxD_InstanceAssets_GetPath
#define LXxC_InstanceAssets_GetPath(c) LxResult c::instass_GetPath([[maybe_unused]] const char *ident, [[maybe_unused]] char *buf, [[maybe_unused]] unsigned len)
#define LXxD_InstanceAssets_SetPath LxResult instass_SetPath([[maybe_unused]] const char *ident, [[maybe_unused]] const char *newPath) override
#define LXxO_InstanceAssets_SetPath LXxD_InstanceAssets_SetPath
#define LXxC_InstanceAssets_SetPath(c) LxResult c::instass_SetPath([[maybe_unused]] const char *ident, [[maybe_unused]] const char *newPath)

template <class T>
class CLxIfc_InstanceAssets: public CLxInterface
{
public:
    CLxIfc_InstanceAssets()
    {
        vt.Count = Count;
        vt.IdentByIndex = IdentByIndex;
        vt.Category = Category;
        vt.GetPath = GetPath;
        vt.SetPath = SetPath;
        vTable = &vt.iunk;
        iid = &lx::guid_InstanceAssets;
    }

    static auto Count(LXtObjectID wcom,unsigned *count) -> LxResult
    {
        LXCWxINST (CLxImpl_InstanceAssets, loc);
        try
        {
           return loc->instass_Count( count);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto IdentByIndex(LXtObjectID wcom,unsigned index,unsigned *isSeq,const char **fileType,char *buf,unsigned len) -> LxResult
    {
        LXCWxINST (CLxImpl_InstanceAssets, loc);
        try
        {
           return loc->instass_IdentByIndex( index, isSeq, fileType, buf, len);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Category(LXtObjectID wcom,unsigned index,char *buf,unsigned len) -> LxResult
    {
        LXCWxINST (CLxImpl_InstanceAssets, loc);
        try
        {
           return loc->instass_Category( index, buf, len);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto GetPath(LXtObjectID wcom,const char *ident,char *buf,unsigned len) -> LxResult
    {
        LXCWxINST (CLxImpl_InstanceAssets, loc);
        try
        {
           return loc->instass_GetPath( ident, buf, len);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SetPath(LXtObjectID wcom,const char *ident,const char *newPath) -> LxResult
    {
        LXCWxINST (CLxImpl_InstanceAssets, loc);
        try
        {
           return loc->instass_SetPath( ident, newPath);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxInstanceAssets vt;
};

class CLxLoc_InstanceAssets : public CLxLocalize<ILxInstanceAssetsID>
{
public:
    CLxLoc_InstanceAssets()
    {
        _init();
    }

    CLxLoc_InstanceAssets(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_InstanceAssets(CLxLoc_InstanceAssets const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_InstanceAssets;
    }

    auto Count(unsigned *count) -> LxResult
    {
        return m_loc[0]->Count(m_loc, count);
    }

    auto IdentByIndex(unsigned index, unsigned *isSeq, const char **fileType, char *buf, unsigned len) const -> LxResult
    {
        return m_loc[0]->IdentByIndex(m_loc, index, isSeq, fileType, buf, len);
    }

    auto IdentByIndex(unsigned index, unsigned *isSeq, const char **fileType, std::string &result) const -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->IdentByIndex(m_loc, index, isSeq, fileType, buf, len);
        LXWx_SBUF2
    }

    auto Category(unsigned index, char *buf, unsigned len) const -> LxResult
    {
        return m_loc[0]->Category(m_loc, index, buf, len);
    }

    auto Category(unsigned index, std::string &result) const -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->Category(m_loc, index, buf, len);
        LXWx_SBUF2
    }

    auto GetPath(const char *ident, char *buf, unsigned len) const -> LxResult
    {
        return m_loc[0]->GetPath(m_loc, ident, buf, len);
    }

    auto GetPath(const char *ident, std::string &result) const -> LxResult
    {
        LXWx_SBUF1
        rc = m_loc[0]->GetPath(m_loc, ident, buf, len);
        LXWx_SBUF2
    }

    auto SetPath(const char *ident, const char *newPath) -> LxResult
    {
        return m_loc[0]->SetPath(m_loc, ident, newPath);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
