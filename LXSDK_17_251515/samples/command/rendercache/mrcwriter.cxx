/*
 * RenderCache writer
 *
 * Copyright 0000
 *
 * Simple ASCII writer for MODO render cache
 *
 */

#include "mrcwriter.hxx"

//=============================================================================
//=============================================================================
MrcWriter::MrcWriter() : m_depth(0)
{
}

//=============================================================================
//=============================================================================
MrcWriter::~MrcWriter()
{
    Close();
}

//=============================================================================
//=============================================================================
bool MrcWriter::Open(const char* filename)
{
    m_depth = 0;
    m_out.open(filename, std::ios_base::out);

    return m_out.is_open();
}

//=============================================================================
//=============================================================================
void MrcWriter::Close()
{
    m_out.close();
    m_depth = 0;
}

//=============================================================================
//=============================================================================
MrcWriter& MrcWriter::BlockBegin(const char* blockName)
{
    Ident();
    m_out << blockName << std::endl;
    Ident();
    m_out << '{' << std::endl;
    ++m_depth;

    return *this;
}

//=============================================================================
//=============================================================================
MrcWriter& MrcWriter::WriteParam(const char* name, const char* s)
{
    Ident();
    m_out << name << " : "
          << "\"" << s << "\"" << std::endl;

    return *this;
}

//=============================================================================
//=============================================================================
MrcWriter& MrcWriter::WriteParam(const char* name, const std::string& s)
{
    Ident();
    m_out << name << " : "
          << "\"" << s << "\"" << std::endl;

    return *this;
}

//=============================================================================
//=============================================================================
MrcWriter& MrcWriter::BlockEnd()
{
    --m_depth;

    // TODO: report error
    if (m_depth < 0)
        m_depth = 0;

    Ident();
    m_out << '}' << std::endl;

    return *this;
}

//=============================================================================
//=============================================================================
MrcWriter& MrcWriter::Separator()
{
    m_out << std::endl;

    return *this;
}

//=============================================================================
//=============================================================================
void MrcWriter::Ident()
{
    for (int c = 0; c < m_depth; ++c)
        m_out << "    ";
}

//=============================================================================
//=============================================================================
MrcWriter::BlockScope::BlockScope(MrcWriter& writer) : m_writer(writer)
{
}

//=============================================================================
//=============================================================================
MrcWriter::BlockScope::~BlockScope()
{
    m_writer.BlockEnd();
}
