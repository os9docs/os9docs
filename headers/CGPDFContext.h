/**
     \file       CGPDFContext.h

    \brief   CoreGraphics PDF context

    \introduced_in  CoreGraphics-122 (Mac OS X 10.1)
    \avaliable_from Universal Interfaces 3.4.1

    \copyright � 2000-2001 by Apple Computer, Inc., all rights reserved.

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/

#ifndef __CGPDFCONTEXT__
#define __CGPDFCONTEXT__

#ifndef __CGBASE__
#include <CGBase.h>
#endif

#ifndef __CGCONTEXT__
#include <CGContext.h>
#endif

#ifndef __CGDATACONSUMER__
#include <CGDataConsumer.h>
#endif

#ifndef __CFDICTIONARY__
#include <CFDictionary.h>
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

/** Create a PDF context, using `consumer' for output. `mediaBox' is the
 * default page media bounding box; if NULL, then a default page size is
 * used.  `auxiliaryInfo' specifies additional information used by the PDF
 * context when generating the PDF file.  The keys and values in
 * `auxiliaryInfo' must be CFStrings.  The following keys are recognized:
 *   Key       Value
 *   --------  --------
 *   Title     The document's title.
 *   Author    The name of the person who created the document.
 *   Creator   If the document was converted to PDF from another format,
 *             the name of the application that created the original
 *             document from which it was converted.
 */
/**
 *  CGPDFContextCreate()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(CGContextRef)
CGPDFContextCreate(CGDataConsumerRef consumer, const CGRect *mediaBox,
                   CFDictionaryRef auxiliaryInfo);

/** Convenience function: create a PDF context, writing to `url'. */
/**
 *  CGPDFContextCreateWithURL()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API_C(CGContextRef)
CGPDFContextCreateWithURL(CFURLRef url, const CGRect *mediaBox,
                          CFDictionaryRef auxiliaryInfo);

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

#endif /** __CGPDFCONTEXT__ */
