/*
 * Plug-in SDK Header: C++ User Classes
 *
 * Copyright 0000
 */
#ifndef LXUSER_imagemon_HPP
#define LXUSER_imagemon_HPP

#include <lxw_imagemon.hpp>

	#include <string>



class CLxUser_ImageMonitor : public CLxLoc_ImageMonitor
{
	public:
	CLxUser_ImageMonitor () {}
	CLxUser_ImageMonitor (ILxUnknownID obj) : CLxLoc_ImageMonitor (obj) {}

	/**
	 * We don't have any user functions; we just use this to force qmake to create
	 * the appropriate files.
	 */
	

};

class CLxUser_ImageMonitorService : public CLxLoc_ImageMonitorService
{
	public:
	LxResult
	RefreshViews (
		const std::string	 imageSource,
		bool			 immediate)
	{
		return CLxLoc_ImageMonitorService::RefreshViews (imageSource.c_str (), immediate);
	}

};
#endif