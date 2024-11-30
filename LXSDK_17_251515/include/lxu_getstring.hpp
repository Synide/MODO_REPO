/*
 * Plug-in SDK Header: Common Utilities
 *
 * Copyright 0000
 *
 * Provides template class for getting string buffers safely.
 */

#ifndef LXU_GETSTRING_HPP
#define LXU_GETSTRING_HPP

#include <cstring>


/*
 * ----------------------------------------------------------
 * This is a simple template for code that reads a string safely through the
 * SDK interfaces into a standard string. The client implements a method called
 * sgs_GetString() that takes a buffer and length. If it returns LXe_SHORTREAD
 * we allocate a larger buffer and try again.
 *
 * Two other variants of the method return booleans or raise exceptions.
 */
template <class T>
class CLxSafeGetString
{
    public:
		LxResult
	GetString (
		T			&thing,
		std::string		&value)
	{
		LxResult		 rc;
		char			*buf;
		size_t			 len;

		len = 1024;
		while (1) {
			buf = new char [len];
			rc  = thing.sgs_GetString (buf, static_cast<unsigned>(len));
			if (rc != LXe_SHORTBUFFER)
				break;

			delete[] buf;
			len *= 2;
		}

		if (LXx_OK (rc))
			value = buf;

		delete[] buf;
		return rc;
	}

		void
	GetStringEx (
		T			&thing,
		std::string		&value)
	{
		LxResult		 rc;

		rc = GetString (thing, value);
		if (LXx_FAIL (rc))
			throw (rc);
	}

		bool
	GetStringBool (
		T			&thing,
		std::string		&value)
	{
		LxResult		 rc;

		rc = GetString (thing, value);
		return LXx_OK (rc);
	}

}; // END CLxSafeGetString template


/*
 * ----------------------------------------------------------
 * "lx" namespace for utility functions.
 */
		namespace lx {

/*
 * This utility function does the opposite. When a method is expected to return
 * a string in a buffer and length, this function will copy the string and return
 * an error if the buffer was too short.
 */
extern LxResult		StringOut (std::string &string, char *buf, unsigned len);
extern LxResult		StringOut (const char *string, char *buf, unsigned len);

/*
 * Get the name associated with a result code from the 'lxresult' message table.
 * If not possible for any reason this returns the code as a string in hex.
 */
extern std::string	LxResultName (LxResult);

		};	// END lx namespace


#endif // LXU_GETSTRING_HPP
