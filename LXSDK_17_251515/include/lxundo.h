/*
 * LX undo module
 *
 * Copyright 0000
 */
#ifndef LX_undo_H
#define LX_undo_H

typedef struct vt_ILxUndo ** ILxUndoID;
typedef struct vt_ILxUndoService ** ILxUndoServiceID;

	#include <lxvalue.h>



/*
 * Plug-ins can participate in the undo stack by creating objects with an
 * ILxUndo interface.  These objects are stored in the undo stack and their
 * Forward() method is called to apply them or redo them, and their Reverse()
 * method is called to undo them.
 * These undo objects should perform changes to the internal plug-in state
 * only, not the application system state.  Application state changes are made
 * with commands which undo themselves.  Also note that the state change
 * methods have no error return codes and cannot fail. Any chance of failure must
 * have been dealt with before they were added to the undo stack.
 */
typedef struct vt_ILxUndo {
	ILxUnknown	 iunk;
	LXxMETHOD(  void,
Forward) (
	LXtObjectID		 self);

	LXxMETHOD(  void,
Reverse) (
	LXtObjectID		 self);
} ILxUndo;

/*
 * The global undo service provides the ScriptQuery() method as required
 * from all globals.
 * The global undo service allows clients to add their actions to the undo
 * state.  The state can be queried at any time and may have one of three
 * values.
 * - INVALID
 * the undo system is not accepting undo objects, and any system state
 * changes at this point are not generally valid.
 * 
 * - ACTIVE
 * new undo objects can be added and will become part of the undo state.
 * 
 * - SUSPEND
 * state changes can be done, but they will not be directly undoable.
 * 
 * 
 * Undo objects are added to the system using these next two methods.  The
 * undo object passed in will be queried for it's ILxUndo interface and that
 * will be held by the undo system.
 * - Apply()
 * this takes the undo object and fires its Forward() method to apply it to
 * the current system state.  If the undo state is ACTIVE the change will be
 * added to the undo stack, and if it's SUSPEND the undo action will be
 * released.
 * 
 * - Record()
 * this takes an undo object and adds it to the undo stack.  This is used
 * for changes which have already happened, so the Reverse() method will be
 * fired only if there is an undo.
 * 
 */
typedef struct vt_ILxUndoService {
	ILxUnknown	 iunk;
	LXxMETHOD(  LxResult,
ScriptQuery) (
	LXtObjectID		 self,
	void		       **ppvObj);
	LXxMETHOD(  unsigned int,
State) (
	LXtObjectID		 self);
	LXxMETHOD(  LxResult,
Apply) (
	LXtObjectID		 self,
	LXtObjectID		 undo);

	LXxMETHOD(  LxResult,
Record) (
	LXtObjectID		 self,
	LXtObjectID		 undo);
} ILxUndoService;


	#define LXu_UNDO		"17FF7DDF-6F9B-47F1-8335-57A41DB3D3AD"
	// [local]  ILxUndo
	// [export] ILxUndo undo


	#define LXiUNDO_INVALID	 0
	#define LXiUNDO_ACTIVE	 1
	#define LXiUNDO_SUSPEND	 2


	#define LXu_UNDOSERVICE		"D8CA1EC8-F6A0-463E-AB82-9478A281B2CB"

#endif