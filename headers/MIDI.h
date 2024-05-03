/**
     \file       MIDI.h

    \brief   MIDI Manager Interfaces.

    \introduced_in  System 7.5
    \avaliable_from Universal Interfaces 3.4.1

    \copyright © 1988-2001 by Apple Computer, Inc., all rights reserved

    \ingroup Managers

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __MIDI__
#define __MIDI__

#ifndef __MACERRORS__
#include <MacErrors.h>
#endif

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

  /**
                          * * *  N O T E  * * *

      This file has been updated to include MIDI 2.0 interfaces.

      The MIDI 2.0 interfaces were developed for the classic 68K runtime.
      Since then, Apple has created the PowerPC and CFM 68K runtimes.
      Currently, the extra functions in MIDI 2.0 are not in InterfaceLib
      and thus not callable from PowerPC and CFM 68K runtimes (you'll
      get a linker error).
  */
  enum
  {
    midiMaxNameLen = 31 /**maximum number of characters in port and client names*/
  };

  enum
  {
    /** Time formats */
    midiFormatMSec = 0,      /**milliseconds*/
    midiFormatBeats = 1,     /**beats*/
    midiFormat24fpsBit = 2,  /**24 frames/sec.*/
    midiFormat25fpsBit = 3,  /**25 frames/sec.*/
    midiFormat30fpsDBit = 4, /**30 frames/sec. drop-frame*/
    midiFormat30fpsBit = 5,  /**30 frames/sec.*/
    midiFormat24fpsQF = 6,   /**24 frames/sec. longInt format */
    midiFormat25fpsQF = 7,   /**25 frames/sec. longInt format */
    midiFormat30fpsDQF = 8,  /**30 frames/sec. drop-frame longInt format */
    midiFormat30fpsQF = 9    /**30 frames/sec. longInt format */
  };

  enum
  {
    midiInternalSync = 0, /**internal sync*/
    midiExternalSync = 1  /**external sync*/
  };

  enum
  {
    /** Port types*/
    midiPortTypeTime = 0,    /**time port*/
    midiPortTypeInput = 1,   /**input port*/
    midiPortTypeOutput = 2,  /**output port*/
    midiPortTypeTimeInv = 3, /**invisible time port*/
    midiPortInvisible =
        0x8000,               /**logical OR this to other types to make invisible ports*/
    midiPortTypeMask = 0x0007 /**logical AND with this to convert new port types
                                 to old, i.e. to strip the property bits*/
  };

  enum
  {
    /** OffsetTimes  */
    midiGetEverything =
        0x7FFFFFFF, /**get all packets, regardless of time stamps*/
    midiGetNothing =
        (long)0x80000000,       /**get no packets, regardless of time stamps*/
    midiGetCurrent = 0x00000000 /**get current packets only*/
  };

  /**    MIDI data and messages are passed in MIDIPacket records (see below).
      The first byte of every MIDIPacket contains a set of flags

      bits 0-1    00 = new MIDIPacket, not continued
                       01 = begining of continued MIDIPacket
                       10 = end of continued MIDIPacket
                       11 = continuation
      bits 2-3     reserved

      bits 4-6      000 = packet contains MIDI data

                    001 = packet contains MIDI Manager message

      bit 7         0 = MIDIPacket has valid stamp
                    1 = stamp with current clock
  */
  enum
  {
    midiContMask = 0x03,
    midiNoCont = 0x00,
    midiStartCont = 0x01,
    midiMidCont = 0x03,
    midiEndCont = 0x02,
    midiTypeMask = 0x70,
    midiMsgType = 0x00,
    midiMgrType = 0x10,
    midiTimeStampMask = 0x80,
    midiTimeStampCurrent = 0x80,
    midiTimeStampValid = 0x00
  };

  enum
  {
    /** MIDIPacket command words (the first word in the data field for midiMgrType
       messages) */
    midiOverflowErr = 0x0001,
    midiSCCErr = 0x0002,
    midiPacketErr =
        0x0003, /**all command words less than this value are error indicators*/
    midiMaxErr = 0x00FF
  };

  enum
  {
    /** Valid results to be returned by readHooks */
    midiKeepPacket = 0,
    midiMorePacket = 1,
    midiNoMorePacket = 2,
    midiHoldPacket = 3
  };

  enum
  {
    /** Driver calls */
    midiOpenDriver = 1,
    midiCloseDriver = 2
  };

  enum
  {
    mdvrAbortNotesOff = 0, /**abort previous mdvrNotesOff request*/
    mdvrChanNotesOff = 1,  /**generate channel note off messages*/
    mdvrAllNotesOff = 2    /**generate all note off messages*/
  };

  enum
  {
    mdvrStopOut = 0, /**stop calling MDVROut temporarily*/
    mdvrStartOut = 1 /**resume calling MDVROut*/
  };

  struct MIDIPacket
  {
    UInt8 flags;
    UInt8 len;
    long tStamp;
    UInt8 data[249];
  };
  typedef struct MIDIPacket MIDIPacket;
  typedef MIDIPacket *MIDIPacketPtr;
  typedef CALLBACK_API(short, MIDIReadHookProcPtr)(MIDIPacketPtr myPacket,
                                                   long myRefCon);
  typedef CALLBACK_API(void, MIDITimeProcPtr)(long curTime, long myRefCon);
  typedef CALLBACK_API(void,
                       MIDIConnectionProcPtr)(short refnum, long refcon,
                                              short portType, OSType clientID,
                                              OSType portID, Boolean connect,
                                              short direction);
  typedef CALLBACK_API(long, MDVRCommProcPtr)(short refnum, short request,
                                              long refCon);
  typedef CALLBACK_API(void, MDVRTimeCodeProcPtr)(short refnum, short newFormat,
                                                  long refCon);
  typedef CALLBACK_API(void, MDVRReadProcPtr)(char *midiChars, short length,
                                              long refCon);
  typedef STACK_UPP_TYPE(MIDIReadHookProcPtr) MIDIReadHookUPP;
  typedef STACK_UPP_TYPE(MIDITimeProcPtr) MIDITimeUPP;
  typedef STACK_UPP_TYPE(MIDIConnectionProcPtr) MIDIConnectionUPP;
  typedef STACK_UPP_TYPE(MDVRCommProcPtr) MDVRCommUPP;
  typedef STACK_UPP_TYPE(MDVRTimeCodeProcPtr) MDVRTimeCodeUPP;
  typedef STACK_UPP_TYPE(MDVRReadProcPtr) MDVRReadUPP;
  struct MIDIClkInfo
  {
    short syncType; /**synchronization external/internal*/
    long curTime;   /**current value of port's clock*/
    short format;   /**time code format*/
  };
  typedef struct MIDIClkInfo MIDIClkInfo;
  struct MIDIIDRec
  {
    OSType clientID;
    OSType portID;
  };
  typedef struct MIDIIDRec MIDIIDRec;
  struct MIDIPortInfo
  {
    short portType;     /**type of port*/
    MIDIIDRec timeBase; /**MIDIIDRec for time base*/
    short numConnects;  /**number of connections*/
    MIDIIDRec cList[1]; /**ARRAY [1..numConnects] of MIDIIDRec*/
  };
  typedef struct MIDIPortInfo MIDIPortInfo;
  typedef MIDIPortInfo *MIDIPortInfoPtr;
  typedef MIDIPortInfoPtr *MIDIPortInfoHdl;
  typedef MIDIPortInfoPtr *MIDIPortInfoHandle;
  struct MIDIPortParams
  {
    OSType portID;            /**ID of port, unique within client*/
    short portType;           /**Type of port - input, output, time, etc.*/
    short timeBase;           /**refnum of time base, 0 if none*/
    long offsetTime;          /**offset for current time stamps*/
    MIDIReadHookUPP readHook; /**routine to call when input data is valid*/
    long refCon;              /**refcon for port (for client use)*/
    MIDIClkInfo initClock;    /**initial settings for a time base*/
    Str255 name;              /**name of the port, This is a real live string, not a ptr.*/
  };
  typedef struct MIDIPortParams MIDIPortParams;
  typedef MIDIPortParams *MIDIPortParamsPtr;
  struct MIDIIDList
  {
    short numIDs;
    OSType list[1];
  };
  typedef struct MIDIIDList MIDIIDList;
  typedef MIDIIDList *MIDIIDListPtr;
  typedef MIDIIDListPtr *MIDIIDListHdl;
  typedef MIDIIDListPtr *MIDIIDListHandle;
  /** MDVR Control structs*/
  struct MDVRInCtlRec
  {
    short timeCodeClock;  /**refnum of time base for time code*/
    short timeCodeFormat; /**format of time code output*/
    MDVRReadUPP readProc; /**proc to call with intput characters*/
    MDVRCommUPP commProc; /**proc to call for handshaking*/
    long refCon;          /**refCon passed to readProc, commProc*/
  };
  typedef struct MDVRInCtlRec MDVRInCtlRec;
  typedef MDVRInCtlRec *MDVRInCtlPtr;
  struct MDVROutCtlRec
  {
    short timeCodeClock;          /**time base driven by time code*/
    short timeCodeFormat;         /**format of time code to listen to*/
    MDVRTimeCodeUPP timeCodeProc; /**proc called on time code fmt change*/
    MDVRCommUPP commProc;         /**proc called for handshaking*/
    long refCon;                  /**refCon passed to timeCodeProc*/
    Boolean timeCodeFilter;       /**filter time code if true*/
    UInt8 padding;                /**unused pad byte*/
    long midiMsgTicks;            /**value of Ticks when MIDI msg rcvd*/
    long timeCodeTicks;           /**value of Ticks when time code rcvd*/
  };
  typedef struct MDVROutCtlRec MDVROutCtlRec;
  typedef MDVROutCtlRec *MDVROutCtlPtr;
  typedef void *MDVRPtr;
#if CALL_NOT_IN_CARBON
  /**
   *  MIDIVersion()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  NumVersion
  MIDIVersion(void);

  /**
   *  MIDISignIn()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  MIDISignIn(OSType clientID, long refCon, Handle icon, ConstStr255Param name);

  /**
   *  MIDISignOut()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  MIDISignOut(OSType clientID);

  /**
   *  MIDIGetClients()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  MIDIIDListHandle
  MIDIGetClients(void);

  /**
   *  MIDIGetClientName()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  MIDIGetClientName(OSType clientID, Str255 name);

  /**
   *  MIDISetClientName()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  MIDISetClientName(OSType clientID, ConstStr255Param name);

  /**
   *  MIDIGetPorts()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  MIDIIDListHandle
  MIDIGetPorts(OSType clientID);

  /**
   *  MIDIAddPort()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  MIDIAddPort(OSType clientID, short BufSize, short *refnum,
              MIDIPortParamsPtr init);

  /**
   *  MIDIGetPortInfo()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  MIDIPortInfoHandle
  MIDIGetPortInfo(OSType clientID, OSType portID);

  /**
   *  MIDIConnectData()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  MIDIConnectData(OSType srcClID, OSType srcPortID, OSType dstClID,
                  OSType dstPortID);

  /**
   *  MIDIUnConnectData()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  MIDIUnConnectData(OSType srcClID, OSType srcPortID, OSType dstClID,
                    OSType dstPortID);

  /**
   *  MIDIConnectTime()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  MIDIConnectTime(OSType srcClID, OSType srcPortID, OSType dstClID,
                  OSType dstPortID);

  /**
   *  MIDIUnConnectTime()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  MIDIUnConnectTime(OSType srcClID, OSType srcPortID, OSType dstClID,
                    OSType dstPortID);

  /**
   *  MIDIFlush()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  MIDIFlush(short refnum);

  /**
   *  MIDIGetReadHook()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  ProcPtr
  MIDIGetReadHook(short refnum);

  /**
   *  MIDISetReadHook()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  MIDISetReadHook(short refnum, ProcPtr hook);

  /**
   *  MIDIGetPortName()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  MIDIGetPortName(OSType clientID, OSType portID, Str255 name);

  /**
   *  MIDISetPortName()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  MIDISetPortName(OSType clientID, OSType portID, ConstStr255Param name);

  /**
   *  MIDIWakeUp()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  MIDIWakeUp(short refnum, long time, long period, MIDITimeUPP timeProc);

  /**
   *  MIDIRemovePort()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  MIDIRemovePort(short refnum);

  /**
   *  MIDIGetSync()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  short
  MIDIGetSync(short refnum);

  /**
   *  MIDISetSync()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  MIDISetSync(short refnum, short sync);

  /**
   *  MIDIGetCurTime()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  long
  MIDIGetCurTime(short refnum);

  /**
   *  MIDISetCurTime()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  MIDISetCurTime(short refnum, long time);

  /**
   *  MIDIStartTime()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  MIDIStartTime(short refnum);

  /**
   *  MIDIStopTime()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  MIDIStopTime(short refnum);

  /**
   *  MIDIPoll()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  MIDIPoll(short refnum, long offsetTime);

  /**
   *  MIDIWritePacket()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  MIDIWritePacket(short refnum, MIDIPacketPtr packet);

  /**
   *  MIDIWorldChanged()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  Boolean
  MIDIWorldChanged(OSType clientID);

  /**
   *  MIDIGetOffsetTime()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  long
  MIDIGetOffsetTime(short refnum);

  /**
   *  MIDISetOffsetTime()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  MIDISetOffsetTime(short refnum, long offsetTime);

  /**
   *  MIDIConvertTime()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  long
  MIDIConvertTime(short srcFormat, short dstFormat, long time);

  /**
   *  MIDIGetRefCon()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  long
  MIDIGetRefCon(short refnum);

  /**
   *  MIDISetRefCon()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  MIDISetRefCon(short refnum, long refCon);

  /**
   *  MIDIGetClRefCon()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  long
  MIDIGetClRefCon(OSType clientID);

  /**
   *  MIDISetClRefCon()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  MIDISetClRefCon(OSType clientID, long refCon);

  /**
   *  MIDIGetTCFormat()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  short
  MIDIGetTCFormat(short refnum);

  /**
   *  MIDISetTCFormat()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  MIDISetTCFormat(short refnum, short format);

  /**
   *  MIDISetRunRate()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  MIDISetRunRate(short refnum, short rate, long time);

  /**
   *  MIDIGetClientIcon()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  Handle
  MIDIGetClientIcon(OSType clientID);

  /**
   *  MIDICallAddress()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  ProcPtr
  MIDICallAddress(short callNum);

  /**
   *  MIDISetConnectionProc()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  MIDISetConnectionProc(short refNum, ProcPtr connectionProc, long refCon);

  /**
   *  MIDIGetConnectionProc()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  MIDIGetConnectionProc(short refnum, ProcPtr *connectionProc, long *refCon);

  /**
   *  MIDIDiscardPacket()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  MIDIDiscardPacket(short refnum, MIDIPacketPtr packet);

  /**
   *  MDVRSignIn()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  MDVRSignIn(OSType clientID, long refCon, Handle icon, Str255 name);

  /**
   *  MDVRSignOut()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  MDVRSignOut(OSType clientID);

  /**
   *  MDVROpen()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  MDVRPtr
  MDVROpen(short portType, short refnum);

  /**
   *  MDVRClose()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  MDVRClose(MDVRPtr driverPtr);

  /**
   *  MDVRControlIn()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  MDVRControlIn(MDVRPtr portPtr, MDVRInCtlPtr inputCtl);

  /**
   *  MDVRControlOut()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  MDVRControlOut(MDVRPtr portPtr, MDVROutCtlPtr outputCtl);

  /**
   *  MDVRIn()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  MDVRIn(MDVRPtr portPtr);

  /**
   *  MDVROut()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  MDVROut(MDVRPtr portPtr, char *dataPtr, short length);

  /**
   *  MDVRNotesOff()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  MDVRNotesOff(MDVRPtr portPtr, short mode);

#endif /** CALL_NOT_IN_CARBON */

#if CALL_NOT_IN_CARBON
  /**
   *  NewMIDIReadHookUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  MIDIReadHookUPP
  NewMIDIReadHookUPP(MIDIReadHookProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppMIDIReadHookProcInfo = 0x000003E0
  }; /** pascal 2_bytes Func(4_bytes, 4_bytes) */
#ifdef __cplusplus
  inline MIDIReadHookUPP NewMIDIReadHookUPP(MIDIReadHookProcPtr userRoutine)
  {
    return (MIDIReadHookUPP)NewRoutineDescriptor((ProcPtr)(userRoutine),
                                                 uppMIDIReadHookProcInfo,
                                                 GetCurrentArchitecture());
  }
#else
#define NewMIDIReadHookUPP(userRoutine)                                     \
  (MIDIReadHookUPP)                                                         \
      NewRoutineDescriptor((ProcPtr)(userRoutine), uppMIDIReadHookProcInfo, \
                           GetCurrentArchitecture())
#endif
#endif

  /**
   *  NewMIDITimeUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  MIDITimeUPP
  NewMIDITimeUPP(MIDITimeProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppMIDITimeProcInfo = 0x000003C0
  }; /** pascal no_return_value Func(4_bytes, 4_bytes) */
#ifdef __cplusplus
  inline MIDITimeUPP NewMIDITimeUPP(MIDITimeProcPtr userRoutine)
  {
    return (MIDITimeUPP)NewRoutineDescriptor(
        (ProcPtr)(userRoutine), uppMIDITimeProcInfo, GetCurrentArchitecture());
  }
#else
#define NewMIDITimeUPP(userRoutine)   \
  (MIDITimeUPP) NewRoutineDescriptor( \
      (ProcPtr)(userRoutine), uppMIDITimeProcInfo, GetCurrentArchitecture())
#endif
#endif

  /**
   *  NewMIDIConnectionUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  MIDIConnectionUPP
  NewMIDIConnectionUPP(MIDIConnectionProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppMIDIConnectionProcInfo = 0x0009FB80
  }; /** pascal no_return_value Func(2_bytes, 4_bytes, 2_bytes, 4_bytes, 4_bytes,
        1_byte, 2_bytes) */
#ifdef __cplusplus
  inline MIDIConnectionUPP
  NewMIDIConnectionUPP(MIDIConnectionProcPtr userRoutine)
  {
    return (MIDIConnectionUPP)NewRoutineDescriptor((ProcPtr)(userRoutine),
                                                   uppMIDIConnectionProcInfo,
                                                   GetCurrentArchitecture());
  }
#else
#define NewMIDIConnectionUPP(userRoutine)                                     \
  (MIDIConnectionUPP)                                                         \
      NewRoutineDescriptor((ProcPtr)(userRoutine), uppMIDIConnectionProcInfo, \
                           GetCurrentArchitecture())
#endif
#endif

  /**
   *  NewMDVRCommUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  MDVRCommUPP
  NewMDVRCommUPP(MDVRCommProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppMDVRCommProcInfo = 0x00000EB0
  }; /** pascal 4_bytes Func(2_bytes, 2_bytes, 4_bytes) */
#ifdef __cplusplus
  inline MDVRCommUPP NewMDVRCommUPP(MDVRCommProcPtr userRoutine)
  {
    return (MDVRCommUPP)NewRoutineDescriptor(
        (ProcPtr)(userRoutine), uppMDVRCommProcInfo, GetCurrentArchitecture());
  }
#else
#define NewMDVRCommUPP(userRoutine)   \
  (MDVRCommUPP) NewRoutineDescriptor( \
      (ProcPtr)(userRoutine), uppMDVRCommProcInfo, GetCurrentArchitecture())
#endif
#endif

  /**
   *  NewMDVRTimeCodeUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  MDVRTimeCodeUPP
  NewMDVRTimeCodeUPP(MDVRTimeCodeProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppMDVRTimeCodeProcInfo = 0x00000E80
  }; /** pascal no_return_value Func(2_bytes, 2_bytes, 4_bytes) */
#ifdef __cplusplus
  inline MDVRTimeCodeUPP NewMDVRTimeCodeUPP(MDVRTimeCodeProcPtr userRoutine)
  {
    return (MDVRTimeCodeUPP)NewRoutineDescriptor((ProcPtr)(userRoutine),
                                                 uppMDVRTimeCodeProcInfo,
                                                 GetCurrentArchitecture());
  }
#else
#define NewMDVRTimeCodeUPP(userRoutine)                                     \
  (MDVRTimeCodeUPP)                                                         \
      NewRoutineDescriptor((ProcPtr)(userRoutine), uppMDVRTimeCodeProcInfo, \
                           GetCurrentArchitecture())
#endif
#endif

  /**
   *  NewMDVRReadUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  MDVRReadUPP
  NewMDVRReadUPP(MDVRReadProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppMDVRReadProcInfo = 0x00000EC0
  }; /** pascal no_return_value Func(4_bytes, 2_bytes, 4_bytes) */
#ifdef __cplusplus
  inline MDVRReadUPP NewMDVRReadUPP(MDVRReadProcPtr userRoutine)
  {
    return (MDVRReadUPP)NewRoutineDescriptor(
        (ProcPtr)(userRoutine), uppMDVRReadProcInfo, GetCurrentArchitecture());
  }
#else
#define NewMDVRReadUPP(userRoutine)   \
  (MDVRReadUPP) NewRoutineDescriptor( \
      (ProcPtr)(userRoutine), uppMDVRReadProcInfo, GetCurrentArchitecture())
#endif
#endif

  /**
   *  DisposeMIDIReadHookUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  DisposeMIDIReadHookUPP(MIDIReadHookUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeMIDIReadHookUPP(MIDIReadHookUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeMIDIReadHookUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  DisposeMIDITimeUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  DisposeMIDITimeUPP(MIDITimeUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeMIDITimeUPP(MIDITimeUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeMIDITimeUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  DisposeMIDIConnectionUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  DisposeMIDIConnectionUPP(MIDIConnectionUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeMIDIConnectionUPP(MIDIConnectionUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeMIDIConnectionUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  DisposeMDVRCommUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  DisposeMDVRCommUPP(MDVRCommUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeMDVRCommUPP(MDVRCommUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeMDVRCommUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  DisposeMDVRTimeCodeUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  DisposeMDVRTimeCodeUPP(MDVRTimeCodeUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeMDVRTimeCodeUPP(MDVRTimeCodeUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeMDVRTimeCodeUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  DisposeMDVRReadUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  DisposeMDVRReadUPP(MDVRReadUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeMDVRReadUPP(MDVRReadUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeMDVRReadUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  InvokeMIDIReadHookUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  short
  InvokeMIDIReadHookUPP(MIDIPacketPtr myPacket, long myRefCon,
                        MIDIReadHookUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline short InvokeMIDIReadHookUPP(MIDIPacketPtr myPacket, long myRefCon,
                                     MIDIReadHookUPP userUPP)
  {
    return (short)CALL_TWO_PARAMETER_UPP(userUPP, uppMIDIReadHookProcInfo,
                                         myPacket, myRefCon);
  }
#else
#define InvokeMIDIReadHookUPP(myPacket, myRefCon, userUPP)          \
  (short)CALL_TWO_PARAMETER_UPP((userUPP), uppMIDIReadHookProcInfo, \
                                (myPacket), (myRefCon))
#endif
#endif

  /**
   *  InvokeMIDITimeUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  InvokeMIDITimeUPP(long curTime, long myRefCon, MIDITimeUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void InvokeMIDITimeUPP(long curTime, long myRefCon,
                                MIDITimeUPP userUPP)
  {
    CALL_TWO_PARAMETER_UPP(userUPP, uppMIDITimeProcInfo, curTime, myRefCon);
  }
#else
#define InvokeMIDITimeUPP(curTime, myRefCon, userUPP) \
  CALL_TWO_PARAMETER_UPP((userUPP), uppMIDITimeProcInfo, (curTime), (myRefCon))
#endif
#endif

  /**
   *  InvokeMIDIConnectionUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  InvokeMIDIConnectionUPP(short refnum, long refcon, short portType,
                          OSType clientID, OSType portID, Boolean connect,
                          short direction, MIDIConnectionUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void InvokeMIDIConnectionUPP(short refnum, long refcon, short portType,
                                      OSType clientID, OSType portID,
                                      Boolean connect, short direction,
                                      MIDIConnectionUPP userUPP)
  {
    CALL_SEVEN_PARAMETER_UPP(userUPP, uppMIDIConnectionProcInfo, refnum, refcon,
                             portType, clientID, portID, connect, direction);
  }
#else
#define InvokeMIDIConnectionUPP(refnum, refcon, portType, clientID, portID, \
                                connect, direction, userUPP)                \
  CALL_SEVEN_PARAMETER_UPP((userUPP), uppMIDIConnectionProcInfo, (refnum),  \
                           (refcon), (portType), (clientID), (portID),      \
                           (connect), (direction))
#endif
#endif

  /**
   *  InvokeMDVRCommUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  long
  InvokeMDVRCommUPP(short refnum, short request, long refCon,
                    MDVRCommUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline long InvokeMDVRCommUPP(short refnum, short request, long refCon,
                                MDVRCommUPP userUPP)
  {
    return (long)CALL_THREE_PARAMETER_UPP(userUPP, uppMDVRCommProcInfo, refnum,
                                          request, refCon);
  }
#else
#define InvokeMDVRCommUPP(refnum, request, refCon, userUPP)                \
  (long)CALL_THREE_PARAMETER_UPP((userUPP), uppMDVRCommProcInfo, (refnum), \
                                 (request), (refCon))
#endif
#endif

  /**
   *  InvokeMDVRTimeCodeUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  InvokeMDVRTimeCodeUPP(short refnum, short newFormat, long refCon,
                        MDVRTimeCodeUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void InvokeMDVRTimeCodeUPP(short refnum, short newFormat, long refCon,
                                    MDVRTimeCodeUPP userUPP)
  {
    CALL_THREE_PARAMETER_UPP(userUPP, uppMDVRTimeCodeProcInfo, refnum, newFormat,
                             refCon);
  }
#else
#define InvokeMDVRTimeCodeUPP(refnum, newFormat, refCon, userUPP)        \
  CALL_THREE_PARAMETER_UPP((userUPP), uppMDVRTimeCodeProcInfo, (refnum), \
                           (newFormat), (refCon))
#endif
#endif

  /**
   *  InvokeMDVRReadUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  InvokeMDVRReadUPP(char *midiChars, short length, long refCon,
                    MDVRReadUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void InvokeMDVRReadUPP(char *midiChars, short length, long refCon,
                                MDVRReadUPP userUPP)
  {
    CALL_THREE_PARAMETER_UPP(userUPP, uppMDVRReadProcInfo, midiChars, length,
                             refCon);
  }
#else
#define InvokeMDVRReadUPP(midiChars, length, refCon, userUPP)           \
  CALL_THREE_PARAMETER_UPP((userUPP), uppMDVRReadProcInfo, (midiChars), \
                           (length), (refCon))
#endif
#endif

#endif /** CALL_NOT_IN_CARBON */

#if CALL_NOT_IN_CARBON || OLDROUTINENAMES
/** support for pre-Carbon UPP routines: New...Proc and Call...Proc */
#define NewMIDIReadHookProc(userRoutine) NewMIDIReadHookUPP(userRoutine)
#define NewMIDITimeProc(userRoutine) NewMIDITimeUPP(userRoutine)
#define NewMIDIConnectionProc(userRoutine) NewMIDIConnectionUPP(userRoutine)
#define NewMDVRCommProc(userRoutine) NewMDVRCommUPP(userRoutine)
#define NewMDVRTimeCodeProc(userRoutine) NewMDVRTimeCodeUPP(userRoutine)
#define NewMDVRReadProc(userRoutine) NewMDVRReadUPP(userRoutine)
#define CallMIDIReadHookProc(userRoutine, myPacket, myRefCon) \
  InvokeMIDIReadHookUPP(myPacket, myRefCon, userRoutine)
#define CallMIDITimeProc(userRoutine, curTime, myRefCon) \
  InvokeMIDITimeUPP(curTime, myRefCon, userRoutine)
#define CallMIDIConnectionProc(userRoutine, refnum, refcon, portType,          \
                               clientID, portID, connect, direction)           \
  InvokeMIDIConnectionUPP(refnum, refcon, portType, clientID, portID, connect, \
                          direction, userRoutine)
#define CallMDVRCommProc(userRoutine, refnum, request, refCon) \
  InvokeMDVRCommUPP(refnum, request, refCon, userRoutine)
#define CallMDVRTimeCodeProc(userRoutine, refnum, newFormat, refCon) \
  InvokeMDVRTimeCodeUPP(refnum, newFormat, refCon, userRoutine)
#define CallMDVRReadProc(userRoutine, midiChars, length, refCon) \
  InvokeMDVRReadUPP(midiChars, length, refCon, userRoutine)
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

#endif /** __MIDI__ */
