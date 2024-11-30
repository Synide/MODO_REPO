/*
 * Plug-in SDK Header: C++ Services
 *
 * Copyright 0000
 *
 * Helper class for posting warnings and catching errors and reporting
 * them to the I/O status log, with identification of the message poster.
 */
#ifndef LX_LOGUTIL_HPP
#define LX_LOGUTIL_HPP

#include <cstdlib>
#include <string>
#include <sstream>
#include <lxresult.h>
#include <lxversion.h>
#include <lx_scripts.hpp>


class CLxLogMessage
{
    public:
	/*
	 * Implement to return identity string (required).
	 */
	virtual const char *	 GetFormat  () = 0;

	/*
	 * Implement to return version string (required).
	 */
	virtual const char *	 GetVersion () = 0;

	/*
	 * Implement to return copyright notice.
	 */
	virtual const char *	 GetCopyright ();

	/*
	 * Call to add a three part message string with result code to log.
	 */
	void			 Message (LxResult, const char *who, const char *what, const char *why);

	/*
	 * Call to add an error message to the log.
	 */
	void			 Error (const char *msg);

	/*
	 * Call to add an error message to the log.
	 */
	void			 Error (const std::string &msg)   { Error (msg.c_str ()); }

	/*
	 * Call to add an info message to the log.
	 */
	void			 Info (const char *msg);

	/*
	 * Call to add an info message to the log.
	 */
	void			 Info (const std::string &msg)    { Info (msg.c_str ()); }

	/*
	 * Call to initialize the log and display initial message. Returns true
	 * on success. Is also called automatically before adding first message.
	 */
	bool			 Setup ();

	/*
	 * Call to append a three part message string with result code to the
	 * previous log entry.
	 */
	void			 SubMessage (LxResult, const char *who, const char *what, const char *why);

	/*
	 * Call to add an info message to the previous log entry.
	 */
	void			 SubInfo (const char *msg);

	/*
	 * Call to add an info message to the previous log entry.
	 */
	void			 SubInfo (const std::string &msg) { SubInfo (msg.c_str ()); }

    //internal:
		 CLxLogMessage (const char *log = "io-status");
	virtual ~CLxLogMessage ();

	class pv_LogMessage	*pv;
};

//@skip

class CLxLuxologyLogMessage : public CLxLogMessage
{
    public:
	CLxLuxologyLogMessage (const char *log = "io-status") : CLxLogMessage (log) { }

	const char *	 GetVersion () override
	{
		if (_versionString.size () == 0)
		{
			std::stringstream	 ss;
			int			 versionMajor = 1, versionMinor = 0, versionSP = 0;
		
			_pfmSvc.AppVersion (&versionMajor);
			_pfmSvc.AppVersionMinor (&versionMinor);
			_pfmSvc.AppVersionSP (&versionSP);
		
			ss << versionMajor << "." << versionMinor << "v" << versionSP;

			_versionString = ss.str ();
		}
	
		return _versionString.c_str ();
	}

	const char *	 GetCopyright () override
	{
		return "Copyright " LXs_VERSION_BUILD_YEAR " The Foundry Visionmongers Limited";
	}
	
    private:
	CLxUser_PlatformService	 _pfmSvc;
	std::string		 _versionString;
};

#endif	/* LX_LOGUTIL_HPP */
