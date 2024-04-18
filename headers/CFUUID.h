/**
     \file       CFUUID.h

    \brief   CoreFoundation UUIDs

    \introduced_in  Mac OS X
    \avaliable_from Universal Interfaces 3.4.1

    \copyright � 1999-2001 by Apple Computer, Inc., all rights reserved

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __CFUUID__
#define __CFUUID__

#ifndef __CFBASE__
#include <CFBase.h>
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

typedef const struct __CFUUID *CFUUIDRef;
struct CFUUIDBytes {
  UInt8 byte0;
  UInt8 byte1;
  UInt8 byte2;
  UInt8 byte3;
  UInt8 byte4;
  UInt8 byte5;
  UInt8 byte6;
  UInt8 byte7;
  UInt8 byte8;
  UInt8 byte9;
  UInt8 byte10;
  UInt8 byte11;
  UInt8 byte12;
  UInt8 byte13;
  UInt8 byte14;
  UInt8 byte15;
};
typedef struct CFUUIDBytes CFUUIDBytes;
/** The CFUUIDBytes struct is a 128-bit struct that contains the
raw UUID.  A CFUUIDRef can provide such a struct from the
CFUUIDGetUUIDBytes() function.  This struct is suitable for
passing to APIs that expect a raw UUID.
*/
/**
 *  CFUUIDGetTypeID()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(CFTypeID)
CFUUIDGetTypeID(void);

/**
 *  CFUUIDCreate()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(CFUUIDRef)
CFUUIDCreate(CFAllocatorRef alloc);

/** Create and return a brand new unique identifier */
/**
 *  CFUUIDCreateWithBytes()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(CFUUIDRef)
CFUUIDCreateWithBytes(CFAllocatorRef alloc, UInt8 byte0, UInt8 byte1,
                      UInt8 byte2, UInt8 byte3, UInt8 byte4, UInt8 byte5,
                      UInt8 byte6, UInt8 byte7, UInt8 byte8, UInt8 byte9,
                      UInt8 byte10, UInt8 byte11, UInt8 byte12, UInt8 byte13,
                      UInt8 byte14, UInt8 byte15);

/** Create and return an identifier with the given contents.  This may return an
 * existing instance with its ref count bumped because of uniquing. */
/**
 *  CFUUIDCreateFromString()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(CFUUIDRef)
CFUUIDCreateFromString(CFAllocatorRef alloc, CFStringRef uuidStr);

/** Converts from a string representation to the UUID.  This may return an
 * existing instance with its ref count bumped because of uniquing. */
/**
 *  CFUUIDCreateString()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(CFStringRef)
CFUUIDCreateString(CFAllocatorRef alloc, CFUUIDRef uuid);

/** Converts from a UUID to its string representation. */
/**
 *  CFUUIDGetConstantUUIDWithBytes()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(CFUUIDRef)
CFUUIDGetConstantUUIDWithBytes(CFAllocatorRef alloc, UInt8 byte0, UInt8 byte1,
                               UInt8 byte2, UInt8 byte3, UInt8 byte4,
                               UInt8 byte5, UInt8 byte6, UInt8 byte7,
                               UInt8 byte8, UInt8 byte9, UInt8 byte10,
                               UInt8 byte11, UInt8 byte12, UInt8 byte13,
                               UInt8 byte14, UInt8 byte15);

/** This returns an immortal CFUUIDRef that should not be released.  It can be
 * used in headers to declare UUID constants with #define. */
/**
 *  CFUUIDGetUUIDBytes()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(CFUUIDBytes)
CFUUIDGetUUIDBytes(CFUUIDRef uuid);

/**
 *  CFUUIDCreateFromUUIDBytes()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(CFUUIDRef)
CFUUIDCreateFromUUIDBytes(CFAllocatorRef alloc, CFUUIDBytes bytes);

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

#endif /** __CFUUID__ */
