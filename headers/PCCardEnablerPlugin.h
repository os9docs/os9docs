/**
     \file       PCCardEnablerPlugin.h

    \brief   Interfacer for PCCard Manager 3.0

    \introduced_in  Mac OS 8.5
    \avaliable_from Universal Interfaces 3.4.1

    \copyright � 1997-2001 by Apple Computer, Inc. and SystemSoft Corporation.
   All rights reserved.

    \ingroup Hardware

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __PCCARDENABLERPLUGIN__
#define __PCCARDENABLERPLUGIN__

#ifndef __MACTYPES__
#include <MacTypes.h>
#endif

#ifndef __NAMEREGISTRY__
#include <NameRegistry.h>
#endif

#ifndef __INTERRUPTS__
#include <Interrupts.h>
#endif

#ifndef __PCCARD__
#include <PCCard.h>
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

#ifndef __CARDSERVICES__
  /**
      NOTE: These prototypes conflict with CardServices.�
            You cannot use both PCCardEnablerPlugin.h and CardServices.h

  */

  // \copyright � 1996 SystemSoft Corporation, all rights reserved. /*------------------------------------------------------------------------------------
  Card Services calls exported by the Family-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --* /
      //  Card Services for Card Enablers
      //  Card Services for Card Enablers
      /**
       *  CSGetCardServicesInfo()
       *
       *  Availability:
       *    \non_carbon_cfm   in PCCard 3.0 and later
       *    \carbon_lib        not available
       *    \mac_os_x         not available
       */
      OSStatus
      CSGetCardServicesInfo(UInt32 *socketCount, UInt32 *complianceLevel,
                            UInt32 *version);

  // Function prototypes for tuples calls
  /**
  // Function prototypes for tuples calls
   *
   *  Availability:
   *    \non_carbon_cfm   in PCCard 3.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  CSGetFirstTuple(PCCardSocket socket, UInt32 device,
                  PCCardTupleIterator tupleIterator, Byte desiredTuple,
                  void *tupleData, ByteCount *tupleBufferSize, Byte *foundTuple);

  /**
   *  CSGetNextTuple()
   *
   *  Availability:
   *    \non_carbon_cfm   in PCCard 3.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  CSGetNextTuple(PCCardTupleIterator tupleIterator, Byte desiredTuple,
                 void *tupleData, ByteCount *tupleBufferSize, Byte *foundTuple);

  // Function prototypes for window calls
  /**
   *  CSRequestWindow()
  // Function prototypes for window calls
   *  Availability:
   *    \non_carbon_cfm   in PCCard 3.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  CSRequestWindow(PCCardSocket vSocket, UInt32 device,
                  PCCardWindowAttributes windowAttributes,
                  PCCardAccessSpeed windowSpeed, LogicalAddress *windowBase,
                  PCCardWindowSize *windowSize, PCCardWindowOffset *windowOffset,
                  PCCardWindowID *requestedWindow);

  /**
   *  CSReleaseWindow()
   *
   *  Availability:
   *    \non_carbon_cfm   in PCCard 3.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  CSReleaseWindow(PCCardWindowID windowToRelease);

  /**
   *  CSModifyWindow()
   *
   *  Availability:
   *    \non_carbon_cfm   in PCCard 3.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  CSModifyWindow(PCCardWindowID windowToModify, PCCardWindowType windowAttributes,
                 PCCardAccessSpeed memorySpeed, PCCardWindowOffset *windowOffset);

  /**
   *  CSGetWindowBaseAddress()
   *
   *  Availability:
   *    \non_carbon_cfm   in PCCard 3.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  CSGetWindowBaseAddress(PCCardWindowID window, LogicalAddress *baseAddress);

  /**
   *  CSInquireWindow()
   *
   *  Availability:
   *    \non_carbon_cfm   in PCCard 3.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  CSInquireWindow(PCCardSocket vSocket, UInt32 device, PCCardWindowID windowID,
                  PCCardWindowAttributes *windowAttributes,
                  PCCardAccessSpeed *windowParam, UInt32 *windowBase,
                  PCCardWindowSize *windowSize, PCCardWindowOffset *windowOffset);

  // Function prototypes for CIS calls
  /**
   *  CSValidateCIS()
   *
  // Function prototypes for CIS calls
   *    \non_carbon_cfm   in PCCard 3.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  CSValidateCIS(PCCardSocket vSocket, UInt32 device, UInt32 *cisChainCount);

  /**
   *  CSGetDeviceCount()
   *
   *  Availability:
   *    \non_carbon_cfm   in PCCard 3.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  CSGetDeviceCount(PCCardSocket vSocket, UInt32 *deviceCount);

  // Function prototypes for Status calls
  /**
   *  CSGetStatus()
   *
   *  Availability:
  // Function prototypes for Status calls
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  CSGetStatus(PCCardSocket vSocket, UInt32 *currentState, UInt32 *changedState,
              PCCardVoltage *Vcc, PCCardVoltage *Vpp);

  // Function prototypes for configuration calls
  /**
   *  CSRequestConfiguration()
   *
   *  Availability:
   *    \non_carbon_cfm   in PCCard 3.0 and later
  // Function prototypes for configuration calls
   *    \mac_os_x         not available
   */
  OSStatus
  CSRequestConfiguration(PCCardSocket vSocket, UInt32 device,
                         PCCardConfigOptions configOptions,
                         PCCardInterfaceType socketInterface,
                         PCCardCustomInterfaceID customInterface,
                         PCCardVoltage vcc, PCCardVoltage vpp, PCCardIRQ IRQ,
                         PCCardDMA DMA, UInt32 configRegBaseAddress,
                         PCCardConfigPresentMask configRegPresentMask,
                         PCCardFunctionConfigReg *configReg);

  /**
   *  CSModifyConfiguration()
   *
   *  Availability:
   *    \non_carbon_cfm   in PCCard 3.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  CSModifyConfiguration(PCCardSocket vSocket, UInt32 device,
                        PCCardConfigOptions modifyAttributes, PCCardIRQ IRQ,
                        PCCardDMA DMA, PCCardVoltage Vpp);

  /**
   *  CSReleaseConfiguration()
   *
   *  Availability:
   *    \non_carbon_cfm   in PCCard 3.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  CSReleaseConfiguration(PCCardSocket vSocket, UInt32 device);

  /**
   *  CSSetRingIndicate()
   *
   *  Availability:
   *    \non_carbon_cfm   in PCCard 3.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  CSSetRingIndicate(PCCardSocket vSocket, Boolean setRingIndicate);

  /**
   *  CSResetFunction()
   *
   *  Availability:
   *    \non_carbon_cfm   in PCCard 3.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  CSResetFunction(PCCardSocket vSocket, UInt32 device);

  /**
   *  CSReadConfigurationRegister()
   *
   *  Availability:
   *    \non_carbon_cfm   in PCCard 3.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  CSReadConfigurationRegister(PCCardSocket vSocket, UInt32 device,
                              PCCardConfigPresentMask whichRegister,
                              UInt32 configRegBaseAddress, UInt8 *registerValue);

  /**
   *  CSWriteConfigurationRegister()
   *
   *  Availability:
   *    \non_carbon_cfm   in PCCard 3.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  CSWriteConfigurationRegister(PCCardSocket vSocket, UInt32 device,
                               PCCardConfigPresentMask whichRegister,
                               UInt32 configRegBaseAddress, UInt8 registerValue);

  // Function prototypes for Client Support calls/**
  *CSRegisterClient() *
          *Availability : *    \non_carbon_cfm in PCCard 3.0 and
      later
              *    \carbon_lib not available
          *    \mac_os_x not available
          // Function prototypes for Client Support calls
          OSStatus
          CSRegisterClient(PCCardSocket vSocket, PCCardEventMask eventMask,
                           PCCardEventHandler clientCallBack, void *clientParam,
                           PCCardClientID *newClientID);

  /**
   *  CSDeRegisterClient()
   *
   *  Availability:
   *    \non_carbon_cfm   in PCCard 3.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  CSDeRegisterClient(PCCardClientID theClientID);

  /**
   *  CSSetEventMask()
   *
   *  Availability:
   *    \non_carbon_cfm   in PCCard 3.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  CSSetEventMask(PCCardClientID theClientID, PCCardEventMask newEventMask);

  /**
   *  CSGetEventMask()
   *
   *  Availability:
   *    \non_carbon_cfm   in PCCard 3.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  CSGetEventMask(PCCardClientID theClientID, PCCardEventMask *newEventMask);

  /**
   *  CSRegisterTimer()
   *
   *  Availability:
   *    \non_carbon_cfm   in PCCard 3.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  CSRegisterTimer(PCCardClientID registeredClientID, PCCardTimerID *lpNewTimerID,
                  long delay);

  /**
   *  CSDeRegisterTimer()
   *
   *  Availability:
   *    \non_carbon_cfm   in PCCard 3.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  CSDeRegisterTimer(PCCardTimerID timerID);

  // Function prototypes for CardBus Config Space access/**
  *CSReadCardBusConfigSpace() *
          *Availability : *    \non_carbon_cfm in PCCard 3.0 and
      later
              *    \carbon_lib not available
          *    \mac_os_x not available
          * /
          // Function prototypes for CardBus Config Space access
          CSReadCardBusConfigSpace(PCCardSocket vSocket, UInt32 device,
                                   UInt32 configOffset, Byte *data, UInt32 dataSize);

  /**
   *  CSWriteCardBusConfigSpace()
   *
   *  Availability:
   *    \non_carbon_cfm   in PCCard 3.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  CSWriteCardBusConfigSpace(PCCardSocket vSocket, UInt32 device,
                            UInt32 configOffset, Byte *data, UInt32 dataSize);

/*------------------------------------------------------------------------------------
    Card Enabler Types
------------------------------------------------------------------------------------*/
#endif // CALL_NOT_IN_CARBON
enum {
  kUnknownDeviceType = FOUR_CHAR_CODE('unkn'), // class-code = 0x00   kSCSIDeviceType =
      FOUR_CHAR_CODE('scsi'), // class-code = 0x01, sub-class = 0x00   kBlockDeviceType =
      FOUR_CHAR_CODE('blok'),  /** = */
0x01, sub-class  =  0xXX   kNetworkDeviceType = FOUR_CHAR_CODE('netw')     /** = */
0x02   kDisplayDeviceType  =  FOUR_CHAR_CODE('dspl')     /** = */
0x03   kMultimediaDeviceType  =  FOUR_CHAR_CODE('mmdv')  /** = */
0x04   kMemoryDeviceType  =  FOUR_CHAR_CODE('mem ')      /** = */
0x05   kBridgeDeviceType  =  FOUR_CHAR_CODE('brdg')      /** = */
0x06   kCommDeviceType  =  FOUR_CHAR_CODE('comm')        /** = */
0x07   kPeripheralDeviceType  =  FOUR_CHAR_CODE('sysp')  /** = */
0x08   kInputDeviceType  =  FOUR_CHAR_CODE('inpt')       /** = */
0x09   kDockingDeviceType  =  FOUR_CHAR_CODE('dock')     /** = */
0x0A   kProcessorDeviceType  =  FOUR_CHAR_CODE('proc')  // class-code = 0x0B   kFirewireBusDeviceType =
      FOUR_CHAR_CODE('firw'), // class-code = 0x0C, sub-class = 0x00   kACCESSBusDeviceType =
      FOUR_CHAR_CODE('accs'), // class-code = 0x0C, sub-class = 0x01   kSSABusDeviceType =
      FOUR_CHAR_CODE('ssa '), // class-code = 0x0C, sub-class = 0x02   kUSBBusDeviceType =
      FOUR_CHAR_CODE('usb '), // class-code = 0x0C, sub-class = 0x03   kFibreBusDeviceType =
      F// CALL_NOT_IN_CARBON 

typedef OSType PCDeviceType;
enum { kAttributeType = 0, kMemoryType = 1, kIO// class-code = 0x00 

typedef UInt32 PCCardMemoryTyp// class-code = 0x01, sub-class = 0x00 
enum {
  kUnknown = FOUR_CHAR_CODE('u// class-code = 0x01, sub-class = 0xXX 
  kPCCard16 = FOUR_CHAR_CODE('pc16'),// class-code = 0x02 
  kCardBus = FOUR_CHAR_CODE('cdbs')// class-code = 0x03 
};// class-code = 0x04 
// class-code = 0x05 
typedef OSType PCCardArchitectureType;// class-code = 0x06
#define kNodeNameName "name"          // class-code = 0x07
#define k16BitPCCardName "16bitcard"  // class-code = 0x08
#define kCardbusPropertyName "cardbus"           // class-code = 0x09
#define kNodeCompatiblePropertyName "compatible" // class-code = 0x0A
#define kDevice_TypeName "device_type"           // class-code = 0x0B
#define kDriverISTPropertyName "driver-ist"
#define kFCRAccessPropertyName // class-code = 0x0C, sub-class = 0x00
#define kConfigRegPropertyName "ConfigRegValues"
#define kNodeTypePropertyName // class-code = 0x0C, sub-class = 0x01
#define kDeviceNumberPropertName "DeviceNumber"
#define kSocketNumberPropertNa // class-code = 0x0C, sub-class = 0x02 

/*----------------------------// class-code = 0x0C, sub-class = 0x03 
  Plugin Dispatch Table
------------------------------// class-code = 0x0C, sub-class = 0x04 
enum {// class-code = 0x?? 
  kServiceTypePCCardEnabler = FOUR_CHAR_CODE('ca// class-code = 0x?? 
  kPCCardEnablerPluginVersion = 0x00000001,// class-code = 0x?? 
  kPCCardEnablerPluginCurrentVersion = kPCCardEn// class-code = 0x?? 
};

//  Card Enabler Entrypointstypedef CALLBACK_API_C(OSStatus,
                       CEValidateHardwareProc)(const RegEntryID *cardRef);
typedef CALLBACK_API_C(OSStatus, CEInitializeProc)(const RegEntryID *cardRef,
                                                   Boolean replacingOld);
typedef CALLBACK_API_C(OSStatus, CECleanupProc)(const RegEntryID *cardRef,
                                                Boolean beingReplaced);
typedef CALLBACK_API_C(OSStatus,
                       CEPowerManagementProc)(const RegEntryID *lpCardEntry,
                                              PCCardPowerOptions powerLevel);
typedef CALLBACK_API_C(OSStatus, CEHandleEventProc)(const RegEntryID *cardRef,
                                                    PCCardEvent theEvent);
typedef CALLBACK_API_C(OSStatus, CEGetCardInfoProc)(const RegEntryID *cardRef,
                                                    PCCardDevType *cardType,
                                                    PCCardSubType *cardSubType,
                                                    StringPtr cardName,
                                                    StringPtr vendorName);
typedef CALLBACK_API_C(OSStatus,
                       CEAddCardPropertiesProc)(const RegEntryID *cardRef);
typedef CALLBACK_API_C(OSStatus,
                       CEGetDeviceCountProc)(const RegEntryID *cardRef,
                                             ItemCount *numberOfDevices);
typedef CALLBACK_API_C(OSStatus, CEGetDeviceNameProc)(UInt32 socketNumber,
                                                      UInt32 deviceNumber,
                                                      char *deviceName);
typedef CALLBACK_API_C(OSStatus,
                       CEGetDeviceCompatibleProc)(const RegEntryID *deviceRef,
                                                  UInt32 socketNumber,
                                                  UInt32 deviceNumber,
                                                  char *name);
typedef CALLBACK_API_C(OSStatus,
                       CEGetDeviceTypeProc)(const RegEntryID *deviceRef,
                                            UInt32 socketNumber,
//  Card Enabler Entrypoints
                                            PCDeviceType *lpDeviceType);
typedef CALLBACK_API_C(OSStatus,
                       CEGetDeviceTypeNameProc)(const RegEntryID *deviceRef,
                                                UInt32 socketNumber,
                                                UInt32 deviceNumber,
                                                char *name);
typedef CALLBACK_API_C(OSStatus,
                       CEAddDevicePropertiesProc)(const RegEntryID *deviceRef,
                                                  UInt32 device);
typedef CALLBACK_API_C(OSStatus,
                       CEConfigureDeviceProc)(const RegEntryID *deviceRef,
                                              UInt32 deviceNumber);
typedef CALLBACK_API_C(OSStatus,
                       CEFinalizeDeviceProc)(UInt32 socket, UInt32 device,
                                             const RegEntryID *deviceRef);
typedef CALLBACK_API_C(OSStatus, CEValidateCISProc)(UInt32 socket,
                                                    UInt32 device,
                                                    UInt32 *lpCISChainCount);
typedef CALLBACK_API_C(OSStatus, CEGetFirstTupleProc)(
    UInt32 socket, UInt32 device, PCCardTupleIterator lpTupleIterator,
    Byte desiredTuple, void *lptupleData, UInt32 *lpTupleBufferSize,
    Byte *lpFoundTuple);
typedef CALLBACK_API_C(OSStatus,
                       CEGetNextTupleProc)(PCCardTupleIterator lpTupleIterator,
                                           Byte desiredTuple, void *lptupleData,
                                           UInt32 *lpTupleBufferSize,
                                           Byte *lpFoundTuple);
struct PCCardEnablerPluginHeader {
  UInt32 pluginDispatchTableVersion;
  UInt32 reserved1;
  UInt32 reserved2;
  UInt32 reserved3;
};
typedef struct PCCardEnablerPluginHeader PCCardEnablerPluginHeader;
struct PCCardEnablerPluginDispatchTable {
  PCCardEnablerPluginHeader header;

  // General functions  CEValidateHardwareProc validateHardwareProc;
  CEInitializeProc initializeProc;
  CECleanupProc cleanUpProc;
  CEPowerManagementProc setPCCardPowerLevel;

  // Card functions  CEHandleEventProc handleEventProc;
  CEGetCardInfoProc getCardInfoProc;
  CEAddCardPropertiesProc addCardProperties;
  CEGetDeviceCountProc getDeviceCount;

  // Device functions  CEGetDeviceNameProc getDeviceName;
  CEGetDeviceCompatibleProc getDeviceCompatibleNames;
  CEGetDeviceTypeProc getDeviceType;
  CEGetDeviceTypeNameProc getDeviceTypeName;
  CEAddDevicePropertiesProc addDeviceProperties;
  CEConfigureDeviceProc configureDevice;
  CEFinalizeDeviceProc finalizeDevice;

  // Card Services Overrides...  CEValidateCISProc validateCIS;
  CEGetFirstTupleProc getFirstTuple;
  CEGetNextTupleProc getNextTuple;

  // InterruptHandlers...  InterruptHandler cardInterruptHandlerFunction;
  InterruptEnabler cardInterruptEnableFunction;
  InterruptDisabler cardInterruptDisableFunction;
};
typedef struct PCCardEnablerPluginDispatchTable
    PCCardEnablerPluginDispatchTable;
typedef PCCardEnablerPluginDispatchTable *PCCardEnablerPluginDispatchTablePtr;
/*------------------------------------------------------------------------------------
    PC Card Enabler Utility calls exported by the Family
------------------------------------------------------------------------------------*/
//  Generic Enabler Entrypoints#if CALL_NOT_IN_CARBON
/*// General functions
 *  CEInitializeCard()
 *
 *  Availability:
 *    \non_carbon_cfm   in PCCard 3.0 and later
 *    \carbon_lib        not available
 *// Card functions
 */
OSStatus
CEInitializeCard(const RegEntryID *cardRef, Boolean replacingOld);

/**
 *// Device functions
 *
 *  Availability:
 *    \non_carbon_cfm   in PCCard 3.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSStatus
CEFinalizeCard(const RegEntryID *cardRef, Boolean beingReplaced);
// Card Services Overrides...
/**
 *  CEPowerManagement()
 *
 *  Availability:
 *// InterruptHandlers...
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSStatus
CEPowerManagement(const RegEntryID *lpParentID, PCCardPowerOptions powerLevel);

/**
 *  CEHandleCardEvent()
 *
 *  Availability:
//  Generic Enabler Entrypoints
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSStatus
CEHandleCardEvent(const RegEntryID *cardRef, PCCardEvent lTheCardEvent);

/**
 *  CEGetCardInfo()
 *
 *  Availability:
 *    \non_carbon_cfm   in PCCard 3.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSStatus
CEGetCardInfo(const RegEntryID *cardRef, PCCardDevType *cardType,
              PCCardSubType *cardSubType, StringPtr cardName,
              StringPtr vendorName);

/**
 *  CEAddCardProperties()
 *
 *  Availability:
 *    \non_carbon_cfm   in PCCard 3.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSStatus
CEAddCardProperties(const RegEntryID *cardRef);

/**
 *  CEGetDeviceCount()
 *
 *  Availability:
 *    \non_carbon_cfm   in PCCard 3.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSStatus
CEGetDeviceCount(const RegEntryID *cardRef, ItemCount *numberOfDevices);

// device functions/**
 *  CEGetDeviceName()
 *
 *  Availability:
 *    \non_carbon_cfm   in PCCard 3.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSStatus
CEGetDeviceName(UInt32 socketNumber, UInt32 deviceNumber, char *deviceName);

/**
 *  CEGetDeviceCompatibleNames()
 *
 *  Availability:
 *    \non_carbon_cfm   in PCCard 3.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSStatus
CEGetDeviceCompatibleNames(const RegEntryID *deviceRef, UInt32 socketNumber,
                           UInt32 deviceNumber, char *name);

/**
 *  CEGetDeviceType()
 *
 *  Availability:
 *    \non_carbon_cfm   in PCCard 3.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSStatus
CEGetDeviceType(const RegEntryID *deviceRef, UInt32 socketNumber,
                UInt32 deviceNumber, PCDeviceType *lpDeviceType);

/**
 *  CEGetDeviceTypeName()
 *
 *  Availability:
// device functions
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSStatus
CEGetDeviceTypeName(const RegEntryID *deviceRef, UInt32 socketNumber,
                    UInt32 deviceNumber, char *name);

/**
 *  CEAddDeviceProperties()
 *
 *  Availability:
 *    \non_carbon_cfm   in PCCard 3.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSStatus
CEAddDeviceProperties(const RegEntryID *deviceRef, UInt32 deviceNumber);

/**
 *  CEConfigureDevice()
 *
 *  Availability:
 *    \non_carbon_cfm   in PCCard 3.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSStatus
CEConfigureDevice(const RegEntryID *deviceRef, UInt32 deviceNumber);

/**
 *  CEFinalizeDevice()
 *
 *  Availability:
 *    \non_carbon_cfm   in PCCard 3.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSStatus
CEFinalizeDevice(UInt32 socket, UInt32 device, const RegEntryID *deviceRef);

//  RegEntryID <-> socket number mapping functions/**
 *  CEGetSocketAndDeviceFromRegEntry()
 *
 *  Availability:
 *    \non_carbon_cfm   in PCCard 3.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSStatus
CEGetSocketAndDeviceFromRegEntry(const RegEntryID *lpNode, UInt32 *lpSocket,
                                 UInt32 *lpDevice);

/**
 *  CEGetPhysicalSocketNumber()
 *
 *  Availability:
 *    \non_carbon_cfm   in PCCard 3.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSStatus
CEGetPhysicalSocketNumber(const RegEntryID *socketRef,
                          const RegEntryID *lpDeviceEntry,
                          UInt32 *lpPhysicalSocketNumber);

//  Hardware Validation Utilities/**
 *  CECompareCISTPL_VERS_1()
 *
 *  Availability:
 *    \non_carbon_cfm   in PCCard 3.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSStatus
CECompareCISTPL_VERS_1(const RegEntryID *cardRef, Byte majorVersion,
                       Byte minorVersion, const char *manufacturer,
                       const char *productName, const char *info1,
                       const char *info2, Boolean *identical);

/**
//  RegEntryID <-> socket number mapping functions
 *
 *  Availability:
 *    \non_carbon_cfm   in PCCard 3.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSStatus
CECompareCISTPL_MANFID(const RegEntryID *cardRef, UInt16 manufacturerCode,
                       UInt16 manufacturerInfo, Boolean *identical);

/**
 *  CECompareMemory()
 *
 *  Availability:
 *    \non_carbon_cfm   in PCCard 3.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSStatus
CECompareMemory(const RegEntryID *cardRef, PCCardMemoryType memType,
                ByteCount offset, ByteCount length, Byte *dataToCompare,
                Boolean *identical);

/**
 *  CEValidateCIS()
//  Hardware Validation Utilities
 *  Availability:
 *    \non_carbon_cfm   in PCCard 3.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSStatus
CEValidateCIS(UInt32 socket, UInt32 device, UInt32 *lpCISChainCount);

/**
 *  CEDefaultInterruptHandler()
 *
 *  Availability:
 *    \non_carbon_cfm   in PCCard 3.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
InterruptMemberNumber
CEDefaultInterruptHandler(InterruptSetMember ISTmember, void *refCon,
                          UInt32 theIntCount);

/*------------------------------------------------------------------------------------
    PC Card Customization Resources
------------------------------------------------------------------------------------*/
#endif // CALL_NOT_IN_CARBON 
enum {
  kPCCardCustomInfoResType = FOUR_CHAR_CODE('pccd'),
  kPCCardCustomInfoVersion = 0
};

struct PCCardCustomResource {
  long version;
  short customIconID;    //    ICN#, etc. resource ID  short customStringsID; //    STR# resource ID  short customTypeStringIndex;
  short customHelpStringIndex;
  OSType customAction;
  long customActionParam1;
  long customActionParam2;
};
  typedef struct PCCardCustomResource PCCardCustomResource;
#endif // !defined(__CARDSERVICES__)
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

#endif // __PCCARDENABLERPLUGIN__ // CALL_NOT_IN_CARBON
//    ICN#, etc. resource ID
//    STR# resource ID
// !defined(__CARDSERVICES__)
// __PCCARDENABLERPLUGIN__
