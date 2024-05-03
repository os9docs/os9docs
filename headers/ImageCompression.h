/**
     \file       ImageCompression.h

    \brief   QuickTime Image Compression Interfaces.

    \introduced_in  QuickTime 5.0
    \avaliable_from Universal Interfaces 3.4.1

    \copyright © 1990-2001 by Apple Computer, Inc., all rights reserved

    \ingroup QuickTime

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __IMAGECOMPRESSION__
#define __IMAGECOMPRESSION__

#ifndef __MACTYPES__
#include <MacTypes.h>
#endif

#ifndef __QUICKDRAW__
#include <Quickdraw.h>
#endif

#ifndef __QDOFFSCREEN__
#include <QDOffscreen.h>
#endif

#ifndef __COMPONENTS__
#include <Components.h>
#endif

#ifndef __DIALOGS__
#include <Dialogs.h>
#endif

#ifndef __STANDARDFILE__
#include <StandardFile.h>
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

    struct MatrixRecord
    {
        Fixed matrix[3][3];
    };
    typedef struct MatrixRecord MatrixRecord;
    typedef MatrixRecord *MatrixRecordPtr;
    enum
    {
        kRawCodecType = FOUR_CHAR_CODE('raw '),
        kCinepakCodecType = FOUR_CHAR_CODE('cvid'),
        kGraphicsCodecType = FOUR_CHAR_CODE('smc '),
        kAnimationCodecType = FOUR_CHAR_CODE('rle '),
        kVideoCodecType = FOUR_CHAR_CODE('rpza'),
        kComponentVideoCodecType = FOUR_CHAR_CODE('yuv2'),
        kJPEGCodecType = FOUR_CHAR_CODE('jpeg'),
        kMotionJPEGACodecType = FOUR_CHAR_CODE('mjpa'),
        kMotionJPEGBCodecType = FOUR_CHAR_CODE('mjpb'),
        kSGICodecType = FOUR_CHAR_CODE('.SGI'),
        kPlanarRGBCodecType = FOUR_CHAR_CODE('8BPS'),
        kMacPaintCodecType = FOUR_CHAR_CODE('PNTG'),
        kGIFCodecType = FOUR_CHAR_CODE('gif '),
        kPhotoCDCodecType = FOUR_CHAR_CODE('kpcd'),
        kQuickDrawGXCodecType = FOUR_CHAR_CODE('qdgx'),
        kAVRJPEGCodecType = FOUR_CHAR_CODE('avr '),
        kOpenDMLJPEGCodecType = FOUR_CHAR_CODE('dmb1'),
        kBMPCodecType = FOUR_CHAR_CODE('WRLE'),
        kWindowsRawCodecType = FOUR_CHAR_CODE('WRAW'),
        kVectorCodecType = FOUR_CHAR_CODE('path'),
        kQuickDrawCodecType = FOUR_CHAR_CODE('qdrw'),
        kWaterRippleCodecType = FOUR_CHAR_CODE('ripl'),
        kFireCodecType = FOUR_CHAR_CODE('fire'),
        kCloudCodecType = FOUR_CHAR_CODE('clou'),
        kH261CodecType = FOUR_CHAR_CODE('h261'),
        kH263CodecType = FOUR_CHAR_CODE('h263'),
        kDVCNTSCCodecType = FOUR_CHAR_CODE('dvc '),
        kDVCPALCodecType = FOUR_CHAR_CODE('dvcp'),
        kDVCProNTSCCodecType = FOUR_CHAR_CODE('dvpn'),
        kDVCProPALCodecType = FOUR_CHAR_CODE('dvpp'),
        kBaseCodecType = FOUR_CHAR_CODE('base'),
        kFLCCodecType = FOUR_CHAR_CODE('flic'),
        kTargaCodecType = FOUR_CHAR_CODE('tga '),
        kPNGCodecType = FOUR_CHAR_CODE('png '),
        kTIFFCodecType = FOUR_CHAR_CODE('tiff'), /**    NOTE: despite what might seem
                                                    obvious from the two constants*/
        /**    below and their names, they really are correct. 'yuvu' really */
        /**    does mean signed, and 'yuvs' really does mean unsigned. Really. */
        kComponentVideoSigned = FOUR_CHAR_CODE('yuvu'),
        kComponentVideoUnsigned = FOUR_CHAR_CODE('yuvs'),
        kCMYKCodecType = FOUR_CHAR_CODE('cmyk'),
        kMicrosoftVideo1CodecType = FOUR_CHAR_CODE('msvc'),
        kSorensonCodecType = FOUR_CHAR_CODE('SVQ1'),
        kSorenson3CodecType =
            FOUR_CHAR_CODE('SVQ3'), /** available in QuickTime 5 and later*/
        kIndeo4CodecType = FOUR_CHAR_CODE('IV41'),
        k64ARGBCodecType = FOUR_CHAR_CODE('b64a'),
        k48RGBCodecType = FOUR_CHAR_CODE('b48r'),
        k32AlphaGrayCodecType = FOUR_CHAR_CODE('b32a'),
        k16GrayCodecType = FOUR_CHAR_CODE('b16g'),
        kMpegYUV420CodecType = FOUR_CHAR_CODE('myuv'),
        kYUV420CodecType = FOUR_CHAR_CODE('y420'),
        kSorensonYUV9CodecType = FOUR_CHAR_CODE('syv9'),
        k422YpCbCr8CodecType =
            FOUR_CHAR_CODE('2vuy'), /** Component Y'CbCr 8-bit 4:2:2  */
        k444YpCbCr8CodecType =
            FOUR_CHAR_CODE('v308'), /** Component Y'CbCr 8-bit 4:4:4  */
        k4444YpCbCrA8CodecType =
            FOUR_CHAR_CODE('v408'), /** Component Y'CbCrA 8-bit 4:4:4:4 */
        k422YpCbCr16CodecType =
            FOUR_CHAR_CODE('v216'), /** Component Y'CbCr 10,12,14,16-bit 4:2:2*/
        k422YpCbCr10CodecType =
            FOUR_CHAR_CODE('v210'), /** Component Y'CbCr 10-bit 4:2:2 */
        k444YpCbCr10CodecType =
            FOUR_CHAR_CODE('v410'), /** Component Y'CbCr 10-bit 4:4:4 */
        k4444YpCbCrA8RCodecType =
            FOUR_CHAR_CODE('r408') /** Component Y'CbCrA 8-bit 4:4:4:4, rendering
                                      format. full range alpha, zero biased yuv*/
    };

    /** one source effects */
    enum
    {
        kBlurImageFilterType = FOUR_CHAR_CODE('blur'),
        kSharpenImageFilterType = FOUR_CHAR_CODE('shrp'),
        kEdgeDetectImageFilterType = FOUR_CHAR_CODE('edge'),
        kEmbossImageFilterType = FOUR_CHAR_CODE('embs'),
        kConvolveImageFilterType = FOUR_CHAR_CODE('genk'),
        kAlphaGainImageFilterType = FOUR_CHAR_CODE('gain'),
        kRGBColorBalanceImageFilterType = FOUR_CHAR_CODE('rgbb'),
        kHSLColorBalanceImageFilterType = FOUR_CHAR_CODE('hslb'),
        kColorSyncImageFilterType = FOUR_CHAR_CODE('sync'),
        kFilmNoiseImageFilterType = FOUR_CHAR_CODE('fmns'),
        kSolarizeImageFilterType = FOUR_CHAR_CODE('solr'),
        kColorTintImageFilterType = FOUR_CHAR_CODE('tint'),
        kLensFlareImageFilterType = FOUR_CHAR_CODE('lens'),
        kBrightnessContrastImageFilterType = FOUR_CHAR_CODE('brco')
    };

    /** two source effects */
    enum
    {
        kAlphaCompositorTransitionType = FOUR_CHAR_CODE('blnd'),
        kCrossFadeTransitionType = FOUR_CHAR_CODE('dslv'),
        kChromaKeyTransitionType = FOUR_CHAR_CODE('ckey'),
        kImplodeTransitionType = FOUR_CHAR_CODE('mplo'),
        kExplodeTransitionType = FOUR_CHAR_CODE('xplo'),
        kGradientTransitionType = FOUR_CHAR_CODE('matt'),
        kPushTransitionType = FOUR_CHAR_CODE('push'),
        kSlideTransitionType = FOUR_CHAR_CODE('slid'),
        kWipeTransitionType = FOUR_CHAR_CODE('smpt'),
        kIrisTransitionType = FOUR_CHAR_CODE('smp2'),
        kRadialTransitionType = FOUR_CHAR_CODE('smp3'),
        kMatrixTransitionType = FOUR_CHAR_CODE('smp4'),
        kZoomTransitionType = FOUR_CHAR_CODE('zoom')
    };

    /** three source effects */
    enum
    {
        kTravellingMatteEffectType = FOUR_CHAR_CODE('trav')
    };

    /** These are the bits that are set in the Component flags, and also in the
     * codecInfo struct. */
    enum
    {
        codecInfoDoes1 = (1L << 0),       /** codec can work with 1-bit pixels */
        codecInfoDoes2 = (1L << 1),       /** codec can work with 2-bit pixels */
        codecInfoDoes4 = (1L << 2),       /** codec can work with 4-bit pixels */
        codecInfoDoes8 = (1L << 3),       /** codec can work with 8-bit pixels */
        codecInfoDoes16 = (1L << 4),      /** codec can work with 16-bit pixels */
        codecInfoDoes32 = (1L << 5),      /** codec can work with 32-bit pixels */
        codecInfoDoesDither = (1L << 6),  /** codec can do ditherMode */
        codecInfoDoesStretch = (1L << 7), /** codec can stretch to arbitrary sizes */
        codecInfoDoesShrink = (1L << 8),  /** codec can shrink to arbitrary sizes */
        codecInfoDoesMask = (1L << 9),    /** codec can mask to clipping regions */
        codecInfoDoesTemporal =
            (1L << 10), /** codec can handle temporal redundancy */
        codecInfoDoesDouble =
            (1L << 11), /** codec can stretch to double size exactly */
        codecInfoDoesQuad =
            (1L << 12),                    /** codec can stretch to quadruple size exactly */
        codecInfoDoesHalf = (1L << 13),    /** codec can shrink to half size */
        codecInfoDoesQuarter = (1L << 14), /** codec can shrink to quarter size */
        codecInfoDoesRotate = (1L << 15),  /** codec can rotate on decompress */
        codecInfoDoesHorizFlip =
            (1L << 16), /** codec can flip horizontally on decompress */
        codecInfoDoesVertFlip =
            (1L << 17), /** codec can flip vertically on decompress */
        codecInfoHasEffectParameterList =
            (1L << 18),                  /** codec implements get effects parameter list call, once was
                                            codecInfoDoesSkew */
        codecInfoDoesBlend = (1L << 19), /** codec can blend on decompress */
        codecInfoDoesWarp =
            (1L << 20), /** codec can warp arbitrarily on decompress */
        codecInfoDoesRecompress =
            (1L << 21),                         /** codec can recompress image without accumulating errors */
        codecInfoDoesSpool = (1L << 22),        /** codec can spool image data */
        codecInfoDoesRateConstrain = (1L << 23) /** codec can data rate constrain */
    };

    enum
    {
        codecInfoDepth1 = (1L << 0),  /** compressed data at 1 bpp depth available */
        codecInfoDepth2 = (1L << 1),  /** compressed data at 2 bpp depth available */
        codecInfoDepth4 = (1L << 2),  /** compressed data at 4 bpp depth available */
        codecInfoDepth8 = (1L << 3),  /** compressed data at 8 bpp depth available */
        codecInfoDepth16 = (1L << 4), /** compressed data at 16 bpp depth available */
        codecInfoDepth32 = (1L << 5), /** compressed data at 32 bpp depth available */
        codecInfoDepth24 = (1L << 6), /** compressed data at 24 bpp depth available */
        codecInfoDepth33 =
            (1L << 7), /** compressed data at 1 bpp monochrome depth  available */
        codecInfoDepth34 =
            (1L << 8), /** compressed data at 2 bpp grayscale depth available */
        codecInfoDepth36 =
            (1L << 9), /** compressed data at 4 bpp grayscale depth available */
        codecInfoDepth40 =
            (1L << 10),                   /** compressed data at 8 bpp grayscale depth available */
        codecInfoStoresClut = (1L << 11), /** compressed data can have custom cluts */
        codecInfoDoesLossless =
            (1L << 12), /** compressed data can be stored in lossless format */
        codecInfoSequenceSensitive =
            (1L << 13) /** compressed data is sensitive to out of sequence decoding */
    };

    /** input sequence flags*/
    enum
    {
        codecFlagUseImageBuffer = (1L << 0),         /** decompress*/
        codecFlagUseScreenBuffer = (1L << 1),        /** decompress*/
        codecFlagUpdatePrevious = (1L << 2),         /** compress*/
        codecFlagNoScreenUpdate = (1L << 3),         /** decompress*/
        codecFlagWasCompressed = (1L << 4),          /** compress*/
        codecFlagDontOffscreen = (1L << 5),          /** decompress*/
        codecFlagUpdatePreviousComp = (1L << 6),     /** compress*/
        codecFlagForceKeyFrame = (1L << 7),          /** compress*/
        codecFlagOnlyScreenUpdate = (1L << 8),       /** decompress*/
        codecFlagLiveGrab = (1L << 9),               /** compress*/
        codecFlagDiffFrame = (1L << 9),              /** decompress*/
        codecFlagDontUseNewImageBuffer = (1L << 10), /** decompress*/
        codecFlagInterlaceUpdate = (1L << 11),       /** decompress*/
        codecFlagCatchUpDiff = (1L << 12),           /** decompress*/
        codecFlagSupportDisable = (1L << 13),        /** decompress*/
        codecFlagReenable = (1L << 14)               /** decompress*/
    };

    /** output sequence flags*/
    enum
    {
        codecFlagOutUpdateOnNextIdle = (1L << 9),
        codecFlagOutUpdateOnDataSourceChange = (1L << 10),
        codecFlagSequenceSensitive = (1L << 11),
        codecFlagOutUpdateOnTimeChange = (1L << 12),
        codecFlagImageBufferNotSourceImage = (1L << 13),
        codecFlagUsedNewImageBuffer = (1L << 14),
        codecFlagUsedImageBuffer = (1L << 15)
    };

    enum
    {
        /** The minimum data size for spooling in or out data */
        codecMinimumDataSize = 32768L
    };

    enum
    {
        compressorComponentType = FOUR_CHAR_CODE(
            'imco'), /** the type for "Components" which compress images */
        decompressorComponentType = FOUR_CHAR_CODE(
            'imdc') /** the type for "Components" which decompress images */
    };

    typedef Component CompressorComponent;
    typedef Component DecompressorComponent;
    typedef Component CodecComponent;
#define anyCodec ((CodecComponent)0)
#define bestSpeedCodec ((CodecComponent)-1)
#define bestFidelityCodec ((CodecComponent)-2)
#define bestCompressionCodec ((CodecComponent)-3)
    typedef OSType CodecType;
    typedef unsigned short CodecFlags;
    typedef unsigned long CodecQ;
    enum
    {
        codecLosslessQuality = 0x00000400,
        codecMaxQuality = 0x000003FF,
        codecMinQuality = 0x00000000,
        codecLowQuality = 0x00000100,
        codecNormalQuality = 0x00000200,
        codecHighQuality = 0x00000300
    };

    enum
    {
        codecLockBitsShieldCursor = (1 << 0) /** shield cursor */
    };

    enum
    {
        codecCompletionSource =
            (1 << 0), /** asynchronous codec is done with source data */
        codecCompletionDest =
            (1 << 1), /** asynchronous codec is done with destination data */
        codecCompletionDontUnshield =
            (1 << 2),                            /** on dest complete don't unshield cursor */
        codecCompletionWentOffscreen = (1 << 3), /** codec used offscreen buffer */
        codecCompletionUnlockBits =
            (1 << 4), /** on dest complete, call ICMSequenceUnlockBits */
        codecCompletionForceChainFlush =
            (1 << 5),                     /** ICM needs to flush the whole chain */
        codecCompletionDropped = (1 << 6) /** codec decided to drop this frame */
    };

    enum
    {
        codecProgressOpen = 0,
        codecProgressUpdatePercent = 1,
        codecProgressClose = 2
    };

    typedef CALLBACK_API(OSErr, ICMDataProcPtr)(Ptr *dataP, long bytesNeeded,
                                                long refcon);
    typedef CALLBACK_API(OSErr, ICMFlushProcPtr)(Ptr data, long bytesAdded,
                                                 long refcon);
    typedef CALLBACK_API(void, ICMCompletionProcPtr)(OSErr result, short flags,
                                                     long refcon);
    typedef CALLBACK_API(OSErr, ICMProgressProcPtr)(short message,
                                                    Fixed completeness,
                                                    long refcon);
    typedef CALLBACK_API(void, StdPixProcPtr)(PixMap *src, Rect *srcRect,
                                              MatrixRecord *matrix, short mode,
                                              RgnHandle mask, PixMap *matte,
                                              Rect *matteRect, short flags);
    typedef CALLBACK_API(void, QDPixProcPtr)(PixMap *src, Rect *srcRect,
                                             MatrixRecord *matrix, short mode,
                                             RgnHandle mask, PixMap *matte,
                                             Rect *matteRect, short flags);
    typedef CALLBACK_API(void, ICMAlignmentProcPtr)(Rect *rp, long refcon);
    typedef CALLBACK_API(void, ICMCursorShieldedProcPtr)(const Rect *r,
                                                         void *refcon, long flags);
    typedef CALLBACK_API(void, ICMMemoryDisposedProcPtr)(Ptr memoryBlock,
                                                         void *refcon);
    typedef void *ICMCursorNotify;
    typedef CALLBACK_API(OSErr, ICMConvertDataFormatProcPtr)(
        void *refCon, long flags, Handle desiredFormat, Handle sourceDataFormat,
        void *srcData, long srcDataSize, void **dstData, long *dstDataSize);
    typedef STACK_UPP_TYPE(ICMDataProcPtr) ICMDataUPP;
    typedef STACK_UPP_TYPE(ICMFlushProcPtr) ICMFlushUPP;
    typedef STACK_UPP_TYPE(ICMCompletionProcPtr) ICMCompletionUPP;
    typedef STACK_UPP_TYPE(ICMProgressProcPtr) ICMProgressUPP;
    typedef STACK_UPP_TYPE(StdPixProcPtr) StdPixUPP;
    typedef STACK_UPP_TYPE(QDPixProcPtr) QDPixUPP;
    typedef STACK_UPP_TYPE(ICMAlignmentProcPtr) ICMAlignmentUPP;
    typedef STACK_UPP_TYPE(ICMCursorShieldedProcPtr) ICMCursorShieldedUPP;
    typedef STACK_UPP_TYPE(ICMMemoryDisposedProcPtr) ICMMemoryDisposedUPP;
    typedef STACK_UPP_TYPE(ICMConvertDataFormatProcPtr) ICMConvertDataFormatUPP;
    typedef long ImageSequence;
    typedef long ImageSequenceDataSource;
    typedef long ImageTranscodeSequence;
    typedef long ImageFieldSequence;
    struct ICMProgressProcRecord
    {
        ICMProgressUPP progressProc;
        long progressRefCon;
    };
    typedef struct ICMProgressProcRecord ICMProgressProcRecord;
    typedef ICMProgressProcRecord *ICMProgressProcRecordPtr;
    struct ICMCompletionProcRecord
    {
        ICMCompletionUPP completionProc;
        long completionRefCon;
    };
    typedef struct ICMCompletionProcRecord ICMCompletionProcRecord;
    typedef ICMCompletionProcRecord *ICMCompletionProcRecordPtr;
    struct ICMDataProcRecord
    {
        ICMDataUPP dataProc;
        long dataRefCon;
    };
    typedef struct ICMDataProcRecord ICMDataProcRecord;
    typedef ICMDataProcRecord *ICMDataProcRecordPtr;
    struct ICMFlushProcRecord
    {
        ICMFlushUPP flushProc;
        long flushRefCon;
    };
    typedef struct ICMFlushProcRecord ICMFlushProcRecord;
    typedef ICMFlushProcRecord *ICMFlushProcRecordPtr;
    struct ICMAlignmentProcRecord
    {
        ICMAlignmentUPP alignmentProc;
        long alignmentRefCon;
    };
    typedef struct ICMAlignmentProcRecord ICMAlignmentProcRecord;
    typedef ICMAlignmentProcRecord *ICMAlignmentProcRecordPtr;
    struct DataRateParams
    {
        long dataRate;
        long dataOverrun;
        long frameDuration;
        long keyFrameRate;
        CodecQ minSpatialQuality;
        CodecQ minTemporalQuality;
    };
    typedef struct DataRateParams DataRateParams;
    typedef DataRateParams *DataRateParamsPtr;
    struct ImageDescription
    {
        long idSize;            /** total size of ImageDescription including extra data ( CLUTs
                                   and other per sequence data ) */
        CodecType cType;        /** what kind of codec compressed this data */
        long resvd1;            /** reserved for Apple use */
        short resvd2;           /** reserved for Apple use */
        short dataRefIndex;     /** set to zero  */
        short version;          /** which version is this data */
        short revisionLevel;    /** what version of that codec did this */
        long vendor;            /** whose  codec compressed this data */
        CodecQ temporalQuality; /** what was the temporal quality factor  */
        CodecQ spatialQuality;  /** what was the spatial quality factor */
        short width;            /** how many pixels wide is this data */
        short height;           /** how many pixels high is this data */
        Fixed hRes;             /** horizontal resolution */
        Fixed vRes;             /** vertical resolution */
        long dataSize;          /** if known, the size of data for this image descriptor */
        short frameCount;       /** number of frames this description applies to */
        Str31 name;             /** name of codec ( in case not installed )  */
        short depth;            /** what depth is this data (1-32) or ( 33-40 grayscale ) */
        short clutID;           /** clut id or if 0 clut follows  or -1 if no clut */
    };
    typedef struct ImageDescription ImageDescription;
    typedef ImageDescription *ImageDescriptionPtr;
    typedef ImageDescriptionPtr *ImageDescriptionHandle;
    struct CodecInfo
    {
        Str31 typeName; /** name of the codec type i.e.: 'Apple Image Compression' */
        short version;  /** version of the codec data that this codec knows about */
        short
            revisionLevel;                 /** revision level of this codec i.e: 0x00010001 (1.0.1) */
        long vendor;                       /** Maker of this codec i.e: 'appl' */
        long decompressFlags;              /** codecInfo flags for decompression capabilities */
        long compressFlags;                /** codecInfo flags for compression capabilities */
        long formatFlags;                  /** codecInfo flags for compression format details */
        UInt8 compressionAccuracy;         /** measure (1-255) of accuracy of this codec for
                                              compress (0 if unknown) */
        UInt8 decompressionAccuracy;       /** measure (1-255) of accuracy of this codec for
                                              decompress (0 if unknown) */
        unsigned short compressionSpeed;   /** ( millisecs for compressing 320x240 on
                                              base mac II) (0 if unknown)  */
        unsigned short decompressionSpeed; /** ( millisecs for decompressing 320x240
                                              on mac II)(0 if unknown)  */
        UInt8 compressionLevel;            /** measure (1-255) of compression level of this codec
                                              (0 if unknown)  */
        UInt8 resvd;                       /** pad */
        short minimumHeight;               /** minimum height of image (block size) */
        short minimumWidth;                /** minimum width of image (block size) */
        short decompressPipelineLatency;   /** in milliseconds ( for asynchronous codecs
                                              ) */
        short compressPipelineLatency;     /** in milliseconds ( for asynchronous codecs )
                                            */
        long privateData;
    };
    typedef struct CodecInfo CodecInfo;
    struct CodecNameSpec
    {
        CodecComponent codec;
        CodecType cType;
        Str31 typeName;
        Handle name;
    };
    typedef struct CodecNameSpec CodecNameSpec;
    struct CodecNameSpecList
    {
        short count;
        CodecNameSpec list[1];
    };
    typedef struct CodecNameSpecList CodecNameSpecList;
    typedef CodecNameSpecList *CodecNameSpecListPtr;
    enum
    {
        defaultDither = 0,
        forceDither = 1,
        suppressDither = 2,
        useColorMatching = 4
    };

    enum
    {
        callStdBits = 1,
        callOldBits = 2,
        noDefaultOpcodes = 4
    };

    enum
    {
        graphicsModeStraightAlpha = 256,
        graphicsModePreWhiteAlpha = 257,
        graphicsModePreBlackAlpha = 258,
        graphicsModeComposition = 259,
        graphicsModeStraightAlphaBlend = 260,
        graphicsModePreMulColorAlpha = 261
    };

    enum
    {
        evenField1ToEvenFieldOut = 1 << 0,
        evenField1ToOddFieldOut = 1 << 1,
        oddField1ToEvenFieldOut = 1 << 2,
        oddField1ToOddFieldOut = 1 << 3,
        evenField2ToEvenFieldOut = 1 << 4,
        evenField2ToOddFieldOut = 1 << 5,
        oddField2ToEvenFieldOut = 1 << 6,
        oddField2ToOddFieldOut = 1 << 7
    };

    enum
    {
        icmFrameTimeHasVirtualStartTimeAndDuration = 1 << 0
    };

    struct ICMFrameTimeRecord
    {
        wide value; /** frame time*/
        long scale; /** timescale of value/duration fields*/
        void *base; /** timebase*/

        long duration; /** duration frame is to be displayed (0 if unknown)*/
        Fixed rate;    /** rate of timebase relative to wall-time*/

        long recordSize; /** total number of bytes in ICMFrameTimeRecord*/

        long frameNumber; /** number of frame, zero if not known*/

        long flags;

        wide virtualStartTime; /** conceptual start time*/
        long virtualDuration;  /** conceptual duration*/
    };
    typedef struct ICMFrameTimeRecord ICMFrameTimeRecord;
    typedef ICMFrameTimeRecord *ICMFrameTimePtr;
    /**
     *  NewICMDataUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    ICMDataUPP
    NewICMDataUPP(ICMDataProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
    enum
    {
        uppICMDataProcInfo = 0x00000FE0
    }; /** pascal 2_bytes Func(4_bytes, 4_bytes, 4_bytes) */
#ifdef __cplusplus
    inline ICMDataUPP NewICMDataUPP(ICMDataProcPtr userRoutine)
    {
        return (ICMDataUPP)NewRoutineDescriptor(
            (ProcPtr)(userRoutine), uppICMDataProcInfo, GetCurrentArchitecture());
    }
#else
#define NewICMDataUPP(userRoutine)     \
    (ICMDataUPP) NewRoutineDescriptor( \
        (ProcPtr)(userRoutine), uppICMDataProcInfo, GetCurrentArchitecture())
#endif
#endif

    /**
     *  NewICMFlushUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    ICMFlushUPP
    NewICMFlushUPP(ICMFlushProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
    enum
    {
        uppICMFlushProcInfo = 0x00000FE0
    }; /** pascal 2_bytes Func(4_bytes, 4_bytes, 4_bytes) */
#ifdef __cplusplus
    inline ICMFlushUPP NewICMFlushUPP(ICMFlushProcPtr userRoutine)
    {
        return (ICMFlushUPP)NewRoutineDescriptor(
            (ProcPtr)(userRoutine), uppICMFlushProcInfo, GetCurrentArchitecture());
    }
#else
#define NewICMFlushUPP(userRoutine)     \
    (ICMFlushUPP) NewRoutineDescriptor( \
        (ProcPtr)(userRoutine), uppICMFlushProcInfo, GetCurrentArchitecture())
#endif
#endif

    /**
     *  NewICMCompletionUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    ICMCompletionUPP
    NewICMCompletionUPP(ICMCompletionProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
    enum
    {
        uppICMCompletionProcInfo = 0x00000E80
    }; /** pascal no_return_value Func(2_bytes, 2_bytes, 4_bytes) */
#ifdef __cplusplus
    inline ICMCompletionUPP NewICMCompletionUPP(ICMCompletionProcPtr userRoutine)
    {
        return (ICMCompletionUPP)NewRoutineDescriptor((ProcPtr)(userRoutine),
                                                      uppICMCompletionProcInfo,
                                                      GetCurrentArchitecture());
    }
#else
#define NewICMCompletionUPP(userRoutine)                                       \
    (ICMCompletionUPP)                                                         \
        NewRoutineDescriptor((ProcPtr)(userRoutine), uppICMCompletionProcInfo, \
                             GetCurrentArchitecture())
#endif
#endif

    /**
     *  NewICMProgressUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    ICMProgressUPP
    NewICMProgressUPP(ICMProgressProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
    enum
    {
        uppICMProgressProcInfo = 0x00000FA0
    }; /** pascal 2_bytes Func(2_bytes, 4_bytes, 4_bytes) */
#ifdef __cplusplus
    inline ICMProgressUPP NewICMProgressUPP(ICMProgressProcPtr userRoutine)
    {
        return (ICMProgressUPP)NewRoutineDescriptor(
            (ProcPtr)(userRoutine), uppICMProgressProcInfo, GetCurrentArchitecture());
    }
#else
#define NewICMProgressUPP(userRoutine)                                       \
    (ICMProgressUPP)                                                         \
        NewRoutineDescriptor((ProcPtr)(userRoutine), uppICMProgressProcInfo, \
                             GetCurrentArchitecture())
#endif
#endif

    /**
     *  NewStdPixUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    StdPixUPP
    NewStdPixUPP(StdPixProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
    enum
    {
        uppStdPixProcInfo = 0x002FEFC0
    }; /** pascal no_return_value Func(4_bytes, 4_bytes, 4_bytes, 2_bytes, 4_bytes,
          4_bytes, 4_bytes, 2_bytes) */
#ifdef __cplusplus
    inline StdPixUPP NewStdPixUPP(StdPixProcPtr userRoutine)
    {
        return (StdPixUPP)NewRoutineDescriptor(
            (ProcPtr)(userRoutine), uppStdPixProcInfo, GetCurrentArchitecture());
    }
#else
#define NewStdPixUPP(userRoutine)                                               \
    (StdPixUPP) NewRoutineDescriptor((ProcPtr)(userRoutine), uppStdPixProcInfo, \
                                     GetCurrentArchitecture())
#endif
#endif

    /**
     *  NewQDPixUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    QDPixUPP
    NewQDPixUPP(QDPixProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
    enum
    {
        uppQDPixProcInfo = 0x002FEFC0
    }; /** pascal no_return_value Func(4_bytes, 4_bytes, 4_bytes, 2_bytes, 4_bytes,
          4_bytes, 4_bytes, 2_bytes) */
#ifdef __cplusplus
    inline QDPixUPP NewQDPixUPP(QDPixProcPtr userRoutine)
    {
        return (QDPixUPP)NewRoutineDescriptor(
            (ProcPtr)(userRoutine), uppQDPixProcInfo, GetCurrentArchitecture());
    }
#else
#define NewQDPixUPP(userRoutine)                                              \
    (QDPixUPP) NewRoutineDescriptor((ProcPtr)(userRoutine), uppQDPixProcInfo, \
                                    GetCurrentArchitecture())
#endif
#endif

    /**
     *  NewICMAlignmentUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    ICMAlignmentUPP
    NewICMAlignmentUPP(ICMAlignmentProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
    enum
    {
        uppICMAlignmentProcInfo = 0x000003C0
    }; /** pascal no_return_value Func(4_bytes, 4_bytes) */
#ifdef __cplusplus
    inline ICMAlignmentUPP NewICMAlignmentUPP(ICMAlignmentProcPtr userRoutine)
    {
        return (ICMAlignmentUPP)NewRoutineDescriptor((ProcPtr)(userRoutine),
                                                     uppICMAlignmentProcInfo,
                                                     GetCurrentArchitecture());
    }
#else
#define NewICMAlignmentUPP(userRoutine)                                       \
    (ICMAlignmentUPP)                                                         \
        NewRoutineDescriptor((ProcPtr)(userRoutine), uppICMAlignmentProcInfo, \
                             GetCurrentArchitecture())
#endif
#endif

    /**
     *  NewICMCursorShieldedUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    ICMCursorShieldedUPP
    NewICMCursorShieldedUPP(ICMCursorShieldedProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
    enum
    {
        uppICMCursorShieldedProcInfo = 0x00000FC0
    }; /** pascal no_return_value Func(4_bytes, 4_bytes, 4_bytes) */
#ifdef __cplusplus
    inline ICMCursorShieldedUPP
    NewICMCursorShieldedUPP(ICMCursorShieldedProcPtr userRoutine)
    {
        return (ICMCursorShieldedUPP)NewRoutineDescriptor(
            (ProcPtr)(userRoutine), uppICMCursorShieldedProcInfo,
            GetCurrentArchitecture());
    }
#else
#define NewICMCursorShieldedUPP(userRoutine)                                  \
    (ICMCursorShieldedUPP) NewRoutineDescriptor((ProcPtr)(userRoutine),       \
                                                uppICMCursorShieldedProcInfo, \
                                                GetCurrentArchitecture())
#endif
#endif

    /**
     *  NewICMMemoryDisposedUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    ICMMemoryDisposedUPP
    NewICMMemoryDisposedUPP(ICMMemoryDisposedProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
    enum
    {
        uppICMMemoryDisposedProcInfo = 0x000003C0
    }; /** pascal no_return_value Func(4_bytes, 4_bytes) */
#ifdef __cplusplus
    inline ICMMemoryDisposedUPP
    NewICMMemoryDisposedUPP(ICMMemoryDisposedProcPtr userRoutine)
    {
        return (ICMMemoryDisposedUPP)NewRoutineDescriptor(
            (ProcPtr)(userRoutine), uppICMMemoryDisposedProcInfo,
            GetCurrentArchitecture());
    }
#else
#define NewICMMemoryDisposedUPP(userRoutine)                                  \
    (ICMMemoryDisposedUPP) NewRoutineDescriptor((ProcPtr)(userRoutine),       \
                                                uppICMMemoryDisposedProcInfo, \
                                                GetCurrentArchitecture())
#endif
#endif

    /**
     *  NewICMConvertDataFormatUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    ICMConvertDataFormatUPP
    NewICMConvertDataFormatUPP(ICMConvertDataFormatProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
    enum
    {
        uppICMConvertDataFormatProcInfo = 0x003FFFE0
    }; /** pascal 2_bytes Func(4_bytes, 4_bytes, 4_bytes, 4_bytes, 4_bytes, 4_bytes,
          4_bytes, 4_bytes) */
#ifdef __cplusplus
    inline ICMConvertDataFormatUPP
    NewICMConvertDataFormatUPP(ICMConvertDataFormatProcPtr userRoutine)
    {
        return (ICMConvertDataFormatUPP)NewRoutineDescriptor(
            (ProcPtr)(userRoutine), uppICMConvertDataFormatProcInfo,
            GetCurrentArchitecture());
    }
#else
#define NewICMConvertDataFormatUPP(userRoutine)                  \
    (ICMConvertDataFormatUPP) NewRoutineDescriptor(              \
        (ProcPtr)(userRoutine), uppICMConvertDataFormatProcInfo, \
        GetCurrentArchitecture())
#endif
#endif

    /**
     *  DisposeICMDataUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    DisposeICMDataUPP(ICMDataUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline void DisposeICMDataUPP(ICMDataUPP userUPP)
    {
        DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
    }
#else
#define DisposeICMDataUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

    /**
     *  DisposeICMFlushUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    DisposeICMFlushUPP(ICMFlushUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline void DisposeICMFlushUPP(ICMFlushUPP userUPP)
    {
        DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
    }
#else
#define DisposeICMFlushUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

    /**
     *  DisposeICMCompletionUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    DisposeICMCompletionUPP(ICMCompletionUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline void DisposeICMCompletionUPP(ICMCompletionUPP userUPP)
    {
        DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
    }
#else
#define DisposeICMCompletionUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

    /**
     *  DisposeICMProgressUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    DisposeICMProgressUPP(ICMProgressUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline void DisposeICMProgressUPP(ICMProgressUPP userUPP)
    {
        DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
    }
#else
#define DisposeICMProgressUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

    /**
     *  DisposeStdPixUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    DisposeStdPixUPP(StdPixUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline void DisposeStdPixUPP(StdPixUPP userUPP)
    {
        DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
    }
#else
#define DisposeStdPixUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

    /**
     *  DisposeQDPixUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    DisposeQDPixUPP(QDPixUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline void DisposeQDPixUPP(QDPixUPP userUPP)
    {
        DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
    }
#else
#define DisposeQDPixUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

    /**
     *  DisposeICMAlignmentUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    DisposeICMAlignmentUPP(ICMAlignmentUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline void DisposeICMAlignmentUPP(ICMAlignmentUPP userUPP)
    {
        DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
    }
#else
#define DisposeICMAlignmentUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

    /**
     *  DisposeICMCursorShieldedUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    DisposeICMCursorShieldedUPP(ICMCursorShieldedUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline void DisposeICMCursorShieldedUPP(ICMCursorShieldedUPP userUPP)
    {
        DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
    }
#else
#define DisposeICMCursorShieldedUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

    /**
     *  DisposeICMMemoryDisposedUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    DisposeICMMemoryDisposedUPP(ICMMemoryDisposedUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline void DisposeICMMemoryDisposedUPP(ICMMemoryDisposedUPP userUPP)
    {
        DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
    }
#else
#define DisposeICMMemoryDisposedUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

    /**
     *  DisposeICMConvertDataFormatUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    DisposeICMConvertDataFormatUPP(ICMConvertDataFormatUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline void DisposeICMConvertDataFormatUPP(ICMConvertDataFormatUPP userUPP)
    {
        DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
    }
#else
#define DisposeICMConvertDataFormatUPP(userUPP) \
    DisposeRoutineDescriptor(userUPP)
#endif
#endif

    /**
     *  InvokeICMDataUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    InvokeICMDataUPP(Ptr *dataP, long bytesNeeded, long refcon, ICMDataUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline OSErr InvokeICMDataUPP(Ptr *dataP, long bytesNeeded, long refcon,
                                  ICMDataUPP userUPP)
    {
        return (OSErr)CALL_THREE_PARAMETER_UPP(userUPP, uppICMDataProcInfo, dataP,
                                               bytesNeeded, refcon);
    }
#else
#define InvokeICMDataUPP(dataP, bytesNeeded, refcon, userUPP)                \
    (OSErr) CALL_THREE_PARAMETER_UPP((userUPP), uppICMDataProcInfo, (dataP), \
                                     (bytesNeeded), (refcon))
#endif
#endif

    /**
     *  InvokeICMFlushUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    InvokeICMFlushUPP(Ptr data, long bytesAdded, long refcon, ICMFlushUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline OSErr InvokeICMFlushUPP(Ptr data, long bytesAdded, long refcon,
                                   ICMFlushUPP userUPP)
    {
        return (OSErr)CALL_THREE_PARAMETER_UPP(userUPP, uppICMFlushProcInfo, data,
                                               bytesAdded, refcon);
    }
#else
#define InvokeICMFlushUPP(data, bytesAdded, refcon, userUPP)                 \
    (OSErr) CALL_THREE_PARAMETER_UPP((userUPP), uppICMFlushProcInfo, (data), \
                                     (bytesAdded), (refcon))
#endif
#endif

    /**
     *  InvokeICMCompletionUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    InvokeICMCompletionUPP(OSErr result, short flags, long refcon,
                           ICMCompletionUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline void InvokeICMCompletionUPP(OSErr result, short flags, long refcon,
                                       ICMCompletionUPP userUPP)
    {
        CALL_THREE_PARAMETER_UPP(userUPP, uppICMCompletionProcInfo, result, flags,
                                 refcon);
    }
#else
#define InvokeICMCompletionUPP(result, flags, refcon, userUPP)              \
    CALL_THREE_PARAMETER_UPP((userUPP), uppICMCompletionProcInfo, (result), \
                             (flags), (refcon))
#endif
#endif

    /**
     *  InvokeICMProgressUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    InvokeICMProgressUPP(short message, Fixed completeness, long refcon,
                         ICMProgressUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline OSErr InvokeICMProgressUPP(short message, Fixed completeness,
                                      long refcon, ICMProgressUPP userUPP)
    {
        return (OSErr)CALL_THREE_PARAMETER_UPP(userUPP, uppICMProgressProcInfo,
                                               message, completeness, refcon);
    }
#else
#define InvokeICMProgressUPP(message, completeness, refcon, userUPP)    \
    (OSErr) CALL_THREE_PARAMETER_UPP((userUPP), uppICMProgressProcInfo, \
                                     (message), (completeness), (refcon))
#endif
#endif

    /**
     *  InvokeStdPixUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    InvokeStdPixUPP(PixMap *src, Rect *srcRect, MatrixRecord *matrix, short mode,
                    RgnHandle mask, PixMap *matte, Rect *matteRect, short flags,
                    StdPixUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline void InvokeStdPixUPP(PixMap *src, Rect *srcRect, MatrixRecord *matrix,
                                short mode, RgnHandle mask, PixMap *matte,
                                Rect *matteRect, short flags, StdPixUPP userUPP)
    {
        CALL_EIGHT_PARAMETER_UPP(userUPP, uppStdPixProcInfo, src, srcRect, matrix,
                                 mode, mask, matte, matteRect, flags);
    }
#else
#define InvokeStdPixUPP(src, srcRect, matrix, mode, mask, matte, matteRect,  \
                        flags, userUPP)                                      \
    CALL_EIGHT_PARAMETER_UPP((userUPP), uppStdPixProcInfo, (src), (srcRect), \
                             (matrix), (mode), (mask), (matte), (matteRect), \
                             (flags))
#endif
#endif

    /**
     *  InvokeQDPixUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    InvokeQDPixUPP(PixMap *src, Rect *srcRect, MatrixRecord *matrix, short mode,
                   RgnHandle mask, PixMap *matte, Rect *matteRect, short flags,
                   QDPixUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline void InvokeQDPixUPP(PixMap *src, Rect *srcRect, MatrixRecord *matrix,
                               short mode, RgnHandle mask, PixMap *matte,
                               Rect *matteRect, short flags, QDPixUPP userUPP)
    {
        CALL_EIGHT_PARAMETER_UPP(userUPP, uppQDPixProcInfo, src, srcRect, matrix,
                                 mode, mask, matte, matteRect, flags);
    }
#else
#define InvokeQDPixUPP(src, srcRect, matrix, mode, mask, matte, matteRect,   \
                       flags, userUPP)                                       \
    CALL_EIGHT_PARAMETER_UPP((userUPP), uppQDPixProcInfo, (src), (srcRect),  \
                             (matrix), (mode), (mask), (matte), (matteRect), \
                             (flags))
#endif
#endif

    /**
     *  InvokeICMAlignmentUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    InvokeICMAlignmentUPP(Rect *rp, long refcon, ICMAlignmentUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline void InvokeICMAlignmentUPP(Rect *rp, long refcon,
                                      ICMAlignmentUPP userUPP)
    {
        CALL_TWO_PARAMETER_UPP(userUPP, uppICMAlignmentProcInfo, rp, refcon);
    }
#else
#define InvokeICMAlignmentUPP(rp, refcon, userUPP) \
    CALL_TWO_PARAMETER_UPP((userUPP), uppICMAlignmentProcInfo, (rp), (refcon))
#endif
#endif

    /**
     *  InvokeICMCursorShieldedUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    InvokeICMCursorShieldedUPP(const Rect *r, void *refcon, long flags,
                               ICMCursorShieldedUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline void InvokeICMCursorShieldedUPP(const Rect *r, void *refcon, long flags,
                                           ICMCursorShieldedUPP userUPP)
    {
        CALL_THREE_PARAMETER_UPP(userUPP, uppICMCursorShieldedProcInfo, r, refcon,
                                 flags);
    }
#else
#define InvokeICMCursorShieldedUPP(r, refcon, flags, userUPP)              \
    CALL_THREE_PARAMETER_UPP((userUPP), uppICMCursorShieldedProcInfo, (r), \
                             (refcon), (flags))
#endif
#endif

    /**
     *  InvokeICMMemoryDisposedUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    InvokeICMMemoryDisposedUPP(Ptr memoryBlock, void *refcon,
                               ICMMemoryDisposedUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline void InvokeICMMemoryDisposedUPP(Ptr memoryBlock, void *refcon,
                                           ICMMemoryDisposedUPP userUPP)
    {
        CALL_TWO_PARAMETER_UPP(userUPP, uppICMMemoryDisposedProcInfo, memoryBlock,
                               refcon);
    }
#else
#define InvokeICMMemoryDisposedUPP(memoryBlock, refcon, userUPP)    \
    CALL_TWO_PARAMETER_UPP((userUPP), uppICMMemoryDisposedProcInfo, \
                           (memoryBlock), (refcon))
#endif
#endif

    /**
     *  InvokeICMConvertDataFormatUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    InvokeICMConvertDataFormatUPP(void *refCon, long flags, Handle desiredFormat,
                                  Handle sourceDataFormat, void *srcData,
                                  long srcDataSize, void **dstData,
                                  long *dstDataSize,
                                  ICMConvertDataFormatUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline OSErr InvokeICMConvertDataFormatUPP(void *refCon, long flags,
                                               Handle desiredFormat,
                                               Handle sourceDataFormat,
                                               void *srcData, long srcDataSize,
                                               void **dstData, long *dstDataSize,
                                               ICMConvertDataFormatUPP userUPP)
    {
        return (OSErr)CALL_EIGHT_PARAMETER_UPP(
            userUPP, uppICMConvertDataFormatProcInfo, refCon, flags, desiredFormat,
            sourceDataFormat, srcData, srcDataSize, dstData, dstDataSize);
    }
#else
#define InvokeICMConvertDataFormatUPP(refCon, flags, desiredFormat,              \
                                      sourceDataFormat, srcData, srcDataSize,    \
                                      dstData, dstDataSize, userUPP)             \
    (OSErr) CALL_EIGHT_PARAMETER_UPP((userUPP), uppICMConvertDataFormatProcInfo, \
                                     (refCon), (flags), (desiredFormat),         \
                                     (sourceDataFormat), (srcData),              \
                                     (srcDataSize), (dstData), (dstDataSize))
#endif
#endif

#if CALL_NOT_IN_CARBON || OLDROUTINENAMES
/** support for pre-Carbon UPP routines: New...Proc and Call...Proc */
#define NewICMDataProc(userRoutine) NewICMDataUPP(userRoutine)
#define NewICMFlushProc(userRoutine) NewICMFlushUPP(userRoutine)
#define NewICMCompletionProc(userRoutine) NewICMCompletionUPP(userRoutine)
#define NewICMProgressProc(userRoutine) NewICMProgressUPP(userRoutine)
#define NewStdPixProc(userRoutine) NewStdPixUPP(userRoutine)
#define NewQDPixProc(userRoutine) NewQDPixUPP(userRoutine)
#define NewICMAlignmentProc(userRoutine) NewICMAlignmentUPP(userRoutine)
#define NewICMCursorShieldedProc(userRoutine) \
    NewICMCursorShieldedUPP(userRoutine)
#define NewICMMemoryDisposedProc(userRoutine) \
    NewICMMemoryDisposedUPP(userRoutine)
#define NewICMConvertDataFormatProc(userRoutine) \
    NewICMConvertDataFormatUPP(userRoutine)
#define CallICMDataProc(userRoutine, dataP, bytesNeeded, refcon) \
    InvokeICMDataUPP(dataP, bytesNeeded, refcon, userRoutine)
#define CallICMFlushProc(userRoutine, data, bytesAdded, refcon) \
    InvokeICMFlushUPP(data, bytesAdded, refcon, userRoutine)
#define CallICMCompletionProc(userRoutine, result, flags, refcon) \
    InvokeICMCompletionUPP(result, flags, refcon, userRoutine)
#define CallICMProgressProc(userRoutine, message, completeness, refcon) \
    InvokeICMProgressUPP(message, completeness, refcon, userRoutine)
#define CallStdPixProc(userRoutine, src, srcRect, matrix, mode, mask, matte,   \
                       matteRect, flags)                                       \
    InvokeStdPixUPP(src, srcRect, matrix, mode, mask, matte, matteRect, flags, \
                    userRoutine)
#define CallQDPixProc(userRoutine, src, srcRect, matrix, mode, mask, matte,   \
                      matteRect, flags)                                       \
    InvokeQDPixUPP(src, srcRect, matrix, mode, mask, matte, matteRect, flags, \
                   userRoutine)
#define CallICMAlignmentProc(userRoutine, rp, refcon) \
    InvokeICMAlignmentUPP(rp, refcon, userRoutine)
#define CallICMCursorShieldedProc(userRoutine, r, refcon, flags) \
    InvokeICMCursorShieldedUPP(r, refcon, flags, userRoutine)
#define CallICMMemoryDisposedProc(userRoutine, memoryBlock, refcon) \
    InvokeICMMemoryDisposedUPP(memoryBlock, refcon, userRoutine)
#define CallICMConvertDataFormatProc(userRoutine, refCon, flags,               \
                                     desiredFormat, sourceDataFormat, srcData, \
                                     srcDataSize, dstData, dstDataSize)        \
    InvokeICMConvertDataFormatUPP(refCon, flags, desiredFormat,                \
                                  sourceDataFormat, srcData, srcDataSize,      \
                                  dstData, dstDataSize, userRoutine)
#endif /** CALL_NOT_IN_CARBON */

    /**
     *  CodecManagerVersion()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    CodecManagerVersion(long *version);

    /**
     *  GetCodecNameList()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    GetCodecNameList(CodecNameSpecListPtr *list, short showAll);

    /**
     *  DisposeCodecNameList()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    DisposeCodecNameList(CodecNameSpecListPtr list);

    /**
     *  GetCodecInfo()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    GetCodecInfo(CodecInfo *info, CodecType cType, CodecComponent codec);

    /**
     *  GetMaxCompressionSize()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    GetMaxCompressionSize(PixMapHandle src, const Rect *srcRect, short colorDepth,
                          CodecQ quality, CodecType cType,
                          CompressorComponent codec, long *size);

    /**
     *  GetCSequenceMaxCompressionSize()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    GetCSequenceMaxCompressionSize(ImageSequence seqID, PixMapHandle src,
                                   long *size);

    /**
     *  GetCompressionTime()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    GetCompressionTime(PixMapHandle src, const Rect *srcRect, short colorDepth,
                       CodecType cType, CompressorComponent codec,
                       CodecQ *spatialQuality, CodecQ *temporalQuality,
                       unsigned long *compressTime);

    /**
     *  CompressImage()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    CompressImage(PixMapHandle src, const Rect *srcRect, CodecQ quality,
                  CodecType cType, ImageDescriptionHandle desc, Ptr data);

    /**
     *  FCompressImage()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    FCompressImage(PixMapHandle src, const Rect *srcRect, short colorDepth,
                   CodecQ quality, CodecType cType, CompressorComponent codec,
                   CTabHandle ctable, CodecFlags flags, long bufferSize,
                   ICMFlushProcRecordPtr flushProc,
                   ICMProgressProcRecordPtr progressProc,
                   ImageDescriptionHandle desc, Ptr data);

    /**
     *  DecompressImage()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    DecompressImage(Ptr data, ImageDescriptionHandle desc, PixMapHandle dst,
                    const Rect *srcRect, const Rect *dstRect, short mode,
                    RgnHandle mask);

    /**
     *  FDecompressImage()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    FDecompressImage(Ptr data, ImageDescriptionHandle desc, PixMapHandle dst,
                     const Rect *srcRect, MatrixRecordPtr matrix, short mode,
                     RgnHandle mask, PixMapHandle matte, const Rect *matteRect,
                     CodecQ accuracy, DecompressorComponent codec, long bufferSize,
                     ICMDataProcRecordPtr dataProc,
                     ICMProgressProcRecordPtr progressProc);

    /**
     *  CompressSequenceBegin()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    CompressSequenceBegin(ImageSequence *seqID, PixMapHandle src, PixMapHandle prev,
                          const Rect *srcRect, const Rect *prevRect,
                          short colorDepth, CodecType cType,
                          CompressorComponent codec, CodecQ spatialQuality,
                          CodecQ temporalQuality, long keyFrameRate,
                          CTabHandle ctable, CodecFlags flags,
                          ImageDescriptionHandle desc);

    /**
     *  CompressSequenceFrame()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    CompressSequenceFrame(ImageSequence seqID, PixMapHandle src,
                          const Rect *srcRect, CodecFlags flags, Ptr data,
                          long *dataSize, UInt8 *similarity,
                          ICMCompletionProcRecordPtr asyncCompletionProc);

    /**
     *  DecompressSequenceBegin()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    DecompressSequenceBegin(ImageSequence *seqID, ImageDescriptionHandle desc,
                            CGrafPtr port, GDHandle gdh, const Rect *srcRect,
                            MatrixRecordPtr matrix, short mode, RgnHandle mask,
                            CodecFlags flags, CodecQ accuracy,
                            DecompressorComponent codec);

    /**
     *  DecompressSequenceBeginS()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    DecompressSequenceBeginS(ImageSequence *seqID, ImageDescriptionHandle desc,
                             Ptr data, long dataSize, CGrafPtr port, GDHandle gdh,
                             const Rect *srcRect, MatrixRecordPtr matrix,
                             short mode, RgnHandle mask, CodecFlags flags,
                             CodecQ accuracy, DecompressorComponent codec);

    /**
     *  DecompressSequenceFrame()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    DecompressSequenceFrame(ImageSequence seqID, Ptr data, CodecFlags inFlags,
                            CodecFlags *outFlags,
                            ICMCompletionProcRecordPtr asyncCompletionProc);

    /**
     *  DecompressSequenceFrameS()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    DecompressSequenceFrameS(ImageSequence seqID, Ptr data, long dataSize,
                             CodecFlags inFlags, CodecFlags *outFlags,
                             ICMCompletionProcRecordPtr asyncCompletionProc);

    /**
     *  DecompressSequenceFrameWhen()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    DecompressSequenceFrameWhen(ImageSequence seqID, Ptr data, long dataSize,
                                CodecFlags inFlags, CodecFlags *outFlags,
                                ICMCompletionProcRecordPtr asyncCompletionProc,
                                const ICMFrameTimeRecord *frameTime);

    /**
     *  CDSequenceFlush()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    CDSequenceFlush(ImageSequence seqID);

    /**
     *  SetDSequenceMatrix()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    SetDSequenceMatrix(ImageSequence seqID, MatrixRecordPtr matrix);

    /**
     *  GetDSequenceMatrix()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    OSErr
    GetDSequenceMatrix(ImageSequence seqID, MatrixRecordPtr matrix);

    /**
     *  SetDSequenceMatte()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    SetDSequenceMatte(ImageSequence seqID, PixMapHandle matte,
                      const Rect *matteRect);

    /**
     *  SetDSequenceMask()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    SetDSequenceMask(ImageSequence seqID, RgnHandle mask);

    /**
     *  SetDSequenceTransferMode()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    SetDSequenceTransferMode(ImageSequence seqID, short mode,
                             const RGBColor *opColor);

    /**
     *  SetDSequenceDataProc()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    SetDSequenceDataProc(ImageSequence seqID, ICMDataProcRecordPtr dataProc,
                         long bufferSize);

    /**
     *  SetDSequenceAccuracy()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    SetDSequenceAccuracy(ImageSequence seqID, CodecQ accuracy);

    /**
     *  SetDSequenceSrcRect()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    SetDSequenceSrcRect(ImageSequence seqID, const Rect *srcRect);

    /**
     *  SetDSequenceFlags()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    OSErr
    SetDSequenceFlags(ImageSequence seqID, long flags, long flagsMask);

    enum
    {
        codecDSequenceSingleField = (1L << 6)
    };

    typedef CodecComponent *CodecComponentPtr;
    typedef CodecComponentPtr *CodecComponentHandle;
    enum
    {
        kICMSequenceTaskWeight =
            FOUR_CHAR_CODE('twei'),                    /** data is pointer to UInt32*/
        kICMSequenceTaskName = FOUR_CHAR_CODE('tnam'), /** data is pointer to OSType*/
        kICMSequenceUserPreferredCodecs =
            FOUR_CHAR_CODE('punt') /** data is pointer to CodecComponentHandle*/
    };

    /**
     *  ICMSequenceGetInfo()
     *

     *    \non_carbon_cfm   in QuickTimeLib 5.0 and later
     *    \carbon_lib        in CarbonLib 1.3 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 5.0 and later
     */
    OSErr
    ICMSequenceGetInfo(ImageSequence seqID, OSType which, void *data);

    /**
     *  ICMSequenceSetInfo()
     *

     *    \non_carbon_cfm   in QuickTimeLib 5.0 and later
     *    \carbon_lib        in CarbonLib 1.3 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 5.0 and later
     */
    OSErr
    ICMSequenceSetInfo(ImageSequence seqID, OSType which, void *data, Size dataSize);

    /**
     *  GetDSequenceImageBuffer()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    GetDSequenceImageBuffer(ImageSequence seqID, GWorldPtr *gworld);

    /**
     *  GetDSequenceScreenBuffer()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    GetDSequenceScreenBuffer(ImageSequence seqID, GWorldPtr *gworld);

    /**
     *  SetCSequenceQuality()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    SetCSequenceQuality(ImageSequence seqID, CodecQ spatialQuality,
                        CodecQ temporalQuality);

    /**
     *  SetCSequencePrev()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    SetCSequencePrev(ImageSequence seqID, PixMapHandle prev, const Rect *prevRect);

    /**
     *  SetCSequenceFlushProc()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    SetCSequenceFlushProc(ImageSequence seqID, ICMFlushProcRecordPtr flushProc,
                          long bufferSize);

    /**
     *  SetCSequenceKeyFrameRate()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    SetCSequenceKeyFrameRate(ImageSequence seqID, long keyFrameRate);

    /**
     *  GetCSequenceKeyFrameRate()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    GetCSequenceKeyFrameRate(ImageSequence seqID, long *keyFrameRate);

    /**
     *  GetCSequencePrevBuffer()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    GetCSequencePrevBuffer(ImageSequence seqID, GWorldPtr *gworld);

    /**
     *  CDSequenceBusy()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    CDSequenceBusy(ImageSequence seqID);

    /**
     *  CDSequenceEnd()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    CDSequenceEnd(ImageSequence seqID);

    /**
     *  CDSequenceEquivalentImageDescription()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    CDSequenceEquivalentImageDescription(ImageSequence seqID,
                                         ImageDescriptionHandle newDesc,
                                         Boolean *equivalent);

    /**
     *  CDSequenceEquivalentImageDescriptionS()
     *

     *    \non_carbon_cfm   in QuickTimeLib 5.0 and later
     *    \carbon_lib        in CarbonLib 1.3 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 5.0 and later
     */
    OSErr
    CDSequenceEquivalentImageDescriptionS(ImageSequence seqID,
                                          ImageDescriptionHandle newDesc,
                                          Boolean *equivalent, Boolean *canSwitch);

    /**
     *  ReplaceDSequenceImageDescription()
     *

     *    \non_carbon_cfm   in QuickTimeLib 5.0 and later
     *    \carbon_lib        in CarbonLib 1.3 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 5.0 and later
     */
    OSErr
    ReplaceDSequenceImageDescription(ImageSequence seqID,
                                     ImageDescriptionHandle newDesc);

    /**
     *  GetCompressedImageSize()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    GetCompressedImageSize(ImageDescriptionHandle desc, Ptr data, long bufferSize,
                           ICMDataProcRecordPtr dataProc, long *dataSize);

    /**
     *  GetSimilarity()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    GetSimilarity(PixMapHandle src, const Rect *srcRect,
                  ImageDescriptionHandle desc, Ptr data, Fixed *similarity);

    enum
    {
        kImageDescriptionSampleFormat = FOUR_CHAR_CODE(
            'idfm'), /** image description extension describing sample format*/
        kImageDescriptionClassicAtomFormat =
            FOUR_CHAR_CODE('atom'), /** sample contains classic atom structure (ie, GX
                                       codec and Curve codec)*/
        kImageDescriptionQTAtomFormat =
            FOUR_CHAR_CODE('qtat'), /** sample contains QT atom structure*/
        kImageDescriptionEffectDataFormat =
            FOUR_CHAR_CODE('fxat'), /** sample describes an effect (as QTAtoms)*/
        kImageDescriptionPrivateDataFormat =
            FOUR_CHAR_CODE('priv'), /** sample is in a private codec specific format*/
        kImageDescriptionAlternateCodec = FOUR_CHAR_CODE(
            'subs'), /** image description extension containing the OSType of a
                        substitute codec should the main codec not be available*/
        kImageDescriptionColorSpace = FOUR_CHAR_CODE(
            'cspc') /** image description extension containing an OSType naming the
                       native pixel format of an image (only used for pixel formats
                       not supported by classic Color QuickDraw)*/
    };

    /**
     *  GetImageDescriptionCTable()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    GetImageDescriptionCTable(ImageDescriptionHandle desc, CTabHandle *ctable);

    /**
     *  SetImageDescriptionCTable()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    SetImageDescriptionCTable(ImageDescriptionHandle desc, CTabHandle ctable);

    /**
     *  GetImageDescriptionExtension()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    GetImageDescriptionExtension(ImageDescriptionHandle desc, Handle *extension,
                                 long idType, long index);

    /**
     *  AddImageDescriptionExtension()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    AddImageDescriptionExtension(ImageDescriptionHandle desc, Handle extension,
                                 long idType);

    /**
     *  RemoveImageDescriptionExtension()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    RemoveImageDescriptionExtension(ImageDescriptionHandle desc, long idType,
                                    long index);

    /**
     *  CountImageDescriptionExtensionType()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    CountImageDescriptionExtensionType(ImageDescriptionHandle desc, long idType,
                                       long *count);

    /**
     *  GetNextImageDescriptionExtensionType()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    GetNextImageDescriptionExtensionType(ImageDescriptionHandle desc, long *idType);

    /**
     *  FindCodec()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    FindCodec(CodecType cType, CodecComponent specCodec,
              CompressorComponent *compressor, DecompressorComponent *decompressor);

    /**
     *  CompressPicture()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    CompressPicture(PicHandle srcPicture, PicHandle dstPicture, CodecQ quality,
                    CodecType cType);

    /**
     *  FCompressPicture()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    FCompressPicture(PicHandle srcPicture, PicHandle dstPicture, short colorDepth,
                     CTabHandle ctable, CodecQ quality, short doDither,
                     short compressAgain, ICMProgressProcRecordPtr progressProc,
                     CodecType cType, CompressorComponent codec);

    /**
     *  CompressPictureFile()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    CompressPictureFile(short srcRefNum, short dstRefNum, CodecQ quality,
                        CodecType cType);

    /**
     *  FCompressPictureFile()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    FCompressPictureFile(short srcRefNum, short dstRefNum, short colorDepth,
                         CTabHandle ctable, CodecQ quality, short doDither,
                         short compressAgain, ICMProgressProcRecordPtr progressProc,
                         CodecType cType, CompressorComponent codec);

    /**
     *  GetPictureFileHeader()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    GetPictureFileHeader(short refNum, Rect *frame, OpenCPicParams *header);

    /**
     *  DrawPictureFile()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    DrawPictureFile(short refNum, const Rect *frame,
                    ICMProgressProcRecordPtr progressProc);

    /**
     *  DrawTrimmedPicture()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    DrawTrimmedPicture(PicHandle srcPicture, const Rect *frame, RgnHandle trimMask,
                       short doDither, ICMProgressProcRecordPtr progressProc);

    /**
     *  DrawTrimmedPictureFile()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    DrawTrimmedPictureFile(short srcRefnum, const Rect *frame, RgnHandle trimMask,
                           short doDither, ICMProgressProcRecordPtr progressProc);

    /**
     *  MakeThumbnailFromPicture()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    MakeThumbnailFromPicture(PicHandle picture, short colorDepth,
                             PicHandle thumbnail,
                             ICMProgressProcRecordPtr progressProc);

    /**
     *  MakeThumbnailFromPictureFile()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    MakeThumbnailFromPictureFile(short refNum, short colorDepth,
                                 PicHandle thumbnail,
                                 ICMProgressProcRecordPtr progressProc);

    /**
     *  MakeThumbnailFromPixMap()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    MakeThumbnailFromPixMap(PixMapHandle src, const Rect *srcRect, short colorDepth,
                            PicHandle thumbnail,
                            ICMProgressProcRecordPtr progressProc);

    /**
     *  TrimImage()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    TrimImage(ImageDescriptionHandle desc, Ptr inData, long inBufferSize,
              ICMDataProcRecordPtr dataProc, Ptr outData, long outBufferSize,
              ICMFlushProcRecordPtr flushProc, Rect *trimRect,
              ICMProgressProcRecordPtr progressProc);

    /**
     *  ConvertImage()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    ConvertImage(ImageDescriptionHandle srcDD, Ptr srcData, short colorDepth,
                 CTabHandle ctable, CodecQ accuracy, CodecQ quality,
                 CodecType cType, CodecComponent codec,
                 ImageDescriptionHandle dstDD, Ptr dstData);

    /**
     *  GetCompressedPixMapInfo()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    GetCompressedPixMapInfo(PixMapPtr pix, ImageDescriptionHandle *desc, Ptr *data,
                            long *bufferSize, ICMDataProcRecord *dataProc,
                            ICMProgressProcRecord *progressProc);

    /**
     *  SetCompressedPixMapInfo()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    SetCompressedPixMapInfo(PixMapPtr pix, ImageDescriptionHandle desc, Ptr data,
                            long bufferSize, ICMDataProcRecordPtr dataProc,
                            ICMProgressProcRecordPtr progressProc);

    /**
     *  StdPix()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    StdPix(PixMapPtr src, const Rect *srcRect, MatrixRecordPtr matrix, short mode,
           RgnHandle mask, PixMapPtr matte, const Rect *matteRect, short flags);

    /**
     *  TransformRgn()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    TransformRgn(MatrixRecordPtr matrix, RgnHandle rgn);

/************
    preview stuff
***********/
#if CALL_NOT_IN_CARBON
    /**
     *  SFGetFilePreview()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SFGetFilePreview(Point where, ConstStr255Param prompt, FileFilterUPP fileFilter,
                     short numTypes, ConstSFTypeListPtr typeList,
                     DlgHookUPP dlgHook, SFReply *reply);

    /**
     *  SFPGetFilePreview()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SFPGetFilePreview(Point where, ConstStr255Param prompt,
                      FileFilterUPP fileFilter, short numTypes,
                      ConstSFTypeListPtr typeList, DlgHookUPP dlgHook,
                      SFReply *reply, short dlgID, ModalFilterUPP filterProc);

    /**
     *  StandardGetFilePreview()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    StandardGetFilePreview(FileFilterUPP fileFilter, short numTypes,
                           ConstSFTypeListPtr typeList, StandardFileReply *reply);

    /**
     *  CustomGetFilePreview()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    CustomGetFilePreview(FileFilterYDUPP fileFilter, short numTypes,
                         ConstSFTypeListPtr typeList, StandardFileReply *reply,
                         short dlgID, Point where, DlgHookYDUPP dlgHook,
                         ModalFilterYDUPP filterProc,
                         ActivationOrderListPtr activeList,
                         ActivateYDUPP activateProc, void *yourDataPtr);

#endif /** CALL_NOT_IN_CARBON */

    /**
     *  MakeFilePreview()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    MakeFilePreview(short resRefNum, ICMProgressProcRecordPtr progress);

    /**
     *  AddFilePreview()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    AddFilePreview(short resRefNum, OSType previewType, Handle previewData);

    enum
    {
        sfpItemPreviewAreaUser = 11,
        sfpItemPreviewStaticText = 12,
        sfpItemPreviewDividerUser = 13,
        sfpItemCreatePreviewButton = 14,
        sfpItemShowPreviewButton = 15
    };

    struct PreviewResourceRecord
    {
        unsigned long modDate;
        short version;
        OSType resType;
        short resID;
    };
    typedef struct PreviewResourceRecord PreviewResourceRecord;
    typedef PreviewResourceRecord *PreviewResourcePtr;
    typedef PreviewResourcePtr *PreviewResource;
    /**
     *  AlignScreenRect()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    AlignScreenRect(Rect *rp, ICMAlignmentProcRecordPtr alignmentProc);

    /**
     *  AlignWindow()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    AlignWindow(WindowRef wp, Boolean front, const Rect *alignmentRect,
                ICMAlignmentProcRecordPtr alignmentProc);

    /**
     *  DragAlignedWindow()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    DragAlignedWindow(WindowRef wp, Point startPt, Rect *boundsRect,
                      Rect *alignmentRect, ICMAlignmentProcRecordPtr alignmentProc);

    /**
     *  DragAlignedGrayRgn()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    long
    DragAlignedGrayRgn(RgnHandle theRgn, Point startPt, Rect *boundsRect,
                       Rect *slopRect, short axis, UniversalProcPtr actionProc,
                       Rect *alignmentRect, ICMAlignmentProcRecordPtr alignmentProc);

    /**
     *  SetCSequenceDataRateParams()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    SetCSequenceDataRateParams(ImageSequence seqID, DataRateParamsPtr params);

    /**
     *  SetCSequenceFrameNumber()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    SetCSequenceFrameNumber(ImageSequence seqID, long frameNumber);

    /**
     *  SetCSequencePreferredPacketSize()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    SetCSequencePreferredPacketSize(ImageSequence seqID,
                                    long preferredPacketSizeInBytes);

    /**
     *  NewImageGWorld()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    NewImageGWorld(GWorldPtr *gworld, ImageDescriptionHandle idh, GWorldFlags flags);

    /**
     *  GetCSequenceDataRateParams()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    GetCSequenceDataRateParams(ImageSequence seqID, DataRateParamsPtr params);

    /**
     *  GetCSequenceFrameNumber()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    GetCSequenceFrameNumber(ImageSequence seqID, long *frameNumber);

    /**
     *  GetBestDeviceRect()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    GetBestDeviceRect(GDHandle *gdh, Rect *rp);

    /**
     *  SetSequenceProgressProc()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    SetSequenceProgressProc(ImageSequence seqID,
                            ICMProgressProcRecord *progressProc);

    /**
     *  GDHasScale()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    GDHasScale(GDHandle gdh, short depth, Fixed *scale);

    /**
     *  GDGetScale()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    GDGetScale(GDHandle gdh, Fixed *scale, short *flags);

    /**
     *  GDSetScale()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    GDSetScale(GDHandle gdh, Fixed scale, short flags);

    /**
     *  ICMShieldSequenceCursor()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    ICMShieldSequenceCursor(ImageSequence seqID);

    /**
     *  ICMDecompressComplete()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    ICMDecompressComplete(ImageSequence seqID, OSErr err, short flag,
                          ICMCompletionProcRecordPtr completionRtn);

    /**
     *  ICMDecompressCompleteS()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.1 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    ICMDecompressCompleteS(ImageSequence seqID, OSErr err, short flag,
                           ICMCompletionProcRecordPtr completionRtn);

    /**
     *  ICMSequenceLockBits()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    ICMSequenceLockBits(ImageSequence seqID, PixMapPtr dst, long flags);

    /**
     *  ICMSequenceUnlockBits()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    ICMSequenceUnlockBits(ImageSequence seqID, long flags);

    enum
    {
        kICMPixelFormatIsPlanarMask = 0x0F,
        kICMPixelFormatIsIndexed = (1L << 4),
        kICMPixelFormatIsSupportedByQD = (1L << 5)
    };

    struct ICMPixelFormatInfo
    {
        long size;
        unsigned long formatFlags;
        short bitsPerPixel[14];
        /** new field for QuickTime 4.1*/
        Fixed defaultGammaLevel;
    };
    typedef struct ICMPixelFormatInfo ICMPixelFormatInfo;
    typedef ICMPixelFormatInfo *ICMPixelFormatInfoPtr;
    /**
     *  ICMGetPixelFormatInfo()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    ICMGetPixelFormatInfo(OSType PixelFormat, ICMPixelFormatInfoPtr theInfo);

    /**
     *  ICMSetPixelFormatInfo()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.1 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    ICMSetPixelFormatInfo(OSType PixelFormat, ICMPixelFormatInfoPtr theInfo);

    enum
    {
        kICMGetChainUltimateParent = 0,
        kICMGetChainParent = 1,
        kICMGetChainChild = 2,
        kICMGetChainUltimateChild = 3
    };

    /**
     *  ICMSequenceGetChainMember()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    ICMSequenceGetChainMember(ImageSequence seqID, ImageSequence *retSeqID,
                              long flags);

    /**
     *  SetDSequenceTimeCode()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    SetDSequenceTimeCode(ImageSequence seqID, void *timeCodeFormat,
                         void *timeCodeTime);

    /**
     *  CDSequenceNewMemory()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    CDSequenceNewMemory(ImageSequence seqID, Ptr *data, Size dataSize, long dataUse,
                        ICMMemoryDisposedUPP memoryGoneProc, void *refCon);

    /**
     *  CDSequenceDisposeMemory()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    CDSequenceDisposeMemory(ImageSequence seqID, Ptr data);

    /**
     *  CDSequenceNewDataSource()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    CDSequenceNewDataSource(ImageSequence seqID, ImageSequenceDataSource *sourceID,
                            OSType sourceType, long sourceInputNumber,
                            Handle dataDescription,
                            ICMConvertDataFormatUPP transferProc, void *refCon);

    /**
     *  CDSequenceDisposeDataSource()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    CDSequenceDisposeDataSource(ImageSequenceDataSource sourceID);

    /**
     *  CDSequenceSetSourceData()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    CDSequenceSetSourceData(ImageSequenceDataSource sourceID, void *data,
                            long dataSize);

    /**
     *  CDSequenceChangedSourceData()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    CDSequenceChangedSourceData(ImageSequenceDataSource sourceID);

    /**
     *  CDSequenceSetSourceDataQueue()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.1 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    CDSequenceSetSourceDataQueue(ImageSequenceDataSource sourceID,
                                 QHdrPtr dataQueue);

    /**
     *  CDSequenceGetDataSource()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    CDSequenceGetDataSource(ImageSequence seqID, ImageSequenceDataSource *sourceID,
                            OSType sourceType, long sourceInputNumber);

    /**
     *  PtInDSequenceData()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    PtInDSequenceData(ImageSequence seqID, void *data, Size dataSize, Point where,
                      Boolean *hit);

    /**
     *  HitTestDSequenceData()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    HitTestDSequenceData(ImageSequence seqID, void *data, Size dataSize,
                         Point where, long *hit, long hitFlags);

    /**
     *  GetGraphicsImporterForFile()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    GetGraphicsImporterForFile(const FSSpec *theFile, ComponentInstance *gi);

    /**
     *  GetGraphicsImporterForDataRef()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    GetGraphicsImporterForDataRef(Handle dataRef, OSType dataRefType,
                                  ComponentInstance *gi);

    enum
    {
        kDontUseValidateToFindGraphicsImporter = 1L << 0
    };

    /**
     *  GetGraphicsImporterForFileWithFlags()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.1 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    GetGraphicsImporterForFileWithFlags(const FSSpec *theFile,
                                        ComponentInstance *gi, long flags);

    /**
     *  GetGraphicsImporterForDataRefWithFlags()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.1 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    GetGraphicsImporterForDataRefWithFlags(Handle dataRef, OSType dataRefType,
                                           ComponentInstance *gi, long flags);

    /**
     *  QTGetFileNameExtension()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    QTGetFileNameExtension(ConstStrFileNameParam fileName, OSType fileType,
                           OSType *extension);

    /**
     *  ImageTranscodeSequenceBegin()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    ImageTranscodeSequenceBegin(ImageTranscodeSequence *its,
                                ImageDescriptionHandle srcDesc, OSType destType,
                                ImageDescriptionHandle *dstDesc, void *data,
                                long dataSize);

    /**
     *  ImageTranscodeSequenceEnd()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    ImageTranscodeSequenceEnd(ImageTranscodeSequence its);

    /**
     *  ImageTranscodeFrame()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    ImageTranscodeFrame(ImageTranscodeSequence its, void *srcData, long srcDataSize,
                        void **dstData, long *dstDataSize);

    /**
     *  ImageTranscodeDisposeFrameData()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    ImageTranscodeDisposeFrameData(ImageTranscodeSequence its, void *dstData);

    /**
     *  CDSequenceInvalidate()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    CDSequenceInvalidate(ImageSequence seqID, RgnHandle invalRgn);

    /**
     *  CDSequenceSetTimeBase()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    CDSequenceSetTimeBase(ImageSequence seqID, void *base);

    /**
     *  ImageFieldSequenceBegin()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    ImageFieldSequenceBegin(ImageFieldSequence *ifs, ImageDescriptionHandle desc1,
                            ImageDescriptionHandle desc2,
                            ImageDescriptionHandle descOut);

    /**
     *  ImageFieldSequenceExtractCombine()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    ImageFieldSequenceExtractCombine(ImageFieldSequence ifs, long fieldFlags,
                                     void *data1, long dataSize1, void *data2,
                                     long dataSize2, void *outputData,
                                     long *outDataSize);

    /**
     *  ImageFieldSequenceEnd()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    ImageFieldSequenceEnd(ImageFieldSequence ifs);

    enum
    {
        kICMTempThenAppMemory = 1L << 12,
        kICMAppThenTempMemory = 1L << 13
    };

    /**
     *  QTNewGWorld()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    QTNewGWorld(GWorldPtr *offscreenGWorld, OSType PixelFormat,
                const Rect *boundsRect, CTabHandle cTable, GDHandle aGDevice,
                GWorldFlags flags);

    /**
     *  QTNewGWorldFromPtr()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    OSErr
    QTNewGWorldFromPtr(GWorldPtr *gw, OSType pixelFormat, const Rect *boundsRect,
                       CTabHandle cTable, GDHandle aGDevice, GWorldFlags flags,
                       void *baseAddr, long rowBytes);

    /**
     *  QTUpdateGWorld()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    GWorldFlags
    QTUpdateGWorld(GWorldPtr *offscreenGWorld, OSType PixelFormat,
                   const Rect *boundsRect, CTabHandle cTable, GDHandle aGDevice,
                   GWorldFlags flags);

    /**
     *  MakeImageDescriptionForPixMap()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    MakeImageDescriptionForPixMap(PixMapHandle pixmap, ImageDescriptionHandle *idh);

    /**
     *  MakeImageDescriptionForEffect()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    OSErr
    MakeImageDescriptionForEffect(OSType effectType, ImageDescriptionHandle *idh);

    /**
     *  QTGetPixelSize()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    short
    QTGetPixelSize(OSType PixelFormat);

    /**
     *  QTGetPixMapPtrRowBytes()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    long
    QTGetPixMapPtrRowBytes(PixMapPtr pm);

    /**
     *  QTGetPixMapHandleRowBytes()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    long
    QTGetPixMapHandleRowBytes(PixMapHandle pm);

    /**
     *  QTSetPixMapPtrRowBytes()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    OSErr
    QTSetPixMapPtrRowBytes(PixMapPtr pm, long rowBytes);

    /**
     *  QTSetPixMapHandleRowBytes()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    OSErr
    QTSetPixMapHandleRowBytes(PixMapHandle pm, long rowBytes);

    enum
    {
        kQTUsePlatformDefaultGammaLevel =
            0,                        /** When decompressing into this PixMap, gamma-correct to the
                                         platform's standard gamma. */
        kQTUseSourceGammaLevel = -1L, /** When decompressing into this PixMap, don't
                                         perform gamma-correction. */
        kQTCCIR601VideoGammaLevel =
            0x00023333 /** 2.2, standard television video gamma.*/
    };

    /**
     *  QTGetPixMapPtrGammaLevel()
     *

     *    \non_carbon_cfm   in QuickTimeLib 5.0 and later
     *    \carbon_lib        in CarbonLib 1.3 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 5.0 and later
     */
    Fixed
    QTGetPixMapPtrGammaLevel(PixMapPtr pm);

    /**
     *  QTSetPixMapPtrGammaLevel()
     *

     *    \non_carbon_cfm   in QuickTimeLib 5.0 and later
     *    \carbon_lib        in CarbonLib 1.3 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 5.0 and later
     */
    OSErr
    QTSetPixMapPtrGammaLevel(PixMapPtr pm, Fixed gammaLevel);

    /**
     *  QTGetPixMapHandleGammaLevel()
     *

     *    \non_carbon_cfm   in QuickTimeLib 5.0 and later
     *    \carbon_lib        in CarbonLib 1.3 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 5.0 and later
     */
    Fixed
    QTGetPixMapHandleGammaLevel(PixMapHandle pm);

    /**
     *  QTSetPixMapHandleGammaLevel()
     *

     *    \non_carbon_cfm   in QuickTimeLib 5.0 and later
     *    \carbon_lib        in CarbonLib 1.3 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 5.0 and later
     */
    OSErr
    QTSetPixMapHandleGammaLevel(PixMapHandle pm, Fixed gammaLevel);

    /**
     *  QTGetPixMapPtrRequestedGammaLevel()
     *

     *    \non_carbon_cfm   in QuickTimeLib 5.0 and later
     *    \carbon_lib        in CarbonLib 1.3 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 5.0 and later
     */
    Fixed
    QTGetPixMapPtrRequestedGammaLevel(PixMapPtr pm);

    /**
     *  QTSetPixMapPtrRequestedGammaLevel()
     *

     *    \non_carbon_cfm   in QuickTimeLib 5.0 and later
     *    \carbon_lib        in CarbonLib 1.3 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 5.0 and later
     */
    OSErr
    QTSetPixMapPtrRequestedGammaLevel(PixMapPtr pm, Fixed requestedGammaLevel);

    /**
     *  QTGetPixMapHandleRequestedGammaLevel()
     *

     *    \non_carbon_cfm   in QuickTimeLib 5.0 and later
     *    \carbon_lib        in CarbonLib 1.3 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 5.0 and later
     */
    Fixed
    QTGetPixMapHandleRequestedGammaLevel(PixMapHandle pm);

    /**
     *  QTSetPixMapHandleRequestedGammaLevel()
     *

     *    \non_carbon_cfm   in QuickTimeLib 5.0 and later
     *    \carbon_lib        in CarbonLib 1.3 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 5.0 and later
     */
    OSErr
    QTSetPixMapHandleRequestedGammaLevel(PixMapHandle pm, Fixed requestedGammaLevel);

    /**
     *  QuadToQuadMatrix()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    OSErr
    QuadToQuadMatrix(const Fixed *source, const Fixed *dest, MatrixRecord *map);

    enum
    {
        identityMatrixType = 0x00,       /** result if matrix is identity */
        translateMatrixType = 0x01,      /** result if matrix translates */
        scaleMatrixType = 0x02,          /** result if matrix scales */
        scaleTranslateMatrixType = 0x03, /** result if matrix scales and translates */
        linearMatrixType = 0x04,         /** result if matrix is general 2 x 2 */
        linearTranslateMatrixType =
            0x05,                    /** result if matrix is general 2 x 2 and translates */
        perspectiveMatrixType = 0x06 /** result if matrix is general 3 x 3 */
    };

    typedef unsigned short MatrixFlags;
    /**
     *  GetMatrixType()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    short
    GetMatrixType(const MatrixRecord *m);

    /**
     *  CopyMatrix()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    CopyMatrix(const MatrixRecord *m1, MatrixRecord *m2);

    /**
     *  EqualMatrix()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    Boolean
    EqualMatrix(const MatrixRecord *m1, const MatrixRecord *m2);

    /**
     *  SetIdentityMatrix()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SetIdentityMatrix(MatrixRecord *matrix);

    /**
     *  TranslateMatrix()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    TranslateMatrix(MatrixRecord *m, Fixed deltaH, Fixed deltaV);

    /**
     *  RotateMatrix()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    RotateMatrix(MatrixRecord *m, Fixed degrees, Fixed aboutX, Fixed aboutY);

    /**
     *  ScaleMatrix()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    ScaleMatrix(MatrixRecord *m, Fixed scaleX, Fixed scaleY, Fixed aboutX,
                Fixed aboutY);

    /**
     *  SkewMatrix()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SkewMatrix(MatrixRecord *m, Fixed skewX, Fixed skewY, Fixed aboutX,
               Fixed aboutY);

    /**
     *  TransformFixedPoints()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    TransformFixedPoints(const MatrixRecord *m, FixedPoint *fpt, long count);

    /**
     *  TransformPoints()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    TransformPoints(const MatrixRecord *mp, Point *pt1, long count);

    /**
     *  TransformFixedRect()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    Boolean
    TransformFixedRect(const MatrixRecord *m, FixedRect *fr, FixedPoint *fpp);

    /**
     *  TransformRect()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    Boolean
    TransformRect(const MatrixRecord *m, Rect *r, FixedPoint *fpp);

    /**
     *  InverseMatrix()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    Boolean
    InverseMatrix(const MatrixRecord *m, MatrixRecord *im);

    /**
     *  ConcatMatrix()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    ConcatMatrix(const MatrixRecord *a, MatrixRecord *b);

    /**
     *  RectMatrix()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    RectMatrix(MatrixRecord *matrix, const Rect *srcRect, const Rect *dstRect);

    /**
     *  MapMatrix()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    MapMatrix(MatrixRecord *matrix, const Rect *fromRect, const Rect *toRect);

    /**
     *  CompAdd()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    CompAdd(wide *src, wide *dst);

    /**
     *  CompSub()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    CompSub(wide *src, wide *dst);

    /**
     *  CompNeg()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    CompNeg(wide *dst);

    /**
     *  CompShift()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    CompShift(wide *src, short shift);

    /**
     *  CompMul()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    CompMul(long src1, long src2, wide *dst);

    /**
     *  CompDiv()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    long
    CompDiv(wide *numerator, long denominator, long *remainder);

    /**
     *  CompFixMul()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    CompFixMul(wide *compSrc, Fixed fixSrc, wide *compDst);

    /**
     *  CompMulDiv()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    CompMulDiv(wide *co, long mul, long divisor);

    /**
     *  CompMulDivTrunc()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    CompMulDivTrunc(wide *co, long mul, long divisor, long *remainder);

    /**
     *  CompCompare()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    long
    CompCompare(const wide *a, const wide *minusb);

    /**
     *  CompSquareRoot()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    unsigned long
    CompSquareRoot(const wide *src);

    /**
     *  FixMulDiv()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    Fixed
    FixMulDiv(Fixed src, Fixed mul, Fixed divisor);

    /**
     *  UnsignedFixMulDiv()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    Fixed
    UnsignedFixMulDiv(Fixed src, Fixed mul, Fixed divisor);

    /**
     *  FracSinCos()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    Fract
    FracSinCos(Fixed degree, Fract *cosOut);

    /**
     *  FixExp2()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    Fixed
    FixExp2(Fixed src);

    /**
     *  FixLog2()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    Fixed
    FixLog2(Fixed src);

    /**
     *  FixPow()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    Fixed
    FixPow(Fixed base, Fixed exp);

    typedef ComponentInstance GraphicsImportComponent;
    enum
    {
        GraphicsImporterComponentType = FOUR_CHAR_CODE('grip')
    };

    enum
    {
        graphicsImporterUsesImageDecompressor = 1L << 23
    };

    enum
    {
        quickTimeImageFileImageDescriptionAtom = FOUR_CHAR_CODE('idsc'),
        quickTimeImageFileImageDataAtom = FOUR_CHAR_CODE('idat'),
        quickTimeImageFileMetaDataAtom = FOUR_CHAR_CODE('meta'),
        quickTimeImageFileColorSyncProfileAtom = FOUR_CHAR_CODE('iicc')
    };

    enum
    {
        graphicsImporterDrawsAllPixels = 0,
        graphicsImporterDoesntDrawAllPixels = 1,
        graphicsImporterDontKnowIfDrawAllPixels = 2
    };

    /** Flags for GraphicsImportSetFlags */
    enum
    {
        kGraphicsImporterDontDoGammaCorrection = 1L
    };

    enum
    {
        kGraphicsExportGroup = FOUR_CHAR_CODE('expo'),
        kGraphicsExportFileType = FOUR_CHAR_CODE('ftyp'),
        kGraphicsExportMIMEType = FOUR_CHAR_CODE('mime'),
        kGraphicsExportExtension = FOUR_CHAR_CODE('ext '),
        kGraphicsExportDescription = FOUR_CHAR_CODE('desc')
    };

    /** User data types for layers of Photoshop files */
    enum
    {
        kQTPhotoshopLayerMode = FOUR_CHAR_CODE('lmod'), /** OSType */
        kQTPhotoshopLayerOpacity =
            FOUR_CHAR_CODE('lopa'), /** UInt8, 0 = transparent .. 255 = opaque */
        kQTPhotoshopLayerClipping =
            FOUR_CHAR_CODE('lclp'),                      /** UInt8, 0 = base, 1 = non-base */
        kQTPhotoshopLayerFlags = FOUR_CHAR_CODE('lflg'), /** UInt8 */
        kQTPhotoshopLayerName = FOUR_CHAR_CODE('©lnm'),  /** Text */
        kQTPhotoshopLayerUnicodeName =
            FOUR_CHAR_CODE('luni') /** Unicode characters, not terminated */
    };

    /** User data returned by graphics importers to suggest intended use for indexed
     * images */
    enum
    {
        kQTIndexedImageType = FOUR_CHAR_CODE(
            'nth?'), /** 1 or more OSTypes, such as the following values: */
        kQTIndexedImageIsThumbnail =
            FOUR_CHAR_CODE('n=th'), /** The image at this index is a thumbnail. */
        kQTIndexedImageIsLayer =
            FOUR_CHAR_CODE('n=ly'), /** The image at this index is a layer. */
        kQTIndexedImageIsPage =
            FOUR_CHAR_CODE('n=pg'), /** The image at this index is a page. */
        kQTIndexedImageIsMultiResolution =
            FOUR_CHAR_CODE('n=rs') /** The image at this index is one of several
                                      identical images at different resolutions. */
    };

    /** Other user data types returned by graphics importers */
    enum
    {
        kQTTIFFUserDataPrefix =
            0x74690000, /** Added to some tag values in TIFF IFDs to generate user
                           data codes.  (0x7469 is 'ti'.) */
        /** For example, YCbCrPositioning is tag 0x0213, so its user data code is
           0x74690213. */
        kQTTIFFExifUserDataPrefix =
            0x65780000, /** Added to tag values in Exif IFDs to generate user data
                           codes.  (0x6578 is 'ex'.) */
        /** For example, DateTimeOriginal is tag 0x9003, so its user data code is
           0x65789003. */
        kQTTIFFExifGPSUserDataPrefix =
            0x67700000, /** Added to tag values in Exif GPS IFDs to generate user data
                           codes.  (0x6770 is 'gp'.) */
        /** For example, GPSAltitude is tag 0x0006, so its user data code is
           0x6770006. */
        kQTAlphaMode =
            FOUR_CHAR_CODE('almo'), /** UInt32; eg, graphicsModeStraightAlpha or
                                       graphicsModePreBlackAlpha */
        kQTAlphaModePreMulColor =
            FOUR_CHAR_CODE('almp'), /** RGBColor; used if kQTAlphaMode is
                                       graphicsModePreMulColorAlpha */
        kUserDataIPTC = FOUR_CHAR_CODE('iptc')
    };

    /*** These are GraphicsImport procedures **/
    /**
     *  GraphicsImportSetDataReference()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    GraphicsImportSetDataReference(GraphicsImportComponent ci, Handle dataRef,
                                   OSType dataReType);

    /**
     *  GraphicsImportGetDataReference()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    GraphicsImportGetDataReference(GraphicsImportComponent ci, Handle *dataRef,
                                   OSType *dataReType);

    /**
     *  GraphicsImportSetDataFile()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    GraphicsImportSetDataFile(GraphicsImportComponent ci, const FSSpec *theFile);

    /**
     *  GraphicsImportGetDataFile()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    GraphicsImportGetDataFile(GraphicsImportComponent ci, FSSpec *theFile);

    /**
     *  GraphicsImportSetDataHandle()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    GraphicsImportSetDataHandle(GraphicsImportComponent ci, Handle h);

    /**
     *  GraphicsImportGetDataHandle()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    GraphicsImportGetDataHandle(GraphicsImportComponent ci, Handle *h);

    /**
     *  GraphicsImportGetImageDescription()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    GraphicsImportGetImageDescription(GraphicsImportComponent ci,
                                      ImageDescriptionHandle *desc);

    /**
     *  GraphicsImportGetDataOffsetAndSize()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    GraphicsImportGetDataOffsetAndSize(GraphicsImportComponent ci,
                                       unsigned long *offset, unsigned long *size);

    /**
     *  GraphicsImportReadData()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    GraphicsImportReadData(GraphicsImportComponent ci, void *dataPtr,
                           unsigned long dataOffset, unsigned long dataSize);

    /**
     *  GraphicsImportSetClip()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    GraphicsImportSetClip(GraphicsImportComponent ci, RgnHandle clipRgn);

    /**
     *  GraphicsImportGetClip()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    GraphicsImportGetClip(GraphicsImportComponent ci, RgnHandle *clipRgn);

    /**
     *  GraphicsImportSetSourceRect()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    GraphicsImportSetSourceRect(GraphicsImportComponent ci, const Rect *sourceRect);

    /**
     *  GraphicsImportGetSourceRect()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    GraphicsImportGetSourceRect(GraphicsImportComponent ci, Rect *sourceRect);

    /**
     *  GraphicsImportGetNaturalBounds()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    GraphicsImportGetNaturalBounds(GraphicsImportComponent ci, Rect *naturalBounds);

    /**
     *  GraphicsImportDraw()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    GraphicsImportDraw(GraphicsImportComponent ci);

    /**
     *  GraphicsImportSetGWorld()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    GraphicsImportSetGWorld(GraphicsImportComponent ci, CGrafPtr port, GDHandle gd);

    /**
     *  GraphicsImportGetGWorld()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    GraphicsImportGetGWorld(GraphicsImportComponent ci, CGrafPtr *port,
                            GDHandle *gd);

    /**
     *  GraphicsImportSetMatrix()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    GraphicsImportSetMatrix(GraphicsImportComponent ci, const MatrixRecord *matrix);

    /**
     *  GraphicsImportGetMatrix()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    GraphicsImportGetMatrix(GraphicsImportComponent ci, MatrixRecord *matrix);

    /**
     *  GraphicsImportSetBoundsRect()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    GraphicsImportSetBoundsRect(GraphicsImportComponent ci, const Rect *bounds);

    /**
     *  GraphicsImportGetBoundsRect()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    GraphicsImportGetBoundsRect(GraphicsImportComponent ci, Rect *bounds);

    /**
     *  GraphicsImportSaveAsPicture()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    GraphicsImportSaveAsPicture(GraphicsImportComponent ci, const FSSpec *fss,
                                ScriptCode scriptTag);

    /**
     *  GraphicsImportSetGraphicsMode()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    GraphicsImportSetGraphicsMode(GraphicsImportComponent ci, long graphicsMode,
                                  const RGBColor *opColor);

    /**
     *  GraphicsImportGetGraphicsMode()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    GraphicsImportGetGraphicsMode(GraphicsImportComponent ci, long *graphicsMode,
                                  RGBColor *opColor);

    /**
     *  GraphicsImportSetQuality()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    GraphicsImportSetQuality(GraphicsImportComponent ci, CodecQ quality);

    /**
     *  GraphicsImportGetQuality()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    GraphicsImportGetQuality(GraphicsImportComponent ci, CodecQ *quality);

    /**
     *  GraphicsImportSaveAsQuickTimeImageFile()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    GraphicsImportSaveAsQuickTimeImageFile(GraphicsImportComponent ci,
                                           const FSSpec *fss, ScriptCode scriptTag);

    /**
     *  GraphicsImportSetDataReferenceOffsetAndLimit()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    GraphicsImportSetDataReferenceOffsetAndLimit(GraphicsImportComponent ci,
                                                 unsigned long offset,
                                                 unsigned long limit);

    /**
     *  GraphicsImportGetDataReferenceOffsetAndLimit()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    GraphicsImportGetDataReferenceOffsetAndLimit(GraphicsImportComponent ci,
                                                 unsigned long *offset,
                                                 unsigned long *limit);

    /**
     *  GraphicsImportGetAliasedDataReference()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    GraphicsImportGetAliasedDataReference(GraphicsImportComponent ci,
                                          Handle *dataRef, OSType *dataRefType);

    /**
     *  GraphicsImportValidate()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    GraphicsImportValidate(GraphicsImportComponent ci, Boolean *valid);

    /**
     *  GraphicsImportGetMetaData()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    GraphicsImportGetMetaData(GraphicsImportComponent ci, void *userData);

    /**
     *  GraphicsImportGetMIMETypeList()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    GraphicsImportGetMIMETypeList(GraphicsImportComponent ci,
                                  void *qtAtomContainerPtr);

    /**
     *  GraphicsImportDoesDrawAllPixels()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    GraphicsImportDoesDrawAllPixels(GraphicsImportComponent ci,
                                    short *drawsAllPixels);

    /**
     *  GraphicsImportGetAsPicture()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    GraphicsImportGetAsPicture(GraphicsImportComponent ci, PicHandle *picture);

    /**
     *  GraphicsImportExportImageFile()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    GraphicsImportExportImageFile(GraphicsImportComponent ci, OSType fileType,
                                  OSType fileCreator, const FSSpec *fss,
                                  ScriptCode scriptTag);

    /**
     *  GraphicsImportGetExportImageTypeList()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    GraphicsImportGetExportImageTypeList(GraphicsImportComponent ci,
                                         void *qtAtomContainerPtr);

    /**
     *  GraphicsImportDoExportImageFileDialog()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    GraphicsImportDoExportImageFileDialog(
        GraphicsImportComponent ci, const FSSpec *inDefaultSpec, StringPtr prompt,
        ModalFilterYDUPP filterProc, OSType *outExportedType,
        FSSpec *outExportedSpec, ScriptCode *outScriptTag);

    /**
     *  GraphicsImportGetExportSettingsAsAtomContainer()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    GraphicsImportGetExportSettingsAsAtomContainer(GraphicsImportComponent ci,
                                                   void *qtAtomContainerPtr);

    /**
     *  GraphicsImportSetExportSettingsFromAtomContainer()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    GraphicsImportSetExportSettingsFromAtomContainer(GraphicsImportComponent ci,
                                                     void *qtAtomContainer);

    /**
     *  GraphicsImportSetProgressProc()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    GraphicsImportSetProgressProc(GraphicsImportComponent ci,
                                  ICMProgressProcRecordPtr progressProc);

    /**
     *  GraphicsImportGetProgressProc()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    GraphicsImportGetProgressProc(GraphicsImportComponent ci,
                                  ICMProgressProcRecordPtr progressProc);

    /**
     *  GraphicsImportGetImageCount()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    GraphicsImportGetImageCount(GraphicsImportComponent ci,
                                unsigned long *imageCount);

    /**
     *  GraphicsImportSetImageIndex()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    GraphicsImportSetImageIndex(GraphicsImportComponent ci,
                                unsigned long imageIndex);

    /**
     *  GraphicsImportGetImageIndex()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    GraphicsImportGetImageIndex(GraphicsImportComponent ci,
                                unsigned long *imageIndex);

    /**
     *  GraphicsImportGetDataOffsetAndSize64()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    GraphicsImportGetDataOffsetAndSize64(GraphicsImportComponent ci, wide *offset,
                                         wide *size);

    /**
     *  GraphicsImportReadData64()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    GraphicsImportReadData64(GraphicsImportComponent ci, void *dataPtr,
                             const wide *dataOffset, unsigned long dataSize);

    /**
     *  GraphicsImportSetDataReferenceOffsetAndLimit64()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    GraphicsImportSetDataReferenceOffsetAndLimit64(GraphicsImportComponent ci,
                                                   const wide *offset,
                                                   const wide *limit);

    /**
     *  GraphicsImportGetDataReferenceOffsetAndLimit64()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    GraphicsImportGetDataReferenceOffsetAndLimit64(GraphicsImportComponent ci,
                                                   wide *offset, wide *limit);

    /**
     *  GraphicsImportGetDefaultMatrix()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    GraphicsImportGetDefaultMatrix(GraphicsImportComponent ci,
                                   MatrixRecord *defaultMatrix);

    /**
     *  GraphicsImportGetDefaultClip()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    GraphicsImportGetDefaultClip(GraphicsImportComponent ci, RgnHandle *defaultRgn);

    /**
     *  GraphicsImportGetDefaultGraphicsMode()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    GraphicsImportGetDefaultGraphicsMode(GraphicsImportComponent ci,
                                         long *defaultGraphicsMode,
                                         RGBColor *defaultOpColor);

    /**
     *  GraphicsImportGetDefaultSourceRect()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    GraphicsImportGetDefaultSourceRect(GraphicsImportComponent ci,
                                       Rect *defaultSourceRect);

    /**
     *  GraphicsImportGetColorSyncProfile()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    GraphicsImportGetColorSyncProfile(GraphicsImportComponent ci, Handle *profile);

    /**
     *  GraphicsImportSetDestRect()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    GraphicsImportSetDestRect(GraphicsImportComponent ci, const Rect *destRect);

    /**
     *  GraphicsImportGetDestRect()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    GraphicsImportGetDestRect(GraphicsImportComponent ci, Rect *destRect);

    /**
     *  GraphicsImportSetFlags()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    GraphicsImportSetFlags(GraphicsImportComponent ci, long flags);

    /**
     *  GraphicsImportGetFlags()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    GraphicsImportGetFlags(GraphicsImportComponent ci, long *flags);

    /** 2 private selectors */
    /**
     *  GraphicsImportGetBaseDataOffsetAndSize64()
     *

     *    \non_carbon_cfm   in QuickTimeLib 5.0.2 and later
     *    \carbon_lib        in CarbonLib 1.4 and later
     *    \mac_os_x         in version 10.1 and later
     *    Windows:          in qtmlClient.lib 5.0.2 and later
     */
    ComponentResult
    GraphicsImportGetBaseDataOffsetAndSize64(GraphicsImportComponent ci,
                                             wide *offset, wide *size);

    typedef ComponentInstance GraphicsExportComponent;
    enum
    {
        GraphicsExporterComponentType = FOUR_CHAR_CODE('grex'),
        kBaseGraphicsExporterSubType = FOUR_CHAR_CODE('base')
    };

    enum
    {
        graphicsExporterIsBaseExporter = 1L << 0,
        graphicsExporterCanTranscode = 1L << 1,
        graphicsExporterUsesImageCompressor = 1L << 2
    };

    struct QTResolutionSettings
    {
        Fixed horizontalResolution;
        Fixed verticalResolution;
    };
    typedef struct QTResolutionSettings QTResolutionSettings;
    struct QTTargetDataSize
    {
        unsigned long targetDataSize;
    };
    typedef struct QTTargetDataSize QTTargetDataSize;
    struct QTThumbnailSettings
    {
        long enableThumbnail;    /** a thoroughly padded Boolean*/
        long maxThumbnailWidth;  /** set to zero to let someone else decide*/
        long maxThumbnailHeight; /** set to zero to let someone else decide*/
    };
    typedef struct QTThumbnailSettings QTThumbnailSettings;
    enum
    {
        kQTResolutionSettings = FOUR_CHAR_CODE('reso'),
        kQTTargetDataSize = FOUR_CHAR_CODE('dasz'),
        kQTDontRecompress = FOUR_CHAR_CODE('dntr'),
        kQTInterlaceStyle = FOUR_CHAR_CODE('ilac'),
        kQTColorSyncProfile = FOUR_CHAR_CODE('iccp'),
        kQTThumbnailSettings = FOUR_CHAR_CODE('thum'),
        kQTEnableExif = FOUR_CHAR_CODE('exif'), /** UInt8 (boolean)*/
        kQTMetaData = FOUR_CHAR_CODE('meta')
    };

    enum
    {
        kQTTIFFCompressionMethod = FOUR_CHAR_CODE('tifc'), /** UInt32*/
        kQTTIFFCompression_None = 1,
        kQTTIFFCompression_PackBits = 32773L,
        kQTTIFFLittleEndian = FOUR_CHAR_CODE('tife') /** UInt8 (boolean)*/
    };

    enum
    {
        kQTPNGFilterPreference = FOUR_CHAR_CODE('pngf'), /** UInt32*/
        kQTPNGFilterBestForColorType = FOUR_CHAR_CODE('bflt'),
        kQTPNGFilterNone = 0,
        kQTPNGFilterSub = 1,
        kQTPNGFilterUp = 2,
        kQTPNGFilterAverage = 3,
        kQTPNGFilterPaeth = 4,
        kQTPNGFilterAdaptivePerRow = FOUR_CHAR_CODE('aflt'),
        kQTPNGInterlaceStyle = FOUR_CHAR_CODE('ilac'), /** UInt32*/
        kQTPNGInterlaceNone = 0,
        kQTPNGInterlaceAdam7 = 1
    };

    /*** These are GraphicsExport procedures **/
    /** To use: set the input and output (and other settings as desired) and call
     * GEDoExport. */
    /**
     *  GraphicsExportDoExport()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    GraphicsExportDoExport(GraphicsExportComponent ci,
                           unsigned long *actualSizeWritten);

    /** Used for internal communication between the base and format-specific
     * graphics exporter: */
    /**
     *  GraphicsExportCanTranscode()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    GraphicsExportCanTranscode(GraphicsExportComponent ci, Boolean *canTranscode);

    /**
     *  GraphicsExportDoTranscode()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    GraphicsExportDoTranscode(GraphicsExportComponent ci);

    /**
     *  GraphicsExportCanUseCompressor()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    GraphicsExportCanUseCompressor(GraphicsExportComponent ci,
                                   Boolean *canUseCompressor,
                                   void *codecSettingsAtomContainerPtr);

    /**
     *  GraphicsExportDoUseCompressor()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    GraphicsExportDoUseCompressor(GraphicsExportComponent ci,
                                  void *codecSettingsAtomContainer,
                                  ImageDescriptionHandle *outDesc);

    /**
     *  GraphicsExportDoStandaloneExport()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    GraphicsExportDoStandaloneExport(GraphicsExportComponent ci);

    /** Queries applications can make of a format-specific graphics exporter: */
    /**
     *  GraphicsExportGetDefaultFileTypeAndCreator()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    GraphicsExportGetDefaultFileTypeAndCreator(GraphicsExportComponent ci,
                                               OSType *fileType,
                                               OSType *fileCreator);

    /**
     *  GraphicsExportGetDefaultFileNameExtension()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    GraphicsExportGetDefaultFileNameExtension(GraphicsExportComponent ci,
                                              OSType *fileNameExtension);

    /**
     *  GraphicsExportGetMIMETypeList()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    GraphicsExportGetMIMETypeList(GraphicsExportComponent ci,
                                  void *qtAtomContainerPtr);

    /** GraphicsExportIsTranscodePossibleFromCurrentInput is removed; call
     * GraphicsExportCanTranscode instead */
    /** Graphics exporter settings: */
    /**
     *  GraphicsExportRequestSettings()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    GraphicsExportRequestSettings(GraphicsExportComponent ci,
                                  ModalFilterYDUPP filterProc, void *yourDataProc);

    /**
     *  GraphicsExportSetSettingsFromAtomContainer()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    GraphicsExportSetSettingsFromAtomContainer(GraphicsExportComponent ci,
                                               void *qtAtomContainer);

    /**
     *  GraphicsExportGetSettingsAsAtomContainer()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    GraphicsExportGetSettingsAsAtomContainer(GraphicsExportComponent ci,
                                             void *qtAtomContainerPtr);

    /**
     *  GraphicsExportGetSettingsAsText()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    GraphicsExportGetSettingsAsText(GraphicsExportComponent ci, Handle *theText);

    /** Graphics exporters may implement some or none of the following: */
    /**
     *  GraphicsExportSetDontRecompress()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    GraphicsExportSetDontRecompress(GraphicsExportComponent ci,
                                    Boolean dontRecompress);

    /**
     *  GraphicsExportGetDontRecompress()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    GraphicsExportGetDontRecompress(GraphicsExportComponent ci,
                                    Boolean *dontRecompress);

    /**
     *  GraphicsExportSetInterlaceStyle()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    GraphicsExportSetInterlaceStyle(GraphicsExportComponent ci,
                                    unsigned long interlaceStyle);

    /**
     *  GraphicsExportGetInterlaceStyle()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    GraphicsExportGetInterlaceStyle(GraphicsExportComponent ci,
                                    unsigned long *interlaceStyle);

    /**
     *  GraphicsExportSetMetaData()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    GraphicsExportSetMetaData(GraphicsExportComponent ci, void *userData);

    /**
     *  GraphicsExportGetMetaData()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    GraphicsExportGetMetaData(GraphicsExportComponent ci, void *userData);

    /**
     *  GraphicsExportSetTargetDataSize()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    GraphicsExportSetTargetDataSize(GraphicsExportComponent ci,
                                    unsigned long targetDataSize);

    /**
     *  GraphicsExportGetTargetDataSize()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    GraphicsExportGetTargetDataSize(GraphicsExportComponent ci,
                                    unsigned long *targetDataSize);

    /**
     *  GraphicsExportSetCompressionMethod()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    GraphicsExportSetCompressionMethod(GraphicsExportComponent ci,
                                       long compressionMethod);

    /**
     *  GraphicsExportGetCompressionMethod()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    GraphicsExportGetCompressionMethod(GraphicsExportComponent ci,
                                       long *compressionMethod);

    /**
     *  GraphicsExportSetCompressionQuality()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    GraphicsExportSetCompressionQuality(GraphicsExportComponent ci,
                                        CodecQ spatialQuality);

    /**
     *  GraphicsExportGetCompressionQuality()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    GraphicsExportGetCompressionQuality(GraphicsExportComponent ci,
                                        CodecQ *spatialQuality);

    /**
     *  GraphicsExportSetResolution()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    GraphicsExportSetResolution(GraphicsExportComponent ci,
                                Fixed horizontalResolution,
                                Fixed verticalResolution);

    /**
     *  GraphicsExportGetResolution()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    GraphicsExportGetResolution(GraphicsExportComponent ci,
                                Fixed *horizontalResolution,
                                Fixed *verticalResolution);

    /**
     *  GraphicsExportSetDepth()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    GraphicsExportSetDepth(GraphicsExportComponent ci, long depth);

    /**
     *  GraphicsExportGetDepth()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    GraphicsExportGetDepth(GraphicsExportComponent ci, long *depth);

    /**
     *  GraphicsExportSetColorSyncProfile()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    GraphicsExportSetColorSyncProfile(GraphicsExportComponent ci,
                                      Handle colorSyncProfile);

    /**
     *  GraphicsExportGetColorSyncProfile()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    GraphicsExportGetColorSyncProfile(GraphicsExportComponent ci,
                                      Handle *colorSyncProfile);

    /** Always implemented by the base graphics exporter: */
    /**
     *  GraphicsExportSetProgressProc()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    GraphicsExportSetProgressProc(GraphicsExportComponent ci,
                                  ICMProgressProcRecordPtr progressProc);

    /**
     *  GraphicsExportGetProgressProc()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    GraphicsExportGetProgressProc(GraphicsExportComponent ci,
                                  ICMProgressProcRecordPtr progressProc);

    /** Sources for the input image: */
    /**
     *  GraphicsExportSetInputDataReference()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    GraphicsExportSetInputDataReference(GraphicsExportComponent ci, Handle dataRef,
                                        OSType dataRefType,
                                        ImageDescriptionHandle desc);

    /**
     *  GraphicsExportGetInputDataReference()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    GraphicsExportGetInputDataReference(GraphicsExportComponent ci, Handle *dataRef,
                                        OSType *dataRefType);

    /**
     *  GraphicsExportSetInputFile()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    GraphicsExportSetInputFile(GraphicsExportComponent ci, const FSSpec *theFile,
                               ImageDescriptionHandle desc);

    /**
     *  GraphicsExportGetInputFile()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    GraphicsExportGetInputFile(GraphicsExportComponent ci, FSSpec *theFile);

    /**
     *  GraphicsExportSetInputHandle()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    GraphicsExportSetInputHandle(GraphicsExportComponent ci, Handle h,
                                 ImageDescriptionHandle desc);

    /**
     *  GraphicsExportGetInputHandle()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    GraphicsExportGetInputHandle(GraphicsExportComponent ci, Handle *h);

    /**
     *  GraphicsExportSetInputPtr()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    GraphicsExportSetInputPtr(GraphicsExportComponent ci, Ptr p, unsigned long size,
                              ImageDescriptionHandle desc);

    /**
     *  GraphicsExportGetInputPtr()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    GraphicsExportGetInputPtr(GraphicsExportComponent ci, Ptr *p,
                              unsigned long *size);

    /**
     *  GraphicsExportSetInputGraphicsImporter()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    GraphicsExportSetInputGraphicsImporter(GraphicsExportComponent ci,
                                           GraphicsImportComponent grip);

    /**
     *  GraphicsExportGetInputGraphicsImporter()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    GraphicsExportGetInputGraphicsImporter(GraphicsExportComponent ci,
                                           GraphicsImportComponent *grip);

    /**
     *  GraphicsExportSetInputPicture()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    GraphicsExportSetInputPicture(GraphicsExportComponent ci, PicHandle picture);

    /**
     *  GraphicsExportGetInputPicture()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    GraphicsExportGetInputPicture(GraphicsExportComponent ci, PicHandle *picture);

    /**
     *  GraphicsExportSetInputGWorld()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    GraphicsExportSetInputGWorld(GraphicsExportComponent ci, GWorldPtr gworld);

    /**
     *  GraphicsExportGetInputGWorld()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    GraphicsExportGetInputGWorld(GraphicsExportComponent ci, GWorldPtr *gworld);

    /**
     *  GraphicsExportSetInputPixmap()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    GraphicsExportSetInputPixmap(GraphicsExportComponent ci, PixMapHandle pixmap);

    /**
     *  GraphicsExportGetInputPixmap()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    GraphicsExportGetInputPixmap(GraphicsExportComponent ci, PixMapHandle *pixmap);

    /** Only applicable when the input is a data reference, file, handle or ptr: */
    /**
     *  GraphicsExportSetInputOffsetAndLimit()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    GraphicsExportSetInputOffsetAndLimit(GraphicsExportComponent ci,
                                         unsigned long offset, unsigned long limit);

    /**
     *  GraphicsExportGetInputOffsetAndLimit()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    GraphicsExportGetInputOffsetAndLimit(GraphicsExportComponent ci,
                                         unsigned long *offset,
                                         unsigned long *limit);

    /** Used by format-specific graphics exporters when transcoding: */
    /**
     *  GraphicsExportMayExporterReadInputData()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    GraphicsExportMayExporterReadInputData(GraphicsExportComponent ci,
                                           Boolean *mayReadInputData);

    /**
     *  GraphicsExportGetInputDataSize()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    GraphicsExportGetInputDataSize(GraphicsExportComponent ci, unsigned long *size);

    /**
     *  GraphicsExportReadInputData()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    GraphicsExportReadInputData(GraphicsExportComponent ci, void *dataPtr,
                                unsigned long dataOffset, unsigned long dataSize);

    /** Used by format-specific graphics exporters, especially when doing standalone
     * export: */
    /**
     *  GraphicsExportGetInputImageDescription()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    GraphicsExportGetInputImageDescription(GraphicsExportComponent ci,
                                           ImageDescriptionHandle *desc);

    /**
     *  GraphicsExportGetInputImageDimensions()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    GraphicsExportGetInputImageDimensions(GraphicsExportComponent ci,
                                          Rect *dimensions);

    /**
     *  GraphicsExportGetInputImageDepth()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    GraphicsExportGetInputImageDepth(GraphicsExportComponent ci, long *inputDepth);

    /**
     *  GraphicsExportDrawInputImage()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    GraphicsExportDrawInputImage(GraphicsExportComponent ci, CGrafPtr gw,
                                 GDHandle gd, const Rect *srcRect,
                                 const Rect *dstRect);

    /** Destinations for the output image: */
    /**
     *  GraphicsExportSetOutputDataReference()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    GraphicsExportSetOutputDataReference(GraphicsExportComponent ci, Handle dataRef,
                                         OSType dataRefType);

    /**
     *  GraphicsExportGetOutputDataReference()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    GraphicsExportGetOutputDataReference(GraphicsExportComponent ci,
                                         Handle *dataRef, OSType *dataRefType);

    /**
     *  GraphicsExportSetOutputFile()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    GraphicsExportSetOutputFile(GraphicsExportComponent ci, const FSSpec *theFile);

    /**
     *  GraphicsExportGetOutputFile()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    GraphicsExportGetOutputFile(GraphicsExportComponent ci, FSSpec *theFile);

    /**
     *  GraphicsExportSetOutputHandle()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    GraphicsExportSetOutputHandle(GraphicsExportComponent ci, Handle h);

    /**
     *  GraphicsExportGetOutputHandle()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    GraphicsExportGetOutputHandle(GraphicsExportComponent ci, Handle *h);

    /**
     *  GraphicsExportSetOutputOffsetAndMaxSize()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    GraphicsExportSetOutputOffsetAndMaxSize(GraphicsExportComponent ci,
                                            unsigned long offset,
                                            unsigned long maxSize,
                                            Boolean truncateFile);

    /**
     *  GraphicsExportGetOutputOffsetAndMaxSize()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    GraphicsExportGetOutputOffsetAndMaxSize(GraphicsExportComponent ci,
                                            unsigned long *offset,
                                            unsigned long *maxSize,
                                            Boolean *truncateFile);

    /**
     *  GraphicsExportSetOutputFileTypeAndCreator()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    GraphicsExportSetOutputFileTypeAndCreator(GraphicsExportComponent ci,
                                              OSType fileType, OSType fileCreator);

    /**
     *  GraphicsExportGetOutputFileTypeAndCreator()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    GraphicsExportGetOutputFileTypeAndCreator(GraphicsExportComponent ci,
                                              OSType *fileType, OSType *fileCreator);

    /** Used by format-specific graphics exporters: */
    /**
     *  GraphicsExportWriteOutputData()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    GraphicsExportWriteOutputData(GraphicsExportComponent ci, const void *dataPtr,
                                  unsigned long dataSize);

    /**
     *  GraphicsExportSetOutputMark()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    GraphicsExportSetOutputMark(GraphicsExportComponent ci, unsigned long mark);

    /**
     *  GraphicsExportGetOutputMark()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    GraphicsExportGetOutputMark(GraphicsExportComponent ci, unsigned long *mark);

    /**
     *  GraphicsExportReadOutputData()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    GraphicsExportReadOutputData(GraphicsExportComponent ci, void *dataPtr,
                                 unsigned long dataOffset, unsigned long dataSize);

    /** Allows embedded thumbnail creation, if supported. */
    /**
     *  GraphicsExportSetThumbnailEnabled()
     *

     *    \non_carbon_cfm   in QuickTimeLib 5.0.2 and later
     *    \carbon_lib        in CarbonLib 1.4 and later
     *    \mac_os_x         in version 10.1 and later
     *    Windows:          in qtmlClient.lib 5.0.2 and later
     */
    ComponentResult
    GraphicsExportSetThumbnailEnabled(GraphicsExportComponent ci,
                                      Boolean enableThumbnail,
                                      long maxThumbnailWidth,
                                      long maxThumbnailHeight);

    /**
     *  GraphicsExportGetThumbnailEnabled()
     *

     *    \non_carbon_cfm   in QuickTimeLib 5.0.2 and later
     *    \carbon_lib        in CarbonLib 1.4 and later
     *    \mac_os_x         in version 10.1 and later
     *    Windows:          in qtmlClient.lib 5.0.2 and later
     */
    ComponentResult
    GraphicsExportGetThumbnailEnabled(GraphicsExportComponent ci,
                                      Boolean *thumbnailEnabled,
                                      long *maxThumbnailWidth,
                                      long *maxThumbnailHeight);

    /** Allows export of Exif files, if supported.  This disables Exif-incompatible
     * settings such as grayscale JPEG and compressed TIFF, and enables export of
     * Exif metadata. */
    /**
     *  GraphicsExportSetExifEnabled()
     *

     *    \non_carbon_cfm   in QuickTimeLib 5.0.2 and later
     *    \carbon_lib        in CarbonLib 1.4 and later
     *    \mac_os_x         in version 10.1 and later
     *    Windows:          in qtmlClient.lib 5.0.2 and later
     */
    ComponentResult
    GraphicsExportSetExifEnabled(GraphicsExportComponent ci, Boolean enableExif);

    /**
     *  GraphicsExportGetExifEnabled()
     *

     *    \non_carbon_cfm   in QuickTimeLib 5.0.2 and later
     *    \carbon_lib        in CarbonLib 1.4 and later
     *    \mac_os_x         in version 10.1 and later
     *    Windows:          in qtmlClient.lib 5.0.2 and later
     */
    ComponentResult
    GraphicsExportGetExifEnabled(GraphicsExportComponent ci, Boolean *exifEnabled);

    typedef ComponentInstance ImageTranscoderComponent;
    enum
    {
        ImageTranscodererComponentType = FOUR_CHAR_CODE('imtc')
    };

    /*** These are ImageTranscoder procedures **/
    /**
     *  ImageTranscoderBeginSequence()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    ImageTranscoderBeginSequence(ImageTranscoderComponent itc,
                                 ImageDescriptionHandle srcDesc,
                                 ImageDescriptionHandle *dstDesc, void *data,
                                 long dataSize);

    /**
     *  ImageTranscoderConvert()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    ImageTranscoderConvert(ImageTranscoderComponent itc, void *srcData,
                           long srcDataSize, void **dstData, long *dstDataSize);

    /**
     *  ImageTranscoderDisposeData()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    ImageTranscoderDisposeData(ImageTranscoderComponent itc, void *dstData);

    /**
     *  ImageTranscoderEndSequence()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    ImageTranscoderEndSequence(ImageTranscoderComponent itc);

    /** UPP call backs */

    /** selectors for component calls */
    enum
    {
        kGraphicsImportSetDataReferenceSelect = 0x0001,
        kGraphicsImportGetDataReferenceSelect = 0x0002,
        kGraphicsImportSetDataFileSelect = 0x0003,
        kGraphicsImportGetDataFileSelect = 0x0004,
        kGraphicsImportSetDataHandleSelect = 0x0005,
        kGraphicsImportGetDataHandleSelect = 0x0006,
        kGraphicsImportGetImageDescriptionSelect = 0x0007,
        kGraphicsImportGetDataOffsetAndSizeSelect = 0x0008,
        kGraphicsImportReadDataSelect = 0x0009,
        kGraphicsImportSetClipSelect = 0x000A,
        kGraphicsImportGetClipSelect = 0x000B,
        kGraphicsImportSetSourceRectSelect = 0x000C,
        kGraphicsImportGetSourceRectSelect = 0x000D,
        kGraphicsImportGetNaturalBoundsSelect = 0x000E,
        kGraphicsImportDrawSelect = 0x000F,
        kGraphicsImportSetGWorldSelect = 0x0010,
        kGraphicsImportGetGWorldSelect = 0x0011,
        kGraphicsImportSetMatrixSelect = 0x0012,
        kGraphicsImportGetMatrixSelect = 0x0013,
        kGraphicsImportSetBoundsRectSelect = 0x0014,
        kGraphicsImportGetBoundsRectSelect = 0x0015,
        kGraphicsImportSaveAsPictureSelect = 0x0016,
        kGraphicsImportSetGraphicsModeSelect = 0x0017,
        kGraphicsImportGetGraphicsModeSelect = 0x0018,
        kGraphicsImportSetQualitySelect = 0x0019,
        kGraphicsImportGetQualitySelect = 0x001A,
        kGraphicsImportSaveAsQuickTimeImageFileSelect = 0x001B,
        kGraphicsImportSetDataReferenceOffsetAndLimitSelect = 0x001C,
        kGraphicsImportGetDataReferenceOffsetAndLimitSelect = 0x001D,
        kGraphicsImportGetAliasedDataReferenceSelect = 0x001E,
        kGraphicsImportValidateSelect = 0x001F,
        kGraphicsImportGetMetaDataSelect = 0x0020,
        kGraphicsImportGetMIMETypeListSelect = 0x0021,
        kGraphicsImportDoesDrawAllPixelsSelect = 0x0022,
        kGraphicsImportGetAsPictureSelect = 0x0023,
        kGraphicsImportExportImageFileSelect = 0x0024,
        kGraphicsImportGetExportImageTypeListSelect = 0x0025,
        kGraphicsImportDoExportImageFileDialogSelect = 0x0026,
        kGraphicsImportGetExportSettingsAsAtomContainerSelect = 0x0027,
        kGraphicsImportSetExportSettingsFromAtomContainerSelect = 0x0028,
        kGraphicsImportSetProgressProcSelect = 0x0029,
        kGraphicsImportGetProgressProcSelect = 0x002A,
        kGraphicsImportGetImageCountSelect = 0x002B,
        kGraphicsImportSetImageIndexSelect = 0x002C,
        kGraphicsImportGetImageIndexSelect = 0x002D,
        kGraphicsImportGetDataOffsetAndSize64Select = 0x002E,
        kGraphicsImportReadData64Select = 0x002F,
        kGraphicsImportSetDataReferenceOffsetAndLimit64Select = 0x0030,
        kGraphicsImportGetDataReferenceOffsetAndLimit64Select = 0x0031,
        kGraphicsImportGetDefaultMatrixSelect = 0x0032,
        kGraphicsImportGetDefaultClipSelect = 0x0033,
        kGraphicsImportGetDefaultGraphicsModeSelect = 0x0034,
        kGraphicsImportGetDefaultSourceRectSelect = 0x0035,
        kGraphicsImportGetColorSyncProfileSelect = 0x0036,
        kGraphicsImportSetDestRectSelect = 0x0037,
        kGraphicsImportGetDestRectSelect = 0x0038,
        kGraphicsImportSetFlagsSelect = 0x0039,
        kGraphicsImportGetFlagsSelect = 0x003A,
        kGraphicsImportGetBaseDataOffsetAndSize64Select = 0x003D,
        kGraphicsExportDoExportSelect = 0x0001,
        kGraphicsExportCanTranscodeSelect = 0x0002,
        kGraphicsExportDoTranscodeSelect = 0x0003,
        kGraphicsExportCanUseCompressorSelect = 0x0004,
        kGraphicsExportDoUseCompressorSelect = 0x0005,
        kGraphicsExportDoStandaloneExportSelect = 0x0006,
        kGraphicsExportGetDefaultFileTypeAndCreatorSelect = 0x0007,
        kGraphicsExportGetDefaultFileNameExtensionSelect = 0x0008,
        kGraphicsExportGetMIMETypeListSelect = 0x0009,
        kGraphicsExportRequestSettingsSelect = 0x000B,
        kGraphicsExportSetSettingsFromAtomContainerSelect = 0x000C,
        kGraphicsExportGetSettingsAsAtomContainerSelect = 0x000D,
        kGraphicsExportGetSettingsAsTextSelect = 0x000E,
        kGraphicsExportSetDontRecompressSelect = 0x000F,
        kGraphicsExportGetDontRecompressSelect = 0x0010,
        kGraphicsExportSetInterlaceStyleSelect = 0x0011,
        kGraphicsExportGetInterlaceStyleSelect = 0x0012,
        kGraphicsExportSetMetaDataSelect = 0x0013,
        kGraphicsExportGetMetaDataSelect = 0x0014,
        kGraphicsExportSetTargetDataSizeSelect = 0x0015,
        kGraphicsExportGetTargetDataSizeSelect = 0x0016,
        kGraphicsExportSetCompressionMethodSelect = 0x0017,
        kGraphicsExportGetCompressionMethodSelect = 0x0018,
        kGraphicsExportSetCompressionQualitySelect = 0x0019,
        kGraphicsExportGetCompressionQualitySelect = 0x001A,
        kGraphicsExportSetResolutionSelect = 0x001B,
        kGraphicsExportGetResolutionSelect = 0x001C,
        kGraphicsExportSetDepthSelect = 0x001D,
        kGraphicsExportGetDepthSelect = 0x001E,
        kGraphicsExportSetColorSyncProfileSelect = 0x0021,
        kGraphicsExportGetColorSyncProfileSelect = 0x0022,
        kGraphicsExportSetProgressProcSelect = 0x0023,
        kGraphicsExportGetProgressProcSelect = 0x0024,
        kGraphicsExportSetInputDataReferenceSelect = 0x0025,
        kGraphicsExportGetInputDataReferenceSelect = 0x0026,
        kGraphicsExportSetInputFileSelect = 0x0027,
        kGraphicsExportGetInputFileSelect = 0x0028,
        kGraphicsExportSetInputHandleSelect = 0x0029,
        kGraphicsExportGetInputHandleSelect = 0x002A,
        kGraphicsExportSetInputPtrSelect = 0x002B,
        kGraphicsExportGetInputPtrSelect = 0x002C,
        kGraphicsExportSetInputGraphicsImporterSelect = 0x002D,
        kGraphicsExportGetInputGraphicsImporterSelect = 0x002E,
        kGraphicsExportSetInputPictureSelect = 0x002F,
        kGraphicsExportGetInputPictureSelect = 0x0030,
        kGraphicsExportSetInputGWorldSelect = 0x0031,
        kGraphicsExportGetInputGWorldSelect = 0x0032,
        kGraphicsExportSetInputPixmapSelect = 0x0033,
        kGraphicsExportGetInputPixmapSelect = 0x0034,
        kGraphicsExportSetInputOffsetAndLimitSelect = 0x0035,
        kGraphicsExportGetInputOffsetAndLimitSelect = 0x0036,
        kGraphicsExportMayExporterReadInputDataSelect = 0x0037,
        kGraphicsExportGetInputDataSizeSelect = 0x0038,
        kGraphicsExportReadInputDataSelect = 0x0039,
        kGraphicsExportGetInputImageDescriptionSelect = 0x003A,
        kGraphicsExportGetInputImageDimensionsSelect = 0x003B,
        kGraphicsExportGetInputImageDepthSelect = 0x003C,
        kGraphicsExportDrawInputImageSelect = 0x003D,
        kGraphicsExportSetOutputDataReferenceSelect = 0x003E,
        kGraphicsExportGetOutputDataReferenceSelect = 0x003F,
        kGraphicsExportSetOutputFileSelect = 0x0040,
        kGraphicsExportGetOutputFileSelect = 0x0041,
        kGraphicsExportSetOutputHandleSelect = 0x0042,
        kGraphicsExportGetOutputHandleSelect = 0x0043,
        kGraphicsExportSetOutputOffsetAndMaxSizeSelect = 0x0044,
        kGraphicsExportGetOutputOffsetAndMaxSizeSelect = 0x0045,
        kGraphicsExportSetOutputFileTypeAndCreatorSelect = 0x0046,
        kGraphicsExportGetOutputFileTypeAndCreatorSelect = 0x0047,
        kGraphicsExportWriteOutputDataSelect = 0x0048,
        kGraphicsExportSetOutputMarkSelect = 0x0049,
        kGraphicsExportGetOutputMarkSelect = 0x004A,
        kGraphicsExportReadOutputDataSelect = 0x004B,
        kGraphicsExportSetThumbnailEnabledSelect = 0x004C,
        kGraphicsExportGetThumbnailEnabledSelect = 0x004D,
        kGraphicsExportSetExifEnabledSelect = 0x004E,
        kGraphicsExportGetExifEnabledSelect = 0x004F,
        kImageTranscoderBeginSequenceSelect = 0x0001,
        kImageTranscoderConvertSelect = 0x0002,
        kImageTranscoderDisposeDataSelect = 0x0003,
        kImageTranscoderEndSequenceSelect = 0x0004
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

#endif /** __IMAGECOMPRESSION__ */
