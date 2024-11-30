/*
 * LX arrayui module
 *
 * Copyright 0000
 */
#ifndef LX_arrayui_H
#define LX_arrayui_H



/*
 * When an array channel is selected that contains either Matrix4, Distance3 or
 * Float3 value types, the array values will be drawn in the GL viewport as a
 * series of axis, aligned to the values stored in the array. By default, if no
 * channel is selected, no array values will be drawn, however this behaviour can
 * be overridden by the item type, by declaring the following server tag with a
 * value matching the name of the array channel that should be drawn by default.
 * If the item is selected, but no array channels are selected, the channel defined
 * in the server tag will be drawn.
 */

	#define LXsPKG_ARRAY_DRAW_CHANNEL	"array.drawChannel"

#endif