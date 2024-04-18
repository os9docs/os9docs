/**
     \file       CFDate.h

    \brief   CoreFoundation date

    \introduced_in  Mac OS X
    \avaliable_from Universal Interfaces 3.4.1

    \copyright � 1999-2001 by Apple Computer, Inc., all rights reserved

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __CFDATE__
#define __CFDATE__

#ifndef __CFBASE__
#include <CFBase.h>
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

#if PRAGMA_ENUM_ALWAYSINT
#if defined(__fourbyteints__) && !__fourbyteints__
#define __CFDATE__RESTORE_TWOBYTEINTS
#pragma fourbyteints on
#endif
#pragma enumsalwaysint on
#elif PRAGMA_ENUM_OPTIONS
#pragma option enum =int
#elif PRAGMA_ENUM_PACK
#if __option(pack_enums)
#define __CFDATE__RESTORE_PACKED_ENUMS
#pragma options(!pack_enums)
#endif
#endif

typedef double CFTimeInterval;
typedef CFTimeInterval CFAbsoluteTime;
/** absolute time is the time interval since the reference date */
/** the reference date (epoch) is 00:00:00 1 January 2001. */
/**
 *  CFAbsoluteTimeGetCurrent()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(CFAbsoluteTime)
CFAbsoluteTimeGetCurrent(void);

/**
 *  kCFAbsoluteTimeIntervalSince1970
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
extern const CFTimeInterval kCFAbsoluteTimeIntervalSince1970;
/**
 *  kCFAbsoluteTimeIntervalSince1904
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
extern const CFTimeInterval kCFAbsoluteTimeIntervalSince1904;
typedef const struct __CFDate *CFDateRef;
/**
 *  CFDateGetTypeID()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(CFTypeID)
CFDateGetTypeID(void);

/**
 *  CFDateCreate()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(CFDateRef)
CFDateCreate(CFAllocatorRef allocator, CFAbsoluteTime at);

/**
 *  CFDateGetAbsoluteTime()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(CFAbsoluteTime)
CFDateGetAbsoluteTime(CFDateRef theDate);

/**
 *  CFDateGetTimeIntervalSinceDate()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(CFTimeInterval)
CFDateGetTimeIntervalSinceDate(CFDateRef theDate, CFDateRef otherDate);

/**
 *  CFDateCompare()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(CFComparisonResult)
CFDateCompare(CFDateRef theDate, CFDateRef otherDate, void *context);

typedef const struct __CFTimeZone *CFTimeZoneRef;
struct CFGregorianDate {
  SInt32 year;
  SInt8 month;
  SInt8 day;
  SInt8 hour;
  SInt8 minute;
  double second;
};
typedef struct CFGregorianDate CFGregorianDate;
struct CFGregorianUnits {
  SInt32 years;
  SInt32 months;
  SInt32 days;
  SInt32 hours;
  SInt32 minutes;
  double seconds;
};
typedef struct CFGregorianUnits CFGregorianUnits;
enum CFGregorianUnitFlags {
  kCFGregorianUnitsYears = (1 << 0),
  kCFGregorianUnitsMonths = (1 << 1),
  kCFGregorianUnitsDays = (1 << 2),
  kCFGregorianUnitsHours = (1 << 3),
  kCFGregorianUnitsMinutes = (1 << 4),
  kCFGregorianUnitsSeconds = (1 << 5),
  kCFGregorianAllUnits = 0x00FFFFFF
};
typedef enum CFGregorianUnitFlags CFGregorianUnitFlags;

/**
 *  CFGregorianDateIsValid()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(Boolean)
CFGregorianDateIsValid(CFGregorianDate gdate, CFOptionFlags unitFlags);

/**
 *  CFGregorianDateGetAbsoluteTime()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(CFAbsoluteTime)
CFGregorianDateGetAbsoluteTime(CFGregorianDate gdate, CFTimeZoneRef tz);

/**
 *  CFAbsoluteTimeGetGregorianDate()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(CFGregorianDate)
CFAbsoluteTimeGetGregorianDate(CFAbsoluteTime at, CFTimeZoneRef tz);

/**
 *  CFAbsoluteTimeAddGregorianUnits()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(CFAbsoluteTime)
CFAbsoluteTimeAddGregorianUnits(CFAbsoluteTime at, CFTimeZoneRef tz,
                                CFGregorianUnits units);

/**
 *  CFAbsoluteTimeGetDifferenceAsGregorianUnits()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(CFGregorianUnits)
CFAbsoluteTimeGetDifferenceAsGregorianUnits(CFAbsoluteTime at1,
                                            CFAbsoluteTime at2,
                                            CFTimeZoneRef tz,
                                            CFOptionFlags unitFlags);

/**
 *  CFAbsoluteTimeGetDayOfWeek()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(SInt32)
CFAbsoluteTimeGetDayOfWeek(CFAbsoluteTime at, CFTimeZoneRef tz);

/**
 *  CFAbsoluteTimeGetDayOfYear()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(SInt32)
CFAbsoluteTimeGetDayOfYear(CFAbsoluteTime at, CFTimeZoneRef tz);

/**
 *  CFAbsoluteTimeGetWeekOfYear()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(SInt32)
CFAbsoluteTimeGetWeekOfYear(CFAbsoluteTime at, CFTimeZoneRef tz);

#if PRAGMA_ENUM_ALWAYSINT
#pragma enumsalwaysint reset
#ifdef __CFDATE__RESTORE_TWOBYTEINTS
#pragma fourbyteints off
#endif
#elif PRAGMA_ENUM_OPTIONS
#pragma option enum =reset
#elif defined(__CFDATE__RESTORE_PACKED_ENUMS)
#pragma options(pack_enums)
#endif

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

#endif /** __CFDATE__ */
