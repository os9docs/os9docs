/**
     \file       CFSet.h

    \brief   CoreFoundation set collection

    \introduced_in  Mac OS X
    \avaliable_from Universal Interfaces 3.4.1

    \copyright � 1999-2001 by Apple Computer, Inc., all rights reserved

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __CFSET__
#define __CFSET__

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

typedef CALLBACK_API_C(const void *,
                       CFSetRetainCallBack)(CFAllocatorRef allocator,
                                            const void *value);
typedef CALLBACK_API_C(void, CFSetReleaseCallBack)(CFAllocatorRef allocator,
                                                   const void *value);
typedef CALLBACK_API_C(CFStringRef,
                       CFSetCopyDescriptionCallBack)(const void *value);
typedef CALLBACK_API_C(Boolean, CFSetEqualCallBack)(const void *value1,
                                                    const void *value2);
typedef CALLBACK_API_C(CFHashCode, CFSetHashCallBack)(const void *value);
struct CFSetCallBacks {
  CFIndex version;
  CFSetRetainCallBack retain;
  CFSetReleaseCallBack release;
  CFSetCopyDescriptionCallBack copyDescription;
  CFSetEqualCallBack equal;
  CFSetHashCallBack hash;
};
typedef struct CFSetCallBacks CFSetCallBacks;
/**
 *  kCFTypeSetCallBacks
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
extern const CFSetCallBacks kCFTypeSetCallBacks;
/**
 *  kCFCopyStringSetCallBacks
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
extern const CFSetCallBacks kCFCopyStringSetCallBacks;
typedef CALLBACK_API_C(void, CFSetApplierFunction)(const void *value,
                                                   void *context);
typedef const struct __CFSet *CFSetRef;
typedef struct __CFSet *CFMutableSetRef;
/**
 *  CFSetGetTypeID()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(CFTypeID)
CFSetGetTypeID(void);

/**
 *  CFSetCreate()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(CFSetRef)
CFSetCreate(CFAllocatorRef allocator, const void **values, CFIndex numValues,
            const CFSetCallBacks *callBacks);

/**
 *  CFSetCreateCopy()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(CFSetRef)
CFSetCreateCopy(CFAllocatorRef allocator, CFSetRef theSet);

/**
 *  CFSetCreateMutable()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(CFMutableSetRef)
CFSetCreateMutable(CFAllocatorRef allocator, CFIndex capacity,
                   const CFSetCallBacks *callBacks);

/**
 *  CFSetCreateMutableCopy()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(CFMutableSetRef)
CFSetCreateMutableCopy(CFAllocatorRef allocator, CFIndex capacity,
                       CFSetRef theSet);

/**
 *  CFSetGetCount()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(CFIndex)
CFSetGetCount(CFSetRef theSet);

/**
 *  CFSetGetCountOfValue()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(CFIndex)
CFSetGetCountOfValue(CFSetRef theSet, const void *value);

/**
 *  CFSetContainsValue()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(Boolean)
CFSetContainsValue(CFSetRef theSet, const void *value);

/**
 *  CFSetGetValue()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(const void *)
CFSetGetValue(CFSetRef theSet, const void *value);

/**
 *  CFSetGetValueIfPresent()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(Boolean)
CFSetGetValueIfPresent(CFSetRef theSet, const void *candidate,
                       const void **value);

/**
 *  CFSetGetValues()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(void)
CFSetGetValues(CFSetRef theSet, const void **values);

/**
 *  CFSetApplyFunction()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(void)
CFSetApplyFunction(CFSetRef theSet, CFSetApplierFunction applier,
                   void *context);

/**
 *  CFSetAddValue()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(void)
CFSetAddValue(CFMutableSetRef theSet, const void *value);

/**
 *  CFSetReplaceValue()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(void)
CFSetReplaceValue(CFMutableSetRef theSet, const void *value);

/**
 *  CFSetSetValue()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(void)
CFSetSetValue(CFMutableSetRef theSet, const void *value);

/**
 *  CFSetRemoveValue()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(void)
CFSetRemoveValue(CFMutableSetRef theSet, const void *value);

/**
 *  CFSetRemoveAllValues()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(void)
CFSetRemoveAllValues(CFMutableSetRef theSet);

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

#endif /** __CFSET__ */
