/*
 * Plug-in SDK Header: C++ User Classes
 *
 * Copyright 0000
 */
#ifndef LXUSER_draw_HPP
#define LXUSER_draw_HPP

#include <lxw_draw.hpp>


class CLxUser_View : public CLxLoc_View
{
	public:
	CLxUser_View () {}
	CLxUser_View (ILxUnknownID obj) : CLxLoc_View (obj) {}



};

class CLxUser_StrokeDraw : public CLxLoc_StrokeDraw
{
	public:
	CLxUser_StrokeDraw () {}
	CLxUser_StrokeDraw (ILxUnknownID obj) : CLxLoc_StrokeDraw (obj) {}

	void
	Vert (
		LXtVector		 pos,
		int			 flags = LXiSTROKE_ABSOLUTE)
	{
		Vertex (pos, flags);
	}
	
		void
	Vert (
		LXtFVector		 pos,
		int			 flags = LXiSTROKE_ABSOLUTE)
	{
		Vertex3 (pos[0], pos[1], pos[2], flags);
	}
	
		void
	Vert (
		double			 x,
		double			 y,
		double			 z,
		int			 flags = LXiSTROKE_ABSOLUTE)
	{
		Vertex3 (x, y, z, flags);
	}
	
		void
	Vert (
		float			 x,
		float			 y,
		float			 z,
		int			 flags = LXiSTROKE_ABSOLUTE)
	{
		Vertex3 (x, y, z, flags);
	}
	
		void
	Vert (
		double			 x,
		double			 y,
		int			 flags = LXiSTROKE_SCREEN)
	{
		Vertex3 (x, y, 0.0, flags);
	}
	
		void
	Vert (
		float			 x,
		float			 y,
		int			 flags = LXiSTROKE_SCREEN)
	{
		Vertex3 (x, y, 0.0, flags);
	}

};

class CLxUser_GLMaterial : public CLxLoc_GLMaterial
{
	public:
	CLxUser_GLMaterial () {}
	CLxUser_GLMaterial (ILxUnknownID obj) : CLxLoc_GLMaterial (obj) {}



};

class CLxUser_GLImage : public CLxLoc_GLImage
{
	public:
	CLxUser_GLImage () {}
	CLxUser_GLImage (ILxUnknownID obj) : CLxLoc_GLImage (obj) {}



};
#endif