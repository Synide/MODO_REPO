/*
 * Plug-in SDK Header: C++ User Classes
 *
 * Copyright 0000
 */
#ifndef LXUSER_renderslot_HPP
#define LXUSER_renderslot_HPP

#include <lxw_renderslot.hpp>


class CLxUser_RenderSlot : public CLxLoc_RenderSlot
{
	public:
	CLxUser_RenderSlot () {}
	CLxUser_RenderSlot (ILxUnknownID obj) : CLxLoc_RenderSlot (obj) {}



};

class CLxUser_RenderSlotPass : public CLxLoc_RenderSlotPass
{
	public:
	CLxUser_RenderSlotPass () {}
	CLxUser_RenderSlotPass (ILxUnknownID obj) : CLxLoc_RenderSlotPass (obj) {}



};

class CLxUser_RenderSlotOutput : public CLxLoc_RenderSlotOutput
{
	public:
	CLxUser_RenderSlotOutput () {}
	CLxUser_RenderSlotOutput (ILxUnknownID obj) : CLxLoc_RenderSlotOutput (obj) {}



};
#endif