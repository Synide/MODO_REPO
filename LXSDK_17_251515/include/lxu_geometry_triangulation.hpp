/*
* Plug-in SDK Header: Geometry Utilities
*
* Copyright 0000
*
* Provides geometry utility functions for C++ plug-ins.
*/

#ifndef LXU_GEOMETRY_TRIANGULATION_HPP
#define LXU_GEOMETRY_TRIANGULATION_HPP

#include <vector>

#include <lxvmath.h>
#include <lx_mesh.hpp>

namespace lx
{
	struct GeoTriangle {
		unsigned v0, v1, v2;
	};

		std::vector<GeoTriangle>
	TriangulateFace (	CLxUser_Polygon&	poly,
				CLxUser_Point&		point);

};	// END lx namespace

#endif // LXU_GEOMETRY_TRIANGULATION_HPP
