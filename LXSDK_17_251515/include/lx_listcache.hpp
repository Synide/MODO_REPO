/*
 * Plug-in SDK Header: C++ User Classes
 *
 * Copyright 0000
 */
#ifndef LXUSER_listcache_HPP
#define LXUSER_listcache_HPP

#include <lxw_listcache.hpp>


class CLxUser_ItemListType : public CLxLoc_ItemListType
{
	public:
	CLxUser_ItemListType () {}
	CLxUser_ItemListType (ILxUnknownID obj) : CLxLoc_ItemListType (obj) {}



};
#endif