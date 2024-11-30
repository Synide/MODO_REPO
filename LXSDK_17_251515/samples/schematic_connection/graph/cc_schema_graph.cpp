/*
 * MODO SDK SAMPLE
 *
 * SchematicConnection server
 * ==========================
 *
 *	Copyright 0000
 *
 * This implements a SchematicConnection server for a custom graph. It also
 * implements a package for defining the graph and testing the server.
 *
 * CLASSES USED:
 *
 *		CLxSchematicConnection
 *		CLxPackage
 *		CLxMeta_SchematicConnection
 *		CLxMeta_Package
 *
 * TESTING:
 *
 * Add the item
 * Test graphs in schematic
 */
#include <lxidef.h>
#include <lxu_package.hpp>
#include <lxu_schematic.hpp>



#define SRVNAME_SCHEMA  "csam.schema.graph"
#define SRVNAME_PACKAGE "csam.schema.graph"

#define GRAPH_NAME "csam.schema.graph"

namespace SchemaGraph
{

    /*
     * ------------------------------------------------------------
     * There's no need to subclass the CLxSchematicConnection class because we're
     * only going to use default behavior.
     *
     *	- Links are managed using a graph.
     *	- Connection points are added only to one item type.
     *	- Items of all types can be connected.
     *
     * Any or all of these can be overridden by methods on a custom
     * CLxSchematicConnection class, but it's not required.
     *
     * Likewise we're going to use the default CLxPackage class because we don't
     * need any custom item behaviors on our test item.
     */

    /*
     * ------------------------------------------------------------
     * Metaclasses
     *
     * The name of the server is passed to the constructor.
     */
    static CLxMeta_SchematicConnection<CLxSchematicConnection> schema_meta(SRVNAME_SCHEMA);
    static CLxMeta_Package<CLxPackage>                         pkg_meta(SRVNAME_PACKAGE);

    /*
     * ------------------------------------------------------------
     * Metaclass declaration.
     *
     *	root
     *	 |
     *	 +---	schematic connection (server)
     *	 |
     *	 +---	package (server)
     *
     * The schematic connection is configured to use our graph and item type. It
     * will allow single connections and make the links in the default order. Adding
     * flags would let us make it a multiple connection and use reverse links.
     *
     * The package sets its supertype to locator and defines the graph.
     */
    static class CRoot : public CLxMetaRoot
    {
        bool pre_init() override
        {
            schema_meta.set_graph(GRAPH_NAME);
            schema_meta.set_itemtype(SRVNAME_PACKAGE);

            pkg_meta.set_supertype(LXsITYPE_LOCATOR);
            pkg_meta.add_tag(LXsPKG_GRAPHS, GRAPH_NAME);

            add(&schema_meta);
            add(&pkg_meta);
            return false;
        }

    } root_meta;

};  // namespace SchemaGraph
