/*
 * Plug-in SDK Header: C++ User Classes
 *
 * Copyright 0000
 */
#ifndef LXUSER_itemui_HPP
#define LXUSER_itemui_HPP

#include <lxw_itemui.hpp>


class CLxUser_LocatorDest : public CLxLoc_LocatorDest
{
	public:
	CLxUser_LocatorDest () {}
	CLxUser_LocatorDest (ILxUnknownID obj) : CLxLoc_LocatorDest (obj) {}



};

class CLxUser_MeshOpDest : public CLxLoc_MeshOpDest
{
	public:
	CLxUser_MeshOpDest () {}
	CLxUser_MeshOpDest (ILxUnknownID obj) : CLxLoc_MeshOpDest (obj) {}



};

class CLxUser_MeshDest : public CLxLoc_MeshDest
{
	public:
	CLxUser_MeshDest () {}
	CLxUser_MeshDest (ILxUnknownID obj) : CLxLoc_MeshDest (obj) {}



};

class CLxUser_ChannelDest : public CLxLoc_ChannelDest
{
	public:
	CLxUser_ChannelDest () {}
	CLxUser_ChannelDest (ILxUnknownID obj) : CLxLoc_ChannelDest (obj) {}



};

class CLxUser_ChannelDropPreview : public CLxLoc_ChannelDropPreview
{
	public:
	CLxUser_ChannelDropPreview () {}
	CLxUser_ChannelDropPreview (ILxUnknownID obj) : CLxLoc_ChannelDropPreview (obj) {}

	/**
	 * Empty ILxChannelDropPreview Python user class.
	 */
	

};

class CLxUser_ItemTypeDest : public CLxLoc_ItemTypeDest
{
	public:
	CLxUser_ItemTypeDest () {}
	CLxUser_ItemTypeDest (ILxUnknownID obj) : CLxLoc_ItemTypeDest (obj) {}



};
#endif