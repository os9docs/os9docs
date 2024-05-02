/**
     \file       OSAComp.h

    \brief   AppleScript Component Implementor's Interfaces.

    \introduced_in  AppleScript 1.1
    \avaliable_from Universal Interfaces 3.4.1

    \copyright © 1992-2001 by Apple Computer, Inc., all rights reserved

    \ingroup OpenScriptingArchitecture

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __OSACOMP__
#define __OSACOMP__

#ifndef __MACTYPES__
#include <MacTypes.h>
#endif

#ifndef __AEDATAMODEL__
#include <AEDataModel.h>
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

    /**************************************************************************
        Types and Constants
    **************************************************************************/
    /**************************************************************************
        Routines for Associating a Storage Type with a Script Data Handle
    **************************************************************************/
    /**
     *  OSAGetStorageType()
     *

     *    \non_carbon_cfm   in AppleScriptLib 1.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    OSAGetStorageType(AEDataStorage scriptData, DescType *dscType);

    /**
     *  OSAAddStorageType()
     *

     *    \non_carbon_cfm   in AppleScriptLib 1.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    OSAAddStorageType(AEDataStorage scriptData, DescType dscType);

    /**
     *  OSARemoveStorageType()
     *

     *    \non_carbon_cfm   in AppleScriptLib 1.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    OSARemoveStorageType(AEDataStorage scriptData);

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

#endif /* __OSACOMP__ */
