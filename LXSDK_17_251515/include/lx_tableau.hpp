/*
 * Plug-in SDK Header: C++ User Classes
 *
 * Copyright 0000
 */
#ifndef LXUSER_tableau_HPP
#define LXUSER_tableau_HPP

#include <lxw_tableau.hpp>

	#include <lxw_vertex.hpp>
	#include <lxw_action.hpp>
	#include <lx_visitor.hpp>



class CLxUser_Tableau : public CLxLoc_Tableau
{
	public:
	CLxUser_Tableau () {}
	CLxUser_Tableau (ILxUnknownID obj) : CLxLoc_Tableau (obj) {}

	float
	Time0 (void)
	{
		float			 t0, dt;
	
		Time (&t0, &dt);
		return t0;
	}
	
		float
	Time1 (void)
	{
		float			 t0, dt;
	
		Time (&t0, &dt);
		return t0 + dt;
	}
	
		bool
	IsVisible (
		ILxUnknownID		 item)
	{
		return (Visible (item) == LXe_TRUE) ? true : false;
	}
	
		bool
	GetShader (
		CLxLoc_TableauShader	&shader,
		ILxUnknownID		 item,
		ILxUnknownID		 tags)
	{
		LXtObjectID		 obj;
	
		if (LXx_FAIL (FindShader (item, tags, &obj)))
			return false;
	
		return shader.take (obj);
	}
	
		bool
	GetChannels (
		CLxLoc_ChannelRead	&chan,
		unsigned		 type)
	{
		LXtObjectID		 obj;
	
		if (LXx_FAIL (Channels (type, &obj)))
			return false;
	
		return chan.take (obj);
	}
	
		LxResult
	VisitorUpdate (
		CLxImpl_AbstractVisitor		*visitor,
		int				 immediate)
	{
		CLxInst_OneVisitor<CLxGenericVisitor>  gv;
	
		gv.loc.vis = visitor;
	
		return Update (gv, immediate);
	}

};

class CLxUser_TableauElement : public CLxLoc_TableauElement
{
	public:
	CLxUser_TableauElement () {}
	CLxUser_TableauElement (ILxUnknownID obj) : CLxLoc_TableauElement (obj) {}



};

class CLxUser_TableauSurface : public CLxLoc_TableauSurface
{
	public:
	CLxUser_TableauSurface () {}
	CLxUser_TableauSurface (ILxUnknownID obj) : CLxLoc_TableauSurface (obj) {}



};

class CLxUser_TriangleSoup : public CLxLoc_TriangleSoup
{
	public:
	CLxUser_TriangleSoup () {}
	CLxUser_TriangleSoup (ILxUnknownID obj) : CLxLoc_TriangleSoup (obj) {}

	/**
	 * The user method allows quads to be created with connectivity.
	 */
		LxResult
	Quad (
		unsigned int		 v0,
		unsigned int		 v1,
		unsigned int		 v2,
		unsigned int		 v3)
	{
		LxResult		 rc;
	
		rc = Polygon (v0, v1, v2);
		if (LXx_FAIL (rc))
			return rc;
	
		Connect (LXiTBLX_CONNECT_QUAD);
		return Polygon (v0, v2, v3);
	}

};

class CLxUser_TableauInstance : public CLxLoc_TableauInstance
{
	public:
	CLxUser_TableauInstance () {}
	CLxUser_TableauInstance (ILxUnknownID obj) : CLxLoc_TableauInstance (obj) {}



};

class CLxUser_TableauShader : public CLxLoc_TableauShader
{
	public:
	CLxUser_TableauShader () {}
	CLxUser_TableauShader (ILxUnknownID obj) : CLxLoc_TableauShader (obj) {}

	bool
	GetSlice (
		CLxLoc_ShaderSlice	&slice,
		ILxUnknownID		 vtOutput,
		ILxUnknownID		 tvDesc)
	{
		LXtObjectID		 obj;
	
		if (LXx_FAIL (Slice (vtOutput, tvDesc, &obj)))
			return false;
	
		return slice.take (obj);
	}

};

class CLxUser_TableauService : public CLxLoc_TableauService
{
	public:
	bool
	NewVertex (
		CLxLoc_TableauVertex	&vert)
	{
		LXtObjectID		 obj;
	
		vert.clear ();
		if (LXx_FAIL (AllocVertex (&obj)))
			return false;
	
		return vert.take (obj);
	}

};

class CLxUser_NodalService : public CLxLoc_NodalService
{
	public:


};
#endif