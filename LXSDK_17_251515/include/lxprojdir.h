/*
 * LX projdir module
 *
 * Copyright 0000
 */
#ifndef LX_projdir_H
#define LX_projdir_H

typedef struct vt_ILxProjDirOverride ** ILxProjDirOverrideID;

	#include <lxcom.h>
	#include <lxserver.h>



/*
 * The interface has a single method.  Returning a failure code will cause the search to
 * walk up the hierarchy of the scene as normal.  A success code will cause the search to
 * start from the path provided by the method.  If that path is empty or doesn't exist, we
 * will not try to find a project directory.
 * We only really expect one server to exist at a time, since this interface is intended
 * for special cases only.  If multiple servers are found, the order is undefined and the
 * first one that returns a success code is the path that is tested.
 */
typedef struct vt_ILxProjDirOverride {
	ILxUnknown	 iunk;
	LXxMETHOD( LxResult,
OverrideWith) (
	LXtObjectID		  self,
	const char		 *originalPath,
	char			 *buf,
	unsigned		  len);
} ILxProjDirOverride;

/*
 * The project directory is normally found by walking up the directory hierarchy containing
 * the scene file itself to look for a .luxproject file.  This can be overridden to look
 * in an arbitrary path by implmenting an ILxProjDirOverride server.
 */

	#define LXu_PROJDIROVERRIDE	"257bac48-5e70-42a3-b5a4-7eb33fdba114"
	#define LXa_PROJDIROVERRIDE	"projdiroverride"

	// [local] ILxProjDirOverride
	// [export] ILxProjDirOverride pdo

#endif