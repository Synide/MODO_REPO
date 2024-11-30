/*
 * Plug-in SDK Header: C++ User Classes
 *
 * Copyright 0000
 */
#ifndef LXUSER_pretype_HPP
#define LXUSER_pretype_HPP

#include <lxw_pretype.hpp>


class CLxUser_PresetLoaderTarget : public CLxLoc_PresetLoaderTarget
{
	public:
	CLxUser_PresetLoaderTarget () {}
	CLxUser_PresetLoaderTarget (ILxUnknownID obj) : CLxLoc_PresetLoaderTarget (obj) {}



};

class CLxUser_PresetType : public CLxLoc_PresetType
{
	public:
	CLxUser_PresetType () {}
	CLxUser_PresetType (ILxUnknownID obj) : CLxLoc_PresetType (obj) {}



};

class CLxUser_PresetType1 : public CLxLoc_PresetType1
{
	public:
	CLxUser_PresetType1 () {}
	CLxUser_PresetType1 (ILxUnknownID obj) : CLxLoc_PresetType1 (obj) {}



};

class CLxUser_PresetBrowserService : public CLxLoc_PresetBrowserService
{
	public:
	bool
	GetServer (
		CLxUser_PresetType	&srv,
		const char		*name)
	{
		LXtObjectID		 obj;
	
		srv.clear ();
		if (LXx_FAIL (ServerLookup (name, &obj)))
			return false;
	
		return srv.take (obj);
	}

};
#endif