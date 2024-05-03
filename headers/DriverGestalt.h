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

  /*__________________________________________________________________________________*/
  /* The Driver Gestalt bit in the dCtlFlags */
  enum
  {
    kbDriverGestaltEnable = 2,
    kmDriverGestaltEnableMask = (1 << kbDriverGestaltEnable)
  };

  /*__________________________________________________________________________________*/
  /* Driver Gestalt related csCodes */
  enum
  {
    kDriverGestaltCode = 43,        /* various uses */
    kDriverConfigureCode = 43,      /* various uses */
    kcsSetBootPartitionCode = 44,   /* Set Startup Partition Control Call */
    kcsGetBootPartitionStatus = 44, /* Get Startup Partition Status Call */
    kdgLowPowerMode = 70,           /* Sets/Returns the current energy consumption level */
    kdgReturnDeviceID = 120,        /* returns SCSI DevID in csParam[0] */
    kdgGetCDDeviceInfo = 121        /* returns CDDeviceCharacteristics in csParam[0] */
  };

  /*__________________________________________________________________________________*/
  /* Driver Gestalt selectors */
  enum
  {
    kdgVersion = FOUR_CHAR_CODE(
        'vers'), /* Version number of the driver in standard Apple format */
    kdgDeviceType =
        FOUR_CHAR_CODE('devt'), /* The type of device the driver is driving. */
    kdgInterface = FOUR_CHAR_CODE(
        'intf'), /* The underlying interface that the driver is using (if any) */
    kdgSync =
        FOUR_CHAR_CODE('sync'), /* True if driver only behaves synchronously. */
    kdgBoot =
        FOUR_CHAR_CODE('boot'),       /* value to place in PRAM for this drive (long) */
    kdgWide = FOUR_CHAR_CODE('wide'), /* True if driver supports ioWPosOffset */
    kdgPurge = FOUR_CHAR_CODE(
        'purg'), /* Driver purge permission (True = purge; False = no purge) */
    kdgSupportsSwitching =
        FOUR_CHAR_CODE('lpwr'), /* True if driver supports power switching */
    kdgMin3VPower =
        FOUR_CHAR_CODE('pmn3'), /* Minimum 3.3V power consumption in microWatts */
    kdgMin5VPower =
        FOUR_CHAR_CODE('pmn5'), /* Minimum 5V power consumption in microWatts */
    kdgMax3VPower =
        FOUR_CHAR_CODE('pmx3'), /* Maximum 3.3V power consumption in microWatts */
    kdgMax5VPower =
        FOUR_CHAR_CODE('pmx5'), /* Maximum 5V power consumption in microWatts */
    kdgInHighPower = FOUR_CHAR_CODE(
        'psta'), /* True if device is currently in high power mode */
    kdgSupportsPowerCtl =
        FOUR_CHAR_CODE('psup'),      /* True if driver supports following five calls */
    kdgAPI = FOUR_CHAR_CODE('dAPI'), /* API support for PC Exchange */
    kdgEject = FOUR_CHAR_CODE(
        'ejec'),                       /* Eject options for shutdown/restart (Shutdown Mgr) */
    kdgFlush = FOUR_CHAR_CODE('flus'), /* Determine if disk driver supports flush
    and if it needs a flush */
    kdgVMOptions =
        FOUR_CHAR_CODE('vmop'),            /* Disk drive's Virtual Memory options */
    kdgMediaInfo = FOUR_CHAR_CODE('minf'), /* return media specific information */
    kdgPhysDriveIconSuite =
        FOUR_CHAR_CODE('dics'), /* Return a pointer to a IconFamily ('icns') data
        structure for */
    /* Disk Driver physical drive (formerly in csCode 21) in
    driverGestaltResponse. */
    kdgMediaIconSuite =
        FOUR_CHAR_CODE('mics'), /* Return a pointer to a IconFamily ('icns') data
        structure for */
    /* Disk Driver media (formerly in csCode 22) in driverGestaltResponse. */
    /* See IconServices.r for information detailing the 'icns' resource data
    format */
    kdgMediaName = FOUR_CHAR_CODE(
        'mnam'), /* Return a pointer to a pascal string describing the Disk Driver
        (formerly in csCode 21) in driverGestaltResponse. */
    kdgGetDriveAddInfo = FOUR_CHAR_CODE(
        'digt'), /* Get a disk driver's add-drive information record */
    kdcAddDriveWithInfo =
        FOUR_CHAR_CODE('diad'), /* Tell disk driver to add the drive specified
        with the drive information record */
    /* DriverGestalt selector for ATA drivers to signify that they are device 0/1
    compliant. */
    /* see
    http://developer.apple.com/techpubs/hardware/Developer_Notes/System_Software/ATA_Device_Zero_One.pdf
    */
    kdgATADev1 = FOUR_CHAR_CODE('dev1'),
    kdgDeviceReference =
        FOUR_CHAR_CODE('dvrf'), /* Returns a 32-bit reference number for the
        device, format is interface specific */
    kdgNameRegistryEntry = FOUR_CHAR_CODE(
        'nmrg'), /* Returns a pointer to the Name Registry ID for the device */
    kdgDeviceModelInfo = FOUR_CHAR_CODE(
        'info'), /* Returns a pointer to a Device Model Info structure */
    kdgSupportedMediaTypes =
        FOUR_CHAR_CODE('mdty'), /* Returns a count and a pointer to list of all
        media types supported by the device */
    kdgOpenFirmwareBootSupport =
        FOUR_CHAR_CODE('ofpt'), /* Returns information that Open Firmware needs to
        support booting from the device */
    kdgOpenFirmwareBootingSupport = FOUR_CHAR_CODE(
        'ofbt') /* Returns same information as kdgOpenFirmwareBootSupport, but is
        only used during booting*/
  };

  /*__________________________________________________________________________________*/
  /* Driver Configure selectors */
  enum
  {
    kdcFlush = FOUR_CHAR_CODE('flus'), /* Tell a disk driver to flush its cache
    and any hardware caches */
    kdcVMOptions = FOUR_CHAR_CODE(
        'vmop') /* Change the disk driver's Virtual Memory options */
  };

  /*__________________________________________________________________________________*/
  /* control parameter block for Driver Configure calls */
  struct DriverConfigParam
  {
    QElemPtr qLink;
    short qType;
    short ioTrap;
    Ptr ioCmdAddr;
    ProcPtr ioCompletion;
    OSErr ioResult;
    StringPtr ioNamePtr;
    short ioVRefNum;
    short ioCRefNum; /* refNum for I/O operation */
    short csCode;    /* == kDriverConfigureCode */
    OSType driverConfigureSelector;
    UInt32 driverConfigureParameter;
  };
  typedef struct DriverConfigParam DriverConfigParam;
  /*__________________________________________________________________________________*/
  /* status parameter block for Driver Gestalt calls */
  struct DriverGestaltParam
  {
    QElemPtr qLink;
    short qType;
    short ioTrap;
    Ptr ioCmdAddr;
    ProcPtr ioCompletion;
    OSErr ioResult;
    StringPtr ioNamePtr;
    short ioVRefNum;
    short ioCRefNum;              /* refNum for I/O operation */
    short csCode;                 /* == kDriverGestaltCode */
    OSType driverGestaltSelector; /* 'sync', 'vers', etc. */
    UInt32
        driverGestaltResponse;     /* Could be a pointer, bit field or other format */
    UInt32 driverGestaltResponse1; /* Could be a pointer, bit field or other
    format */
    UInt32 driverGestaltResponse2; /* Could be a pointer, bit field or other
    format */
    UInt32 driverGestaltResponse3; /* Could be a pointer, bit field or other
    format */
    UInt16 driverGestaltfiller;    /* To pad out to the size of a controlPB */
  };
  typedef struct DriverGestaltParam DriverGestaltParam;
/* Note that the various response definitions are overlays of the response
 fields above. For instance the deviceType response would be returned in
 driverGestaltResponse. The DriverGestaltPurgeResponse would be in
 driverGestaltResponse and driverGestaltResponse1
 */
/* GetDriverGestaltDevTResponse(gestaltPtr)->deviceType */
#define GetDriverGestaltDevTResponse(p) \
  ((DriverGestaltDevTResponse *)(&((p)->driverGestaltResponse)))
#define GetDriverGestaltIntfResponse(p) \
  ((DriverGestaltIntfResponse *)(&((p)->driverGestaltResponse)))
#define GetDriverGestaltPowerResponse(p) \
  ((DriverGestaltPowerResponse *)(&((p)->driverGestaltResponse)))
#define GetDriverGestaltSyncResponse(p) \
  ((DriverGestaltSyncResponse *)(&((p)->driverGestaltResponse)))
#define GetDriverGestaltBootResponse(p) \
  ((DriverGestaltBootResponse *)(&((p)->driverGestaltResponse)))
#define GetDriverGestaltPurgeResponse(p) \
  ((DriverGestaltPurgeResponse *)(&((p)->driverGestaltResponse)))
#define GetDriverGestaltEjectResponse(p) \
  ((DriverGestaltEjectResponse *)(&((p)->driverGestaltResponse)))
#define GetDriverGestaltVersionResponse(p) \
  (((NumVersion *)(&((p)->driverGestaltResponse))))
#define GetDriverGestaltAPIResponse(p) \
  ((DriverGestaltAPIResponse *)(&((p)->driverGestaltResponse)))
#define GetDriverGestaltBooleanResponse(p) \
  ((Boolean *)(&((p)->driverGestaltResponse)))
#define GetDriverGestaltFlushResponse(p) \
  ((DriverGestaltFlushResponse *)(&((p)->driverGestaltResponse)))
#define GetDriverGestaltVMOptionsResponse(p) \
  ((DriverGestaltVMOptionsResponse *)(&((p)->driverGestaltResponse)))
#define GetDriverGestaltMediaInfoResponse(p) \
  ((DriverGestaltMediaInfoResponse *)(&((p)->driverGestaltResponse)))
#define GetDriverGestaltDeviceReferenceResponse(p) \
  ((DriverGestaltDeviceReferenceResponse *)(&((p)->driverGestaltResponse)))
#define GetDriverGestaltNameRegistryResponse(p) \
  ((DriverGestaltNameRegistryResponse *)(&((p)->driverGestaltResponse)))
#define GetDriverGestaltDeviceModelInfoResponse(p) \
  ((DriverGestaltDeviceModelInfoResponse **)(&((p)->driverGestaltResponse)))
#define GetDriverGestaltSupportedMediaTypesResponse(p) \
  ((DriverGestaltSupportedMediaTypesResponse **)(&((p)->driverGestaltResponse)))
#define GetDriverGestaltOFBootSupportResponse(p) \
  ((DriverGestaltOFBootSupportResponse *)(&((p)->driverGestaltResponse)))
#define GetDriverGestaltATADev1Response(p) \
  ((DriverGestaltATADev1Response *)(&((p)->driverGestaltResponse)))
#define GetDriverGestaltDriveAddInfoResponse(p) \
  ((DriverGestaltDriveAddInfoResponse *)(&((p)->driverGestaltResponse)))
  /*__________________________________________________________________________________*/
  /* Device Types response */
  struct DriverGestaltDevTResponse
  {
    OSType deviceType;
  };
  typedef struct DriverGestaltDevTResponse DriverGestaltDevTResponse;
  enum
  {
    kdgDiskType = FOUR_CHAR_CODE('disk'),      /* standard r/w disk drive */
    kdgTapeType = FOUR_CHAR_CODE('tape'),      /* tape drive */
    kdgPrinterType = FOUR_CHAR_CODE('prnt'),   /* printer */
    kdgProcessorType = FOUR_CHAR_CODE('proc'), /* processor */
    kdgWormType = FOUR_CHAR_CODE('worm'),      /* write-once */
    kdgCDType = FOUR_CHAR_CODE('cdrm'),        /* cd-rom drive */
    kdgFloppyType = FOUR_CHAR_CODE('flop'),    /* floppy disk drive */
    kdgScannerType = FOUR_CHAR_CODE('scan'),   /* scanner */
    kdgFileType = FOUR_CHAR_CODE(
        'file'), /* Logical Partition type based on a file (Drive Container) */
    kdgRemovableType = FOUR_CHAR_CODE(
        'rdsk') /* A removable media hard disk drive ie. Syquest, Bernioulli */
  };

  /*__________________________________________________________________________________*/
  /* Device Interfaces response */
  struct DriverGestaltIntfResponse
  {
    OSType interfaceType;
  };
  typedef struct DriverGestaltIntfResponse DriverGestaltIntfResponse;
  enum
  {
    kdgScsiIntf = FOUR_CHAR_CODE('scsi'),
    kdgPcmciaIntf = FOUR_CHAR_CODE('pcmc'),
    kdgATAIntf = FOUR_CHAR_CODE('ata '),
    kdgUSBIntf = FOUR_CHAR_CODE('usb '),
    kdgFireWireIntf = FOUR_CHAR_CODE('fire'),
    kdgExtBus = FOUR_CHAR_CODE('card'),
    kdgNetworkIntf = FOUR_CHAR_CODE('net ')
  };

  /*__________________________________________________________________________________*/
  /* Power Saving */
  struct DriverGestaltPowerResponse
  {
    unsigned long powerValue; /* Power consumed in �Watts */
  };
  typedef struct DriverGestaltPowerResponse DriverGestaltPowerResponse;
  /*__________________________________________________________________________________*/
  /* Disk Specific */
  struct DriverGestaltSyncResponse
  {
    Boolean behavesSynchronously;
    UInt8 pad[3];
  };
  typedef struct DriverGestaltSyncResponse DriverGestaltSyncResponse;
  struct DriverGestaltBootResponse
  {
    UInt8 extDev;    /* Packed target (upper 5 bits) LUN (lower 3 bits) */
    UInt8 partition; /* Unused */
    UInt8 SIMSlot;   /* Slot */
    UInt8 SIMsRSRC;  /* sRsrcID */
  };
  typedef struct DriverGestaltBootResponse DriverGestaltBootResponse;
  struct DriverGestaltAPIResponse
  {
    short partitionCmds; /* if bit 0 is nonzero, supports partition control and
    status calls */
    /* prohibitMounting (control, kProhibitMounting) */
    /* partitionToVRef (status, kGetPartitionStatus) */
    /* getPartitionInfo (status, kGetPartInfo) */
    short unused1; /* all the unused fields should be zero */
    short unused2;
    short unused3;
    short unused4;
    short unused5;
    short unused6;
    short unused7;
    short unused8;
    short unused9;
    short unused10;
  };
  typedef struct DriverGestaltAPIResponse DriverGestaltAPIResponse;
  struct DriverGestaltFlushResponse
  {
    Boolean canFlush; /* Return true if driver supports the */
    /* kdcFlush Driver Configure _Control call */
    Boolean needsFlush; /* Return true if driver/device has data cached */
    /* and needs to be flushed when the disk volume */
    /* is flushed by the File Manager */
    UInt8 pad[2];
  };
  typedef struct DriverGestaltFlushResponse DriverGestaltFlushResponse;
  /* Flags for purge permissions */
  enum
  {
    kbCloseOk = 0,  /* Ok to call Close */
    kbRemoveOk = 1, /* Ok to call RemoveDrvr */
    kbPurgeOk = 2,  /* Ok to call DisposePtr */
    kmNoCloseNoPurge = 0,
    kmOkCloseNoPurge = (1 << kbCloseOk) + (1 << kbRemoveOk),
    kmOkCloseOkPurge = (1 << kbCloseOk) + (1 << kbRemoveOk) + (1 << kbPurgeOk)
  };

  /* Driver purge permission structure */
  struct DriverGestaltPurgeResponse
  {
    UInt16 purgePermission; /* 0 = Do not change the state of the driver */
    /* 3 = Do Close() and DrvrRemove() this driver */
    /* but don't deallocate driver code */
    /* 7 = Do Close(), DrvrRemove(), and DisposePtr() */
    UInt16 purgeReserved;
    Ptr purgeDriverPointer; /* pointer to the start of the driver block (valid */
                            /* only of DisposePtr permission is given */
  };
  typedef struct DriverGestaltPurgeResponse DriverGestaltPurgeResponse;
  struct DriverGestaltEjectResponse
  {
    UInt32 ejectFeatures; /* */
  };
  typedef struct DriverGestaltEjectResponse DriverGestaltEjectResponse;
  /* Flags for Ejection Features field */
  enum
  {
    kRestartDontEject = 0,  /* Dont Want eject during Restart */
    kShutDownDontEject = 1, /* Dont Want eject during Shutdown */
    kRestartDontEject_Mask = 1 << kRestartDontEject,
    kShutDownDontEject_Mask = 1 << kShutDownDontEject
  };

  struct DriverGestaltVMOptionsResponse
  {
    UInt32 vmOptions;
  };
  typedef struct DriverGestaltVMOptionsResponse DriverGestaltVMOptionsResponse;
  /* Bits and masks for DriverGestaltVMOptionsResponse.vmOptions field */
  enum
  {
    kAllowVMReadBit = 0,  /* Allow VM to use this drive for read access */
    kAllowVMWriteBit = 1, /* Allow VM to use this drive for write access */
    kAllowVMNoneMask = 0,
    kAllowVMReadOnlyMask = 1 << kAllowVMReadBit,
    kAllowVMReadWriteMask = (1 << kAllowVMReadBit) + (1 << kAllowVMWriteBit)
  };

  /* drive info option flags */
  enum
  {
    driveInfoInteractBit =
        31, /* Input to kdcAddDriveWithInfo: If set, it's OK for the driver */
    driveInfoInteractMask =
        (long)0x80000000, /* to perform user interaction to add the drive */
    driveInfoChangedBit =
        30, /* Output from kdgGetDriveInfo: If set, the drive was mounted, but */
    driveInfoChangedMask =
        0x40000000, /* the drive information record needs to be updated. */
    driveInfoDriverReservedMask =
        0x0000FFFF, /* bits 0-15 are defined by each driver for its own use */
    driveInfoSystemReservedMask =
        (long)0xFFFF0000 /* bits 16-31 are reserved for Apple system use */
  };

  struct DriverGestaltDriveAddInfoResponse
  {
    OptionBits options; /* option flags. */
    ByteCount length;   /* length of data */
    void *data;         /* this data must be held with HoldMemory */
  };
  typedef struct DriverGestaltDriveAddInfoResponse
      DriverGestaltDriveAddInfoResponse;
  struct DriverGestaltMediaInfoResponse
  {
    UInt32 numberBlocks; /* number of blocks */
    UInt32 blockSize;    /* physical size of blocks */
    SInt16 mediaType;    /* media type identifier */
  };
  typedef struct DriverGestaltMediaInfoResponse DriverGestaltMediaInfoResponse;
  /* DriverGestaltMediaInfoResponse.mediaType constants */
  enum
  {
    kMediaTypeUnknown = 128,      /* media type is unknown */
    kMediaTypeCDROM = 129,        /* media type is a CD-ROM */
    kMediaTypeDVDROM = 130,       /* media type is a DVD-ROM */
    kMediaTypeDVDRAM = 131,       /* media type is a DVD-RAM */
    kMediaTypeDVDR = 132,         /* media type is a DVD-RW */
    kMediaTypeReadOnly = 133,     /* basic read only type */
    kMediaTypeWriteOnce = 134,    /* basic write once type */
    kMediaTypeRewritable = 135,   /* rewritable media, i.e CD-RW */
    kMediaTypeOverwritable = 136, /* random access read write media */
    kMediaTypeNoMedia = -1        /* no media is present */
  };

  struct DriverGestaltATADev1Response
  {
    UInt32 dev1Support; /* 1 = supports devices 0 and 1*/
  };
  typedef struct DriverGestaltATADev1Response DriverGestaltATADev1Response;
  /*__________________________________________________________________________________*/
  /* Device Reference */
  /*The union for the kdgDeviceReference Gestalt */
  union DriverGestaltDeviceReferenceResponse
  {
    UInt32 devRef;       /* Generic reference number for interfaces not specified */
    DeviceIdent scsiID;  /* kdgScsiIntf devices will return a DeviceIdent */
    DeviceIdent ataID;   /* kdgATAIntf devices will return a DeviceIdent */
    USBDeviceRef usbRef; /* kdgUSBIntf devices will return a USBDeviceRef*/
  };
  typedef union DriverGestaltDeviceReferenceResponse
      DriverGestaltDeviceReferenceResponse;
  /*__________________________________________________________________________________*/
  /* Name Registry ID */
  /* The structure for the kdgNameRegistryEntry Gestalt */
  struct DriverGestaltNameRegistryResponse
  {
    RegEntryIDPtr entryID;
  };
  typedef struct DriverGestaltNameRegistryResponse
      DriverGestaltNameRegistryResponse;
  /*__________________________________________________________________________________*/
  /* Device Model Information */
  struct DriverGestaltDeviceModelInfoResponse
  {
    UInt32 infoStructVersion;
    StringPtr vendorName;
    StringPtr productName;
    StringPtr revisionNumber;
    StringPtr subRevisionNumber;
    StringPtr serialNumber;
  };
  typedef struct DriverGestaltDeviceModelInfoResponse
      DriverGestaltDeviceModelInfoResponse;
  /* infoStructVersion field values */
  /* NOTE: May need/want to add a UniCode version of the InfoStruct at some point
   */
  enum
  {
    kInfoStructStringPtrsVers1 = 1
  };

  /*__________________________________________________________________________________*/
  /* Supported Media Types */
  /* The structure for the kdgSupportedMediaTypes Gestalt */
  struct DriverGestaltSupportedMediaTypesResponse
  {
    UInt32 supportTypesCount;      /* The number of Media Types in the array */
    OSType supportedTypesArray[1]; /* Array of supported media types */
  };
  typedef struct DriverGestaltSupportedMediaTypesResponse
      DriverGestaltSupportedMediaTypesResponse;
  /*__________________________________________________________________________________*/
  /* Open Firmware Boot support and Open Firmware Booting support */
  struct DriverGestaltOFBootSupportResponse
  {
    UInt32 bootPartitionQualifier; /* The exact level of booting that the
    driver and device supports */
    UInt32 bootPartitionMapEntry;  /* The Partition Map entry for the boot
     partition if applicable */
  };
  typedef struct DriverGestaltOFBootSupportResponse
      DriverGestaltOFBootSupportResponse;
  /* Levels of boot support that the driver/device supports */
  /* These values are used in the bootPartitionQualifier field of the
   * DriverGestaltOFBootSupportResponse */
  enum
  {
    kOFBootAnyPartition = 1,
    kOFBootSpecifiedPartition = 2,
    kOFBootNotBootable = 3,
    kOFBootNotPartitioned = 4
  };

  /*__________________________________________________________________________________*/
  /* CD-ROM Specific */
  /* The CDDeviceCharacteristics result is returned in csParam[0..2] of a
   standard CntrlParam parameter block called with csCode kdgGetCDDeviceInfo.
  */
  struct CDDeviceCharacteristics
  {
    UInt8 speedMajor;  /* High byte of fixed point number containing drive speed */
    UInt8 speedMinor;  /* Low byte of "" CD 300 == 2.2, CD_SC == 1.0 etc. */
    UInt16 cdFeatures; /* Flags field for features and transport type of this
    CD-ROM */
    UInt16
        extendedCdFeatures; /* extended flags to support new DVD-ROM/DVD-R etc. */
  };
  typedef struct CDDeviceCharacteristics CDDeviceCharacteristics;
  enum
  {
    cdFeatureFlagsMask =
        0xFFFC,              /* The Flags are in the first 14 bits of the cdFeatures field */
    cdTransportMask = 0x0003 /* The transport type is in the last 2 bits of the
    cdFeatures field */
  };

  /* Flags for cdFeatures field */
  enum
  {
    cdPowerInject = 0,       /* device supports power inject of media*/
    cdNotPowerEject = 1,     /* device does not support power eject of media*/
    cdMute = 2,              /* device supports audio channels muting*/
    cdLeftToChannel = 3,     /* device supports left channel only mono audio*/
    cdRightToChannel = 4,    /* device supports right channel only mono audio*/
    cdLeftPlusRight = 5,     /* device supports left + right channels mono audio*/
    cdSCSI_2 = 10,           /* device supports SCSI2 command set (SCSI only)*/
    cdStereoVolume = 11,     /* device supports independent volume per channel*/
    cdDisconnect = 12,       /* device supports disconnect / reconnect (SCSI only)*/
    cdWriteOnce = 13,        /* device is a write-once type of drive*/
    cdLockableButton = 14,   /* device drawer/tray can be locked*/
    cdExtendedFeatures = 15, /* extendedCdFeatures field is used*/
    cdPowerInject_Mask = 1 << cdPowerInject,
    cdNotPowerEject_Mask = 1 << cdNotPowerEject,
    cdMute_Mask = 1 << cdMute,
    cdLeftToChannel_Mask = 1 << cdLeftToChannel,
    cdRightToChannel_Mask = 1 << cdRightToChannel,
    cdLeftPlusRight_Mask = 1 << cdLeftPlusRight,
    cdSCSI_2_Mask = 1 << cdSCSI_2,
    cdStereoVolume_Mask = 1 << cdStereoVolume,
    cdDisconnect_Mask = 1 << cdDisconnect,
    cdWriteOnce_Mask = 1 << cdWriteOnce,
    cdLockableButton_Mask = 1 << cdLockableButton,
    cdExtendedFeatures_Mask = 1 << cdExtendedFeatures
  };

  /* Transport types */
  enum
  {
    cdCaddy = 0,                 /* CD_SC,CD_SC_PLUS,CD-300 etc. - power eject only*/
    cdTray = cdPowerInject_Mask, /* CD_300_PLUS etc. - power inject only*/
    cdLid = cdNotPowerEject_Mask /* Power CD - no power inject/no power eject*/
  };

  enum
  {
    cdDVDROM = 0,   /* device reads DVD-ROM media*/
    cdDVDR = 1,     /* device writes DVD-R media*/
    cdDVDRAM = 2,   /* device writes DVD-RAM media*/
    cdDVDAudio = 3, /* device reads DVD-Audio media*/
    cdDVDRW = 4,    /* device writes DVD-RW media*/
    cdCDRom = 5,    /* device reads CD-ROM media*/
    cdCDR = 6,      /* device writes CD-R media*/
    cdCDRW = 7,     /* device writes CD-RW media*/
    cdDVDROM_Mask = 1 << cdDVDROM,
    cdDVDR_Mask = 1 << cdDVDR,
    cdDVDRAM_Mask = 1 << cdDVDRAM,
    cdDVDAudio_Mask = 1 << cdDVDAudio,
    cdDVDRW_Mask = 1 << cdDVDRW,
    cdCDRom_Mask = 1 << cdCDRom,
    cdCDR_Mask = 1 << cdCDR,
    cdCDRW_Mask = 1 << cdCDRW
  };

  /* the following are used by PC Exchange (and Apple DOS/PC Compatibility Card)*/

  /* Control Codes*/
  enum
  {
    kRegisterPartition = 50,      /* PCX needs a new Drive (for a non-macintosh
         partition found on the disk)*/
    OLD_REGISTER_PARTITION = 301, /* left in for compatibility with shipping Apple
    DOS/PC Compatibility Card*/
    THE_DRIVE = 0,                /* DrvQElPtr for the partition to register*/
    THE_PHYS_START = 1,           /* The start of the partition in logical blocks*/
    THE_PHYS_SIZE = 2,            /* The size of the partition in logical blocks*/
    kGetADrive = 51,              /* control call to ask the driver to create a drive*/
    OLD_GET_A_DRIVE = 302,        /* left in for compatibility with shipping Apple DOS/PC
           Compatibility Card*/
    THE_VAR_QUEL = 0,             /* a VAR parameter for the returned DrvQElPtr*/
    kProhibitMounting = 52,       /* Dont allow mounting of the following drives*/
    kOldProhibitMounting = 2100,  /* left in for compatibility with shipping Apple
     DOS/PC Compatibility Card*/
    kProhibitDevice = 0,          /* CS Param 0 and 1 (partInfoRecPtr)*/
    kIsContainerMounted = 53,
    kOldIsContainerMounted = 2201, /* left in for compatibility with shipping
    Apple DOS/PC Compatibility Card */
    kContainerVRef = 0,            /* CS Param 0 and 1 (VRefNum)*/
    kContainerParID = 1,           /* CS Param 2 and 3 (Parent ID)*/
    kContainerName = 2,            /* CS Param 4 and 5 (File Name)*/
    kContainerResponse = 3,        /* CS Param 6 and 7 (VAR pointer to short result)*/
    kMountVolumeImg = 54,
    OLD_MOUNT_VOLUME_IMG = 2000,
    MV_HOST_VREFNUM = 0,
    MV_HOST_PAR_ID = 1,
    MV_HOST_NAME = 2,
    MV_REQ_PERM = 3
  };

  /* Status Codes*/

  enum
  {
    kGetPartitionStatus = 50,      /* what is the status of this partition?*/
    kOldGetPartitionStatus = 2200, /* left in for compatibility with shipping
    Apple DOS/PC Compatibility Card*/
    kDeviceToQuery = 0,            /* CS Param 0 and 1 (partInfoRecPtr)*/
    kDeviceResponse = 1,           /* CS Param 2 and 3 (VAR pointer to short result)*/
    kGetPartInfo =
        51,                 /* Get a partition info record based on the provided vrefnum*/
    kOldGetPartInfo = 2300, /* left in for compatibility with shipping Apple
    DOS/PC Compatibility Card*/
    kPartInfoResponse =
        0,                        /* var parameter (pointer to partInfoRec) CSParam [0-1]*/
    kGetContainerAlias = 52,      /* Get the alias that describes the file this drive
         was mounted from.*/
    kOldGetContainerAlias = 2400, /* left in for compatibility with shipping Apple
    DOS/PC Compatibility Card*/
    kGetAliasResponse =
        0 /* var parameter (pointer to a Handle) CSParam [0-1]*/
  };

  /* the result codes to come from the driver interface */

  enum
  {
    DRIVER_NOT_INSTALLED = -1,
    DRIVER_BUSY = -2,
    CANT_MOUNT_WITHIN_THIS_FS =
        -3,                     /* can only mount container within residing on HFS volume*/
    VOLUME_ALREADY_MOUNTED = -4 /* Already Mounted*/
  };

  /* requisite structures for PCX control and status calls*/

  enum
  {
    kMaxProhibted =
        2 /* the max number of volumes the PC can possibly have mounted*/
  };

  /* GestaltSelector for Finding Driver information*/

  enum
  {
    kGetDriverInfo = FOUR_CHAR_CODE('vdrc')
  };

  /* VerifyCmd, FormatCmd and EjectCmd are now defined in Disks.h/p/a */
  /* Partition information passed back and forth between PCX and the driver*/
  struct partInfoRec
  {
    DeviceIdent SCSIID;      /* DeviceIdent for the device*/
    UInt32 physPartitionLoc; /* physical block number of beginning of partition*/
    UInt32 partitionNumber;  /* the partition number of this partition*/
  };
  typedef struct partInfoRec partInfoRec;
  typedef partInfoRec *partInfoRecPtr;
  struct vPartInfoRec
  {
    UInt8 VPRTVers;    /* Virtual partition version number*/
    UInt8 VPRTType;    /* virtual partition type (DOS, HFS, etc)*/
    SInt16 drvrRefNum; /* Driver Reference number of partition driver*/
  };
  typedef struct vPartInfoRec vPartInfoRec;
  typedef vPartInfoRec *vPartInfoRecPtr;
  /* Information related to DOS partitions*/
  enum
  {
    kDOSSigLow = 0x01FE, /* offset into boot block for DOS signature*/
    kDOSSigHi = 0x01FF,  /* offset into boot block for DOS signature*/
    kDOSSigValLo = 0x55, /* DOS signature value in low byte*/
    kDOSSigValHi = 0xAA  /* DOS signature value in high byte*/
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

#endif /* __DRIVERGESTALT__ */
