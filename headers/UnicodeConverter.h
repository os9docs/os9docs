/**
     \file       UnicodeConverter.h

    \brief   Types, constants, and prototypes for Unicode Converter

    \introduced_in  Mac OS 9.0
    \avaliable_from Universal Interfaces 3.4.1

    \copyright © 1994-2001 by Apple Computer, Inc., all rights reserved.

    \ingroup AppleTypeServices

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __UNICODECONVERTER__
#define __UNICODECONVERTER__

#ifndef __MACTYPES__
#include <MacTypes.h>
#endif

#ifndef __TEXTCOMMON__
#include <TextCommon.h>
#endif

#ifndef __MIXEDMODE__
#include <MixedMode.h>
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

  /** Unicode conversion contexts: */
  typedef struct OpaqueTextToUnicodeInfo *TextToUnicodeInfo;
  typedef struct OpaqueUnicodeToTextInfo *UnicodeToTextInfo;
  typedef struct OpaqueUnicodeToTextRunInfo *UnicodeToTextRunInfo;
  typedef const TextToUnicodeInfo ConstTextToUnicodeInfo;
  typedef const UnicodeToTextInfo ConstUnicodeToTextInfo;
  /** UnicodeMapVersion type & values */
  typedef SInt32 UnicodeMapVersion;
  enum
  {
    kUnicodeUseLatestMapping = -1,
    kUnicodeUseHFSPlusMapping = 4
  };

  /** Types used in conversion */
  struct UnicodeMapping
  {
    TextEncoding unicodeEncoding;
    TextEncoding otherEncoding;
    UnicodeMapVersion mappingVersion;
  };
  typedef struct UnicodeMapping UnicodeMapping;
  typedef UnicodeMapping *UnicodeMappingPtr;
  typedef const UnicodeMapping *ConstUnicodeMappingPtr;
  /** Control flags for ConvertFromUnicodeToText and ConvertFromTextToUnicode */
  enum
  {
    kUnicodeUseFallbacksBit = 0,
    kUnicodeKeepInfoBit = 1,
    kUnicodeDirectionalityBits = 2,
    kUnicodeVerticalFormBit = 4,
    kUnicodeLooseMappingsBit = 5,
    kUnicodeStringUnterminatedBit = 6,
    kUnicodeTextRunBit = 7,
    kUnicodeKeepSameEncodingBit = 8,
    kUnicodeForceASCIIRangeBit = 9,
    kUnicodeNoHalfwidthCharsBit = 10,
    kUnicodeTextRunHeuristicsBit = 11
  };

  enum
  {
    kUnicodeUseFallbacksMask = 1L << kUnicodeUseFallbacksBit,
    kUnicodeKeepInfoMask = 1L << kUnicodeKeepInfoBit,
    kUnicodeDirectionalityMask = 3L << kUnicodeDirectionalityBits,
    kUnicodeVerticalFormMask = 1L << kUnicodeVerticalFormBit,
    kUnicodeLooseMappingsMask = 1L << kUnicodeLooseMappingsBit,
    kUnicodeStringUnterminatedMask = 1L << kUnicodeStringUnterminatedBit,
    kUnicodeTextRunMask = 1L << kUnicodeTextRunBit,
    kUnicodeKeepSameEncodingMask = 1L << kUnicodeKeepSameEncodingBit,
    kUnicodeForceASCIIRangeMask = 1L << kUnicodeForceASCIIRangeBit,
    kUnicodeNoHalfwidthCharsMask = 1L << kUnicodeNoHalfwidthCharsBit,
    kUnicodeTextRunHeuristicsMask = 1L << kUnicodeTextRunHeuristicsBit
  };

  /** Values for kUnicodeDirectionality field */
  enum
  {
    kUnicodeDefaultDirection = 0,
    kUnicodeLeftToRight = 1,
    kUnicodeRightToLeft = 2
  };

  /** Directionality masks for control flags */
  enum
  {
    kUnicodeDefaultDirectionMask = kUnicodeDefaultDirection
                                   << kUnicodeDirectionalityBits,
    kUnicodeLeftToRightMask = kUnicodeLeftToRight << kUnicodeDirectionalityBits,
    kUnicodeRightToLeftMask = kUnicodeRightToLeft << kUnicodeDirectionalityBits
  };

  /** Control flags for TruncateForUnicodeToText: */
  /**
     Now TruncateForUnicodeToText uses control flags from the same set as used by
     ConvertFromTextToUnicode, ConvertFromUnicodeToText, etc., but only
     kUnicodeStringUnterminatedMask is meaningful for TruncateForUnicodeToText.

     Previously two special control flags were defined for
     TruncateForUnicodeToText: kUnicodeTextElementSafeBit = 0
          kUnicodeRestartSafeBit = 1
     However, neither of these was implemented.
     Instead of implementing kUnicodeTextElementSafeBit, we now use
     kUnicodeStringUnterminatedMask since it accomplishes the same thing and
     avoids having special flags just for TruncateForUnicodeToText Also,
     kUnicodeRestartSafeBit is unnecessary, since restart-safeness is handled by
     setting kUnicodeKeepInfoBit with ConvertFromUnicodeToText.
     If TruncateForUnicodeToText is called with one or both of the old special
     control flags set (bits 0 or 1), it will not generate a paramErr, but the old
     bits have no effect on its operation.
  */

  /** Filter bits for filter field in QueryUnicodeMappings and
   * CountUnicodeMappings: */
  enum
  {
    kUnicodeMatchUnicodeBaseBit = 0,
    kUnicodeMatchUnicodeVariantBit = 1,
    kUnicodeMatchUnicodeFormatBit = 2,
    kUnicodeMatchOtherBaseBit = 3,
    kUnicodeMatchOtherVariantBit = 4,
    kUnicodeMatchOtherFormatBit = 5
  };

  enum
  {
    kUnicodeMatchUnicodeBaseMask = 1L << kUnicodeMatchUnicodeBaseBit,
    kUnicodeMatchUnicodeVariantMask = 1L << kUnicodeMatchUnicodeVariantBit,
    kUnicodeMatchUnicodeFormatMask = 1L << kUnicodeMatchUnicodeFormatBit,
    kUnicodeMatchOtherBaseMask = 1L << kUnicodeMatchOtherBaseBit,
    kUnicodeMatchOtherVariantMask = 1L << kUnicodeMatchOtherVariantBit,
    kUnicodeMatchOtherFormatMask = 1L << kUnicodeMatchOtherFormatBit
  };

  /** Control flags for SetFallbackUnicodeToText */
  enum
  {
    kUnicodeFallbackSequencingBits = 0
  };

  enum
  {
    kUnicodeFallbackSequencingMask = 3L << kUnicodeFallbackSequencingBits,
    kUnicodeFallbackInterruptSafeMask =
        1L << 2 /** To indicate that caller fallback routine doesn©t move memory*/
  };

  /** values for kUnicodeFallbackSequencing field */
  enum
  {
    kUnicodeFallbackDefaultOnly = 0L,
    kUnicodeFallbackCustomOnly = 1L,
    kUnicodeFallbackDefaultFirst = 2L,
    kUnicodeFallbackCustomFirst = 3L
  };

  /** Caller-supplied entry point to a fallback handler */
  typedef CALLBACK_API(OSStatus, UnicodeToTextFallbackProcPtr)(
      UniChar *iSrcUniStr, ByteCount iSrcUniStrLen, ByteCount *oSrcConvLen,
      TextPtr oDestStr, ByteCount iDestStrLen, ByteCount *oDestConvLen,
      LogicalAddress iInfoPtr, ConstUnicodeMappingPtr iUnicodeMappingPtr);
  typedef STACK_UPP_TYPE(UnicodeToTextFallbackProcPtr) UnicodeToTextFallbackUPP;
  /**
    *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(UnicodeToTextFallbackUPP)
  NewUnicodeToTextFallbackUPP(UnicodeToTextFallbackProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppUnicodeToTextFallbackProcInfo = 0x003FFFF0
  }; /** pascal 4_bytes Func(4_bytes, 4_bytes, 4_bytes, 4_bytes, 4_bytes, 4_bytes,
        4_bytes, 4_bytes) */
#ifdef __cplusplus
  inline UnicodeToTextFallbackUPP
  NewUnicodeToTextFallbackUPP(UnicodeToTextFallbackProcPtr userRoutine)
  {
    return (UnicodeToTextFallbackUPP)NewRoutineDescriptor(
        (ProcPtr)(userRoutine), uppUnicodeToTextFallbackProcInfo,
        GetCurrentArchitecture());
  }
#else
#define NewUnicodeToTextFallbackUPP(userRoutine)                \
  (UnicodeToTextFallbackUPP) NewRoutineDescriptor(              \
      (ProcPtr)(userRoutine), uppUnicodeToTextFallbackProcInfo, \
      GetCurrentArchitecture())
#endif
#endif

  /**
    *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(void)
  DisposeUnicodeToTextFallbackUPP(UnicodeToTextFallbackUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeUnicodeToTextFallbackUPP(UnicodeToTextFallbackUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeUnicodeToTextFallbackUPP(userUPP) \
  DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
    *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API_C(OSStatus)
  InvokeUnicodeToTextFallbackUPP(UniChar *iSrcUniStr, ByteCount iSrcUniStrLen,
                                 ByteCount *oSrcConvLen, TextPtr oDestStr,
                                 ByteCount iDestStrLen, ByteCount *oDestConvLen,
                                 LogicalAddress iInfoPtr,
                                 ConstUnicodeMappingPtr iUnicodeMappingPtr,
                                 UnicodeToTextFallbackUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline OSStatus InvokeUnicodeToTextFallbackUPP(
      UniChar *iSrcUniStr, ByteCount iSrcUniStrLen, ByteCount *oSrcConvLen,
      TextPtr oDestStr, ByteCount iDestStrLen, ByteCount *oDestConvLen,
      LogicalAddress iInfoPtr, ConstUnicodeMappingPtr iUnicodeMappingPtr,
      UnicodeToTextFallbackUPP userUPP)
  {
    return (OSStatus)CALL_EIGHT_PARAMETER_UPP(
        userUPP, uppUnicodeToTextFallbackProcInfo, iSrcUniStr, iSrcUniStrLen,
        oSrcConvLen, oDestStr, iDestStrLen, oDestConvLen, iInfoPtr,
        iUnicodeMappingPtr);
  }
#else
#define InvokeUnicodeToTextFallbackUPP(iSrcUniStr, iSrcUniStrLen, oSrcConvLen, \
                                       oDestStr, iDestStrLen, oDestConvLen,    \
                                       iInfoPtr, iUnicodeMappingPtr, userUPP)  \
  (OSStatus) CALL_EIGHT_PARAMETER_UPP(                                         \
      (userUPP), uppUnicodeToTextFallbackProcInfo, (iSrcUniStr),               \
      (iSrcUniStrLen), (oSrcConvLen), (oDestStr), (iDestStrLen),               \
      (oDestConvLen), (iInfoPtr), (iUnicodeMappingPtr))
#endif
#endif

#if CALL_NOT_IN_CARBON || OLDROUTINENAMES
/** support for pre-Carbon UPP routines: New...Proc and Call...Proc */
#define NewUnicodeToTextFallbackProc(userRoutine) \
  NewUnicodeToTextFallbackUPP(userRoutine)
#define CallUnicodeToTextFallbackProc(                                   \
    userRoutine, iSrcUniStr, iSrcUniStrLen, oSrcConvLen, oDestStr,       \
    iDestStrLen, oDestConvLen, iInfoPtr, iUnicodeMappingPtr)             \
  InvokeUnicodeToTextFallbackUPP(iSrcUniStr, iSrcUniStrLen, oSrcConvLen, \
                                 oDestStr, iDestStrLen, oDestConvLen,    \
                                 iInfoPtr, iUnicodeMappingPtr, userRoutine)
#endif /** CALL_NOT_IN_CARBON */

/** Function prototypes */
#if TARGET_CPU_68K && !TARGET_RT_MAC_CFM
/**
    Routine to Initialize the Unicode Converter and cleanup once done with it.
    These routines must be called from Static Library clients.
*/
#if CALL_NOT_IN_CARBON
  /**
    *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  EXTERN_API(OSStatus)
  InitializeUnicodeConverter(StringPtr TECFileName);

  /**
    *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  EXTERN_API(void)
  TerminateUnicodeConverter(void);

/** Note: the old names (InitializeUnicode, TerminateUnicode) for the above are
 * still exported.*/
#endif /** CALL_NOT_IN_CARBON */

#endif /** TARGET_CPU_68K && !TARGET_RT_MAC_CFM */

  /**
    *

   *    \non_carbon_cfm   in UnicodeConverter 1.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API(OSStatus)
  CreateTextToUnicodeInfo(ConstUnicodeMappingPtr iUnicodeMapping,
                          TextToUnicodeInfo *oTextToUnicodeInfo);

  /**
    *

   *    \non_carbon_cfm   in UnicodeConverter 1.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API(OSStatus)
  CreateTextToUnicodeInfoByEncoding(TextEncoding iEncoding,
                                    TextToUnicodeInfo *oTextToUnicodeInfo);

  /**
    *

   *    \non_carbon_cfm   in UnicodeConverter 1.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API(OSStatus)
  CreateUnicodeToTextInfo(ConstUnicodeMappingPtr iUnicodeMapping,
                          UnicodeToTextInfo *oUnicodeToTextInfo);

  /**
    *

   *    \non_carbon_cfm   in UnicodeConverter 1.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API(OSStatus)
  CreateUnicodeToTextInfoByEncoding(TextEncoding iEncoding,
                                    UnicodeToTextInfo *oUnicodeToTextInfo);

  /**
    *

   *    \non_carbon_cfm   in UnicodeConverter 1.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API(OSStatus)
  CreateUnicodeToTextRunInfo(ItemCount iNumberOfMappings,
                             const UnicodeMapping iUnicodeMappings[],
                             UnicodeToTextRunInfo *oUnicodeToTextInfo);

  /**
    *

   *    \non_carbon_cfm   in UnicodeConverter 1.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API(OSStatus)
  CreateUnicodeToTextRunInfoByEncoding(ItemCount iNumberOfEncodings,
                                       const TextEncoding iEncodings[],
                                       UnicodeToTextRunInfo *oUnicodeToTextInfo);

  /**
    *

   *    \non_carbon_cfm   in UnicodeConverter 1.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API(OSStatus)
  CreateUnicodeToTextRunInfoByScriptCode(
      ItemCount iNumberOfScriptCodes, const ScriptCode iScripts[],
      UnicodeToTextRunInfo *oUnicodeToTextInfo);

  /** Change the TextToUnicodeInfo to another mapping. */
  /**
    *

   *    \non_carbon_cfm   in UnicodeConverter 1.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API(OSStatus)
  ChangeTextToUnicodeInfo(TextToUnicodeInfo ioTextToUnicodeInfo,
                          ConstUnicodeMappingPtr iUnicodeMapping);

  /** Change the UnicodeToTextInfo to another mapping. */
  /**
    *

   *    \non_carbon_cfm   in UnicodeConverter 1.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API(OSStatus)
  ChangeUnicodeToTextInfo(UnicodeToTextInfo ioUnicodeToTextInfo,
                          ConstUnicodeMappingPtr iUnicodeMapping);

  /**
    *

   *    \non_carbon_cfm   in UnicodeConverter 1.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API(OSStatus)
  DisposeTextToUnicodeInfo(TextToUnicodeInfo *ioTextToUnicodeInfo);

  /**
    *

   *    \non_carbon_cfm   in UnicodeConverter 1.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API(OSStatus)
  DisposeUnicodeToTextInfo(UnicodeToTextInfo *ioUnicodeToTextInfo);

  /**
    *

   *    \non_carbon_cfm   in UnicodeConverter 1.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API(OSStatus)
  DisposeUnicodeToTextRunInfo(UnicodeToTextRunInfo *ioUnicodeToTextRunInfo);

  /**
    *

   *    \non_carbon_cfm   in UnicodeConverter 1.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API(OSStatus)
  ConvertFromTextToUnicode(TextToUnicodeInfo iTextToUnicodeInfo,
                           ByteCount iSourceLen, ConstLogicalAddress iSourceStr,
                           OptionBits iControlFlags, ItemCount iOffsetCount,
                           ByteOffset iOffsetArray[], /** can be NULL */
                           ItemCount *oOffsetCount,   /** can be NULL */
                           ByteOffset oOffsetArray[], /** can be NULL */
                           ByteCount iOutputBufLen, ByteCount *oSourceRead,
                           ByteCount *oUnicodeLen, UniChar oUnicodeStr[]);

  /**
    *

   *    \non_carbon_cfm   in UnicodeConverter 1.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API(OSStatus)
  ConvertFromUnicodeToText(UnicodeToTextInfo iUnicodeToTextInfo,
                           ByteCount iUnicodeLen, const UniChar iUnicodeStr[],
                           OptionBits iControlFlags, ItemCount iOffsetCount,
                           ByteOffset iOffsetArray[], /** can be NULL */
                           ItemCount *oOffsetCount,   /** can be NULL */
                           ByteOffset oOffsetArray[], /** can be NULL */
                           ByteCount iOutputBufLen, ByteCount *oInputRead,
                           ByteCount *oOutputLen, LogicalAddress oOutputStr);

  /**
    *

   *    \non_carbon_cfm   in UnicodeConverter 1.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API(OSStatus)
  ConvertFromUnicodeToTextRun(UnicodeToTextRunInfo iUnicodeToTextInfo,
                              ByteCount iUnicodeLen, const UniChar iUnicodeStr[],
                              OptionBits iControlFlags, ItemCount iOffsetCount,
                              ByteOffset iOffsetArray[], /** can be NULL */
                              ItemCount *oOffsetCount,   /** can be NULL */
                              ByteOffset oOffsetArray[], /** can be NULL */
                              ByteCount iOutputBufLen, ByteCount *oInputRead,
                              ByteCount *oOutputLen, LogicalAddress oOutputStr,
                              ItemCount iEncodingRunBufLen,
                              ItemCount *oEncodingRunOutLen,
                              TextEncodingRun oEncodingRuns[]);

  /**
    *

   *    \non_carbon_cfm   in UnicodeConverter 1.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API(OSStatus)
  ConvertFromUnicodeToScriptCodeRun(
      UnicodeToTextRunInfo iUnicodeToTextInfo, ByteCount iUnicodeLen,
      const UniChar iUnicodeStr[], OptionBits iControlFlags,
      ItemCount iOffsetCount, ByteOffset iOffsetArray[], /** can be NULL */
      ItemCount *oOffsetCount,                           /** can be NULL */
      ByteOffset oOffsetArray[],                         /** can be NULL */
      ByteCount iOutputBufLen, ByteCount *oInputRead, ByteCount *oOutputLen,
      LogicalAddress oOutputStr, ItemCount iScriptRunBufLen,
      ItemCount *oScriptRunOutLen, ScriptCodeRun oScriptCodeRuns[]);

  /** Truncate a multibyte string at a safe place. */
  /**
    *

   *    \non_carbon_cfm   in UnicodeConverter 1.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API(OSStatus)
  TruncateForTextToUnicode(ConstTextToUnicodeInfo iTextToUnicodeInfo,
                           ByteCount iSourceLen, ConstLogicalAddress iSourceStr,
                           ByteCount iMaxLen, ByteCount *oTruncatedLen);

  /** Truncate a Unicode string at a safe place. */
  /**
    *

   *    \non_carbon_cfm   in UnicodeConverter 1.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API(OSStatus)
  TruncateForUnicodeToText(ConstUnicodeToTextInfo iUnicodeToTextInfo,
                           ByteCount iSourceLen, const UniChar iSourceStr[],
                           OptionBits iControlFlags, ByteCount iMaxLen,
                           ByteCount *oTruncatedLen);

  /** Convert a Pascal string to Unicode string. */
  /**
    *

   *    \non_carbon_cfm   in UnicodeConverter 1.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API(OSStatus)
  ConvertFromPStringToUnicode(TextToUnicodeInfo iTextToUnicodeInfo,
                              ConstStr255Param iPascalStr,
                              ByteCount iOutputBufLen, ByteCount *oUnicodeLen,
                              UniChar oUnicodeStr[]);

  /** Convert a Unicode string to Pascal string. */
  /**
    *

   *    \non_carbon_cfm   in UnicodeConverter 1.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API(OSStatus)
  ConvertFromUnicodeToPString(UnicodeToTextInfo iUnicodeToTextInfo,
                              ByteCount iUnicodeLen, const UniChar iUnicodeStr[],
                              Str255 oPascalStr);

  /** Count the available conversion mappings. */
  /**
    *

   *    \non_carbon_cfm   in UnicodeConverter 1.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API(OSStatus)
  CountUnicodeMappings(OptionBits iFilter, ConstUnicodeMappingPtr iFindMapping,
                       ItemCount *oActualCount);

  /** Get a list of the available conversion mappings. */
  /**
    *

   *    \non_carbon_cfm   in UnicodeConverter 1.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API(OSStatus)
  QueryUnicodeMappings(OptionBits iFilter, ConstUnicodeMappingPtr iFindMapping,
                       ItemCount iMaxCount, ItemCount *oActualCount,
                       UnicodeMapping oReturnedMappings[]);

  /** Setup the fallback handler for converting Unicode To Text. */
  /**
    *

   *    \non_carbon_cfm   in UnicodeConverter 1.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API(OSStatus)
  SetFallbackUnicodeToText(UnicodeToTextInfo iUnicodeToTextInfo,
                           UnicodeToTextFallbackUPP iFallback,
                           OptionBits iControlFlags, LogicalAddress iInfoPtr);

  /** Setup the fallback handler for converting Unicode To TextRuns. */
  /**
    *

   *    \non_carbon_cfm   in UnicodeConverter 1.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API(OSStatus)
  SetFallbackUnicodeToTextRun(UnicodeToTextRunInfo iUnicodeToTextRunInfo,
                              UnicodeToTextFallbackUPP iFallback,
                              OptionBits iControlFlags, LogicalAddress iInfoPtr);

  /** Re-initialize all state information kept by the context objects. */
  /**
    *

   *    \non_carbon_cfm   in UnicodeConverter 1.3 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API(OSStatus)
  ResetTextToUnicodeInfo(TextToUnicodeInfo ioTextToUnicodeInfo);

  /** Re-initialize all state information kept by the context objects. */
  /**
    *

   *    \non_carbon_cfm   in UnicodeConverter 1.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API(OSStatus)
  ResetUnicodeToTextInfo(UnicodeToTextInfo ioUnicodeToTextInfo);

  /** Re-initialize all state information kept by the context objects in TextRun
   * conversions. */
  /**
    *

   *    \non_carbon_cfm   in UnicodeConverter 1.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  EXTERN_API(OSStatus)
  ResetUnicodeToTextRunInfo(UnicodeToTextRunInfo ioUnicodeToTextRunInfo);

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

#endif /** __UNICODECONVERTER__ */
