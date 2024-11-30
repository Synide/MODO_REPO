/*
 * MODO SDK SAMPLE
 *
 * Scene Loader server
 * ===================
 *
 *	Copyright 0000
 *
 * This implements a Loader server that loads simple scenes with options.
 *
 * For purposes of the sample this is a completely made up file format. The
 * files are plain text with the extension ZZZ. The first line of the file
 * is the literal string "ZZZ". The second line is geometric parameters.
 *
 * CLASSES USED:
 *
 *		CLxLoader
 *		CLxLoaderOptions
 *		CLxMeta_Loader
 *		CLxSceneBuilder
 *
 * TESTING:
 *
 * For testing you can clip the three lines here and place them into a text
 * file, and rename it to "test.zzz". The two numbers are the height and
 * radius of cone we're loading.
 *

ZZZ
1.5 0.5

 *
 * To test the loading and saving of options, import this scene as reference
 * into another scene and set the segments to something memorable. Save the
 * master scene and reload it, and the segments should be the same without
 * your having to enter it again.
 */
#include <cmath>
#include <lxidef.h>
#include <lxu_command.hpp>
#include <lxu_io.hpp>
#include <lxu_parser.hpp>
#include <lxu_scene.hpp>

#define SRVNAME_LOADER "csam.loader.options"

namespace LoaderOptions
{

    /*
     * ----------------------------------------------------------------
     * Loader options exist as an independent object that can be saved and
     * loaded.
     *
     * Our optons consist of a single integer.
     */
    class COptions : public CLxLoaderOptions
    {
    public:
        int seg;

        /*
         * save() is called to save the options into a block stream.
         */
        void save(CLxUser_BlockWrite& strm) override
        {
            strm.Write(seg);
        }

        /*
         * load() is called to load the options from a block stream.
         */
        void load(CLxUser_BlockRead& strm) override
        {
            strm.Read(&seg);
        }

        /*
         * Utility to get the current options, implemented by the metaclass.
         */
        static COptions* get();
    };

    /*
     * ----------------------------------------------------------------
     * Our loader derives from the base loader class. Because a new instance of
     * this class is created for every attempt to load, we can use the normal
     * constructors and destructors to manage state.
     */
    class CLoader : public CLxLoader
    {
    public:
        CLxLineParser line_in;
        double        c_h, c_r;

        /*
         * recognize() is called with a filename and returns true if this is
         * a file that this loader can load. On success it also sets up the
         * load target with info about the contents of the file.
         *
         * We mostly fail if the file doesn't have 'ZZZ' at the front. If it
         * does we set the scene mesh-based (which is normal). The GONATIVE
         * is used because there's no saver for this format.
         */
        bool recognize(const char* filename) override
        {
            CLxUser_SceneLoaderTarget targ;

            /*
             * The loader target is specific to the class of object being
             * loaded, and is foudn by querying the loader info.
             */
            lx_err::check(targ.set(loader_info()));

            /*
             * Open the file and check the ID string. Any failure will return
             * false or raise an exception, which is also OK.
             */
            lx_err::check(line_in.fp_Open(filename), line_in.fp_ErrorCode());
            lx_err::check(line_in.lp_ReadLine(), line_in.fp_ErrorCode());

            if (!line_in.PullExpected('Z') || !line_in.PullExpected('Z') || !line_in.PullExpected('Z'))
            {
                return false;
            }

            /*
             * We've found a valid file so we just read the contents now
             * because we've got the file open.
             */
            lx_err::check(line_in.lp_ReadLine(true), line_in.fp_ErrorCode());
            lx_err::check(line_in.PullNum(&c_h));
            lx_err::check(line_in.PullNum(&c_r));

            lx_err::check(targ.SetRootType(LXsITYPE_MESH));
            lx_err::check(targ.SetFlags(LXf_SCENETARG_GONATIVE));
            return true;
        }

        /*
         * load_into() may be called if the file is recognized. The argument is
         * an object of the target type to receive the data.
         *
         * The destination is a scene, and we can use the CLxSceneBuiler class
         * to populate it. In this case a mesh item with a simple convex fan.
         */
        void load_into(ILxUnknownID dest) override
        {
            COptions*       opt;
            CLxSceneBuilder sb;
            unsigned        tip, first, last, prev;
            double          a;
            int             i, n;

            sb.Initialize(dest);
            sb.AddMesh();
            sb.SetName("CONE");

            /*
             * Get options from the loader, either from the command dialog
             * or from the master scene when loading a reference.
             */
            opt = COptions::get();
            n   = (opt ? opt->seg : 12);

            tip = sb.AddPoint(0.0, c_h, 0.0);

            for (i = 0; i <= n; i++)
            {
                if (i == n)
                    last = first;
                else
                {
                    a    = (LXx_TWOPI * i) / n;
                    last = sb.AddPoint(c_r * sin(a), 0.0, c_r * cos(a));
                }

                if (i == 0)
                    first = last;
                else
                {
                    sb.StartPoly(LXiPTYP_FACE);
                    sb.AddVertex(tip);
                    sb.AddVertex(prev);
                    sb.AddVertex(last);
                    sb.AddPolygon();
                }

                prev = last;
            }
        }
    };

    /*
     * ----------------------------------------------------------------
     * Metaclass
     *
     * Constructor sets the server name.
     */
    static CLxMeta_Loader<CLoader, COptions> load_meta(SRVNAME_LOADER);

    /*
     * This static method on the COptions class gets the options from the current
     * application state, and is used when loading.
     */
    COptions* COptions::get()
    {
        return load_meta.get_options();
    }

    /*
     * ----------------------------------------------------------------
     * A command is used to display the dialog for options, and to set the options
     * into the loader state.
     */
    class CCommand : public CLxCommand
    {
    public:
        int arg_seg;

        void setup_args(CLxAttributeDesc& desc) override
        {
            CCommand* cmd = 0;

            desc.add("segments", LXsTYPE_INTEGER);
            desc.struct_offset(&cmd->arg_seg);
        }

        void execute() override
        {
            COptions* opt;

            cmd_read_args(this);

            opt      = load_meta.set_options();
            opt->seg = arg_seg;
        }
    };

    /*
     * Metaclass
     *
     * The server name for the command is a dummy. The real command name will be
     * computed.
     */
    static CLxMeta_Command<CCommand> cmd_meta("-unused-");

    /*
     * -----------------------------------------
     * Root metaclass
     *
     *	(root)
     *	  |
     *	  +---	loader
     *		  |
     *		  +---	command (options)
     *
     * The loader metaclass needs a class (what type of object to load) and a
     * file pattern. Since the command is under the loader it's assumed to be
     * an options command, and will be given the right name based on the
     * name of the loader.
     */
    static class CRoot : public CLxMetaRoot
    {
        bool pre_init() override
        {
            load_meta.set_class(LXu_SCENE);
            load_meta.set_file_pattern("*.zzz");

            add(&load_meta);
            load_meta.add(&cmd_meta);
            return false;
        }
    } root_meta;

};  // namespace LoaderOptions
