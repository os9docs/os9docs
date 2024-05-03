/**
     \file       Power.h

    \brief   Power Manager Interfaces.

    \introduced_in  Mac OS 9
    \avaliable_from Universal Interfaces 3.4.1

    \copyright © 1990-2001 by Apple Computer, Inc.  All rights reserved

    \ingroup Hardware

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __POWER__
#define __POWER__

#ifndef __MACTYPES__
#include <MacTypes.h>
#endif

#ifndef __MIXEDMODE__
#include <MixedMode.h>
#endif

#ifndef __MULTIPROCESSING__
#include <Multiprocessing.h>
#endif

#ifndef __NAMEREGISTRY__
#include <NameRegistry.h>
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

  enum
  {
    /* Bit positions for ModemByte */
    modemOnBit = 0,
    ringWakeUpBit = 2,
    modemInstalledBit = 3,
    ringDetectBit = 4,
    modemOnHookBit = 5
  };

  enum
  {
    /* masks for ModemByte */
    modemOnMask = 0x01,
    ringWakeUpMask = 0x04,
    modemInstalledMask = 0x08,
    ringDetectMask = 0x10,
    modemOnHookMask = 0x20
  };

  enum
  {
    /* bit positions for BatteryByte */
    chargerConnBit = 0,
    hiChargeBit = 1,
    chargeOverFlowBit = 2,
    batteryDeadBit = 3,
    batteryLowBit = 4,
    connChangedBit = 5
  };

  enum
  {
    /* masks for BatteryByte */
    chargerConnMask = 0x01,
    hiChargeMask = 0x02,
    chargeOverFlowMask = 0x04,
    batteryDeadMask = 0x08,
    batteryLowMask = 0x10,
    connChangedMask = 0x20
  };

  enum
  {
    /* bit positions for SoundMixerByte */
    MediaBaySndEnBit = 0,
    PCISndEnBit = 1,
    ZVSndEnBit = 2,
    PCCardSndEnBit = 3
  };

  enum
  {
    /* masks for SoundMixerByte */
    MediaBaySndEnMask = 0x01,
    PCISndEnMask = 0x02,
    ZVSndEnMask = 0x04,
    PCCardSndEnMask = 0x08
  };

  enum
  {
    /* commands to SleepQRec sleepQProc */
    kSleepRequest = 1,
    kSleepDemand = 2,
    kSleepWakeUp = 3,
    kSleepRevoke = 4,
    kSleepUnlock = 4,
    kSleepDeny = 5, /* A non-zero value clients can use to deny requests*/
    kSleepNow = 6,
    kDozeDemand = 7,
    kDozeWakeUp = 8,
    kDozeRequest = 9,   /* additional messages for Power Mgr 2.0*/
    kEnterStandby = 10, /* Idle Queue Only*/
    kEnterRun = 11,     /* Idle Queue Only*/
    kSuspendRequest = 12,
    kSuspendDemand = 13,
    kSuspendRevoke = 14,
    kSuspendWakeUp = 15,
    kGetPowerLevel = 16,
    kSetPowerLevel = 17,
    kDeviceInitiatedWake = 18,
    kWakeToDoze = 19,
    kDozeToFullWakeUp = 20,
    kGetPowerInfo = 21,
    kGetWakeOnNetInfo = 22,
    kSuspendWakeToDoze = 23,
    kEnterIdle = 24, /* Idle Queue Only*/
    kStillIdle = 25, /* Idle Queue Only*/
    kExitIdle = 26   /* Idle Queue Only*/
  };

  enum
  {
    /* depreciated commands to SleepQRec sleepQProc */
    sleepRequest = kSleepRequest,
    sleepDemand = kSleepDemand,
    sleepWakeUp = kSleepWakeUp,
    sleepRevoke = kSleepRevoke,
    sleepUnlock = kSleepUnlock,
    sleepDeny = kSleepDeny,
    sleepNow = kSleepNow,
    dozeDemand = kDozeDemand,
    dozeWakeUp = kDozeWakeUp,
    dozeRequest = kDozeRequest,
    enterStandby = kEnterStandby,
    enterRun = kEnterRun,
    suspendRequestMsg = kSuspendRequest,
    suspendDemandMsg = kSuspendDemand,
    suspendRevokeMsg = kSuspendRevoke,
    suspendWakeUpMsg = kSuspendWakeUp,
    getPowerLevel = kGetPowerLevel,
    setPowerLevel = kSetPowerLevel
  };

  /* Power Handler func messages */
  typedef UInt32 PowerLevel;
  /* Power levels corresponding to PCI Bus Power Management Interface Spec (PMIS)
   */
  enum
  {
    kPMDevicePowerLevel_On = 0, /* fully-powered 'On' state (D0 state)    */
    kPMDevicePowerLevel_D1 = 1, /* not used by Apple system SW         */
    kPMDevicePowerLevel_D2 = 2, /* not used by Apple system SW         */
    kPMDevicePowerLevel_Off = 3 /* main PCI bus power 'Off', but PCI standby power
                                   available (D3cold state) */
  };

  /* PowerHandlerProc definition */
  typedef CALLBACK_API(OSStatus, PowerHandlerProcPtr)(UInt32 message, void *param,
                                                      UInt32 refCon,
                                                      RegEntryID *regEntryID);
  typedef STACK_UPP_TYPE(PowerHandlerProcPtr) PowerHandlerUPP;
#if CALL_NOT_IN_CARBON
  /**
   *  NewPowerHandlerUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  PowerHandlerUPP
  NewPowerHandlerUPP(PowerHandlerProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppPowerHandlerProcInfo = 0x00003FF0
  }; /* pascal 4_bytes Func(4_bytes, 4_bytes, 4_bytes, 4_bytes) */
#ifdef __cplusplus
  inline PowerHandlerUPP NewPowerHandlerUPP(PowerHandlerProcPtr userRoutine)
  {
    return (PowerHandlerUPP)NewRoutineDescriptor((ProcPtr)(userRoutine),
                                                 uppPowerHandlerProcInfo,
                                                 GetCurrentArchitecture());
  }
#else
#define NewPowerHandlerUPP(userRoutine)                                     \
  (PowerHandlerUPP)                                                         \
      NewRoutineDescriptor((ProcPtr)(userRoutine), uppPowerHandlerProcInfo, \
                           GetCurrentArchitecture())
#endif
#endif

  /**
   *  DisposePowerHandlerUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  DisposePowerHandlerUPP(PowerHandlerUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposePowerHandlerUPP(PowerHandlerUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposePowerHandlerUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  InvokePowerHandlerUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  InvokePowerHandlerUPP(UInt32 message, void *param, UInt32 refCon,
                        RegEntryID *regEntryID, PowerHandlerUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline OSStatus InvokePowerHandlerUPP(UInt32 message, void *param,
                                        UInt32 refCon, RegEntryID *regEntryID,
                                        PowerHandlerUPP userUPP)
  {
    return (OSStatus)CALL_FOUR_PARAMETER_UPP(userUPP, uppPowerHandlerProcInfo,
                                             message, param, refCon, regEntryID);
  }
#else
#define InvokePowerHandlerUPP(message, param, refCon, regEntryID, userUPP)   \
  (OSStatus)                                                                 \
      CALL_FOUR_PARAMETER_UPP((userUPP), uppPowerHandlerProcInfo, (message), \
                              (param), (refCon), (regEntryID))
#endif
#endif

#endif /* CALL_NOT_IN_CARBON */

#if CALL_NOT_IN_CARBON || OLDROUTINENAMES
/* support for pre-Carbon UPP routines: New...Proc and Call...Proc */
#define NewPowerHandlerProc(userRoutine) NewPowerHandlerUPP(userRoutine)
#define CallPowerHandlerProc(userRoutine, message, param, refCon, regEntryID) \
  InvokePowerHandlerUPP(message, param, refCon, regEntryID, userRoutine)
#endif /* CALL_NOT_IN_CARBON */

/**
   Use kIdleQueueDeviceType as the deviceType argument to
   AddDevicePowerHandler() to get the handler into the idle queue instead of the
   device sleep queue.
*/
#define kIdleQueueDeviceType "idle-queue"
  /* PCI power management support*/

  enum
  {
    kUseDefaultMinimumWakeTime = 0, /* Defaults to 5 minutes*/
    kPowerSummaryVersion = 1,       /* Version of PowerSummary structure.*/
    kDevicePowerInfoVersion = 1     /* Version of DevicePowerInfo structure.*/
  };

  enum
  {
    /* PowerSummary flags*/
    kPCIPowerOffAllowed = (1L << 0) /* PCI power off is allowed.*/
  };

  enum
  {
    /* DevicePowerInfo flags*/
    kDevicePCIPowerOffAllowed =
        (1L << 0), /* PCI power off is allowed for device.*/
    kDeviceSupportsPMIS =
        (1L << 1), /* Device supports Power Mgt Interface Spec.*/
    kDeviceCanAssertPMEDuringSleep =
        (1L << 2),                           /* Device can assert PME# during sleep.*/
    kDeviceUsesCommonLogicPower = (1L << 3), /* Device uses common-logic power*/
    kDeviceDriverPresent = (1L << 4),        /* Driver present for device.*/
    kDeviceDriverSupportsPowerMgt =
        (1L << 5) /* Driver installed a power handler.*/
  };

  struct DevicePowerInfo
  {
    UInt32 version;          /* Version of this structure.*/
    RegEntryID regID;        /* RegEntryID for device.*/
    OptionBits flags;        /* Flags*/
    UInt32 minimumWakeTime;  /* Minimum seconds before sleeping again.*/
    UInt32 sleepPowerNeeded; /* Milliwatts needed in the sleep state.*/
  };
  typedef struct DevicePowerInfo DevicePowerInfo;
  struct PowerSummary
  {
    UInt32 version;             /* Version of this structure.*/
    OptionBits flags;           /* Flags*/
    UInt32 sleepPowerAvailable; /* Milliwatts available during sleep.*/
    UInt32 sleepPowerNeeded;    /* Milliwatts needed during sleep.*/
    UInt32 minimumWakeTime;     /* Minimum seconds before sleeping again.*/
    ItemCount deviceCount;      /* Number of device power info records.*/
    DevicePowerInfo devices[1]; /* Array of device power info records.*/
  };
  typedef struct PowerSummary PowerSummary;
  enum
  {
    /* SleepQRec.sleepQFlags */
    noCalls = 1,
    noRequest = 2,
    slpQType = 16,
    sleepQType = 16
  };

  /* Power Mgt Apple Event types and errors */
  enum
  {
    /* power mgt class*/
    kAEMacPowerMgtEvt = FOUR_CHAR_CODE('pmgt'), /* event ids*/
    kAEMacToWake = FOUR_CHAR_CODE('wake'),
    kAEMacLowPowerSaveData = FOUR_CHAR_CODE('pmsd'),
    kAEMacEmergencySleep = FOUR_CHAR_CODE('emsl'),
    kAEMacEmergencyShutdown = FOUR_CHAR_CODE('emsd')
  };

  /**
     These are result values returned by a Power Handler when queries
     by the Power Mgr if the device which that Power Handler represents
     woke the machine.
  */
  enum
  {
    kDeviceDidNotWakeMachine = 0, /* device did NOT wake machine*/
    kDeviceRequestsFullWake =
        1, /* device did wake machine and requests full wakeup*/
    kDeviceRequestsWakeToDoze =
        2 /* device did wake machine and requests partial wakeup*/
  };

  /* bits in bitfield returned by PMFeatures */
  enum
  {
    hasWakeupTimer = 0,      /* 1=wakeup timer is supported                    */
    hasSharedModemPort = 1,  /* 1=modem port shared by SCC and internal modem  */
    hasProcessorCycling = 2, /* 1=processor cycling is supported                */
    mustProcessorCycle = 3,  /* 1=processor cycling should not be turned off  */
    hasReducedSpeed = 4,     /* 1=processor can be started up at reduced speed     */
    dynamicSpeedChange = 5,  /* 1=processor speed can be switched dynamically  */
    hasSCSIDiskMode = 6,     /* 1=SCSI Disk Mode is supported                 */
    canGetBatteryTime = 7,   /* 1=battery time can be calculated                */
    canWakeupOnRing = 8,     /* 1=can wakeup when the modem detects a ring          */
    hasDimmingSupport =
        9,                      /* 1=has dimming support built in (DPMS standby by default)   */
    hasStartupTimer = 10,       /* 1=startup timer is supported                    */
    hasChargeNotification = 11, /* 1=client can determine of charge connect status
                                   change notifications available */
    hasDimSuspendSupport =
        12,                    /* 1=supports dimming LCD and CRT to DPMS suspend state     */
    hasWakeOnNetActivity = 13, /* 1=hardware supports wake on network activity */
    hasWakeOnLid = 14,         /* 1=hardware can wake when opened                   */
    canPowerOffPCIBus =
        15,            /* 1=hardware can power off PCI bus during sleep if cards allow */
    hasDeepSleep = 16, /* 1=hardware supports deep sleep (hibernation) mode   */
    hasSleep = 17,     /* 1=hardware supports normal (PowerBook-like) sleep   */
    supportsServerModeAPIs =
        18, /* 1=hardware supports server mode API routines          */
    supportsUPSIntegration =
        19, /* 1=hardware support UPS integration and reporting      */
    hasAggressiveIdling =
        20,                /* 1=Power Manager only resets OverallAct on UsrActvity     */
    supportsIdleQueue = 21 /* 1=Power Manager supports the idle queue */
  };

  /* bits in bitfield returned by GetIntModemInfo and set by SetIntModemState */
  enum
  {
    hasInternalModem = 0,    /* 1=internal modem installed               */
    intModemRingDetect = 1,  /* 1=internal modem has detected a ring          */
    intModemOffHook = 2,     /* 1=internal modem is off hook               */
    intModemRingWakeEnb = 3, /* 1=wakeup on ring is enabled                 */
    extModemSelected = 4,    /* 1=external modem selected             */
    modemSetBit = 15         /* 1=set bit, 0=clear bit (SetIntModemState)   */
  };

  /* bits in BatteryInfo.flags                                    */
  /* ("chargerConnected" doesn't mean the charger is plugged in)  */
  enum
  {
    batteryInstalled = 7, /* 1=battery is currently connected             */
    batteryCharging = 6,  /* 1=battery is being charged               */
    chargerConnected = 5, /* 1=charger is connected to the PowerBook         */
    upsConnected = 4,     /* 1=there is a UPS connected               */
    upsIsPowerSource = 3  /* 1=UPS is source of power                */
  };

  enum
  {
    HDPwrQType = 0x4844,    /* 'HD' hard disk spindown queue element type     */
    PMgrStateQType = 0x504D /* 'PM' Power Manager state queue element type */
  };

  /* client notification bits in PMgrQueueElement.pmNotifyBits */
  enum
  {
    pmSleepTimeoutChanged = 0,
    pmSleepEnableChanged = 1,
    pmHardDiskTimeoutChanged = 2,
    pmHardDiskSpindownChanged = 3,
    pmDimmingTimeoutChanged = 4,
    pmDimmingEnableChanged = 5,
    pmDiskModeAddressChanged = 6,
    pmProcessorCyclingChanged = 7,
    pmProcessorSpeedChanged = 8,
    pmWakeupTimerChanged = 9,
    pmStartupTimerChanged = 10,
    pmHardDiskPowerRemovedbyUser = 11,
    pmChargeStatusChanged = 12,
    pmPowerLevelChanged = 13,
    pmWakeOnNetActivityChanged = 14
  };

  enum
  {
    pmSleepTimeoutChangedMask = (1 << pmSleepTimeoutChanged),
    pmSleepEnableChangedMask = (1 << pmSleepEnableChanged),
    pmHardDiskTimeoutChangedMask = (1 << pmHardDiskTimeoutChanged),
    pmHardDiskSpindownChangedMask = (1 << pmHardDiskSpindownChanged),
    pmDimmingTimeoutChangedMask = (1 << pmDimmingTimeoutChanged),
    pmDimmingEnableChangedMask = (1 << pmDimmingEnableChanged),
    pmDiskModeAddressChangedMask = (1 << pmDiskModeAddressChanged),
    pmProcessorCyclingChangedMask = (1 << pmProcessorCyclingChanged),
    pmProcessorSpeedChangedMask = (1 << pmProcessorSpeedChanged),
    pmWakeupTimerChangedMask = (1 << pmWakeupTimerChanged),
    pmStartupTimerChangedMask = (1 << pmStartupTimerChanged),
    pmHardDiskPowerRemovedbyUserMask = (1 << pmHardDiskPowerRemovedbyUser),
    pmChargeStatusChangedMask = (1 << pmChargeStatusChanged),
    pmPowerLevelChangedMask = (1 << pmPowerLevelChanged),
    pmWakeOnNetActivityChangedMask = (1 << pmWakeOnNetActivityChanged)
  };

  /* System Activity Selectors */
  /* Notes:  The IdleActivity selector is not available unless the
   * hasAggressiveIdling PMFeatures bit is set. */
  /*         Use IdleActivity where you used to use OverallAct if necessary.
   * OverallAct will only            */
  /*         delay power cycling if it's enabled, and will delay sleep by a small
   * amount when                 */
  /*         hasAggressiveIdling is set.  Don't use IdleActivity unless
   * hasAggressiveIdling is set; when      */
  /*         hasAggressiveIdling is not set, the use of IdleActivity is undefined,
   * and well do different      */
  /*         things depending on which Power Manager is currently running. */
  enum
  {
    OverallAct = 0,  /* Delays idle sleep by small amount                 */
    UsrActivity = 1, /* Delays idle sleep and dimming by timeout time          */
    NetActivity = 2, /* Delays idle sleep and power cycling by small amount */
    HDActivity =
        3,           /* Delays hard drive spindown and idle sleep by small amount  */
    IdleActivity = 4 /* Delays idle sleep by timeout time                 */
  };

  /* Storage Media sleep mode defines */
  enum
  {
    kMediaModeOn = 0,      /* Media active (Drive spinning and at full power)    */
    kMediaModeStandBy = 1, /* Media standby (not implemented)    */
    kMediaModeSuspend = 2, /* Media Idle (not implemented)   */
    kMediaModeOff = 3      /* Media Sleep (Drive not spinning and at min power, max
                              recovery time)   */
  };

  enum
  {
    kMediaPowerCSCode = 70
  };

  /* definitions for HDQueueElement.hdFlags   */
  enum
  {
    kHDQueuePostBit = 0, /* 1 = call this routine on the second pass     */
    kHDQueuePostMask = (1 << kHDQueuePostBit)
  };

  struct ActivityInfo
  {
    short ActivityType; /* Type of activity to be fetched.  Same as
                           UpdateSystemActivity Selectors */
    unsigned long
        ActivityTime; /* Time of last activity (in ticks) of specified type. */
  };
  typedef struct ActivityInfo ActivityInfo;
  /* information returned by GetScaledBatteryInfo */
  struct BatteryInfo
  {
    UInt8 flags;        /* misc flags (see below)                  */
    UInt8 warningLevel; /* scaled warning level (0-255)               */
    UInt8 reserved;     /* reserved for internal use             */
    UInt8 batteryLevel; /* scaled battery level (0-255)               */
  };
  typedef struct BatteryInfo BatteryInfo;

  typedef SInt8 ModemByte;
  typedef SInt8 BatteryByte;
  typedef SInt8 SoundMixerByte;
  typedef long PMResultCode;
  typedef struct SleepQRec SleepQRec;
  typedef SleepQRec *SleepQRecPtr;
  typedef struct HDQueueElement HDQueueElement;
  typedef struct PMgrQueueElement PMgrQueueElement;
  typedef CALLBACK_API_REGISTER68K(long, SleepQProcPtr,
                                   (long message, SleepQRecPtr qRecPtr));
  typedef CALLBACK_API(void, HDSpindownProcPtr)(HDQueueElement *theElement);
  typedef CALLBACK_API(void, PMgrStateChangeProcPtr)(PMgrQueueElement *theElement,
                                                     long stateBits);
  typedef REGISTER_UPP_TYPE(SleepQProcPtr) SleepQUPP;
  typedef STACK_UPP_TYPE(HDSpindownProcPtr) HDSpindownUPP;
  typedef STACK_UPP_TYPE(PMgrStateChangeProcPtr) PMgrStateChangeUPP;
  struct SleepQRec
  {
    SleepQRecPtr sleepQLink; /* pointer to next queue element          */
    short sleepQType;        /* queue element type (must be SleepQType)       */
    SleepQUPP sleepQProc;    /* pointer to sleep universal proc ptr         */
    short sleepQFlags;       /* flags                       */
  };

  struct HDQueueElement
  {
    struct HDQueueElement *hdQLink; /* pointer to next queue element          */
    short hdQType;                  /* queue element type (must be HDPwrQType)       */
    short hdFlags;                  /* miscellaneous flags                   */
    HDSpindownUPP hdProc;           /* pointer to routine to call           */
    long hdUser;                    /* user-defined (variable storage, etc.)   */
  };

  struct PMgrQueueElement
  {
    struct PMgrQueueElement *pmQLink; /* pointer to next queue element          */
    short pmQType;                    /* queue element type (must be PMgrStateQType)    */
    short pmFlags;                    /* miscellaneous flags                   */
    long pmNotifyBits;                /* bitmap of which changes to be notified for */
    PMgrStateChangeUPP pmProc;        /* pointer to routine to call           */
    long pmUser;                      /* user-defined (variable storage, etc.)   */
  };

  struct BatteryTimeRec
  {
    unsigned long
        expectedBatteryTime; /* estimated battery time remaining (seconds) */
    unsigned long
        minimumBatteryTime; /* minimum battery time remaining (seconds)     */
    unsigned long
        maximumBatteryTime; /* maximum battery time remaining (seconds)     */
    unsigned long
        timeUntilCharged; /* time until battery is fully charged (seconds)*/
  };
  typedef struct BatteryTimeRec BatteryTimeRec;

  struct WakeupTime
  {
    unsigned long wakeTime; /* wakeup time (same format as current time)   */
    Boolean wakeEnabled;    /* 1=enable wakeup timer, 0=disable wakeup timer  */
    SInt8 filler;
  };
  typedef struct WakeupTime WakeupTime;

  struct StartupTime
  {
    unsigned long startTime; /* startup time (same format as current time)     */
    Boolean startEnabled;    /* 1=enable startup timer, 0=disable startup timer    */
    SInt8 filler;
  };
  typedef struct StartupTime StartupTime;
  /* PowerSource version*/
  enum
  {
    kVersionOnePowerSource = 1,
    kVersionTwoPowerSource = 2,
    kCurrentPowerSourceVersion = kVersionTwoPowerSource
  };

  /* PowerSourceAttrs bits*/

  enum
  {
    bSourceIsBattery = 0,    /* power source is battery*/
    bSourceIsAC = 1,         /* power source is AC*/
    bSourceCanBeCharged = 2, /* power source can be charged*/
    bSourceIsUPS = 3,        /* power source is UPS. NOTE: software should set
                                bSourceIsBattery and bSourceIsAC also, as appropriate*/
    bSourceProvidesWarnLevels =
        4, /* power source provides low power and dead battery warning levels*/
    kSourceIsBatteryMask = (1 << bSourceIsBattery),
    kSourceIsACMask = (1 << bSourceIsAC),
    kSourceCanBeChargedMask = (1 << bSourceCanBeCharged),
    kSourceIsUPSMask = (1 << bSourceIsUPS),
    kSourceProvidesWarnLevelsMask = (1 << bSourceProvidesWarnLevels)
  };

  /* PowerSourceFlags bits*/

  enum
  {
    bSourceIsAvailable = 0, /* power source is installed*/
    bSourceIsCharging = 1,  /* power source being charged*/
    bChargerIsAttached = 2, /* a charger is connected*/
    kSourceIsAvailableMask = (1 << bSourceIsAvailable),
    kSourceIsChargingMask = (1 << bSourceIsCharging),
    kChargerIsAttachedMask = (1 << bChargerIsAttached)
  };

  /* Power Capacity Types*/

  enum
  {
    kCapacityIsActual = 0, /* current capacity is expessed as actual capacity in
                              same units as max*/
    kCapacityIsPercentOfMax =
        1 /* current capacity is expressed as a percentage of maximumCapacity*/
  };

  /* Net Activity Wake Options*/
  enum
  {
    kConfigSupportsWakeOnNetBit = 0,
    kWakeOnNetAdminAccessesBit = 1,
    kWakeOnAllNetAccessesBit = 2,
    kUnmountServersBeforeSleepingBit = 3,
    kConfigSupportsWakeOnNetMask = (1 << kConfigSupportsWakeOnNetBit),
    kWakeOnNetAdminAccessesMask = (1 << kWakeOnNetAdminAccessesBit),
    kWakeOnAllNetAccessesMask = (1 << kWakeOnAllNetAccessesBit),
    kUnmountServersBeforeSleepingMask = (1 << kUnmountServersBeforeSleepingBit)
  };

  /* Power Source capacity usage types*/
  enum
  {
    kCurrentCapacityIsActualValue =
        0, /* currentCapacity is a real value in same units as maxCapacity*/
    kCurrentCapacityIsPercentOfMax =
        1 /* currentCapacity is expressed as a percentage of maxCapacity.*/
  };

  typedef SInt16 PowerSourceID;
  struct PowerSourceParamBlock
  {
    PowerSourceID sourceID;     /* unique id assigned by Power Mgr*/
    UInt16 sourceCapacityUsage; /* how currentCapacity is used*/
    UInt32 sourceVersion;       /* version of this record*/
    OptionBits sourceAttr;      /* attribute flags (see below)*/
    OptionBits sourceState;     /* state flags (see below)*/
    UInt32 currentCapacity;     /* current capacity, in*/
                                /*   milliwatts or %*/
    UInt32 maxCapacity;         /* full capacity, in milliwatts*/
    UInt32 timeRemaining;       /* time left to deplete, */
                                /*   in milliwatt-hours*/
    UInt32 timeToFullCharge;    /* time to charge, */
                                /*   in milliwatt-hours*/
    UInt32 voltage;             /* voltage in millivolts*/
    SInt32 current;             /* current in milliamperes */
                                /*  (negative if consuming, */
                                /*   positive if charging)*/
    UInt32 lowWarnLevel;        /* low warning level in milliwatts (or % if
                                   sourceCapacityUsage is %)*/
    UInt32 deadWarnLevel;       /* dead warning level in milliwatts (or % if
                                   sourceCapacityUsage is %)*/
    UInt32 reserved[16];        /* for future expansion*/
  };
  typedef struct PowerSourceParamBlock PowerSourceParamBlock;
  typedef PowerSourceParamBlock *PowerSourceParamBlockPtr;

  /**
  \brief Disable the wakeup timer

  <pre>The DisableWUTime function disables the wakeup timer. You must set a
new wakeup time to reenable the wakeup timer.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
  OSErr
  DisableWUTime(void);

  /**
  \brief Set and enable the wakeup timer

  <pre>The SetWUTime function sets and enables the wakeup timer. When the
Macintosh Portable computer is in the sleep state, the Power Manager
updates the real-time clock and compares it to the wakeup timer once each
second. When the real-time clock and the wakeup timer have the same setting,
the Power Manager returns the Macintosh Portable to the operating state.
The WUTime parameter specifies the time at which the Power Manager
will return the Macintosh Portable to the operating state. You specify the time
as the number of seconds since midnight, January 1, 1904.
If the Macintosh Portable is not in the sleep state when the wakeup timer and
the real-time clock settings coincide, nothing happens. If you set the wakeup
timer to a time earlier than the current setting of the real-time clock, you
effectively disable the wakeup timer.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
  OSErr
  SetWUTime(long wuTime);

  /**
  \brief Get the current wakeup time settings

  <pre>The GetWUTime function returns the current setting of the wakeup timer
and indicates whether the wakeup timer is enabled.
The value returned by the WUTime parameter is the current setting of the
wakeup timer specified as the number of seconds since midnight, January 1,
1904. If the low-order bit (bit 0) of the WUFlag parameter is set to 1, the
wakeup timer is enabled. The other bits in the WUFlag parameter are reserved.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
  OSErr
  GetWUTime(long *wuTime, Byte *wuFlag);

  /**
  \brief Get status of battery charger and voltage level

  <pre>The BatteryStatus function returns the status of the battery charger and
the voltage level of the battery. The bits in the Status parameter are defined as
follows:
BitMeaning
7Reserved.
6Reserved.
5The charger connection has or has not changed state. If 1, the charger
has been recently connected or disconnected.
4The battery warning. If 1, the battery voltage is low.
3The dead battery indicator. This bit is always 0.
2The hicharge counter overflow. If 1, the hicharge counter has
overflowed.
1The charge rate. If 1, the battery is charging at the hicharge rate.
0The charger is or is not connected. If 1, the charger is connected.
The Power Manager monitors the voltage level of the internal battery and
warns the user when the voltage drops below a threshold value stored in
parameter RAM. If the voltage continues to drop and falls below another, lower
value stored in parameter RAM, the Power Manager puts the computer into
the sleep state. The Power Manager provides a function that allows you to
read the state of charge of the battery and the status of the battery charger.
You can use the constants shown Power Mgr Data to check the values of
these bits.
Use the following formula to calculate the battery voltage, where Power is
the value of the Power parameter returned by this function:
voltage = ((Power/100) + 5.12) volts
Due to the nature of lead-acid batteries, the battery power remaining is
difficult to measure accurately. Temperature, load, and other factors can alter
the measured voltage by 30 percent or more. The Power Manager takes as
many of these factors into account as possible, but the voltage measurement can
still be in error by up to 10 percent. The measurement is most accurate when
the Macintosh Portable has been in the sleep state for at least 30 minutes.
When the battery charger is connected to a Macintosh Portable computer with
a low battery, the battery is charged at the hicharge rate (1.5 amps) until
battery voltage reaches 7.2 volts. The Power Manager has a counter (the
hicharge counter ) that measures the time required to raise the battery
voltage to this level.
After the 7.2 volt level is reached, the power management circuits maintain
the hicharge connection until the hicharge counter counts down to 0. This
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
  OSErr
  BatteryStatus(Byte *status, Byte *power);

  /**
  \brief Get information about Mac Portable internal modem

  <pre>The ModemStatus function returns information about the internal modem in
the Macintosh Portable computer.
The bits in the Status parameter are defined as follows:
BitMeaning
7Reserved.
6Reserved.
5The modem is on or off hook. If 1, the modem is off hook.
4The ring-detect state. If 1, the modem has detected an incoming call.
3The modem is or is not installed. If 1, an internal modem is installed.
2The state of the ring-wakeup feature. If 1, the ring-wakeup feature
is enabled.
1Reserved; must always be set to 1.
0The modem's power is on or off. If 1, the modem is switched on.
You can use the constants shown in Power Mgr Data to check the values of
these bits.
The user can use the Portable control panel to enable or disable the
ring-wakeup feature. When the ring-wakeup feature is enabled and the
Macintosh Portable is in the sleep state, the Power Manager returns the
computer to the operating state when the modem receives an incoming call.
You can use the serial power control functions described in
Switching Serial Power On and Off to control power to the modem.
The modem indicates that it is off hook whenever it is busy sending or
receiving data or processing commands. The modem cannot receive an incoming
call when it is off hook.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
  OSErr
  ModemStatus(Byte *status);

  /**
  \brief Reset the activity timer

  <pre>IdleUpdate is equivalent to the expression tickCount = Ticks;
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 IdleUpdate
#endif
  long
  IdleUpdate(void);

  /**
  \brief Return the current effective clock speed of the CPU

  <pre>The GetCPUSpeed function returns the current effective clock speed of the
CPU. The only values that are returned by this function are 1 and 16,
indicating the clock speed in megahertz.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 GetCPUSpeed
#endif
  long
  GetCPUSpeed(void);

  /**
  \brief Enable the Idle state

  <pre>The EnableIdle procedure cancels the effect of a call to the DisableIdle
procedure. A call to the EnableIdle procedure enables the idle state only if the
user has not used the Portable control panel to disable the idle state and if
every call to the DisableIdle procedure has been balanced by a call to the
EnableIdle procedure.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
  void
  EnableIdle(void);

  /**
  \brief Disable the Idle state

  <pre>The DisableIdle procedure disables the idle state, even if the user has used
the Portable control panel to enable the idle state. Every call to the
DisableIdle procedure must be balanced by a call to the EnableIdle
procedure before the idle state is reenabled.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
  void
  DisableIdle(void);

  /**
  \brief Add an entry to the sleep queue

  <pre>You can use the SleepQInstall procedure to add an entry to the sleep queue,
and you can use the SleepQRemove procedure to remove an entry from the
sleep queue.
The qRecPtr parameter is a pointer to a sleep queue record that you must
provide.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter SleepQInstall(__A0)
#endif
  void
  SleepQInstall(SleepQRecPtr qRecPtr);

  /**
  \brief Remove an entry from the sleep queue

  <pre>You can use the SleepQRemove procedure to remove an entry from the sleep
queue and you can use the SleepQInstall procedure to add an entry to the
sleep queue.
The qRecPtr parameter is a pointer to the sleep queue record that you
provided when you added your routine to the sleep queue.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter SleepQRemove(__A0)
#endif
  void
  SleepQRemove(SleepQRecPtr qRecPtr);

  /**
  \brief Switch on power to the SCC and the -5 volt supply

  <pre>The AOn procedure always switches on power to the SCC and the -5 volt
supply. If the internal modem is installed and is connected to port A, this
procedure also switches on power to the modem. If either of these conditions is
not met, the AOn procedure switches on power to the serial driver chips.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
  void
  AOn(void);

  /**
  \brief Switch on power to SCC, -5 volt supply and serial driver chips

  <pre>The AOnIgnoreModem procedure switches on power to the SCC, the -5 volt
supply, and the serial driver chips. This procedure does not switch on power to
the internal modem, even if the user has used the Portable control panel to
select the modem.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
  void
  AOnIgnoreModem(void);

  /**
  \brief Switch on power to SCC, -5 volt supply and serial driver chips

  <pre>The BOn procedure always switches on power to the SCC, the -5 volt supply,
and the serial driver chips.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
  void
  BOn(void);

  /**
  \brief Switch off power to SCC and -5 volt supply if portB not in use

  <pre>The AOff procedure always switches off power to the SCC and the -5 volt
supply if serial port B is not in use. If the internal modem is installed,
connected to port A, and switched on, this procedure switches off power to the
modem. If any of these conditions are not met, it switches off power to the serial
driver chips, unless they are being used by port B.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
  void
  AOff(void);

  /**
  \brief Switch off power to SCC and -5 volt supply if portA not in use

  <pre>The BOff procedure switches off power to the SCC and the -5 volt supply if
serial port A is not in use. If the internal modem is installed, connected to port
B, and switched on, this procedure switches off power to the modem. Otherwise,
the BOff procedure switches off power to the serial driver chips, unless they
are being used by port A.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
  void
  BOff(void);

/* Public Power Management API  */
/**
 *  PMSelectorCount()
 *

 *    \non_carbon_cfm   in PowerMgrLib 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PMSelectorCount
#endif
  short
  PMSelectorCount(void);

/**
 *  PMFeatures()
 *

 *    \non_carbon_cfm   in PowerMgrLib 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PMFeatures
#endif
  UInt32
  PMFeatures(void);

/**
 *  GetSleepTimeout()
 *

 *    \non_carbon_cfm   in PowerMgrLib 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 GetSleepTimeout
#endif
  UInt8
  GetSleepTimeout(void);

/**
 *  SetSleepTimeout()
 *

 *    \non_carbon_cfm   in PowerMgrLib 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter SetSleepTimeout(__D0)
#endif
  void
  SetSleepTimeout(UInt8 timeout);

/**
 *  GetHardDiskTimeout()
 *

 *    \non_carbon_cfm   in PowerMgrLib 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 GetHardDiskTimeout
#endif
  UInt8
  GetHardDiskTimeout(void);

/**
 *  SetHardDiskTimeout()
 *

 *    \non_carbon_cfm   in PowerMgrLib 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter SetHardDiskTimeout(__D0)
#endif
  void
  SetHardDiskTimeout(UInt8 timeout);

/**
 *  HardDiskPowered()
 *

 *    \non_carbon_cfm   in PowerMgrLib 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 HardDiskPowered
#endif
  Boolean
  HardDiskPowered(void);

/**
 *  SpinDownHardDisk()
 *

 *    \non_carbon_cfm   in PowerMgrLib 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter SpinDownHardDisk
#endif
  void
  SpinDownHardDisk(void);

/**
 *  IsSpindownDisabled()
 *

 *    \non_carbon_cfm   in PowerMgrLib 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 IsSpindownDisabled
#endif
  Boolean
  IsSpindownDisabled(void);

/**
 *  SetSpindownDisable()
 *

 *    \non_carbon_cfm   in PowerMgrLib 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter SetSpindownDisable(__D0)
#endif
  void
  SetSpindownDisable(Boolean setDisable);

/**
 *  HardDiskQInstall()
 *

 *    \non_carbon_cfm   in PowerMgrLib 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 HardDiskQInstall(__A0)
#endif
  OSErr
  HardDiskQInstall(HDQueueElement *theElement);

/**
 *  HardDiskQRemove()
 *

 *    \non_carbon_cfm   in PowerMgrLib 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 HardDiskQRemove(__A0)
#endif
  OSErr
  HardDiskQRemove(HDQueueElement *theElement);

/**
 *  GetScaledBatteryInfo()
 *

 *    \non_carbon_cfm   in PowerMgrLib 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter GetScaledBatteryInfo(__D0, __A0)
#endif
  void
  GetScaledBatteryInfo(short whichBattery, BatteryInfo *theInfo);

/**
 *  AutoSleepControl()
 *

 *    \non_carbon_cfm   in PowerMgrLib 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter AutoSleepControl(__D0)
#endif
  void
  AutoSleepControl(Boolean enableSleep);

/**
 *  GetIntModemInfo()
 *

 *    \non_carbon_cfm   in PowerMgrLib 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 GetIntModemInfo
#endif
  UInt32
  GetIntModemInfo(void);

/**
 *  SetIntModemState()
 *

 *    \non_carbon_cfm   in PowerMgrLib 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter SetIntModemState(__D0)
#endif
  void
  SetIntModemState(short theState);

/**
 *  MaximumProcessorSpeed()
 *

 *    \non_carbon_cfm   in PowerMgrLib 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 MaximumProcessorSpeed
#endif
  short
  MaximumProcessorSpeed(void);

/**
 *  MinimumProcessorSpeed()
 *

 *    \non_carbon_cfm   in PowerMgrLib 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 MinimumProcessorSpeed
#endif
  short
  MinimumProcessorSpeed(void);

/**
 *  CurrentProcessorSpeed()
 *

 *    \non_carbon_cfm   in PowerMgrLib 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 CurrentProcessorSpeed
#endif
  short
  CurrentProcessorSpeed(void);

/**
 *  FullProcessorSpeed()
 *

 *    \non_carbon_cfm   in PowerMgrLib 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 FullProcessorSpeed
#endif
  Boolean
  FullProcessorSpeed(void);

/**
 *  SetProcessorSpeed()
 *

 *    \non_carbon_cfm   in PowerMgrLib 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 SetProcessorSpeed(__D0)
#endif
  Boolean
  SetProcessorSpeed(Boolean fullSpeed);

/**
 *  GetSCSIDiskModeAddress()
 *

 *    \non_carbon_cfm   in PowerMgrLib 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 GetSCSIDiskModeAddress
#endif
  short
  GetSCSIDiskModeAddress(void);

/**
 *  SetSCSIDiskModeAddress()
 *

 *    \non_carbon_cfm   in PowerMgrLib 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter SetSCSIDiskModeAddress(__D0)
#endif
  void
  SetSCSIDiskModeAddress(short scsiAddress);

/**
 *  GetWakeupTimer()
 *

 *    \non_carbon_cfm   in PowerMgrLib 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter GetWakeupTimer(__A0)
#endif
  void
  GetWakeupTimer(WakeupTime *theTime);

/**
 *  SetWakeupTimer()
 *

 *    \non_carbon_cfm   in PowerMgrLib 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter SetWakeupTimer(__A0)
#endif
  void
  SetWakeupTimer(WakeupTime *theTime);

/**
 *  IsProcessorCyclingEnabled()
 *

 *    \non_carbon_cfm   in PowerMgrLib 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 IsProcessorCyclingEnabled
#endif
  Boolean
  IsProcessorCyclingEnabled(void);

/**
 *  EnableProcessorCycling()
 *

 *    \non_carbon_cfm   in PowerMgrLib 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter EnableProcessorCycling(__D0)
#endif
  void
  EnableProcessorCycling(Boolean enable);

/**
 *  BatteryCount()
 *

 *    \non_carbon_cfm   in PowerMgrLib 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 BatteryCount
#endif
  short
  BatteryCount(void);

/**
 *  GetBatteryVoltage()
 *

 *    \non_carbon_cfm   in PowerMgrLib 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 GetBatteryVoltage(__D0)
#endif
  Fixed
  GetBatteryVoltage(short whichBattery);

/**
 *  GetBatteryTimes()
 *

 *    \non_carbon_cfm   in PowerMgrLib 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter GetBatteryTimes(__D0, __A0)
#endif
  void
  GetBatteryTimes(short whichBattery, BatteryTimeRec *theTimes);

/**
 *  GetDimmingTimeout()
 *

 *    \non_carbon_cfm   in PowerMgrLib 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 GetDimmingTimeout
#endif
  UInt8
  GetDimmingTimeout(void);

/**
 *  SetDimmingTimeout()
 *

 *    \non_carbon_cfm   in PowerMgrLib 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter SetDimmingTimeout(__D0)
#endif
  void
  SetDimmingTimeout(UInt8 timeout);

/**
 *  DimmingControl()
 *

 *    \non_carbon_cfm   in PowerMgrLib 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter DimmingControl(__D0)
#endif
  void
  DimmingControl(Boolean enableSleep);

/**
 *  IsDimmingControlDisabled()
 *

 *    \non_carbon_cfm   in PowerMgrLib 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 IsDimmingControlDisabled
#endif
  Boolean
  IsDimmingControlDisabled(void);

/**
 *  IsAutoSlpControlDisabled()
 *

 *    \non_carbon_cfm   in PowerMgrLib 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 IsAutoSlpControlDisabled
#endif
  Boolean
  IsAutoSlpControlDisabled(void);

/**
 *  PMgrStateQInstall()
 *

 *    \non_carbon_cfm   in PowerMgrLib 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PMgrStateQInstall(__A0)
#endif
  OSErr
  PMgrStateQInstall(PMgrQueueElement *theElement);

/**
 *  PMgrStateQRemove()
 *

 *    \non_carbon_cfm   in PowerMgrLib 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 PMgrStateQRemove(__A0)
#endif
  OSErr
  PMgrStateQRemove(PMgrQueueElement *theElement);

/**
 *  UpdateSystemActivity()
 *

 *    \non_carbon_cfm   in PowerMgrLib 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 UpdateSystemActivity(__D0)
#endif
  OSErr
  UpdateSystemActivity(UInt8 activity);

/**
 *  DelaySystemIdle()
 *

 *    \non_carbon_cfm   in PowerMgrLib 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 DelaySystemIdle
#endif
  OSErr
  DelaySystemIdle(void);

/**
 *  GetStartupTimer()
 *

 *    \non_carbon_cfm   in PowerMgrLib 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 GetStartupTimer(__A0)
#endif
  OSErr
  GetStartupTimer(StartupTime *theTime);

/**
 *  SetStartupTimer()
 *

 *    \non_carbon_cfm   in PowerMgrLib 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 SetStartupTimer(__A0)
#endif
  OSErr
  SetStartupTimer(StartupTime *theTime);

/**
 *  GetLastActivity()
 *

 *    \non_carbon_cfm   in PowerMgrLib 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 GetLastActivity(__A0)
#endif
  OSErr
  GetLastActivity(ActivityInfo *theActivity);

/**
 *  GetSoundMixerState()
 *

 *    \non_carbon_cfm   in PowerMgrLib 1.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 GetSoundMixerState(__A0)
#endif
  OSErr
  GetSoundMixerState(SoundMixerByte *theSoundMixerByte);

/**
 *  SetSoundMixerState()
 *

 *    \non_carbon_cfm   in PowerMgrLib 1.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 SetSoundMixerState(__A0)
#endif
  OSErr
  SetSoundMixerState(SoundMixerByte *theSoundMixerByte);

/**
 *  GetDimSuspendState()
 *

 *    \non_carbon_cfm   in PowerMgrLib 1.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 GetDimSuspendState
#endif
  Boolean
  GetDimSuspendState(void);

/**
 *  SetDimSuspendState()
 *

 *    \non_carbon_cfm   in PowerMgrLib 1.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter SetDimSuspendState(__D0)
#endif
  void
  SetDimSuspendState(Boolean dimSuspendState);

#if CALL_NOT_IN_CARBON
/**
 *  GetCoreProcessorTemperature()
 *

 *    \non_carbon_cfm   in PowerMgrLib 2.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 GetCoreProcessorTemperature(__A0)
#endif
  SInt32
  GetCoreProcessorTemperature(MPCpuID inCpuID);

/**
 *  GetWakeOnNetworkOptions()
 *

 *    \non_carbon_cfm   in PowerMgrLib 2.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 GetWakeOnNetworkOptions
#endif
  OptionBits
  GetWakeOnNetworkOptions(void);

/**
 *  SetWakeOnNetworkOptions()
 *

 *    \non_carbon_cfm   in PowerMgrLib 2.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter SetWakeOnNetworkOptions(__A0)
#endif
  void
  SetWakeOnNetworkOptions(OptionBits inOptions);

/**
 *  AddPowerSource()
 *

 *    \non_carbon_cfm   in PowerMgrLib 2.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 AddPowerSource(__A0)
#endif
  OSStatus
  AddPowerSource(PowerSourceParamBlock *ioPowerSource);

/**
 *  RemovePowerSource()
 *

 *    \non_carbon_cfm   in PowerMgrLib 2.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 RemovePowerSource(__D0)
#endif
  OSStatus
  RemovePowerSource(PowerSourceID inSourceID);

/**
 *  UpdatePowerSource()
 *

 *    \non_carbon_cfm   in PowerMgrLib 2.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 UpdatePowerSource(__A0)
#endif
  OSStatus
  UpdatePowerSource(PowerSourceParamBlock *ioSource);

/**
 *  IsServerModeEnabled()
 *

 *    \non_carbon_cfm   in PowerMgrLib 2.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 IsServerModeEnabled
#endif
  Boolean
  IsServerModeEnabled(void);

/**
 *  EnableServerMode()
 *

 *    \non_carbon_cfm   in PowerMgrLib 2.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter EnableServerMode(__D0)
#endif
  void
  EnableServerMode(Boolean inEnable);

/**
   NumBatteriesInstalled is different from BatteryCount in that it
   indicates how many batteries are actually available at the time
   it is called (including UPS batteries). BatteryCount shows a
   static number of batteries a machine is capable of holding which does NOT
   include UPS batteries. So, while a desktop might show a BatteryCount
   of zero, its NumBatteriesInstalled value might be 1 or more if a UPS
   is attached.
*/
/**
 *  NumBatteriesInstalled()
 *

 *    \non_carbon_cfm   in PowerMgrLib 2.0 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 NumBatteriesInstalled
#endif
  UInt32
  NumBatteriesInstalled(void);

  /* Power Handler Management */
  /**
   *  IsPCIPowerOffDisabled()
   *

   *    \non_carbon_cfm   in DriverServicesLib 1.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  Boolean
  IsPCIPowerOffDisabled(void);

  /**
   *  EnablePCIPowerOff()
   *

   *    \non_carbon_cfm   in DriverServicesLib 1.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  EnablePCIPowerOff(Boolean inEnable);

  /**
   *  AddDevicePowerHandler()
   *

   *    \non_carbon_cfm   in DriverServicesLib 1.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  AddDevicePowerHandler(RegEntryIDPtr regEntryID, PowerHandlerProcPtr handler,
                        UInt32 refCon, char *deviceType);

  /**
   *  RemoveDevicePowerHandler()
   *

   *    \non_carbon_cfm   in DriverServicesLib 1.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  RemoveDevicePowerHandler(RegEntryIDPtr regEntryID);

  /**
   *  RemoveDevicePowerHandlerForProc()
   *

   *    \non_carbon_cfm   in DriverServicesLib 1.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  RemoveDevicePowerHandlerForProc(PowerHandlerProcPtr proc);

  /**
   *  GetDevicePowerLevel()
   *

   *    \non_carbon_cfm   in DriverServicesLib 1.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  GetDevicePowerLevel(RegEntryIDPtr regEntryID, PowerLevel *devicePowerLevel);

  /**
   *  SetDevicePowerLevel()
   *

   *    \non_carbon_cfm   in DriverServicesLib 1.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  SetDevicePowerLevel(RegEntryIDPtr regEntryID, PowerLevel devicePowerLevel);

#endif /* CALL_NOT_IN_CARBON */

  /**
   *  NewSleepQUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  SleepQUPP
  NewSleepQUPP(SleepQProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppSleepQProcInfo = 0x00131832
  }; /* register 4_bytes:D0 Func(4_bytes:D0, 4_bytes:A0) */
#ifdef __cplusplus
  inline SleepQUPP NewSleepQUPP(SleepQProcPtr userRoutine)
  {
    return (SleepQUPP)NewRoutineDescriptor(
        (ProcPtr)(userRoutine), uppSleepQProcInfo, GetCurrentArchitecture());
  }
#else
#define NewSleepQUPP(userRoutine)                                             \
  (SleepQUPP) NewRoutineDescriptor((ProcPtr)(userRoutine), uppSleepQProcInfo, \
                                   GetCurrentArchitecture())
#endif
#endif

  /**
   *  NewHDSpindownUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  HDSpindownUPP
  NewHDSpindownUPP(HDSpindownProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppHDSpindownProcInfo = 0x000000C0
  }; /* pascal no_return_value Func(4_bytes) */
#ifdef __cplusplus
  inline HDSpindownUPP NewHDSpindownUPP(HDSpindownProcPtr userRoutine)
  {
    return (HDSpindownUPP)NewRoutineDescriptor(
        (ProcPtr)(userRoutine), uppHDSpindownProcInfo, GetCurrentArchitecture());
  }
#else
#define NewHDSpindownUPP(userRoutine)   \
  (HDSpindownUPP) NewRoutineDescriptor( \
      (ProcPtr)(userRoutine), uppHDSpindownProcInfo, GetCurrentArchitecture())
#endif
#endif

  /**
   *  NewPMgrStateChangeUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  PMgrStateChangeUPP
  NewPMgrStateChangeUPP(PMgrStateChangeProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppPMgrStateChangeProcInfo = 0x000003C0
  }; /* pascal no_return_value Func(4_bytes, 4_bytes) */
#ifdef __cplusplus
  inline PMgrStateChangeUPP
  NewPMgrStateChangeUPP(PMgrStateChangeProcPtr userRoutine)
  {
    return (PMgrStateChangeUPP)NewRoutineDescriptor((ProcPtr)(userRoutine),
                                                    uppPMgrStateChangeProcInfo,
                                                    GetCurrentArchitecture());
  }
#else
#define NewPMgrStateChangeUPP(userRoutine)                                     \
  (PMgrStateChangeUPP)                                                         \
      NewRoutineDescriptor((ProcPtr)(userRoutine), uppPMgrStateChangeProcInfo, \
                           GetCurrentArchitecture())
#endif
#endif

  /**
   *  DisposeSleepQUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeSleepQUPP(SleepQUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeSleepQUPP(SleepQUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeSleepQUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  DisposeHDSpindownUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeHDSpindownUPP(HDSpindownUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeHDSpindownUPP(HDSpindownUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeHDSpindownUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  DisposePMgrStateChangeUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposePMgrStateChangeUPP(PMgrStateChangeUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposePMgrStateChangeUPP(PMgrStateChangeUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposePMgrStateChangeUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

/**
 *  InvokeSleepQUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __D0 InvokeSleepQUPP(__D0, __A0, __A1)
#endif
  long
  InvokeSleepQUPP(long message, SleepQRecPtr qRecPtr, SleepQUPP userUPP);
#if !OPAQUE_UPP_TYPES && \
    (!TARGET_OS_MAC || !TARGET_CPU_68K || TARGET_RT_MAC_CFM)
#ifdef __cplusplus
  inline long InvokeSleepQUPP(long message, SleepQRecPtr qRecPtr,
                              SleepQUPP userUPP)
  {
    return (long)CALL_TWO_PARAMETER_UPP(userUPP, uppSleepQProcInfo, message,
                                        qRecPtr);
  }
#else
#define InvokeSleepQUPP(message, qRecPtr, userUPP)                      \
  (long)CALL_TWO_PARAMETER_UPP((userUPP), uppSleepQProcInfo, (message), \
                               (qRecPtr))
#endif
#endif

  /**
   *  InvokeHDSpindownUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  InvokeHDSpindownUPP(HDQueueElement *theElement, HDSpindownUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void InvokeHDSpindownUPP(HDQueueElement *theElement,
                                  HDSpindownUPP userUPP)
  {
    CALL_ONE_PARAMETER_UPP(userUPP, uppHDSpindownProcInfo, theElement);
  }
#else
#define InvokeHDSpindownUPP(theElement, userUPP) \
  CALL_ONE_PARAMETER_UPP((userUPP), uppHDSpindownProcInfo, (theElement))
#endif
#endif

  /**
   *  InvokePMgrStateChangeUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  InvokePMgrStateChangeUPP(PMgrQueueElement *theElement, long stateBits,
                           PMgrStateChangeUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void InvokePMgrStateChangeUPP(PMgrQueueElement *theElement,
                                       long stateBits,
                                       PMgrStateChangeUPP userUPP)
  {
    CALL_TWO_PARAMETER_UPP(userUPP, uppPMgrStateChangeProcInfo, theElement,
                           stateBits);
  }
#else
#define InvokePMgrStateChangeUPP(theElement, stateBits, userUPP)              \
  CALL_TWO_PARAMETER_UPP((userUPP), uppPMgrStateChangeProcInfo, (theElement), \
                         (stateBits))
#endif
#endif

#if CALL_NOT_IN_CARBON || OLDROUTINENAMES
/* support for pre-Carbon UPP routines: New...Proc and Call...Proc */
#define NewSleepQProc(userRoutine) NewSleepQUPP(userRoutine)
#define NewHDSpindownProc(userRoutine) NewHDSpindownUPP(userRoutine)
#define NewPMgrStateChangeProc(userRoutine) NewPMgrStateChangeUPP(userRoutine)
#define CallSleepQProc(userRoutine, message, qRecPtr) \
  InvokeSleepQUPP(message, qRecPtr, userRoutine)
#define CallHDSpindownProc(userRoutine, theElement) \
  InvokeHDSpindownUPP(theElement, userRoutine)
#define CallPMgrStateChangeProc(userRoutine, theElement, stateBits) \
  InvokePMgrStateChangeUPP(theElement, stateBits, userRoutine)
#endif /* CALL_NOT_IN_CARBON */

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

#endif /* __POWER__ */
