/*
 * Plug-in SDK Header: Message Utilities
 *
 * Copyright 0000
 *
 * Provides message utility functions for C++ plug-ins.
 */

#ifndef LXU_MESSAGE_HPP
#define LXU_MESSAGE_HPP

#include <string>

namespace lx {

	/*
	 * These functions all look up message text from a table and a message
	 * index or name. Use the one that best matches your needs.
	 */
		bool
	GetMessageText (
		std::string		&text,
		const char		*table,
		unsigned		 msgIndex,
		const char		*msgName);

		bool
	GetMessageText (
		std::string		&text,
		const char		*table,
		const char		*msgName);

		bool
	GetMessageText (
		std::string		&text,
		const char		*table,
		unsigned		 msgIndex);

		bool
	GetMessageText (
		std::string		&text,
		const std::string	&table,
		const std::string	&msgName);

		bool
	GetMessageText (
		std::string		&text,
		const std::string	&table,
		unsigned		 msgIndex);

	/*
	 * These are the same but get text from the "common" table.
	 */
		bool
	CommonMessage (
		std::string		&text,
		unsigned		 msgIndex);

		bool
	CommonMessage (
		std::string		&text,
		const char		*msgName);

};	// END namespace

#endif // LXU_MESSAGE_HPP
