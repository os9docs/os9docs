/**
     \file       CMMComponent.h

    \brief   ColorSync CMM Component API

    \introduced_in  ColorSync 2.6
    \avaliable_from Universal Interfaces 3.4.1

    \copyright © 1994-2001 by Apple Computer, Inc., all rights reserved.

    \ingroup ColorSync

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

    // Component-based CMM interface version     enum
    {
        CMMInterfaceVersion = 1};

    // Component-based CMM function selectors     enum
    // Component-based CMM function selectors

    kCMMOpen = -1 kCMMClose = -2 kCMMGetInfo = -4 kNCMMInit = 6 kCMMMatchColors = 1,
    // Required
    // kComponentOpenSelect,
    // Optional       // kComponentCloseSelect,
        kCMMMatchBitmap = // kComponentVersionSelect
        kCMMCheckBitmap = 10,
    kCMMConcatenateProfiles = 5,
    kCMMConcatInit = 7,
    kCMMNewLinkProfile = 16,
    // Optional
        kNCMMNewLinkProfile = 19,
    kCMMGetPS2ColorSpace = 11,
    kCMMGetPS2ColorRenderingIntent = 12,
    kCMMGetPS2ColorRendering = 13,
    kCMMGetPS2ColorRenderingVMSize = 17,

    /** with */
        ColorSync 2.5 kCMMFlattenProfile = 14 kCMMUnflattenProfile = 15,

    /** with */
        ColorSync 2.6 kCMMInit = 0 kCMMGetNamedColorInfo = 70,
    kCMMGetNamedColorValue = 71,
    kCMMGetIndNamedColorValue = 72,
    // obsolete with ColorSync 2.5
        kCMMGetNamedColorName = 74,

    /** with */
        ColorSync 3.0 kCMMMatchPixMap = 3
    // obsolete with ColorSync 2.6
};

#if TARGET_API_MAC_OS8
typedef ComponentInstance CMMComponentInst;
#if CALL_NOT_IN_CARBON
/**
 *  NCMMInit()
  obsolete with ColorSync 3.0

    *    \non_carbon_cfm not available
    *    \carbon_lib not available
    *    \mac_os_x not available */
CMError
NCMMInit(CMMComponentInst cmm, CMProfileRef srcProfile, CMProfileRef dstProfile);

/**
 *  CMMInit()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
CMError
CMMInit(CMMComponentInst cmm, CMProfileHandle srcProfile,
        CMProfileHandle dstProfile);

/**
 *  CMMMatchColors()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
CMError
CMMMatchColors(CMMComponentInst cmm, CMColor *colors, UInt32 count);

/**
 *  CMMCheckColors()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
CMError
CMMCheckColors(CMMComponentInst cmm, CMColor *colors, UInt32 count,
               UInt32 *result);

/**
 *  CMMValidateProfile()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
CMError
CMMValidateProfile(CMMComponentInst cmm, CMProfileRef prof, Boolean *valid);

/**
 *  CMMFlattenProfile()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
CMError
CMMFlattenProfile(CMMComponentInst cmm, CMProfileRef prof, UInt32 flags,
                  CMFlattenUPP proc, void *refCon);

/**
 *  CMMUnflattenProfile()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
CMError
CMMUnflattenProfile(CMMComponentInst cmm, FSSpec *resultFileSpec,
                    CMFlattenUPP proc, void *refCon);

/**
 *  CMMMatchBitmap()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
CMError
CMMMatchBitmap(CMMComponentInst cmm, CMBitmap *bitmap,
               CMBitmapCallBackUPP progressProc, void *refCon,
               CMBitmap *matchedBitmap);

/**
 *  CMMCheckBitmap()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
CMError
CMMCheckBitmap(CMMComponentInst cmm, const CMBitmap *bitmap,
               CMBitmapCallBackUPP progressProc, void *refCon,
               CMBitmap *resultBitmap);

/**
 *  CMMMatchPixMap()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
CMError
CMMMatchPixMap(CMMComponentInst cmm, PixMap *pixMap,
               CMBitmapCallBackUPP progressProc, void *refCon);

/**
 *  CMMCheckPixMap()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
CMError
CMMCheckPixMap(CMMComponentInst cmm, const PixMap *pixMap,
               CMBitmapCallBackUPP progressProc, BitMap *bitMap, void *refCon);

/**
 *  CMMConcatInit()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
CMError
CMMConcatInit(CMMComponentInst cmm, CMConcatProfileSet *profileSet);

/**
 *  NCMMConcatInit()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
CMError
NCMMConcatInit(CMMComponentInst cmm, NCMConcatProfileSet *profileSet,
               CMConcatCallBackUPP proc, void *refCon);

/**
 *  CMMNewLinkProfile()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
CMError
CMMNewLinkProfile(CMMComponentInst cmm, CMProfileRef *prof,
                  const CMProfileLocation *targetLocation,
                  CMConcatProfileSet *profileSet);

/**
 *  NCMMNewLinkProfile()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
CMError
NCMMNewLinkProfile(CMMComponentInst cmm, CMProfileRef prof,
                   NCMConcatProfileSet *profileSet, CMConcatCallBackUPP proc,
                   void *refCon);

/**
 *  CMMGetPS2ColorSpace()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
CMError
CMMGetPS2ColorSpace(CMMComponentInst cmm, CMProfileRef srcProf, UInt32 flags,
                    CMFlattenUPP proc, void *refCon);

/**
 *  CMMGetPS2ColorRenderingIntent()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
CMError
CMMGetPS2ColorRenderingIntent(CMMComponentInst cmm, CMProfileRef srcProf,
                              UInt32 flags, CMFlattenUPP proc, void *refCon);

/**
 *  CMMGetPS2ColorRendering()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
CMError
CMMGetPS2ColorRendering(CMMComponentInst cmm, CMProfileRef srcProf,
                        CMProfileRef dstProf, UInt32 flags, CMFlattenUPP proc,
                        void *refCon);

/**
 *  CMMGetPS2ColorRenderingVMSize()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
CMError
CMMGetPS2ColorRenderingVMSize(CMMComponentInst cmm, CMProfileRef srcProf,
                              CMProfileRef dstProf, UInt32 *vmSize);

/**
 *  CMMConcatenateProfiles()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
CMError
CMMConcatenateProfiles(CMMComponentInst cmm, CMProfileHandle thru,
                       CMProfileHandle dst, CMProfileHandle *newDst);

/**
 *  CMMGetNamedColorInfo()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
CMError
CMMGetNamedColorInfo(CMMComponentInst cmm, CMProfileRef srcProf,
                     UInt32 *deviceChannels, OSType *deviceColorSpace,
                     OSType *PCSColorSpace, UInt32 *count, StringPtr prefix,
                     StringPtr suffix);

/**
 *  CMMGetNamedColorValue()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
CMError
CMMGetNamedColorValue(CMMComponentInst cmm, CMProfileRef prof, StringPtr name,
                      CMColor *deviceColor, CMColor *PCSColor);

/**
 *  CMMGetIndNamedColorValue()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
CMError
CMMGetIndNamedColorValue(CMMComponentInst cmm, CMProfileRef prof, UInt32 index,
                         CMColor *deviceColor, CMColor *PCSColor);

/**
 *  CMMGetNamedColorIndex()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
CMError
CMMGetNamedColorIndex(CMMComponentInst cmm, CMProfileRef prof, StringPtr name,
                      UInt32 *index);

/**
 *  CMMGetNamedColorName()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
CMError
CMMGetNamedColorName(CMMComponentInst cmm, CMProfileRef prof, UInt32 index,
                     StringPtr name);

#endif // CALL_NOT_IN_CARBON
#endif // TARGET_API_MAC_OS8
#if PRAGMA_STRUCT_ALIGN
#pragma options align = reset
#elif PRAGMA_STRUCT_PACKPUSH
#pragma pack(pop)
#elif PRAGMA_STRUCT_PACK
#pragma pack()
#endif

#ifdef // CALL_NOT_IN_CARBON
#pragma import off
#elif P // TARGET_API_MAC_OS8
#pragma import reset
#endif

#ifdef __cplusplus
}
#endif

#endif // __CMMCOMPONENT__ // __CMMCOMPONENT__
