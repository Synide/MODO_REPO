/*
 * INITIALIZER.CPP	Shader entry points.
 *
 *	Copyright 0000
 */
#include <lx_plugin.hpp>

namespace Halftone_Shader
{
    extern void initialize();
    extern void cleanup();
};  // namespace Halftone_Shader

void initialize()
{
    Halftone_Shader ::initialize();
}

void cleanup()
{
    //	Halftone_Shader     ::cleanup ();
}
