/**
     \file       CFTimeZone.h

    \brief   CoreFoundation time zone

    \introduced_in  Mac OS X
    \avaliable_from Universal Interfaces 3.4.1

    \copyright � 1999-2001 by Apple Computer, Inc., all rights reserved

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __CFTIMEZONE__
#define __CFTIMEZONE__

#ifndef __CFBASE__
#include <CFBase.h>
#endif

#ifndef __CFARRAY__
#include <CFArray.h>
#endif

#ifndef __CFDATA__
#include <CFData.h>
#endif

#ifndef __CFDATE__
#include <CFDate.h>
#endif

#ifndef __CFDICTIONARY__
#include <CFDictionary.h>
#endif

#ifndef __CFSTRING__
#include <CFString.h>
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

/**
        ### Warning ###

    The CFTimeZone functions are not usable on when running on CarbonLib under
    Mac OS 8/9.  CFTimeZoneCreate will return NULL and most functions are
   no-ops.

    The CFTimeZone functions do work properly when running on Mac OS X.

*/
/**
 *  CFTimeZoneGetTypeID()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available in CarbonLib 1.x, is available on Mac OS
 X version 10.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(CFTypeID)
CFTimeZoneGetTypeID(void);

/**
 *  CFTimeZoneCopySystem()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available in CarbonLib 1.x, is available on Mac OS
 X version 10.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(CFTimeZoneRef)
CFTimeZoneCopySystem(void);

/**
 *  CFTimeZoneResetSystem()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available in CarbonLib 1.x, is available on Mac OS
 X version 10.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(void)
CFTimeZoneResetSystem(void);

/**
 *  CFTimeZoneCopyDefault()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available in CarbonLib 1.x, is available on Mac OS
 X version 10.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(CFTimeZoneRef)
CFTimeZoneCopyDefault(void);

/**
 *  CFTimeZoneSetDefault()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available in CarbonLib 1.x, is available on Mac OS
 X version 10.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(void)
CFTimeZoneSetDefault(CFTimeZoneRef tz);

/**
 *  CFTimeZoneCopyKnownNames()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available in CarbonLib 1.x, is available on Mac OS
 X version 10.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(CFArrayRef)
CFTimeZoneCopyKnownNames(void);

/**
 *  CFTimeZoneCopyAbbreviationDictionary()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available in CarbonLib 1.x, is available on Mac OS
 X version 10.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(CFDictionaryRef)
CFTimeZoneCopyAbbreviationDictionary(void);

/**
 *  CFTimeZoneSetAbbreviationDictionary()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available in CarbonLib 1.x, is available on Mac OS
 X version 10.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(void)
CFTimeZoneSetAbbreviationDictionary(CFDictionaryRef dict);

/**
 *  CFTimeZoneCreate()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available in CarbonLib 1.x, is available on Mac OS
 X version 10.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(CFTimeZoneRef)
CFTimeZoneCreate(CFAllocatorRef allocator, CFStringRef name, CFDataRef data);

/**
 *  CFTimeZoneCreateWithTimeIntervalFromGMT()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available in CarbonLib 1.x, is available on Mac OS
 X version 10.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(CFTimeZoneRef)
CFTimeZoneCreateWithTimeIntervalFromGMT(CFAllocatorRef allocator,
                                        CFTimeInterval ti);

/**
 *  CFTimeZoneCreateWithName()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available in CarbonLib 1.x, is available on Mac OS
 X version 10.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(CFTimeZoneRef)
CFTimeZoneCreateWithName(CFAllocatorRef allocator, CFStringRef name,
                         Boolean tryAbbrev);

/**
 *  CFTimeZoneGetName()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available in CarbonLib 1.x, is available on Mac OS
 X version 10.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(CFStringRef)
CFTimeZoneGetName(CFTimeZoneRef tz);

/**
 *  CFTimeZoneGetData()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available in CarbonLib 1.x, is available on Mac OS
 X version 10.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(CFDataRef)
CFTimeZoneGetData(CFTimeZoneRef tz);

/**
 *  CFTimeZoneGetSecondsFromGMT()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available in CarbonLib 1.x, is available on Mac OS
 X version 10.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(CFTimeInterval)
CFTimeZoneGetSecondsFromGMT(CFTimeZoneRef tz, CFAbsoluteTime at);

/**
 *  CFTimeZoneCopyAbbreviation()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available in CarbonLib 1.x, is available on Mac OS
 X version 10.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(CFStringRef)
CFTimeZoneCopyAbbreviation(CFTimeZoneRef tz, CFAbsoluteTime at);

/**
 *  CFTimeZoneIsDaylightSavingTime()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available in CarbonLib 1.x, is available on Mac OS
 X version 10.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(Boolean)
CFTimeZoneIsDaylightSavingTime(CFTimeZoneRef tz, CFAbsoluteTime at);

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

#endif /** __CFTIMEZONE__ */
