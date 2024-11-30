/*
 * Plug-in SDK Header: C++ Wrapper Classes
 *
 * Copyright 0000
 *
 * Drop Server Wrappers
 */
#ifndef LXU_DROP_HPP
#define LXU_DROP_HPP

#include <lxu_meta.hpp>
#include <lx_drop.hpp>
#include <lx_message.hpp>
#include <string>


/*
 * ----------------------------------------------------------------
 * Drop Metaclasses
 *
 * The actions a drop server can perform are given by CLxDropAction subclasses.
 * The 
 */
class CLxDrop;

class CLxDropAction :
		public CLxObject
{
    public:
	/*
	 * Implement to test if this action is enabled relative to this
	 * destination. Simple actions just return true or false; custom
	 * actions call CLxDrop::add_custom().
	 */
	virtual bool		enabled (ILxUnknownID /*dest*/) { return true; }

	/*
	 * Implement to return a name for the action different from the default
	 * name in the message table. The string version is called first, and if
	 * that returns null then the message version is used.
	 */
	virtual void		name_str (std::string &) {}

	/*
	 * Implement to return a name for the action coming from a custom
	 * message table.
	 */
	virtual void		name_msg (CLxUser_Message &) {}

	/*
	 * Implement to execute the action.
	 */
	virtual void		exec () {}

	/*
	 * Implement to execute a custom action given by index.
	 */
	virtual void		exec_custom (unsigned /*index*/) {}

    //internal:
	virtual void		init_drop (CLxDrop *) {}
};

/*
 * Templated class adds m_drop member pointer to client drop object.
 */
template <class T>
class CLxDropActionT :
		public CLxDropAction
{
    public:
	T		*m_drop;

    //internal:
	void init_drop (CLxDrop *drop)		override
	{
		m_drop = dynamic_cast<T *> (drop);
	}
};


/*
 * The CLxDrop class implements the customized part of a Drop server.
 */
class CLxDrop :
		public CLxObject
{
    public:
	/*
	 * Because many sources present as ValueArrays, there are two ways to
	 * recognize the source data. The general recognize_any() is called
	 * first and if that returns false then recognize_array() is called for
	 * appropriate sources.
	 *
	 * Implement to get the source data as a general object and return true
	 * if the source is recognized.
	 */
	virtual bool		recognize_any (ILxUnknownID /*src*/) { return false; }

	/*
	 * Implement to get the source as a ValueArray and return true if the
	 * source is recognized.
	 */
	virtual bool		recognize_array (CLxUser_ValueArray &/*src*/) { return false; }

	/*
	 * Implement to test if the destination is valid for any action in this
	 * drop server.
	 */
	virtual bool		enabled (ILxUnknownID /*dest*/) { return true; }

	/*
	 * Call this to add actions to a custom drop action, given by a name string.
	 * The returned index is used for executing them.
	 */
	unsigned		add_custom (const char *);

   //internal:
	 CLxDrop ();
	~CLxDrop ();

	class pv_Drop *pv;
};

/*
 * Core metaclass provides some methods for global customization.
 */
class CLxMeta_Drop_Core :
		public CLxMetaServer
{
    public:
	/*
	 * Set the source of the drop from the LXsDROPSOURCE_* symbols.
	 */
	void		 set_source_type (const char *);

	/*
	 * Actions are added one at a time. The name is the key used for the
	 * default action name in the message table. Custom drop actions can
	 * add their own actions, but are not mappable.
	 */
	void		 add_action (const char *name, CLxDropAction *, bool custom = false);

    //internal:
	 CLxMeta_Drop_Core (const char *srvName);
	~CLxMeta_Drop_Core ();

	virtual CLxDrop *	 new_inst () = 0;

	void *		 alloc () override;

	class pv_Meta_Drop *pv;
};

/*
 * Metaclass template for your specialization.
 */
template <class T>
class CLxMeta_Drop :
		public CLxMeta_Drop_Core
{
    public:
	CLxMeta_Drop (const char *srvName) : CLxMeta_Drop_Core (srvName) { }

		CLxDrop *
	new_inst () override
	{
		return new T;
	}
};

/*
 * ----------------------------------------------------------------
 * Drop Handler
 *
 * The drop handler provides a way for clients to initialize and perform a drag
 * and drop operation. A source object, and a destination object should be
 * provided, and a list of potential actions will can be enumerated and applied.
 */
class CLxDropHandler
{
    public:
	 CLxDropHandler (
		ILxUnknownID		 source,
		const std::string	&sourceType);
	
	~CLxDropHandler ();
	
	/*
	 * Test if any drop servers support the provided source and source type.
	 */
		bool
	accept_drag ();
	
	/*
	 * Set the destination object for the drop.
	 */
		bool
	set_destination (
		ILxUnknownID		 destination);
	
	/*
	 * Returns the number of actions that can be performed on the drop.
 	 */
		unsigned int
	action_count ();
	
	/*
	 * Returns the name of an action by index.
	 */
		std::string
	action_by_index (
		unsigned int		 index);
	
	/*
	 * Performs an action, specified by index.
	 */
		bool
	perform_drop (
		unsigned int		 index);
    //internal:
    private:
	class pv_CLxDropHandler	*pv;
};

#endif /* LX_DROP_HPP */
