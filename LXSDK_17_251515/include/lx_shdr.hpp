/*
 * Plug-in SDK Header: C++ User Classes
 *
 * Copyright 0000
 */
#ifndef LXUSER_shdr_HPP
#define LXUSER_shdr_HPP

#include <lxw_shdr.hpp>

	#include <lx_visitor.hpp>



class CLxUser_Shader : public CLxLoc_Shader
{
	public:
	CLxUser_Shader () {}
	CLxUser_Shader (ILxUnknownID obj) : CLxLoc_Shader (obj) {}

CLxUser_Shader (
		CLxLoc_Item		meshItem,
		LXtPolygonID		poly = NULL)
	{
		CLxLoc_ShaderService	 shdrSrv;
		LXtObjectID		 acc;
		LxResult		 resultCode;
	
		_init ();
		clear ();
	
		if (poly != NULL)
			resultCode = shdrSrv.PolyShaderAccessor (meshItem, poly, &acc);
		else
			resultCode = shdrSrv.MeshShaderAccessor (meshItem, &acc);
	
		if (LXx_OK (resultCode)) {
			take (acc);
		}
	}
	
		LxResult
	Enum (
		CLxImpl_AbstractVisitor	*visitor)
	{
		CLxInst_OneVisitor<CLxGenericVisitor>  gv;
	
		gv.loc.vis = visitor;
		return Enumerate (gv);
	}
	
		bool
	duplicate (
		CLxLoc_Shader		&acc)
	{
		LXtObjectID		 obj;
	
		acc.clear ();
		if (LXx_FAIL (Spawn (&obj)))
			return false;
	
		return acc.take (obj);
	}
	bool
	GetShaderItem (
		CLxLoc_Item		&item)
	{
		LXtObjectID		 obj;
	
		if (LXx_FAIL (ShaderItemGet (&obj)))
			return false;
	
		return item.take (obj);
	}

};

class CLxUser_ShaderService : public CLxLoc_ShaderService
{
	public:
	bool
	GetMeshShaders (
		CLxLoc_Item		&meshItem,
		CLxLoc_Shader		&acc)
	{
		LXtObjectID		 obj;
	
		acc.clear ();
		if (LXx_FAIL (MeshShaderAccessor (meshItem, &obj)))
			return false;
	
		return acc.take (obj);
	}
	
		bool
	GetPolyShaders (
		CLxLoc_Item		&meshItem,
		LXtPolygonID		 polyID,
		CLxLoc_Shader		&acc)
	{
		LXtObjectID		 obj;
	
		acc.clear ();
		if (LXx_FAIL (PolyShaderAccessor (meshItem, polyID, &obj)))
			return false;
	
		return acc.take (obj);
	}

};
#endif