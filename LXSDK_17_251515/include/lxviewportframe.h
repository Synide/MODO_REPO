/*
 * LX viewportframe module
 *
 * Copyright 0000
 */
#ifndef LX_viewportframe_H
#define LX_viewportframe_H

typedef struct vt_ILxViewportDest ** ILxViewportDestID;


/*
 * Declare the 'GetTypeID' method.
 * qweb automatically parses 'IxDECL_' statements
 * and generates the requisite macro definitions.
 */
typedef struct vt_ILxViewportDest {
	ILxUnknown	 iunk;
	LXxMETHOD ( const char *,
GetTypeID) (
	LXtObjectID		  self);
} ILxViewportDest;

/*
 * The below four code blocks define and register the ViewportDest COM object.
 * Define our GUID and COM object type name.
 */

	#define LXu_VIEWPORTDEST	"1e39fb54-23b4-46fc-8e13-fea5eb754bc8"
	#define LXa_VIEWPORTDEST	"viewportdest"

#endif