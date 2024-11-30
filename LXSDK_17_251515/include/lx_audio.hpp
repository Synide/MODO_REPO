/*
 * Plug-in SDK Header: C++ User Classes
 *
 * Copyright 0000
 */
#ifndef LXUSER_audio_HPP
#define LXUSER_audio_HPP

#include <lxw_audio.hpp>


class CLxUser_AudioAnimService : public CLxLoc_AudioAnimService
{
	public:
	bool
	GetAudio (
		CLxUser_Audio		&audio)
	{
		LXtObjectID		 obj;
	
		if (LXx_FAIL (Audio (&obj)))
			return false;
	
		return audio.take (obj);
	}
		bool
	GetItemAudio (
		CLxUser_Item		 item,
		CLxUser_Audio		&audio)
	{
		LXtObjectID		 obj;
	
		if (LXx_FAIL (ItemAudio (item, &obj)))
			return false;
	
		return audio.take (obj);
	}

};
#endif