/*
 * Plug-in SDK Header: Plug-in Header
 *
 * Copyright 0000
 *
 * This defines the global thisModule, and all the other code needed to make
 * a plug-in module.
 */
#ifndef LX_PLUGIN_HPP
#define LX_PLUGIN_HPP

#include <lx_wrap.hpp>


/*
 * ----------------------------------------------------------
 * The Global Module
 *
 * The Module itself is defined as a single static object which is
 * both a module and its own polymorph.  Clients should really only
 * call the AddServer() function to add new polymorphs for output.
 */
class CLxThisModule :
		public CLxImpl_Module,
		public CLxImpl_TagDescription,
		public CLxImpl_NeedContext,
		public CLxGenericPolymorph,
		public CLxGlobalCache
{
	CLxGenericPolymorph	**iPoly;
	const char		**iName;
	const LXtGUID		**iGUID;
	unsigned		 numSrv;
	unsigned		 bufferSize;

    public:
	unsigned		 lifecycle;

				  CLxThisModule ();
				 ~CLxThisModule ();

	void *			 NewObj  ()						override;
	void			 FreeObj (void *self)					override;

	unsigned		 tag_Count ()						override;
	LxResult		 tag_Describe (unsigned, LXtTagInfoDesc *)		override;
	LxResult		 need_SetContext (ILxUnknownID)				override;
	LxResult		 mod_Generate (const char *, const LXtGUID *, void **)	override;

	void			 AddServer  (const char *, CLxGenericPolymorph *);
	CLxGenericPolymorph *	 FindServer (const char *);

}; // END CLxThisModule


/*
 * The module for the plug-in is globally accessible, although the generic
 * accessor functions should normally be sufficient.
 */
extern class CLxThisModule	 thisModule;


/*
 * The "initialize()" function is defined by the plug-in client, and is the
 * right time to call AddServer() to define the servers for this plug-in
 * module. The "cleanup()" function is optional, and allows the plug-in client
 * to do any last-minute cleanup before quit.
 */
extern void			 initialize (void);
extern void			 cleanup (void);


#endif
