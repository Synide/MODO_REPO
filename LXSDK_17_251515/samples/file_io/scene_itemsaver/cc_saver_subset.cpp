/*
 * MODO SDK SAMPLE
 *
 * Scene and Subset Saver server
 * =============================
 *
 *	Copyright 0000
 *
 * This implements a Saver server that saves scenes, or subsets of scenes from
 * "Export Selected".
 *
 * For purposes of the sample the output file just contains a list of item names.
 *
 * CLASSES USED:
 *
 *		CLxSaver
 *		CLxMeta_Saver
 *
 * TESTING:
 *
 * - From "File > Export..." pick this format and save. File shoud contain the
 *   names of all the items in the scene.
 *
 * - Select some items, right-click and pick "Save Selected". Different options
 *   will create one or more output files with selected and related items.
 */
#include <lx_item.hpp>
#include <lx_package.hpp>
#include <lxu_format.hpp>
#include <lxu_io.hpp>

#define SRVNAME_SAVER "csam.saver.subset"

namespace SaverSubset
{

    /*
     * This helper class tests an item to see if it should be saved. If there's
     * a collection we delegate to that, otherwise save all items.
     */
    class ItemTester
    {
    public:
        CLxUser_ItemCollection i_c;

        bool UseItem(CLxUser_Item& item)
        {
            if (i_c.test())
                return (i_c.Test(item) == LXe_TRUE);

            return true;
        }
    };

    /*
     * ----------------------------------------------------------------
     * Because our saver doesn't know the type of object that's being passed
     * a-priori we don't derive from the template. Instead we get the raw object.
     * A new instance of this class is allocated for every save, so we can rely
     * on the destructor to manage some cleanup.
     *
     */
    class CSaver : public CLxSaver
    {
    public:
        CLxLineFormat line_out;

        /*
         * obj_save() is called with the source object, the filename
         * to save to, and a monitor that can be used to track progress.
         *
         * We may get a scene or a subset. Depending on what we get we init
         * the scene object and the tester. The saving after that is the same,
         * enumerating items and getting their names..
         */
        void obj_save(ILxUnknownID source, const char* filename, CLxUser_Monitor& mon) override
        {
            CLxUser_SceneSubset subset;
            CLxUser_Scene       scene;
            CLxUser_Item        item;
            ItemTester          tester;
            unsigned            i, n;

            if (subset.set(source))
            {
                lx_err::check(subset.GetScene(scene));
                lx_err::check(subset.GetCollection(tester.i_c));
            }
            else
                lx_err::check(scene.set(source));

            line_out.ff_Open(filename);
            line_out.lf_Output("hi!");
            line_out.lf_Break();

            lx_err::check(scene.ItemCount(LXiTYPE_ANY, &n));
            for (i = 0; i < n; i++)
            {
                const char* name;

                lx_err::check(scene.ItemByIndex(LXiTYPE_ANY, i, item));
                if (!tester.UseItem(item))
                    continue;

                lx_err::check(item.UniqueName(&name));

                line_out.lf_Output(name);
                line_out.lf_Break();
            }

            lx_err::check(!line_out.ff_HasError());
        }

        /*
         * obj_verify() is called with the source object and a message
         * which can be used to report any errors or warnings before the
         * user saves.
         *
         * This function does nothing but needs to be defined.
         */
        void obj_verify(ILxUnknownID source, CLxUser_Message& msg) override
        {
        }
    };

    /*
     * ----------------------------------------------------------------
     * Metaclass
     *
     * Constructor sets the server name.
     */
    static CLxMeta_Saver<CSaver> save_meta(SRVNAME_SAVER);

    /*
     * ----------------------------------------------------------------
     * Root metaclass
     *
     *	(root)
     *	  |
     *	  +---	saver
     *
     * The saver metaclass needs a class (what type of object to save) and a
     * file extension. We also add the tag that indicates we support subsets.
     */
    static class CRoot : public CLxMetaRoot
    {
        bool pre_init() override
        {
            save_meta.set_class(LXu_SCENE);
            save_meta.set_file_extension("TINL");
            save_meta.add_tag(LXsSAV_SCENE_SUBSET, LXsSUBSET_ALL);

            add(&save_meta);
            return false;
        }
    } root_meta;

};  // namespace SaverSubset
