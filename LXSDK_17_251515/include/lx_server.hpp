/*
 * Plug-in SDK Header: C++ User Classes
 *
 * Copyright 0000
 */
#ifndef LXUSER_server_HPP
#define LXUSER_server_HPP

#include <lxw_server.hpp>


class CLxUser_Factory : public CLxLoc_Factory
{
	public:
	CLxUser_Factory () {}
	CLxUser_Factory (ILxUnknownID obj) : CLxLoc_Factory (obj) {}

	bool
	New (
		CLxLocalizedObject	&loc)
	{
		return Spawn (loc);
	}

};

class CLxUser_HostService : public CLxLoc_HostService
{
	public:
	/**
	 * The C++ service has methods to get a factory directly into a user object.
	 */
		bool
	Lookup (
		CLxLoc_Factory		&fac,
		const char		*className,
		const char		*name,
		bool			 allowLoad = true)
	{
		LXtObjectID		 obj;
	
		if (LXx_FAIL (LookupServer (className, name, allowLoad, &obj)))
			return false;
	
		return fac.take (obj);
	}
	
		bool
	ByIndex (
		CLxLoc_Factory		&fac,
		const char		*className,
		unsigned int		 index)
	{
		LXtObjectID		 obj;
	
		if (LXx_FAIL (ServerByIndex (className, index, &obj)))
			return false;
	
		return fac.take (obj);
	}

};
#endif