/**
     \file       CMConversions.h

    \brief   ColorSync Conversion Component API

    \introduced_in  ColorSync 2.0
    \avaliable_from Universal Interfaces 3.4.1

    \copyright © 1993-2001 by Apple Computer, Inc. All rights reserved.

    \ingroup ColorSync

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __CMCONVERSIONS__
#define __CMCONVERSIONS__

#ifndef __MACTYPES__
#include <MacTypes.h>
#endif

#ifndef __COMPONENTS__
#include <Components.h>
#endif

#ifndef __CMAPPLICATION__
#include <CMApplication.h>
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
        CMConversionInterfaceVersion = 1
    };

    /** Component function selectors */
    enum
    {
        kCMXYZToLab = 0,
        kCMLabToXYZ = 1,
        kCMXYZToLuv = 2,
        kCMLuvToXYZ = 3,
        kCMXYZToYxy = 4,
        kCMYxyToXYZ = 5,
        kCMRGBToHLS = 6,
        kCMHLSToRGB = 7,
        kCMRGBToHSV = 8,
        kCMHSVToRGB = 9,
        kCMRGBToGRAY = 10,
        kCMXYZToFixedXYZ = 11,
        kCMFixedXYZToXYZ = 12
    };

#if CALL_NOT_IN_CARBON
    /**
     *  CMXYZToLab()
     *

     *    \non_carbon_cfm   in ColorSyncLibPriv 2.0 and later
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    ComponentResult
    CMXYZToLab(ComponentInstance ci, const CMColor *src, const CMXYZColor *white,
               CMColor *dst, unsigned long count);

    /**
     *  CMLabToXYZ()
     *

     *    \non_carbon_cfm   in ColorSyncLibPriv 2.0 and later
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    ComponentResult
    CMLabToXYZ(ComponentInstance ci, const CMColor *src, const CMXYZColor *white,
               CMColor *dst, unsigned long count);

    /**
     *  CMXYZToLuv()
     *

     *    \non_carbon_cfm   in ColorSyncLibPriv 2.0 and later
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    ComponentResult
    CMXYZToLuv(ComponentInstance ci, const CMColor *src, const CMXYZColor *white,
               CMColor *dst, unsigned long count);

    /**
     *  CMLuvToXYZ()
     *

     *    \non_carbon_cfm   in ColorSyncLibPriv 2.0 and later
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    ComponentResult
    CMLuvToXYZ(ComponentInstance ci, const CMColor *src, const CMXYZColor *white,
               CMColor *dst, unsigned long count);

    /**
     *  CMXYZToYxy()
     *

     *    \non_carbon_cfm   in ColorSyncLibPriv 2.0 and later
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    ComponentResult
    CMXYZToYxy(ComponentInstance ci, const CMColor *src, CMColor *dst,
               unsigned long count);

    /**
     *  CMYxyToXYZ()
     *

     *    \non_carbon_cfm   in ColorSyncLibPriv 2.0 and later
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    ComponentResult
    CMYxyToXYZ(ComponentInstance ci, const CMColor *src, CMColor *dst,
               unsigned long count);

    /**
     *  CMRGBToHLS()
     *

     *    \non_carbon_cfm   in ColorSyncLibPriv 2.0 and later
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    ComponentResult
    CMRGBToHLS(ComponentInstance ci, const CMColor *src, CMColor *dst,
               unsigned long count);

    /**
     *  CMHLSToRGB()
     *

     *    \non_carbon_cfm   in ColorSyncLibPriv 2.0 and later
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    ComponentResult
    CMHLSToRGB(ComponentInstance ci, const CMColor *src, CMColor *dst,
               unsigned long count);

    /**
     *  CMRGBToHSV()
     *

     *    \non_carbon_cfm   in ColorSyncLibPriv 2.0 and later
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    ComponentResult
    CMRGBToHSV(ComponentInstance ci, const CMColor *src, CMColor *dst,
               unsigned long count);

    /**
     *  CMHSVToRGB()
     *

     *    \non_carbon_cfm   in ColorSyncLibPriv 2.0 and later
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    ComponentResult
    CMHSVToRGB(ComponentInstance ci, const CMColor *src, CMColor *dst,
               unsigned long count);

    /**
     *  CMRGBToGray()
     *

     *    \non_carbon_cfm   in ColorSyncLibPriv 2.0 and later
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    ComponentResult
    CMRGBToGray(ComponentInstance ci, const CMColor *src, CMColor *dst,
                unsigned long count);

    /**
     *  CMXYZToFixedXYZ()
     *

     *    \non_carbon_cfm   in ColorSyncLibPriv 2.0 and later
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    ComponentResult
    CMXYZToFixedXYZ(ComponentInstance ci, const CMXYZColor *src,
                    CMFixedXYZColor *dst, unsigned long count);

    /**
     *  CMFixedXYZToXYZ()
     *

     *    \non_carbon_cfm   in ColorSyncLibPriv 2.0 and later
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    ComponentResult
    CMFixedXYZToXYZ(ComponentInstance ci, const CMFixedXYZColor *src,
                    CMXYZColor *dst, unsigned long count);

#endif /** CALL_NOT_IN_CARBON */

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

#endif /** __CMCONVERSIONS__ */
