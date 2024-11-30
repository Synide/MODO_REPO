/*
 * Plug-in SDK Header: C++ User Classes
 *
 * Copyright 0000
 */
#ifndef LXUSER_listener_HPP
#define LXUSER_listener_HPP

#include <lxw_listener.hpp>


class CLxUser_ListenerPort : public CLxLoc_ListenerPort
{
	public:
	CLxUser_ListenerPort () {}
	CLxUser_ListenerPort (ILxUnknownID obj) : CLxLoc_ListenerPort (obj) {}



};

class CLxUser_ListenerService : public CLxLoc_ListenerService
{
	public:
	/**
	 * Redefine the user method for RemoveListener() so it only fires for real if the
	 * interface pointer is non-null. This can happen in rare cases if the listener
	 * service is initialized after the system has shut down, like for static listener
	 * classes. The higher-level wrappers all handle this more directly.
	 */
		LxResult
	RemoveListener (
		ILxUnknownID		 object)
	{
		if (!m_loc)
			return LXe_NOINTERFACE;
	
		return CLxLoc_ListenerService::RemoveListener (object);
	}

};
/*
 * Since it's relatively common to declare listeners as singletons, we provide a
 * template class to install the listener when needed and remove it when done.
 * This is done using reference counting on the clients. Test lifecycle to prevent
 * listeners from being removed after shutdown in static objects.
 */
template <class T>
class CLxSingletonListener
{
    public:
	T			*ref;
	unsigned		 count;

	CLxSingletonListener ()
	{
		ref   = 0;
		count = 0;
	}

	~CLxSingletonListener ()
	{
		if (lx::Lifecycle () == LXiLIFECYCLE_AFTER)
			return;

		while (count)
			release ();
	}

		void
	acquire ()
	{
		if (!count)
		{
			CLxUser_ListenerService lS;

			ref = new T;
			lS.AddListener (*ref);
		}

		count++;
	}

		void
	release ()
	{
		if (!--count)
		{
			CLxUser_ListenerService lS;

			lS.RemoveListener (*ref);
			delete ref;
			ref = 0;
		}
	}

	operator       T *  ()		{	return  ref;	}
	operator const T *  ()		{	return  ref;	}

	      T& operator*  ()		{	return *ref;	}
	const T& operator*  () const	{	return *ref;	}

	      T* operator-> ()		{	return  ref;	}
	const T* operator-> () const	{	return  ref;	}
};
#endif