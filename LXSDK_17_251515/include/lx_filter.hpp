/*
 * Plug-in SDK Header: C++ User Classes
 *
 * Copyright 0000
 */
#ifndef LXUSER_filter_HPP
#define LXUSER_filter_HPP

#include <lxw_filter.hpp>


class CLxUser_EvaluationStack : public CLxLoc_EvaluationStack
{
	public:
	CLxUser_EvaluationStack () {}
	CLxUser_EvaluationStack (ILxUnknownID obj) : CLxLoc_EvaluationStack (obj) {}

	bool
	MakeBranch (
		CLxLoc_EvaluationStack	&branch)
	{
		LXtObjectID		 obj;
	
		if (LXx_FAIL (Branch (&obj)))
			return false;
	
		return branch.take (obj);
	}

};

class CLxUser_StackFilter : public CLxLoc_StackFilter
{
	public:
	CLxUser_StackFilter () {}
	CLxUser_StackFilter (ILxUnknownID obj) : CLxLoc_StackFilter (obj) {}



};

class CLxUser_CacheData : public CLxLoc_CacheData
{
	public:
	CLxUser_CacheData () {}
	CLxUser_CacheData (ILxUnknownID obj) : CLxLoc_CacheData (obj) {}



};

class CLxUser_CacheService : public CLxLoc_CacheService
{
	public:


};
#endif