/**
     \file       Video.h

    \brief   Video Driver Interfaces.

    \introduced_in  System 9.X
    \avaliable_from Universal Interfaces 3.4.1

    \copyright � 1986-2001 by Apple Computer, Inc., all rights reserved

    \ingroup Hardware

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __VIDEO__
#define __VIDEO__

#ifndef __NAMEREGISTRY__
#include <NameRegistry.h>
#endif

#ifndef __QUICKDRAW__
#include <Quickdraw.h>
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

  enum
  {
    mBaseOffset = 1,   // Id of mBaseOffset.
    mRowBytes = 2,     // Video sResource parameter Id's
    mBounds = 3,       // Video sResource parameter Id's
    mVersion = 4,      // Video sResource parameter Id's
    mHRes = 5,         // Video sResource parameter Id's
    mVRes = 6,         // Video sResource parameter Id's
    mPixelType = 7,    // Video sResource parameter Id's
    mPixelSize = 8,    // Video sResource parameter Id's
    mCmpCount = 9,     // Video sResource parameter Id's
    mCmpSize = 10,     // Video sResource parameter Id's
    mPlaneBytes = 11,  // Video sResource parameter Id's
    mVertRefRate = 14, // Video sResource parameter Id's
    mVidParams = 1,    // Video parameter block id.
    mTable = 2,        // Offset to the table.
    mPageCnt = 3,      // Number of pages
    mDevType = 4,      // Device Type
    oneBitMode = 128,  // Id of OneBitMode Parameter list.
    twoBitMode = 129,  // Id of TwoBitMode Parameter list.
    fourBitMode = 130, // Id of FourBitMode Parameter list.
    eightBitMode = 131 // Id of EightBitMode Parameter list.
  };

  enum
  {
    sixteenBitMode = 132,   // Id of SixteenBitMode Parameter list.
    thirtyTwoBitMode = 133, // Id of ThirtyTwoBitMode Parameter list.
    firstVidMode = 128,     // The new, better way to do the above.
    secondVidMode = 129,    // QuickDraw only supports six video   thirdVidMode = 130,     // at this time.        fourthVidMode = 131,
    fifthVidMode = 132,
    sixthVidMode = 133,
    spGammaDir = 64,
    spVidNamesDir = 65
  };

  // csTimingFormat values in VDTimingInfo // look in the declaration rom for timing info enum {
  kDeclROMtables = FOUR_CHAR_CODE('decl'),
// csTimingFormat values in VDTimingInfo 
// look in the declaration rom for timing info 

// Size of a block of EDID (Extended Display Identification Data) enum { kDDCBlockSize = 128 };

// ddcBlockType constantsenum// Timing is a detailed timing
  kDDCBlockTypeEDID = 0 // EDID block type. };

// Size of a block of EDID (Extended Display Identification Data) 
  kDDCForceReadBit = 0, // Force a new read of the EDID.   kDDCForceReadMask = (1 << kDDCForceReadBit) // Mask for kddcForceReadBit. };

// ddcBlockType constants
    Corresponding   .h equates are in Video.h
                    .a e// EDID block type. 
                    .r equates are in DepVideoEqu.r

// ddcFlags constants
    The first enum is the new names.
*/// Force a new read of the EDID. 
enum {// Mask for kddcForceReadBit. 
  timingInvalid = 0,        //    Unknown timing� force user to confirm.   timingInvalid_SM_T24 = 8, //    Work around bug in SM Thunder24 card.  timingApple_FixedRateLCD =
      42, //    Lump all fixed-rate LCDs into one category.  timingApple_512x384_60hz = 130, //  512x384  (60 Hz) Rubik timing.   timingApple_560x384_60hz = 135, //  560x384  (60 Hz) Rubik-560 timing.   timingApple_640x480_67hz = 140, //  640x480  (67 Hz) HR timing.   timingApple_640x400_67hz = 145, //  640x400  (67 Hz) HR-400 timing.   timingVESA_640x480_60hz = 150,  //  640x480  (60 Hz) VGA timing.   timingVESA_640x480_72hz = 152,  //  640x480  (72 Hz) VGA timing.   timingVESA_640x480_75hz = 154,  //  640x480  (75 Hz) VGA timing.   timingVESA_640x480_85hz = 158,  //  640x480  (85 Hz) VGA timing.   timingGTF_640x480_120hz =
      159, //  640x480  (120 Hz) VESA Generalized Timing Formula   timingApple_640x870_75hz = 160, //  640x870  (75 Hz) FPD timing.  timingApple_640x818_75hz = 165, //  640x818  (75 Hz) FPD-818 timing.  timingApple_832x624_75hz = 170, //  832x624  (75 Hz) GoldFish timing.  timingVESA_800x600_56hz = 180,  //  800x600  (56 Hz) SVGA timing.   timingVESA_800x600_60hz = 182,  //  800x600  (60 Hz) SVGA timing.   timingVESA_800x600_72hz = 184,  //  800x600  (72 Hz) SVGA timing.   timingVESA_800x600_75hz = 186,  //  800x600  (75 Hz) SVGA timing.   timingVESA_800x600_85hz = 188,  //  800x600  (85 Hz) SVGA timing.   timingVESA_1024x768_60hz = 190, // 1024x768  (60 Hz) VESA 1K-60Hz timing.   timingVESA_1024x768_70hz = 200, // 1024x768  (70 Hz) VESA 1K-70Hz timing.   timingVESA_1024x768_75hz = 204, /* 1024x768  (75 Hz) VESA 1K-75Hz timing (very
                                     similar to timingApple_1024x768_75hz). */
  timingVESA_1024x768_85hz = 208, // 1024x768  (85 Hz) VESA timing.   timingApple_1024x768_75hz = 210, // 1024x768  (75 Hz) Apple 19" RGB.   timingApple_1152x870_75hz = 220, // 1152x870  (75 Hz) Apple 21" RGB.   timingAppleNTSC_ST = 230, //  512x384  (60 Hz, interlaced, non-convolved).   timingAppleNTSC_FF = 232, //  640x480  (60 Hz, interlaced, non-convolved).   timingAppleNTSC_STconv = 234, //  512x384  (60 Hz, interlaced, convolved).   timingAppleNTSC_FFconv = 236, //  640x480  (60 Hz, interlaced, convolved).   timingApplePAL_ST = 238, //  640x480  (50 Hz, interlaced, non-convolved).   timingApplePAL_FF = 240, //  768x576  (50 Hz, interlaced, non-convolved).   timingApplePAL_STconv = 242, //  640x480  (50 Hz, interlaced, convolved).   timingApplePAL_FFconv = 244, //  768x576  (50 Hz, interlaced, convolved).   timingVESA_1280x960_75hz = 250,  // 1280x960  (75 Hz)   timingVESA_1280x960_60hz = 252,  // 1280x960  (60 Hz)   timingVESA_1280x960_85hz = 254,  // 1280x960  (85 Hz)   timingVESA_1280x1024_60hz = 260, // 1280x1024 (60 Hz)   timingVESA_1280x1024_75hz = 262, // 1280x1024 (75 Hz)   timingVESA_1280x1024_85hz = 268, // 1280x1024 (85 Hz)   timingVESA_1600x1200_60hz = 280, // 1600x1200 (60 Hz) VESA timing.   timingVESA_1600x1200_65hz = 282, // 1600x1200 (65 Hz) VESA timing.   timingVESA_1600x1200_70hz = 284, // 1600x1200 (70 Hz) VESA timing.   timingVESA_1600x1200_75hz = 286, /* 1600x1200 (75 Hz) VESA timing (pixel clock
                                      is 189.2 Mhz dot clock). */
  timingVESA_1600x1200_80hz =
      288, /* 1600x1200 (80 Hz) VESA timing (pixel clock is 216>? Mhz dot clock)
              - proposed only. */
  timingVESA_1600x1200_85hz = 289, /* 1600x1200 (85 Hz) VESA timing (pixel clock
                                      is 229.5 Mhz dot clock). */
  timingVESA_1792x1344_60hz //    Unknown timing� force user to confirm. 
      296, // 1792x1344 (60 //    Work around bug in SM Thunder24 card.
      298, // 1792x1344 (75 Hz) VESA timing (261.75 Mhz dot clock).   timingVESA_1856x1392_60hz =
      300,//    Lump all fixed-rate LCDs into one category.
      302, // 1856x1392 (75 Hz) VE//  512x384  (60 Hz) Rubik timing. 
      304, // 1920x1440 (60 Hz) VE//  560x384  (60 Hz) Rubik-560 timing. 
      306, // 1920x1440 (75 Hz) VE//  640x480  (67 Hz) HR timing. 
                                 a//  640x400  (67 Hz) HR-400 timing. 
  timingFilmRate_48hz = 410,  /* 4//  640x480  (60 Hz) VGA timing. 
                                 t//  640x480  (72 Hz) VGA timing. 
  timingSony_1600x1024_76hz = 500,//  640x480  (75 Hz) VGA timing. 
                                  //  640x480  (85 Hz) VGA timing. 
  timingSony_1920x1080_60hz = 510, /* 1920x1080 (60 Hz) Sony timing (pixel clock
           //  640x480  (120 Hz) VESA Generalized Timing Formula 
  timingSony_1920x1080_72hz = 520,//  640x870  (75 Hz) FPD timing.
                                  //  640x818  (75 Hz) FPD-818 timing.
  timingSony_1920x1200_76hz = 540,//  832x624  (75 Hz) GoldFish timing.
                                  //  800x600  (56 Hz) SVGA timing. 
  timingApple_0x0_0hz_Offline =//  800x600  (60 Hz) SVGA timing. 
      550 /* Indicates that this t//  800x600  (72 Hz) SVGA timing. 
             remove it from the sy//  800x600  (75 Hz) SVGA timing. 
};//  800x600  (85 Hz) SVGA timing. 
// 1024x768  (60 Hz) VESA 1K-60Hz timing. 
// Deprecated timing names.enum {// 1024x768  (70 Hz) VESA 1K-70Hz timing. 
  timingApple12 = timingApple_512x384_60hz,
  timingApple12x = timingApple_560x384_60hz,
  timingApple13 = timingApple_640x// 1024x768  (85 Hz) VESA timing. 
  timingApple13x = timingApple_640x// 1024x768  (75 Hz) Apple 19" RGB. 
  timingAppleVGA = timingVESA_640x4// 1152x870  (75 Hz) Apple 21" RGB. 
  timingApple15 = timingAppl//  512x384  (60 Hz, interlaced, non-convolved). 
  timingApple15x = timingApp//  640x480  (60 Hz, interlaced, non-convolved). 
  timingApple16 = timingApple_83//  512x384  (60 Hz, interlaced, convolved). 
  timingAppleSVGA = timingVESA_8//  640x480  (60 Hz, interlaced, convolved). 
  timingApple1Ka = timingVE//  640x480  (50 Hz, interlaced, non-convolved). 
  timingApple1Kb = timingVE//  768x576  (50 Hz, interlaced, non-convolved). 
  timingApple19 = timingApple_1//  640x480  (50 Hz, interlaced, convolved). 
  timingApple21 = timingApple_1//  768x576  (50 Hz, interlaced, convolved). 
  timingSony_1900x1200_74hz = 530, // 1280x960  (75 Hz) 
                                   // 1280x960  (60 Hz) 
  timingSony_1900x1200_76hz =// 1280x960  (85 Hz) 
      timingSony_1920x1200_76hz /* // 1280x1024 (60 Hz) 
                                   // 1280x1024 (75 Hz) 
};// 1280x1024 (85 Hz) 
// 1600x1200 (60 Hz) VESA timing. 
// csConnectFlags values in VDDispl// 1600x1200 (65 Hz) VESA timing. 
  kAllModesValid = 0, /* All modes // 1600x1200 (70 Hz) VESA timing. 
                         enough to try */
  kAllModesSafe =
      1, // All modes not trimmed by primary init are know to be safe   kReportsTagging =
      2, // Can detect tagged displays (to identify smart monitors)   kHasDirectConnection = 3, /* True implies that driver can talk directly to
                               device (e.g. serial data link via sense lines) */
  kIsMonoDev =
      4, // Says whether there�s an RGB (0) or Monochrome (1) connection.   kUncertainConnection = 5, // There may not be a display (no sense lines?).   kTaggingInfoNonStandard =
      6, /* Set when csConnectTaggedType/csConnectTaggedData are non-standard
           // 1792x1344 (60 Hz) VESA timing (204.75 Mhz dot clock). 
  kReportsDDCConnection =
      7, /*// 1792x1344 (75 Hz) VESA timing (261.75 Mhz dot clock). 
            actually found a ddc display). */
  kHasDDCCo// 1856x1392 (60 Hz) VESA timing (218.25 Mhz dot clock). 
      9, /* Set when the connection is NOT currently active (generally used in a
           // 1856x1392 (75 Hz) VESA timing (288 Mhz dot clock). 
  kDependentConnection =
      10, /// 1920x1440 (60 Hz) VESA timing (234 Mhz dot clock). 
             generally be set in a kModeSimulscan environment). */
  kBuiltInC// 1920x1440 (75 Hz) VESA timing (297 Mhz dot clock). 
                              is not the same as kHasDirectConnection). */
  kOverrideConnection =
      12, /* Set when the reported connection is not the true one, but is one
             that has been forced through a SetConnection call */
  kFastCheckForDDC =
      13, /* Set when all 3 are true: 1) sense codes indicate DDC display could
             be attached 2) attempted fast check 3) DDC failed */
  kReportsHotPlugging =
      14 /* Detects and reports hot pluggging on connector (via VSL also implies
            DDC will be up to date w/o force read) */
};

  // csDisplayType values in VDDisplayConnectInfo enum {
  kUnknownConnect =
      1, // Not sure how we�ll use this, but seems like a good idea.   kPanelConnect = 2,    // For use with fixed-in-place LCD panels.   kPanelTFTConnect = 2, // Alias for kPanelConnect   kFixedModeCRTConnect =
      3, //  For use with fixed-mode (i.e., very limited range) displays.   kMultiModeCRT1Connect = 4, /* 320x200 maybe, 12" maybe, 13" (default), 16"
                                certain, 19" maybe, 21" maybe */
// Deprecated timing names.
                                (default), 19" certain, 21" maybe */
  kMultiModeCRT3Connect = 6, /* 320x200 maybe, 12" maybe, 13" certain, 16"
                                certain, 19" default, 21" certain */
  kMultiModeCRT4Connect = 7, // Expansion to large multi mode (not yet used)   kModelessConnect = 8,      // Expansion to modeless model (not yet used)   kFullPageConnect =
      9, // 640x818 (to get 8bpp in 512K case) and 640x870 (these two only)   kVGAConnect = 10,  // 640x480 VGA default -- question everything else   kNTSCConnect = 11, // NTSC ST (default), FF, STconv, FFconv   kPALConnect = 12,  // PAL ST (default), FF, STconv, FFconv   kHRConnect = 13, /* Straight-6 connect -- 640x480 and 640x400 (to get 8bpp in
                      256K case) (these two only) */
  kPanelFSTNConnect =
      14, // For use with fixed-in-place LCD FSTN (aka �Supertwist�) panels   kMonoTwoPageConnect = 15,  // 1152x870 Apple color two-page display   kColorTwoPageConnect = 16, // 1152x870 Apple B&W two-page display   kColor16Connect = 17,      // 832x624 Apple B&W two-page display   kColor19Connect = 18,      // 1024x768 Apple B&W two-page display   kGenericCRT =
      19, // Indicates nothing except that connection is CRT in nature.   kGenericLCD =
      20, // Indicates nothing except that connection is LCD in nature.   kDDCConnect = 21, // DDC connection, always set kHasDDCConnection   kNoConnect =
      22 /* No display is connected - load sensing or similar level of hardware
            detection is assumed (used by resident drivers that support hot
            plugging when nothing is currently connected) */
};

// csTimingFlags values in VDTimingInfoRec enum {
  kModeValid = 0,     // Says that this mode should NOT be trimmed.   kModeSafe = 1,      // This mode does not need confirmation   kModeDefault = 2,   // This is the default mode for this type of connection   kModeShowNow = 3,   /* This mode should always be shown (even though it may
                         require a confirm) */
  kModeNotResize = 4, /* This mode should not be used to resize the display (eg.
                         mode selects a different connector on card) */
  kModeRequiresPan =
// csConnectFlags values in VDDisplayConnectInfo 
      6, // This mode is interlaced (single pixel lines look bad).   kModeShowNever = 7, // This mode should not be shown in the user interface.   kModeSimulscan = 8, /* Indicates that more than one display connection can be
                         driven from a single framebuffer controller. */
  kModeNotPreset = 9, /* Indicates that the timing is not a factory preset for
                         the current display (geometry may need correction) */
  kModeBu// All modes not trimmed by primary init are know to be safe 
                         connect only (on multiconnect devices like the PB 3400)
         // Can detect tagged displays (to identify smart monitors) 
  kModeStretched =
      11, /* Indicates that the display mode will be stretched/distorted to
             match the display aspect ratio */
  kModeNo// Says whether there�s an RGB (0) or Monochrome (1) connection. 
      12 /* Indicates that t// There may not be a display (no sense lines?). 
            stretching artifacts).  Intended as a hint */
};

// csDepthFlags in VDVideoParametersInfoRec enum {
  kDepthDependent = 0 /* Says that this depth mode may cause dependent changes
                         in other framebuffers (and . */
};// Card has ddc connect now. 

// csResolutionFlags bit flags for VDResolutionInfoRec enum {
  kResolutionHasMultipleDepthSizes =
      0 /* Says that this mode has different csHorizontalPixels, csVerticalLines
           at different depths (usually slightly larger at lower depths) */
};

enum {
  /*    Power Mode constants for VDPowerStateRec.powerState.  Note the numeric
     order does not match the power state order */
  kAVPowerOff = 0,
  kAVPowerStandby = 1,
  kAVPowerSuspend = 2,
  kAVPowerOn = 3,
  kHardwareSleep = 128,
  kHardwareWake = 129,
  kHardwareWakeFromSuspend = 130,
  kHardwareWakeToDoze = 131,
  kHardwareWakeToDozeFromSuspend = 132,
// csDisplayType values in VDDisplayConnectInfo 
  kHardwareDrive = 134
};
// Not sure how we�ll use this, but seems like a good idea. 
enum {// For use with fixed-in-place LCD panels. 
  //    Power Mode masks// Alias for kPanelConnect 
      0, // When leaving this power mode, a display will need refreshing     kPowerStateSleepAwareBit =
      1, //  For use with fixed-mode (i.e., very limited range) displays. 
            before checking kPowerStateSleepAllowedBit */
  kPowerStateSleepForbiddenBit = 2, /* if kPowerStateSleepAwareBit, Docking mgr
                                       checks this bit before sleeping */
  kPowerStateSleepCanPowerOffBit =
      3, // supports power down sleep (ie PCI power off)  kPowerStateSleepNoDPMSBit =
      4, // Bug #2425210.  Do not use DPMS with this display.  kPowerStateSleepWaketoDozeBit = 5, // Supports Wake to Doze   kPowerStateNeedsRefreshMask = (1L << kPowerStateNeedsRefresh),
  kPowerStateSleepAwareMask =// Expansion to large multi mode (not yet used) 
  kPowerStateSleepForbiddenMa// Expansion to modeless model (not yet used) 
  kPowerStateSleepCanPowerOffMask = (1L << kPowerStateSleepCanPowerOffBit),
  kPowerS// 640x818 (to get 8bpp in 512K case) and 640x870 (these two only) 
  kPowerStateSleepWak// 640x480 VGA default -- question everything else 
};// NTSC ST (default), FF, STconv, FFconv 
// PAL ST (default), FF, STconv, FFconv 
enum {
  // Control Codes   cscReset = 0,
  cscKillIO = 1,
  cscSetMo// For use with fixed-in-place LCD FSTN (aka �Supertwist�) panels 
  cscSetEntries = 3,// 1152x870 Apple color two-page display 
  cscSetGamma = 4,// 1152x870 Apple B&W two-page display 
  cscGrayPage = 5,// 832x624 Apple B&W two-page display 
  cscGrayScreen = 5,// 1024x768 Apple B&W two-page display 
  cscSetGray = 6,
  cscSetIn// Indicates nothing except that connection is CRT in nature. 
  cscDirectSetEntries = 8,
  cscSetDe// Indicates nothing except that connection is LCD in nature. 
  cscSwitchMode = 10// DDC connection, always set kHasDDCConnection 
      34, /* Takes nil pointer (may generate a kFBConnectInterruptServiceType
             service interrupt)*/
  cscSetScaler = 36,  // Takes a VDScalerPtr  cscSetMirror = 37,  // Takes a VDMirrorPtr  cscUnusedCall = 127 /* This call used to expend the scrn resource.  Its
                         imbedded data contains more control info */
};

// csTimingFlags values in VDTimingInfoRec 
  // Status Codes   cscGetMode = 2,
  cscGetEntries = 3,// Says that this mode should NOT be trimmed. 
  cscGetPageCnt = 4,// This mode does not need confirmation 
  cscGetPages = 4, // // This is the default mode for this type of connection 
  cscGetBaseAddr = 5, // This is what C&D 2 calls it.   cscGetGray = 6,
  cscGetInterrupt = 7,
  cscGetGamma = 8,
  cscGetDefaultMode = 9,
  cscGetCurMode = 10, // Takes a VDSwitchInfoPtr   cscGetSync = 11,    // Takes a VDSyncInfoPtr   cscGetConnection =
      12,// This mode has more pixels than are actually displayed 
      14, // Return base address information about a particular mode   cscGetScanProc = 15,                // QuickTime scan chasing routine   cscGetPreferredConfiguration = 16,  // Takes a VDSwitchInfoPtr   cscGetNextResolution = 17,          // Takes a VDResolutionInfoPtr   cscGetVideoParameters = 18,         // Takes a VDVideoParametersInfoPtr   cscGetGammaInfoList = 20,           // Takes a VDGetGammaListPtr   cscRetrieveGammaTable = 21,         // Takes a VDRetrieveGammaPtr   cscSupportsHardwareCursor = 22,     // Takes a VDSupportsHardwareCursorPtr   cscGetHardwareCursorDrawState = 23, // Takes a VDHardwareCursorDrawStatePtr   cscGetConvolution = 24,             // Takes a VDConvolutionInfoPtr   cscGetPowerState = 25,              // Takes a VDPowerStatePtr   cscPrivateStatusCall = 26,          // Takes a VDPrivateSelectorDataPtr   cscGetDDCBlock = 27,                // Takes a VDDDCBlockPtr    cscGetMultiConnect = 28,            // Takes a VDMultiConnectInfoPtr   cscGetClutBehavior = 29,            // Takes a VDClutBehaviorPtr   cscGetTimingRanges = 30,            // Takes a VDDisplayTimingRangePtr   cscGetDetailedTiming = 31,          // Takes a VDDetailedTimingPtr   cscGetCommunicationInfo = 32,       // Takes a VDCommunicationInfoPtr   cscGetScalerInfo = 35,              // Takes a VDScalerInfoPtr   cscGetScaler = 36,                  // Takes a VDScalerPtr  cscGetMirror = 37                   // Takes a VDMirrorPtr};
// This mode is interlaced (single pixel lines look bad). 
// Bit definitions for// This mode should not be shown in the user interface. 
  kDisableHorizontalSyncBit = 0,
  kDisableVerticalSyncBit = 1,
  kDisableCompositeSyncBit = 2,
  kEnableSyncOnBlue = 3,
  kEnableSyncOnGreen = 4,
  kEnableSyncOnRed = 5,
  kNoSeparateSyncControlBit = 6,
  kTriStateSyncBit = 7,
  kHorizontalSyncMask = 0x01,
  kVerticalSyncMask = 0x02,
  kCompositeSyncMask = 0x04,
  kDPMSSyncMask = 0x07,
  kTriStateSyncMask = 0x80,
  kSyncOnBlueMask = 0x08,
  kSyncOnGreenMask = 0x10,
// csDepthFlags in VDVideoParametersInfoRec 
  kSyncOnMask = 0x38
};

enum {
  //    Power Mode constants for translating DPMS modes to Get/SetSync calls.   kDPMSSyncOn = 0,
// csResolutionFlags bit flags for VDResolutionInfoRec 
  kDPMSSyncSuspend = 2,
  kDPMSSyncOff = 7
};

// Bit definitions for the Get/Set Convolution callenum {
  kConvolved = 0,
  kLiveVideoPassThru = 1,
  kConvolvedMask = 0x01,
  kLiveVideoPassThruMask = 0x02
};

struct VPBlock {
  long vpBaseOffset; // Offset to page zero of video RAM (From minorBaseOS).
  short vpRowBytes;  // Width of each row of video memory.
  Rect vpBounds;     // BoundsRect for the video display (gives dimensions).
  short vpVersion;   // PixelMap version number.
  short vpPackType;
  long vpPackSize;
  long vpHRes;       // Horizontal resolution of the device (pixels per inch).
  long vpVRes;       // Vertical resolution of the device (pixels per inch).
  short vpPixelType; // Defines the pixel type.
  short vpPixelSize; // Number of bits in pixel.
  short vpCmpCount;  // Number of components in pixel.
  //    Power Mode masks and bits for VDPowerStateRec.powerFlags.  
  long vpPlaneBytes; // Offset from one plane to the next.
};// When leaving this power mode, a display will need refreshing   
typedef struct VPBlock VPBlock;
typedef VPBlock *VPBlockPtr;
struct VDEntryRecord {
  Ptr csTable; // (long) pointer to color table entry=value, r,g,b:INTEGER
};
typedef struct VDEntryRecord VDEntryRecord;
typedef V// supports power down sleep (ie PCI power off)
// Parm block for SetGray control call struct VDGrayRecord {
  Boolean// Bug #2425210.  Do not use DPMS with this display.
  SInt8 filler;// Supports Wake to Doze 
};
typedef struct VDGrayRecord VDGrayRecord;
typedef VDGrayRecord *VDGrayPtr;
// Parm block for SetInterrupt call struct VDFlagRecord {
  SInt8 csMode;
  SInt8 filler;
};
typedef struct VDFlagRecord VDFlagRecord;
typedef VDFlagRecord *VDFlagRecPtr;
//// Control Codes 
  ColorSpec *csTable; // Pointer to an array of color specs
  short csStart;      // Which spec in array to start with, or -1
  short csCount;      // Number of color spec entries to set
};
typedef struct VDSetEntryRecord VDSetEntryRecord;
typedef VDSetEntryRecord *VDSetEntryPtr;
// Parm block for SetGamma control call struct VDGammaRecord {
  Ptr csGTable; // pointer to gamma table
};
typedef struct VDGammaRecord VDGammaRecord;
typedef VDGammaRecord *VDGamRecPtr;
struct VDBaseAddressInfoRec {// Takes a VDSwitchInfoPtr 
  long csDevData;       // LONGINT - (// Takes a VDSyncInfoPtr 
typedef struct VDBaseAddressInfoRec VD// Takes a VDSwitchInfoPtr 
typedef VDBaseAddressInfoRec *VDBaseAd// Takes a VDSetHardwareCursorPtr 
struct VDSwitchInfoRec {// Takes a VDDrawHardwareCursorPtr 
  unsigned short csMode;    /*(word) m// Takes a VDConvolutionInfoPtr 
  unsigned long csData;     /*(long) f// Takes a VDPowerStatePtr 
  unsigned short csPage;    /*(word) p// Takes a VDPrivateSelectorDataPtr 
  Ptr csBaseAddr;           /*(long) b// Takes a VDMultiConnectInfoPtr 
  unsigned long csReserved; /*(long) R// Takes a VDClutBehavior 
};// Takes a VDDetailedTimingPtr 
typedef struct VDSwitchInfoRec VDSwitc// Takes a VDCommunicationPtr 
typedef VDSwitchInfoRec *VDSwitchInfoPtr;
struct VDTimingInfoRec {
  unsigned long
      csTimingMode; //// Takes a VDScalerPtr
      csTimingFormat; // Takes a VDMirrorPtr
typedef struct VDTimingInfoRec VDTimingInfoRec;
typedef VDTimingInfoRec *VDTimingInfoPtr;
struct VDDisplayConnectInfoRec {
  unsigned short csDisplayType; // INTEGER - (word) Type of display connected   unsigned char csConnectTaggedType; // BYTE - type of tagging   unsigned char csConnectTaggedData; // BYTE - tagging data   unsigned long
      csConnectFlags; // LONGINT - (long) tell us about the connection   unsigned long csDisplayComponent; /* LONGINT - (long) if the card has a direct
  // Status Codes 
                                       display component here (FUTURE) */
  unsigned long csConnectReserved;  // LONGINT - (long) reserved };
typedef struct VDDisplayConnectInfoRec VDDisplayConnectInfoRec;
typedef VDDisplayCo// This is what C&D 2 calls it. 
struct VDMultiConnectInfoRec {
  unsigned long csDisp// This is what C&D 2 calls it. 
                                           of 1..n connections; otherwise,
                                           indicates the ith connection.*/
  VDDisplayConnectInfoRec
      csConnectInfo; // Standard VDDisplayConnectionInfo for connection i.};
typedef struct VDMulti// Takes a VDSwitchInfoPtr 
typedef VDMultiConnect// Takes a VDSyncInfoPtr 
/* RawSenseCode
    This a// Return information about the connection to the display 
   enumerated constants f// Return timing info for a mode 
   sense code hardware is implemented.
// Return base address information about a particular mode 
    For 'standard' sense code hardware// QuickTime scan chasing routine 
        � Instruct the frame buffer co// Takes a VDSwitchInfoPtr 
   monitor sense lines � Read the stat// Takes a VDResolutionInfoPtr 
   (2 is the MSB, 0 the LSB)// Takes a VDVideoParametersInfoPtr 
// Takes a VDGetGammaListPtr 
    IMPORTANT Note:// Takes a VDRetrieveGammaPtr 
    When the 'kTaggingInfoNonStandard'// Takes a VDSupportsHardwareCursorPtr 
   these constants are valid 'csConnec// Takes a VDHardwareCursorDrawStatePtr 
   'VDDisplayConnectInfo'// Takes a VDConvolutionInfoPtr 
// Takes a VDPowerStatePtr 
*/// Takes a VDPrivateSelectorDataPtr 
typedef unsigned char RawSenseCode;// Takes a VDDDCBlockPtr  
enum {// Takes a VDMultiConnectInfoPtr 
  kRSCZero = 0,// Takes a VDClutBehaviorPtr 
  kRSCOne = 1,// Takes a VDDisplayTimingRangePtr 
  kRSCTwo = 2,// Takes a VDDetailedTimingPtr 
  kRSCThree = 3,// Takes a VDCommunicationInfoPtr 
  kRSCFour = 4,// Takes a VDScalerInfoPtr 
  kRSCFive = 5,// Takes a VDScalerPtr
  kRSCSix = 6,// Takes a VDMirrorPtr
  kRSCSeven = 7
};
// Bit definitions for the Get/Set Sync call
/* ExtendedSenseCode
    This abstract data type is not exactly abstract.  Rather, it is merely
   enumerated constants for the values which are possible when the extended
   sense algorithm is applied to hardware which implements 'standard' sense code
   hardware.

    For 'standard' sense code hardware, the extended sense code algorithm is as
   follows: (Note:  as described here, sense line 'A' corresponds to '2', 'B' to
   '1', and 'C' to '0') � Drive sense line 'A' low and read the values of 'B'
   and 'C'. � Drive sense line 'B' low and read the values of 'A' and 'C'. �
   Drive sense line 'C' low and read the values of 'A' and 'B'.

    In this way, a six-bit number of the form BC/AC/AB is generated.

    IMPORTANT Note:
    When the 'kTaggingInfoNonStandard' bit of 'csConnectFlags' is FALSE, then
   these constants are valid 'csConnectTaggedData' values in
   'VDDisplayConnectInfo'

*/
typedef unsigned char ExtendedSenseCode;
en//    Power Mode constants for translating DPMS modes to Get/SetSync calls. 
  kESCZero21Inch = 0x00,            // 21" RGB                       kESCOnePortraitMono = 0x14,       // Portrait Monochrome                kESCTwo12Inch = 0x21,             // 12" RGB                      kESCThree21InchRadius = 0x31,     // 21" RGB (Radius)                 kESCThree21InchMonoRadius = 0x34, // 21" Monochrome (Radius)             kESCThree21InchMono = 0x35,       // 21" Monochrome                 kESCFourNTSC = 0x0A,              // NTSC                       kESCFivePortrait = 0x1E,          // Portrait RGB                kESCSixMSB1 = 0x03,               // MultiScan Band-1 (12" thru 1Six")    kESCSixMSB2 = 0x0B,               // MultiScan Band-2 (13" thru 19")         kESCSixMSB3 = 0x23,               // MultiScan Band-3 (13" thru 21")         kESCSixStandard = 0x2B,           // 13"/14" RGB or 12" Monochrome     kESCSevenPAL = 0x00,              // PAL                          kESCSevenNTSC = 0x14,             // NTSC                       kESCSevenVGA = 0x17,              // VGA                          kESCSeven16Inch = 0x2D,           // 16" RGB (GoldFish)                 kESCSevenPALAlternate = 0x30,     // PAL (Alternate)                  kESCSeven19Inch = 0x3A,           // Third-Party 19�                   kESCSevenDDC = 0x3E,              // DDC display                     kESCSevenNoDisplay = 0x3F         // No display connected           };

/* DepthMode
    This abstract data type is used to to reference RELATIVE pixel depths.
    Its definition is largely derived from its past usage, analogous to
   'xxxVidMode'
// Bit definitions for the Get/Set Convolution call
    Bits per pixel DOES NOT directly map to 'DepthMode'  For example, on some
    graphics hardware, 'kDepthMode1' may represent 1 BPP, whereas on other
    hardware, 'kDepthMode1' may represent 8BPP.

    DepthMode IS considered to be ordinal, i.e., operations such as <, >, ==,
   etc. behave as expected.  The values of the constants which comprise the set
   are such that 'kDepthMode4 < kDepthMode6' behaves as expected.
*/
typedef unsigned short DepthMode;
enum {
  kDepthMode1 = 128,
  kDepthMode2 = 129,
  kDepthMode3 = 130,
  kDepthMode4 = 131,
  kDepthMode5 = 132,
  kDepthMode6 = 133
};

enum {
  kFirstDepthMode = 128,  // These constants are obsolete, and just included    kSecondDepthMode = 129, // for clients that have converted to the above       kThirdDepthMode = 130,  // kDepthModeXXX constants.                  kFourthDepthMode = 131,
  kFifthDepthMode = 132,
  kSixthDepthMode = 133
};

struct VDPageInfo {
  short csMode;   // (word) mode within device
  long csData;    // (long) data supplied by driver
  short csPage;   // (word) page to switch in
  Ptr csBaseAddr; // (long) base address of page
// Parm block for SetGray control call 
typedef struct VDPageInfo VDPageInfo;
typedef VDPageInfo *VDPgInfoPtr;
struct VDSizeInfo {
  short csHSize; // (word) desired/returned h size
  short csHPos;  // (word) desired/returned h position
  short csVSize; // (word) desired/returned v size
// Parm block for SetInterrupt call 
};
typedef struct VDSizeInfo VDSizeInfo;
typedef VDSizeInfo *VDSzInfoPtr;
struct VDSettings {
  short csParamCnt;  // (word) number of params
  short csBrightMax; // (word) max brightness
// Parm block for SetEntries control call 
  short csBrightVal; // (word) current brightness
  short csCntrstMax; // (word) max contrast
  short csCntrstDef; // (word) default contrast
  short csCntrstVal; // (word) current contrast
  short csTintMax;   // (word) max tint
  short csTintDef;   // (word) default tint
  short csTintVal;   // (word) current tint
// Parm block for SetGamma control call 
  short csHueDef;    // (word) default hue
  short csHueVal;    // (word) current hue
  short csHorizDef;  // (word) default horizontal
  short csHorizVal;  // (word) current horizontal
  short csHorizMax;  // (word) max horizontal
  short csVertDef;   // (word) default vertical
  short csVertVal;   /*(// LONGINT - (long) timing mode 
  short csVertMax;   /*(// LONGINT - (long) base address of the mode 
};// INTEGER - (short) will some day be the depth 
typedef struct VDSetting// LONGINT - (long) reserved 
typedef VDSettings *VDSettingsPtr;
struct VDDefMode {
  UInt8 csID;
  SInt8 filler;
};
typedef struct VDDefMode VDDefMode;
typedef VDDefMode *VDDefModePtr;
struct VDSyncInfoRec {
  UInt8 csMode;
  UInt8 csFlags;
};
typedef struct VDSyncInfoRec VDSyncInfoRec;
typedef VDSyncInfoRec *VDSyncInfoPtr;
typedef UInt32 AVIDType;
typedef AVIDType Dis// LONGINT - (long) timing mode (a la InitGDevice) 
typedef UInt32 DisplayModeID;// LONGINT - (long) reserved 
typedef UInt32 VideoDeviceType;
typedef UInt32 GammaTa// LONGINT - (long) what format is the timing info 
/**// LONGINT - (long) data supplied by driver 
   All displayModeID values fro// LONGINT - (long) mode within device 
   are reserved for Apple Computer.
*/
// Constants for the cscGetNextResolution call enum {
  kDisplayModeIDCurrent = 0x00, // Reference the Current DisplayModeID   kDisplayModeIDInvalid =
      (long)0xFFFFFFFF, // A bog// INTEGER - (word) Type of display connected 
      (long)0xFFFFFFFE, // Used in cs// BYTE - type of tagging 
      (long)0xFFFFFFFD, /* Used in cs// BYTE - tagging data 
                         */
  kDisplayModeIDFindFi// LONGINT - (long) tell us about the connection 
      (long)0xFFFFFFFC, /* Used in cscGetNextResolution to find unused
                           programmable timing */
  kDisplayModeIDBootProgrammable =
      (long)0xFFFFFFFB, /* This is t// LONGINT - (long) reserved 
                           a programmable timing */
  kDisplayModeIDReservedBase =
      (long)0x80000000 // Lowest (unsigned) DisplayModeID reserved by Apple };

// Constants for the GetGammaInfoList call enum {
  kGammaTableIDFindFirst = (long)0xFFFFFFFE, // Get the first gamma table ID   kGammaTableIDNoMoreTables =
      (long)0xFFFFFFFD,        // Used to indicate end of list   kGammaTableIDSpecific = 0x00 // Return the info for the given table id };

// Constants for GetM// Standard VDDisplayConnectionInfo for connection i.
  kGetConnectionCount =
      (long)0xFFFFFFFF, /* Used to get the number of possible connections in a
                           �multi-headed� framebuffer environment.*/
  kActivateConnection =
      (0 << kConnectionInactive), /* Used for activating a connection
                                     (csConnectFlags value).*/
  kDeactivateConnection =
      (1 << kConnectionInactive) /* Used for deactivating a connection
                                    (csConnectFlags value.)*/
};

// VDCommunicationRec.csBusID valuesenum { kVideoDefaultBus = 0 };

// VDCommunicationInfoRec.csBusType valuesenum { kVideoBusTypeInvalid = 0, kVideoBusTypeI2C = 1 };

/* VDCommunicationRec.csSendType and VDCommunicationRec.csReplyType values and
 * bits in VDCommunicationInfoRec.csSupportedTypes.*/
enum {
  kVideoNoTransactionType = 0, // No transaction  kVideoSimpleI2CType = 1,     // Simple I2C message  kVideoDDCciReplyType = 2     // DDC/ci message (with imbedded length)};

/* VDCommunicationRec.csCommFlags and
 * VDCommunicationInfoRec.csSupportedCommFlags*/
enum {
  kVideoReplyMicroSecDelayMask =
      (1 << 0) /* If set, the driver should delay csMinReplyDelay micro seconds
                  between send and recieve*/
};

struct VDResolutionInfoRec {
  DisplayModeID
      csPreviousDisplayModeID;   // ID of the previous resolution in a chain   DisplayModeID csDisplayModeID; // ID of the next resolution   unsigned long csHorizontalPixels; /* # of pixels in a horizontal line at the
                                       max depth */
  unsigned long csVerticalLines; // # of lines in a screen at the max depth   Fixed csRefreshRate;           // Vertical Refresh Rate in Hz   DepthMode csMaxDepthMode; // 0x80-based number representing max bit depth   unsigned long csResolutionFlags; // Reserved - flag bits   unsigned long csReserved;        // Reserved };
typedef struct VDResolutionInfoRec VDResolutionInfoRec;
typedef VDResolutionInfoRec *VDResolutionInfoPtr;
struct VDVideoParametersInfoRec {
  DisplayModeID csDisplayModeID; // the ID of the resolution we want info on   DepthMode csDepthMode;   // The bit depth we want the info on (0x80 based)   VPBlockPtr csVPBlockPtr; // Pointer to a video parameter block   unsigned long csPageCount; // Number of pages supported by the resolution   VideoDeviceType csDeviceType; // Device Type:  Direct, Fixed or CLUT;   UInt32 csDepthFlags;          // Flags };
typedef struct VDVideoParametersInfoRec VDVideoParametersInfoRec;
typedef VDVideoParametersInfoRec *VDVideoParametersInfoPtr;
struct VDGammaInfoRec {
  GammaTableID csLastGammaID; // the ID of the previous gamma table   GammaTableID csNextGammaID; // the ID of the next gamma table   Ptr csGammaPtr;             // Ptr to a gamma table data   unsigned long csReserved;   // Reserved };
typedef struct VDGammaInfoRec VDGammaInfoRec;
typedef VDGammaInfoRec *VDGammaInfoPtr;
struct VDGetGammaListRec {
  GammaTableID csPreviousGammaTableID; // ID of the previous gamma table   GammaTableID csGammaTableID;         /* ID of the gamma table following
                                          csPreviousDisplayModeID */
  unsigned long csGammaTableSize;      // Size of the gamma table in bytes   char *csGammaTableName;              // Gamma table name (c-string) };
typedef struct VDGetGammaListRec VDGetGammaListRec;
typedef VDGetGammaListRec *VDGetGammaListPtr;
struct VDRetrieveGammaRec {
  GammaTableID csGammaTableID; // ID of gamma table to retrieve   GammaTbl *csGammaTablePtr;   // Location to copy desired gamma to };
typedef struct VDRetrieveGammaRec VDRetrieveGammaRec;
typedef VDRetrieveGammaRec *VDRetrieveGammaPtr;
struct VDSetHardwareCursorRec {// 21" RGB                     
  void *csCursorRef;  // reference t// Portrait Monochrome              
typedef struct VDSetHardwareCursorRe// 12" RGB                    
typedef VDSetHardwareCursorRec *VDSe// 21" RGB (Radius)               
struct VDDrawHardwareCursorRec {// 21" Monochrome (Radius)           
  SInt32 csCursorX;       // x coord// 21" Monochrome               
typedef struct VDDrawHardwareCursorR// NTSC                     
typedef VDDrawHardwareCursorRec *VDD// Portrait RGB              
struct VDSupportsHardwareCursorRec {// MultiScan Band-1 (12" thru 1Six")  
  UInt32 csSupportsHardwareCursor;// MultiScan Band-2 (13" thru 19")       
  // true if hardware cursor is supp// MultiScan Band-3 (13" thru 21")       
typedef struct VDSupportsHardwareCur// 13"/14" RGB or 12" Monochrome   
typedef VDSupportsHardwareCursorRec // PAL                        
struct VDHardwareCursorDrawStateRec // NTSC                     
  SInt32 csCursorX;       // x coord// VGA                        
                             call */// 16" RGB (GoldFish)               
  UInt32 csReserved1;     // reserve// PAL (Alternate)                
typedef struct VDHardwareCursorDrawS// Third-Party 19�                 
typedef VDHardwareCursorDrawStateRec// DDC display                   
struct VDConvolutionInfoRec {// No display connected           
  DisplayModeID csDisplayModeID; // the ID of the resolution we want info on   DepthMode csDepthMode; // The bit depth we want the info on (0x80 based)   unsigned long csPage;
  UInt32 csFlags;
  UInt32 csReserved;
};
typedef struct VDConvolutionInfoRec VDConvolutionInfoRec;
typedef VDConvolutionInfoRec *VDConvolutionInfoPtr;
struct VDPowerStateRec {
  unsigned long powerState;
  unsigned long powerFlags;

  unsigned long powerReserved1;
  unsigned long powerReserved2;
};
typedef struct VDPowerStateRec VDPowerStateRec;
typedef VDPowerStateRec *VDPowerStatePtr;
/**
    Private Data to video drivers.

    In versions of MacOS with multiple address spaces (System 8), the OS
    must know the extent of parameters in order to move them between the caller
    and driver.  The old private-selector model for video drivers does not have
    this information so:

    For post-7.x Systems private calls should be implemented using the
   cscPrivateCall
*/
struct VDPrivateSelectorDa// These constants are obsolete, and just included  
  LogicalAddress privatePa// for clients that have converted to the above     
                          // kDepthModeXXX constants.                
  ByteCount privateResultsSize; /* Size of data driver returns to caller. Can be
                                   nil, or same as privateParametersSize.*/
};
typedef struct VDPrivateSelectorDataRec VDPrivateSelectorDataRec;

struct VDPrivateSelectorRec {
  UInt32 reserved; // Reserved (set to 0).   VDPrivateSelectorDataRec data[1];
};
typedef struct VDPrivateSelectorRec VDPrivateSelectorRec;
struct VDDDCBlockRec {
  UInt32 ddcBlockNumber;  /* Input -- DDC EDID (Extended Display Identification
                             Data) number (1-based) */
  ResType ddcBlockType;   // Input -- DDC block type (EDID/VDIF)   UInt32 ddcFlags;        // Input -- DDC Flags  UInt32 ddcReserved;     // Reserved   Byte ddcBlockData[128]; // Output -- DDC EDID/VDIF data (kDDCBlockSize) };
typedef struct VDDDCBlockRec VDDDCBlockRec;
typedef VDDDCBlockRec *VDDDCBlockPtr;

enum {
  // timingSyncConfiguration  kSyncInterlaceMask = (1 << 7),
  kSyncAnalogCompositeMask = 0,
  kSyncAnalogCompositeSerrateMask = (1 << 2),
  kSyncAnalogCompositeRGBSyncMask = (1 << 1),
  kSyncAnalogBipolarMask = (1 << 3),
  kSyncAnalogBipolarSerrateMask = (1 << 2),
  kSyncAnalogBipolarSRGBSyncMask = (1 << 1),
  kSyncDigitalCompositeMask = (1 << 4),
  kSyncDigitalCompositeSerrateMask = (1 << 2),
  kSyncDigitalCompositeMatchHSyncMask = (1 << 2),
  kSyncDigitalSeperateMask = (1 << 4) + (1 << 3),
  kSyncDigitalVSyncPositiveMask = (1 << 2),
  kSyncDigitalHSyncPositiveMask = (1 << 1)
};

struct VDDisplayTimingRangeRec {
  UInt32 csRangeSize;     // Init to sizeof(VDDisplayTimingRangeRec)   UInt32 csRangeType;     // Init to 0   UInt32 csRangeVersion;  // Init to 0   UInt32 csRangeReserved; // Init to 0 
  UInt32 csRangeBlockIndex; // Requested block (first index is 0)  UInt32 csRangeGroup;      // set to 0   UInt32 csRangeBlockCount; // # blocks   UInt32 csRangeFlags;      // dependent video 
  UInt64 csMinPixelClock; // Min dot clock in Hz   UInt64 csMaxPixelClock; // Max dot clock in Hz 
  UInt32 csMaxPixelError; // Max dot clock error   UInt32 csTimingRangeSyncFlags;
  UInt32 csTimingRangeSignalLevels;
  UInt32 csReserved0;

  UInt32 csMinFrameRate; // Hz   UInt32 csMaxFrameRate; // Hz   UInt32 csMinLineRate;  // Hz   UInt32 csMaxLineRate;  // Hz 
  UInt32 csMaxHorizontalTotal; // Clocks - Maximum total (active + blanking)   UInt32 csMaxVerticalTotal;   // Clocks - Maximum total (active + blanking)   UInt32 csMaxTotalReserved1;  // Reserved   UInt32 csMaxTotalReserved2;  // Reserved 
  // Some cards require that some timing elements  // be multiples of a "character size" (often 8  // clocks).  The "xxxxCharSize" fields document  // those requirements.
  UInt8 csCharSizeHorizontalActive;     // Character size   UInt8 csCharSizeHorizontalBlanking;   // Character size   UInt8 csCharSizeHorizontalSyncOffset; // Character size   UInt8 csCharSizeHorizontalSyncPulse;  // Character size 
  UInt8 csCharSizeVerticalActive;     // Character size   UInt8 csCharSizeVerticalBlanking;   // Character size   UInt8 csCharSizeVerticalSyncOffset; // Character size   UInt8 csCharSizeVerticalSyncPulse;  // Character size 
  UInt8 csCharSizeHorizontalBorderLeft;  // Character size   UInt8 csCharSizeHorizontalBorderRight; // Character size   UInt8 csCharSizeVerticalBorderTop;     // Character size   UInt8 csCharSizeVerticalBorderBottom;  // Character size 
  UInt8 csCharSizeHorizontalTotal; // Character size for active + blanking   UInt8 csCharSizeVerticalTotal;   // Character size for active + blanking   UInt16 csCharSizeReserved1;      // Reserved (Init to 0) 
  UInt32 csMinHorizontalActiveClocks;
  UInt32 csMaxHorizontalActiveClocks;
  UInt32 csMinHorizontalBlankingClocks;
  UInt32 csMaxHorizontalBlankingClocks;

  UInt32 csMinHorizontalSyncOffsetClocks;
  UInt32 csMaxHorizontalSyncOffsetClocks;
  UInt32 csMinHorizontalPulseWidthClocks;
  UInt32 csMaxHorizontalPulseWidthClocks;

  UInt32 csMinVerticalActiveClocks;
  UInt32 csMaxVerticalActiveClocks;
  UInt32 csMinVerticalBlankingClocks;
  UInt32 csMaxVerticalBlankingClocks;

  UInt32 csMinVerticalSyncOffsetClocks;
  UInt32 csMaxVerticalSyncOffsetClocks;
  UInt32 csMinVerticalPulseWidthClocks;
// Constants for the cscGetNextResolution call 

  UInt32 csMinHorizontalBorderLe// Reference the Current DisplayModeID 
  UInt32 csMaxHorizontalBorderLeft;
  UInt32 csMinHorizontal// A bogus DisplayModeID in all cases 
  UInt32 csMaxHorizontalBorderRight;
// Used in cscGetNextResolution to reset iterator 
  UInt32 csMinVerticalBorderTop;
  UInt32 csMaxVerticalBorderTop;
  UInt32 csMinVerticalBorderBottom;
  UInt32 csMaxVerticalBorderBottom;

  UInt32 csReserved1; // Reserved (Init to 0)  UInt32 csReserved2; // Reserved (Init to 0)  UInt32 csReserved3; // Reserved (Init to 0)  UInt32 csReserved4; // Reserved (Init to 0)
  UInt32 csReserved5; // Reserved (Init to 0)  UInt32 csReserved6; // Reserved (Init to 0)  UInt32 csReserved7; // Reserved (Init to 0)  UInt32 csReserved8; // Reserved (Init to 0)};
typedef struct VDDisplayTimingRangeRec VDDisplayTimingRangeRec;
typedef VDDisplayTimingRangeRec *VDDisplayTimingRangePtr;

enum {// Lowest (unsigned) DisplayModeID reserved by Apple 
  // csDisplayModeState  kDMSModeReady = 0,    // Display Mode ID is configured and ready  kDMSModeNotReady = 1, // Display Mode ID is is being programmed  kDMSModeFree = 2      // Display Mode ID is not associated with a timing};

// Constants for the GetGammaInfoList call 
  kTimingChangeRestrictedErr = -10930,
  kVideoI2CReplyPendingErr = -10931,// Get the first gamma table ID 
  kVideoI2CTransactionErr = -10932,
  kVideoI2CBusyErr = -10933,// Used to indicate end of list 
  kVideoI2CTransactionTypeErr =// Return the info for the given table id 
  kVideoBufferSizeErr = -10935,
  kVideoCannotMirrorErr = -10936
// Constants for GetMultiConnect call

enum {
  // csTimingRangeSignalLevels  kRangeSupportsSignal_0700_0300_Bit = 0,
  kRangeSupportsSignal_0714_0286_Bit = 1,
  kRangeSupportsSignal_1000_0400_Bit = 2,
  kRangeSupportsSignal_0700_0000_Bit = 3,
  kRangeSupportsSignal_0700_0300_Mask =
      (1 << kRangeSupportsSignal_0700_0300_Bit),
  kRangeSupportsSignal_0714_0286_Mask =
      (1 << kRangeSupportsSignal_0714_0286_Bit),
  kRangeSupportsSignal_1000_0400_Mask =
      (1 << kRangeSupportsSignal_1000_0400_Bit),
// VDCommunicationRec.csBusID values
      (1 << kRangeSupportsSignal_0700_0000_Bit)
};
// VDCommunicationInfoRec.csBusType values
enum {
  // csSignalConfig  kDigitalSignalBit = 0, /* Do not set.  Mac OS does not currently support
                            arbitrary digital timings*/
  kAnalogSetupExpectedBit =
      1, /* Analog displays - display expects a blank-to-black setup or
            pedestal.  See VESA// No transaction
  kDigitalSignalMask = (1 << kD// Simple I2C message
  kAnalogSetupExpectedMask = (1// DDC/ci message (with imbedded length)
};

enum {
  // csSignalLevels for analog  kAnalogSignalLevel_0700_0300 = 0,
  kAnalogSignalLevel_0714_0286 = 1,
  kAnalogSignalLevel_1000_0400 = 2,
  kAnalogSignalLevel_0700_0000 = 3
};

enum {
  // csTimingRangeSyncFlags  kRangeSupportsSeperateSyncsBit = 0,
  kRangeSupportsSyncOnGreenBit = 1,
  kRangeSupportsCompositeSyncBit // ID of the previous resolution in a chain 
  kRangeSupportsVSyncSerrationBit// ID of the next resolution 
  kRangeSupportsSeperateSyncsMask = (1 << kRangeSupportsSeperateSyncsBit),
  kRangeSupportsSyncOnGreenMask = (1 << kRangeSupportsSyncOnGreenBit),
  kRangeSupportsCompositeSyncMask// # of lines in a screen at the max depth 
  kRangeSupportsVSyncSerrationMas// Vertical Refresh Rate in Hz 
};// 0x80-based number representing max bit depth 
// Reserved - flag bits 
enum {// Reserved 
  // csHorizontalSyncConfig and csVerticalSyncConfig  kSyncPositivePolarityBit = 0, /* Digital separate sync polarity for analog
                                   interfaces (0 => negative polarity)*/
  kSyncPositivePolarityMask = (1 << kSyncPositivePolarityBit)
};
// the ID of the resolution we want info on 
// For timings with kDetail// The bit depth we want the info on (0x80 based) 
  UInt32 csTimingSize;     // Pointer to a video parameter block 
  DisplayModeID csDisplayMode// Number of pages supported by the resolution 
  UInt32 csSignalConfig;// Device Type:  Direct, Fixed or CLUT; 
  UInt32 csSignalLevels;// Flags 

  UInt64 csPixelClock; // Hz
  UInt64 csMinPixelClock; // Hz - With error what is slowest actual clock   UInt64 csMaxPixelClock; // Hz - With error what is fasted actual clock 
  UInt32 csHorizontalActive;         // Pixels  UInt32 csHorizontalBlanking;       // Pixels  UInt32 csHorizontalSyncOffset;     // Pixels  UInt32 csHorizontalSyncPulseWidth; // Pixels
  UInt32 csVerticalActive;    // the ID of the previous gamma table 
  UInt32 csHorizontalBorderLef// the ID of the next gamma table 
  UInt32 csHorizontalSyncConfi// Ptr to a gamma table data 
  UInt32 csHorizontalSyncLevel// Reserved 
  UInt32 csVerticalSyncLevel; // Future use (init to 0)
  UInt32 csReserved1; // Init to 0  UInt32 csReserved2; // Init to 0  UInt32 csReserved3; // Init to 0  UInt32 csReserved4; // Init to 0
  UInt32 csReserved5; // Init to 0  UInt32 csReserved6; // Init to 0  UInt32 csReserved7; // Init to 0  UInt32 csReserved8; // Init to 0};
typedef struct VDDetailedTimingRec VDDetailedTimingRec;
typedef VDDetailedTimingRec *VDDetailed// ID of the previous gamma table 

enum {
  // csScalerFeatures  kScaleStretchOnl// Size of the gamma table in bytes 
                                       // Gamma table name (c-string) 
  kScaleCanUpSamplePixelsMask =
      (1 << 1), /* True means timings with more active clocks than pixels (ie
                   640x480 pixels on a 1600x1200 timing)*/
  kScaleCanDownSamplePixelsMask =
      (1 << 2) /* True means ti// ID of gamma table to retrieve 
                  1600x1200  pi// Location to copy desired gamma to 
};

enum {
  // csScalerFlags  kScaleStretchToFitMask = (1 << 0) /* True means the driver should avoid
                      // reference to cursor data 
};// reserved for future use 
// should be ignored 
typedef UInt32 VDClutBehavior;
typedef VDClutBehavior *VDClutBehaviorPtr;
enum {
  kSetClutAtSetEntries =
      0, // SetEntries beh// x coordinate 
// y coordinate 
struct VDCommunicationRec // true if cursor is must be visible 
  SInt32 csBusID;         // reserved for future use 
                          // should be ignored 
  UInt32 csReserved2;     // Always zero
  UInt32 csSendAddress;        // Usually I2C address (eg 0x6E)  UInt32 csSendType;           // See kVideoSimpleI2CType etc.  LogicalAddress csSendBuffer; // Pointer to the send buffer  ByteCount csSendSize;        // Number of bytes to send
  UInt32 csReplyAddress;        /* Address from which to read (eg 0x6F for
                                   kVideoDDCciReplyType I2C address)*/
  UInt32 csReplyType;           // See kVideoDDCciReplyType etc.  LogicalAddress csReplyBuffer; // Pointer to the reply buffer  ByteCount csReplySize;        // Max bytes to reply (size of csReplyBuffer)
  // true if hardware cursor is supported 
  UInt32 csReserved4;// reserved for future use 
  UInt32 csReserved5; // must be zero 
typedef struct VDCommunicationRec VDCommunicationRec;
typedef VDCommunicationRec *VDCommunicationPtr;
struct VDCommunicationInfoRec {
  SInt32 csBusID;   // kVideoDefaultBus for single headed cards.   UInt32 csBusType; // See kVideoBusI2C etc.  SInt32 csMinBus;  /* Minimum bus (usually kVideoDefaultBus).  Used to probe
                       add// x coordinate 
  SInt32 csMaxBus;  /* Max// y coordinate 
                       add// true if cursor is visible 

  UInt32
      csSupportedTypes; /*// reserved for future use 
                          // must be zero 
                           kVideoSimpleI2CType and kVideoDDCciReplyType.*/
  UInt32 csSupportedCommFlags; /* Return the flags csCommFlags understood by
                                  this driver.*/
  UInt32 csReserved2;          // Always zero  UInt32 csReserved3;          // Always zero
  UInt32 csReserved4; // Always z// the ID of the resolution we want info on 
typedef struct VDCommunic// The bit depth we want the info on (0x80 based) 
typedef VDCommunicationInfoRec *VDCommunicationInfoPtr;
struct VDScalerRec {
  UInt32 csScalerSize;    // Init to sizeof(VDScalerRec)  UInt32 csScalerVersion; // Init to 0  UInt32 csReserved1;     // Init to 0  UInt32 csReserved2;     // Init to 0
  DisplayModeID csDisplayModeID; // Display Mode ID modified by this call.  UInt32 csDisplayModeSeed;      //   UInt32 csDisplayModeState;     // Display Mode state  UInt32 csReserved3;            // Init to 0
  UInt32 csScalerFlags;      // Init to 0  UInt32 csHorizontalPixels; // Graphics system addressable pixels  UInt32 csVerticalPixels;   // Graphics system addressable lines  UInt32 csReserved4;        // Init to 0
  UInt32 csReserved5; // Init to 0  UInt32 csReserved6; // Init to 0  UInt32 csReserved7; // Init to 0  UInt32 csReserved8; // Init to 0};
typedef struct VDScalerRec VDScalerRec;
typedef VDScalerRec *VDScalerPtr;
struct VDScalerInfoRec {
  UInt32 csScalerInfoSize;    // Init to sizeof(VDScalerInfoRec)  UInt32 csScalerInfoVersion; // Init to 0  UInt32 csReserved1;         // Init to 0  UInt32 csReserved2;         // Init to 0
  UInt32 csScalerFeatures;      // Feature flags  UInt32 csMaxHorizontalPixels; // limit to horizontal scaled pixels  UInt32 csMaxVerticalPixels;   // limit to vertical scaled pixels  UInt32 csReserved3;           // Init to 0
  UInt32 csReserved4; // Init to 0  UInt32 csReserved5; // Init to 0  UInt32 csReserved6; // Init to 0  UInt32 csReserved7; // Init to 0};
typedef struct VDScalerInfoRec VDScalerInfoRec;
typedef VDScalerInfoRec *VDScalerInfoPtr;
enum {
  // csMirrorFeatures  kMirrorSameDepthOnlyMirrorMask =
      (1 << 0), /* Commonly true - Mirroring can only be done if the displays
                   are the same bitdepth*/
  kMirrorSameSizeOnlyMirrorMask =
      (1 << 1), /* Commonly false - Mirroring can only be done if the displays
                   are the same size*/
  kMirrorSameTimingOnlyMirrorMask =
      (1 << 2), /* Sometimes true - Mirroring can only be done if the displays
                   are the same timing*/
  kMirrorCommonGammaMask =
      (1 << 3) // Sometimes true - Only one gamma correction LUT.};

enum {// Caller's parameters
  // csMirrorSupportedFlags and csMi// Size of data sent from caller to driver
      (1
       << 0), // Set means we can HW mirrored right now (uses csMirrorEntryID)  kMirrorAreMirroredMask =
      (1
       << 1), // Set means we are HW mirrored right now (uses csMirrorEntryID)  kMirrorUnclippedMirrorMask = (1 << 2), /* Set means mirrored displays are not
                                            clipped to their intersection*/
  kMirrorHAlignCenterMirrorMask =
      (1 << 3), /* Set means mirrored displays can/should be centered
                   horizontally*/
  kMirrorVAlignCent// Reserved (set to 0). 
      (1
       << 4), // Set means mirrored displays can/should be centered vertically  kMirrorCanChangePixelFormatMask =
      (1 << 5), /* Set means mirrored the device should change the pixel format
                   of mirrored displays to allow mirroring.*/
  kMirrorCanChangeTimingMask =
      (1 << 6) /* Set means mirrored the device should change the timing of
                  mirrored// Input -- DDC block type (EDID/VDIF) 
};// Input -- DDC Flags
// Reserved 
struct VDMirrorRec {// Output -- DDC EDID/VDIF data (kDDCBlockSize) 
  UInt32 csMirrorSize;    // Init to sizeof(VDMirrorRec)  UInt32 csMirrorVersion; // Init to 0
  RegEntryID csMirrorRequestID; /* Input RegEntryID to check for mirroring
                                   support and state*/
  RegEntryID
      csMirrorResultID; // Output RegEntryID of the next mirrored device
  // timingSyncConfiguration
                                    the driver*/
  UInt32 csMirrorFlags;          // Output configuration options active now  UInt32 csReserved1;            // Init to 0
  UInt32 csReserved2; // Init to 0  UInt32 csReserved3; // Init to 0  UInt32 csReserved4; // Init to 0  UInt32 csReserved5; // Init to 0};
typedef struct VDMirrorRec VDMirrorRec;
typedef VDMirrorRec *VDMirrorPtr;

#if PRAGMA_STRUCT_ALIGN
#pragma options align = reset
#elif PRAGMA_STRUCT_PACKPUSH
#pragma pack(pop)
#elif PRAGMA_STRUCT_PACK
#pragma pack()
#endif

#ifdef PRAGMA_IMPORT_OFF
#pragma import off
#elif PRAGMA_IMPORT  // Init to sizeof(VDDisplayTimingRangeRec)
#pragma import reset // Init to 0
#endif               // Init to 0
  // Init to 0
#ifdef __cplusplus
}// Requested block (first index is 0)
#endif // set to 0
  // # blocks
#endif // __VIDEO__ // dependent video
    // Min dot clock in Hz
    // Max dot clock in Hz
    // Max dot clock error
    // Hz
    // Hz
    // Hz
    // Hz
    // Clocks - Maximum total (active + blanking)
    // Clocks - Maximum total (active + blanking)
    // Reserved
    // Reserved
    // Some cards require that some timing elements
    // be multiples of a "character size" (often 8
    // clocks).  The "xxxxCharSize" fields document
    // those requirements.
    // Character size
    // Character size
    // Character size
    // Character size
    // Character size
    // Character size
    // Character size
    // Character size
    // Character size
    // Character size
    // Character size
    // Character size
    // Character size for active + blanking
    // Character size for active + blanking
    // Reserved (Init to 0)
    // Reserved (Init to 0)
    // Reserved (Init to 0)
    // Reserved (Init to 0)
    // Reserved (Init to 0)
    // Reserved (Init to 0)
    // Reserved (Init to 0)
    // Reserved (Init to 0)
    // Reserved (Init to 0)
    // csDisplayModeState
    // Display Mode ID is configured and ready
    // Display Mode ID is is being programmed
    // Display Mode ID is not associated with a timing
    // Video driver Errors -10930 to -10959
    // csTimingRangeSignalLevels
    // csSignalConfig
    // csSignalLevels for analog
    // csTimingRangeSyncFlags
    // csHorizontalSyncConfig and csVerticalSyncConfig
    // For timings with kDetailedTimingFormat.
    // Init to sizeof(VDDetailedTimingRec)
    // Init to 0
    // Init to 0
    // Init to 0
    // Init to 0
    //
    // Display Mode state
    // Mode to use when programmed.
    // Hz
    // Hz - With error what is slowest actual clock
    // Hz - With error what is fasted actual clock
    // Pixels
    // Pixels
    // Pixels
    // Pixels
    // Lines
    // Lines
    // Lines
    // Lines
    // Pixels
    // Pixels
    // Lines
    // Lines
    // Future use (init to 0)
    // Future use (init to 0)
    // Init to 0
    // Init to 0
    // Init to 0
    // Init to 0
    // Init to 0
    // Init to 0
    // Init to 0
    // Init to 0
    // csScalerFeatures
    // csScalerFlags
    // SetEntries behavior is to update clut during SetEntries call
    // SetEntries behavior is to upate clut at next vbl
    // kVideoDefaultBus for single headed cards.
    // Always zero
    // Always zero
    // Usually I2C address (eg 0x6E)
    // See kVideoSimpleI2CType etc.
    // Pointer to the send buffer
    // Number of bytes to send
    // See kVideoDDCciReplyType etc.
    // Pointer to the reply buffer
    // Max bytes to reply (size of csReplyBuffer)
    // Always zero
    // Always zero
    // kVideoDefaultBus for single headed cards.
    // See kVideoBusI2C etc.
    // Always zero
    // Always zero
    // Always zero
    // Always zero
    // Always zero
    // Always zero
    // Init to sizeof(VDScalerRec)
    // Init to 0
    // Init to 0
    // Init to 0
    // Display Mode ID modified by this call.
    //
    // Display Mode state
    // Init to 0
    // Init to 0
    // Graphics system addressable pixels
    // Graphics system addressable lines
    // Init to 0
    // Init to 0
    // Init to 0
    // Init to 0
    // Init to 0
    // Init to sizeof(VDScalerInfoRec)
    // Init to 0
    // Init to 0
    // Init to 0
    // Feature flags
    // limit to horizontal scaled pixels
    // limit to vertical scaled pixels
    // Init to 0
    // Init to 0
    // Init to 0
    // Init to 0
    // Init to 0
    // csMirrorFeatures
    // Sometimes true - Only one gamma correction LUT.
    // csMirrorSupportedFlags and csMirrorFlags
    // Set means we can HW mirrored right now (uses csMirrorEntryID)
    // Set means we are HW mirrored right now (uses csMirrorEntryID)
    // Set means mirrored displays can/should be centered vertically
    // Init to sizeof(VDMirrorRec)
    // Init to 0
    // Output RegEntryID of the next mirrored device
    // Output summary features of the driver
    // Output configuration options active now
    // Init to 0
    // Init to 0
    // Init to 0
    // Init to 0
    // Init to 0
    // __VIDEO__
