/*
 * LX group module
 *
 * Copyright 0000
 */
#ifndef LX_group_H
#define LX_group_H

typedef struct vt_ILxGroupItem ** ILxGroupItemID;
typedef struct vt_ILxGroupEnumerator ** ILxGroupEnumeratorID;
typedef struct vt_ILxPresetPackageService ** ILxPresetPackageServiceID;


/*
 * Since the enumeration has state we have to allocate one from the item interface.
 * Get the Group Item's type.
 * 
 * Set the Group Item's type.
 */
typedef struct vt_ILxGroupItem {
	ILxUnknown	 iunk;
	LXxMETHOD(  LxResult,
Enumerator) (
	LXtObjectID		 self,
	void		       **ppvObj);
	LXxMETHOD(  LxResult,
Type) (
	LXtObjectID		 self,
	int			*type);	
	LXxMETHOD(  LxResult,
SetType) (
	LXtObjectID		 self,
	int			 type);		
} ILxGroupItem;

/*
 * The Enumerate() method takes a visitor and calls its Evaluate() method for
 * each group member. The mask is used to select items, channels or both. During
 * each Evaluate() call, the visitor can query the type of member and get information
 * about the member.
 */
typedef struct vt_ILxGroupEnumerator {
	ILxUnknown	 iunk;
	LXxMETHOD(  LxResult,
Enumerate) (
	LXtObjectID		 self,
	LXtObjectID		 visitor,
	unsigned		 mask);

	LXxMETHOD(  unsigned,
Type) (
	LXtObjectID		 self);

	LXxMETHOD(  LxResult,
Item) (
	LXtObjectID		 self,
	void		       **ppvObj);

	LXxMETHOD(  LxResult,
Channel) (
	LXtObjectID		 self,
	void		       **ppvObj,
	unsigned		*index);
} ILxGroupEnumerator;

typedef struct vt_ILxPresetPackageService {
	ILxUnknown	 iunk;
	LXxMETHOD( const char*,
Version) (
	LXtObjectID	 self,
	const char	*pkg);

	LXxMETHOD( const char*,
UserVersion) (
	LXtObjectID	 self,
	const char	*pkg);

	LXxMETHOD( const char*,
Type) (
	LXtObjectID	 self,
	const char	*pkg);

	LXxMETHOD( unsigned,
AssemblyType) (
	LXtObjectID	 self,
	const char	*pkg);

	LXxMETHOD( unsigned,
CountFiles) (
	LXtObjectID	 self,
	const char	*pkg);

	LXxMETHOD( LxResult,
Filename) (
	LXtObjectID	 self,
	const char	*pkg,
	unsigned	 id,
	char		*buf,
	int		 len);

	LXxMETHOD( LxResult,
HasFile) (
	LXtObjectID	 self,
	const char	*pkg,
	const char	*file);

	LXxMETHOD( LxResult,
Extract) (
	LXtObjectID	 self,
	const char	*pkg,
	const char	*file,
	const char	*dest);

	LXxMETHOD( LxResult,
ExtractAll) (
	LXtObjectID	 self,
	const char	*pkg,
	const char	*dest,
	const char	*subDir);

	LXxMETHOD( LxResult,
AddFile) (
	LXtObjectID	 self,
	const char	*pkg,
	const char	*filename,
	const char	*filepath);

	LXxMETHOD( LxResult,
RemoveFile) (
	LXtObjectID	 self,
	const char	*pkg,
	const char	*filename);

	LXxMETHOD( LxResult,
ReplaceFile) (
	LXtObjectID	 self,
	const char	*pkg,
	const char	*filename,
	const char	*filepath);
} ILxPresetPackageService;


	#define	LXi_GROUP_TYPE_STANDARD		0
	#define	LXi_GROUP_TYPE_ASSEMBLY		1
	#define	LXi_GROUP_TYPE_ACTOR		2
	#define	LXi_GROUP_TYPE_RENDER		3
	#define LXi_GROUP_TYPE_KEYSET		4
	#define LXi_GROUP_TYPE_CHANSET		5
	#define LXi_GROUP_TYPE_PRESET		6
	#define LXi_GROUP_TYPE_SHADER		7

/*
 * The GroupItem interface provides services for operating on a group. Mainly
 * enumerating the members of the group.
 */

	#define LXu_GROUPITEM		"47FDFD87-3FBA-41A4-8044-74EC9D9AA986"
	// [local]  ILxGroupItem
	// [python] ILxGroupItem:Enumerator	obj GroupEnumerator

/*
 * The GroupEnumerator interface allows traversal of the members of the group
 * item, both items and channels.
 */

	#define LXu_GROUPENUMERATOR	"CA4E1FE0-B655-429F-9674-3E1D7DEA5D04"
	// [local]  ILxGroupEnumerator
	// [python] ILxGroupEnumerator:Item	obj Item (item)
	// [python] ILxGroupEnumerator:Channel	obj Item

	#define LXfGRPTYPE_ITEM		 0x01
	#define LXfGRPTYPE_CHANNEL	 0x02
	#define LXfGRPTYPE_BOTH		(LXfGRPTYPE_ITEM | LXfGRPTYPE_CHANNEL)

/*
 * Plug-ins can use the File service for various package operations, such as getting
 * the type, the version, adding, remove files and so on.
 * Some of the function already exist in file serivce.
 */

	#define LXu_PRESETPACKAGESERVICE		"b37c7c4d-e91f-406b-a80b-8d761a623088"
	#define LXa_PRESETPACKAGESERVICE		"presetpackageservice"

/*
 * AssemblyType() returns the assembly types for a given package, as defined by
 * one of the LXsGROUP_ASSEMBLYst_ defines.
 */

	#define LXiASSEMBLY_SUBTYPEt_GENERAL		0
	#define LXiASSEMBLY_SUBTYPEt_MESH			1
	#define LXiASSEMBLY_SUBTYPEt_MATERIALL		2
	#define LXiASSEMBLY_SUBTYPEt_ENVIRONMENT	3
	
	#define LXsASSEMBLY_SUBTYPEs_GENERAL		"general"
	#define LXsASSEMBLY_SUBTYPEs_MESH			"mesh"
	#define LXsASSEMBLY_SUBTYPEs_MATERIALL		"material"
	#define LXsASSEMBLY_SUBTYPEs_ENVIRONMENT	"environment"

#endif