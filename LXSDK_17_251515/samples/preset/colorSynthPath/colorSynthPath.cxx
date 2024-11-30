/*
 * Color SynthPath.
 *
 * Copyright 0000
 */

#include "colorSynthPath.hxx"

#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>

/*
void color_GetMessage (const char *table, const char *entry, int index, char *def, char *buf, unsigned len)
{
        CLxUser_MessageService	 msgSVC;
        CLxUser_Message		 msg;

        msgSVC.NewMessage (msg);
        if (msg.SetMessage (table, entry, index) != LXe_OK) {
                buf = def;
                return;
        }

        msgSVC.MessageText (msg, buf, len);
}
*/

// This simple wrapper function just calls PresetBrowserSerivce::Rescan() for our root.
void PresetBrowserRescan(const char* /*path*/)
{
    CLxUser_PresetBrowserService pbSVC;
    pbSVC.Rescan(COLORPRESET_SYNTH ":");
}

// Sanatize a string for use in a path by removing colons and slashes.
static std::string sanatizeString(std::string in)
{
    std::string        out;
    std::istringstream iss(in);
    char               c;

    while (iss.get(c))
    {
        if (c == ':')
        {
            // Replace colons with spaces (drive separators aren't valid in paths)
            out += ' ';
            continue;
        }

        if ((c == '/') || (c == '\\'))
        {
            // Replace slashes with bars (path separators aren't valid in paths)
            out += '|';
            continue;
        }

        // Any other character; add it to the string
        out += c;
    }

    return out;
}

/////////////////////////////////////////////////////
// ColorPBSynthetic

static ColorPBSynthetic* globalSynth = nullptr;  // There is only one instace of a synthetic, so we can just store this in a global and treat it like
                                                 // a singleton.

CLxPolymorph<ColorPBSyntheticEntry> ColorPBSynthetic::entryFactory;

ColorPBSynthetic::ColorPBSynthetic() : root(nullptr)
{
    // Store ourselves in the global for ease of access.  This works because there is only ever one instance of the synthetic server.
    globalSynth = this;
}

// Allocate a new entry given a path and a username, and if it should be a directory or a file.
// The name argument is the display name, and will be sanatized into "name" without illegal characters
// for use as a path component.
ColorPBSyntheticEntry* ColorPBSynthetic::AllocEntry(const char* path, const char* name, bool isFile)
{
    ColorPBSyntheticEntry* entry;
    LXtObjectID            obj;

    entry              = entryFactory.Alloc(&obj);  // Create an instance for our new entry
    entry->path        = path;                      // Path to this file, without the filename
    entry->displayName = name;                      // Display name of the file
    entry->name        = sanatizeString(name);      // Sanatized name of the file, usable as a filename

    entry->isFile = isFile;  // True if we're a file instead of a folder
    entry->obj    = obj;     // Our COM object

    return entry;
}

// Convenience function to get an instance of our entry class given an ILxUnknown
ColorPBSyntheticEntry* ColorPBSynthetic::ExtractEntry(ILxUnknownID obj)
{
    CLxLoc_DirCacheSyntheticEntry entry(obj);
    return entryFactory.Cast(entry);
}

// This returns an entry that matches a path inside the parent.  The path
// is relative to the parent.  If it's not found in the current parent,
// it tests the child folders until it finds a match or runs out of paths.
ColorPBSyntheticEntry* SynthGetEntry(ColorPBSyntheticEntry* parent, std::string& path)
{
    std::string strPath(path), entName(parent->name);
    unsigned    i, n = static_cast<unsigned>(parent->dirs.size());

    // Check parent directory itself
    ColorPBSyntheticEntry* sub{};
    std::size_t            s_id = path.find("/");
    if (s_id != std::string::npos)
    {
        for (i = 0; i < n; i++)
        {
            sub = parent->dirs.at(i);
            if (!path.compare(0, s_id, sub->name))
                break;
        }

        // Not found; check next directory
        path.erase(0, s_id + 1);
        return i == n ? nullptr : SynthGetEntry(sub, path);
    }

    // Path is terminated by "...directory/" (as in, the entry defined by parent), return parent itself
    if (!path.length())
        return parent;

    // Path is terminated by ".../entry" (as in, an entry in parent), return that entry, which may be a dir or file
    n = static_cast<unsigned>(parent->dirs.size() + parent->files.size());
    for (i = 0; i < n; i++)
    {
        if (i < parent->dirs.size())
            sub = parent->dirs.at(i);
        else
            sub = parent->files.at(i - parent->dirs.size());

        if (!path.compare(sub->name))
            return sub;
    }

    // Not found
    return nullptr;
}

// Create the root item.  This has the path of [ColorPB]: and identifies as a directory.
// For testing purposes it adds three dummy presets in the root, "red", "green" and "blue".
ColorPBSyntheticEntry* createRoot()
{
    ColorPBSyntheticEntry *root, *red, *green, *blue;
    std::string            path(COLORPRESET_SYNTH);
    path.append(":");

    // For Test: Simply add Red, Green, Blue
    root  = ColorPBSynthetic::AllocEntry(COLORPRESET_SYNTH, "", false);  // The root, at [ColorPB]:
    red   = ColorPBSynthetic::AllocEntry(path.c_str(), "red", true);     // Red preset, at [ColorPB]:red
    green = ColorPBSynthetic::AllocEntry(path.c_str(), "green", true);   // Green preset, at [ColorPB]:green
    blue  = ColorPBSynthetic::AllocEntry(path.c_str(), "blue", true);    // Blue preset, at [ColorPB]:blue

    red->color[0]   = 1.;
    red->color[1]   = 0.;
    red->color[2]   = 0.;
    green->color[0] = 0.;
    green->color[1] = 1.;
    green->color[2] = 0.;
    blue->color[0]  = 0.;
    blue->color[1]  = 0.;
    blue->color[2]  = 1.;

    root->files.push_back(red);
    root->files.push_back(green);
    root->files.push_back(blue);

    return root;
}

// Find a preset in the hierarchy given a path.  This walks the hierarchy until a match
// is found, return the AddRef()'ed object or failing with NOTFOUND.
LxResult ColorPBSynthetic::dcsyn_Lookup(const char* path, void** ppvObj)
{
    if (!root)
        root = createRoot();

    std::string strPath(path);
    if (!strPath.length() || !root)
        return LXe_NOTFOUND;

    // Check that the path starts with ColorSynthPath
    if (strPath.compare(0, root->path.length(), root->path))
        return LXe_NOTFOUND;

    // Paths starting with "[COLORPRESET_NAME]" or "[COLORPRESET_NAME]:" return the root entry
    if (strPath.length() == root->path.length() || (strPath.length() == root->path.length() + 1 && strPath[root->path.length()] == ':'))
        return dcsyn_Root(ppvObj);

    // Remove the synthetic ("[COLORPRESET_NAME]:") from the path
    std::size_t s_id = strPath.find(":");
    if (s_id == std::string::npos)
        return LXe_NOTFOUND;

    strPath.erase(0, s_id + 1);

    // Find the entry
    ColorPBSyntheticEntry* entry = SynthGetEntry(root, strPath);
    if (!entry)
        return LXe_NOTFOUND;

    // Found; return it
    *ppvObj = entry->obj;
    lx::ObjAddRef(*ppvObj);
    return LXe_OK;
}

// Returning the root entry is very simple, allocating a default one if needed.
LxResult ColorPBSynthetic::dcsyn_Root(void** ppvObj)
{
    if (!root)
    {
        // Not yet created; create it first
        root = createRoot();
        if (!root)
            return LXe_NOTFOUND;
    }

    *ppvObj = root->obj;
    lx::ObjAddRef(*ppvObj);
    return LXe_OK;
}

/////////////////////////////////////////////////////
// ColorPBSyntheticEntry

// Modification times need to be strings, and need to compare with strcmp() in such a way that
// new times test greater than older times when the synthetic is rescanned.  For simplicity,
// we just do a printf of a global counter. Set the width to 9 and pad with zeroes so that
// a string compare will always show the time as being newer.  This will eventually roll over.
// You could use the current system time converted to a string or some other heuristic instead,
// or just add more prefix characters, as long as strcmp() always treats newer strings as
// greater than older strings.
static unsigned int modTimeCur = 0;

// Update the current modification time
void ColorPBSyntheticEntry::UpdateModTime(void)
{
    std::ostringstream newModTime;

    newModTime << std::setfill('0') << std::setw(9) << modTimeCur++;
    modTime = newModTime.str();
}

// We store the path to the entry and its name separately, so we
// need to combine than and the root path to get hte full path.
LxResult ColorPBSyntheticEntry::dcsyne_Path(char* buf, unsigned int len)
{
    std::string fullPath(path);
    if (name.empty())
        // Root entry; add the colon
        fullPath.append(":");
    else
    {
        // Any other entry; append a slash if needed, and then our name
        if (fullPath.back() != ':')
            fullPath.append("/");

        fullPath.append(name);
    }

    if (len < fullPath.length())
        return LXe_SHORTBUFFER;

    memcpy(buf, fullPath.c_str(), fullPath.length() + 1);  // +1 for the terminating NUL
    buf[fullPath.length()] = 0;
    return LXe_OK;
}

// Return just the name portion of the path.  This represents the filename
// of the entry.
LxResult ColorPBSyntheticEntry::dcsyne_Name(char* buf, unsigned int len)
{
    if (len < name.length())
        return LXe_SHORTBUFFER;

    memcpy(buf, name.c_str(), name.length() + 1);  // +1 for the terminating NUL
    return LXe_OK;
}

// Get the username of a directory for display.
LxResult ColorPBSyntheticEntry::dcsyne_DirUsername(char* buf, unsigned int len)
{
    if (len < displayName.length())
        return LXe_SHORTBUFFER;

    memcpy(buf, displayName.c_str(), displayName.length() + 1);  // +1 for the terminating NUL
    return LXe_OK;
}

// Get the number of files/dirs inside a directory.  listMode is one of
// LXvDCELIST_DIRS, LXvDCELIST_FILES or LXvDCELIST_BOTH.  Since BOTH
// resolves to DIRS | FILES, we just just test the bits.
unsigned ColorPBSyntheticEntry::dcsyne_DirCount(int listMode)
{
    unsigned n = 0;

    if (listMode & LXvDCELIST_DIRS)
        n += static_cast<unsigned>(dirs.size());
    if (listMode & LXvDCELIST_FILES)
        n += static_cast<unsigned>(files.size());

    return n;
}

// Get a child entry in a directory given an index and a listMode.
// We return dirs then files when in BOTH mode.
LxResult ColorPBSyntheticEntry::dcsyne_DirByIndex(int listMode, unsigned index, void** ppvObj)
{
    // Safety check
    if (index >= dcsyne_DirCount(listMode))
        return LXe_OUTOFBOUNDS;

    // Find the entry in the dirs/files lists
    ColorPBSyntheticEntry* sub;
    if ((listMode & LXvDCELIST_DIRS) && (index < dirs.size()))
        sub = dirs.at(index);
    else if (listMode & LXvDCELIST_FILES)
        sub = files.at(index - dirs.size());
    else
        return LXe_FAILED;

    // Return the entry
    *ppvObj = sub->obj;
    lx::ObjAddRef(*ppvObj);
    return LXe_OK;
}

// Return true if this is a file, and false if it's a directory
LxResult ColorPBSyntheticEntry::dcsyne_IsFile()
{
    return isFile ? LXe_TRUE : LXe_FALSE;
}

// Return the "file size".  We don't have a size, so we just return 0.0.
// We use doubles to allow for sizes larger than 4 GB; we don't actually
// expect fractional file sizes.
double ColorPBSyntheticEntry::dcsyne_Size()
{
    return 0.0;
}

// Return the modification time string.  Returning an empty string
// will cause the entry to not be displayed.
LxResult ColorPBSyntheticEntry::dcsyne_ModTime(char* buf, unsigned int len)
{
    if (len < 16)
        return LXe_SHORTBUFFER;

    memcpy(buf, modTime.c_str(), modTime.length() + 1);  // +1 for the terminating NUL

    return LXe_OK;
}

/////////////////////////////////////////////////////
// ColorPresetType

CLxPolymorph<ColorPresetMetrics> ColorPresetType::metricFactory;

// Recognize just claims any preset whose path starts with [ColorPB]:
LxResult ColorPresetType::ptyp_Recognize(const char* path, const char** category)
{
    std::string strPath(path);

    // Recognize paths starting with [ColorPB]:
    if (!strPath.length() || strPath.compare(0, 9, COLORPRESET_SYNTH))
        return LXe_FALSE;

    // Set the category
    *category = COLORPRESET_SYNTH;
    return LXe_TRUE;
}

// When double-clicked or run through preset.do, this is called to apply the color.  We simply
// call color.hdrValue for each of the RGB components, which automatically sets the color on
// whatever target is selected by the user (this is the same as would be targetted by the color
// picker itself).  We do this from a command block so that  it looks like a single call to the
// command history, and thus can be undone with one ctrl-z.
LxResult ColorPresetType::ptyp_Do(const char* path)
{
    // Find the entry given its path
    LXtObjectID obj;
    if (LXx_FAIL(globalSynth->dcsyn_Lookup(path, &obj)))
        return LXe_NOTFOUND;

    ColorPBSyntheticEntry* entry = ColorPBSynthetic::ExtractEntry(static_cast<ILxUnknownID>(obj));
    if (!entry)
        return LXe_NOTFOUND;

    // Open the command block
    CLxUser_CommandService cs;
    cs.BlockBegin("Do ColorPB Preset", LXfCMDBLOCK_UI);  // Should really be from a message table in the form of @table@message@.  The UI flag is
                                                         // promoted to UNDO as needed when undoable commands are fired

    // Execute each of our color.hdrValue commands in turn
    for (int i = 0; i < 3; i++)
    {
        std::stringstream command;
        command << "color.hdrValue axis:" << i << " value:" << entry->color[i];
        if (LXx_FAIL(cs.ExecuteArgString(LXiCMD_EXEC_WITH_PARENTS_FLAGS, LXiCTAG_NULL, command.str().c_str())))
            break;
    }

    // Close the command block
    cs.BlockEnd();

    return LXe_OK;
}

// Generating metrics is only needed if the previous metrics provided to us are non-NULL.  Our
// metrics don't change, so if non-NULL we can just reutrn the previous metrics again.  If there
// are no previous metrics, we create new metrics and return those instead.
//
// The flags indicates the kind of information request by the dir cache.  If LXiPBMETRICS_THUMBNAIL_IMAGE
// is set, the metrics should either contain or be able to return a thumbnail image.  In other
// cases only BASIC_INFO may be set, in which case the thumbnail isn't required and only basic
// metadata is expected.  If EXTRA_ATTRIBUTES is set, all markup and metada are expected to be
// available from this metrics object.
//
// w/h is the size of the thumbnail that should be stored in the metrics object when the THUMBNAIL_IMAGE
// flag is set.  Returning an iamge that is too large will cause the browser to resize it itself.
// Returning one too small will result in that smaller image being used; it will not be scaled up.
//
// In our case, we have a very simple object so we always return the same metrics object
// irrespective of the flags, generating the thumbnail on the fly from the metrics object.
// itself.
LxResult ColorPresetType::ptyp_Metrics(const char* path, int flags, int w, int h, ILxUnknownID prevMetrics, void** ppvObj)
{
    if (prevMetrics)
    {
        // We already created metris, so just return those if the thumbnail requirements match
        ColorPresetMetrics* pm = metricFactory.Cast(prevMetrics);

        if (!(flags & LXiPBMETRICS_THUMBNAIL_IMAGE) || ((pm->w == w) && (pm->h == h)))
        {
            // Either we don't need a thumbnail, or we have a matching thumbnail already; reutrn prevMetrics
            lx::ObjAddRef(prevMetrics);
            *ppvObj = prevMetrics;
            return LXe_OK;
        }
    }

    // Find our entry
    LXtObjectID obj;
    if (LXx_FAIL(globalSynth->dcsyn_Lookup(path, &obj)))
        return LXe_NOTFOUND;

    ColorPBSyntheticEntry* entry = ColorPBSynthetic::ExtractEntry(static_cast<ILxUnknownID>(obj));
    if (!entry)
        return LXe_NOTFOUND;

    lx::ObjRelease(obj);  // We have to release it oursel here, as we called Lookup() ourself

    // Create the new metrics.  We cache w/h and allocate the image when one is requested, rather than doing it right now
    ColorPresetMetrics* metrics = metricFactory.Alloc(ppvObj);
    metrics->entry              = entry;
    metrics->w                  = w;
    metrics->h                  = h;

    // Populate metrics->metadata with LXsPBMETA_ entries (see the Preset Browser docs).
    //  For this we spawn a dynamic attributs object, then add our attributes to it as
    //  strings, storing the final COM object in metrics->metadata.
    CLxSpawnerCreate<CLxDynamicAttributes> spawner("colorPB_metadata");
    if (spawner.created)
        spawner.AddInterface(new CLxIfc_Attributes<CLxDynamicAttributes>);

    CLxDynamicAttributes* metadataWrap = spawner.Alloc(&metrics->metadata);

    metadataWrap->dyna_Add(LXsPBMETA_LABEL, LXsTYPE_STRING);  // Label displayed on the thubmnail.  If ommitted, the filename is used instead
    metadataWrap->attr_SetString(0, entry->displayName.c_str());

    std::ostringstream caption;
    caption << entry->color[0] << ", " << entry->color[1] << ", " << entry->color[2];
    metadataWrap->dyna_Add(LXsPBMETA_CAPTION, LXsTYPE_STRING);  // Caption/description string displayed at the bottom of the thumbnail
    metadataWrap->attr_SetString(1, caption.str().c_str());

    if (!entry->tooltip.empty())
    {
        metadataWrap->dyna_Add(LXsPBMETA_TOOLTIP, LXsTYPE_STRING);  // Tooltip displayed on a hover over the thumbnail
        metadataWrap->attr_SetString(2, entry->tooltip.c_str());
    }

    // This just breaks thumbnails for some reason.  I need to look at it to figure out why -- Joe
    //	metadataWrap->dyna_Add( LXsPBMETA_PRESET_TYPE, LXsTYPE_STRING );			// Type of preset. Not specifically this server or preset type,
    // more what kind of preset it is, like an image or a color. 	metadataWrap->attr_SetString( 3, "color" );

    return LXe_OK;
}

// The generic thumbnail resources is defined as an image resource in the configs, and is used
// when the preset doesn't define its own thumbnail image or the image isn't ready yet.  We just
// use a generic one, but really this will likely never be called for our presets.
LxResult ColorPresetType::ptyp_GenericThumbnailResource(const char* /*path*/, const char** resourceName)
{
    *resourceName = "item.thumbnail.undefined";
    return LXe_OK;
}

/////////////////////////////////////////////////////
// ColorPresetMetrics

// This allows for per-file flags override with LXiDCFM_ flags.  The only flag currently available
//  is LXiDCFM_DYNAMIC_THUMBNAILS, and we provided that as part of our server definition, so we
//  don't need to provide it again for each file.
LxResult ColorPresetMetrics::pmet_Flags(int* flags)
{
    *flags = 0;
    return LXe_OK;
}

// Metadata is an Attributes object that contains common properties like name, caption and tooltip.
LxResult ColorPresetMetrics::pmet_Metadata(void** ppvObj)
{
    if (metadata == nullptr)
        return LXe_NOTIMPL;

    *ppvObj = metadata;
    lx::ObjAddRef(*ppvObj);

    return LXe_OK;
}

// Markup is an Attributes object with user-specific properties like star ratings and favorites.
LxResult ColorPresetMetrics::pmet_Markup(void** /*ppvObj*/)
{
    return LXe_NOTIMPL;
}

// We geenerate our own thumbnail image
LxResult ColorPresetMetrics::pmet_ThumbnailImage(void** ppvObj)
{
    // If we already have an image, just return that
    if (image.test())
    {
        *ppvObj = image;
        lx::ObjAddRef(*ppvObj);
        return LXe_OK;
    }

    // Create a new image of the requested size
    CLxUser_ImageService img_svc;
    img_svc.New(image, w, h, LXiIMP_RGBFP);
    if (!image.test())
        return LXe_NOTFOUND;

    // Fill it with a color
    CLxUser_ImageWrite writeImage(image);
    for (unsigned i = 0; i < h; i++)
    {
        for (unsigned j = 0; j < w; j++)
            writeImage.SetPixel(i, j, LXiIMP_RGBFP, entry->color);
    }

    // Return it indirectly
    *ppvObj = image;
    lx::ObjAddRef(*ppvObj);

    return LXe_OK;
}

// Return the ideal size of the thumbnail.  Since colors have no size, we return 0
// to indicate that we can accomidate any size requested.  If we used a thumbnail
// embedded in a preset file, we might return the dimensions of that thumbnail
// instead.
LxResult ColorPresetMetrics::pmet_ThumbnailIdealSize(int* idealW, int* idealH)
{
    *idealW = 0;
    *idealH = 0;

    return LXe_OK;
}

/////////////////////////////////////////////////////
// ColorCmdRebuild

// Utility command to cause the synthetic to be rebuilt from the test file.
//
// File format:
//    R G B "Name" "Tooltip"
//    "Folder Name" {
//      R G B "Name" "Tooltip"
//    }
//
// Folders can be nested.  The closing curly brace must be on its own line.
// The opening curly brace must be prefixed with the folder name on the same
// line.  On color entries, the name and toolitp are optional.  The R G B
// values are floats, usually between 0-1, although HDR values are valid.
// Quotes are optional around strings unless they have spaces in them.
//
// Note that files and dirs must be uniquely named inside their parent dir.
// We don't currently handle that case here, and just hope the text file
// doens't have any duplicates.
ColorCmdRebuild::ColorCmdRebuild()
{
    dyna_Add("colors", LXsTYPE_FILEPATH);
}

// Since std::quoted() is a C++14 thing and we're on C++11, we have our own
// utility to read a quoted string.  Returns false if we hit the end of the
// string or a C++ style comment (//).
static bool getQuoted(std::istringstream& iss, std::string& out)
{
    char c;

    // Skip leading white space
    bool foundNonWhite = false;
    while (iss.get(c))
    {
        if ((c == ' ') || (c == '\t'))
            continue;

        foundNonWhite = true;
        break;
    }

    if (!foundNonWhite)
        return false;

    if ((c == '/') && (iss.peek() == '\\'))
    {
        // Skip C++ style comments by failing
        return false;
    }

    if (c != '\"')
    {
        // No quote; just get the next word and return it
        iss.unget();
        iss >> out;
        return !out.empty();
    }

    // Read until the next quote
    bool foundEnd = false;
    while (iss.get(c))
    {
        if ((c == '\\') && (iss.peek() == '\"'))
        {
            // Escaped quote; insert the quote itself
            iss.get(c);  // Skip the quote
            out += c;
            continue;
        }

        if (c == '\"')
        {
            // Closing quote; we're done
            foundEnd = true;
            break;
        }

        // Any other character; add it to the string
        out += c;
    }

    return foundEnd;
}

void rebuild_addEntry(std::ifstream& file, ColorPBSyntheticEntry* entry)
{
    char        path[1024];  // Path of the entriy passed into this function (ie: the parent folder)
    std::string strPath;
    int         index = 1;  // Index used to generate entry names if no name was found in the file

    // Get the path from the entry
    entry->dcsyne_Path(path, 1024);  // Really should handle LXe_SHORTBUF here, and allocate a bigger buffer.  But we know our paths won't be bigger
                                     // than 1024.
    strPath.assign(path);

    // Read lines fromt efile in a loop
    std::string line;
    while (std::getline(file, line))
    {
        ColorPBSyntheticEntry* sub;  // Child file/dir that we create from this line in the file
        std::string words[3];  // The first three words from the line.  Will either be "folderName {" or "}" for a folder, or "R G B" for a color.
        std::string name, tooltip;  // Optional name and tooltip for colors

        // Create a string stream for reading from the line
        std::istringstream iss(line);

        // Read the first word and see if it's a closing brace (end of folder)
        getQuoted(iss, words[0]);
        if (words[0] == "}")
        {
            return;
        }

        // Read the next word and check for an open brace (start of folder)
        getQuoted(iss, words[1]);
        if (words[1].empty())
        {
            // Invalid; skip the line
            continue;
        }

        if (words[1] == "{")
        {
            // Folder; word[0] is the folder name, which we provide along with the path to create the new entry
            sub = ColorPBSynthetic::AllocEntry(strPath.c_str(), words[0].c_str(), false);

            // Add the entries to the folder, then push it onto our list of folders
            rebuild_addEntry(file, sub);
            entry->dirs.push_back(sub);

            continue;
        }

        // Color preset; read the next word.  We need at least three: R G B
        getQuoted(iss, words[2]);
        if (words[2].empty())
        {
            // Invalid; skip the line
            continue;
        }

        // Read the optional state
        if (getQuoted(iss, name))     // Name, which may not be present
            getQuoted(iss, tooltip);  // Tooltip, which may not be present

        if (name.empty())
        {
            // No name provided; generate a generic one
            std::ostringstream oss(name);
            oss << "Color " << index++;
        }

        // Create a new entry and set the name, color and tooltip from the words we previously read
        sub           = ColorPBSynthetic::AllocEntry(strPath.c_str(), name.c_str(), true);
        sub->color[0] = std::stof(words[0]);
        sub->color[1] = std::stof(words[1]);
        sub->color[2] = std::stof(words[2]);
        sub->tooltip  = tooltip;

        // Add the new entry to the folder entry as a child
        entry->files.push_back(sub);
    }
}

void ColorCmdRebuild::cmd_Execute(unsigned /*flags*/)
{
    ColorPBSyntheticEntry *oldRoot, *newRoot;
    std::string            path;
    attr_GetString(0, path);

    std::ifstream file;
    file.open(path);
    if (!file.is_open())
        return;

    // Rebuild the synthetic hierarchy.  We create a completely new root and swap our old
    //  global pointer for the new one.  We do call release on the old root->obj, though.
    //  Depending on if the dir cache is holding onto the object still this will either
    //  decrement the ref count or actually free the object.
    // The reason we swap root is because the dir cache may be using it from a thread.
    //  Once the hierarchy is populated and entries are returned, it's best to consider
    //  it read-only and not modify it going forwards.  If you do need to modify it,
    //  you need to use locks or atomic operations that sawp pointers.  In most cases,
    //  it's simpler just to rebuild the entire hirearchy, especially for in-memory
    //  synthetics that are fast to generate.
    newRoot = ColorPBSynthetic::AllocEntry(COLORPRESET_SYNTH, "", false);  // The root, at [ColorPB]:
    rebuild_addEntry(file, newRoot);                                       // Add the contents of the file as children of newRoot

    // Now that the new root is built, swap it in and release the old root->obj.
    oldRoot           = globalSynth->root;
    globalSynth->root = newRoot;

    lx::ObjRelease(oldRoot);

    // Tell the dir cache that our hirarchy has changed. In this case, use [ColorPB]:
    //  as the path to rescan, which in turns cans the entire hierarchy as long as
    //  the modTime is newer than the last time it was scanned.
    PresetBrowserRescan(COLORPRESET_SYNTH ":");
}

/////////////////////////////////////////////////////
// Plugin Initialize

void initialize()
{
    CLxGenericPolymorph* srv;

    // Synthetic
    srv = new CLxPolymorph<ColorPBSynthetic>;
    srv->AddInterface(new CLxIfc_DirCacheSynthetic<ColorPBSynthetic>);
    srv->AddInterface(new CLxIfc_StaticDesc<ColorPBSynthetic>);
    lx::AddServer(COLORPRESET_NAME, srv);

    // Synthetic Entries
    ColorPBSynthetic::entryFactory.AddInterface(new CLxIfc_DirCacheSyntheticEntry<ColorPBSyntheticEntry>);

    // Preset Type
    srv = new CLxPolymorph<ColorPresetType>;
    srv->AddInterface(new CLxIfc_PresetType<ColorPresetType>);
    srv->AddInterface(new CLxIfc_StaticDesc<ColorPresetType>);
    lx::AddServer(COLORPRESET_PRESETTYPE, srv);

    ColorPresetType::metricFactory.AddInterface(new CLxIfc_PresetMetrics<ColorPresetMetrics>);

    // Command
    srv = new CLxPolymorph<ColorCmdRebuild>;
    srv->AddInterface(new CLxIfc_Command<ColorCmdRebuild>);
    srv->AddInterface(new CLxIfc_Attributes<ColorCmdRebuild>);
    lx::AddServer(CMDNAME, srv);
}
