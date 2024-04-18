/**
     \file       DriverSynchronization.h

    \brief   Driver Synchronization Interfaces.

    \introduced_in  MacOS 8
    \avaliable_from Universal Interfaces 3.4.1

    \copyright � 1985-2001 by Apple Computer, Inc., all rights reserved

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __DRIVERSYNCHRONIZATION__
#define __DRIVERSYNCHRONIZATION__

#ifndef __CONDITIONALMACROS__
#include <ConditionalMacros.h>
#endif

#ifndef __MACTYPES__
#include <MacTypes.h>
#endif

#if PRAGMA_ONCE
#pragma once
#endif

#ifdef __cplusplus
extern "C" {
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

#if CALL_NOT_IN_CARBON
/**
 *  SynchronizeIO()
 *

 *    \non_carbon_cfm   in DriverServicesLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API_C(void)
SynchronizeIO(void) ONEWORDINLINE(0x4E71);

#endif /* CALL_NOT_IN_CARBON */

/**
 *  CompareAndSwap()
 *

 *    \non_carbon_cfm   in InterfaceLib 8.5 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(Boolean)
CompareAndSwap(UInt32 oldVvalue, UInt32 newValue, UInt32 *OldValueAdr);

/**
 *  TestAndClear()
 *

 *    \non_carbon_cfm   in InterfaceLib 8.5 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(Boolean)
TestAndClear(UInt32 bit, UInt8 *startAddress);

/**
 *  TestAndSet()
 *

 *    \non_carbon_cfm   in InterfaceLib 8.5 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(Boolean)
TestAndSet(UInt32 bit, UInt8 *startAddress);

/**
 *  IncrementAtomic8()
 *

 *    \non_carbon_cfm   in InterfaceLib 8.5 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(SInt8)
IncrementAtomic8(SInt8 *value);

/**
 *  DecrementAtomic8()
 *

 *    \non_carbon_cfm   in InterfaceLib 8.5 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(SInt8)
DecrementAtomic8(SInt8 *value);

/**
 *  AddAtomic8()
 *

 *    \non_carbon_cfm   in InterfaceLib 8.5 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(SInt8)
AddAtomic8(SInt32 amount, SInt8 *value);

/**
 *  BitAndAtomic8()
 *

 *    \non_carbon_cfm   in InterfaceLib 8.5 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(UInt8)
BitAndAtomic8(UInt32 mask, UInt8 *value);

/**
 *  BitOrAtomic8()
 *

 *    \non_carbon_cfm   in InterfaceLib 8.5 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(UInt8)
BitOrAtomic8(UInt32 mask, UInt8 *value);

/**
 *  BitXorAtomic8()
 *

 *    \non_carbon_cfm   in InterfaceLib 8.5 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(UInt8)
BitXorAtomic8(UInt32 mask, UInt8 *value);

/**
 *  IncrementAtomic16()
 *

 *    \non_carbon_cfm   in InterfaceLib 8.5 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(SInt16)
IncrementAtomic16(SInt16 *value);

/**
 *  DecrementAtomic16()
 *

 *    \non_carbon_cfm   in InterfaceLib 8.5 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(SInt16)
DecrementAtomic16(SInt16 *value);

/**
 *  AddAtomic16()
 *

 *    \non_carbon_cfm   in InterfaceLib 8.5 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(SInt16)
AddAtomic16(SInt32 amount, SInt16 *value);

/**
 *  BitAndAtomic16()
 *

 *    \non_carbon_cfm   in InterfaceLib 8.5 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(UInt16)
BitAndAtomic16(UInt32 mask, UInt16 *value);

/**
 *  BitOrAtomic16()
 *

 *    \non_carbon_cfm   in InterfaceLib 8.5 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(UInt16)
BitOrAtomic16(UInt32 mask, UInt16 *value);

/**
 *  BitXorAtomic16()
 *

 *    \non_carbon_cfm   in InterfaceLib 8.5 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(UInt16)
BitXorAtomic16(UInt32 mask, UInt16 *value);

/**
 *  IncrementAtomic()
 *

 *    \non_carbon_cfm   in InterfaceLib 8.5 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(SInt32)
IncrementAtomic(SInt32 *value);

/**
 *  DecrementAtomic()
 *

 *    \non_carbon_cfm   in InterfaceLib 8.5 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(SInt32)
DecrementAtomic(SInt32 *value);

/**
 *  AddAtomic()
 *

 *    \non_carbon_cfm   in InterfaceLib 8.5 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(SInt32)
AddAtomic(SInt32 amount, SInt32 *value);

/**
 *  BitAndAtomic()
 *

 *    \non_carbon_cfm   in InterfaceLib 8.5 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(UInt32)
BitAndAtomic(UInt32 mask, UInt32 *value);

/**
 *  BitOrAtomic()
 *

 *    \non_carbon_cfm   in InterfaceLib 8.5 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(UInt32)
BitOrAtomic(UInt32 mask, UInt32 *value);

/**
 *  BitXorAtomic()
 *

 *    \non_carbon_cfm   in InterfaceLib 8.5 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(UInt32)
BitXorAtomic(UInt32 mask, UInt32 *value);

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

#endif /* __DRIVERSYNCHRONIZATION__ */
