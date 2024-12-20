/*
 * Plug-in SDK Header: C++ Services
 *
 * Copyright 0000
 *
 * Helper classes for implementing schematic servers.
 */
#ifndef LXU_SCHEMATIC_HPP
#define LXU_SCHEMATIC_HPP

#include <lx_schematic.hpp>
#include <lx_item.hpp>
#include <lxu_meta.hpp>


/*
 * -------------------------------------
 * - Meta Schematic Connection
 *
 * The superclass supports basic behaviors and some customization.
 */
class CLxSchematicConnection :
		public CLxObject
{
    public:
	/*
	 * Implement this to test an item to see if it should have a connection
	 * point. The client function can call set_single() or set_multiple().
	 * If neither function is called the item has no connection.
	 */
	virtual void	test_item (CLxUser_Item &) {}

	/*
	 * Call this from test_item() to add a connection point allowing one
	 * connection.
	 */
	void		set_single ();

	/*
	 * Call this from test_item() to add a connection point allowing
	 * multiple connections. Connections may be ordered or unordered.
	 */
	void		set_multiple (bool ordered = false);

	/*
	 * Implement this to test if an incoming connection matches the
	 * destination. If unimplemented all items can be connected.
	 */
	virtual bool	allow (CLxUser_Item &/*from*/, CLxUser_Item &/*to*/) { return true; }

	/*
	 * Implement this to get connections for connections being managed
	 * manually (either because there is no graph or because 'manual' was
	 * true). The client function can call add_item() for items connected
	 * to this one.
	 */
	virtual void	get_list (CLxUser_Item &) {}

	/*
	 * Call this from get_list() to add a connected item to the ordered
	 * list.
	 */
	void		add_item (CLxUser_Item &);

	/*
	 * Implement this to add a connection for connections being managed
	 * manually.
	 */
	virtual void	connect    (CLxUser_Item &/*from*/, CLxUser_Item &/*to*/, int /*toIndex*/) {}

	/*
	 * Implement this to remove a connection for connections being managed
	 * manually.
	 */
	virtual void	disconnect (CLxUser_Item &/*from*/, CLxUser_Item &/*to*/) {}

    //internal:
	 CLxSchematicConnection ();
	~CLxSchematicConnection ();

	class pv_SchematicConnection	*pv;
};

/*
 * Core metaclass sets global properties.
 */
class CLxMeta_SchematicConnection_Core :
		public CLxMetaServer
{
    public:
	CLxMeta_SchematicConnection_Core (const char *srvName);

	/*
	 * Set the name of the graph for normal, graph-based connections. 'reverse'
	 * can be true to invert the sense of the link, and 'manual' can also be
	 * set for manual control of the links.
	 */
	void		set_graph (const char *, bool reverse = false, bool manual = false);

	/*
	 * If the connection point is to be the same on all items of a given
	 * type, this can be called to set the item type and type of connection.
	 */
	void		set_itemtype (const char *, bool multiple = false, bool ordered = false);

	/*
	 * By default the connections on items are static so each item is tested
	 * only once. This method sets the connection type to dynamic so that the
	 * settings will be refreshed when changes happen.
	 */
	void		set_dynamic ();

	/*
	 * This method should be called on any event that might change the
	 * connections on items. Only valid for dynamic schematic connections.
	 */
	void		invalidate ();

    //internal:
	~CLxMeta_SchematicConnection_Core ();

	virtual CLxSchematicConnection *	 new_inst () = 0;
	void *		alloc () override;

	class pv_Meta_SchematicConnection	*pv;
};

/*
 * Template for server metaclass.
 */
template <class T>
class CLxMeta_SchematicConnection :
		public CLxMeta_SchematicConnection_Core
{
    public:
	CLxMeta_SchematicConnection (const char *srvName) : CLxMeta_SchematicConnection_Core (srvName) { }

		CLxSchematicConnection *
	new_inst () override
	{
		return new T;
	}
};


#endif // LXU_SCHEMATIC_HPP
