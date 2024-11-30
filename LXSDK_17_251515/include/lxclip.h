/*
 * LX clip module
 *
 * Copyright 0000
 */
#ifndef LX_clip_H
#define LX_clip_H

typedef struct vt_ILxVideoClipItem ** ILxVideoClipItemID;

	#include <lxcom.h>



/*
 * A video clip item presents a special interface to allow it to be a video
 * clip.
 * - PrepFilter
 * Given an ILxEvaluation interface, Add the channels needed to compute the
 * filter. Data can be cached in the cache pointer.
 * - AllocFilter
 * Allocate an ILxImageFilter object using the cache. Values for this item
 * can be read from the attributes.
 * 
 * - Cleanup
 * Delete the cache, if any.
 * 
 */
typedef struct vt_ILxVideoClipItem {
	ILxUnknown	 iunk;
	LXxMETHOD(  LxResult,
PrepFilter) (
	LXtObjectID		 self,
	LXtObjectID		 eval,
	void		       **cache);

	LXxMETHOD(  LxResult,
AllocFilter) (
	LXtObjectID		 self,
	LXtObjectID		 attr,
	void			*cache,
	void		       **ppvObj);

	LXxMETHOD(  void,
Cleanup) (
	LXtObjectID		 self,
	void			*cache);
} ILxVideoClipItem;


	#define LXu_VIDEOCLIPITEM	"340FD1AD-B576-4BC3-8B6F-7DF1F5C312FB"
	// [export] ILxVideoClipItem vclip
	// [local]  ILxVideoClipItem
	// [python] ILxVideoClipItem:AllocFilter	obj ImageFilter (image)

#endif