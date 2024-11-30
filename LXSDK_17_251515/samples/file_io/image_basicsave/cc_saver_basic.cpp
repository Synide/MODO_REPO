/*
 * MODO SDK SAMPLE
 *
 * Image Saver server
 * ==================
 *
 *	Copyright 0000
 *
 * This implements a Saver server that saves images.
 *
 * For purposes of the sample this doesn't export an entire image. We'll just
 * write the size of the image and be done with it.
 *
 * CLASSES USED:
 *
 *		CLxSaverT<>
 *		CLxMeta_Saver
 *
 * TESTING:
 *
 * Right click on an image and save it. Pick this format. The file written
 * should contain the width and height of the image.
 */
#include <lx_image.hpp>
#include <lxu_format.hpp>
#include <lxu_io.hpp>

#define SRVNAME_SAVER "csam.saver.basic"

namespace SaverBasic
{

    /*
     * ----------------------------------------------------------------
     * Our saver derives from the template saver class, specialized for images.
     * Because a new instance of this class is allocated for every save, we
     * can rely on the destructor to manage some cleanup.
     */
    class CSaver : public CLxSaverT<CLxUser_Image>
    {
    public:
        CLxLineFormat line_out;

        /*
         * save() is called with the object given in the template, the filename
         * to save to, and a monitor that can be used to track progress.
         */
        void save(CLxUser_Image& image, const char* filename, CLxUser_Monitor& mon) override
        {
            unsigned w, h;

            line_out.ff_Open(filename);

            image.Size(&w, &h);
            line_out.lf_Output(w);
            line_out.lf_Break();
            line_out.lf_Output(h);

            lx_err::check(!line_out.ff_HasError());
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
     * file extension.
     */
    static class CRoot : public CLxMetaRoot
    {
        bool pre_init() override
        {
            save_meta.set_class(LXu_IMAGE);
            save_meta.set_file_extension("YYY");

            add(&save_meta);
            return false;
        }
    } root_meta;

};  // namespace SaverBasic
