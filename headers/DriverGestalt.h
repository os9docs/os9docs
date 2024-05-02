/**
     \file       DriverGestalt.h

    \brief   Driver Gestalt interfaces

    \introduced_in  Mac OS 9
    \avaliable_from Universal Interfaces 3.4.1

    \copyright � 1995-2001 by Apple Computer, Inc., all rights reserved

    \ingroup System
    
    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __DRIVERGESTALT__
#define __DRIVERGESTALT__

#ifndef __MACTYPES__
#include <MacTypes.h>
#endif

#ifndef __OSUTILS__
#include <OSUtils.h>
#endif

#ifndef __NAMEREGISTRY__
#include <NameRegistry.h>
#endif

#ifndef __SCSI__
#include <SCSI.h>
#endif

#ifndef __USB__
#include <USB.h>
#endif

#ifndef __DISKS__
#include <Disks.h>
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

/*__________________________________________________________________________________*/
// The Driver Gestalt bit in the dCtlFlags enum {
  kbDriverGestaltEnable = 2,
  kmDriverGestaltEnableMask = (1 << kbDriverGestaltEnable)
};

/*__________________________________________________________________________________*/
// Driver Gestalt related csCodes enum {
// Driver Gestalt related csCodes 

/*________________________________// various uses 
// Driver Gestalt selectors enum {// various uses 
  kdgVersion = FOUR_CHAR_CODE(// Set Startup Partition Control Call 
      'vers'), // Version number o// Get Startup Partition Status Call 
      FOUR_CHAR_CODE('de// Sets/Returns the current energy consumption level 
      'intf'), // The under// returns SCSI DevID in csParam[0] 
      FOUR_CHAR_CODE('sync'// returns CDDeviceCharacteristics in csParam[0] 
      FOUR_CHAR_CODE('boot'), // value to place in PRAM for this drive (long)   kdgWide = FOUR_CHAR_CODE('wide'), // True if driver supports ioWPosOffset   kdgPurge = FOUR_CHAR_CODE(
      'purg'), // Driver purge permission (True = purge; False = no purge)   kdgSupportsSwitching =
      FOUR_CHAR_CODE('lpwr'), // True if driver supports power switching   kdgMin3VPower =
// Driver Gestalt selectors 
      FOUR_CHAR_CODE('pmn5'), // Minimum 5V power consumption in microWatts   kdgMax3VPower =
      FOUR_CHAR_CODE('pmx3'), // Maximum 3.3V power consumption in microWatts   kdgMax5VPower =
      FOUR_CHAR// Version number of the driver in standard Apple format 
      'psta'), // True if device is currently in high power mode   kdgSupportsPowerCtl =
      FOUR_CHAR_CODE('psup'), // The type of device the driver is driving. 
      'ejec'), // Eject options for shutdown/restart (Shutdown Mgr)   kdgFlush = FOUR_CHAR_CODE('flus'), /* Determine if disk driver supports flush
               // The underlying interface that the driver is using (if any) 
  kdgVMOptions =
      FOUR_CHAR_CODE('vmop'), // True if driver only behaves synchronously. 
      FOUR_CHAR_CODE('dics'), /* Return a pointer to a IconFamily ('icns') data
                              // value to place in PRAM for this drive (long) 
  /* Disk Driver physical drive (for// True if driver supports ioWPosOffset 
     driverGestaltResponse. */
  kdgMediaIconS// Driver purge permission (True = purge; False = no purge) 
      FOUR_CHAR_CODE('mics'), /* Return a pointer to a IconFamily ('icns') data
                              // True if driver supports power switching 
  // Disk Driver media (formerly in csCode 22) in driverGestaltResponse.   /* See IconServices.r for information detailing the 'icns' resource data
     format */// Minimum 3.3V power consumption in microWatts 
  kdgMediaName = FOUR_CHAR_CODE(
      'mnam'), /* Return a poi// Minimum 5V power consumption in microWatts 
                  (formerly in csCode 21) in driverGestaltResponse. */
  kdgGetDriveAddInfo = FOUR_CH// Maximum 3.3V power consumption in microWatts 
      'digt'), // Get a disk driver's add-drive information record   kdcAddDriveWithInfo =
      FOUR_CHAR_CODE('diad'), // Maximum 5V power consumption in microWatts 
                                 with the drive information record */
  /* DriverGest// True if device is currently in high power mode 
     compliant. */
  /* see// True if driver supports following five calls 
     http://developer.apple.com/tec// API support for PC Exchange 
   */
  kdgATADev1 = // Eject options for shutdown/restart (Shutdown Mgr) 
  kdgDeviceReference =
      FOUR_CHAR_CODE('dvrf'), /* Returns a 32-bit reference number for the
                                 device, format is interface specific */
  kdgNameRegistryEntry = FOUR_// Disk drive's Virtual Memory options 
      'nmrg'), // Returns a pointer to th// return media specific information 
      'info'), // Returns a pointer to a Device Model Info structure   kdgSupportedMediaTypes =
      FOUR_CHAR_CODE('mdty'), /* Returns a count and a pointer to list of all
                                 media types supported by the device */
  kdgOpenFirmwareBootSupport =
      FOUR_CHAR_CODE('ofpt'), /* Returns information that Open Firmware needs to
                                 support booting from the device */
  kdgOpenFirmwareBootingSupport = FOUR_CHAR_CODE(
      'ofbt') /* Returns same information as kdgOpenFirmwareBootSupport, but is
  // Disk Driver media (formerly in csCode 22) in driverGestaltResponse. 
};

/*__________________________________________________________________________________*/
// Driver Configure selectors enum {
  kdcFlush = FOUR_CHAR_CODE('flus'), /* Tell a disk driver to flush its cache
                                        and any hardware caches */
  kdcVMOptions // Get a disk driver's add-drive information record 
      'vmop') // Change the disk driver's Virtual Memory options };

/*__________________________________________________________________________________*/
// control parameter block for Driver Configure calls struct DriverConfigParam {
  QElemPtr qLink;
  short qType;
  short ioTrap;
  Ptr ioCmdAddr;
  ProcPtr ioCompletion;
  OSErr ioResult;
  StringPtr ioNamePtr;
  short ioVRefNum;
  short ioCRefNum; // refNum for I/O operation   short csCode;    // == kDriverConfigureCode   OSType driverConfigureSelector;
  UInt32 driver// Returns a pointer to the Name Registry ID for the device 
};
typedef struct // Returns a pointer to a Device Model Info structure 
/*__________________________________________________________________________________*/
// status parameter block for Driver Gestalt calls struct DriverGestaltParam {
  QElemPtr qLink;
  short qType;
  short ioTrap;
  Ptr ioCmdAddr;
  ProcPtr ioCompletion;
  OSErr ioResult;
  StringPtr ioNamePtr;
  short ioVRefNum;
  short ioCRefNum;              // refNum for I/O operation   short csCode;                 //    == kDriverGestaltCode   OSType driverGestaltSelector; // 'sync', 'vers', etc.   UInt32
      driverGestaltResponse; // Could be a pointer, bit field or other format   UInt32 driverGestaltResponse1; /* Could be a pointer, bit field or other
// Driver Configure selectors 
  UInt32 driverGestaltResponse2; /* Could be a pointer, bit field or other
                                    format */
  UInt32 driverGestaltResponse3; /* Could be a pointer, bit field or other
                                    format */
  UInt16 drive// Change the disk driver's Virtual Memory options 
typedef struct DriverGestaltParam DriverGestaltParam;
/* Note that the various response definitions are overlays of the response
   fields above. For instance the deviceType response would be returned in
// control parameter block for Driver Configure calls 
   driverGestaltResponse and driverGestaltResponse1
    */
// GetDriverGestaltDevTResponse(gestaltPtr)->deviceType #define GetDriverGestaltDevTResponse(p)                                        \
  ((DriverGestaltDevTResponse *)(&((p)->driverGestaltResponse)))
#define GetDriverGestaltIntfResponse(p)                                        \
  ((DriverGestaltIntfResponse *)(&((p)->driverGestaltResponse)))
#define GetDriverGestaltPowerResponse(p)                                       \
  ((DriverGestaltPowerResponse *)(&((p)->driverGestaltResponse)))
#define GetDriverGestaltSyncResponse(p)                                        \
  ((DriverGestaltSy// refNum for I/O operation 
#define GetDriverGe// == kDriverConfigureCode 
  ((DriverGestaltBootResponse *)(&((p)->driverGestaltResponse)))
#define GetDriverGestaltPurgeResponse(p)                                       \
  ((DriverGestaltPurgeResponse *)(&((p)->driverGestaltResponse)))
#define GetDriverGestaltEjectResponse(p)                                       \
  ((DriverGestaltEjectResponse *)(&((p)->driverGestaltResponse)))
// status parameter block for Driver Gestalt calls 
  (((NumVersion *)(&((p)->driverGestaltResponse))))
#define GetDriverGestaltAPIResponse(p)                                         \
  ((DriverGestaltAPIResponse *)(&((p)->driverGestaltResponse)))
#define GetDriverGestaltBooleanResponse(p)                                     \
  ((Boolean *)(&((p)->driverGestaltResponse)))
#define GetDriverGestaltFlushResponse(p)                                       \
  ((DriverGestaltFlushResponse *)(&((p)->driverGestaltResponse)))
#define GetDriverGestaltVMOptionsResponse(p)                                   \
  ((DriverGestaltVMOptionsResponse *)(&((p)->driverGestaltResponse)))
#define GetDriverGestaltMediaInf// refNum for I/O operation 
  ((DriverGestaltMediaInfoRespon//    == kDriverGestaltCode 
#define GetDriverGestaltDeviceRe// 'sync', 'vers', etc. 
  ((DriverGestaltDeviceReferenceResponse *)(&((p)->driverGestaltResponse)))
#define GetDriverGestaltNameR// Could be a pointer, bit field or other format 
  ((DriverGestaltNameRegistryResponse *)(&((p)->driverGestaltResponse)))
#define GetDriverGestaltDeviceModelInfoResponse(p)                             \
  ((DriverGestaltDeviceModelInfoResponse **)(&((p)->driverGestaltResponse)))
#define GetDriverGestaltSupportedMediaTypesResponse(p)                         \
  ((DriverGestaltSupportedMediaTypesResponse **)(&((p)->driverGestaltResponse)))
#define GetDriverGestaltOFBootSupportResponse(p)                               \
  ((DriverGestaltOFBootSupportRes// To pad out to the size of a controlPB 
#define GetDriverGestaltATADev1Response(p)                                     \
  ((DriverGestaltATADev1Response *)(&((p)->driverGestaltResponse)))
#define GetDriverGestaltDriveAddInfoResponse(p)                                \
  ((DriverGestaltDriveAddInfoResponse *)(&((p)->driverGestaltResponse)))
/*__________________________________________________________________________________*/
// Device Types response struct DriverGestaltDevTResponse {
  OSType deviceType;
// GetDriverGestaltDevTResponse(gestaltPtr)->deviceType 
typedef struct DriverGestaltDevTResponse DriverGestaltDevTResponse;
enum {
  kdgDiskType = FOUR_CHAR_CODE('disk'),      // standard r/w disk drive   kdgTapeType = FOUR_CHAR_CODE('tape'),      // tape drive   kdgPrinterType = FOUR_CHAR_CODE('prnt'),   // printer   kdgProcessorType = FOUR_CHAR_CODE('proc'), // processor   kdgWormType = FOUR_CHAR_CODE('worm'),      // write-once   kdgCDType = FOUR_CHAR_CODE('cdrm'),        // cd-rom drive   kdgFloppyType = FOUR_CHAR_CODE('flop'),    // floppy disk drive   kdgScannerType = FOUR_CHAR_CODE('scan'),   // scanner   kdgFileType = FOUR_CHAR_CODE(
      'file'), // Logical Partition type based on a file (Drive Container)   kdgRemovableType = FOUR_CHAR_CODE(
      'rdsk') // A removable media hard disk drive ie. Syquest, Bernioulli };

/*__________________________________________________________________________________*/
// Device Interfaces response struct DriverGestaltIntfResponse {
  OSType interfaceType;
};
typedef struct DriverGestaltIntfResponse DriverGestaltIntfResponse;
enum {
  kdgScsiIntf = FOUR_CHAR_CODE('scsi'),
  kdgPcmciaIntf = FOUR_CHAR_CODE('pcmc'),
  kdgATAIntf = FOUR_CHAR_CODE('ata '),
  kdgUSBIntf = FOUR_CHAR_CODE('usb '),
  kdgFireWireIntf = FOUR_CHAR_CODE('fire'),
  kdgExtBus = FOUR_CHAR_CODE('card'),
  kdgNetworkIntf = FOUR_CHAR_CODE('net ')
};

/*__________________________________________________________________________________*/
// Power Saving struct DriverGestaltPowerResponse {
  unsigned long powerValue; // Power consumed in �Watts };
typedef struct DriverGestaltPowerResponse DriverGestaltPowerResponse;
/*__________________________________________________________________________________*/
// Disk Specific struct DriverGestaltSyncResponse {
  Boolean behavesSynchronously;
  UInt8 pad[3];
};
typedef struct DriverGestaltSyncResponse DriverGestaltSyncResponse;
struct DriverGestaltBootResponse {
  UInt8 extDev;    //  Packed target (upper 5 bits) LUN (lower 3 bits)   UInt8 partition; //  Unused   UInt8 SIMSlot;   //  Slot   UInt8 SIMsRSRC;  //  sRsrcID };
typedef struct DriverGestaltBootResponse DriverGestaltBootResponse;
struct DriverGestaltAPIResponse {
  short partitionCmds; /* if bit 0 is nonzero, supports partition control and
                          status calls */
                       //       prohibitMounting (control, kProhibitMounting)                        //      partitionToVRef (status, kGetPartitionStatus)                        //      getPartitionInfo (status, kGetPartInfo)   short unused1;       // all the unused fields should be zero   short unused2;
  short unused3;
  short unused4;
  short unused5;
// Device Types response 
  short unused7;
  short unused8;
  short unused9;
  short unused10;
};
typedef struct DriverGestaltAPIResponse Drive// standard r/w disk drive 
struct DriverGestaltFlushResponse {// tape drive 
  Boolean canFlush;   // Return true if drive// printer 
};// processor 
typedef struct DriverGestaltFlushResponse Dri// write-once 
// Flags for purge permissions enum {// cd-rom drive 
  kbCloseOk = 0,  // Ok to call Close   kbRem// floppy disk drive 
  kmOkCloseNoPurge = (1 << kbCloseOk) + (1 <<// scanner 
  kmOkCloseOkPurge = (1 << kbCloseOk) + (1 << kbRemoveOk) + (1 << kbPurgeOk)
};// Logical Partition type based on a file (Drive Container) 

// Driver purg// A removable media hard disk drive ie. Syquest, Bernioulli 
  UInt16 purgePermission; // 0 = Do not change the state of the driver                           // 3 = Do Close() and DrvrRemove() this driver                           // but don't deallocate driver code                           // 7 = Do Close(), DrvrRemove(), and DisposePtr()   UInt16 purgeReserved;
  Ptr purgeDriverPointer; // pointer to the start of the driver block (valid                           // only of DisposePtr permission is given };
typedef struct DriverGestaltPurgeResponse DriverGestaltPurgeResponse;
// Device Interfaces response 
  UInt32 ejectFeatures; //  };
typedef struct DriverGestaltEjectResponse DriverGestaltEjectResponse;
// Flags for Ejection Features field enum {
  kRestartDontEject = 0,  // Dont Want eject during Restart   kShutDownDontEject = 1, // Dont Want eject during Shutdown   kRestartDontEject_Mask = 1 << kRestartDontEject,
  kShutDownDontEject_Mask = 1 << kShutDownDontEject
};

/**
    The DriverGestaltVMOptionsResponse is returned by a disk driver in response
   to a kdgVMOptions Driver Gestalt request. This allows a disk driver to tell
   VM a few things about a disk drive. For example:

    � A drive that should never be in the page fault path should return
   kAllowVMNoneMask. Examples of this are drives that have manual eject buttons
   that are not disabled by software, drives with very slow throughput, or
// Power Saving 
   written to but is safe for read-only file mapping should return
   kAllowVMReadOnlyMask. Exa// Power consumed in �Watts 
   write-once space on the disk and CD-ROM drives which are read-only media. � A
   drive that should allow VM to create its main backing store file should
   return kAllowVMReadWriteMask. Examples of this are fast read/write drives
// Disk Specific 

    A disk driver must look at the ioVRefNum field of the DriverGestaltParam to
   determine what disk drive this call is for. This is a per-drive call, not a
   per-driver call.

    The only three valid responses to kdgVMOptions at this time are
   kAllowVMNoneMask//  Packed target (upper 5 bits) LUN (lower 3 bits) 
   setting only kAl//  Unused 
//  Slot 
    Important: All //  sRsrcID 
   until they are defined for a specific purpose.

    The kdcVMOptions Driver Configure _Control call provides the ability to
   change a driver's response to kdgVMOptions Driver Gestalt requests. A driver
   should return controlErr if it doesn't want to provide the ability to change
   the kdgVMOptions res//       prohibitMounting (control, kProhibitMounting) 
   Configure _Control c//      partitionToVRef (status, kGetPartitionStatus) 
   support (for example//      getPartitionInfo (status, kGetPartInfo) 
   kAllowVMWriteBit), i// all the unused fields should be zero 
*/
struct DriverGestaltVMOptionsResponse {
  UInt32 vmOptions;
};
typedef struct DriverGestaltVMOptionsResponse DriverGestaltVMOptionsResponse;
// Bits and masks for DriverGestaltVMOptionsResponse.vmOptions field enum {
  kAllowVMReadBit = 0,  // Allow VM to use this drive for read access   kAllowVMWriteBit = 1, // Allow VM to use this drive for write access   kAllowVMNoneMask = 0,
  kAllowVMReadOnlyMask = 1 << kAllowVMReadBit,
  kAllowVMReadWriteMask = (1 << kAllowVMReadBit) + (1 << kAllowVMWriteBit)
};

/**
kdgGetDriveAddInfo/kdc// Return true if driver supports the 
assist in the  remount// kdcFlush Driver Configure _Control call 
can use it to store wh// Return true if driver/device has data cached 
For example the Volume// and needs to be flushed when the disk volume 
dependant on the drive// is flushed by the File Manager 

This extension to the Alias Manager works as such:

// Flags for purge permissions 
----------------------
// Ok to call Close 
If driver supports// Ok to call RemoveDrvr 
 kdgGetDriveAddInf// Ok to call DisposePtr 

Inputs to DriverGestalt:
    ioVRefNum   = drive number
    ioCRefNum   = driver refNum
    csCode      = kDriverGestaltCode
// Driver purge permission structure 

If the driver supports kdg// 0 = Do not change the state of the driver 
drive  information record // 3 = Do Close() and DrvrRemove() this driver 
driverGestaltResponse fiel// but don't deallocate driver code 
// 7 = Do Close(), DrvrRemove(), and DisposePtr() 
  The memory used by the DriverGestaltDriveAddInfoResponse and it's pointed
to data, must be previousl// pointer to the start of the driver block (valid 
// only of DisposePtr permission is given 
If the driver doesn't support kdgGetDriveAddInfo,  it returns statusErr.

If noErr, the Alias Mgr stores the drive information record in the alias record
(the length of the drive//  


// Flags for Ejection Features field 
------------------------
// Dont Want eject during Restart 
If driver supports Driver // Dont Want eject during Shutdown 
record in the alias with HoldMemory and then calls the driver with a
kdcAddDriveWithInfo DriverConfigure request.

Inputs to DriverConfigure:
    ioCRefNum   = driver refNum
    csCode      = kDriverConfigureCode
    driverGestaltSelector = pointer to DriverGestaltDriveAddInfoResponse


If the driver supports kdcAddDriveWithInfo, it uses the information in the drive
information record to add a drive to the drive queue. If the drive is added,
the driver returns noErr and returns the drive number in the ioVRefNum field of
the parameter block.

If the drive cannot be added  (but kdcAddDriveWithInfo is supported), the driver
returns nsDrvErr.

If the driver doesn't  support kdcAddDriveWithInfo, it returns controlErr.

If noErr is returned, but the data in the  drive information record is not
up-to-date, the driver should set driveInfoChangedBit in the options field of
the drive information record.

If driveInfoInteractBit in the options field  is set at input, the driver
may perform user interaction to mount the drive.

If noErr, the Alias Mgr tries to resolve the alias the rest of the way.
 */
// drive info option flags enum {
  driveInfoInteractBit =
      31, // Input to kdcAddDriveWithInfo: If set, it's OK for the driver   driveInfoInteractMask =
      (long)0x80000000, //  to perform user interaction to add the drive   driveInfoChangedBit =
      30, // Output from kdgGetDriveInfo: If set, the drive was mounted, but   driveInfoChangedMask =
      0x40000000, //  the drive information record needs to be updated.   driveInfoDriverReservedMask =
      0x0000FFFF, // bits 0-15 are defined by each driver for its own use   driveInfoSystemReservedMask =
      (long)0xFFFF0000 // bits 16-31 are reserved for Apple system use };

struct DriverGestaltDriveAddInfoResponse {
  OptionBits options; // option flags.   ByteCount length;   // length of data   void *data;         // this data must be held with HoldMemory };
typedef struct DriverGestaltDriveAddInfoResponse
    DriverGestaltDriveAddInfoResponse;
/**
    The DriverGestaltMediaInfoResponse is returned by a disk driver in response
// Bits and masks for DriverGestaltVMOptionsResponse.vmOptions field 
   callers the physical block size, the number of blocks that are of that size,
   and the media type fo// Allow VM to use this drive for read access 
// Allow VM to use this drive for write access 
    A disk driver must look at the ioVRefNum field of the DriverGestaltParam to
   determine what disk drive this call is for. This is a per-drive call, not a
   per-driver call.

    On drives that support ejectable media, the response can change depending on
   what media is currently in the drive.
*/
struct DriverGestaltMediaInfoResponse {
  UInt32 numberBlocks; // number of blocks   UInt32 blockSize;    // physical size of blocks   SInt16 mediaType;    // media type identifier };
typedef struct DriverGestaltMediaInfoResponse DriverGestaltMediaInfoResponse;
// DriverGestaltMediaInfoResponse.mediaType constants enum {
  kMediaTypeUnknown = 128,      // media type is unknown   kMediaTypeCDROM = 129,        // media type is a CD-ROM   kMediaTypeDVDROM = 130,       // media type is a DVD-ROM   kMediaTypeDVDRAM = 131,       // media type is a DVD-RAM   kMediaTypeDVDR = 132,         // media type is a DVD-RW   kMediaTypeReadOnly = 133,     // basic read only type   kMediaTypeWriteOnce = 134,    // basic write once type   kMediaTypeRewritable = 135,   // rewritable media, i.e CD-RW   kMediaTypeOverwritable = 136, // random access read write media   kMediaTypeNoMedia = -1        // no media is present };

struct DriverGestaltATADev1Response {
  UInt32 dev1Support; // 1 = supports devices 0 and 1};
typedef struct DriverGestaltATADev1Response DriverGestaltATADev1Response;
/*__________________________________________________________________________________*/
// Device Reference /**
    The driver will return a 32-bit device reference number in the
   driverGestaltResponse field of the DriverGestaltParam structure. The device
   refernce number will be interpreted differently depending on the interface
   retrieved by using the 'intf' Driver Gestalt call.
*/
/*The union for the kdgDeviceReference Gestalt */
union DriverGestaltDeviceReferenceResponse {
  UInt32 devRef; // Generic reference number for interfaces not specified   DeviceIdent scsiID;  // kdgScsiIntf devices will return a DeviceIdent   DeviceIdent ataID;   // kdgATAIntf devices will return a DeviceIdent   USBDeviceRef usbRef; // kdgUSBIntf devices will return a USBDeviceRef};
typedef union DriverGestaltDeviceReferenceResponse
    DriverGestaltDeviceReferenceResponse;
/*__________________________________________________________________________________*/
// Name Registry ID /**
    The driver will pass back in the driverGestaltResponse field of the
   DriverGestaltParam a pointer to the Name Registry Entry ID for the device
   that it controls
*/
// The structure for the kdgNameRegistryEntry Gestalt struct DriverGestaltNameRegistryResponse {
  RegEntryIDPtr entryID;
};
typedef struct DriverGestaltNameRegistryResponse
    DriverGestaltNameRegistryResponse;
/*__________________________________________________________________________________*/
// Device Model Information /**
    The driver will pass a pointer to the DriverGestaltDeviceModelInfoResponse
   in the driverGestaltResponse field of the DriverGestaltParam structure

    The structure for the kdgDeviceModelInfo Gestalt
    If any of theses pointers are nil, that means that the device doesn't
   provide that information
*/
struct DriverGestaltDeviceModelInfoResponse {
  UInt32 infoStructVersion;
  StringPtr vendorName;
  StringPtr productName;
  StringPtr revisionNumber;
  StringPtr subRevisionNumber;
  StringPtr serialNumber;
};
typedef struct DriverGestaltDeviceModelInfoResponse
    DriverGestaltDeviceModelInfoResponse;
// infoStructVersion field values /* NOTE: May need/want to add a UniCode version of the InfoStruct at some point
 */
enum { kInfoStructStringPtrsVers1 = 1 };

/*__________________________________________________________________________________*/
// Supported Media Types /**
    The driver will return the number of media types supported by the device in
   the driverGestaltResponse field of the DriverGestaltParam structure and an
   array of 'devt' values for the supported media types will be returned in the
   driverGestaltResponse1 field of the DriverGestaltParam.

    This call will return the number of media types supported by the device, and
   an array of 'devt' values for the media types (i.e. if a device supports
// drive info option flags 
   media types are supported, and the array would contain kdgFloppyType ('flop')
   and kdgRemovableType ('rdsk')).
*/// Input to kdcAddDriveWithInfo: If set, it's OK for the driver 
// The structure for the kdgSupportedMediaTypes Gestalt struct DriverGestaltSupportedMediaTypesResponse {
  UInt32 supportTypesCou//  to perform user interaction to add the drive 
typedef struct DriverGestaltSupportedMediaTypesResponse
    Driver// Output from kdgGetDriveInfo: If set, the drive was mounted, but 
/*__________________________________________________________________________________*/
// Open Firmware B//  the drive information record needs to be updated. 
    The kdgOpenFirmwareBootSupport selector is used to get information about
   boot support fo// bits 0-15 are defined by each driver for its own use 
   used during the boot process to allow booting from partitions that Open
   Firmware may not be // bits 16-31 are reserved for Apple system use 
   encrypted partitions, compressed partitions, etc..)

    The driver will return the bootPartitionQualifier value in the
   driverGestaltRespon// option flags. 
   exact partition map// length of data 
   driverGestaltRespon// this data must be held with HoldMemory 
    kOFBootSpecifiedPartition is returned in the driverGestaltResponse.
    The number that is returned for the bootPartitionMapEntry field if the
   kOFBootSpecifiedPartition is returned is the partition map entry number for
   the partition. (i.e. If the partition map entry for the boot partition is the
   2nd partition entry in the partition map, the bootPartitionMapEntry field
   would be set to 2.  If the partition map entry for the boot partition is the
   3rd partition map, the bootPartitionMapEntry field would be set to 3 and
   etc.)
*/
struct DriverGestaltOFBootSupportResponse {
  UInt32 bootPartitionQualifier; /*    The exact level of booting that the
                                    driver and device supports */
  UInt32 bootPartitionMapEntry;  /*    The Partition Map entry for the boot
                                    partition if applicable */
};
typedef struct DriverGestaltOFBootSupportResponse
    DriverGestaltOFBootSupportResponse;
// Levels of boot suppo// number of blocks 
 * DriverGestaltOFBootS// physical size of blocks 
enum {// media type identifier 
  kOFBootAnyPartition = 1,
  kOFBootSpecifiedPartition = 2,
// DriverGestaltMediaInfoResponse.mediaType constants 
  kOFBootNotPartitioned = 4
};// media type is unknown 
// media type is a CD-ROM 
/*______________________________// media type is a DVD-ROM 
// CD-ROM Specific /* The CDDevi// media type is a DVD-RAM 
   standard CntrlParam parameter// media type is a DVD-RW 
*/// basic read only type 
struct CDDeviceCharacteristics {// basic write once type 
  UInt8 speedMajor; // High byte// rewritable media, i.e CD-RW 
                        CD-ROM *// random access read write media 
  UInt16// no media is present 
      extendedCdFeatures; // extended flags to support new DVD-ROM/DVD-R etc. };
typedef struct CDDeviceCharacteristics CDDeviceCharacteristics;
enum {
  cdFeatureFlagsMask =// 1 = supports devices 0 and 1
      0xFFFC, // The Flags are in the first 14 bits of the cdFeatures field   cdTransportMask = 0x0003 /* The transport type is in the last 2 bits of the
                              cdFeatures field */
};
// Device Reference 
// Flags for cdFeatures field enum {
  cdPowerInject = 0,     // device supports power inject of media  cdNotPowerEject = 1,   // device does not support power eject of media  cdMute = 2,            // device supports audio channels muting  cdLeftToChannel = 3,   // device supports left channel only mono audio  cdRightToChannel = 4,  // device supports right channel only mono audio  cdLeftPlusRight = 5,   // device supports left + right channels mono audio  cdSCSI_2 = 10,         // device supports SCSI2 command set (SCSI only)  cdStereoVolume = 11,   // device supports independent volume per channel  cdDisconnect = 12,     // device supports disconnect / reconnect (SCSI only)  cdWriteOnce = 13,      // device is a write-once type of drive  cdLockableButton = 14, // device drawer/tray can be locked  cdExtendedFeatures = 15, // extendedCdFeatures field is used  cdPowerInject_Mask = 1 << cdPowerInject,
  cdNotPowerEject_Mask = 1 << cdNotPowerEject,
  cdMute_Mask = 1 << cdMute,
  cdLeftToChannel_Mask = 1 << cdLeftToChannel,
  cdRightToChannel_Mask = 1 << cdRightToChannel,
  cdLeftPlusRight_Mask = 1 << cdLeftPlusRight,
  cdSCSI_2_Mask = 1 << cdSCSI_2,
  cdStereoVolume_// Generic reference number for interfaces not specified 
  cdDisconnect_Mask = 1// kdgScsiIntf devices will return a DeviceIdent 
  cdWriteOnce_Mask = 1 // kdgATAIntf devices will return a DeviceIdent 
  cdLockableButton_Mask// kdgUSBIntf devices will return a USBDeviceRef
  cdExtendedFeatures_Mask = 1 << cdExtendedFeatures
};

// Transport types enum {
// Name Registry ID 

/**
    Flags for extendedCdFeatures field
    Only valid when cdExtendedFeatures_Mask bit of cdFeatures field is set
*/
// The structure for the kdgNameRegistryEntry Gestalt 
  cdDVDROM = 0,   // device reads DVD-ROM media  cdDVDR = 1,     // device writes DVD-R media  cdDVDRAM = 2,   // device writes DVD-RAM media  cdDVDAudio = 3, // device reads DVD-Audio media  cdDVDRW = 4,    // device writes DVD-RW media  cdCDRom = 5,    // device reads CD-ROM media  cdCDR = 6,      // device writes CD-R media  cdCDRW = 7,     // device writes CD-RW media  cdDVDROM_Mask = 1 << cdDVDROM,
  cdDVDR_Mask = 1 << cdDVDR,
  cdDVDRAM_Mask = 1 << cdDVDRAM,
  cdDVDAudio_Mask = 1 << cdDVDAudio,
  cdDVDRW_Mask = 1 << cdDVDRW,
  cdCDRom_Mask = 1 << cdCDRom,
// Device Model Information 
  cdCDRW_Mask = 1 << cdCDRW
};

// the following are used by PC Exchange (and Apple DOS/PC Compatibility Card)
// Control Codesenum {
  kRegisterPartition = 50,      /* PCX needs a new Drive (for a non-macintosh
                                   partition found on the disk)*/
  OLD_REGISTER_PARTITION = 301, /* left in for compatibility with shipping Apple
                                   DOS/PC Compatibility Card*/
  THE_DRIVE = 0,                // DrvQElPtr for the partition to register  THE_PHYS_START = 1,    // The start of the partition in logical blocks  THE_PHYS_SIZE = 2,     // The size of the partition in logical blocks  kGetADrive = 51,       // control call to ask the driver to create a drive  OLD_GET_A_DRIVE = 302, /* left in for compatibility with shipping Apple DOS/PC
                            Compatibility Card*/
  THE_VAR_QUEL = 0,      // a VAR parameter for the returned DrvQElPtr  kProhibitMounting = 52,      // Dont allow mounting of the following drives  kOldProhibitMounting = 2100, /* left in for compatibility with shipping Apple
                                  DOS/PC Compatibility Card*/
  kProhibitDevice = 0,         // CS Param 0 and 1 (partInfoRecPtr)  kIsContainerMounted = 53,
  kOldIsContainerMounted = 2201, /* left in for compatibility with shipping
                                    Apple DOS/PC Compatibility Card         */
  kContainerVRef = 0,            // CS Param 0 and 1 (VRefNum)  kContainerParID = 1,           // CS Param 2 and 3 (Parent ID)  kContainerName = 2,            // CS Param 4 and 5 (File Name)  kContainerResponse = 3, // CS Param 6 and 7 (VAR pointer to short result)  kMountVolumeImg = 54,
  OLD_MOUNT_VOLUME_IMG = 2000,
// infoStructVersion field values 
  MV_HOST_PAR_ID = 1,
  MV_HOST_NAME = 2,
  MV_REQ_PERM = 3
};

// Supported Media Types 
enum {
  kGetPartitionStatus = 50,      // what is the status of this partition?  kOldGetPartitionStatus = 2200, /* left in for compatibility with shipping
                                    Apple DOS/PC Compatibility Card*/
  kDeviceToQuery = 0,            // CS Param 0 and 1 (partInfoRecPtr)  kDeviceResponse = 1, // CS Param 2 and 3 (VAR pointer to short result)  kGetPartInfo =
      51, // Get a partition info record based on the provided vrefnum  kOldGetPartInfo = 2300, /* left in for compatibility with shipping Apple
                             DOS/PC Compatibility Card*/
  kPartInfoResponse =
      0, // var parameter (pointer to partInfoRec) CSParam [0-1]  kGetContainerAlias = 52, /* Get the alias that describes the file this drive
                              was mounted from.*/
  kOldGetContainerAlias = 2400, /* left in for compatibility with shipping Apple
                                   DOS/PC Compatibility Card*/
  kGetAliasResponse =
// The structure for the kdgSupportedMediaTypes Gestalt 

// the result codes to come from // The number of Media Types in the array 
enum {// Array of supported media types  
  DRIVER_NOT_INSTALLED = -1,
  DRIVER_BUSY = -2,
  CANT_MOUNT_WITHIN_THIS_FS =
      -3, // can only mount container within residing on HFS volume  VOLUME_ALREADY_MOUNTED = -4 // Already Mounted};
// Open Firmware Boot support  and Open Firmware Booting support 
// requisite structures for PCX control and status calls
enum {
  kMaxProhibted =
      2 // the max number of volumes the PC can possibly have mounted};

// GestaltSelector for Finding Driver information
enum { kGetDriverInfo = FOUR_CHAR_CODE('vdrc') };

// VerifyCmd, FormatCmd and EjectCmd are now defined in Disks.h/p/a // Partition information passed back and forth between PCX and the driverstruct partInfoRec {
  DeviceIdent SCSIID;      // DeviceIdent for the device  UInt32 physPartitionLoc; // physical block number of beginning of partition  UInt32 partitionNumber;  // the partition number of this partition};
typedef struct partInfoRec partInfoRec;
typedef partInfoRec *partInfoRecPtr;
struct vPartInfoRec {
  UInt8 VPRTVers;    // Virtual partition version number  UInt8 VPRTType;    // virtual partition type (DOS, HFS, etc)  SInt16 drvrRefNum; // Driver Reference number of partition driver};
typedef struct vPartInfoRec vPartInfoRec;
typedef vPartInfoRec *vPartInfoRecPtr;
// Information related to DOS partitionsenum {
  kDOSSigLow = 0x01FE, // offset into boot block for DOS signature  kDOSSigHi = 0x01FF,  // offset into boot block for DOS signature  kDOSSigValLo = 0x55, // DOS signature value in low byte  kDOSSigValHi = 0xAA  // DOS signature value in high byte};

#if PRAGMA_STRUCT_ALIGN
#pragma options align = reset
#elif PRAGMA_STRUCT_PACKPUSH
#pragma pack(pop)
#elif PRAGMA_STRUCT_PACK
#pragma pack()
#endif

#ifdef PRAGMA_IMPORT_OFF
// Levels of boot support that the driver/device supports 
#elif PRAGMA_IMPORT
#pragma import reset
#endif

#ifdef __cplusplus
}
#endif

#endif // __DRIVERGESTALT__ // CD-ROM Specific 
// High byte of fixed point number containing drive speed 
// Low byte of "" CD 300 == 2.2, CD_SC == 1.0 etc. 
// extended flags to support new DVD-ROM/DVD-R etc. 
// The Flags are in the first 14 bits of the cdFeatures field 
// Flags for cdFeatures field 
// device supports power inject of media
// device does not support power eject of media
// device supports audio channels muting
// device supports left channel only mono audio
// device supports right channel only mono audio
// device supports left + right channels mono audio
// device supports SCSI2 command set (SCSI only)
// device supports independent volume per channel
// device supports disconnect / reconnect (SCSI only)
// device is a write-once type of drive
// device drawer/tray can be locked
// extendedCdFeatures field is used
// Transport types 
// CD_SC,CD_SC_PLUS,CD-300 etc. - power eject only
// CD_300_PLUS etc. - power inject only
// Power CD - no power inject/no power eject
// device reads DVD-ROM media
// device writes DVD-R media
// device writes DVD-RAM media
// device reads DVD-Audio media
// device writes DVD-RW media
// device reads CD-ROM media
// device writes CD-R media
// device writes CD-RW media
// the following are used by PC Exchange (and Apple DOS/PC Compatibility Card)
// Control Codes
// DrvQElPtr for the partition to register
// The start of the partition in logical blocks
// The size of the partition in logical blocks
// control call to ask the driver to create a drive
// a VAR parameter for the returned DrvQElPtr
// Dont allow mounting of the following drives
// CS Param 0 and 1 (partInfoRecPtr)
// CS Param 0 and 1 (VRefNum)
// CS Param 2 and 3 (Parent ID)
// CS Param 4 and 5 (File Name)
// CS Param 6 and 7 (VAR pointer to short result)
// Status Codes
// what is the status of this partition?
// CS Param 0 and 1 (partInfoRecPtr)
// CS Param 2 and 3 (VAR pointer to short result)
// Get a partition info record based on the provided vrefnum
// var parameter (pointer to partInfoRec) CSParam [0-1]
//    var parameter (pointer to a Handle) CSParam [0-1]
// the result codes to come from the driver interface 
// can only mount container within residing on HFS volume
// Already Mounted
// requisite structures for PCX control and status calls
// the max number of volumes the PC can possibly have mounted
// GestaltSelector for Finding Driver information
// VerifyCmd, FormatCmd and EjectCmd are now defined in Disks.h/p/a 
// Partition information passed back and forth between PCX and the driver
// DeviceIdent for the device
// physical block number of beginning of partition
// the partition number of this partition
// Virtual partition version number
// virtual partition type (DOS, HFS, etc)
// Driver Reference number of partition driver
// Information related to DOS partitions
// offset into boot block for DOS signature
// offset into boot block for DOS signature
// DOS signature value in low byte
// DOS signature value in high byte
// __DRIVERGESTALT__ 
