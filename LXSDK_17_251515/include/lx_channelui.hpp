/*
 * Plug-in SDK Header: C++ User Classes
 *
 * Copyright 0000
 */
#ifndef LXUSER_channelui_HPP
#define LXUSER_channelui_HPP

#include <lxw_channelui.hpp>

	#include <lx_command.hpp>
	#include <lxu_getstring.hpp>



class CLxUser_ChannelUIService : public CLxLoc_ChannelUIService
{
	public:
class Tmp_Sgs {
	    public:
		CLxLoc_ChannelUIService	*srv;
		LXtItemType		 typeID;
		const char		*mapName;
		unsigned		 useSuper, addIcon;
		bool			 isMap;
	
		LxResult sgs_GetString (char *buf, unsigned int len)
		{
			if (isMap)
				return srv->MeshMapUserName (mapName, addIcon, buf, len);
			else
				return srv->ItemTypeIconText (typeID, useSuper, buf, len);
		}
	};
	
		LxResult
	GetTypeIcon (
		LXtItemType		 typeID,
		unsigned		 useSuper,
		std::string		&text)
	{
		Tmp_Sgs				 tmp;
		CLxSafeGetString<Tmp_Sgs>	 sgs;
	
		tmp.srv      = this;
		tmp.typeID   = typeID;
		tmp.useSuper = useSuper;
		tmp.isMap    = false;
		return sgs.GetString (tmp, text);
	}
	
		LxResult
	GetMapUserName (
		const char		*name,
		unsigned		 addIcon,
		std::string		&text)
	{
		Tmp_Sgs				 tmp;
		CLxSafeGetString<Tmp_Sgs>	 sgs;
	
		tmp.srv     = this;
		tmp.mapName = name;
		tmp.addIcon = addIcon;
		tmp.isMap   = true;
		return sgs.GetString (tmp, text);
	}

};
#endif