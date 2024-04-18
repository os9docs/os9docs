/**
     \file       CFBag.h

    \brief   CoreFoundation bag collection

    \introduced_in  Mac OS X
    \avaliable_from Universal Interfaces 3.4.1

    \copyright � 1999-2001 by Apple Computer, Inc., all rights reserved

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __CFBAG__
#define __CFBAG__

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
                       CFBagRetainCallBack)(CFAllocatorRef allocator,
                                            const void *value);
typedef CALLBACK_API_C(void, CFBagReleaseCallBack)(CFAllocatorRef allocator,
                                                   const void *value);
typedef CALLBACK_API_C(CFStringRef,
                       CFBagCopyDescriptionCallBack)(const void *value);
typedef CALLBACK_API_C(Boolean, CFBagEqualCallBack)(const void *value1,
                                                    const void *value2);
typedef CALLBACK_API_C(CFHashCode, CFBagHashCallBack)(const void *value);
struct CFBagCallBacks {
  CFIndex version;
  CFBagRetainCallBack retain;
  CFBagReleaseCallBack release;
  CFBagCopyDescriptionCallBack copyDescription;
  CFBagEqualCallBack equal;
  CFBagHashCallBack hash;
};
typedef struct CFBagCallBacks CFBagCallBacks;
/**
 *  kCFTypeBagCallBacks
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
extern const CFBagCallBacks kCFTypeBagCallBacks;
/**
 *  kCFCopyStringBagCallBacks
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
extern const CFBagCallBacks kCFCopyStringBagCallBacks;
typedef CALLBACK_API_C(void, CFBagApplierFunction)(const void *value,
                                                   void *context);
typedef const struct __CFBag *CFBagRef;
typedef struct __CFBag *CFMutableBagRef;
/**
 *  CFBagGetTypeID()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(CFTypeID)
CFBagGetTypeID(void);

/**
 *  CFBagCreate()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(CFBagRef)
CFBagCreate(CFAllocatorRef allocator, const void **values, CFIndex numValues,
            const CFBagCallBacks *callBacks);

/**
 *  CFBagCreateCopy()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(CFBagRef)
CFBagCreateCopy(CFAllocatorRef allocator, CFBagRef theBag);

/**
 *  CFBagCreateMutable()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(CFMutableBagRef)
CFBagCreateMutable(CFAllocatorRef allocator, CFIndex capacity,
                   const CFBagCallBacks *callBacks);

/**
 *  CFBagCreateMutableCopy()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(CFMutableBagRef)
CFBagCreateMutableCopy(CFAllocatorRef allocator, CFIndex capacity,
                       CFBagRef theBag);

/**
 *  CFBagGetCount()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(CFIndex)
CFBagGetCount(CFBagRef theBag);

/**
 *  CFBagGetCountOfValue()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(CFIndex)
CFBagGetCountOfValue(CFBagRef theBag, const void *value);

/**
 *  CFBagContainsValue()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(Boolean)
CFBagContainsValue(CFBagRef theBag, const void *value);

/**
 *  CFBagGetValue()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(const void *)
CFBagGetValue(CFBagRef theBag, const void *value);

/**
 *  CFBagGetValueIfPresent()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(Boolean)
CFBagGetValueIfPresent(CFBagRef theBag, const void *candidate,
                       const void **value);

/**
 *  CFBagGetValues()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(void)
CFBagGetValues(CFBagRef theBag, const void **values);

/**
 *  CFBagApplyFunction()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(void)
CFBagApplyFunction(CFBagRef theBag, CFBagApplierFunction applier,
                   void *context);

/**
 *  CFBagAddValue()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(void)
CFBagAddValue(CFMutableBagRef theBag, const void *value);

/**
 *  CFBagReplaceValue()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(void)
CFBagReplaceValue(CFMutableBagRef theBag, const void *value);

/**
 *  CFBagSetValue()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(void)
CFBagSetValue(CFMutableBagRef theBag, const void *value);

/**
 *  CFBagRemoveValue()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(void)
CFBagRemoveValue(CFMutableBagRef theBag, const void *value);

/**
 *  CFBagRemoveAllValues()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(void)
CFBagRemoveAllValues(CFMutableBagRef theBag);

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

#endif /** __CFBAG__ */
