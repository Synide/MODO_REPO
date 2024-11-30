/*
 * Plug-in Color Presets.
 *
 * Copyright 0000
 */

#pragma once

#include <lx_image.hpp>
#include <lx_pretype.hpp>

#include <lxw_dirbrowse.hpp>

#include <lxu_command.hpp>

#include <vector>

// A DirCacheSynthetic is a way to present arbitrary content in the dir cache (and thus the preset browser) without
// having to reference files that exist on disk.  The server defines a "synthetic" directectory structure containing
// "files".  Synthetics can be identified by their root path, which is always "[servername]:".
//
// A synthetic is often defined by some list of data, such as entries in a text file, items in a scene (such as the
// [clipItems]: synthetic built into modo, which simply lists clip items), item types in the app (such as the ones
// for mesh ops, scene items, and so on), or from a web server (such as the cloud assets synthetic built into modo).
// To the user and to the preset browser, these look like files on disk and are all handled in pretty much the same
// way.
//
// The synthetic provides methods to access the files as a directory structure similar to a file system, as
// represented by synthetic entries (the DirCachSyntheticEntry class).  The Root() method returns the entry
// with the [servername]: path, which can be used to walk the entire hierarchy.  The Lookup() method provides
// a way to get entries given their full path.  Forward slashes are used to separate directories.
// For example: "[servername]:dir/subdir/file.ext"
//
// Entries provide modification times, paths, names for display, and in the case of directories a list of
// child entries.
//
// If the hierarchy changes, the contents can be refreshed by calling PresetBrowserService::Rescan( "(serverName]:" )
// (or a more specific path, if only part of the hierarchy has changed).  However, the scan will only actually
// process those paths if the modtime is larger than the old modtime as tested by a string compare.  Because
// modtimes are strings, they can be arbitrary.  Incrementing a number is common, but it must be prefixed with
// zeroes for the strcmp() to work properly.  This means that you cannot just use "9" as the old modtime and
// "10" as the new one, because "1" is less than "9".  You can work around this by using the "%9u" printf()
// specifier, which will ensure the string is at least 9 characters long, prefixing with 0s as needed.
//
// Note that the synthetic and its entries only define the hierarchy.  You still need a preset server to
// recognize the "files", just like you would for files on disk.

#define COLORPRESET_NAME       "ColorPB"                      // Our synthetic server's name, and the base name for our other servers
#define COLORPRESET_ENTRYNAME  COLORPRESET_NAME "Entry"       // ColorPBSyntheticEntry: A single "directory" or "file" in the synthetic hierarhcy
#define COLORPRESET_PRESETTYPE COLORPRESET_NAME "PresetType"  // ColorPBPresetType:  The server that handles our synethtic entries as presets
#define COLORPRESET_PRESETMETRICS \
    COLORPRESET_NAME "Metrics"  // ColorPBPrsetMetrics: The server that provides metadata and thumbnails for our syntehtic entries through the preset
                                // server

#define COLORPRESET_SYNTH \
    "[" COLORPRESET_NAME "]"  // All synthetic paths start with [servername]:. The part inside the square braces must match the name of the server.

/////////////////////////////////////////////////////
// ColorPBSynthetic
// Synthetic Cache is managing the different entries, from the root path of of [ColorPB]:. Entries are ColorPBSyntheticEntry instances.
// Synthetics are only instanced once.

class ColorPBSyntheticEntry;
class ColorPBSynthetic : public CLxImpl_DirCacheSynthetic
{
public:
    static LXtTagInfoDesc descInfo[];

    static CLxPolymorph<ColorPBSyntheticEntry> entryFactory;

    // Get the ColorPBSyntheticEntry from its obj
    static ColorPBSyntheticEntry* AllocEntry(const char* path, const char* name, bool folder);
    static ColorPBSyntheticEntry* ExtractEntry(ILxUnknownID obj);

    ColorPBSynthetic();

    // Lookup for Synthetic Entry from Path.  The path will always start with [ColorPB]:, or else it wouldn't be in our hierarchy
    LxResult dcsyn_Lookup(const char* path, void** ppvObj) override;
    // Get Synthetic Path Root, which matches the path [ColorPB]:
    LxResult dcsyn_Root(void** ppvObj) override;

    ColorPBSyntheticEntry* root;  // Our root entry, with the path [ColorPB]:
};

LXtTagInfoDesc ColorPBSynthetic::descInfo[] = { { LXsDCSYNTH_BACKING, LXsDCSYNTH_BACKING_MEMORY }, { nullptr } };

/////////////////////////////////////////////////////
// ColorPBSyntheticEntry
// Synthetic Cache Entry is handling each entry

class ColorPBSyntheticEntry : public CLxImpl_DirCacheSyntheticEntry
{
public:
    ColorPBSyntheticEntry()
    {
        UpdateModTime();
    }

    ~ColorPBSyntheticEntry()
    {
        // Free our file and dir lists
        while (files.size())
        {
            lx::ObjRelease(files.back()->obj);
            files.pop_back();
        }

        while (dirs.size())
        {
            lx::ObjRelease(dirs.back()->obj);
            dirs.pop_back();
        }
    }

    // Entry path.  Always starts with "[ColorPB]:"
    LxResult dcsyne_Path(char* buf, unsigned int len) override;
    // Entry name: name of the preset or the directory.  Directories must be separated with forward slashes.
    LxResult dcsyne_Name(char* buf, unsigned int len) override;
    // Entry DirUsername: username of the directory as seen in preset browser
    LxResult dcsyne_DirUsername(char* buf, unsigned int len) override;
    // Entry DirCount: number of sub entry for the directory
    unsigned dcsyne_DirCount(int listMode) override;
    // Entry DirByIndex: get sub entry for the directory
    LxResult dcsyne_DirByIndex(int listMode, unsigned index, void** ppvObj) override;

    // Entry IsFile: is entry a directory or a file. Return LXe_TRUE (file) or LXe_FALSE (directory).
    LxResult dcsyne_IsFile(void) override;
    // Entry Size:  This is the file size in bytes, mostly for informational purposes
    double dcsyne_Size(void) override;
    // Entry ModTime: check the time in order to know if the entry has changed.
    LxResult dcsyne_ModTime(char* buf, unsigned int len) override;

    // Update the mod time to now
    void UpdateModTime(void);

    std::string path;         // Our path, which always starts with "[ColorPB]:".  Does not include the filename.
    std::string name;         // Our name.  This has been sanatized (colons and slashes removed) for use in a path.
    std::string displayName;  // The name without the colons and slashes removed
    std::string tooltip;      // Optional tooltip string
    bool        isFile;       // If we're a folder or a file
    std::string modTime;      // "Time" since we were last modified, represented as s string that counts up from 0.

    // Children
    std::vector<ColorPBSyntheticEntry*> files;  // Files in this directory.  Always empty when isFile is true.
    std::vector<ColorPBSyntheticEntry*> dirs;   // Subdirs in this directory.  Always empty when isFile is true.

    // Entry Data
    LXtColorRGB color;  // The color represented by the entry
    LXtObjectID obj;    // An instance of the ILxDirCacheSyntheticEntry that wraps this object
};

// The preset type for a synthetic is just like one for an on-disk preset.  We only recognize presets that start
// with our root path, [ColorPB]:.  There's no need to look at the contents of the "file", because anything in
// that path is by definition ours.

/////////////////////////////////////////////////////
// ColorPresetType

class ColorPresetMetrics;
class ColorPresetType : public CLxImpl_PresetType
{
public:
    static LXtTagInfoDesc                   descInfo[];
    static CLxPolymorph<ColorPresetMetrics> metricFactory;

    // Recognize: Recongnize if the path is a ColorPresetType.  Mostly just checks if the path starts with [ColorPB]:
    LxResult ptyp_Recognize(const char* path, const char** category) override;
    // Do: Compute the Do when preset.do is run, such as when double-clicking on the preset in the Preset Browser
    LxResult ptyp_Do(const char* path) override;
    // Metrics: Metrics used by the preset, such as the thumbnail, username, description/caption and metadata.
    LxResult ptyp_Metrics(const char* path, int flags, int w, int h, ILxUnknownID prevMetrics, void** ppvObj) override;
    // Generic Thumbnail: Used Thumbnail in generic case where the file doesn't have one of its own
    LxResult ptyp_GenericThumbnailResource(const char* path, const char** resourceName) override;
};

LXtTagInfoDesc ColorPresetType::descInfo[] = { { LXsSRV_USERNAME, "Colors (Synth)" },  // Username of the preset browser.  Really should be a message
                                                                                       // table lookup in the form of @table@message@
                                               { LXsPBS_CATEGORY, COLORPRESET_NAME },  // Preset Category
                                               { LXsPBS_CANAPPLY, "false" },  // Does not support Apply() (legacy; replaced with ILxDrop servers)
                                               { LXsPBS_CANDO, "true" },  // Supports Do() (double-clicking on the preset in a Preset Browser, which
                                                                          // fires the preset.do command)
                                               { LXsPBS_DYNAMICTHUMBNAILS, "true" },  // Thumbnail is dynamic; do not cache it to disk and always ask
                                                                                      // for a new thumbnail
                                               { LXsPBS_SYNTHETICSUPPORT, "true" },   // Supports synthetic paths.  If false, this only works on real
                                                                                      // files on disk.
                                               { nullptr } };

// Metrics return specific information for a given preset.  This includes the metadata (name/description/capation)
// metadata and markup.  Metadata is defined as being an inherent property of the file, such as its name, author,
// creation date and so on, while markup is defined by the user of the preset, such as star ratings or favoriting.

/////////////////////////////////////////////////////
// ColorPresetMetrics

class ColorPresetMetrics : public CLxImpl_PresetMetrics
{
public:
    ColorPresetMetrics() : entry(nullptr), w(0), h(0), metadata(nullptr)
    {
        ;
    }

    ~ColorPresetMetrics()
    {
        // We have to release our metdata on destruction
        if (metadata != nullptr)
            lx::ObjRelease(metadata);
    }

    LxResult pmet_Flags(int* flags) override;              // Optional flags.  We don't return anything special here
    LxResult pmet_Metadata(void** ppvObj) override;        // Attributes object containing intrinsic state (name, caption, etc)
    LxResult pmet_Markup(void** ppvObj) override;          // Attributes object represeting user-defined state (star ratings, favoriting, etc)
    LxResult pmet_ThumbnailImage(void** ppvObj) override;  // Image object representing the thumbnail for the file
    LxResult pmet_ThumbnailIdealSize(int* idealW, int* idealH) override;  // Ideal size of the thumbnail, beyond which the preset browser
                                                                          // won't request a larger one.  Returning 0,0 means we can generate
                                                                          // arbitrarily large images

    ColorPBSyntheticEntry* entry;  // The entry these metrics are from
    CLxUser_Image          image;  // Our generated thumbnail, or NULL if not yet generated
    int                    w, h;   // Dimensions of the generated thumbnail, or 0,0 if not generated
    void* metadata;  // ILxAttributes object representing the metadata about our entry (name, tooltip, etc).  Must be lx::ObjRelease()ed on
                     // destruction
};

// The rebuild command is mostly for testing, and causes color file to be reloaded into the
// synthetic hierarchy, after which a PresetBrowserService::Rescan() call asks the dir cache
// to ask the synthetic for the updated hierarchy.

/////////////////////////////////////////////////////
// ColorCmdRebuild

#define CMDNAME "colorPB.rebuild"

class ColorCmdRebuild : public CLxBasicCommand
{
public:
    ColorCmdRebuild();

    int basic_CmdFlags() override
    {
        return LXfCMD_UI;
    }  // Refreshing is a UI operation, so we use the UI flag for our command

    void cmd_Execute(unsigned int flags) override;  // Called to when the command is fired to actually load the target file and recreate the hierarchy
};
