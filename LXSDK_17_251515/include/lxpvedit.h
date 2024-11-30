/*
 * LX pvedit module
 *
 * Copyright 0000
 */
#ifndef LX_pvedit_H
#define LX_pvedit_H

typedef struct vt_ILxPolygonSlice ** ILxPolygonSliceID;
typedef struct vt_ILxSolidDrill ** ILxSolidDrillID;
typedef struct vt_ILxPolygonEdit ** ILxPolygonEditID;

	#include <lxcom.h>
	#include <lxmesh.h>



/*
 * Set the polygon slicing plane.  This can be set at any time, but must be
 * set before any knives are applied.
 * 
 * Initialize the slice data for the given polygon.  This decomposes the
 * polygon into edges and is ready for knife action.  If "setAxis" is true,
 * the slice axis will be set based on the polygon.
 * 
 * Cut the polygon by the line segment given by two positions.
 * 
 * Complete the slicing of a polygon.  This will either leave the polygon
 * unmarked if it was untouched by any knife, or it will leave the polygon
 * marked for deletion and create a set of new polygons to replace the
 * old, after having been sliced by all the knives.
 * 
 */
typedef struct vt_ILxPolygonSlice {
	ILxUnknown	 iunk;
	LXxMETHOD(  LxResult,
SetAxis) (
	LXtObjectID		 self,
	unsigned		 axis);
	LXxMETHOD(  LxResult,
SetAxisByVector) (
	LXtObjectID		 self,
	const LXtVector		 axis);
	LXxMETHOD(  LxResult,
Start) (
	LXtObjectID		 self,
	LXtObjectID		 meshObj,
	LXtPolygonID		 pol,
	unsigned		 setAxis);
	LXxMETHOD(  LxResult,
ByLine) (
	LXtObjectID		 self,
	const LXtVector		 pos0,
	const LXtVector		 pos1);
	LXxMETHOD(  int,
Done) (
	LXtObjectID		 self);
} ILxPolygonSlice;

/*
 * This object provides the interface to access internal solid drill and CSG
 * boolean functions.
 * 
 * Clear the solid drill context.
 * 
 * Add a mesh to drill the edit mesh. The xfrm is the matrix to convert the
 * vertex positions in the driver mesh to the local space for the edit mesh.
 * If the space of driver mesh is same as the edit mesh, "xfrm" can be null.
 * The solid drill uses only FACE polygons and the mesh shape must be closed.
 * This must be called in the main thread.
 * 
 * Execute the given operation to the edit mesh by added driver meshes. The
 * operation modes are exact same as options from solid drill and CSG boolean
 * commands. "sten" is a string for STENCIL mode.  This must be called in the 
 * main thread.
 * 
 * Unify multiple driver meshes and polygon parts in driver mesh.
 * If 'solid' is enabled, only closed poygon groups will be unified.
 * 
 * Union all meshes in drivers list into new mesh. If 'sset' is set,
 * intersecting edges are saved in the edge selection set.
 */
typedef struct vt_ILxSolidDrill {
	ILxUnknown	 iunk;
	LXxMETHOD(  LxResult,
Clear) (
	LXtObjectID		 self);
	LXxMETHOD(  LxResult,
AddMesh) (
	LXtObjectID		 self,
	LXtObjectID		 meshObj,
	const LXtMatrix4	 xfrm);
	LXxMETHOD(  LxResult,
Execute) (
	LXtObjectID		 self,
	LXtObjectID		 meshObj,
	const LXtMatrix4	 xfrm,
	LXtMarkMode		 pick,
	unsigned int		 mode,
	const char		*sten,
	LXtObjectID		 monitor);
	LXxMETHOD(  LxResult,
UnifyDrivers) (
	LXtObjectID		 self,
	bool			 solid);
	LXxMETHOD(  LxResult,
UnionAll) (
	LXtObjectID		 self,
	const LXtMatrix4	 xfrm,
	LXtMarkMode		 pick,
	const char		*sset,
	void		       **ppvObj);
} ILxSolidDrill;

/*
 * Set the mesh to edit and base mesh.
 * Set the current polygon to that given.This is used in new vertex creation
 * functions to interpolate discontinous vetex values.
 * 
 * Compare vertices with bounding box and move the ones within consideration
 * range to the vertex table and turn searching on.  If the bounding
 * box pointer is NULL, searching will be turned off.
 * 
 * The search mode can also be activated without a box, in which case all
 * existing new data will be marked for search. 
 * 
 * Set the current polygon to that given and sort the vertex lists
 * based on this polygon's bounding box.  We also set the search box
 * if search is requested and the test axis, for the client's
 * convenience. If search is "2", this sets existing vertices in the
 * polygon to the cache.
 * 
 * 
 * This creates a new vertex in the edit mesh at the given position. If there is
 * the LXtPointID which has same location (based on the vertex table tolerance) in the
 * newly created LXtPointID list, return the existing LXtPointID.
 * 
 * Find a vertex with the given position in the cache list.
 * 
 * Return new a vertex at the given position.  No searching is done, and the
 * vertex is not added to the search set, but it's quicker for vertices that
 * will never be shared.
 * 
 * Return a vertex at the given position which is a copy of an existing vertex.
 * 
 * Return a vertex at the given position which is a copy of an existing vertex of the polygon.
 * 
 * Return a vertex partway between the two given.	This is a very complex
 * function which not only performs positional interpolation between the
 * different morphs of the two vertices, but also interpolates the other
 * vmap vectors based on the division.  If 'pos' is null then default linear 
 * interpolation is done on position.
 * 
 * Return a vertex partway between the two given.	This is a very complex
 * function which not only performs positional interpolation between the
 * different morphs of the two vertices, but also interpolates the other
 * vmap vectors based on the division.  If the midpoint callback is null
 * then default linear interpolation is done on position.
 * 
 * Return a vertex at the given position which is a copy of an existing vertex.
 * 
 * This function edits the given polygon to renew the vertex list. It returns the
 * edit polygon.
 * 
 * This function edits the given polygon to renew the vertex list. It returns the
 * edit polygon.
 * 
 * This function deletes the polygon with calling Visitor.
 * 
 * This function removes marked edges.
 * 
 * These functions generates a set of polygons from an edge fragment contour by unwrapping 
 * minimal connected units. This is used in many mesh edtting tools (axis and solid drill,
 * boolean, slice tool and etc..) to rebuild sliced polygons. The initial edge list is set 
 * from 'polygonID' when 'polygonID' is set.
 * 
 * This adds an edge fragment to the current edge list. If 'both' is true, edge is added
 * as inner edge with both direction, otherwise the edge is added as contour edge with 
 * single direction.
 * 
 * 
 * Extracts the edge list to polygons into the current edit mesh. It sets number of new
 * polygons. The 'axis' is to define the plane to project vertex positions.
 * 
 * This function sets a new polygon for the given index.
 */
typedef struct vt_ILxPolygonEdit {
	ILxUnknown	 iunk;
	LXxMETHOD(  LxResult,
SetMesh) (
	LXtObjectID		 self,
	LXtObjectID		 meshObj,
	LXtObjectID		 baseObj);
	LXxMETHOD(  LxResult,
SetPolygon) (
	LXtObjectID		 self,
	LXtObjectID		 meshObj,
	LXtPolygonID		 polygonID);
	LXxMETHOD(  LxResult,
SetSearchBox) (
	LXtObjectID		 self,
	const LXtBBox		*box,
	double			 tol);
	LXxMETHOD(  LxResult,
SetSearch) (
	LXtObjectID		 self,
	int			 search,
	double			 tol);
	LXxMETHOD(  LxResult,
SetSearchPolygon) (
	LXtObjectID		 self,
	LXtPolygonID		 polygonID,
	bool			 search);
	LXxMETHOD(  LxResult,
ClearSearch) (
	LXtObjectID		 self);
	LXxMETHOD(  LxResult,
NewVertex) (
	LXtObjectID		 self,
	const LXtVector		 pos,
	LXtPointID		*pointID);
	LXxMETHOD(  LxResult,
FindVertex) (
	LXtObjectID		 self,
	const LXtVector		 pos,
	LXtPointID		*pointID);
	LXxMETHOD(  LxResult,
NewLoneVertex) (
	LXtObjectID		 self,
	const LXtVector		 pos,
	LXtPointID		*pointID);
	LXxMETHOD(  LxResult,
CopyVertex) (
	LXtObjectID		 self,
	LXtPointID		 sourceID,
	const LXtVector		 pos,
	LXtPointID		*pointID);
	LXxMETHOD(  LxResult,
CopyVrtOfPol) (
	LXtObjectID		 self,
	LXtPointID		 sourceID,
	LXtPolygonID		 polygonID,
	const LXtVector		 pos,
	LXtPointID		*pointID);
	LXxMETHOD(  LxResult,
AddMiddleVertex) (
	LXtObjectID		 self,
	const LXtVector		 pos,
	LXtPointID		 v1,
	LXtPointID		 v2,
	double			 f,
	LXtPointID		*pointID);
	LXxMETHOD(  LxResult,
AddFaceVertex) (
	LXtObjectID		 self,
	const LXtVector		 pos,
	LXtPolygonID		 polygonID,
	const double		*vwt,
	LXtPointID		*pointID);
	LXxMETHOD(  LxResult,
CopyPolygon) (
	LXtObjectID		 self,
	LXtObjectID		 meshObj,
	LXtPolygonID		 sourceID,
	unsigned int		 rev,
	LXtPolygonID		*polygonID);
	LXxMETHOD(  LxResult,
RenewVList) (
	LXtObjectID		 self,
	LXtPolygonID		 sourceID,
	unsigned int		 nvert,
	const LXtPointID	*verts,
	unsigned int		 rev,
	LXtPolygonID		*polygonID);
	LXxMETHOD(  LxResult,
NewPolygon) (
	LXtObjectID		 self,
	LXtID4			 type,
	unsigned int		 nvert,
	const LXtPointID	*verts,
	unsigned int		 rev,
	LXtPolygonID		*polygonID);
	LXxMETHOD(  LxResult,
DeletePolygon) (
	LXtObjectID		 self,
	LXtPolygonID		 polygonID);
	LXxMETHOD(  LxResult,
RemoveEdges) (
	LXtObjectID		 self,
	LXtMarkMode		 pick,
	bool			 keepVertices);
	LXxMETHOD(  LxResult,
UnwrapStart) (
	LXtObjectID		 self,
	LXtPolygonID		 polygonID);
	LXxMETHOD(  LxResult,
UnwrapAddEdge) (
	LXtObjectID		 self,
	LXtPointID		 v0,
	LXtPointID		 v1,
	bool			 both);
	LXxMETHOD(  LxResult,
UnwrapDone) (
	LXtObjectID		 self,
	const LXtVector		 axis,
	unsigned int		*npol);
	LXxMETHOD(  LxResult,
UnwrapPolygonByIndex) (
	LXtObjectID		 self,
	unsigned int		 index,
	LXtPolygonID		*polygonID);
} ILxPolygonEdit;


	#define LXa_POLYGONSLICE	"polygonSlice"
	#define LXu_POLYGONSLICE	"99C623EE-0873-4DB5-90DF-CC9460DA8FA8"

	// [local]  ILxPolygonSlice
	// [python] type LXtPolygonID id


	#define LXi_SDRILLv_CORE		 0
	#define LXi_SDRILLv_TUNNEL		 1
	#define LXi_SDRILLv_STENCIL		 2
	#define LXi_SDRILLv_NONE		 3

	#define LXi_SDRILLv_CSG_UNION		 4
	#define LXi_SDRILLv_CSG_INTERSECT	 5
	#define LXi_SDRILLv_CSG_SUBTRACT	 6
	#define LXi_SDRILLv_CSG_ADD		 7


	#define LXa_SOLIDDRILL	"solidDrill"
	#define LXu_SOLIDDRILL	"0D6D30C6-0DEB-4848-A9F9-731472255BA9"

	// [local]  ILxSolidDrill
	// [python] type LXtMarkMode unsigned


	#define LXa_POLYGONEDIT	"polygonEdit"
	#define LXu_POLYGONEDIT	"3EA0362E-61B6-4BFE-A98B-CE72221FC96B"

	// [local]  ILxPolygonEdit
	// [python] type LXtMarkMode unsigned

#endif