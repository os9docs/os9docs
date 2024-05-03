/**
     \file       Movies.h

    \brief   QuickTime Interfaces.

    \introduced_in  QuickTime 5.0.1
    \avaliable_from Universal Interfaces 3.4.1

    \copyright © 1990-2001 by Apple Computer, Inc., all rights reserved

    \ingroup QuickTime

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __MOVIES__
#define __MOVIES__

#ifndef __QUICKDRAW__
#include <Quickdraw.h>
#endif

#ifndef __ALIASES__
#include <Aliases.h>
#endif

#ifndef __EVENTS__
#include <Events.h>
#endif

#ifndef __MENUS__
#include <Menus.h>
#endif

#ifndef __COMPONENTS__
#include <Components.h>
#endif

#ifndef __SOUND__
#include <Sound.h>
#endif

#ifndef __IMAGECOMPRESSION__
#include <ImageCompression.h>
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

    /*  "kFix1" is defined in FixMath as "fixed1"  */
    /* error codes are in Errors.[haa] */
    /* gestalt codes are in Gestalt.[hpa] */
    enum
    {
        MovieFileType = FOUR_CHAR_CODE('MooV'),
        MovieScrapType = FOUR_CHAR_CODE('moov')
    };

    enum
    {
        MovieResourceType = FOUR_CHAR_CODE('moov'),
        MovieForwardPointerResourceType = FOUR_CHAR_CODE('fore'),
        MovieBackwardPointerResourceType = FOUR_CHAR_CODE('back')
    };

    enum
    {
        MovieResourceAtomType = FOUR_CHAR_CODE('moov'),
        MovieDataAtomType = FOUR_CHAR_CODE('mdat'),
        FreeAtomType = FOUR_CHAR_CODE('free'),
        SkipAtomType = FOUR_CHAR_CODE('skip'),
        WideAtomPlaceholderType = FOUR_CHAR_CODE('wide')
    };

    enum
    {
        MediaHandlerType = FOUR_CHAR_CODE('mhlr'),
        DataHandlerType = FOUR_CHAR_CODE('dhlr')
    };

    enum
    {
        VideoMediaType = FOUR_CHAR_CODE('vide'),
        SoundMediaType = FOUR_CHAR_CODE('soun'),
        TextMediaType = FOUR_CHAR_CODE('text'),
        BaseMediaType = FOUR_CHAR_CODE('gnrc'),
        MPEGMediaType = FOUR_CHAR_CODE('MPEG'),
        MusicMediaType = FOUR_CHAR_CODE('musi'),
        TimeCodeMediaType = FOUR_CHAR_CODE('tmcd'),
        SpriteMediaType = FOUR_CHAR_CODE('sprt'),
        FlashMediaType = FOUR_CHAR_CODE('flsh'),
        MovieMediaType = FOUR_CHAR_CODE('moov'),
        TweenMediaType = FOUR_CHAR_CODE('twen'),
        ThreeDeeMediaType = FOUR_CHAR_CODE('qd3d'),
        HandleDataHandlerSubType = FOUR_CHAR_CODE('hndl'),
        PointerDataHandlerSubType = FOUR_CHAR_CODE('ptr '),
        NullDataHandlerSubType = FOUR_CHAR_CODE('null'),
        ResourceDataHandlerSubType = FOUR_CHAR_CODE('rsrc'),
        URLDataHandlerSubType = FOUR_CHAR_CODE('url '),
        WiredActionHandlerType = FOUR_CHAR_CODE('wire')
    };

    enum
    {
        VisualMediaCharacteristic = FOUR_CHAR_CODE('eyes'),
        AudioMediaCharacteristic = FOUR_CHAR_CODE('ears'),
        kCharacteristicCanSendVideo = FOUR_CHAR_CODE('vsnd'),
        kCharacteristicProvidesActions = FOUR_CHAR_CODE('actn'),
        kCharacteristicNonLinear = FOUR_CHAR_CODE('nonl'),
        kCharacteristicCanStep = FOUR_CHAR_CODE('step'),
        kCharacteristicHasNoDuration = FOUR_CHAR_CODE('noti')
    };

    enum
    {
        kUserDataMovieControllerType = FOUR_CHAR_CODE('ctyp'),
        kUserDataName = FOUR_CHAR_CODE('name'),
        kUserDataTextAlbum = FOUR_CHAR_CODE('©alb'),
        kUserDataTextArtist = FOUR_CHAR_CODE('©ART'),
        kUserDataTextAuthor = FOUR_CHAR_CODE('©aut'),
        kUserDataTextChapter = FOUR_CHAR_CODE('©chp'),
        kUserDataTextComment = FOUR_CHAR_CODE('©cmt'),
        kUserDataTextComposer = FOUR_CHAR_CODE('©com'),
        kUserDataTextCopyright = FOUR_CHAR_CODE('©cpy'),
        kUserDataTextCreationDate = FOUR_CHAR_CODE('©day'),
        kUserDataTextDescription = FOUR_CHAR_CODE('©des'),
        kUserDataTextDirector = FOUR_CHAR_CODE('©dir'),
        kUserDataTextDisclaimer = FOUR_CHAR_CODE('©dis'),
        kUserDataTextEncodedBy = FOUR_CHAR_CODE('©enc'),
        kUserDataTextFullName = FOUR_CHAR_CODE('©nam'),
        kUserDataTextGenre = FOUR_CHAR_CODE('©gen'),
        kUserDataTextHostComputer = FOUR_CHAR_CODE('©hst'),
        kUserDataTextInformation = FOUR_CHAR_CODE('©inf'),
        kUserDataTextKeywords = FOUR_CHAR_CODE('©key'),
        kUserDataTextMake = FOUR_CHAR_CODE('©mak'),
        kUserDataTextModel = FOUR_CHAR_CODE('©mod'),
        kUserDataTextOriginalArtist = FOUR_CHAR_CODE('©ope'),
        kUserDataTextOriginalFormat = FOUR_CHAR_CODE('©fmt'),
        kUserDataTextOriginalSource = FOUR_CHAR_CODE('©src'),
        kUserDataTextPerformers = FOUR_CHAR_CODE('©prf'),
        kUserDataTextProducer = FOUR_CHAR_CODE('©prd'),
        kUserDataTextProduct = FOUR_CHAR_CODE('©PRD'),
        kUserDataTextSoftware = FOUR_CHAR_CODE('©swr'),
        kUserDataTextSpecialPlaybackRequirements = FOUR_CHAR_CODE('©req'),
        kUserDataTextTrack = FOUR_CHAR_CODE('©trk'),
        kUserDataTextWarning = FOUR_CHAR_CODE('©wrn'),
        kUserDataTextWriter = FOUR_CHAR_CODE('©wrt'),
        kUserDataTextURLLink = FOUR_CHAR_CODE('©url'),
        kUserDataTextEditDate1 = FOUR_CHAR_CODE('©ed1')
    };

    enum
    {
        kUserDataUnicodeBit = 1L << 7
    };

    enum
    {
        DoTheRightThing = 0
    };

    struct MovieRecord
    {
        long data[1];
    };
    typedef struct MovieRecord MovieRecord;
    typedef MovieRecord *Movie;
    typedef Movie *MoviePtr;
    struct TrackRecord
    {
        long data[1];
    };
    typedef struct TrackRecord TrackRecord;
    typedef TrackRecord *Track;
    struct MediaRecord
    {
        long data[1];
    };
    typedef struct MediaRecord MediaRecord;
    typedef MediaRecord *Media;
    struct UserDataRecord
    {
        long data[1];
    };
    typedef struct UserDataRecord UserDataRecord;
    typedef UserDataRecord *UserData;
    struct TrackEditStateRecord
    {
        long data[1];
    };
    typedef struct TrackEditStateRecord TrackEditStateRecord;
    typedef TrackEditStateRecord *TrackEditState;
    struct MovieEditStateRecord
    {
        long data[1];
    };
    typedef struct MovieEditStateRecord MovieEditStateRecord;
    typedef MovieEditStateRecord *MovieEditState;
    struct SpriteWorldRecord
    {
        long data[1];
    };
    typedef struct SpriteWorldRecord SpriteWorldRecord;
    typedef SpriteWorldRecord *SpriteWorld;
    struct SpriteRecord
    {
        long data[1];
    };
    typedef struct SpriteRecord SpriteRecord;
    typedef SpriteRecord *Sprite;
    struct QTTweenerRecord
    {
        long data[1];
    };
    typedef struct QTTweenerRecord QTTweenerRecord;
    typedef QTTweenerRecord *QTTweener;
    struct SampleDescription
    {
        long descSize;
        long dataFormat;
        long resvd1;
        short resvd2;
        short dataRefIndex;
    };
    typedef struct SampleDescription SampleDescription;
    typedef SampleDescription *SampleDescriptionPtr;
    typedef SampleDescriptionPtr *SampleDescriptionHandle;
    typedef struct OpaqueQTBandwidthReference *QTBandwidthReference;
    typedef struct OpaqueQTScheduledBandwidthReference
        *QTScheduledBandwidthReference;
    enum
    {
        kQTNetworkStatusNoNetwork = -2,
        kQTNetworkStatusUncertain = -1,
        kQTNetworkStatusNotConnected = 0,
        kQTNetworkStatusConnected = 1
    };

    typedef Handle QTAtomContainer;
    typedef long QTAtom;
    typedef long QTAtomType;
    typedef long QTAtomID;
    /* QTFloatDouble is the 64-bit IEEE-754 standard*/
    typedef Float64 QTFloatDouble;
    /* QTFloatSingle is the 32-bit IEEE-754 standard*/
    typedef Float32 QTFloatSingle;

    struct SoundDescription
    {
        long descSize;   /* total size of SoundDescription including extra data */
        long dataFormat; /* sound format */
        long resvd1;     /* reserved for apple use. set to zero */
        short resvd2;    /* reserved for apple use. set to zero */
        short dataRefIndex;
        short version;            /* which version is this data */
        short revlevel;           /* what version of that codec did this */
        long vendor;              /* whose  codec compressed this data */
        short numChannels;        /* number of channels of sound */
        short sampleSize;         /* number of bits per sample */
        short compressionID;      /* unused. set to zero. */
        short packetSize;         /* unused. set to zero. */
        UnsignedFixed sampleRate; /* sample rate sound is captured at */
    };
    typedef struct SoundDescription SoundDescription;
    typedef SoundDescription *SoundDescriptionPtr;
    typedef SoundDescriptionPtr *SoundDescriptionHandle;
    /* version 1 of the SoundDescription record*/
    struct SoundDescriptionV1
    {
        /* original fields*/
        SoundDescription desc;
        /* fixed compression ratio information*/
        unsigned long samplesPerPacket;
        unsigned long bytesPerPacket;
        unsigned long bytesPerFrame;
        unsigned long bytesPerSample;
        /* additional atom based fields ([long size, long type, some data], repeat)*/
    };
    typedef struct SoundDescriptionV1 SoundDescriptionV1;
    typedef SoundDescriptionV1 *SoundDescriptionV1Ptr;
    typedef SoundDescriptionV1Ptr *SoundDescriptionV1Handle;
    struct TextDescription
    {
        long descSize;   /* Total size of TextDescription*/
        long dataFormat; /* 'text'*/

        long resvd1;
        short resvd2;
        short dataRefIndex;

        long displayFlags; /* see enum below for flag values*/

        long textJustification; /* Can be: teCenter,teFlush -Default,-Right,-Left*/

        RGBColor bgColor; /* Background color*/

        Rect defaultTextBox;        /* Location to place the text within the track bounds*/
        ScrpSTElement defaultStyle; /* Default style (struct defined in TextEdit.h)*/
        char defaultFontName[1];    /* Font Name (pascal string - struct extended to fit)
                                     */
    };
    typedef struct TextDescription TextDescription;
    typedef TextDescription *TextDescriptionPtr;
    typedef TextDescriptionPtr *TextDescriptionHandle;
    struct SpriteDescription
    {
        long descSize;   /* total size of SpriteDescription including extra data */
        long dataFormat; /*  */
        long resvd1;     /* reserved for apple use */
        short resvd2;
        short dataRefIndex;
        long version; /* which version is this data */
        OSType
            decompressorType; /* which decompressor to use, 0 for no decompression */
        long sampleFlags;     /* how to interpret samples */
    };
    typedef struct SpriteDescription SpriteDescription;
    typedef SpriteDescription *SpriteDescriptionPtr;
    typedef SpriteDescriptionPtr *SpriteDescriptionHandle;
    struct FlashDescription
    {
        long descSize;
        long dataFormat;
        long resvd1;
        short resvd2;
        short dataRefIndex;
        long version; /* which version is this data */
        OSType
            decompressorType; /* which decompressor to use, 0 for no decompression */
        long flags;
    };
    typedef struct FlashDescription FlashDescription;
    typedef FlashDescription *FlashDescriptionPtr;
    typedef FlashDescriptionPtr *FlashDescriptionHandle;
    struct ThreeDeeDescription
    {
        long descSize;   /* total size of ThreeDeeDescription including extra data */
        long dataFormat; /*  */
        long resvd1;     /* reserved for apple use */
        short resvd2;
        short dataRefIndex;
        long version;          /* which version is this data */
        long rendererType;     /* which renderer to use, 0 for default */
        long decompressorType; /* which decompressor to use, 0 for default */
    };
    typedef struct ThreeDeeDescription ThreeDeeDescription;
    typedef ThreeDeeDescription *ThreeDeeDescriptionPtr;
    typedef ThreeDeeDescriptionPtr *ThreeDeeDescriptionHandle;
    struct DataReferenceRecord
    {
        OSType dataRefType;
        Handle dataRef;
    };
    typedef struct DataReferenceRecord DataReferenceRecord;
    typedef DataReferenceRecord *DataReferencePtr;
    /*--------------------------
      Music Sample Description
    --------------------------*/
    struct MusicDescription
    {
        long descSize;
        long dataFormat; /* 'musi' */

        long resvd1;
        short resvd2;
        short dataRefIndex;

        long musicFlags;
        unsigned long headerData[1]; /* variable size! */
    };
    typedef struct MusicDescription MusicDescription;
    typedef MusicDescription *MusicDescriptionPtr;
    typedef MusicDescriptionPtr *MusicDescriptionHandle;
    enum
    {
        kMusicFlagDontPlay2Soft = 1L << 0,
        kMusicFlagDontSlaveToMovie = 1L << 1
    };

    enum
    {
        dfDontDisplay = 1 << 0, /* Don't display the text*/
        dfDontAutoScale =
            1 << 1,               /* Don't scale text as track bounds grows or shrinks*/
        dfClipToTextBox = 1 << 2, /* Clip update to the textbox*/
        dfUseMovieBGColor =
            1 << 3,                    /* Set text background to movie's background color*/
        dfShrinkTextBoxToFit = 1 << 4, /* Compute minimum box to fit the sample*/
        dfScrollIn = 1 << 5,           /* Scroll text in until last of text is in view */
        dfScrollOut = 1 << 6,          /* Scroll text out until last of text is gone (if both
                                          set, scroll in then out)*/
        dfHorizScroll =
            1 << 7,               /* Scroll text horizontally (otherwise it's vertical)*/
        dfReverseScroll = 1 << 8, /* vert: scroll down rather than up; horiz: scroll
                                     backwards (justfication dependent)*/
        dfContinuousScroll =
            1 << 9,                    /* new samples cause previous samples to scroll out */
        dfFlowHoriz = 1 << 10,         /* horiz scroll text flows in textbox rather than
                                          extend to right */
        dfContinuousKaraoke = 1 << 11, /* ignore begin offset, hilite everything up to
                                          the end offset(karaoke)*/
        dfDropShadow = 1 << 12,        /* display text with a drop shadow */
        dfAntiAlias = 1 << 13,         /* attempt to display text anti aliased*/
        dfKeyedText = 1 << 14,         /* key the text over background*/
        dfInverseHilite =
            1 << 15,                /* Use inverse hiliting rather than using hilite color*/
        dfTextColorHilite = 1 << 16 /* changes text color in place of hiliting. */
    };

    enum
    {
        searchTextDontGoToFoundTime = 1L << 16,
        searchTextDontHiliteFoundText = 1L << 17,
        searchTextOneTrackOnly = 1L << 18,
        searchTextEnabledTracksOnly = 1L << 19
    };

    /*use these with the text property routines*/
    enum
    {
        /* set property parameter / get property parameter*/
        kTextTextHandle = 1,      /* Handle / preallocated Handle*/
        kTextTextPtr = 2,         /* Pointer*/
        kTextTEStyle = 3,         /* TextStyle * / TextStyle **/
        kTextSelection = 4,       /* long [2] / long [2]*/
        kTextBackColor = 5,       /* RGBColor * / RGBColor **/
        kTextForeColor = 6,       /* RGBColor * / RGBColor **/
        kTextFace = 7,            /* long / long **/
        kTextFont = 8,            /* long / long **/
        kTextSize = 9,            /* long / long **/
        kTextAlignment = 10,      /* short * / short **/
        kTextHilite = 11,         /* hiliteRecord * / hiliteRecord **/
        kTextDropShadow = 12,     /* dropShadowRecord * / dropShadowRecord **/
        kTextDisplayFlags = 13,   /* long / long **/
        kTextScroll = 14,         /* TimeValue * / TimeValue **/
        kTextRelativeScroll = 15, /* Point **/
        kTextHyperTextFace = 16,  /* hyperTextSetFace * / hyperTextSetFace **/
        kTextHyperTextColor = 17, /* hyperTextSetColor * / hyperTextSetColor **/
        kTextKeyEntry = 18,       /* short*/
        kTextMouseDown = 19,      /* Point **/
        kTextTextBox = 20,        /* Rect * / Rect **/
        kTextEditState = 21,      /* short / short **/
        kTextLength = 22          /*       / long **/
    };

    enum
    {
        k3DMediaRendererEntry = FOUR_CHAR_CODE('rend'),
        k3DMediaRendererName = FOUR_CHAR_CODE('name'),
        k3DMediaRendererCode = FOUR_CHAR_CODE('rcod')
    };

    /* progress messages */
    enum
    {
        movieProgressOpen = 0,
        movieProgressUpdatePercent = 1,
        movieProgressClose = 2
    };

    /* progress operations */
    enum
    {
        progressOpFlatten = 1,
        progressOpInsertTrackSegment = 2,
        progressOpInsertMovieSegment = 3,
        progressOpPaste = 4,
        progressOpAddMovieSelection = 5,
        progressOpCopy = 6,
        progressOpCut = 7,
        progressOpLoadMovieIntoRam = 8,
        progressOpLoadTrackIntoRam = 9,
        progressOpLoadMediaIntoRam = 10,
        progressOpImportMovie = 11,
        progressOpExportMovie = 12
    };

    enum
    {
        mediaQualityDraft = 0x0000,
        mediaQualityNormal = 0x0040,
        mediaQualityBetter = 0x0080,
        mediaQualityBest = 0x00C0
    };

    /*****
        Interactive Sprites Support
    *****/
    /* QTEventRecord flags*/
    enum
    {
        kQTEventPayloadIsQTList = 1L << 0
    };

    struct QTEventRecord
    {
        long version;
        OSType eventType;
        Point where;
        long flags;
        long payloadRefcon; /* from here down only present if version >= 2*/
        long param1;
        long param2;
        long param3;
    };
    typedef struct QTEventRecord QTEventRecord;
    typedef QTEventRecord *QTEventRecordPtr;
    struct QTAtomSpec
    {
        QTAtomContainer container;
        QTAtom atom;
    };
    typedef struct QTAtomSpec QTAtomSpec;
    typedef QTAtomSpec *QTAtomSpecPtr;
    struct ResolvedQTEventSpec
    {
        QTAtomSpec actionAtom;
        Track targetTrack;
        long targetRefCon;
    };
    typedef struct ResolvedQTEventSpec ResolvedQTEventSpec;
    typedef ResolvedQTEventSpec *ResolvedQTEventSpecPtr;

    /* action constants */
    enum
    {
        kActionMovieSetVolume = 1024,       /* (short movieVolume) */
        kActionMovieSetRate = 1025,         /* (Fixed rate) */
        kActionMovieSetLoopingFlags = 1026, /* (long loopingFlags) */
        kActionMovieGoToTime = 1027,        /* (TimeValue time) */
        kActionMovieGoToTimeByName = 1028,  /* (Str255 timeName) */
        kActionMovieGoToBeginning = 1029,   /* no params */
        kActionMovieGoToEnd = 1030,         /* no params */
        kActionMovieStepForward = 1031,     /* no params */
        kActionMovieStepBackward = 1032,    /* no params */
        kActionMovieSetSelection =
            1033, /* (TimeValue startTime, TimeValue endTime) */
        kActionMovieSetSelectionByName =
            1034,                         /* (Str255 startTimeName, Str255 endTimeName) */
        kActionMoviePlaySelection = 1035, /* (Boolean selectionOnly) */
        kActionMovieSetLanguage = 1036,   /* (long language) */
        kActionMovieChanged = 1037,       /* no params */
        kActionMovieRestartAtTime = 1038, /* (TimeValue startTime, Fixed rate) */
        kActionTrackSetVolume = 2048,     /* (short volume) */
        kActionTrackSetBalance = 2049,    /* (short balance) */
        kActionTrackSetEnabled = 2050,    /* (Boolean enabled) */
        kActionTrackSetMatrix = 2051,     /* (MatrixRecord matrix) */
        kActionTrackSetLayer = 2052,      /* (short layer) */
        kActionTrackSetClip = 2053,       /* (RgnHandle clip) */
        kActionTrackSetCursor = 2054,     /* (QTATomID cursorID) */
        kActionTrackSetGraphicsMode =
            2055,                            /* (ModifierTrackGraphicsModeRecord graphicsMode) */
        kActionTrackSetIdleFrequency = 2056, /* (long frequency) */
        kActionTrackSetBassTreble = 2057,    /* (short base, short treble) */
        kActionSpriteSetMatrix = 3072,       /* (MatrixRecord matrix) */
        kActionSpriteSetImageIndex = 3073,   /* (short imageIndex) */
        kActionSpriteSetVisible = 3074,      /* (short visible) */
        kActionSpriteSetLayer = 3075,        /* (short layer) */
        kActionSpriteSetGraphicsMode =
            3076,                             /* (ModifierTrackGraphicsModeRecord graphicsMode) */
        kActionSpritePassMouseToCodec = 3078, /* no params */
        kActionSpriteClickOnCodec = 3079,     /* Point localLoc */
        kActionSpriteTranslate = 3080,        /* (Fixed x, Fixed y, Boolean isAbsolute) */
        kActionSpriteScale = 3081,            /* (Fixed xScale, Fixed yScale) */
        kActionSpriteRotate = 3082,           /* (Fixed degrees) */
        kActionSpriteStretch = 3083,          /* (Fixed p1x, Fixed p1y, Fixed p2x, Fixed p2y,
                                                 Fixed p3x, Fixed p3y, Fixed p4x, Fixed p4y) */
        kActionQTVRSetPanAngle = 4096,        /* (float panAngle) */
        kActionQTVRSetTiltAngle = 4097,       /* (float tiltAngle) */
        kActionQTVRSetFieldOfView = 4098,     /* (float fieldOfView) */
        kActionQTVRShowDefaultView = 4099,    /* no params */
        kActionQTVRGoToNodeID = 4100,         /* (UInt32 nodeID) */
        kActionQTVREnableHotSpot = 4101,      /* long ID, Boolean enable */
        kActionQTVRShowHotSpots = 4102,       /* Boolean show */
        kActionQTVRTranslateObject = 4103,    /* float xMove, float yMove */
        kActionMusicPlayNote =
            5120, /* (long sampleDescIndex, long partNumber, long delay, long pitch,
                     long velocity, long duration) */
        kActionMusicSetController =
            5121,              /* (long sampleDescIndex, long partNumber, long delay, long
                                  controller, long value) */
        kActionCase = 6144,    /* [(CaseStatementActionAtoms)] */
        kActionWhile = 6145,   /* [(WhileStatementActionAtoms)] */
        kActionGoToURL = 6146, /* (C string urlLink) */
        kActionSendQTEventToSprite =
            6147,                               /* ([(SpriteTargetAtoms)], QTEventRecord theEvent) */
        kActionDebugStr = 6148,                 /* (Str255 theString) */
        kActionPushCurrentTime = 6149,          /* no params */
        kActionPushCurrentTimeWithLabel = 6150, /* (Str255 theLabel) */
        kActionPopAndGotoTopTime = 6151,        /* no params */
        kActionPopAndGotoLabeledTime = 6152,    /* (Str255 theLabel) */
        kActionStatusString = 6153,             /* (C string theString, long stringTypeFlags) */
        kActionSendQTEventToTrackObject =
            6154, /* ([(TrackObjectTargetAtoms)], QTEventRecord theEvent) */
        kActionAddChannelSubscription =
            6155,                                /* (Str255 channelName, C string channelsURL, C string
                                                    channelsPictureURL) */
        kActionRemoveChannelSubscription = 6156, /* (C string channelsURL) */
        kActionOpenCustomActionHandler =
            6157, /* (long handlerID, ComponentDescription handlerDesc) */
        kActionDoScript =
            6158, /* (long scriptTypeFlags, CString command, CString arguments) */
        kActionDoCompressedActions =
            6159,                             /* (compressed QTAtomContainer prefixed with eight bytes: long
                                                 compressorType, long decompressedSize) */
        kActionSendAppMessage = 6160,         /* (long appMessageID) */
        kActionLoadComponent = 6161,          /* (ComponentDescription handlerDesc) */
        kActionSetFocus = 6162,               /* [(TargetAtoms theObject)] */
        kActionDontPassKeyEvent = 6163,       /* no params */
        kActionSpriteTrackSetVariable = 7168, /* (QTAtomID variableID, float value) */
        kActionSpriteTrackNewSprite =
            7169,                               /* (QTAtomID spriteID, short imageIndex, MatrixRecord *matrix, short
                                                   visible, short layer, ModifierTrackGraphicsModeRecord
                                                   *graphicsMode, QTAtomID actionHandlingSpriteID) */
        kActionSpriteTrackDisposeSprite = 7170, /* (QTAtomID spriteID) */
        kActionSpriteTrackSetVariableToString =
            7171, /* (QTAtomID variableID, C string value) */
        kActionSpriteTrackConcatVariables =
            7172, /* (QTAtomID firstVariableID, QTAtomID secondVariableID, QTAtomID
                     resultVariableID ) */
        kActionSpriteTrackSetVariableToMovieURL =
            7173, /* (QTAtomID variableID, < optional: [(MovieTargetAtoms)] > ) */
        kActionSpriteTrackSetVariableToMovieBaseURL =
            7174, /* (QTAtomID variableID, < optional: [(MovieTargetAtoms)] > ) */
        kActionApplicationNumberAndString =
            8192,                                 /* (long aNumber, Str255 aString ) */
        kActionQD3DNamedObjectTranslateTo = 9216, /* (Fixed x, Fixed y, Fixed z ) */
        kActionQD3DNamedObjectScaleTo =
            9217, /* (Fixed xScale, Fixed yScale, Fixed zScale ) */
        kActionQD3DNamedObjectRotateTo =
            9218,                         /* (Fixed xDegrees, Fixed yDegrees, Fixed zDegrees ) */
        kActionFlashTrackSetPan = 10240,  /* (short xPercent, short yPercent ) */
        kActionFlashTrackSetZoom = 10241, /* (short zoomFactor ) */
        kActionFlashTrackSetZoomRect =
            10242,                                /* (long left, long top, long right, long bottom ) */
        kActionFlashTrackGotoFrameNumber = 10243, /* (long frameNumber ) */
        kActionFlashTrackGotoFrameLabel = 10244,  /* (C string frameLabel ) */
        kActionFlashTrackSetFlashVariable =
            10245, /* (C string path, C string name, C string value, Boolean
                      updateFocus) */
        kActionFlashTrackDoButtonActions =
            10246, /* (C string path, long buttonID, long transition) */
        kActionMovieTrackAddChildMovie =
            11264,                               /* (QTAtomID childMovieID, C string childMovieURL) */
        kActionMovieTrackLoadChildMovie = 11265, /* (QTAtomID childMovieID) */
        kActionMovieTrackLoadChildMovieWithQTListParams =
            11266, /* (QTAtomID childMovieID, C string qtlistXML) */
        kActionTextTrackPasteText =
            12288, /* (C string theText, long startSelection, long endSelection ) */
        kActionTextTrackSetTextBox =
            12291,                            /* (short left, short top, short right, short bottom) */
        kActionTextTrackSetTextStyle = 12292, /* (Handle textStyle) */
        kActionTextTrackSetSelection =
            12293, /* (long startSelection, long endSelection ) */
        kActionTextTrackSetBackgroundColor =
            12294, /* (ModifierTrackGraphicsModeRecord backgroundColor ) */
        kActionTextTrackSetForegroundColor =
            12295,                            /* (ModifierTrackGraphicsModeRecord foregroundColor ) */
        kActionTextTrackSetFace = 12296,      /* (long fontFace ) */
        kActionTextTrackSetFont = 12297,      /* (long fontID ) */
        kActionTextTrackSetSize = 12298,      /* (long fontSize ) */
        kActionTextTrackSetAlignment = 12299, /* (short alignment ) */
        kActionTextTrackSetHilite =
            12300, /* (long startHighlight, long endHighlight,
                      ModifierTrackGraphicsModeRecord highlightColor ) */
        kActionTextTrackSetDropShadow =
            12301,                               /* (Point dropShadow, short transparency ) */
        kActionTextTrackSetDisplayFlags = 12302, /* (long flags ) */
        kActionTextTrackSetScroll = 12303,       /* (long delay ) */
        kActionTextTrackRelativeScroll = 12304,  /* (short deltaX, short deltaY ) */
        kActionTextTrackFindText =
            12305,                                /* (long flags, Str255 theText, ModifierTrackGraphicsModeRecord
                                                     highlightColor ) */
        kActionTextTrackSetHyperTextFace = 12306, /* (short index, long fontFace ) */
        kActionTextTrackSetHyperTextColor =
            12307,                           /* (short index, ModifierTrackGraphicsModeRecord highlightColor )
                                              */
        kActionTextTrackKeyEntry = 12308,    /* (short character ) */
        kActionTextTrackMouseDown = 12309,   /* no params */
        kActionTextTrackSetEditable = 12310, /* (short editState) */
        kActionListAddElement =
            13312, /* (C string parentPath, long atIndex, C string newElementName) */
        kActionListRemoveElements =
            13313, /* (C string parentPath, long startIndex, long endIndex) */
        kActionListSetElementValue =
            13314, /* (C string elementPath, C string valueString) */
        kActionListPasteFromXML =
            13315, /* (C string xml, C string targetParentPath, long startIndex) */
        kActionListSetMatchingFromXML =
            13316, /* (C string xml, C string targetParentPath) */
        kActionListSetFromURL =
            13317,                        /* (C string url, C string targetParentPath ) */
        kActionListExchangeLists = 13318, /* (C string url, C string parentPath) */
        kActionListServerQuery = 13319    /* (C string url, C string keyValuePairs, long
                                             flags, C string parentPath) */
    };

    enum
    {
        kOperandExpression = 1,
        kOperandConstant = 2,
        kOperandSubscribedToChannel = 3, /* C string channelsURL */
        kOperandUniqueCustomActionHandlerID = 4,
        kOperandCustomActionHandlerIDIsOpen = 5, /* long ID */
        kOperandConnectionSpeed = 6,
        kOperandGMTDay = 7,
        kOperandGMTMonth = 8,
        kOperandGMTYear = 9,
        kOperandGMTHours = 10,
        kOperandGMTMinutes = 11,
        kOperandGMTSeconds = 12,
        kOperandLocalDay = 13,
        kOperandLocalMonth = 14,
        kOperandLocalYear = 15,
        kOperandLocalHours = 16,
        kOperandLocalMinutes = 17,
        kOperandLocalSeconds = 18,
        kOperandRegisteredForQuickTimePro = 19,
        kOperandPlatformRunningOn = 20,
        kOperandQuickTimeVersion = 21,
        kOperandComponentVersion =
            22, /* C string type, C string subType, C string manufacturer */
        kOperandOriginalHandlerRefcon = 23,
        kOperandTicks = 24,
        kOperandMaxLoadedTimeInMovie = 25,
        kOperandEventParameter = 26, /* short index */
        kOperandFreeMemory = 27,
        kOperandNetworkStatus = 28,
        kOperandQuickTimeVersionRegistered = 29, /* long version */
        kOperandSystemVersion = 30,
        kOperandMovieVolume = 1024,
        kOperandMovieRate = 1025,
        kOperandMovieIsLooping = 1026,
        kOperandMovieLoopIsPalindrome = 1027,
        kOperandMovieTime = 1028,
        kOperandMovieDuration = 1029,
        kOperandMovieTimeScale = 1030,
        kOperandMovieWidth = 1031,
        kOperandMovieHeight = 1032,
        kOperandMovieLoadState = 1033,
        kOperandMovieTrackCount = 1034,
        kOperandMovieIsActive = 1035,
        kOperandMovieName = 1036,
        kOperandMovieID = 1037,
        kOperandTrackVolume = 2048,
        kOperandTrackBalance = 2049,
        kOperandTrackEnabled = 2050,
        kOperandTrackLayer = 2051,
        kOperandTrackWidth = 2052,
        kOperandTrackHeight = 2053,
        kOperandTrackDuration = 2054,
        kOperandTrackName = 2055,
        kOperandTrackID = 2056,
        kOperandTrackIdleFrequency = 2057,
        kOperandTrackBass = 2058,
        kOperandTrackTreble = 2059,
        kOperandSpriteBoundsLeft = 3072,
        kOperandSpriteBoundsTop = 3073,
        kOperandSpriteBoundsRight = 3074,
        kOperandSpriteBoundsBottom = 3075,
        kOperandSpriteImageIndex = 3076,
        kOperandSpriteVisible = 3077,
        kOperandSpriteLayer = 3078,
        kOperandSpriteTrackVariable = 3079, /* [QTAtomID variableID] */
        kOperandSpriteTrackNumSprites = 3080,
        kOperandSpriteTrackNumImages = 3081,
        kOperandSpriteID = 3082,
        kOperandSpriteIndex = 3083,
        kOperandSpriteFirstCornerX = 3084,
        kOperandSpriteFirstCornerY = 3085,
        kOperandSpriteSecondCornerX = 3086,
        kOperandSpriteSecondCornerY = 3087,
        kOperandSpriteThirdCornerX = 3088,
        kOperandSpriteThirdCornerY = 3089,
        kOperandSpriteFourthCornerX = 3090,
        kOperandSpriteFourthCornerY = 3091,
        kOperandSpriteImageRegistrationPointX = 3092,
        kOperandSpriteImageRegistrationPointY = 3093,
        kOperandSpriteTrackSpriteIDAtPoint = 3094, /* short x, short y */
        kOperandSpriteName = 3095,
        kOperandQTVRPanAngle = 4096,
        kOperandQTVRTiltAngle = 4097,
        kOperandQTVRFieldOfView = 4098,
        kOperandQTVRNodeID = 4099,
        kOperandQTVRHotSpotsVisible = 4100,
        kOperandQTVRViewCenterH = 4101,
        kOperandQTVRViewCenterV = 4102,
        kOperandMouseLocalHLoc = 5120, /* [TargetAtoms aTrack] */
        kOperandMouseLocalVLoc = 5121, /* [TargetAtoms aTrack] */
        kOperandKeyIsDown = 5122,      /* [short modKeys, char asciiValue] */
        kOperandRandom = 5123,         /* [short min, short max] */
        kOperandCanHaveFocus = 5124,   /* [(TargetAtoms theObject)] */
        kOperandHasFocus = 5125,       /* [(TargetAtoms theObject)] */
        kOperandTextTrackEditable = 6144,
        kOperandTextTrackCopyText = 6145, /* long startSelection, long endSelection */
        kOperandTextTrackStartSelection = 6146,
        kOperandTextTrackEndSelection = 6147,
        kOperandTextTrackTextBoxLeft = 6148,
        kOperandTextTrackTextBoxTop = 6149,
        kOperandTextTrackTextBoxRight = 6150,
        kOperandTextTrackTextBoxBottom = 6151,
        kOperandTextTrackTextLength = 6152,
        kOperandListCountElements = 7168, /* (C string parentPath) */
        kOperandListGetElementPathByIndex =
            7169,                           /* (C string parentPath, long index) */
        kOperandListGetElementValue = 7170, /* (C string elementPath) */
        kOperandListCopyToXML =
            7171,                          /* (C string parentPath, long startIndex, long endIndex) */
        kOperandSin = 8192,                /* float x    */
        kOperandCos = 8193,                /* float x    */
        kOperandTan = 8194,                /* float x    */
        kOperandATan = 8195,               /* float x    */
        kOperandATan2 = 8196,              /* float y, float x   */
        kOperandDegreesToRadians = 8197,   /* float x */
        kOperandRadiansToDegrees = 8198,   /* float x */
        kOperandSquareRoot = 8199,         /* float x */
        kOperandExponent = 8200,           /* float x */
        kOperandLog = 8201,                /* float x */
        kOperandFlashTrackVariable = 9216, /* [CString path, CString name] */
        kOperandStringLength = 10240,      /* (C string text) */
        kOperandStringCompare = 10241,     /* (C string aText, C string bText, Boolean
                                              caseSensitive, Boolan diacSensitive) */
        kOperandStringSubString =
            10242,                   /* (C string text, long offset, long length) */
        kOperandStringConcat = 10243 /* (C string aText, C string bText) */
    };

    enum
    {
        kFirstMovieAction = kActionMovieSetVolume,
        kLastMovieAction = kActionMovieRestartAtTime,
        kFirstTrackAction = kActionTrackSetVolume,
        kLastTrackAction = kActionTrackSetBassTreble,
        kFirstSpriteAction = kActionSpriteSetMatrix,
        kLastSpriteAction = kActionSpriteStretch,
        kFirstQTVRAction = kActionQTVRSetPanAngle,
        kLastQTVRAction = kActionQTVRTranslateObject,
        kFirstMusicAction = kActionMusicPlayNote,
        kLastMusicAction = kActionMusicSetController,
        kFirstSystemAction = kActionCase,
        kLastSystemAction = kActionDontPassKeyEvent,
        kFirstSpriteTrackAction = kActionSpriteTrackSetVariable,
        kLastSpriteTrackAction = kActionSpriteTrackSetVariableToMovieBaseURL,
        kFirstApplicationAction = kActionApplicationNumberAndString,
        kLastApplicationAction = kActionApplicationNumberAndString,
        kFirstQD3DNamedObjectAction = kActionQD3DNamedObjectTranslateTo,
        kLastQD3DNamedObjectAction = kActionQD3DNamedObjectRotateTo,
        kFirstFlashTrackAction = kActionFlashTrackSetPan,
        kLastFlashTrackAction = kActionFlashTrackDoButtonActions,
        kFirstMovieTrackAction = kActionMovieTrackAddChildMovie,
        kLastMovieTrackAction = kActionMovieTrackLoadChildMovieWithQTListParams,
        kFirstTextTrackAction = kActionTextTrackPasteText,
        kLastTextTrackAction = kActionTextTrackSetEditable,
        kFirstMultiTargetAction = kActionListAddElement,
        kLastMultiTargetAction = kActionListServerQuery,
        kFirstAction = kFirstMovieAction,
        kLastAction = kLastMultiTargetAction
    };

    /* target atom types*/
    enum
    {
        kTargetMovie = FOUR_CHAR_CODE('moov'),       /* no data */
        kTargetMovieName = FOUR_CHAR_CODE('mona'),   /* (PString movieName) */
        kTargetMovieID = FOUR_CHAR_CODE('moid'),     /* (long movieID) */
        kTargetRootMovie = FOUR_CHAR_CODE('moro'),   /* no data */
        kTargetParentMovie = FOUR_CHAR_CODE('mopa'), /* no data */
        kTargetChildMovieTrackName =
            FOUR_CHAR_CODE('motn'), /* (PString childMovieTrackName) */
        kTargetChildMovieTrackID =
            FOUR_CHAR_CODE('moti'), /* (long childMovieTrackID) */
        kTargetChildMovieTrackIndex =
            FOUR_CHAR_CODE('motx'), /* (long childMovieTrackIndex) */
        kTargetChildMovieMovieName =
            FOUR_CHAR_CODE('momn'),                        /* (PString childMovieName) */
        kTargetChildMovieMovieID = FOUR_CHAR_CODE('momi'), /* (long childMovieID) */
        kTargetTrackName = FOUR_CHAR_CODE('trna'),         /* (PString trackName) */
        kTargetTrackID = FOUR_CHAR_CODE('trid'),           /* (long trackID) */
        kTargetTrackType = FOUR_CHAR_CODE('trty'),         /* (OSType trackType) */
        kTargetTrackIndex = FOUR_CHAR_CODE('trin'),        /* (long trackIndex) */
        kTargetSpriteName = FOUR_CHAR_CODE('spna'),        /* (PString spriteName) */
        kTargetSpriteID = FOUR_CHAR_CODE('spid'),          /* (QTAtomID spriteID) */
        kTargetSpriteIndex = FOUR_CHAR_CODE('spin'),       /* (short spriteIndex) */
        kTargetQD3DNamedObjectName =
            FOUR_CHAR_CODE('nana'),                          /* (CString objectName) */
        kTargetCurrentQTEventParams = FOUR_CHAR_CODE('evpa') /* no data */
    };

    /* action container atom types*/
    enum
    {
        kQTEventType = FOUR_CHAR_CODE('evnt'),
        kAction = FOUR_CHAR_CODE('actn'),
        kWhichAction = FOUR_CHAR_CODE('whic'),
        kActionParameter = FOUR_CHAR_CODE('parm'),
        kActionTarget = FOUR_CHAR_CODE('targ'),
        kActionFlags = FOUR_CHAR_CODE('flag'),
        kActionParameterMinValue = FOUR_CHAR_CODE('minv'),
        kActionParameterMaxValue = FOUR_CHAR_CODE('maxv'),
        kActionListAtomType = FOUR_CHAR_CODE('list'),
        kExpressionContainerAtomType = FOUR_CHAR_CODE('expr'),
        kConditionalAtomType = FOUR_CHAR_CODE('test'),
        kOperatorAtomType = FOUR_CHAR_CODE('oper'),
        kOperandAtomType = FOUR_CHAR_CODE('oprn'),
        kCommentAtomType = FOUR_CHAR_CODE('why '),
        kCustomActionHandler = FOUR_CHAR_CODE('cust'),
        kCustomHandlerID = FOUR_CHAR_CODE('id  '),
        kCustomHandlerDesc = FOUR_CHAR_CODE('desc'),
        kQTEventRecordAtomType = FOUR_CHAR_CODE('erec')
    };

    /* QTEvent types */
    enum
    {
        kQTEventMouseClick = FOUR_CHAR_CODE('clik'),
        kQTEventMouseClickEnd = FOUR_CHAR_CODE('cend'),
        kQTEventMouseClickEndTriggerButton = FOUR_CHAR_CODE('trig'),
        kQTEventMouseEnter = FOUR_CHAR_CODE('entr'),
        kQTEventMouseExit = FOUR_CHAR_CODE('exit'),
        kQTEventMouseMoved = FOUR_CHAR_CODE('move'),
        kQTEventFrameLoaded = FOUR_CHAR_CODE('fram'),
        kQTEventIdle = FOUR_CHAR_CODE('idle'),
        kQTEventKey =
            FOUR_CHAR_CODE('key '), /* qtevent.param1 = key, qtevent.param2 =
                                       modifiers, qtEvent.param3 = scanCode */
        kQTEventMovieLoaded = FOUR_CHAR_CODE('load'),
        kQTEventRequestToModifyMovie = FOUR_CHAR_CODE('reqm'),
        kQTEventListReceived = FOUR_CHAR_CODE('list')
    };

    /* flags for the kActionFlags atom */
    enum
    {
        kActionFlagActionIsDelta = 1L << 1,
        kActionFlagParameterWrapsAround = 1L << 2,
        kActionFlagActionIsToggle = 1L << 3
    };

    /* flags for stringTypeFlags field of the QTStatusStringRecord */
    enum
    {
        kStatusStringIsURLLink = 1L << 1,
        kStatusStringIsStreamingStatus = 1L << 2,
        kStatusHasCodeNumber =
            1L << 3, /* high 16 bits of stringTypeFlags is error code number*/
        kStatusIsError = 1L << 4
    };

    /* flags for scriptTypeFlags field of the QTDoScriptRecord*/
    enum
    {
        kScriptIsUnknownType = 1L << 0,
        kScriptIsJavaScript = 1L << 1,
        kScriptIsLingoEvent = 1L << 2,
        kScriptIsVBEvent = 1L << 3,
        kScriptIsProjectorCommand = 1L << 4,
        kScriptIsAppleScript = 1L << 5
    };

    /* flags for CheckQuickTimeRegistration routine*/
    enum
    {
        kQTRegistrationDialogTimeOutFlag = 1 << 0,
        kQTRegistrationDialogShowDialog = 1 << 1,
        kQTRegistrationDialogForceDialog = 1 << 2
    };

    /* constants for kOperatorAtomType IDs (operator types)*/
    enum
    {
        kOperatorAdd = FOUR_CHAR_CODE('add '),
        kOperatorSubtract = FOUR_CHAR_CODE('sub '),
        kOperatorMultiply = FOUR_CHAR_CODE('mult'),
        kOperatorDivide = FOUR_CHAR_CODE('div '),
        kOperatorOr = FOUR_CHAR_CODE('or  '),
        kOperatorAnd = FOUR_CHAR_CODE('and '),
        kOperatorNot = FOUR_CHAR_CODE('not '),
        kOperatorLessThan = FOUR_CHAR_CODE('<   '),
        kOperatorLessThanEqualTo = FOUR_CHAR_CODE('<=  '),
        kOperatorEqualTo = FOUR_CHAR_CODE('=   '),
        kOperatorNotEqualTo = FOUR_CHAR_CODE('!=  '),
        kOperatorGreaterThan = FOUR_CHAR_CODE('>   '),
        kOperatorGreaterThanEqualTo = FOUR_CHAR_CODE('>=  '),
        kOperatorModulo = FOUR_CHAR_CODE('mod '),
        kOperatorIntegerDivide = FOUR_CHAR_CODE('idiv'),
        kOperatorAbsoluteValue = FOUR_CHAR_CODE('abs '),
        kOperatorNegate = FOUR_CHAR_CODE('neg ')
    };

    /* constants for kOperandPlatformRunningOn*/
    enum
    {
        kPlatformMacintosh = 1,
        kPlatformWindows = 2
    };

    /* flags for kOperandSystemVersion*/
    enum
    {
        kSystemIsWindows9x = 0x00010000,
        kSystemIsWindowsNT = 0x00020000
    };

    /* constants for MediaPropertiesAtom*/
    enum
    {
        kMediaPropertyNonLinearAtomType = FOUR_CHAR_CODE('nonl'),
        kMediaPropertyHasActions = 105
    };

    typedef CALLBACK_API(OSErr, MovieRgnCoverProcPtr)(Movie theMovie,
                                                      RgnHandle changedRgn,
                                                      long refcon);
    typedef CALLBACK_API(OSErr, MovieProgressProcPtr)(Movie theMovie, short message,
                                                      short whatOperation,
                                                      Fixed percentDone,
                                                      long refcon);
    typedef CALLBACK_API(OSErr, MovieDrawingCompleteProcPtr)(Movie theMovie,
                                                             long refCon);
    typedef CALLBACK_API(OSErr, TrackTransferProcPtr)(Track t, long refCon);
    typedef CALLBACK_API(OSErr, GetMovieProcPtr)(long offset, long size,
                                                 void *dataPtr, void *refCon);
    typedef CALLBACK_API(Boolean, MoviePreviewCallOutProcPtr)(long refcon);
    typedef CALLBACK_API(OSErr, TextMediaProcPtr)(Handle theText, Movie theMovie,
                                                  short *displayFlag, long refcon);
    typedef CALLBACK_API(OSErr, ActionsProcPtr)(void *refcon, Track targetTrack,
                                                long targetRefCon,
                                                QTEventRecordPtr theEvent);
    typedef CALLBACK_API(OSErr, DoMCActionProcPtr)(void *refcon, short action,
                                                   void *params, Boolean *handled);
    typedef CALLBACK_API(OSErr, MovieExecuteWiredActionsProcPtr)(
        Movie theMovie, void *refcon, long flags, QTAtomContainer wiredActions);
    typedef CALLBACK_API(void, MoviePrePrerollCompleteProcPtr)(Movie theMovie,
                                                               OSErr prerollErr,
                                                               void *refcon);
    typedef CALLBACK_API(void, MoviesErrorProcPtr)(OSErr theErr, long refcon);
    typedef STACK_UPP_TYPE(MovieRgnCoverProcPtr) MovieRgnCoverUPP;
    typedef STACK_UPP_TYPE(MovieProgressProcPtr) MovieProgressUPP;
    typedef STACK_UPP_TYPE(MovieDrawingCompleteProcPtr) MovieDrawingCompleteUPP;
    typedef STACK_UPP_TYPE(TrackTransferProcPtr) TrackTransferUPP;
    typedef STACK_UPP_TYPE(GetMovieProcPtr) GetMovieUPP;
    typedef STACK_UPP_TYPE(MoviePreviewCallOutProcPtr) MoviePreviewCallOutUPP;
    typedef STACK_UPP_TYPE(TextMediaProcPtr) TextMediaUPP;
    typedef STACK_UPP_TYPE(ActionsProcPtr) ActionsUPP;
    typedef STACK_UPP_TYPE(DoMCActionProcPtr) DoMCActionUPP;
    typedef STACK_UPP_TYPE(MovieExecuteWiredActionsProcPtr)
        MovieExecuteWiredActionsUPP;
    typedef STACK_UPP_TYPE(MoviePrePrerollCompleteProcPtr)
        MoviePrePrerollCompleteUPP;
    typedef STACK_UPP_TYPE(MoviesErrorProcPtr) MoviesErrorUPP;
    typedef ComponentInstance MediaHandler;
    typedef ComponentInstance DataHandler;
    typedef Component MediaHandlerComponent;
    typedef Component DataHandlerComponent;
    typedef ComponentResult HandlerError;
    /* TimeBase and TimeRecord moved to MacTypes.h */
    typedef UInt32 TimeBaseFlags;
    enum
    {
        loopTimeBase = 1,
        palindromeLoopTimeBase = 2,
        maintainTimeBaseZero = 4
    };

    struct CallBackRecord
    {
        long data[1];
    };
    typedef struct CallBackRecord CallBackRecord;
    typedef CallBackRecord *QTCallBack;
    /* CallBack equates */
    typedef UInt16 QTCallBackFlags;
    enum
    {
        triggerTimeFwd = 0x0001, /* when curTime exceeds triggerTime going forward */
        triggerTimeBwd =
            0x0002, /* when curTime exceeds triggerTime going backwards */
        triggerTimeEither =
            0x0003,                /* when curTime exceeds triggerTime going either direction */
        triggerRateLT = 0x0004,    /* when rate changes to less than trigger value */
        triggerRateGT = 0x0008,    /* when rate changes to greater than trigger value */
        triggerRateEqual = 0x0010, /* when rate changes to equal trigger value */
        triggerRateLTE = triggerRateLT | triggerRateEqual,
        triggerRateGTE = triggerRateGT | triggerRateEqual,
        triggerRateNotEqual = triggerRateGT | triggerRateEqual | triggerRateLT,
        triggerRateChange = 0,
        triggerAtStart = 0x0001,
        triggerAtStop = 0x0002
    };

    typedef UInt32 TimeBaseStatus;
    enum
    {
        timeBaseBeforeStartTime = 1,
        timeBaseAfterStopTime = 2
    };

    typedef UInt16 QTCallBackType;
    enum
    {
        callBackAtTime = 1,
        callBackAtRate = 2,
        callBackAtTimeJump = 3,
        callBackAtExtremes = 4,
        callBackAtTimeBaseDisposed = 5,
        callBackAtInterrupt = 0x8000,
        callBackAtDeferredTask = 0x4000
    };

    typedef CALLBACK_API(void, QTCallBackProcPtr)(QTCallBack cb, long refCon);
    typedef STACK_UPP_TYPE(QTCallBackProcPtr) QTCallBackUPP;
    enum
    {
        qtcbNeedsRateChanges = 1, /* wants to know about rate changes */
        qtcbNeedsTimeChanges = 2, /* wants to know about time changes */
        qtcbNeedsStartStopChanges =
            4 /* wants to know when TimeBase start/stop is changed*/
    };

    struct QTCallBackHeader
    {
        long callBackFlags;
        long reserved1;
        SInt8 qtPrivate[40];
    };
    typedef struct QTCallBackHeader QTCallBackHeader;
    typedef CALLBACK_API(void, QTSyncTaskProcPtr)(void *task);
    typedef STACK_UPP_TYPE(QTSyncTaskProcPtr) QTSyncTaskUPP;
    struct QTSyncTaskRecord
    {
        void *qLink;
        QTSyncTaskUPP proc;
    };
    typedef struct QTSyncTaskRecord QTSyncTaskRecord;
    typedef QTSyncTaskRecord *QTSyncTaskPtr;
    enum
    {
        keepInRam = 1 << 0,    /* load and make non-purgable*/
        unkeepInRam = 1 << 1,  /* mark as purgable*/
        flushFromRam = 1 << 2, /* empty those handles*/
        loadForwardTrackEdits =
            1 << 3, /*    load track edits into ram for playing forward*/
        loadBackwardTrackEdits =
            1 << 4 /*    load track edits into ram for playing in reverse*/
    };

    enum
    {
        newMovieActive = 1 << 0,
        newMovieDontResolveDataRefs = 1 << 1,
        newMovieDontAskUnresolvedDataRefs = 1 << 2,
        newMovieDontAutoAlternates = 1 << 3,
        newMovieDontUpdateForeBackPointers = 1 << 4,
        newMovieDontAutoUpdateClock = 1 << 5,
        newMovieAsyncOK = 1 << 8,
        newMovieIdleImportOK = 1 << 10
    };

    /* track usage bits */
    enum
    {
        trackUsageInMovie = 1 << 1,
        trackUsageInPreview = 1 << 2,
        trackUsageInPoster = 1 << 3
    };

    /* Add/GetMediaSample flags */
    enum
    {
        mediaSampleNotSync =
            1 << 0,                    /* sample is not a sync sample (eg. is frame differenced */
        mediaSampleShadowSync = 1 << 1 /* sample is a shadow sync */
    };

    enum
    {
        pasteInParallel = 1 << 0,
        showUserSettingsDialog = 1 << 1,
        movieToFileOnlyExport = 1 << 2,
        movieFileSpecValid = 1 << 3
    };

    enum
    {
        nextTimeMediaSample = 1 << 0,
        nextTimeMediaEdit = 1 << 1,
        nextTimeTrackEdit = 1 << 2,
        nextTimeSyncSample = 1 << 3,
        nextTimeStep = 1 << 4,
        nextTimeEdgeOK = 1 << 14,
        nextTimeIgnoreActiveSegment = 1 << 15
    };

    typedef unsigned short nextTimeFlagsEnum;
    enum
    {
        createMovieFileDeleteCurFile = 1L << 31,
        createMovieFileDontCreateMovie = 1L << 30,
        createMovieFileDontOpenFile = 1L << 29,
        createMovieFileDontCreateResFile = 1L << 28
    };

    typedef unsigned long createMovieFileFlagsEnum;
    enum
    {
        flattenAddMovieToDataFork = 1L << 0,
        flattenActiveTracksOnly = 1L << 2,
        flattenDontInterleaveFlatten = 1L << 3,
        flattenFSSpecPtrIsDataRefRecordPtr = 1L << 4,
        flattenCompressMovieResource = 1L << 5,
        flattenForceMovieResourceBeforeMovieData = 1L << 6
    };

    typedef unsigned long movieFlattenFlagsEnum;
    enum
    {
        movieInDataForkResID = -1 /* magic res ID */
    };

    enum
    {
        mcTopLeftMovie = 1 << 0,    /* usually centered */
        mcScaleMovieToFit = 1 << 1, /* usually only scales down */
        mcWithBadge = 1 << 2,       /* give me a badge */
        mcNotVisible = 1 << 3,      /* don't show controller */
        mcWithFrame = 1 << 4        /* gimme a frame */
    };

    enum
    {
        movieScrapDontZeroScrap = 1 << 0,
        movieScrapOnlyPutMovie = 1 << 1
    };

    enum
    {
        dataRefSelfReference = 1 << 0,
        dataRefWasNotResolved = 1 << 1
    };

    typedef unsigned long dataRefAttributesFlags;
    enum
    {
        kMovieAnchorDataRefIsDefault =
            1 << 0 /* data ref returned is movie default data ref */
    };

    enum
    {
        hintsScrubMode =
            1 << 0, /* mask == && (if flags == scrub on, flags != scrub off) */
        hintsLoop = 1 << 1,
        hintsDontPurge = 1 << 2,
        hintsUseScreenBuffer = 1 << 5,
        hintsAllowInterlace = 1 << 6,
        hintsUseSoundInterp = 1 << 7,
        hintsHighQuality = 1 << 8, /* slooooow */
        hintsPalindrome = 1 << 9,
        hintsInactive = 1 << 11,
        hintsOffscreen = 1 << 12,
        hintsDontDraw = 1 << 13,
        hintsAllowBlacklining = 1 << 14,
        hintsDontUseVideoOverlaySurface = 1 << 16,
        hintsIgnoreBandwidthRestrictions = 1 << 17,
        hintsPlayingEveryFrame = 1 << 18,
        hintsAllowDynamicResize = 1 << 19,
        hintsSingleField = 1 << 20,
        hintsNoRenderingTimeOut = 1 << 21
    };

    typedef unsigned long playHintsEnum;
    enum
    {
        mediaHandlerFlagBaseClient = 1
    };

    typedef unsigned long mediaHandlerFlagsEnum;
    enum
    {
        movieTrackMediaType = 1 << 0,
        movieTrackCharacteristic = 1 << 1,
        movieTrackEnabledOnly = 1 << 2
    };

    struct SampleReferenceRecord
    {
        long dataOffset;
        long dataSize;
        TimeValue durationPerSample;
        long numberOfSamples;
        short sampleFlags;
    };
    typedef struct SampleReferenceRecord SampleReferenceRecord;
    typedef SampleReferenceRecord *SampleReferencePtr;
    struct SampleReference64Record
    {
        wide dataOffset;
        unsigned long dataSize;
        TimeValue durationPerSample;
        unsigned long numberOfSamples;
        short sampleFlags;
    };
    typedef struct SampleReference64Record SampleReference64Record;
    typedef SampleReference64Record *SampleReference64Ptr;

    /*************************
     * Initialization Routines
     **************************/
    /**
     *  CheckQuickTimeRegistration()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.1 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    CheckQuickTimeRegistration(void *registrationKey, long flags);

    /**
     *  EnterMovies()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    EnterMovies(void);

    /**
     *  ExitMovies()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    ExitMovies(void);

    /*************************
     * Error Routines
     **************************/

    /**
     *  GetMoviesError()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    GetMoviesError(void);

    /**
     *  ClearMoviesStickyError()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    ClearMoviesStickyError(void);

    /**
     *  GetMoviesStickyError()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    GetMoviesStickyError(void);

    /**
     *  SetMoviesErrorProc()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SetMoviesErrorProc(MoviesErrorUPP errProc, long refcon);

    /*************************
     * Idle Routines
     **************************/
    /**
     *  MoviesTask()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    MoviesTask(Movie theMovie, long maxMilliSecToUse);

    /**
     *  PrerollMovie()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    PrerollMovie(Movie theMovie, TimeValue time, Fixed Rate);

    /**
     *  PrePrerollMovie()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    OSErr
    PrePrerollMovie(Movie m, TimeValue time, Fixed rate,
                    MoviePrePrerollCompleteUPP proc, void *refcon);

    /**
     *  AbortPrePrerollMovie()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    void
    AbortPrePrerollMovie(Movie m, OSErr err);

    /**
     *  LoadMovieIntoRam()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    LoadMovieIntoRam(Movie theMovie, TimeValue time, TimeValue duration, long flags);

    /**
     *  LoadTrackIntoRam()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    LoadTrackIntoRam(Track theTrack, TimeValue time, TimeValue duration, long flags);

    /**
     *  LoadMediaIntoRam()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    LoadMediaIntoRam(Media theMedia, TimeValue time, TimeValue duration, long flags);

    /**
     *  SetMovieActive()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SetMovieActive(Movie theMovie, Boolean active);

    /**
     *  GetMovieActive()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    Boolean
    GetMovieActive(Movie theMovie);

    /*************************
     * calls for playing movies, previews, posters
     **************************/
    /**
     *  StartMovie()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    StartMovie(Movie theMovie);

    /**
     *  StopMovie()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    StopMovie(Movie theMovie);

    /**
     *  GoToBeginningOfMovie()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    GoToBeginningOfMovie(Movie theMovie);

    /**
     *  GoToEndOfMovie()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    GoToEndOfMovie(Movie theMovie);

    /**
     *  IsMovieDone()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    Boolean
    IsMovieDone(Movie theMovie);

    /**
     *  GetMoviePreviewMode()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    Boolean
    GetMoviePreviewMode(Movie theMovie);

    /**
     *  SetMoviePreviewMode()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SetMoviePreviewMode(Movie theMovie, Boolean usePreview);

    /**
     *  ShowMoviePoster()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    ShowMoviePoster(Movie theMovie);

    /**
     *  PlayMoviePreview()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    PlayMoviePreview(Movie theMovie, MoviePreviewCallOutUPP callOutProc,
                     long refcon);

    /*************************
     * calls for controlling movies & tracks which are playing
     **************************/
    /**
     *  GetMovieTimeBase()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    TimeBase
    GetMovieTimeBase(Movie theMovie);

    /**
     *  SetMovieMasterTimeBase()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SetMovieMasterTimeBase(Movie theMovie, TimeBase tb, const TimeRecord *slaveZero);

    /**
     *  SetMovieMasterClock()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SetMovieMasterClock(Movie theMovie, Component clockMeister,
                        const TimeRecord *slaveZero);

    /**
     *  GetMovieGWorld()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    GetMovieGWorld(Movie theMovie, CGrafPtr *port, GDHandle *gdh);

    /**
     *  SetMovieGWorld()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SetMovieGWorld(Movie theMovie, CGrafPtr port, GDHandle gdh);

    enum
    {
        movieDrawingCallWhenChanged = 0,
        movieDrawingCallAlways = 1
    };

    /**
     *  SetMovieDrawingCompleteProc()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SetMovieDrawingCompleteProc(Movie theMovie, long flags,
                                MovieDrawingCompleteUPP proc, long refCon);

    /**
     *  GetMovieNaturalBoundsRect()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    GetMovieNaturalBoundsRect(Movie theMovie, Rect *naturalBounds);

    /**
     *  GetNextTrackForCompositing()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    Track
    GetNextTrackForCompositing(Movie theMovie, Track theTrack);

    /**
     *  GetPrevTrackForCompositing()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    Track
    GetPrevTrackForCompositing(Movie theMovie, Track theTrack);

    /**
     *  SetTrackGWorld()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SetTrackGWorld(Track theTrack, CGrafPtr port, GDHandle gdh,
                   TrackTransferUPP proc, long refCon);

    /**
     *  GetMoviePict()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    PicHandle
    GetMoviePict(Movie theMovie, TimeValue time);

    /**
     *  GetTrackPict()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    PicHandle
    GetTrackPict(Track theTrack, TimeValue time);

    /**
     *  GetMoviePosterPict()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    PicHandle
    GetMoviePosterPict(Movie theMovie);

    /* called between Begin & EndUpdate */
    /**
     *  UpdateMovie()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    UpdateMovie(Movie theMovie);

    /**
     *  InvalidateMovieRegion()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    InvalidateMovieRegion(Movie theMovie, RgnHandle invalidRgn);

    /**** spatial movie routines ****/
    /**
     *  GetMovieBox()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    GetMovieBox(Movie theMovie, Rect *boxRect);

    /**
     *  SetMovieBox()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SetMovieBox(Movie theMovie, const Rect *boxRect);

    /** movie display clip */
    /**
     *  GetMovieDisplayClipRgn()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    RgnHandle
    GetMovieDisplayClipRgn(Movie theMovie);

    /**
     *  SetMovieDisplayClipRgn()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SetMovieDisplayClipRgn(Movie theMovie, RgnHandle theClip);

    /** movie src clip */
    /**
     *  GetMovieClipRgn()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    RgnHandle
    GetMovieClipRgn(Movie theMovie);

    /**
     *  SetMovieClipRgn()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SetMovieClipRgn(Movie theMovie, RgnHandle theClip);

    /** track src clip */
    /**
     *  GetTrackClipRgn()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    RgnHandle
    GetTrackClipRgn(Track theTrack);

    /**
     *  SetTrackClipRgn()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SetTrackClipRgn(Track theTrack, RgnHandle theClip);

    /** bounds in display space (not clipped by display clip) */
    /**
     *  GetMovieDisplayBoundsRgn()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    RgnHandle
    GetMovieDisplayBoundsRgn(Movie theMovie);

    /**
     *  GetTrackDisplayBoundsRgn()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    RgnHandle
    GetTrackDisplayBoundsRgn(Track theTrack);

    /** bounds in movie space */
    /**
     *  GetMovieBoundsRgn()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    RgnHandle
    GetMovieBoundsRgn(Movie theMovie);

    /**
     *  GetTrackMovieBoundsRgn()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    RgnHandle
    GetTrackMovieBoundsRgn(Track theTrack);

    /** bounds in track space */
    /**
     *  GetTrackBoundsRgn()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    RgnHandle
    GetTrackBoundsRgn(Track theTrack);

    /** mattes - always in track space */
    /**
     *  GetTrackMatte()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    PixMapHandle
    GetTrackMatte(Track theTrack);

    /**
     *  SetTrackMatte()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SetTrackMatte(Track theTrack, PixMapHandle theMatte);

    /**
     *  DisposeMatte()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    DisposeMatte(PixMapHandle theMatte);

    /** video out */
    /**
     *  SetMovieVideoOutput()
     *

     *    \non_carbon_cfm   in QuickTimeLib 5.0 and later
     *    \carbon_lib        in CarbonLib 1.3 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 5.0 and later
     */
    void
    SetMovieVideoOutput(Movie theMovie, ComponentInstance vout);

    /*************************
     * calls for getting/saving movies
     **************************/
    /**
     *  NewMovie()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    Movie
    NewMovie(long flags);

    /**
     *  PutMovieIntoHandle()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    PutMovieIntoHandle(Movie theMovie, Handle publicMovie);

    /**
     *  PutMovieIntoDataFork()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    PutMovieIntoDataFork(Movie theMovie, short fRefNum, long offset, long maxSize);

    /**
     *  PutMovieIntoDataFork64()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    OSErr
    PutMovieIntoDataFork64(Movie theMovie, long fRefNum, const wide *offset,
                           unsigned long maxSize);

    /**
     *  DisposeMovie()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    DisposeMovie(Movie theMovie);

    /*************************
     * Movie State Routines
     **************************/
    /**
     *  GetMovieCreationTime()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    unsigned long
    GetMovieCreationTime(Movie theMovie);

    /**
     *  GetMovieModificationTime()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    unsigned long
    GetMovieModificationTime(Movie theMovie);

    /**
     *  GetMovieTimeScale()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    TimeScale
    GetMovieTimeScale(Movie theMovie);

    /**
     *  SetMovieTimeScale()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SetMovieTimeScale(Movie theMovie, TimeScale timeScale);

    /**
     *  GetMovieDuration()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    TimeValue
    GetMovieDuration(Movie theMovie);

    /**
     *  GetMovieRate()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    Fixed
    GetMovieRate(Movie theMovie);

    /**
     *  SetMovieRate()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SetMovieRate(Movie theMovie, Fixed rate);

    /**
     *  GetMoviePreferredRate()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    Fixed
    GetMoviePreferredRate(Movie theMovie);

    /**
     *  SetMoviePreferredRate()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SetMoviePreferredRate(Movie theMovie, Fixed rate);

    /**
     *  GetMoviePreferredVolume()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    short
    GetMoviePreferredVolume(Movie theMovie);

    /**
     *  SetMoviePreferredVolume()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SetMoviePreferredVolume(Movie theMovie, short volume);

    /**
     *  GetMovieVolume()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    short
    GetMovieVolume(Movie theMovie);

    /**
     *  SetMovieVolume()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SetMovieVolume(Movie theMovie, short volume);

    /**
     *  GetMovieMatrix()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    GetMovieMatrix(Movie theMovie, MatrixRecord *matrix);

    /**
     *  SetMovieMatrix()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SetMovieMatrix(Movie theMovie, const MatrixRecord *matrix);

    /**
     *  GetMoviePreviewTime()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    GetMoviePreviewTime(Movie theMovie, TimeValue *previewTime,
                        TimeValue *previewDuration);

    /**
     *  SetMoviePreviewTime()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SetMoviePreviewTime(Movie theMovie, TimeValue previewTime,
                        TimeValue previewDuration);

    /**
     *  GetMoviePosterTime()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    TimeValue
    GetMoviePosterTime(Movie theMovie);

    /**
     *  SetMoviePosterTime()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SetMoviePosterTime(Movie theMovie, TimeValue posterTime);

    /**
     *  GetMovieSelection()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    GetMovieSelection(Movie theMovie, TimeValue *selectionTime,
                      TimeValue *selectionDuration);

    /**
     *  SetMovieSelection()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SetMovieSelection(Movie theMovie, TimeValue selectionTime,
                      TimeValue selectionDuration);

    /**
     *  SetMovieActiveSegment()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SetMovieActiveSegment(Movie theMovie, TimeValue startTime, TimeValue duration);

    /**
     *  GetMovieActiveSegment()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    GetMovieActiveSegment(Movie theMovie, TimeValue *startTime, TimeValue *duration);

    /**
     *  GetMovieTime()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    TimeValue
    GetMovieTime(Movie theMovie, TimeRecord *currentTime);

    /**
     *  SetMovieTime()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SetMovieTime(Movie theMovie, const TimeRecord *newtime);

    /**
     *  SetMovieTimeValue()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SetMovieTimeValue(Movie theMovie, TimeValue newtime);

    /**
     *  GetMovieUserData()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    UserData
    GetMovieUserData(Movie theMovie);

    /*************************
     * Track/Media finding routines
     **************************/
    /**
     *  GetMovieTrackCount()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    long
    GetMovieTrackCount(Movie theMovie);

    /**
     *  GetMovieTrack()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    Track
    GetMovieTrack(Movie theMovie, long trackID);

    /**
     *  GetMovieIndTrack()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    Track
    GetMovieIndTrack(Movie theMovie, long index);

    /**
     *  GetMovieIndTrackType()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    Track
    GetMovieIndTrackType(Movie theMovie, long index, OSType trackType, long flags);

    /**
     *  GetTrackID()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    long
    GetTrackID(Track theTrack);

    /**
     *  GetTrackMovie()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    Movie
    GetTrackMovie(Track theTrack);

    /*************************
     * Track creation routines
     **************************/
    /**
     *  NewMovieTrack()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    Track
    NewMovieTrack(Movie theMovie, Fixed width, Fixed height, short trackVolume);

    /**
     *  DisposeMovieTrack()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    DisposeMovieTrack(Track theTrack);

    /*************************
     * Track State routines
     **************************/
    /**
     *  GetTrackCreationTime()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    unsigned long
    GetTrackCreationTime(Track theTrack);

    /**
     *  GetTrackModificationTime()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    unsigned long
    GetTrackModificationTime(Track theTrack);

    /**
     *  GetTrackEnabled()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    Boolean
    GetTrackEnabled(Track theTrack);

    /**
     *  SetTrackEnabled()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SetTrackEnabled(Track theTrack, Boolean isEnabled);

    /**
     *  GetTrackUsage()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    long
    GetTrackUsage(Track theTrack);

    /**
     *  SetTrackUsage()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SetTrackUsage(Track theTrack, long usage);

    /**
     *  GetTrackDuration()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    TimeValue
    GetTrackDuration(Track theTrack);

    /**
     *  GetTrackOffset()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    TimeValue
    GetTrackOffset(Track theTrack);

    /**
     *  SetTrackOffset()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SetTrackOffset(Track theTrack, TimeValue movieOffsetTime);

    /**
     *  GetTrackLayer()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    short
    GetTrackLayer(Track theTrack);

    /**
     *  SetTrackLayer()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SetTrackLayer(Track theTrack, short layer);

    /**
     *  GetTrackAlternate()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    Track
    GetTrackAlternate(Track theTrack);

    /**
     *  SetTrackAlternate()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SetTrackAlternate(Track theTrack, Track alternateT);

    /**
     *  SetAutoTrackAlternatesEnabled()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SetAutoTrackAlternatesEnabled(Movie theMovie, Boolean enable);

    /**
     *  SelectMovieAlternates()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SelectMovieAlternates(Movie theMovie);

    /**
     *  GetTrackVolume()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    short
    GetTrackVolume(Track theTrack);

    /**
     *  SetTrackVolume()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SetTrackVolume(Track theTrack, short volume);

    /**
     *  GetTrackMatrix()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    GetTrackMatrix(Track theTrack, MatrixRecord *matrix);

    /**
     *  SetTrackMatrix()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SetTrackMatrix(Track theTrack, const MatrixRecord *matrix);

    /**
     *  GetTrackDimensions()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    GetTrackDimensions(Track theTrack, Fixed *width, Fixed *height);

    /**
     *  SetTrackDimensions()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SetTrackDimensions(Track theTrack, Fixed width, Fixed height);

    /**
     *  GetTrackUserData()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    UserData
    GetTrackUserData(Track theTrack);

    /**
     *  GetTrackDisplayMatrix()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    GetTrackDisplayMatrix(Track theTrack, MatrixRecord *matrix);

    /**
     *  GetTrackSoundLocalizationSettings()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    GetTrackSoundLocalizationSettings(Track theTrack, Handle *settings);

    /**
     *  SetTrackSoundLocalizationSettings()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    SetTrackSoundLocalizationSettings(Track theTrack, Handle settings);

    /*************************
     * get Media routines
     **************************/
    /**
     *  NewTrackMedia()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    Media
    NewTrackMedia(Track theTrack, OSType mediaType, TimeScale timeScale,
                  Handle dataRef, OSType dataRefType);

    /**
     *  DisposeTrackMedia()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    DisposeTrackMedia(Media theMedia);

    /**
     *  GetTrackMedia()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    Media
    GetTrackMedia(Track theTrack);

    /**
     *  GetMediaTrack()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    Track
    GetMediaTrack(Media theMedia);

    /*************************
     * Media State routines
     **************************/
    /**
     *  GetMediaCreationTime()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    unsigned long
    GetMediaCreationTime(Media theMedia);

    /**
     *  GetMediaModificationTime()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    unsigned long
    GetMediaModificationTime(Media theMedia);

    /**
     *  GetMediaTimeScale()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    TimeScale
    GetMediaTimeScale(Media theMedia);

    /**
     *  SetMediaTimeScale()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SetMediaTimeScale(Media theMedia, TimeScale timeScale);

    /**
     *  GetMediaDuration()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    TimeValue
    GetMediaDuration(Media theMedia);

    /**
     *  GetMediaLanguage()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    short
    GetMediaLanguage(Media theMedia);

    /**
     *  SetMediaLanguage()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SetMediaLanguage(Media theMedia, short language);

    /**
     *  GetMediaQuality()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    short
    GetMediaQuality(Media theMedia);

    /**
     *  SetMediaQuality()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SetMediaQuality(Media theMedia, short quality);

    /**
     *  GetMediaHandlerDescription()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    GetMediaHandlerDescription(Media theMedia, OSType *mediaType,
                               Str255 creatorName, OSType *creatorManufacturer);

    /**
     *  GetMediaUserData()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    UserData
    GetMediaUserData(Media theMedia);

    /**
     *  GetMediaInputMap()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    GetMediaInputMap(Media theMedia, QTAtomContainer *inputMap);

    /**
     *  SetMediaInputMap()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    SetMediaInputMap(Media theMedia, QTAtomContainer inputMap);

    /*************************
     * Media Handler routines
     **************************/
    /**
     *  GetMediaHandler()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    MediaHandler
    GetMediaHandler(Media theMedia);

    /**
     *  SetMediaHandler()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    SetMediaHandler(Media theMedia, MediaHandlerComponent mH);

    /*************************
     * Media's Data routines
     **************************/
    /**
     *  BeginMediaEdits()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    BeginMediaEdits(Media theMedia);

    /**
     *  EndMediaEdits()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    EndMediaEdits(Media theMedia);

    /**
     *  SetMediaDefaultDataRefIndex()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    SetMediaDefaultDataRefIndex(Media theMedia, short index);

    /**
     *  GetMediaDataHandlerDescription()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    GetMediaDataHandlerDescription(Media theMedia, short index, OSType *dhType,
                                   Str255 creatorName, OSType *creatorManufacturer);

    /**
     *  GetMediaDataHandler()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    DataHandler
    GetMediaDataHandler(Media theMedia, short index);

    /**
     *  SetMediaDataHandler()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    SetMediaDataHandler(Media theMedia, short index,
                        DataHandlerComponent dataHandler);

    /**
     *  GetDataHandler()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    Component
    GetDataHandler(Handle dataRef, OSType dataHandlerSubType, long flags);

    /**
     *  OpenADataHandler()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.1 and later
     *    \carbon_lib        in CarbonLib 1.1 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.1 and later
     */
    OSErr
    OpenADataHandler(Handle dataRef, OSType dataHandlerSubType,
                     Handle anchorDataRef, OSType anchorDataRefType, TimeBase tb,
                     long flags, ComponentInstance *dh);

    /*************************
     * Media Sample Table Routines
     **************************/
    /**
     *  GetMediaSampleDescriptionCount()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    long
    GetMediaSampleDescriptionCount(Media theMedia);

    /**
     *  GetMediaSampleDescription()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    GetMediaSampleDescription(Media theMedia, long index,
                              SampleDescriptionHandle descH);

    /**
     *  SetMediaSampleDescription()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    SetMediaSampleDescription(Media theMedia, long index,
                              SampleDescriptionHandle descH);

    /**
     *  GetMediaSampleCount()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    long
    GetMediaSampleCount(Media theMedia);

    /**
     *  GetMediaSyncSampleCount()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    long
    GetMediaSyncSampleCount(Media theMedia);

    /**
     *  SampleNumToMediaTime()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SampleNumToMediaTime(Media theMedia, long logicalSampleNum,
                         TimeValue *sampleTime, TimeValue *sampleDuration);

    /**
     *  MediaTimeToSampleNum()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    MediaTimeToSampleNum(Media theMedia, TimeValue time, long *sampleNum,
                         TimeValue *sampleTime, TimeValue *sampleDuration);

    /**
     *  AddMediaSample()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    AddMediaSample(Media theMedia, Handle dataIn, long inOffset, unsigned long size,
                   TimeValue durationPerSample,
                   SampleDescriptionHandle sampleDescriptionH, long numberOfSamples,
                   short sampleFlags, TimeValue *sampleTime);

    /**
     *  AddMediaSampleReference()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    AddMediaSampleReference(Media theMedia, long dataOffset, unsigned long size,
                            TimeValue durationPerSample,
                            SampleDescriptionHandle sampleDescriptionH,
                            long numberOfSamples, short sampleFlags,
                            TimeValue *sampleTime);

    /**
     *  AddMediaSampleReferences()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    AddMediaSampleReferences(Media theMedia,
                             SampleDescriptionHandle sampleDescriptionH,
                             long numberOfSamples, SampleReferencePtr sampleRefs,
                             TimeValue *sampleTime);

    /**
     *  AddMediaSampleReferences64()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    OSErr
    AddMediaSampleReferences64(Media theMedia,
                               SampleDescriptionHandle sampleDescriptionH,
                               long numberOfSamples,
                               SampleReference64Ptr sampleRefs,
                               TimeValue *sampleTime);

    /**
     *  GetMediaSample()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    GetMediaSample(Media theMedia, Handle dataOut, long maxSizeToGrow, long *size,
                   TimeValue time, TimeValue *sampleTime,
                   TimeValue *durationPerSample,
                   SampleDescriptionHandle sampleDescriptionH,
                   long *sampleDescriptionIndex, long maxNumberOfSamples,
                   long *numberOfSamples, short *sampleFlags);

    /**
     *  GetMediaSampleReference()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    GetMediaSampleReference(Media theMedia, long *dataOffset, long *size,
                            TimeValue time, TimeValue *sampleTime,
                            TimeValue *durationPerSample,
                            SampleDescriptionHandle sampleDescriptionH,
                            long *sampleDescriptionIndex, long maxNumberOfSamples,
                            long *numberOfSamples, short *sampleFlags);

    /**
     *  GetMediaSampleReferences()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    GetMediaSampleReferences(Media theMedia, TimeValue time, TimeValue *sampleTime,
                             SampleDescriptionHandle sampleDescriptionH,
                             long *sampleDescriptionIndex, long maxNumberOfEntries,
                             long *actualNumberofEntries,
                             SampleReferencePtr sampleRefs);

    /**
     *  GetMediaSampleReferences64()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    OSErr
    GetMediaSampleReferences64(Media theMedia, TimeValue time,
                               TimeValue *sampleTime,
                               SampleDescriptionHandle sampleDescriptionH,
                               long *sampleDescriptionIndex,
                               long maxNumberOfEntries, long *actualNumberofEntries,
                               SampleReference64Ptr sampleRefs);

    /**
     *  SetMediaPreferredChunkSize()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    SetMediaPreferredChunkSize(Media theMedia, long maxChunkSize);

    /**
     *  GetMediaPreferredChunkSize()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    GetMediaPreferredChunkSize(Media theMedia, long *maxChunkSize);

    /**
     *  SetMediaShadowSync()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    SetMediaShadowSync(Media theMedia, long frameDiffSampleNum, long syncSampleNum);

    /**
     *  GetMediaShadowSync()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    GetMediaShadowSync(Media theMedia, long frameDiffSampleNum, long *syncSampleNum);

    /*************************
     * Editing Routines
     **************************/
    /**
     *  InsertMediaIntoTrack()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    InsertMediaIntoTrack(Track theTrack, TimeValue trackStart, TimeValue mediaTime,
                         TimeValue mediaDuration, Fixed mediaRate);

    /**
     *  InsertTrackSegment()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    InsertTrackSegment(Track srcTrack, Track dstTrack, TimeValue srcIn,
                       TimeValue srcDuration, TimeValue dstIn);

    /**
     *  InsertMovieSegment()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    InsertMovieSegment(Movie srcMovie, Movie dstMovie, TimeValue srcIn,
                       TimeValue srcDuration, TimeValue dstIn);

    /**
     *  InsertEmptyTrackSegment()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    InsertEmptyTrackSegment(Track dstTrack, TimeValue dstIn, TimeValue dstDuration);

    /**
     *  InsertEmptyMovieSegment()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    InsertEmptyMovieSegment(Movie dstMovie, TimeValue dstIn, TimeValue dstDuration);

    /**
     *  DeleteTrackSegment()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    DeleteTrackSegment(Track theTrack, TimeValue startTime, TimeValue duration);

    /**
     *  DeleteMovieSegment()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    DeleteMovieSegment(Movie theMovie, TimeValue startTime, TimeValue duration);

    /**
     *  ScaleTrackSegment()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    ScaleTrackSegment(Track theTrack, TimeValue startTime, TimeValue oldDuration,
                      TimeValue newDuration);

    /**
     *  ScaleMovieSegment()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    ScaleMovieSegment(Movie theMovie, TimeValue startTime, TimeValue oldDuration,
                      TimeValue newDuration);

    /*************************
     * Hi-level Editing Routines
     **************************/
    /**
     *  CutMovieSelection()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    Movie
    CutMovieSelection(Movie theMovie);

    /**
     *  CopyMovieSelection()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    Movie
    CopyMovieSelection(Movie theMovie);

    /**
     *  PasteMovieSelection()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    PasteMovieSelection(Movie theMovie, Movie src);

    /**
     *  AddMovieSelection()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    AddMovieSelection(Movie theMovie, Movie src);

    /**
     *  ClearMovieSelection()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    ClearMovieSelection(Movie theMovie);

    /**
     *  PasteHandleIntoMovie()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    PasteHandleIntoMovie(Handle h, OSType handleType, Movie theMovie, long flags,
                         ComponentInstance userComp);

    /**
     *  PutMovieIntoTypedHandle()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    PutMovieIntoTypedHandle(Movie theMovie, Track targetTrack, OSType handleType,
                            Handle publicMovie, TimeValue start, TimeValue dur,
                            long flags, ComponentInstance userComp);

    /**
     *  IsScrapMovie()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    Component
    IsScrapMovie(Track targetTrack);

    /*************************
     * Middle-level Editing Routines
     **************************/
    /**
     *  CopyTrackSettings()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    CopyTrackSettings(Track srcTrack, Track dstTrack);

    /**
     *  CopyMovieSettings()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    CopyMovieSettings(Movie srcMovie, Movie dstMovie);

    /**
     *  AddEmptyTrackToMovie()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    AddEmptyTrackToMovie(Track srcTrack, Movie dstMovie, Handle dataRef,
                         OSType dataRefType, Track *dstTrack);

    enum
    {
        kQTCloneShareSamples = 1 << 0,
        kQTCloneDontCopyEdits = 1 << 1
    };

    /**
     *  AddClonedTrackToMovie()
     *

     *    \non_carbon_cfm   in QuickTimeLib 5.0 and later
     *    \carbon_lib        in CarbonLib 1.3 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 5.0 and later
     */
    OSErr
    AddClonedTrackToMovie(Track srcTrack, Movie dstMovie, long flags,
                          Track *dstTrack);

    /*************************
     * movie & track edit state routines
     **************************/
    /**
     *  NewMovieEditState()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    MovieEditState
    NewMovieEditState(Movie theMovie);

    /**
     *  UseMovieEditState()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    UseMovieEditState(Movie theMovie, MovieEditState toState);

    /**
     *  DisposeMovieEditState()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    DisposeMovieEditState(MovieEditState state);

    /**
     *  NewTrackEditState()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    TrackEditState
    NewTrackEditState(Track theTrack);

    /**
     *  UseTrackEditState()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    UseTrackEditState(Track theTrack, TrackEditState state);

    /**
     *  DisposeTrackEditState()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    DisposeTrackEditState(TrackEditState state);

    /*************************
     * track reference routines
     **************************/
    /**
     *  AddTrackReference()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    AddTrackReference(Track theTrack, Track refTrack, OSType refType,
                      long *addedIndex);

    /**
     *  DeleteTrackReference()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    DeleteTrackReference(Track theTrack, OSType refType, long index);

    /**
     *  SetTrackReference()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    SetTrackReference(Track theTrack, Track refTrack, OSType refType, long index);

    /**
     *  GetTrackReference()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    Track
    GetTrackReference(Track theTrack, OSType refType, long index);

    /**
     *  GetNextTrackReferenceType()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSType
    GetNextTrackReferenceType(Track theTrack, OSType refType);

    /**
     *  GetTrackReferenceCount()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    long
    GetTrackReferenceCount(Track theTrack, OSType refType);

    /*************************
     * high level file conversion routines
     **************************/
    /**
     *  ConvertFileToMovieFile()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    ConvertFileToMovieFile(const FSSpec *inputFile, const FSSpec *outputFile,
                           OSType creator, ScriptCode scriptTag, short *resID,
                           long flags, ComponentInstance userComp,
                           MovieProgressUPP proc, long refCon);

    /**
     *  ConvertMovieToFile()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    ConvertMovieToFile(Movie theMovie, Track onlyTrack, FSSpec *outputFile,
                       OSType fileType, OSType creator, ScriptCode scriptTag,
                       short *resID, long flags, ComponentInstance userComp);

    enum
    {
        kGetMovieImporterValidateToFind = 1L << 0,
        kGetMovieImporterAllowNewFile = 1L << 1,
        kGetMovieImporterDontConsiderGraphicsImporters = 1L << 2,
        kGetMovieImporterDontConsiderFileOnlyImporters = 1L << 6,
        kGetMovieImporterAutoImportOnly =
            1L << 10 /* reject aggressive movie importers which have
                        dontAutoFileMovieImport set*/
    };

    /**
     *  GetMovieImporterForDataRef()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    GetMovieImporterForDataRef(OSType dataRefType, Handle dataRef, long flags,
                               Component *importer);

    enum
    {
        kQTGetMIMETypeInfoIsQuickTimeMovieType =
            FOUR_CHAR_CODE('moov'), /* info is a pointer to a Boolean*/
        kQTGetMIMETypeInfoIsUnhelpfulType =
            FOUR_CHAR_CODE('dumb') /* info is a pointer to a Boolean*/
    };

    /**
     *  QTGetMIMETypeInfo()
     *

     *    \non_carbon_cfm   in QuickTimeLib 5.0 and later
     *    \carbon_lib        in CarbonLib 1.3 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 5.0 and later
     */
    OSErr
    QTGetMIMETypeInfo(const char *mimeStringStart, short mimeStringLength,
                      OSType infoSelector, void *infoDataPtr, long *infoDataSize);

    /*************************
     * Movie Timebase Conversion Routines
     **************************/
    /**
     *  TrackTimeToMediaTime()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    TimeValue
    TrackTimeToMediaTime(TimeValue value, Track theTrack);

    /**
     *  GetTrackEditRate()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    Fixed
    GetTrackEditRate(Track theTrack, TimeValue atTime);

    /*************************
     * Miscellaneous Routines
     **************************/

    /**
     *  GetMovieDataSize()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    long
    GetMovieDataSize(Movie theMovie, TimeValue startTime, TimeValue duration);

    /**
     *  GetMovieDataSize64()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    OSErr
    GetMovieDataSize64(Movie theMovie, TimeValue startTime, TimeValue duration,
                       wide *dataSize);

    /**
     *  GetTrackDataSize()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    long
    GetTrackDataSize(Track theTrack, TimeValue startTime, TimeValue duration);

    /**
     *  GetTrackDataSize64()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    OSErr
    GetTrackDataSize64(Track theTrack, TimeValue startTime, TimeValue duration,
                       wide *dataSize);

    /**
     *  GetMediaDataSize()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    long
    GetMediaDataSize(Media theMedia, TimeValue startTime, TimeValue duration);

    /**
     *  GetMediaDataSize64()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    OSErr
    GetMediaDataSize64(Media theMedia, TimeValue startTime, TimeValue duration,
                       wide *dataSize);

    /**
     *  PtInMovie()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    Boolean
    PtInMovie(Movie theMovie, Point pt);

    /**
     *  PtInTrack()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    Boolean
    PtInTrack(Track theTrack, Point pt);

    /*************************
     * Group Selection Routines
     **************************/

    /**
     *  SetMovieLanguage()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SetMovieLanguage(Movie theMovie, long language);

    /*************************
     * User Data
     **************************/

    /**
     *  GetUserData()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    GetUserData(UserData theUserData, Handle data, OSType udType, long index);

    /**
     *  AddUserData()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    AddUserData(UserData theUserData, Handle data, OSType udType);

    /**
     *  RemoveUserData()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    RemoveUserData(UserData theUserData, OSType udType, long index);

    /**
     *  CountUserDataType()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    short
    CountUserDataType(UserData theUserData, OSType udType);

    /**
     *  GetNextUserDataType()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    long
    GetNextUserDataType(UserData theUserData, OSType udType);

    /**
     *  GetUserDataItem()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    GetUserDataItem(UserData theUserData, void *data, long size, OSType udType,
                    long index);

    /**
     *  SetUserDataItem()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    SetUserDataItem(UserData theUserData, void *data, long size, OSType udType,
                    long index);

    /**
     *  AddUserDataText()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    AddUserDataText(UserData theUserData, Handle data, OSType udType, long index,
                    short itlRegionTag);

    /**
     *  GetUserDataText()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    GetUserDataText(UserData theUserData, Handle data, OSType udType, long index,
                    short itlRegionTag);

    /**
     *  RemoveUserDataText()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    RemoveUserDataText(UserData theUserData, OSType udType, long index,
                       short itlRegionTag);

    /**
     *  NewUserData()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    NewUserData(UserData *theUserData);

    /**
     *  DisposeUserData()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    DisposeUserData(UserData theUserData);

    /**
     *  NewUserDataFromHandle()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    NewUserDataFromHandle(Handle h, UserData *theUserData);

    /**
     *  PutUserDataIntoHandle()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    PutUserDataIntoHandle(UserData theUserData, Handle h);

    /**
     *  SetMoviePropertyAtom()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.1 and later
     *    \carbon_lib        in CarbonLib 1.1 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.1 and later
     */
    OSErr
    SetMoviePropertyAtom(Movie theMovie, QTAtomContainer propertyAtom);

    /**
     *  GetMoviePropertyAtom()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.1 and later
     *    \carbon_lib        in CarbonLib 1.1 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.1 and later
     */
    OSErr
    GetMoviePropertyAtom(Movie theMovie, QTAtomContainer *propertyAtom);

    /**
     *  GetMediaNextInterestingTime()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    GetMediaNextInterestingTime(Media theMedia, short interestingTimeFlags,
                                TimeValue time, Fixed rate,
                                TimeValue *interestingTime,
                                TimeValue *interestingDuration);

    /**
     *  GetTrackNextInterestingTime()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    GetTrackNextInterestingTime(Track theTrack, short interestingTimeFlags,
                                TimeValue time, Fixed rate,
                                TimeValue *interestingTime,
                                TimeValue *interestingDuration);

    /**
     *  GetMovieNextInterestingTime()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    GetMovieNextInterestingTime(Movie theMovie, short interestingTimeFlags,
                                short numMediaTypes, const OSType *whichMediaTypes,
                                TimeValue time, Fixed rate,
                                TimeValue *interestingTime,
                                TimeValue *interestingDuration);

    /**
     *  CreateMovieFile()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    CreateMovieFile(const FSSpec *fileSpec, OSType creator, ScriptCode scriptTag,
                    long createMovieFileFlags, short *resRefNum, Movie *newmovie);

    /**
     *  OpenMovieFile()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    OpenMovieFile(const FSSpec *fileSpec, short *resRefNum, SInt8 permission);

    /**
     *  CloseMovieFile()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    CloseMovieFile(short resRefNum);

    /**
     *  DeleteMovieFile()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    DeleteMovieFile(const FSSpec *fileSpec);

    /**
     *  NewMovieFromFile()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    NewMovieFromFile(
        Movie *theMovie, short resRefNum, short *resId, /* can be NULL */
        StringPtr resName, short newMovieFlags,
        Boolean *dataRefWasChanged) /* can be NULL */;

    /**
     *  NewMovieFromHandle()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    NewMovieFromHandle(Movie *theMovie, Handle h, short newMovieFlags,
                       Boolean *dataRefWasChanged);

    /**
     *  NewMovieFromDataFork()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    NewMovieFromDataFork(Movie *theMovie, short fRefNum, long fileOffset,
                         short newMovieFlags, Boolean *dataRefWasChanged);

    /**
     *  NewMovieFromDataFork64()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    OSErr
    NewMovieFromDataFork64(Movie *theMovie, long fRefNum, const wide *fileOffset,
                           short newMovieFlags, Boolean *dataRefWasChanged);

    /**
     *  NewMovieFromUserProc()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    NewMovieFromUserProc(Movie *m, short flags, Boolean *dataRefWasChanged,
                         GetMovieUPP getProc, void *refCon, Handle defaultDataRef,
                         OSType dataRefType);

    /**
     *  NewMovieFromDataRef()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    NewMovieFromDataRef(Movie *m, short flags, short *id, Handle dataRef,
                        OSType dataRefType);

    /**
     *  AddMovieResource()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    AddMovieResource(Movie theMovie, short resRefNum, short *resId,
                     ConstStr255Param resName);

    /**
     *  UpdateMovieResource()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    UpdateMovieResource(Movie theMovie, short resRefNum, short resId,
                        ConstStr255Param resName);

    /**
     *  RemoveMovieResource()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    RemoveMovieResource(short resRefNum, short resId);

    /**
     *  HasMovieChanged()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    Boolean
    HasMovieChanged(Movie theMovie);

    /**
     *  ClearMovieChanged()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    ClearMovieChanged(Movie theMovie);

    /**
     *  SetMovieDefaultDataRef()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    SetMovieDefaultDataRef(Movie theMovie, Handle dataRef, OSType dataRefType);

    /**
     *  GetMovieDefaultDataRef()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    GetMovieDefaultDataRef(Movie theMovie, Handle *dataRef, OSType *dataRefType);

    /**
     *  SetMovieAnchorDataRef()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.1 and later
     *    \carbon_lib        in CarbonLib 1.1 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.1 and later
     */
    OSErr
    SetMovieAnchorDataRef(Movie theMovie, Handle dataRef, OSType dataRefType);

    /**
     *  GetMovieAnchorDataRef()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.1 and later
     *    \carbon_lib        in CarbonLib 1.1 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.1 and later
     */
    OSErr
    GetMovieAnchorDataRef(Movie theMovie, Handle *dataRef, OSType *dataRefType,
                          long *outFlags);

    /**
     *  SetMovieColorTable()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    SetMovieColorTable(Movie theMovie, CTabHandle ctab);

    /**
     *  GetMovieColorTable()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    GetMovieColorTable(Movie theMovie, CTabHandle *ctab);

    /**
     *  FlattenMovie()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    FlattenMovie(Movie theMovie, long movieFlattenFlags, const FSSpec *theFile,
                 OSType creator, ScriptCode scriptTag, long createMovieFileFlags,
                 short *resId, ConstStr255Param resName);

    /**
     *  FlattenMovieData()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    Movie
    FlattenMovieData(Movie theMovie, long movieFlattenFlags, const FSSpec *theFile,
                     OSType creator, ScriptCode scriptTag,
                     long createMovieFileFlags);

    /**
     *  SetMovieProgressProc()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SetMovieProgressProc(Movie theMovie, MovieProgressUPP p, long refcon);

    /**
     *  GetMovieProgressProc()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    void
    GetMovieProgressProc(Movie theMovie, MovieProgressUPP *p, long *refcon);

    /**
     *  CreateShortcutMovieFile()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    OSErr
    CreateShortcutMovieFile(const FSSpec *fileSpec, OSType creator,
                            ScriptCode scriptTag, long createMovieFileFlags,
                            Handle targetDataRef, OSType targetDataRefType);

    /**
     *  MovieSearchText()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    MovieSearchText(Movie theMovie, Ptr text, long size, long searchFlags,
                    Track *searchTrack, TimeValue *searchTime, long *searchOffset);

    /**
     *  GetPosterBox()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    GetPosterBox(Movie theMovie, Rect *boxRect);

    /**
     *  SetPosterBox()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SetPosterBox(Movie theMovie, const Rect *boxRect);

    /**
     *  GetMovieSegmentDisplayBoundsRgn()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    RgnHandle
    GetMovieSegmentDisplayBoundsRgn(Movie theMovie, TimeValue time,
                                    TimeValue duration);

    /**
     *  GetTrackSegmentDisplayBoundsRgn()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    RgnHandle
    GetTrackSegmentDisplayBoundsRgn(Track theTrack, TimeValue time,
                                    TimeValue duration);

    /**
     *  SetMovieCoverProcs()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SetMovieCoverProcs(Movie theMovie, MovieRgnCoverUPP uncoverProc,
                       MovieRgnCoverUPP coverProc, long refcon);

    /**
     *  GetMovieCoverProcs()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    GetMovieCoverProcs(Movie theMovie, MovieRgnCoverUPP *uncoverProc,
                       MovieRgnCoverUPP *coverProc, long *refcon);

    /**
     *  GetTrackStatus()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    GetTrackStatus(Track theTrack);

    /**
     *  GetMovieStatus()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    GetMovieStatus(Movie theMovie, Track *firstProblemTrack);

    enum
    {
        kMovieLoadStateError = -1L,
        kMovieLoadStateLoading = 1000,
        kMovieLoadStateLoaded = 2000,
        kMovieLoadStatePlayable = 10000,
        kMovieLoadStatePlaythroughOK = 20000,
        kMovieLoadStateComplete = 100000L
    };

    /**
     *  GetMovieLoadState()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.1 and later
     *    \carbon_lib        in CarbonLib 1.1 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.1 and later
     */
    long
    GetMovieLoadState(Movie theMovie);

    /* Input flags for CanQuickTimeOpenFile/DataRef */
    enum
    {
        kQTDontUseDataToFindImporter = 1L << 0,
        kQTDontLookForMovieImporterIfGraphicsImporterFound = 1L << 1,
        kQTAllowOpeningStillImagesAsMovies = 1L << 2,
        kQTAllowImportersThatWouldCreateNewFile = 1L << 3,
        kQTAllowAggressiveImporters = 1L << 4 /* eg, TEXT and PICT movie importers*/
    };

    /* Determines whether the file could be opened using a graphics importer or
     * opened in place as a movie. */
    /**
     *  CanQuickTimeOpenFile()
     *

     *    \non_carbon_cfm   in QuickTimeLib 5.0 and later
     *    \carbon_lib        in CarbonLib 1.3 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 5.0 and later
     */
    OSErr
    CanQuickTimeOpenFile(FSSpecPtr fileSpec, OSType fileType,
                         OSType fileNameExtension,
                         Boolean *outCanOpenWithGraphicsImporter,
                         Boolean *outCanOpenAsMovie,
                         Boolean *outPreferGraphicsImporter, UInt32 inFlags);

    /* Determines whether the file could be opened using a graphics importer or
     * opened in place as a movie. */
    /**
     *  CanQuickTimeOpenDataRef()
     *

     *    \non_carbon_cfm   in QuickTimeLib 5.0 and later
     *    \carbon_lib        in CarbonLib 1.3 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 5.0 and later
     */
    OSErr
    CanQuickTimeOpenDataRef(Handle dataRef, OSType dataRefType,
                            Boolean *outCanOpenWithGraphicsImporter,
                            Boolean *outCanOpenAsMovie,
                            Boolean *outPreferGraphicsImporter, UInt32 inFlags);

    /****
        Movie Controller support routines
    ****/
    /**
     *  NewMovieController()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentInstance
    NewMovieController(Movie theMovie, const Rect *movieRect, long someFlags);

    /**
     *  DisposeMovieController()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    DisposeMovieController(ComponentInstance mc);

    /**
     *  ShowMovieInformation()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    ShowMovieInformation(Movie theMovie, ModalFilterUPP filterProc, long refCon);

    /*****
        Scrap routines
    *****/
    /**
     *  PutMovieOnScrap()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    PutMovieOnScrap(Movie theMovie, long movieScrapFlags);

    /**
     *  NewMovieFromScrap()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    Movie
    NewMovieFromScrap(long newMovieFlags);

    /*****
        DataRef routines
    *****/

    /**
     *  GetMediaDataRef()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    GetMediaDataRef(Media theMedia, short index, Handle *dataRef,
                    OSType *dataRefType, long *dataRefAttributes);

    /**
     *  SetMediaDataRef()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    SetMediaDataRef(Media theMedia, short index, Handle dataRef, OSType dataRefType);

    /**
     *  SetMediaDataRefAttributes()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    SetMediaDataRefAttributes(Media theMedia, short index, long dataRefAttributes);

    /**
     *  AddMediaDataRef()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    AddMediaDataRef(Media theMedia, short *index, Handle dataRef,
                    OSType dataRefType);

    /**
     *  GetMediaDataRefCount()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    GetMediaDataRefCount(Media theMedia, short *count);

    /**
     *  QTNewAlias()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    QTNewAlias(const FSSpec *fss, AliasHandle *alias, Boolean minimal);

    /*****
        Playback hint routines
    *****/
    /**
     *  SetMoviePlayHints()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SetMoviePlayHints(Movie theMovie, long flags, long flagsMask);

    /**
     *  SetMediaPlayHints()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SetMediaPlayHints(Media theMedia, long flags, long flagsMask);

    /**
     *  GetMediaPlayHints()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    GetMediaPlayHints(Media theMedia, long *flags);

    /*****
        Load time track hints
    *****/
    enum
    {
        preloadAlways = 1L << 0,
        preloadOnlyIfEnabled = 1L << 1
    };

    /**
     *  SetTrackLoadSettings()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SetTrackLoadSettings(Track theTrack, TimeValue preloadTime,
                         TimeValue preloadDuration, long preloadFlags,
                         long defaultHints);

    /**
     *  GetTrackLoadSettings()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    GetTrackLoadSettings(Track theTrack, TimeValue *preloadTime,
                         TimeValue *preloadDuration, long *preloadFlags,
                         long *defaultHints);

    /*****
        Big screen TV
    *****/
    enum
    {
        fullScreenHideCursor = 1L << 0,
        fullScreenAllowEvents = 1L << 1,
        fullScreenDontChangeMenuBar = 1L << 2,
        fullScreenPreflightSize = 1L << 3
    };

    /**
     *  BeginFullScreen()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    BeginFullScreen(Ptr *restoreState, GDHandle whichGD, short *desiredWidth,
                    short *desiredHeight, WindowRef *newWindow,
                    RGBColor *eraseColor, long flags);

    /**
     *  EndFullScreen()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    EndFullScreen(Ptr fullState, long flags);

    /*****
        Wired Actions
    *****/
    /* flags for MovieExecuteWiredActions*/
    enum
    {
        movieExecuteWiredActionDontExecute = 1L << 0
    };

    /**
     *  AddMovieExecuteWiredActionsProc()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    OSErr
    AddMovieExecuteWiredActionsProc(Movie theMovie,
                                    MovieExecuteWiredActionsUPP proc, void *refCon);

    /**
     *  RemoveMovieExecuteWiredActionsProc()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    OSErr
    RemoveMovieExecuteWiredActionsProc(Movie theMovie,
                                       MovieExecuteWiredActionsUPP proc,
                                       void *refCon);

    /**
     *  MovieExecuteWiredActions()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    OSErr
    MovieExecuteWiredActions(Movie theMovie, long flags, QTAtomContainer actions);

    /*****
        Sprite Toolbox
    *****/
    enum
    {
        kBackgroundSpriteLayerNum = 32767
    };

    /*  Sprite Properties*/
    enum
    {
        kSpritePropertyMatrix = 1,
        kSpritePropertyImageDescription = 2,
        kSpritePropertyImageDataPtr = 3,
        kSpritePropertyVisible = 4,
        kSpritePropertyLayer = 5,
        kSpritePropertyGraphicsMode = 6,
        kSpritePropertyImageDataSize = 7,
        kSpritePropertyActionHandlingSpriteID = 8,
        kSpritePropertyImageIndex = 100,
        kSpriteTrackPropertyBackgroundColor = 101,
        kSpriteTrackPropertyOffscreenBitDepth = 102,
        kSpriteTrackPropertySampleFormat = 103,
        kSpriteTrackPropertyScaleSpritesToScaleWorld = 104,
        kSpriteTrackPropertyHasActions = 105,
        kSpriteTrackPropertyVisible = 106,
        kSpriteTrackPropertyQTIdleEventsFrequency = 107,
        kSpriteImagePropertyRegistrationPoint = 1000,
        kSpriteImagePropertyGroupID = 1001
    };

    /* special value for kSpriteTrackPropertyQTIdleEventsFrequency (the default)*/
    enum
    {
        kNoQTIdleEvents = -1
    };

    /* flagsIn for SpriteWorldIdle*/
    enum
    {
        kOnlyDrawToSpriteWorld = 1L << 0,
        kSpriteWorldPreflight = 1L << 1
    };

    /* flagsOut for SpriteWorldIdle*/
    enum
    {
        kSpriteWorldDidDraw = 1L << 0,
        kSpriteWorldNeedsToDraw = 1L << 1
    };

    /* flags for sprite track sample format*/
    enum
    {
        kKeyFrameAndSingleOverride = 1L << 1,
        kKeyFrameAndAllOverrides = 1L << 2
    };

    /* sprite world flags*/
    enum
    {
        kScaleSpritesToScaleWorld = 1L << 1,
        kSpriteWorldHighQuality = 1L << 2,
        kSpriteWorldDontAutoInvalidate = 1L << 3,
        kSpriteWorldInvisible = 1L << 4
    };

    /**
     *  NewSpriteWorld()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    NewSpriteWorld(SpriteWorld *newSpriteWorld, GWorldPtr destination,
                   GWorldPtr spriteLayer, RGBColor *backgroundColor,
                   GWorldPtr background);

    /**
     *  DisposeSpriteWorld()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    DisposeSpriteWorld(SpriteWorld theSpriteWorld);

    /**
     *  SetSpriteWorldClip()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    SetSpriteWorldClip(SpriteWorld theSpriteWorld, RgnHandle clipRgn);

    /**
     *  SetSpriteWorldMatrix()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    SetSpriteWorldMatrix(SpriteWorld theSpriteWorld, const MatrixRecord *matrix);

    /**
     *  SetSpriteWorldGraphicsMode()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    SetSpriteWorldGraphicsMode(SpriteWorld theSpriteWorld, long mode,
                               const RGBColor *opColor);

    /**
     *  SpriteWorldIdle()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    SpriteWorldIdle(SpriteWorld theSpriteWorld, long flagsIn, long *flagsOut);

    /**
     *  InvalidateSpriteWorld()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    InvalidateSpriteWorld(SpriteWorld theSpriteWorld, Rect *invalidArea);

    /**
     *  SpriteWorldHitTest()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    SpriteWorldHitTest(SpriteWorld theSpriteWorld, long flags, Point loc,
                       Sprite *spriteHit);

    /**
     *  SpriteHitTest()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    SpriteHitTest(Sprite theSprite, long flags, Point loc, Boolean *wasHit);

    /**
     *  DisposeAllSprites()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    DisposeAllSprites(SpriteWorld theSpriteWorld);

    /**
     *  SetSpriteWorldFlags()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    SetSpriteWorldFlags(SpriteWorld spriteWorld, long flags, long flagsMask);

    /**
     *  NewSprite()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    NewSprite(Sprite *newSprite, SpriteWorld itsSpriteWorld,
              ImageDescriptionHandle idh, Ptr imageDataPtr, MatrixRecord *matrix,
              Boolean visible, short layer);

    /**
     *  DisposeSprite()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    DisposeSprite(Sprite theSprite);

    /**
     *  InvalidateSprite()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    InvalidateSprite(Sprite theSprite);

    /**
     *  SetSpriteProperty()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    SetSpriteProperty(Sprite theSprite, long propertyType, void *propertyValue);

    /**
     *  GetSpriteProperty()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    GetSpriteProperty(Sprite theSprite, long propertyType, void *propertyValue);

    /*****
        QT Atom Data Support
    *****/
    enum
    {
        kParentAtomIsContainer = 0
    };

    /* create and dispose QTAtomContainer objects*/

    /**
     *  QTNewAtomContainer()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    QTNewAtomContainer(QTAtomContainer *atomData);

    /**
     *  QTDisposeAtomContainer()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    QTDisposeAtomContainer(QTAtomContainer atomData);

    /* locating nested atoms within QTAtomContainer container*/

    /**
     *  QTGetNextChildType()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    QTAtomType
    QTGetNextChildType(QTAtomContainer container, QTAtom parentAtom,
                       QTAtomType currentChildType);

    /**
     *  QTCountChildrenOfType()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    short
    QTCountChildrenOfType(QTAtomContainer container, QTAtom parentAtom,
                          QTAtomType childType);

    /**
     *  QTFindChildByIndex()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    QTAtom
    QTFindChildByIndex(QTAtomContainer container, QTAtom parentAtom,
                       QTAtomType atomType, short index, QTAtomID *id);

    /**
     *  QTFindChildByID()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    QTAtom
    QTFindChildByID(QTAtomContainer container, QTAtom parentAtom,
                    QTAtomType atomType, QTAtomID id, short *index);

    /**
     *  QTNextChildAnyType()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    QTNextChildAnyType(QTAtomContainer container, QTAtom parentAtom,
                       QTAtom currentChild, QTAtom *nextChild);

    /* set a leaf atom's data*/
    /**
     *  QTSetAtomData()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    QTSetAtomData(QTAtomContainer container, QTAtom atom, long dataSize,
                  void *atomData);

    /* extracting data*/
    /**
     *  QTCopyAtomDataToHandle()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    QTCopyAtomDataToHandle(QTAtomContainer container, QTAtom atom,
                           Handle targetHandle);

    /**
     *  QTCopyAtomDataToPtr()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    QTCopyAtomDataToPtr(QTAtomContainer container, QTAtom atom,
                        Boolean sizeOrLessOK, long size, void *targetPtr,
                        long *actualSize);

    /**
     *  QTGetAtomTypeAndID()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    QTGetAtomTypeAndID(QTAtomContainer container, QTAtom atom, QTAtomType *atomType,
                       QTAtomID *id);

    /* extract a copy of an atom and all of it's children, caller disposes*/
    /**
     *  QTCopyAtom()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    QTCopyAtom(QTAtomContainer container, QTAtom atom,
               QTAtomContainer *targetContainer);

    /* obtaining direct reference to atom data*/
    /**
     *  QTLockContainer()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    QTLockContainer(QTAtomContainer container);

    /**
     *  QTGetAtomDataPtr()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    QTGetAtomDataPtr(QTAtomContainer container, QTAtom atom, long *dataSize,
                     Ptr *atomData);

    /**
     *  QTUnlockContainer()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    QTUnlockContainer(QTAtomContainer container);

    /**
       building QTAtomContainer trees
       creates and inserts new atom at specified index, existing atoms at or after
       index are moved toward end of list used for Top-Down tree creation
    */
    /**
     *  QTInsertChild()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    QTInsertChild(QTAtomContainer container, QTAtom parentAtom, QTAtomType atomType,
                  QTAtomID id, short index, long dataSize, void *data,
                  QTAtom *newAtom);

    /* inserts children from childrenContainer as children of parentAtom*/
    /**
     *  QTInsertChildren()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    QTInsertChildren(QTAtomContainer container, QTAtom parentAtom,
                     QTAtomContainer childrenContainer);

    /* destruction*/
    /**
     *  QTRemoveAtom()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    QTRemoveAtom(QTAtomContainer container, QTAtom atom);

    /**
     *  QTRemoveChildren()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    QTRemoveChildren(QTAtomContainer container, QTAtom atom);

    /* replacement must be same type as target*/
    /**
     *  QTReplaceAtom()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    QTReplaceAtom(QTAtomContainer targetContainer, QTAtom targetAtom,
                  QTAtomContainer replacementContainer, QTAtom replacementAtom);

    /**
     *  QTSwapAtoms()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    QTSwapAtoms(QTAtomContainer container, QTAtom atom1, QTAtom atom2);

    /**
     *  QTSetAtomID()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    QTSetAtomID(QTAtomContainer container, QTAtom atom, QTAtomID newID);

    /**
     *  QTGetAtomParent()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    QTAtom
    QTGetAtomParent(QTAtomContainer container, QTAtom childAtom);

    /**
     *  SetMediaPropertyAtom()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    SetMediaPropertyAtom(Media theMedia, QTAtomContainer propertyAtom);

    /**
     *  GetMediaPropertyAtom()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    GetMediaPropertyAtom(Media theMedia, QTAtomContainer *propertyAtom);

    /*****
        Tween Support
    *****/
    typedef struct TweenRecord TweenRecord;
    typedef CALLBACK_API(ComponentResult, TweenerDataProcPtr)(
        TweenRecord *tr, void *tweenData, long tweenDataSize,
        long dataDescriptionSeed, Handle dataDescription,
        ICMCompletionProcRecordPtr asyncCompletionProc,
        UniversalProcPtr transferProc, void *refCon);
    typedef STACK_UPP_TYPE(TweenerDataProcPtr) TweenerDataUPP;
    struct TweenRecord
    {
        long version;

        QTAtomContainer container;
        QTAtom tweenAtom;
        QTAtom dataAtom;
        Fixed percent;

        TweenerDataUPP dataProc;

        void *private1;
        void *private2;
    };

    struct TweenV1Record
    {
        long version;

        QTAtomContainer container;
        QTAtom tweenAtom;
        QTAtom dataAtom;
        Fixed percent;

        TweenerDataUPP dataProc;

        void *private1;
        void *private2;

        Fract fractPercent;
    };
    typedef struct TweenV1Record TweenV1Record;
    /**
     *  QTNewTween()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    QTNewTween(QTTweener *tween, QTAtomContainer container, QTAtom tweenAtom,
               TimeValue maxTime);

    /**
     *  QTDisposeTween()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    QTDisposeTween(QTTweener tween);

    /**
     *  QTDoTween()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    QTDoTween(QTTweener tween, TimeValue atTime, Handle result, long *resultSize,
              TweenerDataUPP tweenDataProc, void *tweenDataRefCon);

    /*****
        Sound Description Manipulations
    *****/
    /**
     *  AddSoundDescriptionExtension()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    AddSoundDescriptionExtension(SoundDescriptionHandle desc, Handle extension,
                                 OSType idType);

    /**
     *  GetSoundDescriptionExtension()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    GetSoundDescriptionExtension(SoundDescriptionHandle desc, Handle *extension,
                                 OSType idType);

    /**
     *  RemoveSoundDescriptionExtension()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    RemoveSoundDescriptionExtension(SoundDescriptionHandle desc, OSType idType);

    /*****
        Preferences
    *****/
    /**
     *  GetQuickTimePreference()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    GetQuickTimePreference(OSType preferenceType, QTAtomContainer *preferenceAtom);

    /**
     *  SetQuickTimePreference()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    SetQuickTimePreference(OSType preferenceType, QTAtomContainer preferenceAtom);

    /*****
        Effects and dialog Support
    *****/
    /* atom types for entries in the effects list*/
    enum
    {
        kEffectNameAtom = FOUR_CHAR_CODE('name'), /* name of effect */
        kEffectTypeAtom = FOUR_CHAR_CODE('type'), /* codec sub-type for effect */
        kEffectManufacturerAtom =
            FOUR_CHAR_CODE('manu') /* codec manufacturer for effect */
    };

    struct QTParamPreviewRecord
    {
        long sourceID;           /* 1 based source identifier*/
        PicHandle sourcePicture; /* picture for preview, must not dispose until dialog
                                    is disposed*/
    };
    typedef struct QTParamPreviewRecord QTParamPreviewRecord;
    typedef QTParamPreviewRecord *QTParamPreviewPtr;
    struct QTParamDialogEventRecord
    {
        EventRecord *theEvent; /* Event received by the dialog */
        DialogRef whichDialog; /* dialog that event was directed towards */
        short itemHit;         /* dialog item which was hit */
    };
    typedef struct QTParamDialogEventRecord QTParamDialogEventRecord;
    typedef QTParamDialogEventRecord *QTParamDialogEventPtr;
    struct QTParamFetchPreviewRecord
    {
        GWorldPtr theWorld; /* the world into which to draw the preview */
        Fixed percentage;   /* frame percentage (from 0.0 - 1.0) to be drawn */
    };
    typedef struct QTParamFetchPreviewRecord QTParamFetchPreviewRecord;
    typedef QTParamFetchPreviewRecord *QTParamFetchPreviewPtr;
    enum
    {
        pdActionConfirmDialog = 1,           /* no param*/
        pdActionSetAppleMenu = 2,            /* param is MenuRef*/
        pdActionSetEditMenu = 3,             /* param is MenuRef*/
        pdActionGetDialogValues = 4,         /* param is QTAtomContainer*/
        pdActionSetPreviewUserItem = 5,      /* param is long*/
        pdActionSetPreviewPicture = 6,       /* param is QTParamPreviewPtr;*/
        pdActionSetColorPickerEventProc = 7, /* param is UserEventUPP*/
        pdActionSetDialogTitle = 8,          /* param is StringPtr */
        pdActionGetSubPanelMenu = 9,         /* param is MenuRef* */
        pdActionActivateSubPanel = 10,       /* param is long */
        pdActionConductStopAlert = 11,       /* param is StringPtr */
        pdActionModelessCallback = 12,       /* param is QTParamDialogEventPtr */
        pdActionFetchPreview = 13            /* param is QTParamFetchPreviewPtr */
    };

    typedef long QTParameterDialog;
    enum
    {
        elOptionsIncludeNoneInList =
            0x00000001 /* "None" effect is included in list */
    };

    typedef long QTEffectListOptions;
    enum
    {
        pdOptionsCollectOneValue = 0x00000001, /* should collect a single value only*/
        pdOptionsAllowOptionalInterpolations =
            0x00000002,                      /* non-novice interpolation options are shown */
        pdOptionsModalDialogBox = 0x00000004 /* dialog box should be modal */
    };

    typedef long QTParameterDialogOptions;
    enum
    {
        effectIsRealtime = 0 /* effect can be rendered in real time */
    };

    /**
     *  QTGetEffectsList()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    QTGetEffectsList(QTAtomContainer *returnedList, long minSources,
                     long maxSources, QTEffectListOptions getOptions);

    /**
     *  QTCreateStandardParameterDialog()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    QTCreateStandardParameterDialog(QTAtomContainer effectList,
                                    QTAtomContainer parameters,
                                    QTParameterDialogOptions dialogOptions,
                                    QTParameterDialog *createdDialog);

    /**
     *  QTIsStandardParameterDialogEvent()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    QTIsStandardParameterDialogEvent(EventRecord *pEvent,
                                     QTParameterDialog createdDialog);

    /**
     *  QTDismissStandardParameterDialog()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    QTDismissStandardParameterDialog(QTParameterDialog createdDialog);

    /**
     *  QTStandardParameterDialogDoAction()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    QTStandardParameterDialogDoAction(QTParameterDialog createdDialog, long action,
                                      void *params);

    /**
     *  QTGetEffectSpeed()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    QTGetEffectSpeed(QTAtomContainer parameters, Fixed *pFPS);

    /*****
        Access Keys
    *****/
    enum
    {
        kAccessKeyAtomType = FOUR_CHAR_CODE('acky')
    };

    enum
    {
        kAccessKeySystemFlag = 1L << 0
    };

    /**
     *  QTGetAccessKeys()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    QTGetAccessKeys(Str255 accessKeyType, long flags, QTAtomContainer *keys);

    /**
     *  QTRegisterAccessKey()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    QTRegisterAccessKey(Str255 accessKeyType, long flags, Handle accessKey);

    /**
     *  QTUnregisterAccessKey()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    QTUnregisterAccessKey(Str255 accessKeyType, long flags, Handle accessKey);

    /*****
        Time table
    *****/
    /**
     *  MakeTrackTimeTable()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    MakeTrackTimeTable(Track trackH, long **offsets, TimeValue startTime,
                       TimeValue endTime, TimeValue timeIncrement,
                       short firstDataRefIndex, short lastDataRefIndex,
                       long *retdataRefSkew);

    /**
     *  MakeMediaTimeTable()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    MakeMediaTimeTable(Media theMedia, long **offsets, TimeValue startTime,
                       TimeValue endTime, TimeValue timeIncrement,
                       short firstDataRefIndex, short lastDataRefIndex,
                       long *retdataRefSkew);

    /**
     *  GetMaxLoadedTimeInMovie()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    GetMaxLoadedTimeInMovie(Movie theMovie, TimeValue *time);

    /**
     *  QTMovieNeedsTimeTable()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    QTMovieNeedsTimeTable(Movie theMovie, Boolean *needsTimeTable);

    /**
     *  QTGetDataRefMaxFileOffset()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    QTGetDataRefMaxFileOffset(Movie movieH, OSType dataRefType, Handle dataRef,
                              long *offset);

    /*****
        Bandwidth management support
    *****/
    enum
    {
        ConnectionSpeedPrefsType = FOUR_CHAR_CODE('cspd'),
        BandwidthManagementPrefsType = FOUR_CHAR_CODE('bwmg')
    };

    struct ConnectionSpeedPrefsRecord
    {
        long connectionSpeed;
    };
    typedef struct ConnectionSpeedPrefsRecord ConnectionSpeedPrefsRecord;
    typedef ConnectionSpeedPrefsRecord *ConnectionSpeedPrefsPtr;
    typedef ConnectionSpeedPrefsPtr *ConnectionSpeedPrefsHandle;
    struct BandwidthManagementPrefsRecord
    {
        Boolean overrideConnectionSpeedForBandwidth;
    };
    typedef struct BandwidthManagementPrefsRecord BandwidthManagementPrefsRecord;
    typedef BandwidthManagementPrefsRecord *BandwidthManagementPrefsPtr;
    typedef BandwidthManagementPrefsPtr *BandwidthManagementPrefsHandle;
    enum
    {
        kQTIdlePriority = 10,
        kQTNonRealTimePriority = 20,
        kQTRealTimeSharedPriority = 25,
        kQTRealTimePriority = 30
    };

    enum
    {
        kQTBandwidthNotifyNeedToStop = 1L << 0,
        kQTBandwidthNotifyGoodToGo = 1L << 1,
        kQTBandwidthChangeRequest = 1L << 2,
        kQTBandwidthQueueRequest = 1L << 3,
        kQTBandwidthScheduledRequest = 1L << 4,
        kQTBandwidthVoluntaryRelease = 1L << 5
    };

    typedef CALLBACK_API(OSErr, QTBandwidthNotificationProcPtr)(long flags,
                                                                void *reserved,
                                                                void *refcon);
    typedef STACK_UPP_TYPE(QTBandwidthNotificationProcPtr)
        QTBandwidthNotificationUPP;
    struct QTScheduledBandwidthRecord
    {
        long recordSize; /* total number of bytes in QTScheduledBandwidthRecord*/

        long priority;
        long dataRate;
        CompTimeValue startTime; /* bandwidth usage start time*/
        CompTimeValue duration;  /* duration of bandwidth usage (0 if unknown)*/
        CompTimeValue
            prerollDuration; /* time for negotiation before startTime (0 if unknown)*/
        TimeScale scale;     /* timescale of value/duration/prerollDuration fields*/
        TimeBase base;       /* timebase*/
    };
    typedef struct QTScheduledBandwidthRecord QTScheduledBandwidthRecord;
    typedef QTScheduledBandwidthRecord *QTScheduledBandwidthPtr;
    typedef QTScheduledBandwidthPtr *QTScheduledBandwidthHandle;
    /**
     *  QTBandwidthRequest()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    OSErr
    QTBandwidthRequest(long priority, QTBandwidthNotificationUPP callback,
                       const void *refcon, QTBandwidthReference *bwRef, long flags);

    /**
     *  QTBandwidthRequestForTimeBase()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.1 and later
     *    \carbon_lib        in CarbonLib 1.1 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.1 and later
     */
    OSErr
    QTBandwidthRequestForTimeBase(TimeBase tb, long priority,
                                  QTBandwidthNotificationUPP callback,
                                  const void *refcon, QTBandwidthReference *bwRef,
                                  long flags);

    /**
     *  QTBandwidthRelease()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    OSErr
    QTBandwidthRelease(QTBandwidthReference bwRef, long flags);

    /**
     *  QTScheduledBandwidthRequest()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.1 and later
     *    \carbon_lib        in CarbonLib 1.1 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.1 and later
     */
    OSErr
    QTScheduledBandwidthRequest(QTScheduledBandwidthPtr scheduleRec,
                                QTBandwidthNotificationUPP notificationCallback,
                                void *refcon, QTScheduledBandwidthReference *sbwRef,
                                long flags);

    /**
     *  QTScheduledBandwidthRelease()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.1 and later
     *    \carbon_lib        in CarbonLib 1.1 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.1 and later
     */
    OSErr
    QTScheduledBandwidthRelease(QTScheduledBandwidthReference sbwRef, long flags);

    /*****
        QT International Text Atom Support
    *****/
    enum
    {
        kITextRemoveEverythingBut = 0 << 1,
        kITextRemoveLeaveSuggestedAlternate = 1 << 1
    };

    enum
    {
        kITextAtomType = FOUR_CHAR_CODE('itxt'),
        kITextStringAtomType = FOUR_CHAR_CODE('text')
    };

    /**
     *  ITextAddString()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    ITextAddString(QTAtomContainer container, QTAtom parentAtom,
                   RegionCode theRegionCode, ConstStr255Param theString);

    /**
     *  ITextRemoveString()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    ITextRemoveString(QTAtomContainer container, QTAtom parentAtom,
                      RegionCode theRegionCode, long flags);

    /**
     *  ITextGetString()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    ITextGetString(QTAtomContainer container, QTAtom parentAtom,
                   RegionCode requestedRegion, RegionCode *foundRegion,
                   StringPtr theString);

    /**
     *  QTTextToNativeText()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    QTTextToNativeText(Handle theText, long encoding, long flags);

    /* QTParseTextHREF inContainer atoms*/
    enum
    {
        kQTParseTextHREFText = FOUR_CHAR_CODE('text'),    /* string*/
        kQTParseTextHREFBaseURL = FOUR_CHAR_CODE('burl'), /* string*/
        kQTParseTextHREFClickPoint =
            FOUR_CHAR_CODE('clik'), /* Point; if present, QTParseTextHREF will expand
                                       URLs to support server-side image maps*/
        kQTParseTextHREFUseAltDelim = FOUR_CHAR_CODE(
            'altd'),                                        /* boolean; if no kQTParseTextHREFDelimiter, delim is ':'*/
        kQTParseTextHREFDelimiter = FOUR_CHAR_CODE('delm'), /* character*/
        kQTParseTextHREFRecomposeHREF = FOUR_CHAR_CODE(
            'rhrf') /* Boolean; if true, QTParseTextHREF returns recomposed HREF with
                       URL expanded as appropriate*/
    };

    /* QTParseTextHREF outContainer atoms*/
    enum
    {
        kQTParseTextHREFURL = FOUR_CHAR_CODE('url '),         /* string*/
        kQTParseTextHREFTarget = FOUR_CHAR_CODE('targ'),      /* string*/
        kQTParseTextHREFChapter = FOUR_CHAR_CODE('chap'),     /* string*/
        kQTParseTextHREFIsAutoHREF = FOUR_CHAR_CODE('auto'),  /* Boolean*/
        kQTParseTextHREFIsServerMap = FOUR_CHAR_CODE('smap'), /* Boolean*/
        kQTParseTextHREFHREF =
            FOUR_CHAR_CODE('href'), /* string; recomposed HREF with URL expanded as
                                       appropriate, suitable for mcActionLinkToURL*/
        kQTParseTextHREFEMBEDArgs =
            FOUR_CHAR_CODE('mbed') /* string; text between 'E<' and '>' to be used as
                                      new movie's embed tags*/
    };

    /**
     *  QTParseTextHREF()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.1 and later
     *    \carbon_lib        in CarbonLib 1.1 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.1 and later
     */
    OSErr
    QTParseTextHREF(char *href, SInt32 hrefLen, QTAtomContainer inContainer,
                    QTAtomContainer *outContainer);

    /*************************
     * track reference types
     **************************/
    enum
    {
        kTrackReferenceChapterList = FOUR_CHAR_CODE('chap'),
        kTrackReferenceTimeCode = FOUR_CHAR_CODE('tmcd'),
        kTrackReferenceModifier = FOUR_CHAR_CODE('ssrc')
    };

    /*************************
     * modifier track types
     **************************/
    enum
    {
        kTrackModifierInput = 0x696E, /* is really 'in'*/
        kTrackModifierType = 0x7479,  /* is really 'ty'*/
        kTrackModifierReference = FOUR_CHAR_CODE('ssrc'),
        kTrackModifierObjectID = FOUR_CHAR_CODE('obid'),
        kTrackModifierInputName = FOUR_CHAR_CODE('name')
    };

    enum
    {
        kInputMapSubInputID = FOUR_CHAR_CODE('subi')
    };

    enum
    {
        kTrackModifierTypeMatrix = 1,
        kTrackModifierTypeClip = 2,
        kTrackModifierTypeGraphicsMode = 5,
        kTrackModifierTypeVolume = 3,
        kTrackModifierTypeBalance = 4,
        kTrackModifierTypeImage =
            FOUR_CHAR_CODE('vide'), /* was kTrackModifierTypeSpriteImage*/
        kTrackModifierObjectMatrix = 6,
        kTrackModifierObjectGraphicsMode = 7,
        kTrackModifierType3d4x4Matrix = 8,
        kTrackModifierCameraData = 9,
        kTrackModifierSoundLocalizationData = 10,
        kTrackModifierObjectImageIndex = 11,
        kTrackModifierObjectLayer = 12,
        kTrackModifierObjectVisible = 13,
        kTrackModifierAngleAspectCamera = 14,
        kTrackModifierPanAngle = FOUR_CHAR_CODE('pan '),
        kTrackModifierTiltAngle = FOUR_CHAR_CODE('tilt'),
        kTrackModifierVerticalFieldOfViewAngle = FOUR_CHAR_CODE('fov '),
        kTrackModifierObjectQTEventSend = FOUR_CHAR_CODE('evnt')
    };

    struct ModifierTrackGraphicsModeRecord
    {
        long graphicsMode;
        RGBColor opColor;
    };
    typedef struct ModifierTrackGraphicsModeRecord ModifierTrackGraphicsModeRecord;

    /*************************
     * tween track types
     **************************/
    enum
    {
        kTweenTypeShort = 1,
        kTweenTypeLong = 2,
        kTweenTypeFixed = 3,
        kTweenTypePoint = 4,
        kTweenTypeQDRect = 5,
        kTweenTypeQDRegion = 6,
        kTweenTypeMatrix = 7,
        kTweenTypeRGBColor = 8,
        kTweenTypeGraphicsModeWithRGBColor = 9,
        kTweenTypeQTFloatSingle = 10,
        kTweenTypeQTFloatDouble = 11,
        kTweenTypeFixedPoint = 12,
        kTweenType3dScale = FOUR_CHAR_CODE('3sca'),
        kTweenType3dTranslate = FOUR_CHAR_CODE('3tra'),
        kTweenType3dRotate = FOUR_CHAR_CODE('3rot'),
        kTweenType3dRotateAboutPoint = FOUR_CHAR_CODE('3rap'),
        kTweenType3dRotateAboutAxis = FOUR_CHAR_CODE('3rax'),
        kTweenType3dRotateAboutVector = FOUR_CHAR_CODE('3rvc'),
        kTweenType3dQuaternion = FOUR_CHAR_CODE('3qua'),
        kTweenType3dMatrix = FOUR_CHAR_CODE('3mat'),
        kTweenType3dCameraData = FOUR_CHAR_CODE('3cam'),
        kTweenType3dAngleAspectCameraData = FOUR_CHAR_CODE('3caa'),
        kTweenType3dSoundLocalizationData = FOUR_CHAR_CODE('3slc'),
        kTweenTypePathToMatrixTranslation = FOUR_CHAR_CODE('gxmt'),
        kTweenTypePathToMatrixRotation = FOUR_CHAR_CODE('gxpr'),
        kTweenTypePathToMatrixTranslationAndRotation = FOUR_CHAR_CODE('gxmr'),
        kTweenTypePathToFixedPoint = FOUR_CHAR_CODE('gxfp'),
        kTweenTypePathXtoY = FOUR_CHAR_CODE('gxxy'),
        kTweenTypePathYtoX = FOUR_CHAR_CODE('gxyx'),
        kTweenTypeAtomList = FOUR_CHAR_CODE('atom'),
        kTweenTypePolygon = FOUR_CHAR_CODE('poly'),
        kTweenTypeMultiMatrix = FOUR_CHAR_CODE('mulm'),
        kTweenTypeSpin = FOUR_CHAR_CODE('spin'),
        kTweenType3dMatrixNonLinear = FOUR_CHAR_CODE('3nlr'),
        kTweenType3dVRObject = FOUR_CHAR_CODE('3vro')
    };

    enum
    {
        kTweenEntry = FOUR_CHAR_CODE('twen'),
        kTweenData = FOUR_CHAR_CODE('data'),
        kTweenType = FOUR_CHAR_CODE('twnt'),
        kTweenStartOffset = FOUR_CHAR_CODE('twst'),
        kTweenDuration = FOUR_CHAR_CODE('twdu'),
        kTweenFlags = FOUR_CHAR_CODE('flag'),
        kTweenOutputMin = FOUR_CHAR_CODE('omin'),
        kTweenOutputMax = FOUR_CHAR_CODE('omax'),
        kTweenSequenceElement = FOUR_CHAR_CODE('seqe'),
        kTween3dInitialCondition = FOUR_CHAR_CODE('icnd'),
        kTweenInterpolationID = FOUR_CHAR_CODE('intr'),
        kTweenRegionData = FOUR_CHAR_CODE('qdrg'),
        kTweenPictureData = FOUR_CHAR_CODE('PICT'),
        kListElementType = FOUR_CHAR_CODE('type'),
        kListElementDataType = FOUR_CHAR_CODE('daty'),
        kNameAtom = FOUR_CHAR_CODE('name'),
        kInitialRotationAtom = FOUR_CHAR_CODE('inro'),
        kNonLinearTweenHeader = FOUR_CHAR_CODE('nlth')
    };

    /* kTweenFlags*/
    enum
    {
        kTweenReturnDelta = 1L << 0
    };

    struct TweenSequenceEntryRecord
    {
        Fixed endPercent;
        QTAtomID tweenAtomID;
        QTAtomID dataAtomID;
    };
    typedef struct TweenSequenceEntryRecord TweenSequenceEntryRecord;

#ifdef __QD3D__

    struct ThreeDeeVRObjectSample
    {
        long rows;
        long columns;
        TQ3Matrix4x4 calib1;
        TQ3Matrix4x4 calib2;
        long reserved1;
        long reserved2;
    };

    typedef struct ThreeDeeVRObjectSample ThreeDeeVRObjectSample;

    struct ThreeDeeNonLinearSample
    {
        float DurFromLastSample; /* 0 to 1 */
        TQ3Matrix4x4 matrix;
    };
    typedef struct ThreeDeeNonLinearSample ThreeDeeNonLinearSample;

    struct ThreeDeeNonLinearTweenHeaderAtom
    {
        long number;
        long dataSize;
        float tensionFactor; /* default is 0 */
        long reserved1;
        long reserved2;
    };
    typedef struct ThreeDeeNonLinearTweenHeaderAtom
        ThreeDeeNonLinearTweenHeaderAtom;

#endif

#if OLDROUTINENAMES

    /*************************
     * Video Media routines
     **************************/

#define GetVideoMediaGraphicsMode MediaGetGraphicsMode
#define SetVideoMediaGraphicsMode MediaSetGraphicsMode

/* use these two routines at your own peril */
#define ResetVideoMediaStatistics VideoMediaResetStatistics
#define GetVideoMediaStatistics VideoMediaGetStatistics

    /*************************
     * Sound Media routines
     **************************/

#define GetSoundMediaBalance MediaGetSoundBalance
#define SetSoundMediaBalance MediaSetSoundBalance

    /*************************
     * Text Media routines
     **************************/

#define SetTextProc TextMediaSetTextProc
#define AddTextSample TextMediaAddTextSample
#define AddTESample TextMediaAddTESample
#define AddHiliteSample TextMediaAddHiliteSample
#define FindNextText TextMediaFindNextText
#define HiliteTextSample TextMediaHiliteTextSample
#define SetTextSampleData TextMediaSetTextSampleData
#define DrawRaw TextMediaDrawRaw
#define RawSetup TextMediaRawSetup
#define RawIdle TextMediaRawIdle
#define SetTextProperty TextMediaSetTextProperty

    /*************************
     * Sprite Media routines
     **************************/

#define SetSpriteMediaSpriteProperty SpriteMediaSetProperty
#define GetSpriteMediaSpriteProperty SpriteMediaGetProperty
#define HitTestSpriteMedia SpriteMediaHitTestSprites
#define CountSpriteMediaSprites SpriteMediaCountSprites
#define CountSpriteMediaImages SpriteMediaCountImages
#define GetSpriteMediaIndImageDescription SpriteMediaGetIndImageDescription
#define GetDisplayedSampleNumber SpriteMediaGetDisplayedSampleNumber
#endif /* OLDROUTINENAMES */

    /*************************
     * Video Media routines
     **************************/

    enum
    {
        videoFlagDontLeanAhead = 1L << 0
    };

    /* use these five routines at your own peril*/
    /**
     *  VideoMediaResetStatistics()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    VideoMediaResetStatistics(MediaHandler mh);

    /**
     *  VideoMediaGetStatistics()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    VideoMediaGetStatistics(MediaHandler mh);

    /**
     *  VideoMediaGetStallCount()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    VideoMediaGetStallCount(MediaHandler mh, unsigned long *stalls);

    /**
     *  VideoMediaSetCodecParameter()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    VideoMediaSetCodecParameter(MediaHandler mh, CodecType cType,
                                OSType parameterID, long parameterChangeSeed,
                                void *dataPtr, long dataSize);

    /**
     *  VideoMediaGetCodecParameter()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    VideoMediaGetCodecParameter(MediaHandler mh, CodecType cType,
                                OSType parameterID, Handle outParameterData);

    /*************************
     * Text Media routines
     **************************/

    /* Return displayFlags for TextProc */
    enum
    {
        txtProcDefaultDisplay = 0, /*    Use the media's default*/
        txtProcDontDisplay = 1,    /*    Don't display the text*/
        txtProcDoDisplay = 2       /*    Do display the text*/
    };

    /**
     *  TextMediaSetTextProc()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    TextMediaSetTextProc(MediaHandler mh, TextMediaUPP TextProc, long refcon);

    /**
     *  TextMediaAddTextSample()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    TextMediaAddTextSample(MediaHandler mh, Ptr text, unsigned long size,
                           short fontNumber, short fontSize, Style textFace,
                           RGBColor *textColor, RGBColor *backColor,
                           short textJustification, Rect *textBox,
                           long displayFlags, TimeValue scrollDelay,
                           short hiliteStart, short hiliteEnd,
                           RGBColor *rgbHiliteColor, TimeValue duration,
                           TimeValue *sampleTime);

    /**
     *  TextMediaAddTESample()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    TextMediaAddTESample(MediaHandler mh, TEHandle hTE, RGBColor *backColor,
                         short textJustification, Rect *textBox, long displayFlags,
                         TimeValue scrollDelay, short hiliteStart, short hiliteEnd,
                         RGBColor *rgbHiliteColor, TimeValue duration,
                         TimeValue *sampleTime);

    /**
     *  TextMediaAddHiliteSample()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    TextMediaAddHiliteSample(MediaHandler mh, short hiliteStart, short hiliteEnd,
                             RGBColor *rgbHiliteColor, TimeValue duration,
                             TimeValue *sampleTime);

    /**
     *  TextMediaDrawRaw()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    TextMediaDrawRaw(MediaHandler mh, GWorldPtr gw, GDHandle gd, void *data,
                     long dataSize, TextDescriptionHandle tdh);

    /**
     *  TextMediaSetTextProperty()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    TextMediaSetTextProperty(MediaHandler mh, TimeValue atMediaTime,
                             long propertyType, void *data, long dataSize);

    /**
     *  TextMediaRawSetup()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    TextMediaRawSetup(MediaHandler mh, GWorldPtr gw, GDHandle gd, void *data,
                      long dataSize, TextDescriptionHandle tdh,
                      TimeValue sampleDuration);

    /**
     *  TextMediaRawIdle()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    TextMediaRawIdle(MediaHandler mh, GWorldPtr gw, GDHandle gd,
                     TimeValue sampleTime, long flagsIn, long *flagsOut);

    /**
     *  TextMediaGetTextProperty()
     *

     *    \non_carbon_cfm   in QuickTimeLib 5.0 and later
     *    \carbon_lib        in CarbonLib 1.3 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 5.0 and later
     */
    ComponentResult
    TextMediaGetTextProperty(MediaHandler mh, TimeValue atMediaTime,
                             long propertyType, void *data, long dataSize);

    enum
    {
        findTextEdgeOK = 1 << 0,        /* Okay to find text at specified sample time*/
        findTextCaseSensitive = 1 << 1, /* Case sensitive search*/
        findTextReverseSearch = 1 << 2, /* Search from sampleTime backwards*/
        findTextWrapAround =
            1 << 3,                /* Wrap search when beginning or end of movie is hit*/
        findTextUseOffset = 1 << 4 /* Begin search at the given character offset into
                                      sample rather than edge*/
    };

    /**
     *  TextMediaFindNextText()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    TextMediaFindNextText(MediaHandler mh, Ptr text, long size, short findFlags,
                          TimeValue startTime, TimeValue *foundTime,
                          TimeValue *foundDuration, long *offset);

    /**
     *  TextMediaHiliteTextSample()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    TextMediaHiliteTextSample(MediaHandler mh, TimeValue sampleTime,
                              short hiliteStart, short hiliteEnd,
                              RGBColor *rgbHiliteColor);

    enum
    {
        dropShadowOffsetType = FOUR_CHAR_CODE('drpo'),
        dropShadowTranslucencyType = FOUR_CHAR_CODE('drpt')
    };

    /**
     *  TextMediaSetTextSampleData()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    TextMediaSetTextSampleData(MediaHandler mh, void *data, OSType dataType);

    /*************************
     * Sprite Media routines
     **************************/
    /* flags for sprite hit test routines */
    enum
    {
        spriteHitTestBounds =
            1L << 0, /*    point must only be within sprite's bounding box*/
        spriteHitTestImage =
            1L << 1, /*  point must be within the shape of the sprite's image*/
        spriteHitTestInvisibleSprites =
            1L << 2,                    /*  invisible sprites may be hit tested*/
        spriteHitTestIsClick = 1L << 3, /*  for codecs that want mouse events*/
        spriteHitTestLocInDisplayCoordinates =
            1L << 4 /*    set if you want to pass a display coordiate point to
                       SpriteHitTest*/
    };

    /* atom types for sprite media */
    enum
    {
        kSpriteAtomType = FOUR_CHAR_CODE('sprt'),
        kSpriteImagesContainerAtomType = FOUR_CHAR_CODE('imct'),
        kSpriteImageAtomType = FOUR_CHAR_CODE('imag'),
        kSpriteImageDataAtomType = FOUR_CHAR_CODE('imda'),
        kSpriteImageDataRefAtomType = FOUR_CHAR_CODE('imre'),
        kSpriteImageDataRefTypeAtomType = FOUR_CHAR_CODE('imrt'),
        kSpriteImageGroupIDAtomType = FOUR_CHAR_CODE('imgr'),
        kSpriteImageRegistrationAtomType = FOUR_CHAR_CODE('imrg'),
        kSpriteImageDefaultImageIndexAtomType = FOUR_CHAR_CODE('defi'),
        kSpriteSharedDataAtomType = FOUR_CHAR_CODE('dflt'),
        kSpriteNameAtomType = FOUR_CHAR_CODE('name'),
        kSpriteImageNameAtomType = FOUR_CHAR_CODE('name'),
        kSpriteUsesImageIDsAtomType = FOUR_CHAR_CODE(
            'uses'), /* leaf data is an array of QTAtomID's, one per image used*/
        kSpriteBehaviorsAtomType = FOUR_CHAR_CODE('beha'),
        kSpriteImageBehaviorAtomType = FOUR_CHAR_CODE('imag'),
        kSpriteCursorBehaviorAtomType = FOUR_CHAR_CODE('crsr'),
        kSpriteStatusStringsBehaviorAtomType = FOUR_CHAR_CODE('sstr'),
        kSpriteVariablesContainerAtomType = FOUR_CHAR_CODE('vars'),
        kSpriteStringVariableAtomType = FOUR_CHAR_CODE('strv'),
        kSpriteFloatingPointVariableAtomType = FOUR_CHAR_CODE('flov')
    };

    struct QTRuntimeSpriteDescStruct
    {
        long version; /* set to zero*/
        QTAtomID spriteID;
        short imageIndex;
        MatrixRecord matrix;
        short visible;
        short layer;
        ModifierTrackGraphicsModeRecord graphicsMode;
        QTAtomID actionHandlingSpriteID;
    };
    typedef struct QTRuntimeSpriteDescStruct QTRuntimeSpriteDescStruct;
    typedef QTRuntimeSpriteDescStruct *QTRuntimeSpriteDescPtr;
    /**
       when filling in QTSpriteButtonBehaviorStruct values -1 may be used to
       indicate that the state transition does not change the property
    */
    struct QTSpriteButtonBehaviorStruct
    {
        QTAtomID notOverNotPressedStateID;
        QTAtomID overNotPressedStateID;
        QTAtomID overPressedStateID;
        QTAtomID notOverPressedStateID;
    };
    typedef struct QTSpriteButtonBehaviorStruct QTSpriteButtonBehaviorStruct;
    typedef QTSpriteButtonBehaviorStruct *QTSpriteButtonBehaviorPtr;
    /**
     *  SpriteMediaSetProperty()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SpriteMediaSetProperty(MediaHandler mh, short spriteIndex, long propertyType,
                           void *propertyValue);

    /**
     *  SpriteMediaGetProperty()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SpriteMediaGetProperty(MediaHandler mh, short spriteIndex, long propertyType,
                           void *propertyValue);

    /**
     *  SpriteMediaHitTestSprites()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SpriteMediaHitTestSprites(MediaHandler mh, long flags, Point loc,
                              short *spriteHitIndex);

    /**
     *  SpriteMediaCountSprites()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SpriteMediaCountSprites(MediaHandler mh, short *numSprites);

    /**
     *  SpriteMediaCountImages()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SpriteMediaCountImages(MediaHandler mh, short *numImages);

    /**
     *  SpriteMediaGetIndImageDescription()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SpriteMediaGetIndImageDescription(MediaHandler mh, short imageIndex,
                                      ImageDescriptionHandle imageDescription);

    /**
     *  SpriteMediaGetDisplayedSampleNumber()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SpriteMediaGetDisplayedSampleNumber(MediaHandler mh, long *sampleNum);

    /**
     *  SpriteMediaGetSpriteName()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SpriteMediaGetSpriteName(MediaHandler mh, QTAtomID spriteID, Str255 spriteName);

    /**
     *  SpriteMediaGetImageName()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SpriteMediaGetImageName(MediaHandler mh, short imageIndex, Str255 imageName);

    /**
     *  SpriteMediaSetSpriteProperty()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SpriteMediaSetSpriteProperty(MediaHandler mh, QTAtomID spriteID,
                                 long propertyType, void *propertyValue);

    /**
     *  SpriteMediaGetSpriteProperty()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SpriteMediaGetSpriteProperty(MediaHandler mh, QTAtomID spriteID,
                                 long propertyType, void *propertyValue);

    /**
     *  SpriteMediaHitTestAllSprites()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SpriteMediaHitTestAllSprites(MediaHandler mh, long flags, Point loc,
                                 QTAtomID *spriteHitID);

    /**
     *  SpriteMediaHitTestOneSprite()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SpriteMediaHitTestOneSprite(MediaHandler mh, QTAtomID spriteID, long flags,
                                Point loc, Boolean *wasHit);

    /**
     *  SpriteMediaSpriteIndexToID()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SpriteMediaSpriteIndexToID(MediaHandler mh, short spriteIndex,
                               QTAtomID *spriteID);

    /**
     *  SpriteMediaSpriteIDToIndex()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SpriteMediaSpriteIDToIndex(MediaHandler mh, QTAtomID spriteID,
                               short *spriteIndex);

    /**
     *  SpriteMediaGetSpriteActionsForQTEvent()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SpriteMediaGetSpriteActionsForQTEvent(MediaHandler mh, QTEventRecordPtr event,
                                          QTAtomID spriteID,
                                          QTAtomContainer *container, QTAtom *atom);

    /**
     *  SpriteMediaSetActionVariable()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SpriteMediaSetActionVariable(MediaHandler mh, QTAtomID variableID,
                                 const float *value);

    /**
     *  SpriteMediaGetActionVariable()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SpriteMediaGetActionVariable(MediaHandler mh, QTAtomID variableID, float *value);

    /**
     *  SpriteMediaGetIndImageProperty()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.1 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SpriteMediaGetIndImageProperty(MediaHandler mh, short imageIndex,
                                   long imagePropertyType, void *imagePropertyValue);

    /**
     *  SpriteMediaNewSprite()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    SpriteMediaNewSprite(MediaHandler mh, QTRuntimeSpriteDescPtr newSpriteDesc);

    /**
     *  SpriteMediaDisposeSprite()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    SpriteMediaDisposeSprite(MediaHandler mh, QTAtomID spriteID);

    /**
     *  SpriteMediaSetActionVariableToString()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    SpriteMediaSetActionVariableToString(MediaHandler mh, QTAtomID variableID,
                                         Ptr theCString);

    /**
     *  SpriteMediaGetActionVariableAsString()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    SpriteMediaGetActionVariableAsString(MediaHandler mh, QTAtomID variableID,
                                         Handle *theCString);

    /*************************
     * Flash Media routines
     **************************/

    /**
     *  FlashMediaSetPan()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    FlashMediaSetPan(MediaHandler mh, short xPercent, short yPercent);

    /**
     *  FlashMediaSetZoom()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    FlashMediaSetZoom(MediaHandler mh, short factor);

    /**
     *  FlashMediaSetZoomRect()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    FlashMediaSetZoomRect(MediaHandler mh, long left, long top, long right,
                          long bottom);

    /**
     *  FlashMediaGetRefConBounds()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    FlashMediaGetRefConBounds(MediaHandler mh, long refCon, long *left, long *top,
                              long *right, long *bottom);

    /**
     *  FlashMediaGetRefConID()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    FlashMediaGetRefConID(MediaHandler mh, long refCon, long *refConID);

    /**
     *  FlashMediaIDToRefCon()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    FlashMediaIDToRefCon(MediaHandler mh, long refConID, long *refCon);

    /**
     *  FlashMediaGetDisplayedFrameNumber()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    FlashMediaGetDisplayedFrameNumber(MediaHandler mh, long *flashFrameNumber);

    /**
     *  FlashMediaFrameNumberToMovieTime()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    FlashMediaFrameNumberToMovieTime(MediaHandler mh, long flashFrameNumber,
                                     TimeValue *movieTime);

    /**
     *  FlashMediaFrameLabelToMovieTime()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    FlashMediaFrameLabelToMovieTime(MediaHandler mh, Ptr theLabel,
                                    TimeValue *movieTime);

    /**
     *  FlashMediaGetFlashVariable()
     *

     *    \non_carbon_cfm   in QuickTimeLib 5.0 and later
     *    \carbon_lib        in CarbonLib 1.3 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 5.0 and later
     */
    ComponentResult
    FlashMediaGetFlashVariable(MediaHandler mh, char *path, char *name,
                               Handle *theVariableCStringOut);

    /**
     *  FlashMediaSetFlashVariable()
     *

     *    \non_carbon_cfm   in QuickTimeLib 5.0 and later
     *    \carbon_lib        in CarbonLib 1.3 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 5.0 and later
     */
    ComponentResult
    FlashMediaSetFlashVariable(MediaHandler mh, char *path, char *name, char *value,
                               Boolean updateFocus);

    /**
     *  FlashMediaDoButtonActions()
     *

     *    \non_carbon_cfm   in QuickTimeLib 5.0 and later
     *    \carbon_lib        in CarbonLib 1.3 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 5.0 and later
     */
    ComponentResult
    FlashMediaDoButtonActions(MediaHandler mh, char *path, long buttonID,
                              long transition);

    /**
     *  FlashMediaGetSupportedSwfVersion()
     *

     *    \non_carbon_cfm   in QuickTimeLib 5.0 and later
     *    \carbon_lib        in CarbonLib 1.3 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 5.0 and later
     */
    ComponentResult
    FlashMediaGetSupportedSwfVersion(MediaHandler mh, unsigned char *swfVersion);

    /* sample format atoms*/
    enum
    {
        kMovieMediaDataReference = FOUR_CHAR_CODE('mmdr'),          /* data reference*/
        kMovieMediaDefaultDataReferenceID = FOUR_CHAR_CODE('ddri'), /* atom id*/
        kMovieMediaSlaveTime = FOUR_CHAR_CODE('slti'),              /* boolean*/
        kMovieMediaSlaveAudio = FOUR_CHAR_CODE('slau'),             /* boolean*/
        kMovieMediaSlaveGraphicsMode = FOUR_CHAR_CODE('slgr'),      /* boolean*/
        kMovieMediaAutoPlay = FOUR_CHAR_CODE('play'),               /* boolean*/
        kMovieMediaLoop =
            FOUR_CHAR_CODE('loop'), /* UInt8 (0=no loop, 1=loop, 2=palindrome loop)*/
        kMovieMediaUseMIMEType =
            FOUR_CHAR_CODE('mime'), /* string indicating the MIME type to use for the
                                       dataref (usually not required)*/
        kMovieMediaTitle =
            FOUR_CHAR_CODE('titl'), /* string of the media's title (tooltips)*/
        kMovieMediaAltText = FOUR_CHAR_CODE(
            'altt'), /* string of alternate text if media isn't loaded*/
        kMovieMediaClipBegin = FOUR_CHAR_CODE(
            'clpb'), /* MovieMediaTimeRecord of start time of embedded media*/
        kMovieMediaClipDuration = FOUR_CHAR_CODE(
            'clpd'), /* MovieMediaTimeRecord of duration of embedded media*/
        kMovieMediaRegionAtom =
            FOUR_CHAR_CODE('regi'), /* contains subatoms that describe layout*/
        kMovieMediaSlaveTrackDuration = FOUR_CHAR_CODE(
            'sltr'), /* Boolean indicating that media handler should adjust track and
                        media based on actual embedded movie duration*/
        kMovieMediaEnableFrameStepping =
            FOUR_CHAR_CODE('enfs'),                          /* boolean. if true stepping on external movie
                                                                steps frames within embedded movie.*/
        kMovieMediaBackgroundColor = FOUR_CHAR_CODE('bkcl'), /* RGBColor.*/
        kMovieMediaPrerollTime =
            FOUR_CHAR_CODE('prer') /* SInt32 indicating preroll time*/
    };

    /* fit types*/
    enum
    {
        kMovieMediaFitNone = 0,
        kMovieMediaFitScroll = FOUR_CHAR_CODE('scro'),
        kMovieMediaFitClipIfNecessary = FOUR_CHAR_CODE('hidd'),
        kMovieMediaFitFill = FOUR_CHAR_CODE('fill'),
        kMovieMediaFitMeet = FOUR_CHAR_CODE('meet'),
        kMovieMediaFitSlice = FOUR_CHAR_CODE('slic')
    };

    /* sub atoms for region atom*/
    enum
    {
        kMovieMediaSpatialAdjustment =
            FOUR_CHAR_CODE('fit '), /* OSType from kMovieMediaFit**/
        kMovieMediaRectangleAtom = FOUR_CHAR_CODE('rect'),
        kMovieMediaTop = FOUR_CHAR_CODE('top '),
        kMovieMediaLeft = FOUR_CHAR_CODE('left'),
        kMovieMediaWidth = FOUR_CHAR_CODE('wd  '),
        kMovieMediaHeight = FOUR_CHAR_CODE('ht  ')
    };

    /* contained movie properties*/
    enum
    {
        kMoviePropertyDuration = FOUR_CHAR_CODE('dura'),      /* TimeValue **/
        kMoviePropertyTimeScale = FOUR_CHAR_CODE('tims'),     /* TimeValue **/
        kMoviePropertyTime = FOUR_CHAR_CODE('timv'),          /* TimeValue **/
        kMoviePropertyNaturalBounds = FOUR_CHAR_CODE('natb'), /* Rect **/
        kMoviePropertyMatrix = FOUR_CHAR_CODE('mtrx'),        /* Matrix **/
        kMoviePropertyTrackList = FOUR_CHAR_CODE('tlst')      /* long ****/
    };

    enum
    {
        kTrackPropertyMediaType = FOUR_CHAR_CODE('mtyp'), /* OSType*/
        kTrackPropertyInstantiation =
            FOUR_CHAR_CODE('inst') /* MovieMediaInstantiationInfoRecord*/
    };

    struct MovieMediaTimeRecord
    {
        wide time;
        TimeScale scale;
    };
    typedef struct MovieMediaTimeRecord MovieMediaTimeRecord;
    struct MovieMediaInstantiationInfoRecord
    {
        Boolean immediately;
        Boolean pad;
        SInt32 bitRate;
    };
    typedef struct MovieMediaInstantiationInfoRecord
        MovieMediaInstantiationInfoRecord;
    /*************************
     * Movie Media routines
     **************************/

    /**
     *  MovieMediaGetChildDoMCActionCallback()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.1 and later
     *    \carbon_lib        in CarbonLib 1.1 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.1 and later
     */
    ComponentResult
    MovieMediaGetChildDoMCActionCallback(MediaHandler mh,
                                         DoMCActionUPP *doMCActionCallbackProc,
                                         long *refcon);

    /**
     *  MovieMediaGetDoMCActionCallback()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.1 and later
     *    \carbon_lib        in CarbonLib 1.1 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.1 and later
     */
    ComponentResult
    MovieMediaGetDoMCActionCallback(MediaHandler mh,
                                    DoMCActionUPP *doMCActionCallbackProc,
                                    long *refcon);

    /**
     *  MovieMediaGetCurrentMovieProperty()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.1 and later
     *    \carbon_lib        in CarbonLib 1.1 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.1 and later
     */
    ComponentResult
    MovieMediaGetCurrentMovieProperty(MediaHandler mh, OSType whichProperty,
                                      void *value);

    /**
     *  MovieMediaGetCurrentTrackProperty()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.1 and later
     *    \carbon_lib        in CarbonLib 1.1 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.1 and later
     */
    ComponentResult
    MovieMediaGetCurrentTrackProperty(MediaHandler mh, long trackID,
                                      OSType whichProperty, void *value);

    /**
     *  MovieMediaGetChildMovieDataReference()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.1 and later
     *    \carbon_lib        in CarbonLib 1.1 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.1 and later
     */
    ComponentResult
    MovieMediaGetChildMovieDataReference(MediaHandler mh, QTAtomID dataRefID,
                                         short dataRefIndex, OSType *dataRefType,
                                         Handle *dataRef, QTAtomID *dataRefIDOut,
                                         short *dataRefIndexOut);

    /**
     *  MovieMediaSetChildMovieDataReference()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.1 and later
     *    \carbon_lib        in CarbonLib 1.1 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.1 and later
     */
    ComponentResult
    MovieMediaSetChildMovieDataReference(MediaHandler mh, QTAtomID dataRefID,
                                         OSType dataRefType, Handle dataRef);

    /**
     *  MovieMediaLoadChildMovieFromDataReference()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.1 and later
     *    \carbon_lib        in CarbonLib 1.1 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.1 and later
     */
    ComponentResult
    MovieMediaLoadChildMovieFromDataReference(MediaHandler mh, QTAtomID dataRefID);

    /*************************
     * 3D Media routines
     **************************/
    /**
     *  Media3DGetNamedObjectList()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    Media3DGetNamedObjectList(MediaHandler mh, QTAtomContainer *objectList);

    /**
     *  Media3DGetRendererList()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    Media3DGetRendererList(MediaHandler mh, QTAtomContainer *rendererList);

    /**
     *  Media3DGetCurrentGroup()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    Media3DGetCurrentGroup(MediaHandler mh, void *group);

    /**
     *  Media3DTranslateNamedObjectTo()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    Media3DTranslateNamedObjectTo(MediaHandler mh, char *objectName, Fixed x,
                                  Fixed y, Fixed z);

    /**
     *  Media3DScaleNamedObjectTo()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    Media3DScaleNamedObjectTo(MediaHandler mh, char *objectName, Fixed xScale,
                              Fixed yScale, Fixed zScale);

    /**
     *  Media3DRotateNamedObjectTo()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    Media3DRotateNamedObjectTo(MediaHandler mh, char *objectName, Fixed xDegrees,
                               Fixed yDegrees, Fixed zDegrees);

    /**
     *  Media3DSetCameraData()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    Media3DSetCameraData(MediaHandler mh, void *cameraData);

    /**
     *  Media3DGetCameraData()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    Media3DGetCameraData(MediaHandler mh, void *cameraData);

    /**
     *  Media3DSetCameraAngleAspect()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    Media3DSetCameraAngleAspect(MediaHandler mh, QTFloatSingle fov,
                                QTFloatSingle aspectRatioXToY);

    /**
     *  Media3DGetCameraAngleAspect()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    Media3DGetCameraAngleAspect(MediaHandler mh, QTFloatSingle *fov,
                                QTFloatSingle *aspectRatioXToY);

    /**
     *  Media3DSetCameraRange()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    Media3DSetCameraRange(MediaHandler mh, void *tQ3CameraRange);

    /**
     *  Media3DGetCameraRange()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    Media3DGetCameraRange(MediaHandler mh, void *tQ3CameraRange);

    /**
     *  Media3DGetViewObject()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.1 and later
     *    \carbon_lib        in CarbonLib 1.1 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.1 and later
     */
    ComponentResult
    Media3DGetViewObject(MediaHandler mh, void *tq3viewObject);

    /****************************************
     *                                       *
     *   M O V I E   C O N T R O L L E R     *
     *                                       *
     ****************************************/
    enum
    {
        MovieControllerComponentType = FOUR_CHAR_CODE('play')
    };

    enum
    {
        kMovieControllerQTVRFlag = 1 << 0,
        kMovieControllerDontDisplayToUser = 1 << 1
    };

    typedef ComponentInstance MovieController;
    typedef MovieController *MovieControllerPtr;
    enum
    {
        mcActionIdle = 1,                   /* no param*/
        mcActionDraw = 2,                   /* param is WindowRef*/
        mcActionActivate = 3,               /* no param*/
        mcActionDeactivate = 4,             /* no param*/
        mcActionMouseDown = 5,              /* param is pointer to EventRecord*/
        mcActionKey = 6,                    /* param is pointer to EventRecord*/
        mcActionPlay = 8,                   /* param is Fixed, play rate*/
        mcActionGoToTime = 12,              /* param is TimeRecord*/
        mcActionSetVolume = 14,             /* param is a short*/
        mcActionGetVolume = 15,             /* param is pointer to a short*/
        mcActionStep = 18,                  /* param is number of steps (short)*/
        mcActionSetLooping = 21,            /* param is Boolean*/
        mcActionGetLooping = 22,            /* param is pointer to a Boolean*/
        mcActionSetLoopIsPalindrome = 23,   /* param is Boolean*/
        mcActionGetLoopIsPalindrome = 24,   /* param is pointer to a Boolean*/
        mcActionSetGrowBoxBounds = 25,      /* param is a Rect*/
        mcActionControllerSizeChanged = 26, /* no param*/
        mcActionSetSelectionBegin = 29,     /* param is TimeRecord*/
        mcActionSetSelectionDuration =
            30,                         /* param is TimeRecord, action only taken on set-duration*/
        mcActionSetKeysEnabled = 32,    /* param is Boolean*/
        mcActionGetKeysEnabled = 33,    /* param is pointer to Boolean*/
        mcActionSetPlaySelection = 34,  /* param is Boolean*/
        mcActionGetPlaySelection = 35,  /* param is pointer to Boolean*/
        mcActionSetUseBadge = 36,       /* param is Boolean*/
        mcActionGetUseBadge = 37,       /* param is pointer to Boolean*/
        mcActionSetFlags = 38,          /* param is long of flags*/
        mcActionGetFlags = 39,          /* param is pointer to a long of flags*/
        mcActionSetPlayEveryFrame = 40, /* param is Boolean*/
        mcActionGetPlayEveryFrame = 41, /* param is pointer to Boolean*/
        mcActionGetPlayRate = 42,       /* param is pointer to Fixed*/
        mcActionShowBalloon =
            43, /* param is a pointer to a boolean. set to false to stop balloon*/
        mcActionBadgeClick =
            44,                                /* param is pointer to Boolean. set to false to ignore click*/
        mcActionMovieClick = 45,               /* param is pointer to event record. change "what" to
                                                  nullEvt to kill click*/
        mcActionSuspend = 46,                  /* no param*/
        mcActionResume = 47,                   /* no param*/
        mcActionSetControllerKeysEnabled = 48, /* param is Boolean*/
        mcActionGetTimeSliderRect = 49,        /* param is pointer to rect*/
        mcActionMovieEdited = 50,              /* no param*/
        mcActionGetDragEnabled = 51,           /* param is pointer to Boolean*/
        mcActionSetDragEnabled = 52,           /* param is Boolean*/
        mcActionGetSelectionBegin = 53,        /* param is TimeRecord*/
        mcActionGetSelectionDuration = 54,     /* param is TimeRecord*/
        mcActionPrerollAndPlay = 55,           /* param is Fixed, play rate*/
        mcActionGetCursorSettingEnabled = 56,  /* param is pointer to Boolean*/
        mcActionSetCursorSettingEnabled = 57,  /* param is Boolean*/
        mcActionSetColorTable = 58,            /* param is CTabHandle*/
        mcActionLinkToURL = 59,                /* param is Handle to URL*/
        mcActionCustomButtonClick = 60,        /* param is pointer to EventRecord*/
        mcActionForceTimeTableUpdate = 61,     /* no param*/
        mcActionSetControllerTimeLimits =
            62,                                   /* param is pointer to 2 time values min/max. do no send this message
                                                     to controller. used internally only.*/
        mcActionExecuteAllActionsForQTEvent = 63, /* param is ResolvedQTEventSpecPtr*/
        mcActionExecuteOneActionForQTEvent = 64,  /* param is ResolvedQTEventSpecPtr*/
        mcActionAdjustCursor = 65,                /* param is pointer to EventRecord (WindowRef is in
                                                     message parameter)*/
        mcActionUseTrackForTimeTable =
            66, /* param is pointer to {long trackID; Boolean useIt}. do not send this
                   message to controller. */
        mcActionClickAndHoldPoint =
            67,                          /* param is point (local coordinates). return true if point has click
                                            & hold action (e.g., VR object movie autorotate spot)*/
        mcActionShowMessageString = 68,  /* param is a StringPtr*/
        mcActionShowStatusString = 69,   /* param is a QTStatusStringPtr*/
        mcActionGetExternalMovie = 70,   /* param is a QTGetExternalMoviePtr*/
        mcActionGetChapterTime = 71,     /* param is a QTGetChapterTimePtr*/
        mcActionPerformActionList = 72,  /* param is a QTAtomSpecPtr*/
        mcActionEvaluateExpression = 73, /* param is a QTEvaluateExpressionPtr*/
        mcActionFetchParameterAs = 74,   /* param is a QTFetchParameterAsPtr*/
        mcActionGetCursorByID = 75,      /* param is a QTGetCursorByIDPtr*/
        mcActionGetNextURL = 76,         /* param is a Handle to URL*/
        mcActionMovieChanged = 77,
        mcActionDoScript = 78,      /* param is QTDoScriptPtr*/
        mcActionRestartAtTime = 79, /* param is QTResartAtTimePtr*/
        mcActionGetIndChapter = 80, /* param is QTChapterInfoPtr*/
        mcActionLinkToURLExtended =
            81,                          /* param is QTAtomContainer as used by QTParseHREF*/
        mcActionSetVolumeStep = 82,      /* param is short containing amount to step volume
                                            via arrow keys - default = 64*/
        mcActionAutoPlay = 83,           /* param is Fixed, play rate*/
        mcActionPauseToBuffer = 84,      /* param is Fixed, play rate on restart*/
        mcActionAppMessageReceived = 85, /* param is a long, application message*/
        mcActionEvaluateExpressionWithType =
            89,                     /* param is a QTEvaluateExpressionWithTypePtr*/
        mcActionGetMovieName = 90,  /* param is a p String Handle*/
        mcActionGetMovieID = 91,    /* param is pointer to long*/
        mcActionGetMovieActive = 92 /* param is pointer to Boolean*/
    };

    typedef short mcAction;
    enum
    {
        mcFlagSuppressMovieFrame = 1 << 0,
        mcFlagSuppressStepButtons = 1 << 1,
        mcFlagSuppressSpeakerButton = 1 << 2,
        mcFlagsUseWindowPalette = 1 << 3,
        mcFlagsDontInvalidate = 1 << 4,
        mcFlagsUseCustomButton = 1 << 5
    };

    enum
    {
        mcPositionDontInvalidate = 1 << 5
    };

    typedef unsigned long mcFlags;
    enum
    {
        kMCIEEnabledButtonPicture = 1,
        kMCIEDisabledButtonPicture = 2,
        kMCIEDepressedButtonPicture = 3,
        kMCIEEnabledSizeBoxPicture = 4,
        kMCIEDisabledSizeBoxPicture = 5,
        kMCIEEnabledUnavailableButtonPicture = 6,
        kMCIEDisabledUnavailableButtonPicture = 7,
        kMCIESoundSlider = 128,
        kMCIESoundThumb = 129,
        kMCIEColorTable = 256,
        kMCIEIsFlatAppearance = 257,
        kMCIEDoButtonIconsDropOnDepress = 258
    };

    typedef unsigned long MCInterfaceElement;
    typedef CALLBACK_API(Boolean, MCActionFilterProcPtr)(MovieController mc,
                                                         short *action,
                                                         void *params);
    typedef CALLBACK_API(Boolean, MCActionFilterWithRefConProcPtr)(
        MovieController mc, short action, void *params, long refCon);
    typedef STACK_UPP_TYPE(MCActionFilterProcPtr) MCActionFilterUPP;
    typedef STACK_UPP_TYPE(MCActionFilterWithRefConProcPtr)
        MCActionFilterWithRefConUPP;
    /**
        menu related stuff
    */
    enum
    {
        mcInfoUndoAvailable = 1 << 0,
        mcInfoCutAvailable = 1 << 1,
        mcInfoCopyAvailable = 1 << 2,
        mcInfoPasteAvailable = 1 << 3,
        mcInfoClearAvailable = 1 << 4,
        mcInfoHasSound = 1 << 5,
        mcInfoIsPlaying = 1 << 6,
        mcInfoIsLooping = 1 << 7,
        mcInfoIsInPalindrome = 1 << 8,
        mcInfoEditingEnabled = 1 << 9,
        mcInfoMovieIsInteractive = 1 << 10
    };

    /* menu item codes*/
    enum
    {
        mcMenuUndo = 1,
        mcMenuCut = 3,
        mcMenuCopy = 4,
        mcMenuPaste = 5,
        mcMenuClear = 6
    };

    /* messages to the application via mcActionAppMessageReceived*/
    enum
    {
        kQTAppMessageSoftwareChanged = 1, /* notification to app that installed
                                             QuickTime software has been updated*/
        kQTAppMessageWindowCloseRequested =
            3, /* request for app to close window containing movie controller*/
        kQTAppMessageExitFullScreenRequested =
            4, /* request for app to turn off full screen mode if active*/
        kQTAppMessageDisplayChannels =
            5, /* request for app to display the channel UI*/
        kQTAppMessageEnterFullScreenRequested =
            6 /* request for app to turn on full screen mode*/
    };

    /* structures used as mcActionFilterProc params*/
    struct QTStatusStringRecord
    {
        long stringTypeFlags;
        char *statusString;
    };
    typedef struct QTStatusStringRecord QTStatusStringRecord;
    typedef QTStatusStringRecord *QTStatusStringPtr;
    struct QTGetExternalMovieRecord
    {
        long targetType; /* set to kTargetMovieName or kTargetMovieID*/
        StringPtr movieName;
        long movieID;
        MoviePtr theMovie;
        MovieControllerPtr theController;
    };
    typedef struct QTGetExternalMovieRecord QTGetExternalMovieRecord;
    typedef QTGetExternalMovieRecord *QTGetExternalMoviePtr;
    struct QTGetChapterTimeRecord
    {
        StringPtr chapterName;
        TimeRecord chapterTime;
    };
    typedef struct QTGetChapterTimeRecord QTGetChapterTimeRecord;
    typedef QTGetChapterTimeRecord *QTGetChapterTimePtr;
    struct QTChapterInfoRecord
    {
        long index;     /* first chapter has index of 1*/
        TimeValue time; /* -1 if no more chapters available*/
        Str255 name;
    };
    typedef struct QTChapterInfoRecord QTChapterInfoRecord;
    typedef QTChapterInfoRecord *QTChapterInfoPtr;
    struct QTEvaluateExpressionRecord
    {
        QTAtomSpec expressionSpec;
        float *expressionResult;
    };
    typedef struct QTEvaluateExpressionRecord QTEvaluateExpressionRecord;
    typedef QTEvaluateExpressionRecord *QTEvaluateExpressionPtr;
    struct QTEvaluateExpressionWithTypeRecord
    {
        long recordSize; /* Size of structure (fill in at allocation) */
        QTAtomSpec expressionSpec;
        float *expressionResult;
        long fetchAsType;
        Handle nonNumericResult;
        /* Current size is 24 */
    };
    typedef struct QTEvaluateExpressionWithTypeRecord
        QTEvaluateExpressionWithTypeRecord;
    typedef QTEvaluateExpressionWithTypeRecord *QTEvaluateExpressionWithTypePtr;
    struct QTFetchParameterAsRecord
    {
        QTAtomSpec paramListSpec;
        long paramIndex;
        long paramType;
        long allowedFlags;
        void *min;
        void *max;
        void *currentValue;
        void *newValue;
        Boolean isUnsignedValue;
    };
    typedef struct QTFetchParameterAsRecord QTFetchParameterAsRecord;
    typedef QTFetchParameterAsRecord *QTFetchParameterAsPtr;
    struct QTGetCursorByIDRecord
    {
        short cursorID;
        Handle colorCursorData;
        long reserved1;
    };
    typedef struct QTGetCursorByIDRecord QTGetCursorByIDRecord;
    typedef QTGetCursorByIDRecord *QTGetCursorByIDPtr;
    struct QTDoScriptRecord
    {
        long scriptTypeFlags;
        char *command;
        char *arguments;
    };
    typedef struct QTDoScriptRecord QTDoScriptRecord;
    typedef QTDoScriptRecord *QTDoScriptPtr;
    struct QTRestartAtTimeRecord
    {
        TimeValue startTime; /* time scale is the movie timescale*/
        Fixed rate;          /* if rate is zero, the movie's current rate is maintained*/
    };
    typedef struct QTRestartAtTimeRecord QTRestartAtTimeRecord;
    typedef QTRestartAtTimeRecord *QTRestartAtTimePtr;
    /* values for paramType field of QTFetchParameterAsRecord*/
    enum
    {
        kFetchAsBooleanPtr = 1,
        kFetchAsShortPtr = 2,
        kFetchAsLongPtr = 3,
        kFetchAsMatrixRecordPtr = 4,
        kFetchAsModifierTrackGraphicsModeRecord = 5,
        kFetchAsHandle = 6,
        kFetchAsStr255 = 7,
        kFetchAsFloatPtr = 8,
        kFetchAsPointPtr = 9,
        kFetchAsNewAtomContainer = 10,
        kFetchAsQTEventRecordPtr = 11,
        kFetchAsFixedPtr = 12,
        kFetchAsSetControllerValuePtr = 13,
        kFetchAsRgnHandle = 14, /* flipped to native*/
        kFetchAsComponentDescriptionPtr = 15,
        kFetchAsCString = 16
    };

    enum
    {
        kQTCursorOpenHand = -19183,
        kQTCursorClosedHand = -19182,
        kQTCursorPointingHand = -19181,
        kQTCursorRightArrow = -19180,
        kQTCursorLeftArrow = -19179,
        kQTCursorDownArrow = -19178,
        kQTCursorUpArrow = -19177,
        kQTCursorIBeam = -19176
    };

    /* target management */
    /**
     *  MCSetMovie()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MCSetMovie(MovieController mc, Movie theMovie, WindowRef movieWindow,
               Point where);

    /**
     *  MCGetIndMovie()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    Movie
    MCGetIndMovie(MovieController mc, short index);

#define MCGetMovie(mc) MCGetIndMovie(mc, 0)
    /**
     *  MCRemoveAllMovies()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MCRemoveAllMovies(MovieController mc);

    /**
     *  MCRemoveAMovie()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MCRemoveAMovie(MovieController mc, Movie m);

    /**
     *  MCRemoveMovie()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MCRemoveMovie(MovieController mc);

    /* event handling etc. */
    /**
     *  MCIsPlayerEvent()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MCIsPlayerEvent(MovieController mc, const EventRecord *e);

    /* obsolete. use MCSetActionFilterWithRefCon instead. */
    /**
     *  MCSetActionFilter()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MCSetActionFilter(MovieController mc, MCActionFilterUPP blob);

    /**
        proc is of the form:
            Boolean userPlayerFilter(MovieController mc, short *action, void
       *params) = proc returns TRUE if it handles the action, FALSE if not action is
       passed as a VAR so that it could be changed by filter this is consistent with
       the current dialog manager stuff params is any potential parameters that go
       with the action such as set playback rate to xxx.
    */
    /**
     *  MCDoAction()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MCDoAction(MovieController mc, short action, void *params);

    /* state type things */
    /**
     *  MCSetControllerAttached()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MCSetControllerAttached(MovieController mc, Boolean attach);

    /**
     *  MCIsControllerAttached()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MCIsControllerAttached(MovieController mc);

    /**
     *  MCSetControllerPort()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MCSetControllerPort(MovieController mc, CGrafPtr gp);

    /**
     *  MCGetControllerPort()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    CGrafPtr
    MCGetControllerPort(MovieController mc);

    /**
     *  MCSetVisible()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MCSetVisible(MovieController mc, Boolean visible);

    /**
     *  MCGetVisible()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MCGetVisible(MovieController mc);

    /**
     *  MCGetControllerBoundsRect()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MCGetControllerBoundsRect(MovieController mc, Rect *bounds);

    /**
     *  MCSetControllerBoundsRect()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MCSetControllerBoundsRect(MovieController mc, const Rect *bounds);

    /**
     *  MCGetControllerBoundsRgn()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    RgnHandle
    MCGetControllerBoundsRgn(MovieController mc);

    /**
     *  MCGetWindowRgn()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    RgnHandle
    MCGetWindowRgn(MovieController mc, WindowRef w);

    /* other stuff */
    /**
     *  MCMovieChanged()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MCMovieChanged(MovieController mc, Movie m);

    /**
        called when the app has changed thing about the movie (like bounding rect)
       or rate. So that we can update our graphical (and internal) state
       accordingly.
    */
    /**
     *  MCSetDuration()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MCSetDuration(MovieController mc, TimeValue duration);

    /**
        duration to use for time slider -- will be reset next time MCMovieChanged is
       called or MCSetMovie is called
    */
    /**
     *  MCGetCurrentTime()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    TimeValue
    MCGetCurrentTime(MovieController mc, TimeScale *scale);

    /**
        returns the time value and the time scale it is on. if there are no movies,
       the time scale is passed back as 0. scale is an optional parameter

    */
    /**
     *  MCNewAttachedController()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MCNewAttachedController(MovieController mc, Movie theMovie, WindowRef w,
                            Point where);

    /**
        makes theMovie the only movie attached to the controller. makes the
       controller visible. the window and where parameters are passed a long to
       MCSetMovie and behave as described there
    */
    /**
     *  MCDraw()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MCDraw(MovieController mc, WindowRef w);

    /**
     *  MCActivate()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MCActivate(MovieController mc, WindowRef w, Boolean activate);

    /**
     *  MCIdle()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MCIdle(MovieController mc);

    /**
     *  MCKey()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MCKey(MovieController mc, SInt8 key, long modifiers);

    /**
     *  MCClick()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MCClick(MovieController mc, WindowRef w, Point where, long when, long modifiers);

    /**
        calls for editing
    */
    /**
     *  MCEnableEditing()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MCEnableEditing(MovieController mc, Boolean enabled);

    /**
     *  MCIsEditingEnabled()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    long
    MCIsEditingEnabled(MovieController mc);

    /**
     *  MCCopy()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    Movie
    MCCopy(MovieController mc);

    /**
     *  MCCut()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    Movie
    MCCut(MovieController mc);

    /**
     *  MCPaste()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MCPaste(MovieController mc, Movie srcMovie);

    /**
     *  MCClear()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MCClear(MovieController mc);

    /**
     *  MCUndo()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MCUndo(MovieController mc);

    /**
     *  somewhat special stuff
     */
    /**
     *  MCPositionController()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MCPositionController(MovieController mc, const Rect *movieRect,
                         const Rect *controllerRect, long someFlags);

    /**
     *  MCGetControllerInfo()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MCGetControllerInfo(MovieController mc, long *someFlags);

    /**
     *  MCSetClip()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MCSetClip(MovieController mc, RgnHandle theClip, RgnHandle movieClip);

    /**
     *  MCGetClip()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MCGetClip(MovieController mc, RgnHandle *theClip, RgnHandle *movieClip);

    /**
     *  MCDrawBadge()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MCDrawBadge(MovieController mc, RgnHandle movieRgn, RgnHandle *badgeRgn);

    /**
     *  MCSetUpEditMenu()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MCSetUpEditMenu(MovieController mc, long modifiers, MenuRef mh);

    /**
     *  MCGetMenuString()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MCGetMenuString(MovieController mc, long modifiers, short item, Str255 aString);

    /**
     *  MCSetActionFilterWithRefCon()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MCSetActionFilterWithRefCon(MovieController mc,
                                MCActionFilterWithRefConUPP blob, long refCon);

    /**
     *  MCPtInController()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MCPtInController(MovieController mc, Point thePt, Boolean *inController);

    /**
     *  MCInvalidate()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MCInvalidate(MovieController mc, WindowRef w, RgnHandle invalidRgn);

    /**
     *  MCAdjustCursor()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MCAdjustCursor(MovieController mc, WindowRef w, Point where, long modifiers);

    /**
     *  MCGetInterfaceElement()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MCGetInterfaceElement(MovieController mc, MCInterfaceElement whichElement,
                          void *element);

    /**
     *  MCGetDoActionsProc()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    MCGetDoActionsProc(MovieController mc, DoMCActionUPP *doMCActionProc,
                       long *doMCActionRefCon);

    /**
     *  MCAddMovieSegment()
     *

     *    \non_carbon_cfm   in QuickTimeLib 5.0 and later
     *    \carbon_lib        in CarbonLib 1.3 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 5.0 and later
     */
    ComponentResult
    MCAddMovieSegment(MovieController mc, Movie srcMovie, Boolean scaled);

    /**
     *  MCTrimMovieSegment()
     *

     *    \non_carbon_cfm   in QuickTimeLib 5.0 and later
     *    \carbon_lib        in CarbonLib 1.3 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 5.0 and later
     */
    ComponentResult
    MCTrimMovieSegment(MovieController mc);

    /****************************************
     *                                       *
     *       T  I  M  E  B  A  S  E          *
     *                                       *
     ****************************************/
    /**
     *  NewTimeBase()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    TimeBase
    NewTimeBase(void);

    /**
     *  DisposeTimeBase()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    DisposeTimeBase(TimeBase tb);

    /**
     *  GetTimeBaseTime()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    TimeValue
    GetTimeBaseTime(TimeBase tb, TimeScale s, TimeRecord *tr);

    /**
     *  SetTimeBaseTime()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SetTimeBaseTime(TimeBase tb, const TimeRecord *tr);

    /**
     *  SetTimeBaseValue()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SetTimeBaseValue(TimeBase tb, TimeValue t, TimeScale s);

    /**
     *  GetTimeBaseRate()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    Fixed
    GetTimeBaseRate(TimeBase tb);

    /**
     *  SetTimeBaseRate()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SetTimeBaseRate(TimeBase tb, Fixed r);

    /**
     *  GetTimeBaseStartTime()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    TimeValue
    GetTimeBaseStartTime(TimeBase tb, TimeScale s, TimeRecord *tr);

    /**
     *  SetTimeBaseStartTime()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SetTimeBaseStartTime(TimeBase tb, const TimeRecord *tr);

    /**
     *  GetTimeBaseStopTime()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    TimeValue
    GetTimeBaseStopTime(TimeBase tb, TimeScale s, TimeRecord *tr);

    /**
     *  SetTimeBaseStopTime()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SetTimeBaseStopTime(TimeBase tb, const TimeRecord *tr);

    /**
     *  GetTimeBaseFlags()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    long
    GetTimeBaseFlags(TimeBase tb);

    /**
     *  SetTimeBaseFlags()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SetTimeBaseFlags(TimeBase tb, long timeBaseFlags);

    /**
     *  SetTimeBaseMasterTimeBase()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SetTimeBaseMasterTimeBase(TimeBase slave, TimeBase master,
                              const TimeRecord *slaveZero);

    /**
     *  GetTimeBaseMasterTimeBase()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    TimeBase
    GetTimeBaseMasterTimeBase(TimeBase tb);

    /**
     *  SetTimeBaseMasterClock()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SetTimeBaseMasterClock(TimeBase slave, Component clockMeister,
                           const TimeRecord *slaveZero);

    /**
     *  GetTimeBaseMasterClock()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentInstance
    GetTimeBaseMasterClock(TimeBase tb);

    /**
     *  ConvertTime()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    ConvertTime(TimeRecord *theTime, TimeBase newBase);

    /**
     *  ConvertTimeScale()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    ConvertTimeScale(TimeRecord *theTime, TimeScale newScale);

    /**
     *  AddTime()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    AddTime(TimeRecord *dst, const TimeRecord *src);

    /**
     *  SubtractTime()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SubtractTime(TimeRecord *dst, const TimeRecord *src);

    /**
     *  GetTimeBaseStatus()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    long
    GetTimeBaseStatus(TimeBase tb, TimeRecord *unpinnedTime);

    /**
     *  SetTimeBaseZero()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SetTimeBaseZero(TimeBase tb, TimeRecord *zero);

    /**
     *  GetTimeBaseEffectiveRate()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    Fixed
    GetTimeBaseEffectiveRate(TimeBase tb);

    /****************************************
     *                                       *
     *       C  A  L  L  B  A  C  K          *
     *                                       *
     ****************************************/
    /**
     *  NewCallBack()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    QTCallBack
    NewCallBack(TimeBase tb, short cbType);

    /**
     *  DisposeCallBack()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    DisposeCallBack(QTCallBack cb);

    /**
     *  GetCallBackType()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    short
    GetCallBackType(QTCallBack cb);

    /**
     *  GetCallBackTimeBase()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    TimeBase
    GetCallBackTimeBase(QTCallBack cb);

    /**
     *  CallMeWhen()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    CallMeWhen(QTCallBack cb, QTCallBackUPP callBackProc, long refCon, long param1,
               long param2, long param3);

    /**
     *  CancelCallBack()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    CancelCallBack(QTCallBack cb);

    /****************************************
     *                                       *
     *       C L O C K   C A L L B A C K     *
     *             S U P P O R T             *
     *                                       *
     ****************************************/
    /**
     *  AddCallBackToTimeBase()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    AddCallBackToTimeBase(QTCallBack cb);

    /**
     *  RemoveCallBackFromTimeBase()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    RemoveCallBackFromTimeBase(QTCallBack cb);

    /**
     *  GetFirstCallBack()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    QTCallBack
    GetFirstCallBack(TimeBase tb);

    /**
     *  GetNextCallBack()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    QTCallBack
    GetNextCallBack(QTCallBack cb);

    /**
     *  ExecuteCallBack()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    ExecuteCallBack(QTCallBack cb);

    /**
     *  MusicMediaGetIndexedTunePlayer()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MusicMediaGetIndexedTunePlayer(ComponentInstance ti, long sampleDescIndex,
                                   ComponentInstance *tp);

    /* UPP call backs */
    /**
     *  NewMovieRgnCoverUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    MovieRgnCoverUPP
    NewMovieRgnCoverUPP(MovieRgnCoverProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
    enum
    {
        uppMovieRgnCoverProcInfo = 0x00000FE0
    }; /* pascal 2_bytes Func(4_bytes, 4_bytes, 4_bytes) */
#ifdef __cplusplus
    inline MovieRgnCoverUPP NewMovieRgnCoverUPP(MovieRgnCoverProcPtr userRoutine)
    {
        return (MovieRgnCoverUPP)NewRoutineDescriptor((ProcPtr)(userRoutine),
                                                      uppMovieRgnCoverProcInfo,
                                                      GetCurrentArchitecture());
    }
#else
#define NewMovieRgnCoverUPP(userRoutine)                                       \
    (MovieRgnCoverUPP)                                                         \
        NewRoutineDescriptor((ProcPtr)(userRoutine), uppMovieRgnCoverProcInfo, \
                             GetCurrentArchitecture())
#endif
#endif

    /**
     *  NewMovieProgressUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    MovieProgressUPP
    NewMovieProgressUPP(MovieProgressProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
    enum
    {
        uppMovieProgressProcInfo = 0x0000FAE0
    }; /* pascal 2_bytes Func(4_bytes, 2_bytes, 2_bytes, 4_bytes, 4_bytes) */
#ifdef __cplusplus
    inline MovieProgressUPP NewMovieProgressUPP(MovieProgressProcPtr userRoutine)
    {
        return (MovieProgressUPP)NewRoutineDescriptor((ProcPtr)(userRoutine),
                                                      uppMovieProgressProcInfo,
                                                      GetCurrentArchitecture());
    }
#else
#define NewMovieProgressUPP(userRoutine)                                       \
    (MovieProgressUPP)                                                         \
        NewRoutineDescriptor((ProcPtr)(userRoutine), uppMovieProgressProcInfo, \
                             GetCurrentArchitecture())
#endif
#endif

    /**
     *  NewMovieDrawingCompleteUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    MovieDrawingCompleteUPP
    NewMovieDrawingCompleteUPP(MovieDrawingCompleteProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
    enum
    {
        uppMovieDrawingCompleteProcInfo = 0x000003E0
    }; /* pascal 2_bytes Func(4_bytes, 4_bytes) */
#ifdef __cplusplus
    inline MovieDrawingCompleteUPP
    NewMovieDrawingCompleteUPP(MovieDrawingCompleteProcPtr userRoutine)
    {
        return (MovieDrawingCompleteUPP)NewRoutineDescriptor(
            (ProcPtr)(userRoutine), uppMovieDrawingCompleteProcInfo,
            GetCurrentArchitecture());
    }
#else
#define NewMovieDrawingCompleteUPP(userRoutine)                  \
    (MovieDrawingCompleteUPP) NewRoutineDescriptor(              \
        (ProcPtr)(userRoutine), uppMovieDrawingCompleteProcInfo, \
        GetCurrentArchitecture())
#endif
#endif

    /**
     *  NewTrackTransferUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    TrackTransferUPP
    NewTrackTransferUPP(TrackTransferProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
    enum
    {
        uppTrackTransferProcInfo = 0x000003E0
    }; /* pascal 2_bytes Func(4_bytes, 4_bytes) */
#ifdef __cplusplus
    inline TrackTransferUPP NewTrackTransferUPP(TrackTransferProcPtr userRoutine)
    {
        return (TrackTransferUPP)NewRoutineDescriptor((ProcPtr)(userRoutine),
                                                      uppTrackTransferProcInfo,
                                                      GetCurrentArchitecture());
    }
#else
#define NewTrackTransferUPP(userRoutine)                                       \
    (TrackTransferUPP)                                                         \
        NewRoutineDescriptor((ProcPtr)(userRoutine), uppTrackTransferProcInfo, \
                             GetCurrentArchitecture())
#endif
#endif

    /**
     *  NewGetMovieUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    GetMovieUPP
    NewGetMovieUPP(GetMovieProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
    enum
    {
        uppGetMovieProcInfo = 0x00003FE0
    }; /* pascal 2_bytes Func(4_bytes, 4_bytes, 4_bytes, 4_bytes) */
#ifdef __cplusplus
    inline GetMovieUPP NewGetMovieUPP(GetMovieProcPtr userRoutine)
    {
        return (GetMovieUPP)NewRoutineDescriptor(
            (ProcPtr)(userRoutine), uppGetMovieProcInfo, GetCurrentArchitecture());
    }
#else
#define NewGetMovieUPP(userRoutine)     \
    (GetMovieUPP) NewRoutineDescriptor( \
        (ProcPtr)(userRoutine), uppGetMovieProcInfo, GetCurrentArchitecture())
#endif
#endif

    /**
     *  NewMoviePreviewCallOutUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    MoviePreviewCallOutUPP
    NewMoviePreviewCallOutUPP(MoviePreviewCallOutProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
    enum
    {
        uppMoviePreviewCallOutProcInfo = 0x000000D0
    }; /* pascal 1_byte Func(4_bytes) */
#ifdef __cplusplus
    inline MoviePreviewCallOutUPP
    NewMoviePreviewCallOutUPP(MoviePreviewCallOutProcPtr userRoutine)
    {
        return (MoviePreviewCallOutUPP)NewRoutineDescriptor(
            (ProcPtr)(userRoutine), uppMoviePreviewCallOutProcInfo,
            GetCurrentArchitecture());
    }
#else
#define NewMoviePreviewCallOutUPP(userRoutine)                  \
    (MoviePreviewCallOutUPP) NewRoutineDescriptor(              \
        (ProcPtr)(userRoutine), uppMoviePreviewCallOutProcInfo, \
        GetCurrentArchitecture())
#endif
#endif

    /**
     *  NewTextMediaUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    TextMediaUPP
    NewTextMediaUPP(TextMediaProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
    enum
    {
        uppTextMediaProcInfo = 0x00003FE0
    }; /* pascal 2_bytes Func(4_bytes, 4_bytes, 4_bytes, 4_bytes) */
#ifdef __cplusplus
    inline TextMediaUPP NewTextMediaUPP(TextMediaProcPtr userRoutine)
    {
        return (TextMediaUPP)NewRoutineDescriptor(
            (ProcPtr)(userRoutine), uppTextMediaProcInfo, GetCurrentArchitecture());
    }
#else
#define NewTextMediaUPP(userRoutine)     \
    (TextMediaUPP) NewRoutineDescriptor( \
        (ProcPtr)(userRoutine), uppTextMediaProcInfo, GetCurrentArchitecture())
#endif
#endif

    /**
     *  NewActionsUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    ActionsUPP
    NewActionsUPP(ActionsProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
    enum
    {
        uppActionsProcInfo = 0x00003FE0
    }; /* pascal 2_bytes Func(4_bytes, 4_bytes, 4_bytes, 4_bytes) */
#ifdef __cplusplus
    inline ActionsUPP NewActionsUPP(ActionsProcPtr userRoutine)
    {
        return (ActionsUPP)NewRoutineDescriptor(
            (ProcPtr)(userRoutine), uppActionsProcInfo, GetCurrentArchitecture());
    }
#else
#define NewActionsUPP(userRoutine)     \
    (ActionsUPP) NewRoutineDescriptor( \
        (ProcPtr)(userRoutine), uppActionsProcInfo, GetCurrentArchitecture())
#endif
#endif

    /**
     *  NewDoMCActionUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     */
    DoMCActionUPP
    NewDoMCActionUPP(DoMCActionProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
    enum
    {
        uppDoMCActionProcInfo = 0x00003EE0
    }; /* pascal 2_bytes Func(4_bytes, 2_bytes, 4_bytes, 4_bytes) */
#ifdef __cplusplus
    inline DoMCActionUPP NewDoMCActionUPP(DoMCActionProcPtr userRoutine)
    {
        return (DoMCActionUPP)NewRoutineDescriptor(
            (ProcPtr)(userRoutine), uppDoMCActionProcInfo, GetCurrentArchitecture());
    }
#else
#define NewDoMCActionUPP(userRoutine)     \
    (DoMCActionUPP) NewRoutineDescriptor( \
        (ProcPtr)(userRoutine), uppDoMCActionProcInfo, GetCurrentArchitecture())
#endif
#endif

    /**
     *  NewMovieExecuteWiredActionsUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     */
    MovieExecuteWiredActionsUPP
    NewMovieExecuteWiredActionsUPP(MovieExecuteWiredActionsProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
    enum
    {
        uppMovieExecuteWiredActionsProcInfo = 0x00003FE0
    }; /* pascal 2_bytes Func(4_bytes, 4_bytes, 4_bytes, 4_bytes) */
#ifdef __cplusplus
    inline MovieExecuteWiredActionsUPP
    NewMovieExecuteWiredActionsUPP(MovieExecuteWiredActionsProcPtr userRoutine)
    {
        return (MovieExecuteWiredActionsUPP)NewRoutineDescriptor(
            (ProcPtr)(userRoutine), uppMovieExecuteWiredActionsProcInfo,
            GetCurrentArchitecture());
    }
#else
#define NewMovieExecuteWiredActionsUPP(userRoutine)                  \
    (MovieExecuteWiredActionsUPP) NewRoutineDescriptor(              \
        (ProcPtr)(userRoutine), uppMovieExecuteWiredActionsProcInfo, \
        GetCurrentArchitecture())
#endif
#endif

    /**
     *  NewMoviePrePrerollCompleteUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     */
    MoviePrePrerollCompleteUPP
    NewMoviePrePrerollCompleteUPP(MoviePrePrerollCompleteProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
    enum
    {
        uppMoviePrePrerollCompleteProcInfo = 0x00000EC0
    }; /* pascal no_return_value Func(4_bytes, 2_bytes, 4_bytes) */
#ifdef __cplusplus
    inline MoviePrePrerollCompleteUPP
    NewMoviePrePrerollCompleteUPP(MoviePrePrerollCompleteProcPtr userRoutine)
    {
        return (MoviePrePrerollCompleteUPP)NewRoutineDescriptor(
            (ProcPtr)(userRoutine), uppMoviePrePrerollCompleteProcInfo,
            GetCurrentArchitecture());
    }
#else
#define NewMoviePrePrerollCompleteUPP(userRoutine)                  \
    (MoviePrePrerollCompleteUPP) NewRoutineDescriptor(              \
        (ProcPtr)(userRoutine), uppMoviePrePrerollCompleteProcInfo, \
        GetCurrentArchitecture())
#endif
#endif

    /**
     *  NewMoviesErrorUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    MoviesErrorUPP
    NewMoviesErrorUPP(MoviesErrorProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
    enum
    {
        uppMoviesErrorProcInfo = 0x00000380
    }; /* pascal no_return_value Func(2_bytes, 4_bytes) */
#ifdef __cplusplus
    inline MoviesErrorUPP NewMoviesErrorUPP(MoviesErrorProcPtr userRoutine)
    {
        return (MoviesErrorUPP)NewRoutineDescriptor(
            (ProcPtr)(userRoutine), uppMoviesErrorProcInfo, GetCurrentArchitecture());
    }
#else
#define NewMoviesErrorUPP(userRoutine)                                       \
    (MoviesErrorUPP)                                                         \
        NewRoutineDescriptor((ProcPtr)(userRoutine), uppMoviesErrorProcInfo, \
                             GetCurrentArchitecture())
#endif
#endif

    /**
     *  NewQTCallBackUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    QTCallBackUPP
    NewQTCallBackUPP(QTCallBackProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
    enum
    {
        uppQTCallBackProcInfo = 0x000003C0
    }; /* pascal no_return_value Func(4_bytes, 4_bytes) */
#ifdef __cplusplus
    inline QTCallBackUPP NewQTCallBackUPP(QTCallBackProcPtr userRoutine)
    {
        return (QTCallBackUPP)NewRoutineDescriptor(
            (ProcPtr)(userRoutine), uppQTCallBackProcInfo, GetCurrentArchitecture());
    }
#else
#define NewQTCallBackUPP(userRoutine)     \
    (QTCallBackUPP) NewRoutineDescriptor( \
        (ProcPtr)(userRoutine), uppQTCallBackProcInfo, GetCurrentArchitecture())
#endif
#endif

    /**
     *  NewQTSyncTaskUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    QTSyncTaskUPP
    NewQTSyncTaskUPP(QTSyncTaskProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
    enum
    {
        uppQTSyncTaskProcInfo = 0x000000C0
    }; /* pascal no_return_value Func(4_bytes) */
#ifdef __cplusplus
    inline QTSyncTaskUPP NewQTSyncTaskUPP(QTSyncTaskProcPtr userRoutine)
    {
        return (QTSyncTaskUPP)NewRoutineDescriptor(
            (ProcPtr)(userRoutine), uppQTSyncTaskProcInfo, GetCurrentArchitecture());
    }
#else
#define NewQTSyncTaskUPP(userRoutine)     \
    (QTSyncTaskUPP) NewRoutineDescriptor( \
        (ProcPtr)(userRoutine), uppQTSyncTaskProcInfo, GetCurrentArchitecture())
#endif
#endif

    /**
     *  NewTweenerDataUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    TweenerDataUPP
    NewTweenerDataUPP(TweenerDataProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
    enum
    {
        uppTweenerDataProcInfo = 0x003FFFF0
    }; /* pascal 4_bytes Func(4_bytes, 4_bytes, 4_bytes, 4_bytes, 4_bytes, 4_bytes,
          4_bytes, 4_bytes) */
#ifdef __cplusplus
    inline TweenerDataUPP NewTweenerDataUPP(TweenerDataProcPtr userRoutine)
    {
        return (TweenerDataUPP)NewRoutineDescriptor(
            (ProcPtr)(userRoutine), uppTweenerDataProcInfo, GetCurrentArchitecture());
    }
#else
#define NewTweenerDataUPP(userRoutine)                                       \
    (TweenerDataUPP)                                                         \
        NewRoutineDescriptor((ProcPtr)(userRoutine), uppTweenerDataProcInfo, \
                             GetCurrentArchitecture())
#endif
#endif

    /**
     *  NewQTBandwidthNotificationUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     */
    QTBandwidthNotificationUPP
    NewQTBandwidthNotificationUPP(QTBandwidthNotificationProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
    enum
    {
        uppQTBandwidthNotificationProcInfo = 0x00000FE0
    }; /* pascal 2_bytes Func(4_bytes, 4_bytes, 4_bytes) */
#ifdef __cplusplus
    inline QTBandwidthNotificationUPP
    NewQTBandwidthNotificationUPP(QTBandwidthNotificationProcPtr userRoutine)
    {
        return (QTBandwidthNotificationUPP)NewRoutineDescriptor(
            (ProcPtr)(userRoutine), uppQTBandwidthNotificationProcInfo,
            GetCurrentArchitecture());
    }
#else
#define NewQTBandwidthNotificationUPP(userRoutine)                  \
    (QTBandwidthNotificationUPP) NewRoutineDescriptor(              \
        (ProcPtr)(userRoutine), uppQTBandwidthNotificationProcInfo, \
        GetCurrentArchitecture())
#endif
#endif

    /**
     *  NewMCActionFilterUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    MCActionFilterUPP
    NewMCActionFilterUPP(MCActionFilterProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
    enum
    {
        uppMCActionFilterProcInfo = 0x00000FD0
    }; /* pascal 1_byte Func(4_bytes, 4_bytes, 4_bytes) */
#ifdef __cplusplus
    inline MCActionFilterUPP
    NewMCActionFilterUPP(MCActionFilterProcPtr userRoutine)
    {
        return (MCActionFilterUPP)NewRoutineDescriptor((ProcPtr)(userRoutine),
                                                       uppMCActionFilterProcInfo,
                                                       GetCurrentArchitecture());
    }
#else
#define NewMCActionFilterUPP(userRoutine)                                       \
    (MCActionFilterUPP)                                                         \
        NewRoutineDescriptor((ProcPtr)(userRoutine), uppMCActionFilterProcInfo, \
                             GetCurrentArchitecture())
#endif
#endif

    /**
     *  NewMCActionFilterWithRefConUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    MCActionFilterWithRefConUPP
    NewMCActionFilterWithRefConUPP(MCActionFilterWithRefConProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
    enum
    {
        uppMCActionFilterWithRefConProcInfo = 0x00003ED0
    }; /* pascal 1_byte Func(4_bytes, 2_bytes, 4_bytes, 4_bytes) */
#ifdef __cplusplus
    inline MCActionFilterWithRefConUPP
    NewMCActionFilterWithRefConUPP(MCActionFilterWithRefConProcPtr userRoutine)
    {
        return (MCActionFilterWithRefConUPP)NewRoutineDescriptor(
            (ProcPtr)(userRoutine), uppMCActionFilterWithRefConProcInfo,
            GetCurrentArchitecture());
    }
#else
#define NewMCActionFilterWithRefConUPP(userRoutine)                  \
    (MCActionFilterWithRefConUPP) NewRoutineDescriptor(              \
        (ProcPtr)(userRoutine), uppMCActionFilterWithRefConProcInfo, \
        GetCurrentArchitecture())
#endif
#endif

    /**
     *  DisposeMovieRgnCoverUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    DisposeMovieRgnCoverUPP(MovieRgnCoverUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline void DisposeMovieRgnCoverUPP(MovieRgnCoverUPP userUPP)
    {
        DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
    }
#else
#define DisposeMovieRgnCoverUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

    /**
     *  DisposeMovieProgressUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    DisposeMovieProgressUPP(MovieProgressUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline void DisposeMovieProgressUPP(MovieProgressUPP userUPP)
    {
        DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
    }
#else
#define DisposeMovieProgressUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

    /**
     *  DisposeMovieDrawingCompleteUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    DisposeMovieDrawingCompleteUPP(MovieDrawingCompleteUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline void DisposeMovieDrawingCompleteUPP(MovieDrawingCompleteUPP userUPP)
    {
        DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
    }
#else
#define DisposeMovieDrawingCompleteUPP(userUPP) \
    DisposeRoutineDescriptor(userUPP)
#endif
#endif

    /**
     *  DisposeTrackTransferUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    DisposeTrackTransferUPP(TrackTransferUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline void DisposeTrackTransferUPP(TrackTransferUPP userUPP)
    {
        DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
    }
#else
#define DisposeTrackTransferUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

    /**
     *  DisposeGetMovieUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    DisposeGetMovieUPP(GetMovieUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline void DisposeGetMovieUPP(GetMovieUPP userUPP)
    {
        DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
    }
#else
#define DisposeGetMovieUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

    /**
     *  DisposeMoviePreviewCallOutUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    DisposeMoviePreviewCallOutUPP(MoviePreviewCallOutUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline void DisposeMoviePreviewCallOutUPP(MoviePreviewCallOutUPP userUPP)
    {
        DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
    }
#else
#define DisposeMoviePreviewCallOutUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

    /**
     *  DisposeTextMediaUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    DisposeTextMediaUPP(TextMediaUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline void DisposeTextMediaUPP(TextMediaUPP userUPP)
    {
        DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
    }
#else
#define DisposeTextMediaUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

    /**
     *  DisposeActionsUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    DisposeActionsUPP(ActionsUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline void DisposeActionsUPP(ActionsUPP userUPP)
    {
        DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
    }
#else
#define DisposeActionsUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

    /**
     *  DisposeDoMCActionUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    DisposeDoMCActionUPP(DoMCActionUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline void DisposeDoMCActionUPP(DoMCActionUPP userUPP)
    {
        DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
    }
#else
#define DisposeDoMCActionUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

    /**
     *  DisposeMovieExecuteWiredActionsUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    DisposeMovieExecuteWiredActionsUPP(MovieExecuteWiredActionsUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline void
    DisposeMovieExecuteWiredActionsUPP(MovieExecuteWiredActionsUPP userUPP)
    {
        DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
    }
#else
#define DisposeMovieExecuteWiredActionsUPP(userUPP) \
    DisposeRoutineDescriptor(userUPP)
#endif
#endif

    /**
     *  DisposeMoviePrePrerollCompleteUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    DisposeMoviePrePrerollCompleteUPP(MoviePrePrerollCompleteUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline void
    DisposeMoviePrePrerollCompleteUPP(MoviePrePrerollCompleteUPP userUPP)
    {
        DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
    }
#else
#define DisposeMoviePrePrerollCompleteUPP(userUPP) \
    DisposeRoutineDescriptor(userUPP)
#endif
#endif

    /**
     *  DisposeMoviesErrorUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    DisposeMoviesErrorUPP(MoviesErrorUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline void DisposeMoviesErrorUPP(MoviesErrorUPP userUPP)
    {
        DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
    }
#else
#define DisposeMoviesErrorUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

    /**
     *  DisposeQTCallBackUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    DisposeQTCallBackUPP(QTCallBackUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline void DisposeQTCallBackUPP(QTCallBackUPP userUPP)
    {
        DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
    }
#else
#define DisposeQTCallBackUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

    /**
     *  DisposeQTSyncTaskUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    DisposeQTSyncTaskUPP(QTSyncTaskUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline void DisposeQTSyncTaskUPP(QTSyncTaskUPP userUPP)
    {
        DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
    }
#else
#define DisposeQTSyncTaskUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

    /**
     *  DisposeTweenerDataUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    DisposeTweenerDataUPP(TweenerDataUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline void DisposeTweenerDataUPP(TweenerDataUPP userUPP)
    {
        DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
    }
#else
#define DisposeTweenerDataUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

    /**
     *  DisposeQTBandwidthNotificationUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    DisposeQTBandwidthNotificationUPP(QTBandwidthNotificationUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline void
    DisposeQTBandwidthNotificationUPP(QTBandwidthNotificationUPP userUPP)
    {
        DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
    }
#else
#define DisposeQTBandwidthNotificationUPP(userUPP) \
    DisposeRoutineDescriptor(userUPP)
#endif
#endif

    /**
     *  DisposeMCActionFilterUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    DisposeMCActionFilterUPP(MCActionFilterUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline void DisposeMCActionFilterUPP(MCActionFilterUPP userUPP)
    {
        DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
    }
#else
#define DisposeMCActionFilterUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

    /**
     *  DisposeMCActionFilterWithRefConUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    DisposeMCActionFilterWithRefConUPP(MCActionFilterWithRefConUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline void
    DisposeMCActionFilterWithRefConUPP(MCActionFilterWithRefConUPP userUPP)
    {
        DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
    }
#else
#define DisposeMCActionFilterWithRefConUPP(userUPP) \
    DisposeRoutineDescriptor(userUPP)
#endif
#endif

    /**
     *  InvokeMovieRgnCoverUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    InvokeMovieRgnCoverUPP(Movie theMovie, RgnHandle changedRgn, long refcon,
                           MovieRgnCoverUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline OSErr InvokeMovieRgnCoverUPP(Movie theMovie, RgnHandle changedRgn,
                                        long refcon, MovieRgnCoverUPP userUPP)
    {
        return (OSErr)CALL_THREE_PARAMETER_UPP(userUPP, uppMovieRgnCoverProcInfo,
                                               theMovie, changedRgn, refcon);
    }
#else
#define InvokeMovieRgnCoverUPP(theMovie, changedRgn, refcon, userUPP)     \
    (OSErr) CALL_THREE_PARAMETER_UPP((userUPP), uppMovieRgnCoverProcInfo, \
                                     (theMovie), (changedRgn), (refcon))
#endif
#endif

    /**
     *  InvokeMovieProgressUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    InvokeMovieProgressUPP(Movie theMovie, short message, short whatOperation,
                           Fixed percentDone, long refcon,
                           MovieProgressUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline OSErr InvokeMovieProgressUPP(Movie theMovie, short message,
                                        short whatOperation, Fixed percentDone,
                                        long refcon, MovieProgressUPP userUPP)
    {
        return (OSErr)CALL_FIVE_PARAMETER_UPP(userUPP, uppMovieProgressProcInfo,
                                              theMovie, message, whatOperation,
                                              percentDone, refcon);
    }
#else
#define InvokeMovieProgressUPP(theMovie, message, whatOperation, percentDone, \
                               refcon, userUPP)                               \
    (OSErr) CALL_FIVE_PARAMETER_UPP((userUPP), uppMovieProgressProcInfo,      \
                                    (theMovie), (message), (whatOperation),   \
                                    (percentDone), (refcon))
#endif
#endif

    /**
     *  InvokeMovieDrawingCompleteUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    InvokeMovieDrawingCompleteUPP(Movie theMovie, long refCon,
                                  MovieDrawingCompleteUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline OSErr InvokeMovieDrawingCompleteUPP(Movie theMovie, long refCon,
                                               MovieDrawingCompleteUPP userUPP)
    {
        return (OSErr)CALL_TWO_PARAMETER_UPP(userUPP, uppMovieDrawingCompleteProcInfo,
                                             theMovie, refCon);
    }
#else
#define InvokeMovieDrawingCompleteUPP(theMovie, refCon, userUPP)               \
    (OSErr) CALL_TWO_PARAMETER_UPP((userUPP), uppMovieDrawingCompleteProcInfo, \
                                   (theMovie), (refCon))
#endif
#endif

    /**
     *  InvokeTrackTransferUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    InvokeTrackTransferUPP(Track t, long refCon, TrackTransferUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline OSErr InvokeTrackTransferUPP(Track t, long refCon,
                                        TrackTransferUPP userUPP)
    {
        return (OSErr)CALL_TWO_PARAMETER_UPP(userUPP, uppTrackTransferProcInfo, t,
                                             refCon);
    }
#else
#define InvokeTrackTransferUPP(t, refCon, userUPP)                           \
    (OSErr) CALL_TWO_PARAMETER_UPP((userUPP), uppTrackTransferProcInfo, (t), \
                                   (refCon))
#endif
#endif

    /**
     *  InvokeGetMovieUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    InvokeGetMovieUPP(long offset, long size, void *dataPtr, void *refCon,
                      GetMovieUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline OSErr InvokeGetMovieUPP(long offset, long size, void *dataPtr,
                                   void *refCon, GetMovieUPP userUPP)
    {
        return (OSErr)CALL_FOUR_PARAMETER_UPP(userUPP, uppGetMovieProcInfo, offset,
                                              size, dataPtr, refCon);
    }
#else
#define InvokeGetMovieUPP(offset, size, dataPtr, refCon, userUPP)             \
    (OSErr) CALL_FOUR_PARAMETER_UPP((userUPP), uppGetMovieProcInfo, (offset), \
                                    (size), (dataPtr), (refCon))
#endif
#endif

    /**
     *  InvokeMoviePreviewCallOutUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    Boolean
    InvokeMoviePreviewCallOutUPP(long refcon, MoviePreviewCallOutUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline Boolean InvokeMoviePreviewCallOutUPP(long refcon,
                                                MoviePreviewCallOutUPP userUPP)
    {
        return (Boolean)CALL_ONE_PARAMETER_UPP(
            userUPP, uppMoviePreviewCallOutProcInfo, refcon);
    }
#else
#define InvokeMoviePreviewCallOutUPP(refcon, userUPP)                           \
    (Boolean) CALL_ONE_PARAMETER_UPP((userUPP), uppMoviePreviewCallOutProcInfo, \
                                     (refcon))
#endif
#endif

    /**
     *  InvokeTextMediaUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    InvokeTextMediaUPP(Handle theText, Movie theMovie, short *displayFlag,
                       long refcon, TextMediaUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline OSErr InvokeTextMediaUPP(Handle theText, Movie theMovie,
                                    short *displayFlag, long refcon,
                                    TextMediaUPP userUPP)
    {
        return (OSErr)CALL_FOUR_PARAMETER_UPP(userUPP, uppTextMediaProcInfo, theText,
                                              theMovie, displayFlag, refcon);
    }
#else
#define InvokeTextMediaUPP(theText, theMovie, displayFlag, refcon, userUPP)     \
    (OSErr) CALL_FOUR_PARAMETER_UPP((userUPP), uppTextMediaProcInfo, (theText), \
                                    (theMovie), (displayFlag), (refcon))
#endif
#endif

    /**
     *  InvokeActionsUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    InvokeActionsUPP(void *refcon, Track targetTrack, long targetRefCon,
                     QTEventRecordPtr theEvent, ActionsUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline OSErr InvokeActionsUPP(void *refcon, Track targetTrack,
                                  long targetRefCon, QTEventRecordPtr theEvent,
                                  ActionsUPP userUPP)
    {
        return (OSErr)CALL_FOUR_PARAMETER_UPP(userUPP, uppActionsProcInfo, refcon,
                                              targetTrack, targetRefCon, theEvent);
    }
#else
#define InvokeActionsUPP(refcon, targetTrack, targetRefCon, theEvent, userUPP) \
    (OSErr) CALL_FOUR_PARAMETER_UPP((userUPP), uppActionsProcInfo, (refcon),   \
                                    (targetTrack), (targetRefCon), (theEvent))
#endif
#endif

    /**
     *  InvokeDoMCActionUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    InvokeDoMCActionUPP(void *refcon, short action, void *params, Boolean *handled,
                        DoMCActionUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline OSErr InvokeDoMCActionUPP(void *refcon, short action, void *params,
                                     Boolean *handled, DoMCActionUPP userUPP)
    {
        return (OSErr)CALL_FOUR_PARAMETER_UPP(userUPP, uppDoMCActionProcInfo, refcon,
                                              action, params, handled);
    }
#else
#define InvokeDoMCActionUPP(refcon, action, params, handled, userUPP)           \
    (OSErr) CALL_FOUR_PARAMETER_UPP((userUPP), uppDoMCActionProcInfo, (refcon), \
                                    (action), (params), (handled))
#endif
#endif

    /**
     *  InvokeMovieExecuteWiredActionsUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    InvokeMovieExecuteWiredActionsUPP(Movie theMovie, void *refcon, long flags,
                                      QTAtomContainer wiredActions,
                                      MovieExecuteWiredActionsUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline OSErr
    InvokeMovieExecuteWiredActionsUPP(Movie theMovie, void *refcon, long flags,
                                      QTAtomContainer wiredActions,
                                      MovieExecuteWiredActionsUPP userUPP)
    {
        return (OSErr)CALL_FOUR_PARAMETER_UPP(userUPP,
                                              uppMovieExecuteWiredActionsProcInfo,
                                              theMovie, refcon, flags, wiredActions);
    }
#else
#define InvokeMovieExecuteWiredActionsUPP(theMovie, refcon, flags,              \
                                          wiredActions, userUPP)                \
    (OSErr)                                                                     \
        CALL_FOUR_PARAMETER_UPP((userUPP), uppMovieExecuteWiredActionsProcInfo, \
                                (theMovie), (refcon), (flags), (wiredActions))
#endif
#endif

    /**
     *  InvokeMoviePrePrerollCompleteUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    InvokeMoviePrePrerollCompleteUPP(Movie theMovie, OSErr prerollErr, void *refcon,
                                     MoviePrePrerollCompleteUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline void
    InvokeMoviePrePrerollCompleteUPP(Movie theMovie, OSErr prerollErr, void *refcon,
                                     MoviePrePrerollCompleteUPP userUPP)
    {
        CALL_THREE_PARAMETER_UPP(userUPP, uppMoviePrePrerollCompleteProcInfo,
                                 theMovie, prerollErr, refcon);
    }
#else
#define InvokeMoviePrePrerollCompleteUPP(theMovie, prerollErr, refcon,      \
                                         userUPP)                           \
    CALL_THREE_PARAMETER_UPP((userUPP), uppMoviePrePrerollCompleteProcInfo, \
                             (theMovie), (prerollErr), (refcon))
#endif
#endif

    /**
     *  InvokeMoviesErrorUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    InvokeMoviesErrorUPP(OSErr theErr, long refcon, MoviesErrorUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline void InvokeMoviesErrorUPP(OSErr theErr, long refcon,
                                     MoviesErrorUPP userUPP)
    {
        CALL_TWO_PARAMETER_UPP(userUPP, uppMoviesErrorProcInfo, theErr, refcon);
    }
#else
#define InvokeMoviesErrorUPP(theErr, refcon, userUPP) \
    CALL_TWO_PARAMETER_UPP((userUPP), uppMoviesErrorProcInfo, (theErr), (refcon))
#endif
#endif

    /**
     *  InvokeQTCallBackUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    InvokeQTCallBackUPP(QTCallBack cb, long refCon, QTCallBackUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline void InvokeQTCallBackUPP(QTCallBack cb, long refCon,
                                    QTCallBackUPP userUPP)
    {
        CALL_TWO_PARAMETER_UPP(userUPP, uppQTCallBackProcInfo, cb, refCon);
    }
#else
#define InvokeQTCallBackUPP(cb, refCon, userUPP) \
    CALL_TWO_PARAMETER_UPP((userUPP), uppQTCallBackProcInfo, (cb), (refCon))
#endif
#endif

    /**
     *  InvokeQTSyncTaskUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    InvokeQTSyncTaskUPP(void *task, QTSyncTaskUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline void InvokeQTSyncTaskUPP(void *task, QTSyncTaskUPP userUPP)
    {
        CALL_ONE_PARAMETER_UPP(userUPP, uppQTSyncTaskProcInfo, task);
    }
#else
#define InvokeQTSyncTaskUPP(task, userUPP) \
    CALL_ONE_PARAMETER_UPP((userUPP), uppQTSyncTaskProcInfo, (task))
#endif
#endif

    /**
     *  InvokeTweenerDataUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    ComponentResult
    InvokeTweenerDataUPP(TweenRecord *tr, void *tweenData, long tweenDataSize,
                         long dataDescriptionSeed, Handle dataDescription,
                         ICMCompletionProcRecordPtr asyncCompletionProc,
                         UniversalProcPtr transferProc, void *refCon,
                         TweenerDataUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline ComponentResult
    InvokeTweenerDataUPP(TweenRecord *tr, void *tweenData, long tweenDataSize,
                         long dataDescriptionSeed, Handle dataDescription,
                         ICMCompletionProcRecordPtr asyncCompletionProc,
                         UniversalProcPtr transferProc, void *refCon,
                         TweenerDataUPP userUPP)
    {
        return (ComponentResult)CALL_EIGHT_PARAMETER_UPP(
            userUPP, uppTweenerDataProcInfo, tr, tweenData, tweenDataSize,
            dataDescriptionSeed, dataDescription, asyncCompletionProc, transferProc,
            refCon);
    }
#else
#define InvokeTweenerDataUPP(                                                  \
    tr, tweenData, tweenDataSize, dataDescriptionSeed, dataDescription,        \
    asyncCompletionProc, transferProc, refCon, userUPP)                        \
    (ComponentResult) CALL_EIGHT_PARAMETER_UPP(                                \
        (userUPP), uppTweenerDataProcInfo, (tr), (tweenData), (tweenDataSize), \
        (dataDescriptionSeed), (dataDescription), (asyncCompletionProc),       \
        (transferProc), (refCon))
#endif
#endif

    /**
     *  InvokeQTBandwidthNotificationUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    InvokeQTBandwidthNotificationUPP(long flags, void *reserved, void *refcon,
                                     QTBandwidthNotificationUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline OSErr
    InvokeQTBandwidthNotificationUPP(long flags, void *reserved, void *refcon,
                                     QTBandwidthNotificationUPP userUPP)
    {
        return (OSErr)CALL_THREE_PARAMETER_UPP(
            userUPP, uppQTBandwidthNotificationProcInfo, flags, reserved, refcon);
    }
#else
#define InvokeQTBandwidthNotificationUPP(flags, reserved, refcon, userUPP)      \
    (OSErr)                                                                     \
        CALL_THREE_PARAMETER_UPP((userUPP), uppQTBandwidthNotificationProcInfo, \
                                 (flags), (reserved), (refcon))
#endif
#endif

    /**
     *  InvokeMCActionFilterUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    Boolean
    InvokeMCActionFilterUPP(MovieController mc, short *action, void *params,
                            MCActionFilterUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline Boolean InvokeMCActionFilterUPP(MovieController mc, short *action,
                                           void *params,
                                           MCActionFilterUPP userUPP)
    {
        return (Boolean)CALL_THREE_PARAMETER_UPP(userUPP, uppMCActionFilterProcInfo,
                                                 mc, action, params);
    }
#else
#define InvokeMCActionFilterUPP(mc, action, params, userUPP)                 \
    (Boolean) CALL_THREE_PARAMETER_UPP((userUPP), uppMCActionFilterProcInfo, \
                                       (mc), (action), (params))
#endif
#endif

    /**
     *  InvokeMCActionFilterWithRefConUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    Boolean
    InvokeMCActionFilterWithRefConUPP(MovieController mc, short action,
                                      void *params, long refCon,
                                      MCActionFilterWithRefConUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline Boolean
    InvokeMCActionFilterWithRefConUPP(MovieController mc, short action,
                                      void *params, long refCon,
                                      MCActionFilterWithRefConUPP userUPP)
    {
        return (Boolean)CALL_FOUR_PARAMETER_UPP(
            userUPP, uppMCActionFilterWithRefConProcInfo, mc, action, params, refCon);
    }
#else
#define InvokeMCActionFilterWithRefConUPP(mc, action, params, refCon, userUPP)  \
    (Boolean)                                                                   \
        CALL_FOUR_PARAMETER_UPP((userUPP), uppMCActionFilterWithRefConProcInfo, \
                                (mc), (action), (params), (refCon))
#endif
#endif

#if CALL_NOT_IN_CARBON || OLDROUTINENAMES
/* support for pre-Carbon UPP routines: New...Proc and Call...Proc */
#define NewMovieRgnCoverProc(userRoutine) NewMovieRgnCoverUPP(userRoutine)
#define NewMovieProgressProc(userRoutine) NewMovieProgressUPP(userRoutine)
#define NewMovieDrawingCompleteProc(userRoutine) \
    NewMovieDrawingCompleteUPP(userRoutine)
#define NewTrackTransferProc(userRoutine) NewTrackTransferUPP(userRoutine)
#define NewGetMovieProc(userRoutine) NewGetMovieUPP(userRoutine)
#define NewMoviePreviewCallOutProc(userRoutine) \
    NewMoviePreviewCallOutUPP(userRoutine)
#define NewTextMediaProc(userRoutine) NewTextMediaUPP(userRoutine)
#define NewActionsProc(userRoutine) NewActionsUPP(userRoutine)
#define NewDoMCActionProc(userRoutine) NewDoMCActionUPP(userRoutine)
#define NewMovieExecuteWiredActionsProc(userRoutine) \
    NewMovieExecuteWiredActionsUPP(userRoutine)
#define NewMoviePrePrerollCompleteProc(userRoutine) \
    NewMoviePrePrerollCompleteUPP(userRoutine)
#define NewMoviesErrorProc(userRoutine) NewMoviesErrorUPP(userRoutine)
#define NewQTCallBackProc(userRoutine) NewQTCallBackUPP(userRoutine)
#define NewQTSyncTaskProc(userRoutine) NewQTSyncTaskUPP(userRoutine)
#define NewTweenerDataProc(userRoutine) NewTweenerDataUPP(userRoutine)
#define NewQTBandwidthNotificationProc(userRoutine) \
    NewQTBandwidthNotificationUPP(userRoutine)
#define NewMCActionFilterProc(userRoutine) NewMCActionFilterUPP(userRoutine)
#define NewMCActionFilterWithRefConProc(userRoutine) \
    NewMCActionFilterWithRefConUPP(userRoutine)
#define CallMovieRgnCoverProc(userRoutine, theMovie, changedRgn, refcon) \
    InvokeMovieRgnCoverUPP(theMovie, changedRgn, refcon, userRoutine)
#define CallMovieProgressProc(userRoutine, theMovie, message, whatOperation, \
                              percentDone, refcon)                           \
    InvokeMovieProgressUPP(theMovie, message, whatOperation, percentDone,    \
                           refcon, userRoutine)
#define CallMovieDrawingCompleteProc(userRoutine, theMovie, refCon) \
    InvokeMovieDrawingCompleteUPP(theMovie, refCon, userRoutine)
#define CallTrackTransferProc(userRoutine, t, refCon) \
    InvokeTrackTransferUPP(t, refCon, userRoutine)
#define CallGetMovieProc(userRoutine, offset, size, dataPtr, refCon) \
    InvokeGetMovieUPP(offset, size, dataPtr, refCon, userRoutine)
#define CallMoviePreviewCallOutProc(userRoutine, refcon) \
    InvokeMoviePreviewCallOutUPP(refcon, userRoutine)
#define CallTextMediaProc(userRoutine, theText, theMovie, displayFlag, refcon) \
    InvokeTextMediaUPP(theText, theMovie, displayFlag, refcon, userRoutine)
#define CallActionsProc(userRoutine, refcon, targetTrack, targetRefCon, \
                        theEvent)                                       \
    InvokeActionsUPP(refcon, targetTrack, targetRefCon, theEvent, userRoutine)
#define CallDoMCActionProc(userRoutine, refcon, action, params, handled) \
    InvokeDoMCActionUPP(refcon, action, params, handled, userRoutine)
#define CallMovieExecuteWiredActionsProc(userRoutine, theMovie, refcon, flags, \
                                         wiredActions)                         \
    InvokeMovieExecuteWiredActionsUPP(theMovie, refcon, flags, wiredActions,   \
                                      userRoutine)
#define CallMoviePrePrerollCompleteProc(userRoutine, theMovie, prerollErr, \
                                        refcon)                            \
    InvokeMoviePrePrerollCompleteUPP(theMovie, prerollErr, refcon, userRoutine)
#define CallMoviesErrorProc(userRoutine, theErr, refcon) \
    InvokeMoviesErrorUPP(theErr, refcon, userRoutine)
#define CallQTCallBackProc(userRoutine, cb, refCon) \
    InvokeQTCallBackUPP(cb, refCon, userRoutine)
#define CallQTSyncTaskProc(userRoutine, task) \
    InvokeQTSyncTaskUPP(task, userRoutine)
#define CallTweenerDataProc(userRoutine, tr, tweenData, tweenDataSize,       \
                            dataDescriptionSeed, dataDescription,            \
                            asyncCompletionProc, transferProc, refCon)       \
    InvokeTweenerDataUPP(tr, tweenData, tweenDataSize, dataDescriptionSeed,  \
                         dataDescription, asyncCompletionProc, transferProc, \
                         refCon, userRoutine)
#define CallQTBandwidthNotificationProc(userRoutine, flags, reserved, refcon) \
    InvokeQTBandwidthNotificationUPP(flags, reserved, refcon, userRoutine)
#define CallMCActionFilterProc(userRoutine, mc, action, params) \
    InvokeMCActionFilterUPP(mc, action, params, userRoutine)
#define CallMCActionFilterWithRefConProc(userRoutine, mc, action, params, \
                                         refCon)                          \
    InvokeMCActionFilterWithRefConUPP(mc, action, params, refCon, userRoutine)
#endif /* CALL_NOT_IN_CARBON */

    /* selectors for component calls */
    enum
    {
        kVideoMediaResetStatisticsSelect = 0x0105,
        kVideoMediaGetStatisticsSelect = 0x0106,
        kVideoMediaGetStallCountSelect = 0x010E,
        kVideoMediaSetCodecParameterSelect = 0x010F,
        kVideoMediaGetCodecParameterSelect = 0x0110,
        kTextMediaSetTextProcSelect = 0x0101,
        kTextMediaAddTextSampleSelect = 0x0102,
        kTextMediaAddTESampleSelect = 0x0103,
        kTextMediaAddHiliteSampleSelect = 0x0104,
        kTextMediaDrawRawSelect = 0x0109,
        kTextMediaSetTextPropertySelect = 0x010A,
        kTextMediaRawSetupSelect = 0x010B,
        kTextMediaRawIdleSelect = 0x010C,
        kTextMediaGetTextPropertySelect = 0x010D,
        kTextMediaFindNextTextSelect = 0x0105,
        kTextMediaHiliteTextSampleSelect = 0x0106,
        kTextMediaSetTextSampleDataSelect = 0x0107,
        kSpriteMediaSetPropertySelect = 0x0101,
        kSpriteMediaGetPropertySelect = 0x0102,
        kSpriteMediaHitTestSpritesSelect = 0x0103,
        kSpriteMediaCountSpritesSelect = 0x0104,
        kSpriteMediaCountImagesSelect = 0x0105,
        kSpriteMediaGetIndImageDescriptionSelect = 0x0106,
        kSpriteMediaGetDisplayedSampleNumberSelect = 0x0107,
        kSpriteMediaGetSpriteNameSelect = 0x0108,
        kSpriteMediaGetImageNameSelect = 0x0109,
        kSpriteMediaSetSpritePropertySelect = 0x010A,
        kSpriteMediaGetSpritePropertySelect = 0x010B,
        kSpriteMediaHitTestAllSpritesSelect = 0x010C,
        kSpriteMediaHitTestOneSpriteSelect = 0x010D,
        kSpriteMediaSpriteIndexToIDSelect = 0x010E,
        kSpriteMediaSpriteIDToIndexSelect = 0x010F,
        kSpriteMediaGetSpriteActionsForQTEventSelect = 0x0110,
        kSpriteMediaSetActionVariableSelect = 0x0111,
        kSpriteMediaGetActionVariableSelect = 0x0112,
        kSpriteMediaGetIndImagePropertySelect = 0x0113,
        kSpriteMediaNewSpriteSelect = 0x0114,
        kSpriteMediaDisposeSpriteSelect = 0x0115,
        kSpriteMediaSetActionVariableToStringSelect = 0x0116,
        kSpriteMediaGetActionVariableAsStringSelect = 0x0117,
        kFlashMediaSetPanSelect = 0x0101,
        kFlashMediaSetZoomSelect = 0x0102,
        kFlashMediaSetZoomRectSelect = 0x0103,
        kFlashMediaGetRefConBoundsSelect = 0x0104,
        kFlashMediaGetRefConIDSelect = 0x0105,
        kFlashMediaIDToRefConSelect = 0x0106,
        kFlashMediaGetDisplayedFrameNumberSelect = 0x0107,
        kFlashMediaFrameNumberToMovieTimeSelect = 0x0108,
        kFlashMediaFrameLabelToMovieTimeSelect = 0x0109,
        kFlashMediaGetFlashVariableSelect = 0x010A,
        kFlashMediaSetFlashVariableSelect = 0x010B,
        kFlashMediaDoButtonActionsSelect = 0x010C,
        kFlashMediaGetSupportedSwfVersionSelect = 0x010D,
        kMovieMediaGetChildDoMCActionCallbackSelect = 0x0102,
        kMovieMediaGetDoMCActionCallbackSelect = 0x0103,
        kMovieMediaGetCurrentMoviePropertySelect = 0x0104,
        kMovieMediaGetCurrentTrackPropertySelect = 0x0105,
        kMovieMediaGetChildMovieDataReferenceSelect = 0x0106,
        kMovieMediaSetChildMovieDataReferenceSelect = 0x0107,
        kMovieMediaLoadChildMovieFromDataReferenceSelect = 0x0108,
        kMedia3DGetNamedObjectListSelect = 0x0101,
        kMedia3DGetRendererListSelect = 0x0102,
        kMedia3DGetCurrentGroupSelect = 0x0103,
        kMedia3DTranslateNamedObjectToSelect = 0x0104,
        kMedia3DScaleNamedObjectToSelect = 0x0105,
        kMedia3DRotateNamedObjectToSelect = 0x0106,
        kMedia3DSetCameraDataSelect = 0x0107,
        kMedia3DGetCameraDataSelect = 0x0108,
        kMedia3DSetCameraAngleAspectSelect = 0x0109,
        kMedia3DGetCameraAngleAspectSelect = 0x010A,
        kMedia3DSetCameraRangeSelect = 0x010D,
        kMedia3DGetCameraRangeSelect = 0x010E,
        kMedia3DGetViewObjectSelect = 0x010F,
        kMCSetMovieSelect = 0x0002,
        kMCGetIndMovieSelect = 0x0005,
        kMCRemoveAllMoviesSelect = 0x0006,
        kMCRemoveAMovieSelect = 0x0003,
        kMCRemoveMovieSelect = 0x0006,
        kMCIsPlayerEventSelect = 0x0007,
        kMCSetActionFilterSelect = 0x0008,
        kMCDoActionSelect = 0x0009,
        kMCSetControllerAttachedSelect = 0x000A,
        kMCIsControllerAttachedSelect = 0x000B,
        kMCSetControllerPortSelect = 0x000C,
        kMCGetControllerPortSelect = 0x000D,
        kMCSetVisibleSelect = 0x000E,
        kMCGetVisibleSelect = 0x000F,
        kMCGetControllerBoundsRectSelect = 0x0010,
        kMCSetControllerBoundsRectSelect = 0x0011,
        kMCGetControllerBoundsRgnSelect = 0x0012,
        kMCGetWindowRgnSelect = 0x0013,
        kMCMovieChangedSelect = 0x0014,
        kMCSetDurationSelect = 0x0015,
        kMCGetCurrentTimeSelect = 0x0016,
        kMCNewAttachedControllerSelect = 0x0017,
        kMCDrawSelect = 0x0018,
        kMCActivateSelect = 0x0019,
        kMCIdleSelect = 0x001A,
        kMCKeySelect = 0x001B,
        kMCClickSelect = 0x001C,
        kMCEnableEditingSelect = 0x001D,
        kMCIsEditingEnabledSelect = 0x001E,
        kMCCopySelect = 0x001F,
        kMCCutSelect = 0x0020,
        kMCPasteSelect = 0x0021,
        kMCClearSelect = 0x0022,
        kMCUndoSelect = 0x0023,
        kMCPositionControllerSelect = 0x0024,
        kMCGetControllerInfoSelect = 0x0025,
        kMCSetClipSelect = 0x0028,
        kMCGetClipSelect = 0x0029,
        kMCDrawBadgeSelect = 0x002A,
        kMCSetUpEditMenuSelect = 0x002B,
        kMCGetMenuStringSelect = 0x002C,
        kMCSetActionFilterWithRefConSelect = 0x002D,
        kMCPtInControllerSelect = 0x002E,
        kMCInvalidateSelect = 0x002F,
        kMCAdjustCursorSelect = 0x0030,
        kMCGetInterfaceElementSelect = 0x0031,
        kMCGetDoActionsProcSelect = 0x0032,
        kMCAddMovieSegmentSelect = 0x0033,
        kMCTrimMovieSegmentSelect = 0x0034,
        kMusicMediaGetIndexedTunePlayerSelect = 0x0101
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

#endif /* __MOVIES__ */
