#pragma once

// OBJ Parser Class
//
//   Copyright 0000

#include "lineCommandParser.hxx"

/*
 * ----------------------------------------------------------------
 * OBJ Parser Class
 *
 * This is a line command parser recognizing OBJ format commands.
 */
typedef enum en_OBJCommand
{
    CMD_UNKNOWN,
    CMD_VERTEX,
    CMD_TEXTURE,
    CMD_NORMAL,
    CMD_FACE,
    CMD_LINE,
    CMD_GROUP,
    CMD_USE_MATERIAL,
    CMD_MATR_LIBRARY,
    CMD_OBJECT,
    CMD_SHADOW_OBJ,
    CMD_SMOOTHING_GROUP,
    CMD_TRACE_OBJ
} OBJCommand;

class COBJParser : public CLineCommandParser<OBJCommand>
{
public:
    COBJParser()
    {
        cmd_table = obj_cmds;
    }
    bool               PullPolyVec(int*, bool*);
    static CommandName obj_cmds[];
};
