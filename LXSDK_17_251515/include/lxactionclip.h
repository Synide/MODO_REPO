/*
 * LX actionclip module
 *
 * Copyright 0000
 */
#ifndef LX_actionclip_H
#define LX_actionclip_H

typedef struct vt_ILxActionClip ** ILxActionClipID;

	#include <lxitem.h>



/*
 * This function must be called after an ActionClip has been created and added to the Actor group.
 * This function can be used to change the active state of an ActionClip item. Zero and one can be
 * passed in the 'state' argument to set the state directly or -1 to toggle the current state.
 * 
 * This function tests whether an ActionClip is active or not.
 * 
 * The enabled state of an ActionClip item is used when the item belongs to a Render Pass group, i.e. a
 * Pass. Only enabled ActionClips will be rendered. Zero and one can be passed in the 'state' argument
 * to set the enable state directly or -1 to toggle the current state.
 * 
 * This function tests whether an ActionClip is enabled or not.
 * 
 * This function gets the Action associated with an ActionClip or ActionPose item.
 * 
 * 
 * This function can be used to get the range of animation in the ActionClip. If the
 * layers argument is set any Action Layers on the Action Clip will be included.
 * 
 * This function creates an ActionClip.
 */
typedef struct vt_ILxActionClip {
	ILxUnknown	 iunk;
	LXxMETHOD(  LxResult,
SetParenting) (
	LXtObjectID		 self,
	LXtObjectID		 group);
	LXxMETHOD(  LxResult,
SetActive) (
	LXtObjectID		 self,
	int			 state);
	LXxMETHOD(  unsigned,
Active) (
	LXtObjectID		 self);
	LXxMETHOD(  LxResult,
SetEnabled) (
	LXtObjectID		 self,
	int			 state);
	LXxMETHOD(  unsigned,
Enabled) (
	LXtObjectID		 self);
	LXxMETHOD(  LxResult,
Action) (
	LXtObjectID		 self,
	double			 time,
	void		       **ppvObj);
	LXxMETHOD ( LxResult,
Extents) (
	LXtObjectID		 self,
	double			*timeS,
	double			*timeE,
	int			 layers);
	LXxMETHOD ( LxResult,
Create) (
	LXtObjectID		 self);
} ILxActionClip;


	#define LXsITYPE_ACTIONCLIP		"actionclip"
	#define LXsITYPE_ACTIONPOSE		"actionpose"

	#define	LXiACTIONCLIP_TYPE_ANIM		0
	#define	LXiACTIONCLIP_TYPE_POSE		1

/*
 * The Action Clip interface provices services for operating on Action Clip items.
 */

	#define LXu_ACTIONCLIP		"A312921B-41D2-4D2A-8678-C90EEA381FAE"
	#define LXa_ACTIONCLIP		"actionclip"
	// [local] ILxActionClip

	// [python] ILxActionClip:Active	bool
	// [python] ILxActionClip:Enabled	bool
	// [python] ILxActionClip:Action	obj ChannelRead (action)

#endif