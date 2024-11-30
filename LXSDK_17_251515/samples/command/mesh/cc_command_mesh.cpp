/*
 * MODO SDK SAMPLE
 *
 * Command server
 * ==============
 *
 *	Copyright 0000
 *
 * This implements a Command server that looks at meshes.
 *
 * CLASSES USED:
 *
 *		CLxCommand
 *		CLxVisitor
 *		CLxMeta_Command
 *
 * TESTING:
 *
 * Execute the command "csam.command.mesh" from the command history.
 * A message will appear in the log reporting that it fired.
 */
#include <lxu_command.hpp>

#include <lx_layer.hpp>
#include <lx_log.hpp>
#include <lxu_math.hpp>
#include <lxu_vector.hpp>

#define SRVNAME_COMMAND "csam.command.mesh"

namespace CommandMesh
{

    /*
     * ----------------------------------------------------------------
     * We'll use a Visitor when walking through the points of a mesh.
     */
    class CVisitor : public CLxVisitor
    {
    public:
        CLxUser_Point* point;
        CLxBoundingBox bound;

        /*
         * evaluate() is called to process each element in the enumeration.
         *
         * Get point position and expand the bounding box to include it.
         */
        void evaluate()
        {
            CLxFVector pos;

            lx_err::check(point->Pos(pos));
            bound.add(pos);
        }
    };

    /*
     * ----------------------------------------------------------------
     * The command will output to the debug log when fired.
     */
    class CCommand : public CLxCommand
    {
    public:
        CLxUser_LayerService lyr_S;
        CLxUser_MeshService  msh_S;
        unsigned             select_mode;

        /*
         * Get the mode for traversing only selected points (or all points if
         * none are selected).
         */
        CCommand()
        {
            lx_err::check(msh_S.ModeCompose("select", NULL, &select_mode));
        }

        /*
         * enabled() is called to test if the command should be enabled
         * given the state of the system.
         *
         * Disable if there no active layers are found.
         */
        bool enabled() override
        {
            int      flags = 0;
            unsigned count;

            lx_err::check(lyr_S.SetScene(0));
            lx_err::check(lyr_S.Count(&count));

            for (unsigned i = 0; i < count; i++)
            {
                lx_err::check(lyr_S.Flags(i, &flags));
                if (flags & LXf_LAYERSCAN_ACTIVE)
                    return true;
            }

            return false;
        }

        /*
         * execute() is called to perform the operation of the command.
         *
         * Get a layer scan for points in active layers, and enumerate all
         * the points in all layers.
         */
        void execute() override
        {
            CLxUser_LayerScan scan;
            CLxUser_Mesh      mesh;
            CLxUser_Point     point;
            CVisitor          vis;
            unsigned          i, n;

            lx_err::check(lyr_S.ScanAllocate(LXf_LAYERSCAN_ACTIVE | LXf_LAYERSCAN_MARKVERTS, scan));
            lx_err::check(scan.Count(&n));

            for (i = 0; i < n; i++)
            {
                lx_err::check(scan.MeshInstance(i, mesh));
                lx_err::check(point.fromMesh(mesh));

                vis.point = &point;
                lx_err::check(point.Enumerate(select_mode, vis, 0));
            }

            CLxUser_LogService lS;
            lS.DebugOut(LXi_DBLOG_NORMAL, SRVNAME_COMMAND " got box %f\n", vis.bound.extent()[0]);
        }
    };

    /*
     * ----------------------------------------------------------------
     * Metaclass
     *
     * The command name is passed to the metaclass constructor.
     */
    static CLxMeta_Command<CCommand> cmd_meta(SRVNAME_COMMAND);

    /*
     * ----------------------------------------------------------------
     * Root metaclass
     *
     *	(root)
     *	  |
     *	  +---	command
     *
     * We'll make this a UI command since it doesn't alter any scene state.
     * Item selections will update the disable state.
     */
    static class CRoot : public CLxMetaRoot
    {
        bool pre_init() override
        {
            cmd_meta.set_type_UI();
            cmd_meta.add_notifier(LXsNOTIFIER_SELECT, "item +d");

            add(&cmd_meta);
            return false;
        }
    } root_meta;

};  // namespace CommandMesh
