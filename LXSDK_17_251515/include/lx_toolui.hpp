/*
 * Plug-in SDK Header: C++ User Classes
 *
 * Copyright 0000
 */
#ifndef LXUSER_toolui_HPP
#define LXUSER_toolui_HPP

#include <lxw_toolui.hpp>
/*
 * NOTE; lxpredest not strictly needed here, but some of the packets are not useful
 * unless it's included. So this gets it into the SDK even though we have no samples.
 */

	#include <lx_predest.hpp>



class CLxUser_RaycastPacket : public CLxLoc_RaycastPacket
{
	public:
	CLxUser_RaycastPacket () {}
	CLxUser_RaycastPacket (ILxUnknownID obj) : CLxLoc_RaycastPacket (obj) {}



};

class CLxUser_PaintBrushPacket : public CLxLoc_PaintBrushPacket
{
	public:
	CLxUser_PaintBrushPacket () {}
	CLxUser_PaintBrushPacket (ILxUnknownID obj) : CLxLoc_PaintBrushPacket (obj) {}



};

class CLxUser_PaintInkPacket : public CLxLoc_PaintInkPacket
{
	public:
	CLxUser_PaintInkPacket () {}
	CLxUser_PaintInkPacket (ILxUnknownID obj) : CLxLoc_PaintInkPacket (obj) {}



};

class CLxUser_PaintNozzlePacket : public CLxLoc_PaintNozzlePacket
{
	public:
	CLxUser_PaintNozzlePacket () {}
	CLxUser_PaintNozzlePacket (ILxUnknownID obj) : CLxLoc_PaintNozzlePacket (obj) {}



};
#endif