/*
 * Plug-in SDK Header: C++ User Classes
 *
 * Copyright 0000
 */
#ifndef LXUSER_layer_HPP
#define LXUSER_layer_HPP

#include <lxw_layer.hpp>

	#include <lxw_item.hpp>
	#include <lxw_mesh.hpp>
	#include <lx_visitor.hpp>
	#include <lx_tool.hpp>



class CLxUser_LayerScan : public CLxLoc_LayerScan
{
	public:
	CLxUser_LayerScan () {}
	CLxUser_LayerScan (ILxUnknownID obj) : CLxLoc_LayerScan (obj) {}

	/**
	 * User class methods just make nicer wrappers for the raw COM methods.
	 */
		unsigned
	NumLayers ()
	{
		unsigned		 n;
	
		if (LXx_OK (Count (&n)))
			return n;
	
		return 0;
	}
	
		bool
	ItemByIndex (
		unsigned int		 index,
		CLxLoc_Item		&item)
	{
		LXtObjectID		 obj;
	
		if (LXx_FAIL (MeshItem (index, &obj)))
			return false;
	
		return item.take (obj);
	}
	
		bool
	BaseMeshByIndex (
		unsigned int		 index,
		CLxLoc_Mesh		&mesh)
	{
		LXtObjectID		 obj;
	
		if (LXx_FAIL (MeshBase (index, &obj)))
			return false;
	
		return mesh.take (obj);
	}
	
		bool
	EditMeshByIndex (
		unsigned int		 index,
		CLxLoc_Mesh		&mesh)
	{
		LXtObjectID		 obj;
	
		if (LXx_FAIL (MeshEdit (index, &obj)))
			return false;
	
		return mesh.take (obj);
	}

};

class CLxUser_TransformScan : public CLxLoc_TransformScan
{
	public:
	CLxUser_TransformScan () {}
	CLxUser_TransformScan (ILxUnknownID obj) : CLxLoc_TransformScan (obj) {}

	/**
	 * The user class method allows easier access to the enumeration method.
	 */
		LxResult
	Enum (
		CLxImpl_AbstractVisitor	*visitor)
	{
		CLxInst_OneVisitor<CLxGenericVisitor>	gv;
	
		gv.loc.vis = visitor;
		return Enumerate (gv);
	}

};

class CLxUser_LayerService : public CLxLoc_LayerService
{
	public:
	/**
	 * - ScanAllocate()
	 * Initialize and return a layer scan object.
	 */
		bool
	BeginScan (
		unsigned int		 flags,
		CLxLoc_LayerScan	&scan)
	{
		LXtObjectID		 obj;
	
		if (LXx_FAIL (ScanAllocate (flags, &obj)))
			return false;
	
		return scan.take (obj);
	}
	bool
	BeginXfrm (
		ILxUnknownID		 toolVec,
		CLxLoc_TransformScan	&xfrm)
	{
		LXtObjectID		 obj;
	
		if (LXx_FAIL (XfrmAllocate (toolVec, &obj)))
			return false;
	
		return xfrm.take (obj);
	}

};
#endif