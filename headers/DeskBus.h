/**
     \file       DeskBus.h

    \brief   Apple Desktop Bus (ADB) Interfaces.

    \introduced_in  System 8.5
    \avaliable_from Universal Interfaces 3.4.1

    \copyright � 1987-2001 by Apple Computer, Inc., all rights reserved

    \ingroup Hardware

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __DESKBUS__
#define __DESKBUS__

#ifndef __MACTYPES__
#include <MacTypes.h>
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

  typedef SInt8 ADBAddress;
#if CALL_NOT_IN_CARBON
  typedef CALLBACK_API_REGISTER68K(void, ADBCompletionProcPtr,
                                   (Ptr buffer, Ptr refCon, long command));
  typedef CALLBACK_API_REGISTER68K(void, ADBDeviceDriverProcPtr,
                                   (SInt8 devAddress, SInt8 devType));
  /**
      TempADBServiceRoutineUPP is needed because of circular definition of
      ADBServiceRoutineProcPtr and ADBServiceRoutineUPP depending on each other.
  */
  typedef REGISTER_UPP_TYPE(ADBServiceRoutineProcPtr) TempADBServiceRoutineUPP;
  typedef CALLBACK_API_REGISTER68K(void, ADBServiceRoutineProcPtr,
                                   (Ptr buffer,
                                    TempADBServiceRoutineUPP completionProc,
                                    Ptr refCon, long command));
  typedef CALLBACK_API_REGISTER68K(void, ADBInitProcPtr, (SInt8 callOrder));
  typedef REGISTER_UPP_TYPE(ADBCompletionProcPtr) ADBCompletionUPP;
  typedef REGISTER_UPP_TYPE(ADBDeviceDriverProcPtr) ADBDeviceDriverUPP;
  typedef REGISTER_UPP_TYPE(ADBServiceRoutineProcPtr) ADBServiceRoutineUPP;
  typedef REGISTER_UPP_TYPE(ADBInitProcPtr) ADBInitUPP;
  /**
  <pre>
   * \copyright THINK Reference © 1991-1992 Symantec Corporation
  */
  struct ADBDataBlock
  {
    char devType;       /**< What kind of an input only device?*/
    char origADBAddr;   /**< Device's original bus address*/
    Ptr dbServiceRtPtr; /**< Address of the service routine*/
    Ptr dbDataAreaAddr; /**< Address of the data area*/
  } ADBDataBlock;       /**< */

  typedef struct ADBDataBlock ADBDataBlock;
  typedef ADBDataBlock *ADBDBlkPtr;
  /**
  <pre>
   * \copyright THINK Reference © 1991-1992 Symantec Corporation
  */
  struct ADBSetInfoBlock
  {
    Ptr siServiceRtPtr; /**<  Address of the service routine*/
    Ptr siDataAreaAddr; /**<  Address of the data area*/
  } ADBSetInfoBlock;    /**< */

  typedef struct ADBSetInfoBlock ADBSetInfoBlock;
  typedef ADBSetInfoBlock *ADBSInfoPtr;
  // ADBOpBlock is only used when calling ADBOp from 68k assembly code
  /**
   <pre>
           * \copyright THINK Reference © 1991 - 1992 Symantec Corporation*/
  struct ADBOpBlock
  {
    Ptr dataBuffPtr;    /**<   address of data buffer*/
    Ptr opServiceRtPtr; /**<   service routine pointer*/
    Ptr opDataAreaPtr;  /**<   optional data area address*/
  } ADBOpBlock;         /**< */

  typedef struct ADBOpBlock ADBOpBlock;
  typedef ADBOpBlock *ADBOpBPtr;
#endif // CALL_NOT_IN_CARBON
#if CALL_NOT_IN_CARBON
  /**ADBReInit() *

          *    \non_carbon_cfm in InterfaceLib 7.1 and
      later
              *    \carbon_lib not available
          *    \mac_os_x not available */
  void ADBReInit(void);

/**
    ADBOp has a different interface for 68k assembly than for everything else
    for 68k assembly the interface is
    #pragma parameter __D0 ADBOp(__A0,__D0)
    OSErr ADBOp( ADBOpBlock * pb, short commandNum );
*/
/**
    IMPORTANT NOTE:
    "Inside Macintosh: Devices" documents the completion routine for ADBOp will
   be called with four parameters using 68k register based calling conventions,
   specifically the completion routine passed in should be of type
   ADBServiceRoutineProcPtr. However, when upp types were first added to this
   interface file, the type ADBCompletionUPP was mistakenly used for the second
   parameter to ADBOp. Since applications have shipped using completion routines
   of type ADBCompletionUPP, the mistake cannot be corrected. The only
   difference between ADBServiceRoutineUPP and ADBCompletionUPP is the former
   takes an extra argument which is a pointer to itself, fortunately not needed
   for PowerPC code. For compatibility with existing 68k code, when an ADBOp
   completion routine is called, 68k register A1 will point to the completion
   routine, as documented in Inside Mac.
*/
#endif // CALL_NOT_IN_CARBON
#if CALL_NOT_IN_CARBON
  // CALL_NOT_IN_CARBON
  /**
  \brief Transmit command byte

  <pre>Use ADBOp to send the command byte specified by the value in commandNum
  field and instruct a bus-connected mouse or keyboard to SendReset, Flush,
  Talk, or Listen.
  datais an optional data area for local completion routine storage.
  compRout is a completion routine structure.
  bufferis a data area whose length is contained in its first byte.
  commandNum is the value of the command byte signifying SendReset, Flush, Talk
  or Listen.
  </pre>
  * \returns <pre>an operating system Error Code . It will be one of:
  noErr(0) No error
  Err(-1) Unsuccessful completion
  </pre>
  * \note <pre>ADBOp executes only when the bus is idle. The rest of the time it is held
  in a command queue. ADBOp returns an error if the command queue is full.
  On entry, D0 holds the commandNum short and register AO contains a
  pointer to a parameter block whose fields are:
  Out-In NameType SizeOffsetDescription
  ->buffer Ptr 40Address of buffer for 8-bytes data
  (max.), 1 byte length prefix
  ->compRout Ptr 44Completion routine address
  ->data Ptr 48Optional data area for local storage
  compRout points to a completion routine which is passed the parameters
  for:
  1) commandNum in D0 (these are the commands to the device to:
  SendReset, Flush, Listen and Talk);
  2) a pointer in A0 to a buffer storing the bus device's send and receive data
  as a variable length Pascal string (but not exceeding 8 data bytes and a
  one-byte length prefix);
  3) a pointer in A1 to the completion routine itself; and
  4) a pointer in A2 to an optional data area designed to hold the completion
  routine's data.
  The completion routine is called when the ADBOp procedure has finished
  execution and has the same meaning as the service routine passed to the
  </pre>
  * \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
  *    \carbon_lib        not available
  *    \mac_os_x         not available
  */
  OSErr ADBOp(Ptr refCon, ADBCompletionUPP compRout, Ptr buffer, short commandNum);

#endif // CALL_NOT_IN_CARBON
#if CALL_NOT_IN_CARBON

  /**
  \brief Count the entries in the device table

              <pre>
                  CountADBs generates and returns a value representing the number of
                      devices connected to the bus.It derives the number by counting the entries in
                          the device table.</ pre>
                              * \returns<pre> a short representing the number of devices in the table.</ pre>
                                  * \copyright THINK Reference © 1991 -
          1992 Symantec Corporation
              *    \non_carbon_cfm in InterfaceLib 7.1 and
      later
              *    \carbon_lib not available *    \mac_os_x not available *
          /
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 CountADBs
#endif
          short
          CountADBs(void);

/**
\brief Find out device's address

<pre>Use GetIndADB to obtain a device's current bus address.
info is a parameter block whose relevant fields are:
Out-In Name Type Size Offset Description
<-devType SignedByte 1 0 Is it a mouse, keyboard, etc.?
<-origADBAddr SignedByte 1 1 Original bus address
<-dbServiceRtPtr Ptr 4 2 Pointer to a service routine
<-dbDataAreaAddr Ptr 4 6 Pointer to a data area
devTableIndex is the index number on the device table of the entry whose address is
being sought.
</pre>
* \returns <pre>a bus address byte for the device specified by the device table
index. A negative number is returned if the search ends
without finding the device.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 GetIndADB(__A0, __D0)
#endif
  ADBAddress
  GetIndADB(ADBDataBlock *info, short devTableIndex);

/**
\brief Obtain information on the specified device

<pre>Use GetADBInfo to obtain current information about a device's address, ID,
service routine and data area.
info is a parameter block whose relevant fields are:
Out-In Name Type SizeOffset Description
<-devHandlerID SignedByte 1 0Device type ID
<-origADBAddr SignedByte 1 1Original bus address
<- dbServiceRtPtr Ptr 42 Pointer to a service routine
<- dbDataAreaAddr Ptr 46 Pointer to a data area
ADBAddr is the index number on the device table of the entry being queried.
</pre>
* \returns <pre>an operating system Error Code .
noErr(0) No error
</pre>
* \note <pre> The devHandlerID parameter indicates the device type, which the
application can change if the device is capable of various modes of operation.
Values below 0x20 are reserved by Apple and other specific values
precipitate actions rather than being stored to indicate device type: 0x00
changes bits 8 through 13 of register 3 to mirror the rest of the Listen
command but leaves the device type unchanged; 0xFD, when sent by the
Listen command, changes the device address to match bits 8 through 11 if
the device activator is depressed but leaves the device type and the flags the
same as they were; 0xFE, when sent sent by the Listen command, will
change the device address to match bits 8 through 11 as long as no other
device already has that address but leaves the devHandlerID and flags
unchanged; and 0xFF, when sent by the Listen command, causes the device
to run a self-test. A successful test leaves register 3 the same as before,
while a failed self-test clears the devHandlerID field to 0x00.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 GetADBInfo(__A0, __D0)
#endif
  OSErr GetADBInfo(ADBDataBlock *info, ADBAddress adbAddr);

/**
\brief Establish a device's service routine address and data area address

<pre>Use SetADBInfo to establish a device's service routine address and data area
address in the device table.
info is a parameter block whose relevant fields are:
Out-In NameType SizeOffset Description
-> siServiceRtPtr Ptr 40 Pointer to a service routine
-> siDataAreaAddr Ptr 44 Pointer to a data area
ADBAddr is the index number on the device table of the entry being queried.
</pre>
* \returns <pre>an operating system Error Code .
noErr(0) No error
</pre>
* \note <pre>  Send the Flush command to the device after you call this procedure as a
way of keeping it from sending old data to the new data area address.
Apple Tech Note 206 points out that just by using SetADBInfo to install a
service routine for the appropriate address you can add devices to the bus
without having to call the ADBReInit procedure and all the bugs associated
with it.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 SetADBInfo(__A0, __D0)
#endif
  OSErr SetADBInfo(const ADBSetInfoBlock *info, ADBAddress adbAddr);

#endif // CALL_NOT_IN_CARBON
#if CALL_NOT_IN_CARBON
  /**
   *  NewADBCompletionUPP()
   * \non_carbon_cfm available as macro / inline
   * \carbon_lib not available
   * \mac_os_x not available
   */
  ADBCompletionUPP
  NewADBCompletionUPP(ADBCompletionProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppADBCompletionProcInfo = 0x007B9802
  }; // register no_return_value Func(4_bytes:A0, 4_bytes:A2, 4_bytes:D0) #ifdef __cplusplus
  inline ADBCompletionUPP NewADBCompletionUPP(ADBCompletionProcPtr userRoutine);
#else
#define NewADBCompletionUPP(userRoutine)                                     \
  (ADBCompletionUPP)                                                         \
      NewRoutineDescriptor((ProcPtr)(userRoutine), uppADBCompletionProcInfo, \
                           GetCurrentArchitecture())
#endif
#endif

  /**
   *  NewADBDeviceDriverUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  ADBDeviceDriverUPP
  NewADBDeviceDriverUPP(ADBDeviceDriverProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppADBDeviceDriverProcInfo = 0x00050802
  }; // register no_return_value Func(1_byte:D0, 1_byte:D1) #ifdef __cplusplus
  inline ADBDeviceDriverUPP
  NewADBDeviceDriverUPP(ADBDeviceDriverProcPtr userRoutine);
#else
#define NewADBDeviceDriverUPP(userRoutine)                                     \
  (ADBDeviceDriverUPP)                                                         \
      NewRoutineDescriptor((ProcPtr)(userRoutine), uppADBDeviceDriverProcInfo, \
                           GetCurrentArchitecture())
#endif
#endif

  /**
   *  NewADBServiceRoutineUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  ADBServiceRoutineUPP
  NewADBServiceRoutineUPP(ADBServiceRoutineProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppADBServiceRoutineProcInfo = 0x0F779802
  }; /* register no_return_value Func(4_bytes:A0, 4_bytes:A1, 4_bytes:A2,
        4_bytes:D0) */
#ifdef __cplusplus
  inline ADBServiceRoutineUPP
  NewADBServiceRoutineUPP(ADBServiceRoutineProcPtr userRoutine)
  {
    return (ADBServiceRoutineUPP)NewRoutineDescriptor(
        (ProcPtr)(userRoutine), uppADBServiceRoutineProcInfo,
        GetCurrentArchitecture());
  }
#else
#define NewADBServiceRoutineUPP(userRoutine)                                \
  (ADBServiceRoutineUPP) NewRoutineDescriptor((ProcPtr)(userRoutine),       \
                                              uppADBServiceRoutineProcInfo, \
                                              GetCurrentArchitecture())
#endif
#endif

  /**
   *  NewADBInitUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  ADBInitUPP
  NewADBInitUPP(ADBInitProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppADBInitProcInfo = 0x00000802
  }; // register no_return_value Func(1_byte:D0) #ifdef __cplusplus
  inline ADBInitUPP NewADBInitUPP(ADBInitProcPtr userRoutine)
  {
    return (ADBInitUPP)NewRoutineDescriptor(
        (ProcPtr)(userRoutine), uppADBInitProcInfo, GetCurrentArchitecture());
  }
#else
#defi // register no_return_value Func(1_byte:D0)
(ADBInitUPP) NewRoutineDescriptor(
    (ProcPtr)(userRoutine), uppADBInitProcInfo, GetCurrentArchitecture())
#endif
#endif

  /**
   *  DisposeADBCompletionUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void DisposeADBCompletionUPP(ADBCompletionUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeADBCompletionUPP(ADBCompletionUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeADBCompletionUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  DisposeADBDeviceDriverUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void DisposeADBDeviceDriverUPP(ADBDeviceDriverUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeADBDeviceDriverUPP(ADBDeviceDriverUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeADBDeviceDriverUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  DisposeADBServiceRoutineUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void DisposeADBServiceRoutineUPP(ADBServiceRoutineUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeADBServiceRoutineUPP(ADBServiceRoutineUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeADBServiceRoutineUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  DisposeADBInitUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void DisposeADBInitUPP(ADBInitUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeADBInitUPP(ADBInitUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeADBInitUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  InvokeADBCompletionUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void InvokeADBCompletionUPP(Ptr buffer, Ptr refCon, long command,
                              ADBCompletionUPP userUPP);
#if !OPAQUE_UPP_TYPES && \
    (!TARGET_OS_MAC || !TARGET_CPU_68K || TARGET_RT_MAC_CFM)
#ifdef __cplusplus
  inline void InvokeADBCompletionUPP(Ptr buffer, Ptr refCon, long command,
                                     ADBCompletionUPP userUPP)
  {
    CALL_THREE_PARAMETER_UPP(userUPP, uppADBCompletionProcInfo, buffer, refCon,
                             command);
  }
#else
#define InvokeADBCompletionUPP(buffer, refCon, command, userUPP)          \
  CALL_THREE_PARAMETER_UPP((userUPP), uppADBCompletionProcInfo, (buffer), \
                           (refCon), (command))
#endif
#endif

/**
 *  InvokeADBDeviceDriverUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter InvokeADBDeviceDriverUPP(__D0, __D1, __A0)
#endif
  void InvokeADBDeviceDriverUPP(SInt8 devAddress, SInt8 devType,
                                ADBDeviceDriverUPP userUPP);
#if !OPAQUE_UPP_TYPES && \
    (!TARGET_OS_MAC || !TARGET_CPU_68K || TARGET_RT_MAC_CFM)
#ifdef __cplusplus
  inline void InvokeADBDeviceDriverUPP(SInt8 devAddress, SInt8 devType,
                                       ADBDeviceDriverUPP userUPP)
  {
    CALL_TWO_PARAMETER_UPP(userUPP, uppADBDeviceDriverProcInfo, devAddress,
                           devType);
  }
#else
#define InvokeADBDeviceDriverUPP(devAddress, devType, userUPP)                \
  CALL_TWO_PARAMETER_UPP((userUPP), uppADBDeviceDriverProcInfo, (devAddress), \
                         (devType))
#endif
#endif

  /**
   *  InvokeADBServiceRoutineUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void InvokeADBServiceRoutineUPP(Ptr buffer, TempADBServiceRoutineUPP completionProc,
                                  Ptr refCon, long command,
                                  ADBServiceRoutineUPP userUPP);
#if !OPAQUE_UPP_TYPES && \
    (!TARGET_OS_MAC || !TARGET_CPU_68K || TARGET_RT_MAC_CFM)
#ifdef __cplusplus
  inline void InvokeADBServiceRoutineUPP(Ptr buffer,
                                         TempADBServiceRoutineUPP completionProc,
                                         Ptr refCon, long command,
                                         ADBServiceRoutineUPP userUPP)
  {
    CALL_FOUR_PARAMETER_UPP(userUPP, uppADBServiceRoutineProcInfo, buffer,
                            completionProc, refCon, command);
  }
#else
#define InvokeADBServiceRoutineUPP(buffer, completionProc, refCon, command,  \
                                   userUPP)                                  \
  CALL_FOUR_PARAMETER_UPP((userUPP), uppADBServiceRoutineProcInfo, (buffer), \
                          (completionProc), (refCon), (command))
#endif
#endif

/**
 *  InvokeADBInitUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter InvokeADBInitUPP(__D0, __A0)
#endif
  void InvokeADBInitUPP(SInt8 callOrder, ADBInitUPP userUPP);
#if !OPAQUE_UPP_TYPES && \
    (!TARGET_OS_MAC || !TARGET_CPU_68K || TARGET_RT_MAC_CFM)
#ifdef __cplusplus
  inline void InvokeADBInitUPP(SInt8 callOrder, ADBInitUPP userUPP)
  {
    CALL_ONE_PARAMETER_UPP(userUPP, uppADBInitProcInfo, callOrder);
  }
#else
#define InvokeADBInitUPP(callOrder, userUPP) \
  CALL_ONE_PARAMETER_UPP((userUPP), uppADBInitProcInfo, (callOrder))
#endif
#endif

#endif // CALL_NOT_IN_CARBON
#if CALL_NOT_IN_CARBON || OLDROUTINENAMES
// support for pre-Carbon UPP routines: New...Proc and Call...Proc #define NewADBCompletionProc(userRoutine) NewADBCompletionUPP(userRoutine)
#define NewADBDeviceDriverProc(userRoutine) NewADBDeviceDriverUPP(userRoutine)
#define NewADBServiceRoutineProc(userRoutine) \
  NewADBServiceRoutineUPP(userRoutine)
#define NewADBInitProc(userRoutine) NewADBInitUPP(userRoutine)
#define CallADBCompletionProc(userRoutine, buffer, refCon, command) \
  Invok // CALL_NOT_IN_CARBON
#define CallADBDeviceDriverProc(userRoutine, devAddress, devType) \
  InvokeADBDeviceDriverUPP(devAddress, devType, userRoutine)
  // support for pre-Carbon UPP routines: New...Proc and Call...Proc
                                  command)                                     \
  InvokeADBServiceRoutineUPP(buffer, completionProc, refCon, command,          \
                             userRoutine)
#define CallADBInitProc(userRoutine, callOrder) \
                                  InvokeADBInitUPP(callOrder, userRoutine)
#endif // CALL_NOT_IN_CARBON
#endif // TARGET_OS_MAC
#if PRAGMA_STRUCT_ALIGN
#pragma options align = reset
#elif PRAGMA_STRUCT_PACKPUSH
#pragma pack(pop)
#elif PRAGMA_STRUCT_PACK
#pragma pack()
#endif

#ifdef // CALL_NOT_IN_CARBON
#pragma import off
#elif P // TARGET_OS_MAC
#pragma import reset
#endif

#ifdef __cplusplus
}
#endif
