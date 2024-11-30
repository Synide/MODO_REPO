/*
 * LX drawover module
 *
 * Copyright 0000
 */
#ifndef LX_drawover_H
#define LX_drawover_H

typedef struct vt_ILxDrawingOverride ** ILxDrawingOverrideID;

	#include <lxcom.h>
	#include <lxserver.h>



/*
 * The flags on the interface determine the overrides that it supports.
 * 
 * Get a collection of the affected items
 * 
 * Set a specific item and read the style bits for override.
 * 
 * Read the color for a specific style bit.
 * 
 * Initialize pass drawing with the GL context pointer.
 * 
 * Cleanup any state in the GL context.
 * 
 * Allocate a draw visitor. This is an object specific to a scene and a view,
 * and it draws itself when the Visitor::Evaluate() method is called.
 */
typedef struct vt_ILxDrawingOverride {
	ILxUnknown	 iunk;
	LXxMETHOD( int,
Flags) (
	LXtObjectID		 self);
	LXxMETHOD( LxResult,
AffectedItems) (
	LXtObjectID		 self,
	LXtObjectID		 scene,
	LXtObjectID		 collection);
	LXxMETHOD( LxResult,
SetItem) (
	LXtObjectID		 self,
	LXtObjectID		 item,
	unsigned		*styles);
	LXxMETHOD( LxResult,
GetColor) (
	LXtObjectID		 self,
	unsigned		 style,
	LXtVector4		 rgba);
	LXxMETHOD( LxResult,
InitContext) (
	LXtObjectID		 self);
	LXxMETHOD( void,
CleanupContext) (
	LXtObjectID		 self);
	LXxMETHOD( LxResult,
DrawVisitor) (
	LXtObjectID		 self,
	LXtObjectID		 scene,
	LXtObjectID		 view,
	void		       **ppvObj);
} ILxDrawingOverride;

/*
 * The DrawingOverride interface is an optional interface on package servers.
 * This allows the package, when present in a scene, to override the default
 * drawing of the scene in the interactive viewports,
 */

	#define LXu_DRAWINGOVERRIDE	"52429702-1D97-4B00-8154-6510D34EE8CA"
	// [local]  ILxDrawingOverride
	// [export] ILxDrawingOverride drov


	#define LXfDRAWOVER_ITEM_STYLES	 0x01
	#define LXfDRAWOVER_PASS_SOLID	 0x02


	#define LXfDRAWOVER_STYLE_GHOSTING	 0x01
	#define LXfDRAWOVER_STYLE_WIREFRAME	 0x02

#endif