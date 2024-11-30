/*
 * Plug-in Scene I/O: OBJ Sample
 *
 * Copyright 0000
 *
 */

#include "objio.hxx"
#include "objLoader.hxx"
#include "objpb.hxx"

#include <lxu_math.hpp>
#include <lxu_queries.hpp>
#include <lxu_select.hpp>

#include <lxlog.h>

static const char* LXsUSER_VALUE_OBJ_IMPORT_STATIC          = "sceneio.obj.import.static";
static const char* LXsUSER_VALUE_OBJ_IMPORT_SEPARATE_MESHES = "sceneio.obj.import.separate.meshes";
static const char* LXsUSER_VALUE_OBJ_IMPORT_SUPPRESS_DIALOG = "sceneio.obj.import.suppress.dialog";
static const char* LXsUSER_VALUE_OBJ_IMPORT_UNITS           = "sceneio.obj.import.units";

/*
 * ----------------------------------------------------------------
 * MTL Parser Class
 *
 * This is a line command parser recognizing MTL format commands.
 */
typedef enum en_MTLCommand
{
    CMD_MTL_UNKNOWN,
    CMD_NEW,
    CMD_AMBIENT,
    CMD_DIFFUSE,
    CMD_SPECULAR,
    CMD_OPACITY,
    CMD_TRANSPARENCY,
    CMD_SHININESS,
    CMD_ILLUM_MODE,
    CMD_MAP_DIFFUSE,
    CMD_MAP_BUMP,
    CMD_MAP_OPACITY,
    CMD_MAP_SPECULAR,
    CMD_MAP_AMBIENT,
    CMD_MAP_REFLECTION,
} MTLCommand;

/*
 * Map of texture MTL params and their number of arguments
 * used for parsing the arguments string
 *
 * Taken from: http://paulbourke.net/dataformats/mtl/
 */
typedef std::map<std::string, int> MtlParamsMap;

const MtlParamsMap::value_type mtlParams_val[] = {
    std::make_pair("-bm", 1), std::make_pair("-clamp", 1), std::make_pair("-blendu", 1), std::make_pair("-blendv", 1), std::make_pair("-imfchan", 1),
    std::make_pair("-mm", 2), std::make_pair("-o", 3),     std::make_pair("-s", 3),      std::make_pair("-t", 3),      std::make_pair("-texres", 1),
};

const MtlParamsMap mtlParams(mtlParams_val, mtlParams_val + sizeof mtlParams_val / sizeof mtlParams_val[0]);

class CMTLParser : public CLineCommandParser<MTLCommand>
{
public:
    CMTLParser()
    {
        cmd_table = mtl_cmds;
    }

    static CommandName mtl_cmds[];

    bool        Load(const char* mtlFilePath, CLxSceneBuilder& builder, COBJLoader& loader);
    double      Normalize(double col[3]);
    std::string cur_mtr;

private:
    bool GetImageMapFileName(const std::string& mapParams, std::string& dest, const MtlParamsMap& paramsMap);
    void CreateImageMap(CLxSceneBuilder& build, const std::string& filePath, const char* effect, COBJLoader& loader);
};

CMTLParser::CommandName CMTLParser::mtl_cmds[] = { { CMD_NEW, "newmtl" },          { CMD_AMBIENT, "Ka" },
                                                   { CMD_DIFFUSE, "Kd" },          { CMD_SPECULAR, "Ks" },
                                                   { CMD_OPACITY, "d" },           { CMD_TRANSPARENCY, "Tr" },
                                                   { CMD_SHININESS, "Ns" },        { CMD_ILLUM_MODE, "illum" },
                                                   { CMD_MAP_DIFFUSE, "map_Kd" },  { CMD_MAP_REFLECTION, "map_refl" },
                                                   { CMD_MAP_BUMP, "map_Bump" },   { CMD_MAP_OPACITY, "map_D" },
                                                   { CMD_MAP_SPECULAR, "map_Ks" }, { CMD_MAP_AMBIENT, "map_Ka" },
                                                   { CMD_MTL_UNKNOWN, nullptr } };

double CMTLParser::Normalize(double col[3])
{
    double max = 0.0;
    int    i;

    for (i = 0; i < 3; i++)
        if (col[i] > max)
            max = col[i];

    if (max == 0.0)
        return 0.0;

    for (i = 0; i < 3; i++)
        col[i] = col[i] / max;

    return max;
}

bool CMTLParser::GetImageMapFileName(const std::string& mapParams, std::string& dest, const MtlParamsMap& paramsMap)
{
    bool   ret;
    size_t curPos = 0;
    size_t nextPos;

    while (true)
    {
        nextPos = mapParams.find_first_of(" ", curPos);
        if (nextPos == std::string::npos)
        {
            dest = mapParams.substr(curPos, std::string::npos);
            ret  = true;
            break;
        }

        std::string                  param = mapParams.substr(curPos, nextPos - curPos);
        MtlParamsMap::const_iterator it    = paramsMap.find(param);
        if (it == paramsMap.end())
        {
            dest = mapParams.substr(curPos, std::string::npos);
            ret  = true;
            break;
        }
        else
        {
            for (unsigned i = 0; i < it->second; i++)
            {
                nextPos = mapParams.find_first_of(" ", nextPos + 1);
                if (nextPos == std::string::npos)
                {
                    ret = false;
                    break;
                }
            }
        }

        curPos = nextPos + 1;
    }

    return ret;
}

void CMTLParser::CreateImageMap(CLxSceneBuilder& build, const std::string& filePath, const char* effect, COBJLoader& loader)
{
    std::string completeFilePath = filePath;

    if (!loader.IsFileAbsolute(completeFilePath))
    {
        loader.MakeFileAbsolute(completeFilePath);
    }

    build.AddImageMap(completeFilePath.c_str(), effect);
}

bool CMTLParser::Load(const char* filename, CLxSceneBuilder& build, COBJLoader& loader)
{
    std::string matr, map;
    MTLCommand  cmd;
    double      col[3];
    bool        need;

    if (!fp_Open(filename))
        return false;

    if (fp_HasError())
        return false;

    matr = "";
    need = true;
    while (lp_ReadLine())
    {
        cmd = Command();
        if (cmd == CMD_NEW)
        {
            PullAtom(matr);
            need = true;
            continue;
        }

        if (need)
        {
            if (matr.empty())
                continue;

            build.AddMaterial(matr.c_str());
            need = false;
        }

        switch (cmd)
        {
            case CMD_AMBIENT:
                if (!PullVec(col, 3) || (OBJ_Options::GetOptions() && OBJ_Options::GetOptions()->ignore_ka))
                    break;

                build.SetChannel(LXsICHAN_ADVANCEDMATERIAL_RADIANCE, 1.0);
                build.SetChannel(LXsICHAN_ADVANCEDMATERIAL_LUMICOL ".R", col[0]);
                build.SetChannel(LXsICHAN_ADVANCEDMATERIAL_LUMICOL ".G", col[1]);
                build.SetChannel(LXsICHAN_ADVANCEDMATERIAL_LUMICOL ".B", col[2]);
                break;

            case CMD_DIFFUSE:
                if (!PullVec(col, 3))
                    break;

                build.SetChannel(LXsICHAN_ADVANCEDMATERIAL_DIFFAMT, 1.0);
                build.SetChannel(LXsICHAN_ADVANCEDMATERIAL_DIFFCOL ".R", col[0]);
                build.SetChannel(LXsICHAN_ADVANCEDMATERIAL_DIFFCOL ".G", col[1]);
                build.SetChannel(LXsICHAN_ADVANCEDMATERIAL_DIFFCOL ".B", col[2]);
                break;

            case CMD_SPECULAR:
                if (!PullVec(col, 3))
                    break;

                build.SetChannel(LXsICHAN_ADVANCEDMATERIAL_SPECAMT, 1.0);
                build.SetChannel(LXsICHAN_ADVANCEDMATERIAL_SPECCOL ".R", col[0]);
                build.SetChannel(LXsICHAN_ADVANCEDMATERIAL_SPECCOL ".G", col[1]);
                build.SetChannel(LXsICHAN_ADVANCEDMATERIAL_SPECCOL ".B", col[2]);
                break;

            case CMD_OPACITY:
                double opa;

                if (PullNum(&opa))
                    build.SetChannel(LXsICHAN_ADVANCEDMATERIAL_TRANAMT, 1.0 - opa);
                break;

            case CMD_TRANSPARENCY:
                break;

            case CMD_SHININESS:
                double exp;

                if (PullNum(&exp))
                    build.SpecExponent(exp);
                break;

            case CMD_ILLUM_MODE:
                /*illum has 3 allowed values:
                    0: only the kd value is considered, lighting disabled.
                    1: ka & kd, lighting on
                    2: ka, kd, ks, ns, lighting on */

                unsigned mode;

                if (PullNum(&mode))
                {
                    build.SetChannel(LXsICHAN_ADVANCEDMATERIAL_SMOOTH, (mode == 1) ? 0.0 : 1.0);
                }
                break;

            case CMD_MAP_DIFFUSE:
            {
                unsigned matItem = build.CurItem();

                std::string fileName;
                if (!GetImageMapFileName(cur_pos, fileName, mtlParams))
                    break;  // malformed params string

                CreateImageMap(build, fileName, LXs_FX_DIFFCOLOR, loader);

                build.SetItem(matItem);
                break;
            }

            case CMD_MAP_BUMP:
            {
                // map_bump -bm <factor> <file_name>: defines a bump mapping file.
                //    <file_name> is a b/w texture file with values representing height.
                //    <factor> is the scale factor of the height values.

                unsigned matItem = build.CurItem();

                std::string fileName;
                if (!GetImageMapFileName(cur_pos, fileName, mtlParams))
                    break;  // malformed params string

                CreateImageMap(build, fileName, LXs_FX_BUMP, loader);

                build.SetItem(matItem);
                break;
            }

            case CMD_MAP_SPECULAR:
            {
                unsigned matItem = build.CurItem();

                std::string fileName;
                if (!GetImageMapFileName(cur_pos, fileName, mtlParams))
                    break;  // malformed params string

                CreateImageMap(build, fileName, LXs_FX_SPECCOLOR, loader);

                build.SetItem(matItem);
                break;
            }

            case CMD_MAP_AMBIENT:
            {
                unsigned matItem = build.CurItem();

                std::string fileName;
                if (!GetImageMapFileName(cur_pos, fileName, mtlParams))
                    break;  // malformed params string

                CreateImageMap(build, fileName, LXs_FX_LUMICOLOR, loader);

                build.SetItem(matItem);
                break;
            }

            case CMD_MAP_OPACITY:
            {
                unsigned matItem = build.CurItem();

                std::string fileName;
                if (!GetImageMapFileName(cur_pos, fileName, mtlParams))
                    break;  // malformed params string

                CreateImageMap(build, fileName, LXs_FX_TRANAMOUNT, loader);

                build.SetChannel(LXsICHAN_TEXTURELAYER_INVERT, 1);

                build.SetItem(matItem);
                break;
            }

            case CMD_MAP_REFLECTION:
            {
                unsigned matItem = build.CurItem();
                // map_refl -type <type> <file_name>: defines a reflection map.
                //     <type> the relection type, I only know about "sphere"...

                // TODO: setup the reflection map

                build.SetItem(matItem);
                break;
            }

            default:
                break;
        }

        if (!build.IsGood())
            return false;
    }

    return !fp_HasError();
}

/*
 * ----------------------------------------------------------------
 * OBJ Parser Class Implementation
 *
 * This is a line command parser recognizing OBJ format commands.
 */

COBJParser::CommandName COBJParser::obj_cmds[] = { { CMD_VERTEX, "v" },
                                                   { CMD_TEXTURE, "vt" },
                                                   { CMD_NORMAL, "vn" },
                                                   { CMD_FACE, "f" },
                                                   { CMD_LINE, "l" },
                                                   { CMD_GROUP, "g" },
                                                   { CMD_USE_MATERIAL, "usemtl" },
                                                   { CMD_MATR_LIBRARY, "mtllib" },
                                                   { CMD_OBJECT, "o" },
                                                   { CMD_SHADOW_OBJ, "shadow_obj" },
                                                   { CMD_SMOOTHING_GROUP, "s" },
                                                   { CMD_TRACE_OBJ, "trace_obj" },
                                                   { CMD_UNKNOWN, nullptr } };

bool COBJParser::PullPolyVec(int* vec, bool* exist)
{
    if (!PullNum(vec))
        return false;

    exist[IP_VRT]  = true;
    exist[IP_UV]   = false;
    exist[IP_NORM] = false;
    if (!PullExpected('/'))
        return true;

    /*
     * Test for a slash followed by white space, which makes it a trailing slash.
     *
     * This unusual variation is written by third-party apps
     * such as Atangeo Balancer and MakeHuman.
     */
    if (IsBlank(cur_pos[0]))
    {
        return true;
    }

    if (PullNum(vec + IP_UV))
        exist[IP_UV] = true;

    if (!PullExpected('/'))
        return true;

    /*
     * Test for a slash followed by white space, which makes it a trailing slash.
     */
    if (IsBlank(cur_pos[0]))
    {
        return true;
    }

    if (PullNum(vec + IP_NORM))
        exist[IP_NORM] = true;

    return true;
}

LXtTagInfoDesc COBJLoader::descInfo[] = { { LXsLOD_CLASSLIST, LXa_SCENE },
                                          { LXsLOD_DOSPATTERN, "*.obj" },
                                          { LXsSRV_USERNAME, "Wavefront OBJ" },
                                          { nullptr } };

/*
 * Recognition is imperfect for OBJ files since there is no required sync
 * field.  We'll try reading the first 50 lines to see if they mostly contain
 * valid commands.  There have to be at least four lines for the smallest
 * OBJ we can read (three points and a triangle).
 */
bool COBJLoader::sl_Recognize()
{
    log.Setup();
    if (!OBJ_Options::Recognize(file_name))
        return false;
    log.Info("OBJ recognized.");
    return true;
}

bool COBJLoader::sl_HasOptions()
{
    CLxReadUserValue ruvUser;
    if (ruvUser.Query(LXsUSER_VALUE_OBJ_IMPORT_SUPPRESS_DIALOG))
    {
        if (ruvUser.GetInt())
        {
            return false;
        }
    }

    return true;
}

void COBJLoader::sl_SpawnOpt(void** ppvObj)
{
    OBJ_Options::SpawnOptions(ppvObj);
}

void COBJLoader::Cleanup()
{
    vrt_list.Clear();
    uv_list.Clear();
    norm_list.Clear();
    vrt_color_list.Clear();

    grp_item.clear();
    tri_list.clear();
    pnt_list.clear();
    pnt_map.clear();

    vertex_list.clear();
    vertex_color_list.clear();
    texcoord_list.clear();
    normal_list.clear();
    vertex_index_map.clear();

    material_lib_paths.clear();

    vrt_hasCol = false;
}

/*
 * Starting to parse adds a blank mesh.
 */
bool COBJLoader::sl_ParseInit()
{
    log.Setup();
    log.Info("Loading a scene.");

    Cleanup();

    // Make sure you read the user preferences once.
    staticPreference   = false;
    separatePreference = false;

    lineIndex = 0;

    isImportingTriSurf = ImportStaticMesh();

    matr_name = "";
    part_name = "";
    obj_name  = "";
    vrt_count = 0;
    no_mesh   = 1;

    has_uv       = 0;
    has_norm     = 0;
    has_vrtColor = 0;

    foundGroup = false;

    UnitsType units = ImportUnits();

    switch (units)
    {
        case UNITS_MM:
            unitScale = 1.0 / 1000.0;
            break;

        case UNITS_CM:
            unitScale = 1.0 / 100.0;
            break;

        case UNITS_INCH:
            unitScale = 1.0 / 39.3701;
            break;

        case UNITS_M:
        default:
            unitScale = 1.0;
            break;
    }

    return true;
}

/*
 * Clean up to prepare for the next load.
 */
bool COBJLoader::sl_ParseDone()
{
    /*
     * Handle the point cloud case, which consists of a list
     * of vertices that are not followed by any faces.
     */
    if ((!vertex_list.empty()) && no_mesh)
    {
        NeedMesh();
        MakeVrts();
    }

    if (isImportingTriSurf)
    {
        WriteSurf();
    }

    Cleanup();

    log.Info("OBJ loading completed.");

    return true;
}

/*
 * Each Parse() call processes a single line.  We detect the command on the line
 * and handle it, mostly doing nothing.
 */
bool COBJLoader::sl_Parse(LxResult* /*error*/)
{
    CVertex  v;
    CTexture vt;
    CNormal  vn;
    C4Vector vc;
    bool     result = false;

    if (!lp_ReadLine())
        return result;

    ++lineIndex;

    result = true;

    switch (Command())
    {
        case CMD_MATR_LIBRARY:
        {
            const char* name;
            const char *mtlLibName, *mtlLibBaseName;

            name = strrchr(file_name, '/');
            if (!name)
                name = strrchr(file_name, '\\');

            if (!name)
            {
                break;
            }

            std::string path(file_name, name - file_name + 1);

            /*
             * Check if there is a colon in the path, so
             * we can strip off the base file name.
             * (As seen in OBJ files exported by ArchiCAD.)
             */
            mtlLibName     = cur_pos;
            mtlLibBaseName = strrchr(mtlLibName, ':') + 1;
            if (mtlLibBaseName && (static_cast<size_t>(mtlLibBaseName - mtlLibName) < strlen(mtlLibName)))
            {
                mtlLibName = mtlLibBaseName;
            }

            // also need to strip off any regular path (#35012, #21769)
            mtlLibBaseName = strrchr(mtlLibName, '/') + 1;
            if (!mtlLibBaseName)
                mtlLibBaseName = strrchr(mtlLibName, '\\');
            if (mtlLibBaseName && (static_cast<size_t>(mtlLibBaseName - mtlLibName) < strlen(mtlLibName)))
            {
                mtlLibName = mtlLibBaseName;
            }

            path.append(mtlLibName);

            // Guard against repeated imports of the same material file
            if (material_lib_paths.find(path) == material_lib_paths.end())
            {
                material_lib_paths.insert(path);

                CMTLParser mtl;
                mtl.Load(path.c_str(), scene_build, *this);
            }
            break;
        }

        case CMD_OBJECT:
            if (isImportingTriSurf)
            {
                WriteSurf();
            }
            obj_name = cur_pos;
            no_mesh  = 1;
            break;

        case CMD_GROUP:
            part_name = cur_pos;

            if (ImportGroups())
            {
                obj_name   = cur_pos;
                foundGroup = true;
            }
            break;

        case CMD_USE_MATERIAL:
            PullAtom(matr_name);
            break;

        case CMD_VERTEX:
            if (isImportingTriSurf)
            {
                result = vrt_list.Read(this);

                // Read Vertex Color. It is not an error if it does not exist
                vc.f_vec[0] = vc.f_vec[1] = vc.f_vec[2] = vc.f_vec[3] = 1.0;

                // Read RGB
                if (PullVec(vc.f_vec, 3))
                {
                    // read Alpha, if present
                    if (!PullVec(&(vc.f_vec[3]), 1))
                        vc.f_vec[3] = 1.0;

                    vrt_hasCol = true;  // Has read vertex color, so
                }

                vrt_color_list.cv_list.push_back(vc);
            }
            else
            {
                if (!PullVec(v.vec, 3, unitScale))
                    return false;

                vertex_list.push_back(v);

                // Read Vertex Color. It is not an error if it does not exist
                vc.f_vec[0] = vc.f_vec[1] = vc.f_vec[2] = vc.f_vec[3] = 1.0;

                // Read RGB
                if (PullVec(vc.f_vec, 3))
                {
                    // read Alpha, if present
                    if (!PullVec(&(vc.f_vec[3]), 1))
                        vc.f_vec[3] = 1.0;

                    vrt_hasCol = true;  // Has read vertex color, so
                }

                vertex_color_list.push_back(vc);
            }
            break;

        case CMD_TEXTURE:
            if (isImportingTriSurf)
            {
                result = uv_list.Read(this);
            }
            else
            {
                if (!PullVec(vt.vec, 2))
                    return false;

                texcoord_list.push_back(vt);
            }
            break;

        case CMD_NORMAL:
            if (isImportingTriSurf)
            {
                result = norm_list.Read(this);
            }
            else
            {
                if (!PullVec(vn.vec, 3))
                    return false;

                normal_list.push_back(vn);
            }
            break;

        case CMD_FACE:
            if (!isImportingTriSurf)
            {
                if (foundGroup)
                {
                    no_mesh    = 1;
                    foundGroup = false;
                }

                NeedMesh();

                /*
                 * If importing groups as separate meshes we can't just add all the vertices to this
                 * mesh.  They are added as required.
                 */
                if (!ImportGroups())
                {
                    MakeVrts();
                }
            }
            ParseFace();
            break;
        case CMD_LINE:
            if (!isImportingTriSurf)
            {
                if (foundGroup)
                {
                    no_mesh    = 1;
                    foundGroup = false;
                }

                NeedMesh();

                /*
                 * If importing groups as separate meshes we can't just add all the vertices to this
                 * mesh.  They are added as required.
                 */
                if (!ImportGroups())
                {
                    MakeVrts();
                }
            }
            ParseLine();
            break;

        case CMD_SHADOW_OBJ:
        case CMD_SMOOTHING_GROUP:
        case CMD_TRACE_OBJ:
        case CMD_UNKNOWN:
            printf("unknown command (%s) skipped\n", cur_pos);
            break;
    }

    return result;
}

void COBJLoader::NeedMesh()
{
    if (!no_mesh)
        return;

    scene_build.AddMesh();
    if (!obj_name.empty())
        scene_build.SetName(obj_name.c_str());

    no_uv      = 1;
    no_norm    = 1;
    no_vertCol = 1;
    no_mesh    = 0;
    vertex_index_map.clear();
    vrt_base = vrt_count + 1;
}

static int GetUserInt(const char* prefKey, int defaultValue = 0)
{
    int              value = defaultValue;
    CLxReadUserValue ruvUser;
    if (ruvUser.Query(prefKey))
    {
        value = ruvUser.GetInt();
    }

    return value;
}

bool COBJLoader::ImportStaticMesh()
{
    OBJ_Options::CLoadOptions* opt;

    opt = OBJ_Options::GetOptions();
    if (!opt)
    {
        if (!staticPreference)
        {
            importStatic     = GetUserInt(LXsUSER_VALUE_OBJ_IMPORT_STATIC);
            staticPreference = true;
        }
        return importStatic;
    }
    else
    {
        return opt->as_static;
    }
}

bool COBJLoader::ImportGroups()
{
    OBJ_Options::CLoadOptions* opt;

    opt = OBJ_Options::GetOptions();
    if (!opt)
    {
        if (!separatePreference)
        {
            importSeparateMeshes = GetUserInt(LXsUSER_VALUE_OBJ_IMPORT_SEPARATE_MESHES);
            separatePreference   = true;
        }
        return importSeparateMeshes;
    }
    else
    {
        return opt->groups_as_separate_meshes;
    }
}

UnitsType COBJLoader::ImportUnits()
{
    OBJ_Options::CLoadOptions* opt;
    int                        value = -1;

    opt = OBJ_Options::GetOptions();
    if (!opt)
    {
        if (!separatePreference)
        {
            value              = GetUserInt(LXsUSER_VALUE_OBJ_IMPORT_UNITS);
            separatePreference = true;
        }
    }
    else
    {
        value = opt->unitsType;
    }

    if (value < 0 || value > UNITS_COUNT)
        return UNITS_NONE;
    else
        return (UnitsType) value;
}

void COBJLoader::MakeVrts()
{
    if (vertex_list.empty())
        return;

    for (auto vit = vertex_list.begin(); vit != vertex_list.end(); vit++)
        scene_build.AddPoint(vit->vec);

    vrt_count += static_cast<int>(vertex_list.size());
    vertex_list.clear();
}

/*
 * Map from the vertex index read from the file to the index of the point in the current mesh.
 * If importing groups as separate meshes add points to the mesh as needed, and map them.
 */
unsigned COBJLoader::MeshPointIndexForVertex(unsigned index)
{
    if (ImportGroups())
    {
        unsigned       point_index;
        const unsigned vertex_index = index - 1;
        auto           it           = vertex_index_map.find(vertex_index);
        if (it == vertex_index_map.end())
        {
            point_index                    = scene_build.AddPoint(vertex_list[vertex_index].vec);
            vertex_index_map[vertex_index] = point_index;
        }
        else
        {
            point_index = (*it).second;
        }
        return point_index;
    }
    else
    {
        return index - vrt_base;
    }
}

void COBJLoader::ParseFace()
{
    if (isImportingTriSurf)
    {
        CPolyElt e;
        bool     exist[3];
        int      idx[3];
        int      n;
        unsigned i;

        cur_pol.clear();

        /*
         * Handle signed indices.
         */
        while (PullPolyVec(idx, exist))
        {
            int valueIndex = idx[0];
            if (valueIndex < 0)
            {
                int vCount = static_cast<int>(vrt_list.cv_list.size());
                valueIndex = vCount + vrt_list.i_base + valueIndex;
            }

            unsigned idxu[3] = { 0, 0, 0 };
            idxu[0]          = static_cast<unsigned>(valueIndex);

            if (exist[1])
            {
                valueIndex = idx[1];
                if (valueIndex < 0)
                {
                    int uvCount = static_cast<int>(uv_list.cv_list.size());
                    valueIndex  = uvCount + uv_list.i_base + valueIndex;
                }
                idxu[1] = static_cast<unsigned>(valueIndex);
            }

            if (exist[2])
            {
                valueIndex = idx[2];
                if (valueIndex < 0)
                {
                    int nCount = static_cast<int>(norm_list.cv_list.size());
                    valueIndex = nCount + norm_list.i_base + valueIndex;
                }
                idxu[2] = static_cast<unsigned>(valueIndex);
            }

            e.Set(idxu, exist);
            e.SetVrtColor(idxu, vrt_hasCol);

            cur_pol.push_back(e);

            if (e.HasUV())
                has_uv = 1;

            if (e.HasNorm())
                has_norm = 1;

            if (e.HasVrtColor())
                has_vrtColor = 1;
        }

        n = static_cast<int>(cur_pol.size());
        if (n < 3)
            return;

        for (i = 0; i < 3; i++)
            tri_list.push_back(PntIndex(cur_pol[i]));

        for (i = 3; i < n; i++)
        {
            int k = static_cast<int>(tri_list.size()) - 3;
            tri_list.push_back(tri_list[k]);
            tri_list.push_back(tri_list[k + 2]);
            tri_list.push_back(PntIndex(cur_pol[i]));
        }
    }
    else
    {
        CTexture vt;
        CNormal  vn;
        C4Vector vc;
        bool     exist[3];
        int      idx[3];
        unsigned polIdx;
        bool     hasUV, hasNorm, hasVertCol;
        int      n, i;

        pol_uv.clear();
        pol_vrt.clear();
        pol_norm.clear();

        hasUV = hasNorm = true;
        hasVertCol      = (false == vertex_color_list.empty() && true == vrt_hasCol);

        n = 0;
        while (PullPolyVec(idx, exist))
        {
            int valueIndex = idx[0];
            if (valueIndex < 0)
            {
                // if vrt_count==0: Crash #35115 when we pass a negative, signed ValueIndex into MeshPointIndexForVertex as unsigned below
                valueIndex = vrt_count + static_cast<int>(vertex_list.size()) + valueIndex + 1;
            }
            pol_vrt.push_back(valueIndex);

            if (exist[1])
            {
                valueIndex = idx[1];
                if (valueIndex < 0)
                {
                    valueIndex = static_cast<int>(texcoord_list.size()) + valueIndex + 1;
                }
                pol_uv.push_back(valueIndex);
            }
            else
                hasUV = false;

            if (exist[2])
            {
                valueIndex = idx[2];
                if (valueIndex < 0)
                {
                    valueIndex = static_cast<int>(normal_list.size()) + valueIndex + 1;
                }
                pol_norm.push_back(valueIndex);
            }
            else
                hasNorm = false;

            n++;
        }

        if (n <= 2)
            return;

        scene_build.StartPoly(LXiPTYP_FACE);

        for (i = 0; i < n; i++)
        {
            scene_build.AddVertex(MeshPointIndexForVertex(pol_vrt[i]));
        }

        polIdx = scene_build.AddPolygon();

        if (!matr_name.empty())
            scene_build.SetPolyTag(polIdx, LXi_PTAG_MATR, matr_name.c_str());

        if (!part_name.empty())
            scene_build.SetPolyTag(polIdx, LXi_PTAG_PART, part_name.c_str());

        if (hasUV)
        {
            if (no_uv)
            {
                uv_map = scene_build.AddMap(LXi_VMAP_TEXTUREUV, "Texture");
                no_uv  = 0;
            }

            for (i = 0; i < n; i++)
            {
                unsigned uvIndex = pol_uv[i] - 1;
                if (uvIndex < texcoord_list.size())
                {
                    vt = texcoord_list[uvIndex];
                }
                else
                {
                    /*
                     * Bad index defaults to 0.
                     * [TODO] Post error to event log.
                     */
                    vt.vec[0] = 0.0f;
                    vt.vec[1] = 0.0f;

                    log.Info("Writing arbitrary texture coordinate.");
                }
                scene_build.SetCoVertMap(uv_map, vt.vec, MeshPointIndexForVertex(pol_vrt[i]), polIdx);
            }
        }

        if (hasNorm)
        {
            if (no_norm)
            {
                norm_map = scene_build.AddMap(LXi_VMAP_NORMAL, "Surface Normal");
                no_norm  = 0;
            }

            for (i = 0; i < n; i++)
            {
                unsigned normIndex = pol_norm[i] - 1;
                if (normIndex < normal_list.size())
                {
                    vn = normal_list[normIndex];
                }
                else
                {
                    /*
                     * Bad index defaults to arbitrary unit normal.
                     * Post info message to the event log.
                     */
                    vn.vec[0] = 1.0;
                    vn.vec[1] = 0.0;
                    vn.vec[1] = 0.0;

                    log.Info("Writing arbitrary unit normal.");
                }
                scene_build.SetCoVertMap(norm_map, vn.vec, MeshPointIndexForVertex(pol_vrt[i]), polIdx);
            }
        }

        if (hasVertCol)
        {
            if (no_vertCol)
            {
                vertCol_map = scene_build.AddMap(LXi_VMAP_RGBA, "Vertex Color");
                no_vertCol  = 0;
            }

            for (i = 0; i < n; i++)
            {
                unsigned vertColIndex = pol_vrt[i] - 1;
                if (vertColIndex < vertex_color_list.size())
                {
                    vc = vertex_color_list[vertColIndex];
                }
                else
                {
                    /*
                     * Bad index defaults to arbitrary white color.
                     * Post info message to the event log.
                     */
                    vc.f_vec[0] = 1.0;
                    vc.f_vec[1] = 1.0;
                    vc.f_vec[2] = 1.0;
                    vc.f_vec[3] = 1.0;

                    log.Info("Writing arbitrary unit color.");
                }
                scene_build.SetCoVertMap(vertCol_map, vc.f_vec, MeshPointIndexForVertex(pol_vrt[i]), polIdx);
            }
        }
    }
}

void COBJLoader::ParseLine()
{
    if (isImportingTriSurf)
    {
        /*
         * Lines don't have a place in triangle surfaces.
         */
        return;
    }
    else
    {
        bool     exist[3];
        int      idx[3];
        unsigned polIdx;
        int      n, i;

        pol_uv.clear();
        pol_vrt.clear();
        pol_norm.clear();

        n = 0;
        while (PullPolyVec(idx, exist))
        {
            int valueIndex = idx[0];
            if (valueIndex < 0)
            {
                // if vrt_count==0: Crash #35115 when we pass a negative, signed ValueIndex into MeshPointIndexForVertex as unsigned below
                valueIndex = vrt_count + static_cast<int>(vertex_list.size()) + valueIndex + 1;
            }
            pol_vrt.push_back(valueIndex);
            n++;
        }

        if (n < 2)
            return;

        scene_build.StartPoly(LXiPTYP_LINE);

        for (i = 0; i < n; i++)
        {
            scene_build.AddVertex(MeshPointIndexForVertex(pol_vrt[i]));
        }

        polIdx = scene_build.AddPolygon();

        if (!matr_name.empty())
            scene_build.SetPolyTag(polIdx, LXi_PTAG_MATR, matr_name.c_str());

        if (!part_name.empty())
            scene_build.SetPolyTag(polIdx, LXi_PTAG_PART, part_name.c_str());
    }
}

void COBJLoader::WriteSurf()
{
    if (tri_list.empty())
        return;

    CLxUser_Scene           scene(scene_build.SceneObject());
    CLxUser_Item            item;
    CLxUser_ChannelWrite    chan;
    CLxUser_TriangleSurface surf;
    CLxUser_StringTag       tags;
    LXtObjectID             obj;
    unsigned                iUV{}, iNORM{}, iVRTCOL = std::numeric_limits<unsigned>::max();
    int                     index;

    if (!grp_item.test())
    {
        scene_build.AddItem("triSurf");
        if (!obj_name.empty())
            scene_build.SetName(obj_name.c_str());

        scene_build.GetItem(item);
        index = item.ChannelIndex("surf");

        scene.SetChannels(chan, "setup");
        chan.ValueObj(item, index, &obj);
        grp_item.take(obj);
        grp_ntri = 0;
    }

    grp_item.NewSurf(surf);

    tags.set(surf);
    tags.Set(LXi_PTAG_MATR, matr_name.c_str());
    tags.Set(LXi_PTAG_PART, part_name.c_str());

    surf.SetSize(static_cast<unsigned>(pnt_list.size()), static_cast<unsigned>(tri_list.size()) / 3);

    if (has_uv)
        surf.AddVector(LXi_VMAP_TEXTUREUV, "Texture", &iUV);

    if (has_norm)
        surf.AddVector(LXi_VMAP_NORMAL, "Normal", &iNORM);

    if (has_vrtColor)
        surf.AddVector(LXi_VMAP_RGBA, "Vertex Color", &iVRTCOL);

    index = 0;
    for (auto pit = pnt_list.begin(); pit < pnt_list.end(); pit++)
    {
        vrt_list.Grab(pit->Vrt(), surf.SetVector(0, index));

        if (pit->HasUV())
            uv_list.Grab(pit->UV(), surf.SetVector(iUV, index));

        if (pit->HasNorm())
            norm_list.Grab(pit->Norm(), surf.SetVector(iNORM, index));

        if (pit->HasVrtColor())
            vrt_color_list.Grab(pit->VrtColor(), surf.SetVector(iVRTCOL, index));

        index++;
    }

    auto tit = tri_list.begin();
    index    = 0;
    while (tit < tri_list.end())
    {
        unsigned* iv;

        iv    = surf.SetTriangle(index++);
        iv[0] = *tit++;
        iv[1] = *tit++;
        iv[2] = *tit++;
    }

    surf.FixNormals();

    grp_ntri += static_cast<unsigned>(tri_list.size());
    if (grp_ntri > 30000)
        grp_item.clear();

    tri_list.clear();
    pnt_list.clear();
    pnt_map.clear();

    vrt_list.Reset();
    uv_list.Reset();
    norm_list.Reset();
    vrt_color_list.Reset();

    has_uv       = 0;
    has_norm     = 0;
    has_vrtColor = 0;
}

unsigned COBJLoader::PntIndex(const CPolyElt& e)
{
    auto pit = pnt_map.find(e);
    if (pit != pnt_map.end())
        return pit->second;

    unsigned x = static_cast<unsigned>(pnt_map.size());
    pnt_list.push_back(e);
    pnt_map[e] = x;
    return x;
}

/*
 * ----------------------------------------------------------------
 * Common Formatter Class
 *
 * Standard line-based formatter, with spaces as delimiter.
 */
class CCommonFormat : public CLxLineFormat
{
public:
    const char* lf_Separator()
    {
        return " ";
    }

    void WriteVector(float*, int);
    void WriteVector(double*, int);
    void WriteAtom(const char*);
};

/*
 * Vector writing just simplifies writing an array of floats, separated by
 * spaces.
 * NOTE: not sure why the two forms can't be done as a template.
 */
void CCommonFormat::WriteVector(float* vec, int n)
{
    while (n--)
        lf_Output(*vec++);
}

void CCommonFormat::WriteVector(double* vec, int n)
{
    while (n--)
        lf_Output(*vec++);
}

/*
 * An atom is a word without anything ugly in it, which we generate by changing
 * out of range characters to underscores.
 */
void CCommonFormat::WriteAtom(const char* text)
{
    std::string          str;
    const unsigned char* c;
    char                 tmp[8];

    for (c = (const unsigned char*) text; *c; c++)
    {
        if ((*c >= 'a' && *c <= 'z') || (*c >= 'A' && *c <= 'Z') || (*c >= '0' && *c <= '9') || (*c == ':') || (*c == '_'))
        {
            tmp[0] = *c;
            tmp[1] = 0;
            str.append(tmp);
        }
        else
        {
            str.append("_");
        }
    }

    lf_Output(str.c_str());
}

/*
 * ----------------------------------------------------------------
 * MTL Formatter Class
 *
 * Common formatter with method to write MTL commands.
 */
class CMTLFormat : public CCommonFormat
{
public:
    const char* lf_Separator()
    {
        return " ";
    }

    void WriteCmd(MTLCommand);
};

void CMTLFormat::WriteCmd(MTLCommand cmd)
{
    CMTLParser::CommandName* t = CMTLParser::mtl_cmds;

    for (; t->str; t++)
        if (t->cmd == cmd)
        {
            lf_Output(t->str);
            break;
        }
}

/*
 * ----------------------------------------------------------------
 * OBJ Formatter Class
 *
 * Common formatter with methods for commands and polygons. Contains the
 * MTL format as a sub-object, which shadows the main format's state.
 */
class COBJFormat : public CCommonFormat
{
    typedef CLxLineFormat SUPER;

public:
    bool ff_Open(const char*) override;
    void ff_Enable(bool) override;
    bool ff_HasError() override;
    void ff_Cleanup() override;

    void WriteCmd(OBJCommand);
    void WritePoly(unsigned, unsigned*, unsigned*);

    bool ExportMaterialFormat();

    CMTLFormat mtl_format;
};

bool COBJFormat::ff_Open(const char* filename)
{
    std::string str(filename);
    int         i, n;

    // since open calls cleanup, and cleanup does both, this has to be first
    if (!SUPER::ff_Open(filename))
        return false;

    auto it = str.end();
    n       = static_cast<int>(str.length());
    if (n > 6)
        n = 6;

    for (i = 1; i < n; i++)
        if (*--it == '.')
            break;

    if (*it == '.')
    {
        str.erase(it + 1, str.end());
        str.append("mtl");
    }
    else
        str.append(".mtl");

    if (ExportMaterialFormat())
    {
        return mtl_format.ff_Open(str.c_str());
    }
    else
    {
        return true;
    }
}

void COBJFormat::ff_Enable(bool enable)
{
    if (ExportMaterialFormat())
    {
        mtl_format.ff_Enable(enable);
    }
    SUPER::ff_Enable(enable);
}

bool COBJFormat::ff_HasError()
{
    bool x1 = false, x2;

    if (ExportMaterialFormat())
    {
        x1 = mtl_format.ff_HasError();
    }
    x2 = SUPER::ff_HasError();
    return x1 || x2;
}

void COBJFormat::ff_Cleanup()
{
    if (ExportMaterialFormat())
    {
        mtl_format.ff_Cleanup();
    }
    SUPER::ff_Cleanup();
}

void COBJFormat::WriteCmd(OBJCommand cmd)
{
    COBJParser::CommandName* t = COBJParser::obj_cmds;

    for (; t->str; t++)
        if (t->cmd == cmd)
        {
            lf_Output(t->str);
            break;
        }
}

/*
 * Polygon indices are optional for texture and normal. We have to write
 * without the normal delimiter when concatenating with slashes.
 */
void COBJFormat::WritePoly(unsigned pos, unsigned* tex, unsigned* nor)
{
    lf_Output(pos);
    if (tex || nor)
    {
        lf_Raw("/");
        if (tex)
            lf_Output(*tex, false);

        if (nor)
        {
            lf_Raw("/");
            lf_Output(*nor, false);
        }
    }
}

bool COBJFormat::ExportMaterialFormat()
{
    static const char* LXsUSER_VALUE_OBJ_EXPORT_MATERIAL_FORMAT = "sceneio.obj.export.material.format";

    return (GetUserInt(LXsUSER_VALUE_OBJ_EXPORT_MATERIAL_FORMAT, 1) ? true : false);
}

/*
 * ----------------------------------------------------------------
 * OBJ Saver
 *
 * The saver is a standard scene saver, and also derives from the format
 * for convenience.
 */
class COBJSaver : public CLxSceneSaver, public COBJFormat
{
    OBJLogMessage log;

public:
    COBJSaver();
    ~COBJSaver()
    {
    }

    CLxFileFormat* ss_Format() override
    {
        return this;
    }
    bool ss_DoSubset() override
    {
        return true;
    }

    void     ss_Verify() override;
    LxResult ss_Save() override;
    void     ss_Point() override;
    void     ss_Polygon() override;

    static LXtTagInfoDesc descInfo[];

    enum
    {
        POLY_PASS_NORMALS,
        POLY_PASS_UVS,
        POLY_PASS_POLYS
    };

    int  pol_pass;
    bool haveMorphMap;

    unsigned    pnt_count, nor_count, tex_count;
    std::string cur_matr;
    std::string cur_part;
    double      unitScale;

    CLxUser_SceneService           svc;
    LXtItemType                    meshType, meshInstType, triSurfType;
    std::map<LXtPointID, unsigned> pnt_index;
    std::map<CTexture, unsigned>   tex_index;
    std::map<CNormal, unsigned>    nor_index;
    std::set<std::string>          matr_set;

    LXtMatrix xfrm_mat;
    double    xfrm_mat_determinant;
    LXtVector xfrm_pos;
    bool      exportAtCurrTime;

    void     WriteMesh();
    void     WriteTriSurf();
    unsigned VertexNormal(unsigned);
    bool     TallyVertexTexture(unsigned);
    unsigned VertexTexture(unsigned);
    void     WriteFace();
    void     WriteMaterial(const std::string&);

    bool      ExportGroups();
    UnitsType ExportUnits();
    bool      ExportAtCurrTime();
};

#define SUBSET_MASK LXsSUBSET_SURFACES " " LXsSUBSET_MATERIALS

LXtTagInfoDesc COBJSaver::descInfo[] = { { LXsSAV_OUTCLASS, LXa_SCENE },       { LXsSAV_DOSTYPE, "obj" },
                                         { LXsSAV_SCENE_SUBSET, SUBSET_MASK }, { LXsSRV_USERNAME, "Wavefront OBJ" },
                                         { LXsSRV_LOGSUBSYSTEM, "io-status" }, { nullptr } };

COBJSaver::COBJSaver()
{
    meshType     = svc.ItemType(LXsITYPE_MESH);
    meshInstType = svc.ItemType(LXsITYPE_MESHINST);
    triSurfType  = svc.ItemType(LXsITYPE_TRISURF);
}

void COBJSaver::ss_Verify()
{
    Message("common", 2020);

    std::string message("OBJ only supports geometry and simple texturing.");

    // Warn about static meshes.
    StartScan(LXsITYPE_TRISURF);
    if (NextItem())
        message.append("\nStatic meshes are not exported.");

    MessageArg(1, message.c_str());
}

LxResult COBJSaver::ss_Save()
{
    LxResult result = LXe_OK;

    try
    {
        /*
         * Setup the message logging system.
         */
        log.Setup();

        CLxUser_SelectionService selSvc;
        double                   currTime;

        currTime = selSvc.GetTime();

        lf_Output("# OBJ written from");
        lf_Output(file_name);
        lf_Break();

        pnt_count = 0;
        nor_count = 0;
        tex_count = 0;

        if (ExportGroups() && ExportMaterialFormat())
        {
            /*
             * Write out the material library file reference
             * before the polygon faces which may point back to it.
             */
            WriteCmd(CMD_MATR_LIBRARY);
            std::string matrFileName(mtl_format.file_name);
            auto        pos          = matrFileName.find_last_of("/\\");
            std::string leafFileName = matrFileName.substr(pos + 1, matrFileName.length() - pos - 1);
            lf_Output(leafFileName.c_str());
            lf_Break();
        }

        // Set export unit scale
        UnitsType units = ExportUnits();

        switch (units)
        {
            case UNITS_MM:
                unitScale = 1000.0;
                lf_Output("# Units\tmillimeters");
                break;

            case UNITS_CM:
                unitScale = 100.0;
                lf_Output("# Units\tcentimeters");
                break;

            case UNITS_INCH:
                lf_Output("# Units\tinches");
                unitScale = 39.3701;
                break;

            case UNITS_M:
            default:
                unitScale = 1.0;
                lf_Output("# Units\tmeters");
                break;
        }
        lf_Break();

        exportAtCurrTime = ExportAtCurrTime();

        /*
         * First iterate over the meshes.
         */
        StartScan();
        while (NextMesh())
        {
            if (exportAtCurrTime)
                SetMeshTime(currTime);
            WriteMesh();
        }

        /*
         * Next, iterate over the mesh instances.
         */
        StartScan(LXsITYPE_MESHINST);
        while (NextItem())
        {
            if (exportAtCurrTime)
                SetMeshTime(currTime);
            WriteMesh();
        }
        /*
         * [TODO] Enable once triSurf saving is ready.
         */
        if (ExportMaterialFormat())
        {
            /*
             * Finally, write out the materials.
             */
            mtl_format.lf_Output("# MTL written from");
            mtl_format.lf_Output(file_name);

            for (auto sit = matr_set.begin(); sit != matr_set.end(); sit++)
            {
                mtl_format.lf_Break();
                WriteMaterial(*sit);
            }
        }

        if (LXx_OK(result) && ReallySaving())
        {
            log.Info("Scene saved successfully.");
        }
    }
    catch (...)
    {
        /*
         * Make sure error doesn't take down the host.
         */
        log.Error("Saver failed with unknown error.");

        /*
         * Force a failure result code, in case no one set it.
         */
        if (LXx_OK(result))
        {
            result = LXe_FAILED;
        }
    }

    return result;
}

void COBJSaver::WriteMesh()
{
    bool exportGroups = ExportGroups();
    lf_Break(true);
    if (exportGroups)
    {
        WriteCmd(CMD_GROUP);
    }
    else
    {
        WriteCmd(CMD_OBJECT);
    }

    lf_Output(ItemName());
    lf_Break();

    /*
     * Apply the first selected morph map to
     * the geometry positions.
     */
    haveMorphMap = SetSelMap(LXi_VMAP_MORPH);

    WorldXform(xfrm_mat, xfrm_pos);
    xfrm_mat_determinant = lx::MatrixDeterminant(xfrm_mat);
    WritePoints();

    pol_pass = POLY_PASS_NORMALS;
    WritePolys();

    bool hasUvs;
    hasUvs = SetSelMap(LXi_VMAP_TEXTUREUV);
    if (!hasUvs)
    {
        hasUvs = SetMap(LXi_VMAP_TEXTUREUV);
    }
    if (hasUvs)
    {
        pol_pass = POLY_PASS_UVS;
        SetSelMap(LXi_VMAP_TEXTUREUV);
        WritePolys();
    }

    if (ExportMaterialFormat() && !exportGroups)
    {
        /*
         * Write out the material library file reference
         * before the polygon faces which may point back to it.
         */
        WriteCmd(CMD_MATR_LIBRARY);
        std::string matrFileName(mtl_format.file_name);
        auto        pos          = matrFileName.find_last_of("/\\");
        std::string leafFileName = matrFileName.substr(pos + 1, matrFileName.length() - pos - 1);
        lf_Output(leafFileName.c_str());
        lf_Break();
    }

    pol_pass = POLY_PASS_POLYS;
    cur_matr = "";
    cur_part = "";
    WritePolys(0, true);  // Enable unified polygon material mapping.

    pnt_index.clear();
    nor_index.clear();
    tex_index.clear();
}

void COBJSaver::WriteTriSurf()
{
    lf_Break(true);
    WriteCmd(CMD_OBJECT);
    lf_Output(ItemName());
    lf_Break();

    WorldXform(xfrm_mat, xfrm_pos);
    xfrm_mat_determinant = lx::MatrixDeterminant(xfrm_mat);
    WritePoints();
}

void COBJSaver::ss_Point()
{
    float  opos[3];
    double vec[3];

    if (GetItemType() == meshType || GetItemType() == meshInstType)
    {
        pnt_index[PntID()] = ++pnt_count;
    }

    WriteCmd(CMD_VERTEX);
    PntPosition(opos);

    if (!exportAtCurrTime)
    {
        /*
         * Check for a selected morph map.
         */
        float morphOffset[3];
        if (haveMorphMap && PntMapValue(morphOffset))
        {
            opos[0] += morphOffset[0];
            opos[1] += morphOffset[1];
            opos[2] += morphOffset[2];
        }
    }

    lx::MatrixMultiply(vec, xfrm_mat, opos);
    vec[0] += xfrm_pos[0];
    vec[1] += xfrm_pos[1];
    vec[2] += xfrm_pos[2];

    vec[0] *= unitScale;
    vec[1] *= unitScale;
    vec[2] *= unitScale;

    WriteVector(vec, 3);
    lf_Break();
}

unsigned COBJSaver::VertexNormal(unsigned index)
{
    LXtPointID vrt;
    double     ovec[3], wvec[3];
    CNormal    norm;

    vrt = PolyVertex(index);
    if (!PolyNormal(ovec, vrt))
        return 0;

    lx::MatrixMultiply(wvec, xfrm_mat, ovec);
    norm.vec[0] = static_cast<float>(wvec[0]);
    norm.vec[1] = static_cast<float>(wvec[1]);
    norm.vec[2] = static_cast<float>(wvec[2]);

    auto mit = nor_index.find(norm);
    if (mit != nor_index.end())
        return mit->second;

    WriteCmd(CMD_NORMAL);
    WriteVector(norm.vec, 3);
    lf_Break();

    nor_index[norm] = ++nor_count;

    return nor_count;
}

bool COBJSaver::TallyVertexTexture(unsigned index)
{
    LXtPointID vrt;
    CTexture   tex;

    vrt = PolyVertex(index);
    return PolyMapValue(tex.vec, vrt);
}

unsigned COBJSaver::VertexTexture(unsigned index)
{
    LXtPointID vrt;
    CTexture   tex;

    vrt = PolyVertex(index);
    if (!PolyMapValue(tex.vec, vrt))
        return 0;

    auto mit = tex_index.find(tex);
    if (mit != tex_index.end())
        return mit->second;

    WriteCmd(CMD_TEXTURE);
    WriteVector(tex.vec, 2);
    lf_Break();

    tex_index[tex] = ++tex_count;
    return tex_count;
}

void COBJSaver::ss_Polygon()
{
    unsigned i, n;

    switch (pol_pass)
    {
        case POLY_PASS_NORMALS:
            n = PolyNumVerts();
            for (i = 0; i < n; i++)
            {
                VertexNormal(i);
            }
            break;

        case POLY_PASS_UVS:
            n = PolyNumVerts();
            for (i = 0; i < n; i++)
            {
                VertexTexture(i);
            }
            break;

        case POLY_PASS_POLYS:
            WriteFace();
            break;
    }
}

void COBJSaver::WriteFace()
{
    LXtPointID  pnt;
    const char* matr;
    const char* part;
    unsigned    i, vrt, nor, *norPtr, tex, *texPtr, n;

    matr = PolyTag(LXi_PTAG_MATR);
    if (matr && strcmp(matr, cur_matr.c_str()))
    {
        WriteCmd(CMD_USE_MATERIAL);
        WriteAtom(matr);
        lf_Break();

        cur_matr = matr;
        matr_set.insert(cur_matr);
    }

    part = PolyTag(LXi_PTAG_PART);
    if (part && strcmp(part, cur_part.c_str()))
    {
        if (!ExportGroups())
        {
            WriteCmd(CMD_GROUP);
            WriteAtom(part);
            lf_Break();
        }
        cur_part = part;
    }

    WriteCmd(CMD_FACE);
    n = PolyNumVerts();
    for (i = 0; i < n; i++)
    {
        // if xform matrix determinant < 0, reverse the winding of vertices
        // since OBJ requires CCW (counter-clockwise) order
        unsigned vInd = (xfrm_mat_determinant > 0) ? i : (n - 1 - i);

        pnt = PolyVertex(vInd);
        vrt = pnt_index[pnt];

        nor    = VertexNormal(vInd);
        norPtr = (nor ? &nor : nullptr);

        tex    = VertexTexture(vInd);
        texPtr = (tex ? &tex : nullptr);

        WritePoly(vrt, texPtr, norPtr);
    }

    lf_Break();
}

void COBJSaver::WriteMaterial(const std::string& name)
{
    CLxUser_Item matr, cmap, bmap, tmap, smap, lmap;
    const char*  fx;
    double       vec[3], a;
    unsigned     idx;

    if (!ExportMaterialFormat())
    {
        return;
    }

    mtl_format.WriteCmd(CMD_NEW);
    mtl_format.WriteAtom(name.c_str());
    mtl_format.lf_Break();

    if (!ScanMask(name.c_str()))
        return;

    while (NextLayer())
    {
        if (!ChanInt(LXsICHAN_TEXTURELAYER_ENABLE))
            continue;

        if (ItemIsA(LXsITYPE_ADVANCEDMATERIAL))
            GetItem(matr);

        else if (ItemIsA(LXsITYPE_IMAGEMAP))
        {
            fx = LayerEffect();

            if (!strcmp(fx, LXs_FX_DIFFCOLOR))
                GetItem(cmap);

            else if (!strcmp(fx, LXs_FX_SPECCOLOR))
                GetItem(smap);

            else if (!strcmp(fx, LXs_FX_TRANCOLOR))
                GetItem(tmap);

            else if (!strcmp(fx, LXs_FX_LUMICOLOR))
                GetItem(lmap);

            else if (!strcmp(fx, LXs_FX_BUMP))
                GetItem(bmap);
        }
    }

    if (matr.test() && SetItem(matr))
    {
        // diffuse
        //
        a      = ChanFloat(LXsICHAN_ADVANCEDMATERIAL_DIFFAMT);
        idx    = ChanIndex(LXsICHAN_ADVANCEDMATERIAL_DIFFCOL ".R");
        vec[0] = ChanFloat(idx + 0) * a;
        vec[1] = ChanFloat(idx + 1) * a;
        vec[2] = ChanFloat(idx + 2) * a;

        mtl_format.WriteCmd(CMD_DIFFUSE);
        mtl_format.WriteVector(vec, 3);
        mtl_format.lf_Break();

        // gloss
        //
        mtl_format.WriteCmd(CMD_SHININESS);
        mtl_format.lf_Output(SpecExponent());
        mtl_format.lf_Break();

        // opacity
        //
        mtl_format.WriteCmd(CMD_OPACITY);
        mtl_format.lf_Output(1.0 - ChanFloat(LXsICHAN_ADVANCEDMATERIAL_TRANAMT));
        mtl_format.lf_Break();

        // smoothing
        //
        a = ChanFloat(LXsICHAN_ADVANCEDMATERIAL_SMOOTH);
        mtl_format.WriteCmd(CMD_ILLUM_MODE);
        mtl_format.lf_Output(a > 0.5 ? 2 : 1);
        mtl_format.lf_Break();

        // luminance (written as ambient)
        //
        a      = ChanFloat(LXsICHAN_ADVANCEDMATERIAL_RADIANCE);
        idx    = ChanIndex(LXsICHAN_ADVANCEDMATERIAL_LUMICOL ".R");
        vec[0] = ChanFloat(idx + 0) * a;
        vec[1] = ChanFloat(idx + 1) * a;
        vec[2] = ChanFloat(idx + 2) * a;

        mtl_format.WriteCmd(CMD_AMBIENT);
        mtl_format.WriteVector(vec, 3);
        mtl_format.lf_Break();

        // specular
        //
        a      = ChanFloat(LXsICHAN_ADVANCEDMATERIAL_SPECAMT);
        idx    = ChanIndex(LXsICHAN_ADVANCEDMATERIAL_SPECCOL ".R");
        vec[0] = ChanFloat(idx + 0) * a;
        vec[1] = ChanFloat(idx + 1) * a;
        vec[2] = ChanFloat(idx + 2) * a;

        mtl_format.WriteCmd(CMD_SPECULAR);
        mtl_format.WriteVector(vec, 3);
        mtl_format.lf_Break();
    }

    // maps
    //
    if (cmap.test() && SetItem(cmap) && TxtrImage() && (fx = ChanString(LXsICHAN_VIDEOSTILL_FILENAME)) != nullptr)
    {
        mtl_format.WriteCmd(CMD_MAP_DIFFUSE);
        mtl_format.lf_Output(fx);
        mtl_format.lf_Break();
    }

    if (smap.test() && SetItem(smap) && TxtrImage() && (fx = ChanString(LXsICHAN_VIDEOSTILL_FILENAME)) != nullptr)
    {
        mtl_format.WriteCmd(CMD_MAP_SPECULAR);
        mtl_format.lf_Output(fx);
        mtl_format.lf_Break();
    }

    if (tmap.test() && SetItem(tmap) && TxtrImage() && (fx = ChanString(LXsICHAN_VIDEOSTILL_FILENAME)) != nullptr)
    {
        mtl_format.WriteCmd(CMD_MAP_OPACITY);
        mtl_format.lf_Output(fx);
        mtl_format.lf_Break();
    }

    if (lmap.test() && SetItem(lmap) && TxtrImage() && (fx = ChanString(LXsICHAN_VIDEOSTILL_FILENAME)) != nullptr)
    {
        mtl_format.WriteCmd(CMD_MAP_AMBIENT);
        mtl_format.lf_Output(fx);
        mtl_format.lf_Break();
    }

    if (bmap.test() && SetItem(bmap) && TxtrImage() && (fx = ChanString(LXsICHAN_VIDEOSTILL_FILENAME)) != nullptr)
    {
        mtl_format.WriteCmd(CMD_MAP_BUMP);
        mtl_format.lf_Output(fx);
        mtl_format.lf_Break();
    }
}

bool COBJSaver::ExportGroups()
{
    static const char* LXsUSER_VALUE_OBJ_EXPORT_GROUPS = "sceneio.obj.export.groups";

    return (GetUserInt(LXsUSER_VALUE_OBJ_EXPORT_GROUPS) ? true : false);
}

UnitsType COBJSaver::ExportUnits()
{
    static const char* LXsUSER_VALUE_OBJ_EXPORT_UNITS = "sceneio.obj.export.units";

    int value = GetUserInt(LXsUSER_VALUE_OBJ_EXPORT_UNITS);

    if (value < 0 || value > UNITS_COUNT)
        return UNITS_NONE;
    else
        return (UnitsType) value;
}

bool COBJSaver::ExportAtCurrTime()
{
    static const char* LXsUSER_VALUE_OBJ_EXPORT_AT_CURRENT_TIME = "sceneio.obj.export.atCurrentTime";

    return (GetUserInt(LXsUSER_VALUE_OBJ_EXPORT_AT_CURRENT_TIME) ? true : false);
}

/*
 * ----------------------------------------------------------------
 * Exporting Servers
 */
void initialize()
{
    LXx_ADD_SERVER(Loader, COBJLoader, "wf_OBJ");
    LXx_ADD_SERVER(Saver, COBJSaver, "wf_OBJ");

    OBJ_Options::initialize();
    ObjPresetType::Initialize();
}

void cleanup()
{
    OBJ_Options::cleanup();
}
