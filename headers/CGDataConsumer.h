/**
     \file       CGDataConsumer.h

    \brief   xxx put contents here xxx

    \introduced_in  from CoreGraphics-70.root
    \avaliable_from Universal Interfaces 3.4.1

    \copyright � 2000-2001 by Apple Computer, Inc., all rights reserved.

    \ingroup CoreGraphics
    
    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __CGDATACONSUMER__
#define __CGDATACONSUMER__

#ifndef __CGBASE__
#include <CGBase.h>
#endif

#ifndef __CFURL__
#include <CFURL.h>
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

typedef struct CGDataConsumer *CGDataConsumerRef;
typedef CALLBACK_API_C(size_t, CGPutBytesProcPtr)(void *info,
                                                  const void *buffer,
                                                  size_t count);
typedef CALLBACK_API_C(void, CGReleaseConsumerProcPtr)(void *info);
/* Callbacks for accessing data.
 * `putBytes' copies `count' bytes from `buffer' to the consumer, and
 * returns the number of bytes copied.  It should return 0 if no more data
 * can be written to the consumer.
 * `releaseConsumer', if non-NULL, is called when the consumer is freed. */
struct CGDataConsumerCallbacks {
  CGPutBytesProcPtr putBytes;
  CGReleaseConsumerProcPtr releaseConsumer;
};
typedef struct CGDataConsumerCallbacks CGDataConsumerCallbacks;
/* Create a data consumer using `callbacks' to handle the data.  `info' is
 * passed to each of the callback functions. */
/**
 *  CGDataConsumerCreate()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(CGDataConsumerRef)
CGDataConsumerCreate(void *info, const CGDataConsumerCallbacks *callbacks);

/* Create a data consumer which writes data to `url'. */
/**
 *  CGDataConsumerCreateWithURL()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(CGDataConsumerRef)
CGDataConsumerCreateWithURL(CFURLRef url);

/* Increment the retain count of `consumer' and return it.  All data
 * consumers are created with an initial retain count of 1. */
/**
 *  CGDataConsumerRetain()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(CGDataConsumerRef)
CGDataConsumerRetain(CGDataConsumerRef consumer);

/* Decrement the retain count of `consumer'.  If the retain count reaches
 * 0, then release it and any associated resources. */
/**
 *  CGDataConsumerRelease()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(void)
CGDataConsumerRelease(CGDataConsumerRef consumer);

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

#endif /* __CGDATACONSUMER__ */
