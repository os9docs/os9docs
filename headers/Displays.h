/**
     \file       Displays.h

    \brief   Display Manager Interfaces.

    \introduced_in  Mac OS 8
    \avaliable_from Universal Interfaces 3.4.1

    \copyright © 1993-2001 by Apple Computer, Inc., all rights reserved.

    \ingroup Hardware

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __DISPLAYS__
#define __DISPLAYS__

#ifndef __CONDITIONALMACROS__
#include <ConditionalMacros.h>
#endif

#ifndef __COMPONENTS__
#include <Components.h>
#endif

#ifndef __VIDEO__
#include <Video.h>
#endif

#ifndef __CMAPPLICATION__
#include <CMApplication.h>
#endif

#ifndef __APPLEEVENTS__
#include <AppleEvents.h>
#endif

#ifndef __EVENTS__
#include <Events.h>
#endif

#ifndef __PROCESSES__
#include <Processes.h>
#endif

#ifndef __DIALOGS__
#include <Dialogs.h>
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

  typedef ProcessSerialNumberPtr DMProcessInfoPtr;
  typedef ModalFilterUPP DMModalFilterUPP;

  enum
  {
    /** AppleEvents Core Suite */
    kAESystemConfigNotice = FOUR_CHAR_CODE('cnfg'), /** Core Suite types */
    kAEDisplayNotice = FOUR_CHAR_CODE('dspl'),
    kAEDisplaySummary = FOUR_CHAR_CODE('dsum'),
    keyDMConfigVersion = FOUR_CHAR_CODE('dmcv'),
    keyDMConfigFlags = FOUR_CHAR_CODE('dmcf'),
    keyDMConfigReserved = FOUR_CHAR_CODE('dmcr'),
    keyDisplayID = FOUR_CHAR_CODE('dmid'),
    keyDisplayComponent = FOUR_CHAR_CODE('dmdc'),
    keyDisplayDevice = FOUR_CHAR_CODE('dmdd'),
    keyDisplayFlags = FOUR_CHAR_CODE('dmdf'),
    keyDisplayMode = FOUR_CHAR_CODE('dmdm'),
    keyDisplayModeReserved = FOUR_CHAR_CODE('dmmr'),
    keyDisplayReserved = FOUR_CHAR_CODE('dmdr'),
    keyDisplayMirroredId = FOUR_CHAR_CODE('dmmi'),
    keyDeviceFlags = FOUR_CHAR_CODE('dddf'),
    keyDeviceDepthMode = FOUR_CHAR_CODE('dddm'),
    keyDeviceRect = FOUR_CHAR_CODE('dddr'),
    keyPixMapRect = FOUR_CHAR_CODE('dpdr'),
    keyPixMapHResolution = FOUR_CHAR_CODE('dphr'),
    keyPixMapVResolution = FOUR_CHAR_CODE('dpvr'),
    keyPixMapPixelType = FOUR_CHAR_CODE('dppt'),
    keyPixMapPixelSize = FOUR_CHAR_CODE('dpps'),
    keyPixMapCmpCount = FOUR_CHAR_CODE('dpcc'),
    keyPixMapCmpSize = FOUR_CHAR_CODE('dpcs'),
    keyPixMapAlignment = FOUR_CHAR_CODE('dppa'),
    keyPixMapResReserved = FOUR_CHAR_CODE('dprr'),
    keyPixMapReserved = FOUR_CHAR_CODE('dppr'),
    keyPixMapColorTableSeed = FOUR_CHAR_CODE('dpct'),
    keySummaryMenubar = FOUR_CHAR_CODE('dsmb'),
    keySummaryChanges = FOUR_CHAR_CODE('dsch'),
    keyDisplayOldConfig = FOUR_CHAR_CODE('dold'),
    keyDisplayNewConfig = FOUR_CHAR_CODE('dnew')
  };

  enum
  {
    dmOnlyActiveDisplays = true,
    dmAllDisplays = false
  };

  enum
  {
    /** DMSendDependentNotification notifyClass */
    kDependentNotifyClassShowCursor = FOUR_CHAR_CODE(
        'shcr'), /** When display mgr shows a hidden cursor during an unmirror */
    kDependentNotifyClassDriverOverride =
        FOUR_CHAR_CODE('ndrv'), /** When a driver is overridden */
    kDependentNotifyClassDisplayMgrOverride =
        FOUR_CHAR_CODE('dmgr'), /** When display manager is upgraded */
    kDependentNotifyClassProfileChanged =
        FOUR_CHAR_CODE('prof') /** When DMSetProfileByAVID is called */
  };

  enum
  {
    /** Switch Flags */
    kNoSwitchConfirmBit = 0,   /** Flag indicating that there is no need to confirm
                                  a switch to this mode */
    kDepthNotAvailableBit = 1, /** Current depth not available in new mode */
    kShowModeBit = 3,          /** Show this mode even though it requires a confirm. */
    kModeNotResizeBit = 4,     /** Do not use this mode to resize display (for cards
                                  that mode drives a different connector). */
    kNeverShowModeBit =
        5 /** This mode should not be shown in the user interface. */
  };

  /**    Summary Change Flags (sticky bits indicating an operation was performed)
      For example, moving a display then moving it back will still set the
     kMovedDisplayBit.
  */
  enum
  {
    kBeginEndConfigureBit = 0,
    kMovedDisplayBit = 1,
    kSetMainDisplayBit = 2,
    kSetDisplayModeBit = 3,
    kAddDisplayBit = 4,
    kRemoveDisplayBit = 5,
    kNewDisplayBit = 6,
    kDisposeDisplayBit = 7,
    kEnabledDisplayBit = 8,
    kDisabledDisplayBit = 9,
    kMirrorDisplayBit = 10,
    kUnMirrorDisplayBit = 11
  };

  enum
  {
    /** Notification Messages for extended call back routines */
    kDMNotifyRequestConnectionProbe =
        0,                  /** Like kDMNotifyRequestDisplayProbe only not for smart displays (used
                               in wake before all busses are awake) */
    kDMNotifyInstalled = 1, /** At install time */
    kDMNotifyEvent = 2,     /** Post change time */
    kDMNotifyRemoved = 3,   /** At remove time */
    kDMNotifyPrep = 4,      /** Pre change time */
    kDMNotifyExtendEvent =
        5,                         /** Allow registrees to extend apple event before it is sent */
    kDMNotifyDependents = 6,       /** Minor notification check without full update */
    kDMNotifySuspendConfigure = 7, /** Temporary end of configuration */
    kDMNotifyResumeConfigure = 8,  /** Resume configuration */
    kDMNotifyRequestDisplayProbe =
        9, /** Request smart displays re-probe (used in sleep and hot plugging) */
           /** Notification Flags */
    kExtendedNotificationProc = (1L << 16)
  };

  /** types for notifyType */
  enum
  {
    kFullNotify = 0, /** This is the appleevent whole nine yards notify */
    kFullDependencyNotify =
        1 /** Only sends to those who want to know about interrelated
             functionality (used for updating UI) */
  };

  /** DisplayID/DeviceID constants */
  enum
  {
    kDummyDeviceID = 0x00FF,    /** This is the ID of the dummy display, used when
                                   the last ©real© display is disabled.*/
    kInvalidDisplayID = 0x0000, /** This is the invalid ID*/
    kFirstDisplayID = 0x0100
  };

  enum
  {
    /** bits for panelListFlags */
    kAllowDuplicatesBit = 0
  };

  enum
  {
    /** bits for nameFlags */
    kSuppressNumberBit = 0,
    kSuppressNumberMask = 1,
    kForceNumberBit = 1,
    kForceNumberMask = 2,
    kSuppressNameBit = 2,
    kSuppressNameMask = 4
  };

  /** DMGetNameByAVID masks*/
  enum
  {
    kDMSupressNumbersMask =
        (1 << 0),                   /** Supress the numbers and return only names*/
    kDMForceNumbersMask = (1 << 1), /** Force numbers to always be shown (even on
                                       single display configs)*/
    kDMSupressNameMask = (1 << 2)   /** Supress the names and return only numbers.*/
  };

  /** Constants for fidelity checks */
  enum
  {
    kNoFidelity = 0,
    kMinimumFidelity = 1,
    kDefaultFidelity =
        500, /** I'm just picking a number for Apple default panels and engines*/
    kDefaultManufacturerFidelity =
        1000 /** I'm just picking a number for Manufacturer's panels and engines
                (overrides apple defaults)*/
  };

  enum
  {
    kAnyPanelType = 0,  /** Pass to DMNewEngineList for list of all panels (as
                           opposed to specific types)*/
    kAnyEngineType = 0, /** Pass to DMNewEngineList for list of all engines*/
    kAnyDeviceType = 0, /** Pass to DMNewDeviceList for list of all devices*/
    kAnyPortType = 0    /** Pass to DMNewDevicePortList for list of all devices*/
  };

  /** portListFlags for DM_NewDevicePortList */
  enum
  {
    /** Should offline devices be put into the port list (such as dummy display)
     */
    kPLIncludeOfflineDevicesBit = 0
  };

  /** confirmFlags for DMConfirmConfiguration */
  enum
  {
    kForceConfirmBit = 0, /** Force a confirm dialog */
    kForceConfirmMask = (1 << kForceConfirmBit)
  };

  /** Flags for displayModeFlags */
  enum
  {
    kDisplayModeListNotPreferredBit = 0,
    kDisplayModeListNotPreferredMask = (1 << kDisplayModeListNotPreferredBit)
  };

  /** Flags for itemFlags */
  enum
  {
    kComponentListNotPreferredBit = 0,
    kComponentListNotPreferredMask = (1 << kComponentListNotPreferredBit)
  };

  enum
  {
    kDisplayTimingInfoVersionZero = 1,
    kDisplayTimingInfoReservedCountVersionZero = 16,
    kDisplayModeEntryVersionZero = 0, /** displayModeVersion - original version*/
    kDisplayModeEntryVersionOne =
        1 /** displayModeVersion - added displayModeOverrideInfo*/
  };

  enum
  {
    kMakeAndModelReservedCount = 4 /** Number of reserved fields*/
  };

  /** Display Gestalt for DMDisplayGestalt*/
  enum
  {
    kDisplayGestaltDisplayCommunicationAttr = FOUR_CHAR_CODE('comm'),
    kDisplayGestaltForbidI2CMask =
        (1 << 0), /** Some displays have firmware problems if they get I2C
                     communication.  If this bit is set, then I2C communication is
                     forbidden*/
    kDisplayGestaltUseI2CPowerMask =
        (1 << 1), /** Some displays require I2C power settings (most use DPMS).*/
    kDisplayGestaltCalibratorAttr = FOUR_CHAR_CODE('cali'),
    kDisplayGestaltBrightnessAffectsGammaMask =
        (1 << 0), /** Used by default calibrator (should we show brightness panel)
                   */
    kDisplayGestaltViewAngleAffectsGammaMask =
        (1 << 1) /** Currently not used by color sync*/
  };

  typedef UInt32 DMFidelityType;
  /**
     AVID is an ID for ports and devices the old DisplayID type
      is carried on for compatibility
  */

  typedef void *DMListType;
  typedef unsigned long DMListIndexType;
  typedef VDPowerStateRec AVPowerStateRec;
  typedef VDPowerStateRec *AVPowerStatePtr;
  struct DMDisplayTimingInfoRec
  {
    UInt32 timingInfoVersion;
    UInt32 timingInfoAttributes;      /** Flags */
    SInt32 timingInfoRelativeQuality; /** quality of the timing */
    SInt32 timingInfoRelativeDefault; /** relative default of the timing */

    UInt32 timingInfoReserved[16]; /** Reserved */
  };
  typedef struct DMDisplayTimingInfoRec DMDisplayTimingInfoRec;
  typedef DMDisplayTimingInfoRec *DMDisplayTimingInfoPtr;

  struct DMComponentListEntryRec
  {
    DisplayIDType itemID;    /** DisplayID Manager*/
    Component itemComponent; /** Component Manager*/
    ComponentDescription
        itemDescription; /** We can always construct this if we use something
                            beyond the compontent mgr.*/

    ResType itemClass; /** Class of group to put this panel (eg geometry/color/etc
                          for panels, brightness/contrast for engines, video
                          out/sound/etc for devices)*/
    DMFidelityType
        itemFidelity;     /** How good is this item for the specified search?*/
    ResType itemSubClass; /** Subclass of group to put this panel.  Can use to do
                             sub-grouping (eg volume for volume panel and mute
                             panel)*/
    Point itemSort;       /** Set to 0 - future to sort the items in a sub group.*/

    unsigned long itemFlags;   /** Set to 0 (future expansion)*/
    ResType itemReserved;      /** What kind of code does the itemReference point to
                                  (right now - kPanelEntryTypeComponentMgr only)*/
    unsigned long itemFuture1; /** Set to 0 (future expansion - probably an
                                  alternate code style)*/
    unsigned long itemFuture2; /** Set to 0 (future expansion - probably an
                                  alternate code style)*/
    unsigned long itemFuture3; /** Set to 0 (future expansion - probably an
                                  alternate code style)*/
    unsigned long itemFuture4; /** Set to 0 (future expansion - probably an
                                  alternate code style)*/
  };
  typedef struct DMComponentListEntryRec DMComponentListEntryRec;
  typedef DMComponentListEntryRec *DMComponentListEntryPtr;
  /** ©©© Move AVLocationRec to AVComponents.i AFTER AVComponents.i is created*/
  struct AVLocationRec
  {
    unsigned long locationConstant; /** Set to 0 (future expansion - probably an
                                       alternate code style)*/
  };
  typedef struct AVLocationRec AVLocationRec;
  typedef AVLocationRec *AVLocationPtr;
  struct DMDepthInfoRec
  {
    VDSwitchInfoPtr depthSwitchInfo; /** This is the switch mode to choose this
                                        timing/depth */
    VPBlockPtr depthVPBlock;         /** VPBlock (including size, depth and format) */
    UInt32 depthFlags;               /** VDVideoParametersInfoRec.csDepthFlags  */
    UInt32 depthReserved1;           /** Reserved */
    UInt32 depthReserved2;           /** Reserved */
  };
  typedef struct DMDepthInfoRec DMDepthInfoRec;
  typedef DMDepthInfoRec *DMDepthInfoPtr;
  struct DMDepthInfoBlockRec
  {
    unsigned long depthBlockCount;     /** How many depths are there? */
    DMDepthInfoPtr depthVPBlock;       /** Array of DMDepthInfoRec */
    unsigned long depthBlockFlags;     /** Reserved */
    unsigned long depthBlockReserved1; /** Reserved */
    unsigned long depthBlockReserved2; /** Reserved */
  };
  typedef struct DMDepthInfoBlockRec DMDepthInfoBlockRec;
  typedef DMDepthInfoBlockRec *DMDepthInfoBlockPtr;
  struct DMDisplayModeListEntryRec
  {
    UInt32 displayModeFlags;
    VDSwitchInfoPtr displayModeSwitchInfo;
    VDResolutionInfoPtr displayModeResolutionInfo;
    VDTimingInfoPtr displayModeTimingInfo;
    DMDepthInfoBlockPtr
        displayModeDepthBlockInfo; /** Information about all the depths*/
    UInt32 displayModeVersion;     /** What version is this record (now
                                      kDisplayModeEntryVersionOne)*/
    StringPtr displayModeName;     /** Name of the timing mode*/
    DMDisplayTimingInfoPtr
        displayModeDisplayInfo; /** Information from the display.*/
  };
  typedef struct DMDisplayModeListEntryRec DMDisplayModeListEntryRec;
  typedef DMDisplayModeListEntryRec *DMDisplayModeListEntryPtr;

  struct DependentNotifyRec
  {
    ResType notifyType;                /** What type was the engine that made the change (may be
                                          zero)*/
    ResType notifyClass;               /** What class was the change (eg geometry, color etc)*/
    DisplayIDType notifyPortID;        /** Which device was touched (kInvalidDisplayID ->
                                          all or none)*/
    ComponentInstance notifyComponent; /** What engine did it (may be 0)?*/

    unsigned long notifyVersion;  /** Set to 0 (future expansion)*/
    unsigned long notifyFlags;    /** Set to 0 (future expansion)*/
    unsigned long notifyReserved; /** Set to 0 (future expansion)*/
    unsigned long notifyFuture;   /** Set to 0 (future expansion)*/
  };
  typedef struct DependentNotifyRec DependentNotifyRec;
  typedef DependentNotifyRec *DependentNotifyPtr;

  struct DMMakeAndModelRec
  {
    ResType manufacturer;
    UInt32 model;
    UInt32 serialNumber;
    UInt32 manufactureDate;

    UInt32 makeReserved[4];
  };
  typedef struct DMMakeAndModelRec DMMakeAndModelRec;
  typedef DMMakeAndModelRec *DMMakeAndModelPtr;
  /** DMNewDisplayList displayListIncludeFlags*/
  enum
  {
    kIncludeOnlineActiveDisplaysMask = (1 << 0),
    kIncludeOnlineDisabledDisplaysMask = (1 << 1),
    kIncludeOfflineDisplaysMask = (1 << 2),
    kIncludeOfflineDummyDisplaysMask = (1 << 3),
    kIncludeHardwareMirroredDisplaysMask = (1 << 4)
  };

  enum
  {
    /** modeListFlags for DMNewDisplayModeList */
    kDMModeListIncludeAllModesMask =
        (1 << 0), /** Include all timing modes not _explicitly_ excluded (see
                     other bits)*/
    kDMModeListIncludeOfflineModesMask = (1 << 1),
    kDMModeListExcludeDriverModesMask =
        (1 << 2), /** Exclude old-style timing modes
                     (cscGetNextResolution/kDisplayModeIDFindFirstResolution
                     modes)*/
    kDMModeListExcludeDisplayModesMask =
        (1 << 3), /** Exclude timing modes that come from the display (always
                     arbritrary timing modes)*/
    kDMModeListExcludeCustomModesMask =
        (1 << 4), /** Exclude custom modes that came neither from the driver or
                     display (need a better name)*/
    kDMModeListPreferStretchedModesMask =
        (1 << 5), /** Prefer modes that are stretched over modes that are
                     letterboxed when setting kDisplayModeListNotPreferredBit*/
    kDMModeListPreferSafeModesMask =
        (1 << 6), /** Prefer modes that are safe over modes that are not when
                     setting kDisplayModeListNotPreferredBit*/
    kDMModeListExcludeDriverScaledModesMask =
        (1 << 7) /** Exclude modes that are scaled by the driver (usually on fixed
                    resolution displays)*/
  };

  /** DMNewDisplayList displayListFlags*/
  struct DisplayListEntryRec
  {
    GDHandle displayListEntryGDevice;
    DisplayIDType displayListEntryDisplayID;
    UInt32 displayListEntryIncludeFlags; /** Reason this entry was included*/
    UInt32 displayListEntryReserved1;

    UInt32 displayListEntryReserved2; /** Zero*/
    UInt32 displayListEntryReserved3; /** Zero*/
    UInt32 displayListEntryReserved4; /** Zero*/
    UInt32 displayListEntryReserved5; /** Zero*/
  };
  typedef struct DisplayListEntryRec DisplayListEntryRec;
  typedef DisplayListEntryRec *DisplayListEntryPtr;
  struct DMProfileListEntryRec
  {
    CMProfileRef profileRef;
    Ptr profileReserved1; /** Reserved*/
    Ptr profileReserved2; /** Reserved*/
    Ptr profileReserved3; /** Reserved*/
  };
  typedef struct DMProfileListEntryRec DMProfileListEntryRec;
  typedef DMProfileListEntryRec *DMProfileListEntryPtr;
  typedef CALLBACK_API(void, DMNotificationProcPtr)(AppleEvent *theEvent);
  typedef CALLBACK_API(void, DMExtendedNotificationProcPtr)(void *userData,
                                                            short theMessage,
                                                            void *notifyData);
  typedef CALLBACK_API(void, DMComponentListIteratorProcPtr)(
      void *userData, DMListIndexType itemIndex,
      DMComponentListEntryPtr componentInfo);
  typedef CALLBACK_API(void, DMDisplayModeListIteratorProcPtr)(
      void *userData, DMListIndexType itemIndex,
      DMDisplayModeListEntryPtr displaymodeInfo);
  typedef CALLBACK_API(void, DMProfileListIteratorProcPtr)(
      void *userData, DMListIndexType itemIndex,
      DMProfileListEntryPtr profileInfo);
  typedef CALLBACK_API(void, DMDisplayListIteratorProcPtr)(
      void *userData, DMListIndexType itemIndex,
      DisplayListEntryPtr displaymodeInfo);
  typedef STACK_UPP_TYPE(DMNotificationProcPtr) DMNotificationUPP;
  typedef STACK_UPP_TYPE(DMExtendedNotificationProcPtr) DMExtendedNotificationUPP;
  typedef STACK_UPP_TYPE(DMComponentListIteratorProcPtr)
      DMComponentListIteratorUPP;
  typedef STACK_UPP_TYPE(DMDisplayModeListIteratorProcPtr)
      DMDisplayModeListIteratorUPP;
  typedef STACK_UPP_TYPE(DMProfileListIteratorProcPtr) DMProfileListIteratorUPP;
  typedef STACK_UPP_TYPE(DMDisplayListIteratorProcPtr) DMDisplayListIteratorUPP;
  /**
   *  NewDMNotificationUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  DMNotificationUPP
  NewDMNotificationUPP(DMNotificationProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppDMNotificationProcInfo = 0x000000C0
  }; /** pascal no_return_value Func(4_bytes) */
#ifdef __cplusplus
  inline DMNotificationUPP
  NewDMNotificationUPP(DMNotificationProcPtr userRoutine)
  {
    return (DMNotificationUPP)NewRoutineDescriptor((ProcPtr)(userRoutine),
                                                   uppDMNotificationProcInfo,
                                                   GetCurrentArchitecture());
  }
#else
#define NewDMNotificationUPP(userRoutine)                                     \
  (DMNotificationUPP)                                                         \
      NewRoutineDescriptor((ProcPtr)(userRoutine), uppDMNotificationProcInfo, \
                           GetCurrentArchitecture())
#endif
#endif

  /**
   *  NewDMExtendedNotificationUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  DMExtendedNotificationUPP
  NewDMExtendedNotificationUPP(DMExtendedNotificationProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppDMExtendedNotificationProcInfo = 0x00000EC0
  }; /** pascal no_return_value Func(4_bytes, 2_bytes, 4_bytes) */
#ifdef __cplusplus
  inline DMExtendedNotificationUPP
  NewDMExtendedNotificationUPP(DMExtendedNotificationProcPtr userRoutine)
  {
    return (DMExtendedNotificationUPP)NewRoutineDescriptor(
        (ProcPtr)(userRoutine), uppDMExtendedNotificationProcInfo,
        GetCurrentArchitecture());
  }
#else
#define NewDMExtendedNotificationUPP(userRoutine)                \
  (DMExtendedNotificationUPP) NewRoutineDescriptor(              \
      (ProcPtr)(userRoutine), uppDMExtendedNotificationProcInfo, \
      GetCurrentArchitecture())
#endif
#endif

  /**
   *  NewDMComponentListIteratorUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  DMComponentListIteratorUPP
  NewDMComponentListIteratorUPP(DMComponentListIteratorProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppDMComponentListIteratorProcInfo = 0x00000FC0
  }; /** pascal no_return_value Func(4_bytes, 4_bytes, 4_bytes) */
#ifdef __cplusplus
  inline DMComponentListIteratorUPP
  NewDMComponentListIteratorUPP(DMComponentListIteratorProcPtr userRoutine)
  {
    return (DMComponentListIteratorUPP)NewRoutineDescriptor(
        (ProcPtr)(userRoutine), uppDMComponentListIteratorProcInfo,
        GetCurrentArchitecture());
  }
#else
#define NewDMComponentListIteratorUPP(userRoutine)                \
  (DMComponentListIteratorUPP) NewRoutineDescriptor(              \
      (ProcPtr)(userRoutine), uppDMComponentListIteratorProcInfo, \
      GetCurrentArchitecture())
#endif
#endif

  /**
   *  NewDMDisplayModeListIteratorUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  DMDisplayModeListIteratorUPP
  NewDMDisplayModeListIteratorUPP(DMDisplayModeListIteratorProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppDMDisplayModeListIteratorProcInfo = 0x00000FC0
  }; /** pascal no_return_value Func(4_bytes, 4_bytes, 4_bytes) */
#ifdef __cplusplus
  inline DMDisplayModeListIteratorUPP
  NewDMDisplayModeListIteratorUPP(DMDisplayModeListIteratorProcPtr userRoutine)
  {
    return (DMDisplayModeListIteratorUPP)NewRoutineDescriptor(
        (ProcPtr)(userRoutine), uppDMDisplayModeListIteratorProcInfo,
        GetCurrentArchitecture());
  }
#else
#define NewDMDisplayModeListIteratorUPP(userRoutine)                \
  (DMDisplayModeListIteratorUPP) NewRoutineDescriptor(              \
      (ProcPtr)(userRoutine), uppDMDisplayModeListIteratorProcInfo, \
      GetCurrentArchitecture())
#endif
#endif

  /**
   *  NewDMProfileListIteratorUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  DMProfileListIteratorUPP
  NewDMProfileListIteratorUPP(DMProfileListIteratorProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppDMProfileListIteratorProcInfo = 0x00000FC0
  }; /** pascal no_return_value Func(4_bytes, 4_bytes, 4_bytes) */
#ifdef __cplusplus
  inline DMProfileListIteratorUPP
  NewDMProfileListIteratorUPP(DMProfileListIteratorProcPtr userRoutine)
  {
    return (DMProfileListIteratorUPP)NewRoutineDescriptor(
        (ProcPtr)(userRoutine), uppDMProfileListIteratorProcInfo,
        GetCurrentArchitecture());
  }
#else
#define NewDMProfileListIteratorUPP(userRoutine)                \
  (DMProfileListIteratorUPP) NewRoutineDescriptor(              \
      (ProcPtr)(userRoutine), uppDMProfileListIteratorProcInfo, \
      GetCurrentArchitecture())
#endif
#endif

  /**
   *  NewDMDisplayListIteratorUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  DMDisplayListIteratorUPP
  NewDMDisplayListIteratorUPP(DMDisplayListIteratorProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppDMDisplayListIteratorProcInfo = 0x00000FC0
  }; /** pascal no_return_value Func(4_bytes, 4_bytes, 4_bytes) */
#ifdef __cplusplus
  inline DMDisplayListIteratorUPP
  NewDMDisplayListIteratorUPP(DMDisplayListIteratorProcPtr userRoutine)
  {
    return (DMDisplayListIteratorUPP)NewRoutineDescriptor(
        (ProcPtr)(userRoutine), uppDMDisplayListIteratorProcInfo,
        GetCurrentArchitecture());
  }
#else
#define NewDMDisplayListIteratorUPP(userRoutine)                \
  (DMDisplayListIteratorUPP) NewRoutineDescriptor(              \
      (ProcPtr)(userRoutine), uppDMDisplayListIteratorProcInfo, \
      GetCurrentArchitecture())
#endif
#endif

  /**
   *  DisposeDMNotificationUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeDMNotificationUPP(DMNotificationUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeDMNotificationUPP(DMNotificationUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeDMNotificationUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  DisposeDMExtendedNotificationUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeDMExtendedNotificationUPP(DMExtendedNotificationUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void
  DisposeDMExtendedNotificationUPP(DMExtendedNotificationUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeDMExtendedNotificationUPP(userUPP) \
  DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  DisposeDMComponentListIteratorUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeDMComponentListIteratorUPP(DMComponentListIteratorUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void
  DisposeDMComponentListIteratorUPP(DMComponentListIteratorUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeDMComponentListIteratorUPP(userUPP) \
  DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  DisposeDMDisplayModeListIteratorUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeDMDisplayModeListIteratorUPP(DMDisplayModeListIteratorUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void
  DisposeDMDisplayModeListIteratorUPP(DMDisplayModeListIteratorUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeDMDisplayModeListIteratorUPP(userUPP) \
  DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  DisposeDMProfileListIteratorUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeDMProfileListIteratorUPP(DMProfileListIteratorUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeDMProfileListIteratorUPP(DMProfileListIteratorUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeDMProfileListIteratorUPP(userUPP) \
  DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  DisposeDMDisplayListIteratorUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeDMDisplayListIteratorUPP(DMDisplayListIteratorUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeDMDisplayListIteratorUPP(DMDisplayListIteratorUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeDMDisplayListIteratorUPP(userUPP) \
  DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  InvokeDMNotificationUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  InvokeDMNotificationUPP(AppleEvent *theEvent, DMNotificationUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void InvokeDMNotificationUPP(AppleEvent *theEvent,
                                      DMNotificationUPP userUPP)
  {
    CALL_ONE_PARAMETER_UPP(userUPP, uppDMNotificationProcInfo, theEvent);
  }
#else
#define InvokeDMNotificationUPP(theEvent, userUPP) \
  CALL_ONE_PARAMETER_UPP((userUPP), uppDMNotificationProcInfo, (theEvent))
#endif
#endif

  /**
   *  InvokeDMExtendedNotificationUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  InvokeDMExtendedNotificationUPP(void *userData, short theMessage,
                                  void *notifyData,
                                  DMExtendedNotificationUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void InvokeDMExtendedNotificationUPP(void *userData, short theMessage,
                                              void *notifyData,
                                              DMExtendedNotificationUPP userUPP)
  {
    CALL_THREE_PARAMETER_UPP(userUPP, uppDMExtendedNotificationProcInfo, userData,
                             theMessage, notifyData);
  }
#else
#define InvokeDMExtendedNotificationUPP(userData, theMessage, notifyData, \
                                        userUPP)                          \
  CALL_THREE_PARAMETER_UPP((userUPP), uppDMExtendedNotificationProcInfo,  \
                           (userData), (theMessage), (notifyData))
#endif
#endif

  /**
   *  InvokeDMComponentListIteratorUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  InvokeDMComponentListIteratorUPP(void *userData, DMListIndexType itemIndex,
                                   DMComponentListEntryPtr componentInfo,
                                   DMComponentListIteratorUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void
  InvokeDMComponentListIteratorUPP(void *userData, DMListIndexType itemIndex,
                                   DMComponentListEntryPtr componentInfo,
                                   DMComponentListIteratorUPP userUPP)
  {
    CALL_THREE_PARAMETER_UPP(userUPP, uppDMComponentListIteratorProcInfo,
                             userData, itemIndex, componentInfo);
  }
#else
#define InvokeDMComponentListIteratorUPP(userData, itemIndex, componentInfo, \
                                         userUPP)                            \
  CALL_THREE_PARAMETER_UPP((userUPP), uppDMComponentListIteratorProcInfo,    \
                           (userData), (itemIndex), (componentInfo))
#endif
#endif

  /**
   *  InvokeDMDisplayModeListIteratorUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  InvokeDMDisplayModeListIteratorUPP(void *userData, DMListIndexType itemIndex,
                                     DMDisplayModeListEntryPtr displaymodeInfo,
                                     DMDisplayModeListIteratorUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void
  InvokeDMDisplayModeListIteratorUPP(void *userData, DMListIndexType itemIndex,
                                     DMDisplayModeListEntryPtr displaymodeInfo,
                                     DMDisplayModeListIteratorUPP userUPP)
  {
    CALL_THREE_PARAMETER_UPP(userUPP, uppDMDisplayModeListIteratorProcInfo,
                             userData, itemIndex, displaymodeInfo);
  }
#else
#define InvokeDMDisplayModeListIteratorUPP(userData, itemIndex,             \
                                           displaymodeInfo, userUPP)        \
  CALL_THREE_PARAMETER_UPP((userUPP), uppDMDisplayModeListIteratorProcInfo, \
                           (userData), (itemIndex), (displaymodeInfo))
#endif
#endif

  /**
   *  InvokeDMProfileListIteratorUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  InvokeDMProfileListIteratorUPP(void *userData, DMListIndexType itemIndex,
                                 DMProfileListEntryPtr profileInfo,
                                 DMProfileListIteratorUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void InvokeDMProfileListIteratorUPP(void *userData,
                                             DMListIndexType itemIndex,
                                             DMProfileListEntryPtr profileInfo,
                                             DMProfileListIteratorUPP userUPP)
  {
    CALL_THREE_PARAMETER_UPP(userUPP, uppDMProfileListIteratorProcInfo, userData,
                             itemIndex, profileInfo);
  }
#else
#define InvokeDMProfileListIteratorUPP(userData, itemIndex, profileInfo, \
                                       userUPP)                          \
  CALL_THREE_PARAMETER_UPP((userUPP), uppDMProfileListIteratorProcInfo,  \
                           (userData), (itemIndex), (profileInfo))
#endif
#endif

  /**
   *  InvokeDMDisplayListIteratorUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  InvokeDMDisplayListIteratorUPP(void *userData, DMListIndexType itemIndex,
                                 DisplayListEntryPtr displaymodeInfo,
                                 DMDisplayListIteratorUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void InvokeDMDisplayListIteratorUPP(void *userData,
                                             DMListIndexType itemIndex,
                                             DisplayListEntryPtr displaymodeInfo,
                                             DMDisplayListIteratorUPP userUPP)
  {
    CALL_THREE_PARAMETER_UPP(userUPP, uppDMDisplayListIteratorProcInfo, userData,
                             itemIndex, displaymodeInfo);
  }
#else
#define InvokeDMDisplayListIteratorUPP(userData, itemIndex, displaymodeInfo, \
                                       userUPP)                              \
  CALL_THREE_PARAMETER_UPP((userUPP), uppDMDisplayListIteratorProcInfo,      \
                           (userData), (itemIndex), (displaymodeInfo))
#endif
#endif

#if CALL_NOT_IN_CARBON || OLDROUTINENAMES
/** support for pre-Carbon UPP routines: New...Proc and Call...Proc */
#define NewDMNotificationProc(userRoutine) NewDMNotificationUPP(userRoutine)
#define NewDMExtendedNotificationProc(userRoutine) \
  NewDMExtendedNotificationUPP(userRoutine)
#define NewDMComponentListIteratorProc(userRoutine) \
  NewDMComponentListIteratorUPP(userRoutine)
#define NewDMDisplayModeListIteratorProc(userRoutine) \
  NewDMDisplayModeListIteratorUPP(userRoutine)
#define NewDMProfileListIteratorProc(userRoutine) \
  NewDMProfileListIteratorUPP(userRoutine)
#define NewDMDisplayListIteratorProc(userRoutine) \
  NewDMDisplayListIteratorUPP(userRoutine)
#define CallDMNotificationProc(userRoutine, theEvent) \
  InvokeDMNotificationUPP(theEvent, userRoutine)
#define CallDMExtendedNotificationProc(userRoutine, userData, theMessage, \
                                       notifyData)                        \
  InvokeDMExtendedNotificationUPP(userData, theMessage, notifyData, userRoutine)
#define CallDMComponentListIteratorProc(userRoutine, userData, itemIndex, \
                                        componentInfo)                    \
  InvokeDMComponentListIteratorUPP(userData, itemIndex, componentInfo,    \
                                   userRoutine)
#define CallDMDisplayModeListIteratorProc(userRoutine, userData, itemIndex, \
                                          displaymodeInfo)                  \
  InvokeDMDisplayModeListIteratorUPP(userData, itemIndex, displaymodeInfo,  \
                                     userRoutine)
#define CallDMProfileListIteratorProc(userRoutine, userData, itemIndex, \
                                      profileInfo)                      \
  InvokeDMProfileListIteratorUPP(userData, itemIndex, profileInfo, userRoutine)
#define CallDMDisplayListIteratorProc(userRoutine, userData, itemIndex, \
                                      displaymodeInfo)                  \
  InvokeDMDisplayListIteratorUPP(userData, itemIndex, displaymodeInfo,  \
                                 userRoutine)
#endif /** CALL_NOT_IN_CARBON */

#if CALL_NOT_IN_CARBON
  /**
   *  DMDisplayGestalt()
   *

   *    \non_carbon_cfm   in DisplayLib 2.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  DMDisplayGestalt(DisplayIDType theDisplayID, ResType displayGestaltSelector,
                   UInt32 *displayGestaltResponse);

  /**
   *  DMUseScreenPrefs()
   *

   *    \non_carbon_cfm   in DisplayLib 2.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  DMUseScreenPrefs(Boolean usePrefs, Handle displayState);

  /**
   *  DMSuspendConfigure()
   *

   *    \non_carbon_cfm   in DisplayLib 2.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  DMSuspendConfigure(Handle displayState, unsigned long reserved1);

  /**
   *  DMResumeConfigure()
   *

   *    \non_carbon_cfm   in DisplayLib 2.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  DMResumeConfigure(Handle displayState, unsigned long reserved1);

  /**
   *  DMSetGammaByAVID()
   *

   *    \non_carbon_cfm   in DisplayLib 2.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  DMSetGammaByAVID(AVIDType gammaAVID, UInt32 setGammaFlags,
                   GammaTblHandle theGamma);

  /**
   *  DMGetGammaByAVID()
   *

   *    \non_carbon_cfm   in DisplayLib 2.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  DMGetGammaByAVID(AVIDType gammaAVID, UInt32 getGammaFlags,
                   GammaTblHandle *theGamma);

  /**
   *  DMGetMakeAndModelByAVID()
   *

   *    \non_carbon_cfm   in DisplayLib 2.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  DMGetMakeAndModelByAVID(AVIDType theAVID, DMMakeAndModelPtr theMakeAndModel);

  /**
   *  DMNewDisplayList()
   *

   *    \non_carbon_cfm   in DisplayLib 2.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  DMNewDisplayList(UInt32 displayListIncludeFlags, UInt32 reserved1,
                   UInt32 reserved2, DMListIndexType *theCount,
                   DMListType *theDisplayList);

  /**
   *  DMGetIndexedDisplayFromList()
   *

   *    \non_carbon_cfm   in DisplayLib 2.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  DMGetIndexedDisplayFromList(DMListType theDisplayList,
                              DMListIndexType itemIndex, UInt32 reserved,
                              DMDisplayListIteratorUPP listIterator,
                              void *userData);

  /**
   *  DMNewProfileListByAVID()
   *

   *    \non_carbon_cfm   in DisplayLib 2.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  DMNewProfileListByAVID(AVIDType theAVID, UInt32 reserved,
                         DMListIndexType *profileCount, DMListType *profileList);

  /**
   *  DMGetIndexedProfileFromList()
   *

   *    \non_carbon_cfm   in DisplayLib 2.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  DMGetIndexedProfileFromList(DMListType profileList, DMListIndexType itemIndex,
                              UInt32 reserved,
                              DMProfileListIteratorUPP listIterator,
                              void *userData);

#endif /** CALL_NOT_IN_CARBON */

  /**
   *  DMGetFirstScreenDevice()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  GDHandle
  DMGetFirstScreenDevice(Boolean activeOnly);

  /**
   *  DMGetNextScreenDevice()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  GDHandle
  DMGetNextScreenDevice(GDHandle theDevice, Boolean activeOnly);

  /**
   *  DMDrawDesktopRect()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DMDrawDesktopRect(Rect *globalRect);

  /**
   *  DMDrawDesktopRegion()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DMDrawDesktopRegion(RgnHandle globalRgn);

  /**
   *  DMBeginConfigureDisplays()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  DMBeginConfigureDisplays(Handle *displayState);

  /**
   *  DMEndConfigureDisplays()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  DMEndConfigureDisplays(Handle displayState);

  /**
   *  DMAddDisplay()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  DMAddDisplay(GDHandle newDevice, short driver, unsigned long mode,
               unsigned long reserved, unsigned long displayID,
               Component displayComponent, Handle displayState);

  /**
   *  DMMoveDisplay()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  DMMoveDisplay(GDHandle moveDevice, short x, short y, Handle displayState);

  /**
   *  DMDisableDisplay()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  DMDisableDisplay(GDHandle disableDevice, Handle displayState);

  /**
   *  DMEnableDisplay()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  DMEnableDisplay(GDHandle enableDevice, Handle displayState);

  /**
   *  DMRemoveDisplay()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  DMRemoveDisplay(GDHandle removeDevice, Handle displayState);

  /**
   *  DMSetMainDisplay()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  DMSetMainDisplay(GDHandle newMainDevice, Handle displayState);

  /**
   *  DMSetDisplayMode()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  DMSetDisplayMode(GDHandle theDevice, unsigned long mode,
                   unsigned long *depthMode, unsigned long reserved,
                   Handle displayState);

  /**
   *  DMCheckDisplayMode()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  DMCheckDisplayMode(GDHandle theDevice, unsigned long mode,
                     unsigned long depthMode, unsigned long *switchFlags,
                     unsigned long reserved, Boolean *modeOk);

  /**
   *  DMGetDeskRegion()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  DMGetDeskRegion(RgnHandle *desktopRegion);

  /**
   *  DMRegisterNotifyProc()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  DMRegisterNotifyProc(DMNotificationUPP notificationProc,
                       DMProcessInfoPtr whichPSN);

  /**
   *  DMRemoveNotifyProc()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  DMRemoveNotifyProc(DMNotificationUPP notificationProc,
                     DMProcessInfoPtr whichPSN);

  /**
   *  DMQDIsMirroringCapable()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  DMQDIsMirroringCapable(Boolean *qdIsMirroringCapable);

  /**
   *  DMCanMirrorNow()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  DMCanMirrorNow(Boolean *canMirrorNow);

  /**
   *  DMIsMirroringOn()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  DMIsMirroringOn(Boolean *isMirroringOn);

  /**
   *  DMMirrorDevices()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  DMMirrorDevices(GDHandle gD1, GDHandle gD2, Handle displayState);

  /**
   *  DMUnmirrorDevice()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  DMUnmirrorDevice(GDHandle gDevice, Handle displayState);

  /**
   *  DMGetNextMirroredDevice()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  DMGetNextMirroredDevice(GDHandle gDevice, GDHandle *mirroredDevice);

  /**
   *  DMBlockMirroring()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  DMBlockMirroring(void);

  /**
   *  DMUnblockMirroring()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  DMUnblockMirroring(void);

#if CALL_NOT_IN_CARBON
  /**
   *  DMGetDisplayMgrA5World()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.5 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  DMGetDisplayMgrA5World(Ptr *dmA5);

#endif /** CALL_NOT_IN_CARBON */

  /**
   *  DMGetDisplayIDByGDevice()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  DMGetDisplayIDByGDevice(GDHandle displayDevice, DisplayIDType *displayID,
                          Boolean failToMain);

  /**
   *  DMGetGDeviceByDisplayID()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  DMGetGDeviceByDisplayID(DisplayIDType displayID, GDHandle *displayDevice,
                          Boolean failToMain);

  /**
   *  DMSetDisplayComponent()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  DMSetDisplayComponent(GDHandle theDevice, Component displayComponent);

  /**
   *  DMGetDisplayComponent()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  DMGetDisplayComponent(GDHandle theDevice, Component *displayComponent);

  /**
   *  DMNewDisplay()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  DMNewDisplay(GDHandle *newDevice, short driverRefNum, unsigned long mode,
               unsigned long reserved, DisplayIDType displayID,
               Component displayComponent, Handle displayState);

  /**
   *  DMDisposeDisplay()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  DMDisposeDisplay(GDHandle disposeDevice, Handle displayState);

  /**
   *  DMResolveDisplayComponents()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  DMResolveDisplayComponents(void);

  /**
   *  DMRegisterExtendedNotifyProc()
   *

   *    \non_carbon_cfm   in DisplayLib 2.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  DMRegisterExtendedNotifyProc(DMExtendedNotificationUPP notifyProc,
                               void *notifyUserData, unsigned short nofifyOnFlags,
                               DMProcessInfoPtr whichPSN);

  /**
   *  DMRemoveExtendedNotifyProc()
   *

   *    \non_carbon_cfm   in DisplayLib 2.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  DMRemoveExtendedNotifyProc(DMExtendedNotificationUPP notifyProc,
                             void *notifyUserData, DMProcessInfoPtr whichPSN,
                             unsigned short removeFlags);

  /**
   *  DMNewAVPanelList()
   *

   *    \non_carbon_cfm   in DisplayLib68k 2.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  DMNewAVPanelList(DisplayIDType displayID, ResType panelType,
                   DMFidelityType minimumFidelity, unsigned long panelListFlags,
                   unsigned long reserved, DMListIndexType *thePanelCount,
                   DMListType *thePanelList);

  /**
   *  DMNewAVEngineList()
   *

   *    \non_carbon_cfm   in DisplayLib68k 2.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  DMNewAVEngineList(DisplayIDType displayID, ResType engineType,
                    DMFidelityType minimumFidelity, unsigned long engineListFlags,
                    unsigned long reserved, DMListIndexType *engineCount,
                    DMListType *engineList);

  /**
   *  DMNewAVDeviceList()
   *

   *    \non_carbon_cfm   in DisplayLib68k 2.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  DMNewAVDeviceList(ResType deviceType, unsigned long deviceListFlags,
                    unsigned long reserved, DMListIndexType *deviceCount,
                    DMListType *deviceList);

  /**
   *  DMNewAVPortListByPortType()
   *

   *    \non_carbon_cfm   in DisplayLib68k 2.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  DMNewAVPortListByPortType(ResType subType, unsigned long portListFlags,
                            unsigned long reserved,
                            DMListIndexType *devicePortCount,
                            DMListType *theDevicePortList);

  /**
   *  DMGetIndexedComponentFromList()
   *

   *    \non_carbon_cfm   in DisplayLib68k 2.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  DMGetIndexedComponentFromList(DMListType panelList, DMListIndexType itemIndex,
                                unsigned long reserved,
                                DMComponentListIteratorUPP listIterator,
                                void *userData);

  /**
   *  DMDisposeList()
   *

   *    \non_carbon_cfm   in DisplayLib 2.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  DMDisposeList(DMListType panelList);

  /**
   *  DMGetNameByAVID()
   *

   *    \non_carbon_cfm   in DisplayLib68k 2.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  DMGetNameByAVID(AVIDType theID, unsigned long nameFlags, Str255 name);

  /**
   *  DMNewAVIDByPortComponent()
   *

   *    \non_carbon_cfm   in DisplayLib68k 2.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  DMNewAVIDByPortComponent(Component thePortComponent, ResType portKind,
                           unsigned long reserved, AVIDType *newID);

  /**
   *  DMGetPortComponentByAVID()
   *

   *    \non_carbon_cfm   in DisplayLib68k 2.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  DMGetPortComponentByAVID(DisplayIDType thePortID, Component *thePortComponent,
                           ComponentDescription *theDesciption,
                           ResType *thePortKind);

  /**
   *  DMSendDependentNotification()
   *

   *    \non_carbon_cfm   in DisplayLib 2.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  DMSendDependentNotification(ResType notifyType, ResType notifyClass,
                              AVIDType displayID,
                              ComponentInstance notifyComponent);

  /**
   *  DMDisposeAVComponent()
   *

   *    \non_carbon_cfm   in DisplayLib68k 2.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  DMDisposeAVComponent(Component theAVComponent);

  /**
   *  DMSaveScreenPrefs()
   *

   *    \non_carbon_cfm   in DisplayLib68k 2.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  DMSaveScreenPrefs(unsigned long reserved1, unsigned long saveFlags,
                    unsigned long reserved2);

  /**
   *  DMNewAVIDByDeviceComponent()
   *

   *    \non_carbon_cfm   in DisplayLib68k 2.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  DMNewAVIDByDeviceComponent(Component theDeviceComponent, ResType portKind,
                             unsigned long reserved, DisplayIDType *newID);

  /**
   *  DMNewAVPortListByDeviceAVID()
   *

   *    \non_carbon_cfm   in DisplayLib68k 2.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  DMNewAVPortListByDeviceAVID(AVIDType theID, DMFidelityType minimumFidelity,
                              unsigned long portListFlags, unsigned long reserved,
                              DMListIndexType *devicePortCount,
                              DMListType *theDevicePortList);

  /**
   *  DMGetDeviceComponentByAVID()
   *

   *    \non_carbon_cfm   in DisplayLib68k 2.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  DMGetDeviceComponentByAVID(AVIDType theDeviceID, Component *theDeviceComponent,
                             ComponentDescription *theDesciption,
                             ResType *theDeviceKind);

  /**
   *  DMNewDisplayModeList()
   *

   *    \non_carbon_cfm   in DisplayLib68k 2.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  DMNewDisplayModeList(DisplayIDType displayID, unsigned long modeListFlags,
                       unsigned long reserved, DMListIndexType *thePanelCount,
                       DMListType *thePanelList);

  /**
   *  DMGetIndexedDisplayModeFromList()
   *

   *    \non_carbon_cfm   in DisplayLib68k 2.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  DMGetIndexedDisplayModeFromList(DMListType panelList, DMListIndexType itemIndex,
                                  unsigned long reserved,
                                  DMDisplayModeListIteratorUPP listIterator,
                                  void *userData);

  /**
   *  DMGetGraphicInfoByAVID()
   *

   *    \non_carbon_cfm   in DisplayLib68k 2.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  DMGetGraphicInfoByAVID(AVIDType theID, PicHandle *theAVPcit,
                         Handle *theAVIconSuite, AVLocationRec *theAVLocation);

  /**
   *  DMGetAVPowerState()
   *

   *    \non_carbon_cfm   in DisplayLib68k 2.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  DMGetAVPowerState(AVIDType theID, AVPowerStatePtr getPowerState,
                    unsigned long reserved1);

  /**
   *  DMSetAVPowerState()
   *

   *    \non_carbon_cfm   in DisplayLib68k 2.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  DMSetAVPowerState(AVIDType theID, AVPowerStatePtr setPowerState,
                    unsigned long powerFlags, Handle displayState);

  /**
   *  DMGetDeviceAVIDByPortAVID()
   *

   *    \non_carbon_cfm   in DisplayLib68k 2.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  DMGetDeviceAVIDByPortAVID(AVIDType portAVID, AVIDType *deviceAVID);

  /**
   *  DMGetEnableByAVID()
   *

   *    \non_carbon_cfm   in DisplayLib68k 2.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  DMGetEnableByAVID(AVIDType theAVID, Boolean *isAVIDEnabledNow,
                    Boolean *canChangeEnableNow);

  /**
   *  DMSetEnableByAVID()
   *

   *    \non_carbon_cfm   in DisplayLib68k 2.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  DMSetEnableByAVID(AVIDType theAVID, Boolean doEnable, Handle displayState);

  /**
   *  DMGetDisplayMode()
   *

   *    \non_carbon_cfm   in DisplayLib68k 2.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  DMGetDisplayMode(GDHandle theDevice, VDSwitchInfoPtr switchInfo);

  /**
   *  DMConfirmConfiguration()
   *

   *    \non_carbon_cfm   in DisplayLib 2.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  DMConfirmConfiguration(DMModalFilterUPP filterProc, UInt32 confirmFlags,
                         UInt32 reserved, Handle displayState);

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

#endif /** __DISPLAYS__ */
