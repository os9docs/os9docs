/**
     \file       QuickTimeStreaming.h

    \brief   QuickTime Interfaces.

    \introduced_in  QuickTime 5.0.1
    \avaliable_from Universal Interfaces 3.4.1

    \copyright � 1990-2001 by Apple Computer, Inc., all rights reserved

    \ingroup Quicktime

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __QUICKTIMESTREAMING__
#define __QUICKTIMESTREAMING__

#ifndef __QUICKDRAW__
#include <Quickdraw.h>
#endif

#ifndef __COMPONENTS__
#include <Components.h>
#endif

#ifndef __MACERRORS__
#include <MacErrors.h>
#endif

#ifndef __MOVIES__
#include <Movies.h>
#endif

#ifndef __QUICKTIMECOMPONENTS__
#include <QuickTimeComponents.h>
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

enum {
  kQTSInfiniteDuration = 0x7FFFFFFF,
  kQTSUnknownDuration = 0x00000000,
  kQTSNormalForwardRate = 0x00010000,
  kQTSStoppedRate = 0x00000000
};

struct QTSPresentationRecord {
  long data[1];
};
typedef struct QTSPresentationRecord QTSPresentationRecord;
typedef QTSPresentationRecord *QTSPresentation;
struct QTSStreamRecord {
  long data[1];
};
typedef struct QTSStreamRecord QTSStreamRecord;
typedef QTSStreamRecord *QTSStream;
struct QTSEditEntry {
  TimeValue64 presentationDuration;
  TimeValue64 streamStartTime;
  Fixed streamRate;
};
typedef struct QTSEditEntry QTSEditEntry;
struct QTSEditList {
  SInt32 numEdits;
  QTSEditEntry edits[1];
};
typedef struct QTSEditList QTSEditList;
typedef QTSEditList *QTSEditListPtr;
typedef QTSEditListPtr *QTSEditListHandle;
#define kQTSInvalidPresentation (QTSPresentation)0L
#define kQTSAllPresentations (QTSPresentation)0L
#define kQTSInvalidStream (QTSStream)0L
#define kQTSAllStreams (QTSStream)0L
typedef CALLBACK_API(ComponentResult,
                     QTSNotificationProcPtr)(ComponentResult inErr,
                                             OSType inNotificationType,
                                             void *inNotificationParams,
                                             void *inRefCon);
typedef STACK_UPP_TYPE(QTSNotificationProcPtr) QTSNotificationUPP;
/*-----------------------------------------
    Get / Set Info
-----------------------------------------*/
enum {
  kQTSGetURLLink = FOUR_CHAR_CODE('gull') // QTSGetURLLinkRecord* };

// get and set enum {
// get and set 
      FOUR_CHAR_CODE('bufr'), // Fixed* in seconds; expected, not actual   kQTSDurationInfo = FOUR_CHAR_CODE('dura'), // QTSDurationAtom*   kQTSSoundLevelMeteringEnabledInfo = FOUR_CHAR_CODE('mtrn'), // Boolean*   kQTSSoundLevelMeterInfo = FOUR_CHAR_CODE('levm'),  // LevelMeterInfoPtr   kQTSSourceTrackIDInfo = FOUR_CHAR_CODE('otid'),    // UInt32*   kQTSSourceLayerInfo = FOUR_CHAR_CODE('olyr'),      // UInt16*   kQTSSourceLanguageInfo = FOUR_CHAR_CODE('olng'),   // UInt16*   kQTSSourceTrackFlagsInfo = FOUR_CHAR_CODE('otfl'), // SInt32*   kQTSSourceDimensionsInfo = FOUR_CHAR_CODE('odim'), // QTSDimensionParams*   kQTSSourceVolumesInfo = FOUR_CHAR_CODE('ovol'),    // QTSVolumesParams*   kQTSSourceMatrixInfo = FOUR_CHAR_CODE('omat'),     // MatrixRecord*   kQTSSourceClipRectInfo = FOUR_CHAR_CODE('oclp'),   // Rect*   kQTSSourceGraphicsModeInfo =
      FOUR_CHAR_CODE('ogrm'),                   // QTSGraphicsModeParams*   kQTSSourceScaleInfo = FOUR_CHAR_CODE('oscl'), // Point*   kQTSSourceBoundingRectInfo = FOUR_CHAR_CODE('orct'), // Rect*   kQTSSourceUserDataInfo = FOUR_CHAR_CODE('oudt'),     // UserData   kQTSSourceInputMapInfo = FOUR_CHAR_CODE('oimp'),     // QTAtomContainer   kQTSInfo_DataProc = FOUR_CHAR_CODE('datp'),          // QTSDataProcParams*   kQTSInfo_SendDataExtras =
      FOUR_CHAR_CODE('dext'), // Fixed* in seconds; expected, not actual 
// QTSDurationAtom* 
// get only enum {// Boolean* 
  kQTSStatisticsInfo = FOUR_CHAR_CODE('stat'), // QTS// LevelMeterInfoPtr 
      FOUR_CHAR_CODE('mstd'), // QTSDimensionParams* // UInt32* 
      FOUR_CHAR_CODE('nstd'), // QTSDimensionParams* // UInt16* 
      FOUR_CHAR_CODE('drtt'), // UInt32*, add to what// UInt16* 
      FOUR_CHAR_CODE('drti'), // UInt32*, add to what// SInt32* 
      FOUR_CHAR_CODE('drto'), // UInt32*, add to what// QTSDimensionParams* 
      FOUR_CHAR_CODE('lpct'), // QTSLostPercentParams// QTSVolumesParams* 
      FOUR_CHAR_CODE('chsd'), // QTSCanHandleSendData// MatrixRecord* 
      FOUR_CHAR_CODE('btms'), /* UInt32* remaining bu// Rect* 
                                 in microseconds */
  kQTSInfo_SettingsText = FOUR_CHAR_CODE('sttx')// QTSGraphicsModeParams* 
// Point* 
enum { kQTSTargetBufferDurationTimeScale = 1000 };// Rect* 
// UserData 
struct QTSPanelFilterParams {// QTAtomContainer 
  SInt32 version;// QTSDataProcParams* 
  QTSStream inStream;
  OSType inPanelType;// QTSSendDataExtrasParams* 
  OSType inPanelSubType;// long* 
  QTAtomSpec details;
};
// get only 
// return true to keep this paneltypedef CALLBACK_API(Boolean,
                     QTSPanelFilterProcPtr)(QTS// QTSStatisticsParams* 
                                            void *inRefCon);
typedef STACK_UPP_TYPE(QTSPane// QTSDimensionParams* 
enum {
  kQTSSettingsTextSummary = FO// QTSDimensionParams* 
  kQTSSettingsTextDetails = FOUR_CHAR_CODE('setd')
};// UInt32*, add to what's there 

struct QTSSettingsTextParams {// UInt32*, add to what's there 
  SInt32 flags;              // None yet defined  OSType inSettingsSelector; // which kind of setting you want from enum above  Handle outSettingsAsText;  // QTS allocates; Caller disposes  QTSPanelFilterUPP inPanelFilterProc; // To get a subset filter with this     void *inPanelFilterProcRefCon;
};// UInt32*, add to what's there 
typedef struct QTSSettingsTextParams QTSSettingsTextParams;
struct QTSCanHandleSendDataTyp// QTSLostPercentParams*, add to what's there 
  SInt32 modifierTypeOrInputID;// UInt32* 
  Boolean isModifierType;// OSType* 
  Boolean returnedCanHandleSendDataType; /* cal// QTSNameParams* 
                                            it*/
};// QTSCanHandleSendDataTypeParams* 
typedef struct QTSCanHandleSendDataTypeParams QT// QTAtomContainer 
struct QTSNameParams {
  SInt32 maxNameLength;
  SInt32 requestedLanguage;
  SInt32 returnedActualLanguage;// QTSSettingsTextParams* 
  unsigned char *returnedName; // pascal string; caller supplies};
typedef struct QTSNameParams QTSNameParams;
struct QTSLostPercentParams {
  UInt32 receivedPkts;
  UInt32 lostPkts;
  Fixed percent;
};
typedef struct QTSLostPercentParams QTSLostPercentParams;
struct QTSDimensionParams {
  Fixed width;
  Fixed height;
};
// return true to keep this panel
struct QTSVolumesParams {
  SInt16 leftVolume;
  SInt16 rightVolume;
};
typedef struct QTSVolumesParams QTSVolumesParams;
struct QTSGraphicsModeParams {
  SInt16 graphicsMode;
  RGBColor opColor;
};
typedef struct QTSGraphicsModeParams QTSGraphicsModeParams;
struct QTSGetURLLinkRecord {// None yet defined
  Point displayWhere;// which kind of setting you want from enum above
  Handle returnedURLLink;// QTS allocates; Caller disposes
};// To get a subset filter with this   
typedef struct QTSGetURLLinkRecord QTSGetURLLinkRecord;
enum { kQTSDataProcParamsVersion1 = 1 };

enum {
  kQTSDataProcType_MediaSample = FOUR_CHAR_CODE('mdia'),
  kQTSDataProcType_HintSample = FOUR_CHAR_CODE('hint')
};

struct QTSDataProcParams {
  SInt32 version;
  SInt32 flags;
  QTSStream stream;
  OSType procType;
  QTSNotificationUPP proc;
  void *procRefCon;// pascal string; caller supplies
};
typedef struct QTSDataProcParams QTSDataProcParams;
enum {
  kQTSDataProcSelector_SampleData = FOUR_CHAR_CODE('samp'),
  kQTSDataProcSelector_UserData = FOUR_CHAR_CODE('user')
};

enum { kQTSSampleDataCallbackParamsVersion1 = 1 };

struct QTSSampleDataCallbackParams {
  SInt32 version;
  SInt32 flags;
  QTSStream stream;
  OSType procType;
  OSType mediaType;
  TimeScale mediaTimeScale;
  SampleDescriptionHandle sampleDesc;
  UInt32 sampleDescSeed;
  TimeValue64 sampleTime;
  TimeValue64 duration; // could be 0   SInt32 sampleFlags;
  UInt32 dataLength;
  const void *data;
};
typedef struct QTSSampleDataCallbackParams QTSSampleDataCallbackParams;
enum { kQTSUserDataCallbackParamsVersion1 = 1 };

struct QTSUserDataCallbackParams {
  SInt32 version;
  SInt32 flags;
  QTSStream stream;
  OSType procType;
  OSType userDataType;
  Handle userDataHandle; /* caller must make copy if it wants to keep the data
                            around*/
};
typedef struct QTSUserDataCallbackParams QTSUserDataCallbackParams;
enum { kQTSSendDataExtrasParamsVersion1 = 1 };

struct QTSSendDataExtrasParams {
  SInt32 version;
  SInt32 flags;
  OSType procType;
};
typedef struct QTSSendDataExtrasParams QTSSendDataExtrasParams;
typedef CALLBACK_API(Boolean, QTSModalFilterProcPtr)(DialogPtr inDialog,
                                                     const EventRecord *inEvent,
                                                     SInt16 *ioItemHit,
                                                     void *inRefCon);
typedef STACK_UPP_TYPE(QTSModalFilterProcPtr) QTSModalFilterUPP;
/*-----------------------------------------
    Characteristics
-----------------------------------------*/
// characteristics in Movies.h work here too enum { kQTSSupportsPerStreamControlCharacteristic = FOUR_CHAR_CODE('psct') };

struct QTSVideoParams {
  Fixed width;
  Fixed height;
  MatrixRecord matrix;
  CGrafPtr gWorld;
  GDHandle gdHandle;
  RgnHandle clip;
  short graphicsMode;// could be 0 
  RGBColor opColor;
};
typedef struct QTSVideoParams QTSVideoParams;
struct QTSAudioParams {
  SInt16 leftVolume;
  SInt16 rightVolume;
  SInt16 bassLevel;
  SInt16 trebleLevel;
  short frequencyBandsCount;
  void *frequencyBands;
  Boolean levelMeteringEnabled;
};
typedef struct QTSAudioParams QTSAudioParams;
struct QTSMediaParams {
  QTSVideoParams v;
  QTSAudioParams a;
};
typedef struct QTSMediaParams QTSMediaParams;
enum {
  kQTSMustDraw = 1 << 3,
  kQTSAtEnd = 1 << 4,
  kQTSPreflightDraw = 1 << 5,
  kQTSSyncDrawing = 1 << 6
};

// media task result flags enum {
  kQTSDidDraw = 1 << 0,
  kQTSNeedsToDraw = 1 << 2,
  kQTSDrawAgain = 1 << 3,
  kQTSPartialDraw = 1 << 4
};

/*============================================================================
// characteristics in Movies.h work here too 
============================================================================*/
// ------ notification types ------ enum {
  kQTSNullNotification = FOUR_CHAR_CODE('null'), // NULL   kQTSErrorNotification =
      FOUR_CHAR_CODE('err '), // QTSErrorParams*, optional   kQTSNewPresDetectedNotification =
      FOUR_CHAR_CODE('newp'), // QTSNewPresDetectedParams*   kQTSPresBeginChangingNotification = FOUR_CHAR_CODE('prcb'),   // NULL   kQTSPresDoneChangingNotification = FOUR_CHAR_CODE('prcd'),    // NULL   kQTSPresentationChangedNotification = FOUR_CHAR_CODE('prch'), // NULL   kQTSNewStreamNotification = FOUR_CHAR_CODE('stnw'), // QTSNewStreamParams*   kQTSStreamBeginChangingNotification = FOUR_CHAR_CODE('stcb'), // QTSStream   kQTSStreamDoneChangingNotification = FOUR_CHAR_CODE('stcd'),  // QTSStream   kQTSStreamChangedNotification =
      FOUR_CHAR_CODE('stch'), // QTSStreamChangedParams*   kQTSStreamGoneNotification =
      FOUR_CHAR_CODE('stgn'), // QTSStreamGoneParams*   kQTSPreviewAckNotification = FOUR_CHAR_CODE('pvak'), // QTSStream   kQTSPrerollAckNotification = FOUR_CHAR_CODE('pack'), // QTSStream   kQTSStartAckNotification = FOUR_CHAR_CODE('sack'),   // QTSStream   kQTSStopAckNotification = FOUR_CHAR_CODE('xack'),    // QTSStream   kQTSStatusNotification = FOUR_CHAR_CODE('stat'),     // QTSStatusParams*   kQTSURLNotification = FOUR_CHAR_CODE('url '),        // QTSURLParams*   kQTSDurationNotification = FOUR_CHAR_CODE('dura'),   // QTSDurationAtom*   kQTSNewPresentationNotification =
      FOUR_CHAR_CODE('nprs'), // QTSPresentation   kQTSPresentationGoneNotification =
      FOUR_CHAR_CODE('xprs'), // QTSPresentation   kQTSPresentationDoneNotification = FOUR_CHAR_CODE('pdon'), // NULL   kQTSBandwidthAlertNotification =
      FOUR_CHAR_CODE('bwal'), // QTSBandwidthAlertParams*   kQTSAnnotationsChangedNotification = FOUR_CHAR_CODE('meta') // NULL };

// flags for QTSErrorParams enum { kQTSFatalErrorFlag = 0x00000001 };

struct QTSErrorParams {
  const char *errorString;
  SInt32 flags;
};
typedef struct QTSErrorParams QTSErrorParams;
struct QTSNewPresDetectedParams {
  void *data;
};
typedef struct QTSNewPresDetectedParams QTSNewPresDetectedParams;
struct QTSNewStreamParams {
  QTSStream stream;
};
typedef struct QTSNewStreamParams QTSNewStreamParams;
struct QTSStreamChangedParams {
  QTSStream stream;
  ComponentInstance mediaComponent; // could be NULL };
typedef struct QTSStreamChangedParams QTSStreamChangedParams;
struct QTSStreamGoneParams {
  QTSStream stream;
};
typedef struct QTSStreamGoneParams QTSStreamGoneParams;
struct QTSStatusParams {
// media task result flags 
  const char *statusString;
  UInt32 detailedStatus;
  const char *detailedStatusString;
};
typedef struct QTSStatusParams QTSStatusParams;
struct QTSInfoParams {
  OSType infoType;
  void *infoParams;
};
typedef struct QTSInfoParams QTSInfoParams;
// ------ notification types ------ 
  UInt32 urlLength;
  const char *url;// NULL 
};
typedef struct QTSURLParams QT// QTSErrorParams*, optional 
enum {
  kQTSBandwidthAlertNeedToStop// QTSNewPresDetectedParams* 
  kQTSBandwidthAlertRestartAt = 1 << 1// NULL 
};// NULL 
// NULL 
struct QTSBandwidthAlertParams {// QTSNewStreamParams* 
  SInt32 flags;// QTSStream 
  TimeValue restartAt; // new field in QT 4.1  void *reserved;// QTSStream 
};
typedef struct QTSBandwidthAle// QTSStreamChangedParams* 
/*============================================================================
        Presentation// QTSStreamGoneParams* 
=======================================================// QTSStream 
/*-----------------------------------------// QTSStream 
     Flags// QTSStream 
-----------------------------------------*/// QTSStream 
// flags for NewPresentationFromData enum {// QTSStatusParams* 
  kQTSAutoModeFlag = 0x00000001,// QTSURLParams* 
  kQTSDontShowStatusFlag = 0x00000008,// QTSDurationAtom* 
  kQTSSendMediaFlag = 0x00010000,
  kQTSReceiveMediaFlag = 0x000// QTSPresentation 
};
// QTSPresentation 
struct QTSNewPresentationParams {// NULL 
  OSType dataType;
  const void *data;// QTSBandwidthAlertParams* 
  UInt32 dataLength;// NULL 
  QTSEditListHandle editList;
  SInt32 flags;
// flags for QTSErrorParams 
  QTSNotificationUPP notificationProc;
  void *notificationRefCon;
};
typedef struct QTSNewPresentationParams QTSNewPresentationParams;
struct QTSPresParams {
  UInt32 version;
  QTSEditListHandle editList;
  SInt32 flags;
  TimeScale timeScale; // set to 0 for default timescale   QTSMediaParams *mediaParams;
  QTSNotificationUPP notificationProc;
  void *notificationRefCon;
};
typedef struct QTSPresParams QTSPresParams;
enum { kQTSPresParamsVersion1 = 1 };

struct QTSPresIdleParams {
  QTSStream stream;
  TimeValue64 movieTimeToDisplay;// could be NULL 
  SInt32 flagsIn;
  SInt32 flagsOut;
};
typedef struct QTSPresIdleParams QTSPresIdleParams;
enum { kQTSExportFlag_ShowDialog = 0x00000001 };

enum { kQTSExportParamsVersion1 = 1 };

struct QTSExportParams {
  SInt32 version;
  OSType exportType;
  void *exportExtraData;
  OSType destinationContainerType;
  void *destinationContainerData;
  void *destinationContainerExtras;
  SInt32 flagsIn;
  SInt32 flagsOut;
  QTSModalFilterUPP filterProc;
  void *filterProcRefCon;
  Component exportComponent; // NULL unless you want to override };
typedef struct QTSExportParams QTSExportParams;
/*-----------------------------------------
    Toolbox Init/Close
-----------------------------------------*/
// all "apps" must call this /**
 *  InitializeQTS()
 *

 *    \non_carbon_cfm   in QTStreamLib 4.0 and later
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x        // new field in QT 4.1
 *    Windows:          in QTSClient.lib 4.0 and later
 */
OSErr
InitializeQTS(void);

/**
 *  TerminateQTS()
 *

// flags for NewPresentationFromData 
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 *    Windows:          in QTSClient.lib 4.0 and later
 */
OSErr
TerminateQTS(void);

/*-----------------------------------------
    Presentation Functions
-----------------------------------------*/
/**
 *  QTSNewPresentation()
 *
// set to 0 for default timescale 
 *    \non_carbon_cfm   in QTStreamLib 4.0 and later
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 *    Windows:          in QTSClient.lib 4.0 and later
 */
OSErr
QTSNewPresentation(const QTSNewPresentationParams *inParams,
                   QTSPresentation *outPresentation);

/**// set to 0 for default timescale 
 *  QTSNewPresentationFromData()
 *

 *    \non_carbon_cfm   in QTStreamLib 5.0 and later
 *    \carbon_lib        in CarbonLib 1.3 and later
 *    \mac_os_x         in version 10.0 and later
 *    Windows:          in QTSClient.lib 5.0 and later
 */
OSErr
QTSNewPresentationFromData(OSType inDataType, const void *inData,
                           const SInt64 *inDataLength,
                           const QTSPresParams *inPresParams,
                           QTSPresentation *outPresentation);

/**
 *  QTSNewPresentationFromFile()
 *

 *    \non_carbon_cfm   in QTStreamLib 5.0 and later
 *    \carbon_lib        in CarbonLib 1.3 and later
 *    \mac_os_x         in version 10.0 and later
 *    Windows:          in QTSClient.lib 5.0 and later
 */
OSErr
QTSNewPresentationFromFile(const FSSpec *inFileSpec,
                           const QTSPresParams *inPresParams,
                           QTSPresentation *outPresentation);

/**
 *  QTSNewPresentationFromDat// NULL unless you want to override 
 *

 *    \non_carbon_cfm   in QTStreamLib 5.0 and later
 *    \carbon_lib        in CarbonLib 1.3 and later
 *    \mac_os_x         in version 10.0 and later
// all "apps" must call this 
 */
OSErr
QTSNewPresentationFromDataRef(Handle inDataRef, OSType inDataRefType,
                              const QTSPresParams *inPresParams,
                              QTSPresentation *outPresentation);

/**
 *  QTSDisposePresentation()
 *

 *    \non_carbon_cfm   in QTStreamLib 4.0 and later
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 *    Windows:          in QTSClient.lib 4.0 and later
 */
OSErr
QTSDisposePresentation(QTSPresentation inPresentation, SInt32 inFlags);

/**
 *  QTSPresExport()
 *

 *    \non_carbon_cfm   in QTStreamLib 5.0 and later
 *    \carbon_lib        in CarbonLib 1.3 and later
 *    \mac_os_x         in version 10.0 and later
 *    Windows:          in QTSClient.lib 5.0 and later
 */
OSErr
QTSPresExport(QTSPresentation inPresentation, QTSStream inStream,
              QTSExportParams *inExportParams);

/**
 *  QTSPresIdle()
 *

 *    \non_carbon_cfm   in QTStreamLib 4.0 and later
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 *    Windows:          in QTSClient.lib 4.0 and later
 */
void
QTSPresIdle(QTSPresentation inPresentation, QTSPresIdleParams *ioParams);

/**
 *  QTSPresInvalidateRegion()
 *

 *    \non_carbon_cfm   in QTStreamLib 4.0 and later
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 *    Windows:          in QTSClient.lib 4.0 and later
 */
OSErr
QTSPresInvalidateRegion(QTSPresentation inPresentation, RgnHandle inRegion);

/*-----------------------------------------
    Presentation Configuration
-----------------------------------------*/
/**
 *  QTSPresSetFlags()
 *

 *    \non_carbon_cfm   in QTStreamLib 4.0 and later
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 *    Windows:          in QTSClient.lib 4.0 and later
 */
OSErr
QTSPresSetFlags(QTSPresentation inPresentation, SInt32 inFlags,
                SInt32 inFlagsMask);

/**
 *  QTSPresGetFlags()
 *

 *    \non_carbon_cfm   in QTStreamLib 4.0 and later
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 *    Windows:          in QTSClient.lib 4.0 and later
 */
OSErr
QTSPresGetFlags(QTSPresentation inPresentation, SInt32 *outFlags);

/**
 *  QTSPresGetTimeBase()
 *

 *    \non_carbon_cfm   in QTStreamLib 4.0 and later
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 *    Windows:          in QTSClient.lib 4.0 and later
 */
OSErr
QTSPresGetTimeBase(QTSPresentation inPresentation, TimeBase *outTimeBase);

/**
 *  QTSPresGetTimeScale()
 *

 *    \non_carbon_cfm   in QTStreamLib 4.0 and later
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 *    Windows:          in QTSClient.lib 4.0 and later
 */
OSErr
QTSPresGetTimeScale(QTSPresentation inPresentation, TimeScale *outTimeScale);

/**
 *  QTSPresSetInfo()
 *

 *    \non_carbon_cfm   in QTStreamLib 4.0 and later
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 *    Windows:          in QTSClient.lib 4.0 and later
 */
OSErr
QTSPresSetInfo(QTSPresentation inPresentation, QTSStream inStream,
               OSType inSelector, void *ioParam);

/**
 *  QTSPresGetInfo()
 *

 *    \non_carbon_cfm   in QTStreamLib 4.0 and later
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 *    Windows:          in QTSClient.lib 4.0 and later
 */
OSErr
QTSPresGetInfo(QTSPresentation inPresentation, QTSStream inStream,
               OSType inSelector, void *ioParam);

/**
 *  QTSPresHasCharacteristic()
 *

 *    \non_carbon_cfm   in QTStreamLib 4.0 and later
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 *    Windows:          in QTSClient.lib 4.0 and later
 */
OSErr
QTSPresHasCharacteristic(QTSPresentation inPresentation, QTSStream inStream,
                         OSType inCharacteristic, Boolean *outHasIt);

/**
 *  QTSPresSetNotificationProc()
 *

 *    \non_carbon_cfm   in QTStreamLib 4.0 and later
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 *    Windows:          in QTSClient.lib 4.0 and later
 */
OSErr
QTSPresSetNotificationProc(QTSPresentation inPresentation,
                           QTSNotificationUPP inNotificationProc,
                           void *inRefCon);

/**
 *  QTSPresGetNotificationProc()
 *

 *    \non_carbon_cfm   in QTStreamLib 4.0 and later
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 *    Windows:          in QTSClient.lib 4.0 and later
 */
OSErr
QTSPresGetNotificationProc(QTSPresentation inPresentation,
                           QTSNotificationUPP *outNotificationProc,
                           void **outRefCon);

/*-----------------------------------------
    Presentation Control
-----------------------------------------*/
/**
 *  QTSPresPreview()
 *

 *    \non_carbon_cfm   in QTStreamLib 5.0 and later
 *    \carbon_lib        in CarbonLib 1.3 and later
 *    \mac_os_x         in version 10.0 and later
 */
OSErr
QTSPresPreview(QTSPresentation inPresentation, QTSStream inStream,
               const TimeValue64 *inTimeValue, Fixed inRate, SInt32 inFlags);

/**
 *  QTSPresPreroll()
 *

 *    \non_carbon_cfm   in QTStreamLib 4.0 and later
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 *    Windows:          in QTSClient.lib 4.0 and later
 */
OSErr
QTSPresPreroll(QTSPresentation inPresentation, QTSStream inStream,
               UInt32 inTimeValue, Fixed inRate, SInt32 inFlags);

/**
 *  QTSPresPreroll64()
 *

 *    \non_carbon_cfm   in QTStreamLib 4.1 and later
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 *    Windows:          in QTSClient.lib 4.1 and later
 */
OSErr
QTSPresPreroll64(QTSPresentation inPresentation, QTSStream inStream,
                 const TimeValue64 *inPrerollTime, Fixed inRate,
                 SInt32 inFlags);

/**
 *  QTSPresStart()
 *

 *    \non_carbon_cfm   in QTStreamLib 4.0 and later
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 *    Windows:          in QTSClient.lib 4.0 and later
 */
OSErr
QTSPresStart(QTSPresentation inPresentation, QTSStream inStream,
             SInt32 inFlags);

/**
 *  QTSPresSkipTo()
 *

 *    \non_carbon_cfm   in QTStreamLib 4.0 and later
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 *    Windows:          in QTSClient.lib 4.0 and later
 */
OSErr
QTSPresSkipTo(QTSPresentation inPresentation, UInt32 inTimeValue);

/**
 *  QTSPresSkipTo64()
 *

 *    \non_carbon_cfm   in QTStreamLib 4.1 and later
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 *    Windows:          in QTSClient.lib 4.1 and later
 */
OSErr
QTSPresSkipTo64(QTSPresentation inPresentation, const TimeValue64 *inTimeValue);

/**
 *  QTSPresStop()
 *

 *    \non_carbon_cfm   in QTStreamLib 4.0 and later
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 *    Windows:          in QTSClient.lib 4.0 and later
 */
OSErr
QTSPresStop(QTSPresentation inPresentation, QTSStream inStream, SInt32 inFlags);

/*============================================================================
        Streams
============================================================================*/
/*-----------------------------------------
    Stream Functions
-----------------------------------------*/
/**
 *  QTSPresNewStream()
 *

 *    \non_carbon_cfm   in QTStreamLib 4.0 and later
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 *    Windows:          in QTSClient.lib 4.0 and later
 */
OSErr
QTSPresNewStream(QTSPresentation inPresentation, OSType inDataType,
                 const void *inData, UInt32 inDataLength, SInt32 inFlags,
                 QTSStream *outStream);

/**
 *  QTSDisposeStream()
 *

 *    \non_carbon_cfm   in QTStreamLib 4.0 and later
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 *    Windows:          in QTSClient.lib 4.0 and later
 */
OSErr
QTSDisposeStream(QTSStream inStream, SInt32 inFlags);

/**
 *  QTSPresGetNumStreams()
 *

 *    \non_carbon_cfm   in QTStreamLib 4.0 and later
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 *    Windows:          in QTSClient.lib 4.0 and later
 */
UInt32
QTSPresGetNumStreams(QTSPresentation inPresentation);

/**
 *  QTSPresGetIndStream()
 *

 *    \non_carbon_cfm   in QTStreamLib 4.0 and later
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 *    Windows:          in QTSClient.lib 4.0 and later
 */
QTSStream
QTSPresGetIndStream(QTSPresentation inPresentation, UInt32 inIndex);

/**
 *  QTSGetStreamPresentation()
 *

 *    \non_carbon_cfm   in QTStreamLib 4.0 and later
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 *    Windows:          in QTSClient.lib 4.0 and later
 */
QTSPresentation
QTSGetStreamPresentation(QTSStream inStream);

/**
 *  QTSPresSetPreferredRate()
 *

 *    \non_carbon_cfm   in QTStreamLib 4.0 and later
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 *    Windows:          in QTSClient.lib 4.0 and later
 */
OSErr
QTSPresSetPreferredRate(QTSPresentation inPresentation, Fixed inRate,
                        SInt32 inFlags);

/**
 *  QTSPresGetPreferredRate()
 *

 *    \non_carbon_cfm   in QTStreamLib 4.0 and later
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 *    Windows:          in QTSClient.lib 4.0 and later
 */
OSErr
QTSPresGetPreferredRate(QTSPresentation inPresentation, Fixed *outRate);

/**
 *  QTSPresSetEnable()
 *

 *    \non_carbon_cfm   in QTStreamLib 4.0 and later
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 *    Windows:          in QTSClient.lib 4.0 and later
 */
OSErr
QTSPresSetEnable(QTSPresentation inPresentation, QTSStream inStream,
                 Boolean inEnableMode);

/**
 *  QTSPresGetEnable()
 *

 *    \non_carbon_cfm   in QTStreamLib 4.0 and later
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 *    Windows:          in QTSClient.lib 4.0 and later
 */
OSErr
QTSPresGetEnable(QTSPresentation inPresentation, QTSStream inStream,
                 Boolean *outEnableMode);

/**
 *  QTSPresSetPresenting()
 *

 *    \non_carbon_cfm   in QTStreamLib 4.0 and later
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 *    Windows:          in QTSClient.lib 4.0 and later
 */
OSErr
QTSPresSetPresenting(QTSPresentation inPresentation, QTSStream inStream,
                     Boolean inPresentingMode);

/**
 *  QTSPresGetPresenting()
 *

 *    \non_carbon_cfm   in QTStreamLib 4.0 and later
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 *    Windows:          in QTSClient.lib 4.0 and later
 */
OSErr
QTSPresGetPresenting(QTSPresentation inPresentation, QTSStream inStream,
                     Boolean *outPresentingMode);

/**
 *  QTSPresSetActiveSegment()
 *

 *    \non_carbon_cfm   in QTStreamLib 4.1 and later
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 *    Windows:          in QTSClient.lib 4.1 and later
 */
OSErr
QTSPresSetActiveSegment(QTSPresentation inPresentation, QTSStream inStream,
                        const TimeValue64 *inStartTime,
                        const TimeValue64 *inDuration);

/**
 *  QTSPresGetActiveSegment()
 *

 *    \non_carbon_cfm   in QTStreamLib 4.1 and later
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 *    Windows:          in QTSClient.lib 4.1 and later
 */
OSErr
QTSPresGetActiveSegment(QTSPresentation inPresentation, QTSStream inStream,
                        TimeValue64 *outStartTime, TimeValue64 *outDuration);

/**
 *  QTSPresSetPlayHints()
 *

 *    \non_carbon_cfm   in QTStreamLib 4.0 and later
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 *    Windows:          in QTSClient.lib 4.0 and later
 */
OSErr
QTSPresSetPlayHints(QTSPresentation inPresentation, QTSStream inStream,
                    SInt32 inFlags, SInt32 inFlagsMask);

/**
 *  QTSPresGetPlayHints()
 *

 *    \non_carbon_cfm   in QTStreamLib 4.0 and later
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 *    Windows:          in QTSClient.lib 4.0 and later
 */
OSErr
QTSPresGetPlayHints(QTSPresentation inPresentation, QTSStream inStream,
                    SInt32 *outFlags);

/*-----------------------------------------
    Stream Spatial Functions
-----------------------------------------*/
/**
 *  QTSPresSetGWorld()
 *

 *    \non_carbon_cfm   in QTStreamLib 4.0 and later
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 *    Windows:          in QTSClient.lib 4.0 and later
 */
OSErr
QTSPresSetGWorld(QTSPresentation inPresentation, QTSStream inStream,
                 CGrafPtr inGWorld, GDHandle inGDHandle);

/**
 *  QTSPresGetGWorld()
 *

 *    \non_carbon_cfm   in QTStreamLib 4.0 and later
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 *    Windows:          in QTSClient.lib 4.0 and later
 */
OSErr
QTSPresGetGWorld(QTSPresentation inPresentation, QTSStream inStream,
                 CGrafPtr *outGWorld, GDHandle *outGDHandle);

/**
 *  QTSPresSetClip()
 *

 *    \non_carbon_cfm   in QTStreamLib 4.0 and later
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 *    Windows:          in QTSClient.lib 4.0 and later
 */
OSErr
QTSPresSetClip(QTSPresentation inPresentation, QTSStream inStream,
               RgnHandle inClip);

/**
 *  QTSPresGetClip()
 *

 *    \non_carbon_cfm   in QTStreamLib 4.0 and later
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 *    Windows:          in QTSClient.lib 4.0 and later
 */
OSErr
QTSPresGetClip(QTSPresentation inPresentation, QTSStream inStream,
               RgnHandle *outClip);

/**
 *  QTSPresSetMatrix()
 *

 *    \non_carbon_cfm   in QTStreamLib 4.0 and later
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 *    Windows:          in QTSClient.lib 4.0 and later
 */
OSErr
QTSPresSetMatrix(QTSPresentation inPresentation, QTSStream inStream,
                 const MatrixRecord *inMatrix);

/**
 *  QTSPresGetMatrix()
 *

 *    \non_carbon_cfm   in QTStreamLib 4.0 and later
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 *    Windows:          in QTSClient.lib 4.0 and later
 */
OSErr
QTSPresGetMatrix(QTSPresentation inPresentation, QTSStream inStream,
                 MatrixRecord *outMatrix);

/**
 *  QTSPresSetDimensions()
 *

 *    \non_carbon_cfm   in QTStreamLib 4.0 and later
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 *    Windows:          in QTSClient.lib 4.0 and later
 */
OSErr
QTSPresSetDimensions(QTSPresentation inPresentation, QTSStream inStream,
                     Fixed inWidth, Fixed inHeight);

/**
 *  QTSPresGetDimensions()
 *

 *    \non_carbon_cfm   in QTStreamLib 4.0 and later
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 *    Windows:          in QTSClient.lib 4.0 and later
 */
OSErr
QTSPresGetDimensions(QTSPresentation inPresentation, QTSStream inStream,
                     Fixed *outWidth, Fixed *outHeight);

/**
 *  QTSPresSetGraphicsMode()
 *

 *    \non_carbon_cfm   in QTStreamLib 4.0 and later
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 *    Windows:          in QTSClient.lib 4.0 and later
 */
OSErr
QTSPresSetGraphicsMode(QTSPresentation inPresentation, QTSStream inStream,
                       short inMode, const RGBColor *inOpColor);

/**
 *  QTSPresGetGraphicsMode()
 *

 *    \non_carbon_cfm   in QTStreamLib 4.0 and later
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 *    Windows:          in QTSClient.lib 4.0 and later
 */
OSErr
QTSPresGetGraphicsMode(QTSPresentation inPresentation, QTSStream inStream,
                       short *outMode, RGBColor *outOpColor);

/**
 *  QTSPresGetPicture()
 *

 *    \non_carbon_cfm   in QTStreamLib 4.0 and later
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 *    Windows:          in QTSClient.lib 4.0 and later
 */
OSErr
QTSPresGetPicture(QTSPresentation inPresentation, QTSStream inStream,
                  PicHandle *outPicture);

/*-----------------------------------------
    Stream Sound Functions
-----------------------------------------*/
/**
 *  QTSPresSetVolumes()
 *

 *    \non_carbon_cfm   in QTStreamLib 4.0 and later
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 *    Windows:          in QTSClient.lib 4.0 and later
 */
OSErr
QTSPresSetVolumes(QTSPresentation inPresentation, QTSStream inStream,
                  short inLeftVolume, short inRightVolume);

/**
 *  QTSPresGetVolumes()
 *

 *    \non_carbon_cfm   in QTStreamLib 4.0 and later
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 *    Windows:          in QTSClient.lib 4.0 and later
 */
OSErr
QTSPresGetVolumes(QTSPresentation inPresentation, QTSStream inStream,
                  short *outLeftVolume, short *outRightVolume);

/*-----------------------------------------
    Sourcing
-----------------------------------------*/
/**
 *  QTSPresGetSettingsAsText()
 *

 *    \non_carbon_cfm   in QTStreamLib 5.0.1 and later
 *    \carbon_lib        not available in CarbonLib 1.x, is available on Mac OS
 X version 10.1 and later
 *    \mac_os_x         in version 10.1 and later
 */
OSErr
QTSPresGetSettingsAsText(QTSPresentation inPresentation, QTSStream inStream,
                         SInt32 inFlags, OSType inSettingsType, Handle *outText,
                         QTSPanelFilterUPP inPanelFilterProc,
                         void *inPanelFilterProcRefCon);

/**
 *  QTSPresSettingsDialog()
 *

 *    \non_carbon_cfm   in QTStreamLib 5.0 and later
 *    \carbon_lib        in CarbonLib 1.3 and later
 *    \mac_os_x         in version 10.0 and later
 */
OSErr
QTSPresSettingsDialog(QTSPresentation inPresentation, QTSStream inStream,
                      SInt32 inFlags, QTSModalFilterUPP inFilterProc,
                      void *inFilterProcRefCon);

/**
 *  QTSPresSettingsDialogWithFilters()
 *

 *    \non_carbon_cfm   in QTStreamLib 5.0.1 and later
 *    \carbon_lib        not available in CarbonLib 1.x, is available on Mac OS
 X version 10.1 and later
 *    \mac_os_x         in version 10.1 and later
 */
OSErr
QTSPresSettingsDialogWithFilters(QTSPresentation inPresentation,
                                 QTSStream inStream, SInt32 inFlags,
                                 QTSModalFilterUPP inFilterProc,
                                 void *inFilterProcRefCon,
                                 QTSPanelFilterUPP inPanelFilterProc,
                                 void *inPanelFilterProcRefCon);

/**
 *  QTSPresSetSettings()
 *

 *    \non_carbon_cfm   in QTStreamLib 5.0 and later
 *    \carbon_lib        in CarbonLib 1.3 and later
 *    \mac_os_x         in version 10.0 and later
 */
OSErr
QTSPresSetSettings(QTSPresentation inPresentation, QTSStream inStream,
                   QTAtomSpecPtr inSettings, SInt32 inFlags);

/**
 *  QTSPresGetSettings()
 *

 *    \non_carbon_cfm   in QTStreamLib 5.0 and later
 *    \carbon_lib        in CarbonLib 1.3 and later
 *    \mac_os_x         in version 10.0 and later
 */
OSErr
QTSPresGetSettings(QTSPresentation inPresentation, QTSStream inStream,
                   QTAtomContainer *outSettings, SInt32 inFlags);

/**
 *  QTSPresAddSourcer()
 *

 *    \non_carbon_cfm   in QTStreamLib 5.0 and later
 *    \carbon_lib        in CarbonLib 1.3 and later
 *    \mac_os_x         in version 10.0 and later
 */
OSErr
QTSPresAddSourcer(QTSPresentation inPresentation, QTSStream inStream,
                  ComponentInstance inSourcer, SInt32 inFlags);

/**
 *  QTSPresRemoveSourcer()
 *

 *    \non_carbon_cfm   in QTStreamLib 5.0 and later
 *    \carbon_lib        in CarbonLib 1.3 and later
 *    \mac_os_x         in version 10.0 and later
 */
OSErr
QTSPresRemoveSourcer(QTSPresentation inPresentation, QTSStream inStream,
                     ComponentInstance inSourcer, SInt32 inFlags);

/**
 *  QTSPresGetNumSourcers()
 *

 *    \non_carbon_cfm   in QTStreamLib 5.0 and later
 *    \carbon_lib        in CarbonLib 1.3 and later
 *    \mac_os_x         in version 10.0 and later
 */
UInt32
QTSPresGetNumSourcers(QTSPresentation inPresentation, QTSStream inStream);

/**
 *  QTSPresGetIndSourcer()
 *

 *    \non_carbon_cfm   in QTStreamLib 5.0 and later
 *    \carbon_lib        in CarbonLib 1.3 and later
 *    \mac_os_x         in version 10.0 and later
 */
OSErr
QTSPresGetIndSourcer(QTSPresentation inPresentation, QTSStream inStream,
                     UInt32 inIndex, ComponentInstance *outSourcer);

/*============================================================================
        Misc
============================================================================*/
// flags for Get/SetNetworkAppName enum { kQTSNetworkAppNameIsFullNameFlag = 0x00000001 };

/**
 *  QTSSetNetworkAppName()
 *

 *    \non_carbon_cfm   in QTStreamLib 4.1 and later
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 *    Windows:          in QTSClient.lib 4.1 and later
 */
OSErr
QTSSetNetworkAppName(const char *inAppName, SInt32 inFlags);

/**
 *  QTSGetNetworkAppName()
 *

 *    \non_carbon_cfm   in QTStreamLib 4.1 and later
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 *    Windows:          in QTSClient.lib 4.1 and later
 */
OSErr
QTSGetNetworkAppName(SInt32 inFlags, char **outCStringPtr);

/*-----------------------------------------
    Statistics Utilities
-----------------------------------------*/
struct QTSStatHelperRecord {
  long data[1];
};
typedef struct QTSStatHelperRecord QTSStatHelperRecord;
typedef QTSStatHelperRecord *QTSStatHelper;
enum { kQTSInvalidStatHelper = 0L };

// flags for QTSStatHelperNextParams enum { kQTSStatHelperReturnPascalStringsFlag = 0x00000001 };

struct QTSStatHelperNextParams {
  SInt32 flags;
  OSType returnedStatisticsType;
  QTSStream returnedStream;
  UInt32 maxStatNameLength;
  char *returnedStatName; // NULL if you don't want it  UInt32 maxStatStringLength;
  char *returnedStatString; // NULL if you don't want it  UInt32 maxStatUnitLength;
  char *returnedStatUnit; // NULL if you don't want it};
typedef struct QTSStatHelperNextParams QTSStatHelperNextParams;
struct QTSStatisticsParams {
  OSType statisticsType;
  QTAtomContainer container;
  QTAtom parentAtom;
  SInt32 flags;
};
typedef struct QTSStatisticsParams QTSStatisticsParams;
// general statistics types enum {
  kQTSAllStatisticsType = FOUR_CHAR_CODE('all '),
  kQTSShortStatisticsType = FOUR_CHAR_CODE('shrt'),
  kQTSSummaryStatisticsType = FOUR_CHAR_CODE('summ')
};

// statistics flags enum {
  kQTSGetNameStatisticsFlag = 0x00000001,
  kQTSDontGetDataStatisticsFlag = 0x00000002,
  kQTSUpdateAtomsStatisticsFlag = 0x00000004,
  kQTSGetUnitsStatisticsFlag = 0x00000008,
  kQTSUpdateAllIfNecessaryStatisticsFlag = 0x00010000
};

// statistics atom types enum {
  kQTSStatisticsStreamAtomType = FOUR_CHAR_CODE('strm'),
  kQTSStatisticsNameAtomType =
      FOUR_CHAR_CODE('name'), // chars only, no length or terminator   kQTSStatisticsDataFormatAtomType = FOUR_CHAR_CODE('frmt'), // OSType   kQTSStatisticsDataAtomType = FOUR_CHAR_CODE('data'),
  kQTSStatisticsUnitsAtomType = FOUR_CHAR_CODE('unit'), // OSType   kQTSStatisticsUnitsNameAtomType =
      FOUR_CHAR_CODE('unin') // chars only, no length or terminator };

// statistics data formats enum {
  kQTSStatisticsSInt32DataFormat = FOUR_CHAR_CODE('si32'),
// flags for Get/SetNetworkAppName 
  kQTSStatisticsSInt16DataFormat = FOUR_CHAR_CODE('si16'),
  kQTSStatisticsUInt16DataFormat = FOUR_CHAR_CODE('ui16'),
  kQTSStatisticsFixedDataFormat = FOUR_CHAR_CODE('fixd'),
  kQTSStatisticsUnsignedFixedDataFormat = FOUR_CHAR_CODE('ufix'),
  kQTSStatisticsStringDataFormat = FOUR_CHAR_CODE('strg'),
  kQTSStatisticsOSTypeDataFormat = FOUR_CHAR_CODE('ostp'),
  kQTSStatisticsRectDataFormat = FOUR_CHAR_CODE('rect'),
  kQTSStatisticsPointDataFormat = FOUR_CHAR_CODE('pont')
};

// statistics units types enum {
  kQTSStatisticsNoUnitsType = 0,
  kQTSStatisticsPercentUnitsType = FOUR_CHAR_CODE('pcnt'),
  kQTSStatisticsBitsPerSecUnitsType = FOUR_CHAR_CODE('bps '),
  kQTSStatisticsFramesPerSecUnitsType = FOUR_CHAR_CODE('fps ')
};

// specific statistics types enum {
  kQTSTotalDataRateStat = FOUR_CHAR_CODE('drtt'),
  kQTSTotalDataRateInStat = FOUR_CHAR_CODE('drti'),
  kQTSTotalDataRateOutStat = FOUR_CHAR_CODE('drto'),
  kQTSNetworkIDStringStat = FOUR_CHAR_CODE('nids')
};

/**
 *  QTSNewStatHelper()
 *

 *    \non_carbon_cfm   in QTStreamLib 4.0 and later
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 *    Windows:          in QTSClient.lib 4.0 and later
 */
OSErr
QTSNewStatHelper(QTSPresentation inPresentation, QTSStream inStream,
                 OSType inStatType, SInt32 inFlags,
// flags for QTSStatHelperNextParams 

/**
 *  QTSDisposeStatHelper()
 *

 *    \non_carbon_cfm   in QTStreamLib 4.0 and later
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in// NULL if you don't want it
 *    Windows:          in QTSClient.lib 4.0 and later
 */// NULL if you don't want it
OSErr
QTSDisposeStatHelper(QTSSt// NULL if you don't want it

/**
 *  QTSStatHelperGetStats()
 *

 *    \non_carbon_cfm   in QTStreamLib 4.0 and later
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 *    Windows:          in QTSClient.lib 4.0 and later
// general statistics types 
OSErr
QTSStatHelperGetStats(QTSStatHelper inStatHelper);

/**
 *  QTSStatHelperResetIter()
 *
// statistics flags 
 *    \non_carbon_cfm   in QTStreamLib 4.0 and later
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 *    Windows:          in QTSClient.lib 4.0 and later
 */
OSErr
QTSStatHelperResetIter(QTSStatHelper inStatHelper);

// statistics atom types 
 *  QTSStatHelperNext()
 *

 *    \non_carbon_cfm   in QTS// chars only, no length or terminator 
 *    \carbon_lib        in CarbonLib 1.1 and later// OSType 
 *    \mac_os_x         in version 10.0 and later
 *    Windows:          in QTSClient.lib 4.0 and later// OSType 
 */
Boolean// chars only, no length or terminator 
QTSStatHelperNext(QTSStatHelper inStatHelper,
                  QTSStatHelperNextParams *ioParams);
// statistics data formats 
/**
 *  QTSStatHelperGetNumStats()
 *

 *    \non_carbon_cfm   in QTStreamLib 4.0 and later
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 *    Windows:          in QTSClient.lib 4.0 and later
 */
UInt32
QTSStatHelperGetNumStats(QTSStatHelper inStatHelper);

// used by components to put statistics into the atom container /**
// statistics units types 
 *

 *    \non_carbon_cfm   in QTStreamLib 4.0 and later
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 *    Windows:          in QTSClient.lib 4.0 and later
 */
// specific statistics types 
QTSGetOrMakeStatAtomForStream(QTAtomContainer inContainer, QTSStream inStream,
                              QTAtom *outParentAtom);

/**
 *  QTSInsertStatistic()
 *

 *    \non_carbon_cfm   in QTStreamLib 4.0 and later
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 *    Windows:          in QTSClient.lib 4.0 and later
 */
OSErr
QTSInsertStatistic(QTAtomContainer inContainer, QTAtom inParentAtom,
                   OSType inStatType, void *inStatData, UInt32 inStatDataLength,
                   OSType inStatDataFormat, SInt32 inFlags);

/**
 *  QTSInsertStatisticName()
 *

 *    \non_carbon_cfm   in QTStreamLib 4.0 and later
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 *    Windows:          in QTSClient.lib 4.0 and later
 */
OSErr
QTSInsertStatisticName(QTAtomContainer inContainer, QTAtom inParentAtom,
                       OSType inStatType, const char *inStatName,
                       UInt32 inStatNameLength);

/**
 *  QTSInsertStatisticUnits()
 *

 *    \non_carbon_cfm   in QTStreamLib 4.0 and later
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 *    Windows:          in QTSClient.lib 4.0 and later
 */
OSErr
QTSInsertStatisticUnits(QTAtomContainer inContainer, QTAtom inParentAtom,
                        OSType inStatType, OSType inUnitsType,
                        const char *inUnitsName, UInt32 inUnitsNameLength);

/*============================================================================
        Data Formats
============================================================================*/
/*-----------------------------------------
    Data Types
-----------------------------------------*/
// universal data types enum {
  kQTSNullDataType = FOUR_CHAR_CODE('NULL'),
  kQTSUnknownDataType = FOUR_CHAR_CODE('huh?'),
  kQTSAtomContainerDataType = FOUR_CHAR_CODE('qtac'), // QTAtomContainer   kQTSAtomDataType = FOUR_CHAR_CODE('qtat'), // QTSAtomContainerDataStruct*   kQTSAliasDataType = FOUR_CHAR_CODE('alis'),
  kQTSFileDataType = FOUR_CHAR_CODE('fspc'),     // FSSpec*   kQTSFileSpecDataType = FOUR_CHAR_CODE('fspc'), // FSSpec*   kQTSHandleDataType = FOUR_CHAR_CODE('hndl'),   // Handle*   kQTSDataRefDataType = FOUR_CHAR_CODE('dref')   // DataReferencePtr };

// these data types are specific to presentations enum {
  kQTSRTSPDataType = FOUR_CHAR_CODE('rtsp'),
  kQTSSDPDataType = FOUR_CHAR_CODE('sdp ')
};

/*-----------------------------------------
    Atom IDs
-----------------------------------------*/
enum {
  kQTSAtomType_Presentation = FOUR_CHAR_CODE('pres'),
  kQTSAtomType_PresentationHeader =
      FOUR_CHAR_CODE('phdr'), // QTSPresentationHeaderAtom   kQTSAtomType_MediaStream = FOUR_CHAR_CODE('mstr'),
  kQTSAtomType_MediaStreamHeader =
      FOUR_CHAR_CODE('mshd'), // QTSMediaStreamHeaderAtom   kQTSAtomType_MediaDescriptionText =
      FOUR_CHAR_CODE('mdes'),                      // chars, no length   kQTSAtomType_ClipRect = FOUR_CHAR_CODE('clip'),  // QTSClipRectAtom   kQTSAtomType_Duration = FOUR_CHAR_CODE('dura'),  // QTSDurationAtom   kQTSAtomType_BufferTime = FOUR_CHAR_CODE('bufr') // QTSBufferTimeAtom };

struct QTSAtomContainerDataStruct {
  QTAtomContainer container;
  QTAtom parentAtom;
};
typedef struct QTSAtomContainerDataStruct QTSAtomContainerDataStruct;
// flags for QTSPresentationHeaderAtom enum {
  kQTSPresHeaderTypeIsData = 0x00000100,
  kQTSPresHeaderDataIsHandle = 0x00000200
};
// used by components to put statistics into the atom container 
struct QTSPresentationHeaderAtom {
  SInt32 versionAndFlags;
  OSType conductorOrDataType;
  OSType dataAtomType; // where the data really is};
typedef struct QTSPresentationHeaderAtom QTSPresentationHeaderAtom;
struct QTSMediaStreamHeaderAtom {
  SInt32 versionAndFlags;
  OSType mediaTransportType;
  OSType mediaTransportDataAID; // where the data really is};
typedef struct QTSMediaStreamHeaderAtom QTSMediaStreamHeaderAtom;
struct QTSBufferTimeAtom {
  SInt32 versionAndFlags;
  Fixed bufferTime;
};
typedef struct QTSBufferTimeAtom QTSBufferTimeAtom;
struct QTSDurationAtom {
  SInt32 versionAndFlags;
  TimeScale timeScale;
  TimeValue64 duration;
};
typedef struct QTSDurationAtom QTSDurationAtom;
struct QTSClipRectAtom {
  SInt32 versionAndFlags;
  Rect clipRect;
};
typedef struct QTSClipRectAtom QTSClipRectAtom;
enum { kQTSEmptyEditStreamStartTime = -1 };

typedef UInt32 QTSStatus;
enum {
  kQTSNullStatus = 0,
  kQTSUninitializedStatus = 1,
  kQTSConnectingStatus = 2,
  kQTSOpeningConnectionDetailedStatus = 3,
  kQTSMadeConnectionDetailedStatus = 4,
  kQTSNegotiatingStatus = 5,
  kQTSGettingDescriptionDetailedStatus = 6,
  kQTSGotDescriptionDetailedStatus = 7,
  kQTSSentSetupCmdDetailedStatus = 8,
  kQTSReceivedSetupResponseDetailedStatus = 9,
  kQTSSentPlayCmdDetailedStatus = 10,
  kQTSReceivedPlayResponseDetailedStatus = 11,
  kQTSBufferingStatus = 12,
  kQTSPlayingStatus = 13,
  kQTSPausedStatus = 14,
  kQTSAutoConfiguringStatus = 15,
  kQTSDownloadingStatus = 16,
  kQTSBufferingWithTimeStatus = 17,
  kQTSWaitingDisconnectStatus = 100
};

/*-----------------------------------------
    QuickTime Preferences Types
-----------------------------------------*/
enum {
  kQTSConnectionPrefsType = FOUR_CHAR_CODE(
      'stcm'), // root atom that all other atoms are contained in  /*    kQTSNotUsedForProxyPrefsType = 'nopr',     //        comma-delimited
     list of URLs that are never used for proxies*/
  kQTSConnectionMethodPrefsType =
      FOUR_CHAR_CODE('mthd'), /*      connection method (OSType that matches one
                                 of the following three)*/
// universal data types 
      'drct'), //       used if direct connect (QTSDirectConnectPrefsRecord)  /*    kQTSRTSPProxyPrefsType =     'rtsp',   //   used if RTSP Proxy
     (QTSProxyPrefsRecord)*/
  kQTSSOCKSPrefsType = FOUR_CHAR_CODE(
      'sock') //       used if SOCKS Proxy (QTSProxyPr// QTAtomContainer 
// QTSAtomContainerDataStruct* 
enum {
  kQTSDirectConnectHTTPProtocol = FOUR_CHAR_CODE(// FSSpec* 
  kQTSDirectConnectRTSPProtocol = FOUR_CHAR_CODE(// FSSpec* 
};// Handle* 
// DataReferencePtr 
struct QTSDirectConnectPrefsRecord {
  UInt32 tcpPortID;
// these data types are specific to presentations 
};
typedef struct QTSDirectConnectPrefsRecord QTSDirectConnectPrefsRecord;
struct QTSProxyPrefsRecord {
  Str255 serverNameStr;
  UInt32 portID;
};
typedef struct QTSProxyPrefsRecord QTSProxyPrefsRecord;
#define kQTSTransAndProxyPrefsVersNum 2 // prefs atom format version enum { kConnectionActive = (1L << 0), kConnectionUseSystemPref = (1L << 1) };

struct QTSTransportPref {
  OSType protocol; // udp, http, tcp, etc  SInt32 portID;   // port to use for this connection type  UInt32 flags;    // connection flags  UInt32 seed; // seed value last time this setting was read from system prefs};
typedef struct QTSTransportPre// QTSPresentationHeaderAtom 
enum { kProxyActive = (1L << 0), kProxyUseSystemPref = (1L << 1) };

struct QTSProxyPref {// QTSMediaStreamHeaderAtom 
  UInt32 flags;  // proxy flags  SInt32 portID; // port to use for this connection type  UInt32 seed; // seed value last time this setting was read from system prefs  Str255 serverNameStr; // proxy server url};
typedef struct QTSProxyPref QTSProxyPref;// chars, no length 
enum { kNoProxyUseSystemPref = (1L << 0) };// QTSClipRectAtom 
// QTSDurationAtom 
struct QTSNoProxyPref {// QTSBufferTimeAtom 
  UInt32 flags; // no-proxy flags  UInt32 seed; // seed value last time this setting was read from system prefs  char urlList[1]; // NULL terminated, comma delimited list of urls};
typedef struct QTSNoProxyPref QTSNoProxyPref;
enum {
  kQTSTransAndProxyAtomType =
      FOUR_CHAR_CODE('strp'), // transport/proxy prefs root atom  kQTSConnectionPrefsVersion =
      FOUR_CHAR_CODE('vers'), //   prefs format version  kQTSTransportPrefsAtomType =
      FOUR_CHAR_CODE('trns'), //   tranport prefs root atom  kQTSConnectionAtomType = FOUR_CHAR_CODE(
// flags for QTSPresentationHeaderAtom 
      FOUR_CHAR_CODE('scks'), //     socks proxy settings  kQTSProxyUserInfoPrefsType =
      FOUR_CHAR_CODE('user'), //   proxy username/password root atom  kQTSDontProxyPrefsAtomType =
      FOUR_CHAR_CODE('nopr'),                    //   no-proxy prefs root atom  kQTSDontProxyDataType = FOUR_CHAR_CODE('data') //     no proxy settings};

/**
 *  QTSPrefsAddProxySetting()
 *

 *    \non_carbon_cfm  // where the data really is
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 *    Windows:          in QTSClient.lib 4.1 and later
 */
OSErr
QTSPrefsAddProxySetting(OSType p// where the data really is
                        UInt32 seed, Str255 srvrURL);

/**
 *  QTSPrefsFindProxyByType()
 *

 *    \non_carbon_cfm   in QTStreamLib 4.1 and later
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 *    Windows:          in QTSClient.lib 4.1 and later
 */
OSErr
QTSPrefsFindProxyByType(OSType proxyType, UInt32 flags, UInt32 flagsMask,
                        QTSProxyPref **proxyHndl, SInt16 *count);

/**
 *  QTSPrefsAddConnectionSetting()
 *

 *    \non_carbon_cfm   in QTStreamLib 4.1 and later
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 *    Windows:          in QTSClient.lib 4.1 and later
 */
OSErr
QTSPrefsAddConnectionSetting(OSType protocol, SInt32 portID, UInt32 flags,
                             UInt32 seed);

/**
 *  QTSPrefsFindConnectionByType()
 *

 *    \non_carbon_cfm   in QTStreamLib 4.1 and later
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 *    Windows:          in QTSClient.lib 4.1 and later
 */
OSErr
QTSPrefsFindConnectionByType(OSType protocol, UInt32 flags, UInt32 flagsMask,
                             QTSTransportPref **connectionHndl, SInt16 *count);

/**
 *  QTSPrefsGetActiveConnection()
 *

 *    \non_carbon_cfm   in QTStreamLib 4.1 and later
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 *    Windows: // root atom that all other atoms are contained in
 */
OSErr
QTSPrefsGetActiveConnection(OSType protocol, QTSTransportPref *connectInfo);

/**
 *  QTSPrefsGetNoProxyURLs()
 *//       used if direct connect (QTSDirectConnectPrefsRecord)

 *    \non_carbon_cfm   in QTStreamLib 4.1 and later
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_//       used if SOCKS Proxy (QTSProxyPrefsRecord)
 *    Windows:          in QTSClient.lib 4.1 and later
 */
OSErr
QTSPrefsGetNoProxyURLs(QTSNoProxyPref **noProxyHndl);

/**
 *  QTSPrefsSetNoProxyURLs()
 *

 *    \non_carbon_cfm   in QTStreamLib 4.1 and later
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 *    Windows:          in QTSClient.lib 4.1 and later
 */
OSErr
QTSPrefsSetNoProxyURLs(char *urls, UInt32 flags, UInt32 seed);

/**// prefs atom format version 
 *  QTSPrefsAddProxyUserInfo()
 *

 *    \non_carbon_c// udp, http, tcp, etc
 *    \carbon_lib  // port to use for this connection type
 X version 10.1 and// connection flags
 *    \mac_os_x// seed value last time this setting was read from system prefs
 *    Windows:          in QTSClient.lib 5.0.1 and later
 */
OSErr
QTSPrefsAddProxyUserInfo(OSType proxyType, SInt32 flags, SInt32 flagsMask,
                         StringPtr username, StringPtr password);
// proxy flags
/**// port to use for this connection type
 *  QTSPrefsFin// seed value last time this setting was read from system prefs
 *// proxy server url

 *    \non_carbon_cfm   in QTStreamLib 5.0.1 and later
 *    \carbon_lib        not available in CarbonLib 1.x, is available on Mac OS
 X version 10.1 and later
 *    \mac_os_x         in version 10.1 and later
 *    Windows:  // no-proxy flags
 */// seed value last time this setting was read from system prefs
OSErr// NULL terminated, comma delimited list of urls
QTSPrefsFindProxyUserInfoByType(OSType proxyType, SInt32 flags,
                                SInt32 flagsMask, StringPtr username,
                                StringPtr password);

/*============================// transport/proxy prefs root atom
        Memory Management Services
==============================//   prefs format version
/**
   These routines allocate nor//   tranport prefs root atom
   but do the correct checking, etc.
   Dispose usin//     connection prefs atom type, one for each transport type
   Call these routines for one time memory allocati//     udp transport prefs
   You do not need to set any hints to use these ca//     http transport prefs
*///     tcp transport prefs   
//   proxy prefs root atom
/**//     http proxy settings
 *  QTSNewPtr()//     rtsp proxy settings
 *
//     socks proxy settings
 *    \non_carbon_cfm   in QTStreamLib 4.0 and later
 *    \carbon_lib        in Ca//   proxy username/password root atom
 *    \mac_os_x         in version 10.0 and later
 *    Windows:          in QTSClient.lib 4.0 and //   no-proxy prefs root atom
 *///     no proxy settings
Ptr
QTSNewPtr(UInt32 inByteCount, SInt32 inFlags, SInt32 *outFlags);

/**
 *  QTSNewHandle()
 *

 *    \non_carbon_cfm   in QTStreamLib 4.0 and later
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 *    Windows:          in QTSClient.lib 4.0 and later
 */
Handle
QTSNewHandle(UInt32 inByteCount, SInt32 inFlags, SInt32 *outFlags);

#define QTSNewPtrClear(_s) QTSNewPtr((_s), kQTSMemAllocClearMem, NULL)
#define QTSNewHandleClear(_s) QTSNewHandle((_s), kQTSMemAllocClearMem, NULL)
// flags inenum {
  kQTSMemAllocClearMem = 0x00000001,
  kQTSMemAllocDontUseTempMem = 0x00000002,
  kQTSMemAllocTryTempMemFirst = 0x00000004,
  kQTSMemAllocDontUseSystemMem = 0x00000008,
  kQTSMemAllocTrySystemMemFirst = 0x00000010,
  kQTSMemAllocHoldMemory = 0x00001000,
  kQTSMemAllocIsInterruptTime =
      0x01010000 // currently not supported for alloc};

// flags outenum {
  kQTSMemAllocAllocatedInTempMem = 0x00000001,
  kQTSMemAllocAllocatedInSystemMem = 0x00000002
};

typedef struct OpaqueQTSMemPtr *QTSMemPtr;
/**
   These routines are for buffers that will be recirculated
   you must use QTReleaseMemPtr instead of DisposePtr
   QTSReleaseMemPtr can be used at interrupt time
   but QTSAllocMemPtr currently cannot
*/
/**
 *  QTSAllocMemPtr()
 *

 *    \non_carbon_cfm   in QTStreamLib 4.0 and later
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 *    Windows:          in QTSClient.lib 4.0 and later
 */
QTSMemPtr
QTSAllocMemPtr(UInt32 inByteCount, SInt32 inFlags);

/**
 *  QTSReleaseMemPtr()
 *

 *    \non_carbon_cfm   in QTStreamLib 4.0 and later
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 *    Windows:          in QTSClient.lib 4.0 and later
 */
void
QTSReleaseMemPtr(QTSMemPtr inMemPtr, SInt32 inFlags);

/*============================================================================
        Buffer Management Services
============================================================================*/

enum { kQTSStreamBufferVersion1 = 1 };

struct QTSStreamBuffer {
  struct QTSStreamBuffer *reserved1;
  struct QTSStreamBuffer *reserved2;
  struct QTSStreamBuffer *next; // next message block in a message   unsigned char *rptr; // first byte with real data in the DataBuffer   unsigned char *wptr; // last+1 byte with real data in the DataBuffer   SInt32 version;
  UInt32 metadata[4]; // usage defined by message sender   SInt32 flags;       // reserved   long reserved3;
  long reserved4;
  long reserved5;

  UInt32 moreMeta[8];
};
typedef struct QTSStreamBuffer QTSStreamBuffer;
// flags for QTSDuplicateMessageenum {
  kQTSDuplicateBufferFlag_CopyData = 0x00000001,
  kQTSDuplicateBufferFlag_FlattenMessage = 0x00000002
};

/**
 *  QTSNewStreamBuffer()
 *

 *    \non_carbon_cfm   in QTStreamLib 5.0 and later
 *    \carbon_lib        in CarbonLib 1.3 and later
 *    \mac_os_x         in version 10.0 and later
 *    Windows:          in QTSClient.lib 5.0 and later
 */
OSErr
QTSNewStreamBuffer(UInt32 inDataSize, SInt32 inFlags,
                   QTSStreamBuffer **outStreamBuffer);

/**
 *  QTSFreeMessage()
 *

 *    \non_carbon_cfm   in QTStreamLib 4.0 and later
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 *    Windows:          in QTSClient.lib 4.0 and later
 */
void
QTSFreeMessage(QTSStreamBuffer *inMessage);

/**
    kQTSDuplicateBufferFlag_CopyData - forces a copy of the data itself
    kQTSCopyBufferFlag_FlattenMessage - copies the data if it needs to be
   flattened QTSDuplicateMessage never frees the old message
*/
/**
 *  QTSDuplicateMessage()
 *

 *    \non_carbon_cfm   in QTStreamLib 5.0 and later
 *    \carbon_lib        in CarbonLib 1.3 and later
 *    \mac_os_x         in version 10.0 and later
 *    Windows:          in QTSClient.lib 5.0 and later
 */
OSErr
QTSDuplicateMessage(QTSStreamBuffer *inMessage, SInt32 inFlags,
                    QTSStreamBuffer **outDuplicatedMessage);

/**
 *  QTSMessageLength()
 *

 *    \non_carbon_cfm   in QTStreamLib 4.0 and later
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 *    Windows:          in QTSClient.lib 4.0 and later
 */
UInt32
QTSMessageLength(QTSStreamBuffer *inMessage);

/**
 *  QTSStreamBufferDataInfo()
 *

 *    \non_carbon_cfm   in QTStreamLib 5.0 and later
 *    \carbon_lib        in CarbonLib 1.3 and later
 *    \mac_os_x         in version 10.0 and later
 *    Windows:          in QTSClient.lib 5.0 and later
 */
void
QTSStreamBufferDataInfo(QTSStreamBuffer *inStreamBuffer,
                        unsigned char **outDataStart, UInt32 *outDataMaxLength);

// ---- old calls (don't use these)
/**
 *  QTSAllocBuffer()
// flags in

 *    \non_carbon_cfm   in QTStreamLib 4.0 and later
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 *    Windows:          in QTSClient.lib 4.0 and later
 */
QTSStreamBuffer *
QTSAllocBuffer(SInt32 inSize);
// currently not supported for alloc
/**
 *  QTSDupMessage()
// flags out

 *    \non_carbon_cfm   in QTStreamLib 4.0 and later
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 *    Windows:          in QTSClient.lib 4.0 and later
 */
QTSStreamBuffer *
QTSDupMessage(QTSStreamBuffer *inMessage);

/**
 *  QTSCopyMessage()
 *

 *    \non_carbon_cfm   in QTStreamLib 4.0 and later
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 *    Windows:          in QTSClient.lib 4.0 and later
 */
QTSStreamBuffer *
QTSCopyMessage(QTSStreamBuffer *inMessage);

/**
 *  QTSFlattenMessage()
 *

 *    \non_carbon_cfm   in QTStreamLib 4.0 and later
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 *    Windows:          in QTSClient.lib 4.0 and later
 */
QTSStreamBuffer *
QTSFlattenMessage(QTSStreamBuffer *inMessage);

/*============================================================================
        Misc
============================================================================*/
/**
 *  QTSGetErrorString()
 *

 *    \non_carbon_cfm   in QTStreamLib 4.0 and later
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 *    Windows:          in QTSClient.lib 4.0 and later
 */
Boolean// next message block in a message 
QTSGetErrorString(SInt3// first byte with real data in the DataBuffer 
                  char // last+1 byte with real data in the DataBuffer 

/**// usage defined by message sender 
 *  QTSInitializeMedia// reserved 
 *

 *    \non_carbon_cfm   in QTStreamLib 5.0.1 and later
 *    \carbon_lib        not available in CarbonLib 1.x, is available on Mac OS
 X version 10.1 and later
 *    \mac_os_x         in version 10.1 and later
 *    Windows:          in QTSClient.lib 5.0.1 and later
// flags for QTSDuplicateMessage
OSErr
QTSInitializeMediaParams(QTSMediaParams *inMediaParams);

// UPP call backs /**
 *  NewQTSNotificationUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        in CarbonLib 1.3 and later
 *    \mac_os_x         in version 10.0 and later
 */
QTSNotificationUPP
NewQTSNotificationUPP(QTSNotificationProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
enum {
  uppQTSNotificationProcInfo = 0x00003FF0
}; // pascal 4_bytes Func(4_bytes, 4_bytes, 4_bytes, 4_bytes) #ifdef __cplusplus
inline QTSNotificationUPP
NewQTSNotificationUPP(QTSNotificationProcPtr userRoutine) {
  return (QTSNotificationUPP)NewRoutineDescriptor((ProcPtr)(userRoutine),
                                                  uppQTSNotificationProcInfo,
                                                  GetCurrentArchitecture());
}
#else
#define NewQTSNotificationUPP(userRoutine)                                     \
  (QTSNotificationUPP)                                                         \
      NewRoutineDescriptor((ProcPtr)(userRoutine), uppQTSNotificationProcInfo, \
                           GetCurrentArchitecture())
#endif
#endif

/**
 *  NewQTSPanelFilterUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        in CarbonLib on Mac OS X
 *    \mac_os_x         in version 10.1 and later
 */
QTSPanelFilterUPP
NewQTSPanelFilterUPP(QTSPanelFilterProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
enum {
  uppQTSPanelFilterProcInfo = 0x000003D0
}; // pascal 1_byte Func(4_bytes, 4_bytes) #ifdef __cplusplus
inline QTSPanelFilterUPP
NewQTSPanelFilterUPP(QTSPanelFilterProcPtr userRoutine) {
  return (QTSPanelFilterUPP)NewRoutineDescriptor((ProcPtr)(userRoutine),
                                                 uppQTSPanelFilterProcInfo,
                                                 GetCurrentArchitecture());
}
#else
#define NewQTSPanelFilterUPP(userRoutine)                                      \
  (QTSPanelFilterUPP)                                                          \
      NewRoutineDescriptor((ProcPtr)(userRoutine), uppQTSPanelFilterProcInfo,  \
                           GetCurrentArchitecture())
#endif
#endif

/**
 *  NewQTSModalFilterUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        in CarbonLib 1.3 and later
 *    \mac_os_x         in version 10.0 and later
 */
QTSModalFilterUPP
NewQTSModalFilterUPP(QTSModalFilterProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
enum {
  uppQTSModalFilterProcInfo = 0x00003FD0
}; // pascal 1_byte Func(4_bytes, 4_bytes, 4_bytes, 4_bytes) #ifdef __cplusplus
// ---- old calls (don't use these)
NewQTSModalFilterUPP(QTSModalFilterProcPtr userRoutine) {
  return (QTSModalFilterUPP)NewRoutineDescriptor((ProcPtr)(userRoutine),
                                                 uppQTSModalFilterProcInfo,
                                                 GetCurrentArchitecture());
}
#else
#define NewQTSModalFilterUPP(userRoutine)                                      \
  (QTSModalFilterUPP)                                                          \
      NewRoutineDescriptor((ProcPtr)(userRoutine), uppQTSModalFilterProcInfo,  \
                           GetCurrentArchitecture())
#endif
#endif

/**
 *  DisposeQTSNotificationUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        in CarbonLib 1.3 and later
 *    \mac_os_x         in version 10.0 and later
 */
void
DisposeQTSNotificationUPP(QTSNotificationUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
inline void DisposeQTSNotificationUPP(QTSNotificationUPP userUPP) {
  DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
}
#else
#define DisposeQTSNotificationUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

/**
 *  DisposeQTSPanelFilterUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        in CarbonLib on Mac OS X
 *    \mac_os_x         in version 10.1 and later
 */
void
DisposeQTSPanelFilterUPP(QTSPanelFilterUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
inline void DisposeQTSPanelFilterUPP(QTSPanelFilterUPP userUPP) {
  DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
}
#else
#define DisposeQTSPanelFilterUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

/**
 *  DisposeQTSModalFilterUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        in CarbonLib 1.3 and later
 *    \mac_os_x         in version 10.0 and later
 */
void
DisposeQTSModalFilterUPP(QTSModalFilterUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
inline void DisposeQTSModalFilterUPP(QTSModalFilterUPP userUPP) {
  DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
}
#else
#define DisposeQTSModalFilterUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

/**
 *  InvokeQTSNotificationUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
// UPP call backs 
 *    \mac_os_x         in version 10.0 and later
 */
ComponentResult
InvokeQTSNotificationUPP(ComponentResult inErr, OSType inNotificationType,
                         void *inNotificationParams, void *inRefCon,
                         QTSNotificationUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
inline ComponentResult InvokeQTSNotificationUPP(ComponentResult inErr,
                                                OSType inNotificationType,
                                                void *inNotificationParams,
                                                void *inRefCon,
                                                QTSNotificationUPP userUPP) {
  r// pascal 4_bytes Func(4_bytes, 4_bytes, 4_bytes, 4_bytes) 
      userUPP, uppQTSNotificationProcInfo, inErr, inNotificationType,
      inNotificationParams, inRefCon);
}
#else
#define InvokeQTSNotificationUPP(inErr, inNotificationType,                    \
                                 inNotificationParams, inRefCon, userUPP)      \
  (ComponentResult) CALL_FOUR_PARAMETER_UPP(                                   \
      (userUPP), uppQTSNotificationProcInfo, (inErr), (inNotificationType),    \
      (inNotificationParams), (inRefCon))
#endif
#endif

/**
 *  InvokeQTSPanelFilterUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        in CarbonLib on Mac OS X
 *    \mac_os_x         in version 10.1 and later
 */
Boolean
InvokeQTSPanelFilterUPP(QTSPanelFilterParams *inParams, void *inRefCon,
                        QTSPanelFilterUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
inline Boolean InvokeQTSPanelFilterUPP(QTSPanelFilterParams *inParams,
                                       void *inRefCon,
                                       QTSPanelFilterUPP userUPP) {
  r// pascal 1_byte Func(4_bytes, 4_bytes) 
                                         inParams, inRefCon);
}
#else
#define InvokeQTSPanelFilterUPP(inParams, inRefCon, userUPP)                   \
  (Boolean) CALL_TWO_PARAMETER_UPP((userUPP), uppQTSPanelFilterProcInfo,       \
                                   (inParams), (inRefCon))
#endif
#endif

/**
 *  InvokeQTSModalFilterUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        in CarbonLib 1.3 and later
 *    \mac_os_x         in version 10.0 and later
 */
Boolean
InvokeQTSModalFilterUPP(DialogPtr inDialog, const EventRecord *inEvent,
                        SInt16 *ioItemHit, void *inRefCon,
                        QTSModalFilterUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
inline Boolean InvokeQTSModalFilterUPP(DialogPtr inDialog,
                                       const EventRecord *inEvent,
                                       SInt16 *ioItemHit, void *inRefCon,
                                       QTSModalFilterUPP userUPP) {
  return (Boolean)CALL_FOUR_PARAMETER_UPP(userUPP, uppQTSModalFilterProcInfo,
   // pascal 1_byte Func(4_bytes, 4_bytes, 4_bytes, 4_bytes) 
                                          inRefCon);
}
#else
#define InvokeQTSModalFilterUPP(inDialog, inEvent, ioItemHit, inRefCon,        \
                                userUPP)                                       \
  (Boolean)                                                                    \
      CALL_FOUR_PARAMETER_UPP((userUPP), uppQTSModalFilterProcInfo,            \
                              (inDialog), (inEvent), (ioItemHit), (inRefCon))
#endif
#endif

#if CALL_NOT_IN_CARBON || OLDROUTINENAMES
// support for pre-Carbon UPP routines: New...Proc and Call...Proc #define NewQTSNotificationProc(userRoutine) NewQTSNotificationUPP(userRoutine)
#define NewQTSPanelFilterProc(userRoutine) NewQTSPanelFilterUPP(userRoutine)
#define NewQTSModalFilterProc(userRoutine) NewQTSModalFilterUPP(userRoutine)
#define CallQTSNotificationProc(userRoutine, inErr, inNotificationType,        \
                                inNotificationParams, inRefCon)                \
  InvokeQTSNotificationUPP(inErr, inNotificationType, inNotificationParams,    \
                           inRefCon, userRoutine)
#define CallQTSPanelFilterProc(userRoutine, inParams, inRefCon)                \
  InvokeQTSPanelFilterUPP(inParams, inRefCon, userRoutine)
#define CallQTSModalFilterProc(userRoutine, inDialog, inEvent, ioItemHit,      \
                               inRefCon)                                       \
  InvokeQTSModalFilterUPP(inDialog, inEvent, ioItemHit, inRefCon, userRoutine)
#endif // CALL_NOT_IN_CARBON 
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

#endif // __QUICKTIMESTREAMING__ // support for pre-Carbon UPP routines: New...Proc and Call...Proc 
// CALL_NOT_IN_CARBON 
// __QUICKTIMESTREAMING__ 
