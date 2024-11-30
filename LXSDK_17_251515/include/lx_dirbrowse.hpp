/*
 * Plug-in SDK Header: C++ User Classes
 *
 * Copyright 0000
 */
#ifndef LXUSER_dirbrowse_HPP
#define LXUSER_dirbrowse_HPP

#include <lxw_dirbrowse.hpp>


class CLxUser_DirCacheEntry : public CLxLoc_DirCacheEntry
{
	public:
	CLxUser_DirCacheEntry () {}
	CLxUser_DirCacheEntry (ILxUnknownID obj) : CLxLoc_DirCacheEntry (obj) {}

	/**
	 * Empty DirCacheEntry Python user class.
	 */
	

};

class CLxUser_DirEntryThumbAsync : public CLxLoc_DirEntryThumbAsync
{
	public:
	CLxUser_DirEntryThumbAsync () {}
	CLxUser_DirEntryThumbAsync (ILxUnknownID obj) : CLxLoc_DirEntryThumbAsync (obj) {}

	/**
	 * Empty DirEntryThumbAsync Python user class.
	 */
	

};

class CLxUser_MergedDirCacheEntry : public CLxLoc_MergedDirCacheEntry
{
	public:
	CLxUser_MergedDirCacheEntry () {}
	CLxUser_MergedDirCacheEntry (ILxUnknownID obj) : CLxLoc_MergedDirCacheEntry (obj) {}

	/**
	 * Empty MergedDirCacheEntry Python user class.
	 */
	

};

class CLxUser_DirCacheFileMetrics : public CLxLoc_DirCacheFileMetrics
{
	public:
	CLxUser_DirCacheFileMetrics () {}
	CLxUser_DirCacheFileMetrics (ILxUnknownID obj) : CLxLoc_DirCacheFileMetrics (obj) {}

	/**
	 * Empty DirCacheFileMetrics Python user class.
	 */
	

};

class CLxUser_BasePathAddDest : public CLxLoc_BasePathAddDest
{
	public:
	CLxUser_BasePathAddDest () {}
	CLxUser_BasePathAddDest (ILxUnknownID obj) : CLxLoc_BasePathAddDest (obj) {}



};

class CLxUser_DirCacheManualOrderDest : public CLxLoc_DirCacheManualOrderDest
{
	public:
	CLxUser_DirCacheManualOrderDest () {}
	CLxUser_DirCacheManualOrderDest (ILxUnknownID obj) : CLxLoc_DirCacheManualOrderDest (obj) {}



};

class CLxUser_DirCacheGridPosDest : public CLxLoc_DirCacheGridPosDest
{
	public:
	CLxUser_DirCacheGridPosDest () {}
	CLxUser_DirCacheGridPosDest (ILxUnknownID obj) : CLxLoc_DirCacheGridPosDest (obj) {}



};

class CLxUser_FileSysDest : public CLxLoc_FileSysDest
{
	public:
	CLxUser_FileSysDest () {}
	CLxUser_FileSysDest (ILxUnknownID obj) : CLxLoc_FileSysDest (obj) {}



};

class CLxUser_MergedFileSysDest : public CLxLoc_MergedFileSysDest
{
	public:
	CLxUser_MergedFileSysDest () {}
	CLxUser_MergedFileSysDest (ILxUnknownID obj) : CLxLoc_MergedFileSysDest (obj) {}



};

class CLxUser_DirBrowserBasePathEntryDest : public CLxLoc_DirBrowserBasePathEntryDest
{
	public:
	CLxUser_DirBrowserBasePathEntryDest () {}
	CLxUser_DirBrowserBasePathEntryDest (ILxUnknownID obj) : CLxLoc_DirBrowserBasePathEntryDest (obj) {}



};

class CLxUser_DirCacheService : public CLxLoc_DirCacheService
{
	public:
	/**
	 * Empty DirCache service user classes.
	 */
	

};
#endif