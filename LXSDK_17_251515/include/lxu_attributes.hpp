/*
 * Plug-in SDK Header: C++ Wrapper Classes
 *
 * Copyright 0000
 *
 * Dynamic Attributes
 */
#ifndef LXU_ATTRIBUTES_HPP
#define LXU_ATTRIBUTES_HPP

#include <lx_command.hpp>
#include <lx_value.hpp>
#include <lx_item.hpp>
#include <vector>
#include <string>


/*
 * ----------------------------------------------------------------
 * The DynamicUIValue class is a simpler form of the ILxUIValueHint interface,
 * allowing the client to define custom UI behaviors for an attribute. The Flags()
 * method must be defined to indicate which of the other method are used with
 * LXfVALHINT_* flag bits.
 */
class CLxDynamicUIValue :
		public CLxObject
{
    public:
	virtual unsigned	Flags () = 0;

	virtual unsigned	PopCount ()
		{ return 0; }
	virtual const char *	PopUserName (unsigned /*index*/)
		{ return nullptr; }
	virtual const char *	PopInternalName (unsigned /*index*/)
		{ return nullptr; }
	virtual const char *	PopToolTip (unsigned /*index*/)
		{ return nullptr; }
	virtual int		PopFlags (unsigned /*index*/)
		{ return 0; }
	virtual const char *	PopCategory ()
		{ return nullptr; }
	virtual LxResult	PopIconSize ( int &/*w*/, int &/*h*/ )
		{ return LXe_NOTIMPL; }
	virtual LxResult	PopIconImage ( int /*index*/, void ** /*ppvObj*/ )
		{ return LXe_NOTIMPL; }
	virtual LxResult	PopIconResource ( int /*index*/, const char ** /*iconResource*/ )
		{ return LXe_NOTIMPL; }

	virtual bool		ItemTest (CLxUser_Item &/*item*/)
		{ return true; }

	virtual LxResult	ColorPickerCommands (char * /*rgb*/, char * /*alpha*/, char * /*rgbAlt*/, char * /*alphaAlt*/, char * /*useAlt*/, unsigned /*bufLens*/)
		{ return LXe_NOTIMPL; }

	virtual int		NotifierCount ()
		{ return 0; }
	virtual LxResult	NotifierByIndex (int /*index*/, const char ** /*name*/, const char ** /*args*/)
		{ return LXe_NOTIMPL; }

	virtual int		FormCommandListCount ()
		{ return 0; }
	virtual const char *	FormCommandListByIndex (int /*index*/)
		{ return nullptr; }

	virtual const char *	CueText ()
		{ return nullptr; }
	
	virtual LxResult	TextValidate (const char * /*value*/, char * /*buf*/, unsigned int /*len*/)
		{ return LXe_NOTIMPL; }
};

namespace lx
{
	/*
	 * Function to spawn a UIValue COM object from a CLxDynamicUIValue object,
	 * or from it's special subclasses, below.
	 */
	extern void	UIValueHintsAllocate (CLxDynamicUIValue *, void **ppvObj, bool ownIt = true);
}


/*
 * This is a simpler format that will implement many of the methods using
 * more stored state. Any of the base methods can be overridden, of course,
 * but it will be easier to set the state on creation.
 */
class CLxUIValue :
		public CLxDynamicUIValue
{
    public:
	 CLxUIValue ();
	~CLxUIValue ();

	/*
	 * Popups can be built by adding a sequence of entries. Each entry has
	 * value and name. If the name is non-null the value is the internal name
	 * and the name is the user name.
	 */
	void		popup_add (const char *value, const char *name = nullptr, const char *tooltip = nullptr);

	/*
	 * Call this after adding an entry to customize the flags.
	 */
	void		popup_flags (int flags);

	/*
	 * Call this after adding an entry to customize the resource image.
	 */
	void		popup_resource (const char *);

	/*
	 * Call this to set the image size for resource icons.
	 */
	void		popup_set_imagesize (int w, int h);

	/*
	 * Call this to enable or disable alphabetic sorting for entries.
	 */
	void		popup_set_alphasort (bool state = true);
	
	/*
	 * Call this to enable or disable the filter text box for searching entries.
	 */
 	void		popup_set_filter (bool state = true);

	/*
	 * Call this to set the category name.
	 */
	void		popup_set_category (const char *cat = nullptr);

	/*
	 * Call this to remove all popup entries allowing them to be replaced.
	 */
	void		popup_clear ();

	/*
	 * Call this to configure a color value with commands for editing RGB
	 * and alpha of the main value.
	 */
	void		color_set (const char *rgb, const char *alpha = nullptr);

	/*
	 * Call this to configure a color value with commands for editing RGB
	 * and alpha of the secondary or alternate value.
	 */
	void		color_alt (const char *rgb, const char *alpha = nullptr);

	/*
	 * Call this to configure a color value with a commands for swapping
	 * between the main value and the secondary or alternate.
	 */
	void		color_swap (const char *);

	/*
	 * Call this to add a notifier for this value. Multiple notifiers can
	 * be added.
	 */
	void		notify_add (const char *name, const char *arg = "");

	/*
	 * Call this to build a form command list. Commnds for the form are 
	 * added one at a time.
	 */
	void		form_add_cmd (const char *cmd);

	/*
	 * Call to set the cue text for the value.
	 */
	void		set_cue_text (const char *text);

	/*
	 * - Inhertied methods.
	 */
   //internal:
	unsigned	Flags () override;
	unsigned	PopCount () override;
	const char *	PopUserName (unsigned index) override;
	const char *	PopInternalName (unsigned index) override;
	const char *	PopToolTip (unsigned index) override;
	int		PopFlags (unsigned index) override;
	const char *	PopCategory () override;
	LxResult	PopIconSize ( int &w, int &h ) override;
	LxResult	PopIconResource ( int index, const char **iconResource ) override;
	LxResult	ColorPickerCommands (char *rgb, char *alpha, char *rgbAlt, char *alphaAlt, char *useAlt, unsigned bufLens) override;
	int		NotifierCount () override;
	LxResult	NotifierByIndex (int index, const char **name, const char **args) override;
	int		FormCommandListCount () override;
	const char *	FormCommandListByIndex (int index) override;
	const char *	CueText () override;

	class pv_UIValue *pv;
};


/*
 * ----------------------------------------------------------------
 * A common specialization of the DynamicUIValue class allows the client to
 * present a simple popup list. The client customizes the list by wrting a
 * function to populate the user list. If set, the list of internal names
 * should be the same length as the user names.  The tooltip strings array
 * can be left empty, but if it is populated it must be a one-to-one match
 * with the names and usernames arrays.  Empty tooltips are allowed for
 * entries that don't have tooltips.
 */
class CLxUIListPopup :
		public CLxDynamicUIValue
{
    public:
	std::vector<std::string>	 user_list, internal_list, tooltip_list;

	virtual void		UpdateLists () = 0;

	unsigned		Flags ()			override;
	unsigned		PopCount ()			override;
	const char *		PopUserName (unsigned)		override;
	const char *		PopInternalName (unsigned)	override;
	const char *		PopToolTip (unsigned)		override;
};


// ------------ following declaractions are internal
//@skip

/*
 * ----------------------------------------------------------------
 * The DynamicAttributes class is an implementation of ILxAttributes that
 * can be used by clients. All the client has to do is add attributes in
 * the order they want, set their flags and hints, if any, and the rest
 * is automatic. It also supports the command methods needed to implement
 * a command.
 */
class CLxDynamicAttributes :
		public CLxImpl_Attributes,
		public CLxImpl_AttributesUI
{
    public:
	 CLxDynamicAttributes();
	~CLxDynamicAttributes();

	void		dyna_Add      (const char *name, const char *type);
	void		dyna_Add      (std::string name, std::string type);
	void		dyna_SetHint  (unsigned int index, const LXtTextValueHint *hint);
	CLxUser_Value &	dyna_Value    (unsigned int index);
	void		dyna_SetType  (unsigned int index, const char *type);
	bool		dyna_IsSet    (unsigned int index);
	void		dyna_SetFlags (unsigned int index, unsigned flags);
	virtual unsigned
			dyna_GetFlags (unsigned int index);

	bool		dyna_Bool     (unsigned int index, bool   value = false);
	int		dyna_Int      (unsigned int index, int    value = 0);
	double		dyna_Float    (unsigned int index, double value = 0.0);
	bool		dyna_String   (unsigned int index, std::string &text, const char *value = "");
	bool		dyna_Object   (unsigned int index, CLxLocalizedObject &);

	unsigned int	attr_Count    ()					override;
	LxResult	attr_Name     (unsigned int index, const char **name)	override;
	LxResult	attr_Lookup   (const char *name, unsigned int *index)	override;
	LxResult	attr_Type     (unsigned int index, unsigned int *type)	override;
	LxResult	attr_TypeName (unsigned int index, const char **tname)	override;
	const LXtTextValueHint *
			attr_Hints    (unsigned int index)			override;

	LxResult	attr_Value     (unsigned int index, void **ppvObj, int writeOK)	 override;
	LxResult	attr_GetInt    (unsigned int index, int *val)			 override;
	LxResult	attr_SetInt    (unsigned int index, int val)			 override;
	LxResult	attr_GetFlt    (unsigned int index, double *val)		 override;
	LxResult	attr_SetFlt    (unsigned int index, double val)			 override;
	LxResult	attr_GetString (unsigned int index, char *val, unsigned int len) override;
	LxResult	attr_SetString (unsigned int index, const char *val)		 override;

	LxResult	attr_GetBool   (unsigned int index, bool *val);
	LxResult	attr_SetBool   (unsigned int index, bool val);
	LxResult	attr_GetString (unsigned int index, std::string &value);

	virtual void	dyna_Changed   (unsigned int /*index*/)			    { }

	virtual bool	atrui_Enabled  (unsigned int /*index*/, CLxUser_Message &/*msg*/)   { return true; }
	virtual void	atrui_UIHints2 (unsigned int /*index*/, CLxUser_UIHints &/*hints*/) { }
	virtual CLxDynamicUIValue *
			atrui_UIValue  (unsigned int /*index*/) { return nullptr; }

 	LxResult	atrui_DisableMsg   (unsigned int index, ILxUnknownID msg)   override;
 	LxResult	atrui_UIHints      (unsigned int index, ILxUnknownID hints) override;
 	LxResult	atrui_UIValueHints (unsigned int index, void **ppvObj)      override;

    private:
	class pv_DynaAttributes	*pv;
};


/*
 * DynamicArguments is a specialization that knows about the specific flags
 * used for command arguments.
 */
class CLxDynamicArguments :
		public CLxDynamicAttributes
{
    public:
	/*
	 * The GetFlags() override reads the stored flags and adds in the
	 * SET flag for arguments that are set.
	 */
	unsigned	dyna_GetFlags (unsigned) override;

	/*
	 * Variable argument types are handled by setting them here. The
	 * GetType() method is implemented by the client.
	 */
	bool		dyna_HasVariable ();
	void		dyna_SetVariable ();
	virtual const char *
			dyna_GetType (unsigned) { return nullptr; }

	/*
	 * Arguments can be cleared which resets some of the flags.
	 */
	void		dyna_Clear (unsigned);
	void		dyna_ClearAll ();
};

#endif /* LX_ATTRIBUTES_HPP */
