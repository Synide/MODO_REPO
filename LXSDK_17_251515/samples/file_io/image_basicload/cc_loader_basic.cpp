/*
 * MODO SDK SAMPLE
 *
 * Image Loader server
 * ===================
 *
 *	Copyright 0000
 *
 * This implements a Loader server that loads simple images.
 *
 * For purposes of the sample this is a completely made up file format. The
 * files are plain text with the extension XXX. The first line of the file
 * is the literal string "XXX". The second line is the size of the image, and
 * the third line is the RGB color to fill the image with.
 *
 * CLASSES USED:
 *
 *		CLxLoader
 *		CLxMeta_Loader
 *
 * TESTING:
 *
 * For testing you can clip the three lines here and place them into a text
 * file, and rename it to "test.xxx". This will create a yellow 512x512 image:

XXX
512 512
255 255 0

 *
 */
#include <lx_image.hpp>
#include <lxu_io.hpp>
#include <lxu_parser.hpp>

#define SRVNAME_LOADER "csam.loader.basic"

namespace LoaderBasic
{

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
        unsigned      i_w, i_h;

        /*
         * recognize() is called with a filename and returns true if this is
         * a file that this loader can load. On success it also sets up the
         * load target with info about the contents of the file.
         *
         * We mostly fail if the file doesn't have 'XXX' at the front. If it
         * does we set the format, width and height of the target image.
         */
        bool recognize(const char* filename) override
        {
            CLxUser_ImageLoaderTarget targ;

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

            if (!line_in.PullExpected('X') || !line_in.PullExpected('X') || !line_in.PullExpected('X'))
            {
                return false;
            }

            /*
             * We've found a valid file so we read the width and height of
             * the image so we can set the destination image type & size.
             */
            lx_err::check(line_in.lp_ReadLine(), line_in.fp_ErrorCode());
            lx_err::check(line_in.PullNum(&i_w));
            lx_err::check(line_in.PullNum(&i_h));

            lx_err::check(i_w > 0 && i_h > 0);
            lx_err::check(targ.SetSize(LXiIMP_RGB24, i_w, i_h));
            return true;
        }

        /*
         * load_into() may be called if the file is recognized. The argument is
         * an object of the target type to receive the data.
         */
        void load_into(ILxUnknownID dest) override
        {
            /*
             * Read the next line to get the fill color.
             */
            unsigned r, g, b;

            lx_err::check(line_in.lp_ReadLine(), line_in.fp_ErrorCode());
            lx_err::check(line_in.PullNum(&r));
            lx_err::check(line_in.PullNum(&g));
            lx_err::check(line_in.PullNum(&b));

            /*
             * Set all pixels to the color in destination image.
             */
            CLxUser_ImageWrite wimg(dest);
            unsigned char      pixel[3];
            unsigned           x, y;

            pixel[0] = r;
            pixel[1] = g;
            pixel[2] = b;

            for (y = 0; y < i_h; y++)
                for (x = 0; x < i_w; x++)
                    lx_err::check(wimg.SetPixel(x, y, LXiIMP_RGB24, pixel));
        }
    };

    /*
     * ----------------------------------------------------------------
     * Metaclass
     *
     * Constructor sets the server name.
     */
    static CLxMeta_Loader<CLoader> load_meta(SRVNAME_LOADER);

    /*
     * ----------------------------------------------------------------
     * Root metaclass
     *
     *	(root)
     *	  |
     *	  +---	loader
     *
     * The loader metaclass needs a class (what type of object to load) and a
     * file pattern.
     */
    static class CRoot : public CLxMetaRoot
    {
        bool pre_init() override
        {
            load_meta.set_class(LXu_IMAGE);
            load_meta.set_file_pattern("*.xxx");

            add(&load_meta);
            return false;
        }
    } root_meta;

};  // namespace LoaderBasic
