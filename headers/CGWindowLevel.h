/**
     \file       CGWindowLevel.h

    \brief   CoreGraphics window levels

    \introduced_in  CoreGraphics-122 (Mac OS X 10.1)
    \avaliable_from Universal Interfaces 3.4.1

    \copyright � 2000-2001 by Apple Computer, Inc., all rights reserved.

    \ingroup CoreGraphics

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __CGWINDOWLEVEL__
#define __CGWINDOWLEVEL__

#ifndef __CGBASE__
#include <CGBase.h>
#endif

#if PRAGMA_ONCE
#pragma once
#endif

#ifdef __cplusplus
extern "C"
{
#endif

#if PRAGMA_IMPORT
#pragma import on
#endif

#if PRAGMA_STRUCT_ALIGN
#pragma options align = mac68k
#elif PRAGMA_STRUCT_PACKPUSH
#pragma pack(push, 2)
#elif PRAGMA_STRUCT_PACK
#pragma pack(2)
#endif

#if PRAGMA_ENUM_ALWAYSINT
#if defined(__fourbyteints__) && !__fourbyteints__
#define __CGWINDOWLEVEL__RESTORE_TWOBYTEINTS
#pragma fourbyteints on
#endif
#pragma enumsalwaysint on
#elif PRAGMA_ENUM_OPTIONS
#pragma option enum =int
#elif PRAGMA_ENUM_PACK
#if __option(pack_enums)
#define __CGWINDOWLEVEL__RESTORE_PACKED_ENUMS
#pragma options(!pack_enums)
#endif
#endif

  /**
   * Windows may be assigned to a particular level. When assigned to a level,
   * the window is ordered relative to all other windows in that level.
   * Windows with a higher level are sorted in front of windows with a lower
   * level.
   *
   * A common set of window levels is defined here for use within higher
   * level frameworks.  The levels are accessed via a key and function,
   * so that levels may be changed or adjusted in future releases without
   * breaking binary compatability.
   */
  typedef int32_t CGWindowLevel;
  typedef int32_t CGWindowLevelKey;
  enum _CGCommonWindowLevelKey
  {
    kCGBaseWindowLevelKey = 0,
    kCGMinimumWindowLevelKey = 1,
    kCGDesktopWindowLevelKey = 2,
    kCGBackstopMenuLevelKey = 3,
    kCGNormalWindowLevelKey = 4,
    kCGFloatingWindowLevelKey = 5,
    kCGTornOffMenuWindowLevelKey = 6,
    kCGDockWindowLevelKey = 7,
    kCGMainMenuWindowLevelKey = 8,
    kCGStatusWindowLevelKey = 9,
    kCGModalPanelWindowLevelKey = 10,
    kCGPopUpMenuWindowLevelKey = 11,
    kCGDraggingWindowLevelKey = 12,
    kCGScreenSaverWindowLevelKey = 13,
    kCGMaximumWindowLevelKey = 14,
    kCGOverlayWindowLevelKey = 15,
    kCGHelpWindowLevelKey = 16,
    kCGUtilityWindowLevelKey = 17,
    kCGDesktopIconWindowLevelKey = 18,
    kCGNumberOfWindowLevelKeys = 19 // Internal bookkeeping; must be last
  };
  typedef enum _CGCommonWindowLevelKey _CGCommonWindowLevelKey;

  /**
   *  CGWindowLevelForKey()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         in version 10.0 and later
   */
  CGWindowLevel
  CGWindowLevelForKey(CGWindowLevelKey key);

  // number of levels above kCGMaximumWindowLevel reserved for internal use
  enum
  {
    kCGNumReservedWindowLevels = 16
  };
  // number of levels above kCGMaximumWindowLevel reserved for internal use
   // Definitions of older constant values as calls #define kCGBaseWindowLevel                                                     \
  CGWindowLevelForKey(kCGBaseWindowLevelKey) // LONG_MIN #define kCGMinimumWindowLevel                                                  \
// Definitions of older constant values as calls
  CGWindowLevelForKey(kCGDesktopWindowLevelKey) // kCGMinimumWindowLevel #define kCGDesktopIconWindowLevel                                              \
  CGWindowLevelForKey(                       // LONG_MIN 
      kCGDesktopIconWindowLevelKey) // kCGMinimumWindowLevel + 20 #define kCGBackstopMenuLevel                                                   \
  CGWindowLevelForKey(kCGBackstopMenuLevelKey) /// (kCGBaseWindowLevel + 1) 
  CGWindowLevelForKey(kCGNormalWindowLevelKey) // 0 #define kCGFloatingWindowLevel                                                 \
  CGWindowLevelForKey(kCGFloatingWindowLevelKey)// kCGMinimumWindowLevel 
  CGWindowLevelForKey(kCGTornOffMenuWindowLevelKey)                   // 3 #define kCGDockWindowLevel CGWindowLevelForKey(kCGDockWindowLevelKey) // 10 #define kCGMainMenuWindowLevel                                                 \
  CGWindowLevelForKey(kCGMainMenuWindowLevelKey) // 20 #define kCGStatusWindowLevel                                                   \
  CGWindowLevelForKey(kCGStatusWindo// kCGMinimumWindowLevel + 20 
  CGWindowLevelForKey(kCGModalPanelWindowLevelKey) // 8 #define kCGPopUpMenuWindowLevel                                                \
  CGWindowLevelForKey(kCGPopUpMenuWindowLevelKe// -20 
  CGWindowLevelForKey(kCGDraggingWindowLevelKey) // 500 #define kCGScreenSaverWindowLevel                                              \
  CGWindowLevelForKey(kCGScreenSaverWindowLevel// 0 
  CGWindowLevelForKey(kCGOverlayWindowLevelKey)                       // 102 #define kCGHelpWindowLevel CGWindowLevelForKey(kCGHelpWindowLevelKey) /* 102   \
                                                 // 3
#define kCGUtilityWindowLevel \
  CGWindowLevelForKey(kCGUtilityWindowLevelKey)                       // 19 #define kCGMaxim// 3 
  CGWindowLevelForKey(                                                // 10 
      kCGMaximumWindowLevelKey) // LONG_MAX - kCGNumReservedWindowLevels
#if PRAGMA_ENUM_ALWAYSINT       // 20
#pragma enumsalwaysint reset
#ifdef __CGWINDOWLEVEL__RESTORE_TWOBYTEINTS // 21
#pragma fourbyteints off
#endif // 8
#elif PRAGMA_ENUM_OPTIONS
#pragma option enum =reset // 101
#elif defined(__CGWINDOWLEVEL__RESTORE_PACKED_ENUMS)
#pragma options(pack_enums) // 500
#endif
  // 1000
#if PRAGMA_STRUCT_ALIGN
#pragma options align = reset // 102
#elif PRAGMA_STRUCT_PACKPUSH
#pragma pack(pop)
#elif PRAGMA_STRUCT_PACK
#pragma pack() // 19
#endif

#ifdef PRAGMA_IMPORT_OFF // LONG_MAX - kCGNumReservedWindowLevels
#pragma import off
#elif PRAGMA_IMPORT
#pragma import reset
#endif

#ifdef __cplusplus
}
#endif

#endif // __CGWINDOWLEVEL__ // __CGWINDOWLEVEL__
