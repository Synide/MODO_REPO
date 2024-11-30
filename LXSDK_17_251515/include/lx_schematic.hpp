/*
 * Plug-in SDK Header: C++ User Classes
 *
 * Copyright 0000
 */
#ifndef LXUSER_schematic_HPP
#define LXUSER_schematic_HPP

#include <lxw_schematic.hpp>

	#include <lxw_item.hpp>



class CLxUser_SchematicConnection : public CLxLoc_SchematicConnection
{
	public:
	CLxUser_SchematicConnection () {}
	CLxUser_SchematicConnection (ILxUnknownID obj) : CLxLoc_SchematicConnection (obj) {}



};

class CLxUser_SchemaDest : public CLxLoc_SchemaDest
{
	public:
	CLxUser_SchemaDest () {}
	CLxUser_SchemaDest (ILxUnknownID obj) : CLxLoc_SchemaDest (obj) {}

	bool
	GetGroup (
		CLxLoc_Item		&item)
	{
		LXtObjectID		 obj;
	
		if (LXx_FAIL (Item (&obj)))
			return false;
	
		return item.take (obj);
	}
	
		bool
	GetItem (
		CLxLoc_Item		&item)
	{
		LXtObjectID		 obj;
	
		if (LXx_FAIL (Item (&obj)))
			return false;
	
		return item.take (obj);
	}

};

class CLxUser_SchematicGroup : public CLxLoc_SchematicGroup
{
	public:
	CLxUser_SchematicGroup () {}
	CLxUser_SchematicGroup (ILxUnknownID obj) : CLxLoc_SchematicGroup (obj) {}

	unsigned int
	NNodes ()
	{
		unsigned int		 count = 0;
	
		if (LXx_OK (NodeCount (&count)))
			return count;
	
		return 0;
	}

};

class CLxUser_SchematicNode : public CLxLoc_SchematicNode
{
	public:
	CLxUser_SchematicNode () {}
	CLxUser_SchematicNode (ILxUnknownID obj) : CLxLoc_SchematicNode (obj) {}

	unsigned int
	NSubNodes ()
	{
		unsigned int		 count = 0;
	
		if (LXx_OK (SubNodeCount (&count)))
			return count;
	
		return 0;
	}

};
#endif