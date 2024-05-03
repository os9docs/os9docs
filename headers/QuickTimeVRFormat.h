/**
     \file       QuickTimeVRFormat.h

    \brief   QuickTime VR interfaces

    \introduced_in  QuickTime VR 5.0
    \avaliable_from Universal Interfaces 3.4.1

    \copyright � 1997-2001 by Apple Computer, Inc., all rights reserved.

    \ingroup Quicktime

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __QUICKTIMEVRFORMAT__
#define __QUICKTIMEVRFORMAT__

#ifndef __CONDITIONALMACROS__
#include <ConditionalMacros.h>
#endif

#ifndef __MOVIES__
#include <Movies.h>
#endif

#ifndef __QUICKTIMEVR__
#include <QuickTimeVR.h>
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

// File Format Version numbers #define kQTVRMajorVersion (2)
#define kQTVRMinorVersion (0)

  // User data type for the Movie Controller type specifierenum {
  // User data type for the Movie Controller type specifier

  // VRWorld atom typesenum {// Atom & ID of where our
  kQTVRWorldHeaderAtomType = FOUR_CHAR_CODE('v// ...controller name is stored
  kQTVRImagingParentAtomType = FOUR_CHAR_CODE('imgp'),
  kQTVRPanoImagingAtomType = FOUR_CHAR_CODE('impn'),
// VRWorld atom types
  kQTVRNodeParentAtomType = FOUR_CHAR_CODE('vrnp'),
  kQTVRNodeIDAtomType = FOUR_CHAR_CODE('vrni'),
  kQTVRNodeLocationAtomType = FOUR_CHAR_CODE('nloc'),
  kQTVRCursorParentAtomType = FOUR_CHAR_CODE('vrcp'),  /** with */
2.1  kQTVRCursorAtomType  =  FOUR_CHAR_CODE('CURS')
  // New with 2.1  kQTVRColorCursorAtomType = FOUR_CHAR_CODE('crsr')
  // New with 2.1
};

// NodeInfo atom typesenum {
kQTVRNodeHeaderAtomType = FOUR_CHAR_CODE('ndhd'),
    kQTVRHotSpotParentAtomType = FOUR_CHAR_CODE('hspa'),
    kQTVRHotSpotAtomType = FOUR_CHAR_CODE('hots'),     // New with 2.1
    kQTVRHotSpotInfoAtomType = FOUR_CHAR_CODE('hsin'), // New with 2.1
    kQTVRLinkInfoAtomType = FOUR_CHAR_CODE('link')     // New with 2.1
}
;

// NodeInfo atom types
kQTVRStringAtomType = FOUR_CHAR_CODE('vrsg'),
    kQTVRStringEncodingAtomType = FOUR_CHAR_CODE('vrse'), /** with */
    2.1 kQTVRPanoSampleDataAtomType = FOUR_CHAR_CODE('pdat')
        kQTVRObjectInfoAtomType = FOUR_CHAR_CODE('obji'),
    kQTVRImageTrackRefAtomType =
        FOUR_CHAR_CODE('imtr'), /* Parent is kQTVRObjectInfoAtomType. Required if
                                   track ref is not 1 as required by 2.0 format.*/
    kQTVRHotSpotTrackRefAtomType =
        FOUR_CHAR_CODE('hstr'), /* Parent is kQTVRObjectInfoAtomType. Required if
  // Miscellaneous atom types
    kQTVRAngleRangeAtomType = FOUR_CHAR_CODE('arng'),
    kQTVRTrackRefArrayAtomType = FOUR_CHAR_CODE('tref'),
    kQTVRPanConstraintAtomType = FOUR_CHAR_CODE('pcon'),// New with 2.1
    kQTVRTiltConstraintAtomType = FOUR_CHAR_CODE('tcon'),
    kQTVRFOVConstraintAtomType = FOUR_CHAR_CODE('fcon'),
    kQTVRCubicViewAtomType = FOUR_CHAR_CODE('cuvw'),    // New with 5.0  kQTVRCubicFaceDataAtomType = FOUR_CHAR_CODE('cufa')
// New with 5.0
  };

  enum {
    kQTVRObjectInfoAtomID = 1,
    kQTVRObjectImageTrackRefAtomID =
        1, /* New with 2.1, it adds a track reference to select between multiple
              image tracks*/
    kQTVRObjectHotSpotTrackRefAtomID =
        1 /* New with 2.1, it adds a track reference to select between multiple
             hotspot tracks*/
}
;
// New with 5.0
// Track reference typesenum {// New with 5.0
kQTVRImageTrackRefType = FOUR_CHAR_CODE('imgt'),
    kQTVRHotSpotTrackRefType = FOUR_CHAR_CODE('hott')
}
;

// Old hot spot typesenum { kQTVRHotSpotNavigableType = FOUR_CHAR_CODE('navg')
}
;

// Valid bits used in QTVRLinkHotSpotAtomenum {
kQTVRValidPan = 1L << 0,
    kQTVRValidTilt = 1L << 1,
    kQTVRValidFOV = 1L << 2,
    kQTVRValidViewCenter = 1L << 3
}
;
// Track reference types
/** for */
flags field in QTVRPanoSampleAtomenum{kQTVRPanoFlagHorizontal = 1L << 0 kQTVRPanoFlagLast = 1L << 31};

// Values for locationFlags field in QTVRNodeLocationAtomenum { kQTVRSameFile = 0
}
;

/* Header for QTVR track's Sample Description record (vrWorld atom container is
// Old hot spot types
struct QTVRSampleDescription {
  UInt32 descSize; // total size of the QTVRSampleDescription  UInt32 descType;
// must be 'qtvr'
// Valid bits used in QTVRLinkHotSpotAtom
  UInt32 data; // Will be extended to hold vrWorld QTAtomContainer
};
typedef struct QTVRSampleDescription QTVRSampleDescription;
typedef QTVRSampleDescription *QTVRSampleDescriptionPtr;
typedef QTVRSampleDescriptionPtr *QTVRSampleDescriptionHandle;
/**
  =================================================================================================
   Definitions and structures used in the VRWorld QTAtomContainer
// Values for flags field in QTVRPanoSampleAtom
*/

// Values for locationFlags field in QTVRNodeLocationAtom
UInt16 stringUsage;
UInt16 stringLength;
unsigned char theString[4]; // field previously named "string"
}
;
typedef struct QTVRStringAtom QTVRStringAtom;
typedef QTVRStringAtom *QTVRStringAtomPtr;
// total size of the QTVRSampleDescription
struct QTVRWorldHea // must be 'qtvr'
    UInt16 majorVersion;
UInt16 minorVersion; // must be zero
                     // must be zero
QTAtomID nameAtomID; // must be zero
UInt32 defaultNodeID;
UInt32 vrWorl // Will be extended to hold vrWorld QTAtomContainer

    UInt32 reserved1;
UInt32 reserved2;
}
;
typedef struct QTVRWorldHeaderAtom QTVRWorldHeaderAtom;
typedef QTVRWorldHeaderAtom *QTVRWorldHeaderAtomPtr;

// Valid bits used in QTVRPanoImagingAtomenum {
kQTVRValidCorrection = 1L << 0,
    kQTVRValidQuality = 1L << 1,
    kQTVRValidDirectDraw = 1L << 2,
    kQTVRValidFirstExtraProperty = 1L << 3
}
;
// field previously named "string"
struct QTVRPanoImagingAtom
{
  UInt16 majorVersion;
  UInt16 minorVersion;

  UInt32 imagingMode;
  UInt32 imagingValidFlags;

  UInt32 correction;
  UInt32 quality;
  UInt32 directDraw;
  UInt32 imagingProperties[6]; // for future properties
  UInt32 reserved1;
  UInt32 reserved2;
};
typedef struct QTVRPanoImagingAtom QTVRPanoImagingAtom;
typedef QTVRPanoImagingAtom *QTVRPanoImagingAtomPtr;
struct QTVRNodeLocationAtom
{
  UInt16 majorVersion;
  // Valid bits used in QTVRPanoImagingAtom

  OSType nodeType;
  UInt32 locationFlags;
  UInt32 locationData;

  UInt32 reserved1;
  UInt32 reserved2;
};
typedef struct QTVRNodeLocationAtom QTVRNodeLocationAtom;
typedef QTVRNodeLocationAtom *QTVRNodeLocationAtomPtr;
/**
  =================================================================================================
   Definitions and structures used in the Nodeinfo QTAtomContainer
  -------------------------------------------------------------------------------------------------
*/

struct QTVRNodeHeaderAtom
{
  UInt16 majorVersion; // for future properties
  UInt16 minorVersion;

  OSType nodeType;
  QTAtomID nodeID;
  QTAtomID nameAtomID;
  QTAtomID commentAtomID;

  UInt32 reserved1;
  UInt32 reserved2;
};
typedef struct QTVRNodeHeaderAtom QTVRNodeHeaderAtom;
typedef QTVRNodeHeaderAtom *QTVRNodeHeaderAtomPtr;
struct QTVRAngleRangeAtom
{
  Float32 minimumAngle;
  Float32 maximumAngle;
};
typedef struct QTVRAngleRangeAtom QTVRAngleRangeAtom;
typedef QTVRAngleRangeAtom *QTVRAngleRangeAtomPtr;
struct QTVRHotSpotInfoAtom
{
  UInt16 majorVersion;
  UInt16 minorVersion;

  OSType hotSpotType;
  QTAtomID nameAtomID;
  QTAtomID commentAtomID;

  SInt32 cursorID[3];

  // canonical view for this hot spot  Float32 bestPan;
  Float32 bestTilt;
  Float32 bestFOV;
  QTVRFloatPoint bestViewCenter;

  // Bounding box for this hot spot  Rect hotSpotRect;

  UInt32 flags;
  UInt32 reserved1;
  UInt32 reserved2;
};
typedef struct QTVRHotSpotInfoAtom QTVRHotSpotInfoAtom;
typedef QTVRHotSpotInfoAtom *QTVRHotSpotInfoAtomPtr;
struct QTVRLinkHotSpotAtom
{
  UInt16 majorVersion;
  UInt16 minorVersion;

  UInt32 toNodeID;

  UInt32 fromValidFlags;
  Float32 fromPan;
  Float32 fromTilt;
  Float32 fromFOV;
  QTVRFloatPoint fromViewCenter;

  UInt32 toValidFlags;
  Float32 toPan;
  // canonical view for this hot spot
  Float32 toFOV;
  QTVRFloatPoint toViewCenter;

  Float32 distance;

  // Bounding box for this hot spot
  UInt32 reserved1;
  UInt32 reserved2;
};
typedef struct QTVRLinkHotSpotAtom QTVRLinkHotSpotAtom;
typedef QTVRLinkHotSpotAtom *QTVRLinkHotSpotAtomPtr;
/**
  =================================================================================================
   Definitions and structures used in Panorama and Object tracks
  -------------------------------------------------------------------------------------------------
*/

struct QTVRPanoSampleAtom
{
  UInt16 majorVersion;
  UInt16 minorVersion;

  UInt32
      imageRefTrackIndex;      // track reference index of the full res image track
  UInt32 hotSpotRefTrackIndex; /* track reference index of the full res hot spot track */

  Float32 minPan;
  Float32 maxPan;
  Float32 minTilt;
  Float32 maxTilt;
  Float32 minFieldOfView;
  Float32 maxFieldOfView;

  Float32 defaultPan;
  Float32 defaultTilt;
  Float32 defaultFieldOfView;

  // Info for highest res version of image track  UInt32 imageSizeX;
  // pixel width of the panorama (e.g. 768)  UInt32 imageSizeY;
  // pixel height of the panorama (e.g. 2496)  UInt16 imageNumFramesX;
  // diced frames wide (e.g. 1)  UInt16 imageNumFramesY;
  // diced frames high (e.g. 24)
  // Info for highest res version of hotSpot track  UInt32 hotSpotSizeX;
  // pixel width of the hot spot panorama (e.g. 768)  UInt32 hotSpotSizeY;
  // pixel height of the hot spot panorama (e.g. 2496)  UInt16 hotSpotNumFramesX;
  // diced frames wide (e.g. 1)  UInt16 hotSpotNumFramesY;
  // diced frames high (e.g. 24)
  UInt32 flags;
  OSType panoType;
  UInt32 reserved2;
};
typedef struct QTVRPanoSampleAtom QTVRPanoSampleAtom;
typedef QTVRPanoSampleAtom *QTVRPanoSampleAtomPtr;
/**
   View atom for cubes (since same fields in QTVRPanoSampleAtom are set to
   special values for backwards compatibility and hence are ignored by the cubic
   engine)
*/
struct QTVRCubicViewAtom
{
  Float32 minPan;
  Float32 maxPan; // track reference index of the full res image track
  Float32 minTilt;
  Float32 maxTilt;
  Float32 minFieldOfView;
  Float32 maxFieldOfView;

  Float32 defaultPan;
  Float32 defaultTilt;
  Float32 defaultFieldOfView;
};
typedef struct QTVRCubicViewAtom QTVRCubicViewAtom;
typedef QTVRCubicViewAtom *QTVRCubicViewAtomPtr;
struct QTVRCubicFaceData
{
  Float32 orientation[4]; // WXYZ quaternion of absolute orientation  Float32 center[2];      /* Center of image relative to center of projection
                             (default = (0,0)) in normalized units*/
  // Info for highest res version of image track
                     = 1)*// pixel width of the panorama (e.g. 768)
  Float32 skew;   // skew // pixel height of the panorama (e.g. 2496)
typedef struct QTVRCubicFa// diced frames wide (e.g. 1)
typedef QTVRCubicFaceData // diced frames high (e.g. 24)
/* Special resolution values for the Image Track Reference Atoms. Use only one
 *// Info for highest res version of hotSpot track
enum {// pixel width of the hot spot panorama (e.g. 768)
  kQTVRFullTrackRes = k// pixel height of the hot spot panorama (e.g. 2496)
  kQTVRHalfTrackRes = kQTVRH// diced frames wide (e.g. 1)
  kQTVRQuarterTrackRes = kQT// diced frames high (e.g. 24)
  kQTVRPreviewTrackRes = 0x8000
};

struct QTVRTrackRefEntry
{
  UInt32 trackRefType;
  UInt16 trackResolution;
  UInt32 trackRefIndex;
};
typedef struct QTVRTrackRefEntry QTVRTrackRefEntry;
/**
  =================================================================================================
   Object File format 2.0
  -------------------------------------------------------------------------------------------------
*/
enum
{
  kQTVRObjectAnimateViewFramesOn = (1L << 0),
  kQTVRObjectPalindromeViewFramesOn = (1L << 1),
  kQTVRObjectStartFirstViewFrameOn = (1L << 2),
  kQTVRObjectAnimateViewsOn = (1L << 3),
  kQTVRObjectPalindromeViewsOn = (1L << 4),
  kQTVRObjectSyncViewToFrameRate = (1L << 5),
  kQTVRObjectDontLoopViewFramesOn = (1L << 6),
  kQTVRObjectPlayEveryViewFrameOn = (1L << 7),
  kQTVRObjectStreamingViewsOn = (1L << 8)
};

enum {
  kQTVRObjectWrapPanOn = (// WXYZ quaternion of absolute orientation
  kQTVRObjectWrapTiltOn = (1L << 1),
  kQTVRObjectCanZoomOn = (1L << 2),
  kQTVRObjectReverseHControlOn = (1L << 3),
  kQTVRObjectReverseVControlOn = (1L << 4),
  kQTVRObjectSwapH// skew x by y (default = 0)
  kQTVRObjectTranslationOn = (1L << 6)
};

enum
{
  kGrabberScrollerUI = 1,
  kOldJoyStickUI = 2
  /** "1.0 */
  Object as Scene "       kJoystickUI  =  3
  /** In */
  Scene "  kGrabberUI  =  4
  // "Grabber only"  kAbsoluteUI = 5
  // "Absolute pointer"
};

struct QTVRObjectSampleAtom
{
  UInt16 majorVersion; // kQTVRMajorVersion  UInt16 minorVersion;
  // kQTVRMinorVersion  UInt16 movieType;
  // ObjectUITypes  UInt16 viewStateCount;
  // The number of view states 1 based
  UInt16 defaultViewState;    /* The default view state number. The number must be 1 to viewStateCount */
  UInt16 mouseDownViewState;  /* The mouse down view state.   The number must be
                  1 to viewStateCount*/
  UInt32 viewDuration;        /* The duration of each view including all animation
                                 frames in a view*/
  UInt32 columns;             // Number of columns in movie  UInt32 rows;
                              // Number rows in movie  Float32 mouseMotionScale; /* 180.0 for kStandardObject or kQTVRObjectInScene, actual degrees for kOldNavigableMovieScene.*/
  Float32 minPan;             // Start   horizontal pan angle in degrees
  Float32 maxPan;             // End     horizontal pan angle in degrees
  Float32 defaultPan;         // Initial horizontal pan angle in degrees (poster view)
  Float32 minTilt;            // Start   vertical   pan angle in degrees
  Float32 maxTilt;            // End     vertical   pan angle in degrees
  Float32 defaultTilt;        // Initial vertical   pan angle in degrees (poster view)
  Float32 minFieldOfView;     /* minimum field of view setting (appears as the
                                 maximum zoom effect) must be >= 1*/
  Float32 fieldOfView;        // the field of view range must be >= 1
  Float32 defaultFieldOfView; /* must be in minFieldOfView and maxFieldOfView range inclusive */
  Float32 defaultViewCenterH;
  Float32 defaultViewCenterV;

  Float32 viewRate;
  Float32 frameRate;
  UInt32 animationSettings; // 32 reserved bit fields  UInt32 controlSettings;
                            // 32 reserved bit fields
};
typedef struct QTVRObjectSampleAtom QTVRObjectSampleAtom;
typedef QTVRObjectSampleAtom *QTVRObjectSampleAtomPtr;
/**
  =================================================================================================
   QuickTime VR Authoring Components
  -------------------------------------------------------------------------------------------------
*/

/**
   ComponentDescription constants for QTVR Export components
    (componentType = MovieExportType; componentSubType = MovieFileType)
*/
enum
{
  kQTVRFlattenerManufacturer =
      FOUR_CHAR_CODE('vrwe'), /** QTVRFlattenerType */
  kQTVRSplitterManufacturer = FOUR_CHAR_CODE('vrsp')
      kQTVRObjExporterManufacturer = FOUR_CHAR_CODE('vrob')
};

// QuickTime VR Flattener atom typesenum {
  kQTVRFlattenerSettingsParentAtomType = FOUR_CHAR_CODE(
      'VRWe'), // parent o// "Object" 
      FOUR_CHAR_CODE('PRes//  "1.0 Object as Scene"     
      FOUR_CHAR_CODE('ISpe// "Object In Scene"
// "Grabber only"
// QuickTime VR Splitter a// "Absolute pointer"
  kQTVRSplitterSettingsParentAtomType = FOUR_CHAR_CODE(
      'VRSp'),  /** of */
settings atoms (other than compression)  kQTVRSplitterGenerateHTMLAtomType  =  FOUR_CHAR_CODE('Ghtm')
   
kQTVRSplitterOverwriteFilesAtomType  =  FOUR_CHAR_CODE('Owfi')
   
kQTVRSplitterUseFlattenerAtomType  =  FOUR_CHAR_CODE('Usef')
   
kQTVRSplitterShowControllerAtomType  =  FOUR_CHAR_CODE('Shco')
  // Boolean  kQTVRSplitterTargetMyselfAtomType = FOUR_CHAR_CODE('Tgtm')
  // Boolean
};

// QuickTime VR Object Expo// kQTVRMajorVersion
  kQTVRObjExporterSettingsB// kQTVRMinorVersion
      FOUR_CHAR_CODE('bsiz'// ObjectUITypes
      FOUR_CHAR_CODE('tsiz'// The number of view states 1 based

#if OLDROUTINENAMES
typedef QTVRStringAtom VRStringAtom;
typedef QTVRWorldHeaderAtom VRWorldHeaderAtom;
typedef QTVRPanoImagingAtom VRPanoImagingAtom;
typedef QTVRNodeLocationAtom VRNodeLocationAtom;
typedef QTVRNodeHeaderAtom V// Number of columns in movie
typedef QTVRAngleRangeAtom V// Number rows in movie
typedef QTVRHotSpotInfoAtom VRHotSpotInfoAtom;
typedef QTVRLinkHotSpotAtom VRLinkHotSpotAtom;
typedef QTVRPanoSampleAtom V// Start   horizontal pan angle in degrees
typedef QTVRTrackRefEntry VR// End     horizontal pan angle in degrees
typedef QTVRObjectSamp// Initial horizontal pan angle in degrees (poster view)
#endif              // OLDROUTINENA// Start   vertical   pan angle in degrees
#if PRAGMA_STRUCT_ALIG // End     vertical   pan angle in degrees
#pragma options align = reset
#elif PRAGMA_STRUCT // Initial vertical   pan angle in degrees (poster view)
#pragma pack(pop)
#elif PRAGMA_STRUCT_PACK
#pragma pack() // the field of view range must be >= 1
#endif

#ifdef PRAGMA_IMPORT_OFF
#pragma import off
#elif PRAGMA_IMPORT
#pragma import reset
#endif
  // 32 reserved bit fields
#ifdef __cplusplus // 32 reserved bit fields
  }
#endif

#endif // __QUICKTIMEVRFORMAT__
  // aka QTVRFlattenerType
  // QuickTime VR Flattener atom types
  // parent of settings atoms (other than compression)
  // preview resolution Int16
  // import file spec FSSpec
  // Boolean
  // Boolean
  // Boolean
  // QuickTime VR Splitter atom types
  // parent of settings atoms (other than compression)
  // Boolean
  // Boolean
  // Boolean
  // Boolean
  // Boolean
  // QuickTime VR Object Exporter atom types
  // block size for compression
  // target file size
  // OLDROUTINENAMES
  // __QUICKTIMEVRFORMAT__
