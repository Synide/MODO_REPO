/*
 * MODO SDK SAMPLE
 *
 * DrawingOverride package server
 * ==============================
 *
 *	Copyright 0000
 *
 * This implements a Package server that performs pass-level drawing overrides.
 *
 * CLASSES USED:
 *
 *		CLxDrawingOverride
 *		CLxPackage
 *		CLxMeta_DrawingOverride
 *		CLxMeta_Package
 *
 * TESTING
 *
 * This can be tested by adding the package to an item using this command:
 *
 *	item.addPackage csam.drawover.pass
 */
#include <GL/glew.h>
#include <lx_log.hpp>
#include <lxu_drawover.hpp>
#include <lxu_package.hpp>

#define SRVNAME_PACKAGE "csam.drawover.pass"

/*
 * ------------------------------------------------------------
 * This is a utility function to check for any OpenGL errors. It's not required
 * for clients to use this, and is only present in the sample for testing.
 */
#define checkGL() _check_gl_error(__FILE__, __LINE__)

void _check_gl_error(const char* file, int line)
{
    GLenum err;

    err = glGetError();

    while (err != GL_NO_ERROR)
    {
        const char* error;

        switch (err)
        {
            case GL_INVALID_OPERATION:
                error = "INVALID_OPERATION";
                break;
            case GL_INVALID_ENUM:
                error = "INVALID_ENUM";
                break;
            case GL_INVALID_VALUE:
                error = "INVALID_VALUE";
                break;
            case GL_OUT_OF_MEMORY:
                error = "OUT_OF_MEMORY";
                break;
            case GL_INVALID_FRAMEBUFFER_OPERATION:
                error = "INVALID_FRAMEBUFFER_OPERATION";
                break;
            default:
                error = "UNKNOWN";
        }

        CLxUser_LogService lS;
        lS.DebugOut(LXi_DBLOG_NORMAL, "GL error %d %s (%s : %d)\n", err, error, file, line);
        err = glGetError();
    }
}

namespace DrawoverPass
{

/*
 * ------------------------------------------------------------
 * Declarations needed for drawing our OpenGL test object.
 */
#define VBOi_VERTEX 0
#define VBOi_NORMAL 1
#define VBOi_COLOR  2
#define VBOi_INDEX  3
#define VBOi_COUNT  4

    static bool   init_glew = true;
    static GLuint vbo[VBOi_COUNT];
    static float  vertices[] = { 0.0, 5.0, 0.0, 5.0, -5.0, 0.0, -5.0, -5.0, 0.0 };

    static float normals[] = { 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0 };

    static float colors[] = { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 };

    static unsigned int indices[] = { 0, 1, 2 };

    /*
     * ------------------------------------------------------------
     * Our implementation is done by customizing the CLxDrawingOverride class.
     * This will be added to the Package.
     *
     * There will be multiple instances of this class created. One persistent
     * instance will be used for setup() and cleanup(). Other instances will be
     * created for drawing, depending on how many viewports are in the GUI.
     */
    class CDrawingOverride : public CLxDrawingOverride
    {
    public:
        /*
         * pass_setup() is called when the first packge of our type is added
         * to any scene. Our state will stay setup as long as there are any
         * of our type of packages in any scenes (even inactive ones).
         */
        void pass_setup() override
        {
            /*
             * Init glew on the first call to setup.
             */
            if (init_glew)
            {
                glewInit();
                init_glew = false;
            }

            /*
             * Allocate the VBOs needed for our geometry.
             */
            checkGL();
            glGenBuffers(VBOi_COUNT, vbo);
            checkGL();

            /*
             * Initialize VBOs from our static arrays.
             */
            glBindBuffer(GL_ARRAY_BUFFER, vbo[VBOi_VERTEX]);
            glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 9, vertices, GL_STATIC_DRAW);
            glBindBuffer(GL_ARRAY_BUFFER, 0);
            checkGL();

            glBindBuffer(GL_ARRAY_BUFFER, vbo[VBOi_NORMAL]);
            glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 9, normals, GL_STATIC_DRAW);
            glBindBuffer(GL_ARRAY_BUFFER, 0);
            checkGL();

            glBindBuffer(GL_ARRAY_BUFFER, vbo[VBOi_COLOR]);
            glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 9, colors, GL_STATIC_DRAW);
            glBindBuffer(GL_ARRAY_BUFFER, 0);
            checkGL();

            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo[VBOi_INDEX]);
            glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * 3, indices, GL_STATIC_DRAW);
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
            checkGL();
        }

        /*
         * pass_cleanup() is only called once all packages of our type have
         * been removed from all scenes in the session. Even after this
         * pass_setup() may be called again if the package is added again.
         */
        void pass_cleanup() override
        {
            /*
             * Release our VBOs, allowing them to be reused.
             */
            checkGL();
            glDeleteBuffers(VBOi_COUNT, vbo);
            checkGL();

            for (int i = 0; i < VBOi_COUNT; i++)
                vbo[i] = 0;
        }

        /*
         * pass_draw() is called during the solid drawing pass for all 3D
         * viewports then they are redrawing any scene that contains our
         * package anywhere.
         *
         * The state of the viewport can be read by calling self functions:
         *
         *	pass_view()	- the CLxUser_View3D for the view being drawn
         *	pass_scene()	- the CLxUser_Scene for the view being drawn
         *
         * The view and scene remain the same for any instance of this class. If
         * a new combination of view and scene are needed then a new instance is
         * created.
         */
        void pass_draw() override
        {
            /*
             * Bind our VBOs to the output state.
             */
            checkGL();
            glBindBuffer(GL_ARRAY_BUFFER, vbo[VBOi_VERTEX]);
            glEnableClientState(GL_VERTEX_ARRAY);
            glVertexPointer(3, GL_FLOAT, 0, (float*) NULL);
            checkGL();

            glBindBuffer(GL_ARRAY_BUFFER, vbo[VBOi_NORMAL]);
            glEnableClientState(GL_NORMAL_ARRAY);
            glNormalPointer(GL_FLOAT, 0, (float*) NULL);
            checkGL();

            glBindBuffer(GL_ARRAY_BUFFER, vbo[VBOi_COLOR]);
            glEnableClientState(GL_COLOR_ARRAY);
            glColorPointer(3, GL_FLOAT, 0, (float*) NULL);
            checkGL();

            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo[VBOi_INDEX]);
            checkGL();

            /*
             * Do the drawing -- a triangle with RGB at the corners.
             */
            glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, (unsigned int*) NULL);
            checkGL();

            /*
             * Clean up nicely to be a good citizen.
             */
            glDisableClientState(GL_VERTEX_ARRAY);
            glDisableClientState(GL_NORMAL_ARRAY);
            glDisableClientState(GL_COLOR_ARRAY);

            glBindBuffer(GL_ARRAY_BUFFER, 0);
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

            checkGL();
        }
    };

    /*
     * ------------------------------------------------------------
     * Metaclasses
     *
     * Our package uses a default implementation, but that could be overridden.
     */
    static CLxMeta_Package<CLxPackage>               pkg_meta(SRVNAME_PACKAGE);
    static CLxMeta_DrawingOverride<CDrawingOverride> draw_meta;

    /*
     * ------------------------------------------------------------
     * Root metaclass
     *
     *	(root)
     *	  |
     *	  +---	package
     *		  |
     *		  +---	drawover
     *
     * We set our drawover state to pass drawing, to enable those methods.
     */
    static class CRoot : public CLxMetaRoot
    {
        bool pre_init() override
        {
            draw_meta.set_flags(LXfDRAWOVER_PASS_SOLID);

            add(&pkg_meta);
            pkg_meta.add(&draw_meta);
            return false;
        }
    } root_meta;

};  // namespace DrawoverPass
