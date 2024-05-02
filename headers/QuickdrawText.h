/**
     \file       QuickdrawText.h

    \brief   Quickdraw Text Interfaces.

    \introduced_in  Mac OS 8.5
    \avaliable_from Universal Interfaces 3.4.1

    \copyright © 1983-2001 by Apple Computer, Inc., all rights reserved.

    \ingroup Quickdraw

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __QUICKDRAWTEXT__
#define __QUICKDRAWTEXT__

#ifndef __MACTYPES__
#include <MacTypes.h>
#endif

#ifndef __MIXEDMODE__
#include <MixedMode.h>
#endif

#ifndef __INTLRESOURCES__
#include <IntlResources.h>
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

/** new CGrafPort bottleneck ("newProc2") function, used in Unicode Text drawing
 */
/**
 *  StandardGlyphs()
 *

 *    \non_carbon_cfm   in QuickDrawText 8.5 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
OSStatus
StandardGlyphs(void *dataStream, ByteCount size);

enum {
  /** CharToPixel directions */
  leftCaret = 0,   /**Place caret for left block*/
  rightCaret = -1, /**Place caret for right block*/
  kHilite = 1      /**Direction is SysDirection*/
};

enum {
  smLeftCaret = 0,   /**Place caret for left block - obsolete */
  smRightCaret = -1, /**Place caret for right block - obsolete */
  smHilite = 1       /**Direction is TESysJust - obsolete */
};

enum {
  /**Constants for styleRunPosition argument in PortionLine, DrawJustified,
     MeasureJustified, CharToPixel, and PixelToChar.*/
  onlyStyleRun = 0,  /** This is the only style run on the line */
  leftStyleRun = 1,  /** This is leftmost of multiple style runs on the line */
  rightStyleRun = 2, /** This is rightmost of multiple style runs on the line */
  middleStyleRun = 3,  /** There are multiple style runs on the line and this is
                          neither the leftmost nor the rightmost. */
  smOnlyStyleRun = 0,  /** obsolete */
  smLeftStyleRun = 1,  /** obsolete */
  smRightStyleRun = 2, /** obsolete */
  smMiddleStyleRun = 3 /** obsolete */
};

/** type for styleRunPosition parameter in PixelToChar etc. */
typedef short JustStyleCode;
/** Type for truncWhere parameter in TruncString, TruncText */
typedef short TruncCode;
enum {
  /** Constants for truncWhere argument in TruncString and TruncText */
  truncEnd = 0,          /** Truncate at end */
  truncMiddle = 0x4000,  /** Truncate in middle */
  smTruncEnd = 0,        /** Truncate at end - obsolete */
  smTruncMiddle = 0x4000 /** Truncate in middle - obsolete */
};

enum {
  /** Constants for TruncString and TruncText results */
  notTruncated = 0,   /** No truncation was necessary */
  truncated = 1,      /** Truncation performed */
  truncErr = -1,      /** General error */
  smNotTruncated = 0, /** No truncation was necessary - obsolete */
  smTruncated = 1,    /** Truncation performed   - obsolete */
  smTruncErr = -1     /** General error - obsolete */
};

typedef SInt8 StyledLineBreakCode;
enum { smBreakWord = 0, smBreakChar = 1, smBreakOverflow = 2 };

/**QuickTime3.0*/
enum {
  /** Constants for txFlags (which used to be the pad field after txFace) */
  tfAntiAlias = 1 << 0,
  tfUnicode = 1 << 1
};

struct FontInfo {
  short ascent;
  short descent;
  short widMax;
  short leading;
};
typedef struct FontInfo FontInfo;

typedef short FormatOrder[1];
typedef FormatOrder *FormatOrderPtr;
/** FormatStatus was moved to TextUtils.i */
/** OffsetTable moved to IntlResources.i */

typedef CALLBACK_API(Boolean, StyleRunDirectionProcPtr)(short styleRunIndex,
                                                        void *dirParam);
typedef STACK_UPP_TYPE(StyleRunDirectionProcPtr) StyleRunDirectionUPP;
/**
 *  NewStyleRunDirectionUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
StyleRunDirectionUPP
NewStyleRunDirectionUPP(StyleRunDirectionProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
enum {
  uppStyleRunDirectionProcInfo = 0x00000390
}; /** pascal 1_byte Func(2_bytes, 4_bytes) */
#ifdef __cplusplus
inline StyleRunDirectionUPP
NewStyleRunDirectionUPP(StyleRunDirectionProcPtr userRoutine) {
  return (StyleRunDirectionUPP)NewRoutineDescriptor(
      (ProcPtr)(userRoutine), uppStyleRunDirectionProcInfo,
      GetCurrentArchitecture());
}
#else
#define NewStyleRunDirectionUPP(userRoutine)                                   \
  (StyleRunDirectionUPP) NewRoutineDescriptor((ProcPtr)(userRoutine),          \
                                              uppStyleRunDirectionProcInfo,    \
                                              GetCurrentArchitecture())
#endif
#endif

/**
 *  DisposeStyleRunDirectionUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void
DisposeStyleRunDirectionUPP(StyleRunDirectionUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
inline void DisposeStyleRunDirectionUPP(StyleRunDirectionUPP userUPP) {
  DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
}
#else
#define DisposeStyleRunDirectionUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

/**
 *  InvokeStyleRunDirectionUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
Boolean
InvokeStyleRunDirectionUPP(short styleRunIndex, void *dirParam,
                           StyleRunDirectionUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
inline Boolean InvokeStyleRunDirectionUPP(short styleRunIndex, void *dirParam,
                                          StyleRunDirectionUPP userUPP) {
  return (Boolean)CALL_TWO_PARAMETER_UPP(userUPP, uppStyleRunDirectionProcInfo,
                                         styleRunIndex, dirParam);
}
#else
#define InvokeStyleRunDirectionUPP(styleRunIndex, dirParam, userUPP)           \
  (Boolean) CALL_TWO_PARAMETER_UPP((userUPP), uppStyleRunDirectionProcInfo,    \
                                   (styleRunIndex), (dirParam))
#endif
#endif

#if CALL_NOT_IN_CARBON || OLDROUTINENAMES
/** support for pre-Carbon UPP routines: New...Proc and Call...Proc */
#define NewStyleRunDirectionProc(userRoutine)                                  \
  NewStyleRunDirectionUPP(userRoutine)
#define CallStyleRunDirectionProc(userRoutine, styleRunIndex, dirParam)        \
  InvokeStyleRunDirectionUPP(styleRunIndex, dirParam, userRoutine)
#endif /** CALL_NOT_IN_CARBON */

#if CALL_NOT_IN_CARBON
/**
 *  Pixel2Char()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(short)
Pixel2Char(Ptr textBuf, short textLen, short slop, short pixelWidth,
           Boolean *leadingEdge) FOURWORDINLINE(0x2F3C, 0x820E, 0x0014, 0xA8B5);

/**
 *  Char2Pixel()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(short)
Char2Pixel(Ptr textBuf, short textLen, short slop, short offset,
           short direction) FOURWORDINLINE(0x2F3C, 0x820C, 0x0016, 0xA8B5);

#endif /** CALL_NOT_IN_CARBON */

/**
 *  PixelToChar()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(short)
PixelToChar(Ptr textBuf, long textLength, Fixed slop, Fixed pixelWidth,
            Boolean *leadingEdge, Fixed *widthRemaining,
            JustStyleCode styleRunPosition, Point numer, Point denom)
    FOURWORDINLINE(0x2F3C, 0x8222, 0x002E, 0xA8B5);

/**
 *  CharToPixel()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(short)
CharToPixel(Ptr textBuf, long textLength, Fixed slop, long offset,
            short direction, JustStyleCode styleRunPosition, Point numer,
            Point denom) FOURWORDINLINE(0x2F3C, 0x821C, 0x0030, 0xA8B5);

/**
 *  DrawJustified()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(void)
DrawJustified(Ptr textPtr, long textLength, Fixed slop,
              JustStyleCode styleRunPosition, Point numer, Point denom)
    FOURWORDINLINE(0x2F3C, 0x8016, 0x0032, 0xA8B5);

/**
 *  MeasureJustified()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(void)
MeasureJustified(Ptr textPtr, long textLength, Fixed slop, Ptr charLocs,
                 JustStyleCode styleRunPosition, Point numer, Point denom)
    FOURWORDINLINE(0x2F3C, 0x801A, 0x0034, 0xA8B5);

/**
 *  PortionLine()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(Fixed)
PortionLine(Ptr textPtr, long textLen, JustStyleCode styleRunPosition,
            Point numer, Point denom)
    FOURWORDINLINE(0x2F3C, 0x8412, 0x0036, 0xA8B5);

/**
 *  HiliteText()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(void)
HiliteText(Ptr textPtr, short textLength, short firstOffset, short secondOffset,
           OffsetTable offsets) FOURWORDINLINE(0x2F3C, 0x800E, 0x001C, 0xA8B5);

#if CALL_NOT_IN_CARBON
/**
 *  DrawJust()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(void)
DrawJust(Ptr textPtr, short textLength, short slop)
    FOURWORDINLINE(0x2F3C, 0x8008, 0x001E, 0xA8B5);

/**
 *  MeasureJust()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(void)
MeasureJust(Ptr textPtr, short textLength, short slop, Ptr charLocs)
    FOURWORDINLINE(0x2F3C, 0x800C, 0x0020, 0xA8B5);


			/** 
			\brief Determine how to distribute the slop value for a line 
			\param    textPtr a pointer to the text to be justified
			<pre>The PortionText procedure indicates the correct proportion of justification
to be allocated to given text when compared to other text; used to determine
how to distribute the slop of a line among the style runs on the line
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
			 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(Fixed)
PortionText(Ptr textPtr, long textLength)
    FOURWORDINLINE(0x2F3C, 0x8408, 0x0024, 0xA8B5);

#endif /** CALL_NOT_IN_CARBON */

/**
 *  VisibleLength()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(long)
VisibleLength(Ptr textPtr, long textLength)
    FOURWORDINLINE(0x2F3C, 0x8408, 0x0028, 0xA8B5);

/**
 *  GetFormatOrder()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(void)
GetFormatOrder(FormatOrderPtr ordering, short firstFormat, short lastFormat,
               Boolean lineRight, StyleRunDirectionUPP rlDirProc, Ptr dirParam)
    FOURWORDINLINE(0x2F3C, 0x8012, 0xFFFC, 0xA8B5);


			/** 
			\brief Select font for subsequent text drawing 
			
			<pre>TextFont sets the txFont field of the current GrafPort . Subsequent text
drawing will use the specified font.
fontNois a font number. The following Standard Fonts are available as
system-defined constants:
systemFont 0System default font; "Chicago"
applFont 1default application font; initially "Geneva"
newYork 2
geneva3
monaco 4
venice5
london6
athens7
sanFran 8
toronto 9
cairo 11
losAngeles 12
times20These are all
helvetica 21 designed for
courier 22  use on the
symbol 23   LaserWriter
mobile 24
See Standard Fonts for a graphic depiction of these fonts. Use
GetFNum if you know the font's name, but not its number.
</pre>
 * \returns <pre>none
</pre>
 * \note <pre>Be sure to call InitFonts (once, early in the program, after InitGraf and
before InitWindows ). This ensures that the Font Manager is properly
initialized for text drawing.
The initial value for txFont is 0, specifying the system font, Chicago. You
can read the current value from the GrafPort structure:
curFont = thePort->txFont;
The appearance of the text is also affected by the txFace, txSize, and txMode
fields of the current GrafPort . Refer to TextFace , TextMode , and
TextSize .
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
			 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(void)
TextFont(short font) ONEWORDINLINE(0xA887);


			/** 
			\brief Select a style for subsequent text drawing 
			
			<pre>TextFace selects the test-style variation(s) (bold, italic, underline, etc.)
for the current GrafPort .
newStyle is an integer value (declared as an enum with a typedef of Style). A
value 0 indicates a "plain" unmodified version of the current font.
You can use bit-manipulation operations to combine any of the
following styles using the constants defined in Quickdraw.h:
bold1increased width on vertical strokes
italic2slanted toward the right
underline 4underscored, with breaks on descending letters
outline 8outlined
shadow 16Shadowed (outlined, heavier on right bottom)
condense 32less space between characters
extend64more space between characters
</pre>
 * \returns <pre>none
</pre>
 * \note <pre>TextFace modifies the txFace field of the current GrafPort . It is initially
set to 0 (plain text). The variation you select affects all subsequent text
drawing and text measuring.
You can read the current style setting by accessing the txFace field of the
current GrafPort :
curStyle = thePort -> txFace;
Here are some examples of usage:
TextFace ( bold ); /* set to bold */
TextFace ( bold | italic ); /* set to bold and italic */
TextFace ( thePort->txFace | bold );/* add bolding */
TextFace ( thePort->txFace & ~bold );/* remove bolding */
TextFace ( 0 ); /* set to plain text */
The "condense" and "extend" variations change the spacing between
characters to an arbitrary value set by the Font Manager. Another way to
compress expand text is to call SetFScaleDisable and use a smaller or
larger font. You may use SpaceExtra for spacing control; e.g., as an aid in
displaying right-justified text.
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
			 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(void)
TextFace(StyleParameter face) ONEWORDINLINE(0xA888);


			/** 
			\brief Set text-drawing transfer mode 
			
			<pre>TextMode selects the bit-transfer mode to be used in subsequent
text-drawing. Used for writing white characters on a black background, etc.
newMode selects the transfer mode. It must be one of the " srcXxx" modes.
Use one of the following constants, as defined in Quickdraw.h :
srcCopy 0overwrite background entirely
srcOr1overwrite where character is black
srcXor 2invert where character is black
srcBic3force white where character is black
notSrcCopy 4invert character, then srcCopy
notSrcOr 5invert character, then srcOr
notSrcXor 6invert character, then srcXor
notSrcBic 7invert character, then srcBic
</pre>
 * \returns <pre>none
</pre>
 * \note <pre>TextMode changes the txMode field of the current GrafPort structure.
See Transfer Modes  for a graphical representation of the effects of the
various modes.
The default mode is srcOr, which causes characters to be drawn over the
background, while allowing the background pattern to show through in the
empty parts of each letter.
The original Mac toolbox supported only srcOr, srcXor, and srcBic.
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
			 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(void)
TextMode(short mode) ONEWORDINLINE(0xA889);


			/** 
			\brief Set the point size for subsequent text drawing 
			
			<pre>TextSize selects the size, in points, for subsequently-drawn text.
newSize is the desired size, in typographical points. Values from 1 to 127
are allowed. A value of 0 specifies the system font size (12 points).
</pre>
 * \returns <pre>none
</pre>
 * \note <pre>TextSize sets the txSize field of the current GrafPort structure. The
initial value is 0, specifying the system font size (12-point).
If the font used in subsequent text drawing is not available in size points,
the Font Manager will use a font it does have, scaling it to the desired size.
Such "scaled" fonts have a jagged look to them. See SetFScaleDisable for
more information font scaling.
You may use SetFScaleDisable to space text as if it were a different
point size, while continuing to use a “real” (unscaled) font.
To see if an unscaled version of a font exists as a system resource, use
GetFNum to learn its font reference number, then call RealFont .
A typographical point is approximately 1/72 of an inch; very nearly the
size of a pixel on the Mac screen.
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
			 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(void)
TextSize(short size) ONEWORDINLINE(0xA88A);


			/** 
			\brief Space out text for left/right justification 
			
			<pre>SpaceExtra tells the Font Manager how much additional space to add when
displaying the space character (ASCII 0x20). It can be useful in
fully-justifying text.
extraSpace is a 4-byte Fixed value, specifying the average number of pixels and
fractional pixels to be added to each space character (ASCII 0x32).
</pre>
 * \returns <pre>none
</pre>
 * \note <pre>SpaceExtra modifies the spExtra field of the current GrafPort structure.
The initial value of this field is 0.
To justify a given text string to a specific line width:
1Use StringWidth to get the unadjusted size of the string.
2Subtract the returned value from the width between the margins; the
difference is the amount of adjustment needed.
3Count the number of spaces in the line.
4Use FixRatio to find the ratio between the results of steps 2 and 3.
5Call SpaceExtra , specifying the ratio returned from step 4.
6Position the pen ( MoveTo ) and draw the text ( DrawString ).
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
			 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(void)
SpaceExtra(Fixed extra) ONEWORDINLINE(0xA88E);

/**
 *  DrawChar()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(void)
DrawChar(CharParameter ch) ONEWORDINLINE(0xA883);

/**
 *  DrawString()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(void)
DrawString(ConstStr255Param s) ONEWORDINLINE(0xA884);

/**
 *  [Mac]DrawText()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC
#define MacDrawText DrawText
#endif
EXTERN_API(void)
MacDrawText(const void *textBuf, short firstByte, short byteCount)
    ONEWORDINLINE(0xA885);

/**
 *  CharWidth()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(short)
CharWidth(CharParameter ch) ONEWORDINLINE(0xA88D);

/**
 *  StringWidth()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(short)
StringWidth(ConstStr255Param s) ONEWORDINLINE(0xA88C);

/**
 *  TextWidth()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(short)
TextWidth(const void *textBuf, short firstByte, short byteCount)
    ONEWORDINLINE(0xA886);

/**
 *  MeasureText()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(void)
MeasureText(short count, const void *textAddr, void *charLocs)
    ONEWORDINLINE(0xA837);

/**
 *  GetFontInfo()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(void)
GetFontInfo(FontInfo *info) ONEWORDINLINE(0xA88B);


			/** 
			\brief Space to widen all text characters, excluding space band 
			
			<pre>CharExtra specifies how much additional width to give all characters .
extrais a Fixed value, specifying the average number of pixels and
fractional pixels to be added to each non-space character
</pre>
 * \returns <pre>none
</pre>
 * \note <pre>This modifies the charExtra field of the current CGrafPort structure. The
initial value of this field is 0, but both positive and negative number can be
used. This is a cGrafPort-specific procedure and has no effect when used in
conjunction with an old-style grafPort.
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
			 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(void)
CharExtra(Fixed extra) ONEWORDINLINE(0xAA23);

/**
 *  StdText()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(void)
StdText(short count, const void *textAddr, Point numer, Point denom)
    ONEWORDINLINE(0xA882);

/**
 *  StdTxMeas()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(short)
StdTxMeas(short byteCount, const void *textAddr, Point *numer, Point *denom,
          FontInfo *info) ONEWORDINLINE(0xA8ED);

/**
 *  StyledLineBreak()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(StyledLineBreakCode)
StyledLineBreak(Ptr textPtr, long textLen, long textStart, long textEnd,
                long flags, Fixed *textWidth, long *textOffset)
    FOURWORDINLINE(0x2F3C, 0x821C, 0xFFFE, 0xA8B5);

/**
 *  TruncString()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(short)
TruncString(short width, Str255 theString, TruncCode truncWhere)
    FOURWORDINLINE(0x2F3C, 0x8208, 0xFFE0, 0xA8B5);

/**
 *  TruncText()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(short)
TruncText(short width, Ptr textPtr, short *length, TruncCode truncWhere)
    FOURWORDINLINE(0x2F3C, 0x820C, 0xFFDE, 0xA8B5);

#if CALL_NOT_IN_CARBON
/**
 *  drawstring()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
drawstring(const char *s);

/**
 *  stringwidth()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
short
stringwidth(const char *s);

#endif /** CALL_NOT_IN_CARBON */

/**
 *  stdtext()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void
stdtext(short count, const void *textAddr, const Point *numer,
        const Point *denom);

#if OLDROUTINENAMES
#define NPixel2Char(textBuf, textLen, slop, pixelWidth, leadingEdge,           \
                    widthRemaining, styleRunPosition, numer, denom)            \
  PixelToChar(textBuf, textLen, slop, pixelWidth, leadingEdge, widthRemaining, \
              styleRunPosition, numer, denom)
#define NChar2Pixel(textBuf, textLen, slop, offset, direction,                 \
                    styleRunPosition, numer, denom)                            \
  CharToPixel(textBuf, textLen, slop, offset, direction, styleRunPosition,     \
              numer, denom)
#define NDrawJust(textPtr, textLength, slop, styleRunPosition, numer, denom)   \
  DrawJustified(textPtr, textLength, slop, styleRunPosition, numer, denom)
#define NMeasureJust(textPtr, textLength, slop, charLocs, styleRunPosition,    \
                     numer, denom)                                             \
  MeasureJustified(textPtr, textLength, slop, charLocs, styleRunPosition,      \
                   numer, denom)
#define NPortionText(textPtr, textLen, styleRunPosition, numer, denom)         \
  PortionLine(textPtr, textLen, styleRunPosition, numer, denom)
#endif /** OLDROUTINENAMES */

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

#endif /** __QUICKDRAWTEXT__ */
*/endif /** __QUICKDRAWTEXT__ */
*/*/*/*/*/*/