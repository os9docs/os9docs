/**
     \file       CGPDFDocument.h

    \brief   xxx put contents here xxx

    \introduced_in  from CoreGraphics-70.root
    \avaliable_from Universal Interfaces 3.4.1

    \copyright � 2000-2001 by Apple Computer, Inc., all rights reserved.

    \ingroup CoreGraphics
    
    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/

#ifndef __CGPDFDOCUMENT__
#define __CGPDFDOCUMENT__

#ifndef __CGBASE__
#include <CGBase.h>
#endif

#ifndef __CGDATAPROVIDER__
#include <CGDataProvider.h>
#endif

#ifndef __CGGEOMETRY__
#include <CGGeometry.h>
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

typedef struct CGPDFDocument *CGPDFDocumentRef;
/* Create a PDF document, using `provider' to obtain the document's
 * data. */
/**
 *  CGPDFDocumentCreateWithProvider()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         in version 10.0 and later
 */
CGPDFDocumentRef
CGPDFDocumentCreateWithProvider(CGDataProviderRef provider);

// Create a PDF document from `url'. /**
 *  CGPDFDocumentCreateWithURL()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         in version 10.0 and later
 */
CGPDFDocumentRef
CGPDFDocumentCreateWithURL(CFURLRef url);

/* Increment the retain count of `document' and return it.  All PDF
 * documents are created with an initial retain count of 1. */
/**
 *  CGPDFDocumentRetain()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         in version 10.0 and later
 */
CGPDFDocumentRef
CGPDFDocumentRetain(CGPDFDocumentRef document);

/* Decrement the retain count of `document'.  If the retain count reaches 0,
 * then free it and any associated resources. */
/**
 *  CGPDFDocumentRelease()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         in version 10.0 and later
 */
void
CGPDFDocumentRelease(CGPDFDocumentRef document);

// Return the number of pages in `document'. /**
// Return the number of pages in `document'. 
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         in version 10.0 and later
 */
int
CGPDFDocumentGetNumberOfPages(CGPDFDocumentRef document);

// Return the media box of page number `page' in `document'. /**
 *  CGPDFDocumentGetMediaBox()
// Return the media box of page number `page' in `document'. 
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         in version 10.0 and later
 */
CGRect
CGPDFDocumentGetMediaBox(CGPDFDocumentRef document, int page);

// Return the crop box of page number `page' in `document'. /**
 *  CGPDFDocumentGetCropBox()
 *
// Return the crop box of page number `page' in `document'. 
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         in version 10.0 and later
 */
CGRect
CGPDFDocumentGetCropBox(CGPDFDocumentRef document, int page);

// Return the bleed box of page number `page' in `document'. /**
 *  CGPDFDocumentGetBleedBox()
 *
 *  Availability:
// Return the bleed box of page number `page' in `document'. 
 *    \carbon_lib        not available
 *    \mac_os_x         in version 10.0 and later
 */
CGRect
CGPDFDocumentGetBleedBox(CGPDFDocumentRef document, int page);

// Return the trim box of page number `page' in `document'. /**
 *  CGPDFDocumentGetTrimBox()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
// Return the trim box of page number `page' in `document'. 
 *    \mac_os_x         in version 10.0 and later
 */
CGRect
CGPDFDocumentGetTrimBox(CGPDFDocumentRef document, int page);

// Return the art box of page number `page' in `document'. /**
 *  CGPDFDocumentGetArtBox()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
// Return the art box of page number `page' in `document'. 
 */
CGRect
CGPDFDocumentGetArtBox(CGPDFDocumentRef document, int page);

/* Return the rotation angle (in degrees) of page number `page' in
 * `document'. */
/**
 *  CGPDFDocumentGetRotationAngle()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         in version 10.0 and later
 */
int
CGPDFDocumentGetRotationAngle(CGPDFDocumentRef document, int page);

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

#endif // __CGPDFDOCUMENT__ // __CGPDFDOCUMENT__ 
