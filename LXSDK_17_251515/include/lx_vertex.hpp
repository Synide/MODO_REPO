/*
 * Plug-in SDK Header: C++ User Classes
 *
 * Copyright 0000
 */
#ifndef LXUSER_vertex_HPP
#define LXUSER_vertex_HPP

#include <lxw_vertex.hpp>


class CLxUser_TableauVertex : public CLxLoc_TableauVertex
{
	public:
	CLxUser_TableauVertex () {}
	CLxUser_TableauVertex (ILxUnknownID obj) : CLxLoc_TableauVertex (obj) {}

	int
	NewFeature (
		LXtID4			 type,
		const char		*name)
	{
		unsigned		 index;
		LxResult		 rc;
	
		rc = AddFeature (type, name, &index);
		if (LXx_OK (rc))
			return index;
		else
			return -1;
	}
	int
	GetOffset (
		LXtID4			 type,
		const char		*name)
	{
		unsigned		 offset;
		LxResult		 rc;
	
		rc = Lookup (type, name, &offset);
		if (LXx_OK (rc))
			return offset;
		else
			return -1;
	}

};

class CLxUser_VertexFeatureService : public CLxLoc_VertexFeatureService
{
	public:


};
#endif