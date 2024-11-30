/*
 * Plug-in SDK Header: C++ User Classes
 *
 * Copyright 0000
 */
#ifndef LXUSER_stddialog_HPP
#define LXUSER_stddialog_HPP

#include <lxw_stddialog.hpp>

	#include <lxw_value.hpp>
	#include <lxw_io.hpp>
	#include <string>



class CLxUser_StdDialogService : public CLxLoc_StdDialogService
{
	public:
	bool
	MonitorAllocate (
		const std::string	&title,
		CLxLoc_Monitor		&monitor)
	{
		LXtObjectID		 obj;
		LxResult		 rc;
	
		rc = CLxLoc_StdDialogService::MonitorAllocate (title.c_str (), &obj);
		if (LXx_FAIL (rc))
			return false;
	
		return monitor.take (obj);
	}
	bool
	MessageAllocate (
		CLxLoc_Message		&message)
	{
		LXtObjectID		 obj;
		LxResult		 rc;
	
		rc = CLxLoc_StdDialogService::MessageAllocate (&obj);
		if (LXx_FAIL (rc))
			return false;
	
		return message.take (obj);
	}
	bool
	AsyncMonitorAllocate (
		const std::string	&system,
		const std::string	&title,
		CLxLoc_Monitor		&monitor)
	{
		LXtObjectID		 obj;
		LxResult		 rc;
	
		rc = CLxLoc_StdDialogService::AsyncMonitorAllocate (system.c_str (), title.c_str (), &obj);
		if (LXx_FAIL (rc))
			return false;
	
		return monitor.take (obj);
	}
	
		bool
	AsyncMonitorSubAllocate (
		LXtObjectID		 parent,
		const std::string	&title,
		CLxLoc_Monitor		&monitor)
	{
		LXtObjectID		 obj;
		LxResult		 rc;
	
		rc = CLxLoc_StdDialogService::AsyncMonitorSubAllocate ((ILxUnknownID)parent, title.c_str (), &obj);
		if (LXx_FAIL (rc))
			return false;
	
		return monitor.take (obj);
	}
	bool
	AsyncMonitorAllocateWithoutAbort (
		const std::string	&system,
		const std::string	&title,
		CLxLoc_Monitor		&monitor)
	{
		LXtObjectID		 obj;
		LxResult		 rc;
	
		rc = CLxLoc_StdDialogService::AsyncMonitorAllocateWithoutAbort (system.c_str (), title.c_str (), &obj);
		if (LXx_FAIL (rc))
			return false;
	
		return monitor.take (obj);
	}

};
#endif