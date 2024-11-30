/*
 * Plug-in SDK Header: C++ User Classes
 *
 * Copyright 0000
 */
#ifndef LXUSER_shade_HPP
#define LXUSER_shade_HPP

#include <lxw_shade.hpp>

	#include <lx_value.hpp>



class CLxUser_ValueTextureCustom : public CLxLoc_ValueTextureCustom
{
	public:
	CLxUser_ValueTextureCustom () {}
	CLxUser_ValueTextureCustom (ILxUnknownID obj) : CLxLoc_ValueTextureCustom (obj) {}



};

class CLxUser_Texture : public CLxLoc_Texture
{
	public:
	CLxUser_Texture () {}
	CLxUser_Texture (ILxUnknownID obj) : CLxLoc_Texture (obj) {}



};
#endif