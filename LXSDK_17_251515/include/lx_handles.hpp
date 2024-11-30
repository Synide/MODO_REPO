/*
 * Plug-in SDK Header: C++ User Classes
 *
 * Copyright 0000
 */
#ifndef LXUSER_handles_HPP
#define LXUSER_handles_HPP

#include <lxw_handles.hpp>


class CLxUser_ShapeDraw : public CLxLoc_ShapeDraw
{
	public:
	CLxUser_ShapeDraw () {}
	CLxUser_ShapeDraw (ILxUnknownID obj) : CLxLoc_ShapeDraw (obj) {}



};

class CLxUser_HandleDraw : public CLxLoc_HandleDraw
{
	public:
	CLxUser_HandleDraw () {}
	CLxUser_HandleDraw (ILxUnknownID obj) : CLxLoc_HandleDraw (obj) {}



};

class CLxUser_EventTranslatePacket : public CLxLoc_EventTranslatePacket
{
	public:
	CLxUser_EventTranslatePacket () {}
	CLxUser_EventTranslatePacket (ILxUnknownID obj) : CLxLoc_EventTranslatePacket (obj) {}



};

class CLxUser_EventGuide : public CLxLoc_EventGuide
{
	public:
	CLxUser_EventGuide () {}
	CLxUser_EventGuide (ILxUnknownID obj) : CLxLoc_EventGuide (obj) {}



};
#endif