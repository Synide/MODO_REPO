/*
 * Plug-in SDK Header: C++ User Classes
 *
 * Copyright 0000
 */
#ifndef LXUSER_vectortools_HPP
#define LXUSER_vectortools_HPP

#include <lxw_vectortools.hpp>


class CLxUser_VectorCanvas : public CLxLoc_VectorCanvas
{
	public:
	CLxUser_VectorCanvas () {}
	CLxUser_VectorCanvas (ILxUnknownID obj) : CLxLoc_VectorCanvas (obj) {}



};

class CLxUser_VectorShape : public CLxLoc_VectorShape
{
	public:
	CLxUser_VectorShape () {}
	CLxUser_VectorShape (ILxUnknownID obj) : CLxLoc_VectorShape (obj) {}



};

class CLxUser_VectorPath : public CLxLoc_VectorPath
{
	public:
	CLxUser_VectorPath () {}
	CLxUser_VectorPath (ILxUnknownID obj) : CLxLoc_VectorPath (obj) {}



};

class CLxUser_VectorListener : public CLxLoc_VectorListener
{
	public:
	CLxUser_VectorListener () {}
	CLxUser_VectorListener (ILxUnknownID obj) : CLxLoc_VectorListener (obj) {}



};
#endif