/*
 * Plug-in SDK Header: C++ User Classes
 *
 * Copyright 0000
 */
#ifndef LXUSER_trisurf_HPP
#define LXUSER_trisurf_HPP

#include <lxw_trisurf.hpp>


class CLxUser_TriangleSurface : public CLxLoc_TriangleSurface
{
	public:
	CLxUser_TriangleSurface () {}
	CLxUser_TriangleSurface (ILxUnknownID obj) : CLxLoc_TriangleSurface (obj) {}



};

class CLxUser_TriangleGroup : public CLxLoc_TriangleGroup
{
	public:
	CLxUser_TriangleGroup () {}
	CLxUser_TriangleGroup (ILxUnknownID obj) : CLxLoc_TriangleGroup (obj) {}

	bool
	NewSurf (
		CLxLoc_TriangleSurface	&surf)
	{
		LXtObjectID		 obj;
	
		surf.clear ();
		if (LXx_FAIL (AddSurface (&obj)))
			return false;
	
		return surf.take (obj);
	}
	
		bool
	GetSurf (
		unsigned		 index,
		CLxLoc_TriangleSurface	&surf)
	{
		LXtObjectID		 obj;
	
		surf.clear ();
		if (LXx_FAIL (GetSurface (index, &obj)))
			return false;
	
		return surf.take (obj);
	}

};
#endif