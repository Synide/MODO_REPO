/*
 * LX variation module
 *
 * Copyright 0000
 */
#ifndef LX_variation_H
#define LX_variation_H

typedef struct vt_ILxVariation ** ILxVariationID;
typedef struct vt_ILxVariationService ** ILxVariationServiceID;


/*
 * This method should return either LXe_TRUE or LXe_FALSE, indicating whether the
 * variation server supports the provided item.
 * 
 * Initialize is called to get the initial X and Y values to determine the start
 * position for the variation viewport. This allow the center thumbnail in the
 * viewport to correctly match the current state of the selected item.
 * 
 * The client should provide the min and max range of the X value and Y value. The
 * variation viewport will be limited to these bounds.
 * 
 * 
 * Given a specific X and Y value, the Thumb method is expected to return an
 * ILxImage that can be displayed in the variation viewport.
 * 
 * When the user double clicks on a variation in the variation viewer, this method
 * will be called. A undoable command should be used to apply the changes to the
 * scene.
 */
typedef struct vt_ILxVariation {
	ILxUnknown	 iunk;
	LXxMETHOD( LxResult,
TestItem) (
	LXtObjectID		 self,
	LXtObjectID		 item,
	LXtObjectID		 chanRead);
	LXxMETHOD( LxResult,
Initialize) (
	LXtObjectID		 self,
	double			*x,
	double			*y,
	LXtObjectID		 item,
	LXtObjectID		 chanRead);
	LXxMETHOD( LxResult,
RangeX) (
	LXtObjectID		 self,
	double			*min,
	double			*max);
	LXxMETHOD( LxResult,
RangeY) (
	LXtObjectID		 self,
	double			*min,
	double			*max);
	LXxMETHOD( LxResult,
Thumb) (
	LXtObjectID		 self,
	double			 x,
	double			 y,
	unsigned int		 size,
	LXtObjectID		 chanRead,
	void		       **ppvObj);
	LXxMETHOD( LxResult,
Do) (
	LXtObjectID		 self,
	double			 x,
	double			 y);
} ILxVariation;

/*
 * 
 * Items are tested to see if they support specific variations. The test result
 * may vary depending on the state of the item. If an item state changes, the
 * following function can be used to invalidate the cached test results for a
 * specific item, and cause it be retested against all variation servers.
 */
typedef struct vt_ILxVariationService {
	ILxUnknown	 iunk;
	LXxMETHOD(  LxResult,
ScriptQuery) (
	LXtObjectID		 self,
	void		       **ppvObj);
	LXxMETHOD( void,
InvalidateItem) (
	LXtObjectID		 self,
	LXtObjectID		 item);
} ILxVariationService;

/*
 * The ILxVariation interface provides a plugin architecture for implementing new
 * variation servers. The interface is provided with a channel read object, and it
 * is expected to return thumbnails that match a position in the grid of thumbnails.
 * The ILxVariation interface is also expected to apply the settings to the scene.
 */

	#define LXu_VARIATION			"9EEA0765-4008-426C-A550-88F6EB08B2E4"
	#define LXa_VARIATION			"variation"
	// [export] ILxVariation		 var
	// [local]  ILxVariation
	// [python] ILxVariation:TestItem	 bool


	#define LXu_VARIATIONSERVICE		"2BD9441B-C671-4F3C-9B02-45E9D750E80B"
	#define LXa_VARIATIONSERVICE		"variationservice"

#endif