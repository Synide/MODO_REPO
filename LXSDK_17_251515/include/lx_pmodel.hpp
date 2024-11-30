/*
 * Plug-in SDK Header: C++ User Classes
 *
 * Copyright 0000
 */
#ifndef LXUSER_pmodel_HPP
#define LXUSER_pmodel_HPP

#include <lxw_pmodel.hpp>


class CLxUser_MeshElementGroup : public CLxLoc_MeshElementGroup
{
	public:
	CLxUser_MeshElementGroup () {}
	CLxUser_MeshElementGroup (ILxUnknownID obj) : CLxLoc_MeshElementGroup (obj) {}



};

class CLxUser_SelectionOperation : public CLxLoc_SelectionOperation
{
	public:
	CLxUser_SelectionOperation () {}
	CLxUser_SelectionOperation (ILxUnknownID obj) : CLxLoc_SelectionOperation (obj) {}



};

class CLxUser_SelectionState : public CLxLoc_SelectionState
{
	public:
	CLxUser_SelectionState () {}
	CLxUser_SelectionState (ILxUnknownID obj) : CLxLoc_SelectionState (obj) {}



};
#endif