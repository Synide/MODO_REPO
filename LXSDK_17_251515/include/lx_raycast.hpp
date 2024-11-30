/*
 * Plug-in SDK Header: C++ User Classes
 *
 * Copyright 0000
 */
#ifndef LXUSER_raycast_HPP
#define LXUSER_raycast_HPP

#include <lxw_raycast.hpp>


class CLxUser_Lighting : public CLxLoc_Lighting
{
	public:
	CLxUser_Lighting () {}
	CLxUser_Lighting (ILxUnknownID obj) : CLxLoc_Lighting (obj) {}



};
#endif