/*
 * Plug-in SDK Header: C++ User Classes
 *
 * Copyright 0000
 */
#ifndef LXUSER_viewobject_HPP
#define LXUSER_viewobject_HPP

#include <lxw_viewobject.hpp>


class CLxUser_ViewObject : public CLxLoc_ViewObject
{
	public:
	CLxUser_ViewObject () {}
	CLxUser_ViewObject (ILxUnknownID obj) : CLxLoc_ViewObject (obj) {}



};
#endif