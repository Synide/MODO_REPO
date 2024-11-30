/*
 * LX colormapping module
 *
 * Copyright 0000
 */
#ifndef LX_colormapping_H
#define LX_colormapping_H

typedef struct vt_ILxColorMappingModule ** ILxColorMappingModuleID;
typedef struct vt_ILxColorMapping ** ILxColorMappingID;
typedef struct vt_ILxColorMapping1 ** ILxColorMapping1ID;
typedef struct vt_ILxColorMappingService ** ILxColorMappingServiceID;

 #include <lxcom.h>
 #include <lxvmath.h>
 #include <lximage.h>
 #include <cstdio>
 #include <string>



typedef struct vt_ILxColorMappingModule {
	ILxUnknown	 iunk;
	LXxMETHOD( unsigned,
Flags) (
	LXtObjectID			self);
} ILxColorMappingModule;

/*
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 */
typedef struct vt_ILxColorMapping {
	ILxUnknown	 iunk;
	LXxMETHOD( LxResult,
Setup) (
	LXtObjectID			self,
	int				toLinear);
	LXxMETHOD( LxResult,
ToLinear) (
	LXtObjectID			self,
	const LXtFVector	sourceValues,
	LXtFVector			linearValues,
	unsigned int		length);
	LXxMETHOD( LxResult,
FromLinear) (
	LXtObjectID			self,
	const LXtFVector	linearValues,
	LXtFVector			targetValues,
	unsigned int		length);
	LXxMETHOD( LxResult,
ToLinearFast) (
	LXtObjectID			self,
	float*				buf,
	unsigned int		length);
	LXxMETHOD( LxResult,
FromLinearFast) (
	LXtObjectID			self,
	float*				buf,
	unsigned int		length);
	LXxMETHOD( LxResult,
GetLUTImage) (
	LXtObjectID			self,
	float			   **ptr);
	LXxMETHOD( LxResult,
GetShaderSource) (
	LXtObjectID			self,
	char			   **ptr);
	LXxMETHOD( const char*,
GetName) (
	LXtObjectID			self);
	LXxMETHOD( const char*,
GetCMServerName) (
	LXtObjectID			self);
	LXxMETHOD( unsigned char*,
GenerateICCProfile) (
	LXtObjectID			self,
	unsigned int*		length);
	LXxMETHOD( const char*,
GetConfigName) (
	LXtObjectID			self);
} ILxColorMapping;

typedef struct vt_ILxColorMapping1 {
	ILxUnknown	 iunk;
	LXxMETHOD( LxResult,
Setup) (
	LXtObjectID			self,
	int				toLinear);

	LXxMETHOD( LxResult,
ToLinear) (
	LXtObjectID			self,
	const LXtFVector	sourceValues,
	LXtFVector			linearValues,
	unsigned int		length);

	LXxMETHOD( LxResult,
FromLinear) (
	LXtObjectID			self,
	const LXtFVector	linearValues,
	LXtFVector			targetValues,
	unsigned int		length);

	LXxMETHOD( LxResult,
ToLinearFast) (
	LXtObjectID			self,
	float*				buf,
	unsigned int		length);

	LXxMETHOD( LxResult,
FromLinearFast) (
	LXtObjectID			self,
	float*				buf,
	unsigned int		length);

	LXxMETHOD( LxResult,
GetLUTImage) (
	LXtObjectID			self,
	float			   **ptr);

	LXxMETHOD( LxResult,
GetShaderSource) (
	LXtObjectID			self,
	char			   **ptr);

	LXxMETHOD( const char*,
GetName) (
	LXtObjectID			self);
} ILxColorMapping1;

/*
 * 
 * 
 * 
 * Get the color mapping used for displaying colors in the interface.
 * 
 * Get the color mapping used for numeric values in the interface.
 * 
 * 
 * 
 * 
 */
typedef struct vt_ILxColorMappingService {
	ILxUnknown	 iunk;
	LXxMETHOD( LxResult,
MakeColorMapping) (
	LXtObjectID		 self,
	const char		*colorspaceName,
	int			 toLinear,
	void		       **ppvObj);
	LXxMETHOD( int,
ConfigCount) (
	LXtObjectID			self);
	LXxMETHOD( LxResult,
ConfigName) (
	LXtObjectID			self,
	int					index,
	const char			**configName);
	LXxMETHOD( LxResult,
ConfigFullPath) (
	LXtObjectID			self,
	int					index,
	const char			**configPath);
	LXxMETHOD( LxResult,
RegisterColorspaceForConfig) (
	LXtObjectID			self,
	const char			*configName,
	const char			*colorspaceName);
	LXxMETHOD( LxResult,
GetDisplayColorMapping) (
	LXtObjectID			self,
	void				**ppvObj);
	LXxMETHOD( LxResult,
GetNumericColorMapping) (
	LXtObjectID			self,
	void				**ppvObj);
	LXxMETHOD( int,
ColorspaceCount) (
	LXtObjectID			self,
	const char			*configName);
	LXxMETHOD( LxResult,
ColorspaceNameByIndex) (
	LXtObjectID			self,
	const char			*configName,
	int					index,
	std::string&		colorspaceName);
	LXxMETHOD( LxResult,
ColorspaceIndexByName) (
	LXtObjectID			self,
	const char			*configName,
	const char			*colorspaceName,
	int&				index);
	LXxMETHOD( LxResult,
ColorspaceNameCombByIndex) (
	LXtObjectID			self,
	const char			*configName,
	int					index,
	std::string&		colorspaceCombName);
} ILxColorMappingService;


	#define LXu_COLORMAPPINGMODULE		"99D65C3D-D394-40E2-A71A-B174E971F462"
	#define LXa_COLORMAPPINGMODULE		"colormappingmodule"
	// [export] ILxColorMappingModule cmapmod
	// [local] ILxColorMappingModule

/*
 * ColorMapping, specifies an object used for color conversion between linear and a particular
 * colorspace.
 */

	#define LXu_COLORMAPPING	"49B0319A-BBAA-4D43-8447-631BE7297FBB"
	#define LXa_COLORMAPPING	"colormapping2"
	// [export] ILxColorMapping cmap
	// [local] ILxColorMapping

	#define	CMS_GPU_LUT3D_EDGE_SIZE 32

/*
 * --------------------------------------------------------------------------------------------
 * Old ColorMapping interface
 */

	#define LXu_COLORMAPPING1	"40D65C4F-D394-40E2-A71A-B174E971F462"
	#define LXa_COLORMAPPING1	"colormapping"
	// [export] ILxColorMapping1 cmap
	// [local] ILxColorMapping1

/*
 * The color mapping service allows color mapping items to be enumerated and created.
 */

	#define LXu_COLORMAPPINGSERVICE	"c3e44fbc-45c6-47b5-aaee-f0cc002dd474"
	#define LXa_COLORMAPPINGSERVICE "colormappingservice"
	// don't need export or local for services, as it's done automatically

	// [python] ILxColorMappingService:GetDisplayColorMapping obj ColorMapping
	// [python] ILxColorMappingService:GetNumericColorMapping obj ColorMapping
	// [python] ILxColorMappingService:MakeColorMapping obj ColorMapping

#endif