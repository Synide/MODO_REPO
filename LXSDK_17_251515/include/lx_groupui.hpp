/*
 * Plug-in SDK Header: C++ User Classes
 *
 * Copyright 0000
 */
#ifndef LXUSER_groupui_HPP
#define LXUSER_groupui_HPP

#include <lxw_groupui.hpp>


class CLxUser_GroupDest : public CLxLoc_GroupDest
{
	public:
	CLxUser_GroupDest () {}
	CLxUser_GroupDest (ILxUnknownID obj) : CLxLoc_GroupDest (obj) {}



};

class CLxUser_GroupMemberItemDest : public CLxLoc_GroupMemberItemDest
{
	public:
	CLxUser_GroupMemberItemDest () {}
	CLxUser_GroupMemberItemDest (ILxUnknownID obj) : CLxLoc_GroupMemberItemDest (obj) {}



};

class CLxUser_GroupMemberChanDest : public CLxLoc_GroupMemberChanDest
{
	public:
	CLxUser_GroupMemberChanDest () {}
	CLxUser_GroupMemberChanDest (ILxUnknownID obj) : CLxLoc_GroupMemberChanDest (obj) {}



};

class CLxUser_PoseItem : public CLxLoc_PoseItem
{
	public:
	CLxUser_PoseItem () {}
	CLxUser_PoseItem (ILxUnknownID obj) : CLxLoc_PoseItem (obj) {}

	bool
	Create ()
	{
		if (LXx_OK(CLxLoc_PoseItem::Create()))
			return true;
		else
			return false;
	}
	
		bool
	SetFloat(
		CLxUser_Item		&item,
		std::string const	&channelName,
		double			value)
	{
		int channelIndex = item.ChannelIndex(channelName.c_str());
		if (channelIndex < 0)
			return false;
	
		return LXx_OK(CLxLoc_PoseItem::SetFloat(item, channelIndex, static_cast<float>(value)));
	}
	
		bool
	SetInt(
		CLxUser_Item		&item,
		std::string const	&channelName,
		int			value)
	{
		int channelIndex = item.ChannelIndex(channelName.c_str());
		if (channelIndex < 0)
			return false;
	
		return LXx_OK(CLxLoc_PoseItem::SetInt(item, channelIndex, value));
	}
	
		bool
	SetValue(
		CLxUser_Item		&item,
		std::string const	&channelName,
		CLxUser_ChannelRead	&chanRead)
	{
		int channelIndex = item.ChannelIndex(channelName.c_str());
		if (channelIndex < 0)
			return false;
	
		unsigned int channelType;
		if (LXx_FAIL(item.ChannelType (channelIndex, &channelType)))
			return false;
	
		switch (channelType)
		{
		case LXiCHANTYPE_FLOAT:
			{
				auto value = static_cast<float>(chanRead.FValue(item, channelIndex));
				return LXx_OK(CLxLoc_PoseItem::SetFloat(item, channelIndex, value));
			}
			break;
	
		case LXiCHANTYPE_INTEGER:
			{
				int value = chanRead.IValue(item, channelIndex);
				return LXx_OK(CLxLoc_PoseItem::SetInt(item, channelIndex, value));
			}
			break;
		}
	
		return false;
	}
	
		float
	GetFloat(
		CLxUser_Item		&item,
		std::string const	&channelName)
	{
		int channelIndex = item.ChannelIndex(channelName.c_str());
		if (channelIndex < 0)
			return false;
	
		float value = 0.0f;
		if (LXx_OK(CLxLoc_PoseItem::GetFloat(item, channelIndex, &value)))
		{
			return value;
		}
		
		return 0.0f;
	}
	
		int
	GetInt(
		CLxUser_Item		&item,
		std::string const	&channelName)
	{
		int channelIndex = item.ChannelIndex(channelName.c_str());
		if (channelIndex < 0)
			return false;
	
		int value = 0;
		if (LXx_OK(CLxLoc_PoseItem::GetInt(item, channelIndex, &value)))
		{
			return value;
		}
		
		return 0;
	}

};
#endif