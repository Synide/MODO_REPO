/*
 * LX customview module
 *
 * Copyright 0000
 */
#ifndef LX_customview_H
#define LX_customview_H

typedef struct vt_ILxCustomPane ** ILxCustomPaneID;
typedef struct vt_ILxCustomView ** ILxCustomViewID;
typedef struct vt_ILxCustomView1 ** ILxCustomView1ID;

	#include <lxserver.h>
	#include <lxvalue.h>

/*
 * This interface defines a CustomView client, which is able to use Python calls (or whatever) to
 * populate a Custom-based interface.
 */

      typedef void*    LXtPaneHandleID;



/*
 * Returns the parent window handle for the custom pane, which can be used to parent any user generated
 * UI. In Python this will be returned as an int representing a pointer, and will need to be converted into a proper
 * PyObject.
 * 
 * Returns the unique identifier for the instance of the CustomPane. This is useful for storing state for the particular
 * instance of the pane in the config, for example.
 */
typedef struct vt_ILxCustomPane {
	ILxUnknown	 iunk;
	LXxMETHOD(  LxResult,
GetParent) (
	LXtObjectID		 self,
	LXtPaneHandleID		*handle );
	LXxMETHOD( LxResult,
GetIdentifier) (
	LXtObjectID		 self,
	const char**		 ident );
} ILxCustomPane;

/*
 * - TYPE
 * This tag consists of four space-delimited strings:
 * - The class of the viewport, mostly for organizational purposes.  Options include:
 *    vp3dEdit, vptoolbars, vpproperties, vpdataLists, vpinfo, vpeditors, vputility, and vpapplication.
 * - Exactly four characters representing the viewport's type as an LXtID4.
 * - An internal string representing the viewport's type as a name.
 * - A message table lookup in the form of "@table@message@"
 * For example:  "vpapplication MYVP myViewportTypeName @myViewportTypeTable@myViewportTypeUsername@"
 * - EMBEDABILITY
 * Determines how the viewport can be embedded into a Form View.  There are three options:
 * - "normal", which is the default mode if this tag isn't set, indicates that the viewport doesn't
 *   specifically support embedding.  These can still be embedded via viewport presets, but they may
 *   not display properly.
 * - "embedAware", meaning that the viewport knows how to handle embedding.
 * - "embedOnly", meaning the viewport can only be embedded and cannot be used in normal layouts.
 * 
 * - EMBEDDED_ARGS
 * Embedded viewports can support arguments, which are presented in the Form Editor.  These are
 * stored in the form state and are passed to the EmbeddedArgumentSet() method when the embedded
 * viewport is instanced in a form.  These are not used in any other context, like putting the
 * viewport into a layout alongside other viewports.
 * 
 * The format for the embedded arguments tag is:
 * 
 * 	name:datatype=defaultValue name2:datatype=defaultValue
 * 
 * Each Argument starts with an internal name (which is also used as a key for the username lookup
 * in the message table), a colon, and the datatype of the argument (integer, float, boolean,
 * string, etc).  Complex datatypes (matrices, gradients, etc) are not supported.  Finally, an
 * equal sign and the default value for the argument are provided as a raw string without any units.
 * This means that distances must be in meters, angles in radians, etc.  Arguments are space-delimited.
 * 
 * - OPTIONS_FORM
 * A string representing the hash of a form to display when the user clicks the gear widget for
 * the viewport.
 * 
 * This is called to tell the server to set up as part of the widget with the name provided.
 * 
 * 
 * This is called to clean up the widget just before the view is torn down.
 * 
 * These methods are called to load or save any per-instance state for the pane provided.
 * 
 * 
 * Alternatively, a settings string can be provided that will be stored in the config for you,
 * and restored when the viewport is instanced.  This string must be ASCII text, most commonly
 * a simple string or JSON.  Note that these are currently stored in an XML config, and while
 * they will be sanitized care should be taken just the same.
 * 
 * Note that this is only available for custom views that define themselves as true viewport
 * types.
 * 
 * 
 * Just before a viewport is destroyed, this method is called to ask if it's allowed to be
 * destroyed.  Return LXe_FALSE will keep the 
 * 
 * Embedded viewports have a number of other options available to them.  These are only
 * valid when the TYPE server tag is set to create a first-class viewport.
 * 
 * Viewports that are marked as embedded can define arguments as part of their user tags.
 * When the viewport is instanced, One of these methods is called once for each argument
 * that is set, in the order they are defined in the server tag.
 * 
 * 
 * While many viewports may expand to fill the available space, some viewports have a
 * fixed height.  If implemented, the viewport will only take this much vertical space
 * in pixels when embedded.  Returning 0 or NOTIMPL will indicate that it should fill
 * the available space.  The current reserved width and height are provided for reference.
 * 
 * 
 * The label set in the form for this viewport.  The viewport can display it if it wants,
 * or ignore it.
 * 
 * 
 * While embedded viewport state may be loaded from configs, it will never be saved to it
 * through the normal store functions.  Instead, they use these functions to store and
 * restore a string with whatever format the viewport defines, although it should be kept
 * in mind that this will be stored in an XML file.
 * 
 */
typedef struct vt_ILxCustomView {
	ILxUnknown	 iunk;
	LXxMETHOD(  LxResult,
Init) (
	LXtObjectID		 self,
	LXtObjectID		 pane );
	LXxMETHOD(  LxResult,
Cleanup) (
	LXtObjectID		self,
	LXtObjectID		pane);
	LXxMETHOD(  LxResult,
StoreState) (
	LXtObjectID		 self,
	LXtObjectID		 pane );

	LXxMETHOD(  LxResult,
RestoreState) (
	LXtObjectID		 self,
	LXtObjectID		 pane );
	LXxMETHOD(  LxResult,
StoreSettingsString) (
	LXtObjectID		 self,
	char			*buf,
	unsigned int	 len);

	LXxMETHOD(  LxResult,
RestoreSettingsString) (
	LXtObjectID		 self,
	const char		*settings );
	LXxMETHOD(  LxResult,
EmbeddedArgumentSetInt) (
	LXtObjectID		 self,
	const char		*name,
	int			 value);

	LXxMETHOD(  LxResult,
EmbeddedArgumentSetFloat) (
	LXtObjectID		 self,
	const char		*name,
	double			 value);

	LXxMETHOD(  LxResult,
EmbeddedArgumentSetString) (
	LXtObjectID		 self,
	const char		*name,
	const char		*value);
	LXxMETHOD(  LxResult,
EmbeddedHeight) (
	LXtObjectID		 self,
	int			 width,
	int			 height,
	int			*fixedHeight);
	LXxMETHOD(  LxResult,
EmbeddedLabel) (
	LXtObjectID		 self,
	const char		*label);
	LXxMETHOD(  LxResult,
EmbeddedStoreSettingsString) (
	LXtObjectID		 self,
	char			*buf,
	unsigned int	 len);

	LXxMETHOD(  LxResult,
EmbeddedRestoreSettingsString) (
	LXtObjectID		 self,
	const char		*settings);
} ILxCustomView;

typedef struct vt_ILxCustomView1 {
	ILxUnknown	 iunk;
	LXxMETHOD(  LxResult,
Init) (
	LXtObjectID		 self,
	LXtObjectID		 pane );

	LXxMETHOD(  LxResult,
Cleanup) (
	LXtObjectID		self,
	LXtObjectID		pane);

	LXxMETHOD(  LxResult,
StoreState) (
	LXtObjectID		 self,
	LXtObjectID		 pane );

	LXxMETHOD(  LxResult,
RestoreState) (
	LXtObjectID		 self,
	LXtObjectID		 pane );
} ILxCustomView1;

/*
 * This interface is what is passed to the plugin and used to obtain the parent's pointer, among other
 * functionality.
 */

	#define LXu_CUSTOMPANE			"7412C685-3ED9-4622-915F-253105012BC4"
	#define LXa_CUSTOMPANE			"custompane"
	//[local] ILxCustomPane


	#define LXu_CUSTOMVIEW			"e9af4a0d-3048-4ec4-b802-aa7201dfdebe"
	#define LXa_CUSTOMVIEW			"customview"
	//[export] ILxCustomView customview
	//[local]  ILxCustomView
	//[python] type LXtPaneHandleID		id

/*
 * Servers are expected to expose tags that define their viewport type.  These allow them to show up as
 * "true" first-class viewports.  If the TYPE tag is not present, then they can still be instanced from
 * a Custom Viewport view's viewport options.
 */

	#define LXsCUSTOMVIEW_TYPE		"CustomViewType"
	#define LXsCUSTOMVIEW_EMBEDABILITY	"CustomViewEmbedability"
	#define LXsCUSTOMVIEW_EMBEDDED_ARGS	"CustomViewEmbeddedArgs"
	#define LXsCUSTOMVIEW_OPTIONS_FORM	"CustomViewOptionsForm"

/*
 * ILxCustomView1, retired as of 16.1.
 * 
 */

	#define LXu_CUSTOMVIEW1		"b427f640-821a-48ee-b7ec-f4aafe799695"
	//[export] ILxCustomView1 customview1
	//[local]  ILxCustomView1

#endif