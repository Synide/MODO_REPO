/*
 * LX cliped module
 *
 * Copyright 0000
 */
#ifndef LX_cliped_H
#define LX_cliped_H

typedef struct vt_ILxClipDest ** ILxClipDestID;

	#include <lxcom.h>
	#include <lxvalue.h>



/*
 * Data from ClipDest object can be obtained using these interfaces.
 */
typedef struct vt_ILxClipDest {
	ILxUnknown	 iunk;
	LXxMETHOD( LxResult,
Item) (
	LXtObjectID	  self,
	void		**ppvObj);

	LXxMETHOD( int,
Type) (
	LXtObjectID	 self);

	LXxMETHOD( int,
Location) (
	LXtObjectID	 self);
} ILxClipDest;


	#define LXu_CLIPDEST		"7d40b3b8-c5a4-4918-b8e4-922e629c3ffc"
	#define LXa_CLIPDEST		"ClipDestination"
	//[local]  ILxClipDest
	//[export] ILxClipDest locd

#endif