/**
     \file       CGImage.h

    \brief   CoreGraphics images

    \introduced_in  CoreGraphics-122 (Mac OS X 10.1)
    \avaliable_from Universal Interfaces 3.4.1

    \copyright © 2000-2001 by Apple Computer, Inc., all rights reserved.

    \ingroup CoreGraphics
    
    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/

#ifndef __CGIMAGE__
#define __CGIMAGE__

#ifndef __CGBASE__
#include <CGBase.h>
#endif

#ifndef __CGCOLORSPACE__
#include <CGColorSpace.h>
#endif

#ifndef __CGDATAPROVIDER__
#include <CGDataProvider.h>
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
#define __CGIMAGE__RESTORE_TWOBYTEINTS
#pragma fourbyteints on
#endif
#pragma enumsalwaysint on
#elif PRAGMA_ENUM_OPTIONS
#pragma option enum =int
#elif PRAGMA_ENUM_PACK
#if __option(pack_enums)
#define __CGIMAGE__RESTORE_PACKED_ENUMS
#pragma options(!pack_enums)
#endif
#endif

typedef struct CGImage *CGImageRef;
enum CGImageAlphaInfo {
  kCGImageAlphaNone = 0,
  kCGImageAlphaPremultipliedLast = 1,  /* For example, premultiplied RGBA */
  kCGImageAlphaPremultipliedFirst = 2, /* For example, premultiplied ARGB */
  kCGImageAlphaLast = 3,               /* For example, non-premultiplied RGBA */
  kCGImageAlphaFirst = 4,              /* For example, non-premultiplied ARGB */
  kCGImageAlphaNoneSkipLast = 5,       /* Equivalent to kCGImageAlphaNone. */
  kCGImageAlphaNoneSkipFirst = 6
};
typedef enum CGImageAlphaInfo CGImageAlphaInfo;

/* Create an image. */
/**
 *  CGImageCreate()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         in version 10.0 and later
 */
CGImageRef
CGImageCreate(size_t width, size_t height, size_t bitsPerComponent,
              size_t bitsPerPixel, size_t bytesPerRow,
              CGColorSpaceRef colorspace, CGImageAlphaInfo alphaInfo,
              CGDataProviderRef provider, const float decode[],
              int shouldInterpolate, CGColorRenderingIntent intent);

/* Create an image mask. */
/**
 *  CGImageMaskCreate()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         in version 10.0 and later
 */
CGImageRef
CGImageMaskCreate(size_t width, size_t height, size_t bitsPerComponent,
                  size_t bitsPerPixel, size_t bytesPerRow,
                  CGDataProviderRef provider, const float decode[],
                  int shouldInterpolate);

/* Create an image from `source', a data provider of JPEG-encoded data. */
/**
 *  CGImageCreateWithJPEGDataProvider()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         in version 10.1 and later
 */
CGImageRef
CGImageCreateWithJPEGDataProvider(CGDataProviderRef source,
                                  const float decode[], int shouldInterpolate,
                                  CGColorRenderingIntent intent);

/* Increment the retain count of `image' and return it.  All images are
 * created with an initial retain count of 1. */
/**
 *  CGImageRetain()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         in version 10.0 and later
 */
CGImageRef
CGImageRetain(CGImageRef image);

/* Decrement the retain count of `image'.  If the retain count reaches 0,
 * then release it and any associated resources. */
/**
 *  CGImageRelease()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         in version 10.0 and later
 */
void
CGImageRelease(CGImageRef image);

/* Return 1 if `image' is an image mask, 0 otherwise. */
/**
 *  CGImageIsMask()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         in version 10.0 and later
 */
int
CGImageIsMask(CGImageRef image);

/* Return the width of `image'. */
/**
 *  CGImageGetWidth()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         in version 10.0 and later
 */
size_t
CGImageGetWidth(CGImageRef image);

/* Return the height of `image'. */
/**
 *  CGImageGetHeight()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         in version 10.0 and later
 */
size_t
CGImageGetHeight(CGImageRef image);

/* Return the number of bits/component of `image'. */
/**
 *  CGImageGetBitsPerComponent()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         in version 10.0 and later
 */
size_t
CGImageGetBitsPerComponent(CGImageRef image);

/* Return the number of bits/pixel of `image'. */
/**
 *  CGImageGetBitsPerPixel()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         in version 10.0 and later
 */
size_t
CGImageGetBitsPerPixel(CGImageRef image);

/* Return the number of bytes/row of `image'. */
/**
 *  CGImageGetBytesPerRow()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         in version 10.0 and later
 */
size_t
CGImageGetBytesPerRow(CGImageRef image);

/* Return the colorspace of `image', or NULL if `image' is an image
 * mask. */
/**
 *  CGImageGetColorSpace()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         in version 10.0 and later
 */
CGColorSpaceRef
CGImageGetColorSpace(CGImageRef image);

/* Return the alpha info of `image'. */
/**
 *  CGImageGetAlphaInfo()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         in version 10.0 and later
 */
CGImageAlphaInfo
CGImageGetAlphaInfo(CGImageRef image);

/*Return the data provider of `image'. */
/**
 *  CGImageGetDataProvider()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         in version 10.0 and later
 */
CGDataProviderRef
CGImageGetDataProvider(CGImageRef image);

/* Return the decode array of `image'. */
/**
 *  CGImageGetDecode()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         in version 10.0 and later
 */
const float *
CGImageGetDecode(CGImageRef image);

/* Return the interpolation parameter of `image'. */
/**
 *  CGImageGetShouldInterpolate()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         in version 10.0 and later
 */
int
CGImageGetShouldInterpolate(CGImageRef image);

/* Return the rendering intent of `image'. */
/**
 *  CGImageGetRenderingIntent()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         in version 10.0 and later
 */
CGColorRenderingIntent
CGImageGetRenderingIntent(CGImageRef image);

#if PRAGMA_ENUM_ALWAYSINT
#pragma enumsalwaysint reset
#ifdef __CGIMAGE__RESTORE_TWOBYTEINTS
#pragma fourbyteints off
#endif
#elif PRAGMA_ENUM_OPTIONS
#pragma option enum =reset
#elif defined(__CGIMAGE__RESTORE_PACKED_ENUMS)
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

#endif /* __CGIMAGE__ */
