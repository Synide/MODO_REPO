/*
 * LX listener module
 *
 * Copyright 0000
 */
#ifndef LX_listener_H
#define LX_listener_H

typedef struct vt_ILxListenerService ** ILxListenerServiceID;
typedef struct vt_ILxListenerPort ** ILxListenerPortID;

	#include <lxvalue.h>



/*
 * A listener service allows a client to submit itself as a global
 * listener. The client object is queried for all global listener interfaces and any
 * that are found will subsequently receive notifications as events occur.
 */
typedef struct vt_ILxListenerService {
	ILxUnknown	 iunk;
	LXxMETHOD(  LxResult,
ScriptQuery) (
	LXtObjectID		 self,
	void		       **ppvObj);

	LXxMETHOD(  LxResult,
AddListener) (
	LXtObjectID		 self,
	LXtObjectID		 object);

	LXxMETHOD(  LxResult,
RemoveListener) (
	LXtObjectID		 self,
	LXtObjectID		 object);
} ILxListenerService;

/*
 * Many nexus objects may also support listener ports. By querying for a port
 * interface on an item or scene and adding to that, the listener client will
 * receive events for changes only on that specific object.
 */
typedef struct vt_ILxListenerPort {
	ILxUnknown	 iunk;
	LXxMETHOD(  LxResult,
AddListener) (
	LXtObjectID		 self,
	LXtObjectID		 object);

	LXxMETHOD(  LxResult,
RemoveListener) (
	LXtObjectID		 self,
	LXtObjectID		 object);
} ILxListenerPort;


	#define LXu_LISTENERSERVICE	"1966420D-DFED-11D7-A237-000A9593D716"


	#define LXu_LISTENERPORT	"4FBF5E77-152D-4C4F-BFD4-3F6062CCF6BA"
	// [export] ILxListenerPort lport
	// [local]  ILxListenerPort

#endif