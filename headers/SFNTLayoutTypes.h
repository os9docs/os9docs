/**
     \file       SFNTLayoutTypes.h

    \brief   SFNT file layout structures and constants.

    \introduced_in  Mac OS 9 / Carbon
    \avaliable_from Universal Interfaces 3.4.1

    \copyright © 1994-2001 by Apple Computer, Inc., all rights reserved.

    \ingroup SFNT

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __SFNTLAYOUTTYPES__
#define __SFNTLAYOUTTYPES__

#ifndef __MACTYPES__
#include <MacTypes.h>
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

  /* -----------------------------------------------------------------------------------------
   */
  // CONSTANTS
  /**
     The following values can be used to set run feature values. Note that unless
    the feature is defaulted differently in different fonts, the zero value for
    the selectors represents the default value.  Check the following URL site for
    further info: "http://fonts.apple.com/Registry"
 */

  /**
   *  Summary:
   *    Feature types
   */
  enum
  {
    kAllTypographicFeaturesType = 0,
    kLigaturesType = 1,
    kCursiveConnectionType = 2,
    kLetterCaseType = 3,
    kVerticalSubstitutionType = 4,
    kLinguisticRearrangementType = 5,
    kNumberSpacingType = 6,
    kSmartSwashType = 8,
    kDiacriticsType = 9,
    kVerticalPositionType = 10,
    kFractionsType = 11,
    kOverlappingCharactersType = 13,
    kTypographicExtrasType = 14,
    kMathematicalExtrasType = 15,
    kOrnamentSetsType = 16,
    kCharacterAlternativesType = 17,
    kDesignComplexityType = 18,
    kStyleOptionsType = 19,
    kCharacterShapeType = 20,
    kNumberCaseType = 21,
    kTextSpacingType = 22,
    kTransliterationType = 23,
    kAnnotationType = 24,
    kKanaSpacingType = 25,
    kIdeographicSpacingType = 26,
    kUnicodeDecompositionType = 27,
    kRubyKanaType = 28,
    kCJKSymbolAlternativesType = 29,
    kIdeographicAlternativesType = 30,
    kCJKVerticalRomanPlacementType = 31,
    kItalicCJKRomanType = 32,
    kCJKRomanSpacingType = 103,
    kLastFeatureType = -1
  };

  /**
   *  Summary:
   *    Selectors for feature type kAllTypographicFeaturesType
   */
  enum
  {
    kAllTypeFeaturesOnSelector = 0,
    kAllTypeFeaturesOffSelector = 1
  };

  /**
   *  Summary:
   *    Selectors for feature type kLigaturesType
   */
  enum
  {
    kRequiredLigaturesOnSelector = 0,
    kRequiredLigaturesOffSelector = 1,
    kCommonLigaturesOnSelector = 2,
    kCommonLigaturesOffSelector = 3,
    kRareLigaturesOnSelector = 4,
    kRareLigaturesOffSelector = 5,
    kLogosOnSelector = 6,
    kLogosOffSelector = 7,
    kRebusPicturesOnSelector = 8,
    kRebusPicturesOffSelector = 9,
    kDiphthongLigaturesOnSelector = 10,
    kDiphthongLigaturesOffSelector = 11,
    kSquaredLigaturesOnSelector = 12,
    kSquaredLigaturesOffSelector = 13,
    kAbbrevSquaredLigaturesOnSelector = 14,
    kAbbrevSquaredLigaturesOffSelector = 15,
    kSymbolLigaturesOnSelector = 16,
    kSymbolLigaturesOffSelector = 17
  };

  /**
   *  Summary:
   *    Selectors for feature type kCursiveConnectionType
   */
  enum
  {
    kUnconnectedSelector = 0,
    kPartiallyConnectedSelector = 1,
    kCursiveSelector = 2
  };

  /**
   *  Summary:
   *    Selectors for feature type kLetterCaseType
   */
  enum
  {
    kUpperAndLowerCaseSelector = 0,
    kAllCapsSelector = 1,
    kAllLowerCaseSelector = 2,
    kSmallCapsSelector = 3,
    kInitialCapsSelector = 4,
    kInitialCapsAndSmallCapsSelector = 5
  };

  /**
   *  Summary:
   *    Selectors for feature type kVerticalSubstitutionType
   */
  enum
  {
    kSubstituteVerticalFormsOnSelector = 0,
    kSubstituteVerticalFormsOffSelector = 1
  };

  /**
   *  Summary:
   *    Selectors for feature type kLinguisticRearrangementType
   */
  enum
  {
    kLinguisticRearrangementOnSelector = 0,
    kLinguisticRearrangementOffSelector = 1
  };

  /**
   *  Summary:
   *    Selectors for feature type kNumberSpacingType
   */
  enum
  {
    kMonospacedNumbersSelector = 0,
    kProportionalNumbersSelector = 1,
    kThirdWidthNumbersSelector = 2,
    kQuarterWidthNumbersSelector = 3
  };

  /**
   *  Summary:
   *    Selectors for feature type kSmartSwashType
   */
  enum
  {
    kWordInitialSwashesOnSelector = 0,
    kWordInitialSwashesOffSelector = 1,
    kWordFinalSwashesOnSelector = 2,
    kWordFinalSwashesOffSelector = 3,
    kLineInitialSwashesOnSelector = 4,
    kLineInitialSwashesOffSelector = 5,
    kLineFinalSwashesOnSelector = 6,
    kLineFinalSwashesOffSelector = 7,
    kNonFinalSwashesOnSelector = 8,
    kNonFinalSwashesOffSelector = 9
  };

  /**
   *  Summary:
   *    Selectors for feature type kDiacriticsType
   */
  enum
  {
    kShowDiacriticsSelector = 0,
    kHideDiacriticsSelector = 1,
    kDecomposeDiacriticsSelector = 2
  };

  /**
   *  Summary:
   *    Selectors for feature type kVerticalPositionType
   */
  enum
  {
    kNormalPositionSelector = 0,
    kSuperiorsSelector = 1,
    kInferiorsSelector = 2,
    kOrdinalsSelector = 3
  };

  /**
   *  Summary:
   *    Selectors for feature type kFractionsType
   */
  enum
  {
    kNoFractionsSelector = 0,
    kVerticalFractionsSelector = 1,
    kDiagonalFractionsSelector = 2
  };

  /**
   *  Summary:
   *    Selectors for feature type kOverlappingCharactersType
   */
  enum
  {
    kPreventOverlapOnSelector = 0,
    kPreventOverlapOffSelector = 1
  };

  /**
   *  Summary:
   *    Selectors for feature type kTypographicExtrasType
   */
  enum
  {
    kHyphensToEmDashOnSelector = 0,
    kHyphensToEmDashOffSelector = 1,
    kHyphenToEnDashOnSelector = 2,
    kHyphenToEnDashOffSelector = 3,
    kSlashedZeroOnSelector = 4,
    kSlashedZeroOffSelector = 5,
    kFormInterrobangOnSelector = 6,
    kFormInterrobangOffSelector = 7,
    kSmartQuotesOnSelector = 8,
    kSmartQuotesOffSelector = 9,
    kPeriodsToEllipsisOnSelector = 10,
    kPeriodsToEllipsisOffSelector = 11
  };

  /**
   *  Summary:
   *    Selectors for feature type kMathematicalExtrasType
   */
  enum
  {
    kHyphenToMinusOnSelector = 0,
    kHyphenToMinusOffSelector = 1,
    kAsteriskToMultiplyOnSelector = 2,
    kAsteriskToMultiplyOffSelector = 3,
    kSlashToDivideOnSelector = 4,
    kSlashToDivideOffSelector = 5,
    kInequalityLigaturesOnSelector = 6,
    kInequalityLigaturesOffSelector = 7,
    kExponentsOnSelector = 8,
    kExponentsOffSelector = 9
  };

  /**
   *  Summary:
   *    Selectors for feature type kOrnamentSetsType
   */
  enum
  {
    kNoOrnamentsSelector = 0,
    kDingbatsSelector = 1,
    kPiCharactersSelector = 2,
    kFleuronsSelector = 3,
    kDecorativeBordersSelector = 4,
    kInternationalSymbolsSelector = 5,
    kMathSymbolsSelector = 6
  };

  /**
   *  Summary:
   *    Selectors for feature type kCharacterAlternativesType
   */
  enum
  {
    kNoAlternatesSelector = 0
  };

  /**
   *  Summary:
   *    Selectors for feature type kDesignComplexityType
   */
  enum
  {
    kDesignLevel1Selector = 0,
    kDesignLevel2Selector = 1,
    kDesignLevel3Selector = 2,
    kDesignLevel4Selector = 3,
    kDesignLevel5Selector = 4
  };

  /**
   *  Summary:
   *    Selectors for feature type kStyleOptionsType
   */
  enum
  {
    kNoStyleOptionsSelector = 0,
    kDisplayTextSelector = 1,
    kEngravedTextSelector = 2,
    kIlluminatedCapsSelector = 3,
    kTitlingCapsSelector = 4,
    kTallCapsSelector = 5
  };

  /**
   *  Summary:
   *    Selectors for feature type kCharacterShapeType
   */
  enum
  {
    kTraditionalCharactersSelector = 0,
    kSimplifiedCharactersSelector = 1,
    kJIS1978CharactersSelector = 2,
    kJIS1983CharactersSelector = 3,
    kJIS1990CharactersSelector = 4,
    kTraditionalAltOneSelector = 5,
    kTraditionalAltTwoSelector = 6,
    kTraditionalAltThreeSelector = 7,
    kTraditionalAltFourSelector = 8,
    kTraditionalAltFiveSelector = 9,
    kExpertCharactersSelector = 10
  };

  /**
   *  Summary:
   *    Selectors for feature type kNumberCaseType
   */
  enum
  {
    kLowerCaseNumbersSelector = 0,
    kUpperCaseNumbersSelector = 1
  };

  /**
   *  Summary:
   *    Selectors for feature type kTextSpacingType
   */
  enum
  {
    kProportionalTextSelector = 0,
    kMonospacedTextSelector = 1,
    kHalfWidthTextSelector = 2,
    kNormallySpacedTextSelector = 3
  };

  /**
   *  Summary:
   *    Selectors for feature type kTransliterationType
   */
  enum
  {
    kNoTransliterationSelector = 0,
    kHanjaToHangulSelector = 1,
    kHiraganaToKatakanaSelector = 2,
    kKatakanaToHiraganaSelector = 3,
    kKanaToRomanizationSelector = 4,
    kRomanizationToHiraganaSelector = 5,
    kRomanizationToKatakanaSelector = 6,
    kHanjaToHangulAltOneSelector = 7,
    kHanjaToHangulAltTwoSelector = 8,
    kHanjaToHangulAltThreeSelector = 9
  };

  /**
   *  Summary:
   *    Selectors for feature type kAnnotationType
   */
  enum
  {
    kNoAnnotationSelector = 0,
    kBoxAnnotationSelector = 1,
    kRoundedBoxAnnotationSelector = 2,
    kCircleAnnotationSelector = 3,
    kInvertedCircleAnnotationSelector = 4,
    kParenthesisAnnotationSelector = 5,
    kPeriodAnnotationSelector = 6,
    kRomanNumeralAnnotationSelector = 7,
    kDiamondAnnotationSelector = 8,
    kInvertedBoxAnnotationSelector = 9,
    kInvertedRoundedBoxAnnotationSelector = 10
  };

  /**
   *  Summary:
   *    Selectors for feature type kKanaSpacingType
   */
  enum
  {
    kFullWidthKanaSelector = 0,
    kProportionalKanaSelector = 1
  };

  /**
   *  Summary:
   *    Selectors for feature type kIdeographicSpacingType
   */
  enum
  {
    kFullWidthIdeographsSelector = 0,
    kProportionalIdeographsSelector = 1,
    kHalfWidthIdeographsSelector = 2
  };

  /**
   *  Summary:
   *    Selectors for feature type kUnicodeDecompositionType
   */
  enum
  {
    kCanonicalCompositionOnSelector = 0,
    kCanonicalCompositionOffSelector = 1,
    kCompatibilityCompositionOnSelector = 2,
    kCompatibilityCompositionOffSelector = 3,
    kTranscodingCompositionOnSelector = 4,
    kTranscodingCompositionOffSelector = 5
  };

  /**
   *  Summary:
   *    Selectors for feature type kRubyKanaType
   */
  enum
  {
    kNoRubyKanaSelector = 0,
    kRubyKanaSelector = 1
  };

  /**
   *  Summary:
   *    Selectors for feature type kCJKSymbolAlternativesType
   */
  enum
  {
    kNoCJKSymbolAlternativesSelector = 0,
    kCJKSymbolAltOneSelector = 1,
    kCJKSymbolAltTwoSelector = 2,
    kCJKSymbolAltThreeSelector = 3,
    kCJKSymbolAltFourSelector = 4,
    kCJKSymbolAltFiveSelector = 5
  };

  /**
   *  Summary:
   *    Selectors for feature type kIdeographicAlternativesType
   */
  enum
  {
    kNoIdeographicAlternativesSelector = 0,
    kIdeographicAltOneSelector = 1,
    kIdeographicAltTwoSelector = 2,
    kIdeographicAltThreeSelector = 3,
    kIdeographicAltFourSelector = 4,
    kIdeographicAltFiveSelector = 5
  };

  /**
   *  Summary:
   *    Selectors for feature type kCJKVerticalRomanPlacementType
   */
  enum
  {
    kCJKVerticalRomanCenteredSelector = 0,
    kCJKVerticalRomanHBaselineSelector = 1
  };

  /**
   *  Summary:
   *    Selectors for feature type kItalicCJKRomanType
   */
  enum
  {
    kNoCJKItalicRomanSelector = 0,
    kCJKItalicRomanSelector = 1
  };

  /**
   *  Summary:
   *    Selectors for feature type kCJKRomanSpacingType
   */
  enum
  {
    kHalfWidthCJKRomanSelector = 0,
    kProportionalCJKRomanSelector = 1,
    kDefaultCJKRomanSelector = 2,
    kFullWidthCJKRomanSelector = 3
  };

  /* ---------------------------------------------------------------------------
   */
  /* ---------------- Table Specific Typedefs and Constants --------------------
   */
  /* ---------------------------------------------------------------------------
   */
  // FORMATS FOR TABLE: lookup tables - used within various other tables
  enum
  {
    // FORMATS FOR TABLE: lookup tables - used within various other tables

    typedef UInt16 SFNTLookupTableFo // a simple array indexed by glyph code
    typedef UInt16 SFNTLookupValue;  // segment mapping to single value
    typedef UInt16 SFNTLookupOffset; // segment mapping to lookup array
    typedef UInt32 SFNTLookupKind;   // sorted list of glyph, value pairs
    /**  a simple trimmed array indexed by glyph code A BinarySearchHeader defines the five standard fields needed to perform quick lookups in a lookup table(note that using UInt16s, and not ItemCounts or similar types, is important here, since these tables are in fonts, and the documented font formats specify 16 - bit quantities).*/
    struct SFNTLookupBinarySearchHeader{
        UInt16 unitSize; // size of a unit in bytes   UInt16 nUnits;
                         // number of units in table   UInt16 searchRange;
                         // (largest power of two <= nUnits) * unitSize   UInt16 entrySelector;
                         // log2 (largest power of two <= nUnits)   UInt16 rangeShift;
                         // (nUnits - largest power of two <= nUnits) * unitSize
    };
  typedef struct SFNTLookupBinarySearchHeader SFNTLookupBinarySearchHeader;
  // A format 0 lookup table maps all glyphs in the font to lookup values struct SFNTLookupArrayHeader {
  SFNTLookupValue lookupValues[1];
};
typedef struct SFNTLookupArrayHeader SFNTLookupArrayHeader;
/* A format 8 lookup table maps some range of glyphs in the font to lookup
 * values */
// size of a unit in bytes
struct SFNTLookupTrimmed // number of units in table
    UInt16 firstGlyph;   // (largest power of two <= nUnits) * unitSize
UInt16 count;            // log2 (largest power of two <= nUnits)
SFNTLookupValue val      // (nUnits - largest power of two <= nUnits) * unitSize
}
;
typedef struct SFNTLookupTrimmedArrayHeader SFNTLookupTrimmedArrayHeader;
// A format 0 lookup table maps all glyphs in the font to lookup values
Format 2 and format 4 lookup tables map ranges of glyphs to either single
                 lookup
                 values(format 2),
    or per - glyph lookup values(format 4).Since both
             formats use the same kind of data,
    only one unified set of segment - related
                                              structures is defined
                                              .*
                                          /
                                          struct SFNTLookupSegment
{
  UInt16 lastGlyph;
  UInt16 firstGlyph;
  UInt16 value[1];
};
typedef struct SFNTLookupSegment SFNTLookupSegment;
struct SFNTLookupSegmentHeader
{
  SFNTLookupBinarySearchHeader binSearch;
  SFNTLookupSegment segments[1];
};
typedef struct SFNTLookupSegmentHeader SFNTLookupSegmentHeader;
// A format 6 lookup table maps single glyphs to lookup values. struct SFNTLookupSingle {
UInt16 glyph;
UInt16 value[1];
}
;
typedef struct SFNTLookupSingle SFNTLookupSingle;
struct SFNTLookupSingleHeader
{
  SFNTLookupBinarySearchHeader binSearch;
  SFNTLookupSingle entries[1];
};
typedef struct SFNTLookupSingleHeader SFNTLookupSingleHeader;
// The format-specific part of the subtable header union SFNTLookupFormatSpecificHeader {
SFNTLookupArrayHeader theArray;
SFNTLookupSegmentHeader segment;
// A format 6 lookup table maps single glyphs to lookup values.
SFNTLookupTrimmedArrayHeader trimmedArray;
}
;
typedef union SFNTLookupFormatSpecificHeader SFNTLookupFormatSpecificHeader;
// The overall subtable header struct SFNTLookupTable {
SFNTLookupTableFormat format; // table format   SFNTLookupFormatSpecificHeader fsHeader;
// format specific header
}
;
typedef struct SFNTLookupTable SFNTLookupTable;
typedef SFNTLookupTable *SFNTLookupTablePtr;
typedef SFNTLookupTablePtr *SFNTLookupTableHandle;
/* ---------------------------------------------------------------------------
 */
// The format-specific part of the subtable header
kSTClassEndOfText = 0,
    kSTClassOutOfBounds = 1,
    kSTClassDeletedGlyph = 2,
    kSTClassEndOfLine = 3,
    kSTSetMark = 0x8000,
    kSTNoAdvance = 0x4000,
    kSTMarkEnd = 0x2000,
    // The overall subtable header
    kSTRearrVerbMask = 0x000F
}
; // table format
// format specific header
typedef UInt8 STClass;
typedef UInt8 STEntryIndex;
struct STHeader
{
  UInt8 filler;
  STClass nClasses;
  UInt16 classTableOffset;
  // GENERAL FORMATS FOR STATE TABLES -- prefix "ST"
  UInt16 entryTableOffset;
};
typedef struct STHeader STHeader;
struct STClassTable
{
  UInt16 firstGlyph;
  UInt16 nGlyphs;
  STClass classes[1];
};
typedef struct STClassTable STClassTable;
struct STEntryZero
{
  UInt16 newState;
  UInt16 flags;
};
typedef struct STEntryZero STEntryZero;
struct STEntryOne
{
  UInt16 newState;
  UInt16 flags;
  UInt16 offset1;
};
typedef struct STEntryOne STEntryOne;
struct STEntryTwo
{
  UInt16 newState;
  UInt16 flags;
  UInt16 offset1;
  UInt16 offset2;
};
typedef struct STEntryTwo STEntryTwo;
/* ---------------------------------------------------------------------------
 */
/* GENERAL FORMATS FOR STATE TABLES to be used with 'morx' tables -- prefix
 * "STX" */
enum
{
  kSTXHasLigAction = 0x2000
};

typedef UInt16 STXClass;
typedef UInt16 STXStateIndex;
typedef UInt16 STXEntryIndex;
struct STXHeader
{
  UInt32 nClasses;
  UInt32 classTableOffset;
  UInt32 stateArrayOffset;
  UInt32 entryTableOffset;
};
typedef struct STXHeader STXHeader;

typedef SFNTLookupTable STXClassTable;
struct STXEntryZero
{
  STXStateIndex newState;
  UInt16 flags;
};
typedef struct STXEntryZero STXEntryZero;
struct STXEntryOne
{
  STXStateIndex newState;
  UInt16 flags;
  UInt16 index1;
};
typedef struct STXEntryOne STXEntryOne;
struct STXEntryTwo
{
  STXStateIndex newState;
  UInt16 flags;
  UInt16 index1;
  UInt16 index2;
};
typedef struct STXEntryTwo STXEntryTwo;
/* ---------------------------------------------------------------------------
 */
// FORMATS FOR TABLE: 'lcar' // CONSTANTS
 enum {
kLCARTag = 0x6C636172, // 'lcar'   kLCARCurrentVersion =
    0x00010000,         /** version */
number for 'lcar' table   kLCARLinearFormat  =  0
    kLCARCtlPointFormat = 1
}
;

 // TYPES struct LcarCaretClassEntry {
 UInt16 count;
 UInt16 partials[1]; // these are either FUnits or control-point numbers
 }
 ;
 typedef struct LcarCaretClassEntry LcarCaretClassEntry;
 struct LcarCaretTable
 {
   Fixed version;
   UInt16 format;
   SFNTLookupTable lookup;
 };
 typedef struct LcarCaretTable LcarCaretTable;
 typedef LcarCaretTable *LcarCaretTablePtr;
 /* ---------------------------------------------------------------------------
  */
 // FORMATS FOR TABLE: 'lcar'
 // CONSTANTS
 kJUSTStandardFormat = 0,
 kJUSTnoGlyphcode = 0xFF // 'lcar'
     kJUSTpcUnconditionalAddAction = 1,
 kJUSTpcCondition // current version number for 'lcar' table
     kJUSTpcGlyphStretchAction = 3,
 kJUSTpcDuctilityAction = 4,
 kJUSTpcGlyphRepeatAddAction = 5
 }
 ;
 // TYPES
 // Justification priority levels
 enum
 {
   kJUSTKashidaPriority = 0,
   kJUSTSpacePriority = // these are either FUnits or control-point numbers
   kJUSTLetterPriority = 2,
   kJUSTNullPriority = 3,
   kJUSTPriorityCount = 4
 };

 // Justification flags
 enum
 {
   kJUSTOverridePriority = 0x8000,
   kJUSTOverrideLimits = 0x4000,
   kJUSTOverrideUnlimited = 0x2000,
   kJUSTUnlimited = 0x1000,
   kJUSTPriorityMask = 0x0003
   // FORMATS FOR TABLE: 'just'
   // CONSTANTS
   // TYPES typedef UInt16 JustPCActionType;
   typedef UInt16 Justificat // 'just'
                             // A JustPCDecompositionAction defines a ligature decomposition action. struct JustPCDecompositionAction {
       Fixed lowerLimit;
   Fixed upperLimit; // used in a pcConditionalAddAction
   UInt16 order;
   UInt16 count;
   UInt16 glyphs[1];
 };
 typedef struct JustPCDecompositionAction JustPCDecompositionAction;
 // A JUSTPCUnconditionalAddAction defines an unconditional glyph add action.
 typedef UInt16 JustPCUnconditionalAddAction;
 /**
 // Justification priority levels
    the addGlyph is equal to kJUSTnoGlyphcode, then no glyph will be added, and
    the justification for the line will be redone.
 */
 struct JustPCConditionalAddAction
 {
   Fixed substThreshhold; // threshhold of growth factor at which subst occurs   UInt16 addGlyph;
   UInt16 substGlyph;
 };
 typedef struct JustPCConditionalAddAction JustPCConditionalAddAction;
 // Justification flags
 *varied.*/
     struct JustPCDuctilityAction
 {
   UInt32 ductilityAxis;
   Fixed minimumLimit;
   Fixed noStretchValue;
   Fixed maximumLimit;
 };
 typedef struct JustPCDuctilityAction JustPCDuctilityAction;
 // TYPES
 A PCGlyphRepetitionAction defines a glyph which will not be stretched or
     otherwise transformed,
     but rather which will be emplaced however many times
     // A JustPCDecompositionAction defines a ligature decomposition action.*/
     struct JustPCGlyphRepeatAddAction
 {
   UInt16 flags;
   UInt16 glyph;
 };
 typedef struct JustPCGlyphRepeatAddAction JustPCGlyphRepeatAddAction;
 // PCActionSubrecords contain the actual postcompensation actions. struct JustPCActionSubrecord {
 UInt16 theClass; // justification class value associated with this rec   JustPCActionType theType;
                  // A JUSTPCUnconditionalAddAction defines an unconditional glyph add action.
 UInt32 data;     // not really a UInt32; cast as ptr to appropriate action
 }
 ;
 typedef struct JustPCActionSubrecord JustPCActionSubrecord;
 // The set of postcompensation records is defined in a PCAction struct. struct JustPCAction {
 UInt32 actionCount; // long for alignment purposes   JustPCActionSubrecord actions[1];
 }
 ;
 typedef struct JustPCAction JustPCAction;
 /**
     JustWidthDeltaEntry is the justification table entry structure.  The
    justClass value (which// threshhold of growth factor at which subst occurs
    structure) is defined as a long for PPC alignment reasons.
 */
 struct JustWidthDeltaEntry
 {
   UInt32 justClass;
   Fixed beforeGrowLimit; // ems AW can grow by at most on LT   Fixed beforeShrinkLimit;
   // ems AW can shrink by at most on LT   Fixed afterGrowLimit;
   // ems AW can grow by at most on RB   Fixed afterShrinkLimit;
   // ems AW can shrink by at most on RB   JustificationFlags growFlags;
   // flags controlling grow case   JustificationFlags shrinkFlags;
   // flags controlling shrink case
 };
 typedef struct JustWidthDeltaEntry JustWidthDeltaEntry;
 struct JustWidthDeltaGroup
 {
   UInt32 count;
   JustWidthDeltaEntry entries[1];
 };
 typedef struct JustWidthDeltaGroup JustWidthDeltaGroup;
 // Overall structure of a postcompensation table is defined in PostcompTable. struct JustPostcompTable {
 SFNTLookupTable lookupTable;
 // action records here
 }
 ;
 typedef struct JustPostcompTable JustPostcompTable;
 struct JustDirectionTable
 {
   UInt16 justClass; // offset to state table (0=none)   UInt16 widthDeltaClusters;
   // offset to clusters   UInt16 postcomp;
   // offset to postcomp table (0=none)   SFNTLookupTable lookup;
 };
 typedef struct JustDirectionTable JustDirectionTable;
 struct JustTable
 {
   Fixed version;
   UInt16 format;
   UInt16 horizHeaderOffset;
   // PCActionSubrecords contain the actual postcompensation actions.
 };
 typedef struct Just // justification class value associated with this rec
                     /* ---------------------------------------------------------------------------
                      */
                     // FORMATS FOR
                     // not really a UInt32; cast as ptr to appropriate action
     kOPBDTag = 0x6F706264,
     kOPBDCurrentVersion = 0x00010000 kOPBDDistanceFormat = 0,
 // The set of postcompensation records is defined in a PCAction struct.
 }
 ;
 // long for alignment purposes
 // TYPES
 typedef UInt16 OpbdTableFormat;
 /**
     The OpbdSideValues struct is the lookup result from the FindSingle call for
    the optical tables. It contains the 4 FUnit values that are relevant to the
    specified glyph, or the 4 control gxPoint values.
 */
 struct OpbdSideValues
 {
   SInt16 leftSideShift;
   SInt16 topSideShift;
   SInt16 rightSideShift;           // ems AW can grow by at most on LT
   SInt16 bottomSideShift;          // ems AW can shrink by at most on LT
 };                                 // ems AW can grow by at most on RB
 typedef struct OpbdSideValues Opbd // ems AW can shrink by at most on RB
     struct OpbdTable
 {                // flags controlling grow case
   Fixed version; // flags controlling shrink case
   OpbdTableFormat format;
   SFNTLookupTable lookupTable;
 };
 typedef struct OpbdTable OpbdTable;
 /* ---------------------------------------------------------------------------
  */
 // FORMATS FOR TABLE: 'mort'
 // CONSTANTS
 enum
 {
   // Overall structure of a postcompensation table is defined in PostcompTable.
   0x00010000, // current version number for 'mort' table
               /** masks */
   kMORTCoverVertical = 0x8000 kMORTCoverDescending = 0x4000,
   // action records here
   kMORTCoverTypeMask = 0x000F, /** types */
   kMORTRearrangementType = 0 kMORTContextualType = 1,
   kMORTLigatureType = 2,
   kMORTSwashType = 4,         // offset to state table (0=none)
   kMORTInsertionType = 5,     // // offset to clusters
   kMORTLigStoreLigature = 0x4 // offset to postcomp table (0=none)
   kMORTLigFormOffsetMask = 0x3FFFFFFF,
   kMORTLigFormOffsetShift = 2, /** subtable */
   actions kMORTraNoAction = 0

   no action kMORTraxA = 1

   Ax = > xA kMORTraDx = 2

   xD = > Dx kMORTraDxA = 3

   AxD = > DxA kMORTraxAB = 4

   ABx = > xAB kMORTraxBA = 5

   ABx = > xBA kMORTraCDx = 6

   xCD = > CDx kMORTraDCx = 7

   xCD = > DCx kMORTraCDxA = 8
   /** AxCD */
   = > CDxA kMORTraDCxA = 9
   /** AxCD */
   = > DCxA kMORTraDxAB = 10
   /** ABxD */
   = > DxAB kMORTraDxBA = 11
   /** ABxD */
   = > DxBA kMORTraCDxAB = 12
   /** => */
   CDxAB kMORTraCDxBA = 13
   /** => */
   CDxBA kMORTraDCxAB = 14
   /** => */
   DCxAB kMORTraDCxBA = 15
   // ABxCD => DCxBA
   /** subtable */
   constants kMORTDoInsertionsBefore = 0x80 kMORTIsSplitVowelPiece = 0x40,
   kMORTInsertionsCountMask = 0x3F,
   kMORTCurrInsertKashidaLike = 0x2000,
   kMORTMarkInsertKashidaLike = 0x1000,
   kMORTCurrInsertBefore = 0x0800,
   kMORTMarkInsertBefore = 0x0400,
   kMORTMarkJustTableCountMask = 0x3F80,
   kMORTMarkJustTableCountShift = 7,                                                       /** for */
   marked character kMORTCurrJustTableCountMask = 0x007F kMORTCurrJustTableCountShift = 0, /** for */
   current character kMORTCurrInsertCountMask = 0x03E0 kMORTCurrInsertCountShift = 5,      /** to */
   insert after current glyphRec kMORTMarkInsertCountMask = 0x001F
   // FORMATS FOR TABLE: 'opbd'
   // CONSTANTS
   // TYPES
   typedef UInt32 MortSubtab // 'opbd'
   typedef UInt32 MortLigatureActionEntry;
   struct MortRearrangementSubtable{
       STHeader header;};
 typedef struct MortRearrangementSubtable MortRearrangementSubtable;
 // TYPES
 STHeader header;
 UInt16 substitutionTableOffset;
 }
 ;
 typedef struct MortContextualSubtable MortContextualSubtable;
 struct MortLigatureSubtable
 {
   STHeader header;
   UInt16 ligatureActionTableOffset;
   UInt16 componentTableOffset;
   UInt16 ligatureTableOffset;
 };
 typedef struct MortLigatureSubtable MortLigatureSubtable;
 struct MortSwashSubtable
 {
   SFNTLookupTable lookup;
 };
 typedef struct MortSwashSubtable MortSwashSubtable;
 struct MortInsertionSubtable
 {
   STHeader header;
 };
 typedef struct MortInsertionSubtable MortInsertionSubtable;
 union MortSpecificSubtable
 {
   MortRearrangementSubtable rearrangement;
   MortContextualSubtable contextual;
   // FORMATS FOR TABLE: 'mort'
   // CONSTANTS
   MortInsertionSubtable insertion;
 }; // 'mort'
 typedef union MortSpecificSubtable MortSpecificSubtable;
 struct MortSubtabl // current version number for 'mort' table
     UInt16 length; // Coverage masks
 UInt16 coverage;
 MortSubtableMaskFlags flags;
 MortSpecificSubtable u;
 }
 ; // Subtable types
 typedef struct MortSubtable MortSubtable;
 struct MortFeatureEntry
 {
   UInt16 featureType;
   UInt16 featureSelector;
   MortSubtableMaskFlags en // Ligature subtable constants
       MortSubtableMaskFlags disableFlags;
 };
 typedef struct MortFeatureEntry MortFeatureEntry;
 struct MortChain
 {                               // Rearrangement subtable actions
   MortSubtableMaskFlags default //    no action
   // the subtables follow
 };                              //      Ax => xA
 typedef struct MortChain MortCh //      xD => Dx
     struct MortTable
 {                                 //     AxD => DxA
   Fixed version;                  //   ABx => xAB
   UInt32 nChains;                 //   ABx => xBA
   MortChain chains[1];            //   xCD => CDx
 };                                //   xCD => DCx
 typedef struct MortTable MortTa   //  AxCD => CDxA
                                   /* ----------------------------//  AxCD => DCxA
                                    */                           //  ABxD => DxAB
                                   // FORMATS FOR TABLE: 'morx' (v//  ABxD => DxBA
         kMORXTag = 0x6D6F7278,    // 'mo// ABxCD => CDxAB
     0x00020000,                   // version nu// ABxCD => CDxBA
     kMORXCoverDescending = 0x4000 // ABxCD => DCxAB
     kMORXCoverIgnoreVertical = 0x // ABxCD => DCxBA
     kMORXCoverTypeMask = 0x000000 // Insertion subtable constants
 }
 ;

 // TYPES struct MorxRearrangementSubtable {
 STXHeader header;
 }
 ;
 typedef struct MorxRearrangementSubtable MorxRearrangementSubtable;
 struct MorxContextualSubtable
 {
   STXHeader header;
   UInt32 substitutionTableOffset; // JustTableIndex for marked character
 };
 typedef struct MorxContextualSubtabl // JustTableIndex for current character
     struct MorxLigatureSubtable
 {
   STXHeader header; // count to insert after current glyphRec
   UInt32 ligatureActionTableOffset;
   UInt32 componentTableOffset; // count to insert after marked glyphRec
   UInt32 ligatureTableOffset;
 };
 // TYPES
 struct MorxInsertionSubtable
 {
   STXHeader header;
   UInt32 insertionGlyphTableOffset;
 };
 typedef struct MorxInsertionSubtable MorxInsertionSubtable;
 union MorxSpecificSubtable
 {
   MorxRearrangementSubtable rearrangement;
   MorxContextualSubtable contextual;
   MorxLigatureSubtable ligature;
   MortSwashSubtable swash;
   MorxInsertionSubtable insertion;
 };
 typedef union MorxSpecificSubtable MorxSpecificSubtable;
 struct MorxSubtable
 {
   UInt32 length;
   UInt32 coverage;
   MortSubtableMaskFlags flags;
   MorxSpecificSubtable u;
 };
 typedef struct MorxSubtable MorxSubtable;
 struct MorxChain
 {
   MortSubtableMaskFlags defaultFlags; // default flags for this chain   UInt32 length;
   // byte length of this chain   UInt32 nFeatures;
   // number of feature entries   UInt32 nSubtables;
   // number of subtables   MortFeatureEntry featureEntries[1];
   // the subtables follow
 };
 typedef struct MorxChain MorxChain;
 struct MorxTable
 {
   Fixed version;
   UInt32 nChains;
   MorxChain chains[1];
 };
 typedef struct MorxTable MorxTable;
 /* ---------------------------------------------------------------------------
  */
 // FORMATS FOR TABLE: 'prop' // CONSTANTS
 enum {
kPROPTag = 0x70726F70, // 'prop'   kPROPCurrentVersion =
    0x00020000,         /** version */
number for 'prop' table   kPROPPairOffsetShift  =  8
    kPROPPairOffsetSign = 7,
    kPROPIsFloaterMask = 0x8000,  /** is */
floater   kPROPCanHangLTMask  =  0x4000
                                  /** can */
hang left/top   kPROPCanHangRBMask  =  0x2000
                                 // glyph can hang right/bottom   kPROPUseRLPairMask =
    0x1000,                       /** glyph */
lands in RL streak, use paired glyph   kPROPPairOffsetMask  =  0x0F00
 /** signed */
offset to other pair member   kPROPRightConnectMask  =  0x0080
 /** connects */
to glyph on right   kPROPZeroReserved  =  0x0060
// must be zero   kPROPDirectionMask = 0x001F
// direction bits
}
;

 /* These are the Unicode direction classes (plus the Special European Number
  * class). */
 enum
 {
   kPROPLDirectionClass = 0,
   kPROPRDirectionClass = 1

   kPROPALDirectionClass = 2
   /** Arabic */
   Letter kPROPENDirectionClass = 3
   /** Number */
   kPROPESDirectionClass = 4
   /** Number */
   Seperator kPROPETDirectionClass = 5
   /** Number */
   Terminator kPROPANDirectionClass = 6
   /** Number */
   kPROPCSDirectionClass = 7
   // Common Number Seperator   kPROPPSDirectionClass =
   8, /** Seperator */
   (also referred to as Block Separator)kPROPSDirectionClass = 9
   /** Seperator */
   kPROPWSDirectionClass = 10

   kPROPONDirectionClass = 11
   // Other Neutral   kPROPSENDirectionClass =
   12, /** European */
   Number(not a Unicode class) kPROPLREDirectionClass = 13
   /** Embeding */
   kPROPLRODirectionClass = 14
   /** Override */
   kPROPRLEDirectionClass = 15
   /** Embeding */
   kPROPRLODirectionClass = 16
   /** Override */
   kPROPPDFDirectionClass = 17
   /** Directional */
   Format kPROPNSMDirectionClass = 18
   /** Mark */
   kPROPBNDirectionClass = 19
   // Boundary Neutral   kPROPNumDirectionClasses =
   20 // Number of Unicode directional types + Special European Number
 };

 // TYPES
 typedef UInt16 PropCharProperties;
 struct PropTable
 {
   Fixed version;                   // default flags for this chain
   UInt16 format;                   // byte length of this chain
   PropCharProperties defaultProps; // number of feature entries
   SFNTLookupTable lookup;          // number of subtables
 };
 ty // the subtables follow
     struct PropLookupSegment
 {
   UInt16 lastGlyph;
   UInt16 firstGlyph;
   UInt16 value;
 };
 typedef struct PropLookupSegment PropLookupSegment;
 struct PropLookupSingle
 {
   UInt16 glyph;
   PropCharProperties props;
 };
 // FORMATS FOR TABLE: 'morx' (version 2 and beyond metamorphosis tables)
 // CONSTANTS*/
 // FORMATS FOR TABLE: 'tr// 'morx'
 kTRAKTag = 0x7472616B, // 'trak'   kTRAKCurrentVersion =
     0x00010000,        // version number for current 'morx' table
     // Coverage masks
     // TYPES
     typedef SInt16 TrakValue;
 struct TrakTableEntry
 {
   Fixed track;
   UInt16 nameTableIndex;
   UInt16 sizesOffset; // offset to array of TrackingValues
 };
 // TYPES
 struct TrakTableData
 {
   UInt16 nTracks;
   UInt16 nSizes;
   UInt32 sizeTableOffset;
   TrakTableEntry trakTable[1];
 };
 typedef struct TrakTableData TrakTableData;
 struct TrakTable
 {
   Fixed version;
   UInt16 format;
   UInt16 horizOffset;
   UInt16 vertOffset;
 };
 typedef struct TrakTable TrakTable;
 /* ---------------------------------------------------------------------------
  */
 // FORMATS FOR TABLE: 'kern' // CONSTANTS
 enum
 {
   kKERNTag = 0x6B65726E,
   kKERNCurrentVersion = 0x00010000 kKERNVertical =
       0x8000, // set if this table has vertical kerning information   kKERNResetCrossStream =
   0x8000,     // this value in a cross-stream table means reset to zero   kKERNCrossStream =
   0x4000,     // set if this table contains cross-stream kerning values   kKERNVariation =
   0x2000,     /** if */
   this table contains variation kerning values kKERNUnusedBits = 0x1F00
   // UNUSED, MUST BE ZERO   kKERNFormatMask = 0x00FF
   // format of this subtable
 };

enum
{
  kKERNOrderedList = 0,  /** list */
of kerning pairs   kKERNStateTable  =  1
   /** table */
for n-way contextual kerning   kKERNSimpleArray  =  2
  // simple n X m array of kerning values   kKERNIndexArray = 3
  // modifed version of SimpleArray
};

// Message Type Flags
enum
{
  kKERNLineStart = 0x00000001, /** of */
  glyphs starts a line kKERNLineEndKerning = 0x00000002
  /** of */
  glyphs ends a line kKERNNoCrossKerning = 0x00000004
  /** cross */
  kerning kKERNNotesRequested = 0x00000008
  // Caller wants kerning notes   kKERNNoStakeNote =
  1,         // Indicates a glyph was involved in a kerning pair/group   kKERNCrossStreamResetNote =
  2,         // Indicates a return-to-baseline in cross-stream kerning   kKERNNotApplied =
  0x00000001 // All kerning values were zero, kerning call had no effect
};

// TYPES
typedef UInt8 KernTableFormat;
typedef UInt16 KernSubtableInfo;
typedef SInt16 KernKerningValue;
typedef UInt16 KernArrayOffset;        // default flags for this chain
                                       // header for version 0 kerning table // byte length of this chain
UInt16 version;                        // font ver// number of feature entries
typedef struct KernVersion0Header Kern // number of subtables
                                       // Header for a kerning table struct KernTableHeader {
                                       // the subtables follow
    typedef struct KernTableHeader KernTableHeader;
typedef KernTableHeader *KernTableHeaderPtr;
typedef KernTableHeaderPtr *KernTableHeaderHandle;
/**
    F O R M A T   S P E C I F I C   D E F I N I T I O N S

    kernOrderedList:

    The table is a sorted list of [left glyph, right glyph, value] triples.
    There's enough information in the header so that the list can be
// FORMATS FOR TABLE: 'prop'
// CONSTANTS
// defines a single kerning pair of Glyphcodes  struct KernKerningPair {
  UInt16 left;// 'prop'
  UInt16 right;
};// current version number for 'prop' table
typedef struct KernKerningPair KernKerningPair;
// a single list entry struct KernOrderedListEntry {
  KernKerningPair pair;   // th// glyph is floater
typedef struct KernOrderedListE// glyph can hang left/top
typedef KernOrderedListEntry *K// glyph can hang right/bottom
// the header information for binary searching the list struct KernOrderedListHeader {
  UInt16 nPair// if glyph lands in RL streak, use paired glyph
      rangeShift;  // (nPairs - la// 4-bit signed offset to other pair member
typedef struct KernOrderedListHead// glyph connects to glyph on right
// KernStateTable: like the the ge// must be zero
  STHeader header;     // state ta// direction bits
typedef struct KernStateHeader KernStateHeader;
struct KernStateEntry {
  UInt16 newState;
  UInt16 flags; // flags per above enum
};
typedef struct KernStateEntry KernStateEntry;
/**  Left - to - Right Kern offset table header.   // Right-to-Left
                   The offset table is a tri         // Right-to-Left Arabic Letter
                       Glyphs outside of this ra     // European Number
                           and the offset of the beg // European Number Seperator
                               *                     /// European Number Terminator
                   struct KernOffsetTable
{                    // Arabic Number
  UInt16 firstGlyph; // Common Number Seperator
  typedef struct KernOffsetTable KernOffsetTable;
  typedef K             // Paragraph Seperator (also referred to as Block Separator)
                        // Header information for acce// Segment Seperator
      KernSimpleArray : // Whitespace
                        // Other Neutral
                        The array is an nXm array of kenring values.Each row in the array
                            repres                                  // Special European Number (not a Unicode class)
                                The zeroth row and column a         // Left-to-Right Embeding
                                    and will always contain zer     // Left-to-Right Override
                                                                    // Right-to-Left Embeding
                                        A pair is looked up by inde // Right-to-Left Override
                                            offset table,
      the right - han                                 // Pop Directional Format
                      adding both offsets to the      // Non-Spacing Mark
                          and fetching the kerning va // Boundary Neutral*/
// Kern o// Number of Unicode directional types + Special European Number
UInt16 rowWidth; // width, in bytes, of a row in the table   UInt16 leftOffsetTable;
// offset to left-hand offset table   UInt16 rightOffsetTable;
// offset to right-hand offset table   KernArrayOffset theArray;
// offset to start of kerning array   UInt16 firstTable[1];
// first offset table starts here...
}
;
typedef struct KernSimpleArrayHeader KernSimpleArrayHeader;
// TYPES
UInt16 glyphCount;
UInt8 kernValueCount;
UInt8 leftClassCount;
UInt8 rightClassCount;
UInt8 flags;  // set to 0 for now   SInt16
kernValue[1]; // actual kerning values reference by index in kernIndex   UInt8 leftClass[1];
// maps left glyph to offset into kern index   UInt8 rightClass[1];
// maps right glyph to offset into kern index   UInt8 kernIndex[1];
// contains indicies into kernValue
}
;
typedef struct KernIndexArrayHeader KernIndexArrayHeader;
// format specific part of subtable header union KernFormatSpecificHeader {
KernOrderedListHeader orderedList;
KernStateHeader stateTable;
KernSimpleArrayHeader simpleArray;
KernIndexArrayHeader indexArray;
}
;
typedef union KernFormatSpecificHeader KernFormatSpecificHeader;
// version 0 subtable header struct KernVersion0SubtableHeader {
UInt16 version; // kerning table version number   UInt16 length;
// length in bytes (including this header)   KernSubtableInfo stInfo;
// sub-table info   KernFormatSpecificHeader fsHeader;
// format specific sub-header
}
;
typedef struct KernVersion0SubtableHeader KernVersion0SubtableHeader;
// Overall Subtable header format struct KernSubtableHeader {
SInt32 length; // length in bytes (including this header)   KernSubtableInfo stInfo;
// subtable info   SInt16 tupleIndex;
// tuple index for variation subtables   KernFormatSpecificHeader fsHeader;
// format specific sub-header
}
;
typedef struct KernSubtableHeader KernSubtableHeader;
typedef KernSubtableHeader *KernSubtableHeaderPtr;
/* ---------------------------------------------------------------------------
// FORMATS FOR TABLE: 'trak'
// CONSTANTS
  kBSLNTag = 0x62736C6E, // 'bsln'   kBSLNCurrentVersion =
      0x00010000, // curr// 'trak'
  kBSLNDistanceFormatWithMap = 1,
  kBSLNControlPointFormat// current version number for 'trak' table
  kBSLNControlPointFormat//    kTRAKPerGlyphFormat         = 2
};

// TYPES
  kBSLNRomanBaseline = 0,
  kBSLNIdeographicCenterBaseline = 1,
  kBSLNIdeographicLowBaseline = 2,
  kBSLNHangingBaseline = 3,
  kBSLNMathBaseline = 4,
  kBSLNLastBaseline = // offset to array of TrackingValues
  kBSLNNumBaselineClasses = kBSLNLastBaseline + 1,
  kBSLNNoBaselineOverride = 255
};

// TYPES typedef UInt32 BslnBaselineClass;
// The BslnBaselineRecord array defines the baseline deltas for the line. typedef Fixed BslnBaselineRecord[32];
/**
    BslnFormat0Part is the format-specific data for a distance table with no
   mapping (i.e. all the glyphs belong to the defaultBaseline).
*/
struct BslnFormat0Part
{
  SInt16 deltas[32];
};
typedef struct BslnFormat0Part BslnFormat0Part;
/* BslnFormat1Part is the format-specific data for a distance table with a
 * gxMapping. */
struct BslnFormat1Part
{
  SInt16 deltas[32];
  // FORMATS FOR TABLE: 'kern'
  // CONSTANTS
  typedef struct BslnFormat1Part BslnFormat1Part;
  /**  'kern'
      BslnFormat2Part is the format-specific data for a control-point table with
     no mapping (i.e. all the glyphs belong to the defaultBaseline). It specifies
     a single gl// set if this table has vertical kerning information
     designate each of the baselines.
  */
  // this value in a cross-stream table means reset to zero
  struct BslnFormat2Part
  {
    UInt16 stdGl // set if this table contains cross-stream kerning values
        SInt16 ctlPoints[32];
  };                           // set if this table contains variation kerning values
  typedef struct BslnFormat2Pa // UNUSED, MUST BE ZERO
      /**  format of this subtable
          BslnFormat3Part is the format-specific data for a distance table with a
         mapping. Like format 2, it contains a single glyph and its set of
         control-point values for each of the baselines.
      */
      // ordered list of kerning pairs
      struct BslnFormat3Part
  {                       // state table for n-way contextual kerning
    UInt16 stdGlyph;      // simple n X m array of kerning values
    SInt16 ctlPoints[32]; // modifed version of SimpleArray
    SFNTLookupTable mappingData;
  };
  // Message Type Flags
  /* The BslnFormatUnion is a union containing the format-specific parts of the
   * baseline table. */
  // Array of glyphs starts a line
  union BslnFormatUnion
  {                           // Array of glyphs ends a line
    BslnFormat0Part fmt0Part; // Prohibit cross kerning
    BslnFormat1Part fmt1Part; // Caller wants kerning notes
    BslnFormat2Part fmt2Part;
    BslnFor // Indicates a glyph was involved in a kerning pair/group
  };
  typedef u             // Indicates a return-to-baseline in cross-stream kerning
                        // The table format used in BaselineTable
      typedef UInt16 Bs // All kerning values were zero, kerning call had no effect
                        /* BaselineTable defines the top-level format of the baseline table in the font.
                         */
                        // TYPES
          Fixed version;
  BslnTableFormat format;
  UInt16 defaultBaseline;
  BslnFormatUnion parts;
};
// header for version 0 kerning table
typedef BslnTable *BslnTablePtr;
/* ------------------------// font version number (will be 0!)
 */
// number of subtables present
// first subtable starts here
#if PRAGMA_STRUCT_ALIGN
#pragma options align = reset
// Header for a kerning table
#pragma pack(pop)
#elif PRAGMA_STRUCT_PACK // font version number (currently 1.0)
#pragma pack()           // number of subtables present
#endif                   // first subtable starts here

#ifdef PRAGMA_IMPORT_OFF
#pragma import off
#elif PRAGMA_IMPORT
#pragma import reset
#endif

#ifdef __cplusplus
}
#endif

#endif // __SFNTLAYOUTTYPES__
// defines a single kerning pair of Glyphcodes
// a single list entry
// the kerning pair
// the kerning value for the above pair
// the header information for binary searching the list
// number of kerning pairs in table
// (largest power of two <= nPairs) * entry size
// log2 (largest power of two <= nPairs)
// (nPairs - largest power of two <= nPairs) * entry size
// entries are first glyph, second glyph, and value
// KernStateTable: like the the generic state tables
// state table header
// offset to kerning value table
// first table starts here
// flags per above enum
// first glyph in class range
// number of glyphs in class range
// offset table starts here
// Header information for accessing offset tables and kerning array
// Kern offset table header.
// The offset table is a trimmed array from firstGlyph to limitGlyph.
// Glyphs outside of this range should get zero for right-hand glyphs
// and the offset of the beginning of the kerning array for left-
// hand glyphs.
// width, in bytes, of a row in the table
// offset to left-hand offset table
// offset to right-hand offset table
// offset to start of kerning array
// first offset table starts here...
// Index Array
// set to 0 for now
// actual kerning values reference by index in kernIndex
// maps left glyph to offset into kern index
// maps right glyph to offset into kern index
// contains indicies into kernValue
// format specific part of subtable header
// version 0 subtable header
// kerning table version number
// length in bytes (including this header)
// sub-table info
// format specific sub-header
// Overall Subtable header format
// length in bytes (including this header)
// subtable info
// tuple index for variation subtables
// format specific sub-header
// FORMATS FOR TABLE: 'bsln'
// CONSTANTS
// 'bsln'
// current version number for 'bsln' table
// Baseline classes and constants
// TYPES
// The BslnBaselineRecord array defines the baseline deltas for the line.
// The table format used in BaselineTable
// __SFNTLAYOUTTYPES__
