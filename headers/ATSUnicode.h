/**
     \file       ATSUnicode.h

    \brief   Public interfaces for Apple Type Services for Unicode Imaging

    \introduced_in  Mac OS 9 / Carbon
    \avaliable_from Universal Interfaces 3.4.1

    \copyright � 1997-2001 by Apple Computer, Inc., all rights reserved.

    \ingroup AppleTypeServices

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __ATSUNICODE__
#define __ATSUNICODE__

#ifndef __MACTYPES__
#include <MacTypes.h>
#endif

#ifndef __MACERRORS__
#include <MacErrors.h>
#endif

#ifndef __MACMEMORY__
#include <MacMemory.h>
#endif

#ifndef __ATSLAYOUTTYPES__
#include <ATSLayoutTypes.h>
#endif

#ifndef __FONTS__
#include <Fonts.h>
#endif

#ifndef __QUICKDRAW__
#include <Quickdraw.h>
#endif

#ifndef __SFNTTYPES__
#include <SFNTTypes.h>
#endif

#ifndef __SFNTLAYOUTTYPES__
#include <SFNTLayoutTypes.h>
#endif

#ifndef __TEXTCOMMON__
#include <TextCommon.h>
#endif

#ifndef __ATSTYPES__
#include <ATSTypes.h>
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

  /********************************/
  /*  Types and related constants */
  /********************************/
  /**
     UniCharArrayHandle and UniCharArrayOffset are defined in the
     TextCommon interface file.
  */

  /**
      ATSUTextMeasurement is specific to ATSUI in that measurement
      quantities are in fractional Fixed format instead of shorts
      used in QuickDraw Text.  This provides exact outline metrics and
      line specifications such as line width, ascent, descent, and so on.
  */
  typedef Fixed ATSUTextMeasurement;
  /**
      ATSUFontID indicates a particular font family and face.
      ATSUFontID's are not guaranteed to remain constant across
      reboots.  Clients should use the font's unique name to
      get a font token to store in documents which is
      guaranteed to remain constant across reboots.
  */
  typedef FMFont ATSUFontID;
  /**
      ATSUFontFeatureType and ATSUFontFeatureSelector are used
      to identify font features.
  */
  typedef UInt16 ATSUFontFeatureType;
  typedef UInt16 ATSUFontFeatureSelector;
  /**
      ATSUFontVariationAxis and ATSUFontVariationValue are used
      in connection with font variations.
  */
  typedef FourCharCode ATSUFontVariationAxis;
  typedef Fixed ATSUFontVariationValue;
  /**
      ATSUTextLayout is used to store the attribute information
      associated with a contiguous block of UniChar's (UInt16's)
      in memory.  It's typed to be an opaque structure.
  */
  typedef struct OpaqueATSUTextLayout *ATSUTextLayout;
  /**
      ATSUStyle is used to store a set of individual attributes,
      font features, and font variations.  It's typed to be
      an opaque structure.
  */
  typedef struct OpaqueATSUStyle *ATSUStyle;
  /**
      ATSUFontFallbacks is used to store the desired font fallback
      list and associated fallback cache information.  It's typed
      to be an opaque structure.
  */
  typedef struct OpaqueATSUFontFallbacks *ATSUFontFallbacks;
  /**
      ATSUAttributeTag is used to indicate the particular type
      of attribute under consideration:  font, size, color,
      and so on.
      Each style run may have at most one attribute with a
      given ATSUAttributeTag (i.e., a style run can't have
      more than one font or size) but may have none.
      Note: Apple reserves values 0 to 65,535 (0 to 0x0000FFFF).
      ATSUI clients may create their own tags with any other value.
  */
  typedef UInt32 ATSUAttributeTag;
  enum
  {
    /*    Layout and Line Control Attribute Tags*/
    kATSULineWidthTag = 1L,     /*    Type:       ATSUTextMeasurement*/
                                /*    Default value: 0*/
    kATSULineRotationTag = 2L,  /*    Type:       Fixed (fixed value in degrees in
                                   right-handed coordinate system)*/
                                /*    Default value: 0*/
    kATSULineDirectionTag = 3L, /*    Type:       Boolean; values 0 or 1 (see
                                   below for value identities)*/
    /*    Default value: GetSysDirection() ? kATSURightToLeftBaseDirection :
       kATSULeftToRightBaseDirection*/
    kATSULineJustificationFactorTag =
        4L,                          /*    Type:       Fract between 0 and 1*/
                                     /*    Default value: kATSUNoJustification*/
    kATSULineFlushFactorTag = 5L,    /*    Type:       Fract between 0 and 1 */
                                     /*    Default value: kATSUStartAlignment*/
    kATSULineBaselineValuesTag = 6L, /*    Type:       BslnBaselineRecord*/
    /*    Default value: All zeros.  Calculated from other style attributes (e.g.,
       font and point size)*/
    kATSULineLayoutOptionsTag =
        7L,                        /*    Type:       ATSLineLayoutOptions (see ATSLayoutTypes.h)*/
                                   /*    Default value: kATSLineNoLayoutOptions - other options listed in
                                      ATSLayoutTypes.h*/
    kATSULineAscentTag = 8L,       /*    Type:       ATSUTextMeasurement*/
                                   /*    Default value: kATSUseLineHeight*/
    kATSULineDescentTag = 9L,      /*    Type:       ATSUTextMeasurement*/
                                   /*    Default value: kATSUseLineHeight*/
    kATSULineLangRegionTag = 10L,  /*    Type:       RegionCode - region values
                                      listed in script.h interface file*/
                                   /*    Default value: kTextRegionDontCare*/
    kATSULineTextLocatorTag = 11L, /*    Type:       TextBreakLocatorRef*/
    /*    Default value: NULL - set Region derived locator or the default Text
       Utilities locator*/
    kATSULineTruncationTag = 12L,    /*    Type:       ATSULineTruncation*/
                                     /*    Default value: kATSUTruncateNone                                  */
    kATSULineFontFallbacksTag = 13L, /*    Type:       ATSUFontFallbacks*/
    /*    Default value: globally set font fallbacks using the
       ATSUSetFontFallbacks                                                     */
    kATSUMaxLineTag = 14L,      /*    This is just for convenience - the upper limit of
                                   the ATSUTextLayout attribute tags*/
                                /* obsolete layout tags */
    kATSULineLanguageTag = 10L, /*    Use kATSULineLangRegionTag           */
                                /*    Run Style Attribute Tags*/
                                /* QuickDraw compatibility tags */
    kATSUQDBoldfaceTag = 256L,  /*    Type:       Boolean    */
                                /*    Default value: false*/
    kATSUQDItalicTag = 257L,    /*    Type:       Boolean       */
                                /*    Default value: false*/
    kATSUQDUnderlineTag = 258L, /*    Type:       Boolean    */
                                /*    Default value: false*/
    kATSUQDCondensedTag = 259L, /*    Type:       Boolean    */
                                /*    Default value: false*/
    kATSUQDExtendedTag = 260L,  /*    Type:       Boolean    */
                                /*    Default value: false*/
                                /* Common run tags */
    kATSUFontTag = 261L,        /*    Type:       ATSUFontID */
    /*    Default value: GetScriptVariable( smSystemScript, smScriptAppFond )*/
    kATSUSizeTag = 262L, /*    Type:       Fixed  */
    /*    Default value: GetScriptVariable( smSystemScript, smScriptAppFondSize )
     */
    kATSUColorTag = 263L,      /*    Type:       RGBColor   */
                               /*    Default value: (0, 0, 0)*/
                               /*    Less common run tags */
    kATSULangRegionTag = 264L, /*    Type:       RegionCode - region values listed
                                  in script.h interface file*/
    /*    Default value: GetScriptManagerVariable( smRegionCode )*/
    kATSUVerticalCharacterTag =
        265L,                   /*    Type:       ATSUVerticalCharacterType  */
                                /*    Default value: kATSUStronglyHorizontal*/
    kATSUImposeWidthTag = 266L, /*    Type:       ATSUTextMeasurement*/
    /*    Default value: 0 - all glyphs use their own font defined advance
       widths*/
    kATSUBeforeWithStreamShiftTag = 267L, /*    Type:       Fixed*/
                                          /*    Default value: 0*/
    kATSUAfterWithStreamShiftTag = 268L,  /*    Type:       Fixed*/
                                          /*    Default value: 0*/
    kATSUCrossStreamShiftTag = 269L,      /*    Type:       Fixed*/
                                          /*    Default value: 0*/
    kATSUTrackingTag = 270L,              /*    Type:       Fixed*/
                                          /*    Default value: kATSNoTracking*/
    kATSUHangingInhibitFactorTag = 271L,  /*    Type:       Fract between 0 and 1*/
                                          /*    Default value: 0*/
    kATSUKerningInhibitFactorTag = 272L,  /*    Type:       Fract between 0 and 1*/
                                          /*    Default value: 0*/
    kATSUDecompositionFactorTag = 273L,   /*    Type:       Fixed (-1.0 -> 1.0)*/
                                          /*    Default value: 0*/
    kATSUBaselineClassTag =
        274L, /*    Type:       BslnBaselineClass  (see SFNTLayoutTypes.h)*/
    /*    Default value: kBSLNRomanBaseline - set to kBSLNNoBaselineOverride to
       use intrinsic baselines*/
    kATSUPriorityJustOverrideTag =
        275L,                       /*    Type:       ATSJustPriorityWidthDeltaOverrides (see
                                       ATSLayoutTypes.h)*/
                                    /*    Default value: all zeros*/
    kATSUNoLigatureSplitTag = 276L, /*    Type:       Boolean*/
    /*    Default value: false - ligatures and compound characters have divisable
       components.*/
    kATSUNoCaretAngleTag = 277L, /*    Type:       Boolean*/
    /*    Default value: false - use the character's angularity to determine its
       boundaries*/
    kATSUSuppressCrossKerningTag = 278L, /*    Type:       Boolean*/
    /*    Default value: false - do not suppress automatic cross kerning (defined
       by font)*/
    kATSUNoOpticalAlignmentTag = 279L, /*    Type:       Boolean*/
    /*    Default value: false - do not suppress character's automatic optical
       positional alignment*/
    kATSUForceHangingTag = 280L, /*    Type:       Boolean*/
    /*    Default value: false - do not force the character's to hang beyond the
       line boundaries*/
    kATSUNoSpecialJustificationTag = 281L, /*    Type:       Boolean*/
    /*    Default value: false - perform post-compensation justification if
       needed*/
    kATSUStyleTextLocatorTag = 282L, /*    Type:       TextBreakLocatorRef*/
    /*    Default value: NULL - region derived locator or the default Text
       Utilities locator*/
    kATSUStyleRenderingOptionsTag =
        283L, /*    Type:       ATSStyleRenderingOptions (see ATSLayoutTypes.h)*/
    /*    Default value: kATSStyleApplyHints - ATS glyph rendering uses hinting*/
    kATSUMaxStyleTag = 284L, /*    This is just for convenience - the upper limit
                                of the ATSUStyle attribute tags */
                             /* obsolete style tags */
    kATSULanguageTag = 264L, /*    use kATSULangRegionTag               */
                             /* special layout tag for Mac OS X */
    kATSUCGContextTag =
        32767L, /*  Type:          CGContext, Default value:    NULL   */
                /* max */
    kATSUMaxATSUITagValue =
        65535L /*    This is the maximum Apple ATSUI reserved tag value.  Client
                  defined tags must be larger.*/
  };

  /**
      ATSUAttributeValuePtr is used to provide generic access to
      storage of attribute values, which vary in size.
      ConstATSUAttributeValuePtr is a pointer to a const attribute value.
  */
  typedef void *ATSUAttributeValuePtr;
  typedef const void *ConstATSUAttributeValuePtr;
  /**
      ATSUAttributeInfo is used to provide a tag/size pairing.
      This makes it possible to provide the client information
      about all the attributes for a given range of text.  This
      structure is only used to return to the client information
      about a complete set of attributes.  An array of
      ATSUAttributeInfos is passed as a parameter so that the
      client can find out what attributes are set and what their
      individual sizes are; with that information, they can then
      query about the values of the attributes they're interested
      in.  Because arrays of ATSUAttributeInfos are used as parameters
      to functions, they have to be of a fixed size, hence the
      value is not included in the structure.
  */
  struct ATSUAttributeInfo
  {
    ATSUAttributeTag fTag;
    ByteCount fValueSize;
  };
  typedef struct ATSUAttributeInfo ATSUAttributeInfo;
  /**
      ATSUCaret contains the complete information needed to render a
      caret.  fX and fY is the position of one of the caret's ends
      relative to the origin position of the line the caret belongs.
      fDeltaX and fDeltaY is the position of the caret's other end.
      Hence, to draw a caret, simply call MoveTo(fX, fY) followed by
      LineTo(fDeltaX, fDeltaY) or equivalent.  The ATSUCaret will
      contain the positions needed to draw carets on angled lines
      and reflect angled carets and leading/trailing split caret
      appearances.
  */
  struct ATSUCaret
  {
    Fixed fX;
    Fixed fY;
    Fixed fDeltaX;
    Fixed fDeltaY;
  };
  typedef struct ATSUCaret ATSUCaret;
  /**
      ATSUCursorMovementType is used to indicate how much to move
      the cursor when using the ATSUI cusor movement routines.
      Note that kATSUByCharacterCluster is only available in Mac OS X
      and in CarbonLib versions 1.3 and later.
  */
  typedef UInt16 ATSUCursorMovementType;
  enum
  {
    kATSUByCharacter = 0,
    kATSUByTypographicCluster = 1, /* clusters based on characters or ligatures*/
    kATSUByWord = 2,
    kATSUByCharacterCluster = 3, /* clusters based on characters only*/
    kATSUByCluster = 1           /* obsolete name for kATSUByTypographicCluster*/
  };

  /**
      ATSULineTruncation is for identifying where truncation will occur when
      using a ATSUTextLayout with the ATSULineTruncation layout attribute.
  */
  typedef UInt32 ATSULineTruncation;
  enum
  {
    kATSUTruncateNone = 0,  /* truncation specification - add to any desired
                               truncFeat bit options listed below*/
    kATSUTruncateStart = 1, /* for instance, kATSUTruncateEnd with
                               kATSUTruncFeatNoSquishing is value 0x0000000A*/
    kATSUTruncateEnd = 2,
    kATSUTruncateMiddle = 3,
    kATSUTruncateSpecificationMask =
        0x00000007, /* these bits are reserved for the truncation specification (0
                       - 7)*/
    /* the following bit-field options can be added to the chosen truncation
       specification*/
    kATSUTruncFeatNoSquishing =
        0x00000008 /* if specified, do not perform any negative justification in
                      lieu of truncation*/
  };

  /**
      ATSUVerticalCharacterType currently can take two values
      and is used to indicate whether text is to be laid out
      as vertical glyphs or horizontal glyphs.
  */
  typedef UInt16 ATSUVerticalCharacterType;
  enum
  {
    kATSUStronglyHorizontal = 0,
    kATSUStronglyVertical = 1
  };

  /**
      ATSUStyleComparison is an enumeration with four values,
      and is used by ATSUCompareStyles() to indicate if the
      first style parameter contains as a proper subset, is
      equal to, or is contained by the second style parameter.
  */
  typedef UInt16 ATSUStyleComparison;
  enum
  {
    kATSUStyleUnequal = 0,
    kATSUStyleContains = 1,
    kATSUStyleEquals = 2,
    kATSUStyleContainedBy = 3
  };

  /**
      ATSUFontFallbackMethod type defines the method by which ATSUI will try to
      find an appropriate font for a character if the assigned font does not
      contain the needed glyph(s) to represent it.  This affects
     ATSUMatchFontsToText and font selection during layout and drawing when
     ATSUSetTransientFontMatching is set ON.
  */
  typedef UInt16 ATSUFontFallbackMethod;
  enum
  {
    kATSUDefaultFontFallbacks = 0,
    kATSULastResortOnlyFallback = 1,
    kATSUSequentialFallbacksPreferred = 2,
    kATSUSequentialFallbacksExclusive = 3
  };

#if CALL_NOT_IN_CARBON
  /**
      ATSUMemoryCallbacks is a union struct that allows the ATSUI
      client to specify a specific heap for ATSUI use or allocation
      callbacks of which ATSUI is to use each time ATSUI performs a
      memory operation (alloc, grow, free).
  */
  typedef CALLBACK_API_C(void *, ATSUCustomAllocFunc)(void *refCon,
                                                      ByteCount howMuch);
  typedef CALLBACK_API_C(void, ATSUCustomFreeFunc)(void *refCon,
                                                   void *doomedBlock);
  typedef CALLBACK_API_C(void *, ATSUCustomGrowFunc)(void *refCon, void *oldBlock,
                                                     ByteCount oldSize,
                                                     ByteCount newSize);
  union ATSUMemoryCallbacks
  {
    struct
    {
      ATSUCustomAllocFunc Alloc;
      ATSUCustomFreeFunc Free;
      ATSUCustomGrowFunc Grow;
      void *memoryRefCon;
    } callbacks;

    THz heapToUse;
  };
  typedef union ATSUMemoryCallbacks ATSUMemoryCallbacks;
  /**
      ATSUHeapSpec provides the ATSUI client a means of specifying the heap
      from which ATSUI should allocate its dynamic memory or specifying
      that ATSUI should use the memory callback provided by the client.
  */
  typedef UInt16 ATSUHeapSpec;
  enum
  {
    kATSUUseCurrentHeap = 0,
    kATSUUseAppHeap = 1,
    kATSUUseSpecificHeap = 2,
    kATSUUseCallbacks = 3
  };

  /**
      ATSUMemorySetting is used to store the results from a ATSUSetMemoryAlloc
      or a ATSUGetCurrentMemorySetting call.  It can also be used to change the
      current ATSUMemorySetting by passing it into the ATSUSetCurrentMemorySetting
      call.
  */
  typedef struct OpaqueATSUMemorySetting *ATSUMemorySetting;
#endif /* CALL_NOT_IN_CARBON */

  /* Types for ATSUI Low Level API */
  struct ATSUGlyphInfo
  {
    GlyphID glyphID;
    UInt16 reserved;
    UInt32 layoutFlags;
    UniCharArrayOffset charIndex;
    ATSUStyle style;
    Float32 deltaY;
    Float32 idealX;
    SInt16 screenX;
    SInt16 caretX;
  };
  typedef struct ATSUGlyphInfo ATSUGlyphInfo;
  struct ATSUGlyphInfoArray
  {
    ATSUTextLayout layout;
    ItemCount numGlyphs;
    ATSUGlyphInfo glyphs[1];
  };
  typedef struct ATSUGlyphInfoArray ATSUGlyphInfoArray;

  /*********************************************************************************/
  /*  ATSUI Highlighting method constants and typedefs             */
  /*********************************************************************************/
  typedef UInt32 ATSUHighlightMethod;
  enum
  {
    kInvertHighlighting = 0,
    kRedrawHighlighting = 1
  };

  typedef UInt32 ATSUBackgroundDataType;
  enum
  {
    kATSUBackgroundColor = 0,
    kATSUBackgroundCallback = 1
  };

  struct ATSUBackgroundColor
  {
    float red;
    float green;
    float blue;
    float alpha;
  };
  typedef struct ATSUBackgroundColor ATSUBackgroundColor;

  /**
   *  RedrawBackgroundProcPtr
   *
   *  Discussion:
   *    RedrawBackgroundProcPtr is a pointer to a client-supplied
   *    callback function (e.g. MyRedrawBackgroundProc) for redrawing
   *    complex backgrounds (and optionally the text as well) that can be
   *    called by ATSUI for highlighting if the client has called
   *    ATSUSetHighlightingMethod with iMethod=kRedrawHighlighting. In
   *    order for ATSUI to call the client function, the client must (1)
   *    in order to obtain a RedrawBackgroundUPP, and (2) pass the
   *    RedrawBackgroundUPP in the unhighlightData.backgroundUPP field of
   *    the iUnhighlightData parameter for the  ATSUSetHighlightingMethod
   *    call. When finished, the client should call
   *    DisposeRedrawBackgroundUPP with the RedrawBackgroundUPP.
   *
   *  Parameters:
   *
   *    iLayout:
   *      The layout to which the highlighting is being applied. The
   *      client function can use this to redraw the text.
   *
   *    iTextOffset:
   *      The offset of the text that is being highlighted; can be used
   *      by the client function to redraaw the text.
   *
   *    iTextLength:
   *      The length of the text that is being highlighted; can be used
   *      by the client function to redraaw the text.
   *
   *    iUnhighlightArea:
   *      An array of ATSTrapezoids that describes the highlight area.
   *      The ATSTrapezoid array is ALWAYS in QD coordinates.
   *
   *    iTrapezoidCount:
   *      The count of ATSTrapezoids in iUnhighlightArea.
   *
   *  Result:
   *    A Boolean result indicating whether ATSUI should redraw the text.
   *    If the client function redraws the text, it should return false,
   *    otherwise it should return true to have ATSUI redraw any text
   *    that needs to be redrawn.
   */
  typedef CALLBACK_API(Boolean,
                       RedrawBackgroundProcPtr)(ATSUTextLayout iLayout,
                                                UniCharArrayOffset iTextOffset,
                                                UniCharCount iTextLength,
                                                ATSTrapezoid iUnhighlightArea[],
                                                ItemCount iTrapezoidCount);
  typedef TVECTOR_UPP_TYPE(RedrawBackgroundProcPtr) RedrawBackgroundUPP;
  /**
    *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        in CarbonLib on Mac OS X
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(RedrawBackgroundUPP)
  NewRedrawBackgroundUPP(RedrawBackgroundProcPtr userRoutine);

  /**
    *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        in CarbonLib on Mac OS X
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(void)
  DisposeRedrawBackgroundUPP(RedrawBackgroundUPP userUPP);

  /**
    *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        in CarbonLib on Mac OS X
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(Boolean)
  InvokeRedrawBackgroundUPP(ATSUTextLayout iLayout,
                            UniCharArrayOffset iTextOffset,
                            UniCharCount iTextLength,
                            ATSTrapezoid iUnhighlightArea[],
                            ItemCount iTrapezoidCount,
                            RedrawBackgroundUPP userUPP);

  union ATSUBackgroundData
  {
    ATSUBackgroundColor backgroundColor;
    RedrawBackgroundUPP backgroundUPP;
  };
  typedef union ATSUBackgroundData ATSUBackgroundData;
  struct ATSUUnhighlightData
  {
    ATSUBackgroundDataType dataType;
    ATSUBackgroundData unhighlightData;
  };
  typedef struct ATSUUnhighlightData ATSUUnhighlightData;

  /********************/
  /*  Other constants */
  /********************/
  /* Line direction types (used for kATSULineDirectionTag values) */
  enum
  {
    kATSULeftToRightBaseDirection =
        0, /*    Impose left-to-right or top-to-bottom dominant direction */
    kATSURightToLeftBaseDirection =
        1 /*    Impose right-to-left or bottom-to-top dominant direction */
  };

/* LineFlushFactor convenience defined values */
#define kATSUStartAlignment ((Fract)0x00000000L)
#define kATSUEndAlignment ((Fract)0x40000000L)
#define kATSUCenterAlignment ((Fract)0x20000000L)
/* LineJustificationFactor convenience defined values */
#define kATSUNoJustification ((Fract)0x00000000L)
#define kATSUFullJustification ((Fract)0x40000000L)
  /* Other constants  */
  enum
  {
    kATSUInvalidFontID = 0
  };

  enum
  {
    kATSUUseLineControlWidth = 0x7FFFFFFF
  };

  enum
  {
    kATSUNoSelector = 0x0000FFFF
  };

  enum
  {
    kATSUUseGrafPortPenLoc = (unsigned long)0xFFFFFFFF,
    kATSUClearAll = (unsigned long)0xFFFFFFFF
  };

  enum
  {
    kATSUFromTextBeginning = (unsigned long)0xFFFFFFFF,
    kATSUToTextEnd = (unsigned long)0xFFFFFFFF
  };

  /****************/
  /*  Functions   */
  /****************/

  /*  Clipboard support, flattened style version 0 (it is advised to not use these
   * routines and perform your own flattening)  */
  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUCopyToHandle(ATSUStyle iStyle, Handle oStyleHandle);

  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUPasteFromHandle(ATSUStyle iStyle, Handle iStyleHandle);

/*  Memory allocation specification functions (not in Carbon)   */
#if CALL_NOT_IN_CARBON
  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.6 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  EXTERN_API_C(OSStatus)
  ATSUCreateMemorySetting(ATSUHeapSpec iHeapSpec,
                          ATSUMemoryCallbacks *iMemoryCallbacks,
                          ATSUMemorySetting *oMemorySetting);

  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.6 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  EXTERN_API_C(OSStatus)
  ATSUSetCurrentMemorySetting(ATSUMemorySetting iMemorySetting);

  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.6 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  EXTERN_API_C(ATSUMemorySetting)
  ATSUGetCurrentMemorySetting(void);

  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.6 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  EXTERN_API_C(OSStatus)
  ATSUDisposeMemorySetting(ATSUMemorySetting iMemorySetting);

/*  Font fallback object functions  */
#endif /* CALL_NOT_IN_CARBON */

  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 9.2.2 and later
   *    \carbon_lib        in CarbonLib 1.5 and later
   *    \mac_os_x         in version 10.1 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUCreateFontFallbacks(ATSUFontFallbacks *oFontFallback);

  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 9.2.2 and later
   *    \carbon_lib        in CarbonLib 1.5 and later
   *    \mac_os_x         in version 10.1 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUDisposeFontFallbacks(ATSUFontFallbacks iFontFallbacks);

  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 9.2.2 and later
   *    \carbon_lib        in CarbonLib 1.5 and later
   *    \mac_os_x         in version 10.1 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUSetObjFontFallbacks(ATSUFontFallbacks iFontFallbacks,
                          ItemCount iFontFallbacksCount,
                          const ATSUFontID iFonts[],
                          ATSUFontFallbackMethod iFontFallbackMethod);

  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 9.2.2 and later
   *    \carbon_lib        in CarbonLib 1.5 and later
   *    \mac_os_x         in version 10.1 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUGetObjFontFallbacks(ATSUFontFallbacks iFontFallbacks,
                          ItemCount iMaxFontFallbacksCount, ATSUFontID oFonts[],
                          ATSUFontFallbackMethod *oFontFallbackMethod,
                          ItemCount *oActualFallbacksCount);

  /*  Basic style functions   */
  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUCreateStyle(ATSUStyle *oStyle);

  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUCreateAndCopyStyle(ATSUStyle iStyle, ATSUStyle *oStyle);

  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUDisposeStyle(ATSUStyle iStyle);

  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUSetStyleRefCon(ATSUStyle iStyle, UInt32 iRefCon);

  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUGetStyleRefCon(ATSUStyle iStyle, UInt32 *oRefCon);

  /*  Style comparison        */
  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUCompareStyles(ATSUStyle iFirstStyle, ATSUStyle iSecondStyle,
                    ATSUStyleComparison *oComparison);

  /*  Attribute manipulations */
  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUCopyAttributes(ATSUStyle iSourceStyle, ATSUStyle iDestinationStyle);

  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUOverwriteAttributes(ATSUStyle iSourceStyle, ATSUStyle iDestinationStyle);

  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUUnderwriteAttributes(ATSUStyle iSourceStyle, ATSUStyle iDestinationStyle);

  /*  Empty styles    */
  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUClearStyle(ATSUStyle iStyle);

  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUStyleIsEmpty(ATSUStyle iStyle, Boolean *oIsClear);

  /*  Get and set attributes */
  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUCalculateBaselineDeltas(ATSUStyle iStyle, BslnBaselineClass iBaselineClass,
                              BslnBaselineRecord oBaselineDeltas);

  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUSetAttributes(ATSUStyle iStyle, ItemCount iAttributeCount,
                    const ATSUAttributeTag iTag[], const ByteCount iValueSize[],
                    const ATSUAttributeValuePtr iValue[]);

  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUGetAttribute(ATSUStyle iStyle, ATSUAttributeTag iTag,
                   ByteCount iExpectedValueSize, ATSUAttributeValuePtr oValue,
                   ByteCount *oActualValueSize);

  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUGetAllAttributes(ATSUStyle iStyle, ATSUAttributeInfo oAttributeInfoArray[],
                       ItemCount iTagValuePairArraySize,
                       ItemCount *oTagValuePairCount);

  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUClearAttributes(ATSUStyle iStyle, ItemCount iTagCount,
                      const ATSUAttributeTag iTag[]);

  /*  Font features   */
  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUSetFontFeatures(ATSUStyle iStyle, ItemCount iFeatureCount,
                      const ATSUFontFeatureType iType[],
                      const ATSUFontFeatureSelector iSelector[]);

  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUGetFontFeature(ATSUStyle iStyle, ItemCount iFeatureIndex,
                     ATSUFontFeatureType *oFeatureType,
                     ATSUFontFeatureSelector *oFeatureSelector);

  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUGetAllFontFeatures(ATSUStyle iStyle, ItemCount iMaximumFeatureCount,
                         ATSUFontFeatureType oFeatureType[],
                         ATSUFontFeatureSelector oFeatureSelector[],
                         ItemCount *oActualFeatureCount);

  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUClearFontFeatures(ATSUStyle iStyle, ItemCount iFeatureCount,
                        const ATSUFontFeatureType iType[],
                        const ATSUFontFeatureSelector iSelector[]);

  /*  Font variations */
  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUSetVariations(ATSUStyle iStyle, ItemCount iVariationCount,
                    const ATSUFontVariationAxis iAxes[],
                    const ATSUFontVariationValue iValue[]);

  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUGetFontVariationValue(ATSUStyle iStyle,
                            ATSUFontVariationAxis iFontVariationAxis,
                            ATSUFontVariationValue *oFontVariationValue);

  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUGetAllFontVariations(ATSUStyle iStyle, ItemCount iVariationCount,
                           ATSUFontVariationAxis oVariationAxes[],
                           ATSUFontVariationValue oFontVariationValues[],
                           ItemCount *oActualVariationCount);

  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUClearFontVariations(ATSUStyle iStyle, ItemCount iAxisCount,
                          const ATSUFontVariationAxis iAxis[]);

  /*  Basic text-layout functions */
  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUCreateTextLayout(ATSUTextLayout *oTextLayout);

  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.6 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUCreateAndCopyTextLayout(ATSUTextLayout iTextLayout,
                              ATSUTextLayout *oTextLayout);

  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUCreateTextLayoutWithTextPtr(
      ConstUniCharArrayPtr iText, UniCharArrayOffset iTextOffset,
      UniCharCount iTextLength, UniCharCount iTextTotalLength,
      ItemCount iNumberOfRuns, const UniCharCount iRunLengths[],
      ATSUStyle iStyles[], ATSUTextLayout *oTextLayout);

  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUCreateTextLayoutWithTextHandle(
      UniCharArrayHandle iText, UniCharArrayOffset iTextOffset,
      UniCharCount iTextLength, UniCharCount iTextTotalLength,
      ItemCount iNumberOfRuns, const UniCharCount iRunLengths[],
      ATSUStyle iStyles[], ATSUTextLayout *oTextLayout);

  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.6 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUClearLayoutCache(ATSUTextLayout iTextLayout, UniCharArrayOffset iLineStart);

  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUDisposeTextLayout(ATSUTextLayout iTextLayout);

  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUSetTextLayoutRefCon(ATSUTextLayout iTextLayout, UInt32 iRefCon);

  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUGetTextLayoutRefCon(ATSUTextLayout iTextLayout, UInt32 *oRefCon);

  /*  Glyph bounds retrieval  */
  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.6 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUGetGlyphBounds(ATSUTextLayout iTextLayout,
                     ATSUTextMeasurement iTextBasePointX,
                     ATSUTextMeasurement iTextBasePointY,
                     UniCharArrayOffset iBoundsCharStart,
                     UniCharCount iBoundsCharLength, UInt16 iTypeOfBounds,
                     ItemCount iMaxNumberOfBounds, ATSTrapezoid oGlyphBounds[],
                     ItemCount *oActualNumberOfBounds);

  /*  Idle processing */
  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUIdle(ATSUTextLayout iTextLayout);

  /*  Text location   */
  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUSetTextPointerLocation(ATSUTextLayout iTextLayout,
                             ConstUniCharArrayPtr iText,
                             UniCharArrayOffset iTextOffset,
                             UniCharCount iTextLength,
                             UniCharCount iTextTotalLength);

  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUSetTextHandleLocation(ATSUTextLayout iTextLayout, UniCharArrayHandle iText,
                            UniCharArrayOffset iTextOffset,
                            UniCharCount iTextLength,
                            UniCharCount iTextTotalLength);

  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUGetTextLocation(ATSUTextLayout iTextLayout, void **oText,
                      Boolean *oTextIsStoredInHandle, UniCharArrayOffset *oOffset,
                      UniCharCount *oTextLength, UniCharCount *oTextTotalLength);

  /*  Text manipulation   */
  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUTextDeleted(ATSUTextLayout iTextLayout,
                  UniCharArrayOffset iDeletedRangeStart,
                  UniCharCount iDeletedRangeLength);

  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUTextInserted(ATSUTextLayout iTextLayout,
                   UniCharArrayOffset iInsertionLocation,
                   UniCharCount iInsertionLength);

  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUTextMoved(ATSUTextLayout iTextLayout, ConstUniCharArrayPtr iNewLocation);

  /*  Layout controls */
  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUCopyLayoutControls(ATSUTextLayout iSourceTextLayout,
                         ATSUTextLayout iDestTextLayout);

  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUSetLayoutControls(ATSUTextLayout iTextLayout, ItemCount iAttributeCount,
                        const ATSUAttributeTag iTag[],
                        const ByteCount iValueSize[],
                        const ATSUAttributeValuePtr iValue[]);

  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUGetLayoutControl(ATSUTextLayout iTextLayout, ATSUAttributeTag iTag,
                       ByteCount iExpectedValueSize, ATSUAttributeValuePtr oValue,
                       ByteCount *oActualValueSize);

  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUGetAllLayoutControls(ATSUTextLayout iTextLayout,
                           ATSUAttributeInfo oAttributeInfoArray[],
                           ItemCount iTagValuePairArraySize,
                           ItemCount *oTagValuePairCount);

  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUClearLayoutControls(ATSUTextLayout iTextLayout, ItemCount iTagCount,
                          const ATSUAttributeTag iTag[]);

  /*  Single line layout controls */
  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.6 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUCopyLineControls(ATSUTextLayout iSourceTextLayout,
                       UniCharArrayOffset iSourceLineStart,
                       ATSUTextLayout iDestTextLayout,
                       UniCharArrayOffset iDestLineStart);

  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.6 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUSetLineControls(ATSUTextLayout iTextLayout, UniCharArrayOffset iLineStart,
                      ItemCount iAttributeCount, const ATSUAttributeTag iTag[],
                      const ByteCount iValueSize[],
                      const ATSUAttributeValuePtr iValue[]);

  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.6 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUGetLineControl(ATSUTextLayout iTextLayout, UniCharArrayOffset iLineStart,
                     ATSUAttributeTag iTag, ByteCount iExpectedValueSize,
                     ATSUAttributeValuePtr oValue, ByteCount *oActualValueSize);

  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.6 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUGetAllLineControls(ATSUTextLayout iTextLayout,
                         UniCharArrayOffset iLineStart,
                         ATSUAttributeInfo oAttributeInfoArray[],
                         ItemCount iTagValuePairArraySize,
                         ItemCount *oTagValuePairCount);

  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.6 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUClearLineControls(ATSUTextLayout iTextLayout, UniCharArrayOffset iLineStart,
                        ItemCount iTagCount, const ATSUAttributeTag iTag[]);

  /*  Style run processing    */
  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUSetRunStyle(ATSUTextLayout iTextLayout, ATSUStyle iStyle,
                  UniCharArrayOffset iRunStart, UniCharCount iRunLength);

  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUGetRunStyle(ATSUTextLayout iTextLayout, UniCharArrayOffset iOffset,
                  ATSUStyle *oStyle, UniCharArrayOffset *oRunStart,
                  UniCharCount *oRunLength);

  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUGetContinuousAttributes(ATSUTextLayout iTextLayout,
                              UniCharArrayOffset iOffset, UniCharCount iLength,
                              ATSUStyle oStyle);

  /*  Drawing and measuring   */
  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUDrawText(ATSUTextLayout iTextLayout, UniCharArrayOffset iLineOffset,
               UniCharCount iLineLength, ATSUTextMeasurement iLocationX,
               ATSUTextMeasurement iLocationY);

  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUMeasureText(ATSUTextLayout iTextLayout, UniCharArrayOffset iLineStart,
                  UniCharCount iLineLength, ATSUTextMeasurement *oTextBefore,
                  ATSUTextMeasurement *oTextAfter, ATSUTextMeasurement *oAscent,
                  ATSUTextMeasurement *oDescent);

  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUMeasureTextImage(ATSUTextLayout iTextLayout, UniCharArrayOffset iLineOffset,
                       UniCharCount iLineLength, ATSUTextMeasurement iLocationX,
                       ATSUTextMeasurement iLocationY, Rect *oTextImageRect);

  /*  Highlighting    */
  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUHighlightText(ATSUTextLayout iTextLayout,
                    ATSUTextMeasurement iTextBasePointX,
                    ATSUTextMeasurement iTextBasePointY,
                    UniCharArrayOffset iHighlightStart,
                    UniCharCount iHighlightLength);

  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUUnhighlightText(ATSUTextLayout iTextLayout,
                      ATSUTextMeasurement iTextBasePointX,
                      ATSUTextMeasurement iTextBasePointY,
                      UniCharArrayOffset iHighlightStart,
                      UniCharCount iHighlightLength);

  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUGetTextHighlight(ATSUTextLayout iTextLayout,
                       ATSUTextMeasurement iTextBasePointX,
                       ATSUTextMeasurement iTextBasePointY,
                       UniCharArrayOffset iHighlightStart,
                       UniCharCount iHighlightLength, RgnHandle oHighlightRegion);

  /*  Hit-testing */
  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUPositionToOffset(ATSUTextLayout iTextLayout, ATSUTextMeasurement iLocationX,
                       ATSUTextMeasurement iLocationY,
                       UniCharArrayOffset *ioPrimaryOffset, Boolean *oIsLeading,
                       UniCharArrayOffset *oSecondaryOffset);

  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUOffsetToPosition(ATSUTextLayout iTextLayout, UniCharArrayOffset iOffset,
                       Boolean iIsLeading, ATSUCaret *oMainCaret,
                       ATSUCaret *oSecondCaret, Boolean *oCaretIsSplit);

  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 9.2.2 and later
   *    \carbon_lib        in CarbonLib 1.5 and later
   *    \mac_os_x         in version 10.1 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUPositionToCursorOffset(ATSUTextLayout iTextLayout,
                             ATSUTextMeasurement iLocationX,
                             ATSUTextMeasurement iLocationY,
                             ATSUCursorMovementType iMovementType,
                             UniCharArrayOffset *ioPrimaryOffset,
                             Boolean *oIsLeading,
                             UniCharArrayOffset *oSecondaryOffset);

  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 9.2.2 and later
   *    \carbon_lib        in CarbonLib 1.5 and later
   *    \mac_os_x         in version 10.1 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUOffsetToCursorPosition(ATSUTextLayout iTextLayout,
                             UniCharArrayOffset iOffset, Boolean iIsLeading,
                             ATSUCursorMovementType iMovementType,
                             ATSUCaret *oMainCaret, ATSUCaret *oSecondCaret,
                             Boolean *oCaretIsSplit);

  /*  Cursor movement */
  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUNextCursorPosition(ATSUTextLayout iTextLayout,
                         UniCharArrayOffset iOldOffset,
                         ATSUCursorMovementType iMovementType,
                         UniCharArrayOffset *oNewOffset);

  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUPreviousCursorPosition(ATSUTextLayout iTextLayout,
                             UniCharArrayOffset iOldOffset,
                             ATSUCursorMovementType iMovementType,
                             UniCharArrayOffset *oNewOffset);

  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSURightwardCursorPosition(ATSUTextLayout iTextLayout,
                              UniCharArrayOffset iOldOffset,
                              ATSUCursorMovementType iMovementType,
                              UniCharArrayOffset *oNewOffset);

  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSULeftwardCursorPosition(ATSUTextLayout iTextLayout,
                             UniCharArrayOffset iOldOffset,
                             ATSUCursorMovementType iMovementType,
                             UniCharArrayOffset *oNewOffset);

  /*  Line breaking   */
  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUBreakLine(ATSUTextLayout iTextLayout, UniCharArrayOffset iLineStart,
                ATSUTextMeasurement iLineWidth, Boolean iUseAsSoftLineBreak,
                UniCharArrayOffset *oLineBreak);

  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUSetSoftLineBreak(ATSUTextLayout iTextLayout, UniCharArrayOffset iLineBreak);

  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUGetSoftLineBreaks(ATSUTextLayout iTextLayout,
                        UniCharArrayOffset iRangeStart, UniCharCount iRangeLength,
                        ItemCount iMaximumBreaks, UniCharArrayOffset oBreaks[],
                        ItemCount *oBreakCount);

  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUClearSoftLineBreaks(ATSUTextLayout iTextLayout,
                          UniCharArrayOffset iRangeStart,
                          UniCharCount iRangeLength);

  /*  Font matching   */
  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.6 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUSetFontFallbacks(ItemCount iFontFallbacksCount, const ATSUFontID iFontIDs[],
                       ATSUFontFallbackMethod iFontFallbackMethod);

  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.6 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUGetFontFallbacks(ItemCount iMaxFontFallbacksCount, ATSUFontID oFontIDs[],
                       ATSUFontFallbackMethod *oFontFallbackMethod,
                       ItemCount *oActualFallbacksCount);

  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUMatchFontsToText(ATSUTextLayout iTextLayout, UniCharArrayOffset iTextStart,
                       UniCharCount iTextLength, ATSUFontID *oFontID,
                       UniCharArrayOffset *oChangedOffset,
                       UniCharCount *oChangedLength);

  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUSetTransientFontMatching(ATSUTextLayout iTextLayout,
                               Boolean iTransientFontMatching);

  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUGetTransientFontMatching(ATSUTextLayout iTextLayout,
                               Boolean *oTransientFontMatching);

  /*  Font ID's   */
  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUFontCount(ItemCount *oFontCount);

  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUGetFontIDs(ATSUFontID oFontIDs[], ItemCount iArraySize,
                 ItemCount *oFontCount);

  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUFONDtoFontID(short iFONDNumber, Style iFONDStyle, ATSUFontID *oFontID);

  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUFontIDtoFOND(ATSUFontID iFontID, short *oFONDNumber, Style *oFONDStyle);

  /*  Font names  */
  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUCountFontNames(ATSUFontID iFontID, ItemCount *oFontNameCount);

  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUGetIndFontName(ATSUFontID iFontID, ItemCount iFontNameIndex,
                     ByteCount iMaximumNameLength, Ptr oName,
                     ByteCount *oActualNameLength, FontNameCode *oFontNameCode,
                     FontPlatformCode *oFontNamePlatform,
                     FontScriptCode *oFontNameScript,
                     FontLanguageCode *oFontNameLanguage);

  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUFindFontName(ATSUFontID iFontID, FontNameCode iFontNameCode,
                   FontPlatformCode iFontNamePlatform,
                   FontScriptCode iFontNameScript,
                   FontLanguageCode iFontNameLanguage,
                   ByteCount iMaximumNameLength, Ptr oName,
                   ByteCount *oActualNameLength, ItemCount *oFontNameIndex);

  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUFindFontFromName(Ptr iName, ByteCount iNameLength,
                       FontNameCode iFontNameCode,
                       FontPlatformCode iFontNamePlatform,
                       FontScriptCode iFontNameScript,
                       FontLanguageCode iFontNameLanguage, ATSUFontID *oFontID);

  /*  Font features   */
  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUCountFontFeatureTypes(ATSUFontID iFontID, ItemCount *oTypeCount);

  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUCountFontFeatureSelectors(ATSUFontID iFontID, ATSUFontFeatureType iType,
                                ItemCount *oSelectorCount);

  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUGetFontFeatureTypes(ATSUFontID iFontID, ItemCount iMaximumTypes,
                          ATSUFontFeatureType oTypes[],
                          ItemCount *oActualTypeCount);

  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUGetFontFeatureSelectors(ATSUFontID iFontID, ATSUFontFeatureType iType,
                              ItemCount iMaximumSelectors,
                              ATSUFontFeatureSelector oSelectors[],
                              Boolean oSelectorIsOnByDefault[],
                              ItemCount *oActualSelectorCount,
                              Boolean *oIsMutuallyExclusive);

  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUGetFontFeatureNameCode(ATSUFontID iFontID, ATSUFontFeatureType iType,
                             ATSUFontFeatureSelector iSelector,
                             FontNameCode *oNameCode);

  /*  Font tracking value & names */
  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.6 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUCountFontTracking(ATSUFontID iFontID,
                        ATSUVerticalCharacterType iCharacterOrientation,
                        ItemCount *oTrackingCount);

  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.6 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUGetIndFontTracking(ATSUFontID iFontID,
                         ATSUVerticalCharacterType iCharacterOrientation,
                         ItemCount iTrackIndex, Fixed *oFontTrackingValue,
                         FontNameCode *oNameCode);

  /*  Font variations */
  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUCountFontVariations(ATSUFontID iFontID, ItemCount *oVariationCount);

  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUGetIndFontVariation(ATSUFontID iFontID, ItemCount iVariationIndex,
                          ATSUFontVariationAxis *oATSUFontVariationAxis,
                          ATSUFontVariationValue *oMinimumValue,
                          ATSUFontVariationValue *oMaximumValue,
                          ATSUFontVariationValue *oDefaultValue);

  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUGetFontVariationNameCode(ATSUFontID iFontID, ATSUFontVariationAxis iAxis,
                               FontNameCode *oNameCode);

  /*  Font Instances  */
  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUCountFontInstances(ATSUFontID iFontID, ItemCount *oInstances);

  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUGetFontInstance(ATSUFontID iFontID, ItemCount iFontInstanceIndex,
                      ItemCount iMaximumVariations, ATSUFontVariationAxis oAxes[],
                      ATSUFontVariationValue oValues[],
                      ItemCount *oActualVariationCount);

  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUGetFontInstanceNameCode(ATSUFontID iFontID, ItemCount iInstanceIndex,
                              FontNameCode *oNameCode);

  /*******************************************************************************/
  /* ATSUI Low-Level API */
  /*******************************************************************************/
  /* GlyphInfo access */
  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 9.1 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUGetGlyphInfo(ATSUTextLayout iTextLayout, UniCharArrayOffset iLineStart,
                   UniCharCount iLineLength, ByteCount *ioBufferSize,
                   ATSUGlyphInfoArray *oGlyphInfoPtr);

  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 9.1 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUDrawGlyphInfo(ATSUGlyphInfoArray *iGlyphInfoArray, Float32Point iLocation);

  /* Font Data Access */
  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 9.1 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUGlyphGetIdealMetrics(ATSUStyle iATSUStyle, ItemCount iNumOfGlyphs,
                           GlyphID iGlyphIDs[], ByteOffset iInputOffset,
                           ATSGlyphIdealMetrics oIdealMetrics[]);

  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 9.1 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUGetNativeCurveType(ATSUStyle iATSUStyle, ATSCurveType *oCurveType);

  /* Device specific routines */
  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 9.1 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUGlyphGetScreenMetrics(ATSUStyle iATSUStyle, ItemCount iNumOfGlyphs,
                            GlyphID iGlyphIDs[], ByteOffset iInputOffset,
                            Boolean iForcingAntiAlias, Boolean iAntiAliasSwitch,
                            ATSGlyphScreenMetrics oScreenMetrics[]);

  /* ATSUGlyphGetQuadraticPaths callbacks */
  typedef CALLBACK_API(OSStatus, ATSQuadraticLineProcPtr)(const Float32Point *pt1,
                                                          const Float32Point *pt2,
                                                          void *callBackDataPtr);
  typedef CALLBACK_API(OSStatus,
                       ATSQuadraticCurveProcPtr)(const Float32Point *pt1,
                                                 const Float32Point *controlPt,
                                                 const Float32Point *pt2,
                                                 void *callBackDataPtr);
  typedef CALLBACK_API(OSStatus,
                       ATSQuadraticNewPathProcPtr)(void *callBackDataPtr);
  typedef CALLBACK_API(OSStatus,
                       ATSQuadraticClosePathProcPtr)(void *callBackDataPtr);
  typedef TVECTOR_UPP_TYPE(ATSQuadraticLineProcPtr) ATSQuadraticLineUPP;
  typedef TVECTOR_UPP_TYPE(ATSQuadraticCurveProcPtr) ATSQuadraticCurveUPP;
  typedef TVECTOR_UPP_TYPE(ATSQuadraticNewPathProcPtr) ATSQuadraticNewPathUPP;
  typedef TVECTOR_UPP_TYPE(ATSQuadraticClosePathProcPtr) ATSQuadraticClosePathUPP;
  /**
    *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(ATSQuadraticLineUPP)
  NewATSQuadraticLineUPP(ATSQuadraticLineProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppATSQuadraticLineProcInfo = 0x00000FF0
  }; /* pascal 4_bytes Func(4_bytes, 4_bytes, 4_bytes) */
#ifdef __cplusplus
  inline ATSQuadraticLineUPP
  NewATSQuadraticLineUPP(ATSQuadraticLineProcPtr userRoutine)
  {
    return userRoutine;
  }
#else
#define NewATSQuadraticLineUPP(userRoutine) (userRoutine)
#endif
#endif

  /**
    *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(ATSQuadraticCurveUPP)
  NewATSQuadraticCurveUPP(ATSQuadraticCurveProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppATSQuadraticCurveProcInfo = 0x00003FF0
  }; /* pascal 4_bytes Func(4_bytes, 4_bytes, 4_bytes, 4_bytes) */
#ifdef __cplusplus
  inline ATSQuadraticCurveUPP
  NewATSQuadraticCurveUPP(ATSQuadraticCurveProcPtr userRoutine)
  {
    return userRoutine;
  }
#else
#define NewATSQuadraticCurveUPP(userRoutine) (userRoutine)
#endif
#endif

  /**
    *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(ATSQuadraticNewPathUPP)
  NewATSQuadraticNewPathUPP(ATSQuadraticNewPathProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppATSQuadraticNewPathProcInfo = 0x000000F0
  }; /* pascal 4_bytes Func(4_bytes) */
#ifdef __cplusplus
  inline ATSQuadraticNewPathUPP
  NewATSQuadraticNewPathUPP(ATSQuadraticNewPathProcPtr userRoutine)
  {
    return userRoutine;
  }
#else
#define NewATSQuadraticNewPathUPP(userRoutine) (userRoutine)
#endif
#endif

  /**
    *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(ATSQuadraticClosePathUPP)
  NewATSQuadraticClosePathUPP(ATSQuadraticClosePathProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppATSQuadraticClosePathProcInfo = 0x000000F0
  }; /* pascal 4_bytes Func(4_bytes) */
#ifdef __cplusplus
  inline ATSQuadraticClosePathUPP
  NewATSQuadraticClosePathUPP(ATSQuadraticClosePathProcPtr userRoutine)
  {
    return userRoutine;
  }
#else
#define NewATSQuadraticClosePathUPP(userRoutine) (userRoutine)
#endif
#endif

  /**
    *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(void)
  DisposeATSQuadraticLineUPP(ATSQuadraticLineUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeATSQuadraticLineUPP(ATSQuadraticLineUPP) {}
#else
#define DisposeATSQuadraticLineUPP(userUPP)
#endif
#endif

  /**
    *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(void)
  DisposeATSQuadraticCurveUPP(ATSQuadraticCurveUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeATSQuadraticCurveUPP(ATSQuadraticCurveUPP) {}
#else
#define DisposeATSQuadraticCurveUPP(userUPP)
#endif
#endif

  /**
    *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(void)
  DisposeATSQuadraticNewPathUPP(ATSQuadraticNewPathUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeATSQuadraticNewPathUPP(ATSQuadraticNewPathUPP) {}
#else
#define DisposeATSQuadraticNewPathUPP(userUPP)
#endif
#endif

  /**
    *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(void)
  DisposeATSQuadraticClosePathUPP(ATSQuadraticClosePathUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeATSQuadraticClosePathUPP(ATSQuadraticClosePathUPP) {}
#else
#define DisposeATSQuadraticClosePathUPP(userUPP)
#endif
#endif

  /**
    *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  InvokeATSQuadraticLineUPP(const Float32Point *pt1, const Float32Point *pt2,
                            void *callBackDataPtr, ATSQuadraticLineUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline OSStatus InvokeATSQuadraticLineUPP(const Float32Point *pt1,
                                            const Float32Point *pt2,
                                            void *callBackDataPtr,
                                            ATSQuadraticLineUPP userUPP)
  {
    return (*userUPP)(pt1, pt2, callBackDataPtr);
  }
#else
#define InvokeATSQuadraticLineUPP(pt1, pt2, callBackDataPtr, userUPP) \
  (*userUPP)(pt1, pt2, callBackDataPtr)
#endif
#endif

  /**
    *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  InvokeATSQuadraticCurveUPP(const Float32Point *pt1,
                             const Float32Point *controlPt,
                             const Float32Point *pt2, void *callBackDataPtr,
                             ATSQuadraticCurveUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline OSStatus InvokeATSQuadraticCurveUPP(const Float32Point *pt1,
                                             const Float32Point *controlPt,
                                             const Float32Point *pt2,
                                             void *callBackDataPtr,
                                             ATSQuadraticCurveUPP userUPP)
  {
    return (*userUPP)(pt1, controlPt, pt2, callBackDataPtr);
  }
#else
#define InvokeATSQuadraticCurveUPP(pt1, controlPt, pt2, callBackDataPtr, \
                                   userUPP)                              \
  (*userUPP)(pt1, controlPt, pt2, callBackDataPtr)
#endif
#endif

  /**
    *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  InvokeATSQuadraticNewPathUPP(void *callBackDataPtr,
                               ATSQuadraticNewPathUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline OSStatus InvokeATSQuadraticNewPathUPP(void *callBackDataPtr,
                                               ATSQuadraticNewPathUPP userUPP)
  {
    return (*userUPP)(callBackDataPtr);
  }
#else
#define InvokeATSQuadraticNewPathUPP(callBackDataPtr, userUPP) \
  (*userUPP)(callBackDataPtr)
#endif
#endif

  /**
    *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  InvokeATSQuadraticClosePathUPP(void *callBackDataPtr,
                                 ATSQuadraticClosePathUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline OSStatus
  InvokeATSQuadraticClosePathUPP(void *callBackDataPtr,
                                 ATSQuadraticClosePathUPP userUPP)
  {
    return (*userUPP)(callBackDataPtr);
  }
#else
#define InvokeATSQuadraticClosePathUPP(callBackDataPtr, userUPP) \
  (*userUPP)(callBackDataPtr)
#endif
#endif

  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 9.1 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUGlyphGetQuadraticPaths(ATSUStyle iATSUStyle, GlyphID iGlyphID,
                             ATSQuadraticNewPathUPP iNewPathProc,
                             ATSQuadraticLineUPP iLineProc,
                             ATSQuadraticCurveUPP iCurveProc,
                             ATSQuadraticClosePathUPP iClosePathProc,
                             void *iCallbackDataPtr, OSStatus *oCallbackResult);

  /* ATSUGlyphGetCubicPaths callbacks */
  typedef CALLBACK_API(OSStatus, ATSCubicMoveToProcPtr)(const Float32Point *pt,
                                                        void *callBackDataPtr);
  typedef CALLBACK_API(OSStatus, ATSCubicLineToProcPtr)(const Float32Point *pt,
                                                        void *callBackDataPtr);
  typedef CALLBACK_API(OSStatus, ATSCubicCurveToProcPtr)(const Float32Point *pt1,
                                                         const Float32Point *pt2,
                                                         const Float32Point *pt3,
                                                         void *callBackDataPtr);
  typedef CALLBACK_API(OSStatus, ATSCubicClosePathProcPtr)(void *callBackDataPtr);
  typedef TVECTOR_UPP_TYPE(ATSCubicMoveToProcPtr) ATSCubicMoveToUPP;
  typedef TVECTOR_UPP_TYPE(ATSCubicLineToProcPtr) ATSCubicLineToUPP;
  typedef TVECTOR_UPP_TYPE(ATSCubicCurveToProcPtr) ATSCubicCurveToUPP;
  typedef TVECTOR_UPP_TYPE(ATSCubicClosePathProcPtr) ATSCubicClosePathUPP;
  /**
    *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(ATSCubicMoveToUPP)
  NewATSCubicMoveToUPP(ATSCubicMoveToProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppATSCubicMoveToProcInfo = 0x000003F0
  }; /* pascal 4_bytes Func(4_bytes, 4_bytes) */
#ifdef __cplusplus
  inline ATSCubicMoveToUPP
  NewATSCubicMoveToUPP(ATSCubicMoveToProcPtr userRoutine)
  {
    return userRoutine;
  }
#else
#define NewATSCubicMoveToUPP(userRoutine) (userRoutine)
#endif
#endif

  /**
    *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(ATSCubicLineToUPP)
  NewATSCubicLineToUPP(ATSCubicLineToProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppATSCubicLineToProcInfo = 0x000003F0
  }; /* pascal 4_bytes Func(4_bytes, 4_bytes) */
#ifdef __cplusplus
  inline ATSCubicLineToUPP
  NewATSCubicLineToUPP(ATSCubicLineToProcPtr userRoutine)
  {
    return userRoutine;
  }
#else
#define NewATSCubicLineToUPP(userRoutine) (userRoutine)
#endif
#endif

  /**
    *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(ATSCubicCurveToUPP)
  NewATSCubicCurveToUPP(ATSCubicCurveToProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppATSCubicCurveToProcInfo = 0x00003FF0
  }; /* pascal 4_bytes Func(4_bytes, 4_bytes, 4_bytes, 4_bytes) */
#ifdef __cplusplus
  inline ATSCubicCurveToUPP
  NewATSCubicCurveToUPP(ATSCubicCurveToProcPtr userRoutine)
  {
    return userRoutine;
  }
#else
#define NewATSCubicCurveToUPP(userRoutine) (userRoutine)
#endif
#endif

  /**
    *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(ATSCubicClosePathUPP)
  NewATSCubicClosePathUPP(ATSCubicClosePathProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppATSCubicClosePathProcInfo = 0x000000F0
  }; /* pascal 4_bytes Func(4_bytes) */
#ifdef __cplusplus
  inline ATSCubicClosePathUPP
  NewATSCubicClosePathUPP(ATSCubicClosePathProcPtr userRoutine)
  {
    return userRoutine;
  }
#else
#define NewATSCubicClosePathUPP(userRoutine) (userRoutine)
#endif
#endif

  /**
    *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(void)
  DisposeATSCubicMoveToUPP(ATSCubicMoveToUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeATSCubicMoveToUPP(ATSCubicMoveToUPP) {}
#else
#define DisposeATSCubicMoveToUPP(userUPP)
#endif
#endif

  /**
    *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(void)
  DisposeATSCubicLineToUPP(ATSCubicLineToUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeATSCubicLineToUPP(ATSCubicLineToUPP) {}
#else
#define DisposeATSCubicLineToUPP(userUPP)
#endif
#endif

  /**
    *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(void)
  DisposeATSCubicCurveToUPP(ATSCubicCurveToUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeATSCubicCurveToUPP(ATSCubicCurveToUPP) {}
#else
#define DisposeATSCubicCurveToUPP(userUPP)
#endif
#endif

  /**
    *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(void)
  DisposeATSCubicClosePathUPP(ATSCubicClosePathUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeATSCubicClosePathUPP(ATSCubicClosePathUPP) {}
#else
#define DisposeATSCubicClosePathUPP(userUPP)
#endif
#endif

  /**
    *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  InvokeATSCubicMoveToUPP(const Float32Point *pt, void *callBackDataPtr,
                          ATSCubicMoveToUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline OSStatus InvokeATSCubicMoveToUPP(const Float32Point *pt,
                                          void *callBackDataPtr,
                                          ATSCubicMoveToUPP userUPP)
  {
    return (*userUPP)(pt, callBackDataPtr);
  }
#else
#define InvokeATSCubicMoveToUPP(pt, callBackDataPtr, userUPP) \
  (*userUPP)(pt, callBackDataPtr)
#endif
#endif

  /**
    *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  InvokeATSCubicLineToUPP(const Float32Point *pt, void *callBackDataPtr,
                          ATSCubicLineToUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline OSStatus InvokeATSCubicLineToUPP(const Float32Point *pt,
                                          void *callBackDataPtr,
                                          ATSCubicLineToUPP userUPP)
  {
    return (*userUPP)(pt, callBackDataPtr);
  }
#else
#define InvokeATSCubicLineToUPP(pt, callBackDataPtr, userUPP) \
  (*userUPP)(pt, callBackDataPtr)
#endif
#endif

  /**
    *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  InvokeATSCubicCurveToUPP(const Float32Point *pt1, const Float32Point *pt2,
                           const Float32Point *pt3, void *callBackDataPtr,
                           ATSCubicCurveToUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline OSStatus InvokeATSCubicCurveToUPP(const Float32Point *pt1,
                                           const Float32Point *pt2,
                                           const Float32Point *pt3,
                                           void *callBackDataPtr,
                                           ATSCubicCurveToUPP userUPP)
  {
    return (*userUPP)(pt1, pt2, pt3, callBackDataPtr);
  }
#else
#define InvokeATSCubicCurveToUPP(pt1, pt2, pt3, callBackDataPtr, userUPP) \
  (*userUPP)(pt1, pt2, pt3, callBackDataPtr)
#endif
#endif

  /**
    *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  InvokeATSCubicClosePathUPP(void *callBackDataPtr, ATSCubicClosePathUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline OSStatus InvokeATSCubicClosePathUPP(void *callBackDataPtr,
                                             ATSCubicClosePathUPP userUPP)
  {
    return (*userUPP)(callBackDataPtr);
  }
#else
#define InvokeATSCubicClosePathUPP(callBackDataPtr, userUPP) \
  (*userUPP)(callBackDataPtr)
#endif
#endif

  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 9.1 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUGlyphGetCubicPaths(ATSUStyle iATSUStyle, GlyphID iGlyphID,
                         ATSCubicMoveToUPP iMoveToProc,
                         ATSCubicLineToUPP iLineToProc,
                         ATSCubicCurveToUPP iCurveToProc,
                         ATSCubicClosePathUPP iClosePathProc,
                         void *iCallbackDataPtr, OSStatus *oCallbackResult);

  /**
    *

   *    \non_carbon_cfm   in ATSUnicodeLib 9.1 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUGlyphGetCurvePaths(ATSUStyle iATSUStyle, GlyphID iGlyphID,
                         ByteCount *ioBufferSize, ATSUCurvePaths *oPaths);

  /*************************************************************************/
  /**
    *
   *  Discussion:
   *    By default ATSUI will highlight text by simply inverting the
   *    text. When a user is using gray-scale text this does not always
   *    provide the best appearance. On MacOS 9 gray-scale is available,
   *    but can be turned off by a user.  MacOS X always uses gray-scale.
   *     A better way to highlight gray-scale text is to first paint the
   *    highlight color and then redraw the text.  Begining with version
   *    2.0 (?) of ATSUI this method is available.  However,
   *    unhighlighting text when this technique is used is more
   *    complicated.  The details of exactly what the background looks
   *    like must be known to whoever unhighlights the text. When using
   *    the redraw method of highlighting ATSUI will redraw the
   *    background if it is a single color(e.g. white).  If this is the
   *    case set iMethod to kRedrawToHighlight, set
   *    iUnhighlightData.dataType to kATSUBackgroundColor and specify the
   *    background color in
   *    iUnhighlightData.unhighlightData.backgroundColor.  When these
   *    settings are supplied then ATSUI will calculate the highlight
   *    area paint it with the specified backgroundColor and then redraw
   *    the text. For more complex backgrounds (multiple colors,
   *    patterns, pictures, etc.) you need to supply a callback that
   *    ATSUI will call when the background needs to be repainted (See
   *    above RedrawBackgroundProcPtr ).  When your callback is called
   *    you should redraw the background.  If you choose to also redraw
   *    the text then you should return false as a function result. If
   *    you return true ATSUI will redraw any text that needs to be
   *    redrawn.
   *
   *  Parameters:
   *
   *    iTextLayout:
   *      The layout to which this highlight method should be applied.
   *
   *    iMethod:
   *      The type of highlighting to use (inversion or redrawing) The
   *      default is inversion.  If you are happy with that technique
   *      there is no reason to call this function.
   *
   *    iUnhighlightData:
   *      Data needed to redraw the background or NULL if inversion is
   *      being chosen.
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available in CarbonLib 1.x, is available on Mac OS
   X version 10.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  ATSUSetHighlightingMethod(ATSUTextLayout iTextLayout,
                            ATSUHighlightMethod iMethod,
                            const ATSUUnhighlightData *iUnhighlightData);

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

#endif /* __ATSUNICODE__ */
