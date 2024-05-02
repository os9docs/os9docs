/**
     \file       FSM.h

    \brief   HFS External File System Interfaces.

    \introduced_in  Mac OS 9
    \avaliable_from Universal Interfaces 3.4.1

    \copyright � 1985-2001 by Apple Computer, Inc., all rights reserved

    \defgroup File

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __FSM__
#define __FSM__

#ifndef __FILES__
#include <Files.h>
#endif

#ifndef __HFSVOLUMES__
#include <HFSVolumes.h>
#endif

#ifndef __PROCESSES__
#include <Processes.h>
#endif

#ifndef __MACERRORS__
#include <MacErrors.h>
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

  // VolMount declarations are now in Files.� 
  /**
   * Miscellaneous file system values not in Files.�
   */
  enum
  {
    fsUsrCNID = 16, // First assignable directory or file number                     //    File system trap word attribute bits     kHFSBit = 9,    // HFS call: bit 9     kHFSMask = 0x0200,
    kAsyncBit = 10, // First assignable directory or file number 
  };//    File system trap word attribute bits 
// HFS call: bit 9 
  /**
   * HFSCIProc selec// Asynchronous call: bit 10 
   * Note: The trap attribute bits (the HFS bit and the asynchronous bit)
   * may be set in these selectCode values.
   */
  enum
  {
    kFSMOpen = 0xA000,
    kFSMClose = 0xA001,
    kFSMRead = 0xA002,
    kFSMWrite = 0xA003,
    kFSMGetVolInfo = 0xA007,
    kFSMCreate = 0xA008,
    kFSMDelete = 0xA009,
    kFSMOpenRF = 0xA00A,
    kFSMRename = 0xA00B,
    kFSMGetFileInfo = 0xA00C,
    kFSMSetFileInfo = 0xA00D,
    kFSMUnmountVol = 0xA00E,
    kFSMMountVol = 0xA00F,
    kFSMAllocate = 0xA010,
    kFSMGetEOF = 0xA011,
    kFSMSetEOF = 0xA012,
    kFSMFlushVol = 0xA013,
    kFSMGetVol = 0xA014,
    kFSMSetVol = 0xA015,
    kFSMEject = 0xA017,
    kFSMGetFPos = 0xA018,
    kFSMOffline = 0xA035,
    kFSMSetFilLock = 0xA041,
    kFSMRstFilLock = 0xA042,
    kFSMSetFilType = 0xA043,
    kFSMSetFPos = 0xA044,
    kFSMFlushFile = 0xA045, //    The File System HFSDispatch selectCodes     kFSMOpenWD = 0x0001,
    kFSMCloseWD = 0x0002,
    kFSMCatMove = 0x0005,
    kFSMDirCreate = 0x0006,
    kFSMGetWDInfo = 0x0007,
    kFSMGetFCBInfo = 0x0008,//    The File System HFSDispatch selectCodes 
    kFSMGetCatInfo = 0x0009,
    kFSMSetCatInfo = 0x000A,
    kFSMSetVolInfo = 0x000B,
    kFSMLockRng = 0x0010,
    kFSMUnlockRng = 0x0011,
    kFSMXGetVolInfo = 0x0012,
    kFSMCreateFileIDRef = 0x0014,
    kFSMDeleteFileIDRef = 0x0015,
    kFSMResolveFileIDRef = 0x0016,
    kFSMExchangeFiles = 0x0017,
    kFSMCatSearch = 0x0018,
    kFSMOpenDF = 0x001A,
    kFSMMakeFSSpec = 0x001B, //    The Desktop Manager HFSDispatch selectCodes     kFSMDTGetPath = 0x0020,
    kFSMDTCloseDown = 0x0021,
    kFSMDTAddIcon = 0x0022,
    kFSMDTGetIcon = 0x0023,
    kFSMDTGetIconInfo = 0x0024,
    kFSMDTAddAPPL = 0x0025,
    kFSMDTRemoveAPPL = 0x0026//    The Desktop Manager HFSDispatch selectCodes 
    kFSMDTGetAPPL = 0x0027,
    kFSMDTSetComment = 0x0028,
    kFSMDTRemoveComment = 0x0029,
    kFSMDTGetComment = 0x002A,
    kFSMDTFlush = 0x002B,
    kFSMDTReset = 0x002C,
    kFSMDTGetInfo = 0x002D,
    kFSMDTOpenInform = 0x002E,
    kFSMDTDelete = 0x002F, //    The AppleShare HFSDispatch selectCodes     kFSMGetVolParms = 0x0030,
    kFSMGetLogInInfo = 0x0031,
    kFSMGetDirAccess = 0x0032,
    kFSMSetDirAccess = 0x0033,
    kFSMMapID = 0x0034,
    kFSMMapName = 0x0035,
    kFSMCopyFile = 0x0036,
    kFSMMoveRename = 0x0037//    The AppleShare HFSDispatch selectCodes 
    kFSMOpenDeny = 0x0038,
    kFSMOpenRFDeny = 0x0039,
    kFSMGetXCatInfo = 0x003A,
    kFSMGetVolMountInfoSize = 0x003F,
    kFSMGetVolMountInfo = 0x0040,
    kFSMVolumeMount = 0x0041,
    kFSMShare = 0x0042,
    kFSMUnShare = 0x0043,
    kFSMGetUGEntry = 0x0044,
    kFSMGetForeignPrivs = 0x0060,
    kFSMSetForeignPrivs = 0x0061, // The HFSPlus API SelectCodes (below)    kFSMGetVolumeInfo = 0x001D,   // Dispatched by ioVRefNum and volumeIndex     kFSMSetVolumeInfo = 0x001E,   // Dispatched by ioVRefNum     kFSMReadFork =
        0x0051, // Fork I/O calls dispatched by forkRefNum (ioRefNum)     kFSMWriteFork = 0x0052,
    kFSMGetForkPosition = 0x0053,
    kFSMSetForkPosition = 0x0054,
    kFSMGetForkSize = 0x0055,
    kFSMSetForkSize = 0x0056,
    kFSMAllocateFork = 0x0057,
    kFSMFlushFork = 0x0058,
    kFSMCloseFork = 0x0059,// The HFSPlus API SelectCodes (below)
    kFSMGetForkCBInfo = 0x005A,// Dispatched by ioVRefNum and volumeIndex 
    kFSMCloseIterator = 0x005B,   // Dispatched by ioVRefNum 
                                        bytes of "iterator", */
    kFSMGetCatal// Fork I/O calls dispatched by forkRefNum (ioRefNum) 
                                        convention, the lower two */
    kFSMCatalogSearch = 0x005D,      /* bytes of the FSIterator are zero, though this
                                        is not enforced. */
    kFSMMakeFSRef = 0x006E,          // Dispatched by ioVRefNum/ioDirID/ioNamePtr     kFSMCreateFileUnicode =
        0x0070,                    // FSRef dispatched calls.  The first two bytes of an FSRef     kFSMCreateDirUnicode = 0x0071, /* are a volume reference number (not a working
                                      directory reference */
    kFSMDeleteObject = 0x0072,     /* number or drive number).  The remaining bytes of
                                      the FSRef are */
    kFSMMoveObject = 0x0073,       // defined by that particular volume format.     kFSMRenameUnicode = 0x0074,
    kFSMExchangeObjects = 0x0075,
    kFSMGetCatalogInfo = 0x0076,
    kFSMSetCatalogInfo = 0x0077,
    kFSMOpenIterator = 0x0078,
    kFSMOpenFork = 0x0079,
    kFSMMakeFSRefUnicode = 0x007A,
    kFSMCompareFSRefs = 0x007C,// Dispatched by ioVRefNum/ioDirID/ioNamePtr 
    kFSMCreateFork = 0x007D,
    kFSMDeleteFork = 0x007E,// FSRef dispatched calls.  The first two bytes of an FSRef 
    kFSMIterateForks = 0x007F
  };

  /**
   * UTDetermineVol status values// defined by that particular volume format. 
   */
  enum
  {
    dtmvError = 0,        // param error     dtmvFullPathname = 1, // determined by full pathname     dtmvVRefNum = 2,      // determined by volume refNum     dtmvWDRefNum = 3,     // determined by working directory refNum     dtmvDriveNum = 4,     // determined by drive number     dtmvDefault = 5       // determined by default volume   };

  /**
   * UTGetBlock options
   */
  enum
  {
    gbDefault = 0, // default value - read if not found                    //    bits and masks     gbReadBit = 0, // read block from disk (forced read)     gbReadMask = 0x0001,
    gbExistBit = 1, // get existing cache block     gbExistMask = 0x0002,
    gbNoReadBit = 2, // don't read block from disk if not found in cache     gbNoReadMask = 0x0004,
    gbReleaseBit = 3, // release block immediately after GetBlock     gbReleaseMask = 0x0008
  };

  /**
   * UTReleaseBlock options
   */// param error 
  enum// determined by full pathname 
  {// determined by volume refNum 
    rbDefault = 0,  // def// determined by working directory refNum 
    rbTrashBit = 1, // tra// determined by drive number 
    rbDirtyBit = 2, // mar// determined by default volume 
    rbFreeBit = 3,      // free the buffer (save in the hash)     rbFreeMask = 0x000A /* rbFreeMask (rbFreeBit + rbTrashBit) works as rbTrash on
                           < System 7.0 RamCache; on >= System 7.0, rbfreeMask
                           overrides rbTrash */
  };

  /**
   * UTFlushCache options
   */// default value - read if not found 
  enum//    bits and masks 
  {// read block from disk (forced read) 
    fcDefault = 0,  /* default value - pass this fcOption to just flush any dirty
                    // get existing cache block 
                    //    bits and masks     fcTrashBit = 0, // (don't pass this as fcOption, use only for testing bit)     fcTrashMask =
        0x0001,      // don't read block from disk if not found in cache 
                           (Note: both fcTrash and fcFree bits are set) */
  };// release block immediately after GetBlock 

  /**
   * UTCacheReadIP and UTCacheWriteIP cacheOption bits and masks are the ioPosMode
   * bits and masks in Files.x
   */

  /**
   * Cache routine internal error codes
   */// default value - just mark the buffer not in-use 
  enum//    bits and masks 
  {// force write buffer to disk 
    chNoBuf = 1,    // no free cache buffers (all in use)     chInUse = 2,    // requested block in use     chnotfound = 3, // requested block not found     chNotInUse = 4  // block being released was not in use   };
// trash buffer contents after release 
  /**
   * FCBRec.fcbFlags// mark buffer dirty 
   */
  enum// free the buffer (save in the hash) 
  {
    fcbWriteBit = 0, // Data can be written to this file     fcbWriteMask = 0x01,
    fcbResourceBit = 1, // This file is a resource fork     fcbResourceMask = 0x02,
    fcbWriteLockedBit = 2, // File has a locked byte range     fcbWriteLockedMask = 0x04,
    fcbLargeFileBit =
        3, // File may grow beyond 2GB; cache uses file blocks, not bytes     fcbLargeFileMask = 0x08,
    fcbSharedWriteBit = 4, // File is open for shared write access     fcbSharedWriteMask = 0x10,
    fcbFileLockedBit = 5, // File is locked (write-protected)     fcbFileLockedMask = 0x20,
    fcbOwnClumpBit = 6, // File has clump size specified in FCB     fcbOwnClumpMask = 0x40,
    fcbModifiedBit = 7, // File has changed since it was last flushed     fcbModifiedMask = 0x80
  };

  /**//    bits and masks 
   *  ForkControlBlo// (don't pass this as fcOption, use only for testing bit) 
   */
  enum// pass this fcOption value to flush and trash cache blocks 
  {// (don't pass this as fcOption, use only for testing bit) 
    fcbIteratorBit = 0, // FCB belongs to an FSIterator     fcbIteratorMask = 0x0001,
    fcbUseForkIDBit = 1, // Use the FCB's forkID instead of fcbResourceBit     fcbUseForkIDMask = 0x0002
  };

  /**
   *  HFS Component Interface constants
   */

  /**
   * compInterfMask bits specific to HFS component
   */
  enum
  {
    hfsCIDoesHFSBit = 23, // set if file system supports HFS calls     hfsCIDoesHFSMask = 0x00800000,
    hfsCIDoesAppleSh// no free cache buffers (all in use) 
    hfsCIDoesDeskTop// requested block in use 
    hfsCIDoesDynamic// requested block not found 
    hfsCIHasHLL2PPro// block being released was not in use 
        0x00040000, /* is written in a high level language. (i.e., uses Pascal
                       calling convention) */
    hfsCIWantsDTSupportBit =
        17, // set if FFS wants the Mac OS's Desktop Manager code to handle     hfsCIWantsDTSupportMask =
        0x00020000 // all Desktop Manager requests to its volumes.   };

  /**
   *  Disk Initializa// Data can be written to this file 
   */
// This file is a resource fork 
  /**
   * compInterfMask bits sp// File has a locked byte range 
   */
  enum
  {// File may grow beyond 2GB; cache uses file blocks, not bytes 
    diCIHasExtFormatParamsBit = 18,          // set if file system needs extended format     diCIHasExtFormatParamsMask = 0x00040000, //       parameters     diCIHasMultiVolTypesBit = 17,            // set if file system supports more than one     diCIHasMultiVolTypesMask = 0x00020000,   //       volume type     diCIDoesSparingBit = 16,                 // set if file system supports disk sparing     diCIDoesSparingMask = 0x00010000,
    diCILiveBit = 0,       // File is open for shared write access 

  /**// File is locked (write-protected) 
   * Disk Initialization Component Function selectors
   */// File has clump size specified in FCB 
  enum
  {// File has changed since it was last flushed 
    diCILoad = 1,                // Make initialization code memory resident     diCIUnload = 2,              // Make initialization code purgeable     diCIEvaluateSizeChoices = 3, // Evaluate size choices     diCIExtendedZero = 4,        // Write an empty volume directory     diCIValidateVolName = 5,     // Validate volume name     diCIGetVolTypeInfo = 6,      // get volume type info     diCIGetFormatString = 7,     // get dialog format string     diCIGetExtFormatParams = 8,  // get extended format parameters     diCIGetDefectList = 9        /* return the defect list for the indicated disk -
                                    reserved for future use */
  };

  /**
   * Constants used in the DICIEvaluateSizeRec and FormatListRec
   */
  enum
  {// FCB belongs to an FSIterator 
    diCIFmtListMax = 8,       /* maximum number of format list entries in
                         // Use the FCB's forkID instead of fcbResourceBit 
                              //    bits in FormatListRec.formatFlags:     diCIFmtFlagsValidBit = 7, // set if sec, side, tracks valid     diCIFmtFlagsValidMask = 0x80,
    diCIFmtFlagsCurrentBit = 6,     // set if current disk has this fmt     diCIFmtFlagsCurrentMask = 0x40, //    bits in FormatListRec.sizeListFlags:     diCISizeListOKBit = 15,         // set if this disk size usable     diCISizeListOKMask = 0x8000
  };

  /**
   * DICIGetFormatStringRec.stringKind format strings
   */
  enum
  {
    diCIAlternateFormatStr = 1, // get alternate format  string (Balloon Help)     diCISizePresentationStr = 2 // get size presentation string (for dialog)   };

  /**
   * Error codes returned // set if file system supports HFS calls 
   */
  enum// set if AppleShare calls supported 
  {
    diCIUserCancelErr = 1,    // set if Desktop Database calls supported 
                                      paramBlock is not supported */
    diCIVolSizeMismatchErr =// set if dynamically loading code resource 
        24,                    // specified//       supported 
        26,                   // disk is ba// set if code resource already loaded 
                                 diCIExtendedZero call */
    diCINoMessageTextErr = 28 /// set if FFS' log2PhyProc 

  /**
   *  File System Manager constants
   */
// set if FFS wants the Mac OS's Desktop Manager code to handle 
  /**
   * Miscellaneous // all Desktop Manager requests to its volumes. 
   */
  enum
  {
    fsdVersion1 = 1,        // current version of FSD record     fsmIgnoreFSID = 0xFFFE, // this FSID should be ignored by the driver     fsmGenericFSID = 0xFFFF // unknown foreign file system ID   };

  /**
   * compInterfMask bits common to all FSM components
   */
  enum
  {
    fsmComponentEnableBit = 31, // set if FSM component interface is enabled     fsmComponentEnableMask = (long)0x80000000,
    fsmComponentBusyBit = 30, // set if FSM c// set if file system needs extended format 
  };//       parameters 
// set if file system supports more than one 
  /**//       volume type 
   * Selectors for GetFSInfo// set if file system supports disk sparing 
   */
  enum// set if file system is candidate for current 
  {//       formatting operation (set by PACK2) 
    fsmGetFSInfoByIndex = -1, // get fs info by index     fsmGetFSInfoByFSID = 0,   // get fs info by FSID     fsmGetFSInfoByRefNum = 1  // get fs info by file/vol refnum   };

  /**
   * InformFSM messages
   */
  enum
  {
    fsmNopMessage = 0,           // Make initialization code memory resident 
// Make initialization code purgeable 
  /**// Evaluate size choices 
   * Messages passed to the fileS// Write an empty volume directory 
   */// Validate volume name 
  enum// get volume type info 
  {// get dialog format string 
    ffsNopMessage = 0,        // // get extended format parameters 
  };

  /**
   *  HFS Utility routine records
   */

  /**
   * record used by UTGetPathComponentName
   */
  struct ParsePathRec
  {
    StringPtr namePtr;     // //    bits in FormatListRec.formatFlags: 
        moreName;             // set if sec, side, tracks valid 
                                  delimiter was found */
  };// set if current disk has this fmt 
  typedef struct ParsePathRec ParseP//    bits in FormatListRec.sizeListFlags: 
  typedef ParsePathRec *ParsePathRec// set if this disk size usable 
  struct WDCBRec
  {
    VCBPtr wdVCBPtr; // Pointer to VCB of this working directory     long wdDirID;    // Directory ID number of this working directory     long wdCatHint;  // Hint for finding this working directory     long wdProcID;   // Process that created this working directory   };
  typedef struct WDCBRec WDCBRec;
  typedef WDCBRec *WDCBRecPtr;
  struct FCBRec
  {
    unsigned long fcbFlNm;     // FCB file number. Non-zero marks FCB used     SignedByte fcbFlags;       // FCB flags     SignedByte fcbTypByt;      // File type byte     unsigned short fcbSBlk;    // File start block (in alloc size blks)     unsigned long fcbEOF;      // Logical length or EOF in bytes     unsigned long fcbPLen;     // Physical file length in bytes     unsigned long fcbCrPs;     // Current position within file     VCBPtr fcbVPtr;            // Pointer to the corresponding VCB     Ptr fcbBfAdr;              // File's buffer address     unsigned short fcbFlPos;   // Directory block this file is in                                // FCB Extensions for HFS     unsigned long fcbClmpSize; // Number of bytes per clump     Ptr fcbBTCBPtr;            // Pointer to B*-Tree control block for file     HFSExtentRecord fcbExtRec; // First 3 file extents     OSType fcbFType;           // File's 4 Finder Type bytes     unsigned long fcbCatPos;   // Catalog hint for use on Close     unsigned long fcbDirID;    // Parent Directory ID     Str31 fcbCName;            // CName of open file   };
  typedef struct FCBRec FCBRec;// get alternate format  string (Balloon Help) 
  typedef FCBRec *FCBRecPtr;// get size presentation string (for dialog) 
  struct ForkControlBlock
  {
    unsigned long fcbFlNm;     // FCB file number. Non-zero marks FCB used     SignedByte fcbFlags;       // FCB flags     SignedByte fcbTypByt;      // File type byte     unsigned short fcbSBlk;    // File start block (in alloc size blks)     unsigned long fcbEOF;      // Logical length or EOF in bytes     unsigned long fcbPLen;     // Physical file length in bytes     unsigned long fcbCrPs;     // Current position within file     VCBPtr fcbVPtr;            // Pointer to the corresponding VCB     Ptr fcbBfAdr;              // File's buffer address     unsigned short fcbFlPos;   // Directory block this file is in                                // FCB Extensions for HFS     unsigned long fcbClmpSize; // Number of bytes per clump     Ptr fcbBTCBPtr;            // Pointer to B*-Tree control block for file     HFSExtentRecord fcbExtRec; // First 3 file extents     OSType fcbFType;           // File's 4 Finder Type bytes     unsigned long fcbCatPos;   // Catalog hint for use on Close     unsigned long fcbDirID;    // Parent Directory ID     Str31 fcbCName;            // CName of open file 
    //    New fields start here
    unsigned short moreFlags; // more flags, align following fields
    //    Old ExtendedFCB fields
    ProcessSerialNumber processID; /* Process Mgr process that opened the file
                                   // user cancelled the disk init 
    HFSPlusExtentRecord extents;   // critical sectors are bad (hopeless)    
    //    New fields for HFS Plus A// disk cannot be spared 
    UInt64 endOfFile;       // logi// too many bad sectors 
    Ptr searchListPtr;  // reserved for File Manager's use    UInt8 reserved1[8]; // reserved  };
  typedef struct ForkControlBlock ForkControlBlock;
  typedef ForkControlBlock *ForkControlBlockPtr;
  /**// specified volume size doesn�t match with formatted disk size 
   *  IteratorControlBlock - a // bogus DI function call selector 
   */
  struct IteratorControlBlock// disk is bad but the target FS doesn't do disk sparing 
  {
    unsigned long containerID;     // directory ID of iterator's container    unsigned short flags;          // reserved    UInt8 user1[14];               // 14 bytes iterator's use    VCBPtr vcbPtr;                 // pointer to the iterator's VCB    unsigned long reserved2;       // reserved    UInt8 user2[6];                // 6 bytes for iterator's use    unsigned long reserved3;       // reserved    UInt8 user3[12];               // 12 bytes for iterator's use    OSType cbType;                 // must be 'fold'    UInt8 user4[40];               // 40 bytes for iterator's use    unsigned short moreFlags;      // must be fcbIteratorMask    ProcessSerialNumber processID; /* Process Mgr process that opened the iterator
                              // missing message text in DIReformat call 
    UInt8 user5[92];               // 92 bytes for iterator's use    Ptr searchListPtr;             // reserved for File Manager's use    UInt8 reserved1[8];            // reserved  };
  typedef struct IteratorControlBlock IteratorControlBlock;
  typedef IteratorControlBlock *IteratorControlBlockPtr;
  /**
   *  HFS Component Interface records
   */
  typedef CALLBACK_API(OSErr, Lg2PhysProcPtr)(
      void *fsdGlobalPtr, VCBPtr volCtrlBlockPtr, FCBRecPtr fileCtrlBlockPtr,
      short fileRefNum, unsigned long filePosition, unsigned long reqCount,
      unsigned long *volOffset, unsigned long *contiguousBytes);
  typedef STACK_UPP_TYPE(Lg2PhysProcPtr) Lg2PhysUPP;
#if CALL_NOT_IN_CARBON// current version of FSD record 
  /**// this FSID should be ignored by the driver 
   *  NewLg2PhysUPP()// unknown foreign file system ID 
   *
   *  Availability:
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  Lg2PhysUPP
  NewLg2PhysUPP(Lg2PhysProcPtr u// set if FSM component interface is enabled 
#if !OPAQUE_UPP_TYPES
  enum// set if FSM component interface is busy 
  {
    uppLg2PhysProcInfo = 0x003FEFE0
  }; /* pascal 2_bytes Func(4_bytes, 4_bytes, 4_bytes, 2_bytes, 4_bytes, 4_bytes,
        4_bytes, 4_bytes) */
#ifdef __cplusplus
  inline Lg2PhysUPP NewLg2PhysUPP(Lg2PhysProcPtr userRoutine)
  {
    return (Lg2PhysUPP)NewRoutineDescriptor(
        (ProcPtr)(userRoutine)// get fs info by index 
  }// get fs info by FSID 
#else// get fs info by file/vol refnum 
#define NewLg2PhysUPP(userRoutine)   \
  (Lg2PhysUPP) NewRoutineDescriptor( \
      (ProcPtr)(userRoutine), uppLg2PhysProcInfo, GetCurrentArchitecture())
#endif
#endif

  /**
   *  DisposeLg2PhysUPP()// nop 
   *// DQE has changed 
   *  Availability:// Get FFS's disk icon 
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  DisposeLg2PhysUPP(Lg2PhysUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus// nop, should always return noErr 
  inline void DisposeLg2PhysUP// return disk icon and mask 
  {// identify the about-to-be-mounted volume 
    DisposeRoutineDescriptor((// load in the FFS 
  }// unload the FFS 
#else// identify a VolMountInfo record 
#define DisposeLg2PhysUPP(user// FFS defined message 
#endif
#endif

  /**
   *  InvokeLg2PhysUPP()
   *
   *  Availability:
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  InvokeLg2PhysUPP(void *fs// pathname to parse 
                   FCBRecPt// where to start parsing 
                   unsigned// the length of the pathname component parsed 
                   unsigned long *volOffset, unsigned long *contiguousBytes,
                   Lg2PhysUPP u// non-zero if there are more components after this one 
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline OSErr InvokeLg2PhysUPP(void *fsdGlobalPtr, VCBPtr volCtrlBlockPtr,
                                FCBRecPtr fileCtrlBlockPtr, short fileRefNum,
                                unsigned long filePosition,
                                unsigned long reqCount, unsigned long *volOffset,
                                unsigned long *contiguousBytes,
                     // Pointer to VCB of this working directory 
  {// Directory ID number of this working directory 
    return (OSErr)CAL// Hint for finding this working directory 
        userUPP, uppL// Process that created this working directory 
        fileCtrlBlockPtr, fileRefNum, filePosition, reqCount, volOffset,
        contiguousBytes);
  }
#else
#define InvokeLg2PhysUPP(fsdGlobalPtr, volCtrlBlockPtr, fileCtrlBlockPtr, \
                         fileRe// FCB file number. Non-zero marks FCB used 
                         contig// FCB flags 
  (OSErr) CALL_EIGHT_PARAMETER_// File type byte 
      (userUPP), uppLg2PhysProc// File start block (in alloc size blks) 
      (fileCtrlBlockPtr), (file// Logical length or EOF in bytes 
      (volOffset), (contiguousB// Physical file length in bytes 
#endif// Current position within file 
#endif// Pointer to the corresponding VCB 
// File's buffer address 
#endif // CALL_NOT_IN_CARBON // Directory block this file is in 
#if CALL_NOT_IN_CARBON || OLDRO// FCB Extensions for HFS 
// support for pre-Carbon UPP r// Number of bytes per clump 
#define CallLg2PhysProc(userRou// Pointer to B*-Tree control block for file 
                        fileCtr// First 3 file extents 
                        volOffs// File's 4 Finder Type bytes 
  InvokeLg2PhysUPP(fsdGlobalPtr// Catalog hint for use on Close 
                   fileRefNum, // Parent Directory ID 
                   contiguousBy// CName of open file 
#endif // CALL_NOT_IN_CARBON 
  typedef CALLBACK_API(OSErr, HFSCIProcPtr)(VCBPtr theVCB, short selectCode,
                                            void *paramBlock, void *fsdGlobalPtr,
                                            short fsid);
  typedef STACK_UPP_TYPE(HFSCIProcPtr) HFSCIUPP;
#if CALL_NOT_IN_CARBON// FCB file number. Non-zero marks FCB used 
  /**// FCB flags 
   *  NewHFSCIUPP()// File type byte 
   *// File start block (in alloc size blks) 
   *  Availability:// Logical length or EOF in bytes 
   *    \non_carbon_cfm   avail// Physical file length in bytes 
   *    \carbon_lib        not // Current position within file 
   *    \mac_os_x         not a// Pointer to the corresponding VCB 
   */// File's buffer address 
  HFSCIUPP// Directory block this file is in 
  NewHFSCIUPP(HFSCIProcPtr user// FCB Extensions for HFS 
#if !OPAQUE_UPP_TYPES// Number of bytes per clump 
  enum// Pointer to B*-Tree control block for file 
  {// First 3 file extents 
    uppHFSCIProcInfo = 0x0000BE// File's 4 Finder Type bytes 
  }; // pascal 2_bytes Func(4_b// Catalog hint for use on Close 
  inline HFSCIUPP NewHFSCIUPP(H// Parent Directory ID 
  {// CName of open file 
    return (HFSCIUPP)NewRoutineDescriptor(
    //    New fields start here
  }
#else// more flags, align following fields
#define NewHFSCIUPP(userRoutine)                                            \
  (H//    Old ExtendedFCB fields
                                  GetCurrentArchitecture())
#endif
#endif
// extents for HFS+ volumes
  /**
   *//    New fields for HFS Plus APIs
   *
   *  Availability:// logical size of this fork
   *    \non_carbon_cfm   av// amount of space physically allocated to this fork
   *    \carbon_lib        n// default offset for next read/write
   *    \mac_os_x         not available
   */// reserved for File Manager's use
  void// reserved
  DisposeHFSCIUPP(HFSCIUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeHFSCIUPP(HFSCIUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeHFSCIUPP(userUPP) Di// directory ID of iterator's container
#endif// reserved
#endif// 14 bytes iterator's use
// pointer to the iterator's VCB
  /**// reserved
   *  InvokeHFSCIUPP()// 6 bytes for iterator's use
   *// reserved
   *  Availability:// 12 bytes for iterator's use
   *    \non_carbon_cfm   available// must be 'fold'
   *    \carbon_lib        not avai// 40 bytes for iterator's use
   *    \mac_os_x         not avail// must be fcbIteratorMask
   */
  OSErr
  InvokeHFSCIUPP(VCBPtr theVCB, sho// 92 bytes for iterator's use
                 void *fsdGlobalPtr// reserved for File Manager's use
#if !OPAQUE_UPP_TYPES// reserved
#ifdef __cplusplus
  inline OSErr InvokeHFSCIUPP(VCBPtr theVCB, short selectCode, void *paramBlock,
                              void *fsdGlobalPtr, short fsid, HFSCIUPP userUPP)
  {
    return (OSErr)CALL_FIVE_PARAMETER_UPP(userUPP, uppHFSCIProcInfo, theVCB,
                                          selectCode, paramBlock, fsdGlobalPtr,
                                          fsid);
  }
#else
#define InvokeHFSCIUPP(theVCB, selectCode, paramBlock, fsdGlobalPtr, fsid,    \
                       userUPP)                                               \
  (OSErr) CALL_FIVE_PARAMETER_UPP((userUPP), uppHFSCIProcInfo, (theVCB),      \
                                  (selectCode), (paramBlock), (fsdGlobalPtr), \
                                  (fsid))
#endif
#endif

#endif // CALL_NOT_IN_CARBON 
#if CALL_NOT_IN_CARBON || OLDROUTINENAMES
// support for pre-Carbon UPP routines: New...Proc and Call...Proc #define NewHFSCIProc(userRoutine) NewHFSCIUPP(userRoutine)
#define CallHFSCIProc(userRoutine, theVCB, selectCode, paramBlock,   \
                      fsdGlobalPtr, fsid)                            \
  InvokeHFSCIUPP(theVCB, selectCode, paramBlock, fsdGlobalPtr, fsid, \
                 userRoutine)
#endif // CALL_NOT_IN_CARBON 
  struct HFSCIRec
  {
    long compInterfMask;     // component flags     HFSCIUPP compInterfProc; // pointer to file system call processing code     Lg2PhysUPP log2PhyProc;  // pointer to Lg2PhysProc() code     Ptr stackTop;            // file system stack top     long stackSize;          // file system stack size     Ptr stackPtr;            // current file system stack pointer     long reserved3;          // --reserved, must be zero--     long idSector;           /* Sector you need to ID a local volume. For networked volumes,
                                this must be -1 */
    long reserved2;          // --reserved, must be zero--     long reserved1;          // --reserved, must be zero--   };
  typedef struct HFSCIRec HFSCIRec;
  typedef HFSCIRec *HFSCIRecPtr;
  /**
   *  Disk Initialization Component Interface records
   */
  typedef CALLBACK_API(OSErr, DICIProcPtr)(short whatFunction, void *paramBlock,
                                           void *fsdGlobalPtr);
  typedef STACK_UPP_TYPE(DICIProcPtr) DICIUPP;
#if CALL_NOT_IN_CARBON
  /**
   *  NewDICIUPP()
   *
   *  Availability:
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  DICIUPP
  NewDICIUPP(DICIProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppDICIProcInfo = 0x00000FA0
  }; // pascal 2_bytes Func(2_bytes, 4_bytes, 4_bytes) #ifdef __cplusplus
  inline DICIUPP NewDICIUPP(DICIProcPtr userRoutine)
  {
    return (DICIUPP)NewRoutineDescriptor((ProcPtr)(userRoutine), uppDICIProcInfo,
                                         GetCurrentArchitecture());
  }
#else
#define NewDICIUPP(userRoutine)                                           \
  (DICIUPP) NewRoutineDescriptor((ProcPtr)(userRoutine), uppDICIProcInfo, \
                                 GetCurrentArchitecture())
#endif
#endif

  /**
   *  DisposeDICIUPP()
   *
   *  Availability:
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  DisposeDICIUPP(DICIUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeDICIUPP(DICIUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeDICIUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  InvokeDICIUPP()
   *
   *  Availability:
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  InvokeDICIUPP(short whatFunction, void *paramBlock, void *fsdGlobalPtr,
                DICIUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline OSErr InvokeDICIUPP(short whatFunction, void *paramBlock,
       // CALL_NOT_IN_CARBON 
  {
    return (OSErr)CALL_THREE_PARAMETER_UPP(userUPP, uppDICIProcInfo, whatFunction,
// support for pre-Carbon UPP routines: New...Proc and Call...Proc 
  }
#else
#define InvokeDICIUPP(whatFunction, paramBlock, fsdGlobalPtr, userUPP)         \
  (OSErr) CALL_THREE_PARAMETER_UPP((userUPP), uppDICIProcInfo, (whatFunction), \
                                   (paramBlock), (fsdGlobalPtr))
#endif
#endif
// CALL_NOT_IN_CARBON 
#endif // CALL_NOT_IN_CARBON 
#if CALL_NOT_IN_CARBON || OLDROUTINENAMES
// support for pre-Carbon UPP routines: New...Proc and Call...Proc #define NewDICIProc(userRoutine) NewDICIUPP(userRoutine)
#define CallDICIProc(userRoutine, whatFunction, paramBlock, fsdGlobalPtr) \
  InvokeDICIUPP(whatFunction, paramBlock, fsdGlobalPtr, userRoutine)
#endif // CALL_NOT_IN_CARBON 
  struct DICIRec
  {
    long compInterfMask;      // component flags     DICIUPP compInterfProc;   // pointer to call processing code     short maxVolNameLength;   // maximum length of your volume name     unsigned short blockSize; // your file system's block size     long reserved3;           // --reserved, must be zero--     long reserved2;           // --reserved, must be zero--     long reserved1;           // --reserved, must be zero--   };
  typedef struct DICIRec DICIRec;
  typedef DICIRec *DICIRecPtr;
  /**
   * FormatListRec as returned by the .Sony disk driver's
   * Return Format List status call (csCode = 6).
   * If the status call to get this list for a drive is not
   * implemented by the driver, then a list with one entry
   * is contructed from the drive queue element for the drive.
   */
  struct FormatListRec
  {
    u// pascal 2_bytes Func(4_bytes, 2_bytes, 4_bytes, 4_bytes, 2_bytes) 
  typedef struct FormatListRec FormatListRec;
  typedef FormatListRec *FormatListRecPtr;
  /**
   * SizeListRec built from FormatListRecs as described above.
   */
  struct SizeListRec
  {
    short sizeListFlags;     // flags as set by external file system     FormatListRec sizeEntry; // disk driver format list record   };
  typedef struct SizeListRec SizeListRec;
  typedef SizeListRec *SizeListRecPtr;
  /**
   * paramBlock for the diCIEvaluateSize call
   */
  struct DICIEvaluateSizeRec
  {
    short defaultSizeIndex;     // default size for this FS     short numSizeEntries;       // number of size entries     short driveNumber;          // drive number     SizeListRecPtr sizeListPtr; // ptr to size entry table     unsigned short sectorSize;  // bytes per sector   };
  typedef struct DICIEvaluateSizeRec DICIEvaluateSizeRec;
  typedef DICIEvaluateSizeRec *DICIEvaluateSizeRecPtr;
  /**
   * paramBlock for the diCIExtendedZero call
   */
  struct DICIExtendedZeroRec
  {
    short driveNumber;    // drive number     StringPtr volNamePtr; // ptr to volume name string     short fsid;           // file system ID     short
        volTypeSelector;            // volume type selector, if supports more than 1 type     unsigned short numDefectBlocks; // number of bad logical blocks     unsigned short defectListSize;  // size of the defect list buffer in bytes     Ptr defectListPtr;              // pointer to defect list buffer     unsigned long volSize;          // size of volume in SECTORs     unsigned short sectorSize;      // bytes per sector     Ptr extendedInfoPtr;            // ptr to extended info   };
  typedef struct DICIExtendedZeroRec DICIExtendedZeroRec;
  typedef DICIExtendedZeroRec *DICIExtendedZeroRecPtr;
  /**
   * paramBlock for the diCIValidateVolName call
   */
  struct DICIValidateVolNameRec
  {
    char theChar;               // the character to validate     Boolean hasMessageBuffer;   // false if no message     short charOffset;           // position of the current character (first char = 1)     StringPtr messageBufferPtr; // pointer to message buffer or nil     short charByteType;         /* theChar's byte type (smSingleByte, smFirstByte, or
                                   smLastByte) */
  };
  typedef struct DICIValidateVolNameRec DICIValidateVolNameRec;
  typedef DICIValidateVolNameRec *DICIValidateVolNameRecPtr;
  /**
   * paramBlock for the diCIGetVolTypeInfo call
   */
  struct DICIGetVolTypeInfoRec
  {
    unsigned long volSize;     // size of volume in SECTORs     unsigned short sectorSize; // bytes per sector     short numVolTypes;         // number of volume types supported     Str31 volTypesBuffer[4];   // 4 string buffers   };
  typedef struct DICIGetVolTypeInfoRec DICIGetVolTypeInfoRec;
  typedef DICIGetVolTypeInfoRec *DICIGetVolTypeInfoRecPtr;
  /**
   * paramBlock for the diCIGetFormatString call
   */
  struct DICIGetFormatStringRec
  {
    unsigned long volSize;     // volume size in SECTORs     unsigned short sectorSize; // sector size     short volTypeSelector;     // volume type selector     short stringKind;          // sub-function = type of string     Str255 stringBuffer;       // string buffer   };
  typedef struct DICIGetFormatStringRec DICIGetFormatStringRec;
  typedef DICIGetFormatStringRec *DICIGetFormatStringRecPtr;
  /**
   * paramBlock for the diCIGetExtendedFormatParams call
   */
  struct DICIGetExtendedFormatRec
  {
    short driveNumber;           // drive number     short volTypeSelector;       // volume type selector or 0     unsigned long volSize;       // size of volume in SECTORs     unsigned short sectorSize;   // bytes per sector     FSSpecPtr fileSystemSpecPtr; // pointer to the foreign file system's FSSpec     Ptr extendedInfoPtr;         // pointer to extended parameter structure   };
  typedef struct DICIGetExtendedFormatRec DICIGetExtendedFormatRec;
  typedef DICIGetExtendedFormatRec *DICIGetExtendedFormatRecPtr;
  /**
   *  File System Manager records
   */// CALL_NOT_IN_CARBON 

  typedef CALLBACK_API(OSErr, FSDCommProcPtr)(short message, void *paramBlock,
// support for pre-Carbon UPP routines: New...Proc and Call...Proc 
  typedef STACK_UPP_TYPE(FSDCommProcPtr) FSDCommUPP;
#if CALL_NOT_IN_CARBON
  /**
   *  NewFSDCommUPP()
   *
   *  A// CALL_NOT_IN_CARBON 
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */// component flags 
  FSDCommUPP// pointer to file system call processing code 
  NewFSDCommUPP(FSDCommProcPt// pointer to Lg2PhysProc() code 
#if !OPAQUE_UPP_TYPES// file system stack top 
  enum// file system stack size 
  {// current file system stack pointer 
    uppFSDCommProcInfo = 0x00// --reserved, must be zero-- 
  }; // pascal 2_bytes Func(2_bytes, 4_bytes, 4_bytes) #ifdef __cplusplus
  inline FSDCommUPP NewFSDCommUPP(FSDCommProcPtr userRoutine)
  {// --reserved, must be zero-- 
    return (FSDCommUPP)NewRou// --reserved, must be zero-- 
        (ProcPtr)(userRoutine), uppFSDCommProcInfo, GetCurrentArchitecture());
  }
#else
#define NewFSDCommUPP(userRoutine)   \
  (FSDCommUPP) NewRoutineDescriptor( \
      (ProcPtr)(userRoutine), uppFSDCommProcInfo, GetCurrentArchitecture())
#endif
#endif

  /**
   *  DisposeFSDCommUPP()
   *
   *  Availability:
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  DisposeFSDCommUPP(FSDCommUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeFSDCommUPP(FSDCommUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }// pascal 2_bytes Func(2_bytes, 4_bytes, 4_bytes) 
#else
#define DisposeFSDCommUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  InvokeFSDCommUPP()
   *
   *  Availability:
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  InvokeFSDCommUPP(short message, void *paramBlock, void *globalsPtr,
                   FSDCommUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline OSErr InvokeFSDCommUPP(short message, void *paramBlock, void *globalsPtr,
                                FSDCommUPP userUPP)
  {
    return (OSErr)CALL_THREE_PARAMETER_UPP(userUPP, uppFSDCommProcInfo, message,
                                           paramBlock, globalsPtr);
  }
#else
#define InvokeFSDCommUPP(message, paramBlock, globalsPtr, userUPP)           \
  (OSErr) CALL_THREE_PARAMETER_UPP((userUPP), uppFSDCommProcInfo, (message), \
                                   (paramBlock), (globalsPtr))
#endif
#endif

#endif // CALL_NOT_IN_CARBON 
#if CALL_NOT_IN_CARBON || OLDROUTINENAMES
// support for pre-Carbon UPP routines: New...Proc and Call...Proc #define NewFSDCommProc(userRoutine) NewFSDCommUPP(userRoutine)
#define CallFSDCommProc(userRoutine, message, paramBlock, globalsPtr) \
  InvokeFSDCommUPP(message, paramBlock, globalsPtr, userRoutine)
#endif // CALL_NOT_IN_CARBON 
  typedef struct FSDRec FSDRec;
  struct FSDRec
  {
    struct FSDRec *fsdLink;        // ptr to next     short fsdLength;               // length of this FSD in BYTES     short fsdVersion;              // version number     short fileSystemFSID;          // file system id     Str31 fileSystemName;          // file system name     FSSpec fileSystemSpec;         // foreign file system's FSSpec     Ptr fileSystemGlobalsPtr;      // ptr to file system globals     FSDCommUPP fileSystemCommProc; // communication proc with the FFS     long reserved3;                // --reserved, must be zero--     long reserved2;                // --reserved, must be zero--     long reserved1;                // --reserved, must be zero--     HFSCIRec fsdHFSCI;             // HFS component interface        DICIRec fsdDICI;               // Disk Initialization component interface   };

  typedef FSDRec *FSDRecPtr;
  struct FSMGetIconInfoRec
  {
    long theIcon[32]; // The ICN# structure     long theMask[32]; // The mask for the icon above     Str255 whereStr;
  };
  typedef struct FSMGetIconInfoRec FSMGetIconInfoRec;
  typedef FSMGetIconInfoRec *FSMGetIconInfoRecPtr;
  /**
   * paramBlock for ffsGetIconMessage and fsmGetFSIconMessage
   */
  struct FSMGetIconRec
  {
    short refNum;                       // target drive num or volume refnum     FSMGetIconInfoRecPtr iconBufferPtr; // pointer to icon buffer     long requestSize;                   // requested size of the icon buffer     long actualSize;                    // actual size of the icon data returned     UInt8 iconType;                     /* kind of icon. Note: A file system supporting
                                           kicnsIconFamily must */
    // return noErr, up to requestSize bytes of data, and the actual size     // of the 'icns' data in the actualSize field. If actualSize is greater     // than requestSize, the caller must resize the icon buffer and retry     // the request with the larger buffer and new requestSize.     Boolean isEjectable;         // true if the device is ejectable     DrvQElPtr driveQElemPtr;     // pointer to DQE     FSSpecPtr fileSystemSpecPtr; // pointer to foreign file system's FSSpec     long reserved1;              // --reserved, must be zero--   };
  typedef struct FSMGetIconRec FSMGetIconRec;
  typedef FSMGetIconRec *FSMGetIconRecPtr;
/**
 *  HFS// CALL_NOT_IN_CARBON 
 */
#if CALL_NOT_IN_CARBON
// support for pre-Carbon UPP routines: New...Proc and Call...Proc 
   *  UTAllocateFCB()
   *
   *  Availability:
   *   // CALL_NOT_IN_CARBON 
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr// component flags 
  UTAllocateFCB(short *fileRef// pointer to call processing code 
      TWOWORDINLINE(0x7000, 0x// maximum length of your volume name 
// your file system's block size 
  /**// --reserved, must be zero-- 
   *  UTReleaseFCB()// --reserved, must be zero-- 
   *// --reserved, must be zero-- 
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 8.5 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  UTReleaseFCB(short fileRefNum) TWOWORDINLINE(0x7001, 0xA824);

  /**
   *  UTLocateFCB()
   *
   *  Availability:
   *    \non_carbon_cfm   in Int// disk capacity in SECTORs 
   *    \carbon_lib        not a// flags 
   *    \mac_os_x         not av// sectors per track side 
   */// number of tracks 
  OSErr
  UTLocateFCB(VCBPtr volCtrlBlockPtr, unsigned long fileNum, StringPtr namePtr,
              short *fileRefNum, FCBRecPtr *fileCtrlBlockPtr)
      TWOWORDINLINE(0x7002, 0xA824);

  /**
   *  UTLocateNextFCB()
   *
   *  Availability:// flags as set by external file system 
   *    \non_carbon_cfm   in // disk driver format list record 
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  UTLocateNextFCB(VCBPtr volCtrlBlockPtr, unsigned long fileNum,
                  StringPtr namePtr, short *fileRefNum,
                  FCBRecPtr *fileCtrlBlockPtr) TWOWORDINLINE(0x7003, 0xA824);

  /**// default size for this FS 
   *  UTIndexFCB()// number of size entries 
   *// drive number 
   *  Availability:// ptr to size entry table 
   *    \non_carbon_cfm   in Int// bytes per sector 
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  UTIndexFCB(VCBPtr volCtrlBlockPtr, short *fileRefNum,
             FCBRecPtr *fileCtrlBlockPtr) TWOWORDINLINE(0x7004, 0xA824);

  /**
   *  UTResolveFCB()// drive number 
   *// ptr to volume name string 
   *  Availability:// file system ID 
   *    \non_carbon_cfm   in InterfaceLib 8.5 and later
   *    \carbon_lib        not avail// volume type selector, if supports more than 1 type 
   *    \mac_os_x         not availa// number of bad logical blocks 
   */// size of the defect list buffer in bytes 
  OSErr// pointer to defect list buffer 
  UTResolveFCB(short fileRefNum, FCB// size of volume in SECTORs 
      TWOWORDINLINE(0x7005, 0xA824);// bytes per sector 
// ptr to extended info 
  /**
   *  UTAllocateVCB()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 8.5 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr// the character to validate 
  UTAllocateVCB(unsigned short *// false if no message 
                unsigned short a// position of the current character (first char = 1) 
// pointer to message buffer or nil 
  /**
   *  UTAddNewVCB()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 8.5 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  UTAddNewVCB(short driveNum, short *vRefNum, VCBPtr volCtrlBlockPtr)
      TWOWORDINLINE(0x7007, 0xA// size of volume in SECTORs 
// bytes per sector 
  /**// number of volume types supported 
   *  UTDisposeVCB()// 4 string buffers 
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 8.5 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  UTDisposeVCB(VCBPtr volCtrlBlockPtr) TWOWORDINLINE(0x7008, 0xA824);
// volume size in SECTORs 
  /**// sector size 
   *  UTLocateVCBByRefNum()// volume type selector 
   *// sub-function = type of string 
   *  Availability:// string buffer 
   *    \non_carbon_cfm   in InterfaceLib 8.5 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  UTLocateVCBByRefNum(short refNum, short *vRefNum, VCBPtr *volCtrlBlockPtr)
      TWOWORDINLINE(0x7009, 0xA824);

  /**// drive number 
   *  UTLocateVCBByName()// volume type selector or 0 
   *// size of volume in SECTORs 
   *  Availability:// bytes per sector 
   *    \non_carbon_cfm   in Inte// pointer to the foreign file system's FSSpec 
   *    \carbon_lib        not av// pointer to extended parameter structure 
   *    \mac_os_x         not available
   */
  OSErr
  UTLocateVCBByName(StringPtr namePtr, short *moreMatches, short *vRefNum,
                    VCBPtr *volCtrlBlockPtr) TWOWORDINLINE(0x700A, 0xA824);

  /**
   *  UTLocateNextVCB()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 8.5 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  UTLocateNextVCB(StringPtr namePtr, short *moreMatches, short *vRefNum,
                  VCBPtr *volCtrlBlockPtr) TWOWORDINLINE(0x700B, 0xA824);

  /**
   *  UTAllocateWDCB()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 8.5 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */// pascal 2_bytes Func(2_bytes, 4_bytes, 4_bytes) 
  OSErr
  UTAllocateWDCB(WDPBPtr paramBlock) TWOWORDINLINE(0x700C, 0xA824);

  /**
   *  UTReleaseWDCB()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 8.5 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  UTReleaseWDCB(short wdRefNum) TWOWORDINLINE(0x700D, 0xA824);

  /**
   *  UTResolveWDCB()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 8.5 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  UTResolveWDCB(long procID, short wdIndex, short wdRefNum,
                WDCBRecPtr *wdCtrlBlockPtr) TWOWORDINLINE(0x700E, 0xA824);

  /**
   *  UTFindDrive()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 8.5 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  UTFindDrive(short driveNum, DrvQElPtr *driveQElementPtr)
      TWOWORDINLINE(0x700F, 0xA824);

  /**
   *  UTAdjustEOF()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 8.5 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  UTAdjustEOF(short fileRefNum) TWOWORDINLINE(0x7010, 0xA824);

  /**
   *  UTSetDefaultVol()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 8.5 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  UTSetDefaultVol(long nodeHint, unsigned long dirID, short refNum)
      TWOWORDINLINE(0x7011, 0xA824);
// CALL_NOT_IN_CARBON 
  /**
   *  UTGetDefaultVol()
// support for pre-Carbon UPP routines: New...Proc and Call...Proc 
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 8.5 and later
   *    \carbon_lib        not available
   *   // CALL_NOT_IN_CARBON 
   */
  OSErr
  UTGetDefaultVol(WDPBPtr paramBlock) TWOWORDINLINE(0x7012, 0xA824);

  /**// ptr to next 
   *  UTEjectVol()// length of this FSD in BYTES 
   *// version number 
   *  Availability:// file system id 
   *    \non_carbon_cfm   in Interf// file system name 
   *    \carbon_lib        not avai// foreign file system's FSSpec 
   *    \mac_os_x         not avail// ptr to file system globals 
   */// communication proc with the FFS 
  OSErr// --reserved, must be zero-- 
  UTEjectVol(VCBPtr volCtrlBlockPtr// --reserved, must be zero-- 
// --reserved, must be zero-- 
  /**// HFS component interface    
   *  UTCheckWDRefNum()// Disk Initialization component interface 
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 8.5 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */// The ICN# structure 
  OSErr// The mask for the icon above 
  UTCheckWDRefNum(short wdRefNum) TWOWORDINLINE(0x7013, 0xA824);

  /**
   *  UTCheckFileRefNum()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 8.5 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */// target drive num or volume refnum 
  OSErr// pointer to icon buffer 
  UTCheckFileRefNum(short fileRefNum) TW// requested size of the icon buffer 
// actual size of the icon data returned 
  /**
   *  UTCheckVolRefNum()
   *// return noErr, up to requestSize bytes of data, and the actual size 
   *// of the 'icns' data in the actualSize field. If actualSize is greater 
   *// than requestSize, the caller must resize the icon buffer and retry 
   *// the request with the larger buffer and new requestSize. 
   *    \mac_os_x         not ava// true if the device is ejectable 
   */// pointer to DQE 
  OSErr// pointer to foreign file system's FSSpec 
  UTCheckVolRefNum(short vRefNum)// --reserved, must be zero-- 

  /**
   *  UTCheckPermission()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 8.5 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  UTCheckPermission(VCBPtr volCtrlBlockPtr, short *modByte, unsigned long fileNum,
                    ParmBlkPtr paramBlock) TWOWORDINLINE(0x7016, 0xA824);

  /**
   *  UTCheckVolOffline()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 8.5 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  UTCheckVolOffline(short vRefNum) TWOWORDINLINE(0x7017, 0xA824);

  /**
   *  UTCheckVolModifiable()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 8.5 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  UTCheckVolModifiable(short vRefNum) TWOWORDINLINE(0x7018, 0xA824);

  /**
   *  UTCheckFileModifiable()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 8.5 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  UTCheckFileModifiable(short fileRefNum) TWOWORDINLINE(0x7019, 0xA824);

  /**
   *  UTCheckDirBusy()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 8.5 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  UTCheckDirBusy(VCBPtr volCtrlBlockPtr, unsigned long dirID)
      TWOWORDINLINE(0x701A, 0xA824);

  /**
   *  UTParsePathname()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 8.5 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  UTParsePathname(short *volNamelength, StringPtr namePtr)
      TWOWORDINLINE(0x701B, 0xA824);

  /**
   *  UTGetPathComponentName()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 8.5 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  UTGetPathComponentName(ParsePathRecPtr parseRec) TWOWORDINLINE(0x701C, 0xA824);

  /**
   *  UTDetermineVol()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 8.5 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  UTDetermineVol(ParmBlkPtr paramBlock, short *status, short *moreMatches,
                 short *vRefNum, VCBPtr *volCtrlBlockPtr)
      TWOWORDINLINE(0x701D, 0xA824);

  /**
   *  UTGetBlock()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 8.5 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  UTGetBlock(short refNum, void *log2PhyProc, unsigned long blockNum,
             short gbOption, Ptr *buffer) TWOWORDINLINE(0x701F, 0xA824);

  /**
   *  UTReleaseBlock()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 8.5 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  UTReleaseBlock(Ptr buffer, short rbOption) TWOWORDINLINE(0x7020, 0xA824);

  /**
   *  UTFlushCache()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 8.5 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  UTFlushCache(short refNum, short fcOption) TWOWORDINLINE(0x7021, 0xA824);

  /**
   *  UTMarkDirty()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 8.5 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  UTMarkDirty(Ptr buffer) TWOWORDINLINE(0x7023, 0xA824);

  /**
   *  UTTrashVolBlocks()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 8.5 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  UTTrashVolBlocks(VCBPtr volCtrlBlockPtr) TWOWORDINLINE(0x7024, 0xA824);

  /**
   *  UTTrashFileBlocks()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 8.5 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  UTTrashFileBlocks(VCBPtr volCtrlBlockPtr, unsigned long fileNum)
      TWOWORDINLINE(0x7025, 0xA824);

  /**
   *  UTTrashBlocks()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 8.5 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  UTTrashBlocks(unsigned long beginPosition, unsigned long byteCount,
                VCBPtr volCtrlBlockPtr, short fileRefNum, short tbOption)
      TWOWORDINLINE(0x7026, 0xA824);

  /**
   *  UTCacheReadIP()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 8.5 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  UTCacheReadIP(void *log2PhyProc, unsigned long filePosition, Ptr ioBuffer,
                short fileRefNum, unsigned long reqCount, unsigned long *actCount,
                short cacheOption) TWOWORDINLINE(0x7027, 0xA824);

  /**
   *  UTCacheWriteIP()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 8.5 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  UTCacheWriteIP(void *log2PhyProc, unsigned long filePosition, Ptr ioBuffer,
                 short fileRefNum, unsigned long reqCount,
                 unsigned long *actCount, short cacheOption)
      TWOWORDINLINE(0x7028, 0xA824);

  /**
   *  UTBlockInFQHashP()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 8.5 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  UTBlockInFQHashP(short vRefNum, unsigned long diskBlock)
      TWOWORDINLINE(0x702C, 0xA824);

  /**
   *  UTVolCacheReadIP()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 8.5 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  UTVolCacheReadIP(VCBPtr volCtrlBlockPtr, unsigned long blockPosition,
                   Ptr ioBuffer, unsigned long reqCount, unsigned long *actCount,
                   short cacheOption) TWOWORDINLINE(0x7034, 0xA824);

  /**
   *  UTVolCacheWriteIP()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 8.5 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  UTVolCacheWriteIP(VCBPtr volCtrlBlockPtr, unsigned long blockPosition,
                    Ptr ioBuffer, unsigned long reqCount, unsigned long *actCount,
                    short cacheOption) TWOWORDINLINE(0x7035, 0xA824);

  /**
   *  UTResolveFileRefNum()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 9.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  UTResolveFileRefNum(FCBRecPtr fileCtrlBlockPtr, short *fileRefNum)
      TWOWORDINLINE(0x7036, 0xA824);

  /**
   *  UTCheckFCB()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 9.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  UTCheckFCB(FCBRecPtr fileCtrlBlockPtr) TWOWORDINLINE(0x7037, 0xA824);

  /**
   *  UTCheckForkPermissions()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 9.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  UTCheckForkPermissions(VCBPtr volCtrlBlockPtr, UInt32 fileNum, UInt32 forkID,
                         Boolean fileLocked, SInt8 permissions,
                         Boolean useSearchList, SInt8 *fcbFlags,
                         SInt16 *openForkRefNum) TWOWORDINLINE(0x7038, 0xA824);

  /**
   *  UTAddFCBToSearchList()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 9.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  UTAddFCBToSearchList(FCBRecPtr fileCtrlBlockPtr) TWOWORDINLINE(0x7039, 0xA824);

  /**
   *  UTRemoveFCBFromSearchList()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 9.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  UTRemoveFCBFromSearchList(FCBRecPtr fileCtrlBlockPtr)
      TWOWORDINLINE(0x703A, 0xA824);

  /**
   *  UTLocateFCBInSearchList()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 9.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  UTLocateFCBInSearchList(VCBPtr volCtrlBlockPtr, unsigned long fileNum,
                          short *fileRefNum, FCBRecPtr *fileCtrlBlockPtr)
      TWOWORDINLINE(0x703B, 0xA824);

  /**
   *  UTGetForkControlBlockSize()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 9.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  UTGetForkControlBlockSize(UInt32 *fcbSize) TWOWORDINLINE(0x703C, 0xA824);

/**
 *  File System Manager call prototypes
 */
/**
 *  InstallFS()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 8.5 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 InstallFS(__A0)
#endif
  OSErr
  InstallFS(FSDRecPtr fsdPtr) TWOWORDINLINE(0x7000, 0xA0AC);

/**
 *  RemoveFS()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 8.5 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 RemoveFS(__A0)
#endif
  OSErr
  RemoveFS(short fsid) TWOWORDINLINE(0x7001, 0xA0AC);

  /**
   *  GetFSInfo()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 8.5 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  GetFSInfo(short selector, short key, short *bufSize, FSDRecPtr fsdPtr);

  /**
   *  SetFSInfo()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 8.5 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  SetFSInfo(short fsid, short bufSize, FSDRecPtr fsdPtr);

  /**
   *  InformFSM()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 8.5 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  InformFSM(short theMessage, void *paramBlock);

  /**
   *  InformFFS()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 8.5 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  InformFFS(short fsid, void *paramBlock);

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
#elif PRAGMA_IMPORT
#pragma import reset
#endif

#ifdef __cplusplus
}
#endif

#endif // __FSM__ // CALL_NOT_IN_CARBON 
// __FSM__ 
