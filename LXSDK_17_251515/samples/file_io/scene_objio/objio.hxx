#pragma once
/*
 * OBJ format header
 *
 *  Copyright 0000
 */

#include <lx_io.hpp>

enum UnitsType
{
    UNITS_NONE = -1,
    UNITS_M,
    UNITS_CM,
    UNITS_MM,
    UNITS_INCH,

    UNITS_COUNT
};

namespace OBJ_Options
{

    /**
     * The options object contains the settings from the user dialog about how to
     * load the file.
     */
    class CLoadOptions : public CLxImpl_StreamIO
    {
    public:
        bool as_static;                  // load meshes as static
        bool groups_as_separate_meshes;  // load groups as separate meshes
        bool ignore_ka;                  // ignore ambient color settings
        int  unitsType;                  // units used (mm,cm,m,inches)

        LxResult io_Write(ILxUnknownID stream) override;
        LxResult io_Read(ILxUnknownID stream) override;
    };

    extern bool          Recognize(const char* file);
    extern CLoadOptions* GetOptions(void);
    extern void          SpawnOptions(void**);

    /**
     * This defines its own servers so it needs init and cleanup.
     */
    extern void initialize(void);
    extern void cleanup(void);

};  // namespace OBJ_Options
