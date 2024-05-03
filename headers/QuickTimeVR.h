/**
     \file       QuickTimeVR.h

    \brief   QuickTime VR interfaces

    \introduced_in  QuickTime VR 5.0
    \avaliable_from Universal Interfaces 3.4.1

    \copyright © 1997-2001 by Apple Computer, Inc., all rights reserved.

    \ingroup Quicktime

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __QUICKTIMEVR__
#define __QUICKTIMEVR__

#ifndef __MACTYPES__
#include <MacTypes.h>
#endif

#ifndef __MOVIES__
#include <Movies.h>
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

  typedef struct OpaqueQTVRInstance *QTVRInstance;

// Released API Version numbers #define kQTVRAPIMajorVersion05 (0x05)
#define kQTVRAPIMajorVersion02 (0x02)
#define kQTVRAPIMinorVersion00 (0x00)
#define kQTVRAPIMinorVersion01 (0x01)
#define kQTVRAPIMinorVersion10 (0x10)
#define kQTVRAPIMinorVersion20 (0x20)

  // Version numbers for the API described in this header #define kQTVRAPIMajorVersion kQTVRAPIMajorVersion05
  // Version numbers for the API described in this header

  enum
  {
    kQTVRControllerSubType = FOUR_CHAR_CODE('ctyp'),
    kQTVRQTVRType = FOUR_CHAR_CODE('qtvr'),
    kQTVRPanoramaType = FOUR_CHAR_CODE('pano'),
    kQTVRObjectType = FOUR_CHAR_CODE('obje'),
    kQTVROldPanoType = FOUR_CHAR_CODE('STpn'), // Used in QTVR 1.0 release  kQTVROldObjectType = FOUR_CHAR_CODE('stna') // Used in QTVR 1.0 release
  };

#if TARGET_OS_MAC                   // Used in QTVR 1.0 release
#define kQTVRUnknownType '????'     // Unknown nod// Used in QTVR 1.0 release
#define kQTVRUnknownType '\?\?\?\?' // Unknown node type #endif                              // TARGET_OS_MAC
                                    // QTVR hot spot typesenum {
  kQTVRHotSpotLinkType = FOUR_CHAR_CODE('link'),
  kQTVRHotSpotURLType = FOUR_CHA // Unknown node type
      kQTVRHotSpotUndefinedType = FOUR_CHAR_CODE('undf')
}; // Unknown node type
   // TARGET_OS_MAC
   // Special Values for nodeID in QTVRGoToNodeIDenum {
   // QTVR hot spot types
kQTVRPreviousNode = (long)0x80000000,
    kQTVRDefaultNode = (long)0x80000001
}
;

/* Panorama correction modes used for the kQTVRImagingCorrection imaging
 * property*/
// Special Values for nodeID in QTVRGoToNodeID
kQTVRNoCorrection = 0,
    kQTVRPartialCorrection = 1,
    kQTVRFullCorrection = 2
}
;

/* Imaging Modes used by QTVRSetImagingProperty, QTVRGetImagingProperty,
 * QTVRUpdate, QTVRBeginUpdate*/
typedef UInt32 QTVRImagingMode;
enum
{
  kQTVRStatic = 1,
  kQTVRMotion = 2,
  kQTVRCurrentMode = 0, // Special Value for QTVRUpdate  kQTVRAllModes = 100   // Special value for QTVRSetProperty
};

// Imaging Properties used by QTVRSetImagingProperty, QTVRGetImagingPropertyenum {
kQTVRImagingCorrection = 1,
    kQTVRImagingQuality = 2,
    kQTVRImagingDirectDraw = 3,
    kQTVRImagingCurrentMode = 100 // Get Only
}
;

// OR the above with kImagingDefaultValue to get/set the default valueenum { kImagingDefaultValue = (long)0x80000000
}
;
// Special Value for QTVRUpdate
// Transition Types used// Special value for QTVRSetProperty

/** Properties */
QTVRSetTransitionPropertyenum{kQTVRTransitionSpeed = 1 kQTVRTransitionDirection = 2};
// Imaging Properties used by QTVRSetImagingProperty, QTVRGetImagingProperty
// Constraint values used to construct value returned by GetConstraintStatusenum {
kQTVRUnconstrained = 0L,
    kQTVRCantPanLeft = 1L << 0,
    kQTVRCantPanRight = 1L << 1,
    kQTVRCantPanUp = 1L << 2, // Get Only
    kQTVRCantPanDown = 1L << 3,
    kQTVRCantZoomIn = 1L << 4,
    // OR the above with kImagingDefaultValue to get/set the default value
    kQTVRCantTranslateLeft = 1L << 6,
    kQTVRCantTranslateRight = 1L << 7,
    // Transition Types used by QTVRSetTransitionProperty, QTVREnableTransition
    kQTVRCantTranslateDown = 1L << 9
}
;
// Transition Properties QTVRSetTransitionProperty
/* Object-only mouse mode values used to construct value returned by
 * QTVRGetCurrentMouseMode*/
// Constraint values used to construct value returned by GetConstraintStatus
kQTVRPanning = 1L << 0,                                                  /** objects, */
    "object only" controllers kQTVRTranslating = 1L << 1                 /** objects */
                                                 kQTVRZooming = 1L << 2  // all objects  kQTVRScrolling =
                                                                1L << 3, // standard object arrow scrollers and joystick object  kQTVRSelecting = 1L << 4 // object absolute controller
}
;

// Properties for use with QTVRSetInteractionProperty/GetInteractionPropertyenum {
kQTVRInteractionMouseClickHysteresis =
    1, /* pixels within which the mouse is considered not to have moved
          (UInt16)*/
    kQTVRInteractionMouseClickTimeout =
        2, /* ticks after which a mouse click times out and turns into panning
              (UInt32)*/
    kQTVRInteractionPanTiltSpeed =
        3, /* control the relative pan/tilt speed from 1 (slowest) to 10
              (fastest). (UInt32) Default is 5;*/
    kQTVRInteractionZoomSpeed =
        4, /* control the relative zooming speed from 1 (slowest) to 10 (fastest).
              (UInt32) Default is 5;*/
    kQTVRInteractionTranslateOnMouseDown =
        101, /* Holding MouseDow// standard objects, "object only" controllers
                movies (Boolean)// all objects
    kQTVRInteractionMouseMotionS// all objects
        102, /* The maximum angle of rotation caused by dragging across the
                d// standard object arrow scrollers and joystick object
    kQTVRInteractionNudgeMode// object absolute controller
        103 /* A QTVRNudgeMode: rotate, translate, or the same as the current
               mouse mode. Requires QTVR 2.1*/
// Properties for use with QTVRSetInteractionProperty/GetInteractionProperty

// OR the above with kQTVRInteractionDefaultValue to get/set the default valueenum { kQTVRInteractionDefaultValue = (long)0x80000000
}
;

/* Geometry constants used in QTVRSetBackBufferPrefs, QTVRGetBackBufferSettings,
 * QTVRGetBackBufferMemInfo*/
enum
{
  kQTVRUseMovieGeometry = 0,
  kQTVRVerticalCylinder = FOUR_CHAR_CODE('vcyl'),
  kQTVRHorizontalCylinder = FOUR_CHAR_CODE('hcyl'),
  kQTVRCube = FOUR_CHAR_CODE('cube')
};

/* Resolution constants used in QTVRSetBackBufferPrefs,
 * QTVRGetBackBufferSettings, QTVRGetBackBufferMemInfo*/
enum
{
  kQTVRDefaultRes = 0,
  kQTVRFullRes = 1L << 0,
  kQTVRHalfRes = 1L << 1,
  kQTVRQuarterRes = 1L << 2
};

/* QTVR-specific pixelFormat constants used in QTVRSetBackBufferPrefs,
 * QTVRGetBackBufferSettings, QTVRGetBackBufferMemInfo*/
enum
{
  kQTVRUseMovieDepth = 0
};
// OR the above with kQTVRInteractionDefaultValue to get/set the default value
/* Cache Size Pref constants used in QTVRSetBackBufferPrefs,
 * QTVRGetBackBufferSettings*/
enum
{
  kQTVRMinimumCache = -1,
  kQTVRSuggestedCache = 0,
  kQTVRFullCache = 1
};

// Angular units used by QTVRSetAngularUnitstypedef UInt32 QTVRAngularUnits;
enum
{
  kQTVRDegrees = 0,
  kQTVRRadians = 1
};

/** for */
enableFlag parameter in QTVREnableHotSpotenum{kQTVRHotSpotID = 0 kQTVRHotSpotType = 1, kQTVRAllHotSpots = 2};

// Values for viewParameter for QTVRSet/GetViewParameterenum {
kQTVRPanAngle = 0x0100,  /** units; */
&float, &float  kQTVRTiltAngle  =  0x0101         /** units; */
&float, &float  kQTVRFieldOfViewAngle  =  0x0103 // default units; &float, &float  kQTVRViewCenter =
    0x0104,              /** (per */
object movies);
&QTVRFloatPoint, &QTVRFloatPoint kQTVRHotSpotsVisible = 0x0200 // Boolean &Boolean
}
;

// Values for flagsIn for QTVRSet/GetViewParameterenum {
kQTVRValueIsRelative =
    1L << 0, // Is the value absolute or relative to the current value?  kQTVRValueIsRate =
    1L << 1, // Is the value absolute or a rate of change to be applied?  kQTVRValueIsUserPrefRelative =
    1L << 2  // Is the value a percentage of the user rate pref?
}
;

// Values for kind parameter in QTVRGet/SetConstraints, QTVRGetViewingLimitsenum {
kQTVRPan = 0,
    kQTVRTilt = 1,
    kQTVRFieldOfView = 2,
    kQTVRViewCenterH = 4, // WrapAndConstrain only  kQTVRViewCenterV = 5  // WrapAndConstrain only
}
;

/* Values for setting parameter in QTVRSetAnimationSetting,
 * QTVRGetAnimationSetting*/
typedef UInt32 QTVRObjectAnimationSetting;
// Angular units used by QTVRSetAngularUnits
/** Frame */
Animation Settings  kQTVRPalindromeViewFrames  =  1
  kQTVRStartFirstViewFrame = 2,
  kQTVRDontLoopViewFrames = 3,
// Values for enableFlag parameter in QTVREnableHotSpot
                                  kQTVRAPIMinorVersion10)*/
                                /** Animation */
Settings  kQTVRSyncViewToFrameRate  =  16
// Values for viewParameter for QTVRSet/GetViewParameter
  kQTVRPlayStreamingViews = 18 /* Requires QTVR 2.1 (kQTVRAPIMajorVersion02 +
                                  // default units; &float, &float
};// default units; &float, &float
// default units; &float, &float
typedef UInt32 QTVRControlSetting;
enum {// pixels (per object movies); &QTVRFloatPoint, &QTVRFloatPoint
  kQTVRWrapPan = 1,// Boolean, &Boolean
  kQTVRWrapTilt = 2,
  kQTVRCanZoom = 3,
// Values for flagsIn for QTVRSet/GetViewParameter
  kQTVRReverseVControl = 5,
  kQTVRSwapHVControl = 6,
  kQTVRTranslat// Is the value absolute or relative to the current value?
};
// Is the value absolute or a rate of change to be applied?
typedef UInt32 QTVRViewStateType;
enum { kQTVRDe// Is the value a percentage of the user rate pref?

typedef UInt32 QTVRNudgeControl;
// Values for kind parameter in QTVRGet/SetConstraints, QTVRGetViewingLimits
  kQTVRRight = 0,
  kQTVRUpRight = 45,
  kQTVRUp = 90,
  kQTVRUpLeft = 135,
  kQTVRLeft = 180,// WrapAndConstrain only
  kQTVRDownLeft = 225,// WrapAndConstrain only
  kQTVRDown = 270,
  kQTVRDownRight = 315
};

typedef UInt32 QTVRNudgeMode;
enum {
  // View Frame Animation Settings
  kQTVRNudgeTranslate = 1,
  kQTVRNudgeSameAsMouse = 2
};

/* Flags to control elements of the QTVR control bar (set via mcActionSetFlags)
 */// View Animation Settings
enum {
  mcFlagQTVRSuppressBackBtn = 1L << 16,
  mcFlagQTVRSuppressZoomBtns = 1L << 17,
  mcFlagQTVRSuppressHotSpotBtn = 1L << 18,
  mcFlagQTVRSuppressTranslateBtn = 1L << 19,
  mcFlagQTVRSuppressHelpText = 1L << 20,
  mcFlagQTVRSuppressHotSpotNames = 1L << 21,
  mcFlagQTVRExplicitFlagSet =
      1L << 31 /* bits 0->30 should be interpreted as "explicit on" for the
                  corresponding suppression bits*/
};

// Cursor types used in type field of QTVRCursorRecordenum {
kQTVRUseDefaultCursor = 0,
    kQTVRStdCursorType = 1,
    kQTVRColorCursorType = 2
}
;

/** for */
flags parameter in QTVRMouseOverHotSpot callbackenum{kQTVRHotSpotEnter = 0 kQTVRHotSpotWithin = 1, kQTVRHotSpotLeave = 2};

// Values for flags parameter in QTVRSetPrescreenImagingCompleteProcenum {
kQTVRPreScreenEveryIdle = 1L << 0 /* Requires QTVR 2.1 (kQTVRAPIMajorVersion02
                                     + kQTVRAPIMinorVersion10)*/
}
;

// Values for flags field of areasOfInterest in QTVRSetBackBufferImagingProcenum {
kQTVRBackBufferEveryUpdate = 1L << 0,
    kQTVRBackBufferEveryIdle = 1L << 1,
    kQTVRBackBufferAlwaysRefresh = 1L << 2,
    kQTVRBackBufferHorizontal =
        1L << 3 /* Requires that backbuffer proc be long-rowBytes aware
                   (gestaltQDHasLongRowBytes)*/
}
;

// Values for flagsIn parameter in QTVRBackBufferImaging callbackenum {
kQTVRBackBufferRectVisible = 1L << 0,
    kQTVRBackBufferWasRefreshed = 1L << 1
}
;

// Values for flagsOut parameter in QTVRBackBufferImaging callbackenum {
kQTVRBackBufferFlagDidDraw = 1L << 0,
    kQTVRBackBufferFlagLastFlag = 1L << 31
}
;

// QTVRCursorRecord used in QTVRReplaceCursorstruct QTVRCursorRecord {
UInt16 theType; // field was previously named "type"  SInt16 rsrcID;
Handle handle;
}
;
typedef struct QTVRCursorRecord QTVRCursorRecord;
struct QTVRFloatPoint
{
  float x;
  float y;
};
// Cursor types used in type field of QTVRCursorRecord
// Struct used for areasOfInterest parameter in QTVRSetBackBufferImagingProcstruct QTVRAreaOfInterest {
float panAngle;
float tiltAngle;
float width;
float height;
UInt32 flags;
// Values for flags parameter in QTVRMouseOverHotSpot callback
typedef struct QTVRAreaOfInterest QTVRAreaOfInterest;
/**
// Values for flags parameter in QTVRSetPrescreenImagingCompleteProc
   Callback routines
  -------------------------------------------------------------------------------------------------
*/

typedef CALLBACK_API(OSErr,
                     // Values for flags field of areasOfInterest in QTVRSetBackBufferImagingProc
                     UInt32 fromNodeID, UInt32 toNodeID,
                     Boolean *cancel, SInt32 refCon);
typedef CALLBACK_API(OSErr, QTVREnteringNodeProcPtr)(QTVRInstance qtvr,
                                                     UInt32 nodeID,
                                                     SInt32 refCon);
typedef CALLBACK_API(OSErr, QTVRMouseOverHotSpotProcPtr)(QTVRInstance qtvr,
                                                         UInt32 hotSpotID,
                                                         UInt32 flags,
                                                         SInt32 refCon);
// Values for flagsIn parameter in QTVRBackBufferImaging callback
                                                        SInt32 refCon);
                                                        typedef CALLBACK_API(OSErr, QTVRBackBufferImagingProcPtr)(
                                                            QTVRInstance qtvr, Rect *drawRect, UInt16 areaIndex, UInt32 flagsIn,
                                                            UInt32 *flagsOut, SInt32 refCon);
                                                        typedef STACK_UPP_TYPE(QTVRLeavingNodeProcPtr) QTVRLeavingNodeUPP;
                                                        // Values for flagsOut parameter in QTVRBackBufferImaging callback
                                                        typedef STACK_UPP_TYPE(QTVRMouseOverHotSpotProcPtr) QTVRMouseOverHotSpotUPP;
                                                        typedef STACK_UPP_TYPE(QTVRImagingCompleteProcPtr) QTVRImagingCompleteUPP;
                                                        typedef STACK_UPP_TYPE(QTVRBackBufferImagingProcPtr) QTVRBackBufferImagingUPP;
                                                        /**
                                                         *  NewQTVRLeavingNodeUPP()
                                                        // QTVRCursorRecord used in QTVRReplaceCursor

                                                         *    \non_carbon_// field was previously named "type"
                                                         *    \carbon_lib        in CarbonLib 1.1 and later
                                                         *    \mac_os_x         in version 10.0 and later
                                                         */
                                                        QTVRLeavingNodeUPP
                                                        NewQTVRLeavingNodeUPP(QTVRLeavingNodeProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
                                                        enum
                                                        {
                                                          uppQTVRLeavingNodeProcInfo = 0x0000FFE0
                                                        }; // pascal 2_bytes Func(4_bytes, 4_bytes, 4_bytes, 4_bytes, 4_bytes) #ifdef __cplusplus
                                                        // Struct used for areasOfInterest parameter in QTVRSetBackBufferImagingProc
                                                        NewQTVRLeavingNodeUPP(QTVRLeavingNodeProcPtr userRoutine)
                                                        {
                                                          return (QTVRLeavingNodeUPP)NewRoutineDescriptor((ProcPtr)(userRoutine),
                                                                                                          uppQTVRLeavingNodeProcInfo,
                                                                                                          GetCurrentArchitecture());
                                                        }
#else
#define NewQTVRLeavingNodeUPP(userRoutine)                                     \
                                                          (QTVRLeavingNodeUPP)                                                         \
                                                              NewRoutineDescriptor((ProcPtr)(userRoutine), uppQTVRLeavingNodeProcInfo, \
                                                                                   GetCurrentArchitecture())
#endif
#endif

                                                        /**
                                                         *  NewQTVREnteringNodeUPP()
                                                         *

                                                         *    \non_carbon_cfm   available as macro/inline
                                                         *    \carbon_lib        in CarbonLib 1.1 and later
                                                         *    \mac_os_x         in version 10.0 and later
                                                         */
                                                        QTVREnteringNodeUPP
                                                        NewQTVREnteringNodeUPP(QTVREnteringNodeProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
                                                        enum
                                                        {
                                                          uppQTVREnteringNodeProcInfo = 0x00000FE0
                                                        }; // pascal 2_bytes Func(4_bytes, 4_bytes, 4_bytes) #ifdef __cplusplus
                                                        inline QTVREnteringNodeUPP
                                                        NewQTVREnteringNodeUPP(QTVREnteringNodeProcPtr userRoutine)
                                                        {
                                                          return (QTVREnteringNodeUPP)NewRoutineDescriptor((ProcPtr)(userRoutine),
                                                                                                           uppQTVREnteringNodeProcInfo,
                                                                                                           GetCurrentArchitecture());
                                                        }
#else
#define NewQTVREnteringNodeUPP(userRoutine)                               \
                                                          (QTVREnteringNodeUPP) NewRoutineDescriptor((ProcPtr)(userRoutine),      \
                                                                                                     uppQTVREnteringNodeProcInfo, \
                                                                                                     GetCurrentArchitecture())
#endif
#endif

                                                        /**
                                                         *  NewQTVRMouseOverHotSpotUPP()
                                                         *

                                                         *    \non_carbon_cfm   available as macro/inline
                                                         *    \carbon_lib        in CarbonLib 1.1 and later
                                                         *    \mac_os_x         in version 10.0 and later
                                                         */
                                                        // pascal 2_bytes Func(4_bytes, 4_bytes, 4_bytes, 4_bytes, 4_bytes)
                                                        QTVRMouseOverHotSpotUPP
                                                        NewQTVRMouseOverHotSpotUPP(QTVRMouseOverHotSpotProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
                                                        enum
                                                        {
                                                          uppQTVRMouseOverHotSpotProcInfo = 0x00003FE0
                                                        }; // pascal 2_bytes Func(4_bytes, 4_bytes, 4_bytes, 4_bytes) #ifdef __cplusplus
                                                        inline QTVRMouseOverHotSpotUPP
                                                        NewQTVRMouseOverHotSpotUPP(QTVRMouseOverHotSpotProcPtr userRoutine)
                                                        {
                                                          return (QTVRMouseOverHotSpotUPP)NewRoutineDescriptor(
                                                              (ProcPtr)(userRoutine), uppQTVRMouseOverHotSpotProcInfo,
                                                              GetCurrentArchitecture());
                                                        }
#else
#define NewQTVRMouseOverHotSpotUPP(userRoutine)                \
                                                          (QTVRMouseOverHotSpotUPP) NewRoutineDescriptor(              \
                                                              (ProcPtr)(userRoutine), uppQTVRMouseOverHotSpotProcInfo, \
                                                              GetCurrentArchitecture())
#endif
#endif

                                                        /**
                                                         *  NewQTVRImagingCompleteUPP()
                                                         *

                                                         *    \non_carbon_cfm   available as macro/inline
                                                         *    \carbon_lib        in CarbonLib 1.1 and later
                                                         *    \mac_os_x         in version 10.0 and later
                                                         */
                                                        QTV // pascal 2_bytes Func(4_bytes, 4_bytes, 4_bytes)
                                                        NewQTVRImagingCompleteUPP(QTVRImagingCompleteProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
                                                        enum
                                                        {
                                                          uppQTVRImagingCompleteProcInfo = 0x000003E0
                                                        }; // pascal 2_bytes Func(4_bytes, 4_bytes) #ifdef __cplusplus
                                                        inline QTVRImagingCompleteUPP
                                                        NewQTVRImagingCompleteUPP(QTVRImagingCompleteProcPtr userRoutine)
                                                        {
                                                          return (QTVRImagingCompleteUPP)NewRoutineDescriptor(
                                                              (ProcPtr)(userRoutine), uppQTVRImagingCompleteProcInfo,
                                                              GetCurrentArchitecture());
                                                        }
#else
#define NewQTVRImagingCompleteUPP(userRoutine)                \
                                                          (QTVRImagingCompleteUPP) NewRoutineDescriptor(              \
                                                              (ProcPtr)(userRoutine), uppQTVRImagingCompleteProcInfo, \
                                                              GetCurrentArchitecture())
#endif
#endif

                                                        /**
                                                         *  NewQTVRBackBufferImagingUPP()
                                                         *

                                                         *    \non_carbon_cfm   available as macro/inline
                                                         *    \carbon_lib        in CarbonLib 1.1 and later
                                                         *    \mac_os_x         in version 10.0 and later
                                                         */
                                                        QTVRBackBufferImagingUPP
                                                            New // pascal 2_bytes Func(4_bytes, 4_bytes, 4_bytes, 4_bytes)
#if !OPAQUE_UPP_TYPES
                                                            enum {
                                                              uppQTVRBackBufferImagingProcInfo = 0x0003FBE0
                                                            }; /* pascal 2_bytes Func(4_bytes, 4_bytes, 2_bytes, 4_bytes, 4_bytes, 4_bytes)
                                                                */
#ifdef __cplusplus
                                                        inline QTVRBackBufferImagingUPP
                                                        NewQTVRBackBufferImagingUPP(QTVRBackBufferImagingProcPtr userRoutine)
                                                        {
                                                          return (QTVRBackBufferImagingUPP)NewRoutineDescriptor(
                                                              (ProcPtr)(userRoutine), uppQTVRBackBufferImagingProcInfo,
                                                              GetCurrentArchitecture());
                                                        }
#else
#define NewQTVRBackBufferImagingUPP(userRoutine)                \
                                                          (QTVRBackBufferImagingUPP) NewRoutineDescriptor(              \
                                                              (ProcPtr)(userRoutine), uppQTVRBackBufferImagingProcInfo, \
                                                              GetCurrentArchitecture())
#endif
#endif

                                                        /**
                                                         *  DisposeQTVRLeavingNodeUPP()
                                                         *

                                                         *    \non_carbon_cfm   available as macro/inline
                                                         *    \carbon_lib        in CarbonLib 1.1 and later
                                                         *    \mac_os_x         in version 10.0 and later
                                                         */
                                                        voi // pascal 2_bytes Func(4_bytes, 4_bytes)
                                                        DisposeQTVRLeavingNodeUPP(QTVRLeavingNodeUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
                                                        inline void DisposeQTVRLeavingNodeUPP(QTVRLeavingNodeUPP userUPP)
                                                        {
                                                          DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
                                                        }
#else
#define DisposeQTVRLeavingNodeUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

                                                        /**
                                                         *  DisposeQTVREnteringNodeUPP()
                                                         *

                                                         *    \non_carbon_cfm   available as macro/inline
                                                         *    \carbon_lib        in CarbonLib 1.1 and later
                                                         *    \mac_os_x         in version 10.0 and later
                                                         */
                                                        void
                                                        DisposeQTVREnteringNodeUPP(QTVREnteringNodeUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
                                                        inline void DisposeQTVREnteringNodeUPP(QTVREnteringNodeUPP userUPP)
                                                        {
                                                          DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
                                                        }
#else
#define DisposeQTVREnteringNodeUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

                                                        /**
                                                         *  DisposeQTVRMouseOverHotSpotUPP()
                                                         *

                                                         *    \non_carbon_cfm   available as macro/inline
                                                         *    \carbon_lib        in CarbonLib 1.1 and later
                                                         *    \mac_os_x         in version 10.0 and later
                                                         */
                                                        void
                                                        DisposeQTVRMouseOverHotSpotUPP(QTVRMouseOverHotSpotUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
                                                        inline void DisposeQTVRMouseOverHotSpotUPP(QTVRMouseOverHotSpotUPP userUPP)
                                                        {
                                                          DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
                                                        }
#else
#define DisposeQTVRMouseOverHotSpotUPP(userUPP) \
                                                          DisposeRoutineDescriptor(userUPP)
#endif
#endif

                                                        /**
                                                         *  DisposeQTVRImagingCompleteUPP()
                                                         *

                                                         *    \non_carbon_cfm   available as macro/inline
                                                         *    \carbon_lib        in CarbonLib 1.1 and later
                                                         *    \mac_os_x         in version 10.0 and later
                                                         */
                                                        void
                                                        DisposeQTVRImagingCompleteUPP(QTVRImagingCompleteUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
                                                        inline void DisposeQTVRImagingCompleteUPP(QTVRImagingCompleteUPP userUPP)
                                                        {
                                                          DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
                                                        }
#else
#define DisposeQTVRImagingCompleteUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

                                                        /**
                                                         *  DisposeQTVRBackBufferImagingUPP()
                                                         *

                                                         *    \non_carbon_cfm   available as macro/inline
                                                         *    \carbon_lib        in CarbonLib 1.1 and later
                                                         *    \mac_os_x         in version 10.0 and later
                                                         */
                                                        void
                                                        DisposeQTVRBackBufferImagingUPP(QTVRBackBufferImagingUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
                                                        inline void DisposeQTVRBackBufferImagingUPP(QTVRBackBufferImagingUPP userUPP)
                                                        {
                                                          DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
                                                        }
#else
#define DisposeQTVRBackBufferImagingUPP(userUPP) \
                                                          DisposeRoutineDescriptor(userUPP)
#endif
#endif

                                                        /**
                                                         *  InvokeQTVRLeavingNodeUPP()
                                                         *

                                                         *    \non_carbon_cfm   available as macro/inline
                                                         *    \carbon_lib        in CarbonLib 1.1 and later
                                                         *    \mac_os_x         in version 10.0 and later
                                                         */
                                                        OSErr
                                                        InvokeQTVRLeavingNodeUPP(QTVRInstance qtvr, UInt32 fromNodeID, UInt32 toNodeID,
                                                                                 Boolean *cancel, SInt32 refCon,
                                                                                 QTVRLeavingNodeUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
                                                        inline OSErr InvokeQTVRLeavingNodeUPP(QTVRInstance qtvr, UInt32 fromNodeID,
                                                                                              UInt32 toNodeID, Boolean *cancel,
                                                                                              SInt32 refCon,
                                                                                              QTVRLeavingNodeUPP userUPP)
                                                        {
                                                          return (OSErr)CALL_FIVE_PARAMETER_UPP(userUPP, uppQTVRLeavingNodeProcInfo,
                                                                                                qtvr, fromNodeID, toNodeID, cancel,
                                                                                                refCon);
                                                        }
#else
#define InvokeQTVRLeavingNodeUPP(qtvr, fromNodeID, toNodeID, cancel, refCon, \
                                                                                         userUPP)                                    \
                                                          (OSErr)                                                                    \
                                                              CALL_FIVE_PARAMETER_UPP((userUPP), uppQTVRLeavingNodeProcInfo, (qtvr), \
                                                                                      (fromNodeID), (toNodeID), (cancel), (refCon))
#endif
#endif

                                                        /**
                                                         *  InvokeQTVREnteringNodeUPP()
                                                         *

                                                         *    \non_carbon_cfm   available as macro/inline
                                                         *    \carbon_lib        in CarbonLib 1.1 and later
                                                         *    \mac_os_x         in version 10.0 and later
                                                         */
                                                        OSErr
                                                        InvokeQTVREnteringNodeUPP(QTVRInstance qtvr, UInt32 nodeID, SInt32 refCon,
                                                                                  QTVREnteringNodeUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
                                                        inline OSErr InvokeQTVREnteringNodeUPP(QTVRInstance qtvr, UInt32 nodeID,
                                                                                               SInt32 refCon,
                                                                                               QTVREnteringNodeUPP userUPP)
                                                        {
                                                          return (OSErr)CALL_THREE_PARAMETER_UPP(userUPP, uppQTVREnteringNodeProcInfo,
                                                                                                 qtvr, nodeID, refCon);
                                                        }
#else
#define InvokeQTVREnteringNodeUPP(qtvr, nodeID, refCon, userUPP)           \
                                                          (OSErr) CALL_THREE_PARAMETER_UPP((userUPP), uppQTVREnteringNodeProcInfo, \
                                                                                           (qtvr), (nodeID), (refCon))
#endif
#endif

                                                        /**
                                                         *  InvokeQTVRMouseOverHotSpotUPP()
                                                         *

                                                         *    \non_carbon_cfm   available as macro/inline
                                                         *    \carbon_lib        in CarbonLib 1.1 and later
                                                         *    \mac_os_x         in version 10.0 and later
                                                         */
                                                        OSErr
                                                        InvokeQTVRMouseOverHotSpotUPP(QTVRInstance qtvr, UInt32 hotSpotID, UInt32 flags,
                                                                                      SInt32 refCon, QTVRMouseOverHotSpotUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
                                                        inline OSErr InvokeQTVRMouseOverHotSpotUPP(QTVRInstance qtvr, UInt32 hotSpotID,
                                                                                                   UInt32 flags, SInt32 refCon,
                                                                                                   QTVRMouseOverHotSpotUPP userUPP)
                                                        {
                                                          return (OSErr)CALL_FOUR_PARAMETER_UPP(
                                                              userUPP, uppQTVRMouseOverHotSpotProcInfo, qtvr, hotSpotID, flags, refCon);
                                                        }
#else
#define InvokeQTVRMouseOverHotSpotUPP(qtvr, hotSpotID, flags, refCon, userUPP) \
                                                          (OSErr) CALL_FOUR_PARAMETER_UPP((userUPP), uppQTVRMouseOverHotSpotProcInfo,  \
                                                                                          (qtvr), (hotSpotID), (flags), (refCon))
#endif
#endif

                                                        /**
                                                         *  InvokeQTVRImagingCompleteUPP()
                                                         *

                                                         *    \non_carbon_cfm   available as macro/inline
                                                         *    \carbon_lib        in CarbonLib 1.1 and later
                                                         *    \mac_os_x         in version 10.0 and later
                                                         */
                                                        OSErr
                                                        InvokeQTVRImagingCompleteUPP(QTVRInstance qtvr, SInt32 refCon,
                                                                                     QTVRImagingCompleteUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
                                                        inline OSErr InvokeQTVRImagingCompleteUPP(QTVRInstance qtvr, SInt32 refCon,
                                                                                                  QTVRImagingCompleteUPP userUPP)
                                                        {
                                                          return (OSErr)CALL_TWO_PARAMETER_UPP(userUPP, uppQTVRImagingCompleteProcInfo,
                                                                                               qtvr, refCon);
                                                        }
#else
#define InvokeQTVRImagingCompleteUPP(qtvr, refCon, userUPP)                 \
                                                          (OSErr) CALL_TWO_PARAMETER_UPP((userUPP), uppQTVRImagingCompleteProcInfo, \
                                                                                         (qtvr), (refCon))
#endif
#endif

                                                        /**
                                                         *  InvokeQTVRBackBufferImagingUPP()
                                                         *

                                                         *    \non_carbon_cfm   available as macro/inline
                                                         *    \carbon_lib        in CarbonLib 1.1 and later
                                                         *    \mac_os_x         in version 10.0 and later
                                                         */
                                                        OSErr
                                                        InvokeQTVRBackBufferImagingUPP(QTVRInstance qtvr, Rect *drawRect,
                                                                                       UInt16 areaIndex, UInt32 flagsIn,
                                                                                       UInt32 *flagsOut, SInt32 refCon,
                                                                                       QTVRBackBufferImagingUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
                                                        inline OSErr InvokeQTVRBackBufferImagingUPP(QTVRInstance qtvr, Rect *drawRect,
                                                                                                    UInt16 areaIndex, UInt32 flagsIn,
                                                                                                    UInt32 *flagsOut, SInt32 refCon,
                                                                                                    QTVRBackBufferImagingUPP userUPP)
                                                        {
                                                          return (OSErr)CALL_SIX_PARAMETER_UPP(
                                                              userUPP, uppQTVRBackBufferImagingProcInfo, qtvr, drawRect, areaIndex,
                                                              flagsIn, flagsOut, refCon);
                                                        }
#else
#define InvokeQTVRBackBufferImagingUPP(qtvr, drawRect, areaIndex, flagsIn,    \
                                                                                               flagsOut, refCon, userUPP)             \
                                                          (OSErr) CALL_SIX_PARAMETER_UPP((userUPP), uppQTVRBackBufferImagingProcInfo, \
                                                                                         (qtvr), (drawRect), (areaIndex), (flagsIn),  \
                                                                                         (flagsOut), (refCon))
#endif
#endif

#if CALL_NOT_IN_CARBON || OLDROUTINENAMES
                                                        // support for pre-Carbon UPP routines: New...Proc and Call...Proc #define NewQTVRLeavingNodeProc(userRoutine) NewQTVRLeavingNodeUPP(userRoutine)
#define NewQTVREnteringNodeProc(userRoutine) NewQTVREnteringNodeUPP(userRoutine)
#define NewQTVRMouseOverHotSpotProc(userRoutine) \
                                                          NewQTVRMouseOverHotSpotUPP(userRoutine)
#define NewQTVRImagingCompleteProc(userRoutine) \
                                                          NewQTVRImagingCompleteUPP(userRoutine)
#define NewQTVRBackBufferImagingProc(userRoutine) \
                                                          NewQTVRBackBufferImagingUPP(userRoutine)
#define CallQTVRLeavingNodeProc(userRoutine, qtvr, fromNodeID, toNodeID, \
                                                                                        cancel, refCon)                          \
                                                          InvokeQTVRLeavingNodeUPP(qtvr, fromNodeID, toNodeID, cancel, refCon,   \
                                                                                   userRoutine)
#define CallQTVREnteringNodeProc(userRoutine, qtvr, nodeID, refCon) \
                                                          InvokeQTVREnteringNodeUPP(qtvr, nodeID, refCon, userRoutine)
#define CallQTVRMouseOverHotSpotProc(userRoutine, qtvr, hotSpotID, flags, \
                                                                                             refCon)                              \
                                                          InvokeQTVRMouseOverHotSpotUPP(qtvr, hotSpotID, flags, refCon, userRoutine)
#define CallQTVRImagingCompleteProc(userRoutine, qtvr, refCon) \
                                                          InvokeQTVRImagingCompleteUPP(qtvr, refCon, userRoutine)
#define CallQTVRBackBufferImagingProc(userRoutine, qtvr, drawRect, areaIndex,  \
                                                                                              flagsIn, flagsOut, refCon)               \
                                                          InvokeQTVRBackBufferImagingUPP(qtvr, drawRect, areaIndex, flagsIn, flagsOut, \
                                                                                         refCon, userRoutine)
#endif // CALL_NOT_IN_CARBON
                                                        /**
                                                          =================================================================================================
                                                            QTVR Intercept Struct, Callback, Routine Descriptors
                                                          -------------------------------------------------------------------------------------------------
                                                        */

                                                        typedef UInt32 QTVRProcSelector;
                                                        enum
                                                        {
                                                          kQTVRSetPanAngleSelector = 0x2000,
                                                          kQTVRSetTiltAngleSelector = 0x2001,
                                                          kQTVRSetFieldOfViewSelector = 0x2002,
                                                          kQTVRSetViewCenterSelector = 0x2003,
                                                          kQTVRMouseEnterSelector = 0x2004,
                                                          kQTVRMouseWithinSelector = 0x2005,
                                                          kQTVRMouseLeaveSelector = 0x2006,
                                                          kQTVRMouseDownSelector = 0x2007,
                                                          kQTVRMouseStillDownSelector = 0x2008,
                                                          kQTVRMouseUpSelector = 0x2009,
                                                          kQTVRTriggerHotSpotSelector = 0x200A,
                                                          kQTVRGetHotSpotTypeSelector =
                                                              0x200B, /* Requires QTVR 2.1 (kQTVRAPIMajorVersion02 +
                                                                         kQTVRAPIMinorVersion10)*/
                                                          kQTVRSetViewParameterSelector =
                                                              0x200C, /* Requires QTVR 5.0 (kQTVRAPIMajorVersion05 +
                                                                         kQTVRAPIMinorVersion00)*/
                                                          kQTVRGetViewParameterSelector =
                                                              0x200D /* Requires QTVR 5.0 (kQTVRAPIMajorVersion05 +
                                                                        kQTVRAPIMinorVersion00)*/
                                                        };

                                                        // support for pre-Carbon UPP routines: New...Proc and Call...Proc
                                                        SInt32 reserved1;
                                                        SInt32 selector;

                                                        SInt32 reserved2;
                                                        SInt32 reserved3;

                                                        SInt32 paramCount;
                                                        void *parameter[6];
                                                        }
                                                        ;
                                                        typedef struct QTVRInterceptRecord QTVRInterceptRecord;
                                                        typedef QTVRInterceptRecord *QTVRInterceptPtr;
                                                        // Prototype for Intercept Proc callbacktypedef CALLBACK_API(void, QTVRInterceptProcPtr)(QTVRInstance qtvr,
                                                 QTVRInterceptPtr qtvrMsg,
                                                 SInt32 refCon,
                                                 Boolean *cancel);
                                                 typedef STACK_UPP_TYPE(QTVRInterceptProcPtr) QTVRInterceptUPP;
                                                 /**
                                                  *  NewQTVRInterceptUPP()
                                                  *

                                                  *    \non_carbon_cfm   available as macro/inline
                                                  *    \carbon_lib        in CarbonLib 1.1 and later
                                                  *    \mac_os_x         in version 10.0 and later
                                                  */
                                                 // CALL_NOT_IN_CARBON
                                                 QTVRInterceptUPP
                                                 NewQTVRInterceptUPP(QTVRInterceptProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
                                                 enum
                                                 {
                                                   uppQTVRInterceptProcInfo = 0x00003FC0
                                                 }; // pascal no_return_value Func(4_bytes, 4_bytes, 4_bytes, 4_bytes) #ifdef __cplusplus
                                                 inline QTVRInterceptUPP NewQTVRInterceptUPP(QTVRInterceptProcPtr userRoutine)
                                                 {
                                                   return (QTVRInterceptUPP)NewRoutineDescriptor((ProcPtr)(userRoutine),
                                                                                                 uppQTVRInterceptProcInfo,
                                                                                                 GetCurrentArchitecture());
                                                 }
#else
#define NewQTVRInterceptUPP(userRoutine)                                     \
                                                   (QTVRInterceptUPP)                                                         \
                                                       NewRoutineDescriptor((ProcPtr)(userRoutine), uppQTVRInterceptProcInfo, \
                                                                            GetCurrentArchitecture())
#endif
#endif

                                                 /**
                                                  *  DisposeQTVRInterceptUPP()
                                                  *

                                                  *    \non_carbon_cfm   available as macro/inline
                                                  *    \carbon_lib        in CarbonLib 1.1 and later
                                                  *    \mac_os_x         in version 10.0 and later
                                                  */
                                                 void
                                                 DisposeQTVRInterceptUPP(QTVRInterceptUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
                                                 inline void DisposeQTVRInterceptUPP(QTVRInterceptUPP userUPP)
                                                 {
                                                   DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
                                                 }
#else
#define DisposeQTVRInterceptUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

                                                 /**
                                                  *  InvokeQTVRInterceptUPP()
                                                  *

                                                 // Prototype for Intercept Proc callback
                                                  *    \carbon_lib        in CarbonLib 1.1 and later
                                                  *    \mac_os_x         in version 10.0 and later
                                                  */
                                                 void
                                                 InvokeQTVRInterceptUPP(QTVRInstance qtvr, QTVRInterceptPtr qtvrMsg,
                                                                        SInt32 refCon, Boolean *cancel,
                                                                        QTVRInterceptUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
                                                 inline void InvokeQTVRInterceptUPP(QTVRInstance qtvr, QTVRInterceptPtr qtvrMsg,
                                                                                    SInt32 refCon, Boolean *cancel,
                                                                                    QTVRInterceptUPP userUPP)
                                                 {
                                                   CALL_FOUR_PARAMETER_UPP(userUPP, uppQTVRInterceptProcInfo, qtvr, qtvrMsg,
                                                                           refCon, cancel);
                                                 }
#else
#define InvokeQTVRInterceptUPP(qtvr, qtvrMsg, refCon, cancel, userUPP) \
  CALL_FOUR_PARAMETER_UPP((userUPP), uppQTVRInterceptProcInfo, (qtvr),                                                  \
                                                   // pascal no_return_value Func(4_bytes, 4_bytes, 4_bytes, 4_bytes)
#endif
#endif

#if CALL_NOT_IN_CARBON || OLDROUTINENAMES
                                                 // support for pre-Carbon UPP routines: New...Proc and Call...Proc #define NewQTVRInterceptProc(userRoutine) NewQTVRInterceptUPP(userRoutine)
#define CallQTVRInterceptProc(userRoutine, qtvr, qtvrMsg, refCon, cancel) \
                                                   InvokeQTVRInterceptUPP(qtvr, qtvrMsg, refCon, cancel, userRoutine)
#endif // CALL_NOT_IN_CARBON
                                                        /**
                                                          =================================================================================================
                                                            Initialization QTVR calls
                                                          -------------------------------------------------------------------------------------------------
                                                           Requires QTVR 2.1 (kQTVRAPIMajorVersion02 + kQTVRAPIMinorVersion10) and only
                                                          work on Non-Macintosh platforms
                                                        */
#if !TARGET_OS_MAC
#if CALL_NOT_IN_CARBON
                                                 /**
                                                  *  InitializeQTVR()
                                                  *

                                                  *    \non_carbon_cfm   not available
                                                  *    \carbon_lib        not available
                                                  *    \mac_os_x         not available
                                                  *    Windows:          in QTVR.lib 2.1 and later
                                                  */
                                                 OSErr
                                                 InitializeQTVR(void);

                                                 /**
                                                  *  TerminateQTVR()
                                                  *

                                                  *    \non_carbon_cfm   not available
                                                  *    \carbon_lib        not available
                                                  *    \mac_os_x         not available
                                                  *    Windows:          in QTVR.lib 2.1 and later
                                                  */
                                                 OSErr
                                                 TerminateQTVR(void);

#endif // CALL_NOT_IN_CARBON
#endif // !TARGET_OS_MAC
                                                 /**
                                                   =================================================================================================
                                                     General QTVR calls
                                                   -------------------------------------------------------------------------------------------------
                                                 */
                                                 /**
                                                  *  QTVRGetQTVRTrack()
                                                  *

                                                  *    \non_carbon_cfm   in QuickTimeVRLib 2.0 and later
                                                  *    \carbon_lib        in CarbonLib 1.1 and later
                                                  *    \mac_os_x         in version 10.0 and later
                                                  *    Windows:          in QTVR.lib 2.1 and later
                                                  */
                                                 Track
                                                 QTVRGetQTVRTrack(Movie theMovie, SInt32 index);

                                                 /**
                                                  *  QTVRGetQTVRInstance()
                                                 // support for pre-Carbon UPP routines: New...Proc and Call...Proc

                                                  *    \non_carbon_cfm   in QuickTimeVRLib 2.0 and later
                                                  *    \carbon_lib        in CarbonLib 1.1 and later
                                                  *    \// CALL_NOT_IN_CARBON
                                                  *    Windows:          in QTVR.lib 2.1 and later
                                                  */
                                                 OSErr
                                                 QTVRGetQTVRInstance(QTVRInstance *qtvr, Track qtvrTrack, MovieController mc);

                                                 /**
                                                   =================================================================================================
                                                     Viewing Angles and Zooming
                                                   -------------------------------------------------------------------------------------------------
                                                 */

                                                 /* QTVRSetViewParameter requires QTVR 5.0 (kQTVRAPIMajorVersion05 +
                                                  * kQTVRAPIMinorVersion00)*/
                                                 /**
                                                  *  QTVRSetViewParameter()
                                                  *

                                                  *    \non_carbon_cfm   in QuickTimeVRLib 5.0 and later
                                                  *    \carbon_lib        in CarbonLib 1.3 and later
                                                  *    \mac_os_x         in version 10.0 and later
                                                  *    Windows:          in QTVR.lib 5.0 and later
                                                  */
                                                 OSErr
                                                 QTVRSetViewParameter(QTVRInstance qtvr, UInt32 viewParameter, void *value,
                                                                      UInt32 flagsIn);

                                                 /* QTVRGetViewParameter requires QTVR 5.0 (kQTVRAPIMajorVersion05 +
                                                  * kQTVRAPIMinorVersion00)*/
                                                 /**
                                                  *  QTVRGetViewParameter()
                                                  *

                                                  *    \non_carbon_cfm   in QuickTimeVRLib 5.0 and later
                                                  *    \carbon_lib        in CarbonLib 1.3 and later
                                                  *    \// CALL_NOT_IN_CARBON
                                                  *    Windows:          in QTVR.lib 5.0 and later
                                                  */
                                                 // !TARGET_OS_MAC
                                                 OSErr
                                                 QTVRGetViewParameter(QTVRInstance qtvr, UInt32 viewParameter, void *value,
                                                                      UInt32 flagsIn, UInt32 *flagsOut);

                                                 /**
                                                  *  QTVRSetPanAngle()
                                                  *

                                                  *    \non_carbon_cfm   in QuickTimeVRLib 2.0 and later
                                                  *    \carbon_lib        in CarbonLib 1.1 and later
                                                  *    \mac_os_x         in version 10.0 and later
                                                  *    Windows:          in QTVR.lib 2.1 and later
                                                  */
                                                 OSErr
                                                 QTVRSetPanAngle(QTVRInstance qtvr, float panAngle);

                                                 /**
                                                  *  QTVRGetPanAngle()
                                                  *

                                                  *    \non_carbon_cfm   in QuickTimeVRLib 2.0 and later
                                                  *    \carbon_lib        in CarbonLib 1.1 and later
                                                  *    \mac_os_x         in version 10.0 and later
                                                  *    Windows:          in QTVR.lib 2.1 and later
                                                  */
                                                 float
                                                 QTVRGetPanAngle(QTVRInstance qtvr);

                                                 /**
                                                  *  QTVRSetTiltAngle()
                                                  *

                                                  *    \non_carbon_cfm   in QuickTimeVRLib 2.0 and later
                                                  *    \carbon_lib        in CarbonLib 1.1 and later
                                                  *    \mac_os_x         in version 10.0 and later
                                                  *    Windows:          in QTVR.lib 2.1 and later
                                                  */
                                                 OSErr
                                                 QTVRSetTiltAngle(QTVRInstance qtvr, float tiltAngle);

                                                 /**
                                                  *  QTVRGetTiltAngle()
                                                  *

                                                  *    \non_carbon_cfm   in QuickTimeVRLib 2.0 and later
                                                  *    \carbon_lib        in CarbonLib 1.1 and later
                                                  *    \mac_os_x         in version 10.0 and later
                                                  *    Windows:          in QTVR.lib 2.1 and later
                                                  */
                                                 float
                                                 QTVRGetTiltAngle(QTVRInstance qtvr);

                                                 /**
                                                  *  QTVRSetFieldOfView()
                                                  *

                                                  *    \non_carbon_cfm   in QuickTimeVRLib 2.0 and later
                                                  *    \carbon_lib        in CarbonLib 1.1 and later
                                                  *    \mac_os_x         in version 10.0 and later
                                                  *    Windows:          in QTVR.lib 2.1 and later
                                                  */
                                                 OSErr
                                                 QTVRSetFieldOfView(QTVRInstance qtvr, float fieldOfView);

                                                 /**
                                                  *  QTVRGetFieldOfView()
                                                  *

                                                  *    \non_carbon_cfm   in QuickTimeVRLib 2.0 and later
                                                  *    \carbon_lib        in CarbonLib 1.1 and later
                                                  *    \mac_os_x         in version 10.0 and later
                                                  *    Windows:          in QTVR.lib 2.1 and later
                                                  */
                                                 float
                                                 QTVRGetFieldOfView(QTVRInstance qtvr);

                                                 /**
                                                  *  QTVRShowDefaultView()
                                                  *

                                                  *    \non_carbon_cfm   in QuickTimeVRLib 2.0 and later
                                                  *    \carbon_lib        in CarbonLib 1.1 and later
                                                  *    \mac_os_x         in version 10.0 and later
                                                  *    Windows:          in QTVR.lib 2.1 and later
                                                  */
                                                 OSErr
                                                 QTVRShowDefaultView(QTVRInstance qtvr);

                                                 // Object Specific
                                                 /**QTVRSetViewCenter() *

                                                         *    \non_carbon_cfm in QuickTimeVRLib 2.0 and
                                                     later
                                                         *    \carbon_lib in CarbonLib 1.1 and
                                                     later
                                                         *    \mac_os_x in version 10.0 and
                                                     later
                                                         *Windows : in QTVR.lib 2.1 and
                                                     later */
                                                 OSErr
                                                 QTVRSetViewCenter(QTVRInstance qtvr, const QTVRFloatPoint *viewCenter);

                                                 /**
                                                  *  QTVRGetViewCenter()
                                                  *

                                                  *    \non_carbon_cfm   in QuickTimeVRLib 2.0 and later
                                                  *    \carbon_lib        in CarbonLib 1.1 and later
                                                  *    \mac_os_x         in version 10.0 and later
                                                  *    Windows:          in QTVR.lib 2.1 and later
                                                  */
                                                 OSErr
                                                 QTVRGetViewCenter(QTVRInstance qtvr, QTVRFloatPoint *viewCenter);

                                                 /**
                                                  *  QTVRNudge()
                                                  *

                                                  *    \non_carbon_cfm   in QuickTimeVRLib 2.0 and later
                                                  *    \carbon_lib        in CarbonLib 1.1 and later
                                                  *    \mac_os_x         in version 10.0 and later
                                                  *    Windows:          in QTVR.lib 2.1 and later
                                                  */
                                                 OSErr
                                                 QTVRNudge(QTVRInstance qtvr, QTVRNudgeControl direction);

                                                 /* QTVRInteractionNudge requires QTVR 2.1 (kQTVRAPIMajorVersion02 +
                                                  * kQTVRAPIMinorVersion10)*/
                                                 /**
                                                  *  QTVRInteractionNudge()
                                                  *

                                                  *    \non_carbon_cfm   in QuickTimeVRLib 2.1 and later
                                                  *    \carbon_lib        in CarbonLib 1.1 and later
                                                  *    \mac_os_x         in version 10.0 and later
                                                  *    Windows:          in QTVR.lib 2.1 and later
                                                  */
                                                 OSErr
                                                 QTVRInteractionNudge(QTVRInstance qtvr, QTVRNudgeControl direction);

                                                 /**
                                                   =================================================================================================
                                                     Scene and Node Location Information
                                                   -------------------------------------------------------------------------------------------------
                                                 */

                                                 /**
                                                  *  QTVRGetVRWorld()
                                                  *

                                                  *    \non_carbon_cfm   in QuickTimeVRLib 2.0 and later
                                                  *    \carbon_lib        in CarbonLib 1.1 and later
                                                 // Object Specific
                                                  *    Windows:          in QTVR.lib 2.1 and later
                                                  */
                                                 OSErr
                                                 QTVRGetVRWorld(QTVRInstance qtvr, QTAtomContainer *VRWorld);

                                                 /**
                                                  *  QTVRGetNodeInfo()
                                                  *

                                                  *    \non_carbon_cfm   in QuickTimeVRLib 2.0 and later
                                                  *    \carbon_lib        in CarbonLib 1.1 and later
                                                  *    \mac_os_x         in version 10.0 and later
                                                  *    Windows:          in QTVR.lib 2.1 and later
                                                  */
                                                 OSErr
                                                 QTVRGetNodeInfo(QTVRInstance qtvr, UInt32 nodeID, QTAtomContainer *nodeInfo);

                                                 /**
                                                  *  QTVRGoToNodeID()
                                                  *

                                                  *    \non_carbon_cfm   in QuickTimeVRLib 2.0 and later
                                                  *    \carbon_lib        in CarbonLib 1.1 and later
                                                  *    \mac_os_x         in version 10.0 and later
                                                  *    Windows:          in QTVR.lib 2.1 and later
                                                  */
                                                 OSErr
                                                 QTVRGoToNodeID(QTVRInstance qtvr, UInt32 nodeID);

                                                 /**
                                                  *  QTVRGetCurrentNodeID()
                                                  *

                                                  *    \non_carbon_cfm   in QuickTimeVRLib 2.0 and later
                                                  *    \carbon_lib        in CarbonLib 1.1 and later
                                                  *    \mac_os_x         in version 10.0 and later
                                                  *    Windows:          in QTVR.lib 2.1 and later
                                                  */
                                                 UInt32
                                                 QTVRGetCurrentNodeID(QTVRInstance qtvr);

                                                 /**
                                                  *  QTVRGetNodeType()
                                                  *

                                                  *    \non_carbon_cfm   in QuickTimeVRLib 2.0 and later
                                                  *    \carbon_lib        in CarbonLib 1.1 and later
                                                  *    \mac_os_x         in version 10.0 and later
                                                  *    Windows:          in QTVR.lib 2.1 and later
                                                  */
                                                 OSType
                                                 QTVRGetNodeType(QTVRInstance qtvr, UInt32 nodeID);

                                                 /**
                                                   =================================================================================================
                                                     Hot Spot related calls
                                                   -------------------------------------------------------------------------------------------------
                                                 */

                                                 /**
                                                  *  QTVRPtToHotSpotID()
                                                  *

                                                  *    \non_carbon_cfm   in QuickTimeVRLib 2.0 and later
                                                  *    \carbon_lib        in CarbonLib 1.1 and later
                                                  *    \mac_os_x         in version 10.0 and later
                                                  *    Windows:          in QTVR.lib 2.1 and later
                                                  */
                                                 OSErr
                                                 QTVRPtToHotSpotID(QTVRInstance qtvr, Point pt, UInt32 *hotSpotID);

                                                 /* QTVRGetHotSpotType requires QTVR 2.1 (kQTVRAPIMajorVersion02 +
                                                  * kQTVRAPIMinorVersion10)*/
                                                 /**
                                                  *  QTVRGetHotSpotType()
                                                  *

                                                  *    \non_carbon_cfm   in QuickTimeVRLib 2.1 and later
                                                  *    \carbon_lib        in CarbonLib 1.1 and later
                                                  *    \mac_os_x         in version 10.0 and later
                                                  *    Windows:          in QTVR.lib 2.1 and later
                                                  */
                                                 OSErr
                                                 QTVRGetHotSpotType(QTVRInstance qtvr, UInt32 hotSpotID, OSType *hotSpotType);

                                                 /**
                                                  *  QTVRTriggerHotSpot()
                                                  *

                                                  *    \non_carbon_cfm   in QuickTimeVRLib 2.0 and later
                                                  *    \carbon_lib        in CarbonLib 1.1 and later
                                                  *    \mac_os_x         in version 10.0 and later
                                                  *    Windows:          in QTVR.lib 2.1 and later
                                                  */
                                                 OSErr
                                                 QTVRTriggerHotSpot(QTVRInstance qtvr, UInt32 hotSpotID,
                                                                    QTAtomContainer nodeInfo, QTAtom selectedAtom);

                                                 /**
                                                  *  QTVRSetMouseOverHotSpotProc()
                                                  *

                                                  *    \non_carbon_cfm   in QuickTimeVRLib 2.0 and later
                                                  *    \carbon_lib        in CarbonLib 1.1 and later
                                                  *    \mac_os_x         in version 10.0 and later
                                                  *    Windows:          in QTVR.lib 2.1 and later
                                                  */
                                                 OSErr
                                                 QTVRSetMouseOverHotSpotProc(QTVRInstance qtvr,
                                                                             QTVRMouseOverHotSpotUPP mouseOverHotSpotProc,
                                                                             SInt32 refCon, UInt32 flags);

                                                 /**
                                                  *  QTVREnableHotSpot()
                                                  *

                                                  *    \non_carbon_cfm   in QuickTimeVRLib 2.0 and later
                                                  *    \carbon_lib        in CarbonLib 1.1 and later
                                                  *    \mac_os_x         in version 10.0 and later
                                                  *    Windows:          in QTVR.lib 2.1 and later
                                                  */
                                                 OSErr
                                                 QTVREnableHotSpot(QTVRInstance qtvr, UInt32 enableFlag, UInt32 hotSpotValue,
                                                                   Boolean enable);

                                                 /**
                                                  *  QTVRGetVisibleHotSpots()
                                                  *

                                                  *    \non_carbon_cfm   in QuickTimeVRLib 2.0 and later
                                                  *    \carbon_lib        in CarbonLib 1.1 and later
                                                  *    \mac_os_x         in version 10.0 and later
                                                  *    Windows:          in QTVR.lib 2.1 and later
                                                  */
                                                 UInt32
                                                 QTVRGetVisibleHotSpots(QTVRInstance qtvr, Handle hotSpots);

                                                 /**
                                                  *  QTVRGetHotSpotRegion()
                                                  *

                                                  *    \non_carbon_cfm   in QuickTimeVRLib 2.0 and later
                                                  *    \carbon_lib        in CarbonLib 1.1 and later
                                                  *    \mac_os_x         in version 10.0 and later
                                                  *    Windows:          in QTVR.lib 2.1 and later
                                                  */
                                                 OSErr
                                                 QTVRGetHotSpotRegion(QTVRInstance qtvr, UInt32 hotSpotID,
                                                                      RgnHandle hotSpotRegion);

                                                 /**
                                                   =================================================================================================
                                                     Event & Cursor Handling Calls
                                                   -------------------------------------------------------------------------------------------------
                                                 */

                                                 /**
                                                  *  QTVRSetMouseOverTracking()
                                                  *

                                                  *    \non_carbon_cfm   in QuickTimeVRLib 2.0 and later
                                                  *    \carbon_lib        in CarbonLib 1.1 and later
                                                  *    \mac_os_x         in version 10.0 and later
                                                  *    Windows:          in QTVR.lib 2.1 and later
                                                  */
                                                 OSErr
                                                 QTVRSetMouseOverTracking(QTVRInstance qtvr, Boolean enable);

                                                 /**
                                                  *  QTVRGetMouseOverTracking()
                                                  *

                                                  *    \non_carbon_cfm   in QuickTimeVRLib 2.0 and later
                                                  *    \carbon_lib        in CarbonLib 1.1 and later
                                                  *    \mac_os_x         in version 10.0 and later
                                                  *    Windows:          in QTVR.lib 2.1 and later
                                                  */
                                                 Boolean
                                                 QTVRGetMouseOverTracking(QTVRInstance qtvr);

                                                 /**
                                                  *  QTVRSetMouseDownTracking()
                                                  *

                                                  *    \non_carbon_cfm   in QuickTimeVRLib 2.0 and later
                                                  *    \carbon_lib        in CarbonLib 1.1 and later
                                                  *    \mac_os_x         in version 10.0 and later
                                                  *    Windows:          in QTVR.lib 2.1 and later
                                                  */
                                                 OSErr
                                                 QTVRSetMouseDownTracking(QTVRInstance qtvr, Boolean enable);

                                                 /**
                                                  *  QTVRGetMouseDownTracking()
                                                  *

                                                  *    \non_carbon_cfm   in QuickTimeVRLib 2.0 and later
                                                  *    \carbon_lib        in CarbonLib 1.1 and later
                                                  *    \mac_os_x         in version 10.0 and later
                                                  *    Windows:          in QTVR.lib 2.1 and later
                                                  */
                                                 Boolean
                                                 QTVRGetMouseDownTracking(QTVRInstance qtvr);

                                                 /**
                                                  *  QTVRMouseEnter()
                                                  *

                                                  *    \non_carbon_cfm   in QuickTimeVRLib 2.0 and later
                                                  *    \carbon_lib        in CarbonLib 1.1 and later
                                                  *    \mac_os_x         in version 10.0 and later
                                                  *    Windows:          in QTVR.lib 2.1 and later
                                                  */
                                                 OSErr
                                                 QTVRMouseEnter(QTVRInstance qtvr, Point pt, UInt32 *hotSpotID, WindowRef w);

                                                 /**
                                                  *  QTVRMouseWithin()
                                                  *

                                                  *    \non_carbon_cfm   in QuickTimeVRLib 2.0 and later
                                                  *    \carbon_lib        in CarbonLib 1.1 and later
                                                  *    \mac_os_x         in version 10.0 and later
                                                  *    Windows:          in QTVR.lib 2.1 and later
                                                  */
                                                 OSErr
                                                 QTVRMouseWithin(QTVRInstance qtvr, Point pt, UInt32 *hotSpotID, WindowRef w);

                                                 /**
                                                  *  QTVRMouseLeave()
                                                  *

                                                  *    \non_carbon_cfm   in QuickTimeVRLib 2.0 and later
                                                  *    \carbon_lib        in CarbonLib 1.1 and later
                                                  *    \mac_os_x         in version 10.0 and later
                                                  *    Windows:          in QTVR.lib 2.1 and later
                                                  */
                                                 OSErr
                                                 QTVRMouseLeave(QTVRInstance qtvr, Point pt, WindowRef w);

                                                 /**
                                                  *  QTVRMouseDown()
                                                  *

                                                  *    \non_carbon_cfm   in QuickTimeVRLib 2.0 and later
                                                  *    \carbon_lib        in CarbonLib 1.1 and later
                                                  *    \mac_os_x         in version 10.0 and later
                                                  *    Windows:          in QTVR.lib 2.1 and later
                                                  */
                                                 OSErr
                                                 QTVRMouseDown(QTVRInstance qtvr, Point pt, UInt32 when, UInt16 modifiers,
                                                               UInt32 *hotSpotID, WindowRef w);

                                                 /**
                                                  *  QTVRMouseStillDown()
                                                  *

                                                  *    \non_carbon_cfm   in QuickTimeVRLib 2.0 and later
                                                  *    \carbon_lib        in CarbonLib 1.1 and later
                                                  *    \mac_os_x         in version 10.0 and later
                                                  *    Windows:          in QTVR.lib 2.1 and later
                                                  */
                                                 OSErr
                                                 QTVRMouseStillDown(QTVRInstance qtvr, Point pt, UInt32 *hotSpotID, WindowRef w);

                                                 /**
                                                  *  QTVRMouseUp()
                                                  *

                                                  *    \non_carbon_cfm   in QuickTimeVRLib 2.0 and later
                                                  *    \carbon_lib        in CarbonLib 1.1 and later
                                                  *    \mac_os_x         in version 10.0 and later
                                                  *    Windows:          in QTVR.lib 2.1 and later
                                                  */
                                                 OSErr
                                                 QTVRMouseUp(QTVRInstance qtvr, Point pt, UInt32 *hotSpotID, WindowRef w);

                                                 // These require QTVR 2.01 (kQTVRAPIMajorVersion02 + kQTVRAPIMinorVersion01)
                                                 /**QTVRMouseStillDownExtended() *

                                                         *    \non_carbon_cfm in QuickTimeVRLib 2.0.1 and
                                                     later
                                                         *    \carbon_lib in CarbonLib 1.1 and
                                                     later
                                                         *    \mac_os_x in version 10.0 and
                                                     later
                                                         *Windows : in QTVR.lib 2.1 and
                                                     later */
                                                 OSErr
                                                 QTVRMouseStillDownExtended(QTVRInstance qtvr, Point pt, UInt32 *hotSpotID,
                                                                            WindowRef w, UInt32 when, UInt16 modifiers);

                                                 /**
                                                  *  QTVRMouseUpExtended()
                                                  *

                                                  *    \non_carbon_cfm   in QuickTimeVRLib 2.0.1 and later
                                                  *    \carbon_lib        in CarbonLib 1.1 and later
                                                  *    \mac_os_x         in version 10.0 and later
                                                  *    Windows:          in QTVR.lib 2.1 and later
                                                  */
                                                 OSErr
                                                 QTVRMouseUpExtended(QTVRInstance qtvr, Point pt, UInt32 *hotSpotID, WindowRef w,
                                                                     UInt32 when, UInt16 modifiers);

                                                 /**
                                                   =================================================================================================
                                                     Intercept Routines
                                                   -------------------------------------------------------------------------------------------------
                                                 */

                                                 /**
                                                  *  QTVRInstallInterceptProc()
                                                  *

                                                  *    \non_carbon_cfm   in QuickTimeVRLib 2.0 and later
                                                  *    \carbon_lib        in CarbonLib 1.1 and later
                                                  *    \mac_os_x         in version 10.0 and later
                                                  *    Windows:          in QTVR.lib 2.1 and later
                                                  */
                                                 OSErr
                                                 QTVRInstallInterceptProc(QTVRInstance qtvr, QTVRProcSelector selector,
                                                                          QTVRInterceptUPP interceptProc, SInt32 refCon,
                                                                          UInt32 flags);

                                                 /**
                                                  *  QTVRCallInterceptedProc()
                                                  *

                                                  *    \non_carbon_cfm   in QuickTimeVRLib 2.0 and later
                                                  *    \carbon_lib        in CarbonLib 1.1 and later
                                                  *    \mac_os_x         in version 10.0 and later
                                                  *    Windows:          in QTVR.lib 2.1 and later
                                                  */
                                                 OSErr
                                                 QTVRCallInterceptedProc(QTVRInstance qtvr, QTVRInterceptRecord *qtvrMsg);

                                                 /**
                                                   =================================================================================================
                                                     Object Movie Specific Calls
                                                   -------------------------------------------------------------------------------------------------
                                                    QTVRGetCurrentMouseMode requires QTRVR 2.1 (kQTVRAPIMajorVersion02 +
                                                 // These require QTVR 2.01 (kQTVRAPIMajorVersion02 + kQTVRAPIMinorVersion01)
                                                 */
                                                 /**
                                                  *  QTVRGetCurrentMouseMode()
                                                  *

                                                  *    \non_carbon_cfm   in QuickTimeVRLib 2.1 and later
                                                  *    \carbon_lib        in CarbonLib 1.1 and later
                                                  *    \mac_os_x         in version 10.0 and later
                                                  *    Windows:          in QTVR.lib 2.1 and later
                                                  */
                                                 UInt32
                                                 QTVRGetCurrentMouseMode(QTVRInstance qtvr);

                                                 /**
                                                  *  QTVRSetFrameRate()
                                                  *

                                                  *    \non_carbon_cfm   in QuickTimeVRLib 2.0 and later
                                                  *    \carbon_lib        in CarbonLib 1.1 and later
                                                  *    \mac_os_x         in version 10.0 and later
                                                  *    Windows:          in QTVR.lib 2.1 and later
                                                  */
                                                 OSErr
                                                 QTVRSetFrameRate(QTVRInstance qtvr, float rate);

                                                 /**
                                                  *  QTVRGetFrameRate()
                                                  *

                                                  *    \non_carbon_cfm   in QuickTimeVRLib 2.0 and later
                                                  *    \carbon_lib        in CarbonLib 1.1 and later
                                                  *    \mac_os_x         in version 10.0 and later
                                                  *    Windows:          in QTVR.lib 2.1 and later
                                                  */
                                                 float
                                                 QTVRGetFrameRate(QTVRInstance qtvr);

                                                 /**
                                                  *  QTVRSetViewRate()
                                                  *

                                                  *    \non_carbon_cfm   in QuickTimeVRLib 2.0 and later
                                                  *    \carbon_lib        in CarbonLib 1.1 and later
                                                  *    \mac_os_x         in version 10.0 and later
                                                  *    Windows:          in QTVR.lib 2.1 and later
                                                  */
                                                 OSErr
                                                 QTVRSetViewRate(QTVRInstance qtvr, float rate);

                                                 /**
                                                  *  QTVRGetViewRate()
                                                  *

                                                  *    \non_carbon_cfm   in QuickTimeVRLib 2.0 and later
                                                  *    \carbon_lib        in CarbonLib 1.1 and later
                                                  *    \mac_os_x         in version 10.0 and later
                                                  *    Windows:          in QTVR.lib 2.1 and later
                                                  */
                                                 float
                                                 QTVRGetViewRate(QTVRInstance qtvr);

                                                 /**
                                                  *  QTVRSetViewCurrentTime()
                                                  *

                                                  *    \non_carbon_cfm   in QuickTimeVRLib 2.0 and later
                                                  *    \carbon_lib        in CarbonLib 1.1 and later
                                                  *    \mac_os_x         in version 10.0 and later
                                                  *    Windows:          in QTVR.lib 2.1 and later
                                                  */
                                                 OSErr
                                                 QTVRSetViewCurrentTime(QTVRInstance qtvr, TimeValue time);

                                                 /**
                                                  *  QTVRGetViewCurrentTime()
                                                  *

                                                  *    \non_carbon_cfm   in QuickTimeVRLib 2.0 and later
                                                  *    \carbon_lib        in CarbonLib 1.1 and later
                                                  *    \mac_os_x         in version 10.0 and later
                                                  *    Windows:          in QTVR.lib 2.1 and later
                                                  */
                                                 TimeValue
                                                 QTVRGetViewCurrentTime(QTVRInstance qtvr);

                                                 /**
                                                  *  QTVRGetCurrentViewDuration()
                                                  *

                                                  *    \non_carbon_cfm   in QuickTimeVRLib 2.0 and later
                                                  *    \carbon_lib        in CarbonLib 1.1 and later
                                                  *    \mac_os_x         in version 10.0 and later
                                                  *    Windows:          in QTVR.lib 2.1 and later
                                                  */
                                                 TimeValue
                                                 QTVRGetCurrentViewDuration(QTVRInstance qtvr);

                                                 /**
                                                   =================================================================================================
                                                    View State Calls - QTVR Object Only
                                                   -------------------------------------------------------------------------------------------------
                                                 */

                                                 /**
                                                  *  QTVRSetViewState()
                                                  *

                                                  *    \non_carbon_cfm   in QuickTimeVRLib 2.0 and later
                                                  *    \carbon_lib        in CarbonLib 1.1 and later
                                                  *    \mac_os_x         in version 10.0 and later
                                                  *    Windows:          in QTVR.lib 2.1 and later
                                                  */
                                                 OSErr
                                                 QTVRSetViewState(QTVRInstance qtvr, QTVRViewStateType viewStateType,
                                                                  UInt16 state);

                                                 /**
                                                  *  QTVRGetViewState()
                                                  *

                                                  *    \non_carbon_cfm   in QuickTimeVRLib 2.0 and later
                                                  *    \carbon_lib        in CarbonLib 1.1 and later
                                                  *    \mac_os_x         in version 10.0 and later
                                                  *    Windows:          in QTVR.lib 2.1 and later
                                                  */
                                                 OSErr
                                                 QTVRGetViewState(QTVRInstance qtvr, QTVRViewStateType viewStateType,
                                                                  UInt16 *state);

                                                 /**
                                                  *  QTVRGetViewStateCount()
                                                  *

                                                  *    \non_carbon_cfm   in QuickTimeVRLib 2.0 and later
                                                  *    \carbon_lib        in CarbonLib 1.1 and later
                                                  *    \mac_os_x         in version 10.0 and later
                                                  *    Windows:          in QTVR.lib 2.1 and later
                                                  */
                                                 UInt16
                                                 QTVRGetViewStateCount(QTVRInstance qtvr);

                                                 /**
                                                  *  QTVRSetAnimationSetting()
                                                  *

                                                  *    \non_carbon_cfm   in QuickTimeVRLib 2.0 and later
                                                  *    \carbon_lib        in CarbonLib 1.1 and later
                                                  *    \mac_os_x         in version 10.0 and later
                                                  *    Windows:          in QTVR.lib 2.1 and later
                                                  */
                                                 OSErr
                                                 QTVRSetAnimationSetting(QTVRInstance qtvr, QTVRObjectAnimationSetting setting,
                                                                         Boolean enable);

                                                 /**
                                                  *  QTVRGetAnimationSetting()
                                                  *

                                                  *    \non_carbon_cfm   in QuickTimeVRLib 2.0 and later
                                                  *    \carbon_lib        in CarbonLib 1.1 and later
                                                  *    \mac_os_x         in version 10.0 and later
                                                  *    Windows:          in QTVR.lib 2.1 and later
                                                  */
                                                 OSErr
                                                 QTVRGetAnimationSetting(QTVRInstance qtvr, QTVRObjectAnimationSetting setting,
                                                                         Boolean *enable);

                                                 /**
                                                  *  QTVRSetControlSetting()
                                                  *

                                                  *    \non_carbon_cfm   in QuickTimeVRLib 2.0 and later
                                                  *    \carbon_lib        in CarbonLib 1.1 and later
                                                  *    \mac_os_x         in version 10.0 and later
                                                  *    Windows:          in QTVR.lib 2.1 and later
                                                  */
                                                 OSErr
                                                 QTVRSetControlSetting(QTVRInstance qtvr, QTVRControlSetting setting,
                                                                       Boolean enable);

                                                 /**
                                                  *  QTVRGetControlSetting()
                                                  *

                                                  *    \non_carbon_cfm   in QuickTimeVRLib 2.0 and later
                                                  *    \carbon_lib        in CarbonLib 1.1 and later
                                                  *    \mac_os_x         in version 10.0 and later
                                                  *    Windows:          in QTVR.lib 2.1 and later
                                                  */
                                                 OSErr
                                                 QTVRGetControlSetting(QTVRInstance qtvr, QTVRControlSetting setting,
                                                                       Boolean *enable);

                                                 /**
                                                  *  QTVREnableFrameAnimation()
                                                  *

                                                  *    \non_carbon_cfm   in QuickTimeVRLib 2.0 and later
                                                  *    \carbon_lib        in CarbonLib 1.1 and later
                                                  *    \mac_os_x         in version 10.0 and later
                                                  *    Windows:          in QTVR.lib 2.1 and later
                                                  */
                                                 OSErr
                                                 QTVREnableFrameAnimation(QTVRInstance qtvr, Boolean enable);

                                                 /**
                                                  *  QTVRGetFrameAnimation()
                                                  *

                                                  *    \non_carbon_cfm   in QuickTimeVRLib 2.0 and later
                                                  *    \carbon_lib        in CarbonLib 1.1 and later
                                                  *    \mac_os_x         in version 10.0 and later
                                                  *    Windows:          in QTVR.lib 2.1 and later
                                                  */
                                                 Boolean
                                                 QTVRGetFrameAnimation(QTVRInstance qtvr);

                                                 /**
                                                  *  QTVREnableViewAnimation()
                                                  *

                                                  *    \non_carbon_cfm   in QuickTimeVRLib 2.0 and later
                                                  *    \carbon_lib        in CarbonLib 1.1 and later
                                                  *    \mac_os_x         in version 10.0 and later
                                                  *    Windows:          in QTVR.lib 2.1 and later
                                                  */
                                                 OSErr
                                                 QTVREnableViewAnimation(QTVRInstance qtvr, Boolean enable);

                                                 /**
                                                  *  QTVRGetViewAnimation()
                                                  *

                                                  *    \non_carbon_cfm   in QuickTimeVRLib 2.0 and later
                                                  *    \carbon_lib        in CarbonLib 1.1 and later
                                                  *    \mac_os_x         in version 10.0 and later
                                                  *    Windows:          in QTVR.lib 2.1 and later
                                                  */
                                                 Boolean
                                                 QTVRGetViewAnimation(QTVRInstance qtvr);

                                                 /**
                                                   =================================================================================================
                                                     Imaging Characteristics
                                                   -------------------------------------------------------------------------------------------------
                                                 */

                                                 /**
                                                  *  QTVRSetVisible()
                                                  *

                                                  *    \non_carbon_cfm   in QuickTimeVRLib 2.0 and later
                                                  *    \carbon_lib        in CarbonLib 1.1 and later
                                                  *    \mac_os_x         in version 10.0 and later
                                                  *    Windows:          in QTVR.lib 2.1 and later
                                                  */
                                                 OSErr
                                                 QTVRSetVisible(QTVRInstance qtvr, Boolean visible);

                                                 /**
                                                  *  QTVRGetVisible()
                                                  *

                                                  *    \non_carbon_cfm   in QuickTimeVRLib 2.0 and later
                                                  *    \carbon_lib        in CarbonLib 1.1 and later
                                                  *    \mac_os_x         in version 10.0 and later
                                                  *    Windows:          in QTVR.lib 2.1 and later
                                                  */
                                                 Boolean
                                                 QTVRGetVisible(QTVRInstance qtvr);

                                                 /**
                                                  *  QTVRSetImagingProperty()
                                                  *

                                                  *    \non_carbon_cfm   in QuickTimeVRLib 2.0 and later
                                                  *    \carbon_lib        in CarbonLib 1.1 and later
                                                  *    \mac_os_x         in version 10.0 and later
                                                  *    Windows:          in QTVR.lib 2.1 and later
                                                  */
                                                 OSErr
                                                 QTVRSetImagingProperty(QTVRInstance qtvr, QTVRImagingMode imagingMode,
                                                                        UInt32 imagingProperty, SInt32 propertyValue);

                                                 /**
                                                  *  QTVRGetImagingProperty()
                                                  *

                                                  *    \non_carbon_cfm   in QuickTimeVRLib 2.0 and later
                                                  *    \carbon_lib        in CarbonLib 1.1 and later
                                                  *    \mac_os_x         in version 10.0 and later
                                                  *    Windows:          in QTVR.lib 2.1 and later
                                                  */
                                                 OSErr
                                                 QTVRGetImagingProperty(QTVRInstance qtvr, QTVRImagingMode imagingMode,
                                                                        UInt32 imagingProperty, SInt32 *propertyValue);

                                                 /**
                                                  *  QTVRUpdate()
                                                  *

                                                  *    \non_carbon_cfm   in QuickTimeVRLib 2.0 and later
                                                  *    \carbon_lib        in CarbonLib 1.1 and later
                                                  *    \mac_os_x         in version 10.0 and later
                                                  *    Windows:          in QTVR.lib 2.1 and later
                                                  */
                                                 OSErr
                                                 QTVRUpdate(QTVRInstance qtvr, QTVRImagingMode imagingMode);

                                                 /**
                                                  *  QTVRBeginUpdateStream()
                                                  *

                                                  *    \non_carbon_cfm   in QuickTimeVRLib 2.0 and later
                                                  *    \carbon_lib        in CarbonLib 1.1 and later
                                                  *    \mac_os_x         in version 10.0 and later
                                                  *    Windows:          in QTVR.lib 2.1 and later
                                                  */
                                                 OSErr
                                                 QTVRBeginUpdateStream(QTVRInstance qtvr, QTVRImagingMode imagingMode);

                                                 /**
                                                  *  QTVREndUpdateStream()
                                                  *

                                                  *    \non_carbon_cfm   in QuickTimeVRLib 2.0 and later
                                                  *    \carbon_lib        in CarbonLib 1.1 and later
                                                  *    \mac_os_x         in version 10.0 and later
                                                  *    Windows:          in QTVR.lib 2.1 and later
                                                  */
                                                 OSErr
                                                 QTVREndUpdateStream(QTVRInstance qtvr);

                                                 /**
                                                  *  QTVRSetTransitionProperty()
                                                  *

                                                  *    \non_carbon_cfm   in QuickTimeVRLib 2.0 and later
                                                  *    \carbon_lib        in CarbonLib 1.1 and later
                                                  *    \mac_os_x         in version 10.0 and later
                                                  *    Windows:          in QTVR.lib 2.1 and later
                                                  */
                                                 OSErr
                                                 QTVRSetTransitionProperty(QTVRInstance qtvr, UInt32 transitionType,
                                                                           UInt32 transitionProperty, SInt32 transitionValue);

                                                 /**
                                                  *  QTVREnableTransition()
                                                  *

                                                  *    \non_carbon_cfm   in QuickTimeVRLib 2.0 and later
                                                  *    \carbon_lib        in CarbonLib 1.1 and later
                                                  *    \mac_os_x         in version 10.0 and later
                                                  *    Windows:          in QTVR.lib 2.1 and later
                                                  */
                                                 OSErr
                                                 QTVREnableTransition(QTVRInstance qtvr, UInt32 transitionType, Boolean enable);

                                                 /**
                                                   =================================================================================================
                                                     Basic Conversion and Math Routines
                                                   -------------------------------------------------------------------------------------------------
                                                 */

                                                 /**
                                                  *  QTVRSetAngularUnits()
                                                  *

                                                  *    \non_carbon_cfm   in QuickTimeVRLib 2.0 and later
                                                  *    \carbon_lib        in CarbonLib 1.1 and later
                                                  *    \mac_os_x         in version 10.0 and later
                                                  *    Windows:          in QTVR.lib 2.1 and later
                                                  */
                                                 OSErr
                                                 QTVRSetAngularUnits(QTVRInstance qtvr, QTVRAngularUnits units);

                                                 /**
                                                  *  QTVRGetAngularUnits()
                                                  *

                                                  *    \non_carbon_cfm   in QuickTimeVRLib 2.0 and later
                                                  *    \carbon_lib        in CarbonLib 1.1 and later
                                                  *    \mac_os_x         in version 10.0 and later
                                                  *    Windows:          in QTVR.lib 2.1 and later
                                                  */
                                                 QTVRAngularUnits
                                                 QTVRGetAngularUnits(QTVRInstance qtvr);

                                                 // Pano specific routines
                                                 /**QTVRPtToAngles() *

                                                         *    \non_carbon_cfm in QuickTimeVRLib 2.0 and
                                                     later
                                                         *    \carbon_lib in CarbonLib 1.1 and
                                                     later
                                                         *    \mac_os_x in version 10.0 and
                                                     later
                                                         *Windows : in QTVR.lib 2.1 and
                                                     later */
                                                 OSErr
                                                 QTVRPtToAngles(QTVRInstance qtvr, Point pt, float *panAngle, float *tiltAngle);

                                                 /**
                                                  *  QTVRCoordToAngles()
                                                  *

                                                  *    \non_carbon_cfm   in QuickTimeVRLib 2.0 and later
                                                  *    \carbon_lib        in CarbonLib 1.1 and later
                                                  *    \mac_os_x         in version 10.0 and later
                                                  *    Windows:          in QTVR.lib 2.1 and later
                                                  */
                                                 OSErr
                                                 QTVRCoordToAngles(QTVRInstance qtvr, QTVRFloatPoint *coord, float *panAngle,
                                                                   float *tiltAngle);

                                                 /**
                                                  *  QTVRAnglesToCoord()
                                                  *

                                                  *    \non_carbon_cfm   in QuickTimeVRLib 2.0 and later
                                                  *    \carbon_lib        in CarbonLib 1.1 and later
                                                  *    \mac_os_x         in version 10.0 and later
                                                  *    Windows:          in QTVR.lib 2.1 and later
                                                  */
                                                 OSErr
                                                 QTVRAnglesToCoord(QTVRInstance qtvr, float panAngle, float tiltAngle,
                                                                   QTVRFloatPoint *coord);

                                                 // Object specific routines
                                                 /**QTVRPanToColumn() *

                                                         *    \non_carbon_cfm in QuickTimeVRLib 2.0 and
                                                     later
                                                         *    \carbon_lib in CarbonLib 1.1 and
                                                     later
                                                         *    \mac_os_x in version 10.0 and
                                                     later
                                                         *Windows : in QTVR.lib 2.1 and
                                                     later */
                                                 short QTVRPanToColumn(QTVRInstance qtvr, float panAngle);

                                                 // zero based
                                                 /**
                                                                                                 *QTVRColumnToPan() *

                                                                                                         *    \non_carbon_cfm in QuickTimeVRLib 2.0 and
                                                                                                     later
                                                                                                         *    \carbon_lib in CarbonLib 1.1 and
                                                                                                     later
                                                                                                         *    \mac_os_x in version 10.0 and
                                                                                                     later
                                                                                                         *Windows : in QTVR.lib 2.1 and
                                                                                                     later*/
                                                 float QTVRColumnToPan(QTVRInstance qtvr, short column);

                                                 // zero based
                                                 /**
                                                                                                 *QTVRTiltToRow()
                                                                                                         // Pano specific routines

                                                                                                         *    \non_carbon_cfm in QuickTimeVRLib 2.0 and
                                                                                                     later
                                                                                                         *    \carbon_lib in CarbonLib 1.1 and
                                                                                                     later
                                                                                                         *    \mac_os_x in version 10.0 and
                                                                                                     later
                                                                                                         *Windows : in QTVR.lib 2.1 and
                                                                                                     later*/
                                                 short QTVRTiltToRow(QTVRInstance qtvr, float tiltAngle);

                                                 // zero based
                                                 /**
                                                                                                 *QTVRRowToTilt() *

                                                                                                         *    \non_carbon_cfm in QuickTimeVRLib 2.0 and
                                                                                                     later
                                                                                                         *    \carbon_lib in CarbonLib 1.1 and
                                                                                                     later
                                                                                                         *    \mac_os_x in version 10.0 and
                                                                                                     later
                                                                                                         *Windows : in QTVR.lib 2.1 and
                                                                                                     later*/
                                                 float QTVRRowToTilt(QTVRInstance qtvr, short row);

                                                 // zero based
                                                 /**
                                                                                                 *QTVRWrapAndConstrain() *

                                                                                                         *    \non_carbon_cfm in QuickTimeVRLib 2.0 and
                                                                                                     later
                                                                                                         *    \carbon_lib in CarbonLib 1.1 and
                                                                                                     later
                                                                                                         *    \mac_os_x in version 10.0 and
                                                                                                     later
                                                                                                         *Windows : in QTVR.lib 2.1 and
                                                                                                     later*/
                                                 OSErr
                                                 QTVRWrapAndConstrain(QTVRInstance qtvr, short kind, float value, float *result);

                                                 /**
                                                   =================================================================================================
                                                     Interaction Routines
                                                   -------------------------------------------------------------------------------------------------
                                                 */
                                                 // Object specific routines
                                                 /**
                                                  *  QTVRSetEnteringNodeProc()
                                                  *

                                                  *    \non_carbon_cfm   in QuickTimeVRLib 2.0 and later
                                                  *    \carbon_lib        in CarbonLib 1.1 and later
                                                  *    \mac_os_x         in version 10.0 and later
                                                  *    Windows:          in QTVR.lib 2.1 and later
                                                  */
                                                 OSErr
                                                 QTVRSetEnteringNodeProc(QTVRInstance qtvr, QTVREnteringNodeUPP enteringNodeProc,
                                                                         SInt32 refCon, UInt32 flags);
                                                 // zero based
                                                 /**
                                                  *  QTVRSetLeavingNodeProc()
                                                  *

                                                  *    \non_carbon_cfm   in QuickTimeVRLib 2.0 and later
                                                  *    \carbon_lib        in CarbonLib 1.1 and later
                                                  *    \mac_os_x         in version 10.0 and later
                                                  *    Windows:          in QTVR.lib 2.1 and later
                                                  */
                                                 OSErr
                                                 QTVRSetLeavingNodeProc(QTVRInstance qtvr, QTVRLeavingNodeUPP leavingNodeProc,
                                                                        SInt32 refCon, UInt32 flags);
                                                 // zero based
                                                 /**
                                                  *  QTVRSetInteractionProperty()
                                                  *

                                                  *    \non_carbon_cfm   in QuickTimeVRLib 2.0 and later
                                                  *    \carbon_lib        in CarbonLib 1.1 and later
                                                  *    \mac_os_x         in version 10.0 and later
                                                  *    Windows:          in QTVR.lib 2.1 and later
                                                  */
                                                 OSErr
                                                 QTVRSetInteractionProperty(QTVRInstance qtvr, UInt32 property, void *value);

                                                 // zero based
                                                 /**QTVRGetInteractionProperty()
                                                  * \non_carbon_cfm in QuickTimeVRLib 2.0 and
                                                     later
                                                         *    \carbon_lib in CarbonLib 1.1 and
                                                     later
                                                         *    \mac_os_x in version 10.0 and
                                                     later
                                                         *Windows : in QTVR.lib 2.1 and
                                                     later */
                                                 OSErr
                                                 QTVRGetInteractionProperty(QTVRInstance qtvr, UInt32 property, void *value);

                                                 /**
                                                 // zero based
                                                  *

                                                  *    \non_carbon_cfm   in QuickTimeVRLib 2.0 and later
                                                  *    \carbon_lib        in CarbonLib 1.1 and later
                                                  *    \mac_os_x         in version 10.0 and later
                                                  *    Windows:          in QTVR.lib 2.1 and later
                                                  */
                                                 OSErr
                                                 QTVRReplaceCursor(QTVRInstance qtvr, QTVRCursorRecord *cursRecord);

                                                 /**
                                                   =================================================================================================
                                                     Viewing Limits and Constraints
                                                   -------------------------------------------------------------------------------------------------
                                                 */

                                                 /**
                                                  *  QTVRGetViewingLimits()
                                                  *

                                                  *    \non_carbon_cfm   in QuickTimeVRLib 2.0 and later
                                                  *    \carbon_lib        in CarbonLib 1.1 and later
                                                  *    \mac_os_x         in version 10.0 and later
                                                  *    Windows:          in QTVR.lib 2.1 and later
                                                  */
                                                 OSErr
                                                 QTVRGetViewingLimits(QTVRInstance qtvr, UInt16 kind, float *minValue,
                                                                      float *maxValue);

                                                 /**
                                                  *  QTVRGetConstraintStatus()
                                                  *

                                                  *    \non_carbon_cfm   in QuickTimeVRLib 2.0 and later
                                                  *    \carbon_lib        in CarbonLib 1.1 and later
                                                  *    \mac_os_x         in version 10.0 and later
                                                  *    Windows:          in QTVR.lib 2.1 and later
                                                  */
                                                 UInt32
                                                 QTVRGetConstraintStatus(QTVRInstance qtvr);

                                                 /**
                                                  *  QTVRGetConstraints()
                                                  *

                                                  *    \non_carbon_cfm   in QuickTimeVRLib 2.0 and later
                                                  *    \carbon_lib        in CarbonLib 1.1 and later
                                                  *    \mac_os_x         in version 10.0 and later
                                                  *    Windows:          in QTVR.lib 2.1 and later
                                                  */
                                                 OSErr
                                                 QTVRGetConstraints(QTVRInstance qtvr, UInt16 kind, float *minValue,
                                                                    float *maxValue);

                                                 /**
                                                  *  QTVRSetConstraints()
                                                  *

                                                  *    \non_carbon_cfm   in QuickTimeVRLib 2.0 and later
                                                  *    \carbon_lib        in CarbonLib 1.1 and later
                                                  *    \mac_os_x         in version 10.0 and later
                                                  *    Windows:          in QTVR.lib 2.1 and later
                                                  */
                                                 OSErr
                                                 QTVRSetConstraints(QTVRInstance qtvr, UInt16 kind, float minValue,
                                                                    float maxValue);

                                                 /**
                                                   =================================================================================================
                                                     Back Buffer Memory Management
                                                   -------------------------------------------------------------------------------------------------
                                                 */

                                                 /**
                                                  *  QTVRGetAvailableResolutions()
                                                  *

                                                  *    \non_carbon_cfm   in QuickTimeVRLib 2.0 and later
                                                  *    \carbon_lib        in CarbonLib 1.1 and later
                                                  *    \mac_os_x         in version 10.0 and later
                                                  *    Windows:          in QTVR.lib 2.1 and later
                                                  */
                                                 OSErr
                                                 QTVRGetAvailableResolutions(QTVRInstance qtvr, UInt16 *resolutionsMask);

                                                 // These require QTVR 2.1 (kQTVRAPIMajorVersion02 + kQTVRAPIMinorVersion10)
                                                 /** QTVRGetBackBufferMemInfo() *

                                                         *    \non_carbon_cfm in QuickTimeVRLib 2.1 and
                                                     later
                                                         *    \carbon_lib in CarbonLib 1.1 and
                                                     later
                                                         *    \mac_os_x in version 10.0 and
                                                     later
                                                         *Windows : in QTVR.lib 2.1 and
                                                     later */
                                                 OSErr
                                                 QTVRGetBackBufferMemInfo(QTVRInstance qtvr, UInt32 geometry, UInt16 resolution,
                                                                          UInt32 cachePixelFormat, SInt32 *minCacheBytes,
                                                                          SInt32 *suggestedCacheBytes, SInt32 *fullCacheBytes);

                                                 /**
                                                  *  QTVRGetBackBufferSettings()
                                                  *

                                                  *    \non_carbon_cfm   in QuickTimeVRLib 2.1 and later
                                                  *    \carbon_lib        in CarbonLib 1.1 and later
                                                  *    \mac_os_x         in version 10.0 and later
                                                  *    Windows:          in QTVR.lib 2.1 and later
                                                  */
                                                 OSErr
                                                 QTVRGetBackBufferSettings(QTVRInstance qtvr, UInt32 *geometry,
                                                                           UInt16 *resolution, UInt32 *cachePixelFormat,
                                                                           SInt16 *cacheSize);

                                                 /**
                                                  *  QTVRSetBackBufferPrefs()
                                                  *

                                                  *    \non_carbon_cfm   in QuickTimeVRLib 2.1 and later
                                                  *    \carbon_lib        in CarbonLib 1.1 and later
                                                  *    \mac_os_x         in version 10.0 and later
                                                  *    Windows:          in QTVR.lib 2.1 and later
                                                  */
                                                 OSErr
                                                 QTVRSetBackBufferPrefs(QTVRInstance qtvr, UInt32 geometry, UInt16 resolution,
                                                                        UInt32 cachePixelFormat, SInt16 cacheSize);

                                                 /**
                                                   =================================================================================================
                                                     Buffer Access
                                                   -------------------------------------------------------------------------------------------------
                                                 */

                                                 /**
                                                  *  QTVRSetPrescreenImagingCompleteProc()
                                                  *

                                                  *    \non_carbon_cfm   in QuickTimeVRLib 2.0 and later
                                                  *    \carbon_lib        in CarbonLib 1.1 and later
                                                  *    \mac_os_x         in version 10.0 and later
                                                  *    Windows:          in QTVR.lib 2.1 and later
                                                  */
                                                 OSErr
                                                 QTVRSetPrescreenImagingCompleteProc(QTVRInstance qtvr,
                                                                                     QTVRImagingCompleteUPP imagingCompleteProc,
                                                                                     SInt32 refCon, UInt32 flags);

                                                 /**
                                                  *  QTVRSetBackBufferImagingProc()
                                                  *

                                                  *    \non_carbon_cfm   in QuickTimeVRLib 2.0 and later
                                                  *    \carbon_lib        in CarbonLib 1.1 and later
                                                  *    \mac_os_x         in version 10.0 and later
                                                  *    Windows:          in QTVR.lib 2.1 and later
                                                  */
                                                 // These require QTVR 2.1 (kQTVRAPIMajorVersion02 + kQTVRAPIMinorVersion10)
                                                 QTVRSetBackBufferImagingProc(QTVRInstance qtvr,
                                                                              QTVRBackBufferImagingUPP backBufferImagingProc,
                                                                              UInt16 numAreas,
                                                                              QTVRAreaOfInterest areasOfInterest[],
                                                                              SInt32 refCon);

                                                 /**
                                                  *  QTVRRefreshBackBuffer()
                                                  *

                                                  *    \non_carbon_cfm   in QuickTimeVRLib 2.0 and later
                                                  *    \carbon_lib        in CarbonLib 1.1 and later
                                                  *    \mac_os_x         in version 10.0 and later
                                                  *    Windows:          in QTVR.lib 2.1 and later
                                                  */
                                                 OSErr
                                                 QTVRRefreshBackBuffer(QTVRInstance qtvr, UInt32 flags);

                                                 /**
                                                   =================================================================================================
                                                     Old Names
                                                   -------------------------------------------------------------------------------------------------
                                                 */
#if OLDROUTINENAMES
                                                 typedef QTVRCursorRecord CursorRecord;
                                                 typedef QTVRAreaOfInterest AreaOfInterest;
                                                 typedef QTVRFloatPoint FloatPoint;
                                                 typedef QTVRLeavingNodeProcPtr LeavingNodeProcPtr;
                                                 typedef QTVRLeavingNodeUPP LeavingNodeUPP;
                                                 typedef QTVREnteringNodeProcPtr EnteringNodeProcPtr;
                                                 typedef QTVREnteringNodeUPP EnteringNodeUPP;
                                                 typedef QTVRMouseOverHotSpotProcPtr MouseOverHotSpotProcPtr;
                                                 typedef QTVRMouseOverHotSpotUPP MouseOverHotSpotUPP;
                                                 typedef QTVRImagingCompleteProcPtr ImagingCompleteProcPtr;
                                                 typedef QTVRImagingCompleteUPP ImagingCompleteUPP;
                                                 typedef QTVRBackBufferImagingProcPtr BackBufferImagingProcPtr;
                                                 typedef QTVRBackBufferImagingUPP BackBufferImagingUPP;
#endif // OLDROUTINENAMES
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

#endif // __QUICKTIMEVR__ // OLDROUTINENAMES
                                                        // __QUICKTIMEVR__
