/*
 * LX proxy module
 *
 * Copyright 0000
 */
#ifndef LX_proxy_H
#define LX_proxy_H

typedef struct vt_ILxSceneContents ** ILxSceneContentsID;
typedef struct vt_ILxProxyOptions ** ILxProxyOptionsID;

	#include <lxcom.h>



/*
 * This adds a new item container with type, internal name and user name.
 * Set the bounding box to the last item container.
 * 
 * Set an item to link to the last item container.
 * 
 * This returns the number of values currently in the container.
 * 
 * These get names out of the container.
 * 
 * 
 * This gets bounding box from the container given by the index.
 * 
 * This gets item type from the container given by the index.
 * 
 * These returns the index of the first container with the given name. If there
 * is no container with the name, it returns LXe_OK, otherwise LXe_NOTFOUND.
 * 
 * 
 * Free all item containers.
 * 
 * This returns the number of links in the item given by the index.
 */
typedef struct vt_ILxSceneContents {
	ILxUnknown	 iunk;
	LXxMETHOD(  LxResult,
Item) (
	LXtObjectID		 self,
	unsigned int		 type,
	const char		*internal_name,
	const char		*user_name);
	LXxMETHOD(  LxResult,
SetBBox) (
	LXtObjectID		 self,
	double			 min_X,
	double			 min_Y,
	double			 min_Z,
	double			 max_X,
	double			 max_Y,
	double			 max_Z);
	LXxMETHOD(  LxResult,
AddLink) (
	LXtObjectID		 self,
	unsigned int		 type,
	const char		*internal_name,
	const char		*user_name);
	LXxMETHOD(  unsigned int,
Count) (
	LXtObjectID		  self);
	LXxMETHOD(  LxResult,
InternalName) (
	LXtObjectID		  self,
	unsigned int		  index,
	char			 *buf,
	unsigned		  len);
	LXxMETHOD(  LxResult,
UserName) (
	LXtObjectID		  self,
	unsigned int		  index,
	char			 *buf,
	unsigned		  len);
	LXxMETHOD(  LxResult,
BBox) (
	LXtObjectID		  self,
	unsigned int		  index,
	LXtBBox			 *box);
	LXxMETHOD(  LxResult,
Type) (
	LXtObjectID		  self,
	unsigned int		  index,
	unsigned int		 *type);
	LXxMETHOD(  LxResult,
ByInternalName) (
	LXtObjectID		 self,
	const char		*internal_name,
	unsigned int		*index);
	LXxMETHOD(  LxResult,
ByUserName) (
	LXtObjectID		  self,
	const char		*user_name,
	unsigned int		*index);
	LXxMETHOD(  LxResult,
Reset) (
	LXtObjectID		  self);
	LXxMETHOD(  unsigned int,
LinkCount) (
	LXtObjectID		  self,
	unsigned int		  index);
} ILxSceneContents;

/*
 * Set the loader to only parses the LXO file and return a list of the item names
 * it contains.
 * Set the loader to load not items. This is a prelude to selecting the items to load.
 * 
 * Add an item to the set of items to load
 * 
 * Set flags about the proxy item loading to the loader.
 */
typedef struct vt_ILxProxyOptions {
	ILxUnknown	 iunk;
	LXxMETHOD(  LxResult,
LoadList) (
	LXtObjectID		 self);
	LXxMETHOD(  LxResult,
LoadNone) (
	LXtObjectID		 self);
	LXxMETHOD(  LxResult,
AddItem) (
	LXtObjectID		 self,
	unsigned int		 type,
	const char		*internal_name,
	const char		*user_name);
	LXxMETHOD(  LxResult,
SetFlags) (
	LXtObjectID		 self,
	unsigned int		 flags);
} ILxProxyOptions;

/*
 * ILxSceneContents stores item type, names and bounding box in the scene file.
 */

	#define LXu_SCENECONTENTS	"89448742-E996-11E1-897D-24D86188709B"
	#define LXa_SCENECONTENTS	"sceneContents"
	//[local]  ILxSceneContents

/*
 * ILxProxyOptions interface allows the mesh proxy system to load only parts of
 * the scene. The methods would be called before loading the scene to alter how
 * it loads.
 */

	#define LXu_PROXYOPTIONS	"68ACA4BE-A274-4D04-A5C9-85ABFA27D2E6"
	#define LXa_PROXYOPTIONS	"proxyOptions"
	// [local]  ILxProxyOptions


	#define LXf_PROPT_ALLOW_NONSURF	 0x01

#endif