/*
 * LX valuehud module
 *
 * Copyright 0000
 */
#ifndef LX_valuehud_H
#define LX_valuehud_H

typedef struct vt_ILxValueHUDService ** ILxValueHUDServiceID;


/*
 * As with all globals, the first method gets the ILxScriptQueryID interface for
 * the system.  This needs to exist, but in this case it isn't implemented.
 * 
 * Adding commands to the HUD first requires passing a cookie.  This is an arbitrary client-defined
 * string that is used to clear the HUD when it is no longer needed.  Note that he HUD is automatically
 * cleared after a timeout, but if the client wants to clear it early, it can ask it to do so with
 * its cookie.  Passing a NULL or empty string is allowed, but it means you have no way to manually
 * clear the HUD if you need to later.
 * 
 * Up to three commands can be added to the value HUD.  These commands will replace any used by the
 * HUD, and will appear in the order provided.  Any of the commands can be NULL or an empty string
 * to skip them.
 * 
 * If alphaSort is true, the HUD controls will be sorted by their command's button name (label) instead
 * of showing them in the order they were added.
 * 
 * 
 * This will clear the HUD, but only if the cookie string matches the most recent call to SetHUDCommands.
 * This keeps misbehaving clients from clearing other client's commands that may still be in use.
 * 
 */
typedef struct vt_ILxValueHUDService {
	ILxUnknown	 iunk;
	LXxMETHOD(  LxResult,
ScriptQuery) (
	LXtObjectID		 self,
	void		       **ppvObj);
	LXxMETHOD(  LxResult,
SetHUDCommands) (
	LXtObjectID		 self,
	const char		*cookie,
	const char		*command1,
	const char		*command2,
	const char		*command3,
	int			 alphaSort);
	LXxMETHOD(  LxResult,
ClearHUD) (
	LXtObjectID		 self,
	const char		*cookie);
} ILxValueHUDService;

/*
 * ILxValueHUDService
 * OmniHaul introduced the ValueHUD, a series of one to three buttons that appear at the bottom
 * of the 3D view while hauling.  These show the current value of the axis being hauled with that
 * button, and the user can click on a button to directly edit the value, or drag on the button
 * itself to change the value.  The HUD automatically fades out after a few seconds of inactivity.
 * 
 * The ValueHUDService provides an API to allow any client to instance these buttons in the
 * current 3D view.  Up to three command strings with integer or float arguments can be provided,
 * and they will automatically be queried and their values and labels displayed in the HUD.  The
 * commands' notifiers will be monitored and automatically update the value as it changes.  The
 * HUD will automatically disappear if the notifier doesn't request updates after enough time.
 * 
 */

	#define LXu_VALUEHUDSERVICE			"7ed5ebf7-578c-4cf6-98e7-2e0af53e56fa"
	#define LXa_VALUEHUDSERVICE			"valuehudservice"
	// [local]  ILxValueHUD
	// [export] ILxViewport vp
	// [python] type LXtQWidgetHandleID	id

#endif