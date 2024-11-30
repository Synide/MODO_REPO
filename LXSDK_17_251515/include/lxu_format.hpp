/*
 * Plug-in SDK Header: C++ Wrapper Classes
 *
 * Copyright 0000
 *
 * General I/O Wrappers
 */
#ifndef LX_FORMAT_HPP
#define LX_FORMAT_HPP

#include <lxw_io.hpp>
#include <string>


/*
 * ----------------------------------------------------------------
 * Abstract file format class. Used as a framework for saver wrappers.
 * The details of the format should be specified by the client.
 */
class CLxFileFormat
{
    public:
	virtual			~CLxFileFormat () {}

	virtual bool		 ff_Open       (const char *)	= 0;
	virtual void		 ff_Enable     (bool)		= 0;
	virtual bool		 ff_HasError   ()		= 0;
	virtual void		 ff_Cleanup    ()		= 0;

	const char		*file_name;
};


/*
 * ----------------------------------------------------------------
 * Format for general line-based text files.
 */
class CLxLineFormat : public CLxFileFormat
{
    public:
				 CLxLineFormat ();
	virtual			~CLxLineFormat ();

	bool		 ff_Open       (const char *)	override;
	void		 ff_Enable     (bool)		override;
	bool		 ff_HasError   ()		override;
	void		 ff_Cleanup    ()		override;

	virtual const char *	 lf_Separator  ()		{ return ""; }
	void		 lf_Raw        (const char *);
	void		 lf_Delim      ();
	void		 lf_Break      (bool force = false);

	virtual void		 lf_Output     (std::string &, bool delim = true);
	virtual void		 lf_Output     (const char *,  bool delim = true);
	virtual void		 lf_Quote      (const char *,  bool delim = true);
	virtual void		 lf_Output     (double,        bool delim = true);
	virtual void		 lf_Output     (int,           bool delim = true);
	virtual void		 lf_Output     (unsigned,      bool delim = true);

	bool			 start_of_line;

    private:
	class pv_LineFormat	*pv;
};

/*
 * ----------------------------------------------------------------
 * Format for general binary files.
 */
class CLxBinaryFormat : public CLxFileFormat
{
    public:
				 CLxBinaryFormat ();
	virtual			~CLxBinaryFormat ();

	bool		 ff_Open       (const char *)	override;
	void		 ff_Enable     (bool)		override;
	bool		 ff_HasError   ()		override;
	void		 ff_Cleanup    ()		override;

	virtual void		 lf_Output     (std::string &);
	virtual void		 lf_Output     (const char *str);
	virtual void		 lf_Output     (float value);
	virtual void		 lf_Output     (double value);
	virtual void		 lf_Output     (int value);
	virtual void		 lf_Output     (unsigned value);

    private:
	class pv_BinaryFormat	*pv;
};

namespace lx
{
	/*
	 * Encode a double for writing to text files. This always uses "." as the
	 * decimal separator regardless of locale settings.
	 */
	void			 Encode (double, std::string &);
	std::string		 Encode (double);

	/*
	 * Encode an int.
	 */
	std::string		 Encode (int);

	/*
	 * Conversions between ID4 code and string.
	 */
	LXtID4			 StringID4 (const char *);
	std::string		 ID4String (LXtID4);
};

#endif /* LX_FORMAT_HPP */
