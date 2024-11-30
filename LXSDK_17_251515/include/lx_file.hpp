/*
 * Plug-in SDK Header: C++ User Classes
 *
 * Copyright 0000
 */
#ifndef LXUSER_file_HPP
#define LXUSER_file_HPP

#include <lxw_file.hpp>

	#include <string>



class CLxUser_VirtualDevice : public CLxLoc_VirtualDevice
{
	public:
	CLxUser_VirtualDevice () {}
	CLxUser_VirtualDevice (ILxUnknownID obj) : CLxLoc_VirtualDevice (obj) {}



};

class CLxUser_FileReference : public CLxLoc_FileReference
{
	public:
	CLxUser_FileReference () {}
	CLxUser_FileReference (ILxUnknownID obj) : CLxLoc_FileReference (obj) {}

	/**
	 * Empty FileReference Python user class.
	 */
	

};

class CLxUser_FileRedirect : public CLxLoc_FileRedirect
{
	public:
	CLxUser_FileRedirect () {}
	CLxUser_FileRedirect (ILxUnknownID obj) : CLxLoc_FileRedirect (obj) {}



};

class CLxUser_FileService : public CLxLoc_FileService
{
	public:
	LxResult
	FileSystemPath (
		const char		*name,
		std::string		&path)
	{
		LxResult		 result;
		const char		*systemPath;
	
		result = CLxLoc_FileService::FileSystemPath (name, &systemPath);
		if (LXx_OK (result))
			path = std::string(systemPath);
	
		return result;
	}

};
#endif