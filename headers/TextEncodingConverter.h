/**
     \file       TextEncodingConverter.h

    \brief   Text Encoding Conversion Interfaces.

    \introduced_in  Mac OS 9.0
    \avaliable_from Universal Interfaces 3.4.1

    \copyright © 1994-2001 by Apple Computer, Inc., all rights reserved.

    \ingroup Font

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __TEXTENCODINGCONVERTER__
#define __TEXTENCODINGCONVERTER__

#ifndef __MACTYPES__
#include <MacTypes.h>
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

  typedef OSType TECPluginSignature;
  typedef UInt32 TECPluginVersion;
  /** plugin signatures */
  enum
  {
    kTECSignature = FOUR_CHAR_CODE('encv'),
    kTECUnicodePluginSignature = FOUR_CHAR_CODE('puni'),
    kTECJapanesePluginSignature = FOUR_CHAR_CODE('pjpn'),
    kTECChinesePluginSignature = FOUR_CHAR_CODE('pzho'),
    kTECKoreanPluginSignature = FOUR_CHAR_CODE('pkor')
  };

  /** converter object reference */
  typedef struct OpaqueTECObjectRef *TECObjectRef;
  typedef struct OpaqueTECSnifferObjectRef *TECSnifferObjectRef;
  typedef OSType TECPluginSig;
  struct TECConversionInfo
  {
    TextEncoding sourceEncoding;
    TextEncoding destinationEncoding;
    UInt16 reserved1;
    UInt16 reserved2;
  };
  typedef struct TECConversionInfo TECConversionInfo;
  /** return number of encodings types supported by user's configuraton of the
   * encoding converter */
  /**
   *  TECCountAvailableTextEncodings()
   *

   *    \non_carbon_cfm   in TextEncodingConverter 1.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  TECCountAvailableTextEncodings(ItemCount *numberEncodings);

  /** fill in an array of type TextEncoding passed in by the user with types of
   * encodings the current configuration of the encoder can handle. */
  /**
   *  TECGetAvailableTextEncodings()
   *

   *    \non_carbon_cfm   in TextEncodingConverter 1.2 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  TECGetAvailableTextEncodings(TextEncoding availableEncodings[],
                               ItemCount maxAvailableEncodings,
                               ItemCount *actualAvailableEncodings);

  /** return number of from-to encoding conversion pairs supported  */
  /**
   *  TECCountDirectTextEncodingConversions()
   *

   *    \non_carbon_cfm   in TextEncodingConverter 1.2 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  TECCountDirectTextEncodingConversions(ItemCount *numberOfEncodings);

  /** fill in an array of type TextEncodingPair passed in by the user with types
   * of encoding pairs the current configuration of the encoder can handle. */
  /**
   *  TECGetDirectTextEncodingConversions()
   *

   *    \non_carbon_cfm   in TextEncodingConverter 1.2 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  TECGetDirectTextEncodingConversions(TECConversionInfo availableConversions[],
                                      ItemCount maxAvailableConversions,
                                      ItemCount *actualAvailableConversions);

  /** return number of encodings a given encoding can be converter into */
  /**
   *  TECCountDestinationTextEncodings()
   *

   *    \non_carbon_cfm   in TextEncodingConverter 1.2 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  TECCountDestinationTextEncodings(TextEncoding inputEncoding,
                                   ItemCount *numberOfEncodings);

  /** fill in an array of type TextEncodingPair passed in by the user with types
   * of encodings pairs the current configuration of the encoder can handle. */
  /**
   *  TECGetDestinationTextEncodings()
   *

   *    \non_carbon_cfm   in TextEncodingConverter 1.2 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  TECGetDestinationTextEncodings(TextEncoding inputEncoding,
                                 TextEncoding destinationEncodings[],
                                 ItemCount maxDestinationEncodings,
                                 ItemCount *actualDestinationEncodings);

  /** get info about a text encoding */
  /**
   *  TECGetTextEncodingInternetName()
   *

   *    \non_carbon_cfm   in TextEncodingConverter 1.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  TECGetTextEncodingInternetName(TextEncoding textEncoding, Str255 encodingName);

  /**
   *  TECGetTextEncodingFromInternetName()
   *

   *    \non_carbon_cfm   in TextEncodingConverter 1.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  TECGetTextEncodingFromInternetName(TextEncoding *textEncoding,
                                     ConstStr255Param encodingName);

  /** create/dispose converters */
  /**
   *  TECCreateConverter()
   *

   *    \non_carbon_cfm   in TextEncodingConverter 1.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  TECCreateConverter(TECObjectRef *newEncodingConverter,
                     TextEncoding inputEncoding, TextEncoding outputEncoding);

  /**
   *  TECCreateConverterFromPath()
   *

   *    \non_carbon_cfm   in TextEncodingConverter 1.2 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  TECCreateConverterFromPath(TECObjectRef *newEncodingConverter,
                             const TextEncoding inPath[], ItemCount inEncodings);

  /**
   *  TECDisposeConverter()
   *

   *    \non_carbon_cfm   in TextEncodingConverter 1.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  TECDisposeConverter(TECObjectRef newEncodingConverter);

  /** convert text encodings */
  /**
   *  TECClearConverterContextInfo()
   *

   *    \non_carbon_cfm   in TextEncodingConverter 1.2 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  TECClearConverterContextInfo(TECObjectRef encodingConverter);

  /**
   *  TECConvertText()
   *

   *    \non_carbon_cfm   in TextEncodingConverter 1.2 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  TECConvertText(TECObjectRef encodingConverter, ConstTextPtr inputBuffer,
                 ByteCount inputBufferLength, ByteCount *actualInputLength,
                 TextPtr outputBuffer, ByteCount outputBufferLength,
                 ByteCount *actualOutputLength);

  /**
   *  TECFlushText()
   *

   *    \non_carbon_cfm   in TextEncodingConverter 1.2 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  TECFlushText(TECObjectRef encodingConverter, TextPtr outputBuffer,
               ByteCount outputBufferLength, ByteCount *actualOutputLength);

  /** one-to-many routines */
  /**
   *  TECCountSubTextEncodings()
   *

   *    \non_carbon_cfm   in TextEncodingConverter 1.2 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  TECCountSubTextEncodings(TextEncoding inputEncoding,
                           ItemCount *numberOfEncodings);

  /**
   *  TECGetSubTextEncodings()
   *

   *    \non_carbon_cfm   in TextEncodingConverter 1.2 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  TECGetSubTextEncodings(TextEncoding inputEncoding, TextEncoding subEncodings[],
                         ItemCount maxSubEncodings,
                         ItemCount *actualSubEncodings);

  /**
   *  TECGetEncodingList()
   *

   *    \non_carbon_cfm   in TextEncodingConverter 1.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  TECGetEncodingList(TECObjectRef encodingConverter, ItemCount *numEncodings,
                     Handle *encodingList);

  /**
   *  TECCreateOneToManyConverter()
   *

   *    \non_carbon_cfm   in TextEncodingConverter 1.2 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  TECCreateOneToManyConverter(TECObjectRef *newEncodingConverter,
                              TextEncoding inputEncoding,
                              ItemCount numOutputEncodings,
                              const TextEncoding outputEncodings[]);

  /**
   *  TECConvertTextToMultipleEncodings()
   *

   *    \non_carbon_cfm   in TextEncodingConverter 1.2 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  TECConvertTextToMultipleEncodings(
      TECObjectRef encodingConverter, ConstTextPtr inputBuffer,
      ByteCount inputBufferLength, ByteCount *actualInputLength,
      TextPtr outputBuffer, ByteCount outputBufferLength,
      ByteCount *actualOutputLength, TextEncodingRun outEncodingsBuffer[],
      ItemCount maxOutEncodingRuns, ItemCount *actualOutEncodingRuns);

  /**
   *  TECFlushMultipleEncodings()
   *

   *    \non_carbon_cfm   in TextEncodingConverter 1.2 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  TECFlushMultipleEncodings(TECObjectRef encodingConverter, TextPtr outputBuffer,
                            ByteCount outputBufferLength,
                            ByteCount *actualOutputLength,
                            TextEncodingRun outEncodingsBuffer[],
                            ItemCount maxOutEncodingRuns,
                            ItemCount *actualOutEncodingRuns);

  /** international internet info */
  /**
   *  TECCountWebTextEncodings()
   *

   *    \non_carbon_cfm   in TextEncodingConverter 1.2 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  TECCountWebTextEncodings(RegionCode locale, ItemCount *numberEncodings);

  /**
   *  TECGetWebTextEncodings()
   *

   *    \non_carbon_cfm   in TextEncodingConverter 1.2 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  TECGetWebTextEncodings(RegionCode locale, TextEncoding availableEncodings[],
                         ItemCount maxAvailableEncodings,
                         ItemCount *actualAvailableEncodings);

  /**
   *  TECCountMailTextEncodings()
   *

   *    \non_carbon_cfm   in TextEncodingConverter 1.2 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  TECCountMailTextEncodings(RegionCode locale, ItemCount *numberEncodings);

  /**
   *  TECGetMailTextEncodings()
   *

   *    \non_carbon_cfm   in TextEncodingConverter 1.2 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  TECGetMailTextEncodings(RegionCode locale, TextEncoding availableEncodings[],
                          ItemCount maxAvailableEncodings,
                          ItemCount *actualAvailableEncodings);

  /** examine text encodings */
  /**
   *  TECCountAvailableSniffers()
   *

   *    \non_carbon_cfm   in TextEncodingConverter 1.2 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  TECCountAvailableSniffers(ItemCount *numberOfEncodings);

  /**
   *  TECGetAvailableSniffers()
   *

   *    \non_carbon_cfm   in TextEncodingConverter 1.2 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  TECGetAvailableSniffers(TextEncoding availableSniffers[],
                          ItemCount maxAvailableSniffers,
                          ItemCount *actualAvailableSniffers);

  /**
   *  TECCreateSniffer()
   *

   *    \non_carbon_cfm   in TextEncodingConverter 1.2 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  TECCreateSniffer(TECSnifferObjectRef *encodingSniffer,
                   TextEncoding testEncodings[], ItemCount numTextEncodings);

  /**
   *  TECSniffTextEncoding()
   *

   *    \non_carbon_cfm   in TextEncodingConverter 1.2 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  TECSniffTextEncoding(TECSnifferObjectRef encodingSniffer, TextPtr inputBuffer,
                       ByteCount inputBufferLength, TextEncoding testEncodings[],
                       ItemCount numTextEncodings, ItemCount numErrsArray[],
                       ItemCount maxErrs, ItemCount numFeaturesArray[],
                       ItemCount maxFeatures);

  /**
   *  TECDisposeSniffer()
   *

   *    \non_carbon_cfm   in TextEncodingConverter 1.2 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  TECDisposeSniffer(TECSnifferObjectRef encodingSniffer);

  /**
   *  TECClearSnifferContextInfo()
   *

   *    \non_carbon_cfm   in TextEncodingConverter 1.2 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  TECClearSnifferContextInfo(TECSnifferObjectRef encodingSniffer);

#if CALL_NOT_IN_CARBON
  /**
   *  TECSetBasicOptions()
   *

   *    \non_carbon_cfm   in TextEncodingConverter 1.5 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  TECSetBasicOptions(TECObjectRef encodingConverter, OptionBits controlFlags);

#endif /** CALL_NOT_IN_CARBON */

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

#endif /** __TEXTENCODINGCONVERTER__ */
