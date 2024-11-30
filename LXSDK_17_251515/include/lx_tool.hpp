/*
 * Plug-in SDK Header: C++ User Classes
 *
 * Copyright 0000
 */
#ifndef LXUSER_tool_HPP
#define LXUSER_tool_HPP

#include <lxw_tool.hpp>


class CLxUser_AttrSequence : public CLxLoc_AttrSequence
{
	public:
	CLxUser_AttrSequence () {}
	CLxUser_AttrSequence (ILxUnknownID obj) : CLxLoc_AttrSequence (obj) {}



};

class CLxUser_ToolOperation : public CLxLoc_ToolOperation
{
	public:
	CLxUser_ToolOperation () {}
	CLxUser_ToolOperation (ILxUnknownID obj) : CLxLoc_ToolOperation (obj) {}



};

class CLxUser_FalloffPacket : public CLxLoc_FalloffPacket
{
	public:
	CLxUser_FalloffPacket () {}
	CLxUser_FalloffPacket (ILxUnknownID obj) : CLxLoc_FalloffPacket (obj) {}



};

class CLxUser_SymmetryPacket : public CLxLoc_SymmetryPacket
{
	public:
	CLxUser_SymmetryPacket () {}
	CLxUser_SymmetryPacket (ILxUnknownID obj) : CLxLoc_SymmetryPacket (obj) {}



};

class CLxUser_Subject2Packet : public CLxLoc_Subject2Packet
{
	public:
	CLxUser_Subject2Packet () {}
	CLxUser_Subject2Packet (ILxUnknownID obj) : CLxLoc_Subject2Packet (obj) {}

	bool
	BeginScan (
		unsigned int		 flags,
		CLxLocalizedObject	&scan)
	{
		LXtObjectID		 obj;
	
		if (LXx_FAIL (ScanAllocate (flags, &obj)))
			return false;
	
		return scan.take (obj);
	}

};

class CLxUser_TexturePacket : public CLxLoc_TexturePacket
{
	public:
	CLxUser_TexturePacket () {}
	CLxUser_TexturePacket (ILxUnknownID obj) : CLxLoc_TexturePacket (obj) {}



};

class CLxUser_ElementAxisPacket : public CLxLoc_ElementAxisPacket
{
	public:
	CLxUser_ElementAxisPacket () {}
	CLxUser_ElementAxisPacket (ILxUnknownID obj) : CLxLoc_ElementAxisPacket (obj) {}



};

class CLxUser_ElementCenterPacket : public CLxLoc_ElementCenterPacket
{
	public:
	CLxUser_ElementCenterPacket () {}
	CLxUser_ElementCenterPacket (ILxUnknownID obj) : CLxLoc_ElementCenterPacket (obj) {}



};

class CLxUser_BagGenerator : public CLxLoc_BagGenerator
{
	public:
	CLxUser_BagGenerator () {}
	CLxUser_BagGenerator (ILxUnknownID obj) : CLxLoc_BagGenerator (obj) {}



};

class CLxUser_PathStep : public CLxLoc_PathStep
{
	public:
	CLxUser_PathStep () {}
	CLxUser_PathStep (ILxUnknownID obj) : CLxLoc_PathStep (obj) {}



};

class CLxUser_PathGeneratorPacket : public CLxLoc_PathGeneratorPacket
{
	public:
	CLxUser_PathGeneratorPacket () {}
	CLxUser_PathGeneratorPacket (ILxUnknownID obj) : CLxLoc_PathGeneratorPacket (obj) {}



};

class CLxUser_ParticleGeneratorPacket : public CLxLoc_ParticleGeneratorPacket
{
	public:
	CLxUser_ParticleGeneratorPacket () {}
	CLxUser_ParticleGeneratorPacket (ILxUnknownID obj) : CLxLoc_ParticleGeneratorPacket (obj) {}



};
#endif