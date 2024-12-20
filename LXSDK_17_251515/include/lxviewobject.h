/*
 * LX viewobject module
 *
 * Copyright 0000
 */
#ifndef LX_viewobject_H
#define LX_viewobject_H

typedef struct vt_ILxViewObject ** ILxViewObjectID;

#include <cstdint>
#include <vector>



/*
 * The TestMode function is used to test if a draw pass type is available. It is
 * called with a single type, such as BBox or Surface. If the function returns
 * LXe_TRUE, it has been generated and is available. If the function returns
 * LXe_FALSE, the Generate function should be called to generate that data. The
 * function can also return LXe_NOTREADY to specify that the ViewObject is working
 * on generating the data in a thread, or LXe_NOTAVAILABLE if the requested data is
 * not supported.
 * The TestModeSet function is used to test if a draw pass types are available. It is
 * called with a list of types, such as BBox and/or Surface. If the function returns
 * LXe_TRUE, all pass types have been generated and are available. If the function returns
 * LXe_FALSE, the Generate function should be called to generate that data. The
 * function can also return LXe_NOTREADY to specify that the ViewObject is working
 * on generating the data in a thread, or LXe_NOTAVAILABLE if the requested data is
 * not supported.
 * 
 * The Flags method allows the ViewObject to declare some properties that determine
 * how it should be evaluated.
 * 
 * If the TestMode function has declared that work needs to be done to generate
 * the ViewObject data, the Generate function will be called. It is expected to
 * generate new draw passes of the requested type. This function may be called from
 * threads if that is supported.
 * 
 * 
 * In cases where the source data may change between generation of
 * view object types, and a set of types may require the same source data,
 * a set of types can all be generated together.
 * 
 * The Count method is expected to return the number of available draw passes of
 * the requested type.
 * 
 * The ByIndex method is expected to return draw passes by index of the requested
 * type.
 * 
 * ViewObjects whose hierarchy of view objects should only refresh when
 * all members are generated can also implement this function to return
 * the root view object.
 */
typedef struct vt_ILxViewObject {
	ILxUnknown	 iunk;
	LXxMETHOD( LxResult,
TestMode) (
	LXtObjectID		  self,
	unsigned int		  type);
	LXxMETHOD( LxResult,
TestModeSet) (
	LXtObjectID 		self,
	const unsigned int* 	passTypes,
	unsigned int 		passTypeCount);
	LXxMETHOD( unsigned int,
Flags) (
	LXtObjectID		  self);
	LXxMETHOD( void,
Generate) (
	LXtObjectID		  self,
	unsigned int		  type);
	LXxMETHOD( void,
GenerateSet) (
	LXtObjectID		  self,
	const unsigned int*	  types,
	unsigned int		  typeCount);
	LXxMETHOD( unsigned int,
Count) (
	LXtObjectID		  self,
	unsigned int		  type);
	LXxMETHOD( LxResult,
ByIndex) (
	LXtObjectID		  self,
	unsigned int		  type,
	unsigned int		  index,
	void			**ppvObj);
	LXxMETHOD( LxResult,
Root) (
	LXtObjectID		  self,
	void			**ppvObj);
} ILxViewObject;

/*
 * The ILxViewObject is used to generate passes that are used for drawing. It is
 * usually generated by a modifier attached to an item that wishes to draw. At draw
 * time, the passes (also ILxViewObjects) are generated and passed to the drawing
 * loop.
 */

	#define	LXu_VIEWOBJECT			"81C986D1-A7BA-4278-B060-E784779F5C36"
	#define LXa_VIEWOBJECT			"viewobject"
	// [local] ILxViewObject
	// [export] ILxViewObject		viewobj
	// [python] ILxViewObject:ByIndex	obj ViewObject
	// [python] ILxViewObject:ByView	obj ViewObject
	// [default] ILxViewObject:TestMode = LXe_NOTAVAILABLE
	// [default] ILxViewObject:Flags = 0
	// [default] ILxViewObject:Count = 0
	// [enum] EViewObjectPass

/*
 * View object passes represent collections of gl buffers used to draw in a particular
 * style based on viewport options and performance requirements. Some of the passes
 * may have overlap in which buffers are required, and some may not be relevant depending
 * on the data the view object wraps.
 * LXiVIEWPASS_BBOX - The bounding box of the view object.
 * LXiVIEWPASS_VERTICES - The point positions and indices.
 * LXiVIEWPASS_CURVES - Curve geometry to be rendered as lines.
 * LXiVIEWPASS_WIREFRAME - Polygonal wireframes to be rendered as lines.
 * LXiVIEWPASS_SUBDIVISION_CAGE - The wireframes of the control polygons for a subdivision surface.
 * LXiVIEWPASS_SUBDIVISION_GUIDES - The vector from the limit surface to control cage for a subdivision surface.
 * LXiVIEWPASS_COLOR - A supplementary vertex color buffer to be overlaid on the GL Surface.
 * LXiVIEWPASS_SURFACE_UNDISPLACED - The triangle surface of the view object, without displacements affecting the position buffer.
 * LXiVIEWPASS_SURFACE - The triangle surface, with displaced positions as dictated by the texturing.
 * LXiVIEWPASS_SURFACE_INVERTED - The triangle surface with an inverted normal buffer.
 * LXiVIEWPASS_SURFACE_FACETED - The triangle surface with an unsmoothed normal buffer.
 * LXiVIEWPASS_MAP_VECTOR - Vectors from the surface vertices, typically based on a selected vertex map.
 * LXiVIEWPASS_MAP_EDGES - User defined set of edges, typically a UV Seam or Edge Pick map.
 * LXiVIEWPASS_BOUNDS_UVMAP - Boundary edges of a UV map.
 * LXiVIEWPASS_BOUNDS_GEOMETRY - Boundary edges of the surface geometry.
 * LXiVIEWPASS_PROCEDURAL_SELECTION - Procedural selection
 * LXiVIEWPASS_PROCEDURAL_OUTLINE - Procedural outline
 * 
 */

enum EViewObjectPass : unsigned {
	LXiVIEWPASS_BBOX,
	LXiVIEWPASS_VERTICES,
	LXiVIEWPASS_CURVES,
	LXiVIEWPASS_WIREFRAME,
	LXiVIEWPASS_SUBDIVISION_CAGE,
	LXiVIEWPASS_SUBDIVISION_GUIDES,
	LXiVIEWPASS_COLOR,
	LXiVIEWPASS_UNDISPLACED,
	LXiVIEWPASS_SURFACE,
	LXiVIEWPASS_SURFACE_INVERTED,
	LXiVIEWPASS_SURFACE_FACETED,
	LXiVIEWPASS_MAP_VECTOR,
	LXiVIEWPASS_MAP_EDGES,
	LXiVIEWPASS_BOUNDS_UVMAP,
	LXiVIEWPASS_BOUNDS_GEOMETRY,
	LXiVIEWPASS_PROCEDURAL_SELECTION,
	LXiVIEWPASS_PROCEDURAL_OUTLINE,
	LXiVIEWPASS_COUNT
};

/*
 * The ViewObject data will be generated in the main thread.
 */

	#define	LXfVIEWOBJECT_NOTHREADS		0x01

/*
 * Items declare that they can provide a ViewObject with a package server tag giving
 * the name of the channel that contains the ILxViewObject. Read in an evaluated
 * context, this will be a ValueReference object channel holding the ILxViewObject.
 */

	#define LXsPKG_VIEWOBJECT_CHANNEL	"viewObject.channel"

#endif