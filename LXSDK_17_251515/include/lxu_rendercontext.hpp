/*
* Plug-in SDK Header: C++ Services
*
* Copyright 0000
*
* Helper classes for implementing a custom renderer.
*/
#ifndef LX_RENDER_CONTEXT_HPP
#define LX_RENDER_CONTEXT_HPP

#include <lxidef.h>
#include <lxlocator.h>
#include <lxtableau.h>		// LXpXXX
#include <lximage.h>		// LXtImageFloat
#include <lxu_math.hpp>
#include <lx_item.hpp>
#include <lx_action.hpp>
#include <lx_shdr.hpp>
#include <lx_rendercache.hpp>

#include <vector>

namespace lx
{
	typedef std::vector< ILxUnknownID >	UnknownArray;
	typedef std::vector< float >		FloatVector;
	typedef std::vector< unsigned >		UIntVector;
}

//-----------------------------------------------------------------------------
/**
 * Common item types.
 * These can be used, for example, with CLxUser_Item::IsA() expressions.
 */
//-----------------------------------------------------------------------------
extern CLxItemType	citRender;

extern CLxItemType	citLocator;
extern CLxItemType	citTransform;
extern CLxItemType	citGroupLocator;

extern CLxItemType	citCamera;
extern CLxItemType	citTextureLoc;

extern CLxItemType	citEnvironment;
extern CLxItemType	citEnvMaterial;

extern CLxItemType	citLightMaterial;
extern CLxItemType	citLight;
extern CLxItemType	citSunLight;
extern CLxItemType	citPointLight;
extern CLxItemType	citSpotLight;
extern CLxItemType	citAreaLight;
extern CLxItemType	citMeshLight;

extern CLxItemType	citMask;
extern CLxItemType	citTextureLayer;
extern CLxItemType	citAdvancedMaterial;
extern CLxItemType	citDefaultShader;
extern CLxItemType	citRenderOutput;
extern CLxItemType	citImageMap;
extern CLxItemType	citConstant;
extern CLxItemType	citShaderFolder;

extern CLxItemType	citVideoClip;
extern CLxItemType	citVideoStill;
extern CLxItemType	citVideoSequence;
extern CLxItemType	citImageLayer;


class CLxRenderSettings;
class CLxCamera;
class CLxLayerStack;
class CLxTextureLayer;
class CLxAdvMaterial;
class CLxLight;
class CLxSunLight;
class CLxPointLight;
class CLxSpotLight;
class CLxAreaLight;
class CLxEnvironment;

namespace lx
{
	class SceneListener;
}

class CLxRenderContextEvent;
class CLxRenderContextListener;

//-----------------------------------------------------------------------------
/**
 * CLxRenderContext is used to obtain rendering data (camera, lights, etc.)
 * It is at least assumed a plugin will have one of these objects to help
 * query scene data.
 * An instance must have Init() invoked on it, which associates a listener and
 * the flags to initialise a local RenderCache instance. (This also implies that
 * a local Tableau is created.)
 * The current selected Scene will be associated with.
 * Subsequent calls will query that Scene.
 */
//-----------------------------------------------------------------------------
class CLxRenderContext
{
public:

	/// Construct an instance
	CLxRenderContext();

	/// Destroy an existing instance, and stop listening to any events.
	~CLxRenderContext();

	/// Initialize the render context from currently selected scene and selected time
	LxResult	Init (
				CLxRenderContextListener* listener = nullptr,
				unsigned rcacheFlags = LXfRENDERCACHE_FULL | LXfRENDERCACHE_TRACK_CURRENT_SCENE);

	/// Get the scene that can be queried
	LxResult	Scene (CLxUser_Scene& scene);

	/// Return CLxUser_ChannelRead object, to inspect channel data
	LxResult	Channels (CLxUser_ChannelRead& chans);

	/// Get the value of an integer channel on the specified item and channel name
	LxResult	ChanInt (CLxUser_Item& item, const char* channel, int& value);

	/// Get the value of a float channel on the specified item and channel name
	LxResult	ChanFlt (CLxUser_Item& item, const char* channel, float& value);

	/// Get the value of a double precision channel on the specified item and channel name
	LxResult	ChanDbl (CLxUser_Item& item, const char* channel, double& value);

	/// Get the value of an RGB channel on the specified item and channel name
	LxResult	ChanRGB (CLxUser_Item& item, const char* channel, LXtColorRGB& value);

	/// Get the value of an RGBA channel on the specified item and channel name
	LxResult	ChanRGBA (CLxUser_Item& item, const char* channel, LXtColorRGBA& value);

	/// Get the value of a string channel on the specified item and channel name
	LxResult	ChanStr (CLxUser_Item& item, const char* channel, const char*& value);

	/// Return the local RenderCache for this context
	LxResult	RenderCache (CLxUser_RenderCache& rcache);

	/// Return the number of items of given type in the scene
	int		NItems (LXtItemType type);

	/// Get an item of given type and index in the scene
	LxResult	GetItem (CLxUser_Item& item, int index, LXtItemType type);

	/// Get all items of given type in the scene
	LxResult	GetItems(lx::UnknownArray& array, LXtItemType type);

	/// Get current render camera in the scene
	LxResult	RenderCamera (CLxCamera& cam);

	/// Get Modo render settings for the scene
	LxResult	RenderSettings (CLxRenderSettings& settings);

	/// Get top-most material for the specified GeoCacheSurface. This may not be the exact material used, as it could be a result of any number of blends
	LxResult	Material (CLxUser_GeoCacheSurface& srf, CLxAdvMaterial& mat);

	/// Get layer stack for scene item (mesh, surface, etc.)
	LxResult	LayerStack (CLxUser_Item& item, CLxLayerStack& stack);

	/// Get layer stack for GeoCacheSurface
	LxResult	LayerStack (CLxUser_GeoCacheSurface& srf, CLxLayerStack& stack);

private:

	friend class lx::SceneListener;

	void		SetEvent (const CLxRenderContextEvent& event);

	CLxUser_Scene			_scene;
	CLxUser_ChannelRead		_chanTime;
	double				_time;

	CLxRenderContextListener*	_listener;
	CLxUser_RenderCache		_rcache;
};

//-----------------------------------------------------------------------------
/**
 * Base class for handling CLxRenderContext events
 * Use this to listen to events of types defined by CLxRenderContextEventType
 */
//-----------------------------------------------------------------------------
class CLxRenderContextListener
{
public:

	virtual void rctx_HandleEvent (const CLxRenderContextEvent& event) = 0;
};


//-----------------------------------------------------------------------------
/**
 * Events that the RenderContext can issue
 */
//-----------------------------------------------------------------------------
enum CLxRenderContextEventType
{
	LXi_RCTX_EVT_NONE = -1,

	LXi_RCTX_EVT_SCENE_CREATE,				//!< a Scene has been created
	LXi_RCTX_EVT_SCENE_DESTROY,				//!< a Scene has been destroyed
	LXi_RCTX_EVT_SCENE_CLEAR,				//!< a Scene has been cleared of all items
	LXi_RCTX_EVT_SCENE_CURRENT,				//!< a Scene has been made currently selected

	LXi_RCTX_EVT_SCENE_ITEM_ADD,			//!< an Item has been added to the current Scene
	LXi_RCTX_EVT_SCENE_ITEM_REMOVE,			//!< an Item has been removed from the current Scene
	LXi_RCTX_EVT_SCENE_ITEM_UPDATE,			//!< an Item has been updated in the current Scene

	LXi_RCTX_EVT_SCENE_TIME_CHANGE,			//!< the time in the current Scene has changed

	LXi_RCTX_EVT_RCACHE_DESTROY,			//!< the local RenderCache has been destroyed
	LXi_RCTX_EVT_RCACHE_CLEAR,				//!< the local RenderCache has been cleared
	LXi_RCTX_EVT_RCACHE_UPDATE_BEGIN,		//!< the local RenderCache is about to start making updates
	LXi_RCTX_EVT_RCACHE_UPDATE_END,			//!< the local RenderCache has finished making updated
	LXi_RCTX_EVT_RCACHE_SURF_ADD,			//!< a new GeoCacheSurface has been added to the local RenderCache
	LXi_RCTX_EVT_RCACHE_SURF_REMOVE,		//!< an existing GeoCacheSurface has been removed from the local RenderCache
	LXi_RCTX_EVT_RCACHE_SURF_GEO_UPDATE,	//!< a geometry update has occurred on an existing GeoCacheSurface in the local RenderCache
	LXi_RCTX_EVT_RCACHE_SURF_XFM_UPDATE,	//!< a transform update has occurred on an existing GeoCacheSurface in the local RenderCache
	LXi_RCTX_EVT_RCACHE_SURF_SHD_UPDATE,	//!< a shader update has occurred on an existing GeoCacheSurface in the local RenderCache

	LXi_RCTX_EVT_COUNT
};

//-----------------------------------------------------------------------------
/**
 * Base class for all render context events.
 * This encapsulates enough data associating an event with an item in the scene at a particular time.
 */
//-----------------------------------------------------------------------------
class CLxRenderContextEvent
{
public:

	/// Construct an event on an item at an unknown time
	CLxRenderContextEvent (CLxRenderContextEventType type, ILxUnknownID obj)
		: _obj (obj)
		, _time (-1.0)
		, _type (type)
	{
	}

	/// Construct an event on an item at the specified time
	CLxRenderContextEvent (CLxRenderContextEventType type, ILxUnknownID obj, double time)
		: _obj (obj)
		, _time (time)
		, _type (type)
	{
	}

	/// Get the type of the event
	CLxRenderContextEventType Type () const
	{
		return _type;
	}

	/// Get the item associated with the event
	ILxUnknownID	Object () const
	{
		return _obj;
	}

	/// Get the time that the event occurred
	double Time () const
	{
		return _time;
	}

private:

	ILxUnknownID			_obj;
	double				_time;
	CLxRenderContextEventType	_type;
};

//-----------------------------------------------------------------------------
/**
 * Class representing the shader tree layer stack, either in full, or as a subset
 * associated with a particular item.
 * Internally, the layer stack is a flat list, but each item provides data to be able
 * to reconstruct the hierarchy of the shader tree shown in Modo's UI.
 */
//-----------------------------------------------------------------------------
class CLxLayerStack
{
public:

	/// Default constructor creates empty layer stack
	CLxLayerStack ();

	/// Initialise the layer stack for a specific GeoCacheSurface. This requires the GeoCacheSurface to have an associated material tag, otherwise the entire shader tree is returned.
	LxResult Init (CLxUser_GeoCacheSurface& srf, CLxRenderContext& ctx);

	/// Initialize the layer stack from the specified item (mesh, surface, etc...)
	LxResult Init (CLxUser_Item& item, CLxRenderContext& ctx);

	/// Return number of items in the initialised layer stack of given type. By default, return number of all items.
	int NItems (LXtItemType type = LXiTYPE_ANY) const;

	/// Return item at index in the initialised layer stack (depending on type)
	LxResult GetItem (CLxUser_Item& item, int index, LXtItemType type = LXiTYPE_ANY) const;

	/// Return all items with given type from the initialised layer stack.
	LxResult GetItems (lx::UnknownArray& itemArray, LXtItemType type = LXiTYPE_ANY) const;

	/// Return number of masks in the initialised layer stack.
	int NMasks () const;

	/// Get mask at given index from the initialised layer stack.
		LxResult
	GetMask (
		CLxUser_Item&			mask,
		int				index) const;

	/// Get mask at given index and all the child items by types from the initialised layer stack.
		LxResult 
	GetMask (
		CLxUser_Item&			mask,
		int				index,
		LXtItemType			types[],
		lx::UnknownArray*		typeArrays[],
		unsigned			nTypes) const;

	/// Get mask at given index and all the child items from the initialised layer stack.
		LxResult 
	GetMask (
		CLxUser_Item&			mask,
		int				index,
		lx::UnknownArray&		children) const;

	/// Get image for the named effect. If effect is not set returns first image found.
	LxResult GetImage (CLxUser_Item& image, const char* fxName = nullptr) const;

	/// Diagnostics only: Print stack items to log
	void Print ();

private:

	void AddChildren (CLxUser_Item& item);

	bool IsEnabled (CLxUser_Item& item) const;

	mutable CLxUser_ChannelRead	_chans;
	std::vector< ILxUnknownID >	_items;
};

//-----------------------------------------------------------------------------
/**
 * Modo renderer settings from the channel values.
 * Once initialised, the public members can be queried.
 * Objects of this type are intended to be stack based.
 */
//-----------------------------------------------------------------------------
class CLxRenderSettings
{
public:

	unsigned	renderType;		//!< [integer] See LXsICHAN_POLYRENDER_RENDTYPE
	unsigned	aa;				//!< [integer] See LXsICHAN_POLYRENDER_AA
	unsigned	aaFilter;		//!< [integer] See LXsICHAN_POLYRENDER_AAFILTER
	float		aaImpMin;		//!< [float] See LXsICHAN_POLYRENDER_AAIMPMIN
	float		coarseRate;		//!< [float] See LXsICHAN_POLYRENDER_COARSERATE
	float		fineRate;		//!< [float] See LXsICHAN_POLYRENDER_FINERATE
	float		fineThresh;		//!< [float] See LXsICHAN_POLYRENDER_FINETHRESH
	unsigned	bktRefine;		//!< [integer] See LXsICHAN_POLYRENDER_BKTREFINE
	unsigned	aRefine;		//!< [integer] See LXsICHAN_POLYRENDER_AREFINE
	unsigned	mergeRad;		//!< [integer] See LXsICHAN_POLYRENDER_MERGERAD
	unsigned	field;			//!< [integer] See LXsICHAN_POLYRENDER_FIELD
	unsigned	bucketX;		//!< [integer] See LXsICHAN_POLYRENDER_BUCKETX
	unsigned	bucketY;		//!< [integer] See LXsICHAN_POLYRENDER_BUCKETY
	unsigned	bktOrder;		//!< [integer] See LXsICHAN_POLYRENDER_BKTORDER
	unsigned	bktReverse;		//!< [integer] See LXsICHAN_POLYRENDER_BKTREVERSE
	unsigned	bktWrite;		//!< [integer] See LXsICHAN_POLYRENDER_BKTWRITE
	unsigned	bktSkip;		//!< [integer] See LXsICHAN_POLYRENDER_BKTSKIP
	unsigned	frmPasses;		//!< [integer] See LXsICHAN_POLYRENDER_FRMPASSES
	unsigned	bakeDir;		//!< [integer] See LXsICHAN_POLYRENDER_BAKEDIR
	float		progConv;		//!< [percent] Progressive render convergence, see LXsICHAN_POLYRENDER_PROGCONV
	float		progTime;		//!< [float] Progressive render maximum render time (in minutes), see LXsICHAN_POLYRENDER_PROGTIME

	unsigned	outputMasking;	//!< [integer] See LXsICHAN_POLYRENDER_OUTPUTMASK
	
	LXtColorRGB	ambColor;		//!< [color] See LXsICHAN_RENDER_AMBCOLOR[.R][.G][.B]
	float		ambRad;			//!< [float] See LXsICHAN_RENDER_AMBRAD
	unsigned	globEnable;		//!< [boolean] See LXsICHAN_RENDER_GLOBENABLE
	unsigned	globScope;		//!< [integer] See LXsICHAN_RENDER_GLOBSCOPE
	unsigned	globLimit;		//!< [integer] See LXsICHAN_RENDER_GLOBLIMIT
	unsigned	globRays;		//!< [integer] See LXsICHAN_RENDER_GLOBRAYS
	float		globRange;		//!< [distance] See LXsICHAN_RENDER_GLOBRANGE
	unsigned	globSubs;		//!< [integer] See LXsICHAN_RENDER_GLOBSUBS
	unsigned	globVols;		//!< [boolean] See LXsICHAN_RENDER_GLOBVOLS
	unsigned	globBump;		//!< [boolean] See LXsICHAN_RENDER_GLOBBUMP
	unsigned	globSuper;		//!< [boolean] See LXsICHAN_RENDER_GLOBSUPER
	unsigned	globReject;		//!< [boolean] See LXsICHAN_RENDER_GLOBREJECT
	unsigned	globCaus;		//!< [integer] See LXsICHAN_RENDER_GLOBCAUS

	unsigned	irrCache;		//!< [integer] See LXsICHAN_RENDER_IRRCACHE
	unsigned	irrUsage;		//!< [integer] See LXsICHAN_RENDER_IRRUSAGE
	unsigned	irrDirect2;		//!< [integer] See LXsICHAN_RENDER_IRRDIRECT2
	unsigned	irrRays;		//!< [integer] See LXsICHAN_RENDER_IRRRAYS
	unsigned	irrRays2;		//!< [integer] See LXsICHAN_RENDER_IRRRAYS2
	unsigned	irrRate;		//!< [integer] See LXsICHAN_RENDER_IRRRATE
	unsigned	irrRatio;		//!< [integer] See LXsICHAN_RENDER_IRRRATIO
	unsigned	irrSmooth;		//!< [integer] See LXsICHAN_RENDER_IRRSMOOTH
	unsigned	irrRetrace;		//!< [integer] See LXsICHAN_RENDER_IRRRETRACE
	unsigned	irrVals;		//!< [integer] See LXsICHAN_RENDER_IRRVALS
	unsigned	irrGrads;		//!< [integer] See LXsICHAN_RENDER_IRRGRADS
	unsigned	irrSample;		//!< [integer] See LXsICHAN_RENDER_IRRSAMPLE
	unsigned	irrData;		//!< [integer] See LXsICHAN_RENDER_IRRDATA
	unsigned	irrStart;		//!< [integer] See LXsICHAN_RENDER_IRRSTART
	unsigned	irrEnd;			//!< [integer] See LXsICHAN_RENDER_IRREND
	unsigned	irrWalk;		//!< [integer] See LXsICHAN_RENDER_IRRWALK
	unsigned	irrLEnable;		//!< [integer] See LXsICHAN_RENDER_IRRLENABLE
	unsigned	irrSEnable;		//!< [integer] See LXsICHAN_RENDER_IRRSENABLE
	const char*	irssLName;		//!< [string] See LXsICHAN_RENDER_IRRLNAME
	const char*	irssSName;		//!< [string] See LXsICHAN_RENDER_IRRSNAME

	unsigned	radCache;		//!< [integer] See LXsICHAN_RENDER_RADCACHE
	unsigned	envSample;		//!< [integer] See LXsICHAN_RENDER_ENVSAMPLE
	unsigned	envRays;		//!< [integer] See LXsICHAN_RENDER_ENVRAYS
	unsigned	envMIS;			//!< [integer] See LXsICHAN_RENDER_ENVMIS

	unsigned	causEnable;		//!< [integer] See LXsICHAN_RENDER_CAUSENABLE
	float		causMult;		//!< [float] See LXsICHAN_RENDER_CAUSMULT
	unsigned	causTotal;		//!< [integer] See LXsICHAN_RENDER_CAUSTOTAL
	unsigned	causLocal;		//!< [integer] See LXsICHAN_RENDER_CAUSLOCAL
	unsigned	causWalk;		//!< [integer] See LXsICHAN_RENDER_CAUSWALK

	unsigned	rayShadow;		//!< [integer] See LXsICHAN_RENDER_RAYSHADOW
	unsigned	reflDepth;		//!< [integer] See LXsICHAN_RENDER_REFLDEPTH
	unsigned	refrDepth;		//!< [integer] See LXsICHAN_RENDER_REFRDEPTH
	float		rayThresh;		//!< [float] See LXsICHAN_RENDER_RAYTHRESH
	unsigned	unbiased;		//!< [integer] See LXsICHAN_RENDER_UNBIASED
	float		rayClamp;		//!< [float] See LXsICHAN_RENDER_RAYCLAMP
	float		rayOffset;		//!< [float] See LXsICHAN_RENDER_RAYOFFSET
	unsigned	reflSmps;		//!< [integer] See LXsICHAN_RENDER_REFLSMPS
	unsigned	refrSmps;		//!< [integer] See LXsICHAN_RENDER_REFRSMPS
	unsigned	specSmps;		//!< [integer] See LXsICHAN_RENDER_SPECSMPS
	unsigned	subsSmps;		//!< [integer] See LXsICHAN_RENDER_SUBSSMPS
	unsigned	animNoise;		//!< [integer] See LXsICHAN_RENDER_ANIMNOISE
	unsigned	noiseSeed;		//!< [integer] See LXsICHAN_RENDER_NOISESEED
	unsigned	rayAccel;		//!< [integer] See LXsICHAN_RENDER_RAYACCEL
	unsigned	batchSize;		//!< [integer] See LXsICHAN_RENDER_BATCHSIZE
	unsigned	impBoost;		//!< [integer] See LXsICHAN_RENDER_IMPBOOST
	unsigned	directSmps;		//!< [integer] See LXsICHAN_RENDER_DIRECTSMPS
	unsigned	directMIS;		//!< [integer] See LXsICHAN_RENDER_DIRECTMIS
	unsigned	multiGeo;		//!< [integer] See LXsICHAN_RENDER_MULTIGEO
	unsigned	mergeFur;		//!< [integer] See LXsICHAN_RENDER_MERGEFUR
	unsigned	subdAdapt;		//!< [integer] See LXsICHAN_RENDER_SUBDADAPT
	float		subdRate;		//!< [float] See LXsICHAN_RENDER_SUBDRATE
	unsigned	dispEnable;		//!< [integer] See LXsICHAN_RENDER_DISPENABLE
	float		dispRate;		//!< [float] See LXsICHAN_RENDER_DISPRATE
	float		dispRatio;		//!< [float] See LXsICHAN_RENDER_DISPRATIO
	float		dispJitter;		//!< [float] See LXsICHAN_RENDER_DISPJITTER
	float		edgeMin;		//!< [float] See LXsICHAN_RENDER_EDGEMIN
	unsigned	dispSmooth;		//!< [integer] See LXsICHAN_RENDER_DISPSMOOTH
	unsigned	dispBump;		//!< [integer] See LXsICHAN_RENDER_DISPBUMP
	unsigned	camera;			//!< [integer] Always 0 

	/// Initialise this instance from the specified item (must be of type citRender), reading channel values from the specified channel reader
	LxResult Init (CLxUser_Item& item, CLxUser_ChannelRead& chan);
};

//-----------------------------------------------------------------------------
/**
 * Every light has a light material defining shading properties.
 * Once initialised, the public members can be queried.
 */
//-----------------------------------------------------------------------------
class CLxLightMaterial
{
public:
	LXtColorRGB		color;		//!< [color]   Light color, see LXsICHAN_LIGHTMATERIAL_LIGHTCOL[.R][.G][.B]
	float			diffuse;	//!< [percent] Diffuse percent, see LXsICHAN_LIGHTMATERIAL_DIFFUSE
	float			specular;	//!< [percent] Specular percent, see LXsICHAN_LIGHTMATERIAL_SPECULAR
	float			caustics;	//!< [percent] Cuastics percent see LXsICHAN_LIGHTMATERIAL_CAUSTICS
	float			subsurface;	//!< [percent] Subsurface percent see LXsICHAN_LIGHTMATERIAL_SUBSURF
	LXtColorRGB		shadCol;	//!< [color]   Shadowing color see LXsICHAN_LIGHTMATERIAL_SHADCOL[.R][.G][.B]
	LXtColorRGB		scatCol;	//!< [color]   Volumetric scattering color see LXsICHAN_LIGHTMATERIAL_SCATCOL[.R][.G][.B]
	float			scatter;	//!< [percent] Volumetric scattering percent see LXsICHAN_LIGHTMATERIAL_SCATTER
	float			density;	//!< [percent] Volumetric density percent see LXsICHAN_LIGHTMATERIAL_DENSITY
	float			attenuate;	//!< [percent] Volumetric light attenuation percent see LXsICHAN_LIGHTMATERIAL_ATTENUATE
	float			shift;		//!< [percent] Volumetric light shift percent see LXsICHAN_LIGHTMATERIAL_SHIFT

	/// Construct an instance with default values
	CLxLightMaterial ();

	/// Initialise this instance from the specified item (must be of type citLightMaterial), reading channel values from the specified channel reader
	LxResult Init (CLxUser_Item& item, CLxUser_ChannelRead& chan);
};

//-----------------------------------------------------------------------------
/**
 * Common base class to all light items.
 * Once initialised, the public members can be queried.
 */
//-----------------------------------------------------------------------------
class CLxLight
{
public:

	CLxLightMaterial	material;	//!< The material associated with the light

	ILxUnknownID		lightItem;		//!< The item representing the light

	LXtMatrix			xfrm;		//!< Rotation matrix in world space
	LXtVector			wpos;		//!< Translation in world space

	float				radiance;	//!< [light] The radiance of the light which modulates the color, see LXsICHAN_LIGHT_RADIANCE
	int					fallType;	//!< [integer] Falloff type for light intensity.  The default is inverse distance squared. LXsICVAL_LIGHT_FALLTYPE_XXX (NONE, INVDIST, INVDIST2), see LXsICHAN_LIGHT_FALLTYPE
	float				range;		//!< [gradient:distance->percent] Gradient falloff for light intensity (radiance). Total intensity is modulated by this percentage as a function of distance, see LXsICHAN_LIGHT_RANGE
	int					shadType;	//!< [integer] Shadow type LXiICVAL_LIGHT_SHADTYPE_XXX (NONE, RAY, MAP, PORTAL), see LXsICHAN_LIGHT_SHADTYPE
	int					shadRes;	//!< [integer] Shadow map (depth buffer) resolution, see LXsICHAN_LIGHT_SHADRES
	float				shadSpot;	//!< [float] Shadow spot size, used for shadow map filtering, see LXsICHAN_LIGHT_SHADSPOT
	int					samples;	//!< [integer] Number of samples for distributed lights, see LXsICHAN_LIGHT_SAMPLES
	float				importance;	//!< [percentage] Multiplier to increase or decrease importance used for light sample allocation, see LXsICHAN_LIGHT_IMPORTANCE
	int					visCam;		//!< [boolean] true if the light should create luminous geometry visible to the camera reflections, or refractions, see LXsICHAN_LIGHT_VISCAM
	int					visRefl;	//!< [boolean] true if the light should create luminous geometry visible to the reflections or refractions, see LXsICHAN_LIGHT_VISREFL
	int					visRefr;	//!< [boolean] true if the light should create luminous geometry visible to the refractions, see LXsICHAN_LIGHT_VISREFR
	float				target;		//!< [distance] see LXsICHAN_LIGHT_TARGET

	/// Initialise this instance from the specified item (must be of type citLight), reading channel values from the specified channel reader
	LxResult Init (CLxUser_Item& item, CLxUser_ChannelRead& chan);

	/// Return the type of the light item
	LXtItemType Type () const
	{
		if (lightItem)
		{
			CLxUser_Item	itm (lightItem);

			return itm.Type ();
		}
		
		return LXiTYPE_NONE;
	}
};

//-----------------------------------------------------------------------------
 /**
  * Class representing a directional light.
  * Once initialised, the public members can be queried.
  * Objects of this type are intended to be stack based.
  *
  * NOTE that LXSunLight is by default simple directional light unless sunPos
  * channel is set to true.
  */
//-----------------------------------------------------------------------------
class CLxSunLight : public CLxLight
{
public:
	
	float			spread;			//!< [angle], see LXsICHAN_SUNLIGHT_SPREAD
	float			mapSize;		//!< [distance], see LXsICHAN_SUNLIGHT_MAPSIZE
	
	// Below are physical sun channels
	int				sunPos;			//!< [boolean] Enable physical sun positioning based on date/time/gps, if false the light is directional light, see LXsICHAN_SUNLIGHT_SUNPOS
	float			lon;			//!< [angle] // Lux HQ: 122 18'5.4" W Long. = 122.3015 deg = 2.134563855 radians, see LXsICHAN_SUNLIGHT_LON
	float			lat;			//!< [angle] // Lux HQ: 37 33' 30.87" N Lat. = 37.532 deg = 0.655057 radians, see LXsICHAN_SUNLIGHT_LAT
	int				day;			//!< [date]  day-of-year 6/21 longest day, use GetDate() to get day, month and year, see LXsICHAN_SUNLIGHT_DAY
	float			time;			//!< [timeofday] time of day , see LXsICHAN_SUNLIGHT_TIME
	float			azimuth;		//!< [angle] // computed results, see LXsICHAN_SUNLIGHT_AZIMUTH
	float			elevation;		//!< [angle], see LXsICHAN_SUNLIGHT_ELEVATION
	float			haze;			//!< [float] turbidity, see LXsICHAN_SUNLIGHT_HAZE
	int				clamp;			//!< [integer] disable full physical intensity, see LXsICHAN_SUNLIGHT_CLAMP
	float			north;			//!< [angle] offset of north direction, see LXsICHAN_SUNLIGHT_NORTH
	float			timeZone;		//!< [float] // SF timezone (offset from GMT, WEST NEGATIVE), see LXsICHAN_SUNLIGHT_TIMEZONE
	float			height;			//!< [distance], see LXsICHAN_SUNLIGHT_DISTANCE
	float			radius;			//!< [distance], see LXsICHAN_SUNLIGHT_RADIUS
	int				thinning;		//!< [boolean], see LXsICHAN_SUNLIGHT_THINNING
	int				summerTime;		//!< [boolean], see LXsICHAN_SUNLIGHT_SUMMERTIME
	float			gamma;			//!< [float] gamma, see LXsICHAN_SUNLIGHT_GAMMA
	int				useWorldXfrm;	//!< [boolean], see LXsICHAN_SUNLIGHT_USEWORLDXFORM

	/// Initialise this instance from the specified item (must be of type citSunLight), reading channel values from the specified channel reader
	LxResult Init (CLxUser_Item& item, CLxUser_ChannelRead& chan);

	/// Given the date (obtained from CLxSunLight::day), it returns day of the year
	static int GetDate (const int date);
};


//-----------------------------------------------------------------------------
// To keep things consistent with SDK the DirectionalLight is same as SunLight
//-----------------------------------------------------------------------------
typedef CLxSunLight CLxDirectionaLight;

//-----------------------------------------------------------------------------
/**
 * Class representing a point light.
 * Once initialised, the public members can be queried.
 * Objects of this type are intended to be stack based.
 */
//-----------------------------------------------------------------------------
class CLxPointLight : public CLxLight
{
public:

	float			radius;		//!< [distance], see LXsICHAN_POINTLIGHT_RADIUS
	float			vrad;		//!< [distance], see LXsICHAN_POINTLIGHT_VRAD

	/// Initialise this instance from the specified item (must be of type citPointLight), reading channel values from the specified channel reader
	LxResult Init (CLxUser_Item& item, CLxUser_ChannelRead& chan);
};

//-----------------------------------------------------------------------------
/**
 * Class representing a spot light.
 * Once initialised, the public members can be queried.
 * Objects of this type are intended to be stack based.
 */
//-----------------------------------------------------------------------------
class CLxSpotLight : public CLxLight
{
public:

	float			radius;		//!< [distance] see LXsICHAN_SPOTLIGHT_RADIUS
	float			cone;		//!< [angle] see LXsICHAN_SPOTLIGHT_CONE
	float			edge;		//!< [angle] see LXsICHAN_SPOTLIGHT_EDGE
	int				outside;	//!< [boolean] see LXsICHAN_SPOTLIGHT_OUTSIDE
	float			height;		//!< [distance] see LXsICHAN_SPOTLIGHT_HEIGHT
	float			base;		//!< [distance] see LXsICHAN_SPOTLIGHT_BASE

	/// Initialise this instance from the specified item (must be of type citSpotLight), reading channel values from the specified channel reader
	LxResult Init (CLxUser_Item& item, CLxUser_ChannelRead& chan);
};

//-----------------------------------------------------------------------------
/**
 * Class representing an area light.
 * Once initialised, the public members can be queried.
 * Objects of this type are intended to be stack based.
 */
//-----------------------------------------------------------------------------
class CLxAreaLight : public CLxLight
{
public:

	int				shape;		//!< [integer] One of the LXi_AREALIGHT_SHAPE_XXX, see LXsICHAN_AREALIGHT_SHAPE
	float			width;		//!< [distance] see LXsICHAN_AREALIGHT_HEIGHT
	float			height;		//!< [distance] see LXsICHAN_AREALIGHT_WIDTH

	/// Initialise this instance from the specified item (must be of type citAreaLight), reading channel values from the specified channel reader
	LxResult Init (CLxUser_Item& item, CLxUser_ChannelRead& chan);
};

//-----------------------------------------------------------------------------
/**
 * Class representing a geometric light.
 * Once initialised, the public members can be queried.
 * Objects of this type are intended to be stack based.
 */
//-----------------------------------------------------------------------------
class CLxMeshLight : public CLxLight
{
public:

	/// Wrapper around geometry data representing the light shape
	struct Geo
	{
		lx::FloatVector*	vPos;	//!< Pointer to vector of floats for position
		lx::FloatVector*	vNrm;	//!< Pointer to vector of floats for normals
		lx::UIntVector*		tris;	//!< Pointer to triangle indices

		unsigned	nTris, nVrts;	//!< Number of triangles and vertices

		/// Construct a default instance
		Geo ()
			: vPos (nullptr)
			, vNrm (nullptr)
			, tris (nullptr)
			, nTris (0)
			, nVrts (0)
		{
		}

		/// Constuct an instance, passing in position, normal, and index vector pointers (empty allocated storage at this point). See GetGeo(). No triangle or vertex counts are calculated.
		Geo (lx::FloatVector* pos, lx::FloatVector* nrm, lx::UIntVector* tri)
			: vPos (pos)
			, vNrm (nrm)
			, tris (tri)
			, nTris (0)
			, nVrts (0)
		{
		}
	};

	ILxUnknownID		meshItem;	//!< [object] CLxUser_Item, the original mesh light item

	/// Initialise this instance from the specified item (must be of type citMeshLight), reading channel values from the specified channel reader
	LxResult Init (CLxUser_Item& item, CLxUser_ChannelRead& chan);

	// NOTE: CLxUser_Surface requires to be initialied in the main thread, otherwise we can get an empty geometry.
	//       Just call this method in the main thread during light scan and then it's safe to call GetGeo() later
	//       in the render thread(s).
	LxResult PrepareGeo (CLxUser_ChannelRead& chan);

	/// Walk the triangulated geometry for the mesh light item that initialised that object, storing the result in the Geo argument passed in.
	LxResult GetGeo (CLxUser_ChannelRead& chan, Geo& geo);
};

//-----------------------------------------------------------------------------
/**
 * Class representing a camera.
 * Once initialised, the public members can be queried.
 * Objects of this type are intended to be stack based.
 */
//-----------------------------------------------------------------------------
class CLxCamera
{
public:

	ILxUnknownID			item;							//!< The camera item initialising this object

	LXtFVector				eyePos;							//!< [vector] Camera position. Extracted from the 4x4 transform
	LXtMatrix				xfrm, invXfrm;					//!< [matrix] Obtained from the camera locator, and inverse is calculated
	float					focalLength;					//!< [float] See LXsICHAN_CAMERA_FOCALLEN
	int						dof;							//!< [integer] See LXsICHAN_CAMERA_DOF
	float					focusDist, fStop;				//!< [float] See LXsICHAN_CAMERA_FOCUSDIST and LXsICHAN_CAMERA_FSTOP
	float					irisRot, irisBias, distort;		//!< [float] See LXsICHAN_CAMERA_IRISROTATION, LXsICHAN_CAMERA_IRISBIAS and LXsICHAN_CAMERA_DISTORT
	float					ioDist, convDist;				//!< [float] See LXsICHAN_CAMERA_IODIST and LXsICHAN_CAMERA_CONVDIST
	float					blurLength, blurOffset;			//!< [float] See LXsICHAN_CAMERA_BLURLEN and LXsICHAN_CAMERA_BLUROFF
	float					apertureX, apertureY;			//!< [float] See LXsICHAN_CAMERA_APERTUREX and LXsICHAN_CAMERA_APERTUREY
	float					offsetX, offsetY;				//!< [float] See LXsICHAN_CAMERA_OFFSETX and LXsICHAN_CAMERA_OFFSETY
	float					squeeze;						//!< [float] See LXsICHAN_CAMERA_SQUEEZE
	float					target;							//!< [float] See LXsICHAN_CAMERA_TARGET
	float					clipDist;						//!< [float] See LXsICHAN_CAMERA_CLIPDIST
	int						clipping;						//!< [integer] See LXsICHAN_CAMERA_CLIPPING
	int						filmFit;						//!< [integer] See LXsICHAN_CAMERA_FILMFIT
	int						projType;						//!< LXiICVAL_CAMERA_PROJTYPE_XXX
	int						irisBlades;						//!< [integer] See LXsICHAN_CAMERA_IRISBLADES
	int						useMask;						//!< [integer] See LXsICHAN_CAMERA_USEMASK
	float					overscan;						//!< [float] See LXsICHAN_CAMERA_OVERSCAN
	float					filmRoll;						//!< [float] See LXsICHAN_CAMERA_FILMROLL

	unsigned int			width;							//!< [integer] See LXsICHAN_POLYRENDER_RESX, from the render item
	unsigned int			height;							//!< [integer] See LXsICHAN_POLYRENDER_RESY, from the render item
	float					pixelAspect;					//!< [float] See LXsICHAN_POLYRENDER_PASPECT, from the render item
	float					dpi;							//!< [float] See LXsICHAN_POLYRENDER_DPI, from the render item
	float					regX0, regX1, regY0, regY1;		//!< 0.0, 1.0, 0.0, 1.0. respectively

	// Default constructor
	CLxCamera ();

	/// Initialise this instance from the specified item (must be of type citCamera), reading channel values from the specified channel reader
	LxResult Init (CLxUser_Item& item, CLxUser_ChannelRead& chan);
};

//-----------------------------------------------------------------------------
/**
 * Class representing a texture layer. This is the base class for a number of other item types.
 * Once initialised, the public members can be queried.
 * Objects of this type are intended to be stack based.
 */
//-----------------------------------------------------------------------------
class CLxTextureLayer
{
public:

	int				enable;		//!< [boolean] Allows you to temporarily enable/disable a layer without losing stored values, see LXsICHAN_TEXTURELAYER_ENABLE
	float			opacity;	//!< [percent] At 100% (1.0) a layer is completely opaque, values below 100% change the transparency of the current
								//!< material layer allowing other lower layers to become visible, ramping toward completely transparent at 0% essentially disabling the layer.
								//!< If only one environment material is present, modifying the opacity fades the brightness of the background and affects how much it contributes to global illumination.
								//!< See LXsICHAN_TEXTURELAYER_OPACITY
	int				blend;		//!< [integer] Affects blending between material layers allowing you to stack several layers for different effects. LXi_TEXLAYER_BLEND_XXX. See LXsICHAN_TEXTURELAYER_BLEND
	int				invert;		//!< [boolean] This setting inverts any RGB color values specified in the environment material, see LXsICHAN_TEXTURELAYER_INVERT
	const char*		effect;		//!< [string] Effect that this layer is associated with, see LXsICHAN_TEXTURELAYER_EFFECT.

	/// Initialise this instance from the specified item (must be of type citTextureLayer), reading channel values from the specified channel reader
	LxResult Init (CLxUser_Item& item, CLxUser_ChannelRead& chan);

};

//-----------------------------------------------------------------------------
/**
 * Class representing an advanced material.
 * Once initialised, the public members can be queried.
 * Objects of this type are intended to be stack based.
 */
//-----------------------------------------------------------------------------
class CLxAdvMaterial : public CLxTextureLayer
{
public:

	ILxUnknownID		item;			//!< Shader tree item associated with this material

	LXtColorRGB			diffCol;		//!< [color] See LXsICHAN_ADVANCEDMATERIAL_DIFFCOL[.R][.G][.B]
	float				diffAmt;		//!< [percent] See LXsICHAN_ADVANCEDMATERIAL_DIFFAMT
	LXtColorRGB			specCol;		//!< [color] See LXsICHAN_ADVANCEDMATERIAL_SPECCOL[.R][.G][.B]
	float				specAmt;		//!< [percent] See LXsICHAN_ADVANCEDMATERIAL_SPECAMT
	LXtColorRGB			reflCol;		//!< [color] See LXsICHAN_ADVANCEDMATERIAL_REFLCOL[.R][.G][.B]
	float				reflAmt;		//!< [percent] See LXsICHAN_ADVANCEDMATERIAL_REFLAMT
	LXtColorRGB			tranCol;		//!< [color] See LXsICHAN_ADVANCEDMATERIAL_TRANCOL[.R][.G][.B]
	float				tranAmt;		//!< [percent] See LXsICHAN_ADVANCEDMATERIAL_TRANAMT
	LXtColorRGB			subsCol;		//!< [color] See LXsICHAN_ADVANCEDMATERIAL_SUBSCOL[.R][.G][.B]
	float				subsAmt;		//!< [percent] See LXsICHAN_ADVANCEDMATERIAL_SUBSAMT
	LXtColorRGB			lumiCol;		//!< [color] See LXsICHAN_ADVANCEDMATERIAL_LUMICOL[.R][.G][.B]
	float				radiance;		//!< [percent] See LXsICHAN_ADVANCEDMATERIAL_RADIANCE
	LXtColorRGB			exitCol;		//!< [color] See LXsICHAN_ADVANCEDMATERIAL_EXITCOL[.R][.G][.B]
	float				coatAmt;		//!< [percent] See LXsICHAN_ADVANCEDMATERIAL_COATAMT
	float				dissAmt;		//!< [percent] See LXsICHAN_ADVANCEDMATERIAL_DISSAMT
	float				diffRough;		//!< [percent] See LXsICHAN_ADVANCEDMATERIAL_DIFFROUGH
	float				rough;			//!< [percent] See LXsICHAN_ADVANCEDMATERIAL_ROUGH
	float				coatRough;		//!< [percent] See LXsICHAN_ADVANCEDMATERIAL_COATROUGH
	float				coatBump;		//!< [percent] See LXsICHAN_ADVANCEDMATERIAL_COATBUMP
	float				aniso;			//!< [percent] See LXsICHAN_ADVANCEDMATERIAL_ANISO
	float				specFres;		//!< [percent] See LXsICHAN_ADVANCEDMATERIAL_SPECFRES
	float				reflFres;		//!< [percent] See LXsICHAN_ADVANCEDMATERIAL_REFLFRES
	float				refIndex;		//!< [float] See LXsICHAN_ADVANCEDMATERIAL_REFINDEX
	float				disperse;		//!< [float] See LXsICHAN_ADVANCEDMATERIAL_DISPERSE
	float				tranRough;		//!< [percent] See LXsICHAN_ADVANCEDMATERIAL_TRANROUGH
	float				tranDist;		//!< [distance] See LXsICHAN_ADVANCEDMATERIAL_TRANDIST
	float				subsDist;		//!< [distance] See LXsICHAN_ADVANCEDMATERIAL_SUBSDIST
	float				subsDepth;		//!< [distance] See LXsICHAN_ADVANCEDMATERIAL_SUBSDEPTH
	float				subsPhase;		//!< [percent] See LXsICHAN_ADVANCEDMATERIAL_SUBSPHASE
	float				bump;			//!< [percent] See LXsICHAN_ADVANCEDMATERIAL_BUMP
	float				bumpAmp;		//!< [distance] See LXsICHAN_ADVANCEDMATERIAL_BUMPAMP
	float				displace;		//!< [distance] See LXsICHAN_ADVANCEDMATERIAL_DISPLACE
	float				smooth;			//!< [percent] See LXsICHAN_ADVANCEDMATERIAL_SMOOTH
	float				smAngle;		//!< [angle] See LXsICHAN_ADVANCEDMATERIAL_SMANGLE
	float				rndWidth;		//!< [distance] See LXsICHAN_ADVANCEDMATERIAL_RNDWIDTH
	float				rndAngle;		//!< [angle] See LXsICHAN_ADVANCEDMATERIAL_RNDANGLE
	LXtColorRGB			clipCol;		//!< [color] See LXsICHAN_ADVANCEDMATERIAL_CLIPCOL[.R][.G][.B]
	float				clipValue;		//!< [percent] See LXsICHAN_ADVANCEDMATERIAL_CLIPVAL
	float				importance;		//!< [percent] See LXsICHAN_ADVANCEDMATERIAL_IMPORTANCE
	LXtColorRGB			scatterCol;		//!< [color] See LXsICHAN_ADVANCEDMATERIAL_SCATTERCOL[.R][.G][.B]
	float				scatterAmt;		//!< [percent] See LXsICHAN_ADVANCEDMATERIAL_SCATTERAMT
	LXtColorRGB			absorbCol;		//!< [color] See LXsICHAN_ADVANCEDMATERIAL_ABSORBCOL[.R][.G][.B]
	float				absorbAmt;		//!< [percent] See LXsICHAN_ADVANCEDMATERIAL_ABSORBAMT
	float				density;		//!< [percent] See LXsICHAN_ADVANCEDMATERIAL_DENSITY
	float				redShift;		//!< [percent] See LXsICHAN_ADVANCEDMATERIAL_REDSHIFT
	LXtColorRGB			luminousCol;	//!< [color] See LXsICHAN_ADVANCEDMATERIAL_CLIPCOL[.R][.G][.B]
	float				luminousAmt;	//!< [percent] See LXsICHAN_ADVANCEDMATERIAL_LUMINOUSAMT
	float				sheen;			//!< [percent], default is 0.0, min is 0.0 See LXsICHAN_ADVANCEDMATERIAL_SHEEN
	float				sheenTint;		//!< [percent], default is 0.0, min is 0.0 See LXsICHAN_ADVANCEDMATERIAL_SHEENTINT
	float				specTint;		//!< [percent], default is 0.0, min is 0.0 See LXsICHAN_ADVANCEDMATERIAL_SPECTINT
	float				flatness;		//!< [percent], default is 0.0, min is 0.0 See LXsICHAN_ADVANCEDMATERIAL_FLATNESS
	float				metallic;		//!< [percent], default is 0.0, [0.0 - 1.0] See LXsICHAN_ADVANCEDMATERIAL_METALLIC


	float				bumpVal;		//!< [percent] See LXsICHAN_ADVANCEDMATERIAL_BUMPVAL
	float				dispVal;		//!< [percent] See LXsICHAN_ADVANCEDMATERIAL_DISPVAL
	float				stenVal;		//!< [percent] See LXsICHAN_ADVANCEDMATERIAL_STENVAL

	int					dblSided;		//!< [boolean] See LXsICHAN_ADVANCEDMATERIAL_DBLSIDED
	int					brdfType;		//!< [integer] LXi_BRDFTYPE_XXX See LXsICHAN_ADVANCEDMATERIAL_BRDFTYPE
	int					useRefIdx;		//!< [boolean] See LXsICHAN_ADVANCEDMATERIAL_USEREFIDX
	int					reflSpec;		//!< [boolean] See LXsICHAN_ADVANCEDMATERIAL_REFLSPEC
	int					reflType;		//!< [integer] LXi_REFLTYPE_XXX See LXsICHAN_ADVANCEDMATERIAL_REFLTYPE
	int					reflBlur;		//!< [boolean] See LXsICHAN_ADVANCEDMATERIAL_REFLBLUR
	int					reflRays;		//!< [integer] See LXsICHAN_ADVANCEDMATERIAL_REFLRAYS
	int					tranRays;		//!< [integer] See LXsICHAN_ADVANCEDMATERIAL_TRANRAYS
	int					subsSmps;		//!< [integer] See LXsICHAN_ADVANCEDMATERIAL_SUBSMPS
	int					sameSurf;		//!< [boolean] See LXsICHAN_ADVANCEDMATERIAL_SAMESRF
	int					rndSame;		//!< [boolean] See LXsICHAN_ADVANCEDMATERIAL_RNDSAME
	int					clearBump;		//!< [boolean] See LXsICHAN_ADVANCEDMATERIAL_CLEARBUMP
	int					clipMatte;		//!< [boolean] See LXsICHAN_ADVANCEDMATERIAL_CLIPMATTE
	int					clipEnable;		//!< [boolean] See LXsICHAN_ADVANCEDMATERIAL_CLIPENABLE
	int					radInter;		//!< [boolean] See LXsICHAN_ADVANCEDMATERIAL_RADINTER

//	CPDxCUST ("uvMap", "string"), CPDxSTORE (NULL),

	/// Construct a default object
	CLxAdvMaterial ();

	/// Initialise this instance from the specified item (must be of type citAdvancedMaterial), reading channel values from the specified channel reader
	LxResult Init (CLxUser_Item& item, CLxUser_ChannelRead& chan);
};

//-----------------------------------------------------------------------------
/**
 * Class representing a shader.
 * Once initialised, the public members can be queried.
 * Objects of this type are intended to be stack based.
 */
//-----------------------------------------------------------------------------
class CLxDefaultShader : public CLxTextureLayer
{
public:

	float		shadeRate;	//!< [fpixel]  CPDxIHINT(shadeRateHint) see LXsICHAN_DEFAULTSHADER_SHADERATE
	float		dirMult;	//!< [percent] see LXsICHAN_DEFAULTSHADER_DIRMULT
	float		indMult;	//!< [percent] see LXsICHAN_DEFAULTSHADER_INDMULT
	float		indSat;		//!< [percent] see LXsICHAN_DEFAULTSHADER_INDSAT
	float		indSatOut;	//!< [percent] see LXsICHAN_DEFAULTSHADER_INDSATOUT
	int			indType;	//!< [integer] CPDxIHINT(indTypeHint) see LXsICHAN_DEFAULTSHADER_INDTYPE
	int			fogType;	//!< [integer] CPDxIHINT(fogTypeHint) see LXsICHAN_DEFAULTSHADER_FOGTYPE
	int			fogEnv;		//!< [boolean] see LXsICHAN_DEFAULTSHADER_FOGENV
	LXtColorRGB	fogColor;	//!< [color] see LXsICHAN_DEFAULTSHADER_FOGCOLOR[.R][.G][.B]
	float		fogStart;	//!< [distance] see LXsICHAN_DEFAULTSHADER_FOGSTART
	float		fogEnd;		//!< [distance] see LXsICHAN_DEFAULTSHADER_FOGEND
	float		fogDensity;	//!< [percent] see LXsICHAN_DEFAULTSHADER_FOGDENSITY
	int			alphaType;	//!< [integer] CPDxIHINT(alphaTypeHint) see LXsICHAN_DEFAULTSHADER_ALPHATYPE
	float		alphaVal;	//!< [percent] see LXsICHAN_DEFAULTSHADER_ALPHAVAL
	int			lightLink;	//!< [integer] see LXsICHAN_DEFAULTSHADER_LIGHTLINK
	int			shadCast;	//!< [boolean] see LXsICHAN_DEFAULTSHADER_SHADCAST
	int			shadRecv;	//!< [boolean] see LXsICHAN_DEFAULTSHADER_SHADRECV
	int			visCam;		//!< [boolean] see LXsICHAN_DEFAULTSHADER_VISCAM
	int			visInd;		//!< [boolean] see LXsICHAN_DEFAULTSHADER_VISIND
	int			visRefl;	//!< [boolean] see LXsICHAN_DEFAULTSHADER_VISREFL
	int			visRefr;	//!< [boolean] see LXsICHAN_DEFAULTSHADER_VISREFR
	int			visOccl;	//!< [boolean] see LXsICHAN_DEFAULTSHADER_VISOCCL
	int			quaEnable;	//!< [boolean] see LXsICHAN_DEFAULTSHADER_TOGQUA
	int			visEnable;	//!< [boolean] see LXsICHAN_DEFAULTSHADER_TOGVIS
	int			lgtEnable;	//!< [boolean] see LXsICHAN_DEFAULTSHADER_TOGLGT
	int			fogEnable;	//!< [boolean] see LXsICHAN_DEFAULTSHADER_TOGFOG
	int			shdEnable;	//!< [boolean] see LXsICHAN_DEFAULTSHADER_TOGSHD

	/// Initialise this instance from the specified item (must be of type citDefaultShader), reading channel values from the specified channel reader
	LxResult Init (CLxUser_Item& item, CLxUser_ChannelRead& chan);
};

//-----------------------------------------------------------------------------
/**
 * Class representing an image map.
 * Once initialised, the public members can be queried.
 * Objects of this type are intended to be stack based.
 */
//-----------------------------------------------------------------------------
class CLxImageMap : public CLxTextureLayer
{
public:

	ILxUnknownID	item;			//!< The image map item, of type citImageMap
	ILxUnknownID	txtrLocItem;	//!< The locator, if found, of type citTextureLoc
	ILxUnknownID	clipItem;		//!< The clip item, if found, of type citVideoClip

	int				aa;				//!< [boolean] See LXsICHAN_IMAGEMAP_AA
	float			aaVal;			//!< [percent] See LXsICHAN_IMAGEMAP_AAVAL
	int				pixBlend;		//!< [integer] LXi_IMAGEMAP_PIXBLEND_XXX See LXsICHAN_IMAGEMAP_PIXBLEND
	float			minSpot;		//!< [float] See LXsICHAN_IMAGEMAP_MINSPOT
	float			min;			//!< [percent] See LXsICHAN_IMAGEMAP_MIN
	float			max;			//!< [percent] See LXsICHAN_IMAGEMAP_MAX
	float			sourceLow;		//!< [float] See LXsICHAN_IMAGEMAP_SOURCELOW
	float			sourceHigh;		//!< [float] See LXsICHAN_IMAGEMAP_SOURCEHIGH
	int				redInv;			//!< [boolean] See LXsICHAN_IMAGEMAP_REDINV
	int				greenInv;		//!< [boolean] See LXsICHAN_IMAGEMAP_GREENINV
	int				blueInv;		//!< [boolean] See LXsICHAN_IMAGEMAP_BLUEINV
	float			gamma;			//!< [float] See LXsICHAN_IMAGEMAP_GAMMA
	int				swizzling;		//!< [boolean] See LXsICHAN_IMAGEMAP_SWIZZLING
	int				alpha;			//!< [integer] IMAGEMAP_SWIZZLING_RGB, IMAGEMAP_SWIZZLING_RGBA, IMAGEMAP_SWIZZLING_ALPHA_ONLY See LXsICHAN_IMAGEMAP_ALPHA
	int				rgba;			//!< [integer] IMAGEMAP_SWIZZLING_RGB, IMAGEMAP_SWIZZLING_RGBA, IMAGEMAP_SWIZZLING_ALPHA_ONLY, IMAGEMAP_SWIZZLING_RED_ONLY, IMAGEMAP_SWIZZLING_GREEN_ONLY, IMAGEMAP_SWIZZLING_BLUE_ONLY See LXsICHAN_IMAGEMAP_RGBA

	/// Initialise this instance from the specified item (must be of type citImageMap), reading channel values from the specified channel reader
	LxResult Init (CLxUser_Item& item, CLxUser_ChannelRead& chan);
};

//-----------------------------------------------------------------------------
/**
 * Class representing a material group (sometimes also referred to as a mask).
 * Once initialised, the public members can be queried.
 * Objects of this type are intended to be stack based.
 */
//-----------------------------------------------------------------------------
class CLxMaterialGroup : public CLxTextureLayer
{
public:

	ILxUnknownID	item;		//!< Item initialised with, of type citMask

	const char*		ptag;		//!< [string] See LXsICHAN_MASK_PTAG
	const char*		ptyp;		//!< [string] See LXsICHAN_MASK_PTYP
	int				submask;	//!< [integer] See LXsICHAN_MASK_SUBMASK
	int				surfType;	//!< [integer] See LXsICHAN_MASK_STYP
	int				addLayer;	//!< [integer] See LXsICHAN_MASK_ADDLAYER
	int				instApply;	//!< [integer] See LXsICHAN_MASK_INSTAPPLY

	/// Initialise this instance from the specified item (must be of type citMask), reading channel values from the specified channel reader
	LxResult Init (CLxUser_Item& item, CLxUser_ChannelRead& chan);

	/// Returns items that this material group should be applied to
	LxResult Items (lx::UnknownArray& items);
};

//-----------------------------------------------------------------------------
/** EnvironmentMaterial data
 * Class representing an environment material.
 * Once initialised, the public members can be queried.
 * Objects of this type are intended to be stack based.
 *
 * type: Environment Type - Specifies colors and gradients that appear in the background LXi_ENVMATERIAL_ENVTYPE_XXX
 *       4 Color Gradient: This easy to use gradient allows you to set 4 color values which are used to simulate the sky and ground.
 *                         The Zenith color is the color that is directly overhead and this ramps into the Sky color which starts 
 *                         at the horizon and ramps upward. 
 *                         The Nadir color is directly below the camera and ramps upwards into the Ground color which terminates 
 *                         at the horizon when it meets the Sky color. 
 *                         There is a soft blend between the Zenith and Sky colors and a soft blend between Ground and Nadir. 
 *                         The boundary between Ground and Sky is hard edged to give the illusion of a distant horizon. 
 *                         When using a 4 Color Gradient, the Sky and Ground Exponents are used to compress or expand the gradation 
 *                         between Zenith and Sky and the Nadir and Ground.
 *                         Higher values push the gradient transition closer to the horizon, while lower values spread the gradient 
 *                         further across the available spectrum.
 *
 *       2 Color Gradient: This option reduces the colors to Zenith and Nadir and creates a soft ramp between the two.
 *
 *       Constant: Uses only the Zenith color for the entire background.
 *
 *       CIE Overcast Sky: This option provides two user defined color values; Zenith and Nadir. The Nadir color is used without 
 *                         any ramp effect for everything below the horizon. 
 *                         The Zenith color starts directly above the camera and then has a slight ramp to a somewhat darker color. 
 *                         By definition the CIE overcast sky is three times brighter at the Zenith than it is at the horizon, so 
 *                         the Zenith color is reduced in brightness by that amount by the time it reaches the horizon. 
 *                         When this setting is applied with global illumination, you can re-create the traditional overcast render 
 *                         look popular in images that want to show off an untextured model's surface detailing.
 *
 *       Physically-based Daylight: This option works in tandem with global illumination to create renders lit by an incredibly 
 *                                  realistic daylight simulation. Especially useful for architectural exterior and interior renders 
 *                                  or in any scene that needs nice outdoor lighting. 
 *
 *
 * Physically-based Daylight (LXi_ENVMATERIAL_ENVTYPE_PHYSICAL)
 * When Physically-based Daylight is selected as the Environment Type, a few additional options become available, allowing you to 
 * fine-tune the look of the lighting simulation. 
 * Global illumination needs to be enabled in order for the Physically-based Daylight function to work.
 *    sunLight: Sun Light
 *          This setting allows you to set a distant light that are considered the sun in the rendered images. 
 *
 *    dics: Solar Disc Size
 *          A small disk is added to the rendered image, representing the actual sun, above the horizon. It also appears 
 *          in reflections, refractions and so on. The default value of 100% is correct to the scale of what you see in 
 *          the real world, however, you can change the size depending on your particular scene needs using this setting.
 *
 *    haze: Haze Amount
 *          In the real world, as the sun nears the horizon, light has to pass through a greater amount of atmosphere to 
 *          reach our eyes. Additionally, moisture, dust and pollutants in the air further affect the light. The further the 
 *          light has to pass through these particles, the shorter wavelengths of light are absorbed, tending the light 
 *          toward warmer hues. Increasing the Haze setting in Modo pushes the horizon colors toward oranges and yellows 
 *          for midday lighting scenarios and deeper reds (sunsets) in evening times. Time of day can be controlled in the 
 *          distant light's Physical Sun settings.
 *
 *    normalize: Clamp Sky Brightness
 *          The Physically-based Daylight function is a highly accurate lighting simulation generating 
 *          light intensities outside of normal render display settings. 
 *          The Clamp Sky Brightness toggle limits the overall brightness of the sky, producing pleasing results 
 *          more easily. When disabled, you might think your scene is completely 'blown out' and overexposed, but 
 *          actually, since Modo renders in full floating point accuracy, you can bring back all that detail 
 *          using a combination of white level, gamma and tone mapping.
 *
 *    clampedGamma: Sky Gamma
 *          Adjusting gamma is the ability to adjust the overall contrast of a target in a non-linear fashion. 
 *          The Sky Gamma option allows you to adjust the values of the procedurally generated Physically-based Sky lightening 
 *          or darkening it for artistic refinement.
 *
 *    albedoCol: Ground Albedo
 *          This option represents the color of any light reflected from the ground upwards in the overall environmental 
 *          light simulation. You can specify an appropriate scene-specific color using the RGB color navigator. 
 *          The Albedo is color only, having no brightness in the calculation, so RGB values between 0-1 (1-255) are the 
 *          most appropriate.
 *
 *    inscatter: Disc In-Scatter
 *          Mixes in light that has been deflected or scattered out of the direct path from the sun, then gets scattered
 *          back in. This results in a reddish cast around the edge of the solar disc (known as limb-darkening), and 
 *          producing a reddening toward the bottom at low elevations (near sunrise or sunset). This is increasingly 
 *          more noticeable at higher haze levels. A setting of 100% shows the physically correct result attenuating 
 *          toward 0%, which disables the effect, making the solar disc appear as it did in previous versions.
 *
 * The Environment Fog option produces a simulated (non-volumetric) fog effect by applying the environment color to 
 * relevant materials with increased intensity as the geometry is further from the camera. This is also a great option
 * to fade objects into a background, increasing the apparent depth (and scale) of a scene. Fog can also be specified 
 * in the Shader item with similar options. The Environment Fog option differs in that it always uses the the environment 
 * color, whereas for the Shader Fog, any color can be specified.
 *    fogType: Fog Type
 *             Allows you to choose from the different fog types:
 *             None: Disables Environment Fog from rendering.
 *
 *             Linear: When selected, fog renders in the scene based on the Start and End distances, where there is no 
 *                     fog up to the starting distance, then surfaces attenuate toward a solid environment color and 
 *                     maximum fog density at the end distance.
 *
 *             Exponential: When selected, fog renders starting at the camera's position, increasing in strength the 
 *                          further a surface is from the camera. Based on exponential values, the strength increases 
 *                          non-linearly and is directly influenced by the Fog Density setting (so for very large scenes,
 *                          you should use a very small value).
 *
 *             Underwater: This option is basically the same as the Exponential function, except that the fog has a 
 *                         tendency to absorb the environment color more readily, producing an environment colored cast. 
 *                         It also reduces color saturation with distance. For a true underwater look, set the 
 *                         environment to a 2 or 4 color gradient with a blueish or teal color, or apply Shader Fog and 
 *                         define the Fog color independent of the environment.
 *
 *             Layered: Produces a ground fog-like effect where the fog density increases with both depth and height.
 *
 *    fogStart/fogEnd:Fog Start/End Distance
 *                   When the Fog type is set to Linear, you can specify specific starting and ending distances for the fog effect.
 *
 *    fogDensity: Fog Density
 *               This percentage value determines how thick the fog is just in front of the camera. 
 *               The default value of 10% indicates that geometry just in front of the camera has a 10% blend of the fog color. 
 *               The density of the fog increases as it recedes further from the camera.
 *
 *    fogFalloff: Altitude Falloff
 *               This option determines the maximum height of the fog when using the Layered Fog option. 
 *               Fog attenuates from the Base Altitude, fading from maximum density at the base to fully transparent at the 
 *               defined Altitude Falloff value.
 *
 *    fogHeight: Base Altitude
 *               Defines the bottom of the layered fog. Anything below has fog applied up to the maximum density 
 *               (based on distance from camera), and above this value fully attenuates up to the Altitude Falloff.
 */
//-----------------------------------------------------------------------------
class CLxEnvMaterial : public CLxTextureLayer
{
public:

	ILxUnknownID	item;			//!< Item initialised for this, of type citEnvMaterial

	int				type;			//!< [integer] LXi_ENVMATERIAL_ENVTYPE_XXX See LXsICHAN_ENVMATERIAL_TYPE
	LXtColorRGB		zenColor;		//!< [color] See LXsICHAN_ENVMATERIAL_ZENCOLOR[.R][.G][.B]
	LXtColorRGB		skyColor;		//!< [color] See LXsICHAN_ENVMATERIAL_SKYCOLOR[.R][.G][.B]
	LXtColorRGB		gndColor;		//!< [color] See LXsICHAN_ENVMATERIAL_GNDCOLOR[.R][.G][.B]
	LXtColorRGB		nadColor;		//!< [color] See LXsICHAN_ENVMATERIAL_NADCOLOR[.R][.G][.B]
	float			skyExp;			//!< [float] See LXsICHAN_ENVMATERIAL_SKYEXP
	float			gndExp;			//!< [float] See LXsICHAN_ENVMATERIAL_GNDEXP

	// Physically-based Daylight
	ILxUnknownID	sunLight;		//!< sunLight item connected to this environment material See 
	float			disc;			//!< [percent] See LXsICHAN_ENVMATERIAL_DISC
	float			haze;			//!< [float] See LXsICHAN_SUNLIGHT_HAZE
	int				normalize;		//!< [boolean] See LXsICHAN_ENVMATERIAL_NORMALIZE
	float			clampedGamma;	//!< [float] See LXsICHAN_ENVMATERIAL_CLMPGAMMA
	LXtColorRGB		albedoCol;		//!< [color] Ground albedo See LXsICHAN_ENVMATERIAL_ALBEDOCOLOR[.R][.G][.B]
	LXtColorRGB		discCol;		//!< [color] See LXsICHAN_ENVMATERIAL_DISCCOLOR[.R][.G][.B]
	float			inscatter;		//!< [percent] See LXsICHAN_ENVMATERIAL_INSCATTER

	// Environment fog
	int				fogType;		//!< [integer] See LXsICHAN_ENVMATERIAL_FOG_TYPE
	float			fogStart;		//!< [distance] See LXsICHAN_ENVMATERIAL_FOG_START
	float			fogEnd;			//!< [distance] See LXsICHAN_ENVMATERIAL_FOG_END
	float			fogDensity;		//!< [percent] See LXsICHAN_ENVMATERIAL_FOG_DENSITY
	float			fogHeight;		//!< [distance] See LXsICHAN_ENVMATERIAL_FOG_HEIGHT
	float			fogFalloff;		//!< [percent] See LXsICHAN_ENVMATERIAL_FOG_FALLOFF

	/// Initialise this instance from the specified item (must be of type citEnvMaterial), reading channel values from the specified channel reader
	LxResult Init (CLxUser_Item& item, CLxUser_ChannelRead& chan);
};


//-----------------------------------------------------------------------------
/**
 * Environment data
 * Class representing an environment.
 * Once initialised, the public members can be queried.
 * Objects of this type are intended to be stack based.
 *
 *    radiance: Acts as a multiplier, providing you with a convenient way to 
 *              control and modify the overall brightness of the Environment. 
 *              This setting has the greatest effect when global illumination 
 *              is enabled, controlling to what degree the overall environment 
 *              contributes to the lighting of the scene.
 *
 *    visCam: Visible to Camera - Toggles whether or not the selected Environment 
 *            is visible to the camera when rendered. This setting is independent 
 *            to the others, even when not visible to the camera, it can still 
 *            contribute to the lighting of the scene providing you with the 
 *            ability to specify alternate images or textures for the background 
 *            in an additional environment item.
 *
 *    visInd: Visible to Indirect Rays - Toggles whether or not the Environment 
 *            contributes lighting to global illumination. 
 *            This setting only affects scenes that have Global Illumination enabled.
 *
 *    visRefl: Visible to Reflection Rays - Toggles whether or not environments 
 *             have an effect on any reflective surfaces within a scene.
 *             
 *    visRef: Visible to Refraction Rays - Toggles whether or not environments 
 *            have an effect on any refractive surfaces within a scene.
 */
//-----------------------------------------------------------------------------
class CLxEnvironment
{
public:

	ILxUnknownID	item;		//!< The item initialising this, of type citEnvironment

	float			radiance;	//!< [radiance in W/srm2] See LXsICHAN_ENVIRONMENT_RADIANCE
	int				visCam;		//!< [boolean] See LXsICHAN_ENVIRONMENT_VISCAM
	int				visInd;		//!< [boolean] See LXsICHAN_ENVIRONMENT_VISIND
	int				visRefl;	//!< [boolean] See LXsICHAN_ENVIRONMENT_VISREFL
	int				visRefr;	//!< [boolean] See LXsICHAN_ENVIRONMENT_VISREFR

	/// Initialise this instance from the specified item (must be of type citEnvironment), reading channel values from the specified channel reader
	LxResult Init (CLxUser_Item& item, CLxUser_ChannelRead& chan);
};

class CLxUser_Image;

//-----------------------------------------------------------------------------
/**
 * Class representing a video clip. This is the common base class for other item classes.
 * Once initialised, the public members can be queried.
 * Objects of this type are intended to be stack based.
 */
//-----------------------------------------------------------------------------
class CLxVideoClip
{
public:
	LXtObjectID		imageStack;	//!< [object] See LXsICHAN_VIDEOCLIP_IMAGESTACK
	int				interlace;	//!< [integer] See LXsICHAN_VIDEOCLIP_INTERLACE
	int				alphaMode;	//!< [boolean] See LXsICHAN_VIDEOCLIP_ALPHAMODE
	float			fps;		//!< [float] See LXsICHAN_VIDEOCLIP_FPS
	int				udim;		//!< [integer] See LXsICHAN_VIDEOCLIP_UDIM
	const char*		colorspace;	//!< [string] See LXsICHAN_VIDEOCLIP_COLORSPACE
	int				enable;		//!< [boolean] See LXsICHAN_VIDEOCLIP_ENABLE
	float			opacity;	//!< [percent] See LXsICHAN_VIDEOCLIP_OPACITY
	int				blend;		//!< [integer] See LXsICHAN_VIDEOCLIP_BLEND

	/// Initialise this instance from the specified item (must be of type citVideoClip), reading channel values from the specified channel reader
	LxResult Init (CLxUser_Item& item, CLxUser_ChannelRead& chan);

	/// Return the image in the clip, optionally returning metrics too
	LxResult GetImage (CLxUser_Image& image, LXtImageMetrics* metrics);

	virtual ~CLxVideoClip(); // CLxVideoClip is a base class
	
protected:
	virtual void zero_members(); // since you can't memset a class instance with a vtable
};

//-----------------------------------------------------------------------------
/**
 * Class representing a video still image.
 * Once initialised, the public members can be queried.
 * Objects of this type are intended to be stack based.
 */
//-----------------------------------------------------------------------------
class CLxVideoStill : public CLxVideoClip
{
public:

	const char*	filename;	//!< [filepath] see LXsICHAN_VIDEOSTILL_FILENAME
	const char*	format;		//!< [string] see LXsICHAN_VIDEOSTILL_FORMAT

	/// Initialise this instance from the specified item (must be of type citVideoStill), reading channel values from the specified channel reader
	LxResult Init (CLxUser_Item& item, CLxUser_ChannelRead& chan);
	
protected:
	void zero_members() override;
};

//-----------------------------------------------------------------------------
/**
 * Class representing a video sequence of images.
 * Once initialised, the public members can be queried.
 * Objects of this type are intended to be stack based.
 */
//-----------------------------------------------------------------------------
class CLxVideoSequence : public CLxVideoClip
{
public:

	const char*	pattern;	//!< [string] See LXsICHAN_VIDEOSEQUENCE_PATTERN
	int		firstFrame;		//!< [integer] See LXsICHAN_VIDEOSEQUENCE_FIRSTFRAME
	int		lastFrame;		//!< [integer] See LXsICHAN_VIDEOSEQUENCE_LASTFRAME
	int		startFrame;		//!< [integer] See LXsICHAN_VIDEOSEQUENCE_STARTFRAME
	int		endBehavior;	//!< [integer] See LXsICHAN_VIDEOSEQUENCE_ENDBEHAVIOR

	/// Initialise this instance from the specified item (must be of type citVideoSequence), reading channel values from the specified channel reader
	LxResult Init (CLxUser_Item& item, CLxUser_ChannelRead& chan);
	
protected:
	void zero_members() override;
};

//-----------------------------------------------------------------------------
/**
 * Class representing an image layer in the shader tree.
 * Once initialised, the public members can be queried.
 * Objects of this type are intended to be stack based.
 */
//-----------------------------------------------------------------------------
class CLxImageLayer : public CLxVideoClip
{
public:

	const char*	filename;	//!< [filepath] See the channel "filename"
	int			layer;		//!< [integer] See the channel "layer"
	const char*	type;		//!< [string]  See the channel "type"

	/// Initialise this instance from the specified item (must be of type citImageLayer), reading channel values from the specified channel reader
	LxResult Init (CLxUser_Item& item, CLxUser_ChannelRead& chan);
	
protected:
	void zero_members() override;
};

//-----------------------------------------------------------------------------
/**
 * Class representing a texture locator.
 * Once initialised, the public members can be queried.
 * Objects of this type are intended to be stack based.
 */
//-----------------------------------------------------------------------------
class CLxTextureLoc
{
public:
	ILxUnknownID	item;					//!< Item used to initialise, of type citTextureLoc

	int				projType;				//!< [integer] LXi_TEXTURE_PROJ_MODE_XXX (lxshade.h) see LXsICHAN_TEXTURELOC_PROJTYPE
	int				projAxis;				//!< [axis] LXi_TEXTURE_PROJ_DIR_XXX (lxshade.h) see LXsICHAN_TEXTURELOC_PROJAXIS
	int				tileU;					//!< [integer] LXiTILE_XXX (lxvector.h) see LXsICHAN_TEXTURELOC_TILEU
	float			wrapU;					//!< [float] see LXsICHAN_TEXTURELOC_WRAPU
	int				tileV;					//!< [integer] LXiTILE_XXX (lxvector.h) see LXsICHAN_TEXTURELOC_TILEV
	float			wrapV;					//!< [float] see LXsICHAN_TEXTURELOC_WRAPV
	int				world;					//!< [boolean] see LXsICHAN_TEXTURELOC_WORLD
	int				fallType;				//!< [integer] LXi_TEXTURE_FALLOFF_XXX (lxtxtr.hpp) see LXsICHAN_TEXTURELOC_FALLTYPE
	float			falloff;				//!< [float] see LXsICHAN_TEXTURELOC_FALLOFF
	const char*		uvMap;					//!< [string] see LXsICHAN_TEXTURELOC_UVMAP
	LXtObjectID		stack;					//!< [object] see LXsICHAN_TEXTURELOC_STACK
	float			m00;					//!< [float] see LXsICHAN_TEXTURELOC_M00
	float			m01;					//!< [float] see LXsICHAN_TEXTURELOC_M01
	float			m02;					//!< [float] see LXsICHAN_TEXTURELOC_M02
	float			m10;					//!< [float] see LXsICHAN_TEXTURELOC_M10
	float			m11;					//!< [float] see LXsICHAN_TEXTURELOC_M11
	float			m12;					//!< [float] see LXsICHAN_TEXTURELOC_M12
	float			m20;					//!< [float] see LXsICHAN_TEXTURELOC_M20
	float			m21;					//!< [float] see LXsICHAN_TEXTURELOC_M21
	float			m22;					//!< [float] see LXsICHAN_TEXTURELOC_M22
	int				worldXfrm;				//!< [boolean] see LXsICHAN_TEXTURELOC_WORLDXFRM
	int				legacyRotation;			//!< [boolean] see LXsICHAN_TEXTURELOC_LEGACYROT
	float			psize;					//!< [float] see LXsICHAN_TEXTURELOC_PSIZE
	float			bias;					//!< [percent] see LXsICHAN_TEXTURELOC_BIAS
	float			gain;					//!< [percent] see LXsICHAN_TEXTURELOC_GAIN
	float			sizeRandom;				//!< [percent] see LXsICHAN_TEXTURELOC_SIZERANDOM
	int				rotation;				//!< [angle] see LXsICHAN_TEXTURELOC_ROTATION
	int				rotRandom;				//!< [angle] see LXsICHAN_TEXTURELOC_ROTRANDOM
	int				localProjection;		//!< [boolean] see LXsICHAN_TEXTURELOC_LOCALPROJ
	int				localNormal;			//!< [boolean] see LXsICHAN_TEXTURELOC_LOCALNRM
	float			textureOffsetAmplitude;	//!< [float] see LXsICHAN_TEXTURELOC_TXTROFFAMPL
	int				uvRotation;				//!< [angle] see LXsICHAN_TEXTURELOC_UVROTATION
	int				useUDIM;				//!< [boolean] see LXsICHAN_TEXTURELOC_USEUDIM
	int				legacyUVRotation;		//!< [boolean] see LXsICHAN_TEXTURELOC_LEGACYUVROT
	int				tngtType;				//!< [integer] LXiTANGENT_DPDU_XXX (lxvector.h) see LXsICHAN_TEXTURELOC_TNGTTYPE
	int				randoffset;				//!< [integer] LXi_TEXTURE_RNDOFFSET_XXX (lxtxtr.h) see LXsICHAN_TEXTURELOC_RANDOFFSET
	int				useOcclusion;			//!< [boolean] see LXsICHAN_TEXTURELOC_USEOCCLUSION
	const char*		vectorMap;				//!< [string] see LXsICHAN_TEXTURELOC_VECTORMAP
	float			overscan;				//!< [percent] see LXsICHAN_TEXTURELOC_OVERSCAN

	LXtMatrix4		uvMat;					//!< Matrix from m00 : m22 members, applied in UV space
	LXtMatrix4		uvRotMat;				//!< Matrix for UV rotation, applied in UV space, if uvRotation is set
	LXtMatrix4		xformMat;				//!< Transformation matrix if worldXfrm is set than this is in world space, otherwise it's same as local xform matrix see 

	/// Initialise this instance from the specified item (must be of type citTextureLoc), reading channel values from the specified channel reader
	LxResult Init (CLxUser_Item& item, CLxUser_ChannelRead& chan);

	~CLxTextureLoc();
};

// Utility functions
namespace lx
{
	/// Fetch the environment item for the provided environment material
	extern bool GetEnvironmentForEnvMaterial (CLxUser_Item& envMat, CLxUser_Item& env);
}

#endif
