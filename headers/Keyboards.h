/**
     \file       Keyboards.h

    \brief   Keyboard API.

    \introduced_in  Keyboard 1.0
    \avaliable_from Universal Interfaces 3.4.1

    \copyright © 1997-2001 by Apple Computer, Inc., all rights reserved

    \ingroup Input

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __KEYBOARDS__
#define __KEYBOARDS__

#ifndef __MACTYPES__
#include <MacTypes.h>
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

  // ©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©
  // Keyboard API constants   // ©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©
  // Keyboard API Trap Number. Should be moved to Traps.i   enum
  // Keyboard API Trap Number. Should be moved to Traps.i
  _KeyboardDispatch = 0xAA7A
};

// Gestalt selector and values for the Keyboard API   enum
{
    // Gestalt selector and values for the Keyboard API
    gestaltKBPS2Keyboards = 1,
    gestaltKBPS2SetIDToAny = 2,
    gestaltKBPS2SetTranslationTable = 4};

// Keyboard API Error Codes
/**
I stole the range blow from the empty space in the Allocation project but
   should be updated to the officially registered range.
   // Keyboard API Error Codes
   enum {
     errKBPS2KeyboardNotAvailable = -30850,
     errKBIlligalParameters = -30851,
     errKBFailSettingID = -30852,
     errKBFailSettingTranslationTable = -30853,
     errKBFailWritePreference = -30854
   };

// Keyboard HW Layout Types   enum
{
   kKeyboardJIS = FOUR_CHAR_CODE('JIS '),
   kKeyboardANSI = FOUR_CHAR_CODE('ANSI'),
   // Keyboard HW Layout Types
   kKeyboardUnknown = kUnknownType // '????'
};

// ©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©
// Keyboard API types   // ©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©

/*©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©// '????'
// Keyboard API routines   // ©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©

#if CALL_NOT_IN_CARBON
// Keyboard API types
*  KBInitialize()
*

// Keyboard API routines
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
OSErr KBInitialize(void);

/**
 *  KBSetupPS2Keyboard()
 *

 *    \non_carbon_cfm   in KeyboardsLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSErr KBSetupPS2Keyboard(SInt16 keyboardType, SInt8 *alternativeTable);

/**
 *  KBGetPS2KeyboardID()
 *

 *    \non_carbon_cfm   in KeyboardsLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSErr KBGetPS2KeyboardID(SInt16 *keyboardType);

/**
 *  KBIsPS2KeyboardConnected()
 *

 *    \non_carbon_cfm   in KeyboardsLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
Boolean
KBIsPS2KeyboardConnected(void);

/**
 *  KBIsPS2KeyboardEnabled()
 *

 *    \non_carbon_cfm   in KeyboardsLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
Boolean
KBIsPS2KeyboardEnabled(void);

/**
 *  KBGetPS2KeyboardAttributes()
 *

 *    \non_carbon_cfm   in KeyboardsLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
SInt32
KBGetPS2KeyboardAttributes(void);

/**
 *  KBSetKCAPForPS2Keyboard()
 *

 *    \non_carbon_cfm   in KeyboardsLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSErr KBSetKCAPForPS2Keyboard(Handle kcapHandle);

/**
 *  KBSetupPS2KeyboardFromLayoutType()
 *

 *    \non_carbon_cfm   in KeyboardsLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSErr KBSetupPS2KeyboardFromLayoutType(OSType layoutType);

/**
 *  KBGetPS2KeyboardLayoutType()
 *

 *    \non_carbon_cfm   in KeyboardsLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSErr KBGetPS2KeyboardLayoutType(OSType *layoutType);

#endif // CALL_NOT_IN_CARBON
/**
 *  KBGetLayoutType()
 *

 *    \non_carbon_cfm   in KeyboardsLib 1.0 and later
 *    \carbon_lib        not available in CarbonLib 1.x, is available on Mac OS
 X version 10.0 and later
 *   // CALL_NOT_IN_CARBON
 */
OSType
KBGetLayoutType(SInt16 keyboardType);

#if PRAGMA_STRUCT_ALIGN
#pragma options align = reset
#elif PRAGMA_STRUCT_PACKPUSH
#pragma pack(pop)
#elif PRAGMA_STRUCT_PACK
#pragma pack()
#endif

#ifdef PRAGMA_IMPORT_OFF
#pragma import off
#elif PRAGMA_IMPORT
#pragma import reset
#endif

#ifdef __cplusplus
}
#endif

#endif // __KEYBOARDS__ // __KEYBOARDS__
