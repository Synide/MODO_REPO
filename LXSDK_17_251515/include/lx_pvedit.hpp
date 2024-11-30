/*
 * Plug-in SDK Header: C++ User Classes
 *
 * Copyright 0000
 */
#ifndef LXUSER_pvedit_HPP
#define LXUSER_pvedit_HPP

#include <lxw_pvedit.hpp>


class CLxUser_PolygonSlice : public CLxLoc_PolygonSlice
{
	public:
	CLxUser_PolygonSlice () {}
	CLxUser_PolygonSlice (ILxUnknownID obj) : CLxLoc_PolygonSlice (obj) {}



};

class CLxUser_SolidDrill : public CLxLoc_SolidDrill
{
	public:
	CLxUser_SolidDrill () {}
	CLxUser_SolidDrill (ILxUnknownID obj) : CLxLoc_SolidDrill (obj) {}



};

class CLxUser_PolygonEdit : public CLxLoc_PolygonEdit
{
	public:
	CLxUser_PolygonEdit () {}
	CLxUser_PolygonEdit (ILxUnknownID obj) : CLxLoc_PolygonEdit (obj) {}



};
#endif