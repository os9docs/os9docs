/**
     \file       DriverServices.h

    \brief   Driver Services Interfaces.

    \introduced_in  PowerSurge 1.0.2
    \avaliable_from Universal Interfaces 3.4.1

    \copyright © 1985-2001 by Apple Computer, Inc., all rights reserved

    \ingroup System

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __DRIVERSERVICES__
#define __DRIVERSERVICES__

#ifndef __CONDITIONALMACROS__
#include <ConditionalMacros.h>
#endif

#ifndef __MACTYPES__
#include <MacTypes.h>
#endif

#ifndef __MACERRORS__
#include <MacErrors.h>
#endif

#ifndef __MACHINEEXCEPTIONS__
#include <MachineExceptions.h>
#endif

#ifndef __DEVICES__
#include <Devices.h>
#endif

#ifndef __DRIVERSYNCHRONIZATION__
#include <DriverSynchronization.h>
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
#pragma options align = power
#elif PRAGMA_STRUCT_PACKPUSH
#pragma pack(push, 2)
#elif PRAGMA_STRUCT_PACK
#pragma pack(2)
#endif

  /*******************************************************************
   *
   *      Previously in Kernel.h
   *
   ******************************************************************/
  /** Kernel basics*/
  typedef struct OpaqueIOPreparationID *IOPreparationID;
  typedef struct OpaqueSoftwareInterruptID *SoftwareInterruptID;
  typedef struct OpaqueTaskID *TaskID;
  typedef struct OpaqueTimerID *TimerID;
  /** Tasking*/
  typedef UInt32 ExecutionLevel;
  enum
  {
    kTaskLevel = 0,
    kSoftwareInterruptLevel = 1,
    kAcceptFunctionLevel = 2,
    kKernelLevel = 3,
    kSIHAcceptFunctionLevel = 4,
    kSecondaryInterruptLevel = 5,
    kHardwareInterruptLevel = 6,
    kMPTaskLevel = 7
  };

  typedef CALLBACK_API_C(void, SoftwareInterruptHandler)(void *p1, void *p2);
  typedef CALLBACK_API_C(OSStatus, SecondaryInterruptHandler2)(void *p1,
                                                               void *p2);
#define kCurrentAddressSpaceID ((AddressSpaceID)-1)
  /** Memory System basics*/
  struct LogicalAddressRange
  {
    LogicalAddress address;
    ByteCount count;
  };
  typedef struct LogicalAddressRange LogicalAddressRange;
  typedef LogicalAddressRange *LogicalAddressRangePtr;
  struct PhysicalAddressRange
  {
    PhysicalAddress address;
    ByteCount count;
  };
  typedef struct PhysicalAddressRange PhysicalAddressRange;
  typedef PhysicalAddressRange *PhysicalAddressRangePtr;
  /** For PrepareMemoryForIO and CheckpointIO*/
  typedef OptionBits IOPreparationOptions;
  enum
  {
    kIOMultipleRanges = 0x00000001,
    kIOLogicalRanges = 0x00000002,
    kIOMinimalLogicalMapping = 0x00000004,
    kIOShareMappingTables = 0x00000008,
    kIOIsInput = 0x00000010,
    kIOIsOutput = 0x00000020,
    kIOCoherentDataPath = 0x00000040,
    kIOTransferIsLogical = 0x00000080,
    kIOClientIsUserMode = 0x00000080
  };

  typedef OptionBits IOPreparationState;
  enum
  {
    kIOStateDone = 0x00000001
  };

  enum
  {
    kInvalidPageAddress = (-1)
  };

  struct AddressRange
  {
    void *base;
    ByteCount length;
  };
  typedef struct AddressRange AddressRange;
  /** C's treatment of arrays and array pointers is atypical*/

  typedef LogicalAddress *LogicalMappingTablePtr;
  typedef PhysicalAddress *PhysicalMappingTablePtr;
  typedef AddressRange *AddressRangeTablePtr;
  struct MultipleAddressRange
  {
    ItemCount entryCount;
    AddressRangeTablePtr rangeTable;
  };
  typedef struct MultipleAddressRange MultipleAddressRange;
  /**
     Separate C definition so that union has a name.  A future version of the
     interfacer tool will allow a name (that gets thrown out in Pascal and Asm).
  */
  struct IOPreparationTable
  {
    IOPreparationOptions options;
    IOPreparationState state;
    IOPreparationID preparationID;
    AddressSpaceID addressSpace;
    ByteCount granularity;
    ByteCount firstPrepared;
    ByteCount lengthPrepared;
    ItemCount mappingEntryCount;
    LogicalMappingTablePtr logicalMapping;
    PhysicalMappingTablePtr physicalMapping;
    union
    {
      AddressRange range;
      MultipleAddressRange multipleRanges;
    } rangeInfo;
  };
  typedef struct IOPreparationTable IOPreparationTable;

  typedef OptionBits IOCheckpointOptions;
  enum
  {
    kNextIOIsInput = 0x00000001,
    kNextIOIsOutput = 0x00000002,
    kMoreIOTransfers = 0x00000004
  };

  /** For SetProcessorCacheMode*/

  typedef UInt32 ProcessorCacheMode;
  enum
  {
    kProcessorCacheModeDefault = 0,
    kProcessorCacheModeInhibited = 1,
    kProcessorCacheModeWriteThrough = 2,
    kProcessorCacheModeCopyBack = 3
  };

  /**
     For GetPageInformation
     (Note: if kPageInformationVersion fails, try 0 -- old versions of DSL defined
     kPageInformationVersion as 0)
  */

  enum
  {
    kPageInformationVersion = 1
  };

  typedef UInt32 PageStateInformation;
  enum
  {
    kPageIsProtected = 0x00000001,
    kPageIsProtectedPrivileged = 0x00000002,
    kPageIsModified = 0x00000004,
    kPageIsReferenced = 0x00000008,
    kPageIsLockedResident = 0x00000010, /** held and locked resident*/
    kPageIsInMemory = 0x00000020,
    kPageIsShared = 0x00000040,
    kPageIsWriteThroughCached = 0x00000080,
    kPageIsCopyBackCached = 0x00000100,
    kPageIsHeldResident =
        0x00000200,                        /** held resident - use kPageIsLockedResident to check for
                                              locked state*/
    kPageIsLocked = kPageIsLockedResident, /** Deprecated*/
    kPageIsResident = kPageIsInMemory      /** Deprecated*/
  };

  struct PageInformation
  {
    AreaID area;
    ItemCount count;
    PageStateInformation information[1];
  };
  typedef struct PageInformation PageInformation;
  typedef PageInformation *PageInformationPtr;

/**  Tasks  */
#if CALL_NOT_IN_CARBON
  /**
   *  CurrentExecutionLevel()
   *

   *    \non_carbon_cfm   in DriverServicesLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  ExecutionLevel
  CurrentExecutionLevel(void);

  /**
   *  CurrentTaskID()
   *

   *    \non_carbon_cfm   in DriverServicesLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TaskID
  CurrentTaskID(void);

  /**
   *  DelayFor()
   *

   *    \non_carbon_cfm   in DriverServicesLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  DelayFor(Duration delayDuration);

  /**
   *  InPrivilegedMode()
   *

   *    \non_carbon_cfm   in DriverServicesLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  Boolean
  InPrivilegedMode(void);

  /**  Software Interrupts  */
  /**
   *  CreateSoftwareInterrupt()
   *

   *    \non_carbon_cfm   in DriverServicesLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  CreateSoftwareInterrupt(SoftwareInterruptHandler handler, TaskID task, void *p1,
                          Boolean persistent,
                          SoftwareInterruptID *theSoftwareInterrupt);

  /**
   *  SendSoftwareInterrupt()
   *

   *    \non_carbon_cfm   in DriverServicesLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  SendSoftwareInterrupt(SoftwareInterruptID theSoftwareInterrupt, void *p2);

  /**
   *  DeleteSoftwareInterrupt()
   *

   *    \non_carbon_cfm   in DriverServicesLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  DeleteSoftwareInterrupt(SoftwareInterruptID theSoftwareInterrupt);

#endif /** CALL_NOT_IN_CARBON */

#if TARGET_OS_MAC
/**  Secondary Interrupts  */
#if CALL_NOT_IN_CARBON
  /**
   *  CallSecondaryInterruptHandler2()
   *

   *    \non_carbon_cfm   in DriverServicesLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  CallSecondaryInterruptHandler2(SecondaryInterruptHandler2 theHandler,
                                 ExceptionHandler exceptionHandler, void *p1,
                                 void *p2);

  /**
   *  QueueSecondaryInterruptHandler()
   *

   *    \non_carbon_cfm   in DriverServicesLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  QueueSecondaryInterruptHandler(SecondaryInterruptHandler2 theHandler,
                                 ExceptionHandler exceptionHandler, void *p1,
                                 void *p2);

#endif /** CALL_NOT_IN_CARBON */

#endif /** TARGET_OS_MAC */

/**  Timers  */
#if CALL_NOT_IN_CARBON
  /**
   *  SetInterruptTimer()
   *

   *    \non_carbon_cfm   in DriverServicesLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  SetInterruptTimer(const AbsoluteTime *expirationTime,
                    SecondaryInterruptHandler2 handler, void *p1,
                    TimerID *theTimer);

  /**
   *  SetPersistentTimer()
   *

   *    \non_carbon_cfm   in DriverServicesLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  SetPersistentTimer(Duration frequency, SecondaryInterruptHandler2 theHandler,
                     void *p1, TimerID *theTimer);

  /**
   *  CancelTimer()
   *

   *    \non_carbon_cfm   in DriverServicesLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  CancelTimer(TimerID theTimer, AbsoluteTime *timeRemaining);

  /**  I/O related Operations  */
  /**
   *  PrepareMemoryForIO()
   *

   *    \non_carbon_cfm   in DriverServicesLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  PrepareMemoryForIO(IOPreparationTable *theIOPreparationTable);

  /**
   *  CheckpointIO()
   *

   *    \non_carbon_cfm   in DriverServicesLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  CheckpointIO(IOPreparationID theIOPreparation, IOCheckpointOptions options);

  /**  Memory Operations  */
  /**
   *  GetPageInformation()
   *

   *    \non_carbon_cfm   in DriverServicesLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  GetPageInformation(AddressSpaceID addressSpace, ConstLogicalAddress base,
                     ByteCount length, PBVersion version,
                     PageInformation *thePageInfo);

  /**  Processor Cache Related  */
  /**
   *  SetProcessorCacheMode()
   *

   *    \non_carbon_cfm   in DriverServicesLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  SetProcessorCacheMode(AddressSpaceID addressSpace, ConstLogicalAddress base,
                        ByteCount length, ProcessorCacheMode cacheMode);

/*******************************************************************
 *
 *      Was in DriverSupport.h or DriverServices.h
 *
 ******************************************************************/
#define kAAPLDeviceLogicalAddress "AAPL,address"
#endif /** CALL_NOT_IN_CARBON */

  typedef LogicalAddress *DeviceLogicalAddressPtr;
  enum
  {
    durationMicrosecond = -1L,   /** Microseconds are negative*/
    durationMillisecond = 1L,    /** Milliseconds are positive*/
    durationSecond = 1000L,      /** 1000 * durationMillisecond*/
    durationMinute = 60000L,     /** 60 * durationSecond,*/
    durationHour = 3600000L,     /** 60 * durationMinute,*/
    durationDay = 86400000L,     /** 24 * durationHour,*/
    durationNoWait = 0L,         /** don't block*/
    durationForever = 0x7FFFFFFF /** no time limit*/
  };

  enum
  {
    k8BitAccess = 0,  /** access as 8 bit*/
    k16BitAccess = 1, /** access as 16 bit*/
    k32BitAccess = 2  /** access as 32 bit*/
  };

  typedef UnsignedWide Nanoseconds;

#if CALL_NOT_IN_CARBON
  /**
   *  IOCommandIsComplete()
   *

   *    \non_carbon_cfm   in DriverServicesLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  IOCommandIsComplete(IOCommandID theID, OSErr theResult);

  /**
   *  GetIOCommandInfo()
   *

   *    \non_carbon_cfm   in DriverServicesLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  GetIOCommandInfo(IOCommandID theID, IOCommandContents *theContents,
                   IOCommandCode *theCommand, IOCommandKind *theKind);

  /**
   *  UpdateDeviceActivity()
   *

   *    \non_carbon_cfm   in DriverServicesLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  UpdateDeviceActivity(RegEntryID *deviceEntry);

  /**
   *  BlockCopy()
   *

   *    \non_carbon_cfm   in DriverServicesLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  BlockCopy(const void *srcPtr, void *destPtr, Size byteCount);

  /**
   *  PoolAllocateResident()
   *

   *    \non_carbon_cfm   in DriverServicesLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  LogicalAddress
  PoolAllocateResident(ByteCount byteSize, Boolean clear);

  /**
   *  PoolDeallocate()
   *

   *    \non_carbon_cfm   in DriverServicesLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  PoolDeallocate(LogicalAddress address);

  /**
   *  GetLogicalPageSize()
   *

   *    \non_carbon_cfm   in DriverServicesLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  ByteCount
  GetLogicalPageSize(void);

  /**
   *  GetDataCacheLineSize()
   *

   *    \non_carbon_cfm   in DriverServicesLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  ByteCount
  GetDataCacheLineSize(void);

  /**
   *  FlushProcessorCache()
   *

   *    \non_carbon_cfm   in DriverServicesLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  FlushProcessorCache(AddressSpaceID spaceID, LogicalAddress base,
                      ByteCount length);

  /**
   *  MemAllocatePhysicallyContiguous()
   *

   *    \non_carbon_cfm   in DriverServicesLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  LogicalAddress
  MemAllocatePhysicallyContiguous(ByteCount byteSize, Boolean clear);

  /**
   *  MemDeallocatePhysicallyContiguous()
   *

   *    \non_carbon_cfm   in DriverServicesLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  MemDeallocatePhysicallyContiguous(LogicalAddress address);

#endif /** CALL_NOT_IN_CARBON */

  /**
   *  UpTime()
   *

   *    \non_carbon_cfm   in InterfaceLib 8.6 and later
   *    \carbon_lib        in CarbonLib 1.0.2 and later
   *    \mac_os_x         in version 10.0 and later
   */
  AbsoluteTime
  UpTime(void);

#if CALL_NOT_IN_CARBON
  /**
   *  GetTimeBaseInfo()
   *

   *    \non_carbon_cfm   in InterfaceLib 8.6 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  GetTimeBaseInfo(UInt32 *minAbsoluteTimeDelta,
                  UInt32 *theAbsoluteTimeToNanosecondNumerator,
                  UInt32 *theAbsoluteTimeToNanosecondDenominator,
                  UInt32 *theProcessorToAbsoluteTimeNumerator,
                  UInt32 *theProcessorToAbsoluteTimeDenominator);

#endif /** CALL_NOT_IN_CARBON */

  /**
   *  AbsoluteToNanoseconds()
   *

   *    \non_carbon_cfm   in InterfaceLib 8.6 and later
   *    \carbon_lib        in CarbonLib 1.0.2 and later
   *    \mac_os_x         in version 10.0 and later
   */
  Nanoseconds
  AbsoluteToNanoseconds(AbsoluteTime absoluteTime);

  /**
   *  AbsoluteToDuration()
   *

   *    \non_carbon_cfm   in InterfaceLib 8.6 and later
   *    \carbon_lib        in CarbonLib 1.0.2 and later
   *    \mac_os_x         in version 10.0 and later
   */
  Duration
  AbsoluteToDuration(AbsoluteTime absoluteTime);

  /**
   *  NanosecondsToAbsolute()
   *

   *    \non_carbon_cfm   in InterfaceLib 8.6 and later
   *    \carbon_lib        in CarbonLib 1.0.2 and later
   *    \mac_os_x         in version 10.0 and later
   */
  AbsoluteTime
  NanosecondsToAbsolute(Nanoseconds nanoseconds);

  /**
   *  DurationToAbsolute()
   *

   *    \non_carbon_cfm   in InterfaceLib 8.6 and later
   *    \carbon_lib        in CarbonLib 1.0.2 and later
   *    \mac_os_x         in version 10.0 and later
   */
  AbsoluteTime
  DurationToAbsolute(Duration duration);

  /**
   *  AddAbsoluteToAbsolute()
   *

   *    \non_carbon_cfm   in InterfaceLib 8.6 and later
   *    \carbon_lib        in CarbonLib 1.0.2 and later
   *    \mac_os_x         in version 10.0 and later
   */
  AbsoluteTime
  AddAbsoluteToAbsolute(AbsoluteTime absoluteTime1, AbsoluteTime absoluteTime2);

  /**
   *  SubAbsoluteFromAbsolute()
   *

   *    \non_carbon_cfm   in InterfaceLib 8.6 and later
   *    \carbon_lib        in CarbonLib 1.0.2 and later
   *    \mac_os_x         in version 10.0 and later
   */
  AbsoluteTime
  SubAbsoluteFromAbsolute(AbsoluteTime leftAbsoluteTime,
                          AbsoluteTime rightAbsoluteTime);

  /**
   *  AddNanosecondsToAbsolute()
   *

   *    \non_carbon_cfm   in InterfaceLib 8.6 and later
   *    \carbon_lib        in CarbonLib 1.0.2 and later
   *    \mac_os_x         in version 10.0 and later
   */
  AbsoluteTime
  AddNanosecondsToAbsolute(Nanoseconds nanoseconds, AbsoluteTime absoluteTime);

  /**
   *  AddDurationToAbsolute()
   *

   *    \non_carbon_cfm   in InterfaceLib 8.6 and later
   *    \carbon_lib        in CarbonLib 1.0.2 and later
   *    \mac_os_x         in version 10.0 and later
   */
  AbsoluteTime
  AddDurationToAbsolute(Duration duration, AbsoluteTime absoluteTime);

  /**
   *  SubNanosecondsFromAbsolute()
   *

   *    \non_carbon_cfm   in InterfaceLib 8.6 and later
   *    \carbon_lib        in CarbonLib 1.0.2 and later
   *    \mac_os_x         in version 10.0 and later
   */
  AbsoluteTime
  SubNanosecondsFromAbsolute(Nanoseconds nanoseconds, AbsoluteTime absoluteTime);

  /**
   *  SubDurationFromAbsolute()
   *

   *    \non_carbon_cfm   in InterfaceLib 8.6 and later
   *    \carbon_lib        in CarbonLib 1.0.2 and later
   *    \mac_os_x         in version 10.0 and later
   */
  AbsoluteTime
  SubDurationFromAbsolute(Duration duration, AbsoluteTime absoluteTime);

  /**
   *  AbsoluteDeltaToNanoseconds()
   *

   *    \non_carbon_cfm   in InterfaceLib 8.6 and later
   *    \carbon_lib        in CarbonLib 1.0.2 and later
   *    \mac_os_x         in version 10.0 and later
   */
  Nanoseconds
  AbsoluteDeltaToNanoseconds(AbsoluteTime leftAbsoluteTime,
                             AbsoluteTime rightAbsoluteTime);

  /**
   *  AbsoluteDeltaToDuration()
   *

   *    \non_carbon_cfm   in InterfaceLib 8.6 and later
   *    \carbon_lib        in CarbonLib 1.0.2 and later
   *    \mac_os_x         in version 10.0 and later
   */
  Duration
  AbsoluteDeltaToDuration(AbsoluteTime leftAbsoluteTime,
                          AbsoluteTime rightAbsoluteTime);

  /**
   *  DurationToNanoseconds()
   *

   *    \non_carbon_cfm   in InterfaceLib 8.6 and later
   *    \carbon_lib        in CarbonLib 1.0.2 and later
   *    \mac_os_x         in version 10.0 and later
   */
  Nanoseconds
  DurationToNanoseconds(Duration theDuration);

  /**
   *  NanosecondsToDuration()
   *

   *    \non_carbon_cfm   in InterfaceLib 8.6 and later
   *    \carbon_lib        in CarbonLib 1.0.2 and later
   *    \mac_os_x         in version 10.0 and later
   */
  Duration
  NanosecondsToDuration(Nanoseconds theNanoseconds);

#if CALL_NOT_IN_CARBON
  /**
   *  PBQueueInit()
   *

   *    \non_carbon_cfm   in DriverServicesLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  PBQueueInit(QHdrPtr qHeader);

  /**
   *  PBQueueCreate()
   *

   *    \non_carbon_cfm   in DriverServicesLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  PBQueueCreate(QHdrPtr *qHeader);

  /**
   *  PBQueueDelete()
   *

   *    \non_carbon_cfm   in DriverServicesLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  PBQueueDelete(QHdrPtr qHeader);

  /**
   *  PBEnqueue()
   *

   *    \non_carbon_cfm   in DriverServicesLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  PBEnqueue(QElemPtr qElement, QHdrPtr qHeader);

  /**
   *  PBEnqueueLast()
   *

   *    \non_carbon_cfm   in DriverServicesLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  PBEnqueueLast(QElemPtr qElement, QHdrPtr qHeader);

  /**
   *  PBDequeue()
   *

   *    \non_carbon_cfm   in DriverServicesLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  PBDequeue(QElemPtr qElement, QHdrPtr qHeader);

  /**
   *  PBDequeueFirst()
   *

   *    \non_carbon_cfm   in DriverServicesLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  PBDequeueFirst(QHdrPtr qHeader, QElemPtr *theFirstqElem);

  /**
   *  PBDequeueLast()
   *

   *    \non_carbon_cfm   in DriverServicesLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  PBDequeueLast(QHdrPtr qHeader, QElemPtr *theLastqElem);

  /**
   *  CStrCopy()
   *

   *    \non_carbon_cfm   in DriverServicesLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  char *
  CStrCopy(char *dst, const char *src);

  /**
   *  PStrCopy()
   *

   *    \non_carbon_cfm   in DriverServicesLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  StringPtr
  PStrCopy(StringPtr dst, ConstStr255Param src);

  /**
   *  CStrNCopy()
   *

   *    \non_carbon_cfm   in DriverServicesLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  char *
  CStrNCopy(char *dst, const char *src, UInt32 max);

  /**
   *  PStrNCopy()
   *

   *    \non_carbon_cfm   in DriverServicesLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  StringPtr
  PStrNCopy(StringPtr dst, ConstStr255Param src, UInt32 max);

  /**
   *  CStrCat()
   *

   *    \non_carbon_cfm   in DriverServicesLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  char *
  CStrCat(char *dst, const char *src);

  /**
   *  PStrCat()
   *

   *    \non_carbon_cfm   in DriverServicesLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  StringPtr
  PStrCat(StringPtr dst, ConstStr255Param src);

  /**
   *  CStrNCat()
   *

   *    \non_carbon_cfm   in DriverServicesLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  char *
  CStrNCat(char *dst, const char *src, UInt32 max);

  /**
   *  PStrNCat()
   *

   *    \non_carbon_cfm   in DriverServicesLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  StringPtr
  PStrNCat(StringPtr dst, ConstStr255Param src, UInt32 max);

  /**
   *  PStrToCStr()
   *

   *    \non_carbon_cfm   in DriverServicesLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  PStrToCStr(char *dst, ConstStr255Param src);

  /**
   *  CStrToPStr()
   *

   *    \non_carbon_cfm   in DriverServicesLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  CStrToPStr(Str255 dst, const char *src);

  /**
   *  CStrCmp()
   *

   *    \non_carbon_cfm   in DriverServicesLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  SInt16
  CStrCmp(const char *s1, const char *s2);

  /**
   *  PStrCmp()
   *

   *    \non_carbon_cfm   in DriverServicesLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  SInt16
  PStrCmp(ConstStr255Param str1, ConstStr255Param str2);

  /**
   *  CStrNCmp()
   *

   *    \non_carbon_cfm   in DriverServicesLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  SInt16
  CStrNCmp(const char *s1, const char *s2, UInt32 max);

  /**
   *  PStrNCmp()
   *

   *    \non_carbon_cfm   in DriverServicesLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  SInt16
  PStrNCmp(ConstStr255Param str1, ConstStr255Param str2, UInt32 max);

  /**
   *  CStrLen()
   *

   *    \non_carbon_cfm   in DriverServicesLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  UInt32
  CStrLen(const char *src);

  /**
   *  PStrLen()
   *

   *    \non_carbon_cfm   in DriverServicesLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  UInt32
  PStrLen(ConstStr255Param src);

  /**
   *  DeviceProbe()
   *

   *    \non_carbon_cfm   in DriverServicesLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  DeviceProbe(void *theSrc, void *theDest, UInt32 AccessType);

  /**
   *  DelayForHardware()
   *

   *    \non_carbon_cfm   in DriverServicesLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  DelayForHardware(AbsoluteTime absoluteTime);

/*******************************************************************
 *
 *      Was in Interrupts.h
 *
 ******************************************************************/
/**  Interrupt types  */
#endif /** CALL_NOT_IN_CARBON */

  typedef struct OpaqueInterruptSetID *InterruptSetID;
  typedef long InterruptMemberNumber;
  struct InterruptSetMember
  {
    InterruptSetID setID;
    InterruptMemberNumber member;
  };
  typedef struct InterruptSetMember InterruptSetMember;
  enum
  {
    kISTChipInterruptSource = 0,
    kISTOutputDMAInterruptSource = 1,
    kISTInputDMAInterruptSource = 2,
    kISTPropertyMemberCount = 3
  };

  typedef InterruptSetMember ISTProperty[3];
#define kISTPropertyName "driver-ist"

  typedef long InterruptReturnValue;
  enum
  {
    kFirstMemberNumber = 1,
    kIsrIsComplete = 0,
    kIsrIsNotComplete = -1,
    kMemberNumberParent = -2
  };

  typedef Boolean InterruptSourceState;
  enum
  {
    kSourceWasEnabled = true,
    kSourceWasDisabled = false
  };

  typedef CALLBACK_API_C(InterruptMemberNumber,
                         InterruptHandler)(InterruptSetMember ISTmember,
                                           void *refCon, UInt32 theIntCount);
  typedef CALLBACK_API_C(void, InterruptEnabler)(InterruptSetMember ISTmember,
                                                 void *refCon);
  typedef CALLBACK_API_C(InterruptSourceState,
                         InterruptDisabler)(InterruptSetMember ISTmember,
                                            void *refCon);
  enum
  {
    kReturnToParentWhenComplete = 0x00000001,
    kReturnToParentWhenNotComplete = 0x00000002
  };

  typedef OptionBits InterruptSetOptions;
/**  Interrupt Services  */
#if CALL_NOT_IN_CARBON
  /**
   *  CreateInterruptSet()
   *

   *    \non_carbon_cfm   in DriverServicesLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  CreateInterruptSet(InterruptSetID parentSet, InterruptMemberNumber parentMember,
                     InterruptMemberNumber setSize, InterruptSetID *setID,
                     InterruptSetOptions options);

  /**
   *  InstallInterruptFunctions()
   *

   *    \non_carbon_cfm   in DriverServicesLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  InstallInterruptFunctions(InterruptSetID setID, InterruptMemberNumber member,
                            void *refCon, InterruptHandler handlerFunction,
                            InterruptEnabler enableFunction,
                            InterruptDisabler disableFunction);

  /**
   *  GetInterruptFunctions()
   *

   *    \non_carbon_cfm   in DriverServicesLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  GetInterruptFunctions(InterruptSetID setID, InterruptMemberNumber member,
                        void **refCon, InterruptHandler *handlerFunction,
                        InterruptEnabler *enableFunction,
                        InterruptDisabler *disableFunction);

  /**
   *  ChangeInterruptSetOptions()
   *

   *    \non_carbon_cfm   in DriverServicesLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  ChangeInterruptSetOptions(InterruptSetID setID, InterruptSetOptions options);

  /**
   *  GetInterruptSetOptions()
   *

   *    \non_carbon_cfm   in DriverServicesLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  GetInterruptSetOptions(InterruptSetID setID, InterruptSetOptions *options);

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

#endif /** __DRIVERSERVICES__ */
