/*
 * LX stopwatch module
 *
 * Copyright 0000
 */
#ifndef LX_stopwatch_H
#define LX_stopwatch_H

typedef struct vt_ILxStopwatchService ** ILxStopwatchServiceID;
typedef struct vt_ILxStopwatch ** ILxStopwatchID;

	#include <lxcom.h>



/*
 * The script query method is required but unimplemented
 * 
 * Allocate a stopwatch with a unique identifier and return it.  If a new
 * stopwatch was allocated, this will return LXe_TRUE.  If the stopwatch was
 * already registered then LXe_FALSE is returned, and the ILxStopwatch returned
 * is simply an add-ref'd copy of the existing one.
 */
typedef struct vt_ILxStopwatchService {
	ILxUnknown	 iunk;
	LXxMETHOD(  LxResult,
ScriptQuery) (
	LXtObjectID		 self,
	void		       **ppvObj);
	LXxMETHOD( LxResult,
Allocate) (
	LXtObjectID			 self,
	const char			*ident,
	void				**ppvObj);
} ILxStopwatchService;

/*
 * Start the stopwatch.  If \p startChildren is true,
 * all of the stopwatch's children will be started as well.
 * Stop the stopwatch. If \p stopChildren is true,
 * all of the stopwatch's children will be stopped as well.
 * 
 * Reset the stopwatch.  If \p resetChildren is true,
 * all of the stopwatch's children will be reset as well.
 * 
 * Get the current time for the stopwatch. If \p incChildren is true,
 * this is the sum of the stopwatch's time and that of all its children.
 * 
 * Check if the stopwatch is currently running.  Note this will return
 * 0 (false) if the stopwatch is inactive or if it doesn't exist at all.
 * 
 * Read the stopwatch's identifier
 * 
 * Child stopwatchs can be added to an existing stopwatch.  Note that the parent stopwatch
 * will hold a reference to the child, and the child will be referenced again by
 * the caller of the function.
 * 
 * Child stopwatchs can also be removed by ident if needed.
 * 
 * Return the number of child stopwatchs this stopwatch has.
 * 
 * Return the ILxStopwatchID for a child stopwatch by index.
 * 
 * Stopwatchs can also be printed to the event log.
 */
typedef struct vt_ILxStopwatch {
	ILxUnknown	 iunk;
	LXxMETHOD( LxResult,
Start) (
	LXtObjectID	 self,
	int		 startChildren);
	LXxMETHOD( LxResult,
Stop) (
	LXtObjectID	 self,
	int		 stopChildren);
	LXxMETHOD( LxResult,
Reset) (
	LXtObjectID	 self,
	int		 resetChildren);
	LXxMETHOD( LxResult,
Time) (
	LXtObjectID	 self,
	int		 includeChildren,
	int		*time);
	LXxMETHOD( int,
IsActive) (
	LXtObjectID	 self);
	LXxMETHOD( void,
Identifier) (
	LXtObjectID	 self,
	const char 	**ident);
	LXxMETHOD( LxResult,
AddChildStopwatch) (
	LXtObjectID	 self,
	const char	*ident,
	void		**ppvObj);
	LXxMETHOD( LxResult,
RemoveChildStopwatch) (
	LXtObjectID	 self,
	const char	*ident);
	LXxMETHOD( int,
ChildCount) (
	LXtObjectID	 self);
	LXxMETHOD( LxResult,
ChildByIndex) (
	LXtObjectID	 self,
	int		 index,
	void		**ppvObj);
	LXxMETHOD( void,
LogOutput) (
	LXtObjectID	 self);
} ILxStopwatch;

/*
 * The Stopwatch Service provides methods for accessing named stopwatchs.
 */

	#define LXu_STOPWATCHSERVICE	 "87E96FE9-FA5C-4C74-AC42-0317FFE38D59"
	
	// [python] ILxStopwatchService:Allocate	obj Stopwatch

/*
 * Stopwatchs are simple objects which can be created and accessed by any client.
 */

	#define LXu_STOPWATCH	"237FC39A-1B46-4392-AE72-CD787FA592C9"

	// [export]  ILxStopwatch
	// [local]   ILxStopwatch

#endif