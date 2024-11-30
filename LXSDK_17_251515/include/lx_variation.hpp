/*
 * Plug-in SDK Header: C++ User Classes
 *
 * Copyright 0000
 */
#ifndef LXUSER_variation_HPP
#define LXUSER_variation_HPP

#include <lxw_variation.hpp>


class CLxUser_Variation : public CLxLoc_Variation
{
	public:
	CLxUser_Variation () {}
	CLxUser_Variation (ILxUnknownID obj) : CLxLoc_Variation (obj) {}



};

class CLxUser_VariationService : public CLxLoc_VariationService
{
	public:


};
#endif