/*
 * Plug-in SDK Header: Geometry Utilities
 *
 * Copyright 0000
 *
 * Provides geometry utility functions for C++ plug-ins.
 */

#ifndef LXU_GEOMETRY_HPP
#define LXU_GEOMETRY_HPP

#include <lxvmath.h>
#include <vector>

	namespace lx
	{

/*
 * Points for standard template containers.
 */
struct GeoPoint
{
	LXtVector vec;
};

struct GeoUV
{
	LXtFVector2 uv;
};

/*
 * Generate vertex normals for a triangle list,
 * with normal smoothing for shared vertices.
 */
	void
GenerateNormals (
	std::vector<GeoPoint>	&points,
	std::vector<unsigned>	&triangles,
	std::vector<GeoPoint>	&normals);

/*
 * Generate vertex normals for a convex polygon list,
 * with normal smoothing for shared vertices.
 */
	void
GeneratePolyNormals (
	std::vector<GeoPoint>	&points,
	std::vector<unsigned>	&polyInds,
	std::vector<unsigned>	&polyCounts,
	std::vector<GeoPoint>	&normals);

/*
 * Generate vertex dPdu/dPdv values, with smoothing for shared vertices.
 */
	void
GenerateDPDUs (
	std::vector<GeoPoint>	&points,
	std::vector<GeoUV>	&uvs,
	std::vector<unsigned>	&triangles,
	std::vector<GeoPoint>	&dPdus,
	std::vector<GeoPoint>	&dPdvs);

	void
GeneratePolyDPDUs (
	std::vector<GeoPoint>	&points,
	std::vector<GeoUV>		&uvs,
	bool					uvsFacevarying,
	std::vector<unsigned>	&polyInds,
	std::vector<unsigned>	&polyCounts,
	std::vector<GeoPoint>	&dPdus,
	std::vector<GeoPoint>	&dPdvs);

	};	// END lx namespace

#endif // LXU_GEOMETRY_HPP
