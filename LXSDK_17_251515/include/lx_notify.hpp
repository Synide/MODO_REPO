/*
 * Plug-in SDK Header: C++ User Classes
 *
 * Copyright 0000
 */
#ifndef LXUSER_notify_HPP
#define LXUSER_notify_HPP

#include <lxw_notify.hpp>


class CLxUser_Notifier : public CLxLoc_Notifier
{
	public:
	CLxUser_Notifier () {}
	CLxUser_Notifier (ILxUnknownID obj) : CLxLoc_Notifier (obj) {}



};

class CLxUser_NotifySysService : public CLxLoc_NotifySysService
{
	public:


};
#endif