/*
 * Plug-in SDK Header: C++ User Classes
 *
 * Copyright 0000
 */
#ifndef LXUSER_drawover_HPP
#define LXUSER_drawover_HPP

#include <lxw_drawover.hpp>


class CLxUser_DrawingOverride : public CLxLoc_DrawingOverride
{
	public:
	CLxUser_DrawingOverride () {}
	CLxUser_DrawingOverride (ILxUnknownID obj) : CLxLoc_DrawingOverride (obj) {}



};
#endif