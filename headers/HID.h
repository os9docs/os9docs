/**
     \file       HID.h

    \brief   Definition of the interfaces to the HIDLib shared library and

    \introduced_in  HID 1.0
    \avaliable_from Universal Interfaces 3.4.1

    \copyright � 1999-2001 by Apple Computer, Inc., all rights reserved.

    \ingroup Misc
    
    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __HID__
#define __HID__

#ifndef __MACTYPES__
#include <MacTypes.h>
#endif

#ifndef __MACERRORS__
#include <MacErrors.h>
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

/**

    Interfaces for HIDLib
*/

// types of HID reports (input, output, feature)enum {
  kHIDInputReport = 1,
  kHIDOutputReport = 2,
  kHIDFeatureReport = 3,
  kHIDUnknownReport = 255
};

// constants used in HIDButtonCapabilities and HIDValueCapabilities structuresenum {
// constants used in HIDButtonCapabilities and HIDValueCapabilities structures
     HIDValueCapabilities.*/
  // While HIDButtonCaps and HIDValueCaps have no version #, they can be
};

// flags passed to HIDOpenReportDescriptorenum { kHIDFlag_StrictErrorChecking = 0x00000001 };

typedef UInt32 HIDReportType;
// flags passed to HIDOpenReportDescriptor
typedef struct OpaqueHIDPreparsedDataRef *HIDPreparsedDataRef;
struct HIDUsageAndPage {
  HIDUsage usage;
  HIDUsage usagePage;
};
typedef struct HIDUsageAndPage HIDUsageAndPage;
typedef HIDUsageAndPage *HIDUsageAndPagePtr;
struct HIDCaps {
  HIDUsage usage;
  HIDUsage usagePage;
  ByteCount inputReportByteLength;
  ByteCount outputReportByteLength;
  ByteCount featureReportByteLength;
  UInt32 numberCollectionNodes;
  UInt32 numberInputButtonCaps;
  UInt32 numberInputValueCaps;
  UInt32 numberOutputButtonCaps;
  UInt32 numberOutputValueCaps;
  UInt32 numberFeatureButtonCaps;
  UInt32 numberFeatureValueCaps;
};
typedef struct HIDCaps HIDCaps;
typedef HIDCaps *HIDCapsPtr;
struct HIDCapabilities {
  HIDUsage usage;
  HIDUsage usagePage;
  ByteCount inputReportByteLength;
  ByteCount outputReportByteLength;
  ByteCount featureReportByteLength;
  UInt32 numberCollectionNodes;
  UInt32 numberInputButtonCaps;
  UInt32 numberInputValueCaps;
  UInt32 numberOutputButtonCaps;
  UInt32 numberOutputValueCaps;
  UInt32 numberFeatureButtonCaps;
  UInt32 numberFeatureValueCaps;
};
typedef struct HIDCapabilities HIDCapabilities;
typedef HIDCapabilities *HIDCapabilitiesPtr;
struct HIDCollectionNode {
  HIDUsage collectionUsage;
  HIDUsage collectionUsagePage;
  UInt32 parent;
  UInt32 numberOfChildren;
  UInt32 nextSibling;
  UInt32 firstChild;
};
typedef struct HIDCollectionNode HIDCollectionNode;
typedef HIDCollectionNode *HIDCollectionNodePtr;
struct HIDButtonCaps {
  HIDUsage usagePage;
  UInt32 reportID;
  UInt32 bitField;
  UInt32 collection;
  HIDUsage collectionUsage;
  HIDUsage collectionUsagePage;
  Boolean isRange;
  Boolean isStringRange;
  Boolean isDesignatorRange;
  Boolean isAbsolute;

  union {
    struct {
      HIDUsage usageMin;
      HIDUsage usageMax;
      UInt32 stringMin;
      UInt32 stringMax;
      UInt32 designatorMin;
      UInt32 designatorMax;
    } range;
    struct {
      HIDUsage usage;
      HIDUsage reserved1;
      UInt32 stringIndex;
      UInt32 reserved2;
      UInt32 designatorIndex;
      UInt32 reserved3;
    } notRange;
  } u;
};
typedef struct HIDButtonCaps HIDButtonCaps;
typedef HIDButtonCaps *HIDButtonCapsPtr;
struct HIDButtonCapabilities {
  HIDUsage usagePage;
  UInt32 reportID;
  UInt32 bitField;
  UInt32 collection;
  HIDUsage collectionUsage;
  HIDUsage collectionUsagePage;

  Boolean isRange;
  Boolean isStringRange;
  Boolean isDesignatorRange;
  Boolean isAbsolute;

  SInt32 unitExponent;
  SInt32 units;
  UInt32 reserved;
  UInt32 pbVersion;

  union {
    struct {
      HIDUsage usageMin;
      HIDUsage usageMax;
      UInt32 stringMin;
      UInt32 stringMax;
      UInt32 designatorMin;
      UInt32 designatorMax;
    } range;
    struct {
      HIDUsage usage;
      HIDUsage reserved1;
      UInt32 stringIndex;
      UInt32 reserved2;
      UInt32 designatorIndex;
      UInt32 reserved3;
    } notRange;
  } u;
};
typedef struct HIDButtonCapabilities HIDButtonCapabilities;
typedef HIDButtonCapabilities *HIDButtonCapabilitiesPtr;
struct HIDValueCaps {
  HIDUsage usagePage;
  UInt32 reportID;
  UInt32 bitField;
  UInt32 collection;
  HIDUsage collectionUsage;
  HIDUsage collectionUsagePage;

  Boolean isRange;
  Boolean isStringRange;
  Boolean isDesignatorRange;
  Boolean isAbsolute;

  UInt32 bitSize;
  UInt32 reportCount;

  SInt32 logicalMin;
  SInt32 logicalMax;
  SInt32 physicalMin;
  SInt32 physicalMax;

  union {
    struct {
      HIDUsage usageMin;
      HIDUsage usageMax;
      UInt32 stringMin;
      UInt32 stringMax;
      UInt32 designatorMin;
      UInt32 designatorMax;
    } range;
    struct {
      HIDUsage usage;
      HIDUsage reserved1;
      UInt32 stringIndex;
      UInt32 reserved2;
      UInt32 designatorIndex;
      UInt32 reserved3;
    } notRange;
  } u;
};
typedef struct HIDValueCaps HIDValueCaps;
typedef HIDValueCaps *HIDValueCapsPtr;
struct HIDValueCapabilities {
  HIDUsage usagePage;
  UInt32 reportID;
  UInt32 bitField;
  UInt32 collection;
  HIDUsage collectionUsage;
  HIDUsage collectionUsagePage;

  Boolean isRange;
  Boolean isStringRange;
  Boolean isDesignatorRange;
  Boolean isAbsolute;

  UInt32 bitSize;
  UInt32 reportCount;

  SInt32 logicalMin;
  SInt32 logicalMax;
  SInt32 physicalMin;
  SInt32 physicalMax;

  SInt32 unitExponent;
  SInt32 units;
  UInt32 reserved;
  UInt32 pbVersion;

  union {
    struct {
      HIDUsage usageMin;
      HIDUsage usageMax;
      UInt32 stringMin;
      UInt32 stringMax;
      UInt32 designatorMin;
      UInt32 designatorMax;
    } range;
    struct {
      HIDUsage usage;
      HIDUsage reserved1;
      UInt32 stringIndex;
      UInt32 reserved2;
      UInt32 designatorIndex;
      UInt32 reserved3;
    } notRange;
  } u;
};
typedef struct HIDValueCapabilities HIDValueCapabilities;
typedef HIDValueCapabilities *HIDValueCapabilitiesPtr;
#if CALL_NOT_IN_CARBON
/**
 *  HIDGetHIDLibVersion()
 *
 *  Availability:
 *    \non_carbon_cfm   in HIDLib 1.4.3 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
UInt32
HIDGetHIDLibVersion(void);

/**
 *  HIDOpenReportDescriptor()
 *
 *  Availability:
 *    \non_carbon_cfm   in HIDLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSStatus
HIDOpenReportDescriptor(void *hidReportDescriptor, ByteCount descriptorLength,
                        HIDPreparsedDataRef *preparsedDataRef, UInt32 flags);

/**
 *  HIDCloseReportDescriptor()
 *
 *  Availability:
 *    \non_carbon_cfm   in HIDLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSStatus
HIDCloseReportDescriptor(HIDPreparsedDataRef preparsedDataRef);

/**
 *  HIDGetCaps()
 *
 *  Availability:
 *    \non_carbon_cfm   in HIDLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSStatus
HIDGetCaps(HIDPreparsedDataRef preparsedDataRef, HIDCapsPtr capabilities);

/**
 *  HIDGetCapabilities()
 *
 *  Availability:
 *    \non_carbon_cfm   in HIDLib 1.4.3 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSStatus
HIDGetCapabilities(HIDPreparsedDataRef preparsedDataRef,
                   HIDCapabilitiesPtr capabilities);

/**
 *  HIDGetCollectionNodes()
 *
 *  Availability:
 *    \non_carbon_cfm   in HIDLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSStatus
HIDGetCollectionNodes(HIDCollectionNodePtr collectionNodes,
                      UInt32 *collectionNodesSize,
                      HIDPreparsedDataRef preparsedDataRef);

/**
 *  HIDGetButtonCaps()
 *
 *  Availability:
 *    \non_carbon_cfm   in HIDLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSStatus
HIDGetButtonCaps(HIDReportType reportType, HIDButtonCapsPtr buttonCaps,
                 UInt32 *buttonCapsSize, HIDPreparsedDataRef preparsedDataRef);

/**
 *  HIDGetButtonCapabilities()
 *
 *  Availability:
 *    \non_carbon_cfm   in HIDLib 1.4.3 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSStatus
HIDGetButtonCapabilities(HIDReportType reportType,
                         HIDButtonCapabilitiesPtr buttonCaps,
                         UInt32 *buttonCapsSize,
                         HIDPreparsedDataRef preparsedDataRef);

/**
 *  HIDGetValueCaps()
 *
 *  Availability:
 *    \non_carbon_cfm   in HIDLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSStatus
HIDGetValueCaps(HIDReportType reportType, HIDValueCapsPtr valueCaps,
                UInt32 *valueCapsSize, HIDPreparsedDataRef preparsedDataRef);

/**
 *  HIDGetValueCapabilities()
 *
 *  Availability:
 *    \non_carbon_cfm   in HIDLib 1.4.3 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSStatus
HIDGetValueCapabilities(HIDReportType reportType,
                        HIDValueCapabilitiesPtr valueCaps,
                        UInt32 *valueCapsSize,
                        HIDPreparsedDataRef preparsedDataRef);

/**
 *  HIDGetSpecificButtonCaps()
 *
 *  Availability:
 *    \non_carbon_cfm   in HIDLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSStatus
HIDGetSpecificButtonCaps(HIDReportType reportType, HIDUsage usagePage,
                         UInt32 collection, HIDUsage usage,
                         HIDButtonCapsPtr buttonCaps, UInt32 *buttonCapsSize,
                         HIDPreparsedDataRef preparsedDataRef);

/**
 *  HIDGetSpecificButtonCapabilities()
 *
 *  Availability:
 *    \non_carbon_cfm   in HIDLib 1.4.3 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSStatus
HIDGetSpecificButtonCapabilities(HIDReportType reportType, HIDUsage usagePage,
                                 UInt32 collection, HIDUsage usage,
                                 HIDButtonCapabilitiesPtr buttonCaps,
                                 UInt32 *buttonCapsSize,
                                 HIDPreparsedDataRef preparsedDataRef);

/**
 *  HIDGetSpecificValueCaps()
 *
 *  Availability:
 *    \non_carbon_cfm   in HIDLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSStatus
HIDGetSpecificValueCaps(HIDReportType reportType, HIDUsage usagePage,
                        UInt32 collection, HIDUsage usage,
                        HIDValueCapsPtr valueCaps, UInt32 *valueCapsSize,
                        HIDPreparsedDataRef preparsedDataRef);

/**
 *  HIDGetSpecificValueCapabilities()
 *
 *  Availability:
 *    \non_carbon_cfm   in HIDLib 1.4.3 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSStatus
HIDGetSpecificValueCapabilities(HIDReportType reportType, HIDUsage usagePage,
                                UInt32 collection, HIDUsage usage,
                                HIDValueCapabilitiesPtr valueCaps,
                                UInt32 *valueCapsSize,
                                HIDPreparsedDataRef preparsedDataRef);

/**
 *  HIDGetNextButtonInfo()
 *
 *  Availability:
 *    \non_carbon_cfm   in HIDLib 1.4 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSStatus
HIDGetNextButtonInfo(HIDReportType reportType, HIDUsage usagePage,
                     HIDUsage usage, UInt32 *collection, UInt8 *reportID,
                     HIDPreparsedDataRef preparsedDataRef);

/**
 *  HIDGetNextUsageValueInfo()
 *
 *  Availability:
 *    \non_carbon_cfm   in HIDLib 1.4 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSStatus
HIDGetNextUsageValueInfo(HIDReportType reportType, HIDUsage usagePage,
                         HIDUsage usage, UInt32 *collection, UInt8 *reportID,
                         HIDPreparsedDataRef preparsedDataRef);

/**
 *  HIDMaxUsageListLength()
 *
 *  Availability:
 *    \non_carbon_cfm   in HIDLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
UInt32
HIDMaxUsageListLength(HIDReportType reportType, HIDUsage usagePage,
                      HIDPreparsedDataRef preparsedDataRef);

/**
 *  HIDGetReportLength()
 *
 *  Availability:
 *    \non_carbon_cfm   in HIDLib 1.4 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSStatus
HIDGetReportLength(HIDReportType reportType, UInt8 reportID,
                   ByteCount *reportLength,
                   HIDPreparsedDataRef preparsedDataRef);

/**
 *  HIDInitReport()
 *
 *  Availability:
 *    \non_carbon_cfm   in HIDLib 1.4 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSStatus
HIDInitReport(HIDReportType reportType, UInt8 reportID,
              HIDPreparsedDataRef preparsedDataRef, void *report,
              ByteCount reportLength);

/**
 *  HIDGetButtons()
 *
 *  Availability:
 *    \non_carbon_cfm   in HIDLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSStatus
HIDGetButtons(HIDReportType reportType, UInt32 collection,
              HIDUsageAndPagePtr usageList, UInt32 *usageListSize,
              HIDPreparsedDataRef preparsedDataRef, void *report,
              ByteCount reportLength);

/**
 *  HIDGetButtonsOnPage()
 *
 *  Availability:
 *    \non_carbon_cfm   in HIDLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSStatus
HIDGetButtonsOnPage(HIDReportType reportType, HIDUsage usagePage,
                    UInt32 collection, HIDUsage *usageList,
                    UInt32 *usageListSize, HIDPreparsedDataRef preparsedDataRef,
                    void *report, ByteCount reportLength);

/**
 *  HIDGetScaledUsageValue()
 *
 *  Availability:
 *    \non_carbon_cfm   in HIDLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSStatus
HIDGetScaledUsageValue(HIDReportType reportType, HIDUsage usagePage,
                       UInt32 collection, HIDUsage usage, SInt32 *usageValue,
                       HIDPreparsedDataRef preparsedDataRef, void *report,
                       ByteCount reportLength);

/**
 *  HIDGetUsageValue()
 *
 *  Availability:
 *    \non_carbon_cfm   in HIDLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSStatus
HIDGetUsageValue(HIDReportType reportType, HIDUsage usagePage,
                 UInt32 collection, HIDUsage usage, SInt32 *usageValue,
                 HIDPreparsedDataRef preparsedDataRef, void *report,
                 ByteCount reportLength);

/**
 *  HIDGetUsageValueArray()
 *
 *  Availability:
 *    \non_carbon_cfm   in HIDLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSStatus
HIDGetUsageValueArray(HIDReportType reportType, HIDUsage usagePage,
                      UInt32 collection, HIDUsage usage, Byte *usageValueBuffer,
                      ByteCount usageValueBufferSize,
                      HIDPreparsedDataRef preparsedDataRef, void *report,
                      ByteCount reportLength);

/**
 *  HIDSetButton()
 *
 *  Availability:
 *    \non_carbon_cfm   in HIDLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSStatus
HIDSetButton(HIDReportType reportType, HIDUsage usagePage, UInt32 collection,
             HIDUsage usage, HIDPreparsedDataRef preparsedDataRef, void *report,
             ByteCount reportLength);

/**
 *  HIDSetButtons()
 *
 *  Availability:
 *    \non_carbon_cfm   in HIDLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSStatus
HIDSetButtons(HIDReportType reportType, HIDUsage usagePage, UInt32 collection,
              HIDUsage *usageList, UInt32 *usageListSize,
              HIDPreparsedDataRef preparsedDataRef, void *report,
              ByteCount reportLength);

/**
 *  HIDSetScaledUsageValue()
 *
 *  Availability:
 *    \non_carbon_cfm   in HIDLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSStatus
HIDSetScaledUsageValue(HIDReportType reportType, HIDUsage usagePage,
                       UInt32 collection, HIDUsage usage, SInt32 usageValue,
                       HIDPreparsedDataRef preparsedDataRef, void *report,
                       ByteCount reportLength);

/**
 *  HIDSetUsageValue()
 *
 *  Availability:
 *    \non_carbon_cfm   in HIDLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSStatus
HIDSetUsageValue(HIDReportType reportType, HIDUsage usagePage,
                 UInt32 collection, HIDUsage usage, SInt32 usageValue,
                 HIDPreparsedDataRef preparsedDataRef, void *report,
                 ByteCount reportLength);

/**
 *  HIDSetUsageValueArray()
 *
 *  Availability:
 *    \non_carbon_cfm   in HIDLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSStatus
HIDSetUsageValueArray(HIDReportType reportType, HIDUsage usagePage,
                      UInt32 collection, HIDUsage usage, Byte *usageValueBuffer,
                      ByteCount usageValueBufferLength,
                      HIDPreparsedDataRef preparsedDataRef, void *report,
                      ByteCount reportLength);

/**
 *  HIDUsageListDifference()
 *
 *  Availability:
 *    \non_carbon_cfm   in HIDLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSStatus
HIDUsageListDifference(HIDUsage *previousUsageList, HIDUsage *currentUsageList,
                       HIDUsage *breakUsageList, HIDUsage *makeUsageList,
                       UInt32 usageListsSize);

/**

    Interfaces for a HID device driver
*/

// these are the constants to be passed to HIDGetDeviceInfo#endif // CALL_NOT_IN_CARBON 
enum {
  kHIDGetInfo_VendorID = 1,
  kHIDGetInfo_ProductID = 2,
// these are the constants to be passed to HIDGetDeviceInfo
  kHIDG// CALL_NOT_IN_CARBON 
  kHIDGetInfo_MaxReportSize = 0x10,
  kHIDGetInfo_GetManufacturerString = 0x0100,
  kHIDGetInfo_GetProductString = 0x0101,
  kHIDGetInfo_GetSerialNumberString = 0x0102,
  kHIDGetInfo_VendorSpecificStart = 0x00010000
};

// these are the valid permissions to pass to HIDOpenDeviceenum {
  kHIDPerm_ReadOnly = 0x0001,
  kHIDPerm_ReadWriteShared = 0x0003,
  kHIDPerm_ReadWriteExclusive = 0x0013
};

// these are the valid permissions to pass to HIDOpenDevice

// these are the constants to be passed to HIDControlDeviceenum { kHIDVendorSpecificControlStart = 0x00010000 };

// these constant versions are used in the HIDDeviceDispatchTable structureenum {
  kHIDCurrentDispatchTableVersion = 3,
  kHIDOldestCompatableDispatchTableVersion = 1,
// these are flags used in HIDInstallReportHandler
  kHIDDispatchTableVersion2 = 2,
  kHIDDispatchTableVersion1OldestCompatible = 1
// these are the constants to be passed to HIDControlDevice

typedef struct OpaqueHIDDeviceConnectionRef *HIDDeviceConnectionRef;
// these constant versions are used in the HIDDeviceDispatchTable structure
                                                          void *outInfo,
                                                          ByteCount *ioSize);
/* HIDGetHIDDescriptor is used to get a specific HID descriptor from a HID
 * device (such as a report descriptor)*/
typedef CALLBACK_API_C(OSStatus,
                       HIDGetHIDDescriptorProcPtr)(UInt32 inDescriptorType,
                                                   UInt32 inDescriptorIndex,
                                                   void *outDescriptor,
                                                   UInt32 *ioBufferSize);
// HIDGetDeviceInfo is used to get specific information about a HID Device
    HIDDeviceConnectionRef *outConnectionRef, UInt32 permissions,
    UInt32 reserved);
// When finished, 'close' a devicetypedef CALLBACK_API_C(OSStatus, HIDCloseDeviceProcPtr)(
    HIDDeviceConnectionRef inConnectionRef);
// User provided ProcPtr to be called when HID report is receivedtypedef CALLBACK_API_C(void, HIDReportHandlerProcPtr)(void *inHIDReport,
                                                      UInt32 inHIDReportLength,
                                                      UInt32 inRefcon);
// User provided ProcPtr to be called when indexed string is receivedtypedef CALLBACK_API_C(void, HIDStringHandlerProcPtr)(void *inHIDReport,
                                                      UInt32 inHIDReportLength,
                                                      UInt32 inRefcon,
// You must first 'open' a device before using it
/**
   When installed, a report handler is called at defered task time (unless
   kHIDFlag_CallbackIsResident is passed) whenever an interrupt packet is
// When finished, 'close' a device
   thru.
*/
// User provided ProcPtr to be called when HID report is received
    HIDDeviceConnectionRef inConnectionRef, UInt32 flags,
    HIDReportHandlerProcPtr inReportHandlerProc, UInt32 inRefcon);
// When finished, remove the report handler.typedef CALLBACK_API_C(OSStatus, HIDRemoveReportHandlerProcPtr)(
// User provided ProcPtr to be called when indexed string is received
/* If there was a HIDReportHandler installed previous to the one from this
 * connection, pass that one this report*/
typedef CALLBACK_API_C(OSStatus, HIDCallPreviousReportHandlerProcPtr)(
    HIDDeviceConnectionRef inConnectionRef, void *inHIDReport,
    UInt32 inHIDReportLength);
/**
   HIDGetReport is used to get a report (of type input, output, or feature)
   directly from a HID device the HIDReportHandler will be called with the
   report when it is received.
*/
typedef CALLBACK_API_C(OSStatus, HIDGetReportProcPtr)(
    HIDDeviceConnectionRef inConnectionRef, UInt32 inReportType,
    UInt32 inReportID, HIDReportHandlerProcPtr inReportHandlerProc,
// When finished, remove the report handler.
/* HIDGetSizedReport is used like HIDGetReport, but for devices that require
 * exact size to return report.*/
typedef CALLBACK_API_C(OSStatus, HIDGetSizedReportProcPtr)(
    HIDDeviceConnectionRef inConnectionRef, UInt32 inReportType,
    UInt32 inReportID, ByteCount inSize,
    HIDReportHandlerProcPtr inReportHandlerProc, UInt32 inRefcon);
/* HIDSetReport is used to send a report (of type input, output, or feature)
 * directly to a HID device*/
typedef CALLBACK_API_C(OSStatus, HIDSetReportProcPtr)(
    HIDDeviceConnectionRef inConnectionRef, UInt32 inReportType,
    UInt32 inReportID, void *inInfo, ByteCount inSize);
// HIDControlDevice is used to send misc control messages to a devicetypedef CALLBACK_API_C(OSStatus, HIDControlDeviceProcPtr)(
    HIDDeviceConnectionRef inConnectionRef, UInt32 inControlSelector,
    void *ioControlData);
/**
   HIDGetIndexedString is used to get a string directly from a HID device.
   The HIDStringHandler will be called with the string when it is received or
   nil string if completed with an error.
*/
typedef CALLBACK_API_C(OSStatus, HIDGetIndexedStringProcPtr)(
    HIDDeviceConnectionRef inConnectionRef, UInt32 inStringIndex,
    UInt32 inStringLanguage, HIDStringHandlerProcPtr inStringHandlerProc,
    UInt32 inRefcon);
/**
   dispatchTableCurrentVersion is kHIDCurrentDispatchTableVersion
   dispatchTableOldestVersion is kHIDOldestCompatableDispatchTableVersion
        (the oldest built client using this API that this HID device driver will
// HIDControlDevice is used to send misc control messages to a device
   vendorID is valid)
*/
struct HIDDeviceDispatchTable {
  UInt32 dispatchTableCurrentVersion;
  UInt32 dispatchTableOldestVersion;
  UInt32 vendorID;
  UInt32 vendorSpecific;
  UInt32 reserved;

  HIDGetDeviceInfoProcPtr pHIDGetDeviceInfo;
  HIDGetHIDDescriptorProcPtr pHIDGetHIDDescriptor;
  HIDOpenDeviceProcPtr pHIDOpenDevice;
  HIDCloseDeviceProcPtr pHIDCloseDevice;
  HIDInstallReportHandlerProcPtr pHIDInstallReportHandler;
  HIDRemoveReportHandlerProcPtr pHIDRemoveReportHandler;
  HIDCallPreviousReportHandlerProcPtr pHIDCallPreviousReportHandler;
  HIDGetReportProcPtr
      pHIDGetReport; // new for vers 2, was reserved in version 1  HIDSetReportProcPtr
      pHIDSetReport; // new for vers 2, was reserved in version 1  HIDControlDeviceProcPtr pHIDControlDevice;
  HIDGetIndexedStringProcPtr pHIDGetIndexedString; // new for vers 3  HIDGetSizedReportProcPtr pHIDGetSizedReport;     // new for vers 3};
typedef struct HIDDeviceDispatchTable HIDDeviceDispatchTable;
typedef HIDDeviceDispatchTable *HIDDeviceDispatchTablePtr;
// A USB HIDDevice driver should export a HIDDeviceDispatchTable symbol // in it's PEF container, with the name "\pTheHIDDeviceDispatchTable" 
/* ******************************************************************************************
 */
// HID Usage Tables //                                                                                            /* The following constants are from the USB 'HID Usage Tables' specification,
 * revision 1.1rc3 */
/* ******************************************************************************************
 */

// Usage Pages enum {
  kHIDPage_Undefined = 0x00,
  kHIDPage_GenericDesktop = 0x01,
  kHIDPage_Simulation = 0x02,
  kHIDPage_VR = 0x03,// new for vers 2, was reserved in version 1
  kHIDPage_Sport = 0x04,
  kHIDPage_Game = 0x0// new for vers 2, was reserved in version 1
      0x07, /* USB Device Class Definition for Human Interface Devices (HID).
               Note: the usage type for all key cod// new for vers 3
  kHIDPage_LEDs = 0x08,// new for vers 3
  kHIDPage_Button = 0x09,
  kHIDPage_Ordinal = 0x0A,
  kHIDPage_Telephony = 0x0B,
// A USB HIDDevice driver should export a HIDDeviceDispatchTable symbol 
// in it's PEF container, with the name "\pTheHIDDeviceDispatchTable" 
                          feedback and related devices. */
  kHIDPage_Unicode = 0x10,             // Reserved 0x11 - 0x13   kHIDPage_AlphanumericDisplay = 0x14, // Reserved 0x15 - 0x7F   // Monitor 0x80 - 0x83     USB Device Class Definition for Monitor Devices   // Power 0x84 - 0x87   USB Device Class Definition for Power Devices   // Reserved 0x88 - 0x8B   kHIDPage_BarCodeScanner = 0x8C, /* (Point of Sale) USB Device Class Definition
                                     for Bar Code Scanner Devices */
// HID Usage Tables 
//                                                                                            
      0x90, // USB Device Class Definition for Image Class Devices   kHIDPage_Arcade =
      0x91, // OAAF Definitions for arcade and coinop related Devices             // Reserved 0x92 - 0xFEFF             // VendorDefined 0xFF00 - 0xFFFF   kHIDPage_VendorDefinedStart = 0xFF00
};

// Undefined Usage for all usage pages enum { kHIDUsage_Undefined = 0x00 };
// Usage Pages 
// GenericDesktop Page (0x01) enum {
  kHIDUsage_GD_Pointer = 0x01,             // Physical Collection   kHIDUsage_GD_Mouse = 0x02,               // Application Collection                                            // 0x03 Reserved   kHIDUsage_GD_Joystick = 0x04,            // Application Collection   kHIDUsage_GD_GamePad = 0x05,             // Application Collection   kHIDUsage_GD_Keyboard = 0x06,            // Application Collection   kHIDUsage_GD_Keypad = 0x07,              // Application Collection   kHIDUsage_GD_MultiAxisController = 0x08, // Application Collection                                            // 0x09 - 0x2F Reserved   kHIDUsage_GD_X = 0x30,                   // Dynamic Value   kHIDUsage_GD_Y = 0x31,                   // Dynamic Value   kHIDUsage_GD_Z = 0x32,                   // Dynamic Value   kHIDUsage_GD_Rx = 0x33,                  // Dynamic Value   kHIDUsage_GD_Ry = 0x34,                  // Dynamic Value   kHIDUsage_GD_Rz = 0x35,                  // Dynamic Value   kHIDUsage_GD_Slider = 0x36,              // Dynamic Value   kHIDUsage_GD_Dial = 0x37,                // Dynamic Value   kHIDUsage_GD_Wheel = 0x38,               // Dynamic Value   kHIDUsage_GD_Hatswitch = 0x39,           // Dynamic Value   kHIDUsage_GD_CountedBuffer = 0x3A,       // Logical Collection   kHIDUsage_GD_ByteCount = 0x3B,           // Dynamic Value   kHIDUsage_GD_MotionWakeup = 0x3C,        // One-Shot Control   kHIDUsage_GD_Start = 0x3D,               // On/Off Control   kHIDUsage_GD_Select = 0x3E,              // On/Off Control                                            // 0x3F Reserved   kHIDUsage_GD_Vx = 0x40,                  // Dynamic Value   kHIDUsage_GD_Vy = 0x41,                  // Dynamic Value   kHIDUsage_GD_Vz = 0x42,                  // Dynamic Value   kHIDUsage_GD_Vbrx = 0x43,                // Dynamic Value   kHIDUsage_GD_Vbry = 0x44,                // Dynamic Value   kHIDUsage_GD_Vbrz = 0x45,                // Dynamic Value   kHIDUsage_GD_Vno = 0x46,                 // Dynamic Value                                            // 0x47 - 0x7F Reserved   kHIDUsage_GD_SystemControl = 0x80,       // Application Collection   kHIDUsage_GD_SystemPowerDown = 0x81,     // One-Shot Control   kHIDUsage_GD_SystemSleep = 0x82,         // One-Shot Control   kHIDUsage_GD_SystemWakeUp = 0x83,        // One-Shot Control   kHIDUsage_GD_SystemContextMenu = 0x84,   // One-Shot Control   kHIDUsage_GD_SystemMainMenu = 0x85,      // One-Shot Control   kHIDUsage_GD_SystemAppMenu = 0x86,       // One-Shot Control   kHIDUsage_GD_SystemMenuHelp = 0x87,      // One-Shot Control   kHIDUsage_GD_SystemMenuExit = 0x88,      // One-Shot Control   kHIDUsage_GD_SystemMenu = 0x89,          // Selector   kHIDUsage_GD_SystemMenuRight = 0x8A,     // Re-Trigger Control   kHIDUsage_GD_SystemMenuLeft = 0x8B,      // Re-Trigger Control   kHIDUsage_GD_SystemMenuUp = 0x8C,        // Re-Trigger Control   kHIDUsage_GD_SystemMenuDown = 0x8D,      // Re-Trigger Control                                            // 0x8E - 0x8F Reserved   kHIDUsage_GD_DPadUp = 0x90,              // On/Off Control   kHIDUsage_GD_DPadDown = 0x91,            // On/Off Control   kHIDUsage_GD_DPadRight = 0x92,           // On/Off Control   kHIDUsage_GD_DPadLeft = 0x93,            // On/Off Control                                            // 0x94 - 0xFFFF Reserved   kHIDUsage_GD_Reserved = 0xFFFF
};

// Simulation Page (0x02) /* This section provides detailed descriptions of the usages employed by
 * simulation devices. */
enum {// Reserved 0x06 
  kHIDUsage_Sim_FlightSimulationDevice = 0x01,      // Application Collection   kHIDUsage_Sim_AutomobileSimulationDevice = 0x02,  // Application Collection   kHIDUsage_Sim_TankSimulationDevice = 0x03,        // Application Collection   kHIDUsage_Sim_SpaceshipSimulationDevice = 0x04,   // Application Collection   kHIDUsage_Sim_SubmarineSimulationDevice = 0x05,   // Application Collection   kHIDUsage_Sim_SailingSimulationDevice = 0x06,     // Application Collection   kHIDUsage_Sim_MotorcycleSimulationDevice = 0x07,  // Application Collection   kHIDUsage_Sim_SportsSimulationDevice = 0x08,      // Application Collection   kHIDUsage_Sim_AirplaneSimulationDevice = 0x09,    // Application Collection   kHIDUsage_Sim_HelicopterSimulationDevice = 0x0A,  // Application Collection   kHIDUsage_Sim_MagicCarpetSimulationDevice = 0x0B, // Application Collection   kHIDUsage_Sim_BicycleSimulationDevice = 0x0C,     // Application Collection                                                     // 0x0D - 0x1F Reserved   kHIDUsage_Sim_FlightControlStick = 0x20,          // Application Collection   kHIDUsage_Sim_FlightStick = 0x21,                 // Application Collection   kHIDUsage_Sim_CyclicControl = 0x22,               // Physical Collection   kHIDUsage_Sim_CyclicTrim = 0x23,                  // Physical Collection   kHIDUsage_Sim_FlightYoke = 0x24,                  // Application Collection   kHIDUsage_Sim_TrackControl = 0x25,                // Physical Collection                                                     // 0x26 - 0xAF Reserved   kHIDUsage_Sim_Aileron = 0xB0,                     // Dynamic Value   kHIDUsage_Sim_AileronTrim = 0xB1,                 // Dynamic Value   kHIDUsage_Sim_AntiTorqueControl = 0xB2,           // Dynamic Value   kHIDUsage_Sim_AutopilotEnable = 0xB3,             // On/Off Control   kHIDUsage_Sim_ChaffRelease = 0xB4,                // One-Shot Control   kHIDUsage_Sim_CollectiveControl = 0xB5,           // Dynamic Value   kHIDUsage_Sim_DiveBrake = 0xB6,                   // Dynamic Value   kHIDUsage_Sim_ElectronicCountermeasures = 0xB7,   // On/Off Control   kHIDUsage_Sim_Elevator = 0xB8,                    // Dynamic Value   kHIDUsage_Sim_ElevatorTrim = 0xB9,                // Dynamic Value   kHIDUsage_Sim_Rudder = 0xBA,                      // Dynamic Value   kHIDUsage_Sim_Throttle = 0xBB,                    // Dynamic Value   kHIDUsage_Sim_FlightCommunications = 0xBC,        // On/Off Control   kHIDUsage_Sim_FlareRelease = 0xBD,                // One-Shot Control   kHIDUsage_Sim_LandingGear = 0xBE,                 // On/Off Control   kHIDUsage_Sim_ToeBrake = 0xBF,                    // Dynamic Value   kHIDUsage_Sim_Trigger = 0xC0,                     // Momentary Control   kHIDUsage_Sim_WeaponsArm = 0xC1,                  // On/Off Control   kHIDUsage_Sim_Weapons = 0xC2,                     // Selector   kHIDUsage_Sim_WingFlaps = 0xC3,                   // Dynamic Value   kHIDUsage_Sim_Accelerator = 0xC4,                 // Dynamic Value   kHIDUsage_Sim_Brake = 0xC5,                       // Dynamic Value   kHIDUsage_Sim_Clutch = 0xC6,                      // Dynamic Value   kHIDUsage_Sim_Shifter = 0xC7,                     // Dynamic Value   kHIDUsage_Sim_Steering = 0xC8,                    // Dynamic Value   kHIDUsage_Sim_TurretDirection = 0xC9,             // Dynamic Value   kHIDUsage_Sim_BarrelElevation = 0xCA,             // Dynamic Value   kHIDUsage_Sim_DivePlane = 0xCB,                   // Dynamic Value   kHIDUsage_Sim_Ballast = 0xCC,                     // Dynamic Value   kHIDUsage_Sim_BicycleCrank = 0xCD,                // Dynamic Value   kHIDUsage_Sim_HandleBars = 0xCE,                  // Dynamic Value   kHIDUsage_Sim_FrontBrake = 0xCF,                  // Dynamic Value   kHIDUsage_Sim_RearBrake = 0xD0,                   // Dynamic Value                                                     // 0xD1 - 0xFFFF Reserved   kHIDUsage_Sim_Reserved = 0xFFFF
};

// VR Page (0x03) /* Virtual Reality controls depend on designators to identify the individual
 * controls. Most of the following are */
/* usages are applied to the collections of entities that comprise the actual
 * device. */
enum {
  kHIDUsage_VR_Belt = 0x01,  // Reserved 0x0E 
};

// Sport Page (0x04) enum {// Reserved 0x11 - 0x13 
  kHIDUsage_Sprt_BaseballBat = 0x01,   // Reserved 0x15 - 0x7F 
};// Monitor 0x80 - 0x83     USB Device Class Definition for Monitor Devices 
// Power 0x84 - 0x87   USB Device Class Definition for Power Devices 
//// Reserved 0x88 - 0x8B 
  kHIDUsage_Game_3DGameController = 0x01,      // Application Collection   kHIDUsage_Game_PinballDevice = 0x02,         // Application Collection   kHIDUsage_Game_GunDevice = 0x03,             // Application Collection                                                // 0x04 - 0x1F Reserved   kHIDUsage_Game_PointofView = 0x20,           // Physical Collection   kHIDUsage_Game_TurnRightOrLeft = 0x21,       // Dynamic Value   kHIDUsage_Game_PitchUpOrDown = 0x22,         // Dynamic Value   kHIDUsage_Game_RollRightOrLeft = 0x23,       // Dynamic Value   kHIDUsage_Game_MoveRightOrLeft = 0x24,       // Dynamic Value   kHIDUsage_Game_MoveForwardOrBackward = 0x25, // Dynamic Value   kHIDUsage_Game_MoveUpOrDown = 0x26,          // Dynamic Value   kHIDUsage_Game_LeanRightOrLeft = 0x27,       // Dynamic Value   kHIDUsage_Game_LeanForwardOrBackward = 0x28, // Dynamic Value   kHIDUsage_Game_HeightOfPOV = 0x29,           // Dynamic Value   kHIDUsage_Game_Flipper = 0x2A,               // Momentary Control   kHIDUsage_Game_SecondaryFlipper = 0x2B,      // Momentary Control   kHIDUsage_Game_Bump = 0x2C,                  // Momentary Control   kHIDUsage_Game_NewGame = 0x2D,               // One-Shot Control   kHIDUsage_Game_ShootBall = 0x2E,             // One-Shot Control   kHIDUsage_Game_Player = 0x2F,                // One-Shot Control   kHIDUsage_Game_GunBolt = 0x30,               // On/Off Control   kHIDUsage_Game_GunClip = 0x31,               // On/Off Control   kHIDUsage_Game_Gun = 0x32,                   // Selector   kHIDUsage_Game_GunSingleShot = 0x33,         // Selector   kHIDUsage_Game_GunBurst = 0x34,              // Selector   kHIDUsage_Game_GunAutomatic = 0x35,          // Selector   kHIDUsage_Game_GunSafety = 0x36,             // On/Off Control   kHIDUsage_Game_GamepadFireOrJump = 0x37,     // Logical Collection   kHIDUsage_Game_GamepadTrigger = 0x39,        // Logical Collection                                                // 0x3A - 0xFFFF Reserved   kHIDUsage_Game_Reserved = 0xFFFF
};

// KeyboardO// (Point of Sale) USB Device Class Definition for Scale Devices 
 * keyboard.// ReservedPointofSalepages 0x8E - 0x8F 
/* A Boot Keyboard (84-, 101- or 104-key) should at a minimum support all
 * associate// USB Device Class Definition for Image Class Devices 
// indicated in the �Boot� column below. /* The usage type of all key codes is Selectors (Sel), except for the modifier
 * keys Keyb// OAAF Definitions for arcade and coinop related Devices 
// to Keyboa// Reserved 0x92 - 0xFEFF 
 * feasible // VendorDefined 0xFF00 - 0xFFFF 
/* for every language. Where this list is not specific for a key function in a
 * language, the closest equivalent key */
/* position should be used, so that a keyboard may be modified for a different
// Undefined Usage for all usage pages 
/* keycaps. One example is the Y key on a North American keyboard. In Germany
 * this is typically Z. Rather than changing */
// GenericDesktop Page (0x01) 
 * list, the vendor should use the Y Usage on */
/* both the North American and German keybo// Physical Collection 
 * existing practice in the industry, in or// Application Collection 
/* minimize the number of changes to the el// 0x03 Reserved 
 * otherlanguages. */// Application Collection 
enum {// Application Collection 
  kHIDUsage_KeyboardErrorRollOver = 0x01,  // Application Collection 
};// Application Collection 
// Application Collection 
// LEDs Page (0x08) /* An LED or indicator // 0x09 - 0x2F Reserved 
�Single button toggle� mode,// Dynamic Value 
|* where a value of 1 will turn on the indi// Dynamic Value 
off. The exceptions are described below. */// Dynamic Value 
enum {// Dynamic Value 
  kHIDUsage_LED_NumLock = 0x01,            // Dynamic Value 
};// Dynamic Value 
// Dynamic Value 
// Button Page (0x09) /* The Button page is// Dynamic Value 
 * selection controls. System graphical use// Dynamic Value 
/* interfaces typically employ a pointer an// Dynamic Value 
 * select, move and otherwise manipulate */// Logical Collection 
/* their environment. For these purposes th// Dynamic Value 
 * significance can be applied to the Butto// One-Shot Control 
/* � Button 1, Primary Button. Used for obj// On/Off Control 
click activation. On MacOS, this is the// On/Off Control 
|*   only button. Microsoft operating syste// 0x3F Reserved 
because it */// Dynamic Value 
/*   is not necessarily physically located // Dynamic Value 
 */// Dynamic Value 
/* � Button 2, Secondary Button. Used by ne// Dynamic Value 
 * browse object properties. Exposed by sys// Dynamic Value 
/*   to applications that typically assign // Dynamic Value 
 */// Dynamic Value 
/* � Button 3, Tertiary Button. Optional co// 0x47 - 0x7F Reserved 
 * seldom assigned functionality due to pre// Application Collection 
//   of two- and one-button devices. /* � B// One-Shot Control 
 * selector decreases. */// One-Shot Control 
/* In many ways the assignment of button nu// One-Shot Control 
 * Effort in Physical descriptors. */// One-Shot Control 
/* Button 1 would be used to define the but// One-Shot Control 
 * is in the �at rest� position, that is, v// One-Shot Control 
/* no effort is required by the user to act// One-Shot Control 
 * increment as the finger has to stretch t// One-Shot Control 
/* control. See Section 6.2.3, �Physical De// Selector 
 * for methods of further qualifying button// Re-Trigger Control 
enum {// Re-Trigger Control 
  kHIDUsage_Button_1 = 0x01, // (primary/tr// Re-Trigger Control 
};// Re-Trigger Control 
// 0x8E - 0x8F Reserved 
// Ordinal Page (0x0A) /* The Ordinal page // On/Off Control 
 * to be declared without requiring individ// On/Off Control 
/* enumeration in the native usage page. Fo// On/Off Control 
 * declare usages of Pointer 1, Pointer 2, // On/Off Control 
/* forth on the Generic Desktop page. When // 0x94 - 0xFFFF Reserved 
 * is, in essence, concatenated to the usages */
/* attached to the encompassing collection to create Pointer 1, Pointer 2, and
 * so forth. */
// Simulation Page (0x02) 
 * Appendix A, �Usage Examples.� By convention, */
/* an Ordinal collection is placed inside the collection for which it is
 * declaring multiple instances. */
// Instances do not have to be identical. enum {// Application Collection 
  // 0x00 Reserved   kHIDUsage_Ord_Instance1 = 0x01,// Application Collection 
// Application Collection 
// Telephony Page (0x0B) /* This usage page defines // Application Collection 
 */// Application Collection 
/* Indicators on a phone are handled by wrapping the// Application Collection 
 * Indicator and LED: Usage Selected Indicator */// Application Collection 
/* usages. For example, a message-indicator LED woul// Application Collection 
 * Telephony: Message usage declared as a Feature */// Application Collection 
// or Output in a LED: Usage In Use Indicator collec// Application Collection 
 */// Application Collection 
enum {// Application Collection 
  kHIDUsage_Tfon_Phone = 0x01,              // Appli// 0x0D - 0x1F Reserved 
};// Application Collection 
// Application Collection 
// Consumer Page (0x0C) /* All controls on the Consu// Physical Collection 
 * affect a specific device, not the system as a who// Physical Collection 
enum {// Application Collection 
  kHIDUsage_Csmr_ConsumerControl = 0x01,          //// Physical Collection 
      0x0168,                                       // 0x26 - 0xAF Reserved 
};// Dynamic Value 
// Dynamic Value 
// Digitizer Page (0x0D) /* This section provides de// Dynamic Value 
 * Digitizer Devices. */// On/Off Control 
enum {// One-Shot Control 
  kHIDUsage_Dig_Digitizer = 0x01,                  /// Dynamic Value 
};// Dynamic Value 
// On/Off Control 
// AlphanumericDisplay Page (0x14) /* The Alphanumer// Dynamic Value 
 * displays that are used on consumer devices. */// Dynamic Value 
enum {// Dynamic Value 
  kHIDUsage_AD_AlphanumericDisplay = 0x01,        //// Dynamic Value 
};// On/Off Control 
// One-Shot Control 
#if PRAGMA_STRUCT_ALIGN// On/Off Control 
#pragma options align = reset// Dynamic Value 
#elif PRAGMA_STRUCT_PACKPUSH// Momentary Control 
#pragma pack(pop)// On/Off Control 
#elif PRAGMA_STRUCT_PACK// Selector 
#pragma pack()// Dynamic Value 
#endif// Dynamic Value 
// Dynamic Value 
#ifdef PRAGMA_IMPORT_OFF// Dynamic Value 
#pragma import off// Dynamic Value 
#elif PRAGMA_IMPORT// Dynamic Value 
#pragma import reset// Dynamic Value 
#endif// Dynamic Value 
// Dynamic Value 
#ifdef __cplusplus// Dynamic Value 
}// Dynamic Value 
#endif// Dynamic Value 
// Dynamic Value 
#endif // __HID__ // Dynamic Value 
// 0xD1 - 0xFFFF Reserved 
// VR Page (0x03) 
// Application Collection 
// Application Collection 
// Physical Collection 
// Application Collection 
// Physical Collection 
// Application Collection 
// Application Collection 
// Application Collection 
// Application Collection 
// Application Collection 
// 0x0B - 0x1F Reserved 
// On/Off Control 
// On/Off Control 
// 0x22 - 0xFFFF Reserved 
// Sport Page (0x04) 
// Application Collection 
// Application Collection 
// Application Collection 
// Application Collection 
// 0x05 - 0x2F Reserved 
// Dynamic Value 
// Dynamic Value 
// Dynamic Value 
// Dynamic Value 
// Dynamic Value 
// Dynamic Value 
// Dynamic Value 
// Dynamic Value 
// Named Array 
// Dynamic Value 
// 0x3A - 0x4F Reserved 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// 0x64 - 0xFFFF Reserved 
// Game Page (0x05) 
// Application Collection 
// Application Collection 
// Application Collection 
// 0x04 - 0x1F Reserved 
// Physical Collection 
// Dynamic Value 
// Dynamic Value 
// Dynamic Value 
// Dynamic Value 
// Dynamic Value 
// Dynamic Value 
// Dynamic Value 
// Dynamic Value 
// Dynamic Value 
// Momentary Control 
// Momentary Control 
// Momentary Control 
// One-Shot Control 
// One-Shot Control 
// One-Shot Control 
// On/Off Control 
// On/Off Control 
// Selector 
// Selector 
// Selector 
// Selector 
// On/Off Control 
// Logical Collection 
// Logical Collection 
// 0x3A - 0xFFFF Reserved 
// KeyboardOrKeypad Page (0x07) 
// indicated in the �Boot� column below. 
// to Keyboard Right GUI (0x231) which are Dynamic Flags (DV). 
// Note: A general note on Usages and languages: 
// ErrorRollOver 
// POSTFail 
// ErrorUndefined 
// a or A 
// b or B 
// c or C 
// d or D 
// e or E 
// f or F 
// g or G 
// h or H 
// i or I 
// j or J 
// k or K 
// l or L 
// m or M 
// n or N 
// o or O 
// p or P 
// q or Q 
// r or R 
// s or S 
// t or T 
// u or U 
// v or V 
// w or W 
// x or X 
// y or Y 
// z or Z 
// 1 or ! 
// 2 or @ 
// 3 or # 
// 4 or $ 
// 5 or % 
// 6 or ^ 
// 7 or & 
// 8 or * 
// 9 or ( 
// 0 or ) 
// Return (Enter) 
// Escape 
// Delete (Backspace) 
// Tab 
// Spacebar 
// - or _ 
// = or + 
// [ or { 
// ] or } 
// \ or | 
// Non-US # or _ 
// ; or : 
// ' or " 
// Grave Accent and Tilde 
// , or < 
// . or > 
// / or ? 
// Caps Lock 
// F1 
// F2 
// F3 
// F4 
// F5 
// F6 
// F7 
// F8 
// F9 
// F10 
// F11 
// F12 
// Print Screen 
// Scroll Lock 
// Pause 
// Insert 
// Home 
// Page Up 
// Delete Forward 
// End 
// Page Down 
// Right Arrow 
// Left Arrow 
// Down Arrow 
// Up Arrow 
// Keypad NumLock or Clear 
// Keypad / 
// Keypad * 
// Keypad - 
// Keypad + 
// Keypad Enter 
// Keypad 1 or End 
// Keypad 2 or Down Arrow 
// Keypad 3 or Page Down 
// Keypad 4 or Left Arrow 
// Keypad 5 
// Keypad 6 or Right Arrow 
// Keypad 7 or Home 
// Keypad 8 or Up Arrow 
// Keypad 9 or Page Up 
// Keypad 0 or Insert 
// Keypad . or Delete 
// Non-US \ or | 
// Application 
// Power 
// Keypad = 
// F13 
// F14 
// F15 
// F16 
// F17 
// F18 
// F19 
// F20 
// F21 
// F22 
// F23 
// F24 
// Execute 
// Help 
// Menu 
// Select 
// Stop 
// Again 
// Undo 
// Cut 
// Copy 
// Paste 
// Find 
// Mute 
// Volume Up 
// Volume Down 
// Locking Caps Lock 
// Locking Num Lock 
// Locking Scroll Lock 
// Keypad Comma 
// Keypad Equal Sign for AS/400 
// International1 
// International2 
// International3 
// International4 
// International5 
// International6 
// International7 
// International8 
// International9 
// LANG1 
// LANG2 
// LANG3 
// LANG4 
// LANG5 
// LANG6 
// LANG7 
// LANG8 
// LANG9 
// AlternateErase 
// SysReq/Attention 
// Cancel 
// Clear 
// Prior 
// Return 
// Separator 
// Out 
// Oper 
// Clear/Again 
// CrSel/Props 
// ExSel 
// 0xA5-0xDF Reserved 
// Left Control 
// Left Shift 
// Left Alt 
// Left GUI 
// Right Control 
// Right Shift 
// Right Alt 
// Right GUI 
// 0xE8-0xFFFF Reserved 
// LEDs Page (0x08) 
// On/Off Control 
// On/Off Control 
// On/Off Control 
// On/Off Control 
// On/Off Control 
// On/Off Control 
// On/Off Control 
// On/Off Control 
// On/Off Control 
// On/Off Control 
// On/Off Control 
// On/Off Control 
// On/Off Control 
// On/Off Control 
// On/Off Control 
// On/Off Control 
// On/Off Control 
// On/Off Control 
// On/Off Control 
// On/Off Control 
// On/Off Control 
// On/Off Control 
// On/Off Control 
// On/Off Control 
// On/Off Control 
// On/Off Control 
// On/Off Control 
// On/Off Control 
// On/Off Control 
// On/Off Control 
// On/Off Control 
// On/Off Control 
// On/Off Control 
// On/Off Control 
// On/Off Control 
// On/Off Control 
// On/Off Control 
// On/Off Control 
// On/Off Control 
// On/Off Control 
// On/Off Control 
// On/Off Control 
// On/Off Control 
// On/Off Control 
// On/Off Control 
// On/Off Control 
// On/Off Control 
// On/Off Control 
// On/Off Control 
// On/Off Control 
// On/Off Control 
// On/Off Control 
// On/Off Control 
// On/Off Control 
// On/Off Control 
// On/Off Control 
// On/Off Control 
// Selector 
// Usage Switch 
// Usage Modifier 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// Dynamic Value 
// Dynamic Value 
// Dynamic Value 
// Dynamic Value 
// Dynamic Value 
// Usage Modifier 
// Selector 
// Selector 
// Selector 
// On/Off Control 
// On/Off Control 
// On/Off Control 
// 0x4E - 0xFFFF Reserved 
// Button Page (0x09) 
//   of two- and one-button devices. 
// (primary/trigger) 
// (secondary) 
// (tertiary) 
// 4th button 
// ... 
// Ordinal Page (0x0A) 
// Instances do not have to be identical. 
// 0x00 Reserved 
// Usage Modifier 
// Usage Modifier 
// Usage Modifier 
// Usage Modifier 
// Usage Modifier 
// Telephony Page (0x0B) 
// or Output in a LED: Usage In Use Indicator collection. 
// Application Collection 
// Application Collection 
// Logical Collection 
// Logical Collection 
// Logical Collection 
// Named Array 
// Named Array 
// 0x08 - 0x1F Reserved 
// On/Off Control 
// Momentary Control 
// One-Shot Control 
// On/Off Control 
// One-Shot Control 
// One-Shot Control 
// One-Shot Control 
// On/Off Control 
// On/Off Control 
// Momentary Control 
// One-Shot Control 
// On/Off Control 
// On/Off Control 
// On/Off Control 
// Selector 
// On/Off Control 
// Momentary Control 
// 0x31 - 0x4F Reserved 
// One-Shot Control 
// One-Shot Control 
// One-Shot Control 
// On/Off Control 
// 0x54 - 0x6F Reserved 
// On/Off Control 
// On/Off Control 
// On/Off Control 
// One-Shot Control 
// On/Off Control 
// 0x75 - 0x8F Reserved 
// Momentary Control 
// Momentary Control 
// Momentary Control 
// Momentary Control 
// Momentary Control 
// Momentary Control 
// Momentary Control 
// Momentary Control 
// Momentary Control 
// Momentary Control 
// Momentary Control 
// Momentary Control 
// On/Off Control 
// Momentary Control 
// 0x9E - 0xAF Reserved 
// Selector/One-Shot Control 
// Selector/One-Shot Control 
// Selector/One-Shot Control 
// Selector/One-Shot Control 
// Selector/One-Shot Control 
// Selector/One-Shot Control 
// Selector/One-Shot Control 
// Selector/One-Shot Control 
// Selector/One-Shot Control 
// Selector/One-Shot Control 
// Selector/One-Shot Control 
// Selector/One-Shot Control 
// Selector/One-Shot Control 
// Selector/One-Shot Control 
// Selector/One-Shot Control 
// Selector/One-Shot Control 
// 0xC0 - 0xFFFF Reserved 
// Consumer Page (0x0C) 
// Application Collection 
// Named Array 
// Named Array 
// 0x03 - 0x1F Reserved 
// One-Shot Control 
// One-Shot Control 
// One-Shot Control 
// 0x23 - 0x3F Reserved 
// On/Off Control 
// One-Shot Control 
// One-Shot Control 
// One-Shot Control 
// Re-Trigger Control 
// On/Off Control 
// Named Array 
// 0x37 - 0x3F Reserved 
// On/Off Control 
// One-Shot Control 
// One-Shot Control 
// One-Shot Control 
// One-Shot Control 
// One-Shot Control 
// One-Shot Control 
// One-Shot Control 
// One-Shot Control 
// 0x49 - 0x5F Reserved 
// On/Off Control 
// On/Off Control 
// Selector 
// On/Off Control 
// One-Shot Control 
// One-Shot Control 
// One-Shot Control 
// 0x67 - 0x7F Reserved 
// Named Array 
// Selector 
// One-Shot Control 
// One-Shot Control 
// One-Shot Control 
// One-Shot Control 
// Linear Control 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// One-Shot Control 
// On/Off Control 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// One-Shot Control 
// One-Shot Control 
// Selector 
// 0x9F Reserved 
// One-Shot Control 
// One-Shot Control 
// One-Shot Control 
// One-Shot Control 
// One-Shot Control 
// 0xA5 - 0xAF Reserved 
// On/Off Control 
// On/Off Control 
// On/Off Control 
// On/Off Control 
// On/Off Control 
// One-Shot Control 
// One-Shot Control 
// One-Shot Control 
// One-Shot Control 
// On/Off Control 
// Named Array 
// Momentary Control 
// One-Shot Control 
// Linear Control 
// One-Shot Control 
// Linear Control 
// Re-Trigger Control 
// Re-Trigger Control 
// One-Shot Control 
// One-Shot Control 
// On/Off Control 
// One-Shot Control 
// One-Shot Control 
// One-Shot Control 
// One-Shot Control 
// One-Shot Control 
// Re-Trigger Control 
// Re-Trigger Control 
// One-Shot Control 
// One-Shot Control 
// One-Shot Control 
// 0xCF - 0xDF Reserved 
// Linear Control 
// Linear Control 
// On/Off Control 
// Linear Control 
// Linear Control 
// On/Off Control 
// One-Shot Control 
// On/Off Control 
// On/Off Control 
// Re-Trigger Control 
// Re-Trigger Control 
// 0xEB - 0xEF Reserved 
// Selector 
// Named Array 
// Selector 
// Selector 
// Selector 
// One-Shot Control 
// 0xF6 - 0xFF Reserved 
// On/Off Control 
// Linear Control 
// On/Off Control 
// Linear Control 
// On/Off Control 
// Linear Control 
// On/Off Control 
// One-Shot Control 
// One-Shot Control 
// 0x109 - 0x14F Reserved 
// Re-Trigger Control 
// Re-Trigger Control 
// Re-Trigger Control 
// Re-Trigger Control 
// Re-Trigger Control 
// Re-Trigger Control 
// 0x156 - 0x15F Reserved 
// Logical Collection 
// Logical Collection 
// Logical Collection 
// Logical Collection 
// Logical Collection 
// Logical Collection 
// Logical Collection 
// Logical Collection 
// Logical Collection 
// Logical Collection 
// Logical Collection 
// 0x16B - 0x16F Reserved 
// Linear Control 
// One-Shot Control 
// One-Shot Control 
// One-Shot Control 
// One-Shot Control 
// 0x175 - 0x17F Reserved 
// Named Array 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// 0x1A6 - 0x1FF Reserved 
// Named Array 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// Selector 
// 0x23D - 0xFFFF Reserved 
// Digitizer Page (0x0D) 
// Application Collection 
// Application Collection 
// Application Collection 
// Application Collection 
// Application Collection 
// Application Collection 
// Application Collection 
// Application Collection 
// Application Collection 
// Application Collection 
// Application Collection 
// Application Collection 
// Application Collection 
// 0x0E - 0x1F Reserved 
// Logical Collection 
// Logical Collection 
// Logical Collection 
// 0x23 - 0x2F Reserved 
// Dynamic Value 
// Dynamic Value 
// Momentary Control 
// Momentary Control 
// One-Shot Control 
// One-Shot Control 
// Dynamic Value 
// Momentary Control 
// Dynamic Value 
// Logical Collection 
// Logical Collection 
// Dynamic Value 
// Momentary Control 
// Dynamic Value 
// Dynamic Value 
// Dynamic Value 
// Dynamic Value 
// Dynamic Value 
// Momentary Control 
// Momentary Control 
// Momentary Control 
// Momentary Control 
// Momentary Control 
// 0x47 - 0xFFFF Reserved 
// AlphanumericDisplay Page (0x14) 
// Application Collection 
// 0x02 - 0x1F Reserved 
// Logical Collection 
// Static Flag 
// Static Flag 
// Static Flag 
// Logical Collection 
// Dynamic Flag 
// Dynamic Flag 
// Static Value 
// Dynamic Flag 
// Static Flag 
// Static Flag 
// Logical Collection 
// Dynamic Value 
// Logical Collection 
// Selector 
// Selector 
// Selector 
// Selector 
// Logical Collection 
// Dynamic Value 
// Dynamic Value 
// Static Value 
// Static Value 
// Static Flag 
// Dynamic Flag 
// Dynamic Flag 
// Dynamic Flag 
// Logical Collection 
// Buffered Byte 
// Static Value 
// Static Value 
// Static Value 
// Static Value 
// Static Flag 
// 0x42 - 0xFFFF Reserved 
// __HID__ 
