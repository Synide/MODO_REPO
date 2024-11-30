/*
 * Plug-in SDK Header: C++ User Classes
 *
 * Copyright 0000
 */
#ifndef LXUSER_rendercache_HPP
#define LXUSER_rendercache_HPP

#include <lxw_rendercache.hpp>


class CLxUser_RenderCache : public CLxLoc_RenderCache
{
	public:
	CLxUser_RenderCache () {}
	CLxUser_RenderCache (ILxUnknownID obj) : CLxLoc_RenderCache (obj) {}

	bool
	GetGeoSurface (
		int		index,
	CLxLoc_GeoCacheSurface	&srf)
	{
		LXtObjectID	obj;
	
		if (LXx_FAIL (GeoSurfaceAt (index, &obj)))
			return false;
	
		return srf.set (obj);
	}

};

class CLxUser_GeoCacheSegment : public CLxLoc_GeoCacheSegment
{
	public:
	CLxUser_GeoCacheSegment () {}
	CLxUser_GeoCacheSegment (ILxUnknownID obj) : CLxLoc_GeoCacheSegment (obj) {}



};

class CLxUser_GeoCacheSurface : public CLxLoc_GeoCacheSurface
{
	public:
	CLxUser_GeoCacheSurface () {}
	CLxUser_GeoCacheSurface (ILxUnknownID obj) : CLxLoc_GeoCacheSurface (obj) {}

	bool
	GetSourceItem (
		CLxLoc_Item	&item)
	{
		LXtObjectID		obj;
	
		if (LXx_FAIL (SourceItem (&obj)))
			return false;
	
		return item.set (obj);
	}
	bool
	GetSourceSurface (
		CLxLoc_GeoCacheSurface	&srf)
	{
		LXtObjectID		obj;
	
		if (LXx_FAIL (SourceSurface (&obj)))
			return false;
	
		return srf.set (obj);
	}
	bool
	GetSegment (
		int			index,
		CLxLoc_GeoCacheSegment	&seg)
	{
		LXtObjectID		obj;
	
		if (LXx_FAIL (SegmentAt (index, &obj)))
			return false;
	
		return seg.set (obj);
	}
	bool
	GetShaderLayer (
		unsigned int	index,
		CLxLoc_Item		&item)
	{
		LXtObjectID		obj;
	
		if (LXx_FAIL (ShaderLayerAt (index, &obj)))
			return false;
	
		return item.set (obj);
	}

};

class CLxUser_RenderCacheService : public CLxLoc_RenderCacheService
{
	public:
	bool
	NewRenderCache (
		CLxLoc_RenderCache	&rcache,
		unsigned		 createFlags)
	{
		LXtObjectID		obj;
	
		if (LXx_FAIL (CreateRenderCache (&obj, createFlags)))
			return false;
	
		return rcache.take (obj);
	}

};
#endif