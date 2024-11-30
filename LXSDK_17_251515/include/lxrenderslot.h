/*
 * LX renderslot module
 *
 * Copyright 0000
 */
#ifndef LX_renderslot_H
#define LX_renderslot_H

typedef struct vt_ILxRenderSlotService ** ILxRenderSlotServiceID;
typedef struct vt_ILxRenderSlot ** ILxRenderSlotID;
typedef struct vt_ILxRenderSlotPass ** ILxRenderSlotPassID;
typedef struct vt_ILxRenderSlotOutput ** ILxRenderSlotOutputID;
typedef struct vt_ILxRenderSlotListener ** ILxRenderSlotListenerID;
typedef struct vt_ILxRenderProgressListener ** ILxRenderProgressListenerID;
typedef struct vt_ILxRenderProgressPixel ** ILxRenderProgressPixelID;

	#include <lxvmath.h>



/*
 * As with all globals, the first method gets the ILxScriptQueryID interface for
 * the system.  This is not implemented for this service.
 * 
 * Before being used, the slot system must be initialized.  This will walk the list of
 * frame buffers on disk, and pull secondary information out of the config.  This only
 * needs to be called once per session, but can called multiple times without any side
 * effects.
 * 
 * This is implicitly called by methods like SlotCount(), so if you don't call it will
 * be called for you when needed, but this allows you to call it at the best time for
 * your client.
 * 
 * 
 * Get the maximum number of slots.  If an attempt is made to add a slot beyond the
 * maximum, the oldest slot is discarded.  Note that this is only render slots, and
 * loaded images do not count toward the maximum.
 * 
 * 
 * Walk the slot list, indirectly returning an ILxRenderSlotID.  Slots can also be
 * looked up by their ident, which is stored in the selection system.
 * 
 * 
 * This is called by render jobs to set up for a new render.  If we have hit max slots, this will reuse an
 * existing slot if necessary, deleting the oldest render slot.
 * 
 * If noImagegOpt is false (which usually comes from the job's flags), the progress image will be cleared.
 * 
 * passName is the name of the new pass in the slot. this will be used to find the background pass for
 * a limited region render within the currently selected slot.
 * 
 * This returns three integers:  the slot index that will be rendered into, and two integers for limited
 * region render representing the background slot index and the pass within that slot, which can be used
 * to find the background slot/pass for the current output to display behind a limited region render.
 * 
 * Note that if a render is already in progress, this will fail.
 * 
 * 
 * Once rendering has finished, this will reset the currently rendering state of the slot list, converting
 * the in-progress render slot into a rendered slot. If asAbort is true, this will flag the slot as an
 * aborted render.
 * 
 * 
 * If a render is currently in progress, this returns that slot.  If no rendering is in progress this
 * fails with NOTFOUND.
 * 
 * 
 * Find a slot by ident and remove it.  This just executes the renderslot.delete command, and will
 * ask the user to confirm that they want to delete the slot.  If you want to suppress the dialog,
 * execute the renderslot.delete command yourself through the command system.
 * 
 * 
 * Open a new file dialog and prompt user to pick an image to load
 * 
 * 
 * Load an image from a specified path.
 * 
 * 
 * Create a progress image from the frame buffer of a specific output.
 * This can be used to show the frame buffer after switching outputs.
 * WARNING: This is slow, prefer to do this work off the main thread.
 * 
 * If a render is currently in progress, this returns the pass being currently rendered.
 * If no rendering is in progress this fails with NOTFOUND.
 * 
 */
typedef struct vt_ILxRenderSlotService {
	ILxUnknown	 iunk;
	LXxMETHOD(  LxResult,
ScriptQuery) (
	LXtObjectID		 self,
	void		       **ppvObj);
	LXxMETHOD(  LxResult,
Initialize) (
	LXtObjectID		 self);
	LXxMETHOD(  int,
MaxSlots) (
	LXtObjectID		 self);
	LXxMETHOD(  LxResult,
SlotCount) (
	LXtObjectID		 self,
	int			*count);

	LXxMETHOD(  LxResult,
SlotByIndex) (
	LXtObjectID		  self,
	int			  index,
	void			**ppvObj);

	LXxMETHOD(  LxResult,
SlotLookupByIdent) (
	LXtObjectID		  self,
	int			  ident,
	void			**ppvObj);
	LXxMETHOD(  LxResult,
SetupSlotForNewRender) (
	LXtObjectID		 self,
	int			 noImageOpt,
	const char		*passName,
	int			*newSlotIndex,
	int			*limitedRegionBackgroundDiskSlot,
	int			*limitedRegionBackgroundPassIndex);
	LXxMETHOD(  LxResult,
ClearCurrentRenderSlot) (
	LXtObjectID		  self,
	bool			  asAbort);
	LXxMETHOD(  LxResult,
CurrentRenderSlot) (
	LXtObjectID		  self,
	void			**ppvObj);
	LXxMETHOD(  LxResult,
SlotRemoveByIdent) (
	LXtObjectID		self,
	int			ident);
	LXxMETHOD(  LxResult,
LoadImage) (
	LXtObjectID		self);
	LXxMETHOD(  LxResult,
LoadImageFromPath) (
	LXtObjectID		self,
	const char *filePath);
	LXxMETHOD(  LxResult,
WriteProgressImageForOutput) (
	LXtObjectID		  self,
	int				outputIdx,
	void		**ppvObj);
	LXxMETHOD(  LxResult,
CurrentRenderPass) (
	LXtObjectID		  self,
	void			**ppvObj);
} ILxRenderSlotService;

/*
 * Return the unique identifier of the slot.
 * 
 * 
 * Returns LXe_TRUE if this is the currently rendering slot.
 * 
 * 
 * Get or set the mapping as an integer from 0 to 9.  If unmapped, this returns LXe_NOTAVAILABLE.
 * 
 * 
 * 
 * Get the disk slot index of a frame buffer slot.  This ranges from 0 to max slots, and is
 * not necessarily the same as the index in the slot list.
 * 
 * 
 * Get or set the locked state of a render slot, which keeps it from being reused
 * when recycling old slots for a new render after max slots has been reached.
 * Returns LXe_TRUE if lcoked, and LXe_FALSE if unlocked.
 * 
 * 
 * Get the stats (ILxRenderStatsID) from a render slot.
 * 
 * 
 * For image slots, this returns the path to the image on disk.
 * 
 * 
 * Get the byte format for images as LXiIMG_ flags, as originally loaded from the file.
 * 
 * 
 * Returns LXe_TRUE if the image is actually an aborted render.
 * 
 * 
 * Walk the list of passes in a slot, which is returned indirectly as an ILxRenderSlotPassID.
 * Images loaded from disk will have one "pass" representing the image itself.  Passes can
 * also be looked up by name.
 * 
 * 
 * Get the "quick thumbnail" of the slot itself, which is just a thumbnail of teh first output of
 * the first pass of the slot.  This may be cached to disk.
 * 
 * 
 * Get the image source of the slot. This only applies to slots of type image.
 * 
 */
typedef struct vt_ILxRenderSlot {
	ILxUnknown	 iunk;
	LXxMETHOD(  LxResult,
Ident) (
	LXtObjectID		 self,
	int			*ident);
	LXxMETHOD(  LxResult,
Type) (
	LXtObjectID		 self,
	int			*type);
	LXxMETHOD(  LxResult,
IsRendering) (
	LXtObjectID		 self);
	LXxMETHOD(  LxResult,
Mapping) (
	LXtObjectID		 self,
	int			*mapping);

	LXxMETHOD(  LxResult,
SetMapping) (
	LXtObjectID		 self,
	int			 mapping);
	LXxMETHOD(  LxResult,
DiskSlotIndex) (
	LXtObjectID		 self,
	int			*index);
	LXxMETHOD(  LxResult,
IsLocked) (
	LXtObjectID		 self);

	LXxMETHOD(  LxResult,
SetIsLocked) (
	LXtObjectID		 self,
	int			 lock);
	LXxMETHOD(  LxResult,
Stats) (
	LXtObjectID		  self,
	void			**ppvObj);
	LXxMETHOD(  LxResult,
ImagePath) (
	LXtObjectID		 self,
	char			*buf,
	int			 len);
	LXxMETHOD(  LxResult,
ImageByteFormat) (
	LXtObjectID		 self,
	int			*format);
	LXxMETHOD(  LxResult,
IsAbortedRender) (
	LXtObjectID		 self);
	LXxMETHOD(  LxResult,
PassCount) (
	LXtObjectID		 self,
	int			*count);

	LXxMETHOD(  LxResult,
PassByIndex) (
	LXtObjectID		  self,
	int			  index,
	void			**ppvObj);

	LXxMETHOD(  LxResult,
PassLookupByName) (
	LXtObjectID		  self,
	const char		 *name,
	void			**ppvObj);
	LXxMETHOD(  LxResult,
QuickThumbnail) (
	LXtObjectID		self,
	void			**ppvObj);
	LXxMETHOD(  LxResult,
ImageSource) (
	LXtObjectID		self,
	void			**ppvObj);
} ILxRenderSlot;

/*
 * Return the name of the pass.  Note that not all passes have names, and this will fail if there
 * is no name.
 * 
 * Get the slot that this pass is a part of.
 * 
 * 
 * Get the index of the pass in the slot's pass list.
 * 
 * 
 * Returns LXe_TRUE if this pass is currently being rendered.  The frame buffer will
 * not be available and associated methods will return LXe_RENDER_IN_PROGRESS.
 * 
 * 
 * Get the frame buffer associated with the pass as an ILxFrameBufferID.  This returns
 * LXe_RENDER_IN_PROGRESS if currently rendering this slot, and the any image for display
 * needs to be pulled from the progress image.
 * 
 * 
 * Returns the result code from when the frame buffer was loaded.
 * 
 * 
 * Walk the list of outputs in a pass, which is returned indirectly as an ILxRenderSlotOutputID.
 * Images loaded from disk will have "outputs" representing the RGB and alpha.  Outputs can also
 * be looked up by name and type (LXiRENDEROUTPUT_)
 * 
 */
typedef struct vt_ILxRenderSlotPass {
	ILxUnknown	 iunk;
	LXxMETHOD(  LxResult,
Name) (
	LXtObjectID		 self,
	char			*buf,
	int			 len);
	LXxMETHOD(  LxResult,
Slot) (
	LXtObjectID		  self,
	void			**ppvObj);
	LXxMETHOD(  LxResult,
Index) (
	LXtObjectID		 self,
	int			*index);
	LXxMETHOD(  LxResult,
IsRendering) (
	LXtObjectID		 self);
	LXxMETHOD(  LxResult,
FrameBuffer) (
	LXtObjectID		  self,
	void			**ppvObj);
	LXxMETHOD(  LxResult,
FrameBufferLoadResult) (
	LXtObjectID		 self,
	int			*index);
	LXxMETHOD(  LxResult,
OutputCount) (
	LXtObjectID		 self,
	int			*count);

	LXxMETHOD(  LxResult,
OutputByIndex) (
	LXtObjectID		  self,
	int			  index,
	void			**ppvObj);

	LXxMETHOD(  LxResult,
OutputLookupByName) (
	LXtObjectID		  self,
	const char		 *name,
	void			**ppvObj);

	LXxMETHOD(  LxResult,
OutputLookupByType) (
	LXtObjectID		  self,
	int			  type,
	void			**ppvObj);
} ILxRenderSlotPass;

/*
 * Return the name of the output.
 * 
 * Get the pass that this output is a part of.
 * 
 * 
 * Return the type of the output as an LXiRENDEROUTPUT_ define (color, alpha, etc).
 * 
 * 
 * The index of the output in the pass.
 * 
 * 
 * Get a thumbnail of the output, if available, for use in popups, at 64 pixels tall.
 * A "raw" thumbnail is available at 256 pixels tall, and does not have any image
 * processing applied to it.
 * 
 * 
 * While this render pass is being rendered, a corrected thumbnail is available.
 * This will be at most 256x256.  This is updated periodically with the main
 * progress image, with update events avaialble from te progress listener.
 * 
 * 
 * Get the image processing object from the output, which will have an
 * ILxImageProcessing interface.
 * 
 * 
 * preferredFormat is the file format to save in by default, although he user can choose
 * a different format, if they so desire.
 * 
 */
typedef struct vt_ILxRenderSlotOutput {
	ILxUnknown	 iunk;
	LXxMETHOD(  LxResult,
Name) (
	LXtObjectID		 self,
	char			*buf,
	int			 len);
	LXxMETHOD(  LxResult,
Pass) (
	LXtObjectID		  self,
	void			**ppvObj);
	LXxMETHOD(  LxResult,
Type) (
	LXtObjectID		 self,
	int			*type);
	LXxMETHOD(  LxResult,
Index) (
	LXtObjectID		 self,
	int			*index);
	LXxMETHOD(  LxResult,
Thumbnail) (
	LXtObjectID		  self,
	void			**ppvObj);

	LXxMETHOD(  LxResult,
RawThumbnail) (
	LXtObjectID		  self,
	void			**ppvObj);
	LXxMETHOD(  LxResult,
InProgressThumbnail) (
	LXtObjectID		  self,
	void			**ppvObj);
	LXxMETHOD(  LxResult,
ImageProcessing) (
	LXtObjectID		  self,
	void			**ppvObj);
	LXxMETHOD(  LxResult,
SaveToImage) (
	LXtObjectID		 self,
	int			 saveOp,
	const char		*preferredFormat );
} ILxRenderSlotOutput;

/*
 * The list of slots has changed, meaning a slot was added or removed.
 * 
 * A slot was added to the slot list.
 * 
 * 
 * A slot is about to be removed from the slot list.
 * 
 * 
 * A slot was initialized as storage for a new rendering.  This is usually as a
 * result of a render job calling ILxRenderService::SetupSlotForNewRender().
 * 
 * 
 * The slot's thumbnail has been generated and is available.  This is for the
 * slot list itself, and is usually the RGB output.  A separate method is used
 * for when an output's thumbnail is updated.
 * 
 * 
 * Called when the locked state of a slot is changed.  Locked slots will not be
 * recycled when a out of slots and a new render starts.
 * 
 * 
 * Called when the mapping changes on a slot.  The mapping provides a quick way
 * to jump between slots with the keyboard.
 * 
 * 
 * Called when the stats object on the slot has changed to a new object.  This normally
 * happens on the slot currently being rendered at the beginning of rendering.
 * 
 */
typedef struct vt_ILxRenderSlotListener {
	ILxUnknown	 iunk;
	LXxMETHOD(  LxResult,
SlotListChanged) (
	LXtObjectID		 self);
	LXxMETHOD(  LxResult,
SlotAdded) (
	LXtObjectID		 self,
	LXtObjectID		 slot);
	LXxMETHOD(  LxResult,
SlotRemoved) (
	LXtObjectID		 self,
	LXtObjectID		 slot);
	LXxMETHOD(  LxResult,
RenderSlotInitialized) (
	LXtObjectID		 self,
	LXtObjectID		 slot);
	LXxMETHOD(  LxResult,
SlotThumbnailUpdated) (
	LXtObjectID		 self,
	LXtObjectID		 slot);

	LXxMETHOD(  LxResult,
OutputThumbnailUpdated) (
	LXtObjectID		 self,
	LXtObjectID		 output);
	LXxMETHOD(  LxResult,
SlotLockChanged) (
	LXtObjectID		 self,
	LXtObjectID		 slot,
	int			 newState);
	LXxMETHOD(  LxResult,
SlotMappingChanged) (
	LXtObjectID		 self,
	LXtObjectID		 slot,
	int			 newMapping);
	LXxMETHOD(  LxResult,
SlotStatsReset) (
	LXtObjectID		 self,
	LXtObjectID		 slot);
} ILxRenderSlotListener;

/*
 * While rendering, this is called with the current progress of the render
 * as a number between 0.0 and 1.0.  The render can be canceled by calling
 * ILxRenderService::Abort() from this method.
 * 
 * As the render progresses, this method is called with a status string,
 * which the client can display in its UI.  The first string provided is
 * an internal string, while the second is a user-readable, translated
 * string.  Note that an empty info string/user string is valid, and usually
 * just means that the any previous string can now be cleared as it is no
 * longer relevant.
 * 
 * The "render" lgo subsystem's rolling log message may also be used to read
 * progress strings.
 * 
 * 
 * Every time a pixel is rendered, the progress image (an object with the
 * ILxImageID interface) is updated.  This image is created when a frame
 * starts rendering, and is passed to the client through this method.  The
 * job can hold onto this image for redrawing by incrementing its reference
 * count.  This image should be considered read-only, The image is always
 * at full resolution.
 * 
 * Note that it is ONLY safe to read from the progress image in this method
 * and from ProgressImageUpdated(), as it is modified from a thread and
 * the contents can change out from under you.  The progress image is locked
 * while these methods are being called.
 * 
 * 
 * The progress image is updated frequently during the render, and the job
 * is notified of this through the ProgressImageUpdated() method.  Since
 * this may be called very frequently, you'll likely want to use this method
 * to set a "dirty" flag in your UI, and actually redraw your UI only a few
 * times a second.
 * 
 * This is sent only when the contents of the image previously sent via
 * ProgressImage() have changed.
 * 
 * 
 * We have a series of begin/end pairs indicating which frame, render pass and
 * sub-frame pass that is currently being rendered.  The hierarchy is like so:
 * - Begin()			Begin rendering
 * - - FrameBegin()		Begin rendering a frame
 * - - - RenderPassBegin()		Begin rendering a pass of a frame
 * - - - - FramePassBegin()	Begin rendering a sub-frame pass within a frame
 * - - - - - NucketBegin()		Begin rendering a bucket
 * - - - - - BucketEnd()		Finish rendering a bucket
 * - - - - FramePassEnd()		Finish rendering a sub-frame pass witihn a frame
 * - - - RenderPassEnd()		Finish rendering a passes of a frame
 * - - FrameEnd()			Finish rendering a frame
 * - End()				Finish rendering
 * 
 * This is called when a render begins.  All other progress messages will be sent between
 * this and End().
 * 
 * Begin() is provided with the ILxRenderStats representing all  of the stats for the render.
 * It is initially empty, will be populated as frames and render passes start to render.
 * This object may be AddRef()'ed if desired, so that it can be used throughout the render
 * and afterward. This object is identical to the one returned by ILxRenderService::JobStats()
 * 
 * The ILxRenderSlot of the slot itself is also provided to the client.
 * 
 * 
 * End() is passed the ILxRender Slot, as well as an ILxAttributesID representing
 * the final stats for the scene, as well as the IlxFrameBufferID for the last frame rendered.
 * These objects may be AddRef()'ed if desired.  Note that the ILxFrameBuffer may be NULL
 * if the render was aborted or otherwise failed, and wasAborted will be true.
 * 
 * Note that when this is called, the render will have been completed and
 * ILxRenderSlotService::CurrentRenderSlot() will return NULL.
 * 
 * 
 * 
 * This is called when an individual frame within begins rendering.
 * The width and height of the frame are also provided to the Begin() method, which 
 * may prove useful when setting up a render progress window.
 * 
 * 
 * When a frame finishes rendering, this method is called with the frame,
 * an object with an ILxAttributes interface. The ILxAttributes object
 * provides statistics representing the final state of the frame. This
 * object can be AddRef()'ed by the job and held onto for future use,
 * if so desired.  The frame buffer is not provided as each pass in the
 * frame has its own unique frame buffer.
 * 
 * 
 * One or more render passes may be rendered per frame.  Each render pass (not to
 * be confused with a frame pass, which aren't really used anymore) represents some
 * variation of the frame.  These methods are called when a render pass begins or ends.
 * 
 * RenderPassEnd() is provided with an ILxAttributesID representing the state of the
 * render at the time the pass finished, as well as an ILxFrameBuffer representing the
 * rendered pass.  These can be AddRef()'ed and held onto for future use, if so desired.
 * 
 * Note that the frame buffer may be NULL if the render was aborted.
 * 
 * If stereo is on, then the left, right or both eyes will be rendered.  The eye
 * argument will be one of the LXiRENDEREYE_* values from lx_rndjob.hpp, with MONO
 * being passed if stereo rendering is disabled.
 * 
 * 
 * The frame is further broken down into frame passes (not to be confused with
 * render passes).  These methods are called when a frame pass begins or ends.
 * 
 * 
 * Individual buckets are rendered within each frame pass.  These methods
 * are called when a bucket starts or ends.  Note that multiple buckets may
 * be rendered at the same time, and thus multiple begin calls may occur
 * before an end call is received. When a bucket begins, this method is
 * called with the row and column of the bucket passed, (where 0,0 is the
 * top-left corner).
 * 
 * 
 * This is called when the bucket ends.  The bucket index is provided along
 * with an LxResult code specifying how the bucket finished.  This can be an
 * OK code for success, LXe_ABORT for a user abort or a failure code.  Note that
 * ProgressAbort() will still be called a LXe_ABORT is sent to ProgressBucketEnd().
 * 
 * 
 * This will be called with the bucket layout.  It can
 * be used in conjunction with BucketBegin() and BucketEnd() to draw buckets
 * over the progress image when using the ILxRenderProgressPixel interface.
 * When using the ProgressImage directly, the buckets are baked into the image.
 * 
 */
typedef struct vt_ILxRenderProgressListener {
	ILxUnknown	 iunk;
	LXxMETHOD(  LxResult,
PercentDone) (
	LXtObjectID		  self,
	double			  progressScene,
	double			  progressFrame,
	double			  progressRenderPass);
	LXxMETHOD(  LxResult,
ProgressString) (
	LXtObjectID		  self,
	const char		 *infoString,
	const char		 *userString);
	LXxMETHOD(  LxResult,
ProgressImage) (
	LXtObjectID		  self,
	LXtObjectID		  img);
	LXxMETHOD(  LxResult,
ProgressImageUpdated) (
	LXtObjectID		  self);
	LXxMETHOD(  LxResult,
Begin) (
	LXtObjectID		  self,
	LXtObjectID		  renderSlot,
	LXtObjectID		  renderStats);
	LXxMETHOD(  LxResult,
End) (
	LXtObjectID		  self,
	LXtObjectID		  renderSlot,
	int			  wasAborted,
	LXtObjectID		  finalFrameBuffer,
	LXtObjectID		  finalStats);
	LXxMETHOD(  LxResult,
FrameBegin) (
	LXtObjectID		  self,
	int			  frame,
	int			  w,
	int			  h);
	LXxMETHOD(  LxResult,
FrameEnd) (
	LXtObjectID		  self,
	int			  frame,
	LXtObjectID		  stats);
	LXxMETHOD(  LxResult,
RenderPassBegin) (
	LXtObjectID		  self,
	int			  frame,
	int			  renderPassIndex,
	const char		 *renderPassName,
	int			  eye);

	LXxMETHOD(  LxResult,
RenderPassEnd) (
	LXtObjectID		  self,
	int			  frame,
	int			  renderPassIndex,
	const char		 *renderPassName,
	int			  eye,
	LXtObjectID		  frameBuffer,
	LXtObjectID		  stats);
	LXxMETHOD(  LxResult,
FramePassBegin) (
	LXtObjectID		  self,
	int			  frame,
	int			  renderPassIndex,
	int			  eye,
	int			  framePassIndex);

	LXxMETHOD(  LxResult,
FramePassEnd) (
	LXtObjectID		  self,
	int			  frame,
	int			  renderPassIndex,
	int			  eye,
	int			  framePassIndex);
	LXxMETHOD(  LxResult,
BucketBegin) (
	LXtObjectID		  self,
	int			  row,
	int			  col);
	LXxMETHOD(  LxResult,
BucketEnd) (
	LXtObjectID		  self,
	int			  row,
	int			  col,
	LxResult		  code);
	LXxMETHOD(  LxResult,
BucketInit) (
	LXtObjectID		  self,
	int			  rows,
	int			  cols,
	int				width,
	int				height);
} ILxRenderProgressListener;

/*
 * As each pixel is updated, these two methods are called. The first one is called with
 * the raw RGB value with no correction of any kind applied.  The second one is called
 * after various image processing has been applied (but not color correction, which is
 * up to the client to apply).
 * Note that this is called for any pixel drawing to the progress image, including things
 * like bucket borders and other such diagnostic information.  Also note that for single
 * component outputs (like alpha), the "rgb" argument will only have the "r" value set
 * to a greyscale value.
 * 
 * 
 * Pixels are also passed for each output.  This can be used to generate thumbnails
 * while rendering, if you don't want to use the progress thumbnails available in
 * the outputs.
 * 
 */
typedef struct vt_ILxRenderProgressPixel {
	ILxUnknown	 iunk;
	LXxMETHOD(  LxResult,
Raw) (
	LXtObjectID		  self,
	int			  x,
	int			  y,
	const LXtFVector	  rgb);

	LXxMETHOD(  LxResult,
Corrected) (
	LXtObjectID		  self,
	int			  x,
	int			  y,
	const LXtFVector	  rgb);
	LXxMETHOD(  LxResult,
OutputRaw) (
	LXtObjectID		  self,
	int			outputIdx,
	int			  x,
	int			  y,
	const LXtFVector	  rgb);

	LXxMETHOD(  LxResult,
OutputCorrected) (
	LXtObjectID		  self,
	int			outputIdx,
	int			  x,
	int			  y,
	const LXtFVector	  rgb);
} ILxRenderProgressPixel;

/*
 * ILxRenderSlot provides access to the slots used for rendering.  Each slot represents
 * a frame buffer, an aborted render, an in-progress render, or an image loaded by the
 * user.
 * 
 * Each slot contains one or more ILxRenderSlotPass objects, each representing a different
 * pass.  There is at least one pass per slot.
 * 
 * Each pass contains one or more ILxRenderSlotOutput objects, each representing a single
 * output, like RGB, alpha, diffuse, etc.
 * 
 * 
 * ILxRenderSlotService
 * 
 * The render service provides methods for walking the list of slots.
 * 
 */

	#define LXu_RENDERSLOTSERVICE	"0f1d9e87-f441-4deb-b93b-129e2d0acee3"
	#define LXa_RENDERSLOTSERVICE	"renderslotservice"

/*
 * An ILxRenderSlot can represent an in-progress render, a completed render, an aborted render,
 * or an image loaded from disk.  Slots contain passes, which in turn contain outputs.
 * 
 */

	#define LXu_RENDERSLOT	"7f3e8cb9-2def-4c50-9dd9-d61984bd3292"
	#define LXa_RENDERSLOT	"renderslot"

	//[local]  ILxRenderSlot

/*
 * Get the slot type (ie: frame buffer or image).
 */

	#define LXiRENDSLOT_TYPE_RENDER		0		// Rendered frame buffer
	#define LXiRENDSLOT_TYPE_IMAGE		1		// Image file loaded from disk

/*
 * 
 * ILxRenderSlotPass is a single pass within a slot.  It contains the outputs from the render
 * 
 */

	#define LXu_RENDERSLOTPASS	"5c2a8557-38b2-4c7e-89bf-90e9a2f64dbb"
	#define LXa_RENDERSLOTPASS	"renderslotpass"

	//[local]  ILxRenderSlotPass

/*
 * 
 * ILxRenderSlotOutput is a single output within a pass.  It contains the outputs from the render
 * 
 */

	#define LXu_RENDERSLOTOUTPUT	"cac5a601-e87a-4e1d-936b-60740abf49f3"
	#define LXa_RENDERSLOTOUTPUT	"renderslotoutput"

	//[local]  ILxRenderSlotOutput

/*
 * Open a file dialog and prompt user to save output to image on disk.
 * Available options for /param saveOp are defined as LXi_RENDSLOT_SAVEIMAGEOP_*.
 * If the operation is not output specific, i.e. LXi_RENDSLOT_SAVEIMAGEOP_LAYEREDIMAGE,
 * parent pass and slot will be extracted via linked pointers.
 */

	#define LXi_RENDSLOT_SAVEIMAGEOP_IMAGE				0	// Save output to single image
	#define LXi_RENDSLOT_SAVEIMAGEOP_LAYEREDIMAGE			1	// Save all outputs of a single pass as layered image
	#define LXi_RENDSLOT_SAVEIMAGEOP_PASSESASIMAGE			2	// Save all outputs in all passes as individual images
	#define LXi_RENDSLOT_SAVEIMAGEOP_PASSESASLAYEREDIMAGE		3	// Save all passes, as layered images

/*
 * // ----------------------------------------------------------------------------------------------
 * // ILxRenderSlotListener
 * 
 * 
 * ILxRenderSlotListener notifies clients about changes to the slot system, such
 * as when the slot list has been modified.
 * 
 */

	#define LXu_RENDERSLOTLISTENER	"0c0f7bb4-809d-4c28-bb67-549d17b04b71"
	// [local]  ILxRenderSlotListener
	// [export] ILxRenderSlotListener rendslotEvent

/*
 * ILxRenderProgressListener provides feedback to clients while a scene is rendering.
 */

	#define LXu_RENDERPROGRESSLISTENER	"1bc2eeb3-6e43-4559-b662-8f5d25a1a98a"
	// [local]  ILxRenderProgressListener
	// [export] ILxRenderProgressListener rendprogEvent

/*
 * Plug-in render views should provide extra infromation in the form of server tags.  This is attached
 * to the customView server that implements the view.
 * - WINDOW_KEY
 * When the an embedded view of this type can't be found, layout.window will be passed this key to
 * open that window, which should have your render view in it.  Without this tag, the view cannot be
 * used as a replacement for the native render window.
 * 
 */

	#define LXsRENDERVIEW_WINDOW_KEY			"renderViewWindowKey"

/*
 * ILxRenderProgressPixel provides a lower-level render progress API.  It is intended to
 * be used together with ILxRenderProgresListener::ProgressImage().  While ProgressUpdate()
 * can be used to get frequently notifications that the progress image has changed, that
 * is only sent from the main thread.  This API will provide updates each time a pixel in
 * the progress image is updated, and will do so from a thread.  All uses of this API must
 * be thread safe, and should be as quick as possible.
 * 
 */

	#define LXu_RENDERPROGRESSPIXEL		"bdc74053-417d-46dc-a9e0-2ebbc26d6213"
	#define LXa_RENDERPROGRESSPIXEL		"rendersprogresspixel"
	// [local]  ILxRenderProgressPixel
	// [export] ILxRenderProgressPixel rendProgPixel

#endif