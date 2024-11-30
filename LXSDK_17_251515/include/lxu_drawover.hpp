/*
 * Plug-in SDK Header: C++ Services
 *
 * Copyright 0000
 *
 * Helper classes for implementing package servers.
 */
#ifndef LXU_DRAWOVER_HPP
#define LXU_DRAWOVER_HPP

#include <lxu_meta.hpp>
#include <lx_drawover.hpp>
#include <lx_item.hpp>
#include <lx_vp.hpp>


/*
 * DrawingOverride is an interface that can be added to a package server
 * to permits the package, when present in a scene, to do full GL drawing or
 * style overrides.
 */
class CLxDrawingOverride :
		public CLxObject
{
    public:
	/*
	 * Implement this to select items for style overrides. For each item
	 * call add_item() and then select the overrides.
	 */
	virtual void	style_items (CLxUser_Scene &/*scene*/) {}

	/*
	 * Call this to set a style override for this item.
	 */
	void		add_item (CLxUser_Item &item, unsigned flags = 0);

	/*
	 * Call this to set ghosting color for an overridde.
	 */
	void		set_ghost_color (double r, double g, double b, double a);

	/*
	 * Call this to set wireframe color for an overridde.
	 */
	void		set_wireframe_color (double r, double g, double b, double a);

	/*
	 * Implement to perform global setup for pass drawing. This is called
	 * when the first package implementing this method is added.
	 */
	virtual void	pass_setup () {}

	/*
	 * Implement to cleanup global state for pass drawing. This is called
	 * when the last package implementing this method is destroyed.
	 */
	virtual void	pass_cleanup () {}

	/*
	 * Implement to execute pass drawing. This is called for each combination
	 * of view and scene visible in the application.
	 */
	virtual void	pass_draw () {}

	/*
	 * Call to get the scene for the pass.
	 */
	CLxUser_Scene &	pass_scene ();

	/*
	 * Call to get the view for the pass.
	 */
	CLxUser_View3D & pass_view ();

    //internal:
	 CLxDrawingOverride ();
	~CLxDrawingOverride ();

	class pv_DrawingOverride	*pv;
};

class CLxMeta_DrawingOverride_Core :
		public CLxMeta
{
    public:
	/*
	 * Set drawing to indicate the type of drawing.
	 */
	void	set_flags (unsigned flags);

	/*
	 * Invalidate the style overrides based on a scene.
	 */
	void	invalidate_style (CLxUser_Scene &);

	/*
	 * Invalidate the style overrides based on an item.
	 */
	void	invalidate_style (CLxUser_Item &);

    //internal:
	CLxMeta_DrawingOverride_Core ();

	class pv_Meta_DrawingOverride	*mpv;

	virtual CLxDrawingOverride *	 new_inst () = 0;
	void *			 alloc () override;
};

template <class T>
class CLxMeta_DrawingOverride :
		public CLxMeta_DrawingOverride_Core
{
    public:
    //internal:
		CLxDrawingOverride *
	new_inst () override
	{
		return new T;
	}
};

#endif // LXU_DRAWOVER_HPP
