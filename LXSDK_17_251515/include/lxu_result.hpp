/*
 * Plug-in SDK Header: C++ Services
 *
 * Copyright 0000
 *
 * Helper class for modo results.
 */

#ifndef LX_RESULT_HPP
#define LX_RESULT_HPP

#include <lxresult.h>
#include <lx_message.hpp>
#include <lx_scripts.hpp>

#include <cstdio>

#include <string>


class CLxResultStr
{
public:
	CLxResultStr(const LxResult rc = LXe_OK,  const std::string &message = "") :
	m_messageGood(false),
	m_message(message) {
		set( rc );
	}
	
	///
	/// Returns true if there was no error
	///
	inline bool ok() const {
		return LXx_OK( m_rc );
	}
	
	///
	/// Returns true if there was an error
	///
	inline bool fail() const {
		return LXx_FAIL( m_rc );
	}
	
	///
	/// Returns true if the result was true
	///
	inline bool isTrue() const {
		return (LXe_TRUE == m_rc);
	}
	
	///
	/// Returns true if the result was false
	///
	inline bool isFalse() const {
		return (LXe_FALSE == m_rc);
	}
	
	///
	/// Copy operator that takes a raw result code
	///
	inline CLxResultStr & 	operator= (const LxResult &rc) {
		set( rc );
		return *this;
	}
	
	///
	/// Copy operator that takes another CLxResultStr
	///
	inline CLxResultStr & 	operator= (const CLxResultStr &rhs) {
		set( rhs.m_rc );
		return *this;
	}
	
	///
	/// Compare operator that takes raw result code
	///
	inline bool operator== (const LxResult &rc) const {
		return (m_rc == rc);
	}
	
	///
	/// Compare operator that takes another CLxResultStr
	///
	inline bool operator== (const CLxResultStr &rhs) const {
		return (m_rc == rhs.m_rc);
	}
	
	///
	/// Not equal compare operator that takes raw result code
	///
	inline bool operator!= (const LxResult &rc) const {
		return (m_rc != rc);
	}
	
	///
	/// Not equal compare operator that takes another CLxResultStr
	///
	inline bool operator!= (const CLxResultStr &rhs) const {
		return (m_rc != rhs.m_rc);
	}
	
	///
	/// The raw result code
	///
	inline LxResult resultCode() const {
		return m_rc;
	}
	
	///
	/// Returns a localized, human readable string of the current result code
	///
	inline const std::string resultString() const {
		char integerCodeAsAString[16];
		sprintf( integerCodeAsAString, "%08x", m_rc );
		const char *errorMsg;
		CLxUser_MessageService   svMsg;
		if( svMsg.m_loc ) {
			svMsg.RawText("lxresult", integerCodeAsAString, &errorMsg);
			return std::string( errorMsg );
		}
		return std::string( "" );
	}
	
	///
	/// If an additional string was given when this result was created,
	/// it can be returned with this method.  Will return "" if none.
	///
	inline const std::string & messageString() const {
		return m_message;
	}
	
	///
	/// If an additional string was given when this result was created,
	/// it can be returned with this method.  Will return "" if none.
	///
	inline const std::string & errorString() {
		if( !m_messageGood ) {
			m_errorMessage = resultString();
			m_messageGood = true;
		}

		return m_errorMessage;
	}
	
	///
	/// Mostly for compatability so that returning a CLxResultStr from a method
	/// that returns an LxResult, will return the raw result code
	inline operator LxResult() const {
		return m_rc;
	}
	
	///
	/// Returns true if there was no error
	///
	static inline bool ok( const LxResult &rc ) {
		return LXx_OK( rc );
	}
	
	///
	/// Returns true if there was an error
	///
	static inline bool fail( const LxResult &rc ) {
		return LXx_FAIL( rc );
	}
	
	///
	/// Returns true if the result was true
	///
	static inline bool isTrue( const LxResult &rc ) {
		return (LXe_TRUE == rc);
	}
	
	///
	/// Returns true if the result was false
	///
	static inline bool isFalse( const LxResult &rc ) {
		return (LXe_FALSE == rc);
	}
	

private:
	
	void set( const LxResult rc ) {
		m_rc = rc;
		m_messageGood = false;
	}
	
	bool		m_messageGood;
	LxResult	m_rc;
	std::string	m_errorMessage;
	std::string	m_message;
	
};



#endif	/* LX_RESULT_HPP */
