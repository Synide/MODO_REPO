/*
 * Plug-in SDK Header: C++ User Classes
 *
 * Copyright 0000
 */
#ifndef LXUSER_tree_HPP
#define LXUSER_tree_HPP

#include <lxw_tree.hpp>


class CLxUser_Tree : public CLxLoc_Tree
{
	public:
	CLxUser_Tree () {}
	CLxUser_Tree (ILxUnknownID obj) : CLxLoc_Tree (obj) {}

	bool
	Clone (
		unsigned		 mode,
		CLxUser_Tree		&tree)
	{
		LXtObjectID		obj;
	
		return (LXx_OK (Spawn (mode, &obj)) && tree.take (obj));
	}

};

class CLxUser_TreeListener : public CLxLoc_TreeListener
{
	public:
	CLxUser_TreeListener () {}
	CLxUser_TreeListener (ILxUnknownID obj) : CLxLoc_TreeListener (obj) {}

	/**
	 * Empty TreeListener user classed.
	 */
	

};
#endif