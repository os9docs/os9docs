/**
     \file       MediaHandlers.h

    \brief   QuickTime Interfaces.

    \introduced_in  QuickTime 5.0.1
    \avaliable_from Universal Interfaces 3.4.1

    \copyright © 1990-2001 by Apple Computer, Inc., all rights reserved

    \ingroup QuickTime

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __MEDIAHANDLERS__
#define __MEDIAHANDLERS__

#ifndef __CONDITIONALMACROS__
#include <ConditionalMacros.h>
#endif

#ifndef __MACTYPES__
#include <MacTypes.h>
#endif

#ifndef __COMPONENTS__
#include <Components.h>
#endif

#ifndef __SOUND__
#include <Sound.h>
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

    typedef CALLBACK_API(void, PrePrerollCompleteProcPtr)(MediaHandler mh,
                                                          OSErr err, void *refcon);
    typedef STACK_UPP_TYPE(PrePrerollCompleteProcPtr) PrePrerollCompleteUPP;
    enum
    {
        handlerHasSpatial = 1 << 0,
        handlerCanClip = 1 << 1,
        handlerCanMatte = 1 << 2,
        handlerCanTransferMode = 1 << 3,
        handlerNeedsBuffer = 1 << 4,
        handlerNoIdle = 1 << 5,
        handlerNoScheduler = 1 << 6,
        handlerWantsTime = 1 << 7,
        handlerCGrafPortOnly = 1 << 8,
        handlerCanSend = 1 << 9,
        handlerCanHandleComplexMatrix = 1 << 10,
        handlerWantsDestinationPixels = 1 << 11,
        handlerCanSendImageData = 1 << 12,
        handlerCanPicSave = 1 << 13
    };

    // media task flags
    enum
    {
        mMustDraw = 1 << 3,
        mAtEnd = 1 << 4,
        mPreflightDraw = 1 << 5,
        mSyncDrawing = 1 << 6,
        mPrecompositeOnly = 1 << 9,
        mSoundOnly = 1 << 10,
        mDoIdleActionsBeforeDraws = 1 << 11,
        mDisableIdleActions = 1 << 12
    };

    // media task result flags
    enum
    {
        mDidDraw = 1 << 0,
        mNeedsToDraw = 1 << 2,
        mDrawAgain = 1 << 3,
        mPartialDraw = 1 << 4,
        mWantIdleActions = 1 << 5
    };

    enum
    {
        forceUpdateRedraw = 1 << 0,
        forceUpdateNewBuffer = 1 << 1
    };

    // media hit test flags
    enum
    {
        mHitTestBounds =
            1L << 0, //    point must only be within targetRefCon's bounding box
        mHitTestImage =
            1L << 1,                 //  point must be within the shape of the targetRefCon's image
        mHitTestInvisible = 1L << 2, //  invisible targetRefCon's may be hit tested
        mHitTestIsClick = 1L << 3    //  for codecs that want mouse events
    };

    // media is opaque flags
    enum
    {
        mOpaque = 1L << 0,
        mInvisible = 1L << 1
    };

    // MediaSetPublicInfo/MediaGetPublicInfo selectors
    enum
    {
        kMediaQTIdleFrequencySelector = FOUR_CHAR_CODE('idfq')
    };

    struct GetMovieCompleteParams
    {
        short version;
        Movie theMovie;
        Track theTrack;
        Media theMedia;
        TimeScale movieScale;
        TimeScale mediaScale;
        TimeValue movieDuration;
        TimeValue trackDuration;
        TimeValue mediaDuration;
        Fixed effectiveRate;
        TimeBase timeBase;
        short volume;
        Fixed width;
        Fixed height;
        MatrixRecord trackMovieMatrix;
        CGrafPtr moviePort;
        GDHandle movieGD;
        PixMapHandle trackMatte;
        QTAtomContainer inputMap;
    };
    typedef struct GetMovieCompleteParams GetMovieCompleteParams;
    enum
    {
        kMediaVideoParamBrightness = 1,
        kMediaVideoParamContrast = 2,
        kMediaVideoParamHue = 3,
        kMediaVideoParamSharpness = 4,
        kMediaVideoParamSaturation = 5,
        kMediaVideoParamBlackLevel = 6,
        kMediaVideoParamWhiteLevel = 7
    };

    // These are for MediaGetInfo() and MediaSetInfo().
    enum
    {
        kMHInfoEncodedFrameRate =
            FOUR_CHAR_CODE('orat') // Parameter is a MHInfoEncodedFrameRateRecord*.
    };

    // This holds the frame rate at which the track was encoded.
    struct MHInfoEncodedFrameRateRecord
    {
        Fixed encodedFrameRate;
    };
    typedef struct MHInfoEncodedFrameRateRecord MHInfoEncodedFrameRateRecord;

    typedef Handle *dataHandlePtr;
    typedef dataHandlePtr *dataHandleHandle;

    struct QTCustomActionTargetRecord
    {
        Movie movie;
        DoMCActionUPP doMCActionCallbackProc;
        long callBackRefcon;
        Track track;
        long trackObjectRefCon;
        Track defaultTrack;
        long defaultObjectRefCon;
        long reserved1;
        long reserved2;
    };
    typedef struct QTCustomActionTargetRecord QTCustomActionTargetRecord;
    typedef QTCustomActionTargetRecord *QTCustomActionTargetPtr;
    struct MediaEQSpectrumBandsRecord
    {
        short count;
        UnsignedFixedPtr frequency; // pointer to array of frequencies
    };
    typedef struct MediaEQSpectrumBandsRecord MediaEQSpectrumBandsRecord;
    typedef MediaEQSpectrumBandsRecord *MediaEQSpectrumBandsRecordPtr;
    /**
     *  CallComponentExecuteWiredAction()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    CallComponentExecuteWiredAction(ComponentInstance ci,
                                    QTAtomContainer actionContainer,
                                    QTAtom actionAtom,
                                    QTCustomActionTargetPtr target,
                                    QTEventRecordPtr event);

    // MediaCallRange2
    // These are unique to each type of media handler
    // They are also included in the public interfaces

    /***** These are the calls for dealing with the Generic media handler *****/
    /**
     *  MediaInitialize()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaInitialize(MediaHandler mh, GetMovieCompleteParams *gmc);

    /**
     *  MediaSetHandlerCapabilities()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaSetHandlerCapabilities(MediaHandler mh, long flags, long flagsMask);

    /**
     *  MediaIdle()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaIdle(MediaHandler mh, TimeValue atMediaTime, long flagsIn, long *flagsOut,
              const TimeRecord *movieTime);

    /**
     *  MediaGetMediaInfo()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaGetMediaInfo(MediaHandler mh, Handle h);

    /**
     *  MediaPutMediaInfo()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaPutMediaInfo(MediaHandler mh, Handle h);

    /**
     *  MediaSetActive()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaSetActive(MediaHandler mh, Boolean enableMedia);

    /**
     *  MediaSetRate()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaSetRate(MediaHandler mh, Fixed rate);

    /**
     *  MediaGGetStatus()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaGGetStatus(MediaHandler mh, ComponentResult *statusErr);

    /**
     *  MediaTrackEdited()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaTrackEdited(MediaHandler mh);

    /**
     *  MediaSetMediaTimeScale()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaSetMediaTimeScale(MediaHandler mh, TimeScale newTimeScale);

    /**
     *  MediaSetMovieTimeScale()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaSetMovieTimeScale(MediaHandler mh, TimeScale newTimeScale);

    /**
     *  MediaSetGWorld()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaSetGWorld(MediaHandler mh, CGrafPtr aPort, GDHandle aGD);

    /**
     *  MediaSetDimensions()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaSetDimensions(MediaHandler mh, Fixed width, Fixed height);

    /**
     *  MediaSetClip()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaSetClip(MediaHandler mh, RgnHandle theClip);

    /**
     *  MediaSetMatrix()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaSetMatrix(MediaHandler mh, MatrixRecord *trackMovieMatrix);

    /**
     *  MediaGetTrackOpaque()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaGetTrackOpaque(MediaHandler mh, Boolean *trackIsOpaque);

    /**
     *  MediaSetGraphicsMode()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaSetGraphicsMode(MediaHandler mh, long mode, const RGBColor *opColor);

    /**
     *  MediaGetGraphicsMode()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaGetGraphicsMode(MediaHandler mh, long *mode, RGBColor *opColor);

    /**
     *  MediaGSetVolume()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaGSetVolume(MediaHandler mh, short volume);

    /**
     *  MediaSetSoundBalance()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaSetSoundBalance(MediaHandler mh, short balance);

    /**
     *  MediaGetSoundBalance()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaGetSoundBalance(MediaHandler mh, short *balance);

    /**
     *  MediaGetNextBoundsChange()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaGetNextBoundsChange(MediaHandler mh, TimeValue *when);

    /**
     *  MediaGetSrcRgn()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaGetSrcRgn(MediaHandler mh, RgnHandle rgn, TimeValue atMediaTime);

    /**
     *  MediaPreroll()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaPreroll(MediaHandler mh, TimeValue time, Fixed rate);

    /**
     *  MediaSampleDescriptionChanged()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaSampleDescriptionChanged(MediaHandler mh, long index);

    /**
     *  MediaHasCharacteristic()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaHasCharacteristic(MediaHandler mh, OSType characteristic, Boolean *hasIt);

    /**
     *  MediaGetOffscreenBufferSize()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaGetOffscreenBufferSize(MediaHandler mh, Rect *bounds, short depth,
                                CTabHandle ctab);

    /**
     *  MediaSetHints()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaSetHints(MediaHandler mh, long hints);

    /**
     *  MediaGetName()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaGetName(MediaHandler mh, Str255 name, long requestedLanguage,
                 long *actualLanguage);

    /**
     *  MediaForceUpdate()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaForceUpdate(MediaHandler mh, long forceUpdateFlags);

    /**
     *  MediaGetDrawingRgn()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaGetDrawingRgn(MediaHandler mh, RgnHandle *partialRgn);

    /**
     *  MediaGSetActiveSegment()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaGSetActiveSegment(MediaHandler mh, TimeValue activeStart,
                           TimeValue activeDuration);

    /**
     *  MediaInvalidateRegion()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaInvalidateRegion(MediaHandler mh, RgnHandle invalRgn);

    /**
     *  MediaGetNextStepTime()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaGetNextStepTime(MediaHandler mh, short flags, TimeValue mediaTimeIn,
                         TimeValue *mediaTimeOut, Fixed rate);

    /**
     *  MediaSetNonPrimarySourceData()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaSetNonPrimarySourceData(MediaHandler mh, long inputIndex,
                                 long dataDescriptionSeed, Handle dataDescription,
                                 void *data, long dataSize,
                                 ICMCompletionProcRecordPtr asyncCompletionProc,
                                 ICMConvertDataFormatUPP transferProc, void *refCon);

    /**
     *  MediaChangedNonPrimarySource()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaChangedNonPrimarySource(MediaHandler mh, long inputIndex);

    /**
     *  MediaTrackReferencesChanged()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaTrackReferencesChanged(MediaHandler mh);

    /**
     *  MediaGetSampleDataPointer()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaGetSampleDataPointer(MediaHandler mh, long sampleNum, Ptr *dataPtr,
                              long *dataSize, long *sampleDescIndex);

    /**
     *  MediaReleaseSampleDataPointer()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaReleaseSampleDataPointer(MediaHandler mh, long sampleNum);

    /**
     *  MediaTrackPropertyAtomChanged()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaTrackPropertyAtomChanged(MediaHandler mh);

    /**
     *  MediaSetTrackInputMapReference()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaSetTrackInputMapReference(MediaHandler mh, QTAtomContainer inputMap);

    /**
     *  MediaSetVideoParam()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaSetVideoParam(MediaHandler mh, long whichParam, unsigned short *value);

    /**
     *  MediaGetVideoParam()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaGetVideoParam(MediaHandler mh, long whichParam, unsigned short *value);

    /**
     *  MediaCompare()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaCompare(MediaHandler mh, Boolean *isOK, Media srcMedia,
                 ComponentInstance srcMediaComponent);

    /**
     *  MediaGetClock()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaGetClock(MediaHandler mh, ComponentInstance *clock);

    /**
     *  MediaSetSoundOutputComponent()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaSetSoundOutputComponent(MediaHandler mh, Component outputComponent);

    /**
     *  MediaGetSoundOutputComponent()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaGetSoundOutputComponent(MediaHandler mh, Component *outputComponent);

    /**
     *  MediaSetSoundLocalizationData()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaSetSoundLocalizationData(MediaHandler mh, Handle data);

    /**
     *  MediaGetInvalidRegion()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaGetInvalidRegion(MediaHandler mh, RgnHandle rgn);

    /**
     *  MediaSampleDescriptionB2N()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.1 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaSampleDescriptionB2N(MediaHandler mh,
                              SampleDescriptionHandle sampleDescriptionH);

    /**
     *  MediaSampleDescriptionN2B()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.1 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaSampleDescriptionN2B(MediaHandler mh,
                              SampleDescriptionHandle sampleDescriptionH);

    /**
     *  MediaQueueNonPrimarySourceData()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaQueueNonPrimarySourceData(MediaHandler mh, long inputIndex,
                                   long dataDescriptionSeed, Handle dataDescription,
                                   void *data, long dataSize,
                                   ICMCompletionProcRecordPtr asyncCompletionProc,
                                   const ICMFrameTimeRecord *frameTime,
                                   ICMConvertDataFormatUPP transferProc,
                                   void *refCon);

    /**
     *  MediaFlushNonPrimarySourceData()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaFlushNonPrimarySourceData(MediaHandler mh, long inputIndex);

    /**
     *  MediaGetURLLink()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaGetURLLink(MediaHandler mh, Point displayWhere, Handle *urlLink);

    /**
     *  MediaMakeMediaTimeTable()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaMakeMediaTimeTable(MediaHandler mh, long **offsets, TimeValue startTime,
                            TimeValue endTime, TimeValue timeIncrement,
                            short firstDataRefIndex, short lastDataRefIndex,
                            long *retDataRefSkew);

    /**
     *  MediaHitTestForTargetRefCon()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaHitTestForTargetRefCon(MediaHandler mh, long flags, Point loc,
                                long *targetRefCon);

    /**
     *  MediaHitTestTargetRefCon()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaHitTestTargetRefCon(MediaHandler mh, long targetRefCon, long flags,
                             Point loc, Boolean *wasHit);

    /**
     *  MediaGetActionsForQTEvent()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaGetActionsForQTEvent(MediaHandler mh, QTEventRecordPtr event,
                              long targetRefCon, QTAtomContainer *container,
                              QTAtom *atom);

    /**
     *  MediaDisposeTargetRefCon()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaDisposeTargetRefCon(MediaHandler mh, long targetRefCon);

    /**
     *  MediaTargetRefConsEqual()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaTargetRefConsEqual(MediaHandler mh, long firstRefCon, long secondRefCon,
                            Boolean *equal);

    /**
     *  MediaSetActionsCallback()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaSetActionsCallback(MediaHandler mh, ActionsUPP actionsCallbackProc,
                            void *refcon);

    /**
     *  MediaPrePrerollBegin()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaPrePrerollBegin(MediaHandler mh, TimeValue time, Fixed rate,
                         PrePrerollCompleteUPP completeProc, void *refcon);

    /**
     *  MediaPrePrerollCancel()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaPrePrerollCancel(MediaHandler mh, void *refcon);

    /**
     *  MediaEnterEmptyEdit()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaEnterEmptyEdit(MediaHandler mh);

    /**
     *  MediaCurrentMediaQueuedData()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaCurrentMediaQueuedData(MediaHandler mh, long *milliSecs);

    /**
     *  MediaGetEffectiveVolume()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    MediaGetEffectiveVolume(MediaHandler mh, short *volume);

    /**
     *  MediaResolveTargetRefCon()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    MediaResolveTargetRefCon(MediaHandler mh, QTAtomContainer container,
                             QTAtom atom, long *targetRefCon);

    /**
     *  MediaGetSoundLevelMeteringEnabled()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    MediaGetSoundLevelMeteringEnabled(MediaHandler mh, Boolean *enabled);

    /**
     *  MediaSetSoundLevelMeteringEnabled()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    MediaSetSoundLevelMeteringEnabled(MediaHandler mh, Boolean enable);

    /**
     *  MediaGetSoundLevelMeterInfo()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    MediaGetSoundLevelMeterInfo(MediaHandler mh, LevelMeterInfoPtr levelInfo);

    /**
     *  MediaGetEffectiveSoundBalance()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    MediaGetEffectiveSoundBalance(MediaHandler mh, short *balance);

    /**
     *  MediaSetScreenLock()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    MediaSetScreenLock(MediaHandler mh, Boolean lockIt);

    /**
     *  MediaSetDoMCActionCallback()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    MediaSetDoMCActionCallback(MediaHandler mh,
                               DoMCActionUPP doMCActionCallbackProc, void *refcon);

    /**
     *  MediaGetErrorString()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    MediaGetErrorString(MediaHandler mh, ComponentResult theError,
                        Str255 errorString);

    /**
     *  MediaGetSoundEqualizerBands()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    MediaGetSoundEqualizerBands(MediaHandler mh,
                                MediaEQSpectrumBandsRecordPtr spectrumInfo);

    /**
     *  MediaSetSoundEqualizerBands()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    MediaSetSoundEqualizerBands(MediaHandler mh,
                                MediaEQSpectrumBandsRecordPtr spectrumInfo);

    /**
     *  MediaGetSoundEqualizerBandLevels()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    MediaGetSoundEqualizerBandLevels(MediaHandler mh, UInt8 *bandLevels);

    /**
     *  MediaDoIdleActions()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    MediaDoIdleActions(MediaHandler mh);

    /**
     *  MediaSetSoundBassAndTreble()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    MediaSetSoundBassAndTreble(MediaHandler mh, short bass, short treble);

    /**
     *  MediaGetSoundBassAndTreble()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    MediaGetSoundBassAndTreble(MediaHandler mh, short *bass, short *treble);

    /**
     *  MediaTimeBaseChanged()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    MediaTimeBaseChanged(MediaHandler mh);

    /**
     *  MediaMCIsPlayerEvent()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.1 and later
     *    \carbon_lib        in CarbonLib 1.1 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.1 and later
     */
    ComponentResult
    MediaMCIsPlayerEvent(MediaHandler mh, const EventRecord *e, Boolean *handledIt);

    /**
     *  MediaGetMediaLoadState()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.1 and later
     *    \carbon_lib        in CarbonLib 1.1 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.1 and later
     */
    ComponentResult
    MediaGetMediaLoadState(MediaHandler mh, long *mediaLoadState);

    /**
     *  MediaVideoOutputChanged()
     *

     *    \non_carbon_cfm   in QuickTimeLib 5.0 and later
     *    \carbon_lib        in CarbonLib 1.3 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 5.0 and later
     */
    ComponentResult
    MediaVideoOutputChanged(MediaHandler mh, ComponentInstance vout);

    /**
     *  MediaEmptySampleCache()
     *

     *    \non_carbon_cfm   in QuickTimeLib 5.0 and later
     *    \carbon_lib        in CarbonLib 1.3 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 5.0 and later
     */
    ComponentResult
    MediaEmptySampleCache(MediaHandler mh, long sampleNum, long sampleCount);

    /**
     *  MediaGetPublicInfo()
     *

     *    \non_carbon_cfm   in QuickTimeLib 5.0 and later
     *    \carbon_lib        in CarbonLib 1.3 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 5.0 and later
     */
    ComponentResult
    MediaGetPublicInfo(MediaHandler mh, OSType infoSelector, void *infoDataPtr,
                       Size *ioDataSize);

    /**
     *  MediaSetPublicInfo()
     *

     *    \non_carbon_cfm   in QuickTimeLib 5.0 and later
     *    \carbon_lib        in CarbonLib 1.3 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 5.0 and later
     */
    ComponentResult
    MediaSetPublicInfo(MediaHandler mh, OSType infoSelector, void *infoDataPtr,
                       Size dataSize);

    /**
     *  MediaGetUserPreferredCodecs()
     *

     *    \non_carbon_cfm   in QuickTimeLib 5.0 and later
     *    \carbon_lib        in CarbonLib 1.3 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 5.0 and later
     */
    ComponentResult
    MediaGetUserPreferredCodecs(MediaHandler mh,
                                CodecComponentHandle *userPreferredCodecs);

    /**
     *  MediaSetUserPreferredCodecs()
     *

     *    \non_carbon_cfm   in QuickTimeLib 5.0 and later
     *    \carbon_lib        in CarbonLib 1.3 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 5.0 and later
     */
    ComponentResult
    MediaSetUserPreferredCodecs(MediaHandler mh,
                                CodecComponentHandle userPreferredCodecs);

    // selectors for component calls
    enum
    {
        kCallComponentExecuteWiredActionSelect = -9,
        kMediaInitializeSelect = 0x0501,
        kMediaSetHandlerCapabilitiesSelect = 0x0502,
        kMediaIdleSelect = 0x0503,
        kMediaGetMediaInfoSelect = 0x0504,
        kMediaPutMediaInfoSelect = 0x0505,
        kMediaSetActiveSelect = 0x0506,
        kMediaSetRateSelect = 0x0507,
        kMediaGGetStatusSelect = 0x0508,
        kMediaTrackEditedSelect = 0x0509,
        kMediaSetMediaTimeScaleSelect = 0x050A,
        kMediaSetMovieTimeScaleSelect = 0x050B,
        kMediaSetGWorldSelect = 0x050C,
        kMediaSetDimensionsSelect = 0x050D,
        kMediaSetClipSelect = 0x050E,
        kMediaSetMatrixSelect = 0x050F,
        kMediaGetTrackOpaqueSelect = 0x0510,
        kMediaSetGraphicsModeSelect = 0x0511,
        kMediaGetGraphicsModeSelect = 0x0512,
        kMediaGSetVolumeSelect = 0x0513,
        kMediaSetSoundBalanceSelect = 0x0514,
        kMediaGetSoundBalanceSelect = 0x0515,
        kMediaGetNextBoundsChangeSelect = 0x0516,
        kMediaGetSrcRgnSelect = 0x0517,
        kMediaPrerollSelect = 0x0518,
        kMediaSampleDescriptionChangedSelect = 0x0519,
        kMediaHasCharacteristicSelect = 0x051A,
        kMediaGetOffscreenBufferSizeSelect = 0x051B,
        kMediaSetHintsSelect = 0x051C,
        kMediaGetNameSelect = 0x051D,
        kMediaForceUpdateSelect = 0x051E,
        kMediaGetDrawingRgnSelect = 0x051F,
        kMediaGSetActiveSegmentSelect = 0x0520,
        kMediaInvalidateRegionSelect = 0x0521,
        kMediaGetNextStepTimeSelect = 0x0522,
        kMediaSetNonPrimarySourceDataSelect = 0x0523,
        kMediaChangedNonPrimarySourceSelect = 0x0524,
        kMediaTrackReferencesChangedSelect = 0x0525,
        kMediaGetSampleDataPointerSelect = 0x0526,
        kMediaReleaseSampleDataPointerSelect = 0x0527,
        kMediaTrackPropertyAtomChangedSelect = 0x0528,
        kMediaSetTrackInputMapReferenceSelect = 0x0529,
        kMediaSetVideoParamSelect = 0x052B,
        kMediaGetVideoParamSelect = 0x052C,
        kMediaCompareSelect = 0x052D,
        kMediaGetClockSelect = 0x052E,
        kMediaSetSoundOutputComponentSelect = 0x052F,
        kMediaGetSoundOutputComponentSelect = 0x0530,
        kMediaSetSoundLocalizationDataSelect = 0x0531,
        kMediaGetInvalidRegionSelect = 0x053C,
        kMediaSampleDescriptionB2NSelect = 0x053E,
        kMediaSampleDescriptionN2BSelect = 0x053F,
        kMediaQueueNonPrimarySourceDataSelect = 0x0540,
        kMediaFlushNonPrimarySourceDataSelect = 0x0541,
        kMediaGetURLLinkSelect = 0x0543,
        kMediaMakeMediaTimeTableSelect = 0x0545,
        kMediaHitTestForTargetRefConSelect = 0x0546,
        kMediaHitTestTargetRefConSelect = 0x0547,
        kMediaGetActionsForQTEventSelect = 0x0548,
        kMediaDisposeTargetRefConSelect = 0x0549,
        kMediaTargetRefConsEqualSelect = 0x054A,
        kMediaSetActionsCallbackSelect = 0x054B,
        kMediaPrePrerollBeginSelect = 0x054C,
        kMediaPrePrerollCancelSelect = 0x054D,
        kMediaEnterEmptyEditSelect = 0x054F,
        kMediaCurrentMediaQueuedDataSelect = 0x0550,
        kMediaGetEffectiveVolumeSelect = 0x0551,
        kMediaResolveTargetRefConSelect = 0x0552,
        kMediaGetSoundLevelMeteringEnabledSelect = 0x0553,
        kMediaSetSoundLevelMeteringEnabledSelect = 0x0554,
        kMediaGetSoundLevelMeterInfoSelect = 0x0555,
        kMediaGetEffectiveSoundBalanceSelect = 0x0556,
        kMediaSetScreenLockSelect = 0x0557,
        kMediaSetDoMCActionCallbackSelect = 0x0558,
        kMediaGetErrorStringSelect = 0x0559,
        kMediaGetSoundEqualizerBandsSelect = 0x055A,
        kMediaSetSoundEqualizerBandsSelect = 0x055B,
        kMediaGetSoundEqualizerBandLevelsSelect = 0x055C,
        kMediaDoIdleActionsSelect = 0x055D,
        kMediaSetSoundBassAndTrebleSelect = 0x055E,
        kMediaGetSoundBassAndTrebleSelect = 0x055F,
        kMediaTimeBaseChangedSelect = 0x0560,
        kMediaMCIsPlayerEventSelect = 0x0561,
        kMediaGetMediaLoadStateSelect = 0x0562,
        kMediaVideoOutputChangedSelect = 0x0563,
        kMediaEmptySampleCacheSelect = 0x0564,
        kMediaGetPublicInfoSelect = 0x0565,
        kMediaSetPublicInfoSelect = 0x0566,
        kMediaGetUserPreferredCodecsSelect = 0x0567,
        kMediaSetUserPreferredCodecsSelect = 0x0568
    };
#if CALL_NOT_IN_CARBON
    /**
     *  NewPrePrerollCompleteUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    PrePrerollCompleteUPP
    NewPrePrerollCompleteUPP(PrePrerollCompleteProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
    enum
    {
        uppPrePrerollCompleteProcInfo = 0x00000EC0
    }; // pascal no_return_value Func(4_bytes, 2_bytes, 4_bytes)
#ifdef __cplusplus
    inline PrePrerollCompleteUPP
    NewPrePrerollCompleteUPP(PrePrerollCompleteProcPtr userRoutine)
    {
        return (PrePrerollCompleteUPP)NewRoutineDescriptor(
            (ProcPtr)(userRoutine), uppPrePrerollCompleteProcInfo,
            GetCurrentArchitecture());
    }
#else
#define NewPrePrerollCompleteUPP(userRoutine)                                   \
    (PrePrerollCompleteUPP) NewRoutineDescriptor((ProcPtr)(userRoutine),        \
                                                 uppPrePrerollCompleteProcInfo, \
                                                 GetCurrentArchitecture())
#endif
#endif

    /**
     *  DisposePrePrerollCompleteUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    DisposePrePrerollCompleteUPP(PrePrerollCompleteUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline void DisposePrePrerollCompleteUPP(PrePrerollCompleteUPP userUPP)
    {
        DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
    }
#else
#define DisposePrePrerollCompleteUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

    /**
     *  InvokePrePrerollCompleteUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    InvokePrePrerollCompleteUPP(MediaHandler mh, OSErr err, void *refcon,
                                PrePrerollCompleteUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline void InvokePrePrerollCompleteUPP(MediaHandler mh, OSErr err,
                                            void *refcon,
                                            PrePrerollCompleteUPP userUPP)
    {
        CALL_THREE_PARAMETER_UPP(userUPP, uppPrePrerollCompleteProcInfo, mh, err,
                                 refcon);
    }
#else
#define InvokePrePrerollCompleteUPP(mh, err, refcon, userUPP)                \
    CALL_THREE_PARAMETER_UPP((userUPP), uppPrePrerollCompleteProcInfo, (mh), \
                             (err), (refcon))
#endif
#endif

#endif // CALL_NOT_IN_CARBON

#if CALL_NOT_IN_CARBON || OLDROUTINENAMES
// support for pre-Carbon UPP routines: New...Proc and Call...Proc
#define NewPrePrerollCompleteProc(userRoutine) \
    NewPrePrerollCompleteUPP(userRoutine)
#define CallPrePrerollCompleteProc(userRoutine, mh, err, refcon) \
    InvokePrePrerollCompleteUPP(mh, err, refcon, userRoutine)
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

#endif // __MEDIAHANDLERS__
