/*
 * INITIALIZER.CPP	Top-level plugin container
 *
 * Copyright 0000
 */
#include <lx_plugin.hpp>

namespace Overlay_SafeArea
{
    extern void initialize();
    extern void cleanup();
};  // namespace Overlay_SafeArea

namespace StereoViz
{
    extern void initialize();
    extern void cleanup();
};  // namespace StereoViz

void initialize()
{
    Overlay_SafeArea ::initialize();
    StereoViz ::initialize();
}

void cleanup()
{
    Overlay_SafeArea ::cleanup();
    StereoViz ::cleanup();
}
