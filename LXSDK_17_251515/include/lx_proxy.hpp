/*
 * Plug-in SDK Header: C++ User Classes
 *
 * Copyright 0000
 */
#ifndef LXUSER_proxy_HPP
#define LXUSER_proxy_HPP

#include <lxw_proxy.hpp>


class CLxUser_SceneContents : public CLxLoc_SceneContents
{
	public:
	CLxUser_SceneContents () {}
	CLxUser_SceneContents (ILxUnknownID obj) : CLxLoc_SceneContents (obj) {}



};

class CLxUser_ProxyOptions : public CLxLoc_ProxyOptions
{
	public:
	CLxUser_ProxyOptions () {}
	CLxUser_ProxyOptions (ILxUnknownID obj) : CLxLoc_ProxyOptions (obj) {}

	/**
	 * - ALLOW_NONSURF
	 * The loader allow none surface items to load into the cinema if this is set.
	 * Otherwise, it skips loading them.
	 */
	

};
#endif