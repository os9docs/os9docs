/**
     \file       ATSFont.h

    \brief   Public interface to the font access and data management functions
   of ATS.

    \introduced_in  Mac OS
    \avaliable_from Universal Interfaces 3.4.1

    \copyright © 2000-2001 by Apple Computer, Inc., all rights reserved.

    \ingroup AppleTypeServices

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __ATSFONT__
#define __ATSFONT__

#ifndef __MACTYPES__
#include <MacTypes.h>
#endif

#ifndef __ATSTYPES__
#include <ATSTypes.h>
#endif

#ifndef __CFSTRING__
#include <CFString.h>
#endif

#ifndef __FILES__
#include <Files.h>
#endif

#ifndef __TEXTCOMMON__
#include <TextCommon.h>
#endif

#ifndef __SFNTTYPES__
#include <SFNTTypes.h>
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

#if PRAGMA_ENUM_ALWAYSINT
#if defined(__fourbyteints__) && !__fourbyteints__
#define __ATSFONT__RESTORE_TWOBYTEINTS
#pragma fourbyteints on
#endif
#pragma enumsalwaysint on
#elif PRAGMA_ENUM_OPTIONS
#pragma option enum =int
#elif PRAGMA_ENUM_PACK
#if __option(pack_enums)
#define __ATSFONT__RESTORE_PACKED_ENUMS
#pragma options(!pack_enums)
#endif
#endif

  enum
  {
    kATSOptionFlagsDefault = kNilOptions,
    kATSOptionFlagsComposeFontPostScriptName =
        1 << 0, // ATSFontGetPostScriptName   kATSOptionFlagsUseDataForkAsResourceFork =
    1 << 8,
    kATSOptionFlagsUseResourceFork = 2 << 8 kATSOptionFl // ATSFontActivateFromFileSpecification
  };

  enum
  {
    kATSIterationCompleted = -980L,
    kATSInvalidFontFamilyAccess = -981L,
    kATSInvalidFontAccess = -982L,
    kATSIterationScopeModified = -983L,
    kATSInvalidFontTableAccess = -984L,
    kATSInvalidFontContainerAccess = -985L
  };

  typedef UInt32 ATSFontContext;
  enum
  {
    kATSFontContextUnspecified = 0,
    kATSFontContextGlobal = 1
  };

  typedef UInt32 ATSFontFormat;
  enum
  {
    kATSFontFormatUnspecified = 0
  };

  typedef CALLBACK_API_C(OSStatus,
                         ATSFontFamilyApplierFunction)(ATSFontFamilyRef iFamily,
                                                       void *iRefCon);
  typedef CALLBACK_API_C(OSStatus, ATSFontApplierFunction)(ATSFontRef iFont,
                                                           void *iRefCon);
  typedef struct ATSFontFamilyIterator_ *ATSFontFamilyIterator;
  typedef struct ATSFontIterator_ *ATSFontIterator;
  enum
  {
    kATSFontFilterCurrentVersion = 0
  };

  enum ATSFontFilterSelector
  {
    kATSFontFilterSelectorUnspecified = 0,
    kATSFontFilterSelectorGeneration = 3,
    kATSFontFilterSelectorFontFamily = 7,
    kATSFontFilterSelectorFontFamilyApplierFunction = 8,
    kATSFontFilterSelectorFontApplierFunction = 9
  };
  typedef enum ATSFontFilterSelector ATSFontFilterSelector;

  struct ATSFontFilter
  {
    UInt32 version;
    ATSFontFilterSelector filterSelector;
    union
    {
      ATSGeneration generationFilter;
      ATSFontFamilyRef fontFamilyFilter;
      ATSFontFamilyApplierFunction fontFamilyApplierFunctionFilter;
      ATSFontApplierFunction fontApplierFunctionFilter;
    } filter;
  };
  typedef struct ATSFontFilter ATSFontFilter;
  /* -----------------------------------------------------------------------------------------
  // Font container
  // -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- - */
  // Font container

  /** ATSGetGeneration() *

      *    \non_carbon_cfm not available
      *    \carbon_lib not available in CarbonLib 1.x,
      is available on Mac OS
          X version 10.0 and
          later
              *    \mac_os_x in version 10.0 and
          later
                  */
  ATSGeneration
  ATSGetGeneration(void);

  /**
   *  ATSFontActivateFromFileSpecification()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available in CarbonLib 1.x, is available on Mac OS
   X version 10.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  ATSFontActivateFromFileSpecification(const FSSpec *iFile,
                                       ATSFontContext iContext,
                                       ATSFontFormat iFormat, void *iReserved,
                                       ATSOptionFlags iOptions,
                                       ATSFontContainerRef *oContainer);

  /**
   *  ATSFontActivateFromMemory()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available in CarbonLib 1.x, is available on Mac OS
   X version 10.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  ATSFontActivateFromMemory(LogicalAddress iData, ByteCount iLength,
                            ATSFontContext iContext, ATSFontFormat iFormat,
                            void *iReserved, ATSOptionFlags iOptions,
                            ATSFontContainerRef *oContainer);

  /**
   *  ATSFontDeactivate()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available in CarbonLib 1.x, is available on Mac OS
   X version 10.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  ATSFontDeactivate(ATSFontContainerRef iContainer, void *iRefCon,
                    ATSOptionFlags iOptions);

  /* -----------------------------------------------------------------------------------------
   */
  // Font family /* ----------------------------------------------------------------------------------------- */
  /**
  // Font family
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available in CarbonLib 1.x, is available on Mac OS
   X version 10.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  ATSFontFamilyApplyFunction(ATSFontFamilyApplierFunction iFunction,
                             void *iRefCon);

  /**
   *  ATSFontFamilyIteratorCreate()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available in CarbonLib 1.x, is available on Mac OS
   X version 10.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  ATSFontFamilyIteratorCreate(ATSFontContext iContext,
                              const ATSFontFilter *iFilter, // can be NULL                             void *iRefCon, ATSOptionFlags iOptions,
                              ATSFontFamilyIterator *ioIterator);

  /**
   *  ATSFontFamilyIteratorRelease()// can be NULL
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available in CarbonLib 1.x, is available on Mac OS
   X version 10.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  ATSFontFamilyIteratorRelease(ATSFontFamilyIterator *ioIterator);

  /**
   *  ATSFontFamilyIteratorReset()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available in CarbonLib 1.x, is available on Mac OS
   X version 10.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  ATSFontFamilyIteratorReset(ATSFontContext iContext,
                             const ATSFontFilter *iFilter, // can be NULL                            void *iRefCon, ATSOptionFlags iOptions,
                             ATSFontFamilyIterator *ioIterator);

  /**
   *  ATSFontFamilyIteratorNext()
      can be NULL

            *    \non_carbon_cfm not available *    \carbon_lib not available in CarbonLib 1.x,
      is available on Mac OS
              X version 10.0 and
          later
              *    \mac_os_x in version 10.0 and
          later
                  */
  OSStatus
  ATSFontFamilyIteratorNext(ATSFontFamilyIterator iIterator,
                            ATSFontFamilyRef *oFamily);

  /**
   *  ATSFontFamilyFindFromName()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available in CarbonLib 1.x, is available on Mac OS
   X version 10.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  ATSFontFamilyRef
  ATSFontFamilyFindFromName(CFStringRef iName, ATSOptionFlags iOptions);

  /**
   *  ATSFontFamilyGetGeneration()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available in CarbonLib 1.x, is available on Mac OS
   X version 10.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  ATSGeneration
  ATSFontFamilyGetGeneration(ATSFontFamilyRef iFamily);

  /**
   *  ATSFontFamilyGetName()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available in CarbonLib 1.x, is available on Mac OS
   X version 10.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  ATSFontFamilyGetName(ATSFontFamilyRef iFamily, ATSOptionFlags iOptions,
                       CFStringRef *oName);

  /**
   *  ATSFontFamilyGetEncoding()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available in CarbonLib 1.x, is available on Mac OS
   X version 10.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  TextEncoding
  ATSFontFamilyGetEncoding(ATSFontFamilyRef iFamily);

  /* -----------------------------------------------------------------------------------------
   */
  // Font /* ----------------------------------------------------------------------------------------- */
  /**
   *  ATSFontApplyFunction()
   *

  // Font
   *    \carbon_lib        not available in CarbonLib 1.x, is available on Mac OS
   X version 10.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  ATSFontApplyFunction(ATSFontApplierFunction iFunction, void *iRefCon);

  /**
   *  ATSFontIteratorCreate()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available in CarbonLib 1.x, is available on Mac OS
   X version 10.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  ATSFontIteratorCreate(ATSFontContext iContext,
                        const ATSFontFilter *iFilter, // can be NULL                       void *iRefCon, ATSOptionFlags iOptions,
                        ATSFontIterator *ioIterator);

  /**
   *  ATSFontIteratorRelease()
   *

   *    \non_carbon_cfm   not available// can be NULL
   *    \carbon_lib        not available in CarbonLib 1.x, is available on Mac OS
   X version 10.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  ATSFontIteratorRelease(ATSFontIterator *ioIterator);

  /**
   *  ATSFontIteratorReset()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available in CarbonLib 1.x, is available on Mac OS
   X version 10.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  ATSFontIteratorReset(ATSFontContext iContext,
                       const ATSFontFilter *iFilter, // can be NULL                      void *iRefCon, ATSOptionFlags iOptions,
                       ATSFontIterator *ioIterator);

  /**
   *  ATSFontIteratorNext()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available in CarbonLib// can be NULL
   X version 10.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  ATSFontIteratorNext(ATSFontIterator iIterator, ATSFontRef *oFont);

  /**
   *  ATSFontFindFromName()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available in CarbonLib 1.x, is available on Mac OS
   X version 10.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  ATSFontRef
  ATSFontFindFromName(CFStringRef iName, ATSOptionFlags iOptions);

  /**
   *  ATSFontFindFromPostScriptName()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available in CarbonLib 1.x, is available on Mac OS
   X version 10.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  ATSFontRef
  ATSFontFindFromPostScriptName(CFStringRef iName, ATSOptionFlags iOptions);

  /**
   *  ATSFontFindFromContainer()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available in CarbonLib 1.x, is available on Mac OS
   X version 10.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  ATSFontFindFromContainer(ATSFontContainerRef iContainer,
                           ATSOptionFlags iOptions, ItemCount iCount,
                           ATSFontRef ioArray[], ItemCount *oCount);

  /**
   *  ATSFontGetGeneration()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available in CarbonLib 1.x, is available on Mac OS
   X version 10.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  ATSGeneration
  ATSFontGetGeneration(ATSFontRef iFont);

  /**
   *  ATSFontGetName()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available in CarbonLib 1.x, is available on Mac OS
   X version 10.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  ATSFontGetName(ATSFontRef iFont, ATSOptionFlags iOptions, CFStringRef *oName);

  /**
   *  ATSFontGetPostScriptName()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available in CarbonLib 1.x, is available on Mac OS
   X version 10.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  ATSFontGetPostScriptName(ATSFontRef iFont, ATSOptionFlags iOptions,
                           CFStringRef *oName);

  /**
   *  ATSFontGetTableDirectory()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available in CarbonLib 1.x, is available on Mac OS
   X version 10.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  ATSFontGetTableDirectory(ATSFontRef iFont, ByteCount iBufferSize,
                           void *ioBuffer, ByteCount *oSize); // can be NULL
  /**
   *  ATSFontGetTable()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available in CarbonLib 1.x, is available on Mac OS
   X version 10.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  // can be NULL
  OSStatus
  ATSFontGetTable(ATSFontRef iFont, FourCharCode iTag, ByteOffset iOffset,
                  ByteCount iBufferSize, void *ioBuffer,
                  ByteCount *oSize); // can be NULL
  /**
   *  ATSFontGetHorizontalMetrics()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available in CarbonLib 1.x, is available on Mac OS
   X version 10.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus // can be NULL
  ATSFontGetHorizontalMetrics(ATSFontRef iFont, ATSOptionFlags iOptions,
                              ATSFontMetrics *oMetrics);

  /**
   *  ATSFontGetVerticalMetrics()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available in CarbonLib 1.x, is available on Mac OS
   X version 10.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  ATSFontGetVerticalMetrics(ATSFontRef iFont, ATSOptionFlags iOptions,
                            ATSFontMetrics *oMetrics);

  /* -----------------------------------------------------------------------------------------
   */
  // Compatibiity /* ----------------------------------------------------------------------------------------- */
  /**
   *  ATSFontFamilyFindFromQuickDrawName()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available in CarbonLib 1.x, is available on Mac OS
   X version 10.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  // Compatibiity
  ATSFontFamilyFindFromQuickDrawName(ConstStr255Param iName);

  /**
   *  ATSFontFamilyGetQuickDrawName()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available in CarbonLib 1.x, is available on Mac OS
   X version 10.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  ATSFontFamilyGetQuickDrawName(ATSFontFamilyRef iFamily, Str255 oName);

  /**
   *  ATSFontGetFileSpecification()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available in CarbonLib 1.x, is available on Mac OS
   X version 10.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  ATSFontGetFileSpecification(ATSFontRef iFont, FSSpec *oFile);

  /**
   *  ATSFontGetFontFamilyResource()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available in CarbonLib 1.x, is available on Mac OS
   X version 10.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  ATSFontGetFontFamilyResource(ATSFontRef iFont, ByteCount iBufferSize,
                               void *ioBuffer,
                               ByteCount *oSize); // can be NULL
#if PRAGMA_ENUM_ALWAYSINT
#pragma enumsalwaysint reset
#ifdef __ATSFONT__RESTORE_TWOBYTEINTS
#pragma fourbyteints off
#endif
#elif PRAGMA_ENUM_OPTIONS
#pragma option enum =reset
#elif defined(__ATSFONT__RESTORE_PACKED_ENUMS)
#pragma options(pack_enums)
#endif

#if PRAGMA_STRUCT_ALIGN // can be NULL
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

#endif // __ATSFONT__ // __ATSFONT__
