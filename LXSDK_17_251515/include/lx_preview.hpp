/*
 * Plug-in SDK Header: C++ User Classes
 *
 * Copyright 0000
 */
#ifndef LXUSER_preview_HPP
#define LXUSER_preview_HPP

#include <lxw_preview.hpp>


class CLxUser_PreviewService : public CLxLoc_PreviewService
{
	public:
	bool
	NewPreview (
		CLxLoc_Preview		 &preview )
	{
		LXtObjectID		  obj;
	
		if (LXx_FAIL (CreatePreview (&obj)))
			return false;
	
		return preview.take (obj);
	}

};

class CLxUser_Preview : public CLxLoc_Preview
{
	public:
	bool
	GetImage (
		CLxLoc_Image		 &image )
	{
		LXtObjectID		  obj;
	
		if (LXx_FAIL (GetBuffer (&obj)))
			return false;
	
		return image.take (obj);
	}

};
#endif