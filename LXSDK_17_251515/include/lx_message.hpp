/*
 * Plug-in SDK Header: C++ User Classes
 *
 * Copyright 0000
 */
#ifndef LXUSER_message_HPP
#define LXUSER_message_HPP

#include <lxw_message.hpp>
/*
 * Includes for the user classes.
 */

	#include <lx_value.hpp>


	#include <lxu_getstring.hpp>
	#include <cstdio>



class CLxUser_MessageService : public CLxLoc_MessageService
{
	public:
	bool
	NewMessage (
		CLxLoc_Message		 &msg)
	{
		LXtObjectID		  obj;
		LxResult		  rc;
	
		rc = Allocate( &obj );
		if( LXx_FAIL( rc ) )
			return false;
	
		return msg.take( obj );
	}
	bool
	DuplicateMessage (
		CLxLoc_Message		 &msg,
		CLxLoc_Message		 &source)
	{
		LxResult		  rc;
		LXtObjectID		  obj;
	
		rc = Duplicate( source, &obj );
		if( !LXx_FAIL( rc ) )
			return false;
	
		return msg.take( obj );
	}
	LxResult
	GetText (
		CLxLoc_Message		&msg,
		char			*buf,
		unsigned		 len)
	{
		return MessageText( msg, buf, len );
	}
	/**
	 * This is a safe string "get" using a dummy class to act as callback for the safe
	 * string "read" template.
	 */
	class Tmp_Sgs {
	    public:
		CLxLoc_MessageService	*srv;
		ILxUnknownID		 msg;
	
		LxResult sgs_GetString (char *buf, unsigned int len)
		{
			return srv->MessageText (msg, buf, len);
		}
	};
	
		LxResult
	GetText (
		CLxLoc_Message		&msg,
		std::string		&text)
	{
		Tmp_Sgs				 tmp;
	
		CLxSafeGetString<Tmp_Sgs>	 sgs;
	
		tmp.srv = this;
		tmp.msg = msg;
		return sgs.GetString (tmp, text);
	}
	/**
	 * The special message table for result codes can be accessed using LxResutl values
	 * as keys.
	 */
		std::string
	ResultMessage (
		LxResult		 rc)
	{
		const char		*msg;
		char			 buf[16];
	
		sprintf (buf, "%08x", rc);
		rc = RawText ("lxresult", buf, &msg);
		return std::string (LXx_OK(rc) ? msg : "");
	}

};
#endif