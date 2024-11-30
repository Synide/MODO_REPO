/*
 * LX listcache module
 *
 * Copyright 0000
 */
#ifndef LX_listcache_H
#define LX_listcache_H

typedef struct vt_ILxItemListType ** ILxItemListTypeID;


/*
 * When first created an item list type object will have the argument string
 * and root item set to define the context for this list.
 * 
 * To generate the list the item is passed an empty item collection. The server
 * should add the items to the collection in order. The scene will be assured to
 * contain the root item, if any.
 */
typedef struct vt_ILxItemListType {
	ILxUnknown	 iunk;
	LXxMETHOD(  LxResult,
SetArgument) (
	LXtObjectID		 self,
	const char		*arg);

	LXxMETHOD(  LxResult,
SetRootItem) (
	LXtObjectID		 self,
	LXtObjectID		 item);
	LXxMETHOD(  LxResult,
GenerateList) (
	LXtObjectID		 self,
	LXtObjectID		 scene,
	LXtObjectID		 collection);
} ILxItemListType;

/*
 * Different types of item lists can be created based on item list type servers.
 * Each server gets passed an argument string and root item and is then required
 * to generate a list matching those settings.
 * The force interface allows clients to compute forces from positions
 * and other element features.
 */

	#define LXu_ITEMLISTTYPE	"14EC78B2-8DAB-4E8B-8D38-142092950AE8"
	#define LXa_ITEMLISTTYPE	"itemlisttype"
	// [export]  ILxItemListType ilt
	// [local]   ILxItemListType

/*
 * Invalidation will happen on any scene change event or any selection event
 * UNLESS any of these server tags are set.
 * - ITEMTYPES
 * This can be set to a list of item types that affect this list type. Changes
 * to items of a different type will not invalidate lists of this type.
 * - GRAPHS
 * This can be set to a list of graph names that affect this list type. Changes
 * different graphs will not invalidate lists of this type.
 * 
 * - NOSELECTION
 * This tag can be set to any value, and if set then item selection events will
 * not invalidate lists of this type.
 * 
 */

	#define LXsILT_ITEMTYPES	"itemlist.itemtypes"
	#define LXsILT_GRAPHS		"itemlist.graphs"
	#define LXsILT_NOSELECTION	"itemlist.nosel"

/*
 * The "by-type" list will list all items matching a set of types. The types
 * are given by whitespace delimited list of type names in the argument string.
 * By default the type will test for subtypes but if the name is preceded by
 * "=" then the type must match exactly.
 */

	#define LXsITEMLIST_BYTYPE	"list.byType"

/*
 * The "sub-items" list will include any items are are parented to the root item
 * for the list. Like "by-type" the argument string is a list of types to include.
 */

	#define LXsITEMLIST_SUBITEMS	"list.subItems"

#endif