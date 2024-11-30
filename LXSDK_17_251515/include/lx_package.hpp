/*
 * Plug-in SDK Header: C++ User Classes
 *
 * Copyright 0000
 */
#ifndef LXUSER_package_HPP
#define LXUSER_package_HPP

#include <lxw_package.hpp>


class CLxUser_SceneLoaderTarget : public CLxLoc_SceneLoaderTarget
{
	public:
	CLxUser_SceneLoaderTarget () {}
	CLxUser_SceneLoaderTarget (ILxUnknownID obj) : CLxLoc_SceneLoaderTarget (obj) {}



};

class CLxUser_AddChannel : public CLxLoc_AddChannel
{
	public:
	CLxUser_AddChannel () {}
	CLxUser_AddChannel (ILxUnknownID obj) : CLxLoc_AddChannel (obj) {}



};

class CLxUser_ItemCollection : public CLxLoc_ItemCollection
{
	public:
	CLxUser_ItemCollection () {}
	CLxUser_ItemCollection (ILxUnknownID obj) : CLxLoc_ItemCollection (obj) {}



};
#endif