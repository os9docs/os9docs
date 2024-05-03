/**
     \file       Fonts.h

    \brief   Public interface to the Font Manager.

    \introduced_in  Mac OS 9 / Carbon
    \avaliable_from Universal Interfaces 3.4.1

    \copyright © 1985-2001 by Apple Computer, Inc., all rights reserved

    \defgroup Font

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __FONTS__
#define __FONTS__

#ifndef __MACTYPES__
#include <MacTypes.h>
#endif

#ifndef __ATSTYPES__
#include <ATSTypes.h>
#endif

#ifndef __FILES__
#include <Files.h>
#endif

#ifndef __MACERRORS__
#include <MacErrors.h>
#endif

#ifndef __QUICKDRAW__
#include <Quickdraw.h>
#endif

#ifndef __TEXTCOMMON__
#include <TextCommon.h>
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

  enum
  {
    systemFont = 0,
    applFont = 1
  };

  enum
  {
    kFMDefaultOptions = kNilOptions
  };

  /** Activation contexts */
  enum
  {
    kFMDefaultActivationContext = kFMDefaultOptions,
    kFMGlobalActivationContext = 0x00000001,
    kFMLocalActivationContext = kFMDefaultActivationContext
  };

  /** Iteration scopes */
  enum
  {
    kFMDefaultIterationScope = kFMDefaultOptions,
    kFMGlobalIterationScope = 0x00000001,
    kFMLocalIterationScope = kFMDefaultIterationScope
  };

/** kPlatformDefaultGuiFontID is used in QuickTime 3.0. */
#if TARGET_OS_MAC
  enum
  {
    kPlatformDefaultGuiFontID = applFont
  };

#else
enum
{
  kPlatformDefaultGuiFontID = -1
};

#endif /** TARGET_OS_MAC */

  enum
  {
    commandMark = 17,
    checkMark = 18,
    diamondMark = 19,
    appleMark = 20
  };

  enum
  {
    propFont = 36864L,
    prpFntH = 36865L,
    prpFntW = 36866L,
    prpFntHW = 36867L,
    fixedFont = 45056L,
    fxdFntH = 45057L,
    fxdFntW = 45058L,
    fxdFntHW = 45059L,
    fontWid = 44208L
  };

  struct FMInput
  {
    short family;
    short size;
    Style face;
    Boolean needBits;
    short device;
    Point numer;
    Point denom;
  };
  typedef struct FMInput FMInput;
  struct FMOutput
  {
    short errNum;
    Handle fontHandle;
    UInt8 boldPixels;
    UInt8 italicPixels;
    UInt8 ulOffset;
    UInt8 ulShadow;
    UInt8 ulThick;
    UInt8 shadowPixels;
    SInt8 extra;
    UInt8 ascent;
    UInt8 descent;
    UInt8 widMax;
    SInt8 leading;
    SInt8 curStyle;
    Point numer;
    Point denom;
  };
  typedef struct FMOutput FMOutput;
  typedef FMOutput *FMOutputPtr;
  typedef FMOutputPtr FMOutPtr;
  struct FMetricRec
  {
    Fixed ascent;      /**base line to top*/
    Fixed descent;     /**base line to bottom*/
    Fixed leading;     /**leading between lines*/
    Fixed widMax;      /**maximum character width*/
    Handle wTabHandle; /**handle to font width table*/
  };
  typedef struct FMetricRec FMetricRec;
  typedef FMetricRec *FMetricRecPtr;
  typedef FMetricRecPtr *FMetricRecHandle;
#if CALL_NOT_IN_CARBON
  /**
   *  InitFonts()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  InitFonts(void);

#endif /** CALL_NOT_IN_CARBON */

  /**
   *  GetFontName()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  GetFontName(short familyID, Str255 name);

  /**
   *  GetFNum()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  GetFNum(ConstStr255Param name, short *familyID);

  /**
   *  RealFont()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  Boolean
  RealFont(short fontNum, short size);

#if CALL_NOT_IN_CARBON
  /**
   *  SetFontLock()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  SetFontLock(Boolean lockFlag);

#endif /** CALL_NOT_IN_CARBON */

  /**
   *  FMSwapFont()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  FMOutPtr
  FMSwapFont(const FMInput *inRec);

  /**
   *  SetFScaleDisable()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  SetFScaleDisable(Boolean fscaleDisable);

  /**
   *  FontMetrics()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  FontMetrics(FMetricRecPtr theMetrics);

  /**
  \brief Enable/disable use of fractional character widths

  <pre>SetFractEnable controls the use of fractional character widths for drawing
text. By default, fractional widths are disabled.
useFract is a Boolean specifying whether to enable or disable use of fractional
character widths. It is one of:
FALSEDisable. All sizes are rounded to integers.
TRUEEnable. Use fixed-point calculations in all operations that
determine character placement.
</pre>
* \returns <pre>none
</pre>
* \note <pre> SetFractEnable affects functions that draw text (such as
DrawString ), and functions that calculate character widths (such as
TextWidth , CharWidth , and MeasureText ).
The 64K ROMs do not support fractional character widths; so all
characters are sized in typographical points (increments of 1/72nd of an
inch).
Use SetFractEnable (TRUE) before printing to the laser printer or other
high-resolution device or when writing in a "page-preview" window. At
other times, leave fractional positioning off for faster calculations.
C and ASM programmers are advised to use this routine rather than
bypassing it by setting the byte-length global variable FractEnable (at
0x0BF4) to 0xFF ( TRUE) or 0x00 ( FALSE). Note: Be sure you're running
on the 128K ROMs or later (see Gestalt).
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
  void
  SetFractEnable(Boolean fractEnable);

  /**
  \brief Retrieve the size of the current default font

  <pre>GetDefFontSize gets the size of the current default font.
</pre>
* \note <pre>This routine is in the Pascal interface, not ROM and can't be used with the
64K ROM.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
  short
  GetDefFontSize(void);

  /**
   *  IsOutline()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  Boolean
  IsOutline(Point numer, Point denom);

  /**
  \brief SetOutlinePreferred Make TrueType fonts preferred over bitmapped fonts

  <pre>You can use the SetOutlinePreferred procedure to cause the
Font Manager to prefer TrueType fonts over bitmapped fonts .
If a TrueType font and a bitmapped font are available for a font request, the
default behavior for the Font Manager is to choose the bitmapped font, in
order to maintain compatibility with documents that were created on computer
systems on which TrueType fonts were not available. The
SetOutlinePreferred procedure sets the preference of which type of font
to use in this situation.
If you want the Font Manager to choose outline fonts over any bitmapped
font counterparts, set the outlinePreferred parameter to TRUE. If only outline
fonts are available and outlinePreferred is set to FALSE, the outline font is
chosen regardless. If only bitmapped fonts are available and outlinePreferred
is set to TRUE, the bitmapped font is still chosen.
</pre>
* \returns <pre>none
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
  void
  SetOutlinePreferred(Boolean outlinePreferred);

  /**
  \brief GetOutlinePreferred Determine if TrueType fonts are preferred

  <pre>You can use the GetOutlinePreferred function to determine whether or not
TrueType fonts are preferred over bitmapped fonts .
If both types of fonts are available for a particular font request, the
GetOutlinePreferred function returns a Boolean value indicating whether
the Font Manager chooses TrueType fonts over bitmapped fonts. By default,
the Font Manager prefers to use bitmapped fonts, for which the
GetOutlinePreferred function returns FALSE; you can also set the
behavior of the Font Manager with the SetOutlinePreferred procedure.
</pre>
* \returns <pre>TRUE = TrueType is preferred
FALSE = bitmapped fonts preferred
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
  Boolean
  GetOutlinePreferred(void);

  /**
   *  OutlineMetrics()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  OutlineMetrics(short byteCount, const void *textPtr, Point numer, Point denom,
                 short *yMax, short *yMin, FixedPtr awArray, FixedPtr lsbArray,
                 RectPtr boundsArray);

  /**
  \brief SetPreserveGlyph Set whether to preserve outline glyph shape

  <pre>The SetPreserveGlyph procedure tells the Font Manager whether to
preserve the original shape of an outline glyph, which in some cases may
exceed the ascent or descent lines.
The default behavior for the Font Manager is to scale a glyph so that it fits
between the ascent and descent lines; however, this alters the look of the glyph.
If you set the preserveGlyph parameter in the SetPreserveGlyph procedure
to TRUE, the measurements of all glyphs are preserved, and your application
may have to alter the leading between lines in a document if some of these
glyphs extend beyond the ascent or descent lines. If you set preserveGlyph to
FALSE, all glyphs are scaled to fit between the ascent and descent lines.
Save the setting of whether glyphs are preserved or not and call
SetPreserveGlyph with this value as the parameter every time the user
opens the application.
</pre>
* \returns <pre>none
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
  void
  SetPreserveGlyph(Boolean preserveGlyph);

  /**
  \brief GetPreserveGlyph Find whether TrueType glyph shape is preserved or

  <pre>The GetPreserveGlyph function returns a Boolean value indicating whether
the Font Manager preserves the shape of TrueType glyphs, which by default
is FALSE. Your application can set the behavior of the
Font Manager using the SetPreserveGlyph procedure.
</pre>
* \returns <pre>Boolean TRUE = does preserve TrueType glyph shape
FALSE = does not preserve TrueType glyph shape
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
  Boolean
  GetPreserveGlyph(void);

#if CALL_NOT_IN_CARBON
  /**
   *  FlushFonts()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  FlushFonts(void);

#endif /** CALL_NOT_IN_CARBON */

#if CALL_NOT_IN_CARBON
  /**
   *  getfnum()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  getfnum(const char *theName, short *familyID);

  /**
   *  getfontname()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  getfontname(short familyID, char *theName);

#endif /** CALL_NOT_IN_CARBON */

  /**
  \brief Fetch the ID of the current system font

  <pre>GetSysFont gets the ID of the current system font.
</pre>
* \note <pre>This routine is in the Pascal interface, not ROM and can't be used with the
64K ROM.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
  short
  GetSysFont(void);

  /**
  \brief Fetch the ID of the current application font

  <pre>GetAppFont gets the ID of the current application font.
</pre>
* \note <pre>This routine is in the Pascal interface, not ROM and can't be used with the
64K ROM.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
  short
  GetAppFont(void);

  /**--------------------------------------------------------------------------------------*/
  /**  Extended font data functions (available only with Mac OS 8.5 or later) */
  /**--------------------------------------------------------------------------------------*/
  /**
   *  SetAntiAliasedTextEnabled()
   *

   *    \non_carbon_cfm   in InterfaceLib 8.6 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  SetAntiAliasedTextEnabled(Boolean iEnable, SInt16 iMinFontSize);

  /**
   *  IsAntiAliasedTextEnabled()
   *

   *    \non_carbon_cfm   in InterfaceLib 8.6 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  Boolean
  IsAntiAliasedTextEnabled(SInt16 *oMinFontSize);

  /**
   *  QDTextBounds()
   *

   *    \non_carbon_cfm   in InterfaceLib 8.6 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  QDTextBounds(short byteCount, const void *textAddr, Rect *bounds);

  /**
   *  FetchFontInfo()
   *

   *    \non_carbon_cfm   in InterfaceLib 8.6 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  FetchFontInfo(SInt16 fontID, SInt16 fontSize, SInt16 fontStyle, FontInfo *info);

  /**--------------------------------------------------------------------------------------*/
  /**  Font access and data management functions (available only with Mac OS 9.0
   * or later) */
  /**--------------------------------------------------------------------------------------*/
  /** Enumeration */
  /**
   *  FMCreateFontFamilyIterator()
   *

   *    \non_carbon_cfm   in FontManager 9.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  FMCreateFontFamilyIterator(const FMFilter *iFilter, /** can be NULL */
                             void *iRefCon, OptionBits iOptions,
                             FMFontFamilyIterator *ioIterator);

  /**
   *  FMDisposeFontFamilyIterator()
   *

   *    \non_carbon_cfm   in FontManager 9.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  FMDisposeFontFamilyIterator(FMFontFamilyIterator *ioIterator);

  /**
   *  FMResetFontFamilyIterator()
   *

   *    \non_carbon_cfm   in FontManager 9.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  FMResetFontFamilyIterator(const FMFilter *iFilter, /** can be NULL */
                            void *iRefCon, OptionBits iOptions,
                            FMFontFamilyIterator *ioIterator);

  /**
   *  FMGetNextFontFamily()
   *

   *    \non_carbon_cfm   in FontManager 9.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  FMGetNextFontFamily(FMFontFamilyIterator *ioIterator,
                      FMFontFamily *oFontFamily);

  /**
   *  FMCreateFontIterator()
   *

   *    \non_carbon_cfm   in FontManager 9.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  FMCreateFontIterator(const FMFilter *iFilter, /** can be NULL */
                       void *iRefCon, OptionBits iOptions,
                       FMFontIterator *ioIterator);

  /**
   *  FMDisposeFontIterator()
   *

   *    \non_carbon_cfm   in FontManager 9.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  FMDisposeFontIterator(FMFontIterator *ioIterator);

  /**
   *  FMResetFontIterator()
   *

   *    \non_carbon_cfm   in FontManager 9.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  FMResetFontIterator(const FMFilter *iFilter, /** can be NULL */
                      void *iRefCon, OptionBits iOptions,
                      FMFontIterator *ioIterator);

  /**
   *  FMGetNextFont()
   *

   *    \non_carbon_cfm   in FontManager 9.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  FMGetNextFont(FMFontIterator *ioIterator, FMFont *oFont);

  /** Font families */
  /**
   *  FMCreateFontFamilyInstanceIterator()
   *

   *    \non_carbon_cfm   in FontManager 9.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  FMCreateFontFamilyInstanceIterator(FMFontFamily iFontFamily,
                                     FMFontFamilyInstanceIterator *ioIterator);

  /**
   *  FMDisposeFontFamilyInstanceIterator()
   *

   *    \non_carbon_cfm   in FontManager 9.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  FMDisposeFontFamilyInstanceIterator(FMFontFamilyInstanceIterator *ioIterator);

  /**
   *  FMResetFontFamilyInstanceIterator()
   *

   *    \non_carbon_cfm   in FontManager 9.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  FMResetFontFamilyInstanceIterator(FMFontFamily iFontFamily,
                                    FMFontFamilyInstanceIterator *ioIterator);

  /**
   *  FMGetNextFontFamilyInstance()
   *

   *    \non_carbon_cfm   in FontManager 9.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  FMGetNextFontFamilyInstance(FMFontFamilyInstanceIterator *ioIterator,
                              FMFont *oFont,
                              FMFontStyle *oStyle, /** can be NULL */
                              FMFontSize *oSize);  /** can be NULL */

  /**
   *  FMGetFontFamilyFromName()
   *

   *    \non_carbon_cfm   in FontManager 9.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  FMFontFamily
  FMGetFontFamilyFromName(ConstStr255Param iName);

  /**
   *  FMGetFontFamilyName()
   *

   *    \non_carbon_cfm   in FontManager 9.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  FMGetFontFamilyName(FMFontFamily iFontFamily, Str255 oName);

  /**
   *  FMGetFontFamilyTextEncoding()
   *

   *    \non_carbon_cfm   in FontManager 9.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  FMGetFontFamilyTextEncoding(FMFontFamily iFontFamily,
                              TextEncoding *oTextEncoding);

  /**
   *  FMGetFontFamilyGeneration()
   *

   *    \non_carbon_cfm   in FontManager 9.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  FMGetFontFamilyGeneration(FMFontFamily iFontFamily, FMGeneration *oGeneration);

  /** Fonts */
  /**
   *  FMGetFontFormat()
   *

   *    \non_carbon_cfm   in FontManager 9.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  FMGetFontFormat(FMFont iFont, FourCharCode *oFormat);

  /**
   *  FMGetFontTableDirectory()
   *

   *    \non_carbon_cfm   in FontManager 9.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  FMGetFontTableDirectory(FMFont iFont, ByteCount iLength, void *iBuffer,
                          ByteCount *oActualLength); /** can be NULL */

  /**
   *  FMGetFontTable()
   *

   *    \non_carbon_cfm   in FontManager 9.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  FMGetFontTable(FMFont iFont, FourCharCode iTag, ByteOffset iOffset,
                 ByteCount iLength, void *iBuffer,
                 ByteCount *oActualLength); /** can be NULL */

  /**
   *  FMGetFontGeneration()
   *

   *    \non_carbon_cfm   in FontManager 9.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  FMGetFontGeneration(FMFont iFont, FMGeneration *oGeneration);

  /**
   *  FMGetFontContainer()
   *

   *    \non_carbon_cfm   in FontManager 9.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  FMGetFontContainer(FMFont iFont, FSSpec *oFontContainer);

  /** Conversion */
  /**
   *  FMGetFontFromFontFamilyInstance()
   *

   *    \non_carbon_cfm   in FontManager 9.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  FMGetFontFromFontFamilyInstance(
      FMFontFamily iFontFamily, FMFontStyle iStyle, FMFont *oFont,
      FMFontStyle *oIntrinsicStyle); /** can be NULL */

  /**
   *  FMGetFontFamilyInstanceFromFont()
   *

   *    \non_carbon_cfm   in FontManager 9.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  FMGetFontFamilyInstanceFromFont(FMFont iFont, FMFontFamily *oFontFamily,
                                  FMFontStyle *oStyle);

  /**
   *  FMGetATSFontRefFromFont()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available in CarbonLib 1.x, is available on Mac OS
   X version 10.1 and later
   *    \mac_os_x         in version 10.1 and later
   */
  ATSFontRef
  FMGetATSFontRefFromFont(FMFont iFont);

  /**
   *  FMGetATSFontFamilyRefFromFontFamily()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available in CarbonLib 1.x, is available on Mac OS
   X version 10.1 and later
   *    \mac_os_x         in version 10.1 and later
   */
  ATSFontFamilyRef
  FMGetATSFontFamilyRefFromFontFamily(FMFontFamily iFamily);

  /**
   *  FMGetFontFromATSFontRef()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available in CarbonLib 1.x, is available on Mac OS
   X version 10.1 and later
   *    \mac_os_x         in version 10.1 and later
   */
  FMFont
  FMGetFontFromATSFontRef(ATSFontRef iFont);

  /**
   *  FMGetFontFamilyFromATSFontFamilyRef()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available in CarbonLib 1.x, is available on Mac OS
   X version 10.1 and later
   *    \mac_os_x         in version 10.1 and later
   */
  FMFontFamily
  FMGetFontFamilyFromATSFontFamilyRef(ATSFontFamilyRef iFamily);

  /** Activation */
  /**
   *  FMActivateFonts()
   *

   *    \non_carbon_cfm   in FontManager 9.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  FMActivateFonts(const FSSpec *iFontContainer,
                  const FMFilter *iFilter, /** can be NULL */
                  void *iRefCon, OptionBits iOptions);

  /**
   *  FMDeactivateFonts()
   *

   *    \non_carbon_cfm   in FontManager 9.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  FMDeactivateFonts(const FSSpec *iFontContainer,
                    const FMFilter *iFilter, /** can be NULL */
                    void *iRefCon, OptionBits iOptions);

  /**
   *  FMGetGeneration()
   *

   *    \non_carbon_cfm   in FontManager 9.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  FMGeneration
  FMGetGeneration(void);

  /** Container Access */
  /**
   *  FMGetFontContainerFromFontFamilyInstance()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        in CarbonLib 1.5 and later
   *    \mac_os_x         in version 10.1 and later
   */
  OSStatus
  FMGetFontContainerFromFontFamilyInstance(FMFontFamily iFontFamily,
                                           FMFontStyle iStyle,
                                           FMFontSize iFontSize,
                                           FSSpec *oFontContainer);

  /**
   *  FMGetFontFamilyResource()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        in CarbonLib 1.5 and later
   *    \mac_os_x         in version 10.1 and later
   */
  OSStatus
  FMGetFontFamilyResource(FMFontFamily iFontFamily, FMFontStyle iFontStyle,
                          FMFontSize iFontSize, ByteCount iBufferSize,
                          void *ioBuffer, ByteCount *oSize); /** can be NULL */

  typedef FMFontFamily FontFamilyID;
  typedef FMFontSize FontPointSize;
  /**--------------------------------------------------------------------------------------*/
  /** Deprecated constant and type definitions */
  /**--------------------------------------------------------------------------------------*/
  /** The font identifier constants are deprecated; use GetFNum or
     FMGetFontFamilyFromName to find a font family from a standard QuickDraw name.
  */
  enum
  {
    kFMUseGlobalScopeOption = 0x00000001
  };

  enum
  {
    kFontIDNewYork = 2,
    kFontIDGeneva = 3,
    kFontIDMonaco = 4,
    kFontIDVenice = 5,
    kFontIDLondon = 6,
    kFontIDAthens = 7,
    kFontIDSanFrancisco = 8,
    kFontIDToronto = 9,
    kFontIDCairo = 11,
    kFontIDLosAngeles = 12,
    kFontIDTimes = 20,
    kFontIDHelvetica = 21,
    kFontIDCourier = 22,
    kFontIDSymbol = 23,
    kFontIDMobile = 24
  };

  /** The following data structures referenced by the low memory global variables
     of the Font Manager are deprecated on Mac OS X and CarbonLib 1.1. The low
     memory global variables are not shared between processes and may result in
     inconsistencies compared to previous releases of the system software. Changes
     made to the information contained in the low memory global variables,
     including any indirectly referenced width tables, font family records, and
     font records, are not reflected in the global state of the Font Manager and
     may only be accessed through the font access and data management functions of
     the Font Manager or ATS.
  */
  struct WidEntry
  {
    short widStyle; /**style entry applies to*/
  };
  typedef struct WidEntry WidEntry;
  struct WidTable
  {
    short numWidths; /**number of entries - 1*/
  };
  typedef struct WidTable WidTable;
  struct AsscEntry
  {
    short fontSize;
    short fontStyle;
    short fontID; /**font resource ID*/
  };
  typedef struct AsscEntry AsscEntry;
  struct FontAssoc
  {
    short numAssoc; /**number of entries - 1*/
  };
  typedef struct FontAssoc FontAssoc;
  struct StyleTable
  {
    short fontClass;
    long offset;
    long reserved;
    char indexes[48];
  };
  typedef struct StyleTable StyleTable;
  struct NameTable
  {
    short stringCount;
    Str255 baseFontName;
  };
  typedef struct NameTable NameTable;
  struct KernPair
  {
    char kernFirst;  /**1st character of kerned pair*/
    char kernSecond; /**2nd character of kerned pair*/
    short kernWidth; /**kerning in 1pt fixed format*/
  };
  typedef struct KernPair KernPair;
  struct KernEntry
  {
    short kernStyle;  /**style the entry applies to*/
    short kernLength; /**length of this entry*/
  };
  typedef struct KernEntry KernEntry;
  struct KernTable
  {
    short numKerns; /**number of kerning entries*/
  };
  typedef struct KernTable KernTable;
  struct WidthTable
  {
    Fixed tabData[256]; /**character widths*/
    Handle tabFont;     /**font record used to build table*/
    long sExtra;        /**space extra used for table*/
    long style;         /**extra due to style*/
    short fID;          /**font family ID*/
    short fSize;        /**font size request*/
    short face;         /**style (face) request*/
    short device;       /**device requested*/
    Point inNumer;      /**scale factors requested*/
    Point inDenom;      /**scale factors requested*/
    short aFID;         /**actual font family ID for table*/
    Handle fHand;       /**family record used to build up table*/
    Boolean usedFam;    /**used fixed point family widths*/
    UInt8 aFace;        /**actual face produced*/
    short vOutput;      /**vertical scale output value*/
    short hOutput;      /**horizontal scale output value*/
    short vFactor;      /**vertical scale output value*/
    short hFactor;      /**horizontal scale output value*/
    short aSize;        /**actual size of actual font used*/
    short tabSize;      /**total size of table*/
  };
  typedef struct WidthTable WidthTable;
  typedef WidthTable *WidthTablePtr;
  typedef WidthTablePtr *WidthTableHdl;
  struct FamRec
  {
    short ffFlags;       /**flags for family*/
    short ffFamID;       /**family ID number*/
    short ffFirstChar;   /**ASCII code of 1st character*/
    short ffLastChar;    /**ASCII code of last character*/
    short ffAscent;      /**maximum ascent for 1pt font*/
    short ffDescent;     /**maximum descent for 1pt font*/
    short ffLeading;     /**maximum leading for 1pt font*/
    short ffWidMax;      /**maximum widMax for 1pt font*/
    long ffWTabOff;      /**offset to width table*/
    long ffKernOff;      /**offset to kerning table*/
    long ffStylOff;      /**offset to style mapping table*/
    short ffProperty[9]; /**style property info*/
    short ffIntl[2];     /**for international use*/
    short ffVersion;     /**version number*/
  };
  typedef struct FamRec FamRec;
  struct FontRec
  {
    short fontType;        /**font type*/
    short firstChar;       /**ASCII code of first character*/
    short lastChar;        /**ASCII code of last character*/
    short widMax;          /**maximum character width*/
    short kernMax;         /**negative of maximum character kern*/
    short nDescent;        /**negative of descent*/
    short fRectWidth;      /**width of font rectangle*/
    short fRectHeight;     /**height of font rectangle*/
    unsigned short owTLoc; /**offset to offset/width table*/
    short ascent;          /**ascent*/
    short descent;         /**descent*/
    short leading;         /**leading*/
    short rowWords;        /**row width of bit image / 2 */
  };
  typedef struct FontRec FontRec;
  typedef FontRec *FontRecPtr;
  typedef FontRecPtr *FontRecHdl;
/**--------------------------------------------------------------------------------------*/
#if OLDROUTINENAMES
  enum
  {
    newYork = kFontIDNewYork,
    geneva = kFontIDGeneva,
    monaco = kFontIDMonaco,
    venice = kFontIDVenice,
    london = kFontIDLondon,
    athens = kFontIDAthens,
    sanFran = kFontIDSanFrancisco,
    toronto = kFontIDToronto,
    cairo = kFontIDCairo,
    losAngeles = kFontIDLosAngeles,
    times = kFontIDTimes,
    helvetica = kFontIDHelvetica,
    courier = kFontIDCourier,
    symbol = kFontIDSymbol,
    mobile = kFontIDMobile
  };

#endif /** OLDROUTINENAMES */

  /**--------------------------------------------------------------------------------------*/

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

#endif /** __FONTS__ */
* / don,
    athens = kFontIDAthens,
    sanFran = kFontIDSanFrancisco,
    toronto = kFontIDToronto,
    cairo = kFontIDCairo,
    losAngeles = kFontIDLosAngeles,
    times = kFontIDTimes,
    helvetica = kFontIDHelvetica,
    courier = kFontIDCourier,
    symbol = kFontIDSymbol,
    mobile = kFontIDMobile
}
;

#endif /** OLDROUTINENAMES */

/**--------------------------------------------------------------------------------------*/

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

#endif /** __FONTS__ */
* /*/*/ * /*/*/ * /