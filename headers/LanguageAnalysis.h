/**
     \file       LanguageAnalysis.h

    \brief   Language Analysis Manager Interfaces

    \introduced_in  Mac OS 8
    \avaliable_from Universal Interfaces 3.4.1

    \copyright © 1996-2001 by Apple Computer, Inc., all rights reserved

    \ingroup Misc

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __LANGUAGEANALYSIS__
#define __LANGUAGEANALYSIS__

#ifndef __MACTYPES__
#include <MacTypes.h>
#endif

#ifndef __FILES__
#include <Files.h>
#endif

#ifndef __AEREGISTRY__
#include <AERegistry.h>
#endif

#ifndef __DICTIONARY__
#include <Dictionary.h>
#endif

#ifndef __TEXTCOMMON__
#include <TextCommon.h>
#endif

#ifndef __MACERRORS__
#include <MacErrors.h>
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
#pragma options align = power
#elif PRAGMA_STRUCT_PACKPUSH
#pragma pack(push, 2)
#elif PRAGMA_STRUCT_PACK
#pragma pack(2)
#endif

  typedef struct OpaqueLAEnvironmentRef *LAEnvironmentRef;
  typedef struct OpaqueLAContextRef *LAContextRef;
  typedef AEKeyword LAPropertyKey;
  typedef DescType LAPropertyType;
  /**
      Data structure for high level API
  */
  struct LAMorphemeRec
  {
    ByteCount sourceTextLength;
    LogicalAddress sourceTextPtr;
    ByteCount morphemeTextLength;
    LogicalAddress morphemeTextPtr;
    UInt32 partOfSpeech;
  };
  typedef struct LAMorphemeRec LAMorphemeRec;
  struct LAMorphemesArray
  {
    ItemCount morphemesCount;
    ByteCount processedTextLength;
    ByteCount morphemesTextLength;
    LAMorphemeRec morphemes[1];
  };
  typedef struct LAMorphemesArray LAMorphemesArray;
  typedef LAMorphemesArray *LAMorphemesArrayPtr;
  enum
  {
    kLAMorphemesArrayVersion = 0
  };

  /**
      Definitions for result path/bundle structure
  */
  typedef AERecord LAMorphemeBundle;
  typedef AERecord LAMorphemePath;
  typedef AERecord LAMorpheme;
  typedef AERecord LAHomograph;
  enum
  {
    keyAELAMorphemeBundle = FOUR_CHAR_CODE('lmfb'),
    keyAELAMorphemePath = FOUR_CHAR_CODE('lmfp'),
    keyAELAMorpheme = FOUR_CHAR_CODE('lmfn'),
    keyAELAHomograph = FOUR_CHAR_CODE('lmfh')
  };

  enum
  {
    typeLAMorphemeBundle = typeAERecord,
    typeLAMorphemePath = typeAERecord,
    typeLAMorpheme = typeAEList,
    typeLAHomograph = typeAEList
  };

  /**
      Definitions for morpheme/homograph information
  */
  enum
  {
    keyAEMorphemePartOfSpeechCode = FOUR_CHAR_CODE('lamc'),
    keyAEMorphemeTextRange = FOUR_CHAR_CODE('lamt')
  };

  enum
  {
    typeAEMorphemePartOfSpeechCode = FOUR_CHAR_CODE('lamc'),
    typeAEMorphemeTextRange = FOUR_CHAR_CODE('lamt')
  };

  typedef UInt32 MorphemePartOfSpeech;
  struct MorphemeTextRange
  {
    UInt32 sourceOffset;
    UInt32 length;
  };
  typedef struct MorphemeTextRange MorphemeTextRange;
  /**
      Mask for High level API convert flags
  */
  enum
  {
    kLAEndOfSourceTextMask = 0x00000001
  };

  /**
      Constants for leading/trailing path of analysis function
  */
  enum
  {
    kLADefaultEdge = 0,
    kLAFreeEdge = 1,
    kLAIncompleteEdge = 2
  };

  /**
      Constants for confirm and shift function
  */
  enum
  {
    kLAAllMorphemes = 0
  };

  /**
      Library version
  */
  /**
   *  LALibraryVersion()
   *

   *    \non_carbon_cfm   in LanguageAnalysisLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  UInt32
  LALibraryVersion(void);

  /**
      High level API
  */
  /**
   *  LATextToMorphemes()
   *

   *    \non_carbon_cfm   in LanguageAnalysisLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  LATextToMorphemes(LAContextRef context, TextEncoding preferedEncoding,
                    ByteCount textLength, ConstLogicalAddress sourceText,
                    ByteCount bufferSize, OptionBits convertFlags,
                    UInt32 structureVersion, ByteCount *acceptedLength,
                    LAMorphemesArrayPtr resultBuffer);

  /**
      Handling Context
  */
  /**
   *  LAOpenAnalysisContext()
   *

   *    \non_carbon_cfm   in LanguageAnalysisLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  LAOpenAnalysisContext(LAEnvironmentRef environ, LAContextRef *context);

  /**
   *  LACloseAnalysisContext()
   *

   *    \non_carbon_cfm   in LanguageAnalysisLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  LACloseAnalysisContext(LAContextRef context);

  /**
      Handling Environment
  */
  /**
   *  LAGetEnvironmentList()
   *

   *    \non_carbon_cfm   in LanguageAnalysisLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  LAGetEnvironmentList(UInt32 maxCount, UInt32 *actualCount,
                       LAEnvironmentRef environmentList[]);

  /**
   *  LAGetEnvironmentName()
   *

   *    \non_carbon_cfm   in LanguageAnalysisLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  LAGetEnvironmentName(LAEnvironmentRef environment, Str63 environmentName);

  /**
   *  LAGetEnvironmentRef()
   *

   *    \non_carbon_cfm   in LanguageAnalysisLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  LAGetEnvironmentRef(ConstStr63Param targetEnvironmentName,
                      LAEnvironmentRef *environment);

  /**
   *  LACreateCustomEnvironment()
   *

   *    \non_carbon_cfm   in LanguageAnalysisLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  LACreateCustomEnvironment(LAEnvironmentRef baseEnvironment,
                            ConstStr63Param newEnvironmentName,
                            Boolean persistent, LAEnvironmentRef *newEnvironment);

  /**
   *  LADeleteCustomEnvironment()
   *

   *    \non_carbon_cfm   in LanguageAnalysisLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  LADeleteCustomEnvironment(LAEnvironmentRef environment);

  /**
      Handling dictionries
  */
  /**
   *  LAOpenDictionary()
   *

   *    \non_carbon_cfm   in LanguageAnalysisLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  LAOpenDictionary(LAEnvironmentRef environ, const FSSpec *dictionary);

  /**
   *  LACloseDictionary()
   *

   *    \non_carbon_cfm   in LanguageAnalysisLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  LACloseDictionary(LAEnvironmentRef environ, const FSSpec *dictionary);

  /**
   *  LAListAvailableDictionaries()
   *

   *    \non_carbon_cfm   in LanguageAnalysisLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  LAListAvailableDictionaries(LAEnvironmentRef environ, ItemCount maxCount,
                              ItemCount *actualCount, FSSpec dictionaryList[],
                              Boolean opened[]);

  /**
   *  LAAddNewWord()
   *

   *    \non_carbon_cfm   in LanguageAnalysisLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  LAAddNewWord(LAEnvironmentRef environ, const FSSpec *dictionary,
               const AEDesc *dataList);

  /**
      Analyzing text
  */
  /**
   *  LAMorphemeAnalysis()
   *

   *    \non_carbon_cfm   in LanguageAnalysisLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  LAMorphemeAnalysis(LAContextRef context, ConstUniCharArrayPtr text,
                     UniCharCount textLength, LAMorphemePath *leadingPath,
                     LAMorphemePath *trailingPath, ItemCount pathCount,
                     LAMorphemeBundle *result);

  /**
   *  LAContinuousMorphemeAnalysis()
   *

   *    \non_carbon_cfm   in LanguageAnalysisLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  LAContinuousMorphemeAnalysis(LAContextRef context, ConstUniCharArrayPtr text,
                               UniCharCount textLength, Boolean incrementalText,
                               LAMorphemePath *leadingPath,
                               LAMorphemePath *trailingPath, Boolean *modified);

  /**
   *  LAGetMorphemes()
   *

   *    \non_carbon_cfm   in LanguageAnalysisLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  LAGetMorphemes(LAContextRef context, LAMorphemePath *result);

  /**
   *  LAShiftMorphemes()
   *

   *    \non_carbon_cfm   in LanguageAnalysisLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  LAShiftMorphemes(LAContextRef context, ItemCount morphemeCount,
                   LAMorphemePath *path, UniCharCount *shiftedLength);

  /**
   *  LAResetAnalysis()
   *

   *    \non_carbon_cfm   in LanguageAnalysisLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  LAResetAnalysis(LAContextRef context);

/**
    Check Language Analysis Manager availability
*/
#if TARGET_RT_MAC_CFM
#ifdef __cplusplus
  inline pascal Boolean LALanguageAnalysisAvailable()
  {
    return (LALibraryVersion != (void *)kUnresolvedCFragSymbolAddress);
  }
#else
#define LALanguageAnalysisAvailable()   ((LALibraryVersion != (void*)kUnresolvedCFragSymbolAddress)
#endif
#elif TARGET_RT_MAC_MACHO
// Language Analysis Manager is always available on OS X #ifdef __cplusplus
inline pascal Boolean LALanguageAnalysisAvailable() { return true; }
#else
#define LALanguageAnalysisAvailable() (true)
#endif
#endif //
/**
=============================================================================================
    Definitions for Japanese Analysis Module
=============================================================================================
*/
/**
    Names for default environments for Japanese analysis
*/
#define kLAJapaneseKanaKanjiEnvironment "\pKanaKanjiConversion"
#define kLAJapaneseMorphemeAnalysisEnvironment "\pJapaneseMorphemeAnalysis"
#define kLAJapaneseTTSEnvironment "\pJapaneseTextToSpeech"
  /**
      File cretor for dictionary of Apple Japanese access method
  */
  enum
  {
    kAppleJapaneseDictionarySignature = FOUR_CHAR_CODE('jlan')
  };

  /**
      Engine limitations
  */
  enum
  {
    kMaxInputLengthOfAppleJapaneseEngine = 200
  };

  /**
      Definitions of information in the path/bundle
  */

  typedef MorphemePartOfSpeech JapanesePartOfSpeech;
  typedef UInt16 HomographWeight;
  typedef UInt8 HomographAccent;
  /**
      AE keywords and type definitions for morpheme/homograph information
  */
  enum
  {
    keyAEHomographDicInfo = FOUR_CHAR_CODE('lahd'),
    keyAEHomographWeight = FOUR_CHAR_CODE('lahw'),
    keyAEHomographAccent = FOUR_CHAR_CODE('laha')
  };

  enum
  {
    typeAEHomographDicInfo = FOUR_CHAR_CODE('lahd'),
    typeAEHomographWeight = typeShortInteger,
    typeAEHomographAccent = FOUR_CHAR_CODE('laha')
  };

  /**
      Structure for dictionary information of homograph
  */
  struct HomographDicInfoRec
  {
    DCMDictionaryID dictionaryID;
    DCMUniqueID uniqueID;
  };
  typedef struct HomographDicInfoRec HomographDicInfoRec;
  /**
  =============================================================================================
      Definitions for Japanese part of speeches
  =============================================================================================
  */
  /**
      Masks for part of speeches
  */
  enum
  {
    kLASpeechRoughClassMask = 0x0000F000,
    kLASpeechMediumClassMask = 0x0000FF00,
    kLASpeechStrictClassMask = 0x0000FFF0,
    kLASpeechKatsuyouMask = 0x0000000F
  };

  /**
      Part of speeches
  */
  enum
  {
    kLASpeechMeishi = 0x00000000,
    kLASpeechFutsuuMeishi = 0x00000000           /** noun */
    kLASpeechJinmei = 0x00000100                 /** name */
    kLASpeechJinmeiSei = 0x00000110              /** name */
    kLASpeechJinmeiMei = 0x00000120              /** name */
    kLASpeechChimei = 0x00000200                 /** name */
    kLASpeechSetsubiChimei = 0x00000210          /** name */
    with suffix kLASpeechSoshikimei = 0x00000300 /** name */
    kLASpeechKoyuuMeishi = 0x00000400            /** noun */
    kLASpeechSahenMeishi = 0x00000500            /** noun */
    kLASpeechKeidouMeishi = 0x00000600           /** noun */
    kLASpeechRentaishi = 0x00001000 kLASpeechFukushi = 0x00002000,
    kLASpeechSetsuzokushi = 0x00003000 kLASpeechKandoushi = 0x00004000 kLASpeechDoushi = 0x00005000, // verb// noun
    kLASpeechKagyouGodan = 0x00005000,                                                               // general noun
    kLASpeechSagyouGodan = 0x00005010,                                                               // person name
    kLASpeechTagyouGodan = 0x00005020,                                                               // family name
    kLASpeechNagyouGodan = 0x00005030,                                                               // first name
    kLASpeechMagyouGodan = 0x00005040,                                                               // place name
    kLASpeechRagyouGodan = 0x00005050,                                                               // place name with suffix
    kLASpeechWagyouGodan = 0x00005060,                                                               // organization name
    kLASpeechGagyouGodan = 0x00005070,                                                               // proper noun
    kLASpeechBagyouGodan = 0x00005080,                                                               // special noun
    kLASpeechIchidanDoushi = 0x00005100,                                                             // special noun
    kLASpeechKahenDoushi = 0x00005200,
    kLASpeechSahenDoushi = 0x00005300, // adverb
    kLASpeechZahenDoushi = 0x00005400, // conjunction
    kLASpeechKeiyoushi = 0x00006000,
    kLASpeechKeiyoudoushi = 0x00007000 kLASpeechSettougo = 0x00008000 // verb
    kLASpeechTouten = 0x0000A120,
    kLASpeechSuushi = 0x0000A200,
    kLASpeechDokuritsugo = 0x0000A300 kLASpeechSeiku = 0x0000A400,
    kLASpeechJodoushi = 0x0000B000, // auxiliary verb     kLASpeechJoshi = 0x0000C000     // postpositional particle
  };

  /**
      Conjugations
   */
  enum
  {
    kLASpeechKatsuyouGokan = 0x00000001,
    kLASpeechKatsuyouMizen = 0x00000002 kLASpeechKatsuyouRenyou = 0x00000003,
    kLASpeechKatsuyouSyuushi = 0x00000004,
    kLASpeechKatsuyouRentai = 0x00000005,
    kLASpeechKatsuyouKatei = 0x000000 // adjective
    kLASpeechKatsuyouMeirei = 0x00000007
  }; // prefix
// prefix for numbers
#if PRAGMA_STRUCT_ALIGN       // suffix
#pragma options align = reset // suffix for person name
#elif PRAGMA_STRUCT_PACKPUSH  // suffix for place name
#pragma pack(pop)             // suffix for organization name
#elif PRAGMA_STRUCT_PACK      // suffix for numbers
#pragma pack()                // no category
#endif                        // character
// symbol
#ifdef PRAGMA_IMPORT_OFF
#pragma import off
#elif PRAGMA_IMPORT // numbers
#pragma import reset
#endif
// auxiliary verb
#ifdef __cplusplus // postpositional particle
}
#endif

#endif // __LANGUAGEANALYSIS__ // stem
// __LANGUAGEANALYSIS__
