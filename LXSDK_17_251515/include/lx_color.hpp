/*
 * Plug-in SDK Header: C++ User Classes
 *
 * Copyright 0000
 */
#ifndef LXUSER_color_HPP
#define LXUSER_color_HPP

#include <lxw_color.hpp>


class CLxUser_ColorModel : public CLxLoc_ColorModel
{
	public:
	CLxUser_ColorModel () {}
	CLxUser_ColorModel (ILxUnknownID obj) : CLxLoc_ColorModel (obj) {}

	/**
	 * The server is assumed to have a message table in the form of "colormodel.<serverName>", where
	 * "<serverName>" is the name of the server.  It is expected to have the following messages:
	 * - Model
	 * The username of the color model itself.  Just a simple string like "RGB", "HSV", "CMYK",
	 * "Color Temperature", etc.
	 * - Component1Short
	 * - Component2Short
	 * - Component3Short
	 * - Component4Short
	 * The short label for the individual components.  These are usually single
	 * characters, such as 'R', 'G', 'B', etc.  These may be concatenated by the
	 * color picker to create longer strings, like "RGB", so keep them short and
	 * standard.
	 * - Component1Long
	 * - Component2Long
	 * - Component3Long
	 * - Component4Long
	 * The long name for the individual components.  These are usually full words,
	 * like "Red", "Green" and "Blue", and are commonly used as the labels for the
	 * controls in forms.
	 * We don't have any user functions; we just use this to force qmake to create
	 * the appropriate files.
	 */
	

};

class CLxUser_Color : public CLxLoc_Color
{
	public:
	CLxUser_Color () {}
	CLxUser_Color (ILxUnknownID obj) : CLxLoc_Color (obj) {}



};
#endif