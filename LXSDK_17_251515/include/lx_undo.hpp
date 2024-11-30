/*
 * Plug-in SDK Header: C++ User Classes
 *
 * Copyright 0000
 */
#ifndef LXUSER_undo_HPP
#define LXUSER_undo_HPP

#include <lxw_undo.hpp>


class CLxUser_UndoService : public CLxLoc_UndoService
{
	public:
	unsigned int
	State ()
	{
		return CLxLoc_UndoService::State ();
	}

};
#endif