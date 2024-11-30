/*
 * Plug-in SDK Header: C++ Services
 *
 * Copyright 0000
 *
 * Helper class for getting user values.
 */
#ifndef LX_QUERIES_HPP
#define LX_QUERIES_HPP

#include <lxu_attributes.hpp>
#include <string>


/*
 * ----------------------------------------------------------------
 * The CLxCommandQuery class makes it easy to query a command.
 */
class CLxCommandQuery
{
    public:
	 CLxCommandQuery (const char *);
	~CLxCommandQuery ();

	CLxUser_Attributes &	 Arguments ();
	bool			 Query     (unsigned int argIndex);
	const char *		 ValueType ();
	unsigned		 Count     ();
	void			 SetIndex  (unsigned int valIndex);
	int			 GetInt    ();
	double			 GetFloat  ();
	const char *		 GetString (char *, unsigned);
	void			 GetString (std::string &string);

	bool			 GetValue(CLxLocalizedObject& o_dest);

	void			 ResetArgs();

	LxResult		 IntHint (const LXtTextValueHint **hints);

    private:
	class pv_CommandQuery	*pv;
};


/*
 * This is a very simple class for reading user values.  User values
 * can be declared in configs and presented in interfaces.
 */
class CLxReadUserValue
{
    public:
	 CLxReadUserValue ();
	~CLxReadUserValue ();

	bool			 Query (const char *);
	const char *		 ValueType ();
	int			 GetInt    ();
	double			 GetFloat  ();
	void			 GetString (std::string &string);

    private:
	class pv_ReadUserValue	*pv;
};


#endif	/* LX_QUERIES_HPP */
