/*
 * Plug-in SDK Header: C++ Services
 *
 * Copyright 0000
 *
 * Helper classes for implementing I/O servers.
 */
#ifndef LXU_IO_HPP
#define LXU_IO_HPP

#include <lx_io.hpp>
#include <lx_value.hpp>
#include <lxu_meta.hpp>


/*
 * -------------------------------------
 * Loader
 *
 * The loader supports user options, which exist independently in a subclass of
 * this object. The client must provide loading and saving.
 */
class CLxLoaderOptions :
		public CLxObject
{
    public:
	virtual void		save (CLxUser_BlockWrite &) {}
	virtual void		load (CLxUser_BlockRead &) {}
};


/*
 * The superclass supports basic behaviors and some customization.
 */
class CLxLoader :
		public CLxObject
{
    public:
	 CLxLoader ();
	~CLxLoader ();

	/*
	 * Implement to determine if a file matches this loader and to set
	 * basic attributes.
	 */
	virtual bool		recognize (const char *) = 0;

	/*
	 * Call to get the loader class if the loader supports more than one.
	 */
	const char *		get_class ();

	/*
	 * Call to set the format for the saver, if it's different from this.
	 */
	void			set_format (const char *);

	/*
	 * Call to set the load to be opaque.
	 */
	void			set_opaque (bool opaque = true);

	/*
	 * Implement to load opaque formats by allocating the new object.
	 */
	virtual ILxUnknownID	load_opaque () { return nullptr; }

	/*
	 * Implement to load direct formats into the destination object.
	 */
	virtual void		load_into (ILxUnknownID) {}

	/*
	 * Call to get secondary objects useful for the load.
	 */
	CLxUser_LoaderInfo &	loader_info ();
	CLxUser_Monitor &	monitor ();

	class pv_Loader	*pv;
};

/*
 * Core metaclass sets global properties.
 */
class CLxMeta_Loader_Core :
		public CLxMetaServer
{
    public:
	 CLxMeta_Loader_Core (const char *srvName);
	~CLxMeta_Loader_Core ();

	/*
	 * Set the file pattern for the loader. This is "*.xxx" for a single
	 * extension, and "*.xxx;*.yyy" for multiple extensions.
	 */
	void		set_file_pattern (const char *);

	/*
	 * Set the class for the loader, like LXu_IMAGE or LXu_SCENE. Can be
	 * called multiple times for loaders that support multiple classes.
	 */
	void		set_class (const char *);

	/*
	 * Set to indicate that the loader is safe to run in threads.
	 */
	void		set_threadsafe ();

    //internal:
	virtual CLxLoader *	new_inst () = 0;
	virtual bool		has_options () = 0;
	virtual CLxLoaderOptions *
				new_options () = 0;

	bool			pre_init () override;
	void *			alloc () override;
	CLxLoaderOptions *	access_opt (bool);

	class pv_Meta_Loader	*pv;
};

/*
 * Template for server metaclass.
 */
template <class T, class OPT = CLxLoaderOptions>
class CLxMeta_Loader :
		public CLxMeta_Loader_Core
{
    public:
	CLxMeta_Loader (const char *srvName) : CLxMeta_Loader_Core (srvName) { }

	/*
	 * Call to read options stored in the global state,
	 */
		OPT *
	get_options ()
	{
		return dynamic_cast<OPT *> (access_opt (false));
	}

	/*
	 * Call to store new options in the global state,
	 */
		OPT *
	set_options ()
	{
		return dynamic_cast<OPT *> (access_opt (true));
	}

    //internal:
		CLxLoader *
	new_inst ()		override
	{
		return new T;
	}

		bool
	has_options ()		override
	{
		return sizeof(OPT) != sizeof(CLxLoaderOptions);
	}

		CLxLoaderOptions *
	new_options ()		override
	{
		return new OPT;
	}
};


/*
 * -------------------------------------
 * Saver
 *
 * The abstract class defines methods taking the unknown object pointer.
 */
class CLxSaver :
		public CLxObject
{
    public:
	virtual void		obj_save (ILxUnknownID, const char *, CLxUser_Monitor &) = 0;
	virtual void		obj_verify (ILxUnknownID, CLxUser_Message &) = 0;
};

/*
 * The client superclass is a template that can be specialized with the
 * wrapper for the object type.
 */
template <class T>
class CLxSaverT :
		public CLxSaver
{
    public:
	/*
	 * Implement to save an object to the named file.
	 */
	virtual void		save (T &, const char *, CLxUser_Monitor &) = 0;

	/*
	 * Implement to test an object to report if any data will be lost.
	 */
	virtual void		verify (T &, CLxUser_Message &) {}

    //internal:
		void
	obj_save (
		ILxUnknownID		 source,
		const char		*filename,
		CLxUser_Monitor		&monitor)		override
	{
		T			 obj (source);

		save (obj, filename, monitor);
	}

		void
	obj_verify (
		ILxUnknownID		 source,
		CLxUser_Message		&msg)			override
	{
		T			 obj (source);

		verify (obj, msg);
	}
};

/*
 * Core metaclass sets global properties.
 */
class CLxMeta_Saver_Core :
		public CLxMetaServer
{
    public:
	 CLxMeta_Saver_Core (const char *srvName);
	~CLxMeta_Saver_Core ();

	/*
	 * Set the class for the saver, like LXu_IMAGE or LXu_SCENE.
	 */
	void		set_class (const char *);

	/*
	 * Set the file extension for the Saver. This is typically a
	 * three-character string in uppercase.
	 */
	void		set_file_extension (const char *);

	/*
	 * Set to indicate that the saver needs to get the real filename
	 * when saving, not a nearby temp file.
	 */
	void		set_overwrite ();

	/*
	 * Set to indicate that the saver can be used to save a matching
	 * loader format.
	 */
	void		set_save_as ();

    //internal:
	virtual CLxSaver *	new_inst () = 0;

	void *			alloc () override;

	class pv_Meta_Saver	*pv;
};

/*
 * Template for server metaclass.
 */
template <class T>
class CLxMeta_Saver :
		public CLxMeta_Saver_Core
{
    public:
	CLxMeta_Saver (const char *srvName) : CLxMeta_Saver_Core (srvName) { }

		CLxSaver *
	new_inst ()		override
	{
		return new T;
	}
};


#endif // LXU_IO_HPP
