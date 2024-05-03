/**
     \file       PCI.h

    \brief   PCI Bus Interfaces.

    \introduced_in  PowerSurge 1.0.2
    \avaliable_from Universal Interfaces 3.4.1

    \copyright © 1993-2001 by Apple Computer, Inc., all rights reserved.

    \ingroup Hardware

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __PCI__
#define __PCI__

#ifndef __MACTYPES__
#include <MacTypes.h>
#endif

#ifndef __NAMEREGISTRY__
#include <NameRegistry.h>
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

  /** Definitions for the PCI Config Registers*/
  enum
  {
    kPCIConfigVendorID = 0x00,
    kPCIConfigDeviceID = 0x02,
    kPCIConfigCommand = 0x04,
    kPCIConfigStatus = 0x06,
    kPCIConfigRevisionID = 0x08,
    kPCIConfigClassCode = 0x09,
    kPCIConfigCacheLineSize = 0x0C,
    kPCIConfigLatencyTimer = 0x0D,
    kPCIConfigHeaderType = 0x0E,
    kPCIConfigBIST = 0x0F,
    kPCIConfigBaseAddress0 = 0x10,
    kPCIConfigBaseAddress1 = 0x14,
    kPCIConfigBaseAddress2 = 0x18,
    kPCIConfigBaseAddress3 = 0x1C,
    kPCIConfigBaseAddress4 = 0x20,
    kPCIConfigBaseAddress5 = 0x24,
    kPCIConfigCardBusCISPtr = 0x28,
    kPCIConfigSubSystemVendorID = 0x2C,
    kPCIConfigSubSystemID = 0x2E,
    kPCIConfigExpansionROMBase = 0x30,
    kPCIConfigCapabilitiesPtr = 0x34,
    kPCIConfigInterruptLine = 0x3C,
    kPCIConfigInterruptPin = 0x3D,
    kPCIConfigMinimumGrant = 0x3E,
    kPCIConfigMaximumLatency = 0x3F
  };

  /** Definitions for the Capabilities PCI Config Register*/
  enum
  {
    kPCICapabilityIDOffset = 0x00,
    kPCINextCapabilityOffset = 0x01,
    kPCIPowerManagementCapability = 0x01,
    kPCIAGPCapability = 0x02
  };

  /** Types and structures for accessing the PCI Assigned-Address property.*/

#define kPCIAssignedAddressProperty "assigned-addresses"
  enum
  {
    kPCIRelocatableSpace = 0x80,
    kPCIPrefetchableSpace = 0x40,
    kPCIAliasedSpace = 0x20,
    kPCIAddressTypeCodeMask = 0x03,
    kPCIConfigSpace = 0,
    kPCIIOSpace = 1,
    kPCI32BitMemorySpace = 2,
    kPCI64BitMemorySpace = 3
  };

  typedef UInt8 PCIAddressSpaceFlags;
  enum
  {
    kPCIDeviceNumberMask = 0x1F,
    kPCIFunctionNumberMask = 0x07
  };

  typedef UInt8 PCIDeviceFunction;
  typedef UInt8 PCIBusNumber;
  typedef UInt8 PCIRegisterNumber;
  struct PCIAssignedAddress
  {
    PCIAddressSpaceFlags addressSpaceFlags;
    PCIBusNumber busNumber;
    PCIDeviceFunction deviceFunctionNumber;
    PCIRegisterNumber registerNumber;
    UnsignedWide address;
    UnsignedWide size;
  };
  typedef struct PCIAssignedAddress PCIAssignedAddress;
  typedef PCIAssignedAddress *PCIAssignedAddressPtr;
#define GetPCIIsRelocatable(AssignedAddressPtr) \
  ((AssignedAddressPtr)->addressSpaceFlags & kPCIRelocatableSpace)
#define GetPCIIsPrefetchable(AssignedAddressPtr) \
  ((AssignedAddressPtr)->addressSpaceFlags & kPCIPrefetchableSpace)
#define GetPCIIsAliased(AssignedAddressPtr) \
  ((AssignedAddressPtr)->addressSpaceFlags & kPCIAliasedSpace)
#define GetPCIAddressSpaceType(AssignedAddressPtr) \
  ((AssignedAddressPtr)->addressSpaceFlags & kPCIAddressTypeCodeMask)
#define GetPCIBusNumber(AssignedAddressPtr) ((AssignedAddressPtr)->busNumber)
#define GetPCIDeviceNumber(AssignedAddressPtr) \
  (((AssignedAddressPtr)->deviceFunctionNumber >> 3) & kPCIDeviceNumberMask)
#define GetPCIFunctionNumber(AssignedAddressPtr) \
  ((AssignedAddressPtr)->deviceFunctionNumber & kPCIFunctionNumberMask)
#define GetPCIRegisterNumber(AssignedAddressPtr) \
  ((AssignedAddressPtr)->registerNumber)

#if CALL_NOT_IN_CARBON
/**
 *  EndianSwap16Bit()
 *

 *    \non_carbon_cfm   in PCILib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 EndianSwap16Bit(__D0)
#endif
  UInt16
  EndianSwap16Bit(UInt16 data16);

/**
 *  EndianSwap32Bit()
 *

 *    \non_carbon_cfm   in PCILib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 EndianSwap32Bit(__D0)
#endif
  UInt32
  EndianSwap32Bit(UInt32 data32);

#endif /** CALL_NOT_IN_CARBON */

#if CALL_NOT_IN_CARBON
  /**
   *  ExpMgrConfigReadByte()
   *

   *    \non_carbon_cfm   in PCILib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  ExpMgrConfigReadByte(RegEntryIDPtr node, LogicalAddress configAddr,
                       UInt8 *valuePtr);

  /**
   *  ExpMgrConfigReadWord()
   *

   *    \non_carbon_cfm   in PCILib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  ExpMgrConfigReadWord(RegEntryIDPtr node, LogicalAddress configAddr,
                       UInt16 *valuePtr);

  /**
   *  ExpMgrConfigReadLong()
   *

   *    \non_carbon_cfm   in PCILib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  ExpMgrConfigReadLong(RegEntryIDPtr node, LogicalAddress configAddr,
                       UInt32 *valuePtr);

  /**
   *  ExpMgrConfigWriteByte()
   *

   *    \non_carbon_cfm   in PCILib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  ExpMgrConfigWriteByte(RegEntryIDPtr node, LogicalAddress configAddr,
                        UInt8 value);

  /**
   *  ExpMgrConfigWriteWord()
   *

   *    \non_carbon_cfm   in PCILib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  ExpMgrConfigWriteWord(RegEntryIDPtr node, LogicalAddress configAddr,
                        UInt16 value);

  /**
   *  ExpMgrConfigWriteLong()
   *

   *    \non_carbon_cfm   in PCILib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  ExpMgrConfigWriteLong(RegEntryIDPtr node, LogicalAddress configAddr,
                        UInt32 value);

  /**
   *  ExpMgrIOReadByte()
   *

   *    \non_carbon_cfm   in PCILib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  ExpMgrIOReadByte(RegEntryIDPtr node, LogicalAddress ioAddr, UInt8 *valuePtr);

  /**
   *  ExpMgrIOReadWord()
   *

   *    \non_carbon_cfm   in PCILib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  ExpMgrIOReadWord(RegEntryIDPtr node, LogicalAddress ioAddr, UInt16 *valuePtr);

  /**
   *  ExpMgrIOReadLong()
   *

   *    \non_carbon_cfm   in PCILib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  ExpMgrIOReadLong(RegEntryIDPtr node, LogicalAddress ioAddr, UInt32 *valuePtr);

  /**
   *  ExpMgrIOWriteByte()
   *

   *    \non_carbon_cfm   in PCILib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  ExpMgrIOWriteByte(RegEntryIDPtr node, LogicalAddress ioAddr, UInt8 value);

  /**
   *  ExpMgrIOWriteWord()
   *

   *    \non_carbon_cfm   in PCILib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  ExpMgrIOWriteWord(RegEntryIDPtr node, LogicalAddress ioAddr, UInt16 value);

  /**
   *  ExpMgrIOWriteLong()
   *

   *    \non_carbon_cfm   in PCILib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  ExpMgrIOWriteLong(RegEntryIDPtr node, LogicalAddress ioAddr, UInt32 value);

  /**
   *  ExpMgrInterruptAcknowledgeReadByte()
   *

   *    \non_carbon_cfm   in PCILib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  ExpMgrInterruptAcknowledgeReadByte(RegEntryIDPtr entry, UInt8 *valuePtr);

  /**
   *  ExpMgrInterruptAcknowledgeReadWord()
   *

   *    \non_carbon_cfm   in PCILib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  ExpMgrInterruptAcknowledgeReadWord(RegEntryIDPtr entry, UInt16 *valuePtr);

  /**
   *  ExpMgrInterruptAcknowledgeReadLong()
   *

   *    \non_carbon_cfm   in PCILib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  ExpMgrInterruptAcknowledgeReadLong(RegEntryIDPtr entry, UInt32 *valuePtr);

  /**
   *  ExpMgrSpecialCycleWriteLong()
   *

   *    \non_carbon_cfm   in PCILib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  ExpMgrSpecialCycleWriteLong(RegEntryIDPtr entry, UInt32 value);

  /**
   *  ExpMgrSpecialCycleBroadcastLong()
   *

   *    \non_carbon_cfm   in PCILib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  ExpMgrSpecialCycleBroadcastLong(UInt32 value);

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

#endif /** __PCI__ */
