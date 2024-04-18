/**
     \file       CFBase.h

    \brief   CoreFoundation base types

    \introduced_in  Mac OS X
    \avaliable_from Universal Interfaces 3.4.1

    \copyright � 1999-2001 by Apple Computer, Inc., all rights reserved

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __CFBASE__
#define __CFBASE__

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

#if PRAGMA_ENUM_ALWAYSINT
#if defined(__fourbyteints__) && !__fourbyteints__
#define __CFBASE__RESTORE_TWOBYTEINTS
#pragma fourbyteints on
#endif
#pragma enumsalwaysint on
#elif PRAGMA_ENUM_OPTIONS
#pragma option enum =int
#elif PRAGMA_ENUM_PACK
#if __option(pack_enums)
#define __CFBASE__RESTORE_PACKED_ENUMS
#pragma options(!pack_enums)
#endif
#endif

#if !defined(NULL)
#define NULL 0
#endif

#if !defined(TRUE)
#define TRUE 1
#endif

#if !defined(FALSE)
#define FALSE 0
#endif

#if defined(__WIN32__)
#undef CF_EXPORT
#if defined(CF_BUILDING_CF)
#define CF_EXPORT __declspec(dllexport) extern
#else
#define CF_EXPORT __declspec(dllimport) extern
#endif
#elif defined(macintosh)
#if defined(__MWERKS__)
#define CF_EXPORT __declspec(export) extern
#endif
#endif

#if !defined(CF_EXPORT)
#define CF_EXPORT extern
#endif

#if !defined(CF_INLINE)
#if defined(__GNUC__)
#define CF_INLINE static __inline__
#elif defined(__MWERKS__) || defined(__cplusplus)
#define CF_INLINE static inline
#endif
#endif

typedef UInt32 CFTypeID;
typedef UInt32 CFOptionFlags;
typedef UInt32 CFHashCode;
typedef SInt32 CFIndex;
typedef const struct __CFString *CFStringRef;
typedef struct __CFString *CFMutableStringRef;
/** Values returned from comparison functions */
enum CFComparisonResult {
  kCFCompareLessThan = -1,
  kCFCompareEqualTo = 0,
  kCFCompareGreaterThan = 1
};
typedef enum CFComparisonResult CFComparisonResult;

/** A standard comparison function */
typedef CALLBACK_API_C(CFComparisonResult,
                       CFComparatorFunction)(const void *val1, const void *val2,
                                             void *context);
/** Constant used by some functions to indicate failed searches. */
/** This is of type CFIndex. */
enum CFNotFound { kCFNotFound = -1 };
typedef enum CFNotFound CFNotFound;

/** Range type */
struct CFRange {
  CFIndex location;
  CFIndex length;
};
typedef struct CFRange CFRange;

#if defined(CF_INLINE)
CF_INLINE CFRange CFRangeMake(CFIndex loc, CFIndex len) {
  CFRange range;
  range.location = loc;
  range.length = len;
  return range;
}
#else
#define CFRangeMake(LOC, LEN) __CFRangeMake(LOC, LEN)
#endif

/** Private; do not use */
/**
 *  __CFRangeMake()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(CFRange)
__CFRangeMake(CFIndex loc, CFIndex len);

/** Allocator API

   Most of the time when specifying an allocator to Create functions, the NULL
   argument indicates "use the default"; this is the same as using
   kCFAllocatorDefault or the return value from CFAllocatorGetDefault().  This
   assures that you will use the allocator in effect at that time.

   You should rarely use kCFAllocatorSystemDefault, the default default
   allocator.
*/
typedef const struct __CFAllocator *CFAllocatorRef;
/** This is a synonym for NULL, if you'd rather use a named constant. */
/**
 *  kCFAllocatorDefault
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
extern const CFAllocatorRef kCFAllocatorDefault;
/** Default system allocator; you rarely need to use this. */
/**
 *  kCFAllocatorSystemDefault
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
extern const CFAllocatorRef kCFAllocatorSystemDefault;
/** This allocator uses malloc(), realloc(), and free(). This should not be
   generally used; stick to kCFAllocatorDefault whenever possible. This
   allocator is useful as the "bytesDeallocator" in CFData or
   "contentsDeallocator" in CFString where the memory was obtained as a
   result of malloc() type functions.
*/
/**
 *  kCFAllocatorMalloc
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
extern const CFAllocatorRef kCFAllocatorMalloc;
/** Null allocator which does nothing and allocates no memory. This allocator
   is useful as the "bytesDeallocator" in CFData or "contentsDeallocator"
   in CFString where the memory should not be freed.
*/
/**
 *  kCFAllocatorNull
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
extern const CFAllocatorRef kCFAllocatorNull;
/** Special allocator argument to CFAllocatorCreate() which means
   "use the functions given in the context to allocate the allocator
   itself as well".
*/
/**
 *  kCFAllocatorUseContext
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
extern const CFAllocatorRef kCFAllocatorUseContext;
typedef CALLBACK_API_C(const void *,
                       CFAllocatorRetainCallBack)(const void *info);
typedef CALLBACK_API_C(void, CFAllocatorReleaseCallBack)(const void *info);
typedef CALLBACK_API_C(CFStringRef,
                       CFAllocatorCopyDescriptionCallBack)(const void *info);
typedef CALLBACK_API_C(void *, CFAllocatorAllocateCallBack)(CFIndex allocSize,
                                                            CFOptionFlags hint,
                                                            void *info);
typedef CALLBACK_API_C(void *, CFAllocatorReallocateCallBack)(
    void *ptr, CFIndex newsize, CFOptionFlags hint, void *info);
typedef CALLBACK_API_C(void, CFAllocatorDeallocateCallBack)(void *ptr,
                                                            void *info);
typedef CALLBACK_API_C(CFIndex,
                       CFAllocatorPreferredSizeCallBack)(CFIndex size,
                                                         CFOptionFlags hint,
                                                         void *info);
struct CFAllocatorContext {
  CFIndex version;
  void *info;
  CFAllocatorRetainCallBack retain;
  CFAllocatorReleaseCallBack release;
  CFAllocatorCopyDescriptionCallBack copyDescription;
  CFAllocatorAllocateCallBack allocate;
  CFAllocatorReallocateCallBack reallocate;
  CFAllocatorDeallocateCallBack deallocate;
  CFAllocatorPreferredSizeCallBack preferredSize;
};
typedef struct CFAllocatorContext CFAllocatorContext;
/**
 *  CFAllocatorGetTypeID()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(CFTypeID)
CFAllocatorGetTypeID(void);

/**
    CFAllocatorSetDefault() sets the allocator that is used in the current
    thread whenever NULL is specified as an allocator argument. This means
    that most, if not all allocations will go through this allocator. It
    also means that any allocator set as the default needs to be ready to
    deal with arbitrary memory allocation requests; in addition, the size
    and number of requests will change between releases.

    An allocator set as the default will never be released, even if later
    another allocator replaces it as the default. Not only is it impractical
    for it to be released (as there might be caches created under the covers
    that refer to the allocator), in general it's also safer and more
    efficient to keep it around.

    If you wish to use a custom allocator in a context, it's best to provide
    it as the argument to the various creation functions rather than setting
    it as the default. Setting the default allocator is not encouraged.

    If you do set an allocator as the default, either do it for all time in
    your app, or do it in a nested fashion (by restoring the previous allocator
    when you exit your context). The latter might be appropriate for plug-ins
    or libraries that wish to set the default allocator.
*/
/**
 *  CFAllocatorSetDefault()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(void)
CFAllocatorSetDefault(CFAllocatorRef allocator);

/**
 *  CFAllocatorGetDefault()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(CFAllocatorRef)
CFAllocatorGetDefault(void);

/**
 *  CFAllocatorCreate()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(CFAllocatorRef)
CFAllocatorCreate(CFAllocatorRef allocator, CFAllocatorContext *context);

/**
 *  CFAllocatorAllocate()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(void *)
CFAllocatorAllocate(CFAllocatorRef allocator, CFIndex size, CFOptionFlags hint);

/**
 *  CFAllocatorReallocate()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(void *)
CFAllocatorReallocate(CFAllocatorRef allocator, void *ptr, CFIndex newsize,
                      CFOptionFlags hint);

/**
 *  CFAllocatorDeallocate()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(void)
CFAllocatorDeallocate(CFAllocatorRef allocator, void *ptr);

/**
 *  CFAllocatorGetPreferredSizeForSize()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(CFIndex)
CFAllocatorGetPreferredSizeForSize(CFAllocatorRef allocator, CFIndex size,
                                   CFOptionFlags hint);

/**
 *  CFAllocatorGetContext()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(void)
CFAllocatorGetContext(CFAllocatorRef allocator, CFAllocatorContext *context);

/** Base "type" of all "CF objects", and polymorphic functions on them */

typedef const void *CFTypeRef;
/**
 *  CFGetTypeID()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(CFTypeID)
CFGetTypeID(CFTypeRef cf);

/**
 *  CFCopyTypeIDDescription()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(CFStringRef)
CFCopyTypeIDDescription(CFTypeID type_id);

/**
 *  CFRetain()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(CFTypeRef)
CFRetain(CFTypeRef cf);

/**
 *  CFRelease()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(void)
CFRelease(CFTypeRef cf);

/**
 *  CFGetRetainCount()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(CFIndex)
CFGetRetainCount(CFTypeRef cf);

/**
 *  CFEqual()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(Boolean)
CFEqual(CFTypeRef cf1, CFTypeRef cf2);

/**
 *  CFHash()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(CFHashCode)
CFHash(CFTypeRef cf);

/**
 *  CFCopyDescription()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(CFStringRef)
CFCopyDescription(CFTypeRef cf);

/**
 *  CFGetAllocator()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(CFAllocatorRef)
CFGetAllocator(CFTypeRef cf);

#if PRAGMA_ENUM_ALWAYSINT
#pragma enumsalwaysint reset
#ifdef __CFBASE__RESTORE_TWOBYTEINTS
#pragma fourbyteints off
#endif
#elif PRAGMA_ENUM_OPTIONS
#pragma option enum =reset
#elif defined(__CFBASE__RESTORE_PACKED_ENUMS)
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

#endif /** __CFBASE__ */
