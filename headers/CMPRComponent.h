/**
     \file       CMPRComponent.h

    \brief   ColorSync ProfileResponder Component API

    \introduced_in  ColorSync 1.0
    \avaliable_from Universal Interfaces 3.4.1

    \copyright � 1993-2001 by Apple Computer, Inc. All rights reserved.

    \ingroup ColorSync

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __CMPRCOMPONENT__
#define __CMPRCOMPONENT__

#ifndef __MACTYPES__
#include <MacTypes.h>
#endif

#ifndef __QUICKDRAW__
#include <Quickdraw.h>
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
        CMPRInterfaceVersion = 0
    };

    /* Component function selectors */
    enum
    {
        kCMPRGetProfile = 0,
        kCMPRSetProfile = 1,
        kCMPRSetProfileDescription = 2,
        kCMPRGetIndexedProfile = 3,
        kCMPRDeleteDeviceProfile = 4
    };

#if CALL_NOT_IN_CARBON
    /**
     *  CMGetProfile()
     *

     *    \non_carbon_cfm   in ColorSyncLibPriv 2.0 and later
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    CMError
    CMGetProfile(ComponentInstance pr, CMProfileHandle aProfile,
                 CMProfileHandle *returnedProfile);

    /**
     *  CMSetProfile()
     *

     *    \non_carbon_cfm   in ColorSyncLibPriv 2.0 and later
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    CMError
    CMSetProfile(ComponentInstance pr, CMProfileHandle newProfile);

    /**
     *  CMSetProfileDescription()
     *

     *    \non_carbon_cfm   in ColorSyncLibPriv 2.0 and later
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    CMError
    CMSetProfileDescription(ComponentInstance pr, long DeviceData,
                            CMProfileHandle hProfile);

    /**
     *  CMGetIndexedProfile()
     *

     *    \non_carbon_cfm   in ColorSyncLibPriv 2.0 and later
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    CMError
    CMGetIndexedProfile(ComponentInstance pr, CMProfileSearchRecordHandle search,
                        CMProfileHandle *returnProfile, long *index);

    /**
     *  CMDeleteDeviceProfile()
     *

     *    \non_carbon_cfm   in ColorSyncLibPriv 2.0 and later
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    CMError
    CMDeleteDeviceProfile(ComponentInstance pr, CMProfileHandle deleteMe);

#endif /* CALL_NOT_IN_CARBON */

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

#endif /* __CMPRCOMPONENT__ */
