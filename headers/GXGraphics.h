/**
     \file       GXGraphics.h

    \brief   QuickDraw GX graphic routine interfaces.

    \introduced_in  Quickdraw GX 1.1
    \avaliable_from Universal Interfaces 3.4.1

    \copyright © 1994-2001 by Apple Computer, Inc., all rights reserved.

    \ingroup QuickDraw

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __GXGRAPHICS__
#define __GXGRAPHICS__

#ifndef __CONDITIONALMACROS__
#include <ConditionalMacros.h>
#endif

#ifndef __MACTYPES__
#include <MacTypes.h>
#endif

#ifndef __FONTS__
#include <Fonts.h>
#endif

#ifndef __GXERRORS__
#include <GXErrors.h>
#endif

#ifndef __GXTYPES__
#include <GXTypes.h>
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

#if defined(__MWERKS__) && TARGET_CPU_68K
#pragma push
#pragma pointers_in_D0
#endif

#if CALL_NOT_IN_CARBON
/**
 *  GXNewGraphicsClient()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxGraphicsClient
GXNewGraphicsClient(void *memoryStart, long memoryLength,
                    gxClientAttribute attributes)
    THREEWORDINLINE(0x303C, 0x0059, 0xA832);

/**
 *  GXGetGraphicsClient()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxGraphicsClient
GXGetGraphicsClient(void) THREEWORDINLINE(0x303C, 0x005A, 0xA832);

/**
 *  GXSetGraphicsClient()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetGraphicsClient(gxGraphicsClient client)
    THREEWORDINLINE(0x303C, 0x005B, 0xA832);

/**
 *  GXDisposeGraphicsClient()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXDisposeGraphicsClient(gxGraphicsClient client)
    THREEWORDINLINE(0x303C, 0x005C, 0xA832);

#endif // CALL_NOT_IN_CARBON 
/*returns the count */
#if CALL_NOT_IN_CARBON
/**
 *  GXGetGraphicsClients()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
long
GXGetGraphicsClients(long index, long count, gxGraphicsClient clients[])
    THREEWORDINLINE(0x303C, 0x005E, 0xA832);

/**
 *  GXEnterGraphics()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXEnterGraphics(void) THREEWORDINLINE(0x303C, 0x005F, 0xA832);

/**
 *  GXExitGraphics()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXExitGraphics(void) THREEWORDINLINE(0x303C, 0x0060, 0xA832);

/**
 *  GXGetGraphicsError()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxGraphicsError
GXGetGraphicsError(gxGraphicsError *stickyError)
    THREEWORDINLINE(0x303C, 0x0061, 0xA832);

/**
 *  GXGetGraphicsNotice()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxGraphicsNotice
GXGetGraphicsNotice(gxGraphicsNotice *stickyNotice)
    THREEWORDINLINE(0x303C, 0x0062, 0xA832);

/**
 *  GXGetGraphicsWarning()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxGraphicsWarning
GXGetGraphicsWarning(gxGraphicsWarning *stickyWarning)
    THREEWORDINLINE(0x303C, 0x0063, 0xA832);

/**
 *  GXPostGraphicsError()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXPostGraphicsError(gxGraphicsError error)
    THREEWORDINLINE(0x303C, 0x0064, 0xA832);

/**
 *  GXPostGraphicsWarning()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXPostGraphicsWarning(gxGraphicsWarning warning)
    THREEWORDINLINE(0x303C, 0x0066, 0xA832);

/**
 *  GXGetUserGraphicsError()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxUserErrorUPP
GXGetUserGraphicsError(long *reference) THREEWORDINLINE(0x303C, 0x0067, 0xA832);

/**
 *  GXGetUserGraphicsNotice()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxUserNoticeUPP
GXGetUserGraphicsNotice(long *reference)
    THREEWORDINLINE(0x303C, 0x0068, 0xA832);

/**
 *  GXGetUserGraphicsWarning()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxUserWarningUPP
GXGetUserGraphicsWarning(long *reference)
    THREEWORDINLINE(0x303C, 0x0069, 0xA832);

/**
 *  GXSetUserGraphicsError()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetUserGraphicsError(gxUserErrorUPP userFunction, long reference)
    THREEWORDINLINE(0x303C, 0x006A, 0xA832);

/**
 *  GXSetUserGraphicsNotice()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetUserGraphicsNotice(gxUserNoticeUPP userFunction, long reference)
    THREEWORDINLINE(0x303C, 0x006B, 0xA832);

/**
 *  GXSetUserGraphicsWarning()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetUserGraphicsWarning(gxUserWarningUPP userFunction, long reference)
    THREEWORDINLINE(0x303C, 0x006C, 0xA832);

/**
 *  GXIgnoreGraphicsWarning()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXIgnoreGraphicsWarning(gxGraphicsWarning warning)
    THREEWORDINLINE(0x303C, 0x006F, 0xA832);

/**
 *  GXPopGraphicsWarning()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXPopGraphicsWarning(void) THREEWORDINLINE(0x303C, 0x0070, 0xA832);

/**
 *  GXNewShapeVector()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxShape
GXNewShapeVector(gxShapeType aType, const Fixed vector[])
    THREEWORDINLINE(0x303C, 0x0071, 0xA832);

/**
 *  GXSetShapeVector()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetShapeVector(gxShape target, const Fixed vector[])
    THREEWORDINLINE(0x303C, 0x0072, 0xA832);

/**
 *  GXNewBitmap()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxShape
GXNewBitmap(const gxBitmap *data, const gxPoint *position)
    THREEWORDINLINE(0x303C, 0x0073, 0xA832);

/**
 *  GXNewCurve()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxShape
GXNewCurve(const gxCurve *data) THREEWORDINLINE(0x303C, 0x0074, 0xA832);

/**
 *  GXNewGlyphs()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxShape
GXNewGlyphs(long charCount, const unsigned char text[],
            const gxPoint positions[], const long advance[],
            const gxPoint tangents[], const short styleRuns[],
            const gxStyle glyphStyles[])
    THREEWORDINLINE(0x303C, 0x0075, 0xA832);

/**
 *  GXNewLine()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxShape
GXNewLine(const gxLine *data) THREEWORDINLINE(0x303C, 0x0076, 0xA832);

/**
 *  GXNewPaths()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxShape
GXNewPaths(const gxPaths *data) THREEWORDINLINE(0x303C, 0x0077, 0xA832);

/**
 *  GXNewPicture()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxShape
GXNewPicture(long count, const gxShape shapes[], const gxStyle styles[],
             const gxInk inks[], const gxTransform transforms[])
    THREEWORDINLINE(0x303C, 0x0078, 0xA832);

/**
 *  GXNewPoint()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxShape
GXNewPoint(const gxPoint *data) THREEWORDINLINE(0x303C, 0x0079, 0xA832);

/**
 *  GXNewPolygons()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxShape
GXNewPolygons(const gxPolygons *data) THREEWORDINLINE(0x303C, 0x007A, 0xA832);

/**
 *  GXNewRectangle()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxShape
GXNewRectangle(const gxRectangle *data) THREEWORDINLINE(0x303C, 0x007B, 0xA832);

/**
 *  GXNewText()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxShape
GXNewText(long charCount, const unsigned char text[], const gxPoint *position)
    THREEWORDINLINE(0x303C, 0x007C, 0xA832);

/**
 *  GXGetBitmap()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxBitmap *
GXGetBitmap(gxShape source, gxBitmap *data, gxPoint *position)
    THREEWORDINLINE(0x303C, 0x007D, 0xA832);

/**
 *  GXGetCurve()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxCurve *
GXGetCurve(gxShape source, gxCurve *data)
    THREEWORDINLINE(0x303C, 0x007E, 0xA832);

// returns byte length of glyphs /**
// returns byte length of glyphs 
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
long
GXGetGlyphs(gxShape source, long *charCount, unsigned char text[],
            gxPoint positions[], long advance[], gxPoint tangents[],
            long *runCount, short styleRuns[], gxStyle glyphStyles[])
    THREEWORDINLINE(0x303C, 0x007F, 0xA832);

/**
 *  GXGetLine()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxLine *
GXGetLine(gxShape source, gxLine *data) THREEWORDINLINE(0x303C, 0x0080, 0xA832);

// returns byte length /**
 *  GXGetPaths()
// returns byte length 

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
long
GXGetPaths(gxShape source, gxPaths *data)
    THREEWORDINLINE(0x303C, 0x0081, 0xA832);

// returns count /**
 *  GXGetPicture()
 *
// returns count 
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
long
GXGetPicture(gxShape source, gxShape shapes[], gxStyle styles[], gxInk inks[],
             gxTransform transforms[]) THREEWORDINLINE(0x303C, 0x0082, 0xA832);

/**
 *  GXGetPoint()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxPoint *
GXGetPoint(gxShape source, gxPoint *data)
    THREEWORDINLINE(0x303C, 0x0083, 0xA832);

// returns byte length /**
 *  GXGetPolygons()
 *

// returns byte length 
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
long
GXGetPolygons(gxShape source, gxPolygons *data)
    THREEWORDINLINE(0x303C, 0x0084, 0xA832);

/**
 *  GXGetRectangle()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxRectangle *
GXGetRectangle(gxShape source, gxRectangle *data)
    THREEWORDINLINE(0x303C, 0x0085, 0xA832);

// returns byte length /**
 *  GXGetText()
 *

 *    \non_carbon_cfm   not available
// returns byte length 
 *    \mac_os_x         not available
 */
long
GXGetText(gxShape source, long *charCount, unsigned char text[],
          gxPoint *position) THREEWORDINLINE(0x303C, 0x0086, 0xA832);

/**
 *  GXSetBitmap()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetBitmap(gxShape target, const gxBitmap *data, const gxPoint *position)
    THREEWORDINLINE(0x303C, 0x0087, 0xA832);

/**
 *  GXSetCurve()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetCurve(gxShape target, const gxCurve *data)
    THREEWORDINLINE(0x303C, 0x0088, 0xA832);

/**
 *  GXSetGlyphs()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetGlyphs(gxShape target, long charCount, const unsigned char text[],
            const gxPoint positions[], const long advance[],
            const gxPoint tangents[], const short styleRuns[],
            const gxStyle glyphStyles[])
    THREEWORDINLINE(0x303C, 0x0089, 0xA832);

/**
 *  GXSetLine()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetLine(gxShape target, const gxLine *data)
    THREEWORDINLINE(0x303C, 0x008A, 0xA832);

/**
 *  GXSetPaths()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetPaths(gxShape target, const gxPaths *data)
    THREEWORDINLINE(0x303C, 0x008B, 0xA832);

/**
 *  GXSetPicture()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetPicture(gxShape target, long count, const gxShape shapes[],
             const gxStyle styles[], const gxInk inks[],
             const gxTransform transforms[])
    THREEWORDINLINE(0x303C, 0x008C, 0xA832);

/**
 *  GXSetPoint()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetPoint(gxShape target, const gxPoint *data)
    THREEWORDINLINE(0x303C, 0x008D, 0xA832);

/**
 *  GXSetPolygons()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetPolygons(gxShape target, const gxPolygons *data)
    THREEWORDINLINE(0x303C, 0x008E, 0xA832);

/**
 *  GXSetRectangle()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetRectangle(gxShape target, const gxRectangle *data)
    THREEWORDINLINE(0x303C, 0x008F, 0xA832);

/**
 *  GXSetText()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetText(gxShape target, long charCount, const unsigned char text[],
          const gxPoint *position) THREEWORDINLINE(0x303C, 0x0090, 0xA832);

/**
 *  GXDrawBitmap()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXDrawBitmap(const gxBitmap *data, const gxPoint *position)
    THREEWORDINLINE(0x303C, 0x0091, 0xA832);

/**
 *  GXDrawCurve()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXDrawCurve(const gxCurve *data) THREEWORDINLINE(0x303C, 0x0092, 0xA832);

/**
 *  GXDrawGlyphs()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXDrawGlyphs(long charCount, const unsigned char text[],
             const gxPoint positions[], const long advance[],
             const gxPoint tangents[], const short styleRuns[],
             const gxStyle glyphStyles[])
    THREEWORDINLINE(0x303C, 0x0093, 0xA832);

/**
 *  GXDrawLine()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXDrawLine(const gxLine *data) THREEWORDINLINE(0x303C, 0x0094, 0xA832);

/**
 *  GXDrawPaths()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXDrawPaths(const gxPaths *data, gxShapeFill fill)
    THREEWORDINLINE(0x303C, 0x0095, 0xA832);

/**
 *  GXDrawPicture()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXDrawPicture(long count, const gxShape shapes[], const gxStyle styles[],
              const gxInk inks[], const gxTransform transforms[])
    THREEWORDINLINE(0x303C, 0x0096, 0xA832);

/**
 *  GXDrawPoint()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXDrawPoint(const gxPoint *data) THREEWORDINLINE(0x303C, 0x0097, 0xA832);

/**
 *  GXDrawPolygons()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXDrawPolygons(const gxPolygons *data, gxShapeFill fill)
    THREEWORDINLINE(0x303C, 0x0098, 0xA832);

/**
 *  GXDrawRectangle()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXDrawRectangle(const gxRectangle *data, gxShapeFill fill)
    THREEWORDINLINE(0x303C, 0x0099, 0xA832);

/**
 *  GXDrawText()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXDrawText(long charCount, const unsigned char text[], const gxPoint *position)
    THREEWORDINLINE(0x303C, 0x009A, 0xA832);

/**
 *  GXNewColorProfile()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxColorProfile
GXNewColorProfile(long size, void *colorProfileData)
    THREEWORDINLINE(0x303C, 0x009B, 0xA832);

/**
 *  GXNewColorSet()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxColorSet
GXNewColorSet(gxColorSpace space, long count, const gxSetColor colors[])
    THREEWORDINLINE(0x303C, 0x009C, 0xA832);

/**
 *  GXNewInk()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxInk
GXNewInk(void) THREEWORDINLINE(0x303C, 0x009D, 0xA832);

/**
 *  GXNewShape()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxShape
GXNewShape(gxShapeType aType) THREEWORDINLINE(0x303C, 0x009E, 0xA832);

/**
 *  GXNewStyle()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxStyle
GXNewStyle(void) THREEWORDINLINE(0x303C, 0x009F, 0xA832);

/**
 *  GXNewTag()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxTag
GXNewTag(long tagType, long length, const void *data)
    THREEWORDINLINE(0x303C, 0x00A0, 0xA832);

/**
 *  GXNewTransform()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxTransform
GXNewTransform(void) THREEWORDINLINE(0x303C, 0x00A1, 0xA832);

/**
 *  GXNewViewDevice()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxViewDevice
GXNewViewDevice(gxViewGroup group, gxShape bitmapShape)
    THREEWORDINLINE(0x303C, 0x00A2, 0xA832);

/**
 *  GXNewViewGroup()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxViewGroup
GXNewViewGroup(void) THREEWORDINLINE(0x303C, 0x00A3, 0xA832);

/**
 *  GXNewViewPort()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxViewPort
GXNewViewPort(gxViewGroup group) THREEWORDINLINE(0x303C, 0x00A4, 0xA832);

/**
 *  GXDisposeColorProfile()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXDisposeColorProfile(gxColorProfile target)
    THREEWORDINLINE(0x303C, 0x00A5, 0xA832);

/**
 *  GXDisposeColorSet()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXDisposeColorSet(gxColorSet target) THREEWORDINLINE(0x303C, 0x00A6, 0xA832);

/**
 *  GXDisposeInk()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXDisposeInk(gxInk target) THREEWORDINLINE(0x303C, 0x00A7, 0xA832);

/**
 *  GXDisposeShape()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXDisposeShape(gxShape target) THREEWORDINLINE(0x303C, 0x00A8, 0xA832);

/**
 *  GXDisposeStyle()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXDisposeStyle(gxStyle target) THREEWORDINLINE(0x303C, 0x00A9, 0xA832);

/**
 *  GXDisposeTag()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXDisposeTag(gxTag target) THREEWORDINLINE(0x303C, 0x00AA, 0xA832);

/**
 *  GXDisposeTransform()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXDisposeTransform(gxTransform target) THREEWORDINLINE(0x303C, 0x00AB, 0xA832);

/**
 *  GXDisposeViewDevice()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXDisposeViewDevice(gxViewDevice target)
    THREEWORDINLINE(0x303C, 0x00AC, 0xA832);

/**
 *  GXDisposeViewGroup()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXDisposeViewGroup(gxViewGroup target) THREEWORDINLINE(0x303C, 0x00AD, 0xA832);

/**
 *  GXDisposeViewPort()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXDisposeViewPort(gxViewPort target) THREEWORDINLINE(0x303C, 0x00AE, 0xA832);

/**
 *  GXCloneColorProfile()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxColorProfile
GXCloneColorProfile(gxColorProfile source)
    THREEWORDINLINE(0x303C, 0x00AF, 0xA832);

/**
 *  GXCloneColorSet()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxColorSet
GXCloneColorSet(gxColorSet source) THREEWORDINLINE(0x303C, 0x00B0, 0xA832);

/**
 *  GXCloneInk()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxInk
GXCloneInk(gxInk source) THREEWORDINLINE(0x303C, 0x00B1, 0xA832);

/**
 *  GXCloneShape()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxShape
GXCloneShape(gxShape source) THREEWORDINLINE(0x303C, 0x00B2, 0xA832);

/**
 *  GXCloneStyle()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxStyle
GXCloneStyle(gxStyle source) THREEWORDINLINE(0x303C, 0x00B3, 0xA832);

/**
 *  GXCloneTag()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxTag
GXCloneTag(gxTag source) THREEWORDINLINE(0x303C, 0x00B4, 0xA832);

/**
 *  GXCloneTransform()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxTransform
GXCloneTransform(gxTransform source) THREEWORDINLINE(0x303C, 0x00B5, 0xA832);

/**
 *  GXCopyToColorProfile()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxColorProfile
GXCopyToColorProfile(gxColorProfile target, gxColorProfile source)
    THREEWORDINLINE(0x303C, 0x00B6, 0xA832);

/**
 *  GXCopyToColorSet()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxColorSet
GXCopyToColorSet(gxColorSet target, gxColorSet source)
    THREEWORDINLINE(0x303C, 0x00B7, 0xA832);

/**
 *  GXCopyToInk()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxInk
GXCopyToInk(gxInk target, gxInk source) THREEWORDINLINE(0x303C, 0x00B8, 0xA832);

/**
 *  GXCopyToShape()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxShape
GXCopyToShape(gxShape target, gxShape source)
    THREEWORDINLINE(0x303C, 0x00B9, 0xA832);

/**
 *  GXCopyToStyle()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxStyle
GXCopyToStyle(gxStyle target, gxStyle source)
    THREEWORDINLINE(0x303C, 0x00BA, 0xA832);

/**
 *  GXCopyToTag()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxTag
GXCopyToTag(gxTag target, gxTag source) THREEWORDINLINE(0x303C, 0x00BB, 0xA832);

/**
 *  GXCopyToTransform()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxTransform
GXCopyToTransform(gxTransform target, gxTransform source)
    THREEWORDINLINE(0x303C, 0x00BC, 0xA832);

/**
 *  GXCopyToViewDevice()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxViewDevice
GXCopyToViewDevice(gxViewDevice target, gxViewDevice source)
    THREEWORDINLINE(0x303C, 0x00BD, 0xA832);

/**
 *  GXCopyToViewPort()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxViewPort
GXCopyToViewPort(gxViewPort target, gxViewPort source)
    THREEWORDINLINE(0x303C, 0x00BE, 0xA832);

/**
 *  GXEqualColorProfile()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
Boolean
GXEqualColorProfile(gxColorProfile one, gxColorProfile two)
    THREEWORDINLINE(0x303C, 0x00BF, 0xA832);

/**
 *  GXEqualColorSet()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
Boolean
GXEqualColorSet(gxColorSet one, gxColorSet two)
    THREEWORDINLINE(0x303C, 0x00C0, 0xA832);

/**
 *  GXEqualInk()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
Boolean
GXEqualInk(gxInk one, gxInk two) THREEWORDINLINE(0x303C, 0x00C1, 0xA832);

/**
 *  GXEqualShape()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
Boolean
GXEqualShape(gxShape one, gxShape two) THREEWORDINLINE(0x303C, 0x00C2, 0xA832);

/**
 *  GXEqualStyle()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
Boolean
GXEqualStyle(gxStyle one, gxStyle two) THREEWORDINLINE(0x303C, 0x00C3, 0xA832);

/**
 *  GXEqualTag()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
Boolean
GXEqualTag(gxTag one, gxTag two) THREEWORDINLINE(0x303C, 0x00C4, 0xA832);

/**
 *  GXEqualTransform()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
Boolean
GXEqualTransform(gxTransform one, gxTransform two)
    THREEWORDINLINE(0x303C, 0x00C5, 0xA832);

/**
 *  GXEqualViewDevice()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
Boolean
GXEqualViewDevice(gxViewDevice one, gxViewDevice two)
    THREEWORDINLINE(0x303C, 0x00C6, 0xA832);

/**
 *  GXEqualViewPort()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
Boolean
GXEqualViewPort(gxViewPort one, gxViewPort two)
    THREEWORDINLINE(0x303C, 0x00C7, 0xA832);

/**
 *  GXResetInk()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXResetInk(gxInk target) THREEWORDINLINE(0x303C, 0x00C8, 0xA832);

/**
 *  GXResetShape()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXResetShape(gxShape target) THREEWORDINLINE(0x303C, 0x00C9, 0xA832);

/**
 *  GXResetStyle()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXResetStyle(gxStyle target) THREEWORDINLINE(0x303C, 0x00CA, 0xA832);

/**
 *  GXResetTransform()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXResetTransform(gxTransform target) THREEWORDINLINE(0x303C, 0x00CB, 0xA832);

/**
 *  GXLoadColorProfile()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXLoadColorProfile(gxColorProfile target)
    THREEWORDINLINE(0x303C, 0x00CC, 0xA832);

/**
 *  GXLoadColorSet()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXLoadColorSet(gxColorSet target) THREEWORDINLINE(0x303C, 0x00CD, 0xA832);

/**
 *  GXLoadInk()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXLoadInk(gxInk target) THREEWORDINLINE(0x303C, 0x00CE, 0xA832);

/**
 *  GXLoadShape()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXLoadShape(gxShape target) THREEWORDINLINE(0x303C, 0x00CF, 0xA832);

/**
 *  GXLoadStyle()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXLoadStyle(gxStyle target) THREEWORDINLINE(0x303C, 0x00D0, 0xA832);

/**
 *  GXLoadTag()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXLoadTag(gxTag target) THREEWORDINLINE(0x303C, 0x00D1, 0xA832);

/**
 *  GXLoadTransform()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXLoadTransform(gxTransform target) THREEWORDINLINE(0x303C, 0x00D2, 0xA832);

/**
 *  GXUnloadColorProfile()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXUnloadColorProfile(gxColorProfile target)
    THREEWORDINLINE(0x303C, 0x00D3, 0xA832);

/**
 *  GXUnloadColorSet()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXUnloadColorSet(gxColorSet target) THREEWORDINLINE(0x303C, 0x00D4, 0xA832);

/**
 *  GXUnloadInk()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXUnloadInk(gxInk target) THREEWORDINLINE(0x303C, 0x00D5, 0xA832);

/**
 *  GXUnloadShape()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXUnloadShape(gxShape target) THREEWORDINLINE(0x303C, 0x00D6, 0xA832);

/**
 *  GXUnloadStyle()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXUnloadStyle(gxStyle target) THREEWORDINLINE(0x303C, 0x00D7, 0xA832);

/**
 *  GXUnloadTag()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXUnloadTag(gxTag target) THREEWORDINLINE(0x303C, 0x00D8, 0xA832);

/**
 *  GXUnloadTransform()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXUnloadTransform(gxTransform target) THREEWORDINLINE(0x303C, 0x00D9, 0xA832);

/**
 *  GXCacheShape()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXCacheShape(gxShape source) THREEWORDINLINE(0x303C, 0x00DA, 0xA832);

/**
 *  GXCopyDeepToShape()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxShape
GXCopyDeepToShape(gxShape target, gxShape source)
    THREEWORDINLINE(0x303C, 0x00DB, 0xA832);

/**
 *  GXDrawShape()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXDrawShape(gxShape source) THREEWORDINLINE(0x303C, 0x00DC, 0xA832);

/**
 *  GXDisposeShapeCache()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXDisposeShapeCache(gxShape target) THREEWORDINLINE(0x303C, 0x00DD, 0xA832);

/**
 *  GXGetDefaultColorProfile()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxColorProfile
GXGetDefaultColorProfile(void) THREEWORDINLINE(0x303C, 0x00DE, 0xA832);

/**
 *  GXGetDefaultShape()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxShape
GXGetDefaultShape(gxShapeType aType) THREEWORDINLINE(0x303C, 0x00DF, 0xA832);

/**
 *  GXGetDefaultColorSet()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxColorSet
GXGetDefaultColorSet(long pixelDepth) THREEWORDINLINE(0x303C, 0x00E0, 0xA832);

/**
 *  GXSetDefaultShape()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetDefaultShape(gxShape target) THREEWORDINLINE(0x303C, 0x00E1, 0xA832);

/**
 *  GXSetDefaultColorSet()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetDefaultColorSet(gxColorSet target, long pixelDepth)
    THREEWORDINLINE(0x303C, 0x00E2, 0xA832);

/**
 *  GXGetTag()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
long
GXGetTag(gxTag source, long *tagType, void *data)
    THREEWORDINLINE(0x303C, 0x00E3, 0xA832);

/**
 *  GXSetTag()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetTag(gxTag target, long tagType, long length, const void *data)
    THREEWORDINLINE(0x303C, 0x00E4, 0xA832);

/**
 *  GXGetShapeBounds()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxRectangle *
GXGetShapeBounds(gxShape source, long index, gxRectangle *bounds)
    THREEWORDINLINE(0x303C, 0x00E5, 0xA832);

/**
 *  GXGetShapeFill()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxShapeFill
GXGetShapeFill(gxShape source) THREEWORDINLINE(0x303C, 0x00E6, 0xA832);

/**
 *  GXGetShapeInk()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxInk
GXGetShapeInk(gxShape source) THREEWORDINLINE(0x303C, 0x00E7, 0xA832);

/**
 *  GXGetShapePixel()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
long
GXGetShapePixel(gxShape source, long x, long y, gxColor *data, long *index)
    THREEWORDINLINE(0x303C, 0x00E8, 0xA832);

/**
 *  GXGetShapeStyle()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxStyle
GXGetShapeStyle(gxShape source) THREEWORDINLINE(0x303C, 0x00E9, 0xA832);

/**
 *  GXGetShapeTransform()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxTransform
GXGetShapeTransform(gxShape source) THREEWORDINLINE(0x303C, 0x00EA, 0xA832);

/**
 *  GXGetShapeType()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxShapeType
GXGetShapeType(gxShape source) THREEWORDINLINE(0x303C, 0x00EB, 0xA832);

/**
 *  GXGetShapeTypographicBounds()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxRectangle *
GXGetShapeTypographicBounds(gxShape source, gxRectangle *bounds)
    THREEWORDINLINE(0x303C, 0x00EC, 0xA832);

/**
 *  GXGetBitmapParts()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxShape
GXGetBitmapParts(gxShape source, const gxLongRectangle *bounds)
    THREEWORDINLINE(0x303C, 0x00ED, 0xA832);

/**
 *  GXGetStyleFontMetrics()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXGetStyleFontMetrics(gxStyle sourceStyle, gxPoint *before, gxPoint *after,
                      gxPoint *caretAngle, gxPoint *caretOffset)
    THREEWORDINLINE(0x303C, 0x00EE, 0xA832);

/**
 *  GXGetShapeFontMetrics()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXGetShapeFontMetrics(gxShape source, gxPoint *before, gxPoint *after,
                      gxPoint *caretAngle, gxPoint *caretOffset)
    THREEWORDINLINE(0x303C, 0x00EF, 0xA832);

/**
 *  GXSetShapeBounds()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetShapeBounds(gxShape target, const gxRectangle *newBounds)
    THREEWORDINLINE(0x303C, 0x00F0, 0xA832);

/**
 *  GXSetShapeFill()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetShapeFill(gxShape target, gxShapeFill newFill)
    THREEWORDINLINE(0x303C, 0x00F1, 0xA832);

/**
 *  GXSetShapeInk()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetShapeInk(gxShape target, gxInk newInk)
    THREEWORDINLINE(0x303C, 0x00F2, 0xA832);

/**
 *  GXSetShapePixel()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetShapePixel(gxShape target, long x, long y, const gxColor *newColor,
                long newIndex) THREEWORDINLINE(0x303C, 0x00F3, 0xA832);

/**
 *  GXSetShapeStyle()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetShapeStyle(gxShape target, gxStyle newStyle)
    THREEWORDINLINE(0x303C, 0x00F4, 0xA832);

/**
 *  GXSetShapeTransform()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetShapeTransform(gxShape target, gxTransform newTransform)
    THREEWORDINLINE(0x303C, 0x00F5, 0xA832);

/**
 *  GXSetShapeType()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetShapeType(gxShape target, gxShapeType newType)
    THREEWORDINLINE(0x303C, 0x00F6, 0xA832);

/**
 *  GXSetBitmapParts()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetBitmapParts(gxShape target, const gxLongRectangle *bounds,
                 gxShape bitmapShape) THREEWORDINLINE(0x303C, 0x00F7, 0xA832);

/**
 *  GXSetShapeGeometry()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetShapeGeometry(gxShape target, gxShape geometry)
    THREEWORDINLINE(0x303C, 0x00F8, 0xA832);

/**
 *  GXGetShapeCurveError()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
Fixed
GXGetShapeCurveError(gxShape source) THREEWORDINLINE(0x303C, 0x00F9, 0xA832);

/**
 *  GXGetShapeDash()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxDashRecord *
GXGetShapeDash(gxShape source, gxDashRecord *dash)
    THREEWORDINLINE(0x303C, 0x00FA, 0xA832);

/**
 *  GXGetShapeCap()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxCapRecord *
GXGetShapeCap(gxShape source, gxCapRecord *cap)
    THREEWORDINLINE(0x303C, 0x00FB, 0xA832);

// returns the number of layers /**
 *  GXGetShapeFace()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
// returns the number of layers 
 */
long
GXGetShapeFace(gxShape source, gxTextFace *face)
    THREEWORDINLINE(0x303C, 0x00FC, 0xA832);

/**
 *  GXGetShapeFont()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxFont
GXGetShapeFont(gxShape source) THREEWORDINLINE(0x303C, 0x00FD, 0xA832);

/**
 *  GXGetShapeJoin()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxJoinRecord *
GXGetShapeJoin(gxShape source, gxJoinRecord *join)
    THREEWORDINLINE(0x303C, 0x00FE, 0xA832);

/**
 *  GXGetShapeJustification()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
Fract
GXGetShapeJustification(gxShape source) THREEWORDINLINE(0x303C, 0x00FF, 0xA832);

/**
 *  GXGetShapePattern()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxPatternRecord *
GXGetShapePattern(gxShape source, gxPatternRecord *pattern)
    THREEWORDINLINE(0x303C, 0x0100, 0xA832);

/**
 *  GXGetShapePen()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
Fixed
GXGetShapePen(gxShape source) THREEWORDINLINE(0x303C, 0x0101, 0xA832);

/**
 *  GXGetShapeEncoding()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxFontPlatform
GXGetShapeEncoding(gxShape source, gxFontScript *script,
                   gxFontLanguage *language)
    THREEWORDINLINE(0x303C, 0x0102, 0xA832);

/**
 *  GXGetShapeTextSize()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
Fixed
GXGetShapeTextSize(gxShape source) THREEWORDINLINE(0x303C, 0x0103, 0xA832);

/**
 *  GXGetShapeFontVariations()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
long
GXGetShapeFontVariations(gxShape source, gxFontVariation variations[])
    THREEWORDINLINE(0x303C, 0x0104, 0xA832);

/**
 *  GXGetShapeFontVariationSuite()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
long
GXGetShapeFontVariationSuite(gxShape source, gxFontVariation variations[])
    THREEWORDINLINE(0x303C, 0x0105, 0xA832);

/**
 *  GXGetStyleCurveError()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
Fixed
GXGetStyleCurveError(gxStyle source) THREEWORDINLINE(0x303C, 0x0106, 0xA832);

/**
 *  GXGetStyleDash()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxDashRecord *
GXGetStyleDash(gxStyle source, gxDashRecord *dash)
    THREEWORDINLINE(0x303C, 0x0107, 0xA832);

/**
 *  GXGetStyleCap()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxCapRecord *
GXGetStyleCap(gxStyle source, gxCapRecord *cap)
    THREEWORDINLINE(0x303C, 0x0108, 0xA832);

// returns the number of layers /**
 *  GXGetStyleFace()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
// returns the number of layers 
long
GXGetStyleFace(gxStyle source, gxTextFace *face)
    THREEWORDINLINE(0x303C, 0x0109, 0xA832);

/**
 *  GXGetStyleFont()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxFont
GXGetStyleFont(gxStyle source) THREEWORDINLINE(0x303C, 0x010A, 0xA832);

/**
 *  GXGetStyleJoin()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxJoinRecord *
GXGetStyleJoin(gxStyle source, gxJoinRecord *join)
    THREEWORDINLINE(0x303C, 0x010B, 0xA832);

/**
 *  GXGetStyleJustification()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
Fract
GXGetStyleJustification(gxStyle source) THREEWORDINLINE(0x303C, 0x010C, 0xA832);

/**
 *  GXGetStylePattern()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxPatternRecord *
GXGetStylePattern(gxStyle source, gxPatternRecord *pattern)
    THREEWORDINLINE(0x303C, 0x010D, 0xA832);

/**
 *  GXGetStylePen()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
Fixed
GXGetStylePen(gxStyle source) THREEWORDINLINE(0x303C, 0x010E, 0xA832);

/**
 *  GXGetStyleEncoding()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxFontPlatform
GXGetStyleEncoding(gxStyle source, gxFontScript *script,
                   gxFontLanguage *language)
    THREEWORDINLINE(0x303C, 0x010F, 0xA832);

/**
 *  GXGetStyleTextSize()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
Fixed
GXGetStyleTextSize(gxStyle source) THREEWORDINLINE(0x303C, 0x0110, 0xA832);

/**
 *  GXGetStyleFontVariations()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
long
GXGetStyleFontVariations(gxStyle source, gxFontVariation variations[])
    THREEWORDINLINE(0x303C, 0x0111, 0xA832);

/**
 *  GXGetStyleFontVariationSuite()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
long
GXGetStyleFontVariationSuite(gxStyle source, gxFontVariation variations[])
    THREEWORDINLINE(0x303C, 0x0112, 0xA832);

/**
 *  GXSetShapeCurveError()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetShapeCurveError(gxShape target, Fixed error)
    THREEWORDINLINE(0x303C, 0x0113, 0xA832);

/**
 *  GXSetShapeDash()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetShapeDash(gxShape target, const gxDashRecord *dash)
    THREEWORDINLINE(0x303C, 0x0114, 0xA832);

/**
 *  GXSetShapeCap()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetShapeCap(gxShape target, const gxCapRecord *cap)
    THREEWORDINLINE(0x303C, 0x0115, 0xA832);

/**
 *  GXSetShapeFace()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetShapeFace(gxShape target, const gxTextFace *face)
    THREEWORDINLINE(0x303C, 0x0116, 0xA832);

/**
 *  GXSetShapeFont()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetShapeFont(gxShape target, gxFont aFont)
    THREEWORDINLINE(0x303C, 0x0117, 0xA832);

/**
 *  GXSetShapeJoin()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetShapeJoin(gxShape target, const gxJoinRecord *join)
    THREEWORDINLINE(0x303C, 0x0118, 0xA832);

/**
 *  GXSetShapeJustification()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetShapeJustification(gxShape target, Fract justify)
    THREEWORDINLINE(0x303C, 0x0119, 0xA832);

/**
 *  GXSetShapePattern()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetShapePattern(gxShape target, const gxPatternRecord *pattern)
    THREEWORDINLINE(0x303C, 0x011A, 0xA832);

/**
 *  GXSetShapePen()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetShapePen(gxShape target, Fixed pen)
    THREEWORDINLINE(0x303C, 0x011B, 0xA832);

/**
 *  GXSetShapeEncoding()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetShapeEncoding(gxShape target, gxFontPlatform platform, gxFontScript script,
                   gxFontLanguage language)
    THREEWORDINLINE(0x303C, 0x011C, 0xA832);

/**
 *  GXSetShapeTextSize()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetShapeTextSize(gxShape target, Fixed size)
    THREEWORDINLINE(0x303C, 0x011D, 0xA832);

/**
 *  GXSetShapeFontVariations()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetShapeFontVariations(gxShape target, long count,
                         const gxFontVariation variations[])
    THREEWORDINLINE(0x303C, 0x011E, 0xA832);

/**
 *  GXSetStyleCurveError()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetStyleCurveError(gxStyle target, Fixed error)
    THREEWORDINLINE(0x303C, 0x011F, 0xA832);

/**
 *  GXSetStyleDash()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetStyleDash(gxStyle target, const gxDashRecord *dash)
    THREEWORDINLINE(0x303C, 0x0120, 0xA832);

/**
 *  GXSetStyleCap()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetStyleCap(gxStyle target, const gxCapRecord *cap)
    THREEWORDINLINE(0x303C, 0x0121, 0xA832);

/**
 *  GXSetStyleFace()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetStyleFace(gxStyle target, const gxTextFace *face)
    THREEWORDINLINE(0x303C, 0x0122, 0xA832);

/**
 *  GXSetStyleFont()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetStyleFont(gxStyle target, gxFont aFont)
    THREEWORDINLINE(0x303C, 0x0123, 0xA832);

/**
 *  GXSetStyleJoin()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetStyleJoin(gxStyle target, const gxJoinRecord *join)
    THREEWORDINLINE(0x303C, 0x0124, 0xA832);

/**
 *  GXSetStyleJustification()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetStyleJustification(gxStyle target, Fract justify)
    THREEWORDINLINE(0x303C, 0x0125, 0xA832);

/**
 *  GXSetStylePattern()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetStylePattern(gxStyle target, const gxPatternRecord *pattern)
    THREEWORDINLINE(0x303C, 0x0126, 0xA832);

/**
 *  GXSetStylePen()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetStylePen(gxStyle target, Fixed pen)
    THREEWORDINLINE(0x303C, 0x0127, 0xA832);

/**
 *  GXSetStyleEncoding()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetStyleEncoding(gxStyle target, gxFontPlatform platform, gxFontScript script,
                   gxFontLanguage language)
    THREEWORDINLINE(0x303C, 0x0128, 0xA832);

/**
 *  GXSetStyleTextSize()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetStyleTextSize(gxStyle target, Fixed size)
    THREEWORDINLINE(0x303C, 0x0129, 0xA832);

/**
 *  GXSetStyleFontVariations()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetStyleFontVariations(gxStyle target, long count,
                         const gxFontVariation variations[])
    THREEWORDINLINE(0x303C, 0x012A, 0xA832);

/**
 *  GXGetShapeColor()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxColor *
GXGetShapeColor(gxShape source, gxColor *data)
    THREEWORDINLINE(0x303C, 0x012B, 0xA832);

/**
 *  GXGetShapeTransfer()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxTransferMode *
GXGetShapeTransfer(gxShape source, gxTransferMode *data)
    THREEWORDINLINE(0x303C, 0x012C, 0xA832);

/**
 *  GXGetInkColor()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxColor *
GXGetInkColor(gxInk source, gxColor *data)
    THREEWORDINLINE(0x303C, 0x012D, 0xA832);

/**
 *  GXGetInkTransfer()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxTransferMode *
GXGetInkTransfer(gxInk source, gxTransferMode *data)
    THREEWORDINLINE(0x303C, 0x012E, 0xA832);

/**
 *  GXSetShapeColor()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetShapeColor(gxShape target, const gxColor *data)
    THREEWORDINLINE(0x303C, 0x012F, 0xA832);

/**
 *  GXSetShapeTransfer()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetShapeTransfer(gxShape target, const gxTransferMode *data)
    THREEWORDINLINE(0x303C, 0x0130, 0xA832);

/**
 *  GXSetInkColor()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetInkColor(gxInk target, const gxColor *data)
    THREEWORDINLINE(0x303C, 0x0131, 0xA832);

/**
 *  GXSetInkTransfer()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetInkTransfer(gxInk target, const gxTransferMode *data)
    THREEWORDINLINE(0x303C, 0x0132, 0xA832);

/**
 *  GXGetShapeClip()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxShape
GXGetShapeClip(gxShape source) THREEWORDINLINE(0x303C, 0x0133, 0xA832);

/**
 *  GXGetShapeClipType()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxShapeType
GXGetShapeClipType(gxShape source) THREEWORDINLINE(0x303C, 0x0276, 0xA832);

/**
 *  GXGetShapeMapping()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxMapping *
GXGetShapeMapping(gxShape source, gxMapping *map)
    THREEWORDINLINE(0x303C, 0x0134, 0xA832);

/**
 *  GXGetShapeHitTest()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxShapePart
GXGetShapeHitTest(gxShape source, Fixed *tolerance)
    THREEWORDINLINE(0x303C, 0x0135, 0xA832);

/**
 *  GXGetShapeViewPorts()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
long
GXGetShapeViewPorts(gxShape source, gxViewPort list[])
    THREEWORDINLINE(0x303C, 0x0136, 0xA832);

/**
 *  GXGetTransformClip()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxShape
GXGetTransformClip(gxTransform source) THREEWORDINLINE(0x303C, 0x0137, 0xA832);

/**
 *  GXGetTransformClipType()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxShapeType
GXGetTransformClipType(gxTransform source)
    THREEWORDINLINE(0x303C, 0x0277, 0xA832);

/**
 *  GXGetTransformMapping()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxMapping *
GXGetTransformMapping(gxTransform source, gxMapping *map)
    THREEWORDINLINE(0x303C, 0x0138, 0xA832);

/**
 *  GXGetTransformHitTest()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxShapePart
GXGetTransformHitTest(gxTransform source, Fixed *tolerance)
    THREEWORDINLINE(0x303C, 0x0139, 0xA832);

/**
 *  GXGetTransformViewPorts()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
long
GXGetTransformViewPorts(gxTransform source, gxViewPort list[])
    THREEWORDINLINE(0x303C, 0x013A, 0xA832);

/**
 *  GXSetShapeClip()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetShapeClip(gxShape target, gxShape clip)
    THREEWORDINLINE(0x303C, 0x013B, 0xA832);

/**
 *  GXSetShapeMapping()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetShapeMapping(gxShape target, const gxMapping *map)
    THREEWORDINLINE(0x303C, 0x013C, 0xA832);

/**
 *  GXSetShapeHitTest()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetShapeHitTest(gxShape target, gxShapePart mask, Fixed tolerance)
    THREEWORDINLINE(0x303C, 0x013D, 0xA832);

/**
 *  GXSetShapeViewPorts()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetShapeViewPorts(gxShape target, long count, const gxViewPort list[])
    THREEWORDINLINE(0x303C, 0x013E, 0xA832);

/**
 *  GXSetTransformClip()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetTransformClip(gxTransform target, gxShape clip)
    THREEWORDINLINE(0x303C, 0x013F, 0xA832);

/**
 *  GXSetTransformMapping()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetTransformMapping(gxTransform target, const gxMapping *map)
    THREEWORDINLINE(0x303C, 0x0140, 0xA832);

/**
 *  GXSetTransformHitTest()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetTransformHitTest(gxTransform target, gxShapePart mask, Fixed tolerance)
    THREEWORDINLINE(0x303C, 0x0141, 0xA832);

/**
 *  GXSetTransformViewPorts()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetTransformViewPorts(gxTransform target, long count, const gxViewPort list[])
    THREEWORDINLINE(0x303C, 0x0142, 0xA832);

/**
 *  GXGetColorSet()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
long
GXGetColorSet(gxColorSet source, gxColorSpace *space, gxSetColor colors[])
    THREEWORDINLINE(0x303C, 0x0143, 0xA832);

/**
 *  GXGetColorProfile()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
long
GXGetColorProfile(gxColorProfile source, void *colorProfileData)
    THREEWORDINLINE(0x303C, 0x0144, 0xA832);

/**
 *  GXSetColorSet()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetColorSet(gxColorSet target, gxColorSpace space, long count,
              const gxSetColor colors[])
    THREEWORDINLINE(0x303C, 0x0145, 0xA832);

/**
 *  GXSetColorProfile()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetColorProfile(gxColorProfile target, long size, void *colorProfileData)
    THREEWORDINLINE(0x303C, 0x0146, 0xA832);

/**
 *  GXGetViewDeviceBitmap()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxShape
GXGetViewDeviceBitmap(gxViewDevice source)
    THREEWORDINLINE(0x303C, 0x0147, 0xA832);

/**
 *  GXGetViewDeviceClip()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxShape
GXGetViewDeviceClip(gxViewDevice source)
    THREEWORDINLINE(0x303C, 0x0148, 0xA832);

/**
 *  GXGetViewDeviceMapping()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxMapping *
GXGetViewDeviceMapping(gxViewDevice source, gxMapping *map)
    THREEWORDINLINE(0x303C, 0x0149, 0xA832);

/**
 *  GXGetViewDeviceViewGroup()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxViewGroup
GXGetViewDeviceViewGroup(gxViewDevice source)
    THREEWORDINLINE(0x303C, 0x014A, 0xA832);

/**
 *  GXSetViewDeviceBitmap()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetViewDeviceBitmap(gxViewDevice target, gxShape bitmapShape)
    THREEWORDINLINE(0x303C, 0x014B, 0xA832);

/**
 *  GXSetViewDeviceClip()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetViewDeviceClip(gxViewDevice target, gxShape clip)
    THREEWORDINLINE(0x303C, 0x014C, 0xA832);

/**
 *  GXSetViewDeviceMapping()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetViewDeviceMapping(gxViewDevice target, const gxMapping *map)
    THREEWORDINLINE(0x303C, 0x014D, 0xA832);

/**
 *  GXSetViewDeviceViewGroup()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetViewDeviceViewGroup(gxViewDevice target, gxViewGroup group)
    THREEWORDINLINE(0x303C, 0x014E, 0xA832);

/**
 *  GXGetViewPortChildren()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
long
GXGetViewPortChildren(gxViewPort source, gxViewPort list[])
    THREEWORDINLINE(0x303C, 0x014F, 0xA832);

/**
 *  GXGetViewPortClip()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxShape
GXGetViewPortClip(gxViewPort source) THREEWORDINLINE(0x303C, 0x0150, 0xA832);

/**
 *  GXGetViewPortDither()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
long
GXGetViewPortDither(gxViewPort source) THREEWORDINLINE(0x303C, 0x0151, 0xA832);

/**
 *  GXGetViewPortHalftone()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
Boolean
GXGetViewPortHalftone(gxViewPort source, gxHalftone *data)
    THREEWORDINLINE(0x303C, 0x0152, 0xA832);

/**
 *  GXGetViewPortMapping()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxMapping *
GXGetViewPortMapping(gxViewPort source, gxMapping *map)
    THREEWORDINLINE(0x303C, 0x0153, 0xA832);

/**
 *  GXGetViewPortParent()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxViewPort
GXGetViewPortParent(gxViewPort source) THREEWORDINLINE(0x303C, 0x0154, 0xA832);

/**
 *  GXGetViewPortViewGroup()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxViewGroup
GXGetViewPortViewGroup(gxViewPort source)
    THREEWORDINLINE(0x303C, 0x0155, 0xA832);

/**
 *  GXGetViewPortHalftoneMatrix()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
long
GXGetViewPortHalftoneMatrix(gxViewPort source, gxViewDevice sourceDevice,
                            gxHalftoneMatrix *theMatrix)
    THREEWORDINLINE(0x303C, 0x0273, 0xA832);

/**
 *  GXSetViewPortChildren()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetViewPortChildren(gxViewPort target, long count, const gxViewPort list[])
    THREEWORDINLINE(0x303C, 0x0156, 0xA832);

/**
 *  GXSetViewPortClip()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetViewPortClip(gxViewPort target, gxShape clip)
    THREEWORDINLINE(0x303C, 0x0157, 0xA832);

/**
 *  GXSetViewPortDither()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetViewPortDither(gxViewPort target, long level)
    THREEWORDINLINE(0x303C, 0x0158, 0xA832);

/**
 *  GXSetViewPortHalftone()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetViewPortHalftone(gxViewPort target, const gxHalftone *data)
    THREEWORDINLINE(0x303C, 0x0159, 0xA832);

/**
 *  GXSetViewPortMapping()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetViewPortMapping(gxViewPort target, const gxMapping *map)
    THREEWORDINLINE(0x303C, 0x015A, 0xA832);

/**
 *  GXSetViewPortParent()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetViewPortParent(gxViewPort target, gxViewPort parent)
    THREEWORDINLINE(0x303C, 0x015B, 0xA832);

/**
 *  GXSetViewPortViewGroup()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetViewPortViewGroup(gxViewPort target, gxViewGroup group)
    THREEWORDINLINE(0x303C, 0x015C, 0xA832);

/**
 *  GXGetColorProfileTags()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
long
GXGetColorProfileTags(gxColorProfile source, long tagType, long index,
                      long count, gxTag items[])
    THREEWORDINLINE(0x303C, 0x015D, 0xA832);

/**
 *  GXGetColorSetTags()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
long
GXGetColorSetTags(gxColorSet source, long tagType, long index, long count,
                  gxTag items[]) THREEWORDINLINE(0x303C, 0x015E, 0xA832);

/**
 *  GXGetInkTags()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
long
GXGetInkTags(gxInk source, long tagType, long index, long count, gxTag items[])
    THREEWORDINLINE(0x303C, 0x015F, 0xA832);

/**
 *  GXGetShapeTags()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
long
GXGetShapeTags(gxShape source, long tagType, long index, long count,
               gxTag items[]) THREEWORDINLINE(0x303C, 0x0160, 0xA832);

/**
 *  GXGetStyleTags()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
long
GXGetStyleTags(gxStyle source, long tagType, long index, long count,
               gxTag items[]) THREEWORDINLINE(0x303C, 0x0161, 0xA832);

/**
 *  GXGetTransformTags()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
long
GXGetTransformTags(gxTransform source, long tagType, long index, long count,
                   gxTag items[]) THREEWORDINLINE(0x303C, 0x0162, 0xA832);

/**
 *  GXGetViewDeviceTags()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
long
GXGetViewDeviceTags(gxViewDevice source, long tagType, long index, long count,
                    gxTag items[]) THREEWORDINLINE(0x303C, 0x0163, 0xA832);

/**
 *  GXGetViewPortTags()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
long
GXGetViewPortTags(gxViewPort source, long tagType, long index, long count,
                  gxTag items[]) THREEWORDINLINE(0x303C, 0x0164, 0xA832);

/**
 *  GXSetColorProfileTags()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetColorProfileTags(gxColorProfile target, long tagType, long index,
                      long oldCount, long newCount, const gxTag items[])
    THREEWORDINLINE(0x303C, 0x0165, 0xA832);

/**
 *  GXSetColorSetTags()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetColorSetTags(gxColorSet target, long tagType, long index, long oldCount,
                  long newCount, const gxTag items[])
    THREEWORDINLINE(0x303C, 0x0166, 0xA832);

/**
 *  GXSetInkTags()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetInkTags(gxInk target, long tagType, long index, long oldCount,
             long newCount, const gxTag items[])
    THREEWORDINLINE(0x303C, 0x0167, 0xA832);

/**
 *  GXSetShapeTags()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetShapeTags(gxShape target, long tagType, long index, long oldCount,
               long newCount, const gxTag items[])
    THREEWORDINLINE(0x303C, 0x0168, 0xA832);

/**
 *  GXSetStyleTags()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetStyleTags(gxStyle target, long tagType, long index, long oldCount,
               long newCount, const gxTag items[])
    THREEWORDINLINE(0x303C, 0x0169, 0xA832);

/**
 *  GXSetTransformTags()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetTransformTags(gxTransform target, long tagType, long index, long oldCount,
                   long newCount, const gxTag items[])
    THREEWORDINLINE(0x303C, 0x016A, 0xA832);

/**
 *  GXSetViewDeviceTags()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetViewDeviceTags(gxViewDevice target, long tagType, long index,
                    long oldCount, long newCount, const gxTag items[])
    THREEWORDINLINE(0x303C, 0x016B, 0xA832);

/**
 *  GXSetViewPortTags()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetViewPortTags(gxViewPort target, long tagType, long index, long oldCount,
                  long newCount, const gxTag items[])
    THREEWORDINLINE(0x303C, 0x016C, 0xA832);

/**
 *  GXGetInkAttributes()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxInkAttribute
GXGetInkAttributes(gxInk source) THREEWORDINLINE(0x303C, 0x016D, 0xA832);

/**
 *  GXGetShapeAttributes()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxShapeAttribute
GXGetShapeAttributes(gxShape source) THREEWORDINLINE(0x303C, 0x016E, 0xA832);

/**
 *  GXGetShapeInkAttributes()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxInkAttribute
GXGetShapeInkAttributes(gxShape source) THREEWORDINLINE(0x303C, 0x016F, 0xA832);

/**
 *  GXGetShapeStyleAttributes()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxStyleAttribute
GXGetShapeStyleAttributes(gxShape source)
    THREEWORDINLINE(0x303C, 0x0170, 0xA832);

/**
 *  GXGetStyleAttributes()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxStyleAttribute
GXGetStyleAttributes(gxStyle source) THREEWORDINLINE(0x303C, 0x0171, 0xA832);

/**
 *  GXGetShapeTextAttributes()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxTextAttribute
GXGetShapeTextAttributes(gxShape source)
    THREEWORDINLINE(0x303C, 0x0172, 0xA832);

/**
 *  GXGetStyleTextAttributes()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxTextAttribute
GXGetStyleTextAttributes(gxStyle source)
    THREEWORDINLINE(0x303C, 0x0173, 0xA832);

/**
 *  GXGetViewDeviceAttributes()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxDeviceAttribute
GXGetViewDeviceAttributes(gxViewDevice source)
    THREEWORDINLINE(0x303C, 0x0174, 0xA832);

/**
 *  GXGetViewPortAttributes()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxPortAttribute
GXGetViewPortAttributes(gxViewPort source)
    THREEWORDINLINE(0x303C, 0x0175, 0xA832);

/**
 *  GXSetInkAttributes()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetInkAttributes(gxInk target, gxInkAttribute attributes)
    THREEWORDINLINE(0x303C, 0x0176, 0xA832);

/**
 *  GXSetShapeAttributes()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetShapeAttributes(gxShape target, gxShapeAttribute attributes)
    THREEWORDINLINE(0x303C, 0x0177, 0xA832);

/**
 *  GXSetShapeInkAttributes()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetShapeInkAttributes(gxShape target, gxInkAttribute attributes)
    THREEWORDINLINE(0x303C, 0x0178, 0xA832);

/**
 *  GXSetShapeStyleAttributes()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetShapeStyleAttributes(gxShape target, gxStyleAttribute attributes)
    THREEWORDINLINE(0x303C, 0x0179, 0xA832);

/**
 *  GXSetStyleAttributes()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetStyleAttributes(gxStyle target, gxStyleAttribute attributes)
    THREEWORDINLINE(0x303C, 0x017A, 0xA832);

/**
 *  GXSetShapeTextAttributes()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetShapeTextAttributes(gxShape target, gxTextAttribute attributes)
    THREEWORDINLINE(0x303C, 0x017B, 0xA832);

/**
 *  GXSetStyleTextAttributes()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetStyleTextAttributes(gxStyle target, gxTextAttribute attributes)
    THREEWORDINLINE(0x303C, 0x017C, 0xA832);

/**
 *  GXSetViewDeviceAttributes()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetViewDeviceAttributes(gxViewDevice target, gxDeviceAttribute attributes)
    THREEWORDINLINE(0x303C, 0x017D, 0xA832);

/**
 *  GXSetViewPortAttributes()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetViewPortAttributes(gxViewPort target, gxPortAttribute attributes)
    THREEWORDINLINE(0x303C, 0x017E, 0xA832);

/**
 *  GXGetColorProfileOwners()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
long
GXGetColorProfileOwners(gxColorProfile source)
    THREEWORDINLINE(0x303C, 0x017F, 0xA832);

/**
 *  GXGetColorSetOwners()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
long
GXGetColorSetOwners(gxColorSet source) THREEWORDINLINE(0x303C, 0x0180, 0xA832);

/**
 *  GXGetInkOwners()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
long
GXGetInkOwners(gxInk source) THREEWORDINLINE(0x303C, 0x0181, 0xA832);

/**
 *  GXGetShapeOwners()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
long
GXGetShapeOwners(gxShape source) THREEWORDINLINE(0x303C, 0x0182, 0xA832);

/**
 *  GXGetStyleOwners()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
long
GXGetStyleOwners(gxStyle source) THREEWORDINLINE(0x303C, 0x0183, 0xA832);

/**
 *  GXGetTagOwners()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
long
GXGetTagOwners(gxTag source) THREEWORDINLINE(0x303C, 0x0184, 0xA832);

/**
 *  GXGetTransformOwners()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
long
GXGetTransformOwners(gxTransform source)
    THREEWORDINLINE(0x303C, 0x0185, 0xA832);

/**
 *  GXLockShape()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXLockShape(gxShape target) THREEWORDINLINE(0x303C, 0x0186, 0xA832);

/**
 *  GXLockTag()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXLockTag(gxTag target) THREEWORDINLINE(0x303C, 0x0187, 0xA832);

/**
 *  GXUnlockShape()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXUnlockShape(gxShape target) THREEWORDINLINE(0x303C, 0x0188, 0xA832);

/**
 *  GXUnlockTag()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXUnlockTag(gxTag target) THREEWORDINLINE(0x303C, 0x0189, 0xA832);

/**
 *  GXGetShapeStructure()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void *
GXGetShapeStructure(gxShape source, long *length)
    THREEWORDINLINE(0x303C, 0x018A, 0xA832);

/**
 *  GXGetTagStructure()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void *
GXGetTagStructure(gxTag source, long *length)
    THREEWORDINLINE(0x303C, 0x018B, 0xA832);

/**
 *  GXGetColorDistance()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
Fixed
GXGetColorDistance(const gxColor *target, const gxColor *source)
    THREEWORDINLINE(0x303C, 0x018C, 0xA832);

/**
 *  GXShapeLengthToPoint()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxPoint *
GXShapeLengthToPoint(gxShape target, long index, Fixed length,
                     gxPoint *location, gxPoint *tangent)
    THREEWORDINLINE(0x303C, 0x018D, 0xA832);

/**
 *  GXGetShapeArea()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
wide *
GXGetShapeArea(gxShape source, long index, wide *area)
    THREEWORDINLINE(0x303C, 0x018E, 0xA832);

/**
 *  GXGetShapeCacheSize()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
long
GXGetShapeCacheSize(gxShape source) THREEWORDINLINE(0x303C, 0x018F, 0xA832);

/**
 *  GXGetShapeCenter()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxPoint *
GXGetShapeCenter(gxShape source, long index, gxPoint *center)
    THREEWORDINLINE(0x303C, 0x0190, 0xA832);

/**
 *  GXGetShapeDirection()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxContourDirection
GXGetShapeDirection(gxShape source, long contour)
    THREEWORDINLINE(0x303C, 0x0191, 0xA832);

/**
 *  GXGetShapeIndex()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
long
GXGetShapeIndex(gxShape source, long contour, long vector)
    THREEWORDINLINE(0x303C, 0x0192, 0xA832);

/**
 *  GXGetShapeLength()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
wide *
GXGetShapeLength(gxShape source, long index, wide *length)
    THREEWORDINLINE(0x303C, 0x0193, 0xA832);

/**
 *  GXGetShapeSize()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
long
GXGetShapeSize(gxShape source) THREEWORDINLINE(0x303C, 0x0194, 0xA832);

/**
 *  GXCountShapeContours()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
long
GXCountShapeContours(gxShape source) THREEWORDINLINE(0x303C, 0x0195, 0xA832);

/**
 *  GXCountShapePoints()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
long
GXCountShapePoints(gxShape source, long contour)
    THREEWORDINLINE(0x303C, 0x0196, 0xA832);

// returns the number of positions /**
 *  GXGetShapeDashPositions()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
// returns the number of positions 
GXGetShapeDashPositions(gxShape source, gxMapping dashMappings[])
    THREEWORDINLINE(0x303C, 0x0197, 0xA832);

/**
 *  GXGetShapeDeviceArea()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
long
GXGetShapeDeviceArea(gxShape source, gxViewPort port, gxViewDevice device)
    THREEWORDINLINE(0x303C, 0x0198, 0xA832);

/**
 *  GXGetShapeDeviceBounds()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
Boolean
GXGetShapeDeviceBounds(gxShape source, gxViewPort port, gxViewDevice device,
                       gxRectangle *bounds)
    THREEWORDINLINE(0x303C, 0x0199, 0xA832);

/**
 *  GXGetShapeDeviceColors()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxColorSet
GXGetShapeDeviceColors(gxShape source, gxViewPort port, gxViewDevice device,
                       long *width) THREEWORDINLINE(0x303C, 0x019A, 0xA832);

/**
 *  GXGetShapeGlobalBounds()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
Boolean
GXGetShapeGlobalBounds(gxShape source, gxViewPort port, gxViewGroup group,
                       gxRectangle *bounds)
    THREEWORDINLINE(0x303C, 0x019B, 0xA832);

/**
 *  GXGetShapeGlobalViewDevices()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
long
GXGetShapeGlobalViewDevices(gxShape source, gxViewPort port,
                            gxViewDevice list[])
    THREEWORDINLINE(0x303C, 0x019C, 0xA832);

/**
 *  GXGetShapeGlobalViewPorts()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
long
GXGetShapeGlobalViewPorts(gxShape source, gxViewPort list[])
    THREEWORDINLINE(0x303C, 0x019D, 0xA832);

/**
 *  GXGetShapeLocalBounds()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxRectangle *
GXGetShapeLocalBounds(gxShape source, gxRectangle *bounds)
    THREEWORDINLINE(0x303C, 0x019E, 0xA832);

// returns the number of positions /**
 *  GXGetShapePatternPositions()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
long
// returns the number of positions 
    THREEWORDINLINE(0x303C, 0x019F, 0xA832);

/**
 *  GXGetShapeLocalFontMetrics()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXGetShapeLocalFontMetrics(gxShape sourceShape, gxPoint *before, gxPoint *after,
                           gxPoint *caretAngle, gxPoint *caretOffset)
    THREEWORDINLINE(0x303C, 0x01A0, 0xA832);

/**
 *  GXGetShapeDeviceFontMetrics()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXGetShapeDeviceFontMetrics(gxShape sourceShape, gxViewPort port,
                            gxViewDevice device, gxPoint *before,
                            gxPoint *after, gxPoint *caretAngle,
                            gxPoint *caretOffset)
    THREEWORDINLINE(0x303C, 0x01A1, 0xA832);

/**
 *  GXGetViewGroupViewDevices()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
long
GXGetViewGroupViewDevices(gxViewGroup source, gxViewDevice list[])
    THREEWORDINLINE(0x303C, 0x01A2, 0xA832);

/**
 *  GXGetViewGroupViewPorts()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
long
GXGetViewGroupViewPorts(gxViewGroup source, gxViewPort list[])
    THREEWORDINLINE(0x303C, 0x01A3, 0xA832);

/**
 *  GXGetViewPortGlobalMapping()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxMapping *
GXGetViewPortGlobalMapping(gxViewPort source, gxMapping *map)
    THREEWORDINLINE(0x303C, 0x01A4, 0xA832);

/**
 *  GXGetViewPortViewDevices()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
long
GXGetViewPortViewDevices(gxViewPort source, gxViewDevice list[])
    THREEWORDINLINE(0x303C, 0x01A5, 0xA832);

/**
 *  GXHitTestPicture()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxShape
GXHitTestPicture(gxShape target, const gxPoint *test, gxHitTestInfo *result,
                 long level, long depth)
    THREEWORDINLINE(0x303C, 0x01A6, 0xA832);

/**
 *  GXIntersectRectangle()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
Boolean
GXIntersectRectangle(gxRectangle *target, const gxRectangle *source,
                     const gxRectangle *operand)
    THREEWORDINLINE(0x303C, 0x01A7, 0xA832);

/**
 *  GXUnionRectangle()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxRectangle *
GXUnionRectangle(gxRectangle *target, const gxRectangle *source,
                 const gxRectangle *operand)
    THREEWORDINLINE(0x303C, 0x01A8, 0xA832);

/**
 *  GXTouchesRectanglePoint()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
Boolean
GXTouchesRectanglePoint(const gxRectangle *target, const gxPoint *test)
    THREEWORDINLINE(0x303C, 0x01A9, 0xA832);

/**
 *  GXTouchesShape()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
Boolean
GXTouchesShape(gxShape target, gxShape test)
    THREEWORDINLINE(0x303C, 0x01AA, 0xA832);

/**
 *  GXTouchesBoundsShape()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
Boolean
GXTouchesBoundsShape(const gxRectangle *target, gxShape test)
    THREEWORDINLINE(0x303C, 0x01AB, 0xA832);

/**
 *  GXContainsRectangle()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
Boolean
GXContainsRectangle(const gxRectangle *container, const gxRectangle *test)
    THREEWORDINLINE(0x303C, 0x01AC, 0xA832);

/**
 *  GXContainsShape()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
Boolean
GXContainsShape(gxShape container, gxShape test)
    THREEWORDINLINE(0x303C, 0x01AD, 0xA832);

/**
 *  GXContainsBoundsShape()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
Boolean
GXContainsBoundsShape(const gxRectangle *container, gxShape test, long index)
    THREEWORDINLINE(0x303C, 0x01AE, 0xA832);

/**
 *  GXConvertColor()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxColor *
GXConvertColor(gxColor *target, gxColorSpace space, gxColorSet aSet,
               gxColorProfile profile) THREEWORDINLINE(0x303C, 0x01AF, 0xA832);

/**
 *  GXCombineColor()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxColor *
GXCombineColor(gxColor *target, gxInk operand)
    THREEWORDINLINE(0x303C, 0x01B0, 0xA832);

/**
 *  GXCheckColor()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
Boolean
GXCheckColor(const gxColor *source, gxColorSpace space, gxColorSet aSet,
             gxColorProfile profile) THREEWORDINLINE(0x303C, 0x01B1, 0xA832);

/**
 *  GXCheckBitmapColor()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxShape
GXCheckBitmapColor(gxShape source, const gxLongRectangle *area,
                   gxColorSpace space, gxColorSet aSet, gxColorProfile profile)
    THREEWORDINLINE(0x303C, 0x01B2, 0xA832);

/**
 *  GXGetHalftoneDeviceAngle()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
Fixed
GXGetHalftoneDeviceAngle(gxViewDevice source, const gxHalftone *data)
    THREEWORDINLINE(0x303C, 0x01B3, 0xA832);

/**
 *  GXGetColorSetParts()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
long
GXGetColorSetParts(gxColorSet source, long index, long count,
                   gxColorSpace *space, gxSetColor data[])
    THREEWORDINLINE(0x303C, 0x01B4, 0xA832);

// returns the glyph count /**
 *  GXGetGlyphParts()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
long
GXGetGlyphParts(gxShape source, long index, long charCount, long *byteLength,
// returns the glyph count 
                gxPoint tangents[], long *runCount, short styleRuns[],
                gxStyle styles[]) THREEWORDINLINE(0x303C, 0x01B5, 0xA832);

/**
 *  GXGetPathParts()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
long
GXGetPathParts(gxShape source, long index, long count, gxPaths *data)
    THREEWORDINLINE(0x303C, 0x01B6, 0xA832);

/**
 *  GXGetPictureParts()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
long
GXGetPictureParts(gxShape source, long index, long count, gxShape shapes[],
                  gxStyle styles[], gxInk inks[], gxTransform transforms[])
    THREEWORDINLINE(0x303C, 0x01B7, 0xA832);

/**
 *  GXGetPolygonParts()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
long
GXGetPolygonParts(gxShape source, long index, long count, gxPolygons *data)
    THREEWORDINLINE(0x303C, 0x01B8, 0xA832);

/**
 *  GXGetShapeParts()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxShape
GXGetShapeParts(gxShape source, long index, long count, gxShape destination)
    THREEWORDINLINE(0x303C, 0x01B9, 0xA832);

/**
 *  GXGetTextParts()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
long
GXGetTextParts(gxShape source, long index, long charCount, unsigned char text[])
    THREEWORDINLINE(0x303C, 0x01BA, 0xA832);

/**
 *  GXSetColorSetParts()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetColorSetParts(gxColorSet target, long index, long oldCount, long newCount,
                   const gxSetColor data[])
    THREEWORDINLINE(0x303C, 0x01BB, 0xA832);

/**
 *  GXSetGlyphParts()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetGlyphParts(gxShape source, long index, long oldCharCount,
                long newCharCount, const unsigned char text[],
                const gxPoint positions[], const long advanceBits[],
                const gxPoint tangents[], const short styleRuns[],
                const gxStyle styles[]) THREEWORDINLINE(0x303C, 0x01BC, 0xA832);

/**
 *  GXSetPathParts()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetPathParts(gxShape target, long index, long count, const gxPaths *data,
               gxEditShapeFlag flags) THREEWORDINLINE(0x303C, 0x01BD, 0xA832);

/**
 *  GXSetPictureParts()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetPictureParts(gxShape target, long index, long oldCount, long newCount,
                  const gxShape shapes[], const gxStyle styles[],
                  const gxInk inks[], const gxTransform transforms[])
    THREEWORDINLINE(0x303C, 0x01BE, 0xA832);

/**
 *  GXSetPolygonParts()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetPolygonParts(gxShape target, long index, long count,
                  const gxPolygons *data, gxEditShapeFlag flags)
    THREEWORDINLINE(0x303C, 0x01BF, 0xA832);

/**
 *  GXSetShapeParts()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetShapeParts(gxShape target, long index, long count, gxShape insert,
                gxEditShapeFlag flags) THREEWORDINLINE(0x303C, 0x01C0, 0xA832);

/**
 *  GXSetTextParts()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetTextParts(gxShape target, long index, long oldCharCount, long newCharCount,
               const unsigned char text[])
    THREEWORDINLINE(0x303C, 0x01C1, 0xA832);

/**
 *  GXGetShapePoints()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
long
GXGetShapePoints(gxShape source, long index, long count, gxPoint data[])
    THREEWORDINLINE(0x303C, 0x01C2, 0xA832);

/**
 *  GXSetShapePoints()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetShapePoints(gxShape target, long index, long count, const gxPoint data[])
    THREEWORDINLINE(0x303C, 0x01C3, 0xA832);

/**
 *  GXGetGlyphPositions()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
long
GXGetGlyphPositions(gxShape source, long index, long charCount, long advance[],
                    gxPoint positions[])
    THREEWORDINLINE(0x303C, 0x01C4, 0xA832);

/**
 *  GXGetGlyphTangents()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
long
GXGetGlyphTangents(gxShape source, long index, long charCount,
                   gxPoint tangents[]) THREEWORDINLINE(0x303C, 0x01C5, 0xA832);

/**
 *  GXSetGlyphPositions()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetGlyphPositions(gxShape target, long index, long charCount,
                    const long advance[], const gxPoint positions[])
    THREEWORDINLINE(0x303C, 0x01C6, 0xA832);

/**
 *  GXSetGlyphTangents()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSetGlyphTangents(gxShape target, long index, long charCount,
                   const gxPoint tangents[])
    THREEWORDINLINE(0x303C, 0x01C7, 0xA832);

/**
 *  GXGetGlyphMetrics()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
long
GXGetGlyphMetrics(gxShape source, gxPoint glyphOrigins[],
                  gxRectangle boundingBoxes[], gxPoint sideBearings[])
    THREEWORDINLINE(0x303C, 0x01C8, 0xA832);

/**
 *  GXDifferenceShape()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXDifferenceShape(gxShape target, gxShape operand)
    THREEWORDINLINE(0x303C, 0x01C9, 0xA832);

/**
 *  GXExcludeShape()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXExcludeShape(gxShape target, gxShape operand)
    THREEWORDINLINE(0x303C, 0x01CA, 0xA832);

/**
 *  GXIntersectShape()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXIntersectShape(gxShape target, gxShape operand)
    THREEWORDINLINE(0x303C, 0x01CB, 0xA832);

/**
 *  GXMapShape()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXMapShape(gxShape target, const gxMapping *map)
    THREEWORDINLINE(0x303C, 0x01CC, 0xA832);

/**
 *  GXMoveShape()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXMoveShape(gxShape target, Fixed deltaX, Fixed deltaY)
    THREEWORDINLINE(0x303C, 0x01CD, 0xA832);

/**
 *  GXMoveShapeTo()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXMoveShapeTo(gxShape target, Fixed x, Fixed y)
    THREEWORDINLINE(0x303C, 0x01CE, 0xA832);

/**
 *  GXReverseDifferenceShape()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXReverseDifferenceShape(gxShape target, gxShape operand)
    THREEWORDINLINE(0x303C, 0x01CF, 0xA832);

/**
 *  GXRotateShape()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXRotateShape(gxShape target, Fixed degrees, Fixed xOffset, Fixed yOffset)
    THREEWORDINLINE(0x303C, 0x01D0, 0xA832);

/**
 *  GXScaleShape()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXScaleShape(gxShape target, Fixed hScale, Fixed vScale, Fixed xOffset,
             Fixed yOffset) THREEWORDINLINE(0x303C, 0x01D1, 0xA832);

/**
 *  GXSkewShape()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSkewShape(gxShape target, Fixed xSkew, Fixed ySkew, Fixed xOffset,
            Fixed yOffset) THREEWORDINLINE(0x303C, 0x01D2, 0xA832);

/**
 *  GXUnionShape()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXUnionShape(gxShape target, gxShape operand)
    THREEWORDINLINE(0x303C, 0x01D3, 0xA832);

/**
 *  GXDifferenceTransform()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXDifferenceTransform(gxTransform target, gxShape operand)
    THREEWORDINLINE(0x303C, 0x01D4, 0xA832);

/**
 *  GXExcludeTransform()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXExcludeTransform(gxTransform target, gxShape operand)
    THREEWORDINLINE(0x303C, 0x01D5, 0xA832);

/**
 *  GXIntersectTransform()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXIntersectTransform(gxTransform target, gxShape operand)
    THREEWORDINLINE(0x303C, 0x01D6, 0xA832);

/**
 *  GXMapTransform()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXMapTransform(gxTransform target, const gxMapping *map)
    THREEWORDINLINE(0x303C, 0x01D7, 0xA832);

/**
 *  GXMoveTransform()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXMoveTransform(gxTransform target, Fixed deltaX, Fixed deltaY)
    THREEWORDINLINE(0x303C, 0x01D8, 0xA832);

/**
 *  GXMoveTransformTo()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXMoveTransformTo(gxTransform target, Fixed x, Fixed y)
    THREEWORDINLINE(0x303C, 0x01D9, 0xA832);

/**
 *  GXReverseDifferenceTransform()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXReverseDifferenceTransform(gxTransform target, gxShape operand)
    THREEWORDINLINE(0x303C, 0x01DA, 0xA832);

/**
 *  GXRotateTransform()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXRotateTransform(gxTransform target, Fixed degrees, Fixed xOffset,
                  Fixed yOffset) THREEWORDINLINE(0x303C, 0x01DB, 0xA832);

/**
 *  GXScaleTransform()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXScaleTransform(gxTransform target, Fixed hScale, Fixed vScale, Fixed xOffset,
                 Fixed yOffset) THREEWORDINLINE(0x303C, 0x01DC, 0xA832);

/**
 *  GXSkewTransform()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSkewTransform(gxTransform target, Fixed xSkew, Fixed ySkew, Fixed xOffset,
                Fixed yOffset) THREEWORDINLINE(0x303C, 0x01DD, 0xA832);

/**
 *  GXUnionTransform()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXUnionTransform(gxTransform target, gxShape operand)
    THREEWORDINLINE(0x303C, 0x01DE, 0xA832);

/**
 *  GXBreakShape()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXBreakShape(gxShape target, long index)
    THREEWORDINLINE(0x303C, 0x01DF, 0xA832);

/**
 *  GXChangedShape()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXChangedShape(gxShape target) THREEWORDINLINE(0x303C, 0x01E0, 0xA832);

/**
 *  GXHitTestShape()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxShapePart
GXHitTestShape(gxShape target, const gxPoint *test, gxHitTestInfo *result)
    THREEWORDINLINE(0x303C, 0x01E1, 0xA832);

/**
 *  GXHitTestDevice()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxShape
GXHitTestDevice(gxShape target, gxViewPort port, gxViewDevice device,
                const gxPoint *test, const gxPoint *tolerance)
    THREEWORDINLINE(0x303C, 0x01E2, 0xA832);

/**
 *  GXInsetShape()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXInsetShape(gxShape target, Fixed inset)
    THREEWORDINLINE(0x303C, 0x01E3, 0xA832);

/**
 *  GXInvertShape()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXInvertShape(gxShape target) THREEWORDINLINE(0x303C, 0x01E4, 0xA832);

/**
 *  GXPrimitiveShape()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXPrimitiveShape(gxShape target) THREEWORDINLINE(0x303C, 0x01E5, 0xA832);

/**
 *  GXReduceShape()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXReduceShape(gxShape target, long contour)
    THREEWORDINLINE(0x303C, 0x01E6, 0xA832);

/**
 *  GXReverseShape()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXReverseShape(gxShape target, long contour)
    THREEWORDINLINE(0x303C, 0x01E7, 0xA832);

/**
 *  GXSimplifyShape()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXSimplifyShape(gxShape target) THREEWORDINLINE(0x303C, 0x01E8, 0xA832);

/**
 *  GXLockColorProfile()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXLockColorProfile(gxColorProfile source)
    THREEWORDINLINE(0x303C, 0x01E9, 0xA832);

/**
 *  GXUnlockColorProfile()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXUnlockColorProfile(gxColorProfile source)
    THREEWORDINLINE(0x303C, 0x01EA, 0xA832);

/**
 *  GXGetColorProfileStructure()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void *
GXGetColorProfileStructure(gxColorProfile source, long *length)
    THREEWORDINLINE(0x303C, 0x01EB, 0xA832);

/**
 *  GXFlattenShape()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXFlattenShape(gxShape source, gxFlattenFlag flags, gxSpoolBlock *block)
    THREEWORDINLINE(0x303C, 0x01EC, 0xA832);

/**
 *  GXUnflattenShape()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxShape
GXUnflattenShape(gxSpoolBlock *block, long count, const gxViewPort portList[])
    THREEWORDINLINE(0x303C, 0x01ED, 0xA832);

/**
 *  GXPostGraphicsNotice()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXPostGraphicsNotice(gxGraphicsNotice notice)
    THREEWORDINLINE(0x303C, 0x0065, 0xA832);

/**
 *  GXIgnoreGraphicsNotice()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXIgnoreGraphicsNotice(gxGraphicsNotice notice)
    THREEWORDINLINE(0x303C, 0x006D, 0xA832);

/**
 *  GXPopGraphicsNotice()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GXPopGraphicsNotice(void) THREEWORDINLINE(0x303C, 0x006E, 0xA832);

#endif // CALL_NOT_IN_CARBON 
#if defined(__MWERKS__) && TARGET_CPU_68K
#pragma pop
#endif

#if PRAGMA_STRUCT_ALIGN
#pragma options align = reset
#elif PRAGMA_STRUCT_PACKPUSH
#pragma pack(pop)
#elif PRAGMA_STRUCT_PACK
#pragma pack()
#endif// CALL_NOT_IN_CARBON 

#ifdef PRAGMA_IMPORT_OFF
#pragma import off
#elif PRAGMA_IMPORT
#pragma import reset
#endif

#ifdef __cplusplus
}
#endif

#endif // __GXGRAPHICS__ // __GXGRAPHICS__ 
