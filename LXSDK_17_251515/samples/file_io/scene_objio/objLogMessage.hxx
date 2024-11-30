#pragma once

// Log Messages
//
//   Copyright 0000

#include <lxu_log.hpp>

#include <string>

/*
 * Custom log messages.
 */
class OBJLogMessage : public CLxLuxologyLogMessage
{
public:
    const char* GetFormat() override
    {
        return "Wavefront Object";
    }

private:
    std::string authoringTool;
};
