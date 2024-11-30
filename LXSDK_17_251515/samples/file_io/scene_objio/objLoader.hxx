#pragma once

// Obj Loader Class
//
//   Copyright 0000

#include "baseGeomTypes.hxx"
#include "objLogMessage.hxx"

#include <lxu_scene.hpp>

#include <map>

/*
 * ----------------------------------------------------------------
 * OBJ Loader Class
 *
 * The loader is a standard scene loader, and also derives from the parser
 * for convenience.
 */
class COBJLoader : public CLxSceneLoader, public COBJParser
{
    OBJLogMessage log;
    bool          foundGroup;
    unsigned      lineIndex;

    // Variables to prevent calling GetUserInt multiple times in an import, which
    // causes a massive slowdown.
    int  importStatic;
    int  importSeparateMeshes;
    bool staticPreference;
    bool separatePreference;

public:
    COBJLoader() : importStatic(0), importSeparateMeshes(0), staticPreference(false), separatePreference(false)
    {
    }

    ~COBJLoader()
    {
    }

    void Cleanup();

    CLxFileParser* sl_Parser() override
    {
        return this;
    }

    bool sl_Recognize() override;
    bool sl_HasOptions() override;
    void sl_SpawnOpt(void**) override;
    bool sl_ParseInit() override;
    bool sl_ParseDone() override;
    bool sl_Parse(LxResult*) override;

    static LXtTagInfoDesc descInfo[];
    std::string           matr_name, part_name, obj_name;

    bool      ImportStaticMesh();
    bool      isImportingTriSurf;
    bool      ImportGroups();
    UnitsType ImportUnits();

    /*
     * Mesh item loading.
     */
    void MakeVrts();
    void NeedMesh();
    void ParseFace();
    void ParseLine();

    unsigned MeshPointIndexForVertex(unsigned index);

    double   unitScale;
    unsigned uv_map, norm_map, vertCol_map;
    bool     no_mesh, no_uv, no_norm, no_vertCol;

    std::vector<CVertex>         vertex_list;
    std::map<unsigned, unsigned> vertex_index_map;
    std::vector<C4Vector>        vertex_color_list;
    std::vector<CTexture>        texcoord_list;
    std::vector<CNormal>         normal_list;
    int                          vrt_count;
    int                          vrt_base;
    bool                         vrt_hasCol;

    std::vector<unsigned> pol_vrt, pol_uv, pol_norm;
    std::set<std::string> material_lib_paths;

    /*
     * TriSurf item loading.
     */
    void     WriteSurf();
    unsigned PntIndex(const CPolyElt&);

    CVectorList<C3Vector> vrt_list, norm_list;
    CVectorList<C2Vector> uv_list;
    CVectorList<C4Vector> vrt_color_list;
    bool                  has_uv, has_norm, has_vrtColor;

    std::vector<CPolyElt>        pnt_list;
    std::map<CPolyElt, unsigned> pnt_map;
    std::vector<unsigned>        tri_list;

    std::vector<CPolyElt> cur_pol;

    CLxUser_TriangleGroup grp_item;
    unsigned              grp_ntri;
};
