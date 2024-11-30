/*
 * Plug-in SDK Header: C++ User Classes
 *
 * Copyright 0000
 */
#ifndef LXUSER_chanmod_HPP
#define LXUSER_chanmod_HPP

#include <lxw_chanmod.hpp>

	#include <lx_item.hpp>



class CLxUser_ChannelModSetup : public CLxLoc_ChannelModSetup
{
	public:
	CLxUser_ChannelModSetup () {}
	CLxUser_ChannelModSetup (ILxUnknownID obj) : CLxLoc_ChannelModSetup (obj) {}



};
#endif