/*
 * Plug-in SDK Header: C++ User Classes
 *
 * Copyright 0000
 */
#ifndef LXUSER_seltypes_HPP
#define LXUSER_seltypes_HPP

#include <lxw_seltypes.hpp>

	#include <lxw_select.hpp>
	#include <lxw_item.hpp>
	#include <lxw_mesh.hpp>



class CLxUser_ScenePacketTranslation : public CLxLoc_ScenePacketTranslation
{
	public:
	CLxUser_ScenePacketTranslation () {}
	CLxUser_ScenePacketTranslation (ILxUnknownID obj) : CLxLoc_ScenePacketTranslation (obj) {}

	// QWEB_MACRO_BEGIN - Packet Translation $$ autoInit
		bool
	autoInit ()
	{
		CLxLoc_SelectionService	 svc;
		LXtObjectID		 obj;
	
		if (LXx_FAIL (svc.Allocate (LXsSELTYP_SCENE, &obj)))
			return false;
	
		return take (obj);
	}
		// QWEB_MACRO_END - Packet Translation $$ autoInit
	
		bool
	GetScene (
		void			*packet,
		CLxLoc_Scene		&scene)
	{
		LXtObjectID		 obj;
	
		if (LXx_FAIL (Scene (packet, &obj)))
			return false;
	
		return scene.take (obj);
	}

};

class CLxUser_ItemPacketTranslation : public CLxLoc_ItemPacketTranslation
{
	public:
	CLxUser_ItemPacketTranslation () {}
	CLxUser_ItemPacketTranslation (ILxUnknownID obj) : CLxLoc_ItemPacketTranslation (obj) {}

	// QWEB_MACRO_BEGIN - Packet Translation $$ autoInit
		bool
	autoInit ()
	{
		CLxLoc_SelectionService	 svc;
		LXtObjectID		 obj;
	
		if (LXx_FAIL (svc.Allocate (LXsSELTYP_ITEM, &obj)))
			return false;
	
		return take (obj);
	}
		// QWEB_MACRO_END - Packet Translation $$ autoInit
	
		bool
	GetItem (
		void			*packet,
		CLxLoc_Item		&item)
	{
		LXtObjectID		 obj;
	
		if (LXx_FAIL (Item (packet, &obj)))
			return false;
	
		return item.take (obj);
	}

};

class CLxUser_NodePacketTranslation : public CLxLoc_NodePacketTranslation
{
	public:
	CLxUser_NodePacketTranslation () {}
	CLxUser_NodePacketTranslation (ILxUnknownID obj) : CLxLoc_NodePacketTranslation (obj) {}

	// QWEB_MACRO_BEGIN - Packet Translation $$ autoInit
		bool
	autoInit ()
	{
		CLxLoc_SelectionService	 svc;
		LXtObjectID		 obj;
	
		if (LXx_FAIL (svc.Allocate (LXsSELTYP_NODE, &obj)))
			return false;
	
		return take (obj);
	}
		// QWEB_MACRO_END - Packet Translation $$ autoInit
	
		bool
	GetNode (
		void			*packet,
		CLxLoc_Item		&node)
	{
		LXtObjectID		 obj;
	
		if (LXx_FAIL (Node (packet, &obj)))
			return false;
	
		return node.take (obj);
	}

};

class CLxUser_ChannelPacketTranslation : public CLxLoc_ChannelPacketTranslation
{
	public:
	CLxUser_ChannelPacketTranslation () {}
	CLxUser_ChannelPacketTranslation (ILxUnknownID obj) : CLxLoc_ChannelPacketTranslation (obj) {}

	// QWEB_MACRO_BEGIN - Packet Translation $$ autoInit
		bool
	autoInit ()
	{
		CLxLoc_SelectionService	 svc;
		LXtObjectID		 obj;
	
		if (LXx_FAIL (svc.Allocate (LXsSELTYP_CHANNEL, &obj)))
			return false;
	
		return take (obj);
	}
		// QWEB_MACRO_END - Packet Translation $$ autoInit
	
		bool
	GetItem (
		void			*packet,
		CLxLoc_Item		&item)
	{
		LXtObjectID		 obj;
	
		if (LXx_FAIL (Item (packet, &obj)))
			return false;
	
		return item.take (obj);
	}

};

class CLxUser_CenterPacketTranslation : public CLxLoc_CenterPacketTranslation
{
	public:
	CLxUser_CenterPacketTranslation () {}
	CLxUser_CenterPacketTranslation (ILxUnknownID obj) : CLxLoc_CenterPacketTranslation (obj) {}

	// QWEB_MACRO_BEGIN - Packet Translation $$ autoInit
		bool
	autoInit ()
	{
		CLxLoc_SelectionService	 svc;
		LXtObjectID		 obj;
	
		if (LXx_FAIL (svc.Allocate (LXsSELTYP_CENTER, &obj)))
			return false;
	
		return take (obj);
	}
		// QWEB_MACRO_END - Packet Translation $$ autoInit
	
		bool
	GetItem (
		void			*packet,
		CLxLoc_Item		&item)
	{
		LXtObjectID		 obj;
	
		if (LXx_FAIL (Item (packet, &obj)))
			return false;
	
		return item.take (obj);
	}

};

class CLxUser_PivotPacketTranslation : public CLxLoc_PivotPacketTranslation
{
	public:
	CLxUser_PivotPacketTranslation () {}
	CLxUser_PivotPacketTranslation (ILxUnknownID obj) : CLxLoc_PivotPacketTranslation (obj) {}

	// QWEB_MACRO_BEGIN - Packet Translation $$ autoInit
		bool
	autoInit ()
	{
		CLxLoc_SelectionService	 svc;
		LXtObjectID		 obj;
	
		if (LXx_FAIL (svc.Allocate (LXsSELTYP_PIVOT, &obj)))
			return false;
	
		return take (obj);
	}
		// QWEB_MACRO_END - Packet Translation $$ autoInit
	
		bool
	GetItem (
		void			*packet,
		CLxLoc_Item		&item)
	{
		LXtObjectID		 obj;
	
		if (LXx_FAIL (Item (packet, &obj)))
			return false;
	
		return item.take (obj);
	}

};

class CLxUser_LinkPacketTranslation : public CLxLoc_LinkPacketTranslation
{
	public:
	CLxUser_LinkPacketTranslation () {}
	CLxUser_LinkPacketTranslation (ILxUnknownID obj) : CLxLoc_LinkPacketTranslation (obj) {}

	// QWEB_MACRO_BEGIN - Packet Translation $$ autoInit
		bool
	autoInit ()
	{
		CLxLoc_SelectionService	 svc;
		LXtObjectID		 obj;
	
		if (LXx_FAIL (svc.Allocate (LXsSELTYP_LINK, &obj)))
			return false;
	
		return take (obj);
	}
		// QWEB_MACRO_END - Packet Translation $$ autoInit
	
		bool
	GetFrom (
		void			*packet,
		CLxLoc_Item		&item,
		int			*channel)
	{
		LXtObjectID		 obj;
	
		if (LXx_FAIL (From (packet, channel, &obj)))
			return false;
	
		return item.take (obj);
	}
	
		bool
	GetTo (
		void			*packet,
		CLxLoc_Item		&item,
		int			*channel)
	{
		LXtObjectID		 obj;
	
		if (LXx_FAIL (To (packet, channel, &obj)))
			return false;
	
		return item.take (obj);
	}

};

class CLxUser_VertexPacketTranslation : public CLxLoc_VertexPacketTranslation
{
	public:
	CLxUser_VertexPacketTranslation () {}
	CLxUser_VertexPacketTranslation (ILxUnknownID obj) : CLxLoc_VertexPacketTranslation (obj) {}

	// QWEB_MACRO_BEGIN - Packet Translation $$ autoInit
		bool
	autoInit ()
	{
		CLxLoc_SelectionService	 svc;
		LXtObjectID		 obj;
	
		if (LXx_FAIL (svc.Allocate (LXsSELTYP_VERTEX, &obj)))
			return false;
	
		return take (obj);
	}
		// QWEB_MACRO_END - Packet Translation $$ autoInit
		// QWEB_MACRO_BEGIN - SDK Common user: mesh and item methods
		bool
	GetMesh (
		void			*packet,
		CLxLoc_Mesh		&mesh)
	{
		LXtObjectID		 obj;
	
		if (LXx_FAIL (Mesh (packet, &obj)))
			return false;
	
		return mesh.take (obj);
	}
	
		bool
	GetItem (
		void			*packet,
		CLxLoc_Item		&item)
	{
		LXtObjectID		 obj;
	
		if (LXx_FAIL (Item (packet, &obj)))
			return false;
	
		return item.take (obj);
	}
		// QWEB_MACRO_END - SDK Common user: mesh and item methods

};

class CLxUser_EdgePacketTranslation : public CLxLoc_EdgePacketTranslation
{
	public:
	CLxUser_EdgePacketTranslation () {}
	CLxUser_EdgePacketTranslation (ILxUnknownID obj) : CLxLoc_EdgePacketTranslation (obj) {}

	// QWEB_MACRO_BEGIN - Packet Translation $$ autoInit
		bool
	autoInit ()
	{
		CLxLoc_SelectionService	 svc;
		LXtObjectID		 obj;
	
		if (LXx_FAIL (svc.Allocate (LXsSELTYP_EDGE, &obj)))
			return false;
	
		return take (obj);
	}
		// QWEB_MACRO_END - Packet Translation $$ autoInit
		// QWEB_MACRO_BEGIN - SDK Common user: mesh and item methods
		bool
	GetMesh (
		void			*packet,
		CLxLoc_Mesh		&mesh)
	{
		LXtObjectID		 obj;
	
		if (LXx_FAIL (Mesh (packet, &obj)))
			return false;
	
		return mesh.take (obj);
	}
	
		bool
	GetItem (
		void			*packet,
		CLxLoc_Item		&item)
	{
		LXtObjectID		 obj;
	
		if (LXx_FAIL (Item (packet, &obj)))
			return false;
	
		return item.take (obj);
	}
		// QWEB_MACRO_END - SDK Common user: mesh and item methods

};

class CLxUser_PolygonPacketTranslation : public CLxLoc_PolygonPacketTranslation
{
	public:
	CLxUser_PolygonPacketTranslation () {}
	CLxUser_PolygonPacketTranslation (ILxUnknownID obj) : CLxLoc_PolygonPacketTranslation (obj) {}

	// QWEB_MACRO_BEGIN - Packet Translation $$ autoInit
		bool
	autoInit ()
	{
		CLxLoc_SelectionService	 svc;
		LXtObjectID		 obj;
	
		if (LXx_FAIL (svc.Allocate (LXsSELTYP_POLYGON, &obj)))
			return false;
	
		return take (obj);
	}
		// QWEB_MACRO_END - Packet Translation $$ autoInit
		// QWEB_MACRO_BEGIN - SDK Common user: mesh and item methods
		bool
	GetMesh (
		void			*packet,
		CLxLoc_Mesh		&mesh)
	{
		LXtObjectID		 obj;
	
		if (LXx_FAIL (Mesh (packet, &obj)))
			return false;
	
		return mesh.take (obj);
	}
	
		bool
	GetItem (
		void			*packet,
		CLxLoc_Item		&item)
	{
		LXtObjectID		 obj;
	
		if (LXx_FAIL (Item (packet, &obj)))
			return false;
	
		return item.take (obj);
	}
		// QWEB_MACRO_END - SDK Common user: mesh and item methods

};

class CLxUser_VMapPacketTranslation : public CLxLoc_VMapPacketTranslation
{
	public:
	CLxUser_VMapPacketTranslation () {}
	CLxUser_VMapPacketTranslation (ILxUnknownID obj) : CLxLoc_VMapPacketTranslation (obj) {}

	// QWEB_MACRO_BEGIN - Packet Translation $$ autoInit
		bool
	autoInit ()
	{
		CLxLoc_SelectionService	 svc;
		LXtObjectID		 obj;
	
		if (LXx_FAIL (svc.Allocate (LXsSELTYP_VERTEXMAP, &obj)))
			return false;
	
		return take (obj);
	}
		// QWEB_MACRO_END - Packet Translation $$ autoInit

};

class CLxUser_PresetPathPacketTranslation : public CLxLoc_PresetPathPacketTranslation
{
	public:
	CLxUser_PresetPathPacketTranslation () {}
	CLxUser_PresetPathPacketTranslation (ILxUnknownID obj) : CLxLoc_PresetPathPacketTranslation (obj) {}

	// QWEB_MACRO_BEGIN - Packet Translation $$ autoInit
		bool
	autoInit ()
	{
		CLxLoc_SelectionService	 svc;
		LXtObjectID		 obj;
	
		if (LXx_FAIL (svc.Allocate (LXsSELTYP_PRESETPATH, &obj)))
			return false;
	
		return take (obj);
	}
		// QWEB_MACRO_END - Packet Translation $$ autoInit
	
		const char *
	GetPath (
		void			*packet)
	{
		const char		*path;
	
		if (LXx_FAIL (Path (packet, &path)))
			return NULL;
	
		return path;
	}
	
		const char *
	GetIdentifier (
		void			*packet)
	{
		const char		*identifier;
	
		if (LXx_FAIL (Identifier (packet, &identifier)))
			return NULL;
	
		return identifier;
	}

};

class CLxUser_ItemChannel : public CLxLoc_ItemChannel
{
	public:
	CLxUser_ItemChannel () {}
	CLxUser_ItemChannel (ILxUnknownID obj) : CLxLoc_ItemChannel (obj) {}

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

class CLxUser_VectorShapePacketTranslation : public CLxLoc_VectorShapePacketTranslation
{
	public:
	CLxUser_VectorShapePacketTranslation () {}
	CLxUser_VectorShapePacketTranslation (ILxUnknownID obj) : CLxLoc_VectorShapePacketTranslation (obj) {}

	// QWEB_MACRO_BEGIN - Packet Translation $$ autoInit
		bool
	autoInit ()
	{
		CLxLoc_SelectionService	 svc;
		LXtObjectID		 obj;
	
		if (LXx_FAIL (svc.Allocate (LXsSELTYP_VECTORSHAPE, &obj)))
			return false;
	
		return take (obj);
	}
		// QWEB_MACRO_END - Packet Translation $$ autoInit

};

class CLxUser_VectorPathPacketTranslation : public CLxLoc_VectorPathPacketTranslation
{
	public:
	CLxUser_VectorPathPacketTranslation () {}
	CLxUser_VectorPathPacketTranslation (ILxUnknownID obj) : CLxLoc_VectorPathPacketTranslation (obj) {}

	// QWEB_MACRO_BEGIN - Packet Translation $$ autoInit
		bool
	autoInit ()
	{
		CLxLoc_SelectionService	 svc;
		LXtObjectID		 obj;
	
		if (LXx_FAIL (svc.Allocate (LXsSELTYP_VECTORPATH, &obj)))
			return false;
	
		return take (obj);
	}
		// QWEB_MACRO_END - Packet Translation $$ autoInit

};

class CLxUser_VectorKnotPacketTranslation : public CLxLoc_VectorKnotPacketTranslation
{
	public:
	CLxUser_VectorKnotPacketTranslation () {}
	CLxUser_VectorKnotPacketTranslation (ILxUnknownID obj) : CLxLoc_VectorKnotPacketTranslation (obj) {}

	// QWEB_MACRO_BEGIN - Packet Translation $$ autoInit
		bool
	autoInit ()
	{
		CLxLoc_SelectionService	 svc;
		LXtObjectID		 obj;
	
		if (LXx_FAIL (svc.Allocate (LXsSELTYP_VECTORKNOT, &obj)))
			return false;
	
		return take (obj);
	}
		// QWEB_MACRO_END - Packet Translation $$ autoInit

};

class CLxUser_RenderSlotPacketTranslation : public CLxLoc_RenderSlotPacketTranslation
{
	public:
	CLxUser_RenderSlotPacketTranslation () {}
	CLxUser_RenderSlotPacketTranslation (ILxUnknownID obj) : CLxLoc_RenderSlotPacketTranslation (obj) {}

	// QWEB_MACRO_BEGIN - Packet Translation $$ autoInit
		bool
	autoInit ()
	{
		CLxLoc_SelectionService	 svc;
		LXtObjectID		 obj;
	
		if (LXx_FAIL (svc.Allocate (LXsSELTYP_RENDERSLOT, &obj)))
			return false;
	
		return take (obj);
	}
		// QWEB_MACRO_END - Packet Translation $$ autoInit

};
#endif