/*
 * LX anim module
 *
 * Copyright 0000
 */
#ifndef LX_anim_H
#define LX_anim_H

typedef struct vt_ILxAnimListener ** ILxAnimListenerID;

	#include <lxcom.h>
	#include <lxvalue.h>
	#include <lxidef.h>



/*
 * 
 * 
 * 
 * 
 */
typedef struct vt_ILxAnimListener {
	ILxUnknown	 iunk;
	LXxMETHOD(  LxResult,
TimeChange) (
	LXtObjectID		  self);
	LXxMETHOD(  LxResult,
PlayStart) (
	LXtObjectID		  self);
	LXxMETHOD(  LxResult,
PlayEnd) (
	LXtObjectID		  self);
	LXxMETHOD(  LxResult,
ScrubTime) (
	LXtObjectID		  self);
	LXxMETHOD(  LxResult,
ScrubEnd) (
	LXtObjectID		  self);
	LXxMETHOD(  LxResult,
EnterSetup) (
	LXtObjectID		  self);
	LXxMETHOD(  LxResult,
LeaveSetup) (
	LXtObjectID		  self);
} ILxAnimListener;


	#define LXu_ANIMLISTENER	"4A0862DA-CAC6-48EC-A3DA-DE285FE528B5"
	#define LXa_ANIMLISTENER	"animlistener"
	#define LXi_PTAG_EXEC_NME       LXxID4('E','X','E','N')
	// [local]  ILxAnimListener
	// [export] ILxAnimListener	 animEvent

#endif