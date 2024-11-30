/*
 * LX txtr module
 *
 * Copyright 0000
 */
#ifndef LX_txtr_H
#define LX_txtr_H

typedef struct vt_ILxTextureMapFilter ** ILxTextureMapFilterID;
typedef struct vt_ILxTextureMapFilter3 ** ILxTextureMapFilter3ID;
typedef struct vt_ILxTextureMapFilter2 ** ILxTextureMapFilter2ID;
typedef struct vt_ILxTextureMapFilter1 ** ILxTextureMapFilter1ID;
typedef struct vt_ILxTextureSpotFilter ** ILxTextureSpotFilterID;
typedef struct vt_ILxTextureFalloffFilter ** ILxTextureFalloffFilterID;
typedef struct vt_ILxTextureBlendWeightFilter ** ILxTextureBlendWeightFilterID;

	#include <lxcom.h>
	#include <lxvector.h>

	enum ETextureProjectionBackfaceModes {
		LXi_TEXLAYER_BFACE_THROUGH,
		LXi_TEXLAYER_BFACE_CULLED,
		LXi_TEXLAYER_BFACE_FLIPPED,
		LXi_TEXLAYER_BFACE_FLIPPEDU,
		LXi_TEXLAYER_BFACE_FLIPPEDV
	};



/*
 * 'Evaluate' computes the texture coordinates using the texture mapping options.
 * It sets the texture position packet.
 */
typedef struct vt_ILxTextureMapFilter {
	ILxUnknown	 iunk;
    LXxMETHOD(  void,
Evaluate) (
    LXtObjectID         self,
    LXtObjectID         etor,
    LXtSampleVectorID     sv,
    double            *res,
    int             i);

    LXxMETHOD(  int,
UVMap) (
    LXtObjectID         self,
    const char           **name,
    int            *tile,
    double            *wrap,
    int            *proj,
    int            *axis,
    double            *offset,
    double            *rot,
    int            *udim,
    int            *randomOffset,
    double            *xfrm,
    LXtFQuaternion        uvInvZRotQuat);

    LXxMETHOD(  int,
VectorMap) (
    LXtObjectID         self,
    const char           **name);

    LXxMETHOD(  int,
UVTBasis) (
    LXtObjectID         self,
    int            *tangentType);

    LXxMETHOD(  int,
WorldTransform) (
    LXtObjectID         self,
    LXtFMatrix4             worldTransform);

    LXxMETHOD(  int,
TriplanarBlendPow) (
    LXtObjectID         self,
    float            &triplanarBlendPow);

    LXxMETHOD(  int,
ProjectionBackfaceMode) (
    LXtObjectID         self,
    ETextureProjectionBackfaceModes &projectionBackfaceMode);

    LXxMETHOD(  int,
ProjectionCoordSystem) (
    LXtObjectID         self,
    int				   &projectionCoordSystem);

} ILxTextureMapFilter;

/*
 * Legacy Interface, retired in 16.1
 */
typedef struct vt_ILxTextureMapFilter3 {
	ILxUnknown	 iunk;
	LXxMETHOD(  void,
Evaluate) (
	LXtObjectID		 self,
	LXtObjectID		 etor,
	LXtSampleVectorID	 sv,
	double			*res,
	int			 i);

	LXxMETHOD(  int,
UVMap) (
	LXtObjectID		 self,
	const char	       **name,
	int			*tile,
	double			*wrap,
	int			*proj,
	int			*axis,
	double			*offset,
	double			*rot,
	int			*udim,
	int			*randomOffset,
	double			*xfrm,
	LXtFQuaternion		uvInvZRotQuat);

	LXxMETHOD(  int,
VectorMap) (
	LXtObjectID		 self,
	const char	       **name);

	LXxMETHOD(  int,
UVTBasis) (
	LXtObjectID		 self,
	int			*tangentType);

} ILxTextureMapFilter3;

/*
 * Legacy Interface, retired in 15.2v2
 */
typedef struct vt_ILxTextureMapFilter2 {
	ILxUnknown	 iunk;
	LXxMETHOD(  void,
Evaluate) (
	LXtObjectID		 self,
	LXtObjectID		 etor,
	LXtSampleVectorID	 sv,
	double			*res,
	int			 i);

	LXxMETHOD(  int,
UVMap) (
	LXtObjectID		 self,
	const char	       **name,
	int			*tile,
	double			*wrap,
	int			*proj,
	int			*axis,
	double			*offset,
	double			*rot,
	int			*udim,
	int			*randomOffset,
	double			*xfrm);

	LXxMETHOD(  int,
VectorMap) (
	LXtObjectID		 self,
	const char	       **name);

	LXxMETHOD(  int,
UVTBasis) (
	LXtObjectID		 self,
	int			*tangentType);

} ILxTextureMapFilter2;

/*
 * Legacy Interface, retired in 11.2.
 */
typedef struct vt_ILxTextureMapFilter1 {
	ILxUnknown	 iunk;
	LXxMETHOD(  void,
Evaluate) (
	LXtObjectID		 self,
	LXtObjectID		 etor,
	LXtSampleVectorID	 sv,
	double			*res,
	int			 i);

	LXxMETHOD(  int,
UVMap) (
	LXtObjectID		 self,
	const char	       **name,
	int			*tile,
	double			*wrap,
	int			*proj,
	int			*axis,
	double			*offset,
	double			*rot,
	int			*udim,
	int			*randomOffset);

	LXxMETHOD(  int,
VectorMap) (
	LXtObjectID		 self,
	const char	       **name);

	LXxMETHOD(  int,
UVTBasis) (
	LXtObjectID		 self,
	int			*tangentType);

} ILxTextureMapFilter1;

/*
 * 'Evaluate' computes the spot size given the input spot size and the
 * projection options.
 * 'Count' returns the number of textures hitting the spot.
 */
typedef struct vt_ILxTextureSpotFilter {
	ILxUnknown	 iunk;
	LXxMETHOD(  void,
Evaluate) (
	LXtObjectID		 self,
	LXtObjectID		 etor,
	LXtSampleVectorID	 sv,
	double			*res);
	
	LXxMETHOD(  int,
Count) (
	LXtObjectID		 self,
	LXtSampleVectorID	 sv);
} ILxTextureSpotFilter;

/*
 * This interface computes the falloff amount at the given position.
 */
typedef struct vt_ILxTextureFalloffFilter {
	ILxUnknown	 iunk;
	LXxMETHOD(  void,
Evaluate) (
	LXtObjectID		 self,
	LXtObjectID		 etor,
	LXtSampleVectorID	 sv,
	double			*res,
	int			 i);
} ILxTextureFalloffFilter;

/*
 * This interface computes the blend weight of the texture stack at the given position.
 */
typedef struct vt_ILxTextureBlendWeightFilter {
	ILxUnknown	 iunk;
    LXxMETHOD(  float,
Evaluate) (
    LXtObjectID         self,
    LXtObjectID         etor,
    LXtSampleVectorID     sv);
} ILxTextureBlendWeightFilter;



	#define	LXi_TEXTURE_FALLOFF_CUBIC		0
	#define	LXi_TEXTURE_FALLOFF_SPHERE		1
	#define	LXi_TEXTURE_FALLOFF_LINEARX		2
	#define	LXi_TEXTURE_FALLOFF_LINEARY		3
	#define	LXi_TEXTURE_FALLOFF_LINEARZ		4



	#define	LXi_TEXTURE_RNDOFFSET_NONE		0
	#define	LXi_TEXTURE_RNDOFFSET_PART		1
	#define	LXi_TEXTURE_RNDOFFSET_MESH		2
	#define	LXi_TEXTURE_RNDOFFSET_ITEM		3


    #define LXu_TEXTUREMAPFILTER        "6479CFD4-5862-48A8-BB8D-FAF4DC3AE5B9"


	#define LXu_TEXTUREMAPFILTER3		"96704B31-F861-47A7-9A1B-ABDC41159EB6"


	#define LXu_TEXTUREMAPFILTER2		"3DC4AA9C-DEF6-4794-B0BE-F23D2869BCDC"


	#define LXu_TEXTUREMAPFILTER1		"81F4F08A-7A37-42dE-ACDE-FC5490E519C6"


	#define LXu_TEXTURESPOTFILTER		"179AD9C3-8B7B-4F91-8BB6-A23FAD3D153E"


	#define LXu_TEXTUREFALLOFFFILTER	"8F3154A6-AC4D-4610-96EF-B54E9611164B"


    #define LXu_TEXTUREBLENDWEIGHTFILTER    "8CC43313-EDF8-4452-B5FC-F758A162E83E"

#endif