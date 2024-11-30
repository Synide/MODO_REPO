/*
 * Plug-in SDK Header: C++ Services
 *
 * Copyright 0000
 *
 * Helper class for opening user dialogs.
 */
#ifndef LXU_DIALOG_HPP
#define LXU_DIALOG_HPP

#include <lx_stddialog.hpp>
#include <string>
#include <vector>


/*
 * The FileDialog utility class lets the client set up a dialog and then
 * use it to get files for load and save.
 */
class CLxFileDialog
{
    public:
	/*
	 * Set the object class for files to find, as well as optional context.
	 * The context helps to remember the specific path for this usage,
	 * especially for common type like images.
	 */
	void		set_class (const char *cls, const char *context = nullptr);

	/*
	 * Set the title, given by tablename and key. The table name can be used
	 * verbatim if there's no key, and no translation is required.
	 */
	void		set_title (const char *table, const char *key = nullptr);

	/*
	 * Set the starting format for the save dialog, matching the class.
	 */
	void		set_format (const char *);

	/*
	 * Set the starting path, if any. This is reset after every dialog.
	 */
	void		set_start_path (const char *);

	/*
	 * Remove the ability to change formats from the dialog.
	 */
	void		no_formats ();

	/*
	 * Pick a single file for loading. The basename can be set if there's
	 * no starting path, otherwise it should be part of the path.
	 */
	bool		load_single (std::string &, const char *basename = nullptr);

	/*
	 * Pick a list of files for loading.
	 */
	bool		load_multiple (std::vector<std::string> &);

	/*
	 * Pick a file for saving. Overwrite allows an existing file to be picked.
	 */
	bool		save (std::string &, bool overwrite = true);

	/*
	 * Pick a directory location. The result is a directory path.
	 */
	bool		pick_directory (std::string &);

    //internal:
	 CLxFileDialog ();
	~CLxFileDialog ();

	class pv_FileDialog	*pv;
};


#endif	/* LXU_DIALOG_HPP */
