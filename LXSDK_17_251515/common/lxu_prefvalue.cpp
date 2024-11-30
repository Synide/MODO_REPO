/*
 * Plug-in SDK Header: Common Utility
 *
 * Copyright 0000
 *
 * Preference value access.  This is implemented as a helper utility to
 * encapsulate the command interfaces, which are undocumented and subject
 * to change.
 */
#include <lx_command.hpp>
#include <lxu_prefvalue.hpp>

/*
 * Scene Export preference values.
 */
const char* LXsPREFERENCE_VALUE_EXPORT_AUTHOR        = "export.author";
const char* LXsPREFERENCE_VALUE_EXPORT_COPYRIGHT     = "export.copyright";
const char* LXsPREFERENCE_VALUE_EXPORT_ABSOLUTE_PATH = "export.absPath";
const char* LXsPREFERENCE_VALUE_EXPORT_MERGE_REFS    = "export.mergsRefs";

/*
 * Accuracy and Units preference values.
 */
const char* LXsPREFERENCE_VALUE_ACCURACY_UNIT_SYSTEM  = "units.system";
const char* LXsPREFERENCE_VALUE_METERS_PER_GAME_UNIT  = "units.gameScale";
const char* LXsPREFERENCE_VALUE_ACCURACY_DEFAULT_UNIT = "units.default";

/*
 * Up Axis.
 */
const char* LXsPREFERENCE_VALUE_ACCURACY_UP_AXIS = "units.upAxis";

/*
 * Animation.
 */

const char* LXsPREFERENCE_VALUE_ANIMATION_FPS_FILM_24 = "film";
const char* LXsPREFERENCE_VALUE_ANIMATION_FPS_PAL_25  = "pal";
const char* LXsPREFERENCE_VALUE_ANIMATION_FPS_NTSC_29 = "ntsc29";
const char* LXsPREFERENCE_VALUE_ANIMATION_FPS_NTSC_30 = "ntsc30";
const char* LXsPREFERENCE_VALUE_ANIMATION_FPS_CUSTOM  = "custom";

const char* LXsPREFERENCE_VALUE_ANIMATION_AUTO_KEY              = "animation.autoKey";
const char* LXsPREFERENCE_VALUE_ANIMATION_CHANNEL_BEHAVIOR      = "animation.envBehavior";
const char* LXsPREFERENCE_VALUE_ANIMATION_CHANNEL_INTERPOLATION = "animation.envInterp";
const char* LXsPREFERENCE_VALUE_ANIMATION_FPS                   = "animation.fps";
const char* LXsPREFERENCE_VALUE_ANIMATION_FPS_CUSTOM_RATE       = "animation.fpsCustom";
const char* LXsPREFERENCE_VALUE_ANIMATION_LINK_KEYS             = "animation.linkKeys";
const char* LXsPREFERENCE_VALUE_ANIMATION_PRESERVE_KEY_TIMING   = "animation.fpsKeepTiming";
const char* LXsPREFERENCE_VALUE_ANIMATION_ROTATION_ORDER        = "animation.rotOrder";
const char* LXsPREFERENCE_VALUE_ANIMATION_SLOPE_TYPE            = "animation.slopeType";
const char* LXsPREFERENCE_VALUE_ANIMATION_TIME_RANGE_START      = "animation.timeRangeS";
const char* LXsPREFERENCE_VALUE_ANIMATION_TIME_RANGE_END        = "animation.timeRangeE";
const char* LXsPREFERENCE_VALUE_ANIMATION_TIME_SNAP             = "animation.timeSnap";
const char* LXsPREFERENCE_VALUE_ANIMATION_TIME_SYSTEM           = "animation.timeSys";
