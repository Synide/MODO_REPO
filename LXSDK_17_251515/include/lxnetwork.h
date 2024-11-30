/*
 * LX network module
 *
 * Copyright 0000
 */
#ifndef LX_network_H
#define LX_network_H

typedef struct vt_ILxNetworkService ** ILxNetworkServiceID;

	#include <lxcom.h>
	#include <lxserver.h>

/*
 * IPv4 addresses are defined as 32 bit unsigned integers, with each byte
 * representing a component of the address.
 */

	typedef unsigned int		 LXtIP4;

/*
 * nexus supports two ways to find nodes for network rendering: Bonjour, which finds
 * node automatically, and host lists, which uses a static list of IPs or host names.
 * It is also possible to attempt a one-off connect to another host.  As with all
 * hosts, if the connection is successful it will remain connected until either the
 * machine quits.  Since the connection is async, there is no feedback as to the
 * success or failure if this.
 * There is a single method to make the connection, OneOffHostListAdd(). This looks
 * up the host by hostname, or if that is NULL, by IP.  The port is the used to connect
 * to the remote host.  Normally this LXiNETWORK_NETRENDER_PORT, the default port, 
 * since that's the one tha other instances of modo will be listening on, but there
 * are cases where an alternate port is useful.  For example, when for rendering on
 * virtual machines where multiple isntances of the VM are running on hte same machine,
 * each will expose a different port to the host machine that is mapped to the standard
 * port inside the VM.
 * 
 */

	#define LXiNETWORK_NETRENDER_PORT	59267



/*
 * As with all globals, the first method gets the ILxScriptQueryID interface for
 * the system.  However, it is not implemented for ILxNetworkService.
 * 
 * 
 * It is also possible to remove a one-off connection.  This is really just a clean-up
 * phase; it doesn't disconnect from the host.  It's usually useful to remove it when
 * you want to try to reconnect to it as calling OneOffHostListAdd() on an already
 * connected host will have no effet.
 */
typedef struct vt_ILxNetworkService {
	ILxUnknown	 iunk;
	LXxMETHOD(  LxResult,
ScriptQuery) (
	LXtObjectID		 self,
	void		       **ppvObj);
	LXxMETHOD( LxResult,
OneOffHostListAdd) (
	LXtObjectID		  self,
	const char		 *hostname,
	LXtIP4			  ip,
	int			  port);
	LXxMETHOD( LxResult,
OneOffHostListRemove) (
	LXtObjectID		  self,
	const char		 *hostname,
	LXtIP4			  ip,
	int			  port);
} ILxNetworkService;

/*
 * Network service provides access to the networking features of nexus.  Currently
 * on very limited functionality is exposed, but more may be added in the future.
 */

	#define LXu_NETWORKSERVICE	"333d439d-cfc8-43e6-ad3c-1e2b6fda27fb"
	#define LXa_NETWORKSERVICE	"networkservice"
	// [local]  ILxNetworkService

#endif