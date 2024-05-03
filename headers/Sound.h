/**
     \file       Sound.h

    \brief   Sound Manager Interfaces.

    \introduced_in  Sound Manager 3.6
    \avaliable_from Universal Interfaces 3.4.1

    \copyright © 1986-2001 by Apple Computer, Inc., all rights reserved

    \ingroup System

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __SOUND__
#define __SOUND__

#ifndef __MACTYPES__
#include <MacTypes.h>
#endif

#ifndef __COMPONENTS__
#include <Components.h>
#endif

#ifndef __MIXEDMODE__
#include <MixedMode.h>
#endif

#ifndef __DIALOGS__
#include <Dialogs.h>
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

/**
                        * * *  N O T E  * * *

    This file has been updated to include Sound Manager 3.3 interfaces.

    Some of the Sound Manager 3.0 interfaces were not put into the InterfaceLib
    that originally shipped with the PowerMacs. These missing functions and the
    new 3.3 interfaces have been released in the SoundLib library for PowerPC
    developers to link with. The runtime library for these functions are
    installed by the Sound Manager. The following functions are found in
   SoundLib.

        GetCompressionInfo(), GetSoundPreference(), SetSoundPreference(),
        UnsignedFixedMulDiv(), SndGetInfo(), SndSetInfo(), GetSoundOutputInfo(),
        SetSoundOutputInfo(), GetCompressionName(), SoundConverterOpen(),
        SoundConverterClose(), SoundConverterGetBufferSizes(),
   SoundConverterBeginConversion(), SoundConverterConvertBuffer(),
   SoundConverterEndConversion(), AudioGetBass(), AudioGetInfo(),
   AudioGetMute(), AudioGetOutputDevice(), AudioGetTreble(), AudioGetVolume(),
   AudioMuteOnEvent(), AudioSetBass(), AudioSetMute(), AudioSetToDefaults(),
   AudioSetTreble(), AudioSetVolume(), OpenMixerSoundComponent(),
   CloseMixerSoundComponent(), SoundComponentAddSource(),
        SoundComponentGetInfo(), SoundComponentGetSource(),
   SoundComponentGetSourceData(), SoundComponentInitOutputDevice(),
   SoundComponentPauseSource(), SoundComponentPlaySourceBuffer(),
   SoundComponentRemoveSource(), SoundComponentSetInfo(),
   SoundComponentSetOutput(), SoundComponentSetSource(),
        SoundComponentStartSource(), SoundComponentStopSource(),
        ParseAIFFHeader(), ParseSndHeader(), SoundConverterGetInfo(),
   SoundConverterSetInfo()
*/
/**
    Interfaces for Sound Driver, !!! OBSOLETE and NOT SUPPORTED !!!

    These items are no longer defined, but appear here so that someone
    searching the interfaces might find them. If you are using one of these
    items, you must change your code to support the Sound Manager.

        swMode, ftMode, ffMode
        FreeWave, FFSynthRec, Tone, SWSynthRec, Wave, FTSoundRec
        SndCompletionProcPtr
        StartSound, StopSound, SoundDone
        SetSoundVol, GetSoundVol
*/
/**
  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
   constants
  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/
#define twelfthRootTwo 1.05946309435

  enum
  {
    soundListRsrc =
        FOUR_CHAR_CODE('snd ') /**Resource type used by Sound Manager*/
  };

  enum
  {
    kSimpleBeepID = 1 /**reserved resource ID for Simple Beep*/
  };

  enum
  {
    rate48khz = (long)0xBB800000, /**48000.00000 in fixed-point*/
    rate44khz = (long)0xAC440000, /**44100.00000 in fixed-point*/
    rate32khz = 0x7D000000,       /**32000.00000 in fixed-point*/
    rate22050hz = 0x56220000,     /**22050.00000 in fixed-point*/
    rate22khz = 0x56EE8BA3,       /**22254.54545 in fixed-point*/
    rate16khz = 0x3E800000,       /**16000.00000 in fixed-point*/
    rate11khz = 0x2B7745D1,       /**11127.27273 in fixed-point*/
    rate11025hz = 0x2B110000,     /**11025.00000 in fixed-point*/
    rate8khz = 0x1F400000         /** 8000.00000 in fixed-point*/
  };

  /**synthesizer numbers for SndNewChannel*/
  enum
  {
    sampledSynth = 5 /**sampled sound synthesizer*/
  };

#if CALL_NOT_IN_CARBON
  enum
  {
    squareWaveSynth = 1, /**square wave synthesizer*/
    waveTableSynth = 3,  /**wave table synthesizer*/
                         /**old Sound Manager MACE synthesizer numbers*/
    MACE3snthID = 11,
    MACE6snthID = 13
  };

#endif /** CALL_NOT_IN_CARBON */

  enum
  {
    kMiddleC = 60 /**MIDI note value for middle C*/
  };

  enum
  {
    kNoVolume = 0,       /**setting for no sound volume*/
    kFullVolume = 0x0100 /**1.0, setting for full hardware output volume*/
  };

  enum
  {
    stdQLength = 128
  };

  enum
  {
    dataOffsetFlag = 0x8000
  };

  enum
  {
    kUseOptionalOutputDevice = -1 /**only for Sound Manager 3.0 or later*/
  };

  enum
  {
    notCompressed = 0,       /**compression ID's*/
    fixedCompression = -1,   /**compression ID for fixed-sized compression*/
    variableCompression = -2 /**compression ID for variable-sized compression*/
  };

  enum
  {
    twoToOne = 1,
    eightToThree = 2,
    threeToOne = 3,
    sixToOne = 4,
    sixToOnePacketSize = 8,
    threeToOnePacketSize = 16
  };

  enum
  {
    stateBlockSize = 64,
    leftOverBlockSize = 32
  };

  enum
  {
    firstSoundFormat = 0x0001, /**general sound format*/
    secondSoundFormat = 0x0002 /**special sampled sound format (HyperCard)*/
  };

#if CALL_NOT_IN_CARBON
  enum
  {
    dbBufferReady = 0x00000001, /**double buffer is filled*/
    dbLastBuffer = 0x00000004   /**last double buffer to play*/
  };

#endif /** CALL_NOT_IN_CARBON */

  enum
  {
    sysBeepDisable = 0x0000, /**SysBeep() enable flags*/
    sysBeepEnable = (1 << 0),
    sysBeepSynchronous = (1 << 1) /**if bit set, make alert sounds synchronous*/
  };

  enum
  {
    unitTypeNoSelection = 0xFFFF, /**unitTypes for AudioSelection.unitType*/
    unitTypeSeconds = 0x0000
  };

  enum
  {
    stdSH = 0x00, /**Standard sound header encode value*/
    extSH = 0xFF, /**Extended sound header encode value*/
    cmpSH = 0xFE  /**Compressed sound header encode value*/
  };

  /**command numbers for SndDoCommand and SndDoImmediate*/
  enum
  {
    nullCmd = 0,
    quietCmd = 3,
    flushCmd = 4,
    reInitCmd = 5,
    waitCmd = 10,
    pauseCmd = 11,
    resumeCmd = 12,
    callBackCmd = 13,
    syncCmd = 14,
    availableCmd = 24,
    versionCmd = 25,
    volumeCmd = 46,              /**sound manager 3.0 or later only*/
    getVolumeCmd = 47,           /**sound manager 3.0 or later only*/
    clockComponentCmd = 50,      /**sound manager 3.2.1 or later only*/
    getClockComponentCmd = 51,   /**sound manager 3.2.1 or later only*/
    scheduledSoundCmd = 52,      /**sound manager 3.3 or later only*/
    linkSoundComponentsCmd = 53, /**sound manager 3.3 or later only*/
    soundCmd = 80,
    bufferCmd = 81,
    rateMultiplierCmd = 86,
    getRateMultiplierCmd = 87
  };

#if CALL_NOT_IN_CARBON
  /**command numbers for SndDoCommand and SndDoImmediate that are not available
   * for use in Carbon */
  enum
  {
    initCmd = 1,
    freeCmd = 2,
    totalLoadCmd = 26,
    loadCmd = 27,
    freqDurationCmd = 40,
    restCmd = 41,
    freqCmd = 42,
    ampCmd = 43,
    timbreCmd = 44,
    getAmpCmd = 45,
    waveTableCmd = 60,
    phaseCmd = 61,
    rateCmd = 82,
    continueCmd = 83,
    doubleBufferCmd = 84,
    getRateCmd = 85,
    sizeCmd = 90,   /**obsolete command*/
    convertCmd = 91 /**obsolete MACE command*/
  };

#endif /** CALL_NOT_IN_CARBON */

#if OLDROUTINENAMES
  /**channel initialization parameters*/
  enum
  {
    waveInitChannelMask = 0x07,
    waveInitChannel0 = 0x04,      /**wave table only, Sound Manager 2.0 and earlier*/
    waveInitChannel1 = 0x05,      /**wave table only, Sound Manager 2.0 and earlier*/
    waveInitChannel2 = 0x06,      /**wave table only, Sound Manager 2.0 and earlier*/
    waveInitChannel3 = 0x07,      /**wave table only, Sound Manager 2.0 and earlier*/
    initChan0 = waveInitChannel0, /**obsolete spelling*/
    initChan1 = waveInitChannel1, /**obsolete spelling*/
    initChan2 = waveInitChannel2, /**obsolete spelling*/
    initChan3 = waveInitChannel3  /**obsolete spelling*/
  };

  enum
  {
    outsideCmpSH = 0, /**obsolete MACE constant*/
    insideCmpSH = 1,  /**obsolete MACE constant*/
    aceSuccess = 0,   /**obsolete MACE constant*/
    aceMemFull = 1,   /**obsolete MACE constant*/
    aceNilBlock = 2,  /**obsolete MACE constant*/
    aceBadComp = 3,   /**obsolete MACE constant*/
    aceBadEncode = 4, /**obsolete MACE constant*/
    aceBadDest = 5,   /**obsolete MACE constant*/
    aceBadCmd = 6     /**obsolete MACE constant*/
  };

#endif /** OLDROUTINENAMES */

  enum
  {
    initChanLeft = 0x0002,   /**left stereo channel*/
    initChanRight = 0x0003,  /**right stereo channel*/
    initNoInterp = 0x0004,   /**no linear interpolation*/
    initNoDrop = 0x0008,     /**no drop-sample conversion*/
    initMono = 0x0080,       /**monophonic channel*/
    initStereo = 0x00C0,     /**stereo channel*/
    initMACE3 = 0x0300,      /**MACE 3:1*/
    initMACE6 = 0x0400,      /**MACE 6:1*/
    initPanMask = 0x0003,    /**mask for right/left pan values*/
    initSRateMask = 0x0030,  /**mask for sample rate values*/
    initStereoMask = 0x00C0, /**mask for mono/stereo values*/
    initCompMask = 0xFF00    /**mask for compression IDs*/
  };

  /**Get&Set Sound Information Selectors*/
  enum
  {
    siActiveChannels = FOUR_CHAR_CODE('chac'), /**active channels*/
    siActiveLevels = FOUR_CHAR_CODE('lmac'),   /**active meter levels*/
    siAGCOnOff = FOUR_CHAR_CODE('agc '),       /**automatic gain control state*/
    siAsync = FOUR_CHAR_CODE('asyn'),          /**asynchronous capability*/
    siAVDisplayBehavior = FOUR_CHAR_CODE('avdb'),
    siChannelAvailable = FOUR_CHAR_CODE('chav'), /**number of channels available*/
    siCompressionAvailable =
        FOUR_CHAR_CODE('cmav'), /**compression types available*/
    siCompressionChannels =
        FOUR_CHAR_CODE('cpct'),                   /**compressor's number of channels*/
    siCompressionFactor = FOUR_CHAR_CODE('cmfa'), /**current compression factor*/
    siCompressionHeader = FOUR_CHAR_CODE('cmhd'), /**return compression header*/
    siCompressionNames =
        FOUR_CHAR_CODE('cnam'),                   /**compression type names available*/
    siCompressionParams = FOUR_CHAR_CODE('evaw'), /**compression parameters*/
    siCompressionSampleRate =
        FOUR_CHAR_CODE('cprt'),                     /**compressor's sample rate*/
    siCompressionType = FOUR_CHAR_CODE('comp'),     /**current compression type*/
    siContinuous = FOUR_CHAR_CODE('cont'),          /**continous recording*/
    siDecompressionParams = FOUR_CHAR_CODE('wave'), /**decompression parameters*/
    siDeviceBufferInfo = FOUR_CHAR_CODE('dbin'),    /**size of interrupt buffer*/
    siDeviceConnected =
        FOUR_CHAR_CODE('dcon'),                  /**input device connection status*/
    siDeviceIcon = FOUR_CHAR_CODE('icon'),       /**input device icon*/
    siDeviceName = FOUR_CHAR_CODE('name'),       /**input device name*/
    siEQSpectrumBands = FOUR_CHAR_CODE('eqsb'),  /** number of spectrum bands*/
    siEQSpectrumLevels = FOUR_CHAR_CODE('eqlv'), /** gets spectum meter levels*/
    siEQSpectrumOnOff =
        FOUR_CHAR_CODE('eqlo'), /** turn on/off spectum meter levels*/
    siEQSpectrumResolution =
        FOUR_CHAR_CODE('eqrs'), /** set the resolution of the FFT, 0 = low res
                                   (<=16 bands), 1 = high res (16-64 bands)*/
    siEQToneControlGain =
        FOUR_CHAR_CODE('eqtg'), /** set the bass and treble gain*/
    siEQToneControlOnOff =
        FOUR_CHAR_CODE('eqtc'), /** turn on equalizer attenuation*/
    siHardwareBalance = FOUR_CHAR_CODE('hbal'),
    siHardwareBalanceSteps = FOUR_CHAR_CODE('hbls'),
    siHardwareBass = FOUR_CHAR_CODE('hbas'),
    siHardwareBassSteps = FOUR_CHAR_CODE('hbst'),
    siHardwareBusy = FOUR_CHAR_CODE('hwbs'),   /**sound hardware is in use*/
    siHardwareFormat = FOUR_CHAR_CODE('hwfm'), /**get hardware format*/
    siHardwareMute = FOUR_CHAR_CODE('hmut'),   /**mute state of all hardware*/
    siHardwareMuteNoPrefs = FOUR_CHAR_CODE(
        'hmnp'), /**mute state of all hardware, but don't store in prefs */
    siHardwareTreble = FOUR_CHAR_CODE('htrb'),
    siHardwareTrebleSteps = FOUR_CHAR_CODE('hwts'),
    siHardwareVolume = FOUR_CHAR_CODE('hvol'), /**volume level of all hardware*/
    siHardwareVolumeSteps =
        FOUR_CHAR_CODE('hstp'),                 /**number of volume steps for hardware*/
    siHeadphoneMute = FOUR_CHAR_CODE('pmut'),   /**mute state of headphones*/
    siHeadphoneVolume = FOUR_CHAR_CODE('pvol'), /**volume level of headphones*/
    siHeadphoneVolumeSteps =
        FOUR_CHAR_CODE('hdst'),                  /**number of volume steps for headphones*/
    siInputAvailable = FOUR_CHAR_CODE('inav'),   /**input sources available*/
    siInputGain = FOUR_CHAR_CODE('gain'),        /**input gain*/
    siInputSource = FOUR_CHAR_CODE('sour'),      /**input source selector*/
    siInputSourceNames = FOUR_CHAR_CODE('snam'), /**input source names*/
    siLevelMeterOnOff = FOUR_CHAR_CODE('lmet'),  /**level meter state*/
    siModemGain = FOUR_CHAR_CODE('mgai'),        /**modem input gain*/
    siMonitorAvailable = FOUR_CHAR_CODE('mnav'),
    siMonitorSource = FOUR_CHAR_CODE('mons'),
    siNumberChannels = FOUR_CHAR_CODE('chan'),    /**current number of channels*/
    siOptionsDialog = FOUR_CHAR_CODE('optd'),     /**display options dialog*/
    siOSTypeInputSource = FOUR_CHAR_CODE('inpt'), /**input source by OSType*/
    siOSTypeInputAvailable =
        FOUR_CHAR_CODE('inav'),                  /**list of available input source OSTypes*/
    siOutputDeviceName = FOUR_CHAR_CODE('onam'), /**output device name*/
    siPlayThruOnOff = FOUR_CHAR_CODE('plth'),    /**playthrough state*/
    siPostMixerSoundComponent =
        FOUR_CHAR_CODE('psmx'), /**install post-mixer effect*/
    siPreMixerSoundComponent =
        FOUR_CHAR_CODE('prmx'),                     /**install pre-mixer effect*/
    siQuality = FOUR_CHAR_CODE('qual'),             /**quality setting*/
    siRateMultiplier = FOUR_CHAR_CODE('rmul'),      /**throttle rate setting*/
    siRecordingQuality = FOUR_CHAR_CODE('qual'),    /**recording quality*/
    siSampleRate = FOUR_CHAR_CODE('srat'),          /**current sample rate*/
    siSampleRateAvailable = FOUR_CHAR_CODE('srav'), /**sample rates available*/
    siSampleSize = FOUR_CHAR_CODE('ssiz'),          /**current sample size*/
    siSampleSizeAvailable = FOUR_CHAR_CODE('ssav'), /**sample sizes available*/
    siSetupCDAudio =
        FOUR_CHAR_CODE('sucd'), /**setup sound hardware for CD audio*/
    siSetupModemAudio =
        FOUR_CHAR_CODE('sumd'), /**setup sound hardware for modem audio*/
    siSlopeAndIntercept =
        FOUR_CHAR_CODE('flap'), /**floating point variables for conversion*/
    siSoundClock = FOUR_CHAR_CODE('sclk'),
    siUseThisSoundClock = FOUR_CHAR_CODE(
        'sclc'), /**sdev uses this to tell the mixer to use his sound clock*/
    siSpeakerMute =
        FOUR_CHAR_CODE('smut'), /**mute state of all built-in speaker*/
    siSpeakerVolume =
        FOUR_CHAR_CODE('svol'), /**volume level of built-in speaker*/
    siSSpCPULoadLimit = FOUR_CHAR_CODE('3dll'),
    siSSpLocalization = FOUR_CHAR_CODE('3dif'),
    siSSpSpeakerSetup = FOUR_CHAR_CODE('3dst'),
    siStereoInputGain = FOUR_CHAR_CODE('sgai'),     /**stereo input gain*/
    siSubwooferMute = FOUR_CHAR_CODE('bmut'),       /**mute state of sub-woofer*/
    siTerminalType = FOUR_CHAR_CODE('ttyp'),        /** usb terminal type */
    siTwosComplementOnOff = FOUR_CHAR_CODE('twos'), /**two's complement state*/
    siVendorProduct = FOUR_CHAR_CODE('vpro'),       /** vendor and product ID */
    siVolume = FOUR_CHAR_CODE('volu'),              /**volume level of source*/
    siVoxRecordInfo = FOUR_CHAR_CODE('voxr'),       /**VOX record parameters*/
    siVoxStopInfo = FOUR_CHAR_CODE('voxs'),         /**VOX stop parameters*/
    siWideStereo = FOUR_CHAR_CODE('wide'),          /**wide stereo setting*/
    siSupportedExtendedFlags = FOUR_CHAR_CODE(
        'exfl'), /**which flags are supported in Extended sound data structures*/
    siRateConverterRollOffSlope = FOUR_CHAR_CODE(
        'rcdb'), /**the roll-off slope for the rate converter's filter, in whole
                    dB as a long this value is a long whose range is from 20
                    (worst quality/fastest performance) to 90 (best
                    quality/slowest performance)*/
    siOutputLatency =
        FOUR_CHAR_CODE('olte') /**latency of sound output component*/
  };

  enum
  {
    siCloseDriver = FOUR_CHAR_CODE('clos'), /**reserved for internal use only*/
    siInitializeDriver =
        FOUR_CHAR_CODE('init'),                /**reserved for internal use only*/
    siPauseRecording = FOUR_CHAR_CODE('paus'), /**reserved for internal use only*/
    siUserInterruptProc =
        FOUR_CHAR_CODE('user') /**reserved for internal use only*/
  };

  /** input source Types*/
  enum
  {
    kInvalidSource =
        (long)0xFFFFFFFF,                    /**this source may be returned from GetInfo if no other
                                                source is the monitored source*/
    kNoSource = FOUR_CHAR_CODE('none'),      /**no source selection*/
    kCDSource = FOUR_CHAR_CODE('cd  '),      /**internal CD player input*/
    kExtMicSource = FOUR_CHAR_CODE('emic'),  /**external mic input*/
    kSoundInSource = FOUR_CHAR_CODE('sinj'), /**sound input jack*/
    kRCAInSource = FOUR_CHAR_CODE('irca'),   /**RCA jack input*/
    kTVFMTunerSource = FOUR_CHAR_CODE('tvfm'),
    kDAVInSource = FOUR_CHAR_CODE('idav'),     /**DAV analog input*/
    kIntMicSource = FOUR_CHAR_CODE('imic'),    /**internal mic input*/
    kMediaBaySource = FOUR_CHAR_CODE('mbay'),  /**media bay input*/
    kModemSource = FOUR_CHAR_CODE('modm'),     /**modem input (internal modem on
                                                  desktops, PCI input on PowerBooks)*/
    kPCCardSource = FOUR_CHAR_CODE('pcm '),    /**PC Card pwm input*/
    kZoomVideoSource = FOUR_CHAR_CODE('zvpc'), /**zoom video input*/
    kDVDSource = FOUR_CHAR_CODE('dvda'),       /** DVD audio input*/
    kMicrophoneArray = FOUR_CHAR_CODE('mica')  /** microphone array*/
  };

  /**Sound Component Types and Subtypes*/
  enum
  {
    kNoSoundComponentType = FOUR_CHAR_CODE('****'),
    kSoundComponentType = FOUR_CHAR_CODE('sift'), /**component type*/
    kSoundComponentPPCType =
        FOUR_CHAR_CODE('nift'),                 /**component type for PowerPC code*/
    kRate8SubType = FOUR_CHAR_CODE('ratb'),     /**8-bit rate converter*/
    kRate16SubType = FOUR_CHAR_CODE('ratw'),    /**16-bit rate converter*/
    kConverterSubType = FOUR_CHAR_CODE('conv'), /**sample format converter*/
    kSndSourceSubType = FOUR_CHAR_CODE('sour'), /**generic source component*/
    kMixerType = FOUR_CHAR_CODE('mixr'),
    kMixer8SubType = FOUR_CHAR_CODE('mixb'),         /**8-bit mixer*/
    kMixer16SubType = FOUR_CHAR_CODE('mixw'),        /**16-bit mixer*/
    kSoundInputDeviceType = FOUR_CHAR_CODE('sinp'),  /**sound input component*/
    kWaveInSubType = FOUR_CHAR_CODE('wavi'),         /**Windows waveIn*/
    kWaveInSnifferSubType = FOUR_CHAR_CODE('wisn'),  /**Windows waveIn sniffer*/
    kSoundOutputDeviceType = FOUR_CHAR_CODE('sdev'), /**sound output component*/
    kClassicSubType = FOUR_CHAR_CODE('clas'),        /**classic hardware, i.e. Mac Plus*/
    kASCSubType = FOUR_CHAR_CODE('asc '),            /**Apple Sound Chip device*/
    kDSPSubType = FOUR_CHAR_CODE('dsp '),            /**DSP device*/
    kAwacsSubType =
        FOUR_CHAR_CODE('awac'), /**Another of Will's Audio Chips device*/
    kGCAwacsSubType =
        FOUR_CHAR_CODE('awgc'),               /**Awacs audio with Grand Central DMA*/
    kSingerSubType = FOUR_CHAR_CODE('sing'),  /**Singer (via Whitney) based sound*/
    kSinger2SubType = FOUR_CHAR_CODE('sng2'), /**Singer 2 (via Whitney) for Acme*/
    kWhitSubType =
        FOUR_CHAR_CODE('whit'),                      /**Whit sound component for PrimeTime 3*/
    kSoundBlasterSubType = FOUR_CHAR_CODE('sbls'),   /**Sound Blaster for CHRP*/
    kWaveOutSubType = FOUR_CHAR_CODE('wavo'),        /**Windows waveOut*/
    kWaveOutSnifferSubType = FOUR_CHAR_CODE('wosn'), /**Windows waveOut sniffer*/
    kDirectSoundSubType = FOUR_CHAR_CODE('dsnd'),    /**Windows DirectSound*/
    kDirectSoundSnifferSubType =
        FOUR_CHAR_CODE('dssn'),                /**Windows DirectSound sniffer*/
    kUNIXsdevSubType = FOUR_CHAR_CODE('un1x'), /**UNIX base sdev*/
    kUSBSubType = FOUR_CHAR_CODE('usb '),      /**USB device*/
    kBlueBoxSubType = FOUR_CHAR_CODE('bsnd'),  /**Blue Box sound component*/
    kSoundCompressor = FOUR_CHAR_CODE('scom'),
    kSoundDecompressor = FOUR_CHAR_CODE('sdec'),
    kAudioComponentType =
        FOUR_CHAR_CODE('adio'), /**Audio components and sub-types*/
    kAwacsPhoneSubType = FOUR_CHAR_CODE('hphn'),
    kAudioVisionSpeakerSubType = FOUR_CHAR_CODE('telc'),
    kAudioVisionHeadphoneSubType = FOUR_CHAR_CODE('telh'),
    kPhilipsFaderSubType = FOUR_CHAR_CODE('tvav'),
    kSGSToneSubType = FOUR_CHAR_CODE('sgs0'),
    kSoundEffectsType = FOUR_CHAR_CODE('snfx'), /**sound effects type*/
    kEqualizerSubType = FOUR_CHAR_CODE('eqal'), /**frequency equalizer*/
    kSSpLocalizationSubType = FOUR_CHAR_CODE('snd3')
  };

  /**Format Types*/
  enum
  {
    kSoundNotCompressed = FOUR_CHAR_CODE('NONE'),      /**sound is not compressed*/
    k8BitOffsetBinaryFormat = FOUR_CHAR_CODE('raw '),  /**8-bit offset binary*/
    k16BitBigEndianFormat = FOUR_CHAR_CODE('twos'),    /**16-bit big endian*/
    k16BitLittleEndianFormat = FOUR_CHAR_CODE('sowt'), /**16-bit little endian*/
    kFloat32Format = FOUR_CHAR_CODE('fl32'),           /**32-bit floating point*/
    kFloat64Format = FOUR_CHAR_CODE('fl64'),           /**64-bit floating point*/
    k24BitFormat = FOUR_CHAR_CODE('in24'),             /**24-bit integer*/
    k32BitFormat = FOUR_CHAR_CODE('in32'),             /**32-bit integer*/
    k32BitLittleEndianFormat =
        FOUR_CHAR_CODE('23ni'),                     /**32-bit little endian integer */
    kMACE3Compression = FOUR_CHAR_CODE('MAC3'),     /**MACE 3:1*/
    kMACE6Compression = FOUR_CHAR_CODE('MAC6'),     /**MACE 6:1*/
    kCDXA4Compression = FOUR_CHAR_CODE('cdx4'),     /**CD/XA 4:1*/
    kCDXA2Compression = FOUR_CHAR_CODE('cdx2'),     /**CD/XA 2:1*/
    kIMACompression = FOUR_CHAR_CODE('ima4'),       /**IMA 4:1*/
    kULawCompression = FOUR_CHAR_CODE('ulaw'),      /**©Law 2:1*/
    kALawCompression = FOUR_CHAR_CODE('alaw'),      /**aLaw 2:1*/
    kMicrosoftADPCMFormat = 0x6D730002,             /**Microsoft ADPCM - ACM code 2*/
    kDVIIntelIMAFormat = 0x6D730011,                /**DVI/Intel IMA ADPCM - ACM code 17*/
    kDVAudioFormat = FOUR_CHAR_CODE('dvca'),        /**DV Audio*/
    kQDesignCompression = FOUR_CHAR_CODE('QDMC'),   /**QDesign music*/
    kQDesign2Compression = FOUR_CHAR_CODE('QDM2'),  /**QDesign2 music*/
    kQUALCOMMCompression = FOUR_CHAR_CODE('Qclp'),  /**QUALCOMM PureVoice*/
    kOffsetBinary = k8BitOffsetBinaryFormat,        /**for compatibility*/
    kTwosComplement = k16BitBigEndianFormat,        /**for compatibility*/
    kLittleEndianFormat = k16BitLittleEndianFormat, /**for compatibility*/
    kMPEGLayer3Format = 0x6D730055,                 /**MPEG Layer 3, CBR only (pre QT4.1)*/
    kFullMPEGLay3Format =
        FOUR_CHAR_CODE('.mp3') /**MPEG Layer 3, CBR & VBR (QT4.1 and later)*/
  };

#if TARGET_RT_LITTLE_ENDIAN
  enum
  {
    k16BitNativeEndianFormat = k16BitLittleEndianFormat,
    k16BitNonNativeEndianFormat = k16BitBigEndianFormat
  };

#else
enum
{
  k16BitNativeEndianFormat = k16BitBigEndianFormat,
  k16BitNonNativeEndianFormat = k16BitLittleEndianFormat
};

#endif /** TARGET_RT_LITTLE_ENDIAN */

  /**Features Flags*/
  enum
  {
    k8BitRawIn = (1 << 0), /**data description*/
    k8BitTwosIn = (1 << 1),
    k16BitIn = (1 << 2),
    kStereoIn = (1 << 3),
    k8BitRawOut = (1 << 8),
    k8BitTwosOut = (1 << 9),
    k16BitOut = (1 << 10),
    kStereoOut = (1 << 11),
    kReverse = (1L << 16), /**  function description*/
    kRateConvert = (1L << 17),
    kCreateSoundSource = (1L << 18),
    kVMAwareness = (1L << 21), /** component will hold its memory*/
    kHighQuality = (1L << 22), /**  performance description*/
    kNonRealTime = (1L << 23)
  };

  /**SoundComponentPlaySourceBuffer action flags*/
  enum
  {
    kSourcePaused = (1 << 0),
    kPassThrough = (1L << 16),
    kNoSoundComponentChain = (1L << 17)
  };

  /**SoundParamBlock flags, usefull for OpenMixerSoundComponent*/
  enum
  {
    kNoMixing = (1 << 0), /**don't mix source*/
    kNoSampleRateConversion =
        (1 << 1), /**don't convert sample rate (i.e. 11 kHz -> 22 kHz)*/
    kNoSampleSizeConversion =
        (1 << 2), /**don't convert sample size (i.e. 16 -> 8)*/
    kNoSampleFormatConversion =
        (1 << 3),                     /**don't convert sample format (i.e. 'twos' -> 'raw ')*/
    kNoChannelConversion = (1 << 4),  /**don't convert stereo/mono*/
    kNoDecompression = (1 << 5),      /**don't decompress (i.e. 'MAC3' -> 'raw ')*/
    kNoVolumeConversion = (1 << 6),   /**don't apply volume*/
    kNoRealtimeProcessing = (1 << 7), /**won't run at interrupt time*/
    kScheduledSource = (1 << 8),      /**source is scheduled*/
    kNonInterleavedBuffer = (1 << 9), /**buffer is not interleaved samples*/
    kNonPagingMixer = (1 << 10),      /**if VM is on, use the non-paging mixer*/
    kSoundConverterMixer =
        (1 << 11), /**the mixer is to be used by the SoundConverter*/
    kPagingMixer =
        (1 << 12),                 /**the mixer is to be used as a paging mixer when VM is on*/
    kVMAwareMixer = (1 << 13),     /**passed to the output device when the SM is going
                                      to deal with VM safety*/
    kExtendedSoundData = (1 << 14) /**SoundComponentData record is actually an
                                      ExtendedSoundComponentData*/
  };

  /**SoundParamBlock quality settings*/
  enum
  {
    kBestQuality = (1 << 0) /**use interpolation in rate conversion*/
  };

  /**useful bit masks*/
  enum
  {
    kInputMask = 0x000000FF,  /**masks off input bits*/
    kOutputMask = 0x0000FF00, /**masks off output bits*/
    kOutputShift = 8,         /**amount output bits are shifted*/
    kActionMask = 0x00FF0000, /**masks off action bits*/
    kSoundComponentBits = 0x00FFFFFF
  };

  /**audio atom types*/
  enum
  {
    kAudioFormatAtomType = FOUR_CHAR_CODE('frma'),
    kAudioEndianAtomType = FOUR_CHAR_CODE('enda'),
    kAudioVBRAtomType = FOUR_CHAR_CODE('vbra'),
    kAudioTerminatorAtomType = 0
  };

  /**siAVDisplayBehavior types*/
  enum
  {
    kAVDisplayHeadphoneRemove =
        0,                         /** monitor does not have a headphone attached*/
    kAVDisplayHeadphoneInsert = 1, /** monitor has a headphone attached*/
    kAVDisplayPlainTalkRemove =
        2,                        /** monitor either sending no input through CPU input port or unable to
                                     tell if input is coming in*/
    kAVDisplayPlainTalkInsert = 3 /** monitor sending PlainTalk level microphone
                                     source input through sound input port*/
  };

  /**Audio Component constants*/
  enum
  {
    /**Values for whichChannel parameter*/
    audioAllChannels =
        0,                       /**All channels (usually interpreted as both left and right)*/
    audioLeftChannel = 1,        /**Left channel*/
    audioRightChannel = 2,       /**Right channel*/
                                 /**Values for mute parameter*/
    audioUnmuted = 0,            /**Device is unmuted*/
    audioMuted = 1,              /**Device is muted*/
                                 /**Capabilities flags definitions*/
    audioDoesMono = (1L << 0),   /**Device supports mono output*/
    audioDoesStereo = (1L << 1), /**Device supports stereo output*/
    audioDoesIndependentChannels =
        (1L
         << 2) /**Device supports independent software control of each channel*/
  };

  /**Sound Input Qualities*/
  enum
  {
    siCDQuality = FOUR_CHAR_CODE('cd  '),     /**44.1kHz, stereo, 16 bit*/
    siBestQuality = FOUR_CHAR_CODE('best'),   /**22kHz, mono, 8 bit*/
    siBetterQuality = FOUR_CHAR_CODE('betr'), /**22kHz, mono, MACE 3:1*/
    siGoodQuality = FOUR_CHAR_CODE('good'),   /**22kHz, mono, MACE 6:1*/
    siNoneQuality = FOUR_CHAR_CODE(
        'none') /**settings don't match any quality for a get call*/
  };

  enum
  {
    siDeviceIsConnected = 1,    /**input device is connected and ready for input*/
    siDeviceNotConnected = 0,   /**input device is not connected*/
    siDontKnowIfConnected = -1, /**can't tell if input device is connected*/
    siReadPermission = 0,       /**permission passed to SPBOpenDevice*/
    siWritePermission = 1       /**permission passed to SPBOpenDevice*/
  };

  /**flags that SoundConverterFillBuffer will return*/
  enum
  {
    kSoundConverterDidntFillBuffer =
        (1 << 0), /**set if the converter couldn't completely satisfy a
                     SoundConverterFillBuffer request*/
    kSoundConverterHasLeftOverData =
        (1 << 1) /**set if the converter had left over data after completely
                    satisfying a SoundConverterFillBuffer call*/
  };

  /** flags for extendedFlags fields of ExtendedSoundComponentData,
   * ExtendedSoundParamBlock, and ExtendedScheduledSoundHeader*/
  enum
  {
    kExtendedSoundSampleCountNotValid =
        1L << 0,                            /** set if sampleCount of SoundComponentData isn't meaningful;
                                               use buffer size instead*/
    kExtendedSoundBufferSizeValid = 1L << 1 /** set if bufferSize field is valid*/
  };

  /**
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
     typedefs
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  */

  /**
  <pre>
   * \copyright THINK Reference © 1991-1992 Symantec Corporation
  */
  struct SndCommand
  {
    unsigned short cmd; /**< command number*/
    short param;        /**< first parameter*/
    long param;         /**< second parameter*/
  } SndCommand;         /**< */

  typedef struct SndCommand SndCommand;
  typedef struct SndChannel SndChannel;

  typedef SndChannel *SndChannelPtr;
  typedef CALLBACK_API(void, SndCallBackProcPtr)(SndChannelPtr chan,
                                                 SndCommand *cmd);
  typedef STACK_UPP_TYPE(SndCallBackProcPtr) SndCallBackUPP;
  /**
  <pre>Most applications do not need to worry about creating or disposing of sound
  channels because the high-level Sound Manager routines take care of these
  automatically. If you are using low-level Sound Manager routines, you can
  create your own sound channels (with the SndNewChannel function).
  </pre>
   * \copyright THINK Reference © 1991-1992 Symantec Corporation
  */
  struct SndChannel
  {
    struct SndChannel *nextChan;  /**< */
    Ptr firstMod;                 /**< reserved for the*/
    SndCallBackProcPtr callBack;  /**< pointer to callback proc*/
    long userInfo;                /**< free for application's use*/
    long wait;                    /**< The following is for*/
    SndCommand cmdInProgress;     /**< */
    short flags;                  /**< */
    short qLength;                /**< */
    short qHead;                  /**< next spot to read or - if*/
    short qTail;                  /**< next spot to write = qHead*/
    SndCommand queue[stdQLength]; /**< */
  } SndChannel;                   /**< */

  /**
   *  NewSndCallBackUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  SndCallBackUPP
  NewSndCallBackUPP(SndCallBackProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppSndCallBackProcInfo = 0x000003C0
  }; /** pascal no_return_value Func(4_bytes, 4_bytes) */
#ifdef __cplusplus
  inline SndCallBackUPP NewSndCallBackUPP(SndCallBackProcPtr userRoutine)
  {
    return (SndCallBackUPP)NewRoutineDescriptor(
        (ProcPtr)(userRoutine), uppSndCallBackProcInfo, GetCurrentArchitecture());
  }
#else
#define NewSndCallBackUPP(userRoutine)                                     \
  (SndCallBackUPP)                                                         \
      NewRoutineDescriptor((ProcPtr)(userRoutine), uppSndCallBackProcInfo, \
                           GetCurrentArchitecture())
#endif
#endif

  /**
   *  DisposeSndCallBackUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeSndCallBackUPP(SndCallBackUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeSndCallBackUPP(SndCallBackUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeSndCallBackUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  InvokeSndCallBackUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  InvokeSndCallBackUPP(SndChannelPtr chan, SndCommand *cmd,
                       SndCallBackUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void InvokeSndCallBackUPP(SndChannelPtr chan, SndCommand *cmd,
                                   SndCallBackUPP userUPP)
  {
    CALL_TWO_PARAMETER_UPP(userUPP, uppSndCallBackProcInfo, chan, cmd);
  }
#else
#define InvokeSndCallBackUPP(chan, cmd, userUPP) \
  CALL_TWO_PARAMETER_UPP((userUPP), uppSndCallBackProcInfo, (chan), (cmd))
#endif
#endif

#if CALL_NOT_IN_CARBON || OLDROUTINENAMES
/** support for pre-Carbon UPP routines: New...Proc and Call...Proc */
#define NewSndCallBackProc(userRoutine) NewSndCallBackUPP(userRoutine)
#define CallSndCallBackProc(userRoutine, chan, cmd) \
  InvokeSndCallBackUPP(chan, cmd, userRoutine)
#endif /** CALL_NOT_IN_CARBON */

  /**MACE structures*/
  /**
  <pre>
   * \copyright THINK Reference © 1991-1992 Symantec Corporation
  */
  struct StateBlock
  {
    short stateVar[stateBlockSize]; /**<  */
  } StateBlock;                     /**< */

  typedef struct StateBlock StateBlock;
  typedef StateBlock *StateBlockPtr;
  /**
  <pre>
   * \copyright THINK Reference © 1991-1992 Symantec Corporation
  */
  struct LeftOverBlock
  {
    unsigned long count;                /**<  */
    char sampleArea[leftOverBlockSize]; /**< */
  } LeftOverBlock;                      /**< */

  typedef struct LeftOverBlock LeftOverBlock;
  typedef LeftOverBlock *LeftOverBlockPtr;
  /**
  <pre>
   * \copyright THINK Reference © 1991-1992 Symantec Corporation
  */
  struct ModRef
  {
    unsigned short modNumber; /**<  */
    long modInit;             /**<  */
  } ModRef;                   /**< */

  typedef struct ModRef ModRef;
  /**
  <pre>
   * \copyright THINK Reference © 1991-1992 Symantec Corporation
  */
  struct SndListResource
  {
    short format;             /**< */
    short numModifiers;       /**< */
    ModRef modifierParts[];   /**< This is a variable length array*/
    short numCommands;        /**< */
    SndCommand commandPart[]; /**< This is a variable length array*/
    char datatPart[];         /**< This is a variable length array*/
  } SndListResource;          /**< */

  typedef struct SndListResource SndListResource;
  typedef SndListResource *SndListPtr;
  typedef SndListPtr *SndListHandle;
  typedef SndListHandle SndListHndl;
  /**HyperCard sound resource format*/
  struct Snd2ListResource
  {
    short format;
    short refCount;
    short numCommands;
    SndCommand commandPart[1];
    UInt8 dataPart[1];
  };
  typedef struct Snd2ListResource Snd2ListResource;
  typedef Snd2ListResource *Snd2ListPtr;
  typedef Snd2ListPtr *Snd2ListHandle;
  typedef Snd2ListHandle Snd2ListHndl;
  /**
  <pre><table><tbody>
  <tr>
    <td>samplePtr</td>
    <td><pre>A pointer to the sampled sound data. If the sampled sound is
  in memory immediately after the baseFrequency field,
  this field should be set to NULL. Otherwise, this field is a
  to the memory location of the sampled sound data.
    </pre></td>
  </tr>

  <tr>
    <td>length</td>
    <td><pre>The number of bytes in the sampled sound data.
    </pre></td>
  </tr>

  <tr>
    <td>sampleRate</td>
    <td><pre>The rate at which the sample was originally recorded. The
  sample rates are shown in theTable below. Note
  the sample rate is declared as a Fixed data type, but the
  significant bit is not treated as a sign bit; instead, that bit
  interpreted as having the value 32,768.
    </pre></td>
  </tr>

  <tr>
    <td>loopStart</td>
    <td><pre>The starting point of the portion of the sampled sound header
  is to be used by the Sound Manager when determining
  duration of freqDurationCmd . These loop points specify the
  numbers in the sampled data to be used as the beginning
  end points to cycle through when playing the sound.
    </pre></td>
  </tr>

  <tr>
    <td>loopEnd</td>
    <td><pre>The end point of the portion of the sampled sound header that
  to be used by the Sound Manager when determining the
  of freqDurationCmd . If no looping is desired, set both
  and loopEnd to 0.
    </pre></td>
  </tr>

  <tr>
    <td>encode</td>
    <td><pre>The method of encoding used to generate the sampled sound
  The current encoding option values are
  standard sound header
  extended sound header
  compressed sound header
  a standard sound header, you should specify the constant
  Encode option values in the ranges 0 through 63 and
  to 255 are reserved for use by Apple. You are free to use
  in the range 64 through 127 for your own encode
  options.
  Reference © 1991-1992 Symantec Corporation
    </pre></td>
  </tr>
  </tbody></table>*/
  struct SoundHeader
  {
    Ptr samplePtr;               /**< if NULL then samples are in*/
    unsigned long length;        /**< length of sound in bytes*/
    Fixed sampleRate;            /**< sample rate for this sound*/
    unsigned long loopStart;     /**< start of looping portion*/
    unsigned long loopEnd;       /**< end of looping portion*/
    unsigned char encode;        /**< header encoding*/
    unsigned char baseFrequency; /**< baseFrequency value*/
    char sampleArea[];           /**< */

    typedef struct SoundHeader SoundHeader;
    typedef SoundHeader *SoundHeaderPtr;
    /**
    <pre><table><tbody>
    <tr>
      <td>samplePtr</td>
      <td><pre>Indicates the location of the compressed sound frames.
    samplePtr is NIL, then the frames are located in the
    field of the
    sound header. Otherwise, samplePtr
    to a buffer that contains the frames.
      </pre></td>
    </tr>

    <tr>
      <td>numChannels</td>
      <td><pre>Indicates how many channels are in the sample.
      </pre></td>
    </tr>

    <tr>
      <td>sampleRate</td>
      <td><pre>Indicates the sample rate at which the frames were
    before compression. The approximate sample
    are shown in the Table "Sample Rates". under the
     entry. Note that the sample rate is
    as a Fixed data type, but the most significant
    is not treated as a sign bit; instead, that bit is
    as having the value 32,768.
    Reference © 1991-1992 Symantec Corporation
      </pre></td>
    </tr>
    </tbody></table>*/
    struct CmpSoundHeader
    {
      Ptr samplePtr;                    /**< if NIL then samples are in*/
      unsigned long numChannels;        /**< number of channels in sample*/
      Fixed sampleRate;                 /**< sample rate in Fixed point*/
      unsigned long loopStart;          /**< start of looping portion*/
      unsigned long loopEnd;            /**< end of looping portion*/
      unsigned char encode;             /**< data structure used , stdSH,*/
      unsigned char baseFrequency;      /**< baseFrequency value*/
      unsigned long numFrames;          /**< length in total number of frames*/
      extended AIFFSampleRate;          /**< IEEE sample rate*/
      Ptr markerChunk;                  /**< sync track*/
      Ptr futureUse;                    /**< reserved by Apple*/
      Ptr futureUse;                    /**< reserved by Apple*/
      StateBlockPtr stateVars;          /**< pointer to StateBlock*/
      LeftOverBlockPtr leftOverSamples; /**< used to save truncated samples*/
      unsigned short compressionID;     /**<  means no compression, non*/
      unsigned short packetSize;        /**< number of bits in compressed*/
      unsigned short snthID;            /**< resource ID of*/
      unsigned short sampleSize;        /**< number of bits in*/
      char sampleArea[];                /**< space for when samples follow*/
    } CmpSoundHeader;                   /**< */

    typedef struct CmpSoundHeader CmpSoundHeader;
    typedef CmpSoundHeader *CmpSoundHeaderPtr;
    /**
    <pre><table><tbody>
    <tr>
      <td>samplePtr</td>
      <td><pre>A pointer to the sampled sound data. If the sampled
    is located in memory immediately after the
    field, then this field should be set to NIL.
    this field is a pointer to the memory
    of the sampled sound data.
      </pre></td>
    </tr>

    <tr>
      <td>numChannels</td>
      <td><pre>The number of channels in the sampled sound data.
      </pre></td>
    </tr>

    <tr>
      <td>sampleRate</td>
      <td><pre>The rate at which the sample was originally recorded.
    approximate sample rates are shown in the Table
    Rates". Note that the sample rate is declared as
    Fixed data type, but the most significant bit is not
    as a sign bit; instead, that bit is interpreted as
    the value 32,768.
      </pre></td>
    </tr>

    <tr>
      <td>sampleRate</td>
      <td><pre>sampleRate
    (kHz) Rate (Hz) value (Fixed)
    kHzH5563.6363 0x15BBA2E8
    kHzH7418.1818 0x1CFA2E8B
    Reference © 1991-1992 Symantec Corporation
      </pre></td>
    </tr>
    </tbody></table>*/
    struct ExtSoundHeader
    {
      Ptr samplePtr;               /**<  if NIL then samples are in*/
      unsigned long numChannels;   /**< number of channels,  ie mono = */
      Fixed sampleRate;            /**< sample rate in Fixed point*/
      unsigned long loopStart;     /**< start of looping portion*/
      unsigned long loopEnd;       /**< end of looping portion*/
      unsigned char encode;        /**< data structure used , stdSH,*/
      unsigned char baseFrequency; /**< baseFrequency value*/
      unsigned long numFrames;     /**< length in total number of frames*/
      extended AIFFSampleRate;     /**< IEEE sample rate*/
      Ptr markerChunk;             /**< sync track*/
      Ptr instrumentChunks;        /**< AIFF instrument chunks*/
      Ptr AESRecording;            /**< */
      unsigned short sampleSize;   /**< number of bits in sample*/
      unsigned short futureUse;    /**< reserved by Apple*/
      unsigned long futureUse;     /**< reserved by Apple*/
      unsigned long futureUse;     /**< reserved by Apple*/
      unsigned long futureUse;     /**< reserved by Apple*/
      char sampleArea[];           /**< space for when samples follow*/
    } ExtSoundHeader;              /**< */

    typedef struct ExtSoundHeader ExtSoundHeader;
    typedef ExtSoundHeader *ExtSoundHeaderPtr;
    union SoundHeaderUnion
    {
      SoundHeader stdHeader;
      CmpSoundHeader cmpHeader;
      ExtSoundHeader extHeader;
    };
    typedef union SoundHeaderUnion SoundHeaderUnion;
    /**
    <pre>
     * \copyright THINK Reference © 1991-1992 Symantec Corporation
    */
    struct ConversionBlock
    {
      short destination;           /**<  */
      short unused;                /**<  */
      CmpSoundHeaderPtr inputPtr;  /**<  */
      CmpSoundHeaderPtr outputPtr; /**<  */
    } ConversionBlock;             /**< */

    typedef struct ConversionBlock ConversionBlock;
    typedef ConversionBlock *ConversionBlockPtr;
    /** ScheduledSoundHeader flags*/
    enum
    {
      kScheduledSoundDoScheduled = 1 << 0,
      kScheduledSoundDoCallBack = 1 << 1,
      kScheduledSoundExtendedHdr = 1 << 2
    };

    struct ScheduledSoundHeader
    {
      SoundHeaderUnion u;
      long flags;
      short reserved;
      short callBackParam1;
      long callBackParam2;
      TimeRecord startTime;
    };
    typedef struct ScheduledSoundHeader ScheduledSoundHeader;
    typedef ScheduledSoundHeader *ScheduledSoundHeaderPtr;
    struct ExtendedScheduledSoundHeader
    {
      SoundHeaderUnion u;
      long flags;
      short reserved;
      short callBackParam1;
      long callBackParam2;
      TimeRecord startTime;
      long recordSize;
      long extendedFlags;
      long bufferSize;
    };
    typedef struct ExtendedScheduledSoundHeader ExtendedScheduledSoundHeader;
    typedef ExtendedScheduledSoundHeader *ExtendedScheduledSoundHeaderPtr;
    /**
    <pre><table><tbody>
    <tr>
      <td>smMaxCPULoad</td>
      <td><pre>The maximum load that the Sound Manager will not
    when allocating channels. The smMaxCPULoad field
    set to a default value of 100 when the system starts
    up.
      </pre></td>
    </tr>

    <tr>
      <td>smNumChannels</td>
      <td><pre>The number of sound channels that are currently
    by all applications. This does not mean that the
    allocated are being used, only that they have
    allocated and that CPU loading is being reserved for
    channels.
      </pre></td>
    </tr>

    <tr>
      <td>smCurCPULoad</td>
      <td><pre>The CPU load that is being taken up by currently
    channels.
    code in Obtaining Information About Sound Features illustrates
    use of SndManagerStatus . It defines a function that returns the number
    sound channels currently allocated by all applications.
    Reference © 1991-1992 Symantec Corporation
      </pre></td>
    </tr>
    </tbody></table>*/
    struct SMStatus
    {
      short smMaxCPULoad;  /**< maximum load on all channels*/
      short smNumChannels; /**< number of allocated channels*/
      short smCurCPULoad;  /**< current load on all channels*/
    } SMStatus;            /**< */

    typedef struct SMStatus SMStatus;
    typedef SMStatus *SMStatusPtr;
    /**
    <pre><table><tbody>
    <tr>
      <td>scStartTime</td>
      <td><pre>If scChannelBusy is TRUE, then scStartTime is the
    time in seconds for a play from disk on the
    channel. If scChannelBusy is FALSE, then
    is 0.
      </pre></td>
    </tr>

    <tr>
      <td>scEndTime</td>
      <td><pre>If scChannelBusy is TRUE, then scEndTime is the
    time in seconds for a play from disk on the
    channel. If scChannelBusy is FALSE, then
     is 0.
      </pre></td>
    </tr>

    <tr>
      <td>scCurrentTime</td>
      <td><pre>If scChannelBusy is TRUE, then scCurrentTime is the
    time in seconds for a play from disk on the
    channel. If scChannelBusy is FALSE, then
     is 0.
      </pre></td>
    </tr>

    <tr>
      <td>scChannelBusy</td>
      <td><pre>If the specified channel is currently making sound,
    scChannelBusy is TRUE; otherwise,
     is FALSE.
      </pre></td>
    </tr>

    <tr>
      <td>scChannelDisposed</td>
      <td><pre>Reserved for use by Apple.
      </pre></td>
    </tr>

    <tr>
      <td>scChannelPaused</td>
      <td><pre>If the specified channel is paused, then
     is TRUE; otherwise, scChannelPaused
    FALSE.
      </pre></td>
    </tr>

    <tr>
      <td>scUnused</td>
      <td><pre>Reserved for use by Apple.
      </pre></td>
    </tr>

    <tr>
      <td>scChannelAttributes</td>
      <td><pre>The current attributes of the specified channel. These
    are in the channel initialization parameters
    format.
      </pre></td>
    </tr>

    <tr>
      <td>scCPULoad</td>
      <td><pre>The CPU load for the specified channel.
    can mask out certain values in the scChannelAttributes field to how a
    has been initialized.
    mask for right/left pan values
    mask for sample rate values
    Reference © 1991-1992 Symantec Corporation
      </pre></td>
    </tr>
    </tbody></table>*/
    struct SCStatus
    {
      Fixed scStartTime;                 /**< starting time for play from disk*/
      Fixed scEndTime;                   /**< ending time for play from disk*/
      Fixed scCurrentTime;               /**< current time for play from disk*/
      Boolean scChannelBusy;             /**< TRUE if channel is making sound*/
      Boolean scChannelDisposed;         /**< reserved*/
      Boolean scChannelPaused;           /**< TRUE if channel is paused*/
      Boolean scUnused;                  /**< unused*/
      unsigned long scChannelAttributes; /**< attributes of this channel*/
      long scCPULoad;                    /**< CPU load for this channel*/
    } SCStatus;                          /**< */

    typedef struct SCStatus SCStatus;
    typedef SCStatus *SCStatusPtr;
    /**
    <pre><table><tbody>
    <tr>
      <td>unitType</td>
      <td><pre>The type of unit of time used in the start and end fields. You
    set this to seconds by specifying the constant
    .
      </pre></td>
    </tr>

    <tr>
      <td>selStart</td>
      <td><pre>The starting point in seconds of the sound to play.
      </pre></td>
    </tr>

    <tr>
      <td>selEnd</td>
      <td><pre>The ending point in seconds of the sound to play.
    a constant to specify the unit type.
    seconds
    no selection
    Reference © 1991-1992 Symantec Corporation
      </pre></td>
    </tr>
    </tbody></table>*/
    struct AudioSelection
    {
      long unitType;  /**< type of time unit*/
      Fixed selStart; /**< starting point of selection*/
      Fixed selEnd;   /**< ending point of selection*/
    } AudioSelection; /**< */

    typedef struct AudioSelection AudioSelection;
    typedef AudioSelection *AudioSelectionPtr;
#if CALL_NOT_IN_CARBON
    /**
    <pre><table><tbody>
    <tr>
      <td>dbNumFrames</td>
      <td><pre>The number of frames in the dbSoundData array.
      </pre></td>
    </tr>

    <tr>
      <td>dbFlags</td>
      <td><pre>Buffer status flags.
    Two long words into which you can place information that you
    to access in your doubleback procedure.
    A variable-length array. You write samples into this array,
    the synthesizer reads samples out of this array.
    buffer status flags field for each of the two buffers may contain either of
    values:
    dbBufferReady
    dbLastBuffer
    other bits in the dbFlags field are reserved by Apple, and your application
    not modify them.
    Reference © 1991-1992 Symantec Corporation
      </pre></td>
    </tr>
    </tbody></table>*/
    struct SndDoubleBuffer
    {
      long dbNumFrames;   /**<  number of frames in buffer*/
      long dbFlags;       /**<  buffer status flags*/
      long dbUserInfo[];  /**<  for application's use*/
      char dbSoundData[]; /**<  array of data*/
    } SndDoubleBuffer;    /**< */

    typedef struct SndDoubleBuffer SndDoubleBuffer;
    typedef SndDoubleBuffer *SndDoubleBufferPtr;

    typedef CALLBACK_API(void,
                         SndDoubleBackProcPtr)(SndChannelPtr channel,
                                               SndDoubleBufferPtr doubleBufferPtr);
    typedef STACK_UPP_TYPE(SndDoubleBackProcPtr) SndDoubleBackUPP;
#if CALL_NOT_IN_CARBON
    /**
     *  NewSndDoubleBackUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    SndDoubleBackUPP
    NewSndDoubleBackUPP(SndDoubleBackProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
    enum
    {
      uppSndDoubleBackProcInfo = 0x000003C0
    }; /** pascal no_return_value Func(4_bytes, 4_bytes) */
#ifdef __cplusplus
    inline SndDoubleBackUPP NewSndDoubleBackUPP(SndDoubleBackProcPtr userRoutine)
    {
      return (SndDoubleBackUPP)NewRoutineDescriptor((ProcPtr)(userRoutine),
                                                    uppSndDoubleBackProcInfo,
                                                    GetCurrentArchitecture());
    }
#else
#define NewSndDoubleBackUPP(userRoutine)                                     \
  (SndDoubleBackUPP)                                                         \
      NewRoutineDescriptor((ProcPtr)(userRoutine), uppSndDoubleBackProcInfo, \
                           GetCurrentArchitecture())
#endif
#endif

    /**
     *  DisposeSndDoubleBackUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    DisposeSndDoubleBackUPP(SndDoubleBackUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline void DisposeSndDoubleBackUPP(SndDoubleBackUPP userUPP)
    {
      DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
    }
#else
#define DisposeSndDoubleBackUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

    /**
     *  InvokeSndDoubleBackUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    InvokeSndDoubleBackUPP(SndChannelPtr channel,
                           SndDoubleBufferPtr doubleBufferPtr,
                           SndDoubleBackUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline void InvokeSndDoubleBackUPP(SndChannelPtr channel,
                                       SndDoubleBufferPtr doubleBufferPtr,
                                       SndDoubleBackUPP userUPP)
    {
      CALL_TWO_PARAMETER_UPP(userUPP, uppSndDoubleBackProcInfo, channel,
                             doubleBufferPtr);
    }
#else
#define InvokeSndDoubleBackUPP(channel, doubleBufferPtr, userUPP)        \
  CALL_TWO_PARAMETER_UPP((userUPP), uppSndDoubleBackProcInfo, (channel), \
                         (doubleBufferPtr))
#endif
#endif

#endif /** CALL_NOT_IN_CARBON */

#if CALL_NOT_IN_CARBON || OLDROUTINENAMES
/** support for pre-Carbon UPP routines: New...Proc and Call...Proc */
#define NewSndDoubleBackProc(userRoutine) NewSndDoubleBackUPP(userRoutine)
#define CallSndDoubleBackProc(userRoutine, channel, doubleBufferPtr) \
  InvokeSndDoubleBackUPP(channel, doubleBufferPtr, userRoutine)
#endif /** CALL_NOT_IN_CARBON */

    /**
    <pre><table><tbody>
    <tr>
      <td>dbhNumChannels</td>
      <td><pre>Indicates the number of channels for the sound (1 for
    sound, 2 for stereo).
      </pre></td>
    </tr>

    <tr>
      <td>dbhSampleSize</td>
      <td><pre>Indicates the sample size for the sound if the sound is
    compressed. If the sound is compressed,
     should be set to 0. Samples that are
    bits have a dbhSampleSize value of 8; samples that
    9-16 bits have a dbhSampleSize value of 16.
    only 8-bit samples are supported. For
    information on sample sizes, refer to the AIFF
    specification.
      </pre></td>
    </tr>

    <tr>
      <td>dbhCompressionID</td>
      <td><pre>Indicates the compression identification number of the
    algorithm, if the sound is compressed. If
    sound is not compressed, dbhCompressionID should
    set to 0.
      </pre></td>
    </tr>

    <tr>
      <td>dbhPacketSize</td>
      <td><pre>Indicates the packet size for the compression
    specified by dbhCompressionID , if the sound
    compressed.
      </pre></td>
    </tr>

    <tr>
      <td>dbhSampleRate</td>
      <td><pre>Indicates the sample rate for the sound. Note that the
    rate is declared as a Fixed data type, but the
    significant bit is not treated as a sign bit; instead,
    bit is interpreted as having the value 32,768.
    Indicates an array of two pointers, each of which
    point to a valid SndDoubleBuffer record.
      </pre></td>
    </tr>

    <tr>
      <td>dbhDoubleBack</td>
      <td><pre>Points to the application-defined routine that is called
    the double buffers are switched and the exhausted
    needs to be refilled.
    Reference © 1991-1992 Symantec Corporation
      </pre></td>
    </tr>
    </tbody></table>*/
    struct SndDoubleBufferHeader
    {
      short dbhNumChannels;               /**< number of sound*/
      short dbhSampleSize;                /**< sample size, if*/
      short dbhCompressionID;             /**< ID of compression*/
      short dbhPacketSize;                /**< number of bits per*/
      Fixed dbhSampleRate;                /**< sample rate*/
      SndDoubleBufferPtr dbhBufferPtr[];  /**< pointers to*/
      SndDoubleBackProcPtr dbhDoubleBack; /**< pointer to doubleback*/
    } SndDoubleBufferHeader;              /**< */

    typedef struct SndDoubleBufferHeader SndDoubleBufferHeader;
    typedef SndDoubleBufferHeader *SndDoubleBufferHeaderPtr;
    struct SndDoubleBufferHeader2
    {
      short dbhNumChannels;
      short dbhSampleSize;
      short dbhCompressionID;
      short dbhPacketSize;
      UnsignedFixed dbhSampleRate;
      SndDoubleBufferPtr dbhBufferPtr[2];
      SndDoubleBackUPP dbhDoubleBack;
      OSType dbhFormat;
    };
    typedef struct SndDoubleBufferHeader2 SndDoubleBufferHeader2;
    typedef SndDoubleBufferHeader2 *SndDoubleBufferHeader2Ptr;
#endif /** CALL_NOT_IN_CARBON */

    struct SoundInfoList
    {
      short count;
      Handle infoHandle;
    };
    typedef struct SoundInfoList SoundInfoList;
    typedef SoundInfoList *SoundInfoListPtr;
    struct SoundComponentData
    {
      long flags;
      OSType format;
      short numChannels;
      short sampleSize;
      UnsignedFixed sampleRate;
      long sampleCount;
      Byte *buffer;
      long reserved;
    };
    typedef struct SoundComponentData SoundComponentData;
    typedef SoundComponentData *SoundComponentDataPtr;
    struct ExtendedSoundComponentData
    {
      SoundComponentData desc; /**description of sound buffer*/
      long recordSize;         /**size of this record in bytes*/
      long extendedFlags;      /**flags for extended record*/
      long bufferSize;         /**size of buffer in bytes*/
    };
    typedef struct ExtendedSoundComponentData ExtendedSoundComponentData;
    typedef ExtendedSoundComponentData *ExtendedSoundComponentDataPtr;
    typedef struct SoundParamBlock SoundParamBlock;
    typedef SoundParamBlock *SoundParamBlockPtr;
    typedef CALLBACK_API(Boolean, SoundParamProcPtr)(SoundParamBlockPtr *pb);
    typedef STACK_UPP_TYPE(SoundParamProcPtr) SoundParamUPP;
    struct SoundParamBlock
    {
      long recordSize;              /**size of this record in bytes*/
      SoundComponentData desc;      /**description of sound buffer*/
      UnsignedFixed rateMultiplier; /**rate multiplier to apply to sound*/
      short leftVolume;             /**volumes to apply to sound*/
      short rightVolume;
      long quality;                /**quality to apply to sound*/
      ComponentInstance filter;    /**filter to apply to sound*/
      SoundParamUPP moreRtn;       /**routine to call to get more data*/
      SoundParamUPP completionRtn; /**routine to call when buffer is complete*/
      long refCon;                 /**user refcon*/
      short result;                /**result*/
    };

    struct ExtendedSoundParamBlock
    {
      SoundParamBlock pb; /**classic SoundParamBlock except recordSize ==
                             sizeof(ExtendedSoundParamBlock)*/
      short reserved;
      long extendedFlags; /**flags*/
      long bufferSize;    /**size of buffer in bytes*/
    };
    typedef struct ExtendedSoundParamBlock ExtendedSoundParamBlock;
    typedef ExtendedSoundParamBlock *ExtendedSoundParamBlockPtr;
    struct CompressionInfo
    {
      long recordSize;
      OSType format;
      short compressionID;
      unsigned short samplesPerPacket;
      unsigned short bytesPerPacket;
      unsigned short bytesPerFrame;
      unsigned short bytesPerSample;
      unsigned short futureUse1;
    };
    typedef struct CompressionInfo CompressionInfo;
    typedef CompressionInfo *CompressionInfoPtr;
    typedef CompressionInfoPtr *CompressionInfoHandle;
    /**variables for floating point conversion*/
    struct SoundSlopeAndInterceptRecord
    {
      Float64 slope;
      Float64 intercept;
      Float64 minClip;
      Float64 maxClip;
    };
    typedef struct SoundSlopeAndInterceptRecord SoundSlopeAndInterceptRecord;
    typedef SoundSlopeAndInterceptRecord *SoundSlopeAndInterceptPtr;
    /**private thing to use as a reference to a Sound Converter*/
    typedef struct OpaqueSoundConverter *SoundConverter;
    /**callback routine to provide data to the Sound Converter*/
    typedef CALLBACK_API(Boolean, SoundConverterFillBufferDataProcPtr)(
        SoundComponentDataPtr *data, void *refCon);
    typedef STACK_UPP_TYPE(SoundConverterFillBufferDataProcPtr)
        SoundConverterFillBufferDataUPP;
    /**private thing to use as a reference to a Sound Source*/
    typedef struct OpaqueSoundSource *SoundSource;
    typedef SoundSource *SoundSourcePtr;

    struct SoundComponentLink
    {
      ComponentDescription description; /**Describes the sound component*/
      SoundSource mixerID;              /**Reserved by Apple*/
      SoundSource *linkID;              /**Reserved by Apple*/
    };
    typedef struct SoundComponentLink SoundComponentLink;
    typedef SoundComponentLink *SoundComponentLinkPtr;
    struct AudioInfo
    {
      long capabilitiesFlags;        /**Describes device capabilities*/
      long reserved;                 /**Reserved by Apple*/
      unsigned short numVolumeSteps; /**Number of significant increments between min
                                        and max volume*/
    };
    typedef struct AudioInfo AudioInfo;
    typedef AudioInfo *AudioInfoPtr;
    struct AudioFormatAtom
    {
      long size;       /** = sizeof(AudioFormatAtom)*/
      OSType atomType; /** = kAudioFormatAtomType*/
      OSType format;
    };
    typedef struct AudioFormatAtom AudioFormatAtom;
    typedef AudioFormatAtom *AudioFormatAtomPtr;
    struct AudioEndianAtom
    {
      long size;       /** = sizeof(AudioEndianAtom)*/
      OSType atomType; /** = kAudioEndianAtomType*/
      short littleEndian;
    };
    typedef struct AudioEndianAtom AudioEndianAtom;
    typedef AudioEndianAtom *AudioEndianAtomPtr;
    struct AudioTerminatorAtom
    {
      long size;       /** = sizeof(AudioTerminatorAtom)*/
      OSType atomType; /** = kAudioTerminatorAtomType*/
    };
    typedef struct AudioTerminatorAtom AudioTerminatorAtom;
    typedef AudioTerminatorAtom *AudioTerminatorAtomPtr;
    struct LevelMeterInfo
    {
      short numChannels; /** mono or stereo source*/
      UInt8 leftMeter;   /** 0-255 range*/
      UInt8 rightMeter;  /** 0-255 range*/
    };
    typedef struct LevelMeterInfo LevelMeterInfo;
    typedef LevelMeterInfo *LevelMeterInfoPtr;
    struct EQSpectrumBandsRecord
    {
      short count;
      UnsignedFixedPtr frequency; /** pointer to array of frequencies*/
    };
    typedef struct EQSpectrumBandsRecord EQSpectrumBandsRecord;
    typedef EQSpectrumBandsRecord *EQSpectrumBandsRecordPtr;

    /** Sound Input Structures*/
    typedef struct SPB SPB;
    typedef SPB *SPBPtr;

    /**user procedures called by sound input routines*/
    typedef CALLBACK_API_REGISTER68K(void, SIInterruptProcPtr,
                                     (SPBPtr inParamPtr, Ptr dataBuffer,
                                      short peakAmplitude, long sampleSize));
    typedef CALLBACK_API(void, SICompletionProcPtr)(SPBPtr inParamPtr);
    typedef REGISTER_UPP_TYPE(SIInterruptProcPtr) SIInterruptUPP;
    typedef STACK_UPP_TYPE(SICompletionProcPtr) SICompletionUPP;

    /**Sound Input Parameter Block*/
    /**
    <pre><table><tbody>
    <tr>
      <td>inRefNum</td>
      <td><pre>The reference number of the sound input device (as
    from SPBOpenDevice ) from which the
    is to occur.
      </pre></td>
    </tr>

    <tr>
      <td>count</td>
      <td><pre>On input, the number of bytes to record. On output, the
    of bytes actually recorded. If this field
    a longer recording time than the milliseconds
    then the milliseconds field is ignored on input.
      </pre></td>
    </tr>

    <tr>
      <td>milliseconds</td>
      <td><pre>On input, the number of milliseconds to record. On
    the number of milliseconds actually recorded. If
    field specifies a longer recording time than the
    field, then the count field is ignored on input.
      </pre></td>
    </tr>

    <tr>
      <td>bufferLength</td>
      <td><pre>The length of the buffer into which recorded sound data
    placed. The recording time specified by the count or
    field is truncated to fit into this length, if
    necessary.
    A pointer to the buffer into which recorded data is
    If this field is NULL, then the count,
    and bufferLength fields are ignored and the
    will continue indefinitely until
     is called. However, the data is
    stored anywhere, so setting this field to NULL is
    only if you want to do something in your
    routine but do not want to save the recorded
    sound.
      </pre></td>
    </tr>

    <tr>
      <td>completionRoutine</td>
      <td><pre>A pointer to a completion routine that is called when
    recording terminates as a result of your calling
     or when the limit specified by
    count or milliseconds field is reached. The
    Reference © 1991-1992 Symantec Corporation
      </pre></td>
    </tr>
    </tbody></table>*/
    struct SPB
    {
      long inRefNum;              /**< reference number of input device*/
      unsigned long count;        /**< number of bytes to record*/
      unsigned long milliseconds; /**< number of milliseconds to record*/
      unsigned long bufferLength; /**< length of buffer to record into*/
      ProcPtr completionRoutine;  /**< pointer to a completion routine*/
      ProcPtr interruptRoutine;   /**< pointer to an interrupt routine*/
      long userLong;              /**< for application's use*/
    } SPB;                        /**< */

    /**
     *  NewSoundParamUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    SoundParamUPP
    NewSoundParamUPP(SoundParamProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
    enum
    {
      uppSoundParamProcInfo = 0x000000D0
    }; /** pascal 1_byte Func(4_bytes) */
#ifdef __cplusplus
    inline SoundParamUPP NewSoundParamUPP(SoundParamProcPtr userRoutine)
    {
      return (SoundParamUPP)NewRoutineDescriptor(
          (ProcPtr)(userRoutine), uppSoundParamProcInfo, GetCurrentArchitecture());
    }
#else
#define NewSoundParamUPP(userRoutine)   \
  (SoundParamUPP) NewRoutineDescriptor( \
      (ProcPtr)(userRoutine), uppSoundParamProcInfo, GetCurrentArchitecture())
#endif
#endif

    /**
     *  NewSoundConverterFillBufferDataUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.1 and later
     *    \mac_os_x         in version 10.0 and later
     */
    SoundConverterFillBufferDataUPP
    NewSoundConverterFillBufferDataUPP(
        SoundConverterFillBufferDataProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
    enum
    {
      uppSoundConverterFillBufferDataProcInfo = 0x000003D0
    }; /** pascal 1_byte Func(4_bytes, 4_bytes) */
#ifdef __cplusplus
    inline SoundConverterFillBufferDataUPP NewSoundConverterFillBufferDataUPP(
        SoundConverterFillBufferDataProcPtr userRoutine)
    {
      return (SoundConverterFillBufferDataUPP)NewRoutineDescriptor(
          (ProcPtr)(userRoutine), uppSoundConverterFillBufferDataProcInfo,
          GetCurrentArchitecture());
    }
#else
#define NewSoundConverterFillBufferDataUPP(userRoutine)                \
  (SoundConverterFillBufferDataUPP) NewRoutineDescriptor(              \
      (ProcPtr)(userRoutine), uppSoundConverterFillBufferDataProcInfo, \
      GetCurrentArchitecture())
#endif
#endif

    /**
     *  NewSIInterruptUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    SIInterruptUPP
    NewSIInterruptUPP(SIInterruptProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
    enum
    {
      uppSIInterruptProcInfo = 0x1C579802
    }; /** register no_return_value Func(4_bytes:A0, 4_bytes:A1, 2_bytes:D0,
          4_bytes:D1) */
#ifdef __cplusplus
    inline SIInterruptUPP NewSIInterruptUPP(SIInterruptProcPtr userRoutine)
    {
      return (SIInterruptUPP)NewRoutineDescriptor(
          (ProcPtr)(userRoutine), uppSIInterruptProcInfo, GetCurrentArchitecture());
    }
#else
#define NewSIInterruptUPP(userRoutine)                                     \
  (SIInterruptUPP)                                                         \
      NewRoutineDescriptor((ProcPtr)(userRoutine), uppSIInterruptProcInfo, \
                           GetCurrentArchitecture())
#endif
#endif

    /**
     *  NewSICompletionUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    SICompletionUPP
    NewSICompletionUPP(SICompletionProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
    enum
    {
      uppSICompletionProcInfo = 0x000000C0
    }; /** pascal no_return_value Func(4_bytes) */
#ifdef __cplusplus
    inline SICompletionUPP NewSICompletionUPP(SICompletionProcPtr userRoutine)
    {
      return (SICompletionUPP)NewRoutineDescriptor((ProcPtr)(userRoutine),
                                                   uppSICompletionProcInfo,
                                                   GetCurrentArchitecture());
    }
#else
#define NewSICompletionUPP(userRoutine)                                     \
  (SICompletionUPP)                                                         \
      NewRoutineDescriptor((ProcPtr)(userRoutine), uppSICompletionProcInfo, \
                           GetCurrentArchitecture())
#endif
#endif

    /**
     *  DisposeSoundParamUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    DisposeSoundParamUPP(SoundParamUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline void DisposeSoundParamUPP(SoundParamUPP userUPP)
    {
      DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
    }
#else
#define DisposeSoundParamUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

    /**
     *  DisposeSoundConverterFillBufferDataUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.1 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    DisposeSoundConverterFillBufferDataUPP(SoundConverterFillBufferDataUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline void DisposeSoundConverterFillBufferDataUPP(
        SoundConverterFillBufferDataUPP userUPP)
    {
      DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
    }
#else
#define DisposeSoundConverterFillBufferDataUPP(userUPP) \
  DisposeRoutineDescriptor(userUPP)
#endif
#endif

    /**
     *  DisposeSIInterruptUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    DisposeSIInterruptUPP(SIInterruptUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline void DisposeSIInterruptUPP(SIInterruptUPP userUPP)
    {
      DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
    }
#else
#define DisposeSIInterruptUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

    /**
     *  DisposeSICompletionUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    DisposeSICompletionUPP(SICompletionUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline void DisposeSICompletionUPP(SICompletionUPP userUPP)
    {
      DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
    }
#else
#define DisposeSICompletionUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

    /**
     *  InvokeSoundParamUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    Boolean
    InvokeSoundParamUPP(SoundParamBlockPtr *pb, SoundParamUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline Boolean InvokeSoundParamUPP(SoundParamBlockPtr *pb,
                                       SoundParamUPP userUPP)
    {
      return (Boolean)CALL_ONE_PARAMETER_UPP(userUPP, uppSoundParamProcInfo, pb);
    }
#else
#define InvokeSoundParamUPP(pb, userUPP) \
  (Boolean) CALL_ONE_PARAMETER_UPP((userUPP), uppSoundParamProcInfo, (pb))
#endif
#endif

    /**
     *  InvokeSoundConverterFillBufferDataUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.1 and later
     *    \mac_os_x         in version 10.0 and later
     */
    Boolean
    InvokeSoundConverterFillBufferDataUPP(SoundComponentDataPtr *data, void *refCon,
                                          SoundConverterFillBufferDataUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline Boolean
    InvokeSoundConverterFillBufferDataUPP(SoundComponentDataPtr *data, void *refCon,
                                          SoundConverterFillBufferDataUPP userUPP)
    {
      return (Boolean)CALL_TWO_PARAMETER_UPP(
          userUPP, uppSoundConverterFillBufferDataProcInfo, data, refCon);
    }
#else
#define InvokeSoundConverterFillBufferDataUPP(data, refCon, userUPP) \
  (Boolean) CALL_TWO_PARAMETER_UPP(                                  \
      (userUPP), uppSoundConverterFillBufferDataProcInfo, (data), (refCon))
#endif
#endif

    /**
     *  InvokeSIInterruptUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    InvokeSIInterruptUPP(SPBPtr inParamPtr, Ptr dataBuffer, short peakAmplitude,
                         long sampleSize, SIInterruptUPP userUPP);
#if !OPAQUE_UPP_TYPES && \
    (!TARGET_OS_MAC || !TARGET_CPU_68K || TARGET_RT_MAC_CFM)
#ifdef __cplusplus
    inline void InvokeSIInterruptUPP(SPBPtr inParamPtr, Ptr dataBuffer,
                                     short peakAmplitude, long sampleSize,
                                     SIInterruptUPP userUPP)
    {
      CALL_FOUR_PARAMETER_UPP(userUPP, uppSIInterruptProcInfo, inParamPtr,
                              dataBuffer, peakAmplitude, sampleSize);
    }
#else
#define InvokeSIInterruptUPP(inParamPtr, dataBuffer, peakAmplitude,        \
                             sampleSize, userUPP)                          \
  CALL_FOUR_PARAMETER_UPP((userUPP), uppSIInterruptProcInfo, (inParamPtr), \
                          (dataBuffer), (peakAmplitude), (sampleSize))
#endif
#endif

    /**
     *  InvokeSICompletionUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    InvokeSICompletionUPP(SPBPtr inParamPtr, SICompletionUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline void InvokeSICompletionUPP(SPBPtr inParamPtr, SICompletionUPP userUPP)
    {
      CALL_ONE_PARAMETER_UPP(userUPP, uppSICompletionProcInfo, inParamPtr);
    }
#else
#define InvokeSICompletionUPP(inParamPtr, userUPP) \
  CALL_ONE_PARAMETER_UPP((userUPP), uppSICompletionProcInfo, (inParamPtr))
#endif
#endif

#if CALL_NOT_IN_CARBON || OLDROUTINENAMES
/** support for pre-Carbon UPP routines: New...Proc and Call...Proc */
#define NewSoundParamProc(userRoutine) NewSoundParamUPP(userRoutine)
#define NewSoundConverterFillBufferDataProc(userRoutine) \
  NewSoundConverterFillBufferDataUPP(userRoutine)
#define NewSIInterruptProc(userRoutine) NewSIInterruptUPP(userRoutine)
#define NewSICompletionProc(userRoutine) NewSICompletionUPP(userRoutine)
#define CallSoundParamProc(userRoutine, pb) InvokeSoundParamUPP(pb, userRoutine)
#define CallSoundConverterFillBufferDataProc(userRoutine, data, refCon) \
  InvokeSoundConverterFillBufferDataUPP(data, refCon, userRoutine)
#define CallSIInterruptProc(userRoutine, inParamPtr, dataBuffer,          \
                            peakAmplitude, sampleSize)                    \
  InvokeSIInterruptUPP(inParamPtr, dataBuffer, peakAmplitude, sampleSize, \
                       userRoutine)
#define CallSICompletionProc(userRoutine, inParamPtr) \
  InvokeSICompletionUPP(inParamPtr, userRoutine)
#endif /** CALL_NOT_IN_CARBON */

    typedef CALLBACK_API(void, FilePlayCompletionProcPtr)(SndChannelPtr chan);
    typedef STACK_UPP_TYPE(FilePlayCompletionProcPtr) FilePlayCompletionUPP;
#if CALL_NOT_IN_CARBON
    /**
     *  NewFilePlayCompletionUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    FilePlayCompletionUPP
    NewFilePlayCompletionUPP(FilePlayCompletionProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
    enum
    {
      uppFilePlayCompletionProcInfo = 0x000000C0
    }; /** pascal no_return_value Func(4_bytes) */
#ifdef __cplusplus
    inline FilePlayCompletionUPP
    NewFilePlayCompletionUPP(FilePlayCompletionProcPtr userRoutine)
    {
      return (FilePlayCompletionUPP)NewRoutineDescriptor(
          (ProcPtr)(userRoutine), uppFilePlayCompletionProcInfo,
          GetCurrentArchitecture());
    }
#else
#define NewFilePlayCompletionUPP(userRoutine)                                 \
  (FilePlayCompletionUPP) NewRoutineDescriptor((ProcPtr)(userRoutine),        \
                                               uppFilePlayCompletionProcInfo, \
                                               GetCurrentArchitecture())
#endif
#endif

    /**
     *  DisposeFilePlayCompletionUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    DisposeFilePlayCompletionUPP(FilePlayCompletionUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline void DisposeFilePlayCompletionUPP(FilePlayCompletionUPP userUPP)
    {
      DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
    }
#else
#define DisposeFilePlayCompletionUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

    /**
     *  InvokeFilePlayCompletionUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    InvokeFilePlayCompletionUPP(SndChannelPtr chan, FilePlayCompletionUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline void InvokeFilePlayCompletionUPP(SndChannelPtr chan,
                                            FilePlayCompletionUPP userUPP)
    {
      CALL_ONE_PARAMETER_UPP(userUPP, uppFilePlayCompletionProcInfo, chan);
    }
#else
#define InvokeFilePlayCompletionUPP(chan, userUPP) \
  CALL_ONE_PARAMETER_UPP((userUPP), uppFilePlayCompletionProcInfo, (chan))
#endif
#endif

#endif /** CALL_NOT_IN_CARBON */

#if CALL_NOT_IN_CARBON || OLDROUTINENAMES
/** support for pre-Carbon UPP routines: New...Proc and Call...Proc */
#define NewFilePlayCompletionProc(userRoutine) \
  NewFilePlayCompletionUPP(userRoutine)
#define CallFilePlayCompletionProc(userRoutine, chan) \
  InvokeFilePlayCompletionUPP(chan, userRoutine)
#endif /** CALL_NOT_IN_CARBON */

    /**
      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
       prototypes
      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    */

    /** Sound Manager routines */
    /**
     *  SysBeep()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    SysBeep(short duration);

    /**
     *  SndDoCommand()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    SndDoCommand(SndChannelPtr chan, const SndCommand *cmd, Boolean noWait);

    /**
     *  SndDoImmediate()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    SndDoImmediate(SndChannelPtr chan, const SndCommand *cmd);

    /**
     *  SndNewChannel()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    SndNewChannel(SndChannelPtr *chan, short synth, long init,
                  SndCallBackUPP userRoutine);

    /**
     *  SndDisposeChannel()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    SndDisposeChannel(SndChannelPtr chan, Boolean quietNow);

    /**
     *  SndPlay()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    SndPlay(SndChannelPtr chan, SndListHandle sndHandle, Boolean async);

#if OLDROUTINENAMES
#if CALL_NOT_IN_CARBON
    /**
     *  SndAddModifier()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    OSErr
    SndAddModifier(SndChannelPtr chan, Ptr modifier, short id, long init);

#endif /** CALL_NOT_IN_CARBON */

#endif /** OLDROUTINENAMES */

#if CALL_NOT_IN_CARBON
    /**
     *  SndControl()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    OSErr
    SndControl(short id, SndCommand *cmd);

/** Sound Manager 2.0 and later, uses _SoundDispatch */
#endif /** CALL_NOT_IN_CARBON */

    /**
    \brief SndSoundManagerVersion Determine the version of the Sound Manager

    <pre>You can use SndSoundManagerVersion to determine the version of the
Sound Manager tools available on a machine.
Returns: a version number that contains the same information as in
the first 4 bytes of a 'vers' resource.
</pre>
* \note <pre>You can call SndSoundManagerVersion at interrupt time.
You can obtain information about a sound channel and about the
Sound Manager itself by calling the SndControl , SndChannelStatus ,
and SndManagerStatus functions. You can obtain the version numbers of
the Sound Manager , the MACE tools, and the sound input routines by
calling the SndSoundManagerVersion , MACEVersion , and
SPBVersion functions, respectively.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
    NumVersion
    SndSoundManagerVersion(void);

#if CALL_NOT_IN_CARBON
    /**
     *  SndStartFilePlay()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    OSErr
    SndStartFilePlay(SndChannelPtr chan, short fRefNum, short resNum,
                     long bufferSize, void *theBuffer,
                     AudioSelectionPtr theSelection,
                     FilePlayCompletionUPP theCompletion, Boolean async);

    /**
    \brief SndPauseFilePlay Suspend asynchronous play from disk

    <pre>You can use SndPauseFilePlay in conjunction with SndStopFilePlay to
control play from disk on a sound channel. Note that this call can be made only
if your application has already called SndStartFilePlay with a valid sound
channel. This function cannot be used with a synchronous SndStartFilePlay
because, by definition, program control does not return to the caller until
after the sound has completely finished playing.
chan should be a pointer to a valid sound channel. If the channel is not
being used for play from disk, then SndPauseFilePlay returns the
result code channelNotBusy. If the channel is busy and paused, then
play from disk is resumed. If the channel is busy and the channel is
not paused, then play from disk is suspended..
Returns: an operating system Error Code .
noErr(0)No error
queueFull (-203)No room in the queue
badChannel (-205)Channel is corrupt or unusable
channelNotBusy (-211)Channel not currently used
</pre>
* \note <pre>You can call SndPauseFilePlay at interrupt time.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
    OSErr
    SndPauseFilePlay(SndChannelPtr chan);

    /**
     *  SndStopFilePlay()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    OSErr
    SndStopFilePlay(SndChannelPtr chan, Boolean quietNow);

#endif /** CALL_NOT_IN_CARBON */

    /**
     *  SndChannelStatus()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    SndChannelStatus(SndChannelPtr chan, short theLength, SCStatusPtr theStatus);

    /**
    \brief SndManagerStatus Determine information about the Sound Manager

    <pre>You can use SndManagerStatus to determine the status of the
Sound Manager sound channel.
theLength should be the size in bytes of the SMStatus structure that
theStatus points to.
theStatus should be a pointer to an SMStatus structure which is filled out
with the status information.
Returns: an operating system Error Code .
noErr(0)No error
</pre>
* \note <pre>You can call SndManagerStatus at interrupt time.
You can obtain information about a sound channel and about the
Sound Manager itself by calling the SndControl , SndChannelStatus ,
and SndManagerStatus functions. You can obtain the version numbers of
the Sound Manager , the MACE tools, and the sound input routines by
calling the SndSoundManagerVersion , MACEVersion , and
SPBVersion functions, respectively.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
    OSErr
    SndManagerStatus(short theLength, SMStatusPtr theStatus);

    /**
    \brief SndGetSysBeepState Determine whether SysBeep is enabled

    <pre>The SndGetSysBeepState procedure is used to determine whether SysBeep
is enabled.
sysBeepState is one of two states , either the sysBeepDisable or the
sysBeepEnable constant.
Returns: none
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
    void
    SndGetSysBeepState(short *sysBeepState);

    /**
    \brief SndSetSysBeepState Set the state of the system alert sound..

    <pre>You can use SndSetSysBeepState to set the state of the system alert sound.
sysBeepState is one of two states , either the sysBeepDisable or the
sysBeepEnable constant.
Returns: an operating system Error Code .
noErr(0)No error
paramErr (-50)A parameter is incorrect
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
    OSErr
    SndSetSysBeepState(short sysBeepState);

#if CALL_NOT_IN_CARBON
    /**
     *  SndPlayDoubleBuffer()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    OSErr
    SndPlayDoubleBuffer(SndChannelPtr chan, SndDoubleBufferHeaderPtr theParams);

    /** MACE compression routines, uses _SoundDispatch */

    /**
    \brief Determine the version of the MACE tools

    <pre>You can use MACEVersion to determine the version of the MACE tools
available on a machine.
Returns: a version number that contains the same information as in the
first 4 bytes of a 'vers' resource.
</pre>
* \note <pre> You can call MACEVersion at interrupt time.
You can obtain information about a sound channel and about the
Sound Manager itself by calling the SndControl , SndChannelStatus ,
and SndManagerStatus functions. You can obtain the version numbers of
the Sound Manager , the MACE tools, and the sound input routines by
calling the SndSoundManagerVersion , MACEVersion , and
SPBVersion functions, respectively.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
    NumVersion
    MACEVersion(void);

    /**
     *  Comp3to1()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    Comp3to1(const void *inBuffer, void *outBuffer, unsigned long cnt,
             StateBlockPtr inState, StateBlockPtr outState,
             unsigned long numChannels, unsigned long whichChannel);

    /**
     *  Exp1to3()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    Exp1to3(const void *inBuffer, void *outBuffer, unsigned long cnt,
            StateBlockPtr inState, StateBlockPtr outState,
            unsigned long numChannels, unsigned long whichChannel);

    /**
     *  Comp6to1()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    Comp6to1(const void *inBuffer, void *outBuffer, unsigned long cnt,
             StateBlockPtr inState, StateBlockPtr outState,
             unsigned long numChannels, unsigned long whichChannel);

    /**
     *  Exp1to6()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    Exp1to6(const void *inBuffer, void *outBuffer, unsigned long cnt,
            StateBlockPtr inState, StateBlockPtr outState,
            unsigned long numChannels, unsigned long whichChannel);

/** Sound Manager 3.0 and later calls, uses _SoundDispatch */
#endif /** CALL_NOT_IN_CARBON */

    /**
     *  GetSysBeepVolume()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    GetSysBeepVolume(long *level);

    /**
     *  SetSysBeepVolume()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    SetSysBeepVolume(long level);

    /**
     *  GetDefaultOutputVolume()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    GetDefaultOutputVolume(long *level);

    /**
     *  SetDefaultOutputVolume()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    SetDefaultOutputVolume(long level);

    /**
     *  GetSoundHeaderOffset()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    GetSoundHeaderOffset(SndListHandle sndHandle, long *offset);

    /**
     *  UnsignedFixedMulDiv()
     *

     *    \non_carbon_cfm   in SoundLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         not available
     */
    UnsignedFixed
    UnsignedFixedMulDiv(UnsignedFixed value, UnsignedFixed multiplier,
                        UnsignedFixed divisor);

    /**
     *  GetCompressionInfo()
     *

     *    \non_carbon_cfm   in SoundLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    GetCompressionInfo(short compressionID, OSType format, short numChannels,
                       short sampleSize, CompressionInfoPtr cp);

    /**
     *  SetSoundPreference()
     *

     *    \non_carbon_cfm   in SoundLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    SetSoundPreference(OSType theType, Str255 name, Handle settings);

    /**
     *  GetSoundPreference()
     *

     *    \non_carbon_cfm   in SoundLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    GetSoundPreference(OSType theType, Str255 name, Handle settings);

    /**
     *  OpenMixerSoundComponent()
     *

     *    \non_carbon_cfm   in SoundLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    OpenMixerSoundComponent(SoundComponentDataPtr outputDescription,
                            long outputFlags, ComponentInstance *mixerComponent);

    /**
     *  CloseMixerSoundComponent()
     *

     *    \non_carbon_cfm   in SoundLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    CloseMixerSoundComponent(ComponentInstance ci);

    /** Sound Manager 3.1 and later calls, uses _SoundDispatch */
    /**
     *  SndGetInfo()
     *

     *    \non_carbon_cfm   in SoundLib 3.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    SndGetInfo(SndChannelPtr chan, OSType selector, void *infoPtr);

    /**
     *  SndSetInfo()
     *

     *    \non_carbon_cfm   in SoundLib 3.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    SndSetInfo(SndChannelPtr chan, OSType selector, const void *infoPtr);

    /**
     *  GetSoundOutputInfo()
     *

     *    \non_carbon_cfm   in SoundLib 3.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    GetSoundOutputInfo(Component outputDevice, OSType selector, void *infoPtr);

    /**
     *  SetSoundOutputInfo()
     *

     *    \non_carbon_cfm   in SoundLib 3.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    SetSoundOutputInfo(Component outputDevice, OSType selector, const void *infoPtr);

    /** Sound Manager 3.2 and later calls, uses _SoundDispatch */
    /**
     *  GetCompressionName()
     *

     *    \non_carbon_cfm   in SoundLib 3.2 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    GetCompressionName(OSType compressionType, Str255 compressionName);

    /**
     *  SoundConverterOpen()
     *

     *    \non_carbon_cfm   in SoundLib 3.2 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    SoundConverterOpen(const SoundComponentData *inputFormat,
                       const SoundComponentData *outputFormat, SoundConverter *sc);

    /**
     *  SoundConverterClose()
     *

     *    \non_carbon_cfm   in SoundLib 3.2 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    SoundConverterClose(SoundConverter sc);

    /**
     *  SoundConverterGetBufferSizes()
     *

     *    \non_carbon_cfm   in SoundLib 3.2 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    SoundConverterGetBufferSizes(SoundConverter sc, unsigned long inputBytesTarget,
                                 unsigned long *inputFrames,
                                 unsigned long *inputBytes,
                                 unsigned long *outputBytes);

    /**
     *  SoundConverterBeginConversion()
     *

     *    \non_carbon_cfm   in SoundLib 3.2 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    SoundConverterBeginConversion(SoundConverter sc);

    /**
     *  SoundConverterConvertBuffer()
     *

     *    \non_carbon_cfm   in SoundLib 3.2 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    SoundConverterConvertBuffer(SoundConverter sc, const void *inputPtr,
                                unsigned long inputFrames, void *outputPtr,
                                unsigned long *outputFrames,
                                unsigned long *outputBytes);

    /**
     *  SoundConverterEndConversion()
     *

     *    \non_carbon_cfm   in SoundLib 3.2 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    SoundConverterEndConversion(SoundConverter sc, void *outputPtr,
                                unsigned long *outputFrames,
                                unsigned long *outputBytes);

    /** Sound Manager 3.3 and later calls, uses _SoundDispatch */
    /**
     *  SoundConverterGetInfo()
     *

     *    \non_carbon_cfm   in SoundLib 3.3 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    SoundConverterGetInfo(SoundConverter sc, OSType selector, void *infoPtr);

    /**
     *  SoundConverterSetInfo()
     *

     *    \non_carbon_cfm   in SoundLib 3.3 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    SoundConverterSetInfo(SoundConverter sc, OSType selector, void *infoPtr);

    /** Sound Manager 3.6 and later calls, uses _SoundDispatch */
    /**
     *  SoundConverterFillBuffer()
     *

     *    \non_carbon_cfm   in SoundLib 3.6 and later
     *    \carbon_lib        in CarbonLib 1.1 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    SoundConverterFillBuffer(SoundConverter sc,
                             SoundConverterFillBufferDataUPP fillBufferDataUPP,
                             void *fillBufferDataRefCon, void *outputBuffer,
                             unsigned long outputBufferByteSize,
                             unsigned long *bytesWritten,
                             unsigned long *framesWritten,
                             unsigned long *outputFlags);

    /**
     *  SoundManagerGetInfo()
     *

     *    \non_carbon_cfm   in SoundLib 3.6 and later
     *    \carbon_lib        in CarbonLib 1.1 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    SoundManagerGetInfo(OSType selector, void *infoPtr);

    /**
     *  SoundManagerSetInfo()
     *

     *    \non_carbon_cfm   in SoundLib 3.6 and later
     *    \carbon_lib        in CarbonLib 1.1 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    SoundManagerSetInfo(OSType selector, const void *infoPtr);

    /**
      Sound Component Functions
       basic sound component functions
    */

    /**
     *  SoundComponentInitOutputDevice()
     *

     *    \non_carbon_cfm   in SoundLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    ComponentResult
    SoundComponentInitOutputDevice(ComponentInstance ti, long actions);

    /**
     *  SoundComponentSetSource()
     *

     *    \non_carbon_cfm   in SoundLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    ComponentResult
    SoundComponentSetSource(ComponentInstance ti, SoundSource sourceID,
                            ComponentInstance source);

    /**
     *  SoundComponentGetSource()
     *

     *    \non_carbon_cfm   in SoundLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    ComponentResult
    SoundComponentGetSource(ComponentInstance ti, SoundSource sourceID,
                            ComponentInstance *source);

    /**
     *  SoundComponentGetSourceData()
     *

     *    \non_carbon_cfm   in SoundLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    ComponentResult
    SoundComponentGetSourceData(ComponentInstance ti,
                                SoundComponentDataPtr *sourceData);

    /**
     *  SoundComponentSetOutput()
     *

     *    \non_carbon_cfm   in SoundLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    ComponentResult
    SoundComponentSetOutput(ComponentInstance ti, SoundComponentDataPtr requested,
                            SoundComponentDataPtr *actual);

    /** junction methods for the mixer, must be called at non-interrupt level*/
    /**
     *  SoundComponentAddSource()
     *

     *    \non_carbon_cfm   in SoundLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    ComponentResult
    SoundComponentAddSource(ComponentInstance ti, SoundSource *sourceID);

    /**
     *  SoundComponentRemoveSource()
     *

     *    \non_carbon_cfm   in SoundLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    ComponentResult
    SoundComponentRemoveSource(ComponentInstance ti, SoundSource sourceID);

    /** info methods*/
    /**
     *  SoundComponentGetInfo()
     *

     *    \non_carbon_cfm   in SoundLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    ComponentResult
    SoundComponentGetInfo(ComponentInstance ti, SoundSource sourceID,
                          OSType selector, void *infoPtr);

    /**
     *  SoundComponentSetInfo()
     *

     *    \non_carbon_cfm   in SoundLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    ComponentResult
    SoundComponentSetInfo(ComponentInstance ti, SoundSource sourceID,
                          OSType selector, void *infoPtr);

    /** control methods*/
    /**
     *  SoundComponentStartSource()
     *

     *    \non_carbon_cfm   in SoundLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    ComponentResult
    SoundComponentStartSource(ComponentInstance ti, short count,
                              SoundSource *sources);

    /**
     *  SoundComponentStopSource()
     *

     *    \non_carbon_cfm   in SoundLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    ComponentResult
    SoundComponentStopSource(ComponentInstance ti, short count,
                             SoundSource *sources);

    /**
     *  SoundComponentPauseSource()
     *

     *    \non_carbon_cfm   in SoundLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    ComponentResult
    SoundComponentPauseSource(ComponentInstance ti, short count,
                              SoundSource *sources);

    /**
     *  SoundComponentPlaySourceBuffer()
     *

     *    \non_carbon_cfm   in SoundLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    ComponentResult
    SoundComponentPlaySourceBuffer(ComponentInstance ti, SoundSource sourceID,
                                   SoundParamBlockPtr pb, long actions);

    /** selectors for component calls */
    enum
    {
      kSoundComponentInitOutputDeviceSelect = 0x0001,
      kSoundComponentSetSourceSelect = 0x0002,
      kSoundComponentGetSourceSelect = 0x0003,
      kSoundComponentGetSourceDataSelect = 0x0004,
      kSoundComponentSetOutputSelect = 0x0005,
      kSoundComponentAddSourceSelect = 0x0101,
      kSoundComponentRemoveSourceSelect = 0x0102,
      kSoundComponentGetInfoSelect = 0x0103,
      kSoundComponentSetInfoSelect = 0x0104,
      kSoundComponentStartSourceSelect = 0x0105,
      kSoundComponentStopSourceSelect = 0x0106,
      kSoundComponentPauseSourceSelect = 0x0107,
      kSoundComponentPlaySourceBufferSelect = 0x0108
    };
/**Audio Components*/
/**Volume is described as a value between 0 and 1, with 0 indicating minimum
  volume and 1 indicating maximum volume; if the device doesn't support
  software control of volume, then a value of unimpErr is returned, indicating
  that these functions are not supported by the device
*/
#if CALL_NOT_IN_CARBON
    /**
     *  AudioGetVolume()
     *

     *    \non_carbon_cfm   in SoundLib 3.0 and later
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    ComponentResult
    AudioGetVolume(ComponentInstance ac, short whichChannel, ShortFixed *volume);

    /**
     *  AudioSetVolume()
     *

     *    \non_carbon_cfm   in SoundLib 3.0 and later
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    ComponentResult
    AudioSetVolume(ComponentInstance ac, short whichChannel, ShortFixed volume);

    /**If the device doesn't support software control of mute, then a value of
    unimpErr is returned, indicating that these functions are not supported by the
    device.*/
    /**
     *  AudioGetMute()
     *

     *    \non_carbon_cfm   in SoundLib 3.0 and later
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    ComponentResult
    AudioGetMute(ComponentInstance ac, short whichChannel, short *mute);

    /**
     *  AudioSetMute()
     *

     *    \non_carbon_cfm   in SoundLib 3.0 and later
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    ComponentResult
    AudioSetMute(ComponentInstance ac, short whichChannel, short mute);

    /**AudioSetToDefaults causes the associated device to reset its volume and mute
    values (and perhaps other characteristics, e.g. attenuation) to "factory
    default" settings*/
    /**
     *  AudioSetToDefaults()
     *

     *    \non_carbon_cfm   in SoundLib 3.0 and later
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    ComponentResult
    AudioSetToDefaults(ComponentInstance ac);

    /**This routine is required; it must be implemented by all audio components*/

    /**
     *  AudioGetInfo()
     *

     *    \non_carbon_cfm   in SoundLib 3.0 and later
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    ComponentResult
    AudioGetInfo(ComponentInstance ac, AudioInfoPtr info);

    /**
     *  AudioGetBass()
     *

     *    \non_carbon_cfm   in SoundLib 3.0 and later
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    ComponentResult
    AudioGetBass(ComponentInstance ac, short whichChannel, short *bass);

    /**
     *  AudioSetBass()
     *

     *    \non_carbon_cfm   in SoundLib 3.0 and later
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    ComponentResult
    AudioSetBass(ComponentInstance ac, short whichChannel, short bass);

    /**
     *  AudioGetTreble()
     *

     *    \non_carbon_cfm   in SoundLib 3.0 and later
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    ComponentResult
    AudioGetTreble(ComponentInstance ac, short whichChannel, short *Treble);

    /**
     *  AudioSetTreble()
     *

     *    \non_carbon_cfm   in SoundLib 3.0 and later
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    ComponentResult
    AudioSetTreble(ComponentInstance ac, short whichChannel, short Treble);

    /**
     *  AudioGetOutputDevice()
     *

     *    \non_carbon_cfm   in SoundLib 3.0 and later
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    ComponentResult
    AudioGetOutputDevice(ComponentInstance ac, Component *outputDevice);

    /**This is routine is private to the AudioVision component.  It enables the
     * watching of the mute key.*/
    /**
     *  AudioMuteOnEvent()
     *

     *    \non_carbon_cfm   in SoundLib 3.0 and later
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    ComponentResult
    AudioMuteOnEvent(ComponentInstance ac, short muteOnEvent);

    /** selectors for component calls */
    enum
    {
      kAudioGetVolumeSelect = 0x0000,
      kAudioSetVolumeSelect = 0x0001,
      kAudioGetMuteSelect = 0x0002,
      kAudioSetMuteSelect = 0x0003,
      kAudioSetToDefaultsSelect = 0x0004,
      kAudioGetInfoSelect = 0x0005,
      kAudioGetBassSelect = 0x0006,
      kAudioSetBassSelect = 0x0007,
      kAudioGetTrebleSelect = 0x0008,
      kAudioSetTrebleSelect = 0x0009,
      kAudioGetOutputDeviceSelect = 0x000A,
      kAudioMuteOnEventSelect = 0x0081
    };
#endif /** CALL_NOT_IN_CARBON */

    enum
    {
      kDelegatedSoundComponentSelectors = 0x0100
    };

    /** Sound Input Manager routines, uses _SoundDispatch */

    /**
    \brief Determine the version of the sound input routines

    <pre>You can use SPBVersion to determine the version of the sound input
routines available on a machine.
Returns: a version number that contains the same information as in the
first 4 bytes of a 'vers' resource.
</pre>
* \note <pre>You can call SPBVersion at interrupt time.
You can obtain information about a sound channel and about the
Sound Manager itself by calling the SndControl , SndChannelStatus ,
and SndManagerStatus functions. You can obtain the version numbers of
the Sound Manager , the MACE tools, and the sound input routines by
calling the SndSoundManagerVersion , MACEVersion , and
SPBVersion functions, respectively.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
    NumVersion
    SPBVersion(void);

    /**
     *  SndRecord()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    SndRecord(ModalFilterUPP filterProc, Point corner, OSType quality,
              SndListHandle *sndHandle);

#if CALL_NOT_IN_CARBON
    /**
     *  SndRecordToFile()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    OSErr
    SndRecordToFile(ModalFilterUPP filterProc, Point corner, OSType quality,
                    short fRefNum);

#endif /** CALL_NOT_IN_CARBON */

    /**
     *  SPBSignInDevice()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    SPBSignInDevice(short deviceRefNum, ConstStr255Param deviceName);

    /**
     *  SPBSignOutDevice()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    SPBSignOutDevice(short deviceRefNum);

    /**
     *  SPBGetIndexedDevice()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    SPBGetIndexedDevice(short count, Str255 deviceName, Handle *deviceIconHandle);

    /**
     *  SPBOpenDevice()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    SPBOpenDevice(ConstStr255Param deviceName, short permission, long *inRefNum);

    /**
     *  SPBCloseDevice()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    SPBCloseDevice(long inRefNum);

    /**
     *  SPBRecord()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    SPBRecord(SPBPtr inParamPtr, Boolean asynchFlag);

#if CALL_NOT_IN_CARBON
    /**
     *  SPBRecordToFile()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    OSErr
    SPBRecordToFile(short fRefNum, SPBPtr inParamPtr, Boolean asynchFlag);

#endif /** CALL_NOT_IN_CARBON */

    /**
    \brief SPBPauseRecording Pause recording from the specified device

    <pre>The SPBPauseRecording function pauses recording from the device
specified by the inRefNum parameter. The recording must be asynchronous for
this call to have any effect
inRefNum must contain a valid reference number for an input device
Returns: an operating system Error Code .
noErr(0)No error
siBadSoundInDevice (-221)Invalid sound input device
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
    OSErr
    SPBPauseRecording(long inRefNum);

    /**
    \brief SPBResumeRecording Resume recording from the specified device

    <pre>The SPBResumeRecording function resumes recording from the device
specified by the inRefNum parameter. The recording must be asynchronous for
this call to have any effect.
inRefNum must contain a valid reference number for an input device
Returns: an operating system Error Code .
noErr(0)No error
siBadSoundInDevice (-221)Invalid sound input device
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
    OSErr
    SPBResumeRecording(long inRefNum);

    /**
    \brief SPBStopRecording Resume recording from the specified device

    <pre>The SPBStopRecording function stops recording from the device specified
by the inRefNum parameter. The recording must be asynchronous for this call
to have any effect. When you call SPBStopRecording , the completion routine
specified in the completionRoutine field of the sound input parameter block ,
SPB, is called and the error field of that parameter block is set to abortErr .
inRefNum must contain a valid reference number for an input device
Returns: an operating system Error Code .
noErr(0)No error
siBadSoundInDevice (-221)Invalid sound input device
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
    OSErr
    SPBStopRecording(long inRefNum);

    /**
    \brief SPBGetRecordingStatus Obtain recording status information

    <pre>You can use SPBGetRecordingStatus to obtain recording status
information about a sound input device.
inRefNum the reference number of a sound input device
recordingStatus While the input device is recording, recordingStatus is
greater than 0. When the recording terminates without an
error, recordingStatus is equal to 0. If any error occurs
during the recording, recordingStatus is less than 0 and
contains an error code. If the recording is terminated by
calling SPBStopRecording , then recordingStatus
contains the abortErr result code.
meterLevel gives the current input signal level. Values returned are
in the range 0 to 255.
totalSamplesToRecord gives an indication of the total to record.
numberOfSamplesRecorded gives an indication of how many samples have been
recorded out of the total to record.
totalMsecsToRecord gives an indication of the total time to record
numberOfMsecsRecorded gives an indication of how much time has been recorded
out of the total to record
Returns: an operating system Error Code .
noErr(0)No error
siBadSoundInDevice (-221)Invalid sound input device
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
    OSErr
    SPBGetRecordingStatus(long inRefNum, short *recordingStatus, short *meterLevel,
                          unsigned long *totalSamplesToRecord,
                          unsigned long *numberOfSamplesRecorded,
                          unsigned long *totalMsecsToRecord,
                          unsigned long *numberOfMsecsRecorded);

    /**
     *  SPBGetDeviceInfo()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    SPBGetDeviceInfo(long inRefNum, OSType infoType, void *infoData);

    /**
     *  SPBSetDeviceInfo()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    SPBSetDeviceInfo(long inRefNum, OSType infoType, void *infoData);

    /**
     *  SPBMillisecondsToBytes()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    SPBMillisecondsToBytes(long inRefNum, long *milliseconds);

    /**
     *  SPBBytesToMilliseconds()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    SPBBytesToMilliseconds(long inRefNum, long *byteCount);

    /**
    \brief Set up headers for 'snd ' resources

    <pre>You can use SetupSndHeader to construct a sampled sound header that can
be passed to SndPlay or stored as an 'snd ' resource. SetupSndHeader
creates a format 1 'snd ' resource header for a sampled sound only, containing
one synthesizer field (the sampled synthesizer) and one sound command (a
bufferCmd command to play the accompanying data). A sampled sound header
is stored immediately following the sound command and is in one of three
formats depending on several of the parameters passed. The Table below shows
how SetupSndHeader determines what kind of sound header to create
sndHandle is a handle that is at least large enough to store the 'snd ' header
information. The handle is not resized in any way upon successful
completion of SetupSndHeader . SetupSndHeader simply fills the
beginning of the handle with the header information needed for a
format 1 'snd ' resource. It is your application's responsibility to
append the desired sampled sound data.
numChannels specifies the number of channels for the sound .
sampleRate specifies the sampling rate for the sound (that is, samples per
second). Note that the most significant bit of this value is interpreted
as having the value 32,768 (not as a sign bit)
sampleSize specifies the sample size for the sound (that is, bits per sample)
compressionType specifies the compression type for the sound ('NONE', 'MAC3',
'MAC6', or other third-party types)
baseFrequency specifies the base frequency for the sound
numBytes specifies the number of bytes of audio data that are to be stored in
the handle. (This value is not necessarily the same as the number of
samples in the sound.)
headerLen returns the size of the 'snd ' resource header that is created, in
bytes. This allows you to put the audio data right after the header in
the handle. The value returned depends on the type of sound header
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
    OSErr
    SetupSndHeader(SndListHandle sndHandle, short numChannels,
                   UnsignedFixed sampleRate, short sampleSize,
                   OSType compressionType, short baseNote, unsigned long numBytes,
                   short *headerLen);

    /**
    \brief Set up a file that can be played by SndStartFilePlay

    <pre>Depending on the parameters passed, SetupAIFFHeader creates an AIFF or
AIFF-C file header:
•Uncompressed sounds of any type are stored in AIFF format (that is,
compressionType is 'NONE').
•Compressed sounds of any type are stored in AIFF-C format (that is,
compressionType is different from 'NONE').
fRefNum contains a file reference number for a file that is open for
writing.The AIFF header information is written starting at the
current file position, and the file position is left at the end of the
header upon completion.
numChannels specifies the number of channels for the sound .
sampleRate specifies the sampling rate for the sound (that is, samples per
second). Note that the most significant bit of this value is interpreted
as having the value 32,768 (not as a sign bit)
sampleSize specifies the sample size for the sound (that is, bits per sample)
compressionType specifies the compression type for the sound ('NONE', 'MAC3',
'MAC6', or other third-party types)
baseFrequency specifies the base frequency for the sound
numBytes specifies the number of bytes of audio data that are to be stored in
the Common Chunk of the AIFF or AIFF-C file. This data should be
stored right after the sound header in the file. (This value is not
necessarily the same as the number of samples in the sound.)
numFrames specifies the number of sample frames for the sound. A value needs
to be passed here only for third-party compression types. If you are
using 'NONE', 'MAC3', or 'MAC6' compression types, you can pass a 0
in this field, and SetupAIFFHeader will calculate the number of
sample frames and store it in the header..
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
    OSErr
    SetupAIFFHeader(short fRefNum, short numChannels, UnsignedFixed sampleRate,
                    short sampleSize, OSType compressionType,
                    unsigned long numBytes, unsigned long numFrames);

    /** Sound Input Manager 1.1 and later calls, uses _SoundDispatch */
    /**
     *  ParseAIFFHeader()
     *

     *    \non_carbon_cfm   in SoundLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    ParseAIFFHeader(short fRefNum, SoundComponentData *sndInfo,
                    unsigned long *numFrames, unsigned long *dataOffset);

    /**
     *  ParseSndHeader()
     *

     *    \non_carbon_cfm   in SoundLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    ParseSndHeader(SndListHandle sndHandle, SoundComponentData *sndInfo,
                   unsigned long *numFrames, unsigned long *dataOffset);

#if !TARGET_OS_MAC || TARGET_API_MAC_CARBON
    /**  Only to be used if you are writing a sound input component; this */
    /**  is the param block for a read request from the SoundMgr to the   */
    /**  sound input component.  Not to be confused with the SPB struct   */
    /**  above, which is the param block for a read request from an app   */
    /**  to the SoundMgr.                                                 */
    typedef struct SndInputCmpParam SndInputCmpParam;
    typedef SndInputCmpParam *SndInputCmpParamPtr;
    typedef CALLBACK_API(void,
                         SICCompletionProcPtr)(SndInputCmpParamPtr SICParmPtr);
    struct SndInputCmpParam
    {
      SICCompletionProcPtr ioCompletion; /** completion routine [pointer]*/
      SIInterruptProcPtr ioInterrupt;    /** interrupt routine [pointer]*/
      OSErr ioResult;                    /** I/O result code [word]*/
      short pad;
      unsigned long ioReqCount;
      unsigned long ioActCount;
      Ptr ioBuffer;
      Ptr ioMisc;
    };

    /**
     *  SndInputReadAsync()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         in version 10.0 and later
     */
    ComponentResult
    SndInputReadAsync(ComponentInstance self, SndInputCmpParamPtr SICParmPtr);

    /**
     *  SndInputReadSync()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         in version 10.0 and later
     */
    ComponentResult
    SndInputReadSync(ComponentInstance self, SndInputCmpParamPtr SICParmPtr);

    /**
     *  SndInputPauseRecording()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         in version 10.0 and later
     */
    ComponentResult
    SndInputPauseRecording(ComponentInstance self);

    /**
     *  SndInputResumeRecording()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         in version 10.0 and later
     */
    ComponentResult
    SndInputResumeRecording(ComponentInstance self);

    /**
     *  SndInputStopRecording()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         in version 10.0 and later
     */
    ComponentResult
    SndInputStopRecording(ComponentInstance self);

    /**
     *  SndInputGetStatus()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         in version 10.0 and later
     */
    ComponentResult
    SndInputGetStatus(ComponentInstance self, short *recordingStatus,
                      unsigned long *totalSamplesToRecord,
                      unsigned long *numberOfSamplesRecorded);

    /**
     *  SndInputGetDeviceInfo()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         in version 10.0 and later
     */
    ComponentResult
    SndInputGetDeviceInfo(ComponentInstance self, OSType infoType, void *infoData);

    /**
     *  SndInputSetDeviceInfo()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         in version 10.0 and later
     */
    ComponentResult
    SndInputSetDeviceInfo(ComponentInstance self, OSType infoType, void *infoData);

    /**
     *  SndInputInitHardware()
     *

     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         in version 10.0 and later
     */
    ComponentResult
    SndInputInitHardware(ComponentInstance self);

    /** selectors for component calls */
    enum
    {
      kSndInputReadAsyncSelect = 0x0001,
      kSndInputReadSyncSelect = 0x0002,
      kSndInputPauseRecordingSelect = 0x0003,
      kSndInputResumeRecordingSelect = 0x0004,
      kSndInputStopRecordingSelect = 0x0005,
      kSndInputGetStatusSelect = 0x0006,
      kSndInputGetDeviceInfoSelect = 0x0007,
      kSndInputSetDeviceInfoSelect = 0x0008,
      kSndInputInitHardwareSelect = 0x0009
    };
#endif /** !TARGET_OS_MAC || TARGET_API_MAC_CARBON */

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

#endif /** __SOUND__ */