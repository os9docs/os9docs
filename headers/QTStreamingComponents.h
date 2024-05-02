/**
     \file       QTStreamingComponents.h

    \brief   QuickTime Interfaces.

    \introduced_in  QuickTime 5.0.1
    \avaliable_from Universal Interfaces 3.4.1

    \copyright � 1990-2001 by Apple Computer, Inc., all rights reserved

    \ingroup QuickTime

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __QTSTREAMINGCOMPONENTS__
#define __QTSTREAMINGCOMPONENTS__

#ifndef __COMPONENTS__
#include <Components.h>
#endif

#ifndef __MOVIES__
#include <Movies.h>
#endif

#ifndef __QUICKTIMESTREAMING__
#include <QuickTimeStreaming.h>
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

  /*============================================================================
          Stream Sourcer
  ============================================================================*/
  enum
  {
    kQTSSourcerType = FOUR_CHAR_CODE('srcr')
  };

  typedef ComponentInstance QTSSourcer;
  enum
  {
    kQTSSGChannelSourcerType = FOUR_CHAR_CODE('sgch'),
    kQTSMovieTrackSourcerType = FOUR_CHAR_CODE('trak'),
    kQTSPushDataSourcerType = FOUR_CHAR_CODE('push')
  };

  // flags for sourcer data   enum
  {
    kQTSSourcerDataFlag_SyncSample = 0x00000001
  };

  enum
  {
    kQTSSourcerInitParamsVersion1 = 1
  };

  struct QTSSourcerInitParams
  {
    SInt32 version;
    SInt32 flags;
    OSType dataType;
    void *data;
    UInt32 dataLength;
  };
  typedef struct QTSSourcerInitParams QTSSourcerInitParams;
  /**
   *  QTSNewSourcer()
   *
   *  Availability:
   *    \non_carbon_cfm   in QTStreamLib 5.0 and later
   *    \carbon_lib        in CarbonLib 1.3 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  QTSNewSourcer(void *params, const QTSSourcerInitParams *inInitParams,
                SInt32 inFlags, ComponentInstance *outSourcer);

  // info selectors for sourcers - get and set   enum
  // info selectors for sourcers - get and set 
    kQTSInfo_Track = FOUR_CHAR_CODE('trak'),         // QTSTrackParams*     kQTSInfo_Loop = FOUR_CHAR_CODE('loop'),          // QTSLoopParams*     kQTSInfo_SourcerTiming = FOUR_CHAR_CODE('stim'), // QTSSourcerTimingParams*     kQTSInfo_TargetFrameRate =
        FOUR_CHAR_CODE('tfps'),                 // Fixed * in frames per second     kQTSInfo_PushData = FOUR_CHAR_CODE('push'), // QTSPushDataParams*     kQTSInfo_SourcerCallbackProc =
        FOUR_CHAR_CODE('scbp'), // QTSSourcerCallback// QTSTrackParams* 
        FOUR_CHAR_CODE('tdrt'), // UInt32 * in bytes // QTSLoopParams* 
        FOUR_CHAR_CODE('agc '), // Boolean*  - error // QTSSourcerTimingParams* 
        FOUR_CHAR_CODE('gain'), // Fixed* kFixed1 is unity gain     kQTSInfo_CroppedInputRect = FOUR_CHAR_CODE(
        'crpr'), // Rect* - defined relative to // Fixed * in frames per second 
        FOUR_CHAR_CODE('sptl'), // pointer to SC// QTSPushDataParams* 
        FOUR_CHAR_CODE('tprl'), // pointer to SCTemporalSettings struct    kQTSInfo_DataRateSettings =
        FOUR_CHAR_CODE('drat'), // QTSSourcerCallbackProcParams* 
        FOUR_CHAR_CODE('ssrt'),                          // pointer to UnsignedFixed    kQTSInfo_SoundSampleSize = FOUR_CHAR_CODE('ssss'),   // pointer to short    kQTSInfo_SoundChannelCount = FOUR_CHAR_CODE('sscc'), // pointer to short    kQTSInfo_SoundCompression = FOUR_CHAR_CODE('ssct'),  // pointer to OSType    kQTSInfo_CompressionList =
        FOUR_CHAR_CODE('ctyl'), // UInt32 * in bytes per second 

  // info selectors for sourcers// Boolean*  - error if unavailable
  {
    kQTSInfo_SGChannel = FOUR_CH// Fixed* kFixed1 is unity gain 

  // loop flags  // Rect* - defined relative to kQTSInfo_FullInputRect below 
  {
    kQTSLoopFlag_Loop = 0x000000// pointer to SCSpatialSettings struct
  };
// pointer to SCTemporalSettings struct
  enum
  {// pointer to SCDataRateSettings struct
    kQTSLoopParamsVersion1 = 1// pointer to CodecFlags
  };// pointer to Handle
// pointer to long
  struct QTSLoopParams
  {// pointer to UnsignedFixed
    SInt32 version;// pointer to short
    SInt32 flags;// pointer to short
    SInt32 loopFlags;// pointer to OSType
    SInt32 flagsMask;
    SInt32 numLoops;// pointer to OSType Handle
  };// UInt16* 
  typedef struct QTSLoopParams QTSLoopParams;// UInt16* 
  enum// UInt16* 
  {// UInt16* 
    kQTSTrackParamsVersion1 = 1// UInt16* 
  };// UInt32* 

  struct QTSTrackParams
  // info selectors for sourcers - get only
    SInt32 version;
    SInt32 flags;
    Track track;// SGChannel* 
    TimeValue64 trackStartOffset; /* to start other tha// Handle* 
                                     otherwise set to 0// Handle* 
    TimeValue64 duration;         // to limit the durat// Rect* 
        *loopParams; // set to NULL if not using; default is no looping   };
  typedef struct QTSTrackParams QTSTrackParams;
  // loop flags 
  {
    kQTSSourcerTimingParamsVersion1 = 1
  };

  struct QTSSourcerTimingParams
  {
    SInt32 version;
    SInt32 flags;
    TimeScale timeScale;
    TimeValue64 presentationStartTime;
    TimeValue64 presentationEndTime;
    TimeValue64 presentationCurrentTime;
    TimeValue64 localStartTime;
    TimeValue64 localEndTime;
    TimeValue64 localCurrentTime;
  };
  typedef struct QTSSourcerTimingParams QTSSourcerTimingParams;
  enum
  {
    kQTSPushDataParamsVersion1 = 1
  };

  enum
  {
    kQTSPushDataFlag_SampleTimeIsValid = 0x00000001,
    kQTSPushDataFlag_DurationIsValid = 0x00000002
  };

  struct QTSPushDataParams
  {
    SInt32 version;
    SInt32 flags;// to limit the duration otherwise set to 0
    SampleDescriptionHandle sampleDescription; // caller owns the handle     UInt32 sampleDescSeed;
    TimeValue64 sampl// set to NULL if not using; default is no looping 
    void *dataPtr; // this does not have to be a real macintosh Ptr   };
  typedef struct QTSPushDataParams QTSPushDataParams;
  enum
  {
    kQTSSourcerCallbackProcParamsVersion1 = 1
  };

  struct QTSSourcerCallbackProcParams
  {
    SInt32 version;
    SInt32 flags;
    QTSNotificationUPP proc;
    void *refCon;
  };
  typedef struct QTSSourcerCallbackProcParams QTSSourcerCallbackProcParams;
  // track sourcer callback selectors  enum
  {
    kQTSSourcerCallback_Done = FOUR_CHAR_CODE('done') // QTSSourcerDoneParams*   };

  // push data sourcer callback selectors  enum
  {
    kQTSPushDataSourcerCallback_HasCharacteristic =
        0x050D,                                   // QTSPushDataHasCharacteristicParams*     kQTSPushDataSourcerCallback_SetInfo = 0x0507, // QTSPushDataInfoParams*     kQTSPushDataSourcerCallback_GetInfo = 0x0508  // QTSPushDataInfoParams*   };

  struct QTSPushDataHasCharacteristicParams
  {
    SInt32 version;
    SInt32 flags;
    OSType characteristic;
    Boolean returnedHasIt;
    char reserved[3];
  };
  typedef struct QTSPushDataHasCharacteristicParams
      QTSPushDataHasCharacteristicParams;
  struct QTSPushDataInfoParams
  {// caller owns the handle 
    SInt32 version;
    SInt32 flags;// also set flag if you set this 
    OSType selector;// also set flag if you set this 
    void *ioParams;
  };// this does not have to be a real macintosh Ptr 
  typedef struct QTSPushDataInfoParams QTSPushDataInfoParams;
  enum
  {
    kQTSSourcerDoneParamsVersion1 = 1
  };

  struct QTSSourcerDoneParams
  {
    SInt32 version;
    SInt32 flags;
    ComponentInstance sourcer;
  };
  typedef struct QTSSourcerDoneParams QTSSourcerDoneParams;

  /*-----------------------------------------
  // track sourcer callback selectors
  -----------------------------------------*/
  enum
  {// QTSSourcerDoneParams* 
    kQTSSourcerInitializeSelect = 0x0500,
    kQTSSourcerSetEnableSelect = 0x0503,
  // push data sourcer callback selectors
    kQTSSourcerSetInfoSelect = 0x0507,
    kQTSSourcerGetInfoSelect = 0x0508,
    kQTSSourcerSetTimeScaleSelect = 0x050E,
    kQTSSourcerGetTimeScaleSelect = 0x050F,// QTSPushDataHasCharacteristicParams* 
    kQTSSourcerIdleSelect = 0x0516// QTSPushDataInfoParams* 
  };// QTSPushDataInfoParams* 

  /*-----------------------------------------
      Stream Sourcer Prototypes
  -----------------------------------------*/
  /**
   *  QTSSourcerInitialize()
   *
   *  Availability:
   *    \non_carbon_cfm   in QTStreamLib 5.0.1 and later
   *    \carbon_lib        not available in CarbonLib 1.x, is available on Mac OS
   * X version 10.1 and later \mac_os_x         in version 10.1 and later
   */
  ComponentResult
  QTSSourcerInitialize(QTSSourcer inSourcer,
                       const QTSSourcerInitParams *inInitParams)
      FIVEWORDINLINE(0x2F3C, 0x0004, 0x0500, 0x7000, 0xA82A);

  /**
   *  QTSSourcerIdle()
   *
   *  Availability:
   *    \non_carbon_cfm   in QTStreamLib 5.0 and later
   *    \carbon_lib        in CarbonLib 1.3 and later
   *    \mac_os_x         in version 10.0 and later
   */
  ComponentResult
  QTSSourcerIdle(QTSSourcer inSourcer, const TimeValue64 *inTime, SInt32 inFlags,
                 SInt32 *outFlags)
      FIVEWORDINLINE(0x2F3C, 0x000C, 0x0516, 0x7000, 0xA82A);

  /**
   *  QTSSourcerSetEnable()
   *
   *  Availability:
   *    \non_carbon_cfm   in QTStreamLib 5.0 and later
   *    \carbon_lib        in CarbonLib 1.3 and later
   *    \mac_os_x         in version 10.0 and later
   */
  ComponentResult
  QTSSourcerSetEnable(QTSSourcer inSourcer, Boolean inEnableMode, SInt32 inFlags)
      FIVEWORDINLINE(0x2F3C, 0x0006, 0x0503, 0x7000, 0xA82A);

  /**
   *  QTSSourcerGetEnable()
   *
   *  Availability:
   *    \non_carbon_cfm   in QTStreamLib 5.0 and later
   *    \carbon_lib        in CarbonLib 1.3 and later
   *    \mac_os_x         in version 10.0 and later
   */
  ComponentResult
  QTSSourcerGetEnable(QTSSourcer inSourcer, Boolean *outEnableMode,
                      SInt32 inFlags)
      FIVEWORDINLINE(0x2F3C, 0x0008, 0x0504, 0x7000, 0xA82A);

  /**
   *  QTSSourcerSetTimeScale()
   *
   *  Availability:
   *    \non_carbon_cfm   in QTStreamLib 5.0 and later
   *    \carbon_lib        in CarbonLib 1.3 and later
   *    \mac_os_x         in version 10.0 and later
   */
  ComponentResult
  QTSSourcerSetTimeScale(QTSSourcer inSourcer, TimeScale inTimeScale)
      FIVEWORDINLINE(0x2F3C, 0x0004, 0x050E, 0x7000, 0xA82A);

  /**
   *  QTSSourcerGetTimeScale()
   *
   *  Availability:
   *    \non_carbon_cfm   in QTStreamLib 5.0 and later
   *    \carbon_lib        in CarbonLib 1.3 and later
   *    \mac_os_x         in version 10.0 and later
   */
  ComponentResult
  QTSSourcerGetTimeScale(QTSSourcer inSourcer, TimeScale *outTimeScale)
      FIVEWORDINLINE(0x2F3C, 0x0004, 0x050F, 0x7000, 0xA82A);

  /**
   *  QTSSourcerSetInfo()
   *
   *  Availability:
   *    \non_carbon_cfm   in QTStreamLib 5.0 and later
   *    \carbon_lib        in CarbonLib 1.3 and later
   *    \mac_os_x         in version 10.0 and later
   */
  ComponentResult
  QTSSourcerSetInfo(QTSSourcer inSourcer, OSType inSelector, void *ioParams)
      FIVEWORDINLINE(0x2F3C, 0x0008, 0x0507, 0x7000, 0xA82A);

  /**
   *  QTSSourcerGetInfo()
   *
   *  Availability:
   *    \non_carbon_cfm   in QTStreamLib 5.0 and later
   *    \carbon_lib        in CarbonLib 1.3 and later
   *    \mac_os_x         in version 10.0 and later
   */
  ComponentResult
  QTSSourcerGetInfo(QTSSourcer inSourcer, OSType inSelector, void *ioParams)
      FIVEWORDINLINE(0x2F3C, 0x0008, 0x0508, 0x7000, 0xA82A);

  /*============================================================================
          Stream Handler
  ============================================================================*/

  /**
      Server edits are only valid for the current chunk
  */
  struct SHServerEditParameters
  {
    UInt32 version;
    Fixed editRate;
    TimeValue64 dataStartTime_mediaAxis;
    TimeValue64 dataEndTime_mediaAxis;
  };
  typedef struct SHServerEditParameters SHServerEditParameters;
  enum
  {
    kSHNoChunkDispatchFlags = 0,
    kSHChunkFlagSyncSample = 1 << 2,
    kSHChunkFlagDataLoss = 1 << 4
  };

  struct SHChunkRecord
  {
    UInt32 version;
    long reserved1;
    SInt32 flags;
    UInt32 dataSize;
    UInt8 *dataPtr;
    long reserved2;
    long reserved3;
    TimeValue64 presentationTime;

    long reserved4;
    long reserved5;
    const SHServerEditParameters *serverEditParameters;
    long reserved6;
    long reserved7;
  };
  typedef struct SHChunkRecord SHChunkRecord;

  /*============================================================================
          RTP Components
  ============================================================================*/

  typedef UInt32 RTPSSRC;
  enum
  {
    kRTPInvalidSSRC = 0
  };

  // RTP standard content encodings for audio   enum
  {
    kRTPPayload_PCMU = 0,       // 8kHz PCM mu-law mono     kRTPPayload_1016 = 1,       // 8kHz CELP (Fed Std 1016) mono     kRTPPayload_G721 = 2,       // 8kHz G.721 ADPCM mono     kRTPPayload_GSM = 3,        // 8kHz GSM mono     kRTPPayload_G723 = 4,       // 8kHz G.723 ADPCM mono     kRTPPayload_DVI_8 = 5,      // 8kHz Intel DVI ADPCM mono     kRTPPayload_DVI_16 = 6,     // 16kHz Intel DVI ADPCM mono     kRTPPayload_LPC = 7,        // 8kHz LPC     kRTPPayload_PCMA = 8,       // 8kHz PCM a-law mono     kRTPPayload_L16_44_2 = 10,  // 44.1kHz 16-bit linear stereo     kRTPPayload_L16_44_1 = 11,  // 44.1kHz 16-bit linear mono     kRTPPayload_PureVoice = 12, // 8kHz PureVoice mono (QCELP)     kRTPPayload_MPEGAUDIO = 14, // MPEG I and II audio     kRTPPayload_DVI_11 = 16,    // 11kHz Intel DVI ADPCM mono     kRTPPayload_DVI_22 = 17     // 22kHz Intel DVI ADPCM mono   };

  // RTP standard content encodings for video   enum
  {
    kRTPPayload_CELLB = 25,     // Sun CellB     kRTPPayload_JPEG = 26,      // JPEG     kRTPPayload_CUSEEME = 27,   // Cornell CU-SeeMe     kRTPPayload_NV = 28,        // Xerox PARC nv     kRTPPayload_PICWIN = 29,    // BBN Picture Window     kRTPPayload_CPV = 30,       // Bolter CPV     kRTPPayload_H261 = 31,      // CCITT H.261     kRTPPayload_MPEGVIDEO = 32, // MPEG I and II video     kRTPPayload_H263 = 34       // CCITT H.263   };

  // Other RTP standard content encodings   enum
  {
    kRTPPayload_MPEG2T = 33 // MPEG 2 Transport   };

  // Dynamic encodings   enum
  {
    kRTPPayload_FirstDynamic = 96,
    kRTPPayload_LastDynamic = 127,
    kRTPPayload_Unknown = 0xFF
  };

  /**
  -----------------------------------------
      RTP Info selectors
  -----------------------------------------
  */
  // ----- these are get and set -----   enum
  {
    kRTPInfo_SSRC = FOUR_CHAR_CODE('ssrc'),      // UInt32*     kRTPInfo_NextSeqNum = FOUR_CHAR_CODE('rnsn') // UInt16*   };

  /*-----------------------------------------
      RTP Statistics
  -----------------------------------------*/
  enum
  {
    kRTPTotalReceivedPktsStat = FOUR_CHAR_CODE('trcp'),
    kRTPTotalLostPktsStat = FOUR_CHAR_CODE('tlsp'),
    kRTPTotalProcessedPktsStat = FOUR_CHAR_CODE('tprp'),
    kRTPTotalDroppedPktsStat = FOUR_CHAR_CODE('tdrp'),
    kRTPBadHeaderDroppedPktsStat = FOUR_CHAR_CODE('bhdp'),
    kRTPOurHeaderDroppedPktsStat = FOUR_CHAR_CODE('ohdp'),
    kRTPNotReceivingSenderDroppedPktsStat = FOUR_CHAR_CODE('nsdp'),
    kRTPNotProcessingDroppedPktsStat = FOUR_CHAR_CODE('npdp'),
    kRTPBadSeqDroppedPktsStat = FOUR_CHAR_CODE('bsdp'),
    kRTPArriveTooLatePktsStat = FOUR_CHAR_CODE('artl'),
    kRTPWaitForSeqDroppedPktsStat = FOUR_CHAR_CODE('wsdp'),
    kRTPBadStateDroppedPktsStat = FOUR_CHAR_CODE('stdp'),
    kRTPBadPayloadDroppedPktsStat = FOUR_CHAR_CODE('bpdp'),
    kRTPNoTimeScaleDroppedPktsStat = FOUR_CHAR_CODE('ntdp'),
  // RTP standard content encodings for audio 
    kRTPLostPktsPercentStat = FOUR_CHAR_CODE('lspp'),
    kRTPDroppedPktsPercentStat = FOUR_CHAR_CODE('dppp'),
    kRTPTotalUnprocessedPktsPerc// 8kHz PCM mu-law mono 
    kRTPRTCPDataRateStat = FOUR_// 8kHz CELP (Fed Std 1016) mono 
    kRTPPayloadIDStat = FOUR_CHA// 8kHz G.721 ADPCM mono 
    kRTPPayloadNameStat = FOUR_C// 8kHz GSM mono 
    kRTPNumPktsInQueueStat = FOU// 8kHz G.723 ADPCM mono 
    kRTPTotalPktsInQueueStat = F// 8kHz Intel DVI ADPCM mono 
    kRTPTotalOutOfOrderPktsStat // 16kHz Intel DVI ADPCM mono 
    kRTPRetransmissionStat = FOU// 8kHz LPC 
  };// 8kHz PCM a-law mono 
// 44.1kHz 16-bit linear stereo 
  /*----------------------------// 44.1kHz 16-bit linear mono 
      Payload Info// 8kHz PureVoice mono (QCELP) 
  ------------------------------// MPEG I and II audio 
  enum// 11kHz Intel DVI ADPCM mono 
  {// 22kHz Intel DVI ADPCM mono 
    kRTPPayloadSpeedTag = FOUR_CHAR_CODE('sped'), // 0-255, 255 is fastest    kRTPPayloadLossRecoveryTag =
        FOUR_CHAR_CODE('loss') /* 0-255, 0 can't handle any loss, 128 can handle
  // RTP standard content encodings for video 
  };

  struct RTPPayloadCharacteristi// Sun CellB 
  {// JPEG 
    OSType tag;// Cornell CU-SeeMe 
    long value;// Xerox PARC nv 
  };// BBN Picture Window 
  typedef struct RTPPayloadChara// Bolter CPV 
  /**// CCITT H.261 
      pass RTPPayloadSortRequest// MPEG I and II video 
     QTSFindMediaPacketizerForTr// CCITT H.263 
     key to sort on. value is positive for ascending sort (low value first),
     negative for descending sort (high value first).
  // Other RTP standard content encodings 
  struct RTPPayloadSortRequest
  {
    long characteristicCount// MPEG 2 Transport 
    RTPPayloadCharacteristic
        characteristic[1]; /* tag is key to sort on, value is + for ascending, -
  // Dynamic encodings 
  };
  typedef struct RTPPayloadSortRequest RTPPayloadSortRequest;
  typedef RTPPayloadSortRequest *RTPPayloadSortRequestPtr;
  // flags for RTPPayloadInfo   enum
  {
    kRTPPayloadTypeStaticFlag = 0x00000001,
    kRTPPayloadTypeDynamicFlag = 0x00000002
  };

  struct RTPPayloadInfo
  {
    long payloadFlags;
  // ----- these are get and set ----- 
    char unused[3];
    char payloadName[1];
  };// UInt32* 
  typedef struct RTPPayloadInfo RTPPayloadInfo;// UInt16* 
  typedef RTPPayloadInfo *RTPPayloadInfoPtr;
  typedef RTPPayloadInfoPtr *RTPPayloadInfoHandle;
  /*============================================================================
          RTP Reassembler
  ============================================================================*/
  typedef ComponentInstance RTPReassembler;
  enum
  {
    kRTPReassemblerType = FOUR_CHAR_CODE('rtpr')
  };

  enum
  {
    kRTPBaseReassemblerType = FOUR_CHAR_CODE('gnrc'),
    kRTP261ReassemblerType = FOUR_CHAR_CODE('h261'),
    kRTP263ReassemblerType = FOUR_CHAR_CODE('h263'),
    kRTP263PlusReassemblerType = FOUR_CHAR_CODE('263+'),
    kRTPAudioReassemblerType = FOUR_CHAR_CODE('soun'),
    kRTPQTReassemblerType = FOUR_CHAR_CODE('qtim'),
    kRTPPureVoiceReassemblerType = FOUR_CHAR_CODE('Qclp'),
    kRTPMp3ReassemblerType = FOUR_CHAR_CODE('mp3 '),
    kRTPJPEGReassemblerType = FOUR_CHAR_CODE('jpeg'),
    kRTPQDesign2ReassemblerType = FOUR_CHAR_CODE('QDM2'),
    kRTPSorensonReassemblerType = FOUR_CHAR_CODE('SVQ1')
  };

  struct RTPRssmInitParams
  {
    RTPSSRC ssrc;
    UInt8 payloadType;
    UInt8 pad[3];
    TimeBase timeBase;
    TimeScale timeScale;
  };
  typedef struct RTPRssmInitParams RTPRssmInitParams;
  struct RTPRssmPacket
  {
    struct RTPRssmPacket *next;
    struct RTPRssmPacket *prev;
    QTSStreamBuffer *streamBuffer;// 0-255, 255 is fastest
    Boolean paramsFilledIn;
    UInt8 pad[1];
    UInt16 sequenceNum;
    UInt32 transportHeaderLength; // filled in by base    UInt32 payloadHeaderLength;   // derived adjusts this     UInt32 dataLength;
    SHServerEditParameters serverEditParams;
    TimeValue64 timeStamp; // lower 32 bits is original rtp timestamp    SInt32 chunkFlags;     // these are or'd together    SInt32 flags;
  };
  typedef struct RTPRssmPacket RTPRssmPacket;
  // flags for RTPRssmPacket struct  enum
  {
    kRTPRssmPacketHasMarkerBitSet = 0x00000001,
    kRTPRssmPacketHasServerEditFlag = 0x00010000
  };

  // flags for RTPRssmSendStreamBufferRange  enum
  {
    kRTPRssmCanRefStreamBuffer = 0x00000001
  };

  // flags for RTPRssmSendPacketList  enum
  {
    kRTPRssmLostSomePackets = 0x00000001
  };

  // flags for RTPRssmSetFlags  enum
  {
  // flags for RTPPayloadInfo 
    kRTPRssmQueueAndUseMarkerBitFlag = 0x00000002,
    kRTPRssmTrackLostPacketsFlag = 0x00010000,
    kRTPRssmNoReorderingRequiredFlag = 0x00020000
  };

  struct RTPSendStreamBufferRangeParams
  {
    QTSStreamBuffer *streamBuffer;
    TimeValue64 presentationTime;
    UInt32 chunkStartPosition;
    UInt32 numDataBytes;
    SInt32 chunkFlags;
    SInt32 flags;
    const SHServerEditParameters *serverEditParams; // NULL if no edit  };
  typedef struct RTPSendStreamBufferRangeParams RTPSendStreamBufferRangeParams;
  // characteristics  enum
  {
    kRTPCharacteristic_RequiresOrderedPackets = FOUR_CHAR_CODE('rrop'),
    kRTPCharacteristic_TimeStampsNotMonoIncreasing = FOUR_CHAR_CODE('tsmi')
  };

  enum
  {
    kRTPReassemblerInfoResType = FOUR_CHAR_CODE('rsmi')
  };

  struct RTPReassemblerInfo
  {
    long characteristicCount;
    RTPPayloadCharacteristic characteristic[1];

    /* after the last characteristic, the payload name (defined by the
     * MediaPacketizerPayloadInfo*/
    // structure) is present.   };
  typedef struct RTPReassemblerInfo RTPReassemblerInfo;
  typedef RTPReassemblerInfo *RTPReassemblerInfoPtr;
  typedef RTPReassemblerInfoPtr *RTPReassemblerInfoHandle;
#define RTPReassemblerInfoToPayloadInfo(_rsmi) \
  ((RTPPayloadInfoPtr)(&(                      \
      (_rsmi)->characteristic[(_rsmi)->characteristicCount])))
  // RTPReassemblerInfoElement structs are padded to 32 bits   enum
  {
    kRTPReassemblerInfoPadUpToBytes = 4
  };

  /**
   *  QTSFindReassemblerForPayloadID()
   *
   *  Availability:
   *    \non_carbon_cfm   in QTStreamLib 4.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in QTSClient.lib 4.0 and later
   */
  OSErr
  QTSFindReassemblerForPayloadID(UInt8 inPayloadID,
                                 RTPPayloadSortRequest *inSortInfo,
                                 Q// filled in by base
// derived adjusts this 
  /**
   *  QTSFindReassemblerForPayloadName()
   *// lower 32 bits is original rtp timestamp
   *  Availability:// these are or'd together
   *    \non_carbon_cfm   in QTStreamLib 4.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
  // flags for RTPRssmPacket struct
   */
  OSErr
  QTSFindReassemblerForPayloadName(const char *inPayloadName,
                                   RTPPayloadSortRequest *inSortInfo,
                                   QTAtomContainer *outReassemblerList);

  // flags for RTPRssmSendStreamBufferRange
      RTP Reassembler Selectors
  -----------------------------------------*/
  enum
  {
    kRTPRssmSetCapabilitiesSelect = 0x0100,
  // flags for RTPRssmSendPacketList
    kRTPRssmSetPayloadHeaderLengthSelect = 0x0102,
    kRTPRssmGetPayloadHeaderLengthSelect = 0x0103,
    kRTPRssmSetTimeScaleSelect = 0x0104,
    kRTPRssmGetTimeScaleSelect = 0x0105,
    kRTPRssmNewStreamHandlerSelect = 0x0106,
  // flags for RTPRssmSetFlags
    kRTPRssmGetStreamHandlerSelect = 0x0108,
    kRTPRssmSendStreamHandlerChangedSelect = 0x0109,
    kRTPRssmSetSampleDescriptionSelect = 0x010A,
    kRTPRssmGetChunkAndIncrRefCountSelect = 0x010D,
    kRTPRssmSendChunkAndDecrRefCountSelect = 0x010E,
    kRTPRssmSendLostChunkSelect = 0x010F,
    kRTPRssmSendStreamBufferRangeSelect = 0x0110,
    kRTPRssmClearCachedPackets = 0x0111,
    kRTPRssmFillPacketListParamsSelect = 0x0113,
    kRTPRssmReleasePacketListSelect = 0x0114,
    kRTPRssmIncrChunkRefCountSelect = 0x0115,
    kRTPRssmDecrChunkRefCountSelect = 0x0116,
    kRTPRssmInitializeSelect = 0x0500,
    kRTPRssmHandleNewPacketSelect = 0x0501,
    kRTPRssmComputeChunkSizeSelect = 0x0502,
    kRTPRssmAdjustPacketParamsSelect = 0x0503,
    kRTPRssmCopyDataToChunkSelect = 0x0504,// NULL if no edit
    kRTPRssmSendPacketListSelect = 0x0505,
    kRTPRssmGetTimeScaleFromPacketSelect = 0x0506,
  // characteristics
    kRTPRssmGetInfoSelect = 0x050A,
    kRTPRssmHasCharacteristicSelect = 0x050B,
    kRTPRssmResetSelect = 0x050C
  };

  /*-----------------------------------------
      RTP Reassembler functions - base to derived
  -----------------------------------------*/

  /**
   *  RTPRssmInitialize()
   *
   *  Availability:
   *    \non_carbon_cfm   in QTStreamLib 4.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in QTSClient.lib 4.0 and later
   */
  Co// structure) is present. 
  RTPRssmInitialize(RTPReassembler rtpr, RTPRssmInitParams *inInitParams)
      FIVEWORDINLINE(0x2F3C, 0x0004, 0x0500, 0x7000, 0xA82A);

  /**
   *  RTPRssmHandleNewPacket()
   *
   *  Availability:
  // RTPReassemblerInfoElement structs are padded to 32 bits 
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in QTSClient.lib 4.0 and later
   */
  ComponentResult
  RTPRssmHandleNewPacket(RTPReassembler rtpr, QTSStreamBuffer *inStreamBuffer,
                         SInt32 inNumWraparounds)
      FIVEWORDINLINE(0x2F3C, 0x0008, 0x0501, 0x7000, 0xA82A);

  /**
   *  RTPRssmComputeChunkSize()
   *
   *  Availability:
   *    \non_carbon_cfm   in QTStreamLib 4.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in QTSClient.lib 4.0 and later
   */
  ComponentResult
  RTPRssmComputeChunkSize(RTPReassembler rtpr, RTPRssmPacket *inPacketListHead,
                          SInt32 inFlags, UInt32 *outChunkDataSize)
      FIVEWORDINLINE(0x2F3C, 0x000C, 0x0502, 0x7000, 0xA82A);

  /**
   *  RTPRssmAdjustPacketParams()
   *
   *  Availability:
   *    \non_carbon_cfm   in QTStreamLib 4.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in QTSClient.lib 4.0 and later
   */
  ComponentResult
  RTPRssmAdjustPacketParams(RTPReassembler rtpr, RTPRssmPacket *inPacket,
                            SInt32 inFlags)
      FIVEWORDINLINE(0x2F3C, 0x0008, 0x0503, 0x7000, 0xA82A);

  /**
   *  RTPRssmCopyDataToChunk()
   *
   *  Availability:
   *    \non_carbon_cfm   in QTStreamLib 4.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in QTSClient.lib 4.0 and later
   */
  ComponentResult
  RTPRssmCopyDataToChunk(RTPReassembler rtpr, RTPRssmPacket *inPacketListHead,
                         UInt32 inMaxChunkDataSize, SHChunkRecord *inChunk,
                         SInt32 inFlags)
      FIVEWORDINLINE(0x2F3C, 0x0010, 0x0504, 0x7000, 0xA82A);

  /**
   *  RTPRssmSendPacketList()
   *
   *  Availability:
   *    \non_carbon_cfm   in QTStreamLib 4.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in QTSClient.lib 4.0 and later
   */
  ComponentResult
  RTPRssmSendPacketList(RTPReassembler rtpr, RTPRssmPacket *inPacketListHead,
                        const TimeValue64 *inLastChunkPresentationTime,
                        SInt32 inFlags)
      FIVEWORDINLINE(0x2F3C, 0x000C, 0x0505, 0x7000, 0xA82A);

  /**
   *  RTPRssmGetTimeScaleFromPacket()
   *
   *  Availability:
   *    \non_carbon_cfm   in QTStreamLib 4.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in QTSClient.lib 4.0 and later
   */
  ComponentResult
  RTPRssmGetTimeScaleFromPacket(RTPReassembler rtpr,
                                QTSStreamBuffer *inStreamBuffer,
                                TimeScale *outTimeScale)
      FIVEWORDINLINE(0x2F3C, 0x0008, 0x0506, 0x7000, 0xA82A);

  /**
   *  RTPRssmSetInfo()
   *
   *  Availability:
   *    \non_carbon_cfm   in QTStreamLib 4.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in QTSClient.lib 4.0 and later
   */
  ComponentResult
  RTPRssmSetInfo(RTPReassembler rtpr, OSType inSelector, void *ioParams)
      FIVEWORDINLINE(0x2F3C, 0x0008, 0x0509, 0x7000, 0xA82A);

  /**
   *  RTPRssmGetInfo()
   *
   *  Availability:
   *    \non_carbon_cfm   in QTStreamLib 4.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in QTSClient.lib 4.0 and later
   */
  ComponentResult
  RTPRssmGetInfo(RTPReassembler rtpr, OSType inSelector, void *ioParams)
      FIVEWORDINLINE(0x2F3C, 0x0008, 0x050A, 0x7000, 0xA82A);

  /**
   *  RTPRssmHasCharacteristic()
   *
   *  Availability:
   *    \non_carbon_cfm   in QTStreamLib 4.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in QTSClient.lib 4.0 and later
   */
  ComponentResult
  RTPRssmHasCharacteristic(RTPReassembler rtpr, OSType inCharacteristic,
                           Boolean *outHasIt)
      FIVEWORDINLINE(0x2F3C, 0x0008, 0x050B, 0x7000, 0xA82A);

  /**
   *  RTPRssmReset()
   *
   *  Availability:
   *    \non_carbon_cfm   in QTStreamLib 4.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in QTSClient.lib 4.0 and later
   */
  ComponentResult
  RTPRssmReset(RTPReassembler rtpr, SInt32 inFlags)
      FIVEWORDINLINE(0x2F3C, 0x0004, 0x050C, 0x7000, 0xA82A);

  /*-----------------------------------------
      RTP Reassembler functions - derived to base
  -----------------------------------------*/
  // ----- setup  /**
   *  RTPRssmSetCapabilities()
   *
   *  Availability:
   *    \non_carbon_cfm   in QTStreamLib 4.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in QTSClient.lib 4.0 and later
   */
  ComponentResult
  RTPRssmSetCapabilities(RTPReassembler rtpr, SInt32 inFlags, SInt32 inFlagsMask)
      FIVEWORDINLINE(0x2F3C, 0x0008, 0x0100, 0x7000, 0xA82A);

  /**
   *  RTPRssmGetCapabilities()
   *
   *  Availability:
   *    \non_carbon_cfm   in QTStreamLib 4.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in QTSClient.lib 4.0 and later
   */
  ComponentResult
  RTPRssmGetCapabilities(RTPReassembler rtpr, SInt32 *outFlags)
      FIVEWORDINLINE(0x2F3C, 0x0004, 0x0101, 0x7000, 0xA82A);

  /**
   *  RTPRssmSetPayloadHeaderLength()
   *
   *  Availability:
   *    \non_carbon_cfm   in QTStreamLib 4.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in QTSClient.lib 4.0 and later
   */
  ComponentResult
  RTPRssmSetPayloadHeaderLength(RTPReassembler rtpr, UInt32 inPayloadHeaderLength)
      FIVEWORDINLINE(0x2F3C, 0x0004, 0x0102, 0x7000, 0xA82A);

  /**
   *  RTPRssmGetPayloadHeaderLength()
   *
   *  Availability:
   *    \non_carbon_cfm   in QTStreamLib 4.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in QTSClient.lib 4.0 and later
   */
  ComponentResult
  RTPRssmGetPayloadHeaderLength(RTPReassembler rtpr,
                                UInt32 *outPayloadHeaderLength)
      FIVEWORDINLINE(0x2F3C, 0x0004, 0x0103, 0x7000, 0xA82A);

  /**
   *  RTPRssmSetTimeScale()
   *
   *  Availability:
   *    \non_carbon_cfm   in QTStreamLib 4.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in QTSClient.lib 4.0 and later
   */
  ComponentResult
  RTPRssmSetTimeScale(RTPReassembler rtpr, TimeScale inSHTimeScale)
      FIVEWORDINLINE(0x2F3C, 0x0004, 0x0104, 0x7000, 0xA82A);

  /**
   *  RTPRssmGetTimeScale()
   *
   *  Availability:
   *    \non_carbon_cfm   in QTStreamLib 4.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in QTSClient.lib 4.0 and later
   */
  ComponentResult
  RTPRssmGetTimeScale(RTPReassembler rtpr, TimeScale *outSHTimeScale)
      FIVEWORDINLINE(0x2F3C, 0x0004, 0x0105, 0x7000, 0xA82A);

  /**
   *  RTPRssmNewStreamHandler()
   *
   *  Availability:
   *    \non_carbon_cfm   in QTStreamLib 4.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in QTSClient.lib 4.0 and later
   */
  ComponentResult
  RTPRssmNewStreamHandler(RTPReassembler rtpr, OSType inSHType,
                          SampleDescriptionHandle inSampleDescription,
                          TimeScale inSHTimeScale, ComponentInstance *outHandler)
      FIVEWORDINLINE(0x2F3C, 0x0010, 0x0106, 0x7000, 0xA82A);
// ----- setup
  /**
   *  RTPRssmSetStreamHandler()
   *
   *  Availability:
   *    \non_carbon_cfm   in QTStreamLib 4.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in QTSClient.lib 4.0 and later
   */
  ComponentResult
  RTPRssmSetStreamHandler(RTPReassembler rtpr, ComponentInstance inStreamHandler)
      FIVEWORDINLINE(0x2F3C, 0x0004, 0x0107, 0x7000, 0xA82A);

  /**
   *  RTPRssmGetStreamHandler()
   *
   *  Availability:
   *    \non_carbon_cfm   in QTStreamLib 4.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in QTSClient.lib 4.0 and later
   */
  ComponentResult
  RTPRssmGetStreamHandler(RTPReassembler rtpr,
                          ComponentInstance *outStreamHandler)
      FIVEWORDINLINE(0x2F3C, 0x0004, 0x0108, 0x7000, 0xA82A);

  /**
   *  RTPRssmSendStreamHandlerChanged()
   *
   *  Availability:
   *    \non_carbon_cfm   in QTStreamLib 4.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in QTSClient.lib 4.0 and later
   */
  ComponentResult
  RTPRssmSendStreamHandlerChanged(RTPReassembler rtpr)
      FIVEWORDINLINE(0x2F3C, 0x0000, 0x0109, 0x7000, 0xA82A);

  /**
   *  RTPRssmSetSampleDescription()
   *
   *  Availability:
   *    \non_carbon_cfm   in QTStreamLib 4.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in QTSClient.lib 4.0 and later
   */
  ComponentResult
  RTPRssmSetSampleDescription(RTPReassembler rtpr,
                              SampleDescriptionHandle inSampleDescription)
      FIVEWORDINLINE(0x2F3C, 0x0004, 0x010A, 0x7000, 0xA82A);

  // ----- manually sending chunks  /**
   *  RTPRssmGetChunkAndIncrRefCount()
   *
   *  Availability:
   *    \non_carbon_cfm   in QTStreamLib 4.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in QTSClient.lib 4.0 and later
   */
  ComponentResult
  RTPRssmGetChunkAndIncrRefCount(RTPReassembler rtpr, UInt32 inChunkDataSize,
                                 const TimeValue64 *inChunkPresentationTime,
                                 SHChunkRecord **outChunk)
      FIVEWORDINLINE(0x2F3C, 0x000C, 0x010D, 0x7000, 0xA82A);

  /**
   *  RTPRssmSendChunkAndDecrRefCount()
   *
   *  Availability:
   *    \non_carbon_cfm   in QTStreamLib 4.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in QTSClient.lib 4.0 and later
   */
  ComponentResult
  RTPRssmSendChunkAndDecrRefCount(RTPReassembler rtpr, SHChunkRecord *inChunk,
                                  const SHServerEditParameters *inServerEdit)
      FIVEWORDINLINE(0x2F3C, 0x0008, 0x010E, 0x7000, 0xA82A);

  /**
   *  RTPRssmSendLostChunk()
   *
   *  Availability:
   *    \non_carbon_cfm   in QTStreamLib 4.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in QTSClient.lib 4.0 and later
   */
  ComponentResult
  RTPRssmSendLostChunk(RTPReassembler rtpr,
                       const TimeValue64 *inChunkPresentationTime)
      FIVEWORDINLINE(0x2F3C, 0x0004, 0x010F, 0x7000, 0xA82A);

  /**
   *  RTPRssmSendStreamBufferRange()
   *
   *  Availability:
   *    \non_carbon_cfm   in QTStreamLib 4.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in QTSClient.lib 4.0 and later
   */
  ComponentResult
  RTPRssmSendStreamBufferRange(RTPReassembler rtpr,
                               RTPSendStreamBufferRangeParams *inParams)
      FIVEWORDINLINE(0x2F3C, 0x0004, 0x0110, 0x7000, 0xA82A);

  /**
   *  RTPRssmClearCachedPackets()
   *
   *  Availability:
   *    \non_carbon_cfm   in QTStreamLib 4.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in QTSClient.lib 4.0 and later
   */
  ComponentResult
  RTPRssmClearCachedPackets(RTPReassembler rtpr, SInt32 inFlags)
      FIVEWORDINLINE(0x2F3C, 0x0004, 0x0111, 0x7000, 0xA82A);

  /**
   *  RTPRssmFillPacketListParams()
   *
   *  Availability:
   *    \non_carbon_cfm   in QTStreamLib 4.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in QTSClient.lib 4.0 and later
   */
  ComponentResult
  RTPRssmFillPacketListParams(RTPReassembler rtpr,
                              RTPRssmPacket *inPacketListHead,
                              SInt32 inNumWraparounds, SInt32 inFlags)
      FIVEWORDINLINE(0x2F3C, 0x000C, 0x0113, 0x7000, 0xA82A);

  /**
   *  RTPRssmReleasePacketList()
   *
   *  Availability:
   *    \non_carbon_cfm   in QTStreamLib 4.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in QTSClient.lib 4.0 and later
   */
  // ----- manually sending chunks
  RTPRssmReleasePacketList(RTPReassembler rtpr, RTPRssmPacket *inPacketListHead)
      FIVEWORDINLINE(0x2F3C, 0x0004, 0x0114, 0x7000, 0xA82A);

  /**
   *  RTPRssmIncrChunkRefCount()
   *
   *  Availability:
   *    \non_carbon_cfm   in QTStreamLib 4.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in QTSClient.lib 4.0 and later
   */
  ComponentResult
  RTPRssmIncrChunkRefCount(RTPReassembler rtpr, SHChunkRecord *inChunk)
      FIVEWORDINLINE(0x2F3C, 0x0004, 0x0115, 0x7000, 0xA82A);

  /**
   *  RTPRssmDecrChunkRefCount()
   *
   *  Availability:
   *    \non_carbon_cfm   in QTStreamLib 4.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in QTSClient.lib 4.0 and later
   */
  ComponentResult
  RTPRssmDecrChunkRefCount(RTPReassembler rtpr, SHChunkRecord *inChunk)
      FIVEWORDINLINE(0x2F3C, 0x0004, 0x0116, 0x7000, 0xA82A);

  /*============================================================================
          RTP Media Packetizer
  ============================================================================*/
  enum
  {
    kRTPMediaPacketizerType = FOUR_CHAR_CODE('rtpm')
  };

  typedef ComponentInstance RTPMediaPacketizer;
  enum
  {
    kRTPBaseMediaPacketizerType = FOUR_CHAR_CODE('gnrc'),
    kRTP261MediaPacketizerType = FOUR_CHAR_CODE('h261'),
    kRTP263PlusMediaPacketizerType = FOUR_CHAR_CODE('263+'),
    kRTPAudioMediaPacketizerType = FOUR_CHAR_CODE('soun'),
    kRTPQTMediaPacketizerType = FOUR_CHAR_CODE('qtim'),
    kRTPPureVoiceMediaPacketizerType = FOUR_CHAR_CODE('Qclp'),
    kRTPMp3MediaPacketizerType = FOUR_CHAR_CODE('mp3 '),
    kRTPJPEGMediaPacketizerType = FOUR_CHAR_CODE('jpeg'),
    kRTPQDesign2MediaPacketizerType = FOUR_CHAR_CODE('QDM2'),
    kRTPSorensonMediaPacketizerType = FOUR_CHAR_CODE('SVQ1')
  };

  typedef UInt32 RTPMPSampleRef;
  typedef CALLBACK_API(void, RTPMPDataReleaseProcPtr)(UInt8 *inData,
                                                      void *inRefCon);
  typedef STACK_UPP_TYPE(RTPMPDataReleaseProcPtr) RTPMPDataReleaseUPP;
  enum
  {
    kMediaPacketizerCanPackEditRate = 1 << 0,
    kMediaPacketizerCanPackLayer = 1 << 1,
    kMediaPacketizerCanPackVolume = 1 << 2,
    kMediaPacketizerCanPackBalance = 1 << 3,
    kMediaPacketizerCanPackGraphicsMode = 1 << 4,
    kMediaPacketizerCanPackEmptyEdit = 1 << 5
  };

  struct MediaPacketizerRequirements
  {
    OSType mediaType;  // media type supported (0 for all)    OSType dataFormat; // data format (e.g., compression) supported (0 for all)    UInt32
        capabilityFlags;     // ability to handle non-standard track characteristics    UInt8 canPackMatrixType; /* can pack any matrix type up to this
                                (identityMatrixType for identity only)*/
    UInt8 pad[3];
  };
  typedef struct MediaPacketizerRequirements MediaPacketizerRequirements;
  typedef MediaPacketizerRequirements *MediaPacketizerRequirementsPtr;
  struct MediaPacketizerInfo
  {
    OSType mediaType;  // media type supported (0 for all)    OSType dataFormat; // data format (e.g., compression) supported (0 for all)    OSType vendor;     // manufacturer of this packetizer (e.g., 'appl' for Apple)    UInt32
        capabilityFlags;     // ability to handle non-standard track characteristics    UInt8 canPackMatrixType; /* can pack any matrix type up to this
                                (identityMatrixType for identity only)*/
    UInt8 pad[3];
    long characteristicCount;
    RTPPayloadCharacteristic characteristic[1];

    /* after the last characteristic, the payload name (defined by the
     * RTPPayloadInfo*/
    // structure) is present.   };
  typedef struct MediaPacketizerInfo MediaPacketizerInfo;
  typedef MediaPacketizerInfo *MediaPacketizerInfoPtr;
  typedef MediaPacketizerInfoPtr *MediaPacketizerInfoHandle;
#define MediaPacketizerInfoToPayloadInfo(_mpi) \
  ((RTPPayloadInfoPtr)(&((_mpi)->characteristic[(_mpi)->characteristicCount])))
  // MediaPacketizerInfo structs are padded to 32 bits   enum
  {
    kMediaPacketizerInfoPadUpToBytes = 4
  };

  /**
   *  QTSFindMediaPacketizer()
   *
   *  Availability:
   *    \non_carbon_cfm   in QTStreamLib 4.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in QTSClient.lib 4.0 and later
   */
  OSErr
  QTSFindMediaPacketizer(MediaPacketizerRequirementsPtr inPacketizerinfo,
                         SampleDescriptionHandle inSampleDescription,
                         RTPPayloadSortRequestPtr inSortInfo,
                         QTAtomContainer *outPacketizerList);

  /**
   *  QTSFindMediaPacketizerForTrack()
   *
   *  Availability:
   *    \non_carbon_cfm   in QTStreamLib 4.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in QTSClient.lib 4.0 and later
   */
  OSErr
  QTSFindMediaPacketizerForTrack(Track inTrack, long inSampleDescriptionIndex,
                                 RTPPayloadSortRequestPtr inSortInfo,
                                 QTAtomContainer *outPacketizerList);

  /**
   *  QTSFindMediaPacketizerForPayloadID()
   *
   *  Availability:
   *    \non_carbon_cfm   in QTStreamLib 4.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in QTSClient.lib 4.0 and later
   */
  OSErr
  QTSFindMediaPacketizerForPayloadID(long payloadID,
                                     RTPPayloadSortRequestPtr inSortInfo,
                                     QTAtomContainer *outPacketizerList);

  /**
   *  QTSFindMediaPacketizerForPayloadName()
   *
   *  Availability:
   *    \non_carbon_cfm   in QTStreamLib 4.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in QTSClient.lib 4.0 and later
   */
  OSErr
  QTSFindMediaPacketizerForPayloadName(const char *payloadName,
                                       RTPPayloadSortRequestPtr inSortInfo,
                                       QTAtomContainer *outPacketizerList);

  // flags for RTPMPInitialize  enum
  {
    kRTPMPRealtimeModeFlag = 0x00000001
  };

  // flags for RTPMPSampleDataParams  enum
  {
    kRTPMPSyncSampleFlag = 0x00000001,
    kRTPMPRespectDurationFlag = 0x00000002
  };// media type supported (0 for all)
// data format (e.g., compression) supported (0 for all)
  struct RTPMPSampleDataParams
  {// ability to handle non-standard track characteristics
    UInt32 version;
    UInt32 timeStamp;
    UInt32 duration; // 0 = unknown duration    UInt32 playOffset;
    Fixed playRate;
    SInt32 flags;
    UInt32 sampleDescSeed;
    Handle sampleDescription;
    RTPMPSampleRef sampleRef;
    UInt32 dataLength;// media type supported (0 for all)
    const UInt8 *data;// data format (e.g., compression) supported (0 for all)
    RTPMPDataReleaseUPP// manufacturer of this packetizer (e.g., 'appl' for Apple)
    void *refCon;
  };// ability to handle non-standard track characteristics
  typedef struct RTPMPSampleDataParams RTPMPSampleDataParams;
  // out flags for idle, RTPMPSetSampleData, and RTPMPFlush  enum
  {
    kRTPMPStillProcessingData = 0x00000001 // not done with data you've got  };

  struct RTPMPPayloadTypeParams
  {
    UInt32 flags;
    // structure) is present. 
    short nameLength;  /* in: size of payloadName buffer (counting null terminator)
                          -- this will be reset to needed length and paramErr
                          returned if too small */
    char *payloadName; // caller must provide buffer   };
  typedef struct RTPMPPayloadTypeParams RTPMPPayloadTypeParams;
  /*-----------------------------------------
  // MediaPacketizerInfo structs are padded to 32 bits 
  -----------------------------------------*/
  // info selectors - get only   enum
  {
    kRTPMPPayloadTypeInfo = FOUR_CHAR_CODE('rtpp'),  // RTPMPPayloadTypeParams*     kRTPMPRTPTimeScaleInfo = FOUR_CHAR_CODE('rtpt'), // TimeScale*     kRTPMPRequiredSampleDescriptionInfo =
        FOUR_CHAR_CODE('sdsc'), // SampleDescriptionHandle*     kRTPMPMinPayloadSize = FOUR_CHAR_CODE(
        'mins'), // UInt32* in bytes, does not include rtp header; default is 0     kRTPMPMinPacketDuration = FOUR_CHAR_CODE(
        'mind'),                                                // UInt3* in milliseconds; default is no min required     kRTPMPSuggestedRepeatPktCountInfo = FOUR_CHAR_CODE('srpc'), // UInt32*     kRTPMPSuggestedRepeatPktSpacingInfo =
        FOUR_CHAR_CODE('srps'), // UInt32* in milliseconds     kRTPMPMaxPartialSampleSizeInfo =
        FOUR_CHAR_CODE('mpss'), // UInt32* in bytes     kRTPMPPreferredBufferDelayInfo =
        FOUR_CHAR_CODE('prbd'),                    // UInt32* in milliseconds     kRTPMPPayloadNameInfo = FOUR_CHAR_CODE('name') // StringPtr   };

  /*-----------------------------------------
      RTP Media Packetizer Characteristics
  -----------------------------------------*/
  // also supports relevant ones in Movies.h and QTSToolbox.h   enum
  {
    kRTPMPNoSampleDataRequiredCharacteristic = FOUR_CHAR_CODE('nsdr'),
    kRTPMPHasUserSettingsDialogCharacteristic = FOUR_CHAR_CODE('sdlg'),
    kRTPMPPrefersReliableTransportCharacteristic = FOUR_CHAR_CODE('rely'),
    kRTPMPRequiresOutOfBandDimensionsCharacteristic = FOUR_CHAR_CODE('robd'),
    kRTPMPReadsPartialSamplesCharacteristic = FOUR_CHAR_CODE('rpsp')
  };

  /*-----------------------------------------
      RTP Media Packetizer selectors
  -----------------------------------------*/
  enum
  {
    kRTPMPInitializeSelect = 0x0500,
    kRTPMPPreflightMediaSelect = 0x0501,
    kRTPMPIdleSelect = 0x0502,
    kRTPMPSetSampleDataSelect = 0x0503,
    kRTPMPFlushSelect = 0x0504,
    kRTPMPResetSelect = 0x0505,
    kRTPMPSetInfoSelect = 0x0506,
    kRTPMPGetInfoSelect = 0x0507,
    kRTPMPSetTimeScaleSelect = 0x0508,
    kRTPMPGetTimeScaleSelect = 0x0509,
    kRTPMPSetTimeBaseSelect = 0x050A,
    kRTPMPGetTimeBaseSelect = 0x050B,
    kRTPMPHasCharacteristicSelect = 0x050C,
    kRTPMPSetPacketBuilderSelect = 0x050E,
    kRTPMPGetPacketBuilderSelect = 0x050F,
    kRTPMPSetMediaTypeSelect = 0x0510,
    kRTPMPGetMediaTypeSelect = 0x0511,
    kRTPMPSetMaxPacketSizeSelect = 0x0512,
    kRTPMPGetMaxPacketSizeSelect = 0x0513,
    kRTPMPSetMaxPacketDurationSelect = 0x0514,
    kRTPMPGetMaxPacketDurationSelect =
        0x0515, // for export component and apps who want to                // access dialogs for Media-specific settings                // (such as Pure Voice interleave factor)    kRTPMPDoUserDialogSelect = 0x0516,
    kRTPMPSetSettingsFromAtomContainerAtAtomSelect = 0x0517,
    kRTPMPGetSettingsIntoAtomContainerAtAtomSelect = 0x0518,
    kRTPMPGetSettingsAsTextSelect = 0x0519,
    kRTPMPGetSettingsSelect = 0x051A,
    kRTPMPSetSettingsSelect = 0x051B
  };

  /*-----------------------------------------
      RTP Media Packetizer functions
  -----------------------------------------*/

  /**
  // flags for RTPMPInitialize
   *
   *  Availability:
   *    \non_carbon_cfm   in QTStreamLib 4.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
  // flags for RTPMPSampleDataParams
   */
  ComponentResult
  RTPMPInitialize(RTPMediaPacketizer rtpm, SInt32 inFlags)
      FIVEWORDINLINE(0x2F3C, 0x0004, 0x0500, 0x7000, 0xA82A);

  // return noErr if you can handle this media   /**
   *  RTPMPPreflightMedia()
   *
   *  Availability:
   *    \non_carbon_cfm   in QTStreamLib 4.0 and later
   *    \carbon_lib  // 0 = unknown duration
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in QTSClient.lib 4.0 and later
   */
  ComponentResult
  RTPMPPreflightMedia(RTPMediaPacketizer rtpm, OSType inMediaType,
                      SampleDescriptionHandle inSampleDescription)
      FIVEWORDINLINE(0x2F3C, 0x0008, 0x0501, 0x7000, 0xA82A);

  /**
     do work here if you need to - give up time periodically
     if you're doing time consuming operations
  */
  // out flags for idle, RTPMPSetSampleData, and RTPMPFlush
   *  RTPMPIdle()
   *
   *  Availability:// not done with data you've got
   *    \non_carbon_cfm   in QTStreamLib 4.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in QTSClient.lib 4.0 and later
   */
  ComponentResult
  RTPMPIdle(RTPMediaPacketizer rtpm, SInt32 inFlags, SInt32 *outFlags)
      FIVEWORDINLINE(0x2F3C, 0x0008, 0x0502, 0x7000, 0xA82A);

  /**// caller must provide buffer 
     caller owns the RTPMPSampleDataParams struct
     media Packetizer must copy any fields of the struct it wants to keep
     media Packetizer must call release proc when done with the data
     you can do the processing work here if it does not take up too
     much cpu time - otherwise do it in idle
  // info selectors - get only 
  /**
   *  RTPMPSetSampleData()
   *// RTPMPPayloadTypeParams* 
   *  Availability:// TimeScale* 
   *    \non_carbon_cfm   in QTStreamLib 4.0 and later
   *    \carbon_lib        in Ca// SampleDescriptionHandle* 
   *    \mac_os_x         in version 10.0 and later
   *    Windows: // UInt32* in bytes, does not include rtp header; default is 0 
   */
  ComponentResult// UInt3* in milliseconds; default is no min required 
  RTPMPSetSampleData(RTPMediaPacketizer rtpm,// UInt32* 
                     const RTPMPSampleDataParams *inSampleData, SInt32 *outFlags)
      FIVEWORDINLINE(0x2F3C, 0x0// UInt32* in milliseconds 

  /**// UInt32* in bytes 
     send everything you have buffered - you will get idles while
     you set the kRTPMPStillProcessingData flag her// UInt32* in milliseconds 
  */// StringPtr 
  /**
   *  RTPMPFlush()
   *
   *  Availability:
   *    \non_carbon_cfm   in QTStreamLib 4.0 and later
  // also supports relevant ones in Movies.h and QTSToolbox.h 
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in QTSClient.lib 4.0 and later
   */
  ComponentResult
  RTPMPFlush(RTPMediaPacketizer rtpm, SInt32 inFlags, SInt32 *outFlags)
      FIVEWORDINLINE(0x2F3C, 0x0008, 0x0504, 0x7000, 0xA82A);

  /**
     dispose of anything buffered and get rid of state
     do not send the buffered data (because presumably
     there is no connection for you to send on)
     state should be the same as if you were just initialized
  */
  /**
   *  RTPMPReset()
   *
   *  Availability:
   *    \non_carbon_cfm   in QTStreamLib 4.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in QTSClient.lib 4.0 and later
   */
  ComponentResult
  RTPMPReset(RTPMediaPacketizer rtpm, SInt32 inFlags)
      FIVEWORDINLINE(0x2F3C, 0x0004, 0x0505, 0x7000, 0xA82A);

  /*-----------------------------------------
      RTP Media Packetizer get / set functions
  -----------------------------------------*/
  /**
   *  RTPMPSetInfo()
   *
   *  Availability:
   *    \non_carbon_cfm   in QTStreamLib 4.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_// for export component and apps who want to
   *    Windows:// access dialogs for Media-specific settings
   */// (such as Pure Voice interleave factor)
  ComponentResult
  RTPMPSetInfo(RTPMediaPacketizer rtpm, OSType inSelector, const void *ioParams)
      FIVEWORDINLINE(0x2F3C, 0x0008, 0x0506, 0x7000, 0xA82A);

  /**
   *  RTPMPGetInfo()
   *
   *  Availability:
   *    \non_carbon_cfm   in QTStreamLib 4.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in QTSClient.lib 4.0 and later
   */
  ComponentResult
  RTPMPGetInfo(RTPMediaPacketizer rtpm, OSType inSelector, void *ioParams)
      FIVEWORDINLINE(0x2F3C, 0x0008, 0x0507, 0x7000, 0xA82A);

  /**
   *  RTPMPSetTimeScale()
   *
   *  Availability:
   *    \non_carbon_cfm   in QTStreamLib 4.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in QTSClient.lib 4.0 and later
  // return noErr if you can handle this media 
  ComponentResult
  RTPMPSetTimeScale(RTPMediaPacketizer rtpm, TimeScale inTimeScale)
      FIVEWORDINLINE(0x2F3C, 0x0004, 0x0508, 0x7000, 0xA82A);

  /**
   *  RTPMPGetTimeScale()
   *
   *  Availability:
   *    \non_carbon_cfm   in QTStreamLib 4.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in QTSClient.lib 4.0 and later
   */
  ComponentResult
  RTPMPGetTimeScale(RTPMediaPacketizer rtpm, TimeScale *outTimeScale)
      FIVEWORDINLINE(0x2F3C, 0x0004, 0x0509, 0x7000, 0xA82A);

  /**
   *  RTPMPSetTimeBase()
   *
   *  Availability:
   *    \non_carbon_cfm   in QTStreamLib 4.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in QTSClient.lib 4.0 and later
   */
  ComponentResult
  RTPMPSetTimeBase(RTPMediaPacketizer rtpm, TimeBase inTimeBase)
      FIVEWORDINLINE(0x2F3C, 0x0004, 0x050A, 0x7000, 0xA82A);

  /**
   *  RTPMPGetTimeBase()
   *
   *  Availability:
   *    \non_carbon_cfm   in QTStreamLib 4.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in QTSClient.lib 4.0 and later
   */
  ComponentResult
  RTPMPGetTimeBase(RTPMediaPacketizer rtpm, TimeBase *outTimeBase)
      FIVEWORDINLINE(0x2F3C, 0x0004, 0x050B, 0x7000, 0xA82A);

  /**
   *  RTPMPHasCharacteristic()
   *
   *  Availability:
   *    \non_carbon_cfm   in QTStreamLib 4.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in QTSClient.lib 4.0 and later
   */
  ComponentResult
  RTPMPHasCharacteristic(RTPMediaPacketizer rtpm, OSType inSelector,
                         Boolean *outHasIt)
      FIVEWORDINLINE(0x2F3C, 0x0008, 0x050C, 0x7000, 0xA82A);

  /**
   *  RTPMPSetPacketBuilder()
   *
   *  Availability:
   *    \non_carbon_cfm   in QTStreamLib 4.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in QTSClient.lib 4.0 and later
   */
  ComponentResult
  RTPMPSetPacketBuilder(RTPMediaPacketizer rtpm,
                        ComponentInstance inPacketBuilder)
      FIVEWORDINLINE(0x2F3C, 0x0004, 0x050E, 0x7000, 0xA82A);

  /**
   *  RTPMPGetPacketBuilder()
   *
   *  Availability:
   *    \non_carbon_cfm   in QTStreamLib 4.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in QTSClient.lib 4.0 and later
   */
  ComponentResult
  RTPMPGetPacketBuilder(RTPMediaPacketizer rtpm,
                        ComponentInstance *outPacketBuilder)
      FIVEWORDINLINE(0x2F3C, 0x0004, 0x050F, 0x7000, 0xA82A);

  /**
   *  RTPMPSetMediaType()
   *
   *  Availability:
   *    \non_carbon_cfm   in QTStreamLib 4.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in QTSClient.lib 4.0 and later
   */
  ComponentResult
  RTPMPSetMediaType(RTPMediaPacketizer rtpm, OSType inMediaType)
      FIVEWORDINLINE(0x2F3C, 0x0004, 0x0510, 0x7000, 0xA82A);

  /**
   *  RTPMPGetMediaType()
   *
   *  Availability:
   *    \non_carbon_cfm   in QTStreamLib 4.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in QTSClient.lib 4.0 and later
   */
  ComponentResult
  RTPMPGetMediaType(RTPMediaPacketizer rtpm, OSType *outMediaType)
      FIVEWORDINLINE(0x2F3C, 0x0004, 0x0511, 0x7000, 0xA82A);

  // size is in bytes  /**
   *  RTPMPSetMaxPacketSize()
   *
   *  Availability:
   *    \non_carbon_cfm   in QTStreamLib 4.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in QTSClient.lib 4.0 and later
   */
  ComponentResult
  RTPMPSetMaxPacketSize(RTPMediaPacketizer rtpm, UInt32 inMaxPacketSize)
      FIVEWORDINLINE(0x2F3C, 0x0004, 0x0512, 0x7000, 0xA82A);

  /**
   *  RTPMPGetMaxPacketSize()
   *
   *  Availability:
   *    \non_carbon_cfm   in QTStreamLib 4.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in QTSClient.lib 4.0 and later
   */
  ComponentResult
  RTPMPGetMaxPacketSize(RTPMediaPacketizer rtpm, UInt32 *outMaxPacketSize)
      FIVEWORDINLINE(0x2F3C, 0x0004, 0x0513, 0x7000, 0xA82A);

  // duration is in milliseconds  /**
   *  RTPMPSetMaxPacketDuration()
   *
   *  Availability:
   *    \non_carbon_cfm   in QTStreamLib 4.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in QTSClient.lib 4.0 and later
   */
  ComponentResult
  RTPMPSetMaxPacketDuration(RTPMediaPacketizer rtpm, UInt32 inMaxPacketDuration)
      FIVEWORDINLINE(0x2F3C, 0x0004, 0x0514, 0x7000, 0xA82A);

  /**
   *  RTPMPGetMaxPacketDuration()
   *
   *  Availability:
   *    \non_carbon_cfm   in QTStreamLib 4.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in QTSClient.lib 4.0 and later
   */
  ComponentResult
  RTPMPGetMaxPacketDuration(RTPMediaPacketizer rtpm, UInt32 *outMaxPacketDuration)
      FIVEWORDINLINE(0x2F3C, 0x0004, 0x0515, 0x7000, 0xA82A);

  /**
   *  RTPMPDoUserDialog()
   *
   *  Availability:
   *    \non_carbon_cfm   in QTStreamLib 4.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in QTSClient.lib 4.0 and later
   */
  ComponentResult
  RTPMPDoUserDialog(RTPMediaPacketizer rtpm, ModalFilterUPP inFilterUPP,
                    Boolean *canceled)
      FIVEWORDINLINE(0x2F3C, 0x0008, 0x0516, 0x7000, 0xA82A);

  /**
   *  RTPMPSetSettingsFromAtomContainerAtAtom()
   *
   *  Availability:
   *    \non_carbon_cfm   in QTStreamLib 4.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in QTSClient.lib 4.0 and later
   */
  ComponentResult
  RTPMPSetSettingsFromAtomContainerAtAtom(RTPMediaPacketizer rtpm,
                                          QTAtomContainer inContainer,
                                          QTAtom inParentAtom)
      FIVEWORDINLINE(0x2F3C, 0x0008, 0x0517, 0x7000, 0xA82A);

  /**
   *  RTPMPGetSettingsIntoAtomContainerAtAtom()
   *
   *  Availability:
   *    \non_carbon_cfm   in QTStreamLib 4.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in QTSClient.lib 4.0 and later
   */
  ComponentResult
  RTPMPGetSettingsIntoAtomContainerAtAtom(RTPMediaPacketizer rtpm,
                                          QTAtomContainer inOutContainer,
                                          QTAtom inParentAtom)
      FIVEWORDINLINE(0x2F3C, 0x0008, 0x0518, 0x7000, 0xA82A);

  /**
   *  RTPMPGetSettingsAsText()
   *
   *  Availability:
   *    \non_carbon_cfm   in QTStreamLib 4.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in QTSClient.lib 4.0 and later
   */
  ComponentResult
  RTPMPGetSettingsAsText(RTPMediaPacketizer rtpm, Handle *text)
      FIVEWORDINLINE(0x2F3C, 0x0004, 0x0519, 0x7000, 0xA82A);

  /**
   *  RTPMPGetSettings()
   *
   *  Availability:
   *    \non_carbon_cfm   in QTStreamLib 5.0 and later
   *    \carbon_lib        in CarbonLib 1.3 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in QTSClient.lib 5.0 and later
   */
  ComponentResult
  RTPMPGetSettings(RTPMediaPacketizer rtpm, QTAtomContainer *outSettings,
                   SInt32 inFlags)
      FIVEWORDINLINE(0x2F3C, 0x0008, 0x051A, 0x7000, 0xA82A);

  /**
   *  RTPMPSetSettings()
   *
  // size is in bytes
   *    \non_carbon_cfm   in QTStreamLib 5.0 and later
   *    \carbon_lib        in CarbonLib 1.3 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in QTSClient.lib 5.0 and later
   */
  ComponentResult
  RTPMPSetSettings(RTPMediaPacketizer rtpm, QTAtomSpecPtr inSettings,
                   SInt32 inFlags)
      FIVEWORDINLINE(0x2F3C, 0x0008, 0x051B, 0x7000, 0xA82A);

  /*============================================================================
          RTP Packet Builder
  ============================================================================*/
  enum
  {
    kRTPPacketBuilderType = FOUR_CHAR_CODE('rtpb')
  };

  typedef ComponentInstance RTPPacketBuilder;
  typedef struct OpaqueRTPPacketGroupRef *RTPPacketGroupRef;
  typedef struct OpaqueRTPPacketRef *RTPPacketRef;
  typedef struct OpaqueRTPPacketRepeatedDataRef *RTPPacketRepeatedDataRef;
  // flags for RTPPBBegin/EndPacket, RTPPBBegin/EndPacketGroup  enum
  {
    kRTPPBSetMarkerFlag = 0x00000001,
    kRTPPBRepeatPacketFlag = 0x00000002,
  // duration is in milliseconds
    kRTPPBBFrameFlag = 0x00020000,
    kRTPPBDontSendFlag =
        0x10000000 // when set in EndPacketGroup, will not add group  };

  enum
  {
    kRTPPBUnknownPacketMediaDataLength = 0
  };

  // flags for RTPPBGetSampleData  enum
  {
    kRTPPBEndOfDataFlag = 0x00000001
  };

  typedef CALLBACK_API(void, RTPPBCallbackProcPtr)(OSType inSelector,
                                                   void *ioParams,
                                                   void *inRefCon);
  typedef STACK_UPP_TYPE(RTPPBCallbackProcPtr) RTPPBCallbackUPP;
  /*-----------------------------------------
      RTP Packet Builder selectors
  -----------------------------------------*/
  enum
  {
    kRTPPBBeginPacketGroupSelect = 0x0500,
    kRTPPBEndPacketGroupSelect = 0x0501,
    kRTPPBBeginPacketSelect = 0x0502,
    kRTPPBEndPacketSelect = 0x0503,
    kRTPPBAddPacketLiteralDataSelect = 0x0504,
    kRTPPBAddPacketSampleDataSelect = 0x0505,
    kRTPPBAddPacketRepeatedDataSelect = 0x0506,
    kRTPPBReleaseRepeatedDataSelect = 0x0507,
    kRTPPBSetPacketSequenceNumberSelect = 0x0508,
    kRTPPBGetPacketSequenceNumberSelect = 0x0509,
    kRTPPBSetCallbackSelect = 0x050A,
    kRTPPBGetCallbackSelect = 0x050B,
    kRTPPBSetInfoSelect = 0x050C,
    kRTPPBGetInfoSelect = 0x050D,
    kRTPPBSetPacketTimeStampOffsetSelect = 0x050E,
    kRTPPBGetPacketTimeStampOffsetSelect = 0x050F,
    kRTPPBAddPacketSampleData64Select = 0x0510,
    kRTPPBGetSampleDataSelect = 0x0511,
    kRTPPBAddRepeatPacketSelect = 0x0512
  };

  /*-----------------------------------------
      RTP Packet Builder functions
  -----------------------------------------*/
  /**
   *  RTPPBBeginPacketGroup()
   *
   *  Availability:
   *    \non_carbon_cfm   in QTStreamLib 4.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in QTSClient.lib 4.0 and later
   */
  ComponentResult
  RTPPBBeginPacketGroup(RTPPacketBuilder rtpb, SInt32 inFlags, UInt32 inTimeStamp,
                        RTPPacketGroupRef *outPacketGroup)
      FIVEWORDINLINE(0x2F3C, 0x000C, 0x0500, 0x7000, 0xA82A);

  /**
   *  RTPPBEndPacketGroup()
   *
   *  Availability:
   *    \non_carbon_cfm   in QTStreamLib 4.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in QTSClient.lib 4.0 and later
   */
  ComponentResult
  RTPPBEndPacketGroup(RTPPacketBuilder rtpb, SInt32 inFlags,
                      RTPPacketGroupRef inPacketGroup)
      FIVEWORDINLINE(0x2F3C, 0x0008, 0x0501, 0x7000, 0xA82A);

  /**
   *  RTPPBBeginPacket()
   *
   *  Availability:
   *    \non_carbon_cfm   in QTStreamLib 4.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in QTSClient.lib 4.0 and later
   */
  ComponentResult
  RTPPBBeginPacket(RTPPacketBuilder rtpb, SInt32 inFlags,
                   RTPPacketGroupRef inPacketGroup,
                   UInt32 inPacketMediaDataLength, RTPPacketRef *outPacket)
      FIVEWORDINLINE(0x2F3C, 0x0010, 0x0502, 0x7000, 0xA82A);

  /**
   *  RTPPBEndPacket()
   *
   *  Availability:
   *    \non_carbon_cfm   in QTStreamLib 4.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in QTSClient.lib 4.0 and later
   */
  ComponentResult
  RTPPBEndPacket(RTPPacketBuilder rtpb, SInt32 inFlags,
                 RTPPacketGroupRef inPacketGroup, RTPPacketRef inPacket,
                 UInt32 inTransmissionTimeOffset, UInt32 inDuration)
      FIVEWORDINLINE(0x2F3C, 0x0014, 0x0503, 0x7000, 0xA82A);

  /**
     non-NULL RTPPacketRepeatedDataRef means this data will be repeated later
     pb must return a repeated data ref
  */
  /**
   *  RTPPBAddPacketLiteralData()
   *
   *  Availability:
   *    \non_carbon_cfm   in QTStreamLib 4.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in QTSClient.lib 4.0 and later
   */
  ComponentResult
  RTPPBAddPacketLiteralData(RTPPacketBuilder rtpb, SInt32 inFlags,
                            RTPPacketGroupRef inPacketGroup,
                            RTPPacketRef inPacket, UInt8 *inData,
                            UInt32 inDataLength,
  // flags for RTPPBBegin/EndPacket, RTPPBBegin/EndPacketGroup
      FIVEWORDINLINE(0x2F3C, 0x0018, 0x0504, 0x7000, 0xA82A);

  /**
     non-NULL RTPPacketRepeatedDataRef means this data will be repeated later
     pb must return a repeated data ref
  */
  /**
   *  RTPPBAddPacke// when set in EndPacketGroup, will not add group
   *
   *  Availability:
   *    \non_carbon_cfm   in QTStreamLib 4.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in QTSClient.lib 4.0 and later
   */
  // flags for RTPPBGetSampleData
  RTPPBAddPacketSampleData(RTPPacketBuilder rtpb, SInt32 inFlags,
                           RTPPacketGroupRef inPacketGroup, RTPPacketRef inPacket,
                           RTPMPSampleDataParams *inSampleDataParams,
                           UInt32 inSampleOffset, UInt32 inSampleDataLength,
                           RTPPacketRepeatedDataRef *outDataRef)
      FIVEWORDINLINE(0x2F3C, 0x001C, 0x0505, 0x7000, 0xA82A);

  /**
     non-NULL RTPPacketRepeatedDataRef means this data will be repeated later
     pb must return a repeated data ref
  */
  /**
   *  RTPPBAddPacketSampleData64()
   *
   *  Availability:
   *    \non_carbon_cfm   in QTStreamLib 5.0 and later
   *    \carbon_lib        in CarbonLib 1.3 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in QTSClient.lib 5.0 and later
   */
  ComponentResult
  RTPPBAddPacketSampleData64(RTPPacketBuilder rtpb, SInt32 inFlags,
                             RTPPacketGroupRef inPacketGroup,
                             RTPPacketRef inPacket,
                             RTPMPSampleDataParams *inSampleDataParams,
                             const UInt64 *inSampleOffset,
                             UInt32 inSampleDataLength,
                             RTPPacketRepeatedDataRef *outDataRef)
      FIVEWORDINLINE(0x2F3C, 0x001C, 0x0510, 0x7000, 0xA82A);

  /**
     call to add the repeated data using the ref you got from
     RTPPBAddPacketLiteralData or RTPPBAddPacketSampleData
  */
  /**
   *  RTPPBAddPacketRepeatedData()
   *
   *  Availability:
   *    \non_carbon_cfm   in QTStreamLib 4.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in QTSClient.lib 4.0 and later
   */
  ComponentResult
  RTPPBAddPacketRepeatedData(RTPPacketBuilder rtpb, SInt32 inFlags,
                             RTPPacketGroupRef inPacketGroup,
                             RTPPacketRef inPacket,
                             RTPPacketRepeatedDataRef inDataRef)
      FIVEWORDINLINE(0x2F3C, 0x0010, 0x0506, 0x7000, 0xA82A);

  // call when done with repeated data  /**
   *  RTPPBReleaseRepeatedData()
   *
   *  Availability:
   *    \non_carbon_cfm   in QTStreamLib 4.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in QTSClient.lib 4.0 and later
   */
  ComponentResult
  RTPPBReleaseRepeatedData(RTPPacketBuilder rtpb,
                           RTPPacketRepeatedDataRef inDataRef)
      FIVEWORDINLINE(0x2F3C, 0x0004, 0x0507, 0x7000, 0xA82A);

  /**
     seq number is just relative seq number
     don't call if you don't care when seq # is used
  */
  /**
   *  RTPPBSetPacketSequenceNumber()
   *
   *  Availability:
   *    \non_carbon_cfm   in QTStreamLib 4.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in QTSClient.lib 4.0 and later
   */
  ComponentResult
  RTPPBSetPacketSequenceNumber(RTPPacketBuilder rtpb, SInt32 inFlags,
                               RTPPacketGroupRef inPacketGroup,
                               RTPPacketRef inPacket, UInt32 inSequenceNumber)
      FIVEWORDINLINE(0x2F3C, 0x0010, 0x0508, 0x7000, 0xA82A);

  /**
   *  RTPPBGetPacketSequenceNumber()
   *
   *  Availability:
   *    \non_carbon_cfm   in QTStreamLib 4.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in QTSClient.lib 4.0 and later
   */
  ComponentResult
  RTPPBGetPacketSequenceNumber(RTPPacketBuilder rtpb, SInt32 inFlags,
                               RTPPacketGroupRef inPacketGroup,
                               RTPPacketRef inPacket, UInt32 *outSequenceNumber)
      FIVEWORDINLINE(0x2F3C, 0x0010, 0x0509, 0x7000, 0xA82A);

  /**
   *  RTPPBSetPacketTimeStampOffset()
   *
   *  Availability:
   *    \non_carbon_cfm   in QTStreamLib 5.0 and later
   *    \carbon_lib        in CarbonLib 1.3 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in QTSClient.lib 5.0 and later
   */
  ComponentResult
  RTPPBSetPacketTimeStampOffset(RTPPacketBuilder rtpb, SInt32 inFlags,
                                RTPPacketGroupRef inPacketGroup,
                                RTPPacketRef inPacket, SInt32 inTimeStampOffset)
      FIVEWORDINLINE(0x2F3C, 0x0010, 0x050E, 0x7000, 0xA82A);

  /**
   *  RTPPBGetPacketTimeStampOffset()
   *
   *  Availability:
   *    \non_carbon_cfm   in QTStreamLib 5.0 and later
   *    \carbon_lib        in CarbonLib 1.3 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in QTSClient.lib 5.0 and later
   */
  ComponentResult
  RTPPBGetPacketTimeStampOffset(RTPPacketBuilder rtpb, SInt32 inFlags,
                                RTPPacketGroupRef inPacketGroup,
                                RTPPacketRef inPacket, SInt32 *outTimeStampOffset)
      FIVEWORDINLINE(0x2F3C, 0x0010, 0x050F, 0x7000, 0xA82A);

  /**
   *  RTPPBAddRepeatPacket()
   *
   *  Availability:
   *    \non_carbon_cfm   in QTStreamLib 5.0 and later
   *    \carbon_lib        in CarbonLib 1.3 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in QTSClient.lib 5.0 and later
   */
  ComponentResult
  RTPPBAddRepeatPacket(RTPPacketBuilder rtpb, SInt32 inFlags,
                       RTPPacketGroupRef inPacketGroup, RTPPacketRef inPacket,
                       TimeValue inTransmissionOffset, UInt32 inSequenceNumber)
      FIVEWORDINLINE(0x2F3C, 0x0014, 0x0512, 0x7000, 0xA82A);

  /**
     used for communicating with the caller of the media packetizers if needed
     NOT used for communicating with the media packetizers themselves
  */
  /**
   *  RTPPBSetCallback()
   *
   *  Availability:
   *    \non_carbon_cfm   in QTStreamLib 4.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in QTSClient.lib 4.0 and later
   */
  ComponentResult
  RTPPBSetCallback(RTPPacketBuilder rtpb, RTPPBCallbackUPP inCallback,
                   void *inRefCon)
      FIVEWORDINLINE(0x2F3C, 0x0008, 0x050A, 0x7000, 0xA82A);

  /**
   *  RTPPBGetCallback()
   *
   *  Availability:
   *    \non_carbon_cfm   in QTStreamLib 4.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in QTSClient.lib 4.0 and later
   */
  ComponentResult
  RTPPBGetCallback(RTPPacketBuilder rtpb, RTPPBCallbackUPP *outCallback,
                   void **outRefCon)
      FIVEWORDINLINE(0x2F3C, 0x0008, 0x050B, 0x7000, 0xA82A);

  /**
   *  RTPPBSetInfo()
   *
   *  Availability:
   *    \non_carbon_cfm   in QTStreamLib 4.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
  // call when done with repeated data
   *    Windows:          in QTSClient.lib 4.0 and later
   */
  ComponentResult
  RTPPBSetInfo(RTPPacketBuilder rtpb, OSType inSelector, void *ioParams)
      FIVEWORDINLINE(0x2F3C, 0x0008, 0x050C, 0x7000, 0xA82A);

  /**
   *  RTPPBGetInfo()
   *
   *  Availability:
   *    \non_carbon_cfm   in QTStreamLib 4.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in QTSClient.lib 4.0 and later
   */
  ComponentResult
  RTPPBGetInfo(RTPPacketBuilder rtpb, OSType inSelector, void *ioParams)
      FIVEWORDINLINE(0x2F3C, 0x0008, 0x050D, 0x7000, 0xA82A);

  /**
   *  RTPPBGetSampleData()
   *
   *  Availability:
   *    \non_carbon_cfm   in QTStreamLib 5.0 and later
   *    \carbon_lib        in CarbonLib 1.3 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in QTSClient.lib 5.0 and later
   */
  ComponentResult
  RTPPBGetSampleData(RTPPacketBuilder rtpb, RTPMPSampleDataParams *inParams,
                     const UInt64 *inStartOffset, UInt8 *outDataBuffer,
                     UInt32 inBytesToRead, UInt32 *outBytesRead, SInt32 *outFlags)
      FIVEWORDINLINE(0x2F3C, 0x0018, 0x0511, 0x7000, 0xA82A);

  // UPP call backs   /**
   *  NewRTPMPDataReleaseUPP()
   *
   *  Availability:
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.3 and later
   *    \mac_os_x         in version 10.0 and later
   */
  RTPMPDataReleaseUPP
  NewRTPMPDataReleaseUPP(RTPMPDataReleaseProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppRTPMPDataReleaseProcInfo = 0x000003C0
  }; // pascal no_return_value Func(4_bytes, 4_bytes) #ifdef __cplusplus
  inline RTPMPDataReleaseUPP
  NewRTPMPDataReleaseUPP(RTPMPDataReleaseProcPtr userRoutine)
  {
    return (RTPMPDataReleaseUPP)NewRoutineDescriptor((ProcPtr)(userRoutine),
                                                     uppRTPMPDataReleaseProcInfo,
                                                     GetCurrentArchitecture());
  }
#else
#define NewRTPMPDataReleaseUPP(userRoutine)                               \
  (RTPMPDataReleaseUPP) NewRoutineDescriptor((ProcPtr)(userRoutine),      \
                                             uppRTPMPDataReleaseProcInfo, \
                                             GetCurrentArchitecture())
#endif
#endif

  /**
   *  NewRTPPBCallbackUPP()
   *
   *  Availability:
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.3 and later
   *    \mac_os_x         in version 10.0 and later
   */
  RTPPBCallbackUPP
  NewRTPPBCallbackUPP(RTPPBCallbackProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppRTPPBCallbackProcInfo = 0x00000FC0
  }; // pascal no_return_value Func(4_bytes, 4_bytes, 4_bytes) #ifdef __cplusplus
  inline RTPPBCallbackUPP NewRTPPBCallbackUPP(RTPPBCallbackProcPtr userRoutine)
  {
    return (RTPPBCallbackUPP)NewRoutineDescriptor((ProcPtr)(userRoutine),
                                                  uppRTPPBCallbackProcInfo,
                                                  GetCurrentArchitecture());
  }
#else
#define NewRTPPBCallbackUPP(userRoutine)                                     \
  (RTPPBCallbackUPP)                                                         \
      NewRoutineDescriptor((ProcPtr)(userRoutine), uppRTPPBCallbackProcInfo, \
                           GetCurrentArchitecture())
#endif
#endif

  /**
   *  DisposeRTPMPDataReleaseUPP()
   *
   *  Availability:
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.3 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeRTPMPDataReleaseUPP(RTPMPDataReleaseUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeRTPMPDataReleaseUPP(RTPMPDataReleaseUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeRTPMPDataReleaseUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  DisposeRTPPBCallbackUPP()
   *
   *  Availability:
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.3 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeRTPPBCallbackUPP(RTPPBCallbackUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeRTPPBCallbackUPP(RTPPBCallbackUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeRTPPBCallbackUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  InvokeRTPMPDataReleaseUPP()
   *
   *  Availability:
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.3 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  InvokeRTPMPDataReleaseUPP(UInt8 *inData, void *inRefCon,
                            RTPMPDataReleaseUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void InvokeRTPMPDataReleaseUPP(UInt8 *inData, void *inRefCon,
                                        RTPMPDataReleaseUPP userUPP)
  {
    CALL_TWO_PARAMETER_UPP(userUPP, uppRTPMPDataReleaseProcInfo, inData,
                           inRefCon);
  }
#else
#define InvokeRTPMPDataReleaseUPP(inData, inRefCon, userUPP)               \
  CALL_TWO_PARAMETER_UPP((userUPP), uppRTPMPDataReleaseProcInfo, (inData), \
                         (inRefCon))
#endif
#endif

  /**
   *  InvokeRTPPBCallbackUPP()
   *
   *  Availability:
   *    \non_carbon_cfm   available as macro/inline
  // UPP call backs 
   *    \mac_os_x         in version 10.0 and later
   */
  void
  InvokeRTPPBCallbackUPP(OSType inSelector, void *ioParams, void *inRefCon,
                         RTPPBCallbackUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void InvokeRTPPBCallbackUPP(OSType inSelector, void *ioParams,
                                     void *inRefCon, RTPPBCallbackUPP userUPP)
  {
    CALL_THREE_PARAMETER_UPP(userUPP, uppRTPPBCallbackProcInfo, inSelector,
                             ioParams, inRefCon);
  }
#else
#defi// pascal no_return_value Func(4_bytes, 4_bytes) 
  CALL_THREE_PARAMETER_UPP((userUPP), uppRTPPBCallbackProcInfo, (inSelector), \
                           (ioParams), (inRefCon))
#endif
#endif

#if CALL_NOT_IN_CARBON || OLDROUTINENAMES
// support for pre-Carbon UPP routines: New...Proc and Call...Proc #define NewRTPMPDataReleaseProc(userRoutine) NewRTPMPDataReleaseUPP(userRoutine)
#define NewRTPPBCallbackProc(userRoutine) NewRTPPBCallbackUPP(userRoutine)
#define CallRTPMPDataReleaseProc(userRoutine, inData, inRefCon) \
  InvokeRTPMPDataReleaseUPP(inData, inRefCon, userRoutine)
#define CallRTPPBCallbackProc(userRoutine, inSelector, ioParams, inRefCon) \
  InvokeRTPPBCallbackUPP(inSelector, ioParams, inRefCon, userRoutine)
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
// pascal no_return_value Func(4_bytes, 4_bytes, 4_bytes) 
#endif // __QTSTREAMINGCOMPONENTS__ // support for pre-Carbon UPP routines: New...Proc and Call...Proc 
// CALL_NOT_IN_CARBON 
// __QTSTREAMINGCOMPONENTS__ 
