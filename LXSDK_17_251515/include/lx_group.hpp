/*
 * Plug-in SDK Header: C++ User Classes
 *
 * Copyright 0000
 */
#ifndef LXUSER_group_HPP
#define LXUSER_group_HPP

#include <lxw_group.hpp>

	#include <lx_visitor.hpp>



class CLxUser_GroupItem : public CLxLoc_GroupItem
{
	public:
	CLxUser_GroupItem () {}
	CLxUser_GroupItem (ILxUnknownID obj) : CLxLoc_GroupItem (obj) {}

	bool
	GetEnumerator (
		CLxLoc_GroupEnumerator	&grpEnum)
	{
		LXtObjectID		 obj;
	
		if (LXx_OK (Enumerator (&obj)))
			return grpEnum.take (obj);
	
		grpEnum.clear ();
		return false;
	}
	
		int
	GetType ()
	{
		int type;
		if (LXx_OK(Type(&type)))
		{
			return type;
		}
	
		return LXi_GROUP_TYPE_STANDARD;
	}
	
		bool
	SetType (
		int type)
	{
		if (LXx_OK(CLxLoc_GroupItem::SetType(type)))
			return true;
	
		return false;
	}

};

class CLxUser_GroupEnumerator : public CLxLoc_GroupEnumerator
{
	public:
	CLxUser_GroupEnumerator () {}
	CLxUser_GroupEnumerator (ILxUnknownID obj) : CLxLoc_GroupEnumerator (obj) {}

	LxResult
	Enum (
		CLxImpl_AbstractVisitor	*visitor,
		unsigned		 mask = LXfGRPTYPE_BOTH)
	{
		CLxInst_OneVisitor<CLxGenericVisitor>  gv;
	
		gv.loc.vis = visitor;
		return Enumerate (gv, mask);
	}
	
		bool
	GetItem (
		CLxLoc_Item		&item)
	{
		LXtObjectID		 obj;
	
		if (LXx_OK (Item (&obj)))
			return item.take (obj);
	
		item.clear ();
		return false;
	}

};
#endif