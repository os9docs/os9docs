/**
     \file       Devices.h

    \brief   Device Manager Interfaces.

    \introduced_in  Mac OS 8
    \avaliable_from Universal Interfaces 3.4.1

    \copyright © 1985-2001 by Apple Computer, Inc., all rights reserved

    \ingroup Hardware
    
    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __DEVICES__
#define __DEVICES__

#ifndef __OSUTILS__
#include <OSUtils.h>
#endif

#ifndef __FILES__
#include <Files.h>
#endif

#ifndef __QUICKDRAW__
#include <Quickdraw.h>
#endif

#ifndef __NAMEREGISTRY__
#include <NameRegistry.h>
#endif

#ifndef __CODEFRAGMENTS__
#include <CodeFragments.h>
#endif

#ifndef __MULTIPROCESSING__
#include <Multiprocessing.h>
#endif

#ifndef __DRIVERFAMILYMATCHING__
#include <DriverFamilyMatching.h>
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

/* Values of the 'message' parameter to a Chooser device package */
enum {
  chooserInitMsg = 11, /* the user selected this device package */
  newSelMsg = 12,      /* the user made new device selections */
  fillListMsg = 13,    /* fill the device list with choices */
  getSelMsg = 14,      /* mark one or more choices as selected */
  selectMsg = 15,      /* the user made a selection */
  deselectMsg = 16,    /* the user canceled a selection */
  terminateMsg = 17,   /* allows device package to clean up */
  buttonMsg = 19       /* the user selected a button */
};

/* Values of the 'caller' parameter to a Chooser device package */
enum { chooserID = 1 };

/* Values of the 'message' parameter to a Monitor 'mntr' */
enum {
  initMsg = 1,       /*initialization*/
  okMsg = 2,         /*user clicked OK button*/
  cancelMsg = 3,     /*user clicked Cancel button*/
  hitMsg = 4,        /*user clicked control in Options dialog*/
  nulMsg = 5,        /*periodic event*/
  updateMsg = 6,     /*update event*/
  activateMsg = 7,   /*not used*/
  deactivateMsg = 8, /*not used*/
  keyEvtMsg = 9,     /*keyboard event*/
  superMsg = 10,     /*show superuser controls*/
  normalMsg = 11,    /*show only normal controls*/
  startupMsg = 12    /*code has been loaded*/
};

/* control codes for DeskAccessories */
enum {
  goodbye = -1,   /* heap being reinitialized */
  killCode = 1,   /* KillIO requested */
  accEvent = 64,  /* handle an event */
  accRun = 65,    /* time for periodic action */
  accCursor = 66, /* change cursor shape */
  accMenu = 67,   /* handle menu item */
  accUndo = 68,   /* handle undo command */
  accCut = 70,    /* handle cut command */
  accCopy = 71,   /* handle copy command */
  accPaste = 72,  /* handle paste command */
  accClear = 73   /* handle clear command */
};

/* Control/Status Call Codes */
/* drvStsCode, ejectCode and tgBuffCode are now defined in Disks.h/p/a */

/* miscellaneous Device Manager constants */
enum {
  ioInProgress = 1, /* predefined value of ioResult while I/O is pending */
  aRdCmd = 2,       /* low byte of ioTrap for Read calls */
  aWrCmd = 3,       /* low byte of ioTrap for Write calls */
  asyncTrpBit = 10, /* trap word modifier */
  noQueueBit = 9    /* trap word modifier */
};

/* flags used in the driver header and device control entry */
enum {
  dReadEnable = 0,  /* set if driver responds to read requests */
  dWritEnable = 1,  /* set if driver responds to write requests */
  dCtlEnable = 2,   /* set if driver responds to control requests */
  dStatEnable = 3,  /* set if driver responds to status requests */
  dNeedGoodBye = 4, /* set if driver needs time for performing periodic tasks */
  dNeedTime = 5,    /* set if driver needs time for performing periodic tasks */
  dNeedLock =
      6 /* set if driver must be locked in memory as soon as it is opened */
};

enum {
  dNeedLockMask = 0x4000, /* set if driver must be locked in memory as soon as
                             it is opened */
  dNeedTimeMask =
      0x2000, /* set if driver needs time for performing periodic tasks */
  dNeedGoodByeMask = 0x1000, /* set if driver needs to be called before the
                                application heap is initialized */
  dStatEnableMask = 0x0800,  /* set if driver responds to status requests */
  dCtlEnableMask = 0x0400,   /* set if driver responds to control requests */
  dWritEnableMask = 0x0200,  /* set if driver responds to write requests */
  dReadEnableMask = 0x0100   /* set if driver responds to read requests */
};

/* run-time flags used in the device control entry */
enum {
  dVMImmuneBit = 0, /* driver does not need VM protection */
  dOpened = 5,      /* driver is open */
  dRAMBased = 6,    /* dCtlDriver is a handle (1) or pointer (0) */
  drvrActive = 7    /* driver is currently processing a request */
};

enum {
  dVMImmuneMask = 0x0001, /* driver does not need VM protection */
  dOpenedMask = 0x0020,   /* driver is open */
  dRAMBasedMask = 0x0040, /* dCtlDriver is a handle (1) or pointer (0) */
  drvrActiveMask = 0x0080 /* driver is currently processing a request */
};

struct DRVRHeader {
  short drvrFlags;
  short drvrDelay;
  short drvrEMask;
  short drvrMenu;
  short drvrOpen;
  short drvrPrime;
  short drvrCtl;
  short drvrStatus;
  short drvrClose;
  unsigned char drvrName[1];
};
typedef struct DRVRHeader DRVRHeader;
typedef DRVRHeader *DRVRHeaderPtr;
typedef DRVRHeaderPtr *DRVRHeaderHandle;
/**
<pre>
 * \note <pre>When a driver serves a slot device the Device Control Entry has six
additional fields added to the end and is known as an AuxDCE .
The low-order byte of the dCtlFlags word contains the following flags:
Bit Number Meaning
5Set if driver is open
6Set if driver is RAM-based
7Set if driver is currently executing
The high-order byte of the dCtlFlags word contains flags copied from
the drvrFlags word of the driver.
DCtlQHdr contains the header of the driver's I/O queue. DCtlPosition is
used only by drivers of block devices, and indicates the current source or
destination position of a read or write call. The position is given as a
number of bytes beyond the physical beginning of the medium used by the
device. For example, if one logical block of data has just been read from a 3
1/2" disk via the Disk Driver, dCtlPosition will be 512.
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
*/
struct DCtlEntry  {
	Ptr dCtlDriver;/**< pointer to ROM driver or handle to*/
	short dCtlFlags;/**< flags*/
	QHdr dCtlQHdr;/**< driver I/O queue header*/
	long dCtlPosition;/**< byte position used by read and write*/
	Handle dCtlStorage;/**< handle to RAM driver's private*/
	short dCtlRefNum;/**< driver reference number*/
	long dCtlCurTicks;/**< used internally*/
	WindowPtr dCtlWindow;/**< pointer to driver's window*/
	short dCtlDelay;/**< number of ticks between periodic*/
	short dCtlEMask;/**< desk accessory event mask*/
	short dCtlMenu;/**< menu ID of menu associated with*/
	} DCtlEntry ;/**< */

typedef struct DCtlEntry DCtlEntry;
typedef DCtlEntry *DCtlPtr;
typedef DCtlPtr *DCtlHandle;
/**
<pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
*/
struct AuxDCE {
	Ptr dCtlDriver;/**< Address of either RAM or ROM*/
	short dCtlFlags;/**< If set, Bit =driver open, Bit*/
	QHdr dCtlQhdr;/**< Address of queue header*/
	long dCtlPosition;/**< Current source or destination of a*/
	Handle dCtlStorage;/**< Handle to private storage for RAM*/
	short dCtlRefNum;/**< Device driver reference number*/
	long dCtlCurTicks;/**< For internal use*/
	WindowPtr dCtlWindow;/**< Address of driver's window*/
	short dCtlDelay;/**< Time (in ticks) between actions*/
	short dCtlEMask;/**< Event mask for desk accessory*/
	short dCtlMenu;/**< ID for menu associated with device*/
	SignedByte dCtlSlot;/**< Slot number*/
	SignedByte dCtlSlotID;/**< Resource directory ID for the slot*/
	long dCtlDevBase;/**< Points to add-in card's base address*/
	long reserved;/**< For future use*/
	short dCtlExtDev;/**< External device ID*/
	short fillByte;/**< */
	} AuxDCE ;/**< */

typedef struct AuxDCE AuxDCE;
typedef AuxDCE *AuxDCEPtr;
typedef AuxDCEPtr *AuxDCEHandle;
/*  The NDRV Driver IO Entry Point and Commands */
typedef UInt16 UnitNumber;
typedef UInt32 DriverOpenCount;
typedef SInt16 DriverRefNum;
typedef SInt16 DriverFlags;
typedef UInt32 IOCommandCode;
enum {
  kOpenCommand = 0,
  kCloseCommand = 1,
  kReadCommand = 2,
  kWriteCommand = 3,
  kControlCommand = 4,
  kStatusCommand = 5,
  kKillIOCommand = 6,
  kInitializeCommand = 7,  /* init driver and device*/
  kFinalizeCommand = 8,    /* shutdown driver and device*/
  kReplaceCommand = 9,     /* replace an old driver*/
  kSupersededCommand = 10, /* prepare to be replaced by a new driver*/
  kSuspendCommand = 11,    /* prepare driver to go to sleep*/
  kResumeCommand = 12      /* wake up sleeping driver*/
};

enum {
  /* one more IOCommandCode*/
  kPowerManagementCommand = 13 /* power management command, supercedes
                                  kSuspendCommand and kResumeCommand*/
};

typedef MPAddressSpaceID AddressSpaceID;
typedef struct OpaqueIOCommandID *IOCommandID;
typedef UInt32 IOCommandKind;
enum {
  kSynchronousIOCommandKind = 0x00000001,
  kAsynchronousIOCommandKind = 0x00000002,
  kImmediateIOCommandKind = 0x00000004
};

struct DriverInitInfo {
  DriverRefNum refNum;
  RegEntryID deviceEntry;
};
typedef struct DriverInitInfo DriverInitInfo;
typedef DriverInitInfo *DriverInitInfoPtr;
typedef DriverInitInfo DriverReplaceInfo;
typedef DriverInitInfo *DriverReplaceInfoPtr;
struct DriverFinalInfo {
  DriverRefNum refNum;
  RegEntryID deviceEntry;
};
typedef struct DriverFinalInfo DriverFinalInfo;
typedef DriverFinalInfo *DriverFinalInfoPtr;
typedef DriverFinalInfo DriverSupersededInfo;
typedef DriverFinalInfo *DriverSupersededInfoPtr;

/* Contents are command specific*/

union IOCommandContents {
  ParmBlkPtr pb;
  DriverInitInfoPtr initialInfo;
  DriverFinalInfoPtr finalInfo;
  DriverReplaceInfoPtr replaceInfo;
  DriverSupersededInfoPtr supersededInfo;
};
typedef union IOCommandContents IOCommandContents;
typedef CALLBACK_API_C(OSErr, DriverEntryPointPtr)(AddressSpaceID SpaceID,
                                                   IOCommandID CommandID,
                                                   IOCommandContents Contents,
                                                   IOCommandCode Code,
                                                   IOCommandKind Kind);
/* Record to describe a file-based driver candidate */
struct FileBasedDriverRecord {
  FSSpec theSpec;         /* file specification*/
  MacDriverType theType;  /* nameInfoStr + version number*/
  Boolean compatibleProp; /* true if matched using a compatible name*/
  UInt8 pad[3];           /* alignment*/
};
typedef struct FileBasedDriverRecord FileBasedDriverRecord;
typedef FileBasedDriverRecord *FileBasedDriverRecordPtr;
/* Detailed Record to describe a file-based driver candidate. Includes fragment
 * name */
struct FileBasedDriverDetailed {
  FileBasedDriverRecord fileBasedDriver;
  Str63 fragName;
};
typedef struct FileBasedDriverDetailed FileBasedDriverDetailed;
typedef FileBasedDriverDetailed *FileBasedDriverDetailedPtr;
/* Driver Loader API */
#define DECLARE_DRIVERDESCRIPTION(N_ADDITIONAL_SERVICES)                       \
  struct {                                                                     \
    DriverDescription fixed;                                                   \
    DriverServiceInfo additional_service[N_ADDITIONAL_SERVICES - 1];           \
  };

#if CALL_NOT_IN_CARBON
/**
 *  HigherDriverVersion()
 *

 *    \non_carbon_cfm   in DriverLoaderLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
SInt16
HigherDriverVersion(const NumVersion *driverVersion1,
                    const NumVersion *driverVersion2);

/**
 *  VerifyFragmentAsDriver()
 *

 *    \non_carbon_cfm   in DriverLoaderLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSErr
VerifyFragmentAsDriver(CFragConnectionID fragmentConnID,
                       DriverEntryPointPtr *fragmentMain,
                       DriverDescriptionPtr *driverDesc);

/**
 *  GetDriverMemoryFragment()
 *

 *    \non_carbon_cfm   in DriverLoaderLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSErr
GetDriverMemoryFragment(Ptr memAddr, long length, ConstStr63Param fragName,
                        CFragConnectionID *fragmentConnID,
                        DriverEntryPointPtr *fragmentMain,
                        DriverDescriptionPtr *driverDesc);

/**
 *  GetDriverDiskFragment()
 *

 *    \non_carbon_cfm   in DriverLoaderLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSErr
GetDriverDiskFragment(FSSpecPtr fragmentSpec, CFragConnectionID *fragmentConnID,
                      DriverEntryPointPtr *fragmentMain,
                      DriverDescriptionPtr *driverDesc);

/**
 *  GetNamedDriverDiskFragment()
 *

 *    \non_carbon_cfm   in DriverLoaderLib 2.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSErr
GetNamedDriverDiskFragment(FSSpecPtr fragmentSpec, ConstStr63Param fragName,
                           CFragConnectionID *fragmentConnID,
                           DriverEntryPointPtr *fragmentMain,
                           DriverDescriptionPtr *driverDesc);

/**
 *  InstallDriverFromFragment()
 *

 *    \non_carbon_cfm   in DriverLoaderLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSErr
InstallDriverFromFragment(CFragConnectionID fragmentConnID, RegEntryID *device,
                          UnitNumber beginningUnit, UnitNumber endingUnit,
                          DriverRefNum *refNum);

/**
 *  InstallDriverFromFile()
 *

 *    \non_carbon_cfm   in DriverLoaderLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSErr
InstallDriverFromFile(FSSpecPtr fragmentSpec, RegEntryID *device,
                      UnitNumber beginningUnit, UnitNumber endingUnit,
                      DriverRefNum *refNum);

/**
 *  InstallDriverFromMemory()
 *

 *    \non_carbon_cfm   in DriverLoaderLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSErr
InstallDriverFromMemory(Ptr memory, long length, ConstStr63Param fragName,
                        RegEntryID *device, UnitNumber beginningUnit,
                        UnitNumber endingUnit, DriverRefNum *refNum);

/**
 *  InstallDriverFromResource()
 *

 *    \non_carbon_cfm   in DriverLoaderLib 2.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSErr
InstallDriverFromResource(SInt16 theRsrcID, ConstStr255Param theRsrcName,
                          RegEntryIDPtr theDevice, UnitNumber theBeginningUnit,
                          UnitNumber theEndingUnit, DriverRefNum *theRefNum);

/**
 *  InstallDriverFromDisk()
 *

 *    \non_carbon_cfm   in DriverLoaderLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSErr
InstallDriverFromDisk(Ptr theDriverName, RegEntryID *theDevice,
                      UnitNumber theBeginningUnit, UnitNumber theEndingUnit,
                      DriverRefNum *theRefNum);

/**
 *  FindDriversForDevice()
 *

 *    \non_carbon_cfm   in DriverLoaderLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSErr
FindDriversForDevice(RegEntryID *device, FSSpec *fragmentSpec,
                     DriverDescription *fileDriverDesc, Ptr *memAddr,
                     long *length, StringPtr fragName,
                     DriverDescription *memDriverDesc);

/**
 *  FindDriverForDeviceFromFile()
 *

 *    \non_carbon_cfm   in DriverLoaderLib 2.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSErr
FindDriverForDeviceFromFile(RegEntryID *device, FSSpec *fragmentSpec,
                            DriverDescription *driverDesc, StringPtr fragName);

/**
 *  FindDriverCandidates()
 *

 *    \non_carbon_cfm   in DriverLoaderLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSErr
FindDriverCandidates(RegEntryID *deviceID, Ptr *propBasedDriver,
                     RegPropertyValueSize *propBasedDriverSize,
                     StringPtr deviceName, MacDriverType *propBasedDriverType,
                     Boolean *gotPropBasedDriver,
                     FileBasedDriverRecordPtr fileBasedDrivers,
                     ItemCount *nFileBasedDrivers);

/**
 *  FindDriverCandidatesDetailed()
 *

 *    \non_carbon_cfm   in DriverLoaderLib 2.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSErr
FindDriverCandidatesDetailed(RegEntryIDPtr deviceID, Ptr *propBasedDriver,
                             RegPropertyValueSize *propBasedDriverSize,
                             StringPtr deviceName,
                             MacDriverType *propBasedDriverType,
                             Boolean *gotPropBasedDriver,
                             FileBasedDriverDetailedPtr fileBasedDrivers,
                             ItemCount *nFileBasedDrivers);

/**
 *  ScanDriverCandidates()
 *

 *    \non_carbon_cfm   in DriverLoaderLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSErr
ScanDriverCandidates(RegEntryID *deviceID,
                     FileBasedDriverRecordPtr fileBasedDrivers,
                     ItemCount nFileBasedDrivers,
                     FileBasedDriverRecordPtr matchingDrivers,
                     ItemCount *nMatchingDrivers);

/**
 *  ScanDriverCandidatesDetailed()
 *

 *    \non_carbon_cfm   in DriverLoaderLib 2.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSErr
ScanDriverCandidatesDetailed(RegEntryID *deviceID,
                             FileBasedDriverDetailedPtr fileBasedDrivers,
                             ItemCount nFileBasedDrivers,
                             FileBasedDriverDetailedPtr matchingDrivers,
                             ItemCount *nMatchingDrivers);

/**
 *  CompareFileCandToPropCand()
 *

 *    \non_carbon_cfm   in DriverLoaderLib 2.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
SInt16
CompareFileCandToPropCand(RegEntryID *device, StringPtr deviceName,
                          DriverTypePtr propBasedCandidate,
                          FileBasedDriverRecordPtr fileBasedCandidate);

/**
 *  GetCompatibleProperty()
 *

 *    \non_carbon_cfm   in DriverLoaderLib 2.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
GetCompatibleProperty(RegEntryID *device, StringPtr *compatibleNames,
                      ItemCount *nCompatibleNames);

/**
 *  CompatibleDriverNames()
 *

 *    \non_carbon_cfm   in DriverLoaderLib 2.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
Boolean
CompatibleDriverNames(StringPtr nameInfoStr, StringPtr compatibleNames,
                      ItemCount nCompatibleNames, long *nameCount);

/**
 *  GetDriverForDevice()
 *

 *    \non_carbon_cfm   in DriverLoaderLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSErr
GetDriverForDevice(RegEntryID *device, CFragConnectionID *fragmentConnID,
                   DriverEntryPointPtr *fragmentMain,
                   DriverDescriptionPtr *driverDesc);

/**
 *  InstallDriverForDevice()
 *

 *    \non_carbon_cfm   in DriverLoaderLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSErr
InstallDriverForDevice(RegEntryID *device, UnitNumber beginningUnit,
                       UnitNumber endingUnit, DriverRefNum *refNum);

/**
 *  GetDriverInformation()
 *

 *    \non_carbon_cfm   in DriverLoaderLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSErr
GetDriverInformation(DriverRefNum refNum, UnitNumber *unitNum,
                     DriverFlags *flags, DriverOpenCount *count, StringPtr name,
                     RegEntryID *device,
                     CFragSystem7Locator *driverLoadLocation,
                     CFragConnectionID *fragmentConnID,
                     DriverEntryPointPtr *fragmentMain,
                     DriverDescription *driverDesc);

/**
 *  GetDriverDescription()
 *

 *    \non_carbon_cfm   in DriverLoaderLib 2.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSErr
GetDriverDescription(LogicalAddress fragmentPtr,
                     DriverDescriptionPtr *theDriverDesc);

/**
 *  GetNamedDriverDescFromFSSpec()
 *

 *    \non_carbon_cfm   in DriverLoaderLib 2.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSStatus
GetNamedDriverDescFromFSSpec(FSSpecPtr fragmentSpec, StringPtr fragName,
                             DriverDescriptionPtr *driverDesc);

/**
 *  SetDriverClosureMemory()
 *

 *    \non_carbon_cfm   in DriverLoaderLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSErr
SetDriverClosureMemory(CFragConnectionID fragmentConnID,
                       Boolean holdDriverMemory);

/**
 *  ReplaceDriverWithFragment()
 *

 *    \non_carbon_cfm   in DriverLoaderLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSErr
ReplaceDriverWithFragment(DriverRefNum theRefNum,
                          CFragConnectionID fragmentConnID);

/**
 *  OpenInstalledDriver()
 *

 *    \non_carbon_cfm   in DriverLoaderLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSErr
OpenInstalledDriver(DriverRefNum refNum, SInt8 ioPermission);

/**
 *  RenameDriver()
 *

 *    \non_carbon_cfm   in DriverLoaderLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSErr
RenameDriver(DriverRefNum refNum, StringPtr newDriverName);

/**
 *  RemoveDriver()
 *

 *    \non_carbon_cfm   in DriverLoaderLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSErr
RemoveDriver(DriverRefNum refNum, Boolean immediate);

/**
 *  LookupDrivers()
 *

 *    \non_carbon_cfm   in DriverLoaderLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSErr
LookupDrivers(UnitNumber beginningUnit, UnitNumber endingUnit,
              Boolean emptyUnits, ItemCount *returnedRefNums,
              DriverRefNum *refNums);

/**
 *  HighestUnitNumber()
 *

 *    \non_carbon_cfm   in DriverLoaderLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
UnitNumber
HighestUnitNumber(void);

/**
 *  DriverGestaltOn()
 *

 *    \non_carbon_cfm   in DriverLoaderLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSErr
DriverGestaltOn(DriverRefNum refNum);

/**
 *  DriverGestaltOff()
 *

 *    \non_carbon_cfm   in DriverLoaderLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSErr
DriverGestaltOff(DriverRefNum refNum);

/**
 *  DriverGestaltIsOn()
 *

 *    \non_carbon_cfm   in DriverLoaderLib 1.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
Boolean
DriverGestaltIsOn(DriverFlags flags);

/**
 *  PBOpenSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBOpenSync(__A0)
#endif
EXTERN_API(OSErr)
PBOpenSync(ParmBlkPtr paramBlock) ONEWORDINLINE(0xA000);

/**
 *  PBOpenAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBOpenAsync(__A0)
#endif
EXTERN_API(OSErr)
PBOpenAsync(ParmBlkPtr paramBlock) ONEWORDINLINE(0xA400);

/**
 *  PBOpenImmed()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBOpenImmed(__A0)
#endif
EXTERN_API(OSErr)
PBOpenImmed(ParmBlkPtr paramBlock) ONEWORDINLINE(0xA200);

#endif /* CALL_NOT_IN_CARBON */

/**
 *  PBCloseSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBCloseSync(__A0)
#endif
EXTERN_API(OSErr)
PBCloseSync(ParmBlkPtr paramBlock) ONEWORDINLINE(0xA001);

/**
 *  PBCloseAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBCloseAsync(__A0)
#endif
EXTERN_API(OSErr)
PBCloseAsync(ParmBlkPtr paramBlock) ONEWORDINLINE(0xA401);

#if CALL_NOT_IN_CARBON
/**
 *  PBCloseImmed()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBCloseImmed(__A0)
#endif
EXTERN_API(OSErr)
PBCloseImmed(ParmBlkPtr paramBlock) ONEWORDINLINE(0xA201);

#endif /* CALL_NOT_IN_CARBON */

/**
 *  PBReadSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBReadSync(__A0)
#endif
EXTERN_API(OSErr)
PBReadSync(ParmBlkPtr paramBlock) ONEWORDINLINE(0xA002);

/**
 *  PBReadAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBReadAsync(__A0)
#endif
EXTERN_API(OSErr)
PBReadAsync(ParmBlkPtr paramBlock) ONEWORDINLINE(0xA402);

#if CALL_NOT_IN_CARBON
/**
 *  PBReadImmed()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBReadImmed(__A0)
#endif
EXTERN_API(OSErr)
PBReadImmed(ParmBlkPtr paramBlock) ONEWORDINLINE(0xA202);

#endif /* CALL_NOT_IN_CARBON */

/**
 *  PBWriteSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBWriteSync(__A0)
#endif
EXTERN_API(OSErr)
PBWriteSync(ParmBlkPtr paramBlock) ONEWORDINLINE(0xA003);

/**
 *  PBWriteAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBWriteAsync(__A0)
#endif
EXTERN_API(OSErr)
PBWriteAsync(ParmBlkPtr paramBlock) ONEWORDINLINE(0xA403);

#if CALL_NOT_IN_CARBON
/**
 *  PBWriteImmed()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBWriteImmed(__A0)
#endif
EXTERN_API(OSErr)
PBWriteImmed(ParmBlkPtr paramBlock) ONEWORDINLINE(0xA203);

/**
    PBWaitIOComplete is a friendly way for applications to monitor
    a pending asynchronous I/O operation in power-managed and
    preemptive multitasking systems.
 */
#endif /* CALL_NOT_IN_CARBON */

/**
 *  PBWaitIOComplete()
 *

 *    \non_carbon_cfm   in InterfaceLib 9.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSErr)
PBWaitIOComplete(ParmBlkPtr paramBlock, Duration timeout);

/* AddDrive and GetDrvQHdr are now defined in Disks.h/p/a */

#if CALL_NOT_IN_CARBON
/**
 *  GetDCtlEntry()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(DCtlHandle)
GetDCtlEntry(short refNum);

/**
    SetChooserAlert used to simply set a bit in a low-mem global
    to tell the Chooser not to display its warning message when
    the printer is changed. However, under MultiFinder and System 7,
    this low-mem is swapped out when a layer change occurs, and the
    Chooser never sees the change. It is obsolete, and completely
    unsupported on the PowerPC. 68K apps can still call it if they
    wish.

    pascal Boolean SetChooserAlert(Boolean f);

*/
/**
 *  DriverInstall()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 DriverInstall(__A0, __D0)
#endif
EXTERN_API(OSErr)
DriverInstall(DRVRHeaderPtr drvrPtr, short refNum) ONEWORDINLINE(0xA03D);

/**
 *  DriverInstallReserveMem()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 DriverInstallReserveMem(__A0, __D0)
#endif
EXTERN_API(OSErr)
DriverInstallReserveMem(DRVRHeaderPtr drvrPtr, short refNum)
    ONEWORDINLINE(0xA43D);

/**
  Note: DrvrInstall() is no longer supported, becuase it never really worked
  anyways. There will soon be a DriverInstall() which does the right thing.

        DrvrRemove has been renamed to DriverRemove.  But, InterfaceLib for
  PowerPC still exports DrvrRemove, so a macro is used to map the new name to
  old.

*/
/**
 *  DrvrRemove()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 DrvrRemove(__D0)
#endif
EXTERN_API(OSErr)
DrvrRemove(short refNum) ONEWORDINLINE(0xA03E);

#endif /* CALL_NOT_IN_CARBON */

#define DriverRemove(refNum) DrvrRemove(refNum)

#if CALL_NOT_IN_CARBON
/**
 *  [Mac]OpenDriver()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC
#define MacOpenDriver OpenDriver
#endif
EXTERN_API(OSErr)
MacOpenDriver(ConstStr255Param name, short *drvrRefNum);

/**
 *  [Mac]CloseDriver()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC
#define MacCloseDriver CloseDriver
#endif
EXTERN_API(OSErr)
MacCloseDriver(short refNum);

/**
 *  Control()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(OSErr)
Control(short refNum, short csCode, const void *csParamPtr);

/**
 *  Status()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(OSErr)
Status(short refNum, short csCode, void *csParamPtr);


			/** 
			\brief Terminate all current and pending device driver reads and writes 
			
			<pre>KillIO immediately terminates all communication with the device driver
indicated by the reference number. Unlike CloseDriver , it does NOT wait to
complete any pending I/O.
refNum is the reference number of an open device driver. See OpenDriver
.
</pre>
 * \returns <pre>an operating system Error Code . It will be one of:
noErr(0) No error
badUnitErr (-21) refNum doesn't match unit table
unitEmptyErr (-22) refnum specifies NIL handle in unit table
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
			 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(OSErr)
KillIO(short refNum);

/**
 *  Fetch()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 Fetch(__A1)
#endif
EXTERN_API(long)
Fetch(DCtlPtr dce) THREEWORDINLINE(0x2078, 0x08F4, 0x4E90);

/**
 *  Stash()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 Stash(__A1, __D0)
#endif
EXTERN_API(long)
Stash(DCtlPtr dce, char data) THREEWORDINLINE(0x2078, 0x08F8, 0x4E90);

/**
 *  IODone()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter IODone(__A1, __D0)
#endif
EXTERN_API(void)
IODone(DCtlPtr dce, OSErr ioResult) THREEWORDINLINE(0x2078, 0x08FC, 0x4E90);

#endif /* CALL_NOT_IN_CARBON */

#if CALL_NOT_IN_CARBON
/**
 *  PBControlSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBControlSync(__A0)
#endif
EXTERN_API(OSErr)
PBControlSync(ParmBlkPtr paramBlock) ONEWORDINLINE(0xA004);

/**
 *  PBControlAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBControlAsync(__A0)
#endif
EXTERN_API(OSErr)
PBControlAsync(ParmBlkPtr paramBlock) ONEWORDINLINE(0xA404);

/**
 *  PBControlImmed()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBControlImmed(__A0)
#endif
EXTERN_API(OSErr)
PBControlImmed(ParmBlkPtr paramBlock) ONEWORDINLINE(0xA204);

/**
 *  PBStatusSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBStatusSync(__A0)
#endif
EXTERN_API(OSErr)
PBStatusSync(ParmBlkPtr paramBlock) ONEWORDINLINE(0xA005);

/**
 *  PBStatusAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBStatusAsync(__A0)
#endif
EXTERN_API(OSErr)
PBStatusAsync(ParmBlkPtr paramBlock) ONEWORDINLINE(0xA405);

/**
 *  PBStatusImmed()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBStatusImmed(__A0)
#endif
EXTERN_API(OSErr)
PBStatusImmed(ParmBlkPtr paramBlock) ONEWORDINLINE(0xA205);

/**
 *  PBKillIOSync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBKillIOSync(__A0)
#endif
EXTERN_API(OSErr)
PBKillIOSync(ParmBlkPtr paramBlock) ONEWORDINLINE(0xA006);

/**
 *  PBKillIOAsync()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBKillIOAsync(__A0)
#endif
EXTERN_API(OSErr)
PBKillIOAsync(ParmBlkPtr paramBlock) ONEWORDINLINE(0xA406);

/**
 *  PBKillIOImmed()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PBKillIOImmed(__A0)
#endif
EXTERN_API(OSErr)
PBKillIOImmed(ParmBlkPtr paramBlock) ONEWORDINLINE(0xA206);

/**
 *  OpenDeskAcc()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(short)
OpenDeskAcc(ConstStr255Param deskAccName) ONEWORDINLINE(0xA9B6);


			/** 
			\brief Close a desk accessory 
			
			<pre>Call CloseDeskAcc when the user selects the Close item of your File menu
and the frontmost window is that of a DA. The DA window is removed from the
screen and the next-to-frontmost window is reactivated.
daRefNum identifies the DA to close. The value to use is stored in the
windowKind field of the DA's window (see the example, below).
</pre>
 * \returns <pre>none
</pre>
 * \note <pre>There is no need to use this call when the user closes a DA by clicking its
Close box; in that case the Desk Manager takes care of it. Use
CloseDeskAcc only when a system window is frontmost and the user
picks Close from your File menu.
It is incorrect to use the daRefNum  returned from a previous call to
OpenDeskAcc . The DA reference number is stored in the DA's
WindowRecord . It is a negative number in the windowKind field. This has
ramifications for DAs (see IsDialogEvent ). For non-DA applications, a
typical sequence might include:
Boolean isMyWindow ( WindowPtr theWindow);
WindowPeek wPeek;
long mr;
EventRecord theEvent;
WindowRecord whichWindow;
if(WaitNextEvent (everyEvent , &theEvent, 0, nil)) {
if ( theEvent. what == mouseDown ) {
switch ( FindWindow ( theEvent. where, &whichWindow ) ) {
case inMenuBar :
mr = MenuSelect ( theEvent. where );/* user interaction*/
if ( HiWord ( mr ) == FILE_MENU ) { /* in File menu? */
if ( LoWord ( mr ) == CLOSE_ITM ) {/* Close Item ? */
if ( isMyWindow( FrontWindow ()) ) {
/* if it's mine */
/* ... close one of my application's windows ..*/
}
else { /* must be a DA window */
wPeek = ( WindowPeek )FrontWindow ();
CloseDeskAcc ( wPeek->windowKind );
}
}
</pre>
 * \copyright THINK Reference © 1991-1992 Symantec Corporation
			 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(void)
CloseDeskAcc(short refNum) ONEWORDINLINE(0xA9B7);

#endif /* CALL_NOT_IN_CARBON */

#if CALL_NOT_IN_CARBON
/**
 *  opendeskacc()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
short
opendeskacc(const char *deskAccName);

/**
 *  opendriver()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
OSErr
opendriver(const char *driverName, short *refNum);

#endif /* CALL_NOT_IN_CARBON */

/**
    The PBxxx() routines are obsolete.

    Use the PBxxxSync(), PBxxxAsync(), or PBxxxImmed version instead.
*/
#define PBControl(pb, async) ((async) ? PBControlAsync(pb) : PBControlSync(pb))
#define PBStatus(pb, async) ((async) ? PBStatusAsync(pb) : PBStatusSync(pb))
#define PBKillIO(pb, async) ((async) ? PBKillIOAsync(pb) : PBKillIOSync(pb))

#define PBOpen(pb, async) ((async) ? PBOpenAsync(pb) : PBOpenSync(pb))
#define PBClose(pb, async) ((async) ? PBCloseAsync(pb) : PBCloseSync(pb))
#define PBRead(pb, async) ((async) ? PBReadAsync(pb) : PBReadSync(pb))
#define PBWrite(pb, async) ((async) ? PBWriteAsync(pb) : PBWriteSync(pb))

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

#endif /* __DEVICES__ */
*/*/