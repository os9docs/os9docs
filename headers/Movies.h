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

    //  "kFix1" is defined in FixMath as "fixed1"      // error codes are in Errors.[haa]     // gestalt codes are in Gestalt.[hpa]     enum
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
    // QTFloatDouble is the 64-bit IEEE-754 standard    typedef Float64 QTFloatDouble;
    // QTFloatSingle is the 32-bit IEEE-754 standard    typedef Float32 QTFloatSingle;

    // QTFloatDouble is the 64-bit IEEE-754 standard
    {
    // QTFloatSingle is the 32-bit IEEE-754 standard
        short version;            // which version is this data         short revlevel;           // what version of that codec did this         long vendor;              // whose  codec compressed this data         short numChannels;        // number of channels of sound         short sampleSize;         // number of bits per sample         short compressionID;      // unused. set to zero.         short packetSize;         // unused. set to zero.         UnsignedFixed sampleRate; // sample rate sound is captured at     };
    typedef struct SoundDescription SoundDescription;
    typedef SoundDescription *SoundDescriptionPtr;
    typedef SoundDescriptionPtr *SoundDescriptionHandle;
    // version 1 of the S// total size of SoundDescription including extra data 
    {// sound format 
        // original field// reserved for apple use. set to zero 
        // fixed compress// reserved for apple use. set to zero 
        unsigned long bytesPerPacket;
        unsigned long bytesPerFram// which version is this data 
        unsigned long bytesPerSamp// what version of that codec did this 
        // additional atom based f// whose  codec compressed this data 
    typedef struct SoundDescriptio// number of channels of sound 
    typedef SoundDescriptionV1 *So// number of bits per sample 
    typedef SoundDescriptionV1Ptr // unused. set to zero. 
    struct TextDescription// unused. set to zero. 
    {// sample rate sound is captured at 
        long descSize;   // Total size of TextDescription        long dataFormat; // 'text'
        long resvd1;
        short resvd2;
        short dataRefIndex;
// version 1 of the SoundDescription record
        long displayFlags; // see enum below for flag values
        long textJustification; // Can be: teCenter,teFlush -Default,-Right,-Left
        // original fields
        Rect defaultTextBox;        // Location to place the text within the track bounds        ScrpSTElement defaultStyle; // Default style (struct defined in TextEdit.h)        char defaultFontName[1];    /* Font Name (pascal string - struct extended to fit)
        // fixed compression ratio information
    };
    typedef struct TextDescription TextDescription;
    typedef TextDescription *TextDescriptionPtr;
    typedef TextDescriptionPtr *TextDescriptionHandle;
    stru// additional atom based fields ([long size, long type, some data], repeat)
    {
        long descSize;   // total size of SpriteDescription including extra data         long dataFormat; //          long resvd1;     // reserved for apple use         short resvd2;
        short dataRefIndex;
        long version; // which version is this data         OSType
            decompressorType; // which decompressor to use, 0 for no decompression         long sampleFlags;     // how to interpret samples     };
    typedef struct SpriteDescription SpriteDescription;
    typedef SpriteDescrip// Total size of TextDescription
    typedef SpriteDescrip// 'text'
    struct FlashDescription
    {
        long descSize;
        long dataFormat;
        long resvd1;
        short resvd2;// see enum below for flag values
        short dataRefIndex;
        long version; // which v// Can be: teCenter,teFlush -Default,-Right,-Left
            decompressorType; // which decompressor to use, 0 for no decompression         long flags;
    };// Background color
    typedef struct FlashDescription FlashDescription;
    typedef FlashDescription *FlashD// Location to place the text within the track bounds
    typedef FlashDescriptionPtr *Fla// Default style (struct defined in TextEdit.h)
    struct ThreeDeeDescription
    {
        long descSize;   // total size of ThreeDeeDescription including extra data         long dataFormat; //          long resvd1;     // reserved for apple use         short resvd2;
        short dataRefIndex;
        long version;          // which version is this data         long rendererType;     // which renderer to use, 0 for default         long decompressorType; // which decompressor to use, 0 for default     };
    typedef struct ThreeDeeDescription ThreeDeeDescription;
    typedef ThreeDeeDescription *ThreeDeeDescriptionPtr;
    typedef ThreeDeeDescriptionPtr *ThreeDeeDescriptionHandle;
    struct DataReferenceR// total size of SpriteDescription including extra data 
    {//  
        OSType dataRefTyp// reserved for apple use 
        Handle dataRef;
    };
    typedef struct Dat// which version is this data 
    typedef DataReferenceRecord *DataReferencePtr;
    /*------------------------// which decompressor to use, 0 for no decompression 
      Music Sample Description// how to interpret samples 
    --------------------------*/
    struct MusicDescription
    {
        long descSize;
        long dataFormat; // 'musi' 
        long resvd1;
        short resvd2;
        short dataRefIndex;

        long musicFlags;
        unsigned long headerData[1]; // variable size!     };
    typedef struct Mus// which version is this data 
    typedef MusicDescription *MusicDescriptionPtr;
    typedef MusicDescriptionPt// which decompressor to use, 0 for no decompression 
    enum
    {
        kMusicFlagDontPlay2Soft = 1L << 0,
        kMusicFlagDontSlaveToMovie = 1L << 1
    };

    enum
    {// total size of ThreeDeeDescription including extra data 
        dfDontDisplay = 1//  
            1 << 1,      // reserved for apple use 
            1 << 3,                    // Set text background to movie's background color        dfShrinkTextBoxToFit = 1 << 4, // Compute minimum box to fit the sample        dfScrollIn = 1 << 5,           // Scroll text in until last of text is in view         dfScrollOut = 1 << 6,          /* Scroll text out until last of text is gone (if both
                                          set, scroll in then out)*/
        dfHorizScroll =// which version is this data 
            1 << 7,            // which renderer to use, 0 for default 
                               // which decompressor to use, 0 for default 
        dfContinuousScroll =
            1 << 9,                    // new samples cause previous samples to scroll out         dfFlowHoriz = 1 << 10,         /* horiz scroll text flows in textbox rather than
                                          extend to right */
        dfContinuousKaraoke = 1 << 11, /* ignore begin offset, hilite everything up to
                                          the end offset(karaoke)*/
        dfDropShadow = 1 << 12,        // display text with a drop shadow         dfAntiAlias = 1 << 13,         // attempt to display text anti aliased        dfKeyedText = 1 << 14,         // key the text over background        dfInverseHilite =
            1 << 15,                // Use inverse hiliting rather than using hilite color        dfTextColorHilite = 1 << 16 // changes text color in place of hiliting.     };

    enum
    {
        searchTextDontGoToFoundTime = 1L << 16,
        searchTextDontHiliteFoundText = 1L << 17,
        searchTextOneTrackOnly = 1L << 18,
        searchTextEnabledTracksOnly = 1L << 19
    };

    // use these with the text property routines
    enum// 'musi' 
    {
        // set property parameter / get property parameter        kTextTextHandle = 1,      // Handle / preallocated Handle        kTextTextPtr = 2,         // Pointer        kTextTEStyle = 3,         // TextStyle * / TextStyle *        kTextSelection = 4,       // long [2] / long [2]        kTextBackColor = 5,       // RGBColor * / RGBColor *        kTextForeColor = 6,       // RGBColor * / RGBColor *        kTextFace = 7,            // long / long *        kTextFont = 8,            // long / long *        kTextSize = 9,            // long / long *        kTextAlignment = 10,      // short * / short *        kTextHilite = 11,         // hiliteRecord * / hiliteRecord *        kTextDropShadow = 12,     // dropShadowRecord * / dropShadowRecord *        kTextDisplayFlags = 13,   // long / long *        kTextScroll = 14,         // TimeValue * / TimeValue *        kTextRelativeScroll = 15, // Point *        kTextHyperTextFace = 16,  // hyperTextSetFace * / hyperTextSetFace *        kTextHyperTextColor = 17, // hyperTextSetColor * / hyperTextSetColor *        kTextKeyEntry = 18,       // short        kTextMouseDown = 19,      // Point *        kTextTextBox = 20,        // Rect * / Rect *        kTextEditState = 21,      // short / short *        kTextLength = 22          //       / long *    };

    enum
    {
        k3DMediaRendererEntry = FOUR_CHAR_CODE('rend'),
        k3DMediaRendererName = FOUR_C// variable size! 
        k3DMediaRendererCode = FOUR_CHAR_CODE('rcod')
    };

    // progress messages     enum
    {
        movieProgressOpen = 0,
        movieProgressUpdatePercent = 1,
        movieProgressClose = 2
    };

    // progress operations     enum
    {
        progressOpFlatten = 1,// Don't display the text
        progressOpInsertTrackSegment = 2,
        progressOpInsertMovieSegme// Don't scale text as track bounds grows or shrinks
        progressOpPaste = 4,// Clip update to the textbox
        progressOpAddMovieSelection = 5,
        progressOpCopy = 6,// Set text background to movie's background color
        progressOpCut = 7,// Compute minimum box to fit the sample
        progressOpLoadMovieIntoRam = 8,// Scroll text in until last of text is in view 
        progressOpLoadTrackIntoRam = 9,
        progressOpLoadMediaIntoRam = 10,
        progressOpImportMovie = 11,
        progressOpExportMovie = 12// Scroll text horizontally (otherwise it's vertical)
    };

    enum
    {// new samples cause previous samples to scroll out 
        mediaQualityDraft = 0x0000,
        mediaQualityNormal = 0x0040,
        mediaQualityBetter = 0x0080,
        mediaQualityBest = 0x00C0
    };// display text with a drop shadow 
// attempt to display text anti aliased
    /*****// key the text over background
        Interactive Sprites Support
    *****/// Use inverse hiliting rather than using hilite color
    // QTEventRecord flags    enum// changes text color in place of hiliting. 
    {
        kQTEventPayloadIsQTList = 1L << 0
    };

    struct QTEventRecord
    {
        long version;
        OSType eventType;
        Point where;
        long flags;
        long payloadRefcon; // from here down only present if version >= 2        long param1;
        long param2;
        long param3;
    };// set property parameter / get property parameter
    typedef struct QTEventRecord Q// Handle / preallocated Handle
    typedef QTEventRecord *QTEvent// Pointer
    struct QTAtomSpec// TextStyle * / TextStyle *
    {// long [2] / long [2]
        QTAtomContainer container;// RGBColor * / RGBColor *
        QTAtom atom;// RGBColor * / RGBColor *
    };// long / long *
    typedef struct QTAtomSpec QTAt// long / long *
    typedef QTAtomSpec *QTAtomSpec// long / long *
    struct ResolvedQTEventSpec// short * / short *
    {// hiliteRecord * / hiliteRecord *
        QTAtomSpec actionAtom;// dropShadowRecord * / dropShadowRecord *
        Track targetTrack;// long / long *
        long targetRefCon;// TimeValue * / TimeValue *
    };// Point *
    typedef struct ResolvedQTEvent// hyperTextSetFace * / hyperTextSetFace *
    typedef ResolvedQTEventSpec *R// hyperTextSetColor * / hyperTextSetColor *
// short
    // action constants     enum// Point *
    {// Rect * / Rect *
        kActionMovieSetVolume = 10// short / short *
            1033, // (TimeValue st//       / long *
            1034,                         // (Str255 startTimeName, Str255 endTimeName)         kActionMoviePlaySelection = 1035, // (Boolean selectionOnly)         kActionMovieSetLanguage = 1036,   // (long language)         kActionMovieChanged = 1037,       // no params         kActionMovieRestartAtTime = 1038, // (TimeValue startTime, Fixed rate)         kActionTrackSetVolume = 2048,     // (short volume)         kActionTrackSetBalance = 2049,    // (short balance)         kActionTrackSetEnabled = 2050,    // (Boolean enabled)         kActionTrackSetMatrix = 2051,     // (MatrixRecord matrix)         kActionTrackSetLayer = 2052,      // (short layer)         kActionTrackSetClip = 2053,       // (RgnHandle clip)         kActionTrackSetCursor = 2054,     // (QTATomID cursorID)         kActionTrackSetGraphicsMode =
            2055,                            // (ModifierTrackGraphicsModeRecord graphicsMode)         kActionTrackSetIdleFrequency = 2056, // (long frequency)         kActionTrackSetBassTreble = 2057,    // (short base, short treble)         kActionSpriteSetMatrix = 3072,       // (MatrixRecord matrix)         kActionSpriteSetImageIndex = 3073,   // (short imageIndex)         kActionSpriteSetVisible = 3074,      // (short visible)         kActionSpriteSetLayer = 3075,        // (short layer)         kActionSpriteSetGraphicsMode =
            3076,                             // (ModifierTrackGraphicsModeRecord graphicsMode)         kActionSpritePassMouseToCodec = 3078, // no params         kActionSpriteClickOnCodec = 3079,     // Point localLoc         kActionSpriteTranslate = 3080,        // (Fixed x, Fixed y, Boolean isAbsolute)         kActionSpriteScale = 3081,            // (Fixed xScale, Fixed yScale)         kActionSpriteRotate = 3082,           // (Fixed degrees)         kActionSpriteStretch = 3083,          /* (Fixed p1x, Fixed p1y, Fixed p2x, Fixed p2y,
                                                 Fixed p3x, Fixed p3y, Fixed p4x, Fixed p4y) */
        kActionQTVRSetPanAngle = 4096,        // (float panAngle)         kActionQTVRSetTiltAngle = 4097,       // (float tiltAngle)         kActionQTVRSetFieldOfView = 4098,     // (float fieldOfView)         kActionQTVRShowDefaultView = 4099,    // no params         kActionQTVRGoToNodeID = 4100,         // (UInt32 nodeID)         kActionQTVREnableHotSpot = 4101,      // long ID, Boolean enable         kActionQTVRShowHotSpots = 4102,       // Boolean show         kActionQTVRTranslateObject = 4103,    // float xMove, float yMove         kActionMusicPlayNote =
            5120, /* (long sampleDescIndex, long partNumber, long delay, long pitch,
                     long velocity, long duration) */
        kActionMusicSetController =
            5121,              /* (long sampleDescIndex, long partNumber, long delay, long
    // progress messages 
        kActionCase = 6144,    // [(CaseStatementActionAtoms)]         kActionWhile = 6145,   // [(WhileStatementActionAtoms)]         kActionGoToURL = 6146, // (C string urlLink)         kActionSendQTEventToSprite =
            6147,                               // ([(SpriteTargetAtoms)], QTEventRecord theEvent)         kActionDebugStr = 6148,                 // (Str255 theString)         kActionPushCurrentTime = 6149,          // no params         kActionPushCurrentTimeWithLabel = 6150, // (Str255 theLabel)         kActionPopAndGotoTopTime = 6151,        // no params         kActionPopAndGotoLabeledTime = 6152,    // (Str255 theLabel)         kActionStatusString = 6153,             // (C string theString, long stringTypeFlags)         kActionSendQTEventToTrackObject =
            6154, // ([(TrackObjectTargetAtoms)], QTEventRecord theEvent)         kActionAddChannelSubscription =
            6155,                                /* (Str255 channelName, C string channelsURL, C string
                                                    channelsPictureURL) */
        kActionRemoveChannelSubscription = 6156, // (C string channelsURL)         kActionOpenCustomActionHandler =
            6157, // (long handlerID, ComponentDescription handlerDesc)         kActionDoScript =
    // progress operations 
            6159,                             /* (compressed QTAtomContainer prefixed with eight bytes: long
                                                 compressorType, long decompressedSize) */
        kActionSendAppMessage = 6160,         // (long appMessageID)         kActionLoadComponent = 6161,          // (ComponentDescription handlerDesc)         kActionSetFocus = 6162,               // [(TargetAtoms theObject)]         kActionDontPassKeyEvent = 6163,       // no params         kActionSpriteTrackSetVariable = 7168, // (QTAtomID variableID, float value)         kActionSpriteTrackNewSprite =
            7169,                               /* (QTAtomID spriteID, short imageIndex, MatrixRecord *matrix, short
                                                   visible, short layer, ModifierTrackGraphicsModeRecord
                                                   *graphicsMode, QTAtomID actionHandlingSpriteID) */
        kActionSpriteTrackDisposeSprite = 7170, // (QTAtomID spriteID)         kActionSpriteTrackSetVariableToString =
            7171, // (QTAtomID variableID, C string value)         kActionSpriteTrackConcatVariables =
            7172, /* (QTAtomID firstVariableID, QTAtomID secondVariableID, QTAtomID
                     resultVariableID ) */
        kActionSpriteTrackSetVariableToMovieURL =
            7173, // (QTAtomID variableID, < optional: [(MovieTargetAtoms)] > )         kActionSpriteTrackSetVariableToMovieBaseURL =
            7174, // (QTAtomID variableID, < optional: [(MovieTargetAtoms)] > )         kActionApplicationNumberAndString =
            8192,                                 // (long aNumber, Str255 aString )         kActionQD3DNamedObjectTranslateTo = 9216, // (Fixed x, Fixed y, Fixed z )         kActionQD3DNamedObjectScaleTo =
            9217, // (Fixed xScale, Fixed yScale, Fixed zScale )         kActionQD3DNamedObjectRotateTo =
            9218,                         // (Fixed xDegrees, Fixed yDegrees, Fixed zDegrees )         kActionFlashTrackSetPan = 10240,  // (short xPercent, short yPercent )         kActionFlashTrackSetZoom = 10241, // (short zoomFactor )         kActionFlashTrackSetZoomRect =
            10242,                                // (long left, long top, long right, long bottom )         kActionFlashTrackGotoFrameNumber = 10243, // (long frameNumber )         kActionFlashTrackGotoFrameLabel = 10244,  // (C string frameLabel )         kActionFlashTrackSetFlashVariable =
            10245, /* (C string path, C string name, C string value, Boolean
                      updateFocus) */
        kActionFlashTrackDoButtonActions =
            10246, // (C string path, long buttonID, long transition)         kActionMovieTrackAddChildMovie =
            11264,                               // (QTAtomID childMovieID, C string childMovieURL)         kActionMovieTrackLoadChildMovie = 11265, // (QTAtomID childMovieID)         kActionMovieTrackLoadChildMovieWithQTListParams =
            11266, // (QTAtomID childMovieID, C string qtlistXML)         kActionTextTrackPasteText =
            12288, // (C string theText, long startSelection, long endSelection )         kActionTextTrackSetTextBox =
            12291,                            // (short left, short top, short right, short bottom)         kActionTextTrackSetTextStyle = 12292, // (Handle textStyle)         kActionTextTrackSetSelection =
            12293, // (long startSelection, long endSelection )         kActionTextTrackSetBackgroundColor =
            12294, // (ModifierTrackGraphicsModeRecord backgroundColor )         kActionTextTrackSetForegroundColor =
    // QTEventRecord flags
            12300, /* (long startHighlight, long endHighlight,
                      ModifierTrackGraphicsModeRecord highlightColor ) */
        kActionTextTrackSetDropShadow =
            12301,                               // (Point dropShadow, short transparency )         kActionTextTrackSetDisplayFlags = 12302, // (long flags )         kActionTextTrackSetScroll = 12303,       // (long delay )         kActionTextTrackRelativeScroll = 12304,  // (short deltaX, short deltaY )         kActionTextTrackFindText =
            12305,                                /* (long flags, Str255 theText, ModifierTrackGraphicsModeRecord
                                                     highlightColor ) */
        kActionTextTrackSetHyperTextFace = 12306, // (short index, long fontFace )         kActionTextTrackSetHyperTextColor =
            12307,                           /* (short index, ModifierTrackGraphicsModeRecord highlightColor )
                                              */
        kActionTextTrackKeyEntry = 12308,    // (short character )         kActionTextTrackMouseDown = 12309,   // no params         kActionTextTrackSetEditable = 12310, // (short editState)         kActionListAddElement =
            13312, // (C string parentPath, long atIndex, C string newElementName)         kActionListRemoveElements =
            13313, // (C str// from here down only present if version >= 2
            13314, // (C string elementPath, C string valueString)         kActionListPasteFromXML =
            13315, // (C string xml, C string targetParentPath, long startIndex)         kActionListSetMatchingFromXML =
            13316, // (C string xml, C string targetParentPath)         kActionListSetFromURL =
            13317,                        // (C string url, C string targetParentPath )         kActionListExchangeLists = 13318, // (C string url, C string parentPath)         kActionListServerQuery = 13319    /* (C string url, C string keyValuePairs, long
                                             flags, C string parentPath) */
    };

    enum
    {
        kOperandExpression = 1,
        kOperandConstant = 2,
        kOperandSubscribedToChannel = 3, // C string channelsURL         kOperandUniqueCustomActionHandlerID = 4,
        kOperandCustomActionHandlerIDIsOpen = 5, // long ID         kOperandConnectionSpeed = 6,
        kOperandGMTDay = 7,
        kOperandGMTMonth = 8,
        kOperandGMTYear = 9,
        kOperandGMTHours = 10,
        kOperandGMTMinutes = 11,
        kOperandGMTSeconds = 12,
        kOperandLocalDay = 13,
        kOperandLocalMonth = 14,
        kOperandLocalYear = 15,
    // action constants 
        kOperandLocalMinutes = 17,
        kOperandLocalSeconds = 18,
        kOperandRegisteredForQuickTimePro = // (short movieVolume) 
        kOperandPlatformRunningOn = 20,// (Fixed rate) 
        kOperandQuickTimeVersion = 21,// (long loopingFlags) 
        kOperandComponentVersion =// (TimeValue time) 
            22, // C string type, C string s// (Str255 timeName) 
        kOperandTicks = 24,// no params 
        kOperandMaxLoadedTimeInMovie = 25,// no params 
        kOperandEventParameter = 26, // shor// no params 
        kOperandNetworkStatus = 28,// no params 
        kOperandQuickTimeVersionRegistered = 29, // long version         kOperandSystemVersion = 30,
        kOperandMo// (TimeValue startTime, TimeValue endTime) 
        kOperandMovieRate = 1025,
        kOperandMovieIsLooping = 1026,// (Str255 startTimeName, Str255 endTimeName) 
        kOperandMovieLoopIsPalindrome = 10// (Boolean selectionOnly) 
        kOperandMovieTime = 1028,// (long language) 
        kOperandMovieDuration = 1029,// no params 
        kOperandMovieTimeScale = 1030,// (TimeValue startTime, Fixed rate) 
        kOperandMovieWidth = 1031,// (short volume) 
        kOperandMovieHeight = 1032,// (short balance) 
        kOperandMovieLoadState = 1033,// (Boolean enabled) 
        kOperandMovieTrackCount = 1034,// (MatrixRecord matrix) 
        kOperandMovieIsActive = 1035,// (short layer) 
        kOperandMovieName = 1036,// (RgnHandle clip) 
        kOperandMovieID = 1037,// (QTATomID cursorID) 
        kOperandTrackVolume = 2048,
        kOperandTrackBalance = 2049,// (ModifierTrackGraphicsModeRecord graphicsMode) 
        kOperandTrackEnabled = 2050,// (long frequency) 
        kOperandTrackLayer = 2051,// (short base, short treble) 
        kOperandTrackWidth = 2052,// (MatrixRecord matrix) 
        kOperandTrackHeight = 2053,// (short imageIndex) 
        kOperandTrackDuration = 2054,// (short visible) 
        kOperandTrackName = 2055,// (short layer) 
        kOperandTrackID = 2056,
        kOperandTrackIdleFrequency = 2057,// (ModifierTrackGraphicsModeRecord graphicsMode) 
        kOperandTrackBass = 2058,// no params 
        kOperandTrackTreble = 2059,// Point localLoc 
        kOperandSpriteBoundsLeft = 3072,// (Fixed x, Fixed y, Boolean isAbsolute) 
        kOperandSpriteBoundsTop = 3073,// (Fixed xScale, Fixed yScale) 
        kOperandSpriteBoundsRight = 3074,// (Fixed degrees) 
        kOperandSpriteBoundsBottom = 3075,
        kOperandSpriteImageIndex = 3076,
        kOperandSpriteVisible = 3077,// (float panAngle) 
        kOperandSpriteLayer = 3078,// (float tiltAngle) 
        kOperandSpriteTrackVariable = 3079, //// (float fieldOfView) 
        kOperandSpriteTrackNumImages = 3081,// no params 
        kOperandSpriteID = 3082,// (UInt32 nodeID) 
        kOperandSpriteIndex = 3083,// long ID, Boolean enable 
        kOperandSpriteFirstCornerX = 3084,// Boolean show 
        kOperandSpriteFirstCornerY = 3085,// float xMove, float yMove 
        kOperandSpriteSecondCornerX = 3086,
        kOperandSpriteSecondCornerY = 3087,
        kOperandSpriteThirdCornerX = 3088,
        kOperandSpriteThirdCornerY = 3089,
        kOperandSpriteFourthCornerX = 3090,
        kOperandSpriteFourthCornerY = 3091,
        kOperandSpriteImageRegi// [(CaseStatementActionAtoms)] 
        kOperandSpriteImageRegi// [(WhileStatementActionAtoms)] 
        kOperandSpriteTrackSpri// (C string urlLink) 
        kOperandQTVRPanAngle = 4096,
        kOperandQTVRTiltAngle = 4097,// ([(SpriteTargetAtoms)], QTEventRecord theEvent) 
        kOperandQTVRFieldOfView = 4098,// (Str255 theString) 
        kOperandQTVRNodeID = 4099,// no params 
        kOperandQTVRHotSpotsVisible = 4100,// (Str255 theLabel) 
        kOperandQTVRViewCenterH = 4101,// no params 
        kOperandQTVRViewCenterV = 4102,// (Str255 theLabel) 
        kOperandMouseLocalHLoc = 5120, // [Targe// (C string theString, long stringTypeFlags) 
        kOperandTextTrackCopyText = 6145, // long startSelection, long endSelection         kOperandTextTrackStartSelection = 6146,
        kOperandTe// ([(TrackObjectTargetAtoms)], QTEventRecord theEvent) 
        kOperandTextTrackTextBoxLeft = 6148,
        kOperandTextTrackTextBoxTop = 6149,
        kOperandTextTrackTextBoxRight = 6150,
        kOperandTextTrackTextBoxBottom = 6151,// (C string channelsURL) 
        kOperandTextTrackTextLength = 6152,
        kOperandLi// (long handlerID, ComponentDescription handlerDesc) 
            7169,                           // (C string parentPath, long index)         kOperandListGetElementValue = 7170, // (C string elementPath)         kOperandListCopyToXML =
            7171, // (long scriptTypeFlags, CString command, CString arguments) 
                                              caseSensitive, Boolan diacSensitive) */
        kOperandStringSubString =
            10242,                   // (C string text, long offset, long length)         kOperandStringConcat = 10243 // (C string aText, C string bText)     };
// (long appMessageID) 
    enum// (ComponentDescription handlerDesc) 
    {// [(TargetAtoms theObject)] 
        kFirstMovieAction = kActionMovieSetVol// no params 
        kLastMovieAction = kActionMovieRestart// (QTAtomID variableID, float value) 
        kFirstTrackAction = kActionTrackSetVolume,
        kLastTrackAction = kActionTrackSetBassTreble,
        kFirstSpriteAction = kActionSpriteSetMatrix,
        kLastSpriteAction = kActionSpriteStretch,
        kFirstQTVRAction = kActionQTVRSetPanAngl// (QTAtomID spriteID) 
        kLastQTVRAction = kActionQTVRTranslateObject,
        kFirstMusi// (QTAtomID variableID, C string value) 
        kLastMusicAction = kActionMusicSetController,
        kFirstSystemAction = kActionCase,
        kLastSystemAction = kActionDontPassKeyEvent,
        kFirstSpriteTrackAction = kActionSpriteTrackSetVariable,
        kLastSprit// (QTAtomID variableID, < optional: [(MovieTargetAtoms)] > ) 
        kFirstApplicationAction = kActionApplicationNumberAndString,
        kLastAppli// (QTAtomID variableID, < optional: [(MovieTargetAtoms)] > ) 
        kFirstQD3DNamedObjectAction = kActionQD3DNamedObjectTranslateTo,
        kLastQD3DNamedObjectAction = kActionQD3DNa// (long aNumber, Str255 aString ) 
        kFirstFlashTrackAction = kActionFlashTrack// (Fixed x, Fixed y, Fixed z ) 
        kLastFlashTrackAction = kActionFlashTrackDoButtonActions,
        kFirstMovi// (Fixed xScale, Fixed yScale, Fixed zScale ) 
        kLastMovieTrackAction = kActionMovieTrackLoadChildMovieWithQTListParams,
        kFirstTextTrackAction = kActionTex// (Fixed xDegrees, Fixed yDegrees, Fixed zDegrees ) 
        kLastTextTrackAction = kActionText// (short xPercent, short yPercent ) 
        kFirstMultiTargetAction = kActionL// (short zoomFactor ) 
        kLastMultiTargetAction = kActionListServerQuery,
        kFirstAction = kFirstMovieAction,// (long left, long top, long right, long bottom ) 
        kLastAction = kLastMultiTargetAction// (long frameNumber ) 
    };// (C string frameLabel ) 

    // target atom types    enum
    {
        kTargetMovie = FOUR_CHAR_CODE('moov'),       // no data         kTargetMovieName = FOUR_CHAR_CODE('mona'),   // (PString movieName)         kTargetMovieID = FOUR_CHAR_CODE('moid'),     // (long movieID)         kTargetRootMovie = FOUR_CHAR_CODE('moro'),   // no data         kTargetParentMovie = FOUR_CHAR_CODE('mopa'), // no data         kTargetChildMovieTrackName =
            FOUR_CH// (C string path, long buttonID, long transition) 
            FOUR_CHAR_CODE('moti'), // (long childMovieTrackID)         kTargetChildMovieTrackIndex =
            FOUR_CHAR_CODE('motx'), // (long chil// (QTAtomID childMovieID, C string childMovieURL) 
            FOUR_CHAR_CODE('momn'),              // (QTAtomID childMovieID) 
            FOUR_CHAR_CODE('nana'),                          // (CString objectName)         kTargetCurrentQTEventParams = FOUR_CHAR_CODE('evpa') // no data     };
// (QTAtomID childMovieID, C string qtlistXML) 
    // action container atom types    enum
    {// (C string theText, long startSelection, long endSelection ) 
        kQTEventType = FOUR_CHAR_CODE('evnt'),
        kAction = FOUR_CHAR_CODE('actn'),// (short left, short top, short right, short bottom) 
        kWhichAction = FOUR_CHAR_CODE('whic'),// (Handle textStyle) 
        kActionParameter = FOUR_CHAR_CODE('parm'),
        kActionTarg// (long startSelection, long endSelection ) 
        kActionFlags = FOUR_CHAR_CODE('flag'),
        kActionPara// (ModifierTrackGraphicsModeRecord backgroundColor ) 
        kActionParameterMaxValue = FOUR_CHAR_CODE('maxv'),
        kActionListAtomType = FOUR_CHAR_CODE('// (ModifierTrackGraphicsModeRecord foregroundColor ) 
        kExpressionContainerAtomType = FOUR_CH// (long fontFace ) 
        kConditionalAtomType = FOUR_CHAR_CODE(// (long fontID ) 
        kOperatorAtomType = FOUR_CHAR_CODE('op// (long fontSize ) 
        kOperandAtomType = FOUR_CHAR_CODE('opr// (short alignment ) 
        kCommentAtomType = FOUR_CHAR_CODE('why '),
        kCustomActionHandler = FOUR_CHAR_CODE('cust'),
        kCustomHandlerID = FOUR_CHAR_CODE('id  '),
        kCustomHandlerDesc = FOUR_CHAR_CODE('desc'),
        kQTEventRecordAtomType = FOUR_CHAR_CODE('// (Point dropShadow, short transparency ) 
    };// (long flags ) 
// (long delay ) 
    // QTEvent types     enum// (short deltaX, short deltaY ) 
    {
        kQTEventMouseClick = FOUR_CHAR_CODE('clik'),
        kQTEventMouseClickEnd = FOUR_CHAR_CODE('cend'),
        kQTEventMouseClickEndTriggerButton = FOUR_// (short index, long fontFace ) 
        kQTEventMouseEnter = FOUR_CHAR_CODE('entr'),
        kQTEventMouseExit = FOUR_CHAR_CODE('exit'),
        kQTEventMouseMoved = FOUR_CHAR_CODE('move'),
        kQTEventFrameLoaded = FOUR_CHAR_CODE(// (short character ) 
        kQTEventIdle = FOUR_CHAR_CODE('idle')// no params 
        kQTEventKey =// (short editState) 
            FOUR_CHAR_CODE('key '), /* qtevent.param1 = key, qtevent.param2 =
                   // (C string parentPath, long atIndex, C string newElementName) 
        kQTEventMovieLoaded = FOUR_CHAR_CODE('load'),
        kQTEventReq// (C string parentPath, long startIndex, long endIndex) 
        kQTEventListReceived = FOUR_CHAR_CODE('list')
    };// (C string elementPath, C string valueString) 

    // flags for th// (C string xml, C string targetParentPath, long startIndex) 
    {
        kActionFlag// (C string xml, C string targetParentPath) 
        kActionFlagParameterWrapsAround = 1L << 2,
        kActionFlagActionIsToggle = 1L << // (C string url, C string targetParentPath ) 
    };// (C string url, C string parentPath) 

    // flags for stringTypeFlags field of the QTStatusStringRecord     enum
    {
        kStatusStringIsURLLink = 1L << 1,
        kStatusStringIsStreamingStatus = 1L << 2,
        kStatusHasCodeNumber =
            1L << 3, // high 16 bits of stringTypeFlags is error code number        kStatusIsError = 1L << 4
    };
// C string channelsURL 
    // flags for scriptTypeFlags field of the QTDoScriptRecord    enum
    {// long ID 
        kScriptIsUnknownType = 1L << 0,
        kScriptIsJavaScript = 1L << 1,
        kScriptIsLingoEvent = 1L << 2,
        kScriptIsVBEvent = 1L << 3,
        kScriptIsProjectorCommand = 1L << 4,
        kScriptIsAppleScript = 1L << 5
    };

    // flags for CheckQuickTimeRegistration routine    enum
    {
        kQTRegistrationDialogTimeOutFlag = 1 << 0,
        kQTRegistrationDialogShowDialog = 1 << 1,
        kQTRegistrationDialogForceDialog = 1 << 2
    };

    // constants for kOperatorAtomType IDs (operator types)    enum
    {
        kOperato// C string type, C string subType, C string manufacturer 
        kOperatorSubtract = FOUR_CHAR_CODE('sub '),
        kOperatorMultiply = FOUR_CHAR_CODE('mult'),
        kOperatorDivide = FOUR_CHAR_CODE('div '),
        kOperatorOr = FOUR_CHAR_CODE(// short index 
        kOperatorAnd = FOUR_CHAR_CODE('and '),
        kOperatorNot = FOUR_CHAR_CODE('not '),
        kOperatorLessThan = FOUR_CHAR_CODE('<   '// long version 
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

    // constants for kOperandPlatformRunningOn    enum
    {
        kPlatformMacintosh = 1,
        kPlatformWindows = 2
    };

    // flags for kOperandSystemVersion    enum
    {
        kSystemIsWindows9x = 0x00010000,
        kSystemIsWindowsNT = 0x00020000
    };

    // constants for MediaPropertiesAtom    enum
    {
        kMediaPropertyNonLinearAtomType = FOUR_CHAR_CODE('nonl'),
        kMediaPropertyHasActions = 105
    };

    typedef CALLBACK_API(OSErr, MovieRgnCoverProcPtr)(Movie theMovie,
                                                      RgnHandle changedRgn,
                                                      long refcon);
    typedef CALLBACK_API(OSErr, MovieProgressProcPtr)(Movie theMovie, short message,
                                                      short whatOperation,
                                            // [QTAtomID variableID] 
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
    typedef CALLBACK_API(OSErr, MovieExecuteWiredAc// short x, short y 
        Movie theMovie, void *refcon, long flags, QTAtomContainer wiredActions);
    typedef CALLBACK_API(void, MoviePrePrerollCompleteProcPtr)(Movie theMovie,
                                                               OSErr prerollErr,
                                                               void *refcon);
    typedef CALLBACK_API(void, MoviesErrorProcPtr)(OSErr theErr, long refcon);
    typedef STACK_UPP_TYPE(MovieRgnCoverProcPtr) MovieRgnCoverUPP;
    typedef STACK_UPP_TYPE(MovieProgressProcPtr) MovieProgressUPP;
    typedef STACK_UPP_TYPE(MovieDrawingCompleteProcPtr) MovieDrawingCompleteUPP;
    typedef STACK_UPP_TYPE(TrackTransfe// [TargetAtoms aTrack] 
    typedef STACK_UPP_TYPE(GetMovieProc// [TargetAtoms aTrack] 
    typedef STACK_UPP_TYPE(MoviePreview// [short modKeys, char asciiValue] 
    typedef STACK_UPP_TYPE(TextMediaPro// [short min, short max] 
    typedef STACK_UPP_TYPE(ActionsProcP// [(TargetAtoms theObject)] 
    typedef STACK_UPP_TYPE(DoMCActionPr// [(TargetAtoms theObject)] 
    typedef STACK_UPP_TYPE(MovieExecuteWiredActionsProcPtr)
        MovieExecuteWiredActionsUPP;// long startSelection, long endSelection 
    typedef STACK_UPP_TYPE(MoviePrePrerollCompleteProcPtr)
        MoviePrePrerollCompleteUPP;
    typedef STACK_UPP_TYPE(MoviesErrorProcPtr) MoviesErrorUPP;
    typedef ComponentInstance MediaHandler;
    typedef ComponentInstance DataHandler;
    typedef Component MediaHandlerComponent;
    typedef Component DataHandlerComponent;
    typedef ComponentResult HandlerError;// (C string parentPath) 
    // TimeBase and TimeRecord moved to MacTypes.h     typedef UInt32 TimeBaseFlags;
    enum// (C string parentPath, long index) 
    {// (C string elementPath) 
        loopTimeBase = 1,
        palindromeLoopTimeBase = 2,// (C string parentPath, long startIndex, long endIndex) 
        maintainTimeBaseZero = 4// float x    
    };// float x    
// float x    
    struct CallBackRecord// float x    
    {// float y, float x   
        long data[1];// float x 
    };// float x 
    typedef struct CallBackRecord CallBackR// float x 
    typedef CallBackRecord *QTCallBack;// float x 
    // CallBack equates     typedef UInt16 // float x 
    enum// [CString path, CString name] 
    {// (C string text) 
        triggerTimeFwd = 0x0001, // when curTime exceeds triggerTime going forward         triggerTimeBwd =
            0x0002, // when curTime exceeds triggerTime going backwards         triggerTimeEither =
            0x0003,                // when curTime exceeds triggerTime going either direction         triggerRateLT = 0x0004,    // when rate changes to less than trigger value         triggerRateGT = 0x0008,    // when rate changes to greater than trigger value         triggerRateEqual = 0x0010, // when rate changes to equal trigger value         triggerRateLTE = triggerRateLT | triggerRateEqual,
        triggerRateGTE = triggerRateG// (C string text, long offset, long length) 
        triggerRateNotEqual = trigger// (C string aText, C string bText) 
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
        qtcbNeedsRateChanges = 1, // wants to know about rate changes         qtcbNeedsTimeChanges = 2, // wants to know about time changes         qtcbNeedsStartStopChanges =
            4 // wants to know when TimeBase start/stop is changed    };

    struct QTCallBackHeader
    {
        long callBackFlags;
    // target atom types
        SInt8 qtPrivate[40];
    };
    typedef struct QTCallBackHeader QTCallBackHeader;// no data 
    typedef CALLBACK_API(void, QTSyncTaskProcPtr)(voi// (PString movieName) 
    typedef STACK_UPP_TYPE(QTSyncTaskProcPtr) QTSyncT// (long movieID) 
    struct QTSyncTaskRecord// no data 
    {// no data 
        void *qLink;
        QTSyncTaskUPP proc;// (PString childMovieTrackName) 
    };
    typedef struct QTSyncTaskRecord // (long childMovieTrackID) 
    typedef QTSyncTaskRecord *QTSyncTaskPtr;
    enum// (long childMovieTrackIndex) 
    {
        keepInRam = 1 << 0,    // load and make non-purgabl// (PString childMovieName) 
            1 << 3, //    load track edits into ram for pla// (long childMovieID) 
            1 << 4 //    load track edits into ram for play// (PString trackName) 
// (long trackID) 
    enum// (OSType trackType) 
    {// (long trackIndex) 
        newMovieActive = 1 << 0,// (PString spriteName) 
        newMovieDontResolveDataRefs = 1 << 1,// (QTAtomID spriteID) 
        newMovieDontAskUnresolvedDataRefs = 1 << 2,// (short spriteIndex) 
        newMovieDontAutoAlternates = 1 << 3,
        newMovieDontUpdateForeBackPointers = 1 << 4,// (CString objectName) 
        newMovieDontAutoUpdateClock = 1 << 5,// no data 
        newMovieAsyncOK = 1 << 8,
        newMovieIdleImportOK = 1 << 10
    // action container atom types

    // track usage bits     enum
    {
        trackUsageInMovie = 1 << 1,
        trackUsageInPreview = 1 << 2,
        trackUsageInPoster = 1 << 3
    };

    // Add/GetMediaSample flags     enum
    {
        mediaSampleNotSync =
            1 << 0,                    // sample is not a sync sample (eg. is frame differenced         mediaSampleShadowSync = 1 << 1 // sample is a shadow sync     };

    enum
    {
        pasteInParallel = 1 << 0,
        showUserSettingsDialog = 1 << 1,
        movieToFileOnlyExport = 1 << 2,
        movieFileSpecValid = 1 << 3
    };

    enum
    // QTEvent types 
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

    // flags for the kActionFlags atom 
    enum
    {
        flattenAddMovieToDataFork = 1L << 0,
        flattenActiveTracksOnly = 1L << 2,
        flattenDontInterleaveFlatten = 1L << 3,
        flattenFSSpecPtrIsDataRefRecordPtr = 1L << 4,
        flattenCompressMovieResource = 1L << 5,
    // flags for stringTypeFlags field of the QTStatusStringRecord 
    };

    typedef unsigned long movieFlattenFlagsEnum;
    enum
    {
        movieInDataFo// high 16 bits of stringTypeFlags is error code number

    enum
    {
    // flags for scriptTypeFlags field of the QTDoScriptRecord

    enum
    {
        movieScrapDontZeroScrap = 1 << 0,
        movieScrapOnlyPutMovie = 1 << 1
    };

    enum
    {
        dataRefSelfReference = 1 << 0,
    // flags for CheckQuickTimeRegistration routine
    };

    typedef unsigned long dataRefAttributesFlags;
    enum
    {
        kMovieAnchorDataRefIsDefault =
            1 << 0 // data ref returned is movie default data ref     };
// constants for kOperatorAtomType IDs (operator types)
    enum
    {
        hintsScrubMode =
            1 << 0, // mask == && (if flags == scrub on, flags != scrub off)         hintsLoop = 1 << 1,
        hintsDontPurge = 1 << 2,
        hintsUseScreenBuffer = 1 << 5,
        hintsAllowInterlace = 1 << 6,
        hintsUseSoundInterp = 1 << 7,
        hintsHighQuality = 1 << 8, // slooooow         hintsPalindrome = 1 << 9,
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

    // constants for kOperandPlatformRunningOn
    enum
    {
        mediaHandlerFlagBaseClient = 1
    };

    typedef unsigned long mediaHandlerFlagsEnum;
    // flags for kOperandSystemVersion
    {
        movieTrackMediaType = 1 << 0,
        movieTrackCharacteristic = 1 << 1,
        movieTrackEnabledOnly = 1 << 2
    };

    // constants for MediaPropertiesAtom
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
    CheckQuickTimeRegistration(void *registrationKey, long flags)
        THREEWORDINLINE(0x303C, 0x02DA, 0xAAAA);

    /**
     *  EnterMovies()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    EnterMovies(void) TWOWORDINLINE(0x7001, 0xAAAA);

    /**
     *  ExitMovies()
     *
// TimeBase and TimeRecord moved to MacTypes.h 
     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    ExitMovies(void) TWOWORDINLINE(0x7002, 0xAAAA);

    /*************************
     * Error Routines
     **************************/

    /**
     *  GetMoviesError()
    // CallBack equates 

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in ve// when curTime exceeds triggerTime going forward 
     *    Windows:          in qtmlClient.lib 3.0 and later
     */// when curTime exceeds triggerTime going backwards 
    OSErr
    GetMoviesError(void) TWOWORDINL// when curTime exceeds triggerTime going either direction 
// when rate changes to less than trigger value 
    /**// when rate changes to greater than trigger value 
     *  ClearMoviesStickyError()// when rate changes to equal trigger value 
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    ClearMoviesStickyError(void) THREEWORDINLINE(0x303C, 0x00DE, 0xAAAA);

    /**
     *  GetMoviesStickyError()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    GetMoviesStickyError(void) TWOWORDINLINE(0x7004, 0xAAAA);

    /**
     *  SetMoviesErrorProc()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void// wants to know about rate changes 
    SetMoviesErrorProc(MoviesError// wants to know about time changes 
        THREEWORDINLINE(0x303C, 0x00EF, 0xAAAA);
// wants to know when TimeBase start/stop is changed
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
    MoviesTask(Movie theMovie, long maxMilliSecToUse) TWOWORDINLINE(0x7005, 0xAAAA);

    /**
     *  PrerollMovie()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in// load and make non-purgable
     *    \mac_os_x         in // mark as purgable
     *    Windows:          in // empty those handles
     */
    OSErr//    load track edits into ram for playing forward
    PrerollMovie(Movie theMovie, TimeValue time, Fixed Rate)
        TWOWORDINLI//    load track edits into ram for playing in reverse

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
                    MoviePrePrerollCompleteUPP proc, void *refcon)
        THREEWORDINLINE(0x303C, 0x02F7, 0xAAAA);
// track usage bits 
    /**
     *  AbortPrePrerollMovie()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
    // Add/GetMediaSample flags 
     */
    void
    AbortPrePrerollMovie(Movie m, OSErr err)
        THREEWORDINLINE(0x303C, 0x02F8,// sample is not a sync sample (eg. is frame differenced 
// sample is a shadow sync 
    /**
     *  LoadMovieIntoRam()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    LoadMovieIntoRam(Movie theMovie, TimeValue time, TimeValue duration, long flags)
        TWOWORDINLINE(0x7007, 0xAAAA);

    /**
     *  LoadTrackIntoRam()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    LoadTrackIntoRam(Track theTrack, TimeValue time, TimeValue duration, long flags)
        THREEWORDINLINE(0x303C, 0x016E, 0xAAAA);

    /**
     *  LoadMediaIntoRam()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    LoadMediaIntoRam(Media theMedia, TimeValue time, TimeValue duration, long flags)
        TWOWORDINLINE(0x7008, 0xAAAA);

    /**
     *  SetMovieActive()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in Ca// magic res ID 
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SetMovieActive(Movie theMovie, B// usually centered 
// usually only scales down 
    /**// give me a badge 
     *  GetMovieActive()// don't show controller 
     *// gimme a frame 

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    Boolean
    GetMovieActive(Movie theMovie) TWOWORDINLINE(0x700A, 0xAAAA);

    /*************************
     * calls for playing movies, previews, posters
     **************************/
    /**
     *  StartMovie()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x// data ref returned is movie default data ref 
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    StartMovie(Movie theMovie) TWOWORDINLINE(0x700B, 0xAAAA);

    /**// mask == && (if flags == scrub on, flags != scrub off) 
     *  StopMovie()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in vers// slooooow 
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    StopMovie(Movie theMovie) TWOWORDINLINE(0x700C, 0xAAAA);

    /**
     *  GoToBeginningOfMovie()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    GoToBeginningOfMovie(Movie theMovie) TWOWORDINLINE(0x700D, 0xAAAA);

    /**
     *  GoToEndOfMovie()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    GoToEndOfMovie(Movie theMovie) TWOWORDINLINE(0x700E, 0xAAAA);

    /**
     *  IsMovieDone()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    Boolean
    IsMovieDone(Movie theMovie) THREEWORDINLINE(0x303C, 0x00DD, 0xAAAA);

    /**
     *  GetMoviePreviewMode()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    Boolean
    GetMoviePreviewMode(Movie theMovie) TWOWORDINLINE(0x700F, 0xAAAA);

    /**
     *  SetMoviePreviewMode()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SetMoviePreviewMode(Movie theMovie, Boolean usePreview)
        TWOWORDINLINE(0x7010, 0xAAAA);

    /**
     *  ShowMoviePoster()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    ShowMoviePoster(Movie theMovie) TWOWORDINLINE(0x7011, 0xAAAA);

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
                     long refcon) THREEWORDINLINE(0x303C, 0x00F2, 0xAAAA);

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
    GetMovieTimeBase(Movie theMovie) TWOWORDINLINE(0x7012, 0xAAAA);

    /**
     *  SetMovieMasterTimeBase()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SetMovieMasterTimeBase(Movie theMovie, TimeBase tb, const TimeRecord *slaveZero)
        THREEWORDINLINE(0x303C, 0x0167, 0xAAAA);

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
                        const TimeRecord *slaveZero)
        THREEWORDINLINE(0x303C, 0x0168, 0xAAAA);

    /**
     *  GetMovieGWorld()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    GetMovieGWorld(Movie theMovie, CGrafPtr *port, GDHandle *gdh)
        TWOWORDINLINE(0x7015, 0xAAAA);

    /**
     *  SetMovieGWorld()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SetMovieGWorld(Movie theMovie, CGrafPtr port, GDHandle gdh)
        TWOWORDINLINE(0x7016, 0xAAAA);

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
                                MovieDrawingCompleteUPP proc, long refCon)
        THREEWORDINLINE(0x303C, 0x01DE, 0xAAAA);

    /**
     *  GetMovieNaturalBoundsRect()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    GetMovieNaturalBoundsRect(Movie theMovie, Rect *naturalBounds)
        THREEWORDINLINE(0x303C, 0x022C, 0xAAAA);

    /**
     *  GetNextTrackForCompositing()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    Track
    GetNextTrackForCompositing(Movie theMovie, Track theTrack)
        THREEWORDINLINE(0x303C, 0x01FA, 0xAAAA);

    /**
     *  GetPrevTrackForCompositing()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    Track
    GetPrevTrackForCompositing(Movie theMovie, Track theTrack)
        THREEWORDINLINE(0x303C, 0x01FB, 0xAAAA);

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
                   TrackTransferUPP proc, long refCon)
        THREEWORDINLINE(0x303C, 0x009D, 0xAAAA);

    /**
     *  GetMoviePict()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    PicHandle
    GetMoviePict(Movie theMovie, TimeValue time) TWOWORDINLINE(0x701D, 0xAAAA);

    /**
     *  GetTrackPict()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    PicHandle
    GetTrackPict(Track theTrack, TimeValue time) TWOWORDINLINE(0x701E, 0xAAAA);

    /**
     *  GetMoviePosterPict()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    PicHandle
    GetMoviePosterPict(Movie theMovie) THREEWORDINLINE(0x303C, 0x00F7, 0xAAAA);

    // called between Begin & EndUpdate     /**
     *  UpdateMovie()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    UpdateMovie(Movie theMovie) TWOWORDINLINE(0x701F, 0xAAAA);

    /**
     *  InvalidateMovieRegion()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    InvalidateMovieRegion(Movie theMovie, RgnHandle invalidRgn)
        THREEWORDINLINE(0x303C, 0x022A, 0xAAAA);

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
    GetMovieBox(Movie theMovie, Rect *boxRect)
        THREEWORDINLINE(0x303C, 0x00F9, 0xAAAA);

    /**
     *  SetMovieBox()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SetMovieBox(Movie theMovie, const Rect *boxRect)
        THREEWORDINLINE(0x303C, 0x00FA, 0xAAAA);

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
    GetMovieDisplayClipRgn(Movie theMovie) THREEWORDINLINE(0x303C, 0x00FC, 0xAAAA);

    /**
     *  SetMovieDisplayClipRgn()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SetMovieDisplayClipRgn(Movie theMovie, RgnHandle theClip)
        THREEWORDINLINE(0x303C, 0x00FD, 0xAAAA);

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
    GetMovieClipRgn(Movie theMovie) THREEWORDINLINE(0x303C, 0x0100, 0xAAAA);

    /**
     *  SetMovieClipRgn()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SetMovieClipRgn(Movie theMovie, RgnHandle theClip)
        THREEWORDINLINE(0x303C, 0x0101, 0xAAAA);

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
    GetTrackClipRgn(Track theTrack) THREEWORDINLINE(0x303C, 0x0102, 0xAAAA);

    /**
     *  SetTrackClipRgn()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SetTrackClipRgn(Track theTrack, RgnHandle theClip)
        THREEWORDINLINE(0x303C, 0x0103, 0xAAAA);

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
    GetMovieDisplayBoundsRgn(Movie theMovie)
        THREEWORDINLINE(0x303C, 0x00FB, 0xAAAA);

    /**
     *  GetTrackDisplayBoundsRgn()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    RgnHandle
    GetTrackDisplayBoundsRgn(Track theTrack)
        THREEWORDINLINE(0x303C, 0x0112, 0xAAAA);

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
    GetMovieBoundsRgn(Movie theMovie) THREEWORDINLINE(0x303C, 0x00FE, 0xAAAA);

    /**
     *  GetTrackMovieBoundsRgn()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    RgnHandle
    GetTrackMovieBoundsRgn(Track theTrack) THREEWORDINLINE(0x303C, 0x00FF, 0xAAAA);

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
    GetTrackBoundsRgn(Track theTrack) THREEWORDINLINE(0x303C, 0x0111, 0xAAAA);

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
    GetTrackMatte(Track theTrack) THREEWORDINLINE(0x303C, 0x0115, 0xAAAA);

    /**
     *  SetTrackMatte()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SetTrackMatte(Track theTrack, PixMapHandle theMatte)
        THREEWORDINLINE(0x303C, 0x0116, 0xAAAA);

    /**
     *  DisposeMatte()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    DisposeMatte(PixMapHandle theMatte) THREEWORDINLINE(0x303C, 0x014A, 0xAAAA);

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
    SetMovieVideoOutput(Movie theMovie, ComponentInstance vout)
        THREEWORDINLINE(0x303C, 0x0340, 0xAAAA);

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
    NewMovie(long flags) THREEWORDINLINE(0x303C, 0x0187, 0xAAAA);

    /**
     *  PutMovieIntoHandle()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    PutMovieIntoHandle(Movie theMovie, Handle publicMovie)
        TWOWORDINLINE(0x7022, 0xAAAA);

    /**
     *  PutMovieIntoDataFork()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
    // called between Begin & EndUpdate 
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    PutMovieIntoDataFork(Movie theMovie, short fRefNum, long offset, long maxSize)
        THREEWORDINLINE(0x303C, 0x01B4, 0xAAAA);

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
                           unsigned long maxSize)
        THREEWORDINLINE(0x303C, 0x02EA, 0xAAAA);

    /**
     *  DisposeMovie()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    DisposeMovie(Movie theMovie) TWOWORDINLINE(0x7023, 0xAAAA);

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
    GetMovieCreationTime(Movie theMovie) TWOWORDINLINE(0x7026, 0xAAAA);

    /**
     *  GetMovieModificationTime()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    unsigned long
    GetMovieModificationTime(Movie theMovie) TWOWORDINLINE(0x7027, 0xAAAA);

    /**
     *  GetMovieTimeScale()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    TimeScale
    GetMovieTimeScale(Movie theMovie) TWOWORDINLINE(0x7029, 0xAAAA);

    /**
     *  SetMovieTimeScale()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SetMovieTimeScale(Movie theMovie, TimeScale timeScale)
        TWOWORDINLINE(0x702A, 0xAAAA);

    /**
     *  GetMovieDuration()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    TimeValue
    GetMovieDuration(Movie theMovie) TWOWORDINLINE(0x702B, 0xAAAA);

    /**
     *  GetMovieRate()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    Fixed
    GetMovieRate(Movie theMovie) TWOWORDINLINE(0x702C, 0xAAAA);

    /**
     *  SetMovieRate()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SetMovieRate(Movie theMovie, Fixed rate) TWOWORDINLINE(0x702D, 0xAAAA);

    /**
     *  GetMoviePreferredRate()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    Fixed
    GetMoviePreferredRate(Movie theMovie) THREEWORDINLINE(0x303C, 0x00F3, 0xAAAA);

    /**
     *  SetMoviePreferredRate()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SetMoviePreferredRate(Movie theMovie, Fixed rate)
        THREEWORDINLINE(0x303C, 0x00F4, 0xAAAA);

    /**
     *  GetMoviePreferredVolume()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    short
    GetMoviePreferredVolume(Movie theMovie) THREEWORDINLINE(0x303C, 0x00F5, 0xAAAA);

    /**
     *  SetMoviePreferredVolume()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SetMoviePreferredVolume(Movie theMovie, short volume)
        THREEWORDINLINE(0x303C, 0x00F6, 0xAAAA);

    /**
     *  GetMovieVolume()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    short
    GetMovieVolume(Movie theMovie) TWOWORDINLINE(0x702E, 0xAAAA);

    /**
     *  SetMovieVolume()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SetMovieVolume(Movie theMovie, short volume) TWOWORDINLINE(0x702F, 0xAAAA);

    /**
     *  GetMovieMatrix()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    GetMovieMatrix(Movie theMovie, MatrixRecord *matrix)
        TWOWORDINLINE(0x7031, 0xAAAA);

    /**
     *  SetMovieMatrix()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SetMovieMatrix(Movie theMovie, const MatrixRecord *matrix)
        TWOWORDINLINE(0x7032, 0xAAAA);

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
                        TimeValue *previewDuration) TWOWORDINLINE(0x7033, 0xAAAA);

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
                        TimeValue previewDuration) TWOWORDINLINE(0x7034, 0xAAAA);

    /**
     *  GetMoviePosterTime()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    TimeValue
    GetMoviePosterTime(Movie theMovie) TWOWORDINLINE(0x7035, 0xAAAA);

    /**
     *  SetMoviePosterTime()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SetMoviePosterTime(Movie theMovie, TimeValue posterTime)
        TWOWORDINLINE(0x7036, 0xAAAA);

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
                      TimeValue *selectionDuration) TWOWORDINLINE(0x7037, 0xAAAA);

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
                      TimeValue selectionDuration) TWOWORDINLINE(0x7038, 0xAAAA);

    /**
     *  SetMovieActiveSegment()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SetMovieActiveSegment(Movie theMovie, TimeValue startTime, TimeValue duration)
        THREEWORDINLINE(0x303C, 0x015C, 0xAAAA);

    /**
     *  GetMovieActiveSegment()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    GetMovieActiveSegment(Movie theMovie, TimeValue *startTime, TimeValue *duration)
        THREEWORDINLINE(0x303C, 0x015D, 0xAAAA);

    /**
     *  GetMovieTime()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    TimeValue
    GetMovieTime(Movie theMovie, TimeRecord *currentTime)
        TWOWORDINLINE(0x7039, 0xAAAA);

    /**
     *  SetMovieTime()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SetMovieTime(Movie theMovie, const TimeRecord *newtime)
        TWOWORDINLINE(0x703C, 0xAAAA);

    /**
     *  SetMovieTimeValue()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SetMovieTimeValue(Movie theMovie, TimeValue newtime)
        TWOWORDINLINE(0x703D, 0xAAAA);

    /**
     *  GetMovieUserData()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    UserData
    GetMovieUserData(Movie theMovie) TWOWORDINLINE(0x703E, 0xAAAA);

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
    GetMovieTrackCount(Movie theMovie) TWOWORDINLINE(0x703F, 0xAAAA);

    /**
     *  GetMovieTrack()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    Track
    GetMovieTrack(Movie theMovie, long trackID) TWOWORDINLINE(0x7040, 0xAAAA);

    /**
     *  GetMovieIndTrack()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    Track
    GetMovieIndTrack(Movie theMovie, long index)
        THREEWORDINLINE(0x303C, 0x0117, 0xAAAA);

    /**
     *  GetMovieIndTrackType()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    Track
    GetMovieIndTrackType(Movie theMovie, long index, OSType trackType, long flags)
        THREEWORDINLINE(0x303C, 0x0208, 0xAAAA);

    /**
     *  GetTrackID()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    long
    GetTrackID(Track theTrack) THREEWORDINLINE(0x303C, 0x0127, 0xAAAA);

    /**
     *  GetTrackMovie()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    Movie
    GetTrackMovie(Track theTrack) THREEWORDINLINE(0x303C, 0x00D0, 0xAAAA);

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
    NewMovieTrack(Movie theMovie, Fixed width, Fixed height, short trackVolume)
        THREEWORDINLINE(0x303C, 0x0188, 0xAAAA);

    /**
     *  DisposeMovieTrack()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    DisposeMovieTrack(Track theTrack) TWOWORDINLINE(0x7042, 0xAAAA);

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
    GetTrackCreationTime(Track theTrack) TWOWORDINLINE(0x7043, 0xAAAA);

    /**
     *  GetTrackModificationTime()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    unsigned long
    GetTrackModificationTime(Track theTrack) TWOWORDINLINE(0x7044, 0xAAAA);

    /**
     *  GetTrackEnabled()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    Boolean
    GetTrackEnabled(Track theTrack) TWOWORDINLINE(0x7045, 0xAAAA);

    /**
     *  SetTrackEnabled()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SetTrackEnabled(Track theTrack, Boolean isEnabled)
        TWOWORDINLINE(0x7046, 0xAAAA);

    /**
     *  GetTrackUsage()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    long
    GetTrackUsage(Track theTrack) TWOWORDINLINE(0x7047, 0xAAAA);

    /**
     *  SetTrackUsage()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SetTrackUsage(Track theTrack, long usage) TWOWORDINLINE(0x7048, 0xAAAA);

    /**
     *  GetTrackDuration()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    TimeValue
    GetTrackDuration(Track theTrack) TWOWORDINLINE(0x704B, 0xAAAA);

    /**
     *  GetTrackOffset()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    TimeValue
    GetTrackOffset(Track theTrack) TWOWORDINLINE(0x704C, 0xAAAA);

    /**
     *  SetTrackOffset()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SetTrackOffset(Track theTrack, TimeValue movieOffsetTime)
        TWOWORDINLINE(0x704D, 0xAAAA);

    /**
     *  GetTrackLayer()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    short
    GetTrackLayer(Track theTrack) TWOWORDINLINE(0x7050, 0xAAAA);

    /**
     *  SetTrackLayer()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SetTrackLayer(Track theTrack, short layer) TWOWORDINLINE(0x7051, 0xAAAA);

    /**
     *  GetTrackAlternate()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    Track
    GetTrackAlternate(Track theTrack) TWOWORDINLINE(0x7052, 0xAAAA);

    /**
     *  SetTrackAlternate()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SetTrackAlternate(Track theTrack, Track alternateT)
        TWOWORDINLINE(0x7053, 0xAAAA);

    /**
     *  SetAutoTrackAlternatesEnabled()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SetAutoTrackAlternatesEnabled(Movie theMovie, Boolean enable)
        THREEWORDINLINE(0x303C, 0x015E, 0xAAAA);

    /**
     *  SelectMovieAlternates()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SelectMovieAlternates(Movie theMovie) THREEWORDINLINE(0x303C, 0x015F, 0xAAAA);

    /**
     *  GetTrackVolume()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    short
    GetTrackVolume(Track theTrack) TWOWORDINLINE(0x7054, 0xAAAA);

    /**
     *  SetTrackVolume()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SetTrackVolume(Track theTrack, short volume) TWOWORDINLINE(0x7055, 0xAAAA);

    /**
     *  GetTrackMatrix()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    GetTrackMatrix(Track theTrack, MatrixRecord *matrix)
        TWOWORDINLINE(0x7056, 0xAAAA);

    /**
     *  SetTrackMatrix()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SetTrackMatrix(Track theTrack, const MatrixRecord *matrix)
        TWOWORDINLINE(0x7057, 0xAAAA);

    /**
     *  GetTrackDimensions()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    GetTrackDimensions(Track theTrack, Fixed *width, Fixed *height)
        TWOWORDINLINE(0x705D, 0xAAAA);

    /**
     *  SetTrackDimensions()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SetTrackDimensions(Track theTrack, Fixed width, Fixed height)
        TWOWORDINLINE(0x705E, 0xAAAA);

    /**
     *  GetTrackUserData()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    UserData
    GetTrackUserData(Track theTrack) TWOWORDINLINE(0x705F, 0xAAAA);

    /**
     *  GetTrackDisplayMatrix()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    GetTrackDisplayMatrix(Track theTrack, MatrixRecord *matrix)
        THREEWORDINLINE(0x303C, 0x0263, 0xAAAA);

    /**
     *  GetTrackSoundLocalizationSettings()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    GetTrackSoundLocalizationSettings(Track theTrack, Handle *settings)
        THREEWORDINLINE(0x303C, 0x0282, 0xAAAA);

    /**
     *  SetTrackSoundLocalizationSettings()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    SetTrackSoundLocalizationSettings(Track theTrack, Handle settings)
        THREEWORDINLINE(0x303C, 0x0283, 0xAAAA);

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
                  Handle dataRef, OSType dataRefType)
        THREEWORDINLINE(0x303C, 0x018E, 0xAAAA);

    /**
     *  DisposeTrackMedia()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    DisposeTrackMedia(Media theMedia) TWOWORDINLINE(0x7061, 0xAAAA);

    /**
     *  GetTrackMedia()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    Media
    GetTrackMedia(Track theTrack) TWOWORDINLINE(0x7062, 0xAAAA);

    /**
     *  GetMediaTrack()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    Track
    GetMediaTrack(Media theMedia) THREEWORDINLINE(0x303C, 0x00C5, 0xAAAA);

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
    GetMediaCreationTime(Media theMedia) TWOWORDINLINE(0x7066, 0xAAAA);

    /**
     *  GetMediaModificationTime()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    unsigned long
    GetMediaModificationTime(Media theMedia) TWOWORDINLINE(0x7067, 0xAAAA);

    /**
     *  GetMediaTimeScale()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    TimeScale
    GetMediaTimeScale(Media theMedia) TWOWORDINLINE(0x7068, 0xAAAA);

    /**
     *  SetMediaTimeScale()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SetMediaTimeScale(Media theMedia, TimeScale timeScale)
        TWOWORDINLINE(0x7069, 0xAAAA);

    /**
     *  GetMediaDuration()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    TimeValue
    GetMediaDuration(Media theMedia) TWOWORDINLINE(0x706A, 0xAAAA);

    /**
     *  GetMediaLanguage()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    short
    GetMediaLanguage(Media theMedia) TWOWORDINLINE(0x706B, 0xAAAA);

    /**
     *  SetMediaLanguage()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SetMediaLanguage(Media theMedia, short language) TWOWORDINLINE(0x706C, 0xAAAA);

    /**
     *  GetMediaQuality()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    short
    GetMediaQuality(Media theMedia) TWOWORDINLINE(0x706D, 0xAAAA);

    /**
     *  SetMediaQuality()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SetMediaQuality(Media theMedia, short quality) TWOWORDINLINE(0x706E, 0xAAAA);

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
                               Str255 creatorName, OSType *creatorManufacturer)
        TWOWORDINLINE(0x706F, 0xAAAA);

    /**
     *  GetMediaUserData()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    UserData
    GetMediaUserData(Media theMedia) TWOWORDINLINE(0x7070, 0xAAAA);

    /**
     *  GetMediaInputMap()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    GetMediaInputMap(Media theMedia, QTAtomContainer *inputMap)
        THREEWORDINLINE(0x303C, 0x0249, 0xAAAA);

    /**
     *  SetMediaInputMap()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    SetMediaInputMap(Media theMedia, QTAtomContainer inputMap)
        THREEWORDINLINE(0x303C, 0x024A, 0xAAAA);

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
    GetMediaHandler(Media theMedia) TWOWORDINLINE(0x7071, 0xAAAA);

    /**
     *  SetMediaHandler()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    SetMediaHandler(Media theMedia, MediaHandlerComponent mH)
        THREEWORDINLINE(0x303C, 0x0190, 0xAAAA);

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
    BeginMediaEdits(Media theMedia) TWOWORDINLINE(0x7072, 0xAAAA);

    /**
     *  EndMediaEdits()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    EndMediaEdits(Media theMedia) TWOWORDINLINE(0x7073, 0xAAAA);

    /**
     *  SetMediaDefaultDataRefIndex()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    SetMediaDefaultDataRefIndex(Media theMedia, short index)
        THREEWORDINLINE(0x303C, 0x01E0, 0xAAAA);

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
                                   Str255 creatorName, OSType *creatorManufacturer)
        THREEWORDINLINE(0x303C, 0x019E, 0xAAAA);

    /**
     *  GetMediaDataHandler()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    DataHandler
    GetMediaDataHandler(Media theMedia, short index)
        THREEWORDINLINE(0x303C, 0x019F, 0xAAAA);

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
                        DataHandlerComponent dataHandler)
        THREEWORDINLINE(0x303C, 0x01A0, 0xAAAA);

    /**
     *  GetDataHandler()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    Component
    GetDataHandler(Handle dataRef, OSType dataHandlerSubType, long flags)
        THREEWORDINLINE(0x303C, 0x01ED, 0xAAAA);

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
                     long flags, ComponentInstance *dh)
        THREEWORDINLINE(0x303C, 0x031C, 0xAAAA);

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
    GetMediaSampleDescriptionCount(Media theMedia) TWOWORDINLINE(0x7077, 0xAAAA);

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
                              SampleDescriptionHandle descH)
        TWOWORDINLINE(0x7078, 0xAAAA);

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
                              SampleDescriptionHandle descH)
        THREEWORDINLINE(0x303C, 0x01D0, 0xAAAA);

    /**
     *  GetMediaSampleCount()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    long
    GetMediaSampleCount(Media theMedia) TWOWORDINLINE(0x7079, 0xAAAA);

    /**
     *  GetMediaSyncSampleCount()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    long
    GetMediaSyncSampleCount(Media theMedia) THREEWORDINLINE(0x303C, 0x02B2, 0xAAAA);

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
                         TimeValue *sampleTime, TimeValue *sampleDuration)
        TWOWORDINLINE(0x707A, 0xAAAA);

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
                         TimeValue *sampleTime, TimeValue *sampleDuration)
        TWOWORDINLINE(0x707B, 0xAAAA);

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
                   short sampleFlags, TimeValue *sampleTime)
        TWOWORDINLINE(0x707C, 0xAAAA);

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
                            TimeValue *sampleTime) TWOWORDINLINE(0x707D, 0xAAAA);

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
                             TimeValue *sampleTime)
        THREEWORDINLINE(0x303C, 0x01F7, 0xAAAA);

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
                               TimeValue *sampleTime)
        THREEWORDINLINE(0x303C, 0x02E8, 0xAAAA);

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
                   long *numberOfSamples, short *sampleFlags)
        TWOWORDINLINE(0x707E, 0xAAAA);

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
                            long *numberOfSamples, short *sampleFlags)
        TWOWORDINLINE(0x707F, 0xAAAA);

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
                             SampleReferencePtr sampleRefs)
        THREEWORDINLINE(0x303C, 0x0235, 0xAAAA);

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
                               SampleReference64Ptr sampleRefs)
        THREEWORDINLINE(0x303C, 0x02E9, 0xAAAA);

    /**
     *  SetMediaPreferredChunkSize()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    SetMediaPreferredChunkSize(Media theMedia, long maxChunkSize)
        THREEWORDINLINE(0x303C, 0x01F8, 0xAAAA);

    /**
     *  GetMediaPreferredChunkSize()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    GetMediaPreferredChunkSize(Media theMedia, long *maxChunkSize)
        THREEWORDINLINE(0x303C, 0x01F9, 0xAAAA);

    /**
     *  SetMediaShadowSync()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    SetMediaShadowSync(Media theMedia, long frameDiffSampleNum, long syncSampleNum)
        THREEWORDINLINE(0x303C, 0x0121, 0xAAAA);

    /**
     *  GetMediaShadowSync()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    GetMediaShadowSync(Media theMedia, long frameDiffSampleNum, long *syncSampleNum)
        THREEWORDINLINE(0x303C, 0x0122, 0xAAAA);

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
                         TimeValue mediaDuration, Fixed mediaRate)
        THREEWORDINLINE(0x303C, 0x0183, 0xAAAA);

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
                       TimeValue srcDuration, TimeValue dstIn)
        THREEWORDINLINE(0x303C, 0x0085, 0xAAAA);

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
                       TimeValue srcDuration, TimeValue dstIn)
        THREEWORDINLINE(0x303C, 0x0086, 0xAAAA);

    /**
     *  InsertEmptyTrackSegment()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    InsertEmptyTrackSegment(Track dstTrack, TimeValue dstIn, TimeValue dstDuration)
        THREEWORDINLINE(0x303C, 0x0087, 0xAAAA);

    /**
     *  InsertEmptyMovieSegment()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    InsertEmptyMovieSegment(Movie dstMovie, TimeValue dstIn, TimeValue dstDuration)
        THREEWORDINLINE(0x303C, 0x0088, 0xAAAA);

    /**
     *  DeleteTrackSegment()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    DeleteTrackSegment(Track theTrack, TimeValue startTime, TimeValue duration)
        THREEWORDINLINE(0x303C, 0x0089, 0xAAAA);

    /**
     *  DeleteMovieSegment()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    DeleteMovieSegment(Movie theMovie, TimeValue startTime, TimeValue duration)
        THREEWORDINLINE(0x303C, 0x008A, 0xAAAA);

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
                      TimeValue newDuration)
        THREEWORDINLINE(0x303C, 0x008B, 0xAAAA);

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
                      TimeValue newDuration)
        THREEWORDINLINE(0x303C, 0x008C, 0xAAAA);

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
    CutMovieSelection(Movie theMovie) THREEWORDINLINE(0x303C, 0x008D, 0xAAAA);

    /**
     *  CopyMovieSelection()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    Movie
    CopyMovieSelection(Movie theMovie) THREEWORDINLINE(0x303C, 0x008E, 0xAAAA);

    /**
     *  PasteMovieSelection()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    PasteMovieSelection(Movie theMovie, Movie src)
        THREEWORDINLINE(0x303C, 0x008F, 0xAAAA);

    /**
     *  AddMovieSelection()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    AddMovieSelection(Movie theMovie, Movie src)
        THREEWORDINLINE(0x303C, 0x0152, 0xAAAA);

    /**
     *  ClearMovieSelection()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    ClearMovieSelection(Movie theMovie) THREEWORDINLINE(0x303C, 0x00E1, 0xAAAA);

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
                         ComponentInstance userComp)
        THREEWORDINLINE(0x303C, 0x00CB, 0xAAAA);

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
                            long flags, ComponentInstance userComp)
        THREEWORDINLINE(0x303C, 0x01CD, 0xAAAA);

    /**
     *  IsScrapMovie()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    Component
    IsScrapMovie(Track targetTrack) THREEWORDINLINE(0x303C, 0x00CC, 0xAAAA);

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
    CopyTrackSettings(Track srcTrack, Track dstTrack)
        THREEWORDINLINE(0x303C, 0x0153, 0xAAAA);

    /**
     *  CopyMovieSettings()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    CopyMovieSettings(Movie srcMovie, Movie dstMovie)
        THREEWORDINLINE(0x303C, 0x0154, 0xAAAA);

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
                         OSType dataRefType, Track *dstTrack)
        TWOWORDINLINE(0x7074, 0xAAAA);

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
                          Track *dstTrack) THREEWORDINLINE(0x303C, 0x0344, 0xAAAA);

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
    NewMovieEditState(Movie theMovie) THREEWORDINLINE(0x303C, 0x0104, 0xAAAA);

    /**
     *  UseMovieEditState()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    UseMovieEditState(Movie theMovie, MovieEditState toState)
        THREEWORDINLINE(0x303C, 0x0105, 0xAAAA);

    /**
     *  DisposeMovieEditState()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    DisposeMovieEditState(MovieEditState state)
        THREEWORDINLINE(0x303C, 0x0106, 0xAAAA);

    /**
     *  NewTrackEditState()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    TrackEditState
    NewTrackEditState(Track theTrack) THREEWORDINLINE(0x303C, 0x0107, 0xAAAA);

    /**
     *  UseTrackEditState()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    UseTrackEditState(Track theTrack, TrackEditState state)
        THREEWORDINLINE(0x303C, 0x0108, 0xAAAA);

    /**
     *  DisposeTrackEditState()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    DisposeTrackEditState(TrackEditState state)
        THREEWORDINLINE(0x303C, 0x0109, 0xAAAA);

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
                      long *addedIndex) THREEWORDINLINE(0x303C, 0x01F0, 0xAAAA);

    /**
     *  DeleteTrackReference()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    DeleteTrackReference(Track theTrack, OSType refType, long index)
        THREEWORDINLINE(0x303C, 0x01F1, 0xAAAA);

    /**
     *  SetTrackReference()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    SetTrackReference(Track theTrack, Track refTrack, OSType refType, long index)
        THREEWORDINLINE(0x303C, 0x01F2, 0xAAAA);

    /**
     *  GetTrackReference()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    Track
    GetTrackReference(Track theTrack, OSType refType, long index)
        THREEWORDINLINE(0x303C, 0x01F3, 0xAAAA);

    /**
     *  GetNextTrackReferenceType()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSType
    GetNextTrackReferenceType(Track theTrack, OSType refType)
        THREEWORDINLINE(0x303C, 0x01F4, 0xAAAA);

    /**
     *  GetTrackReferenceCount()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    long
    GetTrackReferenceCount(Track theTrack, OSType refType)
        THREEWORDINLINE(0x303C, 0x01F5, 0xAAAA);

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
                           MovieProgressUPP proc, long refCon)
        THREEWORDINLINE(0x303C, 0x01CB, 0xAAAA);

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
                       short *resID, long flags, ComponentInstance userComp)
        THREEWORDINLINE(0x303C, 0x01CC, 0xAAAA);

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
                               Component *importer)
        THREEWORDINLINE(0x303C, 0x02C7, 0xAAAA);

    enum
    {
        kQTGetMIMETypeInfoIsQuickTimeMovieType =
            FOUR_CHAR_CODE('moov'), // info is a pointer to a Boolean        kQTGetMIMETypeInfoIsUnhelpfulType =
            FOUR_CHAR_CODE('dumb') // info is a pointer to a Boolean    };

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
                      OSType infoSelector, void *infoDataPtr, long *infoDataSize)
        THREEWORDINLINE(0x303C, 0x036A, 0xAAAA);

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
    TrackTimeToMediaTime(TimeValue value, Track theTrack)
        THREEWORDINLINE(0x303C, 0x0096, 0xAAAA);

    /**
     *  GetTrackEditRate()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    Fixed
    GetTrackEditRate(Track theTrack, TimeValue atTime)
        THREEWORDINLINE(0x303C, 0x0123, 0xAAAA);

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
    GetMovieDataSize(Movie theMovie, TimeValue startTime, TimeValue duration)
        THREEWORDINLINE(0x303C, 0x0098, 0xAAAA);

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
                       wide *dataSize) THREEWORDINLINE(0x303C, 0x02EB, 0xAAAA);

    /**
     *  GetTrackDataSize()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    long
    GetTrackDataSize(Track theTrack, TimeValue startTime, TimeValue duration)
        THREEWORDINLINE(0x303C, 0x0149, 0xAAAA);

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
                       wide *dataSize) THREEWORDINLINE(0x303C, 0x02EC, 0xAAAA);

    /**
     *  GetMediaDataSize()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    long
    GetMediaDataSize(Media theMedia, TimeValue startTime, TimeValue duration)
        THREEWORDINLINE(0x303C, 0x0099, 0xAAAA);

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
                       wide *dataSize) THREEWORDINLINE(0x303C, 0x02ED, 0xAAAA);

    /**
     *  PtInMovie()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    Boolean
    PtInMovie(Movie theMovie, Point pt) THREEWORDINLINE(0x303C, 0x009A, 0xAAAA);

    /**
     *  PtInTrack()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    Boolean
    PtInTrack(Track theTrack, Point pt) THREEWORDINLINE(0x303C, 0x009B, 0xAAAA);

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
    SetMovieLanguage(Movie theMovie, long language)
        THREEWORDINLINE(0x303C, 0x009C, 0xAAAA);

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
    GetUserData(UserData theUserData, Handle data, OSType udType, long index)
        THREEWORDINLINE(0x303C, 0x009E, 0xAAAA);

    /**
     *  AddUserData()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    AddUserData(UserData theUserData, Handle data, OSType udType)
        THREEWORDINLINE(0x303C, 0x009F, 0xAAAA);

    /**
     *  RemoveUserData()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    RemoveUserData(UserData theUserData, OSType udType, long index)
        THREEWORDINLINE(0x303C, 0x00A0, 0xAAAA);

    /**
     *  CountUserDataType()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    short
    CountUserDataType(UserData theUserData, OSType udType)
        THREEWORDINLINE(0x303C, 0x014B, 0xAAAA);

    /**
     *  GetNextUserDataType()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    long
    GetNextUserDataType(UserData theUserData, OSType udType)
        THREEWORDINLINE(0x303C, 0x01A5, 0xAAAA);

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
                    long index) THREEWORDINLINE(0x303C, 0x0126, 0xAAAA);

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
                    long index) THREEWORDINLINE(0x303C, 0x012E, 0xAAAA);

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
                    short itlRegionTag) THREEWORDINLINE(0x303C, 0x014C, 0xAAAA);

    /**
     *  GetUserDataText()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in Carb// info is a pointer to a Boolean
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtml// info is a pointer to a Boolean
     */
    OSErr
    GetUserDataText(UserData theUserData, Handle data, OSType udType, long index,
                    short itlRegionTag) THREEWORDINLINE(0x303C, 0x014D, 0xAAAA);

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
                       short itlRegionTag) THREEWORDINLINE(0x303C, 0x014E, 0xAAAA);

    /**
     *  NewUserData()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    NewUserData(UserData *theUserData) THREEWORDINLINE(0x303C, 0x012F, 0xAAAA);

    /**
     *  DisposeUserData()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    DisposeUserData(UserData theUserData) THREEWORDINLINE(0x303C, 0x0130, 0xAAAA);

    /**
     *  NewUserDataFromHandle()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    NewUserDataFromHandle(Handle h, UserData *theUserData)
        THREEWORDINLINE(0x303C, 0x0131, 0xAAAA);

    /**
     *  PutUserDataIntoHandle()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    PutUserDataIntoHandle(UserData theUserData, Handle h)
        THREEWORDINLINE(0x303C, 0x0132, 0xAAAA);

    /**
     *  SetMoviePropertyAtom()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.1 and later
     *    \carbon_lib        in CarbonLib 1.1 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.1 and later
     */
    OSErr
    SetMoviePropertyAtom(Movie theMovie, QTAtomContainer propertyAtom)
        THREEWORDINLINE(0x303C, 0x0284, 0xAAAA);

    /**
     *  GetMoviePropertyAtom()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.1 and later
     *    \carbon_lib        in CarbonLib 1.1 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.1 and later
     */
    OSErr
    GetMoviePropertyAtom(Movie theMovie, QTAtomContainer *propertyAtom)
        THREEWORDINLINE(0x303C, 0x0285, 0xAAAA);

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
                                TimeValue *interestingDuration)
        THREEWORDINLINE(0x303C, 0x016D, 0xAAAA);

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
                                TimeValue *interestingDuration)
        THREEWORDINLINE(0x303C, 0x00E2, 0xAAAA);

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
                                TimeValue *interestingDuration)
        THREEWORDINLINE(0x303C, 0x010E, 0xAAAA);

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
                    long createMovieFileFlags, short *resRefNum, Movie *newmovie)
        THREEWORDINLINE(0x303C, 0x0191, 0xAAAA);

    /**
     *  OpenMovieFile()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    OpenMovieFile(const FSSpec *fileSpec, short *resRefNum, SInt8 permission)
        THREEWORDINLINE(0x303C, 0x0192, 0xAAAA);

    /**
     *  CloseMovieFile()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    CloseMovieFile(short resRefNum) THREEWORDINLINE(0x303C, 0x00D5, 0xAAAA);

    /**
     *  DeleteMovieFile()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    DeleteMovieFile(const FSSpec *fileSpec) THREEWORDINLINE(0x303C, 0x0175, 0xAAAA);

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
        Movie *theMovie, short resRefNum, short *resId, // can be NULL         StringPtr resName, short newMovieFlags,
        Boolean *dataRefWasChanged) /* can be NULL */ THREEWORDINLINE(0x303C,
                                                                      0x00F0,
                                                                      0xAAAA);

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
                       Boolean *dataRefWasChanged)
        THREEWORDINLINE(0x303C, 0x00F1, 0xAAAA);

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
                         short newMovieFlags, Boolean *dataRefWasChanged)
        THREEWORDINLINE(0x303C, 0x01B3, 0xAAAA);

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
                           short newMovieFlags, Boolean *dataRefWasChanged)
        THREEWORDINLINE(0x303C, 0x02EE, 0xAAAA);

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
                         OSType dataRefType)
        THREEWORDINLINE(0x303C, 0x01EC, 0xAAAA);

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
                        OSType dataRefType) THREEWORDINLINE(0x303C, 0x0220, 0xAAAA);

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
                     ConstStr255Param resName)
        THREEWORDINLINE(0x303C, 0x00D7, 0xAAAA);

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
                        ConstStr255Param resName)
        THREEWORDINLINE(0x303C, 0x00D8, 0xAAAA);

    /**
     *  RemoveMovieResource()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    RemoveMovieResource(short resRefNum, short resId)
        THREEWORDINLINE(0x303C, 0x0176, 0xAAAA);

    /**
     *  HasMovieChanged()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    Boolean
    HasMovieChanged(Movie theMovie) THREEWORDINLINE(0x303C, 0x00D9, 0xAAAA);

    /**
     *  ClearMovieChanged()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    ClearMovieChanged(Movie theMovie) THREEWORDINLINE(0x303C, 0x0113, 0xAAAA);

    /**
     *  SetMovieDefaultDataRef()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    SetMovieDefaultDataRef(Movie theMovie, Handle dataRef, OSType dataRefType)
        THREEWORDINLINE(0x303C, 0x01C1, 0xAAAA);

    /**
     *  GetMovieDefaultDataRef()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    GetMovieDefaultDataRef(Movie theMovie, Handle *dataRef, OSType *dataRefType)
        THREEWORDINLINE(0x303C, 0x01D2, 0xAAAA);

    /**
     *  SetMovieAnchorDataRef()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.1 and later
     *    \carbon_lib        in CarbonLib 1.1 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.1 and later
     */
    OSErr
    SetMovieAnchorDataRef(Movie theMovie, Handle dataRef, OSType dataRefType)
        THREEWORDINLINE(0x303C, 0x0315, 0xAAAA);

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
                          long *outFlags) THREEWORDINLINE(0x303C, 0x0316, 0xAAAA);

    /**
     *  SetMovieColorTable()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    SetMovieColorTable(Movie theMovie, CTabHandle ctab)
        THREEWORDINLINE(0x303C, 0x0205, 0xAAAA);

    /**
     *  GetMovieColorTable()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    GetMovieColorTable(Movie theMovie, CTabHandle *ctab)
        THREEWORDINLINE(0x303C, 0x0206, 0xAAAA);

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
                 short *resId, ConstStr255Param resName)
        THREEWORDINLINE(0x303C, 0x019B, 0xAAAA);

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
                     long createMovieFileFlags)
        THREEWORDINLINE(0x303C, 0x019C, 0xAAAA);

    /**
     *  SetMovieProgressProc()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SetMovieProgressProc(Movie theMovie, MovieProgressUPP p, long refcon)
        THREEWORDINLINE(0x303C, 0x019A, 0xAAAA);

    /**
     *  GetMovieProgressProc()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    void
    GetMovieProgressProc(Movie theMovie, MovieProgressUPP *p, long *refcon)
        THREEWORDINLINE(0x303C, 0x0300, 0xAAAA);

    /**
     *  CreateShortcutMovieFile()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    OSErr
    CreateShortcutMovieFile(const FSSpec *fileSpec, OSTy// can be NULL 
                            ScriptCode scriptTag, long createMovieFileFlags,
                            Handle targetDataRef, OSType targetDataRefType)
        THREEWORDINLINE(0x303C, 0x02FA, 0xAAAA);

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
                    Track *searchTrack, TimeValue *searchTime, long *searchOffset)
        THREEWORDINLINE(0x303C, 0x0207, 0xAAAA);

    /**
     *  GetPosterBox()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    GetPosterBox(Movie theMovie, Rect *boxRect)
        THREEWORDINLINE(0x303C, 0x016F, 0xAAAA);

    /**
     *  SetPosterBox()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SetPosterBox(Movie theMovie, const Rect *boxRect)
        THREEWORDINLINE(0x303C, 0x0170, 0xAAAA);

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
                                    TimeValue duration)
        THREEWORDINLINE(0x303C, 0x016C, 0xAAAA);

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
                                    TimeValue duration)
        THREEWORDINLINE(0x303C, 0x016B, 0xAAAA);

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
                       MovieRgnCoverUPP coverProc, long refcon)
        THREEWORDINLINE(0x303C, 0x0179, 0xAAAA);

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
                       MovieRgnCoverUPP *coverProc, long *refcon)
        THREEWORDINLINE(0x303C, 0x01DD, 0xAAAA);

    /**
     *  GetTrackStatus()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    GetTrackStatus(Track theTrack) THREEWORDINLINE(0x303C, 0x0172, 0xAAAA);

    /**
     *  GetMovieStatus()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    GetMovieStatus(Movie theMovie, Track *firstProblemTrack)
        THREEWORDINLINE(0x303C, 0x0173, 0xAAAA);

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
    GetMovieLoadState(Movie theMovie) THREEWORDINLINE(0x303C, 0x0314, 0xAAAA);

    // Input flags for CanQuickTimeOpenFile/DataRef     enum
    {
        kQTDontUseDataToFindImporter = 1L << 0,
        kQTDontLookForMovieImporterIfGraphicsImporterFound = 1L << 1,
        kQTAllowOpeningStillImagesAsMovies = 1L << 2,
        kQTAllowImportersThatWouldCreateNewFile = 1L << 3,
        kQTAllowAggressiveImporters = 1L << 4 // eg, TEXT and PICT movie importers    };

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
                         Boolean *outPreferGraphicsImporter, UInt32 inFlags)
        THREEWORDINLINE(0x303C, 0x033E, 0xAAAA);

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
                            Boolean *outPreferGraphicsImporter, UInt32 inFlags)
        THREEWORDINLINE(0x303C, 0x033F, 0xAAAA);

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
    NewMovieController(Movie theMovie, const Rect *movieRect, long someFlags)
        THREEWORDINLINE(0x303C, 0x018A, 0xAAAA);

    /**
     *  DisposeMovieController()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    DisposeMovieController(ComponentInstance mc)
        THREEWORDINLINE(0x303C, 0x018B, 0xAAAA);

    /**
     *  ShowMovieInformation()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    ShowMovieInformation(Movie theMovie, ModalFilterUPP filterProc, long refCon)
        THREEWORDINLINE(0x303C, 0x0209, 0xAAAA);

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
    PutMovieOnScrap(Movie theMovie, long movieScrapFlags)
        THREEWORDINLINE(0x303C, 0x018C, 0xAAAA);

    /**
     *  NewMovieFromScrap()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    Movie
    NewMovieFromScrap(long newMovieFlags) THREEWORDINLINE(0x303C, 0x018D, 0xAAAA);

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
                    OSType *dataRefType, long *dataRefAttributes)
        THREEWORDINLINE(0x303C, 0x0197, 0xAAAA);

    /**
     *  SetMediaDataRef()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    SetMediaDataRef(Media theMedia, short index, Handle dataRef, OSType dataRefType)
        THREEWORDINLINE(0x303C, 0x01C9, 0xAAAA);

    /**
     *  SetMediaDataRefAttributes()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    SetMediaDataRefAttributes(Media theMedia, short index, long dataRefAttributes)
        THREEWORDINLINE(0x303C, 0x01CA, 0xAAAA);

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
                    OSType dataRefType) THREEWORDINLINE(0x303C, 0x0198, 0xAAAA);

    /**
     *  GetMediaDataRefCount()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    GetMediaDataRefCount(Media theMedia, short *count)
        THREEWORDINLINE(0x303C, 0x0199, 0xAAAA);

    /**
     *  QTNewAlias()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    QTNewAlias(const FSSpec *fss, AliasHandle *alias, Boolean minimal)
        THREEWORDINLINE(0x303C, 0x0201, 0xAAAA);

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
    SetMoviePlayHints(Movie theMovie, long flags, long flagsMask)
        THREEWORDINLINE(0x303C, 0x01A1, 0xAAAA);

    /**
     *  SetMediaPlayHints()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SetMediaPlayHints(Media theMedia, long flags, long flagsMask)
        THREEWORDINLINE(0x303C, 0x01A2, 0xAAAA);

    /**
     *  GetMediaPlayHints()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    GetMediaPlayHints(Media theMedia, long *flags)
        THREEWORDINLINE(0x303C, 0x02CE, 0xAAAA);

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
                         long defaultHints) THREEWORDINLINE(0x303C, 0x01E3, 0xAAAA);

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
                         long *defaultHints)
        THREEWORDINLINE(0x303C, 0x01E4, 0xAAAA);

    /*****
        Big screen TV
    *****/
    enum
    {
        fullScreenHideCursor = 1L << 0,
        fullScreenAllowEvents = 1L << 1,
    // Input flags for CanQuickTimeOpenFile/DataRef 
        fullScreenPreflightSize = 1L << 3
    };

    /**
     *  BeginFullScreen()
     *
// eg, TEXT and PICT movie importers
     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    BeginFullScreen(Ptr *restoreState, GDHandle whichGD, short *desiredWidth,
                    short *desiredHeight, WindowRef *newWindow,
                    RGBColor *eraseColor, long flags)
        THREEWORDINLINE(0x303C, 0x0233, 0xAAAA);

    /**
     *  EndFullScreen()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    EndFullScreen(Ptr fullState, long flags)
        THREEWORDINLINE(0x303C, 0x0234, 0xAAAA);

    /*****
        Wired Actions
    *****/
    // flags for MovieExecuteWiredActions    enum
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
                                    MovieExecuteWiredActionsUPP proc, void *refCon)
        THREEWORDINLINE(0x303C, 0x0302, 0xAAAA);

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
                                       void *refCon)
        THREEWORDINLINE(0x303C, 0x0303, 0xAAAA);

    /**
     *  MovieExecuteWiredActions()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    OSErr
    MovieExecuteWiredActions(Movie theMovie, long flags, QTAtomContainer actions)
        THREEWORDINLINE(0x303C, 0x0304, 0xAAAA);

    /*****
        Sprite Toolbox
    *****/
    enum
    {
        kBackgroundSpriteLayerNum = 32767
    };

    //  Sprite Properties    enum
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

    // special value for kSpriteTrackPropertyQTIdleEventsFrequency (the default)    enum
    {
        kNoQTIdleEvents = -1
    };

    // flagsIn for SpriteWorldIdle    enum
    {
        kOnlyDrawToSpriteWorld = 1L << 0,
        kSpriteWorldPreflight = 1L << 1
    };

    // flagsOut for SpriteWorldIdle    enum
    {
        kSpriteWorldDidDraw = 1L << 0,
        kSpriteWorldNeedsToDraw = 1L << 1
    };

    // flags for sprite track sample format    enum
    {
        kKeyFrameAndSingleOverride = 1L << 1,
        kKeyFrameAndAllOverrides = 1L << 2
    };

    // sprite world flags    enum
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
                   GWorldPtr background) THREEWORDINLINE(0x303C, 0x0239, 0xAAAA);

    /**
     *  DisposeSpriteWorld()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    DisposeSpriteWorld(SpriteWorld theSpriteWorld)
        THREEWORDINLINE(0x303C, 0x023A, 0xAAAA);

    /**
     *  SetSpriteWorldClip()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    SetSpriteWorldClip(SpriteWorld theSpriteWorld, RgnHandle clipRgn)
        THREEWORDINLINE(0x303C, 0x023B, 0xAAAA);

    /**
     *  SetSpriteWorldMatrix()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    SetSpriteWorldMatrix(SpriteWorld theSpriteWorld, const MatrixRecord *matrix)
        THREEWORDINLINE(0x303C, 0x023C, 0xAAAA);

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
                               const RGBColor *opColor)
        THREEWORDINLINE(0x303C, 0x02D9, 0xAAAA);

    /**
     *  SpriteWorldIdle()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    SpriteWorldIdle(SpriteWorld theSpriteWorld, long flagsIn, long *flagsOut)
        THREEWORDINLINE(0x303C, 0x023D, 0xAAAA);

    /**
     *  InvalidateSpriteWorld()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    InvalidateSpriteWorld(SpriteWorld theSpriteWorld, Rect *invalidArea)
        THREEWORDINLINE(0x303C, 0x023E, 0xAAAA);

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
                       Sprite *spriteHit) THREEWORDINLINE(0x303C, 0x0246, 0xAAAA);

    /**
     *  SpriteHitTest()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    SpriteHitTest(Sprite theSprite, long flags, Point loc, Boolean *wasHit)
        THREEWORDINLINE(0x303C, 0x0247, 0xAAAA);

    /**
     *  DisposeAllSprites()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    DisposeAllSprites(SpriteWorld theSpriteWorld)
        THREEWORDINLINE(0x303C, 0x023F, 0xAAAA);

    /**
     *  SetSpriteWorldFlags()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    SetSpriteWorldFlags(SpriteWorld spriteWorld, long flags, long flagsMask)
        THREEWORDINLINE(0x303C, 0x02C2, 0xAAAA);

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
              Boolean visible, short layer) THREEWORDINLINE(0x303C, 0x0240, 0xAAAA);

    /**
     *  DisposeSprite()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    DisposeSprite(Sprite theSprite) THREEWORDINLINE(0x303C, 0x0241, 0xAAAA);

    /**
     *  InvalidateSprite()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
    // flags for MovieExecuteWiredActions
    void
    InvalidateSprite(Sprite theSprite) THREEWORDINLINE(0x303C, 0x0242, 0xAAAA);

    /**
     *  SetSpriteProperty()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    SetSpriteProperty(Sprite theSprite, long propertyType, void *propertyValue)
        THREEWORDINLINE(0x303C, 0x0243, 0xAAAA);

    /**
     *  GetSpriteProperty()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    GetSpriteProperty(Sprite theSprite, long propertyType, void *propertyValue)
        THREEWORDINLINE(0x303C, 0x0244, 0xAAAA);

    /*****
        QT Atom Data Support
    *****/
    enum
    {
        kParentAtomIsContainer = 0
    };

    // create and dispose QTAtomContainer objects
    /**
     *  QTNewAtomContainer()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    QTNewAtomContainer(QTAtomContainer *atomData)
        THREEWORDINLINE(0x303C, 0x020C, 0xAAAA);

    /**
     *  QTDisposeAtomContainer()
     *

    //  Sprite Properties
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    QTDisposeAtomContainer(QTAtomContainer atomData)
        THREEWORDINLINE(0x303C, 0x020D, 0xAAAA);

    // locating nested atoms within QTAtomContainer container
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
                       QTAtomType currentChildType)
        THREEWORDINLINE(0x303C, 0x020E, 0xAAAA);
// special value for kSpriteTrackPropertyQTIdleEventsFrequency (the default)
    /**
     *  QTCountChildrenOfType()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
    // flagsIn for SpriteWorldIdle
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    short
    QTCountChildrenOfType(QTAtomContainer container, QTAtom parentAtom,
                          QTAtomType childType)
    // flagsOut for SpriteWorldIdle

    /**
     *  QTFindChildByIndex()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
    // flags for sprite track sample format
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    QTAtom
    QTFindChildByIndex(QTAtomContainer container, QTAtom parentAtom,
                       QTAtomType atomType, short index, QTAtomID *id)
    // sprite world flags

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
                    QTAtomType atomType, QTAtomID id, short *index)
        THREEWORDINLINE(0x303C, 0x021D, 0xAAAA);

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
                       QTAtom currentChild, QTAtom *nextChild)
        THREEWORDINLINE(0x303C, 0x0200, 0xAAAA);

    // set a leaf atom's data    /**
     *  QTSetAtomData()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    QTSetAtomData(QTAtomContainer container, QTAtom atom, long dataSize,
                  void *atomData) THREEWORDINLINE(0x303C, 0x0211, 0xAAAA);

    // extracting data    /**
     *  QTCopyAtomDataToHandle()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    QTCopyAtomDataToHandle(QTAtomContainer container, QTAtom atom,
                           Handle targetHandle)
        THREEWORDINLINE(0x303C, 0x0212, 0xAAAA);

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
                        long *actualSize) THREEWORDINLINE(0x303C, 0x0213, 0xAAAA);

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
                       QTAtomID *id) THREEWORDINLINE(0x303C, 0x0232, 0xAAAA);

    // extract a copy of an atom and all of it's children, caller disposes    /**
     *  QTCopyAtom()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    QTCopyAtom(QTAtomContainer container, QTAtom atom,
               QTAtomContainer *targetContainer)
        THREEWORDINLINE(0x303C, 0x0214, 0xAAAA);

    // obtaining direct reference to atom data    /**
     *  QTLockContainer()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    QTLockContainer(QTAtomContainer container)
        THREEWORDINLINE(0x303C, 0x0215, 0xAAAA);

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
                     Ptr *atomData) THREEWORDINLINE(0x303C, 0x0216, 0xAAAA);

    /**
     *  QTUnlockContainer()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    QTUnlockContainer(QTAtomContainer container)
        THREEWORDINLINE(0x303C, 0x0217, 0xAAAA);

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
                  QTAtom *newAtom) THREEWORDINLINE(0x303C, 0x0218, 0xAAAA);

    // inserts children from childrenContainer as children of parentAtom    /**
     *  QTInsertChildren()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    QTInsertChildren(QTAtomContainer container, QTAtom parentAtom,
                     QTAtomContainer childrenContainer)
        THREEWORDINLINE(0x303C, 0x0219, 0xAAAA);

    // destruction    /**
     *  QTRemoveAtom()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    QTRemoveAtom(QTAtomContainer container, QTAtom atom)
        THREEWORDINLINE(0x303C, 0x021A, 0xAAAA);

    /**
     *  QTRemoveChildren()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    QTRemoveChildren(QTAtomContainer container, QTAtom atom)
        THREEWORDINLINE(0x303C, 0x021B, 0xAAAA);

    // replacement must be same type as target    /**
     *  QTReplaceAtom()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    QTReplaceAtom(QTAtomContainer targetContainer, QTAtom targetAtom,
                  QTAtomContainer replacementContainer, QTAtom replacementAtom)
        THREEWORDINLINE(0x303C, 0x021C, 0xAAAA);

    /**
     *  QTSwapAtoms()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    QTSwapAtoms(QTAtomContainer container, QTAtom atom1, QTAtom atom2)
        THREEWORDINLINE(0x303C, 0x01FF, 0xAAAA);

    /**
     *  QTSetAtomID()
     *
// create and dispose QTAtomContainer objects
     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    QTSetAtomID(QTAtomContainer container, QTAtom atom, QTAtomID newID)
        THREEWORDINLINE(0x303C, 0x0231, 0xAAAA);

    /**
     *  QTGetAtomParent()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    QTAtom
    QTGetAtomParent(QTAtomContainer container, QTAtom childAtom)
        THREEWORDINLINE(0x303C, 0x02EF, 0xAAAA);

    /**
     *  SetMediaPropertyAtom()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
    // locating nested atoms within QTAtomContainer container
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    SetMediaPropertyAtom(Media theMedia, QTAtomContainer propertyAtom)
        THREEWORDINLINE(0x303C, 0x022E, 0xAAAA);

    /**
     *  GetMediaPropertyAtom()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    GetMediaPropertyAtom(Media theMedia, QTAtomContainer *propertyAtom)
        THREEWORDINLINE(0x303C, 0x022F, 0xAAAA);

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
    // set a leaf atom's data
    QTNewTween(QTTweener *tween, QTAtomContainer container, QTAtom tweenAtom,
               TimeValue maxTime) THREEWORDINLINE(0x303C, 0x029D, 0xAAAA);

    /**
     *  QTDisposeTween()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    // extracting data

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
              TweenerDataUPP tweenDataProc, void *tweenDataRefCon)
        THREEWORDINLINE(0x303C, 0x029E, 0xAAAA);

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
                                 OSType idType)
        THREEWORDINLINE(0x303C, 0x02CF, 0xAAAA);

    /**
     *  GetSoundDescriptionExtension()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    // extract a copy of an atom and all of it's children, caller disposes
    GetSoundDescriptionExtension(SoundDescriptionHandle desc, Handle *extension,
                                 OSType idType)
        THREEWORDINLINE(0x303C, 0x02D0, 0xAAAA);

    /**
     *  RemoveSoundDescriptionExtension()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    // obtaining direct reference to atom data
        THREEWORDINLINE(0x303C, 0x02D1, 0xAAAA);

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
    GetQuickTimePreference(OSType preferenceType, QTAtomContainer *preferenceAtom)
        THREEWORDINLINE(0x303C, 0x02D4, 0xAAAA);

    /**
     *  SetQuickTimePreference()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    SetQuickTimePreference(OSType preferenceType, QTAtomContainer preferenceAtom)
        THREEWORDINLINE(0x303C, 0x02D5, 0xAAAA);

    /*****
        Effects and dialog Support
    *****/
    // atom types for entries in the effects list    enum
    {
        kEffectNameAtom = FOUR_CHAR_CODE('name'), // name of effect         kEffectTypeAtom = FOUR_CHAR_CODE('type'), // codec sub-type for effect         kEffectManufacturerAtom =
            FOUR_CHAR_CODE('manu') // codec manufacturer for effect     };

    struct QTParamPreviewRecord
    {
        long sourceID;           // 1 based source identifier        PicHandle sourcePicture; /* picture for preview, must not dispose until dialog
                                    is disposed*/
    };
    typedef struct QTParamPreviewRecord QTParamPreviewRecord;
    typedef QTParamPreviewRecord *QTParamPreviewPtr;
    struct QTParamDialogEventRecord
    {
        EventRecord *theEvent; // Event received by the dialog         DialogRef whichDialog; // dialog that event was directed towards         short itemHit;         // dialog item which was hit     };
    typedef struct QTParamDialogEventRecord QTParamDialogEventRecord;
    typedef QTParamDialogEventRecord *QTParamDialogEventPtr;
    struct QTParamFetchPreviewRecord
    {
        GWorldPtr theWorld; // the world into which to draw the preview         Fixed percentage;   // frame percentage (from 0.0 - 1.0) to be drawn     };
    typedef struct QTParamFetchPreviewRecord QTParamFetchPreviewRecord;
    typedef QTParamFetchPreviewRecord *QTParamFetchPreviewPtr;
    enum
    {
    // inserts children from childrenContainer as children of parentAtom

    typedef long QTParameterDialog;
    enum
    {
        elOptionsIncludeNoneInList =
            0x00000001 // "None" effect is included in list     };

    typedef long QTEffectListOptions;
    enum
    {
        pdOptionsCollectOneValue = 0x00000001, // should collect a single value only        pdOptionsAllowOptionalInterpolations =
            0x00000002,                      // non-novice interpolation options are shown         pdOptionsModalDialogBox = 0x00000004 // dialog box should be modal     };

    typedef long QTParameterDialogOptions;
    // destruction
    {
        effectIsRealtime = 0 // effect can be rendered in real time     };

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
                     long maxSources, QTEffectListOptions getOptions)
        THREEWORDINLINE(0x303C, 0x02C9, 0xAAAA);

    /**
     *  QTCreateStandardParameterDialog()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    // replacement must be same type as target
    QTCreateStandardParameterDialog(QTAtomContainer effectList,
                                    QTAtomContainer parameters,
                                    QTParameterDialogOptions dialogOptions,
                                    QTParameterDialog *createdDialog)
        THREEWORDINLINE(0x303C, 0x02CA, 0xAAAA);

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
                                     QTParameterDialog createdDialog)
        THREEWORDINLINE(0x303C, 0x02CB, 0xAAAA);

    /**
     *  QTDismissStandardParameterDialog()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    QTDismissStandardParameterDialog(QTParameterDialog createdDialog)
        THREEWORDINLINE(0x303C, 0x02CC, 0xAAAA);

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
                                      void *params)
        THREEWORDINLINE(0x303C, 0x02CD, 0xAAAA);

    /**
     *  QTGetEffectSpeed()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    QTGetEffectSpeed(QTAtomContainer parameters, Fixed *pFPS)
        THREEWORDINLINE(0x303C, 0x02D2, 0xAAAA);

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
    QTGetAccessKeys(Str255 accessKeyType, long flags, QTAtomContainer *keys)
        THREEWORDINLINE(0x303C, 0x02B3, 0xAAAA);

    /**
     *  QTRegisterAccessKey()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    QTRegisterAccessKey(Str255 accessKeyType, long flags, Handle accessKey)
        THREEWORDINLINE(0x303C, 0x02B4, 0xAAAA);

    /**
     *  QTUnregisterAccessKey()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    QTUnregisterAccessKey(Str255 accessKeyType, long flags, Handle accessKey)
        THREEWORDINLINE(0x303C, 0x02B5, 0xAAAA);

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
                       long *retdataRefSkew)
        THREEWORDINLINE(0x303C, 0x02BE, 0xAAAA);

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
                       long *retdataRefSkew)
        THREEWORDINLINE(0x303C, 0x02BF, 0xAAAA);

    /**
     *  GetMaxLoadedTimeInMovie()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    GetMaxLoadedTimeInMovie(Movie theMovie, TimeValue *time)
        THREEWORDINLINE(0x303C, 0x02C0, 0xAAAA);

    /**
     *  QTMovieNeedsTimeTable()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    QTMovieNeedsTimeTable(Movie theMovie, Boolean *needsTimeTable)
        THREEWORDINLINE(0x303C, 0x02C3, 0xAAAA);

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
                              long *offset) THREEWORDINLINE(0x303C, 0x02C6, 0xAAAA);

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
        long recordSize; // total number of bytes in QTScheduledBandwidthRecord
        long priority;
    // atom types for entries in the effects list
        CompTimeValue startTime; // bandwidth usage start time        CompTimeValue duration;  // duration of bandwidth usage (0 if unknown)        CompTimeValue
            prerollDuration; // time for negotiation before startTime (0 if unknown)        TimeScale scale;     // timescale of value/duration/prerollDuration fields        TimeBase base;       // timebase    };
    typedef struct QTScheduledBandwidthRecord QTSc// name of effect 
    typedef QTScheduledBandwidthRecord *QTSchedule// codec sub-type for effect 
    typedef QTScheduledBandwidthPtr *QTScheduledBandwidthHandle;
    /**// codec manufacturer for effect 
     *  QTBandwidthRequest()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in C// 1 based source identifier
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    OSErr
    QTBandwidthRequest(long priority, QTBandwidthNotificationUPP callback,
                       const void *refcon, QTBandwidthReference *bwRef, long flags)
        THREEWORDINLINE(0x303C, 0x02F5, 0xAAAA);
// Event received by the dialog 
    /**// dialog that event was directed towards 
     *  QTBandwidthRequestForTi// dialog item which was hit 
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.1 and later
     *    \carbon_lib        in CarbonLib 1.1 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          // the world into which to draw the preview 
     */// frame percentage (from 0.0 - 1.0) to be drawn 
    OSErr
    QTBandwidthRequestForTimeBase(TimeBase tb, long priority,
                                  QTBandwidthNotificationUPP callback,
                                  const void *refcon, QTBandwidthReference *bwRef,
                                  long flags)
        THREEWORDINLINE(0x303C, 0x0318, 0xAAA// no param
// param is MenuRef
    /**// param is MenuRef
     *  QTBandwidthRelease()// param is QTAtomContainer
     *// param is long
// param is QTParamPreviewPtr;
     *    \non_carbon_cfm   in QuickTimeLib 4// param is UserEventUPP
     *    \carbon_lib        in CarbonLib 1.0// param is StringPtr 
     *    \mac_os_x         in version 10.0 a// param is MenuRef* 
     *    Windows:          in qtmlClient.lib// param is long 
     */// param is StringPtr 
    OSErr// param is QTParamDialogEventPtr 
    QTBandwidthRelease(QTBandwidthReference b// param is QTParamFetchPreviewPtr 
        THREEWORDINLINE(0x303C, 0x02F6, 0xAAAA);

    /**
     *  QTScheduledBandwidthRequest()
     *

     *    \non_carbon_c// "None" effect is included in list 
     *    \carbon_lib        in CarbonLib 1.1 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.1 and later
     */
    OSErr
    QTScheduledBandwidthRequest(QTScheduledBand// should collect a single value only
                                QTBandwidthNotificationUPP notificationCallback,
                                void *refcon,// non-novice interpolation options are shown 
                                long flags) T// dialog box should be modal 

    /**
     *  QTScheduledBandwidthRelease()
     *

     *    \non_carbon_cfm   i// effect can be rendered in real time 
     *    \carbon_lib        in CarbonLib 1.1 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.1 and later
     */
    OSErr
    QTScheduledBandwidthRelease(QTScheduledBandwidthReference sbwRef, long flags)
        THREEWORDINLINE(0x303C, 0x0311, 0xAAAA);

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
                   RegionCode theRegionCode, ConstStr255Param theString)
        THREEWORDINLINE(0x303C, 0x027A, 0xAAAA);

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
                      RegionCode theRegionCode, long flags)
        THREEWORDINLINE(0x303C, 0x027B, 0xAAAA);

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
                   StringPtr theString) THREEWORDINLINE(0x303C, 0x027C, 0xAAAA);

    /**
     *  QTTextToNativeText()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    QTTextToNativeText(Handle theText, long encoding, long flags)
        THREEWORDINLINE(0x303C, 0x02DB, 0xAAAA);

    // QTParseTextHREF inContainer atoms    enum
    {
        kQTParseTextHREFText = FOUR_CHAR_CODE('text'),    // string        kQTParseTextHREFBaseURL = FOUR_CHAR_CODE('burl'), // string        kQTParseTextHREFClickPoint =
            FOUR_CHAR_CODE('clik'), /* Point; if present, QTParseTextHREF will expand
                                       URLs to support server-side image maps*/
        kQTParseTextHREFUseAltDelim = FOUR_CHAR_CODE(
            'altd'),                                        // boolean; if no kQTParseTextHREFDelimiter, delim is ':'        kQTParseTextHREFDelimiter = FOUR_CHAR_CODE('delm'), // character        kQTParseTextHREFRecomposeHREF = FOUR_CHAR_CODE(
            'rhrf') /* Boolean; if true, QTParseTextHREF returns recomposed HREF with
                       URL expanded as appropriate*/
    };

    // QTParseTextHREF outContainer atoms    enum
    {
        kQTParseTextHREFURL = FOUR_CHAR_CODE('url '),         // string        kQTParseTextHREFTarget = FOUR_CHAR_CODE('targ'),      // string        kQTParseTextHREFChapter = FOUR_CHAR_CODE('chap'),     // string        kQTParseTextHREFIsAutoHREF = FOUR_CHAR_CODE('auto'),  // Boolean        kQTParseTextHREFIsServerMap = FOUR_CHAR_CODE('smap'), // Boolean        kQTParseTextHREFHREF =
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
                    QTAtomContainer *outContainer)
        THREEWORDINLINE(0x303C, 0x0319, 0xAAAA);

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
        kTrackModifierInput = 0x696E, // is really 'in'        kTrackModifierType = 0x7479,  // is really 'ty'        kTrackModifierReference = FOUR_CHAR_CODE('ssrc'),
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
            FOUR_CHAR_CODE('vide'), // was kTrackModifierTypeSpriteImage        kTrackModifierObjectMatrix = 6,
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

    // kTweenFlags    enum
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
    {// total number of bytes in QTScheduledBandwidthRecord
        float DurFromLastSample; // 0 to 1         TQ3Matrix4x4 matrix;
    };
    typedef struct ThreeDeeNonLinearSample ThreeDeeNonLinearSample;
// bandwidth usage start time
    struct ThreeDeeNonLinearTween// duration of bandwidth usage (0 if unknown)
    {
        long number;// time for negotiation before startTime (0 if unknown)
        long dataSize;// timescale of value/duration/prerollDuration fields
        float tensionFactor; // timebase
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

// use these two routines at your own peril #define ResetVideoMediaStatistics VideoMediaResetStatistics
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
#endif // OLDROUTINENAMES 
    /*************************
     * Video Media routines
     **************************/

    enum
    {
        videoFlagDontLeanAhead = 1L << 0
    };

    // use these five routines at your own peril    /**
     *  VideoMediaResetStatistics()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    VideoMediaResetStatistics(MediaHandler mh)
        FIVEWORDINLINE(0x2F3C, 0x0000, 0x0105, 0x7000, 0xA82A);

    /**
     *  VideoMediaGetStatistics()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    VideoMediaGetStatistics(MediaHandler mh)
        FIVEWORDINLINE(0x2F3C, 0x0000, 0x0106, 0x7000, 0xA82A);

    /**
     *  VideoMediaGetStallCount()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    VideoMediaGetStallCount(MediaHandler mh, unsigned long *stalls)
        FIVEWORDINLINE(0x2F3C, 0x0004, 0x010E, 0x7000, 0xA82A);

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
                                void *dataPtr, long dataSize)
        FIVEWORDINLINE(0x2F3C, 0x0014, 0x010F, 0x7000, 0xA82A);

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
                                OSType parameterID, Handle outParameterData)
        FIVEWORDINLINE(0x2F3C, 0x000C, 0x0110, 0x7000, 0xA82A);

    /*************************
     * Text Media routines
     **************************/

    // Return displayFlags for TextProc     enum
    {
        txtProcDefaultDisplay = 0, //    Use the media's default        txtProcDontDisplay = 1,    //    Don't display the text        txtProcDoDisplay = 2       //    Do display the text    };

    /**
     *  TextMediaSetTextProc()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
    // QTParseTextHREF inContainer atoms
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult// string
    TextMediaSetTextProc(MediaHandler mh, TextMediaUPP Tex// string
        FIVEWORDINLINE(0x2F3C, 0x0008, 0x0101, 0x7000, 0xA82A);

    /**
     *  TextMediaAddTextSample()
     *// boolean; if no kQTParseTextHREFDelimiter, delim is ':'
// character
     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    // QTParseTextHREF outContainer atoms
    TextMediaAddTextSample(MediaHandler mh, Ptr text, unsigned long size,
                           short fontNumber, short fontSize, Style textFace,
                           RGBColor *textColor, RGBColor *back// string
                           short textJustification, Rect *text// string
                           long displayFlags, TimeValue scroll// string
                           short hiliteStart, short hiliteEnd,// Boolean
                           RGBColor *rgbHiliteColor, TimeValue// Boolean
                           TimeValue *sampleTime)
        FIVEWORDINLINE(0x2F3C, 0x0034, 0x0102, 0x7000, 0xA82A);

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
                         TimeValue *sampleTime)
        FIVEWORDINLINE(0x2F3C, 0x0026, 0x0103, 0x7000, 0xA82A);

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
                             TimeValue *sampleTime)
        FIVEWORDINLINE(0x2F3C, 0x0010, 0x0104, 0x7000, 0xA82A);

    /**
     *  TextMediaDrawRaw()
     *// is really 'in'
// is really 'ty'
     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    TextMediaDrawRaw(MediaHandler mh, GWorldPtr gw, GDHandle gd, void *data,
                     long dataSize, TextDescriptionHandle tdh)
        FIVEWORDINLINE(0x2F3C, 0x0014, 0x0109, 0x7000, 0xA82A);

    /**
     *  TextMediaSetTextProperty()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */// was kTrackModifierTypeSpriteImage
    ComponentResult
    TextMediaSetTextProperty(MediaHandler mh, TimeValue atMediaTime,
                             long propertyType, void *data, long dataSize)
        FIVEWORDINLINE(0x2F3C, 0x0010, 0x010A, 0x7000, 0xA82A);

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
                      TimeValue sampleDuration)
        FIVEWORDINLINE(0x2F3C, 0x0018, 0x010B, 0x7000, 0xA82A);

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
                     TimeValue sampleTime, long flagsIn, long *flagsOut)
        FIVEWORDINLINE(0x2F3C, 0x0014, 0x010C, 0x7000, 0xA82A);

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
                             long propertyType, void *data, long dataSize)
        FIVEWORDINLINE(0x2F3C, 0x0010, 0x010D, 0x7000, 0xA82A);

    enum
    {
        findTextEdgeOK = 1 << 0,        // Okay to find text at specified sample time        findTextCaseSensitive = 1 << 1, // Case sensitive search        findTextReverseSearch = 1 << 2, // Search from sampleTime backwards        findTextWrapAround =
            1 << 3,                // Wrap search when beginning or end of movie is hit        findTextUseOffset = 1 << 4 /* Begin search at the given character offset into
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
                          TimeValue *foundDuration, long *offset)
        FIVEWORDINLINE(0x2F3C, 0x001A, 0x0105, 0x7000, 0xA82A);

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
                              RGBColor *rgbHiliteColor)
        FIVEWORDINLINE(0x2F3C, 0x000C, 0x0106, 0x7000, 0xA82A);

    enum
    // kTweenFlags
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
    TextMediaSetTextSampleData(MediaHandler mh, void *data, OSType dataType)
        FIVEWORDINLINE(0x2F3C, 0x0008, 0x0107, 0x7000, 0xA82A);

    /*************************
     * Sprite Media routines
     **************************/
    // flags for sprite hit test routines     enum
    {
        spriteHitTestBounds =
            1L << 0, //    point must only be within sprite's bounding box        spriteHitTestImage =
            1L << 1, //  point must be within the shape of the sprite's image        spriteHitTestInvisibleSprites =
            1L << 2,                    //  invisible sprites may be hit tested        spriteHitTestIsClick = 1L << 3, //  for codecs that want mouse events        spriteHitTestLocInDisplayCoordinates =
            1L << 4 /*    set if you want to pass a display coordiate point to
                       SpriteHitTest*/
    };
// 0 to 1 
    // atom types for sprite media     enum
    {
        kSpriteAtomType = FOUR_CHAR_CODE('sprt'),
        kSpriteImagesContainerAtomType = FOUR_CHAR_CODE('imct'),
        kSpriteImageAtomType = FOUR_CHAR_CODE('imag'),
        kSpriteImageDataAtomType = FOUR_CHAR_CODE('imda'),
        kSpriteImageDataRefAtomType = FOUR_CHAR_CODE('imre'),
        kSpriteImageDataRefTypeAtomType = FOUR_CHAR_CODE('imrt'),
        kSpriteImageGroupIDAt// default is 0 
        kSpriteImageRegistrationAtomType = FOUR_CHAR_CODE('imrg'),
        kSpriteImageDefaultImageIndexAtomType = FOUR_CHAR_CODE('defi'),
        kSpriteSharedDataAtomType = FOUR_CHAR_CODE('dflt'),
        kSpriteNameAtomType = FOUR_CHAR_CODE('name'),
        kSpriteImageNameAtomType = FOUR_CHAR_CODE('name'),
        kSpriteUsesImageIDsAtomType = FOUR_CHAR_CODE(
            'uses'), // leaf data is an array of QTAtomID's, one per image used        kSpriteBehaviorsAtomType = FOUR_CHAR_CODE('beha'),
        kSpriteImageBehaviorAtomType = FOUR_CHAR_CODE('imag'),
        kSpriteCursorBehaviorAtomType = FOUR_CHAR_CODE('crsr'),
        kSpriteStatusStringsBehaviorAtomType = FOUR_CHAR_CODE('sstr'),
        kSpriteVariablesContainerAtomType = FOUR_CHAR_CODE('vars'),
        kSpriteStringVariableAtomType = FOUR_CHAR_CODE('strv'),
        kSpriteFloatingPointVariableAtomType = FOUR_CHAR_CODE('flov')
    };

    struct QTRuntimeSpriteDescStruct
    {
// use these two routines at your own peril 
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
                           void *propertyValue)
        FIVEWORDINLINE(0x2F3C, 0x000A, 0x0101, 0x7000, 0xA82A);

    /**
     * // OLDROUTINENAMES 
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SpriteMediaGetProperty(MediaHandler mh, short spriteIndex, long propertyType,
                           void *propertyValue)
    // use these five routines at your own peril

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
                              short *spriteHitIndex)
        FIVEWORDINLINE(0x2F3C, 0x000C, 0x0103, 0x7000, 0xA82A);

    /**
     *  SpriteMediaCountSprites()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SpriteMediaCountSprites(MediaHandler mh, short *numSprites)
        FIVEWORDINLINE(0x2F3C, 0x0004, 0x0104, 0x7000, 0xA82A);

    /**
     *  SpriteMediaCountImages()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SpriteMediaCountImages(MediaHandler mh, short *numImages)
        FIVEWORDINLINE(0x2F3C, 0x0004, 0x0105, 0x7000, 0xA82A);

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
                                      ImageDescriptionHandle imageDescription)
        FIVEWORDINLINE(0x2F3C, 0x0006, 0x0106, 0x7000, 0xA82A);

    /**
     *  SpriteMediaGetDisplayedSampleNumber()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SpriteMediaGetDisplayedSampleNumber(MediaHandler mh, long *sampleNum)
        FIVEWORDINLINE(0x2F3C, 0x0004, 0x0107, 0x7000, 0xA82A);

    /**
     *  SpriteMediaGetSpriteName()
     *

    // Return displayFlags for TextProc 
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtml//    Use the media's default
     *///    Don't display the text
    ComponentResult//    Do display the text
    SpriteMediaGetSpriteName(MediaHandler mh, QTAtomID spriteID, Str255 spriteName)
        FIVEWORDINLINE(0x2F3C, 0x0008, 0x0108, 0x7000, 0xA82A);

    /**
     *  SpriteMediaGetImageName()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SpriteMediaGetImageName(MediaHandler mh, short imageIndex, Str255 imageName)
        FIVEWORDINLINE(0x2F3C, 0x0006, 0x0109, 0x7000, 0xA82A);

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
                                 long propertyType, void *propertyValue)
        FIVEWORDINLINE(0x2F3C, 0x000C, 0x010A, 0x7000, 0xA82A);

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
                                 long propertyType, void *propertyValue)
        FIVEWORDINLINE(0x2F3C, 0x000C, 0x010B, 0x7000, 0xA82A);

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
                                 QTAtomID *spriteHitID)
        FIVEWORDINLINE(0x2F3C, 0x000C, 0x010C, 0x7000, 0xA82A);

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
                                Point loc, Boolean *wasHit)
        FIVEWORDINLINE(0x2F3C, 0x0010, 0x010D, 0x7000, 0xA82A);

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
                               QTAtomID *spriteID)
        FIVEWORDINLINE(0x2F3C, 0x0006, 0x010E, 0x7000, 0xA82A);

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
                               short *spriteIndex)
        FIVEWORDINLINE(0x2F3C, 0x0008, 0x010F, 0x7000, 0xA82A);

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
                                          QTAtomContainer *container, QTAtom *atom)
        FIVEWORDINLINE(0x2F3C, 0x0010, 0x0110, 0x7000, 0xA82A);

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
                                 const float *value)
        FIVEWORDINLINE(0x2F3C, 0x0008, 0x0111, 0x7000, 0xA82A);

    /**
     *  SpriteMediaGetActionVariable()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SpriteMediaGetActionVariable(MediaHandler mh, QTAtomID variableID, float *value)
        FIVEWORDINLINE(0x2F3C, 0x0008, 0// Okay to find text at specified sample time
// Case sensitive search
    /**// Search from sampleTime backwards
     *  SpriteMediaGetIndImageProperty()
     *// Wrap search when beginning or end of movie is hit

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.1 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SpriteMediaGetIndImageProperty(MediaHandler mh, short imageIndex,
                                   long imagePropertyType, void *imagePropertyValue)
        FIVEWORDINLINE(0x2F3C, 0x000A, 0x0113, 0x7000, 0xA82A);

    /**
     *  SpriteMediaNewSprite()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    SpriteMediaNewSprite(MediaHandler mh, QTRuntimeSpriteDescPtr newSpriteDesc)
        FIVEWORDINLINE(0x2F3C, 0x0004, 0x0114, 0x7000, 0xA82A);

    /**
     *  SpriteMediaDisposeSprite()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    SpriteMediaDisposeSprite(MediaHandler mh, QTAtomID spriteID)
        FIVEWORDINLINE(0x2F3C, 0x0004, 0x0115, 0x7000, 0xA82A);

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
                                         Ptr theCString)
        FIVEWORDINLINE(0x2F3C, 0x0008, 0x0116, 0x7000, 0xA82A);

    /**
     *  SpriteMediaGetActionVariableAsString()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
    // flags for sprite hit test routines 
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult//    point must only be within sprite's bounding box
    SpriteMediaGetActionVariableAsString(MediaHandler mh, QTAtomID variableID,
                     //  point must be within the shape of the sprite's image
        FIVEWORDINLINE(0x2F3C, 0x0008, 0x0117, 0x7000, 0xA82A);
//  invisible sprites may be hit tested
    /*************************//  for codecs that want mouse events
     * Flash Media routines
     **************************/

    /**
     *  FlashMediaSetPan()
    // atom types for sprite media 

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    FlashMediaSetPan(MediaHandler mh, short xPercent, short yPercent)
        FIVEWORDINLINE(0x2F3C, 0x0004, 0x0101, 0x7000, 0xA82A);

    /**
     *  FlashMediaSetZoom()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib// leaf data is an array of QTAtomID's, one per image used
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    FlashMediaSetZoom(MediaHandler mh, short factor)
        FIVEWORDINLINE(0x2F3C, 0x0002, 0x0102, 0x7000, 0xA82A);

    /**
     *  FlashMediaSetZoomRect()
     *

     *    \non_carbon_// set to zero
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    FlashMediaSetZoomRect(MediaHandler mh, long left, long top, long right,
                          long bottom)
        FIVEWORDINLINE(0x2F3C, 0x0010, 0x0103, 0x7000, 0xA82A);

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
                              long *right, long *bottom)
        FIVEWORDINLINE(0x2F3C, 0x0014, 0x0104, 0x7000, 0xA82A);

    /**
     *  FlashMediaGetRefConID()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    FlashMediaGetRefConID(MediaHandler mh, long refCon, long *refConID)
        FIVEWORDINLINE(0x2F3C, 0x0008, 0x0105, 0x7000, 0xA82A);

    /**
     *  FlashMediaIDToRefCon()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    FlashMediaIDToRefCon(MediaHandler mh, long refConID, long *refCon)
        FIVEWORDINLINE(0x2F3C, 0x0008, 0x0106, 0x7000, 0xA82A);

    /**
     *  FlashMediaGetDisplayedFrameNumber()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    FlashMediaGetDisplayedFrameNumber(MediaHandler mh, long *flashFrameNumber)
        FIVEWORDINLINE(0x2F3C, 0x0004, 0x0107, 0x7000, 0xA82A);

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
                                     TimeValue *movieTime)
        FIVEWORDINLINE(0x2F3C, 0x0008, 0x0108, 0x7000, 0xA82A);

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
                                    TimeValue *movieTime)
        FIVEWORDINLINE(0x2F3C, 0x0008, 0x0109, 0x7000, 0xA82A);

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
                               Handle *theVariableCStringOut)
        FIVEWORDINLINE(0x2F3C, 0x000C, 0x010A, 0x7000, 0xA82A);

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
                               Boolean updateFocus)
        FIVEWORDINLINE(0x2F3C, 0x000E, 0x010B, 0x7000, 0xA82A);

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
                              long transition)
        FIVEWORDINLINE(0x2F3C, 0x000C, 0x010C, 0x7000, 0xA82A);

    /**
     *  FlashMediaGetSupportedSwfVersion()
     *

     *    \non_carbon_cfm   in QuickTimeLib 5.0 and later
     *    \carbon_lib        in CarbonLib 1.3 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 5.0 and later
     */
    ComponentResult
    FlashMediaGetSupportedSwfVersion(MediaHandler mh, unsigned char *swfVersion)
        FIVEWORDINLINE(0x2F3C, 0x0004, 0x010D, 0x7000, 0xA82A);

    // sample format atoms    enum
    {
        kMovieMediaDataReference = FOUR_CHAR_CODE('mmdr'),          // data reference        kMovieMediaDefaultDataReferenceID = FOUR_CHAR_CODE('ddri'), // atom id        kMovieMediaSlaveTime = FOUR_CHAR_CODE('slti'),              // boolean        kMovieMediaSlaveAudio = FOUR_CHAR_CODE('slau'),             // boolean        kMovieMediaSlaveGraphicsMode = FOUR_CHAR_CODE('slgr'),      // boolean        kMovieMediaAutoPlay = FOUR_CHAR_CODE('play'),               // boolean        kMovieMediaLoop =
            FOUR_CHAR_CODE('loop'), // UInt8 (0=no loop, 1=loop, 2=palindrome loop)        kMovieMediaUseMIMEType =
            FOUR_CHAR_CODE('mime'), /* string indicating the MIME type to use for the
                                       dataref (usually not required)*/
        kMovieMediaTitle =
            FOUR_CHAR_CODE('titl'), // string of the media's title (tooltips)        kMovieMediaAltText = FOUR_CHAR_CODE(
            'altt'), // string of alternate text if media isn't loaded        kMovieMediaClipBegin = FOUR_CHAR_CODE(
            'clpb'), // MovieMediaTimeRecord of start time of embedded media        kMovieMediaClipDuration = FOUR_CHAR_CODE(
            'clpd'), // MovieMediaTimeRecord of duration of embedded media        kMovieMediaRegionAtom =
            FOUR_CHAR_CODE('regi'), // contains subatoms that describe layout        kMovieMediaSlaveTrackDuration = FOUR_CHAR_CODE(
            'sltr'), /* Boolean indicating that media handler should adjust track and
                        media based on actual embedded movie duration*/
        kMovieMediaEnableFrameStepping =
            FOUR_CHAR_CODE('enfs'),                          /* boolean. if true stepping on external movie
                                                                steps frames within embedded movie.*/
        kMovieMediaBackgroundColor = FOUR_CHAR_CODE('bkcl'), // RGBColor.        kMovieMediaPrerollTime =
            FOUR_CHAR_CODE('prer') // SInt32 indicating preroll time    };

    // fit types    enum
    {
        kMovieMediaFitNone = 0,
        kMovieMediaFitScroll = FOUR_CHAR_CODE('scro'),
        kMovieMediaFitClipIfNecessary = FOUR_CHAR_CODE('hidd'),
        kMovieMediaFitFill = FOUR_CHAR_CODE('fill'),
        kMovieMediaFitMeet = FOUR_CHAR_CODE('meet'),
        kMovieMediaFitSlice = FOUR_CHAR_CODE('slic')
    };

    // sub atoms for region atom    enum
    {
        kMovieMediaSpatialAdjustment =
            FOUR_CHAR_CODE('fit '), // OSType from kMovieMediaFit*        kMovieMediaRectangleAtom = FOUR_CHAR_CODE('rect'),
        kMovieMediaTop = FOUR_CHAR_CODE('top '),
        kMovieMediaLeft = FOUR_CHAR_CODE('left'),
        kMovieMediaWidth = FOUR_CHAR_CODE('wd  '),
        kMovieMediaHeight = FOUR_CHAR_CODE('ht  ')
    };

    // contained movie properties    enum
    {
        kMoviePropertyDuration = FOUR_CHAR_CODE('dura'),      // TimeValue *        kMoviePropertyTimeScale = FOUR_CHAR_CODE('tims'),     // TimeValue *        kMoviePropertyTime = FOUR_CHAR_CODE('timv'),          // TimeValue *        kMoviePropertyNaturalBounds = FOUR_CHAR_CODE('natb'), // Rect *        kMoviePropertyMatrix = FOUR_CHAR_CODE('mtrx'),        // Matrix *        kMoviePropertyTrackList = FOUR_CHAR_CODE('tlst')      // long ***    };

    enum
    {
        kTrackPropertyMediaType = FOUR_CHAR_CODE('mtyp'), // OSType        kTrackPropertyInstantiation =
            FOUR_CHAR_CODE('inst') // MovieMediaInstantiationInfoRecord    };

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
                                         long *refcon)
        FIVEWORDINLINE(0x2F3C, 0x0008, 0x0102, 0x7000, 0xA82A);

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
                                    long *refcon)
        FIVEWORDINLINE(0x2F3C, 0x0008, 0x0103, 0x7000, 0xA82A);

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
                                      void *value)
        FIVEWORDINLINE(0x2F3C, 0x0008, 0x0104, 0x7000, 0xA82A);

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
                                      OSType whichProperty, void *value)
        FIVEWORDINLINE(0x2F3C, 0x000C, 0x0105, 0x7000, 0xA82A);

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
                                         short *dataRefIndexOut)
        FIVEWORDINLINE(0x2F3C, 0x0016, 0x0106, 0x7000, 0xA82A);

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
                                         OSType dataRefType, Handle dataRef)
        FIVEWORDINLINE(0x2F3C, 0x000C, 0x0107, 0x7000, 0xA82A);

    /**
     *  MovieMediaLoadChildMovieFromDataReference()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.1 and later
     *    \carbon_lib        in CarbonLib 1.1 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.1 and later
     */
    ComponentResult
    MovieMediaLoadChildMovieFromDataReference(MediaHandler mh, QTAtomID dataRefID)
        FIVEWORDINLINE(0x2F3C, 0x0004, 0x0108, 0x7000, 0xA82A);

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
    Media3DGetNamedObjectList(MediaHandler mh, QTAtomContainer *objectList)
        FIVEWORDINLINE(0x2F3C, 0x0004, 0x0101, 0x7000, 0xA82A);

    /**
     *  Media3DGetRendererList()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    Media3DGetRendererList(MediaHandler mh, QTAtomContainer *rendererList)
        FIVEWORDINLINE(0x2F3C, 0x0004, 0x0102, 0x7000, 0xA82A);

    /**
     *  Media3DGetCurrentGroup()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    Media3DGetCurrentGroup(MediaHandler mh, void *group)
        FIVEWORDINLINE(0x2F3C, 0x0004, 0x0103, 0x7000, 0xA82A);

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
                                  Fixed y, Fixed z)
        FIVEWORDINLINE(0x2F3C, 0x0010, 0x0104, 0x7000, 0xA82A);

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
                              Fixed yScale, Fixed zScale)
        FIVEWORDINLINE(0x2F3C, 0x0010, 0x0105, 0x7000, 0xA82A);

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
                               Fixed yDegrees, Fixed zDegrees)
        FIVEWORDINLINE(0x2F3C, 0x0010, 0x0106, 0x7000, 0xA82A);

    /**
     *  Media3DSetCameraData()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    Media3DSetCameraData(MediaHandler mh, void *cameraData)
        FIVEWORDINLINE(0x2F3C, 0x0004, 0x0107, 0x7000, 0xA82A);

    /**
     *  Media3DGetCameraData()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    Media3DGetCameraData(MediaHandler mh, void *cameraData)
        FIVEWORDINLINE(0x2F3C, 0x0004, 0x0108, 0x7000, 0xA82A);

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
                                QTFloatSingle aspectRatioXToY)
        FIVEWORDINLINE(0x2F3C, 0x0008, 0x0109, 0x7000, 0xA82A);

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
                                QTFloatSingle *aspectRatioXToY)
        FIVEWORDINLINE(0x2F3C, 0x0008, 0x010A, 0x7000, 0xA82A);

    /**
     *  Media3DSetCameraRange()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    Media3DSetCameraRange(MediaHandler mh, void *tQ3CameraRange)
        FIVEWORDINLINE(0x2F3C, 0x0004, 0x010D, 0x7000, 0xA82A);

    /**
     *  Media3DGetCameraRange()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    Media3DGetCameraRange(MediaHandler mh, void *tQ3CameraRange)
        FIVEWORDINLINE(0x2F3C, 0x0004, 0x010E, 0x7000, 0xA82A);

    /**
     *  Media3DGetViewObject()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.1 and later
     *    \carbon_lib        in CarbonLib 1.1 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.1 and later
     */
    ComponentResult
    Media3DGetViewObject(MediaHandler mh, void *tq3viewObject)
        FIVEWORDINLINE(0x2F3C, 0x0004, 0x010F, 0x7000, 0xA82A);

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
        mcActionIdle = 1,                   // no param        mcActionDraw = 2,                   // param is WindowRef        mcActionActivate = 3,               // no param        mcActionDeactivate = 4,             // no param        mcActionMouseDown = 5,              // param is pointer to EventRecord        mcActionKey = 6,                    // param is pointer to EventRecord        mcActionPlay = 8,                   // param is Fixed, play rate        mcActionGoToTime = 12,              // param is TimeRecord        mcActionSetVolume = 14,             // param is a short        mcActionGetVolume = 15,             // param is pointer to a short        mcActionStep = 18,                  // param is number of steps (short)        mcActionSetLooping = 21,            // param is Boolean        mcActionGetLooping = 22,            // param is pointer to a Boolean        mcActionSetLoopIsPalindrome = 23,   // param is Boolean        mcActionGetLoopIsPalindrome = 24,   // param is pointer to a Boolean        mcActionSetGrowBoxBounds = 25,      // param is a Rect        mcActionControllerSizeChanged = 26, // no param        mcActionSetSelectionBegin = 29,     // param is TimeRecord        mcActionSetSelectionDuration =
            30,                         // param is TimeRecord, action only taken on set-duration        mcActionSetKeysEnabled = 32,    // param is Boolean        mcActionGetKeysEnabled = 33,    // param is pointer to Boolean        mcActionSetPlaySelection = 34,  // param is Boolean        mcActionGetPlaySelection = 35,  // param is pointer to Boolean        mcActionSetUseBadge = 36,       // param is Boolean        mcActionGetUseBadge = 37,       // param is pointer to Boolean        mcActionSetFlags = 38,          // param is long of flags        mcActionGetFlags = 39,          // param is pointer to a long of flags        mcActionSetPlayEveryFrame = 40, // param is Boolean        mcActionGetPlayEveryFrame = 41, // param is pointer to Boolean        mcActionGetPlayRate = 42,       // param is pointer to Fixed        mcActionShowBalloon =
            43, // param is a pointer to a boolean. set to false to stop balloon        mcActionBadgeClick =
            44,                                // param is pointer to Boolean. set to false to ignore click        mcActionMovieClick = 45,               /* param is pointer to event record. change "what" to
                                                  nullEvt to kill click*/
        mcActionSuspend = 46,                  // no param        mcActionResume = 47,                   // no param        mcActionSetControllerKeysEnabled = 48, // param is Boolean        mcActionGetTimeSliderRect = 49,        // param is pointer to rect        mcActionMovieEdited = 50,              // no param        mcActionGetDragEnabled = 51,           // param is pointer to Boolean        mcActionSetDragEnabled = 52,           // param is Boolean        mcActionGetSelectionBegin = 53,        // param is TimeRecord        mcActionGetSelectionDuration = 54,     // param is TimeRecord        mcActionPrerollAndPlay = 55,           // param is Fixed, play rate        mcActionGetCursorSettingEnabled = 56,  // param is pointer to Boolean        mcActionSetCursorSettingEnabled = 57,  // param is Boolean        mcActionSetColorTable = 58,            // param is CTabHandle        mcActionLinkToURL = 59,                // param is Handle to URL        mcActionCustomButtonClick = 60,        // param is pointer to EventRecord        mcActionForceTimeTableUpdate = 61,     // no param        mcActionSetControllerTimeLimits =
            62,                                   /* param is pointer to 2 time values min/max. do no send this message
                                                     to controller. used internally only.*/
    // sample format atoms
                                                     message parameter)*/
        mcActionUseTrackForTimeTable =
            66, /* param is pointer to {long trackID; Boolean useIt}// data reference
                   message to controller. */// atom id
        mcActionClickAndHoldPoint =// boolean
            67,                          /* param is point (local co// boolean
                                            & hold action (e.g., VR // boolean
        mcActionShowMessageString = 68,  // param is a StringPtr    // boolean
        mcActionDoScript = 78,      // param is QTDoScriptPtr        mcActionRestartAtTime = 79, // param is QTResartAtTimePtr        mcActionGetIndChapter = 80, // param is QTChapterInfoPtr        mcActionLinkToURLExtended =
            81,                     // UInt8 (0=no loop, 1=loop, 2=palindrome loop)
                                            via arrow keys - default = 64*/
        mcActionAutoPlay = 83,           // param is Fixed, play rate        mcActionPauseToBuffer = 84,      // param is Fixed, play rate on restart        mcActionAppMessageReceived = 85, // param is a long, application message        mcActionEvaluateExpressionWithType =
            89,                     // param is a QTEvaluateExpressionWithTypePtr        mcActionGetMovieName = 90,  // param is a p String Handle        mcActionGetMovieID = 91,    // param is pointer to long        mcActionGetMovieActive = 92 // param is pointer to Boolean    };

    typedef short mcAction;// string of the media's title (tooltips)
    enum
    {// string of alternate text if media isn't loaded
        mcFlagSuppressMovieFrame = 1 << 0,
        mcFlagSuppres// MovieMediaTimeRecord of start time of embedded media
        mcFlagSuppressSpeakerButton = 1 << 2,
        mcFlagsUseWin// MovieMediaTimeRecord of duration of embedded media
        mcFlagsDontInvalidate = 1 << 4,
        mcFlagsUseCustomButton = 1 <// contains subatoms that describe layout
    };

    enum
    {
        mcPositionDontInvalidate = 1 << 5
    };
// RGBColor.
    typedef unsigned long mcFlags;
    enum// SInt32 indicating preroll time
    {
        kMCIEEnabledButtonPicture = 1,
    // fit types
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
    // sub atoms for region atom

    typedef unsigned long MCInterfaceElement;
    typedef CALLBACK_API(Boolean, MCActionFilterProcPtr)(MovieController mc,
                                    // OSType from kMovieMediaFit*
                                                         void *params);
    typedef CALLBACK_API(Boolean, MCActionFilterWithRefConProcPtr)(
        MovieController mc, short action, void *params, long refCon);
    typedef STACK_UPP_TYPE(MCActionFilterProcPtr) MCActionFilterUPP;
    typedef STACK_UPP_TYPE(MCActionFilterWithRefConProcPtr)
        MCActionFilterWithRefConUPP;
    /**
    // contained movie properties
    */
    enum
    {// TimeValue *
        mcInfoUndoAvailable = 1 << 0,// TimeValue *
        mcInfoCutAvailable = 1 << 1,// TimeValue *
        mcInfoCopyAvailable = 1 << 2,// Rect *
        mcInfoPasteAvailable = 1 << 3,// Matrix *
        mcInfoClearAvailable = 1 << 4,// long ***
        mcInfoHasSound = 1 << 5,
        mcInfoIsPlaying = 1 << 6,
        mcInfoIsLooping = 1 << 7,
        mcInfoIsInPalindrome = 1 << 8,
        mcInfoEditingEnabled = 1 << 9,// OSType
        mcInfoMovieIsInteractive = 1 << 10
    };// MovieMediaInstantiationInfoRecord

    // menu item codes    enum
    {
        mcMenuUndo = 1,
        mcMenuCut = 3,
        mcMenuCopy = 4,
        mcMenuPaste = 5,
        mcMenuClear = 6
    };

    // messages to the application via mcActionAppMessageReceived    enum
    {
        kQTAppMessageSoftwareChanged = 1, /* notification to app that installed
                                             QuickTime software has been updated*/
        kQTAppMessageWindowCloseRequested =
            3, // request for app to close window containing movie controller        kQTAppMessageExitFullScreenRequested =
            4, // request for app to turn off full screen mode if active        kQTAppMessageDisplayChannels =
            5, // request for app to display the channel UI        kQTAppMessageEnterFullScreenRequested =
            6 // request for app to turn on full screen mode    };

    // structures used as mcActionFilterProc params    struct QTStatusStringRecord
    {
        long stringTypeFlags;
        char *statusString;
    };
    typedef struct QTStatusStringRecord QTStatusStringRecord;
    typedef QTStatusStringRecord *QTStatusStringPtr;
    struct QTGetExternalMovieRecord
    {
        long targetType; // set to kTargetMovieName or kTargetMovieID        StringPtr movieName;
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
        long index;     // first chapter has index of 1        TimeValue time; // -1 if no more chapters available        Str255 name;
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
        long recordSize; // Size of structure (fill in at allocation)         QTAtomSpec expressionSpec;
        float *expressionResult;
        long fetchAsType;
        Handle nonNumericResult;
        // Current size is 24     };
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
        TimeValue startTime; // time scale is the movie timescale        Fixed rate;          // if rate is zero, the movie's current rate is maintained    };
    typedef struct QTRestartAtTimeRecord QTRestartAtTimeRecord;
    typedef QTRestartAtTimeRecord *QTRestartAtTimePtr;
    // values for paramType field of QTFetchParameterAsRecord    enum
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
        kFetchAsRgnHandle = 14, // flipped to native        kFetchAsComponentDescriptionPtr = 15,
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

    // target management     /**
     *  MCSetMovie()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MCSetMovie(MovieController mc, Movie theMovie, WindowRef movieWindow,
               Point where) FIVEWORDINLINE(0x2F3C, 0x000C, 0x0002, 0x7000, 0xA82A);

    /**
     *  MCGetIndMovie()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    Movie
    MCGetIndMovie(MovieController mc, short index)
        FIVEWORDINLINE(0x2F3C, 0x0002, 0x0005, 0x7000, 0xA82A);

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
    MCRemoveAllMovies(MovieController mc)
        FIVEWORDINLINE(0x2F3C, 0x0000, 0x0006, 0x7000, 0xA82A);

    /**
     *  MCRemoveAMovie()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MCRemoveAMovie(MovieController mc, Movie m)
        FIVEWORDINLINE(0x2F3C, 0x0004, 0x0003, 0x7000, 0xA82A);

    /**
     *  MCRemoveMovie()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MCRemoveMovie(MovieController mc)
        FIVEWORDINLINE(0x2F3C, 0x0000, 0x0006, 0x7000, 0xA82A);

    // event handling etc.     /**
     *  MCIsPlayerEvent()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MCIsPlayerEvent(MovieController mc, const EventRecord *e)
        FIVEWORDINLINE(0x2F3C, 0x0004, 0x0007, 0x7000, 0xA82A);

    // obsolete. use MCSetActionFilterWithRefCon instead.     /**
     *  MCSetActionFilter()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MCSetActionFilter(MovieController mc, MCActionFilterUPP blob)
        FIVEWORDINLINE(0x2F3C, 0x0004, 0x0008, 0x7000, 0xA82A);

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
    MCDoAction(MovieController mc, short action, void *params)
        FIVEWORDINLINE(0x2F3C, 0x0006, 0x0009, 0x7000, 0xA82A);

    // state type things     /**
     *  MCSetControllerAttached()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MCSetControllerAttached(MovieController mc, Boolean attach)
        FIVEWORDINLINE(0x2F3C, 0x0002, 0x000A, 0x7000, 0xA82A);

    /**
     *  MCIsControllerAttached()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MCIsControllerAttached(MovieController mc)
        FIVEWORDINLINE(0x2F3C, 0x0000, 0x000B, 0x7000, 0xA82A);

    /**
     *  MCSetControllerPort()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MCSetControllerPort(MovieController mc, CGrafPtr gp)
        FIVEWORDINLINE(0x2F3C, 0x0004, 0x000C, 0x7000, 0xA82A);

    /**
     *  MCGetControllerPort()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    CGrafPtr
    MCGetControllerPort(MovieController mc)
        FIVEWORDINLINE(0x2F3C, 0x0000, 0x000D, 0x7000, 0xA82A);

    /**
     *  MCSetVisible()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MCSetVisible(MovieController mc, Boolean visible)
        FIVEWORDINLINE(0x2F3C, 0x0002, 0x000E, 0x7000, 0xA82A);

    /**
     *  MCGetVisible()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */// no param
    ComponentResult// param is WindowRef
    MCGetVisible(MovieController mc)// no param
        FIVEWORDINLINE(0x2F3C, 0x0000, 0x000// no param
// param is pointer to EventRecord
    /**// param is pointer to EventRecord
     *  MCGetControllerBoundsRect()// param is Fixed, play rate
     *// param is TimeRecord
// param is a short
     *    \non_carbon_cfm   in QuickTimeLib // param is pointer to a short
     *    \carbon_lib        in CarbonLib 1.// param is number of steps (short)
     *    \mac_os_x         in version 10.0 // param is Boolean
     *    Windows:          in qtmlClient.li// param is pointer to a Boolean
     */// param is Boolean
    ComponentResult// param is pointer to a Boolean
    MCGetControllerBoundsRect(MovieControlle// param is a Rect
        FIVEWORDINLINE(0x2F3C, 0x0004, 0x001// no param
// param is TimeRecord
    /**
     *  MCSetControllerBoundsRect()// param is TimeRecord, action only taken on set-duration
     *// param is Boolean
// param is pointer to Boolean
     *    \non_carbon_cfm   in QuickTime// param is Boolean
     *    \carbon_lib        in CarbonLi// param is pointer to Boolean
     *    \mac_os_x         in version 1// param is Boolean
     *    Windows:          in qtmlClien// param is pointer to Boolean
     */// param is long of flags
    ComponentResult// param is pointer to a long of flags
    MCSetControllerBoundsRect(MovieContr// param is Boolean
        FIVEWORDINLINE(0x2F3C, 0x0004, 0// param is pointer to Boolean
// param is pointer to Fixed
    /**
     *  MCGetCon// param is a pointer to a boolean. set to false to stop balloon
     *
// param is pointer to Boolean. set to false to ignore click
     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and// no param
     *    Windows:          in qtmlClient.lib 3// no param
     */// param is Boolean
    RgnHandle// param is pointer to rect
    MCGetControllerBoundsRgn(MovieController mc// no param
        FIVEWORDINLINE(0x2F3C, 0x0000, 0x0012, // param is pointer to Boolean
// param is Boolean
    /**// param is TimeRecord
     *  MCGetWindowRgn()// param is TimeRecord
     *// param is Fixed, play rate
// param is pointer to Boolean
     *    \non_carbon_cfm   in QuickTimeLib 2.5// param is Boolean
     *    \carbon_lib        in CarbonLib 1.0 a// param is CTabHandle
     *    \mac_os_x         in version 10.0 and// param is Handle to URL
     *    Windows:          in qtmlClient.lib 3// param is pointer to EventRecord
     */// no param
    RgnHandle
    MCGetWindowRgn(MovieController mc, WindowRef w)
        FIVEWORDINLINE(0x2F3C, 0x0004, 0x0013, 0x7000, 0xA82A);
// param is ResolvedQTEventSpecPtr
    // other stuff     /**// param is ResolvedQTEventSpecPtr
     *  MCMovieChanged()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult// param is a StringPtr
    MCMovieChanged(MovieController mc, Mo// param is a QTStatusStringPtr
        FIVEWORDINLINE(0x2F3C, 0x0004, 0x// param is a QTGetExternalMoviePtr
// param is a QTGetChapterTimePtr
    /**// param is a QTAtomSpecPtr
        called when the app has changed t// param is a QTEvaluateExpressionPtr
       or rate. So that we can update our// param is a QTFetchParameterAsPtr
       accordingly.// param is a QTGetCursorByIDPtr
    */// param is a Handle to URL
    /**
     *  MCSetDuration()// param is QTDoScriptPtr
     *// param is QTResartAtTimePtr
// param is QTChapterInfoPtr
     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib// param is QTAtomContainer as used by QTParseHREF
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */// param is Fixed, play rate
    ComponentResult// param is Fixed, play rate on restart
    MCSetDuration(MovieController mc, Tim// param is a long, application message
        FIVEWORDINLINE(0x2F3C, 0x0004, 0x0015, 0x7000, 0xA82A);
// param is a QTEvaluateExpressionWithTypePtr
    /**// param is a p String Handle
        duration to use for time sli// param is pointer to long
       called or MCSetMovie is calle// param is pointer to Boolean
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
    MCGetCurrentTime(MovieController mc, TimeScale *scale)
        FIVEWORDINLINE(0x2F3C, 0x0004, 0x0016, 0x7000, 0xA82A);

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
                            Point where)
        FIVEWORDINLINE(0x2F3C, 0x000C, 0x0017, 0x7000, 0xA82A);

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
    MCDraw(MovieController mc, WindowRef w)
        FIVEWORDINLINE(0x2F3C, 0x0004, 0x0018, 0x7000, 0xA82A);

    /**
     *  MCActivate()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MCActivate(MovieController mc, WindowRef w, Boolean activate)
    // menu item codes

    /**
     *  MCIdle()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
    // messages to the application via mcActionAppMessageReceived
    ComponentResult
    MCIdle(MovieController mc)
        FIVEWORDINLINE(0x2F3C, 0x0000, 0x001A, 0x7000, 0xA82A);

    /**
     *  MCKey()// request for app to close window containing movie controller
     *
// request for app to turn off full screen mode if active
     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carb// request for app to display the channel UI
     *    \mac_os_x         in version 10.0 and later
     *    Wind// request for app to turn on full screen mode
     */
    ComponentResult
    // structures used as mcActionFilterProc params
        FIVEWORDINLINE(0x2F3C, 0x0006, 0x001B, 0x7000, 0xA82A);

    /**
     *  MCClick()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:       // set to kTargetMovieName or kTargetMovieID
     */
    ComponentResult
    MCClick(MovieController mc, WindowRef w, Point where, long when, long modifiers)
        FIVEWORDINLINE(0x2F3C, 0x0010, 0x001C, 0x7000, 0xA82A);

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
     */// first chapter has index of 1
    ComponentResult// -1 if no more chapters available
    MCEnableEditing(MovieController mc, Boolean enabled)
        FIVEWORDINLINE(0x2F3C, 0x0002, 0x001D, 0x7000, 0xA82A);

    /**
     *  MCIsEditingEnabled()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    long
    MCIsEditingEnabled(Mo// Size of structure (fill in at allocation) 
        FIVEWORDINLINE(0x2F3C, 0x0000, 0x001E, 0x7000, 0xA82A);

    /**
     *  MCCopy()
     *// Current size is 24 

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    Movie
    MCCopy(MovieController mc)
        FIVEWORDINLINE(0x2F3C, 0x0000, 0x001F, 0x7000, 0xA82A);

    /**
     *  MCCut()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    Movie
    MCCut(MovieController mc)
        FIVEWORDINLINE(0x2F3C, 0x0000, 0x0020, 0x7000, 0xA82A);

    /**
     *  MCPaste()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MCPaste(MovieController mc, Movie srcMovie)
        FIVEWORDINLINE(0x2F3C, 0x0004, 0x0021, 0x7000, 0xA82A);

    /**// time scale is the movie timescale
     *  MCClear()// if rate is zero, the movie's current rate is maintained
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
    // values for paramType field of QTFetchParameterAsRecord
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MCClear(MovieController mc)
        FIVEWORDINLINE(0x2F3C, 0x0000, 0x0022, 0x7000, 0xA82A);

    /**
     *  MCUndo()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */// flipped to native
    ComponentResult
    MCUndo(MovieController mc)
        FIVEWORDINLINE(0x2F3C, 0x0000, 0x0023, 0x7000, 0xA82A);

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
    // target management 
    MCPositionController(MovieController mc, const Rect *movieRect,
                         const Rect *controllerRect, long someFlags)
        FIVEWORDINLINE(0x2F3C, 0x000C, 0x0024, 0x7000, 0xA82A);

    /**
     *  MCGetControllerInfo()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MCGetControllerInfo(MovieController mc, long *someFlags)
        FIVEWORDINLINE(0x2F3C, 0x0004, 0x0025, 0x7000, 0xA82A);

    /**
     *  MCSetClip()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MCSetClip(MovieController mc, RgnHandle theClip, RgnHandle movieClip)
        FIVEWORDINLINE(0x2F3C, 0x0008, 0x0028, 0x7000, 0xA82A);

    /**
     *  MCGetClip()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MCGetClip(MovieController mc, RgnHandle *theClip, RgnHandle *movieClip)
        FIVEWORDINLINE(0x2F3C, 0x0008, 0x0029, 0x7000, 0xA82A);

    /**
     *  MCDrawBadge()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MCDrawBadge(MovieController mc, RgnHandle movieRgn, RgnHandle *badgeRgn)
        FIVEWORDINLINE(0x2F3C, 0x0008, 0x002A, 0x7000, 0xA82A);

    /**
     *  MCSetUpEditMenu()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    // event handling etc. 
        FIVEWORDINLINE(0x2F3C, 0x0008, 0x002B, 0x7000, 0xA82A);

    /**
     *  MCGetMenuString()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MCGetMenuString(MovieController mc, long modifiers, short item, Str255 aString)
    // obsolete. use MCSetActionFilterWithRefCon instead. 

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
                                MCActionFilterWithRefConUPP blob, long refCon)
        FIVEWORDINLINE(0x2F3C, 0x0008, 0x002D, 0x7000, 0xA82A);

    /**
     *  MCPtInController()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MCPtInController(MovieController mc, Point thePt, Boolean *inController)
        FIVEWORDINLINE(0x2F3C, 0x0008, 0x002E, 0x7000, 0xA82A);

    /**
     *  MCInvalidate()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
    // state type things 
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MCInvalidate(MovieController mc, WindowRef w, RgnHandle invalidRgn)
        FIVEWORDINLINE(0x2F3C, 0x0008, 0x002F, 0x7000, 0xA82A);

    /**
     *  MCAdjustCursor()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MCAdjustCursor(MovieController mc, WindowRef w, Point where, long modifiers)
        FIVEWORDINLINE(0x2F3C, 0x000C, 0x0030, 0x7000, 0xA82A);

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
                          void *element)
        FIVEWORDINLINE(0x2F3C, 0x0008, 0x0031, 0x7000, 0xA82A);

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
                       long *doMCActionRefCon)
        FIVEWORDINLINE(0x2F3C, 0x0008, 0x0032, 0x7000, 0xA82A);

    /**
     *  MCAddMovieSegment()
     *

     *    \non_carbon_cfm   in QuickTimeLib 5.0 and later
     *    \carbon_lib        in CarbonLib 1.3 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 5.0 and later
     */
    ComponentResult
    MCAddMovieSegment(MovieController mc, Movie srcMovie, Boolean scaled)
        FIVEWORDINLINE(0x2F3C, 0x0006, 0x0033, 0x7000, 0xA82A);

    /**
     *  MCTrimMovieSegment()
     *

     *    \non_carbon_cfm   in QuickTimeLib 5.0 and later
     *    \carbon_lib        in CarbonLib 1.3 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 5.0 and later
     */
    ComponentResult
    MCTrimMovieSegment(MovieController mc)
        FIVEWORDINLINE(0x2F3C, 0x0000, 0x0034, 0x7000, 0xA82A);

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
    NewTimeBase(void) THREEWORDINLINE(0x303C, 0x00A5, 0xAAAA);

    /**
     *  DisposeTimeBase()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    DisposeTimeBase(TimeBase tb) THREEWORDINLINE(0x303C, 0x00B6, 0xAAAA);

    /**
     *  GetTimeBaseTime()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    TimeValue
    GetTimeBaseTime(TimeBase tb, TimeScale s, TimeRecord *tr)
        THREEWORDINLINE(0x303C, 0x00A6, 0xAAAA);

    /**
     *  SetTimeBaseTime()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SetTimeBaseTime(TimeBase tb, const TimeRecord *tr)
        THREEWORDINLINE(0x303C, 0x00A7, 0xAAAA);

    /**
     *  SetTimeBaseValue()
    // other stuff 

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SetTimeBaseValue(TimeBase tb, TimeValue t, TimeScale s)
        THREEWORDINLINE(0x303C, 0x00A8, 0xAAAA);

    /**
     *  GetTimeBaseRate()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    Fixed
    GetTimeBaseRate(TimeBase tb) THREEWORDINLINE(0x303C, 0x00A9, 0xAAAA);

    /**
     *  SetTimeBaseRate()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SetTimeBaseRate(TimeBase tb, Fixed r) THREEWORDINLINE(0x303C, 0x00AA, 0xAAAA);

    /**
     *  GetTimeBaseStartTime()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    TimeValue
    GetTimeBaseStartTime(TimeBase tb, TimeScale s, TimeRecord *tr)
        THREEWORDINLINE(0x303C, 0x00AB, 0xAAAA);

    /**
     *  SetTimeBaseStartTime()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SetTimeBaseStartTime(TimeBase tb, const TimeRecord *tr)
        THREEWORDINLINE(0x303C, 0x00AC, 0xAAAA);

    /**
     *  GetTimeBaseStopTime()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    TimeValue
    GetTimeBaseStopTime(TimeBase tb, TimeScale s, TimeRecord *tr)
        THREEWORDINLINE(0x303C, 0x00AD, 0xAAAA);

    /**
     *  SetTimeBaseStopTime()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SetTimeBaseStopTime(TimeBase tb, const TimeRecord *tr)
        THREEWORDINLINE(0x303C, 0x00AE, 0xAAAA);

    /**
     *  GetTimeBaseFlags()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    long
    GetTimeBaseFlags(TimeBase tb) THREEWORDINLINE(0x303C, 0x00B1, 0xAAAA);

    /**
     *  SetTimeBaseFlags()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SetTimeBaseFlags(TimeBase tb, long timeBaseFlags)
        THREEWORDINLINE(0x303C, 0x00B2, 0xAAAA);

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
                              const TimeRecord *slaveZero)
        THREEWORDINLINE(0x303C, 0x00B4, 0xAAAA);

    /**
     *  GetTimeBaseMasterTimeBase()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    TimeBase
    GetTimeBaseMasterTimeBase(TimeBase tb) THREEWORDINLINE(0x303C, 0x00AF, 0xAAAA);

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
                           const TimeRecord *slaveZero)
        THREEWORDINLINE(0x303C, 0x00B3, 0xAAAA);

    /**
     *  GetTimeBaseMasterClock()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentInstance
    GetTimeBaseMasterClock(TimeBase tb) THREEWORDINLINE(0x303C, 0x00B0, 0xAAAA);

    /**
     *  ConvertTime()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    ConvertTime(TimeRecord *theTime, TimeBase newBase)
        THREEWORDINLINE(0x303C, 0x00B5, 0xAAAA);

    /**
     *  ConvertTimeScale()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    ConvertTimeScale(TimeRecord *theTime, TimeScale newScale)
        THREEWORDINLINE(0x303C, 0x00B7, 0xAAAA);

    /**
     *  AddTime()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    AddTime(TimeRecord *dst, const TimeRecord *src)
        THREEWORDINLINE(0x303C, 0x010C, 0xAAAA);

    /**
     *  SubtractTime()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SubtractTime(TimeRecord *dst, const TimeRecord *src)
        THREEWORDINLINE(0x303C, 0x010D, 0xAAAA);

    /**
     *  GetTimeBaseStatus()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    long
    GetTimeBaseStatus(TimeBase tb, TimeRecord *unpinnedTime)
        THREEWORDINLINE(0x303C, 0x010B, 0xAAAA);

    /**
     *  SetTimeBaseZero()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    SetTimeBaseZero(TimeBase tb, TimeRecord *zero)
        THREEWORDINLINE(0x303C, 0x0128, 0xAAAA);

    /**
     *  GetTimeBaseEffectiveRate()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    Fixed
    GetTimeBaseEffectiveRate(TimeBase tb) THREEWORDINLINE(0x303C, 0x0124, 0xAAAA);

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
    NewCallBack(TimeBase tb, short cbType) THREEWORDINLINE(0x303C, 0x00EB, 0xAAAA);

    /**
     *  DisposeCallBack()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    DisposeCallBack(QTCallBack cb) THREEWORDINLINE(0x303C, 0x00EC, 0xAAAA);

    /**
     *  GetCallBackType()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    short
    GetCallBackType(QTCallBack cb) THREEWORDINLINE(0x303C, 0x00ED, 0xAAAA);

    /**
     *  GetCallBackTimeBase()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    TimeBase
    GetCallBackTimeBase(QTCallBack cb) THREEWORDINLINE(0x303C, 0x00EE, 0xAAAA);

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
               long param2, long param3) THREEWORDINLINE(0x303C, 0x00B8, 0xAAAA);

    /**
     *  CancelCallBack()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    CancelCallBack(QTCallBack cb) THREEWORDINLINE(0x303C, 0x00B9, 0xAAAA);

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
    AddCallBackToTimeBase(QTCallBack cb) THREEWORDINLINE(0x303C, 0x0129, 0xAAAA);

    /**
     *  RemoveCallBackFromTimeBase()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    OSErr
    RemoveCallBackFromTimeBase(QTCallBack cb)
        THREEWORDINLINE(0x303C, 0x012A, 0xAAAA);

    /**
     *  GetFirstCallBack()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    QTCallBack
    GetFirstCallBack(TimeBase tb) THREEWORDINLINE(0x303C, 0x012B, 0xAAAA);

    /**
     *  GetNextCallBack()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    QTCallBack
    GetNextCallBack(QTCallBack cb) THREEWORDINLINE(0x303C, 0x012C, 0xAAAA);

    /**
     *  ExecuteCallBack()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    void
    ExecuteCallBack(QTCallBack cb) THREEWORDINLINE(0x303C, 0x012D, 0xAAAA);

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
                                   ComponentInstance *tp)
        FIVEWORDINLINE(0x2F3C, 0x0008, 0x0101, 0x7000, 0xA82A);

    // UPP call backs     /**
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
    }; // pascal 2_bytes Func(4_bytes, 4_bytes, 4_bytes) #ifdef __cplusplus
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
    }; // pascal 2_bytes Func(4_bytes, 2_bytes, 2_bytes, 4_bytes, 4_bytes) #ifdef __cplusplus
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
    }; // pascal 2_bytes Func(4_bytes, 4_bytes) #ifdef __cplusplus
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
    }; // pascal 2_bytes Func(4_bytes, 4_bytes) #ifdef __cplusplus
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
    }; // pascal 2_bytes Func(4_bytes, 4_bytes, 4_bytes, 4_bytes) #ifdef __cplusplus
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
    }; // pascal 1_byte Func(4_bytes) #ifdef __cplusplus
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
    }; // pascal 2_bytes Func(4_bytes, 4_bytes, 4_bytes, 4_bytes) #ifdef __cplusplus
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
    }; // pascal 2_bytes Func(4_bytes, 4_bytes, 4_bytes, 4_bytes) #ifdef __cplusplus
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
    }; // pascal 2_bytes Func(4_bytes, 2_bytes, 4_bytes, 4_bytes) #ifdef __cplusplus
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
    }; // pascal 2_bytes Func(4_bytes, 4_bytes, 4_bytes, 4_bytes) #ifdef __cplusplus
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
    }; // pascal no_return_value Func(4_bytes, 2_bytes, 4_bytes) #ifdef __cplusplus
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
    }; // pascal no_return_value Func(2_bytes, 4_bytes) #ifdef __cplusplus
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
    }; // pascal no_return_value Func(4_bytes, 4_bytes) #ifdef __cplusplus
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
    }; // pascal no_return_value Func(4_bytes) #ifdef __cplusplus
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
    }; // pascal 2_bytes Func(4_bytes, 4_bytes, 4_bytes) #ifdef __cplusplus
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
    }; // pascal 1_byte Func(4_bytes, 4_bytes, 4_bytes) #ifdef __cplusplus
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

    // UPP call backs 
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    MCActionFilterWithRefConUPP
    NewMCActionFilterWithRefConUPP(MCActionFilterWithRefConProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
    enum
    {
        uppMCActionFilterWithRefConProcInfo = 0x00003ED0
    }; // pascal 1_byte Func(4_bytes, 2_bytes, 4_bytes, 4_bytes) #ifdef __cplusplus
    inline MCActionFilterWithRefConUPP
    NewMCActionFilterWithRefConUPP(MCActionFilterWithRefConProcPtr userRoutine)
    {
        return (MCActionFilterWithRefConUPP)NewRoutineDescriptor(
       // pascal 2_bytes Func(4_bytes, 4_bytes, 4_bytes) 
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
#endif// pascal 2_bytes Func(4_bytes, 2_bytes, 2_bytes, 4_bytes, 4_bytes) 

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
     */// pascal 2_bytes Func(4_bytes, 4_bytes) 
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
#else// pascal 2_bytes Func(4_bytes, 4_bytes) 
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

     * // pascal 2_bytes Func(4_bytes, 4_bytes, 4_bytes, 4_bytes) 
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
#ifdef // pascal 1_byte Func(4_bytes) 
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

    /**// pascal 2_bytes Func(4_bytes, 4_bytes, 4_bytes, 4_bytes) 
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
     */// pascal 2_bytes Func(4_bytes, 4_bytes, 4_bytes, 4_bytes) 
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
    inl// pascal 2_bytes Func(4_bytes, 2_bytes, 4_bytes, 4_bytes) 
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
#define// pascal 2_bytes Func(4_bytes, 4_bytes, 4_bytes, 4_bytes) 
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
     * // pascal no_return_value Func(4_bytes, 2_bytes, 4_bytes) 
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
#else// pascal no_return_value Func(2_bytes, 4_bytes) 
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
     * // pascal no_return_value Func(4_bytes, 4_bytes) 
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
    voi// pascal no_return_value Func(4_bytes) 
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
    {// pascal 2_bytes Func(4_bytes, 4_bytes, 4_bytes) 
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
       // pascal 1_byte Func(4_bytes, 4_bytes, 4_bytes) 
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
#endif// pascal 1_byte Func(4_bytes, 2_bytes, 4_bytes, 4_bytes) 
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
// support for pre-Carbon UPP routines: New...Proc and Call...Proc #define NewMovieRgnCoverProc(userRoutine) NewMovieRgnCoverUPP(userRoutine)
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
#endif // CALL_NOT_IN_CARBON 
    // selectors for component calls     enum
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

#endif // __MOVIES__ // support for pre-Carbon UPP routines: New...Proc and Call...Proc 
// CALL_NOT_IN_CARBON 
// selectors for component calls 
// __MOVIES__ 
