/**
     \file       InputSprocket.h

    \brief   Games Sprockets: InputSprocket interfaaces

    \introduced_in  InputSprocket 1.7
    \avaliable_from Universal Interfaces 3.4.1

    \copyright � 1996-2001 by Apple Computer, Inc., all rights reserved.

    \ingroup Sprockets

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __INPUTSPROCKET__
#define __INPUTSPROCKET__

#ifndef __DESKBUS__
#include <DeskBus.h>
#endif

#ifndef __DIALOGS__
#include <Dialogs.h>
#endif

#ifndef __EVENTS__
#include <Events.h>
#endif

#ifndef __ICONS__
#include <Icons.h>
#endif

#ifndef __MACTYPES__
#include <MacTypes.h>
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
#pragma options align = power
#elif PRAGMA_STRUCT_PACKPUSH
#pragma pack(push, 2)
#elif PRAGMA_STRUCT_PACK
#pragma pack(2)
#endif

#ifndef USE_OLD_INPUT_SPROCKET_LABELS
#define USE_OLD_INPUT_SPROCKET_LABELS 0
#endif /* !defined(USE_OLD_INPUT_SPROCKET_LABELS) */

#ifndef USE_OLD_ISPNEED_STRUCT
#define USE_OLD_ISPNEED_STRUCT 0
#endif /* !defined(USE_OLD_ISPNEED_STRUCT) */

  /* ********************* data types ********************* */
  typedef struct OpaqueISpDeviceReference *ISpDeviceReference;
  typedef struct OpaqueISpElementReference *ISpElementReference;
  typedef struct OpaqueISpElementListReference *ISpElementListReference;
  /* ISpDeviceClass is a general classs of device, example: keyboard, mouse,
   * joystick */
  typedef OSType ISpDeviceClass;
  /* ISpDeviceIdentifier is a specific device, example: standard 1-button mouse,
   * 105key ext. kbd. */
  typedef OSType ISpDeviceIdentifier;
  typedef OSType ISpElementLabel;
  typedef OSType ISpElementKind;

  /* *************** resources **************** */
  enum
  {
    kISpApplicationResourceType = FOUR_CHAR_CODE('isap'),
    kISpSetListResourceType = FOUR_CHAR_CODE('setl'),
    kISpSetDataResourceType = FOUR_CHAR_CODE('setd')
  };

  struct ISpApplicationResourceStruct
  {
    UInt32 flags;
    UInt32 reserved1;
    UInt32 reserved2;
    UInt32 reserved3;
  };
  typedef struct ISpApplicationResourceStruct ISpApplicationResourceStruct;
  enum
  {
    kISpAppResFlag_UsesInputSprocket =
        0x00000001, /* true if the application uses InputSprocket*/
    kISpAppResFlag_UsesISpInit =
        0x00000002 /* true if the calls ISpInit (ie, uses the high level
        interface, calls ISpConfigure, has a needs list, etc...)*/
  };

  struct ISpDeviceDefinition
  {
    Str63 deviceName;                        /* a human readable name of the device */
    ISpDeviceClass theDeviceClass;           /* general classs of device example : keyboard,
              mouse, joystick */
    ISpDeviceIdentifier theDeviceIdentifier; /* every distinguishable device
    should have an OSType */
    UInt32 permanentID;                      /* a cross reboot id unique within that deviceType, 0 if
                         not possible */
    UInt32 flags;                            /* status flags */
    UInt32 permanentIDExtend;                /* extension of permanentID, so 64 bits total are
                   now significant */
    UInt32 reserved2;
    UInt32 reserved3;
  };
  typedef struct ISpDeviceDefinition ISpDeviceDefinition;
  enum
  {
    kISpDeviceFlag_HandleOwnEmulation = 1
  };

  struct ISpElementEvent
  {
    AbsoluteTime
        when; /* this is absolute time on PCI or later, otherwise it is */
    /* 0 for the hi 32 bits and TickCount for the low 32 bits */
    ISpElementReference
        element;   /* a reference to the element that generated this event */
    UInt32 refCon; /* for application usage, 0 on the global list */
    UInt32 data;   /* the data for this event */
  };
  typedef struct ISpElementEvent ISpElementEvent;
  typedef ISpElementEvent *ISpElementEventPtr;
  struct ISpElementInfo
  {
    ISpElementLabel theLabel;
    ISpElementKind theKind;
    Str63 theString;
    UInt32 reserved1;
    UInt32 reserved2;
  };
  typedef struct ISpElementInfo ISpElementInfo;
  typedef ISpElementInfo *ISpElementInfoPtr;
  typedef UInt32 ISpNeedFlagBits;
#if USE_OLD_ISPNEED_STRUCT
  struct ISpNeed
  {
    Str63 name;
    short iconSuiteResourceId; /* resource id of the icon suite */
    short reserved;
    ISpElementKind theKind;
    ISpElementLabel theLabel;
    ISpNeedFlagBits flags;
    UInt32 reserved1;
    UInt32 reserved2;
    UInt32 reserved3;
  };
  typedef struct ISpNeed ISpNeed;
#else
struct ISpNeed
{
  Str63 name;                /* human-readable string */
  short iconSuiteResourceId; /* resource id of the icon suite */
  UInt8 playerNum;           /* used for multi-player support */
  UInt8 group;               /* used to group related needs (eg, look left and look right
                button needs) */
  ISpElementKind theKind;
  ISpElementLabel theLabel;
  ISpNeedFlagBits flags;
  UInt32 reserved1;
  UInt32 reserved2;
  UInt32 reserved3;
};
typedef struct ISpNeed ISpNeed;
#endif /* USE_OLD_ISPNEED_STRUCT */

  enum
  {
    kISpNeedFlag_NoMultiConfig =
        0x00000001, /* once this need is autoconfigured to one device dont
        autoconfigure to anything else*/
    kISpNeedFlag_Utility =
        0x00000002, /* this need is a utility function (like show framerate) which
        would not typically be assigned to anything but the
        keyboard*/
    kISpNeedFlag_PolledOnly = 0x00000004,
    kISpNeedFlag_EventsOnly = 0x00000008,
    kISpNeedFlag_NoAutoConfig = 0x00000010, /* this need can be set normally, but
    will not ever be auto configured*/
    kISpNeedFlag_NoConfig =
        0x00000020, /* this need can not be changed by the user*/
    kISpNeedFlag_Invisible =
        0x00000040, /* this need can not be seen by the user*/
    /* *** kISpElementKind specific flags ****/
    /* these are flags specific to kISpElementKind_Button*/
    kISpNeedFlag_Button_AlreadyAxis =
        0x10000000, /* there is a axis version of this button need*/
    kISpNeedFlag_Button_ClickToggles = 0x20000000,
    kISpNeedFlag_Button_ActiveWhenDown = 0x40000000,
    kISpNeedFlag_Button_AlreadyDelta =
        (long)0x80000000, /* there is a delta version of this button need*/
    /* these are flags specific to kISpElementKind_DPad*/
    /* these are flags specific to kISpElementKind_Axis*/
    kISpNeedFlag_Axis_AlreadyButton =
        0x10000000,                           /* there is a button version of this axis need*/
    kISpNeedFlag_Axis_Asymetric = 0x20000000, /* this axis need is asymetric */
    kISpNeedFlag_Axis_AlreadyDelta =
        0x40000000, /* there is a delta version of this axis need*/
    /* these are flags specific to kISpElementKind_Delta*/
    kISpNeedFlag_Delta_AlreadyAxis =
        0x10000000, /* there is a axis version of this delta need*/
    kISpNeedFlag_Delta_AlreadyButton =
        0x20000000 /* there is a button version of this delta need*/
  };

  enum
  {
    kISpDeviceClass_SpeechRecognition = FOUR_CHAR_CODE('talk'),
    kISpDeviceClass_Mouse = FOUR_CHAR_CODE('mous'),
    kISpDeviceClass_Keyboard = FOUR_CHAR_CODE('keyd'),
    kISpDeviceClass_Joystick = FOUR_CHAR_CODE('joys'),
    kISpDeviceClass_Gamepad = FOUR_CHAR_CODE('gmpd'),
    kISpDeviceClass_Wheel = FOUR_CHAR_CODE('whel'),
    kISpDeviceClass_Pedals = FOUR_CHAR_CODE('pedl'),
    kISpDeviceClass_Levers = FOUR_CHAR_CODE('levr'),
    kISpDeviceClass_Tickle =
        FOUR_CHAR_CODE('tckl'), /* a device of this class requires ISpTickle*/
    kISpDeviceClass_Unknown = 0x3F3F3F3F
  };

  enum
  {
    kISpElementKind_Button = FOUR_CHAR_CODE('butn'),
    kISpElementKind_DPad = FOUR_CHAR_CODE('dpad'),
    kISpElementKind_Axis = FOUR_CHAR_CODE('axis'),
    kISpElementKind_Delta = FOUR_CHAR_CODE('dlta'),
    kISpElementKind_Movement = FOUR_CHAR_CODE('move'),
    kISpElementKind_Virtual = FOUR_CHAR_CODE('virt')
  };

#if USE_OLD_INPUT_SPROCKET_LABELS
  enum
  {
    /* axis */
    kISpElementLabel_XAxis = FOUR_CHAR_CODE('xaxi'),
    kISpElementLabel_YAxis = FOUR_CHAR_CODE('yaxi'),
    kISpElementLabel_ZAxis = FOUR_CHAR_CODE('zaxi'),
    kISpElementLabel_Rx = FOUR_CHAR_CODE('rxax'),
    kISpElementLabel_Ry = FOUR_CHAR_CODE('ryax'),
    kISpElementLabel_Rz = FOUR_CHAR_CODE('rzax'),
    kISpElementLabel_Gas = FOUR_CHAR_CODE('gasp'),
    kISpElementLabel_Brake = FOUR_CHAR_CODE('brak'),
    kISpElementLabel_Clutch = FOUR_CHAR_CODE('cltc'),
    kISpElementLabel_Throttle = FOUR_CHAR_CODE('thrt'),
    kISpElementLabel_Trim = FOUR_CHAR_CODE('trim'), /* direction pad */
    kISpElementLabel_POVHat = FOUR_CHAR_CODE('povh'),
    kISpElementLabel_PadMove = FOUR_CHAR_CODE('move'), /* buttons */
    kISpElementLabel_Fire = FOUR_CHAR_CODE('fire'),
    kISpElementLabel_Start = FOUR_CHAR_CODE('strt'),
    kISpElementLabel_Select = FOUR_CHAR_CODE(
        'optn'), /* Pause/Resume was changed into 2 needs: Quit and start/pause */
    kISpElementLabel_Btn_PauseResume = FOUR_CHAR_CODE('strt')
  };

#endif /* USE_OLD_INPUT_SPROCKET_LABELS */

  enum
  {
    /* generic */
    kISpElementLabel_None = FOUR_CHAR_CODE('none'), /* axis */
    kISpElementLabel_Axis_XAxis = FOUR_CHAR_CODE('xaxi'),
    kISpElementLabel_Axis_YAxis = FOUR_CHAR_CODE('yaxi'),
    kISpElementLabel_Axis_ZAxis = FOUR_CHAR_CODE('zaxi'),
    kISpElementLabel_Axis_Rx = FOUR_CHAR_CODE('rxax'),
    kISpElementLabel_Axis_Ry = FOUR_CHAR_CODE('ryax'),
    kISpElementLabel_Axis_Rz = FOUR_CHAR_CODE('rzax'),
    kISpElementLabel_Axis_Roll = kISpElementLabel_Axis_Rz,
    kISpElementLabel_Axis_Pitch = kISpElementLabel_Axis_Rx,
    kISpElementLabel_Axis_Yaw = kISpElementLabel_Axis_Ry,
    kISpElementLabel_Axis_RollTrim = FOUR_CHAR_CODE('rxtm'),
    kISpElementLabel_Axis_PitchTrim = FOUR_CHAR_CODE('trim'),
    kISpElementLabel_Axis_YawTrim = FOUR_CHAR_CODE('rytm'),
    kISpElementLabel_Axis_Gas = FOUR_CHAR_CODE('gasp'),
    kISpElementLabel_Axis_Brake = FOUR_CHAR_CODE('brak'),
    kISpElementLabel_Axis_Clutch = FOUR_CHAR_CODE('cltc'),
    kISpElementLabel_Axis_Throttle = FOUR_CHAR_CODE('thrt'),
    kISpElementLabel_Axis_Trim = kISpElementLabel_Axis_PitchTrim,
    kISpElementLabel_Axis_Rudder = FOUR_CHAR_CODE('rudd'),
    kISpElementLabel_Axis_ToeBrake = FOUR_CHAR_CODE('toeb'), /* delta */
    kISpElementLabel_Delta_X = FOUR_CHAR_CODE('xdlt'),
    kISpElementLabel_Delta_Y = FOUR_CHAR_CODE('ydlt'),
    kISpElementLabel_Delta_Z = FOUR_CHAR_CODE('zdlt'),
    kISpElementLabel_Delta_Rx = FOUR_CHAR_CODE('rxdl'),
    kISpElementLabel_Delta_Ry = FOUR_CHAR_CODE('rydl'),
    kISpElementLabel_Delta_Rz = FOUR_CHAR_CODE('rzdl'),
    kISpElementLabel_Delta_Roll = kISpElementLabel_Delta_Rz,
    kISpElementLabel_Delta_Pitch = kISpElementLabel_Delta_Rx,
    kISpElementLabel_Delta_Yaw = kISpElementLabel_Delta_Ry,
    kISpElementLabel_Delta_Cursor_X = FOUR_CHAR_CODE('curx'),
    kISpElementLabel_Delta_Cursor_Y = FOUR_CHAR_CODE('cury'), /* direction pad */
    kISpElementLabel_Pad_POV = FOUR_CHAR_CODE('povh'),        /* up/down/left/right*/
    kISpElementLabel_Pad_Move = FOUR_CHAR_CODE('move'),       /* up/down/left/right*/
    kISpElementLabel_Pad_POV_Horiz =
        FOUR_CHAR_CODE('hpov'), /* forward/back/left/right*/
    kISpElementLabel_Pad_Move_Horiz =
        FOUR_CHAR_CODE('hmov'), /* forward/back/left/right*/
    /* buttons */
    kISpElementLabel_Btn_Fire = FOUR_CHAR_CODE('fire'),
    kISpElementLabel_Btn_SecondaryFire = FOUR_CHAR_CODE('sfir'),
    kISpElementLabel_Btn_Jump = FOUR_CHAR_CODE('jump'),
    kISpElementLabel_Btn_Quit = FOUR_CHAR_CODE(
        'strt'), /* kISpElementLabel_Btn_Quit automatically binds to escape */
    kISpElementLabel_Btn_StartPause = FOUR_CHAR_CODE('paus'),
    kISpElementLabel_Btn_Select = FOUR_CHAR_CODE('optn'),
    kISpElementLabel_Btn_SlideLeft = FOUR_CHAR_CODE('blft'),
    kISpElementLabel_Btn_SlideRight = FOUR_CHAR_CODE('brgt'),
    kISpElementLabel_Btn_MoveForward = FOUR_CHAR_CODE('btmf'),
    kISpElementLabel_Btn_MoveBackward = FOUR_CHAR_CODE('btmb'),
    kISpElementLabel_Btn_TurnLeft = FOUR_CHAR_CODE('bttl'),
    kISpElementLabel_Btn_TurnRight = FOUR_CHAR_CODE('bttr'),
    kISpElementLabel_Btn_LookLeft = FOUR_CHAR_CODE('btll'),
    kISpElementLabel_Btn_LookRight = FOUR_CHAR_CODE('btlr'),
    kISpElementLabel_Btn_LookUp = FOUR_CHAR_CODE('btlu'),
    kISpElementLabel_Btn_LookDown = FOUR_CHAR_CODE('btld'),
    kISpElementLabel_Btn_Next = FOUR_CHAR_CODE('btnx'),
    kISpElementLabel_Btn_Previous = FOUR_CHAR_CODE('btpv'),
    kISpElementLabel_Btn_SideStep = FOUR_CHAR_CODE('side'),
    kISpElementLabel_Btn_Run = FOUR_CHAR_CODE('quik'),
    kISpElementLabel_Btn_Look = FOUR_CHAR_CODE('blok'),
    kISpElementLabel_Btn_Minimum = FOUR_CHAR_CODE('min '),
    kISpElementLabel_Btn_Decrement = FOUR_CHAR_CODE('decr'),
    kISpElementLabel_Btn_Center = FOUR_CHAR_CODE('cent'),
    kISpElementLabel_Btn_Increment = FOUR_CHAR_CODE('incr'),
    kISpElementLabel_Btn_Maximum = FOUR_CHAR_CODE('max '),
    kISpElementLabel_Btn_10Percent = FOUR_CHAR_CODE(' 10 '),
    kISpElementLabel_Btn_20Percent = FOUR_CHAR_CODE(' 20 '),
    kISpElementLabel_Btn_30Percent = FOUR_CHAR_CODE(' 30 '),
    kISpElementLabel_Btn_40Percent = FOUR_CHAR_CODE(' 40 '),
    kISpElementLabel_Btn_50Percent = FOUR_CHAR_CODE(' 50 '),
    kISpElementLabel_Btn_60Percent = FOUR_CHAR_CODE(' 60 '),
    kISpElementLabel_Btn_70Percent = FOUR_CHAR_CODE(' 70 '),
    kISpElementLabel_Btn_80Percent = FOUR_CHAR_CODE(' 80 '),
    kISpElementLabel_Btn_90Percent = FOUR_CHAR_CODE(' 90 '),
    kISpElementLabel_Btn_MouseOne = FOUR_CHAR_CODE('mou1'),
    kISpElementLabel_Btn_MouseTwo = FOUR_CHAR_CODE('mou2'),
    kISpElementLabel_Btn_MouseThree = FOUR_CHAR_CODE('mou3')
  };

  typedef UInt32 ISpDPadData;
  enum
  {
    kISpPadIdle = 0,
    kISpPadLeft = 1,
    kISpPadUpLeft = 2,
    kISpPadUp = 3,
    kISpPadUpRight = 4,
    kISpPadRight = 5,
    kISpPadDownRight = 6,
    kISpPadDown = 7,
    kISpPadDownLeft = 8
  };

  struct ISpDPadConfigurationInfo
  {
    UInt32 id; /* ordering 1..n, 0 = no relavent ordering of direction pads */
    Boolean
        fourWayPad; /* true if this pad can only produce idle + four directions */
  };
  typedef struct ISpDPadConfigurationInfo ISpDPadConfigurationInfo;
  typedef UInt32 ISpButtonData;
  enum
  {
    kISpButtonUp = 0,
    kISpButtonDown = 1
  };

  struct ISpButtonConfigurationInfo
  {
    UInt32 id; /* ordering 1..n, 0 = no relavent ordering of buttons */
  };
  typedef struct ISpButtonConfigurationInfo ISpButtonConfigurationInfo;
  typedef UInt32 ISpAxisData;

#define kISpAxisMinimum 0x00000000U
#define kISpAxisMiddle 0x7FFFFFFFU
#define kISpAxisMaximum 0xFFFFFFFFU

  struct ISpAxisConfigurationInfo
  {
    Boolean symetricAxis; /* axis is symetric, i.e. a joystick is symetric and a
    gas pedal is not */
  };
  typedef struct ISpAxisConfigurationInfo ISpAxisConfigurationInfo;

  typedef Fixed ISpDeltaData;
  struct ISpDeltaConfigurationInfo
  {
    UInt32 reserved1;
    UInt32 reserved2;
  };
  typedef struct ISpDeltaConfigurationInfo ISpDeltaConfigurationInfo;
  struct ISpMovementData
  {
    ISpAxisData xAxis;
    ISpAxisData yAxis;
    ISpDPadData direction; /* ISpDPadData version of the movement */
  };
  typedef struct ISpMovementData ISpMovementData;
  struct ISpMovementConfigurationInfo
  {
    UInt32 reserved1;
    UInt32 reserved2;
  };
  typedef struct ISpMovementConfigurationInfo ISpMovementConfigurationInfo;
  enum
  {
    kISpVirtualElementFlag_UseTempMem = 1
  };

  enum
  {
    kISpElementListFlag_UseTempMem = 1
  };

  enum
  {
    kISpFirstIconSuite = 30000,
    kISpLastIconSuite = 30100,
    kISpNoneIconSuite = 30000
  };

  /* ********************* user level functions ********************* */

  EXTERN_API_C(OSStatus)
  ISpStartup(void);

  /* 1.1 or later*/
  EXTERN_API_C(OSStatus)
  ISpShutdown(void);

  /* 1.1 or later*/
  EXTERN_API_C(OSStatus)
  ISpTickle(void);

  /* 1.1 or later*/
  /********** user interface functions **********/

  EXTERN_API_C(NumVersion)
  ISpGetVersion(void);

  EXTERN_API_C(OSStatus)
  ISpElement_NewVirtual(UInt32 dataSize, ISpElementReference *outElement,
                        UInt32 flags);

  EXTERN_API_C(OSStatus)
  ISpElement_NewVirtualFromNeeds(UInt32 count, ISpNeed *needs,
                                 ISpElementReference *outElements, UInt32 flags);

  EXTERN_API_C(OSStatus)
  ISpElement_DisposeVirtual(UInt32 count, ISpElementReference *inElements);

  EXTERN_API_C(OSStatus)
  ISpInit(UInt32 count, ISpNeed *needs, ISpElementReference *inReferences,
          OSType appCreatorCode, OSType subCreatorCode, UInt32 flags,
          short setListResourceId, UInt32 reserved);

  typedef CALLBACK_API_C(Boolean, ISpEventProcPtr)(EventRecord *inEvent);
  EXTERN_API_C(OSStatus)
  ISpConfigure(ISpEventProcPtr inEventProcPtr);

  EXTERN_API_C(OSStatus)
  ISpStop(void);

  EXTERN_API_C(OSStatus)
  ISpSuspend(void);

  EXTERN_API_C(OSStatus)
  ISpResume(void);

  EXTERN_API_C(OSStatus)
  ISpDevices_Extract(UInt32 inBufferCount, UInt32 *outCount,
                     ISpDeviceReference *buffer);

  EXTERN_API_C(OSStatus)
  ISpDevices_ExtractByClass(ISpDeviceClass inClass, UInt32 inBufferCount,
                            UInt32 *outCount, ISpDeviceReference *buffer);

  EXTERN_API_C(OSStatus)
  ISpDevices_ExtractByIdentifier(ISpDeviceIdentifier inIdentifier,
                                 UInt32 inBufferCount, UInt32 *outCount,
                                 ISpDeviceReference *buffer);

  EXTERN_API_C(OSStatus)
  ISpDevices_ActivateClass(ISpDeviceClass inClass);

  /* 1.1 or later*/
  EXTERN_API_C(OSStatus)
  ISpDevices_DeactivateClass(ISpDeviceClass inClass);

  /* 1.1 or later*/
  EXTERN_API_C(OSStatus)
  ISpDevices_Activate(UInt32 inDeviceCount,
                      ISpDeviceReference *inDevicesToActivate);

  EXTERN_API_C(OSStatus)
  ISpDevices_Deactivate(UInt32 inDeviceCount,
                        ISpDeviceReference *inDevicesToDeactivate);

  EXTERN_API_C(OSStatus)
  ISpDevice_IsActive(ISpDeviceReference inDevice, Boolean *outIsActive);

  EXTERN_API_C(OSStatus)
  ISpDevice_GetDefinition(ISpDeviceReference inDevice, UInt32 inBuflen,
                          ISpDeviceDefinition *outStruct);

  EXTERN_API_C(OSStatus)
  ISpDevice_GetElementList(ISpDeviceReference inDevice,
                           ISpElementListReference *outElementList);

  EXTERN_API_C(OSStatus)
  ISpElement_GetGroup(ISpElementReference inElement, UInt32 *outGroup);

  EXTERN_API_C(OSStatus)
  ISpElement_GetDevice(ISpElementReference inElement,
                       ISpDeviceReference *outDevice);

  EXTERN_API_C(OSStatus)
  ISpElement_GetInfo(ISpElementReference inElement, ISpElementInfoPtr outInfo);

  EXTERN_API_C(OSStatus)
  ISpElement_GetConfigurationInfo(ISpElementReference inElement, UInt32 buflen,
                                  void *configInfo);

  EXTERN_API_C(OSStatus)
  ISpElement_GetSimpleState(ISpElementReference inElement, UInt32 *state);

  EXTERN_API_C(OSStatus)
  ISpElement_GetComplexState(ISpElementReference inElement, UInt32 buflen,
                             void *state);

  EXTERN_API_C(OSStatus)
  ISpElement_GetNextEvent(ISpElementReference inElement, UInt32 bufSize,
                          ISpElementEventPtr event, Boolean *wasEvent);

  EXTERN_API_C(OSStatus)
  ISpElement_Flush(ISpElementReference inElement);

  EXTERN_API_C(OSStatus)
  ISpElementList_New(UInt32 inCount, ISpElementReference *inElements,
                     ISpElementListReference *outElementList, UInt32 flags);

  EXTERN_API_C(OSStatus)
  ISpElementList_Dispose(ISpElementListReference inElementList);

  EXTERN_API_C(OSStatus)
  ISpGetGlobalElementList(ISpElementListReference *outElementList);

  EXTERN_API_C(OSStatus)
  ISpElementList_AddElements(ISpElementListReference inElementList, UInt32 refCon,
                             UInt32 count, ISpElementReference *newElements);

  EXTERN_API_C(OSStatus)
  ISpElementList_RemoveElements(ISpElementListReference inElementList,
                                UInt32 count, ISpElementReference *oldElement);

  EXTERN_API_C(OSStatus)
  ISpElementList_Extract(ISpElementListReference inElementList,
                         UInt32 inBufferCount, UInt32 *outCount,
                         ISpElementReference *buffer);

  EXTERN_API_C(OSStatus)
  ISpElementList_ExtractByKind(ISpElementListReference inElementList,
                               ISpElementKind inKind, UInt32 inBufferCount,
                               UInt32 *outCount, ISpElementReference *buffer);

  EXTERN_API_C(OSStatus)
  ISpElementList_ExtractByLabel(ISpElementListReference inElementList,
                                ISpElementLabel inLabel, UInt32 inBufferCount,
                                UInt32 *outCount, ISpElementReference *buffer);

  EXTERN_API_C(OSStatus)
  ISpElementList_GetNextEvent(ISpElementListReference inElementList,
                              UInt32 bufSize, ISpElementEventPtr event,
                              Boolean *wasEvent);

  EXTERN_API_C(OSStatus)
  ISpElementList_Flush(ISpElementListReference inElementList);

  EXTERN_API_C(OSStatus)
  ISpTimeToMicroseconds(const AbsoluteTime *inTime,
                        UnsignedWide *outMicroseconds);

  EXTERN_API_C(AbsoluteTime)
  ISpUptime(void);

  /****************************************************************************/
  /* Interfaces for InputSprocket Drivers */
  /* */
  /* These APIs should be called only from InputSprocket drivers */
  /* */
  /* (Moved from InputSprocketDriver.h, which is now obsolete. */
  /****************************************************************************/

  enum
  {
    kOSType_ISpDriverFileType = FOUR_CHAR_CODE('shlb'),
    kOSType_ISpDriverCreator = FOUR_CHAR_CODE('insp')
  };

  EXTERN_API_C(OSErr)
  ISpPlotAppIconSuite(const Rect *theRect, IconAlignmentType align,
                      IconTransformType transform, short iconSuiteResourceId);

  /* label2,5,6,7, disabled and offline are reserved*/

  enum
  {
    kISpIconTransform_Selected =
        kTransformSelected, /* choose one of these (optionally) (these all erase
        what is behind them to the dialog color)*/
    kISpIconTransform_PlotIcon = kTransformLabel1,
    kISpIconTransform_PlotPopupButton = kTransformLabel3,
    kISpIconTransform_PlotButton =
        kTransformLabel4, /* use this is you want to plot the icon while the
        devices button is pressed*/
    /* or the devices axis is activated and so on*/
    kISpIconTransform_DeviceActive = kTransformOpen
  };

  typedef UInt32 ISpMetaHandlerSelector;
  enum
  {
    kISpSelector_Init = 1,
    kISpSelector_Stop = 2,
    kISpSelector_GetSize = 3,
    kISpSelector_HandleEvent = 4,
    kISpSelector_Show = 5,
    kISpSelector_Hide = 6,
    kISpSelector_BeginConfiguration = 7,
    kISpSelector_EndConfiguration = 8,
    kISpSelector_GetIcon = 9,
    kISpSelector_GetState = 10,
    kISpSelector_SetState = 11,
    kISpSelector_Dirty = 12,
    kISpSelector_SetActive = 13,
    kISpSelector_DialogItemHit = 14,
    kISpSelector_Tickle = 15, /* 1.03 and later*/
    kISpSelector_InterruptTickle = 16,
    kISpSelector_Draw = 17,
    kISpSelector_Click = 18,
    kISpSelector_ADBReInit = 19,      /* 1.2 and later*/
    kISpSelector_GetCalibration = 20, /* 1.7 and later*/
    kISpSelector_SetCalibration = 21,
    kISpSelector_CalibrateDialog = 22
  };

  /* a generic driver function pointer */
  typedef CALLBACK_API_C(OSStatus, ISpDriverFunctionPtr_Generic)(UInt32 refCon,
                                                                 ...);
  /* the meta handler pointer */
  typedef CALLBACK_API_C(ISpDriverFunctionPtr_Generic,
                         ISpDriverFunctionPtr_MetaHandler)(
      UInt32 refCon, ISpMetaHandlerSelector metaHandlerSelector);
  /* the pointers you get through the meta handler */
  typedef CALLBACK_API_C(OSStatus, ISpDriverFunctionPtr_Init)(
      UInt32 refCon, UInt32 count, ISpNeed needs[],
      ISpElementReference virtualElements[], Boolean used[],
      OSType appCreatorCode, OSType subCreatorCode, UInt32 reserved,
      void *reserved2);
  typedef CALLBACK_API_C(OSStatus, ISpDriverFunctionPtr_Stop)(UInt32 refCon);
  typedef CALLBACK_API_C(OSStatus, ISpDriverFunctionPtr_GetSize)(UInt32 refCon,
                                                                 Point *minimum,
                                                                 Point *best);
  typedef CALLBACK_API_C(OSStatus,
                         ISpDriverFunctionPtr_HandleEvent)(UInt32 refCon,
                                                           EventRecord *theEvent,
                                                           Boolean *handled);
  typedef CALLBACK_API_C(OSStatus, ISpDriverFunctionPtr_Show)(
      UInt32 refCon, DialogRef theDialog, short dialogItemNumber, Rect *r);
  typedef CALLBACK_API_C(OSStatus, ISpDriverFunctionPtr_Hide)(UInt32 refCon);
  typedef CALLBACK_API_C(OSStatus, ISpDriverFunctionPtr_BeginConfiguration)(
      UInt32 refCon, UInt32 count, ISpNeed needs[]);
  typedef CALLBACK_API_C(OSStatus,
                         ISpDriverFunctionPtr_EndConfiguration)(UInt32 refCon,
                                                                Boolean accept);
  typedef CALLBACK_API_C(OSStatus, ISpDriverFunctionPtr_GetIcon)(
      UInt32 refCon, short *iconSuiteResourceId);
  typedef CALLBACK_API_C(OSStatus, ISpDriverFunctionPtr_GetState)(UInt32 refCon,
                                                                  UInt32 buflen,
                                                                  void *buffer,
                                                                  UInt32 *length);
  typedef CALLBACK_API_C(OSStatus, ISpDriverFunctionPtr_SetState)(UInt32 refCon,
                                                                  UInt32 length,
                                                                  void *buffer);
  typedef CALLBACK_API_C(OSStatus, ISpDriverFunctionPtr_Dirty)(UInt32 refCon,
                                                               Boolean *dirty);
  typedef CALLBACK_API_C(OSStatus,
                         ISpDriverFunctionPtr_SetActive)(UInt32 refCon,
                                                         Boolean active);
  typedef CALLBACK_API_C(OSStatus,
                         ISpDriverFunctionPtr_DialogItemHit)(UInt32 refCon,
                                                             short itemHit);
  /* 1.03 and later*/
  typedef CALLBACK_API_C(OSStatus, ISpDriverFunctionPtr_Tickle)(UInt32 refCon);
  typedef CALLBACK_API_C(OSStatus,
                         ISpDriverFunctionPtr_InterruptTickle)(UInt32 refCon);
  typedef CALLBACK_API_C(OSStatus, ISpDriverFunctionPtr_Draw)(UInt32 refCon);
  typedef CALLBACK_API_C(OSStatus,
                         ISpDriverFunctionPtr_Click)(UInt32 refCon,
                                                     const EventRecord *event);
  /* 1.2 and later*/
  typedef CALLBACK_API_C(OSStatus,
                         ISpDriverFunctionPtr_ADBReInit)(UInt32 refCon,
                                                         Boolean inPostProcess);
  /* 1.7 and later*/
  typedef CALLBACK_API_C(OSStatus, ISpDriverFunctionPtr_GetCalibration)(
      UInt32 refCon, void *calibration, Size *calibrationSize);
  typedef CALLBACK_API_C(OSStatus, ISpDriverFunctionPtr_SetCalibration)(
      UInt32 refCon, void *calibration, Size calibrationSize);
  typedef CALLBACK_API_C(OSStatus,
                         ISpDriverFunctionPtr_CalibrateDialog)(UInt32 refCon,
                                                               Boolean *changed);
/* these functions are exported in the driver's pef container (1.7 or later)*/
#if CALL_NOT_IN_CARBON
  EXTERN_API_C(OSStatus)
  ISpDriver_CheckConfiguration(Boolean *validConfiguration);

  EXTERN_API_C(OSStatus)
  ISpDriver_FindAndLoadDevices(Boolean *keepDriverLoaded);

  EXTERN_API_C(OSStatus)
  ISpDriver_DisposeDevices(void);

  EXTERN_API_C(void)
  ISpDriver_Tickle(void);

#endif /* CALL_NOT_IN_CARBON */

  typedef CALLBACK_API_C(OSStatus, ISpDriver_CheckConfigurationPtr)(
      Boolean *validConfiguration);
  typedef CALLBACK_API_C(OSStatus, ISpDriver_FindAndLoadDevicesPtr)(
      Boolean *keepDriverLoaded);
  typedef CALLBACK_API_C(OSStatus, ISpDriver_DisposeDevicesPtr)(void);
  typedef CALLBACK_API_C(void, ISpDriver_TicklePtr)(void);
  /* ********************* driver level functions ********************* */

  EXTERN_API_C(OSStatus)
  ISpDevice_New(const ISpDeviceDefinition *inStruct,
                ISpDriverFunctionPtr_MetaHandler metaHandler, UInt32 refCon,
                ISpDeviceReference *outReference);

  EXTERN_API_C(OSStatus)
  ISpDevice_Dispose(ISpDeviceReference inReference);

  struct ISpElementDefinitionStruct
  {
    ISpDeviceReference device; /* device this element belongs to */
    UInt32 group;              /* group this element belongs to or 0 */

    Str63 theString; /* a string that is a human readable identifier for this
    element, internationalization ? */

    ISpElementKind kind;
    ISpElementLabel label;

    void *configInfo;        /* a pointer to the buffer containing the configuration
           information for this element */
    UInt32 configInfoLength; /* length of that configuration info */

    UInt32 dataSize; /* the size of the data, so we can generate an appropriate
    buffer */

    UInt32 reserved1;
    UInt32 reserved2;
    UInt32 reserved3;
  };
  typedef struct ISpElementDefinitionStruct ISpElementDefinitionStruct;
  EXTERN_API_C(OSStatus)
  ISpElement_New(const ISpElementDefinitionStruct *inStruct,
                 ISpElementReference *outElement);

  EXTERN_API_C(OSStatus)
  ISpElement_Dispose(ISpElementReference inElement);

  EXTERN_API_C(OSStatus)
  ISpElement_PushSimpleData(ISpElementReference inElement, UInt32 data,
                            const AbsoluteTime *time);

  EXTERN_API_C(OSStatus)
  ISpElement_PushComplexData(ISpElementReference inElement, UInt32 buflen,
                             void *state, const AbsoluteTime *time);

#if CALL_NOT_IN_CARBON
  /* ADBDefer can't be used from carbonized apps because ADB is not available */
  /* ***********************************************************************************
   */

  typedef UInt32 ISpADBDeferRef;
  typedef CALLBACK_API_C(void, ISpADBDeferCallbackProcPtr)(UInt8 adbCommand,
                                                           void *adbBuffer,
                                                           UInt32 refcon);
#if CALL_NOT_IN_CARBON
  EXTERN_API_C(OSErr)
  ISpAllocateADBDeferBlock(ISpADBDeferRef *createBlock);

  EXTERN_API_C(OSErr)
  ISpDisposeADBDeferBlock(ISpADBDeferRef disposeBlock);

  EXTERN_API_C(OSErr)
  ISpInstallADBDefer(ISpADBDeferRef refBlock, ADBAddress reqAddress,
                     ISpADBDeferCallbackProcPtr installProc, UInt32 clientRefCon,
                     ADBServiceRoutineUPP *prevRoutine, Ptr *prevDataArea);

  EXTERN_API_C(OSErr)
  ISpRemoveADBDefer(ISpADBDeferRef refBlock);

#endif /* CALL_NOT_IN_CARBON */

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

#endif /* __INPUTSPROCKET__ */
