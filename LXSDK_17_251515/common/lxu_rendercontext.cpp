/*
 * Plug-in SDK Header: C++ Services
 *
 * Copyright 0000
 *
 * Helper classes for implementing a custom renderer.
 */
#include <lxu_rendercontext.hpp>

#include <lx_locator.hpp>
#include <lx_thread.hpp>

#include <lx_group.hpp>
#include <lx_image.hpp>
#include <lx_rendercache.hpp>
#include <lx_surface.hpp>
#include <lxu_matrix.hpp>
#include <lxu_select.hpp>
#include <lxu_surface.hpp>

#include <lx_listener.hpp>
#include <lx_select.hpp>
#include <lx_seltypes.hpp>

#include <lxidef.h>     // channel names
#include <lxpackage.h>  // LXi_CIT_XXX

#include <algorithm>
#include <iterator>
#include <unordered_set>

// #define ENABLE_LOGGING

#ifdef ENABLE_LOGGING
// FIXME:
// #include "log.h"
#else
#define LogInfo(Msg, ...)
#define LogError(Msg, ...)
#endif

//-----------------------------------------------------------------------------
// Initialize common types
//-----------------------------------------------------------------------------
CLxItemType citRender(LXsITYPE_RENDER);

CLxItemType citLocator(LXsITYPE_LOCATOR);
CLxItemType citTransform(LXsITYPE_TRANSFORM);
CLxItemType citGroupLocator(LXsITYPE_GROUPLOCATOR);

CLxItemType citCamera(LXsITYPE_CAMERA);
CLxItemType citTextureLoc(LXsITYPE_TEXTURELOC);

CLxItemType citEnvironment(LXsITYPE_ENVIRONMENT);
CLxItemType citEnvMaterial(LXsITYPE_ENVMATERIAL);

CLxItemType citLightMaterial(LXsITYPE_LIGHTMATERIAL);
CLxItemType citLight(LXsITYPE_LIGHT);
CLxItemType citSunLight(LXsITYPE_SUNLIGHT);
CLxItemType citPointLight(LXsITYPE_POINTLIGHT);
CLxItemType citSpotLight(LXsITYPE_SPOTLIGHT);
CLxItemType citAreaLight(LXsITYPE_AREALIGHT);
CLxItemType citMeshLight(LXsITYPE_MESHLIGHT);

CLxItemType citMask(LXsITYPE_MASK);
CLxItemType citTextureLayer(LXsITYPE_TEXTURELAYER);
CLxItemType citAdvancedMaterial(LXsITYPE_ADVANCEDMATERIAL);
CLxItemType citDefaultShader(LXsITYPE_DEFAULTSHADER);
CLxItemType citRenderOutput(LXsITYPE_RENDEROUTPUT);
CLxItemType citImageMap(LXsITYPE_IMAGEMAP);
CLxItemType citConstant(LXsITYPE_CONSTANT);
CLxItemType citShaderFolder(LXsITYPE_SHADERFOLDER);

CLxItemType citVideoClip(LXsITYPE_VIDEOCLIP);
CLxItemType citVideoStill(LXsITYPE_VIDEOSTILL);
CLxItemType citVideoSequence(LXsITYPE_VIDEOSEQUENCE);
CLxItemType citImageLayer(LXsITYPE_IMAGELAYER);

namespace lx
{
    bool GetEnvironmentForEnvMaterial(CLxUser_Item& envMat, CLxUser_Item& env)
    {
        env.clear();

        if (!envMat.IsA(citEnvMaterial))
            return false;

        // TODO: Find an environment item for this material
        CLxUser_Item curr, parent;

        curr.set(envMat);

        do
        {
            if (!curr.GetParent(parent))
                break;

            if (parent.IsA(citRender))
                break;

            if (parent.IsA(citEnvironment))
            {
                env.set(parent);
                break;
            }

            curr.set(parent);
        } while (curr.test());

        return env.test();
    }
}  // namespace lx

namespace
{
    //-----------------------------------------------------------------------------
    /**
     * Test whether the item is of the specified type
     */
    //-----------------------------------------------------------------------------
    inline LxResult TestItemType(CLxUser_Item& item, CLxItemType& type)
    {
        LxResult res;

        if (!item.test())
            return LXe_INVALIDARG;

        res = LXxBOOL2RC(item.IsA(type));
        if (LXe_FALSE == res)
        {
            res |= LXe_FAILED;  // since LXe_FALSE does not set this bit
        }

        // #ifdef _DEBUG

        if (LXx_FAIL(res))
        {
            const char*          itemName;
            const char*          itemType;
            CLxUser_SceneService svc;

            item.UniqueName(&itemName);
            svc.ItemTypeName(item.Type(), &itemType);

            LogError("item:%s type:%s is not a:%s type", itemName, itemType, type.type_name);
        }

        // #endif

        return res;
    }

    //-----------------------------------------------------------------------------
    //-----------------------------------------------------------------------------
    // void GetMaskName (std::string& maskName)
    //{
    //	// Cleanup mask name
    //	std::size_t idx = maskName.find('(');

    //	if (idx != std::string::npos)
    //		maskName = maskName.substr(0, idx - 1);
    //}

    ////-----------------------------------------------------------------------------
    ////-----------------------------------------------------------------------------
    // bool GetMaskItem (CLxUser_Item& item, CLxUser_Item& mask)
    //{
    //	CLxUser_Item	parent, tmp;
    //	const char*	name;

    //	mask.clear ();
    //	item.UniqueName (&name);
    //	parent.set (item);

    //	// Search all the parents until we find a mask item
    //	while (1)
    //	{
    //		parent.UniqueName (&name);

    //		if (parent.IsA (citRender))
    //			break;

    //		if (parent.IsA (citMask))
    //		{
    //			// We got the mask item
    //			mask.set (parent);
    //
    //			break;
    //		}

    //		if (!parent.GetParent (tmp))
    //			break;

    //		parent = tmp;
    //	}

    //	return mask.test ();
    //}

    //-----------------------------------------------------------------------------
    /**
     * Return the Light Material (citLightMaterial) from the specified light.
     */
    //-----------------------------------------------------------------------------
    bool GetLightMaterialFromLight(CLxUser_Item& light, CLxUser_Item& lightMat)
    {
        lightMat.clear();

        // Get light material
        unsigned nSubItems;

        light.SubCount(&nSubItems);

        for (unsigned sc = 0; sc < nSubItems; ++sc)
        {
            CLxUser_Item subItem;

            light.SubByIndex(nSubItems - 1 - sc, subItem);

            if (subItem.IsA(citLightMaterial))
            {
                lightMat = subItem;

                break;
            }
        }

        // If no light material is found, check if light belongs to group and find it there
        CLxUser_Scene     scene;
        CLxUser_ItemGraph localShd;
        CLxUser_Item      group;

        if (!lightMat.test())
        {
            light.GetContext(scene);

            localShd.from(scene, "localShader");
            localShd.Reverse(light, 0, group);

            if (group.test())
            {
                nSubItems = localShd.Forward(group);

                for (unsigned sc = 0; sc < nSubItems; ++sc)
                {
                    CLxUser_Item subItem;

                    localShd.Forward(group, nSubItems - 1 - sc, subItem);

                    if (subItem.IsA(citLightMaterial))
                    {
                        lightMat = subItem;
                        break;
                    }
                }
            }
        }

        return lightMat.test();
    }

    //-----------------------------------------------------------------------------
    /**
     * Return the Light from the specified Light Material (citLightMaterial).
     */
    //-----------------------------------------------------------------------------
    bool GetLightFromLightMaterial(CLxUser_Item& lightMat, CLxUser_Item& light)
    {
        light.clear();

        // Check if light material has parent
        // If no light material has no parent, search the "localShader" graph for the light item
        if (!lightMat.GetParent(light))
        {
            CLxUser_Scene     scene;
            CLxUser_ItemGraph localShd;
            CLxUser_Item      group;
            int               nSubItems;

            lightMat.GetContext(scene);

            localShd.from(scene, "localShader");
            localShd.Reverse(lightMat, 0, group);

            if (group.test())
            {
                nSubItems = localShd.Forward(group);

                for (unsigned sc = 0; sc < nSubItems; ++sc)
                {
                    CLxUser_Item subItem;

                    localShd.Forward(group, nSubItems - 1 - sc, subItem);

                    if (subItem.IsA(citLight))
                    {
                        light = subItem;
                        break;
                    }
                }
            }
        }

        return light.test();
    }

    //-----------------------------------------------------------------------------
    /**
     * Determine if an item and all of its parent items are enabled.
     * Used in evaluating the shader tree.
     */
    //-----------------------------------------------------------------------------
    bool IsItemAndAllParentsEnabled(CLxUser_ChannelRead& channelReader, CLxUser_Item& item)
    {
        const int chanEnable = item.ChannelIndex(LXsICHAN_TEXTURELAYER_ENABLE);

        bool enabled = true;
        if (chanEnable >= 0)
        {
            enabled = channelReader.IValue(item, chanEnable) > 0;
        }

        if (enabled)
        {
            // since the visitor is called linearly, need to cope with the hierarchy in the shading tree
            // are all of its parents enabled too?
            CLxUser_Item parentItem;
            item.GetParent(parentItem);
            if (parentItem.test())
            {
                enabled &= IsItemAndAllParentsEnabled(channelReader, parentItem);
            }
        }

        return enabled;
    }
}  // namespace

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
namespace lx
{
    //---------------------------------------------------------------------
    /**
     * Singleton for listening to scene events, selection events, and RenderCache
     * events.
     * Translates these into CLxRenderContextEvent for consumption by plugins that
     * have specified a listener to their CLxRenderContext instance.
     * Instances of this type do not own the CLxRenderContext.
     */
    //---------------------------------------------------------------------
    class SceneListener : public CLxSingletonPolymorph,
                          public CLxImpl_SelectionListener,
                          public CLxImpl_SceneItemListener,
                          public CLxImpl_RenderCacheListener
    {
    public:
        LXxSINGLETON_METHOD

        //-----------------------------------------------------------------------------
        /**
         * Return the singleton instance (creating it if necessary).
         */
        //-----------------------------------------------------------------------------
        static SceneListener*
        GetInstance()
        {
            if (_inst == nullptr)
                _inst = new SceneListener();

            return _inst;
        }

        //-----------------------------------------------------------------------------
        /**
         * Release the singleton instance, and reset to NULL.
         */
        //-----------------------------------------------------------------------------
        static void ReleaseInstance()
        {
            if (_inst)
            {
                delete _inst;
                _inst = nullptr;
            }
        }

        //-----------------------------------------------------------------------------
        /**
         * Construct a default instance.
         * This contains an invalid CLxRenderContext for events to be set upon.
         */
        //-----------------------------------------------------------------------------
        SceneListener() : _ctx(nullptr)
        {
            AddInterface(new CLxIfc_SelectionListener<SceneListener>());
            AddInterface(new CLxIfc_SceneItemListener<SceneListener>());
            AddInterface(new CLxIfc_RenderCacheListener<SceneListener>());
        }

        //-----------------------------------------------------------------------------
        /**
         * Start listening, associating events with the specified CLxRenderContext.
         *
         */
        //-----------------------------------------------------------------------------
        void Start(CLxRenderContext* ctx)
        {
            _ctx = ctx;
            _ctx->Scene(_scene);
            _time = _selSvc.GetTime();

            // Add render cache listener
            CLxUser_ListenerPort rcachePort(ctx->_rcache);

            rcachePort.AddListener(*this);

            // Add scene item listener
            CLxUser_ListenerService lsSvc;

            _sceneCode = _selSvc.LookupType(LXsSELTYP_SCENE);

            lsSvc.AddListener(*this);
        }

        //-----------------------------------------------------------------------------
        /**
         * Stop listening, diassociating events with the current CLxRenderContext.
         */
        //-----------------------------------------------------------------------------
        void Stop()
        {
            CLxUser_ListenerService lsSvc;

            lsSvc.RemoveListener(*this);

            // Remove render cache listener
            CLxUser_ListenerPort rcachePort;

            if (_ctx && _ctx->_rcache)
            {
                if (rcachePort.set(_ctx->_rcache))
                    rcachePort.RemoveListener(*this);
            }

            // clear the variables
            _ctx = nullptr;
            _scene.clear();
            _time = 0.0;
        }

        //-----------------------------------------------------------------------------
        /**
         * Handle scene change events.
         */
        //-----------------------------------------------------------------------------
        void selevent_Add(LXtID4 type, unsigned /*subType*/) override
        {
            if (type != _sceneCode)
                return;

            if (!_ctx)
                return;

            CLxSceneSelection sceneSel;
            CLxUser_Scene     scene;
            if (!sceneSel.Get(scene))
            {
                return;
            }

            // Remember the selected scene
            if (scene != _scene)
            {
                _scene = scene;

                // Notify context that scene has changed
                _ctx->SetEvent(CLxRenderContextEvent(LXi_RCTX_EVT_SCENE_CURRENT, scene));
            }

            ProcessItemEvents();

            _newScene.clear();
        }

        //-----------------------------------------------------------------------------
        /**
         * Handle scene removal events.
         */
        //-----------------------------------------------------------------------------
        void selevent_Remove(LXtID4 type, unsigned /*subType*/) override
        {
            if (type != _sceneCode)
                return;
        }

        //-----------------------------------------------------------------------------
        /**
         * Handle scene time change events.
         */
        //-----------------------------------------------------------------------------
        void selevent_Time(double time) override
        {
            _time = time;

            if (_ctx)
                _ctx->SetEvent(CLxRenderContextEvent(LXi_RCTX_EVT_SCENE_TIME_CHANGE, _scene, _time));
        }

        //-----------------------------------------------------------------------------
        /**
         * Handle scene creation events.
         */
        //-----------------------------------------------------------------------------
        void sil_SceneCreate(ILxUnknownID sceneObj) override
        {
            CLxUser_Scene scene(sceneObj);
            const char*   name = "";

            if (scene.test())
                scene.FriendlyFilename(0, &name);

            _newScene.set(sceneObj);

            LogInfo("SceneListener::SceneCreate():%s %p", name, (ILxUnknownID) scene);

            if (_ctx)
                _ctx->SetEvent(CLxRenderContextEvent(LXi_RCTX_EVT_SCENE_CREATE, _newScene));
        }

        //-----------------------------------------------------------------------------
        /**
         * Handle scene clearing events.
         */
        //-----------------------------------------------------------------------------
        void sil_SceneClear(ILxUnknownID sceneObj) override
        {
            CLxUser_Scene scene(sceneObj);
            const char*   name = "";

            if (scene.test())
                scene.FriendlyFilename(0, &name);

            LogInfo("SceneListener::SceneClear():%s %p", name, (ILxUnknownID) scene);

            if (scene == _scene)
            {
                if (_ctx)
                    _ctx->SetEvent(CLxRenderContextEvent(LXi_RCTX_EVT_SCENE_CLEAR, scene));

                _scene.clear();
            }
        }

        //-----------------------------------------------------------------------------
        /**
         * Handle scene destruction events.
         */
        //-----------------------------------------------------------------------------
        void sil_SceneDestroy(ILxUnknownID sceneObj) override
        {
            CLxUser_Scene scene(sceneObj);
            const char*   name = "";

            if (scene.test())
                scene.FriendlyFilename(0, &name);

            LogInfo("SceneListener::SceneDestroy():%s %p", name, (ILxUnknownID) scene);

            // if (((ILxUnknownID) scene) == ((ILxUnknownID) _scene) && _ctx)
            if (scene == _scene)
            {
                if (_ctx)
                    _ctx->SetEvent(CLxRenderContextEvent(LXi_RCTX_EVT_SCENE_DESTROY, scene));

                _scene.clear();
            }
        }

        //-----------------------------------------------------------------------------
        /**
         * Handle items added to a scene.
         * The processing of the items is deferred. See rli_UpdateEnd
         */
        //-----------------------------------------------------------------------------
        void sil_ItemAdd(ILxUnknownID itemObj) override
        {
            CLxUser_Item  item(itemObj);
            const char*   itemIdent;
            CLxUser_Scene scene;
            const char*   sceneName;

            item.GetContext(scene);
            item.Ident(&itemIdent);
            scene.FriendlyFilename(0, &sceneName);

            LogInfo("SceneListener::ItemAdd() scene:%s ident:%s", sceneName, itemIdent);

            if (_scene == scene)
                _itemAdded.push_back(itemObj);
        }

        //-----------------------------------------------------------------------------
        /**
         * Handle items removed from a scene.
         * The processing of the items is deferred (see rli_UpdateEnd), but the event LXi_RCTX_EVT_SCENE_ITEM_REMOVE
         * is sent to the CLxRenderContext.
         */
        //-----------------------------------------------------------------------------
        void sil_ItemRemove(ILxUnknownID itemObj) override
        {
            CLxUser_Item  item(itemObj);
            const char*   itemIdent;
            CLxUser_Scene scene;
            const char*   sceneName;

            item.GetContext(scene);
            item.Ident(&itemIdent);
            scene.FriendlyFilename(0, &sceneName);

            LogInfo("SceneListener::ItemRemove() scene:%s ident:%s", sceneName, itemIdent);

            if (_scene == scene)
            {
                _ctx->SetEvent(CLxRenderContextEvent(LXi_RCTX_EVT_SCENE_ITEM_REMOVE, item));

                _itemRemoved.push_back(itemObj);

                // Sometimes we're getting sil_ChannelValue() events on removed items
                // We can't keep a item pointer (since item is going to be deleted).
                // We need to store an ident and prevent update event for items that have
                // been deleted.
                _itemRemovedIdents.insert(itemIdent);
            }
        }

        //-----------------------------------------------------------------------------
        /**
         * Handle items that are about to change.
         */
        //-----------------------------------------------------------------------------
        void sil_ItemPreChange(ILxUnknownID /*sceneObj*/) override
        {
        }

        //-----------------------------------------------------------------------------
        /**
         * Handle items that have just been deleted.
         */
        //-----------------------------------------------------------------------------
        void sil_ItemPostDelete(ILxUnknownID sceneObj) override
        {
            CLxUser_Scene scene(sceneObj);

            if (scene == _scene)
                ProcessRemovedItems();
        }

        //-----------------------------------------------------------------------------
        /**
         * Handle channel updates on items
         */
        //-----------------------------------------------------------------------------
        void sil_ChannelValue(const char* action, ILxUnknownID itemObj, unsigned index) override
        {
            // We're interested only in changes in "edit" action.
            // It's assumed that RenderContext clients (renderers) have already got the latest
            // channel values when they've initialized the render context.
            if (strcmp(action, LXs_ACTIONLAYER_EDIT) != 0)
                return;

            CLxUser_Item  item(itemObj);
            const char*   itemIdent = item.IdentPtr();
            CLxUser_Scene scene;

            item.GetContext(scene);

            if (_scene == scene)
            {
                // Make sure we're not sending an update event for removed item (sil_ItemRemove())
                // Also all item update events are deferred until rli_UpdateBegin() is called and
                // processed in rli_UpdateEnd().
                if (_itemRemovedIdents.find(itemIdent) == _itemRemovedIdents.end())
                {
                    // However, we want to update rendering state as soon as possible for certain channels.
                    // For example when render resolution changes (channels on render item).
                    if (item.IsA(citRender))
                        _ctx->SetEvent(CLxRenderContextEvent(LXi_RCTX_EVT_SCENE_ITEM_UPDATE, item));
                    else
                    {
                        ItemChan itemChan = { itemObj, index };

                        _itemUpdated.push_back(itemChan);
                    }
                }
            }
        }

#ifdef ENABLE_LOGGING
        //-----------------------------------------------------------------------------
        //-----------------------------------------------------------------------------
        void sil_LinkRemBefore(const char* graph, ILxUnknownID itemFrom, ILxUnknownID itemTo) override
        {
            CLxUser_Item srcItem(itemFrom);
            CLxUser_Item dstItem(itemTo);

            const char* srcItemIdent = srcItem.IdentPtr();
            const char* dstItemIdent = dstItem.IdentPtr();

            LogInfo("Removing link %s -> %s", srcItemIdent, dstItemIdent);
        }

        //-----------------------------------------------------------------------------
        //-----------------------------------------------------------------------------
        void sil_ChanLinkRemBefore(const char* graph, ILxUnknownID itemFrom, unsigned chanFrom, ILxUnknownID itemTo, unsigned chanTo) override
        {
            CLxUser_Item srcItem(itemFrom);
            CLxUser_Item dstItem(itemTo);

            const char* srcItemIdent = srcItem.IdentPtr();
            const char* dstItemIdent = dstItem.IdentPtr();

            LogInfo("Removing link %s:%d -> %s:%d", srcItemIdent, chanFrom, dstItemIdent, chanTo);
        }
#endif  // ENABLE_LOGGING

        //-----------------------------------------------------------------------------
        /**
         * Handle the local RenderCache being destroyed
         */
        //-----------------------------------------------------------------------------
        void rli_RenderCacheDestroy() override
        {
            if (_ctx)
                _ctx->SetEvent(CLxRenderContextEvent(LXi_RCTX_EVT_RCACHE_DESTROY, _ctx->_rcache));
        }

        //-----------------------------------------------------------------------------
        /**
         * Handle the local RenderCache being cleared
         */
        //-----------------------------------------------------------------------------
        void rli_RenderCacheClear() override
        {
            if (_ctx)
                _ctx->SetEvent(CLxRenderContextEvent(LXi_RCTX_EVT_RCACHE_CLEAR, _ctx->_rcache));
        }

        //-----------------------------------------------------------------------------
        /**
         * Handle updates starting on the local RenderCache
         */
        //-----------------------------------------------------------------------------
        void rli_UpdateBegin() override
        {
            LogInfo("SceneListener:UpdateBegin()");
            _ctx->SetEvent(CLxRenderContextEvent(LXi_RCTX_EVT_RCACHE_UPDATE_BEGIN, nullptr));
        }

        //-----------------------------------------------------------------------------
        /**
         * Handle updates completing on the local RenderCache.
         * This is the point at which deferred actions are processed.
         */
        //-----------------------------------------------------------------------------
        void rli_UpdateEnd() override
        {
            for (size_t c = 0; c < _gcSrfAdded.size(); ++c)
            {
                ILxUnknownID geoSrf = _gcSrfAdded[c];

                _ctx->SetEvent(CLxRenderContextEvent(LXi_RCTX_EVT_RCACHE_SURF_ADD, geoSrf));
            }

            for (size_t c = 0; c < _gcSrfRemoved.size(); ++c)
            {
                ILxUnknownID geoSrf = _gcSrfRemoved[c];

                _ctx->SetEvent(CLxRenderContextEvent(LXi_RCTX_EVT_RCACHE_SURF_REMOVE, geoSrf));
            }

            for (size_t c = 0; c < _gcSrfGeoUpdates.size(); ++c)
            {
                ILxUnknownID geoSrf = _gcSrfGeoUpdates[c];

                _ctx->SetEvent(CLxRenderContextEvent(LXi_RCTX_EVT_RCACHE_SURF_GEO_UPDATE, geoSrf));
            }

            for (size_t c = 0; c < _gcSrfShdUpdates.size(); ++c)
            {
                ILxUnknownID geoSrf = _gcSrfShdUpdates[c];

                _ctx->SetEvent(CLxRenderContextEvent(LXi_RCTX_EVT_RCACHE_SURF_SHD_UPDATE, geoSrf));
            }

            for (size_t c = 0; c < _gcSrfXfmUpdates.size(); ++c)
            {
                ILxUnknownID geoSrf = _gcSrfXfmUpdates[c];

                _ctx->SetEvent(CLxRenderContextEvent(LXi_RCTX_EVT_RCACHE_SURF_XFM_UPDATE, geoSrf));
            }

            ProcessItemEvents();

            LogInfo("SceneListener:UpdateEnd()");

            _ctx->SetEvent(CLxRenderContextEvent(LXi_RCTX_EVT_RCACHE_UPDATE_END, nullptr));

            _gcSrfAdded.clear();
            _gcSrfRemoved.clear();
            _gcSrfGeoUpdates.clear();
            _gcSrfXfmUpdates.clear();
            _gcSrfShdUpdates.clear();
        }

        //-----------------------------------------------------------------------------
        /**
         * Handle surfaces being added to the local RenderCache.
         * Processing is deferred until rli_UpdateEnd.
         */
        //-----------------------------------------------------------------------------
        void rli_GeoCacheSurfaceAdd(ILxUnknownID geoSurf) override
        {
            LogInfo("SceneListener:SurfaceAdd()");
            _gcSrfAdded.push_back(geoSurf);
        }

        //-----------------------------------------------------------------------------
        /**
         * Handle surfaces being removed from the local RenderCache.
         * Processing is deferred until rli_UpdateEnd.
         */
        //-----------------------------------------------------------------------------
        void rli_GeoCacheSurfaceRemove(ILxUnknownID geoSurf) override
        {
            LogInfo("SceneListener:SurfaceRemove()");
            _gcSrfRemoved.push_back(geoSurf);
        }

        //-----------------------------------------------------------------------------
        /**
         * Handle surfaces with geometry updates in the local RenderCache.
         * Processing is deferred until rli_UpdateEnd.
         */
        //-----------------------------------------------------------------------------
        void rli_GeoCacheSurfaceGeoUpdate(ILxUnknownID geoSurf) override
        {
            LogInfo("SceneListener:GeoCacheSurfaceGeoUpdate()");
            _gcSrfGeoUpdates.push_back(geoSurf);
        }

        //-----------------------------------------------------------------------------
        /**
         * Handle surface transform updates in the local RenderCache.
         * Processing is deferred until rli_UpdateEnd.
         */
        //-----------------------------------------------------------------------------
        void rli_GeoCacheSurfaceXformUpdate(ILxUnknownID geoSurf) override
        {
            LogInfo("SceneListener:GeoCacheSurfaceXformUpdate()");
            _gcSrfXfmUpdates.push_back(geoSurf);
        }

        //-----------------------------------------------------------------------------
        /**
         * Handle surface shader updates in the local RenderCache.
         * Processing is deferred until rli_UpdateEnd.
         */
        //-----------------------------------------------------------------------------
        void rli_GeoCacheSurfaceShaderUpdate(ILxUnknownID geoSurf) override
        {
            LogInfo("SceneListener:GeoCacheSurfaceShaderUpdate()");
            _gcSrfShdUpdates.push_back(geoSurf);
        }

    private:
        //-----------------------------------------------------------------------------
        //-----------------------------------------------------------------------------
        // void UpdateSurfaceShaders (const char* maskName)
        //{
        //	// Visit all the surfaces in the render cache
        //	// For each surface get it's material tag
        //	// Compare the material tag and the mask name
        //	CLxUser_RenderCache&		rcache = _ctx->_rcache;
        //	CLxUser_GeoCacheSurface		srf;
        //	int				nSrfs = 0;
        //	const char*			srfMaskName = nullptr;

        //	rcache.GeoSurfaceCount (&nSrfs);

        //	for (int sc = 0; sc < nSrfs; ++sc)
        //	{
        //		if (!rcache.GetGeoSurface(sc, srf))
        //			continue;

        //		// nullptr is special case, trigger the shader update forr all surfaces
        //		if (!maskName)
        //		{
        //			_ctx->SetEvent (CLxRenderContextEvent (LXi_RCTX_EVT_RCACHE_SURF_SHD_UPDATE, srf));
        //			continue;
        //		}

        //		srf.ShaderMaskName (&srfMaskName);

        //		if (srfMaskName && strstr (srfMaskName, maskName))
        //		{
        //			// Trigger the shader update
        //			_ctx->SetEvent (CLxRenderContextEvent (LXi_RCTX_EVT_RCACHE_SURF_SHD_UPDATE, srf));
        //		}
        //	}
        //}

        //-----------------------------------------------------------------------------
        /**
         * Process the deferred item added and updated lists for any removed items
         * so that when rli_UpdateEnd is executed, no adds or updates are executed
         * so a deleted item
         */
        //-----------------------------------------------------------------------------
        void ProcessRemovedItems()
        {
            const char*  itemIdent;
            CLxUser_Item currItem;

            // Sort the items arrays for faster searching
            std::sort(_itemRemoved.begin(), _itemRemoved.end(), SortByItem());
            std::sort(_itemAdded.begin(), _itemAdded.end(), SortByItem());
            std::sort(_itemUpdated.begin(), _itemUpdated.end(), SortByItem());

            // Process removed items
            for (size_t c = 0; c < _itemRemoved.size(); ++c)
            {
                currItem.set(_itemRemoved[c]);
                if (!currItem.test())
                    continue;

                currItem.Ident(&itemIdent);

                // Cleanup the added items (test if they're removed)
                while (1)
                {
                    auto it = std::find(_itemAdded.begin(), _itemAdded.end(), _itemRemoved[c]);

                    if (it == _itemAdded.end())
                        break;
                    else
                        _itemAdded.erase(it);
                }

                // Cleanup the updated items (test if they're removed)
                while (1)
                {
                    auto it = std::find_if(_itemUpdated.begin(), _itemUpdated.end(), FindItem(_itemRemoved[c]));

                    if (it == _itemUpdated.end())
                        break;
                    else
                        _itemUpdated.erase(it);
                }
            }

            _itemRemoved.clear();
        }

        //-----------------------------------------------------------------------------
        /**
         * Process the deferred items from previous events.
         * This may be additions (LXi_RCTX_EVT_SCENE_ITEM_ADD), updates (LXi_RCTX_EVT_SCENE_ITEM_UPDATE) or removals (event already actioned).
         *
         */
        //-----------------------------------------------------------------------------
        void ProcessItemEvents()
        {
            // CLxUser_Scene	itemScene;
            // const char*	itemName;
            const char*  itemIdent;
            CLxUser_Item currItem, prevItem;
            std::string  maskName;

            // Sort the items arrays for faster searching
            std::sort(_itemRemoved.begin(), _itemRemoved.end(), SortByItem());
            std::sort(_itemAdded.begin(), _itemAdded.end(), SortByItem());
            std::sort(_itemUpdated.begin(), _itemUpdated.end(), SortByItem());

            // Process removed items
            for (size_t c = 0; c < _itemRemoved.size(); ++c)
            {
                currItem.set(_itemRemoved[c]);
                if (!currItem.test())
                    continue;

                currItem.Ident(&itemIdent);

                // One item can be added multiple times into array
                if (prevItem.test() && currItem == prevItem)
                    continue;

                // if (currItem.IsA (citMask))
                //{
                //	// Force shader update for all surfaces
                //	// TODO: Check mask channel to update only affected surfaces
                //	UpdateSurfaceShaders (nullptr);
                // }

                prevItem.set(_itemRemoved[c]);

                // Cleanup the updated items (test if they're removed)
                while (1)
                {
                    auto it = std::find_if(_itemUpdated.begin(), _itemUpdated.end(), FindItem(_itemRemoved[c]));

                    if (it == _itemUpdated.end())
                        break;
                    else
                        _itemUpdated.erase(it);
                }
            }

            // Process added items
            for (size_t c = 0; c < _itemAdded.size(); ++c)
            {
                currItem.set(_itemAdded[c]);
                currItem.Ident(&itemIdent);

                _ctx->SetEvent(CLxRenderContextEvent(LXi_RCTX_EVT_SCENE_ITEM_ADD, currItem));

                // Cleanup the updated items (test if they're added)
                while (1)
                {
                    auto it = std::find_if(_itemUpdated.begin(), _itemUpdated.end(), FindItem(_itemAdded[c]));

                    if (it == _itemUpdated.end())
                        break;
                    else
                        _itemUpdated.erase(it);
                }
            }

            // Process updated items
            for (size_t c = 0; c < _itemUpdated.size(); ++c)
            {
                currItem.set(_itemUpdated[c].item);
                currItem.Ident(&itemIdent);

                // One item can be added multiple times into array
                if (prevItem.test() && currItem == prevItem)
                    continue;

                // Always send event notification for current item
                _ctx->SetEvent(CLxRenderContextEvent(LXi_RCTX_EVT_SCENE_ITEM_UPDATE, currItem));

                // If current item is a light material, find the appropriate light for it and
                // send event for that light
                if (currItem.IsA(citLightMaterial))
                {
                    CLxUser_Item light;

                    if (GetLightFromLightMaterial(currItem, light))
                        _ctx->SetEvent(CLxRenderContextEvent(LXi_RCTX_EVT_SCENE_ITEM_UPDATE, light));
                }
                // else
                // if (currItem.IsA (citMask))
                //{
                //	currItem.UniqueName (&itemName);
                //	maskName = itemName;

                //	// Update shader for surfaces that are affected by the mask
                //	UpdateSurfaceShaders (maskName.c_str ());
                //}
                // else
                // if (currItem.IsA (citTextureLayer))
                //{
                //	CLxUser_Item		mask;

                //	if (GetMaskItem (currItem, mask))
                //	{
                //		mask.UniqueName (&itemName);
                //		maskName = itemName;

                //		// Cleanup mask name
                //		//GetMaskName (maskName);

                //		// Update shader for surfaces that are affected by the mask
                //		UpdateSurfaceShaders (maskName.c_str ());
                //	}
                //	//else
                //	//if (!currItem.IsA (citEnvMaterial) && !currItem.IsA (citEnvironment))
                //	//	UpdateSurfaceShaders ("");
                //}

                prevItem.set(_itemUpdated[c].item);
            }

            _itemAdded.clear();
            _itemRemoved.clear();
            _itemUpdated.clear();
            _itemRemovedIdents.clear();
        }

        struct ItemChan
        {
            ILxUnknownID item;
            unsigned int chan;
        };

        /// Sort operator for items and channels of items - by pointer of item, and by index of channel
        struct SortByItem
        {
            bool operator()(const ILxUnknownID& left, const ILxUnknownID& right) const
            {
                return left < right;
            }

            bool operator()(const ItemChan& left, const ItemChan& right) const
            {
                if (left.item == right.item)
                    return left.chan < right.chan;

                return left.item < right.item;
            }
        };

        /// FindItem operator, comparing against ILxUnknownID or update ItemChan objects
        struct FindItem
        {
            ILxUnknownID item;

            FindItem(ILxUnknownID id) : item(id)
            {
            }

            explicit FindItem(const ItemChan& itemChan) : item(itemChan.item)
            {
            }

            bool operator()(const ILxUnknownID& e) const
            {
                return e == item;
            }

            bool operator()(const ItemChan& e) const
            {
                return e.item == item;
            }
        };

        typedef std::vector<ILxUnknownID>       UnknownArray;
        typedef std::vector<ItemChan>           ItemChanArray;
        typedef std::unordered_set<std::string> StringSet;

        static SceneListener* _inst;  //!< the singleton instance

        CLxRenderContext* _ctx;    //!< the externally owned CLxRenderContext for forwarding events to
        CLxUser_Scene     _scene;  //!< the currently selected scene
        double            _time;   //!< the current time on the current scene

        CLxUser_SelectionService _selSvc;     //!< service for handling selections
        LXtID4                   _sceneCode;  //!< ID for a scene

        CLxUser_Scene _newScene;  //!< if a new scene is created, this is it

        UnknownArray  _itemAdded;          //!< deferred list of items to be added
        UnknownArray  _itemRemoved;        //!< deferred list of items to be removed
        ItemChanArray _itemUpdated;        //!< deferred list of items to be updated
        StringSet     _itemRemovedIdents;  //!< list of item identifiers that have been removed (since you can't store pointers to deleted items)

        UnknownArray _gcSrfAdded;       //!< deferred list of GeoCacheSurfaces added
        UnknownArray _gcSrfRemoved;     //!< deferred list of GeoCacheSurfaces removed
        UnknownArray _gcSrfGeoUpdates;  //!< deferred list of GeoCacheSurfaces with geometry updates
        UnknownArray _gcSrfShdUpdates;  //!< deferred list of GeoCacheSurfaces with shader updates
        UnknownArray _gcSrfXfmUpdates;  //!< deferred list of GeoCacheSurfaces with transform updates
    };
}  // namespace lx

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
lx::SceneListener* lx::SceneListener::_inst = nullptr;

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
CLxRenderContext::CLxRenderContext() : _listener(nullptr)
{
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
CLxRenderContext::~CLxRenderContext()
{
    lx::SceneListener::GetInstance()->Stop();
    lx::SceneListener::ReleaseInstance();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LxResult CLxRenderContext::Init(CLxRenderContextListener* listener, unsigned rcacheFlags)
{
    _scene.clear();
    _time = 0.0f;
    _chanTime.clear();

    if (_listener)
        lx::SceneListener::GetInstance()->Stop();

    if (_rcache.test())
        _rcache.clear();

    _listener = listener;

    // Get currently selected scene
    CLxSceneSelection        sceneSel;
    CLxUser_SelectionService selSvc;
    CLxUser_Scene            scene;

    sceneSel.Get(scene);
    if (scene.test())
    {
        _scene = scene;
        _time  = selSvc.GetTime();
        _chanTime.from(_scene, _time);
    }

    // Initialize the render cache
    LxResult                   res = LXe_OK;
    CLxUser_RenderCacheService rcSvc;

    res = rcSvc.NewRenderCache(_rcache, rcacheFlags);
    if (LXx_FAIL(res))
        return res;

    // Start listener
    lx::SceneListener::GetInstance()->Start(this);

    return LXe_OK;
}

//---------------------------------------------------------------------
/**
 * Either handle scene events internally (changing current, destroying, time change)
 * or forward onto the listener (if it's been set).
 */
//---------------------------------------------------------------------
void CLxRenderContext::SetEvent(const CLxRenderContextEvent& event)
{
    bool notify     = true;
    bool clearScene = false;

    if (event.Type() == LXi_RCTX_EVT_SCENE_CURRENT)
    {
        CLxUser_Scene            scene(event.Object());
        CLxUser_SelectionService selSvc;

        if (_scene != scene)
        {
            _scene = scene;
            _time  = selSvc.GetTime();
            _chanTime.from(_scene, _time);
        }
        else
            notify = false;
    }
    else if (event.Type() == LXi_RCTX_EVT_SCENE_DESTROY)
    {
        CLxUser_Scene scene(event.Object());

        if (scene.test() && _scene == scene)
            clearScene = true;
    }
    else if (event.Type() == LXi_RCTX_EVT_SCENE_TIME_CHANGE)
    {
        if (_scene)
            _chanTime.from(_scene, event.Time());
    }

    if (_listener && notify)
        _listener->rctx_HandleEvent(event);

    if (clearScene)
    {
        _scene.clear();
        _chanTime.clear();
        _time = -1.0f;
    }
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
LxResult CLxRenderContext::Scene(CLxUser_Scene& scene)
{
    scene.set(_scene);

    return LXe_OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
LxResult CLxRenderContext::Channels(CLxUser_ChannelRead& chans)
{
    chans.set(_chanTime);

    return LXe_OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
LxResult CLxRenderContext::ChanInt(CLxUser_Item& item, const char* channel, int& value)
{
    unsigned index;

    if (_chanTime.test() && LXx_OK(item.ChannelLookup(channel, &index)))
        return _chanTime.Integer(item, index, &value);

    return LXe_FAILED;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
LxResult CLxRenderContext::ChanFlt(CLxUser_Item& item, const char* channel, float& value)
{
    unsigned index;

    if (_chanTime.test() && LXx_OK(item.ChannelLookup(channel, &index)))
    {
        double v = 0.0;

        LxResult res = _chanTime.Double(item, index, &v);
        value        = (float) v;

        return res;
    }

    return LXe_FAILED;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
LxResult CLxRenderContext::ChanDbl(CLxUser_Item& item, const char* channel, double& value)
{
    unsigned index;

    if (_chanTime.test() && LXx_OK(item.ChannelLookup(channel, &index)))
        return _chanTime.Double(item, index, &value);

    return LXe_FAILED;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
LxResult CLxRenderContext::ChanRGB(CLxUser_Item& item, const char* channel, LXtColorRGB& value)
{
    LxResult res;
    unsigned index;

    if (_chanTime.test())
    {
        char chanName[64];

        sprintf(chanName, "%s.R", channel);

        res = item.ChannelLookup(chanName, &index);

        if (LXx_OK(res))
        {
            double r, g, b;

            _chanTime.Double(item, index, &r);
            _chanTime.Double(item, index + 1, &g);
            _chanTime.Double(item, index + 2, &b);

            value[0] = (float) r;
            value[1] = (float) g;
            value[2] = (float) b;

            return res;
        }
    }

    return LXe_FAILED;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
LxResult CLxRenderContext::ChanRGBA(CLxUser_Item& item, const char* channel, LXtColorRGBA& value)
{
    LxResult res;
    unsigned index;

    if (_chanTime.test())
    {
        char chanName[64];

        sprintf(chanName, "%s.R", channel);

        res = item.ChannelLookup(chanName, &index);

        if (LXx_OK(res))
        {
            double r, g, b, a;

            _chanTime.Double(item, index, &r);
            _chanTime.Double(item, index + 1, &g);
            _chanTime.Double(item, index + 2, &b);
            _chanTime.Double(item, index + 3, &a);

            value[0] = (float) r;
            value[1] = (float) g;
            value[2] = (float) b;
            value[3] = (float) a;

            return res;
        }
    }

    return LXe_FAILED;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
LxResult CLxRenderContext::ChanStr(CLxUser_Item& item, const char* channel, const char*& value)
{
    unsigned index;

    if (_chanTime.test() && LXx_OK(item.ChannelLookup(channel, &index)))
        return _chanTime.String(item, index, &value);

    return LXe_FAILED;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
LxResult CLxRenderContext::RenderCache(CLxUser_RenderCache& rcache)
{
    if (_rcache)
    {
        rcache.set(_rcache);

        return LXe_OK;
    }

    return LXe_NOTAVAILABLE;
}

//---------------------------------------------------------------------
/// Return number of items of given type
//---------------------------------------------------------------------
int CLxRenderContext::NItems(LXtItemType type)
{
    return _scene.NItems(type);
}

//---------------------------------------------------------------------
/// Get item of given type and index
//---------------------------------------------------------------------
LxResult CLxRenderContext::GetItem(CLxUser_Item& item, int index, LXtItemType type)
{
    if (_scene.GetItem(type, index, item))
        return LXe_OK;

    return LXe_FAILED;
}

//---------------------------------------------------------------------
/// Get all items of given type
//---------------------------------------------------------------------
LxResult CLxRenderContext::GetItems(lx::UnknownArray& items, LXtItemType type)
{
    CLxUser_Item   item;
    const unsigned count = _scene.NItems(type);

    items.clear();

    if (count)
    {
        items.reserve(count);

        for (unsigned c = 0; c < count; ++c)
        {
            _scene.GetItem(type, c, item);
            items.push_back(item);
        }
    }

    return LXe_OK;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LxResult CLxRenderContext::RenderCamera(CLxCamera& cam)
{
    // Get render item
    CLxUser_Item rndr;

    _scene.AnyItemOfType(LXi_CIT_RENDER, rndr);

    // Get render camera index
    CLxUser_Item camItem;
    int          camIndex;

    camIndex = _chanTime.IValue(rndr, rndr.ChannelIndex("cameraIndex"));
    _scene.RenderCameraByIndex(camIndex, camItem);

    // if (!camItem.test())
    //	_scene.AnyItemOfType (LXi_CIT_CAMERA, camItem);

    LxResult    res;
    const char* camName;

    res = cam.Init(camItem, _chanTime);

    if (camItem.test())
        camItem.UniqueName(&camName);
    else
        camName = "DefaultCamera";

    LogInfo("resW:%d resH:%d cam:%d %s aperX:%f aperY:%f", cam.width, cam.height, camIndex, camName, cam.apertureX, cam.apertureY);

    return res;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LxResult CLxRenderContext::RenderSettings(CLxRenderSettings& rs)
{
    // Get render item
    CLxUser_Item item;

    _scene.AnyItemOfType(LXi_CIT_RENDER, item);

    return rs.Init(item, _chanTime);
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LxResult CLxRenderContext::Material(CLxUser_GeoCacheSurface& srf, CLxAdvMaterial& mat)
{
    CLxUser_Item matItem;

    // Get first material from layer stack
    CLxLayerStack stack;

    if (LXx_OK(stack.Init(srf, *this)))
        stack.GetItem(matItem, 0, citAdvancedMaterial);

    if (matItem.test())
        return mat.Init(matItem, _chanTime);

    return LXe_NOTFOUND;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LxResult CLxRenderContext::LayerStack(CLxUser_Item& item, CLxLayerStack& stack)
{
    return stack.Init(item, *this);
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LxResult CLxRenderContext::LayerStack(CLxUser_GeoCacheSurface& srf, CLxLayerStack& stack)
{
    return stack.Init(srf, *this);
}

//-----------------------------------------------------------------------------
/**
 * Helper class for getting all the items (in Shader Tree) used to shade a given item.
 * Only include items visited that are enabled and all their parents are enabled too.
 */
//-----------------------------------------------------------------------------
class ShaderVisitor : public CLxImpl_AbstractVisitor
{
public:
    ShaderVisitor(CLxUser_Shader& shader, CLxUser_ChannelRead& chan, lx::UnknownArray& items) : _shader(shader), _chans(chan), _items(items)
    {
    }

    LxResult Evaluate() override
    {
        CLxUser_Item item;

        _shader.GetShaderItem(item);

        if (item.test() && IsItemAndAllParentsEnabled(_chans, item))
        {
            _items.push_back(item);
        }

        return LXe_OK;
    }

private:
    CLxUser_Shader&      _shader;
    CLxUser_ChannelRead& _chans;
    CLxUser_SceneService _sceneSvc;

    lx::UnknownArray& _items;
};

//-----------------------------------------------------------------------------
/**
 * Helper class for getting all the items in a group
 */
//-----------------------------------------------------------------------------
class GroupVisitor : public CLxImpl_AbstractVisitor
{
public:
    GroupVisitor(CLxUser_GroupItem& group, lx::UnknownArray& items) : _items(items)
    {
        group.GetEnumerator(_grpEnum);
    }

    LxResult Evaluate() override
    {
        CLxUser_Item item;

        if (_grpEnum.GetItem(item))
            _items.push_back(item);

        return LXe_OK;
    }

    void Run()
    {
        if (_grpEnum.test())
            _grpEnum.Enum(this, LXfGRPTYPE_ITEM);
    }

private:
    CLxUser_GroupEnumerator _grpEnum;
    lx::UnknownArray&       _items;
};

//-----------------------------------------------------------------------------
/**
 * Recursive function that looks for a material tag on each item (could start from the render item
 * or an environment) and returns matching masks (material groups).
 */
//-----------------------------------------------------------------------------
void FindMasksByMaterialTag(const char* matTag, CLxUser_Item& item, CLxUser_ChannelRead& chan, lx::UnknownArray& masks)
{
    unsigned nSubs;

    item.SubCount(&nSubs);

    for (unsigned sc = 0; sc < nSubs; ++sc)
    {
        CLxUser_Item sub;

        item.SubByIndex(sc, sub);
        if (!IsItemAndAllParentsEnabled(chan, sub))
        {
            continue;
        }

        if (sub.IsA(citMask))
        {
            const char* ptag;

            chan.String(sub, sub.ChannelIndex(LXsICHAN_MASK_PTAG), &ptag);

            if (ptag && strcmp(matTag, ptag) == 0)
                masks.push_back(sub);

            FindMasksByMaterialTag(matTag, sub, chan, masks);
        }
        else if (sub.IsA(citShaderFolder))
        {
            FindMasksByMaterialTag(matTag, sub, chan, masks);
        }
    }
}

//-----------------------------------------------------------------------------
/**
 * Find all materials not in a material group that are enabled.
 */
//-----------------------------------------------------------------------------
void FindOverrideUnmaskedMaterials(const char* matTag, CLxUser_Item& item, CLxUser_ChannelRead& chan, lx::UnknownArray& unmaskedMaterials)
{
    unsigned nSubs;

    item.SubCount(&nSubs);

    // these are visited in REVERSE order of what appears in the UI
    // so override materials appear AFTER the mask has been found
    bool has_found_mask = false;
    for (unsigned sc = 0; sc < nSubs; ++sc)
    {
        CLxUser_Item sub;

        item.SubByIndex(sc, sub);
        if (!IsItemAndAllParentsEnabled(chan, sub))
        {
            continue;
        }

        if (sub.IsA(citMask))
        {
            const char* ptag;

            chan.String(sub, sub.ChannelIndex(LXsICHAN_MASK_PTAG), &ptag);

            if (ptag && strcmp(matTag, ptag) == 0)
            {
                has_found_mask = true;
            }
        }
        else if (sub.IsA(citAdvancedMaterial) && has_found_mask)
        {
            unmaskedMaterials.push_back(sub);
        }
    }
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
CLxLayerStack::CLxLayerStack()
{
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LxResult CLxLayerStack::Init(CLxUser_GeoCacheSurface& srf, CLxRenderContext& ctx)
{
    CLxUser_Item srcItem;
    const char*  matTag;

    matTag = srf.MaterialPTag();

    ctx.Channels(_chans);

    if (matTag)
    {
        CLxUser_Item rndrItem;

        ctx.GetItem(rndrItem, 0, citRender);

        lx::UnknownArray masks;

        FindMasksByMaterialTag(matTag, rndrItem, _chans, masks);
        if (masks.empty())
        {
            // May occur if no masks are enabled
            // So just get the whole shading tree
            srf.GetSourceItem(srcItem);

            if (srcItem.test())
                return Init(srcItem, ctx);
        }

        // Check if mask have parents
        for (size_t mc = 0; mc < masks.size(); ++mc)
        {
            CLxUser_Item maskItem(masks[mc]);
            CLxUser_Item parent;

            maskItem.GetParent(parent);

            while (1)
            {
                if (!parent.IsA(citMask))
                    break;

                _items.push_back(parent);

                unsigned nSubs;

                parent.SubCount(&nSubs);

                for (unsigned sc = 0; sc < nSubs; ++sc)
                {
                    CLxUser_Item subItem;

                    parent.SubByIndex(sc, subItem);

                    if (subItem == maskItem || subItem.IsA(citMask))
                        continue;

                    _items.push_back(subItem);
                }

                parent.GetParent(parent);
            }
        }

        // Add mask children
        for (size_t mc = 0; mc < masks.size(); ++mc)
        {
            CLxUser_Item maskItem(masks[mc]);

            _items.push_back(maskItem);
            AddChildren(maskItem);
        }

        // finally, add any unmasked, enabled, materials
        // that occur before the first mask in the shading tree as
        // these take precedence
        lx::UnknownArray unmaskedMaterials;
        FindOverrideUnmaskedMaterials(matTag, rndrItem, _chans, unmaskedMaterials);
        for (size_t i = 0; i < unmaskedMaterials.size(); ++i)
        {
            CLxUser_Item materialItem(unmaskedMaterials[i]);
            _items.push_back(materialItem);
        }

        return LXe_OK;
    }
    else
    {
        srf.GetSourceItem(srcItem);

        if (srcItem.test())
            return Init(srcItem, ctx);
    }

    return LXe_INVALIDARG;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LxResult CLxLayerStack::Init(CLxUser_Item& item, CLxRenderContext& ctx)
{
    ctx.Channels(_chans);

    if (item.IsA(citEnvironment))
    {
        AddChildren(item);

        return LXe_OK;
    }

    CLxUser_Shader shader(item);
    ShaderVisitor  vis(shader, _chans, _items);

    shader.Enum(&vis);

    return LXe_OK;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void CLxLayerStack::AddChildren(CLxUser_Item& item)
{
    CLxUser_Item sub;
    unsigned     count;

    item.SubCount(&count);

    for (int c = 0; c < count; ++c)
    {
        item.SubByIndex(c, sub);

        // Skip disabled items in shader tree
        if (!IsEnabled(sub))
            continue;

        _items.push_back(sub);

        AddChildren(sub);
    }
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
int CLxLayerStack::NItems(LXtItemType type) const
{
    int count = 0;

    if (type == LXiTYPE_ANY)
        count = (int) _items.size();
    else
    {
        for (size_t c = 0; c < _items.size(); ++c)
        {
            CLxUser_Item item(_items[c]);

            if (item.IsA(type))
                ++count;
        }
    }

    return count;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LxResult CLxLayerStack::GetItem(CLxUser_Item& item, int itemIndex, LXtItemType type) const
{
    LxResult res = LXe_NOTFOUND;

    // Skip searching if type is not set
    if (type == LXiTYPE_ANY)
    {
        if (itemIndex < (int) _items.size())
        {
            item.set(_items[itemIndex]);
            res = LXe_OK;
        }
        else
            item.clear();

        return res;
    }

    const int    count = (int) _items.size();
    int          curr  = 0;
    CLxUser_Item currItem;

    item.clear();

    for (int ic = 0; ic < count; ++ic)
    {
        currItem.set(_items[ic]);

        if (currItem.IsA(type))
        {
            if (curr == itemIndex)
            {
                item.set(currItem);

                return LXe_OK;
            }

            ++curr;
        }
    }

    return res;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LxResult CLxLayerStack::GetItems(lx::UnknownArray& itemArray, LXtItemType type) const
{
    const int    count = NItems(type);
    CLxUser_Item item;
    LxResult     res = LXe_FAILED;

    itemArray.clear();

    if (type == LXiTYPE_ANY)
    {
        std::copy(_items.begin(), _items.end(), std::back_inserter(itemArray));
        return LXe_OK;
    }

    for (int c = 0; c < count; ++c)
    {
        res = GetItem(item, c, type);
        if (LXx_FAIL(res))
            break;

        itemArray.push_back(item);
    }

    return res;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
int CLxLayerStack::NMasks() const
{
    return NItems(citMask);
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LxResult CLxLayerStack::GetMask(CLxUser_Item& mask, int index) const
{
    mask.clear();

    return GetItem(mask, index, citMask);
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LxResult CLxLayerStack::GetMask(CLxUser_Item& mask, int index, LXtItemType types[], lx::UnknownArray* typeItems[], unsigned nTypes) const
{
    LxResult     res;
    unsigned     subCount;
    CLxUser_Item sub;

    mask.clear();

    for (unsigned tc = 0; tc < nTypes; ++tc)
        typeItems[tc]->clear();

    res = GetItem(mask, index, citMask);
    if (LXx_OK(res))
    {
        mask.SubCount(&subCount);

        for (unsigned c = 0; c < subCount; ++c)
        {
            mask.GetSubItem(subCount - 1 - c, sub);

            if (!IsEnabled(sub))
                continue;

            for (unsigned tc = 0; tc < nTypes; ++tc)
            {
                if (sub.IsA(types[tc]))
                    typeItems[tc]->push_back(sub);
            }
        }
    }

    return res;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LxResult CLxLayerStack::GetMask(CLxUser_Item& mask, int index, lx::UnknownArray& children) const
{
    LxResult     res;
    unsigned     subCount;
    CLxUser_Item sub;

    mask.clear();

    res = GetItem(mask, index, citMask);
    if (LXx_OK(res))
    {
        mask.SubCount(&subCount);

        for (unsigned c = 0; c < subCount; ++c)
        {
            mask.GetSubItem(subCount - 1 - c, sub);

            if (!IsEnabled(sub))
                continue;

            children.push_back(sub);
        }
    }

    return res;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LxResult CLxLayerStack::GetImage(CLxUser_Item& item, const char* fxName) const
{
    LxResult    res   = LXe_NOTFOUND;
    const int   count = (int) _items.size();
    const char* effect;

    for (int ic = 0; ic < count; ++ic)
    {
        res = GetItem(item, ic, citImageMap);

        if (LXx_OK(res))
        {
            if (!IsEnabled(item))
                continue;

            if (fxName)
            {
                _chans.String(item, item.ChannelIndex(LXsICHAN_TEXTURELAYER_EFFECT), &effect);

                if (strcmp(fxName, effect) == 0)
                {
                    res = LXe_OK;
                    break;
                }
            }
        }
    }

    if (LXx_FAIL(res))
        item.clear();

    return res;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
bool CLxLayerStack::IsEnabled(CLxUser_Item& item) const
{
    int  chanEnable;
    bool enabled = true;

    chanEnable = item.ChannelIndex(LXsICHAN_TEXTURELAYER_ENABLE);

    if (chanEnable >= 0)
        enabled = _chans.IValue(item, chanEnable) > 0;

    return enabled;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void CLxLayerStack::Print()
{
    CLxUser_Item         item;
    const char*          name;
    const char*          typeName;
    CLxUser_SceneService sceneSvc;
    const size_t         count = _items.size();

    LogInfo("Layer stack has %d item(s)", (int) _items.size());

    for (size_t c = 0; c < count; ++c)
    {
        item.set(_items[count - 1 - c]);

        item.UniqueName(&name);
        sceneSvc.ItemTypeName(item.Type(), &typeName);

        LogInfo("%s type:%s", name, typeName);
    }
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LxResult CLxRenderSettings::Init(CLxUser_Item& item, CLxUser_ChannelRead& chan)
{
    if (LXx_FAIL(TestItemType(item, citRender)))
        return LXe_INVALIDARG;

    renderType = chan.IValue(item, LXsICHAN_POLYRENDER_RENDTYPE);
    aa         = chan.IValue(item, LXsICHAN_POLYRENDER_AA);
    aaFilter   = chan.IValue(item, LXsICHAN_POLYRENDER_AAFILTER);
    aaImpMin   = static_cast<float>(chan.FValue(item, LXsICHAN_POLYRENDER_AAIMPMIN));
    coarseRate = static_cast<float>(chan.FValue(item, LXsICHAN_POLYRENDER_COARSERATE));
    fineRate   = static_cast<float>(chan.FValue(item, LXsICHAN_POLYRENDER_FINERATE));
    fineThresh = static_cast<float>(chan.FValue(item, LXsICHAN_POLYRENDER_FINETHRESH));
    bktRefine  = chan.IValue(item, LXsICHAN_POLYRENDER_BKTREFINE);
    aRefine    = chan.IValue(item, LXsICHAN_POLYRENDER_AREFINE);
    mergeRad   = chan.IValue(item, LXsICHAN_POLYRENDER_MERGERAD);
    field      = chan.IValue(item, LXsICHAN_POLYRENDER_FIELD);
    bucketX    = chan.IValue(item, LXsICHAN_POLYRENDER_BUCKETX);
    bucketY    = chan.IValue(item, LXsICHAN_POLYRENDER_BUCKETY);
    bktOrder   = chan.IValue(item, LXsICHAN_POLYRENDER_BKTORDER);
    bktReverse = chan.IValue(item, LXsICHAN_POLYRENDER_BKTREVERSE);
    bktWrite   = chan.IValue(item, LXsICHAN_POLYRENDER_BKTWRITE);
    bktSkip    = chan.IValue(item, LXsICHAN_POLYRENDER_BKTSKIP);
    frmPasses  = chan.IValue(item, LXsICHAN_POLYRENDER_FRMPASSES);
    bakeDir    = chan.IValue(item, LXsICHAN_POLYRENDER_BAKEDIR);
    progConv   = static_cast<float>(chan.FValue(item, LXsICHAN_POLYRENDER_PROGCONV));
    progTime   = static_cast<float>(chan.FValue(item, LXsICHAN_POLYRENDER_PROGTIME));

    outputMasking = chan.IValue(item, LXsICHAN_POLYRENDER_OUTPUTMASK);

    ambColor[0] = static_cast<float>(chan.FValue(item, LXsICHAN_RENDER_AMBCOLOR ".R"));
    ambColor[1] = static_cast<float>(chan.FValue(item, LXsICHAN_RENDER_AMBCOLOR ".G"));
    ambColor[2] = static_cast<float>(chan.FValue(item, LXsICHAN_RENDER_AMBCOLOR ".B"));
    ambRad      = static_cast<float>(chan.FValue(item, LXsICHAN_RENDER_AMBRAD));

    globEnable = chan.IValue(item, LXsICHAN_RENDER_GLOBENABLE);
    globScope  = chan.IValue(item, LXsICHAN_RENDER_GLOBSCOPE);
    globLimit  = chan.IValue(item, LXsICHAN_RENDER_GLOBLIMIT);
    globRays   = chan.IValue(item, LXsICHAN_RENDER_GLOBRAYS);
    globRange  = static_cast<float>(chan.FValue(item, LXsICHAN_RENDER_GLOBRANGE));
    globSubs   = chan.IValue(item, LXsICHAN_RENDER_GLOBSUBS);
    globVols   = chan.IValue(item, LXsICHAN_RENDER_GLOBVOLS);
    globBump   = chan.IValue(item, LXsICHAN_RENDER_GLOBBUMP);
    globSuper  = chan.IValue(item, LXsICHAN_RENDER_GLOBSUPER);
    globReject = chan.IValue(item, LXsICHAN_RENDER_GLOBREJECT);
    globCaus   = chan.IValue(item, LXsICHAN_RENDER_GLOBCAUS);

    irrCache   = chan.IValue(item, LXsICHAN_RENDER_IRRCACHE);
    irrUsage   = chan.IValue(item, LXsICHAN_RENDER_IRRUSAGE);
    irrDirect2 = chan.IValue(item, LXsICHAN_RENDER_IRRDIRECT2);
    irrRays    = chan.IValue(item, LXsICHAN_RENDER_IRRRAYS);
    irrRays2   = chan.IValue(item, LXsICHAN_RENDER_IRRRAYS2);
    irrRate    = chan.IValue(item, LXsICHAN_RENDER_IRRRATE);
    irrRatio   = chan.IValue(item, LXsICHAN_RENDER_IRRRATIO);
    irrSmooth  = chan.IValue(item, LXsICHAN_RENDER_IRRSMOOTH);
    irrRetrace = chan.IValue(item, LXsICHAN_RENDER_IRRRETRACE);
    irrVals    = chan.IValue(item, LXsICHAN_RENDER_IRRVALS);
    irrGrads   = chan.IValue(item, LXsICHAN_RENDER_IRRGRADS);
    irrSample  = chan.IValue(item, LXsICHAN_RENDER_IRRSAMPLE);
    irrData    = chan.IValue(item, LXsICHAN_RENDER_IRRDATA);
    irrStart   = chan.IValue(item, LXsICHAN_RENDER_IRRSTART);
    irrEnd     = chan.IValue(item, LXsICHAN_RENDER_IRREND);
    irrWalk    = chan.IValue(item, LXsICHAN_RENDER_IRRWALK);
    irrLEnable = chan.IValue(item, LXsICHAN_RENDER_IRRLENABLE);

    chan.String(item, item.ChannelIndex(LXsICHAN_RENDER_IRRLNAME), &irssLName);

    irrSEnable = chan.IValue(item, LXsICHAN_RENDER_IRRSENABLE);

    chan.String(item, item.ChannelIndex(LXsICHAN_RENDER_IRRSNAME), &irssSName);

    radCache = chan.IValue(item, LXsICHAN_RENDER_RADCACHE);

    envSample = chan.IValue(item, LXsICHAN_RENDER_ENVSAMPLE);
    envRays   = chan.IValue(item, LXsICHAN_RENDER_ENVRAYS);
    envMIS    = chan.IValue(item, LXsICHAN_RENDER_ENVMIS);

    causEnable = chan.IValue(item, LXsICHAN_RENDER_CAUSENABLE);
    causMult   = static_cast<float>(chan.FValue(item, LXsICHAN_RENDER_CAUSMULT));
    causTotal  = chan.IValue(item, LXsICHAN_RENDER_CAUSTOTAL);
    causLocal  = chan.IValue(item, LXsICHAN_RENDER_CAUSLOCAL);
    causWalk   = chan.IValue(item, LXsICHAN_RENDER_CAUSWALK);

    rayShadow  = chan.IValue(item, LXsICHAN_RENDER_RAYSHADOW);
    reflDepth  = chan.IValue(item, LXsICHAN_RENDER_REFLDEPTH);
    refrDepth  = chan.IValue(item, LXsICHAN_RENDER_REFRDEPTH);
    rayThresh  = static_cast<float>(chan.FValue(item, LXsICHAN_RENDER_RAYTHRESH));
    unbiased   = chan.IValue(item, LXsICHAN_RENDER_UNBIASED);
    rayClamp   = static_cast<float>(chan.FValue(item, LXsICHAN_RENDER_RAYCLAMP));
    rayOffset  = static_cast<float>(chan.FValue(item, LXsICHAN_RENDER_RAYOFFSET));
    reflSmps   = chan.IValue(item, LXsICHAN_RENDER_REFLSMPS);
    refrSmps   = chan.IValue(item, LXsICHAN_RENDER_REFRSMPS);
    specSmps   = chan.IValue(item, LXsICHAN_RENDER_SPECSMPS);
    subsSmps   = chan.IValue(item, LXsICHAN_RENDER_SUBSSMPS);
    animNoise  = chan.IValue(item, LXsICHAN_RENDER_ANIMNOISE);
    noiseSeed  = chan.IValue(item, LXsICHAN_RENDER_NOISESEED);
    rayAccel   = chan.IValue(item, LXsICHAN_RENDER_RAYACCEL);
    batchSize  = chan.IValue(item, LXsICHAN_RENDER_BATCHSIZE);
    impBoost   = chan.IValue(item, LXsICHAN_RENDER_IMPBOOST);
    directSmps = chan.IValue(item, LXsICHAN_RENDER_DIRECTSMPS);
    directMIS  = chan.IValue(item, LXsICHAN_RENDER_DIRECTMIS);
    multiGeo   = chan.IValue(item, LXsICHAN_RENDER_MULTIGEO);
    mergeFur   = chan.IValue(item, LXsICHAN_RENDER_MERGEFUR);
    subdAdapt  = chan.IValue(item, LXsICHAN_RENDER_SUBDADAPT);
    subdRate   = static_cast<float>(chan.FValue(item, LXsICHAN_RENDER_SUBDRATE));
    dispEnable = chan.IValue(item, LXsICHAN_RENDER_DISPENABLE);
    dispRate   = static_cast<float>(chan.FValue(item, LXsICHAN_RENDER_DISPRATE));
    dispRatio  = static_cast<float>(chan.FValue(item, LXsICHAN_RENDER_DISPRATIO));
    dispJitter = static_cast<float>(chan.FValue(item, LXsICHAN_RENDER_DISPJITTER));
    edgeMin    = static_cast<float>(chan.FValue(item, LXsICHAN_RENDER_EDGEMIN));
    dispSmooth = chan.IValue(item, LXsICHAN_RENDER_DISPSMOOTH);
    dispBump   = chan.IValue(item, LXsICHAN_RENDER_DISPBUMP);

    camera = 0;

    return LXe_OK;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
CLxLightMaterial::CLxLightMaterial()
{
    // Set default light values
    LXx_VSET3(color, 1.0, 1.0, 1.0);

    diffuse    = 1.0f;
    specular   = 1.0f;
    caustics   = 1.0f;
    subsurface = 1.0f;

    LXx_VSET3(shadCol, 0, 0, 0);
    LXx_VSET3(scatCol, 1.0, 1.0, 1.0);

    scatter   = 1.0f;
    density   = 0.5f;
    attenuate = 0.1f;
    shift     = 0.0f;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LxResult CLxLightMaterial::Init(CLxUser_Item& item, CLxUser_ChannelRead& chan)
{
    if (LXx_FAIL(TestItemType(item, citLightMaterial)))
        return LXe_INVALIDARG;

    color[0] = static_cast<float>(chan.FValue(item, LXsICHAN_LIGHTMATERIAL_LIGHTCOL ".R"));
    color[1] = static_cast<float>(chan.FValue(item, LXsICHAN_LIGHTMATERIAL_LIGHTCOL ".G"));
    color[2] = static_cast<float>(chan.FValue(item, LXsICHAN_LIGHTMATERIAL_LIGHTCOL ".B"));

    diffuse    = static_cast<float>(chan.FValue(item, LXsICHAN_LIGHTMATERIAL_DIFFUSE));
    specular   = static_cast<float>(chan.FValue(item, LXsICHAN_LIGHTMATERIAL_SPECULAR));
    caustics   = static_cast<float>(chan.FValue(item, LXsICHAN_LIGHTMATERIAL_CAUSTICS));
    subsurface = static_cast<float>(chan.FValue(item, LXsICHAN_LIGHTMATERIAL_SUBSURF));

    shadCol[0] = static_cast<float>(chan.FValue(item, LXsICHAN_LIGHTMATERIAL_SHADCOL ".R"));
    shadCol[1] = static_cast<float>(chan.FValue(item, LXsICHAN_LIGHTMATERIAL_SHADCOL ".G"));
    shadCol[2] = static_cast<float>(chan.FValue(item, LXsICHAN_LIGHTMATERIAL_SHADCOL ".B"));

    scatCol[0] = static_cast<float>(chan.FValue(item, LXsICHAN_LIGHTMATERIAL_SCATCOL ".R"));
    scatCol[1] = static_cast<float>(chan.FValue(item, LXsICHAN_LIGHTMATERIAL_SCATCOL ".G"));
    scatCol[2] = static_cast<float>(chan.FValue(item, LXsICHAN_LIGHTMATERIAL_SCATCOL ".B"));

    scatter   = static_cast<float>(chan.FValue(item, LXsICHAN_LIGHTMATERIAL_SCATTER));
    density   = static_cast<float>(chan.FValue(item, LXsICHAN_LIGHTMATERIAL_DENSITY));
    attenuate = static_cast<float>(chan.FValue(item, LXsICHAN_LIGHTMATERIAL_ATTENUATE));
    shift     = static_cast<float>(chan.FValue(item, LXsICHAN_LIGHTMATERIAL_SHIFT));

    return LXe_OK;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LxResult CLxLight::Init(CLxUser_Item& item, CLxUser_ChannelRead& chan)
{
    if (LXx_FAIL(TestItemType(item, citLight)))
        return LXe_INVALIDARG;

    lightItem = item;

    CLxUser_Item lightMat;

    GetLightMaterialFromLight(item, lightMat);

    // NOTE: if lightMat is not found, it's going to have default values
    material.Init(lightMat, chan);

    {
        CLxUser_Locator loc(item);
        loc.WorldTransform(chan, xfrm, wpos);
    }

    radiance   = static_cast<float>(chan.FValue(item, LXsICHAN_LIGHT_RADIANCE));
    fallType   = chan.IValue(item, LXsICHAN_LIGHT_FALLTYPE);
    range      = static_cast<float>(chan.FValue(item, LXsICHAN_LIGHT_RANGE));
    shadType   = chan.IValue(item, LXsICHAN_LIGHT_SHADTYPE);
    shadRes    = chan.IValue(item, LXsICHAN_LIGHT_SHADRES);
    shadSpot   = static_cast<float>(chan.FValue(item, LXsICHAN_LIGHT_SHADSPOT));
    samples    = chan.IValue(item, LXsICHAN_LIGHT_SAMPLES);
    importance = static_cast<float>(chan.FValue(item, LXsICHAN_LIGHT_IMPORTANCE));
    visCam     = chan.IValue(item, LXsICHAN_LIGHT_VISCAM);
    visRefl    = chan.IValue(item, LXsICHAN_LIGHT_VISREFL);
    visRefr    = chan.IValue(item, LXsICHAN_LIGHT_VISREFR);
    target     = static_cast<float>(chan.FValue(item, LXsICHAN_LIGHT_TARGET));
    //	linkEnable	= chan.IValue (item, LXsICHAN_LIGHT_LINKENABLE);
    //	linkMode	= chan.IValue (item, LXsICHAN_LIGHT_LINKMODE);

    return LXe_OK;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LxResult CLxSunLight::Init(CLxUser_Item& item, CLxUser_ChannelRead& chan)
{
    if (LXx_FAIL(TestItemType(item, citSunLight)))
        return LXe_INVALIDARG;

    CLxLight::Init(item, chan);

    spread  = static_cast<float>(chan.FValue(item, LXsICHAN_SUNLIGHT_SPREAD));
    mapSize = static_cast<float>(chan.FValue(item, LXsICHAN_SUNLIGHT_MAPSIZE));

    // Below are physical sun channels
    sunPos       = chan.IValue(item, LXsICHAN_SUNLIGHT_SUNPOS);
    lon          = static_cast<float>(chan.FValue(item, LXsICHAN_SUNLIGHT_LON));
    lat          = static_cast<float>(chan.FValue(item, LXsICHAN_SUNLIGHT_LAT));
    day          = (int) chan.FValue(item, LXsICHAN_SUNLIGHT_DAY);
    time         = static_cast<float>(chan.FValue(item, LXsICHAN_SUNLIGHT_TIME));
    azimuth      = static_cast<float>(chan.FValue(item, LXsICHAN_SUNLIGHT_AZIMUTH));
    elevation    = static_cast<float>(chan.FValue(item, LXsICHAN_SUNLIGHT_ELEVATION));
    haze         = static_cast<float>(chan.FValue(item, LXsICHAN_SUNLIGHT_HAZE));
    clamp        = chan.IValue(item, LXsICHAN_SUNLIGHT_CLAMP);
    north        = static_cast<float>(chan.FValue(item, LXsICHAN_SUNLIGHT_NORTH));
    timeZone     = static_cast<float>(chan.FValue(item, LXsICHAN_SUNLIGHT_TIMEZONE));
    height       = static_cast<float>(chan.FValue(item, LXsICHAN_SUNLIGHT_DISTANCE));
    radius       = static_cast<float>(chan.FValue(item, LXsICHAN_SUNLIGHT_RADIUS));
    thinning     = chan.IValue(item, LXsICHAN_SUNLIGHT_THINNING);
    summerTime   = chan.IValue(item, LXsICHAN_SUNLIGHT_SUMMERTIME);
    gamma        = static_cast<float>(chan.FValue(item, LXsICHAN_SUNLIGHT_GAMMA));
    useWorldXfrm = chan.IValue(item, LXsICHAN_SUNLIGHT_USEWORLDXFORM);

    return LXe_OK;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
int CLxSunLight::GetDate(const int date)
{
    double t, dt = date;
    int    y;

    t = dt * 0.001;  // year shifted 3 dec. places (mult by 1000)
    y = (int) t;
    t = dt - (y * 1000);

    // Neb was originally using a local DOYToDOM, which was close to, but subtly different
    // to vmath.qq: DOYToDOM - this returned a day, month and year, but was unused in the
    // RPR code

    return (int) t;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LxResult CLxPointLight::Init(CLxUser_Item& item, CLxUser_ChannelRead& chan)
{
    if (LXx_FAIL(TestItemType(item, citPointLight)))
        return LXe_INVALIDARG;

    CLxLight::Init(item, chan);

    radius = static_cast<float>(chan.FValue(item, LXsICHAN_POINTLIGHT_RADIUS));
    vrad   = static_cast<float>(chan.FValue(item, LXsICHAN_POINTLIGHT_VRAD));

    return LXe_OK;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LxResult CLxSpotLight::Init(CLxUser_Item& item, CLxUser_ChannelRead& chan)
{
    if (LXx_FAIL(TestItemType(item, citSpotLight)))
        return LXe_INVALIDARG;

    CLxLight::Init(item, chan);

    radius  = static_cast<float>(chan.FValue(item, LXsICHAN_SPOTLIGHT_RADIUS));
    cone    = static_cast<float>(chan.FValue(item, LXsICHAN_SPOTLIGHT_CONE));
    edge    = static_cast<float>(chan.FValue(item, LXsICHAN_SPOTLIGHT_EDGE));
    outside = chan.IValue(item, LXsICHAN_SPOTLIGHT_OUTSIDE);
    height  = static_cast<float>(chan.FValue(item, LXsICHAN_SPOTLIGHT_HEIGHT));
    base    = static_cast<float>(chan.FValue(item, LXsICHAN_SPOTLIGHT_BASE));

    return LXe_OK;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LxResult CLxAreaLight::Init(CLxUser_Item& item, CLxUser_ChannelRead& chan)
{
    if (LXx_FAIL(TestItemType(item, citAreaLight)))
        return LXe_INVALIDARG;

    CLxLight::Init(item, chan);

    shape  = chan.IValue(item, LXsICHAN_AREALIGHT_SHAPE);
    height = static_cast<float>(chan.FValue(item, LXsICHAN_AREALIGHT_HEIGHT));
    width  = static_cast<float>(chan.FValue(item, LXsICHAN_AREALIGHT_WIDTH));

    return LXe_OK;
}

//-----------------------------------------------------------------------------
/**
 * Visitor class to enumerate vertex properties of a surface in order to
 * fetch positions, normals and triangle indices.
 */
//-----------------------------------------------------------------------------
class SrfVisitor : public CLxSurfaceVisitor
{
public:
    SrfVisitor(CLxMeshLight::Geo& geo) : _geo(geo), _segStart(0), _indPos(-1), _indNrm(-1)
    {
        _geo.nTris = 0;
        _geo.nVrts = 0;
    }

    bool InitFeatures()
    {
        CLxUser_TableauVertex& tblVert = Features();
        unsigned               index;
        LxResult               res;

        res = tblVert.AddFeature(LXiTBLX_BASEFEATURE, LXsTBLX_FEATURE_POS, &index);
        if (LXx_FAIL(res))
            return false;

        _indPos = (int) index;

        res = tblVert.AddFeature(LXiTBLX_BASEFEATURE, LXsTBLX_FEATURE_NORMAL, &index);
        if (LXx_FAIL(res))
            return false;

        _indNrm = (int) index;

        return true;
    }

    bool StartSegment(unsigned int /*segID*/, unsigned int /*type*/) override
    {
        _segStart = _geo.nVrts;

        return true;
    }

    void Vertex(const float* vertex, unsigned int /*index*/) override
    {
        _geo.vPos->push_back(vertex[_indPos]);
        _geo.vPos->push_back(vertex[_indPos + 1]);
        _geo.vPos->push_back(vertex[_indPos + 2]);

        if (_indNrm >= 0 && _geo.vNrm)
        {
            _geo.vNrm->push_back(vertex[_indNrm]);
            _geo.vNrm->push_back(vertex[_indNrm + 1]);
            _geo.vNrm->push_back(vertex[_indNrm + 2]);
        }

        _geo.nVrts++;
    }

    void Triangle(unsigned int v0, unsigned int v1, unsigned int v2) override
    {
        _geo.tris->push_back(v0 + _segStart);
        _geo.tris->push_back(v1 + _segStart);
        _geo.tris->push_back(v2 + _segStart);

        _geo.nTris++;
    }

private:
    CLxMeshLight::Geo& _geo;

    unsigned _segStart;
    int      _indPos;
    int      _indNrm;
};

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LxResult CLxMeshLight::Init(CLxUser_Item& item, CLxUser_ChannelRead& chan)
{
    if (LXx_FAIL(TestItemType(item, citMeshLight)))
        return LXe_INVALIDARG;

    CLxLight::Init(item, chan);

    meshItem = {};

    // Get connected mesh
    CLxUser_Scene     scene;
    CLxUser_ItemGraph shadeGraph;

    item.GetContext(scene);
    shadeGraph.from(scene, LXsGRAPH_SHADELOC);

    CLxUser_Item mesh;

    shadeGraph.Forward(item, 0, mesh);

    if (mesh.test())
        meshItem = mesh;

    return LXe_OK;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LxResult CLxMeshLight::PrepareGeo(CLxUser_ChannelRead& chan)
{
    if (!meshItem)
        return LXe_NOTFOUND;

    // Get surface for the light mesh, this way we get the triangulated mesh
    CLxUser_SurfaceItem srfItem;
    CLxUser_Surface     surf;

    if (!srfItem.set(meshItem))
        return LXe_FAILED;

    srfItem.GetSurface(chan, 0, surf);

    if (!surf.test())
        return LXe_FAILED;

    LxResult res;
    unsigned nBins;

    res = surf.BinCount(&nBins);
    if (LXx_FAIL(res))
        return res;

    for (unsigned bc = 0; bc < nBins; ++bc)
    {
        CLxUser_SurfaceBin bin;

        res = surf.GetBin(bc, bin);
        if (LXx_FAIL(res))
            return res;
    }

    return res;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LxResult CLxMeshLight::GetGeo(CLxUser_ChannelRead& chan, CLxMeshLight::Geo& geo)
{
    if (!meshItem)
        return LXe_NOTFOUND;

    if (geo.vPos == nullptr || geo.tris == nullptr)
        return LXe_INVALIDARG;

    // Get surface for the light mesh, this way we get the triangulated mesh
    CLxUser_SurfaceItem srfItem;
    CLxUser_Surface     surf;

    if (!srfItem.set(meshItem))
        return LXe_FAILED;

    srfItem.GetSurface(chan, 0, surf);

    if (!surf.test())
        return LXe_FAILED;

    // Create surface visitor that will collect the geometry data (triangles)
    SrfVisitor vis(geo);

    vis.SetSurface(surf);
    vis.InitFeatures();
    vis.AllowQuads(false);

    return vis.Sample();
}

//---------------------------------------------------------------------
// Initialize the default render camera (if there's no camera in the scene)
//---------------------------------------------------------------------
CLxCamera::CLxCamera()
{
    item        = nullptr;
    focalLength = 0.035f;
    filmFit     = 0;
    blurLength  = 0;
    blurOffset  = 0;
    apertureX   = 0;  // TODO:
    apertureY   = 0;  // TODO:
    offsetX     = 0;
    offsetY     = 0;
    squeeze     = 0;
    focusDist   = 0;
    fStop       = 1.0f;
    irisBlades  = 0;
    irisRot     = 0;
    irisBias    = 0;
    distort     = 0;
    ioDist      = 0;
    convDist    = 0;
    projType    = 0;  // LXiICVAL_CAMERA_PROJTYPE_PERSP
    target      = 0;
    clipDist    = 0;
    clipping    = 0;
    overscan    = 0;
    filmRoll    = 0;
    useMask     = 0;

    LXx_VCLR(eyePos);
    lx::MatrixIdent(xfrm);
    lx::MatrixIdent(invXfrm);
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LxResult CLxCamera::Init(CLxUser_Item& cam, CLxUser_ChannelRead& chan)
{
    if (LXx_FAIL(TestItemType(cam, citCamera)))
        return LXe_INVALIDARG;

    item = cam;

    // Get render item
    CLxUser_Scene scene;
    CLxUser_Item  rndr;

    cam.GetContext(scene);
    scene.AnyItemOfType(LXi_CIT_RENDER, rndr);

    // TODO: This is not reading the resolution override by camera
    if (rndr.test())
    {
        width       = chan.IValue(rndr, LXsICHAN_POLYRENDER_RESX);
        height      = chan.IValue(rndr, LXsICHAN_POLYRENDER_RESY);
        pixelAspect = static_cast<float>(chan.FValue(rndr, LXsICHAN_POLYRENDER_PASPECT));
        dpi         = static_cast<float>(chan.FValue(rndr, LXsICHAN_POLYRENDER_DPI));
        regX0       = 0.0f;
        regX1       = 1.0f;
        regY0       = 0.0f;
        regY1       = 1.0f;
    }

    focalLength = static_cast<float>(chan.FValue(cam, LXsICHAN_CAMERA_FOCALLEN));
    dof         = chan.IValue(cam, LXsICHAN_CAMERA_DOF);
    filmFit     = chan.IValue(cam, LXsICHAN_CAMERA_FILMFIT);
    blurLength  = static_cast<float>(chan.FValue(cam, LXsICHAN_CAMERA_BLURLEN));
    blurOffset  = static_cast<float>(chan.FValue(cam, LXsICHAN_CAMERA_BLUROFF));
    apertureX   = static_cast<float>(chan.FValue(cam, LXsICHAN_CAMERA_APERTUREX));
    apertureY   = static_cast<float>(chan.FValue(cam, LXsICHAN_CAMERA_APERTUREY));
    offsetX     = static_cast<float>(chan.FValue(cam, LXsICHAN_CAMERA_OFFSETX));
    offsetY     = static_cast<float>(chan.FValue(cam, LXsICHAN_CAMERA_OFFSETY));
    squeeze     = static_cast<float>(chan.FValue(cam, LXsICHAN_CAMERA_SQUEEZE));
    focusDist   = static_cast<float>(chan.FValue(cam, LXsICHAN_CAMERA_FOCUSDIST));
    fStop       = static_cast<float>(chan.FValue(cam, LXsICHAN_CAMERA_FSTOP));
    irisBlades  = chan.IValue(cam, LXsICHAN_CAMERA_IRISBLADES);
    irisRot     = static_cast<float>(chan.FValue(cam, LXsICHAN_CAMERA_IRISROTATION));
    irisBias    = static_cast<float>(chan.FValue(cam, LXsICHAN_CAMERA_IRISBIAS));
    distort     = static_cast<float>(chan.FValue(cam, LXsICHAN_CAMERA_DISTORT));
    ioDist      = static_cast<float>(chan.FValue(cam, LXsICHAN_CAMERA_IODIST));
    convDist    = static_cast<float>(chan.FValue(cam, LXsICHAN_CAMERA_CONVDIST));
    projType    = chan.IValue(cam, LXsICHAN_CAMERA_PROJTYPE);
    target      = static_cast<float>(chan.FValue(cam, LXsICHAN_CAMERA_TARGET));
    clipDist    = static_cast<float>(chan.FValue(cam, LXsICHAN_CAMERA_CLIPDIST));
    clipping    = chan.IValue(cam, LXsICHAN_CAMERA_CLIPPING);
    overscan    = static_cast<float>(chan.FValue(cam, LXsICHAN_CAMERA_OVERSCAN));
    useMask     = chan.IValue(cam, LXsICHAN_CAMERA_USEMASK);
    filmRoll    = static_cast<float>(chan.FValue(cam, LXsICHAN_CAMERA_FILMROLL));

    lx::MatrixIdent(xfrm);
    lx::MatrixIdent(invXfrm);

    CLxUser_Locator loc(cam);
    LXtMatrix       m3;
    LXtMatrix4      m4;
    LxResult        res = LXe_OK;

    if (loc.test())
    {
        res = loc.WorldTransform4(chan, m4);

        if (LXx_OK(res))
        {
            lx::Matrix4GetSubMatrix(m4, m3, true);

            // lx::MatrixTranspose (m3);
            // lx::MatrixNormalize (m3);
            // lx::MatrixTranspose (m3);

            lx::MatrixCopy(xfrm, m3);

            lx::Matrix4GetTranslation(m4, eyePos);

            // TODO: There's no MatrixInverse() in SDK for LXtMatrix only LXtMatrix4 ?
            m4[3][0] = 0.0;
            m4[3][1] = 0.0;
            m4[3][2] = 0.0;

            LXtMatrix4 m4Inv;

            lx::MatrixInvert(m4, m4Inv);
            lx::Matrix4GetSubMatrix(m4Inv, invXfrm, true);
        }
    }

    return LXe_OK;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LxResult CLxTextureLayer::Init(CLxUser_Item& layer, CLxUser_ChannelRead& chan)
{
    if (LXx_FAIL(TestItemType(layer, citTextureLayer)))
        return LXe_INVALIDARG;

    enable  = chan.IValue(layer, LXsICHAN_TEXTURELAYER_ENABLE);
    opacity = static_cast<float>(chan.FValue(layer, LXsICHAN_TEXTURELAYER_OPACITY));
    blend   = chan.IValue(layer, LXsICHAN_TEXTURELAYER_BLEND);
    invert  = chan.IValue(layer, LXsICHAN_TEXTURELAYER_INVERT);
    effect  = nullptr;

#ifdef _DEBUG
    const char* typeName;
    CLxUser_SceneService().ItemTypeName(layer.Type(), &typeName);
#endif

    // Handle position, rotation and scale gradient in shader tree (they don't have effect channel)
    const int idx = layer.ChannelIndex(LXsICHAN_TEXTURELAYER_EFFECT);

    if (idx >= 0)
        chan.String(layer, idx, &effect);

    return LXe_OK;
}

//-----------------------------------------------------------------------------
// Initialize material to default values
//-----------------------------------------------------------------------------
CLxAdvMaterial::CLxAdvMaterial()
{
    diffCol[0] = diffCol[1] = diffCol[2] = 0.6f;
    diffAmt                              = 0.8f;
    specCol[0] = specCol[1] = specCol[2] = 1.f;
    specAmt                              = 0.04f;
    reflCol[0] = reflCol[1] = reflCol[2] = 1.f;
    reflAmt                              = 0.f;
    tranCol[0] = tranCol[1] = tranCol[2] = 1.f;
    tranAmt                              = 0.f;
    subsCol[0] = subsCol[1] = subsCol[2] = 0.8f;
    subsAmt                              = 0.f;
    lumiCol[0] = lumiCol[1] = lumiCol[2] = 1.f;
    radiance                             = 0.f;
    exitCol[0] = exitCol[1] = exitCol[2] = 0.f;
    coatAmt                              = 0.f;
    dissAmt                              = 0.f;
    diffRough                            = 0.f;
    rough                                = 0.4f;
    coatRough                            = 0.f;
    coatBump                             = 1.f;
    aniso                                = 0.f;
    specFres                             = 1.f;
    reflFres                             = 0.f;
    refIndex                             = 1.f;
    refIndex                             = 1.f;
    disperse                             = 0.f;
    tranRough                            = 0.f;
    tranDist                             = 0.f;
    subsDist                             = 0.005f;
    subsDepth                            = 1.f;
    subsPhase                            = 0.5;
    bumpAmp                              = 0.005f;
    displace                             = 0.02f;
    smooth                               = 1.f;
    smAngle                              = float(LXx_TWOPI) / 9.f;
    rndWidth                             = 0.f;
    rndAngle                             = float(LXx_TWOPI) / 9.f;
    clipCol[0] = clipCol[1] = clipCol[2] = 0.f;
    clipValue                            = 1.f;
    importance                           = 1.f;
    scatterAmt                           = 1.f;
    scatterCol[0] = scatterCol[1] = scatterCol[2] = 1.f;
    absorbAmt                                     = 1.f;
    absorbCol[0] = absorbCol[1] = absorbCol[2] = 1.f;
    density                                    = 1.f;
    redShift                                   = 0.f;
    luminousAmt                                = 0.f;
    luminousCol[0] = luminousCol[1] = luminousCol[2] = 1.f;
    sheen                                            = 0.0f;
    sheenTint                                        = 0.0f;
    specTint                                         = 0.0f;
    flatness                                         = 0.0f;
    metallic                                         = 0.f;

    bumpVal    = 0.f;
    dispVal    = 0.f;
    stenVal    = 0.f;
    dblSided   = 0;
    useRefIdx  = 0;
    reflSpec   = 1;
    reflBlur   = 1;
    reflRays   = 64;
    tranRays   = 64;
    subsSmps   = 64;
    sameSurf   = 0;
    rndSame    = 0;
    clearBump  = 1;
    clipMatte  = 0;
    clipEnable = 1;
    radInter   = 0;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LxResult CLxAdvMaterial::Init(CLxUser_Item& mat, CLxUser_ChannelRead& chan)
{
    if (LXx_FAIL(TestItemType(mat, citAdvancedMaterial)))
    {
        return LXe_INVALIDARG;
    }

    CLxTextureLayer::Init(mat, chan);

    item = mat;

    diffCol[0]     = static_cast<float>(chan.FValue(mat, LXsICHAN_ADVANCEDMATERIAL_DIFFCOL ".R"));
    diffCol[1]     = static_cast<float>(chan.FValue(mat, LXsICHAN_ADVANCEDMATERIAL_DIFFCOL ".G"));
    diffCol[2]     = static_cast<float>(chan.FValue(mat, LXsICHAN_ADVANCEDMATERIAL_DIFFCOL ".B"));
    diffAmt        = static_cast<float>(chan.FValue(mat, LXsICHAN_ADVANCEDMATERIAL_DIFFAMT));
    specCol[0]     = static_cast<float>(chan.FValue(mat, LXsICHAN_ADVANCEDMATERIAL_SPECCOL ".R"));
    specCol[1]     = static_cast<float>(chan.FValue(mat, LXsICHAN_ADVANCEDMATERIAL_SPECCOL ".G"));
    specCol[2]     = static_cast<float>(chan.FValue(mat, LXsICHAN_ADVANCEDMATERIAL_SPECCOL ".B"));
    specAmt        = static_cast<float>(chan.FValue(mat, LXsICHAN_ADVANCEDMATERIAL_SPECAMT));
    reflCol[0]     = static_cast<float>(chan.FValue(mat, LXsICHAN_ADVANCEDMATERIAL_REFLCOL ".R"));
    reflCol[1]     = static_cast<float>(chan.FValue(mat, LXsICHAN_ADVANCEDMATERIAL_REFLCOL ".G"));
    reflCol[2]     = static_cast<float>(chan.FValue(mat, LXsICHAN_ADVANCEDMATERIAL_REFLCOL ".B"));
    reflAmt        = static_cast<float>(chan.FValue(mat, LXsICHAN_ADVANCEDMATERIAL_REFLAMT));
    tranCol[0]     = static_cast<float>(chan.FValue(mat, LXsICHAN_ADVANCEDMATERIAL_TRANCOL ".R"));
    tranCol[1]     = static_cast<float>(chan.FValue(mat, LXsICHAN_ADVANCEDMATERIAL_TRANCOL ".G"));
    tranCol[2]     = static_cast<float>(chan.FValue(mat, LXsICHAN_ADVANCEDMATERIAL_TRANCOL ".B"));
    tranAmt        = static_cast<float>(chan.FValue(mat, LXsICHAN_ADVANCEDMATERIAL_TRANAMT));
    subsCol[0]     = static_cast<float>(chan.FValue(mat, LXsICHAN_ADVANCEDMATERIAL_SUBSCOL ".R"));
    subsCol[1]     = static_cast<float>(chan.FValue(mat, LXsICHAN_ADVANCEDMATERIAL_SUBSCOL ".G"));
    subsCol[2]     = static_cast<float>(chan.FValue(mat, LXsICHAN_ADVANCEDMATERIAL_SUBSCOL ".B"));
    subsAmt        = static_cast<float>(chan.FValue(mat, LXsICHAN_ADVANCEDMATERIAL_SUBSAMT));
    lumiCol[0]     = static_cast<float>(chan.FValue(mat, LXsICHAN_ADVANCEDMATERIAL_LUMICOL ".R"));
    lumiCol[1]     = static_cast<float>(chan.FValue(mat, LXsICHAN_ADVANCEDMATERIAL_LUMICOL ".G"));
    lumiCol[2]     = static_cast<float>(chan.FValue(mat, LXsICHAN_ADVANCEDMATERIAL_LUMICOL ".B"));
    radiance       = static_cast<float>(chan.FValue(mat, LXsICHAN_ADVANCEDMATERIAL_RADIANCE));
    exitCol[0]     = static_cast<float>(chan.FValue(mat, LXsICHAN_ADVANCEDMATERIAL_EXITCOL ".R"));
    exitCol[1]     = static_cast<float>(chan.FValue(mat, LXsICHAN_ADVANCEDMATERIAL_EXITCOL ".G"));
    exitCol[2]     = static_cast<float>(chan.FValue(mat, LXsICHAN_ADVANCEDMATERIAL_EXITCOL ".B"));
    coatAmt        = static_cast<float>(chan.FValue(mat, LXsICHAN_ADVANCEDMATERIAL_COATAMT));
    dissAmt        = static_cast<float>(chan.FValue(mat, LXsICHAN_ADVANCEDMATERIAL_DISSAMT));
    diffRough      = static_cast<float>(chan.FValue(mat, LXsICHAN_ADVANCEDMATERIAL_DIFFROUGH));
    rough          = static_cast<float>(chan.FValue(mat, LXsICHAN_ADVANCEDMATERIAL_ROUGH));
    coatRough      = static_cast<float>(chan.FValue(mat, LXsICHAN_ADVANCEDMATERIAL_COATROUGH));
    coatBump       = static_cast<float>(chan.FValue(mat, LXsICHAN_ADVANCEDMATERIAL_COATBUMP));
    aniso          = static_cast<float>(chan.FValue(mat, LXsICHAN_ADVANCEDMATERIAL_ANISO));
    specFres       = static_cast<float>(chan.FValue(mat, LXsICHAN_ADVANCEDMATERIAL_SPECFRES));
    reflFres       = static_cast<float>(chan.FValue(mat, LXsICHAN_ADVANCEDMATERIAL_REFLFRES));
    refIndex       = static_cast<float>(chan.FValue(mat, LXsICHAN_ADVANCEDMATERIAL_REFINDEX));
    disperse       = static_cast<float>(chan.FValue(mat, LXsICHAN_ADVANCEDMATERIAL_DISPERSE));
    tranRough      = static_cast<float>(chan.FValue(mat, LXsICHAN_ADVANCEDMATERIAL_TRANROUGH));
    tranDist       = static_cast<float>(chan.FValue(mat, LXsICHAN_ADVANCEDMATERIAL_TRANDIST));
    subsDist       = static_cast<float>(chan.FValue(mat, LXsICHAN_ADVANCEDMATERIAL_SUBSDIST));
    subsDepth      = static_cast<float>(chan.FValue(mat, LXsICHAN_ADVANCEDMATERIAL_SUBSDEPTH));
    subsPhase      = static_cast<float>(chan.FValue(mat, LXsICHAN_ADVANCEDMATERIAL_SUBSPHASE));
    bump           = static_cast<float>(chan.FValue(mat, LXsICHAN_ADVANCEDMATERIAL_BUMP));
    bumpAmp        = static_cast<float>(chan.FValue(mat, LXsICHAN_ADVANCEDMATERIAL_BUMPAMP));
    displace       = static_cast<float>(chan.FValue(mat, LXsICHAN_ADVANCEDMATERIAL_DISPLACE));
    smooth         = static_cast<float>(chan.FValue(mat, LXsICHAN_ADVANCEDMATERIAL_SMOOTH));
    smAngle        = static_cast<float>(chan.FValue(mat, LXsICHAN_ADVANCEDMATERIAL_SMANGLE));
    rndWidth       = static_cast<float>(chan.FValue(mat, LXsICHAN_ADVANCEDMATERIAL_RNDWIDTH));
    rndAngle       = static_cast<float>(chan.FValue(mat, LXsICHAN_ADVANCEDMATERIAL_RNDANGLE));
    clipCol[0]     = static_cast<float>(chan.FValue(mat, LXsICHAN_ADVANCEDMATERIAL_CLIPCOL ".R"));
    clipCol[1]     = static_cast<float>(chan.FValue(mat, LXsICHAN_ADVANCEDMATERIAL_CLIPCOL ".G"));
    clipCol[2]     = static_cast<float>(chan.FValue(mat, LXsICHAN_ADVANCEDMATERIAL_CLIPCOL ".B"));
    clipValue      = static_cast<float>(chan.FValue(mat, LXsICHAN_ADVANCEDMATERIAL_CLIPVAL));
    importance     = static_cast<float>(chan.FValue(mat, LXsICHAN_ADVANCEDMATERIAL_IMPORTANCE));
    scatterCol[0]  = static_cast<float>(chan.FValue(mat, LXsICHAN_ADVANCEDMATERIAL_SCATTERCOL ".R"));
    scatterCol[1]  = static_cast<float>(chan.FValue(mat, LXsICHAN_ADVANCEDMATERIAL_SCATTERCOL ".G"));
    scatterCol[2]  = static_cast<float>(chan.FValue(mat, LXsICHAN_ADVANCEDMATERIAL_SCATTERCOL ".B"));
    scatterAmt     = static_cast<float>(chan.FValue(mat, LXsICHAN_ADVANCEDMATERIAL_SCATTERAMT));
    absorbCol[0]   = static_cast<float>(chan.FValue(mat, LXsICHAN_ADVANCEDMATERIAL_ABSORBCOL ".R"));
    absorbCol[1]   = static_cast<float>(chan.FValue(mat, LXsICHAN_ADVANCEDMATERIAL_ABSORBCOL ".G"));
    absorbCol[2]   = static_cast<float>(chan.FValue(mat, LXsICHAN_ADVANCEDMATERIAL_ABSORBCOL ".B"));
    absorbAmt      = static_cast<float>(chan.FValue(mat, LXsICHAN_ADVANCEDMATERIAL_ABSORBAMT));
    density        = static_cast<float>(chan.FValue(mat, LXsICHAN_ADVANCEDMATERIAL_DENSITY));
    redShift       = static_cast<float>(chan.FValue(mat, LXsICHAN_ADVANCEDMATERIAL_REDSHIFT));
    luminousCol[0] = static_cast<float>(chan.FValue(mat, LXsICHAN_ADVANCEDMATERIAL_LUMINOUSCOL ".R"));
    luminousCol[1] = static_cast<float>(chan.FValue(mat, LXsICHAN_ADVANCEDMATERIAL_LUMINOUSCOL ".G"));
    luminousCol[2] = static_cast<float>(chan.FValue(mat, LXsICHAN_ADVANCEDMATERIAL_LUMINOUSCOL ".B"));
    luminousAmt    = static_cast<float>(chan.FValue(mat, LXsICHAN_ADVANCEDMATERIAL_LUMINOUSAMT));
    sheen          = static_cast<float>(chan.FValue(mat, LXsICHAN_ADVANCEDMATERIAL_SHEEN));
    sheenTint      = static_cast<float>(chan.FValue(mat, LXsICHAN_ADVANCEDMATERIAL_SHEENTINT));
    specTint       = static_cast<float>(chan.FValue(mat, LXsICHAN_ADVANCEDMATERIAL_SPECTINT));
    flatness       = static_cast<float>(chan.FValue(mat, LXsICHAN_ADVANCEDMATERIAL_FLATNESS));
    metallic       = static_cast<float>(chan.FValue(mat, LXsICHAN_ADVANCEDMATERIAL_METALLIC));

    bumpVal = static_cast<float>(chan.FValue(mat, LXsICHAN_ADVANCEDMATERIAL_BUMPVAL));
    dispVal = static_cast<float>(chan.FValue(mat, LXsICHAN_ADVANCEDMATERIAL_DISPVAL));
    stenVal = static_cast<float>(chan.FValue(mat, LXsICHAN_ADVANCEDMATERIAL_STENVAL));

    dblSided   = chan.IValue(mat, LXsICHAN_ADVANCEDMATERIAL_DBLSIDED);
    brdfType   = chan.IValue(mat, LXsICHAN_ADVANCEDMATERIAL_BRDFTYPE);
    useRefIdx  = chan.IValue(mat, LXsICHAN_ADVANCEDMATERIAL_USEREFIDX);
    reflSpec   = chan.IValue(mat, LXsICHAN_ADVANCEDMATERIAL_REFLSPEC);
    reflType   = chan.IValue(mat, LXsICHAN_ADVANCEDMATERIAL_REFLTYPE);
    reflBlur   = chan.IValue(mat, LXsICHAN_ADVANCEDMATERIAL_REFLBLUR);
    reflRays   = chan.IValue(mat, LXsICHAN_ADVANCEDMATERIAL_REFLRAYS);
    tranRays   = chan.IValue(mat, LXsICHAN_ADVANCEDMATERIAL_TRANRAYS);
    subsSmps   = chan.IValue(mat, LXsICHAN_ADVANCEDMATERIAL_SUBSMPS);
    sameSurf   = chan.IValue(mat, LXsICHAN_ADVANCEDMATERIAL_SAMESRF);
    rndSame    = chan.IValue(mat, LXsICHAN_ADVANCEDMATERIAL_RNDSAME);
    clearBump  = chan.IValue(mat, LXsICHAN_ADVANCEDMATERIAL_CLEARBUMP);
    clipMatte  = chan.IValue(mat, LXsICHAN_ADVANCEDMATERIAL_CLIPMATTE);
    clipEnable = chan.IValue(mat, LXsICHAN_ADVANCEDMATERIAL_CLIPENABLE);
    radInter   = chan.IValue(mat, LXsICHAN_ADVANCEDMATERIAL_RADINTER);

    return LXe_OK;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LxResult CLxDefaultShader::Init(CLxUser_Item& item, CLxUser_ChannelRead& chan)
{
    if (LXx_FAIL(TestItemType(item, citDefaultShader)))
        return LXe_INVALIDARG;

    CLxTextureLayer::Init(item, chan);

    shadeRate   = static_cast<float>(chan.IValue(item, LXsICHAN_DEFAULTSHADER_SHADERATE));
    dirMult     = static_cast<float>(chan.FValue(item, LXsICHAN_DEFAULTSHADER_DIRMULT));
    indMult     = static_cast<float>(chan.FValue(item, LXsICHAN_DEFAULTSHADER_INDMULT));
    indSat      = static_cast<float>(chan.FValue(item, LXsICHAN_DEFAULTSHADER_INDSAT));
    indSatOut   = static_cast<float>(chan.FValue(item, LXsICHAN_DEFAULTSHADER_INDSATOUT));
    indType     = chan.IValue(item, LXsICHAN_DEFAULTSHADER_INDTYPE);
    fogType     = chan.IValue(item, LXsICHAN_DEFAULTSHADER_FOGTYPE);
    fogEnv      = chan.IValue(item, LXsICHAN_DEFAULTSHADER_FOGENV);
    fogColor[0] = static_cast<float>(chan.FValue(item, LXsICHAN_DEFAULTSHADER_FOGCOLOR ".R"));
    fogColor[1] = static_cast<float>(chan.FValue(item, LXsICHAN_DEFAULTSHADER_FOGCOLOR ".G"));
    fogColor[2] = static_cast<float>(chan.FValue(item, LXsICHAN_DEFAULTSHADER_FOGCOLOR ".B"));
    fogStart    = static_cast<float>(chan.FValue(item, LXsICHAN_DEFAULTSHADER_FOGSTART));
    fogEnd      = static_cast<float>(chan.FValue(item, LXsICHAN_DEFAULTSHADER_FOGEND));
    fogDensity  = static_cast<float>(chan.FValue(item, LXsICHAN_DEFAULTSHADER_FOGDENSITY));
    alphaType   = chan.IValue(item, LXsICHAN_DEFAULTSHADER_ALPHATYPE);
    alphaVal    = static_cast<float>(chan.FValue(item, LXsICHAN_DEFAULTSHADER_ALPHAVAL));
    lightLink   = chan.IValue(item, LXsICHAN_DEFAULTSHADER_LIGHTLINK);
    shadCast    = chan.IValue(item, LXsICHAN_DEFAULTSHADER_SHADCAST);
    shadRecv    = chan.IValue(item, LXsICHAN_DEFAULTSHADER_SHADRECV);
    visCam      = chan.IValue(item, LXsICHAN_DEFAULTSHADER_VISCAM);
    visInd      = chan.IValue(item, LXsICHAN_DEFAULTSHADER_VISIND);
    visRefl     = chan.IValue(item, LXsICHAN_DEFAULTSHADER_VISREFL);
    visRefr     = chan.IValue(item, LXsICHAN_DEFAULTSHADER_VISREFR);
    visOccl     = chan.IValue(item, LXsICHAN_DEFAULTSHADER_VISOCCL);
    visEnable   = chan.IValue(item, LXsICHAN_DEFAULTSHADER_TOGVIS);
    quaEnable   = chan.IValue(item, LXsICHAN_DEFAULTSHADER_TOGQUA);
    lgtEnable   = chan.IValue(item, LXsICHAN_DEFAULTSHADER_TOGLGT);
    fogEnable   = chan.IValue(item, LXsICHAN_DEFAULTSHADER_TOGFOG);
    shdEnable   = chan.IValue(item, LXsICHAN_DEFAULTSHADER_TOGSHD);

    return LXe_OK;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LxResult CLxImageMap::Init(CLxUser_Item& image, CLxUser_ChannelRead& chan)
{
    if (LXx_FAIL(TestItemType(image, citImageMap)))
        return LXe_INVALIDARG;

    item = image;

    CLxTextureLayer::Init(image, chan);

    aa         = chan.IValue(image, LXsICHAN_IMAGEMAP_AA);
    aaVal      = static_cast<float>(chan.FValue(image, LXsICHAN_IMAGEMAP_AAVAL));
    pixBlend   = chan.IValue(image, LXsICHAN_IMAGEMAP_PIXBLEND);
    minSpot    = static_cast<float>(chan.FValue(image, LXsICHAN_IMAGEMAP_MINSPOT));
    min        = static_cast<float>(chan.FValue(image, LXsICHAN_IMAGEMAP_MIN));
    max        = static_cast<float>(chan.FValue(image, LXsICHAN_IMAGEMAP_MAX));
    sourceLow  = static_cast<float>(chan.FValue(image, LXsICHAN_IMAGEMAP_SOURCELOW));
    sourceHigh = static_cast<float>(chan.FValue(image, LXsICHAN_IMAGEMAP_SOURCEHIGH));
    redInv     = chan.IValue(image, LXsICHAN_IMAGEMAP_REDINV);
    greenInv   = chan.IValue(image, LXsICHAN_IMAGEMAP_GREENINV);
    blueInv    = chan.IValue(image, LXsICHAN_IMAGEMAP_BLUEINV);
    gamma      = static_cast<float>(chan.FValue(image, LXsICHAN_IMAGEMAP_GAMMA));
    swizzling  = chan.IValue(image, LXsICHAN_IMAGEMAP_SWIZZLING);
    alpha      = chan.IValue(image, LXsICHAN_IMAGEMAP_ALPHA);
    rgba       = chan.IValue(image, LXsICHAN_IMAGEMAP_RGBA);

    // Get connected clip and texture locator from shade grahp
    CLxUser_Scene     scene;
    CLxUser_ItemGraph shadeGraph;

    image.GetContext(scene);
    shadeGraph.from(scene, LXsGRAPH_SHADELOC);

    CLxUser_Item clip, texLoc, link;
    unsigned     nLinks;

    nLinks = shadeGraph.Forward(image);

    for (unsigned lc = 0; lc < nLinks; ++lc)
    {
        shadeGraph.Forward(image, lc, link);

        if (link.test())
        {
            if (link.IsA(citTextureLoc))
                txtrLocItem = link;
            else if (link.IsA(citVideoClip))
                clipItem = link;
        }
    }

    return LXe_OK;
}

//-----------------------------------------------------------------------------
/**
 * From the item that is of type citMask, get all items that refer to it directly
 * or via links.
 */
//-----------------------------------------------------------------------------
void GetMaterialGroupMaskedItems(CLxUser_Item& item, lx::UnknownArray& items)
{
    if (!item.IsA(citMask))
        return;

    // Get connected items
    CLxUser_Scene     scene;
    CLxUser_ItemGraph shadeGraph;

    item.GetContext(scene);
    shadeGraph.from(scene, LXsGRAPH_SHADELOC);

    CLxUser_Item linkItem;
    unsigned     nLinks;

    nLinks = shadeGraph.Forward(item);

    for (unsigned lc = 0; lc < nLinks; ++lc)
    {
        shadeGraph.Forward(item, 0, linkItem);

        if (linkItem.test())
        {
            if (linkItem.IsA(LXi_CIT_GROUP))
            {
                // Enumerate group
                CLxUser_GroupItem group(linkItem);
                GroupVisitor      grpVis(group, items);

                grpVis.Run();

                continue;
            }
            else if (linkItem.IsA(citGroupLocator))
            {
                CLxUser_Item grpLoc(linkItem);
                unsigned     nSubs;

                grpLoc.SubCount(&nSubs);

                for (unsigned sc = 0; sc < nSubs; ++sc)
                {
                    CLxUser_Item subItem;

                    if (grpLoc.SubByIndex(sc, subItem))
                        items.push_back(subItem);
                }
            }

            items.push_back(linkItem);
        }
    }
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LxResult CLxMaterialGroup::Init(CLxUser_Item& mask, CLxUser_ChannelRead& chan)
{
    if (LXx_FAIL(TestItemType(mask, citMask)))
        return LXe_INVALIDARG;

    item = mask;

    CLxTextureLayer::Init(mask, chan);

    chan.String(mask, mask.ChannelIndex(LXsICHAN_MASK_PTAG), &ptag);
    chan.String(mask, mask.ChannelIndex(LXsICHAN_MASK_PTYP), &ptyp);

    submask   = chan.IValue(mask, LXsICHAN_MASK_SUBMASK);
    surfType  = chan.IValue(mask, LXsICHAN_MASK_STYP);
    addLayer  = chan.IValue(mask, LXsICHAN_MASK_ADDLAYER);
    instApply = chan.IValue(mask, LXsICHAN_MASK_INSTAPPLY);

    return LXe_OK;
}

//-----------------------------------------------------------------------------
// Returns items that this material group should be applied to
//-----------------------------------------------------------------------------
LxResult CLxMaterialGroup::Items(lx::UnknownArray& items)
{
    CLxUser_Item matGrp;

    if (!matGrp.set(item))
        return LXe_FAILED;

    GetMaterialGroupMaskedItems(matGrp, items);

    // Add parent's masked items
    CLxUser_Item parent;

    matGrp.GetParent(parent);

    while (1)
    {
        if (!parent.IsA(citMask))
            break;

        GetMaterialGroupMaskedItems(parent, items);

        parent.GetParent(parent);
    }

    return LXe_OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
LxResult CLxEnvironment::Init(CLxUser_Item& env, CLxUser_ChannelRead& chan)
{
    if (LXx_FAIL(TestItemType(env, citEnvironment)))
        return LXe_INVALIDARG;

    item = env;

    // Read environment item channels
    radiance = static_cast<float>(chan.FValue(env, LXsICHAN_ENVIRONMENT_RADIANCE));
    visCam   = chan.IValue(env, LXsICHAN_ENVIRONMENT_VISCAM);
    visInd   = chan.IValue(env, LXsICHAN_ENVIRONMENT_VISIND);
    visRefl  = chan.IValue(env, LXsICHAN_ENVIRONMENT_VISREFL);
    visRefr  = chan.IValue(env, LXsICHAN_ENVIRONMENT_VISREFR);

    return LXe_OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
LxResult CLxEnvMaterial::Init(CLxUser_Item& envMat, CLxUser_ChannelRead& chan)
{
    if (LXx_FAIL(TestItemType(envMat, citEnvMaterial)))
        return LXe_INVALIDARG;

    item = envMat;

    // Get sunLight connected to this material (if any)
    CLxUser_Item      light;
    CLxUser_Scene     scene;
    CLxUser_ItemGraph shadeGraph;

    envMat.GetContext(scene);
    shadeGraph.from(scene, LXsGRAPH_SHADELOC);

    const int nLinks = shadeGraph.Forward(envMat);

    for (int lc = 0; lc < nLinks; ++lc)
    {
        shadeGraph.Forward(envMat, lc, light);

        if (light.IsA(citSunLight))
        {
            sunLight = light;
            break;
        }
    }

    // Read env material channels
    CLxTextureLayer::Init(envMat, chan);

    type        = chan.IValue(envMat, LXsICHAN_ENVMATERIAL_TYPE);
    zenColor[0] = static_cast<float>(chan.FValue(envMat, LXsICHAN_ENVMATERIAL_ZENCOLOR ".R"));
    zenColor[1] = static_cast<float>(chan.FValue(envMat, LXsICHAN_ENVMATERIAL_ZENCOLOR ".G"));
    zenColor[2] = static_cast<float>(chan.FValue(envMat, LXsICHAN_ENVMATERIAL_ZENCOLOR ".B"));
    skyColor[0] = static_cast<float>(chan.FValue(envMat, LXsICHAN_ENVMATERIAL_SKYCOLOR ".R"));
    skyColor[1] = static_cast<float>(chan.FValue(envMat, LXsICHAN_ENVMATERIAL_SKYCOLOR ".G"));
    skyColor[2] = static_cast<float>(chan.FValue(envMat, LXsICHAN_ENVMATERIAL_SKYCOLOR ".B"));
    gndColor[0] = static_cast<float>(chan.FValue(envMat, LXsICHAN_ENVMATERIAL_GNDCOLOR ".R"));
    gndColor[1] = static_cast<float>(chan.FValue(envMat, LXsICHAN_ENVMATERIAL_GNDCOLOR ".G"));
    gndColor[2] = static_cast<float>(chan.FValue(envMat, LXsICHAN_ENVMATERIAL_GNDCOLOR ".B"));
    nadColor[0] = static_cast<float>(chan.FValue(envMat, LXsICHAN_ENVMATERIAL_NADCOLOR ".R"));
    nadColor[1] = static_cast<float>(chan.FValue(envMat, LXsICHAN_ENVMATERIAL_NADCOLOR ".G"));
    nadColor[2] = static_cast<float>(chan.FValue(envMat, LXsICHAN_ENVMATERIAL_NADCOLOR ".B"));
    skyExp      = static_cast<float>(chan.FValue(envMat, LXsICHAN_ENVMATERIAL_SKYEXP));
    gndExp      = static_cast<float>(chan.FValue(envMat, LXsICHAN_ENVMATERIAL_GNDEXP));

    if (light.test())
        haze = static_cast<float>(chan.FValue(light, LXsICHAN_SUNLIGHT_HAZE));

    normalize    = chan.IValue(envMat, LXsICHAN_ENVMATERIAL_NORMALIZE);
    disc         = static_cast<float>(chan.FValue(envMat, LXsICHAN_ENVMATERIAL_DISC));
    clampedGamma = static_cast<float>(chan.FValue(envMat, LXsICHAN_ENVMATERIAL_CLMPGAMMA));
    albedoCol[0] = static_cast<float>(chan.FValue(envMat, LXsICHAN_ENVMATERIAL_ALBEDOCOLOR ".R"));
    albedoCol[1] = static_cast<float>(chan.FValue(envMat, LXsICHAN_ENVMATERIAL_ALBEDOCOLOR ".G"));
    albedoCol[2] = static_cast<float>(chan.FValue(envMat, LXsICHAN_ENVMATERIAL_ALBEDOCOLOR ".B"));
    discCol[0]   = static_cast<float>(chan.FValue(envMat, LXsICHAN_ENVMATERIAL_DISCCOLOR ".R"));
    discCol[1]   = static_cast<float>(chan.FValue(envMat, LXsICHAN_ENVMATERIAL_DISCCOLOR ".G"));
    discCol[2]   = static_cast<float>(chan.FValue(envMat, LXsICHAN_ENVMATERIAL_DISCCOLOR ".B"));
    inscatter    = static_cast<float>(chan.FValue(envMat, LXsICHAN_ENVMATERIAL_INSCATTER));

    fogType    = chan.IValue(envMat, LXsICHAN_ENVMATERIAL_FOG_TYPE);
    fogStart   = static_cast<float>(chan.FValue(envMat, LXsICHAN_ENVMATERIAL_FOG_START));
    fogEnd     = static_cast<float>(chan.FValue(envMat, LXsICHAN_ENVMATERIAL_FOG_END));
    fogDensity = static_cast<float>(chan.FValue(envMat, LXsICHAN_ENVMATERIAL_FOG_DENSITY));
    fogHeight  = static_cast<float>(chan.FValue(envMat, LXsICHAN_ENVMATERIAL_FOG_HEIGHT));
    fogFalloff = static_cast<float>(chan.FValue(envMat, LXsICHAN_ENVMATERIAL_FOG_FALLOFF));

    return LXe_OK;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LxResult CLxVideoClip::Init(CLxUser_Item& item, CLxUser_ChannelRead& chan)
{
    zero_members();

    if (LXx_FAIL(TestItemType(item, citVideoClip)))
        return LXe_INVALIDARG;

    chan.ValueObj(item, item.ChannelIndex(LXsICHAN_VIDEOCLIP_IMAGESTACK), &imageStack);

    interlace = chan.IValue(item, LXsICHAN_VIDEOCLIP_INTERLACE);
    alphaMode = chan.IValue(item, LXsICHAN_VIDEOCLIP_ALPHAMODE);
    fps       = static_cast<float>(chan.FValue(item, LXsICHAN_VIDEOCLIP_FPS));
    udim      = chan.IValue(item, LXsICHAN_VIDEOCLIP_UDIM);

    chan.String(item, item.ChannelIndex(LXsICHAN_VIDEOCLIP_COLORSPACE), &colorspace);

    enable  = chan.IValue(item, LXsICHAN_VIDEOCLIP_ENABLE);
    opacity = static_cast<float>(chan.FValue(item, LXsICHAN_VIDEOCLIP_OPACITY));
    blend   = chan.IValue(item, LXsICHAN_VIDEOCLIP_BLEND);

    return LXe_OK;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LxResult CLxVideoClip::GetImage(CLxUser_Image& image, LXtImageMetrics* outMetrics)
{
    if (outMetrics)
        memset(outMetrics, 0, sizeof(LXtImageMetrics));

    if (!imageStack)
        return LXe_FAILED;

    LxResult            res;
    CLxUser_ImageFilter filter;

    lx::ObjAddRef(imageStack);  // because of the following take
    res = filter.take(imageStack);
    if (LXx_FAIL(res))
        return res;

    CLxUser_ImageFilterMetrics filtMetrics(filter);
    LXtImageMetrics            metrics;

    res = filtMetrics.Generate(&metrics);
    if (LXx_FAIL(res))
        return res;

    if (outMetrics)
        *outMetrics = metrics;

    bool isOk = filter.Generate(metrics.maxRes[0], metrics.maxRes[1], nullptr, image);

    return isOk ? LXe_OK : LXe_FAILED;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
CLxVideoClip::~CLxVideoClip()
{
    if (nullptr == imageStack)
    {
        return;
    }
    lx::ObjRelease(imageStack);
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void CLxVideoClip::zero_members()
{
    imageStack = nullptr;
    interlace  = 0;
    alphaMode  = 0;
    fps        = 0;
    udim       = 0;
    colorspace = nullptr;
    enable     = 0;
    opacity    = 0;
    blend      = 0;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LxResult CLxVideoStill::Init(CLxUser_Item& item, CLxUser_ChannelRead& chan)
{
    zero_members();

    if (LXx_FAIL(TestItemType(item, citVideoStill)))
        return LXe_INVALIDARG;

    CLxVideoClip::Init(item, chan);

    chan.String(item, item.ChannelIndex(LXsICHAN_VIDEOSTILL_FILENAME), &filename);
    chan.String(item, item.ChannelIndex(LXsICHAN_VIDEOSTILL_FORMAT), &format);

    return LXe_OK;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void CLxVideoStill::zero_members()
{
    CLxVideoClip::zero_members();
    filename = nullptr;
    format   = nullptr;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LxResult CLxVideoSequence::Init(CLxUser_Item& item, CLxUser_ChannelRead& chan)
{
    zero_members();

    if (LXx_FAIL(TestItemType(item, citVideoSequence)))
        return LXe_INVALIDARG;

    CLxVideoClip::Init(item, chan);

    chan.String(item, item.ChannelIndex(LXsICHAN_VIDEOSEQUENCE_PATTERN), &pattern);
    firstFrame  = chan.IValue(item, LXsICHAN_VIDEOSEQUENCE_FIRSTFRAME);
    lastFrame   = chan.IValue(item, LXsICHAN_VIDEOSEQUENCE_LASTFRAME);
    startFrame  = chan.IValue(item, LXsICHAN_VIDEOSEQUENCE_STARTFRAME);
    endBehavior = chan.IValue(item, LXsICHAN_VIDEOSEQUENCE_ENDBEHAVIOR);

    return LXe_OK;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void CLxVideoSequence::zero_members()
{
    CLxVideoClip::zero_members();
    pattern     = nullptr;
    firstFrame  = 0;
    lastFrame   = 0;
    startFrame  = 0;
    endBehavior = 0;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LxResult CLxImageLayer::Init(CLxUser_Item& item, CLxUser_ChannelRead& chan)
{
    zero_members();

    if (LXx_FAIL(TestItemType(item, citImageLayer)))
        return LXe_INVALIDARG;

    CLxVideoClip::Init(item, chan);

    chan.String(item, item.ChannelIndex("filename"), &filename);
    chan.String(item, item.ChannelIndex("type"), &type);

    layer = chan.IValue(item, "layer");

    return LXe_OK;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void CLxImageLayer::zero_members()
{
    CLxVideoClip::zero_members();
    filename = nullptr;
    layer    = 0;
    type     = nullptr;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LxResult CLxTextureLoc::Init(CLxUser_Item& texLoc, CLxUser_ChannelRead& chan)
{
    if (LXx_FAIL(TestItemType(texLoc, citTextureLoc)))
        return LXe_INVALIDARG;

    this->item = texLoc;

    projType = chan.IValue(texLoc, LXsICHAN_TEXTURELOC_PROJTYPE);
    projAxis = chan.IValue(texLoc, LXsICHAN_TEXTURELOC_PROJAXIS);
    tileU    = chan.IValue(texLoc, LXsICHAN_TEXTURELOC_TILEU);
    wrapU    = static_cast<float>(chan.FValue(texLoc, LXsICHAN_TEXTURELOC_WRAPU));
    tileV    = chan.IValue(texLoc, LXsICHAN_TEXTURELOC_TILEV);
    wrapV    = static_cast<float>(chan.FValue(texLoc, LXsICHAN_TEXTURELOC_WRAPV));
    world    = chan.IValue(texLoc, LXsICHAN_TEXTURELOC_WORLD);
    fallType = chan.IValue(texLoc, LXsICHAN_TEXTURELOC_FALLTYPE);
    falloff  = static_cast<float>(chan.FValue(texLoc, LXsICHAN_TEXTURELOC_FALLOFF));

    chan.String(texLoc, texLoc.ChannelIndex(LXsICHAN_TEXTURELOC_UVMAP), &uvMap);
    chan.ValueObj(texLoc, texLoc.ChannelIndex(LXsICHAN_TEXTURELOC_STACK), &stack);

    m00                    = static_cast<float>(chan.FValue(texLoc, LXsICHAN_TEXTURELOC_M00));
    m01                    = static_cast<float>(chan.FValue(texLoc, LXsICHAN_TEXTURELOC_M01));
    m02                    = static_cast<float>(chan.FValue(texLoc, LXsICHAN_TEXTURELOC_M02));
    m10                    = static_cast<float>(chan.FValue(texLoc, LXsICHAN_TEXTURELOC_M10));
    m11                    = static_cast<float>(chan.FValue(texLoc, LXsICHAN_TEXTURELOC_M11));
    m12                    = static_cast<float>(chan.FValue(texLoc, LXsICHAN_TEXTURELOC_M12));
    m20                    = static_cast<float>(chan.FValue(texLoc, LXsICHAN_TEXTURELOC_M20));
    m21                    = static_cast<float>(chan.FValue(texLoc, LXsICHAN_TEXTURELOC_M21));
    m22                    = static_cast<float>(chan.FValue(texLoc, LXsICHAN_TEXTURELOC_M22));
    worldXfrm              = chan.IValue(texLoc, LXsICHAN_TEXTURELOC_WORLDXFRM);
    legacyRotation         = chan.IValue(texLoc, LXsICHAN_TEXTURELOC_LEGACYROT);
    psize                  = static_cast<float>(chan.FValue(texLoc, LXsICHAN_TEXTURELOC_PSIZE));
    bias                   = static_cast<float>(chan.FValue(texLoc, LXsICHAN_TEXTURELOC_BIAS));
    gain                   = static_cast<float>(chan.FValue(texLoc, LXsICHAN_TEXTURELOC_GAIN));
    sizeRandom             = static_cast<float>(chan.FValue(texLoc, LXsICHAN_TEXTURELOC_SIZERANDOM));
    rotation               = static_cast<int>(chan.FValue(texLoc, LXsICHAN_TEXTURELOC_ROTATION));
    rotRandom              = static_cast<int>(chan.FValue(texLoc, LXsICHAN_TEXTURELOC_ROTRANDOM));
    localProjection        = chan.IValue(texLoc, LXsICHAN_TEXTURELOC_LOCALPROJ);
    localNormal            = chan.IValue(texLoc, LXsICHAN_TEXTURELOC_LOCALNRM);
    textureOffsetAmplitude = static_cast<float>(chan.FValue(texLoc, LXsICHAN_TEXTURELOC_TXTROFFAMPL));
    uvRotation             = chan.IValue(texLoc, LXsICHAN_TEXTURELOC_UVROTATION);
    useUDIM                = chan.IValue(texLoc, LXsICHAN_TEXTURELOC_USEUDIM);
    legacyUVRotation       = chan.IValue(texLoc, LXsICHAN_TEXTURELOC_LEGACYUVROT);
    tngtType               = chan.IValue(texLoc, LXsICHAN_TEXTURELOC_TNGTTYPE);
    randoffset             = chan.IValue(texLoc, LXsICHAN_TEXTURELOC_RANDOFFSET);
    useOcclusion           = chan.IValue(texLoc, LXsICHAN_TEXTURELOC_USEOCCLUSION);

    chan.String(texLoc, texLoc.ChannelIndex(LXsICHAN_TEXTURELOC_VECTORMAP), &vectorMap);

    overscan = static_cast<float>(chan.IValue(texLoc, LXsICHAN_TEXTURELOC_OVERSCAN));

    lx::Matrix4Ident(uvMat);

    uvMat[0][0] = m00;
    uvMat[0][1] = m01;
    uvMat[0][2] = m02;
    uvMat[1][0] = m10;
    uvMat[1][1] = m11;
    uvMat[1][2] = m12;
    uvMat[2][0] = m20;
    uvMat[2][1] = m21;
    uvMat[2][2] = m22;

    lx::Matrix4Ident(uvRotMat);

    if (uvRotation)
    {
        double cr, sr;

        cr = cos((double) uvRotation);
        sr = sin((double) uvRotation);

        uvRotMat[0][0] = cr;
        uvRotMat[0][1] = -1.0 * sr;
        uvRotMat[0][2] = 0.0;

        uvRotMat[1][0] = sr;
        uvRotMat[1][1] = cr;
        uvRotMat[1][2] = 0.0;

        uvRotMat[2][0] = 0.0;
        uvRotMat[2][1] = 0.0;
        uvRotMat[2][2] = 1.0;
    }

    CLxUser_Locator loc(item);

    if (worldXfrm)
        loc.WorldTransform4(chan, xformMat);
    else
        loc.LocalTransform4(chan, xformMat);

    return LXe_OK;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
CLxTextureLoc::~CLxTextureLoc()
{
    lx::ObjRelease(stack);
}
