/**
   \file       MultiprocessingInfo.h

   \brief   Multiprocessing Information interfaces

   \introduced_in  Multiprocessing Information API version 2.2
   \avaliable_from Universal Interfaces 3.4.1

   \copyright � 1995-2001 DayStar Digital, Inc.

   \ingroup Multiprocessing

   This is the header file for version 2.3 of the Mac OS multiprocessing
   information support.

   The following services are new in version 2.1:

   * MPGetNextTaskID

   * MPGetNextCpuID

   The following services are new in version 2.2:

   * MPGetPageSizeClasses

   * MPGetPageSize

   * MPGetNextAreaID

   The following services are new in version 2.3:

   * MPGetNextCoherenceID

   * MPGetNextProcessID

   * MPGetNextAddressSpaceID

   * MPGetNextQueueID

   * MPGetNextSemaphoreID

   * MPGetNextCriticalRegionID

   * MPGetNextTimerID

   * MPGetNextEventID

   * MPGetNextNotificationID

   * MPGetNextConsoleID

   For bug reports, consult the following page on the World Wide Web:  http://developer.apple.com/bugreporter/

   \warning You must properly check the availability of MP services before calling them! See CheckingAPIAvailability

   */

#ifndef __MULTIPROCESSINGINFO__
#define __MULTIPROCESSINGINFO__

#ifndef __MACTYPES__
#include <MacTypes.h>
#endif

#ifndef __MULTIPROCESSING__
#include <Multiprocessing.h>
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

  /**
     \section Page size Services
  */

#if CALL_NOT_IN_CARBON
  /**
   *  MPGetPageSizeClasses()
   *
   * The number of page size classes, 1 to n.
   *
   *    \non_carbon_cfm   in MPDiagnostics 2.3 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  MPPageSizeClass MPGetPageSizeClasses(void);
#endif // CALL_NOT_IN_CARBON 
#if CALL_NOT_IN_CARBON
  /**
   *  MPGetPageSize()
   *
   * The page size in bytes.
   *    \non_carbon_cfm   in MPDiagnostics 2.3 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  ByteCount MPGetPageSize(MPPageSizeClass pageClass);

#endif // CALL_NOT_IN_CARBON 
  /**// CALL_NOT_IN_CARBON 
     \section ID Iterator Services
     ========*/

#if CALL_NOT_IN_CARBON
  /**
   *  MPGetNextCoherenceID()
   *

   *    \non_carbon_cfm   in MPDiagnostics 2.3 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus MPGetNextCoherenceID(MPCoherenceID *coherenceID);

  /**
   *  MPGetNextCpuID()
   *

   *    \non_carbon_cfm   in MPDiagnostics 2.3 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus MPGetNextCpuID(MPCoherenceID owningCoherenceID, MPCpuID *cpuID);

  /**
   *  MPGetNextProcessID()
   *

   *    \non_carbon_cfm   in MPDiagnostics 2.3 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus MPGetNextProcessID(MPProcessID *processID);

  /**
   *  MPGetNextAddressSpaceID()
   *

   *    \non_carbon_cfm   in MPDiagnostics 2.3 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus MPGetNextAddressSpaceID(MPProcessID owningProcessID,
                                   MPAddressSpaceID *addressSpaceID);

  /**
   *  MPGetNextTaskID()
   *

   *    \non_carbon_cfm   in MPDiagnostics 2.3 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus MPGetNextTaskID(MPProcessID owningProcessID, MPTaskID *taskID);

  /**
   *  MPGetNextQueueID()
   *

   *    \non_carbon_cfm   in MPDiagnostics 2.3 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus MPGetNextQueueID(MPProcessID owningProcessID, MPQueueID *queueID);

  /**
   *  MPGetNextSemaphoreID()
   *

   *    \non_carbon_cfm   in MPDiagnostics 2.3 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus MPGetNextSemaphoreID(MPProcessID owningProcessID, MPSemaphoreID *semaphoreID);

  /**
   *  MPGetNextCriticalRegionID()
   *

   *    \non_carbon_cfm   in MPDiagnostics 2.3 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus MPGetNextCriticalRegionID(MPProcessID owningProcessID,
                                     MPCriticalRegionID *criticalRegionID);

  /**
   *  MPGetNextTimerID()
   *

   *    \non_carbon_cfm   in MPDiagnostics 2.3 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus MPGetNextTimerID(MPProcessID owningProcessID, MPTimerID *timerID);

  /**
   *  MPGetNextEventID()
   *

   *    \non_carbon_cfm   in MPDiagnostics 2.3 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus MPGetNextEventID(MPProcessID owningProcessID, MPEventID *eventID);

  /**
   *  MPGetNextNotificationID()
   *
   *    \non_carbon_cfm   in MPDiagnostics 2.3 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus MPGetNextNotificationID(MPProcessID owningProcessID,
                                   MPNotificationID *notificationID);

#endif // CALL_NOT_IN_CARBON 
#if CALL_NOT_IN_CARBON
  /**// CALL_NOT_IN_CARBON 
   *  MPGetNextAreaID()
   *

   *    \non_carbon_cfm   in MPDiagnostics 2.3 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  MPGetNextAreaID(MPAddressSpaceID owningSpaceID, MPAreaID *areaID);

#endif // CALL_NOT_IN_CARBON 
#if CALL_NOT_IN_CARBON
  /**
   *  M// CALL_NOT_IN_CARBON 
   *

   *    \non_carbon_cfm   in MPDiagnostics 2.3 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus MPGetNextConsoleID(MPConsoleID *consoleID);

  /**
   *  MPGetNextID()
   *

   *    \non_carbon_cfm   in MPDiagnostics 2.3 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus MPGetNextID(MPOpaqueIDClass kind, MPOpaqueID *id);

  /**
     \section Object Information Services
     \warning The implementation of MPGetObjectInfo assumes that all info records are in 4 byte multiples.
  */

#endif // CALL_NOT_IN_CARBON 
  enum
  {
    // The version of the MPAreaInfo structure requested.    kMPQueueInfoVersion = 1L | (kOpaqueQueueID << 16),
    kMP// CALL_NOT_IN_CARBON 
    kMPEventInfoVersion = 1L | (kOpaqueEventID << 16),
    kMPCriticalRegionInfoVersion = 1L | (kOpaqueCriticalRegionID << 16),
    kMPNotificationInfoVersion = 1L | (kOpaqueNotificationID << 16),
    // The version of the MPAreaInfo structure requested.
  };

  struct MPQueueInfo
  {
    PBVersion version; // Version of the data structure requested
    MPProcessID processID; // Owning process ID    OSType queueName;      // Queue name
    ItemCount nWaiting;
    MPTaskID waitingTaskID; // First waiting task.
    ItemCount nMessages;
    ItemCount nReserved;
// Version of the data structure requested
    void *p1; /*< First message parameters...*/
    void *p2;// Owning process ID
    void *p3;// Queue name
  };
  typedef struct MPQueueInfo MPQueueInfo;
  struct MPSemaphoreInfo// First waiting task.
  {
    PBVersion version; /*< Version of the data structure requested*/

    MPProcessID processID; /*< Owning process ID*/
    OSType semaphoreName;  /*< Semaphore name*/

    ItemCount nWaiting;
    MPTaskID waitingTaskID; /*< First waiting task.*/

    ItemCount maximum;
    ItemCount count;
  };
  typedef struct MPSemaphoreInfo MPSemaphoreInfo;
  struct MPEventInfo
  {
    PBVersion version; /*< Version of the data structure requested*/

    MPProcessID processID; /*< Owning process ID*/
    OSType eventName;      /*< Event name*/

    ItemCount nWaiting;
    MPTaskID waitingTaskID; /*< First waiting task.*/

    MPEventFlags events;
  };
  typedef struct MPEventInfo MPEventInfo;
  struct MPCriticalRegionInfo
  {
    PBVersion version; /*< Version of the data structure requested*/

    MPProcessID processID; /*< Owning process ID*/
    OSType regionName;     /*< Critical region name*/

    ItemCount nWaiting;
    MPTaskID waitingTaskID; /*< First waiting task.*/

    MPTaskID owningTask;
    ItemCount count;
  };
  typedef struct MPCriticalRegionInfo MPCriticalRegionInfo;
  struct MPNotificationInfo
  {
    PBVersion version; /*< Version of the data structure requested*/

    MPProcessID processID;   /*< Owning process ID*/
    OSType notificationName; /*< Notification name*/

    MPQueueID queueID; /*< Queue to notify.*/
    void *p1;
    void *p2;
    void *p3;

    MPEventID eventID; /*< Event to set.*/
    MPEventFlags events;

    MPSemaphoreID semaphoreID; /*< Sempahore to signal.   */
  };
  typedef struct MPNotificationInfo MPNotificationInfo;
  struct MPAddressSpaceInfo
  {
    PBVersion version; /*< Version of the data structure requested*/

    MPProcessID processID; /*< Owning process ID*/
    MPCoherenceID groupID; /*< Related coherence group.*/
    ItemCount nTasks;      /*< Number of tasks in this space.*/
    UInt32 vsid[16];       /*< Segment register VSIDs.*/
  };
  typedef struct MPAddressSpaceInfo MPAddressSpaceInfo;
  // *** We should put the task info call here instead of in MPExtractTaskState.
#if CALL_NOT_IN_CARBON
  /**
   *  MPGetQueueInfo()
   *

   *    \non_carbon_cfm   in MPDiagnostics 2.3 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  // *** We should put the task info call here instead of in MPExtractTaskState.

  /**
   *  MPGetSemaphoreInfo()
   *

   *    \non_carbon_cfm   in MPDiagnostics 2.3 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus MPGetSemaphoreInfo(MPSemaphoreID id, PBVersion version,
                              MPSemaphoreInfo *info_o);

  /**
   *  MPGetEventInfo()
   *

   *    \non_carbon_cfm   in MPDiagnostics 2.3 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus MPGetEventInfo(MPEventID id, PBVersion version, MPEventInfo *info_o);

  /**
   *  MPGetCriticalRegionInfo()
   *

   *    \non_carbon_cfm   in MPDiagnostics 2.3 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus MPGetCriticalRegionInfo(MPCriticalRegionID id, PBVersion version,
                                   MPCriticalRegionInfo *info_o);

  /**
   *  MPGetNotificationInfo()
   *

   *    \non_carbon_cfm   in MPDiagnostics 2.3 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus MPGetNotificationInfo(MPNotificationID id, PBVersion version,
                                 MPNotificationInfo *info_o);

  /**
   *  MPGetAddressSpaceInfo()
   *

   *    \non_carbon_cfm   in MPDiagnostics 2.3 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus MPGetAddressSpaceInfo(MPAddressSpaceID id, PBVersion version,
                                 MPAddressSpaceInfo *info_o);

#endif // CALL_NOT_IN_CARBON 
#if PRAGMA_STRUCT_ALIGN
#pragma options align = reset
#elif PRAGMA_STRUCT_PACKPUSH
#pragma pack(pop)
#elif PRAGMA_STRUCT_PACK
#pragma pack()
#endif

#ifdef PRAGMA_IMPORT_OFF
#pragma import off
#elif P// CALL_NOT_IN_CARBON 
#pragma import reset
#endif

#ifdef __cplusplus
}
#endif

#endif // __MULTIPROCESSINGINFO__ // __MULTIPROCESSINGINFO__ 
