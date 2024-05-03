/**
     \file       Slots.h

    \brief   Slot Manager Interfaces.

    \introduced_in  System 7.5
    \avaliable_from Universal Interfaces 3.4.1

    \copyright © 1986-2001 by Apple Computer, Inc., all rights reserved

    \ingroup Hardware

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __SLOTS__
#define __SLOTS__

#ifndef __MACTYPES__
#include <MacTypes.h>
#endif

#ifndef __EVENTS__
#include <Events.h>
#endif

#ifndef __FILES__
#include <Files.h>
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

  enum
  {
    fCardIsChanged =
        1, /**Card is Changed field in StatusFlags field of sInfoArray*/
    fCkForSame =
        0, /**For SearchSRT. Flag to check for SAME sResource in the table. */
    fCkForNext =
        1,         /**For SearchSRT. Flag to check for NEXT sResource in the table. */
    fWarmStart = 2 /**If this bit is set then warm start else cold start.*/
  };

  enum
  {
    stateNil = 0,      /**State*/
    stateSDMInit = 1,  /**:Slot declaration manager Init*/
    statePRAMInit = 2, /**:sPRAM record init*/
    statePInit = 3,    /**:Primary init*/
    stateSInit = 4     /**:Secondary init*/
  };

  enum
  {
    /** flags for spParamData */
    fall = 0,     /** bit 0: set=search enabled/disabled sRsrc's */
    foneslot = 1, /**    1: set=search sRsrc's in given slot only */
    fnext = 2     /**    2: set=search for next sRsrc */
  };

  enum
  {
    /** Misc masks */
    catMask = 0x08,    /** sets spCategory field of spTBMask (bit 3) */
    cTypeMask = 0x04,  /** sets spCType    field of spTBMask (bit 2) */
    drvrSWMask = 0x02, /** sets spDrvrSW   field of spTBMask (bit 1) */
    drvrHWMask = 0x01  /** sets spDrvrHW    field of spTBMask (bit 0) */
  };

  typedef CALLBACK_API_REGISTER68K(short, SlotIntServiceProcPtr,
                                   (long sqParameter));
  typedef REGISTER_UPP_TYPE(SlotIntServiceProcPtr) SlotIntServiceUPP;
#if CALL_NOT_IN_CARBON
  /**
   *  NewSlotIntServiceUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  SlotIntServiceUPP
  NewSlotIntServiceUPP(SlotIntServiceProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppSlotIntServiceProcInfo = 0x0000B822
  }; /** register 2_bytes:D0 Func(4_bytes:A1) */
#ifdef __cplusplus
  inline SlotIntServiceUPP
  NewSlotIntServiceUPP(SlotIntServiceProcPtr userRoutine)
  {
    return (SlotIntServiceUPP)NewRoutineDescriptor((ProcPtr)(userRoutine),
                                                   uppSlotIntServiceProcInfo,
                                                   GetCurrentArchitecture());
  }
#else
#define NewSlotIntServiceUPP(userRoutine)                                     \
  (SlotIntServiceUPP)                                                         \
      NewRoutineDescriptor((ProcPtr)(userRoutine), uppSlotIntServiceProcInfo, \
                           GetCurrentArchitecture())
#endif
#endif

  /**
   *  DisposeSlotIntServiceUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  DisposeSlotIntServiceUPP(SlotIntServiceUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeSlotIntServiceUPP(SlotIntServiceUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeSlotIntServiceUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

/**
 *  InvokeSlotIntServiceUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 InvokeSlotIntServiceUPP(__A1, __A0)
#endif
  short
  InvokeSlotIntServiceUPP(long sqParameter, SlotIntServiceUPP userUPP);
#if !OPAQUE_UPP_TYPES && \
    (!TARGET_OS_MAC || !TARGET_CPU_68K || TARGET_RT_MAC_CFM)
#ifdef __cplusplus
  inline short InvokeSlotIntServiceUPP(long sqParameter,
                                       SlotIntServiceUPP userUPP)
  {
    return (short)CALL_ONE_PARAMETER_UPP(userUPP, uppSlotIntServiceProcInfo,
                                         sqParameter);
  }
#else
#define InvokeSlotIntServiceUPP(sqParameter, userUPP)                 \
  (short)CALL_ONE_PARAMETER_UPP((userUPP), uppSlotIntServiceProcInfo, \
                                (sqParameter))
#endif
#endif

#endif /** CALL_NOT_IN_CARBON */

#if CALL_NOT_IN_CARBON || OLDROUTINENAMES
/** support for pre-Carbon UPP routines: New...Proc and Call...Proc */
#define NewSlotIntServiceProc(userRoutine) NewSlotIntServiceUPP(userRoutine)
#define CallSlotIntServiceProc(userRoutine, sqParameter) \
  InvokeSlotIntServiceUPP(sqParameter, userRoutine)
#endif /** CALL_NOT_IN_CARBON */

  struct SlotIntQElement
  {
    Ptr sqLink;               /**ptr to next element*/
    short sqType;             /**queue type ID for validity*/
    short sqPrio;             /**priority*/
    SlotIntServiceUPP sqAddr; /**interrupt service routine*/
    long sqParm;              /**optional A1 parameter*/
  };
  typedef struct SlotIntQElement SlotIntQElement;
  typedef SlotIntQElement *SQElemPtr;
  struct SpBlock
  {
    long spResult;      /**FUNCTION Result*/
    Ptr spsPointer;     /**structure pointer*/
    long spSize;        /**size of structure*/
    long spOffsetData;  /**offset/data field used by sOffsetData*/
    Ptr spIOFileName;   /**ptr to IOFile name for sDisDrvrName*/
    Ptr spsExecPBlk;    /**pointer to sExec parameter block.*/
    long spParamData;   /**misc parameter data (formerly spStackPtr).*/
    long spMisc;        /**misc field for SDM.*/
    long spReserved;    /**reserved for future expansion*/
    short spIOReserved; /**Reserved field of Slot Resource Table*/
    short spRefNum;     /**RefNum*/
    short spCategory;   /**sType: Category*/
    short spCType;      /**Type*/
    short spDrvrSW;     /**DrvrSW*/
    short spDrvrHW;     /**DrvrHW*/
    SInt8 spTBMask;     /**type bit mask bits 0..3 mask words 0..3*/
    SInt8 spSlot;       /**slot number*/
    SInt8 spID;         /**structure ID*/
    SInt8 spExtDev;     /**ID of the external device*/
    SInt8 spHwDev;      /**Id of the hardware device.*/
    SInt8 spByteLanes;  /**bytelanes from card ROM format block*/
    SInt8 spFlags;      /**standard flags*/
    SInt8 spKey;        /**Internal use only*/
  };
  typedef struct SpBlock SpBlock;
  typedef SpBlock *SpBlockPtr;
  struct SInfoRecord
  {
    Ptr siDirPtr;         /**Pointer to directory*/
    short siInitStatusA;  /**initialization E*/
    short siInitStatusV;  /**status returned by vendor init code*/
    SInt8 siState;        /**initialization state*/
    SInt8 siCPUByteLanes; /**0=[d0..d7] 1=[d8..d15]*/
    SInt8 siTopOfROM;     /**Top of ROM= $FssFFFFx: x is TopOfROM*/
    SInt8 siStatusFlags;  /**bit 0 - card is changed*/
    short siTOConst;      /**Time Out C for BusErr*/
    SInt8 siReserved[2];  /**reserved*/
    Ptr siROMAddr;        /** addr of top of ROM */
    SInt8 siSlot;         /** slot number */
    SInt8 siPadding[3];   /** reserved */
  };
  typedef struct SInfoRecord SInfoRecord;
  typedef SInfoRecord *SInfoRecPtr;
  struct SDMRecord
  {
    ProcPtr sdBEVSave;    /**Save old BusErr vector*/
    ProcPtr sdBusErrProc; /**Go here to determine if it is a BusErr*/
    ProcPtr sdErrorEntry; /**Go here if BusErrProc finds real BusErr*/
    long sdReserved;      /**Reserved*/
  };
  typedef struct SDMRecord SDMRecord;
  struct FHeaderRec
  {
    long fhDirOffset;  /**offset to directory*/
    long fhLength;     /**length of ROM*/
    long fhCRC;        /**CRC*/
    SInt8 fhROMRev;    /**revision of ROM*/
    SInt8 fhFormat;    /**format - 2*/
    long fhTstPat;     /**test pattern*/
    SInt8 fhReserved;  /**reserved*/
    SInt8 fhByteLanes; /**ByteLanes*/
  };
  typedef struct FHeaderRec FHeaderRec;
  typedef FHeaderRec *FHeaderRecPtr;
  /**

      Extended Format header block  -  extended declaration ROM format header for
     super sRsrc directories.    <H2><SM0>

  */

  struct XFHeaderRec
  {
    long fhXSuperInit;  /**Offset to SuperInit SExecBlock  <fhFormat,offset>*/
    long fhXSDirOffset; /**Offset to SuperDirectory         <$FE,offset>*/
    long fhXEOL;        /**Psuedo end-of-list          <$FF,nil>*/
    long fhXSTstPat;    /**TestPattern*/
    long fhXDirOffset;  /**Offset to (minimal) directory*/
    long fhXLength;     /**Length of ROM*/
    long fhXCRC;        /**CRC*/
    SInt8 fhXROMRev;    /**Revision of ROM*/
    SInt8 fhXFormat;    /**Format-2*/
    long fhXTstPat;     /**TestPattern*/
    SInt8 fhXReserved;  /**Reserved*/
    SInt8 fhXByteLanes; /**ByteLanes*/
  };
  typedef struct XFHeaderRec XFHeaderRec;
  typedef XFHeaderRec *XFHeaderRecPtr;
  struct SEBlock
  {
    UInt8 seSlot;       /**Slot number.*/
    UInt8 sesRsrcId;    /**sResource Id.*/
    short seStatus;     /**Status of code executed by sExec.*/
    UInt8 seFlags;      /**Flags*/
    UInt8 seFiller0;    /**Filler, must be SignedByte to align on odd boundry*/
    UInt8 seFiller1;    /**Filler*/
    UInt8 seFiller2;    /**Filler*/
    long seResult;      /**Result of sLoad.*/
    long seIOFileName;  /**Pointer to IOFile name.*/
    UInt8 seDevice;     /**Which device to read from.*/
    UInt8 sePartition;  /**The partition.*/
    UInt8 seOSType;     /**Type of OS.*/
    UInt8 seReserved;   /**Reserved field.*/
    UInt8 seRefNum;     /**RefNum of the driver.*/
    UInt8 seNumDevices; /** Number of devices to load.*/
    UInt8 seBootState;  /**State of StartBoot code.*/
    SInt8 filler;
  };
  typedef struct SEBlock SEBlock;
/**  Principle  */
#if CALL_NOT_IN_CARBON

  /**
  \brief Return an ID byte

  <pre>SReadByte returns an 8-bit value identified by spID.
spBlkPtr is the address of a 56-byte Slot Parameter Block structure.
The relevant fields are as follows:
Out-In Name Type SizeOffsetDescription
←spResult long 40FUNCTION result
→spsPointer Ptr 44Structure pointer
→spID char 150sResource list ID
Other parameters affected are:
spsOffsetData long 412Offset/data field
spByteLanes  char 153ByteLanes from format block in card ROM
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
smEmptySlot (-300) No card in slot.
smCRCFail (-301) CRC check failed.
smFormatErr (-302) FHeader format is not Apple's
smRevisionErr (-303) The revision of the card's declaration ROM is wrong.
smNoDir (-304) Directory offset is NIL
smNosInfoArray (-306) The SDM could not allocate memory for the sInfo
array.
smResrvErr (-307) A reserved field of the declaration ROM was used.
smUnExBusErr (-308) An unexpected bus error occurred.
smBLFieldBad (-309) A valid ByteLanes field was not found.
smDisposePErr (-312) An error occurred during execution of DisposPointer.
smNoBoardSRsrc (-313) There is no board sResource.
smGetPRErr (-314) Error during execution of sGetPRAMRec.
smNoBoardId (-315) There is no board ID.
smInitStatVErr (-316) The InitStatus_V field was negative after Primary or
Secondary Init.
smInitTblVErr (-317) Error while trying to initialize the sResource Table.
smNoJmpTbl (-318) Slot Manager jump table could not be created
smBadBoardId (-319) Board ID was wrong; reinit the PRAM record
</pre>
* \note <pre>The trap macro SReadByte finds a data structure in slot card firmware.
It returns in spResult an 8-bit value identified by spID from the sResource
list pointed to by spsPointer . This routines' low-order byte can return
non-fatal error reports, which will be one of the following:
smBadRefId (-330) Reference ID was not found in the given sResource
list.
smBadsList (-331) The IDs in the sResource list are not in ascending
order.
smReservedErr (-332) A reserved field was not zero.
smCodeRevErr (-333) Wrong revision of the code to be executed by sExec.
smCPUErr (-334) The CPU field of the code was wrong.
smsPointerNil (-335) LPointer is nil From sOffsetData. If this error occurs;
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 SReadByte(__A0)
#endif
  OSErr
  SReadByte(SpBlockPtr spBlkPtr);

  /**
  \brief Return a 16-bit ID value

  <pre>SReadWord returns a 16-bit value identified by spID.
spBlkPtr is the address of a 56-byte Slot Parameter Block structure.
The relevant fields are as follows:
Out-In Name Type SizeOffsetDescription
←spResult long 40FUNCTION result
→spsPointer Ptr 44Structure pointer
→spID char 150sResource list ID
Other parameters affected are:
spsOffsetData long 412Offset/data field
spByteLanes  char 153ByteLanes from format block in card ROM
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
smEmptySlot (-300) No card in slot.
smCRCFail (-301) CRC check failed.
smFormatErr (-302) FHeader format is not Apple's
smRevisionErr (-303) The revision of the card's declaration ROM is wrong.
smNoDir (-304) Directory offset is NIL
smNosInfoArray (-306) The SDM could not allocate memory for the sInfo
array.
smResrvErr (-307) A reserved field of the declaration ROM was used.
smUnExBusErr (-308) An unexpected bus error occurred.
smBLFieldBad (-309) A valid ByteLanes field was not found.
smDisposePErr (-312) An error occurred during execution of DisposPointer.
smNoBoardSRsrc (-313) There is no board sResource.
smGetPRErr (-314) Error during execution of sGetPRAMRec.
smNoBoardId (-315) There is no board ID.
smInitStatVErr (-316) The InitStatus_V field was negative after Primary or
Secondary Init.
smInitTblVErr (-317) Error while trying to initialize the sResource Table.
smNoJmpTbl (-318) Slot Manager jump table could not be created
smBadBoardId (-319) Board ID was wrong; reinit the PRAM record
</pre>
* \note <pre>The trap macro SReadWord finds a data structure in slot card firmware.
It returns in spResult a 16-bit value identified by spID from the sResource
list pointed to by spsPointer . This routine can return non-fatal error
reports, which will be one of the following:
smBadRefId (-330) Reference ID was not found in the given sResource
list.
smBadsList (-331) The IDs in the sResource list are not in ascending
order.
smReservedErr (-332) A reserved field was not zero.
smCodeRevErr (-333) Wrong revision of the code to be executed by sExec.
smCPUErr (-334) The CPU field of the code was wrong.
smsPointerNil (-335) LPointer is nil From sOffsetData. If this error occurs;
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 SReadWord(__A0)
#endif
  OSErr
  SReadWord(SpBlockPtr spBlkPtr);

  /**
  \brief Return a 32-bit ID value

  <pre>SReadLong returns a 32-bit value identified by spID.
spBlkPtr is the address of a 56-byte Slot Parameter Block structure.
The relevant fields are as follows:
Out-In Name Type SizeOffsetDescription
←spResult long 40FUNCTION result
→spsPointer Ptr 44Structure pointer
→spID char 150sResource list ID
Other parameters affected are:
spSize long 48Size of structure
spsOffsetData long 412Offset/data field
spByteLanes char 153ByteLanes from format block in card ROM
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
smEmptySlot (-300) No card in slot.
smCRCFail (-301) CRC check failed.
smFormatErr (-302) FHeader format is not Apple's
smRevisionErr (-303) The revision of the card's declaration ROM is wrong.
smNoDir (-304) Directory offset is NIL
smNosInfoArray (-306) The SDM could not allocate memory for the sInfo
array.
smResrvErr (-307) A reserved field of the declaration ROM was used.
smUnExBusErr (-308) An unexpected bus error occurred.
smBLFieldBad (-309) A valid ByteLanes field was not found.
smDisposePErr (-312) An error occurred during execution of DisposPointer.
smNoBoardSRsrc (-313) There is no board sResource.
smGetPRErr (-314) Error during execution of sGetPRAMRec.
smNoBoardId (-315) There is no board ID.
smInitStatVErr (-316) The InitStatus_V field was negative after Primary or
Secondary Init.
smInitTblVErr (-317) Error while trying to initialize the sResource Table.
smNoJmpTbl (-318) Slot Manager jump table could not be created
smBadBoardId (-319) Board ID was wrong; reinit the PRAM record
</pre>
* \note <pre>The trap macro SReadLong finds a data structure in slot card firmware.
It returns in spResult a 32-bit value identified by spID from the sResource
list pointed to by spsPointer . This routine can return nonfatal error
reports, which will be one of the following:
smBadRefId (-330) Reference ID was not found in the given sResource
list.
smBadsList (-331) The IDs in the sResource list are not in ascending
order.
smReservedErr (-332) A reserved field was not zero.
smCodeRevErr (-333) Wrong revision of the code to be executed by sExec.
smCPUErr (-334) The CPU field of the code was wrong.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 SReadLong(__A0)
#endif
  OSErr
  SReadLong(SpBlockPtr spBlkPtr);

/**
 *  SGetCString()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 SGetCString(__A0)
#endif
  OSErr
  SGetCString(SpBlockPtr spBlkPtr);

/**
 *  SGetBlock()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 SGetBlock(__A0)
#endif
  OSErr
  SGetBlock(SpBlockPtr spBlkPtr);

/**
 *  SFindStruct()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 SFindStruct(__A0)
#endif
  OSErr
  SFindStruct(SpBlockPtr spBlkPtr);

  /**
  \brief Copy a data structure into a new block

  <pre>SReadStruct copies a data structure into a new block.
spBlkPtr is the address of a 56-byte Slot Parameter Block structure.
The relevant fields are as follows:
Out-In Name Type SizeOffsetDescription
→spResult long 40FUNCTION result
→spsPointer Ptr 44Structure pointer
→spSize long 48Size of structure
Other parameters affected are:
spByteLanes  char 153ByteLanes from format block in card ROM
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
smEmptySlot (-300) No card in slot.
smCRCFail (-301) CRC check failed.
smFormatErr (-302) FHeader format is not Apple's
smRevisionErr (-303) The revision of the card's declaration ROM is wrong.
smNoDir (-304) Directory offset is NIL
smNosInfoArray (-306) The SDM could not allocate memory for the sInfo
array.
smResrvErr (-307) A reserved field of the declaration ROM was used.
smUnExBusErr (-308) An unexpected bus error occurred.
smBLFieldBad (-309) A valid ByteLanes field was not found.
smDisposePErr (-312) An error occurred during execution of DisposPointer.
smNoBoardSRsrc (-313) There is no board sResource.
smGetPRErr (-314) Error during execution of sGetPRAMRec.
smNoBoardId (-315) There is no board ID.
smInitStatVErr (-316) The InitStatus_V field was negative after Primary or
Secondary Init.
smInitTblVErr (-317) Error while trying to initialize the sResource Table.
smNoJmpTbl (-318) Slot Manager jump table could not be created
smBadBoardId (-319) Board ID was wrong; reinit the PRAM record
</pre>
* \note <pre>The trap macro SReadStruct copies a structure of size spSize from the
sResource list pointed to by spsPointer into a new block allocated by the
calling program and pointed to by spResult .
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 SReadStruct(__A0)
#endif
  OSErr
  SReadStruct(SpBlockPtr spBlkPtr);

  /**  Special  */

  /**
  \brief Read a data structure into a new block

  <pre>SReadInfo read the spSlot's sInfoRecord into a new record.
spBlkPtr is the address of a 56-byte Slot Parameter Block structure.
The relevant fields are as follows:
Out-In Name Type SizeOffsetDescription
→spResult long 40FUNCTION result
→spSlot char 149Slot number
Other parameters affected are:
spSize  long4 8QSize of structure
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
smEmptySlot (-300) No card in slot.
smCRCFail (-301) CRC check failed.
smFormatErr (-302) FHeader format is not Apple's
smRevisionErr (-303) The revision of the card's declaration ROM is wrong.
smNoDir (-304) Directory offset is NIL
smNosInfoArray (-306) The SDM could not allocate memory for the sInfo
array.
smResrvErr (-307) A reserved field of the declaration ROM was used.
smUnExBusErr (-308) An unexpected bus error occurred.
smBLFieldBad (-309) A valid ByteLanes field was not found.
smDisposePErr (-312) An error occurred during execution of DisposPointer.
smNoBoardSRsrc (-313) There is no board sResource.
smGetPRErr (-314) Error during execution of sGetPRAMRec.
smNoBoardId (-315) There is no board ID.
smInitStatVErr (-316) The InitStatus_V field was negative after Primary or
Secondary Init.
smInitTblVErr (-317) Error while trying to initialize the sResource Table.
smNoJmpTbl (-318) Slot Manager jump table could not be created
smBadBoardId (-319) Board ID was wrong; reinit the PRAM record
</pre>
* \note <pre>The trap macro SReadInfo reads the sInfoRecord identified by spSlot
into a new record allocated by the calling program and pointed to by
spResult .
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 SReadInfo(__A0)
#endif
  OSErr
  SReadInfo(SpBlockPtr spBlkPtr);

  /**
  \brief Copy the sPRAM data structure into a new record

  <pre>SReadPRAMRec copies the sPRAM record data for the slot identified by
spSlot to a new record allocated by the calling program and pointed to by
spResult .
spBlkPtr is the address of a 56-byte Slot Parameter Block structure.
The relevant fields are as follows:
Out-In Name Type SizeOffsetDescription
→spResult long 40FUNCTION result
→spSlot char 149Slot number
Other parameters affected are:
spSize  long4 8QSize of structure
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
smEmptySlot (-300) No card in slot.
smCRCFail (-301) CRC check failed.
smFormatErr (-302) FHeader format is not Apple's
smRevisionErr (-303) The revision of the card's declaration ROM is wrong.
smNoDir (-304) Directory offset is NIL
smNosInfoArray (-306) The SDM could not allocate memory for the sInfo
array.
smResrvErr (-307) A reserved field of the declaration ROM was used.
smUnExBusErr (-308) An unexpected bus error occurred.
smBLFieldBad (-309) A valid ByteLanes field was not found.
smDisposePErr (-312) An error occurred during execution of DisposPointer.
smNoBoardSRsrc (-313) There is no board sResource.
smGetPRErr (-314) Error during execution of sGetPRAMRec.
smNoBoardId (-315) There is no board ID.
smInitStatVErr (-316) The InitStatus_V field was negative after Primary or
Secondary Init.
smInitTblVErr (-317) Error while trying to initialize the sResource Table.
smNoJmpTbl (-318) Slot Manager jump table could not be created
smBadBoardId (-319) Board ID was wrong; reinit the PRAM record
</pre>
* \note <pre>One sPRAM record for each slot resides in the Macintosh II parameter
RAM. The sPRAM record is initialized during the startup by
SInitPRAMRecs .
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 SReadPRAMRec(__A0)
#endif
  OSErr
  SReadPRAMRec(SpBlockPtr spBlkPtr);

  /**
  \brief Copy  data from spsPointer's block into SPRAMRecord

  <pre>SPutPRAMRec copies the logical data from the block referenced by
spsPointer into the SPRAMRecord for the slot identified by spSlot.
spBlkPtr is the address of a 56-byte Slot Parameter Block structure.
The relevant fields are as follows:
Out-In Name Type SizeOffsetDescription
→spsPointer Ptr 44Structure pointer
→spSlot char 149Slot number
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
smEmptySlot (-300) No card in slot.
smCRCFail (-301) CRC check failed.
smFormatErr (-302) FHeader format is not Apple's
smRevisionErr (-303) The revision of the card's declaration ROM is wrong.
smNoDir (-304) Directory offset is NIL
smNosInfoArray (-306) The SDM could not allocate memory for the sInfo
array.
smResrvErr (-307) A reserved field of the declaration ROM was used.
smUnExBusErr (-308) An unexpected bus error occurred.
smBLFieldBad (-309) A valid ByteLanes field was not found.
smDisposePErr (-312) An error occurred during execution of DisposPointer.
smNoBoardSRsrc (-313) There is no board sResource.
smGetPRErr (-314) Error during execution of sGetPRAMRec.
smNoBoardId (-315) There is no board ID.
smInitStatVErr (-316) The InitStatus_V field was negative after Primary or
Secondary Init.
smInitTblVErr (-317) Error while trying to initialize the sResource Table.
smNoJmpTbl (-318) Slot Manager jump table could not be created
smBadBoardId (-319) Board ID was wrong; reinit the PRAM record
</pre>
* \note <pre>SPutPRAMRec updates the Macintosh PRAM for that slot. The sPRAM
record is defined under SPRAMRecord . In that record, the field boardID is
an Apple-defined field and is protected during execution of SPutPRAMRec.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 SPutPRAMRec(__A0)
#endif
  OSErr
  SPutPRAMRec(SpBlockPtr spBlkPtr);

  /**
  \brief Copy the slot's format block into an FHeaderRec

  <pre>SReadFHeader copies the format block for the slot designated by spSlot to an
FHeaderRec allocated by the calling program and pointed to by spResult .
spBlkPtr is the address of a 56-byte Slot Parameter Block structure.
The relevant fields are as follows:
Out-In Name Type SizeOffsetDescription
→spResult long 40FUNCTION result
→spSlot char 149Slot number
Other parameters affected are:
spsPointer Ptr 44Structure pointer
spSize long 48Size of structure
spsOffsetData long 412Offset/data field
spByteLanes char 153ByteLanes from format block in card ROM
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
smEmptySlot (-300) No card in slot.
smCRCFail (-301) CRC check failed.
smFormatErr (-302) FHeader format is not Apple's
smRevisionErr (-303) The revision of the card's declaration ROM is wrong.
smNoDir (-304) Directory offset is NIL
smNosInfoArray (-306) The SDM could not allocate memory for the sInfo
array.
smResrvErr (-307) A reserved field of the declaration ROM was used.
smUnExBusErr (-308) An unexpected bus error occurred.
smBLFieldBad (-309) A valid field was not found.
smDisposePErr (-312) An error occurred during execution of DisposPointer.
smNoBoardSRsrc (-313) There is no board sResource.
smGetPRErr (-314) Error during execution of sGetPRAMRec.
smNoBoardId (-315) There is no board ID.
smInitStatVErr (-316) The InitStatus_V field was negative after Primary or
Secondary Init.
smInitTblVErr (-317) Error while trying to initialize the sResource Table.
smNoJmpTbl (-318) Slot Manager jump table could not be created
smBadBoardId (-319) Board ID was wrong; reinit the PRAM record
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 SReadFHeader(__A0)
#endif
  OSErr
  SReadFHeader(SpBlockPtr spBlkPtr);

  /**
  \brief Determine the set of all a slot card's or NuBus's sResources

  <pre>SNextSRsrc can be used to determine the set of all sResources in a given slot
card or NuBus configuration.
spBlkPtr is the address of a 56-byte Slot Parameter Block structure.
The relevant fields are as follows:
Out-In Name Type SizeOffsetDescription
←spsPointer Ptr 44Structure pointer
←spIOReserved short 236Reserved field of Slot Resource Table
←spRefNum short 238Slot Resource Table reference number
←spCategory short 240sResource type: Category
←spCType short 242sResource type: Type
←spDrvrSW short 244sResource type: Driver software identifier
←spDrvrHW short 246sResource type: Driver hardware identifier
↔spSlot char 149Slot number
↔spID char 150sResource list ID
↔spExtDev char 151External device identifier
←spHwDev char 152Hardware device identifier
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
smEmptySlot (-300) No card in slot.
smCRCFail (-301) CRC check failed.
smFormatErr (-302) FHeader format is not Apple's
smRevisionErr (-303) The revision of the card's declaration ROM is wrong.
smNoDir (-304) Directory offset is NIL
smNosInfoArray (-306) The SDM could not allocate memory for the sInfo
array.
smResrvErr (-307) A reserved field of the declaration ROM was used.
smUnExBusErr (-308) An unexpected bus error occurred.
smBLFieldBad (-309) A valid ByteLanes field was not found.
smDisposePErr (-312) An error occurred during execution of DisposPointer.
smNoBoardsRsrc (-313) There is no board sResource.
smGetPRErr (-314) Error during execution of sGetPRAMRec.
smNoBoardId (-315) There is no board ID.
smInitStatVErr (-316) The InitStatus_V field was negative after Primary or
Secondary Init.
smInitTblVErr (-317) Error while trying to initialize the sResource Table.
smNoJmpTbl (-318) Slot Manager jump table could not be created
smBadBoardId (-319) Board ID was wrong; reinit the PRAM record
</pre>
* \note <pre>Starting from a given slot number, spSlot, sResource list identification
number, spID, and external device identifier, spExtDev , the trap macro
SNextSRsrc returns the slot number, sResource list identification
number, sResource type (category, cType, software, and hardware), driver
reference number ( spRefNum ), and Slot Resource Table ioReserved field
(spIOReserved ) for the next sResource. If there are no more sResources,
SNextSRsrc returns a nonfatal error status, which can be one of the
following:
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 SNextSRsrc(__A0)
#endif
  OSErr
  SNextSRsrc(SpBlockPtr spBlkPtr);

  /**
  \brief Return information about sResources of a specified type.

  <pre>SNextTypeSRsrc behaves the same as SNextSRsrc except that it returns
information only about sResources of the specified type.
spBlkPtr is the address of a 56-byte Slot Parameter Block structure.
The relevant fields are as follows:
Out-In Name Type SizeOffsetDescription
←spsPointer Ptr 44Structure pointer
←spIOReserved short 236Reserved field of Slot Resource Table
←spRefNum short 238Slot Resource Table reference number
↔spCategory short 240sResource type: Category
↔spCType short 242sResource type: Type
↔spDrvrSW short 244sResource type: Driver software identifier
↔spDrvrHW short 246sResource type: Driver hardware identifier
→spTBMask char 148Type bit mask (bits 0..3 mask words 0..3)
↔spSlot char 149Slot number
↔spID char 150sResource list ID
↔spExtDev char 151External device identifier
↔spHwDev char 152Hardware device identifier
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
smEmptySlot (-300) No card in slot.
smCRCFail (-301) CRC check failed.
smFormatErr (-302) FHeader format is not Apple's
smRevisionErr (-303) The revision of the card's declaration ROM is wrong.
smNoDir (-304) Directory offset is NIL
smNosInfoArray (-306) The SDM could not allocate memory for the sInfo
array.
smResrvErr (-307) A reserved field of the declaration ROM was used.
smUnExBusErr (-308) An unexpected bus error occurred.
smBLFieldBad (-309) A valid ByteLanes field was not found.
smDisposePErr (-312) An error occurred during execution of DisposPointer.
smNoBoardSRsrc (-313) There is no board sResource.
smGetPRErr (-314) Error during execution of sGetPRAMRec.
smNoBoardId (-315) There is no board ID.
smInitStatVErr (-316) The InitStatus_V field was negative after Primary or
Secondary Init.
smInitTblVErr (-317) Error while trying to initialize the sResource Table.
smNoJmpTbl (-318) Slot Manager jump table could not be created
smBadBoardId (-319) Board ID was wrong; reinit the PRAM record
</pre>
* \note <pre>Given an sResource type (category, cType, software, and hardware) and
spTBMask , and starting from a given slot number, spSlot, and sResource
list identification number, spID, the trap macro SNextTypeSRsrc
returns the slot number, spSlot, sResource list identification number,
spID, and Slot Resource Table ioReserved field ( spIOReserved ) for the
next sResource of that type, as masked. If there are no more sResources of
that type, SNextTypeSRsrc returns a nonfatal error report, which can
be one of the following:
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 SNextTypeSRsrc(__A0)
#endif
  OSErr
  SNextTypeSRsrc(SpBlockPtr spBlkPtr);

  /**
  \brief Return the driver reference number

  <pre>SRsrcInfo is most often used to return the driver reference number.
spBlkPtr is the address of a 56-byte Slot Parameter Block structure.
The relevant fields are as follows:
Out-In Name Type SizeOffsetDescription
←spsPointer Ptr 44Structure pointer
←spIOReserved short 236Reserved field of Slot Resource Table
←spRefNum short 238Slot Resource Table reference number
←spCategory short 240sResource type: Category
←spCType short 242sResource type: Type
←spDrvrSW short 244sResource type: Driver software identifier
←spDrvrHW short 246sResource type: Driver hardware identifier
→spSlot char 149Slot number
→spID char 150sResource list ID
→spExtDev char 141External device identifier
←spHwDev char 152Hardware device identifier
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
smEmptySlot (-300) No card in slot.
smCRCFail (-301) CRC check failed.
smFormatErr (-302) FHeader format is not Apple's.
smRevisionErr (-303) The revision of the card's declaration ROM is wrong.
smNoDir (-304) Directory offset is NIL.
smNosInfoArray (-306) The SDM could not allocate memory for the sInfo
array.
smResrvErr (-307) A reserved field of the declaration ROM was used.
smUnExBusErr (-308) An unexpected bus error occurred.
smBLFieldBad (-309) A valid ByteLanes field was not found.
smDisposePErr (-312) An error occurred during execution of DisposPointer.
smNoBoardsRsrc (-313) There is no board sResource.
smGetPRErr (-314) Error during execution of sGetPRAMRec.
smNoBoardId (-315) There is no board ID.
smInitStatVErr (-316) The InitStatus_V field was negative after Primary or
Secondary Init.
smInitTblVErr (-317) Error while trying to initialize the sResource Table.
smNoJmpTbl (-318) Slot Manager jump table could not be created
smBadBoardId (-319) Board ID was wrong; reinit the PRAM record
</pre>
* \note <pre>SRsrcInfo returns an sResource list pointer ( spsPointer ), plus the
sResource type (category, cType, software, and hardware), driver
reference number ( spRefNum ), and Slot Resource Table ioReserved field
(spIOReserved ) for the sResource specified by the slot number spSlot,
sResource list identification number spID, and external device identifier
spExtDev .
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 SRsrcInfo(__A0)
#endif
  OSErr
  SRsrcInfo(SpBlockPtr spBlkPtr);

/**
 *  SDisposePtr()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 SDisposePtr(__A0)
#endif
  OSErr
  SDisposePtr(SpBlockPtr spBlkPtr);

  /**
  \brief Check the SInfoRecord's InitStatusA field

  <pre>SCkCardStat checks the InitStatusA field of the SInfoRecord  of the slot
designated by spSlot, which also reflects the value of the InitStatusV field.
spBlkPtr is the address of a 56-byte Slot Parameter Block structure.
The relevant fields are as follows:
Out-In Name Type SizeOffsetDescription
→spSlot char 149Slot number
Other parameters affected are:
spResult long 40FUNCTION result
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
smEmptySlot (-300) No card in slot.
smCRCFail (-301) CRC check failed.
smFormatErr (-302) FHeader format is not Apple's
smRevisionErr (-303) The revision of the card's declaration ROM is wrong.
smNoDir (-304) Directory offset is NIL
smNosInfoArray (-306) The SDM could not allocate memory for the sInfo
array.
smResrvErr (-307) A reserved field of the declaration ROM was used.
smUnExBusErr (-308) An unexpected bus error occurred.
smBLFieldBad (-309) A valid ByteLanes field was not found.
smDisposePErr (-312) An error occurred during execution of DisposPointer.
smNoBoardSRsrc (-313) There is no board sResource.
smGetPRErr (-314) Error during execution of sGetPRAMRec.
smNoBoardId (-315) There is no board ID.
smInitStatVErr (-316) The InitStatus_V field was negative after Primary or
Secondary Init.
smInitTblVErr (-317) Error while trying to initialize the sResource Table.
smNoJmpTbl (-318) Slot Manager jump table could not be created
smBadBoardId (-319) Board ID was wrong; reinit the PRAM record
</pre>
* \note <pre>If this field contains a nonzero value, SCkCardStat returns a zero value.
See SInfoRecord for a description of the sInfo record. The SCkCardStat
routine can return nonfatal error reports, which can be one of the
following:
smBadRefId (-330) Reference ID was not found in the given sResource
list.
smBadsList (-331) The IDs in the sResource list are not in ascending
order.
smReservedErr (-332) A reserved field was not zero.
smCodeRevErr (-333) Wrong revision of the code to be executed by sExec.
smCPUErr (-334) The CPU field of the code was wrong.
smsPointerNil (-335) LPointer is nil From sOffsetData. If this error occurs;
check sInfo rec for more information.
smNilsBlockErr (-336) The physical block size (of an sBlock) was zero.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 SCkCardStat(__A0)
#endif
  OSErr
  SCkCardStat(SpBlockPtr spBlkPtr);

  /**
  \brief Read the name of the sResource for this slot and list ID

  <pre>SReadDrvrName reads the name of the sResource corresponding to the slot
number and list identification number.
spBlkPtr is the address of a 56-byte Slot Parameter Block structure.
The relevant fields are as follows:
Out-In Name Type SizeOffsetDescription
→spResult long 40FUNCTION result
→spSlot char 149Slot number
→spID char 150sResource list ID
Other parameters affected are:
spsPointer Ptr 44Structure pointer
spSize long 48Size of structure
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
smEmptySlot (-300) No card in slot.
smCRCFail (-301) CRC check failed.
smFormatErr (-302) FHeader format is not Apple's
smRevisionErr (-303) The revision of the card's declaration ROM is wrong.
smNoDir (-304) Directory offset is NIL
smNosInfoArray (-306) The SDM could not allocate memory for the sInfo
array.
smResrvErr (-307) A reserved field of the declaration ROM was used.
smUnExBusErr (-308) An unexpected bus error occurred.
smBLFieldBad (-309) A valid ByteLanes field was not found.
smDisposePErr (-312) An error occurred during execution of DisposPointer.
smNoBoardSRsrc (-313) There is no board sResource.
smGetPRErr (-314) Error during execution of sGetPRAMRec.
smNoBoardId (-315) There is no board ID.
smInitStatVErr (-316) The InitStatus_V field was negative after Primary or
Secondary Init.
smInitTblVErr (-317) Error while trying to initialize the sResource Table.
smNoJmpTbl (-318) Slot Manager jump table could not be created
smBadBoardId (-319) Board ID was wrong; reinit the PRAM record
</pre>
* \note <pre>The trap macro SReadDrvrName reads the name of the sResource
corresponding to the slot number, spSlot, and sResource list identification
number, spID, prefixes a period to the value of the cString and converts its
type to Str255. It then reads the result into a Pascal string variable
declared by the calling program and pointed to by spResult . The final driver
name is compatible with the Open routine.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 SReadDrvrName(__A0)
#endif
  OSErr
  SReadDrvrName(SpBlockPtr spBlkPtr);

/**
 *  SFindSRTRec()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 SFindSRTRec(__A0)
#endif
  OSErr
  SFindSRTRec(SpBlockPtr spBlkPtr);

  /**
  \brief Return a pointer to the base of a device

  <pre>SFindDevBase returns a pointer in spResult to the base of a device whose
slot number is in spSlot and whose sResource ID is in spID.
spBlkPtr is the address of a 56-byte Slot Parameter Block structure.
The relevant fields are as follows:
Out-In Name Type SizeOffsetDescription
←spResult long 40FUNCTION result
→spID char 150sResource list ID
→spSlot char 149Slot number
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
smEmptySlot (-300) No card in slot.
smCRCFail (-301) CRC check failed.
smFormatErr (-302) FHeader format is not Apple's
smRevisionErr (-303) The revision of the card's declaration ROM is wrong.
smNoDir (-304) Directory offset is NIL
smNosInfoArray (-306) The SDM could not allocate memory for the sInfo
array.
smResrvErr (-307) A reserved field of the declaration ROM was used.
smUnExBusErr (-308) An unexpected bus error occurred.
smBLFieldBad (-309) A valid ByteLanes field was not found.
smDisposePErr (-312) An error occurred during execution of DisposPointer.
smNoBoardSRsrc (-313) There is no board sResource.
smGetPRErr (-314) Error during execution of sGetPRAMRec.
smNoBoardId (-315) There is no board ID.
smInitStatVErr (-316) The InitStatus_V field was negative after Primary or
Secondary Init.
smInitTblVErr (-317) Error while trying to initialize the sResource Table.
smNoJmpTbl (-318) Slot Manager jump table could not be created
smBadBoardId (-319) Board ID was wrong; reinit the PRAM record
</pre>
* \note <pre>The base address of a device may be in either slot or superslot space but
not in both. Slot or superslot slot spaces are discussed in the book Designing
Cards and Drivers for Macintosh II and Macintosh SE .
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 SFindDevBase(__A0)
#endif
  OSErr
  SFindDevBase(SpBlockPtr spBlkPtr);

/**
 *  SFindBigDevBase()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 SFindBigDevBase(__A0)
#endif
  OSErr
  SFindBigDevBase(SpBlockPtr spBlkPtr);

/**  Advanced  */
/**
 *  InitSDeclMgr()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 InitSDeclMgr(__A0)
#endif
  OSErr
  InitSDeclMgr(SpBlockPtr spBlkPtr);

/**
 *  SPrimaryInit()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 SPrimaryInit(__A0)
#endif
  OSErr
  SPrimaryInit(SpBlockPtr spBlkPtr);

  /**
  \brief Indicate if a card has been changed

  <pre>SCardChanged returns a value of true in spResult if the card in slot spSlot
has been changed (that is, if its sPRAMRecord has been initialized);
otherwise it returns false. Used only by the Operating System.
spBlkPtr is the address of a 56-byte Slot Parameter Block structure.
The relevant fields are as follows:
Out-In Name Type SizeOffsetDescription
←spResult long 40FUNCTION result
→spSlot char 149Slot number
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
smEmptySlot (-300) No card in slot.
smCRCFail (-301) CRC check failed.
smFormatErr (-302) FHeader format is not Apple's
smRevisionErr (-303) The revision of the card's declaration ROM is wrong.
smNoDir (-304) Directory offset is NIL
smNosInfoArray (-306) The SDM could not allocate memory for the sInfo
array.
smResrvErr (-307) A reserved field of the declaration ROM was used.
smUnExBusErr (-308) An unexpected bus error occurred.
smBLFieldBad (-309) A valid ByteLanes field was not found.
smDisposePErr (-312) An error occurred during execution of DisposPointer.
smNoBoardSRsrc (-313) There is no board sResource.
smGetPRErr (-314) Error during execution of sGetPRAMRec.
smNoBoardId (-315) There is no board ID.
smInitStatVErr (-316) The InitStatus_V field was negative after Primary or
Secondary Init.
smInitTblVErr (-317) Error while trying to initialize the sResource Table.
smNoJmpTbl (-318) Slot Manager jump table could not be created
smBadBoardId (-319) Board ID was wrong; reinit the PRAM record
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 SCardChanged(__A0)
#endif
  OSErr
  SCardChanged(SpBlockPtr spBlkPtr);

/**
 *  SExec()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 SExec(__A0)
#endif
  OSErr
  SExec(SpBlockPtr spBlkPtr);

  /**
  \brief Return the contents of the offset/data field

  <pre>SOffsetData returns (in spOffsetData ) the contents of the offset/data field
from the sResource list identified by spID and pointed to by spsPointer . Used
only by the Operating System.
spBlkPtr is the address of a 56-byte Slot Parameter Block structure.
The relevant fields are as follows:
Out-In Name Type SizeOffsetDescription
→spsPointer Ptr 44Structure pointer
← spsOffsetData long 412Offset/data field
→spID char 150Structure ID
← spByteLanes  char 153ByteLanes from format block in card ROM
Other affected parameters are:
spResult long 40FUNCTION result
spFlags char 154Internal use only
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
smEmptySlot (-300) No card in slot.
smCRCFail (-301) CRC check failed.
smFormatErr (-302) FHeader format is not Apple's
smRevisionErr (-303) The revision of the card's declaration ROM is wrong.
smNoDir (-304) Directory offset is NIL
smNosInfoArray (-306) The SDM could not allocate memory for the sInfo
array.
smResrvErr (-307) A reserved field of the declaration ROM was used.
smUnExBusErr (-308) An unexpected bus error occurred.
smBLFieldBad (-309) A valid ByteLanes field was not found.
smDisposePErr (-312) An error occurred during execution of DisposPointer.
smNoBoardSRsrc (-313) There is no board sResource.
smGetPRErr (-314) Error during execution of sGetPRAMRec.
smNoBoardId (-315) There is no board ID.
smInitStatVErr (-316) The InitStatus_V field was negative after Primary or
Secondary Init.
smInitTblVErr (-317) Error while trying to initialize the sResource Table.
smNoJmpTbl (-318) Slot Manager jump table could not be created
smBadBoardId (-319) Board ID was wrong; reinit the PRAM record
</pre>
* \note <pre>The parameter spsPointer returns a pointer to the field's identification
number in the sResource list.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 SOffsetData(__A0)
#endif
  OSErr
  SOffsetData(SpBlockPtr spBlkPtr);

/**
 *  SInitPRAMRecs()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 SInitPRAMRecs(__A0)
#endif
  OSErr
  SInitPRAMRecs(SpBlockPtr spBlkPtr);

  /**
  \brief Read the size of the indicated sBlock

  <pre>SReadPBSize reads the physical block size of the sBlock pointed to by
spsPointer and identified by spID. Used only by the Operating System.
spBlkPtr is the address of a 56-byte Slot Parameter Block structure.
The relevant fields are as follows:
Out-In Name Type SizeOffsetDescription
→spsPointer Ptr 44Structure pointer
←spSize  long 48Size of structure
→spID char 150Structure ID
← spByteLanes  char 153ByteLanes from format block in card ROM
→spFlags char 154Internal use only
Other affected parameters are:
spResult long 40FUNCTION result
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
smEmptySlot (-300) No card in slot.
smCRCFail (-301) CRC check failed.
smFormatErr (-302) FHeader format is not Apple's
smRevisionErr (-303) The revision of the card's declaration ROM is wrong.
smNoDir (-304) Directory offset is NIL
smNosInfoArray (-306) The SDM could not allocate memory for the sInfo
array.
smResrvErr (-307) A reserved field of the declaration ROM was used.
smUnExBusErr (-308) An unexpected bus error occurred.
smBLFieldBad (-309) A valid ByteLanes field was not found.
smDisposePErr (-312) An error occurred during execution of DisposPointer.
smNoBoardSRsrc (-313) There is no board sResource.
smGetPRErr (-314) Error during execution of sGetPRAMRec.
smNoBoardId (-315) There is no board ID.
smInitStatVErr (-316) The InitStatus_V field was negative after Primary or
Secondary Init.
smInitTblVErr (-317) Error while trying to initialize the sResource Table.
smNoJmpTbl (-318) Slot Manager jump table could not be created
smBadBoardId (-319) Board ID was wrong; reinit the PRAM record
</pre>
* \note <pre>SReadPBSize also checks to see that the upper byte is 0 if the fckReserved
flag is set. The parameter spsPointer points to the resulting logical block
when SReadPBSize is done.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 SReadPBSize(__A0)
#endif
  OSErr
  SReadPBSize(SpBlockPtr spBlkPtr);

  /**
  \brief Find the field sizes in the indicated block

  <pre>SCalcStep calculates the field sizes in the block pointed to by spBlkPtr.
Used only by the Operating System.
spBlkPtr is the address of a 56-byte Slot Parameter Block structure.
The relevant fields are as follows:
Out-In Name Type SizeOffsetDescription
←spResult long 40FUNCTION result
→spsPointer Ptr 44Structure pointer
→ spByteLanes  char 153ByteLanes from format block in card ROM
→spFlags char 154Internal use only
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
smEmptySlot (-300) No card in slot.
smCRCFail (-301) CRC check failed.
smFormatErr (-302) FHeader format is not Apple's
smRevisionErr (-303) The revision of the card's declaration ROM is wrong.
smNoDir (-304) Directory offset is NIL
smNosInfoArray (-306) The SDM could not allocate memory for the sInfo
array.
smResrvErr (-307) A reserved field of the declaration ROM was used.
smUnExBusErr (-308) An unexpected bus error occurred.
smBLFieldBad (-309) A valid ByteLanes field was not found.
smDisposePErr (-312) An error occurred during execution of DisposPointer.
smNoBoardSRsrc (-313) There is no board sResource.
smGetPRErr (-314) Error during execution of sGetPRAMRec.
smNoBoardId (-315) There is no board ID.
smInitStatVErr (-316) The InitStatus_V field was negative after Primary or
Secondary Init.
smInitTblVErr (-317) Error while trying to initialize the sResource Table.
smNoJmpTbl (-318) Slot Manager jump table could not be created
smBadBoardId (-319) Board ID was wrong; reinit the PRAM record
</pre>
* \note <pre>SCalcStep is used for stepping through the card firmware one field at a
time. If the fConsecBytes flag is set it calculates the step value for
consecutive bytes; otherwise it calculates it for consecutive IDs.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 SCalcStep(__A0)
#endif
  OSErr
  SCalcStep(SpBlockPtr spBlkPtr);

/**
 *  SInitSRsrcTable()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 SInitSRsrcTable(__A0)
#endif
  OSErr
  SInitSRsrcTable(SpBlockPtr spBlkPtr);

  /**
  \brief Find the record corresponding to this sResource

  <pre>SSearchSRT searches the Slot Resource Table for the record corresponding
to the sResource in slot spSlot with list spID and external device identifier
spExtDev , and returns a pointer to it in spsPointer . Used only by the
Operating System.
spBlkPtr is the address of a 56-byte Slot Parameter Block structure.
The relevant fields are as follows:
Out-In Name Type SizeOffsetDescription
→spsPointer Ptr 44Structure pointer
→spID char 150sResource list ID
→spExtDev char 151ID of the external device
→spSlot char 149Slot number
→spFlags char 154Internal use only
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
smEmptySlot (-300) No card in slot.
smCRCFail (-301) CRC check failed.
smFormatErr (-302) FHeader format is not Apple's
smRevisionErr (-303) The revision of the card's declaration ROM is wrong.
smNoDir (-304) Directory offset is NIL
smNosInfoArray (-306) The SDM could not allocate memory for the sInfo
array.
smResrvErr (-307) A reserved field of the declaration ROM was used.
smUnExBusErr (-308) An unexpected bus error occurred.
smBLFieldBad (-309) A valid ByteLanes field was not found.
smDisposePErr (-312) An error occurred during execution of DisposPointer.
smNoBoardSRsrc (-313) There is no board sResource.
smGetPRErr (-314) Error during execution of sGetPRAMRec.
smNoBoardId (-315) There is no board ID.
smInitStatVErr (-316) The InitStatus_V field was negative after Primary or
Secondary Init.
smInitTblVErr (-317) Error while trying to initialize the sResource Table.
smNoJmpTbl (-318) Slot Manager jump table could not be created
smBadBoardId (-319) Board ID was wrong; reinit the PRAM record
</pre>
* \note <pre>If fckForNext bit of spFlags has a value of 0, SSearchSRT searches for
that record; if it has a value of 1, it searches for the next record.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 SSearchSRT(__A0)
#endif
  OSErr
  SSearchSRT(SpBlockPtr spBlkPtr);

  /**
  \brief Update the Slot Resource Table

  <pre>SUpdateSRT updates the Slot Resource Table records spRefNum and
spIOReserved with information about the sResource in slot spSlot with list
spID and external device identifier spExtDev . Used only by the Operating
System.
spBlkPtr is the address of a 56-byte Slot Parameter Block structure.
The relevant fields are as follows:
Out-In Name Type SizeOffsetDescription
→spIOReserved short 236Reserved field of Slot Resource Table
→spRefNum short 238Slot Resource Table reference number
→spID char 150sResource list ID
→spExtDev char 151ID of the external device
→spSlot char 149Slot number
Other parameters affected include:
spResult long 40FUNCTION result
spsPointer Ptr 44Structure pointer
spSize long 48Size of structure
spFlags char 154Internal use only
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
smEmptySlot (-300) No card in slot.
smCRCFail (-301) CRC check failed.
smFormatErr (-302) FHeader format is not Apple's
smRevisionErr (-303) The revision of the card's declaration ROM is wrong.
smNoDir (-304) Directory offset is NIL
smNosInfoArray (-306) The SDM could not allocate memory for the sInfo
array.
smResrvErr (-307) A reserved field of the declaration ROM was used.
smUnExBusErr (-308) An unexpected bus error occurred.
smBLFieldBad (-309) A valid ByteLanes field was not found.
smDisposePErr (-312) An error occurred during execution of DisposPointer.
smNoBoardSRsrc (-313) There is no board sResource.
smGetPRErr (-314) Error during execution of sGetPRAMRec.
smNoBoardId (-315) There is no board ID.
smInitStatVErr (-316) The InitStatus_V field was negative after Primary or
Secondary Init.
smInitTblVErr (-317) Error while trying to initialize the sResource Table.
smNoJmpTbl (-318) Slot Manager jump table could not be created
smBadBoardId (-319) Board ID was wrong; reinit the PRAM record
</pre>
* \note <pre>This routine is called by IOCore whenever the driver for a slot device is
opened or closed.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 SUpdateSRT(__A0)
#endif
  OSErr
  SUpdateSRT(SpBlockPtr spBlkPtr);

  /**
  \brief Return pointer to a byte in declaration ROM

  <pre>SCalcSPointer returns a pointer to a given byte in a card's declaration
ROM, given the pointer to a current byte and an offset ( spOffsetData ) in bytes.
Used only by the Operating System.
spBlkPtr is the address of a 56-byte Slot Parameter Block structure.
The relevant fields are as follows:
Out-In Name Type SizeOffsetDescription
→spsPointer Ptr 44Structure pointer
→ spsOffsetData long 412Offset/data field
→  spByteLanes char 153ByteLanes from format block in card ROM
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
smEmptySlot (-300) No card in slot.
smCRCFail (-301) CRC check failed.
smFormatErr (-302) FHeader format is not Apple's
smRevisionErr (-303) The revision of the card's declaration ROM is wrong.
smNoDir (-304) Directory offset is NIL
smNosInfoArray (-306) The SDM could not allocate memory for the sInfo
array.
smResrvErr (-307) A reserved field of the declaration ROM was used.
smUnExBusErr (-308) An unexpected bus error occurred.
smBLFieldBad (-309) A valid ByteLanes field was not found.
smDisposePErr (-312) An error occurred during execution of DisposPointer.
smNoBoardSRsrc (-313) There is no board sResource.
smGetPRErr (-314) Error during execution of sGetPRAMRec.
smNoBoardId (-315) There is no board ID.
smInitStatVErr (-316) The InitStatus_V field was negative after Primary or
Secondary Init.
smInitTblVErr (-317) Error while trying to initialize the sResource Table.
smNoJmpTbl (-318) Slot Manager jump table could not be created
smBadBoardId (-319) Board ID was wrong; reinit the PRAM record
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 SCalcSPointer(__A0)
#endif
  OSErr
  SCalcSPointer(SpBlockPtr spBlkPtr);

/**
 *  SGetDriver()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 SGetDriver(__A0)
#endif
  OSErr
  SGetDriver(SpBlockPtr spBlkPtr);

  /**
  \brief Return the slot number of a card

  <pre>SPtrToSlot returns in spSlot the slot number of the card whose declaration
ROM is pointed to by spsPointer .
spBlkPtr is the address of a 56-byte Slot Parameter Block structure.
The relevant fields are as follows:
Out-In Name Type SizeOffsetDescription
→spsPointer Ptr 44Structure pointer
←spSlot char 149Slot number
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
smEmptySlot (-300) No card in slot.
smCRCFail (-301) CRC check failed.
smFormatErr (-302) FHeader format is not Apple's
smRevisionErr (-303) The revision of the card's declaration ROM is wrong.
smNoDir (-304) Directory offset is NIL
smNosInfoArray (-306) The SDM could not allocate memory for the sInfo
array.
smResrvErr (-307) A reserved field of the declaration ROM was used.
smUnExBusErr (-308) An unexpected bus error occurred.
smBLFieldBad (-309) A valid ByteLanes field was not found.
smDisposePErr (-312) An error occurred during execution of DisposPointer.
smNoBoardSRsrc (-313) There is no board sResource.
smGetPRErr (-314) Error during execution of sGetPRAMRec.
smNoBoardId (-315) There is no board ID.
smInitStatVErr (-316) The InitStatus_V field was negative after Primary or
Secondary Init.
smInitTblVErr (-317) Error while trying to initialize the sResource Table.
smNoJmpTbl (-318) Slot Manager jump table could not be created
smBadBoardId (-319) Board ID was wrong; reinit the PRAM record
</pre>
* \note <pre>The value of spsPointer must have the form Fsxx xxxx, where s is a slot
number.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 SPtrToSlot(__A0)
#endif
  OSErr
  SPtrToSlot(SpBlockPtr spBlkPtr);

  /**
  \brief SFindSInfoRecPtr Return pointer to the sInfoRecord

  <pre>SFindSInfoRecPtr returns a pointer to the sInfoRecord identified by
spSlot. Used only by the Operating System.
spBlkPtr is the address of a 56-byte Slot Parameter Block structure.
The relevant fields are as follows:
Out-In Name Type SizeOffsetDescription
← spResult long 40FUNCTION result
→spSlot char 149Slot number
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
smEmptySlot (-300) No card in slot.
smCRCFail (-301) CRC check failed.
smFormatErr (-302) FHeader format is not Apple's
smRevisionErr (-303) The revision of the card's declaration ROM is wrong.
smNoDir (-304) Directory offset is NIL
smNosInfoArray (-306) The SDM could not allocate memory for the sInfo
array.
smResrvErr (-307) A reserved field of the declaration ROM was used.
smUnExBusErr (-308) An unexpected bus error occurred.
smBLFieldBad (-309) A valid ByteLanes field was not found.
smDisposePErr (-312) An error occurred during execution of DisposPointer.
smNoBoardSRsrc (-313) There is no board sResource.
smGetPRErr (-314) Error during execution of sGetPRAMRec.
smNoBoardId (-315) There is no board ID.
smInitStatVErr (-316) The InitStatus_V field was negative after Primary or
Secondary Init.
smInitTblVErr (-317) Error while trying to initialize the sResource Table.
smNoJmpTbl (-318) Slot Manager jump table could not be created
smBadBoardId (-319) Board ID was wrong; reinit the PRAM record
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 SFindSInfoRecPtr(__A0)
#endif
  OSErr
  SFindSInfoRecPtr(SpBlockPtr spBlkPtr);

  /**
  \brief Return pointer to sRsrc list

  <pre>SFindSRsrcPtr returns a pointer to the sRsrc list for the sRsrc identified
by spSlot, spID, and spExtDev . Used only by the Operating System.
spBlkPtr is the address of a 56-byte Slot Parameter Block structure.
The relevant fields are as follows:
Out-In Name Type SizeOffsetDescription
←spsPointer Ptr 44Structure pointer
→spID char 150sResource list ID
→spSlot char 149Slot number
Other parameters affected include:
spResult long 40FUNCTION result
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
smEmptySlot (-300) No card in slot.
smCRCFail (-301) CRC check failed.
smFormatErr (-302) FHeader format is not Apple's
smRevisionErr (-303) The revision of the card's declaration ROM is wrong.
smNoDir (-304) Directory offset is NIL
smNosInfoArray (-306) The SDM could not allocate memory for the sInfo
array.
smResrvErr (-307) A reserved field of the declaration ROM was used.
smUnExBusErr (-308) An unexpected bus error occurred.
smBLFieldBad (-309) A valid ByteLanes field was not found.
smDisposePErr (-312) An error occurred during execution of DisposPointer.
smNoBoardSRsrc (-313) There is no board sResource.
smGetPRErr (-314) Error during execution of sGetPRAMRec.
smNoBoardId (-315) There is no board ID.
smInitStatVErr (-316) The InitStatus_V field was negative after Primary or
Secondary Init.
smInitTblVErr (-317) Error while trying to initialize the sResource Table.
smNoJmpTbl (-318) Slot Manager jump table could not be created
smBadBoardId (-319) Board ID was wrong; reinit the PRAM record
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 SFindSRsrcPtr(__A0)
#endif
  OSErr
  SFindSRsrcPtr(SpBlockPtr spBlkPtr);

/**
 *  SDeleteSRTRec()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 SDeleteSRTRec(__A0)
#endif
  OSErr
  SDeleteSRTRec(SpBlockPtr spBlkPtr);

#endif /** CALL_NOT_IN_CARBON */

#if CALL_NOT_IN_CARBON

  /**
  \brief Open slot device

  <pre>OpenSlot is the same as PBOpen except that you use it when opening bus
slot devices. It sets the IMMED bit to signal an extended parameter block.
pbis the address of a parameter block. The following fields are
relevant:
Out-In Name Type SizeOffsetDescription
->ioCompletion ProcPtr 412Completion routine address (if async =TRUE)
<-ioResult OSErr 216Error Code (0=no error, 1=not done yet)
->ioNamePtr StringPtr 418Address of device driver name
<-ioRefNum short 224Receives driver reference number
->ioPermssn SignedByte 127Rd/Wrt permission (1=read, 2=write, et.al.)
Additionally, if the slot resource serves a single device, there is an extension that
includes:
->ioMix ProcPtr 428Reserved for the driver open routine
->ioFlags short 232Cleared to indicate single slot device
->ioSlot SignedByte 134Slot number for device being opened
->ioID SignedByte 135Slot resource ID
If the slot resource serves more than one device, there is an extension that includes:
->ioMix ProcPtr 428Reserved for the driver open routine
->ioFlags short 232Cleared to indicate single slot device
->ioSEBlkptr ProcPtr 434Address of external parameter block
asyncis a Boolean value. Use FALSE for normal (synchronous) operation
or TRUE to enqueue the request and resume control immediately. See
Async I/O .
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
badUnitErr (-21) refNum doesn't match unit table
unitEmptyErr (-22) refNum specifies NIL handle in unit table
openErr (-23) Requested Read/Write permission and the driver's Open t
permissions don't match
dInstErr (-26) Couldn't find driver in resource file
</pre>
* \note <pre>OpenSlot opens a bus-based slot device driver when used by the Device
Manager . Other than that, it is the equivalent of PBOpen
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
  OSErr
  OpenSlot(ParmBlkPtr paramBlock, Boolean async);

/**
 *  OpenSlotSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 OpenSlotSync(__A0)
#endif
  OSErr
  OpenSlotSync(ParmBlkPtr paramBlock);

/**
 *  OpenSlotAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 OpenSlotAsync(__A0)
#endif
  OSErr
  OpenSlotAsync(ParmBlkPtr paramBlock);

  /**  Device Manager Slot Support  */

  /**
  \brief Add a new element to the interrupt queue

  <pre>SIntInstall adds a new element to the interrupt queue for a particular card
slot on the bus
sIntQElemPtr points to the element being added to the interrupt queue for a given
slot.
theSlotis the location on the bus where the new element is being installed
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
slotNumErr (-360)   invalid slot # error
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 SIntInstall(__A0, __D0)
#endif
  OSErr
  SIntInstall(SQElemPtr sIntQElemPtr, short theSlot);

  /**
  \brief Remove an element from the interrupt queue

  <pre>SIntRemove removes an element from the interrupt queue for a particular
card slot on the bus.
sIntQElemPtr points to the element being removed from the interrupt queue for a
given slot.
theSlotis the location on the bus where the element is being removed
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
slotNumErr (-360)   invalid slot # error
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 SIntRemove(__A0, __D0)
#endif
  OSErr
  SIntRemove(SQElemPtr sIntQElemPtr, short theSlot);

  /**
  \brief Return the version number of the Slot Manager

  <pre>SVersion returns the version number of the Slot Manager in the
splResuklt field.
spBlkPtr is the address of a 56-byte Slot Parameter Block structure.
The relevant fields are as follows:
Out-In Name Type SizeOffsetDescription
←spResult long 40Slot Manager version number
←spsPointer Ptr 44Structure pointer
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
</pre>
* \note <pre>The SVersion function returns the version number of the
Slot Manager in the spResult field. The system 7.0 or later
Slot Manager returns version number 1 for a RAM-based
Slot Manager and version number 2 for a ROM-based
Slot Manager . Older versions of the Slot Manager do not recognize the
SVersion function and return the nonfatal error:
smSelOOBErr (-338) Selector out of bounds; function not implemented
The SVersion function returns a pointer to additional information, if any,
in the spsPointer field.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 SVersion(__A0)
#endif
  OSErr
  SVersion(SpBlockPtr spBlkPtr);

/**
 *  SetSRsrcState()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 SetSRsrcState(__A0)
#endif
  OSErr
  SetSRsrcState(SpBlockPtr spBlkPtr);

/**
 *  InsertSRTRec()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 InsertSRTRec(__A0)
#endif
  OSErr
  InsertSRTRec(SpBlockPtr spBlkPtr);

/**
 *  SGetSRsrc()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 SGetSRsrc(__A0)
#endif
  OSErr
  SGetSRsrc(SpBlockPtr spBlkPtr);

  /**
  \brief Return information about a matching sResource

  <pre>SGetTypeSRsrc returns information either about the next sResource data
structure of the matching type it finds in the same slot or about the next
sResource data structure of the matching type it finds in any higher-numbered
slot.
spBlkPtr is the address of a 56-byte Slot Parameter Block structure.
The relevant fields are as follows:
Out-In Name Type SizeOffsetDescription
←spsPointer Ptr 44Structure pointer
↔spParamData long 424input: fall, foneslot flags
output: sResource enabled or disabled
←spRefNum short 238Slot Resource Table RefNum
↔spCategory short 240sResource_Type: Category field
↔spCType short 242sResource_Type: cType field
↔spDrvrSW short 244sResource_Type: DrvrSW field
↔spDrvrHW short 246sResource_Type: DrvrHW field
→spTBMask char 148type bit mask
↔spSlot char 149Slot number
↔spID char 150ID of the sResource
↔spExtDev char 151ID of external device
←spHWDev char 152ID of hardware device
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
noErr (0) No error
</pre>
* \note <pre>When you specify an sResource data structure and specify which
resource-type fields to match, the SGetTypeSRsrc function returns
information either about the next sResource data structure of the matching
type it finds in the same slot or about the next sResource data structure of
the matching type it finds in any higher-numbered slot. It performs the
same function as the SNextTypeSRsrc function except that for the
SGetTypeSRsrc function, you set the fall and foneslot flags to specify
which type of search the function is to perform.
You specify an sResource data structure with the spSlot, spID, and
spExtDev fields. You must also use the spTBMask field to specify which
fields of the sRsrcType entry in the sResource data structure should not be
included in the search, as follows:
•Set bit 0 to ignore the DrvrHW field.
•Set bit 1 to ignore the DrvrSW field.
•Set bit 2 to ignore the cType field.
•Set bit 3 to ignore the Category field.
In addition, you must clear the fall flag of the spParamData field (bit 0) to
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 SGetTypeSRsrc(__A0)
#endif
  OSErr
  SGetTypeSRsrc(SpBlockPtr spBlkPtr);

/**
 *  SGetSRsrcPtr()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 SGetSRsrcPtr(__A0)
#endif
  OSErr
  SGetSRsrcPtr(SpBlockPtr spBlkPtr);

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

#endif /** __SLOTS__ */
* /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ */*/