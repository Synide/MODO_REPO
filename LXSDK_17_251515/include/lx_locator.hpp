/*
 * Plug-in SDK Header: C++ User Classes
 *
 * Copyright 0000
 */
#ifndef LXUSER_locator_HPP
#define LXUSER_locator_HPP

#include <lxw_locator.hpp>

	#include <lxw_item.hpp>



class CLxUser_Locator : public CLxLoc_Locator
{
	public:
	CLxUser_Locator () {}
	CLxUser_Locator (ILxUnknownID obj) : CLxLoc_Locator (obj) {}

	bool
	GetXfrmItem (
		LXtTransformType	 type,
		CLxLoc_Item		&item)
	{
		LXtObjectID		 obj;
	
		if (LXx_OK (GetTransformItem (type, &obj)))
			return item.take (obj);
	
		item.clear ();
		return false;
	}
	bool
	AddXfrmItem (
		LXtTransformType	 type,
		CLxLoc_Item		&item,
		unsigned		*index = 0)
	{
		LXtObjectID		 obj;
	
		if (LXx_OK (AddTransformItem (type, &obj, index)))
			return item.take (obj);
	
		item.clear ();
		return false;
	}
	bool
	AddPreXfrmItem (
		ILxUnknownID		 chanWrite,
		LXtTransformType	 type,
		const LXtVector		 value,
		CLxLoc_Item		&item,
		unsigned		*index = 0)
	{
		LXtObjectID		 obj;
	
		if (LXx_OK (AddPreTransformItem (chanWrite, type, value, &obj, index)))
			return item.take (obj);
	
		item.clear ();
		return false;
	}
	bool
	AddPostXfrmItem (
		ILxUnknownID		 chanWrite,
		LXtTransformType	 type,
		const LXtVector		 value,
		CLxLoc_Item		&item,
		unsigned		*index = 0)
	{
		LXtObjectID		 obj;
	
		if (LXx_OK (AddPostTransformItem (chanWrite, type, value, &obj, index)))
			return item.take (obj);
	
		item.clear ();
		return false;
	}

};
#endif