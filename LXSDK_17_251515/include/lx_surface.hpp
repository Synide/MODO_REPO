/*
 * Plug-in SDK Header: C++ User Classes
 *
 * Copyright 0000
 */
#ifndef LXUSER_surface_HPP
#define LXUSER_surface_HPP

#include <lxw_surface.hpp>


class CLxUser_SurfaceItem : public CLxLoc_SurfaceItem
{
	public:
	CLxUser_SurfaceItem () {}
	CLxUser_SurfaceItem (ILxUnknownID obj) : CLxLoc_SurfaceItem (obj) {}

	bool
	AllocSurf (
		ILxUnknownID		 chanRead,
		bool			 morph,
		CLxLoc_Surface		&surf)
	{
		LXtObjectID		 obj;
	
		if (LXx_FAIL (GetSurface (chanRead, morph ? 1 : 0, &obj)))
			return false;
	
		return surf.take (obj);
	}
	
		bool
	AllocSurf (
		ILxUnknownID		 attr,
		unsigned		 index,
		CLxLoc_Surface		&surf)
	{
		LXtObjectID		 obj;
	
		if (LXx_FAIL (Evaluate (attr, index, &obj)))
			return false;
	
		return surf.take (obj);
	}

};

class CLxUser_Surface : public CLxLoc_Surface
{
	public:
	CLxUser_Surface () {}
	CLxUser_Surface (ILxUnknownID obj) : CLxLoc_Surface (obj) {}

	bool
	GetBin (
		unsigned		 index,
		CLxLoc_SurfaceBin	&bin)
	{
		LXtObjectID		 obj;
	
		if (LXx_FAIL (BinByIndex (index, &obj)))
			return false;
	
		return bin.take (obj);
	}

};

class CLxUser_SurfaceBin : public CLxLoc_SurfaceBin
{
	public:
	CLxUser_SurfaceBin () {}
	CLxUser_SurfaceBin (ILxUnknownID obj) : CLxLoc_SurfaceBin (obj) {}



};

class CLxUser_CurveGroup : public CLxLoc_CurveGroup
{
	public:
	CLxUser_CurveGroup () {}
	CLxUser_CurveGroup (ILxUnknownID obj) : CLxLoc_CurveGroup (obj) {}



};

class CLxUser_Curve : public CLxLoc_Curve
{
	public:
	CLxUser_Curve () {}
	CLxUser_Curve (ILxUnknownID obj) : CLxLoc_Curve (obj) {}



};
#endif