/*
 * RenderCache writer
 *
 * Copyright 0000
 *
 * Simple ASCII writer for MODO render cache
 *
 */
#pragma once

#include <fstream>
#include <lxvmath.h>
#include <string>

//=============================================================================
/*
 * Simple class used for writing render cache as an ASCII file.
 *
 * The data is stored into file using blocks. For example:
 * RenderCache
 * {
 *	 GeoCache
 *	 {
 *		...
 *	 }
 * }
 * Each block have parameters and can have nested blocks.
 */
//=============================================================================
class MrcWriter
{
public:
    MrcWriter();
    ~MrcWriter();

    bool Open(const char* filename);
    void Close();

    MrcWriter& BlockBegin(const char* blockName);

    MrcWriter& WriteParam(const char* name, const char* s);
    MrcWriter& WriteParam(const char* name, const std::string& s);

    template <typename T>
    MrcWriter& WriteParam(const char* name, const T& t);

    template <typename T>
    MrcWriter& WriteArray(const char* name, const T* array, int count);

    MrcWriter& BlockEnd();

    // Write EOL
    MrcWriter& Separator();

    //=========================================================================
    /// Helper class
    //=========================================================================
    class BlockScope
    {
    public:
        BlockScope(MrcWriter& writer);
        ~BlockScope();

    private:
        MrcWriter& m_writer;
    };

private:
    /// Write identation
    void Ident();

    template <typename T>
    MrcWriter& operator<<(const T& t);

    std::ofstream m_out;
    int           m_depth;
};

//=============================================================================
//=============================================================================
template <typename T>
inline MrcWriter& MrcWriter::WriteParam(const char* name, const T& t)
{
    Ident();
    m_out << name << " : " << t << std::endl;

    return *this;
}

//=============================================================================
//=============================================================================
template <typename T>
inline MrcWriter& MrcWriter::WriteArray(const char* name, const T* array, int count)
{
    Ident();

    m_out << name << " : ";
    m_out << '[' << std::endl;
    ++m_depth;

    for (int c = 0; c < count; ++c)
    {
        Ident();
        m_out << array[c] << std::endl;
    }

    --m_depth;
    Ident();
    m_out << ']' << std::endl;

    return *this;
}

//=============================================================================
//=============================================================================
template <typename T>
inline MrcWriter& MrcWriter::operator<<(const T& t)
{
    m_out << t;

    return *this;
}

//=============================================================================
//=============================================================================
inline std::ostream& operator<<(std::ostream& out, const LXtBBox& bbox)
{
    out << "[ " << bbox.min[0] << ' ' << bbox.min[1] << ' ' << bbox.min[2] << ' ' << bbox.max[0] << ' ' << bbox.max[1] << ' ' << bbox.max[2] << ' '
        << "]";

    return out;
}

//=============================================================================
//=============================================================================
inline std::ostream& operator<<(std::ostream& out, const LXtMatrix& m)
{
    out << "[ " << m[0][0] << ' ' << m[0][1] << ' ' << m[0][2] << ' ' << m[1][0] << ' ' << m[1][1] << ' ' << m[1][2] << ' ' << m[2][0] << ' '
        << m[2][1] << ' ' << m[2][2] << ' ' << "]";

    return out;
}

//=============================================================================
//=============================================================================
inline std::ostream& operator<<(std::ostream& out, const LXtVector& v)
{
    out << "[ " << v[0] << ' ' << v[1] << ' ' << v[2] << ' ' << "]";

    return out;
}

//=============================================================================
//=============================================================================
inline std::ostream& operator<<(std::ostream& out, const LXtVector2& v)
{
    out << "[ " << v[0] << ' ' << v[1] << ' ' << "]";

    return out;
}

//=============================================================================
//=============================================================================
inline std::ostream& operator<<(std::ostream& out, const LXtFVector& v)
{
    out << "[ " << v[0] << ' ' << v[1] << ' ' << v[2] << ' ' << "]";

    return out;
}

//=============================================================================
//=============================================================================
inline std::ostream& operator<<(std::ostream& out, const LXtFVector2& v)
{
    out << "[ " << v[0] << ' ' << v[1] << ' ' << "]";

    return out;
}
