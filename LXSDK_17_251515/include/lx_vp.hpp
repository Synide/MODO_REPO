/*
 * Plug-in SDK Header: C++ User Classes
 *
 * Copyright 0000
 */
#ifndef LXUSER_vp_HPP
#define LXUSER_vp_HPP

#include <lxw_vp.hpp>


class CLxUser_View3D : public CLxLoc_View3D
{
	public:
	CLxUser_View3D () {}
	CLxUser_View3D (ILxUnknownID obj) : CLxLoc_View3D (obj) {}



};

class CLxUser_SimulationListener : public CLxLoc_SimulationListener
{
	public:
	CLxUser_SimulationListener () {}
	CLxUser_SimulationListener (ILxUnknownID obj) : CLxLoc_SimulationListener (obj) {}



};

class CLxUser_View3DportService : public CLxLoc_View3DportService
{
	public:
	/**
	 * Empty view3Dport service user classes.
	 */
	

};
#endif