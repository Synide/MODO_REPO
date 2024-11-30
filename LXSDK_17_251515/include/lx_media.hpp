/*
 * Plug-in SDK Header: C++ User Classes
 *
 * Copyright 0000
 */
#ifndef LXUSER_media_HPP
#define LXUSER_media_HPP

#include <lxw_media.hpp>


class CLxUser_AudioLoaderTarget : public CLxLoc_AudioLoaderTarget
{
	public:
	CLxUser_AudioLoaderTarget () {}
	CLxUser_AudioLoaderTarget (ILxUnknownID obj) : CLxLoc_AudioLoaderTarget (obj) {}



};

class CLxUser_Audio : public CLxLoc_Audio
{
	public:
	CLxUser_Audio () {}
	CLxUser_Audio (ILxUnknownID obj) : CLxLoc_Audio (obj) {}



};

class CLxUser_AudioWrite : public CLxLoc_AudioWrite
{
	public:
	CLxUser_AudioWrite () {}
	CLxUser_AudioWrite (ILxUnknownID obj) : CLxLoc_AudioWrite (obj) {}



};
#endif