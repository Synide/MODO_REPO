/*
 * Plug-in SDK Header: C++ User Classes
 *
 * Copyright 0000
 */
#ifndef LXUSER_predest_HPP
#define LXUSER_predest_HPP

#include <lxw_predest.hpp>


class CLxUser_ShaderPreDest : public CLxLoc_ShaderPreDest
{
	public:
	CLxUser_ShaderPreDest () {}
	CLxUser_ShaderPreDest (ILxUnknownID obj) : CLxLoc_ShaderPreDest (obj) {}



};

class CLxUser_MeshLayerPreDest : public CLxLoc_MeshLayerPreDest
{
	public:
	CLxUser_MeshLayerPreDest () {}
	CLxUser_MeshLayerPreDest (ILxUnknownID obj) : CLxLoc_MeshLayerPreDest (obj) {}



};

class CLxUser_SceneItemPreDest : public CLxLoc_SceneItemPreDest
{
	public:
	CLxUser_SceneItemPreDest () {}
	CLxUser_SceneItemPreDest (ILxUnknownID obj) : CLxLoc_SceneItemPreDest (obj) {}



};

class CLxUser_Profile1DPreDest : public CLxLoc_Profile1DPreDest
{
	public:
	CLxUser_Profile1DPreDest () {}
	CLxUser_Profile1DPreDest (ILxUnknownID obj) : CLxLoc_Profile1DPreDest (obj) {}



};

class CLxUser_Profile2DPreDest : public CLxLoc_Profile2DPreDest
{
	public:
	CLxUser_Profile2DPreDest () {}
	CLxUser_Profile2DPreDest (ILxUnknownID obj) : CLxLoc_Profile2DPreDest (obj) {}



};

class CLxUser_ColorPreDest : public CLxLoc_ColorPreDest
{
	public:
	CLxUser_ColorPreDest () {}
	CLxUser_ColorPreDest (ILxUnknownID obj) : CLxLoc_ColorPreDest (obj) {}



};

class CLxUser_PresetDestinationService : public CLxLoc_PresetDestinationService
{
	public:


};
#endif