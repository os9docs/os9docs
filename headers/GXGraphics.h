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
extern "C"
{
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
                        gxClientAttribute attributes);

    /**
     *  GXGetGraphicsClient()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxGraphicsClient
    GXGetGraphicsClient(void);

    /**
     *  GXSetGraphicsClient()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetGraphicsClient(gxGraphicsClient client);

    /**
     *  GXDisposeGraphicsClient()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXDisposeGraphicsClient(gxGraphicsClient client);

#endif // CALL_NOT_IN_CARBON
// returns the count
#if CALL_NOT_IN_CARBON
    /**
     *  GXGetGraphicsClients()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    long
    GXGetGraphicsClients(long index, long count, gxGraphicsClient clients[]);

    /**
     *  GXEnterGraphics()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXEnterGraphics(void);

    /**
     *  GXExitGraphics()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXExitGraphics(void);

    /**
     *  GXGetGraphicsError()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxGraphicsError
    GXGetGraphicsError(gxGraphicsError *stickyError);

    /**
     *  GXGetGraphicsNotice()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxGraphicsNotice
    GXGetGraphicsNotice(gxGraphicsNotice *stickyNotice);

    /**
     *  GXGetGraphicsWarning()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxGraphicsWarning
    GXGetGraphicsWarning(gxGraphicsWarning *stickyWarning);

    /**
     *  GXPostGraphicsError()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXPostGraphicsError(gxGraphicsError error);

    /**
     *  GXPostGraphicsWarning()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXPostGraphicsWarning(gxGraphicsWarning warning);

    /**
     *  GXGetUserGraphicsError()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxUserErrorUPP
    GXGetUserGraphicsError(long *reference);

    /**
     *  GXGetUserGraphicsNotice()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxUserNoticeUPP
    GXGetUserGraphicsNotice(long *reference);

    /**
     *  GXGetUserGraphicsWarning()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxUserWarningUPP
    GXGetUserGraphicsWarning(long *reference);

    /**
     *  GXSetUserGraphicsError()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetUserGraphicsError(gxUserErrorUPP userFunction, long reference);

    /**
     *  GXSetUserGraphicsNotice()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetUserGraphicsNotice(gxUserNoticeUPP userFunction, long reference);

    /**
     *  GXSetUserGraphicsWarning()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetUserGraphicsWarning(gxUserWarningUPP userFunction, long reference);

    /**
     *  GXIgnoreGraphicsWarning()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXIgnoreGraphicsWarning(gxGraphicsWarning warning);

    /**
     *  GXPopGraphicsWarning()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXPopGraphicsWarning(void);

    /**
     *  GXNewShapeVector()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxShape
    GXNewShapeVector(gxShapeType aType, const Fixed vector[]);

    /**
     *  GXSetShapeVector()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetShapeVector(gxShape target, const Fixed vector[]);

    /**
     *  GXNewBitmap()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxShape
    GXNewBitmap(const gxBitmap *data, const gxPoint *position);

    /**
     *  GXNewCurve()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxShape
    GXNewCurve(const gxCurve *data);

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
                const gxStyle glyphStyles[]);

    /**
     *  GXNewLine()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxShape
    GXNewLine(const gxLine *data);

    /**
     *  GXNewPaths()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxShape
    GXNewPaths(const gxPaths *data);

    /**
     *  GXNewPicture()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxShape
    GXNewPicture(long count, const gxShape shapes[], const gxStyle styles[],
                 const gxInk inks[], const gxTransform transforms[]);

    /**
     *  GXNewPoint()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxShape
    GXNewPoint(const gxPoint *data);

    /**
     *  GXNewPolygons()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxShape
    GXNewPolygons(const gxPolygons *data);

    /**
     *  GXNewRectangle()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxShape
    GXNewRectangle(const gxRectangle *data);

    /**
     *  GXNewText()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxShape
    GXNewText(long charCount, const unsigned char text[], const gxPoint *position);

    /**
     *  GXGetBitmap()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxBitmap *
    GXGetBitmap(gxShape source, gxBitmap *data, gxPoint *position);

    /**
     *  GXGetCurve()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxCurve *
    GXGetCurve(gxShape source, gxCurve *data);

    // returns byte length of glyphs
    /**
       // returns byte length of glyphs
       *

           *    \non_carbon_cfm not available *    \carbon_lib not available *    \mac_os_x not available *
           /
           long
           GXGetGlyphs(gxShape source, long *charCount, unsigned char text[],
                       gxPoint positions[], long advance[], gxPoint tangents[],
                       long *runCount, short styleRuns[], gxStyle glyphStyles[]);

       /**
        *  GXGetLine()
        *

        *    \non_carbon_cfm   not available
        *    \carbon_lib        not available
        *    \mac_os_x         not available
        */
    gxLine *
    GXGetLine(gxShape source, gxLine *data);

    // returns byte length
    /**
       *GXGetPaths()
           // returns byte length

           *    \non_carbon_cfm not available
           *    \carbon_lib not available
           *    \mac_os_x not available
*/
    long GXGetPaths(gxShape source, gxPaths *data);

    // returns count
    /**
       *GXGetPicture() *
           // returns count
           *    \non_carbon_cfm not available
           *    \carbon_lib not available
           *    \mac_os_x not available
*/
    long GXGetPicture(gxShape source, gxShape shapes[], gxStyle styles[], gxInk inks[],
                      gxTransform transforms[]);

    /**
     *  GXGetPoint()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxPoint *
    GXGetPoint(gxShape source, gxPoint *data);

    // returns byte length
    /**
       *GXGetPolygons() *

           // returns byte length
           *    \carbon_lib not available
           *    \mac_os_x not available
*/
    long GXGetPolygons(gxShape source, gxPolygons *data);

    /**
     *  GXGetRectangle()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxRectangle *
    GXGetRectangle(gxShape source, gxRectangle *data);

    // returns byte length
    /**
       *GXGetText() *

           *    \non_carbon_cfm not available
           // returns byte length
           *    \mac_os_x not available
*/
    long GXGetText(gxShape source, long *charCount, unsigned char text[],
                   gxPoint *position);

    /**
     *  GXSetBitmap()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetBitmap(gxShape target, const gxBitmap *data, const gxPoint *position);

    /**
     *  GXSetCurve()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetCurve(gxShape target, const gxCurve *data);

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
                const gxStyle glyphStyles[]);

    /**
     *  GXSetLine()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetLine(gxShape target, const gxLine *data);

    /**
     *  GXSetPaths()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetPaths(gxShape target, const gxPaths *data);

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
                 const gxTransform transforms[]);

    /**
     *  GXSetPoint()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetPoint(gxShape target, const gxPoint *data);

    /**
     *  GXSetPolygons()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetPolygons(gxShape target, const gxPolygons *data);

    /**
     *  GXSetRectangle()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetRectangle(gxShape target, const gxRectangle *data);

    /**
     *  GXSetText()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetText(gxShape target, long charCount, const unsigned char text[],
              const gxPoint *position);

    /**
     *  GXDrawBitmap()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXDrawBitmap(const gxBitmap *data, const gxPoint *position);

    /**
     *  GXDrawCurve()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXDrawCurve(const gxCurve *data);

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
                 const gxStyle glyphStyles[]);

    /**
     *  GXDrawLine()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXDrawLine(const gxLine *data);

    /**
     *  GXDrawPaths()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXDrawPaths(const gxPaths *data, gxShapeFill fill);

    /**
     *  GXDrawPicture()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXDrawPicture(long count, const gxShape shapes[], const gxStyle styles[],
                  const gxInk inks[], const gxTransform transforms[]);

    /**
     *  GXDrawPoint()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXDrawPoint(const gxPoint *data);

    /**
     *  GXDrawPolygons()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXDrawPolygons(const gxPolygons *data, gxShapeFill fill);

    /**
     *  GXDrawRectangle()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXDrawRectangle(const gxRectangle *data, gxShapeFill fill);

    /**
     *  GXDrawText()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXDrawText(long charCount, const unsigned char text[], const gxPoint *position);

    /**
     *  GXNewColorProfile()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxColorProfile
    GXNewColorProfile(long size, void *colorProfileData);

    /**
     *  GXNewColorSet()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxColorSet
    GXNewColorSet(gxColorSpace space, long count, const gxSetColor colors[]);

    /**
     *  GXNewInk()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxInk
    GXNewInk(void);

    /**
     *  GXNewShape()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxShape
    GXNewShape(gxShapeType aType);

    /**
     *  GXNewStyle()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxStyle
    GXNewStyle(void);

    /**
     *  GXNewTag()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxTag
    GXNewTag(long tagType, long length, const void *data);

    /**
     *  GXNewTransform()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxTransform
    GXNewTransform(void);

    /**
     *  GXNewViewDevice()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxViewDevice
    GXNewViewDevice(gxViewGroup group, gxShape bitmapShape);

    /**
     *  GXNewViewGroup()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxViewGroup
    GXNewViewGroup(void);

    /**
     *  GXNewViewPort()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxViewPort
    GXNewViewPort(gxViewGroup group);

    /**
     *  GXDisposeColorProfile()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXDisposeColorProfile(gxColorProfile target);

    /**
     *  GXDisposeColorSet()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXDisposeColorSet(gxColorSet target);

    /**
     *  GXDisposeInk()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXDisposeInk(gxInk target);

    /**
     *  GXDisposeShape()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXDisposeShape(gxShape target);

    /**
     *  GXDisposeStyle()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXDisposeStyle(gxStyle target);

    /**
     *  GXDisposeTag()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXDisposeTag(gxTag target);

    /**
     *  GXDisposeTransform()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXDisposeTransform(gxTransform target);

    /**
     *  GXDisposeViewDevice()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXDisposeViewDevice(gxViewDevice target);

    /**
     *  GXDisposeViewGroup()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXDisposeViewGroup(gxViewGroup target);

    /**
     *  GXDisposeViewPort()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXDisposeViewPort(gxViewPort target);

    /**
     *  GXCloneColorProfile()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxColorProfile
    GXCloneColorProfile(gxColorProfile source);

    /**
     *  GXCloneColorSet()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxColorSet
    GXCloneColorSet(gxColorSet source);

    /**
     *  GXCloneInk()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxInk
    GXCloneInk(gxInk source);

    /**
     *  GXCloneShape()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxShape
    GXCloneShape(gxShape source);

    /**
     *  GXCloneStyle()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxStyle
    GXCloneStyle(gxStyle source);

    /**
     *  GXCloneTag()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxTag
    GXCloneTag(gxTag source);

    /**
     *  GXCloneTransform()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxTransform
    GXCloneTransform(gxTransform source);

    /**
     *  GXCopyToColorProfile()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxColorProfile
    GXCopyToColorProfile(gxColorProfile target, gxColorProfile source);

    /**
     *  GXCopyToColorSet()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxColorSet
    GXCopyToColorSet(gxColorSet target, gxColorSet source);

    /**
     *  GXCopyToInk()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxInk
    GXCopyToInk(gxInk target, gxInk source);

    /**
     *  GXCopyToShape()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxShape
    GXCopyToShape(gxShape target, gxShape source);

    /**
     *  GXCopyToStyle()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxStyle
    GXCopyToStyle(gxStyle target, gxStyle source);

    /**
     *  GXCopyToTag()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxTag
    GXCopyToTag(gxTag target, gxTag source);

    /**
     *  GXCopyToTransform()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxTransform
    GXCopyToTransform(gxTransform target, gxTransform source);

    /**
     *  GXCopyToViewDevice()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxViewDevice
    GXCopyToViewDevice(gxViewDevice target, gxViewDevice source);

    /**
     *  GXCopyToViewPort()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxViewPort
    GXCopyToViewPort(gxViewPort target, gxViewPort source);

    /**
     *  GXEqualColorProfile()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    Boolean
    GXEqualColorProfile(gxColorProfile one, gxColorProfile two);

    /**
     *  GXEqualColorSet()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    Boolean
    GXEqualColorSet(gxColorSet one, gxColorSet two);

    /**
     *  GXEqualInk()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    Boolean
    GXEqualInk(gxInk one, gxInk two);

    /**
     *  GXEqualShape()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    Boolean
    GXEqualShape(gxShape one, gxShape two);

    /**
     *  GXEqualStyle()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    Boolean
    GXEqualStyle(gxStyle one, gxStyle two);

    /**
     *  GXEqualTag()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    Boolean
    GXEqualTag(gxTag one, gxTag two);

    /**
     *  GXEqualTransform()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    Boolean
    GXEqualTransform(gxTransform one, gxTransform two);

    /**
     *  GXEqualViewDevice()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    Boolean
    GXEqualViewDevice(gxViewDevice one, gxViewDevice two);

    /**
     *  GXEqualViewPort()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    Boolean
    GXEqualViewPort(gxViewPort one, gxViewPort two);

    /**
     *  GXResetInk()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXResetInk(gxInk target);

    /**
     *  GXResetShape()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXResetShape(gxShape target);

    /**
     *  GXResetStyle()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXResetStyle(gxStyle target);

    /**
     *  GXResetTransform()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXResetTransform(gxTransform target);

    /**
     *  GXLoadColorProfile()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXLoadColorProfile(gxColorProfile target);

    /**
     *  GXLoadColorSet()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXLoadColorSet(gxColorSet target);

    /**
     *  GXLoadInk()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXLoadInk(gxInk target);

    /**
     *  GXLoadShape()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXLoadShape(gxShape target);

    /**
     *  GXLoadStyle()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXLoadStyle(gxStyle target);

    /**
     *  GXLoadTag()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXLoadTag(gxTag target);

    /**
     *  GXLoadTransform()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXLoadTransform(gxTransform target);

    /**
     *  GXUnloadColorProfile()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXUnloadColorProfile(gxColorProfile target);

    /**
     *  GXUnloadColorSet()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXUnloadColorSet(gxColorSet target);

    /**
     *  GXUnloadInk()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXUnloadInk(gxInk target);

    /**
     *  GXUnloadShape()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXUnloadShape(gxShape target);

    /**
     *  GXUnloadStyle()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXUnloadStyle(gxStyle target);

    /**
     *  GXUnloadTag()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXUnloadTag(gxTag target);

    /**
     *  GXUnloadTransform()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXUnloadTransform(gxTransform target);

    /**
     *  GXCacheShape()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXCacheShape(gxShape source);

    /**
     *  GXCopyDeepToShape()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxShape
    GXCopyDeepToShape(gxShape target, gxShape source);

    /**
     *  GXDrawShape()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXDrawShape(gxShape source);

    /**
     *  GXDisposeShapeCache()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXDisposeShapeCache(gxShape target);

    /**
     *  GXGetDefaultColorProfile()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxColorProfile
    GXGetDefaultColorProfile(void);

    /**
     *  GXGetDefaultShape()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxShape
    GXGetDefaultShape(gxShapeType aType);

    /**
     *  GXGetDefaultColorSet()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxColorSet
    GXGetDefaultColorSet(long pixelDepth);

    /**
     *  GXSetDefaultShape()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetDefaultShape(gxShape target);

    /**
     *  GXSetDefaultColorSet()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetDefaultColorSet(gxColorSet target, long pixelDepth);

    /**
     *  GXGetTag()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    long
    GXGetTag(gxTag source, long *tagType, void *data);

    /**
     *  GXSetTag()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetTag(gxTag target, long tagType, long length, const void *data);

    /**
     *  GXGetShapeBounds()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxRectangle *
    GXGetShapeBounds(gxShape source, long index, gxRectangle *bounds);

    /**
     *  GXGetShapeFill()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxShapeFill
    GXGetShapeFill(gxShape source);

    /**
     *  GXGetShapeInk()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxInk
    GXGetShapeInk(gxShape source);

    /**
     *  GXGetShapePixel()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    long
    GXGetShapePixel(gxShape source, long x, long y, gxColor *data, long *index);

    /**
     *  GXGetShapeStyle()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxStyle
    GXGetShapeStyle(gxShape source);

    /**
     *  GXGetShapeTransform()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxTransform
    GXGetShapeTransform(gxShape source);

    /**
     *  GXGetShapeType()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxShapeType
    GXGetShapeType(gxShape source);

    /**
     *  GXGetShapeTypographicBounds()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxRectangle *
    GXGetShapeTypographicBounds(gxShape source, gxRectangle *bounds);

    /**
     *  GXGetBitmapParts()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxShape
    GXGetBitmapParts(gxShape source, const gxLongRectangle *bounds);

    /**
     *  GXGetStyleFontMetrics()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXGetStyleFontMetrics(gxStyle sourceStyle, gxPoint *before, gxPoint *after,
                          gxPoint *caretAngle, gxPoint *caretOffset);

    /**
     *  GXGetShapeFontMetrics()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXGetShapeFontMetrics(gxShape source, gxPoint *before, gxPoint *after,
                          gxPoint *caretAngle, gxPoint *caretOffset);

    /**
     *  GXSetShapeBounds()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetShapeBounds(gxShape target, const gxRectangle *newBounds);

    /**
     *  GXSetShapeFill()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetShapeFill(gxShape target, gxShapeFill newFill);

    /**
     *  GXSetShapeInk()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetShapeInk(gxShape target, gxInk newInk);

    /**
     *  GXSetShapePixel()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetShapePixel(gxShape target, long x, long y, const gxColor *newColor,
                    long newIndex);

    /**
     *  GXSetShapeStyle()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetShapeStyle(gxShape target, gxStyle newStyle);

    /**
     *  GXSetShapeTransform()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetShapeTransform(gxShape target, gxTransform newTransform);

    /**
     *  GXSetShapeType()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetShapeType(gxShape target, gxShapeType newType);

    /**
     *  GXSetBitmapParts()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetBitmapParts(gxShape target, const gxLongRectangle *bounds,
                     gxShape bitmapShape);

    /**
     *  GXSetShapeGeometry()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetShapeGeometry(gxShape target, gxShape geometry);

    /**
     *  GXGetShapeCurveError()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    Fixed
    GXGetShapeCurveError(gxShape source);

    /**
     *  GXGetShapeDash()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxDashRecord *
    GXGetShapeDash(gxShape source, gxDashRecord *dash);

    /**
     *  GXGetShapeCap()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxCapRecord *
    GXGetShapeCap(gxShape source, gxCapRecord *cap);

    // returns the number of layers
    /**
       *GXGetShapeFace() *

           *    \non_carbon_cfm not available
           *    \carbon_lib not available
           // returns the number of layers
*/
    long GXGetShapeFace(gxShape source, gxTextFace *face);

    /**
     *  GXGetShapeFont()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxFont
    GXGetShapeFont(gxShape source);

    /**
     *  GXGetShapeJoin()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxJoinRecord *
    GXGetShapeJoin(gxShape source, gxJoinRecord *join);

    /**
     *  GXGetShapeJustification()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    Fract
    GXGetShapeJustification(gxShape source);

    /**
     *  GXGetShapePattern()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxPatternRecord *
    GXGetShapePattern(gxShape source, gxPatternRecord *pattern);

    /**
     *  GXGetShapePen()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    Fixed
    GXGetShapePen(gxShape source);

    /**
     *  GXGetShapeEncoding()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxFontPlatform
    GXGetShapeEncoding(gxShape source, gxFontScript *script,
                       gxFontLanguage *language);

    /**
     *  GXGetShapeTextSize()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    Fixed
    GXGetShapeTextSize(gxShape source);

    /**
     *  GXGetShapeFontVariations()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    long
    GXGetShapeFontVariations(gxShape source, gxFontVariation variations[]);

    /**
     *  GXGetShapeFontVariationSuite()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    long
    GXGetShapeFontVariationSuite(gxShape source, gxFontVariation variations[]);

    /**
     *  GXGetStyleCurveError()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    Fixed
    GXGetStyleCurveError(gxStyle source);

    /**
     *  GXGetStyleDash()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxDashRecord *
    GXGetStyleDash(gxStyle source, gxDashRecord *dash);

    /**
     *  GXGetStyleCap()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxCapRecord *
    GXGetStyleCap(gxStyle source, gxCapRecord *cap);

    // returns the number of layers
    /**
       *GXGetStyleFace() *

           *    \non_carbon_cfm not available
           *    \carbon_lib not available
           *    \mac_os_x not available
           // returns the number of layers
           long GXGetStyleFace(gxStyle source, gxTextFace *face);

       /**
        *  GXGetStyleFont()
        *

        *    \non_carbon_cfm   not available
        *    \carbon_lib        not available
        *    \mac_os_x         not available
        */
    gxFont
    GXGetStyleFont(gxStyle source);

    /**
     *  GXGetStyleJoin()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxJoinRecord *
    GXGetStyleJoin(gxStyle source, gxJoinRecord *join);

    /**
     *  GXGetStyleJustification()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    Fract
    GXGetStyleJustification(gxStyle source);

    /**
     *  GXGetStylePattern()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxPatternRecord *
    GXGetStylePattern(gxStyle source, gxPatternRecord *pattern);

    /**
     *  GXGetStylePen()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    Fixed
    GXGetStylePen(gxStyle source);

    /**
     *  GXGetStyleEncoding()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxFontPlatform
    GXGetStyleEncoding(gxStyle source, gxFontScript *script,
                       gxFontLanguage *language);

    /**
     *  GXGetStyleTextSize()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    Fixed
    GXGetStyleTextSize(gxStyle source);

    /**
     *  GXGetStyleFontVariations()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    long
    GXGetStyleFontVariations(gxStyle source, gxFontVariation variations[]);

    /**
     *  GXGetStyleFontVariationSuite()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    long
    GXGetStyleFontVariationSuite(gxStyle source, gxFontVariation variations[]);

    /**
     *  GXSetShapeCurveError()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetShapeCurveError(gxShape target, Fixed error);

    /**
     *  GXSetShapeDash()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetShapeDash(gxShape target, const gxDashRecord *dash);

    /**
     *  GXSetShapeCap()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetShapeCap(gxShape target, const gxCapRecord *cap);

    /**
     *  GXSetShapeFace()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetShapeFace(gxShape target, const gxTextFace *face);

    /**
     *  GXSetShapeFont()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetShapeFont(gxShape target, gxFont aFont);

    /**
     *  GXSetShapeJoin()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetShapeJoin(gxShape target, const gxJoinRecord *join);

    /**
     *  GXSetShapeJustification()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetShapeJustification(gxShape target, Fract justify);

    /**
     *  GXSetShapePattern()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetShapePattern(gxShape target, const gxPatternRecord *pattern);

    /**
     *  GXSetShapePen()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetShapePen(gxShape target, Fixed pen);

    /**
     *  GXSetShapeEncoding()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetShapeEncoding(gxShape target, gxFontPlatform platform, gxFontScript script,
                       gxFontLanguage language);

    /**
     *  GXSetShapeTextSize()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetShapeTextSize(gxShape target, Fixed size);

    /**
     *  GXSetShapeFontVariations()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetShapeFontVariations(gxShape target, long count,
                             const gxFontVariation variations[]);

    /**
     *  GXSetStyleCurveError()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetStyleCurveError(gxStyle target, Fixed error);

    /**
     *  GXSetStyleDash()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetStyleDash(gxStyle target, const gxDashRecord *dash);

    /**
     *  GXSetStyleCap()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetStyleCap(gxStyle target, const gxCapRecord *cap);

    /**
     *  GXSetStyleFace()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetStyleFace(gxStyle target, const gxTextFace *face);

    /**
     *  GXSetStyleFont()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetStyleFont(gxStyle target, gxFont aFont);

    /**
     *  GXSetStyleJoin()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetStyleJoin(gxStyle target, const gxJoinRecord *join);

    /**
     *  GXSetStyleJustification()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetStyleJustification(gxStyle target, Fract justify);

    /**
     *  GXSetStylePattern()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetStylePattern(gxStyle target, const gxPatternRecord *pattern);

    /**
     *  GXSetStylePen()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetStylePen(gxStyle target, Fixed pen);

    /**
     *  GXSetStyleEncoding()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetStyleEncoding(gxStyle target, gxFontPlatform platform, gxFontScript script,
                       gxFontLanguage language);

    /**
     *  GXSetStyleTextSize()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetStyleTextSize(gxStyle target, Fixed size);

    /**
     *  GXSetStyleFontVariations()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetStyleFontVariations(gxStyle target, long count,
                             const gxFontVariation variations[]);

    /**
     *  GXGetShapeColor()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxColor *
    GXGetShapeColor(gxShape source, gxColor *data);

    /**
     *  GXGetShapeTransfer()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxTransferMode *
    GXGetShapeTransfer(gxShape source, gxTransferMode *data);

    /**
     *  GXGetInkColor()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxColor *
    GXGetInkColor(gxInk source, gxColor *data);

    /**
     *  GXGetInkTransfer()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxTransferMode *
    GXGetInkTransfer(gxInk source, gxTransferMode *data);

    /**
     *  GXSetShapeColor()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetShapeColor(gxShape target, const gxColor *data);

    /**
     *  GXSetShapeTransfer()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetShapeTransfer(gxShape target, const gxTransferMode *data);

    /**
     *  GXSetInkColor()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetInkColor(gxInk target, const gxColor *data);

    /**
     *  GXSetInkTransfer()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetInkTransfer(gxInk target, const gxTransferMode *data);

    /**
     *  GXGetShapeClip()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxShape
    GXGetShapeClip(gxShape source);

    /**
     *  GXGetShapeClipType()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxShapeType
    GXGetShapeClipType(gxShape source);

    /**
     *  GXGetShapeMapping()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxMapping *
    GXGetShapeMapping(gxShape source, gxMapping *map);

    /**
     *  GXGetShapeHitTest()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxShapePart
    GXGetShapeHitTest(gxShape source, Fixed *tolerance);

    /**
     *  GXGetShapeViewPorts()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    long
    GXGetShapeViewPorts(gxShape source, gxViewPort list[]);

    /**
     *  GXGetTransformClip()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxShape
    GXGetTransformClip(gxTransform source);

    /**
     *  GXGetTransformClipType()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxShapeType
    GXGetTransformClipType(gxTransform source);

    /**
     *  GXGetTransformMapping()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxMapping *
    GXGetTransformMapping(gxTransform source, gxMapping *map);

    /**
     *  GXGetTransformHitTest()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxShapePart
    GXGetTransformHitTest(gxTransform source, Fixed *tolerance);

    /**
     *  GXGetTransformViewPorts()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    long
    GXGetTransformViewPorts(gxTransform source, gxViewPort list[]);

    /**
     *  GXSetShapeClip()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetShapeClip(gxShape target, gxShape clip);

    /**
     *  GXSetShapeMapping()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetShapeMapping(gxShape target, const gxMapping *map);

    /**
     *  GXSetShapeHitTest()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetShapeHitTest(gxShape target, gxShapePart mask, Fixed tolerance);

    /**
     *  GXSetShapeViewPorts()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetShapeViewPorts(gxShape target, long count, const gxViewPort list[]);

    /**
     *  GXSetTransformClip()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetTransformClip(gxTransform target, gxShape clip);

    /**
     *  GXSetTransformMapping()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetTransformMapping(gxTransform target, const gxMapping *map);

    /**
     *  GXSetTransformHitTest()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetTransformHitTest(gxTransform target, gxShapePart mask, Fixed tolerance);

    /**
     *  GXSetTransformViewPorts()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetTransformViewPorts(gxTransform target, long count, const gxViewPort list[]);

    /**
     *  GXGetColorSet()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    long
    GXGetColorSet(gxColorSet source, gxColorSpace *space, gxSetColor colors[]);

    /**
     *  GXGetColorProfile()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    long
    GXGetColorProfile(gxColorProfile source, void *colorProfileData);

    /**
     *  GXSetColorSet()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetColorSet(gxColorSet target, gxColorSpace space, long count,
                  const gxSetColor colors[]);

    /**
     *  GXSetColorProfile()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetColorProfile(gxColorProfile target, long size, void *colorProfileData);

    /**
     *  GXGetViewDeviceBitmap()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxShape
    GXGetViewDeviceBitmap(gxViewDevice source);

    /**
     *  GXGetViewDeviceClip()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxShape
    GXGetViewDeviceClip(gxViewDevice source);

    /**
     *  GXGetViewDeviceMapping()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxMapping *
    GXGetViewDeviceMapping(gxViewDevice source, gxMapping *map);

    /**
     *  GXGetViewDeviceViewGroup()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxViewGroup
    GXGetViewDeviceViewGroup(gxViewDevice source);

    /**
     *  GXSetViewDeviceBitmap()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetViewDeviceBitmap(gxViewDevice target, gxShape bitmapShape);

    /**
     *  GXSetViewDeviceClip()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetViewDeviceClip(gxViewDevice target, gxShape clip);

    /**
     *  GXSetViewDeviceMapping()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetViewDeviceMapping(gxViewDevice target, const gxMapping *map);

    /**
     *  GXSetViewDeviceViewGroup()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetViewDeviceViewGroup(gxViewDevice target, gxViewGroup group);

    /**
     *  GXGetViewPortChildren()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    long
    GXGetViewPortChildren(gxViewPort source, gxViewPort list[]);

    /**
     *  GXGetViewPortClip()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxShape
    GXGetViewPortClip(gxViewPort source);

    /**
     *  GXGetViewPortDither()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    long
    GXGetViewPortDither(gxViewPort source);

    /**
     *  GXGetViewPortHalftone()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    Boolean
    GXGetViewPortHalftone(gxViewPort source, gxHalftone *data);

    /**
     *  GXGetViewPortMapping()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxMapping *
    GXGetViewPortMapping(gxViewPort source, gxMapping *map);

    /**
     *  GXGetViewPortParent()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxViewPort
    GXGetViewPortParent(gxViewPort source);

    /**
     *  GXGetViewPortViewGroup()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxViewGroup
    GXGetViewPortViewGroup(gxViewPort source);

    /**
     *  GXGetViewPortHalftoneMatrix()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    long
    GXGetViewPortHalftoneMatrix(gxViewPort source, gxViewDevice sourceDevice,
                                gxHalftoneMatrix *theMatrix);

    /**
     *  GXSetViewPortChildren()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetViewPortChildren(gxViewPort target, long count, const gxViewPort list[]);

    /**
     *  GXSetViewPortClip()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetViewPortClip(gxViewPort target, gxShape clip);

    /**
     *  GXSetViewPortDither()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetViewPortDither(gxViewPort target, long level);

    /**
     *  GXSetViewPortHalftone()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetViewPortHalftone(gxViewPort target, const gxHalftone *data);

    /**
     *  GXSetViewPortMapping()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetViewPortMapping(gxViewPort target, const gxMapping *map);

    /**
     *  GXSetViewPortParent()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetViewPortParent(gxViewPort target, gxViewPort parent);

    /**
     *  GXSetViewPortViewGroup()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetViewPortViewGroup(gxViewPort target, gxViewGroup group);

    /**
     *  GXGetColorProfileTags()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    long
    GXGetColorProfileTags(gxColorProfile source, long tagType, long index,
                          long count, gxTag items[]);

    /**
     *  GXGetColorSetTags()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    long
    GXGetColorSetTags(gxColorSet source, long tagType, long index, long count,
                      gxTag items[]);

    /**
     *  GXGetInkTags()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    long
    GXGetInkTags(gxInk source, long tagType, long index, long count, gxTag items[]);

    /**
     *  GXGetShapeTags()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    long
    GXGetShapeTags(gxShape source, long tagType, long index, long count,
                   gxTag items[]);

    /**
     *  GXGetStyleTags()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    long
    GXGetStyleTags(gxStyle source, long tagType, long index, long count,
                   gxTag items[]);

    /**
     *  GXGetTransformTags()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    long
    GXGetTransformTags(gxTransform source, long tagType, long index, long count,
                       gxTag items[]);

    /**
     *  GXGetViewDeviceTags()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    long
    GXGetViewDeviceTags(gxViewDevice source, long tagType, long index, long count,
                        gxTag items[]);

    /**
     *  GXGetViewPortTags()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    long
    GXGetViewPortTags(gxViewPort source, long tagType, long index, long count,
                      gxTag items[]);

    /**
     *  GXSetColorProfileTags()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetColorProfileTags(gxColorProfile target, long tagType, long index,
                          long oldCount, long newCount, const gxTag items[]);

    /**
     *  GXSetColorSetTags()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetColorSetTags(gxColorSet target, long tagType, long index, long oldCount,
                      long newCount, const gxTag items[]);

    /**
     *  GXSetInkTags()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetInkTags(gxInk target, long tagType, long index, long oldCount,
                 long newCount, const gxTag items[]);

    /**
     *  GXSetShapeTags()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetShapeTags(gxShape target, long tagType, long index, long oldCount,
                   long newCount, const gxTag items[]);

    /**
     *  GXSetStyleTags()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetStyleTags(gxStyle target, long tagType, long index, long oldCount,
                   long newCount, const gxTag items[]);

    /**
     *  GXSetTransformTags()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetTransformTags(gxTransform target, long tagType, long index, long oldCount,
                       long newCount, const gxTag items[]);

    /**
     *  GXSetViewDeviceTags()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetViewDeviceTags(gxViewDevice target, long tagType, long index,
                        long oldCount, long newCount, const gxTag items[]);

    /**
     *  GXSetViewPortTags()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetViewPortTags(gxViewPort target, long tagType, long index, long oldCount,
                      long newCount, const gxTag items[]);

    /**
     *  GXGetInkAttributes()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxInkAttribute
    GXGetInkAttributes(gxInk source);

    /**
     *  GXGetShapeAttributes()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxShapeAttribute
    GXGetShapeAttributes(gxShape source);

    /**
     *  GXGetShapeInkAttributes()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxInkAttribute
    GXGetShapeInkAttributes(gxShape source);

    /**
     *  GXGetShapeStyleAttributes()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxStyleAttribute
    GXGetShapeStyleAttributes(gxShape source);

    /**
     *  GXGetStyleAttributes()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxStyleAttribute
    GXGetStyleAttributes(gxStyle source);

    /**
     *  GXGetShapeTextAttributes()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxTextAttribute
    GXGetShapeTextAttributes(gxShape source);

    /**
     *  GXGetStyleTextAttributes()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxTextAttribute
    GXGetStyleTextAttributes(gxStyle source);

    /**
     *  GXGetViewDeviceAttributes()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxDeviceAttribute
    GXGetViewDeviceAttributes(gxViewDevice source);

    /**
     *  GXGetViewPortAttributes()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxPortAttribute
    GXGetViewPortAttributes(gxViewPort source);

    /**
     *  GXSetInkAttributes()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetInkAttributes(gxInk target, gxInkAttribute attributes);

    /**
     *  GXSetShapeAttributes()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetShapeAttributes(gxShape target, gxShapeAttribute attributes);

    /**
     *  GXSetShapeInkAttributes()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetShapeInkAttributes(gxShape target, gxInkAttribute attributes);

    /**
     *  GXSetShapeStyleAttributes()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetShapeStyleAttributes(gxShape target, gxStyleAttribute attributes);

    /**
     *  GXSetStyleAttributes()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetStyleAttributes(gxStyle target, gxStyleAttribute attributes);

    /**
     *  GXSetShapeTextAttributes()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetShapeTextAttributes(gxShape target, gxTextAttribute attributes);

    /**
     *  GXSetStyleTextAttributes()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetStyleTextAttributes(gxStyle target, gxTextAttribute attributes);

    /**
     *  GXSetViewDeviceAttributes()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetViewDeviceAttributes(gxViewDevice target, gxDeviceAttribute attributes);

    /**
     *  GXSetViewPortAttributes()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetViewPortAttributes(gxViewPort target, gxPortAttribute attributes);

    /**
     *  GXGetColorProfileOwners()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    long
    GXGetColorProfileOwners(gxColorProfile source);

    /**
     *  GXGetColorSetOwners()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    long
    GXGetColorSetOwners(gxColorSet source);

    /**
     *  GXGetInkOwners()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    long
    GXGetInkOwners(gxInk source);

    /**
     *  GXGetShapeOwners()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    long
    GXGetShapeOwners(gxShape source);

    /**
     *  GXGetStyleOwners()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    long
    GXGetStyleOwners(gxStyle source);

    /**
     *  GXGetTagOwners()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    long
    GXGetTagOwners(gxTag source);

    /**
     *  GXGetTransformOwners()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    long
    GXGetTransformOwners(gxTransform source);

    /**
     *  GXLockShape()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXLockShape(gxShape target);

    /**
     *  GXLockTag()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXLockTag(gxTag target);

    /**
     *  GXUnlockShape()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXUnlockShape(gxShape target);

    /**
     *  GXUnlockTag()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXUnlockTag(gxTag target);

    /**
     *  GXGetShapeStructure()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void *
    GXGetShapeStructure(gxShape source, long *length);

    /**
     *  GXGetTagStructure()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void *
    GXGetTagStructure(gxTag source, long *length);

    /**
     *  GXGetColorDistance()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    Fixed
    GXGetColorDistance(const gxColor *target, const gxColor *source);

    /**
     *  GXShapeLengthToPoint()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxPoint *
    GXShapeLengthToPoint(gxShape target, long index, Fixed length,
                         gxPoint *location, gxPoint *tangent);

    /**
     *  GXGetShapeArea()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    wide *
    GXGetShapeArea(gxShape source, long index, wide *area);

    /**
     *  GXGetShapeCacheSize()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    long
    GXGetShapeCacheSize(gxShape source);

    /**
     *  GXGetShapeCenter()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxPoint *
    GXGetShapeCenter(gxShape source, long index, gxPoint *center);

    /**
     *  GXGetShapeDirection()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxContourDirection
    GXGetShapeDirection(gxShape source, long contour);

    /**
     *  GXGetShapeIndex()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    long
    GXGetShapeIndex(gxShape source, long contour, long vector);

    /**
     *  GXGetShapeLength()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    wide *
    GXGetShapeLength(gxShape source, long index, wide *length);

    /**
     *  GXGetShapeSize()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    long
    GXGetShapeSize(gxShape source);

    /**
     *  GXCountShapeContours()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    long
    GXCountShapeContours(gxShape source);

    /**
     *  GXCountShapePoints()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    long
    GXCountShapePoints(gxShape source, long contour);

    // returns the number of positions
    /**
       *GXGetShapeDashPositions() *

           *    \non_carbon_cfm not available
           *    \carbon_lib not available
           *    \mac_os_x not available
*/
    // returns the number of positions
    GXGetShapeDashPositions(gxShape source, gxMapping dashMappings[]);

    /**
     *  GXGetShapeDeviceArea()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    long
    GXGetShapeDeviceArea(gxShape source, gxViewPort port, gxViewDevice device);

    /**
     *  GXGetShapeDeviceBounds()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    Boolean
    GXGetShapeDeviceBounds(gxShape source, gxViewPort port, gxViewDevice device,
                           gxRectangle *bounds);

    /**
     *  GXGetShapeDeviceColors()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxColorSet
    GXGetShapeDeviceColors(gxShape source, gxViewPort port, gxViewDevice device,
                           long *width);

    /**
     *  GXGetShapeGlobalBounds()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    Boolean
    GXGetShapeGlobalBounds(gxShape source, gxViewPort port, gxViewGroup group,
                           gxRectangle *bounds);

    /**
     *  GXGetShapeGlobalViewDevices()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    long
    GXGetShapeGlobalViewDevices(gxShape source, gxViewPort port,
                                gxViewDevice list[]);

    /**
     *  GXGetShapeGlobalViewPorts()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    long
    GXGetShapeGlobalViewPorts(gxShape source, gxViewPort list[]);

    /**
     *  GXGetShapeLocalBounds()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxRectangle *
    GXGetShapeLocalBounds(gxShape source, gxRectangle *bounds);

    // returns the number of positions
    /**
       *GXGetShapePatternPositions() *

           *    \non_carbon_cfm not available
           *    \carbon_lib not available
           *    \mac_os_x not available
*/
    long
        // returns the number of positions
        ;

    /**
     *  GXGetShapeLocalFontMetrics()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXGetShapeLocalFontMetrics(gxShape sourceShape, gxPoint *before, gxPoint *after,
                               gxPoint *caretAngle, gxPoint *caretOffset);

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
                                gxPoint *caretOffset);

    /**
     *  GXGetViewGroupViewDevices()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    long
    GXGetViewGroupViewDevices(gxViewGroup source, gxViewDevice list[]);

    /**
     *  GXGetViewGroupViewPorts()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    long
    GXGetViewGroupViewPorts(gxViewGroup source, gxViewPort list[]);

    /**
     *  GXGetViewPortGlobalMapping()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxMapping *
    GXGetViewPortGlobalMapping(gxViewPort source, gxMapping *map);

    /**
     *  GXGetViewPortViewDevices()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    long
    GXGetViewPortViewDevices(gxViewPort source, gxViewDevice list[]);

    /**
     *  GXHitTestPicture()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxShape
    GXHitTestPicture(gxShape target, const gxPoint *test, gxHitTestInfo *result,
                     long level, long depth);

    /**
     *  GXIntersectRectangle()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    Boolean
    GXIntersectRectangle(gxRectangle *target, const gxRectangle *source,
                         const gxRectangle *operand);

    /**
     *  GXUnionRectangle()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxRectangle *
    GXUnionRectangle(gxRectangle *target, const gxRectangle *source,
                     const gxRectangle *operand);

    /**
     *  GXTouchesRectanglePoint()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    Boolean
    GXTouchesRectanglePoint(const gxRectangle *target, const gxPoint *test);

    /**
     *  GXTouchesShape()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    Boolean
    GXTouchesShape(gxShape target, gxShape test);

    /**
     *  GXTouchesBoundsShape()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    Boolean
    GXTouchesBoundsShape(const gxRectangle *target, gxShape test);

    /**
     *  GXContainsRectangle()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    Boolean
    GXContainsRectangle(const gxRectangle *container, const gxRectangle *test);

    /**
     *  GXContainsShape()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    Boolean
    GXContainsShape(gxShape container, gxShape test);

    /**
     *  GXContainsBoundsShape()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    Boolean
    GXContainsBoundsShape(const gxRectangle *container, gxShape test, long index);

    /**
     *  GXConvertColor()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxColor *
    GXConvertColor(gxColor *target, gxColorSpace space, gxColorSet aSet,
                   gxColorProfile profile);

    /**
     *  GXCombineColor()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxColor *
    GXCombineColor(gxColor *target, gxInk operand);

    /**
     *  GXCheckColor()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    Boolean
    GXCheckColor(const gxColor *source, gxColorSpace space, gxColorSet aSet,
                 gxColorProfile profile);

    /**
     *  GXCheckBitmapColor()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxShape
    GXCheckBitmapColor(gxShape source, const gxLongRectangle *area,
                       gxColorSpace space, gxColorSet aSet, gxColorProfile profile);

    /**
     *  GXGetHalftoneDeviceAngle()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    Fixed
    GXGetHalftoneDeviceAngle(gxViewDevice source, const gxHalftone *data);

    /**
     *  GXGetColorSetParts()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    long
    GXGetColorSetParts(gxColorSet source, long index, long count,
                       gxColorSpace *space, gxSetColor data[]);

    // returns the glyph count
    /**
       *GXGetGlyphParts() *

           *    \non_carbon_cfm not available
           *    \carbon_lib not available
           *    \mac_os_x not available
*/
    long GXGetGlyphParts(gxShape source, long index, long charCount, long *byteLength,
                         // returns the glyph count
                         gxPoint tangents[], long *runCount, short styleRuns[],
                         gxStyle styles[]);

    /**
     *  GXGetPathParts()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    long
    GXGetPathParts(gxShape source, long index, long count, gxPaths *data);

    /**
     *  GXGetPictureParts()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    long
    GXGetPictureParts(gxShape source, long index, long count, gxShape shapes[],
                      gxStyle styles[], gxInk inks[], gxTransform transforms[]);

    /**
     *  GXGetPolygonParts()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    long
    GXGetPolygonParts(gxShape source, long index, long count, gxPolygons *data);

    /**
     *  GXGetShapeParts()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxShape
    GXGetShapeParts(gxShape source, long index, long count, gxShape destination);

    /**
     *  GXGetTextParts()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    long
    GXGetTextParts(gxShape source, long index, long charCount, unsigned char text[]);

    /**
     *  GXSetColorSetParts()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetColorSetParts(gxColorSet target, long index, long oldCount, long newCount,
                       const gxSetColor data[]);

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
                    const gxStyle styles[]);

    /**
     *  GXSetPathParts()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetPathParts(gxShape target, long index, long count, const gxPaths *data,
                   gxEditShapeFlag flags);

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
                      const gxInk inks[], const gxTransform transforms[]);

    /**
     *  GXSetPolygonParts()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetPolygonParts(gxShape target, long index, long count,
                      const gxPolygons *data, gxEditShapeFlag flags);

    /**
     *  GXSetShapeParts()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetShapeParts(gxShape target, long index, long count, gxShape insert,
                    gxEditShapeFlag flags);

    /**
     *  GXSetTextParts()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetTextParts(gxShape target, long index, long oldCharCount, long newCharCount,
                   const unsigned char text[]);

    /**
     *  GXGetShapePoints()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    long
    GXGetShapePoints(gxShape source, long index, long count, gxPoint data[]);

    /**
     *  GXSetShapePoints()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetShapePoints(gxShape target, long index, long count, const gxPoint data[]);

    /**
     *  GXGetGlyphPositions()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    long
    GXGetGlyphPositions(gxShape source, long index, long charCount, long advance[],
                        gxPoint positions[]);

    /**
     *  GXGetGlyphTangents()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    long
    GXGetGlyphTangents(gxShape source, long index, long charCount,
                       gxPoint tangents[]);

    /**
     *  GXSetGlyphPositions()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetGlyphPositions(gxShape target, long index, long charCount,
                        const long advance[], const gxPoint positions[]);

    /**
     *  GXSetGlyphTangents()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSetGlyphTangents(gxShape target, long index, long charCount,
                       const gxPoint tangents[]);

    /**
     *  GXGetGlyphMetrics()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    long
    GXGetGlyphMetrics(gxShape source, gxPoint glyphOrigins[],
                      gxRectangle boundingBoxes[], gxPoint sideBearings[]);

    /**
     *  GXDifferenceShape()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXDifferenceShape(gxShape target, gxShape operand);

    /**
     *  GXExcludeShape()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXExcludeShape(gxShape target, gxShape operand);

    /**
     *  GXIntersectShape()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXIntersectShape(gxShape target, gxShape operand);

    /**
     *  GXMapShape()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXMapShape(gxShape target, const gxMapping *map);

    /**
     *  GXMoveShape()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXMoveShape(gxShape target, Fixed deltaX, Fixed deltaY);

    /**
     *  GXMoveShapeTo()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXMoveShapeTo(gxShape target, Fixed x, Fixed y);

    /**
     *  GXReverseDifferenceShape()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXReverseDifferenceShape(gxShape target, gxShape operand);

    /**
     *  GXRotateShape()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXRotateShape(gxShape target, Fixed degrees, Fixed xOffset, Fixed yOffset);

    /**
     *  GXScaleShape()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXScaleShape(gxShape target, Fixed hScale, Fixed vScale, Fixed xOffset,
                 Fixed yOffset);

    /**
     *  GXSkewShape()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSkewShape(gxShape target, Fixed xSkew, Fixed ySkew, Fixed xOffset,
                Fixed yOffset);

    /**
     *  GXUnionShape()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXUnionShape(gxShape target, gxShape operand);

    /**
     *  GXDifferenceTransform()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXDifferenceTransform(gxTransform target, gxShape operand);

    /**
     *  GXExcludeTransform()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXExcludeTransform(gxTransform target, gxShape operand);

    /**
     *  GXIntersectTransform()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXIntersectTransform(gxTransform target, gxShape operand);

    /**
     *  GXMapTransform()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXMapTransform(gxTransform target, const gxMapping *map);

    /**
     *  GXMoveTransform()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXMoveTransform(gxTransform target, Fixed deltaX, Fixed deltaY);

    /**
     *  GXMoveTransformTo()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXMoveTransformTo(gxTransform target, Fixed x, Fixed y);

    /**
     *  GXReverseDifferenceTransform()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXReverseDifferenceTransform(gxTransform target, gxShape operand);

    /**
     *  GXRotateTransform()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXRotateTransform(gxTransform target, Fixed degrees, Fixed xOffset,
                      Fixed yOffset);

    /**
     *  GXScaleTransform()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXScaleTransform(gxTransform target, Fixed hScale, Fixed vScale, Fixed xOffset,
                     Fixed yOffset);

    /**
     *  GXSkewTransform()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSkewTransform(gxTransform target, Fixed xSkew, Fixed ySkew, Fixed xOffset,
                    Fixed yOffset);

    /**
     *  GXUnionTransform()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXUnionTransform(gxTransform target, gxShape operand);

    /**
     *  GXBreakShape()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXBreakShape(gxShape target, long index);

    /**
     *  GXChangedShape()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXChangedShape(gxShape target);

    /**
     *  GXHitTestShape()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxShapePart
    GXHitTestShape(gxShape target, const gxPoint *test, gxHitTestInfo *result);

    /**
     *  GXHitTestDevice()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxShape
    GXHitTestDevice(gxShape target, gxViewPort port, gxViewDevice device,
                    const gxPoint *test, const gxPoint *tolerance);

    /**
     *  GXInsetShape()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXInsetShape(gxShape target, Fixed inset);

    /**
     *  GXInvertShape()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXInvertShape(gxShape target);

    /**
     *  GXPrimitiveShape()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXPrimitiveShape(gxShape target);

    /**
     *  GXReduceShape()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXReduceShape(gxShape target, long contour);

    /**
     *  GXReverseShape()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXReverseShape(gxShape target, long contour);

    /**
     *  GXSimplifyShape()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXSimplifyShape(gxShape target);

    /**
     *  GXLockColorProfile()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXLockColorProfile(gxColorProfile source);

    /**
     *  GXUnlockColorProfile()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXUnlockColorProfile(gxColorProfile source);

    /**
     *  GXGetColorProfileStructure()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void *
    GXGetColorProfileStructure(gxColorProfile source, long *length);

    /**
     *  GXFlattenShape()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXFlattenShape(gxShape source, gxFlattenFlag flags, gxSpoolBlock *block);

    /**
     *  GXUnflattenShape()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    gxShape
    GXUnflattenShape(gxSpoolBlock *block, long count, const gxViewPort portList[]);

    /**
     *  GXPostGraphicsNotice()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXPostGraphicsNotice(gxGraphicsNotice notice);

    /**
     *  GXIgnoreGraphicsNotice()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXIgnoreGraphicsNotice(gxGraphicsNotice notice);

    /**
     *  GXPopGraphicsNotice()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    GXPopGraphicsNotice(void);

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
#endif // CALL_NOT_IN_CARBON

#ifdef PRAGMA_IMPORT_OFF
#pragma import off
#elif PRAGMA_IMPORT
#pragma import reset
#endif

#ifdef __cplusplus
}
#endif

#endif // __GXGRAPHICS__ // __GXGRAPHICS__
