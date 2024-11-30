/*
 * Plug-in SDK Header: C++ User Classes
 *
 * Copyright 0000
 */
#ifndef LXUSER_anim_HPP
#define LXUSER_anim_HPP

#include <lxw_anim.hpp>


class CLxUser_AnimListener : public CLxLoc_AnimListener
{
	public:
	CLxUser_AnimListener () {}
	CLxUser_AnimListener (ILxUnknownID obj) : CLxLoc_AnimListener (obj) {}

	/**
	 * Empty user classes.
	 */
	

};
#endif