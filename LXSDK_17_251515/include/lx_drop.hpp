/*
 * Plug-in SDK Header: C++ User Classes
 *
 * Copyright 0000
 */
#ifndef LXUSER_drop_HPP
#define LXUSER_drop_HPP

#include <lxw_drop.hpp>


class CLxUser_Drop : public CLxLoc_Drop
{
	public:
	CLxUser_Drop () {}
	CLxUser_Drop (ILxUnknownID obj) : CLxLoc_Drop (obj) {}

	/**
	 * Empty Drop Python user class.
	 */
	

};

class CLxUser_AddDropAction : public CLxLoc_AddDropAction
{
	public:
	CLxUser_AddDropAction () {}
	CLxUser_AddDropAction (ILxUnknownID obj) : CLxLoc_AddDropAction (obj) {}

	/**
	 * Empty AddDropAction Python user class.
	 */
	

};

class CLxUser_DropPreviewDefault : public CLxLoc_DropPreviewDefault
{
	public:
	CLxUser_DropPreviewDefault () {}
	CLxUser_DropPreviewDefault (ILxUnknownID obj) : CLxLoc_DropPreviewDefault (obj) {}

	/**
	 * Empty DropPreviewDefault Python user class.
	 */
	

};

class CLxUser_DropService : public CLxLoc_DropService
{
	public:
	/**
	 * Empty Drop service user classes.
	 */
	

};
#endif