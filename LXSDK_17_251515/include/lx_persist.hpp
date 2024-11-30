/*
 * Plug-in SDK Header: C++ User Classes
 *
 * Copyright 0000
 */
#ifndef LXUSER_persist_HPP
#define LXUSER_persist_HPP

#include <lxw_persist.hpp>

	#include <lx_visitor.hpp>
	#include <string>



class CLxUser_PersistentEntry : public CLxLoc_PersistentEntry
{
	public:
	CLxUser_PersistentEntry () {}
	CLxUser_PersistentEntry (ILxUnknownID obj) : CLxLoc_PersistentEntry (obj) {}

	/**
	 * Easier way to get the entry count, with -1 for errors.
	 */
		int
	Number ()
	{
		unsigned int		 n;
	
		if (LXx_OK (Count (&n)))
			return n;
	
		return -1;
	}
	/**
	 * Easier way to set key/value pairs.
	 */
		bool
	SetKeyValue (
		const char		*key,
		bool			 val)
	{
		return LXx_OK (SetKeyValueInt (key, val ? 1 : 0));
	}
	
		bool
	SetKeyValue (
		const char		*key,
		int			 val)
	{
		return LXx_OK (SetKeyValueInt (key, val));
	}
	
		bool
	SetKeyValue (
		const char		*key,
		double			 val)
	{
		return LXx_OK (SetKeyValueFloat (key, val));
	}
	
		bool
	SetKeyValue (
		const char		*key,
		const char		*val)
	{
		return LXx_OK (SetKeyValueString (key, val));
	}
	
	
	/**
	 * Standard string lookup.
	 */
		LxResult
	Lookup (const std::string &key)
	{
		return CLxLoc_PersistentEntry::Lookup (key.c_str ());
	}
	/**
	 * Standard string insertion.
	 */
		LxResult
	Insert (const std::string &key)
	{
		return CLxLoc_PersistentEntry::Insert (key.c_str ());
	}

};

class CLxUser_PersistenceService : public CLxLoc_PersistenceService
{
	public:
	/**
	 * This user method on the service takes a C++ visitor object and wraps it for COM.
	 */
		LxResult
	ConfigureVis (
		const char		*name,
		CLxImpl_AbstractVisitor	*visitor)
	{
		CLxInst_OneVisitor<CLxGenericVisitor>  gv;
	
		gv.loc.vis = visitor;
		return Configure (name, gv);
	}
	/**
	 * Alternate version of the End() method to get the persistent entry in more C++
	 * friendly terms.
	 */
		bool
	EndDef (
		CLxLoc_PersistentEntry	&entry)
	{
		LXtObjectID		 obj;
	
		entry.clear ();
		if (LXx_FAIL (End (&obj)))
			return false;
	
		return entry.take (obj);
	}

};
#endif