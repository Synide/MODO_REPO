/*
 * Plug-in SDK Header: C++ User Classes
 *
 * Copyright 0000
 */
#ifndef LXUSER_particle_HPP
#define LXUSER_particle_HPP

#include <lxw_particle.hpp>

	#include <lxw_item.hpp>
	#include <lx_visitor.hpp>



class CLxUser_ParticleItem : public CLxLoc_ParticleItem
{
	public:
	CLxUser_ParticleItem () {}
	CLxUser_ParticleItem (ILxUnknownID obj) : CLxLoc_ParticleItem (obj) {}

	bool
	Alloc (
		ILxUnknownID		 attr,
		unsigned		 index,
		CLxLocalizedObject	&loc)
	{
		LXtObjectID		 obj;
	
		if (LXx_OK (Evaluate (attr, index, &obj)))
			return loc.take (obj);
	
		loc.clear ();
		return false;
	}

};

class CLxUser_ReplicatorEnumerator : public CLxLoc_ReplicatorEnumerator
{
	public:
	CLxUser_ReplicatorEnumerator () {}
	CLxUser_ReplicatorEnumerator (ILxUnknownID obj) : CLxLoc_ReplicatorEnumerator (obj) {}

	/**
	 * The two Enum() methods correspond to the two ways of acquiring an enumerator. The
	 * channel-read object is not needed for enumerators allocated as part of a modifier.
	 */
		LxResult
	Enum (
		CLxImpl_AbstractVisitor	*visitor,
		ILxUnknownID		 chan,
		bool			 localXform)
	{
		CLxInst_OneVisitor<CLxGenericVisitor>	 gv;
	
		gv.loc.vis = visitor;
		return Enumerate (gv, chan, localXform ? 1 : 0);
	}
	
		LxResult
	Enum (
		CLxImpl_AbstractVisitor	*visitor,
		bool			 localXform)
	{
		CLxInst_OneVisitor<CLxGenericVisitor>	 gv;
	
		gv.loc.vis = visitor;
		return Enumerate (gv, 0, localXform ? 1 : 0);
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

class CLxUser_ParticleEvalFrame : public CLxLoc_ParticleEvalFrame
{
	public:
	CLxUser_ParticleEvalFrame () {}
	CLxUser_ParticleEvalFrame (ILxUnknownID obj) : CLxLoc_ParticleEvalFrame (obj) {}



};

class CLxUser_ParticleFilter : public CLxLoc_ParticleFilter
{
	public:
	CLxUser_ParticleFilter () {}
	CLxUser_ParticleFilter (ILxUnknownID obj) : CLxLoc_ParticleFilter (obj) {}



};

class CLxUser_ParticleCoOperator : public CLxLoc_ParticleCoOperator
{
	public:
	CLxUser_ParticleCoOperator () {}
	CLxUser_ParticleCoOperator (ILxUnknownID obj) : CLxLoc_ParticleCoOperator (obj) {}



};

class CLxUser_PointCacheItem : public CLxLoc_PointCacheItem
{
	public:
	CLxUser_PointCacheItem () {}
	CLxUser_PointCacheItem (ILxUnknownID obj) : CLxLoc_PointCacheItem (obj) {}



};

class CLxUser_ParticleService : public CLxLoc_ParticleService
{
	public:
	LxResult
	EnumFeatures (
		ILxUnknownID		 item,
		CLxImpl_AbstractVisitor	*visitor)
	{
		CLxInst_OneVisitor<CLxGenericVisitor>  gv;
	
		gv.loc.vis = visitor;
		return EnumParticleFeatures (item, gv);
	}

};
#endif