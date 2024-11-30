/*
 * FMTGEO.CPP	Plug-in Loader for GEO format text object files
 *
 * Copyright 0000
 *
 * This is close to the simplest possible scene loader & saver.  The format
 * consists of a list of point locations followed by faces built from those
 * points.  There is also a color number which in most cases is an RGB value
 * in hex.
 */

#include <lxidef.h>
#include <lxu_math.hpp>
#include <lxu_scene.hpp>
#include <lxu_select.hpp>

#include <cstdio>
#include <list>
#include <map>
#include <string>

/*
 * ----------------------------------------------------------------
 * GEO Loader
 */

/*
 * Our parser is just a default line parser that will strip white space from
 * the start and end of lines and skip blank lines.
 */
class CGEOParser : public CLxLineParser
{
public:
    bool lp_StripWhite() override
    {
        return true;
    }
    bool lp_SkipBlank() override
    {
        return true;
    }
};

/*
 * Our loader is a subclass of the CLxSceneLoader utility class, where we have
 * overloaded the recognition and parsing methods.  It's also its own parser,
 * which we return through the sl_Parser() method.
 */
class CGEOLoader : public CLxSceneLoader, public CGEOParser
{
public:
    CLxFileParser* sl_Parser() override
    {
        return this;
    }

    bool sl_Recognize() override;
    bool sl_ParseInit() override;
    bool sl_ParseDone() override;
    bool sl_Parse(LxResult*) override;

    bool                   read_vrts;
    std::list<std::string> color_list;

    static LXtTagInfoDesc descInfo[];
};

/*
 * Server tags define the format of the loader, its name and file pattern.
 * Since we load a mesh we are a scene loader.
 */
LXtTagInfoDesc CGEOLoader::descInfo[] = { { LXsLOD_CLASSLIST, LXa_SCENE },
                                          { LXsLOD_DOSPATTERN, "*.geo" },
                                          { LXsSRV_USERNAME, "VideoScape GEO" },
                                          { nullptr } };

/*
 * Recognition method reads the first line and sees if it matches the
 * sync pattern.  Returns true for a match.
 */
bool CGEOLoader::sl_Recognize()
{
    return lp_ReadLine() && (strcmp("3DG1", line_buf) == 0);
}

/*
 * Parsing the recognized file (which has been reset to the start again)
 * consists of three phases.  The init method adds a mesh item to the scene
 * and reads past the sync line.
 */
bool CGEOLoader::sl_ParseInit()
{
    color_list.clear();
    read_vrts = true;

    scene_build.AddMesh();
    return lp_ReadLine();
}

/*
 * The sl_Parse() method is called as long as it returns true.
 */
bool CGEOLoader::sl_Parse(LxResult* /*error*/)
{
    unsigned    n, i, k;
    double      x, y, z;
    std::string col;

    /*
     * One EOF this will return false which will terminate parsing.
     */
    if (!lp_ReadLine())
        return false;

    /*
     * The first thing we read is the number of points.  We'll just loop
     * over that many lines here and create points for them all.  This sets
     * the flag false so that this only happens once.
     */
    if (read_vrts)
    {
        if (!PullNum(&n))
            return false;

        for (i = 0; i < n; i++)
        {
            if (!lp_ReadLine())
                return false;

            if (!PullNum(&x) || !PullNum(&y) || !PullNum(&z))
                return false;

            scene_build.AddPoint(x, y, z);
        }

        read_vrts = false;
        return true;
    }

    /*
     * On subsequent calls to sl_Parse() we process one polygon at a time.
     * We first look for the number of vertices.  Those are read one at a
     * time and a polygon is created.
     */
    if (!PullNum(&n))
        return false;

    scene_build.StartPoly(LXiPTYP_FACE);

    for (i = 0; i < n; i++)
    {
        if (!PullNum(&k))
            return false;

        scene_build.AddVertex(k);
    }

    k = scene_build.AddPolygon();

    /*
     * The final value is the color name, which we store in a list and set
     * as the material tag.
     */
    PullWhite();
    PullNonWhite(col);
    if (col.length())
    {
        color_list.push_back(col);
        scene_build.SetPolyTag(k, LXi_PTAG_MATR, col.c_str());
    }
    return true;
}

/*
 * The done method is called when parsing is complete.  We collapse the list
 * of colors that we created during parsing and create materials for them all.
 */
bool CGEOLoader::sl_ParseDone()
{
    double rgb[3];
    int    hex, i;

    color_list.sort();
    color_list.unique();

    for (auto itr = color_list.begin(); itr != color_list.end(); itr++)
    {
        hex = 0x808080;
        sscanf(itr->c_str(), "%x", &hex);
        for (i = 0; i < 3; i++)
        {
            rgb[2 - i] = (hex & 0xFF) / 255.0;
            hex        = hex >> 8;
        }

        scene_build.AddMaterial(itr->c_str());
        scene_build.SetChannel(LXsICHAN_ADVANCEDMATERIAL_DIFFCOL ".R", rgb[0]);
        scene_build.SetChannel(LXsICHAN_ADVANCEDMATERIAL_DIFFCOL ".G", rgb[1]);
        scene_build.SetChannel(LXsICHAN_ADVANCEDMATERIAL_DIFFCOL ".B", rgb[2]);
    }
    return true;
}

/*
 * ----------------------------------------------------------------
 * GEO Saver
 */

/*
 * The GEO format is just a default line format with spaces delimiting
 * elements on the same line.
 */
class CGEOFormat : public CLxLineFormat
{
public:
    const char* lf_Separator() override
    {
        return " ";
    }
};

/*
 * Out GEO saver is a subclass of the CLxSceneSaver utility, and like the
 * loader is its own format.
 */
class CGEOSaver : public CLxSceneSaver, public CGEOFormat
{
public:
    CLxFileFormat* ss_Format() override
    {
        return this;
    }

    void     ss_Verify() override;
    LxResult ss_Save() override;
    void     ss_Point() override;
    void     ss_Polygon() override;

    void GatherColors();

    static LXtTagInfoDesc descInfo[];

    LXtMatrix xfrm;
    LXtVector xfrmPos;

    std::map<LXtPointID, unsigned>  pnt_index;
    unsigned                        pnt_count;
    std::map<std::string, unsigned> matr_color;
    bool                            get_matr;
};

LXtTagInfoDesc CGEOSaver::descInfo[] = { { LXsSAV_OUTCLASS, LXa_SCENE }, { LXsSAV_DOSTYPE, "GEO" }, { LXsSRV_USERNAME, "VideoScape GEO" }, { nullptr } };

/*
 * The optional ss_Verify() method can be used to display a message to the
 * user about what will happen to their data using this format.  Ideally a
 * real message table should be used to support translation, but common
 * message 2020 allows for a general string.
 *
 * The scene could be examined at this point to determine if there was anything
 * that would be lost.
 */
void CGEOSaver::ss_Verify()
{
    Message("common", 2020);
    MessageArg(1, "GEO supports geometry from a single layer, and no texturing.");
}

/*
 * The save method performs the actual save.  Note that this is called twice;
 * first in a dummy mode with the format output disabled and then for real.  In
 * the dummy mode the WritePoints() and WritePolys() calls will not do anything
 * except tabulate how many elements would be traversed in the real case.
 *
 * Because of the multiple passes and the fact that this same instance of the
 * saver is used for all saving during a single session, all persistent state
 * should be reset between uses.
 */
LxResult CGEOSaver::ss_Save()
{
    unsigned                 npts;
    CLxUser_SelectionService selSvc;
    double                   currTime;

    currTime = selSvc.GetTime();

    /*
     * Count points in all meshes.
     */
    npts = 0;
    StartScan();
    while (NextMesh())
        npts += PointCount();

    /*
     * Tabulate the colors of all the materials.
     */
    get_matr = true;
    StartScan();
    while (NextMesh())
        WritePolys();

    GatherColors();

    /*
     * Write the sync line and the number of points.
     */
    lf_Output("3DG1");
    lf_Break();
    lf_Output(npts);
    lf_Break();

    /*
     * Write point positions.
     */
    pnt_count = 0;
    StartScan();
    while (NextMesh())
    {
        // Get world transformation
        if (!WorldXform(xfrm, xfrmPos))
        {
            lx::MatrixIdent(xfrm);
            std::fill(xfrmPos, xfrmPos + 3, 0.0);
        }

        SetMeshTime(currTime);
        WritePoints();
    }

    /*
     * Write polygons.
     */
    get_matr = false;
    StartScan();
    while (NextMesh())
    {
        SetMeshTime(currTime);
        WritePolys();
    }

    /*
     * Clear any persistent state.
     */
    matr_color.clear();
    pnt_index.clear();
    return LXe_OK;
}

/*
 * This is called for every polygon in the current mesh from WritePolys().
 * We make two passes through the polygons -- the first to collect the
 * mask tags, and the second to actually write the polygons.  Writing just
 * writes the number of vertices, the vertex indicies, and the color for
 * the polygon's material.
 */
void CGEOSaver::ss_Polygon()
{
    if (get_matr)
    {
        const char* mask = PolyTag(LXi_PTAG_MATR);
        if (mask)
            matr_color[mask] = 0;
        return;
    }

    unsigned i, n;
    char     buf[32];

    n = PolyNumVerts();
    lf_Output(n);

    for (i = 0; i < n; i++)
        lf_Output(pnt_index[PolyVertex(i)]);

    sprintf(buf, "0x%06X", matr_color[PolyTag(LXi_PTAG_MATR)]);
    lf_Output(buf);
    lf_Break();
}

/*
 * After the first pass through the polygons, we compute the color for each
 * material tag that we stored in the map.  This simply looks up the mask
 * for the tag and looks through its layers.  The first material that it finds
 * we read the diffuse color.
 *
 * This can't be done while enumerating polygons because only one item scan
 * can be performed at once and we're already scanning meshes.
 */
void CGEOSaver::GatherColors()
{
    const char* mask;
    double      rgb[3];
    unsigned    col, cmp, i;

    for (auto it = matr_color.begin(); it != matr_color.end(); it++)
    {
        mask = it->first.c_str();
        if (!ScanMask(mask))
        {
            matr_color[mask] = 0x808080;
            continue;
        }

        while (NextLayer())
        {
            if (strcmp(ItemType(), LXsITYPE_ADVANCEDMATERIAL))
                continue;

            rgb[0] = ChanFloat(LXsICHAN_ADVANCEDMATERIAL_DIFFCOL ".R");
            rgb[1] = ChanFloat(LXsICHAN_ADVANCEDMATERIAL_DIFFCOL ".G");
            rgb[2] = ChanFloat(LXsICHAN_ADVANCEDMATERIAL_DIFFCOL ".B");

            col = 0;
            for (i = 0; i < 3; i++)
            {
                if (rgb[i] <= 0.0)
                    cmp = 0;
                else if (rgb[i] >= 1.0)
                    cmp = 255;
                else
                    cmp = static_cast<int>(rgb[i] * 255 + 0.5);

                col = (col << 8) + cmp;
            }

            matr_color[mask] = col;
        }
    }
}

/*
 * This method is called for every point during WritePoints(). We write the
 * coordinates to a line and save the index of the point in our map.
 */
void CGEOSaver::ss_Point()
{
    float opos[3];
    float vec[3];

    PntPosition(opos);

    lx::MatrixMultiply(vec, xfrm, opos);
    vec[0] += static_cast<float>(xfrmPos[0]);
    vec[1] += static_cast<float>(xfrmPos[1]);
    vec[2] += static_cast<float>(xfrmPos[2]);

    lf_Output(vec[0]);
    lf_Output(vec[1]);
    lf_Output(vec[2]);
    lf_Break();

    pnt_index[PntID()] = pnt_count++;
}

/*
 * ----------------------------------------------------------------
 * Exporting Servers
 */
void initialize()
{
    LXx_ADD_SERVER(Loader, CGEOLoader, "vs_GEO");
    LXx_ADD_SERVER(Saver, CGEOSaver, "vs_GEO");
}
