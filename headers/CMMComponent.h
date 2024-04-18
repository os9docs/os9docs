/**
     \file       CMMComponent.h

    \brief   ColorSync CMM Component API

    \introduced_in  ColorSync 2.6
    \avaliable_from Universal Interfaces 3.4.1

    \copyright � 1994-2001 by Apple Computer, Inc., all rights reserved.

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __CMMCOMPONENT__
#define __CMMCOMPONENT__

#ifndef __CMAPPLICATION__
#include <CMApplication.h>
#endif

#ifndef __QUICKDRAW__
#include <Quickdraw.h>
#endif

#ifndef __COMPONENTS__
#include <Components.h>
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

/* Component-based CMM interface version */
enum { CMMInterfaceVersion = 1 };

/* Component-based CMM function selectors */
enum {
  /* Required */
  kCMMOpen = -1,    /* kComponentOpenSelect,*/
  kCMMClose = -2,   /* kComponentCloseSelect,*/
  kCMMGetInfo = -4, /* kComponentVersionSelect*/
  kNCMMInit = 6,
  kCMMMatchColors = 1,
  kCMMCheckColors = 2,

  /* Optional */
  kCMMValidateProfile = 8,
  kCMMMatchBitmap = 9,
  kCMMCheckBitmap = 10,
  kCMMConcatenateProfiles = 5,
  kCMMConcatInit = 7,
  kCMMNewLinkProfile = 16,
  kNCMMConcatInit = 18,
  kNCMMNewLinkProfile = 19,
  kCMMGetPS2ColorSpace = 11,
  kCMMGetPS2ColorRenderingIntent = 12,
  kCMMGetPS2ColorRendering = 13,
  kCMMGetPS2ColorRenderingVMSize = 17,

  /* obsolete with ColorSync 2.5 */
  kCMMFlattenProfile = 14,
  kCMMUnflattenProfile = 15,

  /* obsolete with ColorSync 2.6 */
  kCMMInit = 0,
  kCMMGetNamedColorInfo = 70,
  kCMMGetNamedColorValue = 71,
  kCMMGetIndNamedColorValue = 72,
  kCMMGetNamedColorIndex = 73,
  kCMMGetNamedColorName = 74,

  /* obsolete with ColorSync 3.0 */
  kCMMMatchPixMap = 3,
  kCMMCheckPixMap = 4
};

#if TARGET_API_MAC_OS8
typedef ComponentInstance CMMComponentInst;
#if CALL_NOT_IN_CARBON
/**
 *  NCMMInit()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(CMError)
NCMMInit(CMMComponentInst cmm, CMProfileRef srcProfile, CMProfileRef dstProfile)
    FIVEWORDINLINE(0x2F3C, 0x0008, 0x0006, 0x7000, 0xA82A);

/**
 *  CMMInit()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(CMError)
CMMInit(CMMComponentInst cmm, CMProfileHandle srcProfile,
        CMProfileHandle dstProfile)
    FIVEWORDINLINE(0x2F3C, 0x0008, 0x0000, 0x7000, 0xA82A);

/**
 *  CMMMatchColors()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(CMError)
CMMMatchColors(CMMComponentInst cmm, CMColor *colors, UInt32 count)
    FIVEWORDINLINE(0x2F3C, 0x0008, 0x0001, 0x7000, 0xA82A);

/**
 *  CMMCheckColors()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(CMError)
CMMCheckColors(CMMComponentInst cmm, CMColor *colors, UInt32 count,
               UInt32 *result)
    FIVEWORDINLINE(0x2F3C, 0x000C, 0x0002, 0x7000, 0xA82A);

/**
 *  CMMValidateProfile()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(CMError)
CMMValidateProfile(CMMComponentInst cmm, CMProfileRef prof, Boolean *valid)
    FIVEWORDINLINE(0x2F3C, 0x0008, 0x0008, 0x7000, 0xA82A);

/**
 *  CMMFlattenProfile()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(CMError)
CMMFlattenProfile(CMMComponentInst cmm, CMProfileRef prof, UInt32 flags,
                  CMFlattenUPP proc, void *refCon)
    FIVEWORDINLINE(0x2F3C, 0x0010, 0x000E, 0x7000, 0xA82A);

/**
 *  CMMUnflattenProfile()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(CMError)
CMMUnflattenProfile(CMMComponentInst cmm, FSSpec *resultFileSpec,
                    CMFlattenUPP proc, void *refCon)
    FIVEWORDINLINE(0x2F3C, 0x000C, 0x000F, 0x7000, 0xA82A);

/**
 *  CMMMatchBitmap()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(CMError)
CMMMatchBitmap(CMMComponentInst cmm, CMBitmap *bitmap,
               CMBitmapCallBackUPP progressProc, void *refCon,
               CMBitmap *matchedBitmap)
    FIVEWORDINLINE(0x2F3C, 0x0010, 0x0009, 0x7000, 0xA82A);

/**
 *  CMMCheckBitmap()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(CMError)
CMMCheckBitmap(CMMComponentInst cmm, const CMBitmap *bitmap,
               CMBitmapCallBackUPP progressProc, void *refCon,
               CMBitmap *resultBitmap)
    FIVEWORDINLINE(0x2F3C, 0x0010, 0x000A, 0x7000, 0xA82A);

/**
 *  CMMMatchPixMap()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(CMError)
CMMMatchPixMap(CMMComponentInst cmm, PixMap *pixMap,
               CMBitmapCallBackUPP progressProc, void *refCon)
    FIVEWORDINLINE(0x2F3C, 0x000C, 0x0003, 0x7000, 0xA82A);

/**
 *  CMMCheckPixMap()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(CMError)
CMMCheckPixMap(CMMComponentInst cmm, const PixMap *pixMap,
               CMBitmapCallBackUPP progressProc, BitMap *bitMap, void *refCon)
    FIVEWORDINLINE(0x2F3C, 0x0010, 0x0004, 0x7000, 0xA82A);

/**
 *  CMMConcatInit()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(CMError)
CMMConcatInit(CMMComponentInst cmm, CMConcatProfileSet *profileSet)
    FIVEWORDINLINE(0x2F3C, 0x0004, 0x0007, 0x7000, 0xA82A);

/**
 *  NCMMConcatInit()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(CMError)
NCMMConcatInit(CMMComponentInst cmm, NCMConcatProfileSet *profileSet,
               CMConcatCallBackUPP proc, void *refCon)
    FIVEWORDINLINE(0x2F3C, 0x000C, 0x0012, 0x7000, 0xA82A);

/**
 *  CMMNewLinkProfile()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(CMError)
CMMNewLinkProfile(CMMComponentInst cmm, CMProfileRef *prof,
                  const CMProfileLocation *targetLocation,
                  CMConcatProfileSet *profileSet)
    FIVEWORDINLINE(0x2F3C, 0x000C, 0x0010, 0x7000, 0xA82A);

/**
 *  NCMMNewLinkProfile()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(CMError)
NCMMNewLinkProfile(CMMComponentInst cmm, CMProfileRef prof,
                   NCMConcatProfileSet *profileSet, CMConcatCallBackUPP proc,
                   void *refCon)
    FIVEWORDINLINE(0x2F3C, 0x0010, 0x0013, 0x7000, 0xA82A);

/**
 *  CMMGetPS2ColorSpace()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(CMError)
CMMGetPS2ColorSpace(CMMComponentInst cmm, CMProfileRef srcProf, UInt32 flags,
                    CMFlattenUPP proc, void *refCon)
    FIVEWORDINLINE(0x2F3C, 0x0010, 0x000B, 0x7000, 0xA82A);

/**
 *  CMMGetPS2ColorRenderingIntent()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(CMError)
CMMGetPS2ColorRenderingIntent(CMMComponentInst cmm, CMProfileRef srcProf,
                              UInt32 flags, CMFlattenUPP proc, void *refCon)
    FIVEWORDINLINE(0x2F3C, 0x0010, 0x000C, 0x7000, 0xA82A);

/**
 *  CMMGetPS2ColorRendering()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(CMError)
CMMGetPS2ColorRendering(CMMComponentInst cmm, CMProfileRef srcProf,
                        CMProfileRef dstProf, UInt32 flags, CMFlattenUPP proc,
                        void *refCon)
    FIVEWORDINLINE(0x2F3C, 0x0014, 0x000D, 0x7000, 0xA82A);

/**
 *  CMMGetPS2ColorRenderingVMSize()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(CMError)
CMMGetPS2ColorRenderingVMSize(CMMComponentInst cmm, CMProfileRef srcProf,
                              CMProfileRef dstProf, UInt32 *vmSize)
    FIVEWORDINLINE(0x2F3C, 0x000C, 0x0011, 0x7000, 0xA82A);

/**
 *  CMMConcatenateProfiles()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(CMError)
CMMConcatenateProfiles(CMMComponentInst cmm, CMProfileHandle thru,
                       CMProfileHandle dst, CMProfileHandle *newDst)
    FIVEWORDINLINE(0x2F3C, 0x000C, 0x0005, 0x7000, 0xA82A);

/**
 *  CMMGetNamedColorInfo()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(CMError)
CMMGetNamedColorInfo(CMMComponentInst cmm, CMProfileRef srcProf,
                     UInt32 *deviceChannels, OSType *deviceColorSpace,
                     OSType *PCSColorSpace, UInt32 *count, StringPtr prefix,
                     StringPtr suffix)
    FIVEWORDINLINE(0x2F3C, 0x001C, 0x0046, 0x7000, 0xA82A);

/**
 *  CMMGetNamedColorValue()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(CMError)
CMMGetNamedColorValue(CMMComponentInst cmm, CMProfileRef prof, StringPtr name,
                      CMColor *deviceColor, CMColor *PCSColor)
    FIVEWORDINLINE(0x2F3C, 0x0010, 0x0047, 0x7000, 0xA82A);

/**
 *  CMMGetIndNamedColorValue()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(CMError)
CMMGetIndNamedColorValue(CMMComponentInst cmm, CMProfileRef prof, UInt32 index,
                         CMColor *deviceColor, CMColor *PCSColor)
    FIVEWORDINLINE(0x2F3C, 0x0010, 0x0048, 0x7000, 0xA82A);

/**
 *  CMMGetNamedColorIndex()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(CMError)
CMMGetNamedColorIndex(CMMComponentInst cmm, CMProfileRef prof, StringPtr name,
                      UInt32 *index)
    FIVEWORDINLINE(0x2F3C, 0x000C, 0x0049, 0x7000, 0xA82A);

/**
 *  CMMGetNamedColorName()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(CMError)
CMMGetNamedColorName(CMMComponentInst cmm, CMProfileRef prof, UInt32 index,
                     StringPtr name)
    FIVEWORDINLINE(0x2F3C, 0x000C, 0x004A, 0x7000, 0xA82A);

#endif /* CALL_NOT_IN_CARBON */

#endif /* TARGET_API_MAC_OS8 */

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

#endif /* __CMMCOMPONENT__ */
