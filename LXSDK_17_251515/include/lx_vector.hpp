/*
 * Plug-in SDK Header: C++ User Classes
 *
 * Copyright 0000
 */
#ifndef LXUSER_vector_HPP
#define LXUSER_vector_HPP

#include <lxw_vector.hpp>


class CLxUser_VectorType : public CLxLoc_VectorType
{
	public:
	CLxUser_VectorType () {}
	CLxUser_VectorType (ILxUnknownID obj) : CLxLoc_VectorType (obj) {}



};

class CLxUser_VectorList : public CLxLoc_VectorList
{
	public:
	CLxUser_VectorList () {}
	CLxUser_VectorList (ILxUnknownID obj) : CLxLoc_VectorList (obj) {}

	// QWEB_MACRO_BEGIN - SDK Common user: Vector methods
		void *
	Read (
		unsigned int		 offset)
	{
		void			*pkt;
	
		if (LXx_FAIL (Readable (offset, &pkt)))
			return 0;
	
		return pkt;
	}
	
		void *
	Write (
		unsigned int		 offset)
	{
		void			*pkt;
	
		if (LXx_FAIL (Writable (offset, &pkt)))
			return 0;
	
		return pkt;
	}
	
		bool
	ReadObject (
		unsigned int		 offset,
		CLxLocalizedObject	&loc)
	{
		LXtObjectID		 obj;
	
		loc.clear ();
		if (LXx_FAIL (Readable (offset, &obj)))
			return false;
	
		return loc.set (obj);
	}
	
		bool
	WriteObject (
		unsigned int		 offset,
		CLxLocalizedObject	&loc)
	{
		LXtObjectID		 obj;
	
		loc.clear ();
		if (LXx_FAIL (Writable (offset, &obj)))
			return false;
	
		return loc.set (obj);
	}
		// QWEB_MACRO_END - SDK Common user: Vector methods

};

class CLxUser_VectorStack : public CLxLoc_VectorStack
{
	public:
	CLxUser_VectorStack () {}
	CLxUser_VectorStack (ILxUnknownID obj) : CLxLoc_VectorStack (obj) {}

	// QWEB_MACRO_BEGIN - SDK Common user: Vector methods
		void *
	Read (
		unsigned int		 offset)
	{
		void			*pkt;
	
		if (LXx_FAIL (Readable (offset, &pkt)))
			return 0;
	
		return pkt;
	}
	
		void *
	Write (
		unsigned int		 offset)
	{
		void			*pkt;
	
		if (LXx_FAIL (Writable (offset, &pkt)))
			return 0;
	
		return pkt;
	}
	
		bool
	ReadObject (
		unsigned int		 offset,
		CLxLocalizedObject	&loc)
	{
		LXtObjectID		 obj;
	
		loc.clear ();
		if (LXx_FAIL (Readable (offset, &obj)))
			return false;
	
		return loc.set (obj);
	}
	
		bool
	WriteObject (
		unsigned int		 offset,
		CLxLocalizedObject	&loc)
	{
		LXtObjectID		 obj;
	
		loc.clear ();
		if (LXx_FAIL (Writable (offset, &obj)))
			return false;
	
		return loc.set (obj);
	}
		// QWEB_MACRO_END - SDK Common user: Vector methods

};

class CLxUser_PacketService : public CLxLoc_PacketService
{
	public:
	unsigned
	GetOffset (
		const char		*category,
		const char		*name)
	{
		unsigned		 offset;
	
		if (LXx_OK (Lookup (category, name, &offset)))
			return offset;
	
		return UINT_MAX;
	}
	
		bool
	PacketObject (
		ILxUnknownID		 vector,
		unsigned int		 offset,
		CLxLocalizedObject	&loc)
	{
		LXtObjectID		 obj;
	
		obj = FastPacket (vector, offset);
		if (!obj)
			return false;
	
		return loc.set (obj);
	}
	
		bool
	NewVectorType (
		const char		*category,
		CLxLoc_VectorType	&vtype)
	{
		LXtObjectID		 obj;
	
		vtype.clear ();
		if (LXx_FAIL (CreateVectorType (category, &obj)))
			return false;
	
		return vtype.take (obj);
	}

};
#endif