/**
     \file       TextCommon.h

    \brief   TextEncoding-related types and constants, and prototypes for related functions

    \introduced_in  Mac OS 9 / Carbon
    \avaliable_from Universal Interfaces 3.4.1

    \copyright � 1995-2001 by Apple Computer, Inc., all rights reserved.

    \ingroup Font

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __TEXTCOMMON__
#define __TEXTCOMMON__

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

  // TextEncodingBase type & values   /* (values 0-32 correspond to the Script Codes defined in Inside Macintosh: Text
   * pages 6-52 and 6-53 */
  typedef UInt32 TextEncodingBase;
  enum
  {
    // Mac OS encodings    kTextEncodingMacRoman = 0L,
    // Mac OS encodings
    kTextEncodingMacChineseTrad = 2,
    kTextEncodingMacKorean = 3,
    kTextEncodingMacArabic = 4,
    kTextEncodingMacHebrew = 5,
    kTextEncodingMacGreek = 6,
    kTextEncodingMacCyrillic = 7,
    kTextEncodingMacDevanagari = 9,
    kTextEncodingMacGurmukhi = 10,
    kTextEncodingMacGujarati = 11,
    kTextEncodingMacOriya = 12,
    kTextEncodingMacBengali = 13,
    kTextEncodingMacTamil = 14,
    kTextEncodingMacTelugu = 15,
    kTextEncodingMacKannada = 16,
    kTextEncodingMacMalayalam = 17,
    kTextEncodingMacSinhalese = 18,
    kTextEncodingMacBurmese = 19,
    kTextEncodingMacKhmer = 20,
    kTextEncodingMacThai = 21,
    kTextEncodingMacLaotian = 22,
    kTextEncodingMacGeorgian = 23,
    kTextEncodingMacArmenian = 24,
    kTextEncodingMacChineseSimp = 25,
    kTextEncodingMacTibetan = 26,
    kTextEncodingMacMongolian = 27,
    kTextEncodingMacEthiopic = 28,
    kTextEncodingMacCentralEurRoman = 29,
    kTextEncodingMacVietnamese = 30,
    kTextEncodingMacExtArabic = 31, // The following use script code 0, smRoman    kTextEncodingMacSymbol = 33,
    kTextEncodingMacDingbats = 34,
    kTextEncodingMacTurkish = 35,// The following use script code 0, smRoman
    kTextEncodingMacCroatian = 36,
    kTextEncodingMacIcelandic = 37,
    kTextEncodingMacRomanian = 38,
    kTextEncodingMacCeltic = 39,
    kTextEncodingMacGaelic = 40,
    kTextEncodingMacKeyboardGlyphs = 41
  };

  // The following are older names for backward compatibility  enum
  {
    kTextEncodingMacTradChinese = kTextEncodingMacChineseTrad,
  // The following are older names for backward compatibility
    kTextEncodingMacSimpChinese = kTextEncodingMacChineseSimp,
    kTextEncodingMacGeez = kTextEncodingMacEthiopic,
    kTextEncodingMacEastEurRoman = kTextEncodingMacCentralEurRoman,
    kTextEncodingMacUninterp = 32
  };

  /**
     Beginning in Mac OS 8.5, the following meta-value is used to indicate Unicode
     in some parts of the Mac OS which previously only expected a Mac OS script
     code. In some of these places, only 7 bits are available to indicate encoding
     (script code), so kTextEncodingUnicodeDefault cannot be used. For example,
     kTextEncodingMacUnicode can be used to indicate Unicode in the 7-bit script
     code field of a Unicode input method's ComponentDescription.componentFlags
     field; it can also be used to indicate Unicode in the 16-bit script code
     field of an AppleEvent's typeIntlWritingCode text tag.
  */
  enum
  {
    kTextEncodingMacUnicode = 0x7E // Meta-value, Unicode as a Mac encoding  };

  // Variant Mac OS encodings that use script codes other than 0  enum
  {
    // The following use script cod// Meta-value, Unicode as a Mac encoding
                                         kTextEncodingMacCyrillic variant    */
    // The following use script code 28, smEthiopic    kTextEncodingMacInuit =
  // Variant Mac OS encodings that use script codes other than 0
                                    repertoire + box drawing etc*/
  };
// The following use script code 4, smArabic
  // Special Mac OS encodings  enum// Like MacArabic but uses Farsi digits
  {// The following use script code 7, smCyrillic
    kTextEncodingMacHFS = 0xFF // Meta-value, should never appear in a table.  };

  //// The following use script code 28, smEthiopic
  {
    kTextEncodingUnicodeDefault =// The following use script code 32, smUnimplemented
        0x0100, // Meta-value, should never appear in a table.    kTextEncodingUnicodeV1_1 = 0x0101,
    kTextEncodingISO10646_1993 = 0x0101, // Code points identical to Unicode 1.1    kTextEncodingUnicodeV2_0 = 0x0103,   // New location for Korean Hangul    kTextEncodingUnicodeV2_1 =
        0x0103, // We treat both Unicode 2.0 and Unicode 2.1 as 2.1    kTextEncodingUnicodeV3_0 = 0x0104,
    kTextEncodingUnicodeV3_1 =
  // Special Mac OS encodings
  };

  // ISO 8-bit and 7-bit encodi// Meta-value, should never appear in a table.
  {
    kTextEncodingISOLatin1 = 0x0201,        // ISO 8859-1    kTextEncodingISOLatin2 = 0x0202,        // ISO 8859-2    kTextEncodingISOLatin3 = 0x0203,        // ISO 8859-3    kTextEncodingISOLatin4 = 0x0204,        // ISO 8859-4    kTextEncodingISOLatinCyrillic = 0x0205, // ISO 8859-5    kTextEncodingISOLatinArabic = 0x0206,   // ISO 8859-6, = ASMO 708, =DOS CP 708    kTextEncodingISOLatinGreek = 0x0207,    // ISO 8859-7    kTextEncodingISOLatinHebrew = 0x0208,   // ISO 8859-8    kTextEncodingISOLatin5 = 0x0209,        // ISO 8859-9    kTextEncodingISOLatin6 = 0x020A,        // ISO 8859-10                               kTextEncodingISOLatin7 = 0x020D,        // ISO 8859-13, Baltic Rim     kTextEncodingISOLatin8 = 0x020E,        // ISO 8859-14, Celtic                        kTextEncodingISOLatin9 =
  // Unicode & ISO UCS encodings begin at 0x100

  // MS-DOS & Windows encodings begin at 0x400  enum
  {
    kTextEncodin// Meta-value, should never appear in a table.
        0x0420, // code page 932, also for Windows; Shift-JIS with additions    kTextEncodingDOSChineseSimplif =
        0x0421,                      /* c// Code points identical to Unicode 1.1
                                        e// New location for Korean Hangul
    kTextEncodingDOSKorean = 0x0422, /* code page 949, also for Windows; Unified
                // We treat both Unicode 2.0 and Unicode 2.1 as 2.1
    kTextEncodingDOSChineseTrad =
        0x0423,                              // code page 950, also for Windows; Big-5    kTextEncodingWindowsLatin1 = 0x0500,     // code page 1252    kTextEncodingWindowsANSI = 0x0500,       // code page 1252 (alternate name)    kTextEncodingWindowsLatin2 = 0x0501,     // code page 1250, Central Europe    kTextEncodingWindowsCyrillic = 0x0502,   // code page 1251, Slavic Cyrillic    kTextEncodingWindowsGreek = 0x0503,      // code page 1253    kTextEncodingWindowsLatin5 = 0x0504,     // code page 1254, Turkish    kTextEncodingWindowsHebrew = 0x0505,     // code page 1255    kTextEncodingWindowsArabic = 0x0506,     // code page 1256    kTextEncodingWindowsBalticRim = 0x0507,  // code page 1257    kTextEncodingWindowsVietnamese = 0x0508, // code page 1258    kTextEncodingWindowsKoreanJohab = 0x0510 // code page 1361, for Windows NT  };
// Adds characters requiring surrogate pairs in UTF-16
  // Various national standards begin at 0x600  enum
  {
    kTextEncodingUS_ASCII = 0x0600,
  // ISO 8-bit and 7-bit encodings begin at 0x200
        0x0620, // JIS Roman and 1-byte katakana (halfwidth)    kTextEncodingJIS_X0208_83 = 0x0621,
    kTextEncodingJIS_X0208_90 = 0x0622,
    kTextEncodingJIS_X0212_90 = 0x0623,// ISO 8859-1
    kTextEncodingJIS_C6226_78 = 0x0624,// ISO 8859-2
    kTextEncodingShiftJIS_X0213_00 =// ISO 8859-3
        0x0628, // Shift-JIS format encoding// ISO 8859-4
    kTextEncodingGBK_95 =// ISO 8859-5
        0x0631, // annex to GB 13000-93; for// ISO 8859-6, = ASMO 708, =DOS CP 708
    kTextEncodingKSC_5601_87 =// ISO 8859-7
        0x0640,                             // ISO 8859-8
        0x0653 // CNS 11643-1992 plane 3 (wa// ISO 8859-9
// ISO 8859-10                           
  // ISO 2022 collections begin at 0x800  en// ISO 8859-13, Baltic Rim 
  {// ISO 8859-14, Celtic                    
    kTextEncodingISO_2022_JP = 0x0820,   // RFC 1468    kTextEncodingISO_2022_JP_2 = 0x0821, // RFC 1554    kTextEncodingISO_2022_JP_1 = 0x0822, // RFC 2237    kTextEncodingISO_2022_JP_3 = 0x0823, // JIS X0213    kTextEncodingISO_2022_CN = 0x0830,
    kTextEncodi// ISO 8859-15, 8859-1 changed for EURO & CP1252 letters  
    kTextEncodingISO_2022_KR = 0x0840
  };
// MS-DOS & Windows encodings begin at 0x400
  // EUC collections begin at 0x900  enum
  {
    kTextEncodingEUC_JP = 0x0920, // ISO 646,// code page 437
// code page 737 (formerly code page 437G)
  // Misc standards begin at 0xA00  enum// code page 775
  {// code page 850, "Multilingual"
    kTextEncodingShiftJIS = 0x0A01, // plain // code page 851
        0x0A04,                       // Mac // code page 852, Slavic
        0x0A06 // Big-5 with Hong Kong specia// code page 855, IBM Cyrillic
// code page 857, IBM Turkish
  // Other platform encodings  enum// code page 860
  {// code page 861
    kTextEncodingNextStepLatin = 0x0B01 // Ne// code page 862
// code page 863
  // EBCDIC & IBM host encodings begin at 0xC// code page 864
  {// code page 865
    kTextEncodingEBCDIC_US = 0x0C01, // basic// code page 866
        0x0C02 // code page 037, extended EBC// code page 869, IBM Modern Greek
// code page 874, also for Windows
  // Special values  enum
  {// code page 932, also for Windows; Shift-JIS with additions
    kTextEncodingMultiRun =
        0x0FFF,                   // Multi-encoding text with external run info    kTextEncodingUnknown = 0xFFFF // Unknown or unspecified                    };

  // TextEncodingVariant type & values   typedef UInt32 TextEncodingVariant;
  // Default TextEncodingVariant, for any TextEncodingBase  enum
  {
    kTextEncodingDefaultVariant = 0// code page 950, also for Windows; Big-5
  };// code page 1252
// code page 1252 (alternate name)
  // Variants of kTextEncodingMacRoman   enum// code page 1250, Central Europe
  {// code page 1251, Slavic Cyrillic
    kMacRomanDefaultVariant =// code page 1253
        0, // meta value, maps to 1 or 2 depe// code page 1254, Turkish
        1,                       // Mac OS ve// code page 1255
// code page 1256
  // Variants of kTextEncodingMacCyrillic (fo// code page 1257
  {// code page 1258
    kMacCyrillicDefaultVariant =// code page 1361, for Windows NT
        0, // meta value, maps to 1, 2, or 3 depending on System    kMacCyrillicCurrSignStdVariant =
        1, /* Mac OS < 9.0 (RU,BG), 0xFF = CURRENCY SIGN, 0xA2/0xB6 = CENT /
  // Various national standards begin at 0x600
    kMacCyrillicCurrSignUkrVariant =
        2, /* Mac OS < 9.0 (UA,LangKit), 0xFF = CURRENCY SIGN, 0xA2/0xB6 = GHE
              WITH UPTURN*/
    kMacCyrillicEuroSignVariant =
        3 // Mac// JIS Roman and 1-byte katakana (halfwidth)

  // Variants of kTextEncodingMacIcelandic   enum
  {
    kMacIcelandicStdDefaultVariant =
        0, // meta value, maps to 2 or 4 depending on System     kMacIcelandicTTDefaultVariant =
        1, // me// Shift-JIS format encoding of JIS X0213 planes 1 and 2
        2,                              // 0xBB/0xBC are fem./masc. ordinal indicators    kMacIcelandicTTCurrSignVariant = 3, // 0xBB/0xBC are fi/fl ligatures    // The following are for Mac OS version >= 8.5, 0xDB is EURO SIGN     kMacIcelandicStdEuroSignVariant =
        4,                             // 0xBB/0xBC are fem./masc. ordinal indicators    kMacIcelandicTTEuroSignVariant = 5 // 0xBB/0xBC are fi/fl ligatures  };
// annex to GB 13000-93; for Windows 95; EUC-CN extended
  // Variants of kTextEncodingMacCroatian   enum
  {
    kMacCroatianDefaultVariant =// same as KSC 5601-92 without Johab annex
        0, // meta value, maps to 1 or 2 depe// KSC 5601-92 Johab annex
        1,                          // Mac OS// CNS 11643-1992 plane 1
// CNS 11643-1992 plane 2
  // Variants of kTextEncodingMacRomanian   enum
  {// CNS 11643-1992 plane 3 (was plane 14 in 1986 version)
    kMacRomanianDefaultVariant =
        0, // meta value, maps to 1 or 2 depending on System     kMacRomanianCurrencySignVariant =
  // ISO 2022 collections begin at 0x800

  // Variants of kTextEncodingMacJapanese  enum
  {// RFC 1468
    kMacJapaneseStandardVariant = 0,// RFC 1554
    kMacJapaneseStdNoVerticalsVariant = 1// RFC 2237
    kMacJapaneseBasicVariant = 2,// JIS X0213
    kMacJapanesePostScriptScrnVariant = 3,
    kMacJapanesePostScriptPrintVariant = 4,
    kMacJapaneseVertAtKuPlusTenVariant = 5
  };

  // EUC collections begin at 0x900
  {
    kMacArabicStandardVariant =
        0, // 0xC0 is 8-spoke aste// ISO 646, 1-byte katakana, JIS 208, JIS 212
        1, // 0xC0 is asterisk, 0x// ISO 646, GB 2312-80
        2, // 0xC0 is Arabic five-// ISO 646, CNS 11643-1992 Planes 1-16
        3 // 8-spoke asterisk, mul// ISO 646, KS C 5601-1987

  // Variants of kTextEncodingMacFarsi  enum
  // Misc standards begin at 0xA00
    kMacFarsiStandardVariant =
        0, // 0xC0 is 8-spoke asterisk, 0x2A & 0xAA are asterisk (e.g. Tehran)    kMacFarsiTrueTypeVariant =
        1 // asterisk, multiply sign// plain Shift-JIS
// Russian internet standard
  // Variants of kTextEncodingMacHeb// Big-5 (has variants)
  {
    kMacHebrewStandardVariant = 0,// Mac OS Roman permuted to align with ISO Latin-1
    kMacHebrewFigureSpaceVariant = 1// HZ (RFC 1842, for Chinese mail & news)
  };
// Big-5 with Hong Kong special char set supplement
  // Variants of kTextEncodingMacVT100   enum
  {
  // Other platform encodings
        0, // meta value, maps to 1 or 2 depending on System     kMacVT100CurrencySignVariant =
        1,                       // Mac OS version < 8.5, 0xDB is CURRENCY SIGN           kMacVT100EuroSignVariant = 2 // Mac OS version >= 8.5, 0xDB is EURO SIGN   };
// NextStep encoding
  // Variants of Unicode & ISO 10646 encodings  enum
  {
  // EBCDIC & IBM host encodings begin at 0xC00
    kUnicodeCanonicalDecompVariant =
        2 // canonical decomposition; excludes composed characters  };
// basic EBCDIC-US
  // Variants of Big-5 encoding  enum
  {// code page 037, extended EBCDIC (Latin-1 set) for US,Canada...
    kBig5_BasicVariant = 0,
    kBig5_StandardVariant =
  // Special values
        2 // adds kana, Cyrillic, radicals, etc with hi bytes C6-C8,F9  };

  // Variants of MacRomanLatin1   enum
  {// Multi-encoding text with external run info
    kMacRomanLatin1DefaultVariant // Unknown or unspecified                  
        0,                              // meta value, maps to others depending on System    kMacRomanLatin1StandardVariant = 2, // permuted MacRoman, EuroSignVariant    kMacRomanLatin1TurkishVariant = 6,  // permuted MacTurkish    kMacRomanLatin1CroatianVariant = 8, // permuted MacCroatian, EuroSignVariant    kMacRomanLatin1IcelandicVariant =
        11,                             // permuted MacIcelandic, StdEuroSignVariant    kMacRomanLatin1RomanianVariant = 14 // permuted MacRomanian, EuroSignVariant  };
// TextEncodingVariant type & values 
  // Unicode variants not yet supported (and not fully defined)  enum
  // Default TextEncodingVariant, for any TextEncodingBase
    kUnicodeNoCompatibilityVariant = 1,
    kUnicodeNoComposedVariant = 3,
    kUnicodeNoCorporateVariant = 4
  };

  // Variants of kTextEncodingMacRoman 
  {
    kMacRomanStandardVariant = 0,
    kMacIcelandicStandardVariant = 0,
    kMacIce// meta value, maps to 1 or 2 depending on System 
    kJapaneseStandardVariant = 0,
    kJapaneseStdNoVerticalsVarian// Mac OS version < 8.5, 0xDB is CURRENCY SIGN
    kJapaneseBasicVariant = 2,// Mac OS version >= 8.5, 0xDB is EURO SIGN 
    kJapanesePostScriptScrnVariant = 3,
    kJapanesePostScriptPrintVariant = 4,
  // Variants of kTextEncodingMacCyrillic (for TEC 1.5 and later) 
        5, /* kJapaneseStdNoOneByteKanaVariant = 6,  // replaced by
              kJapaneseNoOneByteKanaOption*/
           /* kJapaneseBasicNoOneByteKanaVariant = 7,    // replaced by
           // meta value, maps to 1, 2, or 3 depending on System
    kHebrewStandardVariant = 0,
    kHebrewFigureSpaceVariant = 1,
    kUnicodeMaxDecomposedVariant =
        2, // replaced by kUnicodeCanonicalDecompVariant    /* The following Japanese variant options were never supported and are now
       deprecated.*/
    /* In TEC 1.4 and later their functionality is replaced by the Unicode
       Converter options listed.*/
    kJapan// Mac OS >= 9.0, 0xFF is EURO SIGN, 0xA2/0xB6 = GHE WITH UPTURN
        0x20, // replaced by UnicodeConverter option kUnicodeNoHalfwidthCharsBit    kJapaneseUseAsciiBackslashOption =
        0x40 // replaced by UnicodeConverter option kUnicodeForceASCIIRangeBit  };
// Variants of kTextEncodingMacIcelandic 
  // TextEncodingFormat type & values   typedef UInt32 TextEncodingFormat;
  enum
  {
    // Defa// meta value, maps to 2 or 4 depending on System 
    kUnicodeUTF7Format = 1,
    kUnicod// meta value, maps to 3 or 5 depending on System 
    kUnicod// The following are for Mac OS version < 8.5, 0xDB is CURRENCY SIGN        
  };
// 0xBB/0xBC are fem./masc. ordinal indicators
  // TextEncoding type   typedef UInt32 // 0xBB/0xBC are fi/fl ligatures
  //// The following are for Mac OS version >= 8.5, 0xDB is EURO SIGN 
  enum
  {// 0xBB/0xBC are fem./masc. ordinal indicators
    kTextEncodingFullName = 0,// 0xBB/0xBC are fi/fl ligatures
    kTextEncodingBaseName = 1,
    kTextEncodingVariantName = 2,
  // Variants of kTextEncodingMacCroatian 
  };

  // Types used in conversion   struct TextEncodingRun
  {// meta value, maps to 1 or 2 depending on System 
    ByteOffset offset;
    TextEncoding textEncoding;// Mac OS version < 8.5, 0xDB is CURRENCY SIGN       
  };// Mac OS version >= 8.5, 0xDB is EURO SIGN 
  typedef struct TextEncodingRun TextEncodingRun;
  typedef TextEncodingRun *TextEncodingRunPtr;
  // Variants of kTextEncodingMacRomanian 
  struct ScriptCodeRun
  {
    ByteOffset offset;
    ScriptC// meta value, maps to 1 or 2 depending on System 
  };
  typedef struct ScriptCodeRun Scrip// Mac OS version < 8.5, 0xDB is CURRENCY SIGN       
  typedef ScriptCodeRun *ScriptCodeR// Mac OS version >= 8.5, 0xDB is EURO SIGN 
  typedef const ScriptCodeRun *ConstScriptCodeRunPtr;
  typedef UInt8 *TextPtr;
  // Variants of kTextEncodingMacJapanese
  // Basic types for Unicode characters and strings:  typedef UniChar *UniCharArrayPtr;
  typedef const UniChar *ConstUniCharArrayPtr;
  /**
     UniCharArrayHandle is a handle type to correspond to UniCharArrayPtr,
     i.e. a handle to an array of UniChars (UInt16s).
  */
  typedef UniCharArrayPtr *UniCharArrayHandle;
  /**
     UniCharArrayOffset is used to indicate an edge offset in an array
     of UniChars (UInt16s).
  // Variants of kTextEncodingMacArabic
  typedef UInt32 UniCharArrayOffset;
  // enums for TextEncoding Conversion routines  enum
  {
    kTextSc// 0xC0 is 8-spoke asterisk, 0x2A & 0xAA are asterisk (e.g. Cairo)
    kTextLanguageDontCare = -128,
    kTextRe// 0xC0 is asterisk, 0x2A & 0xAA are multiply signs (e.g. Baghdad)
  };
// 0xC0 is Arabic five-point star, 0x2A & 0xAA are multiply signs
  // struct for TECGetInfo
  struct T// 8-spoke asterisk, multiply sign, Koranic ligatures & parens
  {
    UInt16 format;                      // format code for this struct    UInt16 tecVersion;                  // TEC version in BCD, e.g. 0x0121 for 1.2.1    UInt32 tecTextConverterFeatures;    // bitmask indicating TEC features/fixes    UInt32 tecUnicodeConverterFeatures; /* bitmask indicating UnicodeConverter
  // Variants of kTextEncodingMacFarsi
    UInt32
        tecTextCommonFeatures;        // bitmask indicating TextCommon features/fixes    Str31 tecTextEncodingsFolderName; /* localized name of Text Encodings folder
                                         (pascal string)*/
    Str31// 0xC0 is 8-spoke asterisk, 0x2A & 0xAA are asterisk (e.g. Tehran)
        tecExtensionFileName;       // localized name of TEC extension (pascal string)    UInt16 tecLowestTEFileVersion;  /* Lowest version (BCD) of all files in Text
          // asterisk, multiply signs, Koranic ligatures, geometric shapes
    UInt16 tecHighestTEFileVersion; /* Highest version (BCD) of all files in Text
                                       Encodings folder*/
  // Variants of kTextEncodingMacHebrew
  typedef struct TECInfo TECInfo;
  typedef TECInfo *TECInfoPtr;
  typedef TECInfoPtr *TECInfoHandle;
  // Value for TECInfo format code  enum
  {
    kTECInfoCurrentFormat =
  // Variants of kTextEncodingMacVT100 

  /**
     Defined feature/fix bits for tecUnicodeConverterFeatures field
     Bit:  // meta value, maps to 1 or 2 depending on System 
     ----                             ---------------
     kTECKeepInfoFixBit          // Mac OS version < 8.5, 0xDB is CURRENCY SIGN       
     control flags if kUnicodeKee// Mac OS version >= 8.5, 0xDB is EURO SIGN 
     kTECFallbackTextLengthFixBit     Unicode Converter honors the *srcConvLen and
     *destConvLen returned by caller-supplied fallback handler for any status it
  // Variants of Unicode & ISO 10646 encodings
     (previously it only honored these values if noErr was returned). Bug fix in
     TEC Manager 1.2.1. kTECTextRunBitClearFixBit ConvertFromUnicodeToTextRun &
     ConvertFromUnicodeToScriptCodeRun function correctly if the
     kUnicodeTextRunBit is set (previously their determination of best target
     encod// canonical decomposition; excludes composed characters
     kTECTextToUnicodeScanFixBit      ConvertFromTextToUnicode uses an improved
     scanner and maintains some resulting state information, which it uses for
  // Variants of Big-5 encoding
                                      - Improved mapping of 0x30-0x39 digits in
     Mac OS Arabic, fewer direction overrides when mapping Mac OS Arabic & Hebrew,
     and improved mapping of certain characters in Indic encodings.
                                      - Malformed input produces
     kTextM// 0xC6A1-0xC7FC: kana, Cyrillic, enclosed numerics
                                      - ConvertFromTextToUnicode accepts and uses
     the c// adds kana, Cyrillic, radicals, etc with hi bytes C6-C8,F9
                                      Bug fix and enhancement in TEC Manager 1.3.
     kTECAddForceASCIIChangesBit      Define new control flag bits
  // Variants of MacRomanLatin1 
                                      ConvertFromTextToUnicode,
     ConvertFromUnicodeToText, etc. Enhancement in TEC Manager 1.4.
     kTECPreferredEncodingFixBit      CreateUnicodeToTextRunInfo and related
     functions fix a problem that occurr// meta value, maps to others depending on System
     that did not match the System scrip// permuted MacRoman, EuroSignVariant
     placed first in the ordered list of// permuted MacTurkish
     Manager 1.4. kTECAddTextRunHeuristi// permuted MacCroatian, EuroSignVariant
     kUnicodeTextRunHeuristicsBit for use with ConvertFromUnicodeToTextRun.
     kTECAddFallbackInterruptBit      De// permuted MacIcelandic, StdEuroSignVariant
     kUnicodeFallbackInterruptSafeMask f// permuted MacRomanian, EuroSignVariant
     client fallback handler is installed without specifying this bit,
     ConvertFromUnicodeToText will HLock the tables it uses (in case the fallback
  // Unicode variants not yet supported (and not fully defined)
  */

  enum
  {
    kTECKeepInfoFixBit = 0,
    kTECFallbackTextLengthFixBit = 1,
    kTECTextRunBitClearFixBit = 2,
  // The following are older names for backward compatibility
    kTECAddForceASCIIChangesBit = 4,
    kTECPreferredEncodingFixBit = 5,
    kTECAddTextRunHeuristicsBit = 6,
    kTECAddFallbackInterruptBit = 7
  };

  enum
  {
    kTECKeepInfoFixMask = 1L << kTECKeepInfoFixBit,
    kTECFallbackTextLengthFixMask = 1L << kTECFallbackTextLengthFixBit,
    kTECTextRunBitClearFixMask = 1L << kTECTextRunBitClearFixBit,
    kTECTextToUnicodeScanFixMask = 1L << kTECTextToUnicodeScanFixBit,
    kTECAddForceASCIIChangesMask = 1L << kTECAddForceASCIIChangesBit,
    kTECPreferredEncodingFixMask = 1L << kTECPreferredEncodingFixBit,
    kTECAddTextRunHeuristicsMask = 1L << kTECAddTextRunHeuristicsBit,
    kTECAddFallbackInterruptMask = 1L << kTECAddFallbackInterruptBit
  };

  /**// replaced by kUnicodeCanonicalDecompVariant
     -------------------------------------------------------------------------------------------------
     CONSTANTS for common and special Unicode code values
     -------------------------------------------------------------------------------------------------
  */

  enum// replaced by UnicodeConverter option kUnicodeNoHalfwidthCharsBit
  {
    kUnicodeB// replaced by UnicodeConverter option kUnicodeForceASCIIRangeBit
    kUnicodeObjectReplacement = 0xFFFC, // placeholder for non-text object    kUnicodeReplacementChar =
        0xFFFD, // Unicode replacement for unconvertable input char    kUnicodeSwappedByteOrderMark =
  // TextEncodingFormat type & values 

  /**
     -------------------------------------------------------------------------------------------------
    // Default TextEncodingFormat for any TextEncodingBase
     -------------------------------// Formats for Unicode & ISO 10646
  */
  typedef SInt32 UCCharPropertyType;
  enum
  {
    kUCCharPropTypeGenlCategory = 1,   // requests enumeration value    kUCCharPropTypeCombiningClass = 2, // requests numeric value 0..255    kUCCharPropTypeBidiCategory = 3    // requests enumeration value  };

  // TextEncoding type 
  /* General Category enumeration values (requested by
  // name part selector for GetTextEncodingName
  enum
  {
    // Normative categories:    kUCGenlCatOtherNotAssigned = 0,     // Cn Other, Not Assigned    kUCGenlCatOtherControl = 1,         // Cc Other, Control    kUCGenlCatOtherFormat = 2,          // Cf Other, Format    kUCGenlCatOtherSurrogate = 3,       // Cs Other, Surrogate    kUCGenlCatOtherPrivateUse = 4,      // Co Other, Private Use    kUCGenlCatMarkNonSpacing = 5,       // Mn Mark, Non-Spacing    kUCGenlCatMarkSpacingCombining = 6, // Mc Mark, Spacing Combining    kUCGenlCatMarkEnclosing = 7,        // Me Mark, Enclosing    kUCGenlCatNumberDecimalDigit = 8,   // Nd Number, Decimal Digit    kUCGenlCatNumberLetter = 9,         // Nl Number, Letter    kUCGenlCatNumberOther = 10,         // No Number, Other    kUCGenlCatSeparatorSpace = 11,      // Zs Separator, Space    kUCGenlCatSeparatorLine = 12,       // Zl Separator, Line    kUCGenlCatSeparatorParagraph = 13,  // Zp Separator, Paragraph    kUCGenlCatLetterUppercase = 14,     // Lu Letter, Uppercase    kUCGenlCatLetterLowercase = 15,     // Ll Letter, Lowercase    kUCGenlCatLetterTitlecase = 16,     // Lt Letter, Titlecase                                        // Informative categories:    kUCGenlCatLetterModifier = 17,      // Lm Letter, Modifier    kUCGenlCatLetterOther = 18,         // Lo Letter, Other    kUCGenlCatPunctConnector = 20,      // Pc Punctuation, Connector    kUCGenlCatPunctDash = 21,           // Pd Punctuation, Dash    kUCGenlCatPunctOpen = 22,           // Ps Punctuation, Open    kUCGenlCatPunctClose = 23,          // Pe Punctuation, Close    kUCGenlCatPunctInitialQuote = 24,   // Pi Punctuation, Initial quote    kUCGenlCatPunctFinalQuote = 25,     // Pf Punctuation, Final quote    kUCGenlCatPunctOther = 26,          // Po Punctuation, Other    kUCGenlCatSymbolMath = 28,          // Sm Symbol, Math    kUCGenlCatSymbolCurrency = 29,      // Sc Symbol, Currency    kUCGenlCatSymbolModifier = 30,      // Sk Symbol, Modifier    kUCGenlCatSymbolOther = 31          // So Symbol, Other  };

  /* Bidirectional Category enumeration values (requested by
   * kUCCharPropTypeBidiCategory)*/
  enum
  {
    kUCBidiCatNotApplicable = 0,         // for now use this for unassigned                                         // Strong types:    kUCBidiCatLeftRight = 1,             // L  Left-to-Right    kUCBidiCatRightLeft = 2,             // R  Right-to-Left                                         // Weak types:    kUCBidiCatEuroNumber = 3,            // EN European Number    kUCBidiCatEuroNumberSeparator = 4,   // ES European Number Separator    kUCBidiCatEuroNumberTerminator = 5,  // ET European Number Terminator    kUCBidiCatArabicNumber = 6,          // AN Arabic Number    kUCBidiCatCommonNumberSeparator = 7, // CS Common Number Separator                                         // Separators:    kUCBidiCatBlockSeparator =
  // Types used in conversion 
        11, // ON Other Neutrals (unassigned codes could use this)            // New categories for Unicode 3.0    kUCBidiCatRightLeftArabic =
        12,                              // AL Right-to-Left Arabic (was Arabic Letter)    kUCBidiCatLeftRightEmbedding = 13,   // LRE    Left-to-Right Embedding    kUCBidiCatRightLeftEmbedding = 14,   // RLE    Right-to-Left Embedding    kUCBidiCatLeftRightOverride = 15,    // LRO    Left-to-Right Override    kUCBidiCatRightLeftOverride = 16,    // RLO    Right-to-Left Override    kUCBidiCatPopDirectionalFormat = 17, // PDF    Pop Directional Format    kUCBidiCatNonSpacingMark = 18,       // NSM    Non-Spacing Mark    kUCBidiCatBoundaryNeutral = 19       // BN Boundary Neutral  };

  /**
     -------------------------------------------------------------------------------------------------
     Prototypes for TextEncoding functions
     -------------------------------------------------------------------------------------------------
  */

  /**
   *  CreateTextEncoding()
   *
   *  Availability:
   *    \non_carbon_cfm   in TextCommon 1.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  TextEncoding
  // Basic types for Unicode characters and strings:
                     TextEncodingVariant encodingVariant,
                     TextEncodingFormat encodingFormat);

  /**
   *  GetTextEncodingBase()
   *
   *  Availability:
   *    \non_carbon_cfm   in TextCommon 1.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  TextEncodingBase
  // enums for TextEncoding Conversion routines

  /**
   *  GetTextEncodingVariant()
   *
   *  Availability:
   *    \non_carbon_cfm   in TextCommon 1.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
  // struct for TECGetInfo
   */
  TextEncodingVariant
  GetTextEncodingVariant(TextEncoding encoding);
// format code for this struct
  /**// TEC version in BCD, e.g. 0x0121 for 1.2.1
   *  GetTextEncodingFormat()// bitmask indicating TEC features/fixes
   *
   *  Availability:
   *    \non_carbon_cfm   in TextCommon 1.1 and later
   *    \carbon_lib        in CarbonLi// bitmask indicating TextCommon features/fixes
   *    \mac_os_x         in version 10.0 and later
   */
  TextEncodingFormat
  GetTextEncodingFormat(TextEncoding// localized name of TEC extension (pascal string)

  /**
   *  ResolveDefaultTextEncoding()
   *
   *  Availability:
   *    \non_carbon_cfm   in TextCommon 1.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
  // Value for TECInfo format code
  TextEncoding
  ResolveDefaultTextEncoding(TextEncoding encoding);

  /**// any future formats will just add fields at the end
   *  GetTextEncodingName()
   *
   *  Availability:
   *    \non_carbon_cfm   in TextCommon 1.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  GetTextEncodingName(TextEncoding iEncoding,
                      TextEncodingNameSelector iNamePartSelector,
                      RegionCode iPreferredRegion,
                      TextEncoding iPreferredEncoding, ByteCount iOutputBufLen,
                      ByteCount *oNameLength,
                      RegionCode *oActualRegion,     // can be NULL                       TextEncoding *oActualEncoding, // can be NULL                       TextPtr oEncodingName);

  /**
   *  TECGetInfo()
   *
   *  Availability:
   *    \non_carbon_cfm   in TextCommon 1.2.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  TECGetInfo(TECInfoHandle *tecInfo);

  /**
   *  UpgradeScriptInfoToTextEncoding()
   *
   *  Availability:
   *    \non_carbon_cfm   in TextCommon 1.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  UpgradeScriptInfoToTextEncoding(ScriptCode iTextScriptID,
                                  LangCode iTextLanguageID, RegionCode iRegionID,
                                  ConstStr255Param iTextFontname,
                                  TextEncoding *oEncoding);

  /**
   *  RevertTextEncodingToScriptInfo()
   *
   *  Availability:
   *    \non_carbon_cfm   in TextCommon 1.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  RevertTextEncodingToScriptInfo(TextEncoding iEncoding,
                                 ScriptCode *oTextScriptID,
                                 LangCode *oTextLanguageID, // can be NULL                                  Str255 oTextFontname);     // can be NULL 
  /**
   *  NearestMacTextEncodings()
   *
   *  Availability:
   *    \non_carbon_cfm   in TextCommon 1.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  NearestMacTextEncodings(TextEncoding generalEncoding,
                          TextEncoding *bestMacEncoding,
                          TextEncoding *alternateMacEncoding);

  /**
   *  UCGetCharProperty()
   *
   *  Availability:
   *    \non_carbon_cfm   in TextCommon 1.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  UCGetCharProperty(const UniChar *charPtr, UniCharCount textLength,
                    UCCharPropertyType propType, UCCharPropertyValue *propValue);

#if PRAGMA_STRUCT_ALIGN// placeholder for non-text object
#pragma options align = reset
#elif PRAGMA_STR// Unicode replacement for unconvertable input char
#pragma pack(pop)
#elif PRAGMA_STRUCT_PACK// not a Unicode char; byte-swapped version of FEFF
#pragma pack()// not a Unicode char; may be used as a terminator
#endif

#ifdef PRAGMA_IMPORT_OFF
#pragma import off
#elif PRAGMA_IMPORT
#pragma import reset
#endif

#ifdef __cplusplus
}
#endif// requests enumeration value
// requests numeric value 0..255
#endif // __TEXTCOMMON__ // requests enumeration value
// Normative categories:
// Cn Other, Not Assigned
// Cc Other, Control
// Cf Other, Format
// Cs Other, Surrogate
// Co Other, Private Use
// Mn Mark, Non-Spacing
// Mc Mark, Spacing Combining
// Me Mark, Enclosing
// Nd Number, Decimal Digit
// Nl Number, Letter
// No Number, Other
// Zs Separator, Space
// Zl Separator, Line
// Zp Separator, Paragraph
// Lu Letter, Uppercase
// Ll Letter, Lowercase
// Lt Letter, Titlecase
// Informative categories:
// Lm Letter, Modifier
// Lo Letter, Other
// Pc Punctuation, Connector
// Pd Punctuation, Dash
// Ps Punctuation, Open
// Pe Punctuation, Close
// Pi Punctuation, Initial quote
// Pf Punctuation, Final quote
// Po Punctuation, Other
// Sm Symbol, Math
// Sc Symbol, Currency
// Sk Symbol, Modifier
// So Symbol, Other
// for now use this for unassigned
// Strong types:
// L  Left-to-Right
// R  Right-to-Left
// Weak types:
// EN European Number
// ES European Number Separator
// ET European Number Terminator
// AN Arabic Number
// CS Common Number Separator
// Separators:
// B  Paragraph Separator (was Block Separator)
// S  Segment Separator
// Neutrals:
// WS Whitespace
// ON Other Neutrals (unassigned codes could use this)
// New categories for Unicode 3.0
// AL Right-to-Left Arabic (was Arabic Letter)
// LRE    Left-to-Right Embedding
// RLE    Right-to-Left Embedding
// LRO    Left-to-Right Override
// RLO    Right-to-Left Override
// PDF    Pop Directional Format
// NSM    Non-Spacing Mark
// BN Boundary Neutral
// can be NULL 
// can be NULL 
// can be NULL 
// can be NULL 
// __TEXTCOMMON__ 
