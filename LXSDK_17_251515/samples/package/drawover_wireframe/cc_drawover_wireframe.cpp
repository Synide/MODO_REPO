/*
 * MODO SDK SAMPLE
 *
 * Drawing Overrides Style Items Example
 * ======================
 *
 *	Copyright 0000
 *
 * This implements a package class that will
 * affect the drawing style of any items it is
 * added to.
 *
 * CLASSES USED:
 *
 *		CLxDrawingOverride
 *		CLxMeta_DrawingOverride
 *		CLxPackage
 *		CLxMeta_Package
 *
 * TESTING:
 *
 *	This can be tested by selecting a mesh and
 *	running "item.addPackage csam.drawover.wireframe"
 */

#include <lxu_drawover.hpp>
#include <lxu_package.hpp>

#define SRVNAME_ITEMTYPE "csam.drawover.wireframe"

namespace csam_drawover_wireframe
{

    /*
     * To test if an item is a certain type, we can use the
     * CLxItemType class and pass the item type's string
     * name into the constructor.  We create a static instance
     * the "mesh" item type to use later.
     */
    static CLxItemType cit_mesh(LXsITYPE_MESH);

    /*
     * ----------------------------------------------------------------
     * Our drawing override class allows us to control the drawing
     * style of any items we want.  We will loop through the scene's
     * items and tell it to override any mesh items that have our
     * custom package on them.
     */

    class CDraw : public CLxDrawingOverride
    {
        /*
         * When a plugin invalidates drawing overrides through
         * the viewport service or through the meta class,
         * the drawing override plugin's style_items function
         * is called and the current scene is passed in.
         * We can then loop through the existing mesh items and
         * check if they have our package type.
         */
        void style_items(CLxUser_Scene& scene)
        {
            CLxUser_Item tmpItem;
            unsigned     meshCount, i;

            /*
             * To find the number of items of a given type in a scene,
             * we cast the cit_mesh object to LXtItemType which looks up the code.
             * The string names (eg LXsITYPE_MESH) are defined in lxidef.h
             */
            scene.ItemCount(cit_mesh, &meshCount);
            for (i = 0; i < meshCount; i++)
            {
                scene.ItemByIndex(cit_mesh, i, tmpItem);
                if (tmpItem.PackageTest(SRVNAME_ITEMTYPE) == LXe_TRUE)
                {
                    /*
                     * For each item we want to override drawing style
                     * on, we call "add_item" which is an inherited function
                     * that belongs to this CLxDrawingOverride class.  This
                     * adds the item to the list of items to override.  Then
                     * we can call set_wireframe_color or set_ghost_color as
                     * we need.
                     */
                    add_item(tmpItem);
                    set_wireframe_color(0.0, 0.5, 1.0, 0.5);
                }
            }
        }
    };

    /*
     * ------------------------------------------------------------
     * Drawing Override Metaclass
     *
     * The drawing meta_class will be used in the package, so
     * we create an instance of it here by passing in our
     * custom template class.  It doesn't require its own server name.
     */
    static CLxMeta_DrawingOverride<CDraw> draw_meta;

    /*
     * Our package is incredibly simple.  Each time the
     * package is added or removed from an item, we just
     * invalidate the override drawing.  This forces the
     * override's "style_items" function to refire, and our
     * special drawing styles are brought up to date.
     */

    class CDrawPackage : public CLxPackage
    {
    public:
        /*
         * Any time our package is added to or removed from an
         * item in the scene, we'll get one of these functions called.
         * The package automatically stores the item it belongs to as
         * m_item, and we can use that to do the invalidation.
         */
        void add()
        {
            draw_meta.invalidate_style(m_item);
        }
        void remove()
        {
            draw_meta.invalidate_style(m_item);
        }
    };

    /*
     * ------------------------------------------------------------
     * Package Metaclass
     *
     * The package is just a default package which calls our drawing override
     * Metaclass's "invalidate_style" function on add and remove.  We need to
     * pass it our templated class and a server name for the constructor.
     */
    static CLxMeta_Package<CDrawPackage> pkg_meta(SRVNAME_ITEMTYPE);

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
     * We set our drawover state to Item Styles, to let the system know
     * we intend to affect the item drawing styles.
     */
    static class CRoot : public CLxMetaRoot
    {
        bool pre_init() override
        {
            add(&pkg_meta);
            pkg_meta.add(&draw_meta);
            draw_meta.set_flags(LXfDRAWOVER_ITEM_STYLES);

            return false;
        }
    } root_meta;

};  // namespace csam_drawover_wireframe
