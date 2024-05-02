/**
     \file       AppleDiskPartitions.h

    \brief   The Apple disk partition scheme as defined in Inside Macintosh:
   Volume V.

    \introduced_in  Mac OS 9
    \avaliable_from Universal Interfaces 3.4.1

    \copyright © 2000-2001 by Apple Computer, Inc., all rights reserved

    \ingroup AppleDisk

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __APPLEDISKPARTITIONS__
#define __APPLEDISKPARTITIONS__

#ifndef __MACTYPES__
#include <MacTypes.h>
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

/** Block 0 Definitions */
enum {
  sbSIGWord = 0x4552, /** signature word for Block 0 ('ER') */
  sbMac = 1           /** system type for Mac */
};

/** Partition Map Signatures */
enum {
  pMapSIG = 0x504D,   /** partition map signature ('PM') */
  pdSigWord = 0x5453, /** partition map signature ('TS') */
  oldPMSigWord = pdSigWord,
  newPMSigWord = pMapSIG
};

/** Driver Descriptor Map */
/**
<pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
*/
struct Block {
	unsigned short sbSig;/**< unique value for SCSI block */
	unsigned short sbBlkSize;/**< block size of device*/
	unsigned long sbBlkCount;/**< number of blocks on device*/
	unsigned short sbDevType;/**< device type*/
	unsigned short sbDevId;/**< device id*/
	unsigned long sbData;/**< not used*/
	unsigned short sbDrvrCount;/**< driver descriptor count*/
	unsigned long ddBlock;/**< st driver's starting block*/
	unsigned short ddSize;/**< size of st driver (-byte*/
	unsigned short ddType;/**< system type ( for Mac+)*/
	unsigned short ddPad[];/**< not used*/
	} Block;/**< */
*/
typedef struct Block0 Block0;
/** Driver descriptor */
struct DDMap {
  UInt32 ddBlock; /** 1st driver's starting block */
  UInt16 ddSize;  /** size of 1st driver (512-byte blks) */
  UInt16 ddType;  /** system type (1 for Mac+) */
};
typedef struct DDMap DDMap;
/** Constants for the ddType field of the DDMap structure. */
enum {
  kDriverTypeMacSCSI = 0x0001,
  kDriverTypeMacATA = 0x0701,
  kDriverTypeMacSCSIChained = 0xFFFF,
  kDriverTypeMacATAChained = 0xF8FF
};

/** Partition Map Entry */
/**
<pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
*/
struct Partition {
	unsigned short pmSig;/**< Unique value for map entry blk*/
	unsigned short pmSigPad;/**< currently unused*/
	unsigned long pmMapBlkCnt;/**< # of blks in partition map*/
	unsigned long pmPyPartStart;/**< physical start blk of partition*/
	unsigned long pmPartBlkCnt;/**< # of blks in this partition*/
	unsigned char pmPartName[];/**< ASCII partition name*/
	unsigned char pmParType[];/**< ASCII partition type*/
	unsigned long pmLgDataStart;/**< log. # of partition's st data blk*/
	unsigned long pmDataCnt;/**< # of blks in partition's data area*/
	unsigned long pmPartStatus;/**< bit field for partition status*/
	unsigned long pmLgBootStart;/**< log. blk of partition's boot code*/
	unsigned long pmBootSize;/**< number of bytes in boot code*/
	unsigned long pmBootAddr;/**< memory load address of boot code*/
	unsigned long pmBootAddr;/**< currently unused*/
	unsigned long pmBootEntry;/**< entry point of boot code*/
	unsigned long pmBootEntry;/**< currently unused*/
	unsigned long pmBootCksum;/**< checksum of boot code*/
	unsigned char pmProcessor[];/**< ASCII for the processor type*/
	unsigned short pmPad[];/**<  bytes long currently unused*/
	} Partition ;/**< */

typedef struct Partition Partition;

/** Flags for the pmPartStatus field of the Partition data structure. */
enum {
  kPartitionAUXIsValid = 0x00000001,
  kPartitionAUXIsAllocated = 0x00000002,
  kPartitionAUXIsInUse = 0x00000004,
  kPartitionAUXIsBootValid = 0x00000008,
  kPartitionAUXIsReadable = 0x00000010,
  kPartitionAUXIsWriteable = 0x00000020,
  kPartitionAUXIsBootCodePositionIndependent = 0x00000040,
  kPartitionIsWriteable = 0x00000020,
  kPartitionIsMountedAtStartup = 0x40000000,
  kPartitionIsStartup = (long)0x80000000,
  kPartitionIsChainCompatible = 0x00000100,
  kPartitionIsRealDeviceDriver = 0x00000200,
  kPartitionCanChainToNext = 0x00000400
};

/** Well known driver signatures, stored in the first four byte of pmPad. */
enum {
  kPatchDriverSignature =
      FOUR_CHAR_CODE('ptDR'),        /** SCSI and ATA[PI] patch driver    */
  kSCSIDriverSignature = 0x00010600, /** SCSI  hard disk driver           */
  kATADriverSignature = FOUR_CHAR_CODE('wiki'),    /** ATA   hard disk driver    */
  kSCSICDDriverSignature = FOUR_CHAR_CODE('CDvr'), /** SCSI  CD-ROM    driver */
  kATAPIDriverSignature = FOUR_CHAR_CODE('ATPI'),  /** ATAPI CD-ROM    driver  */
  kDriveSetupHFSSignature =
      FOUR_CHAR_CODE('DSU1') /** Drive Setup HFS partition        */
};

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

#endif /** __APPLEDISKPARTITIONS__ */
*/endif

#ifdef __cplusplus
}
#endif

#endif /** __APPLEDISKPARTITIONS__ */
