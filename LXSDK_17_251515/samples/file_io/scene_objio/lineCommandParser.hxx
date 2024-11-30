#pragma once

// Line Command Parser Class
//
//   Copyright 0000

#include <lxu_parser.hpp>
#include <string>

#if !defined(_WIN32) && !defined(_WIN64)
#define stricmp(a, b) strcasecmp((a), (b))
#endif

/*
 * ----------------------------------------------------------------
 * Line Command Parser Class
 *
 * This derives from the standard line parser, stripping white space from the
 * start and end of lines, skipping blank lines, and treating any line that
 * starts with "#" as a comment (and thus skipped).
 *
 * The template type is an enumeration of the possible commands.
 */
template <class T>
class CLineCommandParser : public CLxLineParser
{
public:
    typedef struct st_CommandName
    {
        T           cmd;
        const char* str;
    } CommandName;

    bool lp_IsComment() override
    {
        return line_buf[0] == '#';
    }
    bool lp_StripWhite() override
    {
        return true;
    }
    bool lp_SkipBlank() override
    {
        return true;
    }

    std::string  ln_command;
    CommandName* cmd_table;

    /*
     * Lines that end with "\" are continuation lines.  We strip the character
     * and return true.
     */
    bool lp_Continue() override
    {
        size_t len = strlen(line_buf);

        if (!len || line_buf[len - 1] != '\\')
            return false;

        line_buf[len - 1] = 0;
        return true;
    }

    /*
     * Reading a line sets the command string pointer by advancing past the
     * first non-blank thing on the line and then pinching off the string.
     */
    bool lp_ReadLine(bool force = false) override
    {
        if (!CLxLineParser::lp_ReadLine(force))
            return false;

        PullWhite();
        PullNonWhite(ln_command);
        PullWhite();

        return true;
    }

    /*
     * Return a code for the current command.
     */
    T Command()
    {
        CommandName* t;

        for (t = cmd_table; t->str; t++)
            if (stricmp(ln_command.c_str(), t->str) == 0)
                return t->cmd;

        return t->cmd;
    }

    /*
     * Pull a vector of known size.
     */
    bool PullVec(float* vec, int n, double unitScale = 1.0)
    {
        int i;

        for (i = 0; i < n; i++)
        {
            if (!PullNum(vec + i))
                return false;

            vec[i] *= static_cast<float>(unitScale);
        }

        return true;
    }

    bool PullVec(double* vec, int n, double unitScale = 1.0)
    {
        int i;

        for (i = 0; i < n; i++)
        {
            if (!PullNum(vec + i))
                return false;

            vec[i] *= unitScale;
        }

        return true;
    }

    /*
     * Pull an atom as a string. If we see escape sequences we recognize
     * we convert them.
     */
    bool PullAtom(std::string& atom)
    {
        unsigned char* x;
        char           tmp;

        atom.erase();
        while (*cur_pos)
        {
            x = (unsigned char*) cur_pos;
            if (x[0] == '_' && (x[1] >= '0' && x[1] <= '9') && (x[2] >= '0' && x[2] <= '9') && (x[3] >= '0' && x[3] <= '9'))
            {
                tmp = (x[1] - '0') * 100 + (x[2] - '0') * 10 + (x[3] - '0');
                if (tmp >= 32 && tmp < 127)
                    cur_pos += 4;
                else
                    tmp = *cur_pos++;
            }
            else
                tmp = *cur_pos++;

            atom.append(1, tmp);
        }
        return (atom.length() > 0);
    }
};
