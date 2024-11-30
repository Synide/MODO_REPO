/*
 * Plug-in SDK Header: C++ User Classes
 *
 * Copyright 0000
 */
#ifndef LXUSER_clip_HPP
#define LXUSER_clip_HPP

#include <lxw_clip.hpp>

	#include <lxw_value.hpp>



class CLxUser_VideoClipItem : public CLxLoc_VideoClipItem
{
	public:
	CLxUser_VideoClipItem () {}
	CLxUser_VideoClipItem (ILxUnknownID obj) : CLxLoc_VideoClipItem (obj) {}

	bool
	GetFilter (
		CLxLoc_Attributes	&attr,
		void			*cache,
		CLxLocalizedObject	&filter)
	{
		LXtObjectID		 obj;
	
		if (LXx_OK (AllocFilter (attr, cache, &obj)))
			return filter.take (obj);
	
		filter.clear ();
		return false;
	}

};
#endif