/**
     \file       Files.h

    \brief   File Manager (MFS, HFS, and HFS+) Interfaces.

    \introduced_in  Mac OS 9
    \avaliable_from Universal Interfaces 3.4.1

    \copyright © 1985-2001 by Apple Computer, Inc., all rights reserved

    \ingroup File

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __FILES__
#define __FILES__

#ifndef __MACTYPES__
#include <MacTypes.h>
#endif

#ifndef __MIXEDMODE__
#include <MixedMode.h>
#endif

#ifndef __OSUTILS__
#include <OSUtils.h>
#endif

#ifndef __TEXTCOMMON__
#include <TextCommon.h>
#endif

#ifndef __UTCUTILS__
#include <UTCUtils.h>
#endif

/* Finder constants were moved to Finder.© */
#ifndef __FINDER__
#include <Finder.h>
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

  /* HFSUniStr255 is the Unicode equivalent of Str255 */
  struct HFSUniStr255
  {
    UInt16 length;        /* number of unicode characters */
    UniChar unicode[255]; /* unicode characters */
  };
  typedef struct HFSUniStr255 HFSUniStr255;
  typedef const HFSUniStr255 *ConstHFSUniStr255Param;
  enum
  {
    fsCurPerm = 0x00, /* open access permissions in ioPermssn */
    fsRdPerm = 0x01,
    fsWrPerm = 0x02,
    fsRdWrPerm = 0x03,
    fsRdWrShPerm = 0x04,
    fsRdDenyPerm = 0x10, /* for use with OpenDeny and OpenRFDeny */
    fsWrDenyPerm = 0x20  /* for use with OpenDeny and OpenRFDeny */
  };

  enum
  {
    fsRtParID = 1,
    fsRtDirID = 2
  };

  enum
  {
    fsAtMark = 0, /* positioning modes in ioPosMode */
    fsFromStart = 1,
    fsFromLEOF = 2,
    fsFromMark = 3
  };

  enum
  {
    /* ioPosMode flags */
    pleaseCacheBit = 4, /* please cache this request */
    pleaseCacheMask = 0x0010,
    noCacheBit = 5, /* please don't cache this request */
    noCacheMask = 0x0020,
    rdVerifyBit = 6, /* read verify mode */
    rdVerifyMask = 0x0040,
    rdVerify = 64, /* old name of rdVerifyMask */
    forceReadBit = 6,
    forceReadMask = 0x0040,
    newLineBit = 7, /* newline mode */
    newLineMask = 0x0080,
    newLineCharMask = 0xFF00 /* newline character */
  };

  enum
  {
    /* CatSearch Search bitmask Constants */
    fsSBPartialName = 1,
    fsSBFullName = 2,
    fsSBFlAttrib = 4,
    fsSBFlFndrInfo = 8,
    fsSBFlLgLen = 32,
    fsSBFlPyLen = 64,
    fsSBFlRLgLen = 128,
    fsSBFlRPyLen = 256,
    fsSBFlCrDat = 512,
    fsSBFlMdDat = 1024,
    fsSBFlBkDat = 2048,
    fsSBFlXFndrInfo = 4096,
    fsSBFlParID = 8192,
    fsSBNegate = 16384,
    fsSBDrUsrWds = 8,
    fsSBDrNmFls = 16,
    fsSBDrCrDat = 512,
    fsSBDrMdDat = 1024,
    fsSBDrBkDat = 2048,
    fsSBDrFndrInfo = 4096,
    fsSBDrParID = 8192
  };

  enum
  {
    /* CatSearch Search bit value Constants */
    fsSBPartialNameBit = 0,  /*ioFileName points to a substring*/
    fsSBFullNameBit = 1,     /*ioFileName points to a match string*/
    fsSBFlAttribBit = 2,     /*search includes file attributes*/
    fsSBFlFndrInfoBit = 3,   /*search includes finder info*/
    fsSBFlLgLenBit = 5,      /*search includes data logical length*/
    fsSBFlPyLenBit = 6,      /*search includes data physical length*/
    fsSBFlRLgLenBit = 7,     /*search includes resource logical length*/
    fsSBFlRPyLenBit = 8,     /*search includes resource physical length*/
    fsSBFlCrDatBit = 9,      /*search includes create date*/
    fsSBFlMdDatBit = 10,     /*search includes modification date*/
    fsSBFlBkDatBit = 11,     /*search includes backup date*/
    fsSBFlXFndrInfoBit = 12, /*search includes extended finder info*/
    fsSBFlParIDBit = 13,     /*search includes file's parent ID*/
    fsSBNegateBit = 14,      /*return all non-matches*/
    fsSBDrUsrWdsBit = 3,     /*search includes directory finder info*/
    fsSBDrNmFlsBit = 4,      /*search includes directory valence*/
    fsSBDrCrDatBit = 9,      /*directory-named version of fsSBFlCrDatBit*/
    fsSBDrMdDatBit = 10,     /*directory-named version of fsSBFlMdDatBit*/
    fsSBDrBkDatBit = 11,     /*directory-named version of fsSBFlBkDatBit*/
    fsSBDrFndrInfoBit = 12,  /*directory-named version of fsSBFlXFndrInfoBit*/
    fsSBDrParIDBit = 13      /*directory-named version of fsSBFlParIDBit*/
  };

  enum
  {
    /* vMAttrib (GetVolParms) bit position constants */
    bLimitFCBs = 31,
    bLocalWList = 30,
    bNoMiniFndr = 29,
    bNoVNEdit = 28,
    bNoLclSync = 27,
    bTrshOffLine = 26,
    bNoSwitchTo = 25,
    bDontShareIt = 21, /* this volume should not be shared by Macintosh File
                          Sharing (see Technical Note NW 29) */
    bNoDeskItems = 20,
    bNoBootBlks = 19,
    bAccessCntl = 18,
    bNoSysDir = 17,
    bHasExtFSVol = 16,
    bHasOpenDeny = 15,
    bHasCopyFile = 14,
    bHasMoveRename = 13,
    bHasDesktopMgr = 12,
    bHasShortName = 11,
    bHasFolderLock = 10,
    bHasPersonalAccessPrivileges = 9,
    bHasUserGroupList = 8,
    bHasCatSearch = 7,
    bHasFileIDs = 6,
    bHasBTreeMgr = 5,
    bHasBlankAccessPrivileges = 4,
    bSupportsAsyncRequests = 3, /* asynchronous requests to this volume are
                                   handled correctly at any time*/
    bSupportsTrashVolumeCache = 2
  };

  enum
  {
    /* vMExtendedAttributes (GetVolParms) bit position constants */
    bIsEjectable = 0,               /* volume is in an ejectable disk drive */
    bSupportsHFSPlusAPIs = 1,       /* volume supports HFS Plus APIs directly (not
                                       through compatibility layer) */
    bSupportsFSCatalogSearch = 2,   /* volume supports FSCatalogSearch */
    bSupportsFSExchangeObjects = 3, /* volume supports FSExchangeObjects */
    bSupports2TBFiles = 4,          /* volume supports supports 2 terabyte files */
    bSupportsLongNames = 5,         /* volume supports file/directory/volume names longer
                                       than 31 characters */
    bSupportsMultiScriptNames =
        6, /* volume supports file/directory/volume names with characters from
              multiple script systems */
    bSupportsNamedForks =
        7, /* volume supports forks beyond the data and resource forks */
    bSupportsSubtreeIterators =
        8,                   /* volume supports recursive iterators not at the volume root */
    bL2PCanMapFileBlocks = 9 /* volume supports Lg2Phys SPI correctly */
  };

  enum
  {
    /* vMExtendedAttributes (GetVolParms) bit position constants */
    bParentModDateChanges =
        10, /* Changing a file or folder causes its parent's mod date to change */
    bAncestorModDateChanges =
        11 /* Changing a file or folder causes all ancestor mod dates to change */
  };

  enum
  {
    /* vMExtendedAttributes (GetVolParms) bit position constants */
    bSupportsSymbolicLinks = 13, /* volume supports the creation and use of
                                    symbolic links (Mac OS X only) */
    bIsAutoMounted = 14,         /* volume was mounted automatically (Mac OS X only) */
    bAllowCDiDataHandler =
        17 /* allow QuickTime's CDi data handler to examine this volume */
  };

  enum
  {
    /* Desktop Database, ffsGetIconMessage and fsmGetFSIconMessage icon type and
       size Constants */
    kLargeIcon = 1,
    kLarge4BitIcon = 2,
    kLarge8BitIcon = 3,
    kSmallIcon = 4,
    kSmall4BitIcon = 5,
    kSmall8BitIcon = 6,
    kicnsIconFamily =
        239 /* Note: The 'icns' icon family record is variable sized. */
  };

  enum
  {
    kLargeIconSize = 256,
    kLarge4BitIconSize = 512,
    kLarge8BitIconSize = 1024,
    kSmallIconSize = 64,
    kSmall4BitIconSize = 128,
    kSmall8BitIconSize = 256
  };

  enum
  {
    /* Large Volume Constants */
    kWidePosOffsetBit = 8,
    kUseWidePositioning = (1 << kWidePosOffsetBit),
    kMaximumBlocksIn4GB = 0x007FFFFF
  };

  enum
  {
    /* Foreign Privilege Model Identifiers */
    fsUnixPriv = 1
  };

  enum
  {
    /* Authentication Constants */
    kNoUserAuthentication = 1,
    kPassword = 2,
    kEncryptPassword = 3,
    kTwoWayEncryptPassword = 6
  };

  /* mapping codes (ioObjType) for MapName & MapID */
  enum
  {
    kOwnerID2Name = 1,
    kGroupID2Name = 2,
    kOwnerName2ID = 3,
    kGroupName2ID =
        4, /* types of oj object to be returned (ioObjType) for _GetUGEntry */
    kReturnNextUser = 1,
    kReturnNextGroup = 2,
    kReturnNextUG = 3
  };

  /* vcbFlags bits */
  enum
  {
    kVCBFlagsIdleFlushBit = 3, /* Set if volume should be flushed at idle time */
    kVCBFlagsIdleFlushMask = 0x0008,
    kVCBFlagsHFSPlusAPIsBit =
        4, /* Set if volume implements HFS Plus APIs itself (not via emulation) */
    kVCBFlagsHFSPlusAPIsMask = 0x0010,
    kVCBFlagsHardwareGoneBit =
        5, /* Set if disk driver returned a hardwareGoneErr to Read or Write */
    kVCBFlagsHardwareGoneMask = 0x0020,
    kVCBFlagsVolumeDirtyBit =
        15, /* Set if volume information has changed since the last FlushVol */
    kVCBFlagsVolumeDirtyMask = 0x8000
  };

  /* ioVAtrb bits returned by PBHGetVInfo and PBXGetVolInfo */
  enum
  {
    kioVAtrbDefaultVolumeBit = 5, /* Set if the volume is the default volume */
    kioVAtrbDefaultVolumeMask = 0x0020,
    kioVAtrbFilesOpenBit = 6, /* Set if there are open files or iterators */
    kioVAtrbFilesOpenMask = 0x0040,
    kioVAtrbHardwareLockedBit =
        7, /* Set if volume is locked by a hardware setting */
    kioVAtrbHardwareLockedMask = 0x0080,
    kioVAtrbSoftwareLockedBit = 15, /* Set if volume is locked by software */
    kioVAtrbSoftwareLockedMask = 0x8000
  };

  /* ioFlAttrib bits returned by PBGetCatInfo */
  enum
  {
    /* file and directory attributes in ioFlAttrib */
    kioFlAttribLockedBit = 0, /* Set if file or directory is locked */
    kioFlAttribLockedMask = 0x01,
    kioFlAttribResOpenBit = 2, /* Set if resource fork is open */
    kioFlAttribResOpenMask = 0x04,
    kioFlAttribDataOpenBit = 3, /* Set if data fork is open */
    kioFlAttribDataOpenMask = 0x08,
    kioFlAttribDirBit = 4, /* Set if this is a directory */
    kioFlAttribDirMask = 0x10,
    ioDirFlg = 4, /* Set if this is a directory (old name) */
    ioDirMask = 0x10,
    kioFlAttribCopyProtBit =
        6, /* Set if AppleShare server "copy-protects" the file */
    kioFlAttribCopyProtMask = 0x40,
    kioFlAttribFileOpenBit = 7,     /* Set if file (either fork) is open */
    kioFlAttribFileOpenMask = 0x80, /* ioFlAttrib for directories only */
    kioFlAttribInSharedBit = 2,     /* Set if the directory is within a shared area of
                                       the directory hierarchy */
    kioFlAttribInSharedMask = 0x04,
    kioFlAttribMountedBit = 3, /* Set if the directory is a share point that is
                                  mounted by some user */
    kioFlAttribMountedMask = 0x08,
    kioFlAttribSharePointBit = 5, /* Set if the directory is a share point */
    kioFlAttribSharePointMask = 0x20
  };

  /* ioFCBFlags bits returned by PBGetFCBInfo */
  enum
  {
    kioFCBWriteBit = 8, /* Data can be written to this file */
    kioFCBWriteMask = 0x0100,
    kioFCBResourceBit = 9, /* This file is a resource fork */
    kioFCBResourceMask = 0x0200,
    kioFCBWriteLockedBit = 10, /* File has a locked byte range */
    kioFCBWriteLockedMask = 0x0400,
    kioFCBLargeFileBit =
        11, /* File may grow beyond 2GB; cache uses file blocks, not bytes */
    kioFCBLargeFileMask = 0x0800,
    kioFCBSharedWriteBit = 12, /* File is open for shared write access */
    kioFCBSharedWriteMask = 0x1000,
    kioFCBFileLockedBit = 13, /* File is locked (write-protected) */
    kioFCBFileLockedMask = 0x2000,
    kioFCBOwnClumpBit = 14, /* File has clump size specified in FCB */
    kioFCBOwnClumpMask = 0x4000,
    kioFCBModifiedBit = 15, /* File has changed since it was last flushed */
    kioFCBModifiedMask = 0x8000
  };

  /* ioACUser bits returned by PBGetCatInfo */
  /* Note: you must clear ioACUser before calling PBGetCatInfo because some file
   * systems do not use this field */
  enum
  {
    kioACUserNoSeeFolderBit =
        0, /* Set if user does not have See Folder privileges */
    kioACUserNoSeeFolderMask = 0x01,
    kioACUserNoSeeFilesBit =
        1, /* Set if user does not have See Files privileges */
    kioACUserNoSeeFilesMask = 0x02,
    kioACUserNoMakeChangesBit =
        2, /* Set if user does not have Make Changes privileges */
    kioACUserNoMakeChangesMask = 0x04,
    kioACUserNotOwnerBit = 7, /* Set if user is not owner of the directory */
    kioACUserNotOwnerMask = 0x80
  };

  /* Folder and File values of access privileges in ioACAccess */
  enum
  {
    kioACAccessOwnerBit = 31, /* User is owner of directory */
    kioACAccessOwnerMask = (long)0x80000000,
    kioACAccessBlankAccessBit = 28, /* Directory has blank access privileges */
    kioACAccessBlankAccessMask = 0x10000000,
    kioACAccessUserWriteBit = 26, /* User has write privileges */
    kioACAccessUserWriteMask = 0x04000000,
    kioACAccessUserReadBit = 25, /* User has read privileges */
    kioACAccessUserReadMask = 0x02000000,
    kioACAccessUserSearchBit = 24, /* User has search privileges */
    kioACAccessUserSearchMask = 0x01000000,
    kioACAccessEveryoneWriteBit = 18, /* Everyone has write privileges */
    kioACAccessEveryoneWriteMask = 0x00040000,
    kioACAccessEveryoneReadBit = 17, /* Everyone has read privileges */
    kioACAccessEveryoneReadMask = 0x00020000,
    kioACAccessEveryoneSearchBit = 16, /* Everyone has search privileges */
    kioACAccessEveryoneSearchMask = 0x00010000,
    kioACAccessGroupWriteBit = 10, /* Group has write privileges */
    kioACAccessGroupWriteMask = 0x00000400,
    kioACAccessGroupReadBit = 9, /* Group has read privileges */
    kioACAccessGroupReadMask = 0x00000200,
    kioACAccessGroupSearchBit = 8, /* Group has search privileges */
    kioACAccessGroupSearchMask = 0x00000100,
    kioACAccessOwnerWriteBit = 2, /* Owner has write privileges */
    kioACAccessOwnerWriteMask = 0x00000004,
    kioACAccessOwnerReadBit = 1, /* Owner has read privileges */
    kioACAccessOwnerReadMask = 0x00000002,
    kioACAccessOwnerSearchBit = 0, /* Owner has search privileges */
    kioACAccessOwnerSearchMask = 0x00000001,
    kfullPrivileges = 0x00070007, /* all privileges for everybody and owner*/
    kownerPrivileges = 0x00000007 /* all privileges for owner only*/
  };

  /* values of user IDs and group IDs */
  enum
  {
    knoUser = 0,
    kadministratorUser = 1
  };

  enum
  {
    knoGroup = 0
  };

  /**
  <pre>
   * \note <pre>The first four fields are the same as those in the original
  PBHGetVolParms attributes buffer, introduced with the network
  software described in the File Manager Extensions . The last two fields
  are new in system software version 7.0.
  Offset Field Size Meaning
  14 vMVolumeGrade long Relative speed rating of volume. This
  scale is currently uncalibrated.
  Generally, lower values represent
  faster speeds. A value of 0 means the
  volume is unrated.
  18 vMForeignPrivID shortCode for the privilege model
  supported by the volume. This field
  now has two possible values: 0
  represents a standard HFS volume,
  which might or might not support the
  AFP privilege model; fsUnixPriv
  represents an A/UX volume.
  To determine whether the functions for manipulating privilege
  information in foreign file systems are available on a volume, check the
  vMForeignPrivID field in the attributes buffer. If this field contains a
  nonzero value, the functions are available.
  PBHGetVolParms returns the bulk of its volume description in the
  vMAttrib field of the attributes buffer. Version 7.0 has defined additional
  bits in the vMAttrib field to signal whether the following features are
  present.
  Feature Constant
  Volume supports PBCatSearch bHasCatSearch
  Volume supports the file ID functions, bHasFileIDs
  including PBExchangeFiles
  Volume supports inherited access bHasBlankAccessPrivileges
  privileges for folders
  Volume supports the Desk Manager bHasDesktopMgr
  functions, described in the
  </pre>
   * \copyright THINK Reference © 1991-1992 Symantec Corporation
  */
  struct GetVolParmsInfoBuffer
  {
    short vMVersion;       /**< version number*/
    long vMAttrib;         /**< bit vector of attributes;/**<*/
    Handle vMLocalHand;    /**< handle to private data*/
    long vMServerAdr;      /**< network server address*/
    long vMVolumeGrade;    /**< relative speed rating*/
    short vMForeignPrivID; /**< access privilege model*/
  } GetVolParmsInfoBuffer; /**< */

  typedef struct GetVolParmsInfoBuffer GetVolParmsInfoBuffer;
  typedef union ParamBlockRec ParamBlockRec;

  typedef ParamBlockRec *ParmBlkPtr;
  typedef CALLBACK_API_REGISTER68K(void, IOCompletionProcPtr,
                                   (ParmBlkPtr paramBlock));
  typedef REGISTER_UPP_TYPE(IOCompletionProcPtr) IOCompletionUPP;
  struct IOParam
  {
    QElemPtr qLink;               /*queue link in header*/
    short qType;                  /*type byte for safety check*/
    short ioTrap;                 /*FS: the Trap*/
    Ptr ioCmdAddr;                /*FS: address to dispatch to*/
    IOCompletionUPP ioCompletion; /*completion routine addr (0 for synch calls)*/
    volatile OSErr ioResult;      /*result code*/
    StringPtr ioNamePtr;          /*ptr to Vol:FileName string*/
    short ioVRefNum;              /*volume refnum (DrvNum for Eject and MountVol)*/
    short ioRefNum;               /*refNum for I/O operation*/
    SInt8 ioVersNum;              /*version number*/
    SInt8 ioPermssn;              /*Open: permissions (byte)*/
    Ptr ioMisc;                   /*Rename: new name (GetEOF,SetEOF: logical end of file) (Open:
                                     optional ptr to buffer) (SetFileType: new type)*/
    Ptr ioBuffer;                 /*data buffer Ptr*/
    long ioReqCount;              /*requested byte count; also = ioNewDirID*/
    long ioActCount;              /*actual byte count completed*/
    short ioPosMode;              /*initial file positioning*/
    long ioPosOffset;             /*file position offset*/
  };
  typedef struct IOParam IOParam;
  typedef IOParam *IOParamPtr;
  /**
  <pre>
   * \note <pre>This structure is used in PBxxx calls which typically operate on unopened
  files:
  PBCreate PBGetFInfo PBSetFInfo
  PBDelete PBRstFLock PBSetFLock
  Functions vary as to which fields are required on entry and which fields
  are defined upon return. Some fields take on different meanings or even
  data types in certain cases. Refer to the function in question for additional
  information on fields.
  The most common way to use this structure is to allocate a union which is
  an aggregate. Then create and initialize a pointer to the desired data type.
  See ParamBlockRec for an example.
  The HFileParam structure is similar but has been modernized for use with
  HFS-specific calls ( PBHxxx).
  </pre>
   * \copyright THINK Reference © 1991-1992 Symantec Corporation
  */
  struct FileParam
  {
    short ioFRefNum;           /**< File reference number*/
    SignedByte ioFVersNum;     /**< Version (use  for HFS)*/
    SignedByte filler;         /**< (unused)*/
    short ioFDirIndex;         /**< Index*/
    unsigned char ioFlAttrib;  /**< File Attribute  bits*/
    unsigned char ioFlVersNum; /**< File version (always set to )*/
    FInfo ioFlFndrInfo;        /**< File type, creator, flags, etc. (see*/
    unsigned long ioFlNum;     /**< File number*/
    unsigned short ioFlStBlk;  /**< First allocation block of data fork*/
    long ioFlLgLen;            /**< Logical end-of-file of data fork*/
    long ioFlPyLen;            /**< Physical end-of-file of data fork*/
    unsigned short ioFlRStBlk; /**< First allocation block of resource*/
    long ioFlRLgLen;           /**< Logical end-of-file of resource fork*/
    long ioFlRPyLen;           /**< Physical end-of-file of resource*/
    unsigned long ioFlCrDat;   /**< Date/time of creation (seconds since*/
    unsigned long ioFlMdDat;   /**< Date/Time of last modification*/
  } FileParam;                 /**< */

  typedef struct FileParam FileParam;
  typedef FileParam *FileParamPtr;
  /**
  <pre>
   * \note <pre>This structure is used in PBxxx calls which operate on entire volumes:
  PBEject PBGetVol PBSetVInfo
  PBFlushVol PBMountVol PBSetVol
  PBGetVInfo PBOffLine PBUnmountVol
  Functions vary as to which fields are required on entry and which fields
  are defined upon return. Some fields take on different meanings or even
  data types in certain cases. Refer to the function in question for additional
  information on fields.
  The ioVLsBkUp field is misnamed. It contains the date/time when the file
  was last modified (Note: data may have actually been flushed to disk
  somewhat later).
  The ioVAtrb field is a set of bit flags. See Volume Attributes .
  The ioVClpSiz field is the default allocation "clump" size for files on this
  volume. If the file's clump size is 0 (see CInfoPBRec ), then when a file is
  extended, ioVClpSiz bytes are appended to the file's physical length.
  The most common way to use this structure is to allocate a union which is
  an aggregate and create and initialize a pointer to the desired data type. See
  ParamBlockRec for examples.
  </pre>
   * \copyright THINK Reference © 1991-1992 Symantec Corporation
  */
  struct VolumeParam
  {
    long filler;                /**< (reserved)*/
    short ioVolIndex;           /**< (>: index, <: use name/num, :*/
    unsigned long ioVCrDate;    /**< Date/time volume created*/
    unsigned long ioVLsBkUp;    /**< Date/time volume information was*/
    unsigned short ioVAtrb;     /**< Volume Attributes*/
    unsigned short ioVNmFls;    /**< Count of files in the root directory*/
    unsigned short ioVDirSt;    /**< First allocation block of directory*/
    short ioVBlLn;              /**< Length of directory in blocks*/
    unsigned short ioVNmAlBlks; /**< Count of all allocation blocks*/
    long ioVAlBlkSiz;           /**< Allocation block size, in bytes*/
    long ioVClpSiz;             /**< Number of bytes to allocate*/
    unsigned short ioAlBlSt;    /**< First block in volume block map*/
    unsigned long ioVNxtFNum;   /**< Next unused file number*/
    unsigned short ioVFrBlk;    /**< Count of free allocation blocks*/
  } VolumeParam;                /**< */

  typedef struct VolumeParam VolumeParam;
  typedef VolumeParam *VolumeParamPtr;
  /**
  <pre>
   * \note <pre>This structure is used in Device Manager calls that request and provide
  control and status information:
  PBStatus PBControl
  The most common way to use this structure is to allocate a union which is
  an aggregate and create and initialize a pointer to the desired data type. See
  ParamBlockRec for examples.
  </pre>
   * \copyright THINK Reference © 1991-1992 Symantec Corporation
  */
  struct CntrlParam
  {
    short ioCRefNum; /**< Device driver reference*/
    short csCode;    /**< Type of Control or Status call*/
    short csParam[]; /**< Control or status information*/
  } CntrlParam;      /**< */

  typedef struct CntrlParam CntrlParam;
  typedef CntrlParam *CntrlParamPtr;
  /**
  <pre>
   * \copyright THINK Reference © 1991-1992 Symantec Corporation
  */
  struct SlotDevParam
  {
    short ioRefNum; /**<  */
    char ioVersNum; /**<  */
    char ioPermssn; /**<  */
    Ptr ioMix;      /**<  */
    short ioFlags;  /**<  */
    char ioSlot;    /**<  */
    char ioID;      /**<  */
  } SlotDevParam;   /**< */

  typedef struct SlotDevParam SlotDevParam;
  typedef SlotDevParam *SlotDevParamPtr;
  /**
  <pre>
   * \copyright THINK Reference © 1991-1992 Symantec Corporation
  */
  struct MultiDevParam
  {
    short ioRefNum; /**<  */
    char ioVersNum; /**<  */
    char ioPermssn; /**<  */
    Ptr ioMix;      /**<  */
    short ioFlags;  /**<  */
    Ptr ioSEBlkPtr; /**<  */
  } MultiDevParam;  /**< */

  typedef struct MultiDevParam MultiDevParam;
  typedef MultiDevParam *MultiDevParamPtr;
  /**
  <pre>
   * \note <pre>All six structures on this union share the same names for the first eight
  fields (the first 24 bytes). These common fields are defined in a macro
  called the ParamBlockHeader .
  In lieu of Pascal's system of records and variants, C programmers can use
  predefined unions to access the various parts of the file system parameter
  blocks. There are several options, but a common way to access the data is by
  allocating a union (ie, storage for the largest of the union-member
  structures) and creating pointers which refer to the relevant structure
  data types:
  ParamBlockRec pb; // allocate a union
  ioParam *ipb=(IOParam *)&pb; // and structure ptrs
  fileParam *fpb=(FileParam *)&pb; // all pointing same addr
  volumeParam *vpb=(VolumeParam *)&pb;
  pb.ioParam.ioVRefNum = 2; // as union member field
  pb.fileParam. ioFlFndrInfo .fdType = 'TEXT';
  pb.volumeParam. ioVolIndex = 0;
  ipb->ioVRefNum = 2; // or as a structure field
  fpb->ioFlFndrInfo .fdType = 'TEXT';
  vpb->ioVolIndex = 0;
  You can also do ad hoc type coercion:
  unsigned char pb[80]; // big enough to hold a FileParam or IOParam
  short theVRef;
  theVRef = (( IOParam *)pb)->ioVRefNum;
  ((FileParam *)pb)-> ioFlLgLen = 1000L;
  printf("File type is '%c%c%c%c'\n",pb[32],pb[33],pb[34],pb[35]);
  </pre>
   * \copyright THINK Reference © 1991-1992 Symantec Corporation
  */
  union ParamBlockRec
  {
    IOParam ioParam;             /**< Generally used in I/O for open files*/
    FileParam fileParam;         /**< Used for unopened files*/
    VolumeParam volumeParam;     /**< Used in volume-specific functions*/
    CntrlParam cntrlParam;       /**< */
    SlotDevParam slotDevParam;   /**< */
    MultiDevParam multiDevParam; /**< */
  } ParamBlockRec;               /**< (size of aggregate)*/

  /**
  <pre>
   * \note <pre>Use this HFileInfo structure in calls to PBGetCatInfo and
  PBSetCatInfo when you access information about a file.
  Wherever a function exists to modify one of the values in this structure,
  you should use that function. For instance, don't use PBSetCatInfo to set
  the lock bit; instead call PBSetFLock .
  A common way to use this structure is to allocate a CInfoPBRec union
  which is an aggregate of HFileInfo and DirInfo. Create and initialize a
  pointer to each data type and use either structure in the call to
  PBGetCatInfo . Upon return, check bit 4 of ioFlAttrib. If bit 4 is set,
  then the return data is about a directory and you should use the DirInfo
  structure; otherwise, use HFileInfo. See CInfoPBRec for examples.
  </pre>
   * \copyright THINK Reference © 1991-1992 Symantec Corporation
  */
  struct HFileInfo
  {
    short ioFRefNum;           /**< File reference number*/
    char ioFVersNum;           /**< Version (best to use )*/
    char filler;               /**< (unused)*/
    short ioFDirIndex;         /**< Index*/
    char ioFlAttrib;           /**< File Attribute  bits (bit  set if*/
    char filler;               /**< (unused)*/
    FInfo ioFlFndrInfo;        /**< (File type, creator, flags, icon*/
    long ioDirID;              /**< 'Hard' Directory ID or file number*/
    unsigned short ioFlStBlk;  /**< First allocation block of data fork*/
    long ioFlLgLen;            /**< Logical end-of-file of data fork*/
    long ioFlPyLen;            /**< Physical end-of-file of data fork*/
    unsigned short ioFlRStBlk; /**< First allocation block of resource*/
    long ioFlRLgLen;           /**< Logical end-of-file of resource fork*/
    long ioFlRPyLen;           /**< Physical end-of-file of resource*/
    unsigned long ioFlCrDat;   /**< Date/Time of creation*/
    unsigned long ioFlMdDat;   /**< Date/Time of last modification*/
    unsigned long ioFlBkDat;   /**< Date/Time last backed up*/
    FXInfo ioFlXFndrInfo;      /**< (icon ID, comment, put-away dir)*/
    long ioFlParID;            /**< 'Hard' ID of this dir's parent*/
    long ioFlClpSiz;           /**< Allocation block size (=use volume*/
  } HFileInfo;                 /**< */

  typedef struct HFileInfo HFileInfo;
  /**
  <pre>
   * \note <pre>Use this DirInfo structure in calls to PBGetCatInfo and PBSetCatInfo
  when you access information about a directory.
  A common way to use this structure is to allocate a CInfoPBRec union
  which is an aggregate of HFileInfo and DirInfo. Create and initialize a
  pointer to each data type and use either structure in the call to
  PBGetCatInfo . Upon return, check bit 4 of ioFlAttrib. If bit 4 is set,
  then the return data is about a directory and you should use the DirInfo
  structure; otherwise, use HFileInfo . See CInfoPBRec for examples.
  </pre>
   * \copyright THINK Reference © 1991-1992 Symantec Corporation
  */
  struct DirInfo
  {
    short ioFRefNum;          /**< File reference number*/
    short filler;             /**< (unused)*/
    short ioFDirIndex;        /**< Index*/
    char ioFlAttrib;          /**< File Attribute  bits (locked,*/
    char filler;              /**< (unused)*/
    DInfo ioDrUsrWds;         /**< (Folder rectangle, location, flags,*/
    long ioDrDirID;           /**< 'Hard' directory ID*/
    unsigned short ioDrNmFls; /**< Number of files and directories in*/
    short filler[];           /**< (unused)*/
    unsigned long ioDrCrDat;  /**< Date/Time of creation*/
    unsigned long ioDrMdDat;  /**< Date/Time of last modification*/
    unsigned long ioDrBkDat;  /**< Date/Time last backed up*/
    DXInfo ioDrFndrInfo;      /**< (Scroll point, put-away dir,*/
    long ioDrParID;           /**< 'Hard' ID of this dir's parent*/
  } DirInfo;                  /**< */

  typedef struct DirInfo DirInfo;
  /**
  <pre>
   * \note <pre>This union (or either of the HFileInfo or DirInfo structures) is used in
  calls to PBGetCatInfo and PBSetCatInfo . Note that the return value of
  the ioFlAttrib field (of either member structure) identifies which type of
  information is returned (see PBGetCatInfo for details).
  A handy technique is to allocate the CInfoPBRec union and create pointers
  which refer to each data type:
  CInfoPBRec cipb; /* allocate a union */
  HFileInfo *hfipb = (HFileInfo *)&cipb; /* and separate struc ptrs */
  DirInfo *dipb = (DirInfo *)&cipb;      /* pointing same address */
  cipb.hFileInfo.vRefNum = 2;            /* as a union member field */
  cipb.dirInfo.ioDrFndrInfo.frLocation.h = 100;
  hfipb->vRefNum = 2; /* or as a structure field */
  dipb->ioDrFndrInfo.frLocation.h = 100;
  You can also perform ad hoc type coercion : unsigned char pb[108]; /* big enough to hold either struct */
  short theVRef;
  theVRef = ((HFileInfo *)pb)->ioVRefNum; /* fetch 1 field */
  ((HFileParam *)pb)->ioFlLgLen = 1000L;  /* change some fields */
  ((HFileInfo *)pb)->ioFlClpSiz = 2048;
  GetDateTime(&((HFileInfo *)pb)->ioFlMdDat);
  /* access chars of a long */
  printf("File type is '%c%c%c%c'\n", pb[32], pb[33], pb[34], pb[35]);
  </ pre>
          * \copyright THINK Reference © 1991 - 1992 Symantec Corporation
                                                        * /
                                                    union CInfoPBRec
  {
    HFileInfo hFileInfo; /**< Use for files*/
    DirInfo dirInfo;     /**< Use for directories*/
  } CInfoPBRec;          /**< (size of aggregate)*/

  typedef union CInfoPBRec CInfoPBRec;
  typedef CInfoPBRec *CInfoPBPtr;
  struct XCInfoPBRec
  {
    QElemPtr qLink;
    short qType;
    short ioTrap;
    Ptr ioCmdAddr;
    ProcPtr ioCompletion;    /* --> A pointer to a completion routine */
    volatile OSErr ioResult; /* --> The result code of the function */
    StringPtr ioNamePtr;     /* --> Pointer to pathname to object */
    short ioVRefNum;         /* --> A volume specification */
    long filler1;
    StringPtr ioShortNamePtr; /* <-> A pointer to the short name string buffer -
                                 required! */
    short filler2;
    short ioPDType;   /* <-- The ProDOS file type */
    long ioPDAuxType; /* <-- The ProDOS aux type */
    long filler3[2];
    long ioDirID; /* --> A directory ID */
  };
  typedef struct XCInfoPBRec XCInfoPBRec;
  typedef XCInfoPBRec *XCInfoPBPtr;
  /* Catalog position record */
  /**
  <pre>
   * \note <pre>To start a search at the beginning of the catalog, set the initialization field
  to 0. When it exits because of a timeout, PBCatSearch updates the record
  so that it describes the next entry to be searched. When you call
  PBCatSearch to resume the search after a timeout, pass the entire
  record that was returned by the last call. PBCatSearch returns a list of the
  names and parent directories of all files and directories that match the
  criteria you specify. It places the list in an array pointed to by the
  FSSpecPtr field. The array contains FSSpec records.
  </pre>
   * \copyright THINK Reference © 1991-1992 Symantec Corporation
  */
  struct CatPositionRec
  {
    long initialize; /**< starting point*/
    short priv[];    /**< private data*/
  } CatPositionRec;  /**< */

  typedef struct CatPositionRec CatPositionRec;
  /**
  <pre>
   * \note <pre>The FSSpec record can describe only a file or a directory, not a volume. A
  volume can be identified by its root directory, although the system software
  never uses an FSSpec record to describe a volume. (The directory ID of the
  root's parent directory is fsRtParID, defined in the interface files. The name
  of the root directory is the same as the name of the volume.) Some of the
  system software uses arrays of FSSpec records.
  </pre>
   * \copyright THINK Reference © 1991-1992 Symantec Corporation
  */
  struct FSSpec
  {
    short vRefNum; /**< volume reference number*/
    long parID;    /**< directory ID of parent directory*/
    Str name;      /**< filename or directory name*/
  } FSSpec;        /**< */

  typedef struct FSSpec FSSpec;
  typedef FSSpec *FSSpecPtr;
  typedef FSSpecPtr *FSSpecHandle;
  /* pointer to array of FSSpecs */
  typedef FSSpecPtr FSSpecArrayPtr;
  /**
      The only difference between "const FSSpec*" and "ConstFSSpecPtr" is
      that as a parameter, ConstFSSpecPtr is allowed to be NULL
  */
  typedef const FSSpec *ConstFSSpecPtr;
  /**
      The following are structures to be filled out with the _PBGetVolMountInfo
     call and passed back into the _PBVolumeMount call for external file system
     mounts.
  */
  /* the "signature" of the file system */
  typedef OSType VolumeType;
  enum
  {
    /* the signature for AppleShare */
    AppleShareMediaType = FOUR_CHAR_CODE('afpm')
  };

  /**
      VolMount stuff was once in FSM.©
  */
  /**
  <pre>
   * \note <pre>The size and contents of the record can vary, depending on the external file
  system that's handling the particular volume.
  The length field contains the length of the structure (that is, the total
  length of the structure header described here plus the variable-length
  location data). The length of the record is flexible so that non-Macintosh
  file systems can store whatever information they need for volume
  mounting.
  The media field identifies the volume type of the remote volume. The value
  AppleShareMediaType (a constant that translates to 'afpm') represents an
  AppleShare volume. If you are adding support for the programmatic
  mounting functions to a non-Macintosh file system, you should register a
  four-character identifier for your volumes with Macintosh Developer
  Technical Support at Apple.
  The only volumes that currently support the programmatic mounting
  functions are AppleShare servers, which use this volume mounting record.
  </pre>
   * \copyright THINK Reference © 1991-1992 Symantec Corporation
  */
  struct VolMountInfoHeader
  {
    short length;       /**<  length of mounting*/
    VolumeType media;   /**< n type of volume,*/
  } VolMountInfoHeader; /**< +n*/

  typedef struct VolMountInfoHeader VolMountInfoHeader;
  typedef VolMountInfoHeader *VolMountInfoPtr;
  /* The new volume mount info record.  The old one is included for compatibility.
      the new record allows access by foriegn filesystems writers to the flags
      portion of the record. This portion is now public.
  */
  struct VolumeMountInfoHeader
  {
    short length;     /* length of location data (including self) */
    VolumeType media; /* type of media (must be registered with Apple) */
    short flags;      /* volume mount flags. Variable length data follows */
  };
  typedef struct VolumeMountInfoHeader VolumeMountInfoHeader;
  typedef VolumeMountInfoHeader *VolumeMountInfoHeaderPtr;
  /* volume mount flags */
  enum
  {
    volMountNoLoginMsgFlagBit =
        0, /* Input to VolumeMount: If set, the file system */
    volMountNoLoginMsgFlagMask =
        0x0001, /*  should suppresss any log-in message/greeting dialog */
    volMountExtendedFlagsBit =
        7, /* Input to VolumeMount: If set, the mount info is a */
    volMountExtendedFlagsMask =
        0x0080, /*  AFPXVolMountInfo record for 3.7 AppleShare Client */
    volMountInteractBit =
        15, /* Input to VolumeMount: If set, it's OK for the file system */
    volMountInteractMask =
        0x8000, /*  to perform user interaction to mount the volume */
    volMountChangedBit =
        14, /* Output from VoumeMount: If set, the volume was mounted, but */
    volMountChangedMask =
        0x4000, /*  the volume mounting information record needs to be updated. */
    volMountFSReservedMask =
        0x00FF, /* bits 0-7 are defined by each file system for its own use */
    volMountSysReservedMask =
        0xFF00 /* bits 8-15 are reserved for Apple system use */
  };

  /**
  <pre>
   * \note <pre>The length and media fields in the AFP volume mounting record are the
  same as the length and media fields in the generic volume mounting record.
  The nbpInterval and nbpCount fields are used by the AppleTalk
  Name-Binding Protocol (NBP). Their functions are described in the
  AppleTalk Manager .
  The uamType field specifies the access-control method used by the remote
  volume. AppleShare uses four methods:
  kNoUserAuthentication guest status; no password needed
  kPassword 8-byte password
  kEncryptPassword encrypted 8-byte password
  kTwoWayEncryptPassword two-way random encryption; authenticate both
  user and server
  The six offset fields contain the offsets from the beginning of the record, in
  bytes, to the entries in the data field of the volume's AppleShare zone and
  server name, the volume name, the name of the user, the user's password,
  and the volume password.
  </pre>
   * \copyright THINK Reference © 1991-1992 Symantec Corporation
  */
  struct AFPVolMountInfo
  {
    short length;             /**< length of mounting*/
    VolumeType media;         /**< type of volume,*/
    short flags;              /**< reserved;/**< must be set to */
    char nbpInterval;         /**< NBP retry interval*/
    char nbpCount;            /**< NBP retry count*/
    short uamType;            /**< user authentication method*/
    short zoneNameOffset;     /**< offset from start of record  to*/
    short serverNameOffset;   /**< offset from start of record to*/
    short volNameOffset;      /**< offset from start of record  to*/
    short userNameOffset;     /**< offset from start of record to*/
    short userPassWordOffset; /**<  offset from start of record to*/
    short volPassWordOffset;  /**<  offset from start of record to*/
    char AFPData[];           /**<  standard AFP mounting info,*/
  } AFPVolMountInfo;          /**<*/

  typedef struct AFPVolMountInfo AFPVolMountInfo;
  typedef AFPVolMountInfo *AFPVolMountInfoPtr;

  /* AFPXVolMountInfo is the new AFP volume mount info record, requires the 3.7
   * AppleShare Client */
  struct AFPXVolMountInfo
  {
    short length;                 /* length of location data (including self) */
    VolumeType media;             /* type of media */
    short flags;                  /* bits for no messages, no reconnect */
    SInt8 nbpInterval;            /* NBP Interval parameter (IM2, p.322) */
    SInt8 nbpCount;               /* NBP Interval parameter (IM2, p.322) */
    short uamType;                /* User Authentication Method type */
    short zoneNameOffset;         /* short positive offset from start of struct to Zone
                                     Name */
    short serverNameOffset;       /* offset to pascal Server Name string */
    short volNameOffset;          /* offset to pascal Volume Name string */
    short userNameOffset;         /* offset to pascal User Name string */
    short userPasswordOffset;     /* offset to pascal User Password string */
    short volPasswordOffset;      /* offset to pascal Volume Password string */
    short extendedFlags;          /* extended flags word */
    short uamNameOffset;          /* offset to a pascal UAM name string */
    short alternateAddressOffset; /* offset to Alternate Addresses in tagged
                                     format */
    char AFPData[176];            /* variable length data may follow */
  };
  typedef struct AFPXVolMountInfo AFPXVolMountInfo;
  typedef AFPXVolMountInfo *AFPXVolMountInfoPtr;
  enum
  {
    kAFPExtendedFlagsAlternateAddressMask =
        1 /*  bit in AFPXVolMountInfo.extendedFlags that means
             alternateAddressOffset is used*/
  };

  enum
  {
    /* constants for use in AFPTagData.fType field*/
    kAFPTagTypeIP = 0x01,     /* 4 byte IP address (MSB first)            */
    kAFPTagTypeIPPort = 0x02, /* 4 byte IP address, 2 byte port (MSB first)     */
    kAFPTagTypeDDP = 0x03,    /* Net,Node,Socket Sent by the server, currently unused
                                 by the client */
    kAFPTagTypeDNS = 0x04     /* DNS name in  address:port format   (total length
                                 variable up to 254 chars of dns name)          */
  };

  enum
  {
    /* constants for use in AFPTagData.fLength field*/
    kAFPTagLengthIP = 0x06,
    kAFPTagLengthIPPort = 0x08,
    kAFPTagLengthDDP = 0x06
  };

  struct AFPTagData
  {
    UInt8 fLength; /* length of this data tag including the fLength field */
    UInt8 fType;
    UInt8 fData[1]; /* variable length data */
  };
  typedef struct AFPTagData AFPTagData;
  struct AFPAlternateAddress
  {
    /* ©©©©NOTE: fVersion was missing in 3.2 Universal Interfaces*/
    UInt8 fVersion; /* version of the structure (currently 0x00)*/
    UInt8 fAddressCount;
    UInt8 fAddressList[1]; /* actually variable length packed set of AFPTagData */
  };
  typedef struct AFPAlternateAddress AFPAlternateAddress;
  /**
  <pre>
   * \note <pre>This structure is used in calls that manipulate the desktop database:
  PBDTAddAPPL PBDTGetComment PBDTRemoveAPPL
  PBDTAddIcon PBDTGetIcon PBDTRemoveComment
  PBDTCloseDown PBDTGetIconInfo PBDTReset
  PBDTDelete PBDTGetInfo PBDTSetComment
  PBDTFlush PBDTGetPath
  PBDTGetAPPL PBDTOpenInform
  </pre>
   * \copyright THINK Reference © 1991-1992 Symantec Corporation
  */
  struct DTPBRec
  {
    short ioDTRefNum;     /**< desktop refnum*/
    short ioIndex;        /**< */
    long ioTagInfo;       /**< */
    Ptr ioDTBuffer;       /**< */
    long ioDTReqCount;    /**< */
    long ioDTActCount;    /**< */
    char ioFiller;        /**< */
    char ioIconType;      /**< */
    short ioFiller;       /**< */
    long ioDirID;         /**< */
    OSType ioFileCreator; /**< */
    OSType ioFileType;    /**< */
    long ioFiller;        /**< */
    long ioDTLgLen;       /**< */
    long ioDTPyLen;       /**< */
    short ioFiller[];     /**< */
    long ioAPPLParID;     /**< */
  } DTPBRec;              /**< */

  typedef struct DTPBRec DTPBRec;
  typedef DTPBRec *DTPBPtr;

  struct HIOParam
  {
    QElemPtr qLink;               /*queue link in header*/
    short qType;                  /*type byte for safety check*/
    short ioTrap;                 /*FS: the Trap*/
    Ptr ioCmdAddr;                /*FS: address to dispatch to*/
    IOCompletionUPP ioCompletion; /*completion routine addr (0 for synch calls)*/
    volatile OSErr ioResult;      /*result code*/
    StringPtr ioNamePtr;          /*ptr to Vol:FileName string*/
    short ioVRefNum;              /*volume refnum (DrvNum for Eject and MountVol)*/
    short ioRefNum;
    SInt8 ioVersNum;
    SInt8 ioPermssn;
    Ptr ioMisc;
    Ptr ioBuffer;
    long ioReqCount;
    long ioActCount;
    short ioPosMode;
    long ioPosOffset;
  };
  typedef struct HIOParam HIOParam;
  typedef HIOParam *HIOParamPtr;
  /**
  <pre>
   * \note <pre>The HFileParam structure is used HFS-specific calls ( PBHxxx) calls
  which typically operate on closed files:
  PBDirCreate PBHGetFInfo PBHRename PBHSetFLock
  PBHCreate PBHOpen PBHRstFLock
  PBHDelete PBHOpenRF PBHSetFInfo
  It is identical to FileParam in length, but the ioDirID field at offset 48 has
  changed names and meanings. Use this to specify a 'Hard' directory ID if you
  happen to have one. Use 0 to use the normal volume or working directory
  reference number in ioVRefNum.
  The most common way to use this structure is to allocate a union which is
  </pre>
   * \copyright THINK Reference © 1991-1992 Symantec Corporation
  */
  struct HFileParam
  {
    struct QElem *qLink;       /**< Address of next queue element*/
    short qType;               /**< Always ioQType ()*/
    short ioTrap;              /**< (used internally by File Manager)*/
    Ptr ioCmdAddr;             /**< (used internally by File Manager)*/
    ProcPtr ioCompletion;      /**< Completion routine address*/
    OSErr ioResult;            /**< Error code (=no error, =not done*/
    StringPtr ioNamePtr;       /**< Addr of full or partial path/filename*/
    short ioVRefNum;           /**< Volume, drive, or directory*/
    short ioFRefNum;           /**< File reference number*/
    char ioFVersNum;           /**< Version (use  for HFS)*/
    char filler;               /**< (unused)*/
    short ioFDirIndex;         /**< Index*/
    char ioFlAttrib;           /**< File Attribute  bits (locked,*/
    char ioFlVersNum;          /**< File version (best to use )*/
    FInfo ioFlFndrInfo;        /**< File type, creator, flags, etc. (see*/
    long ioDirID;              /**< 'Hard' Directory ID*/
    unsigned short ioFlStBlk;  /**< First allocation block of data fork*/
    long ioFlLgLen;            /**< Logical end-of-file of data fork*/
    long ioFlPyLen;            /**< Physical end-of-file of data fork*/
    unsigned short ioFlRStBlk; /**< First allocation block of resource*/
    long ioFlRLgLen;           /**< Logical end-of-file of resource fork*/
    long ioFlRPyLen;           /**< Physical end-of-file of resource*/
    unsigned long ioFlCrDat;   /**< Date/time of creation (seconds since*/
    unsigned long ioFlMdDat;   /**< Date/Time of last modification*/
  } HFileParam;                /**< */

  typedef struct HFileParam HFileParam;
  typedef HFileParam *HFileParamPtr;
  /**
  <pre>
   * \note <pre>The HVolumeParam structure is used specifically in only the
  PBHGetVInfo and PBSetVInfo functions which query or change
  information about HFS volumes.
  Some fields match up with fields from the older VolumeParam structure
  </pre>
   * \copyright THINK Reference © 1991-1992 Symantec Corporation
  */
  struct HVolumeParam
  {
    long filler;                /**< (reserved)*/
    short ioVolIndex;           /**< (>: index, <: use name/num, :*/
    unsigned long ioVCrDate;    /**< Date/time volume created*/
    unsigned long ioVLsMod;     /**< Date/time volume information was*/
    short ioVAtrb;              /**< Volume Attributes*/
    unsigned short ioVNmFls;    /**< Count of files in the root directory*/
    short ioVBitMap;            /**< Sector of start of volume bit map*/
    short ioAllocPtr;           /**< Block at which next new file will*/
    unsigned short ioVNmAlBlks; /**< Total allocation blocks on the volume*/
    long ioVAlBlkSiz;           /**< Size of an allocation block, in bytes*/
    long ioVClpSiz;             /**< Default allocation clump size, in*/
    short ioAlBlSt;             /**< First sector represented in bit map*/
    long ioVNxtCNID;            /**< Next serial number for new file or*/
    unsigned short ioVFrBlk;    /**< Number of unused allocation blocks*/
    unsigned short ioVSigWord;  /**< Volume signature: xDD=flat,*/
    short ioVDrvInfo;           /**< Drive number*/
    short ioVDRefNum;           /**< Driver reference number*/
    short ioVFSID;              /**< File system identifier ( =native;/**<*/
    unsigned long ioVBkUp;      /**< Date/Time of last backup*/
    unsigned short ioVSeqNum;   /**< Sequence number (if this is a backup*/
    long ioVWrCnt;              /**< Volume write count*/
    long ioVFilCnt;             /**< Total number of files on the volume*/
    long ioVDirCnt;             /**< Total number of directories on the*/
    long ioVFndrInfo[];         /**< Data used by Finder (mostly*/
  } HVolumeParam;               /**< */

  typedef struct HVolumeParam HVolumeParam;
  typedef HVolumeParam *HVolumeParamPtr;
  struct XIOParam
  {
    QElemPtr qLink;
    short qType;
    short ioTrap;
    Ptr ioCmdAddr;
    IOCompletionUPP ioCompletion;
    volatile OSErr ioResult;
    StringPtr ioNamePtr;
    short ioVRefNum;
    short ioRefNum;
    SInt8 ioVersNum;
    SInt8 ioPermssn;
    Ptr ioMisc;
    Ptr ioBuffer;
    long ioReqCount;
    long ioActCount;
    short ioPosMode;   /* must have kUseWidePositioning bit set */
    wide ioWPosOffset; /* wide positioning offset */
  };
  typedef struct XIOParam XIOParam;
  typedef XIOParam *XIOParamPtr;
  struct XVolumeParam
  {
    QElemPtr qLink;
    short qType;
    short ioTrap;
    Ptr ioCmdAddr;
    IOCompletionUPP ioCompletion;
    volatile OSErr ioResult;
    StringPtr ioNamePtr;
    short ioVRefNum;
    unsigned long ioXVersion; /* this XVolumeParam version (0) */
    short ioVolIndex;
    unsigned long ioVCrDate;
    unsigned long ioVLsMod;
    short ioVAtrb;
    unsigned short ioVNmFls;
    unsigned short ioVBitMap;
    unsigned short ioAllocPtr;
    unsigned short ioVNmAlBlks;
    unsigned long ioVAlBlkSiz;
    unsigned long ioVClpSiz;
    unsigned short ioAlBlSt;
    unsigned long ioVNxtCNID;
    unsigned short ioVFrBlk;
    unsigned short ioVSigWord;
    short ioVDrvInfo;
    short ioVDRefNum;
    short ioVFSID;
    unsigned long ioVBkUp;
    short ioVSeqNum;
    unsigned long ioVWrCnt;
    unsigned long ioVFilCnt;
    unsigned long ioVDirCnt;
    long ioVFndrInfo[8];
    UInt64 ioVTotalBytes; /* total number of bytes on volume */
    UInt64 ioVFreeBytes;  /* number of free bytes on volume */
  };
  typedef struct XVolumeParam XVolumeParam;
  typedef XVolumeParam *XVolumeParamPtr;
  /**
  <pre>
   * \note <pre> The AccessParam structure is used in shared environments to define
  the extent of access privileges for specific files, volumes and
  directories.
  The most common way to use this structure is to allocate a union that
  is an aggregate and create and initialize a pointer to the desired data
  type. See HParamBlockRec for an example.
  The ioACAccess field consists of a long integer with the format:
  uueeggoo. uu represents the user's rights, ee represents everyone's
  rights, gg represents the group's rights and oo represents the owner's
  rights. It can be represented as:
  From left to right,
  bit 7 is set if the user is not the directory's owner
  bits 6-5 are reserved and are returned set to 0
  </pre>
   * \copyright THINK Reference © 1991-1992 Symantec Corporation
  */
  struct AccessParam
  {
    short filler;      /**< */
    short ioDenyModes; /**< access rights data*/
    short filler;      /**< */
    char filler;       /**< */
    char ioACUser;     /**< access rights for directory only*/
    long filler;       /**< */
    long ioACOwnerID;  /**< owner ID*/
    long ioACGroupID;  /**< group ID*/
    long ioACAccess;   /**< access rights*/
  } AccessParam;       /**< */

  typedef struct AccessParam AccessParam;
  typedef AccessParam *AccessParamPtr;
  /**
  <pre>
   * \copyright THINK Reference © 1991-1992 Symantec Corporation
  */
  struct ObjParam
  {
    short filler;     /**< */
    short ioObjType;  /**< function code*/
    Ptr ioObjNamePtr; /**< pointer to returned creator/group*/
    long ioReqCount;  /**< size of buffer area*/
    long ioActCount;  /**< length of volume parameter data*/
  } ObjParam;         /**< */

  typedef struct ObjParam ObjParam;
  typedef ObjParam *ObjParamPtr;
  /**
  <pre>
   * \copyright THINK Reference © 1991-1992 Symantec Corporation
  */
  struct CopyParam
  {
    short ioDstVRefNum;   /**< destination volume identifier*/
    short filler;         /**< */
    StringPtr ioNewName;  /**< pointer to destination pathname*/
    StringPtr ioCopyName; /**< pointer to optional name*/
    long ioNewDirID;      /**< destination directory ID*/
    long filler;          /**< */
    long filler;          /**< */
    long ioDirID;         /**< source directory ID*/
  } CopyParam;            /**< */

  typedef struct CopyParam CopyParam;
  typedef CopyParam *CopyParamPtr;
  /**
  <pre>
   * \copyright THINK Reference © 1991-1992 Symantec Corporation
  */
  struct WDParam
  {
    short filler;      /**< */
    short ioWDIndex;   /**< */
    long ioWDProcID;   /**< */
    short ioWDVRefNum; /**< */
    short filler;      /**< */
    long filler;       /**< */
    long filler;       /**< */
    long filler;       /**< */
    long ioWDDirID;    /**< */
  } WDParam;           /**< */

  typedef struct WDParam WDParam;
  typedef WDParam *WDParamPtr;
  /**
  <pre>
   * \note <pre>This structure is used in procedures that manipulate file id's:
  PBCreateFileIDRef PBDeleteFileIDRef
  PBExchangeFiles PBResolveFileIDRef
  The ioDestNamePtr and ioDestDirID fields are used only with the
  PBExchangeFiles function.
  The most common way to use this structure is to allocate a union which is
  an aggregate and create and initialize a pointer to the desired data type. See
  HParamBlockRec for examples.
  </pre>
   * \copyright THINK Reference © 1991-1992 Symantec Corporation
  */
  struct FIDParam
  {
    long filler;             /**< filler*/
    StringPtr ioDestNamePtr; /**< pointer to destination filename*/
    long filler;             /**< filler*/
    long ioDestDirID;        /**< destination parent directory ID*/
    long;                    /**< filler;/**< filler*/
    long;                    /**< filler;/**< filler*/
    long ioSrcDirID;         /**< source parent directory ID*/
    short filler;            /**< filler*/
  } FIDParam;                /**< */

  typedef struct FIDParam FIDParam;
  typedef FIDParam *FIDParamPtr;
  /**
  <pre>
   * \note <pre>The File Manager provides two functions ( PBGetForeignPrivs and
  PBSetForeignPrivs ) that an application or shell program can use to
  communicate with a foreign file system about its native access-control
  system. The functions retrieve and set access permissions on the foreign
  file system. The access-control functions use the new
  ForeignPrivParam parameter block variant.
  The most common way to use this structure is to allocate a union that is an
  aggregate and create and initialize a pointer to the desired data type. See
  HParamBlockRec for an example.
  </pre>
   * \copyright THINK Reference © 1991-1992 Symantec Corporation
  */
  struct ForeignPrivParam
  {
    long filler;                /**< filler*/
    long filler;                /**< filler*/
    Ptr ioForeignPrivBuffer;    /**< privileges data*/
    long ioForeignPrivReqCount; /**< size of buffer*/
    long ioForeignPrivActCount; /**< amount of buffer used*/
    long filler;                /**< filler*/
    long ioForeignPrivDirID;    /**< parent directory ID of*/
    long ioForeignPrivInfo;     /**< privileges data*/
    long ioForeignPrivInfo;     /**< privileges data*/
    long ioForeignPrivInfo;     /**< privileges data*/
    long ioForeignPrivInfo;     /**< privileges data*/
  } ForeignPrivParam;           /**< */

  typedef struct ForeignPrivParam ForeignPrivParam;
  typedef ForeignPrivParam *ForeignPrivParamPtr;
  /**
  <pre>
   * \note <pre>This structure is used in the File Manager call PBCatSearch which
  provides a way to efficiently search a volume's catalog.:
  The most common way to use this structure is to allocate a union which is
  an aggregate and create and initialize a pointer to the desired data type. See
  HParamBlockRec for examples.
  </pre>
   * \copyright THINK Reference © 1991-1992 Symantec Corporation
  */
  struct CSParam
  {
    FSSpecPtr ioMatchPtr;         /**< match array*/
    long ioReqMatchCount;         /**< maximum allowable matches*/
    long ioActMatchCount;         /**< actual match count*/
    long ioSearchBits;            /**< search criteria selector*/
    CInfoPBPtr ioSearchInfo;      /**< search values and range lower*/
    CInfoPBPtr ioSearchInfo;      /**< search values and range upper*/
    long ioSearchTime;            /**< length of time to run search*/
    CatPositionRec ioCatPosition; /**< current position in catalog*/
    Ptr ioOptBuffer;              /**< optional performance enhancement*/
    long ioOptBufSize;            /**< size of buffer pointed to by*/
  } CSParam;                      /**< */

  typedef struct CSParam CSParam;
  typedef CSParam *CSParamPtr;
  /**
  <pre>union structure)
  convention
  </pre>
   * \note <pre>All ten structures on this union share the same names for the first eight
  fields (the first 24 bytes). These fields are also the same in the flat file
  system version ParamBlockRec . These common fields are defined in a
  macro as the ParamBlockHeader .
  This is the HFS variation of the ParamBlockRec . It should be used in
  HFS-specific calls ( PBHxxx).  A typical technique for using parameter
  blocks is to allocate the HParamBlockRec union and create pointers that
  refer to the relevant structure data types:
  HParamBlockRec hpb; /* allocate a union */
  HIOParam *hipb = (HIOParam *)&hpb;     /* and struc ptrs */
  HFileParam *hfpb = (HFileParam *)&hpb; /* all point same addr */
  HVolumeParam *hvpb = (HVolumeParam *)&hpb;
  AccessParam *hapb = (AccessParam *)&hpb;
  ObjParam *hopb = (ObjParam *)&hpb;
  CopyParam *hcpb = (CopyParam *)&hpb;
  WDParam *hwpb = (WDParam *)&hpb;
  hpb.ioParam.ioVRefNum = 2; /* as a union member */
  hpb.fileParam.ioFlFndrInfo.fdType = 'TEXT';
  hpb.volumeParam.ioVolIndex = 0;
  hpb.accessParam.ioDenyModes = 0;
  hpb.objParam.ioObjType = 2;
  hpb.copyParam.ioDstVRefNum = 1;
  hpb.wdParam.ioWDIndex = 1;
  hipb->ioVRefNum = 2; /* or as a structure field */
  hfpb->ioFlFndrInfo.fdType = 'TEXT';
  </ pre>
          * \copyright THINK Reference © 1991 - 1992 Symantec Corporation
                                                        * /
                                                    union HParamBlockRec
  {
    HIOParam ioParam;                  /**< Generally used in I/O for open files*/
    HFileParam fileParam;              /**< Used for unopened files*/
    HVolumeParam volumeParam;          /**< Used in volume-specific functions*/
    AccessParam accessParam;           /**< Used in shared environment calls*/
    ObjParam objParam;                 /**< Used in shared environment calls*/
    CopyParam copyParam;               /**< Used in shared environment calls*/
    WDParam wdParam;                   /**< Used in shared environment calls*/
    FIDParam fidParam;                 /**< Used in calls which manipulate File*/
    CSParam csParam;                   /**< Used by PBCatSearch*/
    ForeignPrivParam foreignPrivParam; /**< Used for communication with foreign*/
  } HParamBlockRec;                    /**< (size of aggregate - largest struct in*/

  typedef union HParamBlockRec HParamBlockRec;

  typedef HParamBlockRec *HParmBlkPtr;

  /**
  <pre>
   * \note <pre>Use this CMovePBRec structure in calls to PBCatMove .
  The original name is specified in ioVRefNum and ioNamePtr and ioDirID (if
  ioDirID is 0, the directory must be identified in ioVRefNum and/or
  ioNamePtr).
  The file's directory entry is moved into the ioNewDirID directory (unless
  it is 0, in which case ioNewName must contain the full path and filename).
  The file's one-element filename (ie, the last part of the string) must be the
  same in both ioNamePtr and ioNewName.
  </pre>
   * \copyright THINK Reference © 1991-1992 Symantec Corporation
  */
  struct CMovePBRec
  {
    struct QElem *qLink;  /**< Address of next queue element*/
    short qType;          /**< Always ioQType ()*/
    short ioTrap;         /**< (used internally by File Manager)*/
    Ptr ioCmdAddr;        /**< (used internally by File Manager)*/
    ProcPtr ioCompletion; /**< Completion routine address (see*/
    OSErr ioResult;       /**< Error Code  (=no error, =not done*/
    StringPtr ioNamePtr;  /**< Address of p-string of current*/
    short ioVRefNum;      /**< Volume or working directory*/
    long filler;          /**< (unused)*/
    StringPtr ioNewName;  /**< Addr of p-string of desired path and*/
    long filler;          /**< (unused)*/
    long filler[];        /**< (unused)*/
    long ioDirID;         /**< 'Hard' ID of destination directory*/
  } CMovePBRec;           /**< */

  typedef struct CMovePBRec CMovePBRec;
  typedef CMovePBRec *CMovePBPtr;
  struct WDPBRec
  {
    QElemPtr qLink;
    short qType;
    short ioTrap;
    Ptr ioCmdAddr;
    IOCompletionUPP ioCompletion;
    volatile OSErr ioResult;
    StringPtr ioNamePtr;
    short ioVRefNum;
    short filler1;
    short ioWDIndex;
    long ioWDProcID;
    short ioWDVRefNum;
    short filler2[7];
    long ioWDDirID;
  };
  typedef struct WDPBRec WDPBRec;
  typedef WDPBRec *WDPBPtr;
  /**
  <pre>
   * \note <pre>Use this FCBPBRec structure in calls to PBGetFCBInfo (or to examine
  data starting 2 bytes beyond the address in the global variable FCBSPtr ).
  Note that ioVRefNum has an unusual meaning when ioFCBIndx is non-zero
  (i.e., when you want to index through FCBs of open files). It identifies
  where to search and may be a volume or working directory number, a drive
  number, or 0 (which indicates to index through all open files, no matter
  where they are).
  IM IV-180 defines ioFCBFlags masks as bits 0, 1, and 7, but that is based
  on a 1 byte value. If your compiler's headers lay this field out as an short,
  then use masks of 0x0100, 0x0200, and 0x8000, respectively.
  </pre>
   * \copyright THINK Reference © 1991-1992 Symantec Corporation
  */
  struct FCBPBRec
  {
    struct QElem *qLink;  /**< Address of next queue element*/
    short qType;          /**< Always ioQType ()*/
    short ioTrap;         /**< (used internally by File Manager)*/
    Ptr ioCmdAddr;        /**< (used internally by File Manager)*/
    ProcPtr ioCompletion; /**< Completion routine address (see*/
    OSErr ioResult;       /**< Error code  (=no error, =not done*/
    StringPtr ioNamePtr;  /**< Address of p-string of current*/
    short ioVRefNum;      /**< Volume, drive, or working directory*/
    short ioRefNum;       /**< File reference number (from*/
    short filler;         /**< (unused)*/
    short ioFCBIndx;      /**< Index (or  if not indexing)*/
    short Filler;         /**< (unused, error in IM IV)*/
    long ioFCBFlNm;       /**< Unique 'hard' file number*/
    short ioFCBFlags;     /**< Flags  (see notes)*/
    short ioFCBStBlk;     /**< First allocation block*/
    long ioFCBEOF;        /**< Logical EOF (file size, in bytes)*/
    long ioFCBPLen;       /**< Physical EOF*/
    long ioFCBCrPs;       /**< Current file position (mark)*/
    short ioFCBVRefNum;   /**< 'Hard' volume reference number*/
    long ioFCBClpSiz;     /**< File clump size (minimum allocation*/
    long ioFCBParID;      /**< Parent's 'Hard' Directory ID*/
  } FCBPBRec;             /**< */

  typedef struct FCBPBRec FCBPBRec;
  typedef FCBPBRec *FCBPBPtr;
  /**
  <pre>*/
  struct VCB
  {
    struct QElem *qLink;        /**< Address of next queue element*/
    short qType;                /**< Always fsQType ()*/
    short vcbFlags;             /**< Bit = when volume needs*/
    unsigned short vcbSigWord;  /**< File sys signature: x=HFS,*/
    unsigned long vcbCrDate;    /**< Date/Time of initialization*/
    unsigned long vcbLsMod;     /**< Date/Time of last modification **/
    short vcbAtrb;              /**< Volume Attributes*/
    unsigned short vcbNmFls;    /**< Number of files in the root directory*/
    short vcbVBMSt;             /**< Sector of start of volume bit map **/
    short vcbAllocPtr;          /**< (internal: start looking for free*/
    unsigned short vcbNmAlBlks; /**< Total allocation blocks on volume **/
    long vcbAlBlkSiz;           /**< Size of an allocation block, in bytes*/
    long vcbClpSiz;             /**< Default clump size, in bytes*/
    short vcbAlBlSt;            /**< First sector represented in bit map*/
    long vcbNxtCNID;            /**< Next serial number for new file or*/
    unsigned short vcbFreeBks;  /**< Number of unused allocation blocks*/
    Str vcbVN;                  /**< Length-prefixed volume name*/
    short vcbDrvNum;            /**< Drive number*/
    short vcbDRefNum;           /**< Driver reference number*/
    short vcbFSID;              /**< File system ID (=native;/**<*/
    short vcbVRefNum;           /**< Volume reference number*/
    Ptr vcbMAdr;                /**< Address in memory of block bit map*/
    Ptr vcbBufAdr;              /**< Address of volume I/O buffer*/
    short vcbMLen;              /**< Size of block bit map, in bytes*/
    short vcbDirIndex;          /**< (used internally)*/
    short vcbDirBlk;            /**< (used internally) (* last field if*/
    unsigned long vcbVolBkUp;   /**< Date/Time of last backup*/
    unsigned short vcbVSeqNum;  /**< Sequence number (if this is a backup*/
    long vcbWrCnt;              /**< Volume write count*/
    long vcbXTClpSiz;           /**< Clump size of extents tree file*/
    long vcbCTClpSiz;           /**< Clump size of catalog tree file*/
    unsigned short vcbNmRtDirs; /**< Number of directories in the root*/
    long vcbFilCnt;             /**< Total number of files on the volume*/
    long vcbDirCnt;             /**< Total number of directories on the*/
    long vcbFndrInfo[];         /**<Data used by Finder*/

    typedef struct VCB VCB;
    typedef VCB *VCBPtr;
    struct DrvQEl
    {
      QElemPtr qLink;
      short qType;
      short dQDrive;
      short dQRefNum;
      short dQFSID;
      unsigned short dQDrvSz;
      unsigned short dQDrvSz2;
    };
    typedef struct DrvQEl DrvQEl;
    typedef DrvQEl *DrvQElPtr;
    /**
     *  NewIOCompletionUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    IOCompletionUPP
    NewIOCompletionUPP(IOCompletionProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
    enum
    {
      uppIOCompletionProcInfo = 0x00009802
    }; /* register no_return_value Func(4_bytes:A0) */
#ifdef __cplusplus
    inline IOCompletionUPP NewIOCompletionUPP(IOCompletionProcPtr userRoutine)
    {
      return (IOCompletionUPP)NewRoutineDescriptor((ProcPtr)(userRoutine),
                                                   uppIOCompletionProcInfo,
                                                   GetCurrentArchitecture());
    }
#else
#define NewIOCompletionUPP(userRoutine)                                     \
  (IOCompletionUPP)                                                         \
      NewRoutineDescriptor((ProcPtr)(userRoutine), uppIOCompletionProcInfo, \
                           GetCurrentArchitecture())
#endif
#endif

    /**
     *  DisposeIOCompletionUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    DisposeIOCompletionUPP(IOCompletionUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline void DisposeIOCompletionUPP(IOCompletionUPP userUPP)
    {
      DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
    }
#else
#define DisposeIOCompletionUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

/**
 *  InvokeIOCompletionUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter InvokeIOCompletionUPP(__A0, __A1)
#endif
    void
    InvokeIOCompletionUPP(ParmBlkPtr paramBlock, IOCompletionUPP userUPP)
        ONEWORDINLINE(0x4E91);
#if !OPAQUE_UPP_TYPES && \
    (!TARGET_OS_MAC || !TARGET_CPU_68K || TARGET_RT_MAC_CFM)
#ifdef __cplusplus
    inline void InvokeIOCompletionUPP(ParmBlkPtr paramBlock,
                                      IOCompletionUPP userUPP)
    {
      CALL_ONE_PARAMETER_UPP(userUPP, uppIOCompletionProcInfo, paramBlock);
    }
#else
#define InvokeIOCompletionUPP(paramBlock, userUPP) \
  CALL_ONE_PARAMETER_UPP((userUPP), uppIOCompletionProcInfo, (paramBlock))
#endif
#endif

#if CALL_NOT_IN_CARBON || OLDROUTINENAMES
/* support for pre-Carbon UPP routines: New...Proc and Call...Proc */
#define NewIOCompletionProc(userRoutine) NewIOCompletionUPP(userRoutine)
#define CallIOCompletionProc(userRoutine, paramBlock) \
  InvokeIOCompletionUPP(paramBlock, userRoutine)
#endif /* CALL_NOT_IN_CARBON */

    /**
       PBOpenSync(), PBOpenAsync(), PBOpenImmed() were moved to Devices.h
       PBCloseSync(), PBCloseAsync(), PBCloseImmed() were moved to Devices.h
       PBReadSync(), PBReadAsync(), PBReadImmed() were moved to Devices.h
       PBWriteSync(), PBWriteAsync(), PBWriteImmed() were moved to Devices.h
    */

#if CALL_NOT_IN_CARBON
/**
 *  PBGetVInfoSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBGetVInfoSync(__A0)
#endif
    OSErr PBGetVInfoSync(ParmBlkPtr paramBlock) ONEWORDINLINE(0xA007);

/**
 *  PBGetVInfoAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBGetVInfoAsync(__A0)
#endif
    OSErr PBGetVInfoAsync(ParmBlkPtr paramBlock) ONEWORDINLINE(0xA407);

#endif /* CALL_NOT_IN_CARBON */

/**
 *  PBXGetVolInfoSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 8.5 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBXGetVolInfoSync(__A0)
#endif
    OSErr
    PBXGetVolInfoSync(XVolumeParamPtr paramBlock) TWOWORDINLINE(0x7012, 0xA060);

/**
 *  PBXGetVolInfoAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 8.5 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBXGetVolInfoAsync(__A0)
#endif
    OSErr
    PBXGetVolInfoAsync(XVolumeParamPtr paramBlock) TWOWORDINLINE(0x7012, 0xA460);

#if CALL_NOT_IN_CARBON
/**
 *  PBGetVolSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBGetVolSync(__A0)
#endif
    OSErr PBGetVolSync(ParmBlkPtr paramBlock) ONEWORDINLINE(0xA014);

/**
 *  PBGetVolAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBGetVolAsync(__A0)
#endif
    OSErr PBGetVolAsync(ParmBlkPtr paramBlock) ONEWORDINLINE(0xA414);

/**
 *  PBSetVolSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBSetVolSync(__A0)
#endif
    OSErr PBSetVolSync(ParmBlkPtr paramBlock) ONEWORDINLINE(0xA015);

/**
 *  PBSetVolAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBSetVolAsync(__A0)
#endif
    OSErr PBSetVolAsync(ParmBlkPtr paramBlock) ONEWORDINLINE(0xA415);

#endif /* CALL_NOT_IN_CARBON */

/**
 *  PBFlushVolSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBFlushVolSync(__A0)
#endif
    OSErr PBFlushVolSync(ParmBlkPtr paramBlock) ONEWORDINLINE(0xA013);

/**
 *  PBFlushVolAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBFlushVolAsync(__A0)
#endif
    OSErr PBFlushVolAsync(ParmBlkPtr paramBlock) ONEWORDINLINE(0xA413);

#if CALL_NOT_IN_CARBON
/**
 *  PBHTrashVolumeCachesSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 9.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBHTrashVolumeCachesSync(__A0)
#endif
    OSErr
    PBHTrashVolumeCachesSync(ParmBlkPtr paramBlock) ONEWORDINLINE(0xA213);

/**
 *  PBCreateSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBCreateSync(__A0)
#endif
    OSErr PBCreateSync(ParmBlkPtr paramBlock) ONEWORDINLINE(0xA008);

/**
 *  PBCreateAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBCreateAsync(__A0)
#endif
    OSErr PBCreateAsync(ParmBlkPtr paramBlock) ONEWORDINLINE(0xA408);

/**
 *  PBDeleteSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBDeleteSync(__A0)
#endif
    OSErr PBDeleteSync(ParmBlkPtr paramBlock) ONEWORDINLINE(0xA009);

/**
 *  PBDeleteAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBDeleteAsync(__A0)
#endif
    OSErr PBDeleteAsync(ParmBlkPtr paramBlock) ONEWORDINLINE(0xA409);

/**
 *  PBOpenDFSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBOpenDFSync(__A0)
#endif
    OSErr
    PBOpenDFSync(ParmBlkPtr paramBlock) TWOWORDINLINE(0x701A, 0xA060);

/**
 *  PBOpenDFAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBOpenDFAsync(__A0)
#endif
    OSErr
    PBOpenDFAsync(ParmBlkPtr paramBlock) TWOWORDINLINE(0x701A, 0xA460);

/**
 *  PBOpenRFSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBOpenRFSync(__A0)
#endif
    OSErr PBOpenRFSync(ParmBlkPtr paramBlock) ONEWORDINLINE(0xA00A);

/**
 *  PBOpenRFAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBOpenRFAsync(__A0)
#endif
    OSErr PBOpenRFAsync(ParmBlkPtr paramBlock) ONEWORDINLINE(0xA40A);

/**
 *  PBRenameSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBRenameSync(__A0)
#endif
    OSErr PBRenameSync(ParmBlkPtr paramBlock) ONEWORDINLINE(0xA00B);

/**
 *  PBRenameAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBRenameAsync(__A0)
#endif
    OSErr PBRenameAsync(ParmBlkPtr paramBlock) ONEWORDINLINE(0xA40B);

/**
 *  PBGetFInfoSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBGetFInfoSync(__A0)
#endif
    OSErr PBGetFInfoSync(ParmBlkPtr paramBlock) ONEWORDINLINE(0xA00C);

/**
 *  PBGetFInfoAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBGetFInfoAsync(__A0)
#endif
    OSErr PBGetFInfoAsync(ParmBlkPtr paramBlock) ONEWORDINLINE(0xA40C);

/**
 *  PBSetFInfoSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBSetFInfoSync(__A0)
#endif
    OSErr PBSetFInfoSync(ParmBlkPtr paramBlock) ONEWORDINLINE(0xA00D);

/**
 *  PBSetFInfoAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBSetFInfoAsync(__A0)
#endif
    OSErr PBSetFInfoAsync(ParmBlkPtr paramBlock) ONEWORDINLINE(0xA40D);

/**
 *  PBSetFLockSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBSetFLockSync(__A0)
#endif
    OSErr PBSetFLockSync(ParmBlkPtr paramBlock) ONEWORDINLINE(0xA041);

/**
 *  PBSetFLockAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBSetFLockAsync(__A0)
#endif
    OSErr PBSetFLockAsync(ParmBlkPtr paramBlock) ONEWORDINLINE(0xA441);

/**
 *  PBRstFLockSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBRstFLockSync(__A0)
#endif
    OSErr PBRstFLockSync(ParmBlkPtr paramBlock) ONEWORDINLINE(0xA042);

/**
 *  PBRstFLockAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBRstFLockAsync(__A0)
#endif
    OSErr PBRstFLockAsync(ParmBlkPtr paramBlock) ONEWORDINLINE(0xA442);

/**
 *  PBSetFVersSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBSetFVersSync(__A0)
#endif
    OSErr PBSetFVersSync(ParmBlkPtr paramBlock) ONEWORDINLINE(0xA043);

/**
 *  PBSetFVersAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBSetFVersAsync(__A0)
#endif
    OSErr PBSetFVersAsync(ParmBlkPtr paramBlock) ONEWORDINLINE(0xA443);

#endif /* CALL_NOT_IN_CARBON */

/**
 *  PBAllocateSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBAllocateSync(__A0)
#endif
    OSErr PBAllocateSync(ParmBlkPtr paramBlock) ONEWORDINLINE(0xA010);

/**
 *  PBAllocateAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBAllocateAsync(__A0)
#endif
    OSErr PBAllocateAsync(ParmBlkPtr paramBlock) ONEWORDINLINE(0xA410);

/**
 *  PBGetEOFSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBGetEOFSync(__A0)
#endif
    OSErr PBGetEOFSync(ParmBlkPtr paramBlock) ONEWORDINLINE(0xA011);

/**
 *  PBGetEOFAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBGetEOFAsync(__A0)
#endif
    OSErr PBGetEOFAsync(ParmBlkPtr paramBlock) ONEWORDINLINE(0xA411);

/**
 *  PBSetEOFSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBSetEOFSync(__A0)
#endif
    OSErr PBSetEOFSync(ParmBlkPtr paramBlock) ONEWORDINLINE(0xA012);

/**
 *  PBSetEOFAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBSetEOFAsync(__A0)
#endif
    OSErr PBSetEOFAsync(ParmBlkPtr paramBlock) ONEWORDINLINE(0xA412);

/**
 *  PBGetFPosSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBGetFPosSync(__A0)
#endif
    OSErr PBGetFPosSync(ParmBlkPtr paramBlock) ONEWORDINLINE(0xA018);

/**
 *  PBGetFPosAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBGetFPosAsync(__A0)
#endif
    OSErr PBGetFPosAsync(ParmBlkPtr paramBlock) ONEWORDINLINE(0xA418);

/**
 *  PBSetFPosSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBSetFPosSync(__A0)
#endif
    OSErr PBSetFPosSync(ParmBlkPtr paramBlock) ONEWORDINLINE(0xA044);

/**
 *  PBSetFPosAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBSetFPosAsync(__A0)
#endif
    OSErr PBSetFPosAsync(ParmBlkPtr paramBlock) ONEWORDINLINE(0xA444);

/**
 *  PBFlushFileSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBFlushFileSync(__A0)
#endif
    OSErr PBFlushFileSync(ParmBlkPtr paramBlock) ONEWORDINLINE(0xA045);

/**
 *  PBFlushFileAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBFlushFileAsync(__A0)
#endif
    OSErr PBFlushFileAsync(ParmBlkPtr paramBlock) ONEWORDINLINE(0xA445);

#if CALL_NOT_IN_CARBON
/**
 *  PBMountVol()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBMountVol(__A0)
#endif
    OSErr PBMountVol(ParmBlkPtr paramBlock) ONEWORDINLINE(0xA00F);

#endif /* CALL_NOT_IN_CARBON */

    /**
    \brief Flush volume, close its files, release its memory

    <pre>PBUnmountVol flushes a volume buffer to disk and releases all memory
occupied by the volume buffer and related structures. The volume must be
re-mounted before it can be accessed.
pbis the address of a 64-byte VolumeParam structure or any of the
variants which contain all the relevant fields:
Out-In Name Type SizeOffsetDescription
->ioCompletion ProcPtr 412Completion routine address (if async =TRUE)
->ioNamePtr StringPtr 418Address of volume name (or NIL)
->ioVRefNum short 222Volume reference number of volume to unmount
<-ioResult OSErr 216Error Code (0=no error, 1=not done yet)
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
bdNamErr (-37) Bad name
fBsyErr (-47) Files are open on volume
extFSErr (-58) External file system
nsDrvErr (-56) No such drive
nsvErr (-35) No such volume
paramErr (-50) No default volume
</pre>
* \note <pre>Don't unmount the startup volume.
If you are using a string in the ioNamePtr field to specify a volume name,
the string must be in the following form
myVolParam.ioNamePtr = "\pMy HardDisk:"
The trailing colon on the string indicates that we are referring to a
directory, not a file.
All files on a volume must be closed in order for PBUnmountVol to
succeed.
A fBsyErr will be received if this is not the case.
PBUnmountVol is typically called just before PBEject - when the disk
will not be needed again for a while. Use PBMountVol if you need to
remount the volume.
PBOffLine is related; the volume buffer is ditched but its control block
remains in memory so that GetVInfo will continue to return information.
Later, the volume can be brought back online transparently, by the File
Manager, when needed.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBUnmountVol(__A0)
#endif
    OSErr PBUnmountVol(ParmBlkPtr paramBlock) ONEWORDINLINE(0xA00E);

#if CALL_NOT_IN_CARBON
/**
 *  PBUnmountVolImmed()
 *

 *    \non_carbon_cfm   in InterfaceLib 8.5 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBUnmountVolImmed(__A0)
#endif
    OSErr
    PBUnmountVolImmed(ParmBlkPtr paramBlock) ONEWORDINLINE(0xA20E);

/**
 *  PBEject()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBEject(__A0)
#endif
    OSErr PBEject(ParmBlkPtr paramBlock) ONEWORDINLINE(0xA017);

/**
 *  PBOffLine()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBOffLine(__A0)
#endif
    OSErr PBOffLine(ParmBlkPtr paramBlock) ONEWORDINLINE(0xA035);

#endif /* CALL_NOT_IN_CARBON */

/**
 *  PBCatSearchSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBCatSearchSync(__A0)
#endif
    OSErr
    PBCatSearchSync(CSParamPtr paramBlock) TWOWORDINLINE(0x7018, 0xA260);

/**
 *  PBCatSearchAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBCatSearchAsync(__A0)
#endif
    OSErr
    PBCatSearchAsync(CSParamPtr paramBlock) TWOWORDINLINE(0x7018, 0xA660);

#if CALL_NOT_IN_CARBON

    /**
    \brief Select a new default volume or working directory

    <pre>SetVol selects a volume or working directory to become the default.
volName is the address of a length-prefixed, pascal-style string containing
the name of the volume you wish to set as the default. Character case
is ignored.
If volName is NIL (0), the vRefNum  parameter will be used.
vRefNum is the reference number of the volume or working directory you
wish to select as the new default. This parameter is used only if
volName is invalid or NIL.
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
bdNamErr (-37) Invalid volName
nsvErr (-35) No such volume
paramErr (-50) No default volume
</pre>
* \note <pre>SetVol lets you select a default volume for use in subsequent file
operations where you do not specify a volume name or reference number.
There is seldom any need for this since the Standard File Package functions
return a volume reference indicating where a file is (or where the user
wants it to go).
You can specify the desired volume by either a single name or a volume
reference number; e.g.:
err = SetVol( 0, theRefNum ); /* set by reference number */
    err = SetVol("\pMy HardDisk:", 0); /* set by name */
    The volName string should NOT be a multiple - name pathname(such as
                                                                "\pHardDisk:Ltrs:Old") nor should it be an empty string(i.e., "\p");
    this parameter is checked first and anything but a valid name(except a NIL
                                                                      pointer) is rejected as an error.PBHSetVol lets you select both the default volume and default directory(see the second example, below)
        .You can pass a working directory number(i.e., the value of ioVRefNum after a call to PBOpenWD, or a volume reference returned by Standard
                                                                                                                File),
        but only if volName is NIL on entry(see the third example).Also, if you do use a working directory reference, a subsequent call to GetVol will return that number, rather than a "hard" volume ID.</ pre> * \copyright THINK Reference © 1991 - 1992 Symantec Corporation *    \non_carbon_cfm in InterfaceLib 7.1 and later *    \carbon_lib not available *    \mac_os_x not available * / OSErr SetVol(ConstStr63Param volName, /* can be NULL */
                                                                                                                                                                                                                                                                                                                                                                                                                  short vRefNum);

#endif /* CALL_NOT_IN_CARBON */

    /**
    \brief Flush volume, close its files, release its memory

    <pre>All files on a volume must be closed in order for UnmountVol to succeed.
A fBsyErr will be received if this is not the case.
UnmountVol is typically called just before calling Eject - when the disk
will not be needed again. Use PBMountVol to re-mount the volume, or
(most commonly) let Standard File take care of mounting and unmounting.
A related call is PBOffLine , which retains the volume control block in
memory so that GetVInfo will continue to return information and the
volume can be brought back online transparently, by the File Manager,
when needed.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
    OSErr
    UnmountVol(ConstStr63Param volName, /* can be NULL */
               short vRefNum);

#if CALL_NOT_IN_CARBON
    /**
     *  Eject()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    OSErr
    Eject(ConstStr63Param volName, /* can be NULL */
          short vRefNum);

#endif /* CALL_NOT_IN_CARBON */

    /**
     *  FlushVol()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    FlushVol(ConstStr63Param volName, /* can be NULL */
             short vRefNum);

    /**
    \brief Select a default default volume/directory (HFS only)

    <pre>Apple does not recommend using HSetVol or PBSetVol . See the notes below
for details.
HSetVol is used to select a default volume.  The File Manager will use these
defaults in future calls in which you specify no volume name and a volume
reference number of 0.
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
nsvErr (-35) No default volume
</pre>
* \note <pre>You can specify the new default by any of the following options:
•A full or partial pathname (ends in a colon). Put the address of the
pascal-style string in ioNamePtr.
•A volume number or a working directory number in ioVRefNum If you use
a WD ref, it will affect how PBGetVol works.
•A directory number in ioWDDirID (as obtained via PBOpenWD ).
See SetVol for an example showing usage of various ways to set a default
volume and open a file.
HSetVol lets you specify a WDRefNum for the ioVRefNum in addition to a
paritial pathname in ioNamePtr. HSetVol will start at the specified
working directory and use the paritial pathname to determine the final
directory. This directory might not correspond to an already existing
working directory, so the File Manager cannot refer to this directory with a
WDRefNum. Instead it must use the actual volume refNum and the dirID
number (which is assigned when the directory is created, and does not
change). This all means that if you call HSetVol , the File Manager stores
the actual volume refNum as the default volume, and the default dirID
separately. This will happen on all calls to HSetVol . Subsequent calls to
GetVol or PBGetVol or HGetVol will return only the volume refNum in
the ioVRefNum field of the parameter block. If any code tries to use the
refNum returned by GetVol or HGetVol , it will be accessing the root of the
volume, and not the current default directory as expected. This can be
disastrous for desk accessories because they don't know that your code has
called HSetVol or PBGetVol and they don't get what they expect if they call
GetVol.
Because of these problems, Apple does not recommend using HSetVol or
PBSetVol .
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
    OSErr
    HSetVol(ConstStr63Param volName, /* can be NULL */
            short vRefNum, long dirID);

    /* AddDrive() was moved to Devices.h*/

#if CALL_NOT_IN_CARBON

    /**
    \brief Open the data fork of an existing file

    <pre>FSOpen opens the data fork of an existing file for read/write or read-only
access (depending upon whether or not the file is locked).
fileName is the address of a length-prefixed, pascal-style string containing
the name of the file to be opened. It may be a partial or full
pathname, depending upon the value of vRefNum . If it is a
fully-qualified pathname, vRefNum is ignored.
vRefNum is the reference number of the volume or directory containing
fileName . It may be one of:
volume ref num A "hard" volume number; i.e., the refNum of the root directory on
the volume. In this case, fileName  must specify the rest of the
name, including all subdirectories leading from the root to the file.
directory ref num A directory reference number as returned by PBOpenWD and
SFPutFile (et.al.) . In this case, fileName  can be a simple
one-name file in that directory, or a multiple-name pathname
including directories leading from vRefNum  to the file.
0This specifies the current default volume/directory, as set via
SetVol or PBHSetVol . In this case, fileName  can be a full or
partial pathname as above.
fRefNum is the address of a 16-bit short. Upon return, it will contain the
file reference number (also called the access path number) of the
file. This value is used in all subsequent operations on the open file.
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
nsvErr (-35) No such volume
ioErr(-36) I/O error
bdNamErr (-37) Bad name
tmfoErr (-42) Too many files open
fnfErr(-43) File not found
opWrErr (-49) File already open for writing
extFSErr (-58) External file system
</pre>
* \note <pre>The file must exist (use Create to create a new file). If fileName  is not
found in the volume/directory specified, then the File Manager searches the
directory containing the currently-open System File (its volume number is
in the global variable BootDrive at 0x0210). If the file is not there, then
the File Manager searches the System Folder (actually, it searches the
directory whose "hard" ID is in the first long word in the ioVFndrInfo field
of the HVolumeParam structure returned by a call to PBHGetVInfo ).
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
    OSErr
    FSOpen(ConstStr255Param fileName, short vRefNum, short *refNum);

    /**
     *  OpenDF()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    OSErr
    OpenDF(ConstStr255Param fileName, short vRefNum, short *refNum);

#endif /* CALL_NOT_IN_CARBON */

    /**
    \brief Close a file

    <pre>FSClose removes the access path of an open file and updates the directory
entry for the file. The file must be re-opened before attempting any
subsequent file I/O calls.
fRefNum is the reference number of an open file. See FSOpen and OpenRF .
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
extFSErr (-58) External file system
fnfErr(-43) File not found
fnOpnErr (-38) File not open
ioErr(-36) I/O error
nsvErr (-35) No such volume
rfNumErr (-51) Bad fRefNum
</pre>
* \note <pre>DO NOT close a file that has already been closed.  As incredible as it
sounds, it is possible to wipe out a disk if you do so.  A safe suggestion is to
set your file reference number to 0 (an invalid value) after you close a
file; then if you close the file again, you'll get an error, rather than a
catastrophe.
FSClose (or even PBClose ) does not guarantee that the file (or even the
directory) on disk has been updated with any recent writes. You must use
FlushVol or PBFlushFile to ensure that data gets physically written to
disk. Otherwise, a power outage or the chance of a system error will cause
work to be lost.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
    OSErr
    FSClose(short refNum);

    /**
    \brief Read from an open file or device driver

    <pre>FSRead is used to read from files and from device drivers. The following
description pertains to reading from files, but the two uses are conceptually
similar. A description of how to use it with device drivers is also given below.
#include < Files.h> File Manager
OSErr FSRead(fRefNum , inOutCount , buffer );
short fRefNum ;reference number as obtained from FSOpen
long *inOutCount ;bytes to read; receives actual bytes read
Ptr buffer ; address of buffer to receive data
returns Error Code ; 0=no error
FSRead reads data from an open file into the caller's buffer. The read begins
at the current position of the file mark and advances that mark by the actual
number of bytes read.
fRefNum is the reference number of an open file. See FSOpen and OpenRF .
inOutCount is the address of a positive long integer. On entry, it specifies the
number of bytes you wish to read. Upon return, it will contain the
actual number of bytes read.
bufferis the address of a memory area, at least inOutCount  bytes long.
Upon return, the buffer will contain data read from the file.
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
eofErr (-39) End of file (partial read occurred)
extFSErr (-58) External file system
fnOpnErr (-38) File not open
ioErr(-36) I/O error
paramErr (-50) inOutCount  was negative
rfNumErr (-51) Bad file reference number
</pre>
* \note <pre>You can call FSRead repeatedly to read the file sequentially, or you can
use SetFPos before the read to access any part of the file randomly.
In the event that the end-of-file is reached during the read, the return
code will be eofErr and inOutCount  value will contain the actual number of
bytes read (probably less than the amount requested on entry).
Note: This is different from other operating systems that return an EOF
error only when attempting to start the read at the EOF.
Use the low-level PBRead function for asynchronous reading or to use the
'newline' mode (to read from the current file position up to a carriage
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
    OSErr
    FSRead(short refNum, long *count, void *buffPtr);

    /**
    \brief Write data from memory to a file

    <pre>FSWrite writes data from memory to an open file or an open device driver.
Descriptions of both uses of FSWrite are given below
When writing to a file, the data is written starting at the current file mark
and advances that mark by the actual number of bytes written.
fRefNum is the reference number of an open file. See FSOpen and OpenRF .
inOutCount is the address of a positive long integer. On entry, it specifies the
number of bytes you wish to write. Upon return, it will contain the
actual number of bytes written.
bufferis the address of a memory area containing the data to be written to
disk (it should be at least inOutCount  bytes long).
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
dskFulErr (-34) Disk full (incomplete or no write)
extFSErr (-58) External file system
fLckdErr (-45) File is locked
fnOpnErr (-38) File not open
ioErr(-36) I/O error
paramErr (-50) inOutCount  was negative
rfNumErr (-51) Bad file reference number
wPrErr (-44) Diskette is write-protected
wrPermErr (-61) Write permissions doesn't allow writing
</pre>
* \note <pre>You can call FSWrite repeatedly to write the file sequentially, or you can
use SetFPos before the write to store data to any part of the file. The file
mark is updated (in preparation for the next sequential write).
The data is transferred to the volume buffer and may not be written to disk
for some time (even after the file is closed). Use FlushVol or
PBFlushFile to force buffered data to be written to disk.
In the event the disk fills up during the read, the return code will be
dskFulErr and inOutCount  value will contain the actual number of bytes
written (probably less than the amount requested on entry).
Use the low-level PBWrite function for asynchronous writing and a
possible performance increase.
The following example illustrates how to open a file and append a 24-byte
data block to the end of the file. See OpenRF for an example that uses
FSRead and FSWrite to copy an entire file. See
Using FSWrite to Write to a File for a longer example.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
    OSErr
    FSWrite(short refNum, long *count, const void *buffPtr);

#if CALL_NOT_IN_CARBON

    /**
    \brief Get volume name, reference number and free bytes

    <pre>Given a physical drive number, GetVInfo returns information about the
volume mounted in that drive. Remember that since GetVInfo is only glue that
fills in a parameter block for you and then calls PBGetVInfo , the values
returned from it are subject to the limitations (imposed by MFS) of unsigned
shorts for the ioVNmAlBlks and ioVFrBlk fields of the parameter block. If the
actual numbers are larger than what fits in an unsigned short, they will be
clipped to 31744.
drvNum identifies the physical drive of interest. Historically, 1=internal,
2=external, 3 and up are hard disks. However, in the SE and MacII,
the drive numbers are assigned by the disk driver and may not fit
this mold ( drvNum =1 is always the first floppy drive).
volName is the address of a buffer. Upon return, the buffer will contain the
volume name, as a length-prefixed, pascal-style string. The buffer
should be at least 28 bytes long (to receive the 27-byte maximum
volume name).
vRefNum is the address of an unsigned short. Upon return it will contain the
volume's reference number.
freeBytes is the address of a long integer. Upon return it will contain the total
free space (in bytes) available on the volume. This will be a
multiple of the allocation block size for the volume.
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
nsvErr (-35) No such volume
paramErr (-50) Bad drvNum
</pre>
* \note <pre>See GetDrvQHdr for a way to determine the drive numbers of all drives
on the system.  Use indexing techniques with PBGetVInfo to learn about
all mounted volumes.
Example
#include < Files.h>
#include <pascal.h> /* for PtoCstr() */
    Str255 volName;
    short vRef, rc;
    long avail;
    </ pre>
                * \copyright THINK Reference © 1991 - 1992 Symantec Corporation
                                                          *    \non_carbon_cfm in InterfaceLib 7.1 and
        later
                *    \carbon_lib not available *    \mac_os_x not available *
            /
            OSErr
            GetVInfo(short drvNum, StringPtr volName, short *vRefNum, long *freeBytes);

    /**
    \brief Obtain file type, creator, icon position, etc.

    <pre>GetFInfo obtains a copy of the 16-byte packet of descriptive information
maintained for the Finder. This includes the file's type, the signature of its
creator, Finder flags (such as whether the icon is displayed or is actually on
the desktop), and the display position of the file's icon within its folder
(window).
fileName is the address of a length-prefixed, pascal-style string containing
the name of the file of interest. It may be a partial or full pathname,
depending upon the value of vRefNum .
vRefNum is the reference number of the volume or working directory that
contains the file or directory fileName . 0 indicates the default
volume.
fndrInfo is the address of a 16-byte FInfo structure. Upon return, it is
filled with file-specific information used by the Finder.
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
bdNamErr (-37) Bad name
extFSErr (-58) External file system
fnfErr(-43) File not found
ioErr(-36) I/O error
paramErr (-50) No default volume
</pre>
* \note <pre>The meaning of the bits in the fdFlags field of the FInfo structure has
changed since System 6.x. Be sure to check the FInfo structure to be sure
that the meaning of the bit that you are checking has not changed. For
instance, there is no longer a bit in the fdFlags field which indicates
whether or not a file is locked. To determine this information call
PBGetFInfo and examine the ioFlAttrib field.
GetFInfo is a functional subset of the low-level PBGetFInfo call (which
allows you to examine the file's date/time information as well as the
Finder-specific data).
The FInfo structure maintains the primary information used by the Finder
in locating the icon to display, where to display it and which application to
run when its icon is double-clicked. It is the same information as in the
ioFlFndrInfo field of the FileParam structure, which is passed to custom
"file filters" used in the Standard File Package (see SFGetFile ).
Additional Finder information is maintained in an FXInfo structure, which
can be obtained via PBGetCatInfo . Use SetFInfo , PBSetFInfo , or
PBSetCatInfo to modify the Finder information (and other information
about a file).
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
    OSErr
    GetFInfo(ConstStr255Param fileName, short vRefNum, FInfo *fndrInfo);

    /**
    \brief Obtain name and reference number of default volume

    <pre>GetVol returns the name and volume reference number of the current default
volume or working directory.
volName is either the address of a 28-byte buffer or NIL (0). Upon return,
one of the following will be true:
address: The buffer at volName will contain the name of the root
directory of the default volume (as a length-prefixed
pascal-style string) and vRefNum  will contain its volume
reference number.
NIL (0) The word at vRefNum  will contain the correct directory
number of the current working directory.
Note: This does NOT return multiple-name pathnames.
vRefNum is the address of an unsigned short. Upon return it will contain the
default volume's reference number (or if a previous call to SetVol
used a working directory reference, vRefNum  will receive that same
value).
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
nsvErr (-35) No such volume
</pre>
* \note <pre>Initially, the root of the startup disk is the default volume (or working
directory) for an application. After you set the default, you can use NIL for
a file name and 0 for a volume reference - this will imply the default
volume (or directory).
The lower-level PBGetVol returns the same information. Use
PBHGetVol to obtain a few snippets of additional data.
Use PBHSetVol to select both a default volume and directory. Use
PBOpenWD to open a working directory and use SetVol to select the root
of a volume (or a previously-opened working directory) as the default.
Example
#include < Files.h>
Str255 volName;
shortvRef;
shortrc;
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
    OSErr
    GetVol(StringPtr volName, short *vRefNum);

    /**
    \brief a new empty file (data fork only)

    <pre>Create creates a new file with an empty data fork and initializes the
information the Finder will need to start your application if the file is clicked
from the desktop. Note that the file is NOT opened. No resource fork for the
file is created.
fileName is the address of a length-prefixed, pascal-style string containing
the name of the file to be created. It may be a partial or full
pathname, depending upon the value of vRefNum . You should NOT use
names beginning with a period (".") since that convention is reserved
for devices. Imagine what happens when you create and write to a
file named ".Sony" (it's not a pretty sight when your hard disk goes
south).
vRefNum is the reference number of the volume or directory containing
fileName . See FSOpen for a description of the options.
creatoris a 32-bit value, often expressed as a four-letter literal (e.g.,
'MSWD'). It is normally the unique signature of your application
(as registered with Apple), or the signature of the application you
want to be launched when this file is double-clicked in the Finder.
Note: use creator = '????' if you don't want the file to auto-start
any application.
fileType is a 32-bit value, normally expressed as a four-letter literal (e.g.,
'TEXT'). It identifies the file type, which helps applications
determine how to process the file. This value is used in file filtering
(see SFGetFile , et.al).
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
bdNamErr (-37) Bad name
dirFulErr (-33) Directory full
dupFNErr (-48) Duplicate filename (rename)
extFSErr (-58) External file system
ioErr(-36) I/O error
nsvErr (-35) No such volume
vLckdErr (-46) Volume is locked
wPrErr (-44) Diskette is write-protected
</pre>
* \note <pre>Use SetFInfo for control over other descriptive information about the
file, such as the Finder's placement of the file's icon in its folder, whether
or not the file has a bundle of descriptive resources, and whether the file's
icon is invisible.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
    OSErr
    Create(ConstStr255Param fileName, short vRefNum, OSType creator,
           OSType fileType);

    /**
    \brief Delete an unopened file or empty directory

    <pre>FSDelete deletes both forks of a file. The file must not be open. This
function can also be used to delete an empty directory.
fileName is the address of a length-prefixed, pascal-style string containing
the name of the file to be deleted. It may be a partial or full
pathname, depending upon the value of vRefNum .
vRefNum is the reference number of the volume or working directory
containing the file or directory fileName . Use 0 to specify the default
volume.
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
bdNamErr (-37) Bad name
extFSErr (-58) External file system
fBsyErr (-47) File is busy
fLckdErr (-45) File is locked
fnfErr(-43) File not found
ioErr(-36) I/O error
nsvErr (-35) No such volume
vLckdErr (-46) Volume is locked
wPrErr (-44) Diskette is write-protected
</pre>
* \note <pre>If the file to delete is currently open (or if the directory to delete contains
any files or directories) FSDelete will fail, returning an Error Code .
Use PBDelete if you need to specify a file version number. If you want to
clear out an entire directory, use PBGetCatInfo to index through all
entries in the directory.
Note that this is a permanent deletion, and not a retrievable transfer to a
friendly "trash can ”. However, a good disk utility package can recover the
file data as long as no new data is written over it.
Example
#include < Files.h>
shortrc;
rc = FSDelete ( "\pHardDisk:Ltrs:Smith", 0 ); /* delete file */
    if (rc)
    { /* . . . handle the error . . . */
    }
    rc = FSDelete("\pHardDisk:Ltrs:", 0); /* delete directory */
    if (rc)
    { /* . . . handle the error . . . */
    }
    </ pre>
                * \copyright THINK Reference © 1991 - 1992 Symantec Corporation
                                                          *    \non_carbon_cfm in InterfaceLib 7.1 and
        later
                *    \carbon_lib not available *    \mac_os_x not available *
            /
            OSErr
            FSDelete(ConstStr255Param fileName, short vRefNum);

    /**
     *  OpenRF()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    OSErr
    OpenRF(ConstStr255Param fileName, short vRefNum, short *refNum);

    /**
    \brief Change the name of a file or directory

    <pre>Rename renames a file or directory. This simply changes the text of the
name; it cannot be used to move a file to a different directory (see
PBCatMove ).
oldName is the address of a length-prefixed, pascal-style string containing
the current name of the file or directory (directory names should
end with a colon ":").
vRefNum is the reference number of the volume or working directory that
contains the file or directory fileName . Use 0 to specify the default
volume.
newName is the address of a length-prefixed, pascal-style string containing
the desired new name for the file or directory (directory names
should end with a colon ":").
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
bdNamErr (-37) Bad name, newName is different type from oldName
dirFulErr (-33) Directory full
dirNFErr (-120) Directory not found
dupFNErr (-48) Duplicate filename ( newName already exists)
extFSErr (-58) External file system
fLckdErr (-45) File is locked
fnfErr(-43) File not found
fsRnErr (-59) Rename error
ioErr(-36) I/O error
nsvErr (-35) No such volume
paramErr (-50) No default volume
vLckdErr (-46) Volume is locked
wPrErr (-44) Diskette is write-protected
</pre>
* \note <pre>The vRefNum  parameter describes the volume or directory in which the
item to rename currently resides. You may use a "hard" volume number,
or a working directory reference as returned by Standard File.
Both filenames must resolve to entries in the same directory; i.e., if
oldName is a fully-qualified three-name pathspec, then newName must
also provide that same information, with only the final element in the name
changing. For instance:
Rename ( "\pHardDisk:Ltrs: Smith", 0, "\pHardDisk:Ltrs: Jones" );
When you rename a directory or volume, both names should end in a colon,
e.g.:
Rename ( "\pHardDisk:", 0, "\pEasyDisk:" );
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
    OSErr
    Rename(ConstStr255Param oldName, short vRefNum, ConstStr255Param newName);

    /**
    \brief Change file type, creator, icon position, etc.

    <pre>SetFInfo changes Finder-specific information about a file. This includes the
file's type, the signature of its creator, Finder flags (such as whether the icon
is displayed), and the display position of the file's icon within its window.
fileName is the address of a length-prefixed, pascal-style string containing
the name of the target file. It may be a partial or full pathname,
depending upon the value of vRefNum .
vRefNum is the reference number of the volume or working directory
containing the file or directory fileName . 0 indicates the default
volume.
fndrInfo is the address of a 16-byte FInfo structure containing the desired
values of Finder specific information to be changed. Normal usage is
to pre-set all fields with current values by first calling GetFInfo ,
then change only those fields which you wish to modify.
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
extFSErr (-58) External file system
fLckdErr (-45) File is locked
fnfErr(-43) File not found
ioErr(-36) I/O error
nsvErr (-35) No such volume
vLckdErr (-46) Volume is locked
wPrErr (-44) Diskette is write-protected
</pre>
* \note <pre>SetFInfo is a functional subset of the low-level PBSetFInfo call (which
allows you to change the file's date/time information as well as its
Finder-specific data).
The FInfo structure maintains the primary information used by the Finder
in locating the icon to display, where to display it, and which application to
run when its icon is double-clicked. It is the same information as in the
ioFlFndrInfo field of the FileParam structure, which is passed to custom
"file filters" used in the Standard File Package (see SFGetFile ).
Additional Finder information is maintained in an FXInfo structure, which
can be obtained via PBGetCatInfo . In all operations in which you modify
file-descriptive information, the normal usage is to obtain a copy of the
current information before modifying selected fields and updating the disk,
as in the following example.
Example
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
    OSErr
    SetFInfo(ConstStr255Param fileName, short vRefNum, const FInfo *fndrInfo);

    /**
    \brief Lock a file (prevent changes, deletion, renaming, etc.)

    <pre>SetFLock locks a file. This prevents programs from modifying it in any way
- deleting, renaming, or writing data to either its data or resource fork.
fileName is the address of a length-prefixed, pascal-style string containing
the name of the file to be locked. It may be a partial or full
pathname, depending upon the value of vRefNum .
vRefNum is the reference number of the volume or working directory that
contains the file or directory fileName . Use 0 to specify the default
volume.
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
extFSErr (-58) External file system
fnfErr(-43) File not found
ioErr(-36) I/O error
nsvErr (-35) No such volume
vLckdErr (-46) Volume is locked
wPrErr (-44) Diskette is write-protected
</pre>
* \note <pre>This sets the file's "lock" flag (as found in the ioFlAttrib field of the
FileParam structure) and notifies the system of the change (Note: if you
change this bit directly, as with PBSetCatInfo , the change may not be
noticed by the Finder until the file's folder is closed and reopened or the
system is restarted).
This prevents programs from deleting ( FSDelete ), renaming ( Rename ),
or writing ( FSWrite ) to the file. Any attempt to open the file ( FSOpen)
for read/write access will fail. Of course, any process can unlock the file
(via RstFLock ) if it wants such access.
This has no affect on currently-open access paths. Thus, you can open a
file for writing, then lock it to prevent other concurrent processes from
writing to it. Afterward, use RstFLock to unlock the file.
You can lock/unlock an entire volume via PBSetVInfo or lock a selected
portion of an open file via PBLockRange . Use PBGetFInfo to see if a file
is currently locked (ioFlAttrib bit 1 is set).
Be sure to call FlushVol to make sure that the change is written to the
disk in a timely manner.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
    OSErr
    SetFLock(ConstStr255Param fileName, short vRefNum);

    /**
    \brief Unlock a file (allow changes, deletion, renaming, etc.)

    <pre>RstFLock locks a file; it undoes the effect of SetFLock . This allows
programs to delete, rename, or write data to it.
fileName is the address of a length-prefixed, pascal-style string containing
the name of the file to be unlocked. It may be a partial or full
pathname, depending upon the value of vRefNum .
vRefNum is the reference number of the volume or working directory that
contains the file or directory fileName . Use 0 to specify the default
volume.
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
extFSErr (-58) External file system
fnfErr(-43) File not found
ioErr(-36) I/O error
nsvErr (-35) No such volume
vLckdErr (-46) Volume is locked
wPrErr (-44) Diskette is write-protected
</pre>
* \note <pre>This clears the file's "lock" flag (as found in the ioFlAttrib field of the
FileParam structure) and notifies the system of the change (Note: changing
this bit directly, e.g., via PBSetCatInfo , may not be noticed by the Finder
until the file's folder is closed and reopened or the system is restarted).
This does not affect currently-open access paths. Thus, if some other
process has opened the file, locking it will not prevent the other program
from continuing to modify it.
See SetFLock for related details. You can lock/unlock an entire volume
via PBSetVInfo or lock a selected portion of an open file via
PBLockRange . Use PBGetFInfo to see if a file is currently locked
(ioFlAttrib bit 1 is set).
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
    OSErr
    RstFLock(ConstStr255Param fileName, short vRefNum);

#endif /* CALL_NOT_IN_CARBON */

    /**
    \brief Increase the physical size of an open file

    <pre>Allocate extends the physical size of a file on disk, without changing the
file's logical EOF.
fRefNum is the reference number of an open file. See FSOpen and OpenRF .
byteCount is the address of a positive long integer. On entry, it specifies how
much space, in bytes, you wish to add to the file's physical allocation.
Upon return, it contains the actual number of bytes added (it will be a
multiple of the disk block size).
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
dskFulErr (-34) Disk full
fLckdErr (-45) File is locked
fnOpnErr (-38) File not open
ioErr(-36) I/O error
rfNumErr (-51) Bad fRefNum
vLckdErr (-46) Volume is locked
wPrErr (-44) Diskette is write-protected
wrPermErr (-61) Write permission error
</pre>
* \note <pre>The byteCount  parameter is added to the current physical end-of-file, the
sum is rounded up to the size of the next higher allocation block, and the
File Manager attempts to allocate enough blocks to satisfy the request.
If there is not enough free space on the disk, then all available space is
allocated , the byteCount  variable is set to the actual number of bytes
allocated, and dskFulErr is returned. Hint: you may wish to shrink the file
back down if the allocation fails (see SetEOF).
Note that Allocate works in disk-block size units, with no regard to the
logical EOF. For instance:
longbyteCount;
shortfRef;
byteCount = 1;
Allocate ( fRef, &byteCount ); /* add 1 byte to the file */
This attempts to extend the file by 1 byte, but it will always eat up one full
allocation unit (e.g., 512 or 1K) of disk space. Before using Allocate , you
may wish to learn the current physical file length by examining the
ioFlPyLen field of the FileParam structure returned by PBGetFInfo .
The PBAllocContig attempts to expand a file by adding contiguous disk
blocks to the file (for fastest I/O) SetEOF can also be used to increase file
size.
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
			 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
OSErr
Allocate(short refNum, long *count);

/**
\brief Obtain the size of an open file (logical EOF)

<pre>Use GetEOF to find the current size of a file (its logical end-of-file
position).
fRefNum is the reference number of an open file. See FSOpen and OpenRF .
curEOFis the address of long integer. Upon return, it will contain the file
position of the logical end-of-file; i.e., the size of the file, in bytes.
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
extFSErr (-58) External file system
fnOpnErr (-38) File not open
ioErr(-36) I/O error
rfNumErr (-51) Bad fRefNum
</pre>
* \note <pre>Use GetEOF to learn the size of file. This and all high-level file
operations refer to the logical end-of-file, as opposed to the physical EOF.
Note: The physical EOF is always greater than or equal to the logical
EOF, is a multiple of the size of an allocation unit (usually 1K), and has no
significance for most applications.
The following example opens a file, allocates a memory buffer to hold all of
its data, and reads the data into the buffer. See OpenRF for an example
program that copies the contents of both forks of one file to another and uses
this function to learn the size of the file.
Example
#include < Files.h>
#include < Memory.h >
short fRef, rc;
long fileSize;
Handle hData; /* handle to buffer to be allocated */
rc = FSOpen("\pHardDisk:MyFile", 0, &fRef);
if (rc)
{ /* . . . handle the error . . . */
}
rc = GetEOF(fRef, &fileSize); /* get file size */
if (rc)
{ /* . . . handle the error . . . */
}
hData = NewHandle(fileSize); /* allocate enough RAM */
if (hData == 0)
{ /* . . . handle the error . . . */
}
rc = FSRead(fRef, &fileSize, *hData); /* read it in */
</ pre>
            * \copyright THINK Reference © 1991 - 1992 Symantec Corporation
                                                      *    \non_carbon_cfm in InterfaceLib 7.1 and
    later
        *    \carbon_lib in CarbonLib 1.0 and
    later
        *    \mac_os_x in version 10.0 and
    later
            * /
        OSErr
        GetEOF(short refNum, long *logEOF);

/**
\brief Increase or decrease the logical size of a file

<pre>Use SetEOF to change the size of a file to any arbitrary length. Disk blocks
are allocated or released to accommodate the request.
fRefNum is the reference number of an open file. See FSOpen and OpenRF .
newEOF is the desired new size of the file, in bytes.
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
dskFulErr (-34) Disk full (partial allocation made)
extFSErr (-58) External file system
fLckdErr (-45) File is locked
fnOpnErr (-38) File not open
ioErr(-36) I/O error
rfNumErr (-51) Bad fRefNum
vLckdErr (-46) Volume is locked
wPrErr (-44) Diskette is write-protected
wrPermErr (-61) Write permissions error
</pre>
* \note <pre>If newEOF is larger than the current file size (see GetEOF), the file size
is increased by allocating additional disk blocks to the physical EOF (if
needed). If there is not enough available disk space to satisfy the entire
request the dskFulErr is returned and no new space is allocated.
You can also use Allocate to increase the size of a file. The
PBAllocContig function may be preferable since it attempts to allocate
contiguous blocks (for best read/write performance).
If newEOF is smaller than the current size and if the new size is small
enough to fit in fewer allocation blocks, disk blocks will be released as the
file is truncated. For instance,
SetEOF( fRef, 0 );
sets the logical end-of-file to 0 and releases all the disk blocks allocated to
the file (thus, freeing up space on the disk).
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
OSErr SetEOF(short refNum, long logEOF);

/**
\brief Obtain position of the file mark of an open file

<pre>GetFPos returns the current position of the file mark (the file address at
which the next read or write will begin).
fRefNum is the reference number of an open file. See FSOpen and OpenRF .
filePosis the address of a 32-bit long integer. Upon return, it will contain
the current value of the file's mark; i.e., an offset in bytes from the
start of the file.
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
eofErr (-39) End of file
extFSErr (-58) External file system
fnOpnErr (-38) File not open
ioErr(-36) I/O error
rfNumErr (-51) fRefNum  is invalid
</pre>
* \note <pre>You can use GetFPos before attempting a read, and compare the return
value of filePos to the location of file's logical end-of-file (see GetEOF).
See OpenRF for an example usage of this function.
The SetFPos function performs the complementary function of setting the
file mark, in preparation for reading from or writing to the file at that
position.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
OSErr GetFPos(short refNum, long *filePos);

/**
\brief Position file mark for random-access read/write

<pre>SetFPos sets the position of the file mark (the file position at which the next
read or write operation will start).
fRefNum is the reference number of an open file. See FSOpen and OpenRF .
posMode specifies the method by which the file pointer will be moved. The
following constants are defined in Files.h:
fsAtMark 0Remain at current mark ( posOffset  is ignored)
fsFromStart 1Move to absolute file position in posOffset
fsFromLEOF 2Move posOffset  bytes from logical end of file
fsFromMark 3Move posOffset  bytes from current position
posOffset is a signed long integer (positive or negative); it identifies how far
to move the file mark. The resulting absolute file position will
depend upon the method specified by posMode.
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
eofErr (-39) Attempt tp position past the end-of-file
extFSErr (-58) External file system
fnOpnErr (-38) File not open
ioErr(-36) I/O error
posErr (-40) Can't position to before start of file
rfNumErr (-51) Bad fRefNum
</pre>
* \note <pre>SetFPos (LSEEK to UNIX fans) is used in random-access disk operations
to position the file mark to a specified position in order to read from or
write to a selected position in the file. This function is not needed in
sequential file I/O, since the file mark is updated automatically via FSRead
and FSWrite .
The posOffset  parameter may be positive or negative. If the combination
of posMode and a positive posOffset  would move past the end of the file, the
mark is set to the EOF and eofErr is returned. If you attempt to position the
file mark before the start of the file (i.e., while using a negative value in
posOffset ) posErr is returned.
If you wish to append records to the end of the file, simply use
posMode=fsFromLEOF and posOffset =0 (see FSWrite for an example). If
you need to seek beyond the end of the file, you can use Allocate or SetEOF
to add empty space to the end of the file before using SetFPos .
Some examples:
FSOpen( "\pHardDisk:MyFile", 0, &fRef );
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
OSErr SetFPos(short refNum, short posMode, long posOff);

/**
\brief Get volume reference number of an open file

<pre>Given the reference number of an open file, GetVRefNum returns the
reference number of the volume on which the file resides.
fRefNum identifies the file whose volume reference you wish to query. This
is normally a value obtained via FSOpen, or SFGetFile , et al.
vRefNum is the address of an unsigned short. Upon return it will contain the
volume reference number of the volume containing the file identified
in fRefNum .
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
rfNumErr (-51) Bad refNum
</pre>
* \note <pre>You can use the low-level PBGetFCBInfo function to obtain additional
information about any open file.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
OSErr GetVRefNum(short fileRefNum, short *vRefNum);

#if CALL_NOT_IN_CARBON
/**
 *  fsopen()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSErr fsopen(const char *fileName, short vRefNum, short *refNum);

/**
 *  getvinfo()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSErr getvinfo(short drvNum, char *volName, short *vRefNum, long *freeBytes);

/**
 *  getfinfo()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSErr getfinfo(const char *fileName, short vRefNum, FInfo *fndrInfo);

/**
 *  getvol()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSErr getvol(char *volName, short *vRefNum);

/**
 *  setvol()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSErr setvol(const char *volName, short vRefNum);

/**
 *  unmountvol()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSErr unmountvol(const char *volName, short vRefNum);

/**
 *  eject()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSErr eject(const char *volName, short vRefNum);

/**
 *  flushvol()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSErr flushvol(const char *volName, short vRefNum);

/**
 *  create()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSErr create(const char *fileName, short vRefNum, OSType creator, OSType fileType);

/**
 *  fsdelete()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSErr fsdelete(const char *fileName, short vRefNum);

/**
 *  openrf()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSErr openrf(const char *fileName, short vRefNum, short *refNum);

/**
 *  fsrename()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSErr fsrename(const char *oldName, short vRefNum, const char *newName);

/**
 *  setfinfo()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSErr setfinfo(const char *fileName, short vRefNum, const FInfo *fndrInfo);

/**
 *  setflock()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSErr setflock(const char *fileName, short vRefNum);

/**
 *  rstflock()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSErr rstflock(const char *fileName, short vRefNum);

#endif /* CALL_NOT_IN_CARBON */

#if CALL_NOT_IN_CARBON
/**
 *  PBOpenWDSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBOpenWDSync(__A0)
#endif
    OSErr
    PBOpenWDSync(WDPBPtr paramBlock) TWOWORDINLINE(0x7001, 0xA260);

/**
 *  PBOpenWDAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBOpenWDAsync(__A0)
#endif
    OSErr
    PBOpenWDAsync(WDPBPtr paramBlock) TWOWORDINLINE(0x7001, 0xA660);

/**
 *  PBCloseWDSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBCloseWDSync(__A0)
#endif
    OSErr
    PBCloseWDSync(WDPBPtr paramBlock) TWOWORDINLINE(0x7002, 0xA260);

/**
 *  PBCloseWDAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBCloseWDAsync(__A0)
#endif
    OSErr
    PBCloseWDAsync(WDPBPtr paramBlock) TWOWORDINLINE(0x7002, 0xA660);

#endif /* CALL_NOT_IN_CARBON */

/**
 *  PBHSetVolSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBHSetVolSync(__A0)
#endif
    OSErr PBHSetVolSync(WDPBPtr paramBlock) ONEWORDINLINE(0xA215);

/**
 *  PBHSetVolAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBHSetVolAsync(__A0)
#endif
    OSErr PBHSetVolAsync(WDPBPtr paramBlock) ONEWORDINLINE(0xA615);

/**
 *  PBHGetVolSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBHGetVolSync(__A0)
#endif
    OSErr PBHGetVolSync(WDPBPtr paramBlock) ONEWORDINLINE(0xA214);

/**
 *  PBHGetVolAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBHGetVolAsync(__A0)
#endif
    OSErr PBHGetVolAsync(WDPBPtr paramBlock) ONEWORDINLINE(0xA614);

/**
 *  PBCatMoveSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBCatMoveSync(__A0)
#endif
    OSErr
    PBCatMoveSync(CMovePBPtr paramBlock) TWOWORDINLINE(0x7005, 0xA260);

/**
 *  PBCatMoveAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBCatMoveAsync(__A0)
#endif
    OSErr
    PBCatMoveAsync(CMovePBPtr paramBlock) TWOWORDINLINE(0x7005, 0xA660);

/**
 *  PBDirCreateSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBDirCreateSync(__A0)
#endif
    OSErr
    PBDirCreateSync(HParmBlkPtr paramBlock) TWOWORDINLINE(0x7006, 0xA260);

/**
 *  PBDirCreateAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBDirCreateAsync(__A0)
#endif
    OSErr
    PBDirCreateAsync(HParmBlkPtr paramBlock) TWOWORDINLINE(0x7006, 0xA660);

#if CALL_NOT_IN_CARBON
/**
 *  PBGetWDInfoSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBGetWDInfoSync(__A0)
#endif
    OSErr
    PBGetWDInfoSync(WDPBPtr paramBlock) TWOWORDINLINE(0x7007, 0xA260);

/**
 *  PBGetWDInfoAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBGetWDInfoAsync(__A0)
#endif
    OSErr
    PBGetWDInfoAsync(WDPBPtr paramBlock) TWOWORDINLINE(0x7007, 0xA660);

#endif /* CALL_NOT_IN_CARBON */

/**
 *  PBGetFCBInfoSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBGetFCBInfoSync(__A0)
#endif
    OSErr
    PBGetFCBInfoSync(FCBPBPtr paramBlock) TWOWORDINLINE(0x7008, 0xA260);

/**
 *  PBGetFCBInfoAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBGetFCBInfoAsync(__A0)
#endif
    OSErr
    PBGetFCBInfoAsync(FCBPBPtr paramBlock) TWOWORDINLINE(0x7008, 0xA660);

/**
 *  PBGetCatInfoSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBGetCatInfoSync(__A0)
#endif
    OSErr
    PBGetCatInfoSync(CInfoPBPtr paramBlock) TWOWORDINLINE(0x7009, 0xA260);

/**
 *  PBGetCatInfoAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBGetCatInfoAsync(__A0)
#endif
    OSErr
    PBGetCatInfoAsync(CInfoPBPtr paramBlock) TWOWORDINLINE(0x7009, 0xA660);

/**
 *  PBSetCatInfoSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBSetCatInfoSync(__A0)
#endif
    OSErr
    PBSetCatInfoSync(CInfoPBPtr paramBlock) TWOWORDINLINE(0x700A, 0xA260);

/**
 *  PBSetCatInfoAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBSetCatInfoAsync(__A0)
#endif
    OSErr
    PBSetCatInfoAsync(CInfoPBPtr paramBlock) TWOWORDINLINE(0x700A, 0xA660);

/**
 *  PBAllocContigSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBAllocContigSync(__A0)
#endif
    OSErr
    PBAllocContigSync(ParmBlkPtr paramBlock) ONEWORDINLINE(0xA210);

/**
 *  PBAllocContigAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBAllocContigAsync(__A0)
#endif
    OSErr
    PBAllocContigAsync(ParmBlkPtr paramBlock) ONEWORDINLINE(0xA610);

/**
 *  PBLockRangeSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBLockRangeSync(__A0)
#endif
    OSErr
    PBLockRangeSync(ParmBlkPtr paramBlock) TWOWORDINLINE(0x7010, 0xA260);

/**
 *  PBLockRangeAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBLockRangeAsync(__A0)
#endif
    OSErr
    PBLockRangeAsync(ParmBlkPtr paramBlock) TWOWORDINLINE(0x7010, 0xA660);

/**
 *  PBUnlockRangeSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBUnlockRangeSync(__A0)
#endif
    OSErr
    PBUnlockRangeSync(ParmBlkPtr paramBlock) TWOWORDINLINE(0x7011, 0xA260);

/**
 *  PBUnlockRangeAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBUnlockRangeAsync(__A0)
#endif
    OSErr
    PBUnlockRangeAsync(ParmBlkPtr paramBlock) TWOWORDINLINE(0x7011, 0xA660);

/**
 *  PBSetVInfoSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBSetVInfoSync(__A0)
#endif
    OSErr
    PBSetVInfoSync(HParmBlkPtr paramBlock) TWOWORDINLINE(0x700B, 0xA260);

/**
 *  PBSetVInfoAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBSetVInfoAsync(__A0)
#endif
    OSErr
    PBSetVInfoAsync(HParmBlkPtr paramBlock) TWOWORDINLINE(0x700B, 0xA660);

/**
 *  PBHGetVInfoSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBHGetVInfoSync(__A0)
#endif
    OSErr PBHGetVInfoSync(HParmBlkPtr paramBlock) ONEWORDINLINE(0xA207);

/**
 *  PBHGetVInfoAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBHGetVInfoAsync(__A0)
#endif
    OSErr
    PBHGetVInfoAsync(HParmBlkPtr paramBlock) ONEWORDINLINE(0xA607);

/**
 *  PBHOpenSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBHOpenSync(__A0)
#endif
    OSErr PBHOpenSync(HParmBlkPtr paramBlock) ONEWORDINLINE(0xA200);

/**
 *  PBHOpenAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBHOpenAsync(__A0)
#endif
    OSErr PBHOpenAsync(HParmBlkPtr paramBlock) ONEWORDINLINE(0xA600);

/**
 *  PBHOpenRFSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBHOpenRFSync(__A0)
#endif
    OSErr PBHOpenRFSync(HParmBlkPtr paramBlock) ONEWORDINLINE(0xA20A);

/**
 *  PBHOpenRFAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBHOpenRFAsync(__A0)
#endif
    OSErr PBHOpenRFAsync(HParmBlkPtr paramBlock) ONEWORDINLINE(0xA60A);

/**
 *  PBHOpenDFSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBHOpenDFSync(__A0)
#endif
    OSErr
    PBHOpenDFSync(HParmBlkPtr paramBlock) TWOWORDINLINE(0x701A, 0xA260);

/**
 *  PBHOpenDFAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBHOpenDFAsync(__A0)
#endif
    OSErr
    PBHOpenDFAsync(HParmBlkPtr paramBlock) TWOWORDINLINE(0x701A, 0xA660);

/**
 *  PBHCreateSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBHCreateSync(__A0)
#endif
    OSErr PBHCreateSync(HParmBlkPtr paramBlock) ONEWORDINLINE(0xA208);

/**
 *  PBHCreateAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBHCreateAsync(__A0)
#endif
    OSErr PBHCreateAsync(HParmBlkPtr paramBlock) ONEWORDINLINE(0xA608);

/**
 *  PBHDeleteSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBHDeleteSync(__A0)
#endif
    OSErr PBHDeleteSync(HParmBlkPtr paramBlock) ONEWORDINLINE(0xA209);

/**
 *  PBHDeleteAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBHDeleteAsync(__A0)
#endif
    OSErr PBHDeleteAsync(HParmBlkPtr paramBlock) ONEWORDINLINE(0xA609);

/**
 *  PBHRenameSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBHRenameSync(__A0)
#endif
    OSErr PBHRenameSync(HParmBlkPtr paramBlock) ONEWORDINLINE(0xA20B);

/**
 *  PBHRenameAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBHRenameAsync(__A0)
#endif
    OSErr PBHRenameAsync(HParmBlkPtr paramBlock) ONEWORDINLINE(0xA60B);

/**
 *  PBHRstFLockSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBHRstFLockSync(__A0)
#endif
    OSErr PBHRstFLockSync(HParmBlkPtr paramBlock) ONEWORDINLINE(0xA242);

/**
 *  PBHRstFLockAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBHRstFLockAsync(__A0)
#endif
    OSErr
    PBHRstFLockAsync(HParmBlkPtr paramBlock) ONEWORDINLINE(0xA642);

/**
 *  PBHSetFLockSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBHSetFLockSync(__A0)
#endif
    OSErr PBHSetFLockSync(HParmBlkPtr paramBlock) ONEWORDINLINE(0xA241);

/**
 *  PBHSetFLockAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBHSetFLockAsync(__A0)
#endif
    OSErr
    PBHSetFLockAsync(HParmBlkPtr paramBlock) ONEWORDINLINE(0xA641);

/**
 *  PBHGetFInfoSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBHGetFInfoSync(__A0)
#endif
    OSErr PBHGetFInfoSync(HParmBlkPtr paramBlock) ONEWORDINLINE(0xA20C);

/**
 *  PBHGetFInfoAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBHGetFInfoAsync(__A0)
#endif
    OSErr
    PBHGetFInfoAsync(HParmBlkPtr paramBlock) ONEWORDINLINE(0xA60C);

/**
 *  PBHSetFInfoSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBHSetFInfoSync(__A0)
#endif
    OSErr PBHSetFInfoSync(HParmBlkPtr paramBlock) ONEWORDINLINE(0xA20D);

/**
 *  PBHSetFInfoAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBHSetFInfoAsync(__A0)
#endif
    OSErr
    PBHSetFInfoAsync(HParmBlkPtr paramBlock) ONEWORDINLINE(0xA60D);

/**
 *  PBMakeFSSpecSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBMakeFSSpecSync(__A0)
#endif
    OSErr
    PBMakeFSSpecSync(HParmBlkPtr paramBlock) TWOWORDINLINE(0x701B, 0xA260);

/**
 *  PBMakeFSSpecAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBMakeFSSpecAsync(__A0)
#endif
    OSErr
    PBMakeFSSpecAsync(HParmBlkPtr paramBlock) TWOWORDINLINE(0x701B, 0xA660);

#if CALL_NOT_IN_CARBON

    /**
    \brief Clear enqueued File Manager calls

    <pre>FInitQueue purges the File Manager queue of all I/O requests, except for the
current one (if any).
</pre>
* \returns <pre>none
</pre>
* \note <pre>FInitQueue is useful when several asynchronous calls are queued and an
error occurs on one of the early calls. Use it to ditch the subsequent calls to
avoid having to handle the errors that are sure to occur.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
    void FInitQueue(void) ONEWORDINLINE(0xA016);

#endif /* CALL_NOT_IN_CARBON */

#if CALL_NOT_IN_CARBON

    /**
    \brief Obtain pointer to the file I/O queue header

    <pre>GetFSQHdr returns the address of the standard Operating System queue used
to maintain the linked-list of I/O requests.
</pre>
* \returns <pre>a 32-bit QHdrPtr; the address of the 10-byte QHdr structure whose
qLink field points to the parameter block of the first pending file I/O
request.
</pre>
* \note <pre>C programmers may prefer to get the address from the global variable
FSQHdr (at 0x0360).
Given this queue header pointer, an application could use the OS Utility
functions Enqueue and Dequeue to manipulate the queue elements (I/O
requests), or it could walk through the queue element chain to count how
many requests are pending.
The I/O queue is a series of parameter blocks, linked by the qLink field of
each block.
When using Asynchronous I/O , you may discover that an early request
generated an error, invalidating other subsequent requests. In that case,
you could use FInitQueue to purge the queue, or you could fiddle with the
I/O queue elements directly. Be aware that the File Manager does its own
manipulation at interrupt time.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
    QHdrPtr
    GetFSQHdr(void) THREEWORDINLINE(0x2EBC, 0x0000, 0x0360);

    /**
    \brief Obtain pointer to the volume control block queue header

    <pre>GetVCBQHdr returns the standard Operating System queue's header address,
which is used to maintain the linked-list of volume control blocks. There is
one VCB entry for every online volume, whether it is currently mounted or
not.
</pre>
* \returns <pre>a 32-bit QHdrPtr; the address of the 10-byte QHdr structure whose
qLink field points to the first volume control block in the queue.
</pre>
* \note <pre>C programmers may prefer to get this address from the global variable
VCBQHdr (at 0x0356). The global variable DefVCBPtr points directly to
the VCB of the current default volume.
It is probably a mistake to manipulate this queue directly, but if you need
to, you can use the OS Utilities functions Enqueue and Dequeue , passing
VCBQHdr as the queue you wish to modify.
Nearly everything you'll ever want to know about volumes can be obtained
via PBGetVInfo (which lets you easily index through the list).
If you are running under HFS, the queue elements are 178-byte VCB
structures. If you booted with a flat file system, the queue is made up of
structures which include only the first 94-bytes of the VCB structure. The
qLink field of either structure points to the next such structure in the chain
or is 0 to indicate the end of the chain. The following example illustrates
how to access the VCB queue.
Example
#include < Files.h>
#include < OSUtils.h >
QHdrPtr qhp;
VCB *vcbp;
qhp= GetVCBQHdr (); /* address of queue header */
    printf("First vcb is at = %lx\n", qhp->qHead);
    vcbp = (VCB *)qhp->qHead; /* address of a queue element */
    printf("Volume's drive # is: %d\n", vcbp->vcbDrvNum);
    printf("number of files in root = %d\n", vcbp->vcbNmFls);
    printf("Next vcb is at = %lx\n", vcbp->qLink); /* 0 means no more */
    </ pre>
                * \copyright THINK Reference © 1991 - 1992 Symantec Corporation
                                                          *    \non_carbon_cfm in InterfaceLib 7.1 and
        later
                *    \carbon_lib not available *    \mac_os_x not available *
            /
            QHdrPtr
            GetVCBQHdr(void) THREEWORDINLINE(0x2EBC, 0x0000, 0x0356);

    /* GetDrvQHdr was moved to Devices.h*/

#endif /* CALL_NOT_IN_CARBON */

    /**
    \brief Obtain default volume/directory name and reference

    <pre>Use HGetVol to get the vRefNum and dirID of the current default volume or
directory. It is similar to PBGetVol , except it uses refNums and dirID's
instead of a ParmBlkPtr .
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
nsvErr (-35) No such volume
paramErr (-50) No default volume
</pre>
* \note <pre>The ioNamePtr field can be NIL to ignore the name. Otherwise, it should
point to a 28-byte buffer to hold the maximum 27-character name of the
default volume. Note that this does NOT return a multiple-name directory
name, even when a previous SetVol set the default to a working directory.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
    OSErr
    HGetVol(StringPtr volName, short *vRefNum, long *dirID);

    /**
     *  HOpen()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    HOpen(short vRefNum, long dirID, ConstStr255Param fileName, SInt8 permission,
          short *refNum);

    /**
     *  HOpenDF()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    HOpenDF(short vRefNum, long dirID, ConstStr255Param fileName, SInt8 permission,
            short *refNum);

    /**
     *  HOpenRF()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    HOpenRF(short vRefNum, long dirID, ConstStr255Param fileName, SInt8 permission,
            short *refNum);

    /**
    \brief Allocate contiguous space on disk

    <pre>AllocContig works the same way as the Allocate routine except that it
allocates contiguous space on the disk for the specified file. If the required
space cannot be allocated, a dskFullErr (-35) is returned.
refNum is the reference number of an open file. See FSOpen and OpenRF .
countis the address of a positive long integer. On entry, it specifies how
much space, in bytes, you wish to add to the file's physical allocation.
Upon return, it contains the actual number of bytes added (it will be a
multiple of the disk block size).
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
dskFulErr (-34) Disk full
fLckdErr (-45) File is locked
fnOpnErr (-38) File not open
ioErr(-36) I/O error
rfNumErr (-51) Bad fRefNum
vLckdErr (-46) Volume is locked
wPrErr (-44) Diskette is write-protected
wrPermErr (-61) Write permission error
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
    OSErr
    AllocContig(short refNum, long *count);

    /**
    \brief Create a new file like PB and set type and creator

    <pre>HCreate creates a new file like PBHCreate , and then sets the file type and
creator of the file.
vRefNum is the reference number of the volume or working directory to
contain fileName . See FSOpen for a description of the options.
dirIDis the directory ID of the directory to contain fileName .
fileName is the address of a length-prefixed, pascal-style string containing
the name of the file to be created. It may be a partial or full
pathname, depending upon the value of vRefNum . You should NOT use
names beginning with a period ('.') since that convention is reserved
for devices.
creatoris a 32-bit value, often expressed as a four-letter literal (e.g.,
'MSWD'). It is normally the unique signature of your application
(as registered with Apple), or the signature of the application which
want to be launched when this file is double-clicked in the Finder.
Note: use creator = '????' if you don't want the file to auto-start
any application.
fileType is a 32-bit value, normally expressed as a four-letter literal (e.g.,
'TEXT'). It identifies the file type, which helps applications
determine how to process the file. This value is used in file filtering
(see SFGetFile , et.al).
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
bdNamErr (-37) Bad name
dirFulErr (-33) Directory full
dupFNErr (-48) Duplicate filename (rename)
extFSErr (-58) External file system
ioErr(-36) I/O error
nsvErr (-35) No such volume
vLckdErr (-46) Volume is locked
wPrErr (-44) Diskette is write-protected
</pre>
* \note <pre>Use SetFInfo for control over other descriptive information about the
file, such as the Finder's placement of the file's icon in its folder, whether
or not the file has a bundle of descriptive resources, and whether the file's
icon is invisible.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
    OSErr
    HCreate(short vRefNum, long dirID, ConstStr255Param fileName, OSType creator,
            OSType fileType);

    /**
    \brief Create a directory

    <pre>DirCreate creates a directory. It returns the new directory ID in the
createdDirID parameter.
vRefNum is the reference number of the volume or directory
containing fileName . See FSOpen for a description of the options.
parentID  is the reference number of the directory that will hold the
newly created directory.
dirName is the address of a length-prefixed, pascal-style string
containing the name of the directory to be created. You should NOT
use names beginning with a period ('.') since that convention is
reserved for devices.
createdDirID  is the ID of the newly created directory.
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
bdNamErr (-37) Bad name
dirFulErr (-33) Directory full
dupFNErr (-48) Duplicate filename (rename)
extFSErr (-58) External file system
ioErr(-36) I/O error
nsvErr (-35) No such volume
vLckdErr (-46) Volume is locked
wPrErr (-44) Diskette is write-protected
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
    OSErr
    DirCreate(short vRefNum, long parentDirID, ConstStr255Param directoryName,
              long *createdDirID);

    /**
    \brief Delete an unopened file or empty directory

    <pre>HDelete deletes both forks of a file. The file must not be open. This function
can also be used to delete an empty directory.
vRefNum is the reference number of the volume or working directory
containing the file or directory fileName . Use 0 to specify the default
volume.
dirIDis the ID of the directory that contains the file to be deleted.
fileName is the address of a length-prefixed, pascal-style string containing
the name of the file to be deleted. It may be a partial or full
pathname, depending upon the value of vRefNum .
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
bdNamErr (-37) Bad name
extFSErr (-58) External file system
fBsyErr (-47) File is busy
fLckdErr (-45) File is locked
fnfErr(-43) File not found
ioErr(-36) I/O error
nsvErr (-35) No such volume
vLckdErr (-46) Volume is locked
wPrErr (-44) Diskette is write-protected
</pre>
* \note <pre>If the file to delete is currently open (or if the directory to delete contains
any files or directories) HDelete will fail, returning an Error Code .
Use PBDelete if you need to specify a file version number. If you want to
clear out an entire directory, use PBGetCatInfo to index through all
entries in the directory.
Note that this is a permanent deletion, and not a retrievable transfer to a
friendly "trash can ”. However, a good disk utility package can recover the
file data as long as no new data is written over it.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
    OSErr
    HDelete(short vRefNum, long dirID, ConstStr255Param fileName);

    /**
    \brief Obtain file type, creator, icon position, etc.

    <pre>HGetFInfo obtains a copy of the 16-byte packet of descriptive information
maintained for the Finder. This includes the file's type, the signature of its
creator, Finder flags (such as whether the icon is displayed or is actually on
the desktop), and the display position of the file's icon within its folder
(window).
vRefNum is the reference number of the volume or working directory that
contains the file or directory fileName . 0 indicates the default
volume.
dirIDis the directory ID that contains the file to get info about
fileName is the address of a length-prefixed, pascal-style string containing
the name of the file of interest. It may be a partial or full pathname,
depending upon the value of vRefNum .
fndrInfo is the address of a 16-byte FInfo structure. Upon return, it is
filled with file-specific information used by the Finder.
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
bdNamErr (-37) Bad name
extFSErr (-58) External file system
fnfErr(-43) File not found
ioErr(-36) I/O error
paramErr (-50) No default volume
</pre>
* \note <pre>The FInfo structure maintains the primary information used by the Finder
in locating the icon to display, where to display it and which application to
run when its icon is double-clicked. It is the same information as in the
ioFlFndrInfo field of the FileParam structure, which is passed to custom
"file filters" used in the Standard File Package (see SFGetFile ).
Additional Finder information is maintained in an FXInfo structure, which
can be obtained via PBGetCatInfo . Use SetFInfo , PBSetFInfo , or
PBSetCatInfo to modify the Finder information (and other information
about a file).
If your application rewrites files by deleting the original and creating a
new one, you should maintain the position on the file's icon within its folder.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
    OSErr
    HGetFInfo(short vRefNum, long dirID, ConstStr255Param fileName,
              FInfo *fndrInfo);

    /**
    \brief Change file type, creator, icon position, etc.

    <pre>HSetFInfo changes Finder-specific information about a file. This includes
the file's type, the signature of its creator, Finder flags (such as whether the
icon is displayed), and the display position of the file's icon within its window.
vRefNum is the reference number of the volume or working directory
containing the file or directory fileName . 0 indicates the default
volume.
dirIDis the ID of the directory that contains the file to set info about
fileName is the address of a length-prefixed, pascal-style string containing
the name of the target file. It may be a partial or full pathname,
depending upon the value of vRefNum .
fndrInfo is the address of a 16-byte FInfo structure containing the desired
values of Finder specific information to be changed. Normal usage is
to pre-set all fields with current values by first calling GetFInfo ,
then change only those fields you wish to modify.
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
extFSErr (-58) External file system
fLckdErr (-45) File is locked
fnfErr(-43) File not found
ioErr(-36) I/O error
nsvErr (-35) No such volume
vLckdErr (-46) Volume is locked
wPrErr (-44) Diskette is write-protected
</pre>
* \note <pre>The FInfo structure maintains the primary information used by the Finder
in locating the icon to display, where to display it, and which application to
run when its icon is double-clicked. It is the same information as in the
ioFlFndrInfo field of the FileParam structure, which is passed to the
custom "file filters" used in the Standard File Package (see SFGetFile ).
Additional Finder information is maintained in an FXInfo structure, which
can be obtained via PBGetCatInfo . In all operations where you modify
file-descriptive information, the normal usage is to obtain a copy of the
current information before modifying selected fields and updating the disk.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
    OSErr
    HSetFInfo(short vRefNum, long dirID, ConstStr255Param fileName,
              const FInfo *fndrInfo);

    /**
    \brief Lock a file (prevent changes, deletion, renaming, etc.)

    <pre>HSetFLock locks a file. This prevents programs from modifying it in any
way - deleting, renaming, or writing to either its data or resource fork. It is
similar to SetFLock except that it takes a vRefNum/dirID combination instead
of just a vRefNum.
vRefNum is the reference number of the volume or working directory that
contains the file or directory fileName . Use 0 to specify the default
volume.
dirIDis the ID of the directory where the file resides.
fileName is the address of a length-prefixed, pascal-style string containing
the name of the file to be locked. It may be a partial or full
pathname, depending upon the value of vRefNum .
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
extFSErr (-58) External file system
fnfErr(-43) File not found
ioErr(-36) I/O error
nsvErr (-35) No such volume
vLckdErr (-46) Volume is locked
wPrErr (-44) Diskette is write-protected
</pre>
* \note <pre>This sets the file's "lock" flag (as found in the ioFlAttrib field of the
FileParam structure) and notifies the system of the change (Note: if you
change this bit directly, as with PBSetCatInfo , the change may not be
noticed by the Finder until the file's folder is closed and reopened or the
system is restarted).
This prevents programs from deleting ( FSDelete ), renaming ( Rename ),
or writing ( FSWrite ) to the file. Any attempt to open the file ( FSOpen)
for read/write access will fail. Of course, any process can unlock the file
(via RstFLock ) if it wants such access.
This has no affect on currently-open access paths. Thus, you can open a
file for writing, then lock it to prevent other concurrent processes from
writing to it. Afterward, use RstFLock to unlock the file.
You can lock/unlock an entire volume via PBSetVInfo or lock a selected
portion of an open file via PBLockRange . Use PBGetFInfo to see if a file
is currently locked (ioFlAttrib bit 1 is set).
Be sure to call FlushVol to make sure that the change is written to the
disk in a timely manner.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
    OSErr
    HSetFLock(short vRefNum, long dirID, ConstStr255Param fileName);

    /**
    \brief Unlock a file (allow changes, deletion, renaming, etc.)

    <pre>HRstFLock unlocks a file; it undoes the effect of SetFLock . This allows
programs to delete, rename, or write data to it.
vRefNum is the reference number of the volume or working directory that
contains the file or directory fileName . Use 0 to specify the default
volume.
dirIDis the directory ID of the directory where the file resides.
fileName is the address of a length-prefixed, pascal-style string containing
the name of the file to be unlocked. It may be a partial or full
pathname, depending upon the value of vRefNum .
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
extFSErr (-58) External file system
fnfErr(-43) File not found
ioErr(-36) I/O error
nsvErr (-35) No such volume
vLckdErr (-46) Volume is locked
wPrErr (-44) Diskette is write-protected
</pre>
* \note <pre>This clears the file's "lock" flag (as found in the ioFlAttrib field of the
FileParam structure) and notifies the system of the change (Note: changing
this bit directly, e.g., via PBSetCatInfo , may not be noticed by the Finder
until the file's folder is closed and reopened or the system is restarted).
This does not affect currently-open access paths. Thus, if some other
process has opened the file, locking it will not prevent the other program
from continuing to modify it.
See SetFLock for related details. You can lock/unlock an entire volume
via PBSetVInfo or lock a selected portion of an open file via
PBLockRange . Use PBGetFInfo to see if a file is currently locked
(ioFlAttrib bit 1 is set).
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
    OSErr
    HRstFLock(short vRefNum, long dirID, ConstStr255Param fileName);

    /**
    \brief Rename a file, volume, or directory

    <pre>HRename changes the name of a file or volume. It does NOT move a file from
one directory to another (use PBCatMove for that). It is similar to yet easier
to use than PBReName since it uses a vRefNum and dirID instead of a
ParmBlkRec structure.
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
bdNamErr (-37) Bad name
dirFulErr (-33) Directory full
dupFNErr (-48) Duplicate filename (new name already exists)
extFSErr (-58) External file system
fLckdErr (-45) File is locked
fnfErr(-43) File not found
fsRnErr (-59) File system rename error
ioErr(-36) I/O error
nsvErr (-35) No such volume
paramErr (-50) No default volume
vLckdErr (-46) Volume is locked
wPrErr (-44) Diskette is write-protected
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
    OSErr
    HRename(short vRefNum, long dirID, ConstStr255Param oldName,
            ConstStr255Param newName);

    /**
    \brief Transfer file or directory to another directory on the same volume

    <pre>CatMove moves the directory entry of a file or directory into a different
directory on the same volume. File contents are not transferred; this is
strictly a directory-modification operation. It is similar to the PBCatMove
routine, but it takes a vRefNum, dirID's and filenames instead of a complicated
CMovePBRec structure.
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
badMovErr (-122) Can't move into offspring
bdNamErr (-37) Bad file name or attempt to move into file
dupFNErr (-48) Duplicate filename (destination file/dir already exists)
fnfErr(-43) Source file not found
ioErr(-36) I/O error
nsvErr (-35) No such volume
paramErr (-50) No default volume
vLckdErr (-46) Volume is locked
wPrErr (-44) Diskette is write-protected
</pre>
* \note <pre>The file or directory specified by ioNamePtr, ioVRefNum, and ioDirID (in
various combinations), is transferred to the directory identified by
ioNewName and/or ioNewDirID.
CatMove cannot transfer between different disks (volumes) nor can it
rename an item - use PBHRename for that.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
    OSErr
    CatMove(short vRefNum, long dirID, ConstStr255Param oldName, long newDirID,
            ConstStr255Param newName);

#if CALL_NOT_IN_CARBON
    /**
     *  OpenWD()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    OSErr
    OpenWD(short vRefNum, long dirID, long procID, short *wdRefNum);

    /**
    \brief Close and release a working directory

    <pre>CloseWD closes a working directory.
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
nsvErr (-35) No such volume
</pre>
* \note <pre>You should only call CloseWD or PBCloseWD on working directories you
have created. Do not call CloseWD or PBCloseWD on working directories
created by Standard File or SysEnvirons .
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
    OSErr
    CloseWD(short wdRefNum);

    /**
    \brief Query information about an existing working directory

    <pre>GetWDInfo obtains the "hard" directory ID and the real volume number
associated with a working directory.
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
nsvErr (-35) No such volume
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
    OSErr
    GetWDInfo(short wdRefNum, short *vRefNum, long *dirID, long *procID);

/*  shared environment  */
#endif /* CALL_NOT_IN_CARBON */

/**
 *  PBHGetVolParmsSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBHGetVolParmsSync(__A0)
#endif
    OSErr
    PBHGetVolParmsSync(HParmBlkPtr paramBlock) TWOWORDINLINE(0x7030, 0xA260);

/**
 *  PBHGetVolParmsAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBHGetVolParmsAsync(__A0)
#endif
    OSErr
    PBHGetVolParmsAsync(HParmBlkPtr paramBlock) TWOWORDINLINE(0x7030, 0xA660);

/**
 *  PBHGetLogInInfoSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBHGetLogInInfoSync(__A0)
#endif
    OSErr
    PBHGetLogInInfoSync(HParmBlkPtr paramBlock) TWOWORDINLINE(0x7031, 0xA260);

/**
 *  PBHGetLogInInfoAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBHGetLogInInfoAsync(__A0)
#endif
    OSErr
    PBHGetLogInInfoAsync(HParmBlkPtr paramBlock) TWOWORDINLINE(0x7031, 0xA660);

/**
 *  PBHGetDirAccessSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBHGetDirAccessSync(__A0)
#endif
    OSErr
    PBHGetDirAccessSync(HParmBlkPtr paramBlock) TWOWORDINLINE(0x7032, 0xA260);

/**
 *  PBHGetDirAccessAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBHGetDirAccessAsync(__A0)
#endif
    OSErr
    PBHGetDirAccessAsync(HParmBlkPtr paramBlock) TWOWORDINLINE(0x7032, 0xA660);

/**
 *  PBHSetDirAccessSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBHSetDirAccessSync(__A0)
#endif
    OSErr
    PBHSetDirAccessSync(HParmBlkPtr paramBlock) TWOWORDINLINE(0x7033, 0xA260);

/**
 *  PBHSetDirAccessAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBHSetDirAccessAsync(__A0)
#endif
    OSErr
    PBHSetDirAccessAsync(HParmBlkPtr paramBlock) TWOWORDINLINE(0x7033, 0xA660);

/**
 *  PBHMapIDSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBHMapIDSync(__A0)
#endif
    OSErr
    PBHMapIDSync(HParmBlkPtr paramBlock) TWOWORDINLINE(0x7034, 0xA260);

/**
 *  PBHMapIDAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBHMapIDAsync(__A0)
#endif
    OSErr
    PBHMapIDAsync(HParmBlkPtr paramBlock) TWOWORDINLINE(0x7034, 0xA660);

/**
 *  PBHMapNameSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBHMapNameSync(__A0)
#endif
    OSErr
    PBHMapNameSync(HParmBlkPtr paramBlock) TWOWORDINLINE(0x7035, 0xA260);

/**
 *  PBHMapNameAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBHMapNameAsync(__A0)
#endif
    OSErr
    PBHMapNameAsync(HParmBlkPtr paramBlock) TWOWORDINLINE(0x7035, 0xA660);

/**
 *  PBHCopyFileSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBHCopyFileSync(__A0)
#endif
    OSErr
    PBHCopyFileSync(HParmBlkPtr paramBlock) TWOWORDINLINE(0x7036, 0xA260);

/**
 *  PBHCopyFileAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBHCopyFileAsync(__A0)
#endif
    OSErr
    PBHCopyFileAsync(HParmBlkPtr paramBlock) TWOWORDINLINE(0x7036, 0xA660);

/**
 *  PBHMoveRenameSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBHMoveRenameSync(__A0)
#endif
    OSErr
    PBHMoveRenameSync(HParmBlkPtr paramBlock) TWOWORDINLINE(0x7037, 0xA260);

/**
 *  PBHMoveRenameAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBHMoveRenameAsync(__A0)
#endif
    OSErr
    PBHMoveRenameAsync(HParmBlkPtr paramBlock) TWOWORDINLINE(0x7037, 0xA660);

/**
 *  PBHOpenDenySync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBHOpenDenySync(__A0)
#endif
    OSErr
    PBHOpenDenySync(HParmBlkPtr paramBlock) TWOWORDINLINE(0x7038, 0xA260);

/**
 *  PBHOpenDenyAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBHOpenDenyAsync(__A0)
#endif
    OSErr
    PBHOpenDenyAsync(HParmBlkPtr paramBlock) TWOWORDINLINE(0x7038, 0xA660);

/**
 *  PBHOpenRFDenySync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBHOpenRFDenySync(__A0)
#endif
    OSErr
    PBHOpenRFDenySync(HParmBlkPtr paramBlock) TWOWORDINLINE(0x7039, 0xA260);

/**
 *  PBHOpenRFDenyAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBHOpenRFDenyAsync(__A0)
#endif
    OSErr
    PBHOpenRFDenyAsync(HParmBlkPtr paramBlock) TWOWORDINLINE(0x7039, 0xA660);

/**
 *  PBGetXCatInfoSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 8.5 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBGetXCatInfoSync(__A0)
#endif
    OSErr
    PBGetXCatInfoSync(XCInfoPBPtr paramBlock) TWOWORDINLINE(0x703A, 0xA260);

/**
 *  PBGetXCatInfoAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 8.5 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBGetXCatInfoAsync(__A0)
#endif
    OSErr
    PBGetXCatInfoAsync(XCInfoPBPtr paramBlock) TWOWORDINLINE(0x703A, 0xA660);

/**
 *  PBExchangeFilesSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBExchangeFilesSync(__A0)
#endif
    OSErr
    PBExchangeFilesSync(HParmBlkPtr paramBlock) TWOWORDINLINE(0x7017, 0xA260);

/**
 *  PBExchangeFilesAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBExchangeFilesAsync(__A0)
#endif
    OSErr
    PBExchangeFilesAsync(HParmBlkPtr paramBlock) TWOWORDINLINE(0x7017, 0xA660);

/**
 *  PBCreateFileIDRefSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBCreateFileIDRefSync(__A0)
#endif
    OSErr
    PBCreateFileIDRefSync(HParmBlkPtr paramBlock) TWOWORDINLINE(0x7014, 0xA260);

/**
 *  PBCreateFileIDRefAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBCreateFileIDRefAsync(__A0)
#endif
    OSErr
    PBCreateFileIDRefAsync(HParmBlkPtr paramBlock) TWOWORDINLINE(0x7014, 0xA660);

/**
 *  PBResolveFileIDRefSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBResolveFileIDRefSync(__A0)
#endif
    OSErr
    PBResolveFileIDRefSync(HParmBlkPtr paramBlock) TWOWORDINLINE(0x7016, 0xA260);

/**
 *  PBResolveFileIDRefAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBResolveFileIDRefAsync(__A0)
#endif
    OSErr
    PBResolveFileIDRefAsync(HParmBlkPtr paramBlock) TWOWORDINLINE(0x7016, 0xA660);

/**
 *  PBDeleteFileIDRefSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBDeleteFileIDRefSync(__A0)
#endif
    OSErr
    PBDeleteFileIDRefSync(HParmBlkPtr paramBlock) TWOWORDINLINE(0x7015, 0xA260);

/**
 *  PBDeleteFileIDRefAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBDeleteFileIDRefAsync(__A0)
#endif
    OSErr
    PBDeleteFileIDRefAsync(HParmBlkPtr paramBlock) TWOWORDINLINE(0x7015, 0xA660);

/**
 *  PBGetForeignPrivsSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBGetForeignPrivsSync(__A0)
#endif
    OSErr
    PBGetForeignPrivsSync(HParmBlkPtr paramBlock) TWOWORDINLINE(0x7060, 0xA260);

/**
 *  PBGetForeignPrivsAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBGetForeignPrivsAsync(__A0)
#endif
    OSErr
    PBGetForeignPrivsAsync(HParmBlkPtr paramBlock) TWOWORDINLINE(0x7060, 0xA660);

/**
 *  PBSetForeignPrivsSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBSetForeignPrivsSync(__A0)
#endif
    OSErr
    PBSetForeignPrivsSync(HParmBlkPtr paramBlock) TWOWORDINLINE(0x7061, 0xA260);

/**
 *  PBSetForeignPrivsAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBSetForeignPrivsAsync(__A0)
#endif
    OSErr
    PBSetForeignPrivsAsync(HParmBlkPtr paramBlock) TWOWORDINLINE(0x7061, 0xA660);

/*  Desktop Manager  */
/**
 *  PBDTGetPath()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBDTGetPath(__A0)
#endif
    OSErr PBDTGetPath(DTPBPtr paramBlock) TWOWORDINLINE(0x7020, 0xA260);

/**
 *  PBDTCloseDown()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBDTCloseDown(__A0)
#endif
    OSErr
    PBDTCloseDown(DTPBPtr paramBlock) TWOWORDINLINE(0x7021, 0xA260);

/**
 *  PBDTAddIconSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBDTAddIconSync(__A0)
#endif
    OSErr
    PBDTAddIconSync(DTPBPtr paramBlock) TWOWORDINLINE(0x7022, 0xA260);

/**
 *  PBDTAddIconAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBDTAddIconAsync(__A0)
#endif
    OSErr
    PBDTAddIconAsync(DTPBPtr paramBlock) TWOWORDINLINE(0x7022, 0xA660);

/**
 *  PBDTGetIconSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBDTGetIconSync(__A0)
#endif
    OSErr
    PBDTGetIconSync(DTPBPtr paramBlock) TWOWORDINLINE(0x7023, 0xA260);

/**
 *  PBDTGetIconAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBDTGetIconAsync(__A0)
#endif
    OSErr
    PBDTGetIconAsync(DTPBPtr paramBlock) TWOWORDINLINE(0x7023, 0xA660);

/**
 *  PBDTGetIconInfoSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBDTGetIconInfoSync(__A0)
#endif
    OSErr
    PBDTGetIconInfoSync(DTPBPtr paramBlock) TWOWORDINLINE(0x7024, 0xA260);

/**
 *  PBDTGetIconInfoAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBDTGetIconInfoAsync(__A0)
#endif
    OSErr
    PBDTGetIconInfoAsync(DTPBPtr paramBlock) TWOWORDINLINE(0x7024, 0xA660);

/**
 *  PBDTAddAPPLSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBDTAddAPPLSync(__A0)
#endif
    OSErr
    PBDTAddAPPLSync(DTPBPtr paramBlock) TWOWORDINLINE(0x7025, 0xA260);

/**
 *  PBDTAddAPPLAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBDTAddAPPLAsync(__A0)
#endif
    OSErr
    PBDTAddAPPLAsync(DTPBPtr paramBlock) TWOWORDINLINE(0x7025, 0xA660);

/**
 *  PBDTRemoveAPPLSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBDTRemoveAPPLSync(__A0)
#endif
    OSErr
    PBDTRemoveAPPLSync(DTPBPtr paramBlock) TWOWORDINLINE(0x7026, 0xA260);

/**
 *  PBDTRemoveAPPLAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBDTRemoveAPPLAsync(__A0)
#endif
    OSErr
    PBDTRemoveAPPLAsync(DTPBPtr paramBlock) TWOWORDINLINE(0x7026, 0xA660);

/**
 *  PBDTGetAPPLSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBDTGetAPPLSync(__A0)
#endif
    OSErr
    PBDTGetAPPLSync(DTPBPtr paramBlock) TWOWORDINLINE(0x7027, 0xA260);

/**
 *  PBDTGetAPPLAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBDTGetAPPLAsync(__A0)
#endif
    OSErr
    PBDTGetAPPLAsync(DTPBPtr paramBlock) TWOWORDINLINE(0x7027, 0xA660);

/**
 *  PBDTSetCommentSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBDTSetCommentSync(__A0)
#endif
    OSErr
    PBDTSetCommentSync(DTPBPtr paramBlock) TWOWORDINLINE(0x7028, 0xA260);

/**
 *  PBDTSetCommentAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBDTSetCommentAsync(__A0)
#endif
    OSErr
    PBDTSetCommentAsync(DTPBPtr paramBlock) TWOWORDINLINE(0x7028, 0xA660);

/**
 *  PBDTRemoveCommentSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBDTRemoveCommentSync(__A0)
#endif
    OSErr
    PBDTRemoveCommentSync(DTPBPtr paramBlock) TWOWORDINLINE(0x7029, 0xA260);

/**
 *  PBDTRemoveCommentAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBDTRemoveCommentAsync(__A0)
#endif
    OSErr
    PBDTRemoveCommentAsync(DTPBPtr paramBlock) TWOWORDINLINE(0x7029, 0xA660);

/**
 *  PBDTGetCommentSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBDTGetCommentSync(__A0)
#endif
    OSErr
    PBDTGetCommentSync(DTPBPtr paramBlock) TWOWORDINLINE(0x702A, 0xA260);

/**
 *  PBDTGetCommentAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBDTGetCommentAsync(__A0)
#endif
    OSErr
    PBDTGetCommentAsync(DTPBPtr paramBlock) TWOWORDINLINE(0x702A, 0xA660);

/**
 *  PBDTFlushSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBDTFlushSync(__A0)
#endif
    OSErr
    PBDTFlushSync(DTPBPtr paramBlock) TWOWORDINLINE(0x702B, 0xA260);

/**
 *  PBDTFlushAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBDTFlushAsync(__A0)
#endif
    OSErr
    PBDTFlushAsync(DTPBPtr paramBlock) TWOWORDINLINE(0x702B, 0xA660);

/**
 *  PBDTResetSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBDTResetSync(__A0)
#endif
    OSErr
    PBDTResetSync(DTPBPtr paramBlock) TWOWORDINLINE(0x702C, 0xA260);

/**
 *  PBDTResetAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBDTResetAsync(__A0)
#endif
    OSErr
    PBDTResetAsync(DTPBPtr paramBlock) TWOWORDINLINE(0x702C, 0xA660);

/**
 *  PBDTGetInfoSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBDTGetInfoSync(__A0)
#endif
    OSErr
    PBDTGetInfoSync(DTPBPtr paramBlock) TWOWORDINLINE(0x702D, 0xA260);

/**
 *  PBDTGetInfoAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBDTGetInfoAsync(__A0)
#endif
    OSErr
    PBDTGetInfoAsync(DTPBPtr paramBlock) TWOWORDINLINE(0x702D, 0xA660);

/**
 *  PBDTOpenInform()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBDTOpenInform(__A0)
#endif
    OSErr
    PBDTOpenInform(DTPBPtr paramBlock) TWOWORDINLINE(0x702E, 0xA060);

/**
 *  PBDTDeleteSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBDTDeleteSync(__A0)
#endif
    OSErr
    PBDTDeleteSync(DTPBPtr paramBlock) TWOWORDINLINE(0x702F, 0xA060);

/**
 *  PBDTDeleteAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBDTDeleteAsync(__A0)
#endif
    OSErr
    PBDTDeleteAsync(DTPBPtr paramBlock) TWOWORDINLINE(0x702F, 0xA460);

    /*  VolumeMount traps  */

    /**
    \brief PBGetVolMountInfoSize Determine space  allocation for volume-mounting record

    <pre>Use PBGetVolMountInfoSize to determine how much space to allocate for
the volume-mounting record.
pbis a pointer to a IOParam structure.The relevant fields are as
follows:
Out-In Name Type SizeOffsetDescription
→ioCompletion ProcPtr 412Completion routine address (if async =TRUE)
←ioResult short 216Error Code (0=no error, 1=not done yet)
→ioVRefNum short 222Volume or working directory reference
→ioBuffer Ptr 432pointer to storage for size (4 bytes of storage)
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
nsvErr (-35) Volume not found
paramErr (-50) Parameter error
extFSErr (-58) External file system error; typically, function is
not available for that volume
</pre>
* \note <pre>For a specified volume, the PBGetVolMountInfoSize function provides
the size of the record needed to hold the volume's mounting information.
After ascertaining the size of the record needed and allocating storage, you
call the PBGetVolMountInfo function to retrieve a record containing all
the information needed to mount the volume, except for passwords. You can
later pass this record to the PBVolumeMount function to mount the
volume.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBGetVolMountInfoSize(__A0)
#endif
    OSErr
    PBGetVolMountInfoSize(ParmBlkPtr paramBlock) TWOWORDINLINE(0x703F, 0xA260);

    /**
    \brief PBGetVolMountInfo Places volume mounting information  into a buffer

    <pre>Use PBGetVolMountInfo to place the mounting information for a specified
volume into the buffer
pbis a pointer to a IOParam structure.The relevant fields are as
follows:
Out-In Name Type SizeOffsetDescription
→ioCompletion ProcPtr 412Completion routine address (if async =TRUE)
←ioResult short 216Error Code (0=no error, 1=not done yet)
→ioVRefNum short 222Volume or working directory reference
→ioBuffer Ptr 432Pointer to mounting information
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
nsvErr (-35) Volume not found
paramErr (-50) Parameter error
extFSErr (-58) External file system error; typically, function is
not available for that volume
</pre>
* \note <pre>PBGetVolMountInfo places the mounting information for a specified
volume into the buffer pointed to by the ioBuffer field. The mounting
information for an AppleShare volume is stored as an AFP mounting record.
The length of the buffer is specified by the value pointed to by the ioBuffer
field in a previous call to PBGetVolMountInfoSize .
PBGetVolMountInfo does not return the user password or volume
password in the AFPVolMountInfo record. Your application solicits these
passwords from the user and fills in the record before attempting to mount
the remote volume.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBGetVolMountInfo(__A0)
#endif
    OSErr
    PBGetVolMountInfo(ParmBlkPtr paramBlock) TWOWORDINLINE(0x7040, 0xA260);

/**
 *  PBVolumeMount()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBVolumeMount(__A0)
#endif
    OSErr
    PBVolumeMount(ParmBlkPtr paramBlock) TWOWORDINLINE(0x7041, 0xA260);

    /*  FSp traps  */

    /**
    \brief Convert a file or directory spec into an FSSpec record

    <pre>You use the FSMakeFSSpec function to convert a conventional file or
directory specification into an FSSpec record.
vRefNum is the volume reference number, a working directory reference
number, a drive number, or 0 for the default volume.
dirIDis usually the parent directory ID of the target object. If the
directory is sufficiently specified by either vRefNum or fileName ,
dirID can be 0. If you explicitly specify dirID (that is, if it is any
value other than 0), and if vRefNum is a working directory reference
number, dirID overrides the directory ID included in vRefNum . If the
fileName parameter is an empty string, FSMakeFSSpec creates an
FSSpec record for a directory specified by either the dirID or
vRefNum parameter.
fileName is a full or partial pathname. If it is a full pathname,
FSMakeFSSpec ignores vRefNum and dirID. A partial pathname
might identify only the final target, or it might include one or more
parent directory names. If fileName is a partial pathname,
vRefNum , dirID , or both must be valid.
specis a pointer to an FSSpec record, which FSMakeFSSpec fills in
Returns: an operating system Error Code . It will be one of:
noErr(0) No error
fnfErr(-43) File or directory does not exist ( FSSpec
is still valid)
</pre>
* \note <pre>FSMakeFSSpec places the specification in the spec parameter. Call
FSMakeFSSpec whenever you want to create an FSSpec record.
You can pass the input to FSMakeFSSpec in any of the four ways
described in File Specification Strategies under the section entitled
Identifying Files, Directories, and Volumes . See the table in
Using FSSpec Records under Using the File Manager for details of
how FSMakeFSSpec interprets input.
If the specified volume is mounted and the specified parent directory
exists, but the target file or directory doesn't exist in that location,
FSMakeFSSpec fills in the record and then returns fnfErr instead of
noErr. The record is valid, but it describes a target that doesn't exist. You
can use the record for other operations, such as creating a file with the
FSpCreate function.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
    OSErr
    FSMakeFSSpec(short vRefNum, long dirID, ConstStr255Param fileName, FSSpec *spec)
        TWOWORDINLINE(0x7001, 0xAA52);

    /**
     *  FSpOpenDF()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    FSpOpenDF(const FSSpec *spec, SInt8 permission, short *refNum)
        TWOWORDINLINE(0x7002, 0xAA52);

    /**
     *  FSpOpenRF()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    FSpOpenRF(const FSSpec *spec, SInt8 permission, short *refNum)
        TWOWORDINLINE(0x7003, 0xAA52);

    /**
    \brief Create a new file and set  the type and creator

    <pre>FSpCreate creates a new file and sets the type and creator. It is the
high-level, FSSpec version of the PBHCreate function.
spec is a ponter to an FSSpec record specifying the file to be created
creatoris used to set the new file creator
fileType is used to set the new file type
scriptTag specifies the code of the script system in which the document name
is to be displayed. If StandardPutFile was used to get the file, the
sfScript field of the StandardFileReply structure should be passed in
this parameter.
Returns: an operating system Error Code . It will be one of:
noErr(0) No error
bdNamErr (-37) Bad name
dirFulErr (-33) Directory full
dirNFErr (-120) Directory not found
dupFNErr (-48) Duplicate filename already exists
extFSErr (-58) External file system
ioErr(-36) I/O error
nsvErr (-35) No such volume
vLckdErr (-46) Volume is locked
wPrErr (-44) Diskette is write-protected
</pre>
* \note <pre> If you have established the name and location of the new file through either
the StandardPutFile or CustomPutFile procedure, specify the script
code returned in the reply record. Otherwise, specify the system script by
setting the scriptTag parameter to smSystemScript. For more information
on script systems, see the Worldwide Software Overview
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
    OSErr
    FSpCreate(const FSSpec *spec, OSType creator, OSType fileType,
              ScriptCode scriptTag) TWOWORDINLINE(0x7004, 0xAA52);

    /**
    \brief Create a new directory

    <pre>FSpDirCreate creates a new empty directory.
spec is a pointer to an FSSpec record identifying the new directory
scriptTag identifies the script system code
createDirID ;on return, will identify the new directory
Returns: an operating system Error Code . It will be one of:
noErr(0) No error
bdNamErr (-37) Bad name
dirFulErr (-33) Directory full
dirNFErr (-120) Directory not found
dupFNErr (-48) Duplicate filename (rename)
extFSErr (-58) External file system
ioErr(-36) I/O error
nsvErr (-35) No such volume
vLckdErr (-46) Volume is locked
wPrErr (-44) Diskette is write-protected
</pre>
* \note <pre> The FSpDirCreate function creates a new directory. It is a high-level,
FSSpec version of PBDirCreate .
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
    OSErr
    FSpDirCreate(const FSSpec *spec, ScriptCode scriptTag, long *createdDirID)
        TWOWORDINLINE(0x7005, 0xAA52);

    /**
    \brief Remove a closed file

    <pre>FSpDelete removes a closed file.
spec is a pointer to an FSSpec record specifying the file to be removed.
Returns: an operating system Error Code . It will be one of:
noErr(0) No error
bdNamErr (-37) Bad name
dirNFErr (-120) Directory not found or incomplete pathname
extFSErr (-58) External file system
fBsyErr (-47) File is busy, directory not empty, or working dir
open
fLckdErr (-45) File is locked
fnfErr(-43) File not found
ioErr(-36) I/O error
nsvErr (-35) No such volume
vLckdErr (-46) Volume is locked
wPrErr (-44) Diskette is write-protected
</pre>
* \note <pre> The FSpDelete function removes a closed file. It is the high-level,
FSSpec version of the PBHDelete function.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
    OSErr
    FSpDelete(const FSSpec *spec) TWOWORDINLINE(0x7006, 0xAA52);

    /**
    \brief Get Finder information

    <pre>The FSpGetFInfo function returns the Finder information from the volume
catalog entry for the specified file or directory. It provides only the original
Finder information-the FInfo and DInfo records, not FXInfo and DXInfo
spec is a pointer to an FSSpec record specifying the file to be opened
fndrInfo identifies the the original Finder information-the FInfo and DInfo
records
Returns: an operating system Error Code . It will be one of:
noErr(0) No error
bdNamErr (-37) Bad name
dirNFErr (-120) Directory not found
extFSErr (-58) External file system
fnfErr(-43) File not found
ioErr(-36) I/O error
nsvErr (-35) No such volume
paramErr (-50) Error in user parameter list
</pre>
* \note <pre> The FSpGetFInfo function is the high-level, FSSpec version of the
PBHGetFInfo function.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
    OSErr
    FSpGetFInfo(const FSSpec *spec, FInfo *fndrInfo) TWOWORDINLINE(0x7007, 0xAA52);

    /**
    \brief Set the Finder information

    <pre>The FSpSetFInfo function sets the Finder information in the volume catalog
entry for the specified file or directory. It affects only the original Finder
information-the FInfo and DInfo records, not FXInfo and DXInfo.
spec is a pointer to an FSSpec record specifying the file to be opened
fndrInfo identifies the the original Finder information-the FInfo and DInfo
records
Returns: an operating system Error Code. It will be one of:
noErr(0) No error
dirNFErr (-120) Directory not found
extFSErr (-58) External file system
fLckdErr (-45) File is locked
fnfErr(-43) File not found
ioErr(-36) I/O error
nsvErr (-35) No such volume
vLckdErr (-46) Volume is locked
wPrErr (-44) Diskette is write-protected
</pre>
* \note <pre> The FSpSetFInfo functions the high-level, FSSpec version of the
PBHSetFInfo function.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
    OSErr
    FSpSetFInfo(const FSSpec *spec, const FInfo *fndrInfo)
        TWOWORDINLINE(0x7008, 0xAA52);

    /**
    \brief Lock a file

    <pre>FSpSetFLock locks a file.
spec is pointer to an FSSpec record specifying the file to be locked.
Returns: an operating system Error Code. It will be one of:
noErr(0) No error
dirNFErr (-120) Directory not found
extFSErr (-58) External file system
fnfErr(-43) File not found
ioErr(-36) I/O error
nsvErr (-35) No such volume
vLckdErr (-46) Volume is locked
wPrErr (-44) Diskette is write-protected
</pre>
* \note <pre> The FSpSetFLock function locks a file. It is the high-level, FSSpec
version of the PBHSetFLock function.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
    OSErr
    FSpSetFLock(const FSSpec *spec) TWOWORDINLINE(0x7009, 0xAA52);

    /**
    \brief Unlock a file

    <pre>FSpRstFLock unlocks a file.
spec is pointer to an FSSpec record specifying the file to be unlocked.
Returns: an operating system Error Code. It will be one of:
noErr(0) No error
dirNFErr (-120) Directory not found
extFSErr (-58) External file system
fnfErr(-43) File not found
ioErr(-36) I/O error
nsvErr (-35) No such volume
vLckdErr (-46) Volume is locked
wPrErr (-44) Diskette is write-protected
</pre>
* \note <pre> The FSpRstFLock function unlocks a file. It is the high-level, FSSpec
version of the PBHRstFLock function.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
    OSErr
    FSpRstFLock(const FSSpec *spec) TWOWORDINLINE(0x700A, 0xAA52);

    /**
    \brief Change a file's name

    <pre>FSpRename function changes the name of a file or directory.
spec is pointer to aa FSSpec record specifying the file to be renamed.
newname is the name you want the file to have.
Returns: an operating system Error Code. It will be one of:
noErr(0) No error
bdNamErr (-37) Bad file or volume name
dirFulErr (-33) Directory full
dupFNErr (-48) Duplicate filename (new name already exists)
extFSErr (-58) External file system
fLckdErr (-45) File is locked
fnfErr(-43) File not found
fsRnErr (-59) File system rename error
ioErr(-36) I/O error
nsvErr (-35) No such volume
paramErr (-50) Error in user parameter list
vLckdErr (-46) Volume is locked
wPrErr (-44) Diskette is write-protected
</pre>
* \note <pre> The FSpRename function unlocks a file. It is the high-level, FSSpec
version of the PBHRename function.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
    OSErr
    FSpRename(const FSSpec *spec, ConstStr255Param newName)
        TWOWORDINLINE(0x700B, 0xAA52);

    /**
    \brief Change a file's location

    <pre>FSpCatMove function changes the location of a file or directory.
source is a pointer to an FSSpec record specifying the file to be moved.
dest is a pointer to an FSSpec record specifying the file's new location.
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
badMovErr (-122) Can't move into offspring
bdNamErr (-37) Bad file name or attempt to move into file
dupFNErr (-48) Duplicate filename (destination file/dir already
exists)
fnfErr(-43) Source file not found
ioErr(-36) I/O error
nsvErr (-35) No such volume
paramErr (-50) Error in user parameter list
vLckdErr (-46) Volume is locked
wPrErr (-44) Diskette is write-protected
</pre>
* \note <pre> The FSpCatMove is the high-level, FSSpec version of the PBCatMove
function. It moves the file or directory specified by the source parameter to
the destination specified by the dest parameter. The source and dest
parameters specify the name and location of the file or directory before and
after the move.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
    OSErr
    FSpCatMove(const FSSpec *source, const FSSpec *dest)
        TWOWORDINLINE(0x700C, 0xAA52);

    /**
    \brief FSpExchangeFiles Swap the files' data

    <pre>FSpExchangeFiles swaps the files' data by changing the information in the
volume's catalog and, if the files are open, in the file control blocks.
source is a pointer to an FSSpec record specifying the source file.
destis a pointer to an FSSpec specifying the file that will receive the
new data
</pre>
* \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
nsvErr (-35) Volume not found
ioErr(-36) I/O error
fnfErr(-43) File not found
fLckdErr (-45) File locked
volOffLinErr (-53) Volume is off line
extFSErr (-58) External file system
wrgVolTypErr (-123) Not an HFS volume
notAFileErr (-1302) Specified file is a directory
diffVolErr (-1303) Files on different volumes
</pre>
* \note <pre>The Tables in Updating Files under the section,
Using the File Manager , illustrate how FSpExchangeFiles alters the
catalog entries and file control blocks.
You should use FSpExchangeFiles when updating an existing file, so that
if the file is being tracked through its file ID, the ID remains valid.
Typically, you use PBExchangeFiles after creating a new file during a
safe save (see Updating Files under the section,
Using the File Manager ,). You identify the two files to be exchanged in
the source and dest parameters. FSpExchangeFiles changes the fields in
the catalog entries that record the location of the data and the modification
dates. It swaps both the data forks and the resource forks.
FSpExchangeFiles works on either open or closed files. If either file is
open, FSpExchangeFiles updates any file control blocks associated with
the file. Exchanging the contents of two files requires essentially the same
access as opening both files for writing.
FSpExchangeFiles does not require that file IDs exist for the files being
exchanged.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
    OSErr
    FSpExchangeFiles(const FSSpec *source, const FSSpec *dest)
        TWOWORDINLINE(0x700F, 0xAA52);

/**
 *  PBShareSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBShareSync(__A0)
#endif
    OSErr
    PBShareSync(HParmBlkPtr paramBlock) TWOWORDINLINE(0x7042, 0xA260);

/**
 *  PBShareAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBShareAsync(__A0)
#endif
    OSErr
    PBShareAsync(HParmBlkPtr paramBlock) TWOWORDINLINE(0x7042, 0xA660);

/**
 *  PBUnshareSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBUnshareSync(__A0)
#endif
    OSErr
    PBUnshareSync(HParmBlkPtr paramBlock) TWOWORDINLINE(0x7043, 0xA260);

/**
 *  PBUnshareAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBUnshareAsync(__A0)
#endif
    OSErr
    PBUnshareAsync(HParmBlkPtr paramBlock) TWOWORDINLINE(0x7043, 0xA660);

/**
 *  PBGetUGEntrySync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBGetUGEntrySync(__A0)
#endif
    OSErr
    PBGetUGEntrySync(HParmBlkPtr paramBlock) TWOWORDINLINE(0x7044, 0xA260);

/**
 *  PBGetUGEntryAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBGetUGEntryAsync(__A0)
#endif
    OSErr
    PBGetUGEntryAsync(HParmBlkPtr paramBlock) TWOWORDINLINE(0x7044, 0xA660);

#if TARGET_CPU_68K
/**
    PBGetAltAccess and PBSetAltAccess are obsolete and will not be supported
    on PowerPC. Equivalent functionality is provided by the routines
    PBGetForeignPrivs and PBSetForeignPrivs.
*/
#if CALL_NOT_IN_CARBON
/**
 *  PBGetAltAccessSync()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBGetAltAccessSync(__A0)
#endif
    OSErr
    PBGetAltAccessSync(HParmBlkPtr paramBlock) TWOWORDINLINE(0x7060, 0xA060);

/**
 *  PBGetAltAccessAsync()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBGetAltAccessAsync(__A0)
#endif
    OSErr
    PBGetAltAccessAsync(HParmBlkPtr paramBlock) TWOWORDINLINE(0x7060, 0xA460);

/**
 *  PBSetAltAccessSync()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBSetAltAccessSync(__A0)
#endif
    OSErr
    PBSetAltAccessSync(HParmBlkPtr paramBlock) TWOWORDINLINE(0x7061, 0xA060);

/**
 *  PBSetAltAccessAsync()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBSetAltAccessAsync(__A0)
#endif
    OSErr
    PBSetAltAccessAsync(HParmBlkPtr paramBlock) TWOWORDINLINE(0x7061, 0xA460);

#endif /* CALL_NOT_IN_CARBON */

#define PBSetAltAccess(pb, async) \
  ((async) ? PBSetAltAccessAsync(pb) : PBSetAltAccessSync(pb))
#define PBGetAltAccess(pb, async) \
  ((async) ? PBGetAltAccessAsync(pb) : PBGetAltAccessSync(pb))
#endif /* TARGET_CPU_68K */

/**
    The PBxxx() routines are obsolete.

    Use the PBxxxSync() or PBxxxAsync() version instead.
*/
#define PBGetVInfo(pb, async) \
  ((async) ? PBGetVInfoAsync(pb) : PBGetVInfoSync(pb))
#define PBXGetVolInfo(pb, async) \
  ((async) ? PBXGetVolInfoAsync(pb) : PBXGetVolInfoSync(pb))
#define PBGetVol(pb, async) ((async) ? PBGetVolAsync(pb) : PBGetVolSync(pb))
#define PBSetVol(pb, async) ((async) ? PBSetVolAsync(pb) : PBSetVolSync(pb))
#define PBFlushVol(pb, async) \
  ((async) ? PBFlushVolAsync(pb) : PBFlushVolSync(pb))
#define PBCreate(pb, async) ((async) ? PBCreateAsync(pb) : PBCreateSync(pb))
#define PBDelete(pb, async) ((async) ? PBDeleteAsync(pb) : PBDeleteSync(pb))
#define PBOpenDF(pb, async) ((async) ? PBOpenDFAsync(pb) : PBOpenDFSync(pb))
#define PBOpenRF(pb, async) ((async) ? PBOpenRFAsync(pb) : PBOpenRFSync(pb))
#define PBRename(pb, async) ((async) ? PBRenameAsync(pb) : PBRenameSync(pb))
#define PBGetFInfo(pb, async) \
  ((async) ? PBGetFInfoAsync(pb) : PBGetFInfoSync(pb))
#define PBSetFInfo(pb, async) \
  ((async) ? PBSetFInfoAsync(pb) : PBSetFInfoSync(pb))
#define PBSetFLock(pb, async) \
  ((async) ? PBSetFLockAsync(pb) : PBSetFLockSync(pb))
#define PBRstFLock(pb, async) \
  ((async) ? PBRstFLockAsync(pb) : PBRstFLockSync(pb))
#define PBSetFVers(pb, async) \
  ((async) ? PBSetFVersAsync(pb) : PBSetFVersSync(pb))
#define PBAllocate(pb, async) \
  ((async) ? PBAllocateAsync(pb) : PBAllocateSync(pb))
#define PBGetEOF(pb, async) ((async) ? PBGetEOFAsync(pb) : PBGetEOFSync(pb))
#define PBSetEOF(pb, async) ((async) ? PBSetEOFAsync(pb) : PBSetEOFSync(pb))
#define PBGetFPos(pb, async) ((async) ? PBGetFPosAsync(pb) : PBGetFPosSync(pb))
#define PBSetFPos(pb, async) ((async) ? PBSetFPosAsync(pb) : PBSetFPosSync(pb))
#define PBFlushFile(pb, async) \
  ((async) ? PBFlushFileAsync(pb) : PBFlushFileSync(pb))
#define PBCatSearch(pb, async) \
  ((async) ? PBCatSearchAsync(pb) : PBCatSearchSync(pb))
#define PBOpenWD(pb, async) ((async) ? PBOpenWDAsync(pb) : PBOpenWDSync(pb))
#define PBCloseWD(pb, async) ((async) ? PBCloseWDAsync(pb) : PBCloseWDSync(pb))
#define PBHSetVol(pb, async) ((async) ? PBHSetVolAsync(pb) : PBHSetVolSync(pb))
#define PBHGetVol(pb, async) ((async) ? PBHGetVolAsync(pb) : PBHGetVolSync(pb))
#define PBCatMove(pb, async) ((async) ? PBCatMoveAsync(pb) : PBCatMoveSync(pb))
#define PBDirCreate(pb, async) \
  ((async) ? PBDirCreateAsync(pb) : PBDirCreateSync(pb))
#define PBGetWDInfo(pb, async) \
  ((async) ? PBGetWDInfoAsync(pb) : PBGetWDInfoSync(pb))
#define PBGetFCBInfo(pb, async) \
  ((async) ? PBGetFCBInfoAsync(pb) : PBGetFCBInfoSync(pb))
#define PBGetCatInfo(pb, async) \
  ((async) ? PBGetCatInfoAsync(pb) : PBGetCatInfoSync(pb))
#define PBSetCatInfo(pb, async) \
  ((async) ? PBSetCatInfoAsync(pb) : PBSetCatInfoSync(pb))
#define PBAllocContig(pb, async) \
  ((async) ? PBAllocContigAsync(pb) : PBAllocContigSync(pb))
#define PBLockRange(pb, async) \
  ((async) ? PBLockRangeAsync(pb) : PBLockRangeSync(pb))
#define PBUnlockRange(pb, async) \
  ((async) ? PBUnlockRangeAsync(pb) : PBUnlockRangeSync(pb))
#define PBSetVInfo(pb, async) \
  ((async) ? PBSetVInfoAsync(pb) : PBSetVInfoSync(pb))
#define PBHGetVInfo(pb, async) \
  ((async) ? PBHGetVInfoAsync(pb) : PBHGetVInfoSync(pb))
#define PBHOpen(pb, async) ((async) ? PBHOpenAsync(pb) : PBHOpenSync(pb))
#define PBHOpenRF(pb, async) ((async) ? PBHOpenRFAsync(pb) : PBHOpenRFSync(pb))
#define PBHOpenDF(pb, async) ((async) ? PBHOpenDFAsync(pb) : PBHOpenDFSync(pb))
#define PBHCreate(pb, async) ((async) ? PBHCreateAsync(pb) : PBHCreateSync(pb))
#define PBHDelete(pb, async) ((async) ? PBHDeleteAsync(pb) : PBHDeleteSync(pb))
#define PBHRename(pb, async) ((async) ? PBHRenameAsync(pb) : PBHRenameSync(pb))
#define PBHRstFLock(pb, async) \
  ((async) ? PBHRstFLockAsync(pb) : PBHRstFLockSync(pb))
#define PBHSetFLock(pb, async) \
  ((async) ? PBHSetFLockAsync(pb) : PBHSetFLockSync(pb))
#define PBHGetFInfo(pb, async) \
  ((async) ? PBHGetFInfoAsync(pb) : PBHGetFInfoSync(pb))
#define PBHSetFInfo(pb, async) \
  ((async) ? PBHSetFInfoAsync(pb) : PBHSetFInfoSync(pb))
#define PBMakeFSSpec(pb, async) \
  ((async) ? PBMakeFSSpecAsync(pb) : PBMakeFSSpecSync(pb))
#define PBHGetVolParms(pb, async) \
  ((async) ? PBHGetVolParmsAsync(pb) : PBHGetVolParmsSync(pb))
#define PBHGetLogInInfo(pb, async) \
  ((async) ? PBHGetLogInInfoAsync(pb) : PBHGetLogInInfoSync(pb))
#define PBHGetDirAccess(pb, async) \
  ((async) ? PBHGetDirAccessAsync(pb) : PBHGetDirAccessSync(pb))
#define PBHSetDirAccess(pb, async) \
  ((async) ? PBHSetDirAccessAsync(pb) : PBHSetDirAccessSync(pb))
#define PBHMapID(pb, async) ((async) ? PBHMapIDAsync(pb) : PBHMapIDSync(pb))
#define PBHMapName(pb, async) \
  ((async) ? PBHMapNameAsync(pb) : PBHMapNameSync(pb))
#define PBHCopyFile(pb, async) \
  ((async) ? PBHCopyFileAsync(pb) : PBHCopyFileSync(pb))
#define PBHMoveRename(pb, async) \
  ((async) ? PBHMoveRenameAsync(pb) : PBHMoveRenameSync(pb))
#define PBHOpenDeny(pb, async) \
  ((async) ? PBHOpenDenyAsync(pb) : PBHOpenDenySync(pb))
#define PBHOpenRFDeny(pb, async) \
  ((async) ? PBHOpenRFDenyAsync(pb) : PBHOpenRFDenySync(pb))
#define PBExchangeFiles(pb, async) \
  ((async) ? PBExchangeFilesAsync(pb) : PBExchangeFilesSync(pb))
#define PBCreateFileIDRef(pb, async) \
  ((async) ? PBCreateFileIDRefAsync(pb) : PBCreateFileIDRefSync(pb))
#define PBResolveFileIDRef(pb, async) \
  ((async) ? PBResolveFileIDRefAsync(pb) : PBResolveFileIDRefSync(pb))
#define PBDeleteFileIDRef(pb, async) \
  ((async) ? PBDeleteFileIDRefAsync(pb) : PBDeleteFileIDRefSync(pb))
#define PBGetForeignPrivs(pb, async) \
  ((async) ? PBGetForeignPrivsAsync(pb) : PBGetForeignPrivsSync(pb))
#define PBSetForeignPrivs(pb, async) \
  ((async) ? PBSetForeignPrivsAsync(pb) : PBSetForeignPrivsSync(pb))
#define PBDTAddIcon(pb, async) \
  ((async) ? PBDTAddIconAsync(pb) : PBDTAddIconSync(pb))
#define PBDTGetIcon(pb, async) \
  ((async) ? PBDTGetIconAsync(pb) : PBDTGetIconSync(pb))
#define PBDTGetIconInfo(pb, async) \
  ((async) ? PBDTGetIconInfoAsync(pb) : PBDTGetIconInfoSync(pb))
#define PBDTAddAPPL(pb, async) \
  ((async) ? PBDTAddAPPLAsync(pb) : PBDTAddAPPLSync(pb))
#define PBDTRemoveAPPL(pb, async) \
  ((async) ? PBDTRemoveAPPLAsync(pb) : PBDTRemoveAPPLSync(pb))
#define PBDTGetAPPL(pb, async) \
  ((async) ? PBDTGetAPPLAsync(pb) : PBDTGetAPPLSync(pb))
#define PBDTSetComment(pb, async) \
  ((async) ? PBDTSetCommentAsync(pb) : PBDTSetCommentSync(pb))
#define PBDTRemoveComment(pb, async) \
  ((async) ? PBDTRemoveCommentAsync(pb) : PBDTRemoveCommentSync(pb))
#define PBDTGetComment(pb, async) \
  ((async) ? PBDTGetCommentAsync(pb) : PBDTGetCommentSync(pb))
#define PBDTFlush(pb, async) ((async) ? PBDTFlushAsync(pb) : PBDTFlushSync(pb))
#define PBDTReset(pb, async) ((async) ? PBDTResetAsync(pb) : PBDTResetSync(pb))
#define PBDTGetInfo(pb, async) \
  ((async) ? PBDTGetInfoAsync(pb) : PBDTGetInfoSync(pb))
#define PBDTDelete(pb, async) \
  ((async) ? PBDTDeleteAsync(pb) : PBDTDeleteSync(pb))

    typedef SInt16 FSVolumeRefNum;
    enum
    {
      kFSInvalidVolumeRefNum = 0
    };

    struct FSRef
    {
      UInt8 hidden[80]; /* private to File Manager; ©© need symbolic constant */
    };
    typedef struct FSRef FSRef;
    typedef FSRef *FSRefPtr;

    /**
     *  FSPermissionInfo
     *
     *  Discussion:
     *    This structure is used when kFSCatInfoPermissions is passed to
     *    the HFSPlus API. On return from GetCatalogInfo and
     *    GetCatalogInfoBulk, the userID, groupID, and mode fields are
     *    returned.  When passed to SetCatalogInfo, only the mode field is
     *    set.  See chmod(2) for details about the mode field. This is
     *    supported on Mac OS X only.
     */
    struct FSPermissionInfo
    {
      UInt32 userID;
      UInt32 groupID;
      UInt8 reserved1;
      UInt8 userAccess;
      UInt16 mode;
      UInt32 reserved2;
    };
    typedef struct FSPermissionInfo FSPermissionInfo;
    /*  CatalogInfoBitmap describes which fields of the CatalogInfo you wish to get
     * or set.*/

    typedef UInt32 FSCatalogInfoBitmap;
    enum
    {
      kFSCatInfoNone = 0x00000000,
      kFSCatInfoTextEncoding = 0x00000001,
      kFSCatInfoNodeFlags =
          0x00000002, /* Locked (bit 0) and directory (bit 4) only */
      kFSCatInfoVolume = 0x00000004,
      kFSCatInfoParentDirID = 0x00000008,
      kFSCatInfoNodeID = 0x00000010,
      kFSCatInfoCreateDate = 0x00000020,
      kFSCatInfoContentMod = 0x00000040,
      kFSCatInfoAttrMod = 0x00000080,
      kFSCatInfoAccessDate = 0x00000100,
      kFSCatInfoBackupDate = 0x00000200,
      kFSCatInfoPermissions = 0x00000400, /* Should this be finer granularity? */
      kFSCatInfoFinderInfo = 0x00000800,
      kFSCatInfoFinderXInfo = 0x00001000,
      kFSCatInfoValence = 0x00002000,   /* Folders only, zero for files */
      kFSCatInfoDataSizes = 0x00004000, /* Data fork logical and physical size */
      kFSCatInfoRsrcSizes =
          0x00008000,                      /* Resource fork logical and physical size */
      kFSCatInfoSharingFlags = 0x00010000, /* sharingFlags: kioFlAttribMountedBit,
                                              kioFlAttribSharePointBit */
      kFSCatInfoUserPrivs = 0x00020000,    /* userPrivileges */
      kFSCatInfoUserAccess = 0x00080000,   /* (OS X only) */
      kFSCatInfoAllDates = 0x000003E0,
      kFSCatInfoGettableInfo = 0x0003FFFF,
      kFSCatInfoSettableInfo =
          0x00001FE3,                       /* flags, dates, permissions, Finder info, text encoding */
      kFSCatInfoReserved = (long)0xFFFC0000 /* bits that are currently reserved */
    };

    /*  Constants for nodeFlags field of FSCatalogInfo */
    enum
    {
      kFSNodeLockedBit = 0, /* Set if file or directory is locked */
      kFSNodeLockedMask = 0x0001,
      kFSNodeResOpenBit = 2, /* Set if the resource fork is open */
      kFSNodeResOpenMask = 0x0004,
      kFSNodeDataOpenBit = 3, /* Set if the data fork is open */
      kFSNodeDataOpenMask = 0x0008,
      kFSNodeIsDirectoryBit = 4, /* Set if the object is a directory */
      kFSNodeIsDirectoryMask = 0x0010,
      kFSNodeCopyProtectBit = 6,
      kFSNodeCopyProtectMask = 0x0040,
      kFSNodeForkOpenBit = 7, /* Set if the file or directory has any open fork */
      kFSNodeForkOpenMask = 0x0080
    };

    /*  Constants for sharingFlags field of FSCatalogInfo */
    enum
    {
      kFSNodeInSharedBit = 2, /* Set if a directory is within a share point */
      kFSNodeInSharedMask = 0x0004,
      kFSNodeIsMountedBit = 3, /* Set if a directory is a share point currently
                                  mounted by some user */
      kFSNodeIsMountedMask = 0x0008,
      kFSNodeIsSharePointBit =
          5, /* Set if a directory is a share point (exported volume) */
      kFSNodeIsSharePointMask = 0x0020
    };

    struct FSCatalogInfo
    {
      UInt16 nodeFlags;      /* node flags */
      FSVolumeRefNum volume; /* object's volume ref */
      UInt32 parentDirID;    /* parent directory's ID */
      UInt32 nodeID;         /* file/directory ID */
      UInt8 sharingFlags;    /* kioFlAttribMountedBit and kioFlAttribSharePointBit */
      UInt8 userPrivileges;  /* user's effective AFP privileges (same as ioACUser) */
      UInt8 reserved1;
      UInt8 reserved2;
      UTCDateTime createDate;     /* date and time of creation */
      UTCDateTime contentModDate; /* date and time of last fork modification */
      UTCDateTime
          attributeModDate;   /* date and time of last attribute modification */
      UTCDateTime accessDate; /* date and time of last access (for Mac OS X) */
      UTCDateTime backupDate; /* date and time of last backup */

      UInt32 permissions[4]; /* permissions (for Mac OS X) */

      UInt8 finderInfo[16];    /* Finder information part 1 */
      UInt8 extFinderInfo[16]; /* Finder information part 2 */

      UInt64 dataLogicalSize;  /* files only */
      UInt64 dataPhysicalSize; /* files only */
      UInt64 rsrcLogicalSize;  /* files only */
      UInt64 rsrcPhysicalSize; /* files only */

      UInt32 valence; /* folders only */
      TextEncoding textEncodingHint;
    };
    typedef struct FSCatalogInfo FSCatalogInfo;
    typedef FSCatalogInfo *FSCatalogInfoPtr;
    struct FSRefParam
    {
      QElemPtr qLink;               /*queue link in header*/
      short qType;                  /*type byte for safety check*/
      short ioTrap;                 /*FS: the Trap*/
      Ptr ioCmdAddr;                /*FS: address to dispatch to*/
      IOCompletionUPP ioCompletion; /*completion routine addr (0 for synch calls)*/
      volatile OSErr ioResult;      /*result code*/
      ConstStringPtr ioNamePtr;     /*ptr to Vol:FileName string*/
      short ioVRefNum;              /*volume refnum (DrvNum for Eject and MountVol)*/

      SInt16 reserved1; /* was ioRefNum */
      UInt8 reserved2;  /* was ioVersNum */
      UInt8 reserved3;  /* was ioPermssn */

      const FSRef *ref; /* Input ref; the target of the call */
      FSCatalogInfoBitmap whichInfo;
      FSCatalogInfo *catInfo;
      UniCharCount nameLength; /* input name length for create/rename */
      const UniChar *name;     /* input name for create/rename */
      long ioDirID;
      FSSpec *spec;
      FSRef *parentRef;              /* ref of directory to move another ref to */
      FSRef *newRef;                 /* Output ref */
      TextEncoding textEncodingHint; /* for Rename, MakeFSRefUnicode */
      HFSUniStr255 *outName;         /* Output name for GetCatalogInfo */
    };
    typedef struct FSRefParam FSRefParam;
    typedef FSRefParam *FSRefParamPtr;
    typedef struct OpaqueFSIterator *FSIterator;
    enum
    {
      kFSIterateFlat = 0,    /* Immediate children of container only */
      kFSIterateSubtree = 1, /* Entire subtree rooted at container */
      kFSIterateDelete = 2,
      kFSIterateReserved = (long)0xFFFFFFFC
    };

    typedef OptionBits FSIteratorFlags;
    enum
    {
      /* CatalogSearch constants */
      fsSBNodeID = 0x00008000,           /* search by range of nodeID */
      fsSBAttributeModDate = 0x00010000, /* search by range of attributeModDate */
      fsSBAccessDate = 0x00020000,       /* search by range of accessDate */
      fsSBPermissions = 0x00040000,      /* search by value/mask of permissions */
      fsSBNodeIDBit = 15,
      fsSBAttributeModDateBit = 16,
      fsSBAccessDateBit = 17,
      fsSBPermissionsBit = 18
    };

    struct FSSearchParams
    {
      Duration searchTime;   /* a Time Manager duration */
      OptionBits searchBits; /* which fields to search on */
      UniCharCount searchNameLength;
      const UniChar *searchName;
      FSCatalogInfo *searchInfo1; /* values and lower bounds */
      FSCatalogInfo *searchInfo2; /* masks and upper bounds */
    };
    typedef struct FSSearchParams FSSearchParams;
    typedef FSSearchParams *FSSearchParamsPtr;
    struct FSCatalogBulkParam
    {
      QElemPtr qLink;               /*queue link in header*/
      short qType;                  /*type byte for safety check*/
      short ioTrap;                 /*FS: the Trap*/
      Ptr ioCmdAddr;                /*FS: address to dispatch to*/
      IOCompletionUPP ioCompletion; /*completion routine addr (0 for synch calls)*/
      volatile OSErr ioResult;      /*result code*/
      Boolean containerChanged;     /* true if container changed since last iteration */
      UInt8 reserved;               /* make following fields 4-byte aligned */

      FSIteratorFlags iteratorFlags;
      FSIterator iterator;
      const FSRef *container; /* directory/volume to iterate */
      ItemCount maximumItems;
      ItemCount actualItems;
      FSCatalogInfoBitmap whichInfo;
      FSCatalogInfo *catalogInfo; /* returns an array */
      FSRef *refs;                /* returns an array */
      FSSpec *specs;              /* returns an array */
      HFSUniStr255 *names;        /* returns an array */
      const FSSearchParams *searchParams;
    };
    typedef struct FSCatalogBulkParam FSCatalogBulkParam;
    typedef FSCatalogBulkParam *FSCatalogBulkParamPtr;
    typedef UInt16 FSAllocationFlags;
    enum
    {
      kFSAllocDefaultFlags = 0x0000,     /* as much as possible, not contiguous */
      kFSAllocAllOrNothingMask = 0x0001, /* allocate all of the space, or nothing */
      kFSAllocContiguousMask = 0x0002,   /* new space must be one contiguous piece */
      kFSAllocNoRoundUpMask = 0x0004,    /* don't round up allocation to clump size */
      kFSAllocReservedMask =
          0xFFF8 /* these bits are reserved and must not be set */
    };

    struct FSForkIOParam
    {
      QElemPtr qLink;               /*queue link in header*/
      short qType;                  /*type byte for safety check*/
      short ioTrap;                 /*FS: the Trap*/
      Ptr ioCmdAddr;                /*FS: address to dispatch to*/
      IOCompletionUPP ioCompletion; /*completion routine addr (0 for synch calls)*/
      volatile OSErr ioResult;      /*result code*/
      void *reserved1;              /* was ioNamePtr */
      SInt16 reserved2;             /* was ioVRefNum */
      SInt16 forkRefNum;            /* same as ioRefNum */
      UInt8 reserved3;              /* was ioVersNum */
      SInt8 permissions;            /* desired access to the fork */
      const FSRef *ref;             /* which object to open */

      Ptr buffer;            /*data buffer Ptr*/
      UInt32 requestCount;   /*requested byte count*/
      UInt32 actualCount;    /*actual byte count completed*/
      UInt16 positionMode;   /*initial file positioning*/
      SInt64 positionOffset; /*file position offset*/

      FSAllocationFlags allocationFlags;
      UInt64 allocationAmount;

      UniCharCount forkNameLength; /* input; length of fork name */
      const UniChar *forkName;     /* input; name of fork */

      CatPositionRec forkIterator;
      HFSUniStr255 *outForkName; /* output; name of fork */
    };
    typedef struct FSForkIOParam FSForkIOParam;
    typedef FSForkIOParam *FSForkIOParamPtr;
    struct FSForkInfo
    {
      SInt8 flags; /* copy of FCB flags */
      SInt8 permissions;
      FSVolumeRefNum volume;
      UInt32 reserved2;
      UInt32 nodeID; /* file or directory ID */
      UInt32 forkID; /* fork ID */
      UInt64 currentPosition;
      UInt64 logicalEOF;
      UInt64 physicalEOF;
      UInt64 process; /* should be ProcessSerialNumber */
    };
    typedef struct FSForkInfo FSForkInfo;
    typedef FSForkInfo *FSForkInfoPtr;
    struct FSForkCBInfoParam
    {
      QElemPtr qLink;               /*queue link in header*/
      short qType;                  /*type byte for safety check*/
      short ioTrap;                 /*FS: the Trap*/
      Ptr ioCmdAddr;                /*FS: address to dispatch to*/
      IOCompletionUPP ioCompletion; /*completion routine addr (0 for synch calls)*/
      volatile OSErr ioResult;      /*result code*/
      SInt16 desiredRefNum;         /* 0 to iterate, non-0 for specific refnum */
      SInt16 volumeRefNum;          /* volume to match, or 0 for all volumes */
      SInt16 iterator;              /* 0 to start iteration */
      SInt16 actualRefNum;          /* actual refnum found */

      FSRef *ref;
      FSForkInfo *forkInfo;
      HFSUniStr255 *forkName;
    };
    typedef struct FSForkCBInfoParam FSForkCBInfoParam;
    typedef FSForkCBInfoParam *FSForkCBInfoParamPtr;
    typedef UInt32 FSVolumeInfoBitmap;
    enum
    {
      kFSVolInfoNone = 0x0000,
      kFSVolInfoCreateDate = 0x0001,
      kFSVolInfoModDate = 0x0002,
      kFSVolInfoBackupDate = 0x0004,
      kFSVolInfoCheckedDate = 0x0008,
      kFSVolInfoFileCount = 0x0010,
      kFSVolInfoDirCount = 0x0020,
      kFSVolInfoSizes = 0x0040,  /* totalBytes and freeBytes */
      kFSVolInfoBlocks = 0x0080, /* blockSize, totalBlocks, freeBlocks */
      kFSVolInfoNextAlloc = 0x0100,
      kFSVolInfoRsrcClump = 0x0200,
      kFSVolInfoDataClump = 0x0400,
      kFSVolInfoNextID = 0x0800,
      kFSVolInfoFinderInfo = 0x1000,
      kFSVolInfoFlags = 0x2000,
      kFSVolInfoFSInfo = 0x4000,    /* filesystemID, signature */
      kFSVolInfoDriveInfo = 0x8000, /* driveNumber, driverRefNum */
      kFSVolInfoGettableInfo =
          0xFFFF,                     /* This seems like it is here just for completeness */
      kFSVolInfoSettableInfo = 0x3004 /* backup date, Finder info, flags */
    };

    /* FSVolumeInfo.flags bits.  These are the same as for ioVAtrb, but with nicer
     * names. */
    enum
    {
      kFSVolFlagDefaultVolumeBit = 5, /* Set if the volume is the default volume */
      kFSVolFlagDefaultVolumeMask = 0x0020,
      kFSVolFlagFilesOpenBit = 6, /* Set if there are open files or iterators */
      kFSVolFlagFilesOpenMask = 0x0040,
      kFSVolFlagHardwareLockedBit =
          7, /* Set if volume is locked by a hardware setting */
      kFSVolFlagHardwareLockedMask = 0x0080,
      kFSVolFlagSoftwareLockedBit = 15, /* Set if volume is locked by software */
      kFSVolFlagSoftwareLockedMask = 0x8000
    };

    struct FSVolumeInfo
    {
      /* Dates -- zero means "never" or "unknown" */
      UTCDateTime createDate;
      UTCDateTime modifyDate;
      UTCDateTime backupDate;
      UTCDateTime checkedDate;

      /* File/Folder counts -- return zero if unknown */
      UInt32 fileCount;   /* total files on volume */
      UInt32 folderCount; /* total folders on volume */
                          /* Note: no root directory counts */

      UInt64 totalBytes; /* total number of bytes on volume */
      UInt64 freeBytes;  /* number of free bytes on volume */

      /* HFS and HFS Plus specific.  Set fields to zero if not appropriate */
      UInt32 blockSize;      /* size (in bytes) of allocation blocks */
      UInt32 totalBlocks;    /* number of allocation blocks in volume */
      UInt32 freeBlocks;     /* number of unused allocation blocks */
      UInt32 nextAllocation; /* start of next allocation search */
      UInt32 rsrcClumpSize;  /* default resource fork clump size */
      UInt32 dataClumpSize;  /* default data fork clump size */
      UInt32 nextCatalogID;  /* next unused catalog node ID ©©© OYG ©©© need to make
                                HFSVolumes.h work Should be HFSCatalogNodeID*/
      UInt8 finderInfo[32];  /* information used by Finder */

      /* Identifying information */
      UInt16 flags;        /* ioVAtrb */
      UInt16 filesystemID; /* ioVFSID */
      UInt16 signature;    /* ioVSigWord, unique within an FSID */
      UInt16 driveNumber;  /* ioVDrvInfo */
      short driverRefNum;  /* ioVDRefNum */
    };
    typedef struct FSVolumeInfo FSVolumeInfo;
    typedef FSVolumeInfo *FSVolumeInfoPtr;
    struct FSVolumeInfoParam
    {
      QElemPtr qLink;               /*queue link in header*/
      short qType;                  /*type byte for safety check*/
      short ioTrap;                 /*FS: the Trap*/
      Ptr ioCmdAddr;                /*FS: address to dispatch to*/
      IOCompletionUPP ioCompletion; /*completion routine addr (0 for synch calls)*/
      volatile OSErr ioResult;      /*result code*/
      StringPtr ioNamePtr;          /* unused */
      FSVolumeRefNum ioVRefNum;     /* volume refnum */

      UInt32 volumeIndex;           /* index, or 0 to use ioVRefNum */
      FSVolumeInfoBitmap whichInfo; /* which volumeInfo fields to get/set */
      FSVolumeInfo *volumeInfo;     /* information about the volume */
      HFSUniStr255 *volumeName;     /* output; pointer to volume name */
      FSRef *ref;                   /* volume's FSRef */
    };
    typedef struct FSVolumeInfoParam FSVolumeInfoParam;
    typedef FSVolumeInfoParam *FSVolumeInfoParamPtr;
    /**
        MakeFSRef
        Create an FSRef for an existing object specified by a combination
        of volume refnum, parent directory, and pathname.
        ->  ioCompletion    A pointer to a completion routine
        <-  ioResult        The result code of the function
        ->  ioNamePtr       A pointer to a pathname
        ->  ioVRefNum       A volume specification
        ->  ioDirID         A directory ID
        <-  newRef          A pointer to an FSRef
    */
    /**
     *  FSpMakeFSRef()
     *

     *    \non_carbon_cfm   in InterfaceLib 9.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    FSpMakeFSRef(const FSSpec *source, FSRef *newRef)
        THREEWORDINLINE(0x303C, 0x041A, 0xAA52);

/**
 *  PBMakeFSRefSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 9.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBMakeFSRefSync(__A0)
#endif
    OSErr
    PBMakeFSRefSync(FSRefParam *paramBlock) TWOWORDINLINE(0x706E, 0xA260);

/**
 *  PBMakeFSRefAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 9.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter PBMakeFSRefAsync(__A0)
#endif
    void
    PBMakeFSRefAsync(FSRefParam *paramBlock) TWOWORDINLINE(0x706E, 0xA660);

    /**
        MakeFSRefUnicode
        Create an FSRef for an existing object specified by
        Parent FSRef and Unicode name.
        ->  ioCompletion    A pointer to a completion routine
        <-  ioResult        The result code of the function
        ->  ref             A pointer to the parent directory FSRef
        ->  name            A pointer to Unicde name
        ->  nameLength      The length of the Unicode Name
        ->  textEncodingHint A suggested text encoding to use for the name
        <-  newRef          A pointer to an FSRef
    */
    /**
     *  FSMakeFSRefUnicode()
     *

     *    \non_carbon_cfm   in InterfaceLib 9.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    FSMakeFSRefUnicode(const FSRef *parentRef, UniCharCount nameLength,
                       const UniChar *name, TextEncoding textEncodingHint,
                       FSRef *newRef) THREEWORDINLINE(0x303C, 0x0A1B, 0xAA52);

/**
 *  PBMakeFSRefUnicodeSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 9.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBMakeFSRefUnicodeSync(__A0)
#endif
    OSErr
    PBMakeFSRefUnicodeSync(FSRefParam *paramBlock) TWOWORDINLINE(0x707A, 0xA260);

/**
 *  PBMakeFSRefUnicodeAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 9.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter PBMakeFSRefUnicodeAsync(__A0)
#endif
    void
    PBMakeFSRefUnicodeAsync(FSRefParam *paramBlock) TWOWORDINLINE(0x707A, 0xA660);

    /**
        CompareFSRefs
        Test whether two FSRefs refer to the same file or directory.
        If they do, noErr is returned.  Otherwise, an appropriate error
        (such as errFSRefsDifferent) is returned.
        ->  ioCompletion    A pointer to a completion routine
        <-  ioResult        The result code of the function
        ->  ref             A pointer to the first FSRef
        ->  parentRef       A pointer to the second FSRef
    */
    /**
     *  FSCompareFSRefs()
     *

     *    \non_carbon_cfm   in InterfaceLib 9.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    FSCompareFSRefs(const FSRef *ref1, const FSRef *ref2)
        THREEWORDINLINE(0x303C, 0x0435, 0xAA52);

/**
 *  PBCompareFSRefsSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 9.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBCompareFSRefsSync(__A0)
#endif
    OSErr
    PBCompareFSRefsSync(FSRefParam *paramBlock) TWOWORDINLINE(0x707C, 0xA260);

/**
 *  PBCompareFSRefsAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 9.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter PBCompareFSRefsAsync(__A0)
#endif
    void
    PBCompareFSRefsAsync(FSRefParam *paramBlock) TWOWORDINLINE(0x707C, 0xA660);

    /**
        CreateFileUnicode
        Creates a new file.  The input filename is in Unicode.
        You can optionally set catalog info for the file.
        ->  ioCompletion    A pointer to a completion routine
        <-  ioResult        The result code of the function
        ->  ref             The directory where the file is to be created
        ->  whichInfo       Which catalog info fields to set
        ->  catInfo         The values for catalog info fields to set; may be NULL
        ->  nameLength      Number of Unicode characters in the file's name
        ->  name            A pointer to the Unicode name
        <-  spec            A pointer to the FSSpec for the new directory; may be
       NULL
        <-  newRef          A pointer to the FSRef for the new file; may be NULL
    */
    /**
     *  FSCreateFileUnicode()
     *

     *    \non_carbon_cfm   in InterfaceLib 9.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    FSCreateFileUnicode(const FSRef *parentRef, UniCharCount nameLength,
                        const UniChar *name, FSCatalogInfoBitmap whichInfo,
                        const FSCatalogInfo *catalogInfo, /* can be NULL */
                        FSRef *newRef,                    /* can be NULL */
                        FSSpec *newSpec) /* can be NULL */ THREEWORDINLINE(0x303C,
                                                                           0x0E1C,
                                                                           0xAA52);

/**
 *  PBCreateFileUnicodeSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 9.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBCreateFileUnicodeSync(__A0)
#endif
    OSErr
    PBCreateFileUnicodeSync(FSRefParam *paramBlock) TWOWORDINLINE(0x7070, 0xA260);

/**
 *  PBCreateFileUnicodeAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 9.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter PBCreateFileUnicodeAsync(__A0)
#endif
    void
    PBCreateFileUnicodeAsync(FSRefParam *paramBlock) TWOWORDINLINE(0x7070, 0xA660);

    /**
        CreateDirectoryUnicode
        Creates a new directory.  The input directory name is in Unicode.
        You can optionally set catalog info for the directory.
        ->  ioCompletion    A pointer to a completion routine
        <-  ioResult        The result code of the function
        ->  ref             The parent directory where the directory is to be
       created
        ->  whichInfo       Which catalog info fields to set
        ->  catInfo         The values for catalog info fields to set; may be NULL
        ->  nameLength      Number of Unicode characters in the directory's name
        ->  name            A pointer to the Unicode name
        <-  ioDirID         The DirID of the new directory
        <-  spec            A pointer to the FSSpec for the new directory; may be
       NULL
        <-  newRef          A pointer to the FSRef for the new directory; may be
       NULL
    */
    /**
     *  FSCreateDirectoryUnicode()
     *

     *    \non_carbon_cfm   in InterfaceLib 9.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    FSCreateDirectoryUnicode(
        const FSRef *parentRef, UniCharCount nameLength, const UniChar *name,
        FSCatalogInfoBitmap whichInfo,
        const FSCatalogInfo *catalogInfo, /* can be NULL */
        FSRef *newRef,                    /* can be NULL */
        FSSpec *newSpec,                  /* can be NULL */
        UInt32 *newDirID) /* can be NULL */ THREEWORDINLINE(0x303C, 0x101D, 0xAA52);

/**
 *  PBCreateDirectoryUnicodeSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 9.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBCreateDirectoryUnicodeSync(__A0)
#endif
    OSErr
    PBCreateDirectoryUnicodeSync(FSRefParam *paramBlock)
        TWOWORDINLINE(0x7071, 0xA260);

/**
 *  PBCreateDirectoryUnicodeAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 9.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter PBCreateDirectoryUnicodeAsync(__A0)
#endif
    void
    PBCreateDirectoryUnicodeAsync(FSRefParam *paramBlock)
        TWOWORDINLINE(0x7071, 0xA660);

    /**
        DeleteObject
        Deletes an existing file or directory.
        ->  ioCompletion    A pointer to a completion routine
        <-  ioResult        The result code of the function
        ->  ref             The file or directory to be deleted
    */
    /**
     *  FSDeleteObject()
     *

     *    \non_carbon_cfm   in InterfaceLib 9.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    FSDeleteObject(const FSRef *ref) THREEWORDINLINE(0x303C, 0x021E, 0xAA52);

/**
 *  PBDeleteObjectSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 9.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBDeleteObjectSync(__A0)
#endif
    OSErr
    PBDeleteObjectSync(FSRefParam *paramBlock) TWOWORDINLINE(0x7072, 0xA260);

/**
 *  PBDeleteObjectAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 9.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter PBDeleteObjectAsync(__A0)
#endif
    void
    PBDeleteObjectAsync(FSRefParam *paramBlock) TWOWORDINLINE(0x7072, 0xA660);

    /**
        MoveObject
        Move an existing file or directory into a different directory.
        ->  ioCompletion    A pointer to a completion routine
        <-  ioResult        The result code of the function
        ->  ref             The file or directory to be moved
        ->  parentRef       The file or directory will be moved into this directory
        <-  newRef          A new FSRef for the file or directory in its new
       location; optional, may be NULL NOTE: Moving an object may change its FSRef.
       If you want to continue to refer to the object, you should pass a non-NULL
       pointer in newRef and use that returned FSRef to access the object after the
       move.  The FSRef passed in "ref" may or may not be usable to access the
       object after it is moved. "newRef" may point to the same storage as
       "parentRef" or "ref".
    */
    /**
     *  FSMoveObject()
     *

     *    \non_carbon_cfm   in InterfaceLib 9.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    FSMoveObject(const FSRef *ref, const FSRef *destDirectory,
                 FSRef *newRef) /* can be NULL */ THREEWORDINLINE(0x303C, 0x061F,
                                                                  0xAA52);

/**
 *  PBMoveObjectSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 9.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBMoveObjectSync(__A0)
#endif
    OSErr
    PBMoveObjectSync(FSRefParam *paramBlock) TWOWORDINLINE(0x7073, 0xA260);

/**
 *  PBMoveObjectAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 9.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter PBMoveObjectAsync(__A0)
#endif
    void
    PBMoveObjectAsync(FSRefParam *paramBlock) TWOWORDINLINE(0x7073, 0xA660);

    /**
        ExchangeObjects
        swap the contents of two files.
        ->  ioCompletion    A pointer to a completion routine
        <-  ioResult        The result code of the function
        ->  ref             The first file
        ->  parentRef       The second file
    */
    /**
     *  FSExchangeObjects()
     *

     *    \non_carbon_cfm   in InterfaceLib 9.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    FSExchangeObjects(const FSRef *ref, const FSRef *destRef)
        THREEWORDINLINE(0x303C, 0x0421, 0xAA52);

/**
 *  PBExchangeObjectsSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 9.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBExchangeObjectsSync(__A0)
#endif
    OSErr
    PBExchangeObjectsSync(FSRefParam *paramBlock) TWOWORDINLINE(0x7075, 0xA260);

/**
 *  PBExchangeObjectsAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 9.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter PBExchangeObjectsAsync(__A0)
#endif
    void
    PBExchangeObjectsAsync(FSRefParam *paramBlock) TWOWORDINLINE(0x7075, 0xA660);

    /**
        RenameUnicode
        Change the name of an existing file or directory.  The new name is in
        Unicode.
        ->  ioCompletion    A pointer to a completion routine
        <-  ioResult        The result code of the function
        ->  ref             The file or directory to be moved
        ->  nameLength      Number of Unicode characters in the new name
        ->  name            A pointer to the new Unicode name
        ->  textEncodingHint A suggested text encoding to use for the name
        <-  newRef          A new FSRef for the file or directory; may be NULL
        NOTE: Renaming an object may change its FSRef.  If you want to continue to
        refer to the object, you should pass a non-NULL pointer in newRef and use
        that returned FSRef to access the object after the rename.  The FSRef passed
        in "ref" may or may not be usable to access the object after it is renamed.
        "newRef" may point to the same storage as "ref".
    */
    /**
     *  FSRenameUnicode()
     *

     *    \non_carbon_cfm   in InterfaceLib 9.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    FSRenameUnicode(const FSRef *ref, UniCharCount nameLength, const UniChar *name,
                    TextEncoding textEncodingHint,
                    FSRef *newRef) /* can be NULL */ THREEWORDINLINE(0x303C, 0x0A20,
                                                                     0xAA52);

/**
 *  PBRenameUnicodeSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 9.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBRenameUnicodeSync(__A0)
#endif
    OSErr
    PBRenameUnicodeSync(FSRefParam *paramBlock) TWOWORDINLINE(0x7074, 0xA260);

/**
 *  PBRenameUnicodeAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 9.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter PBRenameUnicodeAsync(__A0)
#endif
    void
    PBRenameUnicodeAsync(FSRefParam *paramBlock) TWOWORDINLINE(0x7074, 0xA660);

    /**
        GetCatalogInfo
        Returns various information about a given file or directory.
        ->  ioCompletion    A pointer to a completion routine
        <-  ioResult        The result code of the function
        ->  ref             The file or directory whose information is to be
       returned
        ->  whichInfo       Which catalog info fields to get
        <-  catInfo         The returned values of catalog info fields; may be NULL
        <-  spec            A pointer to the FSSpec for the object; may be NULL
        <-  parentRef       A pointer to the FSRef for the object's parent
       directory; may be NULL
        <-  outName         The Unicode name is returned here.  This pointer may be
       NULL. Note: All of the outputs are optional; if you don't want that
       particular output, just set its pointer to NULL.  This is the call to use to
       map from an FSRef to an FSSpec.
    */
    /**
     *  FSGetCatalogInfo()
     *

     *    \non_carbon_cfm   in InterfaceLib 9.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    FSGetCatalogInfo(const FSRef *ref, FSCatalogInfoBitmap whichInfo,
                     FSCatalogInfo *catalogInfo, /* can be NULL */
                     HFSUniStr255 *outName,      /* can be NULL */
                     FSSpec *fsSpec,             /* can be NULL */
                     FSRef *parentRef) /* can be NULL */ THREEWORDINLINE(0x303C,
                                                                         0x0C22,
                                                                         0xAA52);

/**
 *  PBGetCatalogInfoSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 9.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBGetCatalogInfoSync(__A0)
#endif
    OSErr
    PBGetCatalogInfoSync(FSRefParam *paramBlock) TWOWORDINLINE(0x7076, 0xA260);

/**
 *  PBGetCatalogInfoAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 9.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter PBGetCatalogInfoAsync(__A0)
#endif
    void
    PBGetCatalogInfoAsync(FSRefParam *paramBlock) TWOWORDINLINE(0x7076, 0xA660);

    /**
        SetCatalogInfo
        Set catalog information about a given file or directory.
        ->  ioCompletion    A pointer to a completion routine
        <-  ioResult        The result code of the function
        ->  ref             The file or directory whose information is to be changed
        ->  whichInfo       Which catalog info fields to set
        ->  catInfo         The new values of catalog info fields
        Note: Only some of the catalog info fields may be set.  The settable fields
        are given by the constant kFSCatInfoSettableInfo; no other bits may be set
       in whichInfo.
    */
    /**
     *  FSSetCatalogInfo()
     *

     *    \non_carbon_cfm   in InterfaceLib 9.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    FSSetCatalogInfo(const FSRef *ref, FSCatalogInfoBitmap whichInfo,
                     const FSCatalogInfo *catalogInfo)
        THREEWORDINLINE(0x303C, 0x0623, 0xAA52);

/**
 *  PBSetCatalogInfoSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 9.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBSetCatalogInfoSync(__A0)
#endif
    OSErr
    PBSetCatalogInfoSync(FSRefParam *paramBlock) TWOWORDINLINE(0x7077, 0xA260);

/**
 *  PBSetCatalogInfoAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 9.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter PBSetCatalogInfoAsync(__A0)
#endif
    void
    PBSetCatalogInfoAsync(FSRefParam *paramBlock) TWOWORDINLINE(0x7077, 0xA660);

    /**
        OpenIterator
        Creates an FSIterator to iterate over a directory or subtree.  The
        iterator can then be passed to GetCatalogInfoBulk or CatalogSearch.
        ->  ioCompletion    A pointer to a completion routine
        <-  ioResult        The result code of the function
        <-  iterator        The returned FSIterator
        ->  iteratorFlags   Controls whether the iterator iterates over subtrees
                            or just the immediate children of the container.
        ->  container       An FSRef for the directory to iterate (or root of
                            the subtree to iterate).
    */
    /**
     *  FSOpenIterator()
     *

     *    \non_carbon_cfm   in InterfaceLib 9.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    FSOpenIterator(const FSRef *container, FSIteratorFlags iteratorFlags,
                   FSIterator *iterator) THREEWORDINLINE(0x303C, 0x0624, 0xAA52);

/**
 *  PBOpenIteratorSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 9.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBOpenIteratorSync(__A0)
#endif
    OSErr
    PBOpenIteratorSync(FSCatalogBulkParam *paramBlock)
        TWOWORDINLINE(0x7078, 0xA260);

/**
 *  PBOpenIteratorAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 9.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter PBOpenIteratorAsync(__A0)
#endif
    void
    PBOpenIteratorAsync(FSCatalogBulkParam *paramBlock)
        TWOWORDINLINE(0x7078, 0xA660);

    /**
        CloseIterator
        Invalidates and disposes an FSIterator.
        ->  ioCompletion    A pointer to a completion routine
        <-  ioResult        The result code of the function
        ->  iterator        The returned FSIterator
    */
    /**
     *  FSCloseIterator()
     *

     *    \non_carbon_cfm   in InterfaceLib 9.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    FSCloseIterator(FSIterator iterator) THREEWORDINLINE(0x303C, 0x0225, 0xAA52);

/**
 *  PBCloseIteratorSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 9.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBCloseIteratorSync(__A0)
#endif
    OSErr
    PBCloseIteratorSync(FSCatalogBulkParam *paramBlock)
        TWOWORDINLINE(0x705B, 0xA260);

/**
 *  PBCloseIteratorAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 9.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter PBCloseIteratorAsync(__A0)
#endif
    void
    PBCloseIteratorAsync(FSCatalogBulkParam *paramBlock)
        TWOWORDINLINE(0x705B, 0xA660);

    /**
        GetCatalogInfoBulk
        Iterates over catalog objects and returns information about them.
        For now, iterator must have been created with kFSIterateFlat option.
        ->  ioCompletion    A pointer to a completion routine
        <-  ioResult        The result code of the function
        ->  iterator        The iterator
        ->  maximumItems    The maximum number of items to return
        <-  actualItems     The actual number of items returned
        <-  containerChanged Set to true if the container's contents changed
        ->  whichInfo       The catalog information fields to return for each item
        <-  catalogInfo     An array of catalog information; one for each returned
       item
        <-  refs            An array of FSRefs; one for each returned item
        <-  specs           An array of FSSpecs; one for each returned item
        <-  names           An array of filenames; one for each returned item
        Note: The catalogInfo, refs, specs, names, and containerChanged are all
       optional outputs; if you don't want that particular output, set its pointer
       to NULL.
    */
    /**
     *  FSGetCatalogInfoBulk()
     *

     *    \non_carbon_cfm   in InterfaceLib 9.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    FSGetCatalogInfoBulk(
        FSIterator iterator, ItemCount maximumObjects, ItemCount *actualObjects,
        Boolean *containerChanged, /* can be NULL */
        FSCatalogInfoBitmap whichInfo,
        FSCatalogInfo *catalogInfos, /* can be NULL */
        FSRef *refs,                 /* can be NULL */
        FSSpec *specs,               /* can be NULL */
        HFSUniStr255 *names) /* can be NULL */ THREEWORDINLINE(0x303C, 0x1226,
                                                               0xAA52);

/**
 *  PBGetCatalogInfoBulkSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 9.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBGetCatalogInfoBulkSync(__A0)
#endif
    OSErr
    PBGetCatalogInfoBulkSync(FSCatalogBulkParam *paramBlock)
        TWOWORDINLINE(0x705C, 0xA260);

/**
 *  PBGetCatalogInfoBulkAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 9.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter PBGetCatalogInfoBulkAsync(__A0)
#endif
    void
    PBGetCatalogInfoBulkAsync(FSCatalogBulkParam *paramBlock)
        TWOWORDINLINE(0x705C, 0xA660);

    /**
        CatalogSearch
        Iterates over catalog objects, searching for objects that match given
        search criteria.  Returns various information about matching objects.
        For now, iterator must have been created with kFSIterateSubtree option
        and the container must have been the root directory of a volume.
        ->  ioCompletion    A pointer to a completion routine
        <-  ioResult        The result code of the function
        ->  iterator        The iterator
        ->  maximumItems    The maximum number of items to return
        <-  actualItems     The actual number of items returned
        <-  containerChanged Set to true if the container's contents changed
        ->  whichInfo       The catalog information fields to return for each item
        <-  catalogInfo     An array of catalog information; one for each returned
       item
        <-  refs            An array of FSRefs; one for each returned item
        <-  specs           An array of FSSpecs; one for each returned item
        <-  names           An array of filenames; one for each returned item
        ->  searchParams    The criteria that controls the matching, including
       timeout, a bitmap controlling the fields to compare, and the (Unicode) name
       to compare. Note: The catalogInfo, refs, specs, and names are all optional
       outputs; if you don't want that particular output, set its pointer to NULL.
    */
    /**
     *  FSCatalogSearch()
     *

     *    \non_carbon_cfm   in InterfaceLib 9.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    FSCatalogSearch(FSIterator iterator, const FSSearchParams *searchCriteria,
                    ItemCount maximumObjects, ItemCount *actualObjects,
                    Boolean *containerChanged, /* can be NULL */
                    FSCatalogInfoBitmap whichInfo,
                    FSCatalogInfo *catalogInfos, /* can be NULL */
                    FSRef *refs,                 /* can be NULL */
                    FSSpec *specs,               /* can be NULL */
                    HFSUniStr255 *names) /* can be NULL */ THREEWORDINLINE(0x303C,
                                                                           0x1427,
                                                                           0xAA52);

/**
 *  PBCatalogSearchSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 9.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBCatalogSearchSync(__A0)
#endif
    OSErr
    PBCatalogSearchSync(FSCatalogBulkParam *paramBlock)
        TWOWORDINLINE(0x705D, 0xA260);

/**
 *  PBCatalogSearchAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 9.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter PBCatalogSearchAsync(__A0)
#endif
    void
    PBCatalogSearchAsync(FSCatalogBulkParam *paramBlock)
        TWOWORDINLINE(0x705D, 0xA660);

    /**
        CreateFork
        Create a named fork for a file or directory.
        ->  ioCompletion    A pointer to a completion routine
        <-  ioResult        The result code of the function
        ->  ref             The file or directory
        ->  forkNameLength  The length of the fork name (in Unicode characters)
        ->  forkName        The name of the fork to open (in Unicode)
    */
    /**
     *  FSCreateFork()
     *

     *    \non_carbon_cfm   in InterfaceLib 9.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    FSCreateFork(const FSRef *ref, UniCharCount forkNameLength,
                 const UniChar *forkName) /* can be NULL */ THREEWORDINLINE(0x303C,
                                                                            0x0636,
                                                                            0xAA52);

/**
 *  PBCreateForkSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 9.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBCreateForkSync(__A0)
#endif
    OSErr
    PBCreateForkSync(FSForkIOParam *paramBlock) TWOWORDINLINE(0x707D, 0xA260);

/**
 *  PBCreateForkAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 9.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter PBCreateForkAsync(__A0)
#endif
    void
    PBCreateForkAsync(FSForkIOParam *paramBlock) TWOWORDINLINE(0x707D, 0xA660);

    /**
        DeleteFork
        Delete a named fork of a file or directory.
        ->  ioCompletion    A pointer to a completion routine
        <-  ioResult        The result code of the function
        ->  ref             The file or directory
        ->  forkNameLength  The length of the fork name (in Unicode characters)
        ->  forkName        The name of the fork to open (in Unicode)
    */
    /**
     *  FSDeleteFork()
     *

     *    \non_carbon_cfm   in InterfaceLib 9.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    FSDeleteFork(const FSRef *ref, UniCharCount forkNameLength,
                 const UniChar *forkName) /* can be NULL */ THREEWORDINLINE(0x303C,
                                                                            0x0637,
                                                                            0xAA52);

/**
 *  PBDeleteForkSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 9.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBDeleteForkSync(__A0)
#endif
    OSErr
    PBDeleteForkSync(FSForkIOParam *paramBlock) TWOWORDINLINE(0x707E, 0xA260);

/**
 *  PBDeleteForkAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 9.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter PBDeleteForkAsync(__A0)
#endif
    void
    PBDeleteForkAsync(FSForkIOParam *paramBlock) TWOWORDINLINE(0x707E, 0xA660);

    /**
        IterateForks
        Return the names and sizes of the forks of a file or directory.
        One fork is returned per call.
        ->  ioCompletion    A pointer to a completion routine.
        <-  ioResult        The result code of the function.
        ->  ref             The file or directory containing the forks.
        <-  positionOffset  The length of the fork, in bytes.
        <-  allocationAmount The space allocated to the fork (physical length).
        <-  outForkName     The name of the fork in Unicode.
        <>  forkIterator    Maintains state between calls for a given FSRef.
                            Before the first call, set the initialize field to zero.
    */
    /**
     *  FSIterateForks()
     *

     *    \non_carbon_cfm   in InterfaceLib 9.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    FSIterateForks(
        const FSRef *ref, CatPositionRec *forkIterator,
        HFSUniStr255 *forkName, /* can be NULL */
        SInt64 *forkSize,       /* can be NULL */
        UInt64 *forkPhysicalSize) /* can be NULL */ THREEWORDINLINE(0x303C, 0x0A38,
                                                                    0xAA52);

/**
 *  PBIterateForksSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 9.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBIterateForksSync(__A0)
#endif
    OSErr
    PBIterateForksSync(FSForkIOParam *paramBlock) TWOWORDINLINE(0x707F, 0xA260);

/**
 *  PBIterateForksAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 9.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter PBIterateForksAsync(__A0)
#endif
    void
    PBIterateForksAsync(FSForkIOParam *paramBlock) TWOWORDINLINE(0x707F, 0xA660);

    /**
        OpenFork
        Open a fork for reading and/or writing.  Allows the opened fork
        to grow beyond 2GB in size.  All volumes should support data and
        resource forks.  Other named forks may be supported by some
        volumes.
        ->  ioCompletion    A pointer to a completion routine
        <-  ioResult        The result code of the function
        ->  ref             The file or directory containing the fork to open
        ->  forkNameLength  The length of the fork name (in Unicode characters)
        ->  forkName        The name of the fork to open (in Unicode)
        ->  permissions     The access (read and/or write) you want
        <-  forkRefNum      The reference number for accessing the open fork
    */
    /**
     *  FSOpenFork()
     *

     *    \non_carbon_cfm   in InterfaceLib 9.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    FSOpenFork(const FSRef *ref, UniCharCount forkNameLength,
               const UniChar *forkName, /* can be NULL */
               SInt8 permissions, SInt16 *forkRefNum)
        THREEWORDINLINE(0x303C, 0x0928, 0xAA52);

/**
 *  PBOpenForkSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 9.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBOpenForkSync(__A0)
#endif
    OSErr
    PBOpenForkSync(FSForkIOParam *paramBlock) TWOWORDINLINE(0x7079, 0xA260);

/**
 *  PBOpenForkAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 9.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter PBOpenForkAsync(__A0)
#endif
    void
    PBOpenForkAsync(FSForkIOParam *paramBlock) TWOWORDINLINE(0x7079, 0xA660);

    /**
        ReadFork
        Read data from a fork opened via OpenFork.  The first byte to read is
        indicated by a combination of positionMode and positionOffset.
        ->  ioCompletion    A pointer to a completion routine
        <-  ioResult        The result code of the function
        ->  forkRefNum      The reference number of the fork to read from
        <-  buffer          Pointer to buffer where data will be returned
        ->  requestCount    The number of bytes to read
        <-  actualCount     The number of bytes actually read
        ->  positionMode    The base location for start of read
        ->  positionOffset  The offset from base location for start of read
    */
    /**
     *  FSReadFork()
     *

     *    \non_carbon_cfm   in InterfaceLib 9.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    FSReadFork(SInt16 forkRefNum, UInt16 positionMode, SInt64 positionOffset,
               ByteCount requestCount, void *buffer,
               ByteCount *actualCount) /* can be NULL */ THREEWORDINLINE(0x303C,
                                                                         0x0A29,
                                                                         0xAA52);

/**
 *  PBReadForkSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 9.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBReadForkSync(__A0)
#endif
    OSErr
    PBReadForkSync(FSForkIOParam *paramBlock) TWOWORDINLINE(0x7051, 0xA2A8);

/**
 *  PBReadForkAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 9.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter PBReadForkAsync(__A0)
#endif
    void
    PBReadForkAsync(FSForkIOParam *paramBlock) TWOWORDINLINE(0x7051, 0xA6A8);

    /**
        WriteFork
        Write data to a fork opened via OpenFork.  The first byte to write is
        indicated by a combination of positionMode and positionOffset.
        ->  ioCompletion    A pointer to a completion routine
        <-  ioResult        The result code of the function
        ->  forkRefNum      The reference number of the fork to write to
        ->  buffer          Pointer to data to write
        ->  requestCount    The number of bytes to write
        <-  actualCount     The number of bytes actually written
        ->  positionMode    The base location for start of write
        ->  positionOffset  The offset from base location for start of write
    */
    /**
     *  FSWriteFork()
     *

     *    \non_carbon_cfm   in InterfaceLib 9.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    FSWriteFork(SInt16 forkRefNum, UInt16 positionMode, SInt64 positionOffset,
                ByteCount requestCount, const void *buffer,
                ByteCount *actualCount) /* can be NULL */ THREEWORDINLINE(0x303C,
                                                                          0x0A2A,
                                                                          0xAA52);

/**
 *  PBWriteForkSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 9.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBWriteForkSync(__A0)
#endif
    OSErr
    PBWriteForkSync(FSForkIOParam *paramBlock) TWOWORDINLINE(0x7052, 0xA2A8);

/**
 *  PBWriteForkAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 9.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter PBWriteForkAsync(__A0)
#endif
    void
    PBWriteForkAsync(FSForkIOParam *paramBlock) TWOWORDINLINE(0x7052, 0xA6A8);

    /**
        GetForkPosition
        Get the current (default) position of a fork that was
        opened via OpenFork.
        ->  ioCompletion    A pointer to a completion routine
        <-  ioResult        The result code of the function
        ->  forkRefNum      The reference number of the fork
        <-  positionOffset  The current position of the fork
    */
    /**
     *  FSGetForkPosition()
     *

     *    \non_carbon_cfm   in InterfaceLib 9.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    FSGetForkPosition(SInt16 forkRefNum, SInt64 *position)
        THREEWORDINLINE(0x303C, 0x032B, 0xAA52);

/**
 *  PBGetForkPositionSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 9.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBGetForkPositionSync(__A0)
#endif
    OSErr
    PBGetForkPositionSync(FSForkIOParam *paramBlock) TWOWORDINLINE(0x7053, 0xA260);

/**
 *  PBGetForkPositionAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 9.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter PBGetForkPositionAsync(__A0)
#endif
    void
    PBGetForkPositionAsync(FSForkIOParam *paramBlock) TWOWORDINLINE(0x7053, 0xA660);

    /**
        SetForkPosition
        Set the current (default) position of a fork that was
        opened via OpenFork.
        ->  ioCompletion    A pointer to a completion routine
        <-  ioResult        The result code of the function
        ->  forkRefNum      The reference number of the fork
        ->  positionMode    The base location for the new position
        ->  positionOffset  The offset of the new position from the base
    */
    /**
     *  FSSetForkPosition()
     *

     *    \non_carbon_cfm   in InterfaceLib 9.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    FSSetForkPosition(SInt16 forkRefNum, UInt16 positionMode, SInt64 positionOffset)
        THREEWORDINLINE(0x303C, 0x042C, 0xAA52);

/**
 *  PBSetForkPositionSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 9.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBSetForkPositionSync(__A0)
#endif
    OSErr
    PBSetForkPositionSync(FSForkIOParam *paramBlock) TWOWORDINLINE(0x7054, 0xA260);

/**
 *  PBSetForkPositionAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 9.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter PBSetForkPositionAsync(__A0)
#endif
    void
    PBSetForkPositionAsync(FSForkIOParam *paramBlock) TWOWORDINLINE(0x7054, 0xA660);

    /**
        GetForkSize
        Get the current logical size (end-of-file) of an open fork.
        ->  ioCompletion    A pointer to a completion routine
        <-  ioResult        The result code of the function
        ->  forkRefNum      The reference number of the fork
        <-  positionOffset  The logical size of the fork, in bytes
    */
    /**
     *  FSGetForkSize()
     *

     *    \non_carbon_cfm   in InterfaceLib 9.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    FSGetForkSize(SInt16 forkRefNum, SInt64 *forkSize)
        THREEWORDINLINE(0x303C, 0x032D, 0xAA52);

/**
 *  PBGetForkSizeSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 9.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBGetForkSizeSync(__A0)
#endif
    OSErr
    PBGetForkSizeSync(FSForkIOParam *paramBlock) TWOWORDINLINE(0x7055, 0xA260);

/**
 *  PBGetForkSizeAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 9.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter PBGetForkSizeAsync(__A0)
#endif
    void
    PBGetForkSizeAsync(FSForkIOParam *paramBlock) TWOWORDINLINE(0x7055, 0xA660);

    /**
        SetForkSize
        Set the logical size (end-of-file) of an open fork.  This
        may cause space to be allocated or deallocated.
        ->  ioCompletion    A pointer to a completion routine
        <-  ioResult        The result code of the function
        ->  forkRefNum      The reference number of the fork
        ->  positionMode    The base location for the new size
        ->  positionOffset  The offset of the new size from the base
    */
    /**
     *  FSSetForkSize()
     *

     *    \non_carbon_cfm   in InterfaceLib 9.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    FSSetForkSize(SInt16 forkRefNum, UInt16 positionMode, SInt64 positionOffset)
        THREEWORDINLINE(0x303C, 0x042E, 0xAA52);

/**
 *  PBSetForkSizeSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 9.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBSetForkSizeSync(__A0)
#endif
    OSErr
    PBSetForkSizeSync(FSForkIOParam *paramBlock) TWOWORDINLINE(0x7056, 0xA260);

/**
 *  PBSetForkSizeAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 9.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter PBSetForkSizeAsync(__A0)
#endif
    void
    PBSetForkSizeAsync(FSForkIOParam *paramBlock) TWOWORDINLINE(0x7056, 0xA660);

    /**
        AllocateFork
        Allocate space to an open fork.  Typically, the space to be
        allocated is beyond the current size of the fork, to reserve
        space so the file will be able to grow later.  Some volume
        formats are unable to allocate space beyond the logical size
        of the fork.
        ->  ioCompletion    A pointer to a completion routine
        <-  ioResult        The result code of the function
        ->  forkRefNum      The reference number of the fork
        ->  positionMode    The base location for start of allocation
        ->  positionOffset  The offset of the start of allocation
        ->  allocationFlags Zero or more of the following flags:
            kFSAllocContiguousMask
                    Any newly allocated space must be one contiguous piece.
            kFSAllocAllOrNothingMask
                    All of the request space must be available, or the call
                    will fail.  (If not set, the call may succeed even though
                    some of the requested space wasn't allocated.)
            kFSAllocNoRoundUpMask
                    Do not allocate additional space.  (If not set, a volume
                    may allocate additional space in order to reduce fragmentation.)
        <>  allocationAmount    The number of bytes to allocate
                                On output, the number of bytes actually added
    */
    /**
     *  FSAllocateFork()
     *

     *    \non_carbon_cfm   in InterfaceLib 9.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    FSAllocateFork(SInt16 forkRefNum, FSAllocationFlags flags, UInt16 positionMode,
                   SInt64 positionOffset, UInt64 requestCount,
                   UInt64 *actualCount) /* can be NULL */ THREEWORDINLINE(0x303C,
                                                                          0x092F,
                                                                          0xAA52);

/**
 *  PBAllocateForkSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 9.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBAllocateForkSync(__A0)
#endif
    OSErr
    PBAllocateForkSync(FSForkIOParam *paramBlock) TWOWORDINLINE(0x7057, 0xA260);

/**
 *  PBAllocateForkAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 9.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter PBAllocateForkAsync(__A0)
#endif
    void
    PBAllocateForkAsync(FSForkIOParam *paramBlock) TWOWORDINLINE(0x7057, 0xA660);

    /**
        FlushFork
        Flush a fork.  Any data written to this fork refnum is flushed to the
       device. The volume's control structures are also flushed to the device.
        ->  ioCompletion    A pointer to a completion routine
        <-  ioResult        The result code of the function
        ->  forkRefNum      The reference number of the fork to flush
    */
    /**
     *  FSFlushFork()
     *

     *    \non_carbon_cfm   in InterfaceLib 9.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    FSFlushFork(SInt16 forkRefNum) THREEWORDINLINE(0x303C, 0x0130, 0xAA52);

/**
 *  PBFlushForkSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 9.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBFlushForkSync(__A0)
#endif
    OSErr
    PBFlushForkSync(FSForkIOParam *paramBlock) TWOWORDINLINE(0x7058, 0xA260);

/**
 *  PBFlushForkAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 9.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter PBFlushForkAsync(__A0)
#endif
    void
    PBFlushForkAsync(FSForkIOParam *paramBlock) TWOWORDINLINE(0x7058, 0xA660);

    /**
        CloseFork
        Flush and close a fork.  Any data written to this fork refnum is flushed
        to the device.  The volume's control structures are also flushed to the
       device.
        ->  ioCompletion    A pointer to a completion routine
        <-  ioResult        The result code of the function
        ->  forkRefNum      The reference number of the fork to close
    */
    /**
     *  FSCloseFork()
     *

     *    \non_carbon_cfm   in InterfaceLib 9.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    FSCloseFork(SInt16 forkRefNum) THREEWORDINLINE(0x303C, 0x0131, 0xAA52);

/**
 *  PBCloseForkSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 9.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBCloseForkSync(__A0)
#endif
    OSErr
    PBCloseForkSync(FSForkIOParam *paramBlock) TWOWORDINLINE(0x7059, 0xA260);

/**
 *  PBCloseForkAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 9.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter PBCloseForkAsync(__A0)
#endif
    void
    PBCloseForkAsync(FSForkIOParam *paramBlock) TWOWORDINLINE(0x7059, 0xA660);

    /**
        GetForkCBInfo
        Return information about an open fork.
        ->  ioCompletion    A pointer to a completion routine
        <-  ioResult        The result code of the function
        <>  desiredRefNum   If non-zero on input, then get information for this
       refnum; unchanged on output.  If zero on input, iterate over all open forks
       (possibly limited to a single volume); on output, contains the fork's refnum.
        ->  volumeRefNum    Used when desiredRefNum is zero on input.  Set to 0 to
       iterate over all volumes, or set to a FSVolumeRefNum to limit iteration to
       that volume.
        <>  iterator        Used when desiredRefNum is zero on input.  Set to 0
       before iterating. Pass the iterator returned by the previous call to continue
       iterating.
        <-  actualRefNum    The refnum of the open fork.
        <-  ref             The FSRef for the file or directory that contains the
       fork.
        <-  forkInfo        Various information about the open fork.
        <-  outForkName     The name of the fork
        Note: the foundRefNum, ref, forkInfo, and fork name outputs are all
       optional; if you don't want a particular output, then set its pointer to
       NULL.  If forkName is NULL, then forkNameLength will be undefined. Note:
       Returning the forkInfo generally does not require a disk access.  Returning
       the ref or forkName may cause disk access for some volume formats.
    */
    /**
     *  FSGetForkCBInfo()
     *

     *    \non_carbon_cfm   in InterfaceLib 9.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    FSGetForkCBInfo(
        SInt16 desiredRefNum, FSVolumeRefNum volume,
        SInt16 *iterator,     /* can be NULL */
        SInt16 *actualRefNum, /* can be NULL */
        FSForkInfo *forkInfo, /* can be NULL */
        FSRef *ref,           /* can be NULL */
        HFSUniStr255 *outForkName) /* can be NULL */ THREEWORDINLINE(0x303C, 0x0C32,
                                                                     0xAA52);

/**
 *  PBGetForkCBInfoSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 9.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBGetForkCBInfoSync(__A0)
#endif
    OSErr
    PBGetForkCBInfoSync(FSForkCBInfoParam *paramBlock)
        TWOWORDINLINE(0x705A, 0xA260);

/**
 *  PBGetForkCBInfoAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 9.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter PBGetForkCBInfoAsync(__A0)
#endif
    void
    PBGetForkCBInfoAsync(FSForkCBInfoParam *paramBlock)
        TWOWORDINLINE(0x705A, 0xA660);

    /**
        GetVolumeInfo
        Returns various information about a given volume, or indexing over all
       volumes.
        ->  ioCompletion    A pointer to a completion routine
        <-  ioResult        The result code of the function
        <>  ioVRefNum       On input, the volume reference number or drive number
       whose information is to be returned (if volumeIndex is 0); same as "volume"
       input to FSGetVolumeInfo. On output, the actual volume reference number; same
       as "actualVolume" output of FSGetVolumeInfo.
        ->  volumeIndex     The index of the desired volume, or 0 to use ioVRefNum
        ->  whichInfo       Which volInfo info fields to get
        <-  volumeInfo      The returned values of Volume info fields; may be NULL
        <-  name            The Unicode name is returned here.  This pointer may be
       NULL. Note: All of the outputs are optional; if you don't want that
       particular output, just set its pointer to NULL.
    */
    /**
     *  FSGetVolumeInfo()
     *

     *    \non_carbon_cfm   in InterfaceLib 9.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    FSGetVolumeInfo(FSVolumeRefNum volume, ItemCount volumeIndex,
                    FSVolumeRefNum *actualVolume, /* can be NULL */
                    FSVolumeInfoBitmap whichInfo,
                    FSVolumeInfo *info,       /* can be NULL */
                    HFSUniStr255 *volumeName, /* can be NULL */
                    FSRef *rootDirectory) /* can be NULL */ THREEWORDINLINE(0x303C,
                                                                            0x0D33,
                                                                            0xAA52);

/**
 *  PBGetVolumeInfoSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 9.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBGetVolumeInfoSync(__A0)
#endif
    OSErr
    PBGetVolumeInfoSync(FSVolumeInfoParam *paramBlock)
        TWOWORDINLINE(0x701D, 0xA260);

/**
 *  PBGetVolumeInfoAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 9.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter PBGetVolumeInfoAsync(__A0)
#endif
    void
    PBGetVolumeInfoAsync(FSVolumeInfoParam *paramBlock)
        TWOWORDINLINE(0x701D, 0xA660);

    /**
        SetVolumeInfo
        Set information about a given volume.
        ->  ioCompletion    A pointer to a completion routine
        <-  ioResult        The result code of the function
        ->  ioVRefNum       The volume whose information is to be changed
        ->  whichInfo       Which catalog info fields to set
        ->  volumeInfo      The new values of volume info fields
        Note: Only some of the volume info fields may be set.  The settable fields
        are given by the constant kFSVolInfoSettableInfo; no other bits may be set
       in whichInfo.
    */
    /**
     *  FSSetVolumeInfo()
     *

     *    \non_carbon_cfm   in InterfaceLib 9.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    FSSetVolumeInfo(FSVolumeRefNum volume, FSVolumeInfoBitmap whichInfo,
                    const FSVolumeInfo *info)
        THREEWORDINLINE(0x303C, 0x0534, 0xAA52);

/**
 *  PBSetVolumeInfoSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 9.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBSetVolumeInfoSync(__A0)
#endif
    OSErr
    PBSetVolumeInfoSync(FSVolumeInfoParam *paramBlock)
        TWOWORDINLINE(0x701E, 0xA260);

/**
 *  PBSetVolumeInfoAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 9.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter PBSetVolumeInfoAsync(__A0)
#endif
    void
    PBSetVolumeInfoAsync(FSVolumeInfoParam *paramBlock)
        TWOWORDINLINE(0x701E, 0xA660);

    /**
        FSGetDataForkName
        Returns the constant for the name of the data fork (the empty string)
    */
    /**
     *  FSGetDataForkName()
     *

     *    \non_carbon_cfm   in InterfaceLib 9.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    FSGetDataForkName(HFSUniStr255 *dataForkName)
        THREEWORDINLINE(0x303C, 0x0218, 0xAA52);

    /**
        FSGetResourceForkName
        Returns the constant for the name of the resource fork
        (currently "RESOURCE_FORK").
    */
    /**
     *  FSGetResourceForkName()
     *

     *    \non_carbon_cfm   in InterfaceLib 9.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    FSGetResourceForkName(HFSUniStr255 *resourceForkName)
        THREEWORDINLINE(0x303C, 0x0219, 0xAA52);

    /**
     *  FSRefMakePath()
     *
     *  Summary:
     *    Converts an FSRef to a pathname.
     *
     *  Parameters:
     *
     *    ref:
     *      An FSRef to the file or directory to get the pathname for.
     *
     *    path:
     *      A pointer to a buffer which FSRefMakePath will fill with a C
     *      string representing the pathname to the file or directory
     *      specified by the ref parameter. The format of the pathname
     *      returned can be determined with the Gestalt selector
     *      gestaltFSAttr's gestaltFSUsesPOSIXPathsForConversion bit.
     *       If the gestaltFSUsesPOSIXPathsForConversion bit is clear, the
     *      pathname is a Mac OS File Manager full pathname in a C string,
     *      and file or directory names in the pathname may be mangled as
     *      returned by the File Manager.
     *      If the gestaltFSUsesPOSIXPathsForConversion bit is set, the
     *      pathname is a UTF8 encoded POSIX absolute pathname in a C
     *      string.
     *      In either case, the pathname returned can be passed back to
     *      FSRefMakePath to create an FSRef to the file or directory.
     *
     *    maxPathSize:
     *      The size of the path buffer in bytes. If the path buffer is too
     *      small for the pathname string, FSRefMakePath returns
     *      pathTooLongErr or buffersTooSmall.
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        in CarbonLib 1.1 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSStatus
    FSRefMakePath(const FSRef *ref, UInt8 *path, UInt32 maxPathSize);

    /**
     *  FSPathMakeRef()
     *
     *  Summary:
     *    Converts a pathname to an FSRef.
     *
     *  Parameters:
     *
     *    path:
     *      A pointer to a C String that is the pathname. The format of the
     *      pathname you must supply can be determined with the Gestalt
     *      selector gestaltFSAttr's gestaltFSUsesPOSIXPathsForConversion
     *      bit.
     *      If the gestaltFSUsesPOSIXPathsForConversion bit is clear, the
     *      pathname must be a Mac OS File Manager full pathname in a C
     *      string.
     *      If the gestaltFSUsesPOSIXPathsForConversion bit is set, the
     *      pathname must be a UTF8 encoded POSIX absolute pathname in a C
     *      string.
     *      In either case, the pathname returned by FSRefMakePath can be
     *      passed to FSPathMakeRef.
     *
     *    ref:
     *      A pointer to an FSRef to fill in.
     *
     *    isDirectory:
     *      An optional pointer to a Boolean that will be filled in to
     *      indicate if the specified path is a directory (vs. a file).
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        in CarbonLib 1.1 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSStatus
    FSPathMakeRef(const UInt8 *path, FSRef *ref,
                  Boolean *isDirectory); /* can be NULL */

    /**
     *  FNMessage
     *
     *  Discussion:
     *    Messages broadcast about a directory.  If system clients (such as
     *    the Finder) are interested in changes to a directory, they will
     *    receive notifications when application code broadcasts change
     *    messages about that directory.
     */
    typedef UInt32 FNMessage;
    enum
    {
      kFNDirectoryModifiedMessage = 1
    };

    /**
     *  FNNotify()
     *
     *  Summary:
     *    Broadcasts notification of changes to the specified directory.
     *
     *  Parameters:
     *
     *    ref:
     *      The directory for which to broadcast the notification
     *
     *    message:
     *      An indication of what happened to the target directory
     *
     *    flags:
     *      Options about delivery of the notification (specify kNilOptions
     *      for default behaviour)
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        in CarbonLib 1.5 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSStatus
    FNNotify(const FSRef *ref, FNMessage message, OptionBits flags);

    /**
     *  FNNotifyByPath()
     *
     *  Summary:
     *    Broadcasts notification of changes to the specified directory.
     *
     *  Parameters:
     *
     *    path:
     *      Path to the directory for which to broadcast the notification
     *
     *    message:
     *      An indication of what happened to the target directory
     *
     *    flags:
     *      Options about delivery of the notification (specify kNilOptions
     *      for default behaviour)
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        in CarbonLib 1.5 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSStatus
    FNNotifyByPath(const UInt8 *path, FNMessage message, OptionBits flags);

    /**
     *  FNNotifyAll()
     *
     *  Discussion:
     *    Broadcasts notification of changes to the filesystem (should only
     *    be used by installers or programs which make lots of changes and
     *    only send one broadcast).
     *
     *  Parameters:
     *
     *    message:
     *      An indication of what happened
     *
     *    flags:
     *      Options about delivery of the notification (specify kNilOptions
     *      for default behaviour)
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        in CarbonLib 1.5 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSStatus
    FNNotifyAll(FNMessage message, OptionBits flags);

    /**
     *  FNSubscriptionRef
     *
     *  Discussion:
     *    A token associated with a notification subscription.  The
     *    subscriber gets one back when they subscribe to notifications for
     *    a particular directory, and they supply it when the unsubscribe.
     *    It is also delivered along with the notifications for that
     *    subscription.
     */
    typedef struct OpaqueFNSubscriptionRef *FNSubscriptionRef;

    /**
     *  Discussion:
     *    Options that can be specified at subscription time.
     */
    enum
    {

      /**
       * Specify this option if you do not want to receive notifications on
       * this subscription when FNNotifyAll is called; by default any
       * subscription is also implicitly a subscription to wildcard
       * notifications
       */
      kFNNoImplicitAllSubscription = (1 << 0)
    };

    /**
     *  FNSubscriptionProcPtr
     *
     *  Discussion:
     *    Callback delivered for directory notifications.
     *
     *  Parameters:
     *
     *    message:
     *      An indication of what happened
     *
     *    flags:
     *      Options about delivery of the notification (typically
     *      kNilOptions)
     *
     *    refcon:
     *      User reference supplied with subscription
     *
     *    subscription:
     *      Subscription corresponding to this notification
     */
    typedef CALLBACK_API_C(void,
                           FNSubscriptionProcPtr)(FNMessage message,
                                                  OptionBits flags, void *refcon,
                                                  FNSubscriptionRef subscription);
    typedef TVECTOR_UPP_TYPE(FNSubscriptionProcPtr) FNSubscriptionUPP;
    /**
     *  NewFNSubscriptionUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib on Mac OS X
     *    \mac_os_x         in version 10.0 and later
     */
    FNSubscriptionUPP
    NewFNSubscriptionUPP(FNSubscriptionProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
    enum
    {
      uppFNSubscriptionProcInfo = 0x00003FC1
    }; /* no_return_value Func(4_bytes, 4_bytes, 4_bytes, 4_bytes) */
#ifdef __cplusplus
    inline FNSubscriptionUPP
    NewFNSubscriptionUPP(FNSubscriptionProcPtr userRoutine)
    {
      return userRoutine;
    }
#else
#define NewFNSubscriptionUPP(userRoutine) (userRoutine)
#endif
#endif

    /**
     *  DisposeFNSubscriptionUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib on Mac OS X
     *    \mac_os_x         in version 10.0 and later
     */
    void
    DisposeFNSubscriptionUPP(FNSubscriptionUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline void DisposeFNSubscriptionUPP(FNSubscriptionUPP) {}
#else
#define DisposeFNSubscriptionUPP(userUPP)
#endif
#endif

    /**
     *  InvokeFNSubscriptionUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib on Mac OS X
     *    \mac_os_x         in version 10.0 and later
     */
    void
    InvokeFNSubscriptionUPP(FNMessage message, OptionBits flags, void *refcon,
                            FNSubscriptionRef subscription,
                            FNSubscriptionUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline void InvokeFNSubscriptionUPP(FNMessage message, OptionBits flags,
                                        void *refcon,
                                        FNSubscriptionRef subscription,
                                        FNSubscriptionUPP userUPP)
    {
      (*userUPP)(message, flags, refcon, subscription);
    }
#else
#define InvokeFNSubscriptionUPP(message, flags, refcon, subscription, userUPP) \
  (*userUPP)(message, flags, refcon, subscription)
#endif
#endif

    /**
     *  FNSubscribe()
     *
     *  Summary:
     *    Subscribe to change notifications for the specified directory.
     *
     *  Parameters:
     *
     *    directoryRef:
     *      Directory for which the caller wants notifications
     *
     *    callback:
     *      Function to call back when a notification arrives
     *
     *    refcon:
     *      User state carried with the subscription
     *
     *    flags:
     *      Options for future use (specify kNilOptions, or one of the
     *      FNSubscriptionOptions)
     *
     *    subscription:
     *      Subscription token for subsequent query or unsubscription
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available in CarbonLib 1.x, is available on Mac OS
     X version 10.1 and later
     *    \mac_os_x         in version 10.1 and later
     */
    OSStatus
    FNSubscribe(const FSRef *directoryRef, FNSubscriptionUPP callback, void *refcon,
                OptionBits flags, FNSubscriptionRef *subscription);

    /**
     *  FNSubscribeByPath()
     *
     *  Summary:
     *    Subscribe to change notifications for the specified directory.
     *
     *  Parameters:
     *
     *    directoryPath:
     *      Directory for which the caller wants notifications
     *
     *    callback:
     *      Function to call back when a notification arrives
     *
     *    refcon:
     *      User state carried with the subscription
     *
     *    flags:
     *      Options for future use (specify kNilOptions, or one of the
     *      FNSubscriptionOptions)
     *
     *    subscription:
     *      Subscription token for subsequent query or unsubscription
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available in CarbonLib 1.x, is available on Mac OS
     X version 10.1 and later
     *    \mac_os_x         in version 10.1 and later
     */
    OSStatus
    FNSubscribeByPath(const UInt8 *directoryPath, FNSubscriptionUPP callback,
                      void *refcon, OptionBits flags,
                      FNSubscriptionRef *subscription);

    /**
     *  FNUnsubscribe()
     *
     *  Summary:
     *    Release a subscription which is no longer needed.
     *
     *  Parameters:
     *
     *    subscription:
     *      Subscription previously returned from FNSubscribe or
     *      FNSubscribeForPath
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available in CarbonLib 1.x, is available on Mac OS
     X version 10.1 and later
     *    \mac_os_x         in version 10.1 and later
     */
    OSStatus
    FNUnsubscribe(FNSubscriptionRef subscription);

    /**
     *  FNGetDirectoryForSubscription()
     *
     *  Summary:
     *    Fetch the directory for which this subscription was originally
     *    entered. There is no path variant because paths are fragile, and
     *    the path may have changed.  If the caller does not care about
     *    this subtlety, she can call FSRefMakePath to get a path from the
     *    returned ref.
     *
     *  Parameters:
     *
     *    subscription:
     *      Subscription previously returned from FNSubscribe or
     *      FNSubscribeForPath
     *
     *    ref:
     *      Directory for which this subscription was created
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available in CarbonLib 1.x, is available on Mac OS
     X version 10.1 and later
     *    \mac_os_x         in version 10.1 and later
     */
    OSStatus
    FNGetDirectoryForSubscription(FNSubscriptionRef subscription, FSRef *ref);

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

#endif /* __FILES__ */
*/< 0)
};

/**
 *  FNSubscriptionProcPtr
 *
 *  Discussion:
 *    Callback delivered for directory notifications.
 *
 *  Parameters:
 *
 *    message:
 *      An indication of what happened
 *
 *    flags:
 *      Options about delivery of the notification (typically
 *      kNilOptions)
 *
 *    refcon:
 *      User reference supplied with subscription
 *
 *    subscription:
 *      Subscription corresponding to this notification
 */
typedef CALLBACK_API_C(void,
                       FNSubscriptionProcPtr)(FNMessage message,
                                              OptionBits flags, void *refcon,
                                              FNSubscriptionRef subscription);
typedef TVECTOR_UPP_TYPE(FNSubscriptionProcPtr) FNSubscriptionUPP;
/**
 *  NewFNSubscriptionUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        in CarbonLib on Mac OS X
 *    \mac_os_x         in version 10.0 and later
 */
FNSubscriptionUPP
NewFNSubscriptionUPP(FNSubscriptionProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
enum
{
  uppFNSubscriptionProcInfo = 0x00003FC1
}; /* no_return_value Func(4_bytes, 4_bytes, 4_bytes, 4_bytes) */
#ifdef __cplusplus
inline FNSubscriptionUPP
NewFNSubscriptionUPP(FNSubscriptionProcPtr userRoutine)
{
  return userRoutine;
}
#else
#define NewFNSubscriptionUPP(userRoutine) (userRoutine)
#endif
#endif

/**
 *  DisposeFNSubscriptionUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        in CarbonLib on Mac OS X
 *    \mac_os_x         in version 10.0 and later
 */
void DisposeFNSubscriptionUPP(FNSubscriptionUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
inline void DisposeFNSubscriptionUPP(FNSubscriptionUPP) {}
#else
#define DisposeFNSubscriptionUPP(userUPP)
#endif
#endif

/**
 *  InvokeFNSubscriptionUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        in CarbonLib on Mac OS X
 *    \mac_os_x         in version 10.0 and later
 */
void InvokeFNSubscriptionUPP(FNMessage message, OptionBits flags, void *refcon,
                             FNSubscriptionRef subscription,
                             FNSubscriptionUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
inline void InvokeFNSubscriptionUPP(FNMessage message, OptionBits flags,
                                    void *refcon,
                                    FNSubscriptionRef subscription,
                                    FNSubscriptionUPP userUPP)
{
  (*userUPP)(message, flags, refcon, subscription);
}
#else
#define InvokeFNSubscriptionUPP(message, flags, refcon, subscription, userUPP) \
  (*userUPP)(message, flags, refcon, subscription)
#endif
#endif

/**
 *  FNSubscribe()
 *
 *  Summary:
 *    Subscribe to change notifications for the specified directory.
 *
 *  Parameters:
 *
 *    directoryRef:
 *      Directory for which the caller wants notifications
 *
 *    callback:
 *      Function to call back when a notification arrives
 *
 *    refcon:
 *      User state carried with the subscription
 *
 *    flags:
 *      Options for future use (specify kNilOptions, or one of the
 *      FNSubscriptionOptions)
 *
 *    subscription:
 *      Subscription token for subsequent query or unsubscription
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available in CarbonLib 1.x, is available on Mac OS
 X version 10.1 and later
 *    \mac_os_x         in version 10.1 and later
 */
OSStatus
FNSubscribe(const FSRef *directoryRef, FNSubscriptionUPP callback, void *refcon,
            OptionBits flags, FNSubscriptionRef *subscription);

/**
 *  FNSubscribeByPath()
 *
 *  Summary:
 *    Subscribe to change notifications for the specified directory.
 *
 *  Parameters:
 *
 *    directoryPath:
 *      Directory for which the caller wants notifications
 *
 *    callback:
 *      Function to call back when a notification arrives
 *
 *    refcon:
 *      User state carried with the subscription
 *
 *    flags:
 *      Options for future use (specify kNilOptions, or one of the
 *      FNSubscriptionOptions)
 *
 *    subscription:
 *      Subscription token for subsequent query or unsubscription
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available in CarbonLib 1.x, is available on Mac OS
 X version 10.1 and later
 *    \mac_os_x         in version 10.1 and later
 */
OSStatus
FNSubscribeByPath(const UInt8 *directoryPath, FNSubscriptionUPP callback,
                  void *refcon, OptionBits flags,
                  FNSubscriptionRef *subscription);

/**
 *  FNUnsubscribe()
 *
 *  Summary:
 *    Release a subscription which is no longer needed.
 *
 *  Parameters:
 *
 *    subscription:
 *      Subscription previously returned from FNSubscribe or
 *      FNSubscribeForPath
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available in CarbonLib 1.x, is available on Mac OS
 X version 10.1 and later
 *    \mac_os_x         in version 10.1 and later
 */
OSStatus
FNUnsubscribe(FNSubscriptionRef subscription);

/**
 *  FNGetDirectoryForSubscription()
 *
 *  Summary:
 *    Fetch the directory for which this subscription was originally
 *    entered. There is no path variant because paths are fragile, and
 *    the path may have changed.  If the caller does not care about
 *    this subtlety, she can call FSRefMakePath to get a path from the
 *    returned ref.
 *
 *  Parameters:
 *
 *    subscription:
 *      Subscription previously returned from FNSubscribe or
 *      FNSubscribeForPath
 *
 *    ref:
 *      Directory for which this subscription was created
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available in CarbonLib 1.x, is available on Mac OS
 X version 10.1 and later
 *    \mac_os_x         in version 10.1 and later
 */
OSStatus
FNGetDirectoryForSubscription(FNSubscriptionRef subscription, FSRef *ref);

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

#endif /* __FILES__ */
* /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ = reset
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

#endif /* __FILES__ */
* /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ reset
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

#endif /* __FILES__ */
* /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ ma import reset
#endif

#ifdef __cplusplus
}
#endif

#endif /* __FILES__ */
* /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ ort reset
#endif

#ifdef __cplusplus
}
#endif

#endif /* __FILES__ */
* /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ ma import reset
#endif

#ifdef __cplusplus
}
#endif

#endif /* __FILES__ */
* /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ /*/*/ ort reset
#endif

#ifdef __cplusplus
}
#endif

#endif /* __FILES__ */
* /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ ma import reset
#endif

#ifdef __cplusplus
}
#endif

#endif /* __FILES__ */
* /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ / ort reset
#endif

#ifdef __cplusplus
}
#endif

#endif /* __FILES__ */
* /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ ma import reset
#endif

#ifdef __cplusplus
}
#endif

#endif                                                                                                                                                                                                                                           /* __FILES__ */
* /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*/*/ * /*//*/ * /*/*/