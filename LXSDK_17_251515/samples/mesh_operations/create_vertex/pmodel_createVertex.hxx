/*
 *
 * The Create Vertex mesh operation generates a single vertex from a position.
 *
 * Copyright 0000
 *
 */

#pragma once

#include <lxu_modifier.hpp>
#include <lxu_package.hpp>

#include <lxw_mesh.hpp>
#include <lxw_pmodel.hpp>

namespace CreateVertex
{

    // MeshOp implementation that modifies a mesh by adding a vertex

    class MeshOp : public CLxImpl_MeshOperation, public CLxImpl_MeshElementGroup
    {
    public:
        static void    initialize();
        static MeshOp* Spawn(LXtVector pos, void** ppvObj);

        LxResult mop_Evaluate(ILxUnknownID meshObj, LXtID4 type, LXtMarkMode mode) override;

        LxResult eltgrp_GroupCount(unsigned int* count) override;

        LxResult eltgrp_GroupName(unsigned int index, const char** name) override;

        LxResult eltgrp_GroupUserName(unsigned int index, const char** username) override;

        LxResult             eltgrp_TestPoint(unsigned int index, LXtPointID point) override;
        std::set<LXtPointID> NewPoints;

    private:
        // Position at which to add vertex
        LXtVector mPosition;
    };

    // Package describing this plugin

    class Package : public CLxDefaultPackage
    {
    public:
        static void initialize();

        LxResult pkg_SetupChannels(ILxUnknownID addChan) override;

        static LXtTagInfoDesc descInfo[];
    };

    // A modifier that can create new instances of our MeshOp

    class ModifierElement : public CLxItemModifierElement
    {
    public:
        ModifierElement(CLxUser_Evaluation& eval, ILxUnknownID item);

        void Eval(CLxUser_Evaluation& eval, CLxUser_Attributes& attr) override;

    private:
        // Indices of channel values within attributes
        unsigned int mPositionXIndex;
        unsigned int mPositionYIndex;
        unsigned int mPositionZIndex;
        unsigned int mOutputIndex;
    };

    // Modifier server to create new instances of our modifier

    class ModifierServer : public CLxItemModifierServer
    {
    public:
        static void initialize();

        const char*             ItemType() override;
        CLxItemModifierElement* Alloc(CLxUser_Evaluation& eval, ILxUnknownID item) override;
    };

    void initialize();
}  // namespace CreateVertex
