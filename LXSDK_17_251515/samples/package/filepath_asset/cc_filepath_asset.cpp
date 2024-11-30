/*
 * MODO SDK SAMPLE
 *
 * InstanceAssets interface
 * ========================
 *
 *	Copyright 0000
 *
 * This implements an InstanceAssets interface on a package with filepath
 * channels.
 *
 * CLASSES USED:
 *
 *		CLxInstanceAssets
 *		CLxPackage
 *		CLxMeta_InstanceAssets
 *		CLxMeta_Package
 *
 * TESTING:
 *
 * - add the item
 * - allocate a SceneAssets object for the scene
 * - check that the assets are listed
 * - read the asset paths
 * - set the asset paths and pattern
 *
 * These same tests can be done with USE_ASSETIFC define and not defined. It
 * should work in both cases except that setting the pattern will only reset
 * the start and end if the asset interface is used.
 */
#include <lx_file.hpp>
#include <lxidef.h>
#include <lxu_package.hpp>

#define SRVNAME_PACKAGE "csam.filepath.asset"

#define USE_ASSETIFC

namespace FilepathAsset
{

/*
 * ----------------------------------------------------------------
 * This defines the channel description as well as the structure that
 * contains channel values. Channels are set to read and are enabled
 * for nodal overrides.
 */
#define Cs_FILENAME "filename"
#define Cs_PATTERN  "pattern"
#define Cs_START    "startFrame"
#define Cs_END      "endFrame"

    class CChannels : public CLxChannels
    {
    public:
        std::string cv_filename;
        std::string cv_pattern;
        int         cv_start;
        int         cv_end;

        /*
         * init_chan() is called on initialization to define the channels for
         * this item using a CLxAttributeDesc object.
         */
        void init_chan(CLxAttributeDesc& desc) override
        {
            static LXtTextValueHint filename_hint[] = { 0, "@" LXa_IMAGE, -1, 0 };
            static LXtTextValueHint pattern_hint[]  = { 0, "@[]txt", -1, 0 };
            CChannels*              chan            = 0;

            desc.add(Cs_FILENAME, LXsTYPE_FILEPATH);
            desc.struct_offset(&chan->cv_filename);
            desc.set_hint(filename_hint);

            desc.add(Cs_PATTERN, LXsTYPE_FILEPATH);
            desc.struct_offset(&chan->cv_pattern);
            desc.set_hint(pattern_hint);

            desc.add(Cs_START, LXsTYPE_INTEGER);
            desc.struct_offset(&chan->cv_start);

            desc.add(Cs_END, LXsTYPE_INTEGER);
            desc.struct_offset(&chan->cv_end);
        }
    };

#ifdef USE_ASSETIFC

    /*
     * ----------------------------------------------------------------
     * This class allows items to manage their own external assets.
     */
    class CAssets : public CLxInstanceAssets
    {
    public:
        CLxUser_FileService file_S;

        void get_assets(CLxUser_Item& item)
        {
            add_asset(Cs_FILENAME, LXa_IMAGE);
            add_asset(Cs_PATTERN, "txt", 0, true);
        }

        std::string get_path(CLxUser_Item& item, const char* ident)
        {
            CLxUser_ChannelRead read;
            std::string         path;

            read.from(item);
            lx_err::check(read.Get(item, ident, path));
            return path;
        }

        void set_path(CLxUser_Item& item, const char* ident, const char* path)
        {
            CLxUser_ChannelWrite write;
            unsigned             type, first, last;

            write.from(item);

            if (strcmp(ident, Cs_FILENAME) == 0)
            {
                lx_err::check(file_S.TestFileType(path, &type));
                if (type != LXiFILETYPE_NORMAL)
                    throw(LXe_INVALIDARG);

                lx_err::check(write.Set(item, ident, path));
            }
            else if (strcmp(ident, Cs_PATTERN) == 0)
            {
                lx_err::check(file_S.FindSequenceBounds(path, &first, &last));

                lx_err::check(write.Set(item, ident, path));
                lx_err::check(write.Set(item, Cs_START, first));
                lx_err::check(write.Set(item, Cs_END, last));
            }
            else
                throw(LXe_NOTFOUND);
        }
    };

#endif

    /*
     * ------------------------------------------------------------
     * Metaclasses
     *
     * The name of the server is passed to the constructor.
     */
    static CLxMeta_Channels<CChannels> chan_meta;
    static CLxMeta_Package<CLxPackage> pkg_meta(SRVNAME_PACKAGE);
#ifdef USE_ASSETIFC
    static CLxMeta_InstanceAssets<CAssets> ass_meta;
#endif

    /*
     * ------------------------------------------------------------
     * Metaclass declaration.
     *
     *	root
     *	 |
     *	 +---	channels
     *	 |
     *	 +---	package (server)
     *		 |
     *		 +---	assets (interface)
     *
     */
    static class CRoot : public CLxMetaRoot
    {
        bool pre_init() override
        {
            pkg_meta.set_supertype(LXsITYPE_LOCATOR);
#ifdef USE_ASSETIFC
            pkg_meta.add(&ass_meta);
#endif

            add(&chan_meta);
            add(&pkg_meta);
            return false;
        }

    } root_meta;

};  // namespace FilepathAsset
