/**
     \file       ASDebugging.h

    \brief   AppleScript Debugging Interfaces.

    \introduced_in  AppleScript 1.1
    \avaliable_from Universal Interfaces 3.4.1

    \copyright � 1992-2001 by Apple Computer, Inc., all rights reserved

    \ingroup AppleScript
    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __ASDEBUGGING__
#define __ASDEBUGGING__

#ifndef __MACTYPES__
#include <MacTypes.h>
#endif

#ifndef __FILES__
#include <Files.h>
#endif

#ifndef __COMPONENTS__
#include <Components.h>
#endif

#ifndef __APPLEEVENTS__
#include <AppleEvents.h>
#endif

#ifndef __APPLESCRIPT__
#include <AppleScript.h>
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
        Mode Flags
    **************************************************************************/
    /*    This mode flag can be passed to OSASetProperty or OSASetHandler
        and will prevent properties or handlers from being defined in a context
        that doesn't already have bindings for them. An error is returned if
        a current binding doesn't already exist.
    */
    enum
    {
        kOSAModeDontDefine = 0x0001
    };

    /**************************************************************************
        Component Selectors
    **************************************************************************/
    enum
    {
        kASSelectSetPropertyObsolete = 0x1101,
        kASSelectGetPropertyObsolete = 0x1102,
        kASSelectSetHandlerObsolete = 0x1103,
        kASSelectGetHandlerObsolete = 0x1104,
        kASSelectGetAppTerminologyObsolete = 0x1105,
        kASSelectSetProperty = 0x1106,
        kASSelectGetProperty = 0x1107,
        kASSelectSetHandler = 0x1108,
        kASSelectGetHandler = 0x1109,
        kASSelectGetAppTerminology = 0x110A,
        kASSelectGetSysTerminology = 0x110B,
        kASSelectGetPropertyNames = 0x110C,
        kASSelectGetHandlerNames = 0x110D
    };

    /**************************************************************************
        Context Accessors
    **************************************************************************/
    /**
     *  OSASetProperty()
     *

     *    \non_carbon_cfm   in AppleScriptLib 1.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSAError
    OSASetProperty(ComponentInstance scriptingComponent, long modeFlags,
                   OSAID contextID, const AEDesc *variableName, OSAID scriptValueID);

    /**
     *  OSAGetProperty()
     *

     *    \non_carbon_cfm   in AppleScriptLib 1.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSAError
    OSAGetProperty(ComponentInstance scriptingComponent, long modeFlags,
                   OSAID contextID, const AEDesc *variableName,
                   OSAID *resultingScriptValueID);

    /**
     *  OSAGetPropertyNames()
     *

     *    \non_carbon_cfm   in AppleScriptLib 1.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSAError
    OSAGetPropertyNames(ComponentInstance scriptingComponent, long modeFlags,
                        OSAID contextID, AEDescList *resultingPropertyNames);

    /**
     *  OSASetHandler()
     *

     *    \non_carbon_cfm   in AppleScriptLib 1.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSAError
    OSASetHandler(ComponentInstance scriptingComponent, long modeFlags,
                  OSAID contextID, const AEDesc *handlerName,
                  OSAID compiledScriptID);

    /**
     *  OSAGetHandler()
     *

     *    \non_carbon_cfm   in AppleScriptLib 1.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSAError
    OSAGetHandler(ComponentInstance scriptingComponent, long modeFlags,
                  OSAID contextID, const AEDesc *handlerName,
                  OSAID *resultingCompiledScriptID);

    /**
     *  OSAGetHandlerNames()
     *

     *    \non_carbon_cfm   in AppleScriptLib 1.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSAError
    OSAGetHandlerNames(ComponentInstance scriptingComponent, long modeFlags,
                       OSAID contextID, AEDescList *resultingHandlerNames);

    /**
     *  OSAGetAppTerminology()
     *

     *    \non_carbon_cfm   in AppleScriptLib 1.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSAError
    OSAGetAppTerminology(ComponentInstance scriptingComponent, long modeFlags,
                         FSSpec *fileSpec, short terminologyID, Boolean *didLaunch,
                         AEDesc *terminologyList);

    /* Errors:
           errOSASystemError        operation failed
        */
    /**
     *  OSAGetSysTerminology()
     *

     *    \non_carbon_cfm   in AppleScriptLib 1.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSAError
    OSAGetSysTerminology(ComponentInstance scriptingComponent, long modeFlags,
                         short terminologyID, AEDesc *terminologyList);

    /* Errors:
           errOSASystemError        operation failed
        */
    /* Notes on terminology ID

        A terminology ID is derived from script code and language code
        as follows;

            terminologyID = ((scriptCode & 0x7F) << 8) | (langCode & 0xFF)
    */
    /**************************************************************************
        Obsolete versions provided for backward compatibility:
    */
    /**
     *  ASSetProperty()
     *

     *    \non_carbon_cfm   in AppleScriptLib 1.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSAError
    ASSetProperty(ComponentInstance scriptingComponent, OSAID contextID,
                  const AEDesc *variableName, OSAID scriptValueID);

    /**
     *  ASGetProperty()
     *

     *    \non_carbon_cfm   in AppleScriptLib 1.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSAError
    ASGetProperty(ComponentInstance scriptingComponent, OSAID contextID,
                  const AEDesc *variableName, OSAID *resultingScriptValueID);

    /**
     *  ASSetHandler()
     *

     *    \non_carbon_cfm   in AppleScriptLib 1.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSAError
    ASSetHandler(ComponentInstance scriptingComponent, OSAID contextID,
                 const AEDesc *handlerName, OSAID compiledScriptID);

    /**
     *  ASGetHandler()
     *

     *    \non_carbon_cfm   in AppleScriptLib 1.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSAError
    ASGetHandler(ComponentInstance scriptingComponent, OSAID contextID,
                 const AEDesc *handlerName, OSAID *resultingCompiledScriptID);

    /**
     *  ASGetAppTerminology()
     *

     *    \non_carbon_cfm   in AppleScriptLib 1.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSAError
    ASGetAppTerminology(ComponentInstance scriptingComponent, FSSpec *fileSpec,
                        short terminologID, Boolean *didLaunch,
                        AEDesc *terminologyList);

    /* Errors:
            errOSASystemError       operation failed
        */
    /**************************************************************************/

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

#endif // __ASDEBUGGING__