/*
 * Plug-in SDK Header: C++ User Classes
 *
 * Copyright 0000
 */
#ifndef LXUSER_vmodel_HPP
#define LXUSER_vmodel_HPP

#include <lxw_vmodel.hpp>


class CLxUser_VirtualModel : public CLxLoc_VirtualModel
{
	public:
	CLxUser_VirtualModel () {}
	CLxUser_VirtualModel (ILxUnknownID obj) : CLxLoc_VirtualModel (obj) {}



};

class CLxUser_AdjustTool : public CLxLoc_AdjustTool
{
	public:
	CLxUser_AdjustTool () {}
	CLxUser_AdjustTool (ILxUnknownID obj) : CLxLoc_AdjustTool (obj) {}



};
#endif