/*
 *
 * The Create Vertex mesh operation generates a single vertex from a position.
 *
 * Copyright 0000
 *
 */

#include "pmodel_createVertex.hxx"

namespace CreateVertex
{
    // Name of this plugin's Package
    // We'll also register a Modifier 'pmodel.createVertex.mod' and a MeshOp 'pmodel.createVertex.op'

#define CREATEVERTEX_MESHOP "pmodel.createVertex"

    // Name of the channel on which the vertex position will be given

#define POSITION_CHAN "position"

    // Add a spawner that will allow us to create new instances of the MeshOp class
    //
    // We don't want a server here since we want to create the MeshOp instances ourself
    // so we can initialise them with the vertex position

    void MeshOp::initialize()
    {
        CLxGenericPolymorph* srv = new CLxPolymorph<MeshOp>;

        srv->AddInterface(new CLxIfc_MeshOperation<MeshOp>);
        srv->AddInterface(new CLxIfc_MeshElementGroup<MeshOp>);

        lx::AddSpawner(CREATEVERTEX_MESHOP ".op", srv);
    }

    // Create a new instance of the MeshOp class from the spawner
    //
    // This is effectively a constructor, but we need to create the object via the spawner
    // rather than directly as it's really a COM object, not just a plain C++ class

    MeshOp* MeshOp::Spawn(LXtVector pos, void** ppvObj)
    {
        static CLxSpawner<MeshOp> spawner(CREATEVERTEX_MESHOP ".op");
        MeshOp*                   meshop = spawner.Alloc(ppvObj);
        if (meshop)
        {
            LXx_VCPY(meshop->mPosition, pos);
        }

        return meshop;
    }

    // Evaluate the MeshOp by modifying the input mesh

    LxResult MeshOp::mop_Evaluate(ILxUnknownID meshObj, LXtID4 /*type*/, LXtMarkMode /*mode*/)
    {
        // Get the mesh interface from the input mesh object
        CLxUser_Mesh mesh(meshObj);

        // Query a point accessor for the mesh that will allow us to add a new vertex
        CLxUser_Point pointAccessor;
        if (!pointAccessor.fromMesh(mesh))
            return LXe_FAILED;

        // Add the new vertex at the requested position
        LXtPointID pointID;
        if (!LXx_OK(pointAccessor.New(mPosition, &pointID)))
            return LXe_FAILED;
        NewPoints.insert(pointID);

        return LXe_OK;
    }

    LxResult MeshOp::eltgrp_GroupCount(unsigned int* count)
    {
        count[0] = 1;
        return LXe_OK;
    }

    LxResult MeshOp::eltgrp_GroupName(unsigned int /*index*/, const char** name)
    {
        name[0] = "new";
        return LXe_OK;
    }

    LxResult MeshOp::eltgrp_GroupUserName(unsigned int /*index*/, const char** username)
    {
        username[0] = "new";
        return LXe_OK;
    }

    LxResult MeshOp::eltgrp_TestPoint(unsigned int /*index*/, LXtPointID point)
    {
        auto it = NewPoints.find(point);
        if (it != NewPoints.end())
        {
            return LXe_TRUE;
        }
        return LXe_FALSE;
    }

    // Create a new Package server that describes the channels our modifier needs

    void Package::initialize()
    {
        CLxGenericPolymorph* srv = new CLxPolymorph<Package>;

        srv->AddInterface(new CLxIfc_Package<Package>);
        srv->AddInterface(new CLxIfc_StaticDesc<Package>);

        lx::AddServer(CREATEVERTEX_MESHOP, srv);
    }

    // Add our channels

    LxResult Package::pkg_SetupChannels(ILxUnknownID addChan)
    {
        CLxUser_AddChannel ac(addChan);

        // Add a single position channel to receive the position for the new vertex
        if (LXx_OK(ac.NewChannel(POSITION_CHAN, LXsTYPE_DISTANCE)))
        {
            ac.SetVector(LXsCHANVEC_XYZ);

            LXtVector v;
            LXx_VSET3(v, 0.0, 0.0, 0.0);
            ac.SetDefaultVec(v);
        }

        return LXe_OK;
    }

    // Package information describing what type of plugin this is and a few other options

    LXtTagInfoDesc Package::descInfo[] = { { LXsPKG_SUPERTYPE, LXsITYPE_MESHOP },             // This is a MeshOp plugin
                                           { LXsPMODEL_SELECTIONTYPES, LXsSELOP_TYPE_NONE },  // We ignore selections
                                           { LXsPMODEL_NOTRANSFORM, "." },                    // We don't care about the mesh transform
                                           { nullptr } };

    // Initialise the modifier

    ModifierElement::ModifierElement(CLxUser_Evaluation& eval, ILxUnknownID item)
    {
        // Save the indices of all the channels we need so that we can use them
        // to query and return values when evaluating the modifier
        mPositionXIndex = eval.AddChan(item, POSITION_CHAN ".X", LXfECHAN_READ);
        mPositionYIndex = eval.AddChan(item, POSITION_CHAN ".Y", LXfECHAN_READ);
        mPositionZIndex = eval.AddChan(item, POSITION_CHAN ".Z", LXfECHAN_READ);

        mOutputIndex = eval.AddChan(item, LXsICHAN_MESHOP_OBJ, LXfECHAN_WRITE);
    }

    // Evaluate the modifier to produce a new instance of the MeshOp

    void ModifierElement::Eval(CLxUser_Evaluation& /*eval*/, CLxUser_Attributes& attr)
    {
        // Read the vertex position from the position channel
        LXtVector pos;
        pos[0] = attr.Float(mPositionXIndex);
        pos[1] = attr.Float(mPositionYIndex);
        pos[2] = attr.Float(mPositionZIndex);

        // Create a new instance of our MeshOp
        ILxUnknownID obj = nullptr;
        if (MeshOp::Spawn(pos, (void**) &obj))
        {
            // Store it on the output channel
            attr.SetRef(mOutputIndex, obj);
            lx::UnkRelease(obj);
        }
    }

    // Register a Modifier server that can create our modifier

    void ModifierServer::initialize()
    {
        CLxExport_ItemModifierServer<ModifierServer>::Define(CREATEVERTEX_MESHOP ".mod");
    }

    const char* ModifierServer::ItemType()
    {
        return CREATEVERTEX_MESHOP;
    }

    CLxItemModifierElement* ModifierServer::Alloc(CLxUser_Evaluation& eval, ILxUnknownID item)
    {
        return new ModifierElement(eval, item);
    }

    // Register each server with Modo

    void initialize()
    {
        MeshOp::initialize();
        Package::initialize();
        ModifierServer::initialize();
    }

}  // namespace CreateVertex
